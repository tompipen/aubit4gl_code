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
#define YYLAST   9600

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  734
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  876
/* YYNRULES -- Number of rules. */
#define YYNRULES  2064
/* YYNRULES -- Number of states. */
#define YYNSTATES  3502

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
    4373,  4375,  4377,  4379,  4381,  4383,  4385,  4387,  4395,  4402,
    4407,  4412,  4414,  4416,  4418,  4419,  4421,  4424,  4426,  4428,
    4430,  4432,  4436,  4439,  4441,  4443,  4446,  4448,  4450,  4451,
    4455,  4457,  4461,  4463,  4467,  4469,  4471,  4478,  4479,  4483,
    4485,  4489,  4490,  4492,  4497,  4503,  4506,  4508,  4510,  4515,
    4517,  4521,  4526,  4531,  4536,  4538,  4542,  4544,  4546,  4548,
    4551,  4553,  4555,  4557,  4562,  4563,  4565,  4566,  4568,  4570,
    4573,  4576,  4578,  4580,  4582,  4584,  4586,  4591,  4593,  4597,
    4599,  4601,  4603,  4606,  4608,  4610,  4613,  4616,  4618,  4622,
    4625,  4628,  4630,  4634,  4636,  4639,  4644,  4646,  4649,  4653,
    4655,  4659,  4664,  4665,  4667,  4668,  4670,  4671,  4673,  4675,
    4679,  4681,  4685,  4687,  4690,  4692,  4696,  4699,  4702,  4703,
    4706,  4708,  4710,  4716,  4720,  4726,  4730,  4732,  4736,  4738,
    4740,  4741,  4743,  4747,  4751,  4755,  4762,  4767,  4772,  4777,
    4782,  4788,  4790,  4792,  4794,  4796,  4798,  4800,  4802,  4804,
    4806,  4808,  4809,  4811,  4813,  4815,  4817,  4819,  4821,  4823,
    4828,  4829,  4831,  4836,  4838,  4844,  4850,  4852,  4854,  4856,
    4858,  4860,  4865,  4867,  4872,  4879,  4884,  4886,  4891,  4893,
    4901,  4903,  4905,  4907,  4912,  4919,  4920,  4923,  4928,  4930,
    4932,  4934,  4936,  4938,  4940,  4942,  4946,  4948,  4950,  4954,
    4960,  4964,  4970,  4978,  4982,  4984,  4986,  4990,  4996,  5000,
    5006,  5014,  5016,  5017,  5021,  5027,  5029,  5032,  5035,  5040,
    5044,  5046,  5048,  5050,  5052,  5054,  5057,  5060,  5061,  5065,
    5066,  5070,  5072,  5074,  5076,  5078,  5080,  5082,  5084,  5089,
    5091,  5093,  5095,  5097,  5099,  5101,  5103,  5105,  5107,  5109,
    5111,  5113,  5115,  5117,  5122,  5124,  5128,  5130,  5134,  5135,
    5143,  5144,  5153,  5154,  5161,  5162,  5171,  5172,  5174,  5177,
    5179,  5183,  5185,  5189,  5195,  5197,  5199,  5201,  5203,  5205,
    5206,  5207,  5217,  5223,  5225,  5227,  5234,  5235,  5239,  5241,
    5245,  5250,  5252,  5253,  5256,  5261,  5268,  5269,  5271,  5273,
    5275,  5277,  5281,  5283,  5286,  5290,  5292,  5294,  5297,  5300,
    5302,  5304,  5306,  5309,  5312,  5315,  5318,  5323,  5327,  5330,
    5334,  5338,  5342,  5344,  5346,  5348,  5350,  5352,  5354,  5360,
    5366,  5372,  5378,  5384,  5389,  5394,  5398,  5403,  5405,  5407,
    5409,  5413,  5415,  5421,  5429,  5435,  5436,  5439,  5441,  5443,
    5444,  5448,  5450,  5454,  5456,  5458,  5460,  5461,  5465,  5467,
    5469,  5471,  5473,  5478,  5485,  5487,  5489,  5492,  5496,  5498,
    5500,  5502,  5504,  5506,  5508,  5510,  5512,  5518,  5524,  5529,
    5535,  5537,  5542,  5544,  5546,  5554,  5559,  5561,  5562,  5567,
    5569,  5572,  5574,  5576,  5578,  5579,  5583,  5584,  5588,  5589,
    5590,  5597,  5598,  5601,  5604,  5612,  5616,  5620,  5623,  5626,
    5629,  5631,  5635,  5637,  5641,  5643,  5647,  5649,  5653,  5655,
    5657,  5659,  5662,  5665,  5667,  5669,  5672,  5677,  5683,  5691,
    5699,  5709,  5711,  5713,  5715,  5717,  5719,  5721,  5725,  5728,
    5732,  5736,  5740,  5746,  5752,  5758,  5764,  5770,  5775,  5780,
    5784,  5789,  5791,  5793,  5795,  5797,  5801,  5802,  5808,  5810,
    5814,  5818,  5822,  5824,  5826,  5829,  5831,  5833,  5837,  5839,
    5843,  5847,  5849,  5851,  5853,  5857,  5860,  5864,  5871,  5873,
    5877,  5879,  5881,  5882,  5883,  5890,  5891,  5894,  5895,  5897,
    5899,  5902,  5905,  5907,  5909,  5914,  5918,  5920,  5923,  5929,
    5932,  5935,  5941,  5942,  5945,  5947,  5949,  5952,  5959,  5966,
    5968,  5969,  5971,  5974,  5976,  5979,  5980,  5983,  5985,  5987,
    5989,  5991,  5993,  5995,  5997,  5999,  6001,  6003,  6005,  6007,
    6009,  6011,  6013,  6015,  6017,  6019,  6021,  6023,  6025,  6027,
    6029,  6031,  6033,  6035,  6037,  6039,  6041,  6043,  6045,  6047,
    6049,  6051,  6053,  6055,  6057,  6059,  6061,  6063,  6065,  6067,
    6069,  6071,  6073,  6075,  6077,  6079,  6081,  6083,  6085,  6087,
    6089,  6091,  6093,  6095,  6097,  6099,  6101,  6103,  6105,  6107,
    6109,  6111,  6113,  6115,  6117,  6119,  6121,  6123,  6125,  6127,
    6129,  6131,  6133,  6135,  6137,  6139,  6141,  6143,  6145,  6147,
    6149,  6151,  6153,  6155,  6157
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
      -1,    26,    -1,    26,    19,    26,    -1,  1014,    -1,   971,
       5,  1014,    -1,  1015,    -1,   972,     5,  1015,    -1,    -1,
      -1,    -1,   459,   974,  1017,   975,   977,  1388,   976,  1604,
     297,    -1,    -1,     8,   944,   926,    -1,    -1,    -1,   690,
    1023,   979,   827,   980,  1128,   982,   981,   987,   691,    -1,
      -1,   992,    -1,    -1,   983,    -1,   984,    -1,   983,   984,
      -1,    -1,   692,   985,  1604,    -1,    -1,   693,   986,  1604,
      -1,    -1,   988,    -1,   989,    -1,   988,   989,    -1,    -1,
     694,   990,  1604,    -1,    -1,   695,   991,  1604,    -1,   993,
     997,   382,    -1,   148,    -1,   148,   994,   599,   995,    -1,
     148,   441,   996,    -1,  1179,    -1,   994,     5,  1179,    -1,
    1023,    -1,   995,     5,  1023,    -1,  1179,    -1,   996,     5,
    1179,    -1,   998,    -1,   997,   998,    -1,    -1,   696,   999,
    1604,    -1,    -1,   697,  1000,  1604,    -1,    -1,   716,   995,
    1001,  1604,    -1,    -1,   534,   995,  1002,  1604,    -1,    -1,
     677,   995,  1003,  1604,    -1,    -1,    -1,   648,  1179,    14,
     928,   678,   928,  1007,  1005,  1604,  1006,   298,    -1,    -1,
     624,   928,    -1,   598,  1016,    -1,   607,    19,    26,    -1,
     607,    -1,   554,    18,    26,    -1,   554,    -1,    26,    -1,
    1179,    -1,   721,    -1,    25,    -1,  1028,    -1,   928,    -1,
    1011,     5,  1011,    -1,  1012,    -1,  1023,    -1,   719,   485,
    1023,   448,    -1,  1023,   672,   719,   485,  1023,   448,    -1,
    1023,   513,   742,   481,    -1,  1023,   672,    20,    -1,  1023,
     513,   742,   481,   672,    20,    -1,  1023,   672,  1023,    -1,
    1023,   513,   742,   481,   672,  1023,    -1,  1014,    -1,    25,
      -1,  1024,    -1,  1024,    -1,  1024,    -1,  1024,    -1,  1024,
      -1,  1024,    -1,    -1,   603,    26,    -1,  1603,    -1,  1025,
      -1,  1603,    -1,   407,   485,  1026,   448,    -1,  1182,    -1,
      25,    -1,  1023,    -1,  1023,   513,   742,   481,    -1,  1023,
     672,    20,    -1,  1023,   513,   742,   481,   672,    20,    -1,
    1023,   672,  1023,    -1,  1023,   513,   742,   481,   672,  1023,
      -1,  1179,    -1,    24,    -1,   672,    26,    -1,   600,  1031,
      -1,  1023,    -1,   642,  1023,    -1,   704,  1033,    -1,  1034,
      -1,  1033,     5,  1034,    -1,  1023,    -1,   715,  1033,    -1,
     706,  1033,    -1,   707,   971,    -1,   705,  1020,   711,   971,
      -1,   709,  1033,    -1,   710,   971,    -1,   708,  1020,   711,
     971,    -1,    -1,   713,  1039,   926,  1044,  1046,  1048,  1040,
    1042,    -1,    -1,  1041,    -1,   701,    -1,   702,    -1,    -1,
    1043,    -1,   402,  1179,    -1,    -1,  1045,    -1,   446,   926,
      -1,    -1,  1047,    -1,   712,    26,    -1,    -1,  1049,    -1,
     703,    26,  1050,    -1,    -1,   455,    26,    -1,    -1,    -1,
     674,   928,   628,  1052,  1604,  1053,  1054,   495,    -1,    -1,
      -1,   595,  1055,  1604,    -1,    -1,    -1,   120,  1056,   928,
     628,  1057,  1604,  1054,    -1,   165,  1023,   485,    26,   448,
      -1,   111,  1023,    -1,    43,  1023,    -1,   133,  1023,    -1,
      -1,   346,  1208,  1062,   678,   536,    -1,   346,  1208,   609,
    1063,    -1,  1064,    -1,  1063,     5,  1064,    -1,  1065,   672,
    1482,    -1,  1065,   672,    20,    -1,  1478,    -1,    -1,  1068,
     382,    -1,   382,    -1,    -1,   208,    -1,  1069,    -1,  1068,
    1069,    -1,    -1,   326,  1083,  1070,  1604,    -1,    -1,   329,
    1084,  1071,  1604,    -1,    -1,   409,  1072,  1604,    -1,    -1,
     405,  1073,  1604,    -1,    -1,  1097,  1074,  1604,    -1,    -1,
     361,  1075,  1604,    -1,    -1,   331,  1076,  1604,    -1,    -1,
      53,  1077,  1604,    -1,    -1,    50,  1078,  1604,    -1,    -1,
      49,  1079,  1604,    -1,    -1,    48,  1080,  1604,    -1,    -1,
      56,  1081,  1604,    -1,    -1,    55,  1082,  1604,    -1,  1014,
      -1,  1083,     5,  1014,    -1,  1014,    -1,  1084,     5,  1014,
      -1,   370,  1087,    -1,   371,  1023,   711,  1087,    -1,   614,
      -1,   432,    -1,  1014,    -1,    -1,   717,  1090,  1089,  1066,
      -1,   441,  1197,  1067,  1022,   745,    -1,  1197,  1067,   599,
     971,  1022,   745,    -1,    -1,   540,  1204,  1067,   599,  1023,
     672,    20,  1022,  1091,   745,    -1,   523,   971,  1093,    -1,
     139,    26,    -1,   140,    26,    -1,   679,    -1,   592,    -1,
     139,  1179,    -1,   140,  1179,    -1,    -1,   603,    26,    -1,
    1096,    -1,    62,    25,    -1,   549,    14,    26,    -1,   549,
      14,  1179,    -1,    63,    14,    26,    -1,    63,    14,  1179,
      -1,    59,    -1,    61,    -1,    58,    -1,    60,    -1,    -1,
     484,  1098,  1103,    -1,   351,    -1,    -1,   649,  1100,  1103,
      -1,   359,  1105,    -1,   649,  1103,    -1,  1105,    -1,   485,
    1104,   448,    -1,  1105,    -1,  1104,     5,  1105,    -1,  1106,
      -1,   647,    -1,   368,    -1,   388,    -1,   360,    -1,   538,
      -1,   496,    -1,   679,    -1,   603,    -1,   592,    -1,   234,
      -1,   493,    -1,   504,    -1,   593,    -1,   608,    -1,   573,
      -1,   366,    -1,   367,    -1,    25,    -1,   563,    -1,    -1,
      -1,   651,  1109,  1202,  1110,    14,   944,  1111,    -1,   536,
      -1,   927,    -1,   276,  1179,    -1,   266,  1179,    -1,   279,
    1179,    -1,   505,  1200,   391,    -1,   505,  1200,   442,  1010,
      -1,  1117,    -1,  1118,    -1,   793,    -1,    -1,  1120,  1119,
    1123,    -1,    -1,  1121,    -1,  1122,    -1,  1121,  1122,    -1,
    1060,    -1,  1127,    -1,  1588,    -1,  1059,    -1,  1143,    -1,
    1129,    -1,  1142,    -1,    -1,  1124,    -1,  1126,    -1,  1124,
    1126,    -1,   124,  1023,    -1,  1131,    -1,  1137,    -1,  1302,
      -1,  1312,    -1,  1149,    -1,   978,    -1,   801,    -1,  1058,
      -1,  1588,    -1,   801,    -1,    -1,   801,    -1,   828,    -1,
     424,    -1,   118,    -1,    -1,    -1,    -1,    -1,  1130,  1132,
    1023,   485,  1133,  1195,   448,  1134,   827,  1135,  1128,  1604,
    1136,    -1,   268,    -1,    -1,    -1,   610,  1138,   827,  1139,
    1604,   418,    -1,   234,   923,    -1,   944,    -1,   944,   926,
      -1,   413,  1493,    -1,   521,  1493,    -1,  1144,    -1,  1145,
      -1,  1144,  1145,    -1,  1146,    -1,    -1,   461,  1147,  1148,
      -1,   827,   299,    -1,  1010,    -1,  1127,    -1,  1142,    -1,
      -1,    -1,   698,  1023,  1150,   827,  1151,  1152,   699,    -1,
    1153,    -1,  1152,  1153,    -1,    -1,   700,  1154,  1604,    -1,
      -1,   677,  1023,  1155,  1604,    -1,    -1,   611,  1157,  1172,
    1163,  1158,    -1,   419,    -1,    -1,   291,  1160,  1604,    -1,
      -1,    23,  1164,  1165,  1166,  1022,  1161,  1604,    -1,    -1,
      23,  1164,  1022,  1162,  1604,    -1,  1159,    -1,  1163,  1159,
      -1,    -1,  1099,    -1,    25,    -1,  1179,    -1,    -1,  1179,
      -1,    25,    -1,   308,  1170,    -1,   319,  1171,    -1,   303,
    1171,    -1,   638,    -1,    25,    -1,  1179,    -1,  1170,    -1,
    1171,     5,  1170,    -1,  1179,    -1,    25,    -1,  1176,  1174,
      -1,    -1,   746,  1177,    -1,  1178,    -1,  1175,    -1,  1045,
      -1,  1047,    -1,  1049,    -1,  1041,    -1,  1043,    -1,   427,
     944,   926,    -1,    -1,   123,    -1,   123,    -1,  1180,    -1,
    1182,    -1,   247,  1182,    -1,  1182,   672,    -1,  1181,  1186,
      -1,  1181,  1023,   513,  1189,   481,    -1,  1181,  1023,   513,
    1189,   481,   513,  1189,   481,    -1,  1187,    -1,  1023,    -1,
    1183,    -1,  1023,   512,  1185,   480,    -1,  1023,   512,  1185,
     480,    -1,  1179,    -1,    25,    -1,    20,    -1,  1023,    -1,
    1023,  1188,    -1,   513,  1189,   481,    -1,   513,  1189,   481,
     513,  1189,   481,    -1,  1190,    -1,  1189,     5,  1190,    -1,
     742,    -1,  1192,    -1,  1194,    -1,  1192,   672,  1193,    -1,
    1192,   672,  1023,   513,  1189,   481,    -1,  1192,   672,  1023,
     513,  1189,   481,   513,  1189,   481,    -1,  1023,    -1,  1184,
      -1,    20,    -1,  1023,    -1,  1023,  1188,    -1,    -1,  1196,
      -1,  1198,    -1,  1196,     5,  1198,    -1,  1199,    -1,  1197,
       5,  1199,    -1,  1023,    -1,  1023,   672,  1023,    -1,  1179,
      -1,  1179,   475,  1179,    -1,    25,    -1,  1029,    -1,    26,
      -1,  1201,    -1,  1200,     5,  1201,    -1,  1179,    -1,  1179,
     475,  1179,    -1,  1203,    -1,  1202,     5,  1203,    -1,  1191,
      -1,  1179,    -1,  1206,    -1,  1205,     5,  1206,    -1,  1179,
    1207,    -1,    -1,   640,    -1,   591,    -1,  1209,    -1,  1208,
       5,  1209,    -1,  1179,    -1,  1179,   475,  1179,    -1,   311,
    1019,   670,  1012,   632,  1596,   750,    -1,    -1,   670,   485,
     928,     5,   928,   448,  1212,    -1,    -1,   621,   485,   928,
       5,   928,   448,    -1,   312,  1023,  1211,    -1,  1023,    -1,
     396,  1021,  1216,    -1,  1217,    -1,   599,   928,    -1,  1218,
    1219,  1224,     8,  1214,    -1,    -1,   670,  1220,   485,   928,
       5,   928,   448,    -1,    -1,   609,  1024,    -1,    -1,   408,
      -1,   274,  1535,   322,  1577,  1223,    -1,   616,  1016,    -1,
     616,  1016,     8,   944,   926,    -1,    -1,   669,   629,  1529,
     431,  1529,    -1,   669,   629,  1529,     5,   431,  1529,    -1,
     669,  1529,     5,  1529,    -1,    -1,   701,    -1,   702,    -1,
     450,   678,  1577,  1226,  1227,    -1,    -1,   669,  1577,    -1,
      -1,   669,   629,  1529,     8,  1529,    -1,   629,  1529,     8,
    1529,    -1,   466,  1229,    -1,  1230,    -1,  1229,     5,  1230,
      -1,   259,  1009,    -1,   340,  1009,    -1,   387,  1009,    -1,
     395,  1009,    -1,   349,  1009,    -1,   316,  1009,    -1,  1101,
      -1,   493,  1102,    -1,   504,  1102,    -1,   614,  1102,    -1,
     432,  1102,    -1,   603,  1102,    -1,   601,  1010,    -1,   602,
    1010,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
     456,   746,    -1,   717,   746,    -1,   347,    -1,   252,    -1,
     209,    -1,   189,    -1,   197,    -1,   206,    -1,   659,  1231,
      -1,   733,  1232,    -1,    40,    -1,    41,    -1,    40,    -1,
      41,    -1,  1534,   468,  1236,   599,  1234,    -1,  1179,    -1,
      25,    -1,   458,  1236,    -1,   458,  1236,     8,  1197,    -1,
     458,  1236,   606,  1200,    -1,   458,  1236,   606,  1200,     8,
    1197,    -1,    57,  1234,    -1,  1024,    -1,    -1,   516,  1246,
     745,   648,  1241,  1179,  1239,  1022,   745,  1238,  1242,    -1,
      -1,   720,    26,    -1,   516,  1246,   745,   402,  1179,    -1,
      -1,   375,    -1,    -1,  1243,   338,    -1,  1244,    -1,  1243,
    1244,    -1,    -1,  1097,  1245,  1604,    -1,   927,    -1,    -1,
     656,  1016,  1248,  1249,    -1,    -1,   599,  1250,    -1,  1251,
      -1,  1250,     5,  1251,    -1,  1521,    -1,   536,    -1,   277,
    1255,   146,  1253,    -1,   277,  1255,   678,  1254,  1253,    -1,
     277,  1255,   145,  1254,  1253,    -1,   277,  1255,  1253,    -1,
      -1,    51,    -1,    25,    -1,  1028,    -1,  1023,    -1,    -1,
     532,    -1,   205,  1255,  1256,   485,   944,  1141,   448,    -1,
     250,  1255,    -1,   125,  1255,    -1,  1293,  1301,    -1,   501,
     119,    -1,   501,  1262,    -1,  1263,    -1,  1262,  1263,    -1,
      -1,   193,  1264,  1604,    -1,    -1,   255,  1265,  1604,    -1,
      -1,   285,  1266,  1604,    -1,    -1,   273,  1267,  1604,    -1,
      -1,   310,  1268,  1604,    -1,    -1,   257,  1179,  1269,  1604,
      -1,    -1,   281,  1179,  1270,  1604,    -1,  1281,    -1,  1285,
      -1,  1284,    -1,  1272,    -1,  1310,    -1,  1275,    -1,    -1,
     613,   928,  1273,   535,    -1,    -1,   535,    -1,    -1,   622,
      26,  1276,  1274,    -1,   216,    -1,   681,  1297,    -1,   219,
    1297,    -1,   218,  1297,    -1,    -1,  1278,    -1,  1279,    -1,
    1278,  1279,    -1,  1290,  1280,    -1,    -1,   670,  1297,    -1,
      -1,   572,  1282,  1277,  1289,    -1,  1529,    -1,   485,  1529,
     448,    -1,   571,  1283,  1289,    -1,   570,  1288,  1287,  1286,
    1289,    -1,    -1,   210,   921,    -1,   210,   921,     5,   921,
      -1,   665,    -1,   666,    -1,   667,    -1,   668,    -1,  1179,
      -1,    -1,   575,    -1,  1291,    -1,  1290,     5,  1291,    -1,
     928,  1324,    -1,   661,   485,   921,   448,  1309,    -1,   122,
    1309,    -1,   549,   485,    20,   448,  1309,    -1,   467,   485,
      20,   448,  1309,    -1,   444,   485,   921,   448,  1309,    -1,
     641,   485,   921,   448,  1309,    -1,   654,   485,   921,   448,
    1309,    -1,   653,   485,   921,   448,  1309,    -1,    -1,   515,
    1294,    -1,  1295,    -1,  1294,  1295,    -1,   284,    26,    -1,
     275,    26,    -1,   357,    26,    -1,   241,    26,    -1,   313,
      26,    -1,   232,    -1,   401,    25,    -1,   401,  1179,    -1,
     233,    25,    -1,   217,    25,    -1,  1300,    -1,  1296,  1300,
      -1,  1298,   167,    -1,  1298,   169,    -1,  1298,   168,    -1,
    1298,    -1,  1029,    -1,    26,    -1,    -1,   515,  1296,    -1,
     284,  1297,    -1,   275,  1297,    -1,   357,  1297,    -1,   241,
    1297,    -1,   313,  1297,    -1,   314,  1297,    -1,   680,    25,
      -1,   681,  1297,    -1,   685,    -1,   682,    -1,   683,    -1,
     684,    -1,   689,    -1,   686,    -1,   687,    -1,   688,    -1,
     134,  1297,    -1,   135,  1297,    -1,   136,  1297,    -1,   401,
      25,    -1,   233,    25,    -1,   455,    -1,   131,    -1,   132,
      -1,    -1,   567,   671,  1205,    -1,   194,  1205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   519,  1303,  1023,   485,  1304,
    1195,   448,  1305,   827,  1306,  1260,  1307,  1261,  1308,   296,
      -1,    -1,   579,   921,    -1,   569,  1311,    -1,    -1,  1234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,  1313,  1023,
     485,  1314,  1195,   448,  1315,   827,  1316,  1319,  1317,  1261,
    1318,   296,    -1,  1299,  1301,    -1,    -1,    -1,    -1,   212,
     485,    25,     5,  1321,   774,  1322,   448,  1323,   772,    -1,
      -1,   440,    -1,   440,   275,    26,    -1,   440,   275,  1179,
      -1,   659,   928,    -1,   659,   928,  1326,    -1,   659,   928,
     402,  1179,    -1,   659,   928,   220,    -1,   659,   928,  1326,
     402,  1179,    -1,   659,   928,  1326,   220,    -1,   659,   928,
     630,    -1,   659,   928,   597,    -1,    41,    -1,    40,    -1,
    1328,    -1,   229,  1478,    -1,   381,  1478,    -1,   337,  1479,
      -1,    54,  1023,    -1,  1342,    -1,  1330,    -1,    -1,    -1,
     262,  1331,  1478,   485,  1332,  1346,   448,  1335,    -1,    -1,
      -1,   191,  1333,  1478,   485,  1334,  1346,   448,  1335,  1343,
      -1,    -1,  1336,    -1,  1337,    -1,  1336,  1337,    -1,   675,
    1338,    -1,   301,    26,    -1,    66,    26,    -1,   143,    -1,
     144,    -1,  1603,    -1,    -1,  1340,    -1,  1341,    -1,  1340,
    1341,    -1,   675,  1338,    -1,   729,    26,    -1,   162,  1479,
     677,  1478,   485,  1344,   448,  1339,    -1,   109,  1024,    -1,
     110,  1024,    -1,   228,  1478,   648,  1478,    -1,   114,  1478,
      -1,    -1,   324,    -1,  1345,    -1,  1344,     5,  1345,    -1,
    1023,   640,    -1,  1023,   591,    -1,  1023,    -1,  1347,    -1,
    1346,     5,  1347,    -1,  1430,    -1,  1428,    -1,   178,  1023,
      -1,   236,    -1,    64,  1023,  1350,    -1,    65,  1479,   159,
      -1,    65,  1479,   160,    -1,  1351,    -1,  1350,     5,  1351,
      -1,  1352,    -1,  1355,    -1,  1358,    -1,  1363,    -1,  1366,
      -1,  1362,    -1,  1361,    -1,   637,  1353,    -1,   637,   485,
    1354,   448,    -1,  1347,    -1,  1347,   716,  1023,    -1,  1353,
      -1,  1354,     5,  1353,    -1,   594,  1357,    -1,   594,   485,
    1356,   448,    -1,  1357,    -1,  1356,     5,  1357,    -1,  1023,
      -1,   509,  1360,    -1,   509,   485,  1359,   448,    -1,  1360,
      -1,  1359,     5,  1360,    -1,  1347,    -1,   143,    -1,   144,
      -1,   142,    26,    -1,   112,  1428,  1365,    -1,   112,   485,
    1364,   448,    -1,  1428,  1365,    -1,  1364,     5,  1428,  1365,
      -1,    -1,   115,  1023,    -1,   113,  1367,    -1,   113,   485,
    1367,   448,    -1,  1368,    -1,  1367,     5,  1368,    -1,  1023,
      -1,   321,    -1,   288,    -1,   222,  1371,    -1,   201,    -1,
     190,    -1,   177,    -1,   175,    -1,   179,    -1,   235,  1535,
      -1,   287,  1370,   514,  1529,   678,  1529,    -1,   354,  1016,
     514,  1529,   678,  1529,    -1,    -1,  1535,    -1,    -1,   928,
      -1,   576,   928,    -1,   286,    -1,    -1,   305,  1375,  1478,
    1378,  1376,    -1,    -1,   532,  1377,   485,  1380,   448,    -1,
    1515,    -1,    -1,   485,  1379,   448,    -1,  1482,    -1,  1379,
       5,  1482,    -1,  1381,    -1,  1380,     5,  1381,    -1,  1521,
      -1,   536,    -1,    -1,   553,  1383,  1385,  1386,    -1,  1024,
      -1,  1390,  1017,    -1,  1017,    -1,    -1,    -1,   606,  1387,
    1200,    -1,    -1,    -1,   606,  1389,  1200,    -1,   554,    -1,
     607,    -1,   614,    -1,   432,    -1,   399,    -1,   451,    -1,
     435,   928,    -1,   408,   928,    -1,   294,  1478,   207,  1017,
      -1,   294,  1478,  1451,    -1,   567,   671,  1394,    -1,  1395,
      -1,  1394,     5,  1395,    -1,  1396,  1397,    -1,    26,    -1,
    1482,    -1,    -1,   640,    -1,   591,    -1,   332,    -1,   365,
      -1,    -1,   384,    -1,   413,  1402,  1400,    -1,  1577,    -1,
    1577,   664,  1023,    -1,    25,    -1,    -1,  1534,  1404,  1405,
      -1,  1436,    -1,    37,    -1,  1440,    -1,  1399,    -1,  1536,
      -1,  1398,    -1,  1391,    -1,  1392,    -1,  1382,    -1,  1374,
      -1,  1373,    -1,  1505,    -1,  1557,    -1,   558,  1409,   677,
    1478,   678,  1414,  1408,    -1,   520,  1409,   677,  1478,   599,
    1414,    -1,   558,  1407,   678,  1414,    -1,   520,  1407,   599,
    1414,    -1,   450,    -1,   436,    -1,   644,    -1,    -1,   200,
      -1,   669,  1023,    -1,   224,    -1,   638,    -1,  1410,    -1,
    1411,    -1,  1410,     5,  1411,    -1,   525,  1412,    -1,   504,
      -1,   493,    -1,   531,  1412,    -1,   539,    -1,   561,    -1,
      -1,   485,  1413,   448,    -1,  1482,    -1,  1413,     5,  1482,
      -1,  1415,    -1,  1414,     5,  1415,    -1,   517,    -1,  1480,
      -1,   292,  1478,  1417,   669,  1515,  1419,    -1,    -1,   485,
    1418,   448,    -1,  1482,    -1,  1418,     5,  1482,    -1,    -1,
     199,    -1,   545,   485,  1454,   448,    -1,   302,   485,  1423,
     448,  1422,    -1,   352,  1424,    -1,  1425,    -1,  1478,    -1,
    1478,   485,  1425,   448,    -1,  1482,    -1,  1425,     5,  1482,
      -1,   529,   485,  1427,   448,    -1,   416,   485,  1427,   448,
      -1,   315,   485,  1427,   448,    -1,  1482,    -1,  1427,     5,
    1482,    -1,  1426,    -1,  1421,    -1,  1420,    -1,   455,  1485,
      -1,   265,    -1,   264,    -1,   263,    -1,  1023,  1470,  1431,
    1432,    -1,    -1,  1429,    -1,    -1,  1433,    -1,  1434,    -1,
    1433,  1434,    -1,  1435,  1365,    -1,   430,    -1,   215,    -1,
     529,    -1,   416,    -1,  1422,    -1,   545,   485,  1454,   448,
      -1,   315,    -1,   176,  1437,  1439,    -1,  1438,    -1,  1480,
      -1,  1440,    -1,  1439,  1440,    -1,  1416,    -1,  1406,    -1,
     502,  1454,    -1,   425,  1443,    -1,  1520,    -1,  1443,     5,
    1520,    -1,   579,  1454,    -1,   599,  1446,    -1,  1447,    -1,
    1446,     5,  1447,    -1,  1448,    -1,   568,  1448,    -1,   568,
     485,  1449,   448,    -1,  1478,    -1,  1478,  1484,    -1,  1478,
     669,  1484,    -1,  1447,    -1,  1449,     5,  1447,    -1,  1445,
    1451,  1452,  1453,    -1,    -1,  1444,    -1,    -1,  1442,    -1,
      -1,  1441,    -1,  1455,    -1,  1454,     6,  1455,    -1,  1456,
      -1,  1455,     7,  1456,    -1,  1457,    -1,     9,  1457,    -1,
    1468,    -1,   485,  1454,   448,    -1,   497,  1516,    -1,   350,
    1516,    -1,    -1,   496,  1461,    -1,  1522,    -1,  1525,    -1,
    1521,   675,   485,  1463,   448,    -1,  1521,   675,  1516,    -1,
    1521,   483,   485,  1463,   448,    -1,  1521,   483,  1516,    -1,
    1464,    -1,  1463,     5,  1464,    -1,  1583,    -1,  1485,    -1,
      -1,     9,    -1,  1521,  1465,   443,    -1,  1521,  1465,   306,
      -1,  1521,  1467,  1521,    -1,  1521,  1465,   445,  1521,     7,
    1521,    -1,  1521,   609,  1460,  1459,    -1,  1521,   428,  1460,
    1459,    -1,  1521,   726,  1460,  1459,    -1,  1521,   429,  1460,
    1459,    -1,  1521,  1465,    10,  1460,  1459,    -1,    14,    -1,
      17,    -1,    12,    -1,    13,    -1,   725,    -1,    16,    -1,
      15,    -1,  1466,    -1,  1462,    -1,  1458,    -1,    -1,   638,
      -1,   416,    -1,   529,    -1,  1471,    -1,  1472,    -1,  1474,
      -1,   375,    -1,   375,   485,  1475,   448,    -1,    -1,   526,
      -1,   526,   485,    26,   448,    -1,   453,    -1,   453,   485,
    1476,  1473,   448,    -1,   565,   485,  1476,  1473,   448,    -1,
     565,    -1,   590,    -1,   463,    -1,   437,    -1,   376,    -1,
     376,   485,  1475,   448,    -1,   377,    -1,   377,   485,    26,
     448,    -1,   377,   485,    26,     5,    26,   448,    -1,   414,
    1491,   678,  1492,    -1,   414,    -1,   426,  1491,   678,  1492,
      -1,   426,    -1,   426,  1491,   485,    26,   448,   678,  1492,
      -1,   627,    -1,   586,    -1,   478,    -1,   478,   485,    26,
     448,    -1,   478,   485,    26,     5,    26,   448,    -1,    -1,
       5,  1477,    -1,   555,   485,  1476,   448,    -1,   618,    -1,
     355,    -1,   555,    -1,   121,    -1,    26,    -1,    26,    -1,
      26,    -1,    25,   672,  1023,    -1,    25,    -1,  1023,    -1,
    1023,   642,  1023,    -1,  1023,   642,    25,   672,  1023,    -1,
    1023,   664,  1023,    -1,  1023,   664,  1023,   642,  1023,    -1,
    1023,   664,  1023,   642,    25,   672,  1023,    -1,    25,   672,
    1023,    -1,    25,    -1,  1023,    -1,  1023,   642,  1023,    -1,
    1023,   642,    25,   672,  1023,    -1,  1023,   664,  1023,    -1,
    1023,   664,  1023,   642,  1023,    -1,  1023,   664,  1023,   642,
      25,   672,  1023,    -1,  1023,    -1,    -1,   513,    26,   481,
      -1,   513,    26,     5,    26,   481,    -1,  1483,    -1,   664,
    1483,    -1,  1023,  1481,    -1,  1478,   672,  1023,  1481,    -1,
    1478,   672,    20,    -1,  1023,    -1,    25,    -1,  1029,    -1,
      26,    -1,  1487,    -1,   451,  1489,    -1,   451,  1488,    -1,
      -1,  1491,   678,  1492,    -1,    -1,  1490,   678,  1490,    -1,
     634,    -1,   566,    -1,   643,    -1,   605,    -1,   508,    -1,
     524,    -1,   423,    -1,   423,   485,    26,   448,    -1,   634,
      -1,   566,    -1,   643,    -1,   605,    -1,   508,    -1,   524,
      -1,   423,    -1,   634,    -1,   566,    -1,   643,    -1,   605,
      -1,   508,    -1,   524,    -1,   423,    -1,   423,   485,    26,
     448,    -1,  1023,    -1,  1023,   664,  1023,    -1,    25,    -1,
    1534,   556,  1017,    -1,    -1,  1534,   454,  1384,   491,   648,
    1503,  1496,    -1,    -1,  1534,   454,  1384,   491,   157,   648,
    1504,  1497,    -1,    -1,  1534,   454,  1384,   195,  1504,  1498,
      -1,    -1,  1534,   454,  1384,   196,   157,   648,  1504,  1499,
      -1,    -1,   344,    -1,   343,  1501,    -1,  1502,    -1,  1501,
       5,  1502,    -1,  1023,    -1,  1023,   672,  1023,    -1,    25,
     672,  1023,   672,  1023,    -1,  1504,    -1,  1374,    -1,  1236,
      -1,  1506,    -1,  1506,    -1,    -1,    -1,   525,  1517,  1507,
    1518,  1508,  1514,  1450,  1512,  1500,    -1,   525,  1517,  1518,
    1450,  1512,    -1,  1511,    -1,  1529,    -1,   525,  1517,  1518,
    1514,  1450,  1512,    -1,    -1,   578,  1469,  1510,    -1,  1393,
      -1,   389,  1513,  1343,    -1,  1393,   389,  1513,  1343,    -1,
    1023,    -1,    -1,   606,  1200,    -1,   525,  1517,  1518,  1450,
      -1,   485,   525,  1517,  1518,  1450,   448,    -1,    -1,   638,
      -1,   416,    -1,   529,    -1,  1519,    -1,  1518,     5,  1519,
      -1,  1521,    -1,  1521,  1023,    -1,  1521,   669,  1023,    -1,
    1521,    -1,  1522,    -1,    19,  1522,    -1,    18,  1522,    -1,
    1523,    -1,  1583,    -1,  1516,    -1,   638,  1516,    -1,   639,
    1516,    -1,   623,  1516,    -1,   664,  1023,    -1,   664,  1023,
     672,  1023,    -1,  1522,    21,  1521,    -1,  1522,  1543,    -1,
    1522,    20,  1521,    -1,  1522,    18,  1521,    -1,  1522,    19,
    1521,    -1,  1485,    -1,   537,    -1,   482,    -1,   629,    -1,
      20,    -1,   122,    -1,   641,   485,  1469,  1521,   448,    -1,
     653,   485,  1469,  1521,   448,    -1,   654,   485,  1469,  1521,
     448,    -1,   661,   485,  1469,  1521,   448,    -1,   549,   485,
    1469,  1521,   448,    -1,  1023,   485,  1524,   448,    -1,   590,
     485,  1524,   448,    -1,   485,  1521,   448,    -1,   498,   485,
    1544,   448,    -1,  1545,    -1,  1547,    -1,  1521,    -1,  1524,
       5,  1521,    -1,  1485,    -1,  1534,   404,  1533,  1528,  1510,
      -1,  1534,   393,  1533,  1528,   305,  1478,  1530,    -1,  1534,
     393,  1533,  1528,  1179,    -1,    -1,   379,  1529,    -1,    25,
      -1,  1179,    -1,    -1,   485,  1531,   448,    -1,  1532,    -1,
    1531,     5,  1532,    -1,  1023,    -1,    25,    -1,  1179,    -1,
      -1,   323,  1535,   648,    -1,  1024,    -1,  1541,    -1,  1540,
      -1,  1537,    -1,   372,  1538,   678,  1538,    -1,   353,  1478,
     672,  1539,   678,  1539,    -1,  1023,    -1,  1023,    -1,   278,
    1478,    -1,   348,  1478,  1542,    -1,   327,    -1,   231,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   451,     5,  1491,   678,  1492,    -1,  1583,     5,
    1491,   678,  1492,    -1,   451,  1491,   678,  1492,    -1,  1521,
       5,  1491,   678,  1492,    -1,  1546,    -1,  1546,  1491,   678,
    1492,    -1,    38,    -1,  1548,    -1,  1548,  1491,   485,    26,
     448,   678,  1492,    -1,  1548,  1491,   678,  1492,    -1,    39,
      -1,    -1,   660,  1550,  1551,   246,    -1,  1552,    -1,  1551,
    1552,    -1,    33,    -1,  1553,    -1,  1555,    -1,    -1,   247,
    1554,  1583,    -1,    -1,   606,  1556,  1200,    -1,    -1,    -1,
     531,  1478,  1558,  1561,  1559,  1560,    -1,    -1,   207,  1017,
      -1,   579,  1454,    -1,   107,  1565,   448,    14,   485,  1566,
     448,    -1,   103,  1566,   448,    -1,   104,  1566,   448,    -1,
     636,  1562,    -1,   106,  1566,    -1,   105,  1566,    -1,  1564,
      -1,  1562,     5,  1564,    -1,  1482,    -1,  1563,    14,  1567,
      -1,  1563,    -1,  1565,     5,  1563,    -1,  1567,    -1,  1566,
       5,  1567,    -1,   536,    -1,  1568,    -1,  1569,    -1,    19,
    1569,    -1,    18,  1569,    -1,  1571,    -1,  1516,    -1,   664,
    1023,    -1,   664,  1023,   672,  1023,    -1,   664,  1023,   513,
      26,   481,    -1,   664,  1023,   672,  1023,   513,    26,   481,
      -1,   664,  1023,   513,    26,     5,    26,   481,    -1,   664,
    1023,   672,  1023,   513,    26,     5,    26,   481,    -1,  1570,
      -1,  1485,    -1,   537,    -1,   482,    -1,   629,    -1,   122,
      -1,  1569,    21,  1568,    -1,  1569,  1543,    -1,  1569,    20,
    1568,    -1,  1569,    18,  1568,    -1,  1569,    19,  1568,    -1,
     641,   485,  1469,  1568,   448,    -1,   653,   485,  1469,  1568,
     448,    -1,   654,   485,  1469,  1568,   448,    -1,   661,   485,
    1469,  1568,   448,    -1,   549,   485,  1469,  1568,   448,    -1,
    1023,   485,  1572,   448,    -1,   590,   485,  1572,   448,    -1,
     485,  1568,   448,    -1,   498,   485,  1544,   448,    -1,  1545,
      -1,  1547,    -1,  1583,    -1,  1568,    -1,  1572,     5,  1568,
      -1,    -1,   438,  1208,   609,  1574,  1575,    -1,  1576,    -1,
    1575,     5,  1576,    -1,  1478,   672,  1482,    -1,  1478,   672,
      20,    -1,  1579,    -1,  1579,    -1,   247,  1580,    -1,  1580,
      -1,  1581,    -1,    25,   672,  1581,    -1,  1582,    -1,  1581,
     672,  1582,    -1,  1581,   672,    20,    -1,  1584,    -1,  1023,
      -1,  1578,    -1,  1578,   475,  1578,    -1,  1023,  1585,    -1,
     513,  1586,   481,    -1,   513,  1586,   481,   513,  1586,   481,
      -1,  1587,    -1,  1586,     5,  1587,    -1,   742,    -1,    34,
      -1,    -1,    -1,   580,  1590,   928,  1591,  1604,   383,    -1,
      -1,   711,   971,    -1,    -1,   714,    -1,   238,    -1,   333,
    1018,    -1,   127,  1018,    -1,   363,    -1,   362,    -1,   364,
    1020,  1592,  1593,    -1,   546,   971,  1593,    -1,   161,    -1,
     192,  1018,    -1,   928,   619,     5,   928,   449,    -1,   562,
     928,    -1,   320,  1018,    -1,   158,  1599,     8,  1600,  1598,
      -1,    -1,   599,   928,    -1,  1023,    -1,  1023,    -1,   304,
    1018,    -1,   307,  1018,   678,   928,     5,   928,    -1,   307,
    1018,   671,   928,     5,   928,    -1,    27,    -1,    -1,  1606,
      -1,  1607,  1289,    -1,  1605,    -1,  1606,  1605,    -1,    -1,
    1608,  1609,    -1,   735,    -1,   736,    -1,   737,    -1,   738,
      -1,   755,    -1,   779,    -1,   800,    -1,   801,    -1,   807,
      -1,   826,    -1,   900,    -1,   901,    -1,   902,    -1,   903,
      -1,   914,    -1,   915,    -1,   916,    -1,   917,    -1,   918,
      -1,   919,    -1,   920,    -1,   973,    -1,  1004,    -1,  1008,
      -1,  1030,    -1,  1032,    -1,  1035,    -1,  1036,    -1,  1037,
      -1,  1038,    -1,  1051,    -1,  1061,    -1,  1085,    -1,  1086,
      -1,  1088,    -1,  1092,    -1,  1107,    -1,  1108,    -1,  1112,
      -1,  1113,    -1,  1114,    -1,  1115,    -1,  1125,    -1,  1140,
      -1,  1156,    -1,  1167,    -1,  1168,    -1,  1169,    -1,  1173,
      -1,  1210,    -1,  1213,    -1,  1215,    -1,  1221,    -1,  1222,
      -1,  1225,    -1,  1228,    -1,  1233,    -1,  1235,    -1,  1237,
      -1,  1240,    -1,  1247,    -1,  1252,    -1,  1257,    -1,  1258,
      -1,  1259,    -1,  1271,    -1,  1325,    -1,  1327,    -1,  1329,
      -1,  1348,    -1,  1349,    -1,  1369,    -1,  1372,    -1,  1401,
      -1,  1403,    -1,  1494,    -1,  1495,    -1,  1526,    -1,  1527,
      -1,  1549,    -1,  1573,    -1,  1588,    -1,  1589,    -1,  1594,
      -1,  1595,    -1,  1597,    -1,  1601,    -1,  1602,    -1
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
    3458,  3462,  3463,  3468,  3472,  3477,  3481,  3496,  3500,  3506,
    3495,  3519,  3520,  3532,  3538,  3532,  3552,  3552,  3554,  3555,
    3559,  3559,  3563,  3563,  3568,  3568,  3575,  3576,  3580,  3580,
    3584,  3584,  3589,  3589,  3596,  3600,  3601,  3602,  3607,  3607,
    3610,  3610,  3614,  3614,  3618,  3618,  3622,  3622,  3627,  3627,
    3632,  3632,  3637,  3637,  3642,  3642,  3658,  3662,  3657,  3670,
    3673,  3687,  3704,  3705,  3706,  3707,  3708,  3709,  3710,  3713,
    3713,  3716,  3718,  3721,  3724,  3727,  3732,  3737,  3740,  3745,
    3750,  3755,  3762,  3763,  3770,  3777,  3779,  3785,  3790,  3795,
    3800,  3800,  3803,  3809,  3814,  3817,  3824,  3824,  3826,  3829,
    3832,  3837,  3842,  3847,  3854,  3865,  3865,  3927,  3935,  3936,
    3944,  3951,  3951,  3955,  3960,  3966,  3970,  3974,  3980,  3984,
    3988,  3994,  3994,  4002,  4003,  4007,  4007,  4011,  4012,  4015,
    4018,  4018,  4021,  4023,  4023,  4026,  4028,  4028,  4029,  4031,
    4031,  4040,  4047,  4038,  4068,  4068,  4068,  4071,  4073,  4071,
    4080,  4083,  4090,  4095,  4106,  4106,  4110,  4116,  4116,  4120,
    4121,  4125,  4135,  4136,  4137,  4140,  4142,  4147,  4147,  4151,
    4150,  4158,  4157,  4164,  4164,  4170,  4170,  4177,  4177,  4183,
    4183,  4189,  4189,  4195,  4195,  4199,  4199,  4200,  4200,  4201,
    4201,  4202,  4202,  4206,  4206,  4217,  4221,  4227,  4231,  4236,
    4241,  4246,  4247,  4248,  4252,  4251,  4264,  4269,  4274,  4274,
    4290,  4296,  4297,  4298,  4299,  4300,  4310,  4324,  4324,  4327,
    4334,  4335,  4336,  4337,  4338,  4339,  4340,  4341,  4342,  4347,
    4347,  4349,  4352,  4352,  4354,  4358,  4361,  4362,  4365,  4365,
    4370,  4373,  4374,  4375,  4376,  4377,  4378,  4379,  4380,  4381,
    4382,  4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,  4394,
    4412,  4412,  4412,  4439,  4450,  4457,  4463,  4469,  4475,  4487,
    4510,  4511,  4514,  4518,  4517,  4535,  4535,  4539,  4540,  4548,
    4549,  4550,  4551,  4552,  4553,  4554,  4561,  4562,  4564,  4565,
    4569,  4574,  4575,  4576,  4577,  4578,  4579,  4580,  4581,  4582,
    4585,  4587,  4587,  4589,  4593,  4593,  4602,  4608,  4624,  4630,
    4601,  4644,  4658,  4669,  4657,  4682,  4689,  4689,  4694,  4700,
    4708,  4713,  4714,  4717,  4720,  4720,  4728,  4734,  4745,  4746,
    4754,  4760,  4754,  4771,  4772,  4776,  4776,  4783,  4783,  4798,
    4798,  4812,  4823,  4822,  4834,  4830,  4847,  4844,  4857,  4857,
    4859,  4860,  4862,  4863,  4866,  4867,  4868,  4870,  4875,  4880,
    4886,  4888,  4889,  4892,  4893,  4896,  4898,  4905,  4908,  4911,
    4914,  4918,  4922,  4923,  4924,  4925,  4926,  4930,  4935,  4935,
    4938,  4965,  5023,  5023,  5026,  5030,  5034,  5077,  5119,  5120,
    5121,  5124,  5138,  5150,  5150,  5155,  5156,  5162,  5227,  5232,
    5239,  5244,  5252,  5258,  5291,  5294,  5295,  5336,  5379,  5380,
    5384,  5385,  5389,  5442,  5447,  5451,  5456,  5467,  5474,  5482,
    5482,  5485,  5486,  5487,  5488,  5489,  5492,  5495,  5501,  5504,
    5508,  5513,  5521,  5526,  5533,  5535,  5541,  5543,  5543,  5543,
    5563,  5570,  5577,  5580,  5594,  5601,  5602,  5605,  5606,  5610,
    5616,  5621,  5627,  5628,  5633,  5637,  5637,  5641,  5642,  5645,
    5646,  5650,  5658,  5661,  5667,  5668,  5670,  5672,  5676,  5676,
    5677,  5682,  5690,  5691,  5696,  5697,  5699,  5712,  5714,  5715,
    5718,  5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,
    5728,  5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,
    5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,  5749,  5750,
    5754,  5755,  5769,  5777,  5777,  5779,  5783,  5787,  5791,  5795,
    5800,  5815,  5813,  5833,  5834,  5838,  5843,  5844,  5848,  5849,
    5851,  5852,  5854,  5854,  5863,  5872,  5872,  5882,  5883,  5888,
    5889,  5892,  5905,  5919,  5923,  5927,  5931,  5938,  5939,  5942,
    5942,  5946,  5949,  5949,  5951,  5957,  5965,  5971,  5973,  5977,
    5980,  5980,  5983,  5983,  5988,  5988,  5997,  5997,  6001,  6001,
    6002,  6002,  6003,  6003,  6017,  6017,  6037,  6038,  6039,  6040,
    6041,  6042,  6045,  6045,  6051,  6051,  6054,  6054,  6070,  6071,
    6072,  6081,  6093,  6094,  6097,  6098,  6101,  6104,  6104,  6109,
    6109,  6132,  6133,  6139,  6144,  6150,  6151,  6152,  6156,  6157,
    6158,  6159,  6163,  6173,  6175,  6180,  6183,  6188,  6194,  6201,
    6208,  6217,  6224,  6231,  6238,  6245,  6254,  6254,  6256,  6256,
    6259,  6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,
    6271,  6271,  6274,  6275,  6276,  6277,  6280,  6280,  6283,  6283,
    6286,  6287,  6288,  6289,  6290,  6291,  6292,  6293,  6295,  6296,
    6297,  6298,  6300,  6301,  6302,  6303,  6305,  6306,  6307,  6308,
    6309,  6310,  6311,  6312,  6316,  6324,  6334,  6347,  6358,  6369,
    6373,  6377,  6383,  6346,  6396,  6399,  6407,  6419,  6421,  6426,
    6436,  6446,  6449,  6453,  6461,  6425,  6470,  6474,  6478,  6482,
    6474,  6492,  6493,  6494,  6495,  6500,  6501,  6502,  6503,  6504,
    6505,  6506,  6507,  6511,  6512,  6515,  6520,  6527,  6528,  6529,
    6534,  6535,  6541,  6541,  6541,  6546,  6546,  6546,  6554,  6555,
    6559,  6560,  6565,  6566,  6567,  6568,  6569,  6572,  6574,  6574,
    6577,  6578,  6582,  6583,  6586,  6587,  6590,  6593,  6596,  6602,
    6603,  6615,  6616,  6621,  6622,  6623,  6627,  6630,  6636,  6639,
    6647,  6648,  6654,  6658,  6662,  6668,  6671,  6680,  6683,  6686,
    6689,  6692,  6695,  6698,  6705,  6708,  6715,  6718,  6724,  6727,
    6734,  6737,  6744,  6745,  6750,  6754,  6757,  6763,  6766,  6772,
    6779,  6780,  6784,  6794,  6797,  6803,  6805,  6810,  6811,  6815,
    6817,  6823,  6824,  6837,  6849,  6850,  6851,  6852,  6853,  6854,
    6855,  6856,  6857,  6860,  6863,  6869,  6869,  6875,  6875,  6886,
    6899,  6909,  6909,  6914,  6914,  6918,  6922,  6923,  6929,  6930,
    6935,  6939,  6946,  6949,  6956,  6955,  6966,  6970,  6974,  6981,
    6984,  6984,  6997,  7001,  7001,  7016,  7018,  7020,  7022,  7024,
    7026,  7028,  7030,  7036,  7046,  7053,  7058,  7059,  7063,  7066,
    7067,  7070,  7071,  7072,  7075,  7080,  7087,  7088,  7095,  7107,
    7108,  7109,  7112,  7112,  7117,  7122,  7127,  7132,  7133,  7136,
    7137,  7142,  7147,  7151,  7156,  7157,  7161,  7168,  7169,  7170,
    7171,  7176,  7177,  7178,  7181,  7182,  7183,  7187,  7188,  7189,
    7193,  7194,  7198,  7199,  7200,  7201,  7202,  7203,  7206,  7207,
    7212,  7213,  7218,  7219,  7224,  7225,  7230,  7235,  7236,  7241,
    7242,  7246,  7247,  7252,  7259,  7264,  7269,  7273,  7274,  7279,
    7280,  7286,  7289,  7293,  7298,  7299,  7305,  7308,  7311,  7318,
    7319,  7320,  7321,  7335,  7340,  7341,  7344,  7346,  7353,  7356,
    7362,  7370,  7374,  7378,  7382,  7387,  7390,  7393,  7400,  7407,
    7412,  7416,  7417,  7423,  7426,  7437,  7444,  7450,  7453,  7460,
    7467,  7473,  7474,  7480,  7481,  7482,  7485,  7486,  7493,  7500,
    7500,  7504,  7512,  7513,  7516,  7519,  7524,  7525,  7530,  7533,
    7539,  7542,  7548,  7551,  7557,  7560,  7567,  7568,  7597,  7598,
    7602,  7610,  7615,  7618,  7621,  7624,  7630,  7631,  7635,  7638,
    7641,  7642,  7647,  7650,  7653,  7656,  7659,  7662,  7665,  7668,
    7673,  7679,  7680,  7681,  7682,  7685,  7686,  7687,  7692,  7695,
    7699,  7705,  7706,  7707,  7708,  7720,  7721,  7722,  7726,  7727,
    7731,  7732,  7733,  7734,  7735,  7737,  7746,  7753,  7754,  7755,
    7756,  7757,  7758,  7759,  7761,  7763,  7765,  7766,  7768,  7769,
    7771,  7772,  7773,  7774,  7776,  7780,  7781,  7787,  7789,  7790,
    7791,  7792,  7797,  7801,  7805,  7809,  7816,  7820,  7821,  7822,
    7830,  7831,  7832,  7843,  7850,  7855,  7856,  7857,  7865,  7866,
    7867,  7884,  7893,  7894,  7895,  7899,  7902,  7907,  7912,  7917,
    7925,  7929,  7934,  7935,  7943,  7946,  7949,  7963,  7977,  7990,
    7991,  7995,  7995,  7995,  7995,  7995,  7995,  7996,  7999,  8016,
    8016,  8016,  8016,  8016,  8016,  8016,  8017,  8017,  8017,  8017,
    8017,  8017,  8017,  8017,  8020,  8021,  8022,  8025,  8034,  8034,
    8040,  8040,  8047,  8047,  8053,  8053,  8061,  8062,  8063,  8066,
    8066,  8069,  8070,  8071,  8082,  8085,  8091,  8096,  8103,  8116,
    8117,  8114,  8135,  8146,  8149,  8154,  8166,  8169,  8173,  8176,
    8177,  8187,  8190,  8191,  8200,  8209,  8214,  8215,  8216,  8217,
    8224,  8227,  8233,  8236,  8243,  8255,  8264,  8267,  8270,  8276,
    8284,  8287,  8288,  8289,  8290,  8291,  8294,  8300,  8302,  8304,
    8306,  8308,  8310,  8311,  8312,  8313,  8314,  8315,  8316,  8318,
    8320,  8322,  8324,  8326,  8328,  8330,  8331,  8333,  8334,  8340,
    8341,  8348,  8351,  8359,  8363,  8370,  8370,  8374,  8374,  8379,
    8379,  8383,  8383,  8387,  8393,  8393,  8396,  8396,  8402,  8409,
    8410,  8411,  8415,  8416,  8419,  8420,  8424,  8430,  8440,  8441,
    8449,  8450,  8451,  8452,  8453,  8454,  8458,  8459,  8460,  8461,
    8465,  8466,  8470,  8486,  8487,  8488,  8492,  8506,  8506,  8518,
    8519,  8523,  8524,  8525,  8849,  8849,  8856,  8856,  8944,  8948,
    8944,  8957,  8961,  8967,  8975,  8985,  8995,  9007,  9010,  9029,
    9055,  9058,  9064,  9067,  9072,  9075,  9083,  9091,  9104,  9107,
    9115,  9118,  9121,  9129,  9133,  9134,  9135,  9136,  9137,  9138,
    9139,  9140,  9144,  9145,  9146,  9147,  9148,  9154,  9155,  9156,
    9157,  9158,  9159,  9160,  9161,  9162,  9163,  9164,  9165,  9166,
    9167,  9168,  9169,  9174,  9180,  9181,  9189,  9189,  9197,  9197,
    9201,  9205,  9220,  9235,  9241,  9243,  9251,  9252,  9256,  9257,
    9260,  9267,  9270,  9299,  9325,  9379,  9415,  9424,  9435,  9438,
    9443,  9457,  9471,  9474,  9470,  9493,  9493,  9499,  9500,  9503,
    9504,  9505,  9506,  9507,  9508,  9509,  9520,  9523,  9528,  9532,
    9537,  9541,  9546,  9550,  9553,  9557,  9560,  9565,  9569,  9580,
    9586,  9586,  9587,  9588,  9595,  9605,  9605,  9607,  9608,  9609,
    9610,  9611,  9612,  9613,  9614,  9615,  9616,  9617,  9618,  9619,
    9620,  9621,  9622,  9623,  9624,  9625,  9626,  9627,  9628,  9629,
    9630,  9631,  9632,  9633,  9634,  9635,  9636,  9637,  9638,  9639,
    9640,  9641,  9642,  9643,  9644,  9645,  9646,  9647,  9648,  9649,
    9650,  9651,  9652,  9653,  9654,  9655,  9656,  9657,  9658,  9659,
    9660,  9661,  9662,  9663,  9664,  9665,  9666,  9667,  9668,  9669,
    9670,  9671,  9672,  9673,  9674,  9675,  9676,  9677,  9678,  9679,
    9680,  9681,  9682,  9683,  9684,  9685,  9686,  9687,  9688,  9689,
    9690,  9691,  9692,  9693,  9694
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
     969,   970,   970,   971,   971,   972,   972,   974,   975,   976,
     973,   977,   977,   979,   980,   978,   981,   981,   982,   982,
     983,   983,   985,   984,   986,   984,   987,   987,   988,   988,
     990,   989,   991,   989,   992,   993,   993,   993,   994,   994,
     995,   995,   996,   996,   997,   997,   999,   998,  1000,   998,
    1001,   998,  1002,   998,  1003,   998,  1005,  1006,  1004,  1007,
    1007,  1008,  1009,  1009,  1009,  1009,  1009,  1009,  1009,  1010,
    1010,  1011,  1012,  1013,  1014,  1014,  1014,  1014,  1014,  1014,
    1014,  1014,  1015,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1022,  1023,  1024,  1025,  1025,  1026,  1026,  1027,  1027,
    1027,  1027,  1027,  1027,  1028,  1029,  1029,  1030,  1031,  1031,
    1032,  1033,  1033,  1034,  1035,  1036,  1036,  1036,  1037,  1037,
    1037,  1039,  1038,  1040,  1040,  1041,  1041,  1042,  1042,  1043,
    1044,  1044,  1045,  1046,  1046,  1047,  1048,  1048,  1049,  1050,
    1050,  1052,  1053,  1051,  1054,  1055,  1054,  1056,  1057,  1054,
    1058,  1058,  1059,  1060,  1062,  1061,  1061,  1063,  1063,  1064,
    1064,  1065,  1066,  1066,  1066,  1067,  1067,  1068,  1068,  1070,
    1069,  1071,  1069,  1072,  1069,  1073,  1069,  1074,  1069,  1075,
    1069,  1076,  1069,  1077,  1069,  1078,  1069,  1079,  1069,  1080,
    1069,  1081,  1069,  1082,  1069,  1083,  1083,  1084,  1084,  1085,
    1086,  1087,  1087,  1087,  1089,  1088,  1090,  1090,  1091,  1090,
    1092,  1093,  1093,  1093,  1093,  1093,  1093,  1094,  1094,  1095,
    1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1096,  1098,
    1097,  1097,  1100,  1099,  1101,  1102,  1103,  1103,  1104,  1104,
    1105,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,
    1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1106,  1107,
    1109,  1110,  1108,  1111,  1111,  1112,  1113,  1114,  1115,  1115,
    1116,  1116,  1117,  1119,  1118,  1120,  1120,  1121,  1121,  1122,
    1122,  1122,  1122,  1122,  1122,  1122,  1123,  1123,  1124,  1124,
    1125,  1126,  1126,  1126,  1126,  1126,  1126,  1126,  1126,  1126,
    1127,  1128,  1128,  1129,  1130,  1130,  1132,  1133,  1134,  1135,
    1131,  1136,  1138,  1139,  1137,  1140,  1141,  1141,  1142,  1142,
    1143,  1144,  1144,  1145,  1147,  1146,  1148,  1148,  1148,  1148,
    1150,  1151,  1149,  1152,  1152,  1154,  1153,  1155,  1153,  1157,
    1156,  1158,  1160,  1159,  1161,  1159,  1162,  1159,  1163,  1163,
    1164,  1164,  1165,  1165,  1166,  1166,  1166,  1167,  1168,  1169,
    1170,  1170,  1170,  1171,  1171,  1172,  1172,  1173,  1174,  1174,
    1174,  1174,  1175,  1175,  1175,  1175,  1175,  1176,  1177,  1177,
    1178,  1179,  1180,  1180,  1181,  1182,  1182,  1182,  1182,  1182,
    1182,  1183,  1184,  1185,  1185,  1186,  1186,  1187,  1188,  1188,
    1189,  1189,  1190,  1191,  1192,  1192,  1192,  1192,  1192,  1192,
    1193,  1193,  1194,  1195,  1195,  1196,  1196,  1197,  1197,  1198,
    1198,  1199,  1199,  1199,  1199,  1199,  1200,  1200,  1201,  1201,
    1202,  1202,  1203,  1204,  1205,  1205,  1206,  1207,  1207,  1207,
    1208,  1208,  1209,  1209,  1210,  1211,  1211,  1212,  1212,  1213,
    1214,  1215,  1216,  1216,  1217,  1218,  1218,  1219,  1219,  1220,
    1220,  1221,  1222,  1222,  1223,  1223,  1223,  1223,  1224,  1224,
    1224,  1225,  1226,  1226,  1227,  1227,  1227,  1228,  1229,  1229,
    1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,
    1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,
    1230,  1230,  1230,  1230,  1230,  1230,  1230,  1230,  1231,  1231,
    1232,  1232,  1233,  1234,  1234,  1235,  1235,  1235,  1235,  1235,
    1236,  1238,  1237,  1239,  1239,  1240,  1241,  1241,  1242,  1242,
    1243,  1243,  1245,  1244,  1246,  1248,  1247,  1249,  1249,  1250,
    1250,  1251,  1251,  1252,  1252,  1252,  1252,  1253,  1253,  1254,
    1254,  1255,  1256,  1256,  1257,  1258,  1259,  1260,  1261,  1261,
    1262,  1262,  1264,  1263,  1265,  1263,  1266,  1263,  1267,  1263,
    1268,  1263,  1269,  1263,  1270,  1263,  1271,  1271,  1271,  1271,
    1271,  1271,  1273,  1272,  1274,  1274,  1276,  1275,  1275,  1275,
    1275,  1275,  1277,  1277,  1278,  1278,  1279,  1280,  1280,  1282,
    1281,  1283,  1283,  1284,  1285,  1286,  1286,  1286,  1287,  1287,
    1287,  1287,  1288,  1289,  1289,  1290,  1290,  1291,  1292,  1292,
    1292,  1292,  1292,  1292,  1292,  1292,  1293,  1293,  1294,  1294,
    1295,  1295,  1295,  1295,  1295,  1295,  1295,  1295,  1295,  1295,
    1296,  1296,  1297,  1297,  1297,  1297,  1298,  1298,  1299,  1299,
    1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,
    1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1300,
    1300,  1300,  1300,  1300,  1301,  1301,  1301,  1303,  1304,  1305,
    1306,  1307,  1308,  1302,  1309,  1309,  1310,  1311,  1311,  1313,
    1314,  1315,  1316,  1317,  1318,  1312,  1319,  1321,  1322,  1323,
    1320,  1324,  1324,  1324,  1324,  1325,  1325,  1325,  1325,  1325,
    1325,  1325,  1325,  1326,  1326,  1327,  1328,  1328,  1328,  1328,
    1329,  1329,  1331,  1332,  1330,  1333,  1334,  1330,  1335,  1335,
    1336,  1336,  1337,  1337,  1337,  1337,  1337,  1338,  1339,  1339,
    1340,  1340,  1341,  1341,  1342,  1342,  1342,  1342,  1342,  1343,
    1343,  1344,  1344,  1345,  1345,  1345,  1346,  1346,  1347,  1347,
    1348,  1348,  1349,  1349,  1349,  1350,  1350,  1351,  1351,  1351,
    1351,  1351,  1351,  1351,  1352,  1352,  1353,  1353,  1354,  1354,
    1355,  1355,  1356,  1356,  1357,  1358,  1358,  1359,  1359,  1360,
    1361,  1361,  1362,  1363,  1363,  1364,  1364,  1365,  1365,  1366,
    1366,  1367,  1367,  1368,  1369,  1369,  1369,  1369,  1369,  1369,
    1369,  1369,  1369,  1369,  1369,  1370,  1370,  1371,  1371,  1372,
    1373,  1375,  1374,  1377,  1376,  1376,  1378,  1378,  1379,  1379,
    1380,  1380,  1381,  1381,  1383,  1382,  1384,  1385,  1385,  1386,
    1387,  1386,  1388,  1389,  1388,  1390,  1390,  1390,  1390,  1390,
    1390,  1390,  1390,  1391,  1392,  1393,  1394,  1394,  1395,  1396,
    1396,  1397,  1397,  1397,  1398,  1399,  1400,  1400,  1401,  1402,
    1402,  1402,  1404,  1403,  1405,  1405,  1405,  1405,  1405,  1405,
    1405,  1405,  1405,  1405,  1405,  1405,  1405,  1406,  1406,  1406,
    1406,  1407,  1407,  1407,  1408,  1408,  1408,  1409,  1409,  1409,
    1410,  1410,  1411,  1411,  1411,  1411,  1411,  1411,  1412,  1412,
    1413,  1413,  1414,  1414,  1415,  1415,  1416,  1417,  1417,  1418,
    1418,  1419,  1419,  1420,  1421,  1422,  1423,  1424,  1424,  1425,
    1425,  1426,  1426,  1426,  1427,  1427,  1428,  1428,  1428,  1429,
    1429,  1429,  1429,  1430,  1431,  1431,  1432,  1432,  1433,  1433,
    1434,  1435,  1435,  1435,  1435,  1435,  1435,  1435,  1436,  1437,
    1438,  1439,  1439,  1440,  1440,  1441,  1442,  1443,  1443,  1444,
    1445,  1446,  1446,  1447,  1447,  1447,  1448,  1448,  1448,  1449,
    1449,  1450,  1451,  1451,  1452,  1452,  1453,  1453,  1454,  1454,
    1455,  1455,  1456,  1456,  1457,  1457,  1458,  1458,  1459,  1459,
    1460,  1461,  1462,  1462,  1462,  1462,  1463,  1463,  1464,  1464,
    1465,  1465,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1467,  1467,  1467,  1467,  1467,  1467,  1467,  1468,  1468,
    1468,  1469,  1469,  1469,  1469,  1470,  1470,  1470,  1471,  1471,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1472,  1472,  1472,  1473,  1473,  1474,  1474,  1474,
    1474,  1474,  1475,  1476,  1477,  1478,  1478,  1478,  1478,  1478,
    1478,  1478,  1478,  1479,  1479,  1479,  1479,  1479,  1479,  1479,
    1479,  1480,  1481,  1481,  1481,  1482,  1482,  1483,  1483,  1483,
    1484,  1485,  1485,  1485,  1485,  1486,  1487,  1488,  1488,  1489,
    1489,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,  1491,
    1491,  1491,  1491,  1491,  1491,  1491,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1493,  1493,  1493,  1494,  1496,  1495,
    1497,  1495,  1498,  1495,  1499,  1495,  1500,  1500,  1500,  1501,
    1501,  1502,  1502,  1502,  1503,  1503,  1504,  1504,  1505,  1507,
    1508,  1506,  1509,  1510,  1510,  1511,  1512,  1512,  1512,  1512,
    1512,  1513,  1514,  1514,  1515,  1516,  1517,  1517,  1517,  1517,
    1518,  1518,  1519,  1519,  1519,  1520,  1521,  1521,  1521,  1522,
    1522,  1522,  1522,  1522,  1522,  1522,  1522,  1523,  1523,  1523,
    1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,
    1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1523,  1524,
    1524,  1525,  1526,  1527,  1527,  1528,  1528,  1529,  1529,  1530,
    1530,  1531,  1531,  1532,  1533,  1533,  1534,  1534,  1535,  1536,
    1536,  1536,  1537,  1537,  1538,  1539,  1540,  1541,  1542,  1542,
    1543,  1543,  1543,  1543,  1543,  1543,  1544,  1544,  1544,  1544,
    1545,  1545,  1546,  1547,  1547,  1547,  1548,  1550,  1549,  1551,
    1551,  1552,  1552,  1552,  1554,  1553,  1556,  1555,  1558,  1559,
    1557,  1560,  1560,  1560,  1561,  1561,  1561,  1561,  1561,  1561,
    1562,  1562,  1563,  1564,  1565,  1565,  1566,  1566,  1567,  1567,
    1568,  1568,  1568,  1569,  1569,  1569,  1569,  1569,  1569,  1569,
    1569,  1569,  1569,  1569,  1569,  1569,  1569,  1570,  1570,  1570,
    1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,  1570,
    1570,  1570,  1570,  1571,  1572,  1572,  1574,  1573,  1575,  1575,
    1576,  1576,  1577,  1578,  1579,  1579,  1580,  1580,  1581,  1581,
    1581,  1582,  1582,  1583,  1583,  1584,  1585,  1585,  1586,  1586,
    1587,  1588,  1590,  1591,  1589,  1592,  1592,  1593,  1593,  1594,
    1594,  1594,  1594,  1594,  1594,  1594,  1595,  1595,  1596,  1596,
    1597,  1597,  1598,  1598,  1599,  1600,  1601,  1602,  1602,  1603,
    1604,  1604,  1605,  1606,  1606,  1608,  1607,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,  1609,
    1609,  1609,  1609,  1609,  1609
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
       1,     1,     1,     1,     1,     1,     1,     7,     6,     4,
       4,     1,     1,     1,     0,     1,     2,     1,     1,     1,
       1,     3,     2,     1,     1,     2,     1,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     6,     0,     3,     1,
       3,     0,     1,     4,     5,     2,     1,     1,     4,     1,
       3,     4,     4,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     4,     0,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     3,     1,
       3,     4,     0,     1,     0,     1,     0,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     2,     2,     0,     2,
       1,     1,     5,     3,     5,     3,     1,     3,     1,     1,
       0,     1,     3,     3,     3,     6,     4,     4,     4,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     1,     4,     1,     5,     5,     1,     1,     1,     1,
       1,     4,     1,     4,     6,     4,     1,     4,     1,     7,
       1,     1,     1,     4,     6,     0,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     5,
       3,     5,     7,     3,     1,     1,     3,     5,     3,     5,
       7,     1,     0,     3,     5,     1,     2,     2,     4,     3,
       1,     1,     1,     1,     1,     2,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     0,     7,
       0,     8,     0,     6,     0,     8,     0,     1,     2,     1,
       3,     1,     3,     5,     1,     1,     1,     1,     1,     0,
       0,     9,     5,     1,     1,     6,     0,     3,     1,     3,
       4,     1,     0,     2,     4,     6,     0,     1,     1,     1,
       1,     3,     1,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     2,     2,     2,     2,     4,     3,     2,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     4,     4,     3,     4,     1,     1,     1,
       3,     1,     5,     7,     5,     0,     2,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     0,     3,     1,     1,
       1,     1,     4,     6,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     4,     5,
       1,     4,     1,     1,     7,     4,     1,     0,     4,     1,
       2,     1,     1,     1,     0,     3,     0,     3,     0,     0,
       6,     0,     2,     2,     7,     3,     3,     2,     2,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     2,     2,     1,     1,     2,     4,     5,     7,     7,
       9,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     3,     5,     5,     5,     5,     5,     4,     4,     3,
       4,     1,     1,     1,     1,     3,     0,     5,     1,     3,
       3,     3,     1,     1,     2,     1,     1,     3,     1,     3,
       3,     1,     1,     1,     3,     2,     3,     6,     1,     3,
       1,     1,     0,     0,     6,     0,     2,     0,     1,     1,
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
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     855,     0,  1941,     0,     0,     0,     0,   904,   192,     0,
       0,   852,   880,   883,   190,   195,   862,   859,     0,   850,
     851,   853,   856,   857,   860,   864,   865,   863,   900,   901,
     903,   861,   148,   145,     0,   141,   143,   142,   146,  1969,
     732,   672,   733,   324,  1716,  1714,   898,   188,   198,   899,
     125,   191,     1,   866,   858,   902,   140,   144,   147,     0,
       0,   649,     0,     0,   189,   907,   969,   650,   908,   909,
     905,   684,   961,     0,   962,   970,   968,   198,   193,   211,
       0,   196,   212,   250,   129,     0,   885,  1269,     0,   884,
    1257,   892,     0,     0,   877,   876,   878,   854,   867,   868,
     886,   871,   872,   875,   873,   874,   879,     0,  1715,   963,
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
    1689,     0,   449,     0,     0,     0,   448,     0,   463,   558,
       0,     0,     0,     0,     0,   561,   416,   422,   459,   456,
     417,   418,   420,   421,   454,   457,   462,   557,   511,   508,
     517,   514,     0,     0,    17,    18,    19,    20,    21,     0,
      14,     0,   499,     0,     0,   978,     0,   200,   203,   201,
     202,     0,   208,   207,   206,   209,   217,   218,   219,   222,
     289,   198,   289,     0,     0,     0,     0,   198,   285,   286,
       0,     0,   198,     0,   289,     0,     0,   264,   248,   127,
    1270,     0,  1258,  1975,   594,   911,   887,     0,   226,   227,
       0,     0,   305,   307,   302,   303,   299,   301,   298,   300,
     297,     0,   307,   318,   319,   315,   317,   314,   316,   309,
       0,     0,     0,   358,     0,   361,   363,   234,     0,   233,
       0,   198,   198,   198,     0,     0,     0,   583,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   566,
     571,     0,   567,   570,   569,   663,     0,   662,   585,     0,
      11,   184,   447,   424,   423,     0,  1199,     0,     0,   461,
    1697,  1695,  1696,  1692,  1694,  1691,  1693,  1685,     0,     0,
       0,   460,     0,     0,     0,     0,     0,     0,     0,   686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   563,   564,   565,   474,     0,     0,   473,
     483,     0,     0,   428,     0,     0,   429,   419,   425,   427,
     430,   431,   432,   433,   434,   426,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    96,     0,   981,     0,   966,
     210,     0,     0,   277,     0,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,   198,   249,   252,
       0,   993,   730,   993,     0,  1973,  1975,  1193,  1816,   881,
       0,   993,     0,     0,   329,   294,     0,     0,   304,   321,
     295,   320,     0,   313,     0,   336,     0,   330,     0,   355,
       0,   360,   350,     0,     0,   339,   236,     0,   292,   349,
     542,     0,     0,   554,     0,     0,   551,   550,   553,   549,
     560,   545,   545,     0,     0,   545,     0,   568,     0,   572,
       0,   312,     0,   552,   559,   296,     0,  1265,  1756,     0,
       0,     0,     0,     0,   450,     0,     0,   464,     0,     0,
       0,     0,   466,   465,   484,   475,   490,   493,   494,   491,
     497,   496,   495,   485,   486,   487,   488,   489,   435,   476,
     480,   498,   492,   479,   498,   458,   512,   509,   518,   515,
     543,     0,   505,   101,   500,    97,    98,   100,   502,     0,
       0,   250,     0,     0,     0,   257,   258,     0,   261,     0,
       0,   269,     0,   259,   239,   220,     0,   272,   291,     0,
     131,   133,   999,     0,   994,   995,     0,   894,  1974,  1972,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1956,     0,  1390,  1389,     0,
    1391,     0,   412,  1388,  1305,     0,     5,  1387,   413,   410,
       0,   415,   186,   498,  1168,     0,     0,  1397,   137,   409,
     408,     0,     0,   403,   498,     0,  1341,  1949,     0,   414,
     375,     0,     3,     2,     0,   411,  1302,     0,     0,   404,
     401,   397,     0,     0,     0,     0,  1395,  1385,   407,     0,
       0,     0,     0,     0,     0,     0,     0,  1384,     0,     0,
       0,   187,     0,   400,   399,     0,     0,  1953,  1952,     0,
       0,     0,   149,     0,   406,   405,     0,     0,   402,   498,
       0,     0,   498,     0,   587,     0,     0,     0,     0,     0,
       0,   498,   839,  1267,     0,     0,  1179,     0,  1942,     0,
     108,     0,     0,   919,     0,     0,     0,     0,   840,     0,
       0,  1847,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   701,     0,     0,  1977,  1978,  1979,  1980,  1981,  1982,
    1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,
    1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,
    2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,  2012,
    2013,  2014,  2015,  2016,  2017,  2018,  2019,  2020,  2021,  2022,
    2023,  2024,  2025,   948,  2026,  2027,  2028,  2029,  2030,  2031,
    2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,
    2042,  1159,  1161,  1156,  1158,  1157,  1160,  2043,  2044,  1295,
    2045,  1301,  1300,  2046,  2047,  2048,  2049,  2050,  2051,  2052,
    2053,  2054,  2055,  1452,  2056,  2057,  2058,  2059,  2060,  2061,
    2062,  2063,  2064,  1976,   882,   598,     0,   915,     0,   913,
       0,   357,   228,   229,     0,   306,   311,     0,     0,     0,
       0,   359,   362,     0,   232,     0,   198,     0,   584,     0,
     658,     0,   660,     0,   523,   521,     0,   545,     0,   522,
       0,     0,   582,     0,   579,   576,   547,   520,   586,     0,
     183,  1758,  1759,  1757,     0,   452,  1264,     0,  1690,  1264,
     451,  1264,  1264,  1264,  1264,  1264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,    96,   979,     0,   223,   290,   241,     0,     0,
     198,     0,     0,     0,     0,   128,   132,     0,  1271,     0,
    1259,   394,   392,   393,  1299,  1094,  1093,  1099,     0,  1664,
    1665,     0,     0,  1325,   673,   674,  1326,  1656,  1657,  1328,
     870,  1131,  1136,  1951,   666,   136,  1964,     0,     0,  1340,
       7,     0,     6,     0,  1957,  1132,     0,  1227,  1226,  1171,
    1225,  1170,   446,  1398,  1386,     0,  1296,   895,   436,  1818,
    1392,   138,     0,  1135,   135,     0,   846,    24,   668,   398,
       0,   845,  1127,   847,     0,  1396,   941,   940,   943,   939,
     942,  1966,     0,   937,     0,   667,  1025,   938,  1960,     0,
    1950,   134,  1298,  1022,   734,  1020,     0,   664,  1945,   782,
     781,   783,   779,     0,     0,  1297,  1035,   669,  1451,     0,
    1932,  1446,  1449,  1922,  1925,  1926,  1928,  1931,     0,     0,
       0,     0,  1100,  1095,     0,  1074,  1075,  1076,  1077,  1083,
    1084,  1085,  1082,  1081,     0,     0,     0,  1080,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,  1057,  1058,  1008,     0,  1006,  1114,
     444,    24,     0,  1947,   139,   665,     0,  1268,  1266,  1192,
       0,  1807,     0,  1808,  1193,  1181,  1172,  1399,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,   969,     0,
      69,     0,   106,   641,     0,   688,   687,     0,  1162,  1042,
    1166,     0,     0,  1115,  1285,     0,     0,  1169,   693,   690,
     691,     0,   695,   696,     0,   698,   699,     0,   694,  1003,
    1005,     0,     0,  1004,   784,  1001,   745,   997,   960,     0,
       0,     0,     0,   705,   706,     0,     0,   958,   955,   956,
     952,   953,   954,   947,   951,   950,     0,     0,     0,     0,
       0,     0,   602,   604,   596,   599,   600,   917,  1975,   912,
     914,   888,     0,   308,   310,   337,   331,     0,     0,   340,
     237,   655,   657,     0,     0,     0,     0,   545,   528,     0,
     545,   545,     0,   573,     0,   305,     0,     0,  1786,  1681,
    1683,  1842,  1846,  1787,  1687,  1784,     0,     0,  1783,     0,
       0,     0,  1785,     0,     0,     0,     0,     0,     0,     0,
    1932,  1682,  1782,  1684,  1771,     0,  1760,  1762,  1766,  1769,
    1797,  1840,  1798,  1843,  1933,  1923,  1770,  1202,  1698,  1201,
    1200,  1203,  1205,  1204,  1198,   477,   478,   482,   467,     0,
     470,   481,     0,   469,   513,   510,   519,   516,   544,   506,
     501,    99,   503,   967,     0,   262,   246,     0,   244,   270,
     260,   250,   273,  1000,   188,   996,   188,     0,     0,     0,
    1370,  1371,     0,     0,     0,  1342,  1345,  1347,  1348,  1349,
    1353,  1352,  1350,  1351,     0,     0,     0,  1343,  1344,     0,
       0,     0,     0,     0,     0,     0,     0,  1133,     0,    24,
    1222,  1224,  1223,     0,   439,   440,   437,   438,  1013,     0,
       0,   380,    25,   374,     0,  1128,     0,  1127,     0,  1126,
       0,     0,     0,     0,     0,     0,  1029,  1817,     0,     0,
       0,     0,     0,     0,  1947,     0,     0,   150,     0,     0,
    1039,  1031,  1032,  1037,     0,     0,  1924,     0,  1935,  1447,
    1448,     0,     0,   957,   442,  1916,  1052,   364,     0,     0,
     588,   646,   645,   643,   648,  1060,   647,  1065,  1061,  1064,
     838,   830,   824,   836,   837,   822,   823,   831,   826,   832,
     825,   835,   829,   833,   828,   834,   821,   827,   814,   820,
    1062,  1063,     0,  1070,  1078,  1067,  1068,  1072,  1073,  1071,
    1069,  1088,  1089,  1086,  1079,  1090,  1091,  1087,     0,     0,
       0,   848,     0,     0,     0,     0,     0,   794,   793,   790,
    1948,  1955,    24,  1188,  1189,  1190,  1191,  1185,     0,  1183,
    1281,  1193,  1173,  1174,  1177,  1195,  1943,     0,     0,     0,
       0,   102,     0,   103,     0,     0,     0,    77,     0,     0,
       0,     0,   115,   110,     0,   689,   946,     0,   945,     0,
     498,  1164,     0,   988,   989,  1012,   983,   984,   841,  1010,
    1117,  1294,  1293,  1288,     0,  1292,  1291,  1286,  1851,  1854,
    1856,     0,  1849,  1852,  1853,   721,     0,     0,     0,   710,
     745,   745,   742,     0,     0,   746,     0,    26,   709,   712,
       0,   719,   715,   959,   949,  1814,  1815,  1805,  1805,  1416,
       0,     0,  1717,  1455,     0,     0,  1400,     0,     0,  1401,
    1444,     0,     0,  1445,     0,     0,  1756,     0,  1414,     0,
    1464,  1463,  1462,  1460,  1461,  1459,  1457,  1453,  1544,  1543,
    1454,  1456,  1465,  1738,  1458,  1821,  1820,  1819,  1466,  1975,
    1975,   615,   606,   597,     0,   601,  1975,   916,   188,     0,
     351,   231,     0,     0,   546,     0,   545,     0,   532,   545,
       0,   525,   524,     0,     0,     0,   578,   577,   185,  1768,
    1767,  1705,  1703,  1704,  1700,  1702,  1699,  1701,  1686,     0,
    1756,     0,     0,  1611,     0,     0,  1774,  1772,  1773,  1611,
    1611,  1611,  1611,  1775,     0,     0,     0,  1562,  1746,     0,
    1763,     0,     0,     0,     0,  1830,  1831,  1832,  1833,  1834,
    1835,  1778,     0,     0,     0,     0,   472,   471,     0,     0,
       0,   198,   243,   221,  1272,  1260,     0,     0,     0,     0,
       0,     0,  1518,  1517,  1516,  1377,     0,  1383,  1379,  1381,
    1372,     0,  1620,  1369,  1365,  1339,  1338,     0,  1364,  1360,
       0,  1356,  1354,     0,  1663,     0,  1666,  1668,   677,     0,
     676,  1655,     0,  1658,  1660,  1965,  1962,     0,     0,  1306,
     498,   372,  1327,     0,     0,  1303,  1044,  1129,  1130,  1127,
    1123,  1127,     0,   944,     0,     0,   651,     0,     0,     0,
    1023,  1021,   736,   737,     0,   741,     0,     0,  1946,  1954,
     780,     0,   154,     0,  1033,  1040,     0,     0,  1048,  1927,
    1940,     0,  1938,  1450,  1930,  1929,     0,     0,     0,  1054,
     367,     0,     0,     0,     0,    24,  1096,  1097,   591,     0,
       0,     0,   815,   816,  1059,  1009,  1007,   849,   445,     0,
    1106,   791,   795,   792,   796,   395,     0,  1193,  1182,  1282,
    1197,  1180,  1175,     0,     0,  1176,  1975,     0,     0,     0,
       0,     0,     0,     0,    64,    96,     0,     0,     0,   121,
     116,     0,   111,     0,   118,   112,   930,   922,   928,     0,
    1163,     0,  1165,  1167,     0,     0,   992,     0,     0,     0,
       0,  1116,  1287,  1290,     0,     0,     0,  1848,  1850,  1975,
     692,   697,   700,   713,   711,   670,     0,   769,   767,   765,
     763,   773,   771,     0,     0,   761,   811,   759,   744,   755,
     753,   809,   785,     0,   747,   757,  1002,   998,     0,     0,
       0,     0,   718,     0,     0,     0,     0,     0,     0,     0,
    1671,     0,  1539,  1540,  1826,  1497,  1562,     0,     0,     0,
    1824,     0,  1477,  1472,  1471,  1484,  1483,  1488,  1488,  1486,
    1487,  1478,  1473,     0,     0,  1479,  1480,  1739,  1858,     0,
       0,     0,   603,   605,     0,     0,   618,   610,   612,     0,
     607,   608,     0,     0,   626,   628,     0,     0,   624,   918,
     889,   230,     0,   659,   661,   656,     0,   545,   534,     0,
     529,     0,     0,   545,   545,   575,   574,     0,     0,  1795,
    1687,     0,     0,  1770,  1613,  1614,  1612,     0,  1799,     0,
       0,     0,     0,     0,     0,     0,  1761,     0,  1550,  1551,
    1553,  1556,     0,  1563,  1564,     0,     0,  1611,  1748,  1742,
    1764,  1780,  1781,  1779,  1777,     0,     0,     0,  1934,   468,
     507,   504,     0,   245,  1228,  1206,     0,     0,     0,     0,
    1377,     0,     0,     0,  1373,     0,     0,     0,  1367,  1651,
    1649,  1618,  1630,  1632,  1636,  1638,  1629,  1623,  1628,  1642,
    1621,  1650,  1626,  1641,  1627,  1648,  1640,  1524,  1615,  1616,
    1617,     0,  1362,  1358,     0,     0,  1346,     0,     0,   675,
       0,     0,     0,  1961,     0,     4,     8,    10,     0,   498,
     441,     0,     0,     0,  1041,  1125,  1124,     0,     0,     0,
       0,     0,     0,     0,     0,   735,     0,     0,   171,   169,
       0,     0,   151,     0,   161,   167,   745,   156,   158,     0,
    1038,  1049,  1050,     0,     0,  1936,   443,     0,  1917,  1918,
    1053,     0,     0,  1051,   366,   371,   653,   365,     0,   368,
     373,     0,   498,  1422,   644,   642,     0,   818,  1105,  1107,
       0,   396,  1186,  1184,     0,  1196,  1178,     0,     0,  1277,
       0,     0,     0,   104,     0,     0,    78,    84,    74,    71,
    1975,  1975,   114,   109,   123,   119,     0,   113,   812,   931,
     670,  1975,   921,   920,   929,  1043,     0,     0,   990,   991,
     985,  1011,   498,  1122,  1118,  1119,  1121,  1289,  1855,  1857,
     722,   716,   714,     0,    24,     0,  1975,  1975,  1975,  1975,
    1975,  1975,   775,   749,   777,   751,  1975,  1975,  1975,  1975,
       0,   743,   748,  1975,   670,   807,   805,   808,   806,     0,
       0,    46,    44,    41,    35,    39,    43,    38,    31,    40,
       0,    34,    37,    32,    42,    33,    45,    36,     0,    29,
      47,   799,     0,   720,  1806,     0,  1804,  1756,  1802,  1743,
    1744,  1736,  1722,  1737,     0,     0,     0,  1092,  1538,  1541,
       0,     0,     0,  1434,  1406,  1829,  1828,  1827,     0,     0,
       0,  1482,  1485,     0,     0,     0,     0,     0,  1429,     0,
    1428,     0,  1430,  1425,  1426,  1427,  1418,  1419,     0,     0,
       0,   617,   622,     0,     0,  1975,  1975,   595,   609,   632,
     620,   634,  1975,  1975,   630,   614,   625,   881,   352,   545,
       0,   533,   545,     0,   545,   545,   527,   526,  1712,  1710,
    1711,  1707,  1709,  1706,  1708,  1688,     0,     0,     0,     0,
    1796,     0,     0,     0,  1794,     0,     0,     0,     0,  1776,
    1793,     0,  1554,     0,     0,  1680,  1557,     0,     0,     0,
       0,  1549,  1568,  1570,  1572,  1610,  1609,  1608,  1574,  1590,
       0,  1565,  1566,  1751,  1329,     0,     0,     0,  1841,     0,
    1845,   224,     0,  1254,  1273,     0,  1261,  1254,     0,  1672,
       0,  1506,     0,  1509,  1675,     0,  1514,     0,     0,  1374,
    1375,     0,     0,  1378,  1380,  1382,     0,  1366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1522,  1521,
    1520,     0,  1525,  1526,     0,  1361,     0,  1355,  1357,  1667,
       0,  1669,  1659,     0,  1661,  1963,  1335,     0,  1331,     0,
       0,  1336,   896,     0,     0,     0,     0,     0,  1393,  1968,
    1967,   652,     0,     0,    48,     0,   738,   740,   739,  1394,
     745,  1975,  1975,   163,   678,   173,   165,   175,   155,   162,
    1975,     0,     0,     0,     0,     0,  1939,     0,     0,     0,
       0,     0,     0,  1098,     0,  1423,   589,     0,   817,  1103,
       0,  1283,  1284,  1944,     0,    96,     0,    65,     0,     0,
       0,    81,     0,    96,    96,    96,   122,   117,  1975,  1975,
     107,     0,   932,   926,   934,   933,   923,   639,   972,     0,
       0,     0,   724,   703,   717,   671,   786,     0,   770,   768,
     766,   764,   774,   772,     0,  1975,     0,  1975,   762,   760,
     756,   754,   810,   758,    24,   800,     0,     0,     0,    27,
       0,  1809,     0,  1723,     0,     0,  1735,  1718,  1734,  1542,
       0,  1499,     0,  1433,     0,     0,  1825,     0,  1822,     0,
    1490,  1494,  1470,  1492,  1495,     0,  1481,  1740,     0,     0,
       0,     0,     0,     0,  1859,  1432,  1431,  1420,  1415,  1417,
    1469,     0,     0,   619,   616,   611,   613,     0,  1975,  1975,
     627,   629,  1975,  1975,     0,   535,     0,   539,     0,     0,
     531,   530,     0,     0,     0,     0,     0,     0,  1792,  1800,
    1788,  1789,  1790,  1791,  1559,     0,  1552,  1558,  1573,  1577,
       0,  1590,  1576,     0,     0,  1591,  1603,  1604,  1601,  1607,
    1606,  1602,     0,     0,     0,     0,     0,  1605,     0,     0,
       0,  1546,  1547,  1765,     0,  1567,  1561,  1330,  1749,  1439,
    1435,  1436,  1441,  1440,  1747,  1329,     0,     0,  1252,  1253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1251,     0,     0,  1239,  1240,  1241,  1238,  1243,  1244,
    1245,  1242,  1229,  1220,     0,     0,  1276,     0,     0,  1215,
       0,     0,     0,     0,     0,     0,     0,  1207,  1208,     0,
    1137,  1676,     0,  1677,     0,     0,     0,     0,  1513,  1512,
    1377,  1511,  1503,  1368,  1652,     0,     0,     0,     0,     0,
       0,  1653,  1645,     0,     0,     0,  1645,  1681,  1519,  1532,
    1537,     0,  1534,  1531,  1533,     0,  1535,  1523,  1527,  1528,
    1377,  1363,  1359,     0,     0,  1334,  1333,     0,  1318,     9,
       0,  1308,   897,  1134,   378,  1308,     0,     0,  1959,     0,
       0,  1024,    49,     0,   797,   172,   170,     0,  1975,     0,
       0,     0,  1975,   168,   157,     0,   160,   159,     0,  1030,
    1034,     0,  1921,  1920,  1919,     0,     0,   370,     0,   592,
       0,  1975,   819,     0,   670,  1187,     0,  1278,    70,     0,
       0,   105,    68,    96,    79,    85,     0,     0,   124,   120,
     813,  1975,   936,   670,   935,     0,   636,     0,   843,   844,
     842,  1120,   727,   725,     0,   707,   704,     0,   776,   750,
     778,   752,   787,   803,   804,   801,   802,    30,    28,     0,
    1803,  1752,  1724,  1720,  1719,     0,  1498,  1756,  1501,     0,
    1408,  1403,  1402,  1405,     0,     0,  1489,     0,     0,  1752,
       0,     0,  1896,  1894,     0,     0,  1878,  1893,     0,     0,
    1895,     0,     0,     0,     0,     0,  1932,  1892,  1884,  1911,
    1912,     0,  1876,  1879,  1880,  1891,  1883,  1913,     0,  1869,
    1868,  1872,  1874,     0,  1867,     0,  1870,  1861,     0,     0,
     623,   621,   633,   635,   631,     0,     0,   545,     0,   545,
     545,     0,  1755,     0,  1688,     0,     0,     0,  1555,  1575,
    1569,  1571,  1578,  1580,  1578,     0,  1585,  1578,     0,  1583,
    1578,     0,  1593,  1592,     0,  1594,     0,  1545,     0,  1443,
    1442,  1438,  1750,     0,   250,  1246,  1247,  1248,  1250,  1233,
    1231,  1230,  1234,  1235,  1232,  1249,  1236,  1237,  1221,  1017,
    1256,  1014,     0,     0,  1274,  1219,  1218,  1213,  1211,  1210,
    1214,  1212,  1216,  1217,  1209,  1262,     0,  1504,  1510,  1679,
    1672,  1515,  1376,  1619,  1631,     0,  1633,  1635,     0,  1637,
       0,     0,     0,  1643,  1622,  1647,     0,  1505,  1507,     0,
    1529,  1530,  1670,  1662,  1332,     0,     0,  1324,  1319,  1320,
    1337,     0,  1315,  1316,     0,     0,  1329,  1309,  1310,     0,
      24,  1304,     0,     0,  1047,     0,    50,  1027,     0,    24,
     174,   164,     0,   680,   682,   176,   166,   797,     0,  1937,
    1056,     0,   369,  1424,     0,  1104,    24,     0,     0,    66,
       0,    82,    91,     0,    75,    72,   927,   924,   640,  1975,
     986,     0,  1975,   723,   702,   708,   670,  1813,     0,  1811,
       0,     0,  1725,  1721,  1500,     0,  1502,  1496,     0,  1407,
       0,  1823,  1491,  1493,  1468,     0,  1882,  1881,     0,     0,
    1611,     0,  1611,  1611,  1611,  1611,  1885,     0,     0,  1865,
       0,     0,     0,     0,  1898,  1866,     0,     0,     0,     0,
       0,     0,  1860,  1421,  1474,   891,   890,   353,   536,     0,
       0,   541,   540,  1713,  1836,  1839,  1837,  1560,     0,  1597,
    1599,     0,  1586,  1589,  1588,  1596,     0,  1598,  1578,     0,
    1548,  1437,  1844,   225,  1019,  1018,  1016,     0,  1255,  1138,
    1142,  1144,     0,  1148,     0,  1146,  1150,  1139,  1140,     0,
       0,     0,  1673,  1678,     0,     0,  1654,  1646,  1624,     0,
    1625,     0,     0,  1322,  1317,  1323,  1321,  1314,  1313,  1312,
    1307,  1311,   379,   376,     0,  1045,     0,     0,     0,  1026,
     798,   152,   679,    24,  1036,  1055,   590,  1101,    67,  1279,
      87,     0,     0,    80,    91,    91,    91,  1975,   637,     0,
       0,   726,   788,     0,  1810,  1753,  1746,     0,  1409,     0,
    1746,  1909,     0,     0,  1914,     0,     0,     0,     0,     0,
       0,     0,     0,  1877,  1900,  1901,  1899,  1897,  1875,     0,
    1871,  1873,  1862,  1863,  1475,     0,  1467,   545,   545,  1579,
    1801,  1581,     0,  1584,  1582,  1600,     0,  1015,  1975,  1975,
    1152,  1975,  1154,  1975,  1975,  1141,  1275,  1263,     0,  1634,
       0,  1644,     0,  1536,   381,  1046,  1958,     0,     0,     0,
       0,     0,     0,    55,     0,    54,     0,    52,     0,     0,
     153,  1108,    91,    96,    91,    92,    86,    76,    73,   925,
       0,     0,   728,    24,  1812,  1745,  1754,  1413,     0,  1410,
    1412,  1726,  1910,     0,     0,  1908,     0,     0,     0,     0,
       0,  1886,  1907,     0,  1476,   538,   537,  1587,  1595,  1143,
    1145,  1975,  1149,  1975,  1147,  1151,  1674,  1639,  1508,   383,
     388,   386,   377,     0,   384,   390,    57,    62,    59,    61,
      58,    60,    56,     0,    51,     0,   681,   683,  1112,  1102,
       0,  1110,  1280,    88,    83,   638,   987,  1975,   789,     0,
    1404,     0,  1727,  1741,  1906,  1915,  1902,  1903,  1904,  1905,
       0,  1887,     0,     0,  1153,  1155,  1975,  1975,   382,   385,
    1975,    53,     0,  1975,  1109,  1111,     0,   724,  1411,     0,
    1731,  1728,  1729,     0,     0,  1864,   389,   387,   391,     0,
    1113,    89,   729,     0,     0,     0,  1889,     0,  1888,  1028,
      93,     0,  1732,  1730,     0,    95,     0,    90,     0,  1890,
      94,  1733
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   844,   845,   846,   847,  1071,  2145,  2146,   187,   329,
     188,  1441,  1442,  1969,  2308,  3355,  2831,  2832,  3257,  3356,
    3357,   848,  1216,  2869,  2565,  3276,  2564,  3275,  1905,  2562,
    3122,  2873,  3271,  2563,  3123,  3363,  3466,  3490,  3273,  3497,
     664,   665,   666,  1572,  2222,   849,  1584,  1221,  1582,  1914,
    2233,  1911,  2231,  2236,  2569,  1583,  2230,  1915,  2568,    11,
      84,   240,   550,   128,   689,   690,   850,    12,    34,    35,
      36,    37,    38,   852,  1134,  1842,  1467,  2172,  2176,  2177,
    2173,  2174,  2838,  2842,  2530,  2522,  2521,  2523,  2526,   506,
     279,   616,   853,    63,    64,    14,    48,   120,    78,   263,
      80,    81,   203,   344,    82,    83,   250,   349,   235,  1033,
     531,  2727,   380,   954,  2032,   408,   409,   264,   236,   362,
     351,   357,  1387,  1388,   124,   549,   125,   126,   368,   237,
     364,   350,   352,   533,   238,   589,   252,   255,   253,   254,
     973,   565,   566,   568,   573,   957,   256,   257,   399,   570,
     199,    15,    59,   157,   158,   159,   963,  2664,   160,   260,
     248,   402,   403,   404,   405,  1865,   854,   855,   856,   857,
    1092,  3344,  3090,  1443,  3412,  3413,  3414,  3457,  3456,  3460,
     858,   859,   860,   861,   862,   863,   864,  1082,   507,  1087,
    1435,  1436,  1483,  1189,  1484,   306,   307,   308,   309,   310,
     464,   508,  1369,   509,   510,   511,   512,   513,   514,   515,
    1009,   189,   525,  1020,  1022,  1759,  1019,  1758,   190,   518,
    1015,   517,  1014,   520,  1017,   519,  1016,   974,   987,   311,
     312,   192,   313,   431,   432,   433,   434,   416,   436,   865,
    1154,  1868,  2861,  2203,    95,   245,   559,  1682,  1284,  1285,
    1286,  1679,  1680,  2019,  2020,  2021,  2365,  2366,  1683,  1684,
    2015,  2369,  2361,  2027,  2028,  2372,  2373,  2662,  2658,  2659,
     866,  3129,  3370,  2886,   867,  1495,    65,  1827,  1828,  2197,
     417,   438,  1126,  1194,  1063,  1114,  1097,  1136,  2264,   193,
    1064,  1054,  1799,  2525,    67,   314,   868,  1226,   869,  1239,
    1240,   870,   871,   872,   873,  1247,  2895,  1268,  3134,  1269,
    1943,  1270,  2261,  1271,  2583,  1272,  1972,   874,  1939,  2582,
    2894,  3132,  3131,  3437,    96,    16,    17,   875,  1461,  1832,
    1833,  1834,  1962,  1626,  1963,  1964,  2595,  2597,  2279,  2278,
    2283,  2277,  2276,  2269,  2268,  2267,  2266,  2271,  2270,  2273,
    2275,   876,   877,  1132,   878,  1622,  1254,  3373,   879,  1549,
    3099,  2310,  2311,  1965,  2280,  2239,  2571,  1183,  1523,  1872,
    2206,  1873,  1519,   880,   881,  1232,  1929,  2890,   882,   883,
     884,   885,    18,    19,    20,    53,    21,    22,    23,    97,
      98,   886,    99,    24,   945,    25,   100,   101,   137,   561,
    1688,  2377,  3186,   102,   133,   373,   887,  2503,    26,    27,
      28,    29,    30,    47,    70,   103,   246,   560,   948,   949,
    1288,  1686,   888,  1227,  2243,  1918,  2241,  3277,  2881,  1919,
    2240,  2574,  2883,   889,   890,   891,  1108,  1109,  1587,   892,
    1273,  1274,   893,  1634,  1275,   315,    72,    73,    74,    75,
    1594,   163,   116,    76,   113,   195,   196,  1595,  1596,  2250,
    1597,   693,   694,  1256,   695,  1257,  1187,  1188,  1598,  1599,
    1439,  3030,  3031,  3216,  1124,  1125,   894,  1456,  3259,   895,
    2850,   896,  1471,  1472,  1473,  1848,  1846,   897,   898,  2154,
    2183,   899,  1859,  2193,   900,  1184,  1185,  1533,  1537,   901,
    1047,   902,  2321,   903,  3361,  2864,   904,  2210,  3429,  3430,
    3431,  3463,  1191,   905,  1600,  1931,  2254,  2255,   906,  1449,
    1819,  1062,  1428,   907,   908,   909,  2446,  3034,  3227,  3228,
    3328,  3329,  3333,  3331,  3334,  3401,  3403,   910,   911,  1589,
    1923,   912,  1591,  1561,  1562,  1563,  1895,   913,  1206,  1204,
     914,   915,  1887,  1557,  1200,   202,  1564,  1565,   316,  2447,
    2767,  2768,  2752,  1079,  1080,  2443,  2753,  2756,   104,   132,
     553,  1396,  2095,  2769,  3230,   446,   916,  1198,   105,   130,
     551,  1394,  2094,  2757,  3229,  2444,  1220,  2555,  3118,  3362,
    1890,   917,  1607,   918,   919,   920,   921,  1095,  2152,  1073,
    2148,  3086,  3087,  3088,  3243,  3077,  3078,  3079,   922,  2718,
    2497,  2498,  2500,  1783,   923,   924,  1405,  1406,  1407,  1792,
    2134,  1408,  2131,  1789,  1409,  2107,  1784,  1410,  1411,  1412,
    2099,  2104,  1413,  1778,  1779,   925,  1104,  1084,   926,  1660,
    1661,  1987,  2922,  3150,  2625,  2919,  3378,  3379,  1662,  2009,
    1640,  2357,  2648,  2968,  2546,  2860,  2358,  1663,  1664,  2078,
    2720,  2721,  2722,  3011,  1665,  1666,  1480,   927,  1141,   928,
    1281,  1667,  1668,  2003,  3316,  2004,  2005,  2006,  2341,  2629,
    2632,  2633,  1669,  2331,  2620,  3147,  1772,  1773,  2806,  2450,
    3067,  2451,  1774,  2455,  1785,  2482,  1786,  2483,  2807,  2808,
    2809,  2810,  1670,  1981,  1982,  2328,  1671,  2715,  2431,  2711,
    2073,  1737,  2068,  2069,  2070,  2685,  1738,  2074,  2432,  2716,
    2421,  2422,  2423,  2424,  2425,  3199,  2992,  3319,  2426,  3201,
    3202,  2709,  2427,  2710,  2428,  2057,  2127,  2128,  2129,  3061,
    2130,  2785,  2792,  3237,  2452,  1051,  2634,  2773,  2961,  2454,
    2416,  1342,   317,  1343,  1718,   457,   458,  1719,  2395,    46,
     929,   930,  2914,  3143,  2613,  3142,  3443,  3471,  3472,  2617,
    2322,  1672,  2323,  2346,  2929,   619,  2318,  2319,  2079,  2434,
    3141,  2918,  1344,   994,  1345,  1346,  2712,  2429,  1348,  1349,
    2059,  3321,   931,   932,  1974,  2320,  2910,  3138,  3139,  1637,
     933,  1090,  1674,  1675,  1991,  2627,  1676,  1677,  2337,  1751,
    2052,  1350,  1351,  1352,  1353,   934,  1235,  1611,  1612,  1613,
    1935,  1614,  1936,  1678,  2347,  2967,  3182,  2644,  2964,  2965,
    2966,  2963,  2951,  2952,  2953,  2954,  2955,  2956,  3295,   935,
    1857,  2188,  2189,  1142,  1354,  1355,  1144,  1145,  1146,  1356,
    1147,  1478,  1851,  1852,    31,   937,  1208,  1896,  1464,  1551,
     938,   939,  2514,   940,  2143,  1067,  1806,   941,   942,    41,
     554,   555,   556,   557,   558,   943
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2567
static const short yypact[] =
{
     138,  1180, -2567,   468,   468,   468,  1469, -2567, -2567,  1469,
     468, -2567, -2567,   364, -2567, -2567, -2567, -2567,   505, -2567,
   -2567, -2567,  1146, -2567, -2567, -2567, -2567, -2567,    49, -2567,
   -2567, -2567, -2567, -2567,   752,   490, -2567,   544, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  -111, -2567,   825,   515, -2567,
   -2567, -2567, -2567,   352, -2567, -2567, -2567, -2567, -2567,   218,
     468, -2567,   468,   677,   364, -2567,   937, -2567, -2567, -2567,
   -2567, -2567, -2567,   932,   317, -2567, -2567, -2567,  1042,   657,
     468, -2567, -2567,  1072,   366,   468, -2567, -2567,   468, -2567,
   -2567, -2567,   468,   468, -2567, -2567, -2567, -2567,   352, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  4403, -2567,   317,
   -2567,   892,  3370, -2567, -2567,   627, -2567, -2567,  1131,   515,
     594, -2567, -2567, -2567, -2567, -2567,  8616,   468, -2567, -2567,
     468,   698,   468,   364, -2567, -2567, -2567,   468, -2567, -2567,
     869,   778,  1050, -2567, -2567,   798, -2567,   806, -2567,   764,
   -2567, -2567,   811, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   821, -2567, -2567, -2567,   830,   850,   854,
     887,   893,   909,   925,   943,   947,   953,   989,  3370,   997,
    5217,  1019,  1055,  1067,  1132,  1152,  1158,  1808,  1372, -2567,
   -2567, -2567, -2567,   333, -2567,   251, -2567,  3370, -2567,   234,
   -2567, -2567, -2567,   188, -2567, -2567, -2567,   746, -2567, -2567,
   -2567, -2567, -2567, -2567,   869,  1183,  1187,  1201, -2567,  1050,
   -2567, -2567,  1206, -2567,  1210, -2567,   813, -2567, -2567,  1225,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
     364,  1232,  1418,  1235, -2567,   364,   364,  1250,   468, -2567,
     612,  1520, -2567,   879,  1142, -2567,   894,  1458,  1627,  1637,
     468,  1731,  1735,  -200,  1082, -2567,   428,    56,    56,    56,
      56,    56,  5217,  1537,  1569,    59,  5217,  1061,  5217, -2567,
    5217,  5217,  5217, -2567, -2567, -2567,  1195,  1294,  1297,  5217,
    1522,  1307, -2567,  5217,  5217,  1333, -2567,  1335, -2567,  1055,
    1339,  1347,  1378,  1382,  1849,  7344, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  1411, -2567, -2567, -2567, -2567,
   -2567, -2567,   428,   428, -2567, -2567, -2567, -2567, -2567,  3370,
   -2567,   468, -2567,   468,  3370,  1376,   286, -2567, -2567, -2567,
   -2567,  1862, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    1405, -2567,  1405,   612,  1865,  1867,  1868, -2567, -2567, -2567,
    1871,  1873,   515,  1731,  1405,  1875,  1238, -2567,  1786, -2567,
   -2567,  1463, -2567,  1494, -2567, -2567, -2567,  1246, -2567, -2567,
    1888,  1467, -2567,  1436, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,  1458,  1436, -2567, -2567, -2567, -2567, -2567, -2567,  1438,
     288,   382,   268, -2567,  3760, -2567, -2567, -2567,  1447,  1914,
     384, -2567, -2567, -2567,  1481,  1445,   425, -2567,  -110,  1486,
    1487,   429,   434,  6233,  1490,  1493,   160,  1331, -2567, -2567,
     175,  1496, -2567, -2567, -2567, -2567,   435, -2567, -2567,  6471,
   -2567,  5284,  7863,  4742,  4742,  5217, -2567,  1414,  5217,  7344,
    1457, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  1268,  1927,
    6495,  7344,  1414,  1929,   541,  5217,  5217,  5217,  5217, -2567,
    5217,  5217,  5217,  5217,  5217,  5217,  5217,  5217,  5217,  5217,
    5217,  5217,  5217,  5217,  5217,  5217,  5217, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  5217,  5217, -2567,
   -2567,  1470,  5217, -2567,  5217,  1471, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,   428,  5217,  5217,  5217,
    5217,  1506,  1953,  1808,  1474,  3632,  1475, -2567,  3370,  1449,
   -2567,  1287,  1938, -2567,  1296, -2567,  1947,  1526,  1527,   436,
    1662,   445,   448,   441,  1500, -2567,   451, -2567, -2567, -2567,
     211,   468, -2567,   468,  1568, -2567,  4110,   594,  5759,  1957,
     582,   468,  1969,    20, -2567, -2567,  1142,  1964, -2567, -2567,
   -2567, -2567,  1966, -2567,  1968, -2567,  1970, -2567,   468, -2567,
     468, -2567, -2567,  1731,  1972, -2567, -2567,  1357, -2567, -2567,
   -2567,   468,    56, -2567,  3370,    38, -2567, -2567, -2567, -2567,
   -2567,  1142,  1142,  1974,   442,  1142,  1565, -2567,  1975,  1360,
    1653, -2567,    59, -2567, -2567, -2567,  1559,  7344,  -130,  1560,
    6538,  1983,  1522,  1564, -2567,  1566,  1570, -2567,  6589,  6707,
    6777,  7226,  7537,  7561,  7863,  7955,  8116,  8162,  8172,  8337,
    7792,  8345,  3281,  4742,  4742,  2337,  2337,  1697,  7344,  7255,
    7279,  1414,  7344,  7322,  1414, -2567,  7344,  7344,  7344,  7344,
   -2567,  1990, -2567, -2567, -2567,  2012, -2567,  7344, -2567,   334,
    3370, -2567,  1573,  2005,    20, -2567, -2567,  2000, -2567,  1542,
    2002, -2567,  2003, -2567, -2567, -2567,  2006, -2567, -2567,    79,
   -2567, -2567,  1359,  1586,  2030, -2567,  1589, -2567, -2567, -2567,
     428,   428,   428,   468,  1038,   468,  1656,   263,   263,  1667,
     468,   468,   263,   263,   468, -2567,  1656, -2567, -2567,   468,
   -2567,   349, -2567, -2567, -2567,   263, -2567, -2567, -2567, -2567,
     468, -2567, -2567, -2567, -2567,   117,   117,  5217, -2567, -2567,
   -2567,  1667,  1667, -2567, -2567,   263, -2567, -2567,   263, -2567,
   -2567,   468, -2567, -2567,   263, -2567, -2567,   428,   263, -2567,
   -2567,  5217,   263,   428,   468,   428,   263, -2567, -2567,   190,
     263,   263,   190,   263,   468,   190,   263, -2567,   263,   263,
     263, -2567,  1656, -2567, -2567,   428,   263, -2567, -2567,   263,
      27,   468, -2567,  1667, -2567, -2567,   263,  1095, -2567, -2567,
     428,  1361, -2567,   263, -2567,  7433,   428,  5217,    56,    56,
     263, -2567, -2567,  1038,   428,   373, -2567,  5217, -2567,  2725,
    5217,   263,    84, -2567,  5217,   263,  2016,   428, -2567,   263,
    5217, -2567,  5217,   117,   468,   263,   468,    56,   263,   468,
      56, -2567,   468,   282, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   549, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1124, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   828,   468, -2567,   803, -2567,
    1595, -2567, -2567, -2567,  1691, -2567, -2567,  1596,  1602,  1603,
    1604, -2567, -2567,  1377,  2050,  1614, -2567,  1617, -2567,   454,
   -2567,  1582, -2567,  1392, -2567, -2567,   406,  1142,  2045, -2567,
    1625,   477, -2567,  2048, -2567,  1437, -2567, -2567, -2567,  1398,
   -2567, -2567, -2567, -2567,  8559, -2567,  1195,  1630, -2567,  1195,
   -2567,  1195,  1195,  1195,  1195,  1195,  2062,  2064,  2066,  5217,
    1635,  2071,  5217,  1649,  1658,  1669,  1670,  1671,  1676,  3632,
    1680,  3632,  3632, -2567,   361, -2567, -2567, -2567,  1746,  1683,
   -2567,  1685,  1688,  1472,  1695, -2567, -2567,   468, -2567,   468,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   335,  1451,
     398,  1375,  1654, -2567, -2567, -2567, -2567,  1479,   559, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2102,  1476, -2567,
   -2567,  1674, -2567,  1667, -2567,  1620,   307, -2567, -2567, -2567,
    1530, -2567,  7344, -2567, -2567,  1509, -2567, -2567,  4210, -2567,
   -2567, -2567,   428, -2567, -2567,  1667, -2567,   -34, -2567, -2567,
    1844, -2567,    37, -2567,  1645, -2567, -2567, -2567, -2567,  2166,
   -2567, -2567,   323, -2567,  1502, -2567,  1505,  2166, -2567,  1528,
   -2567, -2567, -2567,  1699,    95, -2567,  1663, -2567,  1468, -2567,
   -2567, -2567, -2567,  1482,   250, -2567,   357, -2567,  1510,  1675,
    1665,  1797,  1519, -2567, -2567,  1513, -2567, -2567,  5217,    96,
    1130,  5217, -2567,   127,   263, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,    70,    70,    70, -2567,    70,  1230,
      70,    70,  1538,   -34,  1538,  1538,  1133,  1133,  1538,  1538,
    1563,   -34,  1571, -2567,  2187, -2567,  1724,   203, -2567,  2197,
   -2567,   -34,    64,    42, -2567, -2567,  5217, -2567, -2567, -2567,
     957, -2567,  1193, -2567,   594, -2567,  5217, -2567,  5217,  1719,
    1721,  1733,  1737,  1686,  1741,  1193, -2567,  1801,   701,    87,
   -2567,  1574, -2567, -2567,   468, -2567, -2567,  1229, -2567,  2201,
   -2567,  2196,   468, -2567,   229,   207,  1591, -2567, -2567,  2215,
   -2567,  1517,  2215,  2219,  1518,  2215,  2219,  5217,  2215, -2567,
   -2567,   307,   428, -2567, -2567,  1755,   417, -2567, -2567,  1748,
     428,  5217,  1749, -2567, -2567,  2205,  2209,  2115, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,  1242,  1242,   263,   263,
     263,  1954, -2567, -2567,  2091,   828, -2567, -2567,   815, -2567,
   -2567, -2567,  1729, -2567, -2567, -2567, -2567,  4403,  1731, -2567,
   -2567, -2567,  1572,   468,  1142,  2217,   483,  1142, -2567,   580,
    1142,  1142,  1692,  1599,  1703, -2567,  4040,  4040, -2567,  1510,
   -2567, -2567, -2567, -2567,  1618, -2567,  8394,  1760, -2567,  1764,
    1765,  1768, -2567,  1768,  1768,  1769,  1773,  1775,  1780,   468,
     616, -2567, -2567, -2567, -2567,   123, -2567,    65,  2638, -2567,
   -2567,  1618, -2567,  1618,  1781, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  7344,   455,
   -2567, -2567,   464, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,  1753, -2567, -2567,   475, -2567, -2567,
   -2567, -2567, -2567, -2567,   364, -2567,   364,   864,   134,  2231,
   -2567, -2567,   609,   148,   862,  2259, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,   468,  1718,   468, -2567, -2567,  1725,
     468,  1728,   468,   468,  1667,  1619,  1784, -2567,  1785,    93,
   -2567, -2567, -2567,  1667, -2567, -2567,  2266, -2567, -2567,  1594,
    1788, -2567, -2567, -2567,  1130, -2567,  1243,  2223,  1243, -2567,
    1193,   190,  5217,  5217,  5217,  1796, -2567, -2567,   428,   428,
    1667,  1610,  1193,    56,  1577,    27,   428, -2567,  1605,  5217,
    1884, -2567, -2567,  1687,   468,  1510, -2567,  3370, -2567, -2567,
   -2567,   468,  1151,  2290, -2567, -2567,  1628,   173,   307,   428,
   -2567, -2567,  2280,  2281, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  3225, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  7433,   428,
     428, -2567,  1133,  5217,   -91,   431,   992, -2567, -2567, -2567,
   -2567, -2567,    98, -2567, -2567, -2567, -2567,  2093,  1856, -2567,
    1870,   594,  5217, -2567,    75, -2567, -2567,   468,  2283,    56,
      56, -2567,  1672, -2567,    59,  1640,   428, -2567,   468,   468,
     468,  5217,   -79, -2567,  1694, -2567, -2567,   347, -2567,  1793,
   -2567,  1795,  5217,  1300, -2567, -2567,  1659, -2567,  2327, -2567,
    1743, -2567, -2567, -2567,   428, -2567, -2567,   201, -2567, -2567,
   -2567,   198, -2567, -2567, -2567, -2567,   468,    56,    56,   244,
     417,  2125,  1531,   428,   307, -2567,  1747, -2567, -2567,  2290,
    2308,  1890, -2567, -2567, -2567, -2567, -2567,  1971,  1971, -2567,
     418,  1750, -2567, -2567,   468,  1667, -2567,  1667,  1667, -2567,
   -2567,  1667,  1667, -2567,   468,  2044,  -130,  1667, -2567,  2044,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   -42,
     -42,   354,  1120, -2567,   822, -2567,   815, -2567,   364,  2321,
   -2567, -2567,  1342,  1900, -2567,   217,  1142,  2325, -2567,  1142,
    1704, -2567, -2567,  1904,  1907,  1734, -2567, -2567, -2567,  1273,
    1273, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  1684,
    -130,  1910,  8678,    51,  8559,  1839, -2567, -2567, -2567,    51,
      51,    51,    51,  1698,  8559,  8559,   285,  1787,   792,   468,
   -2567,  8559,  8559,  8559,  8559, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  1693,   -66,  1130,  5217, -2567, -2567,  1921,  1926,
    2321, -2567, -2567, -2567, -2567, -2567,  1891,  1892,  1898,   819,
    1903,  1905, -2567, -2567, -2567,  2260,   468, -2567,  2380, -2567,
   -2567,   296,  1330, -2567, -2567, -2567, -2567,   468, -2567, -2567,
     296,  1677, -2567,   335, -2567,  1722, -2567,  1756, -2567,  1951,
     317, -2567,  1723, -2567,  1759, -2567,  1803,  1922,   468, -2567,
   -2567, -2567, -2567,  4210,   468, -2567,  1752, -2567, -2567,  2223,
   -2567,  2223,  1742, -2567,  2404,  2407, -2567,  2408,  1783,  5217,
   -2567, -2567,  2412, -2567,  1757, -2567,  1882,  1758,  2219, -2567,
   -2567,  1761,   846,   468, -2567, -2567,  1934,   263,  1168,  1513,
    1808,   367, -2567, -2567, -2567, -2567,  5217,  1667,  1130,  -127,
   -2567,   468,   468,  5217,    28,   -34,  2417,  1355,  2415,  2402,
    2411,  1230, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   428,
    2055, -2567, -2567, -2567, -2567,  2328,  5217,   594, -2567,  2169,
   -2567, -2567, -2567,  5217,   117, -2567,  2067,  2457,  2459,   479,
     486,   468,  2017,  1193, -2567,  3632,  1986,  1988,  1991, -2567,
   -2567,  2065, -2567,  5217,    30, -2567,  1826, -2567, -2567,   274,
   -2567,  5217, -2567, -2567,  1806,   892, -2567,  1434,   468,  2479,
    8423, -2567, -2567, -2567,   428,  1130,   428, -2567, -2567,   313,
   -2567,  2219,  2219,  1789, -2567,  1894,  1896, -2567, -2567, -2567,
   -2567, -2567, -2567,    56,    56, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  2141, -2567, -2567, -2567, -2567,    56,  8943,
    2493,  2474, -2567,  1193,   888,   137,   157,  2351,   -21,  1038,
   -2567,   537, -2567, -2567, -2567,  2024,    67,  1667,   273,  1838,
   -2567,  1833, -2567, -2567, -2567, -2567, -2567,  2029,  2029, -2567,
   -2567, -2567, -2567,  1916,  1836,  2511, -2567, -2567, -2567,   539,
    1840,  1845, -2567, -2567,   428,   154, -2567, -2567, -2567,  1834,
    1120, -2567,   468,   468, -2567, -2567,   468,   622, -2567, -2567,
   -2567, -2567,  2036, -2567, -2567, -2567,   591,  1142, -2567,   604,
   -2567,  2081,  2083,  1142,  1142, -2567, -2567,  1739,  8559, -2567,
     362,  2528,  2097,  2534, -2567, -2567, -2567,  8559, -2567,   488,
    8559,  8559,  8559,  8559,   468,   491, -2567,   377,  2536, -2567,
   -2567,    83,  6404, -2567,  2122,   468,  1878,    51,  2162, -2567,
   -2567, -2567, -2567, -2567, -2567,  1739,  2526,  1739, -2567,  7344,
   -2567, -2567,  2073, -2567,  2046,  2047,   120,   120,   120,   496,
    2260,   120,  6404,   468, -2567,   501,   468,   502, -2567, -2567,
   -2567,  2074,  2075,  2079,  1618,  1618, -2567,  2080, -2567,  2082,
    2092,  2094,  2099, -2567, -2567, -2567, -2567,   843, -2567, -2567,
   -2567,   507, -2567, -2567,   509,   468, -2567,   468,  1744, -2567,
     468,  1745,  5217, -2567,   468,  2563, -2567, -2567,   296, -2567,
   -2567,  1915,   296,   262, -2567, -2567, -2567,  1193,  5217,  5217,
    5217,  4905,  2571,  1667,   199, -2567,  1193,   468, -2567, -2567,
     468,   468, -2567,   982, -2567, -2567,   424, -2567,  1917,  5217,
   -2567, -2567, -2567,  2574,  3370,  2077, -2567,  1924,  2583, -2567,
   -2567,  1193,  1965, -2567, -2567, -2567, -2567, -2567,   468,  2219,
   -2567,   307, -2567,  1992, -2567, -2567,   510, -2567, -2567, -2567,
     428, -2567,  6146, -2567,  1017, -2567, -2567,  2214,  2575, -2567,
    2200,  2206,  2098,  1941,  2208,  2129, -2567, -2567, -2567, -2567,
     641,  2202, -2567, -2567, -2567, -2567,  2065, -2567, -2567, -2567,
     277,   718, -2567, -2567, -2567,  2290,  5217,  2140, -2567,  2109,
   -2567, -2567, -2567, -2567,  2618, -2567, -2567, -2567, -2567,  2619,
   -2567,  1923, -2567,  2601,   -34,   468,  2471,  2471,  2471,  2471,
    2471,  2471, -2567,  2623, -2567,  2625,  2471,  2471,  2471,  2471,
    3225, -2567, -2567,  2471,   183, -2567, -2567, -2567, -2567,  2606,
    2620, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    2627, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   517, -2567,
   -2567, -2567,  2621, -2567, -2567,  1667, -2567,  -130, -2567, -2567,
   -2567, -2567, -2567, -2567,  1984,  1996,   310, -2567,   537, -2567,
     120,  1976,   263, -2567,  2163, -2567, -2567, -2567,   468,   468,
     120, -2567, -2567,   112,  1667,  1255,  8559,   304, -2567,  5217,
   -2567,  5217, -2567, -2567, -2567, -2567, -2567,  2054,   263,   112,
    1667,  2645, -2567,   428,   468,   939,   939, -2567, -2567,  2646,
   -2567,  2646,   625,   625,  2646, -2567, -2567,  1957, -2567,  1142,
    2635, -2567,  1142,  1751,  1142,  1142, -2567, -2567,  2168, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,   123,  1618,  1985,  1618,
   -2567,  1618,  2216,  8559, -2567,  2218,  2220,  2221,  2224, -2567,
   -2567,   285, -2567,   285,   468, -2567, -2567,  8262,  1768,  7577,
    1768,  2656,  2660, -2567, -2567, -2567, -2567, -2567, -2567,   267,
    8559, -2567,  2171, -2567,  2347,   106,   137,   468, -2567,  2226,
   -2567, -2567,  1772,   101, -2567,  1720, -2567,   101,  1667,   841,
    2227,  2671,  2007, -2567, -2567,   518, -2567,   521,   819, -2567,
   -2567,   522,   192, -2567, -2567, -2567,   296, -2567,  2651,  2651,
    2652,  2008,   -50,  2655,  2657,  2658,  2655,  2655, -2567, -2567,
   -2567,   166, -2567,   913,   468, -2567,   296, -2567, -2567, -2567,
    2013, -2567, -2567,  2015, -2567, -2567,   -93,   525, -2567,   468,
     527, -2567,  5217,  2241,  2672,   529,  1193,  2688, -2567, -2567,
   -2567, -2567,  5217,  2076,  2364,  5217, -2567, -2567, -2567, -2567,
     424,   983,   983,  2691,   -77, -2567,  2692, -2567, -2567, -2567,
     983,   468,  2104,  1480,  2693,   468, -2567,  3370,   208,  1667,
    2696,  1193,   -56,  2417,  5217, -2567, -2567,  1230, -2567,  1981,
    5217, -2567, -2567, -2567,  2701,  3632,   428, -2567,   349,   468,
     428, -2567,  2264,  3632,  3632,  3632, -2567, -2567,   641,  2202,
   -2567,  3225, -2567, -2567,  1261, -2567, -2567,  2084, -2567,  3370,
    5098,  8423,    53,  1178, -2567, -2567, -2567,  2041, -2567, -2567,
   -2567, -2567, -2567, -2567,    56,  2471,    56,  2471, -2567, -2567,
   -2567, -2567, -2567, -2567,   -34, -2567,  1048,  1106,  8943, -2567,
    2267,  2229,  8559, -2567,   157,   157, -2567, -2567, -2567, -2567,
     530, -2567,  2191, -2567,   120,   991, -2567,  2039, -2567,   532,
   -2567, -2567,  2713, -2567, -2567,  2121, -2567,  2716,  8650,  8650,
    8650,  8650,   120,   120, -2567, -2567, -2567, -2567, -2567, -2567,
    2713,  2049,   428, -2567,  2646, -2567, -2567,   468,   625,   625,
   -2567, -2567,   625,  2458,  2053, -2567,   611, -2567,  2282,  2284,
   -2567, -2567,  2705,  2286,  2057,  1739,  2061,  2068, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   533, -2567, -2567, -2567, -2567,
     210,   238, -2567,  6404,  6404, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  4040,  4040,  2248,  4040,  2251, -2567,  4040,   782,
    8559,  2735, -2567, -2567,  6404, -2567, -2567, -2567, -2567, -2567,
    2740, -2567,   560, -2567, -2567,  2347,  2069,  2072, -2567, -2567,
     117,   117,   117,  2728,   117,   117,   117,   117,   117,   117,
    2729, -2567,  2730,   117, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  1772, -2567,   428,  2085, -2567,  2249,  2732, -2567,
    2736,  2738,  2742,  2743,  2744,  2745,  1265,  1720, -2567,  2249,
   -2567, -2567,  2749, -2567,  2414,   120,  1504,   120, -2567, -2567,
    2260, -2567, -2567, -2567, -2567,  2329,  2330,   536,  1739,  2750,
    1739, -2567,  2776,   538,  2334,  2335,  2776, -2567, -2567, -2567,
   -2567,  1667, -2567, -2567, -2567,  2300, -2567, -2567,   913, -2567,
    2260, -2567, -2567,   468,   468, -2567, -2567,   468,  -185, -2567,
     296,   182,  2290, -2567,  2271,   182,   257,  1193, -2567,  2781,
    2309, -2567, -2567,  2348,  2192, -2567, -2567,   468,   983,  3370,
    1524,   468,   983, -2567, -2567,    56, -2567, -2567,  5217, -2567,
   -2567,   380, -2567, -2567, -2567,  1193,  2791, -2567,    56,  2290,
     428,  2504, -2567,  2777,  1894,  7344,  2779, -2567, -2567,   307,
    2331, -2567, -2567,  3632, -2567, -2567,  2360,  2361, -2567, -2567,
   -2567,   718, -2567,  1894, -2567,  5217, -2567,   383, -2567,  2197,
   -2567, -2567, -2567, -2567,  2318,  2416, -2567,  2796, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   468,
   -2567,   114, -2567, -2567, -2567,   120, -2567,  -130,  2626,   550,
   -2567, -2567, -2567, -2567,   468,   120, -2567,   112,   112,  2213,
    3720,  3720, -2567, -2567,  8771,  2343, -2567, -2567,  2350,  2354,
   -2567,  2355,  2356,  2365,  2366,   468,   713, -2567, -2567, -2567,
   -2567,   554, -2567, -2567,  2826, -2567, -2567, -2567,   555,  2831,
    2831, -2567, -2567,   558,  2844,  2840, -2567,   115,   428,   112,
   -2567, -2567, -2567, -2567, -2567,  2588,  4403,  1142,  1771,  1142,
    1142,  2413, -2567,  1739,  2419,  1739,  1739,   285, -2567, -2567,
    2660, -2567,  2363,  2638,  2363,   289, -2567,  2363,   289, -2567,
    2363,  4040, -2567, -2567,  8559, -2567,  8559,  2656,   106, -2567,
   -2567, -2567, -2567,  1739, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   605,
    2857, -2567,   428,  1712, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,   400, -2567, -2567, -2567,
    2357, -2567, -2567, -2567, -2567,  2837, -2567, -2567,  2420, -2567,
    2843,  2426,  2849, -2567, -2567, -2567,  2431, -2567,  2396,  6404,
   -2567, -2567, -2567, -2567, -2567,   468,  2856, -2567,  -185, -2567,
   -2567,  2858, -2567, -2567,  2860,   468,  2347,   182, -2567,    56,
     -34, -2567,  2452,  1193, -2567,  5217, -2567,  2270,  2861,   -34,
   -2567, -2567,   467, -2567, -2567, -2567, -2567,   195,  2444, -2567,
   -2567,  1193,  2219,  2619,  2596, -2567,   -34,  2447,  2449,  2417,
    2418, -2567,  2496,  2451, -2567, -2567, -2567, -2567, -2567,  2602,
    2389,  5217,  2409, -2567, -2567, -2567,  1894, -2567,   562, -2567,
     428,  2306, -2567, -2567, -2567,  8559, -2567, -2567,   120, -2567,
    2422, -2567, -2567, -2567,  2713,  2306,  2126,  2126,  2460,  8678,
      51,  8843,    51,    51,    51,    51,   -62,  8843,  8650, -2567,
    8843,  8843,  8843,  8843, -2567, -2567,   120,  2895,   120,  8650,
     263,  6404, -2567,  2619,    94, -2567, -2567, -2567, -2567,  2462,
    2463, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   166, -2567,
   -2567,   564, -2567, -2567, -2567, -2567,   565, -2567,  2363,  2907,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,   428,  2857, -2567,
   -2567, -2567,   428, -2567,   428, -2567, -2567,  2028, -2567,  2622,
    2624,  2889, -2567, -2567,  2468,  2239, -2567, -2567, -2567,  2475,
   -2567,   120,   235, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,  1193, -2567,  2470,  4842,  2441, -2567,
   -2567, -2567,  2257,   -34, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,  2484,   307, -2567,  2496,  2496,  2496,   718, -2567,  3370,
    2305, -2567, -2567,   468, -2567,  2619,   792,   123, -2567,  8501,
     792, -2567,  2486,  8843, -2567,   566,  8843,  8843,  8843,  8843,
    2909,   468,   568, -2567, -2567, -2567, -2567, -2567, -2567,  2453,
   -2567, -2567, -2567,  2656, -2567,   468, -2567,  1142,  1142, -2567,
   -2567, -2567,   196, -2567, -2567, -2567,  8559, -2567,  2285,  2285,
   -2567,  2285, -2567,  2285,  2285, -2567, -2567, -2567,  2455, -2567,
    1739, -2567,   569, -2567,   981, -2567, -2567,    70,    70,    70,
      70,    70,    70, -2567,  2914, -2567,   573, -2567,  5217,  1579,
   -2567,   551,  2496,  3632,  2496,  2417, -2567, -2567, -2567, -2567,
    2642,   411, -2567,   -34, -2567, -2567, -2567, -2567,   574, -2567,
   -2567,  1491, -2567,  2495,  8843, -2567,  2497,  2499,  2500,  2501,
     413,  2428, -2567,  8650, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,  2285, -2567,  2285, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1101, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  4842, -2567,  2939, -2567, -2567, -2567, -2567,
     881, -2567, -2567, -2567, -2567, -2567, -2567,   313, -2567,  8501,
   -2567,  1779, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    2924, -2567,  2925,   576, -2567, -2567,  1337,  1337, -2567, -2567,
    1337, -2567,  5217,   969, -2567, -2567,  2505,    53, -2567,  2287,
    2288,  2947, -2567,  2473,   419, -2567, -2567, -2567, -2567,  2508,
   -2567, -2567, -2567,   468,   468,  1779, -2567,  2932, -2567, -2567,
     629,  2289, -2567, -2567,  2481, -2567,   307, -2567,   468, -2567,
    2417, -2567
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2567, -2567, -2567, -2567, -2567,   405, -2567,   465,  -174, -2567,
   -2567, -1173,    11, -2567, -2567, -1864, -2567, -2567, -2567, -2567,
    -456, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -1887, -2567,
    -995, -2567,  1948, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
     732, -2567, -2567, -2567, -2567,  1388, -2567,  1057, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  2292, -2567,   -38, -2567, -2567,
    2938, -2567,  2945, -2567, -2567, -2567, -2567, -2567,   816,   456,
   -2567,   812, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   -69,  1087,   481, -2567, -2567,  2628,     2,
   -2567,  2869, -2567, -2567,  2866, -2567,  2780, -2567, -2567, -2567,
   -2567, -2567,  2640,  2317,  1236,  2634,  -540,   959, -2567, -2567,
   -2567, -2567, -2567,  1239,  -660, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   147, -2567,  2464,  2785,   -25,  2384, -2567,
    -228,  1700, -2567,  2614, -2567, -2567, -2567, -2567,  2616, -2567,
   -2567, -2567, -2567,  -396, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  2432, -2567,  2429, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -1242, -2567, -2567,  -400, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  -124, -2567, -2567,
    1203, -2567, -1098, -1183,  -532, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  2009, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    -593, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2195, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  -511, -2567,  -102,
   -2567, -2567, -2567, -2567,  2590, -2567, -2567,  -203, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    1738, -2567, -2567, -2567, -2567,   998, -2567, -2567, -2567, -2567,
   -2567, -1655, -2567, -2567,   993, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -1135,  -637,   859,  1159, -2567,
    -229,  -575,   666, -1142,   933, -2567,   692, -2567, -2191,    -3,
    -636, -2567, -2567, -2064,   318,  1837, -2567, -2567, -2567,   766,
    1408, -2567, -2567, -2567, -2567, -2567, -2567,   443, -2567,   130,
   -2567,  1412, -2567,  1084, -2567,   769, -2567, -2567, -2567, -2567,
    -435, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
     870, -2567, -2567, -1579, -2567,  1071, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1575, -2567, -2567, -2567, -2567, -2567, -2567,
     -68, -2567, -2567, -1761, -2567, -2567, -2567, -2567,   461, -1945,
   -2567, -1141, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  3019, -2567,
   -2567, -2567,  2944,  2996,   667, -2567, -2567,   -98, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2998, -2567,
   -2567,  3018, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2100,
   -2567, -2567, -2567, -2567, -2567,  1128, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,  -709,  2274, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  2058, -2567, -2567,   -43, -2567,
   -2567,  1125, -2567, -2567,  1459,  -188,  2717, -2567, -2567, -2567,
   -2567,   654, -2567, -1071,  2018,  1430, -1475,  1516, -2567,  1134,
    1807,    26,  -157, -2567,  2261,  1608, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,  1525, -2567, -2567, -2567,
    -792, -2567,  -569, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    -366, -2567, -2567, -2567, -2567, -2567, -2567,   487, -2567, -1217,
    1621,   628, -2567, -2567, -2567, -2567, -2567,   302, -2567,  -155,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  1511, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  -535, -2567,  1181,  2611, -2567,
   -2567,   309, -2567,  -623, -2567, -2567,   325,   631, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   840, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,   254, -2567,    -7,    -2, -2567, -2567,     4, -2567, -2447,
   -2567,   270,   941, -1384, -2567, -2567, -2567,  1291, -2567, -1712,
   -2567, -2567, -2567, -1735, -2567, -2567, -1715, -2567, -2567, -2567,
   -2567, -2055, -2567,  1309,   988, -2567, -2567, -2567, -2567, -2567,
     770, -2567, -2567, -2567, -2567, -2567, -2567,  -350, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,    89, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1439, -2567,  1440, -2567,   750,  1102, -2567,
   -2241,   174, -2567, -2567, -2567, -2567, -2567, -2567,   328, -2567,
   -2567,  -138, -2567,  -441, -1372, -2567, -2567, -2567, -2567, -2567,
     297, -2567, -2567, -2567, -2567, -2567, -1604, -2567, -2567, -2567,
   -2567, -2567, -2567, -2167,  1037, -2567, -2334,  1121, -2567, -2567,
   -2054,   416,   412,   693, -2567, -1626, -2087, -2567, -2567,   121,
    -211, -2567, -2567, -2567, -2567, -1615, -2567, -2567, -2567,   316,
   -2567,   644,  -624, -2567,   642,  -251,  1477,    68, -1859,   672,
     708,   397, -2567, -2567, -2567, -2567,  2502, -1249, -2053,  3114,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  -360, -2567,
   -1934, -2567,  1846, -2567, -2567,  -126,   690, -2567, -2024,   691,
     200,   506,   476, -1633, -2019,  1395,   126,   662, -1300, -2567,
    1399, -2567, -2567, -2567,  1497,  -669, -2567, -2567,  -147,  1861,
   -2567,   763, -2567, -2567,   801,   219, -2567, -2567, -2567, -1851,
     -18, -2056, -2567,  -850, -2567, -2567, -2567, -2567,  1533, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2522,
     -32, -2567, -2566, -1921,  -555, -1047, -2567, -2567,   -19, -2567,
   -2567, -2567,   610, -1099,  1401,  -759,  2020,  1678,  1679, -1497,
   -2567, -2567,   620,   976,   113, -2567, -2567, -2567, -2567,  1702,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   275,
    1740,  2615, -2567, -2567, -2567, -2567
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1972
static const short yytable[] =
{
      40,    42,    43,    45,   277,  1429,    45,    50,   581,   336,
     191,  1025,  1490,  1552,  1867,    94,  1709,  1710,  1544,   109,
    1791,  1197,   699,  2007,  1379,  1775,   390,  1382,  1518,  2396,
    1497,  1498,  2438,  1499,  2440,  1520,  1521,   988,  1143,   419,
     420,  1945,  1946,   964,    66,  2460,   437,   592,  2462,  2573,
      79,  1486,  2132,  1487,    39,    39,   305,   108,   970,    66,
      94,  1012,  2673,  1113,   244,    39,  2108,   421,   422,   592,
     115,  1053,  1056,  2958,  2959,  2960,   191,   122,  2133,   118,
    1893,  2175,   129,    39,   435,   131,    39,  2048,  1445,   134,
     135,   975,    39,  2604,   979,   191,  1491,    39,  1624,  2927,
    1459,  1459,  1752,  1543,  1753,  2309, -1970,  2527,    66,  1089,
      39,    39,  1089,  1081,  2060,  2061,  2062,  2063,  2650,  1735,
    2962,    79,  1098,  1579,   239,   204,  1089,   241,  1735,   243,
    1089,  1057,  2719,    39,   247,  1488,  2325,  1115,  1642,    39,
    1076,   283,  1089,  1077,  1098,  1057,  1205,    39,   423,  1619,
    1127,  1088,   439,  1098,   441,   523,   442,   443,   444,  2363,
    1137,    39,  1201,  1629,    39,   449,   106,  1152,     1,   460,
     461,   369,     2,  2892,  1195,    39,   374,   375,  1856,   603,
    1620,     3,  1446,  1447,    39,  1127,   604,  1811,   592,  1127,
     283,  2797,  1320,  1127,   608,   359,   339,    86,  2693,  1098,
     592,   609,  1098,  1545,  1546,  1083,  1148,   341,  1540,  1151,
    1237,   106,   283,   342,   343,  1106,  2693,    39,  1196,  2517,
     283,  1319,  1320,    39,  1057,  2053,    39,   191,  2852,  1099,
    1820,  1608,   191,  1057,  1153,    39,   367,  2453,  2456,  2456,
    1608,  2693,  2456,  2036,  2684,   377,  2686,  2695,  3081,  1856,
    2696,  2697,  2698,  2699,  2700,  2701,   334,   406,   283,   337,
     338,    39,  3092,    66,   418,   418,   418,   418,   418,  1601,
    1602,     4,   418,   578,  2332,  1190,  2695,    39,  3012,  2696,
    2697,  2698,  2699,  2700,  2701,  1207,   991,  1201,  1222,    39,
      39,   334,  1228,   574,  3314,  2754,  1259,  1916,  1234,  1860,
    1236,  1861,  2572,  1862,    39,  2518,   283,  1249,  1250,    39,
    1057,  1879,    39,   283,  1319,  1320,    39,    62,  1910,    66,
      66,   617,  3180,    39,   620,  3082,  3083,  2637,   524,    86,
     526,   283,  1249,  1250,    39,  2602,   625,    39,   955,   334,
     669,   628,   629,   630,   631,  1816,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   968,    79,  2690,   334,  2397,  2371,   331,
    1916,  2374,  2184,   649,   650,  1070,    39,  2329,   652,  1885,
     653,    39,     1,   437,    62,  2184,     2,   576,   334,   584,
    2857,  1143,  2618,   656,   657,   658,   659,  2100,  1201,   992,
      39,   667,  1057,   594,    39,  3231,  1791,  2638,  2639,  2640,
    2641,  2642,  2175,   586,   587,   588,   334,  1866,  3450,  2086,
     969,  1933,  1624,  1259,  3487,  1305,   191,  2235,  1259,  2531,
     592,     5,  1306, -1970,   592,  2789,  2839,    62,  2258,   592,
     612,   677,   411,  1139,  1937,  1609,   119,  1397,  1398,  1603,
     680,  3300,   691,   682,  1609,    39,   686,  1881,    39,  1129,
    1755,  2259,  2436,    85,   412,  1068,  1308,  2054,   952,  1755,
      86,  2621,   324,   325,   326,   327,   328,  1399,  1400,  1401,
    1761,  2630,  1024,  3084,   592,   324,   325,   326,   327,   328,
    3075,   592,   191,  2403,    51,    39,  2403,    62,  2815,   535,
     953,  2458,  2191,    89,  2335,    52,  2106,  2466,   993,    62,
       7,   545,  2484,    66,  2486,  2547,    87,    88,  1195,    33,
     851,   944,  2608,  2777,    62,  1010,  2777,  2777,  1013,    62,
    2817,  1122,  2820,  1558,  2820,  2915,  1139,  2925,  2987,  1527,
    1528,  3055,  2192,  3062,  3076,    51,  1575,  2816,   692,   588,
     692,     6,  1581,    60,    62,  3148,  1437,  1880,   692,  3168,
    3168,  1131,   595,  3176,  1052,  1917,    39,  3283,   191,  3322,
    3322,  3384,    32,  3384,  2775,   406,  2723,   406,  3423,  3439,
    2055,  3168,  2949,  2949,  2949,  2949,   986,  1262,   967,   418,
    2198,   691,   972,  2911,  1541,  2840,    62,  2532,  1766,     7,
    2336,    62,  2155,  1934,  2156,  1192,  1193,   579,   605,   418,
    3301,  1767,  2087,  1976,  1977,  1649,  2994,  1324,  2997,  1776,
      62,  3000,  2984,  2200,  1492,  1625,  2880,  2326,  2790,  2631,
       8,  1604,  1625,  1787,  1243,    89,    39,  1246,  1917,  3250,
    2782,  1130,  1639,  1152,  1195,  1542,  2072,  1324,  2893, -1970,
   -1970, -1970, -1970, -1970,  3308,  2858,  1547,     5,  2989,     9,
    3007,  1913,  2317,   286,  1190,  2037,  2702,  2703,  2755,  1559,
    1052,   936,  1258,  3116,  1560,    62,  1566,  1493,    62,  2853,
    2912,  2913,  1656,  3343,  2612,  1143,  2049,  3154,  3093,  2056,
    1261,  1466,  3127,  2242,  3181,  2702,  2703,    66,    66,    66,
    1044,    66,  1048,  1050,  1460,  1485,  1058,  1060,  1061,  2654,
    1641,  1066,  1768,  1050,  1262,  1448,  1069,  1052,    66,  1262,
    3140,  2704,  1736,  1251,  2619,  3052,  1224,  1061,  3184,  1580,
    2207,  1763,   335,  1489,  1739,  3057,   575,  3059,  1058,  1058,
    1324, -1970,  1823,  1548,  2907,  1894,   415,   415,  1061,  2811,
    2704,  2783,  2414,  2364,    66,  3071,  1550,   971,  1691,  2190,
      66,  1061,    66,  3315,  2501,  2920,    66,   529,  2501,    66,
    2448,  1116,    66,  3100,  2812,   415,    89,  3105,   415,  1050,
     684,  1822,    66,    56,  2448,  1711,  2263,   418,  1133,   304,
    1058,  1494,  3001,  1837,  1140,  2014,  1698,    66,  3098,  1701,
    1702,  2398,   606,    66,  1610,   418,   418,  3286, -1970,  1035,
      66,    66,    66,  1610,  1720,  1023,  1218,   610,   332,  1225,
    3197,  3290,  1252,  2245,    66,  1770,  1605,  3453,  1107,  1647,
     577,  1238,   585,  1238,   418,  1656,  1238,   418,   304,  1238,
      66,  1771,  1383,  1863,  1402,   111,   112,  2705,  2185,  3495,
      61,  1864,    39,  2067,  1307,     1,     8,  3085,  1202,  1606,
     304,  3109,  2411,  2448,  3130,  2471,  2472,  2356,   304,    10,
    1712,    90,  2448,   593,  2949,  2949,  2705,   598,  2949,  1259,
    2263,  3232,   599,   613,   678,  1368,  1713,   107,  1368,    39,
     977,  2506,  3436,   681,  3451,   667,   683,   667,   667,   687,
    3488,  1690,  1956,  1756,  1267,  1877,   304,   333, -1970,  1978,
    2226,  1766,  1757,  2706,  3208,    39,  3048,   161,  3051,    39,
    1824,  1825,  1826,  1762,  1767,  1311,    77,  2220,  1714,  1403,
    3194,  1696,  3195,  3196,  2221,  1302,  2404,  1844,  2348,  2410,
    2643,  2834,  2706,  1287,  2459,  3282,  1052,  2349,  3262,  2464,
    2467,  1260,   114,  3376,   304,  2485,  1469,  2487,  2548,    39,
    3212,   304,    91,  2707,  2708,  2609,  2778,  1715,  1300,  2779,
    2781,  2350,  1404,  2818,  2351,  2821,   110,  2825,  2916,   304,
    2926,  2988,  1055,  1055,  3056,   288,  3063,  1055,  1055,   117,
    2352,  1340,  2707,  2708,  1452,  1261,  1716,  1921,  3149,  1902,
    1055,  1453,  3169,  3175,  2375,  1717,  3177, -1970,   291, -1970,
    3284,  1878,  3323,  3324,  3385,  3242,  3392,  3408,  1883,    39,
    1055,  3424,  3440,  1055,  3475,  1768,  1891,  1470,  1699,  1055,
    1560,  3496,  1386,  1055,  1393,  1961,   692,  1055, -1970,  2379,
    1415,  1055,    92,  2551,    39,  1055,  1055,   119,  1055,  1909,
      93,  1055,  2382,  1055,  1055,  1055,  3144,  1655, -1970,  2977,
    1924,  1055,  1416,  1045,  1055,    39,  3152,  2168,   121,  2169,
    1058,  1055,    62,    66,  2903,    39,  1694,   123,  1055,   324,
     325,   326,   327,   328,   978,  1055,  2780,    13,  3002,    66,
     297,  2586,  1058,  2353,  1781,  1659,  1055,   378,   127,  1143,
    1055,  1734,  1791,  3174,  1055,  2949,  2478,  2479,  2480,    13,
    1055,  2949,  2949,  1055,  2949,  2949,  2949,  2949,     5,  1312,
    1138,  1766,    39,  2949,   379,  1697,  3287,  3313,  2799,  1477,
    2543,    66,  2905,    39,  1767,    62,  1140, -1970,  1770,    62,
     197,  2957,  2957,  2957,  2957,   198,  2354,  1140,  2674,  2723,
    2676,  3009,  2677,  2355,  1771,  1475,  2022,    39,    61, -1970,
      39,    66,    66,    66,  1766,    66,  1766,    66,    66,   201,
    1262,  1854,  2170,    66,    66,  2171,     1,  1767,    39,  1767,
       2,  2075,   300,   242,  1524,  2038,  1577,  2327,  2040,     3,
    2623,   366,  1534,  2315,   301,   302,  3214,  1956,  3167,    66,
    3010,  1421,   303,  2168, -1970,  2169, -1970,   696,    32,    33,
    1573,  2180,    66,   111,   112,   950,  2649,  2149,  1201,  3464,
      39,  1585,  1700,  1422,    66,  3003,  1477,  3004,  2800,  1593,
    2528, -1970,  1956,  2380,  2225,  1768,  1131,  2949,     6,    62,
    2949,  2949,  2949,  2949,   249,  3215,  2383,  3303,    66,    66,
    1263,  1264,  1265,  2978,  1586,  1500,    39,    66,  3311,   946,
    1838,  1266,  3375,   251,    62,  2801,  3381,  1635,  1817,    39,
      39,  2216, -1970,    66,    66,  1578,  3409,   261,  1768,     4,
    1768,  1437,   947,   258,  3145,    62,  2882,  3407,    39,  3288,
    3042,   259,    39,  1743,  1744,    62,   262,  2162,  2481,  2023,
    1693,   265, -1970,  1850,  2314,  3174,  3174, -1970,  2170, -1970,
     534,  2171, -1970,  1340,  1340,   266,   540,     8,  2024,  2025,
   -1970, -1970, -1970,  1340,  2186,  1764,   363,  1765,  2949,  2802,
    1961,  1826,  1956,  1956, -1970,   267,  1733,  2949,  2026,   268,
    1152, -1970,  1139,  2803,  1740,   437,     9,  1790,  1770,  1769,
     427,  1059,  2213,    62,  2772,   428,  2022,   430,  1075,  2076,
    1540,  1560,  2033,  2201,  1771,  1961,  1899,  1900,  3200,    39,
    2077,  3205,   269,  1195,  3207,   191,  1800,  1139,   270,  1093,
      62,  2234,  2453,  1085,  1086,  3113,  3410,  3366,  3367,  3368,
    3411,  1770,  1102,  1770,   271,  1777,  3458,  2889,   330,  1782,
    1788,  1782,  2993,  2993,  2822,  2993,  2862,  1771,  2993,  1771,
     272,  1794,  1796,  1797,  1941,  1942,    66,  1801,  1803,  1804,
    1805,  1058,  1745,  1746,  1747,  1748,  1749,  1750,   273,  1055,
    1058,  2902,   274,  2957,  2957,  1135,  3080,  2957,   275,     5,
      62,  1140,  2804,    66,   371,    66,  2859,    66,    66,   111,
     112,  2109,  1956, -1970,  2248,    66,    66,  1058,  2805,    66,
     418,    39,   418,    66,  1501,  1961,  1961, -1970,   346,   347,
     348,  1140,  1121,  -296,   276,  3432,    62,  3434,  1853,  1140,
     946,  1128,   278,  1421,  2507,    66,    66,  1223,  2508,    62,
      62,  1229, -1970,  3183,    44,  1233,    39,  2519,  3204,  2023,
    2846,  3204,  1289,   947,   318,  1422,  3410,    39,    62,   440,
    3411,  1091,    62, -1657, -1970, -1970,  2917,  1276,  2024,  2025,
    1282,  1283,  2540,  2921,  3049,  1100,  2381,  1241,  1277,  1105,
    1244,    39,  2386,  2387,  1417,  1418,    66,    66,  2026,    66,
     319,  1119,    66,    66,  3103,  3293,   381,  3296,  3297,  3298,
    3299,    39,   320,  1055,  1055,  1055,  2502,   382,  -296,     6,
    2867,   424,   425,   426,  1897,   383,   418,   418,  2875,  2876,
    2877,   418,   391,    66,  -296,  1906,  1907,  1908,  1278,  1947,
    1948,  1949,  3325,  3415,  1950,  1961,  1951,  1952,   427,   980,
    1502,   981,  1279,   428,   429,   430,  1503,  1504,  1505,  3426,
    3428,    66,  1242,  1531,  1532,  1245,    39,     7,  1248,  2544,
    2495,  1535,  1536,  1238,   418,   418,  -296,   321,  1506,  2030,
      66,    66,  1553,  1554,  1555,  1556,  2509,  2510,  1826,  2513,
   -1970,  2089, -1970, -1970, -1970,  1525,  1526,   322,     8,  1529,
    1530,  1980,  1058,   323,  1058,  1058,  1065,  2534,  1058,  1058,
     384,  1990,  3415,   400,  1058,  -296,  1347,  2457,  1074,  2580,
    2461,  2199,  2053,   401,  2957,  3285,   385,     9,   354,  3428,
    2957,  2957,   355,  2957,  2957,  2957,  2957,   984,    66,   985,
    1280,  1049,  2957,    39,  -296,  2110,   356,  1094, -1970,  2034,
    1152,   360,  1057,  -296,    39,   361,  1195,  1430,  1431,  1432,
    1475,  2993,    39,  1111,  1112,  2111,  2112,  2113,   386,  1118,
     365,  1571,  1120,    39,  2577,  1426,  1703,   370,  1704,  1340,
     372,  1340,  1195,  1507,  2272,  2274,  1508,  1706,  2041,  1707,
    2042,  1340,  1340,  1058,  1509,   376,  2080,  1440,  1340,  1340,
    1340,  1340, -1970,  1795,  2114,    39, -1970,   387,  1995,   486,
    1798,  1140,    39,  1802,   413,    39,  2115,   407,  2045,  1996,
    2046,   410,  2212,  1386,  1818,  2284,  1818,  2116,  1510,  2490,
    2493,    39,    39,  1777,   445,  2668,   388,  2669,  1782,   447,
    1997,   667,   448,  2117,  1788,   389,  1998,  1782,  2950,  2950,
    2950,  2950,   459,  2118,  1999,  3189,  2957,  3190,  3119,  2957,
    2957,  2957,  2957,  1511,  3469,  2147,    39,  1726,  2119,  1727,
    1728,  2151,  1925,   112,  2017,  2018,  2000,  2645,   462,  2646,
     463, -1970,  1512,  1513,   465,  3204,   324,   325,   326,   327,
     328,  3219,   466,  1514,  3441,  3442,  1357,  2826,  1515,  1359,
    2178,  1360,  1361,  1362,  1363,  1364,   487,   488,   489,   490,
     491,   492,  2795,  2796,  1058,  1140,  2120,  1953,  2194,  2195,
    1954,   418,  1955,   467,   493,   494,   495,   468,  2665,  2181,
    2182,  2667,  2856,  2670,  2671,   469,    66,  1516,  3121,  1263,
    1264,   392,  1956,  3156,  3157,  2121,   516,  2957,   530,   528,
     532,   537,  1957,   538,   539,  2122,  2957,   541,  2223,   542,
      66,   546,   548,  2728,  2729,  3220,  2730,  2731,  2732,  1517,
     547,   552, -1970,  1958,   563,   564,  2123,  3253,   562,   583,
    2124,   567,    66,   572,  2249,  1593,  3261,  1340,   582,   590,
     591,    66,  1140,    66,   596,   597,  1959,  2758,   601,   618,
    1960,   602,   621,  3267,   611,   450,   622,   623,  2125,   626,
     418,   418,  2759,  2760,   660,   651,   654,  2126,   661,   662,
     668,  2761,   670,   671,   672,   418,   393,  3221,   673,  3222,
      66,    66,    66,   674,   675,   676,    66,   679,  1152,  1152,
    2828,   685,   394,  2833,  1058,  3223,   697,     1,  1721,   951,
     956,  1643,   958,  3224,   959,  2762,   960,  3225,   965,   966,
     976,   982,   983,   496,  2763,  2733,   497,   990,   995,   997,
    1850,    66,   999,  2734,  1000,  1961,  1018,  1021,  1001,  2370,
    2370,  1026,  3226,  2370,   395,  1027,  1029,  1030,  1031,  1032,
     451,  1037,  1034,  2764,  1038,  1039,   340,  1040,  3312,  1150,
     345,  1711,  1230,  1291,  1293,  1340,   452,  2735,  1190,  1292,
    1294,  1295,  1296,  1297,  1340,  1298,  2736,  1340,  1340,  1340,
    1340,  2409,  1299,   396,  1058,  1301,  1807,  1303,  2415,  1340,
    1304,  1309,  2433,  1310,  1313,  1812,  1315,  2765,  1358,  1314,
    2950,  2950,   191,  1370,  2950,  2737,  2738,  1365,   453,  1366,
    3360,  1367,   397,  2449,  2449,  2449,  1371,  1373,  2449,  1340,
    2463,   398,  1835,  1777,  1384,    71,  1374,  3015,  3016,  3017,
    1423,  3019,  3020,  3021,  3022,  3023,  3024,  1375,  1376,  1377,
    3027,  2766,  1055,  1414,  1378,   498,  1712,   454,  1380,  2739,
    1644,  1385,  2488,  1389,  2489,  2491,  1390,  2492,  2494,  1419,
     499,  2496,  1713,  1392,   500,  1782,  3172,  3173,  1391,  1782,
      66,  1420,  1427,  1424,    66,  1425,   455,  1433,  3094,  1450,
    1058,  2449,  2388,    66,  2178,   456,  1444,  2524,  2524,   162,
     194,  1451,  1454,  2740,  1458,  1455,  1457,  1462,  1477,  1463,
     501,  1479,  1474,  1481,  1714,  1482,  3110,  1522,    66,  1947,
    1948,  1949,  1538,  1465,  1950,  2542,  1951,  1952,    66,  1539,
    3438,  3365,  1543,  1576,  1567,  1581,  1568,    66,   502,  1590,
    1592,    66,  3416,  3417,  3418,  3419,  3420,  3421,  1569,  1615,
    1616,  3220,  1570,  1715,   592,   503,  1574,  2741,  1617,  1618,
    1623,  1631,  1645,  1627,  1630,  1632,   194,    66,  1633,  1681,
    1646,  1705,  1689,  1695,  1692,  1722,  1647,  2389,  1648,  1723,
    1724,  1055,  1716,  1725,  1729,   194,  1754,  1780,  1730,  1649,
    1731,  1717,  2587,  2390,  1793,  1732,  1760,  1808,  1992,  1809,
    1810,  1813,  1814,  1815,  1445,  1745,  1746,  1747,  1748,  1749,
    1750,  1829,  1843,  3221,  1055,  3222,  1650,  1984,  1836,  1985,
    1986,  1550,  1845,  1988,  1989,  1856,  1847,  1858,  1869,  2008,
    1870,  3223,  1651,  1886,  1888,  2391,   504,  1652,  1898,  3224,
    1889,  2950,  1058,  3225,  1901,  1903,  3108,  2950,  2950,  1653,
    2950,  2950,  2950,  2950,   414,  1913,  1654,  2449,  1920,  2950,
    1922,  1927,  1928,  1625,  1970,  2626,  1990,  2449,  3226,   944,
    1980,  1058,  1930,  1340,  2392,  1971,  1968,  2031,  2035,  1979,
    1973,  2039,  2043,  3128,  3213,  2044,  1980,  1058,  2049,   485,
      66,  2370,  2047,  1850,  1720,  2898,  2072,  2900,  3433,  2090,
    2064,  2085,   505,  2393,  2091,  2103,  2096,  2097,  2071,  3158,
     521,   522,  2394,  2098,  2051,  2106,  2058,   194,  2101,   486,
    2102,  2887,   194,  2135,  2137,  2140,  2058,  1347,  2138,  2139,
    1340,  2141,  2142,  2081,  2082,  2083,  2084,  2144,  1058,  2158,
    1058,  2415,  2159,  2160,  1340,  2161,  1340,  2163,  2165,  2179,
    2157,  2153,  1624,  2202,  3255,  3500,  2865,  1340,  2204,  2164,
    2209,   667,  2449,    66,  2433,   191,  2166,  2205,  2167,   667,
     667,   667,  3265,  2950,  2214,  2449,  2950,  2950,  2950,  2950,
   -1970,  2211,  2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749,
    2750,  2751,  2218,  1782,  2219,  2224,  3188,  1953,  3191,  3192,
    1954,  2227,  1955,  2228,  1655,  2238,  2229,   191, -1970,  1656,
    1993,  1788,  2232,  1782,  2246,  1657,   487,   488,   489,   490,
     491,   492,  1956,  2252,  1994,  2265,  2147,  2263,  2312,  2187,
    2313,  1266,  1957,    66,   493,   494,   495,  1658,  2324,  2330,
    2338,  2339,  1659,  2344,  2340,  2343,  2345,  2378,  2359, -1970,
   -1970, -1970,  2360,  2281, -1970,  2367, -1970, -1970,  2178,  2384,
    2847,  2385,  2849,  2399,  2950,  2449,  1058,  1995,    66,  2401,
   -1970,  2413, -1970,  2950,  1195,  2400,  1959,  2430,  1996,  2435,
    1960,  2437,  2439,    66,  2441,    66,  2871,    66, -1970,  2468,
    2469,  2442,  2445,  3256,  2470,  2473, -1970,  2474,  2499,  1997,
   -1970,    66,  1078,  1078,   655,  1998,  2515,  2475,  1340,  2476,
    3187, -1970,  2535,  1999,  2477,  3345,   194,  2504,  2539,  2533,
    2537,   418,  2256,   418,  2541, -1970,  2538,  2553,  2545,  3280,
    2554,  1055,  2556,    66,    66,  2000,  3294,  1055,  2557,  1340,
    2560,  2558,  3294,  2559,  2561,  3304,  3305,  3306,  3307, -1970,
    2578,  2449,  2579,  2581,  1540,  1961,  1265,  2585,  2594,  2334,
    2596,  2605,  2614,  1055,  2606,  2946,  2946,  2946,  2946,  2449,
    2449,  2607,  3107,   496,  2615,  2622,   497,  2610,  2624,    66,
    2652,  2657,   194,  2672,  2971,  3112,  1741,  1742,  1743,  1744,
    2647,  2666,  2693,  2675,  2678,  3102,  2680,  2694,  2681,  2682,
    1078,  2717,  2683,  2714,  2726,  2774,  2775,  2784,  2787,  2776,
    1253,  2791,  2001,  2793,  2794,  2813,  2788,  2814,  2002,  2823,
    1340,  1340,  2824,  2827,  2830,  2829,  2837,  2841,  2848,  1340,
    1340,  2863,  1340,  2845,  2855,  1340,  2866,  1340,  2885,  2071,
    1347,  1340,  2874,  2897,  2909,  2908,  2917,  2924,  2927,  2402,
    2928,  1735,  2405,  2406,  2407,  2408, -1970,  2969,   194,  2976,
    2979,  2981,  2980,  2995,  2982,  2983,  2998,   191,  3383,  2985,
    3006,  3386,  3387,  3388,  3389,  3008,  2986,  3013,  3014,   667,
    3033,    66,    39,  3018,  3025,  3026,  3032,  3035,  1041,  1042,
    1043,  3036,  1046,    66,  3037,   498,  2801,   167,  3038,  3039,
    3040,  3041,  2449,  3050,  2449,  3046,  3058,  3053,  3054,  1072,
     499,  3060,  3064,  3065,   500,  3069,  3095,  1745,  1746,  1747,
    1748,  1749,  1750,  3089,  3096,  3098,  3097, -1970,  1058,  3111,
   -1970, -1970, -1970,  3115,  3117,  1835,  3395,  3396,  3124,  3125,
    3072,  3073,  3120,  3133,  2496,  1096,  3136,  1782,  1260,  3140,
     501,  1101, -1970,  1103,    66,  3146,  3425,  1110,  3159,  3445,
    1110,  1341, -1970,  1110,  2524,  3160,  3168,  3104,  2524,  3161,
    3162,  3163,   418,  1123,  3170,  3171,  3172,  3173,   502,  3178,
    3164,  3165,    66, -1970,  3179,   418,  3185,    66,  1123,  3198,
    3252,  3193,  3217,  3234,  1186,   503,    66, -1838,  3235,  3236,
    2772,  1046,  1199,  1203,  3238,  3239, -1970,  1219,  2798,  3240,
   -1970,  3241,  3245,  3254,  3247,  1231,  3248,  3260,  1209,  1055,
    1055,  3258,  3264,  3266,  2689,  3268,  2692,  3269,  3272,  3274,
   -1970,  1255,  3279,  3270, -1970,  1736,  3137,  3289,  3291,  3309,
    3317,  3318,  2449,  1253,  3326,  3338,  3339,  3340,  3336,  3346,
    3337,  2626,  2449,  3341,  1980,  1980,  3358,  2946,  2946,  3359,
    3479,  2946,  3364,  3372,  3382,  3390,  3406,  1210,  3393,  3422,
    3435,  3452,  3166,  3444,  3462,  3446,   504,  3447,  3448,  3449,
    3473,  3474,  3485,  3481,  3486, -1970,  3489,  2611,  3494,  3483,
    3484,  3498,  3499,  2870,  2819,    66,  1980,  3461,  2570,  1381,
    1912,  2237,    62,    57,  1211,  1745,  1746,  1747,  1748,  1749,
    1750,  1036,    58,  2520,  1058,  2529,  2635,  2844,   200,   205,
     543,  1028,  1140,   536,   353,  1140,  2092,   544,  1340,   989,
    2093,  1340,  2651,  1340,   358,  2449,   571,   569,  1347,   962,
     961,   688,   505,  3459,  1217,  1708,  2150,   607,  2368,  2511,
    2376,  1372,  2196,  1685,  1940,  3135,  2896,  2262,  1687,    66,
    2584,  1944,  3482,  2516,  2282,  2947,  2947,  2947,  2947,  3263,
    1840,    54,   136,    68,  2663,    69,    55,  2244,  1290,  1117,
    2247,   527,  1926,  2071,  1967,  2071,  1876,  1395,  3218,  1621,
    3327,  1149,  2251,  1874,  3465,  2679,  1340,  1831,  2891,  1821,
    1212,  3045,  3335,  1892,  2215,   627,  3044,  3028,  2770,  3091,
    3251,  2691,  3246,  3249,  2136,  2105,   418,  3074,  1253,  3468,
      66,  3371,  2713,  2505,  2465,  2636,  2616,  3211,  2010,  2011,
    2342,  3153,  3047,  3342,  2412,  3070,  2991,  2333,    66,  2990,
    2688,  3397,  3066,  2786,  2948,  2948,  2948,  2948,  3233,  3206,
    2771,  1983,  2687,    49,   998,  3493,  2724,  1673,  2725,  3155,
    2066,  2923,  3210,  2065,  1255,  1975,  3374,    66,  1638,   174,
    2628,  3292,  1340,  3151,  1938,  2449,  3310,  1213,  3302,  2854,
    1438,   175,  1849,  1341,  1341,  2088,  1340,  2851,  2946,  1476,
    2536,  1855,     0,  1341,  2946,  2946,  1839,  2946,  2946,  2946,
    2946,   698,     0,  2449,     0,  2449,  2946,   191,  1340,     0,
    2996,  2187,  2999,     0,     0,     0,     0,  1214,     0,     0,
       0,     0,  1468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,    66,
       0,    66,  1496,  1496,  1496,     0,  1496,     0,  1496,  1496,
       0,     0,     0,     0,    71,    71,     0,     0,  2449,   667,
       0,     0,     0,  2256,     0,     0,     0,     0,     0,     0,
    1500,    66,  1215,     0,     0,     0,     0,     0,     0,     0,
    1203,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,     0,     0,  1203,  1347,     0,     0,     0,     0,     0,
    3137,     0,     0,     0,     0,  1588,  1340,     0,     0,     0,
    2946,   181,     0,  2946,  2946,  2946,  2946,     0,  3391,   481,
     482,   483,   484,   485,     0,     0,     0,     0,     0,  1255,
    1438,     0,  3394,     0,     0,   182,     0,     0,  1628,  1140,
       0,     0,     0,  1340,     0,  1253,     0,  2947,  2947,     0,
       0,  2947,     0,   486,  1636,  1636,     0,     0,     0,     0,
       0,     0,     0,     0,    66,    66,    66,    66,    66,    66,
    3244,     0,     0,     0,     0,     0,  3427,     0,     0,   183,
    3244,     0,     0,     0,     0,     0,     0,     0,   184,     0,
       0,     0,  3005,     0,     0,     0,     0,     0,     0,     0,
       0,  2946,     0,     0,     0,     0,     0,     0,   164,   165,
    2946,     0,  3203,     0,     0,  3203,   166,    39,     0,     0,
       0,     0,     0,     0,     0,     0,  2948,  2948,     0,     0,
    2948,     0,   167,     0,     0,     0,     0,     0,     0,  2012,
    2013,     0,     0,     0,     0,     0,  2029,     0,     0,     0,
     487,   488,   489,   490,   491,   492,  1340,     0,  3470,     0,
       0,     0,     0,  3068,     0,     0,     0,     0,   493,   494,
     495,     0,   185,   186,     0,  1055,     0,     0,     0,  1501,
       0,  1253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3491,  3492,  3470,     0,     0,     0,     0,   168,     0,     0,
       0,     0,     0,    66,     0,  3501,     0,     0,     0,   169,
       0,     0,     0,     0,    71,     0,    71,     0,  1203,  1110,
       0,     0,     0,     0,     0,     0,  1830,  1123,     0,     0,
    1203,     0,     0,     0,  1841,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1255,  1186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2947,  1341,
       0,  1341,     0,     0,  2947,  2947,     0,  2947,  2947,  2947,
    2947,  1341,  1341,     0,     0,     0,  2947,     0,  1341,  1341,
    1341,  1341,     0,     0,     0,  1502,     0,   496,     0,     0,
     497,  1503,  1504,  1505,     0,  3320,     0,  1875,  1186,     0,
      71,     0,     0,  1882,  1884,     0,     0,     0,     0,     0,
       0,     0,     0,  1506,     0,     0,     0,    62,     0,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2071,
       0,     0,     0,     0,  1904,     0,  2217,  2948,     0,     0,
       0,   280,     0,  2948,  2948,     0,  2948,  2948,  2948,  2948,
     281,   282,     0,     0,     0,  2948,   283,   284,   285,    39,
       0,     0,  1932,     0,     0,     0,  3209,     0,  2713,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,  2260,
       0,  1966,  1255,     0,     0,     0,     0,     0,     0,     0,
    2947,     0,     0,  2947,  2947,  2947,  2947,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
    1871,     0,     0,     0,     0,   172,     0,     0,  1507,  3203,
       0,  1508,     0,     0,   499,     0,     0,     0,   500,  1509,
       0,  1078,     0,     0,     0,     0,     0,     0,     0,  2016,
       0,     0,     0,     0,   283,  1319,  1320,    39,     0,   168,
     173,     0,     0,     0,   286,     0,     0,     0,  1321,  1322,
       0,   169,     0,  1510,   501,   580,     0,  1341,     0,  2948,
       0,     0,  2948,  2948,  2948,  2948,     0,     0,     0,     0,
       0,  2947,     0,     0,   174,     0,     0,     0,   170,     0,
    2947,     0,   502,     0,     0,     0,   175,     0,  1511,     0,
       0,     0,     0,     0,     0,     0,     0,  1347,     0,   503,
       0,     0,     0,     0,     0,     0,     0,  1512,  1513,     0,
       0,  2051,     0,     0,     0,     0,     0,     0,  1514,     0,
       0,     0,   176,  1515,     0,     0,     0,     0,     0,     0,
       0,     0,  2932,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,   178,     0,     0,     0,     0,
    2948,     0,     0,     0,     0,     0,     0,     0,   179,  2948,
       0,     0,  1516,     0,     0,     0,     0,     0,     0,    62,
       0,   171,     0,     0,     0,  1341,     0,     0,     0,     0,
     504,     0,     0,     0,  1341,     0,     0,  1341,  1341,  1341,
    1341,     0,     0,     0,  1517,     0,     0,     0,     0,  1341,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,  2208,     0,  1341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3380,     0,     0,     0,     0,   505,     0,     0,     0,
     182,  1203,     0,     0,     0,     0,     0,  1139,     0,     0,
    2566,  2567,     0,     0,     0,     0,     0,   172,     0,     0,
       0,  2576,   287,   162,     0,     0,     0,     0,  3398,     0,
       0,     0,  2257,     0,  1186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,     0,  2588,  2589,  2590,  2591,
    2592,  2593,   173,   184,     0,     0,  2598,  2599,  2600,  2601,
       0,     0,     0,  2603,     0,     0,     0,     0,     0,     0,
       0,  1203,  2316,  1203,     0,     0,     0,  1046,  1253,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,     0,
    1318,     0,     0,     0,   283,  1319,  1320,    39,     0,     0,
       0,     0,  2362,     0,     0,     0,   288,   138,  1321,  1322,
       0,   289,     0,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,     0,   185,   186,   291,
       0,  3380,     0,     0,     0,  2655,  2656,     0,     0,   177,
       0,     0,  2660,  2661,   292,   139,     0,   293,     0,     0,
     294,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     179,     0,     0, -1971,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1971, -1971,
   -1971,     0,  1323, -1971,     0, -1971, -1971,     0,   663,   296,
       0,  1324,     0,   180,   142,     0,     0,     0,     0,     0,
       0,   297,     0,  1341,     0,     0,   143,     0,     0,     0,
       0,     0,   298,     0,     0,     0,     0,   144,   181,     0,
       0,     0,  2933,     0,     0,  2934,     0,     0,     0,     0,
       0,  1203,     0,   145,     0,  1203,     0,     0,  2935,   280,
       0,     0,   299,   146,  1203,     0,     0,     0,   281,   282,
   -1971,     0,     0,     0,   283,   284,   285,    39,   147,     0,
    1341,     0,   194,     0,     0,     0,     0,     0,     0,  1203,
       0,     0,   167,     0,  1341,     0,  1341,  2937, -1971,  1255,
       0,  2835,  2836,     0,     0,     0,   183,  1341,  2549,  2938,
    2843,     0,  2552,   300,     0,   184,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   301,   302,  1139,     0,     0,
       0,     0,     0,   303,     0,     0,     0,     0,  2575,     0,
     149,     0,     0, -1971,   304,     0,     0,     0,  2878,  2879,
    2939,     0,     0,     0,     0,   150,     0,     0,  1341,     0,
       0,     0,   151,     0,     0,   152,     0,   168,     0,     0,
       0, -1971,   286, -1971,     0,  2899,     0,  2901,     0,   169,
       0,     0,     0,     0,     0,     0,   153,     0,     0,  2940,
     154,     0,     0,     0,     0,     0,     0,     0, -1971,   185,
     186,  2941,     0,     0,     0, -1971,   170, -1971,     0,   155,
       0,     0,     0,  2942,  2943,     0,     0,     0, -1971,     0,
       0,  2944,     0, -1971,  2945,     0,     0,   156,     0,     0,
       0, -1971,   304,     0,     0, -1971,     0,     0,  2972,  2973,
       0, -1971,  2974,  2975,     0, -1971, -1971, -1971, -1971,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1341,     0,
   -1971,  2653,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1971,     0,     0, -1971,
       0, -1971,     0,     0,     0,     0,     0,     0, -1971,  1341,
       0,     0,     0,     0,     0,     0,     0,    62,     0,   171,
       0, -1971,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1971,     0,     0,     0,  1341,  1341,  1341,  1341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1324, -1971, -1971,  1203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1971,     0,     0,
       0,     0,     0,     0,     0, -1971,     0,     0,     0, -1971,
       0,     0,  1325,     0,     0,  1326,     0, -1971, -1971, -1971,
    1341,  1341,     0,     0,     0,     0,     0,     0,  1327,  1341,
    1341,     0,  1341,     0,     0,  1341,     0,  1341,     0,     0,
       0,  1341,     0,     0,     0,   172,     0,     0,     0,     0,
     287,     0,     0,     0,  1203,     0,     0,  1078,  1078,  1078,
       0,  1078,  1078,  1078,  1078,  1078,  1078,  1328,  3101,     0,
    1078,     0,  3106,     0,     0,     0,     0,     0,     0,  1329,
     173,     0,     0,     0, -1971,   194,     0,     0,     0,  1203,
       0,  3114,     0,     0,     0, -1971,     0,     0,     0,     0,
       0,     0,     0,     0,  2868,     0,  1072,     0,  2872,     0,
       0,  3126,     0,     0,   174,     0,     0,     0,     0,     0,
    1330,     0,  2884,     0,     0,     0,   175,   194,     0,     0,
       0,     0,     0,     0, -1971,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,   289,
       0,   290,     0,  1331,  2904,  2906,     0,     0,     0,  1332,
       0,     0,   176,     0,     0,     0,     0,   291,  1333,  1334,
       0,  1335,     0,     0,     0,     0,     0,   177,     0,     0,
       0,     0,   292,  1336,  1337,   293,     0,     0,   294,     0,
       0,  1338,     0,     0,  1339, -1971,  1253,   295,   179,     0,
    2970,     0,   304,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1971,     0,     0,     0,     0,  1434,   296,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,   139,   297,
       0,     0,   483,   484,   485,     0,     0,  1341,  1341,     0,
     298,  1341,     0,     0,     0,     0,   181,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0, -1971,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
     299, -1971, -1971, -1971, -1971, -1971, -1971, -1971,     0, -1971,
   -1971,     0,  3029,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,  3043,     0, -1971,     0,     0,   143,
       0,     0,  1341,     0,     0,  1341,     0,     0,  1341,     0,
     144,  1341,     0,  1341,   183,     0,     0,     0,     0,     0,
       0,   300,     0,   184,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   301,   302,     0,   146,     0,     0,  3278,
       0,   303,  3281,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   304,     0,     0,  1203,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   194,     0,     0,
    2285,  2286,  2287,  2288,  2289,  2290,  1341,     0,     0,   493,
     494,   495,     0,  1203,   280,     0,     0,     0,  1186,     0,
       0,   148,     0,   281,   282,     0,     0,  1255,     0,   283,
     284,   285,    39,     0,     0,     0,     0,   185,   186,     0,
       0,     0,     0,   149,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,   151,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1341,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,   154,     0,     0,  1341,  2291,  1341,     0,
       0,     0,     0,     0,  1341,  1341,     0,  1341,  1341,  1341,
    1341,     0,   155,     0,     0,     0,  1341,  3369,  1341,     0,
       0,     0,   168,     0,     0,     0,  1186,   286,     0,     0,
     156,     0,     0,     0,   169,  1341,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
       0,   497,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,     0,     0,     0,     0,     0,  3399,  3400,
       0,  3402,     0,  3404,  3405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3029,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3347,     0,     0,     0,     0,     0,   280,     0,  1253,
       0,     0,     0,     0,     0,     0,   281,   282,     0,     0,
       0,     0,   283,   284,   285,    39,  1341,     0,     0,     0,
    1341,     0,     0,  1341,  1341,  1341,  1341,     0,     0,     0,
     167,  3454,     0,  3455,     0,     0,     0,     0,     0,     0,
       0,  1203,    62,     0,   171,     0,     0,     0,  3348,  1341,
       0,     0,     0,  1341,     0,     0,     0,     0,     0,  1203,
     498,     0,     0,     0,     0,     0,     0,  3467,     0,     0,
       0,     0,  3349,     0,     0,   499,     0,     0,     0,   500,
       0,  3350,     0,     0,     0,     0,  3476,  3477,  1186,     0,
    3478,     0,     0,  3480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,     0,     0,     0,     0,
     286,  1341,     0,     0,     0,   501,   280,   169,     0,  3351,
    1341,     0,  2292,     0,     0,   281,   282,  3352,     0,     0,
       0,   283,   284,   285,    39,  2293,     0,     0,     0,     0,
     172,     0,     0,   502,   170,   287,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,  3029,  1341,     0,     0,     0,
    3330,     0,  3332,     0,     0,   173,     0,     0,     0,   615,
     470,   471,   472,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,  2294,     0,     0,
       0,     0,  1203,  2295,     0,     0,     0,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,     0,  3353,     0,
    1255,   175,     0,  1253,   168,     0,   486,   194,     0,   286,
       0,     0,     0,     0,     0,    62,   169,   171,     0,   288,
       0,   504,  2296,     0,   289,     0,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,     0,     0,
       0,     0,   291,   170,     0,  2297,     0,     0,     0,     0,
       0,     0,   177,     0,     0,  2298,  2299,   292,     0,     0,
     293,  2300,     0,   294,     0,     0,     0,     0,     0,     0,
       0,  2301,   295,   179,     0,  1496,  1496,  1496,  1496,  1496,
    1496,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,  2302,     0,     0,  2303,  2304,     0,     0,
       0,  2305,     0,   487,   488,   489,   490,   491,   492,     0,
       0,     0,   296,   172,     0,     0,   180,     0,   287,     0,
       0,   493,   494,   495,   297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,   298,   171,  2512,     0,     0,
       0,   181,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2306,     0,
       0,     0,     0,     0,     0,   299,     0,  3354,     0,  2307,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,   288,     0,     0,     0,   300,   289,   184,   290,
       0,     0,     0,     0,  1255,     0,     0,     0,   301,   302,
     176,     0,   172,     0,     0,   291,   303,   287,     0,     0,
       0,     0,     0,     0,     0,   177,     0,   304,     0,     0,
     292,     0,     0,   293,     0,     0,   294,     0,     0,     0,
     496,     0,     0,   497,     0,   295,   179,   173,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   185,   186,  2888,   296,     0,     0,     0,   180,
       0,     0,     0,   175,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   298,     0,
       0,   288,     0,     0,   181,     0,   289,     0,   290,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,     0,   291,     0,     0,     0,   299,     0,
       0,     0,     0,     0,   177,     0,     0,     0,     0,   292,
       0,     0,   293,     0,     0,   294,     0,     0,     0,     0,
       0,     0,   498,     0,   295,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,   500,   183,     0,     0,     0,     0,     0,     0,   300,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,   302,     0,   296,     0,     0,     0,   180,   303,
       0,     0,     0,     0,     0,     0,   297,   501,     0,     0,
     304,     0,     0,     0,     0,     0,     0,   298,     0,     0,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     2,     0,   502,     0,     0,     0,     0,
       0,     0,     0,     0,   700,   701,   702,   299,     0,     0,
       0,     0,   503,   703,     0,     0,   704,     0,     0,     0,
       0,     0,     0,   705,   706,   185,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,   300,     0,
     184,     0,     0,     0,     0,     0,     0,     0,   707,   708,
     301,   302,     0,   709,     0,     0,     0,     0,   303,     0,
       0,     0,     0,   710,   711,     0,   712,     0,     0,   304,
       0,     0,     0,   504,     0,     0,     0,     0,     0,     0,
     713,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   714,     0,     0,
     715,   716,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   717,     0,   718,   719,   720,     0,
       0,     0,     0,     0,   185,   186,   721,   722,     0,   723,
     724,   725,     0,     0,     0,     0,     0,   726,     0,   505,
     727,     0,   728,   729,   730,     0,     0,     0,     0,     0,
     731,     0,   732,   733,     0,   734,     0,   735,   736,     0,
       0,   737,     0,     0,   738,   739,   740,   741,   742,   743,
       0,     0,     0,   744,   745,   746,     0,   747,     0,     0,
       0,   748,     0,   749,   750,     0,     0,     0,     0,   751,
       0,     0,   752,     0,     0,   753,     0,   754,     0,   755,
       0,   756,     0,     0,     0,   757,   758,     0,   759,   760,
     761,     0,     0,   762,     0,   763,   764,     0,   765,     0,
       0,     0,     0,     0,     0,     0,   766,   767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   768,
       0,     0,   769,   770,     0,     0,   771,   772,     0,     0,
     773,   774,     0,     0,     0,     0,     0,     0,   775,   776,
     777,     0,   778,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   779,   780,   781,     0,   782,     0,     0,     0,
     783,   784,     0,     0,     0,   785,     0,     0,     0,     0,
       0,     0,     0,   786,     0,     0,     0,     0,     0,     0,
       0,   787,   788,   789,     0,     0,     0,     0,     0,   790,
     791,     0,     0,     0,     0,     0,     0,   792,     0,     0,
     793,     0,     0,     0,   794,   795,     0,     0,     0,     0,
       0,  2550,   470,   471,   472,   796,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,   797,     0,     0,     0,     0,     0,     0,     0,
     798,     0,     0,     0,     0,     0,   799,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   800,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   801,
       0,     0,     0,     0,     0,   802,     0,   803,   804,     0,
       0,     0,     0,     0,     0,   805,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
     471,   472,     0,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
       0,     0,     0,     0,   806,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   807,     0,     0,     0,     0,
       0,     0,   808,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,     0,     0,     0,     0,   809,   810,     0,     0,     0,
     811,     0,     0,   493,   494,   495,     0,     0,     0,     0,
       0,     0,   812,     0,     0,     0,     0,     0,   813,   814,
     815,   816,     0,     0,     0,   817,     0,     0,     0,   818,
       0,     0,     0,     0,     0,     0,   819,   820,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   821,     0,   822,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     823,     0,   824,     0,     0,   825,     0,     0,     0,     0,
       0,   826,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   495,     0,     0,     0,     0,   827,     0,     0,
     828,     0,     0,  2417,     0,   829,     0,     0,   830,   831,
       0,     0,  1316,  1317,  1318,     0,     0,     0,   283,  1319,
    1320,    39,     0,   832,     0,     0,     0,     0,     0,     0,
     833,     0,  1321,  1322,     0,     0,     0,     0,     0,     0,
       0,     0,   496,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,   834,   835,   836,   837,   838,   839,   840,
       0,     0,   841,     0,   842,     0,   843,   470,   471,   472,
       0,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,     0,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,     0,   486,     0,     0,  1323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   496,
       0,     0,   497,     0,   470,   471,   472,   486,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
     486,     0,     0,   500,     0,   470,   471,   472,     0,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,     0,     0,     0,     0,
     487,   488,   489,   490,   491,   492,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,     0,     0,   493,   494,
     495,   486,     0,     0,   487,   488,   489,   490,   491,   492,
       0,  1139,     0,     0,     0,     0,     0,   502,     0,     0,
       0,   498,   493,   494,   495,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,   499,     0,     0,     0,
     500,   600,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,     0,     0,
       0,     0,     0,   470,   471,   472,   501,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2418,   504,   493,   494,   495,   486,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   496,     0,     0,
     497,     0,     0,   470,   471,   472,     0,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,   496,     0,     0,   497,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,   496,     0,     0,   497,     0,     0,
       0,     0,     0,     0,     0,  1324,   487,   488,   489,   490,
     491,   492,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   494,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1325,     0,     0,  2419,
       0,     0,     0,     0,     0,   496,     0,     0,   497,   498,
       0,  2420,  1327,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,   499,     0,     0,     0,   500,   614,
       0,     0,     0,   498,     0,     0,   487,   488,   489,   490,
     491,   492,     0,     0,     0,     0,     0,     0,   499,     0,
       0,  1328,   500,   624,   493,   494,   495,     0,     0,     0,
       0,     0,     0,  1329,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,     0,
       0,   499,   502,     0,     0,   500,   996,     0,     0,     0,
       0,     0,     0,     0,  1330,     0,     0,     0,     0,   503,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,   496,     0,     0,   497,   498,     0,     0,
       0,   501,     0,   503,     0,     0,     0,  1331,     0,     0,
       0,     0,   499,  1332,     0,     0,   500,  1002,     0,     0,
       0,     0,  1333,  1334,     0,  1335,     0,     0,     0,   502,
       0,     0,     0,     0,     0,     0,     0,  1336,  1337,     0,
       0,     0,     0,     0,     0,  1338,   503,     0,  1339,     0,
       0,     0,   501,     0,     0,     0,   304,     0,     0,     0,
     504,     0,     0,   496,     0,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,   504,     0,     0,
     499,     0,     0,     0,   500,  1003,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,   502,     0,
     499,     0,     0,     0,   500,  1004,     0,     0,     0,     0,
       0,     0,   470,   471,   472,   503,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,   470,   471,   472,   505,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
       0,     0,     0,     0,     0,   470,   471,   472,   502,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,   503,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   471,
     472,   486,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,     0,
     470,   471,   472,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,     0,     0,     0,   486,   487,   488,   489,   490,   491,
     492,     0,   505,     0,     0,     0,   504,     0,     0,     0,
       0,     0,     0,   493,   494,   495,   486,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   495,     0,     0,     0,   487,   488,
     489,   490,   491,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   495,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   495,     0,   487,   488,   489,   490,   491,   492,     0,
    1155,  1156,  1157,  1158,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   496,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,     0,   471,   472,     0,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,   496,     0,     0,   497,     0,     0,     0,     0,   472,
       0,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,     0,   496,  2417,     0,   497,   486,
       0,     0,     0,     0,     0,  1316,  1317,  1318,     0,     0,
       0,   283,  1319,  1320,    39,     0,     0,     0,     0,     0,
       0,     0,     0,   486,     0,  1321,  1322,     0,     0,     0,
       0,     0,  1159,     0,     0,     0,     0,     0,   496,     0,
    1160,   497,     0,     0,     0,     0,     0,     0,     0,  1161,
       0,     0,  1162,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     0,   497,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,   500,  1005,     0,     0,     0,     0,     0,
       0,     0,     0,   498,     0,  1163,   487,   488,   489,   490,
     491,   492,  1164,     0,     0,     0,     0,     0,   499,  1323,
       0,     0,   500,     0,   493,   494,   495,   498,     0,   501,
     487,   488,   489,   490,   491,   492,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,   500,     0,   493,   494,
     495,     0,     0,     0,     0,     0,     0,   502,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1165,
     498,  1007,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,   501,     0,     0,   499,   502,     0,     0,   500,
       0,     0,   498,  1166,     0,  1008,     0,     0,     0,     0,
    1167,     0,  1168,   503,     0,     0,     0,   499,     0,     0,
     502,   500,  1169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,     0,   503,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,  1011,     0,
    1170,     0,     0,     0,  1139,     0,     0,   501,  1171,     0,
       0,     0,     0,   502,     0,   504,     0,     0,     0,     0,
       0,     0,     0,   496,   486,     0,   497,     0,     0,     0,
     503,     0,     0,     0,     0,   502,     0,     0,     0,     0,
       0,     0,     0,     0,   504,  1172,     0,   496,     0,     0,
     497,     0,   503,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,   504,  1173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1174,  2418,     0,     0,
     505,   504,     0,     0,     0,     0,     0,  1175,     0,     0,
       0,   487,   488,   489,   490,   491,   492,     0,     0,     0,
       0,     0,     0,   504,   505,     0,     0,     0,     0,   493,
     494,   495,     0,     0,     0,   498,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
     499,     0,     0,     0,   500,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,   499,     0,     0,   486,   500,     0,
       0,     0,   487,   488,   489,   490,   491,   492,     0,   505,
     501,     0,     0,     0,     0,     0,     0,     0,  1324,     0,
     493,   494,   495,     0,  1176,  1177,  1178,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,  1179,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1325,
       0,     0,  2419,     0,     0,   503,     0,     0,     0,     0,
       0,     0,   502,     0,  2420,  1327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,     0,  1180,     0,     0,     0,     0,     0,   496,     0,
       0,   497,  1720,     0,   487,   488,   489,   490,   491,   492,
       0,     0,     0,     0,  1328,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   495,     0,  1329,     0,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,     0,   504,     0,     0,     0,
    1181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1182,  1330,   486,   496,
     504,     0,   497,     0,     0,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,     0,
    1331,     0,     0,     0,     0,     0,  1332,     0,     0,     0,
       0,     0,   505,     0,   486,  1333,  1334,     0,  1335,     0,
     498,     0,     0,     0,   486,     0,     0,     0,     0,     0,
    1336,  1337,     0,     0,     0,   499,   505,     0,  1338,   500,
       0,  1339,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,   497,   487,   488,   489,   490,   491,
     492,     0,     0,     0,     0,   501,     0,     0,     0,     0,
    1316,  1317,  1318,   493,   494,   495,   283,  1319,  1320,    39,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
    1321,  1322,     0,   502,     0,     0,   499,     0,     0,     0,
     500,   487,   488,   489,   490,   491,   492,     0,     0,     0,
     503,   487,   488,   489,   490,   491,   492,     0,     0,   493,
     494,   495,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   495,     0,     0,     0,     0,   501,     0,     0,     0,
       0,     0,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,     0,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,   498,  1323,     0,     0,     0,     0,   486,
       0,   503,     0,     0,     0,     0,     0,   486,   499,     0,
       0,   504,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1316,  1317,  1318,     0,     0,     0,   283,  1319,
    1320,    39,   496,     0,     0,   497,     0,     0,     0,     0,
       0,     0,  1321,  1322,     0,     0,     0,     0,   501,     0,
       0,  1316,  1317,  1318,     0,     0,     0,   283,  1319,  1320,
      39,  1006,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1321,  1322,     0,     0,     0,   502,   505,   496,     0,
       0,   497,   504,     0,     0,     0,     0,     0,   496,     0,
       0,   497,     0,   503,     0,     0,   487,   488,   489,   490,
     491,   492,     0,     0,   487,   488,   489,   490,   491,   492,
       0,     0,     0,     0,   493,   494,   495,     0,     0,  1139,
       0,     0,   493,   494,   495,     0,  1323,     0,     0,  1316,
    1317,  1318,     0,     0,     0,   283,  1319,  1320,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,  1321,
    1322,     0,     0,     0,   498,  1323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,   500,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1316,  1317,  1318,
       0,     0,     0,   283,  1319,  1320,    39,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,  1321,  1322,   501,
     498,     0,     0,     0,     0,   499,     0,     0,     0,   500,
       0,     0,  2418,     0,     0,   499,     0,     0,     0,   500,
       0,     0,     0,  1323,     0,     0,     0,   502,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1139,     0,   496,   503,   501,   497,     0,   206,     0,
       0,   496,     0,     0,   497,   501,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,     0,     0,  2930,  2931,
    1139,     0,     0,   502,   283,  1319,  1320,    39,     0,     0,
       0,  1323,     0,   502,     0,     0,     0,     0,  1321,  1322,
     503,     0,     0,     0,     0,     0,  1316,  1317,  1318,     0,
     503,     0,   283,  1319,  1320,    39,     0,     0,     0,     0,
       0,     0,     0,  1324,     0,     0,  1321,  1322,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,  1325,     0,     0,  2419,  1139,     0,
       0,     0,     0,   209,   210,     0,     0,     0,     0,  2420,
    1327,     0,     0,   211,     0,   498,     0,     0,     0,     0,
       0,   504,  2932,   498,     0,     0,     0,     0,     0,     0,
     499,   504,     0,     0,   500,     0,     0,     0,   499,  2930,
    2931,   505,   500,     0,     0,   283,  1319,  1320,    39,  1328,
    1323,     0,     0,     0,     0,     0,  1139,     0,     0,  1321,
    1322,  1329,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,     0,     0,     0,   501,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,     0,  1324,     0,   505,   502,     0,
       0,     0,  1330,     0,     0,     0,   502,     0,     0,     0,
       0,  2930,  2931,     0,     0,   503,     0,   283,  1319,  1320,
      39,     0,     0,   503,  1324,     0,  1325,     0,     0,  1326,
       0,  1321,  1322,     0,     0,  1331,     0,     0,     0,     0,
       0,  1332,  1327,  2932,     0,     0,     0,  1139,     0,     0,
    1333,  1334,     0,  1335,     0,  1325,     0,     0,  1326,     0,
       0,     0,     0,     0,     0,  1336,  1337,     0,     0,  1720,
       0,  1327,     0,  1338,     0,  1139,  1339,     0,     0,     0,
       0,  1328,     0,   212,   304,     0,     0,     0,     0,     0,
       0,     0,     0,  1329,     0,     0,   504,     0,     0,     0,
       0,     0,  1324,     0,   504,     0,     0,     0,     0,  2253,
    1328,     0,     0,     0,     0,  2932,     0,     0,     0,     0,
       0,   213,  1329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1325,  1330,     0,  1326,     0,     0,     0,
     214,   215,   216,   217,     0,     0,     0,     0,     0,  1327,
       0,  2285,  2286,  2287,  2288,  2289,  2290,     0,   218,     0,
    1324,     0,   505,  1330,     0,     0,     0,  1331,  1139,     0,
     505,     0,     0,  1332,     0,     0,     0,     0,     0,     0,
     219,     0,  1333,  1334,     0,  1335,     0,  3377,  1328,     0,
       0,  1325,   220,     0,  1326,     0,  1331,  1336,  1337,     0,
    1329,     0,  1332,   221,     0,  1338,     0,  1327,  1339,     0,
       0,  1333,  1334,     0,  1335,     0,   304,     0,     0,   222,
       0,     0,     0,     0,     0,     0,  1336,  1337,     0,   223,
       0,     0,     0,     0,  1338,     0,     0,  1339,     0,     0,
    1139,  1330,     0,     0,   224,   304,  1328,     0,  2291,     0,
       0,  1324,     0,     0,     0,     0,     0,     0,  1329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1331,     0,     0,     0,     0,  2050,
    1332,     0,  2933,     0,   225,  2934,     0,     0,     0,  1333,
    1334,     0,  1335,     0,     0,     0,     0,     0,  2935,  1330,
       0,     0,     0,     0,  1336,  1337,   226,     0,     0,     0,
    1325,     0,  1338,  1326,     0,  1339,     0,     0,     0,     0,
       0,   227,     0,   304,     0,     0,  1327,     0,   228,     0,
       0,   229,  1331,     0,     0,     0,  2936,  2937,  1332,     0,
       0,     0,     0,     0,     0,     0,     0,  1333,  1334,  2938,
    1335,     0,   230,     0,     0,     0,   231,     0,     0,     0,
       0,     0,  1336,  1337,     0,  1328,     0,     0,     0,     0,
    1338,     0,  1324,  1339,     0,   232,     0,  1329,     0,     0,
       0,   304,     0,     0,     0,     0,     0,     0,     0,     0,
    2939,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2933,     0,     0,  2934,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1330,  2935,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2940,
       0,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       0,  2941,     0,     0,  1324,     0,  1720,     0,     0,     0,
       0,  1331,     0,  2942,  2943,     0,     0,  1332,  2937,     0,
       0,  2944,     0,     0,  2945,     0,  1333,  1334,     0,  1335,
    2938,     0,   304,     0,     0,  2933,     0,     0,  2934,     0,
       0,  1336,  1337,  2292,     0,     0,     0,     0,     0,  1338,
       0,  2935,  1339,     0,     0,     0,  2293,     0,     0,     0,
     304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2939,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2937,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2938,     0,     0,     0,     0,     0,     0,     0,
    2940,     0,     0,     0,     0,     0,     0,     0,  2294,     0,
       0,     0,  2941,     0,  2295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2942,  2943,     0,     0,     0,     0,
       0,     0,  2944,  2939,     0,  2945,     0,     0,     0,     0,
       0,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2940,     0,     0,     0,  2297,     0,     0,     0,
       0,     0,     0,     0,  2941,     0,  2298,  2299,     0,     0,
       0,     0,  2300,     0,     0,     0,  2942,  2943,     0,     0,
       0,     0,  2301,     0,  2944,     0,     0,  2945,     0,     0,
       0,     0,     0,     0,     0,   304,     0,     0,     0,     0,
       0,     0,     0,     0,  2302,     0,     0,  2303,  2304,     0,
       0,     0,  2305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2307
};

static const short yycheck[] =
{
       3,     4,     5,     6,   178,  1076,     9,    10,   404,   197,
     112,   671,  1154,  1196,  1489,    53,  1316,  1317,  1191,    62,
    1404,   813,   557,  1656,  1019,  1397,   254,  1022,  1169,  2048,
    1165,  1166,  2085,  1168,  2087,  1170,  1171,   612,   797,   268,
     269,  1620,  1621,   583,    47,  2100,   275,     5,  2102,  2240,
      48,  1150,  1787,  1151,    27,    27,   180,    60,    20,    62,
      98,   654,  2396,   772,   133,    27,  1781,   270,   271,     5,
      73,   707,   708,  2639,  2640,  2641,   178,    80,  1790,    77,
       5,  1842,    85,    27,    25,    88,    27,  1720,    51,    92,
      93,   602,    27,  2284,   605,   197,    26,    27,     5,     5,
       5,     5,  1351,     5,  1353,  1969,   148,  2171,   111,   745,
      27,    27,   748,   736,  1729,  1730,  1731,  1732,  2359,     5,
    2642,   119,   758,    36,   127,   123,   762,   130,     5,   132,
     766,    25,    26,    27,   137,     8,   157,   773,  1280,    27,
     733,    24,   778,    26,   780,    25,   815,    27,   272,  1247,
     786,   744,   276,   789,   278,   329,   280,   281,   282,     5,
     796,    27,    25,  1261,    27,   289,    53,   803,    30,   293,
     294,   240,    34,   120,   810,    27,   245,   246,     5,    19,
    1251,    43,   145,   146,    27,   821,    26,  1429,     5,   825,
      24,    25,    26,   829,    19,   220,   199,   118,     6,   835,
       5,    26,   838,   139,   140,   737,   799,    19,     5,   802,
     833,    98,    24,    25,    26,    25,     6,    27,   811,    20,
      24,    25,    26,    27,    25,  1722,    27,   329,    20,   761,
    1447,    33,   334,    25,   803,    27,   234,  2096,  2097,  2098,
      33,     6,  2101,    26,  2411,   248,  2413,     9,    66,     5,
      12,    13,    14,    15,    16,    17,     5,   260,    24,    25,
      26,    27,     5,   266,   267,   268,   269,   270,   271,    40,
      41,   133,   275,     5,   207,   807,     9,    27,  2725,    12,
      13,    14,    15,    16,    17,   817,   416,    25,   820,    27,
      27,     5,   824,     5,   200,   194,   330,    23,   830,   126,
     832,   128,    25,   130,    27,  2164,    24,    25,    26,    27,
      25,   402,    27,    24,    25,    26,    27,   247,   397,   322,
     323,   445,   207,    27,   448,   143,   144,  2346,   331,   118,
     333,    24,    25,    26,    27,  2280,   462,    27,   566,     5,
     528,   465,   466,   467,   468,  1444,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   592,   362,  2419,     5,     5,  2023,    36,
      23,  2026,     5,   497,   498,    26,    27,  1981,   502,  1552,
     504,    27,    30,   612,   247,     5,    34,     5,     5,     5,
     446,  1150,  2326,   517,   518,   519,   520,  1769,    25,   529,
      27,   525,    25,   513,    27,     5,  1790,   103,   104,   105,
     106,   107,  2173,   411,   412,   413,     5,  1488,     5,   485,
     594,   220,     5,   330,     5,    19,   528,   397,   330,     5,
       5,   293,    26,   120,     5,   485,   513,   247,  1935,     5,
       5,     5,   642,   247,   246,   247,     5,   112,   113,   220,
       5,   513,   550,     5,   247,    27,     5,    26,    27,   432,
       5,  1936,  2077,   111,   664,   716,   977,   416,   448,     5,
     118,  2330,    18,    19,    20,    21,    22,   142,   143,   144,
       5,  2340,   670,   301,     5,    18,    19,    20,    21,    22,
     675,     5,   594,     5,    13,    27,     5,   247,   591,   352,
     480,     5,   629,   424,   231,     0,     5,     5,   638,   247,
     461,   364,     5,   516,     5,     5,   164,   165,  1154,    29,
     558,   559,     5,     5,   247,   651,     5,     5,   654,   247,
       5,   782,     5,  1202,     5,     5,   247,     5,     5,  1176,
    1177,     5,   669,     5,   729,    64,  1215,   640,   551,   547,
     553,   413,   631,   664,   247,     5,  1088,   648,   561,     5,
       5,   790,   672,     5,   407,   291,    27,     5,   670,     5,
       5,     5,    28,     5,     5,   578,  2435,   580,     5,     5,
     529,     5,  2638,  2639,  2640,  2641,   611,   621,   591,   592,
     562,   689,   595,  2612,   391,   672,   247,  2176,   302,   461,
     327,   247,  1819,   402,  1821,   808,   809,   339,   448,   612,
     672,   315,   678,   195,   196,   305,  2703,   451,  2705,   485,
     247,  2708,  2675,  1865,   554,   208,  2571,   648,   678,   517,
     492,   402,   208,   485,   837,   424,    27,   840,   291,  3086,
     448,   614,  1278,  1279,  1280,   442,   579,   451,   595,   691,
     692,   693,   694,   695,  3176,   711,   592,   293,   448,   521,
    2714,   631,   525,   122,  1196,   448,   428,   429,   567,  1204,
     407,   558,   123,  2864,  1206,   247,  1208,   607,   247,  2538,
    2614,  2615,   525,   448,  2317,  1444,   448,  2928,   431,   638,
     446,   441,  2883,   419,   579,   428,   429,   700,   701,   702,
     703,   704,   705,   706,   609,   609,   709,   710,   711,  2364,
    1279,   714,   416,   716,   621,   678,   719,   407,   721,   621,
     606,   483,   599,   441,  2328,  2780,   642,   730,  2969,   642,
    1871,  1391,   481,   606,   669,  2788,   448,  2790,   741,   742,
     451,    23,  1451,   679,  2608,   670,   719,   719,   751,  2484,
     483,  2466,   669,   599,   757,  2810,   714,   719,  1298,  1858,
     763,   764,   765,   669,  2148,  2624,   769,   481,  2152,   772,
     664,   774,   775,  2837,  2486,   719,   424,  2841,   719,   782,
     339,  1450,   785,    31,   664,   423,   603,   790,   791,   672,
     793,   721,    10,  1462,   797,   441,  1307,   800,   603,  1310,
    1311,  2050,   642,   806,   606,   808,   809,  3141,   495,   730,
     813,   814,   815,   606,   525,   481,   819,   642,   485,   822,
    2987,  3155,   540,  1921,   827,   529,   597,  3393,   638,   292,
     448,   834,   448,   836,   837,   525,   839,   840,   672,   842,
     843,   545,   481,   670,   509,   512,   513,   609,   481,   220,
      25,   678,    27,   568,   448,    30,   492,   675,   485,   630,
     672,   481,   485,   664,   481,  2114,  2115,  2009,   672,   731,
     508,   519,   664,   448,  2930,  2931,   609,   448,  2934,   330,
     603,   481,   448,   448,   448,  1009,   524,   669,  1012,    27,
     448,   629,   481,   448,   481,  1019,   448,  1021,  1022,   448,
     481,  1297,   351,   448,   893,  1542,   672,   574,   595,   491,
    1905,   302,   448,   675,  3001,    27,  2775,    25,  2777,    27,
    1452,  1453,  1454,   448,   315,   448,   411,   448,   566,   594,
    2983,   448,  2985,  2986,   448,   481,   448,  1469,   399,   448,
     636,  2520,   675,   946,   448,  3136,   407,   408,   481,   448,
     448,   402,    20,  3287,   672,   448,   599,   448,   448,    27,
    3013,   672,   610,   725,   726,   448,   448,   605,   966,   448,
     448,   432,   637,   448,   435,   448,   299,   448,   448,   672,
     448,   448,   707,   708,   448,   444,   448,   712,   713,   672,
     451,   994,   725,   726,   671,   446,   634,  1590,   448,  1574,
     725,   678,   448,   448,   382,   643,   448,   382,   467,   291,
     448,  1543,   448,   448,   448,  3069,   448,   448,    26,    27,
     745,   448,   448,   748,   448,   416,  1561,   670,   448,   754,
    1562,   402,  1030,   758,  1037,   484,  1039,   762,   397,   448,
     642,   766,   690,    26,    27,   770,   771,     5,   773,  1581,
     698,   776,   448,   778,   779,   780,  2915,   520,   417,   448,
    1592,   786,   664,    25,   789,    27,  2925,   221,   411,   223,
    1073,   796,   247,  1076,    26,    27,  1304,     5,   803,    18,
      19,    20,    21,    22,   642,   810,  2458,     0,   306,  1092,
     549,  2264,  1095,   554,   485,   558,   821,   485,   732,  1858,
     825,   485,  2486,  2954,   829,  3161,   263,   264,   265,    22,
     835,  3167,  3168,   838,  3170,  3171,  3172,  3173,   293,   642,
      25,   302,    27,  3179,   512,   642,  3145,  3181,   215,   513,
    2201,  1134,    26,    27,   315,   247,  1139,   419,   529,   247,
     513,  2638,  2639,  2640,  2641,    14,   607,  1150,  2397,  3008,
    2399,   591,  2401,   614,   545,    25,   534,    27,    25,   534,
      27,  1164,  1165,  1166,   302,  1168,   302,  1170,  1171,   575,
     621,    20,   326,  1176,  1177,   329,    30,   315,    27,   315,
      34,   389,   641,   485,  1173,  1696,   485,  1979,  1699,    43,
    2332,   232,  1181,   305,   653,   654,   591,   351,   485,  1202,
     640,   642,   661,   221,   221,   223,   223,   553,    28,    29,
    1213,  1847,  1215,   512,   513,   561,  2358,  1810,    25,   338,
      27,  1224,   642,   664,  1227,   443,   513,   445,   315,  1232,
     248,   248,   351,   642,  1903,   416,  1465,  3293,   413,   247,
    3296,  3297,  3298,  3299,   375,   640,   642,  3168,  1251,  1252,
     701,   702,   703,   642,    25,    25,    27,  1260,  3179,   677,
    1463,   712,  3286,   485,   247,   352,  3290,    25,    25,    27,
      27,  1894,   631,  1276,  1277,   574,   295,   513,   416,   133,
     416,  1813,   700,   485,  2917,   247,    25,  3340,    27,  3148,
      25,   485,    27,    20,    21,   247,   485,  1829,   455,   677,
    1303,   480,   677,  1477,  1973,  3156,  3157,   338,   326,   326,
     351,   329,   329,  1316,  1317,   485,   357,   492,   696,   697,
     351,   696,   697,  1326,  1856,  1394,   513,  1396,  3384,   416,
     484,  1863,   351,   351,   351,   485,  1339,  3393,   716,   485,
    1976,   716,   247,   430,  1347,  1574,   521,   485,   529,   485,
      19,   709,  1887,   247,   513,    24,   534,    26,   730,   567,
       5,  1893,    20,     8,   545,   484,  1569,  1570,  2994,    27,
     578,  2997,   485,  2009,  3000,  1477,  1419,   247,   485,   751,
     247,  1913,  3241,   741,   742,  2860,   405,  3274,  3275,  3276,
     409,   529,   764,   529,   485,  1398,   295,  2580,    26,  1402,
    1403,  1404,  2702,  2703,  2502,  2705,  2547,   545,  2708,   545,
     485,  1414,  1415,  1416,  1617,  1618,  1419,  1420,  1421,  1422,
    1423,  1424,   149,   150,   151,   152,   153,   154,   485,  1154,
    1433,  2604,   485,  2930,  2931,   793,  2820,  2934,   485,   293,
     247,  1444,   529,  1446,    26,  1448,  2544,  1450,  1451,   512,
     513,   121,   351,   484,    20,  1458,  1459,  1460,   545,  1462,
    1463,    27,  1465,  1466,   234,   484,   484,   484,   722,   723,
     724,  1474,   780,   423,   485,  3362,   247,  3364,  1481,  1482,
     677,   789,   485,   642,  2153,  1488,  1489,   821,  2157,   247,
     247,   825,   677,  2968,    25,   829,    27,  2166,  2995,   677,
      20,  2998,   699,   700,   485,   664,   405,    27,   247,   448,
     409,   748,   247,   672,   699,   700,   525,   393,   696,   697,
     692,   693,  2191,   532,    20,   762,  2037,   835,   404,   766,
     838,    27,  2043,  2044,   159,   160,  1539,  1540,   716,  1542,
     485,   778,  1545,  1546,    20,  3160,    26,  3162,  3163,  3164,
    3165,    27,   485,  1278,  1279,  1280,  2149,   678,   508,   413,
    2555,    24,    25,    26,  1567,   423,  1569,  1570,  2563,  2564,
    2565,  1574,   678,  1576,   524,  1578,  1579,  1580,   454,    48,
      49,    50,  3208,  3344,    53,   484,    55,    56,    19,    24,
     360,    26,   468,    24,    25,    26,   366,   367,   368,    20,
    3361,  1604,   836,    40,    41,   839,    27,   461,   842,  2202,
    2142,    40,    41,  1616,  1617,  1618,   566,   485,   388,  1688,
    1623,  1624,   665,   666,   667,   668,  2158,  2159,  2160,  2161,
     691,  1755,   295,   694,   695,  1174,  1175,   485,   492,  1178,
    1179,  1644,  1645,   485,  1647,  1648,   713,  2179,  1651,  1652,
     508,  1654,  3413,    26,  1657,   605,   994,  2098,   725,  2252,
    2101,  1864,  3159,    26,  3161,  3140,   524,   521,   485,  3430,
    3167,  3168,   485,  3170,  3171,  3172,  3173,    24,  1681,    26,
     556,    25,  3179,    27,   634,   355,   485,   754,   351,  1692,
    2326,   485,    25,   643,    27,   485,  2332,   167,   168,   169,
      25,  3001,    27,   770,   771,   375,   376,   377,   566,   776,
     485,    25,   779,    27,  2246,  1073,    24,   485,    26,  1722,
     485,  1724,  2358,   493,  1953,  1954,   496,    24,    24,    26,
      26,  1734,  1735,  1736,   504,   485,  1739,  1095,  1741,  1742,
    1743,  1744,   405,    25,   414,    27,   409,   605,   493,    52,
      25,  1754,    27,    25,   672,    27,   426,    26,    24,   504,
      26,    26,  1886,  1761,  1446,  1968,  1448,   437,   538,    25,
      25,    27,    27,  1776,   579,    24,   634,    26,  1781,   485,
     525,  1905,   485,   453,  1787,   643,   531,  1790,  2638,  2639,
    2640,  2641,   485,   463,   539,    24,  3293,    26,  2869,  3296,
    3297,  3298,  3299,   573,    25,  1808,    27,  1331,   478,  1333,
    1334,  1814,   512,   513,   694,   695,   561,  2349,   485,  2351,
     485,   484,   592,   593,   485,  3322,    18,    19,    20,    21,
      22,   119,   485,   603,   343,   344,   996,  2506,   608,   999,
    1843,  1001,  1002,  1003,  1004,  1005,   149,   150,   151,   152,
     153,   154,  2476,  2477,  1857,  1858,   526,   326,  1861,  1862,
     329,  1864,   331,   485,   167,   168,   169,   485,  2379,   701,
     702,  2382,  2541,  2384,  2385,    26,  1879,   647,  2873,   701,
     702,   423,   351,  2930,  2931,   555,   475,  3384,    26,   513,
     485,    26,   361,    26,    26,   565,  3393,    26,  1901,    26,
    1903,    26,   116,   131,   132,   193,   134,   135,   136,   679,
     672,   448,   418,   382,    26,   448,   586,  3090,   672,     5,
     590,   485,  1925,   485,  1927,  1928,  3099,  1930,   481,   448,
     485,  1934,  1935,  1936,   448,   448,   405,   217,   448,   525,
     409,   448,   485,  3116,   448,   423,   678,    20,   618,    20,
    1953,  1954,   232,   233,   448,   485,   485,   627,     5,   485,
     485,   241,   513,   676,    26,  1968,   508,   255,   672,   257,
    1973,  1974,  1975,    26,   448,   448,  1979,   315,  2614,  2615,
    2512,   481,   524,  2515,  1987,   273,   418,    30,  1326,    20,
      26,    37,    26,   281,    26,   275,    26,   285,    26,   642,
      26,    26,   642,   306,   284,   233,   309,   448,   448,    26,
    2184,  2014,   448,   241,   448,   484,    26,     5,   448,  2022,
    2023,   448,   310,  2026,   566,    20,    26,   485,    26,    26,
     508,   672,    26,   313,   448,     5,   199,   448,  3180,   678,
     203,   423,    26,   448,   448,  2048,   524,   275,  2580,   358,
     448,   448,   448,   676,  2057,     5,   284,  2060,  2061,  2062,
    2063,  2064,   448,   605,  2067,   448,  1424,   485,  2071,  2072,
     678,    26,  2075,   448,    26,  1433,   678,   357,   448,   642,
    2930,  2931,  2184,   448,  2934,   313,   314,    25,   566,    25,
    3263,    25,   634,  2096,  2097,  2098,    25,   448,  2101,  2102,
    2103,   643,  1460,  2106,   358,    47,   448,  2730,  2731,  2732,
       8,  2734,  2735,  2736,  2737,  2738,  2739,   448,   448,   448,
    2743,   401,  1847,   672,   448,   428,   508,   605,   448,   357,
     176,   448,  2135,   448,  2137,  2138,   448,  2140,  2141,   485,
     443,  2144,   524,   448,   447,  2148,    20,    21,   676,  2152,
    2153,   672,   532,   677,  2157,   481,   634,   648,  2827,   514,
    2163,  2164,   423,  2166,  2167,   643,   322,  2170,  2171,   111,
     112,     5,   670,   401,   475,   670,   648,   514,   513,   711,
     483,   384,   672,   664,   566,   672,  2855,   649,  2191,    48,
      49,    50,     5,   711,    53,  2198,    55,    56,  2201,   475,
    3373,  3272,     5,   402,   485,   631,   485,  2210,   511,     8,
      14,  2214,  3347,  3348,  3349,  3350,  3351,  3352,   485,   628,
       5,   193,   485,   605,     5,   528,   485,   455,   711,   711,
     475,    26,   278,   485,   485,    26,   178,  2240,   123,   148,
     286,   642,   513,    26,   672,   485,   292,   508,   294,   485,
     485,  1976,   634,   485,   485,   197,   475,    26,   485,   305,
     485,   643,  2265,   524,     5,   485,   513,   648,   224,   485,
     485,     5,   678,   485,    51,   149,   150,   151,   152,   153,
     154,   485,   677,   255,  2009,   257,   332,  1645,   678,  1647,
    1648,   714,   408,  1651,  1652,     5,   609,   669,    18,  1657,
      19,   273,   348,   210,   448,   566,   609,   353,    25,   281,
     440,  3161,  2315,   285,   642,   675,  2848,  3167,  3168,   365,
    3170,  3171,  3172,  3173,   266,   631,   372,  2330,   535,  3179,
     535,   672,     5,   208,    26,  2338,  2339,  2340,   310,  2377,
    2343,  2344,   599,  2346,   605,   455,   599,    26,   448,   599,
     379,    26,   448,  2885,  3014,   448,  2359,  2360,   448,    22,
    2363,  2364,   678,  2537,   525,  2594,   579,  2596,  3363,   448,
     672,   678,   675,   634,   448,   115,   485,   485,  1736,  2934,
     322,   323,   643,   485,  1722,     5,  1724,   329,   485,    52,
     485,  2579,   334,   716,   672,   672,  1734,  1735,   642,   448,
    2403,   642,   599,  1741,  1742,  1743,  1744,   485,  2411,     5,
    2413,  2414,     5,     5,  2417,   632,  2419,     5,   536,   485,
     678,   669,     5,     8,  3093,  3496,  2550,  2430,    26,   672,
     375,  2555,  2435,  2436,  2437,  2537,   678,    26,   677,  2563,
    2564,  2565,  3111,  3293,   275,  2448,  3296,  3297,  3298,  3299,
     383,   123,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,     5,  2466,     5,   448,  2977,   326,  2979,  2980,
     329,   485,   331,   485,   520,   649,   485,  2579,   193,   525,
     436,  2484,   417,  2486,   678,   531,   149,   150,   151,   152,
     153,   154,   351,    14,   450,   599,  2499,   603,     5,  1857,
      26,   712,   361,  2506,   167,   168,   169,   553,   157,   485,
     672,   678,   558,   677,   485,   599,     5,   481,   678,    48,
      49,    50,   677,   382,    53,   691,    55,    56,  2531,   448,
    2533,   448,  2535,     5,  3384,  2538,  2539,   493,  2541,     5,
     255,     5,   257,  3393,  3180,   448,   405,   425,   504,   671,
     409,   389,    26,  2556,   481,  2558,  2559,  2560,   273,   485,
     485,   515,   515,  3095,   485,   485,   281,   485,     5,   525,
     285,  2574,   735,   736,   516,   531,     5,   485,  2581,   485,
    2976,   296,     8,   539,   485,  3254,   528,   672,     5,   672,
     513,  2594,  1930,  2596,   629,   310,   672,   383,   606,  3131,
      25,  2326,   402,  2606,  2607,   561,  3161,  2332,   402,  2612,
     402,   513,  3167,   672,   485,  3170,  3171,  3172,  3173,   417,
     480,  2624,   513,     5,     5,   484,   703,    26,     5,  1987,
       5,    25,   648,  2358,    14,  2638,  2639,  2640,  2641,  2642,
    2643,    14,  2845,   306,   648,   669,   309,    26,   485,  2652,
       5,     5,   594,   485,  2657,  2858,    18,    19,    20,    21,
     606,    26,     6,   678,   448,  2839,   448,     7,   448,   448,
     833,   324,   448,   502,   448,   448,     5,    26,    26,   672,
     843,    26,   638,    26,    26,   672,   678,   672,   644,   448,
    2693,  2694,    20,     5,   330,   619,     5,     5,     5,  2702,
    2703,   720,  2705,   599,     8,  2708,     5,  2710,   624,  2067,
    2048,  2714,   448,   672,   485,   448,   525,   678,     5,  2057,
     599,     5,  2060,  2061,  2062,  2063,   268,   678,   670,   676,
     448,    26,   448,   485,   448,   678,   485,  2839,  3293,   678,
       5,  3296,  3297,  3298,  3299,     5,   678,   678,   676,  2873,
     501,  2754,    27,    25,    25,    25,   671,    25,   700,   701,
     702,    25,   704,  2766,    26,   428,   352,    42,    26,    26,
      26,    26,  2775,  2776,  2777,    26,    26,   448,   448,   721,
     443,     5,   448,   448,   447,   485,     5,   149,   150,   151,
     152,   153,   154,   522,   485,   603,   448,   326,  2801,     8,
     329,   297,   331,    26,    25,  2163,  3317,  3318,   448,   448,
    2813,  2814,   481,   495,  2817,   757,    20,  2820,   402,   606,
     483,   763,   351,   765,  2827,   199,  3358,   769,   485,  3384,
     772,   994,   361,   775,  2837,   485,     5,  2840,  2841,   485,
     485,   485,  2845,   785,    18,    19,    20,    21,   511,     5,
     485,   485,  2855,   382,    14,  2858,   268,  2860,   800,   496,
    3089,   448,     5,    26,   806,   528,  2869,   448,   448,    26,
     513,   813,   814,   815,   448,    26,   405,   819,  2481,   448,
     409,   485,    26,   431,    26,   827,    26,    26,   163,  2614,
    2615,   621,   448,   297,  2418,   448,  2420,   448,   402,   448,
     298,   843,   513,   485,   495,   599,  2909,   485,   448,    14,
     448,   448,  2915,  1076,     7,    26,   448,   678,   296,   449,
     296,  2924,  2925,   448,  2927,  2928,   485,  2930,  2931,   672,
    3462,  2934,   448,   628,   448,    26,   481,   212,   485,    25,
     298,   513,  2945,   448,     5,   448,   609,   448,   448,   448,
      26,    26,     5,   448,   481,   484,   448,  2315,    26,   672,
     672,   672,   481,  2558,  2499,  2968,  2969,  3423,  2236,  1021,
    1582,  1914,   247,    35,   249,   149,   150,   151,   152,   153,
     154,   689,    37,  2167,  2987,  2173,  2344,  2531,   119,   123,
     362,   674,  2995,   353,   214,  2998,  1760,   363,  3001,   615,
    1761,  3004,  2360,  3006,   219,  3008,   392,   391,  2346,   580,
     578,   547,   675,  3413,   819,  1315,  1813,   427,  2020,  2160,
    2027,  1012,  1863,  1285,  1616,  2895,  2583,  1943,  1288,  3032,
    2261,  1619,  3467,  2163,  1963,  2638,  2639,  2640,  2641,  3107,
    1465,    22,    98,    47,  2377,    47,    28,  1919,   948,   775,
    1925,   334,  1593,  2411,  1624,  2413,  1540,  1039,  3032,  1252,
    3217,   800,  1928,  1538,  3430,  2403,  3069,  1459,  2581,  1448,
     345,  2769,  3227,  1562,  1893,   464,  2767,  2752,  2447,  2825,
    3087,  2419,  3078,  3085,  1793,  1776,  3089,  2817,  1251,  3439,
    3093,  3279,  2430,  2152,  2106,  2345,  2326,  3008,  1659,  1659,
    1998,  2927,  2774,  3241,  2067,  2808,  2694,  1986,  3111,  2693,
    2417,  3322,  2796,  2469,  2638,  2639,  2640,  2641,  3050,  2998,
    2448,  1644,  2414,     9,   622,  3485,  2436,  1281,  2437,  2929,
    1735,  2625,  3006,  1734,  1076,  1638,  3283,  3140,  1277,   414,
    2339,  3159,  3145,  2924,  1611,  3148,  3178,   422,  3167,  2539,
    1092,   426,  1474,  1316,  1317,  1754,  3159,  2537,  3161,  1139,
    2184,  1482,    -1,  1326,  3167,  3168,  1464,  3170,  3171,  3172,
    3173,   556,    -1,  3176,    -1,  3178,  3179,  3279,  3181,    -1,
    2704,  2539,  2706,    -1,    -1,    -1,    -1,   462,    -1,    -1,
      -1,    -1,  1134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3217,    -1,    -1,    -1,    -1,  3222,
      -1,  3224,  1164,  1165,  1166,    -1,  1168,    -1,  1170,  1171,
      -1,    -1,    -1,    -1,  1176,  1177,    -1,    -1,  3241,  3363,
      -1,    -1,    -1,  2581,    -1,    -1,    -1,    -1,    -1,    -1,
      25,  3254,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3272,
      -1,    -1,    -1,  1215,  2612,    -1,    -1,    -1,    -1,    -1,
    3283,    -1,    -1,    -1,    -1,  1227,  3289,    -1,    -1,    -1,
    3293,   566,    -1,  3296,  3297,  3298,  3299,    -1,  3301,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,  1251,
    1252,    -1,  3315,    -1,    -1,   590,    -1,    -1,  1260,  3322,
      -1,    -1,    -1,  3326,    -1,  1488,    -1,  2930,  2931,    -1,
      -1,  2934,    -1,    52,  1276,  1277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3347,  3348,  3349,  3350,  3351,  3352,
    3075,    -1,    -1,    -1,    -1,    -1,  3359,    -1,    -1,   634,
    3085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,
      -1,    -1,  2710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3384,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
    3393,    -1,  2995,    -1,    -1,  2998,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2930,  2931,    -1,    -1,
    2934,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,  1679,
    1680,    -1,    -1,    -1,    -1,    -1,  1686,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,  3439,    -1,  3441,    -1,
      -1,    -1,    -1,  2801,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,   727,   728,    -1,  3180,    -1,    -1,    -1,   234,
      -1,  1624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3483,  3484,  3485,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,  3496,    -1,  3498,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,  1446,    -1,  1448,    -1,  1450,  1451,
      -1,    -1,    -1,    -1,    -1,    -1,  1458,  1459,    -1,    -1,
    1462,    -1,    -1,    -1,  1466,    -1,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1477,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1488,  1489,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3161,  1722,
      -1,  1724,    -1,    -1,  3167,  3168,    -1,  3170,  3171,  3172,
    3173,  1734,  1735,    -1,    -1,    -1,  3179,    -1,  1741,  1742,
    1743,  1744,    -1,    -1,    -1,   360,    -1,   306,    -1,    -1,
     309,   366,   367,   368,    -1,  3198,    -1,  1539,  1540,    -1,
    1542,    -1,    -1,  1545,  1546,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   388,    -1,    -1,    -1,   247,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2987,
      -1,    -1,    -1,    -1,  1576,    -1,  1896,  3161,    -1,    -1,
      -1,     9,    -1,  3167,  3168,    -1,  3170,  3171,  3172,  3173,
      18,    19,    -1,    -1,    -1,  3179,    24,    25,    26,    27,
      -1,    -1,  1604,    -1,    -1,    -1,  3004,    -1,  3006,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,  1939,
      -1,  1623,  1624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3293,    -1,    -1,  3296,  3297,  3298,  3299,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     485,    -1,    -1,    -1,    -1,   345,    -1,    -1,   493,  3322,
      -1,   496,    -1,    -1,   443,    -1,    -1,    -1,   447,   504,
      -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1681,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,   117,
     380,    -1,    -1,    -1,   122,    -1,    -1,    -1,    38,    39,
      -1,   129,    -1,   538,   483,     5,    -1,  1930,    -1,  3293,
      -1,    -1,  3296,  3297,  3298,  3299,    -1,    -1,    -1,    -1,
      -1,  3384,    -1,    -1,   414,    -1,    -1,    -1,   156,    -1,
    3393,    -1,   511,    -1,    -1,    -1,   426,    -1,   573,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3145,    -1,   528,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,   593,    -1,
      -1,  3159,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,
      -1,    -1,   462,   608,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,   477,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,    -1,    -1,
    3384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,  3393,
      -1,    -1,   647,    -1,    -1,    -1,    -1,    -1,    -1,   247,
      -1,   249,    -1,    -1,    -1,  2048,    -1,    -1,    -1,    -1,
     609,    -1,    -1,    -1,  2057,    -1,    -1,  2060,  2061,  2062,
    2063,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,  2072,
      -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   566,  1879,    -1,  2102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3289,    -1,    -1,    -1,    -1,   675,    -1,    -1,    -1,
     590,  1903,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,
    2230,  2231,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,
      -1,  2241,   350,  1925,    -1,    -1,    -1,    -1,  3326,    -1,
      -1,    -1,  1934,    -1,  1936,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   634,    -1,  2266,  2267,  2268,  2269,
    2270,  2271,   380,   643,    -1,    -1,  2276,  2277,  2278,  2279,
      -1,    -1,    -1,  2283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1973,  1974,  1975,    -1,    -1,    -1,  1979,  2201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,  2014,    -1,    -1,    -1,   444,   317,    38,    39,
      -1,   449,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   462,    -1,    -1,   727,   728,   467,
      -1,  3439,    -1,    -1,    -1,  2365,  2366,    -1,    -1,   477,
      -1,    -1,  2372,  2373,   482,   355,    -1,   485,    -1,    -1,
     488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,
     498,    -1,    -1,    23,   374,   375,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,   122,    53,    -1,    55,    56,    -1,   536,   537,
      -1,   451,    -1,   541,   414,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,  2346,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,   560,    -1,    -1,    -1,    -1,   437,   566,    -1,
      -1,    -1,   482,    -1,    -1,   485,    -1,    -1,    -1,    -1,
      -1,  2153,    -1,   453,    -1,  2157,    -1,    -1,   498,     9,
      -1,    -1,   590,   463,  2166,    -1,    -1,    -1,    18,    19,
     120,    -1,    -1,    -1,    24,    25,    26,    27,   478,    -1,
    2403,    -1,  2184,    -1,    -1,    -1,    -1,    -1,    -1,  2191,
      -1,    -1,    42,    -1,  2417,    -1,  2419,   537,   148,  2201,
      -1,  2521,  2522,    -1,    -1,    -1,   634,  2430,  2210,   549,
    2530,    -1,  2214,   641,    -1,   643,    -1,    -1,   518,    -1,
      -1,    -1,    -1,    -1,    -1,   653,   654,   247,    -1,    -1,
      -1,    -1,    -1,   661,    -1,    -1,    -1,    -1,  2240,    -1,
     540,    -1,    -1,   193,   672,    -1,    -1,    -1,  2568,  2569,
     590,    -1,    -1,    -1,    -1,   555,    -1,    -1,  2481,    -1,
      -1,    -1,   562,    -1,    -1,   565,    -1,   117,    -1,    -1,
      -1,   221,   122,   223,    -1,  2595,    -1,  2597,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,    -1,   629,
     590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   727,
     728,   641,    -1,    -1,    -1,   255,   156,   257,    -1,   609,
      -1,    -1,    -1,   653,   654,    -1,    -1,    -1,   268,    -1,
      -1,   661,    -1,   273,   664,    -1,    -1,   627,    -1,    -1,
      -1,   281,   672,    -1,    -1,   285,    -1,    -1,  2658,  2659,
      -1,   291,  2662,  2663,    -1,   295,   296,   297,   298,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2581,    -1,
     310,  2363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   326,    -1,    -1,   329,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,   338,  2612,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,   249,
      -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   361,    -1,    -1,    -1,  2638,  2639,  2640,  2641,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,   382,   383,  2436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,   409,
      -1,    -1,   482,    -1,    -1,   485,    -1,   417,   418,   419,
    2693,  2694,    -1,    -1,    -1,    -1,    -1,    -1,   498,  2702,
    2703,    -1,  2705,    -1,    -1,  2708,    -1,  2710,    -1,    -1,
      -1,  2714,    -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,
     350,    -1,    -1,    -1,  2506,    -1,    -1,  2730,  2731,  2732,
      -1,  2734,  2735,  2736,  2737,  2738,  2739,   537,  2838,    -1,
    2743,    -1,  2842,    -1,    -1,    -1,    -1,    -1,    -1,   549,
     380,    -1,    -1,    -1,   484,  2537,    -1,    -1,    -1,  2541,
      -1,  2861,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2556,    -1,  2558,    -1,  2560,    -1,
      -1,  2881,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
     590,    -1,  2574,    -1,    -1,    -1,   426,  2579,    -1,    -1,
      -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,   449,
      -1,   451,    -1,   623,  2606,  2607,    -1,    -1,    -1,   629,
      -1,    -1,   462,    -1,    -1,    -1,    -1,   467,   638,   639,
      -1,   641,    -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,
      -1,    -1,   482,   653,   654,   485,    -1,    -1,   488,    -1,
      -1,   661,    -1,    -1,   664,   595,  2869,   497,   498,    -1,
    2652,    -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   631,    -1,    -1,    -1,    -1,   536,   537,    -1,    -1,
      -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,   355,   549,
      -1,    -1,    20,    21,    22,    -1,    -1,  2930,  2931,    -1,
     560,  2934,    -1,    -1,    -1,    -1,   566,   374,   375,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
     590,   691,   692,   693,   694,   695,   696,   697,    -1,   699,
     700,    -1,  2754,    -1,    -1,    -1,    -1,   414,    -1,    -1,
      -1,    -1,    -1,    -1,  2766,    -1,   716,    -1,    -1,   426,
      -1,    -1,  2995,    -1,    -1,  2998,    -1,    -1,  3001,    -1,
     437,  3004,    -1,  3006,   634,    -1,    -1,    -1,    -1,    -1,
      -1,   641,    -1,   643,    -1,    -1,   453,    -1,    -1,    -1,
      -1,    -1,    -1,   653,   654,    -1,   463,    -1,    -1,  3129,
      -1,   661,  3132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   478,   672,    -1,    -1,  2827,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,  2839,    -1,    -1,
      58,    59,    60,    61,    62,    63,  3069,    -1,    -1,   167,
     168,   169,    -1,  2855,     9,    -1,    -1,    -1,  2860,    -1,
      -1,   518,    -1,    18,    19,    -1,    -1,  2869,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   727,   728,    -1,
      -1,    -1,    -1,   540,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,
      -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,   565,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3145,    -1,    -1,    -1,    -1,    -1,    -1,   586,
      -1,    -1,    -1,   590,    -1,    -1,  3159,   155,  3161,    -1,
      -1,    -1,    -1,    -1,  3167,  3168,    -1,  3170,  3171,  3172,
    3173,    -1,   609,    -1,    -1,    -1,  3179,  3277,  3181,    -1,
      -1,    -1,   117,    -1,    -1,    -1,  2968,   122,    -1,    -1,
     627,    -1,    -1,    -1,   129,  3198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,
      -1,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,  3328,  3329,
      -1,  3331,    -1,  3333,  3334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3032,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,     9,    -1,  3272,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,  3289,    -1,    -1,    -1,
    3293,    -1,    -1,  3296,  3297,  3298,  3299,    -1,    -1,    -1,
      42,  3401,    -1,  3403,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3093,   247,    -1,   249,    -1,    -1,    -1,   316,  3322,
      -1,    -1,    -1,  3326,    -1,    -1,    -1,    -1,    -1,  3111,
     428,    -1,    -1,    -1,    -1,    -1,    -1,  3437,    -1,    -1,
      -1,    -1,   340,    -1,    -1,   443,    -1,    -1,    -1,   447,
      -1,   349,    -1,    -1,    -1,    -1,  3456,  3457,  3140,    -1,
    3460,    -1,    -1,  3463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
     122,  3384,    -1,    -1,    -1,   483,     9,   129,    -1,   387,
    3393,    -1,   390,    -1,    -1,    18,    19,   395,    -1,    -1,
      -1,    24,    25,    26,    27,   403,    -1,    -1,    -1,    -1,
     345,    -1,    -1,   511,   156,   350,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,  3217,  3439,    -1,    -1,    -1,
    3222,    -1,  3224,    -1,    -1,   380,    -1,    -1,    -1,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   465,    -1,    -1,
      -1,    -1,  3254,   471,    -1,    -1,    -1,    -1,    -1,   414,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,
    3272,   426,    -1,  3496,   117,    -1,    52,  3279,    -1,   122,
      -1,    -1,    -1,    -1,    -1,   247,   129,   249,    -1,   444,
      -1,   609,   510,    -1,   449,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,
      -1,    -1,   467,   156,    -1,   533,    -1,    -1,    -1,    -1,
      -1,    -1,   477,    -1,    -1,   543,   544,   482,    -1,    -1,
     485,   549,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,   497,   498,    -1,  3347,  3348,  3349,  3350,  3351,
    3352,    -1,    -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,   584,   585,    -1,    -1,
      -1,   589,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,   537,   345,    -1,    -1,   541,    -1,   350,    -1,
      -1,   167,   168,   169,   549,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   560,   249,   562,    -1,    -1,
      -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   646,    -1,
      -1,    -1,    -1,    -1,    -1,   590,    -1,   655,    -1,   657,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   634,
      -1,    -1,   444,    -1,    -1,    -1,   641,   449,   643,   451,
      -1,    -1,    -1,    -1,  3496,    -1,    -1,    -1,   653,   654,
     462,    -1,   345,    -1,    -1,   467,   661,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   477,    -1,   672,    -1,    -1,
     482,    -1,    -1,   485,    -1,    -1,   488,    -1,    -1,    -1,
     306,    -1,    -1,   309,    -1,   497,   498,   380,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   727,   728,   536,   537,    -1,    -1,    -1,   541,
      -1,    -1,    -1,   426,    -1,    -1,    -1,   549,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,
      -1,   444,    -1,    -1,   566,    -1,   449,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,
      -1,    -1,    -1,    -1,   467,    -1,    -1,    -1,   590,    -1,
      -1,    -1,    -1,    -1,   477,    -1,    -1,    -1,    -1,   482,
      -1,    -1,   485,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,   428,    -1,   497,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,   447,   634,    -1,    -1,    -1,    -1,    -1,    -1,   641,
      -1,   643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   653,   654,    -1,   537,    -1,    -1,    -1,   541,   661,
      -1,    -1,    -1,    -1,    -1,    -1,   549,   483,    -1,    -1,
     672,    -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,    -1,
      -1,    -1,    -1,   566,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    -1,   511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,   590,    -1,    -1,
      -1,    -1,   528,    54,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,   727,   728,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   634,    -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,
     643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     653,   654,    -1,   114,    -1,    -1,    -1,    -1,   661,    -1,
      -1,    -1,    -1,   124,   125,    -1,   127,    -1,    -1,   672,
      -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,    -1,   177,   178,   179,    -1,
      -1,    -1,    -1,    -1,   727,   728,   187,   188,    -1,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   675,
     201,    -1,   203,   204,   205,    -1,    -1,    -1,    -1,    -1,
     211,    -1,   213,   214,    -1,   216,    -1,   218,   219,    -1,
      -1,   222,    -1,    -1,   225,   226,   227,   228,   229,   230,
      -1,    -1,    -1,   234,   235,   236,    -1,   238,    -1,    -1,
      -1,   242,    -1,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,   253,    -1,    -1,   256,    -1,   258,    -1,   260,
      -1,   262,    -1,    -1,    -1,   266,   267,    -1,   269,   270,
     271,    -1,    -1,   274,    -1,   276,   277,    -1,   279,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,   288,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
      -1,    -1,   303,   304,    -1,    -1,   307,   308,    -1,    -1,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,
     321,    -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   333,   334,   335,    -1,   337,    -1,    -1,    -1,
     341,   342,    -1,    -1,    -1,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   362,   363,   364,    -1,    -1,    -1,    -1,    -1,   370,
     371,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,
     381,    -1,    -1,    -1,   385,   386,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,   396,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   438,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,    -1,    -1,    -1,    -1,   456,    -1,   458,   459,    -1,
      -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
      -1,    -1,   523,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   546,   547,    -1,    -1,    -1,
     551,    -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,   569,   570,
     571,   572,    -1,    -1,    -1,   576,    -1,    -1,    -1,   580,
      -1,    -1,    -1,    -1,    -1,    -1,   587,   588,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,   600,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     611,    -1,   613,    -1,    -1,   616,    -1,    -1,    -1,    -1,
      -1,   622,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,    -1,    -1,    -1,    -1,   648,    -1,    -1,
     651,    -1,    -1,     9,    -1,   656,    -1,    -1,   659,   660,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,
     681,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   704,   705,   706,   707,   708,   709,   710,
      -1,    -1,   713,    -1,   715,    -1,   717,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,
      -1,    -1,   309,    -1,     6,     7,     8,    52,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      52,    -1,    -1,   447,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,   483,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,
     169,    52,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,   428,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   528,    -1,   443,    -1,    -1,    -1,
     447,   448,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   483,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,   609,   167,   168,   169,    52,
      -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,
     309,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   609,    -1,   306,    -1,    -1,   309,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   451,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   482,    -1,    -1,   485,
      -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,   309,   428,
      -1,   497,   498,    -1,    -1,    -1,    -1,    -1,   675,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,   447,   448,
      -1,    -1,    -1,   428,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,   537,   447,   448,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,   549,   483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,   443,   511,    -1,    -1,   447,   448,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,   528,
      -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,   306,    -1,    -1,   309,   428,    -1,    -1,
      -1,   483,    -1,   528,    -1,    -1,    -1,   623,    -1,    -1,
      -1,    -1,   443,   629,    -1,    -1,   447,   448,    -1,    -1,
      -1,    -1,   638,   639,    -1,   641,    -1,    -1,    -1,   511,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   653,   654,    -1,
      -1,    -1,    -1,    -1,    -1,   661,   528,    -1,   664,    -1,
      -1,    -1,   483,    -1,    -1,    -1,   672,    -1,    -1,    -1,
     609,    -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   675,   609,    -1,    -1,
     443,    -1,    -1,    -1,   447,   448,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   675,    -1,    -1,    -1,    -1,   511,    -1,
     443,    -1,    -1,    -1,   447,   448,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,   528,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     483,     6,     7,     8,   675,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    52,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,   511,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,   528,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    52,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,   149,   150,   151,   152,   153,
     154,    -1,   675,    -1,    -1,    -1,   609,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,    -1,
      -1,    -1,   675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,   149,   150,   151,   152,   153,   154,    -1,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,   306,     9,    -1,   309,    52,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,   306,    -1,
     197,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
      -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     306,    -1,    -1,   309,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,   447,   448,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,   252,   149,   150,   151,   152,
     153,   154,   259,    -1,    -1,    -1,    -1,    -1,   443,   122,
      -1,    -1,   447,    -1,   167,   168,   169,   428,    -1,   483,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   447,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,   511,   483,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,
     428,   496,    -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   483,    -1,    -1,   443,   511,    -1,    -1,   447,
      -1,    -1,   428,   340,    -1,   496,    -1,    -1,    -1,    -1,
     347,    -1,   349,   528,    -1,    -1,    -1,   443,    -1,    -1,
     511,   447,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   483,    -1,   528,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   496,    -1,
     387,    -1,    -1,    -1,   247,    -1,    -1,   483,   395,    -1,
      -1,    -1,    -1,   511,    -1,   609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   306,    52,    -1,   309,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   609,   432,    -1,   306,    -1,    -1,
     309,    -1,   528,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   609,   456,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   493,   350,    -1,    -1,
     675,   609,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   609,   675,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,    -1,    -1,   428,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     443,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    52,   447,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   675,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
     167,   168,   169,    -1,   601,   602,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,    -1,    -1,   614,   511,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,
      -1,    -1,   485,    -1,    -1,   528,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,   497,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   528,
      -1,    -1,   659,    -1,    -1,    -1,    -1,    -1,   306,    -1,
      -1,   309,   525,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,    -1,   549,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,    -1,    -1,
     717,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   733,   590,    52,   306,
     609,    -1,   309,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
     623,    -1,    -1,    -1,    -1,    -1,   629,    -1,    -1,    -1,
      -1,    -1,   675,    -1,    52,   638,   639,    -1,   641,    -1,
     428,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
     653,   654,    -1,    -1,    -1,   443,   675,    -1,   661,   447,
      -1,   664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   306,    -1,    -1,   309,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,
      18,    19,    20,   167,   168,   169,    24,    25,    26,    27,
      -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,   511,    -1,    -1,   443,    -1,    -1,    -1,
     447,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
     528,   149,   150,   151,   152,   153,   154,    -1,    -1,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,   122,    -1,    -1,    -1,    -1,    52,
      -1,   528,    -1,    -1,    -1,    -1,    -1,    52,   443,    -1,
      -1,   609,   447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,   496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,   511,   675,   306,    -1,
      -1,   309,   609,    -1,    -1,    -1,    -1,    -1,   306,    -1,
      -1,   309,    -1,   528,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   167,   168,   169,    -1,    -1,   247,
      -1,    -1,   167,   168,   169,    -1,   122,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,    38,
      39,    -1,    -1,    -1,   428,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,   447,   609,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
     428,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,   483,
     428,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,   447,
      -1,    -1,   350,    -1,    -1,   443,    -1,    -1,    -1,   447,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   511,    -1,    -1,
     675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,    -1,   306,   528,   483,   309,    -1,    32,    -1,
      -1,   306,    -1,    -1,   309,   483,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
     247,    -1,    -1,   511,    24,    25,    26,    27,    -1,    -1,
      -1,   122,    -1,   511,    -1,    -1,    -1,    -1,    38,    39,
     528,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
     528,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   482,    -1,    -1,   485,   247,    -1,
      -1,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,   497,
     498,    -1,    -1,   147,    -1,   428,    -1,    -1,    -1,    -1,
      -1,   609,   122,   428,    -1,    -1,    -1,    -1,    -1,    -1,
     443,   609,    -1,    -1,   447,    -1,    -1,    -1,   443,    18,
      19,   675,   447,    -1,    -1,    24,    25,    26,    27,   537,
     122,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    38,
      39,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   451,    -1,   675,   511,    -1,
      -1,    -1,   590,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,   528,    -1,    24,    25,    26,
      27,    -1,    -1,   528,   451,    -1,   482,    -1,    -1,   485,
      -1,    38,    39,    -1,    -1,   623,    -1,    -1,    -1,    -1,
      -1,   629,   498,   122,    -1,    -1,    -1,   247,    -1,    -1,
     638,   639,    -1,   641,    -1,   482,    -1,    -1,   485,    -1,
      -1,    -1,    -1,    -1,    -1,   653,   654,    -1,    -1,   525,
      -1,   498,    -1,   661,    -1,   247,   664,    -1,    -1,    -1,
      -1,   537,    -1,   317,   672,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   549,    -1,    -1,   609,    -1,    -1,    -1,
      -1,    -1,   451,    -1,   609,    -1,    -1,    -1,    -1,   536,
     537,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   355,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   482,   590,    -1,   485,    -1,    -1,    -1,
     374,   375,   376,   377,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    58,    59,    60,    61,    62,    63,    -1,   392,    -1,
     451,    -1,   675,   590,    -1,    -1,    -1,   623,   247,    -1,
     675,    -1,    -1,   629,    -1,    -1,    -1,    -1,    -1,    -1,
     414,    -1,   638,   639,    -1,   641,    -1,   536,   537,    -1,
      -1,   482,   426,    -1,   485,    -1,   623,   653,   654,    -1,
     549,    -1,   629,   437,    -1,   661,    -1,   498,   664,    -1,
      -1,   638,   639,    -1,   641,    -1,   672,    -1,    -1,   453,
      -1,    -1,    -1,    -1,    -1,    -1,   653,   654,    -1,   463,
      -1,    -1,    -1,    -1,   661,    -1,    -1,   664,    -1,    -1,
     247,   590,    -1,    -1,   478,   672,   537,    -1,   155,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,   451,
     629,    -1,   482,    -1,   518,   485,    -1,    -1,    -1,   638,
     639,    -1,   641,    -1,    -1,    -1,    -1,    -1,   498,   590,
      -1,    -1,    -1,    -1,   653,   654,   540,    -1,    -1,    -1,
     482,    -1,   661,   485,    -1,   664,    -1,    -1,    -1,    -1,
      -1,   555,    -1,   672,    -1,    -1,   498,    -1,   562,    -1,
      -1,   565,   623,    -1,    -1,    -1,   536,   537,   629,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   639,   549,
     641,    -1,   586,    -1,    -1,    -1,   590,    -1,    -1,    -1,
      -1,    -1,   653,   654,    -1,   537,    -1,    -1,    -1,    -1,
     661,    -1,   451,   664,    -1,   609,    -1,   549,    -1,    -1,
      -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     590,    -1,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   482,    -1,    -1,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,   498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   629,
      -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,
      -1,   641,    -1,    -1,   451,    -1,   525,    -1,    -1,    -1,
      -1,   623,    -1,   653,   654,    -1,    -1,   629,   537,    -1,
      -1,   661,    -1,    -1,   664,    -1,   638,   639,    -1,   641,
     549,    -1,   672,    -1,    -1,   482,    -1,    -1,   485,    -1,
      -1,   653,   654,   390,    -1,    -1,    -1,    -1,    -1,   661,
      -1,   498,   664,    -1,    -1,    -1,   403,    -1,    -1,    -1,
     672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,
      -1,    -1,   641,    -1,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   653,   654,    -1,    -1,    -1,    -1,
      -1,    -1,   661,   590,    -1,   664,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   629,    -1,    -1,    -1,   533,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   641,    -1,   543,   544,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,   653,   654,    -1,    -1,
      -1,    -1,   559,    -1,   661,    -1,    -1,   664,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   672,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,    -1,   584,   585,    -1,
      -1,    -1,   589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     657
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
      26,   967,   968,   969,   970,    25,   972,  1014,  1015,   921,
     448,   921,   921,   921,   921,   579,  1309,   485,   485,   921,
     423,   508,   524,   566,   605,   634,   643,  1489,  1490,   485,
     921,   921,   485,   485,   934,   485,   485,   485,   485,    26,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    52,   149,   150,   151,
     152,   153,   154,   167,   168,   169,   306,   309,   428,   443,
     447,   483,   511,   528,   609,   675,   823,   922,   935,   937,
     938,   939,   940,   941,   942,   943,   475,   955,   953,   959,
     957,  1179,  1179,   742,  1023,   946,  1023,  1190,   513,   481,
      26,   844,   485,   867,   851,   867,   846,    26,    26,    26,
     851,    26,    26,   832,   849,   867,    26,   672,   116,   859,
     796,  1314,   448,  1304,  1604,  1605,  1606,  1607,  1608,   980,
    1151,  1133,   672,    26,   448,   875,   876,   485,   877,   882,
     883,   877,   485,   878,     5,   448,     5,   448,     5,   339,
       5,   887,   481,     5,     5,   448,   833,   833,   833,   869,
     448,   485,     5,   448,   513,   672,   448,   448,   448,   448,
     448,   448,   448,    19,    26,   448,   642,   968,    19,    26,
     642,   448,     5,   448,   448,     5,   825,   921,   525,  1509,
     921,   485,   678,    20,   448,  1509,    20,  1292,   921,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   921,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   921,   921,
     921,   485,   921,   921,   485,  1179,   921,   921,   921,   921,
     448,     5,   485,   536,   774,   775,   776,   921,   485,  1189,
     513,   676,    26,   672,    26,   448,   448,     5,   448,   315,
       5,   448,     5,   448,   339,   481,     5,   448,   869,   798,
     799,  1131,  1023,  1195,  1196,  1198,  1195,   418,  1605,  1289,
      45,    46,    47,    54,    57,    64,    65,   109,   110,   114,
     124,   125,   127,   141,   158,   161,   162,   175,   177,   178,
     179,   187,   188,   190,   191,   192,   198,   201,   203,   204,
     205,   211,   213,   214,   216,   218,   219,   222,   225,   226,
     227,   228,   229,   230,   234,   235,   236,   238,   242,   244,
     245,   250,   253,   256,   258,   260,   262,   266,   267,   269,
     270,   271,   274,   276,   277,   279,   287,   288,   300,   303,
     304,   307,   308,   311,   312,   319,   320,   321,   323,   333,
     334,   335,   337,   341,   342,   346,   354,   362,   363,   364,
     370,   371,   378,   381,   385,   386,   396,   413,   421,   427,
     438,   450,   456,   458,   459,   466,   505,   516,   523,   546,
     547,   551,   563,   569,   570,   571,   572,   576,   580,   587,
     588,   598,   600,   611,   613,   616,   622,   648,   651,   656,
     659,   660,   674,   681,   704,   705,   706,   707,   708,   709,
     710,   713,   715,   717,   735,   736,   737,   738,   755,   779,
     800,   801,   807,   826,   900,   901,   902,   903,   914,   915,
     916,   917,   918,   919,   920,   973,  1004,  1008,  1030,  1032,
    1035,  1036,  1037,  1038,  1051,  1061,  1085,  1086,  1088,  1092,
    1107,  1108,  1112,  1113,  1114,  1115,  1125,  1140,  1156,  1167,
    1168,  1169,  1173,  1176,  1210,  1213,  1215,  1221,  1222,  1225,
    1228,  1233,  1235,  1237,  1240,  1247,  1252,  1257,  1258,  1259,
    1271,  1272,  1275,  1281,  1284,  1285,  1310,  1325,  1327,  1328,
    1329,  1330,  1342,  1348,  1349,  1369,  1372,  1401,  1403,  1494,
    1495,  1526,  1527,  1534,  1549,  1573,  1588,  1589,  1594,  1595,
    1597,  1601,  1602,  1609,   801,  1128,   677,   700,  1152,  1153,
    1195,    20,   448,   480,   847,   874,    26,   879,    26,    26,
      26,   896,   898,   890,   850,    26,   642,  1023,  1014,   742,
      20,   719,  1023,   874,   961,   961,    26,   448,   642,   961,
      24,    26,    26,   642,    24,    26,   871,   962,  1015,   872,
     448,   416,   529,   638,  1517,   448,   448,    26,  1490,   448,
     448,   448,   448,   448,   448,   448,   496,   496,   496,   944,
    1509,   496,   944,  1509,   956,   954,   960,   958,    26,   950,
     947,     5,   948,   481,  1189,   858,   448,    20,   847,    26,
     485,    26,    26,   843,    26,   730,   799,   672,   448,     5,
     448,  1179,  1179,  1179,  1023,    25,  1179,  1234,  1023,    25,
    1023,  1479,   407,  1024,  1025,  1603,  1024,    25,  1023,  1478,
    1023,  1023,  1255,  1018,  1024,  1018,  1023,  1599,  1479,  1023,
      26,   739,  1179,  1333,  1018,  1255,   944,    26,  1029,  1297,
    1298,  1297,   921,   928,  1371,  1478,  1478,   923,   944,  1024,
    1535,  1535,   904,  1255,  1018,  1331,  1179,  1020,  1024,   928,
    1535,  1179,  1255,  1179,  1370,  1535,    25,   638,  1170,  1171,
    1179,  1018,  1018,  1170,  1019,  1024,  1023,  1171,  1018,  1535,
    1018,  1020,  1479,  1179,  1208,  1209,  1016,  1024,  1020,   432,
     614,  1014,  1087,  1023,   808,  1478,  1021,  1024,    25,   247,
    1023,  1402,  1577,  1579,  1580,  1581,  1582,  1584,   944,  1208,
     678,   944,  1024,  1236,   974,    67,    68,    69,    70,   189,
     197,   206,   209,   252,   259,   316,   340,   347,   349,   359,
     387,   395,   432,   456,   493,   504,   601,   602,   603,   614,
     659,   717,   733,  1101,  1229,  1230,  1179,  1200,  1201,   927,
     928,  1246,   971,   971,  1017,  1024,   944,  1234,  1311,  1179,
    1288,    25,   485,  1179,  1283,  1529,  1282,   928,  1590,   163,
     212,   249,   345,   422,   462,   527,   756,   952,  1023,  1179,
    1320,   781,   928,  1016,   642,  1023,  1031,  1157,   928,  1016,
      26,  1179,  1109,  1016,   928,  1550,   928,  1297,  1023,  1033,
    1034,  1020,  1033,   971,  1020,  1033,   971,  1039,  1033,    25,
      26,   441,   540,  1029,  1090,  1179,  1197,  1199,   123,   330,
     402,   446,   621,   701,   702,   703,   712,   746,  1041,  1043,
    1045,  1047,  1049,  1174,  1175,  1178,   393,   404,   454,   468,
     556,  1404,   692,   693,   982,   983,   984,  1023,  1154,   699,
    1153,   448,   358,   448,   448,   448,   448,   676,     5,   448,
     833,   448,   481,   485,   678,    19,    26,   448,   961,    26,
     448,   448,   642,    26,   642,   678,    18,    19,    20,    25,
      26,    38,    39,   122,   451,   482,   485,   498,   537,   549,
     590,   623,   629,   638,   639,   641,   653,   654,   661,   664,
    1023,  1029,  1485,  1487,  1516,  1518,  1519,  1521,  1522,  1523,
    1545,  1546,  1547,  1548,  1578,  1579,  1583,  1309,   448,  1309,
    1309,  1309,  1309,  1309,  1309,    25,    25,    25,   921,   936,
     448,    25,   936,   448,   448,   448,   448,   448,   448,   774,
     448,   776,   774,   481,   358,   448,   833,   856,   857,   448,
     448,   676,   448,  1023,  1315,  1198,  1305,   112,   113,   142,
     143,   144,   509,   594,   637,  1350,  1351,  1352,  1355,  1358,
    1361,  1362,  1363,  1366,   672,   642,   664,   159,   160,   485,
     672,   642,   664,     8,   677,   481,  1478,   532,  1256,  1197,
     167,   168,   169,   648,   536,   924,   925,   928,  1179,  1204,
    1478,   745,   746,   907,   322,    51,   145,   146,   678,  1253,
     514,     5,   671,   678,   670,   670,  1211,   648,   475,     5,
     609,  1062,   514,   711,  1592,   711,   441,   810,  1179,   599,
     670,  1216,  1217,  1218,   672,    25,  1580,   513,  1585,   384,
    1400,   664,   672,   926,   928,   609,  1577,   926,     8,   606,
    1017,    26,   554,   607,   721,  1009,  1179,  1009,  1009,  1009,
      25,   234,   360,   366,   367,   368,   388,   493,   496,   504,
     538,   573,   592,   593,   603,   608,   647,   679,  1105,  1106,
    1009,  1009,   649,  1102,   746,  1102,  1102,  1010,  1010,  1102,
    1102,    40,    41,  1231,   746,    40,    41,  1232,     5,   475,
       5,   391,   442,     5,   745,   139,   140,   592,   679,  1093,
     714,  1593,   927,   665,   666,   667,   668,  1287,  1529,  1289,
     928,  1277,  1278,  1279,  1290,  1291,   928,   485,   485,   485,
     485,    25,   777,  1023,   485,  1529,   402,   485,   574,    36,
     642,   631,   782,   789,   780,  1023,    25,  1172,  1179,  1273,
       8,  1276,    14,  1023,  1184,  1191,  1192,  1194,  1202,  1203,
    1248,    40,    41,   220,   402,   597,   630,  1326,    33,   247,
     606,  1551,  1552,  1553,  1555,   628,     5,   711,   711,   926,
    1197,  1204,  1089,   475,     5,   208,  1067,   485,  1179,   926,
     485,    26,    26,   123,  1177,    25,  1179,  1533,  1533,  1024,
    1384,  1236,  1017,    37,   176,   278,   286,   292,   294,   305,
     332,   348,   353,   365,   372,   520,   525,   531,   553,   558,
    1373,  1374,  1382,  1391,  1392,  1398,  1399,  1405,  1406,  1416,
    1436,  1440,  1505,  1506,  1536,  1537,  1540,  1541,  1557,   985,
     986,   148,   981,   992,   993,   984,  1155,  1604,  1134,   513,
     887,   850,   672,  1023,   874,    26,   448,   642,   961,   448,
     642,   961,   961,    24,    26,   642,    24,    26,   875,  1522,
    1522,   423,   508,   524,   566,   605,   634,   643,  1488,  1491,
     525,  1521,   485,   485,   485,   485,  1516,  1516,  1516,   485,
     485,   485,   485,  1023,   485,     5,   599,  1445,  1450,   669,
    1023,    18,    19,    20,    21,   149,   150,   151,   152,   153,
     154,  1543,  1491,  1491,   475,     5,   448,   448,   951,   949,
     513,     5,   448,   858,   827,   827,   302,   315,   416,   485,
     529,   545,  1420,  1421,  1426,  1428,   485,  1023,  1367,  1368,
      26,   485,  1023,  1347,  1360,  1428,  1430,   485,  1023,  1357,
     485,  1347,  1353,     5,  1023,    25,  1023,  1023,    25,  1026,
    1182,  1023,    25,  1023,  1023,  1023,  1600,  1478,   648,   485,
     485,   907,  1478,     5,   678,   485,  1577,    25,  1028,  1254,
    1253,  1254,  1529,  1170,   928,   928,   928,  1011,  1012,   485,
    1179,  1209,  1063,  1064,  1065,  1478,   678,  1529,   971,  1593,
    1087,  1179,   809,   677,   928,   408,  1220,   609,  1219,  1581,
     742,  1586,  1587,  1023,    20,  1582,     5,  1574,   669,  1226,
     126,   128,   130,   670,   678,   899,  1197,  1200,   975,    18,
      19,   485,  1103,  1105,  1230,  1179,  1201,  1010,   928,   402,
     648,    26,  1179,    26,  1179,   745,   210,  1286,   448,   440,
    1324,  1289,  1279,     5,   670,  1280,  1591,  1023,    25,   971,
     971,   642,  1015,   675,  1179,   762,  1023,  1023,  1023,   928,
     397,   785,   789,   631,   783,   791,    23,   291,  1159,  1163,
     535,   944,   535,  1274,   928,   512,  1188,   672,     5,  1110,
     599,  1249,  1179,   220,   402,  1554,  1556,   246,  1552,  1052,
    1034,   971,   971,  1044,  1045,  1067,  1067,    48,    49,    50,
      53,    55,    56,   326,   329,   331,   351,   361,   382,   405,
     409,   484,  1066,  1068,  1069,  1097,  1179,  1199,   599,   747,
      26,   455,  1050,   379,  1528,  1528,   195,   196,   491,   599,
    1023,  1437,  1438,  1480,  1478,  1478,  1478,  1375,  1478,  1478,
    1023,  1538,   224,   436,   450,   493,   504,   525,   531,   539,
     561,   638,   644,  1407,  1409,  1410,  1411,  1517,  1478,  1383,
    1407,  1409,  1604,  1604,   441,   994,  1179,   694,   695,   987,
     988,   989,   534,   677,   696,   697,   716,   997,   998,  1604,
     827,    26,   848,    20,  1023,   448,    26,   448,   961,    26,
     961,    24,    26,   448,   448,    24,    26,   678,  1517,   448,
     451,  1521,  1544,  1583,   416,   529,   638,  1469,  1521,  1524,
    1469,  1469,  1469,  1469,   672,  1524,  1519,   568,  1446,  1447,
    1448,  1478,   579,  1444,  1451,   389,   567,   578,  1393,  1512,
    1023,  1521,  1521,  1521,  1521,   678,   485,   678,  1578,   921,
     448,   448,   848,   857,  1316,  1306,   485,   485,   485,  1364,
    1428,   485,   485,   115,  1365,  1367,     5,  1359,  1360,   121,
     355,   375,   376,   377,   414,   426,   437,   453,   463,   478,
     526,   555,   565,   586,   590,   618,   627,  1470,  1471,  1472,
    1474,  1356,  1357,  1353,  1354,   716,  1351,   672,   642,   448,
     672,   642,   599,  1598,   485,   740,   741,  1023,  1334,   944,
     924,  1023,  1332,   669,  1223,  1253,  1253,   678,     5,     5,
       5,   632,   928,     5,   672,   536,   678,   677,   221,   223,
     326,   329,   811,   814,   815,  1097,   812,   813,  1023,   485,
    1024,   701,   702,  1224,     5,   481,   928,  1478,  1575,  1576,
    1577,   629,   669,  1227,  1023,  1023,  1012,  1013,   562,   971,
     907,     8,     8,   977,    26,    26,  1104,  1105,  1179,   375,
    1241,   123,   921,  1289,   275,  1291,  1297,  1604,     5,     5,
     448,   448,   778,  1023,   448,  1529,   774,   485,   485,   485,
     790,   786,   417,   784,   928,   397,   787,   791,   649,  1099,
    1164,  1160,   419,  1158,  1159,   926,   678,  1185,    20,  1023,
    1193,  1203,    14,   536,  1250,  1251,  1521,  1179,  1583,  1200,
    1604,  1046,  1047,   603,  1022,   599,  1080,  1079,  1078,  1077,
    1082,  1081,  1014,  1083,  1014,  1084,  1076,  1075,  1073,  1072,
    1098,   382,  1069,  1074,   971,    58,    59,    60,    61,    62,
      63,   155,   390,   403,   465,   471,   510,   533,   543,   544,
     549,   559,   581,   584,   585,   589,   646,   657,   748,   749,
    1095,  1096,     5,    26,  1529,   305,  1179,   525,  1510,  1511,
    1529,  1236,  1504,  1506,   157,   157,   648,  1234,  1439,  1440,
     485,  1417,   207,  1451,  1478,   231,   327,  1542,   672,   678,
     485,  1412,  1412,   599,   677,     5,  1507,  1558,   399,   408,
     432,   435,   451,   554,   607,   614,  1017,  1385,  1390,   678,
     677,   996,  1179,     5,   599,   990,   991,   691,   989,   995,
    1023,   995,   999,  1000,   995,   382,   998,  1135,   481,   448,
     642,   961,   448,   642,   448,   448,   961,   961,   423,   508,
     524,   566,   605,   634,   643,  1492,  1518,     5,  1491,     5,
     448,     5,  1521,     5,   448,  1521,  1521,  1521,  1521,  1023,
     448,   485,  1448,     5,   669,  1023,  1484,     9,   350,   485,
     497,  1454,  1455,  1456,  1457,  1458,  1462,  1466,  1468,  1521,
     425,  1442,  1452,  1023,  1513,   671,  1469,   389,  1492,    26,
    1492,   481,   515,  1299,  1319,   515,  1260,  1293,   664,  1023,
    1423,  1425,  1478,  1482,  1483,  1427,  1482,  1427,     5,   448,
    1365,  1427,  1454,  1023,   448,  1368,     5,   448,   485,   485,
     485,  1491,  1491,   485,   485,   485,   485,   485,   263,   264,
     265,   455,  1429,  1431,     5,   448,     5,   448,  1023,  1023,
      25,  1023,  1023,    25,  1023,   928,  1023,  1344,  1345,     5,
    1346,  1347,   944,  1141,   672,  1346,   629,  1529,  1529,   928,
     928,  1011,   562,   928,  1596,     5,  1064,    20,  1482,  1529,
     812,   820,   819,   821,  1023,  1027,   822,  1027,   248,   815,
     818,     5,  1067,   672,   928,     8,  1587,   513,   672,     5,
    1529,   629,  1023,  1197,   944,   606,  1388,     5,   448,  1179,
       5,    26,  1179,   383,    25,  1321,   402,   402,   513,   672,
     402,   485,   763,   767,   760,   758,  1604,  1604,   792,   788,
     784,  1100,    25,  1022,  1165,  1179,  1604,   928,   480,   513,
     944,     5,  1053,  1048,  1049,    26,   745,  1023,  1604,  1604,
    1604,  1604,  1604,  1604,     5,  1070,     5,  1071,  1604,  1604,
    1604,  1604,  1103,  1604,  1022,    25,    14,    14,     5,   448,
      26,  1478,  1517,  1498,   648,   648,  1374,  1503,  1504,  1440,
    1418,  1482,   669,  1017,   485,  1378,  1023,  1539,  1538,  1413,
    1482,   517,  1414,  1415,  1480,  1478,  1411,  1518,   103,   104,
     105,   106,   107,   636,  1561,   928,   928,   606,  1386,  1017,
    1414,  1478,     5,  1179,   995,  1604,  1604,     5,  1002,  1003,
    1604,  1604,  1001,  1128,   891,   961,    26,   961,    24,    26,
     961,   961,   485,  1450,  1491,   678,  1491,  1491,   448,  1521,
     448,   448,   448,   448,  1447,  1449,  1447,  1484,  1457,  1516,
    1454,  1521,  1516,     6,     7,     9,    12,    13,    14,    15,
      16,    17,   428,   429,   483,   609,   675,   725,   726,  1465,
    1467,  1443,  1520,  1521,   502,  1441,  1453,   324,  1343,    26,
    1394,  1395,  1396,  1482,  1510,  1513,   448,   845,   131,   132,
     134,   135,   136,   233,   241,   275,   284,   313,   314,   357,
     401,   455,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,  1296,  1300,   194,   567,  1301,  1317,   217,   232,
     233,   241,   275,   284,   313,   357,   401,  1294,  1295,  1307,
    1301,  1483,   513,  1481,   448,     5,   672,     5,   448,   448,
    1428,   448,   448,  1360,    26,  1475,  1475,    26,   678,   485,
     678,    26,  1476,    26,    26,  1476,  1476,    25,  1485,   215,
     315,   352,   416,   430,   529,   545,  1422,  1432,  1433,  1434,
    1435,  1357,  1353,   672,   672,   591,   640,     5,   448,   741,
       5,   448,   926,   448,    20,   448,  1529,     5,   928,   619,
     330,   750,   751,   928,  1067,  1604,  1604,     5,   816,   513,
     672,     5,   817,  1604,   813,   599,    20,  1023,     5,  1023,
    1214,  1586,    20,  1482,  1576,     8,  1529,   446,   711,   926,
    1389,   976,  1105,   720,  1239,   921,     5,   774,  1179,   757,
     739,  1023,  1179,   765,   448,   774,   774,   774,  1604,  1604,
    1103,  1162,    25,  1166,  1179,   624,  1007,  1189,   536,   927,
    1111,  1251,   120,   595,  1054,  1040,  1041,   672,  1014,  1604,
    1014,  1604,   745,    26,  1179,    26,  1179,   749,   448,   485,
    1530,  1518,  1504,  1504,  1496,     5,   448,   525,  1515,  1379,
    1482,   532,  1376,  1515,   678,     5,   448,     5,   599,  1508,
      18,    19,   122,   482,   485,   498,   536,   537,   549,   590,
     629,   641,   653,   654,   661,   664,  1023,  1485,  1516,  1545,
    1547,  1566,  1567,  1568,  1569,  1570,  1571,  1583,  1566,  1566,
    1566,  1482,  1563,  1565,  1562,  1563,  1564,  1559,  1387,   678,
    1179,  1023,  1604,  1604,  1604,  1604,   676,   448,   642,   448,
     448,    26,   448,   678,  1492,   678,   678,     5,   448,   448,
    1455,  1456,  1460,  1522,  1460,   485,  1516,  1460,   485,  1516,
    1460,    10,   306,   443,   445,  1521,     5,  1454,     5,   591,
     640,  1397,  1343,   678,   676,  1297,  1297,  1297,    25,  1297,
    1297,  1297,  1297,  1297,  1297,    25,    25,  1297,  1300,  1179,
    1205,  1206,   671,   501,  1261,    25,    25,    26,    26,    26,
      26,    26,    25,  1179,  1295,  1261,    26,  1422,  1482,    20,
    1023,  1482,  1365,   448,   448,     5,   448,  1492,    26,  1492,
       5,  1473,     5,   448,   448,   448,  1473,  1424,  1478,   485,
    1434,  1365,  1023,  1023,  1345,   675,   729,  1339,  1340,  1341,
    1347,    66,   143,   144,   301,   675,  1335,  1336,  1337,   522,
     906,  1335,     5,   431,  1529,     5,   485,   448,   603,  1094,
    1027,  1604,   742,    20,  1023,  1027,  1604,   971,   928,   481,
    1529,     8,   971,  1200,  1604,    26,  1022,    25,  1322,  1197,
     481,   774,   764,   768,   448,   448,  1604,  1022,   928,  1005,
     481,  1056,  1055,   495,  1042,  1043,    20,  1023,  1531,  1532,
     606,  1514,  1499,  1497,  1482,  1517,   199,  1419,     5,   448,
    1377,  1539,  1482,  1415,  1414,  1514,  1569,  1569,  1568,   485,
     485,   485,   485,   485,   485,   485,  1023,   485,     5,   448,
      18,    19,    20,    21,  1543,   448,     5,   448,     5,    14,
     207,   579,  1560,  1200,  1414,   268,  1136,   887,   961,    24,
      26,   961,   961,   448,  1492,  1492,  1492,  1447,   496,  1459,
    1459,  1463,  1464,  1485,  1583,  1459,  1463,  1459,  1460,  1521,
    1520,  1395,  1492,   858,   591,   640,  1207,     5,  1205,   119,
     193,   255,   257,   273,   281,   285,   310,  1262,  1263,  1318,
    1308,     5,   481,  1481,    26,   448,    26,  1477,   448,    26,
     448,   485,  1454,  1338,  1603,    26,  1341,    26,    26,  1338,
    1343,  1337,  1014,   745,   431,  1529,   928,   752,   621,  1212,
      26,   745,   481,  1094,   448,  1529,   297,   745,   448,   448,
     485,   766,   402,   772,   448,   761,   759,  1161,  1604,   513,
     928,  1604,  1022,     5,   448,  1200,  1450,  1518,  1482,   485,
    1450,   448,  1544,  1469,  1568,  1572,  1469,  1469,  1469,  1469,
     513,   672,  1572,  1567,  1568,  1568,  1568,  1568,  1563,    14,
    1564,  1567,  1017,  1454,   200,   669,  1408,   448,   448,  1461,
    1485,  1525,     5,   448,   448,  1459,     7,  1206,  1264,  1265,
    1179,  1267,  1179,  1266,  1268,  1263,   296,   296,    26,   448,
     678,   448,  1425,   448,   905,  1529,   449,   259,   316,   340,
     349,   387,   395,   486,   655,   749,   753,   754,   485,   672,
     745,  1238,  1323,   769,   448,  1197,   772,   772,   772,  1604,
    1006,  1189,   628,  1091,  1532,  1512,  1450,   536,  1380,  1381,
    1521,  1512,   448,  1568,     5,   448,  1568,  1568,  1568,  1568,
      26,  1023,   448,   485,  1023,   961,   961,  1464,  1521,  1604,
    1604,  1269,  1604,  1270,  1604,  1604,   481,  1492,   448,   295,
     405,   409,   908,   909,   910,  1097,  1009,  1009,  1009,  1009,
    1009,  1009,    25,     5,   448,   928,    20,  1023,  1097,  1242,
    1243,  1244,   772,   774,   772,   298,   481,  1057,   745,     5,
     448,   343,   344,  1500,   448,  1568,   448,   448,   448,   448,
       5,   481,   513,  1566,  1604,  1604,   912,   911,   295,   910,
     913,   754,     5,  1245,   338,  1244,   770,  1604,  1381,    25,
    1023,  1501,  1502,    26,    26,   448,  1604,  1604,  1604,   928,
    1604,   448,  1054,   672,   672,     5,   481,     5,   481,   448,
     771,  1023,  1023,  1502,    26,   220,   402,   773,   672,   481,
    1197,  1023
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

  case 582:
#line 3464 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 583:
#line 3468 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 584:
#line 3472 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 585:
#line 3477 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 586:
#line 3481 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 587:
#line 3496 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 588:
#line 3500 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 589:
#line 3506 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 590:
#line 3510 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 591:
#line 3519 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 592:
#line 3520 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 593:
#line 3532 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 594:
#line 3538 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 595:
#line 3546 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 602:
#line 3563 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 603:
#line 3565 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 604:
#line 3568 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 605:
#line 3570 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 610:
#line 3584 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 611:
#line 3586 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 612:
#line 3589 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 613:
#line 3591 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 626:
#line 3622 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 627:
#line 3624 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 628:
#line 3627 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 629:
#line 3629 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 630:
#line 3632 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 631:
#line 3634 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 632:
#line 3637 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 633:
#line 3639 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 634:
#line 3642 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 635:
#line 3644 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 636:
#line 3658 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 637:
#line 3662 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 638:
#line 3663 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 639:
#line 3670 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 641:
#line 3688 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 642:
#line 3704 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 643:
#line 3705 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 644:
#line 3706 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 645:
#line 3707 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 646:
#line 3708 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 647:
#line 3709 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 648:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 652:
#line 3718 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 654:
#line 3724 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 655:
#line 3727 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 656:
#line 3732 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 657:
#line 3737 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 658:
#line 3740 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 659:
#line 3745 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 660:
#line 3750 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 661:
#line 3755 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 662:
#line 3762 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 663:
#line 3763 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 664:
#line 3770 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 665:
#line 3777 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 666:
#line 3779 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 667:
#line 3785 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3790 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 669:
#line 3795 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 670:
#line 3800 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 671:
#line 3800 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 672:
#line 3803 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 673:
#line 3809 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 674:
#line 3814 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 675:
#line 3818 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 678:
#line 3826 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 679:
#line 3829 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 680:
#line 3832 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 681:
#line 3837 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 682:
#line 3842 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 683:
#line 3847 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 684:
#line 3854 "fgl.yacc"
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
#line 3865 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 687:
#line 3927 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 689:
#line 3936 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 690:
#line 3945 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 692:
#line 3952 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 693:
#line 3955 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 694:
#line 3961 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 695:
#line 3967 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 696:
#line 3971 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 697:
#line 3975 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 698:
#line 3981 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 699:
#line 3985 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 700:
#line 3989 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 701:
#line 3994 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 702:
#line 3999 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 721:
#line 4040 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 722:
#line 4047 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 723:
#line 4049 "fgl.yacc"
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
#line 4068 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 727:
#line 4071 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 728:
#line 4073 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 729:
#line 4076 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 730:
#line 4080 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 731:
#line 4083 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 732:
#line 4090 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 733:
#line 4095 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 734:
#line 4106 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 735:
#line 4107 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 736:
#line 4110 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 738:
#line 4116 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 739:
#line 4120 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 740:
#line 4121 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 741:
#line 4125 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 745:
#line 4140 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 746:
#line 4142 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 749:
#line 4151 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 750:
#line 4154 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 751:
#line 4158 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 752:
#line 4161 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 753:
#line 4164 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 754:
#line 4167 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 755:
#line 4170 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 756:
#line 4174 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 757:
#line 4177 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 758:
#line 4180 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 759:
#line 4183 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 760:
#line 4186 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 761:
#line 4189 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 762:
#line 4192 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 763:
#line 4195 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 764:
#line 4198 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 765:
#line 4199 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 766:
#line 4199 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 767:
#line 4200 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 768:
#line 4200 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 769:
#line 4201 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 770:
#line 4201 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 771:
#line 4202 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 772:
#line 4205 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 773:
#line 4206 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 774:
#line 4209 "fgl.yacc"
    { print_befaft_field_2(); }
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
#line 4227 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 778:
#line 4231 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 779:
#line 4236 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 780:
#line 4241 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 781:
#line 4246 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 782:
#line 4247 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 783:
#line 4248 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 784:
#line 4252 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 785:
#line 4256 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 786:
#line 4265 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 787:
#line 4270 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 788:
#line 4274 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 789:
#line 4281 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 790:
#line 4290 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 791:
#line 4296 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 792:
#line 4297 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 793:
#line 4298 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 794:
#line 4299 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 795:
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

  case 796:
#line 4310 "fgl.yacc"
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
#line 4324 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 799:
#line 4327 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 800:
#line 4334 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 801:
#line 4335 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4336 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4337 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 804:
#line 4338 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 805:
#line 4339 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 806:
#line 4340 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 807:
#line 4341 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 808:
#line 4342 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 809:
#line 4347 "fgl.yacc"
    {iskey=1;}
    break;

  case 810:
#line 4347 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 811:
#line 4349 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 812:
#line 4352 "fgl.yacc"
    {iskey=1;}
    break;

  case 813:
#line 4352 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 814:
#line 4354 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 815:
#line 4358 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 816:
#line 4361 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 817:
#line 4362 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 819:
#line 4365 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 825:
#line 4377 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 826:
#line 4378 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 827:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 828:
#line 4380 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 829:
#line 4381 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 830:
#line 4382 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 831:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 832:
#line 4384 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 833:
#line 4385 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 834:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 835:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 836:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 837:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 838:
#line 4390 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 839:
#line 4394 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 840:
#line 4412 "fgl.yacc"
    {chk4var=1;}
    break;

  case 841:
#line 4412 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 842:
#line 4415 "fgl.yacc"
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
#line 4439 "fgl.yacc"
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
#line 4457 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 846:
#line 4463 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 847:
#line 4469 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 848:
#line 4475 "fgl.yacc"
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
#line 4487 "fgl.yacc"
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
#line 4518 "fgl.yacc"
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
#line 4535 "fgl.yacc"
    {
	}
    break;

  case 866:
#line 4561 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 870:
#line 4569 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 884:
#line 4593 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 885:
#line 4594 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 886:
#line 4602 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 887:
#line 4608 "fgl.yacc"
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
#line 4624 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 889:
#line 4630 "fgl.yacc"
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
#line 4645 "fgl.yacc"
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
#line 4658 "fgl.yacc"
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
#line 4669 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 894:
#line 4676 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 895:
#line 4683 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 896:
#line 4689 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 897:
#line 4689 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 898:
#line 4694 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 899:
#line 4700 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 900:
#line 4708 "fgl.yacc"
    {
}
    break;

  case 904:
#line 4720 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 906:
#line 4728 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 907:
#line 4734 "fgl.yacc"
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
#line 4754 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 911:
#line 4760 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 912:
#line 4764 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 915:
#line 4776 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 916:
#line 4779 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 917:
#line 4783 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 918:
#line 4786 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 919:
#line 4798 "fgl.yacc"
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
#line 4806 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 921:
#line 4812 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 922:
#line 4823 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 923:
#line 4827 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 924:
#line 4834 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 925:
#line 4841 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 926:
#line 4847 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 927:
#line 4852 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 930:
#line 4859 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 931:
#line 4860 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 932:
#line 4862 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 933:
#line 4863 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 934:
#line 4866 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 935:
#line 4867 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 936:
#line 4868 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 937:
#line 4870 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 938:
#line 4875 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 939:
#line 4880 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 940:
#line 4887 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 944:
#line 4894 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 945:
#line 4896 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 946:
#line 4898 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 948:
#line 4908 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 949:
#line 4911 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 950:
#line 4914 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 957:
#line 4930 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 958:
#line 4935 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 959:
#line 4935 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 960:
#line 4938 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 961:
#line 4966 "fgl.yacc"
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
#line 5023 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 965:
#line 5030 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 966:
#line 5034 "fgl.yacc"
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
#line 5077 "fgl.yacc"
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
#line 5125 "fgl.yacc"
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
#line 5139 "fgl.yacc"
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
#line 5163 "fgl.yacc"
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
#line 5227 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 979:
#line 5232 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 980:
#line 5240 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 981:
#line 5245 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 982:
#line 5253 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 983:
#line 5259 "fgl.yacc"
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
#line 5291 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 985:
#line 5294 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 986:
#line 5296 "fgl.yacc"
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
#line 5337 "fgl.yacc"
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
#line 5390 "fgl.yacc"
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
#line 5442 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 995:
#line 5451 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 996:
#line 5456 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 997:
#line 5467 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 998:
#line 5474 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1000:
#line 5482 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1001:
#line 5485 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1002:
#line 5486 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1004:
#line 5488 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1005:
#line 5489 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1006:
#line 5492 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1007:
#line 5495 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1008:
#line 5501 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1009:
#line 5504 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1010:
#line 5508 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1011:
#line 5513 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1012:
#line 5521 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1013:
#line 5526 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1014:
#line 5533 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1015:
#line 5535 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1020:
#line 5563 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1021:
#line 5570 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1022:
#line 5577 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1023:
#line 5580 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1024:
#line 5594 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1029:
#line 5611 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1030:
#line 5616 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1031:
#line 5622 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1033:
#line 5629 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1034:
#line 5634 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1035:
#line 5637 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1036:
#line 5638 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1037:
#line 5641 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1038:
#line 5642 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5645 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1040:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1041:
#line 5651 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1042:
#line 5658 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1043:
#line 5661 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1044:
#line 5667 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1045:
#line 5669 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1046:
#line 5671 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1047:
#line 5673 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1048:
#line 5676 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1049:
#line 5676 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1050:
#line 5677 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1051:
#line 5682 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1052:
#line 5690 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1053:
#line 5691 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1054:
#line 5696 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1055:
#line 5698 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1056:
#line 5700 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1060:
#line 5718 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1061:
#line 5719 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1062:
#line 5720 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1063:
#line 5721 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1064:
#line 5722 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1065:
#line 5723 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1066:
#line 5724 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1067:
#line 5725 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1068:
#line 5726 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5727 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1070:
#line 5728 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1071:
#line 5729 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1072:
#line 5730 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1073:
#line 5731 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1074:
#line 5732 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1075:
#line 5733 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1076:
#line 5734 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1077:
#line 5735 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1078:
#line 5736 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1079:
#line 5737 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1080:
#line 5738 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1081:
#line 5739 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1082:
#line 5740 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1083:
#line 5741 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1084:
#line 5742 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1085:
#line 5743 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1086:
#line 5744 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1087:
#line 5745 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1088:
#line 5749 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1089:
#line 5750 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1090:
#line 5754 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1091:
#line 5755 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1092:
#line 5770 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1095:
#line 5779 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1096:
#line 5783 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1097:
#line 5787 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1098:
#line 5791 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1099:
#line 5795 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1101:
#line 5815 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1102:
#line 5820 "fgl.yacc"
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
#line 5833 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1104:
#line 5834 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1105:
#line 5838 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1106:
#line 5843 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1107:
#line 5844 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1108:
#line 5848 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1112:
#line 5854 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1113:
#line 5857 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1115:
#line 5872 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1116:
#line 5876 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1117:
#line 5882 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1118:
#line 5883 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1119:
#line 5888 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1120:
#line 5889 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1121:
#line 5892 "fgl.yacc"
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
#line 5919 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1124:
#line 5923 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1125:
#line 5927 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1126:
#line 5931 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1127:
#line 5938 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1128:
#line 5939 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1134:
#line 5951 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1135:
#line 5957 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1136:
#line 5965 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1137:
#line 5971 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1138:
#line 5973 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1142:
#line 5983 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1143:
#line 5983 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1144:
#line 5988 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1145:
#line 5992 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1146:
#line 5997 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1147:
#line 5997 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1148:
#line 6001 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1149:
#line 6001 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1150:
#line 6002 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1151:
#line 6002 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1152:
#line 6003 "fgl.yacc"
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
#line 6016 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1154:
#line 6017 "fgl.yacc"
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
#line 6033 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1162:
#line 6045 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1163:
#line 6045 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1164:
#line 6051 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1165:
#line 6051 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1166:
#line 6054 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1167:
#line 6054 "fgl.yacc"
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
#line 6070 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1169:
#line 6071 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1170:
#line 6072 "fgl.yacc"
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
#line 6081 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1172:
#line 6093 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1178:
#line 6104 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1179:
#line 6109 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1180:
#line 6109 "fgl.yacc"
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
#line 6133 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1183:
#line 6139 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1184:
#line 6144 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1185:
#line 6150 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1186:
#line 6151 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1187:
#line 6152 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1188:
#line 6156 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1189:
#line 6157 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1190:
#line 6158 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1191:
#line 6159 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1192:
#line 6163 "fgl.yacc"
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
#line 6173 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1194:
#line 6175 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1195:
#line 6180 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1196:
#line 6183 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1197:
#line 6188 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1198:
#line 6195 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1199:
#line 6202 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1200:
#line 6209 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1201:
#line 6218 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1202:
#line 6225 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1203:
#line 6232 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1204:
#line 6239 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1205:
#line 6246 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1210:
#line 6259 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1211:
#line 6260 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1212:
#line 6261 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1213:
#line 6262 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1214:
#line 6263 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1215:
#line 6264 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1216:
#line 6265 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1217:
#line 6266 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1218:
#line 6267 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1219:
#line 6268 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1222:
#line 6274 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1223:
#line 6275 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1224:
#line 6276 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1225:
#line 6277 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1230:
#line 6286 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1231:
#line 6287 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1232:
#line 6288 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1233:
#line 6289 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1234:
#line 6290 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1235:
#line 6291 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1236:
#line 6292 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1237:
#line 6293 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1238:
#line 6295 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1239:
#line 6296 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1240:
#line 6297 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1241:
#line 6298 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1242:
#line 6300 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1243:
#line 6301 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1244:
#line 6302 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1245:
#line 6303 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1249:
#line 6308 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1250:
#line 6309 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1254:
#line 6316 "fgl.yacc"
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
#line 6325 "fgl.yacc"
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
#line 6334 "fgl.yacc"
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
#line 6347 "fgl.yacc"
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
#line 6358 "fgl.yacc"
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
#line 6369 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1260:
#line 6373 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1261:
#line 6377 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1262:
#line 6383 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1263:
#line 6388 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1264:
#line 6396 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1265:
#line 6399 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1266:
#line 6408 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1267:
#line 6419 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1269:
#line 6426 "fgl.yacc"
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
#line 6436 "fgl.yacc"
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
#line 6446 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1272:
#line 6449 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1273:
#line 6453 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1274:
#line 6461 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1275:
#line 6464 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1276:
#line 6470 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1277:
#line 6474 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1278:
#line 6478 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1279:
#line 6482 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1280:
#line 6486 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1281:
#line 6492 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1282:
#line 6493 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1283:
#line 6494 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1284:
#line 6495 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1285:
#line 6500 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1286:
#line 6501 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1287:
#line 6502 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1288:
#line 6503 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1289:
#line 6504 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1290:
#line 6505 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1291:
#line 6506 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1292:
#line 6507 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1293:
#line 6511 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1294:
#line 6512 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1295:
#line 6515 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1296:
#line 6520 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1297:
#line 6527 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1298:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 6529 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6534 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1301:
#line 6535 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1302:
#line 6541 "fgl.yacc"
    {insql=1;}
    break;

  case 1303:
#line 6541 "fgl.yacc"
    {insql=0;}
    break;

  case 1304:
#line 6541 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1305:
#line 6546 "fgl.yacc"
    {insql=1;}
    break;

  case 1306:
#line 6546 "fgl.yacc"
    {insql=0;}
    break;

  case 1307:
#line 6546 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1308:
#line 6554 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1309:
#line 6555 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1311:
#line 6560 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1312:
#line 6565 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1313:
#line 6566 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1314:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1315:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1316:
#line 6569 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1318:
#line 6574 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1319:
#line 6574 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1321:
#line 6578 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1322:
#line 6582 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1323:
#line 6583 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1324:
#line 6586 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6587 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1326:
#line 6590 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1327:
#line 6593 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1328:
#line 6596 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1329:
#line 6602 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1330:
#line 6604 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1332:
#line 6617 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1333:
#line 6621 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1334:
#line 6622 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1336:
#line 6627 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1337:
#line 6630 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1338:
#line 6636 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1339:
#line 6639 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1340:
#line 6647 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6654 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1343:
#line 6658 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1344:
#line 6662 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1345:
#line 6668 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1346:
#line 6671 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1347:
#line 6680 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1348:
#line 6683 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
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
		yyval.sql_string=strdup(yyvsp[0].str);
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
#line 6705 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1355:
#line 6708 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1356:
#line 6715 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1357:
#line 6718 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1358:
#line 6724 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1359:
#line 6727 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1360:
#line 6734 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1361:
#line 6737 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1363:
#line 6745 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1365:
#line 6754 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1366:
#line 6757 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1367:
#line 6763 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1368:
#line 6766 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1369:
#line 6772 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1370:
#line 6779 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1371:
#line 6780 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1372:
#line 6784 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1373:
#line 6794 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1374:
#line 6797 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1375:
#line 6803 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1376:
#line 6805 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1377:
#line 6810 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6811 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6816 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1380:
#line 6817 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1381:
#line 6823 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1382:
#line 6824 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6851 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6857 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1393:
#line 6860 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1394:
#line 6863 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1395:
#line 6869 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1397:
#line 6875 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1399:
#line 6886 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1400:
#line 6900 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1401:
#line 6909 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1402:
#line 6909 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1403:
#line 6914 "fgl.yacc"
    {insql=1;}
    break;

  case 1404:
#line 6914 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1405:
#line 6919 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1406:
#line 6922 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1407:
#line 6924 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6931 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6935 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1411:
#line 6939 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1412:
#line 6946 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1413:
#line 6949 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1414:
#line 6956 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1415:
#line 6960 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1416:
#line 6966 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1417:
#line 6971 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1418:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1419:
#line 6981 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1420:
#line 6984 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1421:
#line 6990 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1422:
#line 6997 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1423:
#line 7001 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1424:
#line 7006 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1425:
#line 7016 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1426:
#line 7019 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1427:
#line 7021 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1428:
#line 7023 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1429:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1430:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1431:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_RELATIVE);}
    break;

  case 1432:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_ABSOLUTE);}
    break;

  case 1433:
#line 7037 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1434:
#line 7047 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1435:
#line 7054 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7060 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7063 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7070 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1444:
#line 7075 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1445:
#line 7080 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1446:
#line 7087 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1447:
#line 7088 "fgl.yacc"
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
			print_exec_sql(convstrsql(yyvsp[0].str));
			printf("Warning: Informix specific SQL @ line %d\n",yylineno);
			strcpy(yyval.str,"InfxSpecificSql");
	}
    break;

  case 1456:
#line 7127 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1458:
#line 7133 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1460:
#line 7137 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1461:
#line 7142 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1462:
#line 7147 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1463:
#line 7151 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1465:
#line 7157 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1466:
#line 7161 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1467:
#line 7168 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7169 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7170 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7171 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1474:
#line 7181 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7182 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1476:
#line 7183 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7187 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1478:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1481:
#line 7195 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7198 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1485:
#line 7201 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7206 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1489:
#line 7208 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7214 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7220 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1496:
#line 7230 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1497:
#line 7235 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1498:
#line 7237 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7243 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7246 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1503:
#line 7252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1504:
#line 7260 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7265 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7275 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 7281 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7286 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1512:
#line 7289 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1513:
#line 7294 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 7300 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7305 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1517:
#line 7308 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1518:
#line 7311 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1519:
#line 7318 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1520:
#line 7319 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1521:
#line 7320 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1522:
#line 7322 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1523:
#line 7335 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1524:
#line 7340 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1526:
#line 7344 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1527:
#line 7346 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1528:
#line 7353 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1529:
#line 7356 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1530:
#line 7362 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1531:
#line 7370 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1532:
#line 7374 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1533:
#line 7378 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1534:
#line 7382 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1535:
#line 7387 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1536:
#line 7390 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1537:
#line 7393 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1538:
#line 7401 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1539:
#line 7408 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1542:
#line 7417 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7423 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1544:
#line 7426 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1545:
#line 7437 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1546:
#line 7444 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1547:
#line 7450 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1548:
#line 7453 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1549:
#line 7460 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1550:
#line 7467 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1552:
#line 7474 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1553:
#line 7480 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1554:
#line 7481 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1555:
#line 7482 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1557:
#line 7486 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1558:
#line 7493 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1560:
#line 7500 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1561:
#line 7507 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1562:
#line 7512 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1563:
#line 7513 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1564:
#line 7516 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1565:
#line 7519 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1566:
#line 7524 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1567:
#line 7525 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1568:
#line 7530 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1569:
#line 7533 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1570:
#line 7539 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1571:
#line 7542 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1572:
#line 7548 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1573:
#line 7551 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1574:
#line 7557 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1575:
#line 7560 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1576:
#line 7567 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1577:
#line 7568 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1578:
#line 7597 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1579:
#line 7598 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1580:
#line 7602 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1582:
#line 7615 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1583:
#line 7618 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1584:
#line 7621 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1585:
#line 7624 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1587:
#line 7632 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1588:
#line 7635 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1590:
#line 7641 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1592:
#line 7647 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1593:
#line 7650 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1594:
#line 7653 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1595:
#line 7656 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1596:
#line 7659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1597:
#line 7662 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
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
#line 7673 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1602:
#line 7680 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1606:
#line 7686 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1607:
#line 7687 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1608:
#line 7692 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1609:
#line 7695 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7699 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7705 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1612:
#line 7706 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1613:
#line 7707 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1614:
#line 7708 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1619:
#line 7728 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1621:
#line 7732 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1622:
#line 7733 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1624:
#line 7736 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1625:
#line 7737 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1626:
#line 7746 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1633:
#line 7760 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1634:
#line 7762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1635:
#line 7764 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1637:
#line 7767 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1639:
#line 7770 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1643:
#line 7775 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1644:
#line 7777 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1645:
#line 7780 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1646:
#line 7781 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1647:
#line 7788 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1651:
#line 7793 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1655:
#line 7809 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1656:
#line 7816 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1657:
#line 7820 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1658:
#line 7821 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1659:
#line 7822 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1660:
#line 7830 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1661:
#line 7831 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1662:
#line 7832 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1663:
#line 7843 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1664:
#line 7850 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1665:
#line 7855 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1666:
#line 7856 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1667:
#line 7857 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1668:
#line 7865 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1669:
#line 7866 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1670:
#line 7867 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1672:
#line 7893 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1673:
#line 7894 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1674:
#line 7895 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1675:
#line 7899 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1676:
#line 7902 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1677:
#line 7908 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1678:
#line 7913 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1679:
#line 7918 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1681:
#line 7929 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1685:
#line 7947 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1686:
#line 7950 "fgl.yacc"
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

  case 1687:
#line 7963 "fgl.yacc"
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

  case 1688:
#line 7978 "fgl.yacc"
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

  case 1689:
#line 7990 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1690:
#line 7992 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1691:
#line 7995 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1692:
#line 7995 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1693:
#line 7995 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1694:
#line 7995 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1695:
#line 7995 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1696:
#line 7995 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1697:
#line 7996 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1698:
#line 7999 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1713:
#line 8017 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1714:
#line 8020 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1715:
#line 8021 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1716:
#line 8022 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1717:
#line 8026 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1718:
#line 8034 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1719:
#line 8034 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1720:
#line 8040 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1721:
#line 8040 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1722:
#line 8047 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1723:
#line 8047 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
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
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1726:
#line 8061 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1727:
#line 8062 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1728:
#line 8063 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1729:
#line 8066 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1730:
#line 8066 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1732:
#line 8070 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1733:
#line 8071 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1734:
#line 8082 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1735:
#line 8085 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1736:
#line 8091 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1737:
#line 8096 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1738:
#line 8104 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1739:
#line 8116 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1740:
#line 8117 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1741:
#line 8120 "fgl.yacc"
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

  case 1742:
#line 8135 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1743:
#line 8146 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1744:
#line 8149 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1745:
#line 8157 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1746:
#line 8166 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1747:
#line 8169 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1748:
#line 8173 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1749:
#line 8176 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1750:
#line 8177 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1752:
#line 8190 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1753:
#line 8191 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1754:
#line 8200 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1755:
#line 8209 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1756:
#line 8214 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1757:
#line 8215 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1758:
#line 8216 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1759:
#line 8217 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1760:
#line 8224 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1761:
#line 8227 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1762:
#line 8233 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1763:
#line 8236 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1764:
#line 8243 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1765:
#line 8255 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1766:
#line 8264 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1767:
#line 8267 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1768:
#line 8270 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1769:
#line 8276 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1770:
#line 8284 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1771:
#line 8287 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1772:
#line 8288 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1773:
#line 8289 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1774:
#line 8290 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1775:
#line 8291 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1776:
#line 8294 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1777:
#line 8301 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1778:
#line 8303 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1779:
#line 8305 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1780:
#line 8307 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1781:
#line 8309 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1782:
#line 8310 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1783:
#line 8311 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1784:
#line 8312 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1785:
#line 8313 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1786:
#line 8314 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1787:
#line 8315 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1788:
#line 8317 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1789:
#line 8319 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1790:
#line 8321 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1791:
#line 8323 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1792:
#line 8325 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1793:
#line 8327 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1794:
#line 8329 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1795:
#line 8330 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1796:
#line 8332 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1797:
#line 8333 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1798:
#line 8334 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1799:
#line 8340 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1800:
#line 8341 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1802:
#line 8351 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1803:
#line 8359 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1804:
#line 8363 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1805:
#line 8370 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1806:
#line 8370 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1808:
#line 8374 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1809:
#line 8379 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1810:
#line 8379 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1812:
#line 8383 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1813:
#line 8387 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1816:
#line 8396 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1817:
#line 8396 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1822:
#line 8415 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1823:
#line 8416 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1826:
#line 8424 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1827:
#line 8430 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1830:
#line 8449 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1831:
#line 8450 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1832:
#line 8451 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1833:
#line 8452 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1834:
#line 8453 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1835:
#line 8454 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1836:
#line 8458 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1837:
#line 8459 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1838:
#line 8460 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1840:
#line 8465 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1841:
#line 8466 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1842:
#line 8470 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1843:
#line 8486 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1844:
#line 8487 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1845:
#line 8488 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1846:
#line 8492 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1847:
#line 8506 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1848:
#line 8510 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1850:
#line 8519 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1852:
#line 8524 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1853:
#line 8525 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1854:
#line 8849 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1855:
#line 8849 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1856:
#line 8856 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1857:
#line 8856 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1858:
#line 8944 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1859:
#line 8948 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1860:
#line 8950 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1861:
#line 8957 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1862:
#line 8961 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1863:
#line 8967 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1864:
#line 8975 "fgl.yacc"
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

  case 1865:
#line 8985 "fgl.yacc"
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
#line 8995 "fgl.yacc"
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
#line 9007 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1868:
#line 9010 "fgl.yacc"
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
#line 9029 "fgl.yacc"
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
#line 9055 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1871:
#line 9058 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1873:
#line 9067 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1874:
#line 9072 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1875:
#line 9075 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1876:
#line 9083 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1877:
#line 9091 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1878:
#line 9104 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1879:
#line 9107 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1880:
#line 9115 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1881:
#line 9118 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1882:
#line 9121 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1883:
#line 9129 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1884:
#line 9133 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1885:
#line 9134 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1886:
#line 9135 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1887:
#line 9136 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1888:
#line 9137 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1889:
#line 9138 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1890:
#line 9139 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1891:
#line 9140 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1892:
#line 9144 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1893:
#line 9145 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1894:
#line 9146 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1895:
#line 9147 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1896:
#line 9148 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1897:
#line 9154 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1898:
#line 9155 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1899:
#line 9156 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1900:
#line 9157 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1901:
#line 9158 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1902:
#line 9159 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1903:
#line 9160 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1904:
#line 9161 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1905:
#line 9162 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1906:
#line 9163 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1907:
#line 9164 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1908:
#line 9165 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1909:
#line 9166 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1910:
#line 9167 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1911:
#line 9168 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1912:
#line 9169 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1913:
#line 9174 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1914:
#line 9180 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1915:
#line 9181 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1916:
#line 9189 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1917:
#line 9191 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1919:
#line 9197 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1920:
#line 9201 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1921:
#line 9205 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1922:
#line 9221 "fgl.yacc"
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

  case 1923:
#line 9235 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1924:
#line 9241 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1925:
#line 9243 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1929:
#line 9257 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1930:
#line 9260 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1931:
#line 9267 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1932:
#line 9270 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1933:
#line 9300 "fgl.yacc"
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

  case 1934:
#line 9325 "fgl.yacc"
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

  case 1935:
#line 9380 "fgl.yacc"
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

  case 1936:
#line 9415 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1937:
#line 9424 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1938:
#line 9435 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1939:
#line 9438 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1940:
#line 9444 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1941:
#line 9457 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1942:
#line 9471 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1943:
#line 9474 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1944:
#line 9478 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1945:
#line 9493 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1946:
#line 9493 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1947:
#line 9499 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1948:
#line 9500 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1949:
#line 9503 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1950:
#line 9504 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1951:
#line 9505 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1952:
#line 9506 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1953:
#line 9507 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1954:
#line 9508 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1955:
#line 9509 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1956:
#line 9520 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1957:
#line 9524 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1958:
#line 9528 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1959:
#line 9532 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1960:
#line 9537 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1961:
#line 9541 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1962:
#line 9546 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1964:
#line 9554 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1966:
#line 9560 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1967:
#line 9566 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1968:
#line 9570 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1973:
#line 9588 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1974:
#line 9595 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1975:
#line 9605 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1976:
#line 9605 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18977 "y.tab.c"

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



