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
     NAME = 1720,
     UMINUS = 1721,
     COMMA = 1622,
     KW_OR = 1662,
     KW_AND = 1617,
     KW_USING = 1554,
     NOT = 1637,
     MATCHES = 1434,
     POWER = 1540,
     LESS_THAN = 1536,
     GREATER_THAN = 1451,
     EQUAL = 1612,
     GREATER_THAN_EQ = 1353,
     LESS_THAN_EQ = 1410,
     NOT_EQUAL = 1482,
     PLUS = 1648,
     MINUS = 1635,
     MULTIPLY = 1541,
     DIVIDE = 1568,
     MOD = 1636,
     COMMAND = 1417,
     NUMBER_VALUE = 1722,
     CHAR_VALUE = 1723,
     INT_VALUE = 1724,
     NAMED_GEN = 1725,
     CLINE = 1726,
     SQLLINE = 1727,
     KW_CSTART = 1728,
     KW_CEND = 1729,
     USER_DTYPE = 1730,
     SQL_TEXT = 1731,
     KW_WHENEVER_SET = 1732,
     COMMENT = 1733,
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
     SETBL = 1283,
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
     SETL = 1498,
     SHARED = 1499,
     SPACES = 1500,
     UNIQUE = 1501,
     UNLOCK = 1502,
     UPDATE = 1503,
     VALUES = 1504,
     YELLOW = 1505,
     AFTER = 1506,
     KWLINE = 1507,
     KW_NULL = 1508,
     KW_TRUE = 1509,
     SINGLE_KEY = 1510,
     ALTER = 1511,
     ARRAY = 1512,
     ASCII = 1513,
     AUDIT = 1514,
     BLACK = 1515,
     BLINK = 1516,
     CHECK = 1517,
     CLEAR = 1518,
     CLOSE = 1519,
     CODE_C = 1520,
     COUNT = 1521,
     DEFER = 1522,
     ERROR = 1523,
     EVERY = 1524,
     FETCH = 1525,
     FIRST = 1526,
     FLOAT = 1527,
     FLUSH = 1528,
     FOUND = 1529,
     GRANT = 1530,
     GREEN = 1531,
     GROUP = 1532,
     INDEX = 1533,
     KWFORM = 1534,
     LABEL = 1535,
     LOCAL = 1537,
     MONEY = 1538,
     MONTH = 1539,
     ORDER = 1542,
     OUTER = 1543,
     PAUSE = 1544,
     PRINT_IMAGE = 1545,
     PRINT_FILE = 1546,
     PRINT = 1547,
     RIGHT = 1548,
     DOUBLE_COLON = 1549,
     SEMICOLON = 1550,
     SLEEP = 1551,
     TUPLE = 1552,
     UNION = 1553,
     WHERE = 1555,
     WHILE = 1556,
     WHITE = 1557,
     CCODE = 1558,
     ANSI = 1559,
     BLUE = 1560,
     BOLD = 1561,
     BYTE = 1562,
     FCALL = 1563,
     CASE = 1564,
     CYAN = 1565,
     DATE = 1566,
     DESC = 1567,
     KWDOWN = 1569,
     TAB = 1570,
     DROP = 1571,
     ELSE = 1572,
     EXEC = 1573,
     EXIT = 1574,
     FREE = 1575,
     FROM = 1576,
     GOTO = 1577,
     HELP_FILE = 1578,
     LANG_FILE = 1579,
     HELP = 1580,
     HIDE = 1581,
     HOUR = 1582,
     INTO = 1583,
     LAST = 1584,
     LEFT = 1585,
     LIKE = 1586,
     MAIN = 1587,
     MENU = 1588,
     MODE = 1589,
     NEED = 1590,
     NEXT = 1591,
     NOCR = 1592,
     OPEN = 1593,
     QUIT = 1594,
     REAL = 1595,
     ROWS = 1596,
     SHOW = 1597,
     SIZE = 1598,
     SKIP = 1599,
     SOME = 1600,
     STEP = 1601,
     STOP = 1602,
     TEMP = 1603,
     TEXT = 1604,
     THEN = 1605,
     USER = 1606,
     WAIT = 1607,
     WHEN = 1608,
     WITH = 1609,
     WORK = 1610,
     YEAR = 1611,
     KW_IS = 1613,
     XSET = 1614,
     ADD = 1615,
     ALL = 1616,
     ANY = 1618,
     ASC = 1619,
     AVG = 1620,
     COLON = 1621,
     DAY = 1623,
     DBA = 1624,
     DEC = 1625,
     DIM = 1626,
     FKEY = 1627,
     FOR = 1628,
     KEY = 1629,
     KWNO = 1630,
     LET = 1631,
     LOG = 1632,
     XMAX = 1633,
     XMIN = 1634,
     PAD = 1638,
     PUT = 1639,
     RED = 1640,
     ROW = 1641,
     RUN = 1642,
     SQL = 1643,
     SUM = 1644,
     TOP = 1645,
     USE = 1646,
     ATSIGN = 1647,
     AS_TIFF = 1649,
     AS_GIF = 1650,
     AS_PNG = 1651,
     AS_JPEG = 1652,
     AS = 1653,
     AT = 1654,
     BY = 1655,
     DOT = 1656,
     GO = 1657,
     IF = 1658,
     IN = 1659,
     OF = 1660,
     ON = 1661,
     TO = 1663,
     KWUP = 1664,
     FONT_NAME = 1665,
     FONT_SIZE = 1666,
     PAPER_SIZE_IS_LETTER = 1667,
     PAPER_SIZE_IS_LEGAL = 1668,
     PAPER_SIZE_IS_A5 = 1669,
     PAPER_SIZE_IS_A4 = 1670,
     PAPER_SIZE_IS_LETTER_L = 1671,
     PAPER_SIZE_IS_LEGAL_L = 1672,
     PAPER_SIZE_IS_A5_L = 1673,
     PAPER_SIZE_IS_A4_L = 1674,
     FORMHANDLER = 1675,
     END_FORMHANDLER = 1676,
     BEFORE_EVENT = 1677,
     BEFORE_OPEN_FORM = 1678,
     AFTER_EVENT = 1679,
     BEFORE_CLOSE_FORM = 1680,
     BEFORE_ANY = 1681,
     AFTER_ANY = 1682,
     MENUHANDLER = 1683,
     END_MENUHANDLER = 1684,
     BEFORE_SHOW_MENU = 1685,
     DISABLE_PROGRAM = 1686,
     DISABLE_ALL = 1687,
     BUTTONS = 1688,
     CHECK_MENUITEM = 1689,
     DISABLE_FORM = 1690,
     DISABLE_MENUITEMS = 1691,
     DISABLE = 1692,
     ENABLE_FORM = 1693,
     ENABLE_MENUITEMS = 1694,
     ENABLE = 1695,
     KWFIELD = 1696,
     ICON = 1697,
     MESSAGEBOX = 1698,
     TO_DEFAULTS = 1699,
     UNCHECK_MENUITEM = 1700,
     BEFORE = 1701,
     INPUT = 1702,
     END = 1703,
     INT_TO_ID = 1704,
     TIMEOUT = 1705,
     OFF = 1706,
     WITH_1_DIMENSION = 1707,
     WITH_2_DIMENSION = 1708,
     WITH_3_DIMENSION = 1709,
     TILDE = 1710,
     ILIKE = 1711,
     FGL_ISDYNARR_ALLOCATED = 1712,
     FGL_DYNARR_EXTENTSIZE = 1713,
     FILLFACTOR = 1714,
     END_CLASS = 1715,
     KW_CLASS = 1716,
     EXTENDS = 1717,
     PIPE = 1718
   };
#endif
#define NAME 1720
#define UMINUS 1721
#define COMMA 1622
#define KW_OR 1662
#define KW_AND 1617
#define KW_USING 1554
#define NOT 1637
#define MATCHES 1434
#define POWER 1540
#define LESS_THAN 1536
#define GREATER_THAN 1451
#define EQUAL 1612
#define GREATER_THAN_EQ 1353
#define LESS_THAN_EQ 1410
#define NOT_EQUAL 1482
#define PLUS 1648
#define MINUS 1635
#define MULTIPLY 1541
#define DIVIDE 1568
#define MOD 1636
#define COMMAND 1417
#define NUMBER_VALUE 1722
#define CHAR_VALUE 1723
#define INT_VALUE 1724
#define NAMED_GEN 1725
#define CLINE 1726
#define SQLLINE 1727
#define KW_CSTART 1728
#define KW_CEND 1729
#define USER_DTYPE 1730
#define SQL_TEXT 1731
#define KW_WHENEVER_SET 1732
#define COMMENT 1733
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
#define SETBL 1283
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
#define SETL 1498
#define SHARED 1499
#define SPACES 1500
#define UNIQUE 1501
#define UNLOCK 1502
#define UPDATE 1503
#define VALUES 1504
#define YELLOW 1505
#define AFTER 1506
#define KWLINE 1507
#define KW_NULL 1508
#define KW_TRUE 1509
#define SINGLE_KEY 1510
#define ALTER 1511
#define ARRAY 1512
#define ASCII 1513
#define AUDIT 1514
#define BLACK 1515
#define BLINK 1516
#define CHECK 1517
#define CLEAR 1518
#define CLOSE 1519
#define CODE_C 1520
#define COUNT 1521
#define DEFER 1522
#define ERROR 1523
#define EVERY 1524
#define FETCH 1525
#define FIRST 1526
#define FLOAT 1527
#define FLUSH 1528
#define FOUND 1529
#define GRANT 1530
#define GREEN 1531
#define GROUP 1532
#define INDEX 1533
#define KWFORM 1534
#define LABEL 1535
#define LOCAL 1537
#define MONEY 1538
#define MONTH 1539
#define ORDER 1542
#define OUTER 1543
#define PAUSE 1544
#define PRINT_IMAGE 1545
#define PRINT_FILE 1546
#define PRINT 1547
#define RIGHT 1548
#define DOUBLE_COLON 1549
#define SEMICOLON 1550
#define SLEEP 1551
#define TUPLE 1552
#define UNION 1553
#define WHERE 1555
#define WHILE 1556
#define WHITE 1557
#define CCODE 1558
#define ANSI 1559
#define BLUE 1560
#define BOLD 1561
#define BYTE 1562
#define FCALL 1563
#define CASE 1564
#define CYAN 1565
#define DATE 1566
#define DESC 1567
#define KWDOWN 1569
#define TAB 1570
#define DROP 1571
#define ELSE 1572
#define EXEC 1573
#define EXIT 1574
#define FREE 1575
#define FROM 1576
#define GOTO 1577
#define HELP_FILE 1578
#define LANG_FILE 1579
#define HELP 1580
#define HIDE 1581
#define HOUR 1582
#define INTO 1583
#define LAST 1584
#define LEFT 1585
#define LIKE 1586
#define MAIN 1587
#define MENU 1588
#define MODE 1589
#define NEED 1590
#define NEXT 1591
#define NOCR 1592
#define OPEN 1593
#define QUIT 1594
#define REAL 1595
#define ROWS 1596
#define SHOW 1597
#define SIZE 1598
#define SKIP 1599
#define SOME 1600
#define STEP 1601
#define STOP 1602
#define TEMP 1603
#define TEXT 1604
#define THEN 1605
#define USER 1606
#define WAIT 1607
#define WHEN 1608
#define WITH 1609
#define WORK 1610
#define YEAR 1611
#define KW_IS 1613
#define XSET 1614
#define ADD 1615
#define ALL 1616
#define ANY 1618
#define ASC 1619
#define AVG 1620
#define COLON 1621
#define DAY 1623
#define DBA 1624
#define DEC 1625
#define DIM 1626
#define FKEY 1627
#define FOR 1628
#define KEY 1629
#define KWNO 1630
#define LET 1631
#define LOG 1632
#define XMAX 1633
#define XMIN 1634
#define PAD 1638
#define PUT 1639
#define RED 1640
#define ROW 1641
#define RUN 1642
#define SQL 1643
#define SUM 1644
#define TOP 1645
#define USE 1646
#define ATSIGN 1647
#define AS_TIFF 1649
#define AS_GIF 1650
#define AS_PNG 1651
#define AS_JPEG 1652
#define AS 1653
#define AT 1654
#define BY 1655
#define DOT 1656
#define GO 1657
#define IF 1658
#define IN 1659
#define OF 1660
#define ON 1661
#define TO 1663
#define KWUP 1664
#define FONT_NAME 1665
#define FONT_SIZE 1666
#define PAPER_SIZE_IS_LETTER 1667
#define PAPER_SIZE_IS_LEGAL 1668
#define PAPER_SIZE_IS_A5 1669
#define PAPER_SIZE_IS_A4 1670
#define PAPER_SIZE_IS_LETTER_L 1671
#define PAPER_SIZE_IS_LEGAL_L 1672
#define PAPER_SIZE_IS_A5_L 1673
#define PAPER_SIZE_IS_A4_L 1674
#define FORMHANDLER 1675
#define END_FORMHANDLER 1676
#define BEFORE_EVENT 1677
#define BEFORE_OPEN_FORM 1678
#define AFTER_EVENT 1679
#define BEFORE_CLOSE_FORM 1680
#define BEFORE_ANY 1681
#define AFTER_ANY 1682
#define MENUHANDLER 1683
#define END_MENUHANDLER 1684
#define BEFORE_SHOW_MENU 1685
#define DISABLE_PROGRAM 1686
#define DISABLE_ALL 1687
#define BUTTONS 1688
#define CHECK_MENUITEM 1689
#define DISABLE_FORM 1690
#define DISABLE_MENUITEMS 1691
#define DISABLE 1692
#define ENABLE_FORM 1693
#define ENABLE_MENUITEMS 1694
#define ENABLE 1695
#define KWFIELD 1696
#define ICON 1697
#define MESSAGEBOX 1698
#define TO_DEFAULTS 1699
#define UNCHECK_MENUITEM 1700
#define BEFORE 1701
#define INPUT 1702
#define END 1703
#define INT_TO_ID 1704
#define TIMEOUT 1705
#define OFF 1706
#define WITH_1_DIMENSION 1707
#define WITH_2_DIMENSION 1708
#define WITH_3_DIMENSION 1709
#define TILDE 1710
#define ILIKE 1711
#define FGL_ISDYNARR_ALLOCATED 1712
#define FGL_DYNARR_EXTENTSIZE 1713
#define FILLFACTOR 1714
#define END_CLASS 1715
#define KW_CLASS 1716
#define EXTENDS 1717
#define PIPE 1718




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
#line 1728 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1740 "y.tab.c"

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
#define YYLAST   9390

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  736
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  876
/* YYNRULES -- Number of rules. */
#define YYNRULES  2064
/* YYNRULES -- Number of states. */
#define YYNSTATES  3502

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1733

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
     560,   561,   562,   563,   564,   565,    12,   566,   567,   568,
      11,    20,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,     8,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,    21,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,    14,   637,   638,   639,   640,     7,   641,   642,
     643,   644,     5,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,    19,    22,     9,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,    18,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,     6,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,     2,
       3,     4,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35
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
    1118,     0,    -1,   256,    -1,   253,    -1,   187,   741,   482,
     650,   742,    -1,   198,    -1,  1181,    -1,    26,    -1,   743,
      -1,   742,     5,   743,    -1,  1025,    -1,   486,   744,   449,
      -1,   744,   745,   744,    -1,    26,    -1,   746,    26,    -1,
    1181,    -1,   965,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   748,
      -1,    -1,   331,   486,   749,   750,   449,    -1,   623,   486,
      26,     5,    26,   449,    -1,   751,    -1,   750,     5,   751,
      -1,   545,    -1,   586,    -1,   591,    -1,   561,    -1,   466,
      -1,   659,    -1,   583,    -1,   535,    -1,   472,    -1,   546,
      -1,   404,    -1,   587,    -1,   511,    -1,   391,    -1,   648,
      -1,   155,    -1,  1097,    -1,    -1,   753,    -1,    -1,   331,
     486,   754,   755,   449,    -1,   756,    -1,   755,     5,   756,
      -1,   751,    -1,   487,    -1,   657,    25,    -1,   259,  1011,
      -1,   388,  1011,    -1,   341,  1011,    -1,   396,  1011,    -1,
     350,  1011,    -1,   316,  1011,    -1,   589,   758,    -1,   954,
     403,  1181,    -1,    -1,   346,   486,   973,   449,   403,   759,
    1199,    -1,   163,   486,  1025,     5,    25,     5,    25,   449,
      -1,   463,   486,  1017,   449,   403,  1181,    -1,  1322,    -1,
     249,   486,   973,   449,   403,  1181,    -1,    -1,    -1,  1181,
     644,  1025,   486,   760,   776,   449,   761,   774,    -1,    -1,
      -1,  1181,    36,  1025,   486,   762,   776,   449,   763,   774,
      -1,    -1,    -1,    -1,  1025,   486,   764,   776,   765,   449,
     766,   774,    -1,    -1,    -1,   529,  1531,   677,  1531,   486,
     767,   776,   768,   449,   774,    -1,    -1,    -1,  1025,   576,
    1025,   486,   769,   776,   770,   449,   774,    -1,    -1,    -1,
      -1,   423,   779,   644,   780,   514,   741,   482,   486,   771,
     776,   772,   449,   773,   775,    -1,    -1,   403,  1199,    -1,
      -1,   403,  1199,    -1,   220,    -1,    -1,   777,    -1,   778,
      -1,   777,     5,   778,    -1,   923,    -1,   538,    -1,    25,
      -1,  1025,    -1,  1025,    -1,  1025,   674,  1025,    -1,    -1,
     590,   930,   782,   785,   789,   786,    -1,    -1,   590,   783,
     784,   787,   786,    -1,   791,    -1,   784,   791,    -1,   793,
      -1,   785,   793,    -1,   418,    -1,    -1,    -1,   398,   788,
    1606,    -1,    -1,    -1,   398,   790,  1606,    -1,    -1,   633,
     930,   792,  1606,    -1,    -1,   633,   930,   794,  1606,    -1,
      -1,    -1,    -1,   733,  1025,   796,   799,   797,   829,   798,
     800,   732,    -1,    -1,   734,  1025,    -1,   801,    -1,   800,
     801,    -1,  1133,    -1,   335,  1022,    -1,   258,  1020,    -1,
     141,  1020,    -1,   225,    -1,   242,  1537,    -1,   549,  1019,
      -1,    30,   804,    31,    -1,   805,    -1,   807,    -1,   806,
      -1,   805,   806,    -1,    29,    -1,   808,    -1,   807,   808,
      -1,    28,    -1,    -1,    -1,   379,   810,   812,   811,   813,
      -1,   442,  1181,   679,   814,  1069,  1096,   747,    -1,  1181,
     679,   814,  1069,   601,   973,  1096,   747,    -1,    -1,   816,
     248,    -1,   815,    -1,   814,     5,   815,    -1,  1025,    -1,
    1025,   674,  1025,    -1,  1025,   674,    20,    -1,   817,    -1,
     816,   817,    -1,    -1,   327,   823,   818,  1606,    -1,    -1,
     330,   824,   819,  1606,    -1,    -1,  1099,   820,  1606,    -1,
      -1,   223,   821,  1606,    -1,    -1,   221,   822,  1606,    -1,
    1029,    -1,   823,     5,  1029,    -1,  1029,    -1,   824,     5,
    1029,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,   486,   923,   827,   449,    -1,    -1,
       5,   874,   680,   877,    -1,   213,    -1,   336,    -1,    -1,
     830,    -1,   831,    -1,   830,   831,    -1,    -1,    -1,   493,
     832,   834,   833,  1291,    -1,   887,    -1,   837,    -1,   834,
       5,   837,    -1,    -1,   836,  1025,    -1,   412,   835,   886,
      25,    -1,   412,   835,   886,  1025,    -1,   412,   835,   886,
    1031,    -1,   412,   835,   886,    26,    -1,   841,   860,    -1,
      -1,   835,   412,   838,   839,    -1,    26,    -1,    25,    -1,
    1031,    -1,    19,    26,    -1,   835,    -1,   840,    -1,   841,
       5,   840,    -1,    -1,   376,    -1,    -1,   724,    -1,   725,
      -1,   726,    -1,    -1,   542,   514,   851,   482,   845,   678,
     860,    -1,    -1,    44,   843,   846,   678,   860,    -1,    -1,
     375,   842,   848,    26,   849,   359,   514,   850,   482,   847,
     678,   860,    -1,   486,    -1,   513,    -1,   449,    -1,   481,
      -1,    26,    -1,   852,     5,   852,     5,   852,    -1,   852,
       5,   852,    -1,   852,    -1,    26,    -1,   835,    -1,   835,
     644,   835,    -1,   835,   666,   835,   644,   835,    -1,    -1,
     519,   855,   834,   340,    -1,    -1,   317,   856,   853,   674,
      20,    -1,    -1,   393,   857,   853,   315,   486,   858,   449,
      -1,   859,    -1,   858,     5,   859,    -1,   835,    -1,   862,
      -1,    -1,   116,    -1,    -1,    -1,   863,   865,   864,   861,
      -1,   844,    -1,   854,    -1,   376,    -1,   377,    -1,   376,
     486,    26,   449,    -1,   377,   486,    26,   449,    -1,   479,
     486,    26,   449,    -1,   479,   486,    26,     5,    26,   449,
      -1,   378,   486,    26,   449,    -1,   378,   486,    26,     5,
      26,   449,    -1,   464,    -1,   671,   835,    -1,   438,    -1,
     564,    -1,   147,    -1,   454,    -1,   454,   486,    26,   449,
      -1,   454,   486,    26,     5,    26,   449,    -1,   567,    -1,
     567,   486,    26,   449,    -1,   567,   486,    26,     5,    26,
     449,    -1,    -1,   557,   866,   869,    -1,    -1,   121,   867,
     869,    -1,    -1,   356,   868,   869,    -1,   592,    -1,   588,
      -1,   137,    -1,   138,    -1,   629,    -1,   415,   872,    -1,
     427,   873,    -1,   870,    -1,    32,    -1,    -1,   486,    26,
     449,    -1,   611,   853,   674,   871,    -1,   835,    -1,    -1,
     874,   680,   877,    -1,   882,   680,   885,    -1,    -1,   875,
     876,    -1,   636,    -1,   568,    -1,   645,    -1,   607,    -1,
     509,    -1,   525,    -1,   424,   879,    -1,    -1,   878,   876,
      -1,    -1,   486,   881,   449,    -1,    -1,   486,    26,   449,
      -1,    26,    -1,    -1,   883,   884,   880,    -1,   636,    -1,
     568,    -1,   645,    -1,   607,    -1,   509,    -1,   525,    -1,
     424,   879,    -1,   884,    -1,    -1,    14,    -1,    -1,   293,
    1025,   888,   671,   889,    -1,   891,    -1,   894,    -1,   376,
      -1,   376,   486,    26,   449,    -1,   479,   486,    26,   449,
      -1,   479,   486,    26,     5,    26,   449,    -1,   464,    -1,
     438,    -1,   564,    -1,   454,    -1,   454,   486,    26,   449,
      -1,   454,   486,    26,     5,    26,   449,    -1,   567,    -1,
     567,   486,    26,   449,    -1,   567,   486,    26,     5,    26,
     449,    -1,   557,    -1,   356,    -1,   592,    -1,   588,    -1,
     629,    -1,   415,   872,    -1,   427,   873,    -1,   890,    -1,
     611,   853,   674,   871,    -1,    -1,   542,   514,   851,   482,
     892,   678,   889,    -1,    -1,   375,   842,   848,    26,   849,
     359,   514,   850,   482,   893,   678,   889,    -1,    -1,   519,
     895,   897,   340,    -1,    -1,   317,   896,  1025,   674,    20,
      -1,   898,    -1,   897,     5,   898,    -1,   899,   889,    -1,
     900,    -1,   899,     5,   900,    -1,  1025,    -1,    -1,   672,
    1015,    -1,   128,  1025,    -1,   126,    -1,   680,   973,    -1,
     680,   564,  1025,   713,   973,    -1,   680,   564,  1025,   447,
      -1,   130,  1025,    -1,   214,   946,  1199,   909,    -1,   457,
     946,   928,   901,   909,    -1,   267,  1022,   909,    -1,    -1,
      -1,   245,   906,  1206,   680,  1025,   674,    20,   908,   747,
     907,   910,    -1,    -1,   523,  1016,    -1,   747,    -1,    -1,
     911,   295,    -1,   295,    -1,   912,    -1,   911,   912,    -1,
      -1,   410,   913,  1606,    -1,    -1,   406,   914,  1606,    -1,
      -1,  1099,   915,  1606,    -1,    46,  1181,    -1,    47,  1181,
      -1,    45,  1181,    -1,   553,   946,   929,   747,    -1,   553,
     946,   929,   747,   123,    -1,   271,    -1,   271,   930,    -1,
     343,    -1,   342,    -1,   270,    -1,   422,    -1,   230,    -1,
     269,    -1,   387,    -1,   386,    -1,   300,    -1,   227,    -1,
     226,    -1,   204,    -1,   260,    -1,   188,    -1,   203,    -1,
     244,    -1,   211,    -1,   931,    -1,   935,    -1,   965,    -1,
     923,   924,    -1,   966,    -1,   968,    -1,   932,    -1,    19,
     923,    -1,    18,   923,    -1,   937,    -1,   945,    -1,   939,
      -1,   530,    -1,   825,    -1,   940,    -1,   941,    -1,   942,
      -1,   943,    -1,   944,    -1,    52,   923,    -1,   946,    -1,
     946,   927,    -1,   930,    -1,   538,    -1,   926,    -1,   927,
       5,   926,    -1,   930,    -1,   928,     5,   930,    -1,   930,
      -1,   929,     5,   930,    -1,   923,    -1,     9,   923,    -1,
     539,    -1,   483,    -1,   486,   923,   449,    -1,   498,   486,
    1511,   449,    -1,   351,   486,  1511,   449,    -1,    25,    -1,
    1031,    -1,    26,    -1,   934,    -1,  1181,    -1,  1181,   476,
    1181,    -1,   933,    -1,   489,   923,    -1,   450,   923,    -1,
    1294,    -1,    -1,   562,   936,  1294,    -1,     7,   923,    -1,
       6,   923,    -1,   923,    -1,   938,     5,   923,    -1,   677,
     486,  1511,   449,    -1,   484,   486,  1511,   449,    -1,   677,
     486,   946,   938,   449,    -1,   484,   486,   946,   938,   449,
      -1,   444,    -1,   306,    -1,    10,   923,    -1,   309,   923,
      -1,    10,   923,   497,    25,    -1,   309,   923,   497,    25,
      -1,   611,   923,    -1,   429,   923,    -1,   611,   923,   497,
      25,    -1,   429,   923,   497,    25,    -1,   448,    -1,     8,
     923,    -1,    18,   923,    -1,    19,   923,    -1,    20,   923,
      -1,    21,   923,    -1,    22,   923,    -1,    11,   923,    -1,
      14,   923,    -1,   512,   923,    -1,    12,   923,    -1,    13,
     923,    -1,    17,   923,    -1,    16,   923,    -1,    15,   923,
      -1,    -1,    -1,    -1,  1025,   486,   948,   776,   949,   449,
      -1,    -1,    -1,  1025,   576,  1025,   486,   950,   776,   951,
     449,    -1,    -1,    -1,  1025,    36,  1025,   486,   952,   776,
     953,   449,    -1,    -1,    -1,   592,   486,   955,   923,   956,
     449,    -1,    -1,    -1,   568,   486,   957,   923,   958,   449,
      -1,    -1,    -1,   645,   486,   959,   923,   960,   449,    -1,
      -1,    -1,   636,   486,   961,   923,   962,   449,    -1,   427,
     486,   969,   449,   964,    -1,   415,   486,    25,   449,   963,
      -1,   415,   486,    26,   449,   963,    -1,   415,   486,    24,
     449,   963,    -1,   415,   486,    26,   644,    26,   449,   963,
      -1,   415,   486,    26,   644,    24,   449,   963,    -1,   415,
     486,    26,   644,    26,   644,    26,   449,   963,    -1,   415,
     486,    26,   644,    26,   644,    24,   449,   963,    -1,   415,
     486,    26,    26,   449,   963,    -1,   415,   486,    26,    26,
     644,    26,   449,   963,    -1,   415,   486,    26,    26,   644,
      26,   644,    26,   449,   963,    -1,   415,   486,    26,    26,
     644,    26,   644,    24,   449,   963,    -1,   415,   486,    26,
      19,    26,   449,   963,    -1,   415,   486,    26,    19,    26,
      19,    26,   449,   963,    -1,   415,   486,    26,    19,    26,
      26,   449,   963,    -1,   415,   486,    26,    19,    26,    19,
      26,    26,   449,   963,    -1,   415,   486,    26,    19,    26,
      19,    26,    26,   644,    26,   449,   963,    -1,   415,   486,
      26,    19,    26,    19,    26,    26,   644,    26,   644,    26,
     449,   963,    -1,   415,   486,    26,    19,    26,    19,    26,
      26,   644,    26,   644,    24,   449,   963,    -1,   415,   486,
      26,    19,    26,    26,   644,    26,   449,   963,    -1,   415,
     486,    26,    19,    26,    26,   644,    26,   644,    26,   449,
     963,    -1,   415,   486,    26,    19,    26,    26,   644,    26,
     644,    24,   449,   963,    -1,    42,   486,  1181,   449,    -1,
     729,   486,  1181,   449,    -1,   730,   486,  1181,     5,    26,
     449,    -1,    -1,   876,   680,   876,    -1,   873,    -1,   954,
      -1,   346,   486,   973,   449,    -1,   156,   486,  1016,   449,
      -1,   129,   486,  1016,   449,    -1,   463,   486,   974,   449,
      -1,   249,   486,   973,   449,    -1,   117,   486,   973,   449,
      -1,   967,    -1,   947,    -1,  1488,    -1,   592,    -1,   478,
     486,   923,   449,    -1,   381,   486,   923,   449,    -1,   543,
     923,    -1,   499,   826,    -1,   923,   167,    -1,   923,   168,
      -1,   923,   169,    -1,    25,    -1,   970,    -1,    19,   970,
      -1,   972,    -1,   971,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   644,    26,    -1,    26,    26,   644,    26,   644,
      26,    -1,    26,    26,   644,    26,   644,    24,    -1,    26,
     644,    26,    -1,    26,   644,    26,   644,    26,    -1,    26,
     644,    26,   644,    24,    -1,    26,   644,    24,    -1,    24,
      -1,    26,    -1,    26,    19,    26,    -1,  1016,    -1,   973,
       5,  1016,    -1,  1017,    -1,   974,     5,  1017,    -1,    -1,
      -1,    -1,   460,   976,  1019,   977,   979,  1390,   978,  1606,
     297,    -1,    -1,     8,   946,   928,    -1,    -1,    -1,   692,
    1025,   981,   829,   982,  1130,   984,   983,   989,   693,    -1,
      -1,   994,    -1,    -1,   985,    -1,   986,    -1,   985,   986,
      -1,    -1,   694,   987,  1606,    -1,    -1,   695,   988,  1606,
      -1,    -1,   990,    -1,   991,    -1,   990,   991,    -1,    -1,
     696,   992,  1606,    -1,    -1,   697,   993,  1606,    -1,   995,
     999,   383,    -1,   148,    -1,   148,   996,   601,   997,    -1,
     148,   442,   998,    -1,  1181,    -1,   996,     5,  1181,    -1,
    1025,    -1,   997,     5,  1025,    -1,  1181,    -1,   998,     5,
    1181,    -1,  1000,    -1,   999,  1000,    -1,    -1,   698,  1001,
    1606,    -1,    -1,   699,  1002,  1606,    -1,    -1,   718,   997,
    1003,  1606,    -1,    -1,   536,   997,  1004,  1606,    -1,    -1,
     679,   997,  1005,  1606,    -1,    -1,    -1,   650,  1181,    14,
     930,   680,   930,  1009,  1007,  1606,  1008,   298,    -1,    -1,
     626,   930,    -1,   600,  1018,    -1,   609,    19,    26,    -1,
     609,    -1,   556,    18,    26,    -1,   556,    -1,    26,    -1,
    1181,    -1,   723,    -1,    25,    -1,  1030,    -1,   930,    -1,
    1013,     5,  1013,    -1,  1014,    -1,  1025,    -1,   721,   486,
    1025,   449,    -1,  1025,   674,   721,   486,  1025,   449,    -1,
    1025,   514,   744,   482,    -1,  1025,   674,    20,    -1,  1025,
     514,   744,   482,   674,    20,    -1,  1025,   674,  1025,    -1,
    1025,   514,   744,   482,   674,  1025,    -1,  1016,    -1,    25,
      -1,  1026,    -1,  1026,    -1,  1026,    -1,  1026,    -1,  1026,
      -1,  1026,    -1,    -1,   605,    26,    -1,  1605,    -1,  1027,
      -1,  1605,    -1,   408,   486,  1028,   449,    -1,  1184,    -1,
      25,    -1,  1025,    -1,  1025,   514,   744,   482,    -1,  1025,
     674,    20,    -1,  1025,   514,   744,   482,   674,    20,    -1,
    1025,   674,  1025,    -1,  1025,   514,   744,   482,   674,  1025,
      -1,  1181,    -1,    24,    -1,   674,    26,    -1,   602,  1033,
      -1,  1025,    -1,   644,  1025,    -1,   706,  1035,    -1,  1036,
      -1,  1035,     5,  1036,    -1,  1025,    -1,   717,  1035,    -1,
     708,  1035,    -1,   709,   973,    -1,   707,  1022,   713,   973,
      -1,   711,  1035,    -1,   712,   973,    -1,   710,  1022,   713,
     973,    -1,    -1,   715,  1041,   928,  1046,  1048,  1050,  1042,
    1044,    -1,    -1,  1043,    -1,   703,    -1,   704,    -1,    -1,
    1045,    -1,   403,  1181,    -1,    -1,  1047,    -1,   447,   928,
      -1,    -1,  1049,    -1,   714,    26,    -1,    -1,  1051,    -1,
     705,    26,  1052,    -1,    -1,   456,    26,    -1,    -1,    -1,
     676,   930,   630,  1054,  1606,  1055,  1056,   496,    -1,    -1,
      -1,   597,  1057,  1606,    -1,    -1,    -1,   120,  1058,   930,
     630,  1059,  1606,  1056,    -1,   165,  1025,   486,    26,   449,
      -1,   111,  1025,    -1,    43,  1025,    -1,   133,  1025,    -1,
      -1,   347,  1210,  1064,   680,   538,    -1,   347,  1210,   611,
    1065,    -1,  1066,    -1,  1065,     5,  1066,    -1,  1067,   674,
    1484,    -1,  1067,   674,    20,    -1,  1480,    -1,    -1,  1070,
     383,    -1,   383,    -1,    -1,   208,    -1,  1071,    -1,  1070,
    1071,    -1,    -1,   327,  1085,  1072,  1606,    -1,    -1,   330,
    1086,  1073,  1606,    -1,    -1,   410,  1074,  1606,    -1,    -1,
     406,  1075,  1606,    -1,    -1,  1099,  1076,  1606,    -1,    -1,
     362,  1077,  1606,    -1,    -1,   332,  1078,  1606,    -1,    -1,
      53,  1079,  1606,    -1,    -1,    50,  1080,  1606,    -1,    -1,
      49,  1081,  1606,    -1,    -1,    48,  1082,  1606,    -1,    -1,
      56,  1083,  1606,    -1,    -1,    55,  1084,  1606,    -1,  1016,
      -1,  1085,     5,  1016,    -1,  1016,    -1,  1086,     5,  1016,
      -1,   371,  1089,    -1,   372,  1025,   713,  1089,    -1,   616,
      -1,   433,    -1,  1016,    -1,    -1,   719,  1092,  1091,  1068,
      -1,   442,  1199,  1069,  1024,   747,    -1,  1199,  1069,   601,
     973,  1024,   747,    -1,    -1,   542,  1206,  1069,   601,  1025,
     674,    20,  1024,  1093,   747,    -1,   524,   973,  1095,    -1,
     139,    26,    -1,   140,    26,    -1,   681,    -1,   594,    -1,
     139,  1181,    -1,   140,  1181,    -1,    -1,   605,    26,    -1,
    1098,    -1,    62,    25,    -1,   551,    14,    26,    -1,   551,
      14,  1181,    -1,    63,    14,    26,    -1,    63,    14,  1181,
      -1,    59,    -1,    61,    -1,    58,    -1,    60,    -1,    -1,
     485,  1100,  1105,    -1,   352,    -1,    -1,   651,  1102,  1105,
      -1,   360,  1107,    -1,   651,  1105,    -1,  1107,    -1,   486,
    1106,   449,    -1,  1107,    -1,  1106,     5,  1107,    -1,  1108,
      -1,   649,    -1,   369,    -1,   389,    -1,   361,    -1,   540,
      -1,   497,    -1,   681,    -1,   605,    -1,   594,    -1,   234,
      -1,   494,    -1,   505,    -1,   595,    -1,   610,    -1,   575,
      -1,   367,    -1,   368,    -1,    25,    -1,   565,    -1,    -1,
      -1,   653,  1111,  1204,  1112,    14,   946,  1113,    -1,   538,
      -1,   929,    -1,   276,  1181,    -1,   266,  1181,    -1,   279,
    1181,    -1,   506,  1202,   392,    -1,   506,  1202,   443,  1012,
      -1,  1119,    -1,  1120,    -1,   795,    -1,    -1,  1122,  1121,
    1125,    -1,    -1,  1123,    -1,  1124,    -1,  1123,  1124,    -1,
    1062,    -1,  1129,    -1,  1590,    -1,  1061,    -1,  1145,    -1,
    1131,    -1,  1144,    -1,    -1,  1126,    -1,  1128,    -1,  1126,
    1128,    -1,   124,  1025,    -1,  1133,    -1,  1139,    -1,  1304,
      -1,  1314,    -1,  1151,    -1,   980,    -1,   803,    -1,  1060,
      -1,  1590,    -1,   803,    -1,    -1,   803,    -1,   830,    -1,
     425,    -1,   118,    -1,    -1,    -1,    -1,    -1,  1132,  1134,
    1025,   486,  1135,  1197,   449,  1136,   829,  1137,  1130,  1606,
    1138,    -1,   268,    -1,    -1,    -1,   612,  1140,   829,  1141,
    1606,   419,    -1,   234,   925,    -1,   946,    -1,   946,   928,
      -1,   414,  1495,    -1,   522,  1495,    -1,  1146,    -1,  1147,
      -1,  1146,  1147,    -1,  1148,    -1,    -1,   462,  1149,  1150,
      -1,   829,   299,    -1,  1012,    -1,  1129,    -1,  1144,    -1,
      -1,    -1,   700,  1025,  1152,   829,  1153,  1154,   701,    -1,
    1155,    -1,  1154,  1155,    -1,    -1,   702,  1156,  1606,    -1,
      -1,   679,  1025,  1157,  1606,    -1,    -1,   613,  1159,  1174,
    1165,  1160,    -1,   420,    -1,    -1,   291,  1162,  1606,    -1,
      -1,    23,  1166,  1167,  1168,  1024,  1163,  1606,    -1,    -1,
      23,  1166,  1024,  1164,  1606,    -1,  1161,    -1,  1165,  1161,
      -1,    -1,  1101,    -1,    25,    -1,  1181,    -1,    -1,  1181,
      -1,    25,    -1,   308,  1172,    -1,   320,  1173,    -1,   303,
    1173,    -1,   640,    -1,    25,    -1,  1181,    -1,  1172,    -1,
    1173,     5,  1172,    -1,  1181,    -1,    25,    -1,  1178,  1176,
      -1,    -1,   748,  1179,    -1,  1180,    -1,  1177,    -1,  1047,
      -1,  1049,    -1,  1051,    -1,  1043,    -1,  1045,    -1,   428,
     946,   928,    -1,    -1,   123,    -1,   123,    -1,  1182,    -1,
    1184,    -1,   247,  1184,    -1,  1184,   674,    -1,  1183,  1188,
      -1,  1183,  1025,   514,  1191,   482,    -1,  1183,  1025,   514,
    1191,   482,   514,  1191,   482,    -1,  1189,    -1,  1025,    -1,
    1185,    -1,  1025,   513,  1187,   481,    -1,  1025,   513,  1187,
     481,    -1,  1181,    -1,    25,    -1,    20,    -1,  1025,    -1,
    1025,  1190,    -1,   514,  1191,   482,    -1,   514,  1191,   482,
     514,  1191,   482,    -1,  1192,    -1,  1191,     5,  1192,    -1,
     744,    -1,  1194,    -1,  1196,    -1,  1194,   674,  1195,    -1,
    1194,   674,  1025,   514,  1191,   482,    -1,  1194,   674,  1025,
     514,  1191,   482,   514,  1191,   482,    -1,  1025,    -1,  1186,
      -1,    20,    -1,  1025,    -1,  1025,  1190,    -1,    -1,  1198,
      -1,  1200,    -1,  1198,     5,  1200,    -1,  1201,    -1,  1199,
       5,  1201,    -1,  1025,    -1,  1025,   674,  1025,    -1,  1181,
      -1,  1181,   476,  1181,    -1,    25,    -1,  1031,    -1,    26,
      -1,  1203,    -1,  1202,     5,  1203,    -1,  1181,    -1,  1181,
     476,  1181,    -1,  1205,    -1,  1204,     5,  1205,    -1,  1193,
      -1,  1181,    -1,  1208,    -1,  1207,     5,  1208,    -1,  1181,
    1209,    -1,    -1,   642,    -1,   593,    -1,  1211,    -1,  1210,
       5,  1211,    -1,  1181,    -1,  1181,   476,  1181,    -1,   311,
    1021,   672,  1014,   634,  1598,   752,    -1,    -1,   672,   486,
     930,     5,   930,   449,  1214,    -1,    -1,   623,   486,   930,
       5,   930,   449,    -1,   312,  1025,  1213,    -1,  1025,    -1,
     397,  1023,  1218,    -1,  1219,    -1,   601,   930,    -1,  1220,
    1221,  1226,     8,  1216,    -1,    -1,   672,  1222,   486,   930,
       5,   930,   449,    -1,    -1,   611,  1026,    -1,    -1,   409,
      -1,   274,  1537,   323,  1579,  1225,    -1,   618,  1018,    -1,
     618,  1018,     8,   946,   928,    -1,    -1,   671,   631,  1531,
     432,  1531,    -1,   671,   631,  1531,     5,   432,  1531,    -1,
     671,  1531,     5,  1531,    -1,    -1,   703,    -1,   704,    -1,
     451,   680,  1579,  1228,  1229,    -1,    -1,   671,  1579,    -1,
      -1,   671,   631,  1531,     8,  1531,    -1,   631,  1531,     8,
    1531,    -1,   467,  1231,    -1,  1232,    -1,  1231,     5,  1232,
      -1,   259,  1011,    -1,   341,  1011,    -1,   388,  1011,    -1,
     396,  1011,    -1,   350,  1011,    -1,   316,  1011,    -1,  1103,
      -1,   494,  1104,    -1,   505,  1104,    -1,   616,  1104,    -1,
     433,  1104,    -1,   605,  1104,    -1,   603,  1012,    -1,   604,
    1012,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
     457,   748,    -1,   719,   748,    -1,   348,    -1,   252,    -1,
     209,    -1,   189,    -1,   197,    -1,   206,    -1,   661,  1233,
      -1,   735,  1234,    -1,    40,    -1,    41,    -1,    40,    -1,
      41,    -1,  1536,   469,  1238,   601,  1236,    -1,  1181,    -1,
      25,    -1,   459,  1238,    -1,   459,  1238,     8,  1199,    -1,
     459,  1238,   608,  1202,    -1,   459,  1238,   608,  1202,     8,
    1199,    -1,    57,  1236,    -1,  1026,    -1,    -1,   517,  1248,
     747,   650,  1243,  1181,  1241,  1024,   747,  1240,  1244,    -1,
      -1,   722,    26,    -1,   517,  1248,   747,   403,  1181,    -1,
      -1,   376,    -1,    -1,  1245,   339,    -1,  1246,    -1,  1245,
    1246,    -1,    -1,  1099,  1247,  1606,    -1,   929,    -1,    -1,
     658,  1018,  1250,  1251,    -1,    -1,   601,  1252,    -1,  1253,
      -1,  1252,     5,  1253,    -1,  1523,    -1,   538,    -1,   277,
    1257,   146,  1255,    -1,   277,  1257,   680,  1256,  1255,    -1,
     277,  1257,   145,  1256,  1255,    -1,   277,  1257,  1255,    -1,
      -1,    51,    -1,    25,    -1,  1030,    -1,  1025,    -1,    -1,
     534,    -1,   205,  1257,  1258,   486,   946,  1143,   449,    -1,
     250,  1257,    -1,   125,  1257,    -1,  1295,  1303,    -1,   502,
     119,    -1,   502,  1264,    -1,  1265,    -1,  1264,  1265,    -1,
      -1,   193,  1266,  1606,    -1,    -1,   255,  1267,  1606,    -1,
      -1,   285,  1268,  1606,    -1,    -1,   273,  1269,  1606,    -1,
      -1,   310,  1270,  1606,    -1,    -1,   257,  1181,  1271,  1606,
      -1,    -1,   281,  1181,  1272,  1606,    -1,  1283,    -1,  1287,
      -1,  1286,    -1,  1274,    -1,  1312,    -1,  1277,    -1,    -1,
     615,   930,  1275,   537,    -1,    -1,   537,    -1,    -1,   624,
      26,  1278,  1276,    -1,   216,    -1,   683,  1299,    -1,   219,
    1299,    -1,   218,  1299,    -1,    -1,  1280,    -1,  1281,    -1,
    1280,  1281,    -1,  1292,  1282,    -1,    -1,   672,  1299,    -1,
      -1,   574,  1284,  1279,  1291,    -1,  1531,    -1,   486,  1531,
     449,    -1,   573,  1285,  1291,    -1,   572,  1290,  1289,  1288,
    1291,    -1,    -1,   210,   923,    -1,   210,   923,     5,   923,
      -1,   667,    -1,   668,    -1,   669,    -1,   670,    -1,  1181,
      -1,    -1,   577,    -1,  1293,    -1,  1292,     5,  1293,    -1,
     930,  1326,    -1,   663,   486,   923,   449,  1311,    -1,   122,
    1311,    -1,   551,   486,    20,   449,  1311,    -1,   468,   486,
      20,   449,  1311,    -1,   445,   486,   923,   449,  1311,    -1,
     643,   486,   923,   449,  1311,    -1,   656,   486,   923,   449,
    1311,    -1,   655,   486,   923,   449,  1311,    -1,    -1,   516,
    1296,    -1,  1297,    -1,  1296,  1297,    -1,   284,    26,    -1,
     275,    26,    -1,   358,    26,    -1,   241,    26,    -1,   313,
      26,    -1,   232,    -1,   402,    25,    -1,   402,  1181,    -1,
     233,    25,    -1,   217,    25,    -1,  1302,    -1,  1298,  1302,
      -1,  1300,   167,    -1,  1300,   169,    -1,  1300,   168,    -1,
    1300,    -1,  1031,    -1,    26,    -1,    -1,   516,  1298,    -1,
     284,  1299,    -1,   275,  1299,    -1,   358,  1299,    -1,   241,
    1299,    -1,   313,  1299,    -1,   314,  1299,    -1,   682,    25,
      -1,   683,  1299,    -1,   687,    -1,   684,    -1,   685,    -1,
     686,    -1,   691,    -1,   688,    -1,   689,    -1,   690,    -1,
     134,  1299,    -1,   135,  1299,    -1,   136,  1299,    -1,   402,
      25,    -1,   233,    25,    -1,   456,    -1,   131,    -1,   132,
      -1,    -1,   569,   673,  1207,    -1,   194,  1207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   520,  1305,  1025,   486,  1306,
    1197,   449,  1307,   829,  1308,  1262,  1309,  1263,  1310,   296,
      -1,    -1,   581,   923,    -1,   571,  1313,    -1,    -1,  1236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,  1315,  1025,
     486,  1316,  1197,   449,  1317,   829,  1318,  1321,  1319,  1263,
    1320,   296,    -1,  1301,  1303,    -1,    -1,    -1,    -1,   212,
     486,    25,     5,  1323,   776,  1324,   449,  1325,   774,    -1,
      -1,   441,    -1,   441,   275,    26,    -1,   441,   275,  1181,
      -1,   661,   930,    -1,   661,   930,  1328,    -1,   661,   930,
     403,  1181,    -1,   661,   930,   220,    -1,   661,   930,  1328,
     403,  1181,    -1,   661,   930,  1328,   220,    -1,   661,   930,
     632,    -1,   661,   930,   599,    -1,    41,    -1,    40,    -1,
    1330,    -1,   229,  1480,    -1,   382,  1480,    -1,   338,  1481,
      -1,    54,  1025,    -1,  1344,    -1,  1332,    -1,    -1,    -1,
     262,  1333,  1480,   486,  1334,  1348,   449,  1337,    -1,    -1,
      -1,   191,  1335,  1480,   486,  1336,  1348,   449,  1337,  1345,
      -1,    -1,  1338,    -1,  1339,    -1,  1338,  1339,    -1,   677,
    1340,    -1,   301,    26,    -1,    66,    26,    -1,   143,    -1,
     144,    -1,  1605,    -1,    -1,  1342,    -1,  1343,    -1,  1342,
    1343,    -1,   677,  1340,    -1,   731,    26,    -1,   162,  1481,
     679,  1480,   486,  1346,   449,  1341,    -1,   109,  1026,    -1,
     110,  1026,    -1,   228,  1480,   650,  1480,    -1,   114,  1480,
      -1,    -1,   325,    -1,  1347,    -1,  1346,     5,  1347,    -1,
    1025,   642,    -1,  1025,   593,    -1,  1025,    -1,  1349,    -1,
    1348,     5,  1349,    -1,  1432,    -1,  1430,    -1,   178,  1025,
      -1,   236,    -1,    64,  1025,  1352,    -1,    65,  1481,   159,
      -1,    65,  1481,   160,    -1,  1353,    -1,  1352,     5,  1353,
      -1,  1354,    -1,  1357,    -1,  1360,    -1,  1365,    -1,  1368,
      -1,  1364,    -1,  1363,    -1,   639,  1355,    -1,   639,   486,
    1356,   449,    -1,  1349,    -1,  1349,   718,  1025,    -1,  1355,
      -1,  1356,     5,  1355,    -1,   596,  1359,    -1,   596,   486,
    1358,   449,    -1,  1359,    -1,  1358,     5,  1359,    -1,  1025,
      -1,   510,  1362,    -1,   510,   486,  1361,   449,    -1,  1362,
      -1,  1361,     5,  1362,    -1,  1349,    -1,   143,    -1,   144,
      -1,   142,    26,    -1,   112,  1430,  1367,    -1,   112,   486,
    1366,   449,    -1,  1430,  1367,    -1,  1366,     5,  1430,  1367,
      -1,    -1,   115,  1025,    -1,   113,  1369,    -1,   113,   486,
    1369,   449,    -1,  1370,    -1,  1369,     5,  1370,    -1,  1025,
      -1,   322,    -1,   288,    -1,   222,  1373,    -1,   201,    -1,
     190,    -1,   177,    -1,   175,    -1,   179,    -1,   235,  1537,
      -1,   287,  1372,   515,  1531,   680,  1531,    -1,   355,  1018,
     515,  1531,   680,  1531,    -1,    -1,  1537,    -1,    -1,   930,
      -1,   578,   930,    -1,   286,    -1,    -1,   305,  1377,  1480,
    1380,  1378,    -1,    -1,   534,  1379,   486,  1382,   449,    -1,
    1517,    -1,    -1,   486,  1381,   449,    -1,  1484,    -1,  1381,
       5,  1484,    -1,  1383,    -1,  1382,     5,  1383,    -1,  1523,
      -1,   538,    -1,    -1,   555,  1385,  1387,  1388,    -1,  1026,
      -1,  1392,  1019,    -1,  1019,    -1,    -1,    -1,   608,  1389,
    1202,    -1,    -1,    -1,   608,  1391,  1202,    -1,   556,    -1,
     609,    -1,   616,    -1,   433,    -1,   400,    -1,   452,    -1,
     436,   930,    -1,   409,   930,    -1,   294,  1480,   207,  1019,
      -1,   294,  1480,  1453,    -1,   569,   673,  1396,    -1,  1397,
      -1,  1396,     5,  1397,    -1,  1398,  1399,    -1,    26,    -1,
    1484,    -1,    -1,   642,    -1,   593,    -1,   333,    -1,   366,
      -1,    -1,   385,    -1,   414,  1404,  1402,    -1,  1579,    -1,
    1579,   666,  1025,    -1,    25,    -1,    -1,  1536,  1406,  1407,
      -1,  1438,    -1,    37,    -1,  1442,    -1,  1401,    -1,  1538,
      -1,  1400,    -1,  1393,    -1,  1394,    -1,  1384,    -1,  1376,
      -1,  1375,    -1,  1507,    -1,  1559,    -1,   560,  1411,   679,
    1480,   680,  1416,  1410,    -1,   521,  1411,   679,  1480,   601,
    1416,    -1,   560,  1409,   680,  1416,    -1,   521,  1409,   601,
    1416,    -1,   451,    -1,   437,    -1,   646,    -1,    -1,   200,
      -1,   671,  1025,    -1,   224,    -1,   640,    -1,  1412,    -1,
    1413,    -1,  1412,     5,  1413,    -1,   526,  1414,    -1,   505,
      -1,   494,    -1,   533,  1414,    -1,   541,    -1,   563,    -1,
      -1,   486,  1415,   449,    -1,  1484,    -1,  1415,     5,  1484,
      -1,  1417,    -1,  1416,     5,  1417,    -1,   518,    -1,  1482,
      -1,   292,  1480,  1419,   671,  1517,  1421,    -1,    -1,   486,
    1420,   449,    -1,  1484,    -1,  1420,     5,  1484,    -1,    -1,
     199,    -1,   547,   486,  1456,   449,    -1,   302,   486,  1425,
     449,  1424,    -1,   353,  1426,    -1,  1427,    -1,  1480,    -1,
    1480,   486,  1427,   449,    -1,  1484,    -1,  1427,     5,  1484,
      -1,   531,   486,  1429,   449,    -1,   417,   486,  1429,   449,
      -1,   315,   486,  1429,   449,    -1,  1484,    -1,  1429,     5,
    1484,    -1,  1428,    -1,  1423,    -1,  1422,    -1,   456,  1487,
      -1,   265,    -1,   264,    -1,   263,    -1,  1025,  1472,  1433,
    1434,    -1,    -1,  1431,    -1,    -1,  1435,    -1,  1436,    -1,
    1435,  1436,    -1,  1437,  1367,    -1,   431,    -1,   215,    -1,
     531,    -1,   417,    -1,  1424,    -1,   547,   486,  1456,   449,
      -1,   315,    -1,   176,  1439,  1441,    -1,  1440,    -1,  1482,
      -1,  1442,    -1,  1441,  1442,    -1,  1418,    -1,  1408,    -1,
     503,  1456,    -1,   426,  1445,    -1,  1522,    -1,  1445,     5,
    1522,    -1,   581,  1456,    -1,   601,  1448,    -1,  1449,    -1,
    1448,     5,  1449,    -1,  1450,    -1,   570,  1450,    -1,   570,
     486,  1451,   449,    -1,  1480,    -1,  1480,  1486,    -1,  1480,
     671,  1486,    -1,  1449,    -1,  1451,     5,  1449,    -1,  1447,
    1453,  1454,  1455,    -1,    -1,  1446,    -1,    -1,  1444,    -1,
      -1,  1443,    -1,  1457,    -1,  1456,     6,  1457,    -1,  1458,
      -1,  1457,     7,  1458,    -1,  1459,    -1,     9,  1459,    -1,
    1470,    -1,   486,  1456,   449,    -1,   498,  1518,    -1,   351,
    1518,    -1,    -1,   497,  1463,    -1,  1524,    -1,  1527,    -1,
    1523,   677,   486,  1465,   449,    -1,  1523,   677,  1518,    -1,
    1523,   484,   486,  1465,   449,    -1,  1523,   484,  1518,    -1,
    1466,    -1,  1465,     5,  1466,    -1,  1585,    -1,  1487,    -1,
      -1,     9,    -1,  1523,  1467,   444,    -1,  1523,  1467,   306,
      -1,  1523,  1469,  1523,    -1,  1523,  1467,   446,  1523,     7,
    1523,    -1,  1523,   611,  1462,  1461,    -1,  1523,   429,  1462,
    1461,    -1,  1523,   728,  1462,  1461,    -1,  1523,   430,  1462,
    1461,    -1,  1523,  1467,    10,  1462,  1461,    -1,    14,    -1,
      17,    -1,    12,    -1,    13,    -1,   727,    -1,    16,    -1,
      15,    -1,  1468,    -1,  1464,    -1,  1460,    -1,    -1,   640,
      -1,   417,    -1,   531,    -1,  1473,    -1,  1474,    -1,  1476,
      -1,   376,    -1,   376,   486,  1477,   449,    -1,    -1,   527,
      -1,   527,   486,    26,   449,    -1,   454,    -1,   454,   486,
    1478,  1475,   449,    -1,   567,   486,  1478,  1475,   449,    -1,
     567,    -1,   592,    -1,   464,    -1,   438,    -1,   377,    -1,
     377,   486,  1477,   449,    -1,   378,    -1,   378,   486,    26,
     449,    -1,   378,   486,    26,     5,    26,   449,    -1,   415,
    1493,   680,  1494,    -1,   415,    -1,   427,  1493,   680,  1494,
      -1,   427,    -1,   427,  1493,   486,    26,   449,   680,  1494,
      -1,   629,    -1,   588,    -1,   479,    -1,   479,   486,    26,
     449,    -1,   479,   486,    26,     5,    26,   449,    -1,    -1,
       5,  1479,    -1,   557,   486,  1478,   449,    -1,   620,    -1,
     356,    -1,   557,    -1,   121,    -1,    26,    -1,    26,    -1,
      26,    -1,    25,   674,  1025,    -1,    25,    -1,  1025,    -1,
    1025,   644,  1025,    -1,  1025,   644,    25,   674,  1025,    -1,
    1025,   666,  1025,    -1,  1025,   666,  1025,   644,  1025,    -1,
    1025,   666,  1025,   644,    25,   674,  1025,    -1,    25,   674,
    1025,    -1,    25,    -1,  1025,    -1,  1025,   644,  1025,    -1,
    1025,   644,    25,   674,  1025,    -1,  1025,   666,  1025,    -1,
    1025,   666,  1025,   644,  1025,    -1,  1025,   666,  1025,   644,
      25,   674,  1025,    -1,  1025,    -1,    -1,   514,    26,   482,
      -1,   514,    26,     5,    26,   482,    -1,  1485,    -1,   666,
    1485,    -1,  1025,  1483,    -1,  1480,   674,  1025,  1483,    -1,
    1480,   674,    20,    -1,  1025,    -1,    25,    -1,  1031,    -1,
      26,    -1,  1489,    -1,   452,  1491,    -1,   452,  1490,    -1,
      -1,  1493,   680,  1494,    -1,    -1,  1492,   680,  1492,    -1,
     636,    -1,   568,    -1,   645,    -1,   607,    -1,   509,    -1,
     525,    -1,   424,    -1,   424,   486,    26,   449,    -1,   636,
      -1,   568,    -1,   645,    -1,   607,    -1,   509,    -1,   525,
      -1,   424,    -1,   636,    -1,   568,    -1,   645,    -1,   607,
      -1,   509,    -1,   525,    -1,   424,    -1,   424,   486,    26,
     449,    -1,  1025,    -1,  1025,   666,  1025,    -1,    25,    -1,
    1536,   558,  1019,    -1,    -1,  1536,   455,  1386,   492,   650,
    1505,  1498,    -1,    -1,  1536,   455,  1386,   492,   157,   650,
    1506,  1499,    -1,    -1,  1536,   455,  1386,   195,  1506,  1500,
      -1,    -1,  1536,   455,  1386,   196,   157,   650,  1506,  1501,
      -1,    -1,   345,    -1,   344,  1503,    -1,  1504,    -1,  1503,
       5,  1504,    -1,  1025,    -1,  1025,   674,  1025,    -1,    25,
     674,  1025,   674,  1025,    -1,  1506,    -1,  1376,    -1,  1238,
      -1,  1508,    -1,  1508,    -1,    -1,    -1,   526,  1519,  1509,
    1520,  1510,  1516,  1452,  1514,  1502,    -1,   526,  1519,  1520,
    1452,  1514,    -1,  1513,    -1,  1531,    -1,   526,  1519,  1520,
    1516,  1452,  1514,    -1,    -1,   580,  1471,  1512,    -1,  1395,
      -1,   390,  1515,  1345,    -1,  1395,   390,  1515,  1345,    -1,
    1025,    -1,    -1,   608,  1202,    -1,   526,  1519,  1520,  1452,
      -1,   486,   526,  1519,  1520,  1452,   449,    -1,    -1,   640,
      -1,   417,    -1,   531,    -1,  1521,    -1,  1520,     5,  1521,
      -1,  1523,    -1,  1523,  1025,    -1,  1523,   671,  1025,    -1,
    1523,    -1,  1524,    -1,    19,  1524,    -1,    18,  1524,    -1,
    1525,    -1,  1585,    -1,  1518,    -1,   640,  1518,    -1,   641,
    1518,    -1,   625,  1518,    -1,   666,  1025,    -1,   666,  1025,
     674,  1025,    -1,  1524,    21,  1523,    -1,  1524,  1545,    -1,
    1524,    20,  1523,    -1,  1524,    18,  1523,    -1,  1524,    19,
    1523,    -1,  1487,    -1,   539,    -1,   483,    -1,   631,    -1,
      20,    -1,   122,    -1,   643,   486,  1471,  1523,   449,    -1,
     655,   486,  1471,  1523,   449,    -1,   656,   486,  1471,  1523,
     449,    -1,   663,   486,  1471,  1523,   449,    -1,   551,   486,
    1471,  1523,   449,    -1,  1025,   486,  1526,   449,    -1,   592,
     486,  1526,   449,    -1,   486,  1523,   449,    -1,   499,   486,
    1546,   449,    -1,  1547,    -1,  1549,    -1,  1523,    -1,  1526,
       5,  1523,    -1,  1487,    -1,  1536,   405,  1535,  1530,  1512,
      -1,  1536,   394,  1535,  1530,   305,  1480,  1532,    -1,  1536,
     394,  1535,  1530,  1181,    -1,    -1,   380,  1531,    -1,    25,
      -1,  1181,    -1,    -1,   486,  1533,   449,    -1,  1534,    -1,
    1533,     5,  1534,    -1,  1025,    -1,    25,    -1,  1181,    -1,
      -1,   324,  1537,   650,    -1,  1026,    -1,  1543,    -1,  1542,
      -1,  1539,    -1,   373,  1540,   680,  1540,    -1,   354,  1480,
     674,  1541,   680,  1541,    -1,  1025,    -1,  1025,    -1,   278,
    1480,    -1,   349,  1480,  1544,    -1,   328,    -1,   231,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   452,     5,  1493,   680,  1494,    -1,  1585,     5,
    1493,   680,  1494,    -1,   452,  1493,   680,  1494,    -1,  1523,
       5,  1493,   680,  1494,    -1,  1548,    -1,  1548,  1493,   680,
    1494,    -1,    38,    -1,  1550,    -1,  1550,  1493,   486,    26,
     449,   680,  1494,    -1,  1550,  1493,   680,  1494,    -1,    39,
      -1,    -1,   662,  1552,  1553,   246,    -1,  1554,    -1,  1553,
    1554,    -1,    33,    -1,  1555,    -1,  1557,    -1,    -1,   247,
    1556,  1585,    -1,    -1,   608,  1558,  1202,    -1,    -1,    -1,
     533,  1480,  1560,  1563,  1561,  1562,    -1,    -1,   207,  1019,
      -1,   581,  1456,    -1,   107,  1567,   449,    14,   486,  1568,
     449,    -1,   103,  1568,   449,    -1,   104,  1568,   449,    -1,
     638,  1564,    -1,   106,  1568,    -1,   105,  1568,    -1,  1566,
      -1,  1564,     5,  1566,    -1,  1484,    -1,  1565,    14,  1569,
      -1,  1565,    -1,  1567,     5,  1565,    -1,  1569,    -1,  1568,
       5,  1569,    -1,   538,    -1,  1570,    -1,  1571,    -1,    19,
    1571,    -1,    18,  1571,    -1,  1573,    -1,  1518,    -1,   666,
    1025,    -1,   666,  1025,   674,  1025,    -1,   666,  1025,   514,
      26,   482,    -1,   666,  1025,   674,  1025,   514,    26,   482,
      -1,   666,  1025,   514,    26,     5,    26,   482,    -1,   666,
    1025,   674,  1025,   514,    26,     5,    26,   482,    -1,  1572,
      -1,  1487,    -1,   539,    -1,   483,    -1,   631,    -1,   122,
      -1,  1571,    21,  1570,    -1,  1571,  1545,    -1,  1571,    20,
    1570,    -1,  1571,    18,  1570,    -1,  1571,    19,  1570,    -1,
     643,   486,  1471,  1570,   449,    -1,   655,   486,  1471,  1570,
     449,    -1,   656,   486,  1471,  1570,   449,    -1,   663,   486,
    1471,  1570,   449,    -1,   551,   486,  1471,  1570,   449,    -1,
    1025,   486,  1574,   449,    -1,   592,   486,  1574,   449,    -1,
     486,  1570,   449,    -1,   499,   486,  1546,   449,    -1,  1547,
      -1,  1549,    -1,  1585,    -1,  1570,    -1,  1574,     5,  1570,
      -1,    -1,   439,  1210,   611,  1576,  1577,    -1,  1578,    -1,
    1577,     5,  1578,    -1,  1480,   674,  1484,    -1,  1480,   674,
      20,    -1,  1581,    -1,  1581,    -1,   247,  1582,    -1,  1582,
      -1,  1583,    -1,    25,   674,  1583,    -1,  1584,    -1,  1583,
     674,  1584,    -1,  1583,   674,    20,    -1,  1586,    -1,  1025,
      -1,  1580,    -1,  1580,   476,  1580,    -1,  1025,  1587,    -1,
     514,  1588,   482,    -1,   514,  1588,   482,   514,  1588,   482,
      -1,  1589,    -1,  1588,     5,  1589,    -1,   744,    -1,    34,
      -1,    -1,    -1,   582,  1592,   930,  1593,  1606,   384,    -1,
      -1,   713,   973,    -1,    -1,   716,    -1,   238,    -1,   334,
    1020,    -1,   127,  1020,    -1,   364,    -1,   363,    -1,   365,
    1022,  1594,  1595,    -1,   548,   973,  1595,    -1,   161,    -1,
     192,  1020,    -1,   930,   621,     5,   930,   450,    -1,   564,
     930,    -1,   321,  1020,    -1,   158,  1601,     8,  1602,  1600,
      -1,    -1,   601,   930,    -1,  1025,    -1,  1025,    -1,   304,
    1020,    -1,   307,  1020,   680,   930,     5,   930,    -1,   307,
    1020,   673,   930,     5,   930,    -1,    27,    -1,    -1,  1608,
      -1,  1609,  1291,    -1,  1607,    -1,  1608,  1607,    -1,    -1,
    1610,  1611,    -1,   737,    -1,   738,    -1,   739,    -1,   740,
      -1,   757,    -1,   781,    -1,   802,    -1,   803,    -1,   809,
      -1,   828,    -1,   902,    -1,   903,    -1,   904,    -1,   905,
      -1,   916,    -1,   917,    -1,   918,    -1,   919,    -1,   920,
      -1,   921,    -1,   922,    -1,   975,    -1,  1006,    -1,  1010,
      -1,  1032,    -1,  1034,    -1,  1037,    -1,  1038,    -1,  1039,
      -1,  1040,    -1,  1053,    -1,  1063,    -1,  1087,    -1,  1088,
      -1,  1090,    -1,  1094,    -1,  1109,    -1,  1110,    -1,  1114,
      -1,  1115,    -1,  1116,    -1,  1117,    -1,  1127,    -1,  1142,
      -1,  1158,    -1,  1169,    -1,  1170,    -1,  1171,    -1,  1175,
      -1,  1212,    -1,  1215,    -1,  1217,    -1,  1223,    -1,  1224,
      -1,  1227,    -1,  1230,    -1,  1235,    -1,  1237,    -1,  1239,
      -1,  1242,    -1,  1249,    -1,  1254,    -1,  1259,    -1,  1260,
      -1,  1261,    -1,  1273,    -1,  1327,    -1,  1329,    -1,  1331,
      -1,  1350,    -1,  1351,    -1,  1371,    -1,  1374,    -1,  1403,
      -1,  1405,    -1,  1496,    -1,  1497,    -1,  1528,    -1,  1529,
      -1,  1551,    -1,  1575,    -1,  1590,    -1,  1591,    -1,  1596,
      -1,  1597,    -1,  1599,    -1,  1603,    -1,  1604,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1012,  1012,  1015,  1018,  1024,  1030,  1037,  1041,  1041,
    1047,  1066,  1067,  1068,  1069,  1070,  1081,  1087,  1088,  1089,
    1090,  1091,  1096,  1097,  1108,  1111,  1114,  1114,  1118,  1121,
    1122,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1147,  1148,
    1151,  1151,  1166,  1167,  1170,  1176,  1178,  1189,  1191,  1193,
    1195,  1199,  1201,  1263,  1267,  1271,  1271,  1281,  1285,  1288,
    1289,  1298,  1304,  1298,  1318,  1324,  1318,  1340,  1345,  1349,
    1340,  1361,  1365,  1361,  1373,  1378,  1373,  1397,  1404,  1408,
    1396,  1434,  1434,  1438,  1439,  1440,  1445,  1448,  1453,  1457,
    1465,  1466,  1469,  1469,  1475,  1479,  1494,  1492,  1510,  1510,
    1525,  1525,  1528,  1528,  1532,  1535,  1535,  1535,  1542,  1543,
    1542,  1550,  1550,  1561,  1561,  1574,  1598,  1606,  1574,  1622,
    1627,  1635,  1636,  1640,  1650,  1653,  1656,  1659,  1662,  1665,
    1678,  1683,  1683,  1684,  1684,  1687,  1692,  1692,  1696,  1715,
    1720,  1714,  1731,  1737,  1745,  1746,  1749,  1749,  1752,  1756,
    1761,  1768,  1768,  1772,  1772,  1773,  1773,  1774,  1774,  1775,
    1775,  1776,  1776,  1784,  1788,  1794,  1798,  1813,  1816,  1819,
    1822,  1825,  1828,  1834,  1845,  1850,  1863,  1867,  1882,  1883,
    1887,  1887,  1891,  1891,  1891,  1892,  1897,  1897,  1900,  1900,
    1909,  1910,  1911,  1914,  1918,  1919,  1919,  1936,  1936,  1936,
    1936,  1940,  1947,  1948,  1951,  1951,  1955,  1956,  1957,  1958,
    1963,  1963,  1969,  1969,  1978,  1975,  1991,  1991,  1993,  1993,
    1995,  1997,  1999,  2001,  2004,  2009,  2010,  2012,  2017,  2017,
    2018,  2018,  2022,  2022,  2034,  2034,  2039,  2043,  2045,  2046,
    2049,  2049,  2049,  2053,  2054,  2055,  2056,  2057,  2058,  2059,
    2060,  2061,  2062,  2063,  2064,  2067,  2068,  2069,  2070,  2074,
    2079,  2084,  2088,  2091,  2095,  2095,  2096,  2096,  2097,  2097,
    2098,  2099,  2100,  2101,  2102,  2103,  2106,  2107,  2108,  2138,
    2138,  2143,  2148,  2150,  2150,  2157,  2161,  2161,  2165,  2166,
    2167,  2168,  2169,  2170,  2171,  2177,  2177,  2180,  2182,  2188,
    2190,  2196,  2204,  2204,  2207,  2208,  2209,  2210,  2211,  2212,
    2213,  2219,  2222,  2222,  2235,  2235,  2242,  2243,  2244,  2246,
    2247,  2248,  2252,  2253,  2254,  2255,  2260,  2266,  2272,  2273,
    2275,  2277,  2278,  2279,  2280,  2281,  2282,  2285,  2286,  2293,
    2301,  2301,  2309,  2306,  2321,  2321,  2323,  2323,  2331,  2331,
    2334,  2337,  2338,  2343,  2355,  2359,  2362,  2365,  2366,  2367,
    2368,  2369,  2374,  2381,  2387,  2392,  2397,  2392,  2410,  2412,
    2417,  2422,  2422,  2422,  2426,  2426,  2429,  2429,  2436,  2436,
    2443,  2443,  2454,  2472,  2478,  2502,  2505,  2520,  2523,  2536,
    2538,  2540,  2542,  2544,  2546,  2548,  2554,  2556,  2560,  2562,
    2564,  2566,  2568,  2570,  2572,  2578,  2595,  2596,  2597,  2598,
    2602,  2603,  2604,  2608,  2613,  2620,  2621,  2622,  2623,  2624,
    2625,  2626,  2627,  2628,  2629,  2630,  2637,  2637,  2642,  2642,
    2645,  2651,  2659,  2665,  2675,  2676,  2684,  2705,  2709,  2714,
    2719,  2721,  2724,  2742,  2747,  2753,  2758,  2763,  2764,  2770,
    2841,  2852,  2861,  2869,  2869,  2884,  2888,  2895,  2898,  2906,
    2910,  2913,  2919,  2928,  2933,  2941,  2944,  2947,  2952,  2959,
    2964,  2969,  2974,  2984,  2992,  3000,  3005,  3009,  3014,  3018,
    3022,  3029,  3032,  3035,  3039,  3043,  3047,  3051,  3059,  3069,
    3074,  3067,  3090,  3095,  3090,  3109,  3114,  3109,  3135,  3135,
    3135,  3138,  3138,  3138,  3142,  3142,  3142,  3146,  3146,  3146,
    3150,  3156,  3162,  3168,  3176,  3182,  3190,  3196,  3205,  3211,
    3218,  3225,  3234,  3240,  3246,  3253,  3259,  3265,  3271,  3279,
    3285,  3291,  3300,  3306,  3312,  3322,  3322,  3326,  3330,  3331,
    3342,  3343,  3349,  3359,  3369,  3379,  3380,  3383,  3388,  3394,
    3398,  3402,  3405,  3411,  3414,  3417,  3434,  3437,  3443,  3444,
    3445,  3449,  3450,  3451,  3452,  3453,  3455,  3456,  3457,  3459,
    3460,  3464,  3465,  3470,  3474,  3479,  3483,  3498,  3502,  3508,
    3497,  3521,  3522,  3534,  3540,  3534,  3554,  3554,  3556,  3557,
    3561,  3561,  3565,  3565,  3570,  3570,  3577,  3578,  3582,  3582,
    3586,  3586,  3591,  3591,  3598,  3602,  3603,  3604,  3609,  3609,
    3612,  3612,  3616,  3616,  3620,  3620,  3624,  3624,  3629,  3629,
    3634,  3634,  3639,  3639,  3644,  3644,  3660,  3664,  3659,  3672,
    3675,  3689,  3706,  3707,  3708,  3709,  3710,  3711,  3712,  3715,
    3715,  3718,  3720,  3723,  3726,  3729,  3734,  3739,  3742,  3747,
    3752,  3757,  3764,  3765,  3772,  3779,  3781,  3787,  3792,  3797,
    3802,  3802,  3805,  3811,  3816,  3819,  3826,  3826,  3828,  3831,
    3834,  3839,  3844,  3849,  3856,  3867,  3867,  3929,  3937,  3938,
    3946,  3953,  3953,  3957,  3962,  3968,  3972,  3976,  3982,  3986,
    3990,  3996,  3996,  4004,  4005,  4009,  4009,  4013,  4014,  4017,
    4020,  4020,  4023,  4025,  4025,  4028,  4030,  4030,  4031,  4033,
    4033,  4042,  4049,  4040,  4070,  4070,  4070,  4073,  4075,  4073,
    4082,  4085,  4092,  4097,  4108,  4108,  4112,  4118,  4118,  4122,
    4123,  4127,  4137,  4138,  4139,  4142,  4144,  4149,  4149,  4153,
    4152,  4160,  4159,  4166,  4166,  4172,  4172,  4179,  4179,  4185,
    4185,  4191,  4191,  4197,  4197,  4201,  4201,  4202,  4202,  4203,
    4203,  4204,  4204,  4208,  4208,  4219,  4223,  4229,  4233,  4238,
    4243,  4248,  4249,  4250,  4254,  4253,  4266,  4271,  4276,  4276,
    4292,  4298,  4299,  4300,  4301,  4302,  4312,  4326,  4326,  4329,
    4336,  4337,  4338,  4339,  4340,  4341,  4342,  4343,  4344,  4349,
    4349,  4351,  4354,  4354,  4356,  4360,  4363,  4364,  4367,  4367,
    4372,  4375,  4376,  4377,  4378,  4379,  4380,  4381,  4382,  4383,
    4384,  4385,  4386,  4387,  4388,  4389,  4390,  4391,  4392,  4396,
    4414,  4414,  4414,  4441,  4452,  4459,  4465,  4471,  4477,  4489,
    4512,  4513,  4516,  4520,  4519,  4537,  4537,  4541,  4542,  4550,
    4551,  4552,  4553,  4554,  4555,  4556,  4563,  4564,  4566,  4567,
    4571,  4576,  4577,  4578,  4579,  4580,  4581,  4582,  4583,  4584,
    4587,  4589,  4589,  4591,  4595,  4595,  4604,  4610,  4626,  4632,
    4603,  4646,  4660,  4671,  4659,  4684,  4691,  4691,  4696,  4702,
    4710,  4715,  4716,  4719,  4722,  4722,  4730,  4736,  4747,  4748,
    4756,  4762,  4756,  4773,  4774,  4778,  4778,  4785,  4785,  4800,
    4800,  4814,  4825,  4824,  4836,  4832,  4849,  4846,  4859,  4859,
    4861,  4862,  4864,  4865,  4868,  4869,  4870,  4872,  4877,  4882,
    4888,  4890,  4891,  4894,  4895,  4898,  4900,  4907,  4910,  4913,
    4916,  4920,  4924,  4925,  4926,  4927,  4928,  4932,  4937,  4937,
    4940,  4967,  5025,  5025,  5028,  5032,  5036,  5079,  5121,  5122,
    5123,  5126,  5140,  5152,  5152,  5157,  5158,  5164,  5229,  5234,
    5241,  5246,  5254,  5260,  5293,  5296,  5297,  5338,  5381,  5382,
    5386,  5387,  5391,  5444,  5449,  5453,  5458,  5469,  5476,  5484,
    5484,  5487,  5488,  5489,  5490,  5491,  5494,  5497,  5503,  5506,
    5510,  5515,  5523,  5528,  5535,  5537,  5543,  5545,  5545,  5545,
    5565,  5572,  5579,  5582,  5596,  5603,  5604,  5607,  5608,  5612,
    5618,  5623,  5629,  5630,  5635,  5639,  5639,  5643,  5644,  5647,
    5648,  5652,  5660,  5663,  5669,  5670,  5672,  5674,  5678,  5678,
    5679,  5684,  5692,  5693,  5698,  5699,  5701,  5714,  5716,  5717,
    5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,  5728,  5729,
    5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,  5738,  5739,
    5740,  5741,  5742,  5743,  5744,  5745,  5746,  5747,  5751,  5752,
    5756,  5757,  5771,  5779,  5779,  5781,  5785,  5789,  5793,  5797,
    5802,  5817,  5815,  5835,  5836,  5840,  5845,  5846,  5850,  5851,
    5853,  5854,  5856,  5856,  5865,  5874,  5874,  5884,  5885,  5890,
    5891,  5894,  5907,  5921,  5925,  5929,  5933,  5940,  5941,  5944,
    5944,  5948,  5951,  5951,  5953,  5959,  5967,  5973,  5975,  5979,
    5982,  5982,  5985,  5985,  5990,  5990,  5999,  5999,  6003,  6003,
    6004,  6004,  6005,  6005,  6019,  6019,  6039,  6040,  6041,  6042,
    6043,  6044,  6047,  6047,  6053,  6053,  6056,  6056,  6072,  6073,
    6074,  6083,  6095,  6096,  6099,  6100,  6103,  6106,  6106,  6111,
    6111,  6134,  6135,  6141,  6146,  6152,  6153,  6154,  6158,  6159,
    6160,  6161,  6165,  6175,  6177,  6182,  6185,  6190,  6196,  6203,
    6210,  6219,  6226,  6233,  6240,  6247,  6256,  6256,  6258,  6258,
    6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,  6269,  6270,
    6273,  6273,  6276,  6277,  6278,  6279,  6282,  6282,  6285,  6285,
    6288,  6289,  6290,  6291,  6292,  6293,  6294,  6295,  6297,  6298,
    6299,  6300,  6302,  6303,  6304,  6305,  6307,  6308,  6309,  6310,
    6311,  6312,  6313,  6314,  6318,  6326,  6336,  6349,  6360,  6371,
    6375,  6379,  6385,  6348,  6398,  6401,  6409,  6421,  6423,  6428,
    6438,  6448,  6451,  6455,  6463,  6427,  6472,  6476,  6480,  6484,
    6476,  6494,  6495,  6496,  6497,  6502,  6503,  6504,  6505,  6506,
    6507,  6508,  6509,  6513,  6514,  6517,  6522,  6529,  6530,  6531,
    6536,  6537,  6543,  6543,  6543,  6548,  6548,  6548,  6556,  6557,
    6561,  6562,  6567,  6568,  6569,  6570,  6571,  6574,  6576,  6576,
    6579,  6580,  6584,  6585,  6588,  6589,  6592,  6595,  6598,  6604,
    6605,  6617,  6618,  6623,  6624,  6625,  6629,  6632,  6638,  6641,
    6649,  6650,  6656,  6660,  6664,  6670,  6673,  6682,  6685,  6688,
    6691,  6694,  6697,  6700,  6707,  6710,  6717,  6720,  6726,  6729,
    6736,  6739,  6746,  6747,  6752,  6756,  6759,  6765,  6768,  6774,
    6781,  6782,  6786,  6796,  6799,  6805,  6807,  6812,  6813,  6817,
    6819,  6825,  6826,  6839,  6851,  6852,  6853,  6854,  6855,  6856,
    6857,  6858,  6859,  6862,  6865,  6871,  6871,  6877,  6877,  6888,
    6901,  6911,  6911,  6916,  6916,  6920,  6924,  6925,  6931,  6932,
    6937,  6941,  6948,  6951,  6958,  6957,  6968,  6972,  6976,  6983,
    6986,  6986,  6999,  7003,  7003,  7018,  7020,  7022,  7024,  7026,
    7028,  7030,  7032,  7038,  7048,  7055,  7060,  7061,  7065,  7068,
    7069,  7072,  7073,  7074,  7077,  7082,  7089,  7090,  7097,  7109,
    7110,  7111,  7114,  7114,  7119,  7124,  7129,  7134,  7135,  7138,
    7139,  7144,  7149,  7153,  7158,  7159,  7163,  7170,  7171,  7172,
    7173,  7178,  7179,  7180,  7183,  7184,  7185,  7189,  7190,  7191,
    7195,  7196,  7200,  7201,  7202,  7203,  7204,  7205,  7208,  7209,
    7214,  7215,  7220,  7221,  7226,  7227,  7232,  7237,  7238,  7243,
    7244,  7248,  7249,  7254,  7261,  7266,  7271,  7275,  7276,  7281,
    7282,  7288,  7291,  7295,  7300,  7301,  7307,  7310,  7313,  7320,
    7321,  7322,  7323,  7337,  7342,  7343,  7346,  7348,  7355,  7358,
    7364,  7372,  7376,  7380,  7384,  7389,  7392,  7395,  7402,  7409,
    7414,  7418,  7419,  7425,  7428,  7439,  7446,  7452,  7455,  7462,
    7469,  7475,  7476,  7482,  7483,  7484,  7487,  7488,  7495,  7502,
    7502,  7506,  7514,  7515,  7518,  7521,  7526,  7527,  7532,  7535,
    7541,  7544,  7550,  7553,  7559,  7562,  7569,  7570,  7599,  7600,
    7604,  7612,  7617,  7620,  7623,  7626,  7632,  7633,  7637,  7640,
    7643,  7644,  7649,  7652,  7655,  7658,  7661,  7664,  7667,  7670,
    7675,  7681,  7682,  7683,  7684,  7687,  7688,  7689,  7694,  7697,
    7701,  7707,  7708,  7709,  7710,  7722,  7723,  7724,  7728,  7729,
    7733,  7734,  7735,  7736,  7737,  7739,  7748,  7755,  7756,  7757,
    7758,  7759,  7760,  7761,  7763,  7765,  7767,  7768,  7770,  7771,
    7773,  7774,  7775,  7776,  7778,  7782,  7783,  7789,  7791,  7792,
    7793,  7794,  7799,  7803,  7807,  7811,  7818,  7822,  7823,  7824,
    7832,  7833,  7834,  7845,  7852,  7857,  7858,  7859,  7867,  7868,
    7869,  7886,  7895,  7896,  7897,  7901,  7904,  7909,  7914,  7919,
    7927,  7931,  7936,  7937,  7945,  7948,  7951,  7965,  7979,  7992,
    7993,  7997,  7997,  7997,  7997,  7997,  7997,  7998,  8001,  8018,
    8018,  8018,  8018,  8018,  8018,  8018,  8019,  8019,  8019,  8019,
    8019,  8019,  8019,  8019,  8022,  8023,  8024,  8027,  8036,  8036,
    8042,  8042,  8049,  8049,  8055,  8055,  8063,  8064,  8065,  8068,
    8068,  8071,  8072,  8073,  8084,  8087,  8093,  8098,  8105,  8118,
    8119,  8116,  8137,  8148,  8151,  8156,  8168,  8171,  8175,  8178,
    8179,  8189,  8192,  8193,  8202,  8211,  8216,  8217,  8218,  8219,
    8226,  8229,  8235,  8238,  8245,  8257,  8266,  8269,  8272,  8278,
    8286,  8289,  8290,  8291,  8292,  8293,  8296,  8302,  8304,  8306,
    8308,  8310,  8312,  8313,  8314,  8315,  8316,  8317,  8318,  8320,
    8322,  8324,  8326,  8328,  8330,  8332,  8333,  8335,  8336,  8342,
    8343,  8350,  8353,  8361,  8365,  8372,  8372,  8376,  8376,  8381,
    8381,  8385,  8385,  8389,  8395,  8395,  8398,  8398,  8404,  8411,
    8412,  8413,  8417,  8418,  8421,  8422,  8426,  8432,  8442,  8443,
    8451,  8452,  8453,  8454,  8455,  8456,  8460,  8461,  8462,  8463,
    8467,  8468,  8472,  8488,  8489,  8490,  8494,  8508,  8508,  8520,
    8521,  8525,  8526,  8527,  8851,  8851,  8858,  8858,  8946,  8950,
    8946,  8959,  8963,  8969,  8977,  8987,  8997,  9009,  9012,  9031,
    9057,  9060,  9066,  9069,  9074,  9077,  9085,  9093,  9106,  9109,
    9117,  9120,  9123,  9131,  9135,  9136,  9137,  9138,  9139,  9140,
    9141,  9142,  9146,  9147,  9148,  9149,  9150,  9156,  9157,  9158,
    9159,  9160,  9161,  9162,  9163,  9164,  9165,  9166,  9167,  9168,
    9169,  9170,  9171,  9176,  9182,  9183,  9191,  9191,  9199,  9199,
    9203,  9207,  9222,  9237,  9243,  9245,  9253,  9254,  9258,  9259,
    9262,  9269,  9272,  9301,  9327,  9381,  9417,  9426,  9437,  9440,
    9445,  9459,  9473,  9476,  9472,  9495,  9495,  9501,  9502,  9505,
    9506,  9507,  9508,  9509,  9510,  9511,  9522,  9525,  9530,  9534,
    9539,  9543,  9548,  9552,  9555,  9559,  9562,  9567,  9571,  9582,
    9588,  9588,  9589,  9590,  9597,  9607,  9607,  9609,  9610,  9611,
    9612,  9613,  9614,  9615,  9616,  9617,  9618,  9619,  9620,  9621,
    9622,  9623,  9624,  9625,  9626,  9627,  9628,  9629,  9630,  9631,
    9632,  9633,  9634,  9635,  9636,  9637,  9638,  9639,  9640,  9641,
    9642,  9643,  9644,  9645,  9646,  9647,  9648,  9649,  9650,  9651,
    9652,  9653,  9654,  9655,  9656,  9657,  9658,  9659,  9660,  9661,
    9662,  9663,  9664,  9665,  9666,  9667,  9668,  9669,  9670,  9671,
    9672,  9673,  9674,  9675,  9676,  9677,  9678,  9679,  9680,  9681,
    9682,  9683,  9684,  9685,  9686,  9687,  9688,  9689,  9690,  9691,
    9692,  9693,  9694,  9695,  9696
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
       0,   256,  1719,  1720,  1721,  1622,  1662,  1617,  1554,  1637,
    1434,  1540,  1536,  1451,  1612,  1353,  1410,  1482,  1648,  1635,
    1541,  1568,  1636,  1417,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1000,  1001,  1002,  1003,
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
    1530,  1531,  1532,  1533,  1534,  1535,  1537,  1538,  1539,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,
    1553,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1613,  1614,  1615,
    1616,  1618,  1619,  1620,  1621,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1634,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,  1646,  1647,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,
    1713,  1714,  1715,  1716,  1717,  1718
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   736,   737,   738,   739,   740,   741,   741,   742,   742,
     743,   744,   744,   744,   744,   744,   744,   745,   745,   745,
     745,   745,   746,   746,   747,   747,   749,   748,   748,   750,
     750,   751,   751,   751,   751,   751,   751,   751,   751,   751,
     751,   751,   751,   751,   751,   751,   751,   751,   752,   752,
     754,   753,   755,   755,   756,   756,   756,   756,   756,   756,
     756,   756,   756,   757,   758,   759,   758,   758,   758,   758,
     758,   760,   761,   758,   762,   763,   758,   764,   765,   766,
     758,   767,   768,   758,   769,   770,   758,   771,   772,   773,
     758,   774,   774,   775,   775,   775,   776,   776,   777,   777,
     778,   778,   779,   779,   780,   780,   782,   781,   783,   781,
     784,   784,   785,   785,   786,   787,   788,   787,   789,   790,
     789,   792,   791,   794,   793,   796,   797,   798,   795,   799,
     799,   800,   800,   801,   802,   802,   802,   802,   802,   802,
     803,   804,   804,   805,   805,   806,   807,   807,   808,   810,
     811,   809,   812,   812,   813,   813,   814,   814,   815,   815,
     815,   816,   816,   818,   817,   819,   817,   820,   817,   821,
     817,   822,   817,   823,   823,   824,   824,   825,   825,   825,
     825,   825,   825,   826,   827,   827,   828,   828,   829,   829,
     830,   830,   832,   833,   831,   831,   834,   834,   836,   835,
     837,   837,   837,   837,   837,   838,   837,   839,   839,   839,
     839,   840,   841,   841,   842,   842,   843,   843,   843,   843,
     845,   844,   846,   844,   847,   844,   848,   848,   849,   849,
     850,   851,   851,   851,   852,   853,   853,   853,   855,   854,
     856,   854,   857,   854,   858,   858,   859,   860,   861,   861,
     863,   864,   862,   865,   865,   865,   865,   865,   865,   865,
     865,   865,   865,   865,   865,   865,   865,   865,   865,   865,
     865,   865,   865,   865,   866,   865,   867,   865,   868,   865,
     865,   865,   865,   865,   865,   865,   865,   865,   865,   869,
     869,   870,   871,   872,   872,   873,   875,   874,   876,   876,
     876,   876,   876,   876,   876,   878,   877,   879,   879,   880,
     880,   881,   883,   882,   884,   884,   884,   884,   884,   884,
     884,   885,   886,   886,   888,   887,   889,   889,   889,   889,
     889,   889,   889,   889,   889,   889,   889,   889,   889,   889,
     889,   889,   889,   889,   889,   889,   889,   889,   889,   890,
     892,   891,   893,   891,   895,   894,   896,   894,   897,   897,
     898,   899,   899,   900,   901,   901,   901,   901,   901,   901,
     901,   901,   902,   903,   904,   906,   907,   905,   908,   908,
     909,   910,   910,   910,   911,   911,   913,   912,   914,   912,
     915,   912,   916,   917,   918,   919,   919,   920,   920,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   922,   922,
     922,   922,   922,   922,   922,   922,   923,   923,   923,   923,
     923,   923,   923,   923,   923,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   925,   925,   926,   926,
     927,   927,   928,   928,   929,   929,   930,   931,   931,   931,
     931,   931,   931,   932,   932,   932,   932,   933,   933,   934,
     935,   935,   935,   936,   935,   937,   937,   938,   938,   939,
     939,   939,   939,   940,   940,   941,   941,   941,   941,   941,
     941,   941,   941,   942,   943,   944,   944,   944,   944,   944,
     944,   945,   945,   945,   945,   945,   945,   945,   946,   948,
     949,   947,   950,   951,   947,   952,   953,   947,   955,   956,
     954,   957,   958,   954,   959,   960,   954,   961,   962,   954,
     954,   954,   954,   954,   954,   954,   954,   954,   954,   954,
     954,   954,   954,   954,   954,   954,   954,   954,   954,   954,
     954,   954,   954,   954,   954,   963,   963,   964,   965,   965,
     965,   965,   965,   965,   965,   965,   965,   966,   966,   967,
     967,   967,   967,   968,   968,   968,   969,   969,   970,   970,
     970,   971,   971,   971,   971,   971,   971,   971,   971,   971,
     971,   972,   972,   973,   973,   974,   974,   976,   977,   978,
     975,   979,   979,   981,   982,   980,   983,   983,   984,   984,
     985,   985,   987,   986,   988,   986,   989,   989,   990,   990,
     992,   991,   993,   991,   994,   995,   995,   995,   996,   996,
     997,   997,   998,   998,   999,   999,  1001,  1000,  1002,  1000,
    1003,  1000,  1004,  1000,  1005,  1000,  1007,  1008,  1006,  1009,
    1009,  1010,  1011,  1011,  1011,  1011,  1011,  1011,  1011,  1012,
    1012,  1013,  1014,  1015,  1016,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1017,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1024,  1025,  1026,  1027,  1027,  1028,  1028,  1029,  1029,
    1029,  1029,  1029,  1029,  1030,  1031,  1031,  1032,  1033,  1033,
    1034,  1035,  1035,  1036,  1037,  1038,  1038,  1038,  1039,  1039,
    1039,  1041,  1040,  1042,  1042,  1043,  1043,  1044,  1044,  1045,
    1046,  1046,  1047,  1048,  1048,  1049,  1050,  1050,  1051,  1052,
    1052,  1054,  1055,  1053,  1056,  1057,  1056,  1058,  1059,  1056,
    1060,  1060,  1061,  1062,  1064,  1063,  1063,  1065,  1065,  1066,
    1066,  1067,  1068,  1068,  1068,  1069,  1069,  1070,  1070,  1072,
    1071,  1073,  1071,  1074,  1071,  1075,  1071,  1076,  1071,  1077,
    1071,  1078,  1071,  1079,  1071,  1080,  1071,  1081,  1071,  1082,
    1071,  1083,  1071,  1084,  1071,  1085,  1085,  1086,  1086,  1087,
    1088,  1089,  1089,  1089,  1091,  1090,  1092,  1092,  1093,  1092,
    1094,  1095,  1095,  1095,  1095,  1095,  1095,  1096,  1096,  1097,
    1098,  1098,  1098,  1098,  1098,  1098,  1098,  1098,  1098,  1100,
    1099,  1099,  1102,  1101,  1103,  1104,  1105,  1105,  1106,  1106,
    1107,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,
    1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1109,
    1111,  1112,  1110,  1113,  1113,  1114,  1115,  1116,  1117,  1117,
    1118,  1118,  1119,  1121,  1120,  1122,  1122,  1123,  1123,  1124,
    1124,  1124,  1124,  1124,  1124,  1124,  1125,  1125,  1126,  1126,
    1127,  1128,  1128,  1128,  1128,  1128,  1128,  1128,  1128,  1128,
    1129,  1130,  1130,  1131,  1132,  1132,  1134,  1135,  1136,  1137,
    1133,  1138,  1140,  1141,  1139,  1142,  1143,  1143,  1144,  1144,
    1145,  1146,  1146,  1147,  1149,  1148,  1150,  1150,  1150,  1150,
    1152,  1153,  1151,  1154,  1154,  1156,  1155,  1157,  1155,  1159,
    1158,  1160,  1162,  1161,  1163,  1161,  1164,  1161,  1165,  1165,
    1166,  1166,  1167,  1167,  1168,  1168,  1168,  1169,  1170,  1171,
    1172,  1172,  1172,  1173,  1173,  1174,  1174,  1175,  1176,  1176,
    1176,  1176,  1177,  1177,  1177,  1177,  1177,  1178,  1179,  1179,
    1180,  1181,  1182,  1182,  1183,  1184,  1184,  1184,  1184,  1184,
    1184,  1185,  1186,  1187,  1187,  1188,  1188,  1189,  1190,  1190,
    1191,  1191,  1192,  1193,  1194,  1194,  1194,  1194,  1194,  1194,
    1195,  1195,  1196,  1197,  1197,  1198,  1198,  1199,  1199,  1200,
    1200,  1201,  1201,  1201,  1201,  1201,  1202,  1202,  1203,  1203,
    1204,  1204,  1205,  1206,  1207,  1207,  1208,  1209,  1209,  1209,
    1210,  1210,  1211,  1211,  1212,  1213,  1213,  1214,  1214,  1215,
    1216,  1217,  1218,  1218,  1219,  1220,  1220,  1221,  1221,  1222,
    1222,  1223,  1224,  1224,  1225,  1225,  1225,  1225,  1226,  1226,
    1226,  1227,  1228,  1228,  1229,  1229,  1229,  1230,  1231,  1231,
    1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,
    1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,
    1232,  1232,  1232,  1232,  1232,  1232,  1232,  1232,  1233,  1233,
    1234,  1234,  1235,  1236,  1236,  1237,  1237,  1237,  1237,  1237,
    1238,  1240,  1239,  1241,  1241,  1242,  1243,  1243,  1244,  1244,
    1245,  1245,  1247,  1246,  1248,  1250,  1249,  1251,  1251,  1252,
    1252,  1253,  1253,  1254,  1254,  1254,  1254,  1255,  1255,  1256,
    1256,  1257,  1258,  1258,  1259,  1260,  1261,  1262,  1263,  1263,
    1264,  1264,  1266,  1265,  1267,  1265,  1268,  1265,  1269,  1265,
    1270,  1265,  1271,  1265,  1272,  1265,  1273,  1273,  1273,  1273,
    1273,  1273,  1275,  1274,  1276,  1276,  1278,  1277,  1277,  1277,
    1277,  1277,  1279,  1279,  1280,  1280,  1281,  1282,  1282,  1284,
    1283,  1285,  1285,  1286,  1287,  1288,  1288,  1288,  1289,  1289,
    1289,  1289,  1290,  1291,  1291,  1292,  1292,  1293,  1294,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1295,  1295,  1296,  1296,
    1297,  1297,  1297,  1297,  1297,  1297,  1297,  1297,  1297,  1297,
    1298,  1298,  1299,  1299,  1299,  1299,  1300,  1300,  1301,  1301,
    1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,
    1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,
    1302,  1302,  1302,  1302,  1303,  1303,  1303,  1305,  1306,  1307,
    1308,  1309,  1310,  1304,  1311,  1311,  1312,  1313,  1313,  1315,
    1316,  1317,  1318,  1319,  1320,  1314,  1321,  1323,  1324,  1325,
    1322,  1326,  1326,  1326,  1326,  1327,  1327,  1327,  1327,  1327,
    1327,  1327,  1327,  1328,  1328,  1329,  1330,  1330,  1330,  1330,
    1331,  1331,  1333,  1334,  1332,  1335,  1336,  1332,  1337,  1337,
    1338,  1338,  1339,  1339,  1339,  1339,  1339,  1340,  1341,  1341,
    1342,  1342,  1343,  1343,  1344,  1344,  1344,  1344,  1344,  1345,
    1345,  1346,  1346,  1347,  1347,  1347,  1348,  1348,  1349,  1349,
    1350,  1350,  1351,  1351,  1351,  1352,  1352,  1353,  1353,  1353,
    1353,  1353,  1353,  1353,  1354,  1354,  1355,  1355,  1356,  1356,
    1357,  1357,  1358,  1358,  1359,  1360,  1360,  1361,  1361,  1362,
    1363,  1363,  1364,  1365,  1365,  1366,  1366,  1367,  1367,  1368,
    1368,  1369,  1369,  1370,  1371,  1371,  1371,  1371,  1371,  1371,
    1371,  1371,  1371,  1371,  1371,  1372,  1372,  1373,  1373,  1374,
    1375,  1377,  1376,  1379,  1378,  1378,  1380,  1380,  1381,  1381,
    1382,  1382,  1383,  1383,  1385,  1384,  1386,  1387,  1387,  1388,
    1389,  1388,  1390,  1391,  1390,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1393,  1394,  1395,  1396,  1396,  1397,  1398,
    1398,  1399,  1399,  1399,  1400,  1401,  1402,  1402,  1403,  1404,
    1404,  1404,  1406,  1405,  1407,  1407,  1407,  1407,  1407,  1407,
    1407,  1407,  1407,  1407,  1407,  1407,  1407,  1408,  1408,  1408,
    1408,  1409,  1409,  1409,  1410,  1410,  1410,  1411,  1411,  1411,
    1412,  1412,  1413,  1413,  1413,  1413,  1413,  1413,  1414,  1414,
    1415,  1415,  1416,  1416,  1417,  1417,  1418,  1419,  1419,  1420,
    1420,  1421,  1421,  1422,  1423,  1424,  1425,  1426,  1426,  1427,
    1427,  1428,  1428,  1428,  1429,  1429,  1430,  1430,  1430,  1431,
    1431,  1431,  1431,  1432,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1438,  1439,
    1440,  1441,  1441,  1442,  1442,  1443,  1444,  1445,  1445,  1446,
    1447,  1448,  1448,  1449,  1449,  1449,  1450,  1450,  1450,  1451,
    1451,  1452,  1453,  1453,  1454,  1454,  1455,  1455,  1456,  1456,
    1457,  1457,  1458,  1458,  1459,  1459,  1460,  1460,  1461,  1461,
    1462,  1463,  1464,  1464,  1464,  1464,  1465,  1465,  1466,  1466,
    1467,  1467,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,  1470,
    1470,  1471,  1471,  1471,  1471,  1472,  1472,  1472,  1473,  1473,
    1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,
    1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,
    1474,  1474,  1474,  1474,  1474,  1475,  1475,  1476,  1476,  1476,
    1476,  1476,  1477,  1478,  1479,  1480,  1480,  1480,  1480,  1480,
    1480,  1480,  1480,  1481,  1481,  1481,  1481,  1481,  1481,  1481,
    1481,  1482,  1483,  1483,  1483,  1484,  1484,  1485,  1485,  1485,
    1486,  1487,  1487,  1487,  1487,  1488,  1489,  1490,  1490,  1491,
    1491,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1495,  1495,  1495,  1496,  1498,  1497,
    1499,  1497,  1500,  1497,  1501,  1497,  1502,  1502,  1502,  1503,
    1503,  1504,  1504,  1504,  1505,  1505,  1506,  1506,  1507,  1509,
    1510,  1508,  1511,  1512,  1512,  1513,  1514,  1514,  1514,  1514,
    1514,  1515,  1516,  1516,  1517,  1518,  1519,  1519,  1519,  1519,
    1520,  1520,  1521,  1521,  1521,  1522,  1523,  1523,  1523,  1524,
    1524,  1524,  1524,  1524,  1524,  1524,  1524,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1525,  1526,
    1526,  1527,  1528,  1529,  1529,  1530,  1530,  1531,  1531,  1532,
    1532,  1533,  1533,  1534,  1535,  1535,  1536,  1536,  1537,  1538,
    1538,  1538,  1539,  1539,  1540,  1541,  1542,  1543,  1544,  1544,
    1545,  1545,  1545,  1545,  1545,  1545,  1546,  1546,  1546,  1546,
    1547,  1547,  1548,  1549,  1549,  1549,  1550,  1552,  1551,  1553,
    1553,  1554,  1554,  1554,  1556,  1555,  1558,  1557,  1560,  1561,
    1559,  1562,  1562,  1562,  1563,  1563,  1563,  1563,  1563,  1563,
    1564,  1564,  1565,  1566,  1567,  1567,  1568,  1568,  1569,  1569,
    1570,  1570,  1570,  1571,  1571,  1571,  1571,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1571,  1571,  1571,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1573,  1574,  1574,  1576,  1575,  1577,  1577,
    1578,  1578,  1579,  1580,  1581,  1581,  1582,  1582,  1583,  1583,
    1583,  1584,  1584,  1585,  1585,  1586,  1587,  1587,  1588,  1588,
    1589,  1590,  1592,  1593,  1591,  1594,  1594,  1595,  1595,  1596,
    1596,  1596,  1596,  1596,  1596,  1596,  1597,  1597,  1598,  1598,
    1599,  1599,  1600,  1600,  1601,  1602,  1603,  1604,  1604,  1605,
    1606,  1606,  1607,  1608,  1608,  1610,  1609,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,  1611,
    1611,  1611,  1611,  1611,  1611
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
     158,  1100, -2567,   375,   375,   375,   528, -2567, -2567,   528,
     375, -2567, -2567,    30, -2567, -2567, -2567, -2567,   498, -2567,
   -2567, -2567,   885, -2567, -2567, -2567, -2567, -2567,   -16, -2567,
   -2567, -2567, -2567, -2567,   428,   616, -2567,   436, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   -45, -2567,   430,   434, -2567,
   -2567, -2567, -2567,   446, -2567, -2567, -2567, -2567, -2567,   -64,
     375, -2567,   375,   456,    30, -2567,   896, -2567, -2567, -2567,
   -2567, -2567, -2567,  1218,   273, -2567, -2567, -2567,   874,   517,
     375, -2567, -2567,  1023,   305,   375, -2567, -2567,   375, -2567,
   -2567, -2567,   375,   375, -2567, -2567, -2567, -2567,   446, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  8761, -2567,   273,
   -2567,   930,  3367, -2567, -2567,   568, -2567, -2567,  1054,   434,
     521, -2567, -2567, -2567, -2567, -2567,  8581,   375, -2567, -2567,
     375,   674,   375,    30, -2567, -2567, -2567,   375, -2567, -2567,
     733,   689,  1099, -2567, -2567,   715, -2567,   747, -2567,   705,
   -2567, -2567,   764, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   664, -2567, -2567, -2567,   790,   807,   847,
     871,   882,   952,   956,   966,   972,  1044,  1049,  3367,  1055,
    5320,  1060,  1066,  1071,  1077,  1102,  1105,  1863,  1568, -2567,
   -2567, -2567, -2567,   349, -2567,   199, -2567,  3367, -2567,   234,
   -2567, -2567, -2567,    73, -2567, -2567, -2567,   959, -2567, -2567,
   -2567, -2567, -2567, -2567,   733,  1113,  1131,  1136, -2567,  1099,
   -2567, -2567,  1153, -2567,  1157, -2567,   754, -2567, -2567,  1160,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
      30,  1164,  1631,  1177, -2567,    30,    30,  1180,   375, -2567,
      15,  1646, -2567,  1006,  1178, -2567,  1017,  1244,  1694,  1697,
     375,  1700,  1704,   -99,  1076, -2567,   289,    42,    42,    42,
      42,    42,  5320,  1684,  1579,    53,  5320,  1135,  5320, -2567,
    5320,  5320,  5320, -2567, -2567, -2567,  1166,  1248,  1281,  5320,
    1270,  1294, -2567,  5320,  5320,  1311, -2567,  1320, -2567,  1066,
    1322,  1327,  1332,  1335,  1796,  7296, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  1348, -2567, -2567, -2567, -2567,
   -2567, -2567,   289,   289, -2567, -2567, -2567, -2567, -2567,  3367,
   -2567,   375, -2567,   375,  3367,  1313,   242, -2567, -2567, -2567,
   -2567,  1802, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    1349, -2567,  1349,    15,  1808,  1810,  1813, -2567, -2567, -2567,
    1815,  1816,   434,  1700,  1349,  1817,  1170, -2567,  1736, -2567,
   -2567,  1404, -2567,  1437, -2567, -2567, -2567,  1186, -2567, -2567,
    1836,  1417, -2567,  1381, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,  1244,  1381, -2567, -2567, -2567, -2567, -2567, -2567,  1384,
     268,   271,   239, -2567,  8064, -2567, -2567, -2567,  1393,  1881,
     371, -2567, -2567, -2567,  1430,  1402,   379, -2567,  -185,  1442,
    1443,   411,   423,  4787,  1444,  1445,   198,  1611, -2567, -2567,
     109,  1446, -2567, -2567, -2567, -2567,   437, -2567, -2567,  5588,
   -2567,  4133,  6341,  1696,  1696,  5320, -2567,  1364,  5320,  7296,
    1416, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  1217,  1883,
    6408,  7296,  1364,  1884,   438,  5320,  5320,  5320,  5320, -2567,
    5320,  5320,  5320,  5320,  5320,  5320,  5320,  5320,  5320,  5320,
    5320,  5320,  5320,  5320,  5320,  5320,  5320, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  5320,  5320, -2567,
   -2567,  1421,  5320, -2567,  5320,  1422, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,   289,  5320,  5320,  5320,
    5320,  1460,  1906,  1863,  1426,  3404,  1427, -2567,  3367,  1400,
   -2567,  1238,  1892, -2567,  1245, -2567,  1894,  1474,  1479,   440,
    1614,   447,   458,   473,  1452, -2567,   463, -2567, -2567, -2567,
     207,   375, -2567,   375,  1511, -2567,  5647,   521,  5950,  1905,
    -163,   375,  1916,   578, -2567, -2567,  1178,  1911, -2567, -2567,
   -2567, -2567,  1912, -2567,  1922, -2567,  1923, -2567,   375, -2567,
     375, -2567, -2567,  1700,  1927, -2567, -2567,  1298, -2567, -2567,
   -2567,   375,    42, -2567,  3367,    83, -2567, -2567, -2567, -2567,
   -2567,  1178,  1178,  1928,   -18,  1178,  1201, -2567,  1933,  1316,
    1295, -2567,    53, -2567, -2567, -2567,  1512,  7296,   519,  1514,
    6429,  1936,  1270,  1515, -2567,  1517,  1518, -2567,  6624,  6667,
    6736,  6793,  7357,  7415,  6341,  7462,  7606,  7935,  7856,  7913,
    7960,  8079,  4023,  1696,  1696,  1847,  1847,  3764,  7296,  6974,
    7188,  1364,  7296,  7239,  1364, -2567,  7296,  7296,  7296,  7296,
   -2567,  1942, -2567, -2567, -2567,  1964, -2567,  7296, -2567,   327,
    3367, -2567,  1524,  1954,   578, -2567, -2567,  1949, -2567,  1491,
    1955, -2567,  1956, -2567, -2567, -2567,  1959, -2567, -2567,    54,
   -2567, -2567,  1312,  1538,  1984, -2567,  1542, -2567, -2567, -2567,
     289,   289,   289,   375,  1070,   375,  1328,   260,   260,  1365,
     375,   375,   260,   260,   375, -2567,  1328, -2567, -2567,   375,
   -2567,  1228, -2567, -2567, -2567,   260, -2567, -2567, -2567, -2567,
     375, -2567, -2567, -2567, -2567,    62,    62,  5320, -2567, -2567,
   -2567,  1365,  1365, -2567, -2567,   260, -2567, -2567,   260, -2567,
   -2567,   375, -2567, -2567,   260, -2567, -2567,   289,   260, -2567,
   -2567,  5320,   260,   289,   375,   289,   260, -2567, -2567,   201,
     260,   260,   201,   260,   375,   201,   260, -2567,   260,   260,
     260, -2567,  1328, -2567, -2567,   289,   260, -2567, -2567,   260,
      25,   375, -2567,  1365, -2567, -2567,   260,  1112, -2567, -2567,
     289,  1323, -2567,   260, -2567,  4760,   289,  5320,    42,    42,
     260, -2567, -2567,  1070,   289,   408, -2567,  5320, -2567,  1265,
    5320,   260,   134, -2567,  5320,   260,  1966,   289, -2567,   260,
    5320, -2567,  5320,    62,   375,   260,   375,    42,   260,   375,
      42, -2567,   375,   187, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   501, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1123, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   912,   375, -2567,   669, -2567,
    1555, -2567, -2567, -2567,  1648, -2567, -2567,  1559,  1560,  1563,
    1564, -2567, -2567,  1339,  2013,  1572, -2567,  1573, -2567,   485,
   -2567,  1539, -2567,  1344, -2567, -2567,   464,  1178,  2000, -2567,
    1578,     5, -2567,  2002, -2567,  1385, -2567, -2567, -2567,  1351,
   -2567, -2567, -2567, -2567,  8375, -2567,  1166,  1583, -2567,  1166,
   -2567,  1166,  1166,  1166,  1166,  1166,  2008,  2009,  2010,  5320,
    1588,  2014,  5320,  1593,  1595,  1598,  1601,  1602,  1603,  3404,
    1604,  3404,  3404, -2567,   361, -2567, -2567, -2567,  1682,  1606,
   -2567,  1613,  1616,  1378,  1621, -2567, -2567,   375, -2567,   375,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   382,  1389,
     459,  1545,  1585, -2567, -2567, -2567, -2567,  1399,   474, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2066,  1397, -2567,
   -2567,  1597, -2567,  1365, -2567,  1543,   287, -2567, -2567, -2567,
    1592, -2567,  7296, -2567, -2567,  1428, -2567, -2567,  4204, -2567,
   -2567, -2567,   289, -2567, -2567,  1365, -2567,   -29, -2567, -2567,
    1760, -2567,    45, -2567,  1570, -2567, -2567, -2567, -2567,  2081,
   -2567, -2567,   659, -2567,  1415, -2567,  1419,  2081, -2567,  1447,
   -2567, -2567, -2567,  1620,   115, -2567,  1577, -2567,  1388, -2567,
   -2567, -2567, -2567,  1391,   270, -2567,  -134, -2567,  1432,  1371,
    1605,  1725,  1455, -2567, -2567,  1453, -2567, -2567,  5320,   131,
    1144,  5320, -2567,   125,   260, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,    79,    79,    79, -2567,    79,  3105,
      79,    79,  1467,   -29,  1467,  1467,  1175,  1175,  1467,  1467,
    1672,   -29,  1702, -2567,  2118, -2567,  1657,   481, -2567,  2134,
   -2567,   -29,    95,    40, -2567, -2567,  5320, -2567, -2567, -2567,
     851, -2567,  1193, -2567,   521, -2567,  5320, -2567,  5320,  1656,
    1660,  1662,  1665,  1398,  1685,  1193, -2567,  1749,   940,    75,
   -2567,  1510, -2567, -2567,   375, -2567, -2567,  1219, -2567,  2154,
   -2567,  2158,   375, -2567,   381,   222,  1544, -2567, -2567,  2168,
   -2567,  1462,  2168,  2171,  1464,  2168,  2171,  5320,  2168, -2567,
   -2567,   287,   289, -2567, -2567,  1707,   285, -2567, -2567,  1692,
     289,  5320,  1693, -2567, -2567,  2159,  2163,  2068, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,  1226,  1226,   260,   260,
     260,  2677, -2567, -2567,  2044,   912, -2567, -2567,   808, -2567,
   -2567, -2567,  1679, -2567, -2567, -2567, -2567,  8761,  1700, -2567,
   -2567, -2567,  1520,   375,  1178,  2170,    70,  1178, -2567,   435,
    1178,  1178,  1456,  1553,  1470, -2567,  8540,  8540, -2567,  1432,
   -2567, -2567, -2567, -2567,  1481, -2567,  8128,  1713, -2567,  1716,
    1717,  1718, -2567,  1718,  1718,  1719,  1720,  1723,  1724,   375,
     680, -2567, -2567, -2567, -2567,   182, -2567,    57,  2474, -2567,
   -2567,  1481, -2567,  1481,  1743, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  7296,   468,
   -2567, -2567,   482, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,  1706, -2567, -2567,   491, -2567, -2567,
   -2567, -2567, -2567, -2567,    30, -2567,    30,  1048,   116,  2196,
   -2567, -2567,   588,   171,   648,  2219, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,   375,  1513,   375, -2567, -2567,  1547,
     375,  1607,   375,   375,  1365,  1575,  1741, -2567,  1742,   118,
   -2567, -2567, -2567,  1365, -2567, -2567,  2224, -2567, -2567,  1550,
    1745, -2567, -2567, -2567,  1144, -2567,  1242,  2181,  1242, -2567,
    1193,   201,  5320,  5320,  5320,  1747, -2567, -2567,   289,   289,
    1365,  1554,  1193,    42,  1519,    25,   289, -2567,  1561,  5320,
    1829, -2567, -2567,  1628,   375,  1432, -2567,  3367, -2567, -2567,
   -2567,   375,  1366,  2236, -2567, -2567,  1571,   173,   287,   289,
   -2567, -2567,  2226,  2228, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  1896, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  4760,   289,
     289, -2567,  1175,  5320,  -119,  1256,  1259, -2567, -2567, -2567,
   -2567, -2567,   154, -2567, -2567, -2567, -2567,  2036,  1799, -2567,
    1804,   521,  5320, -2567,    60, -2567, -2567,   375,  2225,    42,
      42, -2567,  1608, -2567,    53,  1581,   289, -2567,   375,   375,
     375,  5320,   -59, -2567,  1623, -2567, -2567,   299, -2567,  1712,
   -2567,  1729,  5320,  1258, -2567, -2567,  1580, -2567,  2255, -2567,
    1667, -2567, -2567, -2567,   289, -2567, -2567,   168, -2567, -2567,
   -2567,   183, -2567, -2567, -2567, -2567,   375,    42,    42,   225,
     285,  2053,  1891,   289,   287, -2567,  1668, -2567, -2567,  2236,
    2241,  1814, -2567, -2567, -2567, -2567, -2567,  1893,  1893, -2567,
     223,  1670, -2567, -2567,   375,  1365, -2567,  1365,  1365, -2567,
   -2567,  1365,  1365, -2567,   375,  2035,   519,  1365, -2567,  2035,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   162,
     162,   457,  1078, -2567,   826, -2567,   808, -2567,    30,  2246,
   -2567, -2567,  1424,  1826, -2567,   205,  1178,  2251, -2567,  1178,
    1612, -2567, -2567,  1830,  1831,  1634, -2567, -2567, -2567,  2368,
    2368, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  1618,
     519,  1832,  8430,   552,  8375,  1752, -2567, -2567, -2567,   552,
     552,   552,   552,  1609,  8375,  8375,   120,  1705,    34,   375,
   -2567,  8375,  8375,  8375,  8375, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  1622,  -115,  1144,  5320, -2567, -2567,  1839,  1843,
    2246, -2567, -2567, -2567, -2567, -2567,  1818,  1819,  1820,   818,
    1822,  1823, -2567, -2567, -2567,  2185,   375, -2567,  2291, -2567,
   -2567,   660,  5272, -2567, -2567, -2567, -2567,   375, -2567, -2567,
     660,  1610, -2567,   382, -2567,  1629, -2567,  1669, -2567,  1861,
     273, -2567,  1640, -2567,  1671, -2567,  1731,  1833,   375, -2567,
   -2567, -2567, -2567,  4204,   375, -2567,  1654, -2567, -2567,  2181,
   -2567,  2181,  1650, -2567,  2321,  2328, -2567,  2329,  1708,  5320,
   -2567, -2567,  2333, -2567,  1673, -2567,  1807,  1675,  2171, -2567,
   -2567,  1687,  1097,   375, -2567, -2567,  1862,   260,  1073,  1453,
    1863,   365, -2567, -2567, -2567, -2567,  5320,  1365,  1144,  -199,
   -2567,   375,   375,  5320,    31,   -29,  2344,  1283,  2342,  2325,
    2326,  3105, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   289,
    1982, -2567, -2567, -2567, -2567,  2248,  5320,   521, -2567,  2094,
   -2567, -2567, -2567,  5320,    62, -2567,  1980,  2367,  2370,   495,
     497,   375,  1930,  1193, -2567,  3404,  1897,  1908,  1909, -2567,
   -2567,  1989, -2567,  5320,   -17, -2567,  1751, -2567, -2567,   686,
   -2567,  5320, -2567, -2567,  1732,   930, -2567,  1441,   375,  2384,
    8165, -2567, -2567, -2567,   289,  1144,   289, -2567, -2567,    74,
   -2567,  2171,  2171,  1695, -2567,  1812,  1821, -2567, -2567, -2567,
   -2567, -2567, -2567,    42,    42, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  3135, -2567, -2567, -2567, -2567,    42,  2488,
    2408,  2389, -2567,  1193,   875,   383,   170,  2261,   -25,  1070,
   -2567,   643, -2567, -2567, -2567,  1935,    82,  1365,   342,  1754,
   -2567,  1750, -2567, -2567, -2567, -2567, -2567,  1937,  1937, -2567,
   -2567, -2567, -2567,  1828,  1758,  2414, -2567, -2567, -2567,   823,
    1764,  1759, -2567, -2567,   289,   228, -2567, -2567, -2567,  1757,
    1078, -2567,   375,   375, -2567, -2567,   375,   636, -2567, -2567,
   -2567, -2567,  1969, -2567, -2567, -2567,   477,  1178, -2567,   553,
   -2567,  2003,  2004,  1178,  1178, -2567, -2567,  1521,  8375, -2567,
     402,  2449,  2006,  2451, -2567, -2567, -2567,  8375, -2567,   509,
    8375,  8375,  8375,  8375,   375,   510, -2567,   414,  2452, -2567,
   -2567,    80,  7532, -2567,  2033,   375,  1787,   552,  2071, -2567,
   -2567, -2567, -2567, -2567, -2567,  1521,  2436,  1521, -2567,  7296,
   -2567, -2567,  1983, -2567,  1948,  1951,   114,   114,   114,   522,
    2185,   114,  7532,   375, -2567,   525,   375,   527, -2567, -2567,
   -2567,  1987,  1988,  1990,  1481,  1481, -2567,  1992, -2567,  1993,
    1994,  1999,  2001, -2567, -2567, -2567, -2567,  1124, -2567, -2567,
   -2567,   530, -2567, -2567,   532,   375, -2567,   375,  1652, -2567,
     375,  1666,  5320, -2567,   375,  2465, -2567, -2567,   660, -2567,
   -2567,  1801,   660,   139, -2567, -2567, -2567,  1193,  5320,  5320,
    5320,  4905,  2483,  1365,   148, -2567,  1193,   375, -2567, -2567,
     375,   375, -2567,  1042, -2567, -2567,   404, -2567,  1824,  5320,
   -2567, -2567, -2567,  2481,  3367,  1991, -2567,  1835,  2492, -2567,
   -2567,  1193,  1871, -2567, -2567, -2567, -2567, -2567,   375,  2171,
   -2567,   287, -2567,  1899, -2567, -2567,   535, -2567, -2567, -2567,
     289, -2567,  4334, -2567,  1268, -2567, -2567,  2120,  2485, -2567,
    2108,  2110,  2011,  1840,  2112,  2030, -2567, -2567, -2567, -2567,
      29,  2105, -2567, -2567, -2567, -2567,  1989, -2567, -2567, -2567,
     244,   841, -2567, -2567, -2567,  2236,  5320,  2045, -2567,  2017,
   -2567, -2567, -2567, -2567,  2522, -2567, -2567, -2567, -2567,  2528,
   -2567,  1834, -2567,  2515,   -29,   375,  3222,  3222,  3222,  3222,
    3222,  3222, -2567,  2537, -2567,  2547,  3222,  3222,  3222,  3222,
    1896, -2567, -2567,  3222,   203, -2567, -2567, -2567, -2567,  2529,
    2544, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    2545, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   536, -2567,
   -2567, -2567,  2534, -2567, -2567,  1365, -2567,   519, -2567, -2567,
   -2567, -2567, -2567, -2567,  1914,  1915,   135, -2567,   643, -2567,
     114,  1895,   260, -2567,  2076, -2567, -2567, -2567,   375,   375,
     114, -2567, -2567,   192,  1365,  1092,  8375,   230, -2567,  5320,
   -2567,  5320, -2567, -2567, -2567, -2567, -2567,  1961,   260,   192,
    1365,  2562, -2567,   289,   375,  1002,  1002, -2567, -2567,  2565,
   -2567,  2565,   793,   793,  2565, -2567, -2567,  1905, -2567,  1178,
    2549, -2567,  1178,  1676,  1178,  1178, -2567, -2567,  2093, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,   182,  1481,  1901,  1481,
   -2567,  1481,  2133,  8375, -2567,  2135,  2138,  2139,  2140, -2567,
   -2567,   120, -2567,   120,   375, -2567, -2567,  8018,  1718,  7151,
    1718,  2577,  2587, -2567, -2567, -2567, -2567, -2567, -2567,   265,
    8375, -2567,  2092, -2567,  2271,   156,   383,   375, -2567,  2148,
   -2567, -2567,  4844,    89, -2567,  2373, -2567,    89,  1365,   672,
    2151,  2597,  1934, -2567, -2567,   537, -2567,   546,   818, -2567,
   -2567,   547,   197, -2567, -2567, -2567,   660, -2567,  2589,  2589,
    2590,  1938,    11,  2591,  2593,  2594,  2591,  2591, -2567, -2567,
   -2567,   343, -2567,   943,   375, -2567,   660, -2567, -2567, -2567,
    1957, -2567, -2567,  1958, -2567, -2567,  -168,   549, -2567,   375,
     554, -2567,  5320,  2173,  2610,   557,  1193,  2629, -2567, -2567,
   -2567, -2567,  5320,  2020,  2313,  5320, -2567, -2567, -2567, -2567,
     404,  1260,  1260,  2640,  -127, -2567,  2641, -2567, -2567, -2567,
    1260,   375,  2046,  1449,  2645,   375, -2567,  3367,   159,  1365,
    2643,  1193,   -75,  2344,  5320, -2567, -2567,  3105, -2567,  1931,
    5320, -2567, -2567, -2567,  2651,  3404,   289, -2567,  1228,   375,
     289, -2567,  2211,  3404,  3404,  3404, -2567, -2567,    29,  2105,
   -2567,  1896, -2567, -2567,  1252, -2567, -2567,  2037, -2567,  3367,
    5020,  8165,   255,  1079, -2567, -2567, -2567,  1995, -2567, -2567,
   -2567, -2567, -2567, -2567,    42,  3222,    42,  3222, -2567, -2567,
   -2567, -2567, -2567, -2567,   -29, -2567,  1282,  1284,  2488, -2567,
    2212,  2176,  8375, -2567,   170,   170, -2567, -2567, -2567, -2567,
     558, -2567,  2141, -2567,   114,   655, -2567,  1986, -2567,   561,
   -2567, -2567,  2659, -2567, -2567,  2067, -2567,  2666,  2658,  2658,
    2658,  2658,   114,   114, -2567, -2567, -2567, -2567, -2567, -2567,
    2659,  1998,   289, -2567,  2565, -2567, -2567,   375,   793,   793,
   -2567, -2567,   793,  2404,  1996, -2567,   620, -2567,  2230,  2238,
   -2567, -2567,  2647,  2239,  2012,  1521,  2015,  2018, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   575, -2567, -2567, -2567, -2567,
     256,   237, -2567,  7532,  7532, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  8540,  8540,  2203,  8540,  2207, -2567,  8540,   782,
    8375,  2689, -2567, -2567,  7532, -2567, -2567, -2567, -2567, -2567,
    2696, -2567,   245, -2567, -2567,  2271,  2023,  2026, -2567, -2567,
      62,    62,    62,  2681,    62,    62,    62,    62,    62,    62,
    2683, -2567,  2687,    62, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  4844, -2567,   289,  2040, -2567,  2213,  2691, -2567,
    2692,  2694,  2695,  2700,  2701,  2703,  1253,  2373, -2567,  2213,
   -2567, -2567,  2704, -2567,  2365,   114,  1475,   114, -2567, -2567,
    2185, -2567, -2567, -2567, -2567,  2283,  2284,   576,  1521,  2708,
    1521, -2567,  2730,   582,  2287,  2289,  2730, -2567, -2567, -2567,
   -2567,  1365, -2567, -2567, -2567,  2253, -2567, -2567,   943, -2567,
    2185, -2567, -2567,   375,   375, -2567, -2567,   375,  -278, -2567,
     660,   174,  2236, -2567,  2217,   174,   195,  1193, -2567,  2742,
    2262, -2567, -2567,  2301,  2147, -2567, -2567,   375,  1260,  3367,
    1531,   375,  1260, -2567, -2567,    42, -2567, -2567,  5320, -2567,
   -2567,   372, -2567, -2567, -2567,  1193,  2745, -2567,    42,  2236,
     289,  2457, -2567,  2729,  1812,  7296,  2731, -2567, -2567,   287,
    2275, -2567, -2567,  3404, -2567, -2567,  2312,  2315, -2567, -2567,
   -2567,   841, -2567,  1812, -2567,  5320, -2567,   387, -2567,  2134,
   -2567, -2567, -2567, -2567,  2269,  2363, -2567,  2747, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   375,
   -2567,   190, -2567, -2567, -2567,   114, -2567,   519,  2569,   586,
   -2567, -2567, -2567, -2567,   375,   114, -2567,   192,   192,  2161,
    5181,  5181, -2567, -2567,  8511,  2285, -2567, -2567,  2290,  2292,
   -2567,  2295,  2296,  2297,  2298,   375,   684, -2567, -2567, -2567,
   -2567,   591, -2567, -2567,  2592, -2567, -2567, -2567,   593,  2765,
    2765, -2567, -2567,   594,  2772,  2771, -2567,    97,   289,   192,
   -2567, -2567, -2567, -2567, -2567,  2518,  8761,  1178,  1703,  1178,
    1178,  2345, -2567,  1521,  2346,  1521,  1521,   120, -2567, -2567,
    2587, -2567,  2299,  2474,  2299,   196, -2567,  2299,   196, -2567,
    2299,  8540, -2567, -2567,  8375, -2567,  8375,  2577,   156, -2567,
   -2567, -2567, -2567,  1521, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   380,
    2788, -2567,   289,  1874, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,   395, -2567, -2567, -2567,
    2286, -2567, -2567, -2567, -2567,  2773, -2567, -2567,  2348, -2567,
    2775,  2353,  2777, -2567, -2567, -2567,  2355, -2567,  2322,  7532,
   -2567, -2567, -2567, -2567, -2567,   375,  2783, -2567,  -278, -2567,
   -2567,  2786, -2567, -2567,  2787,   375,  2271,   174, -2567,    42,
     -29, -2567,  2386,  1193, -2567,  5320, -2567,  2193,  2793,   -29,
   -2567, -2567,   490, -2567, -2567, -2567, -2567,   210,  2371, -2567,
   -2567,  1193,  2171,  2528,  2525, -2567,   -29,  2376,  2379,  2344,
    2343, -2567,  2429,  2387, -2567, -2567, -2567, -2567, -2567,  2541,
    2327,  5320,  2339, -2567, -2567, -2567,  1812, -2567,   595, -2567,
     289,  2243, -2567, -2567, -2567,  8375, -2567, -2567,   114, -2567,
    2354, -2567, -2567, -2567,  2659,  2243,  2638,  2638,  2396,  8430,
     552,  3774,   552,   552,   552,   552,   -70,  3774,  2658, -2567,
    3774,  3774,  3774,  3774, -2567, -2567,   114,  2832,   114,  2658,
     260,  7532, -2567,  2528,    96, -2567, -2567, -2567, -2567,  2398,
    2399, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   343, -2567,
   -2567,   603, -2567, -2567, -2567, -2567,   608, -2567,  2299,  2842,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,   289,  2788, -2567,
   -2567, -2567,   289, -2567,   289, -2567, -2567,  2227, -2567,  2554,
    2555,  2828, -2567, -2567,  2407,  2179, -2567, -2567, -2567,  2412,
   -2567,   114,   444, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567,  1193, -2567,  2413,  8718,  2381, -2567,
   -2567, -2567,  2188,   -29, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,  2416,   287, -2567,  2429,  2429,  2429,   841, -2567,  3367,
    2240, -2567, -2567,   375, -2567,  2528,    34,   182, -2567,  8287,
      34, -2567,  2419,  3774, -2567,   613,  3774,  3774,  3774,  3774,
    2843,   375,   614, -2567, -2567, -2567, -2567, -2567, -2567,  2388,
   -2567, -2567, -2567,  2577, -2567,   375, -2567,  1178,  1178, -2567,
   -2567, -2567,   282, -2567, -2567, -2567,  8375, -2567,  2089,  2089,
   -2567,  2089, -2567,  2089,  2089, -2567, -2567, -2567,  2393, -2567,
    1521, -2567,   618, -2567,   856, -2567, -2567,    79,    79,    79,
      79,    79,    79, -2567,  2851, -2567,   623, -2567,  5320,  1596,
   -2567,    37,  2429,  3404,  2429,  2344, -2567, -2567, -2567, -2567,
    2582,   398, -2567,   -29, -2567, -2567, -2567, -2567,   626, -2567,
   -2567,  1448, -2567,  2432,  3774, -2567,  2433,  2434,  2435,  2437,
     399,  2374, -2567,  2658, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,  2089, -2567,  2089, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1155, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  8718, -2567,  2882, -2567, -2567, -2567, -2567,
      59, -2567, -2567, -2567, -2567, -2567, -2567,    74, -2567,  8287,
   -2567,  1739, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    2865, -2567,  2867,   631, -2567, -2567,  1301,  1301, -2567, -2567,
    1301, -2567,  5320,    84, -2567, -2567,  2446,   255, -2567,  2223,
    2229,  2893, -2567,  2417,   400, -2567, -2567, -2567, -2567,  2453,
   -2567, -2567, -2567,   375,   375,  1739, -2567,  2874, -2567, -2567,
     279,  2233, -2567, -2567,  2422, -2567,   287, -2567,   375, -2567,
    2344, -2567
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2567, -2567, -2567, -2567, -2567,   350, -2567,   410,  -174, -2567,
   -2567, -1173,    41, -2567, -2567, -1851, -2567, -2567, -2567, -2567,
    -513, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2092, -2567,
    -995, -2567,  1890, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
     678, -2567, -2567, -2567, -2567,  1333, -2567,  1003, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  2231, -2567,   -38, -2567, -2567,
    2881, -2567,  2886, -2567, -2567, -2567, -2567, -2567,   751,   388,
   -2567,   756, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   -69,  1230,   424, -2567, -2567,  2564,     2,
   -2567,  2813, -2567, -2567,  2810, -2567,  2720, -2567, -2567, -2567,
   -2567, -2567,  2583,  2263,  1179,  2572,  -540,  1007, -2567, -2567,
   -2567, -2567, -2567,  1182,  -660, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,   113, -2567,  2391,  2721,    28,  2330, -2567,
    -228,  1626, -2567,  2552, -2567, -2567, -2567, -2567,  2556, -2567,
   -2567, -2567, -2567,  -396, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  2372, -2567,  2366, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -1047, -2567, -2567,  -465, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  -124, -2567, -2567,
    1138, -2567, -1098, -1183,  -532, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567,  1940, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    -593, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2130, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567,  -511, -2567,  -102,
   -2567, -2567, -2567, -2567,  2526, -2567, -2567,  -203, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    1674, -2567, -2567, -2567, -2567,   936, -2567, -2567, -2567, -2567,
   -2567, -1370, -2567, -2567,   931, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -1135,  -883,   801,  1101, -2567,
    -229,  -575,   760, -1142,  1411, -2567,   724, -2567, -2191,    -3,
    -636, -2567, -2567, -2052,   322,  1837, -2567, -2567, -2567,   628,
    1346, -2567, -2567, -2567, -2567, -2567, -2567,   384, -2567,    77,
   -2567,  1354, -2567,  1025, -2567,   709, -2567, -2567, -2567, -2567,
    -493, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
     812, -2567, -2567, -1579, -2567,  1013, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1516, -2567, -2567, -2567, -2567, -2567, -2567,
    -130, -2567, -2567, -1761, -2567, -2567, -2567, -2567,   127, -1985,
   -2567, -1141, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2956, -2567,
   -2567, -2567,  2885,  2932,   610, -2567, -2567,  -219, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2933, -2567,
   -2567,  2957, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  2041,
   -2567, -2567, -2567, -2567, -2567,  1069, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,  -706,  2215, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  2058, -2567, -2567,   -43, -2567,
   -2567,  1068, -2567, -2567,  1401,  -188,  2657, -2567, -2567, -2567,
   -2567,   455, -2567, -1071,  1965,  1372, -1475,  1457, -2567,  1072,
    1755,   -26,  -208, -2567,  2214,  1552, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567,  1477, -2567, -2567, -2567,
    -792, -2567,  -596, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
    -418, -2567, -2567, -2567, -2567, -2567, -2567,   432, -2567,  -807,
    1569,   592, -2567, -2567, -2567, -2567, -2567,   247, -2567,  -209,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  1458, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,  -535, -2567,  1126,  2557, -2567,
   -2567,   257, -2567,  -623, -2567, -2567,   278,   580, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567,   753, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,   200, -2567,   -65,   -53, -2567, -2567,   -37, -2567, -2469,
   -2567,   227,   888, -1384, -2567, -2567, -2567,  1249, -2567, -1736,
   -2567, -2567, -2567, -1740, -2567, -2567, -1726, -2567, -2567, -2567,
   -2567, -2037, -2567,  1269,   941, -2567, -2567, -2567, -2567, -2567,
     720, -2567, -2567, -2567, -2567, -2567, -2567,  -391, -2567, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567,    43, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,
   -2567, -2567, -2567,  1395, -2567,  1403, -2567,   707,  1058, -2567,
   -2276,   130, -2567, -2567, -2567, -2567, -2567, -2567,   284, -2567,
   -2567,  -182, -2567,  -721, -1372, -2567, -2567, -2567, -2567, -2567,
     252, -2567, -2567, -2567, -2567, -2567, -1695, -2567, -2567, -2567,
   -2567, -2567, -2567, -2170,   994, -2567, -2334,  1081, -2567, -2567,
   -2054,   370,   374,   647, -2567, -1910, -1754, -2567, -2567,    71,
    -252, -2567, -2567, -2567, -2567, -1615, -2567, -2567, -2567,   276,
   -2567,   604,  -673, -2567,   642,  -326,  1433,    26, -1859,   630,
     666,   397, -2567, -2567, -2567, -2567,  2460, -1249, -2053,  3074,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,  -401, -2567,
   -1676, -2567,  1806, -2567, -2567,   542,   649, -2567, -2077,   652,
     164,   469,   476, -1633, -2019,  1360,    90,   662, -1300, -2567,
    1363, -2567, -2567, -2567,  1461,  -669, -2567, -2567,  -183,  1825,
   -2567,   564, -2567, -2567,   759,   177, -2567, -2567, -2567, -2049,
     -56, -2056, -2567,  -850, -2567, -2567, -2567, -2567,  1493, -2567,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2511,
     -73, -2567, -2566, -2178, -1341, -1115, -2567, -2567,   -61, -2567,
   -2567, -2567,   570, -1099,  1353,  -759,  1972,  1638,  1636, -1497,
   -2567, -2567,   583,   929,   217, -2567, -2567, -2567, -2567,  1655,
   -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567, -2567,   275,
    1740,  2566, -2567, -2567, -2567, -2567
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
     420,  1945,  1946,   964,    66,   592,   437,  2132,  2462,  2573,
      79,  1486,    39,  1487,  2133,  2108,   305,   108,    39,    66,
      94,  1012,  2673,  2460,   244,  1893,  1113,   421,   422,    39,
     115,  1053,  1056,  2958,  2959,  2960,   191,   122,   435,   118,
      39,  2175,   129,  2650,    39,   131,   283,  2048,  1077,   134,
     135,   975,   341,  2604,   979,   191,  1445,   283,   342,   343,
     592,  2927,  1752,   970,  1753,  1491,    39,    39,    66,  1089,
      39,  1579,  1089,  1081,  2060,  2061,  2062,  2063,  2309,  2527,
    1459,    79,  1098,  1624,   239,   204,  1089,   241,   608,   243,
    1089,  2962,  2325,  1488,   247,   609,  1459,  1115,  1642,  1057,
    1076,    39,  1089,    39,  1098,  1057,  1205,    39,   423,  1619,
    1127,  1088,   439,  1098,   441,   523,   442,   443,   444,  1543,
    1137,    39,    39,  1629,  1201,   449,    39,  1152,  2517,   460,
     461,   369,    86,  1057,  1195,    39,   374,   375,  1856,  2852,
    1620,  1057,  2719,    39,  1057,  1127,    39,  1735,     1,  1127,
    1446,  1447,     2,  1127, -1970,  1735,   339,    39,    39,  1098,
    3092,     3,  1098,  2693,   334,  1083,  1148,  1153,   592,  1151,
    1237,   283,  1249,  1250,    39,   592,  1608,   603,  1196,    39,
     283,  1319,  1320,    39,   604,  2053,  1106,   191,    39,  1099,
    1856,  2036,   191,  2363,  1545,  1546,   367,  2453,  2456,  2456,
    3081,  2684,  2456,  2686,   578,   377,  2695,   334,   359,  2696,
    2697,  2698,  2699,  2700,  2701,  1608,  3012,   406,   283,   337,
     338,    39,  2693,    66,   418,   418,   418,   418,   418,  2572,
     106,    39,   418,   574,  2695,  1190,   576,  2696,  2697,  2698,
    2699,  2700,  2701,  2754,  1879,  1207,  2329,    39,  1222,  2332,
    1624,     4,  1228,  1527,  1528,  2602,  3314,    39,  1234,  1860,
    1236,  1861,  1259,  1862,  3180,  2518,   283,  1319,  1320,    39,
   -1970,   283,  1249,  1250,    39,   106,    39,  3082,  3083,    66,
      66,   617,  1916,     5,   620,    86,    62,  2637,   524,   594,
     526,   691,   334,  2638,  2639,  2640,  2641,  2642,   955,  1910,
     669,   628,   629,   630,   631,  1816,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   968,    79,  2690,   334,   283,  2797,  1320,
    2184,  2086,  2857,   649,   650,  2892,   584,  2184,   652,  1885,
     653,  2235,  1811,   437,   592,   331,    62,  2839,  1933,  1956,
    1068,  1143,   334,   656,   657,   658,   659,  2100,  3464,  3075,
    3231,   667,    39,   334,  3450,  3487,  1791,  2397,  1201,  2531,
      39,  1956,  2175,   586,   587,   588,   592,  1866,  1976,  1977,
     969,  1601,  1602, -1970,  2075,  2815,   191, -1970,   592,  1937,
    1609,   977,  2191,  1201,    62,    39, -1970,    51,  2258,  1057,
    1649,    39,   612,  1139,  3300,   677,     7, -1970,    62,  1259,
    2693,     5,   680,  3076,  1311,    61,  1122,    39,  1129,    56,
       1,  2259,  2436,   682,    32,   535,  1308,  1469,   686,  1609,
     691,  2621,  2192,  1755,  2816,  3084,     1,   545,   119,    89,
       2,  2630,  1024,  1305,    39,  1259,  1540,  1755,    51,   595,
    1306,    62,   191,  1625,  1397,  1398,  1761,  2789,    52,  3495,
     592,   378,   592,   324,   325,   326,   327,   328,   324,   325,
     326,   327,   328,    66,  2403,  2403,   946,    62,  1195,  1696,
     851,   944,  1961,     8,  1399,  1400,  1401,  2458,   379,  1139,
    2106,  1880,  2466,  1558,    62,  2484,    62,  2486,  1470,   947,
    2547,  2608,  2777,  1052,  1961,   411,  1575,  2840,   692,   588,
     692,  2777,  2777,    44,  2817,    39,  1437,    85,   692,  2820,
     286,  1131,  2820,  2915,    86,  2087,  2925,   412,   191, -1970,
   -1970,  1934,     6,  2335,  1581,   406,  2723,   406,  1052,   579,
    2987,  3055,  2949,  2949,  2949,  2949,  2880,  3062,   967,   418,
    1917,  3148,   972,  2911,  1262,  2198,  3168,  2532,  3168,  3176,
    3283,  1603,  1776,  2076,  3301,  1192,  1193,   107,  3322,   418,
      87,    88,  1625,  3322,  2077,    39,  1913,  3250,  3384,  3384,
       7,    60,  2984,  2775,  1258,  2326,   978,  3093,  3423,  1251,
      62,  3439,    89,  2619,  1243,  1492,  3168,  1246,  2858,   986,
    1820,  1130,  1639,  1152,  1195,    33,  2782,   605,  1324,  1312,
    2618,     8,  3154,  2371,  2037,    62,  2374,  1787,  2755,  1877,
    3007,  1656, -1970,  2072,  1190,  3308,  2702,  2703,  1052,  1559,
    2336, -1970,  1261,  3116,  1560,    39,  1566,    62,  3181,  2853,
       9,   335,  3496,  1641,  2612,  1143,  2049,    39,  1493,  1547,
    2067,  2790,  3127,  3184,  2702,  2703,  1656,    66,    66,    66,
    1044,    66,  1048,  1050,    62,  2989,  1058,  1060,  1061,  1916,
    2631,  1066,  1466,  1050,  1697,  1978,  1069,   575,    66,  1580,
     577,  2704,  1720,     5,   529,  1448,  1460,  1061,  1739,  1252,
    2207,  1763,  1894,  1489,  1324,  3057,   304,  3059,  1058,  1058,
    2783,  1262,  1485,  3052,  2811,  1823,   415,   304,  1061,  2704,
    2812,  2414,   415,   610,    66,   110,  1550,  2907,  1691,  2190,
      66,  1061,    66,   415,  2501,  2920,    66,  3315,  2501,    66,
    2506,  1116,    66,  3071,   415,   936,  1548,  1262,  1224,  1050,
    2448,  1822,    66,  1736,  1604,  3100,  1035,   418,  1133,  3105,
    1058,  1610,  3001,  1837,  1140,  1324,  1698,    66,  3140,  1701,
    1702,  2398,  1494,    66,   971,   418,   418,  3286,  2263,  1023,
      66,    66,    66,   684,  2448,  3098,  1218,  3197,  2200,  1225,
     585,  3290,  2448,  2245,    66,  2448,  1711,  3453,   593,  2364,
    1610,  1238,  1259,  1238,   418,   332,  1238,   418,  3009,  1238,
      66,  1107,   606,  1383,     6,  1863,    77,  2185,  2705,  2263,
      39,  3085,  2893,  1864,  3109, -1970, -1970, -1970, -1970, -1970,
     598,   304,   111,   112, -1970,  2471,  2472,  2356,  2643,  3130,
     304,    89,   599,  1541,  2949,  2949,  2705,  3232,  2949,   119,
    3436,  3451,  3488,   288,  1699,  1368,   613,  3010,  1368,   678,
    1766,    10,  1402,  3343,  1202,   667,   681,   667,   667,  2014,
    2411,  1690,    39,  1767,  1260,  3174,   291,   683,   304,  2317,
    2226,  1712,   687,  1307,  2706,     1,  3048,  1756,  3051,     2,
    1824,  1825,  1826,     8,  1542,   333,  2379,  1713,     3,   121,
    3194,  1757,  3195,  3196,  1267,  1647,   991,  1844,  2912,  2913,
    1762,  2834,  2706,  1287,  2220,  3282,  2221,   117,  1261,  2994,
    1766,  2997,     9,  3376,  3000,   161,   304,    39,  2404,  2410,
    3212,   304,  1766,  1767,  2707,  2708,    90,  1302,  1300,  2054,
    1714,  2459,  3262,  3214,  2464,  1767,  2467,  1917,  1403,  2485,
    1605,  2487,  1055,  1055,  2548,  2609,  2778,  1055,  1055,   297,
    3303,  1340,  2707,  2708,  2654,  2779,  2781,  1921,  2818,  1902,
    1055,  3311,  2382,  2821,   625,  1768,  2825,  2916,   696,  1715,
    2926,  1878,  2155,  1606,  2156,  3242,   950,   304,     4,  2375,
    1055,  1404,  3215,  1055,  2988,  3056,  1891,   952,   123,  1055,
    1560,  3063,  1386,  1055,  1393,  3149,   692,  1055,  1716,   127,
    3169,  1055,  3175,  3177,  3284,  1055,  1055,  1717,  1055,  1909,
     992,  1055,  3323,  1055,  1055,  1055,  3144,  3324,    91,   953,
    1924,  1055,  3385,  3392,  1055,  1768,  3152,  3408,   198,  2977,
    1058,  1055,  3424,    66,  1781,  3440,  1694,  1768,  1055,  1700,
    3475,   300,   197,  2055,  3200,  1055,  2780,  3205,  3002,    66,
    3207,  2586,  1058,   301,   302,  1045,  1055,    39,   201,  1143,
    1055,   303,  1791,  1415,  1055,  2949,  2242,  3174,  3174,   249,
    1055,  2949,  2949,  1055,  2949,  2949,  2949,  2949,  1421,  1770,
    1766,  2380,    62,  2949,  1262,  1416,  3287,  3313,    32,    33,
    2543,    66, -1970,  1767,  1790,  1771,  1140,  1138,    92,    39,
    1422,  2957,  2957,  2957,  2957,   265,    93,  1140,  2674,  2723,
    2676,  3409,  2677,   324,   325,   326,   327,   328,  2799,   993,
     242,    66,    66,    66,  1655,    66,  1734,    66,    66,  1475,
    3167,    39,  2022,    66,    66,   251, -1970,    62,     5,  1770,
    2315,  2917,  3366,  3367,  3368,  2038,  2772,  2327,  2040,  2921,
    2623,  1770,  2056,  1010,  1477,  1771,  1013,  2383,  1477,    66,
      61,   258,    39,  1659,  1263,  1264,  1265,  1771,  1956,  3375,
    1573,  2180,    66,  3381,  1524,  1266,  2649,  2149,  1201,   261,
      39,  1585,  1534,  2348,    66,   980,  3003,   981,  3004,  1593,
      13,  1052,  2349,   259,  2225,  1768,  1131,  2949,   114,   366,
    2949,  2949,  2949,  2949,  1586,    39,    39,  3208,    66,    66,
     262,  1635,    13,    39,  1070,    39,  2350,    66,  2800,  2351,
    1838, -1970,  3410,  2168,  2978,  2169,  3411,  1817,   363,    39,
    3432,  2216,  3434,    66,    66,  2352,   266,  2882,  3042,    39,
      39,  1437,  1881,    39,  3145,  1883,    39,  3407,  1540,  3288,
    2528,  2201,    39,   267,  2551,    39,  2801,  2162,  3325,     6,
    1693,  1525,  1526,  1850,  2314,  1529,  1530,   167,  2903,    39,
    2905,    39,  1091,  1340,  1340,  2023,  1421,    62,  2168,   984,
    2169,   985,  1075,  1340,  2186,  1764,  1100,  1765,  2949, -1970,
    1105,  1826,  1452,   268,  2024,  2025,  1733,  2949,  1422,  1453,
    1152,  1961,  1119,  1093,  1740,   437, -1657,     7,   946,  1770,
    1766,  1059,  2213,  1049,  2026,    39,  1102,   269,   534,  1139,
    2802,  1560,  2022,  1767,   540,  1771,  1899,  1900,   270,  2170,
    1289,   947,  2171,  1195,  2803,   191,  1800,  2457,     8,  2353,
    2461,  2234,  2453,  1085,  1086,  3113,  1854,  2478,  2479,  2480,
    1057,  1139,    39,    39,  1956,  1777,  1475,  2889,    39,  1782,
    1788,  1782,  2993,  2993,  2822,  2993,  2862,     9,  2993,   111,
     112,  1794,  1796,  1797,  1941,  1942,    66,  1801,  1803,  1804,
    1805,  1058,    62,  1571,  2170,    39,  1577,  2171,  1209,  1055,
    1058,  2902,  2354,  2957,  2957,  1135,  3080,  2957,   271,  2355,
      62,  1140,   272,    66,  2033,    66,  2859,    66,    66,  1956,
    3458,    39,   273,   111,   112,    66,    66,  1058,   274,    66,
     418,  2248,   418,    66,  1242,  1768,    62,  1245,    39,  2846,
    1248,  1140, -1970,    62,  2804,    62,    39,  1210,  1853,  1140,
    1703, -1970,  1704, -1970,  2507,    66,    66, -1970,  2508,    62,
    2805, -1970, -1970,  3183,  1706,  3049,  1707,  2519,  3204,    62,
      62,  3204,    39,    62,  1121,  2023,    62,  1956, -1970, -1970,
   -1970, -1970,    62,  1128,  1211,    62,  1578,  1276,  1553,  1554,
    1555,  1556,  2540,  -296,  2024,  2025,  2381,  1961,  1277,    62,
     275,    62,  2386,  2387,  1769,   276,    66,    66,  1795,    66,
      39,   278,    66,    66,  2026,  3293,   318,  3296,  3297,  3298,
    3299,  3103,   319,  1055,  1055,  1055,  2502,   320,    39,  1241,
    2867,  3410,  1244,   321,  1897,  3411,   418,   418,  2875,  2876,
    2877,   418,  1798,    66,    39,  1906,  1907,  1908,  1278,  1770,
    2481,  1223,  1961,  3415,   440,  1229,  1995, -1970,   322,  1233,
   -1970,   323,  1279,  3158,   330,  1771, -1970,  1996,   427,   354,
    3428,    66,   383,   428,   429,   430,  1282,  1283,  -296,  2544,
    2495,  1212, -1970,  1238,   418,   418,  3426,   355,  1997,  2030,
      66,    66,   356,    39,  -296,  1998,  2509,  2510,  1826,  2513,
     427,  2089,  1802,  1999,    39,   428,  2041,   430,  2042,   360,
    1961,  1980,  1058,   361,  1058,  1058,   365,  2534,  1058,  1058,
     370,  1990,  3415, -1970,  1058,  2000,  1347,   371,  2045,  2580,
    2046,  2199,  2053,   372,  2957,  3285,   376,  -296,   392,  3428,
    2957,  2957,   381,  2957,  2957,  2957,  2957,  2490,    66,    39,
     174,  1280,  2957,   346,   347,   348,   382,   384,  1213,  2034,
    1152,  2493,   175,    39,   450, -1970,  1195,   391, -1970, -1970,
    2668,  2993,  2669,   385,  1417,  1418,  -296, -1970,   424,   425,
     426, -1970,  1531,  1532,  2577,  1426,   483,   484,   485,  1340,
     400,  1340,  1195,   401,  2272,  2274,   407,  3189,  1214,  3190,
     410,  1340,  1340,  1058,   447,  -296,  2080,  1440,  1340,  1340,
    1340,  1340,  1535,  1536,  -296, -1970,   386,   445,   486,  1357,
     413,  1140,  1359,   393,  1360,  1361,  1362,  1363,  1364,  1430,
    1431,  1432,  2212,  1386,  3469,  2284,    39,   448,  1818,   394,
    1818,  1925,   112,  1777,  2017,  2018,  2181,  2182,  1782,   451,
     459,   667,  1263,  1264,  1788,   387, -1970,  1782,  2950,  2950,
    2950,  2950,  3441,  3442,  1215,   452,  2957,   462,  3119,  2957,
    2957,  2957,  2957,  2795,  2796,  2147,   463,  1726,   465,  1727,
    1728,  2151,   395,   466,   388,  3156,  3157,  2645,   467,  2646,
    3294,   468,   469,   389,   516,  3204,  3294,   528,   530,  3304,
    3305,  3306,  3307,   181,   537,   532,   538,  2826,   453,   539,
    2178,   541,   542,   546,   547,   487,   488,   489,   490,   491,
     492,   396,   548,   552,  1058,  1140, -1970,   182,  2194,  2195,
     562,   418,   563,   493,   494,   495,   564,   567,  2665,   485,
     572,  2667,  2856,  2670,  2671,   582,    66,   454,  3121,   590,
     397,   324,   325,   326,   327,   328,   583,  2957,   591,   398,
     618,   596,   597,   601,   602,   611,  2957,   622,  2223,   486,
      66,   183,   621,   623,   626,  1711,   455,   651,   654,   660,
     184,   661,   662,   668,   670,   456,   671,  3253,   672,   673,
     674,  1500,    66,   675,  2249,  1593,  3261,  1340,   676,   679,
     697,    66,  1140,    66,   685,     1,   951,   956,   958,  1947,
    1948,  1949,   966,  3267,  1950,  2388,  1951,  1952,   959,   960,
     418,   418,  3383,   965,   976,  3386,  3387,  3388,  3389,   982,
     983,   990,   997,   995,   999,   418,  1000,  1001,  1018,  1021,
      66,    66,    66,  1026,  1027,  1029,    66,  1030,  1152,  1152,
    2828,  1031,  1032,  2833,  1058,  1034,  1037,  1038,  1721,  1039,
    1712,  1040,  1230,  3219,   185,   186,   487,   488,   489,   490,
     491,   492,   496,  1150,  1291,   497,  1713,  1292,  1293,  1294,
    1850,    66,  1295,  1296,   493,   494,   495,  1297,  1298,  2370,
    2370,  1299,  1301,  2370,  1304,  1303,  1309,  1310,  1313,  1314,
    2389,  1315,  1358,  1365,  1366,  1367,   340,  1370,  3312,  1371,
     345,  1384,  1373,  3445,  1374,  1340,  2390,  1375,  1190,  1714,
    1376,  1377,  1378,  1380,  1340,  1385,  1391,  1340,  1340,  1340,
    1340,  2409,  1389,  1414,  1058,  1390,  1807,  3220,  2415,  1340,
    1392,  1419,  2433,  1420,  1423,  1812,  1424,  1427,  1433,  1425,
    2950,  2950,   191,  1444,  2950,  1450,  1451,  1454,  1715,  2391,
    3360,  1455,  1462,  2449,  2449,  2449,  1458,  1457,  2449,  1340,
    2463,  1463,  1835,  1777,  1465,    71,  1474,  3015,  3016,  3017,
    1479,  3019,  3020,  3021,  3022,  3023,  3024,  1716,  1522,  1477,
    3027,  1481,  1055,  1538,  1065,   498,  1717,  1482,  2392,  3221,
    1501,  3222,  2488,  1539,  2489,  2491,  1074,  2492,  2494,  1543,
     499,  2496,  1567,  1581,   500,  1782,  1568,  3223,  1569,  1782,
      66,  1570,  1576,   496,    66,  3224,   497,  2393,  3094,  3225,
    1058,  2449,  1590,    66,  2178,  1094,  2394,  2524,  2524,   162,
     194,  1574,  1592,  1616,  1615,  1617,   592,  1618,  1627,  1630,
     501,  1111,  1112,  1623,  3226,  1631,  3110,  1118,    66,  1632,
    1120,  1633,  1681,  1689,  1692,  2542,  1695,  1705,    66,  1722,
    3438,  3365,  1723,  1724,  1725,  1729,  1730,    66,   502,  1731,
    1732,    66,  3416,  3417,  3418,  3419,  3420,  3421,  1953,  1754,
    1760,  1954,  1780,  1955,  1793,  1808,   503,  1809,  1810,  1813,
    1814,  1815,  1445,  1829,  1836,  1550,   194,    66,  1845,  1847,
    1843,  1856,  1858,  1956,  1869,  1889,  1886,  1870,  1888,  1920,
    1898,  1055,  1901,  1957,  1927,   194,  1913,  1502,  1903,  1992,
    1928,  1625,  2587,  1503,  1504,  1505,  1922,  1970,  1930,  1968,
    1971,  1979,  2031,  1973,  1958,  2035,   498,  2039,  1720,  2043,
    2044,  2049, -1970,  2064,  1055,  1506,  2072,  1984,  2090,  1985,
    1986,   499,  2091,  1988,  1989,   500,  2106,  1959,  2047,  2008,
    2103,  1960,  2085,  2137,  2096,  2097,  2098,   504,  2101,  2102,
    2139,  2950,  1058,  2138,  2140,  2141,  3108,  2950,  2950,  2144,
    2950,  2950,  2950,  2950,   414,  2153,  2158,  2449,  2135,  2950,
    2157,   501,  2142,  2159,  2160,  2626,  1990,  2449,  2163,   944,
    1980,  1058,  2161,  1340, -1970,  2165, -1970,  2164,  2179,  1624,
    2202,  2204,  2205,  3128,  3213,  2166,  1980,  1058,  2209,   502,
      66,  2370, -1970,  1850, -1970,  2898,  2167,  2900,  3433,  2214,
   -1970,  2211,  2218,   505, -1970,  2219,  1961,   503,  2071,  2224,
     521,   522,  1871,  2227,  2051, -1970,  2058,   194,  1743,  1744,
    1507,  2887,   194,  1508,  2228,  2229,  2058,  1347,  2252, -1970,
    1340,  1509,  2238,  2081,  2082,  2083,  2084,  2232,  1058,  1266,
    1058,  2415,  2246,  2312,  1340,  2313,  1340,  2263,  2324,  2345,
    3220,  2330,  2265,  2340,  3255,  3500,  2865,  1340,  2338,  2343,
    2339,   667,  2449,    66,  2433,   191,  1510,  2344,  2360,   667,
     667,   667,  3265,  2950,  2359,  2449,  2950,  2950,  2950,  2950,
    2367,  2378,  2384,  2385,  2399,  2400,  2401,  2413,   504,  2430,
    2435,  2437,  2439,  1782,  2442,  2441,  3188,  2445,  3191,  3192,
    2499,  1511,  1993,  2468,  2469,  2504,  2470,   191,  2473,  2474,
    2475,  1788,  3221,  1782,  3222,  2476,  1994,  2477,  2515,  2535,
    1512,  1513,  1741,  1742,  1743,  1744,  2147,  2539,  2533,  2187,
    3223,  1514,  2541,    66,  2553,  2537,  1515,  2545,  3224,  2538,
    2554,  2556,  3225,  2557,  2559,  2560,  2561,  1745,  1746,  1747,
    1748,  1749,  1750, -1970,   505,  2558,  2578,  2581,  2178,  1995,
    2847,  2579,  2849,  1540,  2950,  2449,  1058,  3226,    66,  1265,
    1996,  2585,  2594,  2950,  1195,  1516,  2285,  2286,  2287,  2288,
    2289,  2290,  2596,    66,  2605,    66,  2871,    66,  2606,  2607,
    2610,  1997,  2624,  3256,  2614,  2615,  2622,  2652,  1998,  2647,
    2657,    66,  1078,  1078,   655,  2666,  1999,  1517,  1340,  2672,
    3187,  2675,  2678,  2693,  2680,  3345,   194,  2681,  2682,  2683,
    2758,   418,  2256,   418,  2694,  2714,  2717,  2726,  2000,  3280,
    2774,  1055,  2775,    66,    66,  2759,  2760,  1055,  2776,  1340,
    3170,  3171,  3172,  3173,  2761,  2784,  2787,  2791,  2788,  2793,
    2794,  2449,  2823,  1745,  1746,  1747,  1748,  1749,  1750,  2334,
    2824,  2813,  2814,  1055,  2827,  2946,  2946,  2946,  2946,  2449,
    2449,  2829,  3107,  2291,  2830,  2837,  2841,  2845,  2762,    66,
    2848,  2855,   194,  2863,  2971,  3112,  2866,  2763,  3172,  3173,
    2874,  2908,  2909,  2885,  2927,  3102,  2924,  2917,  2928,  2897,
    1078,  1735, -1970,  2981,  2976,  2001,  2930,  2931,  2969,  2979,
    1253,  2002,   283,  1319,  1320,    39,  2764,  2980,  2982,  2995,
    1340,  1340,  2983,  2998,  3006,  2985,  1321,  1322,  2986,  1340,
    1340,  3008,  1340,  3013,  3014,  1340,  3018,  1340,  3025,  2071,
    1347,  1340,  3026,  3032,  1643,  3033,  3035,  3036,  2801,  2402,
    3037,  3038,  2405,  2406,  2407,  2408,  3039,  3040,   194,  3041,
    3046,  2765,  3053,  3054,  3058,  3060,  3064,   191,  3065,  3069,
    3089,  1745,  1746,  1747,  1748,  1749,  1750,  3095,  3096,   667,
    3097,    66,  3098,  3111, -1970,  3115,  3117,  3120,  1041,  1042,
    1043,  3124,  1046,    66,  3125,  3133,  1260,  3136,  3146,  3140,
    3168,  3159,  2449,  3050,  2449,  2766,  3160,  3178,  3161,  1072,
    2932,  3162,  3163,  3164,  3165,  3179,  3185,  1745,  1746,  1747,
    1748,  1749,  1750,  3217,  3193, -1838,  3198,  3235,  1058,  3234,
    2772,  3236,  3238,  3239,  3240,  1835,  3395,  3396,  3241,  3245,
    3072,  3073,  3247,  3248,  2496,  1096,  3258,  1782,  3254,  3260,
    3264,  1101,  3266,  1103,    66,  3268,  3425,  1110,  3269,  3270,
    1110,  1341,  3272,  1110,  2524, -1970,  3274,  3104,  2524, -1970,
    3289,  3279,   418,  1123,  1736,  3291,  3309,  3317,  3318,  3326,
    3336,  3337,    66,  1644,  3338,   418,  3339,    66,  1123,  3340,
    3252,  3341,  3359,  3346,  1186,  3364,    66,  3358,  3382,  3390,
    3372,  1046,  1199,  1203,  3393,  3406,  3422,  1219,  2798,  2292,
    3435,  3444,  3446,  3447,  3448,  1231,  3449,  3462,  3452,  1055,
    1055,  3473,  2293,  3474,  2689,  3481,  2692,  3483,  3485,  3486,
    3494,  1255,  3489,  3484,  3499,  1139,  3137,  3498,  2870,  2819,
    3461,  1381,  2449,  1253,  2570,  1912,    57,  2237,  2520,  2844,
    1036,  2626,  2449,    58,  1980,  1980,   543,  2946,  2946,  2529,
    3479,  2946,   200,   205,   353,   544,   536,  1028,   688,  2092,
     358,  1708,  3166,  2093,   571,   989,   962,   569,  3459,  1217,
     961,  2150,  1372,   607,  2294,  1645,  2368,  2611,  2376,  1685,
    2295,  2511,  1940,  1646,  2196,    66,  1980,  2896,  2262,  1647,
    2584,  1648,  3135,  1944,  3482,  2516,  2282,  3263,    54,    68,
      69,  1840,  1649,   136,  1058,    55,  2635,  2663,  2244,  1290,
    1117,   527,  1140,  2247,  1926,  1140,  1967,  1876,  1340,  2296,
    2251,  1340,  2651,  1340,  1395,  2449,  3218,  1621,  1347,  3327,
    1650,  1831,  3465,  2891,  1149,  1874,  3045,  1821,  3335,  2215,
    1892,   627,  3251,  2297,  3044,  3091,  1651,  2770,  1687,    66,
    3028,  1652,  3249,  2298,  2299,  2947,  2947,  2947,  2947,  2300,
    2505,  3246,  2136,  1653,  3074,  2105,  2616,  2465,  3468,  2301,
    1654,  3211,  2636,  2071,  2010,  2071,  2342,  3153,  3047,  3342,
    3070,  2412,  2011,  2990,  2688,  2679,  1340,  2333,  2991,  3206,
    3397,  2302,  3066,  2786,  2303,  2304,  3233,  1983,  2771,  2305,
    2687,  2691,   998,    49,  3493,  2724,   418,  1673,  1253,  2725,
      66,  3371,  2713,  3155,  2923,  2066,  3210,  2065,  2628,  1975,
    3374,  3151,  1638,  3292,  1938,  3310,  3302,  2088,    66,  2854,
    1324,  1476,  1849,  2536,  2948,  2948,  2948,  2948,  1855,  1839,
    2851,     0,   698,     0,     0,     0,     0,     0,     0,     0,
    1500,     0,     0,     0,  1255,     0,  2306,    66,     0,     0,
       0,  2933,  1340,     0,  2934,  2449,     0,  2307,     0,     0,
    1438,     0,     0,  1341,  1341,     0,  1340,  2935,  2946,     0,
       0,     0,     0,  1341,  2946,  2946,     0,  2946,  2946,  2946,
    2946,     0,     0,  2449,     0,  2449,  2946,   191,  1340,     0,
    2996,  2187,  2999,  1947,  1948,  1949,     0,     0,  1950,     0,
    1951,  1952,  1468,     0,     0,     0,  2936,  2937,  1655,     0,
       0,     0,     0,  1656,     0,     0,     0,     0,     0,  2938,
    1657,     0,     0,     0,    66,     0,     0,     0,     0,    66,
       0,    66,  1496,  1496,  1496,     0,  1496,     0,  1496,  1496,
       0,     0,  1658,     0,    71,    71,     0,  1659,  2449,   667,
       0,     0,     0,  2256,     0,     0,     0,     0,     0,     0,
    2939,    66,     0,     0,     0,     0,     0,     0,     0,     0,
    1203,     0,     0,     0,     0,     0,     0,     0,     0,    66,
   -1970, -1970, -1970,  1203,  1347, -1970,     0, -1970, -1970,     0,
    3137,     0,     0,     0,     0,  1588,  1340,     0,     0,  2940,
    2946,     0,     0,  2946,  2946,  2946,  2946,     0,  3391,     0,
       0,  2941,     0,     0,     0,     0,     0,     0,     0,  1255,
    1438,     0,  3394,  2942,  2943,     0,     0,     0,  1628,  1140,
       0,  2944,     0,  1340,  2945,  1253,     0,  2947,  2947,     0,
       0,  2947,   304,     0,  1636,  1636,     0,     0,     0,  1501,
       0,     0,     0,     0,    66,    66,    66,    66,    66,    66,
    3244,     0,     0,     0,     0,     0,  3427,     0,     0,     0,
    3244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3005,     0,     0,     0,     0,     0,     0,     0,
       0,  2946,     0,     0,     0,   164,   165,     0,     0,     0,
    2946,     0,  3203,   166,    39,  3203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2948,  2948,     0,   167,
    2948,     0,     0,   280,     0,     0,     0,     0,     0,  2012,
    2013,     0,   281,   282,     0,     0,  2029,     0,   283,   284,
     285,    39,     0,     0,     0,     0,  1340,     0,  3470,     0,
       0,     0,     0,  3068,     0,     0,   167,     0,     0,     0,
       0,     0,     0,     0,     0,  1055,     0,     0,     0,     0,
       0,  1253,  1953,     0,     0,  1954,  1502,  1955,     0,     0,
       0,     0,  1503,  1504,  1505,     0,     0,     0,     0,     0,
    3491,  3492,  3470,     0,   168,     0,     0,  1956,     0,     0,
       0,     0,     0,    66,  1506,  3501,   169,  1957,     0,     0,
       0,     0,     0,     0,    71,     0,    71,     0,  1203,  1110,
       0,     0,     0,     0,     0,     0,  1830,  1123,  2281,     0,
    1203,   168,     0,   170,  1841,     0,   286,     0,     0,     0,
       0,     0,     0,   169,     0,   194,     0,     0,     0,     0,
       0,  1959,     0,     0,     0,  1960,  1255,  1186,     0, -1970,
       0,     0, -1970,     0, -1970,     0,     0,     0,  2947,  1341,
     170,  1341,     0,     0,  2947,  2947,     0,  2947,  2947,  2947,
    2947,  1341,  1341,     0, -1970,     0,  2947,     0,  1341,  1341,
    1341,  1341,     0,     0, -1970,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3320,     0,  1875,  1186,  1507,
      71,     0,  1508,  1882,  1884, -1970,     0,     0,     0,     0,
    1509,     0,     0,     0,    62,     0,   171,     0,     0,     0,
    1961,     0,     0,     0,     0,     0,     0,     0, -1970,  2071,
       0,     0, -1970,     0,  1904,     0,  2217,  2948,     0,     0,
       0,     0,     0,  2948,  2948,  1510,  2948,  2948,  2948,  2948,
       0,    62,     0,   171,     0,  2948,     0,     0,     0,     0,
       0,     0,  1932,     0,     0,     0,  3209,     0,  2713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2260,
    1511,  1966,  1255,     0,     0,     0,     0,     0,     0,     0,
    2947,     0,     0,  2947,  2947,  2947,  2947,     0,     0,  1512,
    1513,     0,     0,     0,     0,     0,     0, -1970,     0,     0,
    1514,     0,     0,   172,     0,  1515,     0,     0,     0,  3203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1078,     0,     0,     0,     0,     0,     0,     0,  2016,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
     172,     0,     0,     0,  1516,   287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1341,     0,  2948,
       0,     0,  2948,  2948,  2948,  2948,     0,     0,     0,     0,
       0,  2947,   174,     0,     0,   173,  1517,     0,     0,     0,
    2947,     0,  2930,  2931,   175,     0,     0,     0,   283,  1319,
    1320,    39,     0,     0,     0,     0,     0,  1347,     0,     0,
       0,     0,  1321,  1322,     0,     0,   486,     0,     0,   174,
       0,  2051,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,     0,     0,     0,   288,
       0,     0,     0,   178,   289,     0,   290,     0,     0,     0,
    2948,     0,     0,     0,     0,     0,   179,   176,     0,  2948,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,     0,     0,  1341,     0,   292,     0,     0,
     293,     0,     0,   294,  1341,     0,  2932,  1341,  1341,  1341,
    1341,     0,   295,   179,     0,     0,     0,     0,     0,  1341,
     180,     0,     0,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   495,     0,   181,     0,  2208,     0,  1341,
       0,     0,   663,   296,     0,     0,     0,   180,     0,     0,
       0,  3380,     0,     0,     0,   297,     0,     0,     0,   182,
       0,  1203,     0,     0,     0,     0,   298,     0,     0,     0,
    2566,  2567,   181,     0,     0,     0,     0,     0,     0,     0,
       0,  2576,     0,   162,     0,     0,     0,     0,  3398,     0,
       0,     0,  2257,     0,  1186,     0,   299,     0,     0,     0,
       0,     0,     0,   183,     0,     0,  2588,  2589,  2590,  2591,
    2592,  2593,   184,     0,     0,     0,  2598,  2599,  2600,  2601,
       0,  1139,     0,  2603,     0,     0,     0,     0,     0,     0,
       0,  1203,  2316,  1203,     0,     0,     0,  1046,  1253,     0,
     183,   481,   482,   483,   484,   485,     0,   300,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
     302,     0,     0,     0,     0,     0,     0,   303,     0,     0,
     496,     0,  2362,   497,     0,   486,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   186,     0,     0,
       0,  3380,     0,     0,     0,  2655,  2656,     0,     0,     0,
       0,     0,  2660,  2661,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   186,     0,     0,     0,   615,   470,
     471,   472,     0,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,  1341,     0,   486,     0,     0,     0,     0,
     493,   494,   495,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,  1203,   500,   280,     0,  1203,     0,     0,     0,     0,
       0,     0,   281,   282,  1203,     0,  1324,     0,   283,   284,
     285,    39,     0,     0,     0,     0,     0,     0,     0,     0,
    1341,     0,   194,     0,     0,     0,   167,     0,   501,  1203,
       0,     0,     0,     0,  1341,     0,  1341,  2933,     0,  1255,
    2934,  2835,  2836,     0,     0,     0,     0,  1341,  2549,     0,
    2843,     0,  2552,  2935,     0,     0,   502,     0,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,     0,     0,   503,     0,     0,     0,  2575,     0,
     493,   494,   495,     0,     0,     0,     0,     0,  2878,  2879,
       0,     0,     0,  2937,     0,     0,     0,     0,  1341,     0,
       0,   168,     0,     0,     0,  2938,   286,     0,     0,   496,
       0,     0,   497,   169,     0,  2899,     0,  2901,     0,  2550,
     470,   471,   472,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
     170,     0,     0,     0,     0,     0,  2939,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2972,  2973,
       0,     0,  2974,  2975,     0,  2940,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2941,  1341,     0,
       0,  2653,     0,     0,     0,     0,     0,     0,     0,  2942,
    2943,     0,     0,     0,     0,     0,     0,  2944,     0,   496,
    2945,   505,   497,     0,     0,     0,     0,     0,   304,  1341,
       0,    62,   498,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,   500,     0,     0,     0,  1341,  1341,  1341,  1341,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,  1203,     0,     0,     0,     0,     0,
       0,   493,   494,   495,     0,     0,     0,   501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1341,  1341,     0,     0,     0,   502,     0,     0,     0,  1341,
    1341,     0,  1341,     0,     0,  1341,     0,  1341,     0,     0,
     172,  1341,     0,   503,     0,   287,     0,     0,     0,     0,
       0,     0,   498,     0,  1203,     0,     0,  1078,  1078,  1078,
       0,  1078,  1078,  1078,  1078,  1078,  1078,   499,  3101,     0,
    1078,   500,  3106,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,     0,     0,     0,  1203,
       0,  3114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2868,     0,  1072,   501,  2872,   174,
       0,  3126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,  2884,     0,   504,     0,     0,   194,     0,     0,
     496,     0,     0,   497,     0,   502,     0,     0,     0,   288,
       0,     0,     0,     0,   289,     0,   290,     0,     0,     0,
       0,     0,     0,   503,  2904,  2906,     0,   176,     0,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,     0,     0,     0,     0,   292,     0,     0,
     293,     0,     0,   294,     0,     0,     0,     0,     0,     0,
     505,     0,   295,   179,     0,     0,  1253,     0,     0,     0,
    2970,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1434,   296,   504,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,     0,   498,     0,     0,   298,  1341,  1341,     0,
       0,  1341,   181,     0,     0,     0,     0,     0,   499,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   470,   471,   472,   299,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     505,     0,  3029,     0,     0,     0,     0,     0,   501,     0,
       0,     0,     0,     0,  3043,     0,     0,  1155,  1156,  1157,
    1158,     0,  1341,     0,     0,  1341,     0,     0,  1341,   486,
     183,  1341,     0,  1341,     0,     0,   502,   300,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
     302,     0,     0,     0,   503,     0,     0,   303,     0,  3278,
       0,     0,  3281,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,  1203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,     0,     0,
       0,     0,     0,     0,     0,     0,  1341,     0,     0,     0,
       0,     0,     0,  1203,   280,     0,     0,     0,  1186,     0,
       0,     0,     0,   281,   282,     0,     0,  1255,     0,   283,
     284,   285,    39,   185,   186,     0,   487,   488,   489,   490,
     491,   492,     0,     0,     0,   504,     0,   167,     0,  1159,
       0,     0,     0,     0,   493,   494,   495,  1160,     0,     0,
       0,     0,     0,     0,     0,     0,  1161,     0,     0,  1162,
       0,     0,     0,     0,     0,  2728,  2729,     0,  2730,  2731,
    2732,     0,  1341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1341,     0,  1341,     0,
       0,     0,     0,     0,  1341,  1341,     0,  1341,  1341,  1341,
    1341,   505,  1163,     0,     0,     0,  1341,  3369,  1341,  1164,
       0,     0,   168,     0,     0,     0,  1186,   286,     0,   280,
       0,     0,     0,     0,   169,  1341,     0,     0,   281,   282,
       0,     0,     0,     0,   283,   284,   285,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   167,     0,     0,     0,     0,     0,  3399,  3400,
       0,  3402,     0,  3404,  3405,     0,  1165,  2733,     0,     0,
       0,     0,     0,     0,     0,  2734,     0,     0,     0,     0,
    3029,     0,     0,   496,     0,     0,   497,     0,     0,     0,
       0,  1166,     0,     0,     0,     0,     0,     0,  1167,  1253,
    1168,     0,     0,     0,     0,     0,     0,     0,     0,  2735,
    1169,     0,     0,     0,     0,     0,  1341,     0,  2736,     0,
    1341,     0,     0,  1341,  1341,  1341,  1341,   168,     0,     0,
       0,  3454,   286,  3455,     0,     0,     0,     0,  1170,   169,
       0,  1203,    62,     0,   171,     0,  1171,  2737,  2738,  1341,
       0,     0,     0,  1341,     0,     0,     0,     0,     0,  1203,
       0,     0,     0,     0,     0,     0,   170,  3467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1172,     0,     0,  3476,  3477,  1186,     0,
    3478,     0,  2739,  3480,     0,   283,  1319,  1320,    39,     0,
       0,     0,     0,     0,     0,     0,   498,  1173,     0,  1321,
    1322,  1341,     0,     0,     0,     0,     0,     0,     0,     0,
    1341,   499,     0,     0,     0,   500,   600,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2740,     0,     0,     0,
       0,   172,     0,     0,  1174,     0,   287,     0,     0,     0,
       0,     0,     0,     0,     0,  1175,     0,    62,     0,   171,
       0,   501,     0,     0,     0,  3029,  1341,     0,     0,     0,
    3330,     0,  3332,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   502,
    2741,     0,     0,  2932,     0,     0,     0,     0,     0,     0,
       0,     0,  1203,     0,     0,     0,     0,   503,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,   280,
    1255,     0,   175,  1253,     0,     0,     0,   194,   281,   282,
       0,     0,     0,     0,   283,   284,   285,    39,     0,     0,
     288,     0,     0,     0,     0,   289,     0,   290,     0,     0,
       0,     0,   167,  1176,  1177,  1178,   172,     0,   176,     0,
       0,   287,     0,   291,     0,     0,  1179,     0,     0,     0,
       0,     0,     0,   177,     0,     0,     0,     0,   292,     0,
       0,   293,     0,  2109,   294,     0,     0,     0,   504,     0,
       0,   173,     0,   295,   179,  1496,  1496,  1496,  1496,  1496,
    1496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1180,     0,     0,     0,     0,     0,     0,  1139,     0,
       0,     0,     0,     0,     0,   174,     0,   168,     0,     0,
       0,     0,   286,     0,   296,     0,     0,   175,   180,   169,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,     0,   505,   288,     0,   298,     0,  2512,
     289,     0,   290,   181,     0,     0,   170,     0,     0,  1181,
       0,     0,     0,   176,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,  1182,     0,   299,   177,     0,
       0,     0,     0,   292,     0,     0,   293,     0,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   179,
       0,     0,     0,     0,     0,     0,  2742,  2743,  2744,  2745,
    2746,  2747,  2748,  2749,  2750,  2751,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,   300,     0,
     184,     0,     0,     0,  1255,     0,     0,     0,  2888,   296,
     301,   302,     0,   180,     0,     0,     0,    62,   303,   171,
       0,   297,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,   298,     0,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,   470,   471,   472,     0,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2110,     0,
       0,     0,     0,  1324,   185,   186,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,  2111,  2112,
    2113,     0,     0,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,   300,  2933,   184,   172,  2934,     0,     0,
   -1971,   287,     0,     0,     0,   301,   302,     0,     0,     0,
    2935,     0,     0,   303,     0,     0,     0,  2114,     0,     0,
       0,     0,     0,     0,   304, -1971, -1971, -1971,     0,  2115,
   -1971,   173, -1971, -1971,     0,     0,     0,     0,     0,     0,
    2116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2937,     0,     0,     0,     0,     0,  2117,     0,     0,     0,
       0,     0,  2938,     0,     0,   174,  2118,   487,   488,   489,
     490,   491,   492,     0,     0,     0,     0,   175,     0,   185,
     186,  2119,     0,     0,     0,   493,   494,   495,     0,     0,
       0,     0,     0,     0,     0,   288,     0, -1971,     0,     0,
     289,     0,   290,  2939,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0, -1971,     0,     0,   177,  2120,
       0,     0,     0,   292,     0,     0,   293,     0,     0,   294,
       0,     0,  2940,     0,     0,     0,     0,     0,   295,   179,
       0,     0,     0,     0,  2941,     0,     0,     0,     0,  2121,
       0,     0,     0,     0,     0,     0,  2942,  2943,     0,  2122,
   -1971,     0,     0,     0,  2944,     0,     0,  2945,     0,     0,
       0,     0,     0,     0,     0,   304,     0,     0,     0,   296,
    2123,     0,     0,   180,  2124,     0,     0,     0, -1971,     0,
   -1971,   297,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     0,   181,     0,
       0,     0,  2125,     0,   496, -1971,     0,   497,     0,     0,
       0,  2126, -1971,     0, -1971,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0, -1971,     0,     0,     0,     0,
   -1971,     0,     0,     0,     0,     0,     0,     0, -1971,     0,
       0,     0, -1971,     0,     0,     0,     0,     0, -1971,     0,
       0,     0, -1971, -1971, -1971, -1971,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183, -1971,     0,     0,
       0,     0,     0,   300,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     0, -1971,   301,   302, -1971,     0, -1971,
       1,     0,     0,   303,     2,     0, -1971,     0,     0,     0,
       0,     0,     0,     0,   304,   700,   701,   702,     0, -1971,
       0,     0,     0,     0,   703,     0,     0,   704,     0, -1971,
       0,     0,     0,     0,   705,   706,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1971, -1971,   499,     0,     0,     0,   500,   614,     0,     0,
       0,     0,     0,     0,     0, -1971,     0,     0,     0,   185,
     186,     0,     0, -1971,     0,     0,     0, -1971,     0,   707,
     708,     0,     0,     0,   709, -1971, -1971, -1971,     0,     0,
       0,     0,   501,     0,   710,   711,     0,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   713,     0,     0,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,     0,     0,     0,     0,   714,     0,
       0,   715,   716,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,   717,     0,   718,   719,   720,
       0,     0, -1971,     0,     0,     0,     0,   721,   722,     0,
     723,   724,   725, -1971,     0,     0,     0,     0,   726,     0,
       0,   727,     0,   728,   729,   730,     0,     0,     0,     0,
       0,   731,     0,   732,   733,     0,   734,     0,   735,   736,
       0,     0,   737,     0,     0,   738,   739,   740,   741,   742,
     743,     0,     0, -1971,   744,   745,   746,     0,   747,     0,
       0,     0,   748,     0,   749,   750,     0,     0,     0,   504,
     751,     0,     0,   752,     0,     0,   753,     0,   754,     0,
     755,     0,   756,     0,     0,     0,   757,   758,     0,   759,
     760,   761,     0,     0,   762,     0,   763,   764,     0,   765,
       0,     0,     0,     0,     0,     0,     0,   766,   767,     0,
       0,     0,     0,     0, -1971,     0,     0,     0,     0,     0,
     768,     0,     0,   769,   770,     0,     0,   771,   772,     0,
       0,   773,   774,     0,     0,   505,     0,     0,     0,     0,
     775,   776,   777,     0,   778,     0,     0,     0,     0,     0,
   -1971,     0,     0,     0,   779,   780,   781,     0,   782,     0,
       0,     0,   783,   784,     0,     0,     0,   785,     0,     0,
       0,     0,     0,     0,     0,   786,     0,     0,     0,     0,
       0,     0,     0,   787,   788,   789,     0,     0,     0,     0,
       0,   790,   791,     0,     0,     0, -1971,     0,     0,   792,
       0,     0,   793,     0,     0,     0,   794,   795,     0,     0,
   -1971, -1971, -1971, -1971, -1971, -1971, -1971,   796, -1971, -1971,
       0,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   797, -1971,     0,     0,     0,     0,
       0,     0,   798,     0,     0,     0,     0,     0,   799,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   800,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,   801,     0,     0,     0,     0,     0,   802,     0,   803,
     804,     0,     0,     0,   470,   471,   472,   805,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,   470,   471,   472,     0,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   806,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,   807,     0,     0,
       0,     0,     0,     0,   808,     0,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
     487,   488,   489,   490,   491,   492,     0,     0,   809,   810,
       0,     0,     0,   811,     0,     0,     0,     0,   493,   494,
     495,     0,     0,     0,     0,   812,     0,     0,     0,     0,
       0,   813,   814,   815,   816,     0,     0,     0,   817,     0,
       0,     0,   818,     0,     0,     0,     0,     0,     0,   819,
     820,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     821,     0,   822,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   823,     0,   824,     0,     0,   825,     0,
       0,     0,     0,     0,   826,   493,   494,   495,   487,   488,
     489,   490,   491,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   495,     0,
     827,     0,     0,   828,     0,     0,     0,     0,   829,     0,
       0,   830,   831,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   832,     0,     0,     0,
     470,   471,   472,   833,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   496,     0,     0,
     497,     0,     0,     0,     0,     0,   834,   835,   836,   837,
     838,   839,   840,     0,     0,   841,     0,   842,     0,   843,
       0,     0,     0,   470,   471,   472,   486,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,     0,   497,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   496,     0,     0,   497,     0,
       0,     0,   470,   471,   472,     0,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     498,     0,     0,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,   499,     0,     0,   486,   500,
       0,   493,   494,   495,     0,     0,     0,     0,     0,   470,
     471,   472,     0,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   487,   488,   489,   490,
     491,   492,     0,     0,     0,   501,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   494,   495,   498,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,   499,   502,     0,     0,   500,   624,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,   499,     0,     0,     0,   500,   996,     0,
       0,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,     0,   501,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,   494,   495,     0,     0,     0,     0,
       0,     0,     0,   501,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     0,   497,     0,     0,     0,     0,   503,     0,
       0,   502,   487,   488,   489,   490,   491,   492,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,   503,
     493,   494,   495,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   496,     0,     0,   497,     0,     0,     0,
     470,   471,   472,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   504,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,   496,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,   500,  1002,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   498,     0,     0,   496,
       0,     0,   497,     0,     0,     0,   505,     0,   501,     0,
       0,   499,     0,     0,     0,   500,  1003,     0,     0,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,     0,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,   493,   494,   495,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,   503,     0,     0,     0,     0,     0,
    2417,     0,     0,     0,     0,   498,     0,     0,     0,  1316,
    1317,  1318,     0,     0,     0,   283,  1319,  1320,    39,   502,
     499,     0,     0,     0,   500,  1004,     0,     0,     0,  1321,
    1322,     0,     0,     0,   470,   471,   472,   503,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,   499,     0,     0,
     486,   500,  1005,     0,     0,   470,   471,   472,   502,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1323,     0,     0,     0,   501,   504,     0,
     496,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,   470,   471,   472,   502,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,     0,   505,     0,     0,   504,   486,     0,
       0,     0,     0,     0,     0,   493,   494,   495,     0,     0,
       0,     0,     0,     0,   471,   472,     0,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,     0,     0,     0,     0,  1139,     0,
       0,     0,     0,   498,   504,     0,   493,   494,   495,   486,
       0,     0,     0,   505,     0,     0,     0,     0,   499,     0,
       0,     0,   500,   472,     0,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,     0,     0,     0,     0,     0,     0,     0,   501,     0,
       0,     0,     0,   493,   494,   495,     0,   486,     0,     0,
     505,  1007,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,   502,     0,     0,     0,
       0,     0,     0,     0,   496,     0,     0,   497,     0,     0,
       0,     0,  2418,     0,   503,     0,   487,   488,   489,   490,
     491,   492,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   494,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2417,     0,     0,     0,   496,     0,     0,   497,     0,
    1316,  1317,  1318,     0,     0,     0,   283,  1319,  1320,    39,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
    1321,  1322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   495,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   496,  1324,     0,   497,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   498,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   493,
     494,   495,   499,     0,  1325,     0,   500,  2419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2420,
    1327,   505,     0,     0,  1323,     0,     0,     0,   486,     0,
       0,     0,     0,   496,     0,     0,   497,     0,   498,     0,
       0,     0,   501,     0,     0,     0,     0,  1720,     0,     0,
       0,     0,     0,   499,     0,  1008,     0,   500,     0,     0,
    1328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     502,     0,  1329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,   496,     0,   501,   497,   498,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1011,     0,     0,     0,
     499,     0,     0,  1330,   500,     0,     0,     0,     0,     0,
       0,   502,     0,     0,     0,   487,   488,   489,   490,   491,
     492,     0,     0,     0,     0,     0,     0,     0,   496,   503,
       0,   497,     0,   493,   494,   495,  1331,     0,     0,  1139,
     501,     0,  1332,     0,     0,     0,   498,     0,     0,     0,
       0,  1333,  1334,     0,  1335,     0,     0,     0,     0,   504,
       0,   499,     0,     0,     0,   500,  1336,  1337,   502,     0,
       0,     0,     0,     0,  1338,     0,     0,  1339,     0,     0,
       0,     0,     0,     0,     0,   304,   503,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,   498,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,   500,     0,   505,     0,     0,     0,   502,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,  2418,     0,     0,     0,   503,     0,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,   499,   504,   486,     0,
     500,     0,   496,     0,     0,   497,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   502,   478,   479,
     480,   481,   482,   483,   484,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,   501,     0,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,     0,  1006,
       0,     0,     0,     0,     0,   486,     0,     0,   504,     0,
       0,     0,     0,   505,   502,     0,   479,   480,   481,   482,
     483,   484,   485,     0,  1324,     0,     0,   486,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,     0,   486,     0,     0,  1325,     0,     0,  2419,     0,
       0,     0,     0,   493,   494,   495,   504,     0,     0,     0,
    2420,  1327,     0,     0,   505,   498,  1316,  1317,  1318,     0,
       0,     0,   283,  1319,  1320,    39,     0,     0,     0,     0,
     499,     0,     0,     0,   500,     0,  1321,  1322,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,     0,   580,
       0,  1328,     0,   504,     0,     0,     0,     0,     0,     0,
     493,   494,   495,  1329,   487,   488,   489,   490,   491,   492,
     501,     0,   505,     0,     0,     0,   480,   481,   482,   483,
     484,   485,   493,   494,   495,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,     0,     0,     0,   502,     0,
       0,     0,     0,     0,  1330,     0,     0,   493,   494,   495,
       0,   486,     0,     0,     0,     0,   503,     0,     0,   505,
    1323,     0,     0,     0,     0,     0,  1316,  1317,  1318,     0,
       0,     0,   283,  1319,  1320,    39,     0,  1331,     0,     0,
       0,     0,   496,  1332,     0,   497,  1321,  1322,     0,     0,
       0,     0,  1333,  1334,     0,  1335,     0,     0,     0,     0,
       0,     0,     0,  1316,  1317,  1318,     0,  1336,  1337,   283,
    1319,  1320,    39,     0,     0,  1338,     0,     0,  1339,     0,
       0,     0,     0,  1321,  1322,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   496,
       0,     0,   497,     0,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,   497,     0,   493,   494,   495,     0,
    1323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1139,   496,     0,     0,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,   498,     0,  1323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     499,     0,     0,     0,   500,  1316,  1317,  1318,     0,     0,
       0,   283,  1319,  1320,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1321,  1322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,   500,     0,     0,   498,     0,     0,     0,   502,  2418,
       0,     0,     0,     0,     0,  1139,     0,     0,     0,   499,
       0,   138,     0,   500,     0,   496,   503,     0,   497,   498,
       0,     0,     0,  1316,  1317,  1318,     0,   501,     0,   283,
    1319,  1320,    39,     0,   499,     0,     0,     0,   500,  1323,
       0,     0,  1139,  1321,  1322,     0,     0,     0,     0,   501,
     139,     0,     0,     0,     0,   502,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,     0,     0,   503,   501,     0,     0,   502,  1316,  1317,
    1318,     0,     0,     0,   283,  1319,  1320,    39,     0,     0,
       0,     0,     0,     0,     0,   503,     0,   504,  1321,  1322,
    1324,     0,   502,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,   143,     0,     0,     0,     0,     0,  1323,     0,     0,
       0,  1325,   144,     0,  2419,     0,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,  2420,  1327,   145,     0,
       0,     0,     0,   499,   504,     0,     0,   500,   146,  2930,
    2931,     0,     0,   505,  1139,   283,  1319,  1320,    39,     0,
       0,     0,     0,   147,     0,     0,   504,     0,     0,  1321,
    1322,     0,  1323,     0,     0,     0,     0,  1328,     0,     0,
    1318,     0,     0,   501,   283,  1319,  1320,    39,     0,  1329,
       0,   504,     0,     0,     0,     0,     0,     0,  1321,  1322,
    1324,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     505,   502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,   503,
    1330,  1325,   505,   206,  1326,     0,     0,  1324,     0,     0,
       0,   150,  1139,     0,     0,   207,     0,  1327,   151,     0,
       0,   152,     0,  2932,     0,     0,     0,   505,     0,     0,
       0,     0,     0,  1331,     0,     0,     0,     0,  1325,  1332,
       0,  1326,   153,     0,  1720,     0,   154,     0,  1333,  1334,
       0,  1335,  1323,     0,  1327,     0,     0,  1328,     0,     0,
       0,     0,     0,  1336,  1337,   155,     0,  1139,     0,  1329,
       0,  1338,     0,     0,  1339,     0,     0,     0,     0,     0,
     504,     0,   304,   156,     0,     0,     0,     0,     0,     0,
       0,     0,   208,  2253,  1328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1329,     0,   209,   210,
    1330,     0,     0,     0,     0,     0,     0,     0,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1324,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1331,     0,     0,   505,  1330,  1139,  1332,
       0,     0,     0,     0,     0,     0,     0,     0,  1333,  1334,
    1325,  1335,     0,  1326,     0,     0,  2285,  2286,  2287,  2288,
    2289,  2290,     0,  1336,  1337,     0,  1327,  1139,     0,     0,
    1331,  1338,     0,     0,  1339,     0,  1332,     0,     0,     0,
       0,     0,   304,     0,     0,  1333,  1334,     0,  1335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1336,  1337,     0,     0,     0,  3377,  1328,  1324,  1338,     0,
       0,  1339,     0,     0,     0,     0,     0,     0,  1329,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1325,     0,
       0,  1326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2291,  1327,     0,     0,     0,     0,  1330,
       0,     0,  2050,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1331,  1325,  1328,     0,  1326,     0,  1332,     0,
       0,     0,     0,     0,     0,     0,  1329,  1333,  1334,  1327,
    1335,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,  1336,  1337,     0,     0,     0,     0,     0,     0,
    1338,     0,     0,  1339,     0,     0,   214,   215,   216,   217,
       0,   304,     0,  1324,     0,     0,     0,  1330,     0,  1328,
       0,     0,     0,     0,   218,     0,     0,  3347,     0,     0,
       0,  1329,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1324,     0,  2933,     0,   219,  2934,     0,     0,
    1331,     0,     0,     0,     0,     0,  1332,     0,   220,     0,
    2935,     0,     0,     0,     0,  1333,  1334,     0,  1335,   221,
       0,     0,  1330,  1325,     0,     0,  1326,     0,     0,     0,
    1336,  1337,     0,     0,  3348,   222,     0,  1720,  1338,  1327,
       0,  1339,     0,     0,     0,   223,     0,     0,     0,   304,
    2937,     0,     0,     0,     0,  1331,     0,     0,     0,  3349,
     224,  1332,  2938,     0,     0,     0,     0,     0,  3350,     0,
    1333,  1334,     0,  1335,     0,     0,     0,     0,   138,  1328,
       0,     0,     0,     0,     0,  1336,  1337,     0,     0,     0,
       0,  1329,     0,  1338,     0,     0,  1339,     0,     0,     0,
     225,     0,     0,  2939,   304,     0,  3351,     0,     0,  2292,
       0,     0,     0,     0,  3352,     0,     0,   139,     0,     0,
       0,     0,  2293,   226,     0,     0,     0,     0,     0,     0,
       0,     0,  1330,     0,     0,     0,   140,   141,   227,     0,
       0,     0,  2940,     0,     0,   228,     0,     0,   229,     0,
       0,     0,     0,     0,  2941,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1331,  2942,  2943,     0,   230,
       0,  1332,     0,   231,  2944,     0,   142,  2945,     0,     0,
    1333,  1334,     0,  1335,  2294,   304,     0,     0,   143,     0,
    2295,     0,   232,     0,     0,  1336,  1337,     0,     0,   144,
       0,     0,     0,  1338,     0,  3353,  1339,     0,     0,     0,
     233,     0,     0,     0,   304,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,  2296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,  2297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2298,  2299,     0,     0,     0,     0,  2300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2301,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2302,     0,   149,  2303,  2304,     0,     0,     0,  2305,
       0,     0,     0,     0,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,   151,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2306,     0,     0,     0,
       0,     0,   155,     0,     0,  3354,     0,  2307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156
};

static const short yycheck[] =
{
       3,     4,     5,     6,   178,  1076,     9,    10,   404,   197,
     112,   671,  1154,  1196,  1489,    53,  1316,  1317,  1191,    62,
    1404,   813,   557,  1656,  1019,  1397,   254,  1022,  1169,  2048,
    1165,  1166,  2085,  1168,  2087,  1170,  1171,   612,   797,   268,
     269,  1620,  1621,   583,    47,     5,   275,  1787,  2102,  2240,
      48,  1150,    27,  1151,  1790,  1781,   180,    60,    27,    62,
      98,   654,  2396,  2100,   133,     5,   772,   270,   271,    27,
      73,   707,   708,  2639,  2640,  2641,   178,    80,    25,    77,
      27,  1842,    85,  2359,    27,    88,    24,  1720,    26,    92,
      93,   602,    19,  2284,   605,   197,    51,    24,    25,    26,
       5,     5,  1351,    20,  1353,    26,    27,    27,   111,   745,
      27,    36,   748,   736,  1729,  1730,  1731,  1732,  1969,  2171,
       5,   119,   758,     5,   127,   123,   762,   130,    19,   132,
     766,  2642,   157,     8,   137,    26,     5,   773,  1280,    25,
     733,    27,   778,    27,   780,    25,   815,    27,   272,  1247,
     786,   744,   276,   789,   278,   329,   280,   281,   282,     5,
     796,    27,    27,  1261,    25,   289,    27,   803,    20,   293,
     294,   240,   118,    25,   810,    27,   245,   246,     5,    20,
    1251,    25,    26,    27,    25,   821,    27,     5,    30,   825,
     145,   146,    34,   829,   120,     5,   199,    27,    27,   835,
       5,    43,   838,     6,     5,   737,   799,   803,     5,   802,
     833,    24,    25,    26,    27,     5,    33,    19,   811,    27,
      24,    25,    26,    27,    26,  1722,    25,   329,    27,   761,
       5,    26,   334,     5,   139,   140,   234,  2096,  2097,  2098,
      66,  2411,  2101,  2413,     5,   248,     9,     5,   220,    12,
      13,    14,    15,    16,    17,    33,  2725,   260,    24,    25,
      26,    27,     6,   266,   267,   268,   269,   270,   271,    25,
      53,    27,   275,     5,     9,   807,     5,    12,    13,    14,
      15,    16,    17,   194,   403,   817,  1981,    27,   820,   207,
       5,   133,   824,  1176,  1177,  2280,   200,    27,   830,   126,
     832,   128,   331,   130,   207,  2164,    24,    25,    26,    27,
     148,    24,    25,    26,    27,    98,    27,   143,   144,   322,
     323,   445,    23,   293,   448,   118,   247,  2346,   331,   514,
     333,   550,     5,   103,   104,   105,   106,   107,   566,   398,
     528,   465,   466,   467,   468,  1444,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   592,   362,  2419,     5,    24,    25,    26,
       5,   486,   447,   497,   498,   120,     5,     5,   502,  1552,
     504,   398,  1429,   612,     5,    36,   247,   514,   220,   352,
     716,  1150,     5,   517,   518,   519,   520,  1769,   339,   677,
       5,   525,    27,     5,     5,     5,  1790,     5,    25,     5,
      27,   352,  2173,   411,   412,   413,     5,  1488,   195,   196,
     594,    40,    41,   339,   390,   593,   528,   398,     5,   246,
     247,   449,   631,    25,   247,    27,   352,    13,  1935,    25,
     305,    27,     5,   247,   514,     5,   462,   418,   247,   331,
       6,   293,     5,   731,   449,    25,   782,    27,   433,    31,
      30,  1936,  2077,     5,    28,   352,   977,   601,     5,   247,
     689,  2330,   671,     5,   642,   301,    30,   364,     5,   425,
      34,  2340,   670,    19,    27,   331,     5,     5,    64,   674,
      26,   247,   594,   208,   112,   113,     5,   486,     0,   220,
       5,   486,     5,    18,    19,    20,    21,    22,    18,    19,
      20,    21,    22,   516,     5,     5,   679,   247,  1154,   449,
     558,   559,   485,   493,   142,   143,   144,     5,   513,   247,
       5,   650,     5,  1202,   247,     5,   247,     5,   672,   702,
       5,     5,     5,   408,   485,   644,  1215,   674,   551,   547,
     553,     5,     5,    25,     5,    27,  1088,   111,   561,     5,
     122,   790,     5,     5,   118,   680,     5,   666,   670,   485,
     496,   403,   414,   231,   633,   578,  2435,   580,   408,   340,
       5,     5,  2638,  2639,  2640,  2641,  2571,     5,   591,   592,
     291,     5,   595,  2612,   623,   564,     5,  2176,     5,     5,
       5,   220,   486,   569,   674,   808,   809,   671,     5,   612,
     164,   165,   208,     5,   580,    27,   633,  3086,     5,     5,
     462,   666,  2675,     5,   123,   650,   644,   432,     5,   442,
     247,     5,   425,  2328,   837,   556,     5,   840,   713,   611,
    1447,   616,  1278,  1279,  1280,    29,   449,   449,   452,   644,
    2326,   493,  2928,  2023,   449,   247,  2026,   486,   569,  1542,
    2714,   526,   633,   581,  1196,  3176,   429,   430,   408,  1204,
     328,   597,   447,  2864,  1206,    27,  1208,   247,   581,  2538,
     522,   482,   403,  1279,  2317,  1444,   449,    27,   609,   594,
     570,   680,  2883,  2969,   429,   430,   526,   700,   701,   702,
     703,   704,   705,   706,   247,   449,   709,   710,   711,    23,
     518,   714,   442,   716,   644,   492,   719,   449,   721,   644,
     449,   484,   526,   293,   482,   680,   611,   730,   671,   542,
    1871,  1391,   672,   608,   452,  2788,   674,  2790,   741,   742,
    2466,   623,   611,  2780,  2484,  1451,   721,   674,   751,   484,
    2486,   671,   721,   644,   757,   299,   716,  2608,  1298,  1858,
     763,   764,   765,   721,  2148,  2624,   769,   671,  2152,   772,
     631,   774,   775,  2810,   721,   558,   681,   623,   644,   782,
     666,  1450,   785,   601,   403,  2837,   732,   790,   791,  2841,
     793,   608,    10,  1462,   797,   452,  1307,   800,   608,  1310,
    1311,  2050,   723,   806,   721,   808,   809,  3141,   605,   482,
     813,   814,   815,   340,   666,   605,   819,  2987,  1865,   822,
     449,  3155,   666,  1921,   827,   666,   424,  3393,   449,   601,
     608,   834,   331,   836,   837,   486,   839,   840,   593,   842,
     843,   640,   644,   482,   414,   672,   412,   482,   611,   605,
      27,   677,   597,   680,   482,   693,   694,   695,   696,   697,
     449,   674,   513,   514,    23,  2114,  2115,  2009,   638,   482,
     674,   425,   449,   392,  2930,  2931,   611,   482,  2934,     5,
     482,   482,   482,   445,   449,  1009,   449,   642,  1012,   449,
     302,   733,   510,   449,   486,  1019,   449,  1021,  1022,   442,
     486,  1297,    27,   315,   403,  2954,   468,   449,   674,   526,
    1905,   509,   449,   449,   677,    30,  2775,   449,  2777,    34,
    1452,  1453,  1454,   493,   443,   576,   449,   525,    43,   412,
    2983,   449,  2985,  2986,   893,   292,   417,  1469,  2614,  2615,
     449,  2520,   677,   946,   449,  3136,   449,   674,   447,  2703,
     302,  2705,   522,  3287,  2708,    25,   674,    27,   449,   449,
    3013,   674,   302,   315,   727,   728,   520,   482,   966,   417,
     568,   449,   482,   593,   449,   315,   449,   291,   596,   449,
     599,   449,   707,   708,   449,   449,   449,   712,   713,   551,
    3168,   994,   727,   728,  2364,   449,   449,  1590,   449,  1574,
     725,  3179,   449,   449,   462,   417,   449,   449,   553,   607,
     449,  1543,  1819,   632,  1821,  3069,   561,   674,   133,   383,
     745,   639,   642,   748,   449,   449,  1561,   449,     5,   754,
    1562,   449,  1030,   758,  1037,   449,  1039,   762,   636,   734,
     449,   766,   449,   449,   449,   770,   771,   645,   773,  1581,
     531,   776,   449,   778,   779,   780,  2915,   449,   612,   481,
    1592,   786,   449,   449,   789,   417,  2925,   449,    14,   449,
    1073,   796,   449,  1076,   486,   449,  1304,   417,   803,   644,
     449,   643,   514,   531,  2994,   810,  2458,  2997,   306,  1092,
    3000,  2264,  1095,   655,   656,    25,   821,    27,   577,  1858,
     825,   663,  2486,   644,   829,  3161,   420,  3156,  3157,   376,
     835,  3167,  3168,   838,  3170,  3171,  3172,  3173,   644,   531,
     302,   644,   247,  3179,   623,   666,  3145,  3181,    28,    29,
    2201,  1134,   291,   315,   486,   547,  1139,    25,   692,    27,
     666,  2638,  2639,  2640,  2641,   481,   700,  1150,  2397,  3008,
    2399,   295,  2401,    18,    19,    20,    21,    22,   215,   640,
     486,  1164,  1165,  1166,   521,  1168,   486,  1170,  1171,    25,
     486,    27,   536,  1176,  1177,   486,   383,   247,   293,   531,
     305,   526,  3274,  3275,  3276,  1696,   514,  1979,  1699,   534,
    2332,   531,   640,   651,   514,   547,   654,   644,   514,  1202,
      25,   486,    27,   560,   703,   704,   705,   547,   352,  3286,
    1213,  1847,  1215,  3290,  1173,   714,  2358,  1810,    25,   514,
      27,  1224,  1181,   400,  1227,    24,   444,    26,   446,  1232,
       0,   408,   409,   486,  1903,   417,  1465,  3293,    20,   232,
    3296,  3297,  3298,  3299,    25,    27,    27,  3001,  1251,  1252,
     486,    25,    22,    27,    26,    27,   433,  1260,   315,   436,
    1463,   420,   406,   221,   644,   223,   410,    25,   514,    27,
    3362,  1894,  3364,  1276,  1277,   452,   486,    25,    25,    27,
      27,  1813,    26,    27,  2917,    26,    27,  3340,     5,  3148,
     248,     8,    27,   486,    26,    27,   353,  1829,  3208,   414,
    1303,  1174,  1175,  1477,  1973,  1178,  1179,    42,    26,    27,
      26,    27,   748,  1316,  1317,   679,   644,   247,   221,    24,
     223,    26,   730,  1326,  1856,  1394,   762,  1396,  3384,   536,
     766,  1863,   673,   486,   698,   699,  1339,  3393,   666,   680,
    1976,   485,   778,   751,  1347,  1574,   674,   462,   679,   531,
     302,   709,  1887,    25,   718,    27,   764,   486,   351,   247,
     417,  1893,   536,   315,   357,   547,  1569,  1570,   486,   327,
     701,   702,   330,  2009,   431,  1477,  1419,  2098,   493,   556,
    2101,  1913,  3241,   741,   742,  2860,    20,   263,   264,   265,
      25,   247,    27,    27,   352,  1398,    25,  2580,    27,  1402,
    1403,  1404,  2702,  2703,  2502,  2705,  2547,   522,  2708,   513,
     514,  1414,  1415,  1416,  1617,  1618,  1419,  1420,  1421,  1422,
    1423,  1424,   247,    25,   327,    27,   486,   330,   163,  1154,
    1433,  2604,   609,  2930,  2931,   793,  2820,  2934,   486,   616,
     247,  1444,   486,  1446,    20,  1448,  2544,  1450,  1451,   352,
     295,    27,   486,   513,   514,  1458,  1459,  1460,   486,  1462,
    1463,    20,  1465,  1466,   836,   417,   247,   839,    27,    20,
     842,  1474,   679,   247,   531,   247,    27,   212,  1481,  1482,
      24,   221,    26,   223,  2153,  1488,  1489,   679,  2157,   247,
     547,   698,   699,  2968,    24,    20,    26,  2166,  2995,   247,
     247,  2998,    27,   247,   780,   679,   247,   352,   248,   701,
     702,   718,   247,   789,   249,   247,   576,   394,   667,   668,
     669,   670,  2191,   424,   698,   699,  2037,   485,   405,   247,
     486,   247,  2043,  2044,   486,   486,  1539,  1540,    25,  1542,
      27,   486,  1545,  1546,   718,  3160,   486,  3162,  3163,  3164,
    3165,    20,   486,  1278,  1279,  1280,  2149,   486,    27,   835,
    2555,   406,   838,   486,  1567,   410,  1569,  1570,  2563,  2564,
    2565,  1574,    25,  1576,    27,  1578,  1579,  1580,   455,   531,
     456,   821,   485,  3344,   449,   825,   494,   327,   486,   829,
     330,   486,   469,  2934,    26,   547,   295,   505,    19,   486,
    3361,  1604,   424,    24,    25,    26,   694,   695,   509,  2202,
    2142,   346,   352,  1616,  1617,  1618,    20,   486,   526,  1688,
    1623,  1624,   486,    27,   525,   533,  2158,  2159,  2160,  2161,
      19,  1755,    25,   541,    27,    24,    24,    26,    26,   486,
     485,  1644,  1645,   486,  1647,  1648,   486,  2179,  1651,  1652,
     486,  1654,  3413,   352,  1657,   563,   994,    26,    24,  2252,
      26,  1864,  3159,   486,  3161,  3140,   486,   568,   424,  3430,
    3167,  3168,    26,  3170,  3171,  3172,  3173,    25,  1681,    27,
     415,   558,  3179,   724,   725,   726,   680,   509,   423,  1692,
    2326,    25,   427,    27,   424,   693,  2332,   680,   696,   697,
      24,  3001,    26,   525,   159,   160,   607,   406,    24,    25,
      26,   410,    40,    41,  2246,  1073,    20,    21,    22,  1722,
      26,  1724,  2358,    26,  1953,  1954,    26,    24,   463,    26,
      26,  1734,  1735,  1736,   486,   636,  1739,  1095,  1741,  1742,
    1743,  1744,    40,    41,   645,   485,   568,   581,    52,   996,
     674,  1754,   999,   509,  1001,  1002,  1003,  1004,  1005,   167,
     168,   169,  1886,  1761,    25,  1968,    27,   486,  1446,   525,
    1448,   513,   514,  1776,   696,   697,   703,   704,  1781,   509,
     486,  1905,   703,   704,  1787,   607,   485,  1790,  2638,  2639,
    2640,  2641,   344,   345,   529,   525,  3293,   486,  2869,  3296,
    3297,  3298,  3299,  2476,  2477,  1808,   486,  1331,   486,  1333,
    1334,  1814,   568,   486,   636,  2930,  2931,  2349,   486,  2351,
    3161,   486,    26,   645,   476,  3322,  3167,   514,    26,  3170,
    3171,  3172,  3173,   568,    26,   486,    26,  2506,   568,    26,
    1843,    26,    26,    26,   674,   149,   150,   151,   152,   153,
     154,   607,   116,   449,  1857,  1858,   419,   592,  1861,  1862,
     674,  1864,    26,   167,   168,   169,   449,   486,  2379,    22,
     486,  2382,  2541,  2384,  2385,   482,  1879,   607,  2873,   449,
     636,    18,    19,    20,    21,    22,     5,  3384,   486,   645,
     526,   449,   449,   449,   449,   449,  3393,   680,  1901,    52,
    1903,   636,   486,    20,    20,   424,   636,   486,   486,   449,
     645,     5,   486,   486,   514,   645,   678,  3090,    26,   674,
      26,    25,  1925,   449,  1927,  1928,  3099,  1930,   449,   315,
     419,  1934,  1935,  1936,   482,    30,    20,    26,    26,    48,
      49,    50,   644,  3116,    53,   424,    55,    56,    26,    26,
    1953,  1954,  3293,    26,    26,  3296,  3297,  3298,  3299,    26,
     644,   449,    26,   449,   449,  1968,   449,   449,    26,     5,
    1973,  1974,  1975,   449,    20,    26,  1979,   486,  2614,  2615,
    2512,    26,    26,  2515,  1987,    26,   674,   449,  1326,     5,
     509,   449,    26,   119,   729,   730,   149,   150,   151,   152,
     153,   154,   306,   680,   449,   309,   525,   359,   449,   449,
    2184,  2014,   449,   449,   167,   168,   169,   678,     5,  2022,
    2023,   449,   449,  2026,   680,   486,    26,   449,    26,   644,
     509,   680,   449,    25,    25,    25,   199,   449,  3180,    25,
     203,   359,   449,  3384,   449,  2048,   525,   449,  2580,   568,
     449,   449,   449,   449,  2057,   449,   678,  2060,  2061,  2062,
    2063,  2064,   449,   674,  2067,   449,  1424,   193,  2071,  2072,
     449,   486,  2075,   674,     8,  1433,   679,   534,   650,   482,
    2930,  2931,  2184,   323,  2934,   515,     5,   672,   607,   568,
    3263,   672,   515,  2096,  2097,  2098,   476,   650,  2101,  2102,
    2103,   713,  1460,  2106,   713,    47,   674,  2730,  2731,  2732,
     385,  2734,  2735,  2736,  2737,  2738,  2739,   636,   651,   514,
    2743,   666,  1847,     5,   713,   429,   645,   674,   607,   255,
     234,   257,  2135,   476,  2137,  2138,   725,  2140,  2141,     5,
     444,  2144,   486,   633,   448,  2148,   486,   273,   486,  2152,
    2153,   486,   403,   306,  2157,   281,   309,   636,  2827,   285,
    2163,  2164,     8,  2166,  2167,   754,   645,  2170,  2171,   111,
     112,   486,    14,     5,   630,   713,     5,   713,   486,   486,
     484,   770,   771,   476,   310,    26,  2855,   776,  2191,    26,
     779,   123,   148,   514,   674,  2198,    26,   644,  2201,   486,
    3373,  3272,   486,   486,   486,   486,   486,  2210,   512,   486,
     486,  2214,  3347,  3348,  3349,  3350,  3351,  3352,   327,   476,
     514,   330,    26,   332,     5,   650,   530,   486,   486,     5,
     680,   486,    51,   486,   680,   716,   178,  2240,   409,   611,
     679,     5,   671,   352,    18,   441,   210,    19,   449,   537,
      25,  1976,   644,   362,   674,   197,   633,   361,   677,   224,
       5,   208,  2265,   367,   368,   369,   537,    26,   601,   601,
     456,   601,    26,   380,   383,   449,   429,    26,   526,   449,
     449,   449,   193,   674,  2009,   389,   581,  1645,   449,  1647,
    1648,   444,   449,  1651,  1652,   448,     5,   406,   680,  1657,
     115,   410,   680,   674,   486,   486,   486,   611,   486,   486,
     449,  3161,  2315,   644,   674,   644,  2848,  3167,  3168,   486,
    3170,  3171,  3172,  3173,   266,   671,     5,  2330,   718,  3179,
     680,   484,   601,     5,     5,  2338,  2339,  2340,     5,  2377,
    2343,  2344,   634,  2346,   255,   538,   257,   674,   486,     5,
       8,    26,    26,  2885,  3014,   680,  2359,  2360,   376,   512,
    2363,  2364,   273,  2537,   384,  2594,   679,  2596,  3363,   275,
     281,   123,     5,   677,   285,     5,   485,   530,  1736,   449,
     322,   323,   486,   486,  1722,   296,  1724,   329,    20,    21,
     494,  2579,   334,   497,   486,   486,  1734,  1735,    14,   310,
    2403,   505,   651,  1741,  1742,  1743,  1744,   418,  2411,   714,
    2413,  2414,   680,     5,  2417,    26,  2419,   605,   157,     5,
     193,   486,   601,   486,  3093,  3496,  2550,  2430,   674,   601,
     680,  2555,  2435,  2436,  2437,  2537,   540,   679,   679,  2563,
    2564,  2565,  3111,  3293,   680,  2448,  3296,  3297,  3298,  3299,
     693,   482,   449,   449,     5,   449,     5,     5,   611,   426,
     673,   390,    26,  2466,   516,   482,  2977,   516,  2979,  2980,
       5,   575,   437,   486,   486,   674,   486,  2579,   486,   486,
     486,  2484,   255,  2486,   257,   486,   451,   486,     5,     8,
     594,   595,    18,    19,    20,    21,  2499,     5,   674,  1857,
     273,   605,   631,  2506,   384,   514,   610,   608,   281,   674,
      25,   403,   285,   403,   674,   403,   486,   149,   150,   151,
     152,   153,   154,   418,   677,   514,   481,     5,  2531,   494,
    2533,   514,  2535,     5,  3384,  2538,  2539,   310,  2541,   705,
     505,    26,     5,  3393,  3180,   649,    58,    59,    60,    61,
      62,    63,     5,  2556,    25,  2558,  2559,  2560,    14,    14,
      26,   526,   486,  3095,   650,   650,   671,     5,   533,   608,
       5,  2574,   735,   736,   516,    26,   541,   681,  2581,   486,
    2976,   680,   449,     6,   449,  3254,   528,   449,   449,   449,
     217,  2594,  1930,  2596,     7,   503,   325,   449,   563,  3131,
     449,  2326,     5,  2606,  2607,   232,   233,  2332,   674,  2612,
      18,    19,    20,    21,   241,    26,    26,    26,   680,    26,
      26,  2624,   449,   149,   150,   151,   152,   153,   154,  1987,
      20,   674,   674,  2358,     5,  2638,  2639,  2640,  2641,  2642,
    2643,   621,  2845,   155,   331,     5,     5,   601,   275,  2652,
       5,     8,   594,   722,  2657,  2858,     5,   284,    20,    21,
     449,   449,   486,   626,     5,  2839,   680,   526,   601,   674,
     833,     5,   268,    26,   678,   640,    18,    19,   680,   449,
     843,   646,    24,    25,    26,    27,   313,   449,   449,   486,
    2693,  2694,   680,   486,     5,   680,    38,    39,   680,  2702,
    2703,     5,  2705,   680,   678,  2708,    25,  2710,    25,  2067,
    2048,  2714,    25,   673,    37,   502,    25,    25,   353,  2057,
      26,    26,  2060,  2061,  2062,  2063,    26,    26,   670,    26,
      26,   358,   449,   449,    26,     5,   449,  2839,   449,   486,
     523,   149,   150,   151,   152,   153,   154,     5,   486,  2873,
     449,  2754,   605,     8,   297,    26,    25,   482,   700,   701,
     702,   449,   704,  2766,   449,   496,   403,    20,   199,   608,
       5,   486,  2775,  2776,  2777,   402,   486,     5,   486,   721,
     122,   486,   486,   486,   486,    14,   268,   149,   150,   151,
     152,   153,   154,     5,   449,   449,   497,   449,  2801,    26,
     514,    26,   449,    26,   449,  2163,  3317,  3318,   486,    26,
    2813,  2814,    26,    26,  2817,   757,   623,  2820,   432,    26,
     449,   763,   297,   765,  2827,   449,  3358,   769,   449,   486,
     772,   994,   403,   775,  2837,   496,   449,  2840,  2841,   298,
     486,   514,  2845,   785,   601,   449,    14,   449,   449,     7,
     296,   296,  2855,   176,    26,  2858,   449,  2860,   800,   680,
    3089,   449,   674,   450,   806,   449,  2869,   486,   449,    26,
     630,   813,   814,   815,   486,   482,    25,   819,  2481,   391,
     298,   449,   449,   449,   449,   827,   449,     5,   514,  2614,
    2615,    26,   404,    26,  2418,   449,  2420,   674,     5,   482,
      26,   843,   449,   674,   482,   247,  2909,   674,  2558,  2499,
    3423,  1021,  2915,  1076,  2236,  1582,    35,  1914,  2167,  2531,
     689,  2924,  2925,    37,  2927,  2928,   362,  2930,  2931,  2173,
    3462,  2934,   119,   123,   214,   363,   353,   674,   547,  1760,
     219,  1315,  2945,  1761,   392,   615,   580,   391,  3413,   819,
     578,  1813,  1012,   427,   466,   278,  2020,  2315,  2027,  1285,
     472,  2160,  1616,   286,  1863,  2968,  2969,  2583,  1943,   292,
    2261,   294,  2895,  1619,  3467,  2163,  1963,  3107,    22,    47,
      47,  1465,   305,    98,  2987,    28,  2344,  2377,  1919,   948,
     775,   334,  2995,  1925,  1593,  2998,  1624,  1540,  3001,   511,
    1928,  3004,  2360,  3006,  1039,  3008,  3032,  1252,  2346,  3217,
     333,  1459,  3430,  2581,   800,  1538,  2769,  1448,  3227,  1893,
    1562,   464,  3087,   535,  2767,  2825,   349,  2447,  1288,  3032,
    2752,   354,  3085,   545,   546,  2638,  2639,  2640,  2641,   551,
    2152,  3078,  1793,   366,  2817,  1776,  2326,  2106,  3439,   561,
     373,  3008,  2345,  2411,  1659,  2413,  1998,  2927,  2774,  3241,
    2808,  2067,  1659,  2693,  2417,  2403,  3069,  1986,  2694,  2998,
    3322,   583,  2796,  2469,   586,   587,  3050,  1644,  2448,   591,
    2414,  2419,   622,     9,  3485,  2436,  3089,  1281,  1251,  2437,
    3093,  3279,  2430,  2929,  2625,  1735,  3006,  1734,  2339,  1638,
    3283,  2924,  1277,  3159,  1611,  3178,  3167,  1754,  3111,  2539,
     452,  1139,  1474,  2184,  2638,  2639,  2640,  2641,  1482,  1464,
    2537,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,  1076,    -1,   648,  3140,    -1,    -1,
      -1,   483,  3145,    -1,   486,  3148,    -1,   659,    -1,    -1,
    1092,    -1,    -1,  1316,  1317,    -1,  3159,   499,  3161,    -1,
      -1,    -1,    -1,  1326,  3167,  3168,    -1,  3170,  3171,  3172,
    3173,    -1,    -1,  3176,    -1,  3178,  3179,  3279,  3181,    -1,
    2704,  2539,  2706,    48,    49,    50,    -1,    -1,    53,    -1,
      55,    56,  1134,    -1,    -1,    -1,   538,   539,   521,    -1,
      -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,   551,
     533,    -1,    -1,    -1,  3217,    -1,    -1,    -1,    -1,  3222,
      -1,  3224,  1164,  1165,  1166,    -1,  1168,    -1,  1170,  1171,
      -1,    -1,   555,    -1,  1176,  1177,    -1,   560,  3241,  3363,
      -1,    -1,    -1,  2581,    -1,    -1,    -1,    -1,    -1,    -1,
     592,  3254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3272,
      48,    49,    50,  1215,  2612,    53,    -1,    55,    56,    -1,
    3283,    -1,    -1,    -1,    -1,  1227,  3289,    -1,    -1,   631,
    3293,    -1,    -1,  3296,  3297,  3298,  3299,    -1,  3301,    -1,
      -1,   643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1251,
    1252,    -1,  3315,   655,   656,    -1,    -1,    -1,  1260,  3322,
      -1,   663,    -1,  3326,   666,  1488,    -1,  2930,  2931,    -1,
      -1,  2934,   674,    -1,  1276,  1277,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,  3347,  3348,  3349,  3350,  3351,  3352,
    3075,    -1,    -1,    -1,    -1,    -1,  3359,    -1,    -1,    -1,
    3085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3384,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
    3393,    -1,  2995,    26,    27,  2998,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2930,  2931,    -1,    42,
    2934,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,  1679,
    1680,    -1,    18,    19,    -1,    -1,  1686,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,  3439,    -1,  3441,    -1,
      -1,    -1,    -1,  2801,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3180,    -1,    -1,    -1,    -1,
      -1,  1624,   327,    -1,    -1,   330,   361,   332,    -1,    -1,
      -1,    -1,   367,   368,   369,    -1,    -1,    -1,    -1,    -1,
    3483,  3484,  3485,    -1,   117,    -1,    -1,   352,    -1,    -1,
      -1,    -1,    -1,  3496,   389,  3498,   129,   362,    -1,    -1,
      -1,    -1,    -1,    -1,  1446,    -1,  1448,    -1,  1450,  1451,
      -1,    -1,    -1,    -1,    -1,    -1,  1458,  1459,   383,    -1,
    1462,   117,    -1,   156,  1466,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,  1477,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    -1,   410,  1488,  1489,    -1,   327,
      -1,    -1,   330,    -1,   332,    -1,    -1,    -1,  3161,  1722,
     156,  1724,    -1,    -1,  3167,  3168,    -1,  3170,  3171,  3172,
    3173,  1734,  1735,    -1,   352,    -1,  3179,    -1,  1741,  1742,
    1743,  1744,    -1,    -1,   362,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3198,    -1,  1539,  1540,   494,
    1542,    -1,   497,  1545,  1546,   383,    -1,    -1,    -1,    -1,
     505,    -1,    -1,    -1,   247,    -1,   249,    -1,    -1,    -1,
     485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,  2987,
      -1,    -1,   410,    -1,  1576,    -1,  1896,  3161,    -1,    -1,
      -1,    -1,    -1,  3167,  3168,   540,  3170,  3171,  3172,  3173,
      -1,   247,    -1,   249,    -1,  3179,    -1,    -1,    -1,    -1,
      -1,    -1,  1604,    -1,    -1,    -1,  3004,    -1,  3006,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1939,
     575,  1623,  1624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3293,    -1,    -1,  3296,  3297,  3298,  3299,    -1,    -1,   594,
     595,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,
     605,    -1,    -1,   346,    -1,   610,    -1,    -1,    -1,  3322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1681,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,    -1,
     346,    -1,    -1,    -1,   649,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1930,    -1,  3293,
      -1,    -1,  3296,  3297,  3298,  3299,    -1,    -1,    -1,    -1,
      -1,  3384,   415,    -1,    -1,   381,   681,    -1,    -1,    -1,
    3393,    -1,    18,    19,   427,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,  3145,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    52,    -1,    -1,   415,
      -1,  3159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     463,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,   445,
      -1,    -1,    -1,   486,   450,    -1,   452,    -1,    -1,    -1,
    3384,    -1,    -1,    -1,    -1,    -1,   499,   463,    -1,  3393,
      -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   478,    -1,    -1,  2048,    -1,   483,    -1,    -1,
     486,    -1,    -1,   489,  2057,    -1,   122,  2060,  2061,  2062,
    2063,    -1,   498,   499,    -1,    -1,    -1,    -1,    -1,  2072,
     543,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,   568,    -1,  1879,    -1,  2102,
      -1,    -1,   538,   539,    -1,    -1,    -1,   543,    -1,    -1,
      -1,  3289,    -1,    -1,    -1,   551,    -1,    -1,    -1,   592,
      -1,  1903,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
    2230,  2231,   568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2241,    -1,  1925,    -1,    -1,    -1,    -1,  3326,    -1,
      -1,    -1,  1934,    -1,  1936,    -1,   592,    -1,    -1,    -1,
      -1,    -1,    -1,   636,    -1,    -1,  2266,  2267,  2268,  2269,
    2270,  2271,   645,    -1,    -1,    -1,  2276,  2277,  2278,  2279,
      -1,   247,    -1,  2283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1973,  1974,  1975,    -1,    -1,    -1,  1979,  2201,    -1,
     636,    18,    19,    20,    21,    22,    -1,   643,    -1,   645,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,
     656,    -1,    -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,
     306,    -1,  2014,   309,    -1,    52,    -1,    -1,   674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   729,   730,    -1,    -1,
      -1,  3439,    -1,    -1,    -1,  2365,  2366,    -1,    -1,    -1,
      -1,    -1,  2372,  2373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   729,   730,    -1,    -1,    -1,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,  2346,    -1,    52,    -1,    -1,    -1,    -1,
     167,   168,   169,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,  2153,   448,     9,    -1,  2157,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,  2166,    -1,   452,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2403,    -1,  2184,    -1,    -1,    -1,    42,    -1,   484,  2191,
      -1,    -1,    -1,    -1,  2417,    -1,  2419,   483,    -1,  2201,
     486,  2521,  2522,    -1,    -1,    -1,    -1,  2430,  2210,    -1,
    2530,    -1,  2214,   499,    -1,    -1,   512,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,  2240,    -1,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,  2568,  2569,
      -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,  2481,    -1,
      -1,   117,    -1,    -1,    -1,   551,   122,    -1,    -1,   306,
      -1,    -1,   309,   129,    -1,  2595,    -1,  2597,    -1,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     156,    -1,    -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   611,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2658,  2659,
      -1,    -1,  2662,  2663,    -1,   631,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,  2581,    -1,
      -1,  2363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,
     656,    -1,    -1,    -1,    -1,    -1,    -1,   663,    -1,   306,
     666,   677,   309,    -1,    -1,    -1,    -1,    -1,   674,  2612,
      -1,   247,   429,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   448,    -1,    -1,    -1,  2638,  2639,  2640,  2641,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,  2436,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2693,  2694,    -1,    -1,    -1,   512,    -1,    -1,    -1,  2702,
    2703,    -1,  2705,    -1,    -1,  2708,    -1,  2710,    -1,    -1,
     346,  2714,    -1,   530,    -1,   351,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,  2506,    -1,    -1,  2730,  2731,  2732,
      -1,  2734,  2735,  2736,  2737,  2738,  2739,   444,  2838,    -1,
    2743,   448,  2842,    -1,    -1,   381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2537,    -1,    -1,    -1,  2541,
      -1,  2861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2556,    -1,  2558,   484,  2560,   415,
      -1,  2881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   427,  2574,    -1,   611,    -1,    -1,  2579,    -1,    -1,
     306,    -1,    -1,   309,    -1,   512,    -1,    -1,    -1,   445,
      -1,    -1,    -1,    -1,   450,    -1,   452,    -1,    -1,    -1,
      -1,    -1,    -1,   530,  2606,  2607,    -1,   463,    -1,    -1,
      -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   478,    -1,    -1,    -1,    -1,   483,    -1,    -1,
     486,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,
     677,    -1,   498,   499,    -1,    -1,  2869,    -1,    -1,    -1,
    2652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   538,   539,   611,    -1,    -1,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,    -1,   562,  2930,  2931,    -1,
      -1,  2934,   568,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   592,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     677,    -1,  2754,    -1,    -1,    -1,    -1,    -1,   484,    -1,
      -1,    -1,    -1,    -1,  2766,    -1,    -1,    67,    68,    69,
      70,    -1,  2995,    -1,    -1,  2998,    -1,    -1,  3001,    52,
     636,  3004,    -1,  3006,    -1,    -1,   512,   643,    -1,   645,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,
     656,    -1,    -1,    -1,   530,    -1,    -1,   663,    -1,  3129,
      -1,    -1,  3132,    -1,    -1,    -1,    -1,    -1,   674,    -1,
      -1,    -1,    -1,    -1,    -1,  2827,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2839,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3069,    -1,    -1,    -1,
      -1,    -1,    -1,  2855,     9,    -1,    -1,    -1,  2860,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,  2869,    -1,    24,
      25,    26,    27,   729,   730,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   611,    -1,    42,    -1,   189,
      -1,    -1,    -1,    -1,   167,   168,   169,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,   209,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,   134,   135,
     136,    -1,  3145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3159,    -1,  3161,    -1,
      -1,    -1,    -1,    -1,  3167,  3168,    -1,  3170,  3171,  3172,
    3173,   677,   252,    -1,    -1,    -1,  3179,  3277,  3181,   259,
      -1,    -1,   117,    -1,    -1,    -1,  2968,   122,    -1,     9,
      -1,    -1,    -1,    -1,   129,  3198,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    42,    -1,    -1,    -1,    -1,    -1,  3328,  3329,
      -1,  3331,    -1,  3333,  3334,    -1,   316,   233,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
    3032,    -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,
      -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,   348,  3272,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     360,    -1,    -1,    -1,    -1,    -1,  3289,    -1,   284,    -1,
    3293,    -1,    -1,  3296,  3297,  3298,  3299,   117,    -1,    -1,
      -1,  3401,   122,  3403,    -1,    -1,    -1,    -1,   388,   129,
      -1,  3093,   247,    -1,   249,    -1,   396,   313,   314,  3322,
      -1,    -1,    -1,  3326,    -1,    -1,    -1,    -1,    -1,  3111,
      -1,    -1,    -1,    -1,    -1,    -1,   156,  3437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,    -1,    -1,  3456,  3457,  3140,    -1,
    3460,    -1,   358,  3463,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   457,    -1,    38,
      39,  3384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3393,   444,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   402,    -1,    -1,    -1,
      -1,   346,    -1,    -1,   494,    -1,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   505,    -1,   247,    -1,   249,
      -1,   484,    -1,    -1,    -1,  3217,  3439,    -1,    -1,    -1,
    3222,    -1,  3224,    -1,    -1,    -1,   381,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,
     456,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3254,    -1,    -1,    -1,    -1,   530,    -1,    -1,
     415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
    3272,    -1,   427,  3496,    -1,    -1,    -1,  3279,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
     445,    -1,    -1,    -1,    -1,   450,    -1,   452,    -1,    -1,
      -1,    -1,    42,   603,   604,   605,   346,    -1,   463,    -1,
      -1,   351,    -1,   468,    -1,    -1,   616,    -1,    -1,    -1,
      -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,   483,    -1,
      -1,   486,    -1,   121,   489,    -1,    -1,    -1,   611,    -1,
      -1,   381,    -1,   498,   499,  3347,  3348,  3349,  3350,  3351,
    3352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   661,    -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,   415,    -1,   117,    -1,    -1,
      -1,    -1,   122,    -1,   539,    -1,    -1,   427,   543,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   551,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   677,   445,    -1,   562,    -1,   564,
     450,    -1,   452,   568,    -1,    -1,   156,    -1,    -1,   719,
      -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    -1,    -1,   735,    -1,   592,   478,    -1,
      -1,    -1,    -1,   483,    -1,    -1,   486,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,
      -1,    -1,    -1,    -1,    -1,    -1,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,    -1,    -1,    -1,    -1,
      -1,   636,    -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,
     645,    -1,    -1,    -1,  3496,    -1,    -1,    -1,   538,   539,
     655,   656,    -1,   543,    -1,    -1,    -1,   247,   663,   249,
      -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,
      -1,    -1,    -1,   452,   729,   730,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,   377,
     378,    -1,    -1,    -1,    -1,    -1,   636,    -1,    -1,    -1,
      -1,    -1,    -1,   643,   483,   645,   346,   486,    -1,    -1,
      23,   351,    -1,    -1,    -1,   655,   656,    -1,    -1,    -1,
     499,    -1,    -1,   663,    -1,    -1,    -1,   415,    -1,    -1,
      -1,    -1,    -1,    -1,   674,    48,    49,    50,    -1,   427,
      53,   381,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     539,    -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,
      -1,    -1,   551,    -1,    -1,   415,   464,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,    -1,   427,    -1,   729,
     730,   479,    -1,    -1,    -1,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,    -1,   120,    -1,    -1,
     450,    -1,   452,   592,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,   478,   527,
      -1,    -1,    -1,   483,    -1,    -1,   486,    -1,    -1,   489,
      -1,    -1,   631,    -1,    -1,    -1,    -1,    -1,   498,   499,
      -1,    -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,   557,
      -1,    -1,    -1,    -1,    -1,    -1,   655,   656,    -1,   567,
     193,    -1,    -1,    -1,   663,    -1,    -1,   666,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   674,    -1,    -1,    -1,   539,
     588,    -1,    -1,   543,   592,    -1,    -1,    -1,   221,    -1,
     223,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   568,    -1,
      -1,    -1,   620,    -1,   306,   248,    -1,   309,    -1,    -1,
      -1,   629,   255,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,   268,    -1,    -1,    -1,    -1,
     273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,
      -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,   291,    -1,
      -1,    -1,   295,   296,   297,   298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   636,   310,    -1,    -1,
      -1,    -1,    -1,   643,    -1,   645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   327,   655,   656,   330,    -1,   332,
      30,    -1,    -1,   663,    34,    -1,   339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   674,    45,    46,    47,    -1,   352,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,   362,
      -1,    -1,    -1,    -1,    64,    65,    -1,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,   384,   444,    -1,    -1,    -1,   448,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,    -1,   729,
     730,    -1,    -1,   406,    -1,    -1,    -1,   410,    -1,   109,
     110,    -1,    -1,    -1,   114,   418,   419,   420,    -1,    -1,
      -1,    -1,   484,    -1,   124,   125,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,    -1,   530,    -1,
      -1,    -1,    -1,    -1,    -1,   175,    -1,   177,   178,   179,
      -1,    -1,   485,    -1,    -1,    -1,    -1,   187,   188,    -1,
     190,   191,   192,   496,    -1,    -1,    -1,    -1,   198,    -1,
      -1,   201,    -1,   203,   204,   205,    -1,    -1,    -1,    -1,
      -1,   211,    -1,   213,   214,    -1,   216,    -1,   218,   219,
      -1,    -1,   222,    -1,    -1,   225,   226,   227,   228,   229,
     230,    -1,    -1,   536,   234,   235,   236,    -1,   238,    -1,
      -1,    -1,   242,    -1,   244,   245,    -1,    -1,    -1,   611,
     250,    -1,    -1,   253,    -1,    -1,   256,    -1,   258,    -1,
     260,    -1,   262,    -1,    -1,    -1,   266,   267,    -1,   269,
     270,   271,    -1,    -1,   274,    -1,   276,   277,    -1,   279,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,   288,    -1,
      -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,
     300,    -1,    -1,   303,   304,    -1,    -1,   307,   308,    -1,
      -1,   311,   312,    -1,    -1,   677,    -1,    -1,    -1,    -1,
     320,   321,   322,    -1,   324,    -1,    -1,    -1,    -1,    -1,
     633,    -1,    -1,    -1,   334,   335,   336,    -1,   338,    -1,
      -1,    -1,   342,   343,    -1,    -1,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   363,   364,   365,    -1,    -1,    -1,    -1,
      -1,   371,   372,    -1,    -1,    -1,   679,    -1,    -1,   379,
      -1,    -1,   382,    -1,    -1,    -1,   386,   387,    -1,    -1,
     693,   694,   695,   696,   697,   698,   699,   397,   701,   702,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   414,   718,    -1,    -1,    -1,    -1,
      -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,   457,    -1,   459,
     460,    -1,    -1,    -1,     6,     7,     8,   467,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,   506,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,   517,    -1,    -1,
      -1,    -1,    -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,   548,   549,
      -1,    -1,    -1,   553,    -1,    -1,    -1,    -1,   167,   168,
     169,    -1,    -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,
      -1,   571,   572,   573,   574,    -1,    -1,    -1,   578,    -1,
      -1,    -1,   582,    -1,    -1,    -1,    -1,    -1,    -1,   589,
     590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,    -1,   602,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,   613,    -1,   615,    -1,    -1,   618,    -1,
      -1,    -1,    -1,    -1,   624,   167,   168,   169,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,    -1,
     650,    -1,    -1,   653,    -1,    -1,    -1,    -1,   658,    -1,
      -1,   661,   662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
       6,     7,     8,   683,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   306,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    -1,   706,   707,   708,   709,
     710,   711,   712,    -1,    -1,   715,    -1,   717,    -1,   719,
      -1,    -1,    -1,     6,     7,     8,    52,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,    -1,    -1,   309,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   306,    -1,    -1,   309,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,    52,   448,
      -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   168,   169,   429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,   444,   512,    -1,    -1,   448,   449,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   530,    -1,   444,    -1,    -1,    -1,   448,   449,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,
     512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     306,    -1,    -1,   309,    -1,    -1,    -1,    -1,   530,    -1,
      -1,   512,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,   530,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   677,   611,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     611,    -1,   306,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,    -1,   448,   449,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,   306,
      -1,    -1,   309,    -1,    -1,    -1,   677,    -1,   484,    -1,
      -1,   444,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,   512,
     444,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,     6,     7,     8,   530,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     484,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   611,    -1,   444,    -1,    -1,
      52,   448,   449,    -1,    -1,     6,     7,     8,   512,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   484,   611,    -1,
     306,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   677,     6,     7,     8,   512,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   677,    -1,    -1,   611,    52,    -1,
      -1,    -1,    -1,    -1,    -1,   167,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,   429,   611,    -1,   167,   168,   169,    52,
      -1,    -1,    -1,   677,    -1,    -1,    -1,    -1,   444,    -1,
      -1,    -1,   448,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,    -1,
      -1,    -1,    -1,   167,   168,   169,    -1,    52,    -1,    -1,
     677,   497,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,    -1,    -1,   309,    -1,    -1,
      -1,    -1,   351,    -1,   530,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,   306,    -1,    -1,   309,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   168,   169,   611,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   306,   452,    -1,   309,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,   429,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   167,
     168,   169,   444,    -1,   483,    -1,   448,   486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
     499,   677,    -1,    -1,   122,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,   306,    -1,    -1,   309,    -1,   429,    -1,
      -1,    -1,   484,    -1,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,   444,    -1,   497,    -1,   448,    -1,    -1,
     539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     512,    -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,
      -1,   306,    -1,   484,   309,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,
     444,    -1,    -1,   592,   448,    -1,    -1,    -1,    -1,    -1,
      -1,   512,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,   530,
      -1,   309,    -1,   167,   168,   169,   625,    -1,    -1,   247,
     484,    -1,   631,    -1,    -1,    -1,   429,    -1,    -1,    -1,
      -1,   640,   641,    -1,   643,    -1,    -1,    -1,    -1,   611,
      -1,   444,    -1,    -1,    -1,   448,   655,   656,   512,    -1,
      -1,    -1,    -1,    -1,   663,    -1,    -1,   666,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   674,   530,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,
     611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
      -1,    -1,    -1,   448,    -1,   677,    -1,    -1,    -1,   512,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    -1,   530,    -1,    -1,
      -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   611,    52,    -1,
     448,    -1,   306,    -1,    -1,   309,   677,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   530,   484,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   497,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,   611,    -1,
      -1,    -1,    -1,   677,   512,    -1,    16,    17,    18,    19,
      20,    21,    22,    -1,   452,    -1,    -1,    52,    -1,    -1,
      -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    52,    -1,    -1,   483,    -1,    -1,   486,    -1,
      -1,    -1,    -1,   167,   168,   169,   611,    -1,    -1,    -1,
     498,   499,    -1,    -1,   677,   429,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
     444,    -1,    -1,    -1,   448,    -1,    38,    39,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,     5,
      -1,   539,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,   551,   149,   150,   151,   152,   153,   154,
     484,    -1,   677,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,   167,   168,   169,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   512,    -1,
      -1,    -1,    -1,    -1,   592,    -1,    -1,   167,   168,   169,
      -1,    52,    -1,    -1,    -1,    -1,   530,    -1,    -1,   677,
     122,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,   625,    -1,    -1,
      -1,    -1,   306,   631,    -1,   309,    38,    39,    -1,    -1,
      -1,    -1,   640,   641,    -1,   643,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,   655,   656,    24,
      25,    26,    27,    -1,    -1,   663,    -1,    -1,   666,    -1,
      -1,    -1,    -1,    38,    39,    -1,   674,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   611,    -1,   306,
      -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   306,    -1,    -1,   309,    -1,   167,   168,   169,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   306,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   677,    -1,   429,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,    -1,    -1,    -1,   448,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     484,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   448,    -1,    -1,   429,    -1,    -1,    -1,   512,   351,
      -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   444,
      -1,   317,    -1,   448,    -1,   306,   530,    -1,   309,   429,
      -1,    -1,    -1,    18,    19,    20,    -1,   484,    -1,    24,
      25,    26,    27,    -1,   444,    -1,    -1,    -1,   448,   122,
      -1,    -1,   247,    38,    39,    -1,    -1,    -1,    -1,   484,
     356,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,
     376,    -1,    -1,   530,   484,    -1,    -1,   512,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   530,    -1,   611,    38,    39,
     452,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,   415,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     530,   427,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   483,   438,    -1,   486,    -1,    -1,    -1,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   498,   499,   454,    -1,
      -1,    -1,    -1,   444,   611,    -1,    -1,   448,   464,    18,
      19,    -1,    -1,   677,   247,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,   479,    -1,    -1,   611,    -1,    -1,    38,
      39,    -1,   122,    -1,    -1,    -1,    -1,   539,    -1,    -1,
      20,    -1,    -1,   484,    24,    25,    26,    27,    -1,   551,
      -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
     452,    -1,    -1,   519,    -1,    -1,    -1,    -1,    -1,    -1,
     677,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,   530,
     592,   483,   677,    32,   486,    -1,    -1,   452,    -1,    -1,
      -1,   557,   247,    -1,    -1,    44,    -1,   499,   564,    -1,
      -1,   567,    -1,   122,    -1,    -1,    -1,   677,    -1,    -1,
      -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,   483,   631,
      -1,   486,   588,    -1,   526,    -1,   592,    -1,   640,   641,
      -1,   643,   122,    -1,   499,    -1,    -1,   539,    -1,    -1,
      -1,    -1,    -1,   655,   656,   611,    -1,   247,    -1,   551,
      -1,   663,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,
     611,    -1,   674,   629,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   538,   539,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   551,    -1,   137,   138,
     592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   625,    -1,    -1,   677,   592,   247,   631,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,   641,
     483,   643,    -1,   486,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,   655,   656,    -1,   499,   247,    -1,    -1,
     625,   663,    -1,    -1,   666,    -1,   631,    -1,    -1,    -1,
      -1,    -1,   674,    -1,    -1,   640,   641,    -1,   643,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     655,   656,    -1,    -1,    -1,   538,   539,   452,   663,    -1,
      -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,   551,   674,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   499,    -1,    -1,    -1,    -1,   592,
      -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   625,   483,   539,    -1,   486,    -1,   631,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   551,   640,   641,   499,
     643,    -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,
      -1,    -1,   655,   656,    -1,    -1,    -1,    -1,    -1,    -1,
     663,    -1,    -1,   666,    -1,    -1,   375,   376,   377,   378,
      -1,   674,    -1,   452,    -1,    -1,    -1,   592,    -1,   539,
      -1,    -1,    -1,    -1,   393,    -1,    -1,   259,    -1,    -1,
      -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   452,    -1,   483,    -1,   415,   486,    -1,    -1,
     625,    -1,    -1,    -1,    -1,    -1,   631,    -1,   427,    -1,
     499,    -1,    -1,    -1,    -1,   640,   641,    -1,   643,   438,
      -1,    -1,   592,   483,    -1,    -1,   486,    -1,    -1,    -1,
     655,   656,    -1,    -1,   316,   454,    -1,   526,   663,   499,
      -1,   666,    -1,    -1,    -1,   464,    -1,    -1,    -1,   674,
     539,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,   341,
     479,   631,   551,    -1,    -1,    -1,    -1,    -1,   350,    -1,
     640,   641,    -1,   643,    -1,    -1,    -1,    -1,   317,   539,
      -1,    -1,    -1,    -1,    -1,   655,   656,    -1,    -1,    -1,
      -1,   551,    -1,   663,    -1,    -1,   666,    -1,    -1,    -1,
     519,    -1,    -1,   592,   674,    -1,   388,    -1,    -1,   391,
      -1,    -1,    -1,    -1,   396,    -1,    -1,   356,    -1,    -1,
      -1,    -1,   404,   542,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,   375,   376,   557,    -1,
      -1,    -1,   631,    -1,    -1,   564,    -1,    -1,   567,    -1,
      -1,    -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   625,   655,   656,    -1,   588,
      -1,   631,    -1,   592,   663,    -1,   415,   666,    -1,    -1,
     640,   641,    -1,   643,   466,   674,    -1,    -1,   427,    -1,
     472,    -1,   611,    -1,    -1,   655,   656,    -1,    -1,   438,
      -1,    -1,    -1,   663,    -1,   487,   666,    -1,    -1,    -1,
     629,    -1,    -1,    -1,   674,   454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   464,    -1,    -1,    -1,   511,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   671,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,   546,    -1,    -1,    -1,    -1,   551,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,
     519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   583,    -1,   542,   586,   587,    -1,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,
      -1,    -1,    -1,    -1,    -1,   564,    -1,    -1,   567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,
      -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   648,    -1,    -1,    -1,
      -1,    -1,   611,    -1,    -1,   657,    -1,   659,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     629
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    43,   133,   293,   414,   462,   493,   522,
     733,   795,   803,   830,   831,   887,  1061,  1062,  1118,  1119,
    1120,  1122,  1123,  1124,  1129,  1131,  1144,  1145,  1146,  1147,
    1148,  1590,    28,    29,   804,   805,   806,   807,   808,    27,
    1025,  1605,  1025,  1025,    25,  1025,  1495,  1149,   832,  1495,
    1025,   831,     0,  1121,  1124,  1147,    31,   806,   808,   888,
     666,    25,   247,   829,   830,  1012,  1025,  1030,  1129,  1144,
    1150,  1181,  1182,  1183,  1184,  1185,  1189,   412,   834,   835,
     836,   837,   840,   841,   796,   111,   118,   164,   165,   425,
     520,   612,   692,   700,   803,   980,  1060,  1125,  1126,  1128,
    1132,  1133,  1139,  1151,  1304,  1314,  1590,   671,  1025,  1184,
     299,   513,   514,  1190,    20,  1025,  1188,   674,   835,     5,
     833,   412,  1025,     5,   860,   862,   863,   734,   799,  1025,
    1315,  1025,  1305,  1140,  1025,  1025,  1128,  1134,   317,   356,
     375,   376,   415,   427,   438,   454,   464,   479,   519,   542,
     557,   564,   567,   588,   592,   611,   629,   889,   890,   891,
     894,    25,  1181,  1187,    18,    19,    26,    42,   117,   129,
     156,   249,   346,   381,   415,   427,   463,   478,   486,   499,
     543,   568,   592,   636,   645,   729,   730,   744,   746,   947,
     954,   965,   967,  1025,  1181,  1191,  1192,   514,    14,   886,
     837,   577,  1291,   838,   835,   840,    32,    44,   121,   137,
     138,   147,   317,   356,   375,   376,   377,   378,   393,   415,
     427,   438,   454,   464,   479,   519,   542,   557,   564,   567,
     588,   592,   611,   629,   671,   844,   854,   865,   870,  1025,
     797,  1025,   486,  1025,   829,   981,  1152,  1025,   896,   376,
     842,   486,   872,   874,   875,   873,   882,   883,   486,   486,
     895,   514,   486,   835,   853,   481,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   744,   486,   826,
       9,    18,    19,    24,    25,    26,   122,   351,   445,   450,
     452,   468,   483,   486,   489,   498,   539,   551,   562,   592,
     643,   655,   656,   663,   674,   923,   931,   932,   933,   934,
     935,   965,   966,   968,  1031,  1181,  1294,  1488,   486,   486,
     486,   486,   486,   486,    18,    19,    20,    21,    22,   745,
      26,    36,   486,   576,     5,   482,  1191,    25,    26,  1025,
    1031,    19,    25,    26,   839,  1031,   724,   725,   726,   843,
     867,   856,   868,   842,   486,   486,   486,   857,   872,   873,
     486,   486,   855,   514,   866,   486,   853,   835,   864,   829,
     486,    26,   486,  1141,   829,   829,   486,  1025,   486,   513,
     848,    26,   680,   424,   509,   525,   568,   607,   636,   645,
     876,   680,   424,   509,   525,   568,   607,   636,   645,   884,
      26,    26,   897,   898,   899,   900,  1025,    26,   851,   852,
      26,   644,   666,   674,  1181,   721,   973,  1016,  1025,  1016,
    1016,   973,   973,   923,    24,    25,    26,    19,    24,    25,
      26,   969,   970,   971,   972,    25,   974,  1016,  1017,   923,
     449,   923,   923,   923,   923,   581,  1311,   486,   486,   923,
     424,   509,   525,   568,   607,   636,   645,  1491,  1492,   486,
     923,   923,   486,   486,   936,   486,   486,   486,   486,    26,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    52,   149,   150,   151,
     152,   153,   154,   167,   168,   169,   306,   309,   429,   444,
     448,   484,   512,   530,   611,   677,   825,   924,   937,   939,
     940,   941,   942,   943,   944,   945,   476,   957,   955,   961,
     959,  1181,  1181,   744,  1025,   948,  1025,  1192,   514,   482,
      26,   846,   486,   869,   853,   869,   848,    26,    26,    26,
     853,    26,    26,   834,   851,   869,    26,   674,   116,   861,
     798,  1316,   449,  1306,  1606,  1607,  1608,  1609,  1610,   982,
    1153,  1135,   674,    26,   449,   877,   878,   486,   879,   884,
     885,   879,   486,   880,     5,   449,     5,   449,     5,   340,
       5,   889,   482,     5,     5,   449,   835,   835,   835,   871,
     449,   486,     5,   449,   514,   674,   449,   449,   449,   449,
     449,   449,   449,    19,    26,   449,   644,   970,    19,    26,
     644,   449,     5,   449,   449,     5,   827,   923,   526,  1511,
     923,   486,   680,    20,   449,  1511,    20,  1294,   923,   923,
     923,   923,   923,   923,   923,   923,   923,   923,   923,   923,
     923,   923,   923,   923,   923,   923,   923,   923,   923,   923,
     923,   486,   923,   923,   486,  1181,   923,   923,   923,   923,
     449,     5,   486,   538,   776,   777,   778,   923,   486,  1191,
     514,   678,    26,   674,    26,   449,   449,     5,   449,   315,
       5,   449,     5,   449,   340,   482,     5,   449,   871,   800,
     801,  1133,  1025,  1197,  1198,  1200,  1197,   419,  1607,  1291,
      45,    46,    47,    54,    57,    64,    65,   109,   110,   114,
     124,   125,   127,   141,   158,   161,   162,   175,   177,   178,
     179,   187,   188,   190,   191,   192,   198,   201,   203,   204,
     205,   211,   213,   214,   216,   218,   219,   222,   225,   226,
     227,   228,   229,   230,   234,   235,   236,   238,   242,   244,
     245,   250,   253,   256,   258,   260,   262,   266,   267,   269,
     270,   271,   274,   276,   277,   279,   287,   288,   300,   303,
     304,   307,   308,   311,   312,   320,   321,   322,   324,   334,
     335,   336,   338,   342,   343,   347,   355,   363,   364,   365,
     371,   372,   379,   382,   386,   387,   397,   414,   422,   428,
     439,   451,   457,   459,   460,   467,   506,   517,   524,   548,
     549,   553,   565,   571,   572,   573,   574,   578,   582,   589,
     590,   600,   602,   613,   615,   618,   624,   650,   653,   658,
     661,   662,   676,   683,   706,   707,   708,   709,   710,   711,
     712,   715,   717,   719,   737,   738,   739,   740,   757,   781,
     802,   803,   809,   828,   902,   903,   904,   905,   916,   917,
     918,   919,   920,   921,   922,   975,  1006,  1010,  1032,  1034,
    1037,  1038,  1039,  1040,  1053,  1063,  1087,  1088,  1090,  1094,
    1109,  1110,  1114,  1115,  1116,  1117,  1127,  1142,  1158,  1169,
    1170,  1171,  1175,  1178,  1212,  1215,  1217,  1223,  1224,  1227,
    1230,  1235,  1237,  1239,  1242,  1249,  1254,  1259,  1260,  1261,
    1273,  1274,  1277,  1283,  1286,  1287,  1312,  1327,  1329,  1330,
    1331,  1332,  1344,  1350,  1351,  1371,  1374,  1403,  1405,  1496,
    1497,  1528,  1529,  1536,  1551,  1575,  1590,  1591,  1596,  1597,
    1599,  1603,  1604,  1611,   803,  1130,   679,   702,  1154,  1155,
    1197,    20,   449,   481,   849,   876,    26,   881,    26,    26,
      26,   898,   900,   892,   852,    26,   644,  1025,  1016,   744,
      20,   721,  1025,   876,   963,   963,    26,   449,   644,   963,
      24,    26,    26,   644,    24,    26,   873,   964,  1017,   874,
     449,   417,   531,   640,  1519,   449,   449,    26,  1492,   449,
     449,   449,   449,   449,   449,   449,   497,   497,   497,   946,
    1511,   497,   946,  1511,   958,   956,   962,   960,    26,   952,
     949,     5,   950,   482,  1191,   860,   449,    20,   849,    26,
     486,    26,    26,   845,    26,   732,   801,   674,   449,     5,
     449,  1181,  1181,  1181,  1025,    25,  1181,  1236,  1025,    25,
    1025,  1481,   408,  1026,  1027,  1605,  1026,    25,  1025,  1480,
    1025,  1025,  1257,  1020,  1026,  1020,  1025,  1601,  1481,  1025,
      26,   741,  1181,  1335,  1020,  1257,   946,    26,  1031,  1299,
    1300,  1299,   923,   930,  1373,  1480,  1480,   925,   946,  1026,
    1537,  1537,   906,  1257,  1020,  1333,  1181,  1022,  1026,   930,
    1537,  1181,  1257,  1181,  1372,  1537,    25,   640,  1172,  1173,
    1181,  1020,  1020,  1172,  1021,  1026,  1025,  1173,  1020,  1537,
    1020,  1022,  1481,  1181,  1210,  1211,  1018,  1026,  1022,   433,
     616,  1016,  1089,  1025,   810,  1480,  1023,  1026,    25,   247,
    1025,  1404,  1579,  1581,  1582,  1583,  1584,  1586,   946,  1210,
     680,   946,  1026,  1238,   976,    67,    68,    69,    70,   189,
     197,   206,   209,   252,   259,   316,   341,   348,   350,   360,
     388,   396,   433,   457,   494,   505,   603,   604,   605,   616,
     661,   719,   735,  1103,  1231,  1232,  1181,  1202,  1203,   929,
     930,  1248,   973,   973,  1019,  1026,   946,  1236,  1313,  1181,
    1290,    25,   486,  1181,  1285,  1531,  1284,   930,  1592,   163,
     212,   249,   346,   423,   463,   529,   758,   954,  1025,  1181,
    1322,   783,   930,  1018,   644,  1025,  1033,  1159,   930,  1018,
      26,  1181,  1111,  1018,   930,  1552,   930,  1299,  1025,  1035,
    1036,  1022,  1035,   973,  1022,  1035,   973,  1041,  1035,    25,
      26,   442,   542,  1031,  1092,  1181,  1199,  1201,   123,   331,
     403,   447,   623,   703,   704,   705,   714,   748,  1043,  1045,
    1047,  1049,  1051,  1176,  1177,  1180,   394,   405,   455,   469,
     558,  1406,   694,   695,   984,   985,   986,  1025,  1156,   701,
    1155,   449,   359,   449,   449,   449,   449,   678,     5,   449,
     835,   449,   482,   486,   680,    19,    26,   449,   963,    26,
     449,   449,   644,    26,   644,   680,    18,    19,    20,    25,
      26,    38,    39,   122,   452,   483,   486,   499,   539,   551,
     592,   625,   631,   640,   641,   643,   655,   656,   663,   666,
    1025,  1031,  1487,  1489,  1518,  1520,  1521,  1523,  1524,  1525,
    1547,  1548,  1549,  1550,  1580,  1581,  1585,  1311,   449,  1311,
    1311,  1311,  1311,  1311,  1311,    25,    25,    25,   923,   938,
     449,    25,   938,   449,   449,   449,   449,   449,   449,   776,
     449,   778,   776,   482,   359,   449,   835,   858,   859,   449,
     449,   678,   449,  1025,  1317,  1200,  1307,   112,   113,   142,
     143,   144,   510,   596,   639,  1352,  1353,  1354,  1357,  1360,
    1363,  1364,  1365,  1368,   674,   644,   666,   159,   160,   486,
     674,   644,   666,     8,   679,   482,  1480,   534,  1258,  1199,
     167,   168,   169,   650,   538,   926,   927,   930,  1181,  1206,
    1480,   747,   748,   909,   323,    51,   145,   146,   680,  1255,
     515,     5,   673,   680,   672,   672,  1213,   650,   476,     5,
     611,  1064,   515,   713,  1594,   713,   442,   812,  1181,   601,
     672,  1218,  1219,  1220,   674,    25,  1582,   514,  1587,   385,
    1402,   666,   674,   928,   930,   611,  1579,   928,     8,   608,
    1019,    26,   556,   609,   723,  1011,  1181,  1011,  1011,  1011,
      25,   234,   361,   367,   368,   369,   389,   494,   497,   505,
     540,   575,   594,   595,   605,   610,   649,   681,  1107,  1108,
    1011,  1011,   651,  1104,   748,  1104,  1104,  1012,  1012,  1104,
    1104,    40,    41,  1233,   748,    40,    41,  1234,     5,   476,
       5,   392,   443,     5,   747,   139,   140,   594,   681,  1095,
     716,  1595,   929,   667,   668,   669,   670,  1289,  1531,  1291,
     930,  1279,  1280,  1281,  1292,  1293,   930,   486,   486,   486,
     486,    25,   779,  1025,   486,  1531,   403,   486,   576,    36,
     644,   633,   784,   791,   782,  1025,    25,  1174,  1181,  1275,
       8,  1278,    14,  1025,  1186,  1193,  1194,  1196,  1204,  1205,
    1250,    40,    41,   220,   403,   599,   632,  1328,    33,   247,
     608,  1553,  1554,  1555,  1557,   630,     5,   713,   713,   928,
    1199,  1206,  1091,   476,     5,   208,  1069,   486,  1181,   928,
     486,    26,    26,   123,  1179,    25,  1181,  1535,  1535,  1026,
    1386,  1238,  1019,    37,   176,   278,   286,   292,   294,   305,
     333,   349,   354,   366,   373,   521,   526,   533,   555,   560,
    1375,  1376,  1384,  1393,  1394,  1400,  1401,  1407,  1408,  1418,
    1438,  1442,  1507,  1508,  1538,  1539,  1542,  1543,  1559,   987,
     988,   148,   983,   994,   995,   986,  1157,  1606,  1136,   514,
     889,   852,   674,  1025,   876,    26,   449,   644,   963,   449,
     644,   963,   963,    24,    26,   644,    24,    26,   877,  1524,
    1524,   424,   509,   525,   568,   607,   636,   645,  1490,  1493,
     526,  1523,   486,   486,   486,   486,  1518,  1518,  1518,   486,
     486,   486,   486,  1025,   486,     5,   601,  1447,  1452,   671,
    1025,    18,    19,    20,    21,   149,   150,   151,   152,   153,
     154,  1545,  1493,  1493,   476,     5,   449,   449,   953,   951,
     514,     5,   449,   860,   829,   829,   302,   315,   417,   486,
     531,   547,  1422,  1423,  1428,  1430,   486,  1025,  1369,  1370,
      26,   486,  1025,  1349,  1362,  1430,  1432,   486,  1025,  1359,
     486,  1349,  1355,     5,  1025,    25,  1025,  1025,    25,  1028,
    1184,  1025,    25,  1025,  1025,  1025,  1602,  1480,   650,   486,
     486,   909,  1480,     5,   680,   486,  1579,    25,  1030,  1256,
    1255,  1256,  1531,  1172,   930,   930,   930,  1013,  1014,   486,
    1181,  1211,  1065,  1066,  1067,  1480,   680,  1531,   973,  1595,
    1089,  1181,   811,   679,   930,   409,  1222,   611,  1221,  1583,
     744,  1588,  1589,  1025,    20,  1584,     5,  1576,   671,  1228,
     126,   128,   130,   672,   680,   901,  1199,  1202,   977,    18,
      19,   486,  1105,  1107,  1232,  1181,  1203,  1012,   930,   403,
     650,    26,  1181,    26,  1181,   747,   210,  1288,   449,   441,
    1326,  1291,  1281,     5,   672,  1282,  1593,  1025,    25,   973,
     973,   644,  1017,   677,  1181,   764,  1025,  1025,  1025,   930,
     398,   787,   791,   633,   785,   793,    23,   291,  1161,  1165,
     537,   946,   537,  1276,   930,   513,  1190,   674,     5,  1112,
     601,  1251,  1181,   220,   403,  1556,  1558,   246,  1554,  1054,
    1036,   973,   973,  1046,  1047,  1069,  1069,    48,    49,    50,
      53,    55,    56,   327,   330,   332,   352,   362,   383,   406,
     410,   485,  1068,  1070,  1071,  1099,  1181,  1201,   601,   749,
      26,   456,  1052,   380,  1530,  1530,   195,   196,   492,   601,
    1025,  1439,  1440,  1482,  1480,  1480,  1480,  1377,  1480,  1480,
    1025,  1540,   224,   437,   451,   494,   505,   526,   533,   541,
     563,   640,   646,  1409,  1411,  1412,  1413,  1519,  1480,  1385,
    1409,  1411,  1606,  1606,   442,   996,  1181,   696,   697,   989,
     990,   991,   536,   679,   698,   699,   718,   999,  1000,  1606,
     829,    26,   850,    20,  1025,   449,    26,   449,   963,    26,
     963,    24,    26,   449,   449,    24,    26,   680,  1519,   449,
     452,  1523,  1546,  1585,   417,   531,   640,  1471,  1523,  1526,
    1471,  1471,  1471,  1471,   674,  1526,  1521,   570,  1448,  1449,
    1450,  1480,   581,  1446,  1453,   390,   569,   580,  1395,  1514,
    1025,  1523,  1523,  1523,  1523,   680,   486,   680,  1580,   923,
     449,   449,   850,   859,  1318,  1308,   486,   486,   486,  1366,
    1430,   486,   486,   115,  1367,  1369,     5,  1361,  1362,   121,
     356,   376,   377,   378,   415,   427,   438,   454,   464,   479,
     527,   557,   567,   588,   592,   620,   629,  1472,  1473,  1474,
    1476,  1358,  1359,  1355,  1356,   718,  1353,   674,   644,   449,
     674,   644,   601,  1600,   486,   742,   743,  1025,  1336,   946,
     926,  1025,  1334,   671,  1225,  1255,  1255,   680,     5,     5,
       5,   634,   930,     5,   674,   538,   680,   679,   221,   223,
     327,   330,   813,   816,   817,  1099,   814,   815,  1025,   486,
    1026,   703,   704,  1226,     5,   482,   930,  1480,  1577,  1578,
    1579,   631,   671,  1229,  1025,  1025,  1014,  1015,   564,   973,
     909,     8,     8,   979,    26,    26,  1106,  1107,  1181,   376,
    1243,   123,   923,  1291,   275,  1293,  1299,  1606,     5,     5,
     449,   449,   780,  1025,   449,  1531,   776,   486,   486,   486,
     792,   788,   418,   786,   930,   398,   789,   793,   651,  1101,
    1166,  1162,   420,  1160,  1161,   928,   680,  1187,    20,  1025,
    1195,  1205,    14,   538,  1252,  1253,  1523,  1181,  1585,  1202,
    1606,  1048,  1049,   605,  1024,   601,  1082,  1081,  1080,  1079,
    1084,  1083,  1016,  1085,  1016,  1086,  1078,  1077,  1075,  1074,
    1100,   383,  1071,  1076,   973,    58,    59,    60,    61,    62,
      63,   155,   391,   404,   466,   472,   511,   535,   545,   546,
     551,   561,   583,   586,   587,   591,   648,   659,   750,   751,
    1097,  1098,     5,    26,  1531,   305,  1181,   526,  1512,  1513,
    1531,  1238,  1506,  1508,   157,   157,   650,  1236,  1441,  1442,
     486,  1419,   207,  1453,  1480,   231,   328,  1544,   674,   680,
     486,  1414,  1414,   601,   679,     5,  1509,  1560,   400,   409,
     433,   436,   452,   556,   609,   616,  1019,  1387,  1392,   680,
     679,   998,  1181,     5,   601,   992,   993,   693,   991,   997,
    1025,   997,  1001,  1002,   997,   383,  1000,  1137,   482,   449,
     644,   963,   449,   644,   449,   449,   963,   963,   424,   509,
     525,   568,   607,   636,   645,  1494,  1520,     5,  1493,     5,
     449,     5,  1523,     5,   449,  1523,  1523,  1523,  1523,  1025,
     449,   486,  1450,     5,   671,  1025,  1486,     9,   351,   486,
     498,  1456,  1457,  1458,  1459,  1460,  1464,  1468,  1470,  1523,
     426,  1444,  1454,  1025,  1515,   673,  1471,   390,  1494,    26,
    1494,   482,   516,  1301,  1321,   516,  1262,  1295,   666,  1025,
    1425,  1427,  1480,  1484,  1485,  1429,  1484,  1429,     5,   449,
    1367,  1429,  1456,  1025,   449,  1370,     5,   449,   486,   486,
     486,  1493,  1493,   486,   486,   486,   486,   486,   263,   264,
     265,   456,  1431,  1433,     5,   449,     5,   449,  1025,  1025,
      25,  1025,  1025,    25,  1025,   930,  1025,  1346,  1347,     5,
    1348,  1349,   946,  1143,   674,  1348,   631,  1531,  1531,   930,
     930,  1013,   564,   930,  1598,     5,  1066,    20,  1484,  1531,
     814,   822,   821,   823,  1025,  1029,   824,  1029,   248,   817,
     820,     5,  1069,   674,   930,     8,  1589,   514,   674,     5,
    1531,   631,  1025,  1199,   946,   608,  1390,     5,   449,  1181,
       5,    26,  1181,   384,    25,  1323,   403,   403,   514,   674,
     403,   486,   765,   769,   762,   760,  1606,  1606,   794,   790,
     786,  1102,    25,  1024,  1167,  1181,  1606,   930,   481,   514,
     946,     5,  1055,  1050,  1051,    26,   747,  1025,  1606,  1606,
    1606,  1606,  1606,  1606,     5,  1072,     5,  1073,  1606,  1606,
    1606,  1606,  1105,  1606,  1024,    25,    14,    14,     5,   449,
      26,  1480,  1519,  1500,   650,   650,  1376,  1505,  1506,  1442,
    1420,  1484,   671,  1019,   486,  1380,  1025,  1541,  1540,  1415,
    1484,   518,  1416,  1417,  1482,  1480,  1413,  1520,   103,   104,
     105,   106,   107,   638,  1563,   930,   930,   608,  1388,  1019,
    1416,  1480,     5,  1181,   997,  1606,  1606,     5,  1004,  1005,
    1606,  1606,  1003,  1130,   893,   963,    26,   963,    24,    26,
     963,   963,   486,  1452,  1493,   680,  1493,  1493,   449,  1523,
     449,   449,   449,   449,  1449,  1451,  1449,  1486,  1459,  1518,
    1456,  1523,  1518,     6,     7,     9,    12,    13,    14,    15,
      16,    17,   429,   430,   484,   611,   677,   727,   728,  1467,
    1469,  1445,  1522,  1523,   503,  1443,  1455,   325,  1345,    26,
    1396,  1397,  1398,  1484,  1512,  1515,   449,   847,   131,   132,
     134,   135,   136,   233,   241,   275,   284,   313,   314,   358,
     402,   456,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,  1298,  1302,   194,   569,  1303,  1319,   217,   232,
     233,   241,   275,   284,   313,   358,   402,  1296,  1297,  1309,
    1303,  1485,   514,  1483,   449,     5,   674,     5,   449,   449,
    1430,   449,   449,  1362,    26,  1477,  1477,    26,   680,   486,
     680,    26,  1478,    26,    26,  1478,  1478,    25,  1487,   215,
     315,   353,   417,   431,   531,   547,  1424,  1434,  1435,  1436,
    1437,  1359,  1355,   674,   674,   593,   642,     5,   449,   743,
       5,   449,   928,   449,    20,   449,  1531,     5,   930,   621,
     331,   752,   753,   930,  1069,  1606,  1606,     5,   818,   514,
     674,     5,   819,  1606,   815,   601,    20,  1025,     5,  1025,
    1216,  1588,    20,  1484,  1578,     8,  1531,   447,   713,   928,
    1391,   978,  1107,   722,  1241,   923,     5,   776,  1181,   759,
     741,  1025,  1181,   767,   449,   776,   776,   776,  1606,  1606,
    1105,  1164,    25,  1168,  1181,   626,  1009,  1191,   538,   929,
    1113,  1253,   120,   597,  1056,  1042,  1043,   674,  1016,  1606,
    1016,  1606,   747,    26,  1181,    26,  1181,   751,   449,   486,
    1532,  1520,  1506,  1506,  1498,     5,   449,   526,  1517,  1381,
    1484,   534,  1378,  1517,   680,     5,   449,     5,   601,  1510,
      18,    19,   122,   483,   486,   499,   538,   539,   551,   592,
     631,   643,   655,   656,   663,   666,  1025,  1487,  1518,  1547,
    1549,  1568,  1569,  1570,  1571,  1572,  1573,  1585,  1568,  1568,
    1568,  1484,  1565,  1567,  1564,  1565,  1566,  1561,  1389,   680,
    1181,  1025,  1606,  1606,  1606,  1606,   678,   449,   644,   449,
     449,    26,   449,   680,  1494,   680,   680,     5,   449,   449,
    1457,  1458,  1462,  1524,  1462,   486,  1518,  1462,   486,  1518,
    1462,    10,   306,   444,   446,  1523,     5,  1456,     5,   593,
     642,  1399,  1345,   680,   678,  1299,  1299,  1299,    25,  1299,
    1299,  1299,  1299,  1299,  1299,    25,    25,  1299,  1302,  1181,
    1207,  1208,   673,   502,  1263,    25,    25,    26,    26,    26,
      26,    26,    25,  1181,  1297,  1263,    26,  1424,  1484,    20,
    1025,  1484,  1367,   449,   449,     5,   449,  1494,    26,  1494,
       5,  1475,     5,   449,   449,   449,  1475,  1426,  1480,   486,
    1436,  1367,  1025,  1025,  1347,   677,   731,  1341,  1342,  1343,
    1349,    66,   143,   144,   301,   677,  1337,  1338,  1339,   523,
     908,  1337,     5,   432,  1531,     5,   486,   449,   605,  1096,
    1029,  1606,   744,    20,  1025,  1029,  1606,   973,   930,   482,
    1531,     8,   973,  1202,  1606,    26,  1024,    25,  1324,  1199,
     482,   776,   766,   770,   449,   449,  1606,  1024,   930,  1007,
     482,  1058,  1057,   496,  1044,  1045,    20,  1025,  1533,  1534,
     608,  1516,  1501,  1499,  1484,  1519,   199,  1421,     5,   449,
    1379,  1541,  1484,  1417,  1416,  1516,  1571,  1571,  1570,   486,
     486,   486,   486,   486,   486,   486,  1025,   486,     5,   449,
      18,    19,    20,    21,  1545,   449,     5,   449,     5,    14,
     207,   581,  1562,  1202,  1416,   268,  1138,   889,   963,    24,
      26,   963,   963,   449,  1494,  1494,  1494,  1449,   497,  1461,
    1461,  1465,  1466,  1487,  1585,  1461,  1465,  1461,  1462,  1523,
    1522,  1397,  1494,   860,   593,   642,  1209,     5,  1207,   119,
     193,   255,   257,   273,   281,   285,   310,  1264,  1265,  1320,
    1310,     5,   482,  1483,    26,   449,    26,  1479,   449,    26,
     449,   486,  1456,  1340,  1605,    26,  1343,    26,    26,  1340,
    1345,  1339,  1016,   747,   432,  1531,   930,   754,   623,  1214,
      26,   747,   482,  1096,   449,  1531,   297,   747,   449,   449,
     486,   768,   403,   774,   449,   763,   761,  1163,  1606,   514,
     930,  1606,  1024,     5,   449,  1202,  1452,  1520,  1484,   486,
    1452,   449,  1546,  1471,  1570,  1574,  1471,  1471,  1471,  1471,
     514,   674,  1574,  1569,  1570,  1570,  1570,  1570,  1565,    14,
    1566,  1569,  1019,  1456,   200,   671,  1410,   449,   449,  1463,
    1487,  1527,     5,   449,   449,  1461,     7,  1208,  1266,  1267,
    1181,  1269,  1181,  1268,  1270,  1265,   296,   296,    26,   449,
     680,   449,  1427,   449,   907,  1531,   450,   259,   316,   341,
     350,   388,   396,   487,   657,   751,   755,   756,   486,   674,
     747,  1240,  1325,   771,   449,  1199,   774,   774,   774,  1606,
    1008,  1191,   630,  1093,  1534,  1514,  1452,   538,  1382,  1383,
    1523,  1514,   449,  1570,     5,   449,  1570,  1570,  1570,  1570,
      26,  1025,   449,   486,  1025,   963,   963,  1466,  1523,  1606,
    1606,  1271,  1606,  1272,  1606,  1606,   482,  1494,   449,   295,
     406,   410,   910,   911,   912,  1099,  1011,  1011,  1011,  1011,
    1011,  1011,    25,     5,   449,   930,    20,  1025,  1099,  1244,
    1245,  1246,   774,   776,   774,   298,   482,  1059,   747,     5,
     449,   344,   345,  1502,   449,  1570,   449,   449,   449,   449,
       5,   482,   514,  1568,  1606,  1606,   914,   913,   295,   912,
     915,   756,     5,  1247,   339,  1246,   772,  1606,  1383,    25,
    1025,  1503,  1504,    26,    26,   449,  1606,  1606,  1606,   930,
    1606,   449,  1056,   674,   674,     5,   482,     5,   482,   449,
     773,  1025,  1025,  1504,    26,   220,   403,   775,   674,   482,
    1199,  1025
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
#line 1012 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1015 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1019 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1025 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1030 "fgl.yacc"
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
#line 1042 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1047 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	//sprintf($<str>$, "A4GL_unregister_func(\"%s\",%s%s);\n", $<str>1, (char *)get_namespace($<str>1), $<str>1);
	sprintf(yyval.str, "A4GL_unregister_func(\"%s\");\n", yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1066 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1067 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1068 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1069 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1070 "fgl.yacc"
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
#line 1081 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1087 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1088 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1089 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1090 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1091 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1096 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1097 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1108 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1111 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1114 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1114 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1121 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1122 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1139 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1140 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1141 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1142 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1143 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1144 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1151 "fgl.yacc"
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
#line 1162 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1166 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1167 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1171 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1177 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1179 "fgl.yacc"
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
#line 1190 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1192 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1194 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1196 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1200 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1202 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1263 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1267 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1271 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1278 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1281 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1285 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1289 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1298 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1304 "fgl.yacc"
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
#line 1313 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1318 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1324 "fgl.yacc"
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
#line 1333 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 77:
#line 1340 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 78:
#line 1345 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 79:
#line 1349 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 80:
#line 1357 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 81:
#line 1361 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1365 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1367 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1373 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 85:
#line 1378 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 86:
#line 1381 "fgl.yacc"
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
#line 1397 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 88:
#line 1404 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 89:
#line 1408 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 90:
#line 1412 "fgl.yacc"
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
#line 1434 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 92:
#line 1434 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 93:
#line 1438 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 94:
#line 1439 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 95:
#line 1440 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 96:
#line 1445 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 97:
#line 1448 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 98:
#line 1454 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 99:
#line 1457 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 101:
#line 1466 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 103:
#line 1470 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 104:
#line 1476 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 105:
#line 1479 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 106:
#line 1494 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 107:
#line 1504 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1510 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 109:
#line 1519 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 114:
#line 1532 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 116:
#line 1535 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 117:
#line 1537 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 119:
#line 1543 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 120:
#line 1545 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 121:
#line 1550 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 122:
#line 1555 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 123:
#line 1561 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 124:
#line 1565 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 125:
#line 1574 "fgl.yacc"
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
#line 1598 "fgl.yacc"
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
#line 1606 "fgl.yacc"
    { 
		pop_record();in_record--;
		read_class(yyvsp[-2].str); 
		print_variables(); 
		class_set_parent();
		}
    break;

  case 128:
#line 1612 "fgl.yacc"
    {
		class_cnt++; 
		CLASS_print_reflector();
		dump_class();
		}
    break;

  case 129:
#line 1622 "fgl.yacc"
    {
	static char buff[256];
		strcpy(buff,"default_object");
		CLASS_set_parent_name(buff);
		strcpy(yyval.str,buff);
	}
    break;

  case 130:
#line 1627 "fgl.yacc"
    {
		CLASS_set_parent_name(yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 134:
#line 1650 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 135:
#line 1653 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 136:
#line 1656 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 137:
#line 1659 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 138:
#line 1662 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 139:
#line 1665 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 145:
#line 1687 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 148:
#line 1696 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 149:
#line 1715 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 150:
#line 1720 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 151:
#line 1723 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 152:
#line 1732 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 153:
#line 1738 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 158:
#line 1753 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 159:
#line 1757 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 160:
#line 1762 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 163:
#line 1772 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 164:
#line 1772 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 165:
#line 1773 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 166:
#line 1773 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 167:
#line 1774 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 168:
#line 1774 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 169:
#line 1775 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 170:
#line 1775 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 171:
#line 1776 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 172:
#line 1776 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 173:
#line 1784 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 174:
#line 1788 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 175:
#line 1794 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 176:
#line 1798 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 177:
#line 1813 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 178:
#line 1816 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 179:
#line 1819 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 180:
#line 1822 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 181:
#line 1825 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 182:
#line 1828 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 183:
#line 1837 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 184:
#line 1845 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 185:
#line 1850 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 186:
#line 1863 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 187:
#line 1867 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 188:
#line 1882 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 189:
#line 1883 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 192:
#line 1891 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 193:
#line 1891 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 198:
#line 1900 "fgl.yacc"
    {in_define=1;}
    break;

  case 199:
#line 1900 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 200:
#line 1909 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 201:
#line 1910 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 202:
#line 1911 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 203:
#line 1914 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 205:
#line 1919 "fgl.yacc"
    { }
    break;

  case 206:
#line 1919 "fgl.yacc"
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
#line 1936 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 211:
#line 1940 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 216:
#line 1955 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 217:
#line 1956 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 218:
#line 1957 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 219:
#line 1958 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 220:
#line 1963 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 222:
#line 1969 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 224:
#line 1978 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 225:
#line 1982 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 231:
#line 1998 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 232:
#line 2000 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 233:
#line 2001 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 236:
#line 2010 "fgl.yacc"
    {
		sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 237:
#line 2012 "fgl.yacc"
    {
		sprintf(yyval.str,"%s@%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 238:
#line 2017 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 239:
#line 2017 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 240:
#line 2018 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 241:
#line 2019 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 242:
#line 2022 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 243:
#line 2024 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 245:
#line 2034 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 250:
#line 2049 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 251:
#line 2049 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 255:
#line 2055 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 256:
#line 2056 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 257:
#line 2057 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 258:
#line 2058 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 259:
#line 2059 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 260:
#line 2060 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 261:
#line 2061 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 262:
#line 2062 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 263:
#line 2063 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 264:
#line 2064 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 265:
#line 2067 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 266:
#line 2068 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 267:
#line 2069 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 268:
#line 2070 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 269:
#line 2074 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 270:
#line 2079 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 271:
#line 2084 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 272:
#line 2088 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 273:
#line 2091 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 274:
#line 2095 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 276:
#line 2096 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 278:
#line 2097 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 280:
#line 2098 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 281:
#line 2099 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 282:
#line 2100 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 283:
#line 2101 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 284:
#line 2102 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 285:
#line 2103 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 286:
#line 2106 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 287:
#line 2107 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 288:
#line 2108 "fgl.yacc"
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
#line 2143 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 292:
#line 2148 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2150 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 294:
#line 2152 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 295:
#line 2157 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 296:
#line 2161 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 297:
#line 2161 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 298:
#line 2165 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 299:
#line 2166 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 300:
#line 2167 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 301:
#line 2168 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 302:
#line 2169 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 303:
#line 2170 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 304:
#line 2172 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 305:
#line 2177 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 306:
#line 2177 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 307:
#line 2180 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 308:
#line 2182 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 309:
#line 2188 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 310:
#line 2190 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 311:
#line 2196 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 312:
#line 2204 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 313:
#line 2204 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 314:
#line 2207 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 315:
#line 2208 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 316:
#line 2209 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 317:
#line 2210 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 318:
#line 2211 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 319:
#line 2212 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 320:
#line 2214 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 324:
#line 2235 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 328:
#line 2244 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 329:
#line 2246 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 330:
#line 2247 "fgl.yacc"
    { dim_push_type("varchar",yyvsp[-1].str,0); }
    break;

  case 331:
#line 2248 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 332:
#line 2252 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 333:
#line 2253 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 334:
#line 2254 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 335:
#line 2255 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 336:
#line 2260 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 337:
#line 2267 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 338:
#line 2272 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 339:
#line 2274 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 340:
#line 2276 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 341:
#line 2277 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 342:
#line 2278 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 343:
#line 2279 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 344:
#line 2280 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 345:
#line 2281 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 346:
#line 2282 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 347:
#line 2285 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 348:
#line 2287 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 349:
#line 2293 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 350:
#line 2301 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 352:
#line 2309 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 353:
#line 2313 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 354:
#line 2321 "fgl.yacc"
    {dim_push_record();}
    break;

  case 355:
#line 2322 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 356:
#line 2323 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 357:
#line 2324 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 363:
#line 2343 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 364:
#line 2355 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 365:
#line 2359 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 366:
#line 2362 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 367:
#line 2365 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 368:
#line 2366 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 369:
#line 2367 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 370:
#line 2368 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 371:
#line 2369 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 372:
#line 2375 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 373:
#line 2382 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 374:
#line 2387 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 375:
#line 2392 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 376:
#line 2397 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 377:
#line 2401 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 378:
#line 2410 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 379:
#line 2412 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 380:
#line 2417 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 386:
#line 2429 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 387:
#line 2433 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 388:
#line 2436 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 389:
#line 2440 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 390:
#line 2443 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 391:
#line 2447 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 392:
#line 2454 "fgl.yacc"
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
#line 2472 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 394:
#line 2478 "fgl.yacc"
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
#line 2502 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 396:
#line 2505 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 397:
#line 2520 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 398:
#line 2523 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 399:
#line 2537 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 400:
#line 2539 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 401:
#line 2541 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 402:
#line 2543 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 403:
#line 2545 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 404:
#line 2547 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 405:
#line 2548 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 406:
#line 2555 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 407:
#line 2557 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 408:
#line 2561 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 409:
#line 2563 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 410:
#line 2565 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 411:
#line 2567 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 412:
#line 2569 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 413:
#line 2571 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 414:
#line 2573 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 415:
#line 2579 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 419:
#line 2598 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 422:
#line 2604 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 423:
#line 2608 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 424:
#line 2613 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 428:
#line 2623 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 429:
#line 2624 "fgl.yacc"
    {inc_counter();}
    break;

  case 435:
#line 2630 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 436:
#line 2637 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 437:
#line 2637 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 439:
#line 2642 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 440:
#line 2646 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 441:
#line 2652 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 442:
#line 2660 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 443:
#line 2666 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 444:
#line 2675 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 445:
#line 2677 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 446:
#line 2684 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 447:
#line 2705 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2710 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 449:
#line 2715 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 450:
#line 2719 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 451:
#line 2721 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 452:
#line 2724 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 453:
#line 2742 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 454:
#line 2748 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2754 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 458:
#line 2764 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 459:
#line 2770 "fgl.yacc"
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
#line 2842 "fgl.yacc"
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
#line 2853 "fgl.yacc"
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
#line 2861 "fgl.yacc"
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
#line 2869 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 464:
#line 2869 "fgl.yacc"
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
#line 2885 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 466:
#line 2889 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 467:
#line 2895 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 468:
#line 2898 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 469:
#line 2906 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 470:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 471:
#line 2913 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 472:
#line 2919 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 473:
#line 2929 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 474:
#line 2934 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 475:
#line 2941 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 476:
#line 2944 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 477:
#line 2947 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 478:
#line 2952 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 479:
#line 2959 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 480:
#line 2964 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 481:
#line 2969 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 482:
#line 2974 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 483:
#line 2985 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 484:
#line 2993 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 485:
#line 3001 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 486:
#line 3006 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 487:
#line 3010 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 488:
#line 3015 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 489:
#line 3019 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 490:
#line 3023 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 491:
#line 3029 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 492:
#line 3032 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 493:
#line 3036 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 494:
#line 3040 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 495:
#line 3044 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 496:
#line 3048 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 497:
#line 3052 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 498:
#line 3059 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 499:
#line 3069 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 500:
#line 3074 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 501:
#line 3080 "fgl.yacc"
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
#line 3090 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 503:
#line 3095 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 504:
#line 3098 "fgl.yacc"
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
#line 3109 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 506:
#line 3114 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 507:
#line 3117 "fgl.yacc"
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
#line 3135 "fgl.yacc"
    {chk4var=1;}
    break;

  case 509:
#line 3135 "fgl.yacc"
    {chk4var=0;}
    break;

  case 510:
#line 3135 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 511:
#line 3138 "fgl.yacc"
    {chk4var=1;}
    break;

  case 512:
#line 3138 "fgl.yacc"
    {chk4var=0;}
    break;

  case 513:
#line 3138 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 514:
#line 3142 "fgl.yacc"
    {chk4var=1;}
    break;

  case 515:
#line 3142 "fgl.yacc"
    {chk4var=0;}
    break;

  case 516:
#line 3142 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 517:
#line 3146 "fgl.yacc"
    {chk4var=1;}
    break;

  case 518:
#line 3146 "fgl.yacc"
    {chk4var=0;}
    break;

  case 519:
#line 3146 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 520:
#line 3150 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3156 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3162 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3168 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3176 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3182 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 526:
#line 3190 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 527:
#line 3196 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 528:
#line 3205 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 529:
#line 3211 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 530:
#line 3218 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 531:
#line 3225 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 532:
#line 3234 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 533:
#line 3240 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 534:
#line 3246 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 535:
#line 3253 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 536:
#line 3259 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 537:
#line 3265 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 538:
#line 3271 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 539:
#line 3279 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 540:
#line 3285 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 541:
#line 3291 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 542:
#line 3300 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 543:
#line 3306 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 544:
#line 3312 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 545:
#line 3322 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 546:
#line 3323 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 549:
#line 3331 "fgl.yacc"
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
#line 3342 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 551:
#line 3343 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 552:
#line 3349 "fgl.yacc"
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
#line 3360 "fgl.yacc"
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
#line 3370 "fgl.yacc"
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
#line 3383 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 558:
#line 3388 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 559:
#line 3395 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 560:
#line 3399 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 561:
#line 3402 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 562:
#line 3405 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 563:
#line 3411 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 564:
#line 3414 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 565:
#line 3417 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 566:
#line 3434 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 567:
#line 3437 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 568:
#line 3443 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 569:
#line 3444 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 570:
#line 3445 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 572:
#line 3450 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 573:
#line 3451 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 574:
#line 3452 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 575:
#line 3453 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 576:
#line 3455 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 577:
#line 3456 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 578:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 579:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 580:
#line 3460 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 582:
#line 3466 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 583:
#line 3470 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 584:
#line 3474 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 585:
#line 3479 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 586:
#line 3483 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 587:
#line 3498 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 588:
#line 3502 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 589:
#line 3508 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 590:
#line 3512 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 591:
#line 3521 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 592:
#line 3522 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 593:
#line 3534 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 594:
#line 3540 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 595:
#line 3548 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 602:
#line 3565 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 603:
#line 3567 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 604:
#line 3570 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 605:
#line 3572 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 610:
#line 3586 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 611:
#line 3588 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 612:
#line 3591 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 613:
#line 3593 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 626:
#line 3624 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 627:
#line 3626 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 628:
#line 3629 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 629:
#line 3631 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 630:
#line 3634 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 631:
#line 3636 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 632:
#line 3639 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 633:
#line 3641 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 634:
#line 3644 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 635:
#line 3646 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 636:
#line 3660 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 637:
#line 3664 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 638:
#line 3665 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 639:
#line 3672 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 641:
#line 3690 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 642:
#line 3706 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 643:
#line 3707 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 644:
#line 3708 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 645:
#line 3709 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 646:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 647:
#line 3711 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 648:
#line 3712 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 652:
#line 3720 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 654:
#line 3726 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 655:
#line 3729 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 656:
#line 3734 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 657:
#line 3739 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 658:
#line 3742 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 659:
#line 3747 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 660:
#line 3752 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 661:
#line 3757 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 662:
#line 3764 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 663:
#line 3765 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 664:
#line 3772 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 665:
#line 3779 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 666:
#line 3781 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 667:
#line 3787 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3792 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 669:
#line 3797 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 670:
#line 3802 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 671:
#line 3802 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 672:
#line 3805 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 673:
#line 3811 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 674:
#line 3816 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 675:
#line 3820 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 678:
#line 3828 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 679:
#line 3831 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 680:
#line 3834 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 681:
#line 3839 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 682:
#line 3844 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 683:
#line 3849 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 684:
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

  case 686:
#line 3867 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 687:
#line 3929 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 689:
#line 3938 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 690:
#line 3947 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 692:
#line 3954 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 693:
#line 3957 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 694:
#line 3963 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 695:
#line 3969 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 696:
#line 3973 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 697:
#line 3977 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 698:
#line 3983 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 699:
#line 3987 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 700:
#line 3991 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 701:
#line 3996 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 702:
#line 4001 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 721:
#line 4042 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 722:
#line 4049 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 723:
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

  case 725:
#line 4070 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 727:
#line 4073 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 728:
#line 4075 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 729:
#line 4078 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 730:
#line 4082 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 731:
#line 4085 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 732:
#line 4092 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 733:
#line 4097 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 734:
#line 4108 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 735:
#line 4109 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 736:
#line 4112 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 738:
#line 4118 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 739:
#line 4122 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 740:
#line 4123 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 741:
#line 4127 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 745:
#line 4142 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 746:
#line 4144 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 749:
#line 4153 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 750:
#line 4156 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 751:
#line 4160 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 752:
#line 4163 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 753:
#line 4166 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 754:
#line 4169 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 755:
#line 4172 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 756:
#line 4176 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 757:
#line 4179 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 758:
#line 4182 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 759:
#line 4185 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 760:
#line 4188 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 761:
#line 4191 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 762:
#line 4194 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 763:
#line 4197 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 764:
#line 4200 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 765:
#line 4201 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 766:
#line 4201 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 767:
#line 4202 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 768:
#line 4202 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 769:
#line 4203 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 770:
#line 4203 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 771:
#line 4204 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 772:
#line 4207 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 773:
#line 4208 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 774:
#line 4211 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 775:
#line 4219 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 776:
#line 4223 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 777:
#line 4229 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 778:
#line 4233 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 779:
#line 4238 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 780:
#line 4243 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 781:
#line 4248 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 782:
#line 4249 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 783:
#line 4250 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 784:
#line 4254 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 785:
#line 4258 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 786:
#line 4267 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 787:
#line 4272 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 788:
#line 4276 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 789:
#line 4283 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 790:
#line 4292 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 791:
#line 4298 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 792:
#line 4299 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 793:
#line 4300 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 794:
#line 4301 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 795:
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

  case 796:
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

  case 797:
#line 4326 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 799:
#line 4329 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 800:
#line 4336 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 801:
#line 4337 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4338 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4339 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 804:
#line 4340 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 805:
#line 4341 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 806:
#line 4342 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 807:
#line 4343 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 808:
#line 4344 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 809:
#line 4349 "fgl.yacc"
    {iskey=1;}
    break;

  case 810:
#line 4349 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 811:
#line 4351 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 812:
#line 4354 "fgl.yacc"
    {iskey=1;}
    break;

  case 813:
#line 4354 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 814:
#line 4356 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 815:
#line 4360 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 816:
#line 4363 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 817:
#line 4364 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 819:
#line 4367 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 825:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 826:
#line 4380 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 827:
#line 4381 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 828:
#line 4382 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 829:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 830:
#line 4384 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 831:
#line 4385 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 832:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 833:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 834:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 835:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 836:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 837:
#line 4391 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 838:
#line 4392 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 839:
#line 4396 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 840:
#line 4414 "fgl.yacc"
    {chk4var=1;}
    break;

  case 841:
#line 4414 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 842:
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

  case 843:
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

  case 845:
#line 4459 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 846:
#line 4465 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 847:
#line 4471 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 848:
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

  case 849:
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

  case 853:
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

  case 856:
#line 4537 "fgl.yacc"
    {
	}
    break;

  case 866:
#line 4563 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 870:
#line 4571 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 884:
#line 4595 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 885:
#line 4596 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 886:
#line 4604 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 887:
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

  case 888:
#line 4626 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 889:
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

  case 891:
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

  case 892:
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

  case 893:
#line 4671 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 894:
#line 4678 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 895:
#line 4685 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 896:
#line 4691 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 897:
#line 4691 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 898:
#line 4696 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 899:
#line 4702 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 900:
#line 4710 "fgl.yacc"
    {
}
    break;

  case 904:
#line 4722 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 906:
#line 4730 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 907:
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

  case 910:
#line 4756 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 911:
#line 4762 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 912:
#line 4766 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 915:
#line 4778 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 916:
#line 4781 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 917:
#line 4785 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 918:
#line 4788 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 919:
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

  case 920:
#line 4808 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 921:
#line 4814 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 922:
#line 4825 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 923:
#line 4829 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 924:
#line 4836 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 925:
#line 4843 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 926:
#line 4849 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 927:
#line 4854 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 930:
#line 4861 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 931:
#line 4862 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 932:
#line 4864 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 933:
#line 4865 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 934:
#line 4868 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 935:
#line 4869 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 936:
#line 4870 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 937:
#line 4872 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 938:
#line 4877 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 939:
#line 4882 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 940:
#line 4889 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 944:
#line 4896 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 945:
#line 4898 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 946:
#line 4900 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 948:
#line 4910 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 949:
#line 4913 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 950:
#line 4916 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 957:
#line 4932 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 958:
#line 4937 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 959:
#line 4937 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 960:
#line 4940 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 961:
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

  case 963:
#line 5025 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 965:
#line 5032 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 966:
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

  case 967:
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

  case 971:
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

  case 972:
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

  case 977:
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

  case 978:
#line 5229 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 979:
#line 5234 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 980:
#line 5242 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 981:
#line 5247 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 982:
#line 5255 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 983:
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

  case 984:
#line 5293 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 985:
#line 5296 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 986:
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

  case 987:
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

  case 992:
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

  case 993:
#line 5444 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 995:
#line 5453 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 996:
#line 5458 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 997:
#line 5469 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 998:
#line 5476 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1000:
#line 5484 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1001:
#line 5487 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1002:
#line 5488 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1004:
#line 5490 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1005:
#line 5491 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1006:
#line 5494 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1007:
#line 5497 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1008:
#line 5503 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1009:
#line 5506 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1010:
#line 5510 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1011:
#line 5515 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1012:
#line 5523 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1013:
#line 5528 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1014:
#line 5535 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1015:
#line 5537 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1020:
#line 5565 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1021:
#line 5572 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1022:
#line 5579 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1023:
#line 5582 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1024:
#line 5596 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1029:
#line 5613 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1030:
#line 5618 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1031:
#line 5624 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1033:
#line 5631 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1034:
#line 5636 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1035:
#line 5639 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1036:
#line 5640 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1037:
#line 5643 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1038:
#line 5644 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1040:
#line 5648 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1041:
#line 5653 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1042:
#line 5660 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1043:
#line 5663 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1044:
#line 5669 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1045:
#line 5671 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1046:
#line 5673 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1047:
#line 5675 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1048:
#line 5678 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1049:
#line 5678 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1050:
#line 5679 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1051:
#line 5684 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1052:
#line 5692 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1053:
#line 5693 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1054:
#line 5698 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1055:
#line 5700 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1056:
#line 5702 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1060:
#line 5720 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1061:
#line 5721 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1062:
#line 5722 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1063:
#line 5723 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1064:
#line 5724 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1065:
#line 5725 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1066:
#line 5726 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1067:
#line 5727 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1068:
#line 5728 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5729 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1070:
#line 5730 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1071:
#line 5731 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1072:
#line 5732 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1073:
#line 5733 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1074:
#line 5734 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1075:
#line 5735 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1076:
#line 5736 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1077:
#line 5737 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1078:
#line 5738 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1079:
#line 5739 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1080:
#line 5740 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1081:
#line 5741 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1082:
#line 5742 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1083:
#line 5743 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1084:
#line 5744 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1085:
#line 5745 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1086:
#line 5746 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1087:
#line 5747 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1088:
#line 5751 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1089:
#line 5752 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1090:
#line 5756 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1091:
#line 5757 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1092:
#line 5772 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1095:
#line 5781 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1096:
#line 5785 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1097:
#line 5789 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1098:
#line 5793 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1099:
#line 5797 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1101:
#line 5817 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1102:
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

  case 1103:
#line 5835 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1104:
#line 5836 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1105:
#line 5840 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1106:
#line 5845 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1107:
#line 5846 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1108:
#line 5850 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1112:
#line 5856 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1113:
#line 5859 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1115:
#line 5874 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1116:
#line 5878 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1117:
#line 5884 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1118:
#line 5885 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1119:
#line 5890 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1120:
#line 5891 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1121:
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

  case 1123:
#line 5921 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1124:
#line 5925 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1125:
#line 5929 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1126:
#line 5933 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1127:
#line 5940 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1128:
#line 5941 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1134:
#line 5953 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1135:
#line 5959 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1136:
#line 5967 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1137:
#line 5973 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1138:
#line 5975 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1142:
#line 5985 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1143:
#line 5985 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1144:
#line 5990 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1145:
#line 5994 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1146:
#line 5999 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1147:
#line 5999 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1148:
#line 6003 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1149:
#line 6003 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1150:
#line 6004 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1151:
#line 6004 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1152:
#line 6005 "fgl.yacc"
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
#line 6018 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1154:
#line 6019 "fgl.yacc"
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
#line 6035 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1162:
#line 6047 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1163:
#line 6047 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1164:
#line 6053 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1165:
#line 6053 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1166:
#line 6056 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1167:
#line 6056 "fgl.yacc"
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
#line 6072 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1169:
#line 6073 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1170:
#line 6074 "fgl.yacc"
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
#line 6083 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1172:
#line 6095 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1178:
#line 6106 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1179:
#line 6111 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1180:
#line 6111 "fgl.yacc"
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
#line 6135 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1183:
#line 6141 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1184:
#line 6146 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1185:
#line 6152 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1186:
#line 6153 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1187:
#line 6154 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1188:
#line 6158 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1189:
#line 6159 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1190:
#line 6160 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1191:
#line 6161 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1192:
#line 6165 "fgl.yacc"
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
#line 6175 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1194:
#line 6177 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1195:
#line 6182 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1196:
#line 6185 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1197:
#line 6190 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1198:
#line 6197 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1199:
#line 6204 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1200:
#line 6211 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1201:
#line 6220 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1202:
#line 6227 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1203:
#line 6234 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1204:
#line 6241 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1205:
#line 6248 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1210:
#line 6261 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1211:
#line 6262 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1212:
#line 6263 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1213:
#line 6264 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1214:
#line 6265 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1215:
#line 6266 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1216:
#line 6267 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1217:
#line 6268 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1218:
#line 6269 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1219:
#line 6270 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1222:
#line 6276 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1223:
#line 6277 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1224:
#line 6278 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1225:
#line 6279 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1230:
#line 6288 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1231:
#line 6289 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1232:
#line 6290 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1233:
#line 6291 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1234:
#line 6292 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1235:
#line 6293 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1236:
#line 6294 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1237:
#line 6295 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1238:
#line 6297 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1239:
#line 6298 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1240:
#line 6299 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1241:
#line 6300 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1242:
#line 6302 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1243:
#line 6303 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1244:
#line 6304 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1245:
#line 6305 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1249:
#line 6310 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1250:
#line 6311 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1254:
#line 6318 "fgl.yacc"
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
#line 6327 "fgl.yacc"
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
#line 6336 "fgl.yacc"
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
#line 6349 "fgl.yacc"
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
#line 6360 "fgl.yacc"
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
#line 6371 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1260:
#line 6375 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1261:
#line 6379 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1262:
#line 6385 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1263:
#line 6390 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1264:
#line 6398 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1265:
#line 6401 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1266:
#line 6410 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1267:
#line 6421 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1269:
#line 6428 "fgl.yacc"
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
#line 6438 "fgl.yacc"
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
#line 6448 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1272:
#line 6451 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1273:
#line 6455 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1274:
#line 6463 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1275:
#line 6466 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1276:
#line 6472 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1277:
#line 6476 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1278:
#line 6480 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1279:
#line 6484 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1280:
#line 6488 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1281:
#line 6494 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1282:
#line 6495 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1283:
#line 6496 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1284:
#line 6497 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1285:
#line 6502 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1286:
#line 6503 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1287:
#line 6504 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1288:
#line 6505 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1289:
#line 6506 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1290:
#line 6507 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1291:
#line 6508 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1292:
#line 6509 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1293:
#line 6513 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1294:
#line 6514 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1295:
#line 6517 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1296:
#line 6522 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1297:
#line 6529 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1298:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 6531 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6536 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1301:
#line 6537 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1302:
#line 6543 "fgl.yacc"
    {insql=1;}
    break;

  case 1303:
#line 6543 "fgl.yacc"
    {insql=0;}
    break;

  case 1304:
#line 6543 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1305:
#line 6548 "fgl.yacc"
    {insql=1;}
    break;

  case 1306:
#line 6548 "fgl.yacc"
    {insql=0;}
    break;

  case 1307:
#line 6548 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1308:
#line 6556 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1309:
#line 6557 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1311:
#line 6562 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1312:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1313:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1314:
#line 6569 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1315:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1316:
#line 6571 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1318:
#line 6576 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1319:
#line 6576 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1321:
#line 6580 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1322:
#line 6584 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1323:
#line 6585 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1324:
#line 6588 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6589 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1326:
#line 6592 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1327:
#line 6595 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1328:
#line 6598 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1329:
#line 6604 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1330:
#line 6606 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1332:
#line 6619 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1333:
#line 6623 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1334:
#line 6624 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1336:
#line 6629 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1337:
#line 6632 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1338:
#line 6638 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1339:
#line 6641 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1340:
#line 6649 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6656 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1343:
#line 6660 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1344:
#line 6664 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1345:
#line 6670 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1346:
#line 6673 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1347:
#line 6682 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1348:
#line 6685 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1349:
#line 6688 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1350:
#line 6691 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1351:
#line 6694 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1352:
#line 6697 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1353:
#line 6700 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1354:
#line 6707 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1355:
#line 6710 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1356:
#line 6717 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1357:
#line 6720 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1358:
#line 6726 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1359:
#line 6729 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1360:
#line 6736 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1361:
#line 6739 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1363:
#line 6747 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1365:
#line 6756 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1366:
#line 6759 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1367:
#line 6765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1368:
#line 6768 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1369:
#line 6774 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1370:
#line 6781 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1371:
#line 6782 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1372:
#line 6786 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1373:
#line 6796 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1374:
#line 6799 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1375:
#line 6805 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1376:
#line 6807 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1377:
#line 6812 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6813 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6818 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1380:
#line 6819 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1381:
#line 6825 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1382:
#line 6826 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6853 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6859 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1393:
#line 6862 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1394:
#line 6865 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1395:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1397:
#line 6877 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1399:
#line 6888 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1400:
#line 6902 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1401:
#line 6911 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1402:
#line 6911 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1403:
#line 6916 "fgl.yacc"
    {insql=1;}
    break;

  case 1404:
#line 6916 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1405:
#line 6921 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1406:
#line 6924 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1407:
#line 6926 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6933 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6937 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1411:
#line 6941 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1412:
#line 6948 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1413:
#line 6951 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1414:
#line 6958 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1415:
#line 6962 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1416:
#line 6968 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1417:
#line 6973 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1418:
#line 6977 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1419:
#line 6983 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1420:
#line 6986 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1421:
#line 6992 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1422:
#line 6999 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1423:
#line 7003 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1424:
#line 7008 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1425:
#line 7018 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1426:
#line 7021 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1427:
#line 7023 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1428:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1429:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1430:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1431:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_RELATIVE);}
    break;

  case 1432:
#line 7033 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_ABSOLUTE);}
    break;

  case 1433:
#line 7039 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1434:
#line 7049 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1435:
#line 7056 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7062 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7065 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7072 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1444:
#line 7077 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1445:
#line 7082 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1446:
#line 7089 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1447:
#line 7090 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1448:
#line 7098 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1449:
#line 7109 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1450:
#line 7110 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1451:
#line 7111 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1452:
#line 7114 "fgl.yacc"
    {insql=1;}
    break;

  case 1453:
#line 7114 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1454:
#line 7119 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1455:
#line 7124 "fgl.yacc"
    {
			print_exec_sql(yyvsp[0].sql_string);
			printf("Warning: Informix specific SQL @ line %d\n",yylineno);
			strcpy(yyval.str,"InfxSpecificSql");
	}
    break;

  case 1456:
#line 7129 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1458:
#line 7135 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1460:
#line 7139 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1461:
#line 7144 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1462:
#line 7149 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1463:
#line 7153 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1465:
#line 7159 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1466:
#line 7163 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1467:
#line 7170 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7171 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7172 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7173 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1474:
#line 7183 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7184 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1476:
#line 7185 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7189 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1478:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1481:
#line 7197 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7200 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1485:
#line 7203 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7208 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1489:
#line 7210 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7216 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7222 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1496:
#line 7232 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1497:
#line 7237 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1498:
#line 7239 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7245 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7248 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1503:
#line 7254 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1504:
#line 7262 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7267 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7277 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 7283 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7288 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1512:
#line 7291 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1513:
#line 7296 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 7302 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7307 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1517:
#line 7310 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1518:
#line 7313 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1519:
#line 7320 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1520:
#line 7321 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1521:
#line 7322 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1522:
#line 7324 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1523:
#line 7337 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1524:
#line 7342 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1526:
#line 7346 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1527:
#line 7348 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1528:
#line 7355 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1529:
#line 7358 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1530:
#line 7364 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1531:
#line 7372 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1532:
#line 7376 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1533:
#line 7380 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1534:
#line 7384 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1535:
#line 7389 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1536:
#line 7392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1537:
#line 7395 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1538:
#line 7403 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1539:
#line 7410 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1542:
#line 7419 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7425 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1544:
#line 7428 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1545:
#line 7439 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1546:
#line 7446 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1547:
#line 7452 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1548:
#line 7455 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1549:
#line 7462 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1550:
#line 7469 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1552:
#line 7476 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1553:
#line 7482 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1554:
#line 7483 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1555:
#line 7484 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1557:
#line 7488 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1558:
#line 7495 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1560:
#line 7502 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1561:
#line 7509 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1562:
#line 7514 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1563:
#line 7515 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1564:
#line 7518 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1565:
#line 7521 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1566:
#line 7526 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1567:
#line 7527 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1568:
#line 7532 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1569:
#line 7535 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1570:
#line 7541 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1571:
#line 7544 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1572:
#line 7550 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1573:
#line 7553 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1574:
#line 7559 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1575:
#line 7562 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1576:
#line 7569 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1577:
#line 7570 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1578:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1579:
#line 7600 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1580:
#line 7604 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1582:
#line 7617 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1583:
#line 7620 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1584:
#line 7623 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1585:
#line 7626 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1587:
#line 7634 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1588:
#line 7637 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1590:
#line 7643 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1592:
#line 7649 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1593:
#line 7652 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1594:
#line 7655 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1595:
#line 7658 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1596:
#line 7661 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1597:
#line 7664 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1598:
#line 7667 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1599:
#line 7670 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1600:
#line 7675 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1602:
#line 7682 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1606:
#line 7688 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1607:
#line 7689 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1608:
#line 7694 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1609:
#line 7697 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7701 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7707 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1612:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1613:
#line 7709 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1614:
#line 7710 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1619:
#line 7730 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1621:
#line 7734 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1622:
#line 7735 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1624:
#line 7738 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1625:
#line 7739 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1626:
#line 7748 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1633:
#line 7762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1634:
#line 7764 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1635:
#line 7766 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1637:
#line 7769 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1639:
#line 7772 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1643:
#line 7777 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1644:
#line 7779 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1645:
#line 7782 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1646:
#line 7783 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1647:
#line 7790 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1651:
#line 7795 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1655:
#line 7811 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1656:
#line 7818 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1657:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1658:
#line 7823 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1659:
#line 7824 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1660:
#line 7832 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1661:
#line 7833 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1662:
#line 7834 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1663:
#line 7845 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1664:
#line 7852 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1665:
#line 7857 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1666:
#line 7858 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1667:
#line 7859 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1668:
#line 7867 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1669:
#line 7868 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1670:
#line 7869 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1672:
#line 7895 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1673:
#line 7896 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1674:
#line 7897 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1675:
#line 7901 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1676:
#line 7904 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1677:
#line 7910 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1678:
#line 7915 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1679:
#line 7920 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1681:
#line 7931 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1685:
#line 7949 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1686:
#line 7952 "fgl.yacc"
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
#line 7965 "fgl.yacc"
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
#line 7980 "fgl.yacc"
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
#line 7992 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1690:
#line 7994 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1691:
#line 7997 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1692:
#line 7997 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1693:
#line 7997 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1694:
#line 7997 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1695:
#line 7997 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1696:
#line 7997 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1697:
#line 7998 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1698:
#line 8001 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1713:
#line 8019 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1714:
#line 8022 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1715:
#line 8023 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1716:
#line 8024 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1717:
#line 8028 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1718:
#line 8036 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1719:
#line 8036 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1720:
#line 8042 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1721:
#line 8042 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1722:
#line 8049 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1723:
#line 8049 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1724:
#line 8055 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1725:
#line 8055 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1726:
#line 8063 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1727:
#line 8064 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1728:
#line 8065 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1729:
#line 8068 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1730:
#line 8068 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1732:
#line 8072 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1733:
#line 8073 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1734:
#line 8084 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1735:
#line 8087 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1736:
#line 8093 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1737:
#line 8098 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1738:
#line 8106 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1739:
#line 8118 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1740:
#line 8119 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1741:
#line 8122 "fgl.yacc"
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
#line 8137 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1743:
#line 8148 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1744:
#line 8151 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1745:
#line 8159 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1746:
#line 8168 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1747:
#line 8171 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1748:
#line 8175 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1749:
#line 8178 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1750:
#line 8179 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1752:
#line 8192 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1753:
#line 8193 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1754:
#line 8202 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1755:
#line 8211 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1756:
#line 8216 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1757:
#line 8217 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1758:
#line 8218 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1759:
#line 8219 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1760:
#line 8226 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1761:
#line 8229 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1762:
#line 8235 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1763:
#line 8238 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1764:
#line 8245 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1765:
#line 8257 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1766:
#line 8266 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1767:
#line 8269 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1768:
#line 8272 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1769:
#line 8278 "fgl.yacc"
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
#line 8286 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1771:
#line 8289 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1772:
#line 8290 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1773:
#line 8291 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1774:
#line 8292 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1775:
#line 8293 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1776:
#line 8296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1777:
#line 8303 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1778:
#line 8305 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1779:
#line 8307 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1780:
#line 8309 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1781:
#line 8311 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1782:
#line 8312 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1783:
#line 8313 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1784:
#line 8314 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1785:
#line 8315 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1786:
#line 8316 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1787:
#line 8317 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1788:
#line 8319 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1789:
#line 8321 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1790:
#line 8323 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1791:
#line 8325 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1792:
#line 8327 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1793:
#line 8329 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1794:
#line 8331 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1795:
#line 8332 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1796:
#line 8334 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1797:
#line 8335 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1798:
#line 8336 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1799:
#line 8342 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1800:
#line 8343 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1802:
#line 8353 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1803:
#line 8361 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1804:
#line 8365 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1805:
#line 8372 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1806:
#line 8372 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1808:
#line 8376 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1809:
#line 8381 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1810:
#line 8381 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1812:
#line 8385 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1813:
#line 8389 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1816:
#line 8398 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1817:
#line 8398 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1822:
#line 8417 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1823:
#line 8418 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1826:
#line 8426 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1827:
#line 8432 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1830:
#line 8451 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1831:
#line 8452 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1832:
#line 8453 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1833:
#line 8454 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1834:
#line 8455 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1835:
#line 8456 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1836:
#line 8460 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1837:
#line 8461 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1838:
#line 8462 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1840:
#line 8467 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1841:
#line 8468 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1842:
#line 8472 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1843:
#line 8488 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1844:
#line 8489 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1845:
#line 8490 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1846:
#line 8494 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1847:
#line 8508 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1848:
#line 8512 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1850:
#line 8521 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1852:
#line 8526 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1853:
#line 8527 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1854:
#line 8851 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1855:
#line 8851 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1856:
#line 8858 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1857:
#line 8858 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1858:
#line 8946 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1859:
#line 8950 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1860:
#line 8952 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1861:
#line 8959 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1862:
#line 8963 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1863:
#line 8969 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1864:
#line 8977 "fgl.yacc"
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
#line 8987 "fgl.yacc"
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
#line 8997 "fgl.yacc"
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
#line 9009 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1868:
#line 9012 "fgl.yacc"
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
#line 9031 "fgl.yacc"
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
#line 9057 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1871:
#line 9060 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1873:
#line 9069 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1874:
#line 9074 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1875:
#line 9077 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1876:
#line 9085 "fgl.yacc"
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
#line 9093 "fgl.yacc"
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
#line 9106 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1879:
#line 9109 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1880:
#line 9117 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1881:
#line 9120 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1882:
#line 9123 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1883:
#line 9131 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1884:
#line 9135 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1885:
#line 9136 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1886:
#line 9137 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1887:
#line 9138 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1888:
#line 9139 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1889:
#line 9140 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1890:
#line 9141 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1891:
#line 9142 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1892:
#line 9146 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1893:
#line 9147 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1894:
#line 9148 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1895:
#line 9149 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1896:
#line 9150 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1897:
#line 9156 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1898:
#line 9157 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1899:
#line 9158 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1900:
#line 9159 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1901:
#line 9160 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1902:
#line 9161 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1903:
#line 9162 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1904:
#line 9163 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1905:
#line 9164 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1906:
#line 9165 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1907:
#line 9166 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1908:
#line 9167 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1909:
#line 9168 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1910:
#line 9169 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1911:
#line 9170 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1912:
#line 9171 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1913:
#line 9176 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1914:
#line 9182 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1915:
#line 9183 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1916:
#line 9191 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1917:
#line 9193 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1919:
#line 9199 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1920:
#line 9203 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1921:
#line 9207 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1922:
#line 9223 "fgl.yacc"
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
#line 9237 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1924:
#line 9243 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1925:
#line 9245 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1929:
#line 9259 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1930:
#line 9262 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1931:
#line 9269 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1932:
#line 9272 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1933:
#line 9302 "fgl.yacc"
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
#line 9327 "fgl.yacc"
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
#line 9382 "fgl.yacc"
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
#line 9417 "fgl.yacc"
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
#line 9426 "fgl.yacc"
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
#line 9437 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1939:
#line 9440 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1940:
#line 9446 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1941:
#line 9459 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1942:
#line 9473 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1943:
#line 9476 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1944:
#line 9480 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1945:
#line 9495 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1946:
#line 9495 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1947:
#line 9501 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1948:
#line 9502 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1949:
#line 9505 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1950:
#line 9506 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1951:
#line 9507 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1952:
#line 9508 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1953:
#line 9509 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1954:
#line 9510 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1955:
#line 9511 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1956:
#line 9522 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1957:
#line 9526 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1958:
#line 9530 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1959:
#line 9534 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1960:
#line 9539 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1961:
#line 9543 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1962:
#line 9548 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1964:
#line 9556 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1966:
#line 9562 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1967:
#line 9568 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1968:
#line 9572 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1973:
#line 9590 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1974:
#line 9597 "fgl.yacc"
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
#line 9607 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1976:
#line 9607 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18940 "y.tab.c"

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


#line 1012 "fgl.yacc"

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



