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
     NAME = 1709,
     UMINUS = 1710,
     COMMA = 1615,
     KW_OR = 1655,
     KW_AND = 1610,
     KW_USING = 1547,
     NOT = 1630,
     MATCHES = 1427,
     POWER = 1533,
     LESS_THAN = 1529,
     GREATER_THAN = 1444,
     EQUAL = 1605,
     GREATER_THAN_EQ = 1345,
     LESS_THAN_EQ = 1402,
     NOT_EQUAL = 1475,
     PLUS = 1641,
     MINUS = 1628,
     MULTIPLY = 1534,
     DIVIDE = 1561,
     MOD = 1629,
     COMMAND = 1409,
     NUMBER_VALUE = 1711,
     CHAR_VALUE = 1712,
     INT_VALUE = 1713,
     NAMED_GEN = 1714,
     CLINE = 1715,
     SQLLINE = 1716,
     KW_CSTART = 1717,
     KW_CEND = 1718,
     USER_DTYPE = 1719,
     SQL_TEXT = 1720,
     KW_WHENEVER_SET = 1721,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     AFTER_INSERT_DELETE = 1004,
     BEFORE_INSERT_DELETE = 1005,
     BEFORE_INSERT = 1006,
     CONCAT_PIPES = 1007,
     BEFORE_DELETE = 1008,
     DROP_TRIGGER = 1009,
     AFTER_INSERT = 1010,
     AFTER_DELETE = 1011,
     EXECUTE_IMMEDIATE = 1012,
     DELETE_ROW_EQUAL_TRUE = 1013,
     INSERT_ROW_EQUAL_TRUE = 1014,
     DELETE_ROW_EQUAL_FALSE = 1015,
     INSERT_ROW_EQUAL_FALSE = 1016,
     CURRENT_ROW_DISPLAY_EQUAL = 1017,
     MAXCOUNT = 1018,
     ALTER_TABLE = 1019,
     ALTER_INDEX = 1020,
     NEXT_SIZE = 1021,
     DISPLAY_ATTR_FORM = 1022,
     DISPLAY_ATTR_WINDOW = 1023,
     INPUT_ATTR_FORM = 1024,
     INPUT_ATTR_WINDOW = 1025,
     WHENEVER_ERROR_CONTINUE = 1026,
     WHENEVER_ANY_ERROR_CONTINUE = 1027,
     WHENEVER_WARNING_CONTINUE = 1028,
     WHENEVER_SQLSUCCESS_CONTINUE = 1029,
     WHENEVER_SQLWARNING_CONTINUE = 1030,
     WHENEVER_NOT_FOUND_CONTINUE = 1031,
     WHENEVER_SQLERROR_CONTINUE = 1032,
     WHENEVER_SUCCESS_CONTINUE = 1033,
     WHENEVER_ERROR_GOTO = 1034,
     WHENEVER_ANY_ERROR_GOTO = 1035,
     WHENEVER_WARNING_GOTO = 1036,
     WHENEVER_SQLSUCCESS_GOTO = 1037,
     WHENEVER_SQLWARNING_GOTO = 1038,
     WHENEVER_NOT_FOUND_GOTO = 1039,
     WHENEVER_SQLERROR_GOTO = 1040,
     WHENEVER_SUCCESS_GOTO = 1041,
     WHENEVER_ERROR_CALL = 1042,
     WHENEVER_ANY_ERROR_CALL = 1043,
     WHENEVER_WARNING_CALL = 1044,
     WHENEVER_SQLSUCCESS_CALL = 1045,
     WHENEVER_SQLWARNING_CALL = 1046,
     WHENEVER_NOT_FOUND_CALL = 1047,
     WHENEVER_SQLERROR_CALL = 1048,
     WHENEVER_SUCCESS_CALL = 1049,
     WHENEVER_ERROR_STOP = 1050,
     WHENEVER_ANY_ERROR_STOP = 1051,
     WHENEVER_WARNING_STOP = 1052,
     WHENEVER_SQLSUCCESS_STOP = 1053,
     WHENEVER_SQLWARNING_STOP = 1054,
     WHENEVER_NOT_FOUND_STOP = 1055,
     WHENEVER_SQLERROR_STOP = 1056,
     WHENEVER_SUCCESS_STOP = 1057,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1058,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1059,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1060,
     XSET_MULTIPLY_EQUAL = 1061,
     XSET_OPEN_BRACKET = 1062,
     NEWFORMATSHARED = 1063,
     CREATE_DATABASE = 1064,
     DROP_DATABASE = 1065,
     IMPORT_LEGACY_FUNCTION = 1066,
     ADD_CONSTRAINT = 1067,
     DROP_CONSTRAINT = 1068,
     DROP_SYNONYM = 1069,
     CONSTRAINT = 1070,
     AS_STATIC = 1071,
     NOT_FIELD_TOUCHED = 1072,
     LOCAL_FUNCTION = 1073,
     EVERY_ROW = 1074,
     ELIF = 1075,
     DOUBLE_PRECISION = 1076,
     COUNT_MULTIPLY = 1077,
     WAIT_FOR_KEY = 1078,
     AT_TERMINATION_CALL = 1079,
     TERMINATE_REPORT = 1080,
     TO_MAIN_CAPTION = 1081,
     CLEARSTAT = 1082,
     TO_MENUITEM = 1083,
     ID_TO_INT = 1084,
     TO_STATUSBOX = 1085,
     ASCII_HEIGHT_ALL = 1086,
     ASCII_WIDTH_ALL = 1087,
     IMPORT_DATATYPE = 1088,
     PAGE_TRAILER_SIZE = 1089,
     PAGE_HEADER_SIZE = 1090,
     FIRST_PAGE_HEADER_SIZE = 1091,
     BYTES_USE_AS_IMAGE = 1092,
     BYTES_USE_AS_ASCII = 1093,
     KWUP_BY = 1094,
     KWDOWN_BY = 1095,
     CLOSE_STATUSBOX = 1096,
     MODIFY_NEXT_SIZE = 1097,
     LOCK_MODE_PAGE = 1098,
     LOCK_MODE_ROW = 1099,
     TO_PIPE = 1100,
     TO_PRINTER = 1101,
     STATUSBOX = 1102,
     FORMHANDLER_INPUT = 1103,
     UNITS_YEAR = 1104,
     UNITS_MONTH = 1105,
     UNITS_DAY = 1106,
     UNITS_HOUR = 1107,
     UNITS_MINUTE = 1108,
     UNITS_SECOND = 1109,
     NO_NEW_LINES = 1110,
     FIELDTOWIDGET = 1111,
     WITH_HOLD = 1112,
     SHOW_MENU = 1113,
     TO_CLUSTER = 1114,
     TO_NOT_CLUSTER = 1115,
     CWIS = 1116,
     CREATE_IDX = 1117,
     FORM_IS_COMPILED = 1118,
     PDF_REPORT = 1119,
     IMPORT_FUNCTION = 1120,
     PROMPT_MANY = 1121,
     POINTS = 1122,
     MM = 1123,
     INCHES = 1124,
     PREPEND = 1125,
     MEMBER_OF = 1126,
     MEMBER_FUNCTION = 1127,
     APPEND = 1128,
     TEMPLATE = 1129,
     END_TEMPLATE = 1130,
     SQLSICS = 1131,
     CREATE_SCHEMA = 1132,
     SQLSIRR = 1133,
     UPDATESTATS_T = 1134,
     SQLSICR = 1135,
     WHENEVER_SQLSUCCESS = 1136,
     WHENEVER_SQLWARNING = 1137,
     WHENEVER_ANY_ERROR = 1138,
     WHENEVER_NOT_FOUND = 1139,
     WHENEVER_SQLERROR = 1140,
     WHENEVER_SUCCESS = 1141,
     WHENEVER_ERROR = 1142,
     START_EXTERN = 1143,
     CONTINUE_CONSTRUCT = 1144,
     FOUNCONSTR = 1145,
     SQLSIDR = 1146,
     CREATE_TEMP_TABLE = 1147,
     CURRENT_WINDOW_IS = 1148,
     FIRST_PAGE_HEADER = 1149,
     ORDER_EXTERNAL_BY = 1150,
     SCROLL_CURSOR_FOR = 1151,
     SCROLL_CURSOR = 1152,
     SQL_INTERRUPT_OFF = 1153,
     STOP_ALL_EXTERNAL = 1154,
     WITH_CHECK_OPTION = 1155,
     WITH_GRANT_OPTION = 1156,
     SQLSLMNW = 1157,
     ADDCONSTUNIQ = 1158,
     CONTINUE_DISPLAY = 1159,
     CONTINUE_FOREACH = 1160,
     OUTPUT_TO_REPORT = 1161,
     SQL_INTERRUPT_ON = 1162,
     WHERE_CURRENT_OF = 1163,
     WITHOUT_DEFAULTS = 1164,
     FOCONSTR = 1165,
     SCALED_BY = 1166,
     CONTINUE_PROMPT = 1167,
     PDF_FUNCTION = 1168,
     DEFER_INTERRUPT = 1169,
     DISPLAY_BY_NAME = 1170,
     NOT_NULL_UNIQUE = 1171,
     SKIP_TO_TOP = 1172,
     TOP_OF_PAGE = 1173,
     SKIP_TO = 1174,
     SKIP_BY = 1175,
     WITHOUT_WAITING = 1176,
     BEFCONSTRUCT = 1177,
     SQLSLMW = 1178,
     AFTCONSTRUCT = 1179,
     ALL_PRIVILEGES = 1180,
     CLOSE_DATABASE = 1181,
     CONTINUE_INPUT = 1182,
     CONTINUE_WHILE = 1183,
     CREATE_SYNONYM = 1184,
     DROP_TABLE = 1185,
     EXIT_CONSTRUCT = 1186,
     INEXCLUSIVE = 1187,
     REPORT_TO_PRINTER = 1188,
     REPORT_TO_PIPE = 1189,
     RETURN = 1190,
     SET_SESSION_TO = 1191,
     UPDATESTATS = 1192,
     WITHOUT_HEAD = 1193,
     CLEARSCR = 1194,
     WITH_B_LOG = 1195,
     AUTHORIZATION = 1196,
     BOTTOM_MARGIN = 1197,
     CLOSE_SESSION = 1198,
     CONTINUE_CASE = 1199,
     CONTINUE_MENU = 1200,
     DISPLAY_ARRAY = 1201,
     END_SQL = 1202,
     DOLLAR = 1203,
     END_CONSTRUCT = 1204,
     FIELD_TOUCHED = 1205,
     FINISH_REPORT = 1206,
     INFACC = 1207,
     INPUT_NO_WRAP = 1208,
     SETPMOFF = 1209,
     UNCONSTRAINED = 1210,
     PAGE_TRAILER = 1211,
     SETPMON = 1212,
     BEFGROUP = 1213,
     CLOSE_WINDOW = 1214,
     COMMENT_LINE = 1215,
     CONTINUE_FOR = 1216,
     CREATE_DB = 1217,
     CREATE_TABLE = 1218,
     DEFAULT_NULL = 1219,
     DEFAULT_TODAY = 1220,
     DEFAULT_USER = 1221,
     DELETE_USING = 1222,
     DISPLAY_FORM = 1223,
     END_FUNCTION = 1224,
     EXIT_DISPLAY = 1225,
     EXIT_FOREACH = 1226,
     EXIT_PROGRAM = 1227,
     INFCOLS = 1228,
     ON_EVERY_ROW = 1229,
     OPEN_SESSION = 1230,
     RIGHT_MARGIN = 1231,
     SELECT_USING = 1232,
     START_REPORT = 1233,
     UNLOCK_TABLE = 1234,
     UPDATE_USING = 1235,
     ACL_BUILTIN = 1236,
     AFTGROUP = 1237,
     INFIDX = 1238,
     INFSTAT = 1239,
     LEFT_MARGIN = 1240,
     PAGE_HEADER = 1241,
     ROLLBACK_W = 1242,
     SET_SESSION = 1243,
     SQLSEOFF = 1244,
     WITH_A_LOG = 1245,
     BEFDISP = 1246,
     BEFORE_MENU = 1247,
     CREATE_VIEW = 1248,
     DEFINE_TYPE = 1249,
     DELETE_FROM = 1250,
     END_DISPLAY = 1251,
     END_REPORT = 1252,
     END_FOREACH = 1253,
     END_FOR = 1254,
     END_GLOBALS = 1255,
     EXIT_PROMPT = 1256,
     EXTENT_SIZE = 1257,
     FOREIGN_KEY = 1258,
     HIDE_OPTION = 1259,
     HIDE_WINDOW = 1260,
     INSERT_INTO = 1261,
     IS_NOT_NULL = 1262,
     MOVE_WINDOW = 1263,
     NEXT_OPTION = 1264,
     NOT_MATCHES = 1265,
     ON_LAST_ROW = 1266,
     OPEN_WINDOW = 1267,
     OPEN_STATUSBOX = 1268,
     PAGE_LENGTH = 1269,
     PAGE_WIDTH = 1270,
     PRIMARY_KEY = 1271,
     PROMPT_LINE = 1272,
     RECORD_LIKE = 1273,
     ROLLFORWARD = 1274,
     SETBL = 1275,
     SHOW_OPTION = 1276,
     SHOW_WINDOW = 1277,
     SQLSEON = 1278,
     TO_DATABASE = 1279,
     USE_SESSION = 1280,
     WITH_NO_LOG = 1281,
     AFTDISP = 1282,
     BEFFIELD = 1283,
     INSHARE = 1284,
     UNLOCKTAB = 1285,
     AFTFIELD = 1286,
     ATTRIBUTES = 1287,
     BEFINP = 1288,
     BEGIN_WORK = 1289,
     CLEARWIN = 1290,
     CLOSE_FORM = 1291,
     DEFER_QUIT = 1292,
     DESCENDING = 1293,
     DROP_INDEX = 1294,
     END_PROMPT = 1295,
     END_RECORD = 1296,
     ERROR_LINE = 1297,
     EXIT_INPUT = 1298,
     EXIT_WHILE = 1299,
     FOR_UPDATE_OF = 1300,
     FOR_UPDATE = 1301,
     GET_FLDBUF = 1302,
     INITIALIZE = 1303,
     INPUT_WRAP = 1304,
     LOCK_TABLE = 1305,
     MSG_LINE = 1306,
     NOT_EXISTS = 1307,
     ON_ANY_KEY = 1308,
     REFERENCES = 1309,
     RENCOL = 1310,
     SET_CURSOR = 1311,
     SMALLFLOAT = 1312,
     SQLSUCCESS = 1313,
     TOP_MARGIN = 1314,
     WITH_ARRAY = 1315,
     ACCEPTKEY = 1316,
     ACCEPT = 1317,
     AFTINP = 1318,
     CLEARFORMTODEFAULTS = 1319,
     CLEARFORM = 1320,
     CLEAR_X_FORM = 1321,
     COMMIT_W = 1322,
     NEXTPAGE = 1323,
     PREVPAGE = 1324,
     CTRL_KEY = 1325,
     INFTABS = 1326,
     NEXTFIELD = 1327,
     NEXTFORM = 1328,
     RENTAB = 1329,
     ASCENDING = 1330,
     ASSOCIATE = 1331,
     CHAR = 1332,
     NCHAR = 1333,
     NVARCHAR = 1334,
     CONSTRUCT = 1335,
     DELIMITER = 1336,
     DOWNSHIFT = 1337,
     DROP_VIEW = 1338,
     END_INPUT = 1339,
     END_WHILE = 1340,
     EXCLUSIVE = 1341,
     EXIT_CASE = 1342,
     EXIT_MENU = 1343,
     FORM_LINE = 1344,
     INTERRUPT = 1346,
     INTO_TEMP = 1347,
     INVISIBLE = 1348,
     IN_MEMORY = 1349,
     LINKED_TO = 1350,
     LOAD_FROM = 1351,
     LOCKTAB = 1352,
     MENU_LINE = 1353,
     OPEN_FORM = 1354,
     OTHERWISE = 1355,
     PRECISION = 1356,
     PRIOR = 1357,
     PROCEDURE = 1358,
     REPORT_TO = 1359,
     RETURNING = 1360,
     UNDERLINE = 1361,
     UNLOAD_TO = 1362,
     BEFROW = 1363,
     UNLOAD_T = 1364,
     VARIABLE = 1365,
     ABSOLUTE = 1366,
     AFTROW = 1367,
     BUFFERED = 1368,
     CONSTANT = 1369,
     CONST = 1370,
     DATABASE = 1371,
     DATETIME = 1372,
     DEFAULTS = 1373,
     DISTINCT = 1374,
     END_CASE = 1375,
     END_MAIN = 1376,
     END_MENU = 1377,
     END_TYPE = 1378,
     EXIT_FOR = 1379,
     EXTERNAL = 1380,
     FRACTION = 1381,
     FUNCTION = 1382,
     GROUP_BY = 1383,
     INTERVAL = 1384,
     KWMESSAGE = 1385,
     NOT_LIKE = 1386,
     NOT_ILIKE = 1387,
     NOT_NULL = 1388,
     PASSWORD = 1389,
     PREVIOUS = 1390,
     READONLY = 1391,
     REGISTER = 1392,
     RELATIVE = 1393,
     RESOURCE = 1394,
     SMALLINT = 1395,
     VALIDATE = 1396,
     WITH_LOG = 1397,
     WORDWRAP = 1398,
     BY_NAME = 1399,
     IN_FILE = 1400,
     IS_NULL = 1401,
     AVERAGE = 1403,
     BETWEEN = 1404,
     CAPTION = 1405,
     CLIPPED = 1406,
     CLOSE_BRACKET = 1407,
     COLUMNS = 1408,
     COMMENT = 1410,
     CONNECT = 1411,
     CURRENT = 1412,
     DBYNAME = 1413,
     DECIMAL = 1414,
     DECLARE = 1415,
     DEFAULT = 1416,
     DISPLAY = 1417,
     ENDCODE = 1418,
     EXECUTE = 1419,
     FOREACH = 1420,
     FOREIGN = 1421,
     GLOBALS = 1422,
     INFIELD = 1423,
     INTEGER = 1424,
     KWWINDOW = 1425,
     MAGENTA = 1426,
     OPTIONS = 1428,
     PERCENT = 1429,
     PREPARE = 1430,
     PROGRAM = 1431,
     RECOVER = 1432,
     REVERSE = 1433,
     SECTION = 1434,
     SESSION = 1435,
     SYNONYM = 1436,
     THRU = 1437,
     TRAILER = 1438,
     UPSHIFT = 1439,
     VARCHAR = 1440,
     WAITING = 1441,
     CLOSE_SHEV = 1442,
     CLOSE_SQUARE = 1443,
     KW_FALSE = 1445,
     NOT_IN = 1446,
     ONKEY = 1447,
     OPEN_BRACKET = 1448,
     BORDER = 1449,
     BOTTOM = 1450,
     COLUMN = 1451,
     COMMIT = 1452,
     CREATE = 1453,
     CURSOR = 1454,
     DEFINE = 1455,
     DELETE = 1456,
     DOUBLE = 1457,
     END_IF = 1458,
     ESCAPE = 1459,
     EXISTS = 1460,
     EXTEND = 1461,
     EXTENT = 1462,
     FINISH = 1463,
     FORMAT = 1464,
     HAVING = 1465,
     HEADER = 1466,
     INSERT = 1467,
     LOCATE = 1468,
     MARGIN = 1469,
     MEMORY = 1470,
     MINUTE = 1471,
     MODIFY = 1472,
     NORMAL = 1473,
     EQUAL_EQUAL = 1474,
     OPEN_SHEV = 1476,
     OPEN_SQUARE = 1477,
     OPTION = 1478,
     OUTPUT = 1479,
     PROMPT = 1480,
     PUBLIC = 1481,
     RECORD = 1482,
     REPORT = 1483,
     REVOKE = 1484,
     SCHEMA = 1485,
     SCROLL_USING = 1486,
     SCROLL = 1487,
     SECOND = 1488,
     SELECT = 1489,
     SERIAL = 1490,
     SETL = 1491,
     SHARED = 1492,
     SPACES = 1493,
     UNIQUE = 1494,
     UNLOCK = 1495,
     UPDATE = 1496,
     VALUES = 1497,
     YELLOW = 1498,
     AFTER = 1499,
     KWLINE = 1500,
     KW_NULL = 1501,
     KW_TRUE = 1502,
     SINGLE_KEY = 1503,
     ALTER = 1504,
     ARRAY = 1505,
     ASCII = 1506,
     AUDIT = 1507,
     BLACK = 1508,
     BLINK = 1509,
     CHECK = 1510,
     CLEAR = 1511,
     CLOSE = 1512,
     CODE_C = 1513,
     COUNT = 1514,
     DEFER = 1515,
     ERROR = 1516,
     EVERY = 1517,
     FETCH = 1518,
     FIRST = 1519,
     FLOAT = 1520,
     FLUSH = 1521,
     FOUND = 1522,
     GRANT = 1523,
     GREEN = 1524,
     GROUP = 1525,
     INDEX = 1526,
     KWFORM = 1527,
     LABEL = 1528,
     LOCAL = 1530,
     MONEY = 1531,
     MONTH = 1532,
     ORDER = 1535,
     OUTER = 1536,
     PAUSE = 1537,
     PRINT_IMAGE = 1538,
     PRINT_FILE = 1539,
     PRINT = 1540,
     RIGHT = 1541,
     DOUBLE_COLON = 1542,
     SEMICOLON = 1543,
     SLEEP = 1544,
     TUPLE = 1545,
     UNION = 1546,
     WHERE = 1548,
     WHILE = 1549,
     WHITE = 1550,
     CCODE = 1551,
     ANSI = 1552,
     BLUE = 1553,
     BOLD = 1554,
     BYTE = 1555,
     FCALL = 1556,
     CASE = 1557,
     CYAN = 1558,
     DATE = 1559,
     DESC = 1560,
     KWDOWN = 1562,
     TAB = 1563,
     DROP = 1564,
     ELSE = 1565,
     EXEC = 1566,
     EXIT = 1567,
     FREE = 1568,
     FROM = 1569,
     GOTO = 1570,
     HELP_FILE = 1571,
     LANG_FILE = 1572,
     HELP = 1573,
     HIDE = 1574,
     HOUR = 1575,
     INTO = 1576,
     LAST = 1577,
     LEFT = 1578,
     LIKE = 1579,
     MAIN = 1580,
     MENU = 1581,
     MODE = 1582,
     NEED = 1583,
     NEXT = 1584,
     NOCR = 1585,
     OPEN = 1586,
     QUIT = 1587,
     REAL = 1588,
     ROWS = 1589,
     SHOW = 1590,
     SIZE = 1591,
     SKIP = 1592,
     SOME = 1593,
     STEP = 1594,
     STOP = 1595,
     TEMP = 1596,
     TEXT = 1597,
     THEN = 1598,
     USER = 1599,
     WAIT = 1600,
     WHEN = 1601,
     WITH = 1602,
     WORK = 1603,
     YEAR = 1604,
     KW_IS = 1606,
     XSET = 1607,
     ADD = 1608,
     ALL = 1609,
     ANY = 1611,
     ASC = 1612,
     AVG = 1613,
     COLON = 1614,
     DAY = 1616,
     DBA = 1617,
     DEC = 1618,
     DIM = 1619,
     FKEY = 1620,
     FOR = 1621,
     KEY = 1622,
     KWNO = 1623,
     LET = 1624,
     LOG = 1625,
     XMAX = 1626,
     XMIN = 1627,
     PAD = 1631,
     PUT = 1632,
     RED = 1633,
     ROW = 1634,
     RUN = 1635,
     SQL = 1636,
     SUM = 1637,
     TOP = 1638,
     USE = 1639,
     ATSIGN = 1640,
     AS_TIFF = 1642,
     AS_GIF = 1643,
     AS_PNG = 1644,
     AS_JPEG = 1645,
     AS = 1646,
     AT = 1647,
     BY = 1648,
     DOT = 1649,
     GO = 1650,
     IF = 1651,
     IN = 1652,
     OF = 1653,
     ON = 1654,
     TO = 1656,
     KWUP = 1657,
     FONT_NAME = 1658,
     FONT_SIZE = 1659,
     PAPER_SIZE_IS_LETTER = 1660,
     PAPER_SIZE_IS_LEGAL = 1661,
     PAPER_SIZE_IS_A5 = 1662,
     PAPER_SIZE_IS_A4 = 1663,
     PAPER_SIZE_IS_LETTER_L = 1664,
     PAPER_SIZE_IS_LEGAL_L = 1665,
     PAPER_SIZE_IS_A5_L = 1666,
     PAPER_SIZE_IS_A4_L = 1667,
     FORMHANDLER = 1668,
     END_FORMHANDLER = 1669,
     BEFORE_EVENT = 1670,
     BEFORE_OPEN_FORM = 1671,
     AFTER_EVENT = 1672,
     BEFORE_CLOSE_FORM = 1673,
     BEFORE_ANY = 1674,
     AFTER_ANY = 1675,
     MENUHANDLER = 1676,
     END_MENUHANDLER = 1677,
     BEFORE_SHOW_MENU = 1678,
     DISABLE_PROGRAM = 1679,
     DISABLE_ALL = 1680,
     BUTTONS = 1681,
     CHECK_MENUITEM = 1682,
     DISABLE_FORM = 1683,
     DISABLE_MENUITEMS = 1684,
     DISABLE = 1685,
     ENABLE_FORM = 1686,
     ENABLE_MENUITEMS = 1687,
     ENABLE = 1688,
     KWFIELD = 1689,
     ICON = 1690,
     MESSAGEBOX = 1691,
     TO_DEFAULTS = 1692,
     UNCHECK_MENUITEM = 1693,
     BEFORE = 1694,
     INPUT = 1695,
     END = 1696,
     INT_TO_ID = 1697,
     TIMEOUT = 1698,
     OFF = 1699,
     WITH_1_DIMENSION = 1700,
     WITH_2_DIMENSION = 1701,
     WITH_3_DIMENSION = 1702,
     TILDE = 1703,
     ILIKE = 1704,
     FGL_ISDYNARR_ALLOCATED = 1705,
     FGL_DYNARR_EXTENTSIZE = 1706,
     FILLFACTOR = 1707
   };
#endif
#define NAME 1709
#define UMINUS 1710
#define COMMA 1615
#define KW_OR 1655
#define KW_AND 1610
#define KW_USING 1547
#define NOT 1630
#define MATCHES 1427
#define POWER 1533
#define LESS_THAN 1529
#define GREATER_THAN 1444
#define EQUAL 1605
#define GREATER_THAN_EQ 1345
#define LESS_THAN_EQ 1402
#define NOT_EQUAL 1475
#define PLUS 1641
#define MINUS 1628
#define MULTIPLY 1534
#define DIVIDE 1561
#define MOD 1629
#define COMMAND 1409
#define NUMBER_VALUE 1711
#define CHAR_VALUE 1712
#define INT_VALUE 1713
#define NAMED_GEN 1714
#define CLINE 1715
#define SQLLINE 1716
#define KW_CSTART 1717
#define KW_CEND 1718
#define USER_DTYPE 1719
#define SQL_TEXT 1720
#define KW_WHENEVER_SET 1721
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define AFTER_INSERT_DELETE 1004
#define BEFORE_INSERT_DELETE 1005
#define BEFORE_INSERT 1006
#define CONCAT_PIPES 1007
#define BEFORE_DELETE 1008
#define DROP_TRIGGER 1009
#define AFTER_INSERT 1010
#define AFTER_DELETE 1011
#define EXECUTE_IMMEDIATE 1012
#define DELETE_ROW_EQUAL_TRUE 1013
#define INSERT_ROW_EQUAL_TRUE 1014
#define DELETE_ROW_EQUAL_FALSE 1015
#define INSERT_ROW_EQUAL_FALSE 1016
#define CURRENT_ROW_DISPLAY_EQUAL 1017
#define MAXCOUNT 1018
#define ALTER_TABLE 1019
#define ALTER_INDEX 1020
#define NEXT_SIZE 1021
#define DISPLAY_ATTR_FORM 1022
#define DISPLAY_ATTR_WINDOW 1023
#define INPUT_ATTR_FORM 1024
#define INPUT_ATTR_WINDOW 1025
#define WHENEVER_ERROR_CONTINUE 1026
#define WHENEVER_ANY_ERROR_CONTINUE 1027
#define WHENEVER_WARNING_CONTINUE 1028
#define WHENEVER_SQLSUCCESS_CONTINUE 1029
#define WHENEVER_SQLWARNING_CONTINUE 1030
#define WHENEVER_NOT_FOUND_CONTINUE 1031
#define WHENEVER_SQLERROR_CONTINUE 1032
#define WHENEVER_SUCCESS_CONTINUE 1033
#define WHENEVER_ERROR_GOTO 1034
#define WHENEVER_ANY_ERROR_GOTO 1035
#define WHENEVER_WARNING_GOTO 1036
#define WHENEVER_SQLSUCCESS_GOTO 1037
#define WHENEVER_SQLWARNING_GOTO 1038
#define WHENEVER_NOT_FOUND_GOTO 1039
#define WHENEVER_SQLERROR_GOTO 1040
#define WHENEVER_SUCCESS_GOTO 1041
#define WHENEVER_ERROR_CALL 1042
#define WHENEVER_ANY_ERROR_CALL 1043
#define WHENEVER_WARNING_CALL 1044
#define WHENEVER_SQLSUCCESS_CALL 1045
#define WHENEVER_SQLWARNING_CALL 1046
#define WHENEVER_NOT_FOUND_CALL 1047
#define WHENEVER_SQLERROR_CALL 1048
#define WHENEVER_SUCCESS_CALL 1049
#define WHENEVER_ERROR_STOP 1050
#define WHENEVER_ANY_ERROR_STOP 1051
#define WHENEVER_WARNING_STOP 1052
#define WHENEVER_SQLSUCCESS_STOP 1053
#define WHENEVER_SQLWARNING_STOP 1054
#define WHENEVER_NOT_FOUND_STOP 1055
#define WHENEVER_SQLERROR_STOP 1056
#define WHENEVER_SUCCESS_STOP 1057
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1058
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1059
#define XSET_ident_DOT_MULTIPLY_EQUAL 1060
#define XSET_MULTIPLY_EQUAL 1061
#define XSET_OPEN_BRACKET 1062
#define NEWFORMATSHARED 1063
#define CREATE_DATABASE 1064
#define DROP_DATABASE 1065
#define IMPORT_LEGACY_FUNCTION 1066
#define ADD_CONSTRAINT 1067
#define DROP_CONSTRAINT 1068
#define DROP_SYNONYM 1069
#define CONSTRAINT 1070
#define AS_STATIC 1071
#define NOT_FIELD_TOUCHED 1072
#define LOCAL_FUNCTION 1073
#define EVERY_ROW 1074
#define ELIF 1075
#define DOUBLE_PRECISION 1076
#define COUNT_MULTIPLY 1077
#define WAIT_FOR_KEY 1078
#define AT_TERMINATION_CALL 1079
#define TERMINATE_REPORT 1080
#define TO_MAIN_CAPTION 1081
#define CLEARSTAT 1082
#define TO_MENUITEM 1083
#define ID_TO_INT 1084
#define TO_STATUSBOX 1085
#define ASCII_HEIGHT_ALL 1086
#define ASCII_WIDTH_ALL 1087
#define IMPORT_DATATYPE 1088
#define PAGE_TRAILER_SIZE 1089
#define PAGE_HEADER_SIZE 1090
#define FIRST_PAGE_HEADER_SIZE 1091
#define BYTES_USE_AS_IMAGE 1092
#define BYTES_USE_AS_ASCII 1093
#define KWUP_BY 1094
#define KWDOWN_BY 1095
#define CLOSE_STATUSBOX 1096
#define MODIFY_NEXT_SIZE 1097
#define LOCK_MODE_PAGE 1098
#define LOCK_MODE_ROW 1099
#define TO_PIPE 1100
#define TO_PRINTER 1101
#define STATUSBOX 1102
#define FORMHANDLER_INPUT 1103
#define UNITS_YEAR 1104
#define UNITS_MONTH 1105
#define UNITS_DAY 1106
#define UNITS_HOUR 1107
#define UNITS_MINUTE 1108
#define UNITS_SECOND 1109
#define NO_NEW_LINES 1110
#define FIELDTOWIDGET 1111
#define WITH_HOLD 1112
#define SHOW_MENU 1113
#define TO_CLUSTER 1114
#define TO_NOT_CLUSTER 1115
#define CWIS 1116
#define CREATE_IDX 1117
#define FORM_IS_COMPILED 1118
#define PDF_REPORT 1119
#define IMPORT_FUNCTION 1120
#define PROMPT_MANY 1121
#define POINTS 1122
#define MM 1123
#define INCHES 1124
#define PREPEND 1125
#define MEMBER_OF 1126
#define MEMBER_FUNCTION 1127
#define APPEND 1128
#define TEMPLATE 1129
#define END_TEMPLATE 1130
#define SQLSICS 1131
#define CREATE_SCHEMA 1132
#define SQLSIRR 1133
#define UPDATESTATS_T 1134
#define SQLSICR 1135
#define WHENEVER_SQLSUCCESS 1136
#define WHENEVER_SQLWARNING 1137
#define WHENEVER_ANY_ERROR 1138
#define WHENEVER_NOT_FOUND 1139
#define WHENEVER_SQLERROR 1140
#define WHENEVER_SUCCESS 1141
#define WHENEVER_ERROR 1142
#define START_EXTERN 1143
#define CONTINUE_CONSTRUCT 1144
#define FOUNCONSTR 1145
#define SQLSIDR 1146
#define CREATE_TEMP_TABLE 1147
#define CURRENT_WINDOW_IS 1148
#define FIRST_PAGE_HEADER 1149
#define ORDER_EXTERNAL_BY 1150
#define SCROLL_CURSOR_FOR 1151
#define SCROLL_CURSOR 1152
#define SQL_INTERRUPT_OFF 1153
#define STOP_ALL_EXTERNAL 1154
#define WITH_CHECK_OPTION 1155
#define WITH_GRANT_OPTION 1156
#define SQLSLMNW 1157
#define ADDCONSTUNIQ 1158
#define CONTINUE_DISPLAY 1159
#define CONTINUE_FOREACH 1160
#define OUTPUT_TO_REPORT 1161
#define SQL_INTERRUPT_ON 1162
#define WHERE_CURRENT_OF 1163
#define WITHOUT_DEFAULTS 1164
#define FOCONSTR 1165
#define SCALED_BY 1166
#define CONTINUE_PROMPT 1167
#define PDF_FUNCTION 1168
#define DEFER_INTERRUPT 1169
#define DISPLAY_BY_NAME 1170
#define NOT_NULL_UNIQUE 1171
#define SKIP_TO_TOP 1172
#define TOP_OF_PAGE 1173
#define SKIP_TO 1174
#define SKIP_BY 1175
#define WITHOUT_WAITING 1176
#define BEFCONSTRUCT 1177
#define SQLSLMW 1178
#define AFTCONSTRUCT 1179
#define ALL_PRIVILEGES 1180
#define CLOSE_DATABASE 1181
#define CONTINUE_INPUT 1182
#define CONTINUE_WHILE 1183
#define CREATE_SYNONYM 1184
#define DROP_TABLE 1185
#define EXIT_CONSTRUCT 1186
#define INEXCLUSIVE 1187
#define REPORT_TO_PRINTER 1188
#define REPORT_TO_PIPE 1189
#define RETURN 1190
#define SET_SESSION_TO 1191
#define UPDATESTATS 1192
#define WITHOUT_HEAD 1193
#define CLEARSCR 1194
#define WITH_B_LOG 1195
#define AUTHORIZATION 1196
#define BOTTOM_MARGIN 1197
#define CLOSE_SESSION 1198
#define CONTINUE_CASE 1199
#define CONTINUE_MENU 1200
#define DISPLAY_ARRAY 1201
#define END_SQL 1202
#define DOLLAR 1203
#define END_CONSTRUCT 1204
#define FIELD_TOUCHED 1205
#define FINISH_REPORT 1206
#define INFACC 1207
#define INPUT_NO_WRAP 1208
#define SETPMOFF 1209
#define UNCONSTRAINED 1210
#define PAGE_TRAILER 1211
#define SETPMON 1212
#define BEFGROUP 1213
#define CLOSE_WINDOW 1214
#define COMMENT_LINE 1215
#define CONTINUE_FOR 1216
#define CREATE_DB 1217
#define CREATE_TABLE 1218
#define DEFAULT_NULL 1219
#define DEFAULT_TODAY 1220
#define DEFAULT_USER 1221
#define DELETE_USING 1222
#define DISPLAY_FORM 1223
#define END_FUNCTION 1224
#define EXIT_DISPLAY 1225
#define EXIT_FOREACH 1226
#define EXIT_PROGRAM 1227
#define INFCOLS 1228
#define ON_EVERY_ROW 1229
#define OPEN_SESSION 1230
#define RIGHT_MARGIN 1231
#define SELECT_USING 1232
#define START_REPORT 1233
#define UNLOCK_TABLE 1234
#define UPDATE_USING 1235
#define ACL_BUILTIN 1236
#define AFTGROUP 1237
#define INFIDX 1238
#define INFSTAT 1239
#define LEFT_MARGIN 1240
#define PAGE_HEADER 1241
#define ROLLBACK_W 1242
#define SET_SESSION 1243
#define SQLSEOFF 1244
#define WITH_A_LOG 1245
#define BEFDISP 1246
#define BEFORE_MENU 1247
#define CREATE_VIEW 1248
#define DEFINE_TYPE 1249
#define DELETE_FROM 1250
#define END_DISPLAY 1251
#define END_REPORT 1252
#define END_FOREACH 1253
#define END_FOR 1254
#define END_GLOBALS 1255
#define EXIT_PROMPT 1256
#define EXTENT_SIZE 1257
#define FOREIGN_KEY 1258
#define HIDE_OPTION 1259
#define HIDE_WINDOW 1260
#define INSERT_INTO 1261
#define IS_NOT_NULL 1262
#define MOVE_WINDOW 1263
#define NEXT_OPTION 1264
#define NOT_MATCHES 1265
#define ON_LAST_ROW 1266
#define OPEN_WINDOW 1267
#define OPEN_STATUSBOX 1268
#define PAGE_LENGTH 1269
#define PAGE_WIDTH 1270
#define PRIMARY_KEY 1271
#define PROMPT_LINE 1272
#define RECORD_LIKE 1273
#define ROLLFORWARD 1274
#define SETBL 1275
#define SHOW_OPTION 1276
#define SHOW_WINDOW 1277
#define SQLSEON 1278
#define TO_DATABASE 1279
#define USE_SESSION 1280
#define WITH_NO_LOG 1281
#define AFTDISP 1282
#define BEFFIELD 1283
#define INSHARE 1284
#define UNLOCKTAB 1285
#define AFTFIELD 1286
#define ATTRIBUTES 1287
#define BEFINP 1288
#define BEGIN_WORK 1289
#define CLEARWIN 1290
#define CLOSE_FORM 1291
#define DEFER_QUIT 1292
#define DESCENDING 1293
#define DROP_INDEX 1294
#define END_PROMPT 1295
#define END_RECORD 1296
#define ERROR_LINE 1297
#define EXIT_INPUT 1298
#define EXIT_WHILE 1299
#define FOR_UPDATE_OF 1300
#define FOR_UPDATE 1301
#define GET_FLDBUF 1302
#define INITIALIZE 1303
#define INPUT_WRAP 1304
#define LOCK_TABLE 1305
#define MSG_LINE 1306
#define NOT_EXISTS 1307
#define ON_ANY_KEY 1308
#define REFERENCES 1309
#define RENCOL 1310
#define SET_CURSOR 1311
#define SMALLFLOAT 1312
#define SQLSUCCESS 1313
#define TOP_MARGIN 1314
#define WITH_ARRAY 1315
#define ACCEPTKEY 1316
#define ACCEPT 1317
#define AFTINP 1318
#define CLEARFORMTODEFAULTS 1319
#define CLEARFORM 1320
#define CLEAR_X_FORM 1321
#define COMMIT_W 1322
#define NEXTPAGE 1323
#define PREVPAGE 1324
#define CTRL_KEY 1325
#define INFTABS 1326
#define NEXTFIELD 1327
#define NEXTFORM 1328
#define RENTAB 1329
#define ASCENDING 1330
#define ASSOCIATE 1331
#define CHAR 1332
#define NCHAR 1333
#define NVARCHAR 1334
#define CONSTRUCT 1335
#define DELIMITER 1336
#define DOWNSHIFT 1337
#define DROP_VIEW 1338
#define END_INPUT 1339
#define END_WHILE 1340
#define EXCLUSIVE 1341
#define EXIT_CASE 1342
#define EXIT_MENU 1343
#define FORM_LINE 1344
#define INTERRUPT 1346
#define INTO_TEMP 1347
#define INVISIBLE 1348
#define IN_MEMORY 1349
#define LINKED_TO 1350
#define LOAD_FROM 1351
#define LOCKTAB 1352
#define MENU_LINE 1353
#define OPEN_FORM 1354
#define OTHERWISE 1355
#define PRECISION 1356
#define PRIOR 1357
#define PROCEDURE 1358
#define REPORT_TO 1359
#define RETURNING 1360
#define UNDERLINE 1361
#define UNLOAD_TO 1362
#define BEFROW 1363
#define UNLOAD_T 1364
#define VARIABLE 1365
#define ABSOLUTE 1366
#define AFTROW 1367
#define BUFFERED 1368
#define CONSTANT 1369
#define CONST 1370
#define DATABASE 1371
#define DATETIME 1372
#define DEFAULTS 1373
#define DISTINCT 1374
#define END_CASE 1375
#define END_MAIN 1376
#define END_MENU 1377
#define END_TYPE 1378
#define EXIT_FOR 1379
#define EXTERNAL 1380
#define FRACTION 1381
#define FUNCTION 1382
#define GROUP_BY 1383
#define INTERVAL 1384
#define KWMESSAGE 1385
#define NOT_LIKE 1386
#define NOT_ILIKE 1387
#define NOT_NULL 1388
#define PASSWORD 1389
#define PREVIOUS 1390
#define READONLY 1391
#define REGISTER 1392
#define RELATIVE 1393
#define RESOURCE 1394
#define SMALLINT 1395
#define VALIDATE 1396
#define WITH_LOG 1397
#define WORDWRAP 1398
#define BY_NAME 1399
#define IN_FILE 1400
#define IS_NULL 1401
#define AVERAGE 1403
#define BETWEEN 1404
#define CAPTION 1405
#define CLIPPED 1406
#define CLOSE_BRACKET 1407
#define COLUMNS 1408
#define COMMENT 1410
#define CONNECT 1411
#define CURRENT 1412
#define DBYNAME 1413
#define DECIMAL 1414
#define DECLARE 1415
#define DEFAULT 1416
#define DISPLAY 1417
#define ENDCODE 1418
#define EXECUTE 1419
#define FOREACH 1420
#define FOREIGN 1421
#define GLOBALS 1422
#define INFIELD 1423
#define INTEGER 1424
#define KWWINDOW 1425
#define MAGENTA 1426
#define OPTIONS 1428
#define PERCENT 1429
#define PREPARE 1430
#define PROGRAM 1431
#define RECOVER 1432
#define REVERSE 1433
#define SECTION 1434
#define SESSION 1435
#define SYNONYM 1436
#define THRU 1437
#define TRAILER 1438
#define UPSHIFT 1439
#define VARCHAR 1440
#define WAITING 1441
#define CLOSE_SHEV 1442
#define CLOSE_SQUARE 1443
#define KW_FALSE 1445
#define NOT_IN 1446
#define ONKEY 1447
#define OPEN_BRACKET 1448
#define BORDER 1449
#define BOTTOM 1450
#define COLUMN 1451
#define COMMIT 1452
#define CREATE 1453
#define CURSOR 1454
#define DEFINE 1455
#define DELETE 1456
#define DOUBLE 1457
#define END_IF 1458
#define ESCAPE 1459
#define EXISTS 1460
#define EXTEND 1461
#define EXTENT 1462
#define FINISH 1463
#define FORMAT 1464
#define HAVING 1465
#define HEADER 1466
#define INSERT 1467
#define LOCATE 1468
#define MARGIN 1469
#define MEMORY 1470
#define MINUTE 1471
#define MODIFY 1472
#define NORMAL 1473
#define EQUAL_EQUAL 1474
#define OPEN_SHEV 1476
#define OPEN_SQUARE 1477
#define OPTION 1478
#define OUTPUT 1479
#define PROMPT 1480
#define PUBLIC 1481
#define RECORD 1482
#define REPORT 1483
#define REVOKE 1484
#define SCHEMA 1485
#define SCROLL_USING 1486
#define SCROLL 1487
#define SECOND 1488
#define SELECT 1489
#define SERIAL 1490
#define SETL 1491
#define SHARED 1492
#define SPACES 1493
#define UNIQUE 1494
#define UNLOCK 1495
#define UPDATE 1496
#define VALUES 1497
#define YELLOW 1498
#define AFTER 1499
#define KWLINE 1500
#define KW_NULL 1501
#define KW_TRUE 1502
#define SINGLE_KEY 1503
#define ALTER 1504
#define ARRAY 1505
#define ASCII 1506
#define AUDIT 1507
#define BLACK 1508
#define BLINK 1509
#define CHECK 1510
#define CLEAR 1511
#define CLOSE 1512
#define CODE_C 1513
#define COUNT 1514
#define DEFER 1515
#define ERROR 1516
#define EVERY 1517
#define FETCH 1518
#define FIRST 1519
#define FLOAT 1520
#define FLUSH 1521
#define FOUND 1522
#define GRANT 1523
#define GREEN 1524
#define GROUP 1525
#define INDEX 1526
#define KWFORM 1527
#define LABEL 1528
#define LOCAL 1530
#define MONEY 1531
#define MONTH 1532
#define ORDER 1535
#define OUTER 1536
#define PAUSE 1537
#define PRINT_IMAGE 1538
#define PRINT_FILE 1539
#define PRINT 1540
#define RIGHT 1541
#define DOUBLE_COLON 1542
#define SEMICOLON 1543
#define SLEEP 1544
#define TUPLE 1545
#define UNION 1546
#define WHERE 1548
#define WHILE 1549
#define WHITE 1550
#define CCODE 1551
#define ANSI 1552
#define BLUE 1553
#define BOLD 1554
#define BYTE 1555
#define FCALL 1556
#define CASE 1557
#define CYAN 1558
#define DATE 1559
#define DESC 1560
#define KWDOWN 1562
#define TAB 1563
#define DROP 1564
#define ELSE 1565
#define EXEC 1566
#define EXIT 1567
#define FREE 1568
#define FROM 1569
#define GOTO 1570
#define HELP_FILE 1571
#define LANG_FILE 1572
#define HELP 1573
#define HIDE 1574
#define HOUR 1575
#define INTO 1576
#define LAST 1577
#define LEFT 1578
#define LIKE 1579
#define MAIN 1580
#define MENU 1581
#define MODE 1582
#define NEED 1583
#define NEXT 1584
#define NOCR 1585
#define OPEN 1586
#define QUIT 1587
#define REAL 1588
#define ROWS 1589
#define SHOW 1590
#define SIZE 1591
#define SKIP 1592
#define SOME 1593
#define STEP 1594
#define STOP 1595
#define TEMP 1596
#define TEXT 1597
#define THEN 1598
#define USER 1599
#define WAIT 1600
#define WHEN 1601
#define WITH 1602
#define WORK 1603
#define YEAR 1604
#define KW_IS 1606
#define XSET 1607
#define ADD 1608
#define ALL 1609
#define ANY 1611
#define ASC 1612
#define AVG 1613
#define COLON 1614
#define DAY 1616
#define DBA 1617
#define DEC 1618
#define DIM 1619
#define FKEY 1620
#define FOR 1621
#define KEY 1622
#define KWNO 1623
#define LET 1624
#define LOG 1625
#define XMAX 1626
#define XMIN 1627
#define PAD 1631
#define PUT 1632
#define RED 1633
#define ROW 1634
#define RUN 1635
#define SQL 1636
#define SUM 1637
#define TOP 1638
#define USE 1639
#define ATSIGN 1640
#define AS_TIFF 1642
#define AS_GIF 1643
#define AS_PNG 1644
#define AS_JPEG 1645
#define AS 1646
#define AT 1647
#define BY 1648
#define DOT 1649
#define GO 1650
#define IF 1651
#define IN 1652
#define OF 1653
#define ON 1654
#define TO 1656
#define KWUP 1657
#define FONT_NAME 1658
#define FONT_SIZE 1659
#define PAPER_SIZE_IS_LETTER 1660
#define PAPER_SIZE_IS_LEGAL 1661
#define PAPER_SIZE_IS_A5 1662
#define PAPER_SIZE_IS_A4 1663
#define PAPER_SIZE_IS_LETTER_L 1664
#define PAPER_SIZE_IS_LEGAL_L 1665
#define PAPER_SIZE_IS_A5_L 1666
#define PAPER_SIZE_IS_A4_L 1667
#define FORMHANDLER 1668
#define END_FORMHANDLER 1669
#define BEFORE_EVENT 1670
#define BEFORE_OPEN_FORM 1671
#define AFTER_EVENT 1672
#define BEFORE_CLOSE_FORM 1673
#define BEFORE_ANY 1674
#define AFTER_ANY 1675
#define MENUHANDLER 1676
#define END_MENUHANDLER 1677
#define BEFORE_SHOW_MENU 1678
#define DISABLE_PROGRAM 1679
#define DISABLE_ALL 1680
#define BUTTONS 1681
#define CHECK_MENUITEM 1682
#define DISABLE_FORM 1683
#define DISABLE_MENUITEMS 1684
#define DISABLE 1685
#define ENABLE_FORM 1686
#define ENABLE_MENUITEMS 1687
#define ENABLE 1688
#define KWFIELD 1689
#define ICON 1690
#define MESSAGEBOX 1691
#define TO_DEFAULTS 1692
#define UNCHECK_MENUITEM 1693
#define BEFORE 1694
#define INPUT 1695
#define END 1696
#define INT_TO_ID 1697
#define TIMEOUT 1698
#define OFF 1699
#define WITH_1_DIMENSION 1700
#define WITH_2_DIMENSION 1701
#define WITH_3_DIMENSION 1702
#define TILDE 1703
#define ILIKE 1704
#define FGL_ISDYNARR_ALLOCATED 1705
#define FGL_DYNARR_EXTENTSIZE 1706
#define FILLFACTOR 1707




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
#line 1700 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1712 "y.tab.c"

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
#define YYLAST   10806

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  724
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  865
/* YYNRULES -- Number of rules. */
#define YYNRULES  2357
/* YYNRULES -- Number of states. */
#define YYNSTATES  3765

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1721

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,    15,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,    16,   436,   437,   438,   439,   440,   441,    23,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,    10,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,    13,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,    17,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,    12,
     558,   559,   560,    11,    20,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,     8,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,    21,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,    14,   629,   630,   631,   632,
       7,   633,   634,   635,   636,     5,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,    19,    22,
       9,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,    18,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,     6,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,     2,     3,
       4,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34
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
     371,   373,   375,   378,   380,   382,   385,   387,   389,   390,
     391,   397,   405,   414,   415,   418,   420,   424,   426,   430,
     434,   436,   439,   440,   445,   446,   451,   452,   456,   457,
     461,   462,   466,   468,   472,   474,   478,   480,   482,   484,
     486,   488,   490,   495,   496,   501,   503,   505,   506,   508,
     510,   513,   514,   515,   521,   523,   525,   529,   530,   533,
     538,   543,   548,   553,   556,   557,   562,   564,   566,   568,
     571,   573,   575,   579,   580,   582,   583,   585,   587,   589,
     590,   598,   599,   605,   606,   619,   621,   623,   625,   627,
     629,   635,   639,   641,   643,   644,   649,   650,   656,   657,
     665,   667,   671,   673,   675,   676,   678,   679,   680,   685,
     687,   689,   691,   693,   698,   703,   708,   715,   720,   727,
     729,   732,   734,   736,   738,   740,   745,   752,   754,   759,
     766,   767,   771,   772,   776,   777,   781,   783,   785,   787,
     789,   791,   794,   797,   799,   801,   802,   806,   811,   813,
     815,   816,   820,   824,   825,   828,   830,   832,   834,   836,
     838,   840,   843,   844,   847,   848,   852,   853,   857,   859,
     860,   864,   866,   868,   870,   872,   874,   876,   879,   881,
     882,   884,   885,   891,   893,   895,   897,   902,   907,   914,
     916,   918,   920,   922,   927,   934,   936,   941,   948,   950,
     952,   954,   956,   958,   961,   964,   966,   971,   972,   980,
     981,   994,   995,  1000,  1001,  1007,  1009,  1013,  1016,  1018,
    1022,  1024,  1025,  1028,  1031,  1033,  1036,  1042,  1047,  1050,
    1055,  1061,  1065,  1066,  1067,  1079,  1080,  1083,  1085,  1086,
    1089,  1091,  1093,  1096,  1097,  1101,  1102,  1106,  1107,  1111,
    1114,  1117,  1120,  1125,  1131,  1133,  1135,  1137,  1139,  1141,
    1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,
    1163,  1165,  1167,  1170,  1172,  1174,  1176,  1178,  1181,  1183,
    1185,  1187,  1190,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1211,  1213,  1216,  1218,  1221,  1223,  1225,  1227,
    1231,  1233,  1237,  1239,  1243,  1245,  1247,  1249,  1252,  1254,
    1256,  1260,  1265,  1270,  1273,  1276,  1278,  1280,  1282,  1284,
    1286,  1290,  1292,  1295,  1298,  1300,  1301,  1305,  1308,  1311,
    1313,  1317,  1322,  1327,  1333,  1339,  1341,  1343,  1346,  1349,
    1354,  1359,  1362,  1365,  1370,  1375,  1377,  1380,  1383,  1386,
    1389,  1392,  1395,  1398,  1401,  1404,  1407,  1410,  1413,  1416,
    1419,  1420,  1421,  1422,  1429,  1430,  1431,  1440,  1441,  1442,
    1449,  1450,  1451,  1458,  1459,  1460,  1467,  1468,  1469,  1476,
    1482,  1488,  1494,  1502,  1510,  1520,  1525,  1532,  1533,  1537,
    1539,  1541,  1546,  1551,  1556,  1561,  1566,  1571,  1573,  1575,
    1577,  1579,  1584,  1589,  1592,  1595,  1598,  1601,  1604,  1606,
    1608,  1611,  1613,  1615,  1617,  1620,  1625,  1632,  1639,  1643,
    1649,  1655,  1659,  1661,  1663,  1667,  1669,  1673,  1675,  1679,
    1680,  1681,  1693,  1694,  1697,  1698,  1699,  1700,  1710,  1711,
    1715,  1716,  1717,  1728,  1729,  1731,  1732,  1734,  1736,  1739,
    1740,  1744,  1745,  1749,  1750,  1752,  1754,  1757,  1758,  1762,
    1763,  1767,  1771,  1773,  1778,  1782,  1784,  1788,  1790,  1794,
    1796,  1800,  1802,  1805,  1806,  1810,  1811,  1815,  1816,  1821,
    1822,  1827,  1828,  1833,  1836,  1840,  1842,  1846,  1848,  1850,
    1852,  1854,  1856,  1858,  1860,  1864,  1866,  1868,  1873,  1880,
    1885,  1889,  1896,  1900,  1907,  1909,  1911,  1913,  1915,  1917,
    1919,  1921,  1923,  1924,  1927,  1929,  1931,  1933,  1938,  1940,
    1942,  1944,  1949,  1953,  1960,  1964,  1971,  1973,  1975,  1978,
    1981,  1983,  1986,  1989,  1991,  1995,  1997,  2000,  2003,  2006,
    2011,  2014,  2017,  2022,  2023,  2032,  2033,  2035,  2037,  2039,
    2040,  2042,  2045,  2046,  2048,  2051,  2052,  2054,  2057,  2058,
    2060,  2064,  2065,  2068,  2069,  2070,  2079,  2080,  2081,  2085,
    2086,  2087,  2095,  2101,  2104,  2107,  2108,  2114,  2119,  2121,
    2125,  2129,  2133,  2135,  2136,  2139,  2141,  2142,  2144,  2146,
    2149,  2150,  2155,  2156,  2161,  2162,  2166,  2167,  2171,  2172,
    2176,  2177,  2181,  2182,  2186,  2187,  2191,  2192,  2196,  2197,
    2201,  2202,  2206,  2207,  2211,  2212,  2216,  2218,  2222,  2224,
    2228,  2231,  2236,  2238,  2240,  2242,  2243,  2248,  2254,  2261,
    2262,  2273,  2277,  2280,  2283,  2285,  2287,  2288,  2291,  2293,
    2296,  2300,  2304,  2308,  2312,  2314,  2316,  2318,  2320,  2321,
    2325,  2327,  2328,  2332,  2335,  2338,  2340,  2344,  2346,  2350,
    2352,  2354,  2356,  2358,  2360,  2362,  2364,  2366,  2368,  2370,
    2372,  2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,
    2391,  2392,  2400,  2402,  2404,  2407,  2410,  2413,  2417,  2422,
    2423,  2427,  2428,  2430,  2432,  2435,  2437,  2439,  2441,  2443,
    2445,  2447,  2448,  2450,  2452,  2455,  2458,  2460,  2462,  2464,
    2466,  2468,  2470,  2472,  2474,  2476,  2478,  2480,  2482,  2483,
    2485,  2487,  2489,  2491,  2492,  2493,  2494,  2495,  2509,  2511,
    2512,  2513,  2520,  2523,  2525,  2528,  2531,  2534,  2536,  2538,
    2541,  2543,  2544,  2548,  2551,  2553,  2555,  2557,  2558,  2559,
    2560,  2575,  2576,  2582,  2584,  2585,  2589,  2590,  2598,  2599,
    2605,  2607,  2610,  2611,  2613,  2615,  2617,  2618,  2620,  2622,
    2625,  2628,  2631,  2633,  2635,  2637,  2639,  2643,  2645,  2647,
    2648,  2649,  2657,  2659,  2662,  2663,  2667,  2668,  2673,  2676,
    2677,  2680,  2682,  2684,  2686,  2688,  2690,  2692,  2694,  2698,
    2699,  2701,  2703,  2705,  2707,  2710,  2713,  2716,  2722,  2731,
    2733,  2735,  2737,  2742,  2747,  2749,  2751,  2753,  2755,  2758,
    2762,  2769,  2771,  2775,  2777,  2779,  2781,  2785,  2792,  2802,
    2804,  2806,  2808,  2810,  2813,  2814,  2816,  2818,  2822,  2824,
    2828,  2830,  2834,  2836,  2840,  2842,  2844,  2846,  2848,  2852,
    2854,  2858,  2860,  2864,  2866,  2868,  2870,  2874,  2877,  2878,
    2880,  2882,  2884,  2888,  2890,  2894,  2902,  2903,  2911,  2912,
    2919,  2923,  2925,  2929,  2931,  2934,  2940,  2941,  2949,  2950,
    2953,  2954,  2956,  2962,  2965,  2971,  2972,  2978,  2985,  2990,
    2991,  2993,  2995,  3001,  3002,  3005,  3006,  3012,  3017,  3020,
    3022,  3026,  3029,  3032,  3035,  3038,  3041,  3044,  3046,  3049,
    3052,  3055,  3058,  3061,  3064,  3067,  3069,  3071,  3073,  3075,
    3078,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3099,  3101,
    3103,  3106,  3111,  3116,  3123,  3126,  3128,  3129,  3141,  3142,
    3145,  3151,  3152,  3154,  3155,  3158,  3160,  3163,  3164,  3168,
    3170,  3171,  3176,  3177,  3180,  3182,  3186,  3188,  3190,  3194,
    3199,  3204,  3207,  3209,  3211,  3213,  3214,  3216,  3224,  3227,
    3230,  3233,  3236,  3239,  3241,  3244,  3245,  3249,  3250,  3254,
    3255,  3259,  3260,  3264,  3265,  3269,  3270,  3275,  3276,  3281,
    3283,  3285,  3287,  3289,  3291,  3293,  3294,  3299,  3300,  3302,
    3303,  3308,  3310,  3313,  3316,  3319,  3320,  3322,  3324,  3327,
    3330,  3331,  3334,  3335,  3340,  3344,  3350,  3351,  3354,  3359,
    3361,  3363,  3365,  3367,  3369,  3370,  3372,  3374,  3378,  3381,
    3387,  3390,  3396,  3402,  3408,  3414,  3420,  3426,  3427,  3430,
    3432,  3435,  3438,  3441,  3444,  3447,  3450,  3452,  3455,  3458,
    3461,  3464,  3466,  3469,  3472,  3475,  3478,  3480,  3482,  3484,
    3485,  3488,  3491,  3494,  3497,  3500,  3503,  3506,  3509,  3512,
    3514,  3516,  3518,  3520,  3522,  3524,  3526,  3528,  3531,  3534,
    3537,  3540,  3543,  3545,  3547,  3549,  3550,  3554,  3557,  3558,
    3559,  3560,  3561,  3562,  3563,  3579,  3580,  3583,  3586,  3587,
    3589,  3590,  3591,  3592,  3593,  3594,  3595,  3611,  3614,  3615,
    3616,  3617,  3628,  3629,  3631,  3635,  3639,  3642,  3647,  3651,
    3655,  3659,  3661,  3664,  3667,  3670,  3673,  3675,  3677,  3678,
    3679,  3688,  3689,  3690,  3700,  3701,  3703,  3705,  3708,  3711,
    3714,  3717,  3719,  3721,  3723,  3724,  3726,  3728,  3731,  3734,
    3737,  3746,  3749,  3752,  3757,  3760,  3761,  3763,  3765,  3769,
    3772,  3775,  3777,  3779,  3783,  3785,  3787,  3790,  3792,  3796,
    3800,  3804,  3806,  3810,  3812,  3814,  3816,  3818,  3820,  3822,
    3824,  3827,  3832,  3834,  3838,  3840,  3844,  3847,  3852,  3854,
    3858,  3860,  3863,  3868,  3870,  3874,  3876,  3878,  3880,  3883,
    3887,  3892,  3895,  3900,  3901,  3904,  3907,  3912,  3914,  3918,
    3920,  3922,  3924,  3927,  3929,  3931,  3933,  3935,  3937,  3940,
    3947,  3954,  3955,  3957,  3958,  3960,  3963,  3965,  3966,  3972,
    3973,  3979,  3981,  3982,  3986,  3988,  3992,  3994,  3998,  4000,
    4002,  4003,  4008,  4010,  4013,  4015,  4016,  4017,  4021,  4022,
    4023,  4027,  4029,  4031,  4033,  4035,  4037,  4039,  4042,  4045,
    4050,  4054,  4058,  4060,  4064,  4067,  4069,  4071,  4072,  4074,
    4076,  4078,  4080,  4081,  4083,  4087,  4089,  4093,  4095,  4096,
    4100,  4102,  4104,  4106,  4108,  4110,  4112,  4114,  4116,  4118,
    4120,  4122,  4124,  4132,  4139,  4144,  4149,  4151,  4153,  4155,
    4156,  4158,  4161,  4163,  4165,  4167,  4169,  4173,  4176,  4178,
    4180,  4183,  4185,  4187,  4188,  4192,  4194,  4198,  4200,  4204,
    4206,  4208,  4215,  4216,  4220,  4222,  4226,  4227,  4229,  4234,
    4240,  4243,  4245,  4247,  4252,  4254,  4258,  4263,  4268,  4273,
    4275,  4279,  4281,  4283,  4285,  4288,  4290,  4292,  4294,  4299,
    4300,  4302,  4303,  4305,  4307,  4310,  4313,  4315,  4317,  4319,
    4321,  4323,  4328,  4330,  4334,  4336,  4338,  4340,  4343,  4345,
    4347,  4350,  4353,  4355,  4359,  4362,  4365,  4367,  4371,  4373,
    4376,  4381,  4383,  4386,  4388,  4392,  4397,  4398,  4400,  4401,
    4403,  4404,  4406,  4408,  4412,  4414,  4418,  4420,  4423,  4425,
    4429,  4432,  4435,  4436,  4439,  4441,  4443,  4449,  4453,  4459,
    4463,  4465,  4469,  4471,  4473,  4474,  4476,  4480,  4484,  4488,
    4495,  4500,  4505,  4510,  4515,  4521,  4523,  4525,  4527,  4529,
    4531,  4533,  4535,  4537,  4539,  4541,  4543,  4545,  4546,  4548,
    4550,  4552,  4554,  4556,  4558,  4560,  4565,  4566,  4568,  4573,
    4575,  4581,  4587,  4589,  4591,  4593,  4595,  4597,  4602,  4604,
    4609,  4616,  4621,  4623,  4628,  4630,  4638,  4640,  4642,  4644,
    4649,  4656,  4657,  4660,  4665,  4667,  4669,  4671,  4673,  4675,
    4677,  4679,  4683,  4685,  4687,  4691,  4697,  4701,  4707,  4715,
    4719,  4721,  4723,  4727,  4733,  4737,  4743,  4751,  4753,  4754,
    4758,  4764,  4766,  4769,  4772,  4777,  4781,  4783,  4785,  4787,
    4789,  4791,  4794,  4797,  4798,  4802,  4803,  4807,  4809,  4811,
    4813,  4815,  4817,  4819,  4821,  4826,  4828,  4830,  4832,  4834,
    4836,  4838,  4840,  4845,  4847,  4849,  4851,  4853,  4855,  4857,
    4859,  4861,  4863,  4865,  4867,  4869,  4871,  4873,  4878,  4880,
    4884,  4886,  4890,  4891,  4899,  4900,  4909,  4910,  4917,  4918,
    4927,  4928,  4930,  4933,  4935,  4939,  4941,  4945,  4951,  4953,
    4955,  4957,  4959,  4961,  4962,  4963,  4973,  4979,  4981,  4983,
    4990,  4991,  4995,  4997,  5001,  5006,  5008,  5009,  5012,  5017,
    5024,  5025,  5027,  5029,  5031,  5033,  5037,  5039,  5042,  5046,
    5048,  5050,  5053,  5056,  5058,  5060,  5062,  5065,  5068,  5071,
    5074,  5079,  5083,  5086,  5090,  5094,  5098,  5100,  5102,  5104,
    5106,  5108,  5110,  5116,  5122,  5128,  5134,  5140,  5145,  5150,
    5154,  5159,  5161,  5163,  5165,  5169,  5171,  5177,  5185,  5191,
    5192,  5195,  5197,  5199,  5200,  5204,  5206,  5210,  5212,  5214,
    5216,  5217,  5221,  5223,  5225,  5227,  5229,  5234,  5241,  5243,
    5245,  5248,  5252,  5254,  5256,  5258,  5260,  5262,  5264,  5266,
    5268,  5274,  5280,  5285,  5291,  5293,  5298,  5303,  5308,  5315,
    5322,  5331,  5340,  5354,  5366,  5368,  5376,  5381,  5386,  5391,
    5398,  5405,  5414,  5423,  5424,  5429,  5431,  5434,  5436,  5438,
    5440,  5442,  5444,  5446,  5448,  5450,  5452,  5454,  5456,  5458,
    5460,  5462,  5464,  5466,  5468,  5470,  5472,  5474,  5476,  5478,
    5480,  5482,  5484,  5486,  5488,  5490,  5492,  5494,  5496,  5498,
    5500,  5502,  5504,  5506,  5508,  5510,  5512,  5514,  5516,  5518,
    5520,  5522,  5524,  5526,  5528,  5530,  5532,  5534,  5536,  5538,
    5540,  5542,  5544,  5546,  5548,  5550,  5552,  5554,  5556,  5558,
    5560,  5562,  5564,  5566,  5568,  5570,  5572,  5574,  5576,  5578,
    5580,  5582,  5584,  5586,  5588,  5590,  5592,  5594,  5596,  5598,
    5600,  5602,  5604,  5606,  5608,  5610,  5612,  5614,  5616,  5618,
    5620,  5622,  5624,  5626,  5628,  5630,  5632,  5634,  5636,  5638,
    5640,  5642,  5644,  5646,  5648,  5650,  5652,  5654,  5656,  5658,
    5660,  5662,  5664,  5666,  5668,  5670,  5672,  5674,  5676,  5678,
    5680,  5682,  5684,  5686,  5688,  5690,  5692,  5694,  5696,  5698,
    5700,  5702,  5704,  5706,  5708,  5710,  5712,  5714,  5716,  5718,
    5720,  5722,  5724,  5726,  5728,  5730,  5732,  5734,  5736,  5738,
    5740,  5742,  5744,  5746,  5748,  5750,  5752,  5754,  5756,  5758,
    5760,  5762,  5764,  5766,  5768,  5770,  5772,  5774,  5776,  5778,
    5780,  5782,  5784,  5786,  5788,  5790,  5792,  5794,  5796,  5798,
    5800,  5802,  5804,  5806,  5808,  5810,  5812,  5814,  5816,  5818,
    5820,  5822,  5824,  5826,  5828,  5830,  5832,  5834,  5836,  5838,
    5840,  5842,  5844,  5846,  5848,  5850,  5852,  5854,  5856,  5858,
    5860,  5862,  5864,  5866,  5868,  5870,  5872,  5874,  5876,  5878,
    5880,  5882,  5884,  5886,  5888,  5890,  5892,  5894,  5896,  5898,
    5900,  5902,  5904,  5906,  5908,  5910,  5912,  5914,  5916,  5918,
    5920,  5922,  5924,  5926,  5928,  5930,  5932,  5934,  5936,  5938,
    5940,  5942,  5944,  5946,  5948,  5950,  5952,  5954,  5956,  5958,
    5960,  5962,  5964,  5966,  5968,  5970,  5972,  5974,  5976,  5978,
    5980,  5982,  5984,  5986,  5988,  5990,  5992,  5994,  5996,  5998,
    6000,  6002,  6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,
    6020,  6022,  6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,
    6040,  6042,  6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,
    6060,  6062,  6064,  6066,  6068,  6070,  6072,  6073,  6077,  6078,
    6082,  6083,  6084,  6091,  6092,  6095,  6098,  6106,  6110,  6114,
    6117,  6120,  6123,  6125,  6129,  6131,  6135,  6137,  6141,  6143,
    6147,  6149,  6151,  6153,  6156,  6159,  6161,  6163,  6166,  6171,
    6177,  6185,  6193,  6203,  6205,  6207,  6209,  6211,  6213,  6215,
    6219,  6222,  6226,  6230,  6234,  6240,  6246,  6252,  6258,  6264,
    6269,  6274,  6278,  6283,  6285,  6287,  6289,  6291,  6295,  6296,
    6302,  6304,  6308,  6312,  6316,  6318,  6320,  6323,  6325,  6327,
    6331,  6333,  6337,  6341,  6343,  6345,  6347,  6351,  6354,  6358,
    6365,  6367,  6371,  6373,  6375,  6376,  6377,  6384,  6385,  6388,
    6389,  6391,  6393,  6396,  6399,  6401,  6403,  6408,  6412,  6414,
    6417,  6423,  6426,  6429,  6435,  6436,  6439,  6441,  6443,  6446,
    6453,  6460,  6462,  6463,  6465,  6468,  6470,  6473,  6474,  6477,
    6479,  6481,  6483,  6485,  6487,  6489,  6491,  6493,  6495,  6497,
    6499,  6501,  6503,  6505,  6507,  6509,  6511,  6513,  6515,  6517,
    6519,  6521,  6523,  6525,  6527,  6529,  6531,  6533,  6535,  6537,
    6539,  6541,  6543,  6545,  6547,  6549,  6551,  6553,  6555,  6557,
    6559,  6561,  6563,  6565,  6567,  6569,  6571,  6573,  6575,  6577,
    6579,  6581,  6583,  6585,  6587,  6589,  6591,  6593,  6595,  6597,
    6599,  6601,  6603,  6605,  6607,  6609,  6611,  6613,  6615,  6617,
    6619,  6621,  6623,  6625,  6627,  6629,  6631,  6633,  6635,  6637,
    6639,  6641,  6643,  6645,  6647,  6649,  6651,  6653
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1097,     0,    -1,   247,    -1,   244,    -1,   178,   729,   474,
     642,   730,    -1,   189,    -1,  1162,    -1,    26,    -1,   731,
      -1,   730,     5,   731,    -1,  1005,    -1,   478,   732,   440,
      -1,   732,   733,   732,    -1,    26,    -1,   734,    26,    -1,
    1162,    -1,   945,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   736,
      -1,    -1,   322,   478,   737,   738,   440,    -1,   615,   478,
      26,     5,    26,   440,    -1,   739,    -1,   738,     5,   739,
      -1,   537,    -1,   578,    -1,   583,    -1,   553,    -1,   458,
      -1,   651,    -1,   575,    -1,   527,    -1,   464,    -1,   538,
      -1,   395,    -1,   579,    -1,   503,    -1,   382,    -1,   640,
      -1,   145,    -1,  1076,    -1,    -1,   741,    -1,    -1,   322,
     478,   742,   743,   440,    -1,   744,    -1,   743,     5,   744,
      -1,   739,    -1,   479,    -1,   649,    25,    -1,   250,   991,
      -1,   379,   991,    -1,   332,   991,    -1,   387,   991,    -1,
     341,   991,    -1,   307,   991,    -1,   581,   746,    -1,   934,
     394,  1162,    -1,    -1,   337,   478,   953,   440,   394,   747,
    1180,    -1,   153,   478,  1005,     5,    25,     5,    25,   440,
      -1,   455,   478,   997,   440,   394,  1162,    -1,  1299,    -1,
     240,   478,   953,   440,   394,  1162,    -1,    -1,    -1,  1162,
     636,  1005,   478,   748,   762,   440,   749,   760,    -1,    -1,
      -1,    -1,  1005,   478,   750,   762,   751,   440,   752,   760,
      -1,    -1,    -1,   521,  1508,   669,  1508,   478,   753,   762,
     754,   440,   760,    -1,    -1,    -1,  1005,   568,  1005,   478,
     755,   762,   756,   440,   760,    -1,    -1,    -1,    -1,   414,
     765,   636,   766,   506,   729,   474,   478,   757,   762,   758,
     440,   759,   761,    -1,    -1,   394,  1180,    -1,    -1,   394,
    1180,    -1,   211,    -1,    -1,   763,    -1,   764,    -1,   763,
       5,   764,    -1,   903,    -1,   530,    -1,    25,    -1,  1005,
      -1,  1005,    -1,  1005,   666,  1005,    -1,    -1,   582,   910,
     768,   771,   775,   772,    -1,    -1,   582,   769,   770,   773,
     772,    -1,   777,    -1,   770,   777,    -1,   779,    -1,   771,
     779,    -1,   409,    -1,    -1,    -1,   389,   774,  1583,    -1,
      -1,    -1,   389,   776,  1583,    -1,    -1,   625,   910,   778,
    1583,    -1,    -1,   625,   910,   780,  1583,    -1,   326,  1002,
      -1,   249,  1000,    -1,   131,  1000,    -1,   216,    -1,   233,
    1514,    -1,   541,   999,    -1,    30,   783,    31,    -1,   784,
      -1,   786,    -1,   785,    -1,   784,   785,    -1,    29,    -1,
     787,    -1,   786,   787,    -1,    28,    -1,   442,    -1,    -1,
      -1,   370,   790,   792,   791,   793,    -1,   433,  1162,   671,
     794,  1048,  1075,   735,    -1,  1162,   671,   794,  1048,   593,
     953,  1075,   735,    -1,    -1,   796,   239,    -1,   795,    -1,
     794,     5,   795,    -1,  1005,    -1,  1005,   666,  1005,    -1,
    1005,   666,    20,    -1,   797,    -1,   796,   797,    -1,    -1,
     318,   803,   798,  1583,    -1,    -1,   321,   804,   799,  1583,
      -1,    -1,  1078,   800,  1583,    -1,    -1,   214,   801,  1583,
      -1,    -1,   212,   802,  1583,    -1,  1009,    -1,   803,     5,
    1009,    -1,  1009,    -1,   804,     5,  1009,    -1,   139,    -1,
     140,    -1,   141,    -1,   142,    -1,   143,    -1,   144,    -1,
     478,   903,   807,   440,    -1,    -1,     5,   854,   672,   857,
      -1,   204,    -1,   327,    -1,    -1,   810,    -1,   811,    -1,
     810,   811,    -1,    -1,    -1,   485,   812,   814,   813,  1268,
      -1,   867,    -1,   817,    -1,   814,     5,   817,    -1,    -1,
     816,  1005,    -1,   403,   815,   866,    25,    -1,   403,   815,
     866,  1005,    -1,   403,   815,   866,  1011,    -1,   403,   815,
     866,    26,    -1,   821,   839,    -1,    -1,   815,   403,   818,
     819,    -1,    26,    -1,    25,    -1,  1011,    -1,    19,    26,
      -1,   815,    -1,   820,    -1,   821,     5,   820,    -1,    -1,
     367,    -1,    -1,   716,    -1,   717,    -1,   718,    -1,    -1,
     534,   506,   831,   474,   825,   670,   839,    -1,    -1,    35,
     823,   826,   670,   839,    -1,    -1,   366,   822,   828,    26,
     829,   350,   506,   830,   474,   827,   670,   839,    -1,   478,
      -1,   505,    -1,   440,    -1,   473,    -1,    26,    -1,   832,
       5,   832,     5,   832,    -1,   832,     5,   832,    -1,   832,
      -1,    26,    -1,    -1,   511,   834,   814,   331,    -1,    -1,
     308,   835,   815,   666,    20,    -1,    -1,   384,   836,   815,
     306,   478,   837,   440,    -1,   838,    -1,   837,     5,   838,
      -1,   815,    -1,   841,    -1,    -1,   106,    -1,    -1,    -1,
     842,   844,   843,   840,    -1,   824,    -1,   833,    -1,   367,
      -1,   368,    -1,   367,   478,    26,   440,    -1,   368,   478,
      26,   440,    -1,   471,   478,    26,   440,    -1,   471,   478,
      26,     5,    26,   440,    -1,   369,   478,    26,   440,    -1,
     369,   478,    26,     5,    26,   440,    -1,   456,    -1,   663,
     815,    -1,   429,    -1,   556,    -1,   137,    -1,   446,    -1,
     446,   478,    26,   440,    -1,   446,   478,    26,     5,    26,
     440,    -1,   559,    -1,   559,   478,    26,   440,    -1,   559,
     478,    26,     5,    26,   440,    -1,    -1,   549,   845,   848,
      -1,    -1,   111,   846,   848,    -1,    -1,   347,   847,   848,
      -1,   584,    -1,   580,    -1,   127,    -1,   128,    -1,   621,
      -1,   406,   852,    -1,   418,   853,    -1,   849,    -1,    32,
      -1,    -1,   478,    26,   440,    -1,   603,   850,   666,   851,
      -1,   815,    -1,   815,    -1,    -1,   854,   672,   857,    -1,
     862,   672,   865,    -1,    -1,   855,   856,    -1,   628,    -1,
     560,    -1,   637,    -1,   599,    -1,   501,    -1,   517,    -1,
     415,   859,    -1,    -1,   858,   856,    -1,    -1,   478,   861,
     440,    -1,    -1,   478,    26,   440,    -1,    26,    -1,    -1,
     863,   864,   860,    -1,   628,    -1,   560,    -1,   637,    -1,
     599,    -1,   501,    -1,   517,    -1,   415,   859,    -1,   864,
      -1,    -1,    14,    -1,    -1,   284,  1005,   868,   663,   869,
      -1,   871,    -1,   874,    -1,   367,    -1,   367,   478,    26,
     440,    -1,   471,   478,    26,   440,    -1,   471,   478,    26,
       5,    26,   440,    -1,   456,    -1,   429,    -1,   556,    -1,
     446,    -1,   446,   478,    26,   440,    -1,   446,   478,    26,
       5,    26,   440,    -1,   559,    -1,   559,   478,    26,   440,
      -1,   559,   478,    26,     5,    26,   440,    -1,   549,    -1,
     347,    -1,   584,    -1,   580,    -1,   621,    -1,   406,   852,
      -1,   418,   853,    -1,   870,    -1,   603,   850,   666,   851,
      -1,    -1,   534,   506,   831,   474,   872,   670,   869,    -1,
      -1,   366,   822,   828,    26,   829,   350,   506,   830,   474,
     873,   670,   869,    -1,    -1,   511,   875,   877,   331,    -1,
      -1,   308,   876,  1005,   666,    20,    -1,   878,    -1,   877,
       5,   878,    -1,   879,   869,    -1,   880,    -1,   879,     5,
     880,    -1,  1005,    -1,    -1,   664,   995,    -1,   118,  1005,
      -1,   116,    -1,   672,   953,    -1,   672,   556,  1005,   705,
     953,    -1,   672,   556,  1005,   438,    -1,   120,  1005,    -1,
     205,   928,  1180,   889,    -1,   449,   928,   908,   881,   889,
      -1,   258,  1002,   889,    -1,    -1,    -1,   236,   886,  1187,
     672,  1005,   666,    20,   888,   735,   887,   890,    -1,    -1,
     515,   996,    -1,   735,    -1,    -1,   891,   286,    -1,   286,
      -1,   892,    -1,   891,   892,    -1,    -1,   401,   893,  1583,
      -1,    -1,   397,   894,  1583,    -1,    -1,  1078,   895,  1583,
      -1,    37,  1162,    -1,    38,  1162,    -1,    36,  1162,    -1,
     545,   928,   909,   735,    -1,   545,   928,   909,   735,   113,
      -1,   334,    -1,   333,    -1,   261,    -1,   413,    -1,   221,
      -1,   260,    -1,   378,    -1,   377,    -1,   291,    -1,   218,
      -1,   217,    -1,   195,    -1,   251,    -1,   179,    -1,   194,
      -1,   235,    -1,   202,    -1,   262,    -1,   262,   910,    -1,
     913,    -1,   912,    -1,   917,    -1,   945,    -1,   903,   904,
      -1,   946,    -1,   948,    -1,   914,    -1,    19,   903,    -1,
      18,   903,    -1,   919,    -1,   927,    -1,   921,    -1,   522,
      -1,   805,    -1,   922,    -1,   923,    -1,   924,    -1,   925,
      -1,   926,    -1,    42,   903,    -1,   928,    -1,   928,   907,
      -1,   910,    -1,   530,    -1,   906,    -1,   907,     5,   906,
      -1,   910,    -1,   908,     5,   910,    -1,   910,    -1,   909,
       5,   910,    -1,   903,    -1,    18,    -1,    19,    -1,     9,
     903,    -1,   531,    -1,   475,    -1,   478,   903,   440,    -1,
     490,   478,  1488,   440,    -1,   342,   478,  1488,   440,    -1,
     911,  1011,    -1,   911,    26,    -1,    25,    -1,  1011,    -1,
      26,    -1,   916,    -1,  1162,    -1,  1162,   468,  1162,    -1,
     915,    -1,   481,   903,    -1,   441,   903,    -1,  1271,    -1,
      -1,   554,   918,  1271,    -1,     7,   903,    -1,     6,   903,
      -1,   903,    -1,   920,     5,   903,    -1,   669,   478,  1488,
     440,    -1,   476,   478,  1488,   440,    -1,   669,   478,   928,
     920,   440,    -1,   476,   478,   928,   920,   440,    -1,   435,
      -1,   297,    -1,    10,   903,    -1,   300,   903,    -1,    10,
     903,   489,    25,    -1,   300,   903,   489,    25,    -1,   603,
     903,    -1,   420,   903,    -1,   603,   903,   489,    25,    -1,
     420,   903,   489,    25,    -1,   439,    -1,     8,   903,    -1,
      18,   903,    -1,    19,   903,    -1,    20,   903,    -1,    21,
     903,    -1,    22,   903,    -1,    11,   903,    -1,    14,   903,
      -1,   504,   903,    -1,    12,   903,    -1,    13,   903,    -1,
      17,   903,    -1,    16,   903,    -1,    15,   903,    -1,    -1,
      -1,    -1,  1005,   478,   930,   762,   931,   440,    -1,    -1,
      -1,  1005,   568,  1005,   478,   932,   762,   933,   440,    -1,
      -1,    -1,   584,   478,   935,   903,   936,   440,    -1,    -1,
      -1,   560,   478,   937,   903,   938,   440,    -1,    -1,    -1,
     637,   478,   939,   903,   940,   440,    -1,    -1,    -1,   628,
     478,   941,   903,   942,   440,    -1,   418,   478,   949,   440,
     944,    -1,   406,   478,    25,   440,   943,    -1,   406,   478,
      26,   440,   943,    -1,   406,   478,    26,   636,    26,   440,
     943,    -1,   406,   478,    26,    19,    26,   440,   943,    -1,
     406,   478,    26,    19,    26,    19,    26,   440,   943,    -1,
     721,   478,  1162,   440,    -1,   722,   478,  1162,     5,    26,
     440,    -1,    -1,  1468,   672,  1469,    -1,   853,    -1,   934,
      -1,   337,   478,   953,   440,    -1,   146,   478,   996,   440,
      -1,   119,   478,   996,   440,    -1,   455,   478,   954,   440,
      -1,   240,   478,   953,   440,    -1,   107,   478,   953,   440,
      -1,   947,    -1,   929,    -1,  1464,    -1,   584,    -1,   470,
     478,   903,   440,    -1,   372,   478,   903,   440,    -1,   535,
     903,    -1,   491,   806,    -1,   903,   157,    -1,   903,   158,
      -1,   903,   159,    -1,    25,    -1,   950,    -1,    19,   950,
      -1,   952,    -1,   951,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   636,    26,    -1,    26,    26,   636,    26,   636,
      26,    -1,    26,    26,   636,    26,   636,    24,    -1,    26,
     636,    26,    -1,    26,   636,    26,   636,    26,    -1,    26,
     636,    26,   636,    24,    -1,    26,   636,    24,    -1,    24,
      -1,    26,    -1,    26,    19,    26,    -1,   996,    -1,   953,
       5,   996,    -1,   997,    -1,   954,     5,   997,    -1,    -1,
      -1,   642,  1162,    14,   910,   672,   910,   958,   956,  1583,
     957,   289,    -1,    -1,   618,   910,    -1,    -1,    -1,    -1,
     452,   960,   999,   961,   963,  1366,   962,  1583,   288,    -1,
      -1,     8,   928,   908,    -1,    -1,    -1,   684,  1005,   965,
     809,   966,  1107,   968,   967,   973,   685,    -1,    -1,   978,
      -1,    -1,   969,    -1,   970,    -1,   969,   970,    -1,    -1,
     686,   971,  1583,    -1,    -1,   687,   972,  1583,    -1,    -1,
     974,    -1,   975,    -1,   974,   975,    -1,    -1,   688,   976,
    1583,    -1,    -1,   689,   977,  1583,    -1,   979,   983,   374,
      -1,   138,    -1,   138,   980,   593,   981,    -1,   138,   433,
     982,    -1,  1162,    -1,   980,     5,  1162,    -1,  1005,    -1,
     981,     5,  1005,    -1,  1162,    -1,   982,     5,  1162,    -1,
     984,    -1,   983,   984,    -1,    -1,   690,   985,  1583,    -1,
      -1,   691,   986,  1583,    -1,    -1,   710,   981,   987,  1583,
      -1,    -1,   528,   981,   988,  1583,    -1,    -1,   671,   981,
     989,  1583,    -1,   592,   998,    -1,   601,    19,    26,    -1,
     601,    -1,   548,    18,    26,    -1,   548,    -1,    26,    -1,
    1162,    -1,   715,    -1,    25,    -1,  1010,    -1,   910,    -1,
     993,     5,   993,    -1,   994,    -1,  1005,    -1,   713,   478,
    1005,   440,    -1,  1005,   666,   713,   478,  1005,   440,    -1,
    1005,   506,   732,   474,    -1,  1005,   666,    20,    -1,  1005,
     506,   732,   474,   666,    20,    -1,  1005,   666,  1005,    -1,
    1005,   506,   732,   474,   666,  1005,    -1,   996,    -1,    25,
      -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,
      -1,  1006,    -1,    -1,   597,    26,    -1,  1582,    -1,  1007,
      -1,  1582,    -1,   399,   478,  1008,   440,    -1,  1165,    -1,
      25,    -1,  1005,    -1,  1005,   506,   732,   474,    -1,  1005,
     666,    20,    -1,  1005,   506,   732,   474,   666,    20,    -1,
    1005,   666,  1005,    -1,  1005,   506,   732,   474,   666,  1005,
      -1,  1162,    -1,    24,    -1,   666,    26,    -1,   594,  1013,
      -1,  1005,    -1,   636,  1005,    -1,   698,  1015,    -1,  1016,
      -1,  1015,     5,  1016,    -1,  1005,    -1,   709,  1015,    -1,
     700,  1015,    -1,   701,   953,    -1,   699,  1002,   705,   953,
      -1,   703,  1015,    -1,   704,   953,    -1,   702,  1002,   705,
     953,    -1,    -1,   707,  1021,   908,  1026,  1028,  1030,  1022,
    1024,    -1,    -1,  1023,    -1,   695,    -1,   696,    -1,    -1,
    1025,    -1,   394,  1162,    -1,    -1,  1027,    -1,   438,   908,
      -1,    -1,  1029,    -1,   706,    26,    -1,    -1,  1031,    -1,
     697,    26,  1032,    -1,    -1,   448,    26,    -1,    -1,    -1,
     668,   910,   622,  1034,  1583,  1035,  1036,   488,    -1,    -1,
      -1,   589,  1037,  1583,    -1,    -1,    -1,   110,  1038,   910,
     622,  1039,  1583,  1036,    -1,   155,  1005,   478,    26,   440,
      -1,   101,  1005,    -1,   123,  1005,    -1,    -1,   338,  1191,
    1043,   672,   530,    -1,   338,  1191,   603,  1044,    -1,  1045,
      -1,  1044,     5,  1045,    -1,  1046,   666,  1460,    -1,  1046,
     666,    20,    -1,  1456,    -1,    -1,  1049,   374,    -1,   374,
      -1,    -1,   199,    -1,  1050,    -1,  1049,  1050,    -1,    -1,
     318,  1064,  1051,  1583,    -1,    -1,   321,  1065,  1052,  1583,
      -1,    -1,   401,  1053,  1583,    -1,    -1,   397,  1054,  1583,
      -1,    -1,  1078,  1055,  1583,    -1,    -1,   353,  1056,  1583,
      -1,    -1,   323,  1057,  1583,    -1,    -1,    43,  1058,  1583,
      -1,    -1,    41,  1059,  1583,    -1,    -1,    40,  1060,  1583,
      -1,    -1,    39,  1061,  1583,    -1,    -1,    46,  1062,  1583,
      -1,    -1,    45,  1063,  1583,    -1,   996,    -1,  1064,     5,
     996,    -1,   996,    -1,  1065,     5,   996,    -1,   362,  1068,
      -1,   363,  1005,   705,  1068,    -1,   608,    -1,   424,    -1,
     996,    -1,    -1,   711,  1071,  1070,  1047,    -1,   433,  1180,
    1048,  1004,   735,    -1,  1180,  1048,   593,   953,  1004,   735,
      -1,    -1,   534,  1187,  1048,   593,  1005,   666,    20,  1004,
    1072,   735,    -1,   516,   953,  1074,    -1,   129,    26,    -1,
     130,    26,    -1,   673,    -1,   586,    -1,    -1,   597,    26,
      -1,  1077,    -1,    52,    25,    -1,   543,    14,    26,    -1,
     543,    14,  1162,    -1,    53,    14,    26,    -1,    53,    14,
    1162,    -1,    49,    -1,    51,    -1,    48,    -1,    50,    -1,
      -1,   477,  1079,  1084,    -1,   343,    -1,    -1,   643,  1081,
    1084,    -1,   351,  1086,    -1,   643,  1084,    -1,  1086,    -1,
     478,  1085,   440,    -1,  1086,    -1,  1085,     5,  1086,    -1,
    1087,    -1,   641,    -1,   360,    -1,   380,    -1,   352,    -1,
     532,    -1,   489,    -1,   673,    -1,   597,    -1,   586,    -1,
     225,    -1,   486,    -1,   497,    -1,   587,    -1,   602,    -1,
     567,    -1,   358,    -1,   359,    -1,    25,    -1,   557,    -1,
      -1,    -1,   645,  1090,  1185,  1091,    14,   928,  1092,    -1,
     530,    -1,   909,    -1,   267,  1162,    -1,   257,  1162,    -1,
     270,  1162,    -1,   498,  1183,   383,    -1,   498,  1183,   434,
     992,    -1,    -1,  1099,  1098,  1102,    -1,    -1,  1100,    -1,
    1101,    -1,  1100,  1101,    -1,  1041,    -1,  1106,    -1,  1567,
      -1,  1122,    -1,  1108,    -1,  1121,    -1,    -1,  1103,    -1,
    1105,    -1,  1103,  1105,    -1,   114,  1005,    -1,  1110,    -1,
    1116,    -1,  1128,    -1,  1281,    -1,  1291,    -1,  1149,    -1,
     964,    -1,   782,    -1,  1040,    -1,   788,    -1,  1567,    -1,
     782,    -1,    -1,   782,    -1,   810,    -1,   416,    -1,   108,
      -1,    -1,    -1,    -1,    -1,  1109,  1111,  1005,   478,  1112,
    1178,   440,  1113,   809,  1114,  1107,  1583,  1115,    -1,   259,
      -1,    -1,    -1,   604,  1117,   809,  1118,  1583,   410,    -1,
     225,   905,    -1,   928,    -1,   928,   908,    -1,   405,  1472,
      -1,   514,  1472,    -1,  1123,    -1,  1124,    -1,  1123,  1124,
      -1,  1125,    -1,    -1,   454,  1126,  1127,    -1,   809,   290,
      -1,   992,    -1,  1106,    -1,  1121,    -1,    -1,    -1,    -1,
     162,  1005,   161,  1005,   478,  1129,  1178,   440,  1130,   809,
    1131,  1107,  1583,  1115,    -1,    -1,   605,  1133,  1148,  1139,
    1134,    -1,   411,    -1,    -1,   282,  1136,  1583,    -1,    -1,
      23,  1140,  1141,  1142,  1004,  1137,  1583,    -1,    -1,    23,
    1140,  1004,  1138,  1583,    -1,  1135,    -1,  1139,  1135,    -1,
      -1,  1080,    -1,    25,    -1,  1162,    -1,    -1,  1162,    -1,
      25,    -1,   299,  1146,    -1,   311,  1147,    -1,   294,  1147,
      -1,   632,    -1,    25,    -1,  1162,    -1,  1146,    -1,  1147,
       5,  1146,    -1,  1162,    -1,    25,    -1,    -1,    -1,   692,
    1005,  1150,   809,  1151,  1152,   693,    -1,  1153,    -1,  1152,
    1153,    -1,    -1,   694,  1154,  1583,    -1,    -1,   671,  1005,
    1155,  1583,    -1,  1159,  1157,    -1,    -1,   736,  1160,    -1,
    1161,    -1,  1158,    -1,  1027,    -1,  1029,    -1,  1031,    -1,
    1023,    -1,  1025,    -1,   419,   928,   908,    -1,    -1,   113,
      -1,   113,    -1,  1163,    -1,  1165,    -1,   238,  1165,    -1,
    1165,   666,    -1,  1164,  1169,    -1,  1164,  1005,   506,  1172,
     474,    -1,  1164,  1005,   506,  1172,   474,   506,  1172,   474,
      -1,  1170,    -1,  1005,    -1,  1166,    -1,  1005,   505,  1168,
     473,    -1,  1005,   505,  1168,   473,    -1,  1162,    -1,    25,
      -1,    20,    -1,  1005,    -1,  1005,  1171,    -1,   506,  1172,
     474,    -1,   506,  1172,   474,   506,  1172,   474,    -1,  1173,
      -1,  1172,     5,  1173,    -1,   732,    -1,  1175,    -1,  1177,
      -1,  1175,   666,  1176,    -1,  1175,   666,  1005,   506,  1172,
     474,    -1,  1175,   666,  1005,   506,  1172,   474,   506,  1172,
     474,    -1,  1005,    -1,  1167,    -1,    20,    -1,  1005,    -1,
    1005,  1171,    -1,    -1,  1179,    -1,  1181,    -1,  1179,     5,
    1181,    -1,  1182,    -1,  1180,     5,  1182,    -1,  1005,    -1,
    1005,   666,  1005,    -1,  1162,    -1,  1162,   468,  1162,    -1,
      25,    -1,  1011,    -1,    26,    -1,  1184,    -1,  1183,     5,
    1184,    -1,  1162,    -1,  1162,   468,  1162,    -1,  1186,    -1,
    1185,     5,  1186,    -1,  1174,    -1,  1162,    -1,  1189,    -1,
    1188,     5,  1189,    -1,  1162,  1190,    -1,    -1,   634,    -1,
     585,    -1,  1192,    -1,  1191,     5,  1192,    -1,  1162,    -1,
    1162,   468,  1162,    -1,   302,  1001,   664,   994,   626,  1575,
     740,    -1,    -1,   664,   478,   910,     5,   910,   440,  1195,
      -1,    -1,   615,   478,   910,     5,   910,   440,    -1,   303,
    1005,  1194,    -1,  1005,    -1,   388,  1003,  1199,    -1,  1200,
      -1,   593,   910,    -1,  1201,  1202,  1207,     8,  1197,    -1,
      -1,   664,  1203,   478,   910,     5,   910,   440,    -1,    -1,
     603,  1006,    -1,    -1,   400,    -1,   265,  1514,   314,  1556,
    1206,    -1,   610,   998,    -1,   610,   998,     8,   928,   908,
      -1,    -1,   663,   623,  1508,   423,  1508,    -1,   663,   623,
    1508,     5,   423,  1508,    -1,   663,  1508,     5,  1508,    -1,
      -1,   695,    -1,   696,    -1,   443,   672,  1556,  1209,  1210,
      -1,    -1,   663,  1556,    -1,    -1,   663,   623,  1508,     8,
    1508,    -1,   623,  1508,     8,  1508,    -1,   459,  1212,    -1,
    1213,    -1,  1212,     5,  1213,    -1,   250,   991,    -1,   332,
     991,    -1,   379,   991,    -1,   387,   991,    -1,   341,   991,
      -1,   307,   991,    -1,  1082,    -1,   486,  1083,    -1,   497,
    1083,    -1,   608,  1083,    -1,   424,  1083,    -1,   597,  1083,
      -1,   595,   992,    -1,   596,   992,    -1,    57,    -1,    58,
      -1,    59,    -1,    60,    -1,   449,   736,    -1,   711,   736,
      -1,   339,    -1,   243,    -1,   200,    -1,   180,    -1,   197,
      -1,   188,    -1,  1513,   461,  1217,   593,  1215,    -1,  1162,
      -1,    25,    -1,   451,  1217,    -1,   451,  1217,     8,  1180,
      -1,   451,  1217,   600,  1183,    -1,   451,  1217,   600,  1183,
       8,  1180,    -1,    47,  1215,    -1,  1006,    -1,    -1,   509,
    1227,   735,   642,  1222,  1162,  1220,  1004,   735,  1219,  1223,
      -1,    -1,   714,    26,    -1,   509,  1227,   735,   394,  1162,
      -1,    -1,   367,    -1,    -1,  1224,   330,    -1,  1225,    -1,
    1224,  1225,    -1,    -1,  1078,  1226,  1583,    -1,   909,    -1,
      -1,   650,   998,  1229,  1230,    -1,    -1,   593,  1231,    -1,
    1232,    -1,  1231,     5,  1232,    -1,  1500,    -1,   530,    -1,
     268,  1235,   136,    -1,   268,  1235,   672,  1234,    -1,   268,
    1235,   135,  1234,    -1,   268,  1235,    -1,    25,    -1,  1010,
      -1,  1005,    -1,    -1,   526,    -1,   196,  1235,  1236,   478,
     928,  1120,   440,    -1,   241,  1235,    -1,   115,  1235,    -1,
    1272,  1280,    -1,   494,   109,    -1,   494,  1242,    -1,  1243,
      -1,  1242,  1243,    -1,    -1,   184,  1244,  1583,    -1,    -1,
     246,  1245,  1583,    -1,    -1,   276,  1246,  1583,    -1,    -1,
     264,  1247,  1583,    -1,    -1,   301,  1248,  1583,    -1,    -1,
     248,  1162,  1249,  1583,    -1,    -1,   272,  1162,  1250,  1583,
      -1,  1261,    -1,  1264,    -1,  1263,    -1,  1252,    -1,  1289,
      -1,  1255,    -1,    -1,   607,   910,  1253,   529,    -1,    -1,
     529,    -1,    -1,   616,    26,  1256,  1254,    -1,   207,    -1,
     675,  1276,    -1,   210,  1276,    -1,   209,  1276,    -1,    -1,
    1258,    -1,  1259,    -1,  1258,  1259,    -1,  1269,  1260,    -1,
      -1,   664,  1276,    -1,    -1,   566,  1262,  1257,  1268,    -1,
     565,  1508,  1268,    -1,   564,  1267,  1266,  1265,  1268,    -1,
      -1,   201,   903,    -1,   201,   903,     5,   903,    -1,   659,
      -1,   660,    -1,   661,    -1,   662,    -1,  1162,    -1,    -1,
     569,    -1,  1270,    -1,  1269,     5,  1270,    -1,   910,  1303,
      -1,   655,   478,   903,   440,  1288,    -1,   112,  1288,    -1,
     543,   478,    20,   440,  1288,    -1,   460,   478,    20,   440,
    1288,    -1,   436,   478,   903,   440,  1288,    -1,   635,   478,
     903,   440,  1288,    -1,   648,   478,   903,   440,  1288,    -1,
     647,   478,   903,   440,  1288,    -1,    -1,   508,  1273,    -1,
    1274,    -1,  1273,  1274,    -1,   275,    26,    -1,   266,    26,
      -1,   349,    26,    -1,   232,    26,    -1,   304,    26,    -1,
     223,    -1,   393,    25,    -1,   393,  1162,    -1,   224,    25,
      -1,   208,    25,    -1,  1279,    -1,  1275,  1279,    -1,  1277,
     157,    -1,  1277,   159,    -1,  1277,   158,    -1,  1277,    -1,
    1011,    -1,    26,    -1,    -1,   508,  1275,    -1,   275,  1276,
      -1,   266,  1276,    -1,   349,  1276,    -1,   232,  1276,    -1,
     304,  1276,    -1,   305,  1276,    -1,   674,    25,    -1,   675,
    1276,    -1,   679,    -1,   676,    -1,   677,    -1,   678,    -1,
     683,    -1,   680,    -1,   681,    -1,   682,    -1,   124,  1276,
      -1,   125,  1276,    -1,   126,  1276,    -1,   393,    25,    -1,
     224,    25,    -1,   448,    -1,   121,    -1,   122,    -1,    -1,
     561,   665,  1188,    -1,   185,  1188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   512,  1282,  1005,   478,  1283,  1178,   440,
    1284,   809,  1285,  1240,  1286,  1241,  1287,   287,    -1,    -1,
     573,   903,    -1,   563,  1290,    -1,    -1,  1215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,  1292,  1005,   478,  1293,
    1178,   440,  1294,   809,  1295,  1298,  1296,  1241,  1297,   287,
      -1,  1278,  1280,    -1,    -1,    -1,    -1,   203,   478,    25,
       5,  1300,   762,  1301,   440,  1302,   760,    -1,    -1,   432,
      -1,   432,   266,    26,    -1,   432,   266,  1162,    -1,   653,
     910,    -1,   653,   910,   394,  1162,    -1,   653,   910,   211,
      -1,   653,   910,   624,    -1,   653,   910,   591,    -1,  1306,
      -1,   220,  1456,    -1,   373,  1456,    -1,   329,  1457,    -1,
      44,  1005,    -1,  1320,    -1,  1308,    -1,    -1,    -1,   253,
    1309,  1456,   478,  1310,  1324,   440,  1313,    -1,    -1,    -1,
     182,  1311,  1456,   478,  1312,  1324,   440,  1313,  1321,    -1,
      -1,  1314,    -1,  1315,    -1,  1314,  1315,    -1,   669,  1316,
      -1,   292,    26,    -1,    56,    26,    -1,   133,    -1,   134,
      -1,  1582,    -1,    -1,  1318,    -1,  1319,    -1,  1318,  1319,
      -1,   669,  1316,    -1,   723,    26,    -1,   152,  1457,   671,
    1456,   478,  1322,   440,  1317,    -1,    99,  1006,    -1,   100,
    1006,    -1,   219,  1456,   642,  1456,    -1,   104,  1456,    -1,
      -1,   316,    -1,  1323,    -1,  1322,     5,  1323,    -1,  1005,
     634,    -1,  1005,   585,    -1,  1005,    -1,  1325,    -1,  1324,
       5,  1325,    -1,  1408,    -1,  1406,    -1,   169,  1005,    -1,
     227,    -1,    54,  1005,  1328,    -1,    55,  1457,   149,    -1,
      55,  1457,   150,    -1,  1329,    -1,  1328,     5,  1329,    -1,
    1330,    -1,  1333,    -1,  1336,    -1,  1341,    -1,  1344,    -1,
    1340,    -1,  1339,    -1,   631,  1331,    -1,   631,   478,  1332,
     440,    -1,  1325,    -1,  1325,   710,  1005,    -1,  1331,    -1,
    1332,     5,  1331,    -1,   588,  1335,    -1,   588,   478,  1334,
     440,    -1,  1335,    -1,  1334,     5,  1335,    -1,  1005,    -1,
     502,  1338,    -1,   502,   478,  1337,   440,    -1,  1338,    -1,
    1337,     5,  1338,    -1,  1325,    -1,   133,    -1,   134,    -1,
     132,    26,    -1,   102,  1406,  1343,    -1,   102,   478,  1342,
     440,    -1,  1406,  1343,    -1,  1342,     5,  1406,  1343,    -1,
      -1,   105,  1005,    -1,   103,  1345,    -1,   103,   478,  1345,
     440,    -1,  1346,    -1,  1345,     5,  1346,    -1,  1005,    -1,
     313,    -1,   279,    -1,   213,  1349,    -1,   192,    -1,   181,
      -1,   168,    -1,   166,    -1,   170,    -1,   226,  1514,    -1,
     278,  1348,   507,  1508,   672,  1508,    -1,   346,   998,   507,
    1508,   672,  1508,    -1,    -1,  1514,    -1,    -1,   910,    -1,
     570,   910,    -1,   277,    -1,    -1,   296,  1353,  1456,  1356,
    1354,    -1,    -1,   526,  1355,   478,  1358,   440,    -1,  1494,
      -1,    -1,   478,  1357,   440,    -1,  1460,    -1,  1357,     5,
    1460,    -1,  1359,    -1,  1358,     5,  1359,    -1,  1500,    -1,
     530,    -1,    -1,   547,  1361,  1363,  1364,    -1,  1006,    -1,
    1368,   999,    -1,   999,    -1,    -1,    -1,   600,  1365,  1183,
      -1,    -1,    -1,   600,  1367,  1183,    -1,   548,    -1,   601,
      -1,   608,    -1,   424,    -1,   391,    -1,   444,    -1,   427,
     910,    -1,   400,   910,    -1,   285,  1456,   198,   999,    -1,
     285,  1456,  1429,    -1,   561,   665,  1372,    -1,  1373,    -1,
    1372,     5,  1373,    -1,  1374,  1375,    -1,    26,    -1,  1460,
      -1,    -1,   634,    -1,   585,    -1,   324,    -1,   357,    -1,
      -1,   376,    -1,   405,  1380,  1378,    -1,  1556,    -1,  1556,
     658,  1005,    -1,    25,    -1,    -1,  1513,  1382,  1383,    -1,
    1414,    -1,  1418,    -1,  1377,    -1,  1515,    -1,  1376,    -1,
    1369,    -1,  1370,    -1,  1360,    -1,  1352,    -1,  1351,    -1,
    1484,    -1,  1536,    -1,   552,  1387,   671,  1456,   672,  1392,
    1386,    -1,   513,  1387,   671,  1456,   593,  1392,    -1,   552,
    1385,   672,  1392,    -1,   513,  1385,   593,  1392,    -1,   443,
      -1,   428,    -1,   638,    -1,    -1,   191,    -1,   663,  1005,
      -1,   215,    -1,   632,    -1,  1388,    -1,  1389,    -1,  1388,
       5,  1389,    -1,   518,  1390,    -1,   497,    -1,   486,    -1,
     525,  1390,    -1,   533,    -1,   555,    -1,    -1,   478,  1391,
     440,    -1,  1460,    -1,  1391,     5,  1460,    -1,  1393,    -1,
    1392,     5,  1393,    -1,   510,    -1,  1458,    -1,   283,  1456,
    1395,   663,  1494,  1397,    -1,    -1,   478,  1396,   440,    -1,
    1460,    -1,  1396,     5,  1460,    -1,    -1,   190,    -1,   539,
     478,  1432,   440,    -1,   293,   478,  1401,   440,  1400,    -1,
     344,  1402,    -1,  1403,    -1,  1456,    -1,  1456,   478,  1403,
     440,    -1,  1460,    -1,  1403,     5,  1460,    -1,   523,   478,
    1405,   440,    -1,   408,   478,  1405,   440,    -1,   306,   478,
    1405,   440,    -1,  1460,    -1,  1405,     5,  1460,    -1,  1404,
      -1,  1399,    -1,  1398,    -1,   448,  1463,    -1,   256,    -1,
     255,    -1,   254,    -1,  1005,  1448,  1409,  1410,    -1,    -1,
    1407,    -1,    -1,  1411,    -1,  1412,    -1,  1411,  1412,    -1,
    1413,  1343,    -1,   422,    -1,   206,    -1,   523,    -1,   408,
      -1,  1400,    -1,   539,   478,  1432,   440,    -1,   306,    -1,
     167,  1415,  1417,    -1,  1416,    -1,  1458,    -1,  1418,    -1,
    1417,  1418,    -1,  1394,    -1,  1384,    -1,   495,  1432,    -1,
     417,  1421,    -1,  1499,    -1,  1421,     5,  1499,    -1,   573,
    1432,    -1,   593,  1424,    -1,  1425,    -1,  1424,     5,  1425,
      -1,  1426,    -1,   562,  1426,    -1,   562,   478,  1427,   440,
      -1,  1456,    -1,  1456,  1462,    -1,  1425,    -1,  1427,     5,
    1425,    -1,  1423,  1429,  1430,  1431,    -1,    -1,  1422,    -1,
      -1,  1420,    -1,    -1,  1419,    -1,  1433,    -1,  1432,     6,
    1433,    -1,  1434,    -1,  1433,     7,  1434,    -1,  1435,    -1,
       9,  1435,    -1,  1446,    -1,   478,  1432,   440,    -1,   490,
    1495,    -1,   342,  1495,    -1,    -1,   489,  1439,    -1,  1501,
      -1,  1504,    -1,  1500,   669,   478,  1441,   440,    -1,  1500,
     669,  1495,    -1,  1500,   476,   478,  1441,   440,    -1,  1500,
     476,  1495,    -1,  1442,    -1,  1441,     5,  1442,    -1,  1562,
      -1,  1463,    -1,    -1,     9,    -1,  1500,  1443,   435,    -1,
    1500,  1443,   297,    -1,  1500,  1445,  1500,    -1,  1500,  1443,
     437,  1500,     7,  1500,    -1,  1500,   603,  1438,  1437,    -1,
    1500,   420,  1438,  1437,    -1,  1500,   720,  1438,  1437,    -1,
    1500,   421,  1438,  1437,    -1,  1500,  1443,    10,  1438,  1437,
      -1,    14,    -1,    17,    -1,    12,    -1,    13,    -1,   300,
      -1,    10,    -1,   719,    -1,    16,    -1,    15,    -1,  1444,
      -1,  1440,    -1,  1436,    -1,    -1,   632,    -1,   408,    -1,
     523,    -1,  1449,    -1,  1450,    -1,  1452,    -1,   367,    -1,
     367,   478,  1453,   440,    -1,    -1,   519,    -1,   519,   478,
      26,   440,    -1,   446,    -1,   446,   478,  1454,  1451,   440,
      -1,   559,   478,  1454,  1451,   440,    -1,   559,    -1,   584,
      -1,   456,    -1,   429,    -1,   368,    -1,   368,   478,  1453,
     440,    -1,   369,    -1,   369,   478,    26,   440,    -1,   369,
     478,    26,     5,    26,   440,    -1,   406,  1470,   672,  1471,
      -1,   406,    -1,   418,  1470,   672,  1471,    -1,   418,    -1,
     418,  1470,   478,    26,   440,   672,  1471,    -1,   621,    -1,
     580,    -1,   471,    -1,   471,   478,    26,   440,    -1,   471,
     478,    26,     5,    26,   440,    -1,    -1,     5,  1455,    -1,
     549,   478,  1454,   440,    -1,   612,    -1,   347,    -1,   549,
      -1,   111,    -1,    26,    -1,    26,    -1,    26,    -1,    25,
     666,  1005,    -1,    25,    -1,  1005,    -1,  1005,   636,  1005,
      -1,  1005,   636,    25,   666,  1005,    -1,  1005,   658,  1005,
      -1,  1005,   658,  1005,   636,  1005,    -1,  1005,   658,  1005,
     636,    25,   666,  1005,    -1,    25,   666,  1005,    -1,    25,
      -1,  1005,    -1,  1005,   636,  1005,    -1,  1005,   636,    25,
     666,  1005,    -1,  1005,   658,  1005,    -1,  1005,   658,  1005,
     636,  1005,    -1,  1005,   658,  1005,   636,    25,   666,  1005,
      -1,  1005,    -1,    -1,   506,    26,   474,    -1,   506,    26,
       5,    26,   474,    -1,  1461,    -1,   658,  1461,    -1,  1005,
    1459,    -1,  1456,   666,  1005,  1459,    -1,  1456,   666,    20,
      -1,  1005,    -1,    25,    -1,  1011,    -1,    26,    -1,  1465,
      -1,   444,  1467,    -1,   444,  1466,    -1,    -1,  1470,   672,
    1471,    -1,    -1,  1468,   672,  1468,    -1,   628,    -1,   560,
      -1,   637,    -1,   599,    -1,   501,    -1,   517,    -1,   415,
      -1,   415,   478,    26,   440,    -1,   628,    -1,   560,    -1,
     637,    -1,   599,    -1,   501,    -1,   517,    -1,   415,    -1,
     415,   478,    26,   440,    -1,   628,    -1,   560,    -1,   637,
      -1,   599,    -1,   501,    -1,   517,    -1,   415,    -1,   628,
      -1,   560,    -1,   637,    -1,   599,    -1,   501,    -1,   517,
      -1,   415,    -1,   415,   478,    26,   440,    -1,  1005,    -1,
    1005,   658,  1005,    -1,    25,    -1,  1513,   550,   999,    -1,
      -1,  1513,   447,  1362,   484,   642,  1482,  1475,    -1,    -1,
    1513,   447,  1362,   484,   147,   642,  1483,  1476,    -1,    -1,
    1513,   447,  1362,   186,  1483,  1477,    -1,    -1,  1513,   447,
    1362,   187,   147,   642,  1483,  1478,    -1,    -1,   336,    -1,
     335,  1480,    -1,  1481,    -1,  1480,     5,  1481,    -1,  1005,
      -1,  1005,   666,  1005,    -1,    25,   666,  1005,   666,  1005,
      -1,  1483,    -1,  1352,    -1,  1217,    -1,  1485,    -1,  1485,
      -1,    -1,    -1,   518,  1496,  1486,  1497,  1487,  1493,  1428,
    1491,  1479,    -1,   518,  1496,  1497,  1428,  1491,    -1,  1490,
      -1,  1508,    -1,   518,  1496,  1497,  1493,  1428,  1491,    -1,
      -1,   572,  1447,  1489,    -1,  1371,    -1,   381,  1492,  1321,
      -1,  1371,   381,  1492,  1321,    -1,  1005,    -1,    -1,   600,
    1183,    -1,   518,  1496,  1497,  1428,    -1,   478,   518,  1496,
    1497,  1428,   440,    -1,    -1,   632,    -1,   408,    -1,   523,
      -1,  1498,    -1,  1497,     5,  1498,    -1,  1500,    -1,  1500,
    1005,    -1,  1500,   663,  1005,    -1,  1500,    -1,  1501,    -1,
      19,  1501,    -1,    18,  1501,    -1,  1502,    -1,  1562,    -1,
    1495,    -1,   632,  1495,    -1,   633,  1495,    -1,   617,  1495,
      -1,   658,  1005,    -1,   658,  1005,   666,  1005,    -1,  1501,
      21,  1500,    -1,  1501,  1522,    -1,  1501,    20,  1500,    -1,
    1501,    18,  1500,    -1,  1501,    19,  1500,    -1,  1463,    -1,
     531,    -1,   475,    -1,   623,    -1,    20,    -1,   112,    -1,
     635,   478,  1447,  1500,   440,    -1,   647,   478,  1447,  1500,
     440,    -1,   648,   478,  1447,  1500,   440,    -1,   655,   478,
    1447,  1500,   440,    -1,   543,   478,  1447,  1500,   440,    -1,
    1005,   478,  1503,   440,    -1,   584,   478,  1503,   440,    -1,
     478,  1500,   440,    -1,   491,   478,  1523,   440,    -1,  1524,
      -1,  1526,    -1,  1500,    -1,  1503,     5,  1500,    -1,  1463,
      -1,  1513,   396,  1512,  1507,  1489,    -1,  1513,   385,  1512,
    1507,   296,  1456,  1509,    -1,  1513,   385,  1512,  1507,  1162,
      -1,    -1,   371,  1508,    -1,    25,    -1,  1162,    -1,    -1,
     478,  1510,   440,    -1,  1511,    -1,  1510,     5,  1511,    -1,
    1005,    -1,    25,    -1,  1162,    -1,    -1,   315,  1514,   642,
      -1,  1006,    -1,  1520,    -1,  1519,    -1,  1516,    -1,   364,
    1517,   672,  1517,    -1,   345,  1456,   666,  1518,   672,  1518,
      -1,  1005,    -1,  1005,    -1,   269,  1456,    -1,   340,  1456,
    1521,    -1,   319,    -1,   222,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    -1,   143,    -1,   144,    -1,   444,     5,
    1470,   672,  1471,    -1,  1562,     5,  1470,   672,  1471,    -1,
     444,  1470,   672,  1471,    -1,  1500,     5,  1470,   672,  1471,
      -1,  1525,    -1,  1525,  1470,   672,  1471,    -1,   406,   478,
      25,   440,    -1,   406,   478,    26,   440,    -1,   406,   478,
      26,    19,    26,   440,    -1,   406,   478,    26,   636,    26,
     440,    -1,   406,   478,    26,    19,    26,    19,    26,   440,
      -1,   406,   478,    26,   636,    26,   636,    26,   440,    -1,
     406,   478,    26,    19,    26,    19,    26,    26,   636,    26,
     636,    26,   440,    -1,   406,   478,    26,    19,    26,    19,
      26,    26,   636,    26,   440,    -1,  1527,    -1,  1527,  1470,
     478,    26,   440,   672,  1471,    -1,  1527,  1470,   672,  1471,
      -1,   418,   478,    25,   440,    -1,   418,   478,    26,   440,
      -1,   418,   478,    26,    19,    26,   440,    -1,   418,   478,
      26,   636,    26,   440,    -1,   418,   478,    26,    19,    26,
      19,    26,   440,    -1,   418,   478,    26,   636,    26,   636,
      26,   440,    -1,    -1,   654,  1529,  1530,   237,    -1,  1531,
      -1,  1530,  1531,    -1,    33,    -1,  1532,    -1,  1534,    -1,
     400,    -1,   352,    -1,   271,    -1,   631,    -1,   528,    -1,
     632,    -1,   533,    -1,   577,    -1,   633,    -1,   163,    -1,
     534,    -1,   663,    -1,   634,    -1,   365,    -1,   535,    -1,
     366,    -1,   664,    -1,   658,    -1,   322,    -1,   536,    -1,
     231,    -1,   436,    -1,   635,    -1,   710,    -1,   437,    -1,
     537,    -1,   538,    -1,   578,    -1,   579,    -1,   479,    -1,
     480,    -1,   402,    -1,   697,    -1,   665,    -1,   580,    -1,
     438,    -1,   582,    -1,   576,    -1,   367,    -1,   539,    -1,
     540,    -1,   439,    -1,   541,    -1,   440,    -1,   474,    -1,
     542,    -1,   636,    -1,   481,    -1,   441,    -1,     5,    -1,
      23,    -1,   442,    -1,   482,    -1,   443,    -1,   404,    -1,
     403,    -1,   370,    -1,   543,    -1,   483,    -1,   444,    -1,
     484,    -1,   583,    -1,   405,    -1,   584,    -1,   406,    -1,
     637,    -1,   638,    -1,   445,    -1,   639,    -1,   446,    -1,
     447,    -1,   448,    -1,   407,    -1,   544,    -1,   485,    -1,
     486,    -1,   371,    -1,   585,    -1,   328,    -1,   640,    -1,
     701,    -1,   449,    -1,   408,    -1,    21,    -1,   666,    -1,
     487,    -1,   372,    -1,   588,    -1,   110,    -1,   589,    -1,
     704,    -1,   450,    -1,    14,    -1,   545,    -1,   489,    -1,
     546,    -1,   376,    -1,   590,    -1,   451,    -1,   490,    -1,
     591,    -1,   491,    -1,   492,    -1,   414,    -1,   581,    -1,
     547,    -1,   146,    -1,   240,    -1,   493,    -1,   548,    -1,
     641,    -1,   549,    -1,   550,    -1,   642,    -1,   452,    -1,
     453,    -1,   494,    -1,   684,    -1,   138,    -1,   153,    -1,
     551,    -1,   415,    -1,   592,    -1,   593,    -1,   416,    -1,
     337,    -1,   454,    -1,   667,    -1,   594,    -1,   552,    -1,
      13,    -1,   553,    -1,   554,    -1,   495,    -1,   496,    -1,
     597,    -1,   598,    -1,   599,    -1,   706,    -1,   119,    -1,
     668,    -1,   669,    -1,   159,    -1,   555,    -1,   455,    -1,
     338,    -1,   711,    -1,   497,    -1,   456,    -1,   380,    -1,
     418,    -1,   713,    -1,   382,    -1,   643,    -1,   586,    -1,
     705,    -1,   556,    -1,   529,    -1,   419,    -1,   644,    -1,
     673,    -1,   457,    -1,     7,    -1,   475,    -1,   629,    -1,
     530,    -1,     6,    -1,   531,    -1,     8,    -1,   601,    -1,
     602,    -1,    12,    -1,   645,    -1,   603,    -1,   558,    -1,
     498,    -1,   646,    -1,   458,    -1,   604,    -1,   499,    -1,
      10,    -1,    53,    -1,   500,    -1,   605,    -1,   692,    -1,
     707,    -1,    19,    -1,   501,    -1,   158,    -1,    22,    -1,
     606,    -1,   502,    -1,   559,    -1,   560,    -1,    20,    -1,
     607,    -1,   608,    -1,   358,    -1,   609,    -1,   503,    -1,
       9,    -1,   670,    -1,   715,    -1,   671,    -1,   610,    -1,
     478,    -1,   506,    -1,   507,    -1,   459,    -1,   561,    -1,
     389,    -1,   562,    -1,   508,    -1,   649,    -1,   423,    -1,
     563,    -1,   203,    -1,   154,    -1,   460,    -1,    18,    -1,
     157,    -1,   390,    -1,   461,    -1,   160,    -1,   424,    -1,
     359,    -1,   566,    -1,   391,    -1,   392,    -1,   462,    -1,
     509,    -1,   510,    -1,   650,    -1,   611,    -1,   425,    -1,
     612,    -1,   511,    -1,   463,    -1,   651,    -1,   344,    -1,
     426,    -1,   427,    -1,   512,    -1,   428,    -1,   225,    -1,
     394,    -1,   464,    -1,   513,    -1,   567,    -1,   309,    -1,
     652,    -1,   613,    -1,   653,    -1,   514,    -1,   516,    -1,
     517,    -1,   465,    -1,   518,    -1,   569,    -1,   519,    -1,
     466,    -1,   521,    -1,   614,    -1,   532,    -1,   615,    -1,
     616,    -1,   570,    -1,   347,    -1,   429,    -1,   617,    -1,
     522,    -1,   654,    -1,   348,    -1,   137,    -1,   618,    -1,
     619,    -1,   655,    -1,   467,    -1,   587,    -1,   620,    -1,
     164,    -1,   621,    -1,   622,    -1,   468,    -1,   714,    -1,
     672,    -1,   656,    -1,   469,    -1,   571,    -1,   245,    -1,
     395,    -1,   572,    -1,   523,    -1,   524,    -1,   525,    -1,
     470,    -1,   657,    -1,   623,    -1,   430,    -1,   526,    -1,
     471,    -1,   399,    -1,   624,    -1,   472,    -1,   625,    -1,
     573,    -1,   574,    -1,   575,    -1,   626,    -1,   432,    -1,
     627,    -1,   647,    -1,   648,    -1,   630,    -1,   628,    -1,
     527,    -1,    -1,   238,  1533,  1562,    -1,    -1,   600,  1535,
    1183,    -1,    -1,    -1,   525,  1456,  1537,  1540,  1538,  1539,
      -1,    -1,   198,   999,    -1,   573,  1432,    -1,    97,  1544,
     440,    14,   478,  1545,   440,    -1,    93,  1545,   440,    -1,
      94,  1545,   440,    -1,   630,  1541,    -1,    96,  1545,    -1,
      95,  1545,    -1,  1543,    -1,  1541,     5,  1543,    -1,  1460,
      -1,  1542,    14,  1546,    -1,  1542,    -1,  1544,     5,  1542,
      -1,  1546,    -1,  1545,     5,  1546,    -1,   530,    -1,  1547,
      -1,  1548,    -1,    19,  1548,    -1,    18,  1548,    -1,  1550,
      -1,  1495,    -1,   658,  1005,    -1,   658,  1005,   666,  1005,
      -1,   658,  1005,   506,    26,   474,    -1,   658,  1005,   666,
    1005,   506,    26,   474,    -1,   658,  1005,   506,    26,     5,
      26,   474,    -1,   658,  1005,   666,  1005,   506,    26,     5,
      26,   474,    -1,  1549,    -1,  1463,    -1,   531,    -1,   475,
      -1,   623,    -1,   112,    -1,  1548,    21,  1547,    -1,  1548,
    1522,    -1,  1548,    20,  1547,    -1,  1548,    18,  1547,    -1,
    1548,    19,  1547,    -1,   635,   478,  1447,  1547,   440,    -1,
     647,   478,  1447,  1547,   440,    -1,   648,   478,  1447,  1547,
     440,    -1,   655,   478,  1447,  1547,   440,    -1,   543,   478,
    1447,  1547,   440,    -1,  1005,   478,  1551,   440,    -1,   584,
     478,  1551,   440,    -1,   478,  1547,   440,    -1,   491,   478,
    1523,   440,    -1,  1524,    -1,  1526,    -1,  1562,    -1,  1547,
      -1,  1551,     5,  1547,    -1,    -1,   430,  1191,   603,  1553,
    1554,    -1,  1555,    -1,  1554,     5,  1555,    -1,  1456,   666,
    1460,    -1,  1456,   666,    20,    -1,  1558,    -1,  1558,    -1,
     238,  1559,    -1,  1559,    -1,  1560,    -1,    25,   666,  1560,
      -1,  1561,    -1,  1560,   666,  1561,    -1,  1560,   666,    20,
      -1,  1563,    -1,  1005,    -1,  1557,    -1,  1557,   468,  1557,
      -1,  1005,  1564,    -1,   506,  1565,   474,    -1,   506,  1565,
     474,   506,  1565,   474,    -1,  1566,    -1,  1565,     5,  1566,
      -1,   732,    -1,    34,    -1,    -1,    -1,   574,  1569,   910,
    1570,  1583,   375,    -1,    -1,   705,   953,    -1,    -1,   708,
      -1,   229,    -1,   325,  1000,    -1,   117,  1000,    -1,   355,
      -1,   354,    -1,   356,  1002,  1571,  1572,    -1,   540,   953,
    1572,    -1,   151,    -1,   183,  1000,    -1,   910,   613,     5,
     910,   441,    -1,   556,   910,    -1,   312,  1000,    -1,   148,
    1578,     8,  1579,  1577,    -1,    -1,   593,   910,    -1,  1005,
      -1,  1005,    -1,   295,  1000,    -1,   298,  1000,   672,   910,
       5,   910,    -1,   298,  1000,   665,   910,     5,   910,    -1,
      27,    -1,    -1,  1585,    -1,  1586,  1268,    -1,  1584,    -1,
    1585,  1584,    -1,    -1,  1587,  1588,    -1,   725,    -1,   726,
      -1,   727,    -1,   728,    -1,   745,    -1,   767,    -1,   781,
      -1,   782,    -1,   788,    -1,   789,    -1,   808,    -1,   882,
      -1,   883,    -1,   884,    -1,   885,    -1,   896,    -1,   897,
      -1,   898,    -1,   899,    -1,   900,    -1,   901,    -1,   902,
      -1,   955,    -1,   959,    -1,   990,    -1,  1012,    -1,  1014,
      -1,  1017,    -1,  1018,    -1,  1019,    -1,  1020,    -1,  1033,
      -1,  1042,    -1,  1066,    -1,  1067,    -1,  1069,    -1,  1073,
      -1,  1088,    -1,  1089,    -1,  1093,    -1,  1094,    -1,  1095,
      -1,  1096,    -1,  1104,    -1,  1119,    -1,  1132,    -1,  1143,
      -1,  1144,    -1,  1145,    -1,  1156,    -1,  1193,    -1,  1196,
      -1,  1198,    -1,  1204,    -1,  1205,    -1,  1208,    -1,  1211,
      -1,  1214,    -1,  1216,    -1,  1218,    -1,  1221,    -1,  1228,
      -1,  1233,    -1,  1237,    -1,  1238,    -1,  1239,    -1,  1251,
      -1,  1304,    -1,  1305,    -1,  1307,    -1,  1326,    -1,  1327,
      -1,  1347,    -1,  1350,    -1,  1379,    -1,  1381,    -1,  1473,
      -1,  1474,    -1,  1505,    -1,  1506,    -1,  1528,    -1,  1552,
      -1,  1567,    -1,  1568,    -1,  1573,    -1,  1574,    -1,  1576,
      -1,  1580,    -1,  1581,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   996,   996,   999,  1002,  1008,  1014,  1021,  1025,  1025,
    1031,  1054,  1055,  1056,  1057,  1058,  1069,  1075,  1076,  1077,
    1078,  1079,  1084,  1085,  1096,  1099,  1102,  1102,  1106,  1109,
    1110,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1135,  1136,
    1139,  1139,  1154,  1155,  1158,  1164,  1166,  1177,  1179,  1181,
    1183,  1187,  1189,  1251,  1255,  1259,  1259,  1269,  1273,  1276,
    1277,  1284,  1290,  1284,  1303,  1308,  1312,  1303,  1324,  1328,
    1324,  1336,  1341,  1336,  1360,  1367,  1371,  1359,  1397,  1397,
    1401,  1402,  1403,  1408,  1411,  1416,  1420,  1428,  1429,  1432,
    1432,  1438,  1442,  1457,  1455,  1473,  1473,  1488,  1488,  1491,
    1491,  1495,  1498,  1498,  1498,  1505,  1506,  1505,  1513,  1513,
    1524,  1524,  1543,  1546,  1549,  1552,  1555,  1558,  1571,  1576,
    1576,  1577,  1577,  1580,  1585,  1585,  1589,  1599,  1613,  1618,
    1612,  1629,  1635,  1643,  1644,  1647,  1647,  1650,  1654,  1659,
    1666,  1666,  1670,  1670,  1671,  1671,  1672,  1672,  1673,  1673,
    1674,  1674,  1682,  1686,  1692,  1696,  1711,  1714,  1717,  1720,
    1723,  1726,  1732,  1743,  1748,  1761,  1765,  1780,  1781,  1785,
    1785,  1789,  1789,  1789,  1790,  1795,  1795,  1798,  1798,  1807,
    1808,  1809,  1812,  1816,  1817,  1817,  1834,  1834,  1834,  1834,
    1838,  1845,  1846,  1849,  1849,  1853,  1854,  1855,  1856,  1861,
    1861,  1867,  1867,  1876,  1873,  1889,  1889,  1891,  1891,  1893,
    1895,  1897,  1899,  1902,  1906,  1906,  1907,  1907,  1911,  1911,
    1923,  1923,  1928,  1932,  1934,  1935,  1938,  1938,  1938,  1942,
    1943,  1944,  1945,  1946,  1947,  1948,  1949,  1950,  1951,  1952,
    1953,  1956,  1957,  1958,  1959,  1963,  1968,  1973,  1977,  1980,
    1984,  1984,  1985,  1985,  1986,  1986,  1987,  1988,  1989,  1990,
    1991,  1992,  1995,  1996,  1997,  2027,  2027,  2032,  2036,  2038,
    2040,  2040,  2047,  2051,  2051,  2055,  2056,  2057,  2058,  2059,
    2060,  2061,  2067,  2067,  2070,  2072,  2078,  2080,  2086,  2094,
    2094,  2097,  2098,  2099,  2100,  2101,  2102,  2103,  2109,  2112,
    2112,  2125,  2125,  2132,  2133,  2134,  2136,  2137,  2139,  2141,
    2142,  2143,  2144,  2149,  2155,  2161,  2162,  2164,  2166,  2167,
    2168,  2169,  2170,  2171,  2174,  2175,  2182,  2190,  2190,  2198,
    2195,  2210,  2210,  2212,  2212,  2220,  2220,  2223,  2226,  2227,
    2232,  2244,  2248,  2251,  2254,  2255,  2256,  2257,  2258,  2263,
    2270,  2276,  2281,  2286,  2281,  2299,  2301,  2306,  2311,  2311,
    2311,  2315,  2315,  2318,  2318,  2325,  2325,  2332,  2332,  2343,
    2361,  2367,  2391,  2394,  2408,  2410,  2412,  2414,  2416,  2418,
    2420,  2426,  2428,  2432,  2434,  2436,  2438,  2440,  2442,  2444,
    2450,  2465,  2468,  2481,  2482,  2483,  2484,  2485,  2489,  2490,
    2491,  2495,  2500,  2507,  2508,  2509,  2510,  2511,  2512,  2513,
    2514,  2515,  2516,  2517,  2524,  2524,  2529,  2529,  2532,  2538,
    2546,  2552,  2562,  2563,  2571,  2578,  2582,  2592,  2596,  2601,
    2606,  2608,  2611,  2617,  2625,  2638,  2643,  2649,  2654,  2659,
    2660,  2666,  2737,  2748,  2757,  2765,  2765,  2780,  2784,  2791,
    2794,  2802,  2806,  2809,  2815,  2824,  2829,  2837,  2840,  2843,
    2848,  2855,  2860,  2865,  2870,  2880,  2888,  2896,  2901,  2905,
    2910,  2914,  2918,  2925,  2928,  2931,  2935,  2939,  2943,  2947,
    2955,  2965,  2970,  2963,  2986,  2991,  2986,  3008,  3008,  3008,
    3011,  3011,  3011,  3015,  3015,  3015,  3019,  3019,  3019,  3023,
    3029,  3035,  3041,  3047,  3053,  3062,  3068,  3078,  3078,  3082,
    3086,  3087,  3098,  3099,  3105,  3115,  3125,  3135,  3136,  3139,
    3144,  3150,  3154,  3158,  3161,  3167,  3170,  3173,  3190,  3193,
    3199,  3200,  3201,  3205,  3206,  3207,  3208,  3209,  3211,  3212,
    3213,  3215,  3216,  3220,  3221,  3226,  3230,  3235,  3239,  3254,
    3258,  3253,  3266,  3269,  3283,  3287,  3293,  3282,  3306,  3307,
    3319,  3325,  3319,  3339,  3339,  3341,  3342,  3346,  3346,  3350,
    3350,  3355,  3355,  3362,  3363,  3367,  3367,  3371,  3371,  3376,
    3376,  3383,  3387,  3388,  3389,  3394,  3394,  3397,  3397,  3401,
    3401,  3405,  3405,  3409,  3409,  3414,  3414,  3419,  3419,  3424,
    3424,  3429,  3429,  3445,  3462,  3463,  3464,  3465,  3466,  3467,
    3468,  3471,  3471,  3474,  3476,  3479,  3482,  3485,  3490,  3495,
    3498,  3503,  3508,  3513,  3520,  3521,  3528,  3535,  3537,  3543,
    3548,  3553,  3558,  3558,  3561,  3567,  3572,  3575,  3582,  3582,
    3584,  3587,  3590,  3595,  3600,  3605,  3612,  3621,  3621,  3683,
    3691,  3692,  3700,  3707,  3707,  3711,  3716,  3722,  3726,  3730,
    3736,  3740,  3744,  3750,  3750,  3758,  3759,  3763,  3763,  3767,
    3768,  3771,  3774,  3774,  3777,  3779,  3779,  3782,  3784,  3784,
    3785,  3787,  3787,  3796,  3803,  3794,  3824,  3824,  3824,  3827,
    3829,  3827,  3836,  3839,  3845,  3856,  3856,  3860,  3866,  3866,
    3870,  3871,  3875,  3885,  3886,  3887,  3890,  3892,  3897,  3897,
    3901,  3900,  3908,  3907,  3914,  3914,  3920,  3920,  3927,  3927,
    3933,  3933,  3939,  3939,  3945,  3945,  3949,  3949,  3950,  3950,
    3951,  3951,  3952,  3952,  3956,  3956,  3967,  3971,  3977,  3981,
    3986,  3991,  3996,  3997,  3998,  4002,  4001,  4014,  4019,  4024,
    4024,  4040,  4046,  4047,  4048,  4049,  4052,  4052,  4055,  4062,
    4063,  4064,  4065,  4066,  4067,  4068,  4069,  4070,  4075,  4075,
    4077,  4080,  4080,  4082,  4086,  4089,  4090,  4093,  4093,  4098,
    4101,  4102,  4103,  4104,  4105,  4106,  4107,  4108,  4109,  4110,
    4111,  4112,  4113,  4114,  4115,  4116,  4117,  4118,  4122,  4140,
    4140,  4140,  4167,  4178,  4185,  4191,  4197,  4203,  4215,  4240,
    4239,  4256,  4256,  4260,  4261,  4269,  4270,  4271,  4272,  4273,
    4274,  4281,  4282,  4284,  4285,  4289,  4294,  4295,  4296,  4297,
    4298,  4299,  4300,  4301,  4302,  4303,  4304,  4307,  4309,  4309,
    4311,  4315,  4315,  4324,  4329,  4345,  4351,  4323,  4365,  4379,
    4389,  4378,  4402,  4409,  4409,  4414,  4420,  4428,  4433,  4434,
    4437,  4440,  4440,  4448,  4454,  4465,  4466,  4470,  4474,  4487,
    4469,  4505,  4505,  4519,  4530,  4529,  4541,  4537,  4554,  4551,
    4564,  4564,  4566,  4567,  4569,  4570,  4573,  4574,  4575,  4577,
    4582,  4587,  4593,  4595,  4596,  4599,  4600,  4603,  4605,  4613,
    4619,  4613,  4630,  4631,  4635,  4635,  4642,  4642,  4651,  4654,
    4657,  4660,  4664,  4668,  4669,  4670,  4671,  4672,  4676,  4681,
    4681,  4684,  4711,  4769,  4769,  4772,  4776,  4780,  4823,  4865,
    4866,  4867,  4870,  4884,  4896,  4896,  4901,  4902,  4908,  4973,
    4978,  4985,  4990,  4998,  5004,  5037,  5040,  5041,  5082,  5125,
    5126,  5130,  5131,  5135,  5188,  5193,  5197,  5202,  5213,  5220,
    5228,  5228,  5231,  5232,  5233,  5234,  5235,  5238,  5241,  5247,
    5250,  5254,  5259,  5267,  5272,  5279,  5281,  5287,  5289,  5289,
    5289,  5313,  5320,  5327,  5330,  5344,  5351,  5352,  5355,  5356,
    5360,  5366,  5371,  5377,  5378,  5383,  5387,  5387,  5391,  5392,
    5395,  5396,  5400,  5408,  5411,  5417,  5418,  5420,  5422,  5426,
    5426,  5427,  5432,  5440,  5441,  5446,  5447,  5449,  5462,  5464,
    5465,  5468,  5469,  5470,  5471,  5472,  5473,  5474,  5475,  5476,
    5477,  5478,  5479,  5480,  5481,  5482,  5483,  5484,  5485,  5486,
    5487,  5488,  5489,  5490,  5491,  5492,  5493,  5507,  5515,  5515,
    5517,  5521,  5525,  5529,  5533,  5538,  5553,  5551,  5571,  5572,
    5576,  5581,  5582,  5586,  5587,  5589,  5590,  5592,  5592,  5601,
    5610,  5610,  5620,  5621,  5626,  5627,  5630,  5643,  5657,  5661,
    5665,  5669,  5678,  5678,  5682,  5685,  5685,  5687,  5693,  5701,
    5707,  5709,  5713,  5716,  5716,  5719,  5719,  5724,  5724,  5733,
    5733,  5737,  5737,  5738,  5738,  5739,  5739,  5753,  5753,  5773,
    5774,  5775,  5776,  5777,  5778,  5781,  5781,  5787,  5787,  5790,
    5790,  5806,  5807,  5808,  5817,  5829,  5830,  5833,  5834,  5837,
    5840,  5840,  5845,  5845,  5866,  5871,  5877,  5878,  5879,  5883,
    5884,  5885,  5886,  5890,  5900,  5902,  5907,  5910,  5915,  5921,
    5928,  5935,  5944,  5951,  5958,  5965,  5972,  5981,  5981,  5983,
    5983,  5986,  5987,  5988,  5989,  5990,  5991,  5992,  5993,  5994,
    5995,  5998,  5998,  6001,  6002,  6003,  6004,  6007,  6007,  6010,
    6010,  6013,  6014,  6015,  6016,  6017,  6018,  6019,  6020,  6022,
    6023,  6024,  6025,  6027,  6028,  6029,  6030,  6032,  6033,  6034,
    6035,  6036,  6037,  6038,  6039,  6043,  6051,  6061,  6074,  6083,
    6094,  6098,  6102,  6108,  6073,  6121,  6124,  6132,  6144,  6146,
    6151,  6159,  6169,  6172,  6176,  6184,  6150,  6193,  6197,  6201,
    6205,  6197,  6215,  6216,  6217,  6218,  6223,  6225,  6228,  6232,
    6235,  6242,  6247,  6248,  6249,  6250,  6255,  6256,  6262,  6262,
    6262,  6267,  6267,  6267,  6275,  6276,  6280,  6281,  6286,  6287,
    6288,  6289,  6290,  6293,  6295,  6295,  6298,  6299,  6303,  6304,
    6307,  6308,  6311,  6314,  6317,  6323,  6324,  6336,  6337,  6342,
    6343,  6344,  6348,  6351,  6357,  6360,  6368,  6369,  6375,  6379,
    6383,  6389,  6392,  6401,  6404,  6407,  6410,  6413,  6416,  6419,
    6426,  6429,  6436,  6439,  6445,  6448,  6455,  6458,  6465,  6466,
    6471,  6475,  6478,  6484,  6487,  6493,  6500,  6501,  6505,  6515,
    6518,  6524,  6526,  6531,  6532,  6536,  6538,  6544,  6545,  6558,
    6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,  6578,  6581,
    6584,  6590,  6590,  6596,  6596,  6607,  6620,  6630,  6630,  6635,
    6635,  6639,  6643,  6644,  6650,  6651,  6656,  6660,  6667,  6670,
    6677,  6676,  6687,  6691,  6695,  6702,  6705,  6705,  6718,  6722,
    6722,  6737,  6739,  6741,  6743,  6745,  6747,  6749,  6751,  6757,
    6767,  6774,  6779,  6780,  6784,  6787,  6788,  6791,  6792,  6793,
    6796,  6801,  6808,  6809,  6815,  6827,  6828,  6829,  6832,  6832,
    6837,  6842,  6847,  6848,  6851,  6852,  6857,  6862,  6866,  6871,
    6872,  6876,  6883,  6884,  6885,  6886,  6891,  6892,  6893,  6896,
    6897,  6898,  6902,  6903,  6904,  6908,  6909,  6913,  6914,  6915,
    6916,  6917,  6918,  6921,  6922,  6927,  6928,  6933,  6934,  6939,
    6940,  6945,  6950,  6951,  6956,  6957,  6961,  6962,  6967,  6974,
    6979,  6984,  6988,  6989,  6994,  6995,  7001,  7002,  7003,  7008,
    7009,  7015,  7018,  7021,  7028,  7029,  7030,  7031,  7045,  7050,
    7051,  7054,  7056,  7063,  7066,  7072,  7080,  7084,  7088,  7092,
    7096,  7099,  7102,  7109,  7116,  7121,  7125,  7126,  7132,  7135,
    7146,  7153,  7159,  7162,  7169,  7176,  7182,  7183,  7189,  7190,
    7191,  7194,  7195,  7200,  7200,  7204,  7212,  7213,  7216,  7219,
    7224,  7225,  7230,  7233,  7239,  7242,  7248,  7251,  7257,  7260,
    7267,  7268,  7297,  7298,  7303,  7311,  7316,  7319,  7322,  7325,
    7331,  7332,  7336,  7339,  7342,  7343,  7348,  7351,  7354,  7357,
    7360,  7363,  7366,  7369,  7374,  7380,  7381,  7382,  7383,  7384,
    7386,  7387,  7389,  7390,  7395,  7398,  7402,  7408,  7409,  7410,
    7411,  7423,  7424,  7425,  7429,  7430,  7434,  7435,  7436,  7437,
    7438,  7440,  7442,  7443,  7444,  7445,  7446,  7447,  7448,  7449,
    7451,  7453,  7455,  7456,  7458,  7459,  7461,  7462,  7463,  7464,
    7466,  7470,  7471,  7477,  7479,  7480,  7481,  7482,  7487,  7491,
    7495,  7499,  7506,  7510,  7511,  7512,  7520,  7521,  7522,  7533,
    7540,  7545,  7546,  7547,  7555,  7556,  7557,  7574,  7583,  7584,
    7585,  7589,  7592,  7597,  7602,  7607,  7615,  7619,  7624,  7625,
    7633,  7636,  7639,  7653,  7667,  7680,  7681,  7685,  7685,  7685,
    7685,  7685,  7685,  7686,  7689,  7694,  7694,  7694,  7694,  7694,
    7694,  7696,  7699,  7705,  7705,  7705,  7705,  7705,  7705,  7705,
    7706,  7706,  7706,  7706,  7706,  7706,  7706,  7706,  7709,  7710,
    7711,  7714,  7723,  7723,  7729,  7729,  7736,  7736,  7742,  7742,
    7750,  7751,  7752,  7755,  7755,  7758,  7759,  7760,  7771,  7774,
    7780,  7785,  7792,  7805,  7806,  7803,  7824,  7835,  7838,  7843,
    7855,  7858,  7862,  7865,  7866,  7872,  7875,  7876,  7885,  7894,
    7899,  7900,  7901,  7902,  7909,  7912,  7918,  7921,  7928,  7940,
    7949,  7952,  7955,  7961,  7967,  7970,  7971,  7972,  7973,  7974,
    7977,  7983,  7985,  7987,  7989,  7991,  7993,  7994,  7995,  7996,
    7997,  7998,  7999,  8001,  8003,  8005,  8007,  8009,  8011,  8013,
    8014,  8016,  8017,  8023,  8024,  8031,  8034,  8042,  8046,  8053,
    8053,  8057,  8057,  8062,  8062,  8066,  8066,  8070,  8076,  8076,
    8079,  8079,  8085,  8092,  8093,  8094,  8098,  8099,  8102,  8103,
    8107,  8113,  8123,  8124,  8132,  8133,  8134,  8135,  8136,  8137,
    8141,  8142,  8143,  8144,  8148,  8149,  8153,  8154,  8155,  8156,
    8157,  8158,  8159,  8161,  8165,  8166,  8167,  8171,  8172,  8173,
    8174,  8175,  8176,  8179,  8179,  8191,  8192,  8196,  8197,  8198,
    8199,  8200,  8201,  8202,  8203,  8204,  8205,  8206,  8207,  8208,
    8209,  8210,  8211,  8212,  8213,  8214,  8215,  8216,  8217,  8218,
    8219,  8220,  8221,  8222,  8223,  8224,  8225,  8226,  8227,  8228,
    8229,  8230,  8231,  8232,  8233,  8234,  8235,  8236,  8237,  8238,
    8239,  8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,
    8249,  8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,
    8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,  8268,
    8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,  8278,
    8279,  8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,  8288,
    8289,  8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,
    8299,  8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,  8308,
    8309,  8310,  8311,  8312,  8313,  8314,  8315,  8316,  8317,  8318,
    8319,  8320,  8321,  8322,  8323,  8324,  8325,  8326,  8327,  8328,
    8329,  8330,  8331,  8332,  8333,  8334,  8335,  8336,  8337,  8338,
    8339,  8340,  8341,  8342,  8343,  8344,  8345,  8346,  8347,  8348,
    8349,  8350,  8351,  8352,  8353,  8354,  8355,  8356,  8357,  8358,
    8359,  8360,  8361,  8362,  8363,  8364,  8365,  8366,  8367,  8368,
    8369,  8370,  8371,  8372,  8373,  8374,  8375,  8376,  8377,  8378,
    8379,  8380,  8381,  8382,  8383,  8384,  8385,  8386,  8387,  8388,
    8389,  8390,  8391,  8392,  8393,  8394,  8395,  8396,  8397,  8398,
    8399,  8401,  8402,  8403,  8404,  8405,  8406,  8407,  8408,  8409,
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
    8510,  8511,  8512,  8513,  8514,  8515,  8523,  8523,  8530,  8530,
    8618,  8622,  8618,  8631,  8635,  8641,  8649,  8659,  8669,  8681,
    8684,  8703,  8729,  8732,  8738,  8741,  8746,  8749,  8757,  8765,
    8778,  8781,  8789,  8792,  8795,  8803,  8807,  8808,  8809,  8810,
    8811,  8812,  8813,  8814,  8818,  8819,  8820,  8821,  8822,  8828,
    8829,  8830,  8831,  8832,  8833,  8834,  8835,  8836,  8837,  8838,
    8839,  8840,  8841,  8842,  8843,  8848,  8854,  8855,  8863,  8863,
    8871,  8871,  8875,  8879,  8894,  8909,  8915,  8917,  8925,  8926,
    8930,  8931,  8934,  8941,  8944,  8973,  8999,  9045,  9081,  9090,
    9101,  9104,  9109,  9123,  9137,  9140,  9136,  9159,  9159,  9165,
    9166,  9169,  9170,  9171,  9172,  9173,  9174,  9175,  9186,  9189,
    9194,  9198,  9203,  9207,  9212,  9216,  9219,  9223,  9226,  9231,
    9235,  9246,  9252,  9252,  9253,  9254,  9261,  9271,  9271,  9273,
    9274,  9275,  9276,  9277,  9278,  9279,  9280,  9281,  9282,  9283,
    9284,  9285,  9286,  9287,  9288,  9289,  9290,  9291,  9292,  9293,
    9294,  9295,  9296,  9297,  9298,  9299,  9300,  9301,  9302,  9303,
    9304,  9305,  9306,  9307,  9308,  9309,  9310,  9311,  9312,  9313,
    9314,  9315,  9316,  9317,  9318,  9319,  9320,  9321,  9322,  9323,
    9324,  9325,  9326,  9327,  9328,  9329,  9330,  9331,  9332,  9333,
    9334,  9335,  9336,  9337,  9338,  9339,  9340,  9341,  9342,  9343,
    9344,  9345,  9346,  9347,  9348,  9349,  9350,  9351,  9352,  9353,
    9354,  9355,  9356,  9357,  9358,  9359,  9360,  9361
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "KW_WHENEVER_SET", "DYNAMIC_ARRAY", 
  "RESIZE_ARRAY", "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", 
  "AFTER_INSERT_DELETE", "BEFORE_INSERT_DELETE", "BEFORE_INSERT", 
  "CONCAT_PIPES", "BEFORE_DELETE", "DROP_TRIGGER", "AFTER_INSERT", 
  "AFTER_DELETE", "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", 
  "INSERT_ROW_EQUAL_TRUE", "DELETE_ROW_EQUAL_FALSE", 
  "INSERT_ROW_EQUAL_FALSE", "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", 
  "ALTER_TABLE", "ALTER_INDEX", "NEXT_SIZE", "DISPLAY_ATTR_FORM", 
  "DISPLAY_ATTR_WINDOW", "INPUT_ATTR_FORM", "INPUT_ATTR_WINDOW", 
  "WHENEVER_ERROR_CONTINUE", "WHENEVER_ANY_ERROR_CONTINUE", 
  "WHENEVER_WARNING_CONTINUE", "WHENEVER_SQLSUCCESS_CONTINUE", 
  "WHENEVER_SQLWARNING_CONTINUE", "WHENEVER_NOT_FOUND_CONTINUE", 
  "WHENEVER_SQLERROR_CONTINUE", "WHENEVER_SUCCESS_CONTINUE", 
  "WHENEVER_ERROR_GOTO", "WHENEVER_ANY_ERROR_GOTO", 
  "WHENEVER_WARNING_GOTO", "WHENEVER_SQLSUCCESS_GOTO", 
  "WHENEVER_SQLWARNING_GOTO", "WHENEVER_NOT_FOUND_GOTO", 
  "WHENEVER_SQLERROR_GOTO", "WHENEVER_SUCCESS_GOTO", 
  "WHENEVER_ERROR_CALL", "WHENEVER_ANY_ERROR_CALL", 
  "WHENEVER_WARNING_CALL", "WHENEVER_SQLSUCCESS_CALL", 
  "WHENEVER_SQLWARNING_CALL", "WHENEVER_NOT_FOUND_CALL", 
  "WHENEVER_SQLERROR_CALL", "WHENEVER_SUCCESS_CALL", 
  "WHENEVER_ERROR_STOP", "WHENEVER_ANY_ERROR_STOP", 
  "WHENEVER_WARNING_STOP", "WHENEVER_SQLSUCCESS_STOP", 
  "WHENEVER_SQLWARNING_STOP", "WHENEVER_NOT_FOUND_STOP", 
  "WHENEVER_SQLERROR_STOP", "WHENEVER_SUCCESS_STOP", 
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
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
  "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "COMMENT", "CONNECT", "CURRENT", 
  "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", 
  "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", 
  "KWWINDOW", "MAGENTA", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", 
  "RECOVER", "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", 
  "TRAILER", "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", 
  "CLOSE_SQUARE", "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", 
  "BOTTOM", "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", 
  "DOUBLE", "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", 
  "FORMAT", "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", 
  "MINUTE", "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", 
  "OPTION", "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", 
  "SCHEMA", "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", 
  "SETL", "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", 
  "YELLOW", "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", 
  "ALTER", "ARRAY", "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", 
  "CLOSE", "CODE_C", "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", 
  "FLOAT", "FLUSH", "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", 
  "LABEL", "LOCAL", "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", 
  "PRINT_IMAGE", "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", 
  "SEMICOLON", "SLEEP", "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", 
  "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", "FCALL", "CASE", "CYAN", 
  "DATE", "DESC", "KWDOWN", "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", 
  "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", 
  "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", 
  "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", 
  "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", 
  "WORK", "YEAR", "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", 
  "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", 
  "LET", "LOG", "XMAX", "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", 
  "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", 
  "AS", "AT", "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "KWUP", 
  "FONT_NAME", "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
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
  "c_code_part", "comment_cmd", "construct_cmd", "@22", "@23", 
  "constr_rest", "end_constr", "constr_col_list", "constr_col", 
  "constr_extra_commands", "constr_extra_command", "@24", "@25", "@26", 
  "@27", "@28", "bef_c_field_list_as_struct", 
  "aft_c_field_list_as_struct", "interval_expr", "extend_parameters", 
  "op_datetime_qual", "defer_cmd", "define_section", "define_multiple", 
  "define_set", "@29", "@30", "def_part", "define_ident", "@31", 
  "def_part2", "@32", "constant_value", "var_def_name", "var_def_list", 
  "op_char", "ranking", "array_variable", "@33", "@34", "@35", 
  "assoc_open_bracket", "assoc_close_bracket", "number_arr_assoc", 
  "number_arr_list", "number_value_arr", "record_variable", "@36", "@37", 
  "@38", "link_to_pk_list", "link_to_pk", "dtype_ident", "op_as_static", 
  "dtype2", "@39", "@40", "dtype", "@41", "@42", "@43", "op_prec", 
  "like_var", "tab_name", "col_name", "datetime_qual", "interval_qual", 
  "dtime_start", "@44", "dtime_val", "dtime_end", "@45", "opt_frac", 
  "opt_unit_size", "dtfrac", "int_start", "@46", "int_start_unit", 
  "int_end", "op_equal", "dim_section", "@47", "dim_dtype", 
  "dim_like_var", "dim_array_variable", "@48", "@49", 
  "dim_record_variable", "@50", "@51", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@52", "@53", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@54", "@55", "@56", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@57", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@58", "@59", "@60", "@61", "function_callb", 
  "@62", "@63", "@64", "@65", "@66", "@67", "@68", "@69", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
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
  "put_val", "start_cmd", "rout", "rep_name", "op_values", "output_cmd", 
  "finish_cmd", "term_rep_cmd", "report_section", "format_section", 
  "format_actions", "format_action", "@134", "@135", "@136", "@137", 
  "@138", "@139", "@140", "report_cmd", "need_command", "@141", 
  "op_lines", "skip_command", "@142", "opt_rep_expr_list", 
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
       0,   256,  1708,  1709,  1710,  1615,  1655,  1610,  1547,  1630,
    1427,  1533,  1529,  1444,  1605,  1345,  1402,  1475,  1641,  1628,
    1534,  1561,  1629,  1409,  1711,  1712,  1713,  1714,  1715,  1716,
    1717,  1718,  1719,  1720,  1721,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,
    1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,
    1396,  1397,  1398,  1399,  1400,  1401,  1403,  1404,  1405,  1406,
    1407,  1408,  1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,
    1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,  1428,
    1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1442,  1443,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,
    1470,  1471,  1472,  1473,  1474,  1476,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,  1520,
    1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1530,  1531,
    1532,  1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,  1543,
    1544,  1545,  1546,  1548,  1549,  1550,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,  1558,  1559,  1560,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,
    1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1606,
    1607,  1608,  1609,  1611,  1612,  1613,  1614,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1642,
    1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   724,   725,   726,   727,   728,   729,   729,   730,   730,
     731,   732,   732,   732,   732,   732,   732,   733,   733,   733,
     733,   733,   734,   734,   735,   735,   737,   736,   736,   738,
     738,   739,   739,   739,   739,   739,   739,   739,   739,   739,
     739,   739,   739,   739,   739,   739,   739,   739,   740,   740,
     742,   741,   743,   743,   744,   744,   744,   744,   744,   744,
     744,   744,   744,   745,   746,   747,   746,   746,   746,   746,
     746,   748,   749,   746,   750,   751,   752,   746,   753,   754,
     746,   755,   756,   746,   757,   758,   759,   746,   760,   760,
     761,   761,   761,   762,   762,   763,   763,   764,   764,   765,
     765,   766,   766,   768,   767,   769,   767,   770,   770,   771,
     771,   772,   773,   774,   773,   775,   776,   775,   778,   777,
     780,   779,   781,   781,   781,   781,   781,   781,   782,   783,
     783,   784,   784,   785,   786,   786,   787,   788,   790,   791,
     789,   792,   792,   793,   793,   794,   794,   795,   795,   795,
     796,   796,   798,   797,   799,   797,   800,   797,   801,   797,
     802,   797,   803,   803,   804,   804,   805,   805,   805,   805,
     805,   805,   806,   807,   807,   808,   808,   809,   809,   810,
     810,   812,   813,   811,   811,   814,   814,   816,   815,   817,
     817,   817,   817,   817,   818,   817,   819,   819,   819,   819,
     820,   821,   821,   822,   822,   823,   823,   823,   823,   825,
     824,   826,   824,   827,   824,   828,   828,   829,   829,   830,
     831,   831,   831,   832,   834,   833,   835,   833,   836,   833,
     837,   837,   838,   839,   840,   840,   842,   843,   841,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   844,
     845,   844,   846,   844,   847,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   844,   848,   848,   849,   850,   851,
     852,   852,   853,   855,   854,   856,   856,   856,   856,   856,
     856,   856,   858,   857,   859,   859,   860,   860,   861,   863,
     862,   864,   864,   864,   864,   864,   864,   864,   865,   866,
     866,   868,   867,   869,   869,   869,   869,   869,   869,   869,
     869,   869,   869,   869,   869,   869,   869,   869,   869,   869,
     869,   869,   869,   869,   869,   869,   870,   872,   871,   873,
     871,   875,   874,   876,   874,   877,   877,   878,   879,   879,
     880,   881,   881,   881,   881,   881,   881,   881,   881,   882,
     883,   884,   886,   887,   885,   888,   888,   889,   890,   890,
     890,   891,   891,   893,   892,   894,   892,   895,   892,   896,
     897,   898,   899,   899,   900,   900,   900,   900,   900,   900,
     900,   900,   900,   901,   901,   901,   901,   901,   901,   901,
     901,   902,   902,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,   904,   905,   905,   906,   906,   907,   907,
     908,   908,   909,   909,   910,   911,   911,   912,   912,   912,
     912,   912,   912,   913,   913,   914,   914,   914,   914,   915,
     915,   916,   917,   917,   917,   918,   917,   919,   919,   920,
     920,   921,   921,   921,   921,   922,   922,   923,   923,   923,
     923,   923,   923,   923,   923,   924,   925,   926,   926,   926,
     926,   926,   926,   927,   927,   927,   927,   927,   927,   927,
     928,   930,   931,   929,   932,   933,   929,   935,   936,   934,
     937,   938,   934,   939,   940,   934,   941,   942,   934,   934,
     934,   934,   934,   934,   934,   934,   934,   943,   943,   944,
     945,   945,   945,   945,   945,   945,   945,   945,   945,   946,
     946,   947,   947,   947,   947,   948,   948,   948,   949,   949,
     950,   950,   950,   951,   951,   951,   951,   951,   951,   951,
     951,   951,   951,   952,   952,   953,   953,   954,   954,   956,
     957,   955,   958,   958,   960,   961,   962,   959,   963,   963,
     965,   966,   964,   967,   967,   968,   968,   969,   969,   971,
     970,   972,   970,   973,   973,   974,   974,   976,   975,   977,
     975,   978,   979,   979,   979,   980,   980,   981,   981,   982,
     982,   983,   983,   985,   984,   986,   984,   987,   984,   988,
     984,   989,   984,   990,   991,   991,   991,   991,   991,   991,
     991,   992,   992,   993,   994,   995,   996,   996,   996,   996,
     996,   996,   996,   996,   997,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1004,  1005,  1006,  1007,  1007,  1008,  1008,
    1009,  1009,  1009,  1009,  1009,  1009,  1010,  1011,  1011,  1012,
    1013,  1013,  1014,  1015,  1015,  1016,  1017,  1018,  1018,  1018,
    1019,  1019,  1019,  1021,  1020,  1022,  1022,  1023,  1023,  1024,
    1024,  1025,  1026,  1026,  1027,  1028,  1028,  1029,  1030,  1030,
    1031,  1032,  1032,  1034,  1035,  1033,  1036,  1037,  1036,  1038,
    1039,  1036,  1040,  1040,  1041,  1043,  1042,  1042,  1044,  1044,
    1045,  1045,  1046,  1047,  1047,  1047,  1048,  1048,  1049,  1049,
    1051,  1050,  1052,  1050,  1053,  1050,  1054,  1050,  1055,  1050,
    1056,  1050,  1057,  1050,  1058,  1050,  1059,  1050,  1060,  1050,
    1061,  1050,  1062,  1050,  1063,  1050,  1064,  1064,  1065,  1065,
    1066,  1067,  1068,  1068,  1068,  1070,  1069,  1071,  1071,  1072,
    1071,  1073,  1074,  1074,  1074,  1074,  1075,  1075,  1076,  1077,
    1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1079,  1078,
    1078,  1081,  1080,  1082,  1083,  1084,  1084,  1085,  1085,  1086,
    1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,
    1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1088,  1090,
    1091,  1089,  1092,  1092,  1093,  1094,  1095,  1096,  1096,  1098,
    1097,  1099,  1099,  1100,  1100,  1101,  1101,  1101,  1101,  1101,
    1101,  1102,  1102,  1103,  1103,  1104,  1105,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,  1105,  1105,  1105,  1106,  1107,  1107,
    1108,  1109,  1109,  1111,  1112,  1113,  1114,  1110,  1115,  1117,
    1118,  1116,  1119,  1120,  1120,  1121,  1121,  1122,  1123,  1123,
    1124,  1126,  1125,  1127,  1127,  1127,  1127,  1129,  1130,  1131,
    1128,  1133,  1132,  1134,  1136,  1135,  1137,  1135,  1138,  1135,
    1139,  1139,  1140,  1140,  1141,  1141,  1142,  1142,  1142,  1143,
    1144,  1145,  1146,  1146,  1146,  1147,  1147,  1148,  1148,  1150,
    1151,  1149,  1152,  1152,  1154,  1153,  1155,  1153,  1156,  1157,
    1157,  1157,  1157,  1158,  1158,  1158,  1158,  1158,  1159,  1160,
    1160,  1161,  1162,  1163,  1163,  1164,  1165,  1165,  1165,  1165,
    1165,  1165,  1166,  1167,  1168,  1168,  1169,  1169,  1170,  1171,
    1171,  1172,  1172,  1173,  1174,  1175,  1175,  1175,  1175,  1175,
    1175,  1176,  1176,  1177,  1178,  1178,  1179,  1179,  1180,  1180,
    1181,  1181,  1182,  1182,  1182,  1182,  1182,  1183,  1183,  1184,
    1184,  1185,  1185,  1186,  1187,  1188,  1188,  1189,  1190,  1190,
    1190,  1191,  1191,  1192,  1192,  1193,  1194,  1194,  1195,  1195,
    1196,  1197,  1198,  1199,  1199,  1200,  1201,  1201,  1202,  1202,
    1203,  1203,  1204,  1205,  1205,  1206,  1206,  1206,  1206,  1207,
    1207,  1207,  1208,  1209,  1209,  1210,  1210,  1210,  1211,  1212,
    1212,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1214,  1215,  1215,
    1216,  1216,  1216,  1216,  1216,  1217,  1219,  1218,  1220,  1220,
    1221,  1222,  1222,  1223,  1223,  1224,  1224,  1226,  1225,  1227,
    1229,  1228,  1230,  1230,  1231,  1231,  1232,  1232,  1233,  1233,
    1233,  1233,  1234,  1234,  1235,  1236,  1236,  1237,  1238,  1239,
    1240,  1241,  1241,  1242,  1242,  1244,  1243,  1245,  1243,  1246,
    1243,  1247,  1243,  1248,  1243,  1249,  1243,  1250,  1243,  1251,
    1251,  1251,  1251,  1251,  1251,  1253,  1252,  1254,  1254,  1256,
    1255,  1255,  1255,  1255,  1255,  1257,  1257,  1258,  1258,  1259,
    1260,  1260,  1262,  1261,  1263,  1264,  1265,  1265,  1265,  1266,
    1266,  1266,  1266,  1267,  1268,  1268,  1269,  1269,  1270,  1271,
    1271,  1271,  1271,  1271,  1271,  1271,  1271,  1272,  1272,  1273,
    1273,  1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,
    1274,  1275,  1275,  1276,  1276,  1276,  1276,  1277,  1277,  1278,
    1278,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,
    1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,
    1279,  1279,  1279,  1279,  1279,  1280,  1280,  1280,  1282,  1283,
    1284,  1285,  1286,  1287,  1281,  1288,  1288,  1289,  1290,  1290,
    1292,  1293,  1294,  1295,  1296,  1297,  1291,  1298,  1300,  1301,
    1302,  1299,  1303,  1303,  1303,  1303,  1304,  1304,  1304,  1304,
    1304,  1305,  1306,  1306,  1306,  1306,  1307,  1307,  1309,  1310,
    1308,  1311,  1312,  1308,  1313,  1313,  1314,  1314,  1315,  1315,
    1315,  1315,  1315,  1316,  1317,  1317,  1318,  1318,  1319,  1319,
    1320,  1320,  1320,  1320,  1320,  1321,  1321,  1322,  1322,  1323,
    1323,  1323,  1324,  1324,  1325,  1325,  1326,  1326,  1327,  1327,
    1327,  1328,  1328,  1329,  1329,  1329,  1329,  1329,  1329,  1329,
    1330,  1330,  1331,  1331,  1332,  1332,  1333,  1333,  1334,  1334,
    1335,  1336,  1336,  1337,  1337,  1338,  1339,  1339,  1340,  1341,
    1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,
    1347,  1347,  1347,  1347,  1347,  1347,  1347,  1347,  1347,  1347,
    1347,  1348,  1348,  1349,  1349,  1350,  1351,  1353,  1352,  1355,
    1354,  1354,  1356,  1356,  1357,  1357,  1358,  1358,  1359,  1359,
    1361,  1360,  1362,  1363,  1363,  1364,  1365,  1364,  1366,  1367,
    1366,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1369,
    1370,  1371,  1372,  1372,  1373,  1374,  1374,  1375,  1375,  1375,
    1376,  1377,  1378,  1378,  1379,  1380,  1380,  1380,  1382,  1381,
    1383,  1383,  1383,  1383,  1383,  1383,  1383,  1383,  1383,  1383,
    1383,  1383,  1384,  1384,  1384,  1384,  1385,  1385,  1385,  1386,
    1386,  1386,  1387,  1387,  1387,  1388,  1388,  1389,  1389,  1389,
    1389,  1389,  1389,  1390,  1390,  1391,  1391,  1392,  1392,  1393,
    1393,  1394,  1395,  1395,  1396,  1396,  1397,  1397,  1398,  1399,
    1400,  1401,  1402,  1402,  1403,  1403,  1404,  1404,  1404,  1405,
    1405,  1406,  1406,  1406,  1407,  1407,  1407,  1407,  1408,  1409,
    1409,  1410,  1410,  1411,  1411,  1412,  1413,  1413,  1413,  1413,
    1413,  1413,  1413,  1414,  1415,  1416,  1417,  1417,  1418,  1418,
    1419,  1420,  1421,  1421,  1422,  1423,  1424,  1424,  1425,  1425,
    1425,  1426,  1426,  1427,  1427,  1428,  1429,  1429,  1430,  1430,
    1431,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1436,  1437,  1437,  1438,  1439,  1440,  1440,  1440,  1440,
    1441,  1441,  1442,  1442,  1443,  1443,  1444,  1444,  1444,  1444,
    1444,  1444,  1444,  1444,  1444,  1445,  1445,  1445,  1445,  1445,
    1445,  1445,  1445,  1445,  1446,  1446,  1446,  1447,  1447,  1447,
    1447,  1448,  1448,  1448,  1449,  1449,  1450,  1450,  1450,  1450,
    1450,  1450,  1450,  1450,  1450,  1450,  1450,  1450,  1450,  1450,
    1450,  1450,  1450,  1450,  1450,  1450,  1450,  1450,  1450,  1450,
    1450,  1451,  1451,  1452,  1452,  1452,  1452,  1452,  1453,  1454,
    1455,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1458,  1459,  1459,
    1459,  1460,  1460,  1461,  1461,  1461,  1462,  1463,  1463,  1463,
    1463,  1464,  1465,  1466,  1466,  1467,  1467,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1469,  1469,  1469,  1469,  1469,
    1469,  1469,  1469,  1470,  1470,  1470,  1470,  1470,  1470,  1470,
    1471,  1471,  1471,  1471,  1471,  1471,  1471,  1471,  1472,  1472,
    1472,  1473,  1475,  1474,  1476,  1474,  1477,  1474,  1478,  1474,
    1479,  1479,  1479,  1480,  1480,  1481,  1481,  1481,  1482,  1482,
    1483,  1483,  1484,  1486,  1487,  1485,  1488,  1489,  1489,  1490,
    1491,  1491,  1491,  1491,  1491,  1492,  1493,  1493,  1494,  1495,
    1496,  1496,  1496,  1496,  1497,  1497,  1498,  1498,  1498,  1499,
    1500,  1500,  1500,  1501,  1501,  1501,  1501,  1501,  1501,  1501,
    1501,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,
    1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,  1502,
    1502,  1502,  1502,  1503,  1503,  1504,  1505,  1506,  1506,  1507,
    1507,  1508,  1508,  1509,  1509,  1510,  1510,  1511,  1512,  1512,
    1513,  1513,  1514,  1515,  1515,  1515,  1516,  1516,  1517,  1518,
    1519,  1520,  1521,  1521,  1522,  1522,  1522,  1522,  1522,  1522,
    1523,  1523,  1523,  1523,  1524,  1524,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1526,  1526,  1526,  1527,  1527,  1527,
    1527,  1527,  1527,  1529,  1528,  1530,  1530,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,  1531,
    1531,  1531,  1531,  1531,  1531,  1531,  1533,  1532,  1535,  1534,
    1537,  1538,  1536,  1539,  1539,  1539,  1540,  1540,  1540,  1540,
    1540,  1540,  1541,  1541,  1542,  1543,  1544,  1544,  1545,  1545,
    1546,  1546,  1547,  1547,  1547,  1548,  1548,  1548,  1548,  1548,
    1548,  1548,  1548,  1548,  1548,  1548,  1548,  1548,  1548,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1550,  1551,  1551,  1553,  1552,
    1554,  1554,  1555,  1555,  1556,  1557,  1558,  1558,  1559,  1559,
    1560,  1560,  1560,  1561,  1561,  1562,  1562,  1563,  1564,  1564,
    1565,  1565,  1566,  1567,  1569,  1570,  1568,  1571,  1571,  1572,
    1572,  1573,  1573,  1573,  1573,  1573,  1573,  1573,  1574,  1574,
    1575,  1575,  1576,  1576,  1577,  1577,  1578,  1579,  1580,  1581,
    1581,  1582,  1583,  1583,  1584,  1585,  1585,  1587,  1586,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588,
    1588,  1588,  1588,  1588,  1588,  1588,  1588,  1588
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
       1,     1,     2,     1,     1,     2,     1,     1,     0,     0,
       5,     7,     8,     0,     2,     1,     3,     1,     3,     3,
       1,     2,     0,     4,     0,     4,     0,     3,     0,     3,
       0,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     0,     4,     1,     1,     0,     1,     1,
       2,     0,     0,     5,     1,     1,     3,     0,     2,     4,
       4,     4,     4,     2,     0,     4,     1,     1,     1,     2,
       1,     1,     3,     0,     1,     0,     1,     1,     1,     0,
       7,     0,     5,     0,    12,     1,     1,     1,     1,     1,
       5,     3,     1,     1,     0,     4,     0,     5,     0,     7,
       1,     3,     1,     1,     0,     1,     0,     0,     4,     1,
       1,     1,     1,     4,     4,     4,     6,     4,     6,     1,
       2,     1,     1,     1,     1,     4,     6,     1,     4,     6,
       0,     3,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     0,     3,     4,     1,     1,
       0,     3,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     0,     2,     0,     3,     0,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       1,     0,     5,     1,     1,     1,     4,     4,     6,     1,
       1,     1,     1,     4,     6,     1,     4,     6,     1,     1,
       1,     1,     1,     2,     2,     1,     4,     0,     7,     0,
      12,     0,     4,     0,     5,     1,     3,     2,     1,     3,
       1,     0,     2,     2,     1,     2,     5,     4,     2,     4,
       5,     3,     0,     0,    11,     0,     2,     1,     0,     2,
       1,     1,     2,     0,     3,     0,     3,     0,     3,     2,
       2,     2,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     1,
       3,     4,     4,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     1,     0,     3,     2,     2,     1,
       3,     4,     4,     5,     5,     1,     1,     2,     2,     4,
       4,     2,     2,     4,     4,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     0,     0,     6,     0,     0,     8,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     5,
       5,     5,     7,     7,     9,     4,     6,     0,     3,     1,
       1,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     4,     4,     2,     2,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     2,     4,     6,     6,     3,     5,
       5,     3,     1,     1,     3,     1,     3,     1,     3,     0,
       0,    11,     0,     2,     0,     0,     0,     9,     0,     3,
       0,     0,    10,     0,     1,     0,     1,     1,     2,     0,
       3,     0,     3,     0,     1,     1,     2,     0,     3,     0,
       3,     3,     1,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     0,     3,     0,     3,     0,     4,     0,
       4,     0,     4,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     6,     4,
       3,     6,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     4,     1,     1,
       1,     4,     3,     6,     3,     6,     1,     1,     2,     2,
       1,     2,     2,     1,     3,     1,     2,     2,     2,     4,
       2,     2,     4,     0,     8,     0,     1,     1,     1,     0,
       1,     2,     0,     1,     2,     0,     1,     2,     0,     1,
       3,     0,     2,     0,     0,     8,     0,     0,     3,     0,
       0,     7,     5,     2,     2,     0,     5,     4,     1,     3,
       3,     3,     1,     0,     2,     1,     0,     1,     1,     2,
       0,     4,     0,     4,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     3,     1,     3,
       2,     4,     1,     1,     1,     0,     4,     5,     6,     0,
      10,     3,     2,     2,     1,     1,     0,     2,     1,     2,
       3,     3,     3,     3,     1,     1,     1,     1,     0,     3,
       1,     0,     3,     2,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     7,     1,     1,     2,     2,     2,     3,     4,     0,
       3,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     0,     0,     0,     0,    13,     1,     0,
       0,     6,     2,     1,     2,     2,     2,     1,     1,     2,
       1,     0,     3,     2,     1,     1,     1,     0,     0,     0,
      14,     0,     5,     1,     0,     3,     0,     7,     0,     5,
       1,     2,     0,     1,     1,     1,     0,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     0,
       0,     7,     1,     2,     0,     3,     0,     4,     2,     0,
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
       2,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       2,     4,     4,     6,     2,     1,     0,    11,     0,     2,
       5,     0,     1,     0,     2,     1,     2,     0,     3,     1,
       0,     4,     0,     2,     1,     3,     1,     1,     3,     4,
       4,     2,     1,     1,     1,     0,     1,     7,     2,     2,
       2,     2,     2,     1,     2,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     4,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     1,     0,
       4,     1,     2,     2,     2,     0,     1,     1,     2,     2,
       0,     2,     0,     4,     3,     5,     0,     2,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     3,     2,     5,
       2,     5,     5,     5,     5,     5,     5,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     0,     3,     2,     0,     0,
       0,     0,     0,     0,    15,     0,     2,     2,     0,     1,
       0,     0,     0,     0,     0,     0,    15,     2,     0,     0,
       0,    10,     0,     1,     3,     3,     2,     4,     3,     3,
       3,     1,     2,     2,     2,     2,     1,     1,     0,     0,
       8,     0,     0,     9,     0,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       8,     2,     2,     4,     2,     0,     1,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     2,     1,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     3,     1,     3,     2,     4,     1,     3,
       1,     2,     4,     1,     3,     1,     1,     1,     2,     3,
       4,     2,     4,     0,     2,     2,     4,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     6,
       6,     0,     1,     0,     1,     2,     1,     0,     5,     0,
       5,     1,     0,     3,     1,     3,     1,     3,     1,     1,
       0,     4,     1,     2,     1,     0,     0,     3,     0,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     3,     1,     3,     2,     1,     1,     0,     1,     1,
       1,     1,     0,     1,     3,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     7,     6,     4,     4,     1,     1,     1,     0,
       1,     2,     1,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     1,     0,     3,     1,     3,     1,     3,     1,
       1,     6,     0,     3,     1,     3,     0,     1,     4,     5,
       2,     1,     1,     4,     1,     3,     4,     4,     4,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     4,     0,
       1,     0,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       2,     2,     1,     3,     2,     2,     1,     3,     1,     2,
       4,     1,     2,     1,     3,     4,     0,     1,     0,     1,
       0,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       2,     2,     0,     2,     1,     1,     5,     3,     5,     3,
       1,     3,     1,     1,     0,     1,     3,     3,     3,     6,
       4,     4,     4,     4,     5,     1,     1,     1,     1,     1,
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
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     3,     0,     7,     0,     8,     0,     6,     0,     8,
       0,     1,     2,     1,     3,     1,     3,     5,     1,     1,
       1,     1,     1,     0,     0,     9,     5,     1,     1,     6,
       0,     3,     1,     3,     4,     1,     0,     2,     4,     6,
       0,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       1,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       4,     3,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     5,     4,     4,     3,
       4,     1,     1,     1,     3,     1,     5,     7,     5,     0,
       2,     1,     1,     0,     3,     1,     3,     1,     1,     1,
       0,     3,     1,     1,     1,     1,     4,     6,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     4,     5,     1,     4,     4,     4,     6,     6,
       8,     8,    13,    11,     1,     7,     4,     4,     4,     6,
       6,     8,     8,     0,     4,     1,     2,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     0,     3,     0,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     821,     0,  2233,     0,     0,     0,   871,   181,     0,   847,
     850,   179,   184,   825,     0,   819,   822,   823,   826,   829,
     830,   828,   867,   868,   870,   827,   136,   133,     0,   129,
     131,   130,   134,  2261,   704,   644,   311,  1680,  1678,   865,
     177,   187,   866,   180,     1,   831,   824,   869,   128,   132,
     135,     0,     0,   621,     0,     0,   178,   874,   940,   622,
     875,   876,   872,   656,   932,     0,   933,   941,   939,   187,
     182,   200,     0,   185,   201,   236,     0,   852,  1230,     0,
       0,   851,   137,  1218,   859,     0,     0,   843,   845,   842,
     844,   820,   832,   833,   853,   836,   837,   838,   841,   839,
     840,   846,     0,  1679,   934,   873,     0,     0,   948,   946,
     947,   936,   935,   309,   187,  1154,   194,   188,   187,   193,
     233,     0,   703,     0,     0,     0,     0,   177,   570,   909,
     834,     0,   343,   329,   203,   315,   280,   299,   320,   322,
     319,     0,   341,     0,   328,   321,   325,   331,   330,   187,
     332,   312,   335,   313,   314,   945,   944,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     953,     0,   528,   520,    16,   527,   940,    15,     0,   951,
       0,   310,     0,   186,  1155,   183,     0,   200,   202,   274,
     205,   262,   268,   269,   253,   226,   264,   203,   241,   242,
       0,   228,   280,   299,   251,   254,   249,     0,   224,     0,
     260,   252,   257,   267,   266,   187,   270,   187,   239,   240,
     237,   273,     0,     0,     0,     0,   860,   177,   177,     0,
       0,   204,     0,     0,   333,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,   278,     0,   942,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     534,     0,     0,     0,   657,   445,   447,  1225,     0,     0,
       0,  1645,     0,   439,     0,     0,     0,   438,     0,   455,
     530,     0,     0,     0,     0,     0,   533,     0,   404,   403,
     410,   451,   448,   405,   406,   408,   409,   446,   449,   454,
     529,   500,   497,   506,   503,     0,     0,    17,    18,    19,
      20,    21,     0,    14,   491,     0,     0,   949,     0,   189,
     192,   190,   191,     0,   197,   196,   195,   198,   206,   207,
     208,   211,   275,   187,   275,     0,     0,     0,     0,   187,
     271,   272,     0,     0,   187,     0,   275,     0,     0,   250,
     234,  1231,     0,     0,  1219,  2267,   571,   910,   854,     0,
     215,   216,     0,     0,   292,   294,   289,   290,   286,   288,
     285,   287,   284,     0,   294,   305,   306,   302,   304,   301,
     303,   296,     0,     0,     0,   345,     0,   348,   350,   223,
       0,   222,     0,   187,     0,     0,   555,   626,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   538,   543,     0,
     539,   542,   541,   635,     0,   634,   557,     0,    11,   173,
     437,   412,   411,     0,  1160,     0,     0,   453,  1653,  1651,
    1652,  1648,  1650,  1647,  1649,  1641,     0,     0,     0,   452,
       0,     0,     0,     0,     0,     0,     0,   658,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   535,   536,   537,   466,     0,     0,   465,   475,     0,
       0,   416,     0,     0,   417,   407,   413,   415,   418,   419,
     420,   421,   422,   414,   444,   443,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   952,     0,   937,   199,
       0,     0,   263,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,   187,   235,   238,   964,
     702,   877,   964,     0,  2265,  2267,  1154,  1780,   848,     0,
     964,     0,     0,   316,   281,     0,     0,   291,   308,   282,
     307,     0,   300,     0,   323,     0,   317,     0,   342,     0,
     347,   337,     0,     0,   326,   279,   336,     0,     0,   526,
       0,     0,   523,   522,   525,   521,   532,   517,     0,   517,
       0,   540,     0,   544,     0,   299,     0,   524,   531,   283,
       0,  1226,  1720,     0,     0,     0,     0,     0,   440,     0,
       0,   456,     0,     0,     0,     0,   458,   457,   476,   467,
     482,   485,   486,   483,   489,   488,   487,   477,   478,   479,
     480,   481,   423,   468,   472,   490,   484,   471,   490,   450,
     501,   498,   507,   504,   515,     0,    98,   492,    94,    95,
      97,   494,     0,     0,   236,     0,     0,     0,   243,   244,
       0,   247,     0,     0,   255,     0,   245,   225,   209,     0,
     258,   277,   970,     0,   965,   966,   964,     0,   861,  2266,
    2264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2248,     0,  1346,  1345,
       0,  1347,     0,   397,  1344,  1261,     0,     5,  1343,   398,
     395,     0,   400,   175,   490,  1131,     0,     0,  1353,   125,
     394,   393,     0,     0,   388,   490,     0,  1297,  2241,     0,
     399,   362,     0,     3,     2,     0,   396,  1258,     0,     0,
     389,   386,   401,     0,     0,     0,     0,  1351,  1341,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1340,     0,
       0,     0,   176,     0,   385,   384,     0,     0,  2245,  2244,
       0,     0,     0,   138,     0,   391,   390,     0,     0,   387,
     490,     0,     0,   490,     0,   564,     0,     0,     0,     0,
       0,     0,   490,   808,  1228,     0,     0,  1142,     0,  2234,
       0,   105,     0,     0,   881,     0,     0,     0,     0,   809,
       0,     0,  1823,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   673,     0,     0,  2269,  2270,  2271,  2272,  2273,
    2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,  2282,  2283,
    2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,  2292,  2293,
    2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,
    2304,  2305,  2306,  2307,  2308,  2309,  2310,  2311,  2312,  2313,
    2314,  2315,  2316,  2317,  2318,   919,  2319,  2320,  2321,  2322,
    2323,  2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,
    2333,  2334,  2335,  1122,  1124,  1119,  1121,  1120,  1123,  2336,
    2337,  1251,  2338,  1257,  1256,  2339,  2340,  2341,  2342,  2343,
    2344,  2345,  2346,  2347,  2348,  1408,  2349,  2350,  2351,  2352,
    2353,  2354,  2355,  2356,  2357,  2268,   849,   575,     0,   914,
       0,   912,     0,   344,   217,   218,     0,   293,   298,     0,
       0,     0,     0,   346,   349,     0,   221,     0,     0,   556,
       0,   630,     0,   632,   510,     0,     0,   511,     0,   554,
       0,   551,   548,   519,   509,   558,     0,   172,  1722,  1723,
    1721,     0,   442,  1225,     0,  1646,  1225,   441,  1225,  1225,
    1225,  1225,  1225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,   950,
       0,   212,   276,   227,     0,     0,   187,     0,     0,     0,
       0,     0,  1232,     0,     0,  1220,   381,   379,   380,  1255,
    1059,  1058,  1064,     0,  1620,  1621,     0,     0,  1281,   645,
     646,  1282,  1612,  1613,  1284,   835,  1094,  1099,  2243,   638,
     124,  2256,     0,     0,  1296,     7,     0,     6,     0,  2249,
    1095,     0,  1188,  1187,  1134,  1186,  1133,   434,  1354,  1342,
       0,  1252,   862,   424,  1782,  1348,   126,     0,  1098,   123,
       0,   815,    24,   640,   402,     0,   814,  1091,   816,     0,
    1352,   903,   902,   905,   901,   904,  2258,     0,   899,     0,
     639,   996,   900,  2252,     0,  2242,   122,  1254,   993,   705,
     991,     0,   636,  2237,   753,   752,   754,   750,     0,     0,
    1253,  1006,   641,  1407,     0,  2224,  1402,  1405,  2214,  2217,
    2218,  2220,  2223,     0,     0,     0,     0,  1065,  1060,     0,
    1045,  1046,  1047,  1048,  1054,  1056,  1055,  1053,  1052,     0,
       0,     0,  1051,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1037,  1028,  1029,   979,
       0,   977,  1079,   432,    24,     0,  2239,   127,   637,     0,
    1229,  1227,  1153,     0,  1771,  1772,  1154,  1135,  1355,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,   940,
       0,    69,     0,   103,   613,     0,   660,   659,     0,  1125,
    1013,  1129,     0,     0,  1080,  1246,     0,     0,  1132,   665,
     662,   663,     0,   667,   668,     0,   670,   671,     0,   666,
     974,   976,     0,     0,   975,   755,   972,   716,   968,   931,
       0,     0,     0,     0,   677,   678,     0,     0,   929,   926,
     927,   923,   924,   925,   918,   922,   921,     0,     0,     0,
       0,     0,     0,   579,   581,   573,   576,   577,   916,  2267,
     911,   913,   855,     0,   295,   297,   324,   318,     0,     0,
     327,   627,   629,     0,     0,     0,   517,   517,   545,     0,
     292,     0,     0,  1750,  1637,  1639,  1751,     0,     0,  1643,
    1748,     0,     0,  1747,     0,     0,     0,  1749,     0,     0,
       0,     0,     0,     0,     0,  2224,  1638,  1746,  1640,  1735,
       0,  1724,  1726,  1730,  1733,  1761,  1804,  1762,  1814,  2225,
    2215,  1734,  1163,  1654,  1162,  1161,  1164,  1166,  1165,  1159,
     469,   470,   474,   459,     0,   462,   473,     0,   461,   502,
     499,   508,   505,   516,   493,    96,   495,   938,     0,   248,
     232,     0,   230,   256,   246,   236,   259,   971,   177,   967,
     878,   177,     0,     0,     0,  1326,  1327,     0,     0,     0,
    1298,  1301,  1303,  1304,  1305,  1309,  1308,  1306,  1307,     0,
       0,     0,  1299,  1300,     0,     0,     0,     0,     0,     0,
       0,     0,  1096,     0,    24,  1183,  1185,  1184,     0,   427,
     428,   425,   426,   984,     0,     0,   367,    25,   361,     0,
       0,  1088,     0,     0,     0,     0,     0,     0,     0,  1000,
    1781,     0,     0,     0,     0,     0,     0,  2239,     0,     0,
     139,     0,     0,  1010,  1002,  1003,  1008,     0,     0,  2216,
       0,  2227,  1403,  1404,     0,     0,   928,   430,  2208,  1023,
     351,     0,     0,   565,   618,   617,   615,   620,  1031,   619,
    1036,  1032,  1035,   807,   799,   793,   805,   806,   791,   792,
     800,   795,   801,   794,   804,   798,   802,   797,   803,   790,
     796,   783,   789,  1033,  1034,     0,  1041,  1049,  1038,  1039,
    1043,  1044,  1042,  1040,  1050,     0,     0,     0,   817,     0,
       0,     0,     0,     0,   765,   764,   761,  2240,  2247,    24,
    1149,  1150,  1151,  1152,  1146,  1144,  1242,  1154,  1136,  1137,
    1140,  1156,  2235,     0,     0,     0,     0,    99,     0,   100,
       0,     0,     0,    74,     0,     0,     0,   112,   107,     0,
     661,   908,     0,   907,     0,   490,  1127,     0,   959,   960,
     983,   954,   955,   810,   981,  1082,  1248,     0,  1250,  1249,
    1879,  1996,  1992,  1998,  2030,  2010,  2001,  1960,  1922,  2049,
    2016,  2024,  1913,  2019,  1880,  1827,  2011,  1918,  1969,  2103,
    1948,  1936,  1949,  2047,  2050,  2018,  1972,  2053,  1839,  2110,
    2046,  2074,  1850,  2146,  1937,  2119,  1832,  2079,  1848,  1908,
    1955,  1975,  2069,  2097,  2102,  1831,  2027,  2055,  1843,  1845,
    1868,  1886,  1906,  1916,  1926,  1979,  1982,  2040,  2051,  2057,
    2058,  2075,  2120,  2131,  1830,  1861,  1885,  1884,  1892,  1894,
    1902,  1912,  1933,  1951,  1954,  1980,  1988,  2044,  2054,  2064,
    2070,  2071,  2073,  2098,  2128,  2139,  1851,  1854,  1865,  1871,
    1873,  1878,  1881,  1883,  1889,  1897,  1899,  1900,  1901,  1911,
    1921,  1928,  1944,  1945,  1956,  1974,  1978,  1991,  2007,  2038,
    2048,  2052,  2059,  2067,  2076,  2086,  2090,  2107,  2113,  2117,
    2125,  2130,  2133,  1874,  1993,  2035,  1859,  1860,  1877,  1882,
    1888,  1890,  1904,  1905,  1915,  1924,  1929,  1931,  1932,  1938,
    1946,  1963,  1964,  1977,  2005,  2009,  2012,  2017,  2021,  2029,
    2036,  2037,  2042,  2060,  2061,  2066,  2072,  2077,  2083,  2084,
    2085,  2087,  2089,  2091,  2100,  2122,  2123,  2124,  2129,  2145,
    1834,  1987,  1995,  1997,  2093,  1836,  1840,  1844,  1849,  1855,
    1856,  1869,  1870,  1872,  1875,  1887,  1903,  1923,  1925,  1935,
    1939,  1941,  1942,  1950,  1959,  1961,  1962,  1973,  1986,  2004,
    2022,  2023,  2039,  2041,  2045,  2056,  2078,  2088,  2096,  2118,
    2121,  2135,  2136,  2137,  1867,  1837,  1857,  1858,  1864,  1934,
    1866,  1891,  1893,  1907,  1984,  2108,  1917,  1919,  1927,  1930,
    1952,  1953,  1958,  1965,  1966,  1967,  2148,  1999,  2000,  2003,
    2008,  2013,  2020,  2025,  2026,  2028,  2034,  2063,  2065,  2081,
    2092,  2094,  2095,  2099,  2104,  2105,  2109,  2111,  2112,  2127,
    2132,  2134,  2138,  2140,  2144,  1994,  2143,  1833,  1835,  1838,
    1842,  1852,  1876,  1895,  1896,  1898,  1909,  1940,  1943,  1983,
    1989,  2002,  2006,  2141,  2142,  2043,  2062,  2068,  2080,  2082,
    2101,  2106,  2116,  2126,  1847,  1841,  1846,  1863,  1914,  1957,
    1970,  1971,  2031,  2033,  2115,  1990,  1947,  2014,  1862,  1910,
    1920,  1985,  1968,  2015,  1853,  1976,  1981,  2114,  2032,     0,
    1825,  1828,  1829,   693,     0,     0,     0,   682,   716,   716,
     713,     0,     0,   717,     0,    26,   681,   684,     0,   691,
     687,   930,   920,  1778,  1779,  1769,  1769,  1372,     0,     0,
    1681,     0,     0,  1356,     0,     0,  1357,  1400,     0,     0,
    1401,     0,     0,  1720,     0,  1370,     0,  1419,  1418,  1417,
    1415,  1416,  1414,  1412,  1409,  1499,  1498,  1410,  1411,  1420,
    1702,  1413,  1785,  1784,  1783,  1421,  2267,  2267,   592,   583,
     574,     0,   578,  2267,   915,   177,     0,   338,   220,     0,
       0,  1661,  1659,  1660,  1656,  1658,  1655,  1657,   518,     0,
     513,   512,     0,   550,   549,   174,  1732,  1731,     0,     0,
    1669,  1667,  1668,  1664,  1666,  1663,  1665,  1642,     0,  1720,
       0,     0,  1567,     0,     0,  1738,  1736,  1737,  1567,  1567,
    1567,  1567,  1739,     0,     0,     0,  1516,  1710,     0,  1727,
       0,     0,     0,     0,  1794,  1795,  1796,  1797,  1798,  1799,
    1742,     0,     0,     0,     0,   464,   463,     0,     0,   187,
     229,   210,  1233,   177,  1221,     0,     0,     0,     0,     0,
       0,  1473,  1472,  1471,  1333,     0,  1339,  1335,  1337,  1328,
       0,  1576,  1325,  1321,  1295,  1294,     0,  1320,  1316,     0,
    1312,  1310,     0,  1619,     0,  1622,  1624,   649,     0,   648,
    1611,     0,  1614,  1616,  2257,  2254,     0,     0,  1262,   490,
     359,  1283,     0,     0,  1259,  1015,  1092,  1093,  1090,  1089,
       0,   906,     0,     0,   623,     0,     0,     0,   994,   992,
     707,   708,     0,   712,     0,     0,  2238,  2246,   751,     0,
     143,     0,  1004,  1011,     0,     0,  1019,  2219,  2232,     0,
    2230,  1406,  2222,  2221,     0,     0,     0,  1025,   354,     0,
       0,     0,     0,    24,  1061,  1062,   568,     0,     0,     0,
     784,   785,  1030,   980,   978,   818,   433,     0,  1071,   762,
     763,   382,     0,  1154,  1243,  1158,  1143,  1138,     0,     0,
    1139,  2267,     0,     0,     0,     0,     0,     0,     0,    64,
      93,     0,     0,   118,   113,     0,   108,     0,   115,   109,
     892,   884,   890,     0,  1126,     0,  1128,  1130,     0,     0,
     963,     0,     0,     0,     0,  1081,  1247,     0,     0,  1824,
    1826,  2267,   664,   669,   672,   685,   683,   642,     0,   740,
     738,   736,   734,   744,   742,     0,     0,   732,   780,   730,
     715,   726,   724,   778,   756,     0,   718,   728,   973,   969,
       0,     0,     0,     0,   690,     0,     0,     0,     0,     0,
       0,     0,  1627,     0,  1494,  1495,  1790,  1452,  1516,     0,
       0,     0,  1788,     0,  1432,  1427,  1426,  1439,  1438,  1443,
    1443,  1441,  1442,  1433,  1428,     0,     0,  1434,  1435,  1703,
    2150,     0,     0,     0,   580,   582,     0,     0,   595,   587,
     589,     0,   584,   585,     0,     0,   603,   605,     0,     0,
     601,   917,   856,   219,     0,   631,   633,   628,     0,   517,
     547,   546,     0,     0,     0,     0,     0,     0,  1759,  1643,
       0,     0,  1734,  1569,  1570,  1568,     0,  1763,     0,     0,
       0,     0,     0,     0,     0,  1725,     0,  1505,  1506,  1508,
    1511,     0,  1517,  1518,     0,     0,  1567,  1712,  1706,  1728,
    1744,  1745,  1743,  1741,     0,     0,     0,  2226,   460,   496,
       0,   231,  1189,   879,  1167,     0,     0,     0,     0,  1333,
       0,     0,     0,  1329,     0,     0,     0,  1323,  1607,  1605,
    1574,  1586,  1588,  1592,  1594,  1585,  1579,  1584,  1598,  1577,
    1606,  1582,  1597,  1583,  1604,  1596,  1479,  1571,  1572,  1573,
       0,  1318,  1314,     0,     0,  1302,     0,     0,   647,     0,
       0,     0,  2253,     0,     4,     8,    10,     0,   490,   429,
       0,     0,     0,  1012,     0,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,   160,   158,     0,     0,   140,
       0,   150,   156,   716,   145,   147,     0,  1009,  1020,  1021,
       0,     0,  2228,   431,     0,  2209,  2210,  1024,     0,     0,
    1022,   353,   358,   625,   352,     0,   355,   360,     0,   490,
    1378,   616,   614,     0,   787,  1070,  1072,     0,   383,  1147,
    1145,     0,  1157,  1141,     0,     0,  1238,     0,     0,     0,
     101,     0,     0,    75,    81,    71,  2267,  2267,   111,   106,
     120,   116,     0,   110,   781,   893,   642,  2267,   883,   882,
     891,  1014,     0,     0,   961,   962,   956,   982,   490,  1087,
    1083,  1084,  1086,  2147,  2149,   694,   688,   686,     0,    24,
       0,  2267,  2267,  2267,  2267,  2267,  2267,   746,   720,   748,
     722,  2267,  2267,  2267,  2267,     0,   714,   719,  2267,   642,
     776,   774,   777,   775,     0,     0,    46,    44,    41,    35,
      39,    43,    38,    31,    40,     0,    34,    37,    32,    42,
      33,    45,    36,     0,    29,    47,   768,     0,   692,  1770,
       0,  1768,  1720,  1766,  1707,  1708,  1700,  1686,  1701,     0,
       0,     0,  1057,  1493,  1496,     0,     0,     0,  1390,  1362,
    1793,  1792,  1791,     0,     0,     0,  1437,  1440,     0,     0,
       0,     0,     0,  1385,     0,  1384,     0,  1386,  1381,  1382,
    1383,  1374,  1375,     0,     0,     0,   594,   599,     0,     0,
    2267,  2267,   572,   586,   609,   597,   611,  2267,  2267,   607,
     591,   602,   848,   339,     0,   514,  1806,     0,  1807,     0,
    1817,     0,  1818,     0,  1676,  1674,  1675,  1671,  1673,  1670,
    1672,  1644,     0,     0,     0,     0,  1760,     0,     0,     0,
    1758,     0,     0,     0,     0,  1740,  1757,     0,  1509,     0,
    1636,  1512,     0,     0,     0,     0,  1504,  1522,  1524,  1526,
    1566,  1565,  1564,  1528,  1544,     0,  1519,  1520,  1715,  1285,
       0,     0,     0,  1805,     0,  1816,   213,     0,  1215,  1234,
     848,     0,  1222,  1215,     0,  1628,     0,  1461,     0,  1464,
    1631,     0,  1469,     0,     0,  1330,  1331,     0,     0,  1334,
    1336,  1338,     0,  1322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1477,  1476,  1475,     0,  1480,  1481,
       0,  1317,     0,  1311,  1313,  1623,     0,  1625,  1615,     0,
    1617,  2255,  1291,     0,  1287,     0,     0,  1292,   863,     0,
       0,     0,     0,     0,  1349,  2260,  2259,   624,     0,     0,
      48,     0,   709,   711,   710,  1350,   716,  2267,  2267,   152,
     650,   162,   154,   164,   144,   151,  2267,     0,     0,     0,
       0,     0,  2231,     0,     0,     0,     0,     0,     0,  1063,
       0,  1379,   566,     0,   786,  1068,     0,  1244,  1245,  2236,
       0,    93,     0,    65,     0,     0,     0,    78,     0,    93,
      93,   119,   114,  2267,  2267,   104,     0,   894,   888,   896,
     895,   885,   562,   943,     0,     0,     0,   696,   675,   689,
     643,   757,     0,   741,   739,   737,   735,   745,   743,     0,
    2267,     0,  2267,   733,   731,   727,   725,   779,   729,    24,
     769,     0,     0,     0,    27,     0,  1773,     0,  1687,     0,
       0,  1699,  1682,  1698,  1497,     0,  1454,     0,  1389,     0,
       0,  1789,     0,  1786,     0,  1445,  1449,  1425,  1447,  1450,
       0,  1436,  1704,     0,     0,     0,     0,     0,     0,  2151,
    1388,  1387,  1376,  1371,  1373,  1424,     0,     0,   596,   593,
     588,   590,     0,  2267,  2267,   604,   606,  2267,  2267,     0,
    1662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1756,  1764,  1752,  1753,  1754,  1755,  1513,     0,  1507,
    1527,  1531,     0,  1544,  1530,     0,     0,  1545,  1560,  1557,
    1558,  1555,  1563,  1562,  1556,  1559,     0,     0,     0,     0,
       0,  1561,     0,     0,     0,  1501,  1502,  1729,     0,  1521,
    1515,  1286,  1713,  1395,  1391,  1392,  1397,  1396,  1711,  1285,
       0,     0,  1213,  1214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1212,     0,     0,  1200,  1201,
    1202,  1199,  1204,  1205,  1206,  1203,  1190,  1181,     0,     0,
    1237,     0,  2267,     0,  1176,     0,     0,     0,     0,     0,
       0,     0,  1168,  1169,     0,  1100,  1632,     0,  1633,     0,
       0,     0,     0,  1468,  1467,  1333,  1466,  1458,  1324,  1608,
       0,     0,     0,     0,     0,     0,  1609,  1601,     0,     0,
       0,  1601,  1637,  1474,  1487,  1492,     0,  1489,  1486,  1488,
       0,  1490,  1478,  1482,  1483,  1333,  1319,  1315,     0,     0,
    1290,  1289,     0,  1274,     9,     0,  1264,   864,  1097,   365,
    1264,     0,     0,  2251,     0,     0,   995,    49,     0,   766,
     161,   159,     0,  2267,     0,     0,     0,  2267,   157,   146,
       0,   149,   148,     0,  1001,  1005,     0,  2213,  2212,  2211,
       0,     0,   357,     0,   569,     0,  2267,   788,     0,   642,
    1148,     0,  1239,    70,     0,     0,   102,    68,    93,    76,
      82,     0,   121,   117,   782,  2267,   898,   642,   897,     0,
     559,     0,   812,   813,   811,  1085,   699,   697,     0,   679,
     676,     0,   747,   721,   749,   723,   758,   772,   773,   770,
     771,    30,    28,     0,  1767,  1716,  1688,  1684,  1683,     0,
    1453,  1720,  1456,     0,  1364,  1359,  1358,  1361,     0,     0,
    1444,     0,     0,  1716,     0,     0,  2188,  2186,     0,     0,
    2170,  2185,     0,     0,  2187,     0,     0,     0,     0,     0,
    2224,  2184,  2176,  2203,  2204,     0,  2168,  2171,  2172,  2183,
    2175,  2205,     0,  2161,  2160,  2164,  2166,     0,  2159,     0,
    2162,  2153,     0,     0,   600,   598,   610,   612,   608,     0,
       0,     0,  1808,  1809,     0,     0,  1819,  1820,     0,     0,
    1719,     0,  1644,     0,     0,     0,  1510,  1529,  1523,  1525,
    1532,  1534,  1532,     0,  1539,  1532,     0,  1537,  1532,     0,
    1547,  1546,     0,  1548,     0,  1500,     0,  1399,  1398,  1394,
    1714,     0,   236,  1207,  1208,  1209,  1211,  1194,  1192,  1191,
    1195,  1196,  1193,  1210,  1197,  1198,  1182,   988,  1217,   985,
       0,     0,  1235,     0,  1180,  1179,  1174,  1172,  1171,  1175,
    1173,  1177,  1178,  1170,  1223,     0,  1459,  1465,  1635,  1628,
    1470,  1332,  1575,  1587,     0,  1589,  1591,     0,  1593,     0,
       0,     0,  1599,  1578,  1603,     0,  1460,  1462,     0,  1484,
    1485,  1626,  1618,  1288,     0,     0,  1280,  1275,  1276,  1293,
       0,  1271,  1272,     0,     0,  1285,  1265,  1266,     0,    24,
    1260,     0,     0,  1018,     0,    50,   998,     0,    24,   163,
     153,     0,   652,   654,   165,   155,   766,     0,  2229,  1027,
       0,   356,  1380,     0,  1069,    24,     0,     0,    66,     0,
      79,    88,     0,    72,   889,   886,   563,  2267,   957,     0,
    2267,   695,   674,   680,   642,  1777,     0,  1775,     0,     0,
    1689,  1685,  1455,     0,  1457,  1451,     0,  1363,     0,  1787,
    1446,  1448,  1423,     0,  2174,  2173,     0,     0,  1567,     0,
    1567,  1567,  1567,  1567,  2177,     0,     0,  2157,     0,     0,
       0,     0,  2190,  2158,     0,     0,     0,     0,     0,     0,
    2152,  1377,  1429,   858,   857,   340,     0,     0,     0,     0,
    1677,  1800,  1803,  1801,  1514,     0,  1551,  1553,     0,  1540,
    1543,  1542,  1550,     0,  1552,  1532,     0,  1503,  1393,  1815,
     214,   990,   989,   987,     0,  1216,  1101,  1105,  1107,     0,
    1111,     0,  1109,  1113,  1102,  1103,     0,   880,     0,     0,
    1629,  1634,     0,     0,  1610,  1602,  1580,     0,  1581,     0,
       0,  1278,  1273,  1279,  1277,  1270,  1269,  1268,  1263,  1267,
     366,   363,     0,  1016,     0,     0,     0,   997,   767,   141,
     651,    24,  1007,  1026,   567,  1066,    67,  1240,    84,     0,
       0,    77,    88,    88,  2267,   560,     0,     0,   698,   759,
       0,  1774,  1717,  1710,     0,  1365,     0,  1710,  2201,     0,
       0,  2206,     0,     0,     0,     0,     0,     0,     0,     0,
    2169,  2192,  2193,  2191,  2189,  2167,     0,  2163,  2165,  2154,
    2155,  1430,     0,  1422,     0,  1810,  1811,  1821,  1822,  1533,
    1765,  1535,     0,  1538,  1536,  1554,     0,   986,  2267,  2267,
    1115,  2267,  1117,  2267,  2267,  1104,  1236,  1224,     0,  1590,
       0,  1600,     0,  1491,   368,  1017,  2250,     0,     0,     0,
       0,     0,     0,    55,     0,    54,     0,    52,     0,     0,
     142,  1073,    88,    93,    88,    89,    83,    73,   887,     0,
       0,   700,    24,  1776,  1709,  1718,  1369,     0,  1366,  1368,
    1690,  2202,     0,     0,  2200,     0,     0,     0,     0,     0,
    2178,  2199,     0,  1431,     0,  1541,  1549,  1106,  1108,  2267,
    1112,  2267,  1110,  1114,  1630,  1595,  1463,   370,   375,   373,
     364,     0,   371,   377,    57,    62,    59,    61,    58,    60,
      56,     0,    51,     0,   653,   655,  1077,  1067,     0,  1075,
    1241,    85,    80,   561,   958,  2267,   760,     0,  1360,     0,
    1691,  1705,  2198,  2207,  2194,  2195,  2196,  2197,     0,  2179,
       0,     0,     0,  1116,  1118,  2267,  2267,   369,   372,  2267,
      53,     0,  2267,  1074,  1076,     0,   696,  1367,     0,  1695,
    1692,  1693,     0,     0,  2156,  1813,     0,   376,   374,   378,
       0,  1078,    86,   701,     0,     0,     0,  2181,     0,  2180,
       0,   999,    90,     0,  1696,  1694,     0,  1812,    92,     0,
      87,     0,  2182,    91,  1697
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   825,   826,   827,   828,  1046,  2404,  2405,   180,   322,
     181,  1406,  1407,  2231,  2563,  3615,  3086,  3087,  3515,  3616,
    3617,   829,  1187,  3124,  2820,  3533,  2170,  2818,  3381,  3128,
    3529,  2819,  3382,  3623,  3725,  3752,  3531,  3760,   647,   648,
     649,  1528,  2479,   830,  1539,  1192,  1537,  2178,  2489,  2175,
    2487,  2492,  2824,  1538,  2486,  2179,  2823,   831,     9,    28,
      29,    30,    31,    32,    88,   834,  1109,  2110,  1430,  2429,
    2433,  2434,  2430,  2431,  3093,  3097,  2786,  2778,  2777,  2779,
    2782,   494,   270,   600,   835,    55,    56,    11,    41,   115,
      70,    71,    72,    73,   196,   336,    74,    75,   242,   341,
     228,  1009,   520,  2981,   372,   936,  2294,   400,   401,   229,
     354,   343,   349,  1351,  1352,   119,   538,   120,   121,   360,
     230,   356,   342,   344,   522,   231,   256,   576,   244,   247,
     245,   246,   382,   554,   555,   557,   562,   939,   248,   249,
     391,   559,   192,    12,    51,   151,   152,   153,   945,  2919,
     154,   252,   240,   394,   395,   396,   397,  2133,   836,   837,
     838,   839,  1067,  3604,  3349,  1408,  3670,  3671,  3672,  3716,
    3715,  3719,   840,   841,   842,   843,   844,   845,   846,  1057,
     495,  1062,  1400,  1401,  1446,  1162,  1447,   297,   298,   299,
     300,   301,   302,   303,   452,   496,  1334,   497,   498,   499,
     500,   501,   502,   503,   986,   182,   514,   996,   998,  2027,
     183,   508,   992,   507,   991,   510,   994,   509,   993,   954,
     964,   304,   305,   185,   306,   419,   420,   421,   422,   405,
     424,   847,  3387,  3629,  3140,   848,  1129,  2136,  3116,  2460,
      89,   237,   548,  1949,  1255,  1256,  1257,  1946,  1947,  2281,
    2282,  2283,  2620,  2621,  1950,  1951,  2277,  2624,  2616,  2289,
    2290,  2627,  2628,  2917,  2913,  2914,   849,  1458,    57,  2095,
    2096,  2454,   406,   426,  1101,  1167,  1038,  1089,  1072,  1111,
    2519,   186,  1039,  1029,  2068,  2781,    59,   307,   850,  1197,
     851,  1210,  1211,   852,   853,   854,   855,  1218,  3149,  1239,
    3392,  1240,  2205,  1241,  2516,  1242,  2838,  1243,  2234,   856,
    2201,  2837,  3148,  3390,  3389,  3695,    90,    13,   857,  1424,
    2100,  2101,  2102,  2224,  1894,  2225,  2226,  2850,  2852,  2534,
    2533,  2538,  2532,  2531,  2524,  2523,  2522,  2521,  2526,  2525,
    2528,  2530,   858,   859,  1107,   860,  1890,  1225,  3632,   861,
    1506,  3358,  2565,  2566,  2227,  2535,  2495,  2826,  1156,  1486,
    2140,  2463,  2141,  1482,   862,   863,  1203,  2193,  3144,   864,
     865,   866,   867,    14,    45,    15,    16,    17,    91,    92,
     868,    93,    18,   927,    19,    94,    95,   131,   550,  1955,
    2632,  3444,    96,   127,   365,   869,  2759,    20,    21,    22,
      23,    24,    40,    62,    97,   676,  2033,  2700,   870,  1198,
    2499,  2182,  2497,  3534,  3135,  2183,  2496,  2829,  3137,   871,
     872,   873,  1083,  1084,  1542,    98,   238,   549,   930,   931,
    1259,  1953,   874,  1244,  1245,   875,  1902,  1246,   308,    64,
      65,    66,    67,  1549,   157,   111,    68,   108,   188,   189,
    1550,  1551,  2506,  1552,   673,   674,  1227,   675,  1228,  1160,
    1161,  1553,  1554,  1404,  3288,  3289,  3473,  1099,  1100,   876,
    1419,  3517,   877,  3105,   878,  1434,  1435,  1436,  2116,  2114,
     879,   880,  2413,  2440,   881,  2127,  2450,   882,  1157,  1158,
     883,  1022,   884,  2576,   885,  3621,  3119,   886,  2467,  3687,
    3688,  3689,  3722,  1164,   887,  1555,  2195,  2510,  2511,   888,
    2088,  1037,  1393,   889,   890,   891,  2702,  3292,  3484,  3485,
    3588,  3589,  3593,  3591,  3594,  3659,  3661,   892,   893,  1544,
    2187,   894,  1546,  1517,  1518,  1519,  2160,   895,  1177,   896,
     897,  2153,  1514,  1173,   195,  1520,  1521,   309,  2703,  3022,
    3023,  3006,  1054,  1055,  2698,  3007,  3010,    99,   126,   542,
    1361,  2354,  3024,  3488,   434,   898,  1171,   100,   123,   539,
    1358,  2352,  3011,  3486,  2699,  1191,  2811,  3377,  3622,  2155,
     899,   900,   901,   902,   903,  1070,  2411,  1048,  2407,  3345,
    3346,  3347,  3501,  3336,  3337,  3338,   904,  2972,  2753,  2754,
    2756,  2052,   905,   906,  1370,  1371,  1372,  2061,  2393,  1373,
    2390,  2058,  1374,  2366,  2053,  1375,  1376,  1377,  2358,  2363,
    1378,  2047,  2048,   907,  1079,  1059,   908,  1927,  1928,  2249,
    3176,  3408,  2880,  3173,  3637,  3638,  1929,  2271,  1908,  2612,
    2903,  3222,  2802,  3115,  2613,  1930,  1931,  2337,  2974,  2975,
    2976,  3269,  1932,  1933,  1443,   909,  1116,   910,  1252,  1934,
    1935,  2265,  3573,  2266,  2267,  2268,  2596,  2884,  2887,  2888,
    1936,  2586,  2875,  3405,  2041,  2042,  3061,  2706,  3326,  2707,
    2043,  2711,  2054,  2738,  2055,  2739,  3062,  3063,  3064,  3065,
    1937,  2243,  2244,  2583,  1938,  2969,  2686,  2965,  2332,  2006,
    2327,  2328,  2329,  2938,  2007,  2333,  2687,  2970,  2676,  2677,
    2678,  2679,  2680,  3456,  3250,  3579,  2681,  3458,  3459,  2963,
    2682,  2964,  2683,  2316,  2386,  2387,  2388,  3320,  2389,  3040,
    3047,  3495,  2708,  1026,  2889,  3028,  3215,  2710,  2671,  1307,
     310,  1308,  1987,   445,   955,  1968,  1988,  2651,    39,   911,
     912,  3168,  3401,  2868,  3400,  3701,  3730,  3731,  2872,  2577,
    1939,  2578,  2601,  3183,   603,  2573,  2574,  2338,  2689,  3399,
    3172,  1309,   971,  1310,  1311,  2966,  2684,  1313,  1314,  2318,
    3581,   913,   914,  2236,  2575,  3164,  3396,  3397,  1905,   915,
    1065,  1941,  1942,  2253,  2882,  1943,  1944,  2592,  2020,  2311,
    1315,  1316,  1317,  1318,   916,  1206,  1879,  1880,  1881,  2197,
    1882,  2198,  1945,  2602,  3221,  3440,  2899,  3218,  3219,  3220,
    3217,  3205,  3206,  3207,  3208,  3209,  3210,  3552,   917,  2125,
    2445,  2446,  1117,  1319,  1320,  1119,  1120,  1121,  1321,  1122,
    1441,  2119,  2120,    25,   919,  1179,  2161,  1427,  1508,   920,
     921,  2770,   922,  2402,  1042,  2075,   923,   924,    35,   543,
     544,   545,   546,   547,   925
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2906
static const short yypact[] =
{
     907,  1488, -2906,   363,   363,  1120, -2906, -2906,  1120, -2906,
      15, -2906, -2906, -2906,   377, -2906,   907, -2906, -2906, -2906,
   -2906, -2906,   -43, -2906, -2906, -2906, -2906, -2906,   419,   553,
   -2906,   489, -2906, -2906, -2906, -2906, -2906, -2906,  -146, -2906,
     951,   139, -2906, -2906, -2906,   442, -2906, -2906, -2906, -2906,
   -2906,  -105,   363, -2906,   363,   337,    15, -2906,  1037, -2906,
   -2906, -2906, -2906, -2906, -2906,   410,    -7, -2906, -2906, -2906,
     939,   568,   363, -2906, -2906,   996,   363, -2906, -2906,   363,
     363, -2906, -2906, -2906, -2906,   363,   363, -2906, -2906, -2906,
   -2906, -2906,   442, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,  6156, -2906,    -7, -2906,   959,  3247, -2906, -2906,
     500, -2906, -2906,  1043,   139,   493, -2906, -2906, -2906, -2906,
   -2906,  9941, -2906,   363,   595,   933,   363,    15, -2906, -2906,
   -2906,   363, -2906, -2906,   751,   651,  1036, -2906, -2906,   661,
   -2906,   666, -2906,   647, -2906, -2906,   685, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,   706, -2906, -2906,
   -2906,   721,   755,   776,   782,   799,   819,   836,   853,   862,
     881,  3247,   885,  5271,   897,   923,   957,   965,   983,   988,
    1717,  1158, -2906, -2906, -2906, -2906,   712, -2906,   170, -2906,
    3247, -2906,   241, -2906, -2906, -2906,   198, -2906, -2906, -2906,
     889, -2906, -2906, -2906, -2906, -2906, -2906,   751,   993,   997,
    1002, -2906,  1036, -2906, -2906,  1008, -2906,  1017, -2906,   732,
   -2906, -2906,  1027, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,  1055,  1240,   363,  1071, -2906,    15,    15,  1074,
     363, -2906,  -111,  1318, -2906,   839,  1068, -2906,   891,  1160,
    1545,  1550,   363,  1558,  1566, -2906,   952, -2906,    57,    57,
      57,    57,    57,  5271,  1572,  1532,    23,  5271,  1050,  5271,
   -2906,  5271,  5271,  5271, -2906, -2906, -2906,  1065,  1169,  1177,
    5271,  1229,  1181, -2906,  5271,  5271,  1190, -2906,  1194, -2906,
     923,  1201,  1213,  1221,  1231,  1640,  8877,   108, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1219, -2906,
   -2906, -2906, -2906, -2906, -2906,   334,   334, -2906, -2906, -2906,
   -2906, -2906,  3247, -2906, -2906,   363,  3247,  1205,   309, -2906,
   -2906, -2906, -2906,  1668, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,  1235, -2906,  1235,  -111,  1681,  1703,  1707, -2906,
   -2906, -2906,  1719,  1724,   139,  1558,  1235,  1727,  1095, -2906,
    1659, -2906,  1329,  1301, -2906,  1380, -2906, -2906, -2906,  1129,
   -2906, -2906,  1772,  1360, -2906,  1326, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906,  1160,  1326, -2906, -2906, -2906, -2906, -2906,
   -2906,  1334,   256,   269,   293, -2906,  5469, -2906, -2906, -2906,
    1339,  1809,   272, -2906,  1337,   358, -2906,  -191,  1379,  1381,
     413,   415,  4691,  1382,   158,  1279, -2906, -2906,   177,  1387,
   -2906, -2906, -2906, -2906,   422, -2906, -2906,  7886, -2906,  3831,
    9150,  3898,  3898,  5271, -2906,  1312,  5271,  8877,  1353, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,  1164,  1812,  8092,  8877,
    1312,  1813,   386,  5271,  5271,  5271,  5271, -2906,  5271,  5271,
    5271,  5271,  5271,  5271,  5271,  5271,  5271,  5271,  5271,  5271,
    5271,  5271,  5271,  5271,  5271, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  5271,  5271, -2906, -2906,  1363,
    5271, -2906,  5271,  1366, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,   334,  5271,  5271,  5271,
    5271,  1398,  1844,  1717,  3674,  1372, -2906,  3247,  1345, -2906,
    1185,  1830, -2906,  1192, -2906,  1833,  1414,  1420,   433,  1555,
     438,   446,   304,  1388, -2906,   455, -2906, -2906, -2906,   363,
   -2906, -2906,   363,  1454, -2906,  7122,   493,  7426,  1838,   390,
     363,  1850,     1, -2906, -2906,  1068,  1847, -2906, -2906, -2906,
   -2906,  1848, -2906,  1851, -2906,  1853, -2906,   363, -2906,   363,
   -2906, -2906,  1558,  1859, -2906, -2906, -2906,   363,    57, -2906,
    3247,    48, -2906, -2906, -2906, -2906, -2906,  1229,  1860,  1229,
    1861, -2906,  1864,  1255,  1150, -2906,    23, -2906, -2906, -2906,
    1452,  8877,   -29,  1457,  8132,  1874,  1229,  1462, -2906,  1465,
    1466, -2906,  8195,  8364,  8403,  8436,  8935,  8973,  9150,  9189,
    4800,  9244,  9416,  9302,  4456,  1184,  4697,  3898,  3898,  4389,
    4389,  5398,  8877,  8631,  8669,  1312,  8877,  8708,  1312, -2906,
    8877,  8877,  8877,  8877, -2906,  1881, -2906, -2906,  1871, -2906,
    8877, -2906,   352,  3247, -2906,  1470,  1893,     1, -2906, -2906,
    1888, -2906,  1439,  1896, -2906,  1898, -2906, -2906, -2906,  1900,
   -2906, -2906,  1253,  1487,  1923, -2906,   363,  1489, -2906, -2906,
   -2906,   334,   334,   334,   363,  1033,   363,  1188,   276,   276,
    1214,   363,   363,   276,   276,   363, -2906,  1188, -2906, -2906,
     363, -2906,   380, -2906, -2906, -2906,   276, -2906, -2906, -2906,
   -2906,   363, -2906, -2906, -2906, -2906,   157,   157,  5271, -2906,
   -2906, -2906,  1214,  1214, -2906, -2906,   276, -2906, -2906,   276,
   -2906, -2906,   363, -2906, -2906,   276, -2906, -2906,   334,   276,
   -2906, -2906,  5271,   276,   334,   363,   334,   276, -2906, -2906,
      85,   276,   276,    85,   276,   363,    85,   276, -2906,   276,
     276,   276, -2906,  1188, -2906, -2906,   334,   276, -2906, -2906,
     276,    54,   363, -2906,  1214, -2906, -2906,   276,  1066, -2906,
   -2906,   334,  1259, -2906,   276, -2906,  5251,   334,  5271,    57,
      57,   276, -2906, -2906,  1033,   334,  1083, -2906,  5271, -2906,
     153,  5271,   276,    82, -2906,  5271,   276,  1906,   334, -2906,
     276,  5271, -2906,  5271,   157,   363,   276,   363,    57,   276,
     363,    57, -2906,   363,   214, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,   213, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  1319, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,   928,   363, -2906,
     601, -2906,  1497, -2906, -2906, -2906,  1588, -2906, -2906,  1499,
    1500,  1501,  1503, -2906, -2906,  1274,  1945,  1511,  1512, -2906,
     414, -2906,  1476, -2906, -2906,  1283,   229, -2906,  1518, -2906,
    1935, -2906,  1327, -2906, -2906, -2906,  1292, -2906, -2906, -2906,
   -2906,  9631, -2906,  1065,  1525, -2906,  1065, -2906,  1065,  1065,
    1065,  1065,  1065,  1946,  1947,  1950,  5271,  1530,  1951,  5271,
    1540,  1541,  1544,  1546,  1547,  1551,  1553,  3674,  3674, -2906,
     364, -2906, -2906, -2906,  1644,  1559, -2906,  1563,  1571,  1328,
    1573,   363, -2906,   363,  1577, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906,   497,  1346,   483,  1477,  1543, -2906, -2906,
   -2906, -2906,  1352,   591, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,  2011,  1354, -2906, -2906,  1554, -2906,  1214, -2906,
    1498,   226, -2906, -2906, -2906,  1483, -2906,  8877, -2906, -2906,
    1385, -2906, -2906,  3908, -2906, -2906, -2906,   334, -2906, -2906,
    1214, -2906,   191, -2906, -2906,  1715, -2906,   159, -2906,  1524,
   -2906, -2906, -2906, -2906,  2030, -2906, -2906,   350, -2906,  1374,
   -2906,  1377,  2030, -2906,  1395, -2906, -2906, -2906,  1575,   112,
   -2906,  1538, -2906,  1341, -2906, -2906, -2906, -2906,  1343,   281,
   -2906,  -208, -2906,  1383,  1275,  1548,  1674,  1399, -2906, -2906,
    1392, -2906, -2906,  5271,   122,  1132,  5271, -2906,   116,   276,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,    64,
      64,    64, -2906,    64,  2952,    64,    64,  1419,   191,  1419,
    1419,  1142,  1142,  1419,  1419,   191, -2906,  2058, -2906,  1596,
     399, -2906,  2060, -2906,   191,   100,    58, -2906, -2906,  5271,
   -2906, -2906, -2906,   771, -2906, -2906,   493,  5271, -2906,  5271,
    1595,  1606,  1620,  1622,  1322,  1624,  1083, -2906,  1712,  1019,
    1471, -2906,  1484, -2906, -2906,   363, -2906, -2906,  1155, -2906,
    2102, -2906,  2100,   363, -2906,   456,  6486,  1496, -2906, -2906,
    2111, -2906,  1415,  2111,  2114,  1423,  2111,  2114,  5271,  2111,
   -2906, -2906,   226,   334, -2906, -2906,  1656,   347, -2906, -2906,
    1652,   334,  5271,  1653, -2906, -2906,  2116,  2119,  2034, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1161,  1161,   276,
     276,   276,  1816, -2906, -2906,  2010,   928, -2906, -2906,   775,
   -2906, -2906, -2906,  1651, -2906, -2906, -2906, -2906,  6156,  1558,
   -2906, -2906,  1492,   363,  1243,  2134,  1229,  1229,  1533,  1365,
   -2906,  9942,  9942, -2906,  1383, -2906, -2906,  1688,  1690,  1247,
   -2906,  9256,  1692, -2906,  1694,  1696,  1697, -2906,  1697,  1697,
    1698,  1700,  1701,  1706,   363,    -9, -2906, -2906, -2906, -2906,
     179, -2906,    65,  1928, -2906, -2906,  1247, -2906,  1247,  1713,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906,  8877,   461, -2906, -2906,   463, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1679, -2906,
   -2906,   472, -2906, -2906, -2906, -2906, -2906, -2906,    15, -2906,
   -2906,    15,   746,   160,  2161, -2906, -2906,   542,   220,   559,
    2185, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,   363,
    1389,   363, -2906, -2906,  1431,   363,  1464,   363,   363,  1214,
    1556,  1714, -2906,  1721,   109, -2906, -2906, -2906,  1214, -2906,
   -2906,  2192, -2906, -2906,  1528,  1723, -2906, -2906, -2906,  1132,
    1189, -2906,  1189,  1083,    85,  5271,  5271,  5271,  1725, -2906,
   -2906,   334,   334,  1214,  1534,  1083,    57,  1502,    54,   334,
   -2906,  1536,  5271,  1804, -2906, -2906,  1602,   363,  1383, -2906,
    3247, -2906, -2906, -2906,   363,  1029,  2211, -2906, -2906,  1560,
      90,   226,   334, -2906, -2906,  2204,  2205, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  2228, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  5251,   334,   334, -2906,  1142,
    5271,   -94,  2199,  2203, -2906, -2906, -2906, -2906, -2906,   204,
   -2906, -2906, -2906, -2906,  2029, -2906,  1799,   493,  5271, -2906,
      95, -2906, -2906,   363,  2210,    57,    57, -2906,  1600, -2906,
      23,  1568,   334, -2906,   363,   363,  5271,   -70, -2906,  1614,
   -2906, -2906,   288, -2906,  1711, -2906,  1716,  5271,  1165, -2906,
   -2906,  1578, -2906,  2238, -2906,  1654, -2906,   334, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  5775,
   -2906, -2906, -2906, -2906,   363,    57,    57,   369,   347,  2049,
    1357,   334,   226, -2906,  1657, -2906, -2906,  2211,  2223,  1803,
   -2906, -2906, -2906, -2906, -2906,  1883,  1883, -2906,   118,  1662,
   -2906,   363,  1214, -2906,  1214,  1214, -2906, -2906,  1214,  1214,
   -2906,   363,  1076,   -29,  1214, -2906,  1076, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,   211,   211,   469,  1009,
   -2906,   788, -2906,   775, -2906,    15,  2226, -2906, -2906,  1141,
    1817,  1778, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1818,
   -2906, -2906,  1510, -2906, -2906, -2906,  1582,  1582,  1677,  1691,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1587,   -29,
    1820,  9783,   632,  9631,  1744, -2906, -2906, -2906,   632,   632,
     632,   632,  1599,  9631,  9631,   254,  1695,   -28,   363, -2906,
    9631,  9631,  9631,  9631, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,  1598,    29,  1132,  5271, -2906, -2906,  1827,  2226, -2906,
   -2906, -2906, -2906,    15, -2906,  1791,  1793,  1794,   905,  1796,
    1797, -2906, -2906, -2906,  2171,   363, -2906,  2272, -2906, -2906,
     117,  5576, -2906, -2906, -2906, -2906,   363, -2906, -2906,   117,
    1569, -2906,   497, -2906,  1612, -2906,  1648, -2906,  1840,    -7,
   -2906,  1621, -2906,  1650, -2906,  1709,  1810,   363, -2906, -2906,
   -2906, -2906,  3908,   363, -2906,  1626, -2906, -2906, -2906, -2906,
    1618, -2906,  2286,  2302, -2906,  2303,  1683,  5271, -2906, -2906,
    2305, -2906,  1645, -2906,  1782,  1642,  2114, -2906, -2906,  1655,
    1139,   363, -2906, -2906,  1837,   276,  1067,  1392,  1717,   366,
   -2906, -2906, -2906, -2906,  5271,  1214,  1132,  -204, -2906,   363,
     363,  5271,    45,   191,  2316,  1094,  2314,  2298,  2304,  2952,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,   334,  1965, -2906,
   -2906,  2220,  5271,   493,  2069, -2906, -2906, -2906,  5271,   157,
   -2906,  1961,  2332,  2333,   482,   484,   363,  1907,  1083, -2906,
    3674,  1868,  1870, -2906, -2906,  1940, -2906,  5271,    12, -2906,
    1708, -2906, -2906,   255, -2906,  5271, -2906, -2906,  1678,   959,
   -2906,  1167,   363,  2341,  9472, -2906, -2906,  1132,   334, -2906,
   -2906,    30, -2906,  2114,  2114,  1658, -2906,  1759,  1767, -2906,
   -2906, -2906, -2906, -2906, -2906,    57,    57, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  3729, -2906, -2906, -2906, -2906,
      57,  8204,  2356,  2339, -2906,  1083,   866,   208,   121,  2219,
     -22,  1033, -2906,   633, -2906, -2906, -2906,  1889,    87,  1214,
     143,  1704, -2906,  1699, -2906, -2906, -2906, -2906, -2906,  1894,
    1894, -2906, -2906, -2906, -2906,  1780,  1705,  2370, -2906, -2906,
   -2906,   443,  1718,  1710, -2906, -2906,   334,   202, -2906, -2906,
   -2906,  1693,  1009, -2906,   363,   363, -2906, -2906,   363,   596,
   -2906, -2906, -2906, -2906,  1903, -2906, -2906, -2906,  2353,  1229,
   -2906, -2906,  1952,   173,  1955,   174,  1266,  9631, -2906,    94,
    2375,  1958,  2381, -2906, -2906, -2906,  9631, -2906,   486,  9631,
    9631,  9631,  9631,   363,   488, -2906,   371,  2382, -2906, -2906,
     363,  9227, -2906,  1971,   363,  1734,   632,  2020, -2906, -2906,
   -2906, -2906, -2906, -2906,  1266,  2377,  1266, -2906,  8877, -2906,
    1931, -2906,  1899, -2906,  1902,    69,    69,    69,   494,  2171,
      69,  9227,   363, -2906,   503,   363,   506, -2906, -2906, -2906,
    1934,  1941,  1944,  1247,  1247, -2906,  1949, -2906,  1956,  1957,
    1959,  1960, -2906, -2906, -2906, -2906,   992, -2906, -2906, -2906,
     511, -2906, -2906,   517,   363, -2906,   363,  1597, -2906,   363,
    1607,  5271, -2906,   363,  2401, -2906, -2906,   117, -2906, -2906,
    1757,   117,   207, -2906,  1083,  5271,  5271,  5271,  5037,  2424,
    1214,   145, -2906,  1083,   363, -2906, -2906,   363,   363, -2906,
    1069, -2906, -2906,   906, -2906,  1770,  5271, -2906, -2906, -2906,
    2425,  3247,  1933, -2906,  1774,  2438, -2906, -2906,  1083,  1821,
   -2906, -2906, -2906, -2906, -2906,   363,  2114, -2906,   226, -2906,
    1846, -2906, -2906,   522, -2906, -2906, -2906,   334, -2906,  4499,
   -2906,  1005, -2906, -2906,  2072,  2423, -2906,  2055,  2056,  1954,
    1785,  2062,  1976, -2906, -2906, -2906,    16,  2048, -2906, -2906,
   -2906, -2906,  1940, -2906, -2906, -2906,   248,   679, -2906, -2906,
   -2906,  2211,  5271,  1985, -2906,  1963, -2906, -2906, -2906, -2906,
    2456, -2906, -2906, -2906,  2457, -2906,  1766, -2906,  2439,   191,
     363,  4630,  4630,  4630,  4630,  4630,  4630, -2906,  2461, -2906,
    2462,  4630,  4630,  4630,  4630,  2228, -2906, -2906,  4630,   152,
   -2906, -2906, -2906, -2906,  2448,  2463, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  2464, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906,   523, -2906, -2906, -2906,  2449, -2906, -2906,
    1214, -2906,   -29, -2906, -2906, -2906, -2906, -2906, -2906,  1834,
    1842,   125, -2906,   633, -2906,    69,  1819,   276, -2906,  2001,
   -2906, -2906, -2906,   363,   363,    69, -2906, -2906,   124,  1214,
    1075,  9631,   194, -2906,  5271, -2906,  5271, -2906, -2906, -2906,
   -2906, -2906,  1880,   276,   124,  1214,  2481, -2906,   334,   363,
     893,   893, -2906, -2906,  2483, -2906,  2483,   628,   628,  2483,
   -2906, -2906,  1838, -2906,  2050, -2906, -2906,  2466, -2906,  2468,
   -2906,  2470, -2906,  2471,  2021, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,   179,  1247,  1826,  1247, -2906,  1247,  2061,  9631,
   -2906,  2064,  2065,  2066,  2067, -2906, -2906,   254, -2906,   254,
   -2906, -2906,  7327,  1697,  2825,  1697,  2494,  2482, -2906, -2906,
   -2906, -2906, -2906, -2906,  1320,  9631, -2906,  2013, -2906,  2193,
     201,   208,   363, -2906,  2070, -2906, -2906,  2992,    75, -2906,
    1838,  1828, -2906,    75,  1214,   849,  2071,  2507,  1852, -2906,
   -2906,   526, -2906,   529,   905, -2906, -2906,   533,   206, -2906,
   -2906, -2906,   117, -2906,  2487,  2487,  2488,  1843,   440,  2490,
    2499,  2500,  2490,  2490, -2906, -2906, -2906,   136, -2906,   829,
     363, -2906,   117, -2906, -2906, -2906,  1862, -2906, -2906,  1863,
   -2906, -2906,  -185,   535, -2906,   363,   540, -2906,  5271,  2090,
    2511,   548,  1083,  2527, -2906, -2906, -2906, -2906,  5271,  1921,
    2214,  5271, -2906, -2906, -2906, -2906,   906,  1134,  1134,  2532,
    -136, -2906,  2533, -2906, -2906, -2906,  1134,   363,  1953,  1295,
    2535,   363, -2906,  3247,   193,  1214,  2536,  1083,  -142,  2316,
    5271, -2906, -2906,  2952, -2906,  1829,  5271, -2906, -2906, -2906,
    2542,  3674,   334, -2906,   380,   363,   334, -2906,  2101,  3674,
    3674, -2906, -2906,    16,  2048, -2906,  2228, -2906, -2906,  1209,
   -2906, -2906,  1930, -2906,  3247,  4989,  9472,    43,  1082, -2906,
   -2906, -2906,  1884, -2906, -2906, -2906, -2906, -2906, -2906,    57,
    4630,    57,  4630, -2906, -2906, -2906, -2906, -2906, -2906,   191,
   -2906,  1052,  1124,  8204, -2906,  2109,  2073,  9631, -2906,   121,
     121, -2906, -2906, -2906, -2906,   549, -2906,  2035, -2906,    69,
     -71, -2906,  1882, -2906,   555, -2906, -2906,  2547, -2906, -2906,
    1964, -2906,  2551,  2717,  2717,  2717,  2717,    69,    69, -2906,
   -2906, -2906, -2906, -2906, -2906,  2547,  1886,   334, -2906,  2483,
   -2906, -2906,   363,   628,   628, -2906, -2906,   628,  2300,  1890,
   -2906,   251,   473,   264,   534,  2537,  2121,  1892,  1266,  1897,
    1901, -2906, -2906, -2906, -2906, -2906, -2906, -2906,   556, -2906,
   -2906, -2906,   230,   185, -2906,  9227,  9227, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,  9942,  9942,  2084,  9942,
    2087, -2906,  9942,   618,  9631,  2561, -2906, -2906,  9227, -2906,
   -2906, -2906, -2906, -2906,  2563, -2906,  -132, -2906, -2906,  2193,
    1905,  1904, -2906, -2906,   157,   157,   157,  2546,   157,   157,
     157,   157,   157,   157,  2550, -2906,  2553,   157, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,  2992, -2906,   334,  1914,
   -2906,  2078,  2300,  2556, -2906,  2568,  2575,  2576,  2577,  2578,
    2579,  1215,  1828, -2906,  2078, -2906, -2906,  2580, -2906,  2250,
      69,  1330,    69, -2906, -2906,  2171, -2906, -2906, -2906, -2906,
    2167,  2169,   557,  1266,  2588,  1266, -2906,  2612,   560,  2178,
    2179,  2612, -2906, -2906, -2906, -2906,  1214, -2906, -2906, -2906,
    2142, -2906, -2906,   829, -2906,  2171, -2906, -2906,   363,   363,
   -2906, -2906,   363,  -260, -2906,   117,   295,  2211, -2906,  2106,
     295,   277,  1083, -2906,  2618,  2146, -2906, -2906,  2186,  2028,
   -2906, -2906,   363,  1134,  3247,  1397,   363,  1134, -2906, -2906,
      57, -2906, -2906,  5271, -2906, -2906,   367, -2906, -2906, -2906,
    1083,  2622, -2906,    57,  2211,   334,  2345, -2906,  2608,  1759,
    8877,  2613, -2906, -2906,   226,  2163, -2906, -2906,  3674, -2906,
   -2906,  2200, -2906, -2906, -2906,   679, -2906,  1759, -2906,  5271,
   -2906,   370, -2906,  2060, -2906, -2906, -2906, -2906,  2151,  2247,
   -2906,  2623, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906,   363, -2906,   130, -2906, -2906, -2906,    69,
   -2906,   -29,  2452,   563, -2906, -2906, -2906, -2906,   363,    69,
   -2906,   124,   124,  2044, 10033, 10033, -2906, -2906,  9905,  2168,
   -2906, -2906,  2173,  2174, -2906,  2175,  2176,  2177,  2180,   363,
     617, -2906, -2906, -2906, -2906,   571, -2906, -2906,  1948, -2906,
   -2906, -2906,   572,  2640,  2640, -2906, -2906,   574,  2642,  2635,
   -2906,    99,   334,   124, -2906, -2906, -2906, -2906, -2906,  2398,
    6156,  2633, -2906, -2906,  2634,  2636, -2906, -2906,  2637,  2221,
   -2906,  1266,  2225,  1266,  1266,   254, -2906, -2906,  2482, -2906,
    2181,  1928,  2181,   388, -2906,  2181,   388, -2906,  2181,  9942,
   -2906, -2906,  9631, -2906,  9631,  2494,   201, -2906, -2906, -2906,
   -2906,  1266, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,   402,  2663, -2906,
     334,  1758, -2906,  2398, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,   382, -2906, -2906, -2906,  2170,
   -2906, -2906, -2906, -2906,  2649, -2906, -2906,  2239, -2906,  2652,
    2241,  2657, -2906, -2906, -2906,  2244, -2906,  2208,  9227, -2906,
   -2906, -2906, -2906, -2906,   363,  2665, -2906,  -260, -2906, -2906,
    2669, -2906, -2906,  2670,   363,  2193,   295, -2906,    57,   191,
   -2906,  2274,  1083, -2906,  5271, -2906,  2083,  2673,   191, -2906,
   -2906,   462, -2906, -2906, -2906, -2906,   199,  2260, -2906, -2906,
    1083,  2114,  2457,  2414, -2906,   191,  2263,  2267,  2316,  2231,
   -2906,  2317,  2270, -2906, -2906, -2906, -2906,  2426,  2206,  5271,
    2230, -2906, -2906, -2906,  1759, -2906,   576, -2906,   334,  2120,
   -2906, -2906, -2906,  9631, -2906, -2906,    69, -2906,  2242, -2906,
   -2906, -2906,  2547,  2120,  1995,  1995,  2281,  9783,   632,  9933,
     632,   632,   632,   632,   -18,  9933,  2717, -2906,  9933,  9933,
    9933,  9933, -2906, -2906,    69,  2708,    69,  2717,   276,  9227,
   -2906,  2457,    81, -2906, -2906, -2906,   250,  2283,  2284,  2287,
   -2906, -2906, -2906, -2906, -2906,   136, -2906, -2906,   578, -2906,
   -2906, -2906, -2906,   579, -2906,  2181,  2719, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,   334,  2663, -2906, -2906, -2906,   334,
   -2906,   334, -2906, -2906,  1849, -2906,  2441, -2906,  2442,  2704,
   -2906, -2906,  2291,  2068, -2906, -2906, -2906,  2292, -2906,    69,
     236, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,  1083, -2906,  2293, 10155,  2268, -2906, -2906, -2906,
    2079,   191, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  2307,
     226, -2906,  2317,  2317,   679, -2906,  3247,  2126, -2906, -2906,
     363, -2906,  2457,   -28,   179, -2906,  9500,   -28, -2906,  2309,
    9933, -2906,   584,  9933,  9933,  9933,  9933,  2712,   363,   585,
   -2906, -2906, -2906, -2906, -2906, -2906,  2273, -2906, -2906, -2906,
    2494, -2906,   363, -2906,  2117, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,   219, -2906, -2906, -2906,  9631, -2906,  1895,  1895,
   -2906,  1895, -2906,  1895,  1895, -2906, -2906, -2906,  2276, -2906,
    1266, -2906,   586, -2906,  1102, -2906, -2906,    64,    64,    64,
      64,    64,    64, -2906,  2729, -2906,   587, -2906,  5271,  1494,
   -2906,    46,  2317,  3674,  2317,  2316, -2906, -2906, -2906,  2467,
     387, -2906,   191, -2906, -2906, -2906, -2906,   589, -2906, -2906,
    1436, -2906,  2315,  9933, -2906,  2318,  2321,  2322,  2324,   392,
    2261, -2906,  2717, -2906,  2740, -2906, -2906, -2906, -2906,  1895,
   -2906,  1895, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,  1216, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, 10155, -2906,  2763, -2906, -2906, -2906, -2906,   834, -2906,
   -2906, -2906, -2906, -2906, -2906,    30, -2906,  9500, -2906,  1629,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  2744, -2906,
    2745,   610,   573, -2906, -2906,  1224,  1224, -2906, -2906,  1224,
   -2906,  5271,   977, -2906, -2906,  2334,    43, -2906,  2107,  2110,
    2767, -2906,  2306,   394, -2906, -2906,  2751, -2906, -2906, -2906,
    2338, -2906, -2906, -2906,   363,   363,  1629, -2906,  2753, -2906,
    2342, -2906,   672,  2115, -2906, -2906,  2311, -2906, -2906,   226,
   -2906,   363, -2906,  2316, -2906
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2906, -2906, -2906, -2906, -2906,   -31, -2906,    32,  -158, -2906,
   -2906, -1147,   -48, -2906, -2906, -2123, -2906, -2906, -2906, -2906,
    -892, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2361, -2906,  -995, -2906,
    1800, -2906, -2906, -2906, -2906, -2906, -2906, -2906,   298, -2906,
   -2906, -2906, -2906,  1256, -2906,   620, -2906, -2906,   -33, -2906,
   -2906,  2771, -2906,  2765,  2255, -2906, -2906, -2906, -2906, -2906,
     379,    17, -2906,   376, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  -108,   426,   485, -2906, -2906,
    2453,    37, -2906,  2694, -2906, -2906,  2698, -2906,  2610, -2906,
   -2906, -2906, -2906, -2906,  2473,  2162,   792,  2469,  -505, -2906,
   -2906, -2906, -2906, -2906,   793,  -645, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,   513, -2906,  2596,  2295,  2611,    73,
    2229, -2906,  2280,  1562, -2906,  2443, -2906, -2906, -2906, -2906,
    2455, -2906, -2906, -2906, -2906,  -389, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,  2269, -2906,  2278, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -1356, -2906, -2906,  -818, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  -126,
   -2906, -2906,   772, -2906, -1082, -1149,  -340, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,  1866, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,  -607, -2906, -2906, -2906, -2906, -2906,
    2057, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  -571,
   -2906,  -101, -2906, -2906, -2906, -2906,  2445, -2906, -2906,  -233,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906,  1605, -2906, -2906, -2906,
   -2906,   580, -2906, -2906, -2906, -2906, -2906, -1964, -2906, -2906,
     577, -2906, -2906, -2906, -2906, -2906, -2906, -1088,  -231,   448,
     737, -2906,  -220,  -553,   764, -1113,  1088, -2906,   731, -2906,
   -2442,    -3,  -628, -2906, -2906, -2307,   253,  1786, -2906, -2906,
   -2906,   760,   979, -2906, -2906, -2906, -2906, -2906, -2906,    33,
   -2906,  -279, -2906,   985, -2906,   668, -2906,   359, -2906, -2906,
   -2906, -2906,  -852, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,   457, -2906, -2906, -1823, -2906,   653, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,  1451, -2906, -2906, -2906, -2906, -2906,
   -2906,  -485, -2906, -2906, -2076, -2906, -2906, -2906, -2906,   602,
   -2217, -2906, -1134, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,  2866, -2906, -2906,
   -2906,  2791,  2844, -2208, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,  -408, -2906, -2906, -2906, -2906, -2906,  2846, -2906, -2906,
    2865, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,   705, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906,  -649,  2133, -2906, -2906, -2906, -2906, -2906,  1966,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1789, -2906,
   -2906,   -30, -2906, -2906,   708, -2906, -2906,  1351,  -186,  2574,
   -2906, -2906, -2906, -2906,  -147, -2906, -1043,  1908,  1010, -1441,
    1406, -2906,   713,  1684,  -384,  -564, -2906,  2130,  1490, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  1418,
   -2906,  -771, -2906,  -579, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,  -766, -2906, -2906, -2906, -2906, -2906, -2906,    88, -2906,
    1513,   718, -2906, -2906, -2906, -2906, -2906,   -97, -2906,  -561,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906,  1413, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,  -524, -2906,   780,  2492, -2906, -2906,
     -89, -2906,  -692, -2906, -2906,   -59,   249, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906,  1173, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  -122,
   -2906,  -386,  -382, -2906, -2906,  -374, -2906, -2687, -2906,  -106,
     558, -1348, -2906, -2906, -2906,   902, -2906, -1966, -2906, -2906,
   -2906, -1985, -2906, -2906, -1976, -2906, -2906, -2906, -2906, -2314,
   -2906,   922,   603, -2906, -2906, -2906, -2906, -2906,   389, -2906,
   -2906, -2906, -2906, -2906, -2906,  -726, -2906, -2906, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,  -294,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,
   -2906,  1047, -2906,  1048, -2906,   378,   716, -2906, -2443,  -202,
   -2906, -2906, -2906, -2906, -2906, -2906,   -49, -2906, -2906,  -518,
   -2906, -1375, -1335, -2906, -2906, -2906, -2906, -2906,   -81, -2906,
   -2906, -2906, -2906, -2906, -1950, -2906, -2906, -2906, -2906, -2906,
   -2906, -2398,   657, -2906, -2588,   736, -2906, -2906, -2319,    40,
      42,   314, -2906, -2169, -2158, -2906, -2906,  -267,  -592, -2906,
   -2906, -2906, -2906, -1832, -2906, -2906, -2906,   -60, -2906,   267,
    -947, -2906,  -406,  -258,  1084,  -315, -2141,   292, -2906, -1620,
   -2906, -2906, -2906, -2906,    39, -2906, -1286, -2311,  2989, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906,  -748, -2906, -1773,
   -2906,  1747, -2906, -2906,   624,   310, -2906, -2322,   308,  -180,
     126, -1211, -1887, -2251,  1000,  -257,  -781, -1267, -2906,  1006,
   -2906, -2906, -2906,  1104,  -680, -2906, -2906,  -527,  1768, -2906,
     801, -2906, -2906,   421,  -161, -2906, -2906, -2906, -2249,  -398,
    -511, -2906,  -480, -2906, -2906, -2906, -2906,  1143, -2906, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2784,  -415,
   -2906, -2816, -2905, -2298, -1392, -2906, -2906,  -402, -2906, -2906,
   -2906,   231, -1084,  1001,  -752,  1911,  1593,  1586, -1780, -2906,
   -2906,   239,   592,   209, -2906, -2906, -2906, -2906,  1608, -2906,
   -2906, -2906, -2906, -2906, -2906, -2906, -2906, -2906,   188,  1373,
    2489, -2906, -2906, -2906, -2906
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2264
static const short yytable[] =
{
      34,    36,    38,  1346,   328,    38,   184,   570,  1394,  1001,
    1481,  2135,    87,   268,  1976,  1977,  1453,  1501,   957,   236,
    1509,  2060,   680,  1170,   104,  1056,  1118,  2044,   410,   411,
    2021,   989,  2022,  2693,  2432,  2695,  2269,    58,  2080,   408,
     409,  1449,  2718,   965,  1450,  2716,   425,   296,   423,   103,
      33,    58,  1460,  1461,  2828,  1462,  2652,  1483,  1484,    87,
    1028,  1031,   110,   578,  2926,  2207,  2208,   946,   951,   117,
     184,  2391,    33,   122,  2367,    33,   124,   125,  3212,  3213,
    3214,    33,   128,   129,    33,  1995,  3181,  1996,  1997,   184,
    1454,    33,    33,  2392,  1032,  2124,    33,  2859,  1064,  2653,
    2158,  1064,  2307,    58,  1088,   578,   113,  1051,  2564,    33,
    1081,  1073,    33,  3216,  1892,  1064,  1176,  1422,  1063,  1064,
     232,  2783,  1208,   235,  1451,  2580,  1090,  1422,   239,   366,
     367,  1064,   274,  1073,   504,  2004,  1887,   412,  1910,  1102,
   -2262,   427,  1073,   429,    33,   430,   431,   432,    33,  1112,
    1897,    33,    33,  3146,   437,   197,  1127,   578,   448,   449,
     274,  3052,  1285,  1168,   513,  2773,  2319,  2320,  2321,  2322,
    1032,  2905,    33,  1123,  1102,   326,  1126,   588,  1102,  1888,
      33,   274,  1102,  1052,  2004,  1169,   255,    33,  1073,   331,
    1312,  1073,  2637,  2641,  2947,  2948,   592,  2949,  2950,  2951,
    2952,  2953,  2954,   593,   578,  1128,  2128,  2618,  2129,  1500,
    2130,  2312,  2945,  3107,  2709,  2712,  2712,   333,  1032,  2712,
      33,   184,   274,   334,   335,   184,  1032,  2973,    33,  1502,
    1503,   363,  1174,  1174,    33,    33,  2945,   369,   274,  1220,
    1221,    33,  2945,   274,  1284,  1285,    33,    33,  1275,   398,
     274,  1220,  1221,    33,   101,   407,   407,   407,   407,   407,
    3008,   563,   255,   407,   359,   274,   329,   330,    33,  2937,
    3231,  2939,  3571,  2827,   565,    33,  3574,   573,  2180,  1032,
    2774,    33,  3351,  3235,  1034,  2587,   351,  2893,  2894,  2895,
    2896,  2897,  3270,  2584,  1410,  1411,  3112,  3438,   567,     4,
    2147,   101,    54,    33,  2238,  2239,  1180,   601,    33,   114,
     604,  2180,    58,    58,   326,   580,  1060,  1061,  2857,  2174,
     446,  2626,   515,    54,  2629,  2085,  1229,   612,   613,   614,
     615,   652,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632, -2262,
    2892,  3340,  1892,  2334,  2432,  2942,  1181,   326,   949,   633,
     634,    33,  2151,   578,   636,  2590,   637,   370,  1110,   326,
    3094,  2441,  2441,  1118,  2124,   326,   425,    44,  1058,   968,
     523,   640,   641,   642,   643,  1432,   529,  3489,   650,  2218,
      33,    54,   326,  1182,   371,   677,  1032,  3708,    33,  3748,
    3070,  2491,  1074,   932,  1497, -2262,  1045,    33,  2134,  3334,
    2035,     6,   274,  1284,  1285,    33,   184,  2513,   578,  2448,
     578,  1916,   950,  2036,  2918, -2262,    10,   596,  3341,  3342,
     109,  1230,   317,   318,   319,   320,   321,    33,   660,  1043,
     575,   934,    10,   663,  2876,    54,    54,  3171,  1163,  3071,
      48,   665,    54,  3267,  2885,  3175,  1433,  1114,  1178,  2449,
     669,  1193,  2591,  3335,    54,  1199,  2024,  1000,  2024,  2003,
      33,  1205,     1,  1207,   935,   581,     2,  2029,  1104,   184,
     317,   318,   319,   320,   321,  2955,    54,   578,  3557,   578,
    1183,  2659,  3012,  2659,   969,    43,    33,  1440,   277,  2714,
       7,  1168,  3268,    58,  2691,  1097,  1531,  2345,  2365,  1980,
    1990,  2722,    52,  1230,   832,   926,  2740,    26, -2262,    54,
    1027,  3560,  2742,  2223,  1027,  2037,  1230,  2803,  2863,  1014,
    3095,  3032,  3568,  2335,  3032,  1230,   672,  2181,  3032,   672,
    3072,    43,    69,    76,  2336,  3075,  1893,   672,  2148,  2977,
      77,  1106,   184,  3075,  3169,  1536,  1165,  1166,   102,   167,
    3179,  3245,  3314,  3113,   398,  3321,   398,  1184,  3406,    33,
    2181,   168,    54,   575,   948,   407,  3426,  3426,   953,  3434,
    1289,  3540,    27,  3582,  3582,  1214,    33,  3343,  1217,  3643,
    3643,  3030,  3681,   407,  3697,  1981,    78,    79,   589,  1362,
    1363,  2455,  2240,   970,    80,  2956,  2957,  1231,  1185,  3134,
    2788,  1982,  1455,  2638,  2642,  3426,  3165,  3242,    54, -2262,
    2581,  1907,  1127,  1168,   568,  2308,  1114,   105,  3259,  1364,
    1365,  1366,  3147,  2874,  2886,   667,  3009,  2177,  2045,  1923,
    2039, -2262,  1391,  1923,   327,   975,  3037,  1222,  3558,  3265,
    3565,  1232,  1515,  3108,  1983,  2909,  2040,  1118,  3508,   112,
    2331,  2958,  1105,  1289,  1405,  1456,  2498,  1556,   963,  1276,
    3247,  1909,  3439,   672,  1186,  1027,  3603,  3375,    58,    58,
      58,  1019,    58,  1023,  1025,  2867,  1504,  1033,  1035,  1036,
    3575,  3232,  1041,  1984,  1025,  3385,   564,  1044,  2056,    58,
    3352,  2346, -2262,  2359,  3236,  1970,  1971,    54,  1036,   566,
    2031,  2060,   574,   174,  1429,  1423,  1452,  1082,  1195,  1033,
    1033,  3311,  1985,  1402,  1233,  1448,  2572,  2704,  2008,  1036,
    3398,  1986,  3316,  2090,  3318,    58,   404,   175,  3174,  3412,
    3161,    58,  1036,    58,  3572,  2105,  3038,    58,  1223,  2518,
      58,  3330,  1091,    58,  2131,  3066,   918,  2514,   404,  2159,
    1025,   952,  2132,    58,  1958,  2091,  1507,   404,   407,  1108,
     404,  1033,  2005,  1505,   295,  1115,  3067,  2457,    58,  1457,
    3442,   176,  1498,   518,    58,  3359,   407,   407,  2959,  3364,
     177,    58,    58,    58,   590,  2619,  3357,  1189,   579,  3252,
    1196,  3255,   295,  2704,  3258,    58,  1233,  1232,  2873,  2639,
    2643,  3543,  1209,   594,  1209,   407,  2326,  1209,   407,  1233,
    1209,    58,   279,   295,  2898,  3547,   999,  1238,  1233,  1163,
    2762,  1412,  1289,  1499,  2603,  2035,  3711,  1516,  1347,  1522,
    2442,  3368,  1027,  2604,  3388,  2518,   282,  3454,  2036,  2667,
    1557,  2704,  2035,   584,  2960,   585,  3490,   524,    81,  2704,
    1333,  3694,   597,  1333,   295,  2036,  3709,  2605,  3749,   534,
    2606,   650,   650,   661,   178,   179,  1030,  1030,   664,  1957,
     295,  1030,  1030,  3758,    82,   295,   666,  2607,  1272,  3307,
    3416,  3310,   295,    33,  1030,   670, -2262, -2262, -2262, -2262,
   -2262,  2025,  2276,  2026,  2961,  2962,  1989,   295,  1234,  1235,
    1236,  2787,  2030,  3233,  1030,  3260,  1914,  1030,  3044,  1237,
    1490,  1491,  2477,  1030,  2478,  1258,  2660,  1030,  2666,   288,
    3451,  1030,  3452,  3453,  2715,  1030,  3520,     1,  2185,  1030,
    1030,     2,  1030,  2720,   114,  1030,  2723,  1030,  1030,  1030,
    2037,  2741,  3539,  3089,    83,  1030,  3635,  2743,  1030,  3432,
    3469, -2262,  2804,  2864,  3344,  1030,  3033,  2037,  1305,  3034,
    2630,   116,  1030,  3036,  3237,  3073,    53,  2167,    33,  1030,
    3076,     1,  2713,  2076,   155,  2717,    33,  3471,  3080,  3170,
    1030,  2608,  2081,  2156,  1030,  3180,  3246,  3315,  1030,  1367,
    3322,   118, -2262,  3407,  1030,  2464,   190,  1030,  1357,  3500,
     672,  3427,  3433,  3735,  3435,  1415,  3541,  2103,  3583,  3584,
    2050,   291,  1416,  2654,  3644,  3651,  3666,  3682,  3402,  3698,
       3,  2807,    33,   292,   293,  3054,  3472,  2059,  3410,  2035,
    2313,   294,  2447,  1350,  2609,  1033,    84,  1558,    58,  2122,
    3734,  2610,  2036,  3261,   295,  3262,    33,   191,  1020,  2757,
      33,   928,   194,  2757,    58,  2039,  3759,  1033,   317,   318,
     319,   320,   321,   233,   609,  2092,  2093,  2094,  3157,    33,
    1559,  2040,  2039,  3457,   929,  1368,  3462,  2727,  2728,  3464,
   -2262,  1113,  2112,    33,   234,  3425,  3166,  3167,  2040,  1497,
    1487,  3465,  2458,  2501,    54,  1893,    58,  1494,  1174,  3234,
      33,  1115,  3045,  3211,  3211,  3211,  3211,  3053,   241,  1380,
    3570,  3551,  1115,  1440,  2284,  2977,    85,  3551,  1369,   243,
    3561,  3562,  3563,  3564,    86,  3055,    58,    58,    58,   250,
      58,  1381,    58,    58,   251,    37,  1922,    33,    58,    58,
    3159,    33,  3544,   253,  2037,  2314, -2262,  1438,  2611,    33,
    2146,  2295,  2570,   254,  3723,  3432,  3432,    53,    33,    33,
    3238,  3626,  3627,  3056,   961,  2483,   962,  2218,  1516,   257,
    1541,  1529,    33,    58,   323,  1926,  1903,  2504,    33,    54,
     324,     4,  1540,  2106,    33,    58,  2173,    54,  2035,   258,
    1548,   468,   469,   470,   471,   472,   473,  2188,  1106,  3736,
    2310,  2036,  2317,  1024,  2086,    33,    33,   106,   107,    58,
      58,  3634,  2317,  1312,  2038,  3640,   474,  1386,    58,  2340,
    2341,  2342,  2343,   259,  3136,     4,    33,  3057,   355,  1032,
    3301,    33,    33,    54,    58,    58,  2734,  2735,  2736,  1387,
    2032,  3058,  3642,  2034,   260,  3645,  3646,  3647,  3648,   987,
     261,  3690,   990,  3692,  2315,  3545,   362,  2285,  2145,  2039,
    1960,    54,   928,  3201,  3201,  3201,  3201,   262,  1305,  1305,
     325,  2425,  2118,  2426,  3403,  2040,  2286,  2287,  1305,  3665,
      54,  2254,  2164,  2165,  1260,   929,  3585,   263,   415, -2262,
    1438,  2002,    33,   416,  1114,   418,  2288, -2262,  2784,  2009,
     425,  2223,     5,  2037,   264,  3101,  2284,  1030, -2262, -2262,
   -2262,    54,    33,   475,   476,   477,   478,   479,   480,  2947,
    2948,   265,  2949,  2950,  2951,  2952,  2953,  2954, -2262,   184,
     266,   481,   482,   483,   373,  3703, -2262,  1527, -2262,    33,
    3308,  2425,  3059,  2426,  2069,  3027,     5,    33,  2709,   267,
    2046,     6,    54,   269,  2051,  2057,  2051,  2927,  3060,  2929,
    1114,  2930,  2841, -2262,  1118,   311,  2063,  2065,  2066,  3035,
      54,    58,  2070,  2072,  2073,  2074,  1033,  2427,  3667,  1973,
    2428,  1974,     7,    54,  2060,  1033,  2209,  2210,  2211,    54,
    2212,   312,  2213,  2214,  3211,  3211,  1115,    58,  3211,    58,
      58,    58,  2218,  2512,  2064,  2799,    33,  3362,    58,    58,
    1033,     8,    58,   407,    33,   407,    58,    54,  2039,  1050,
    1510,  1511,  1512,  1513,  1115,   313,     7,  1030,  1030,  1030,
    2737,  2121,  1115,   314,  2040,  2218, -2262,    54,    58,    58,
    1068,  -283, -2262,    54, -2262, -2262,  2067,  2427,    33,  2285,
    2428,   315,  2941,  1077,  2944,     8,   316,  2473, -2262, -2262,
    2582,   346,  2408,  3461,  2878,   347,  3461, -2262,  2286,  2287,
     348,   484,  2218,   375,   485,  1386,   352,  2437,  2482,  2071,
     428,    33,  1096,    58,    58,   353,    58,  1533,  2288,  3668,
    2904,  1103,  3717,  3669,  2255,   357,  2246,  1387,  2247,  2248,
   -2262,   374,  2250,  2251,  3684, -1613,    26,    27,  2270,  2256,
    2162,    33,   407,   407,   106,   107,  1312,   407,  3673,    58,
    1066,  2171,  2172,   361,  2300,  2658,  2301,  -283,  2661,  2662,
    2663,  2664,   106,   107,  1075,  3686,  2223,  1212,  1080,   364,
    1215,   415,   368,  -283,    58,  2569,   416,   417,   418,  2218,
    1094,  2257,  2257,   383,  3201,  3201,  1194, -2262,  3201,   376,
    1200,   392,  2258,  2258,  1204,   384,   393,  1213, -2262,  2223,
    1216, -2262, -2262,  1219,   399,   377,  3550,  1534,  3553,  3554,
    3555,  3556,   402,  2259,  2259,  3673,  -283,   413,   414,  2330,
    2260,  2260,  2012,  2013,   486,   338,   339,   340,  2261,  2261,
    1127, -2262,  3686,  3668,  1253,  1254,  2223,  3669,   403,   487,
    2955, -2262,  2746,   488,    33, -2262,  1382,  1383,   378,  2470,
    2262,  2262,  2749,  3460,    33,  -283,  3460,  2312,   433,  3211,
    1395,  1396,  1397,  1168,   438,  3211,  3211,   435,  3211,  3211,
    3211,  3211,  2203,  2204,  3728,   436,    33,  3211,  1961,   447,
     489,   385,  1980,  2087,  -283,  2087,   457,   379,   450,  3117,
    2189,   107,   451,  -283,  3372,  2215,  3077,   386,  2216,   453,
    2217,  2644,  3202,  3202,  3202,  3202,  3143,   506,   490,  3251,
    3251,   454,  3251,  2223,   519,  3251,   380,  2279,  2280,   455,
    2218, -2262,  2302,  2303,  1247,   381,   491,   526,  2263,   456,
    2219,   517,  3156,   521,  2264,  1248,  2304,  2305,  3114,  2444,
     387,  2014,  2015,  2016,  2017,  2018,  2019,  3339,  2635,   527,
     439,  2220,  2763,   528,  2764,   317,   318,   319,   320,   321,
    2956,  2957,  1402,  2775,  1962,   530,   440,  3254,  1981,  3257,
     531,  1488,  1489,   535,  2221,  1492,  1493,  2419,  2222,   388,
    1963,   536,  2438,  2439,  1982,   537,  1249,  2645,  2796,   540,
    3211,  3699,  3700,  3211,  3211,  3211,  3211,  1234,  1235,   541,
    1250,  3441,  1040,  2646,  2443,  3050,  3051,   492,   389,   441,
   -2262,  2094,  3414,  3415,  1049,   551,  2958,   390,   552,  3201,
     553,  2758,  3461,  1964,   556,  3201,  3201,  1983,  3201,  3201,
    3201,  3201,   561,   571,   572,   577,  3122,  3201,  1516,   582,
    1312,   583,   587,  1069,  3130,  3131,  2647,   595,   442,    63,
     602,   605,   607,   610,  2223,  3580,   606,  2490,   644,  1086,
    1087,   635,  1965,  2589,   638,  1093,  1984,  2292,  1095,   645,
     651,   653,  2800,   493,   658,   654,   655,   443,   656,   657,
     659,   662,   668,  3211,   678,  2648,   444,  3476,     1,  1251,
     933,  1966,  3211,   938,   940,  1985,   997,   941,  2932,   942,
    1967,  1209,   407,   407,  1986,   947,   956,   958,    58,    58,
     959,   960,   967,  2943,  2649,   156,   187,   972,  2348,  2456,
     974,  2835,   976,  2650,  2967,   977,   978,   995,  2242,  1033,
    1002,  1033,  1033,  1003,  1005,  1033,  1033,  1006,  2252,  1011,
    2330,  1033,  1007,  2959,  1008,  2353,  1010,  1012,  1013,  1015,
    3201,  1125,  1201,  3201,  3201,  3201,  3201,  1262,  1263,  1264,
    1265,  1266,  3477,  1267,  1268,    58,  2010,  2011,  2012,  2013,
    1269,  1270,  1271,  1127,  1273,  1274,  2296,  3542,  1277,  1168,
     187,  1278,  3460,  1279,  1280,  1323,  3428,  3429,  3430,  3431,
    1335,  1330,  1331,  3202,  3202,  1332,  1336,  3202,   332,   187,
    1338,  1339,   337,  1911,  1340,  1168,  1341,  1342,  1305,  2960,
    1305,  1343,  3251,  1344,  1348,  2527,  2529,  2539,  1355,  1349,
    1305,  1305,  1033,  1353,  3478,  2339,  3479,  1305,  1305,  1305,
    1305,  1354,  1379,  1356,  2103,  3430,  3431,  1360,  1385,  1388,
    1115,  1384,  3480,  3201,  1392,  1389,  2469,  1398,  1390,  1409,
    3481,  1413,  3201,  3477,  3482,  1414,  3013,  1420,  1417,  2961,
    2962,  1418,  2046,  1421,   650,  1425,  1426,  2051,  1428,  1437,
    1442,  3014,  3015,  2057,  1440,  2512,  2051,  1444,  1445,  3483,
    3016,  2751,  1485,  1495,  1496,  1500,  1350,  2014,  2015,  2016,
    2017,  2018,  2019,  1523,  2406,  2765,  2766,  2094,  2769, -2262,
    2410,  3378,  3081,   505,  1524,  1912,  1312,  2014,  2015,  2016,
    2017,  2018,  2019,  1913,  3017,  3478,  2790,  3479,  1525,  1914,
    1526,  1915,  1530,  3018,   511,   512,  1532,  1535,  2435,  1536,
    1545,   187,  1916,  3480,  1547,   187,  1884,  3111,  1883,   578,
    1885,  3481,  1033,  1115,  1891,  3482,  2451,  2452,  1886,   407,
    1895,  1898,  3019,  3380,  2014,  2015,  2016,  2017,  2018,  2019,
    1917, -2262,  1899, -2262,    58,  1900,  1322,  1901,  1948,  1324,
    3483,  1325,  1326,  1327,  1328,  1329,  1918,  1956,  1959, -2262,
    1969,  1919,  2832,  2480,  2866,    58,  1978, -2262,  1979,  1972,
    1991, -2262,  1992,  1920,  1993,  1994,  1998,  3020,  1999,  2000,
    1921,  2023, -2262,  3263,  2001,  2028,    58,  2049,  2505,  1548,
    2062,  1305,  2078,  2890,  1115,    58, -2262,  2082,  2077,  2079,
    2083,  2084,  3511,  2097,  2113,  2115,  2104,  2111,  3202,  2906,
    1507,  3519,   407,   407,  3202,  3202,  2124,  3202,  3202,  3202,
    3202,  3021,  2137,  2126,  2138,  2149,  3202,   407,  3525,  2150,
    2152,  2154,    58,    58,    58,  2163,  2166,  2168,    58,  2177,
    2184,  1127,  1127,  2192,  2191,  2186,  1033,  2194,  1893,  2232,
    2230,  2233,  2293,  1463,  2235,  2241,  2298,  2297,  2299,  2306,
    2308,  2330,  1989,  2330,  2900,  2323,  2901,  2349,  2331,  2355,
    2344,  2356,  2357,    58,  2360,  2361,  2362,  2365,  2396,  2394,
    2398,  2625,  2625,  2118,  2397,  2625,  2400,  2399,  2403,  2412,
    2414,  2415,  3273,  3274,  3275,   639,  3277,  3278,  3279,  3280,
    3281,  3282,  2401,  1030,  1305,  3285,   187,  2416,  2417,  2418,
    2420,  2421,  2422,  1305,  2423,  2436,  1305,  1305,  1305,  1305,
    2665,  1892,  2459,  1033,  2461,  3569,  2424,  2670,  1305,  1922,
    2462,  2688,  2466,  2468,  1923,  2471, -2262,  2475,  2476,  3202,
     184,  1924,  3202,  3202,  3202,  3202,  2484,  2481,  2485,  2488,
    2502,  2494,  2705,  2705,  2705,  2508,  2518,  2705,  1305,  2719,
    2520,  2567,  2046,  1925,  1237,  2568,  2579,  2585,  1926,   187,
    2593,  2594,  2595,  2598,  3620,  2600,  2599,  2633,  2622,  2634,
    2655,  2615,  3203,  3203,  3203,  3203,  2657,  2669,  2685,  2444,
    2614,  2744,  2636,  2745,  2747,  2640,  2748,  2750,  2656,  2690,
    2752,  2692,  3353,  2694,  2051,  2696,  2755,  2697,  2051,    58,
    2701,    58,  2724,  3204,  3204,  3204,  3204,  1033,  2705,  2725,
      58,  2435,  2726,  2760,  2780,  2780,  1030,  2729,  3083,  2771,
    3369,  3088,  3202,  2791,  2730,  2731,  2789,  2732,  2733,  2793,
    2794,  3202,   187,  2795,  2797,    58,  2801,  2809,  2810,  2812,
    2813,  2815,  2798,  1464,  2817,    58,  2816, -2262,  2833,  1030,
    2814,  2836,  1497,  1236,    58,  2840,  2849,  2851,    58,  2834,
    1016,  1017,  1018,  2860,  1021,  2865,  2869,  2861,  2862,  2879,
    2902,  3466,  2877,  2967,  2870,  3696,  2907,  3625,  2912,  2946,
    2920,  1047,  2921,    58,  2922,  1163,  2923,  2924,  2928,  2925,
    2945,  2931,  1053,  1053,  2933,  2934,  2935,  2936,  2968,  2971,
    2980,  3029,  3030,  3039,  3042,  3043,  3046,  2842,  3031,  3674,
    3675,  3676,  3677,  3678,  3679,  3048,  3049,  1071,  3068,  3069,
    3078,  3079,  3082,  1076,  3084,  1078,  3085,  3092,  3096,  1085,
    3103,  3129,  1085,  3118,  3110,  1085,  3100,  3121,  3139,  3162,
    3151,  3163,  3181,  3171,  3178,  1098,  2004,  3182,  3223, -2262,
    3230,  3240,  3253,  3239,  3241,  3256,  3264,  1033,  3266,  3243,
    1098,  3276,  3291,  3244,  3272,  3283,  1159,  3271,  3284,  3290,
    1465,  3294,  2705,  1021,  1172,  1175,  1466,  1467,  1468,  1190,
    2881,  2252,  2705,  3295,  3056,  2242,  1033,  1202,  1305,   926,
    1053,  3296,  3297,  3298,  3299,  3300,  3305,  3312,  1469,  3313,
    1224,  2242,  1033,  1226,  3317,    58,  2625,  3319,  3323,  3324,
    3328,  3348,  1312,  3354,  3355,  3357,  3356,  3470,  3691,  3152,
    3370,  3154,  1954, -2262,  3374,  2118,  2310,  3379,  3376,  3391,
    3383,  1231,  3404,  3394,  3398,  3426,  3417,  3436,  3141,  3437,
    3327,  3418,  3419,  3420,  3421,  3422,  1305,  3443,  3423,  3446,
    3447,  3450,  3448,  3449,  1033, -1802,  1033,   926,  3474,  1305,
    3455,  1305,  3513,  3203,  3203,  3492,  3027,  3203,  3494,  3493,
    3120,  3496,  1305,  3497,  3498,   650,  3499,  2705,    58,  2688,
    3523,  3503,   184,   650,   650,  3505,  3506,  3512,  3516,  3518,
    3522,  2705,  3524,  3526,  3204,  3204,  2139,  3527,  3204,  3528,
    3532,  3530,  3536,  2005,  1470, -2262,  3763,  1471, -2262,  2051,
    3546,  3548,  3566,  3576,  3577,  1472,  3586,  3578,  3596,  3597,
    3598,  3599,  3601,   184,  3606,  3184,  3185,  2057,  3649,  2051,
    3600,   274,  1284,  1285,    33,  3619,  3618,  3624,  3631,  3641,
    3664,  3652,  2406,  3654,  3680,  3702,  3693,  1306,  3704,    58,
    1473,  3705,  3706,  3367,  3707,  3639,  3712,  3710,  3721,  1030,
    3732,  3733,  3746,  3744,  3742,  1030,  3745,  3750,  3751,  3756,
    3747,  3761,  3757,  3125,  2435,  3762,  3102,  3074,  3104,  3720,
    2825,  2705,  1033,  2176,    58,  1474,    50,  1345,  2493,  3386,
      49,  1030,   833,  2776,  3099,  3656,  2785,   532,   193,    58,
    1168,    58,  3126,    58,  1475,  1476,   198,   345,   525,  1004,
    2350,   358,  2351,   350,   533,  1477,    58,   560,   966,  3186,
    1478,   671,  3605,  1305,  2672,   937,   943,  1224,   558,  2330,
    1226,  3445,  1975,  1281,  1282,  1283,   407,   944,   407,   274,
    1284,  1285,    33,  3718,  2409,  1337,  1403,  1188,    58,    58,
     591,  1952,  2623,  2202,  1305,  2767,  2631,  3366,  2453,  1479,
    3393,  3150,  2206,  2517,  3743,  2839,  2705,  2772,  2537,  2108,
    3371,  3521,    46,   130,    60,  3487,    61,    47,  2500,  1092,
    3200,  3200,  3200,  3200,  2705,  2705,  1261,  2503,  1431,  2190,
     516,  1480,  2229,  2144,    58,  2507,  3475,  1889,  3203,  3225,
    3587,  1124,  2099,  2142,  3203,  3203,  3639,  3203,  3203,  3203,
    3203,  1359,  3724,  3595,  3145,  2089,  3203,  3304,  1459,  1459,
    1459,  2157,  1459,  3303,  1459,  1459,  3361,  1286,  2472,  3204,
      63,    63,  1305,  1305,   611,  3204,  3204,  3286,  3204,  3204,
    3204,  3204,  3025,  1305,  1305,  1114,  1305,  3204,  3350,  1305,
    3509,  1305,  3507,  3504,  2395,  1305,  3333,  2364,  2721,  2761,
    2871,  3727,  3468,  2272,  2273,  1175,  2597,  1463,  2891,  3411,
    3306,  3602,  3329,  2668,  2588,  3248,  2940,  1543,  3249,  3463,
    3655,  3325,  3041,   184,  3491,  2245,  3026,    42,  3755,  1940,
    2979,  2978,   650,  3413,  2325,    58,  3177,  3467,  1224,  2324,
    2237,  1226,  1403,  3633,  3514,  2883,  1906,  3409,    58,  3549,
    1896,  3567,  2200,  3559,  2347,  1439,  3109,  2705,  3309,  2705,
    2117,  2123,  3106,  2792,   679,  2107,  1904,  1904,     0,  3203,
       0,     0,  3203,  3203,  3203,  3203,     0,     0,     0,  3537,
       0,     0,     0,  1033,     0,     0,     0,  1030,  1030,     0,
       0,     0,     0,  1114,     0,  3331,  3332,  1306,  1306,  2752,
    3204,     0,  2051,  3204,  3204,  3204,  3204,  1306,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2780,
       0,     0,  3363,  2780,     0,     0,     0,   407,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
     407,     0,    58,  2982,  2983,     0,  2984,  2985,  2986,     0,
       0,    58,     0,  1287,     0,     0,     0,     0,  3510,     0,
       0,     0,  3203,     0,     0,  1288,     0,     0,     0,     0,
       0,  3203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3395,  1289,     0,  3204,     0,     0,  2705,  2673,     0,     0,
       0,     0,  3204,     0,     0,  2881,  2705,  1464,  2242,  2242,
       0,  3200,  3200,     0,     0,  3200,     0,     0,     0,     0,
       0,     0,  3187,     0,     0,  3188,  3424,     0,     0,    63,
       0,    63,  1175,  1085,     0,     0,     0,     0,  3189,     0,
    2098,  1098,     0,     0,  1175,     0,  2987,     0,  2109,    58,
    2242,     0,     0,     0,  2988,     0,     0,     0,     0,   187,
       0,  1287,     0,     0,     0,     0,     0,  1224,     0,     0,
    1226,  1159,  1033,  1288,     0,     0,     0,  3190,  3191,     0,
    1115,     0,     0,  1115,     0,     0,  1305,     0,  2989,  1305,
    3192,  1305,     0,  2705,     0,   158,   159,  2990,     0,  1289,
       0,     0,     0,   160,    33,     0,     0,     0,  3683,     0,
       0,     0,     0,     0,     0,  2143,  1159,    58,    63,     0,
       0,     0,     0,     0,     0,     0,  2991,  2992,     0,     0,
    1290,  3193,     0,  2674,  1465,     0,     0,     0,     0,     0,
    1466,  1467,  1468,     0,     0,  2675,  1292,     0,     0,  2274,
    2275,  2169,     0,     0,     0,  1305,  2291,     0,     0,     0,
       0,     0,  1469,     0,     0,     0,     0,     0,     0,     0,
    3194,  2993,     0,  1989,     0,   407,  2196,     0,     0,    58,
    3630,     0,  3195,     0,   161,     0,  1293,     0,     0,     0,
       0,     0,     0,     0,  3196,  3197,   162,    58,  1294,     0,
       0,     0,  3198,     0,     0,  3199,     0,     0,     0,     0,
       0,  3740,     0,   295,     0,  2994,     0,     0,     0,     0,
       0,     0,     0,   163,     0,    58,     0,     0,     0,     0,
    1305,     0,     0,  2705,     0,     0,     0,     0,     0,  1295,
       0,     0,     0,     0,  1305,     0,  3200,     0,     0,     0,
       0,     0,  3200,  3200,     0,  3200,  3200,  3200,  3200,     0,
       0,  2705,     0,  2705,  3200,   184,  1305,     0,  1470,     0,
    2995,  1471,  1296,     0,     0,     0,     0,     0,  1297,  1472,
       0,     0,     0,     0,     0,     0,     0,  1298,  1299,     0,
    1300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,  1301,  1302,     0,     0,    58,     0,    58,     0,
    1303,     0,     0,  1304,  1473,    54,     0,   164,     0,     0,
       0,   295,     0,     0,     0,     0,  2705,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1474,
       0,     0,  3502,     0,     0,     0,     0,    58,     0,     0,
       0,     0,  3502,     0,  2474,     0,     0,  3395,  1475,  1476,
       0,     0,     0,  1305,     0,     0,     0,  3200,     0,  1477,
    3200,  3200,  3200,  3200,  1478,  3650,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3653,
       0,     0,     0,     0,  2515,     0,     0,     0,     0,  1115,
       0,     0,     0,  1305,   165,     0,     0,     0,     0,     0,
       0,     0,     0,  1479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    58,    58,    58,    58,    58,
       0,     0,     0,     0,     0,     0,  3685,     0,     0,   166,
       0,     0,     0,     0,     0,  1480,  1030,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3200,     0,     0,     0,     0,     0,     0,     0,     0,  3200,
       0,     0,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   168,  2996,  2997,  2998,  2999,
    3000,  3001,  3002,  3003,  3004,  3005,     0,     0,  1224,     0,
    2228,  1226,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,   272,   273,  1305,     0,  3729,     0,   274,   275,
     276,    33,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2278,   172,     0,
       0,  3753,  3754,  3729,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,  3764,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2209,  2210,
    2211,     0,  2212,     0,  2213,  2214,     0,  1306,     0,  1306,
       0,   161,   173,     0,     0,     0,   277,     0,     0,  1306,
    1306,     0,     0,   162,     0,     0,  1306,  1306,  1306,  1306,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,     0,     0,     0,     0,   599,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,  2821,
    2822,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2831,     0,     0,   474,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2843,  2844,  2845,  2846,  2847,  2848,
       0,     0,     0,     0,  2853,  2854,  2855,  2856,     0,     0,
       0,  2858,    54,     0,   164,     0,     0,   271,   471,   472,
     473,     0,     0,     0,     0,     0,   272,   273,     0,     0,
       0,     0,   274,   275,   276,    33,  2465,     0,     0,     0,
     474,     0,     0,     0,     0,  1053,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   178,   179,
     475,   476,   477,   478,   479,   480,     0,     0,   156,     0,
    1306,     0,     0,     0,     0,     0,     0,  1159,   481,   482,
     483,     0,     0,  2910,  2911,     0,     0,     0,     0,     0,
    2915,  2916,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,     0,   161,   278,     0,     0,     0,
     277,     0,     0,     0,  1175,  2571,  1175,   162,     0,     0,
    1021,     0,     0,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,     0,   166,  2215,     0,     0,
    2216,     0,  2217,     0,   163,   481,   482,   483,     0,     0,
       0,     0,     0,     0,     0,  2617,     0,     0,     0,     0,
       0,     0,  2218,     0,     0,     0,     0,     0,     0,     0,
     167,     0,  2219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,  1306,     0,     0,     0,     0,     0,     0,
       0,     0,  1306,  2536,     0,  1306,  1306,  1306,  1306,     0,
     279,     0,     0,     0,     0,   280,     0,  1306,   281,     0,
       0,     0,     0,     0,     0,     0,  2221,     0,   484,   169,
    2222,   485,     0,     0,   282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,     0,    54,  1306,   164,   283,
    3090,  3091,   284,     0,     0,   285,     0,     0,     0,  3098,
       0,     0,     0,     0,   286,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,  3132,  3133,   485,     0,
       0,  1175,     0,  1175,   646,   287,  2223,     0,     0,   173,
       0,     0,  1175,     0,     0,     0,     0,   288,     0,     0,
       0,     0,     0,  3153,     0,  3155,     0,     0,   289,     0,
     187,     0,     0,     0,   174,     0,     0,  1175,     0,     0,
       0,     0,     0,     0,  1224,   165,     0,  1226,     0,     0,
     278,   486,     0,     0,     0,     0,  2805,     0,   290,     0,
    2808,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,     0,     0,     0,  2830,  3226,  3227,     0,     0,
    3228,  3229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,   489,     0,   291,
       0,   177,     0,     0,   167,     0,     0,     0,   486,     0,
       0,   292,   293,     0,     0,     0,   168,     0,     0,   294,
       0,     0,     0,   487,     0,   490,     0,   488,     0,     0,
     295,     0,     0,     0,   279,     0,     0,     0,     0,   280,
       0,     0,   281,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,     0,     0,   282,     0,
       0,     0,     0,     0,   489,     0,     0,     0,   170,     0,
       0,     0,     0,   283,     0,  3293,   284,  1306,     0,   285,
       0,     0,     0,     0,     0,   178,   179,     0,   286,   172,
       0,     0,   490,     0,     0,     0,     0,  2908,     0,     0,
       0,   473,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,     0,     0,   492,     0,     0,     0,  1399,   287,
       0,     0,     0,   173,     0,  1306,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,     0,     0,  1306,     0,
    1306,     0,   289,     0,     0,     0,  3360,     0,   174,     0,
    3365,  1306,   467,   468,   469,   470,   471,   472,   473,     0,
    1175,     0,     0,     0,     0,     0,     0,     0,     0,  3373,
       0,     0,   290,     0,     0,     0,     0,     0,   474,     0,
     493,   492,     0,     0,  2806,   458,   459,   460,  3384,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,  1306,     0,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,   176,     0,     0,     0,
       0,   474,     0,   291,     0,   177,   481,   482,   483,     0,
       0,  1175,     0,     0,     0,   292,   293,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,   493,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,   187,     0,     0,     0,  1175,     0,     0,     0,
       0,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,  3123,     0,  1047,     0,  3127,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,     0,     0,  3138,     0,
       0,     0,  1306,   187,     0,     0,     0,     0,     0,   178,
     179,     0,     0,     0,     0,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,     0,     0,     0,     0,
    3158,  3160,     0,  1306,     0,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2262,
   -2262, -2262,     0, -2262,     0, -2262, -2262,     0,     0,  1306,
    1306,  1306,  1306,     0,     0,     0,   484,     0,     0,   485,
       0,     0,     0,     0,     0,     0,  3224,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1306,  1306,   474,     0,     0,     0,     0,     0,   474,
       0,     0,  1306,  1306,     0,  1306,     0,     0,  1306,     0,
    1306,     0,     0,   484,  1306,     0,   485,     0,     0,     0,
    3535,     0,     0,  3538,     0,     0,     0,     0,     0,     0,
    1053,  1053,  1053,     0,  1053,  1053,  1053,  1053,  1053,  1053,
       0,     0,     0,  1053,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,  3287,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   486,
    3302,     0,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,   487,     0,     0,     0,   488,     0,
     475,   476,   477,   478,   479,   480,   475,   476,   477,   478,
     479,   480,   474,     0,     0,     0,     0,     0,   481,   482,
     483,     0,     0,     0,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,     0,
       0,  1175,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,   487,     0,   490,     0,   488,     0,     0,     0,  1175,
       0,     0,     0,     0,  1159,     0,     0,  3628,     0,     0,
    1224,   491,     0,  1226,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,   487,     0,     0,     0,   488,   475,
     476,   477,   478,   479,   480,     0,     0,     0, -2262,     0,
       0, -2262,     0, -2262,     0,     0,     0,   481,   482,   483,
     490,  3657,  3658,     0,  3660,     0,  3662,  3663,     0,     0,
    1306,  1306,     0, -2262,  1306,   489,     0,     0,   491,     0,
       0,     0,     0, -2262,     0,     0,     0,     0,   484,     0,
       0,   485,   492,     0,   484,     0,     0,   485,   271,     0,
       0,     0,     0,   490, -2262,     0,     0,   272,   273,     0,
       0,  1159,     0,   274,   275,   276,    33,     0,     0,     0,
       0,   491,     0,     0,     0,     0,     0, -2262,     0,     0,
       0, -2262,  3713,     0,  3714,     0,     0,     0,     0,  1306,
       0,     0,  1306,     0,     0,  1306,   271,     0,  1306,     0,
    1306,     0,     0,     0,     0,   272,   273,     0,   493,   492,
       0,   274,   275,   276,    33,     0,     0,     0,  3726,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3287,
       0,     0,     0,     0,     0,     0,     0,     0,  3737,  3738,
       0,     0,  3739,     0,     0,  3741,   161,   484,     0,     0,
     485,   277,   492,     0,     0,     0,     0, -2262,   162,     0,
       0,   486,     0,     0,  1306,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,   493,   487,     0,     0,     0,
     488,   586,   487,     0,     0,   163,   488,     0,     0,     0,
       0,  1175,     0,     0,   161,     0,     0,     0,     0,   277,
       0,     0,     0,     0,     0,     0,   162,     0,     0,  1175,
       0,     0,     0,     0,     0,     0,     0,   489,   493,     0,
       0,     0,     0,   489,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,  1159,     0,  1306,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,   490,     0,  1306,     0,  1306,     0,     0,     0,     0,
       0,  1306,  1306,   491,  1306,  1306,  1306,  1306,     0,   491,
     486,     0,     0,  1306,     0,  1306,     0,    54,     0,   164,
       0,     0,     0,     0,     0,   487,     0,     0,     0,   488,
       0,  1306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3287,     0,     0,     0,     0,  3590,     0,
    3592,     0,     0,     0,     0,    54,   489,   164,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,   272,
     273,     0,     0,     0,   492,   274,   275,   276,    33,     0,
     492,  1175,     0,     0,   490,     0,     0,     0,  1130,  1131,
    1132,  1133,     0,     0,     0,     0,  1224,     0,     0,  1226,
       0,     0,   491,     0,     0,   187,   165,     0,     0,     0,
       0,   278,  1306,     0,     0,     0,  1306,     0,     0,  1306,
    1306,  1306,  1306,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     493,   166,     0,     0,     0,     0,   493,     0,  1306,     0,
       0,     0,  1306,     0,   165,     0,     0,     0,   161,   278,
       0,     0,     0,   277,     0,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,   167,  1459,  1459,  1459,  1459,
    1459,  1459,     0,   492,     0,     0,     0,   168,     0,   166,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,  1306,
     280,  1134,     0,   281,     0,     0,     0,     0,  1306,  1135,
     474,     0,     0,   167,   169,     0,     0,     0,  1136,   282,
       0,  1137,     0,     0,     0,   168,     0,     0,     0,   170,
       0,     0,     0,     0,   283,     0,     0,   284,     0,   493,
     285,     0,     0,   279,   569,     0,     0,     0,   280,   286,
     172,   281,     0,  1306,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,  1138,     0,     0,   282,     0,     0,
       0,  1139,     0,     0,     0,     0,     0,   170,     0,    54,
       0,   164,   283,     0,     0,   284,     0,     0,   285,  3142,
     287,     0,     0,     0,   173,     0,     0,   286,   172,     0,
       0,     0,   288,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,   289,     0,  1224,     0,     0,  1226,   174,
       0,     0,     0,     0,     0,   481,   482,   483,  1140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,   173,   290,     0,     0,     0,     0,     0,     0,
     288,     0,     0,  1141,     0,     0,     0,     0,     0,     0,
    1142,   289,  1143,  2768,     0,     0,     0,   174,     0,     0,
       0,     0,  1144,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   278,     0,     0,     0,   176,     0,     0,
       0,   290,     0,     0,   291,     0,   177,     0,     0,     0,
    1145,     0,     0,     0,     0,     0,   292,   293,  1146,     0,
       0,     0,     0,   166,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,     0,     0,     0,     0,
       0,     0,   291,     0,   177,  1147,     0,   167,     0,     0,
       0,     0,     0,     0,   292,   293,     0,  2368,     0,   168,
       0,     0,   294,     0,     0,   484,     0,     0,   485,     0,
    1148,     0,     0,   295,     0,     0,     0,   279,     0,     0,
     178,   179,   280,     0,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
       0,   282,     0,     0,     0,     0,     0,  1149,     0,     0,
       0,   170,     0,     0,     0,     0,   283,     0,  1150,   284,
       0,     0,   285,     0,     0,     0,     0,     0,   178,   179,
       0,   286,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,     0,     0,
    1560,  1561,  1562,  1563,  1564,  1565,     0,  1566,  1567,  1568,
       0,     0,     0,  1569,  1570,  1571,  1572,  1573,  1574,     0,
       0,     0,   287,     0,     0,     0,   173,     0,  1575,     0,
       0,     0,     0,     0,   288,     0,   133,     0,   486,     0,
       0,     0,     0,     0,     0,   289,     0,     0,  1576,     0,
       0,   174,     0,   487,     0,   134,   135,   488,     0,     0,
       0,     0,     0,     0,     0,     0,  1151,  1152,  1153,     0,
       0,     0,     0,     0,     0,   290,     0,     0,     0,  1154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1577,     0,   137,     0,     0,
       0,     0,     0,     0,  1578,     0,     0,     0,   138,   176,
       0,     0,   490,     0,     0,     0,   291,     0,   177,     0,
       0,     0,  1579,  1580,     0,   139,     0,     0,   292,   293,
     491,  1581,     0,  2369,     0,   140,   294,     0,  1582,  1583,
       0,     0,  1584,  1585,  1586,  1587,     0,   295,  1588,  1589,
     141,     0,     0,  2370,  2371,  2372,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1590,     0,
     142,     0,  2373,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   178,   179,  2374,     0,     0,     0,     0,     0,
    1591,   492,     0,   143,     0,  2375,  1592,     0,     0,     0,
       0,     0,  2199,  1593,     0,  1594,     0,     0,   144,     0,
    1595,     0,  2376,     0,     0,   145,     0,     0,   146,     0,
       0,     0,  2377,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1596,  2378,     0,   147,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   493,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1597,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,  2379,     0,  1598,     0,     0,
       0,     0,     0,  1599,     0,     0,     0,     0,     0,     0,
       0,     0,  1600,  1601,     0,     0,     0,     0,     0,  1602,
       0,     0,  1603,  1604,     0,  2380,     0,  1605,     0,     0,
       0,     0,     0,  1606,  1607,  2381,     0,     0,     0,     0,
    1608,  1609,  1610,     0,     0,  1611,  1612,  1613,     0,     0,
       0,  1614,     0,     0,     0,  1615,  2382,  1616,     0,     0,
    2383,     0,     0,     0,  1617,  1618,  1619,  1620,     0,  1621,
    1622,     0,     0,     0,  1623,  1624,     0,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,     0,     0,     0,     0,  2384,  1632,
    1633,  1634,     0,  1635,  1636,     0,     0,  2385,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,  1644,     0,  1645,     0,     0,
       0,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,     0,  1683,
    1684,     0,     0,  1685,  1686,  1687,  1688,  1689,  1690,  1691,
    1692,  1693,  1694,     0,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,     0,
       0,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,
       0,  1719,  1720,  1721,  1722,     0,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,
    1757,  1758,     0,  1759,  1760,  1761,  1762,  1763,  1764,     0,
       0,  1765,  1766,     0,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
       0,     0,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,
    1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,  1853,  1854,     0,     0,     0,     0,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1866,
       0,     0,     0,     0,   132,     0,     0,  1867,     0,     0,
       0,     0,  1868,     0,     0,     0,  1869,     0,     0,  1870,
    1871,  1872,  1873,     0,     0,  1874,  1875,     0,  1876,  1877,
    1878,  1560,  1561,  1562,  1563,  1564,  1565,     0,  1566,  1567,
    1568,     0,     0,   133,  1569,  1570,  1571,  1572,  1573,  1574,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1575,
       0,     0,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1577,     0,     0,     0,
       0,     0,   139,     0,     0,  1578,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1579,  1580,     0,     0,   141,     0,     0,
       0,     0,  1581,     0,     0,     0,     0,     0,     0,  1582,
    1583,     0,     0,  1584,  1585,  1586,  1587,     0,     0,  1588,
    1589,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1590,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,  1591,   145,     0,     0,   146,     0,  1592,     0,     0,
       0,     0,     0,     0,  1593,     0,  1594,     0,     0,     0,
       0,  1595,     0,     0,     0,     0,   147,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1596,     0,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1597,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1598,     0,
       0,     0,     0,     0,  1599,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,  1601,     0,     0,     0,     0,     0,
    1602,     0,     0,  1603,  1604,     0,     0,     0,  1605,     0,
       0,     0,     0,     0,  1606,  1607,     0,     0,     0,     0,
       0,  1608,  1609,  1610,     0,     0,  1611,  1612,  1613,     0,
       0,     0,  1614,     0,     0,     0,  1615,     0,  1616,     0,
       0,     0,     0,     0,     0,  1617,  1618,  1619,  1620,     0,
    1621,  1622,     0,     0,     0,  1623,  1624,     0,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,     0,     0,     0,     0,     0,
    1632,  1633,  1634,     0,  1635,  1636,     0,     0,     0,  1637,
    1638,  1639,  1640,  1641,  1642,  1643,  1644,     0,  1645,     0,
       0,     0,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,     0,
    1683,  1684,     0,     0,  1685,  1686,  1687,  1688,  1689,  1690,
    1691,  1692,  1693,  1694,     0,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
       0,     0,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,
    1718,     0,  1719,  1720,  1721,  1722,     0,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,     0,  1759,  1760,  1761,  1762,  1763,  1764,
       0,     0,  1765,  1766,     0,  1767,  1768,  1769,  1770,  1771,
    1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,     0,     0,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854, -2263,     0,     0,     0,  1855,
    1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,
       0, -2263, -2263, -2263,     0, -2263,     0, -2263, -2263,     0,
    1866,     0,     0,     0,     0,     0,     0,     0,  1867,     0,
       0,     0,     0,  1868,     0,     0,     0,  1869,     0,     0,
    1870,  1871,  1872,  1873,     0,     0,  1874,  1875,     0,  1876,
    1877,  1878,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2263,     0, -2263,     0,     0,     0,
       0,     0,     0,     0,     0,  1281,  1282,  1283,     0,     0,
       0,   274,  1284,  1285,    33,     0,     0,     0,     0,     0,
       0, -2263,     0,     0,     0,     0,     0,     0, -2263,     0,
   -2263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2263,     0,     0,     0,     0, -2263,     0,     0,     0,
       0,     0,     0,     0, -2263,     0,     0,     0, -2263,     0,
       0,     0,     0,     0, -2263,     0,     0,     0, -2263, -2263,
   -2263, -2263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1286,
   -2263,     0,     0, -2263,     0, -2263,     0,     0,     0,     0,
       0,     0, -2263,     0,     0,     0,     1,     0,     0,     0,
       2,     0,   681,   682,   683, -2263,     0,     0,     0,     0,
     684,     0,     0,   685,     0, -2263,     0,     0,     0,     0,
     686,   687,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2263, -2263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2263,     0,     0,     0,     0,     0,     0,     0, -2263,
       0,     0,     0, -2263,     0,   688,   689,     0,     0,     0,
     690, -2263, -2263, -2263,     0,     0,     0,     0,     0,     0,
     691,   692,     0,   693,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   694,     0,     0,
       0,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,   695,     0,     0,   696,   697,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   698,     0,   699,   700,   701,     0,     0, -2263,
       0,     0,     0,     0,   702,   703,     0,   704,   705,   706,
   -2263,     0,     0,     0,     0,   707,     0,     0,   708,     0,
     709,   710,   711,     0,     0,     0,     0,     0,   712,     0,
     713,   714,     0,   715,     0,   716,   717,     0,     0,   718,
       0,     0,   719,   720,   721,   722,   723,   724,     0,     0,
   -2263,   725,   726,   727,     0,   728,     0,     0,     0,   729,
       0,   730,   731,     0,     0,     0,     0,   732,     0,  2673,
     733,     0,     0,   734,     0,   735,     0,   736,     0,   737,
       0,     0,     0,   738,   739,     0,   740,   741,   742,     0,
       0,   743,     0,   744,   745,     0,   746,     0,     0,     0,
       0,     0,     0,     0,   747,   748,     0,     0,     0,     0,
       0, -2263,     0,     0,     0,     0,     0,   749,     0,     0,
     750,   751,     0,     0,   752,   753,     0,     0,   754,   755,
       0,     0,     0,  1287,     0,     0,     0,   756,   757,   758,
       0,   759,     0,     0,     0,  1288,     0, -2263,     0,     0,
       0,   760,   761,   762,     0,   763,     0,     0,     0,   764,
     765,     0,     0,     0,   766,     0,     0,     0,     0,     0,
       0,  1289,   767,     0,     0,     0,     0,     0,     0,     0,
     768,   769,   770,     0,     0,     0,     0,     0,   771,   772,
       0,     0,     0, -2263,     0,     0,   773,     0,     0,   774,
       0,     0,  1290,   775,   776,  2674,     0, -2263, -2263, -2263,
   -2263, -2263, -2263, -2263,   777, -2263, -2263,  2675,  1292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   778, -2263,     0,     0,     0,     0,     0,     0,   779,
       0,     0,     0,     0,     0,   780,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   781,     0,  1293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,   782,
    1294,     0,     0,     0,     0,   783,     0,   784,   785,     0,
       0,     0,     0,     0,     0,   786,     0,     0,     0,     0,
       0,     0,   458,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,  1295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   787,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,   788,     0,     0,     0,     0,
       0,     0,   789,     0,  1296,     0,     0,     0,     0,     0,
    1297,     0,     0,     0,     0,     0,     0,     0,     0,  1298,
    1299,     0,  1300,     0,     0,     0,   790,   791,     0,     0,
       0,   792,     0,     0,  1301,  1302,     0,     0,     0,     0,
       0,     0,  1303,   793,     0,  1304,     0,     0,     0,   794,
     795,   796,   797,   295,     0,     0,   798,     0,     0,     0,
     799,     0,     0,     0,     0,     0,     0,   800,   801,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   802,     0,
     803,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,   804,     0,   805,     0,     0,   806,     0,     0,     0,
       0,     0,   807,   481,   482,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   808,     0,
       0,   809,     0,     0,     0,     0,   810,     0,     0,   811,
     812,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   813,     0,     0,     0,   458,   459,
     460,   814,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   815,   816,   817,   818,   819,   820,
     821,     0,     0,   822,   474,   823,     0,   824,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,  2540,  2541,  2542,  2543,  2544,  2545,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,   488,   598,     0,     0,     0,
       0,     0,     0,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2546,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
     458,   459,   460,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,   484,
     490,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,   491,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,   484,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,   459,   460,   474,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   492,
       0,     0,   484,     0,     0,   485,     0,     0,     0,     0,
       0,     0,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,   481,   482,   483,     0,     0,     0,   487,     0,     0,
       0,   488,   608,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,   486,     0,     0,   493,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,   487,   489,     0,
       0,   488,   973,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,  2547,     0,     0,     0,
       0,     0,     0,   481,   482,   483,   490,     0,     0,  2548,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,   491,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,   488,   979,   490,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   491,     0,     0,     0,     0,     0,
       0,   484,  2549,     0,   485,     0,     0,     0,  2550,     0,
       0,   489,     0,   474,     0,   458,   459,   460,     0,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,   492,     0,     0,     0,   490,
     484,     0,     0,   485,     0,     0,     0,  2551,     0,     0,
       0,   474,     0,     0,   458,   459,   460,   491,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,  2552,     0,   484,     0,   492,   485,     0,     0,     0,
       0,  2553,  2554,     0,     0,     0,     0,  2555,     0,     0,
     474,     0,     0,     0,     0,     0,     0,  2556,     0,     0,
       0,   493,     0,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,  2557,
       0,     0,  2558,  2559,   486,     0,     0,  2560,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,   492,   487,
       0,   493,     0,   488,   980,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,     0,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
     489,     0,   488,   981,  2561,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,  2562,   486,     0,     0,     0,
       0,     0,     0,     0,   493,   481,   482,   483,   490,     0,
       0,   487,     0,     0,     0,   488,   982,     0,     0,   489,
       0,     0,     0,   458,   459,   460,   491,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,   490,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,   474,
       0,     0,     0,     0,     0,   491,     0,     0,   484,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   491,     0,
       0,     0,     0,     0,     0,     0,   484,   492,     0,   485,
       0,     0,     0,     0,     0,     0,     0,   474,     0,     0,
       0,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,   492,     0,   485,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,   481,   482,   483,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     488,     0,   493,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   486,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,   493,     0,   489,   488,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
     984,     0,     0,     0,     0,     0,     0,     0,   486,     0,
     481,   482,   483,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,   487,     0,   489,     0,   488,     0,     0,
       0,     0,     0,   491,     0,     0,     0,     0,   985,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   490,   484,     0,     0,   485,     0,     0,
       0,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,   491,   474,     0,     0,     0,     0,   988,     0,     0,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,   474,   484,     0,   492,   485,  2672,     0,     0,     0,
       0,     0,     0,     0,     0,  1281,  1282,  1283,     0,     0,
       0,   274,  1284,  1285,    33,     0,     0,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
     484,     0,   492,   485,  1281,  1282,  1283,     0,     0,     0,
     274,  1284,  1285,    33,     0,     0,   474,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,   486,     0,     0,
     493,     0,     0,     0,     0,     0,     0,   481,   482,   483,
       0,   492,   487,     0,     0,     0,   488,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,     0,     0,   493,  1286,
       0,     0,     0,     0,   474,     0,   481,   482,   483,     0,
       0,     0,     0,   489,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1286,     0,
     487,     0,     0,     0,   488,     0,     0,   493,     0,     0,
       0,   490,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,   491,
       0,   481,   482,   483,     0,     0,     0,     0,   487,     0,
       0,   489,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   490,
       0,   475,   476,   477,   478,   479,   480,   484,     0,   489,
     485,     0,     0,     0,     0,     0,     0,   491,   474,   481,
     482,   483,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,     0,     0,
     492,     0,     0,     0,     0,     0,   484,     0,     0,   485,
    1281,  1282,  1283,     0,  1114,   491,   274,  1284,  1285,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1281,  1282,
    1283,     0,     0,     0,   274,  1284,  1285,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   492,     0,
       0,   484,     0,     0,   485,     0,   493,     0,     0,     0,
       0,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,  2673,
     486,     0,     0,   481,   482,   483,   492,     0,     0,     0,
       0,     0,     0,     0,  1286,   487,     0,     0,     0,   488,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   485,     0,   493,     0,     0,     0,     0,   486,
       0,     0,  1286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,   489,     0,   488,     0,
       0,     0,     0,  1287,     0,     0,     0,     0,     0,     0,
       0,     0,   493,     0,     0,  1288,     0,     0,     0,  1281,
    1282,  1283,     0,     0,   490,   274,  1284,  1285,    33,     0,
       0,     0,  1287,     0,   486,   489,     0,     0,     0,     0,
       0,  1289,   491,     0,  1288,     0,     0,     0,   983,   487,
       0,     0,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
    1289,     0,  1290,     0,     0,  2674,     0,     0,     0,     0,
    1114,   491,     0,   484,     0,     0,   485,  2675,  1292,     0,
     489,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,  1290,     0,     0,  1291,     0,     0,   487,  1114,     0,
       0,   488,     0,  1286,     0,     0,     0,  1292,   490,     0,
       0,     0,     0,   492,     0,     0,     0,     0,  1293,     0,
       0,     0,     0,     0,     0,     0,   491,     0,     0,     0,
    1294,     0,     0,     0,  1989,     0,     0,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,  1293,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,  1294,
       0,  1281,  1282,  1283,     0,     0,   490,   274,  1284,  1285,
      33,  1295,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,     0,
    1295,     0,     0,     0,  1296,     0,     0,   492,     0,     0,
    1297,   487,     0,     0,     0,   488,     0,     0,   493,  1298,
    1299,     0,  1300,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,  1296,  1301,  1302,     0,     0,  1287,  1297,
       0,     0,  1303,     0,     0,  1304,     0,     0,  1298,  1299,
    1288,  1300,   489,   295,     0,  1286,     0,     0,     0,     0,
       0,     0,     0,  1301,  1302,   492,  1287,     0,     0,     0,
       0,  1303,     0,   493,  1304,     0,  1289,     0,  1288,     0,
     490,     0,   295,  3184,  3185,     0,     0,     0,     0,   274,
    1284,  1285,    33,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,  1289,     0,     0,  1290,     0,     0,
    1291,  3184,  3185,     0,     0,     0,     0,   274,  1284,  1285,
      33,     0,  1283,  1292,     0,     0,   274,  1284,  1285,    33,
       0,   493,     0,   199,     0,  1290,   200,     0,  1291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2509,  1293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1294,     0,  3186,     0,   492,
       0,  1114,     0,     0,     0,     0,     0,     0,     0,     0,
    3636,  1293,     0,     0,     0,     0,     0,  1287,     0,     0,
       0,     0,     0,  1294,     0,  3186,     0,     0,     0,  1288,
       0,     0,   201,     0,  1286,     0,  1295,   274,  1284,  1285,
      33,     0,     0,     0,     0,     0,     0,     0,   202,   203,
       0,     0,     0,     0,     0,  1289,     0,     0,   204,     0,
       0,     0,     0,     0,  1295,   493,     0,     0,     0,  1296,
       0,     0,     0,     0,     0,  1297,     0,     0,     0,     0,
       0,     0,     0,     0,  1298,  1299,  1290,  1300,     0,  1291,
       0,     0,     0,     0,     0,     0,     0,  1296,     0,  1301,
    1302,     0,  1292,  1297,     0,     0,     0,  1303,     0,     0,
    1304,     0,  1298,  1299,     0,  1300,     0,     0,   295,     0,
       0,     0,     0,  1114,     0,  3186,     0,  1301,  1302,     0,
       0,     0,     0,     0,     0,  1303,     0,     0,  1304,     0,
       0,     0,  1293,     0,     0,     0,   295,     0,     0,     0,
       0,  1114,     0,     0,  1294,     0,     0,     0,     0,     0,
    1114,     0,     0,     0,     0,     0,     0,     0,     0,  1287,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1288,     0,  2540,  2541,  2542,  2543,  2544,  2545,     0,
       0,     0,     0,     0,     0,  1295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1296,   205,
       0,     0,     0,     0,  1297,     0,     0,     0,  1290,     0,
       0,  1291,     0,  1298,  1299,     0,  1300,     0,     0,     0,
       0,  1114,     0,     0,  1292,     0,     0,     0,  1301,  1302,
       0,     0,     0,     0,     0,     0,  1303,     0,   206,  1304,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
    2546,     0,     0,     0,     0,     0,     0,   207,   208,   209,
     210,  1287,     0,     0,  1293,     0,     0,     0,     0,     0,
       0,     0,     0,  1288,     0,   211,  1294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1287,
       0,     0,     0,     0,     0,     0,     0,   212,  1287,  1289,
       0,  1288,     0,     0,     0,     0,     0,     0,     0,   213,
    1288,     0,     0,     0,     0,     0,     0,  1295,     0,     0,
     214,     0,     0,     0,     0,     0,     0,  1289,     0,     0,
    3187,     0,     0,  3188,     0,     0,  1289,   215,     0,     0,
       0,     0,     0,     0,     0,     0,  3189,   216,     0,     0,
    1296,     0,     0,     0,     0,  3607,  1297,     0,  3187,     0,
       0,  3188,   217,     0,     0,  1298,  1299,  1290,  1300,     0,
    1291,     0,     0,  1989,  3189,     0,     0,     0,     0,     0,
    1301,  1302,     0,  1292,     0,     0,  3191,     0,  1303,  1287,
       0,  1304,     0,     0,     0,     0,     0,     0,  3192,   295,
       0,  1288,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3608,     0,  3191,     0,     0,     0,     0,     0,
       0,     0,     0,  1293,     0,   219,  3192,  1289,     0,     0,
       0,     0,     0,     0,     0,  1294,     0,  3609,     0,  3193,
     220,     0,     0,     0,     0,     0,  3610,   221,     0,     0,
     222,     0,     0,     0,     0,     0,     0,     0,  3187,     0,
       0,  3188,     0,     0,     0,     0,     0,  3193,     0,     0,
       0,   223,     0,     0,  3189,   224,  1295,     0,  3194,     0,
       0,     0,     0,     0,  3611,     0,     0,  2547,     0,     0,
    3195,     0,  3612,     0,   225,     0,     0,     0,     0,     0,
    2548,     0,  3196,  3197,     0,     0,  3194,     0,     0,  1296,
    3198,     0,   226,  3199,  3191,  1297,     0,     0,  3195,     0,
       0,   295,     0,     0,  1298,  1299,  3192,  1300,     0,     0,
    3196,  3197,     0,     0,     0,     0,     0,     0,  3198,  1301,
    1302,  3199,     0,     0,     0,     0,     0,  1303,     0,   295,
    1304,     0,     0,     0,   227,     0,     0,     0,   295,     0,
       0,     0,     0,  2549,     0,     0,     0,  3193,     0,  2550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3194,     0,  2551,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3196,  3197,  2552,     0,     0,     0,     0,     0,  3198,     0,
       0,  3199,  2553,  2554,     0,     0,     0,     0,  2555,   295,
       0,     0,     0,     0,     0,     0,     0,     0,  2556,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2557,     0,     0,  2558,  2559,     0,     0,     0,  2560,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2561,     0,     0,     0,     0,
       0,     0,     0,     0,  3614,     0,  2562
};

static const short yycheck[] =
{
       3,     4,     5,   998,   190,     8,   107,   396,  1051,   654,
    1144,  1452,    45,   171,  1281,  1282,  1129,  1164,   589,   127,
    1169,  1369,   546,   794,    54,   717,   778,  1362,   261,   262,
    1316,   638,  1318,  2344,  2110,  2346,  1923,    40,  1394,   259,
     260,  1125,  2361,   596,  1126,  2359,   266,   173,    25,    52,
      27,    54,  1140,  1141,  2496,  1143,  2307,  1145,  1146,    92,
     688,   689,    65,     5,  2652,  1888,  1889,   572,    20,    72,
     171,  2056,    27,    76,  2050,    27,    79,    80,  2894,  2895,
    2896,    27,    85,    86,    27,  1296,     5,  1298,  1299,   190,
      26,    27,    27,  2059,    25,     5,    27,  2539,   726,     5,
       5,   729,  1989,   106,   753,     5,    69,   714,  2231,    27,
      25,   739,    27,  2897,     5,   743,   796,     5,   725,   747,
     123,  2428,   814,   126,     8,   147,   754,     5,   131,   237,
     238,   759,    24,   761,    26,     5,  1218,   263,  1251,   767,
     110,   267,   770,   269,    27,   271,   272,   273,    27,   777,
    1232,    27,    27,   110,   280,   118,   784,     5,   284,   285,
      24,    25,    26,   791,   322,    20,  1998,  1999,  2000,  2001,
      25,  2614,    27,   780,   802,     5,   783,    19,   806,  1222,
      27,    24,   810,    26,     5,   792,   149,    27,   816,   192,
     971,   819,    19,    19,     9,    10,    19,    12,    13,    14,
      15,    16,    17,    26,     5,   784,   116,     5,   118,     5,
     120,  1991,     6,    20,  2355,  2356,  2357,    19,    25,  2360,
      27,   322,    24,    25,    26,   326,    25,    26,    27,   129,
     130,   234,    25,    25,    27,    27,     6,   240,    24,    25,
      26,    27,     6,    24,    25,    26,    27,    27,    19,   252,
      24,    25,    26,    27,    45,   258,   259,   260,   261,   262,
     185,     5,   225,   266,   227,    24,    25,    26,    27,  2667,
      19,  2669,   191,    25,     5,    27,    26,     5,    23,    25,
    2421,    27,     5,    19,   690,   198,   213,    93,    94,    95,
      96,    97,  2979,  2243,   135,   136,   438,   198,     5,   284,
     394,    92,   238,    27,   186,   187,   153,   433,    27,     5,
     436,    23,   315,   316,     5,   506,   722,   723,  2535,   389,
     281,  2285,   325,   238,  2288,  1409,   113,   453,   454,   455,
     456,   517,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   138,
    2601,    56,     5,   381,  2430,  2674,   203,     5,   578,   485,
     486,    27,  1509,     5,   490,   222,   492,   478,   774,     5,
     506,     5,     5,  1125,     5,     5,   596,     0,   718,   408,
     343,   507,   508,   509,   510,   593,   349,     5,   514,   343,
      27,   238,     5,   240,   505,   542,    25,     5,    27,     5,
     585,   389,   742,   550,     5,   389,    26,    27,  1451,   669,
     293,   454,    24,    25,    26,    27,   517,  2197,     5,   623,
       5,   296,   580,   306,  2632,   409,     0,     5,   133,   134,
      20,   322,    18,    19,    20,    21,    22,    27,     5,   697,
     403,   440,    16,     5,  2585,   238,   238,   518,   788,   634,
      31,     5,   238,   585,  2595,   526,   664,   238,   798,   663,
       5,   801,   319,   723,   238,   805,     5,   653,     5,   478,
      27,   811,    30,   813,   473,   666,    34,     5,   424,   580,
      18,    19,    20,    21,    22,   300,   238,     5,   506,     5,
     337,     5,  2700,     5,   523,    10,    27,   506,   112,     5,
     485,  1129,   634,   506,  2336,   763,  1186,   478,     5,   415,
    1291,     5,   658,   322,   547,   548,     5,    28,   488,   238,
     399,  3426,     5,   477,   399,   408,   322,     5,     5,   676,
     666,     5,  3437,   561,     5,   322,   539,   282,     5,   542,
       5,    56,   403,   101,   572,     5,   199,   550,   642,  2690,
     108,   771,   653,     5,     5,   625,   789,   790,   663,   406,
       5,     5,     5,   705,   567,     5,   569,   414,     5,    27,
     282,   418,   238,   536,   577,   578,     5,     5,   581,     5,
     444,     5,    29,     5,     5,   818,    27,   292,   821,     5,
       5,     5,     5,   596,     5,   501,   154,   155,   440,   102,
     103,   556,   484,   632,   162,   420,   421,   394,   455,  2826,
    2433,   517,   548,   440,   440,     5,  2867,  2928,   238,   589,
     642,  1249,  1250,  1251,   331,   440,   238,   290,    10,   132,
     133,   134,   589,  2583,   510,   331,   561,   625,   478,   518,
     523,   625,  1048,   518,   474,   606,   440,   433,   666,  2968,
    3434,   438,  1176,  2794,   560,  2619,   539,  1409,  3345,   666,
     573,   476,   608,   444,  1070,   601,   411,   211,   595,   440,
     440,  1250,   573,   676,   521,   399,   440,  3119,   681,   682,
     683,   684,   685,   686,   687,  2572,   586,   690,   691,   692,
     440,   440,   695,   599,   697,  3137,   440,   700,   478,   702,
     423,   672,    23,  2038,   440,  1276,  1277,   238,   711,   440,
    1355,  2059,   440,   560,   433,   603,   600,   632,   636,   722,
     723,  3035,   628,  1063,   615,   603,   518,   658,   663,   732,
     600,   637,  3043,  1413,  3045,   738,   713,   584,  2879,  3182,
    2863,   744,   745,   746,   663,  1425,  2722,   750,   534,   597,
     753,  3065,   755,   756,   664,  2740,   547,  2198,   713,   664,
     763,   713,   672,   766,  1269,  1414,   708,   713,   771,   772,
     713,   774,   593,   673,   666,   778,  2742,  2133,   781,   715,
    3223,   628,   383,   474,   787,  3092,   789,   790,   603,  3096,
     637,   794,   795,   796,   636,   593,   597,   800,   440,  2957,
     803,  2959,   666,   658,  2962,   808,   615,   438,  2581,   636,
     636,  3399,   815,   636,   817,   818,   562,   820,   821,   615,
     823,   824,   436,   666,   630,  3413,   474,   875,   615,  1169,
     623,   672,   444,   434,   391,   293,  3652,  1177,   474,  1179,
     474,   474,   399,   400,   474,   597,   460,  3245,   306,   478,
     394,   658,   293,   440,   669,   440,   474,   344,   416,   658,
     986,   474,   440,   989,   666,   306,   474,   424,   474,   356,
     427,   997,   998,   440,   721,   722,   688,   689,   440,  1268,
     666,   693,   694,   211,   442,   666,   440,   444,   474,  3030,
    3188,  3032,   666,    27,   706,   440,   685,   686,   687,   688,
     689,   440,   433,   440,   719,   720,   518,   666,   695,   696,
     697,     5,   440,   440,   726,   297,   283,   729,   478,   706,
    1151,  1152,   440,   735,   440,   928,   440,   739,   440,   543,
    3241,   743,  3243,  3244,   440,   747,   474,    30,  1545,   751,
     752,    34,   754,   440,     5,   757,   440,   759,   760,   761,
     408,   440,  3394,  2776,   512,   767,  3544,   440,   770,  3208,
    3271,   282,   440,   440,   669,   777,   440,   408,   971,   440,
     374,   403,   784,   440,   440,   440,    25,  1530,    27,   791,
     440,    30,  2357,  1389,    25,  2360,    27,   585,   440,   440,
     802,   548,  1398,  1517,   806,   440,   440,   440,   810,   502,
     440,     5,   374,   440,   816,  2139,   506,   819,  1011,  3328,
    1013,   440,   440,   440,   440,   665,   440,  1423,   440,   440,
     478,   635,   672,  2309,   440,   440,   440,   440,  3169,   440,
     123,    26,    27,   647,   648,   206,   634,   478,  3179,   293,
     408,   655,  2126,  1006,   601,  1048,   604,   591,  1051,    20,
     440,   608,   306,   435,   666,   437,    27,    14,    25,  2407,
      27,   671,   569,  2411,  1067,   523,   394,  1070,    18,    19,
      20,    21,    22,   478,   450,  1415,  1416,  1417,    26,    27,
     624,   539,   523,  3252,   694,   588,  3255,  2373,  2374,  3258,
     411,    25,  1432,    27,   161,   478,  2869,  2870,   539,     5,
    1148,  3259,     8,  2185,   238,   199,  1109,  1155,    25,   636,
      27,  1114,   672,  2893,  2894,  2895,  2896,  2737,   367,   636,
    3439,  3419,  1125,   506,   528,  3266,   684,  3425,   631,   478,
    3428,  3429,  3430,  3431,   692,   306,  1139,  1140,  1141,   478,
    1143,   658,  1145,  1146,   478,    25,   513,    27,  1151,  1152,
      26,    27,  3403,   506,   408,   523,   528,    25,  2271,    27,
    1500,    20,   296,   478,   330,  3414,  3415,    25,    27,    27,
     636,  3532,  3533,   344,    24,  2170,    26,   343,  1518,   473,
      25,  1184,    27,  1186,    26,   552,    25,    20,    27,   238,
     478,   284,  1195,  1426,    27,  1198,  1536,   238,   293,   478,
    1203,    17,    18,    19,    20,    21,    22,  1547,  1428,   636,
    1991,   306,  1993,    25,    25,    27,    27,   505,   506,  1222,
    1223,  3543,  2003,  2004,   478,  3547,    42,   636,  1231,  2010,
    2011,  2012,  2013,   478,    25,   284,    27,   408,   506,    25,
      25,    27,    27,   238,  1247,  1248,   254,   255,   256,   658,
    1358,   422,  3550,  1361,   478,  3553,  3554,  3555,  3556,   635,
     478,  3622,   638,  3624,   632,  3406,    26,   671,  1499,   523,
    1273,   238,   671,  2893,  2894,  2895,  2896,   478,  1281,  1282,
     568,   212,  1440,   214,  3171,   539,   690,   691,  1291,  3600,
     238,   215,  1525,  1526,   693,   694,  3465,   478,    19,   671,
      25,  1304,    27,    24,   238,    26,   710,   330,   239,  1312,
    1530,   477,   405,   408,   478,    20,   528,  1129,   690,   691,
     343,   238,    27,   139,   140,   141,   142,   143,   144,     9,
      10,   478,    12,    13,    14,    15,    16,    17,   710,  1440,
     478,   157,   158,   159,    26,  3643,   212,    25,   214,    27,
      20,   212,   523,   214,  1384,   506,   405,    27,  3499,   478,
    1363,   454,   238,   478,  1367,  1368,  1369,  2653,   539,  2655,
     238,  2657,  2519,   239,  2126,   478,  1379,  1380,  1381,  2714,
     238,  1384,  1385,  1386,  1387,  1388,  1389,   318,   286,    24,
     321,    26,   485,   238,  2742,  1398,    39,    40,    41,   238,
      43,   478,    45,    46,  3184,  3185,  1409,  1410,  3188,  1412,
    1413,  1414,   343,  2194,    25,  2458,    27,    20,  1421,  1422,
    1423,   514,  1425,  1426,    27,  1428,  1429,   238,   523,   711,
     659,   660,   661,   662,  1437,   478,   485,  1249,  1250,  1251,
     448,  1444,  1445,   478,   539,   343,   671,   238,  1451,  1452,
     732,   415,   318,   238,   477,   321,    25,   318,    27,   671,
     321,   478,  2673,   745,  2675,   514,   478,  2159,   693,   694,
    2241,   478,  2079,  3253,  2587,   478,  3256,   343,   690,   691,
     478,   297,   343,   415,   300,   636,   478,  2115,  2168,    25,
     440,    27,   761,  1496,  1497,   478,  1499,   478,   710,   397,
    2613,   770,   286,   401,   428,   478,  1912,   658,  1914,  1915,
     286,   672,  1918,  1919,    20,   666,    28,    29,  1924,   443,
    1523,    27,  1525,  1526,   505,   506,  2307,  1530,  3604,  1532,
     729,  1534,  1535,   478,    24,  2316,    26,   501,  2319,  2320,
    2321,  2322,   505,   506,   743,  3621,   477,   816,   747,   478,
     819,    19,   478,   517,  1557,  2235,    24,    25,    26,   343,
     759,   486,   486,   672,  3184,  3185,   802,   343,  3188,   501,
     806,    26,   497,   497,   810,   415,    26,   817,   685,   477,
     820,   688,   689,   823,    26,   517,  3418,   568,  3420,  3421,
    3422,  3423,    26,   518,   518,  3671,   560,    25,    26,  2005,
     525,   525,    20,    21,   420,   716,   717,   718,   533,   533,
    2238,   477,  3688,   397,   686,   687,   477,   401,   666,   435,
     300,   397,    25,   439,    27,   401,   149,   150,   560,  2153,
     555,   555,    25,  3253,    27,   599,  3256,  3417,   573,  3419,
     157,   158,   159,  2271,   415,  3425,  3426,   478,  3428,  3429,
    3430,  3431,  1885,  1886,    25,   478,    27,  3437,   415,   478,
     476,   501,   415,  1410,   628,  1412,    26,   599,   478,  2803,
     505,   506,   478,   637,  3115,   318,  2758,   517,   321,   478,
     323,   415,  2893,  2894,  2895,  2896,  2835,   468,   504,  2956,
    2957,   478,  2959,   477,    26,  2962,   628,   688,   689,   478,
     343,   477,    25,    26,   385,   637,   522,    26,   632,   478,
     353,   506,  2859,   478,   638,   396,    25,    26,  2800,  2125,
     560,   139,   140,   141,   142,   143,   144,  3075,  2299,    26,
     501,   374,  2412,    26,  2414,    18,    19,    20,    21,    22,
     420,   421,  2082,  2423,   501,    26,   517,  2958,   501,  2960,
      26,  1149,  1150,    26,   397,  1153,  1154,  2097,   401,   599,
     517,   666,   695,   696,   517,   106,   447,   501,  2448,   440,
    3550,   335,   336,  3553,  3554,  3555,  3556,   695,   696,   478,
     461,  3222,   694,   517,  2124,  2732,  2733,   603,   628,   560,
     410,  2131,  3184,  3185,   706,   666,   476,   637,    26,  3419,
     440,  2408,  3582,   560,   478,  3425,  3426,   560,  3428,  3429,
    3430,  3431,   478,   474,     5,   478,  2811,  3437,  2158,   440,
    2601,   440,   440,   735,  2819,  2820,   560,   440,   599,    40,
     518,   478,    20,    20,   477,  3455,   672,  2177,   440,   751,
     752,   478,   599,  2249,   478,   757,   599,  1955,   760,     5,
     478,   506,  2459,   669,   440,   670,    26,   628,   666,    26,
     440,   306,   474,  3643,   410,   599,   637,   109,    30,   550,
      20,   628,  3652,    26,    26,   628,     5,    26,  2659,    26,
     637,  1884,  1885,  1886,   637,    26,    26,    26,  1891,  1892,
      26,   636,   440,  2674,   628,   106,   107,   440,  2024,  2132,
      26,  2508,   440,   637,  2685,   440,   440,    26,  1911,  1912,
     440,  1914,  1915,    20,    26,  1918,  1919,   478,  1921,   666,
    2326,  1924,    26,   603,    26,  2033,    26,   440,     5,   440,
    3550,   672,    26,  3553,  3554,  3555,  3556,   440,   350,   440,
     440,   440,   184,   440,   670,  1948,    18,    19,    20,    21,
       5,   440,   440,  2581,   478,   672,  1959,  3398,   440,  2587,
     171,    26,  3582,   636,   672,   440,    18,    19,    20,    21,
     440,    25,    25,  3184,  3185,    25,    25,  3188,   192,   190,
     440,   440,   196,   167,   440,  2613,   440,   440,  1991,   669,
    1993,   440,  3259,   440,   350,  2215,  2216,  2230,   670,   440,
    2003,  2004,  2005,   440,   246,  2008,   248,  2010,  2011,  2012,
    2013,   440,   666,   440,  2420,    20,    21,   440,   666,     8,
    2023,   478,   264,  3643,   526,   671,  2152,   642,   474,   314,
     272,   507,  3652,   184,   276,     5,   208,   642,   664,   719,
     720,   664,  2045,   468,  2170,   507,   705,  2050,   705,   666,
     376,   223,   224,  2056,   506,  2836,  2059,   658,   666,   301,
     232,  2401,   643,     5,   468,     5,  2029,   139,   140,   141,
     142,   143,   144,   478,  2077,  2415,  2416,  2417,  2418,   184,
    2083,  3124,  2762,   297,   478,   269,  2867,   139,   140,   141,
     142,   143,   144,   277,   266,   246,  2436,   248,   478,   283,
     478,   285,   478,   275,   315,   316,   394,   636,  2111,   625,
       8,   322,   296,   264,    14,   326,     5,  2797,   622,     5,
     705,   272,  2125,  2126,   468,   276,  2129,  2130,   705,  2132,
     478,   478,   304,  3128,   139,   140,   141,   142,   143,   144,
     324,   246,    26,   248,  2147,    26,   973,   113,   138,   976,
     301,   978,   979,   980,   981,   982,   340,   506,   666,   264,
      26,   345,  2502,  2166,  2570,  2168,   478,   272,   478,   636,
     478,   276,   478,   357,   478,   478,   478,   349,   478,   478,
     364,   468,   287,  2964,   478,   506,  2189,    26,  2191,  2192,
       5,  2194,   478,  2599,  2197,  2198,   301,     5,   642,   478,
     672,   478,  3349,   478,   400,   603,   672,   671,  3419,  2615,
     708,  3358,  2215,  2216,  3425,  3426,     5,  3428,  3429,  3430,
    3431,   393,    18,   663,    19,    26,  3437,  2230,  3375,    26,
     201,   432,  2235,  2236,  2237,    25,   636,   669,  2241,   625,
     529,  2869,  2870,     5,   666,   529,  2249,   593,   199,    26,
     593,   448,    26,    25,   371,   593,   478,   440,   440,   672,
     440,  2667,   518,  2669,  2604,   666,  2606,   440,   573,   478,
     672,   478,   478,  2276,   478,   478,   105,     5,   666,   710,
     440,  2284,  2285,  2441,   636,  2288,   636,   666,   478,   663,
     672,     5,  2984,  2985,  2986,   506,  2988,  2989,  2990,  2991,
    2992,  2993,   593,  2115,  2307,  2997,   517,     5,     5,   626,
       5,   666,   530,  2316,   672,   478,  2319,  2320,  2321,  2322,
    2323,     5,     8,  2326,    26,  3438,   671,  2330,  2331,   513,
      26,  2334,   367,   113,   518,   266,   375,     5,     5,  3550,
    2441,   525,  3553,  3554,  3555,  3556,   478,   440,   478,   409,
     672,   643,  2355,  2356,  2357,    14,   597,  2360,  2361,  2362,
     593,     5,  2365,   547,   706,    26,   147,   478,   552,   580,
     666,   672,   478,   593,  3521,     5,   671,   474,   685,    26,
       5,   671,  2893,  2894,  2895,  2896,     5,     5,   417,  2795,
     672,  2394,   440,  2396,  2397,   440,  2399,  2400,   440,   665,
    2403,   381,  3082,    26,  2407,   474,     5,   508,  2411,  2412,
     508,  2414,   478,  2893,  2894,  2895,  2896,  2420,  2421,   478,
    2423,  2424,   478,   666,  2427,  2428,  2238,   478,  2768,     5,
    3110,  2771,  3643,     8,   478,   478,   666,   478,   478,   506,
     666,  3652,   653,     5,   623,  2448,   600,   375,    25,   394,
     394,   666,  2455,   225,   478,  2458,   394,   409,   473,  2271,
     506,     5,     5,   697,  2467,    26,     5,     5,  2471,   506,
     681,   682,   683,    25,   685,    26,   642,    14,    14,   478,
     600,  3262,   663,  3264,   642,  3632,     5,  3530,     5,     7,
     440,   702,    26,  2496,    26,  2835,    26,    26,   672,   478,
       6,   440,   716,   717,   440,   440,   440,   440,   495,   316,
     440,   440,     5,    26,    26,   672,    26,  2520,   666,  3607,
    3608,  3609,  3610,  3611,  3612,    26,    26,   738,   666,   666,
     440,    20,     5,   744,   613,   746,   322,     5,     5,   750,
       5,   440,   753,   714,     8,   756,   593,     5,   618,   440,
     666,   478,     5,   518,   672,   766,     5,   593,   672,   259,
     670,   440,   478,    26,   672,   478,     5,  2570,     5,   672,
     781,    25,   494,   672,   670,    25,   787,   672,    25,   665,
     352,    25,  2585,   794,   795,   796,   358,   359,   360,   800,
    2593,  2594,  2595,    25,   344,  2598,  2599,   808,  2601,  2632,
     814,    26,    26,    26,    26,    26,    26,   440,   380,   440,
     824,  2614,  2615,   824,    26,  2618,  2619,     5,   440,   440,
     478,   515,  3403,     5,   478,   597,   440,  3272,  3623,  2849,
       8,  2851,  1259,   288,    26,  2793,  3417,   474,    25,   488,
     440,   394,   190,    20,   600,     5,   478,     5,  2834,    14,
    3056,   478,   478,   478,   478,   478,  2659,   259,   478,    26,
      26,   440,    26,    26,  2667,   440,  2669,  2700,     5,  2672,
     489,  2674,  3352,  3184,  3185,    26,   506,  3188,    26,   440,
    2806,   440,  2685,    26,   440,  2811,   478,  2690,  2691,  2692,
    3370,    26,  2793,  2819,  2820,    26,    26,   423,   615,    26,
     440,  2704,   288,   440,  3184,  3185,   478,   440,  3188,   478,
     440,   394,   506,   593,   486,   289,  3759,   489,   488,  2722,
     478,   440,    14,   440,   440,   497,     7,   440,   287,   287,
      26,   440,   440,  2834,   441,    18,    19,  2740,    26,  2742,
     672,    24,    25,    26,    27,   666,   478,   440,   622,   440,
     474,   478,  2755,   636,    25,   440,   289,   971,   440,  2762,
     532,   440,   440,  3103,   440,  3546,    26,   506,     5,  2581,
      26,    26,     5,   666,   440,  2587,   666,    26,   440,    26,
     474,   666,   440,  2814,  2787,   474,  2789,  2755,  2791,  3681,
    2492,  2794,  2795,  1537,  2797,   567,    31,   997,  2178,  3139,
      29,  2613,   547,  2424,  2787,  3586,  2430,   354,   114,  2812,
    3438,  2814,  2815,  2816,   586,   587,   118,   207,   345,   657,
    2028,   225,  2029,   212,   355,   597,  2829,   384,   599,   112,
     602,   536,  3512,  2836,     9,   555,   567,  1051,   383,  3245,
    1051,  3230,  1280,    18,    19,    20,  2849,   569,  2851,    24,
      25,    26,    27,  3671,  2082,   989,  1067,   800,  2861,  2862,
     415,  1256,  2282,  1884,  2867,  2417,  2289,  3100,  2131,   641,
    3149,  2838,  1887,  2205,  3726,  2516,  2879,  2420,  2225,  1428,
    3113,  3366,    16,    92,    40,  3293,    40,    22,  2183,   756,
    2893,  2894,  2895,  2896,  2897,  2898,   930,  2189,  1109,  1548,
     326,   673,  1892,  1497,  2907,  2192,  3290,  1223,  3419,  2912,
    3474,   781,  1422,  1495,  3425,  3426,  3697,  3428,  3429,  3430,
    3431,  1013,  3688,  3484,  2836,  1412,  3437,  3024,  1139,  1140,
    1141,  1518,  1143,  3022,  1145,  1146,  3094,   112,  2158,  3419,
    1151,  1152,  2945,  2946,   452,  3425,  3426,  3006,  3428,  3429,
    3430,  3431,  2703,  2956,  2957,   238,  2959,  3437,  3080,  2962,
    3346,  2964,  3344,  3337,  2062,  2968,  3072,  2045,  2365,  2411,
    2581,  3697,  3266,  1926,  1926,  1186,  2260,    25,  2600,  3181,
    3029,  3499,  3063,  2326,  2248,  2945,  2672,  1198,  2946,  3256,
    3582,  3051,  2725,  3094,  3309,  1911,  2704,     8,  3746,  1252,
    2692,  2691,  3128,  3183,  2004,  3008,  2880,  3264,  1222,  2003,
    1906,  1222,  1223,  3540,  3354,  2594,  1248,  3178,  3021,  3417,
    1231,  3436,  1879,  3425,  2023,  1114,  2795,  3030,  3031,  3032,
    1437,  1445,  2793,  2441,   545,  1427,  1247,  1248,    -1,  3550,
      -1,    -1,  3553,  3554,  3555,  3556,    -1,    -1,    -1,  3389,
      -1,    -1,    -1,  3056,    -1,    -1,    -1,  2869,  2870,    -1,
      -1,    -1,    -1,   238,    -1,  3068,  3069,  1281,  1282,  3072,
    3550,    -1,  3075,  3553,  3554,  3555,  3556,  1291,    -1,  3082,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3092,
      -1,    -1,  3095,  3096,    -1,    -1,    -1,  3100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3110,    -1,    -1,
    3113,    -1,  3115,   121,   122,    -1,   124,   125,   126,    -1,
      -1,  3124,    -1,   406,    -1,    -1,    -1,    -1,  3348,    -1,
      -1,    -1,  3643,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,  3652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3163,   444,    -1,  3643,    -1,    -1,  3169,   342,    -1,    -1,
      -1,    -1,  3652,    -1,    -1,  3178,  3179,   225,  3181,  3182,
      -1,  3184,  3185,    -1,    -1,  3188,    -1,    -1,    -1,    -1,
      -1,    -1,   475,    -1,    -1,   478,  3199,    -1,    -1,  1410,
      -1,  1412,  1413,  1414,    -1,    -1,    -1,    -1,   491,    -1,
    1421,  1422,    -1,    -1,  1425,    -1,   224,    -1,  1429,  3222,
    3223,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,  1440,
      -1,   406,    -1,    -1,    -1,    -1,    -1,  1451,    -1,    -1,
    1451,  1452,  3245,   418,    -1,    -1,    -1,   530,   531,    -1,
    3253,    -1,    -1,  3256,    -1,    -1,  3259,    -1,   266,  3262,
     543,  3264,    -1,  3266,    -1,    18,    19,   275,    -1,   444,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,  3618,    -1,
      -1,    -1,    -1,    -1,    -1,  1496,  1497,  3290,  1499,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,    -1,    -1,
     475,   584,    -1,   478,   352,    -1,    -1,    -1,    -1,    -1,
     358,   359,   360,    -1,    -1,   490,   491,    -1,    -1,  1946,
    1947,  1532,    -1,    -1,    -1,  3328,  1953,    -1,    -1,    -1,
      -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     623,   349,    -1,   518,    -1,  3348,  1557,    -1,    -1,  3352,
    3536,    -1,   635,    -1,   107,    -1,   531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   647,   648,   119,  3370,   543,    -1,
      -1,    -1,   655,    -1,    -1,   658,    -1,    -1,    -1,    -1,
      -1,  3721,    -1,   666,    -1,   393,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,    -1,  3398,    -1,    -1,    -1,    -1,
    3403,    -1,    -1,  3406,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,    -1,    -1,  3417,    -1,  3419,    -1,    -1,    -1,
      -1,    -1,  3425,  3426,    -1,  3428,  3429,  3430,  3431,    -1,
      -1,  3434,    -1,  3436,  3437,  3536,  3439,    -1,   486,    -1,
     448,   489,   617,    -1,    -1,    -1,    -1,    -1,   623,   497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   632,   633,    -1,
     635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3474,   647,   648,    -1,    -1,  3479,    -1,  3481,    -1,
     655,    -1,    -1,   658,   532,   238,    -1,   240,    -1,    -1,
      -1,   666,    -1,    -1,    -1,    -1,  3499,  3623,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   567,
      -1,    -1,  3334,    -1,    -1,    -1,    -1,  3530,    -1,    -1,
      -1,    -1,  3344,    -1,  2161,    -1,    -1,  3540,   586,   587,
      -1,    -1,    -1,  3546,    -1,    -1,    -1,  3550,    -1,   597,
    3553,  3554,  3555,  3556,   602,  3558,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3572,
      -1,    -1,    -1,    -1,  2201,    -1,    -1,    -1,    -1,  3582,
      -1,    -1,    -1,  3586,   337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   641,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3607,  3608,  3609,  3610,  3611,  3612,
      -1,    -1,    -1,    -1,    -1,    -1,  3619,    -1,    -1,   372,
      -1,    -1,    -1,    -1,    -1,   673,  3438,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3652,
      -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   418,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,    -1,    -1,  1892,    -1,
    1891,  1892,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,  3697,    -1,  3699,    -1,    24,    25,
      26,    27,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1948,   491,    -1,
      -1,  3744,  3745,  3746,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3759,    -1,  3761,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    43,    -1,    45,    46,    -1,  1991,    -1,  1993,
      -1,   107,   535,    -1,    -1,    -1,   112,    -1,    -1,  2003,
    2004,    -1,    -1,   119,    -1,    -1,  2010,  2011,  2012,  2013,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   584,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,  2486,
    2487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2497,    -1,    -1,    42,    -1,   628,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   637,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2521,  2522,  2523,  2524,  2525,  2526,
      -1,    -1,    -1,    -1,  2531,  2532,  2533,  2534,    -1,    -1,
      -1,  2538,   238,    -1,   240,    -1,    -1,     9,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,  2147,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,  2159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,   722,
     139,   140,   141,   142,   143,   144,    -1,    -1,  2189,    -1,
    2194,    -1,    -1,    -1,    -1,    -1,    -1,  2198,   157,   158,
     159,    -1,    -1,  2620,  2621,    -1,    -1,    -1,    -1,    -1,
    2627,  2628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   337,    -1,    -1,    -1,   107,   342,    -1,    -1,    -1,
     112,    -1,    -1,    -1,  2235,  2236,  2237,   119,    -1,    -1,
    2241,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   372,   318,    -1,    -1,
     321,    -1,   323,    -1,   146,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2276,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     406,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,  2307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2316,   374,    -1,  2319,  2320,  2321,  2322,    -1,
     436,    -1,    -1,    -1,    -1,   441,    -1,  2331,   444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,   297,   455,
     401,   300,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,   238,  2361,   240,   475,
    2777,  2778,   478,    -1,    -1,   481,    -1,    -1,    -1,  2786,
      -1,    -1,    -1,    -1,   490,   491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   297,  2823,  2824,   300,    -1,
      -1,  2412,    -1,  2414,   530,   531,   477,    -1,    -1,   535,
      -1,    -1,  2423,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      -1,    -1,    -1,  2850,    -1,  2852,    -1,    -1,   554,    -1,
    2441,    -1,    -1,    -1,   560,    -1,    -1,  2448,    -1,    -1,
      -1,    -1,    -1,    -1,  2458,   337,    -1,  2458,    -1,    -1,
     342,   420,    -1,    -1,    -1,    -1,  2467,    -1,   584,    -1,
    2471,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     372,    -1,    -1,    -1,    -1,  2496,  2913,  2914,    -1,    -1,
    2917,  2918,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   628,    -1,    -1,    -1,    -1,   476,    -1,   635,
      -1,   637,    -1,    -1,   406,    -1,    -1,    -1,   420,    -1,
      -1,   647,   648,    -1,    -1,    -1,   418,    -1,    -1,   655,
      -1,    -1,    -1,   435,    -1,   504,    -1,   439,    -1,    -1,
     666,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,   441,
      -1,    -1,   444,   522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,   460,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,   475,    -1,  3012,   478,  2601,    -1,   481,
      -1,    -1,    -1,    -1,    -1,   721,   722,    -1,   490,   491,
      -1,    -1,   504,    -1,    -1,    -1,    -1,  2618,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,   603,    -1,    -1,    -1,   530,   531,
      -1,    -1,    -1,   535,    -1,  2659,    -1,    -1,    -1,    -1,
      -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,  2672,    -1,
    2674,    -1,   554,    -1,    -1,    -1,  3093,    -1,   560,    -1,
    3097,  2685,    16,    17,    18,    19,    20,    21,    22,    -1,
    2691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3116,
      -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    42,    -1,
     669,   603,    -1,    -1,     5,     6,     7,     8,  3135,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,  2737,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,    -1,    -1,   628,    -1,    -1,    -1,
      -1,    42,    -1,   635,    -1,   637,   157,   158,   159,    -1,
      -1,  2762,    -1,    -1,    -1,   647,   648,    -1,    -1,    -1,
      -1,    -1,    -1,   655,    -1,    -1,    -1,   669,    -1,    -1,
      -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2793,    -1,    -1,    -1,  2797,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,  2812,    -1,  2814,    -1,  2816,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,  2829,    -1,
      -1,    -1,  2836,  2834,    -1,    -1,    -1,    -1,    -1,   721,
     722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
    2861,  2862,    -1,  2867,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,  2893,
    2894,  2895,  2896,    -1,    -1,    -1,   297,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,  2907,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2945,  2946,    42,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,  2956,  2957,    -1,  2959,    -1,    -1,  2962,    -1,
    2964,    -1,    -1,   297,  2968,    -1,   300,    -1,    -1,    -1,
    3387,    -1,    -1,  3390,    -1,    -1,    -1,    -1,    -1,    -1,
    2984,  2985,  2986,    -1,  2988,  2989,  2990,  2991,  2992,  2993,
      -1,    -1,    -1,  2997,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   297,  3008,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
    3021,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,   435,    -1,    -1,    -1,   439,    -1,
     139,   140,   141,   142,   143,   144,   139,   140,   141,   142,
     143,   144,    42,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,
      -1,  3082,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,
      -1,    -1,    -1,  3094,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   435,    -1,   504,    -1,   439,    -1,    -1,    -1,  3110,
      -1,    -1,    -1,    -1,  3115,    -1,    -1,  3534,    -1,    -1,
    3124,   522,    -1,  3124,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,   435,    -1,    -1,    -1,   439,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   318,    -1,
      -1,   321,    -1,   323,    -1,    -1,    -1,   157,   158,   159,
     504,  3588,  3589,    -1,  3591,    -1,  3593,  3594,    -1,    -1,
    3184,  3185,    -1,   343,  3188,   476,    -1,    -1,   522,    -1,
      -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,   297,    -1,
      -1,   300,   603,    -1,   297,    -1,    -1,   300,     9,    -1,
      -1,    -1,    -1,   504,   374,    -1,    -1,    18,    19,    -1,
      -1,  3222,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,
      -1,   401,  3659,    -1,  3661,    -1,    -1,    -1,    -1,  3253,
      -1,    -1,  3256,    -1,    -1,  3259,     9,    -1,  3262,    -1,
    3264,    -1,    -1,    -1,    -1,    18,    19,    -1,   669,   603,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,  3695,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3290,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3715,  3716,
      -1,    -1,  3719,    -1,    -1,  3722,   107,   297,    -1,    -1,
     300,   112,   603,    -1,    -1,    -1,    -1,   477,   119,    -1,
      -1,   420,    -1,    -1,  3328,    -1,    -1,   420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   669,   435,    -1,    -1,    -1,
     439,   440,   435,    -1,    -1,   146,   439,    -1,    -1,    -1,
      -1,  3352,    -1,    -1,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,  3370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   669,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   146,    -1,    -1,    -1,  3398,    -1,  3403,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,   504,    -1,  3417,    -1,  3419,    -1,    -1,    -1,    -1,
      -1,  3425,  3426,   522,  3428,  3429,  3430,  3431,    -1,   522,
     420,    -1,    -1,  3437,    -1,  3439,    -1,   238,    -1,   240,
      -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,
      -1,  3455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3474,    -1,    -1,    -1,    -1,  3479,    -1,
    3481,    -1,    -1,    -1,    -1,   238,   476,   240,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,   603,    24,    25,    26,    27,    -1,
     603,  3512,    -1,    -1,   504,    -1,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,  3530,    -1,    -1,  3530,
      -1,    -1,   522,    -1,    -1,  3536,   337,    -1,    -1,    -1,
      -1,   342,  3546,    -1,    -1,    -1,  3550,    -1,    -1,  3553,
    3554,  3555,  3556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     669,   372,    -1,    -1,    -1,    -1,   669,    -1,  3582,    -1,
      -1,    -1,  3586,    -1,   337,    -1,    -1,    -1,   107,   342,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   406,  3607,  3608,  3609,  3610,
    3611,  3612,    -1,   603,    -1,    -1,    -1,   418,    -1,   372,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,  3643,
     441,   180,    -1,   444,    -1,    -1,    -1,    -1,  3652,   188,
      42,    -1,    -1,   406,   455,    -1,    -1,    -1,   197,   460,
      -1,   200,    -1,    -1,    -1,   418,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,   475,    -1,    -1,   478,    -1,   669,
     481,    -1,    -1,   436,     5,    -1,    -1,    -1,   441,   490,
     491,   444,    -1,  3697,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   455,    -1,   243,    -1,    -1,   460,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   470,    -1,   238,
      -1,   240,   475,    -1,    -1,   478,    -1,    -1,   481,   530,
     531,    -1,    -1,    -1,   535,    -1,    -1,   490,   491,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   554,    -1,  3759,    -1,    -1,  3759,   560,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,   307,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,
      -1,    -1,   535,   584,    -1,    -1,    -1,    -1,    -1,    -1,
     543,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,
     339,   554,   341,   556,    -1,    -1,    -1,   560,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,   337,    -1,
      -1,    -1,    -1,   342,    -1,    -1,    -1,   628,    -1,    -1,
      -1,   584,    -1,    -1,   635,    -1,   637,    -1,    -1,    -1,
     379,    -1,    -1,    -1,    -1,    -1,   647,   648,   387,    -1,
      -1,    -1,    -1,   372,   655,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,
      -1,    -1,   635,    -1,   637,   424,    -1,   406,    -1,    -1,
      -1,    -1,    -1,    -1,   647,   648,    -1,   111,    -1,   418,
      -1,    -1,   655,    -1,    -1,   297,    -1,    -1,   300,    -1,
     449,    -1,    -1,   666,    -1,    -1,    -1,   436,    -1,    -1,
     721,   722,   441,    -1,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    -1,   475,    -1,   497,   478,
      -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,   721,   722,
      -1,   490,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,   531,    -1,    -1,    -1,   535,    -1,    33,    -1,
      -1,    -1,    -1,    -1,   543,    -1,   347,    -1,   420,    -1,
      -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,    53,    -1,
      -1,   560,    -1,   435,    -1,   366,   367,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   595,   596,   597,    -1,
      -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,   608,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   476,   406,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   418,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,   429,   628,
      -1,    -1,   504,    -1,    -1,    -1,   635,    -1,   637,    -1,
      -1,    -1,   137,   138,    -1,   446,    -1,    -1,   647,   648,
     522,   146,    -1,   347,    -1,   456,   655,    -1,   153,   154,
      -1,    -1,   157,   158,   159,   160,    -1,   666,   163,   164,
     471,    -1,    -1,   367,   368,   369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     511,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   721,   722,   418,    -1,    -1,    -1,    -1,    -1,
     225,   603,    -1,   534,    -1,   429,   231,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,   240,    -1,    -1,   549,    -1,
     245,    -1,   446,    -1,    -1,   556,    -1,    -1,   559,    -1,
      -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   271,   471,    -1,   580,
      -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,   519,    -1,   322,    -1,    -1,
      -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,   338,    -1,    -1,    -1,    -1,    -1,   344,
      -1,    -1,   347,   348,    -1,   549,    -1,   352,    -1,    -1,
      -1,    -1,    -1,   358,   359,   559,    -1,    -1,    -1,    -1,
     365,   366,   367,    -1,    -1,   370,   371,   372,    -1,    -1,
      -1,   376,    -1,    -1,    -1,   380,   580,   382,    -1,    -1,
     584,    -1,    -1,    -1,   389,   390,   391,   392,    -1,   394,
     395,    -1,    -1,    -1,   399,   400,    -1,   402,   403,   404,
     405,   406,   407,   408,    -1,    -1,    -1,    -1,   612,   414,
     415,   416,    -1,   418,   419,    -1,    -1,   621,   423,   424,
     425,   426,   427,   428,   429,   430,    -1,   432,    -1,    -1,
      -1,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,    -1,   474,
     475,    -1,    -1,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,    -1,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,    -1,
      -1,   506,   507,   508,   509,   510,   511,   512,   513,   514,
      -1,   516,   517,   518,   519,    -1,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,    -1,   558,   559,   560,   561,   562,   563,    -1,
      -1,   566,   567,    -1,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
      -1,    -1,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,    -1,    -1,    -1,    -1,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,
      -1,    -1,    -1,    -1,   308,    -1,    -1,   692,    -1,    -1,
      -1,    -1,   697,    -1,    -1,    -1,   701,    -1,    -1,   704,
     705,   706,   707,    -1,    -1,   710,   711,    -1,   713,   714,
     715,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    -1,   347,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,   366,   367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,   446,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,    -1,    -1,   471,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,    -1,   157,   158,   159,   160,    -1,    -1,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
     534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,
      -1,   225,   556,    -1,    -1,   559,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,
     584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,   603,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,   338,    -1,    -1,    -1,    -1,    -1,
     344,    -1,    -1,   347,   348,    -1,    -1,    -1,   352,    -1,
      -1,    -1,    -1,    -1,   358,   359,    -1,    -1,    -1,    -1,
      -1,   365,   366,   367,    -1,    -1,   370,   371,   372,    -1,
      -1,    -1,   376,    -1,    -1,    -1,   380,    -1,   382,    -1,
      -1,    -1,    -1,    -1,    -1,   389,   390,   391,   392,    -1,
     394,   395,    -1,    -1,    -1,   399,   400,    -1,   402,   403,
     404,   405,   406,   407,   408,    -1,    -1,    -1,    -1,    -1,
     414,   415,   416,    -1,   418,   419,    -1,    -1,    -1,   423,
     424,   425,   426,   427,   428,   429,   430,    -1,   432,    -1,
      -1,    -1,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,    -1,
     474,   475,    -1,    -1,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,    -1,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
      -1,    -1,   506,   507,   508,   509,   510,   511,   512,   513,
     514,    -1,   516,   517,   518,   519,    -1,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,    -1,   558,   559,   560,   561,   562,   563,
      -1,    -1,   566,   567,    -1,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,    -1,    -1,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,    23,    -1,    -1,    -1,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
      -1,    39,    40,    41,    -1,    43,    -1,    45,    46,    -1,
     684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   692,    -1,
      -1,    -1,    -1,   697,    -1,    -1,    -1,   701,    -1,    -1,
     704,   705,   706,   707,    -1,    -1,   710,   711,    -1,   713,
     714,   715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,   214,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,   276,    -1,
      -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,   286,   287,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     318,    -1,    -1,   321,    -1,   323,    -1,    -1,    -1,    -1,
      -1,    -1,   330,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    -1,    36,    37,    38,   343,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,   353,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,
      -1,    -1,    -1,   401,    -1,    99,   100,    -1,    -1,    -1,
     104,   409,   410,   411,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,   168,   169,   170,    -1,    -1,   477,
      -1,    -1,    -1,    -1,   178,   179,    -1,   181,   182,   183,
     488,    -1,    -1,    -1,    -1,   189,    -1,    -1,   192,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,   202,    -1,
     204,   205,    -1,   207,    -1,   209,   210,    -1,    -1,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,    -1,    -1,
     528,   225,   226,   227,    -1,   229,    -1,    -1,    -1,   233,
      -1,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,   342,
     244,    -1,    -1,   247,    -1,   249,    -1,   251,    -1,   253,
      -1,    -1,    -1,   257,   258,    -1,   260,   261,   262,    -1,
      -1,   265,    -1,   267,   268,    -1,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,    -1,    -1,    -1,    -1,
      -1,   589,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,
     294,   295,    -1,    -1,   298,   299,    -1,    -1,   302,   303,
      -1,    -1,    -1,   406,    -1,    -1,    -1,   311,   312,   313,
      -1,   315,    -1,    -1,    -1,   418,    -1,   625,    -1,    -1,
      -1,   325,   326,   327,    -1,   329,    -1,    -1,    -1,   333,
     334,    -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,    -1,
      -1,   444,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     354,   355,   356,    -1,    -1,    -1,    -1,    -1,   362,   363,
      -1,    -1,    -1,   671,    -1,    -1,   370,    -1,    -1,   373,
      -1,    -1,   475,   377,   378,   478,    -1,   685,   686,   687,
     688,   689,   690,   691,   388,   693,   694,   490,   491,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,   710,    -1,    -1,    -1,    -1,    -1,    -1,   413,
      -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,   531,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,   443,
     543,    -1,    -1,    -1,    -1,   449,    -1,   451,   452,    -1,
      -1,    -1,    -1,    -1,    -1,   459,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,   617,    -1,    -1,    -1,    -1,    -1,
     623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   632,
     633,    -1,   635,    -1,    -1,    -1,   540,   541,    -1,    -1,
      -1,   545,    -1,    -1,   647,   648,    -1,    -1,    -1,    -1,
      -1,    -1,   655,   557,    -1,   658,    -1,    -1,    -1,   563,
     564,   565,   566,   666,    -1,    -1,   570,    -1,    -1,    -1,
     574,    -1,    -1,    -1,    -1,    -1,    -1,   581,   582,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,
     594,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   605,    -1,   607,    -1,    -1,   610,    -1,    -1,    -1,
      -1,    -1,   616,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   642,    -1,
      -1,   645,    -1,    -1,    -1,    -1,   650,    -1,    -1,   653,
     654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   668,    -1,    -1,    -1,     6,     7,
       8,   675,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   698,   699,   700,   701,   702,   703,
     704,    -1,    -1,   707,    42,   709,    -1,   711,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   297,    -1,    -1,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   435,    -1,    -1,    -1,   439,   440,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,   297,
     504,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,   522,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,   297,
      -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    42,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,
      -1,    -1,   297,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,   435,    -1,    -1,
      -1,   439,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   420,    -1,    -1,   669,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,   435,   476,    -1,
      -1,   439,   440,    -1,    -1,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,   382,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,   504,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,   522,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     435,    -1,    -1,    -1,   439,   440,   504,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   522,    -1,    -1,    -1,    -1,    -1,
      -1,   297,   458,    -1,   300,    -1,    -1,    -1,   464,    -1,
      -1,   476,    -1,    42,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,   603,    -1,    -1,    -1,   504,
     297,    -1,    -1,   300,    -1,    -1,    -1,   503,    -1,    -1,
      -1,    42,    -1,    -1,     6,     7,     8,   522,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   527,    -1,   297,    -1,   603,   300,    -1,    -1,    -1,
      -1,   537,   538,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,
      -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   575,
      -1,    -1,   578,   579,   420,    -1,    -1,   583,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,   435,
      -1,   669,    -1,   439,   440,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,
     476,    -1,   439,   440,   640,    -1,    -1,   139,   140,   141,
     142,   143,   144,    -1,    -1,   651,   420,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,   157,   158,   159,   504,    -1,
      -1,   435,    -1,    -1,    -1,   439,   440,    -1,    -1,   476,
      -1,    -1,    -1,     6,     7,     8,   522,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,   297,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     504,    -1,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   297,   603,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   297,   603,    -1,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    42,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   669,   157,   158,   159,    -1,    -1,   603,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     439,    -1,   669,    -1,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,   669,    -1,   476,   439,    -1,
      -1,    -1,   139,   140,   141,   142,   143,   144,    -1,    -1,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,
     157,   158,   159,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   435,    -1,   476,    -1,   439,    -1,    -1,
      -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,   489,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   504,   297,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,
      -1,   522,    42,    -1,    -1,    -1,    -1,   489,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     522,    42,   297,    -1,   603,   300,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     297,    -1,   603,   300,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    42,    -1,    -1,   139,
     140,   141,   142,   143,   144,    -1,    -1,   420,    -1,    -1,
     669,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,   603,   435,    -1,    -1,    -1,   439,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   669,   112,
      -1,    -1,    -1,    -1,    42,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,   476,    -1,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
     435,    -1,    -1,    -1,   439,    -1,    -1,   669,    -1,    -1,
      -1,   504,    -1,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,   522,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,   435,    -1,
      -1,   476,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   504,
      -1,   139,   140,   141,   142,   143,   144,   297,    -1,   476,
     300,    -1,    -1,    -1,    -1,    -1,    -1,   522,    42,   157,
     158,   159,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,   300,
      18,    19,    20,    -1,   238,   522,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,
      -1,   297,    -1,    -1,   300,    -1,   669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,
     420,    -1,    -1,   157,   158,   159,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   435,    -1,    -1,    -1,   439,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,
      -1,    -1,   300,    -1,   669,    -1,    -1,    -1,    -1,   420,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,   476,    -1,   439,    -1,
      -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   669,    -1,    -1,   418,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,   504,    24,    25,    26,    27,    -1,
      -1,    -1,   406,    -1,   420,   476,    -1,    -1,    -1,    -1,
      -1,   444,   522,    -1,   418,    -1,    -1,    -1,   489,   435,
      -1,    -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,
     444,    -1,   475,    -1,    -1,   478,    -1,    -1,    -1,    -1,
     238,   522,    -1,   297,    -1,    -1,   300,   490,   491,    -1,
     476,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   475,    -1,    -1,   478,    -1,    -1,   435,   238,    -1,
      -1,   439,    -1,   112,    -1,    -1,    -1,   491,   504,    -1,
      -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,   531,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,
     543,    -1,    -1,    -1,   518,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,   543,
      -1,    18,    19,    20,    -1,    -1,   504,    24,    25,    26,
      27,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,
      -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,
     584,    -1,    -1,    -1,   617,    -1,    -1,   603,    -1,    -1,
     623,   435,    -1,    -1,    -1,   439,    -1,    -1,   669,   632,
     633,    -1,   635,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   617,   647,   648,    -1,    -1,   406,   623,
      -1,    -1,   655,    -1,    -1,   658,    -1,    -1,   632,   633,
     418,   635,   476,   666,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   647,   648,   603,   406,    -1,    -1,    -1,
      -1,   655,    -1,   669,   658,    -1,   444,    -1,   418,    -1,
     504,    -1,   666,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,   444,    -1,    -1,   475,    -1,    -1,
     478,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    20,   491,    -1,    -1,    24,    25,    26,    27,
      -1,   669,    -1,    32,    -1,   475,    35,    -1,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   530,   531,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   543,    -1,   112,    -1,   603,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     530,   531,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
      -1,    -1,    -1,   543,    -1,   112,    -1,    -1,    -1,   418,
      -1,    -1,   111,    -1,   112,    -1,   584,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,   584,   669,    -1,    -1,    -1,   617,
      -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   632,   633,   475,   635,    -1,   478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,   647,
     648,    -1,   491,   623,    -1,    -1,    -1,   655,    -1,    -1,
     658,    -1,   632,   633,    -1,   635,    -1,    -1,   666,    -1,
      -1,    -1,    -1,   238,    -1,   112,    -1,   647,   648,    -1,
      -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,   658,    -1,
      -1,    -1,   531,    -1,    -1,    -1,   666,    -1,    -1,    -1,
      -1,   238,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,   308,
      -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,   475,    -1,
      -1,   478,    -1,   632,   633,    -1,   635,    -1,    -1,    -1,
      -1,   238,    -1,    -1,   491,    -1,    -1,    -1,   647,   648,
      -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,   347,   658,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,   366,   367,   368,
     369,   406,    -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,    -1,   384,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,   406,   444,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,
     418,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,
     429,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
     475,    -1,    -1,   478,    -1,    -1,   444,   446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,   456,    -1,    -1,
     617,    -1,    -1,    -1,    -1,   250,   623,    -1,   475,    -1,
      -1,   478,   471,    -1,    -1,   632,   633,   475,   635,    -1,
     478,    -1,    -1,   518,   491,    -1,    -1,    -1,    -1,    -1,
     647,   648,    -1,   491,    -1,    -1,   531,    -1,   655,   406,
      -1,   658,    -1,    -1,    -1,    -1,    -1,    -1,   543,   666,
      -1,   418,   511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   307,    -1,   531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   531,    -1,   534,   543,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   543,    -1,   332,    -1,   584,
     549,    -1,    -1,    -1,    -1,    -1,   341,   556,    -1,    -1,
     559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,   478,    -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,
      -1,   580,    -1,    -1,   491,   584,   584,    -1,   623,    -1,
      -1,    -1,    -1,    -1,   379,    -1,    -1,   382,    -1,    -1,
     635,    -1,   387,    -1,   603,    -1,    -1,    -1,    -1,    -1,
     395,    -1,   647,   648,    -1,    -1,   623,    -1,    -1,   617,
     655,    -1,   621,   658,   531,   623,    -1,    -1,   635,    -1,
      -1,   666,    -1,    -1,   632,   633,   543,   635,    -1,    -1,
     647,   648,    -1,    -1,    -1,    -1,    -1,    -1,   655,   647,
     648,   658,    -1,    -1,    -1,    -1,    -1,   655,    -1,   666,
     658,    -1,    -1,    -1,   663,    -1,    -1,    -1,   666,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,   584,    -1,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   623,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     647,   648,   527,    -1,    -1,    -1,    -1,    -1,   655,    -1,
      -1,   658,   537,   538,    -1,    -1,    -1,    -1,   543,   666,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,    -1,    -1,   578,   579,    -1,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   649,    -1,   651
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   123,   284,   405,   454,   485,   514,   782,
     810,   811,   867,  1041,  1097,  1099,  1100,  1101,  1106,  1108,
    1121,  1122,  1123,  1124,  1125,  1567,    28,    29,   783,   784,
     785,   786,   787,    27,  1005,  1582,  1005,    25,  1005,  1472,
    1126,   812,  1472,   811,     0,  1098,  1101,  1124,    31,   785,
     787,   868,   658,    25,   238,   809,   810,   992,  1005,  1010,
    1106,  1121,  1127,  1162,  1163,  1164,  1165,  1166,  1170,   403,
     814,   815,   816,   817,   820,   821,   101,   108,   154,   155,
     162,   416,   442,   512,   604,   684,   692,   782,   788,   964,
    1040,  1102,  1103,  1105,  1109,  1110,  1116,  1128,  1149,  1281,
    1291,  1567,   663,  1005,  1165,   290,   505,   506,  1171,    20,
    1005,  1169,   666,   815,     5,   813,   403,  1005,     5,   839,
     841,   842,  1005,  1292,  1005,  1005,  1282,  1117,  1005,  1005,
    1105,  1111,   308,   347,   366,   367,   406,   418,   429,   446,
     456,   471,   511,   534,   549,   556,   559,   580,   584,   603,
     621,   869,   870,   871,   874,    25,  1162,  1168,    18,    19,
      26,   107,   119,   146,   240,   337,   372,   406,   418,   455,
     470,   478,   491,   535,   560,   584,   628,   637,   721,   722,
     732,   734,   929,   934,   945,   947,  1005,  1162,  1172,  1173,
     506,    14,   866,   817,   569,  1268,   818,   815,   820,    32,
      35,   111,   127,   128,   137,   308,   347,   366,   367,   368,
     369,   384,   406,   418,   429,   446,   456,   471,   511,   534,
     549,   556,   559,   580,   584,   603,   621,   663,   824,   833,
     844,   849,  1005,   478,   161,  1005,   809,   965,  1150,  1005,
     876,   367,   822,   478,   852,   854,   855,   853,   862,   863,
     478,   478,   875,   506,   478,   815,   850,   473,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   732,   478,
     806,     9,    18,    19,    24,    25,    26,   112,   342,   436,
     441,   444,   460,   475,   478,   481,   490,   531,   543,   554,
     584,   635,   647,   648,   655,   666,   903,   911,   912,   913,
     914,   915,   916,   917,   945,   946,   948,  1011,  1162,  1271,
    1464,   478,   478,   478,   478,   478,   478,    18,    19,    20,
      21,    22,   733,    26,   478,   568,     5,   474,  1172,    25,
      26,  1005,  1011,    19,    25,    26,   819,  1011,   716,   717,
     718,   823,   846,   835,   847,   822,   478,   478,   478,   836,
     852,   853,   478,   478,   834,   506,   845,   478,   850,   815,
     843,   478,    26,  1005,   478,  1118,   809,   809,   478,  1005,
     478,   505,   828,    26,   672,   415,   501,   517,   560,   599,
     628,   637,   856,   672,   415,   501,   517,   560,   599,   628,
     637,   864,    26,    26,   877,   878,   879,   880,  1005,    26,
     831,   832,    26,   666,   713,   953,   996,  1005,   996,   996,
     953,   953,   903,    25,    26,    19,    24,    25,    26,   949,
     950,   951,   952,    25,   954,   996,   997,   903,   440,   903,
     903,   903,   903,   573,  1288,   478,   478,   903,   415,   501,
     517,   560,   599,   628,   637,  1467,  1468,   478,   903,   903,
     478,   478,   918,   478,   478,   478,   478,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    42,   139,   140,   141,   142,   143,
     144,   157,   158,   159,   297,   300,   420,   435,   439,   476,
     504,   522,   603,   669,   805,   904,   919,   921,   922,   923,
     924,   925,   926,   927,    26,  1011,   468,   937,   935,   941,
     939,  1162,  1162,   732,   930,  1005,  1173,   506,   474,    26,
     826,   478,   848,   815,   848,   828,    26,    26,    26,   815,
      26,    26,   814,   831,   848,    26,   666,   106,   840,  1293,
     440,   478,  1283,  1583,  1584,  1585,  1586,  1587,   966,  1151,
    1112,   666,    26,   440,   857,   858,   478,   859,   864,   865,
     859,   478,   860,     5,   440,     5,   440,     5,   331,     5,
     869,   474,     5,     5,   440,   815,   851,   478,     5,   440,
     506,   666,   440,   440,   440,   440,   440,   440,    19,   440,
     636,   950,    19,    26,   636,   440,     5,   440,   440,     5,
     807,   903,   518,  1488,   903,   478,   672,    20,   440,  1488,
      20,  1271,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   903,   478,   903,   903,   478,  1162,
     903,   903,   903,   903,   440,     5,   530,   762,   763,   764,
     903,   478,  1172,   506,   670,    26,   666,    26,   440,   440,
       5,   440,   306,     5,   440,     5,   440,   331,   474,     5,
     440,   851,  1005,  1178,  1179,  1181,  1129,  1178,   410,  1584,
    1268,    36,    37,    38,    44,    47,    54,    55,    99,   100,
     104,   114,   115,   117,   131,   148,   151,   152,   166,   168,
     169,   170,   178,   179,   181,   182,   183,   189,   192,   194,
     195,   196,   202,   204,   205,   207,   209,   210,   213,   216,
     217,   218,   219,   220,   221,   225,   226,   227,   229,   233,
     235,   236,   241,   244,   247,   249,   251,   253,   257,   258,
     260,   261,   262,   265,   267,   268,   270,   278,   279,   291,
     294,   295,   298,   299,   302,   303,   311,   312,   313,   315,
     325,   326,   327,   329,   333,   334,   338,   346,   354,   355,
     356,   362,   363,   370,   373,   377,   378,   388,   405,   413,
     419,   430,   443,   449,   451,   452,   459,   498,   509,   516,
     540,   541,   545,   557,   563,   564,   565,   566,   570,   574,
     581,   582,   592,   594,   605,   607,   610,   616,   642,   645,
     650,   653,   654,   668,   675,   698,   699,   700,   701,   702,
     703,   704,   707,   709,   711,   725,   726,   727,   728,   745,
     767,   781,   782,   788,   789,   808,   882,   883,   884,   885,
     896,   897,   898,   899,   900,   901,   902,   955,   959,   990,
    1012,  1014,  1017,  1018,  1019,  1020,  1033,  1042,  1066,  1067,
    1069,  1073,  1088,  1089,  1093,  1094,  1095,  1096,  1104,  1119,
    1132,  1143,  1144,  1145,  1156,  1159,  1193,  1196,  1198,  1204,
    1205,  1208,  1211,  1214,  1216,  1218,  1221,  1228,  1233,  1237,
    1238,  1239,  1251,  1252,  1255,  1261,  1263,  1264,  1289,  1304,
    1305,  1306,  1307,  1308,  1320,  1326,  1327,  1347,  1350,  1379,
    1381,  1473,  1474,  1505,  1506,  1513,  1528,  1552,  1567,  1568,
    1573,  1574,  1576,  1580,  1581,  1588,   782,  1107,   671,   694,
    1152,  1153,  1178,    20,   440,   473,   829,   856,    26,   861,
      26,    26,    26,   878,   880,   872,   832,    26,  1005,   996,
     732,    20,   713,  1005,   943,  1468,    26,   943,    26,    26,
     636,    24,    26,   853,   944,   997,   854,   440,   408,   523,
     632,  1496,   440,   440,    26,  1468,   440,   440,   440,   440,
     440,   440,   440,   489,   489,   489,   928,  1488,   489,   928,
    1488,   938,   936,   942,   940,    26,   931,     5,   932,   474,
    1172,   839,   440,    20,   829,    26,   478,    26,    26,   825,
      26,   666,   440,     5,  1178,   440,  1162,  1162,  1162,  1005,
      25,  1162,  1215,  1005,    25,  1005,  1457,   399,  1006,  1007,
    1582,  1006,    25,  1005,  1456,  1005,  1005,  1235,  1000,  1006,
    1000,  1005,  1578,  1457,  1005,    26,   729,  1162,  1311,  1000,
    1235,   928,    26,  1011,  1276,  1277,  1276,   903,   910,  1349,
    1456,  1456,   905,   928,  1006,  1514,  1514,   886,  1235,  1000,
    1309,  1162,  1002,  1006,   910,  1514,  1162,  1235,  1162,  1348,
    1514,    25,   632,  1146,  1147,  1162,  1000,  1000,  1146,  1001,
    1006,  1005,  1147,  1000,  1514,  1000,  1002,  1457,  1162,  1191,
    1192,   998,  1006,  1002,   424,   608,   996,  1068,  1005,   790,
    1456,  1003,  1006,    25,   238,  1005,  1380,  1556,  1558,  1559,
    1560,  1561,  1563,   928,  1191,   672,   928,  1006,  1217,   960,
      57,    58,    59,    60,   180,   188,   197,   200,   243,   250,
     307,   332,   339,   341,   351,   379,   387,   424,   449,   486,
     497,   595,   596,   597,   608,   711,  1082,  1212,  1213,  1162,
    1183,  1184,   909,   910,  1227,   953,   953,   999,  1006,   928,
    1215,  1290,  1162,  1267,    25,  1162,  1508,  1262,   910,  1569,
     153,   203,   240,   337,   414,   455,   521,   746,   934,  1005,
    1162,  1299,   769,   910,   998,   636,  1005,  1013,  1133,   910,
     998,    26,  1162,  1090,   998,   910,  1529,   910,  1276,  1005,
    1015,  1016,  1002,  1015,   953,  1002,  1015,   953,  1021,  1015,
      25,    26,   433,   534,  1011,  1071,  1162,  1180,  1182,   113,
     322,   394,   438,   615,   695,   696,   697,   706,   736,  1023,
    1025,  1027,  1029,  1031,  1157,  1158,  1161,   385,   396,   447,
     461,   550,  1382,   686,   687,   968,   969,   970,  1005,  1154,
     693,  1153,   440,   350,   440,   440,   440,   440,   670,     5,
     440,   440,   474,   478,   672,    19,   440,   440,    26,   636,
     672,    18,    19,    20,    25,    26,   112,   406,   418,   444,
     475,   478,   491,   531,   543,   584,   617,   623,   632,   633,
     635,   647,   648,   655,   658,  1005,  1011,  1463,  1465,  1495,
    1497,  1498,  1500,  1501,  1502,  1524,  1525,  1526,  1527,  1557,
    1558,  1562,  1288,   440,  1288,  1288,  1288,  1288,  1288,  1288,
      25,    25,    25,   903,   920,   440,    25,   920,   440,   440,
     440,   440,   440,   440,   440,   764,   762,   474,   350,   440,
     815,   837,   838,   440,   440,   670,   440,  1005,  1294,  1181,
     440,  1284,   102,   103,   132,   133,   134,   502,   588,   631,
    1328,  1329,  1330,  1333,  1336,  1339,  1340,  1341,  1344,   666,
     636,   658,   149,   150,   478,   666,   636,   658,     8,   671,
     474,  1456,   526,  1236,  1180,   157,   158,   159,   642,   530,
     906,   907,   910,  1162,  1187,  1456,   735,   736,   889,   314,
     135,   136,   672,   507,     5,   665,   672,   664,   664,  1194,
     642,   468,     5,   603,  1043,   507,   705,  1571,   705,   433,
     792,  1162,   593,   664,  1199,  1200,  1201,   666,    25,  1559,
     506,  1564,   376,  1378,   658,   666,   908,   910,   603,  1556,
     908,     8,   600,   999,    26,   548,   601,   715,   991,  1162,
     991,   991,   991,    25,   225,   352,   358,   359,   360,   380,
     486,   489,   497,   532,   567,   586,   587,   597,   602,   641,
     673,  1086,  1087,   991,   991,   643,  1083,   736,  1083,  1083,
     992,   992,  1083,  1083,   736,     5,   468,     5,   383,   434,
       5,   735,   129,   130,   586,   673,  1074,   708,  1572,   909,
     659,   660,   661,   662,  1266,  1268,   910,  1257,  1258,  1259,
    1269,  1270,   910,   478,   478,   478,   478,    25,   765,  1005,
     478,  1508,   394,   478,   568,   636,   625,   770,   777,   768,
    1005,    25,  1148,  1162,  1253,     8,  1256,    14,  1005,  1167,
    1174,  1175,  1177,  1185,  1186,  1229,   211,   394,   591,   624,
       5,     6,     7,     8,     9,    10,    12,    13,    14,    18,
      19,    20,    21,    22,    23,    33,    53,   110,   119,   137,
     138,   146,   153,   154,   157,   158,   159,   160,   163,   164,
     203,   225,   231,   238,   240,   245,   271,   309,   322,   328,
     337,   338,   344,   347,   348,   352,   358,   359,   365,   366,
     367,   370,   371,   372,   376,   380,   382,   389,   390,   391,
     392,   394,   395,   399,   400,   402,   403,   404,   405,   406,
     407,   408,   414,   415,   416,   418,   419,   423,   424,   425,
     426,   427,   428,   429,   430,   432,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   474,   475,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   516,
     517,   518,   519,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   558,
     559,   560,   561,   562,   563,   566,   567,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   684,   692,   697,   701,
     704,   705,   706,   707,   710,   711,   713,   714,   715,  1530,
    1531,  1532,  1534,   622,     5,   705,   705,   908,  1180,  1187,
    1070,   468,     5,   199,  1048,   478,  1162,   908,   478,    26,
      26,   113,  1160,    25,  1162,  1512,  1512,  1006,  1362,  1217,
     999,   167,   269,   277,   283,   285,   296,   324,   340,   345,
     357,   364,   513,   518,   525,   547,   552,  1351,  1352,  1360,
    1369,  1370,  1376,  1377,  1383,  1384,  1394,  1414,  1418,  1484,
    1485,  1515,  1516,  1519,  1520,  1536,   971,   972,   138,   967,
     978,   979,   970,  1155,  1583,  1113,   506,   869,   832,   666,
    1005,   415,   501,   517,   560,   599,   628,   637,  1469,    26,
     943,   943,   636,    24,    26,   857,  1501,  1501,   478,   478,
     415,   501,   517,   560,   599,   628,   637,  1466,  1470,   518,
    1500,   478,   478,   478,   478,  1495,  1495,  1495,   478,   478,
     478,   478,  1005,   478,     5,   593,  1423,  1428,   663,  1005,
      18,    19,    20,    21,   139,   140,   141,   142,   143,   144,
    1522,  1470,  1470,   468,     5,   440,   440,   933,   506,     5,
     440,   839,   809,  1130,   809,   293,   306,   408,   478,   523,
     539,  1398,  1399,  1404,  1406,   478,  1005,  1345,  1346,    26,
     478,  1005,  1325,  1338,  1406,  1408,   478,  1005,  1335,   478,
    1325,  1331,     5,  1005,    25,  1005,  1005,    25,  1008,  1165,
    1005,    25,  1005,  1005,  1005,  1579,  1456,   642,   478,   478,
     889,  1456,     5,   672,   478,  1556,    25,  1010,  1234,  1234,
    1508,  1146,   910,   910,   910,   993,   994,   478,  1162,  1192,
    1044,  1045,  1046,  1456,   672,  1508,   953,  1572,  1068,  1162,
     791,   671,   910,   400,  1203,   603,  1202,  1560,   732,  1565,
    1566,  1005,    20,  1561,     5,  1553,   663,  1209,   116,   118,
     120,   664,   672,   881,  1180,  1183,   961,    18,    19,   478,
    1084,  1086,  1213,  1162,  1184,   992,   910,   394,   642,    26,
      26,   735,   201,  1265,   432,  1303,  1268,  1259,     5,   664,
    1260,  1570,  1005,    25,   953,   953,   636,   997,   669,  1162,
     750,  1005,  1005,   910,   389,   773,   777,   625,   771,   779,
      23,   282,  1135,  1139,   529,   928,   529,  1254,   910,   505,
    1171,   666,     5,  1091,   593,  1230,  1162,  1533,  1535,   237,
    1531,  1034,  1016,   953,   953,  1026,  1027,  1048,  1048,    39,
      40,    41,    43,    45,    46,   318,   321,   323,   343,   353,
     374,   397,   401,   477,  1047,  1049,  1050,  1078,  1162,  1182,
     593,   737,    26,   448,  1032,   371,  1507,  1507,   186,   187,
     484,   593,  1005,  1415,  1416,  1458,  1456,  1456,  1456,  1353,
    1456,  1456,  1005,  1517,   215,   428,   443,   486,   497,   518,
     525,   533,   555,   632,   638,  1385,  1387,  1388,  1389,  1496,
    1456,  1361,  1385,  1387,  1583,  1583,   433,   980,  1162,   688,
     689,   973,   974,   975,   528,   671,   690,   691,   710,   983,
     984,  1583,   809,    26,   830,    20,  1005,   440,   478,   440,
      24,    26,    25,    26,    25,    26,   672,  1496,   440,   444,
    1500,  1523,  1562,   408,   523,   632,  1447,  1500,  1503,  1447,
    1447,  1447,  1447,   666,  1503,  1498,   562,  1424,  1425,  1426,
    1456,   573,  1422,  1429,   381,   561,   572,  1371,  1491,  1005,
    1500,  1500,  1500,  1500,   672,   478,   672,  1557,   903,   440,
     830,   838,  1295,   809,  1285,   478,   478,   478,  1342,  1406,
     478,   478,   105,  1343,  1345,     5,  1337,  1338,   111,   347,
     367,   368,   369,   406,   418,   429,   446,   456,   471,   519,
     549,   559,   580,   584,   612,   621,  1448,  1449,  1450,  1452,
    1334,  1335,  1331,  1332,   710,  1329,   666,   636,   440,   666,
     636,   593,  1577,   478,   730,   731,  1005,  1312,   928,   906,
    1005,  1310,   663,  1206,   672,     5,     5,     5,   626,   910,
       5,   666,   530,   672,   671,   212,   214,   318,   321,   793,
     796,   797,  1078,   794,   795,  1005,   478,  1006,   695,   696,
    1207,     5,   474,   910,  1456,  1554,  1555,  1556,   623,   663,
    1210,  1005,  1005,   994,   995,   556,   953,   889,     8,     8,
     963,    26,    26,  1085,  1086,  1162,   367,  1222,   113,   903,
    1268,   266,  1270,  1276,  1583,     5,     5,   440,   440,   766,
    1005,   440,  1508,   762,   478,   478,   778,   774,   409,   772,
     910,   389,   775,   779,   643,  1080,  1140,  1136,   411,  1134,
    1135,   908,   672,  1168,    20,  1005,  1176,  1186,    14,   530,
    1231,  1232,  1500,  1562,  1183,  1583,  1028,  1029,   597,  1004,
     593,  1061,  1060,  1059,  1058,  1063,  1062,   996,  1064,   996,
    1065,  1057,  1056,  1054,  1053,  1079,   374,  1050,  1055,   953,
      48,    49,    50,    51,    52,    53,   145,   382,   395,   458,
     464,   503,   527,   537,   538,   543,   553,   575,   578,   579,
     583,   640,   651,   738,   739,  1076,  1077,     5,    26,  1508,
     296,  1162,   518,  1489,  1490,  1508,  1217,  1483,  1485,   147,
     147,   642,  1215,  1417,  1418,   478,  1395,   198,  1429,  1456,
     222,   319,  1521,   666,   672,   478,  1390,  1390,   593,   671,
       5,  1486,  1537,   391,   400,   424,   427,   444,   548,   601,
     608,   999,  1363,  1368,   672,   671,   982,  1162,     5,   593,
     976,   977,   685,   975,   981,  1005,   981,   985,   986,   981,
     374,   984,  1114,   474,    26,   943,   440,    19,   440,   636,
     440,    19,   440,   636,   415,   501,   517,   560,   599,   628,
     637,  1471,  1497,     5,  1470,     5,   440,     5,  1500,     5,
     440,  1500,  1500,  1500,  1500,  1005,   440,   478,  1426,     5,
    1005,  1462,     9,   342,   478,   490,  1432,  1433,  1434,  1435,
    1436,  1440,  1444,  1446,  1500,   417,  1420,  1430,  1005,  1492,
     665,  1447,   381,  1471,    26,  1471,   474,   508,  1278,  1298,
    1131,   508,  1240,  1272,   658,  1005,  1401,  1403,  1456,  1460,
    1461,  1405,  1460,  1405,     5,   440,  1343,  1405,  1432,  1005,
     440,  1346,     5,   440,   478,   478,   478,  1470,  1470,   478,
     478,   478,   478,   478,   254,   255,   256,   448,  1407,  1409,
       5,   440,     5,   440,  1005,  1005,    25,  1005,  1005,    25,
    1005,   910,  1005,  1322,  1323,     5,  1324,  1325,   928,  1120,
     666,  1324,   623,  1508,  1508,   910,   910,   993,   556,   910,
    1575,     5,  1045,    20,  1460,  1508,   794,   802,   801,   803,
    1005,  1009,   804,  1009,   239,   797,   800,     5,  1048,   666,
     910,     8,  1566,   506,   666,     5,  1508,   623,  1005,  1180,
     928,   600,  1366,     5,   440,  1162,     5,    26,  1162,   375,
      25,  1300,   394,   394,   506,   666,   394,   478,   751,   755,
     748,  1583,  1583,   780,   776,   772,  1081,    25,  1004,  1141,
    1162,  1583,   910,   473,   506,   928,     5,  1035,  1030,  1031,
      26,   735,  1005,  1583,  1583,  1583,  1583,  1583,  1583,     5,
    1051,     5,  1052,  1583,  1583,  1583,  1583,  1084,  1583,  1004,
      25,    14,    14,     5,   440,    26,  1456,  1496,  1477,   642,
     642,  1352,  1482,  1483,  1418,  1396,  1460,   663,   999,   478,
    1356,  1005,  1518,  1517,  1391,  1460,   510,  1392,  1393,  1458,
    1456,  1389,  1497,    93,    94,    95,    96,    97,   630,  1540,
     910,   910,   600,  1364,   999,  1392,  1456,     5,  1162,   981,
    1583,  1583,     5,   988,   989,  1583,  1583,   987,  1107,   873,
     440,    26,    26,    26,    26,   478,  1428,  1470,   672,  1470,
    1470,   440,  1500,   440,   440,   440,   440,  1425,  1427,  1425,
    1435,  1495,  1432,  1500,  1495,     6,     7,     9,    10,    12,
      13,    14,    15,    16,    17,   300,   420,   421,   476,   603,
     669,   719,   720,  1443,  1445,  1421,  1499,  1500,   495,  1419,
    1431,   316,  1321,    26,  1372,  1373,  1374,  1460,  1489,  1492,
     440,   827,   121,   122,   124,   125,   126,   224,   232,   266,
     275,   304,   305,   349,   393,   448,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,  1275,  1279,   185,   561,
    1280,  1296,  1107,   208,   223,   224,   232,   266,   275,   304,
     349,   393,  1273,  1274,  1286,  1280,  1461,   506,  1459,   440,
       5,   666,     5,   440,   440,  1406,   440,   440,  1338,    26,
    1453,  1453,    26,   672,   478,   672,    26,  1454,    26,    26,
    1454,  1454,    25,  1463,   206,   306,   344,   408,   422,   523,
     539,  1400,  1410,  1411,  1412,  1413,  1335,  1331,   666,   666,
     585,   634,     5,   440,   731,     5,   440,   908,   440,    20,
     440,  1508,     5,   910,   613,   322,   740,   741,   910,  1048,
    1583,  1583,     5,   798,   506,   666,     5,   799,  1583,   795,
     593,    20,  1005,     5,  1005,  1197,  1565,    20,  1460,  1555,
       8,  1508,   438,   705,   908,  1367,   962,  1086,   714,  1220,
     903,     5,   762,  1162,   747,   729,  1005,  1162,   753,   440,
     762,   762,  1583,  1583,  1084,  1138,    25,  1142,  1162,   618,
     958,  1172,   530,   909,  1092,  1232,   110,   589,  1036,  1022,
    1023,   666,   996,  1583,   996,  1583,   735,    26,  1162,    26,
    1162,   739,   440,   478,  1509,  1497,  1483,  1483,  1475,     5,
     440,   518,  1494,  1357,  1460,   526,  1354,  1494,   672,     5,
     440,     5,   593,  1487,    18,    19,   112,   475,   478,   491,
     530,   531,   543,   584,   623,   635,   647,   648,   655,   658,
    1005,  1463,  1495,  1524,  1526,  1545,  1546,  1547,  1548,  1549,
    1550,  1562,  1545,  1545,  1545,  1460,  1542,  1544,  1541,  1542,
    1543,  1538,  1365,   672,  1162,  1005,  1583,  1583,  1583,  1583,
     670,    19,   440,   440,   636,    19,   440,   440,   636,    26,
     440,   672,  1471,   672,   672,     5,   440,   440,  1433,  1434,
    1438,  1501,  1438,   478,  1495,  1438,   478,  1495,  1438,    10,
     297,   435,   437,  1500,     5,  1432,     5,   585,   634,  1375,
    1321,   672,   670,  1276,  1276,  1276,    25,  1276,  1276,  1276,
    1276,  1276,  1276,    25,    25,  1276,  1279,  1162,  1188,  1189,
     665,   494,  1241,  1583,    25,    25,    26,    26,    26,    26,
      26,    25,  1162,  1274,  1241,    26,  1400,  1460,    20,  1005,
    1460,  1343,   440,   440,     5,   440,  1471,    26,  1471,     5,
    1451,     5,   440,   440,   440,  1451,  1402,  1456,   478,  1412,
    1343,  1005,  1005,  1323,   669,   723,  1317,  1318,  1319,  1325,
      56,   133,   134,   292,   669,  1313,  1314,  1315,   515,   888,
    1313,     5,   423,  1508,     5,   478,   440,   597,  1075,  1009,
    1583,   732,    20,  1005,  1009,  1583,   953,   910,   474,  1508,
       8,   953,  1183,  1583,    26,  1004,    25,  1301,  1180,   474,
     762,   752,   756,   440,  1583,  1004,   910,   956,   474,  1038,
    1037,   488,  1024,  1025,    20,  1005,  1510,  1511,   600,  1493,
    1478,  1476,  1460,  1496,   190,  1397,     5,   440,  1355,  1518,
    1460,  1393,  1392,  1493,  1548,  1548,  1547,   478,   478,   478,
     478,   478,   478,   478,  1005,   478,     5,   440,    18,    19,
      20,    21,  1522,   440,     5,   440,     5,    14,   198,   573,
    1539,  1183,  1392,   259,  1115,   869,    26,    26,    26,    26,
     440,  1471,  1471,  1471,  1425,   489,  1437,  1437,  1441,  1442,
    1463,  1562,  1437,  1441,  1437,  1438,  1500,  1499,  1373,  1471,
     839,   585,   634,  1190,     5,  1188,   109,   184,   246,   248,
     264,   272,   276,   301,  1242,  1243,  1297,  1115,  1287,     5,
     474,  1459,    26,   440,    26,  1455,   440,    26,   440,   478,
    1432,  1316,  1582,    26,  1319,    26,    26,  1316,  1321,  1315,
     996,   735,   423,  1508,   910,   742,   615,  1195,    26,   735,
     474,  1075,   440,  1508,   288,   735,   440,   440,   478,   754,
     394,   760,   440,   749,  1137,  1583,   506,   910,  1583,  1004,
       5,   440,  1183,  1428,  1497,  1460,   478,  1428,   440,  1523,
    1447,  1547,  1551,  1447,  1447,  1447,  1447,   506,   666,  1551,
    1546,  1547,  1547,  1547,  1547,  1542,    14,  1543,  1546,   999,
    1432,   191,   663,  1386,    26,   440,   440,   440,   440,  1439,
    1463,  1504,     5,   440,   440,  1437,     7,  1189,  1244,  1245,
    1162,  1247,  1162,  1246,  1248,  1243,   287,   287,    26,   440,
     672,   440,  1403,   440,   887,  1508,   441,   250,   307,   332,
     341,   379,   387,   479,   649,   739,   743,   744,   478,   666,
     735,  1219,  1302,   757,   440,  1180,   760,   760,  1583,   957,
    1172,   622,  1072,  1511,  1491,  1428,   530,  1358,  1359,  1500,
    1491,   440,  1547,     5,   440,  1547,  1547,  1547,  1547,    26,
    1005,   440,   478,  1005,   636,  1442,  1500,  1583,  1583,  1249,
    1583,  1250,  1583,  1583,   474,  1471,   440,   286,   397,   401,
     890,   891,   892,  1078,   991,   991,   991,   991,   991,   991,
      25,     5,   440,   910,    20,  1005,  1078,  1223,  1224,  1225,
     760,   762,   760,   289,   474,  1039,   735,     5,   440,   335,
     336,  1479,   440,  1547,   440,   440,   440,   440,     5,   474,
     506,  1545,    26,  1583,  1583,   894,   893,   286,   892,   895,
     744,     5,  1226,   330,  1225,   758,  1583,  1359,    25,  1005,
    1480,  1481,    26,    26,   440,   440,   636,  1583,  1583,  1583,
     910,  1583,   440,  1036,   666,   666,     5,   474,     5,   474,
      26,   440,   759,  1005,  1005,  1481,    26,   440,   211,   394,
     761,   666,   474,  1180,  1005
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
#line 996 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 999 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1003 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1009 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1014 "fgl.yacc"
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
#line 1026 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1031 "fgl.yacc"
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
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1055 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1056 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1058 "fgl.yacc"
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
#line 1069 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1075 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1076 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1077 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1078 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1084 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1096 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1099 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1102 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1102 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1109 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1110 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1116 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1117 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1118 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1131 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1132 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1139 "fgl.yacc"
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
#line 1150 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1154 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1155 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1159 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1165 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1167 "fgl.yacc"
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
#line 1178 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1180 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1182 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1184 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1188 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1190 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1251 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1255 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1259 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1266 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1269 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1273 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1277 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1284 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1290 "fgl.yacc"
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
#line 1299 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1303 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1308 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1312 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1320 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1324 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1328 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1330 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1336 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1341 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1344 "fgl.yacc"
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
#line 1360 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1367 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1371 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1375 "fgl.yacc"
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
#line 1397 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1397 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1401 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1402 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1403 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1408 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1411 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1417 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1420 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1429 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1433 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1439 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1442 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1457 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1467 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1473 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1482 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1495 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1498 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1500 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1506 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1508 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1513 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1518 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1524 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1528 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1543 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1546 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1549 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1552 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1555 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1558 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1580 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1589 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1599 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 138:
#line 1613 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 139:
#line 1618 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 140:
#line 1621 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 141:
#line 1630 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 142:
#line 1636 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 147:
#line 1651 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 148:
#line 1655 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 149:
#line 1660 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 152:
#line 1670 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 153:
#line 1670 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 154:
#line 1671 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 155:
#line 1671 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 156:
#line 1672 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 157:
#line 1672 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 158:
#line 1673 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 159:
#line 1673 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 160:
#line 1674 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 161:
#line 1674 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 162:
#line 1682 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1686 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1692 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1696 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 166:
#line 1711 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 167:
#line 1714 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 168:
#line 1717 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 169:
#line 1720 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 170:
#line 1723 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 171:
#line 1726 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 172:
#line 1735 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 173:
#line 1743 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1748 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 175:
#line 1761 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 176:
#line 1765 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 177:
#line 1780 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 178:
#line 1781 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 181:
#line 1789 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 182:
#line 1789 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 187:
#line 1798 "fgl.yacc"
    {in_define=1;}
    break;

  case 188:
#line 1798 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 189:
#line 1807 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1808 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 191:
#line 1809 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1812 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 194:
#line 1817 "fgl.yacc"
    { }
    break;

  case 195:
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

  case 199:
#line 1834 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 200:
#line 1838 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 205:
#line 1853 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1854 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 207:
#line 1855 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 208:
#line 1856 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 209:
#line 1861 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 211:
#line 1867 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 213:
#line 1876 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 214:
#line 1880 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 220:
#line 1896 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 221:
#line 1898 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 222:
#line 1899 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 224:
#line 1906 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 225:
#line 1906 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 226:
#line 1907 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 227:
#line 1908 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 228:
#line 1911 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 229:
#line 1913 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 231:
#line 1923 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 236:
#line 1938 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 237:
#line 1938 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 241:
#line 1944 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1945 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 243:
#line 1946 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1947 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 245:
#line 1948 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 246:
#line 1949 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 247:
#line 1950 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 248:
#line 1951 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 249:
#line 1952 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 250:
#line 1953 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 251:
#line 1956 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 252:
#line 1957 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1958 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 254:
#line 1959 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 255:
#line 1963 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1968 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 257:
#line 1973 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1977 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1980 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 260:
#line 1984 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 262:
#line 1985 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 264:
#line 1986 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 266:
#line 1987 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 267:
#line 1988 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1989 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 269:
#line 1990 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1991 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 271:
#line 1992 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 272:
#line 1995 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 273:
#line 1996 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 274:
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

  case 277:
#line 2032 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 278:
#line 2036 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2038 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 280:
#line 2040 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 281:
#line 2042 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 282:
#line 2047 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 283:
#line 2051 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 284:
#line 2051 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 285:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 286:
#line 2056 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 287:
#line 2057 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 288:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 289:
#line 2059 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 290:
#line 2060 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 291:
#line 2062 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 292:
#line 2067 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 293:
#line 2067 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 294:
#line 2070 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 295:
#line 2072 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 296:
#line 2078 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 297:
#line 2080 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 298:
#line 2086 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 299:
#line 2094 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 300:
#line 2094 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 301:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 302:
#line 2098 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 303:
#line 2099 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 304:
#line 2100 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 305:
#line 2101 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 306:
#line 2102 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 307:
#line 2104 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 311:
#line 2125 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 315:
#line 2134 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 316:
#line 2136 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 317:
#line 2138 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 318:
#line 2140 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 319:
#line 2141 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 320:
#line 2142 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 321:
#line 2143 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 322:
#line 2144 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2149 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2156 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 325:
#line 2161 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2163 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2165 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 328:
#line 2166 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 329:
#line 2167 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 330:
#line 2168 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 331:
#line 2169 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 332:
#line 2170 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 333:
#line 2171 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 334:
#line 2174 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 335:
#line 2176 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 336:
#line 2182 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 337:
#line 2190 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2198 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 340:
#line 2202 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 341:
#line 2210 "fgl.yacc"
    {dim_push_record();}
    break;

  case 342:
#line 2211 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 343:
#line 2212 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 344:
#line 2213 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 350:
#line 2232 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 351:
#line 2244 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 352:
#line 2248 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 353:
#line 2251 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 354:
#line 2254 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 355:
#line 2255 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 356:
#line 2256 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 357:
#line 2257 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 358:
#line 2258 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 359:
#line 2264 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 360:
#line 2271 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 361:
#line 2276 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 362:
#line 2281 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 363:
#line 2286 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 364:
#line 2290 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 365:
#line 2299 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 366:
#line 2301 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 367:
#line 2306 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 373:
#line 2318 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 374:
#line 2322 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 375:
#line 2325 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 376:
#line 2329 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 377:
#line 2332 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 378:
#line 2336 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 379:
#line 2343 "fgl.yacc"
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

  case 380:
#line 2361 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 381:
#line 2367 "fgl.yacc"
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

  case 382:
#line 2391 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 383:
#line 2394 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 384:
#line 2409 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 385:
#line 2411 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 386:
#line 2413 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 387:
#line 2415 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 388:
#line 2417 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 389:
#line 2419 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 390:
#line 2420 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 391:
#line 2427 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 392:
#line 2429 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 393:
#line 2433 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 394:
#line 2435 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 395:
#line 2437 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 396:
#line 2439 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 397:
#line 2441 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 398:
#line 2443 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 399:
#line 2445 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 400:
#line 2451 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 401:
#line 2465 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 402:
#line 2468 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 407:
#line 2485 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 410:
#line 2491 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 411:
#line 2495 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 412:
#line 2500 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 416:
#line 2510 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 417:
#line 2511 "fgl.yacc"
    {inc_counter();}
    break;

  case 423:
#line 2517 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 424:
#line 2524 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 425:
#line 2524 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 427:
#line 2529 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 428:
#line 2533 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2539 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2547 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 431:
#line 2553 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 432:
#line 2562 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 433:
#line 2564 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 434:
#line 2571 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 435:
#line 2579 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 436:
#line 2583 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 437:
#line 2592 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 438:
#line 2597 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 439:
#line 2602 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 440:
#line 2606 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 441:
#line 2608 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 442:
#line 2611 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 443:
#line 2618 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 444:
#line 2626 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2638 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 446:
#line 2644 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 447:
#line 2650 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 450:
#line 2660 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 451:
#line 2666 "fgl.yacc"
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

  case 452:
#line 2738 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 453:
#line 2749 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 454:
#line 2757 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 455:
#line 2765 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 456:
#line 2765 "fgl.yacc"
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

  case 457:
#line 2781 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 458:
#line 2785 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 459:
#line 2791 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 460:
#line 2794 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 461:
#line 2802 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 462:
#line 2806 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 463:
#line 2809 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 464:
#line 2815 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 465:
#line 2825 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 466:
#line 2830 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 467:
#line 2837 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 468:
#line 2840 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 469:
#line 2843 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 470:
#line 2848 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 471:
#line 2855 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 472:
#line 2860 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 473:
#line 2865 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 474:
#line 2870 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 475:
#line 2881 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 476:
#line 2889 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 477:
#line 2897 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 478:
#line 2902 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 479:
#line 2906 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 480:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 481:
#line 2915 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 482:
#line 2919 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 483:
#line 2925 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 484:
#line 2928 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 485:
#line 2932 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 486:
#line 2936 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 487:
#line 2940 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 488:
#line 2944 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 489:
#line 2948 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 490:
#line 2955 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 491:
#line 2965 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 492:
#line 2970 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 493:
#line 2976 "fgl.yacc"
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

  case 494:
#line 2986 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 495:
#line 2991 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 496:
#line 2994 "fgl.yacc"
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

  case 497:
#line 3008 "fgl.yacc"
    {chk4var=1;}
    break;

  case 498:
#line 3008 "fgl.yacc"
    {chk4var=0;}
    break;

  case 499:
#line 3008 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 500:
#line 3011 "fgl.yacc"
    {chk4var=1;}
    break;

  case 501:
#line 3011 "fgl.yacc"
    {chk4var=0;}
    break;

  case 502:
#line 3011 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 503:
#line 3015 "fgl.yacc"
    {chk4var=1;}
    break;

  case 504:
#line 3015 "fgl.yacc"
    {chk4var=0;}
    break;

  case 505:
#line 3015 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 506:
#line 3019 "fgl.yacc"
    {chk4var=1;}
    break;

  case 507:
#line 3019 "fgl.yacc"
    {chk4var=0;}
    break;

  case 508:
#line 3019 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 509:
#line 3023 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3029 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3035 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3041 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3047 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3053 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 515:
#line 3062 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 516:
#line 3068 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 517:
#line 3078 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 518:
#line 3079 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 521:
#line 3087 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	field_name_list_as_char(yyvsp[-1].field_list), lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 522:
#line 3098 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 523:
#line 3099 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 524:
#line 3105 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 525:
#line 3116 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 526:
#line 3126 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 529:
#line 3139 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 530:
#line 3144 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 531:
#line 3151 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 532:
#line 3155 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 533:
#line 3158 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 534:
#line 3161 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 535:
#line 3167 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 536:
#line 3170 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 537:
#line 3173 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 538:
#line 3190 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 539:
#line 3193 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 540:
#line 3199 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 541:
#line 3200 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 542:
#line 3201 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 544:
#line 3206 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 545:
#line 3207 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 546:
#line 3208 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 547:
#line 3209 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3211 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 549:
#line 3212 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 550:
#line 3213 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 551:
#line 3215 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 552:
#line 3216 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 554:
#line 3222 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 555:
#line 3226 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 556:
#line 3230 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 557:
#line 3235 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 558:
#line 3239 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 559:
#line 3254 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 560:
#line 3258 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 561:
#line 3259 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 562:
#line 3266 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 564:
#line 3283 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 565:
#line 3287 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 566:
#line 3293 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 567:
#line 3297 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 568:
#line 3306 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 569:
#line 3307 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 570:
#line 3319 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 571:
#line 3325 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 572:
#line 3333 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 579:
#line 3350 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 580:
#line 3352 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 581:
#line 3355 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 582:
#line 3357 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 587:
#line 3371 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 588:
#line 3373 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 589:
#line 3376 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 590:
#line 3378 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 603:
#line 3409 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 604:
#line 3411 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 605:
#line 3414 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 606:
#line 3416 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 607:
#line 3419 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 608:
#line 3421 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 609:
#line 3424 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 610:
#line 3426 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 611:
#line 3429 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 612:
#line 3431 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 613:
#line 3446 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 614:
#line 3462 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 615:
#line 3463 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 616:
#line 3464 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 617:
#line 3465 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 618:
#line 3466 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 619:
#line 3467 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 620:
#line 3468 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 624:
#line 3476 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 626:
#line 3482 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 627:
#line 3485 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 628:
#line 3490 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 629:
#line 3495 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 630:
#line 3498 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 631:
#line 3503 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 632:
#line 3508 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 633:
#line 3513 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 634:
#line 3520 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 635:
#line 3521 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 636:
#line 3528 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 637:
#line 3535 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 638:
#line 3537 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 639:
#line 3543 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 640:
#line 3548 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 641:
#line 3553 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 642:
#line 3558 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 643:
#line 3558 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 644:
#line 3561 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 645:
#line 3567 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 646:
#line 3572 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 647:
#line 3576 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 650:
#line 3584 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 651:
#line 3587 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 652:
#line 3590 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 653:
#line 3595 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 654:
#line 3600 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 655:
#line 3605 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 656:
#line 3612 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 658:
#line 3621 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 659:
#line 3683 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 661:
#line 3692 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 662:
#line 3701 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 664:
#line 3708 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 665:
#line 3711 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 666:
#line 3717 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 667:
#line 3723 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 668:
#line 3727 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 669:
#line 3731 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 670:
#line 3737 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 671:
#line 3741 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 672:
#line 3745 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 673:
#line 3750 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 674:
#line 3755 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 693:
#line 3796 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 694:
#line 3803 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 695:
#line 3805 "fgl.yacc"
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

  case 697:
#line 3824 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 699:
#line 3827 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 700:
#line 3829 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 701:
#line 3832 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 702:
#line 3836 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 703:
#line 3839 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 704:
#line 3845 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 705:
#line 3856 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 706:
#line 3857 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 707:
#line 3860 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 709:
#line 3866 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 710:
#line 3870 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 711:
#line 3871 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 712:
#line 3875 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 716:
#line 3890 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 717:
#line 3892 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 720:
#line 3901 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 721:
#line 3904 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 722:
#line 3908 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 723:
#line 3911 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 724:
#line 3914 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 725:
#line 3917 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 726:
#line 3920 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 727:
#line 3924 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 728:
#line 3927 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 729:
#line 3930 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 730:
#line 3933 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 731:
#line 3936 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 732:
#line 3939 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 733:
#line 3942 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 734:
#line 3945 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 735:
#line 3948 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 736:
#line 3949 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 737:
#line 3949 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 738:
#line 3950 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 739:
#line 3950 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 740:
#line 3951 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 741:
#line 3951 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 742:
#line 3952 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 743:
#line 3955 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 744:
#line 3956 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 745:
#line 3959 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 746:
#line 3967 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 747:
#line 3971 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 748:
#line 3977 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 749:
#line 3981 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 750:
#line 3986 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 751:
#line 3991 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 752:
#line 3996 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 753:
#line 3997 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 754:
#line 3998 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 755:
#line 4002 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 756:
#line 4006 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 757:
#line 4015 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 758:
#line 4020 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 759:
#line 4024 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 760:
#line 4031 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 761:
#line 4040 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 762:
#line 4046 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 763:
#line 4047 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 764:
#line 4048 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 765:
#line 4049 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 766:
#line 4052 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 768:
#line 4055 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 769:
#line 4062 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 770:
#line 4063 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 771:
#line 4064 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 772:
#line 4065 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 773:
#line 4066 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 774:
#line 4067 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 775:
#line 4068 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 776:
#line 4069 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 777:
#line 4070 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 778:
#line 4075 "fgl.yacc"
    {iskey=1;}
    break;

  case 779:
#line 4075 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 780:
#line 4077 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 781:
#line 4080 "fgl.yacc"
    {iskey=1;}
    break;

  case 782:
#line 4080 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 783:
#line 4082 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 784:
#line 4086 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 785:
#line 4089 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 786:
#line 4090 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 788:
#line 4093 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 794:
#line 4105 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 795:
#line 4106 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 796:
#line 4107 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 797:
#line 4108 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 798:
#line 4109 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 799:
#line 4110 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 800:
#line 4111 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 801:
#line 4112 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 802:
#line 4113 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 803:
#line 4114 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 804:
#line 4115 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 805:
#line 4116 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 806:
#line 4117 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 807:
#line 4118 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 808:
#line 4122 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 809:
#line 4140 "fgl.yacc"
    {chk4var=1;}
    break;

  case 810:
#line 4140 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 811:
#line 4143 "fgl.yacc"
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

  case 812:
#line 4167 "fgl.yacc"
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

  case 814:
#line 4185 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 815:
#line 4191 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 816:
#line 4197 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 817:
#line 4203 "fgl.yacc"
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

  case 818:
#line 4215 "fgl.yacc"
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

  case 819:
#line 4240 "fgl.yacc"
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

  case 822:
#line 4256 "fgl.yacc"
    {
	}
    break;

  case 831:
#line 4281 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 835:
#line 4289 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 851:
#line 4315 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 852:
#line 4316 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 853:
#line 4324 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 854:
#line 4329 "fgl.yacc"
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

  case 855:
#line 4345 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 856:
#line 4351 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 858:
#line 4366 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 859:
#line 4379 "fgl.yacc"
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

  case 860:
#line 4389 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 861:
#line 4396 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 862:
#line 4403 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 863:
#line 4409 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 864:
#line 4409 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 865:
#line 4414 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 866:
#line 4420 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 867:
#line 4428 "fgl.yacc"
    {
}
    break;

  case 871:
#line 4440 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 873:
#line 4448 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 874:
#line 4454 "fgl.yacc"
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

  case 877:
#line 4470 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 878:
#line 4474 "fgl.yacc"
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

  case 879:
#line 4487 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 881:
#line 4505 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 882:
#line 4513 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 883:
#line 4519 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 884:
#line 4530 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 885:
#line 4534 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 886:
#line 4541 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 887:
#line 4548 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 888:
#line 4554 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 889:
#line 4559 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 892:
#line 4566 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 893:
#line 4567 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 894:
#line 4569 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 895:
#line 4570 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4573 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 897:
#line 4574 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 898:
#line 4575 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 899:
#line 4577 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 900:
#line 4582 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 901:
#line 4587 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 902:
#line 4594 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 906:
#line 4601 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 907:
#line 4603 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 908:
#line 4605 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 909:
#line 4613 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 910:
#line 4619 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 911:
#line 4623 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 914:
#line 4635 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 915:
#line 4638 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 916:
#line 4642 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 917:
#line 4645 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 919:
#line 4654 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 920:
#line 4657 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 921:
#line 4660 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 928:
#line 4676 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 929:
#line 4681 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 930:
#line 4681 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 931:
#line 4684 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 932:
#line 4712 "fgl.yacc"
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

  case 934:
#line 4769 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 936:
#line 4776 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 937:
#line 4780 "fgl.yacc"
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

  case 938:
#line 4823 "fgl.yacc"
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

  case 942:
#line 4871 "fgl.yacc"
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

  case 943:
#line 4885 "fgl.yacc"
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

  case 948:
#line 4909 "fgl.yacc"
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

  case 949:
#line 4973 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 950:
#line 4978 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 951:
#line 4986 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 952:
#line 4991 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 953:
#line 4999 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 954:
#line 5005 "fgl.yacc"
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

  case 955:
#line 5037 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 956:
#line 5040 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 957:
#line 5042 "fgl.yacc"
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

  case 958:
#line 5083 "fgl.yacc"
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

  case 963:
#line 5136 "fgl.yacc"
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

  case 964:
#line 5188 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 966:
#line 5197 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 967:
#line 5202 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 968:
#line 5213 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5220 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 971:
#line 5228 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 972:
#line 5231 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 973:
#line 5232 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 975:
#line 5234 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 976:
#line 5235 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 977:
#line 5238 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 978:
#line 5241 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 979:
#line 5247 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 980:
#line 5250 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 981:
#line 5254 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 982:
#line 5259 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5267 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 984:
#line 5272 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 985:
#line 5279 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 986:
#line 5281 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 991:
#line 5313 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 992:
#line 5320 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 993:
#line 5327 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 994:
#line 5330 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 995:
#line 5344 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1000:
#line 5361 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1001:
#line 5366 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1002:
#line 5372 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1004:
#line 5379 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1005:
#line 5384 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1006:
#line 5387 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1007:
#line 5388 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1008:
#line 5391 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1009:
#line 5392 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1010:
#line 5395 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1011:
#line 5396 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1012:
#line 5401 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1013:
#line 5408 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1014:
#line 5411 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1015:
#line 5417 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1016:
#line 5419 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1017:
#line 5421 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5423 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1019:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1020:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1021:
#line 5427 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1022:
#line 5432 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1023:
#line 5440 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1024:
#line 5441 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1025:
#line 5446 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1026:
#line 5448 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1027:
#line 5450 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5468 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1032:
#line 5469 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1033:
#line 5470 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1034:
#line 5471 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1035:
#line 5472 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1036:
#line 5473 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1037:
#line 5474 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1038:
#line 5475 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1039:
#line 5476 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1040:
#line 5477 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1041:
#line 5478 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1042:
#line 5479 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1043:
#line 5480 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1044:
#line 5481 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1045:
#line 5482 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1046:
#line 5483 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1047:
#line 5484 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1048:
#line 5485 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1049:
#line 5486 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1050:
#line 5487 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1051:
#line 5488 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1052:
#line 5489 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1053:
#line 5490 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1054:
#line 5491 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1055:
#line 5492 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1056:
#line 5493 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1057:
#line 5508 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1060:
#line 5517 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1061:
#line 5521 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1062:
#line 5525 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1063:
#line 5529 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1064:
#line 5533 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1066:
#line 5553 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1067:
#line 5558 "fgl.yacc"
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

  case 1068:
#line 5571 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1069:
#line 5572 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1070:
#line 5576 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1071:
#line 5581 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1072:
#line 5582 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1073:
#line 5586 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1077:
#line 5592 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1078:
#line 5595 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1080:
#line 5610 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1081:
#line 5614 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1082:
#line 5620 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1083:
#line 5621 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1084:
#line 5626 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1085:
#line 5627 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1086:
#line 5630 "fgl.yacc"
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

  case 1088:
#line 5657 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
			}
    break;

  case 1089:
#line 5661 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1090:
#line 5665 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1091:
#line 5669 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[0].str);
			}
    break;

  case 1097:
#line 5687 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1098:
#line 5693 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1099:
#line 5701 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1100:
#line 5707 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1101:
#line 5709 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1105:
#line 5719 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1106:
#line 5719 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1107:
#line 5724 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1108:
#line 5728 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1109:
#line 5733 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1110:
#line 5733 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1111:
#line 5737 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1112:
#line 5737 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1113:
#line 5738 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1114:
#line 5738 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1115:
#line 5739 "fgl.yacc"
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

  case 1116:
#line 5752 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1117:
#line 5753 "fgl.yacc"
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

  case 1118:
#line 5769 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1125:
#line 5781 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1126:
#line 5781 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1127:
#line 5787 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1128:
#line 5787 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1129:
#line 5790 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1130:
#line 5790 "fgl.yacc"
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

  case 1131:
#line 5806 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1132:
#line 5807 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1133:
#line 5808 "fgl.yacc"
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

  case 1134:
#line 5817 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1135:
#line 5829 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1141:
#line 5840 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1142:
#line 5845 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1143:
#line 5845 "fgl.yacc"
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

  case 1144:
#line 5866 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1145:
#line 5871 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1146:
#line 5877 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1147:
#line 5878 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1148:
#line 5879 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1149:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1150:
#line 5884 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1151:
#line 5885 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1152:
#line 5886 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1153:
#line 5890 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1154:
#line 5900 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1155:
#line 5902 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1156:
#line 5907 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1157:
#line 5910 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1158:
#line 5915 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1159:
#line 5922 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1160:
#line 5929 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1161:
#line 5936 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1162:
#line 5945 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1163:
#line 5952 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1164:
#line 5959 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1165:
#line 5966 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1166:
#line 5973 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1171:
#line 5986 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1172:
#line 5987 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1173:
#line 5988 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1174:
#line 5989 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1175:
#line 5990 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1176:
#line 5991 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1177:
#line 5992 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1178:
#line 5993 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1179:
#line 5994 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1180:
#line 5995 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1183:
#line 6001 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1184:
#line 6002 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1185:
#line 6003 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1186:
#line 6004 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1191:
#line 6013 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1192:
#line 6014 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1193:
#line 6015 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1194:
#line 6016 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1195:
#line 6017 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1196:
#line 6018 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1197:
#line 6019 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1198:
#line 6020 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1199:
#line 6022 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1200:
#line 6023 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1201:
#line 6024 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1202:
#line 6025 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1203:
#line 6027 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1204:
#line 6028 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1205:
#line 6029 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1206:
#line 6030 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1210:
#line 6035 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1211:
#line 6036 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1215:
#line 6043 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1216:
#line 6052 "fgl.yacc"
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

  case 1217:
#line 6061 "fgl.yacc"
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

  case 1218:
#line 6074 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1219:
#line 6083 "fgl.yacc"
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

  case 1220:
#line 6094 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1221:
#line 6098 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1222:
#line 6102 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1223:
#line 6108 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1224:
#line 6113 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1225:
#line 6121 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1226:
#line 6124 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1227:
#line 6133 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1228:
#line 6144 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1230:
#line 6151 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1231:
#line 6159 "fgl.yacc"
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

  case 1232:
#line 6169 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1233:
#line 6172 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1234:
#line 6176 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1235:
#line 6184 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1236:
#line 6187 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1237:
#line 6193 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1238:
#line 6197 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1239:
#line 6201 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1240:
#line 6205 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1241:
#line 6209 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1242:
#line 6215 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1243:
#line 6216 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1244:
#line 6217 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1245:
#line 6218 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1246:
#line 6223 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1247:
#line 6225 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1248:
#line 6228 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1249:
#line 6232 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1250:
#line 6235 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1251:
#line 6242 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1252:
#line 6247 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1253:
#line 6248 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1254:
#line 6249 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1255:
#line 6250 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1256:
#line 6255 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1257:
#line 6256 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1258:
#line 6262 "fgl.yacc"
    {insql=1;}
    break;

  case 1259:
#line 6262 "fgl.yacc"
    {insql=0;}
    break;

  case 1260:
#line 6262 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1261:
#line 6267 "fgl.yacc"
    {insql=1;}
    break;

  case 1262:
#line 6267 "fgl.yacc"
    {insql=0;}
    break;

  case 1263:
#line 6267 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1264:
#line 6275 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1265:
#line 6276 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1267:
#line 6281 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1268:
#line 6286 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1269:
#line 6287 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1270:
#line 6288 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1271:
#line 6289 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1272:
#line 6290 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1274:
#line 6295 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1275:
#line 6295 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1277:
#line 6299 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1278:
#line 6303 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1279:
#line 6304 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1280:
#line 6307 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1281:
#line 6308 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1282:
#line 6311 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1283:
#line 6314 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1284:
#line 6317 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1285:
#line 6323 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1286:
#line 6325 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1288:
#line 6338 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1289:
#line 6342 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1290:
#line 6343 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1292:
#line 6348 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1293:
#line 6351 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1294:
#line 6357 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6360 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1296:
#line 6368 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1298:
#line 6375 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1299:
#line 6379 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1300:
#line 6383 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1301:
#line 6389 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1302:
#line 6392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1303:
#line 6401 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1304:
#line 6404 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1305:
#line 6407 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1306:
#line 6410 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1307:
#line 6413 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1308:
#line 6416 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1309:
#line 6419 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1310:
#line 6426 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1311:
#line 6429 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1312:
#line 6436 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1313:
#line 6439 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1314:
#line 6445 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6448 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1316:
#line 6455 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1317:
#line 6458 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1319:
#line 6466 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1321:
#line 6475 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1322:
#line 6478 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1323:
#line 6484 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1324:
#line 6487 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1325:
#line 6493 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1326:
#line 6500 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1327:
#line 6501 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1328:
#line 6505 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1329:
#line 6515 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1330:
#line 6518 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1331:
#line 6524 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1332:
#line 6526 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1333:
#line 6531 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1334:
#line 6532 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1335:
#line 6537 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1336:
#line 6538 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1337:
#line 6544 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1338:
#line 6545 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6572 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6578 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1349:
#line 6581 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1350:
#line 6584 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1351:
#line 6590 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1353:
#line 6596 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1355:
#line 6607 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1356:
#line 6621 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1357:
#line 6630 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1358:
#line 6630 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1359:
#line 6635 "fgl.yacc"
    {insql=1;}
    break;

  case 1360:
#line 6635 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1361:
#line 6640 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1362:
#line 6643 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1363:
#line 6645 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6652 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6656 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1367:
#line 6660 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1368:
#line 6667 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1369:
#line 6670 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1370:
#line 6677 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1371:
#line 6681 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1372:
#line 6687 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1373:
#line 6692 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1374:
#line 6696 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1375:
#line 6702 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1376:
#line 6705 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1377:
#line 6711 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1378:
#line 6718 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1379:
#line 6722 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1380:
#line 6727 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1381:
#line 6737 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1382:
#line 6740 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1383:
#line 6742 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1384:
#line 6744 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1385:
#line 6746 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1386:
#line 6748 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1387:
#line 6750 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1388:
#line 6752 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1389:
#line 6758 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1390:
#line 6768 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1391:
#line 6775 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6781 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1394:
#line 6784 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6791 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1400:
#line 6796 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1401:
#line 6801 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1402:
#line 6808 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1403:
#line 6809 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1404:
#line 6816 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1405:
#line 6827 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1406:
#line 6828 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6829 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1408:
#line 6832 "fgl.yacc"
    {insql=1;}
    break;

  case 1409:
#line 6832 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1410:
#line 6837 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1411:
#line 6842 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1413:
#line 6848 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1415:
#line 6852 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1416:
#line 6857 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1417:
#line 6862 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1418:
#line 6866 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1420:
#line 6872 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1421:
#line 6876 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1422:
#line 6883 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6884 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6885 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6886 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6896 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1430:
#line 6897 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1431:
#line 6898 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1432:
#line 6902 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1433:
#line 6903 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1436:
#line 6910 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 6913 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 6916 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 6921 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1444:
#line 6923 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 6929 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1448:
#line 6935 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 6945 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1452:
#line 6950 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1453:
#line 6952 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 6958 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1456:
#line 6961 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1458:
#line 6967 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1459:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 6980 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1463:
#line 6990 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 6996 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 7001 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7004 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7010 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 7015 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1472:
#line 7018 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1473:
#line 7021 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1474:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1475:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1476:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1477:
#line 7032 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1478:
#line 7045 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1479:
#line 7050 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1481:
#line 7054 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1482:
#line 7056 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1483:
#line 7063 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1484:
#line 7066 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1485:
#line 7072 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1486:
#line 7080 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1487:
#line 7084 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1488:
#line 7088 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1489:
#line 7092 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1490:
#line 7096 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1491:
#line 7099 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1492:
#line 7102 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1493:
#line 7110 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1494:
#line 7117 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1497:
#line 7126 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1498:
#line 7132 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1499:
#line 7135 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1500:
#line 7146 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1501:
#line 7153 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1502:
#line 7159 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1503:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1504:
#line 7169 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1505:
#line 7176 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1507:
#line 7183 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1508:
#line 7189 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1509:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 7191 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1512:
#line 7195 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 7200 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1515:
#line 7207 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1516:
#line 7212 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1517:
#line 7213 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1518:
#line 7216 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1519:
#line 7219 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1520:
#line 7224 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1521:
#line 7225 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1522:
#line 7230 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1523:
#line 7233 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1524:
#line 7239 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1525:
#line 7242 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1526:
#line 7248 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1527:
#line 7251 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1528:
#line 7257 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1529:
#line 7260 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1530:
#line 7267 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1531:
#line 7268 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1532:
#line 7297 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1533:
#line 7299 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1534:
#line 7303 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1536:
#line 7316 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1537:
#line 7319 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1538:
#line 7322 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1539:
#line 7325 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1541:
#line 7333 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1542:
#line 7336 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1544:
#line 7342 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1546:
#line 7348 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1547:
#line 7351 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1548:
#line 7354 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1549:
#line 7357 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1550:
#line 7360 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1551:
#line 7363 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1552:
#line 7366 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1553:
#line 7369 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1554:
#line 7374 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1556:
#line 7381 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1562:
#line 7389 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1563:
#line 7390 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1564:
#line 7395 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1565:
#line 7398 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1566:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1567:
#line 7408 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1568:
#line 7409 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1569:
#line 7410 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1570:
#line 7411 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1575:
#line 7431 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1577:
#line 7435 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1578:
#line 7436 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1580:
#line 7439 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1581:
#line 7441 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7450 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1590:
#line 7452 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1591:
#line 7454 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1593:
#line 7457 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1595:
#line 7460 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1599:
#line 7465 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1600:
#line 7467 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1601:
#line 7470 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1602:
#line 7471 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1603:
#line 7478 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7483 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1611:
#line 7499 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1612:
#line 7506 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1613:
#line 7510 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1614:
#line 7511 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1615:
#line 7512 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1616:
#line 7520 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1617:
#line 7521 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1618:
#line 7522 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1619:
#line 7533 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1620:
#line 7540 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1621:
#line 7545 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1622:
#line 7546 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1623:
#line 7547 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1624:
#line 7555 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1625:
#line 7556 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1626:
#line 7557 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1628:
#line 7583 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1629:
#line 7584 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1630:
#line 7585 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1631:
#line 7589 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1632:
#line 7592 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1633:
#line 7598 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1634:
#line 7603 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1635:
#line 7608 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1637:
#line 7619 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1641:
#line 7637 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1642:
#line 7640 "fgl.yacc"
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

  case 1643:
#line 7653 "fgl.yacc"
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

  case 1644:
#line 7668 "fgl.yacc"
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

  case 1645:
#line 7680 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1646:
#line 7682 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1647:
#line 7685 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1648:
#line 7685 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1649:
#line 7685 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1650:
#line 7685 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1651:
#line 7685 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1652:
#line 7685 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1653:
#line 7686 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1654:
#line 7689 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1655:
#line 7694 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1656:
#line 7694 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1657:
#line 7694 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1658:
#line 7694 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1659:
#line 7694 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1660:
#line 7694 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1661:
#line 7696 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1662:
#line 7699 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1677:
#line 7706 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1678:
#line 7709 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1679:
#line 7710 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1680:
#line 7711 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1681:
#line 7715 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1682:
#line 7723 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1683:
#line 7723 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1684:
#line 7729 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1685:
#line 7729 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1686:
#line 7736 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1687:
#line 7736 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1688:
#line 7742 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1689:
#line 7742 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1690:
#line 7750 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1691:
#line 7751 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1692:
#line 7752 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1693:
#line 7755 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1694:
#line 7755 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1696:
#line 7759 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1697:
#line 7760 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1698:
#line 7771 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1699:
#line 7774 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1700:
#line 7780 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1701:
#line 7785 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1702:
#line 7793 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1703:
#line 7805 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1704:
#line 7806 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1705:
#line 7809 "fgl.yacc"
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

  case 1706:
#line 7824 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1707:
#line 7835 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1708:
#line 7838 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1709:
#line 7846 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1710:
#line 7855 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1711:
#line 7858 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1712:
#line 7862 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1713:
#line 7865 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1714:
#line 7866 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1716:
#line 7875 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1717:
#line 7876 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1718:
#line 7885 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1719:
#line 7894 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1720:
#line 7899 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1721:
#line 7900 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1722:
#line 7901 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1723:
#line 7902 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1724:
#line 7909 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1725:
#line 7912 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1726:
#line 7918 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1727:
#line 7921 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1728:
#line 7928 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1729:
#line 7940 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1730:
#line 7949 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1731:
#line 7952 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1732:
#line 7955 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1733:
#line 7961 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1734:
#line 7967 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1735:
#line 7970 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1736:
#line 7971 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1737:
#line 7972 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1738:
#line 7973 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1739:
#line 7974 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1740:
#line 7977 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1741:
#line 7984 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1742:
#line 7986 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1743:
#line 7988 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1744:
#line 7990 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1745:
#line 7992 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1746:
#line 7993 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1747:
#line 7994 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1748:
#line 7995 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1749:
#line 7996 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1750:
#line 7997 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1751:
#line 7998 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1752:
#line 8000 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1753:
#line 8002 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1754:
#line 8004 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1755:
#line 8006 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1756:
#line 8008 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1757:
#line 8010 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1758:
#line 8012 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1759:
#line 8013 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1760:
#line 8015 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1761:
#line 8016 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1762:
#line 8017 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1763:
#line 8023 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1764:
#line 8024 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1766:
#line 8034 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1767:
#line 8042 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1768:
#line 8046 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1769:
#line 8053 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1770:
#line 8053 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1772:
#line 8057 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1773:
#line 8062 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1774:
#line 8062 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1776:
#line 8066 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1777:
#line 8070 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1780:
#line 8079 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1781:
#line 8079 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1786:
#line 8098 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1787:
#line 8099 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1790:
#line 8107 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1791:
#line 8113 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1794:
#line 8132 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1795:
#line 8133 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1796:
#line 8134 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1797:
#line 8135 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1798:
#line 8136 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1799:
#line 8137 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1800:
#line 8141 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1801:
#line 8142 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1802:
#line 8143 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1804:
#line 8148 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1805:
#line 8149 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1806:
#line 8153 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME (\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1807:
#line 8154 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s)",yyvsp[-1].str);}
    break;

  case 1808:
#line 8155 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1809:
#line 8156 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1810:
#line 8157 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1811:
#line 8158 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1812:
#line 8159 "fgl.yacc"
    {sprintf(yyval.str,
		"DATETIME(%s-%s-%s %s:%s:%s)",yyvsp[-10].str,yyvsp[-8].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1813:
#line 8161 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s %s:%s)",yyvsp[-8].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1814:
#line 8165 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1815:
#line 8166 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1816:
#line 8167 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1817:
#line 8171 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1818:
#line 8172 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s)",yyvsp[-1].str);}
    break;

  case 1819:
#line 8173 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1820:
#line 8174 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1821:
#line 8175 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1822:
#line 8176 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1823:
#line 8179 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1824:
#line 8183 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1826:
#line 8192 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1828:
#line 8197 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1829:
#line 8198 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2146:
#line 8523 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2147:
#line 8523 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2148:
#line 8530 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2149:
#line 8530 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2150:
#line 8618 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2151:
#line 8622 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2152:
#line 8624 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2153:
#line 8631 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2154:
#line 8635 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2155:
#line 8641 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2156:
#line 8649 "fgl.yacc"
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

  case 2157:
#line 8659 "fgl.yacc"
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

  case 2158:
#line 8669 "fgl.yacc"
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
#line 8681 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2160:
#line 8684 "fgl.yacc"
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

  case 2161:
#line 8703 "fgl.yacc"
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
#line 8729 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2163:
#line 8732 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2165:
#line 8741 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2166:
#line 8746 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2167:
#line 8749 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2168:
#line 8757 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2169:
#line 8765 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2170:
#line 8778 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2171:
#line 8781 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2172:
#line 8789 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2173:
#line 8792 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2174:
#line 8795 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2175:
#line 8803 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2176:
#line 8807 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2177:
#line 8808 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2178:
#line 8809 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2179:
#line 8810 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2180:
#line 8811 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2181:
#line 8812 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2182:
#line 8813 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2183:
#line 8814 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2184:
#line 8818 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2185:
#line 8819 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2186:
#line 8820 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2187:
#line 8821 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2188:
#line 8822 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2189:
#line 8828 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2190:
#line 8829 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2191:
#line 8830 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2192:
#line 8831 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2193:
#line 8832 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2194:
#line 8833 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2195:
#line 8834 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 8835 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 8836 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 8837 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 8838 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2200:
#line 8839 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2201:
#line 8840 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2202:
#line 8841 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2203:
#line 8842 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2204:
#line 8843 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2205:
#line 8848 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2206:
#line 8854 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2207:
#line 8855 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2208:
#line 8863 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2209:
#line 8865 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2211:
#line 8871 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2212:
#line 8875 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2213:
#line 8879 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2214:
#line 8895 "fgl.yacc"
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

  case 2215:
#line 8909 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2216:
#line 8915 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2217:
#line 8917 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2221:
#line 8931 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2222:
#line 8934 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2223:
#line 8941 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2224:
#line 8944 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2225:
#line 8974 "fgl.yacc"
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

  case 2226:
#line 8999 "fgl.yacc"
    {
char buff[256];
char was_str[40000];
int z = 0,a = 0;
strcpy(was_str,"");
printf("THRU : %s %s\n",yyvsp[-2].str,yyvsp[0].str);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
a=get_bind_cnt('i');
printf("get_bind_cnt=%d\n",a);
z=add_bind('i',buff);
z-=a;
for (a=0;a<z;a++)  {
         if (strlen(was_str)) {strcat(was_str,",");}
         strcat(was_str,"?");
}


	/* split_record(buff,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                //strcpy(kp,was_str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
        	}

		for (a=0;a<z;a++)  {
			if (strlen(was_str)) {strcat(was_str,",");}
         		strcat(was_str,"?");
		}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
*/
	yyval.sql_string=strdup(was_str);
}
    break;

  case 2227:
#line 9046 "fgl.yacc"
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

  case 2228:
#line 9081 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 2229:
#line 9090 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 2230:
#line 9101 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2231:
#line 9104 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2232:
#line 9110 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2233:
#line 9123 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2234:
#line 9137 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2235:
#line 9140 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2236:
#line 9144 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2237:
#line 9159 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2238:
#line 9159 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2239:
#line 9165 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2240:
#line 9166 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2241:
#line 9169 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2242:
#line 9170 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2243:
#line 9171 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2244:
#line 9172 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2245:
#line 9173 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2246:
#line 9174 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2247:
#line 9175 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2248:
#line 9186 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2249:
#line 9190 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2250:
#line 9194 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2251:
#line 9198 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2252:
#line 9203 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2253:
#line 9207 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2254:
#line 9212 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2256:
#line 9220 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2258:
#line 9226 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2259:
#line 9232 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2260:
#line 9236 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2265:
#line 9254 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2266:
#line 9261 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2267:
#line 9271 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2268:
#line 9271 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19131 "y.tab.c"

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


#line 996 "fgl.yacc"

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



