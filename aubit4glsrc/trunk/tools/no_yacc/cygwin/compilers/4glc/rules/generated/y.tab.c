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
     BEFORE_INSERT = 1004,
     CONCAT_PIPES = 1005,
     BEFORE_DELETE = 1006,
     DROP_TRIGGER = 1007,
     AFTER_INSERT = 1008,
     AFTER_DELETE = 1009,
     EXECUTE_IMMEDIATE = 1010,
     DELETE_ROW_EQUAL_TRUE = 1011,
     INSERT_ROW_EQUAL_TRUE = 1012,
     DELETE_ROW_EQUAL_FALSE = 1013,
     INSERT_ROW_EQUAL_FALSE = 1014,
     AFTER_INSERT_DELETE = 1015,
     BEFORE_INSERT_DELETE = 1016,
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
#define BEFORE_INSERT 1004
#define CONCAT_PIPES 1005
#define BEFORE_DELETE 1006
#define DROP_TRIGGER 1007
#define AFTER_INSERT 1008
#define AFTER_DELETE 1009
#define EXECUTE_IMMEDIATE 1010
#define DELETE_ROW_EQUAL_TRUE 1011
#define INSERT_ROW_EQUAL_TRUE 1012
#define DELETE_ROW_EQUAL_FALSE 1013
#define INSERT_ROW_EQUAL_FALSE 1014
#define AFTER_INSERT_DELETE 1015
#define BEFORE_INSERT_DELETE 1016
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
#line 213 "fgl.yacc"
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
	int 	integer_val;
	float 	float_val;
	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1696 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1708 "y.tab.c"

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
#define YYLAST   10974

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  724
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  861
/* YYNRULES -- Number of rules. */
#define YYNRULES  2347
/* YYNRULES -- Number of states. */
#define YYNSTATES  3745

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
    2761,  2765,  2772,  2774,  2778,  2780,  2782,  2784,  2788,  2795,
    2805,  2807,  2809,  2811,  2813,  2816,  2817,  2819,  2821,  2825,
    2827,  2831,  2833,  2837,  2839,  2843,  2845,  2847,  2849,  2851,
    2855,  2857,  2861,  2863,  2867,  2869,  2871,  2873,  2877,  2880,
    2881,  2883,  2885,  2890,  2892,  2896,  2898,  2902,  2910,  2911,
    2919,  2920,  2927,  2931,  2933,  2937,  2939,  2942,  2948,  2949,
    2957,  2958,  2961,  2962,  2964,  2970,  2973,  2979,  2980,  2986,
    2993,  2998,  2999,  3001,  3003,  3009,  3010,  3013,  3014,  3020,
    3025,  3028,  3030,  3034,  3037,  3040,  3043,  3046,  3049,  3052,
    3054,  3057,  3060,  3063,  3066,  3069,  3072,  3075,  3077,  3079,
    3081,  3083,  3086,  3089,  3091,  3093,  3095,  3097,  3099,  3101,
    3107,  3109,  3111,  3114,  3119,  3124,  3131,  3134,  3136,  3137,
    3149,  3150,  3153,  3159,  3160,  3162,  3163,  3166,  3168,  3171,
    3172,  3176,  3178,  3179,  3184,  3185,  3188,  3190,  3194,  3196,
    3198,  3202,  3207,  3212,  3215,  3217,  3219,  3221,  3222,  3224,
    3232,  3235,  3238,  3241,  3244,  3247,  3249,  3252,  3253,  3257,
    3258,  3262,  3263,  3267,  3268,  3272,  3273,  3277,  3278,  3283,
    3284,  3289,  3291,  3293,  3295,  3297,  3299,  3301,  3302,  3307,
    3308,  3310,  3311,  3316,  3318,  3321,  3324,  3327,  3328,  3330,
    3332,  3335,  3338,  3339,  3342,  3343,  3348,  3352,  3358,  3359,
    3362,  3367,  3369,  3371,  3373,  3375,  3377,  3378,  3380,  3382,
    3386,  3389,  3395,  3398,  3404,  3410,  3416,  3422,  3428,  3434,
    3435,  3438,  3440,  3443,  3446,  3449,  3452,  3455,  3458,  3460,
    3463,  3466,  3469,  3472,  3474,  3477,  3480,  3483,  3486,  3488,
    3490,  3492,  3493,  3496,  3499,  3502,  3505,  3508,  3511,  3514,
    3517,  3520,  3522,  3524,  3526,  3528,  3530,  3532,  3534,  3536,
    3539,  3542,  3545,  3548,  3551,  3553,  3555,  3557,  3558,  3562,
    3565,  3566,  3567,  3568,  3569,  3570,  3571,  3587,  3588,  3591,
    3594,  3595,  3597,  3598,  3599,  3600,  3601,  3602,  3603,  3619,
    3622,  3623,  3624,  3625,  3636,  3637,  3639,  3643,  3647,  3650,
    3655,  3659,  3663,  3667,  3669,  3672,  3675,  3678,  3681,  3683,
    3685,  3686,  3687,  3696,  3697,  3698,  3708,  3709,  3711,  3713,
    3716,  3719,  3722,  3725,  3727,  3729,  3731,  3732,  3734,  3736,
    3739,  3742,  3745,  3754,  3757,  3760,  3765,  3768,  3769,  3771,
    3773,  3777,  3780,  3783,  3785,  3787,  3791,  3793,  3795,  3798,
    3800,  3804,  3808,  3812,  3814,  3818,  3820,  3822,  3824,  3826,
    3828,  3830,  3832,  3835,  3840,  3842,  3846,  3848,  3852,  3855,
    3860,  3862,  3866,  3868,  3871,  3876,  3878,  3882,  3884,  3886,
    3888,  3891,  3895,  3900,  3903,  3908,  3909,  3912,  3915,  3920,
    3922,  3926,  3928,  3930,  3932,  3935,  3937,  3939,  3941,  3943,
    3945,  3948,  3955,  3962,  3963,  3965,  3966,  3968,  3971,  3973,
    3974,  3980,  3981,  3987,  3989,  3990,  3994,  3996,  4000,  4002,
    4006,  4008,  4010,  4011,  4016,  4018,  4021,  4023,  4024,  4025,
    4029,  4030,  4031,  4035,  4037,  4039,  4041,  4043,  4045,  4047,
    4050,  4053,  4058,  4062,  4066,  4068,  4072,  4075,  4077,  4079,
    4080,  4082,  4084,  4086,  4088,  4089,  4091,  4095,  4097,  4101,
    4103,  4104,  4108,  4110,  4112,  4114,  4116,  4118,  4120,  4122,
    4124,  4126,  4128,  4130,  4132,  4140,  4147,  4152,  4157,  4159,
    4161,  4163,  4164,  4166,  4169,  4171,  4173,  4175,  4177,  4181,
    4184,  4186,  4188,  4191,  4193,  4195,  4196,  4200,  4202,  4206,
    4208,  4212,  4214,  4216,  4223,  4224,  4228,  4230,  4234,  4235,
    4237,  4242,  4248,  4251,  4253,  4255,  4260,  4262,  4266,  4271,
    4276,  4281,  4283,  4287,  4289,  4291,  4293,  4296,  4298,  4300,
    4302,  4307,  4308,  4310,  4311,  4313,  4315,  4318,  4321,  4323,
    4325,  4327,  4329,  4331,  4336,  4338,  4342,  4344,  4346,  4348,
    4351,  4353,  4355,  4358,  4361,  4363,  4367,  4370,  4373,  4375,
    4379,  4381,  4384,  4389,  4391,  4394,  4396,  4400,  4405,  4406,
    4408,  4409,  4411,  4412,  4414,  4416,  4420,  4422,  4426,  4428,
    4431,  4433,  4437,  4440,  4443,  4444,  4447,  4449,  4451,  4457,
    4461,  4467,  4471,  4473,  4477,  4479,  4481,  4482,  4484,  4488,
    4492,  4496,  4503,  4508,  4513,  4518,  4523,  4529,  4531,  4533,
    4535,  4537,  4539,  4541,  4543,  4545,  4547,  4549,  4551,  4553,
    4554,  4556,  4558,  4560,  4562,  4564,  4566,  4568,  4573,  4574,
    4576,  4581,  4583,  4589,  4595,  4597,  4599,  4601,  4603,  4605,
    4610,  4612,  4617,  4624,  4629,  4631,  4636,  4638,  4646,  4648,
    4650,  4652,  4657,  4664,  4665,  4668,  4673,  4675,  4677,  4679,
    4681,  4683,  4685,  4687,  4691,  4693,  4695,  4699,  4705,  4709,
    4715,  4723,  4727,  4729,  4731,  4735,  4741,  4745,  4751,  4759,
    4761,  4762,  4766,  4772,  4774,  4777,  4780,  4785,  4789,  4791,
    4793,  4795,  4797,  4799,  4802,  4805,  4806,  4810,  4811,  4815,
    4817,  4819,  4821,  4823,  4825,  4827,  4829,  4834,  4836,  4838,
    4840,  4842,  4844,  4846,  4848,  4853,  4855,  4857,  4859,  4861,
    4863,  4865,  4867,  4869,  4871,  4873,  4875,  4877,  4879,  4881,
    4886,  4888,  4892,  4894,  4898,  4899,  4907,  4908,  4917,  4918,
    4925,  4926,  4935,  4936,  4938,  4941,  4943,  4947,  4949,  4953,
    4959,  4961,  4963,  4965,  4967,  4969,  4970,  4971,  4981,  4987,
    4989,  4991,  4998,  4999,  5003,  5005,  5009,  5014,  5016,  5017,
    5020,  5025,  5032,  5033,  5035,  5037,  5039,  5041,  5045,  5047,
    5050,  5052,  5054,  5057,  5060,  5062,  5064,  5066,  5069,  5072,
    5075,  5078,  5083,  5087,  5090,  5094,  5098,  5102,  5104,  5106,
    5108,  5110,  5112,  5114,  5120,  5126,  5132,  5138,  5144,  5149,
    5154,  5158,  5163,  5165,  5167,  5169,  5173,  5175,  5181,  5189,
    5195,  5196,  5199,  5201,  5203,  5204,  5208,  5210,  5214,  5216,
    5218,  5220,  5221,  5225,  5227,  5229,  5231,  5233,  5238,  5245,
    5247,  5249,  5252,  5256,  5258,  5260,  5262,  5264,  5266,  5268,
    5270,  5272,  5278,  5284,  5289,  5295,  5297,  5302,  5307,  5312,
    5319,  5326,  5335,  5344,  5358,  5370,  5372,  5380,  5385,  5390,
    5395,  5402,  5409,  5418,  5427,  5428,  5433,  5435,  5438,  5440,
    5442,  5444,  5446,  5448,  5450,  5452,  5454,  5456,  5458,  5460,
    5462,  5464,  5466,  5468,  5470,  5472,  5474,  5476,  5478,  5480,
    5482,  5484,  5486,  5488,  5490,  5492,  5494,  5496,  5498,  5500,
    5502,  5504,  5506,  5508,  5510,  5512,  5514,  5516,  5518,  5520,
    5522,  5524,  5526,  5528,  5530,  5532,  5534,  5536,  5538,  5540,
    5542,  5544,  5546,  5548,  5550,  5552,  5554,  5556,  5558,  5560,
    5562,  5564,  5566,  5568,  5570,  5572,  5574,  5576,  5578,  5580,
    5582,  5584,  5586,  5588,  5590,  5592,  5594,  5596,  5598,  5600,
    5602,  5604,  5606,  5608,  5610,  5612,  5614,  5616,  5618,  5620,
    5622,  5624,  5626,  5628,  5630,  5632,  5634,  5636,  5638,  5640,
    5642,  5644,  5646,  5648,  5650,  5652,  5654,  5656,  5658,  5660,
    5662,  5664,  5666,  5668,  5670,  5672,  5674,  5676,  5678,  5680,
    5682,  5684,  5686,  5688,  5690,  5692,  5694,  5696,  5698,  5700,
    5702,  5704,  5706,  5708,  5710,  5712,  5714,  5716,  5718,  5720,
    5722,  5724,  5726,  5728,  5730,  5732,  5734,  5736,  5738,  5740,
    5742,  5744,  5746,  5748,  5750,  5752,  5754,  5756,  5758,  5760,
    5762,  5764,  5766,  5768,  5770,  5772,  5774,  5776,  5778,  5780,
    5782,  5784,  5786,  5788,  5790,  5792,  5794,  5796,  5798,  5800,
    5802,  5804,  5806,  5808,  5810,  5812,  5814,  5816,  5818,  5820,
    5822,  5824,  5826,  5828,  5830,  5832,  5834,  5836,  5838,  5840,
    5842,  5844,  5846,  5848,  5850,  5852,  5854,  5856,  5858,  5860,
    5862,  5864,  5866,  5868,  5870,  5872,  5874,  5876,  5878,  5880,
    5882,  5884,  5886,  5888,  5890,  5892,  5894,  5896,  5898,  5900,
    5902,  5904,  5906,  5908,  5910,  5912,  5914,  5916,  5918,  5920,
    5922,  5924,  5926,  5928,  5930,  5932,  5934,  5936,  5938,  5940,
    5942,  5944,  5946,  5948,  5950,  5952,  5954,  5956,  5958,  5960,
    5962,  5964,  5966,  5968,  5970,  5972,  5974,  5976,  5978,  5980,
    5982,  5984,  5986,  5988,  5990,  5992,  5994,  5996,  5998,  6000,
    6002,  6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,
    6022,  6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,
    6042,  6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,
    6062,  6064,  6066,  6068,  6070,  6072,  6074,  6076,  6077,  6081,
    6082,  6086,  6087,  6088,  6095,  6096,  6099,  6102,  6110,  6114,
    6118,  6121,  6124,  6127,  6129,  6133,  6135,  6139,  6141,  6145,
    6147,  6151,  6153,  6155,  6157,  6160,  6163,  6165,  6167,  6170,
    6175,  6177,  6179,  6181,  6183,  6185,  6187,  6191,  6194,  6198,
    6202,  6206,  6212,  6218,  6224,  6230,  6236,  6241,  6246,  6250,
    6255,  6257,  6259,  6261,  6263,  6267,  6268,  6274,  6276,  6280,
    6284,  6288,  6290,  6293,  6295,  6297,  6299,  6303,  6309,  6311,
    6313,  6315,  6317,  6321,  6323,  6324,  6325,  6332,  6333,  6336,
    6337,  6339,  6341,  6344,  6347,  6349,  6351,  6356,  6360,  6362,
    6365,  6371,  6374,  6377,  6383,  6384,  6387,  6389,  6391,  6394,
    6401,  6408,  6410,  6411,  6413,  6416,  6418,  6421,  6422,  6425,
    6427,  6429,  6431,  6433,  6435,  6437,  6439,  6441,  6443,  6445,
    6447,  6449,  6451,  6453,  6455,  6457,  6459,  6461,  6463,  6465,
    6467,  6469,  6471,  6473,  6475,  6477,  6479,  6481,  6483,  6485,
    6487,  6489,  6491,  6493,  6495,  6497,  6499,  6501,  6503,  6505,
    6507,  6509,  6511,  6513,  6515,  6517,  6519,  6521,  6523,  6525,
    6527,  6529,  6531,  6533,  6535,  6537,  6539,  6541,  6543,  6545,
    6547,  6549,  6551,  6553,  6555,  6557,  6559,  6561,  6563,  6565,
    6567,  6569,  6571,  6573,  6575,  6577,  6579,  6581,  6583,  6585,
    6587,  6589,  6591,  6593,  6595,  6597,  6599,  6601
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
    1181,    -1,   153,   478,  1005,     5,    25,     5,    25,   440,
      -1,   455,   478,   997,   440,   394,  1162,    -1,  1301,    -1,
     240,   478,   953,   440,   394,  1162,    -1,    -1,    -1,  1162,
     636,  1005,   478,   748,   762,   440,   749,   760,    -1,    -1,
      -1,    -1,  1005,   478,   750,   762,   751,   440,   752,   760,
      -1,    -1,    -1,   521,  1510,   669,  1510,   478,   753,   762,
     754,   440,   760,    -1,    -1,    -1,  1005,   568,  1005,   478,
     755,   762,   756,   440,   760,    -1,    -1,    -1,    -1,   414,
     765,   636,   766,   506,   729,   474,   478,   757,   762,   758,
     440,   759,   761,    -1,    -1,   394,  1181,    -1,    -1,   394,
    1181,    -1,   211,    -1,    -1,   763,    -1,   764,    -1,   763,
       5,   764,    -1,   903,    -1,   530,    -1,    25,    -1,  1005,
      -1,  1005,    -1,  1005,   666,  1005,    -1,    -1,   582,   910,
     768,   771,   775,   772,    -1,    -1,   582,   769,   770,   773,
     772,    -1,   777,    -1,   770,   777,    -1,   779,    -1,   771,
     779,    -1,   409,    -1,    -1,    -1,   389,   774,  1579,    -1,
      -1,    -1,   389,   776,  1579,    -1,    -1,   625,   910,   778,
    1579,    -1,    -1,   625,   910,   780,  1579,    -1,   326,  1002,
      -1,   249,  1000,    -1,   131,  1000,    -1,   216,    -1,   233,
    1516,    -1,   541,   999,    -1,    30,   783,    31,    -1,   784,
      -1,   786,    -1,   785,    -1,   784,   785,    -1,    29,    -1,
     787,    -1,   786,   787,    -1,    28,    -1,   442,    -1,    -1,
      -1,   370,   790,   792,   791,   793,    -1,   433,  1162,   671,
     794,  1048,  1075,   735,    -1,  1162,   671,   794,  1048,   593,
     953,  1075,   735,    -1,    -1,   796,   239,    -1,   795,    -1,
     794,     5,   795,    -1,  1005,    -1,  1005,   666,  1005,    -1,
    1005,   666,    20,    -1,   797,    -1,   796,   797,    -1,    -1,
     318,   803,   798,  1579,    -1,    -1,   321,   804,   799,  1579,
      -1,    -1,  1078,   800,  1579,    -1,    -1,   214,   801,  1579,
      -1,    -1,   212,   802,  1579,    -1,  1009,    -1,   803,     5,
    1009,    -1,  1009,    -1,   804,     5,  1009,    -1,   139,    -1,
     140,    -1,   141,    -1,   142,    -1,   143,    -1,   144,    -1,
     478,   903,   807,   440,    -1,    -1,     5,   854,   672,   857,
      -1,   204,    -1,   327,    -1,    -1,   810,    -1,   811,    -1,
     810,   811,    -1,    -1,    -1,   485,   812,   814,   813,  1270,
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
     205,   928,  1181,   889,    -1,   449,   928,   908,   881,   889,
      -1,   258,  1002,   889,    -1,    -1,    -1,   236,   886,  1188,
     672,  1005,   666,    20,   888,   735,   887,   890,    -1,    -1,
     515,   996,    -1,   735,    -1,    -1,   891,   286,    -1,   286,
      -1,   892,    -1,   891,   892,    -1,    -1,   401,   893,  1579,
      -1,    -1,   397,   894,  1579,    -1,    -1,  1078,   895,  1579,
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
      -1,   926,    -1,    40,   903,    -1,   928,    -1,   928,   907,
      -1,   910,    -1,   530,    -1,   906,    -1,   907,     5,   906,
      -1,   910,    -1,   908,     5,   910,    -1,   910,    -1,   909,
       5,   910,    -1,   903,    -1,    18,    -1,    19,    -1,     9,
     903,    -1,   531,    -1,   475,    -1,   478,   903,   440,    -1,
     490,   478,  1490,   440,    -1,   342,   478,  1490,   440,    -1,
     911,  1011,    -1,   911,    26,    -1,    25,    -1,  1011,    -1,
      26,    -1,   916,    -1,  1162,    -1,  1162,   468,  1162,    -1,
     915,    -1,   481,   903,    -1,   441,   903,    -1,  1273,    -1,
      -1,   554,   918,  1273,    -1,     7,   903,    -1,     6,   903,
      -1,   903,    -1,   920,     5,   903,    -1,   669,   478,  1490,
     440,    -1,   476,   478,  1490,   440,    -1,   669,   478,   928,
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
     440,    -1,    -1,  1470,   672,  1471,    -1,   853,    -1,   934,
      -1,   337,   478,   953,   440,    -1,   146,   478,   996,   440,
      -1,   119,   478,   996,   440,    -1,   455,   478,   954,   440,
      -1,   240,   478,   953,   440,    -1,   107,   478,   953,   440,
      -1,   947,    -1,   929,    -1,  1466,    -1,   584,    -1,   470,
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
      -1,   642,  1162,    14,   910,   672,   910,   958,   956,  1579,
     957,   289,    -1,    -1,   618,   910,    -1,    -1,    -1,    -1,
     452,   960,   999,   961,   963,  1368,   962,  1579,   288,    -1,
      -1,     8,   928,   908,    -1,    -1,    -1,   684,  1005,   965,
     809,   966,  1107,   968,   967,   973,   685,    -1,    -1,   978,
      -1,    -1,   969,    -1,   970,    -1,   969,   970,    -1,    -1,
     686,   971,  1579,    -1,    -1,   687,   972,  1579,    -1,    -1,
     974,    -1,   975,    -1,   974,   975,    -1,    -1,   688,   976,
    1579,    -1,    -1,   689,   977,  1579,    -1,   979,   983,   374,
      -1,   138,    -1,   138,   980,   593,   981,    -1,   138,   433,
     982,    -1,  1162,    -1,   980,     5,  1162,    -1,  1005,    -1,
     981,     5,  1005,    -1,  1162,    -1,   982,     5,  1162,    -1,
     984,    -1,   983,   984,    -1,    -1,   690,   985,  1579,    -1,
      -1,   691,   986,  1579,    -1,    -1,   710,   981,   987,  1579,
      -1,    -1,   528,   981,   988,  1579,    -1,    -1,   671,   981,
     989,  1579,    -1,   592,   998,    -1,   601,    19,    26,    -1,
     601,    -1,   548,    18,    26,    -1,   548,    -1,    26,    -1,
    1162,    -1,   715,    -1,    25,    -1,  1010,    -1,   910,    -1,
     993,     5,   993,    -1,   994,    -1,  1005,    -1,   713,   478,
    1005,   440,    -1,  1005,   666,   713,   478,  1005,   440,    -1,
    1005,   506,   732,   474,    -1,  1005,   666,    20,    -1,  1005,
     506,   732,   474,   666,    20,    -1,  1005,   666,  1005,    -1,
    1005,   506,   732,   474,   666,  1005,    -1,   996,    -1,    25,
      -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,
      -1,  1006,    -1,    -1,   597,    26,    -1,  1578,    -1,  1007,
      -1,  1578,    -1,   399,   478,  1008,   440,    -1,  1165,    -1,
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
     668,   910,   622,  1034,  1579,  1035,  1036,   488,    -1,    -1,
      -1,   589,  1037,  1579,    -1,    -1,    -1,   110,  1038,   910,
     622,  1039,  1579,  1036,    -1,   155,  1005,   478,    26,   440,
      -1,   101,  1005,    -1,   123,  1005,    -1,    -1,   338,  1193,
    1043,   672,   530,    -1,   338,  1193,   603,  1044,    -1,  1045,
      -1,  1044,     5,  1045,    -1,  1046,   666,  1462,    -1,  1046,
     666,    20,    -1,  1458,    -1,    -1,  1049,   374,    -1,   374,
      -1,    -1,   199,    -1,  1050,    -1,  1049,  1050,    -1,    -1,
     318,  1064,  1051,  1579,    -1,    -1,   321,  1065,  1052,  1579,
      -1,    -1,   401,  1053,  1579,    -1,    -1,   397,  1054,  1579,
      -1,    -1,  1078,  1055,  1579,    -1,    -1,   353,  1056,  1579,
      -1,    -1,   323,  1057,  1579,    -1,    -1,    41,  1058,  1579,
      -1,    -1,    39,  1059,  1579,    -1,    -1,    51,  1060,  1579,
      -1,    -1,    50,  1061,  1579,    -1,    -1,    44,  1062,  1579,
      -1,    -1,    43,  1063,  1579,    -1,   996,    -1,  1064,     5,
     996,    -1,   996,    -1,  1065,     5,   996,    -1,   362,  1068,
      -1,   363,  1005,   705,  1068,    -1,   608,    -1,   424,    -1,
     996,    -1,    -1,   711,  1071,  1070,  1047,    -1,   433,  1181,
    1048,  1004,   735,    -1,  1181,  1048,   593,   953,  1004,   735,
      -1,    -1,   534,  1188,  1048,   593,  1005,   666,    20,  1004,
    1072,   735,    -1,   516,   953,  1074,    -1,   129,    26,    -1,
     130,    26,    -1,   673,    -1,   586,    -1,    -1,   597,    26,
      -1,  1077,    -1,    52,    25,    -1,   543,    14,    26,    -1,
     543,    14,  1162,    -1,    53,    14,    26,    -1,    53,    14,
    1162,    -1,    47,    -1,    49,    -1,    46,    -1,    48,    -1,
      -1,   477,  1079,  1084,    -1,   343,    -1,    -1,   643,  1081,
    1084,    -1,   351,  1086,    -1,   643,  1084,    -1,  1086,    -1,
     478,  1085,   440,    -1,  1086,    -1,  1085,     5,  1086,    -1,
    1087,    -1,   641,    -1,   360,    -1,   380,    -1,   352,    -1,
     532,    -1,   489,    -1,   673,    -1,   597,    -1,   586,    -1,
     225,    -1,   486,    -1,   497,    -1,   587,    -1,   602,    -1,
     567,    -1,   358,    -1,   359,    -1,    25,    -1,   557,    -1,
      -1,    -1,   645,  1090,  1186,  1091,    14,   928,  1092,    -1,
     530,    -1,   909,    -1,   267,  1162,    -1,   257,  1162,    -1,
     270,  1162,    -1,   498,  1184,   383,    -1,   498,  1184,   434,
     992,    -1,    -1,  1099,  1098,  1102,    -1,    -1,  1100,    -1,
    1101,    -1,  1100,  1101,    -1,  1041,    -1,  1106,    -1,  1563,
      -1,  1122,    -1,  1108,    -1,  1121,    -1,    -1,  1103,    -1,
    1105,    -1,  1103,  1105,    -1,   114,  1005,    -1,  1110,    -1,
    1116,    -1,  1128,    -1,  1283,    -1,  1293,    -1,  1149,    -1,
     964,    -1,   782,    -1,  1040,    -1,   788,    -1,  1563,    -1,
     782,    -1,    -1,   782,    -1,   810,    -1,   416,    -1,   108,
      -1,    -1,    -1,    -1,    -1,  1109,  1111,  1005,   478,  1112,
    1179,   440,  1113,   809,  1114,  1107,  1579,  1115,    -1,   259,
      -1,    -1,    -1,   604,  1117,   809,  1118,  1579,   410,    -1,
     225,   905,    -1,   928,    -1,   928,   908,    -1,   405,  1474,
      -1,   514,  1474,    -1,  1123,    -1,  1124,    -1,  1123,  1124,
      -1,  1125,    -1,    -1,   454,  1126,  1127,    -1,   809,   290,
      -1,   992,    -1,  1106,    -1,  1121,    -1,    -1,    -1,    -1,
     162,  1005,   161,  1005,   478,  1129,  1179,   440,  1130,   809,
    1131,  1107,  1579,  1115,    -1,    -1,   605,  1133,  1148,  1139,
    1134,    -1,   411,    -1,    -1,   282,  1136,  1579,    -1,    -1,
      23,  1140,  1141,  1142,  1004,  1137,  1579,    -1,    -1,    23,
    1140,  1004,  1138,  1579,    -1,  1135,    -1,  1139,  1135,    -1,
      -1,  1080,    -1,    25,    -1,  1162,    -1,    -1,  1162,    -1,
      25,    -1,   299,  1146,    -1,   311,  1147,    -1,   294,  1147,
      -1,   632,    -1,    25,    -1,  1162,    -1,  1146,    -1,  1147,
       5,  1146,    -1,  1162,    -1,    25,    -1,    -1,    -1,   692,
    1005,  1150,   809,  1151,  1152,   693,    -1,  1153,    -1,  1152,
    1153,    -1,    -1,   694,  1154,  1579,    -1,    -1,   671,  1005,
    1155,  1579,    -1,  1159,  1157,    -1,    -1,   736,  1160,    -1,
    1161,    -1,  1158,    -1,  1027,    -1,  1029,    -1,  1031,    -1,
    1023,    -1,  1025,    -1,   419,   928,   908,    -1,    -1,   113,
      -1,   113,    -1,  1163,    -1,  1165,    -1,   238,  1165,    -1,
    1165,   666,    -1,  1164,  1169,    -1,  1164,  1005,   506,  1173,
     474,    -1,  1164,  1005,   506,  1173,   474,   506,  1173,   474,
      -1,  1170,    -1,  1005,    -1,  1166,    -1,  1005,   505,  1168,
     473,    -1,  1005,   505,  1168,   473,    -1,  1162,    -1,    25,
      -1,    20,    -1,  1005,    -1,  1005,  1172,    -1,  1005,  1172,
      -1,   506,  1173,   474,    -1,   506,  1173,   474,   506,  1173,
     474,    -1,  1174,    -1,  1173,     5,  1174,    -1,   732,    -1,
    1176,    -1,  1178,    -1,  1176,   666,  1177,    -1,  1176,   666,
    1005,   506,  1173,   474,    -1,  1176,   666,  1005,   506,  1173,
     474,   506,  1173,   474,    -1,  1005,    -1,  1167,    -1,    20,
      -1,  1005,    -1,  1005,  1172,    -1,    -1,  1180,    -1,  1182,
      -1,  1180,     5,  1182,    -1,  1183,    -1,  1181,     5,  1183,
      -1,  1005,    -1,  1005,   666,  1005,    -1,  1162,    -1,  1162,
     468,  1162,    -1,    25,    -1,  1011,    -1,    26,    -1,  1185,
      -1,  1184,     5,  1185,    -1,  1162,    -1,  1162,   468,  1162,
      -1,  1187,    -1,  1186,     5,  1187,    -1,  1175,    -1,  1162,
      -1,  1190,    -1,  1189,     5,  1190,    -1,  1162,  1191,    -1,
      -1,   634,    -1,   585,    -1,  1005,   506,  1173,   474,    -1,
    1194,    -1,  1193,     5,  1194,    -1,  1162,    -1,  1162,   468,
    1162,    -1,   302,  1001,   664,   994,   626,  1571,   740,    -1,
      -1,   664,   478,   910,     5,   910,   440,  1197,    -1,    -1,
     615,   478,   910,     5,   910,   440,    -1,   303,  1005,  1196,
      -1,  1005,    -1,   388,  1003,  1201,    -1,  1202,    -1,   593,
     910,    -1,  1203,  1204,  1209,     8,  1199,    -1,    -1,   664,
    1205,   478,   910,     5,   910,   440,    -1,    -1,   603,  1006,
      -1,    -1,   400,    -1,   265,  1516,   314,  1558,  1208,    -1,
     610,   998,    -1,   610,   998,     8,   928,   908,    -1,    -1,
     663,   623,  1510,   423,  1510,    -1,   663,   623,  1510,     5,
     423,  1510,    -1,   663,  1510,     5,  1510,    -1,    -1,   695,
      -1,   696,    -1,   443,   672,  1558,  1211,  1212,    -1,    -1,
     663,  1558,    -1,    -1,   663,   623,  1510,     8,  1510,    -1,
     623,  1510,     8,  1510,    -1,   459,  1214,    -1,  1215,    -1,
    1214,     5,  1215,    -1,   250,   991,    -1,   332,   991,    -1,
     379,   991,    -1,   387,   991,    -1,   341,   991,    -1,   307,
     991,    -1,  1082,    -1,   486,  1083,    -1,   497,  1083,    -1,
     608,  1083,    -1,   424,  1083,    -1,   597,  1083,    -1,   595,
     992,    -1,   596,   992,    -1,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,   449,   736,    -1,   711,   736,    -1,   339,
      -1,   243,    -1,   200,    -1,   180,    -1,   197,    -1,   188,
      -1,  1515,   461,  1219,   593,  1217,    -1,  1162,    -1,    25,
      -1,   451,  1219,    -1,   451,  1219,     8,  1181,    -1,   451,
    1219,   600,  1184,    -1,   451,  1219,   600,  1184,     8,  1181,
      -1,    45,  1217,    -1,  1006,    -1,    -1,   509,  1229,   735,
     642,  1224,  1162,  1222,  1004,   735,  1221,  1225,    -1,    -1,
     714,    26,    -1,   509,  1229,   735,   394,  1162,    -1,    -1,
     367,    -1,    -1,  1226,   330,    -1,  1227,    -1,  1226,  1227,
      -1,    -1,  1078,  1228,  1579,    -1,   909,    -1,    -1,   650,
     998,  1231,  1232,    -1,    -1,   593,  1233,    -1,  1234,    -1,
    1233,     5,  1234,    -1,  1502,    -1,   530,    -1,   268,  1237,
     136,    -1,   268,  1237,   672,  1236,    -1,   268,  1237,   135,
    1236,    -1,   268,  1237,    -1,    25,    -1,  1010,    -1,  1005,
      -1,    -1,   526,    -1,   196,  1237,  1238,   478,   928,  1120,
     440,    -1,   241,  1237,    -1,   115,  1237,    -1,  1274,  1282,
      -1,   494,   109,    -1,   494,  1244,    -1,  1245,    -1,  1244,
    1245,    -1,    -1,   184,  1246,  1579,    -1,    -1,   246,  1247,
    1579,    -1,    -1,   276,  1248,  1579,    -1,    -1,   264,  1249,
    1579,    -1,    -1,   301,  1250,  1579,    -1,    -1,   248,  1162,
    1251,  1579,    -1,    -1,   272,  1162,  1252,  1579,    -1,  1263,
      -1,  1266,    -1,  1265,    -1,  1254,    -1,  1291,    -1,  1257,
      -1,    -1,   607,   910,  1255,   529,    -1,    -1,   529,    -1,
      -1,   616,    26,  1258,  1256,    -1,   207,    -1,   675,  1278,
      -1,   210,  1278,    -1,   209,  1278,    -1,    -1,  1260,    -1,
    1261,    -1,  1260,  1261,    -1,  1271,  1262,    -1,    -1,   664,
    1278,    -1,    -1,   566,  1264,  1259,  1270,    -1,   565,  1510,
    1270,    -1,   564,  1269,  1268,  1267,  1270,    -1,    -1,   201,
     903,    -1,   201,   903,     5,   903,    -1,   659,    -1,   660,
      -1,   661,    -1,   662,    -1,  1162,    -1,    -1,   569,    -1,
    1272,    -1,  1271,     5,  1272,    -1,   910,  1305,    -1,   655,
     478,   903,   440,  1290,    -1,   112,  1290,    -1,   543,   478,
      20,   440,  1290,    -1,   460,   478,    20,   440,  1290,    -1,
     436,   478,   903,   440,  1290,    -1,   635,   478,   903,   440,
    1290,    -1,   648,   478,   903,   440,  1290,    -1,   647,   478,
     903,   440,  1290,    -1,    -1,   508,  1275,    -1,  1276,    -1,
    1275,  1276,    -1,   275,    26,    -1,   266,    26,    -1,   349,
      26,    -1,   232,    26,    -1,   304,    26,    -1,   223,    -1,
     393,    25,    -1,   393,  1162,    -1,   224,    25,    -1,   208,
      25,    -1,  1281,    -1,  1277,  1281,    -1,  1279,   157,    -1,
    1279,   159,    -1,  1279,   158,    -1,  1279,    -1,  1011,    -1,
      26,    -1,    -1,   508,  1277,    -1,   275,  1278,    -1,   266,
    1278,    -1,   349,  1278,    -1,   232,  1278,    -1,   304,  1278,
      -1,   305,  1278,    -1,   674,    25,    -1,   675,  1278,    -1,
     679,    -1,   676,    -1,   677,    -1,   678,    -1,   683,    -1,
     680,    -1,   681,    -1,   682,    -1,   124,  1278,    -1,   125,
    1278,    -1,   126,  1278,    -1,   393,    25,    -1,   224,    25,
      -1,   448,    -1,   121,    -1,   122,    -1,    -1,   561,   665,
    1189,    -1,   185,  1189,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   512,  1284,  1005,   478,  1285,  1179,   440,  1286,   809,
    1287,  1242,  1288,  1243,  1289,   287,    -1,    -1,   573,   903,
      -1,   563,  1292,    -1,    -1,  1217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,  1294,  1005,   478,  1295,  1179,   440,
    1296,   809,  1297,  1300,  1298,  1243,  1299,   287,    -1,  1280,
    1282,    -1,    -1,    -1,    -1,   203,   478,    25,     5,  1302,
     762,  1303,   440,  1304,   760,    -1,    -1,   432,    -1,   432,
     266,    26,    -1,   432,   266,  1162,    -1,   653,   910,    -1,
     653,   910,   394,  1162,    -1,   653,   910,   211,    -1,   653,
     910,   624,    -1,   653,   910,   591,    -1,  1308,    -1,   220,
    1458,    -1,   373,  1458,    -1,   329,  1459,    -1,    42,  1005,
      -1,  1322,    -1,  1310,    -1,    -1,    -1,   253,  1311,  1458,
     478,  1312,  1326,   440,  1315,    -1,    -1,    -1,   182,  1313,
    1458,   478,  1314,  1326,   440,  1315,  1323,    -1,    -1,  1316,
      -1,  1317,    -1,  1316,  1317,    -1,   669,  1318,    -1,   292,
      26,    -1,    56,    26,    -1,   133,    -1,   134,    -1,  1578,
      -1,    -1,  1320,    -1,  1321,    -1,  1320,  1321,    -1,   669,
    1318,    -1,   723,    26,    -1,   152,  1459,   671,  1458,   478,
    1324,   440,  1319,    -1,    99,  1006,    -1,   100,  1006,    -1,
     219,  1458,   642,  1458,    -1,   104,  1458,    -1,    -1,   316,
      -1,  1325,    -1,  1324,     5,  1325,    -1,  1005,   634,    -1,
    1005,   585,    -1,  1005,    -1,  1327,    -1,  1326,     5,  1327,
      -1,  1410,    -1,  1408,    -1,   169,  1005,    -1,   227,    -1,
      54,  1005,  1330,    -1,    55,  1459,   149,    -1,    55,  1459,
     150,    -1,  1331,    -1,  1330,     5,  1331,    -1,  1332,    -1,
    1335,    -1,  1338,    -1,  1343,    -1,  1346,    -1,  1342,    -1,
    1341,    -1,   631,  1333,    -1,   631,   478,  1334,   440,    -1,
    1327,    -1,  1327,   710,  1005,    -1,  1333,    -1,  1334,     5,
    1333,    -1,   588,  1337,    -1,   588,   478,  1336,   440,    -1,
    1337,    -1,  1336,     5,  1337,    -1,  1005,    -1,   502,  1340,
      -1,   502,   478,  1339,   440,    -1,  1340,    -1,  1339,     5,
    1340,    -1,  1327,    -1,   133,    -1,   134,    -1,   132,    26,
      -1,   102,  1408,  1345,    -1,   102,   478,  1344,   440,    -1,
    1408,  1345,    -1,  1344,     5,  1408,  1345,    -1,    -1,   105,
    1005,    -1,   103,  1347,    -1,   103,   478,  1347,   440,    -1,
    1348,    -1,  1347,     5,  1348,    -1,  1005,    -1,   313,    -1,
     279,    -1,   213,  1351,    -1,   192,    -1,   181,    -1,   168,
      -1,   166,    -1,   170,    -1,   226,  1516,    -1,   278,  1350,
     507,  1510,   672,  1510,    -1,   346,   998,   507,  1510,   672,
    1510,    -1,    -1,  1516,    -1,    -1,   910,    -1,   570,   910,
      -1,   277,    -1,    -1,   296,  1355,  1458,  1358,  1356,    -1,
      -1,   526,  1357,   478,  1360,   440,    -1,  1496,    -1,    -1,
     478,  1359,   440,    -1,  1462,    -1,  1359,     5,  1462,    -1,
    1361,    -1,  1360,     5,  1361,    -1,  1502,    -1,   530,    -1,
      -1,   547,  1363,  1365,  1366,    -1,  1006,    -1,  1370,   999,
      -1,   999,    -1,    -1,    -1,   600,  1367,  1184,    -1,    -1,
      -1,   600,  1369,  1184,    -1,   548,    -1,   601,    -1,   608,
      -1,   424,    -1,   391,    -1,   444,    -1,   427,   910,    -1,
     400,   910,    -1,   285,  1458,   198,   999,    -1,   285,  1458,
    1431,    -1,   561,   665,  1374,    -1,  1375,    -1,  1374,     5,
    1375,    -1,  1376,  1377,    -1,    26,    -1,  1462,    -1,    -1,
     634,    -1,   585,    -1,   324,    -1,   357,    -1,    -1,   376,
      -1,   405,  1382,  1380,    -1,  1558,    -1,  1558,   658,  1005,
      -1,    25,    -1,    -1,  1515,  1384,  1385,    -1,  1416,    -1,
    1420,    -1,  1379,    -1,  1517,    -1,  1378,    -1,  1371,    -1,
    1372,    -1,  1362,    -1,  1354,    -1,  1353,    -1,  1486,    -1,
    1538,    -1,   552,  1389,   671,  1458,   672,  1394,  1388,    -1,
     513,  1389,   671,  1458,   593,  1394,    -1,   552,  1387,   672,
    1394,    -1,   513,  1387,   593,  1394,    -1,   443,    -1,   428,
      -1,   638,    -1,    -1,   191,    -1,   663,  1005,    -1,   215,
      -1,   632,    -1,  1390,    -1,  1391,    -1,  1390,     5,  1391,
      -1,   518,  1392,    -1,   497,    -1,   486,    -1,   525,  1392,
      -1,   533,    -1,   555,    -1,    -1,   478,  1393,   440,    -1,
    1462,    -1,  1393,     5,  1462,    -1,  1395,    -1,  1394,     5,
    1395,    -1,   510,    -1,  1460,    -1,   283,  1458,  1397,   663,
    1496,  1399,    -1,    -1,   478,  1398,   440,    -1,  1462,    -1,
    1398,     5,  1462,    -1,    -1,   190,    -1,   539,   478,  1434,
     440,    -1,   293,   478,  1403,   440,  1402,    -1,   344,  1404,
      -1,  1405,    -1,  1458,    -1,  1458,   478,  1405,   440,    -1,
    1462,    -1,  1405,     5,  1462,    -1,   523,   478,  1407,   440,
      -1,   408,   478,  1407,   440,    -1,   306,   478,  1407,   440,
      -1,  1462,    -1,  1407,     5,  1462,    -1,  1406,    -1,  1401,
      -1,  1400,    -1,   448,  1465,    -1,   256,    -1,   255,    -1,
     254,    -1,  1005,  1450,  1411,  1412,    -1,    -1,  1409,    -1,
      -1,  1413,    -1,  1414,    -1,  1413,  1414,    -1,  1415,  1345,
      -1,   422,    -1,   206,    -1,   523,    -1,   408,    -1,  1402,
      -1,   539,   478,  1434,   440,    -1,   306,    -1,   167,  1417,
    1419,    -1,  1418,    -1,  1460,    -1,  1420,    -1,  1419,  1420,
      -1,  1396,    -1,  1386,    -1,   495,  1434,    -1,   417,  1423,
      -1,  1501,    -1,  1423,     5,  1501,    -1,   573,  1434,    -1,
     593,  1426,    -1,  1427,    -1,  1426,     5,  1427,    -1,  1428,
      -1,   562,  1428,    -1,   562,   478,  1429,   440,    -1,  1458,
      -1,  1458,  1464,    -1,  1427,    -1,  1429,     5,  1427,    -1,
    1425,  1431,  1432,  1433,    -1,    -1,  1424,    -1,    -1,  1422,
      -1,    -1,  1421,    -1,  1435,    -1,  1434,     6,  1435,    -1,
    1436,    -1,  1435,     7,  1436,    -1,  1437,    -1,     9,  1437,
      -1,  1448,    -1,   478,  1434,   440,    -1,   490,  1497,    -1,
     342,  1497,    -1,    -1,   489,  1441,    -1,  1503,    -1,  1506,
      -1,  1502,   669,   478,  1443,   440,    -1,  1502,   669,  1497,
      -1,  1502,   476,   478,  1443,   440,    -1,  1502,   476,  1497,
      -1,  1444,    -1,  1443,     5,  1444,    -1,  1562,    -1,  1465,
      -1,    -1,     9,    -1,  1502,  1445,   435,    -1,  1502,  1445,
     297,    -1,  1502,  1447,  1502,    -1,  1502,  1445,   437,  1502,
       7,  1502,    -1,  1502,   603,  1440,  1439,    -1,  1502,   420,
    1440,  1439,    -1,  1502,   720,  1440,  1439,    -1,  1502,   421,
    1440,  1439,    -1,  1502,  1445,    10,  1440,  1439,    -1,    14,
      -1,    17,    -1,    12,    -1,    13,    -1,   300,    -1,    10,
      -1,   719,    -1,    16,    -1,    15,    -1,  1446,    -1,  1442,
      -1,  1438,    -1,    -1,   632,    -1,   408,    -1,   523,    -1,
    1451,    -1,  1452,    -1,  1454,    -1,   367,    -1,   367,   478,
    1455,   440,    -1,    -1,   519,    -1,   519,   478,    26,   440,
      -1,   446,    -1,   446,   478,  1456,  1453,   440,    -1,   559,
     478,  1456,  1453,   440,    -1,   559,    -1,   584,    -1,   456,
      -1,   429,    -1,   368,    -1,   368,   478,  1455,   440,    -1,
     369,    -1,   369,   478,    26,   440,    -1,   369,   478,    26,
       5,    26,   440,    -1,   406,  1472,   672,  1473,    -1,   406,
      -1,   418,  1472,   672,  1473,    -1,   418,    -1,   418,  1472,
     478,    26,   440,   672,  1473,    -1,   621,    -1,   580,    -1,
     471,    -1,   471,   478,    26,   440,    -1,   471,   478,    26,
       5,    26,   440,    -1,    -1,     5,  1457,    -1,   549,   478,
    1456,   440,    -1,   612,    -1,   347,    -1,   549,    -1,   111,
      -1,    26,    -1,    26,    -1,    26,    -1,    25,   666,  1005,
      -1,    25,    -1,  1005,    -1,  1005,   636,  1005,    -1,  1005,
     636,    25,   666,  1005,    -1,  1005,   658,  1005,    -1,  1005,
     658,  1005,   636,  1005,    -1,  1005,   658,  1005,   636,    25,
     666,  1005,    -1,    25,   666,  1005,    -1,    25,    -1,  1005,
      -1,  1005,   636,  1005,    -1,  1005,   636,    25,   666,  1005,
      -1,  1005,   658,  1005,    -1,  1005,   658,  1005,   636,  1005,
      -1,  1005,   658,  1005,   636,    25,   666,  1005,    -1,  1005,
      -1,    -1,   506,    26,   474,    -1,   506,    26,     5,    26,
     474,    -1,  1463,    -1,   658,  1463,    -1,  1005,  1461,    -1,
    1458,   666,  1005,  1461,    -1,  1458,   666,    20,    -1,  1005,
      -1,    25,    -1,  1011,    -1,    26,    -1,  1467,    -1,   444,
    1469,    -1,   444,  1468,    -1,    -1,  1472,   672,  1473,    -1,
      -1,  1470,   672,  1470,    -1,   628,    -1,   560,    -1,   637,
      -1,   599,    -1,   501,    -1,   517,    -1,   415,    -1,   415,
     478,    26,   440,    -1,   628,    -1,   560,    -1,   637,    -1,
     599,    -1,   501,    -1,   517,    -1,   415,    -1,   415,   478,
      26,   440,    -1,   628,    -1,   560,    -1,   637,    -1,   599,
      -1,   501,    -1,   517,    -1,   415,    -1,   628,    -1,   560,
      -1,   637,    -1,   599,    -1,   501,    -1,   517,    -1,   415,
      -1,   415,   478,    26,   440,    -1,  1005,    -1,  1005,   658,
    1005,    -1,    25,    -1,  1515,   550,   999,    -1,    -1,  1515,
     447,  1364,   484,   642,  1484,  1477,    -1,    -1,  1515,   447,
    1364,   484,   147,   642,  1485,  1478,    -1,    -1,  1515,   447,
    1364,   186,  1485,  1479,    -1,    -1,  1515,   447,  1364,   187,
     147,   642,  1485,  1480,    -1,    -1,   336,    -1,   335,  1482,
      -1,  1483,    -1,  1482,     5,  1483,    -1,  1005,    -1,  1005,
     666,  1005,    -1,    25,   666,  1005,   666,  1005,    -1,  1485,
      -1,  1354,    -1,  1219,    -1,  1487,    -1,  1487,    -1,    -1,
      -1,   518,  1498,  1488,  1499,  1489,  1495,  1430,  1493,  1481,
      -1,   518,  1498,  1499,  1430,  1493,    -1,  1492,    -1,  1510,
      -1,   518,  1498,  1499,  1495,  1430,  1493,    -1,    -1,   572,
    1449,  1491,    -1,  1373,    -1,   381,  1494,  1323,    -1,  1373,
     381,  1494,  1323,    -1,  1005,    -1,    -1,   600,  1184,    -1,
     518,  1498,  1499,  1430,    -1,   478,   518,  1498,  1499,  1430,
     440,    -1,    -1,   632,    -1,   408,    -1,   523,    -1,  1500,
      -1,  1499,     5,  1500,    -1,  1502,    -1,  1502,  1005,    -1,
    1502,    -1,  1503,    -1,    19,  1503,    -1,    18,  1503,    -1,
    1504,    -1,  1562,    -1,  1497,    -1,   632,  1497,    -1,   633,
    1497,    -1,   617,  1497,    -1,   658,  1005,    -1,   658,  1005,
     666,  1005,    -1,  1503,    21,  1502,    -1,  1503,  1524,    -1,
    1503,    20,  1502,    -1,  1503,    18,  1502,    -1,  1503,    19,
    1502,    -1,  1465,    -1,   531,    -1,   475,    -1,   623,    -1,
      20,    -1,   112,    -1,   635,   478,  1449,  1502,   440,    -1,
     647,   478,  1449,  1502,   440,    -1,   648,   478,  1449,  1502,
     440,    -1,   655,   478,  1449,  1502,   440,    -1,   543,   478,
    1449,  1502,   440,    -1,  1005,   478,  1505,   440,    -1,   584,
     478,  1505,   440,    -1,   478,  1502,   440,    -1,   491,   478,
    1525,   440,    -1,  1526,    -1,  1528,    -1,  1502,    -1,  1505,
       5,  1502,    -1,  1465,    -1,  1515,   396,  1514,  1509,  1491,
      -1,  1515,   385,  1514,  1509,   296,  1458,  1511,    -1,  1515,
     385,  1514,  1509,  1162,    -1,    -1,   371,  1510,    -1,    25,
      -1,  1162,    -1,    -1,   478,  1512,   440,    -1,  1513,    -1,
    1512,     5,  1513,    -1,  1005,    -1,    25,    -1,  1162,    -1,
      -1,   315,  1516,   642,    -1,  1006,    -1,  1522,    -1,  1521,
      -1,  1518,    -1,   364,  1519,   672,  1519,    -1,   345,  1458,
     666,  1520,   672,  1520,    -1,  1005,    -1,  1005,    -1,   269,
    1458,    -1,   340,  1458,  1523,    -1,   319,    -1,   222,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,
     144,    -1,   444,     5,  1472,   672,  1473,    -1,  1562,     5,
    1472,   672,  1473,    -1,   444,  1472,   672,  1473,    -1,  1502,
       5,  1472,   672,  1473,    -1,  1527,    -1,  1527,  1472,   672,
    1473,    -1,   406,   478,    25,   440,    -1,   406,   478,    26,
     440,    -1,   406,   478,    26,    19,    26,   440,    -1,   406,
     478,    26,   636,    26,   440,    -1,   406,   478,    26,    19,
      26,    19,    26,   440,    -1,   406,   478,    26,   636,    26,
     636,    26,   440,    -1,   406,   478,    26,    19,    26,    19,
      26,    26,   636,    26,   636,    26,   440,    -1,   406,   478,
      26,    19,    26,    19,    26,    26,   636,    26,   440,    -1,
    1529,    -1,  1529,  1472,   478,    26,   440,   672,  1473,    -1,
    1529,  1472,   672,  1473,    -1,   418,   478,    25,   440,    -1,
     418,   478,    26,   440,    -1,   418,   478,    26,    19,    26,
     440,    -1,   418,   478,    26,   636,    26,   440,    -1,   418,
     478,    26,    19,    26,    19,    26,   440,    -1,   418,   478,
      26,   636,    26,   636,    26,   440,    -1,    -1,   654,  1531,
    1532,   237,    -1,  1533,    -1,  1532,  1533,    -1,    33,    -1,
    1534,    -1,  1536,    -1,   400,    -1,   352,    -1,   271,    -1,
     631,    -1,   528,    -1,   632,    -1,   533,    -1,   577,    -1,
     633,    -1,   163,    -1,   534,    -1,   663,    -1,   634,    -1,
     365,    -1,   535,    -1,   366,    -1,   664,    -1,   658,    -1,
     322,    -1,   536,    -1,   231,    -1,   436,    -1,   635,    -1,
     710,    -1,   437,    -1,   537,    -1,   538,    -1,   578,    -1,
     579,    -1,   479,    -1,   480,    -1,   402,    -1,   697,    -1,
     665,    -1,   580,    -1,   438,    -1,   582,    -1,   576,    -1,
     367,    -1,   539,    -1,   540,    -1,   439,    -1,   541,    -1,
     440,    -1,   474,    -1,   542,    -1,   636,    -1,   481,    -1,
     441,    -1,     5,    -1,    23,    -1,   442,    -1,   482,    -1,
     443,    -1,   404,    -1,   403,    -1,   370,    -1,   543,    -1,
     483,    -1,   444,    -1,   484,    -1,   583,    -1,   405,    -1,
     584,    -1,   406,    -1,   637,    -1,   638,    -1,   445,    -1,
     639,    -1,   446,    -1,   447,    -1,   448,    -1,   407,    -1,
     544,    -1,   485,    -1,   486,    -1,   371,    -1,   585,    -1,
     328,    -1,   640,    -1,   701,    -1,   449,    -1,   408,    -1,
      21,    -1,   666,    -1,   487,    -1,   372,    -1,   588,    -1,
     110,    -1,   589,    -1,   704,    -1,   450,    -1,    14,    -1,
     545,    -1,   489,    -1,   546,    -1,   376,    -1,   590,    -1,
     451,    -1,   490,    -1,   591,    -1,   491,    -1,   492,    -1,
     414,    -1,   581,    -1,   547,    -1,   146,    -1,   240,    -1,
     493,    -1,   548,    -1,   641,    -1,   549,    -1,   550,    -1,
     642,    -1,   452,    -1,   453,    -1,   494,    -1,   684,    -1,
     138,    -1,   153,    -1,   551,    -1,   415,    -1,   592,    -1,
     593,    -1,   416,    -1,   337,    -1,   454,    -1,   667,    -1,
     594,    -1,   552,    -1,    13,    -1,   553,    -1,   554,    -1,
     495,    -1,   496,    -1,   597,    -1,   598,    -1,   599,    -1,
     706,    -1,   119,    -1,   668,    -1,   669,    -1,   159,    -1,
     555,    -1,   455,    -1,   338,    -1,   711,    -1,   497,    -1,
     456,    -1,   380,    -1,   418,    -1,   713,    -1,   382,    -1,
     643,    -1,   586,    -1,   705,    -1,   556,    -1,   529,    -1,
     419,    -1,   644,    -1,   673,    -1,   457,    -1,     7,    -1,
     475,    -1,   629,    -1,   530,    -1,     6,    -1,   531,    -1,
       8,    -1,   601,    -1,   602,    -1,    12,    -1,   645,    -1,
     603,    -1,   558,    -1,   498,    -1,   646,    -1,   458,    -1,
     604,    -1,   499,    -1,    10,    -1,    53,    -1,   500,    -1,
     605,    -1,   692,    -1,   707,    -1,    19,    -1,   501,    -1,
     158,    -1,    22,    -1,   606,    -1,   502,    -1,   559,    -1,
     560,    -1,    20,    -1,   607,    -1,   608,    -1,   358,    -1,
     609,    -1,   503,    -1,     9,    -1,   670,    -1,   715,    -1,
     671,    -1,   610,    -1,   478,    -1,   506,    -1,   507,    -1,
     459,    -1,   561,    -1,   389,    -1,   562,    -1,   508,    -1,
     649,    -1,   423,    -1,   563,    -1,   203,    -1,   154,    -1,
     460,    -1,    18,    -1,   157,    -1,   390,    -1,   461,    -1,
     160,    -1,   424,    -1,   359,    -1,   566,    -1,   391,    -1,
     392,    -1,   462,    -1,   509,    -1,   510,    -1,   650,    -1,
     611,    -1,   425,    -1,   612,    -1,   511,    -1,   463,    -1,
     651,    -1,   344,    -1,   426,    -1,   427,    -1,   512,    -1,
     428,    -1,   225,    -1,   394,    -1,   464,    -1,   513,    -1,
     567,    -1,   309,    -1,   652,    -1,   613,    -1,   653,    -1,
     514,    -1,   516,    -1,   517,    -1,   465,    -1,   518,    -1,
     569,    -1,   519,    -1,   466,    -1,   521,    -1,   614,    -1,
     532,    -1,   615,    -1,   616,    -1,   570,    -1,   347,    -1,
     429,    -1,   617,    -1,   522,    -1,   654,    -1,   348,    -1,
     137,    -1,   618,    -1,   619,    -1,   655,    -1,   467,    -1,
     587,    -1,   620,    -1,   164,    -1,   621,    -1,   622,    -1,
     468,    -1,   714,    -1,   672,    -1,   656,    -1,   469,    -1,
     571,    -1,   245,    -1,   395,    -1,   572,    -1,   523,    -1,
     524,    -1,   525,    -1,   470,    -1,   657,    -1,   623,    -1,
     430,    -1,   526,    -1,   471,    -1,   399,    -1,   624,    -1,
     472,    -1,   625,    -1,   573,    -1,   574,    -1,   575,    -1,
     626,    -1,   432,    -1,   627,    -1,   647,    -1,   648,    -1,
     630,    -1,   628,    -1,   527,    -1,    -1,   238,  1535,  1562,
      -1,    -1,   600,  1537,  1184,    -1,    -1,    -1,   525,  1458,
    1539,  1542,  1540,  1541,    -1,    -1,   198,   999,    -1,   573,
    1434,    -1,    97,  1546,   440,    14,   478,  1547,   440,    -1,
      93,  1547,   440,    -1,    94,  1547,   440,    -1,   630,  1543,
      -1,    96,  1547,    -1,    95,  1547,    -1,  1545,    -1,  1543,
       5,  1545,    -1,  1462,    -1,  1544,    14,  1548,    -1,  1544,
      -1,  1546,     5,  1544,    -1,  1548,    -1,  1547,     5,  1548,
      -1,   530,    -1,  1549,    -1,  1550,    -1,    19,  1550,    -1,
      18,  1550,    -1,  1552,    -1,  1497,    -1,   658,  1005,    -1,
     658,  1005,   666,  1005,    -1,  1551,    -1,  1465,    -1,   531,
      -1,   475,    -1,   623,    -1,   112,    -1,  1550,    21,  1549,
      -1,  1550,  1524,    -1,  1550,    20,  1549,    -1,  1550,    18,
    1549,    -1,  1550,    19,  1549,    -1,   635,   478,  1449,  1549,
     440,    -1,   647,   478,  1449,  1549,   440,    -1,   648,   478,
    1449,  1549,   440,    -1,   655,   478,  1449,  1549,   440,    -1,
     543,   478,  1449,  1549,   440,    -1,  1005,   478,  1553,   440,
      -1,   584,   478,  1553,   440,    -1,   478,  1549,   440,    -1,
     491,   478,  1525,   440,    -1,  1526,    -1,  1528,    -1,  1562,
      -1,  1549,    -1,  1553,     5,  1549,    -1,    -1,   430,  1193,
     603,  1555,  1556,    -1,  1557,    -1,  1556,     5,  1557,    -1,
    1458,   666,  1462,    -1,  1458,   666,    20,    -1,  1559,    -1,
     238,  1560,    -1,  1560,    -1,  1171,    -1,  1005,    -1,  1560,
     666,  1561,    -1,    25,   666,  1560,   666,  1561,    -1,    20,
      -1,  1192,    -1,  1005,    -1,  1559,    -1,  1559,   468,  1559,
      -1,    34,    -1,    -1,    -1,   574,  1565,   910,  1566,  1579,
     375,    -1,    -1,   705,   953,    -1,    -1,   708,    -1,   229,
      -1,   325,  1000,    -1,   117,  1000,    -1,   355,    -1,   354,
      -1,   356,  1002,  1567,  1568,    -1,   540,   953,  1568,    -1,
     151,    -1,   183,  1000,    -1,   910,   613,     5,   910,   441,
      -1,   556,   910,    -1,   312,  1000,    -1,   148,  1574,     8,
    1575,  1573,    -1,    -1,   593,   910,    -1,  1005,    -1,  1005,
      -1,   295,  1000,    -1,   298,  1000,   672,   910,     5,   910,
      -1,   298,  1000,   665,   910,     5,   910,    -1,    27,    -1,
      -1,  1581,    -1,  1582,  1270,    -1,  1580,    -1,  1581,  1580,
      -1,    -1,  1583,  1584,    -1,   725,    -1,   726,    -1,   727,
      -1,   728,    -1,   745,    -1,   767,    -1,   781,    -1,   782,
      -1,   788,    -1,   789,    -1,   808,    -1,   882,    -1,   883,
      -1,   884,    -1,   885,    -1,   896,    -1,   897,    -1,   898,
      -1,   899,    -1,   900,    -1,   901,    -1,   902,    -1,   955,
      -1,   959,    -1,   990,    -1,  1012,    -1,  1014,    -1,  1017,
      -1,  1018,    -1,  1019,    -1,  1020,    -1,  1033,    -1,  1042,
      -1,  1066,    -1,  1067,    -1,  1069,    -1,  1073,    -1,  1088,
      -1,  1089,    -1,  1093,    -1,  1094,    -1,  1095,    -1,  1096,
      -1,  1104,    -1,  1119,    -1,  1132,    -1,  1143,    -1,  1144,
      -1,  1145,    -1,  1156,    -1,  1195,    -1,  1198,    -1,  1200,
      -1,  1206,    -1,  1207,    -1,  1210,    -1,  1213,    -1,  1216,
      -1,  1218,    -1,  1220,    -1,  1223,    -1,  1230,    -1,  1235,
      -1,  1239,    -1,  1240,    -1,  1241,    -1,  1253,    -1,  1306,
      -1,  1307,    -1,  1309,    -1,  1328,    -1,  1329,    -1,  1349,
      -1,  1352,    -1,  1381,    -1,  1383,    -1,  1475,    -1,  1476,
      -1,  1507,    -1,  1508,    -1,  1530,    -1,  1554,    -1,  1563,
      -1,  1564,    -1,  1569,    -1,  1570,    -1,  1572,    -1,  1576,
      -1,  1577,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   992,   992,   995,   998,  1004,  1010,  1017,  1021,  1021,
    1027,  1050,  1051,  1052,  1053,  1054,  1065,  1071,  1072,  1073,
    1074,  1075,  1080,  1081,  1092,  1095,  1098,  1098,  1102,  1105,
    1106,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,
    1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1131,  1132,
    1135,  1135,  1150,  1151,  1154,  1160,  1162,  1173,  1175,  1177,
    1179,  1183,  1185,  1247,  1251,  1255,  1255,  1265,  1269,  1272,
    1273,  1280,  1286,  1280,  1299,  1304,  1308,  1299,  1320,  1324,
    1320,  1332,  1337,  1332,  1356,  1363,  1367,  1355,  1393,  1393,
    1397,  1398,  1399,  1404,  1407,  1412,  1416,  1424,  1425,  1428,
    1428,  1434,  1438,  1453,  1451,  1469,  1469,  1484,  1484,  1487,
    1487,  1491,  1494,  1494,  1494,  1501,  1502,  1501,  1509,  1509,
    1520,  1520,  1539,  1542,  1545,  1548,  1551,  1554,  1567,  1572,
    1572,  1573,  1573,  1576,  1581,  1581,  1585,  1595,  1609,  1614,
    1608,  1625,  1631,  1639,  1640,  1643,  1643,  1646,  1650,  1655,
    1662,  1662,  1666,  1666,  1667,  1667,  1668,  1668,  1669,  1669,
    1670,  1670,  1678,  1682,  1688,  1692,  1707,  1710,  1713,  1716,
    1719,  1722,  1728,  1739,  1744,  1757,  1761,  1776,  1777,  1781,
    1781,  1785,  1785,  1785,  1786,  1791,  1791,  1794,  1794,  1803,
    1804,  1805,  1808,  1812,  1813,  1813,  1830,  1830,  1830,  1830,
    1834,  1841,  1842,  1845,  1845,  1849,  1850,  1851,  1852,  1857,
    1857,  1863,  1863,  1872,  1869,  1885,  1885,  1887,  1887,  1889,
    1891,  1893,  1895,  1898,  1902,  1902,  1903,  1903,  1907,  1907,
    1919,  1919,  1924,  1928,  1930,  1931,  1934,  1934,  1934,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,
    1949,  1952,  1953,  1954,  1955,  1959,  1964,  1969,  1973,  1976,
    1980,  1980,  1981,  1981,  1982,  1982,  1983,  1984,  1985,  1986,
    1987,  1988,  1991,  1992,  1993,  2023,  2023,  2028,  2032,  2034,
    2036,  2036,  2043,  2047,  2047,  2051,  2052,  2053,  2054,  2055,
    2056,  2057,  2063,  2063,  2066,  2068,  2074,  2076,  2082,  2090,
    2090,  2093,  2094,  2095,  2096,  2097,  2098,  2099,  2105,  2108,
    2108,  2121,  2121,  2128,  2129,  2130,  2132,  2133,  2135,  2137,
    2138,  2139,  2140,  2145,  2151,  2157,  2158,  2160,  2162,  2163,
    2164,  2165,  2166,  2167,  2170,  2171,  2178,  2186,  2186,  2194,
    2191,  2206,  2206,  2208,  2208,  2216,  2216,  2219,  2222,  2223,
    2228,  2240,  2244,  2247,  2250,  2251,  2252,  2253,  2254,  2259,
    2266,  2272,  2277,  2282,  2277,  2295,  2297,  2302,  2307,  2307,
    2307,  2311,  2311,  2314,  2314,  2321,  2321,  2328,  2328,  2339,
    2357,  2363,  2387,  2390,  2404,  2406,  2408,  2410,  2412,  2414,
    2416,  2422,  2424,  2428,  2430,  2432,  2434,  2436,  2438,  2440,
    2446,  2461,  2464,  2477,  2478,  2479,  2480,  2481,  2485,  2486,
    2487,  2491,  2496,  2503,  2504,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2512,  2513,  2520,  2520,  2525,  2525,  2528,  2534,
    2542,  2548,  2558,  2559,  2567,  2574,  2578,  2588,  2592,  2597,
    2602,  2604,  2607,  2613,  2621,  2634,  2639,  2645,  2650,  2655,
    2656,  2662,  2733,  2744,  2753,  2761,  2761,  2776,  2780,  2787,
    2790,  2798,  2802,  2805,  2811,  2820,  2825,  2833,  2836,  2839,
    2844,  2851,  2856,  2861,  2866,  2876,  2884,  2892,  2897,  2901,
    2906,  2910,  2914,  2921,  2924,  2927,  2931,  2935,  2939,  2943,
    2951,  2961,  2966,  2959,  2982,  2987,  2982,  3004,  3004,  3004,
    3007,  3007,  3007,  3011,  3011,  3011,  3015,  3015,  3015,  3019,
    3025,  3031,  3037,  3043,  3049,  3058,  3064,  3074,  3074,  3078,
    3082,  3083,  3094,  3095,  3101,  3111,  3121,  3131,  3132,  3135,
    3140,  3146,  3150,  3154,  3157,  3163,  3166,  3169,  3186,  3189,
    3195,  3196,  3197,  3201,  3202,  3203,  3204,  3205,  3207,  3208,
    3209,  3211,  3212,  3216,  3217,  3222,  3226,  3231,  3235,  3250,
    3254,  3249,  3262,  3265,  3279,  3283,  3289,  3278,  3302,  3303,
    3315,  3321,  3315,  3335,  3335,  3337,  3338,  3342,  3342,  3346,
    3346,  3351,  3351,  3358,  3359,  3363,  3363,  3367,  3367,  3372,
    3372,  3379,  3383,  3384,  3385,  3390,  3390,  3393,  3393,  3397,
    3397,  3401,  3401,  3405,  3405,  3410,  3410,  3415,  3415,  3420,
    3420,  3425,  3425,  3441,  3458,  3459,  3460,  3461,  3462,  3463,
    3464,  3467,  3467,  3470,  3472,  3475,  3478,  3481,  3486,  3491,
    3494,  3499,  3504,  3509,  3516,  3517,  3524,  3531,  3533,  3539,
    3544,  3549,  3554,  3554,  3557,  3563,  3568,  3571,  3578,  3578,
    3580,  3583,  3586,  3591,  3596,  3601,  3608,  3617,  3617,  3679,
    3687,  3688,  3696,  3703,  3703,  3707,  3712,  3718,  3722,  3726,
    3732,  3736,  3740,  3746,  3746,  3754,  3755,  3759,  3759,  3763,
    3764,  3767,  3770,  3770,  3773,  3775,  3775,  3778,  3780,  3780,
    3781,  3783,  3783,  3792,  3799,  3790,  3820,  3820,  3820,  3823,
    3825,  3823,  3832,  3835,  3841,  3852,  3852,  3856,  3862,  3862,
    3866,  3867,  3871,  3881,  3882,  3883,  3886,  3888,  3893,  3893,
    3897,  3896,  3904,  3903,  3910,  3910,  3916,  3916,  3923,  3923,
    3929,  3929,  3935,  3935,  3941,  3941,  3945,  3945,  3946,  3946,
    3947,  3947,  3948,  3948,  3952,  3952,  3963,  3967,  3973,  3977,
    3982,  3987,  3992,  3993,  3994,  3998,  3997,  4010,  4015,  4020,
    4020,  4036,  4042,  4043,  4044,  4045,  4048,  4048,  4051,  4058,
    4059,  4060,  4061,  4062,  4063,  4064,  4065,  4066,  4071,  4071,
    4073,  4076,  4076,  4078,  4082,  4085,  4086,  4089,  4089,  4094,
    4097,  4098,  4099,  4100,  4101,  4102,  4103,  4104,  4105,  4106,
    4107,  4108,  4109,  4110,  4111,  4112,  4113,  4114,  4118,  4136,
    4136,  4136,  4163,  4174,  4181,  4187,  4193,  4199,  4211,  4236,
    4235,  4252,  4252,  4256,  4257,  4265,  4266,  4267,  4268,  4269,
    4270,  4277,  4278,  4280,  4281,  4285,  4290,  4291,  4292,  4293,
    4294,  4295,  4296,  4297,  4298,  4299,  4300,  4303,  4305,  4305,
    4307,  4311,  4311,  4320,  4325,  4341,  4347,  4319,  4361,  4375,
    4385,  4374,  4398,  4405,  4405,  4410,  4416,  4424,  4429,  4430,
    4433,  4436,  4436,  4444,  4450,  4461,  4462,  4466,  4470,  4483,
    4465,  4501,  4501,  4515,  4526,  4525,  4537,  4533,  4550,  4547,
    4560,  4560,  4562,  4563,  4565,  4566,  4569,  4570,  4571,  4573,
    4578,  4583,  4589,  4591,  4592,  4595,  4596,  4599,  4601,  4609,
    4615,  4609,  4626,  4627,  4631,  4631,  4638,  4638,  4647,  4650,
    4653,  4656,  4660,  4664,  4665,  4666,  4667,  4668,  4672,  4677,
    4677,  4680,  4707,  4765,  4765,  4768,  4772,  4776,  4819,  4861,
    4862,  4863,  4866,  4880,  4892,  4892,  4897,  4898,  4904,  4964,
    5021,  5026,  5033,  5038,  5046,  5052,  5085,  5088,  5089,  5130,
    5173,  5174,  5178,  5179,  5183,  5236,  5240,  5243,  5249,  5260,
    5267,  5275,  5275,  5278,  5279,  5280,  5281,  5282,  5285,  5288,
    5294,  5297,  5301,  5306,  5314,  5319,  5326,  5329,  5335,  5337,
    5337,  5337,  5341,  5361,  5368,  5375,  5378,  5392,  5399,  5400,
    5403,  5404,  5408,  5414,  5419,  5425,  5426,  5431,  5435,  5435,
    5439,  5440,  5443,  5444,  5448,  5456,  5459,  5465,  5466,  5468,
    5470,  5474,  5474,  5475,  5480,  5488,  5489,  5494,  5495,  5497,
    5510,  5512,  5513,  5516,  5517,  5518,  5519,  5520,  5521,  5522,
    5523,  5524,  5525,  5526,  5527,  5528,  5529,  5530,  5531,  5532,
    5533,  5534,  5535,  5536,  5537,  5538,  5539,  5540,  5541,  5555,
    5563,  5563,  5565,  5569,  5573,  5577,  5581,  5586,  5601,  5599,
    5619,  5620,  5624,  5629,  5630,  5634,  5635,  5637,  5638,  5640,
    5640,  5649,  5658,  5658,  5668,  5669,  5674,  5675,  5678,  5691,
    5705,  5709,  5713,  5717,  5726,  5726,  5730,  5733,  5733,  5735,
    5741,  5749,  5755,  5757,  5761,  5764,  5764,  5767,  5767,  5772,
    5772,  5781,  5781,  5785,  5785,  5786,  5786,  5787,  5787,  5801,
    5801,  5821,  5822,  5823,  5824,  5825,  5826,  5829,  5829,  5835,
    5835,  5838,  5838,  5854,  5855,  5856,  5865,  5877,  5878,  5881,
    5882,  5885,  5888,  5888,  5893,  5893,  5914,  5919,  5925,  5926,
    5927,  5931,  5932,  5933,  5934,  5938,  5948,  5950,  5955,  5958,
    5963,  5969,  5976,  5983,  5992,  5999,  6006,  6013,  6020,  6029,
    6029,  6031,  6031,  6034,  6035,  6036,  6037,  6038,  6039,  6040,
    6041,  6042,  6043,  6046,  6046,  6049,  6050,  6051,  6052,  6055,
    6055,  6058,  6058,  6061,  6062,  6063,  6064,  6065,  6066,  6067,
    6068,  6070,  6071,  6072,  6073,  6075,  6076,  6077,  6078,  6080,
    6081,  6082,  6083,  6084,  6085,  6086,  6087,  6091,  6098,  6107,
    6119,  6128,  6139,  6143,  6147,  6153,  6118,  6166,  6169,  6177,
    6189,  6191,  6196,  6204,  6214,  6217,  6221,  6229,  6195,  6238,
    6242,  6246,  6250,  6242,  6260,  6261,  6262,  6263,  6268,  6270,
    6273,  6277,  6280,  6287,  6292,  6293,  6294,  6295,  6300,  6301,
    6307,  6307,  6307,  6312,  6312,  6312,  6320,  6321,  6325,  6326,
    6331,  6332,  6333,  6334,  6335,  6338,  6340,  6340,  6343,  6344,
    6348,  6349,  6352,  6353,  6356,  6359,  6362,  6368,  6369,  6381,
    6382,  6387,  6388,  6389,  6393,  6396,  6402,  6405,  6413,  6414,
    6420,  6424,  6428,  6434,  6437,  6446,  6449,  6452,  6455,  6458,
    6461,  6464,  6471,  6474,  6481,  6484,  6490,  6493,  6500,  6503,
    6510,  6511,  6516,  6520,  6523,  6529,  6532,  6538,  6545,  6546,
    6550,  6560,  6563,  6569,  6571,  6576,  6577,  6581,  6583,  6589,
    6590,  6603,  6615,  6616,  6617,  6618,  6619,  6620,  6621,  6622,
    6623,  6626,  6629,  6635,  6635,  6641,  6641,  6652,  6665,  6675,
    6675,  6680,  6680,  6684,  6688,  6689,  6695,  6696,  6701,  6705,
    6712,  6715,  6722,  6721,  6732,  6736,  6740,  6747,  6750,  6750,
    6763,  6767,  6767,  6782,  6784,  6786,  6788,  6790,  6792,  6794,
    6796,  6802,  6812,  6819,  6824,  6825,  6829,  6832,  6833,  6836,
    6837,  6838,  6841,  6846,  6853,  6854,  6860,  6872,  6873,  6874,
    6877,  6877,  6882,  6887,  6892,  6893,  6896,  6897,  6902,  6907,
    6911,  6916,  6917,  6921,  6928,  6929,  6930,  6931,  6936,  6937,
    6938,  6941,  6942,  6943,  6947,  6948,  6949,  6953,  6954,  6958,
    6959,  6960,  6961,  6962,  6963,  6966,  6967,  6972,  6973,  6978,
    6979,  6984,  6985,  6990,  6995,  6996,  7001,  7002,  7006,  7007,
    7012,  7019,  7024,  7029,  7033,  7034,  7039,  7040,  7046,  7047,
    7048,  7053,  7054,  7060,  7063,  7066,  7073,  7074,  7075,  7076,
    7090,  7095,  7096,  7099,  7101,  7108,  7111,  7117,  7125,  7129,
    7133,  7137,  7141,  7144,  7147,  7154,  7161,  7166,  7170,  7171,
    7177,  7180,  7191,  7198,  7204,  7207,  7214,  7221,  7227,  7228,
    7234,  7235,  7236,  7239,  7240,  7245,  7245,  7249,  7257,  7258,
    7261,  7264,  7269,  7270,  7275,  7278,  7284,  7287,  7293,  7296,
    7302,  7305,  7312,  7313,  7342,  7343,  7348,  7356,  7361,  7364,
    7367,  7370,  7376,  7377,  7381,  7384,  7387,  7388,  7393,  7396,
    7399,  7402,  7405,  7408,  7411,  7414,  7419,  7425,  7426,  7427,
    7428,  7429,  7431,  7432,  7434,  7435,  7440,  7443,  7447,  7453,
    7454,  7455,  7456,  7468,  7469,  7470,  7474,  7475,  7479,  7480,
    7481,  7482,  7483,  7485,  7487,  7488,  7489,  7490,  7491,  7492,
    7493,  7494,  7496,  7498,  7500,  7501,  7503,  7504,  7506,  7507,
    7508,  7509,  7511,  7515,  7516,  7522,  7524,  7525,  7526,  7527,
    7532,  7536,  7540,  7544,  7551,  7555,  7556,  7557,  7565,  7566,
    7567,  7578,  7585,  7590,  7591,  7592,  7600,  7601,  7602,  7619,
    7628,  7629,  7630,  7634,  7637,  7642,  7647,  7652,  7660,  7664,
    7669,  7670,  7678,  7681,  7684,  7698,  7712,  7725,  7726,  7730,
    7730,  7730,  7730,  7730,  7730,  7731,  7734,  7739,  7739,  7739,
    7739,  7739,  7739,  7741,  7744,  7750,  7750,  7750,  7750,  7750,
    7750,  7750,  7751,  7751,  7751,  7751,  7751,  7751,  7751,  7751,
    7754,  7755,  7756,  7759,  7768,  7768,  7774,  7774,  7781,  7781,
    7787,  7787,  7795,  7796,  7797,  7800,  7800,  7803,  7804,  7805,
    7816,  7819,  7825,  7830,  7837,  7850,  7851,  7848,  7869,  7880,
    7883,  7888,  7900,  7903,  7907,  7910,  7911,  7917,  7920,  7921,
    7930,  7939,  7944,  7945,  7946,  7947,  7954,  7957,  7963,  7966,
    7976,  7985,  7988,  7991,  7997,  8003,  8006,  8007,  8008,  8009,
    8010,  8013,  8019,  8021,  8023,  8025,  8027,  8029,  8030,  8031,
    8032,  8033,  8034,  8035,  8037,  8039,  8041,  8043,  8045,  8047,
    8049,  8050,  8052,  8053,  8059,  8060,  8067,  8070,  8078,  8082,
    8089,  8089,  8093,  8093,  8098,  8098,  8102,  8102,  8106,  8112,
    8112,  8115,  8115,  8121,  8128,  8129,  8130,  8134,  8135,  8138,
    8139,  8143,  8149,  8159,  8160,  8168,  8169,  8170,  8171,  8172,
    8173,  8177,  8178,  8179,  8180,  8184,  8185,  8189,  8190,  8191,
    8192,  8193,  8194,  8195,  8197,  8201,  8202,  8203,  8207,  8208,
    8209,  8210,  8211,  8212,  8215,  8215,  8227,  8228,  8232,  8233,
    8234,  8235,  8236,  8237,  8238,  8239,  8240,  8241,  8242,  8243,
    8244,  8245,  8246,  8247,  8248,  8249,  8250,  8251,  8252,  8253,
    8254,  8255,  8256,  8257,  8258,  8259,  8260,  8261,  8262,  8263,
    8264,  8265,  8266,  8267,  8268,  8269,  8270,  8271,  8272,  8273,
    8274,  8275,  8276,  8277,  8278,  8279,  8280,  8281,  8282,  8283,
    8284,  8285,  8286,  8287,  8288,  8289,  8290,  8291,  8292,  8293,
    8294,  8295,  8296,  8297,  8298,  8299,  8300,  8301,  8302,  8303,
    8304,  8305,  8306,  8307,  8308,  8309,  8310,  8311,  8312,  8313,
    8314,  8315,  8316,  8317,  8318,  8319,  8320,  8321,  8322,  8323,
    8324,  8325,  8326,  8327,  8328,  8329,  8330,  8331,  8332,  8333,
    8334,  8335,  8336,  8337,  8338,  8339,  8340,  8341,  8342,  8343,
    8344,  8345,  8346,  8347,  8348,  8349,  8350,  8351,  8352,  8353,
    8354,  8355,  8356,  8357,  8358,  8359,  8360,  8361,  8362,  8363,
    8364,  8365,  8366,  8367,  8368,  8369,  8370,  8371,  8372,  8373,
    8374,  8375,  8376,  8377,  8378,  8379,  8380,  8381,  8382,  8383,
    8384,  8385,  8386,  8387,  8388,  8389,  8390,  8391,  8392,  8393,
    8394,  8395,  8396,  8397,  8398,  8399,  8400,  8401,  8402,  8403,
    8404,  8405,  8406,  8407,  8408,  8409,  8410,  8411,  8412,  8413,
    8414,  8415,  8416,  8417,  8418,  8419,  8420,  8421,  8422,  8423,
    8424,  8425,  8426,  8427,  8428,  8429,  8430,  8431,  8432,  8433,
    8434,  8435,  8437,  8438,  8439,  8440,  8441,  8442,  8443,  8444,
    8445,  8446,  8447,  8448,  8449,  8450,  8451,  8452,  8453,  8454,
    8455,  8456,  8457,  8458,  8459,  8460,  8461,  8462,  8463,  8464,
    8465,  8466,  8467,  8468,  8469,  8470,  8471,  8472,  8473,  8474,
    8475,  8476,  8477,  8478,  8479,  8480,  8481,  8482,  8483,  8484,
    8485,  8486,  8487,  8488,  8489,  8490,  8491,  8492,  8493,  8494,
    8495,  8496,  8497,  8498,  8499,  8500,  8501,  8502,  8503,  8504,
    8505,  8506,  8507,  8508,  8509,  8510,  8511,  8512,  8513,  8514,
    8515,  8516,  8517,  8518,  8519,  8520,  8521,  8522,  8523,  8524,
    8525,  8526,  8527,  8528,  8529,  8530,  8531,  8532,  8533,  8534,
    8535,  8536,  8537,  8538,  8539,  8540,  8541,  8542,  8543,  8544,
    8545,  8546,  8547,  8548,  8549,  8550,  8551,  8559,  8559,  8566,
    8566,  8654,  8658,  8654,  8667,  8671,  8677,  8685,  8695,  8705,
    8717,  8720,  8739,  8765,  8768,  8774,  8777,  8782,  8785,  8793,
    8801,  8814,  8817,  8825,  8828,  8831,  8839,  8843,  8846,  8849,
    8852,  8856,  8857,  8858,  8859,  8860,  8866,  8867,  8868,  8869,
    8870,  8871,  8872,  8873,  8874,  8875,  8876,  8877,  8878,  8879,
    8880,  8881,  8886,  8892,  8893,  8901,  8901,  8909,  8909,  8913,
    8917,  8932,  8952,  8954,  8960,  8961,  8962,  8963,  8973,  8974,
    8975,  8980,  9006,  9062,  9076,  9079,  9075,  9098,  9098,  9104,
    9105,  9108,  9109,  9110,  9111,  9112,  9113,  9114,  9125,  9128,
    9133,  9137,  9142,  9146,  9151,  9155,  9158,  9162,  9165,  9170,
    9174,  9185,  9191,  9191,  9192,  9193,  9200,  9210,  9210,  9212,
    9213,  9214,  9215,  9216,  9217,  9218,  9219,  9220,  9221,  9222,
    9223,  9224,  9225,  9226,  9227,  9228,  9229,  9230,  9231,  9232,
    9233,  9234,  9235,  9236,  9237,  9238,  9239,  9240,  9241,  9242,
    9243,  9244,  9245,  9246,  9247,  9248,  9249,  9250,  9251,  9252,
    9253,  9254,  9255,  9256,  9257,  9258,  9259,  9260,  9261,  9262,
    9263,  9264,  9265,  9266,  9267,  9268,  9269,  9270,  9271,  9272,
    9273,  9274,  9275,  9276,  9277,  9278,  9279,  9280,  9281,  9282,
    9283,  9284,  9285,  9286,  9287,  9288,  9289,  9290,  9291,  9292,
    9293,  9294,  9295,  9296,  9297,  9298,  9299,  9300
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
  "RESIZE_ARRAY", "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", 
  "CONCAT_PIPES", "BEFORE_DELETE", "DROP_TRIGGER", "AFTER_INSERT", 
  "AFTER_DELETE", "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", 
  "INSERT_ROW_EQUAL_TRUE", "DELETE_ROW_EQUAL_FALSE", 
  "INSERT_ROW_EQUAL_FALSE", "AFTER_INSERT_DELETE", "BEFORE_INSERT_DELETE", 
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
  "array_r_variable", "array_r_variable_or_ident", "arr_subscripts", 
  "num_list", "num_list_element", "let_variable", "let_var", 
  "let_var_dot", "let_array_r_variable", "op_param_var_list", 
  "fparam_var_list", "ibind_var_list", "func_def_var", "ibind_var", 
  "obind_var_list", "obind_var", "obind_var_let_list", "obind_let_var", 
  "use_arr_var", "obind_var_list_ord", "obind_var_ord", 
  "optional_asc_desc", "array_r_varid", "init_bind_var_list", 
  "init_bind_var", "open_window_cmd", "op_at_statusbox", 
  "op_size_statusbox", "open_statusbox_cmd", "formhandler_name", 
  "open_form_cmd", "open_form_rest", "open_form_gui", "op_at_gui", 
  "op_like_gui", "op_absolute", "open_session_cmd", "open_cursor_cmd", 
  "user_details", "op_disable", "connect_cmd", "op_connect_as", 
  "con_user_details", "options_cmd", "opt_options", "opt_allopts", 
  "prepare_cmd", "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", 
  "@131", "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@132", "prompt_title", 
  "put_cmd", "@133", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@134", "@135", "@136", "@137", "@138", "@139", "@140", 
  "report_cmd", "need_command", "@141", "op_lines", "skip_command", 
  "@142", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "@143", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@144", "@145", "@146", "@147", "@148", 
  "@149", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@150", "@151", "@152", "@153", "@154", "@155", "pdf_report_section", 
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
  "@180", "validate_tab_list", "validate_tab", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind_ss", "whenever_cmd", "while_cmd", 
  "@181", "@182", "op_clr_fields", "op_to_defs", "clear_cmd", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@183", "commands_all1", 0
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
    1172,  1172,  1173,  1173,  1174,  1175,  1176,  1176,  1176,  1176,
    1176,  1176,  1177,  1177,  1178,  1179,  1179,  1180,  1180,  1181,
    1181,  1182,  1182,  1183,  1183,  1183,  1183,  1183,  1184,  1184,
    1185,  1185,  1186,  1186,  1187,  1188,  1189,  1189,  1190,  1191,
    1191,  1191,  1192,  1193,  1193,  1194,  1194,  1195,  1196,  1196,
    1197,  1197,  1198,  1199,  1200,  1201,  1201,  1202,  1203,  1203,
    1204,  1204,  1205,  1205,  1206,  1207,  1207,  1208,  1208,  1208,
    1208,  1209,  1209,  1209,  1210,  1211,  1211,  1212,  1212,  1212,
    1213,  1214,  1214,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1216,
    1217,  1217,  1218,  1218,  1218,  1218,  1218,  1219,  1221,  1220,
    1222,  1222,  1223,  1224,  1224,  1225,  1225,  1226,  1226,  1228,
    1227,  1229,  1231,  1230,  1232,  1232,  1233,  1233,  1234,  1234,
    1235,  1235,  1235,  1235,  1236,  1236,  1237,  1238,  1238,  1239,
    1240,  1241,  1242,  1243,  1243,  1244,  1244,  1246,  1245,  1247,
    1245,  1248,  1245,  1249,  1245,  1250,  1245,  1251,  1245,  1252,
    1245,  1253,  1253,  1253,  1253,  1253,  1253,  1255,  1254,  1256,
    1256,  1258,  1257,  1257,  1257,  1257,  1257,  1259,  1259,  1260,
    1260,  1261,  1262,  1262,  1264,  1263,  1265,  1266,  1267,  1267,
    1267,  1268,  1268,  1268,  1268,  1269,  1270,  1270,  1271,  1271,
    1272,  1273,  1273,  1273,  1273,  1273,  1273,  1273,  1273,  1274,
    1274,  1275,  1275,  1276,  1276,  1276,  1276,  1276,  1276,  1276,
    1276,  1276,  1276,  1277,  1277,  1278,  1278,  1278,  1278,  1279,
    1279,  1280,  1280,  1281,  1281,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1282,  1282,  1282,
    1284,  1285,  1286,  1287,  1288,  1289,  1283,  1290,  1290,  1291,
    1292,  1292,  1294,  1295,  1296,  1297,  1298,  1299,  1293,  1300,
    1302,  1303,  1304,  1301,  1305,  1305,  1305,  1305,  1306,  1306,
    1306,  1306,  1306,  1307,  1308,  1308,  1308,  1308,  1309,  1309,
    1311,  1312,  1310,  1313,  1314,  1310,  1315,  1315,  1316,  1316,
    1317,  1317,  1317,  1317,  1317,  1318,  1319,  1319,  1320,  1320,
    1321,  1321,  1322,  1322,  1322,  1322,  1322,  1323,  1323,  1324,
    1324,  1325,  1325,  1325,  1326,  1326,  1327,  1327,  1328,  1328,
    1329,  1329,  1329,  1330,  1330,  1331,  1331,  1331,  1331,  1331,
    1331,  1331,  1332,  1332,  1333,  1333,  1334,  1334,  1335,  1335,
    1336,  1336,  1337,  1338,  1338,  1339,  1339,  1340,  1341,  1341,
    1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,  1346,  1347,
    1347,  1348,  1349,  1349,  1349,  1349,  1349,  1349,  1349,  1349,
    1349,  1349,  1349,  1350,  1350,  1351,  1351,  1352,  1353,  1355,
    1354,  1357,  1356,  1356,  1358,  1358,  1359,  1359,  1360,  1360,
    1361,  1361,  1363,  1362,  1364,  1365,  1365,  1366,  1367,  1366,
    1368,  1369,  1368,  1370,  1370,  1370,  1370,  1370,  1370,  1370,
    1370,  1371,  1372,  1373,  1374,  1374,  1375,  1376,  1376,  1377,
    1377,  1377,  1378,  1379,  1380,  1380,  1381,  1382,  1382,  1382,
    1384,  1383,  1385,  1385,  1385,  1385,  1385,  1385,  1385,  1385,
    1385,  1385,  1385,  1385,  1386,  1386,  1386,  1386,  1387,  1387,
    1387,  1388,  1388,  1388,  1389,  1389,  1389,  1390,  1390,  1391,
    1391,  1391,  1391,  1391,  1391,  1392,  1392,  1393,  1393,  1394,
    1394,  1395,  1395,  1396,  1397,  1397,  1398,  1398,  1399,  1399,
    1400,  1401,  1402,  1403,  1404,  1404,  1405,  1405,  1406,  1406,
    1406,  1407,  1407,  1408,  1408,  1408,  1409,  1409,  1409,  1409,
    1410,  1411,  1411,  1412,  1412,  1413,  1413,  1414,  1415,  1415,
    1415,  1415,  1415,  1415,  1415,  1416,  1417,  1418,  1419,  1419,
    1420,  1420,  1421,  1422,  1423,  1423,  1424,  1425,  1426,  1426,
    1427,  1427,  1427,  1428,  1428,  1429,  1429,  1430,  1431,  1431,
    1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,  1436,  1436,
    1437,  1437,  1438,  1438,  1439,  1439,  1440,  1441,  1442,  1442,
    1442,  1442,  1443,  1443,  1444,  1444,  1445,  1445,  1446,  1446,
    1446,  1446,  1446,  1446,  1446,  1446,  1446,  1447,  1447,  1447,
    1447,  1447,  1447,  1447,  1447,  1447,  1448,  1448,  1448,  1449,
    1449,  1449,  1449,  1450,  1450,  1450,  1451,  1451,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1453,  1453,  1454,  1454,  1454,  1454,  1454,
    1455,  1456,  1457,  1458,  1458,  1458,  1458,  1458,  1458,  1458,
    1458,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1460,
    1461,  1461,  1461,  1462,  1462,  1463,  1463,  1463,  1464,  1465,
    1465,  1465,  1465,  1466,  1467,  1468,  1468,  1469,  1469,  1470,
    1470,  1470,  1470,  1470,  1470,  1470,  1470,  1471,  1471,  1471,
    1471,  1471,  1471,  1471,  1471,  1472,  1472,  1472,  1472,  1472,
    1472,  1472,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1474,  1474,  1474,  1475,  1477,  1476,  1478,  1476,  1479,  1476,
    1480,  1476,  1481,  1481,  1481,  1482,  1482,  1483,  1483,  1483,
    1484,  1484,  1485,  1485,  1486,  1488,  1489,  1487,  1490,  1491,
    1491,  1492,  1493,  1493,  1493,  1493,  1493,  1494,  1495,  1495,
    1496,  1497,  1498,  1498,  1498,  1498,  1499,  1499,  1500,  1500,
    1501,  1502,  1502,  1502,  1503,  1503,  1503,  1503,  1503,  1503,
    1503,  1503,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1504,  1504,  1504,  1505,  1505,  1506,  1507,  1508,  1508,
    1509,  1509,  1510,  1510,  1511,  1511,  1512,  1512,  1513,  1514,
    1514,  1515,  1515,  1516,  1517,  1517,  1517,  1518,  1518,  1519,
    1520,  1521,  1522,  1523,  1523,  1524,  1524,  1524,  1524,  1524,
    1524,  1525,  1525,  1525,  1525,  1526,  1526,  1527,  1527,  1527,
    1527,  1527,  1527,  1527,  1527,  1528,  1528,  1528,  1529,  1529,
    1529,  1529,  1529,  1529,  1531,  1530,  1532,  1532,  1533,  1533,
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
    1550,  1550,  1550,  1550,  1550,  1550,  1551,  1551,  1551,  1551,
    1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,  1551,
    1551,  1551,  1552,  1553,  1553,  1555,  1554,  1556,  1556,  1557,
    1557,  1558,  1559,  1559,  1560,  1560,  1560,  1560,  1561,  1561,
    1561,  1562,  1562,  1563,  1565,  1566,  1564,  1567,  1567,  1568,
    1568,  1569,  1569,  1569,  1569,  1569,  1569,  1569,  1570,  1570,
    1571,  1571,  1572,  1572,  1573,  1573,  1574,  1575,  1576,  1577,
    1577,  1578,  1579,  1579,  1580,  1581,  1581,  1583,  1582,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1584,  1584,  1584,  1584
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
       1,     1,     4,     4,     1,     1,     1,     1,     2,     2,
       3,     6,     1,     3,     1,     1,     1,     3,     6,     9,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     2,     0,
       1,     1,     4,     1,     3,     1,     3,     7,     0,     7,
       0,     6,     3,     1,     3,     1,     2,     5,     0,     7,
       0,     2,     0,     1,     5,     2,     5,     0,     5,     6,
       4,     0,     1,     1,     5,     0,     2,     0,     5,     4,
       2,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     5,
       1,     1,     2,     4,     4,     6,     2,     1,     0,    11,
       0,     2,     5,     0,     1,     0,     2,     1,     2,     0,
       3,     1,     0,     4,     0,     2,     1,     3,     1,     1,
       3,     4,     4,     2,     1,     1,     1,     0,     1,     7,
       2,     2,     2,     2,     2,     1,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       1,     0,     4,     1,     2,     2,     2,     0,     1,     1,
       2,     2,     0,     2,     0,     4,     3,     5,     0,     2,
       4,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       2,     5,     2,     5,     5,     5,     5,     5,     5,     0,
       2,     1,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     0,     3,     2,
       0,     0,     0,     0,     0,     0,    15,     0,     2,     2,
       0,     1,     0,     0,     0,     0,     0,     0,    15,     2,
       0,     0,     0,    10,     0,     1,     3,     3,     2,     4,
       3,     3,     3,     1,     2,     2,     2,     2,     1,     1,
       0,     0,     8,     0,     0,     9,     0,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     0,     1,     1,     2,
       2,     2,     8,     2,     2,     4,     2,     0,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     1,     2,     1,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     1,     3,     1,     3,     2,     4,
       1,     3,     1,     2,     4,     1,     3,     1,     1,     1,
       2,     3,     4,     2,     4,     0,     2,     2,     4,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     6,     6,     0,     1,     0,     1,     2,     1,     0,
       5,     0,     5,     1,     0,     3,     1,     3,     1,     3,
       1,     1,     0,     4,     1,     2,     1,     0,     0,     3,
       0,     0,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     3,     3,     1,     3,     2,     1,     1,     0,
       1,     1,     1,     1,     0,     1,     3,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     6,     4,     4,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     1,     3,     2,
       1,     1,     2,     1,     1,     0,     3,     1,     3,     1,
       3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
       4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       4,     0,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     3,     2,     2,     1,     3,
       1,     2,     4,     1,     2,     1,     3,     4,     0,     1,
       0,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     0,     2,     1,     1,     5,     3,
       5,     3,     1,     3,     1,     1,     0,     1,     3,     3,
       3,     6,     4,     4,     4,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     1,
       4,     1,     5,     5,     1,     1,     1,     1,     1,     4,
       1,     4,     6,     4,     1,     4,     1,     7,     1,     1,
       1,     4,     6,     0,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     5,     3,     5,
       7,     3,     1,     1,     3,     5,     3,     5,     7,     1,
       0,     3,     5,     1,     2,     2,     4,     3,     1,     1,
       1,     1,     1,     2,     2,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     0,     7,     0,     8,     0,     6,
       0,     8,     0,     1,     2,     1,     3,     1,     3,     5,
       1,     1,     1,     1,     1,     0,     0,     9,     5,     1,
       1,     6,     0,     3,     1,     3,     4,     1,     0,     2,
       4,     6,     0,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     4,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     5,     5,     4,     4,
       3,     4,     1,     1,     1,     3,     1,     5,     7,     5,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     5,     1,     4,     4,     4,     6,
       6,     8,     8,    13,    11,     1,     7,     4,     4,     4,
       6,     6,     8,     8,     0,     4,     1,     2,     1,     1,
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
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       3,     5,     5,     5,     5,     5,     4,     4,     3,     4,
       1,     1,     1,     1,     3,     0,     5,     1,     3,     3,
       3,     1,     2,     1,     1,     1,     3,     5,     1,     1,
       1,     1,     3,     1,     0,     0,     6,     0,     2,     0,
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
     821,     0,  2223,     0,     0,     0,   871,   181,     0,   847,
     850,   179,   184,   825,     0,   819,   822,   823,   826,   829,
     830,   828,   867,   868,   870,   827,   136,   133,     0,   129,
     131,   130,   134,  2251,   704,   644,   311,  1682,  1680,   865,
     177,   187,   866,   180,     1,   831,   824,   869,   128,   132,
     135,     0,     0,   621,     0,     0,   178,   874,   940,   622,
     875,   876,   872,   656,   932,     0,   933,   941,   939,   187,
     182,   200,     0,   185,   201,   236,     0,   852,  1232,     0,
       0,   851,   137,  1220,   859,     0,     0,   843,   845,   842,
     844,   820,   832,   833,   853,   836,   837,   838,   841,   839,
     840,   846,     0,  1681,   934,   873,     0,     0,   948,   946,
     947,   936,   935,   309,   187,  1156,   194,   188,   187,   193,
     233,     0,   703,     0,     0,     0,     0,   177,   570,   909,
     834,     0,   343,   329,   203,   315,   280,   299,   320,   322,
     319,     0,   341,     0,   328,   321,   325,   331,   330,   187,
     332,   312,   335,   313,   314,   945,   944,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     954,     0,   528,   520,    16,   527,   940,    15,     0,   952,
       0,   310,     0,   186,  1157,   183,     0,   200,   202,   274,
     205,   262,   268,   269,   253,   226,   264,   203,   241,   242,
       0,   228,   280,   299,   251,   254,   249,     0,   224,     0,
     260,   252,   257,   267,   266,   187,   270,   187,   239,   240,
     237,   273,     0,     0,     0,     0,   860,   177,   177,     0,
       0,   204,     0,     0,   333,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,   278,     0,   942,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     534,     0,     0,     0,   657,   445,   447,  1227,     0,     0,
       0,  1647,     0,   439,     0,     0,     0,   438,     0,   455,
     530,     0,     0,     0,     0,     0,   533,     0,   404,   403,
     410,   451,   448,   405,   406,   408,   409,   446,   449,   454,
     529,   500,   497,   506,   503,     0,     0,    17,    18,    19,
      20,    21,     0,    14,   491,     0,     0,   950,     0,   189,
     192,   190,   191,     0,   197,   196,   195,   198,   206,   207,
     208,   211,   275,   187,   275,     0,     0,     0,     0,   187,
     271,   272,     0,     0,   187,     0,   275,     0,     0,   250,
     234,  1233,     0,     0,  1221,  2257,   571,   910,   854,     0,
     215,   216,     0,     0,   292,   294,   289,   290,   286,   288,
     285,   287,   284,     0,   294,   305,   306,   302,   304,   301,
     303,   296,     0,     0,     0,   345,     0,   348,   350,   223,
       0,   222,     0,   187,     0,     0,   555,   626,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   538,   543,     0,
     539,   542,   541,   635,     0,   634,   557,     0,    11,   173,
     437,   412,   411,     0,  1162,     0,     0,   453,  1655,  1653,
    1654,  1650,  1652,  1649,  1651,  1643,     0,     0,     0,   452,
       0,     0,     0,     0,     0,     0,     0,   658,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   535,   536,   537,   466,     0,     0,   465,   475,     0,
       0,   416,     0,     0,   417,   407,   413,   415,   418,   419,
     420,   421,   422,   414,   444,   443,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   953,     0,   937,   199,
       0,     0,   263,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,   187,   235,   238,   965,
     702,   877,   965,     0,  2255,  2257,  1156,  1781,   848,     0,
     965,     0,     0,   316,   281,     0,     0,   291,   308,   282,
     307,     0,   300,     0,   323,     0,   317,     0,   342,     0,
     347,   337,     0,     0,   326,   279,   336,     0,     0,   526,
       0,     0,   523,   522,   525,   521,   532,   517,     0,   517,
       0,   540,     0,   544,     0,   299,     0,   524,   531,   283,
       0,  1228,  1722,     0,     0,     0,     0,     0,   440,     0,
       0,   456,     0,     0,     0,     0,   458,   457,   476,   467,
     482,   485,   486,   483,   489,   488,   487,   477,   478,   479,
     480,   481,   423,   468,   472,   490,   484,   471,   490,   450,
     501,   498,   507,   504,   515,     0,    98,   492,    94,    95,
      97,   494,     0,     0,   236,     0,     0,     0,   243,   244,
       0,   247,     0,     0,   255,     0,   245,   225,   209,     0,
     258,   277,   971,     0,   966,   967,   965,     0,   861,  2256,
    2254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2238,     0,  1348,  1347,
       0,  1349,     0,   397,  1346,  1263,     0,     5,  1345,   398,
     395,     0,   400,   175,   490,  1133,     0,     0,  1355,   125,
     394,   393,     0,     0,   388,   490,     0,  1299,  2231,     0,
     399,   362,     0,     3,     2,     0,   396,  1260,     0,     0,
     389,   386,   401,     0,     0,     0,     0,  1353,  1343,   392,
       0,     0,     0,     0,     0,     0,     0,     0,  1342,     0,
       0,     0,   176,     0,   385,   384,     0,     0,  2235,  2234,
       0,     0,     0,   138,     0,   391,   390,     0,     0,   387,
     490,     0,     0,   490,     0,   564,     0,     0,     0,     0,
       0,     0,   490,   808,  1230,     0,     0,  1144,     0,  2224,
       0,   105,     0,     0,   881,     0,     0,     0,     0,   809,
       0,     0,  1824,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   673,     0,     0,  2259,  2260,  2261,  2262,  2263,
    2264,  2265,  2266,  2267,  2268,  2269,  2270,  2271,  2272,  2273,
    2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,  2282,  2283,
    2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,  2292,  2293,
    2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,
    2304,  2305,  2306,  2307,  2308,   919,  2309,  2310,  2311,  2312,
    2313,  2314,  2315,  2316,  2317,  2318,  2319,  2320,  2321,  2322,
    2323,  2324,  2325,  1124,  1126,  1121,  1123,  1122,  1125,  2326,
    2327,  1253,  2328,  1259,  1258,  2329,  2330,  2331,  2332,  2333,
    2334,  2335,  2336,  2337,  2338,  1410,  2339,  2340,  2341,  2342,
    2343,  2344,  2345,  2346,  2347,  2258,   849,   575,     0,   914,
       0,   912,     0,   344,   217,   218,     0,   293,   298,     0,
       0,     0,     0,   346,   349,     0,   221,     0,     0,   556,
       0,   630,     0,   632,   510,     0,     0,   511,     0,   554,
       0,   551,   548,   519,   509,   558,     0,   172,  1724,  1725,
    1723,     0,   442,  1227,     0,  1648,  1227,   441,  1227,  1227,
    1227,  1227,  1227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,   951,
       0,   212,   276,   227,     0,     0,   187,     0,     0,     0,
       0,     0,  1234,     0,     0,  1222,   381,   379,   380,  1257,
    1061,  1060,  1066,     0,  1622,  1623,     0,     0,  1283,   645,
     646,  1284,  1614,  1615,  1286,   835,  1096,  1101,  2233,   638,
     124,  2246,     0,     0,  1298,     7,     0,     6,     0,  2239,
    1097,     0,  1190,  1189,  1136,  1188,  1135,   434,  1356,  1344,
       0,  1254,   862,   424,  1783,  1350,   126,     0,  1100,   123,
       0,   815,    24,   640,   402,     0,   814,  1093,   816,     0,
    1354,   903,   902,   905,   901,   904,  2248,     0,   899,     0,
     639,   998,   900,  2242,     0,  2232,   122,  1256,   995,   705,
     993,     0,   636,  2227,   753,   752,   754,   750,     0,     0,
    1255,  1008,   641,  1409,     0,  2215,  2214,  1404,  1407,  2211,
    2213,     0,     0,     0,     0,  1067,  1062,     0,  1047,  1048,
    1049,  1050,  1056,  1058,  1057,  1055,  1054,     0,     0,     0,
    1053,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1039,  1030,  1031,   980,     0,   978,
    1081,   432,    24,     0,  2229,   127,   637,     0,  1231,  1229,
    1155,     0,  1772,  1773,  1156,  1137,  1357,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,   940,     0,    69,
       0,   103,   613,     0,   660,   659,     0,  1127,  1015,  1131,
       0,     0,  1082,  1248,     0,     0,  1134,   665,   662,   663,
       0,   667,   668,     0,   670,   671,     0,   666,   975,   977,
       0,     0,   976,   755,   973,   716,   969,   931,     0,     0,
       0,     0,   677,   678,     0,     0,   929,   926,   927,   923,
     924,   925,   918,   922,   921,     0,     0,     0,     0,     0,
       0,   579,   581,   573,   576,   577,   916,  2257,   911,   913,
     855,     0,   295,   297,   324,   318,     0,     0,   327,   627,
     629,     0,     0,     0,   517,   517,   545,     0,   292,     0,
       0,  1751,  1639,  1641,  1752,     0,     0,  1645,  1749,     0,
       0,  1748,     0,     0,     0,  1750,     0,     0,     0,     0,
       0,     0,     0,  2215,  1640,  1747,  1642,  1736,     0,  1726,
    1728,  1731,  1734,  1762,  1805,  1763,  1815,  2221,  1735,  1165,
    1656,  1164,  1163,  1166,  1168,  1167,  1161,   469,   470,   474,
     459,     0,   462,   473,     0,   461,   502,   499,   508,   505,
     516,   493,    96,   495,   938,     0,   248,   232,     0,   230,
     256,   246,   236,   259,   972,   177,   968,   878,   177,     0,
       0,     0,  1328,  1329,     0,     0,     0,  1300,  1303,  1305,
    1306,  1307,  1311,  1310,  1308,  1309,     0,     0,     0,  1301,
    1302,     0,     0,     0,     0,     0,     0,     0,     0,  1098,
       0,    24,  1185,  1187,  1186,     0,   427,   428,   425,   426,
     985,     0,     0,   367,    25,   361,     0,     0,  1090,     0,
       0,     0,     0,     0,     0,     0,  1002,  1782,     0,     0,
       0,     0,     0,     0,  2229,     0,     0,   139,     0,     0,
    1012,  1004,  1005,  1010,     0,     0,  2212,   949,  1405,  1406,
       0,     0,   928,   430,  2205,  1025,   351,     0,     0,   565,
     618,   617,   615,   620,  1033,   619,  1038,  1034,  1037,   807,
     799,   793,   805,   806,   791,   792,   800,   795,   801,   794,
     804,   798,   802,   797,   803,   790,   796,   783,   789,  1035,
    1036,     0,  1043,  1051,  1040,  1041,  1045,  1046,  1044,  1042,
    1052,     0,     0,     0,   817,     0,     0,     0,     0,     0,
     765,   764,   761,  2230,  2237,    24,  1151,  1152,  1153,  1154,
    1148,  1146,  1244,  1156,  1138,  1139,  1142,  1158,  2225,     0,
       0,     0,     0,    99,     0,   100,     0,     0,     0,    74,
       0,     0,     0,   112,   107,     0,   661,   908,     0,   907,
       0,   490,  1129,     0,   960,   961,   984,   955,   956,   810,
     982,  1084,  1250,     0,  1252,  1251,  1880,  1997,  1993,  1999,
    2031,  2011,  2002,  1961,  1923,  2050,  2017,  2025,  1914,  2020,
    1881,  1828,  2012,  1919,  1970,  2104,  1949,  1937,  1950,  2048,
    2051,  2019,  1973,  2054,  1840,  2111,  2047,  2075,  1851,  2147,
    1938,  2120,  1833,  2080,  1849,  1909,  1956,  1976,  2070,  2098,
    2103,  1832,  2028,  2056,  1844,  1846,  1869,  1887,  1907,  1917,
    1927,  1980,  1983,  2041,  2052,  2058,  2059,  2076,  2121,  2132,
    1831,  1862,  1886,  1885,  1893,  1895,  1903,  1913,  1934,  1952,
    1955,  1981,  1989,  2045,  2055,  2065,  2071,  2072,  2074,  2099,
    2129,  2140,  1852,  1855,  1866,  1872,  1874,  1879,  1882,  1884,
    1890,  1898,  1900,  1901,  1902,  1912,  1922,  1929,  1945,  1946,
    1957,  1975,  1979,  1992,  2008,  2039,  2049,  2053,  2060,  2068,
    2077,  2087,  2091,  2108,  2114,  2118,  2126,  2131,  2134,  1875,
    1994,  2036,  1860,  1861,  1878,  1883,  1889,  1891,  1905,  1906,
    1916,  1925,  1930,  1932,  1933,  1939,  1947,  1964,  1965,  1978,
    2006,  2010,  2013,  2018,  2022,  2030,  2037,  2038,  2043,  2061,
    2062,  2067,  2073,  2078,  2084,  2085,  2086,  2088,  2090,  2092,
    2101,  2123,  2124,  2125,  2130,  2146,  1835,  1988,  1996,  1998,
    2094,  1837,  1841,  1845,  1850,  1856,  1857,  1870,  1871,  1873,
    1876,  1888,  1904,  1924,  1926,  1936,  1940,  1942,  1943,  1951,
    1960,  1962,  1963,  1974,  1987,  2005,  2023,  2024,  2040,  2042,
    2046,  2057,  2079,  2089,  2097,  2119,  2122,  2136,  2137,  2138,
    1868,  1838,  1858,  1859,  1865,  1935,  1867,  1892,  1894,  1908,
    1985,  2109,  1918,  1920,  1928,  1931,  1953,  1954,  1959,  1966,
    1967,  1968,  2149,  2000,  2001,  2004,  2009,  2014,  2021,  2026,
    2027,  2029,  2035,  2064,  2066,  2082,  2093,  2095,  2096,  2100,
    2105,  2106,  2110,  2112,  2113,  2128,  2133,  2135,  2139,  2141,
    2145,  1995,  2144,  1834,  1836,  1839,  1843,  1853,  1877,  1896,
    1897,  1899,  1910,  1941,  1944,  1984,  1990,  2003,  2007,  2142,
    2143,  2044,  2063,  2069,  2081,  2083,  2102,  2107,  2117,  2127,
    1848,  1842,  1847,  1864,  1915,  1958,  1971,  1972,  2032,  2034,
    2116,  1991,  1948,  2015,  1863,  1911,  1921,  1986,  1969,  2016,
    1854,  1977,  1982,  2115,  2033,     0,  1826,  1829,  1830,   693,
       0,     0,     0,   682,   716,   716,   713,     0,     0,   717,
       0,    26,   681,   684,     0,   691,   687,   930,   920,  1779,
    1780,  1770,  1770,  1374,     0,     0,  1683,     0,     0,  1358,
       0,     0,  1359,  1402,     0,     0,  1403,     0,     0,  1722,
       0,  1372,     0,  1421,  1420,  1419,  1417,  1418,  1416,  1414,
    1411,  1501,  1500,  1412,  1413,  1422,  1704,  1415,  1786,  1785,
    1784,  1423,  2257,  2257,   592,   583,   574,     0,   578,  2257,
     915,   177,     0,   338,   220,     0,     0,  1663,  1661,  1662,
    1658,  1660,  1657,  1659,   518,     0,   513,   512,     0,   550,
     549,   174,  1733,  1732,     0,     0,  1671,  1669,  1670,  1666,
    1668,  1665,  1667,  1644,     0,  1722,     0,     0,  1569,     0,
       0,  1739,  1737,  1738,  1569,  1569,  1569,  1569,  1740,     0,
       0,     0,  1518,  1712,  1729,     0,     0,     0,     0,  1795,
    1796,  1797,  1798,  1799,  1800,  1743,     0,     0,     0,     0,
     464,   463,     0,     0,   187,   229,   210,  1235,   177,  1223,
       0,     0,     0,     0,     0,     0,  1475,  1474,  1473,  1335,
       0,  1341,  1337,  1339,  1330,     0,  1578,  1327,  1323,  1297,
    1296,     0,  1322,  1318,     0,  1314,  1312,     0,  1621,     0,
    1624,  1626,   649,     0,   648,  1613,     0,  1616,  1618,  2247,
    2244,     0,     0,  1264,   490,   359,  1285,     0,     0,  1261,
    1017,  1094,  1095,  1092,  1091,     0,   906,     0,     0,   623,
       0,     0,     0,   996,   994,   707,   708,     0,   712,     0,
       0,  2228,  2236,   751,     0,   143,     0,  1006,  1013,     0,
       0,  1021,     0,  1408,  2218,  2220,  2219,  2216,     0,     0,
       0,  1027,   354,     0,     0,     0,     0,    24,  1063,  1064,
     568,     0,     0,     0,   784,   785,  1032,   981,   979,   818,
     433,     0,  1073,   762,   763,   382,     0,  1156,  1245,  1160,
    1145,  1140,     0,     0,  1141,  2257,     0,     0,     0,     0,
       0,     0,     0,    64,    93,     0,     0,   118,   113,     0,
     108,     0,   115,   109,   892,   884,   890,     0,  1128,     0,
    1130,  1132,     0,     0,   964,     0,     0,     0,     0,  1083,
    1249,     0,     0,  1825,  1827,  2257,   664,   669,   672,   685,
     683,   642,     0,   736,   734,   744,   742,   740,   738,     0,
       0,   732,   780,   730,   715,   726,   724,   778,   756,     0,
     718,   728,   974,   970,     0,     0,     0,     0,   690,     0,
       0,     0,     0,     0,     0,     0,  1629,     0,  1496,  1497,
    1791,  1454,  1518,     0,     0,     0,  1789,     0,  1434,  1429,
    1428,  1441,  1440,  1445,  1445,  1443,  1444,  1435,  1430,     0,
       0,  1436,  1437,  1705,  2151,     0,     0,     0,   580,   582,
       0,     0,   595,   587,   589,     0,   584,   585,     0,     0,
     603,   605,     0,     0,   601,   917,   856,   219,     0,   631,
     633,   628,     0,   517,   547,   546,     0,     0,     0,     0,
       0,     0,  1760,  1645,     0,     0,  1735,  1571,  1572,  1570,
       0,  1764,     0,     0,     0,     0,     0,     0,     0,  1727,
       0,  1507,  1508,  1510,  1513,     0,  1519,  1520,     0,     0,
    1569,  1714,  1708,  1745,  1746,  1744,  1742,     0,     0,     0,
    2222,   460,   496,     0,   231,  1191,   879,  1169,     0,     0,
       0,     0,  1335,     0,     0,     0,  1331,     0,     0,     0,
    1325,  1609,  1607,  1576,  1588,  1590,  1594,  1596,  1587,  1581,
    1586,  1600,  1579,  1608,  1584,  1599,  1585,  1606,  1598,  1481,
    1573,  1574,  1575,     0,  1320,  1316,     0,     0,  1304,     0,
       0,   647,     0,     0,     0,  2243,     0,     4,     8,    10,
       0,   490,   429,     0,     0,     0,  1014,     0,     0,     0,
       0,     0,     0,     0,     0,   706,     0,     0,   160,   158,
       0,     0,   140,     0,   150,   156,   716,   145,   147,     0,
    1011,  1022,  1023,     0,     0,     0,   431,     0,  2206,  2207,
    1026,     0,     0,  1024,   353,   358,   625,   352,     0,   355,
     360,     0,   490,  1380,   616,   614,     0,   787,  1072,  1074,
       0,   383,  1149,  1147,     0,  1159,  1143,     0,     0,  1240,
       0,     0,     0,   101,     0,     0,    75,    81,    71,  2257,
    2257,   111,   106,   120,   116,     0,   110,   781,   893,   642,
    2257,   883,   882,   891,  1016,     0,     0,   962,   963,   957,
     983,   490,  1089,  1085,  1086,  1088,  2148,  2150,   694,   688,
     686,     0,    24,     0,  2257,  2257,  2257,  2257,  2257,  2257,
     746,   720,   748,   722,  2257,  2257,  2257,  2257,     0,   714,
     719,  2257,   642,   776,   774,   777,   775,     0,     0,    46,
      44,    41,    35,    39,    43,    38,    31,    40,     0,    34,
      37,    32,    42,    33,    45,    36,     0,    29,    47,   768,
       0,   692,  1771,     0,  1769,  1722,  1767,  1709,  1710,  1702,
    1688,  1703,     0,     0,     0,  1059,  1495,  1498,     0,     0,
       0,  1392,  1364,  1794,  1793,  1792,     0,     0,     0,  1439,
    1442,     0,     0,     0,     0,     0,  1387,     0,  1386,     0,
    1388,  1383,  1384,  1385,  1376,  1377,     0,     0,     0,   594,
     599,     0,     0,  2257,  2257,   572,   586,   609,   597,   611,
    2257,  2257,   607,   591,   602,   848,   339,     0,   514,  1807,
       0,  1808,     0,  1818,     0,  1819,     0,  1678,  1676,  1677,
    1673,  1675,  1672,  1674,  1646,     0,     0,     0,     0,  1761,
       0,     0,     0,  1759,     0,     0,     0,     0,  1741,  1758,
       0,  1511,     0,  1638,  1514,     0,     0,     0,     0,  1506,
    1524,  1526,  1528,  1568,  1567,  1566,  1530,  1546,     0,  1521,
    1522,  1717,  1287,     0,     0,     0,  1806,     0,  1817,   213,
       0,  1217,  1236,   848,     0,  1224,  1217,     0,  1630,     0,
    1463,     0,  1466,  1633,     0,  1471,     0,     0,  1332,  1333,
       0,     0,  1336,  1338,  1340,     0,  1324,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1479,  1478,  1477,
       0,  1482,  1483,     0,  1319,     0,  1313,  1315,  1625,     0,
    1627,  1617,     0,  1619,  2245,  1293,     0,  1289,     0,     0,
    1294,   863,     0,     0,     0,     0,     0,  1351,  2250,  2249,
     624,     0,     0,    48,     0,   709,   711,   710,  1352,   716,
    2257,  2257,   152,   650,   162,   154,   164,   144,   151,  2257,
       0,     0,     0,     0,     0,  2217,     0,     0,     0,     0,
       0,     0,  1065,     0,  1381,   566,     0,   786,  1070,     0,
    1246,  1247,  2226,     0,    93,     0,    65,     0,     0,     0,
      78,     0,    93,    93,   119,   114,  2257,  2257,   104,     0,
     894,   888,   896,   895,   885,   562,   943,     0,     0,     0,
     696,   675,   689,   643,   757,     0,   737,   735,   745,   743,
     741,   739,     0,  2257,     0,  2257,   733,   731,   727,   725,
     779,   729,    24,   769,     0,     0,     0,    27,     0,  1774,
       0,  1689,     0,     0,  1701,  1684,  1700,  1499,     0,  1456,
       0,  1391,     0,     0,  1790,     0,  1787,     0,  1447,  1451,
    1427,  1449,  1452,     0,  1438,  1706,     0,     0,     0,     0,
       0,     0,  2152,  1390,  1389,  1378,  1373,  1375,  1426,     0,
       0,   596,   593,   588,   590,     0,  2257,  2257,   604,   606,
    2257,  2257,     0,  1664,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1757,  1765,  1753,  1754,  1755,  1756,
    1515,     0,  1509,  1529,  1533,     0,  1546,  1532,     0,     0,
    1547,  1562,  1559,  1560,  1557,  1565,  1564,  1558,  1561,     0,
       0,     0,     0,     0,  1563,     0,     0,     0,  1503,  1504,
    1730,     0,  1523,  1517,  1288,  1715,  1397,  1393,  1394,  1399,
    1398,  1713,  1287,     0,     0,  1215,  1216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1214,     0,
       0,  1202,  1203,  1204,  1201,  1206,  1207,  1208,  1205,  1192,
    1183,     0,     0,  1239,     0,  2257,     0,  1178,     0,     0,
       0,     0,     0,     0,     0,  1170,  1171,     0,  1102,  1634,
       0,  1635,     0,     0,     0,     0,  1470,  1469,  1335,  1468,
    1460,  1326,  1610,     0,     0,     0,     0,     0,     0,  1611,
    1603,     0,     0,     0,  1603,  1639,  1476,  1489,  1494,     0,
    1491,  1488,  1490,     0,  1492,  1480,  1484,  1485,  1335,  1321,
    1317,     0,     0,  1292,  1291,     0,  1276,     9,     0,  1266,
     864,  1099,   365,  1266,     0,     0,  2241,     0,     0,   997,
      49,     0,   766,   161,   159,     0,  2257,     0,     0,     0,
    2257,   157,   146,     0,   149,   148,     0,  1003,  1007,   992,
    2210,  2209,  2208,     0,     0,   357,     0,   569,     0,  2257,
     788,     0,   642,  1150,     0,  1241,    70,     0,     0,   102,
      68,    93,    76,    82,     0,   121,   117,   782,  2257,   898,
     642,   897,     0,   559,     0,   812,   813,   811,  1087,   699,
     697,     0,   679,   676,     0,   747,   721,   749,   723,   758,
     772,   773,   770,   771,    30,    28,     0,  1768,  1718,  1690,
    1686,  1685,     0,  1455,  1722,  1458,     0,  1366,  1361,  1360,
    1363,     0,     0,  1446,     0,     0,  1718,     0,     0,  2185,
    2183,     0,     0,  2171,  2182,     0,     0,  2184,     0,     0,
       0,     0,     0,  2215,  2181,  2177,  2200,  2201,     0,  2169,
    2172,  2173,  2180,  2176,  2202,     0,  2162,  2161,  2165,  2167,
       0,  2160,     0,  2163,  2154,     0,     0,   600,   598,   610,
     612,   608,     0,     0,     0,  1809,  1810,     0,     0,  1820,
    1821,     0,     0,  1721,     0,  1646,     0,     0,     0,  1512,
    1531,  1525,  1527,  1534,  1536,  1534,     0,  1541,  1534,     0,
    1539,  1534,     0,  1549,  1548,     0,  1550,     0,  1502,     0,
    1401,  1400,  1396,  1716,     0,   236,  1209,  1210,  1211,  1213,
    1196,  1194,  1193,  1197,  1198,  1195,  1212,  1199,  1200,  1184,
     989,  1219,   986,     0,     0,  1237,     0,  1182,  1181,  1176,
    1174,  1173,  1177,  1175,  1179,  1180,  1172,  1225,     0,  1461,
    1467,  1637,  1630,  1472,  1334,  1577,  1589,     0,  1591,  1593,
       0,  1595,     0,     0,     0,  1601,  1580,  1605,     0,  1462,
    1464,     0,  1486,  1487,  1628,  1620,  1290,     0,     0,  1282,
    1277,  1278,  1295,     0,  1273,  1274,     0,     0,  1287,  1267,
    1268,     0,    24,  1262,     0,     0,  1020,     0,    50,  1000,
       0,    24,   163,   153,     0,   652,   654,   165,   155,   766,
       0,  1029,     0,   356,  1382,     0,  1071,    24,     0,     0,
      66,     0,    79,    88,     0,    72,   889,   886,   563,  2257,
     958,     0,  2257,   695,   674,   680,   642,  1778,     0,  1776,
       0,     0,  1691,  1687,  1457,     0,  1459,  1453,     0,  1365,
       0,  1788,  1448,  1450,  1425,     0,  2175,  2174,     0,     0,
    1569,     0,  1569,  1569,  1569,  1569,  2178,     0,     0,  2158,
       0,     0,     0,     0,  2187,  2159,     0,     0,     0,     0,
       0,     0,  2153,  1379,  1431,   858,   857,   340,     0,     0,
       0,     0,  1679,  1801,  1804,  1802,  1516,     0,  1553,  1555,
       0,  1542,  1545,  1544,  1552,     0,  1554,  1534,     0,  1505,
    1395,  1816,   214,   991,   990,   988,     0,  1218,  1103,  1107,
    1109,     0,  1113,     0,  1111,  1115,  1104,  1105,     0,   880,
       0,     0,  1631,  1636,     0,     0,  1612,  1604,  1582,     0,
    1583,     0,     0,  1280,  1275,  1281,  1279,  1272,  1271,  1270,
    1265,  1269,   366,   363,     0,  1018,     0,     0,     0,   999,
     767,   141,   651,    24,  1009,  1028,   567,  1068,    67,  1242,
      84,     0,     0,    77,    88,    88,  2257,   560,     0,     0,
     698,   759,     0,  1775,  1719,  1712,     0,  1367,     0,  1712,
    2198,     0,     0,  2203,     0,     0,     0,     0,     0,     0,
       0,  2170,  2189,  2190,  2188,  2186,  2168,     0,  2164,  2166,
    2155,  2156,  1432,     0,  1424,     0,  1811,  1812,  1822,  1823,
    1535,  1766,  1537,     0,  1540,  1538,  1556,     0,   987,  2257,
    2257,  1117,  2257,  1119,  2257,  2257,  1106,  1238,  1226,     0,
    1592,     0,  1602,     0,  1493,   368,  1019,  2240,     0,     0,
       0,     0,     0,     0,    55,     0,    54,     0,    52,     0,
       0,   142,  1075,    88,    93,    88,    89,    83,    73,   887,
       0,     0,   700,    24,  1777,  1711,  1720,  1371,     0,  1368,
    1370,  1692,  2199,     0,     0,  2197,     0,     0,     0,     0,
    2179,  2196,     0,  1433,     0,  1543,  1551,  1108,  1110,  2257,
    1114,  2257,  1112,  1116,  1632,  1597,  1465,   370,   375,   373,
     364,     0,   371,   377,    57,    62,    59,    61,    58,    60,
      56,     0,    51,     0,   653,   655,  1079,  1069,     0,  1077,
    1243,    85,    80,   561,   959,  2257,   760,     0,  1362,     0,
    1693,  1707,  2195,  2204,  2191,  2192,  2193,  2194,     0,     0,
    1118,  1120,  2257,  2257,   369,   372,  2257,    53,     0,  2257,
    1076,  1078,     0,   696,  1369,     0,  1697,  1694,  1695,  2157,
    1814,     0,   376,   374,   378,     0,  1080,    86,   701,     0,
       0,     0,     0,  1001,    90,     0,  1698,  1696,  1813,    92,
       0,    87,     0,    91,  1699
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   825,   826,   827,   828,  1046,  2397,  2398,   180,   322,
     181,  1403,  1404,  2225,  2556,  3606,  3079,  3080,  3507,  3607,
    3608,   829,  1185,  3117,  2813,  3525,  2164,  2811,  3373,  3121,
    3521,  2812,  3374,  3614,  3712,  3734,  3523,  3741,   647,   648,
     649,  1524,  2472,   830,  1535,  1190,  1533,  2172,  2482,  2169,
    2480,  2485,  2817,  1534,  2479,  2173,  2816,   831,     9,    28,
      29,    30,    31,    32,    88,   834,  1109,  2105,  1427,  2422,
    2426,  2427,  2423,  2424,  3086,  3090,  2779,  2771,  2770,  2772,
    2775,   494,   270,   600,   835,    55,    56,    11,    41,   115,
      70,    71,    72,    73,   196,   336,    74,    75,   242,   341,
     228,  1009,   520,  2974,   372,   936,  2288,   400,   401,   229,
     354,   343,   349,  1348,  1349,   119,   538,   120,   121,   360,
     230,   356,   342,   344,   522,   231,   256,   576,   244,   247,
     245,   246,   382,   554,   555,   557,   562,   939,   248,   249,
     391,   559,   192,    12,    51,   151,   152,   153,   945,  2912,
     154,   252,   240,   394,   395,   396,   397,  2127,   836,   837,
     838,   839,  1067,  3595,  3342,  1405,  3660,  3661,  3662,  3703,
    3702,  3706,   840,   841,   842,   843,   844,   845,   846,  1057,
     495,  1062,  1397,  1398,  1442,  1160,  1443,   297,   298,   299,
     300,   301,   302,   303,   452,   496,  1331,   497,   498,   499,
     500,   501,   502,   503,   986,   182,   514,   996,   998,  2022,
     183,   508,   992,   507,   991,   510,   994,   509,   993,   954,
     964,   304,   305,   185,   306,   419,   420,   421,   422,   405,
     424,   847,  3379,  3620,  3133,   848,  1127,  2130,  3109,  2453,
      89,   237,   548,  1945,  1253,  1254,  1255,  1942,  1943,  2275,
    2276,  2277,  2613,  2614,  1946,  1947,  2271,  2617,  2609,  2283,
    2284,  2620,  2621,  2910,  2906,  2907,   849,  1454,    57,  2090,
    2091,  2447,   406,   426,  1101,  1165,  1038,  1089,  1072,  1111,
    2512,   186,  1039,  1029,  2063,  2774,    59,   307,   850,  1195,
     851,  1208,  1209,   852,   853,   854,   855,  1216,  3142,  1237,
    3384,  1238,  2199,  1239,  2509,  1240,  2831,  1241,  2228,   856,
    2195,  2830,  3141,  3382,  3381,  3685,    90,    13,   857,  1421,
    2095,  2096,  2097,  2218,  1890,  2219,  2220,  2843,  2845,  2527,
    2526,  2531,  2525,  2524,  2515,  2514,  2519,  2518,  2517,  2516,
    2521,  2523,   858,   859,  1107,   860,  1886,  1223,  3623,   861,
    1502,  3351,  2558,  2559,  2221,  2528,  2488,  2819,  1154,  1482,
    2134,  2456,  2135,  1478,   862,   863,  1201,  2187,  3137,   864,
     865,   866,   867,    14,    45,    15,    16,    17,    91,    92,
     868,    93,    18,   927,    19,    94,    95,   131,   550,  1951,
    2625,  3436,    96,   127,   365,   869,  2752,    20,    21,    22,
      23,    24,    40,    62,    97,   676,  2028,  2693,   870,  1196,
    2492,  2176,  2490,  3526,  3128,  2177,  2489,  2822,  3130,   871,
     872,   873,  1083,  1084,  1538,    98,   238,   549,   930,   931,
    1257,  1949,   874,  1242,  1243,   875,  1898,  1244,   308,    64,
      65,    66,    67,  1545,   157,   111,    68,  1116,   108,   188,
     189,  1546,  1547,  2499,  1548,   673,   674,  1225,   675,  1226,
    1158,  1159,  1549,  1550,  1401,  3281,  3282,  3465,  2116,  1099,
    1100,   876,  1416,  3509,   877,  3098,   878,  1431,  1432,  1433,
    2111,  2109,   879,   880,  2406,  2433,   881,  2121,  2443,   882,
    1155,  1156,   883,  1022,   884,  2569,   885,  3612,  3112,   886,
    2460,  3677,  3678,  3679,  3709,  1162,   887,  1551,  2189,  2503,
    2504,   888,  2083,  1037,  1390,   889,   890,   891,  2695,  3285,
    3476,  3477,  3579,  3580,  3584,  3582,  3585,  3649,  3651,   892,
     893,  1540,  2181,   894,  1542,  1513,  1514,  1515,  2154,   895,
    1175,   896,   897,  2147,  1510,  1171,   195,  1516,  1517,   309,
    2696,  3015,  3016,  2999,  1054,  1055,  2691,  3000,  3003,    99,
     126,   542,  1358,  2347,  3017,  3480,   434,   898,  1169,   100,
     123,   539,  1355,  2345,  3004,  3478,  2692,  1189,  2804,  3369,
    3613,  2149,   899,   900,   901,   902,   903,  1070,  2404,  1048,
    2400,  3338,  3339,  3340,  3493,  3329,  3330,  3331,   904,  2965,
    2746,  2747,  2749,  2047,   905,   906,  1367,  1368,  1369,  2056,
    2386,  1370,  2383,  2053,  1371,  2359,  2048,  1372,  1373,  1374,
    2351,  2356,  1375,  2042,  2043,   907,  1079,  1059,   908,  1923,
    1924,  2243,  3169,  3400,  2873,  3166,  3628,  3629,  1925,  2265,
    1904,  2605,  2896,  3215,  2795,  3108,  2606,  1926,  1927,  2331,
    2967,  2968,  2969,  3262,  1928,  1929,  1439,   909,  1117,   910,
    1250,  1930,  1931,  2259,  3564,  2260,  2261,  2262,  2589,  2877,
    2880,  2881,  1932,  2579,  2868,  3397,  2036,  2037,  3054,  2699,
    3319,  2700,  2038,  2704,  2049,  2731,  2050,  2732,  3055,  3056,
    3057,  3058,  1933,  2237,  2238,  2576,  1934,  2962,  2679,  2958,
    2326,  2002,  2321,  2322,  2323,  2931,  2003,  2327,  2680,  2963,
    2669,  2670,  2671,  2672,  2673,  3448,  3243,  3570,  2674,  3450,
    3451,  2956,  2675,  2957,  2676,  2310,  2379,  2380,  2381,  3313,
    2382,  3033,  3040,  3487,  2701,  1026,  2882,  3021,  3208,  2703,
    2664,  1305,   310,  1306,  1983,   445,   955,  1964,  1984,  2644,
      39,   911,   912,  3161,  3393,  2861,  3392,  3691,  3717,  3718,
    2865,  2570,  1935,  2571,  2594,  3176,   603,  2566,  2567,  2332,
    2682,  3391,  3165,  1307,   971,  1308,  1309,  2959,  2677,  1311,
    1312,  2312,  3572,   913,   914,  2230,  2568,  3157,  3388,  3389,
    1901,   915,  1065,  1937,  1938,  2247,  2875,  1939,  1940,  2585,
    2015,  2305,  1313,  1314,  1315,  1316,   916,  1204,  1875,  1876,
    1877,  2191,  1878,  2192,  1941,  2595,  3214,  3432,  2892,  3211,
    3212,  3213,  3210,  3198,  3199,  3200,  3201,  3202,  3203,  3544,
     917,  2119,  2438,  2439,  1118,  1317,  1120,  2117,  1318,    25,
     919,  1177,  2155,  1424,  1504,   920,   921,  2763,   922,  2395,
    1042,  2070,   923,   924,    35,   543,   544,   545,   546,   547,
     925
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -3074
static const short yypact[] =
{
    1022,  1330, -3074,   329,   329,   974, -3074, -3074,   974, -3074,
     184, -3074, -3074, -3074,   351, -3074,  1022, -3074, -3074, -3074,
   -3074, -3074,   -40, -3074, -3074, -3074, -3074, -3074,   397,   475,
   -3074,   584, -3074, -3074, -3074, -3074, -3074, -3074,   -90, -3074,
     346,   554, -3074, -3074, -3074,  1129, -3074, -3074, -3074, -3074,
   -3074,   -59,   329, -3074,   329,   693,   184, -3074,   808, -3074,
   -3074, -3074, -3074, -3074, -3074,  1024,   403, -3074, -3074, -3074,
    1099,   712,   329, -3074, -3074,  1114,   329, -3074, -3074,   329,
     329, -3074, -3074, -3074, -3074,   329,   329, -3074, -3074, -3074,
   -3074, -3074,  1129, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074,  4104, -3074,   403, -3074,   869,  1608, -3074, -3074,
     651, -3074, -3074,  1178,   554,   650, -3074, -3074, -3074, -3074,
   -3074, 10251, -3074,   329,   744,  1066,   329,   184, -3074, -3074,
   -3074,   329, -3074, -3074,   883,   757,   971, -3074, -3074,   781,
   -3074,   797, -3074,   766, -3074, -3074,   810, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074,   835, -3074, -3074,
   -3074,   839,   857,   860,   886,   931,   951,   964,   978,   997,
    1009,  1608,  1013,  5103,  1033,  1036,  1046,  1068,  1096,  1140,
    1839,  1321, -3074, -3074, -3074, -3074,  1070, -3074,   155, -3074,
    1608, -3074,   168, -3074, -3074, -3074,   157, -3074, -3074, -3074,
     850, -3074, -3074, -3074, -3074, -3074, -3074,   883,  1146,  1150,
    1155, -3074,   971, -3074, -3074,  1164, -3074,  1184, -3074,   960,
   -3074, -3074,  1195, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074,  1198,  1523,   329,  1226, -3074,   184,   184,  1234,
     329, -3074,    -9,  1551, -3074,   908,   995, -3074,   911,  1062,
    1569,  1683,   329,  1690,  1697, -3074,  1078, -3074,    54,    54,
      54,    54,    54,  5103,  1351,  1533,    43,  5103,  1148,  5103,
   -3074,  5103,  5103,  5103, -3074, -3074, -3074,  1180,  1277,  1294,
    5103,  1157,  1296, -3074,  5103,  5103,  1305, -3074,  1318, -3074,
    1036,  1320,  1322,  1323,  1324,  1763,  9078,    83, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  1337, -3074,
   -3074, -3074, -3074, -3074, -3074,   350,   350, -3074, -3074, -3074,
   -3074, -3074,  1608, -3074, -3074,   329,  1608,  1300,   164, -3074,
   -3074, -3074, -3074,  1783, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074,  1339, -3074,  1339,    -9,  1796,  1805,  1808, -3074,
   -3074, -3074,  1811,  1814,   554,  1690,  1339,  1815,  1176, -3074,
    1737, -3074,  1415,  1387, -3074,  1458, -3074, -3074, -3074,  1203,
   -3074, -3074,  1854,  1441, -3074,  1404, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074,  1062,  1404, -3074, -3074, -3074, -3074, -3074,
   -3074,  1405,   160,   191,   215, -3074,  4091, -3074, -3074, -3074,
    1413,  1884,   202, -3074,  1412,   205, -3074,   367,  1456,  1463,
     210,   220,  4194,  1466,    92,  1315, -3074, -3074,   103,  1469,
   -3074, -3074, -3074, -3074,   223, -3074, -3074,  8161, -3074,  7951,
    5167,  2890,  2890,  5103, -3074,  1395,  5103,  9078,  1438, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,  1248,  1901,  8201,  9078,
    1395,  1906,   338,  5103,  5103,  5103,  5103, -3074,  5103,  5103,
    5103,  5103,  5103,  5103,  5103,  5103,  5103,  5103,  5103,  5103,
    5103,  5103,  5103,  5103,  5103, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,  5103,  5103, -3074, -3074,  1450,
    5103, -3074,  5103,  1451, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,   350,  5103,  5103,  5103,
    5103,  1490,  1926,  1839,  3906,  1455, -3074,  1608,  1430, -3074,
    1268,  1914, -3074,  1278, -3074,  1917,  1508,  1511,   228,  1647,
     356,   400,   242,  1480, -3074,   427, -3074, -3074, -3074,   329,
   -3074, -3074,   329,  1545, -3074,  7191,   650,  7495,  1928,   517,
     329,  1936,   483, -3074, -3074,   995,  1935, -3074, -3074, -3074,
   -3074,  1937, -3074,  1938, -3074,  1940, -3074,   329, -3074,   329,
   -3074, -3074,  1690,  1941, -3074, -3074, -3074,   329,    54, -3074,
    1608,    52, -3074, -3074, -3074, -3074, -3074,  1157,  1943,  1157,
    1947, -3074,  1948,  1326,  1151, -3074,    43, -3074, -3074, -3074,
    1537,  9078,   468,  1542,  8275,  1959,  1157,  1548, -3074,  1549,
    1550, -3074,  8381,  8469,  8722,  8828,  9346,  9437,  5167,  9240,
    9544,  3562,  9599,  3414,  9632,  9569,  9777,  2890,  2890,  1121,
    1121,  1507,  9078,  8916,  8990,  1395,  9078,  9026,  1395, -3074,
    9078,  9078,  9078,  9078, -3074,  1965, -3074, -3074,  1988, -3074,
    9078, -3074,   216,  1608, -3074,  1555,  1979,   483, -3074, -3074,
    1974, -3074,  1528,  1975, -3074,  1981, -3074, -3074, -3074,  1984,
   -3074, -3074,  1346,  1576,  2012, -3074,   329,  1579, -3074, -3074,
   -3074,   350,   350,   350,   329,   942,   329,  1231,   249,   249,
    1271,   329,   329,   249,   249,   329, -3074,  1231, -3074, -3074,
     329, -3074,   880, -3074, -3074, -3074,   249, -3074, -3074, -3074,
   -3074,   329, -3074, -3074, -3074, -3074,   116,   116,  5103, -3074,
   -3074, -3074,  1271,  1271, -3074, -3074,   249, -3074, -3074,   249,
   -3074, -3074,   329, -3074, -3074,   249, -3074, -3074,   350,   249,
   -3074, -3074,  5103,   249,   350,   329,   350,   249, -3074, -3074,
     187,   249,   249,   187,   249,   329,   187,   249, -3074,   249,
     249,   249, -3074,  1231, -3074, -3074,   350,   249, -3074, -3074,
     249,    97,   329, -3074,  1271, -3074, -3074,   249,   949, -3074,
   -3074,   350,  1348, -3074,   249, -3074,  2367,   350,  5103,    54,
      54,   249, -3074, -3074,   942,   350,   957, -3074,  5103, -3074,
     395,  5103,   249,    87, -3074,  5103,   249,  1996,   350, -3074,
     249,  5103, -3074,  5103,   116,   329,   249,   329,    54,   249,
     329,    54, -3074,   329,   177, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,   459, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,  1117, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074,   813,   329, -3074,
     719, -3074,  1583, -3074, -3074, -3074,  1677, -3074, -3074,  1588,
    1590,  1591,  1594, -3074, -3074,  1362,  2030,  1599,  1600, -3074,
     382, -3074,  1563, -3074, -3074,  1371,   404, -3074,  1604, -3074,
    2019, -3074,  1411, -3074, -3074, -3074,  1377, -3074, -3074, -3074,
   -3074,  9861, -3074,  1180,  1612, -3074,  1180, -3074,  1180,  1180,
    1180,  1180,  1180,  2028,  2029,  2031,  5103,  1615,  2032,  5103,
    1618,  1619,  1620,  1621,  1624,  1626,  1630,  3906,  3906, -3074,
     256, -3074, -3074, -3074,  1730,  1642, -3074,  1644,  1645,  1418,
    1649,   329, -3074,   329,  1650, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074,   339,  1417,   264,  1380,  1613, -3074, -3074,
   -3074, -3074,  1426,   295, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074,  2085,  1427, -3074, -3074,  1623, -3074,  1271, -3074,
    1568,   245, -3074, -3074, -3074,  1433, -3074,  9078, -3074, -3074,
    1460, -3074, -3074,  4302, -3074, -3074, -3074,   350, -3074, -3074,
    1271, -3074,   -48, -3074, -3074,  1786, -3074,    64, -3074,  1601,
   -3074, -3074, -3074, -3074,  2101, -3074, -3074,   436, -3074,  1443,
   -3074,  1445,  2101, -3074,  1470, -3074, -3074, -3074,  1651,   122,
   -3074,  1606, -3074,  1406, -3074, -3074, -3074, -3074,  1409,   218,
   -3074,  -201, -3074,  1449,  1340,  1616, -3074,  1742,  1467, -3074,
    1461,  5103,   180,  1055,  5103, -3074,    76,   249, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074,   137,   137,   137,
   -3074,   137,  2609,   137,   137,  1481,   -48,  1481,  1481,  1071,
    1071,  1481,  1481,   -48, -3074,  2123, -3074,  1658,   575, -3074,
    2124, -3074,   -48,   100,    50, -3074, -3074,  5103, -3074, -3074,
   -3074,  1103, -3074, -3074,   650,  5103, -3074,  5103,  1652,  1653,
    1654,  1655,  1399,  1656,   957, -3074,  1743,  1244,  1500, -3074,
    1519, -3074, -3074,   329, -3074, -3074,  1085, -3074,  2137, -3074,
    2132,   329, -3074,   666,  6555,  1525, -3074, -3074,  2143, -3074,
    1444,  2143,  2146,  1447,  2143,  2146,  5103,  2143, -3074, -3074,
     245,   350, -3074, -3074,  1685,   315, -3074, -3074,  1678,   350,
    5103,  1682, -3074, -3074,  2128,  2129,  2052, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,  1102,  1102,   249,   249,   249,
    3627, -3074, -3074,  2033,   813, -3074, -3074,   868, -3074, -3074,
   -3074,  1661, -3074, -3074, -3074, -3074,  4104,  1690, -3074, -3074,
    1503,   329,  1158,  2140,  1157,  1157,  1534,  1428, -3074,  5394,
    5394, -3074,  1449, -3074, -3074,  1695,  1696,  1183, -3074,  9607,
    1699, -3074,  1700,  1701,  1703, -3074,  1703,  1703,  1706,  1708,
    1712,  1713,   329,   348, -3074, -3074, -3074, -3074,   114, -3074,
     329,  1595, -3074, -3074,  1183, -3074,  1183,  1707, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
    9078,   428, -3074, -3074,   431, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,  1666, -3074, -3074,   432, -3074,
   -3074, -3074, -3074, -3074, -3074,   184, -3074, -3074,   184,   947,
     181,  2169, -3074, -3074,   713,   189,   777,  2196, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,   329,  1575,   329, -3074,
   -3074,  1592,   329,  1629,   329,   329,  1271,  1560,  1726, -3074,
    1732,   173, -3074, -3074, -3074,  1271, -3074, -3074,  2203, -3074,
   -3074,  1541,  1740, -3074, -3074, -3074,  1055,  1133, -3074,  1133,
     957,   187,  5103,  5103,  5103,  1741, -3074, -3074,   350,   350,
    1271,  1552,   957,    54,  1512,    97,   350, -3074,  1558,  5103,
    1822, -3074, -3074,  1628,  1340,  1449,  1461, -3074, -3074, -3074,
     329,  1169,  2225, -3074, -3074,  1570,   166,   245,   350, -3074,
   -3074,  2216,  2218, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  1174, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  2367,   350,   350, -3074,  1071,  5103,   -84,  2209,  2212,
   -3074, -3074, -3074, -3074, -3074,   201, -3074, -3074, -3074, -3074,
    2041, -3074,  1816,   650,  5103, -3074,    69, -3074, -3074,   329,
    2221,    54,    54, -3074,  1617, -3074,    43,  1578,   350, -3074,
     329,   329,  5103,   -74, -3074,  1633, -3074, -3074,   605, -3074,
    1720, -3074,  1723,  5103,  1037, -3074, -3074,  1593, -3074,  2249,
   -3074,  1663, -3074,   350, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,  5844, -3074, -3074, -3074, -3074,
     329,    54,    54,   206,   315,  2067,  2200,   350,   245, -3074,
    1679, -3074, -3074,  2225,  2245,  1825, -3074, -3074, -3074, -3074,
   -3074,  1907,  1907, -3074,   421,  1684, -3074,   329,  1271, -3074,
    1271,  1271, -3074, -3074,  1271,  1271, -3074,   329,  1338,   468,
    1271, -3074,  1338, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074,   253,   253,   267,   923, -3074,   930, -3074,   868,
   -3074,   184,  2255, -3074, -3074,  1219,  1842,  1806, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,  1843, -3074, -3074,  1631, -3074,
   -3074, -3074,  1710,  1710,  1611,  1660, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,  1614,   468,  1847,  9919,   599,  9861,
    1770, -3074, -3074, -3074,   599,   599,   599,   599,  1625,  9861,
    9861,   237,  1716,   677, -3074,  9861,  9861,  9861,  9861, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,  1622,   -47,  1055,  5103,
   -3074, -3074,  1853,  2255, -3074, -3074, -3074, -3074,   184, -3074,
    1817,  1818,  1819,   833,  1821,  1823, -3074, -3074, -3074,  2195,
     329, -3074,  2297, -3074, -3074,   586,  2572, -3074, -3074, -3074,
   -3074,   329, -3074, -3074,   586,  1598, -3074,   339, -3074,  1637,
   -3074,  1668, -3074,  1865,   403, -3074,  1657, -3074,  1673, -3074,
    1722,  1838,   329, -3074, -3074, -3074, -3074,  4302,   329, -3074,
    1664, -3074, -3074, -3074, -3074,  1648, -3074,  2314,  2319, -3074,
    2321,  1702,  5103, -3074, -3074,  2327, -3074,  1667, -3074,  1804,
    1665,  2146, -3074, -3074,  1686,   891,   329, -3074, -3074,  1857,
     249,  1030,  1672, -3074, -3074,  1848, -3074, -3074,  5103,  1271,
    1055,  -183, -3074,   329,   329,  5103,    33,   -48,  2343,  1021,
    2341,  2330,  2332,  2609, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,   350,  1986, -3074, -3074,  2246,  5103,   650,  2094, -3074,
   -3074, -3074,  5103,   116, -3074,  1987,  2356,  2358,   440,   443,
     329,  1924,   957, -3074,  3906,  1887,  1889, -3074, -3074,  1969,
   -3074,  5103,   446, -3074,  1736, -3074, -3074,   617, -3074,  5103,
   -3074, -3074,  1719,   869, -3074,  1267,   329,  2366,  7396, -3074,
   -3074,  1055,   350, -3074, -3074,    20, -3074,  2146,  2146,  1689,
   -3074,  1785,  1792, -3074, -3074, -3074, -3074, -3074, -3074,    54,
      54, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  2527,
   -3074, -3074, -3074, -3074,    54,  3645,  2383,  2370, -3074,   957,
     875,   284,   426,  2251,   -26,   942, -3074,   620, -3074, -3074,
   -3074,  1921,    26,  1271,   174,  1734, -3074,  1731, -3074, -3074,
   -3074, -3074, -3074,  1927,  1927, -3074, -3074, -3074, -3074,  1799,
    1735,  2402, -3074, -3074, -3074,   491,  1744,  1738, -3074, -3074,
     350,   129, -3074, -3074, -3074,  1727,   923, -3074,   329,   329,
   -3074, -3074,   329,   534, -3074, -3074, -3074, -3074,  1934, -3074,
   -3074, -3074,  2389,  1157, -3074, -3074,  1980,   119,  1983,   136,
    1188,  9861, -3074,   361,  2414,  1989,  2416, -3074, -3074, -3074,
    9861, -3074,   444,  9861,  9861,  9861,  9861,   329,   469, -3074,
     370,  2427, -3074, -3074,   329,  5081, -3074,  2016,   329,  1769,
     599,  2054, -3074, -3074, -3074, -3074, -3074,  1188,  2411,  1188,
   -3074,  9078, -3074,  1966, -3074,  1931, -3074,  1939,   148,   148,
     148,   473,  2195,   148,  5081,   329, -3074,   474,   329,   477,
   -3074, -3074, -3074,  1964,  1971,  1976,  1183,  1183, -3074,  1977,
   -3074,  1982,  1985,  1990,  1991, -3074, -3074, -3074, -3074,   799,
   -3074, -3074, -3074,   480, -3074, -3074,   489,   329, -3074,   329,
    1643, -3074,   329,  1676,  5103, -3074,   329,  2438, -3074, -3074,
     586, -3074, -3074,  1793,   586,   252, -3074,   957,  5103,  5103,
    5103,  4894,  2453,  1271,   207, -3074,   957,   329, -3074, -3074,
     329,   329, -3074,   994, -3074, -3074,   450, -3074,  1798,  5103,
   -3074, -3074, -3074,  2454,  1169,  1608, -3074,  1800,  2460, -3074,
   -3074,   957,  1844, -3074, -3074, -3074, -3074, -3074,   329,  2146,
   -3074,   245, -3074,  1870, -3074, -3074,   492, -3074, -3074, -3074,
     350, -3074,  8113, -3074,  1105, -3074, -3074,  2096,  2447, -3074,
    2086,  2089,  1973,  1824,  2090,  2007, -3074, -3074, -3074,   182,
    2078, -3074, -3074, -3074, -3074,  1969, -3074, -3074, -3074,   262,
     862, -3074, -3074, -3074,  2225,  5103,  2015, -3074,  1992, -3074,
   -3074, -3074, -3074,  2484, -3074, -3074, -3074,  2486, -3074,  1797,
   -3074,  2467,   -48,   329,  3084,  3084,  3084,  3084,  3084,  3084,
   -3074,  2490, -3074,  2491,  3084,  3084,  3084,  3084,  1174, -3074,
   -3074,  3084,    94, -3074, -3074, -3074, -3074,  2472,  2485, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  2487, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,   493, -3074, -3074, -3074,
    2474, -3074, -3074,  1271, -3074,   468, -3074, -3074, -3074, -3074,
   -3074, -3074,  1861,  1862,   345, -3074,   620, -3074,   148,  1845,
     249, -3074,  2034, -3074, -3074, -3074,   329,   329,   148, -3074,
   -3074,   124,  1271,  1311,  9861,   324, -3074,  5103, -3074,  5103,
   -3074, -3074, -3074, -3074, -3074,  1911,   249,   124,  1271,  2501,
   -3074,   350,   329,   897,   897, -3074, -3074,  2502, -3074,  2502,
     614,   614,  2502, -3074, -3074,  1928, -3074,  2073, -3074, -3074,
    2488, -3074,  2493, -3074,  2494, -3074,  2496,  2038, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,   114,  1183,  1852,  1183, -3074,
    1183,  2087,  9861, -3074,  2088,  2091,  2092,  2093, -3074, -3074,
     237, -3074,   237, -3074, -3074,  1302,  1703,  3633,  1703,  2519,
    2522, -3074, -3074, -3074, -3074, -3074, -3074,   283,  9861, -3074,
    2035, -3074,  2210,    90,   284,   329, -3074,  2095, -3074, -3074,
    5104,   -23, -3074,  1928,  1801, -3074,   -23,  1271,   667,  2097,
    2529,  1872, -3074, -3074,   496, -3074,   519,   833, -3074, -3074,
     522,   272, -3074, -3074, -3074,   586, -3074,  2510,  2510,  2513,
    1868,   194,  2515,  2518,  2520,  2515,  2515, -3074, -3074, -3074,
     162, -3074,   706,   329, -3074,   586, -3074, -3074, -3074,  1879,
   -3074, -3074,  1882, -3074, -3074,  -127,   523, -3074,   329,   524,
   -3074,  5103,  2109,  2530,   525,   957,  2546, -3074, -3074, -3074,
   -3074,  5103,  1944,  2230,  5103, -3074, -3074, -3074, -3074,   450,
    1130,  1130,  2549,   486, -3074,  2551, -3074, -3074, -3074,  1130,
     329,  1968,  1375,  2553,   329,  1893,   311,   240,  1271,  2557,
     957,  -155,  2343,  5103, -3074, -3074,  2609, -3074,  1855,  5103,
   -3074, -3074, -3074,  2567,  3906,   350, -3074,   880,   329,   350,
   -3074,  2136,  3906,  3906, -3074, -3074,   182,  2078, -3074,  1174,
   -3074, -3074,  1149, -3074, -3074,  1962, -3074,  1608,  5045,  7396,
      37,  1056, -3074, -3074, -3074,  1915, -3074, -3074, -3074, -3074,
   -3074, -3074,    54,  3084,    54,  3084, -3074, -3074, -3074, -3074,
   -3074, -3074,   -48, -3074,  1122,  1156,  3645, -3074,  2142,  2108,
    9861, -3074,   426,   426, -3074, -3074, -3074, -3074,   526, -3074,
    2069, -3074,   148,    44, -3074,  1920, -3074,   532, -3074, -3074,
    2588, -3074, -3074,  2001, -3074,  2590,  8661,  8661,  8661,  8661,
     148,   148, -3074, -3074, -3074, -3074, -3074, -3074,  2588,  1930,
     350, -3074,  2502, -3074, -3074,   329,   614,   614, -3074, -3074,
     614,  2337,  1929, -3074,   411,   -73,   415,   -13,  2574,  2163,
    1942,  1188,  1946,  1949, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,   540, -3074, -3074, -3074,   354,   226, -3074,  5081,  5081,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  5394,
    5394,  2138,  5394,  2144, -3074,  5394,   622,  9861,  2601, -3074,
   -3074,  5081, -3074, -3074, -3074, -3074, -3074,  2602, -3074,   636,
   -3074, -3074,  2210,  1951,  1945, -3074, -3074,   116,   116,   116,
    2595,   116,   116,   116,   116,   116,   116,  2599, -3074,  2600,
     116, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  5104,
   -3074,   350,  1961, -3074,  2133,  2337,  2604, -3074,  2605,  2606,
    2607,  2611,  2612,  2613,  1159,  1801, -3074,  2133, -3074, -3074,
    2614, -3074,  2287,   148,  1408,   148, -3074, -3074,  2195, -3074,
   -3074, -3074, -3074,  2201,  2202,   547,  1188,  2617,  1188, -3074,
    2630,   555,  2207,  2208,  2630, -3074, -3074, -3074, -3074,  1271,
   -3074, -3074, -3074,  2172, -3074, -3074,   706, -3074,  2195, -3074,
   -3074,   329,   329, -3074, -3074,   329,  -188, -3074,   586,   219,
    2225, -3074,  2141,   219,   419,   957, -3074,  2646,  2174, -3074,
   -3074,  2215,  2064, -3074, -3074,   329,  1130,  1608,  1420,   329,
    1130, -3074, -3074,    54, -3074, -3074,  5103, -3074, -3074, -3074,
   -3074, -3074, -3074,   957,  2655, -3074,    54,  2225,   350,  2377,
   -3074,  2640,  1785,  9078,  2642, -3074, -3074,   245,  2194, -3074,
   -3074,  3906, -3074, -3074,  2229, -3074, -3074, -3074,   862, -3074,
    1785, -3074,  5103, -3074,   316, -3074,  2124, -3074, -3074, -3074,
   -3074,  2182,  2278, -3074,  2653, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,   329, -3074,   126, -3074,
   -3074, -3074,   148, -3074,   468,  2489,   556, -3074, -3074, -3074,
   -3074,   329,   148, -3074,   124,   124,  2102, 10105, 10105, -3074,
   -3074,  9637,  2211, -3074, -3074,  2213,  2223, -3074,  2227,  2231,
    2233,  2235,   329,   543, -3074, -3074, -3074, -3074,   560, -3074,
   -3074,  2121, -3074, -3074, -3074,   564,  2682,  2682, -3074, -3074,
     574,  2683,  2676, -3074,    46,   350,   124, -3074, -3074, -3074,
   -3074, -3074,  2444,  4104,  2681, -3074, -3074,  2688,  2689, -3074,
   -3074,  2690,  2277, -3074,  1188,  2279,  1188,  1188,   237, -3074,
   -3074,  2522, -3074,  2232,  1595,  2232,   277, -3074,  2232,   277,
   -3074,  2232,  5394, -3074, -3074,  9861, -3074,  9861,  2519,    90,
   -3074, -3074, -3074, -3074,  1188, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
     647,  2715, -3074,   350,  1221, -3074,  2444, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,   363, -3074,
   -3074, -3074,  2219, -3074, -3074, -3074, -3074,  2698, -3074, -3074,
    2286, -3074,  2701,  2288,  2705, -3074, -3074, -3074,  2293, -3074,
    2256,  5081, -3074, -3074, -3074, -3074, -3074,   329,  2709, -3074,
    -188, -3074, -3074,  2710, -3074, -3074,  2711,   329,  2210,   219,
   -3074,    54,   -48, -3074,  2315,   957, -3074,  5103, -3074,  2125,
    2713,   -48, -3074, -3074,   390, -3074, -3074, -3074, -3074,   121,
    2301, -3074,   957,  2146,  2486,  2455, -3074,   -48,  2302,  2304,
    2343,  2269, -3074,  2354,  2309, -3074, -3074, -3074, -3074,  2461,
    2247,  5103,  2263, -3074, -3074, -3074,  1785, -3074,   576, -3074,
     350,  2162, -3074, -3074, -3074,  9861, -3074, -3074,   148, -3074,
    2280, -3074, -3074, -3074,  2588,  2162,  1758,  1758,  2316,  9919,
     599, 10069,   599,   599,   599,   599,  2098, 10069,  8661, -3074,
   10069, 10069, 10069, 10069, -3074, -3074,   148,  2743,   148,  8661,
     249,  5081, -3074,  2486,    99, -3074, -3074, -3074,   224,  2320,
    2322,  2323, -3074, -3074, -3074, -3074, -3074,   162, -3074, -3074,
     577, -3074, -3074, -3074, -3074,   580, -3074,  2232,  2752, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,   350,  2715, -3074, -3074,
   -3074,   350, -3074,   350, -3074, -3074,  1646, -3074,  2478, -3074,
    2479,  2735, -3074, -3074,  2328,  2099, -3074, -3074, -3074,  2329,
   -3074,   148,   368, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,   957, -3074,  2331, 10323,  2292, -3074,
   -3074, -3074,  2107,   -48, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  2334,   245, -3074,  2354,  2354,   862, -3074,  1608,  2153,
   -3074, -3074,   329, -3074,  2486,   677,   114, -3074,  9783,   677,
   -3074,  2336, 10069, -3074,   587, 10069, 10069, 10069, 10069,   329,
     591, -3074, -3074, -3074, -3074, -3074, -3074,  2300, -3074, -3074,
   -3074,  2519, -3074,   329, -3074,  2147, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074,   227, -3074, -3074, -3074,  9861, -3074,  1527,
    1527, -3074,  1527, -3074,  1527,  1527, -3074, -3074, -3074,  2306,
   -3074,  1188, -3074,   596, -3074,   988, -3074, -3074,   137,   137,
     137,   137,   137,   137, -3074,  2757, -3074,   597, -3074,  5103,
    1437, -3074,    40,  2354,  3906,  2354,  2343, -3074, -3074, -3074,
    2497,   365, -3074,   -48, -3074, -3074, -3074, -3074,   598, -3074,
   -3074,  1423, -3074,  2348, 10069, -3074,  2349,  2350,  2352,  2353,
   -3074, -3074,  8661, -3074,  2768, -3074, -3074, -3074, -3074,  1527,
   -3074,  1527, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  1107, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, 10323, -3074,  2791, -3074, -3074, -3074, -3074,   794, -3074,
   -3074, -3074, -3074, -3074, -3074,    20, -3074,  9783, -3074,  1694,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,   606,   294,
   -3074, -3074,  1192,  1192, -3074, -3074,  1192, -3074,  5103,   924,
   -3074, -3074,  2357,    37, -3074,  2134,  2135,  2793, -3074, -3074,
   -3074,  2773, -3074, -3074, -3074,  2363, -3074, -3074, -3074,   329,
     329,  1694,  2368, -3074,   699,  2145, -3074, -3074, -3074, -3074,
     245, -3074,   329,  2343, -3074
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -3074, -3074, -3074, -3074, -3074,     0, -3074,    61,  -164, -3074,
   -3074, -1142,  -556, -3074, -3074, -2140, -3074, -3074, -3074, -3074,
    -861, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -2172, -3074,  -986, -3074,
    1827, -3074, -3074, -3074, -3074, -3074, -3074, -3074,   327, -3074,
   -3074, -3074, -3074,  1280, -3074,   642, -3074, -3074,   -35, -3074,
   -3074,  2786, -3074,  2787,  2281, -3074, -3074, -3074, -3074, -3074,
     408,    47, -3074,   406, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074,   -89,   509,   801, -3074, -3074,
    2476,    41, -3074,  2718, -3074, -3074,  2717, -3074,  2629, -3074,
   -3074, -3074, -3074, -3074,  2495,  2181,   819,  2503,  -522, -3074,
   -3074, -3074, -3074, -3074,   820,  -646, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,   674, -3074,  2618,  2310,  2637,   101,
    2257, -3074,  2305,  1581, -3074,  2482, -3074, -3074, -3074, -3074,
    2480, -3074, -3074, -3074, -3074,  -392, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,  2295, -3074,  2298, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -1347, -3074, -3074,  -793, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  -128,
   -3074, -3074,   795, -3074, -1098, -1135,  1704, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,  1885, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,  -613, -3074, -3074, -3074, -3074, -3074,
    2075, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  -565,
   -3074,  -104, -3074, -3074, -3074, -3074,  2458, -3074, -3074,  -203,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,  1635, -3074, -3074, -3074,
   -3074,   600, -3074, -3074, -3074, -3074, -3074, -1991, -3074, -3074,
     594, -3074, -3074, -3074, -3074, -3074, -3074, -1125,  -843,   472,
     753, -3074,  -231,  -555,   653, -1112,  1344, -3074,   630, -3074,
   -2435,    -3,  -593, -3074, -3074, -2319,   333,  1627, -3074, -3074,
   -3074,   678,  1011, -3074, -3074, -3074, -3074, -3074, -3074,    62,
   -3074,  -250, -3074,  1012, -3074,   695, -3074,   387, -3074, -3074,
   -3074, -3074,  -815, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,   487, -3074, -3074, -1832, -3074,   680, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,  1479, -3074, -3074, -3074, -3074, -3074,
   -3074,  -454, -3074, -3074, -2074, -3074, -3074, -3074, -3074,   458,
   -2205, -3074, -1108, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074,  2892, -3074, -3074,
   -3074,  2821,  2874, -2247, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  -371, -3074, -3074, -3074, -3074, -3074,  2878, -3074, -3074,
    2898, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,   745, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074,  -647,  2165, -3074, -3074, -3074, -3074, -3074,  1995,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  2539, -3074,
   -3074,   -15, -3074, -3074,   743, -3074, -3074, -3074, -1106,  -167,
    2603, -3074, -3074, -3074, -3074,   804, -3074, -1040,  1918,  1039,
   -1431,  1439, -3074,   747,  1717,  -349,  -529, -3074, -3074,  2161,
    1524, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  1453, -3074,  -761, -3074,  -631, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074,  -733, -3074, -3074, -3074, -3074, -3074, -3074,
     128, -3074,  1539,  -212, -3074, -3074, -3074, -3074, -3074,   -67,
   -3074,  -525, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074,  1442, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,  -516, -3074,   803,  2507,
   -3074, -3074,   -62, -3074,  -609, -3074, -3074,   -39,   269, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074,   894, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  -107, -3074,  -369,  -366, -3074, -3074,  -358, -3074, -2699,
   -3074,   -92,   570, -1339, -3074, -3074, -3074,   919, -3074, -1998,
   -3074, -3074, -3074, -1976, -3074, -3074, -1984, -3074, -3074, -3074,
   -3074, -2304, -3074,   937,   621, -3074, -3074, -3074, -3074, -3074,
     407, -3074, -3074, -3074, -3074, -3074, -3074,  -707, -3074, -3074,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074,  -277, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074,  1063, -3074,  1064, -3074,   391,   733, -3074,
   -2518,  -186, -3074, -3074, -3074, -3074, -3074, -3074,   -31, -3074,
   -3074,  -499, -3074, -1146, -1319, -3074, -3074, -3074, -3074, -3074,
     -61, -3074, -3074, -3074, -3074, -3074, -1956, -3074, -3074, -3074,
   -3074, -3074, -3074, -2414,   676, -3074, -2602,   752, -3074, -3074,
   -2308,    59,    60,   335, -3074, -1812, -2328, -3074, -3074,  -247,
    -570, -3074, -3074, -3074, -3074, -1931, -3074, -3074, -3074,   -38,
   -3074,   287,  -958, -3074,  -405,  -299,  1100,  -294, -1861,   312,
   -3074, -2345, -3074, -3074, -3074, -3074,    -1, -3074, -1216, -2259,
    3002, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,  -719,
   -3074, -2226, -3074,  1764, -3074, -3074,   613,   331, -3074, -3073,
     328,  -160,   144, -1206, -1872, -2265,  1019,  -234,  -965, -1258,
   -3074,  1025, -3074, -3074, -3074,  1123,  -709, -3074, -3074,  -506,
    1789, -3074,   822, -3074, -3074,   449,  -133, -3074, -3074, -3074,
   -2312,  -370, -2332, -3074,  -725, -3074, -3074, -3074, -3074,  1165,
   -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074, -3074,
   -2765,  -387, -3074, -2795, -2468, -1349, -1408, -3074, -3074,  -375,
   -3074, -3074, -3074,   263, -1052,  -736,  -759,   610,   463,   127,
   -3074, -3074, -3074, -3074,  1636, -3074, -3074, -3074, -3074, -3074,
   -3074, -3074, -3074, -3074,  -300,  1285,  2505, -3074, -3074, -3074,
   -3074
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2254
static const short yytable[] =
{
      34,    36,    38,   184,   570,    38,  1310,   268,  1001,  1437,
      87,  1391,  1343,  1456,  1457,  1449,  1458,  2129,  1479,  1480,
    1497,  1972,  1973,   328,   957,   989,  1446,  2055,   408,   409,
     680,  2425,  1505,  1168,  1477,   425,  2645,    58,   236,   104,
    2039,   965,  1119,  2919,  2075,   296,  2711,  2263,  2709,   103,
     946,    58,  2201,  2202,  2821,   578,  2385,    87,   410,   411,
      33,  2360,   110,  2313,  2314,  2315,  2316,   184,   423,   117,
      33,  1445,   951,   122,  2152,  2384,   124,   125,  2686,    33,
    2688,    33,   128,   129,  1447,  2557,   184,  1174,  1991,  2898,
    1992,  1993,  3205,  3206,  3207,  1028,  1031,  2852,  2016,   578,
    2017,  1051,  2776,    58,  3174,   578,  1088,   274,  1056,   504,
     113,   588,  1063,  2301,    33,  1032,  2966,    33,  1883,  2000,
     232,  2573,   592,   235,    33,  3209,   578,  1419,   239,   593,
   -2252,  2000,  1893,  1064,  2611,   412,  1064,  1906,  2630,   427,
     274,   429,  1052,   430,   431,   432,  1073,  3139,   366,   367,
    1064,    33,   437,  1126,  1064,  2634,   448,   449,   513,   197,
     326,  1090,  3001,  1450,    33,   563,  1064,  1121,  1073,   326,
    1124,  2118,   101,  1032,  1102,    33,   333,  1073,  1888,  1167,
    1884,   274,   334,   335,  1112,  1419,   274,  3045,  1283,   331,
     255,  1125,   274,   329,   330,    33,   565,  1437,  1166,  1407,
    1408,   274,  1218,  1219,    33,  1206,  1496,   573,    33,  1102,
     578,  2118,  1081,  1102,    33,   578,    33,  1102,   184,   101,
     567,   326,   184,  1073,  2580,   578,  1073,  2766,   596,  1498,
    1499,   363,  1032,   660,    33,  2940,  2941,   369,  2942,  2943,
    2944,  2945,  2946,  2947,  3430,    33,  2930,   114,  2932,   398,
    3565,   274,  1282,  1283,    33,   407,   407,   407,   407,   407,
    3100,   326,  1032,   407,    33,  1032,   255,    33,   359,   274,
    1218,  1219,    33,  3263,  1228,  3333,    33,  1172,  2938,    33,
     446,  2577,  2122,  3105,  2123,  1034,  2124,  2820,  2619,    33,
    3562,  2622,  2940,  2941,    33,  2942,  2943,  2944,  2945,  2946,
    2947,   274,  1282,  1283,    33,   601,  1486,  1487,   604,  1172,
    2141,    33,    58,    58,   351,  2168,   326,  1060,  1061,  1236,
    1888,   326,   515,  2850,  1986,   612,   613,   614,   615,  2885,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   949,  2866,  2425,
     652,    44,  3334,  3335,  2080,  1436,    33,   633,   634,  2935,
    2938,   663,   636,  2145,   637,   425,  2646,  3226,  3481,  1110,
     326,    53,    33,    33,  2938,    54,     1,    33,  2911,   640,
     641,   642,   643,  2212,   523,  3046,   650,  1119,  1030,  1030,
     529, -2252,  1429,  1030,  1030,  1032,  2583,    33,  1043,  2684,
     317,   318,   319,   320,   321,   665,  1030,  2128,   317,   318,
     319,   320,   321,   184,     6,    54,   950,  2886,  2887,  2888,
    2889,  2890,    33,  1273,  3344,    54,  1030,  3230,    48,  1030,
    3224,  2338,   669,  2019,  3228,  1030,  2019,  2024,  2184,  1030,
    2441,  1359,  1360,  1030,   575,   578,  3005,  1030,   578,  2652,
     277,  1030,  1030,    33,  1030,  2780,    54,  1030,  3063,  1030,
    1030,  1030,  3625,  1430,  1097,  1114,  3631,  1030,     4,   370,
    1030,  1361,  1362,  1363,  2652,  1527,   184,  1030,  2707,  2358,
    2442,  3327,  2715,    54,  1030,  2733,  1000,  2702,  2705,  2705,
      54,  1030,  2705,  2584,  2735,  1228,   371,  2796,  2856,  1050,
      54,  3025,  1030,    58,    27,    54,  1030,  3064, -2252,    10,
    1030,  3336,   832,   926,  1889,  1114,  1030,  2217,    33,  1030,
    1068,  1104,    54,  1228,  3025,    10,  2948,  3025,  3065,  3068,
    3068,  3162,   589,  1077,  1166,  3328,   672,  3172,  3002,   672,
    1106,  3194,  3194,  3194,  3194,  3238,   568,   672,  1178,   184,
    3106,  1532,  3307,  2767,  3196,  3196,  3196,  3196,  2142,  2631,
    3314,  3398,  3164,  3227,   398,  3418,   398,  1231,    52,  3418,
    3168, -2252,  1227,   667,   948,   407,  2635,   575,   953,  3426,
    1493,  3532,  3573,  2948,    54,  3573,  1163,  1164,    54,  2448,
    1483, -2252,  3634,   407,  2781,  3158,  3634,  1490,  1179,  2325,
     564,  3023,  3671,  3687,   102,   975,  1287,  2232,  2233, -2252,
    1220,  3418,    26,    33,  3127,  1212,  2574,  1905,  1215,  3431,
    2867,  2902,  3245,  3231,  3248,  2339,  3140,  3251,  2174,   327,
       4,   566,  3252,    54,  2879,  1180,  3159,  3160,   518,  3500,
    2174,  1912,   574,  1388,  1230,   579,  2949,  2950,  1027,  1889,
     584,  1426,  2139,  3258,  1903,  1125,  1166,  3404,  1511,  2040,
     585,  3556,  3235,   597,  3566,  1402,  2302,  2051,   661,     7,
    1119,  1287,  3037,   672,   918,  2112,  1448,  3367,    58,    58,
      58,  1019,    58,  1023,  1025,  1451,  1500,  1033,  1035,  1036,
     999,  2511,  1041,  2860,  1025,  3377,   963,  1044,  3434,    58,
    2270,  2085,  2951,  2949,  2950,  1105,  2026,  2001,  1036,  1966,
    1967,  1221,  3030,  2100,  2352,  2055,  3154,  2869,  3350,  1033,
    1033,  1287,  2612,  1193,  3304,  1420,  3390,  2878,   590,  1036,
    1344,  3031,  1181,  2153,  3720,    58,  1409,  3060,  1452,   594,
      33,    58,  1036,    58,  1027,  1954,   404,    58,  2697,   295,
      58,     5,  1091,    58,  3323,  2632,   404,  3059,  1503,  2951,
    1025,  2507,  3563,    58,  2086,   952,  3352,   404,   407,  1108,
    3357,  1033,  2636,  1501,   279,  1115,  1976,  3309,    58,  3311,
    2450,  1228,   295,  1444,    58,  3099,   407,   407,  1231,  3535,
    3380,    58,    58,    58,  3240,  1985,   664,  1187,   282,  2320,
    1194,   167,  2565,  3539,    33,    58,  2697, -2252,  3594,  1182,
     404,    43,  1207,   168,  1207,   407,  1231,  1207,   407,  1082,
    1207,    58,  2970,   295,  3446,  1027,  1999,  1030,   295,  2952,
    2125,     7,  3194,  3194,   295,  2484,  3194,  3482,  2126,  3684,
     666,  1364,  3345,   295,  1274,  3196,  3196,  3698,  2660,  3196,
    1183,  3225,  1453,  1229,   107,  3229,  1270,    43,  1330,  2511,
       8,  1330,  1977,  1919,  3512,  2697,  3038,   670,  2020,   650,
     650,  2021,  2025,   580,  1953,  2755,   968,  1552,  1978,  2030,
    2470,   288,  2596,  2471,  2653, -2252,  2952,  2175,  3337,  3424,
    1027,  2597,  2031,   295,   155,  2953,    33,  1230,  2697,  2175,
    1377,  3452,    33,  1910,  3452,  2234,  1045,    33,  2623,  2659,
    3739,   295,  3047,  2708,  2713,  2598,  1184,  2716,  2599,  3253,
    2734,  1979,  1378,   934,  3457,  1256,  3101,  1365,  2179,  2736,
    3721,  1383,  2797,  2857,  3626,  2600,  3026,  3082, -2252, -2252,
   -2252, -2252, -2252,   295,  1919,  2954,  2955,  1030,  1030,  1030,
    3551,  3531,  2953,  1384,  2891,   174,   935,    69,  1494,  3027,
    1980,  3559,  3029,  3066,  3069,  3073,  3163,  1020,  1303,    33,
    1366,  2161,  3173,   291,  1113,  3443,    33,  3444,  3445,   175,
    3239,  2071,  1172,   105,    33,   292,   293,  3308, -2252,  1981,
    2076,   969,  3087,   294,  2032,  3315,  3399,  2150,  1982,    37,
    3419,    33,  2954,  2955,  3425,  3461,  2030,  2307,  1354,  1495,
     672,  3167,  3048,  3492,  3427,  2098,  3533,  3574,   524,  2031,
    3575,  3417,  2304,   176,  2311,  2457,  1493,  3635,  2491,  2451,
     534,  3641,   177,   581,  2311,  1310,  3656,  3672,  3688,  2601,
    2333,  2334,  2335,  2336,   109,  1033,  3719,  1347,    58,   107,
    3049,    33,     1,  2727,  2728,  2729,     2,  3254,  2328,  3255,
    1553,  2750,  2278,   609,    58,  2750,  3194,  1033,  2440,   112,
    2030,  2171,  3194,  3194,  1231,  3194,  3194,  3194,  3194,  3196,
    1435,  2494,    33,  2031,  3194,  3196,  3196,  2647,  3196,  3196,
    3196,  3196,  2602,  3740,  3424,  3424,    53,  3196,    33,  2603,
     970,  1412,  3571,  2418,   114,  2419,    58,    54,  1413,  2034,
    1537,  1115,    33,    54,  3050,   116,   178,   179,    54,   118,
    1115,  2032,  2308,  3561,  3710,  2035,  2030,  1899,  3051,    33,
    3536,  2800,    33,  1918,    58,    58,    58,  2212,    58,  2031,
      58,    58, -2252,   473, -2252,     3,    58,    58,  3150,    33,
    2720,  2721,  3088,  2604,  1232,  1233,  1234,   190,  2081,     1,
      33,   474,  3300,     2,  3303,  1235,   317,   318,   319,   320,
     321,  2563,  1922,  3020,  3129,   961,    33,   962,  2476,  1525,
      54,    58,  3152,    33,  3294,  2032,    33,  1114,   928,  2114,
    1536,  2045,   191,    58,  1106,    54,    33,  3194,  1544,  1459,
    3194,  3194,  3194,  3194,  2706,  2279,  2418,  2710,  2419,  2420,
    3196,   929,  2421,  3196,  3196,  3196,  3196,    58,    58,   194,
    2101,  3260,   233,  2505,  2280,  2281,    58,   234,  3452,  3052,
      76,  2309,  3463,  2777,  2212,   243,  2034,    77,  2329,  2289,
    2030,  2032,    58,    58,  2282,  3053,    33,  2730,   987,  2330,
     241,   990,  2035,  2031, -2252,  2054,  1024,  1554,    33,   250,
     475,   476,   477,   478,   479,   480,  2027, -2252,  1956,  2029,
    3261,  2217,   253, -2252,  3657,   251,  1303,  1303,   481,   482,
     483,  3464,  2340,    78,    79, -2252,  1303,  2497,   254,  3194,
    1555,    80,  3395,  1114,    33,   425,  1032,  3194,    33,  1998,
    2034,  3394,  3196,  1383, -2252, -2252,     4,  2004,   257,    54,
    3196,  3402,  2420,   106,   107,  2421,  2035,   258,  2158,  2159,
    1279,  1280,  1281,    54, -2252,  1384,   274,  1282,  1283,    33,
    3468,  2212,  3655, -1615,   415,   259,  1310,  2212,   260,   416,
      54,   418, -2252,    54, -2252,  2651,   677,   323,  2654,  2655,
    2656,  2657,  3617,  3618,   932,  2032,  2034,  2041,    26,    27,
      54,  2046,  2052,  2046,   261,  1435,  2064,    33,  2217, -2252,
    2834,    54,  2035,  2058,  2060,  2061,   413,   414,    58,  2065,
    2067,  2068,  2069,  1033,  1119,  3658,  -283,    54,  3028,  3659,
     928,  1096,  1033,  3704,    54,  3094,  2055,    54,  2970,  1460,
    1103, -2252,    33,  1115,    58,  3469,    58,    58,    58,   262,
     375,  2792,  1258,   929,  1284,    58,    58,  1033,   484,    58,
     407,   485,   407,    58,  1523,  2033,    33,     5,  3301,   263,
    2920,  1115,  2922,  3449,  2923,    33,  3454,  2113,  2115,  3456,
    3355,  3680,   264,  3682,    58,    58,  1210,    33, -2252,  1213,
    2212, -2252,  1969,  2475,  1970,  1192,   265,  3674,  2278,  1198,
    2934,  2401,  2937,  1202,    33,  2217,   355,  3470,  2871,  3471,
    2034,  2217,  -283, -2252,  2575,   266,     6,   384, -2252,  3542,
    1014,  3545,  3546,  3547,  3548,  3472,  2035,   267,  -283,    58,
      58,   269,    58,  3473,  2897,  1211,   376,  3474,  1214,  1251,
    1252,  1217,  1245,  2240,  3658,  2241,  2242,     7,  3659,  2244,
    2245,   311,   377,  1246,   312,  2264,  2156,  2430,   407,   407,
    2562,  3663,  3475,   407,   313,    58,  1461,  2165,  2166,  1379,
    1380,  -283,  1462,  1463,  1464, -2252,     8,  3537,  3676, -2252,
    1114,   486,  2183,   107,  2466,    81,   314,   474,   324,   362,
      58,  1066,   415,  2248,  1465,   378,   487,   416,   417,   418,
     488, -2252, -2252,   385,  1247,  1075,   338,   339,   340,  1080,
    -283,    82,   438,  1957,   315,   106,   107,   373,  1248,   386,
     374,  1094, -2252,   383,  2217, -2252, -2252,  3663,   428, -2252,
    1392,  1393,  1394, -2252,   379,   392,  2324,   489,  1976,  -283,
    2059,  2279,    33,  2637,  3676,  1484,  1485, -2252,  -283,  1488,
    1489,  2273,  2274,  2005,  2006,  2007,  2008,  2062,   316,    33,
    2280,  2281,   387,   380,   346,   490,   158,   159,   347,  1310,
    2702,  2463,   381,   348,   160,    33,  2296,  2297,   325,  1125,
    2282,    83,   352,   491,  2666,  3576,   475,   476,   477,   478,
     479,   480,  2133,  3070,  2066,  2294,    33,  2295,   439,  1958,
    1466,   388,   353,  1467,   481,   482,   483,  1249,  2739, -2252,
      33,  1468,  1166,   357,   440,  1959,   361,  3364,  2197,  2198,
    3195,  3195,  3195,  3195,  1977,  2298,  2299,  2925,  3110,  2638,
     389,  3244,  3244,  3136,  3244,  3107,  2756,  3244,  2757,   390,
    1978,  2742,  2936,    33,   364,  2639,  1469,  2768,  1285,   393,
    3149, -2252,   368,  2960,  2437,   161,   399,   441,  1960,  3715,
    1286,    33,  1529,   402,   492,  2431,  2432,   162,  2628,  3332,
    2007,  2008,  2789,    84,  2009,  2010,  2011,  2012,  2013,  2014,
    2082,  1470,  2082,  1979,   403,  3247,  1287,  3250,  2640,   106,
     107,  1232,  1233,   433,   163,   435,   442,  1961,  3689,  3690,
    1471,  1472,  1506,  1507,  1508,  1509,  2249,  3043,  3044,  3406,
    3407,  1473,   436, -2252,   447, -2252,  1474,  1288,  3422,  3423,
    2667,  2250,  1980,   450,  3433,   443,  1962,  2641,  2751,   457,
     493, -2252,  2668,  1290,   444,  1963,   451,  2251,   453, -2252,
     454,   455,   456, -2252,   484,   506,   517,   485,  2252,   519,
    1030,  1981,  1530,    85, -2252,  1475,  2642,   521,  3115,   332,
    1982,    86,   526,   337,  2251,  2643,  3123,  3124, -2252,  2253,
    3469,   527,  3408,  1291,   528,  2252,  2254,   530,  2582,  2793,
     531,   535,   536,   537,  2255,  1292,    54,  1476,   164,  2009,
    2010,  2011,  2012,  2013,  2014,   540,  2253,   317,   318,   319,
     320,   321,  2286,  2254,  2505,   541,  2256,  1319, -2252,   551,
    1321,  2255,  1322,  1323,  1324,  1325,  1326,  1207,   407,   407,
     552,   553,   556,   561,    58,    58,  1293,   571,  2828,   572,
     577,  2341,  3470,  2256,  3471,  1310,   582,  2009,  2010,  2011,
    2012,  2013,  2014,   583,  2236,  1033,   587,  1033,  1033,   595,
    3472,  1033,  1033,   602,  2246,  2324,   605,  1033,  3473,  1294,
     606,   607,  3474,  2449,   505,  1295,   610,   486,   635,   638,
     644,   645,  1030,   651,  1296,  1297,   653,  1298,   654,  2346,
     655,    58,   487,   657,   656,   165,   488,  3475,   658,  1299,
    1300,   659,  2290,   662,   668,   678,   933,  1301,     1,  3534,
    1302,   938,   960,   940,   941,  1030,   942,   947,   295,   956,
    2257,  3195,  3195,   958,   959,  3195,  2258,   967,  2520,  2522,
     166,  1125,   972,   489,  1303,   974,  1303,  1166,   976,   977,
     978,   995,  3256,   997,  3244,  1002,  1303,  1303,  1033,  1003,
    1005,  1007,  1303,  1303,  1303,  1303,  1006,  1008,  2098,  3006,
    1010,   490,  1011,  1166,   167,  1115,  1012,  1013,  2462,  1015,
    1123,  2532,  1199,  1260,  3007,  3008,   168,  1261,  1262,   491,
    1263,  1264,  1266,  3009,  1265,  1267,   650,  2041,  1040,  1268,
    1269,  1271,  2046,  1272,  1275,  1276,  3074,  1277,  2052,  1278,
    1049,  2046,  1320,  1327,  1328,  1332,  1329,  1333,  1335,  1336,
    1337,  1338,  3543,   169,  1339,  1347,  1340,  3010,  3543,  2399,
    1341,  3552,  3553,  3554,  3555,  2403,  3011,  3370,   170,  1069,
    1345,  3104,  1346,  1376,  1350,  1351,   171,  1437,  1352,  1353,
    1357,  1381,  1382,  1385,  1389,  1086,  1087,  1387,  1386,   172,
    1406,  1093,  1395,  2428,  1095,  3012,  1411,  1414,  1410,  1415,
     492,  1423,  1417,  1422,  1425,  1434,  1033,  1115,  1438,  1418,
    2444,  2445,   107,   407,  1481,  1440,  1492,  1441,  1491,  1496,
    1519,  1520,  1521,  1522,  1526,  3372,  1531,  1528,    58,  3420,
    3421,  3422,  3423,   173,  1532,  1541,  1543,  1879,  1880,  1881,
    3013,   578,  1882,  1887,  1895,  1896,  1891,  2473,  2859,    58,
    1894,  3197,  3197,  3197,  3197,  1897,  1965,  1952,   174,  1955,
    1968,  1944,  2023,  1974,  1975,  2018,   493,  1987,  1988,  1989,
      58,  1990,  2498,  1544,  1994,  1303,  1995,  2883,  1115,    58,
    1996,  1997,   175,  3633,  3014,  2044,  3636,  3637,  3638,  3639,
    3503,  2057,  2072,  2899,  2073,  3195,   407,   407,  2077,  3511,
    2074,  3195,  3195,  2078,  3195,  3195,  3195,  3195,  2079,  2092,
    1503,   407,  2108,  3195,  2099,  3517,    58,    58,    58,  2106,
    2118,  2110,    58,  2120,  2131,  2143,   176,  2132,  2144,  2203,
    1033,  2204,  2146,  2205,  2206,   177,  2157,  2162,  2148,  2178,
    2207,  2208,  2180,  2160,  2186,  2324,  2188,  2324,  2171,  2185,
    2009,  2010,  2011,  2012,  2013,  2014,  1889,    58,  2786,  1125,
    1125,  2226,  2224,  2227,  1030,  2618,  2618,  2235,  2229,  2618,
    1030,  2287,  2291,  2293,  2292,  3693,  2300,  2302,  1985,  2325,
    3458,  2317,  2960,  2342,  2337,  2348,  2349,  2350,  1303,  2353,
    2355,  2354,  2358,  2389,  2390,  2391,  1030,  1303,  2387,  2393,
    1303,  1303,  1303,  1303,  2658,  2394,  2396,  1033,  3560,  2408,
    2407,  2663,  1303,  2392,  2409,  2681,  2410,  2405,  2411,   178,
     179,   184,  2413,  2414,  2415,  2429,  3195,  2416,  2434,  3195,
    3195,  3195,  3195,  1053,  1053,  2698,  2698,  2698,  1888,  2452,
    2698,  1303,  2712,  2459,  2435,  2041,  2454,  2417,  2455,  2461,
    2464,  2468, -2252,  2469,  2474,  2477,  3346,  2478,  3266,  3267,
    3268,  3611,  3270,  3271,  3272,  3273,  3274,  3275,  2481,  2487,
    2501,  3278,  2511,  2437,  2737,  2513,  2738,  2740,  2560,  2741,
    2743,  2495,  2591,  2745,  3361,  1235,  2561,  2046,  2572,  2578,
    2586,  2046,    58,  2587,    58,  2588,  2592,  2593,  2626,  2608,
    1033,  2698,  2615,    58,  2428,  2627,  2607,  2773,  2773,  2648,
    2629,  2650,  1058,  2633,  1128,  1129,  1130,  1131,  3195,  2649,
    1310,  2115,  2662,  2678,  2683,  2685,  3195,  2687,    58,  2690,
    2689,  1053,  2717,  2748,  2304,  2791,  1074,  2694,    58,  2718,
    2306,  1222,  3197,  3197,  2719,  2722,  3197,    58,  2764,  2753,
    2723,    58,  2784,  2724,  2782,  2788,  2787,  2790,  2725,  2726,
    2794,  2802,  2803,  3664,  3665,  3666,  3667,  3668,  3669,  2807,
    2805,  3686,  3616,  2806,  2809,  2810,    58, -2252,  2826,  2829,
    2808,  1493,  1161,  2833,  1234,  2842,  2844,  2853,  2827,  2854,
    2858,  2855,  1176,  2862,  2863,  1191,  2900,  2905,  2870,  1197,
    2835,  2895,  2872,  2913,  2914,  1203,  2918,  1205,  2209,  2915,
    2916,  2210,  2917,  2211,  2921,  2938,  2964,  2924,  2926,  2939,
    2961,  2927,  2928,  2929,  3023,  2973,  3032,  3022,  3024,  3035,
    3036,  3039,  1950,  2212,  3041,  3061,  3042,  1132,  3062,  3071,
    3072,  3075,  3078,  2213,  3085,  1133,  3089,  3077,  3096, -2216,
    1033,  3093,  1030,  1030,  1134,  3103,  2203,  1135,  2204,  3111,
    2205,  2206,  3114,  3630,  2214,  2698,  3122,  2207,  2208,    63,
    3132,  3144,  3155,  2874,  2246,  2698,  3156,  3164,  2236,  1033,
     926,  1303,  3171,  3174,  3175,  2000, -2252,  2215,  1304,  3223,
    3232,  2216,  3216,  3233,  2236,  1033,  3257,  3259,    58,  2618,
    1136,  3145,  3646,  3147,  3234,  3265,  3246,  1137,  3236,  3462,
    3269,  3237,  3249,  3264,  3276,  3277,  3283,  3284,  3681,  3287,
    3288,  3049,  3289,  3290,  1459,  3312,  3505,  3291,  3292,  3293,
    3298,  3305,  3306,  3310,  3320,   156,   187,  3316,  3317,  1303,
    3321,  3347,  3348,  3515,  2506,  3349,  3341,  1033,   926,  1033,
    3134,  3350,  1303,  3362,  1303, -2252,  3366,  3368,  3371,  3375,
    3383,  3113,  1229,  3386,  1138,  1303,   650,  2217,  1222,  3396,
    2698,    58,  2681,  2361,   650,   650,  3197,  3418,  3428,  3409,
    3429,  3410,  3197,  3197,  2698,  3197,  3197,  3197,  3197,  1139,
    3743,  3411,  3390,  3435,  3197,  3412,  1140,  3438,  1141,  3413,
     187,  3414,  2046,  3415,  3439,  3440,  3441,  3442,  1142, -1803,
    3466,  3447,  3630,   184,  3484,  3020,  3485,  3486,  3488,   187,
    2052,  3489,  2046,  3490,  3491,  3495,  3497,  3498,  3504,  3510,
    3508,  3514,  3518,  3516,  3519,  2399,  1143,  3520,  3522,  3524,
   -2252, -2252,    58,  3528,  1144,  2001,  3540,  3557,  3538,  3577,
    3567,  3589,  3568,  3569,  3549,  3587,  3588,  1399,  3590,  3592,
    3609,  3591,  3597,  3610,  3615,  3622,  3632,  2428,  3642,  3095,
    3654,  3097,  3670,  3644,  2698,  1033,  3683,    58,  3692,  3694,
    3695,  1145,  3696,  3697,  3699,  3596,  3708,  3727,  3731,  3732,
    3729,  3730,    58,  3733,    58,  3119,    58,  3118,  3738,  3067,
    3707,  3742,  2818,  2170,  2486,    49,  1146,  3197,    50,    58,
    3197,  3197,  3197,  3197,  1342,  2769,  1303,  3092,   833,  2778,
     532,  3437,   193,  2324,  1460,   198,   345,  1166,  1004,   407,
     525,   407,  2343,   358,  2344,  2209,   671,  1222,  2210,   350,
    2211,    58,    58,  1147,   511,   512,   966,  1303,   533,  1971,
     937,   187,   943,   558,  1148,   187,   560,   944,  3705,  2698,
    2212,  1161,  2402,   591,  1334,  1186,  2616,  2624,  2446,  1512,
    2213,  1518,  2760,  3193,  3193,  3193,  3193,  2698,  2698,  1948,
    3359,  2196,  3385,  3143,  2510,  2200,  2832,    58,  3728,  2530,
    2765,  2529,  3218,  3363,  2103,  3513,  1304,  1304,    46,  3197,
     471,   472,   473,   130,    60,  3479,  1304,  3197,    61,  2362,
      47,  1092,  2493,  3354,  2215,  1259,  2496,  2223,  2216,   516,
     474,  1356,  2138,  2500,  3467,  1303,  1303,  3578,  1885,  2363,
    2364,  2365,  1122,  2094,  2136,  3711,  1303,  1303,  2084,  1303,
    3297,  3586,  1303,  3296,  1303,  2465,  2151,  3138,  1303,   611,
    3279,  1461,  1149,  1150,  1151,  3018,  3343,  1462,  1463,  1464,
    3501,  3499,  3496,  3326,  2754,  1152,  2388,  2357,  2366,  2714,
    3714,  2864,  3460,   184,  2884,  2266,  2267,  2590,  3403,  1465,
    2367,  3299,  3593,   650,  2581,  3322,  2661,  3241,    58,  3242,
    2933,  2368,  3455,  3645,  2217,  3034,  3318,  2239,  3483,  3019,
      42,    58,  3737,  2972,  1936,  2971,  3405,  3170,  2369,  2319,
    2698,  3302,  2698,  3459,  2318,  2231,  3624,  3494,  2370,   475,
     476,   477,   478,   479,   480,  1902,  2876,  3494,  3401,  3541,
    2194,  3558,  3550,  2371,  2785,   639,  1033,   481,   482,   483,
     679,  3102,     0,     0,     0,     0,   187,     0,  3324,  3325,
    2102,     0,  2745,     0,     0,  2046,     0,     0,     0,     0,
       0,     0,    58,     0,  1222,     0,     0,     0,  1153,     0,
       0,     0,  2773,     0,     0,  3356,  2773,     0,     0,     0,
     407,  2372,     0,     0,     0,  1466,     0,     0,  1467,     0,
      58,     0,     0,   407,     0,    58,  1468,     0,     0,     0,
    3502,     0,     0,     0,    58,     0,  2087,  2088,  2089,   187,
       0,  2373,     0, -2252,     0, -2252,     0, -2252, -2252,     0,
    1030,  2374,     0,  2107, -2252, -2252,     0,     0,     0,     0,
       0,  1469,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2375,  3387,     0,     0,  2376,     0,     0,  2698,
       0,     0,     0,     0,     0,     0,     0,     0,  2874,  2698,
       0,  2236,  2236,     0,  3193,  3193,  1470,     0,  3193,     0,
       0,     0,     0,     0,  2377,     0,     0,   484,     0,  3416,
     485,     0,   187,  2378,     0,  1471,  1472,     0,     0,     0,
    2140,     0,     0,     0,     0,     0,  1473,     0,     0,     0,
       0,  1474,    58,  2236,     0,     0,     0,     0,  1512,     0,
    1016,  1017,  1018,     0,  1021,     0,     0,  2268,  2269,     0,
       0,     0,     0,     0,  2285,  1033,  2167,     0,     0,     0,
       0,  1047,     0,  1115,     0,     0,  1115,  2182,     0,  1303,
    1475,     0,  1303,     0,  1303,     0,  2698,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1071,     0,     0,
      58,     0,  1476,  1076,     0,  1078,     0,     0,     0,  1085,
       0,     0,  1085,     0,     0,  1085,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,  1303,     0,
    1098,     0,     0,     0,     0,   487,  1157,     0,     0,   488,
       0,     0,     0,  1021,  1170,  1173,     0,     0,   407,  1188,
       0,     0,    58,     0,     0,     0,     0,  1200,     0,  3204,
    3204,  3204,  3204,     0,     0,     0,     0,     0,     0,    58,
       0,  3621,     0,  1224,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,  1303,     0,   490,  2698,     0,     0,     0,     0,
       0,     0, -2252,     0,     0, -2252,  1303, -2252,  3193,     0,
       0,     0,   491,     0,  3193,  3193,     0,  3193,  3193,  3193,
    3193,     0,     0,  2698,   184,  2698,  3193, -2252,  1303,   466,
     467,   468,   469,   470,   471,   472,   473, -2252,     0,     0,
    2467,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,     0,     0,     0, -2252,     0,
       0,     0,     0,    58,     0,     0,     0,     0,    58,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2508, -2252,     0,     0,     0, -2252,   650,     0,  2698,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1222,     0,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3387,
       0,     0,     0,     0,     0,  1303,     0,     0,     0,  3193,
       0,     0,  3193,  3193,  3193,  3193,  3640,     0,     0,     0,
       0,     0,     0,   475,   476,   477,   478,   479,   480,   493,
    3643, -2252,     0,     0,     0,     0,     0,     0,     0,     0,
    1115,   481,   482,   483,  1303,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
    1224,     0,     0,     0,     0,    58,    58,    58,    58,    58,
      58,     0,   474,     0,     0,     0,  1400,  3675,     0,     0,
       0,     0,     0,     0,  1304,     0,  1304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1304,  1304,     0,     0,
       0,  3193,  1304,  1304,  1304,  1304,     0,     0,     0,  3193,
    3204,  3204,  2665,     0,  3204,     0,     0,     0,  1428,     0,
       0,  1279,  1280,  1281,     0,     0,     0,   274,  1282,  1283,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1455,  1455,  1455,     0,
    1455,     0,  1455,  1455,  1303,     0,  3716,     0,    63,    63,
       0,  2533,  2534,  2535,  2536,     0,     0,  2537,  2538,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,  3453,
       0,   484,  3453,     0,   485,     0,     0,     0,     0,   481,
     482,   483,     0,  1173,     0,     0,  3735,  3736,  3716,     0,
       0,     0,     0,     0,     0,  1539,     0,    58,     0,  3744,
       0,     0,     0,     0,     0,  1284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1224,
    1400,     0,     0,     0,  2814,  2815,     0,     0,  1892,     0,
       0,     0,     0,     0,     0,  2824,     0,     0,     0,     0,
    1053,  1399,     0,     0,  1900,  1900,     0,     0,     0,     0,
    2539,     0,     0,     0,  1907,     0,  2412,     0,     0,  2836,
    2837,  2838,  2839,  2840,  2841,     0,     0,     0,     0,  2846,
    2847,  2848,  2849,     0,     0,  1304,  2851,     0,     0,     0,
       0,     0,  2436,     0,     0,     0,     0,     0,     0,  2089,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   488,     0,     0,  1512,     0,     0,   484,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,  2306,     0,  3204,  2483,     0,     0,     0,     0,
    3204,  3204,     0,  3204,  3204,  3204,  3204,     0,     0,     0,
     489,     0,  3204,     0,     0,     0,  1908,     0,  2903,  2904,
       0,     0,     0,     0,  1909,  2908,  2909,     0,     0,     0,
    1910,     0,  1911,     0,     0,   271,     0,     0,   490,     0,
       0,     0,     0,  1912,   272,   273,     0,     0,  1304,     0,
     274,   275,   276,    33,     0,     0,   491,  1304,     0,     0,
    1304,  1304,  1304,  1304,     0,     0,    63,     0,    63,  1173,
    1085,  1913,  1304,     0,     0,     0,     0,  2093,  1098,     0,
       0,  1173,     0,     0,     0,  2104,     0,  1914,     0,     0,
       0,     0,  1915,     0,     0,  2666,     0,     0,     0,     0,
       0,  1304,   486,     0,  1916,     0,  1224,  1157,     0,     0,
       0,  1917,     0,     0,     0,     0,     0,   487,     0,     0,
       0,   488,     0,     0,     0,  3204,     0,     0,  3204,  3204,
    3204,  3204,     0,   161,     0,     0,     0,   492,   277,     0,
       0,     0,     0,     0,     0,   162,     0,  2540,     0,     0,
       0,  2137,  1157,     0,    63,     0,  3453,     0,   489,  1285,
    2541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1286,   163,     0,     0,  3083,  3084,     0,     0,     0,
       0,     0,     0,     0,  3091,     0,   490,  2163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1287,  1222,     0,
       0,     0,     0,   493,   491,     0,     0,     0,     0,     0,
       0,     0,  2190,     0,     0,     0,   569,  3204,  2744,     0,
       0,  3125,  3126,  2542,     0,  3204,     0,     0,  1288,  2543,
       0,  2667,  2758,  2759,  2089,  2762,     0,     0,     0,     0,
       0,     0,     0,  2668,  1290,     0,     0,     0,  3146,     0,
    3148,     0,     0,  2783,     0,     0,     0,     0,     0,     0,
    1918,     0,     0,     0,    54,  1919,   164,     0,  2544,     0,
       0,  1985,  1920,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1291,   492,     0,     0,     0,     0,
       0,     0,  2545,     0,  1921,     0,  1292,     0,     0,  1922,
       0,     0,  2546,  2547,     0,     0,     0,     0,  2548,     0,
       0,  3219,  3220,     0,     0,  3221,  3222,     0,  2549,  2825,
     458,   459,   460,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,  1293,     0,     0,
    2550,  1304,     0,  2551,  2552,     0,     0,     0,  2553,     0,
       0,   493,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   278,     0,
    1294,     0,     0,     0,     0,     0,  1295,     0,     0,     0,
       0,     0,     0,     0,     0,  1296,  1297,     0,  1298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,  1304,
    1299,  1300,     0,     0,     0,  2554,     0,     0,  1301,     0,
    3286,  1302,  1304,     0,  1304,     0,  2555,     0,     0,   295,
       0,  2893,     0,  2894,     0,  1304,     0,     0,     0,     0,
       0,   271,   167,     0,     0,     0,     0,     0,     0,     0,
     272,   273,     0,     0,   168,     0,   274,   275,   276,    33,
       0,     0,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,   279,     0,     0,     0,     0,   280,     0,     0,
     281,   481,   482,   483,     0,     0,     0,  1304,     0,     0,
       0,   169,     0,     0,     0,     0,   282,     0,     0,     0,
       0,  3353,     0,     0,     0,  3358,   170,     0,     0,     0,
       0,   283,     0,     0,   284,     0,     0,   285,     0,     0,
       0,     0,     0,     0,  3365,     0,   286,   172,     0,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   132,  3376,   277,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,     0,  2222,  1224,     0,     0,
       0,     0,     0,     0,     0,     0,   646,   287,   133,     0,
       0,   173,     0,     0,     0,     0,     0,     0,   163,   288,
       0,   133,     0,     0,     0,     0,  1304,   134,   135,     0,
     289,     0,     0,     0,     0,  3076,   174,     0,  3081,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2272,     0,     0,     0,  1304,     0,     0,
     290,   484,     0,     0,   485,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     136,     0,     0,  1304,  1304,  1304,  1304,     0,     0,     0,
     138,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1161,   138,   176,     0,     0,   139,     0,     0,
      54,   291,   164,   177,     0,     0,     0,   140,     0,     0,
     139,     0,     0,   292,   293,     0,     0,     0,     0,     0,
     140,   294,   141,     0,     0,  1304,  1304,     0,     0,     0,
       0,     0,   295,     0,     0,   141,  1304,  1304,     0,  1304,
       0,     0,  1304,     0,  1304,     0,     0,     0,  1304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,  1053,  1053,  1053,     0,  1053,  1053,
    1053,  1053,  1053,  1053,   486,   142,     0,  1053,     0,     0,
       0,     0,     0,     0,     0,   143,     0,   178,   179,   487,
       0,     0,     0,   488,   586,     0,     0,     0,   143,   165,
     144,     0,     0,     0,   278,     0,     0,   145,     0,     0,
     146,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,   146,  3527,     0,     0,  3530,     0,     0,
     489,   147,     0,     0,   166,   148,     0,     0,     0,     0,
    2458,     0,     0,     0,   147,     0,     0,     0,   148,     0,
       0,     0,     0,     0,   149,     0,     0,     0,   490,     0,
       0,  1173,     0,     0,     0,     0,     0,   149,   167,     0,
       0,     0,   150,     0,     0,     0,   491,     0,     0,     0,
     168,     0,   156,     0,     0,   150,     0,     0,     0,     0,
       0,  1157,     0,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,   280,  1222,     0,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,  1173,  2564,
    1173,     0,   170,     0,  1021,     0,     0,   283,     0,     0,
     284,     0,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   172,     0,     0,     0,   492,     0,     0,
    3360,     0,     0,     0,  1304,  1304,     0,     0,  1304,  2610,
       0,  3619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1396,   287,     0,     0,  3378,   173,     0,     0,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,     0,   174,   493,  3647,  3648,     0,  3650,     0,  3652,
    3653,     0,     0,  1304,     0,     0,  1304,     0,     0,  1304,
       0,     0,  1304,     0,  1304,     0,   290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,   272,   273,     0,     0,     0,     0,   274,   275,
     276,    33,     0,     0,     0,     0,     0,     0,     0,     0,
     176,     0,     0,     0,  3700,     0,  3701,   291,     0,   177,
       0,     0,     0,     0,  1173,     0,  1173,     0,  1304,   292,
     293,     0,     0,     0,     0,  1173,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
    3713,     0,     0,     0,   187,     0,     0,     0,     0,     0,
    1173,     0,     0,     0,     0,     0,     0,  3722,  3723,     0,
    1224,  3724,     0,     0,  3726,     0,     0,     0,     0,  2798,
       0,   161,     0,  2801,     0,     0,   277,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,  1304,   178,   179,     0,     0,     0,  2823,     0,
       0,     0,     0,     0,     0,     0,  1304,     0,  1304,     0,
     163,     0,     0,     0,  1304,  1304,     0,  1304,  1304,  1304,
    1304,  3506,     0,     0,   271,     0,  1304,     0,  1304,     0,
       0,     0,     0,   272,   273,     0,     0,     0,     0,   274,
     275,   276,    33,     0,  1304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3529,     0,     0,     0,     0,
    2665,     0,     0,     0,     0,     0,     0,     0,     0,  1279,
    1280,  1281,     0,     0,     0,   274,  1282,  1283,    33,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,   272,   273,     0,     0,     0,     0,   274,   275,   276,
      33,     0,    54,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1222,
    2901,     0,   161,     0,     0,     0,     0,   277,     0,     0,
       0,     0,     0,     0,   162,  1304,     0,     0,     0,  1304,
       0,     0,  1304,  1304,  1304,  1304,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,   163,     0,  1284,     0,     0,     0,     0,     0,     0,
    1304,     0,     0,     0,  1304,     0,     0,   474,     0,     0,
     161,     0,     0,     0,     0,   277,     0,     0,     0,     0,
       0,     0,   162,  1173,     0,  2975,  2976,     0,  2977,  2978,
    2979,   165,     0,     0,     0,     0,   278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1304,     0,     0,     0,     0,   166,     0,     0,  1304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,  1173,     0,     0,     0,     0,     0,
     167,     0,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,   168,  3673,  1304,     0,     0,     0,     0,  1114,
       0,     0,     0,     0,   481,   482,   483,     0,  2980,  1173,
     279,     0,     0,     0,     0,   280,  2981,     0,   281,     0,
       0,    54,     0,   164,  3116,     0,  1047,     0,  3120,   169,
       0,     0,     0,     0,   282,     0,     0,     0,     0,     0,
       0,  3131,     0,     0,   170,     0,   187,  1222,     0,   283,
    2982,     0,   284,     0,     0,   285,     0,     0,     0,  2983,
       0,     0,   165,     0,   286,   172,     0,   278,     0,     0,
       0,     0,     0,  3151,  3153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2984,  2985,
       0,     0,  3725,     0,  1281,     0,     0,   166,   274,  1282,
    1283,    33,     0,  2666,     0,   287,     0,     0,     0,   173,
       0,     0,     0,     0,     0,     0,     0,   288,     0,  3217,
     165,     0,     0,     0,     0,   278,     0,     0,   289,     0,
    2761,   167,     0,  2986,   174,     0,     0,     0,     0,     0,
       0,     0,     0,   168,   484,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,   166,     0,     0,   290,     0,
       0,   279,     0,     0,     0,     0,   280,  1285,     0,   281,
       0,     0,     0,     0,     0,     0,     0,  2987,     0,  1286,
     169,     0,     0,     0,     0,   282,  1284,     0,     0,   167,
       0,     0,     0,     0,     0,   170,     0,     0,     0,     0,
     283,   168,   176,   284,     0,  1287,   285,     0,     0,   291,
       0,   177,     0,     0,     0,   286,   172,     0,     0,   279,
    3280,   292,   293,     0,   280,     0,     0,   281,     0,   294,
       0,     0,  2988,  3295,     0,     0,  1288,     0,   169,  2667,
     295,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,  2668,  1290,   170,     0,  3135,   287,     0,   283,     0,
     173,   284,     0,     0,   285,     0,     0,   486,   288,     0,
       0,     0,     0,   286,   172,     0,     0,     0,     0,   289,
       0,     0,   487,     0,     0,   174,   488,     0,     0,     0,
       0,     0,  1291,     0,  1173,   178,   179,     0,     0,     0,
       0,     0,     0,     0,  1292,     0,   187,     0,     0,   290,
       0,     0,  1114,     0,   287,     0,     0,     0,   173,     0,
       0,     0,  1173,   489,     0,     0,   288,  1157,     0,     0,
       0,     0,     0,     0,     0,     0,  1224,   289,     0,     0,
       0,     0,     0,   174,     0,  1293,     0,     0,     0,     0,
       0,   490,     0,   176,     0,     0,     0,     0,     0,     0,
     291,     0,   177,     0,     0,     0,     0,   290,     0,   491,
       0,     0,   292,   293,     0,     0,     0,     0,  1294,     0,
     294,     0,     0,     0,  1295,     0,     0,     0,     0,     0,
       0,   295,     0,  1296,  1297,     0,  1298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1299,  1300,
       0,   176,     0,     0,     0,     0,  1301,     0,   291,  1302,
     177,     0,     0,     0,     0,     0,     0,   295,     0,     0,
     292,   293,     0,     0,  1157,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,     0,   178,   179,     0,   295,
     492,     0,     0,     0,     0,     0,     0,     0,  2989,  2990,
    2991,  2992,  2993,  2994,  2995,  2996,  2997,  2998,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1285,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3280,     0,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,     0,  1287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1556,
    1557,  1558,  1559,  1560,  1561,     0,  1562,  1563,  1564,     0,
       0,     0,  1565,  1566,  1567,  1568,  1569,  1570,     0,  1288,
       0,     0,  1289,     0,     0,     0,     0,  1571,     0,     0,
       0,     0,     0,     0,  1173,  1290,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1572,     0,     0,
       0,  1173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1291,     0,     0,     0,  1157,
       0,     0,     0,     0,     0,     0,     0,  1292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1573,     0,     0,     0,     0,     0,
       0,     0,     0,  1574,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1293,     0,
       0,  1575,  1576,     0,     0,     0,     0,     0,     0,     0,
    1577,     0,     0,     0,     0,     0,     0,  1578,  1579,     0,
       0,  1580,  1581,  1582,  1583,  3280,     0,  1584,  1585,     0,
    3581,  1294,  3583,     0,     0,     0,     0,  1295,     0,     0,
       0,     0,     0,     0,     0,     0,  1296,  1297,     0,  1298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1299,  1300,  1173,     0,     0,     0,  1586,     0,  1301,
       0,     0,  1302,     0,     0,     0,     0,     0,     0,     0,
     295,  1224,     0,     0,     0,     0,     0,   187,     0,  1587,
       0,     0,     0,     0,     0,  1588,     0,     0,     0,     0,
       0,  2193,  1589,     0,  1590,     0,     0,     0,     0,  1591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1455,  1455,  1455,
    1455,  1455,  1455,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1594,     0,     0,     0,
       0,     0,  1595,     0,     0,     0,     0,     0,     0,     0,
       0,  1596,  1597,     0,     0,     0,     0,     0,  1598,     0,
       0,  1599,  1600,     0,     0,     0,  1601,     0,     0,     0,
       0,     0,  1602,  1603,     0,     0,     0,     0,     0,  1604,
    1605,  1606,     0,     0,  1607,  1608,  1609,     0,     0,     0,
    1610,     0,     0,     0,  1611,     0,  1612,     0,     0,     0,
       0,     0,     0,  1613,  1614,  1615,  1616,     0,  1617,  1618,
       0,     0,     0,  1619,  1620,     0,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,     0,     0,     0,     0,     0,  1628,  1629,
    1630,     0,  1631,  1632,     0,     0,     0,  1633,  1634,  1635,
    1636,  1637,  1638,  1639,  1640,     0,  1641,     0,     0,  1224,
    1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,
    1672,  1673,  1674,  1675,  1676,  1677,  1678,     0,  1679,  1680,
       0,     0,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,     0,  1691,  1692,  1693,  1694,  1695,  1696,  1697,
    1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,     0,     0,
    1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,     0,
    1715,  1716,  1717,  1718,     0,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
    1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,
    1754,     0,  1755,  1756,  1757,  1758,  1759,  1760,     0,     0,
    1761,  1762,     0,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,     0,
       0,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,
    1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,     0,     0,     0,     0,  1851,  1852,  1853,
    1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1862,     0,
       0,     0,     0,     0,     0,     0,  1863,     0,     0,     0,
       0,  1864,     0,     0,     0,  1865,     0,     0,  1866,  1867,
    1868,  1869,     0,     0,  1870,  1871,     0,  1872,  1873,  1874,
    1556,  1557,  1558,  1559,  1560,  1561,     0,  1562,  1563,  1564,
       0,     0,     0,  1565,  1566,  1567,  1568,  1569,  1570,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1572,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1573,     0,     0,     0,     0,
       0,     0,     0,     0,  1574,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1575,  1576,     0,     0,     0,     0,     0,     0,
       0,  1577,     0,     0,     0,     0,     0,     0,  1578,  1579,
       0,     0,  1580,  1581,  1582,  1583,     0,     0,  1584,  1585,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1586,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1587,     0,     0,     0,     0,     0,  1588,     0,     0,     0,
       0,     0,     0,  1589,     0,  1590,     0,     0,     0,     0,
    1591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1594,     0,     0,
       0,     0,     0,  1595,     0,     0,     0,     0,     0,     0,
       0,     0,  1596,  1597,     0,     0,     0,     0,     0,  1598,
       0,     0,  1599,  1600,     0,     0,     0,  1601,     0,     0,
       0,     0,     0,  1602,  1603,     0,     0,     0,     0,     0,
    1604,  1605,  1606,     0,     0,  1607,  1608,  1609,     0,     0,
       0,  1610,     0,     0,     0,  1611,     0,  1612,     0,     0,
       0,     0,     0,     0,  1613,  1614,  1615,  1616,     0,  1617,
    1618,     0,     0,     0,  1619,  1620,     0,  1621,  1622,  1623,
    1624,  1625,  1626,  1627,     0,     0,     0,     0,     0,  1628,
    1629,  1630,     0,  1631,  1632,     0,     0,     0,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,     0,  1641,     0,     0,
       0,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,
    1651,  1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,
    1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,
    1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,     0,  1679,
    1680,     0,     0,  1681,  1682,  1683,  1684,  1685,  1686,  1687,
    1688,  1689,  1690,     0,  1691,  1692,  1693,  1694,  1695,  1696,
    1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,     0,
       0,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
       0,  1715,  1716,  1717,  1718,     0,  1719,  1720,  1721,  1722,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,
    1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,
    1753,  1754,     0,  1755,  1756,  1757,  1758,  1759,  1760,     0,
       0,  1761,  1762,     0,  1763,  1764,  1765,  1766,  1767,  1768,
    1769,  1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,
    1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,
       0,     0,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,
    1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,
    1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850, -2253,     0,     0,     0,  1851,  1852,
    1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,     0,
   -2253,     0, -2253,     0, -2253, -2253,     0,     0,     0,  1862,
       0, -2253, -2253,     0,     0,     0,     0,  1863,     0,     0,
       0,     0,  1864,     0,     0,     0,  1865,     0,     0,  1866,
    1867,  1868,  1869,     0,     0,  1870,  1871,     0,  1872,  1873,
    1874,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2253,     0, -2253,     0,     0,     0,     0,
       0,     0,     0,     0,  1279,  1280,  1281,     0,     0,     0,
     274,  1282,  1283,    33,     0,     0,     0,     0,     0,     0,
   -2253,     0,     0,     0,     0,     0,     0, -2253,     0, -2253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2253,     0,     0,     0,     0, -2253,     0,     0,     0,     0,
       0,     0,     0, -2253,     0,     0,     0, -2253,     0,     0,
       0,     0,     0, -2253,     0,     0,     0, -2253, -2253, -2253,
   -2253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1284, -2253,
       0,     0, -2253,     0, -2253,     0,     0,     0,     0,     0,
       0, -2253,     0,     0,     0,     1,     0,     0,     0,     2,
       0,   681,   682,   683, -2253,     0,     0,   684,     0,     0,
     685,     0,     0,     0, -2253,     0,     0,     0,     0,   686,
     687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2253, -2253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2253,     0,     0,     0,     0,     0,     0,     0, -2253,     0,
       0,     0, -2253,     0,   688,   689,     0,     0,     0,   690,
   -2253, -2253, -2253,     0,     0,     0,     0,     0,     0,   691,
     692,     0,   693,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   694,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,   695,     0,     0,   696,   697,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   698,     0,   699,   700,   701,     0,     0, -2253,     0,
       0,     0,     0,   702,   703,     0,   704,   705,   706, -2253,
       0,     0,     0,     0,   707,     0,     0,   708,     0,   709,
     710,   711,     0,     0,     0,     0,     0,   712,     0,   713,
     714,     0,   715,     0,   716,   717,     0,     0,   718,     0,
       0,   719,   720,   721,   722,   723,   724,     0,     0, -2253,
     725,   726,   727,     0,   728,     0,     0,     0,   729,     0,
     730,   731,     0,     0,     0,     0,   732,     0,     0,   733,
       0,     0,   734,     0,   735,     0,   736,     0,   737,     0,
       0,     0,   738,   739,     0,   740,   741,   742,     0,     0,
     743,     0,   744,   745,     0,   746,     0,     0,     0,     0,
       0,     0,     0,   747,   748,     0,     0,     0,     0,     0,
   -2253,     0,     0,     0,     0,     0,   749,     0,     0,   750,
     751,     0,     0,   752,   753,     0,     0,   754,   755,     0,
       0,     0,  1285,     0,     0,     0,   756,   757,   758,     0,
     759,     0,     0,     0,  1286,     0, -2253,     0,     0,     0,
     760,   761,   762,     0,   763,     0,     0,     0,   764,   765,
       0,     0,     0,   766,     0,     0,     0,     0,     0,     0,
    1287,   767,     0,     0,     0,     0,     0,     0,     0,   768,
     769,   770,     0,     0,     0,     0,     0,   771,   772,     0,
       0,     0, -2253,     0,     0,   773,     0,     0,   774,     0,
       0,  1288,   775,   776,  1289,     0, -2253, -2253, -2253, -2253,
   -2253, -2253, -2253,   777, -2253, -2253,     0,  1290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     778, -2253,     0,     0,     0,     0,     0,     0,   779,     0,
       0,     0,     0,     0,   780,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   781,  2502,  1291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,   782,  1292,
       0,     0,     0,     0,   783,     0,   784,   785,     0,     0,
       0,     0,     0,     0,   786,     0,   599,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
    1293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,     0,   787,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   788,     0,     0,     0,     0,     0,
       0,   789,     0,  1294,     0,     0,     0,     0,     0,  1295,
       0,     0,     0,     0,     0,     0,     0,     0,  1296,  1297,
       0,  1298,     0,     0,     0,   790,   791,     0,     0,     0,
     792,     0,     0,  1299,  1300,     0,     0,     0,     0,     0,
       0,  1301,   793,     0,  1302,     0,     0,     0,   794,   795,
     796,   797,   295,     0,     0,   798,     0,     0,     0,   799,
       0,     0,     0,     0,     0,     0,   800,   801,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   802,     0,   803,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
     804,     0,   805,     0,     0,   806,     0,     0,   481,   482,
     483,   807,     0,     0,     0,     0,     0,     0,  2799,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,   808,     0,     0,
     809,     0,     0,     0,     0,   810,     0,     0,   811,   812,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   813,     0,     0,     0,   458,   459,   460,
     814,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   815,   816,   817,   818,   819,   820,   821,
       0,   474,   822,     0,   823,     0,   824,   458,   459,   460,
       0,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,   484,     0,
       0,   485,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,     0,     0,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,   458,   459,   460,
     488,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
     484,     0,     0,   485,   475,   476,   477,   478,   479,   480,
       0,   474,     0,     0,     0,     0,     0,   489,     0,     0,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,   484,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   491,     0,   458,   459,   460,     0,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,   484,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,   474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,   486,     0,     0,     0,     0,   481,   482,
     483,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,   488,     0,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,   485,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     488,   598,     0,     0,     0,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,     0,   490,     0,     0,
     493,   486,     0,     0,     0,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,   491,   487,   489,     0,     0,
     488,   608,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   489,   484,  3177,
    3178,   485,     0,   491,     0,   274,  1282,  1283,    33,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
     487,     0,     0,     0,   488,   973,   492,     0,     0,     0,
       0,     0,     0,   491,     0,     0,     0,     0,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,     0,   492,     0,   484,     0,     0,   485,
       0,     0,     0,  3179,     0,     0,     0,     0,     0,   490,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,     0,     0,
       0,   486,     0,     0,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
     488,   979,     0,     0,     0,     0,     0,     0,     0,     0,
     493,     0,     0,     0,   458,   459,   460,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,   489,     0,     0,
       0,   475,   476,   477,   478,   479,   480,     0,   474,     0,
     493,     0,     0,     0,     0,     0,     0,     0,   492,   481,
     482,   483,     0,     0,     0,   490,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,   491,   487,     0,     0,     0,   488,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,   493,   489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   492,   481,   482,   483,     0,     0,
       0,   491,     0,     0,     0,     0,   458,   459,   460,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
     474,     0,   458,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
     493,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,   474,  1285,     0,     0,
       0,     0,   492,   481,   482,   483,     0,     0,     0,  1286,
       0,     0,     0,     0,   458,   459,   460,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,  1287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,   484,     0,     0,   485,   475,
     476,   477,   478,   479,   480,     0,  3180,     0,   493,  3181,
       0,     0,   486,     0,     0,     0,     0,   481,   482,   483,
       0,     0,  3182,     0,     0,     0,     0,   487,     0,     0,
       0,   488,   981,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,     0,     0,     0,     0,
       0,  3183,  3184,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,  3185,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   485,   475,   476,   477,
     478,   479,   480,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,     0,   481,   482,   483,     0,     0,
       0,     0,     0,     0,   491,  3186,     0,     0,   486,     0,
       0,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   487,     0,     0,     0,   488,   982,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,     0,     0,     0,  3187,     0,     0,   484,     0,     0,
     485,     0,     0,     0,     0,     0,  3188,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,     0,  3189,  3190,
       0,     0,     0,     0,     0,     0,  3191,     0,     0,  3192,
       0,     0,     0,   484,     0,   492,   485,   295,     0,     0,
       0,     0,   490,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,   487,     0,   459,   460,   488,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,   484,     0,     0,   485,   475,
     476,   477,   478,   479,   480,     0,   474,     0,     0,     0,
       0,   493,   489,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,     0,     0,   984,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,   487,     0,     0,     0,   488,
       0,   492,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,   460,   486,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,   487,     0,     0,     0,   488,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,     0,   985,
       0,     0,     0,     0,     0,   475,   476,   477,   478,   479,
     480,     0,     0,     0,   490,     0,     0,   493,   486,     0,
       0,     0,   489,   481,   482,   483,     0,     0,     0,     0,
       0,     0,   491,   487,     0,   988,     0,   488,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,   484,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,   489,     0,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,   490,     0,   474,   493,   468,   469,   470,   471,
     472,   473,     0,   492,   481,   482,   483,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,   474,
       0,     0,     0,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,  1279,  1280,  1281,     0,   492,
       0,   274,  1282,  1283,    33,     0,     0,     0,     0,   474,
       0,     0,     0,   484,     0,     0,   485,     0,   467,   468,
     469,   470,   471,   472,   473,  3177,  3178,     0,     0,   493,
     486,   274,  1282,  1283,    33,     0,     0,     0,     0,     0,
       0,     0,   474,     0,     0,   487,     0,     0,     0,   488,
       0,   492,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,     0,     0,     0,   493,     0,     0,     0,     0,
       0,   481,   482,   483,     0,     0,     0,     0,   475,   476,
     477,   478,   479,   480,     0,     0,   489,     0,     0,  1284,
       0,     0,     0,     0,     0,     0,   481,   482,   483,   983,
       0,     0,     0,     0,   484,     0,     0,   485,   475,   476,
     477,   478,   479,   480,   490,     0,     0,   493,     0,  3179,
       0,     0,     0,     0,     0,     0,   481,   482,   483,     0,
       0,     0,   491,     0,     0,     0,   486,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,     0,     0,     0,
       0,   487,     0,     0,     0,   488,     0,     0,     0,   481,
     482,   483,     0,     0,     0,   469,   470,   471,   472,   473,
       0,  1279,  1280,  1281,     0,     0,     0,   274,  1282,  1283,
      33,     0,     0,     0,     0,     0,     0,   474,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,     0,   492,   485,  1114,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,   491,   485,
       0,     0,   487,     0,     0,  1114,   488,     0,     0,  1279,
    1280,  1281,     0,     0,     0,   274,  1282,  1283,    33,     0,
       0,     0,     0,     0,     0,  1284,   484,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,   489,     0,     0,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   485,     0,   481,   482,   483,  1279,  1280,  1281,
       0,   490,     0,   274,  1282,  1283,    33,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,  1284,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   488,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,     0,   488,     0,
       0,     0,     0,  1285,     0,   493,     0,     0,     0,   486,
     489,  1114,     0,     0,     0,  1286,     0,     0,     0,     0,
       0,  1284,     0,     0,   487,     0,     0,     0,   488,     0,
     492,     0,     0,  1285,     0,   489,     0,     0,   490,     0,
       0,  1287,   486,     0,     0,  1286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   487,     0,     0,
       0,   488,     0,   490,   484,   489,     0,   485,     0,     0,
       0,  1287,  1288,     0,     0,  1289,     0,  3177,  3178,     0,
       0,   491,     0,   274,  1282,  1283,    33,     0,  1290,  1114,
       0,     0,     0,   490,     0,     0,   493,     0,   489,     0,
       0,     0,  3180,     0,     0,  3181,     0,     0,     0,     0,
       0,   491,     0,     0,     0,  1985,     0,     0,  3182,   274,
    1282,  1283,    33,     0,     0,     0,   490,     0,  1291,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
    1292,     0,     0,     0,   491,  1985,     0,  1114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3184,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,     0,
    3185,  3179,     0,     0,     0,     0,     0,     0,     0,  1285,
       0,  1293,     0,     0,     0,     0,     0,   486,     0,     0,
       0,  1286,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,   493,     0,     0,   488,  3179,     0,     0,
       0,  3186,     0,     0,  1294,     0,     0,  1287,     0,     0,
    1295,     0,     0,     0,     0,   492,     0,     0,   493,  1296,
    1297,     0,  1298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   489,  1299,  1300,     0,     0,  1288,     0,
    3187,  1289,  1301,     0,     0,  1302,     0,  1285,   493,     0,
       0,     0,  3188,   295,  1290,     0,     0,     0,     0,  1286,
       0,   490,     0,   199,  3189,  3190,   200,     0,     0,     0,
       0,     0,  3191,     0,     0,  3192,     0,     0,     0,   491,
       0,   493,     0,   295,     0,  1287,     0,  1114,     0,     0,
       0,     0,     0,  3627,  1291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1285,  1292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1288,  1286,     0,  1289,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,  1290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,  2303,     0,     0,     0,  1293,     0,  2533,
    2534,  2535,  2536,     0,     0,  2537,  2538,     0,   202,   203,
     492,     0,     0,     0,     0,     0,     0,     0,   204,     0,
       0,     0,  1291,     0,  1288,     0,     0,  1289,     0,     0,
    1294,     0,     0,     0,  1292,     0,  1295,     0,     0,     0,
    1290,     0,     0,     0,     0,  1296,  1297,     0,  1298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1299,  1300,     0,     0,     0,     0,     0,     0,  1301,     0,
       0,  1302,     0,     0,     0,  1293,   493,     0,     0,   295,
    1291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1292,     0,     0,     0,     0,     0,  2539,     0,
       0,     0,     0,     0,     0,  1285,     0,     0,  1294,     0,
       0,     0,     0,     0,  1295,     0,     0,  1286,     0,     0,
       0,     0,     0,  1296,  1297,     0,  1298,     0,     0,     0,
       0,     0,     0,  1293,     0,     0,     0,     0,  1299,  1300,
       0,  1285,     0,  1287,     0,     0,  1301,     0,     0,  1302,
       0,     0,     0,  1286,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,  1294,     0,     0,     0,
       0,     0,  1295,     0,  3180,     0,     0,  3181,     0,  1287,
       0,  1296,  1297,     0,  1298,     0,     0,     0,     0,   205,
    3182,     0,     0,     0,     0,     0,  1299,  1300,     0,     0,
       0,     0,     0,  3598,  1301,     0,     0,  1302,     0,     0,
    3180,     0,     0,  3181,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3182,     0,   206,     0,
    3184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3185,     0,     0,     0,     0,   207,   208,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3599,     0,     0,     0,     0,   211,  3184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3185,     0,
       0,     0,     0,  3186,     0,  3600,     0,   212,     0,     0,
       0,     0,     0,     0,  3601,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,  3186,
       0,     0,  3187,     0,     0,     0,     0,   215,     0,     0,
       0,     0,  3602,     0,  3188,  2540,     0,   216,     0,     0,
    3603,     0,     0,     0,     0,     0,  3189,  3190,  2541,     0,
       0,     0,   217,     0,  3191,     0,     0,  3192,  3187,     0,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
    3188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3189,  3190,     0,     0,     0,     0,     0,     0,
    3191,     0,   218,  3192,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2542,     0,     0,     0,   219,     0,  2543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,     0,  3604,     0,     0,     0,     0,   221,     0,     0,
     222,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2544,     0,     0,     0,
       0,   223,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2545,     0,     0,     0,   225,     0,     0,     0,     0,     0,
    2546,  2547,     0,     0,     0,     0,  2548,     0,     0,     0,
       0,     0,   226,     0,     0,     0,  2549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2550,     0,
       0,  2551,  2552,     0,     0,     0,  2553,     0,     0,     0,
       0,     0,     0,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2554,     0,     0,     0,     0,     0,     0,
       0,     0,  3605,     0,  2555
};

static const short yycheck[] =
{
       3,     4,     5,   107,   396,     8,   971,   171,   654,  1115,
      45,  1051,   998,  1138,  1139,  1127,  1141,  1448,  1143,  1144,
    1162,  1279,  1280,   190,   589,   638,  1124,  1366,   259,   260,
     546,  2105,  1167,   794,  1142,   266,  2301,    40,   127,    54,
    1359,   596,   778,  2645,  1391,   173,  2354,  1919,  2352,    52,
     572,    54,  1884,  1885,  2489,     5,  2054,    92,   261,   262,
      27,  2045,    65,  1994,  1995,  1996,  1997,   171,    25,    72,
      27,  1123,    20,    76,     5,  2051,    79,    80,  2337,    27,
    2339,    27,    85,    86,     8,  2225,   190,   796,  1294,  2607,
    1296,  1297,  2887,  2888,  2889,   688,   689,  2532,  1314,     5,
    1316,   714,  2421,   106,     5,     5,   753,    24,   717,    26,
      69,    19,   725,  1985,    27,    25,    26,    27,  1216,     5,
     123,   147,    19,   126,    27,  2890,     5,     5,   131,    26,
     110,     5,  1230,   726,     5,   263,   729,  1249,    19,   267,
      24,   269,    26,   271,   272,   273,   739,   110,   237,   238,
     743,    27,   280,   784,   747,    19,   284,   285,   322,   118,
       5,   754,   185,    26,    27,     5,   759,   780,   761,     5,
     783,     5,    45,    25,   767,    27,    19,   770,     5,   792,
    1220,    24,    25,    26,   777,     5,    24,    25,    26,   192,
     149,   784,    24,    25,    26,    27,     5,  1303,   791,   135,
     136,    24,    25,    26,    27,   814,     5,     5,    27,   802,
       5,     5,    25,   806,    27,     5,    27,   810,   322,    92,
       5,     5,   326,   816,   198,     5,   819,    20,     5,   129,
     130,   234,    25,     5,    27,     9,    10,   240,    12,    13,
      14,    15,    16,    17,   198,    27,  2660,     5,  2662,   252,
      26,    24,    25,    26,    27,   258,   259,   260,   261,   262,
      20,     5,    25,   266,    27,    25,   225,    27,   227,    24,
      25,    26,    27,  2972,   322,    56,    27,    25,     6,    27,
     281,  2237,   116,   438,   118,   690,   120,    25,  2279,    27,
     191,  2282,     9,    10,    27,    12,    13,    14,    15,    16,
      17,    24,    25,    26,    27,   433,  1149,  1150,   436,    25,
     394,    27,   315,   316,   213,   389,     5,   722,   723,   875,
       5,     5,   325,  2528,  1289,   453,   454,   455,   456,  2594,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   578,  2574,  2423,
     517,     0,   133,   134,  1406,  1114,    27,   485,   486,  2667,
       6,     5,   490,  1505,   492,   596,     5,   440,     5,   774,
       5,    25,    27,    27,     6,   238,    30,    27,  2625,   507,
     508,   509,   510,   343,   343,  2730,   514,  1123,   688,   689,
     349,   138,   593,   693,   694,    25,   222,    27,   697,  2330,
      18,    19,    20,    21,    22,     5,   706,  1447,    18,    19,
      20,    21,    22,   517,   454,   238,   580,    93,    94,    95,
      96,    97,    27,    19,     5,   238,   726,   440,    31,   729,
      19,   478,     5,     5,    19,   735,     5,     5,  1544,   739,
     623,   102,   103,   743,   403,     5,  2693,   747,     5,     5,
     112,   751,   752,    27,   754,     5,   238,   757,   585,   759,
     760,   761,  3535,   664,   763,   238,  3539,   767,   284,   478,
     770,   132,   133,   134,     5,  1184,   580,   777,     5,     5,
     663,   669,     5,   238,   784,     5,   653,  2348,  2349,  2350,
     238,   791,  2353,   319,     5,   322,   505,     5,     5,   711,
     238,     5,   802,   506,    29,   238,   806,   634,   488,     0,
     810,   292,   547,   548,   199,   238,   816,   477,    27,   819,
     732,   424,   238,   322,     5,    16,   300,     5,     5,     5,
       5,     5,   440,   745,  1127,   723,   539,     5,   561,   542,
     771,  2886,  2887,  2888,  2889,     5,   331,   550,   153,   653,
     705,   625,     5,  2414,  2886,  2887,  2888,  2889,   642,   440,
       5,     5,   518,   636,   567,     5,   569,   615,   658,     5,
     526,   389,   113,   331,   577,   578,   440,   536,   581,     5,
       5,     5,     5,   300,   238,     5,   789,   790,   238,   556,
    1146,   409,     5,   596,  2426,  2860,     5,  1153,   203,   573,
     440,     5,     5,     5,   663,   606,   444,   186,   187,   589,
     433,     5,    28,    27,  2819,   818,   642,  1248,   821,   573,
    2576,  2612,  2950,   636,  2952,   672,   589,  2955,    23,   474,
     284,   440,    10,   238,   510,   240,  2862,  2863,   474,  3338,
      23,   296,   440,  1048,   438,   440,   420,   421,   399,   199,
     440,   433,  1495,  2961,  1247,  1248,  1249,  3175,  1174,   478,
     440,  3426,  2921,   440,   440,  1070,   440,   478,   440,   485,
    1406,   444,   478,   676,   547,  1434,   600,  3112,   681,   682,
     683,   684,   685,   686,   687,   548,   586,   690,   691,   692,
     474,   597,   695,  2565,   697,  3130,   595,   700,  3216,   702,
     433,  1410,   476,   420,   421,   608,  1352,   593,   711,  1274,
    1275,   534,   440,  1422,  2033,  2054,  2856,  2578,   597,   722,
     723,   444,   593,   636,  3028,   603,   600,  2588,   636,   732,
     474,  2715,   337,   664,   440,   738,   672,  2735,   601,   636,
      27,   744,   745,   746,   399,  1267,   713,   750,   658,   666,
     753,   405,   755,   756,  3058,   636,   713,  2733,   708,   476,
     763,  2192,   663,   766,  1411,   713,  3085,   713,   771,   772,
    3089,   774,   636,   673,   436,   778,   415,  3036,   781,  3038,
    2127,   322,   666,   603,   787,   474,   789,   790,   615,  3391,
     474,   794,   795,   796,   440,   518,   440,   800,   460,   562,
     803,   406,   518,  3405,    27,   808,   658,   625,   440,   414,
     713,    10,   815,   418,   817,   818,   615,   820,   821,   632,
     823,   824,  2683,   666,  3238,   399,   478,  1127,   666,   603,
     664,   485,  3177,  3178,   666,   389,  3181,   474,   672,   474,
     440,   502,   423,   666,   440,  3177,  3178,  3642,   478,  3181,
     455,   440,   715,   394,   506,   440,   474,    56,   986,   597,
     514,   989,   501,   518,   474,   658,   672,   440,   440,   997,
     998,   440,   440,   506,  1266,   623,   408,   211,   517,   293,
     440,   543,   391,   440,   440,    23,   603,   282,   669,  3201,
     399,   400,   306,   666,    25,   669,    27,   438,   658,   282,
     636,  3246,    27,   283,  3249,   484,    26,    27,   374,   440,
     211,   666,   206,   440,   440,   424,   521,   440,   427,   297,
     440,   560,   658,   440,  3252,   928,  2787,   588,  1541,   440,
     636,   636,   440,   440,  3536,   444,   440,  2769,   685,   686,
     687,   688,   689,   666,   518,   719,   720,  1247,  1248,  1249,
    3418,  3386,   669,   658,   630,   560,   473,   403,   383,   440,
     599,  3429,   440,   440,   440,   440,   440,    25,   971,    27,
     631,  1526,   440,   635,    25,  3234,    27,  3236,  3237,   584,
     440,  1386,    25,   290,    27,   647,   648,   440,   374,   628,
    1395,   523,   506,   655,   408,   440,   440,  1513,   637,    25,
     440,    27,   719,   720,   440,  3264,   293,   408,  1011,   434,
    1013,  2872,   306,  3321,   440,  1420,   440,   440,   344,   306,
     440,   478,  1987,   628,  1989,  2133,     5,   440,   411,     8,
     356,   440,   637,   666,  1999,  2000,   440,   440,   440,   548,
    2005,  2006,  2007,  2008,    20,  1048,   440,  1006,  1051,   506,
     344,    27,    30,   254,   255,   256,    34,   435,   381,   437,
     394,  2400,   528,   450,  1067,  2404,  3411,  1070,  2120,   666,
     293,   625,  3417,  3418,   615,  3420,  3421,  3422,  3423,  3411,
      25,  2179,    27,   306,  3429,  3417,  3418,  2303,  3420,  3421,
    3422,  3423,   601,   394,  3406,  3407,    25,  3429,    27,   608,
     632,   665,  3447,   212,     5,   214,  1109,   238,   672,   523,
      25,  1114,    27,   238,   408,   403,   721,   722,   238,     5,
    1123,   408,   523,  3431,   330,   539,   293,    25,   422,    27,
    3395,    26,    27,   513,  1137,  1138,  1139,   343,  1141,   306,
    1143,  1144,   528,    22,   282,   123,  1149,  1150,    26,    27,
    2366,  2367,   666,  2265,   695,   696,   697,   506,    25,    30,
      27,    40,  3023,    34,  3025,   706,    18,    19,    20,    21,
      22,   296,   552,   506,    25,    24,    27,    26,  2164,  1182,
     238,  1184,    26,    27,    25,   408,    27,   238,   671,    20,
    1193,   478,    14,  1196,  1425,   238,    27,  3542,  1201,    25,
    3545,  3546,  3547,  3548,  2350,   671,   212,  2353,   214,   318,
    3542,   694,   321,  3545,  3546,  3547,  3548,  1220,  1221,   569,
    1423,   585,   478,  2188,   690,   691,  1229,   161,  3573,   523,
     101,   632,   585,   239,   343,   478,   523,   108,   561,    20,
     293,   408,  1245,  1246,   710,   539,    27,   448,   635,   572,
     367,   638,   539,   306,   330,   478,    25,   591,    27,   478,
     139,   140,   141,   142,   143,   144,  1355,   343,  1271,  1358,
     634,   477,   506,   411,   286,   478,  1279,  1280,   157,   158,
     159,   634,  2018,   154,   155,   671,  1289,    20,   478,  3634,
     624,   162,  3164,   238,    27,  1526,    25,  3642,    27,  1302,
     523,  3162,  3634,   636,   690,   691,   284,  1310,   473,   238,
    3642,  3172,   318,   505,   506,   321,   539,   478,  1521,  1522,
      18,    19,    20,   238,   710,   658,    24,    25,    26,    27,
     109,   343,  3591,   666,    19,   478,  2301,   343,   478,    24,
     238,    26,   212,   238,   214,  2310,   542,    26,  2313,  2314,
    2315,  2316,  3524,  3525,   550,   408,   523,  1360,    28,    29,
     238,  1364,  1365,  1366,   478,    25,  1381,    27,   477,   239,
    2512,   238,   539,  1376,  1377,  1378,    25,    26,  1381,  1382,
    1383,  1384,  1385,  1386,  2120,   397,   415,   238,  2707,   401,
     671,   761,  1395,   286,   238,    20,  2735,   238,  3259,   225,
     770,   477,    27,  1406,  1407,   184,  1409,  1410,  1411,   478,
     415,  2451,   693,   694,   112,  1418,  1419,  1420,   297,  1422,
    1423,   300,  1425,  1426,    25,   478,    27,   405,    20,   478,
    2646,  1434,  2648,  3245,  2650,    27,  3248,  1440,  1441,  3251,
      20,  3613,   478,  3615,  1447,  1448,   816,    27,   318,   819,
     343,   321,    24,  2162,    26,   802,   478,    20,   528,   806,
    2666,  2074,  2668,   810,    27,   477,   506,   246,  2580,   248,
     523,   477,   501,   343,  2235,   478,   454,   415,   286,  3410,
     676,  3412,  3413,  3414,  3415,   264,   539,   478,   517,  1492,
    1493,   478,  1495,   272,  2606,   817,   501,   276,   820,   686,
     687,   823,   385,  1908,   397,  1910,  1911,   485,   401,  1914,
    1915,   478,   517,   396,   478,  1920,  1519,  2110,  1521,  1522,
    2229,  3595,   301,  1526,   478,  1528,   352,  1530,  1531,   149,
     150,   560,   358,   359,   360,   343,   514,  3398,  3612,   671,
     238,   420,   505,   506,  2153,   416,   478,    40,   478,    26,
    1553,   729,    19,   215,   380,   560,   435,    24,    25,    26,
     439,   693,   694,   501,   447,   743,   716,   717,   718,   747,
     599,   442,   415,   415,   478,   505,   506,    26,   461,   517,
     672,   759,   685,   672,   477,   688,   689,  3661,   440,   397,
     157,   158,   159,   401,   599,    26,  2001,   476,   415,   628,
      25,   671,    27,   415,  3678,  1147,  1148,   477,   637,  1151,
    1152,   688,   689,    18,    19,    20,    21,    25,   478,    27,
     690,   691,   560,   628,   478,   504,    18,    19,   478,  2594,
    3491,  2147,   637,   478,    26,    27,    25,    26,   568,  2232,
     710,   512,   478,   522,   342,  3457,   139,   140,   141,   142,
     143,   144,   478,  2751,    25,    24,    27,    26,   501,   501,
     486,   599,   478,   489,   157,   158,   159,   550,    25,   477,
      27,   497,  2265,   478,   517,   517,   478,  3108,  1881,  1882,
    2886,  2887,  2888,  2889,   501,    25,    26,  2652,  2796,   501,
     628,  2949,  2950,  2828,  2952,  2793,  2405,  2955,  2407,   637,
     517,    25,  2667,    27,   478,   517,   532,  2416,   406,    26,
    2852,   184,   478,  2678,  2119,   107,    26,   560,   560,    25,
     418,    27,   478,    26,   603,   695,   696,   119,  2293,  3068,
      20,    21,  2441,   604,   139,   140,   141,   142,   143,   144,
    1407,   567,  1409,   560,   666,  2951,   444,  2953,   560,   505,
     506,   695,   696,   573,   146,   478,   599,   599,   335,   336,
     586,   587,   659,   660,   661,   662,   428,  2725,  2726,  3177,
    3178,   597,   478,   246,   478,   248,   602,   475,    20,    21,
     478,   443,   599,   478,  3215,   628,   628,   599,  2401,    26,
     669,   264,   490,   491,   637,   637,   478,   486,   478,   272,
     478,   478,   478,   276,   297,   468,   506,   300,   497,    26,
    2110,   628,   568,   684,   287,   641,   628,   478,  2804,   192,
     637,   692,    26,   196,   486,   637,  2812,  2813,   301,   518,
     184,    26,  3181,   531,    26,   497,   525,    26,  2243,  2452,
      26,    26,   666,   106,   533,   543,   238,   673,   240,   139,
     140,   141,   142,   143,   144,   440,   518,    18,    19,    20,
      21,    22,  1951,   525,  2829,   478,   555,   973,   410,   666,
     976,   533,   978,   979,   980,   981,   982,  1880,  1881,  1882,
      26,   440,   478,   478,  1887,  1888,   584,   474,  2501,     5,
     478,  2019,   246,   555,   248,  2860,   440,   139,   140,   141,
     142,   143,   144,   440,  1907,  1908,   440,  1910,  1911,   440,
     264,  1914,  1915,   518,  1917,  2320,   478,  1920,   272,   617,
     672,    20,   276,  2126,   297,   623,    20,   420,   478,   478,
     440,     5,  2232,   478,   632,   633,   506,   635,   670,  2028,
      26,  1944,   435,    26,   666,   337,   439,   301,   440,   647,
     648,   440,  1955,   306,   474,   410,    20,   655,    30,  3390,
     658,    26,   636,    26,    26,  2265,    26,    26,   666,    26,
     632,  3177,  3178,    26,    26,  3181,   638,   440,  2209,  2210,
     372,  2574,   440,   476,  1987,    26,  1989,  2580,   440,   440,
     440,    26,  2957,     5,  3252,   440,  1999,  2000,  2001,    20,
      26,    26,  2005,  2006,  2007,  2008,   478,    26,  2413,   208,
      26,   504,   666,  2606,   406,  2018,   440,     5,  2146,   440,
     672,  2224,    26,   440,   223,   224,   418,   350,   440,   522,
     440,   440,   670,   232,   440,     5,  2164,  2040,   694,   440,
     440,   478,  2045,   672,   440,    26,  2755,   636,  2051,   672,
     706,  2054,   440,    25,    25,   440,    25,    25,   440,   440,
     440,   440,  3411,   455,   440,  2024,   440,   266,  3417,  2072,
     440,  3420,  3421,  3422,  3423,  2078,   275,  3117,   470,   735,
     350,  2790,   440,   666,   440,   440,   478,  3193,   670,   440,
     440,   478,   666,     8,   526,   751,   752,   474,   671,   491,
     314,   757,   642,  2106,   760,   304,     5,   664,   507,   664,
     603,   705,   642,   507,   705,   666,  2119,  2120,   376,   468,
    2123,  2124,   506,  2126,   643,   658,   468,   666,     5,     5,
     478,   478,   478,   478,   478,  3121,   636,   394,  2141,    18,
      19,    20,    21,   535,   625,     8,    14,   622,     5,   705,
     349,     5,   705,   468,    26,    26,   478,  2160,  2563,  2162,
     478,  2886,  2887,  2888,  2889,   113,    26,   506,   560,   666,
     636,   138,   506,   478,   478,   468,   669,   478,   478,   478,
    2183,   478,  2185,  2186,   478,  2188,   478,  2592,  2191,  2192,
     478,   478,   584,  3542,   393,    26,  3545,  3546,  3547,  3548,
    3342,     5,   642,  2608,   478,  3411,  2209,  2210,     5,  3351,
     478,  3417,  3418,   672,  3420,  3421,  3422,  3423,   478,   478,
     708,  2224,   400,  3429,   672,  3367,  2229,  2230,  2231,   671,
       5,   603,  2235,   663,    18,    26,   628,    19,    26,    39,
    2243,    41,   201,    43,    44,   637,    25,   669,   432,   529,
      50,    51,   529,   636,     5,  2660,   593,  2662,   625,   666,
     139,   140,   141,   142,   143,   144,   199,  2270,  2435,  2862,
    2863,    26,   593,   448,  2574,  2278,  2279,   593,   371,  2282,
    2580,    26,   440,   440,   478,  3634,   672,   440,   518,   573,
    3255,   666,  3257,   440,   672,   478,   478,   478,  2301,   478,
     105,   478,     5,   666,   636,   440,  2606,  2310,   710,   636,
    2313,  2314,  2315,  2316,  2317,   593,   478,  2320,  3430,     5,
     672,  2324,  2325,   666,     5,  2328,     5,   663,   626,   721,
     722,  2435,     5,   666,   530,   478,  3542,   672,   666,  3545,
    3546,  3547,  3548,   716,   717,  2348,  2349,  2350,     5,     8,
    2353,  2354,  2355,   367,   506,  2358,    26,   671,    26,   113,
     266,     5,   375,     5,   440,   478,  3075,   478,  2977,  2978,
    2979,  3513,  2981,  2982,  2983,  2984,  2985,  2986,   409,   643,
      14,  2990,   597,  2788,  2387,   593,  2389,  2390,     5,  2392,
    2393,   672,   593,  2396,  3103,   706,    26,  2400,   147,   478,
     666,  2404,  2405,   672,  2407,   478,   671,     5,   474,   671,
    2413,  2414,   685,  2416,  2417,    26,   672,  2420,  2421,     5,
     440,     5,   718,   440,    57,    58,    59,    60,  3634,   440,
    3395,  2434,     5,   417,   665,   381,  3642,    26,  2441,   508,
     474,   814,   478,     5,  3409,  2448,   742,   508,  2451,   478,
    1987,   824,  3177,  3178,   478,   478,  3181,  2460,     5,   666,
     478,  2464,     8,   478,   666,     5,   666,   623,   478,   478,
     600,   375,    25,  3598,  3599,  3600,  3601,  3602,  3603,   506,
     394,  3623,  3522,   394,   394,   478,  2489,   409,   473,     5,
     666,     5,   788,    26,   697,     5,     5,    25,   506,    14,
      26,    14,   798,   642,   642,   801,     5,     5,   663,   805,
    2513,   600,   478,   440,    26,   811,   478,   813,   318,    26,
      26,   321,    26,   323,   672,     6,   316,   440,   440,     7,
     495,   440,   440,   440,     5,   440,    26,   440,   666,    26,
     672,    26,  1257,   343,    26,   666,    26,   180,   666,   440,
      20,     5,   322,   353,     5,   188,     5,   613,     5,   666,
    2563,   593,  2862,  2863,   197,     8,    39,   200,    41,   714,
      43,    44,     5,  3538,   374,  2578,   440,    50,    51,    40,
     618,   666,   440,  2586,  2587,  2588,   478,   518,  2591,  2592,
    2625,  2594,   672,     5,   593,     5,   259,   397,   971,   670,
      26,   401,   672,   440,  2607,  2608,     5,     5,  2611,  2612,
     243,  2842,  3577,  2844,   672,   670,   478,   250,   672,  3265,
      25,   672,   478,   672,    25,    25,   665,   494,  3614,    25,
      25,   344,    26,    26,    25,     5,  3345,    26,    26,    26,
      26,   440,   440,    26,  3049,   106,   107,   440,   440,  2652,
     478,     5,   478,  3362,  2191,   440,   515,  2660,  2693,  2662,
    2827,   597,  2665,     8,  2667,   288,    26,    25,   474,   440,
     488,  2799,   394,    20,   307,  2678,  2804,   477,  1051,   190,
    2683,  2684,  2685,   111,  2812,  2813,  3411,     5,     5,   478,
      14,   478,  3417,  3418,  2697,  3420,  3421,  3422,  3423,   332,
    3740,   478,   600,   259,  3429,   478,   339,    26,   341,   478,
     171,   478,  2715,   478,    26,    26,    26,   440,   351,   440,
       5,   489,  3687,  2827,    26,   506,   440,    26,   440,   190,
    2733,    26,  2735,   440,   478,    26,    26,    26,   423,    26,
     615,   440,   440,   288,   440,  2748,   379,   478,   394,   440,
     289,   488,  2755,   506,   387,   593,   440,    14,   478,     7,
     440,    26,   440,   440,   666,   287,   287,  1063,   440,   440,
     478,   672,   441,   666,   440,   622,   440,  2780,   478,  2782,
     474,  2784,    25,   636,  2787,  2788,   289,  2790,   440,   440,
     440,   424,   440,   440,    26,  3504,     5,   440,     5,    26,
     666,   666,  2805,   440,  2807,  2808,  2809,  2807,   440,  2748,
    3671,   666,  2485,  1533,  2172,    29,   449,  3542,    31,  2822,
    3545,  3546,  3547,  3548,   997,  2417,  2829,  2780,   547,  2423,
     354,  3223,   114,  3238,   225,   118,   207,  3430,   657,  2842,
     345,  2844,  2023,   225,  2024,   318,   536,  1220,   321,   212,
     323,  2854,  2855,   486,   315,   316,   599,  2860,   355,  1278,
     555,   322,   567,   383,   497,   326,   384,   569,  3661,  2872,
     343,  1167,  2077,   415,   989,   800,  2276,  2283,  2125,  1175,
     353,  1177,  2410,  2886,  2887,  2888,  2889,  2890,  2891,  1254,
    3093,  1880,  3142,  2831,  2199,  1883,  2509,  2900,  3713,  2219,
    2413,   374,  2905,  3106,  1425,  3359,  1279,  1280,    16,  3634,
      20,    21,    22,    92,    40,  3286,  1289,  3642,    40,   347,
      22,   756,  2177,  3087,   397,   930,  2183,  1888,   401,   326,
      40,  1013,  1493,  2186,  3283,  2938,  2939,  3466,  1221,   367,
     368,   369,   781,  1419,  1491,  3678,  2949,  2950,  1409,  2952,
    3017,  3476,  2955,  3015,  2957,  2152,  1514,  2829,  2961,   452,
    2999,   352,   595,   596,   597,  2696,  3073,   358,   359,   360,
    3339,  3337,  3330,  3065,  2404,   608,  2057,  2040,   406,  2358,
    3687,  2574,  3259,  3087,  2593,  1922,  1922,  2254,  3174,   380,
     418,  3022,  3491,  3121,  2242,  3056,  2320,  2938,  3001,  2939,
    2665,   429,  3249,  3573,   477,  2718,  3044,  1907,  3302,  2697,
       8,  3014,  3731,  2685,  1250,  2684,  3176,  2873,   446,  2000,
    3023,  3024,  3025,  3257,  1999,  1902,  3532,  3327,   456,   139,
     140,   141,   142,   143,   144,  1246,  2587,  3337,  3171,  3409,
    1875,  3428,  3417,   471,  2434,   506,  3049,   157,   158,   159,
     545,  2788,    -1,    -1,    -1,    -1,   517,    -1,  3061,  3062,
    1424,    -1,  3065,    -1,    -1,  3068,    -1,    -1,    -1,    -1,
      -1,    -1,  3075,    -1,  1447,    -1,    -1,    -1,   711,    -1,
      -1,    -1,  3085,    -1,    -1,  3088,  3089,    -1,    -1,    -1,
    3093,   519,    -1,    -1,    -1,   486,    -1,    -1,   489,    -1,
    3103,    -1,    -1,  3106,    -1,  3108,   497,    -1,    -1,    -1,
    3341,    -1,    -1,    -1,  3117,    -1,  1412,  1413,  1414,   580,
      -1,   549,    -1,    39,    -1,    41,    -1,    43,    44,    -1,
    3430,   559,    -1,  1429,    50,    51,    -1,    -1,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,  3156,    -1,    -1,   584,    -1,    -1,  3162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3171,  3172,
      -1,  3174,  3175,    -1,  3177,  3178,   567,    -1,  3181,    -1,
      -1,    -1,    -1,    -1,   612,    -1,    -1,   297,    -1,  3192,
     300,    -1,   653,   621,    -1,   586,   587,    -1,    -1,    -1,
    1496,    -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,
      -1,   602,  3215,  3216,    -1,    -1,    -1,    -1,  1514,    -1,
     681,   682,   683,    -1,   685,    -1,    -1,  1942,  1943,    -1,
      -1,    -1,    -1,    -1,  1949,  3238,  1532,    -1,    -1,    -1,
      -1,   702,    -1,  3246,    -1,    -1,  3249,  1543,    -1,  3252,
     641,    -1,  3255,    -1,  3257,    -1,  3259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   738,    -1,    -1,
    3283,    -1,   673,   744,    -1,   746,    -1,    -1,    -1,   750,
      -1,    -1,   753,    -1,    -1,   756,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   766,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3321,    -1,
     781,    -1,    -1,    -1,    -1,   435,   787,    -1,    -1,   439,
      -1,    -1,    -1,   794,   795,   796,    -1,    -1,  3341,   800,
      -1,    -1,  3345,    -1,    -1,    -1,    -1,   808,    -1,  2886,
    2887,  2888,  2889,    -1,    -1,    -1,    -1,    -1,    -1,  3362,
      -1,  3528,    -1,   824,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3390,    -1,    -1,
      -1,    -1,  3395,    -1,   504,  3398,    -1,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,   321,  3409,   323,  3411,    -1,
      -1,    -1,   522,    -1,  3417,  3418,    -1,  3420,  3421,  3422,
    3423,    -1,    -1,  3426,  3528,  3428,  3429,   343,  3431,    15,
      16,    17,    18,    19,    20,    21,    22,   353,    -1,    -1,
    2155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,   374,    -1,
      -1,    -1,    -1,  3466,    -1,    -1,    -1,    -1,  3471,    -1,
    3473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2195,   397,    -1,    -1,    -1,   401,  3614,    -1,  3491,    -1,
      -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1888,    -1,    -1,    -1,  3522,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3532,
      -1,    -1,    -1,    -1,    -1,  3538,    -1,    -1,    -1,  3542,
      -1,    -1,  3545,  3546,  3547,  3548,  3549,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,   669,
    3563,   477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3573,   157,   158,   159,  3577,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
    1051,    -1,    -1,    -1,    -1,  3598,  3599,  3600,  3601,  3602,
    3603,    -1,    40,    -1,    -1,    -1,  1067,  3610,    -1,    -1,
      -1,    -1,    -1,    -1,  1987,    -1,  1989,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1999,  2000,    -1,    -1,
      -1,  3634,  2005,  2006,  2007,  2008,    -1,    -1,    -1,  3642,
    3177,  3178,     9,    -1,  3181,    -1,    -1,    -1,  1109,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1137,  1138,  1139,    -1,
    1141,    -1,  1143,  1144,  3687,    -1,  3689,    -1,  1149,  1150,
      -1,    46,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      -1,   139,   140,   141,   142,   143,   144,    -1,    -1,  3246,
      -1,   297,  3249,    -1,   300,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,  1184,    -1,    -1,  3729,  3730,  3731,    -1,
      -1,    -1,    -1,    -1,    -1,  1196,    -1,  3740,    -1,  3742,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1220,
    1221,    -1,    -1,    -1,  2479,  2480,    -1,    -1,  1229,    -1,
      -1,    -1,    -1,    -1,    -1,  2490,    -1,    -1,    -1,    -1,
    2153,  2077,    -1,    -1,  1245,  1246,    -1,    -1,    -1,    -1,
     145,    -1,    -1,    -1,   167,    -1,  2092,    -1,    -1,  2514,
    2515,  2516,  2517,  2518,  2519,    -1,    -1,    -1,    -1,  2524,
    2525,  2526,  2527,    -1,    -1,  2188,  2531,    -1,    -1,    -1,
      -1,    -1,  2118,    -1,    -1,    -1,    -1,    -1,    -1,  2125,
      -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,
      -1,    -1,    -1,   439,    -1,    -1,  2152,    -1,    -1,   297,
      -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,  3409,    -1,  3411,  2171,    -1,    -1,    -1,    -1,
    3417,  3418,    -1,  3420,  3421,  3422,  3423,    -1,    -1,    -1,
     476,    -1,  3429,    -1,    -1,    -1,   269,    -1,  2613,  2614,
      -1,    -1,    -1,    -1,   277,  2620,  2621,    -1,    -1,    -1,
     283,    -1,   285,    -1,    -1,     9,    -1,    -1,   504,    -1,
      -1,    -1,    -1,   296,    18,    19,    -1,    -1,  2301,    -1,
      24,    25,    26,    27,    -1,    -1,   522,  2310,    -1,    -1,
    2313,  2314,  2315,  2316,    -1,    -1,  1407,    -1,  1409,  1410,
    1411,   324,  2325,    -1,    -1,    -1,    -1,  1418,  1419,    -1,
      -1,  1422,    -1,    -1,    -1,  1426,    -1,   340,    -1,    -1,
      -1,    -1,   345,    -1,    -1,   342,    -1,    -1,    -1,    -1,
      -1,  2354,   420,    -1,   357,    -1,  1447,  1448,    -1,    -1,
      -1,   364,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,   439,    -1,    -1,    -1,  3542,    -1,    -1,  3545,  3546,
    3547,  3548,    -1,   107,    -1,    -1,    -1,   603,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   382,    -1,    -1,
      -1,  1492,  1493,    -1,  1495,    -1,  3573,    -1,   476,   406,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,   146,    -1,    -1,  2770,  2771,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2779,    -1,   504,  1528,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,  2451,    -1,
      -1,    -1,    -1,   669,   522,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1553,    -1,    -1,    -1,     5,  3634,  2394,    -1,
      -1,  2816,  2817,   458,    -1,  3642,    -1,    -1,   475,   464,
      -1,   478,  2408,  2409,  2410,  2411,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,   491,    -1,    -1,    -1,  2843,    -1,
    2845,    -1,    -1,  2429,    -1,    -1,    -1,    -1,    -1,    -1,
     513,    -1,    -1,    -1,   238,   518,   240,    -1,   503,    -1,
      -1,   518,   525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   531,   603,    -1,    -1,    -1,    -1,
      -1,    -1,   527,    -1,   547,    -1,   543,    -1,    -1,   552,
      -1,    -1,   537,   538,    -1,    -1,    -1,    -1,   543,    -1,
      -1,  2906,  2907,    -1,    -1,  2910,  2911,    -1,   553,  2495,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   584,    -1,    -1,
     575,  2594,    -1,   578,   579,    -1,    -1,    -1,   583,    -1,
      -1,   669,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,   342,    -1,
     617,    -1,    -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   632,   633,    -1,   635,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,  2652,
     647,   648,    -1,    -1,    -1,   640,    -1,    -1,   655,    -1,
    3005,   658,  2665,    -1,  2667,    -1,   651,    -1,    -1,   666,
      -1,  2597,    -1,  2599,    -1,  2678,    -1,    -1,    -1,    -1,
      -1,     9,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,   418,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   436,    -1,    -1,    -1,    -1,   441,    -1,    -1,
     444,   157,   158,   159,    -1,    -1,    -1,  2730,    -1,    -1,
      -1,   455,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,
      -1,  3086,    -1,    -1,    -1,  3090,   470,    -1,    -1,    -1,
      -1,   475,    -1,    -1,   478,    -1,    -1,   481,    -1,    -1,
      -1,    -1,    -1,    -1,  3109,    -1,   490,   491,    -1,   308,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,    -1,   308,  3128,   112,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,  1887,  1888,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   530,   531,   347,    -1,
      -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,   146,   543,
      -1,   347,    -1,    -1,    -1,    -1,  2829,   366,   367,    -1,
     554,    -1,    -1,    -1,    -1,  2761,   560,    -1,  2764,    -1,
     366,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1944,    -1,    -1,    -1,  2860,    -1,    -1,
     584,   297,    -1,    -1,   300,    -1,    -1,   406,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,
     406,    -1,    -1,  2886,  2887,  2888,  2889,    -1,    -1,    -1,
     429,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2828,   429,   628,    -1,    -1,   446,    -1,    -1,
     238,   635,   240,   637,    -1,    -1,    -1,   456,    -1,    -1,
     446,    -1,    -1,   647,   648,    -1,    -1,    -1,    -1,    -1,
     456,   655,   471,    -1,    -1,  2938,  2939,    -1,    -1,    -1,
      -1,    -1,   666,    -1,    -1,   471,  2949,  2950,    -1,  2952,
      -1,    -1,  2955,    -1,  2957,    -1,    -1,    -1,  2961,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,  2977,  2978,  2979,    -1,  2981,  2982,
    2983,  2984,  2985,  2986,   420,   511,    -1,  2990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   534,    -1,   721,   722,   435,
      -1,    -1,    -1,   439,   440,    -1,    -1,    -1,   534,   337,
     549,    -1,    -1,    -1,   342,    -1,    -1,   556,    -1,    -1,
     559,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,
     556,    -1,    -1,   559,  3379,    -1,    -1,  3382,    -1,    -1,
     476,   580,    -1,    -1,   372,   584,    -1,    -1,    -1,    -1,
    2141,    -1,    -1,    -1,   580,    -1,    -1,    -1,   584,    -1,
      -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,   504,    -1,
      -1,  2162,    -1,    -1,    -1,    -1,    -1,   603,   406,    -1,
      -1,    -1,   621,    -1,    -1,    -1,   522,    -1,    -1,    -1,
     418,    -1,  2183,    -1,    -1,   621,    -1,    -1,    -1,    -1,
      -1,  2192,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,   441,  3117,    -1,   444,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,  2229,  2230,
    2231,    -1,   470,    -1,  2235,    -1,    -1,   475,    -1,    -1,
     478,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   490,   491,    -1,    -1,    -1,   603,    -1,    -1,
    3096,    -1,    -1,    -1,  3177,  3178,    -1,    -1,  3181,  2270,
      -1,  3526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   530,   531,    -1,    -1,  3132,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,
      -1,    -1,   560,   669,  3579,  3580,    -1,  3582,    -1,  3584,
    3585,    -1,    -1,  3246,    -1,    -1,  3249,    -1,    -1,  3252,
      -1,    -1,  3255,    -1,  3257,    -1,   584,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     628,    -1,    -1,    -1,  3649,    -1,  3651,   635,    -1,   637,
      -1,    -1,    -1,    -1,  2405,    -1,  2407,    -1,  3321,   647,
     648,    -1,    -1,    -1,    -1,  2416,    -1,   655,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,
    3685,    -1,    -1,    -1,  2435,    -1,    -1,    -1,    -1,    -1,
    2441,    -1,    -1,    -1,    -1,    -1,    -1,  3702,  3703,    -1,
    2451,  3706,    -1,    -1,  3709,    -1,    -1,    -1,    -1,  2460,
      -1,   107,    -1,  2464,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3395,   721,   722,    -1,    -1,    -1,  2489,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3409,    -1,  3411,    -1,
     146,    -1,    -1,    -1,  3417,  3418,    -1,  3420,  3421,  3422,
    3423,  3347,    -1,    -1,     9,    -1,  3429,    -1,  3431,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,  3447,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3381,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,   238,    -1,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3522,
    2611,    -1,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,  3538,    -1,    -1,    -1,  3542,
      -1,    -1,  3545,  3546,  3547,  3548,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   146,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
    3573,    -1,    -1,    -1,  3577,    -1,    -1,    40,    -1,    -1,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,  2684,    -1,   121,   122,    -1,   124,   125,
     126,   337,    -1,    -1,    -1,    -1,   342,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3634,    -1,    -1,    -1,    -1,   372,    -1,    -1,  3642,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2755,    -1,    -1,    -1,    -1,    -1,
     406,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
     143,   144,   418,  3609,  3687,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,   224,  2790,
     436,    -1,    -1,    -1,    -1,   441,   232,    -1,   444,    -1,
      -1,   238,    -1,   240,  2805,    -1,  2807,    -1,  2809,   455,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
      -1,  2822,    -1,    -1,   470,    -1,  2827,  3740,    -1,   475,
     266,    -1,   478,    -1,    -1,   481,    -1,    -1,    -1,   275,
      -1,    -1,   337,    -1,   490,   491,    -1,   342,    -1,    -1,
      -1,    -1,    -1,  2854,  2855,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,
      -1,    -1,  3708,    -1,    20,    -1,    -1,   372,    24,    25,
      26,    27,    -1,   342,    -1,   531,    -1,    -1,    -1,   535,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,  2900,
     337,    -1,    -1,    -1,    -1,   342,    -1,    -1,   554,    -1,
     556,   406,    -1,   349,   560,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   418,   297,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,   584,    -1,
      -1,   436,    -1,    -1,    -1,    -1,   441,   406,    -1,   444,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,   418,
     455,    -1,    -1,    -1,    -1,   460,   112,    -1,    -1,   406,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
     475,   418,   628,   478,    -1,   444,   481,    -1,    -1,   635,
      -1,   637,    -1,    -1,    -1,   490,   491,    -1,    -1,   436,
    3001,   647,   648,    -1,   441,    -1,    -1,   444,    -1,   655,
      -1,    -1,   448,  3014,    -1,    -1,   475,    -1,   455,   478,
     666,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   490,   491,   470,    -1,   530,   531,    -1,   475,    -1,
     535,   478,    -1,    -1,   481,    -1,    -1,   420,   543,    -1,
      -1,    -1,    -1,   490,   491,    -1,    -1,    -1,    -1,   554,
      -1,    -1,   435,    -1,    -1,   560,   439,    -1,    -1,    -1,
      -1,    -1,   531,    -1,  3075,   721,   722,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,    -1,  3087,    -1,    -1,   584,
      -1,    -1,   238,    -1,   531,    -1,    -1,    -1,   535,    -1,
      -1,    -1,  3103,   476,    -1,    -1,   543,  3108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3117,   554,    -1,    -1,
      -1,    -1,    -1,   560,    -1,   584,    -1,    -1,    -1,    -1,
      -1,   504,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
     635,    -1,   637,    -1,    -1,    -1,    -1,   584,    -1,   522,
      -1,    -1,   647,   648,    -1,    -1,    -1,    -1,   617,    -1,
     655,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,
      -1,   666,    -1,   632,   633,    -1,   635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,   648,
      -1,   628,    -1,    -1,    -1,    -1,   655,    -1,   635,   658,
     637,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,
     647,   648,    -1,    -1,  3215,    -1,    -1,    -1,   655,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   721,   722,    -1,   666,
     603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3283,    -1,   721,   722,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   669,    -1,   444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,   475,
      -1,    -1,   478,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,  3345,   491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,  3362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,  3390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,
      -1,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
      -1,   157,   158,   159,   160,  3466,    -1,   163,   164,    -1,
    3471,   617,  3473,    -1,    -1,    -1,    -1,   623,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   632,   633,    -1,   635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   647,   648,  3504,    -1,    -1,    -1,   203,    -1,   655,
      -1,    -1,   658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     666,  3522,    -1,    -1,    -1,    -1,    -1,  3528,    -1,   225,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3598,  3599,  3600,
    3601,  3602,  3603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   337,   338,    -1,    -1,    -1,    -1,    -1,   344,    -1,
      -1,   347,   348,    -1,    -1,    -1,   352,    -1,    -1,    -1,
      -1,    -1,   358,   359,    -1,    -1,    -1,    -1,    -1,   365,
     366,   367,    -1,    -1,   370,   371,   372,    -1,    -1,    -1,
     376,    -1,    -1,    -1,   380,    -1,   382,    -1,    -1,    -1,
      -1,    -1,    -1,   389,   390,   391,   392,    -1,   394,   395,
      -1,    -1,    -1,   399,   400,    -1,   402,   403,   404,   405,
     406,   407,   408,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,    -1,   418,   419,    -1,    -1,    -1,   423,   424,   425,
     426,   427,   428,   429,   430,    -1,   432,    -1,    -1,  3740,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,    -1,   474,   475,
      -1,    -1,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,    -1,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,    -1,    -1,
     506,   507,   508,   509,   510,   511,   512,   513,   514,    -1,
     516,   517,   518,   519,    -1,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,    -1,   558,   559,   560,   561,   562,   563,    -1,    -1,
     566,   567,    -1,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,    -1,
      -1,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,    -1,    -1,    -1,    -1,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   692,    -1,    -1,    -1,
      -1,   697,    -1,    -1,    -1,   701,    -1,    -1,   704,   705,
     706,   707,    -1,    -1,   710,   711,    -1,   713,   714,   715,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
      -1,    -1,   157,   158,   159,   160,    -1,    -1,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,    -1,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,   338,    -1,    -1,    -1,    -1,    -1,   344,
      -1,    -1,   347,   348,    -1,    -1,    -1,   352,    -1,    -1,
      -1,    -1,    -1,   358,   359,    -1,    -1,    -1,    -1,    -1,
     365,   366,   367,    -1,    -1,   370,   371,   372,    -1,    -1,
      -1,   376,    -1,    -1,    -1,   380,    -1,   382,    -1,    -1,
      -1,    -1,    -1,    -1,   389,   390,   391,   392,    -1,   394,
     395,    -1,    -1,    -1,   399,   400,    -1,   402,   403,   404,
     405,   406,   407,   408,    -1,    -1,    -1,    -1,    -1,   414,
     415,   416,    -1,   418,   419,    -1,    -1,    -1,   423,   424,
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
     655,   656,   657,   658,    23,    -1,    -1,    -1,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,    -1,
      39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,   684,
      -1,    50,    51,    -1,    -1,    -1,    -1,   692,    -1,    -1,
      -1,    -1,   697,    -1,    -1,    -1,   701,    -1,    -1,   704,
     705,   706,   707,    -1,    -1,   710,   711,    -1,   713,   714,
     715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,   276,    -1,    -1,
      -1,    -1,    -1,   282,    -1,    -1,    -1,   286,   287,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   318,
      -1,    -1,   321,    -1,   323,    -1,    -1,    -1,    -1,    -1,
      -1,   330,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      -1,    36,    37,    38,   343,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,   375,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,
      -1,    -1,   401,    -1,    99,   100,    -1,    -1,    -1,   104,
     409,   410,   411,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,   168,   169,   170,    -1,    -1,   477,    -1,
      -1,    -1,    -1,   178,   179,    -1,   181,   182,   183,   488,
      -1,    -1,    -1,    -1,   189,    -1,    -1,   192,    -1,   194,
     195,   196,    -1,    -1,    -1,    -1,    -1,   202,    -1,   204,
     205,    -1,   207,    -1,   209,   210,    -1,    -1,   213,    -1,
      -1,   216,   217,   218,   219,   220,   221,    -1,    -1,   528,
     225,   226,   227,    -1,   229,    -1,    -1,    -1,   233,    -1,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,   244,
      -1,    -1,   247,    -1,   249,    -1,   251,    -1,   253,    -1,
      -1,    -1,   257,   258,    -1,   260,   261,   262,    -1,    -1,
     265,    -1,   267,   268,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,   279,    -1,    -1,    -1,    -1,    -1,
     589,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,   294,
     295,    -1,    -1,   298,   299,    -1,    -1,   302,   303,    -1,
      -1,    -1,   406,    -1,    -1,    -1,   311,   312,   313,    -1,
     315,    -1,    -1,    -1,   418,    -1,   625,    -1,    -1,    -1,
     325,   326,   327,    -1,   329,    -1,    -1,    -1,   333,   334,
      -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,
     355,   356,    -1,    -1,    -1,    -1,    -1,   362,   363,    -1,
      -1,    -1,   671,    -1,    -1,   370,    -1,    -1,   373,    -1,
      -1,   475,   377,   378,   478,    -1,   685,   686,   687,   688,
     689,   690,   691,   388,   693,   694,    -1,   491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     405,   710,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,
      -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   430,   530,   531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,   443,   543,
      -1,    -1,    -1,    -1,   449,    -1,   451,   452,    -1,    -1,
      -1,    -1,    -1,    -1,   459,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,   516,    -1,   617,    -1,    -1,    -1,    -1,    -1,   623,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   632,   633,
      -1,   635,    -1,    -1,    -1,   540,   541,    -1,    -1,    -1,
     545,    -1,    -1,   647,   648,    -1,    -1,    -1,    -1,    -1,
      -1,   655,   557,    -1,   658,    -1,    -1,    -1,   563,   564,
     565,   566,   666,    -1,    -1,   570,    -1,    -1,    -1,   574,
      -1,    -1,    -1,    -1,    -1,    -1,   581,   582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,   594,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     605,    -1,   607,    -1,    -1,   610,    -1,    -1,   157,   158,
     159,   616,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   642,    -1,    -1,
     645,    -1,    -1,    -1,    -1,   650,    -1,    -1,   653,   654,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   668,    -1,    -1,    -1,     6,     7,     8,
     675,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   698,   699,   700,   701,   702,   703,   704,
      -1,    40,   707,    -1,   709,    -1,   711,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,
      -1,   300,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,     6,     7,     8,
     439,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     297,    -1,    -1,   300,   139,   140,   141,   142,   143,   144,
      -1,    40,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,   297,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   522,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,
      -1,    -1,   439,    -1,   603,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     439,   440,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   504,    -1,    -1,
     669,   420,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   522,   435,   476,    -1,    -1,
     439,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   297,    18,
      19,   300,    -1,   522,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,
     435,    -1,    -1,    -1,   439,   440,   603,    -1,    -1,    -1,
      -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,   603,    -1,   297,    -1,    -1,   300,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,
      -1,   420,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     439,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     669,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,    -1,    40,    -1,
     669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,   157,
     158,   159,    -1,    -1,    -1,   504,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   522,   435,    -1,    -1,    -1,   439,   440,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,   669,   476,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,   504,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   603,   157,   158,   159,    -1,    -1,
      -1,   522,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   297,
      -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
     669,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    40,   406,    -1,    -1,
      -1,    -1,   603,   157,   158,   159,    -1,    -1,    -1,   418,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,   300,   139,
     140,   141,   142,   143,   144,    -1,   475,    -1,   669,   478,
      -1,    -1,   420,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,   491,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,   439,   440,    -1,    -1,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,   530,   531,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   297,    -1,    -1,   300,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   504,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,   522,   584,    -1,    -1,   420,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   435,    -1,    -1,    -1,   439,   440,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,   623,    -1,    -1,   297,    -1,    -1,
     300,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,   647,   648,
      -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,   658,
      -1,    -1,    -1,   297,    -1,   603,   300,   666,    -1,    -1,
      -1,    -1,   504,    -1,    -1,    -1,   420,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     522,   435,    -1,     7,     8,   439,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,   300,   139,
     140,   141,   142,   143,   144,    -1,    40,    -1,    -1,    -1,
      -1,   669,   476,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     504,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,
      -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,    -1,     8,   420,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   435,    -1,    -1,    -1,   439,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,   489,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   504,    -1,    -1,   669,   420,    -1,
      -1,    -1,   476,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,   522,   435,    -1,   489,    -1,   439,    -1,   603,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     504,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,
     300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
     143,   144,   504,    -1,    40,   669,    17,    18,    19,    20,
      21,    22,    -1,   603,   157,   158,   159,    -1,    -1,    -1,
     522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    18,    19,    20,    -1,   603,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,   297,    -1,    -1,   300,    -1,    16,    17,
      18,    19,    20,    21,    22,    18,    19,    -1,    -1,   669,
     420,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,   435,    -1,    -1,    -1,   439,
      -1,   603,    -1,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,    -1,    -1,   476,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   489,
      -1,    -1,    -1,    -1,   297,    -1,    -1,   300,   139,   140,
     141,   142,   143,   144,   504,    -1,    -1,   669,    -1,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,   522,    -1,    -1,    -1,   420,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   435,    -1,    -1,    -1,   439,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   297,    -1,   603,   300,   238,    -1,    -1,    -1,    -1,
     504,    -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,   522,   300,
      -1,    -1,   435,    -1,    -1,   238,   439,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   297,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,
      -1,    -1,    -1,   476,    -1,    -1,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,
      -1,    -1,   300,    -1,   157,   158,   159,    18,    19,    20,
      -1,   504,    -1,    24,    25,    26,    27,    -1,    -1,   603,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,
      -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,   435,
      -1,    -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,    -1,
      -1,    -1,    -1,   406,    -1,   669,    -1,    -1,    -1,   420,
     476,   238,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   435,    -1,    -1,    -1,   439,    -1,
     603,    -1,    -1,   406,    -1,   476,    -1,    -1,   504,    -1,
      -1,   444,   420,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   522,   435,    -1,    -1,
      -1,   439,    -1,   504,   297,   476,    -1,   300,    -1,    -1,
      -1,   444,   475,    -1,    -1,   478,    -1,    18,    19,    -1,
      -1,   522,    -1,    24,    25,    26,    27,    -1,   491,   238,
      -1,    -1,    -1,   504,    -1,    -1,   669,    -1,   476,    -1,
      -1,    -1,   475,    -1,    -1,   478,    -1,    -1,    -1,    -1,
      -1,   522,    -1,    -1,    -1,   518,    -1,    -1,   491,    24,
      25,    26,    27,    -1,    -1,    -1,   504,    -1,   531,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,
     543,    -1,    -1,    -1,   522,   518,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     543,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,   584,    -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,
      -1,   418,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,   669,    -1,    -1,   439,   112,    -1,    -1,
      -1,   584,    -1,    -1,   617,    -1,    -1,   444,    -1,    -1,
     623,    -1,    -1,    -1,    -1,   603,    -1,    -1,   669,   632,
     633,    -1,   635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   476,   647,   648,    -1,    -1,   475,    -1,
     623,   478,   655,    -1,    -1,   658,    -1,   406,   669,    -1,
      -1,    -1,   635,   666,   491,    -1,    -1,    -1,    -1,   418,
      -1,   504,    -1,    32,   647,   648,    35,    -1,    -1,    -1,
      -1,    -1,   655,    -1,    -1,   658,    -1,    -1,    -1,   522,
      -1,   669,    -1,   666,    -1,   444,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,   418,    -1,   478,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   444,    -1,    -1,    -1,   584,    -1,    46,
      47,    48,    49,    -1,    -1,    52,    53,    -1,   127,   128,
     603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,   531,    -1,   475,    -1,    -1,   478,    -1,    -1,
     617,    -1,    -1,    -1,   543,    -1,   623,    -1,    -1,    -1,
     491,    -1,    -1,    -1,    -1,   632,   633,    -1,   635,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     647,   648,    -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,
      -1,   658,    -1,    -1,    -1,   584,   669,    -1,    -1,   666,
     531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   617,    -1,
      -1,    -1,    -1,    -1,   623,    -1,    -1,   418,    -1,    -1,
      -1,    -1,    -1,   632,   633,    -1,   635,    -1,    -1,    -1,
      -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,   647,   648,
      -1,   406,    -1,   444,    -1,    -1,   655,    -1,    -1,   658,
      -1,    -1,    -1,   418,    -1,    -1,    -1,   666,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,    -1,    -1,
      -1,    -1,   623,    -1,   475,    -1,    -1,   478,    -1,   444,
      -1,   632,   633,    -1,   635,    -1,    -1,    -1,    -1,   308,
     491,    -1,    -1,    -1,    -1,    -1,   647,   648,    -1,    -1,
      -1,    -1,    -1,   250,   655,    -1,    -1,   658,    -1,    -1,
     475,    -1,    -1,   478,    -1,   666,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,   347,    -1,
     531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,   366,   367,   368,
     369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     307,    -1,    -1,    -1,    -1,   384,   531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,
      -1,    -1,    -1,   584,    -1,   332,    -1,   406,    -1,    -1,
      -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,   418,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,   623,    -1,    -1,    -1,    -1,   446,    -1,    -1,
      -1,    -1,   379,    -1,   635,   382,    -1,   456,    -1,    -1,
     387,    -1,    -1,    -1,    -1,    -1,   647,   648,   395,    -1,
      -1,    -1,   471,    -1,   655,    -1,    -1,   658,   623,    -1,
      -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,
     635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   647,   648,    -1,    -1,    -1,    -1,    -1,    -1,
     655,    -1,   511,   658,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   458,    -1,    -1,    -1,   534,    -1,   464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,    -1,   479,    -1,    -1,    -1,    -1,   556,    -1,    -1,
     559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,    -1,
      -1,   580,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,
     537,   538,    -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,    -1,   553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   575,    -1,
      -1,   578,   579,    -1,    -1,    -1,   583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   649,    -1,   651
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   123,   284,   405,   454,   485,   514,   782,
     810,   811,   867,  1041,  1097,  1099,  1100,  1101,  1106,  1108,
    1121,  1122,  1123,  1124,  1125,  1563,    28,    29,   783,   784,
     785,   786,   787,    27,  1005,  1578,  1005,    25,  1005,  1474,
    1126,   812,  1474,   811,     0,  1098,  1101,  1124,    31,   785,
     787,   868,   658,    25,   238,   809,   810,   992,  1005,  1010,
    1106,  1121,  1127,  1162,  1163,  1164,  1165,  1166,  1170,   403,
     814,   815,   816,   817,   820,   821,   101,   108,   154,   155,
     162,   416,   442,   512,   604,   684,   692,   782,   788,   964,
    1040,  1102,  1103,  1105,  1109,  1110,  1116,  1128,  1149,  1283,
    1293,  1563,   663,  1005,  1165,   290,   505,   506,  1172,    20,
    1005,  1169,   666,   815,     5,   813,   403,  1005,     5,   839,
     841,   842,  1005,  1294,  1005,  1005,  1284,  1117,  1005,  1005,
    1105,  1111,   308,   347,   366,   367,   406,   418,   429,   446,
     456,   471,   511,   534,   549,   556,   559,   580,   584,   603,
     621,   869,   870,   871,   874,    25,  1162,  1168,    18,    19,
      26,   107,   119,   146,   240,   337,   372,   406,   418,   455,
     470,   478,   491,   535,   560,   584,   628,   637,   721,   722,
     732,   734,   929,   934,   945,   947,  1005,  1162,  1173,  1174,
     506,    14,   866,   817,   569,  1270,   818,   815,   820,    32,
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
     914,   915,   916,   917,   945,   946,   948,  1011,  1162,  1273,
    1466,   478,   478,   478,   478,   478,   478,    18,    19,    20,
      21,    22,   733,    26,   478,   568,     5,   474,  1173,    25,
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
     903,   903,   903,   573,  1290,   478,   478,   903,   415,   501,
     517,   560,   599,   628,   637,  1469,  1470,   478,   903,   903,
     478,   478,   918,   478,   478,   478,   478,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    40,   139,   140,   141,   142,   143,
     144,   157,   158,   159,   297,   300,   420,   435,   439,   476,
     504,   522,   603,   669,   805,   904,   919,   921,   922,   923,
     924,   925,   926,   927,    26,  1011,   468,   937,   935,   941,
     939,  1162,  1162,   732,   930,  1005,  1174,   506,   474,    26,
     826,   478,   848,   815,   848,   828,    26,    26,    26,   815,
      26,    26,   814,   831,   848,    26,   666,   106,   840,  1295,
     440,   478,  1285,  1579,  1580,  1581,  1582,  1583,   966,  1151,
    1112,   666,    26,   440,   857,   858,   478,   859,   864,   865,
     859,   478,   860,     5,   440,     5,   440,     5,   331,     5,
     869,   474,     5,     5,   440,   815,   851,   478,     5,   440,
     506,   666,   440,   440,   440,   440,   440,   440,    19,   440,
     636,   950,    19,    26,   636,   440,     5,   440,   440,     5,
     807,   903,   518,  1490,   903,   478,   672,    20,   440,  1490,
      20,  1273,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   903,   478,   903,   903,   478,  1162,
     903,   903,   903,   903,   440,     5,   530,   762,   763,   764,
     903,   478,  1173,   506,   670,    26,   666,    26,   440,   440,
       5,   440,   306,     5,   440,     5,   440,   331,   474,     5,
     440,   851,  1005,  1179,  1180,  1182,  1129,  1179,   410,  1580,
    1270,    36,    37,    38,    42,    45,    54,    55,    99,   100,
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
    1132,  1143,  1144,  1145,  1156,  1159,  1195,  1198,  1200,  1206,
    1207,  1210,  1213,  1216,  1218,  1220,  1223,  1230,  1235,  1239,
    1240,  1241,  1253,  1254,  1257,  1263,  1265,  1266,  1291,  1306,
    1307,  1308,  1309,  1310,  1322,  1328,  1329,  1349,  1352,  1381,
    1383,  1475,  1476,  1507,  1508,  1515,  1530,  1554,  1563,  1564,
    1569,  1570,  1572,  1576,  1577,  1584,   782,  1107,   671,   694,
    1152,  1153,  1179,    20,   440,   473,   829,   856,    26,   861,
      26,    26,    26,   878,   880,   872,   832,    26,  1005,   996,
     732,    20,   713,  1005,   943,  1470,    26,   943,    26,    26,
     636,    24,    26,   853,   944,   997,   854,   440,   408,   523,
     632,  1498,   440,   440,    26,  1470,   440,   440,   440,   440,
     440,   440,   440,   489,   489,   489,   928,  1490,   489,   928,
    1490,   938,   936,   942,   940,    26,   931,     5,   932,   474,
    1173,   839,   440,    20,   829,    26,   478,    26,    26,   825,
      26,   666,   440,     5,  1179,   440,  1162,  1162,  1162,  1005,
      25,  1162,  1217,  1005,    25,  1005,  1459,   399,  1006,  1007,
    1578,  1006,    25,  1005,  1458,  1005,  1005,  1237,  1000,  1006,
    1000,  1005,  1574,  1459,  1005,    26,   729,  1162,  1313,  1000,
    1237,   928,    26,  1011,  1278,  1279,  1278,   903,   910,  1351,
    1458,  1458,   905,   928,  1006,  1516,  1516,   886,  1237,  1000,
    1311,  1162,  1002,  1006,   910,  1516,  1162,  1237,  1162,  1350,
    1516,    25,   632,  1146,  1147,  1162,  1000,  1000,  1146,  1001,
    1006,  1005,  1147,  1000,  1516,  1000,  1002,  1459,  1162,  1193,
    1194,   998,  1006,  1002,   424,   608,   996,  1068,  1005,   790,
    1458,  1003,  1006,    25,   238,  1005,  1171,  1382,  1558,  1559,
    1560,   928,  1193,   672,   928,  1006,  1219,   960,    57,    58,
      59,    60,   180,   188,   197,   200,   243,   250,   307,   332,
     339,   341,   351,   379,   387,   424,   449,   486,   497,   595,
     596,   597,   608,   711,  1082,  1214,  1215,  1162,  1184,  1185,
     909,   910,  1229,   953,   953,   999,  1006,   928,  1217,  1292,
    1162,  1269,    25,  1162,  1510,  1264,   910,  1565,   153,   203,
     240,   337,   414,   455,   521,   746,   934,  1005,  1162,  1301,
     769,   910,   998,   636,  1005,  1013,  1133,   910,   998,    26,
    1162,  1090,   998,   910,  1531,   910,  1278,  1005,  1015,  1016,
    1002,  1015,   953,  1002,  1015,   953,  1021,  1015,    25,    26,
     433,   534,  1011,  1071,  1162,  1181,  1183,   113,   322,   394,
     438,   615,   695,   696,   697,   706,   736,  1023,  1025,  1027,
    1029,  1031,  1157,  1158,  1161,   385,   396,   447,   461,   550,
    1384,   686,   687,   968,   969,   970,  1005,  1154,   693,  1153,
     440,   350,   440,   440,   440,   440,   670,     5,   440,   440,
     474,   478,   672,    19,   440,   440,    26,   636,   672,    18,
      19,    20,    25,    26,   112,   406,   418,   444,   475,   478,
     491,   531,   543,   584,   617,   623,   632,   633,   635,   647,
     648,   655,   658,  1005,  1011,  1465,  1467,  1497,  1499,  1500,
    1502,  1503,  1504,  1526,  1527,  1528,  1529,  1559,  1562,  1290,
     440,  1290,  1290,  1290,  1290,  1290,  1290,    25,    25,    25,
     903,   920,   440,    25,   920,   440,   440,   440,   440,   440,
     440,   440,   764,   762,   474,   350,   440,   815,   837,   838,
     440,   440,   670,   440,  1005,  1296,  1182,   440,  1286,   102,
     103,   132,   133,   134,   502,   588,   631,  1330,  1331,  1332,
    1335,  1338,  1341,  1342,  1343,  1346,   666,   636,   658,   149,
     150,   478,   666,   636,   658,     8,   671,   474,  1458,   526,
    1238,  1181,   157,   158,   159,   642,   530,   906,   907,   910,
    1162,  1188,  1458,   735,   736,   889,   314,   135,   136,   672,
     507,     5,   665,   672,   664,   664,  1196,   642,   468,     5,
     603,  1043,   507,   705,  1567,   705,   433,   792,  1162,   593,
     664,  1201,  1202,  1203,   666,    25,  1560,  1172,   376,  1380,
     658,   666,   908,   910,   603,  1558,   908,     8,   600,   999,
      26,   548,   601,   715,   991,  1162,   991,   991,   991,    25,
     225,   352,   358,   359,   360,   380,   486,   489,   497,   532,
     567,   586,   587,   597,   602,   641,   673,  1086,  1087,   991,
     991,   643,  1083,   736,  1083,  1083,   992,   992,  1083,  1083,
     736,     5,   468,     5,   383,   434,     5,   735,   129,   130,
     586,   673,  1074,   708,  1568,   909,   659,   660,   661,   662,
    1268,  1270,   910,  1259,  1260,  1261,  1271,  1272,   910,   478,
     478,   478,   478,    25,   765,  1005,   478,  1510,   394,   478,
     568,   636,   625,   770,   777,   768,  1005,    25,  1148,  1162,
    1255,     8,  1258,    14,  1005,  1167,  1175,  1176,  1178,  1186,
    1187,  1231,   211,   394,   591,   624,     5,     6,     7,     8,
       9,    10,    12,    13,    14,    18,    19,    20,    21,    22,
      23,    33,    53,   110,   119,   137,   138,   146,   153,   154,
     157,   158,   159,   160,   163,   164,   203,   225,   231,   238,
     240,   245,   271,   309,   322,   328,   337,   338,   344,   347,
     348,   352,   358,   359,   365,   366,   367,   370,   371,   372,
     376,   380,   382,   389,   390,   391,   392,   394,   395,   399,
     400,   402,   403,   404,   405,   406,   407,   408,   414,   415,
     416,   418,   419,   423,   424,   425,   426,   427,   428,   429,
     430,   432,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   474,
     475,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   516,   517,   518,   519,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   558,   559,   560,   561,   562,
     563,   566,   567,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   684,   692,   697,   701,   704,   705,   706,   707,
     710,   711,   713,   714,   715,  1532,  1533,  1534,  1536,   622,
       5,   705,   705,   908,  1181,  1188,  1070,   468,     5,   199,
    1048,   478,  1162,   908,   478,    26,    26,   113,  1160,    25,
    1162,  1514,  1514,  1006,  1364,  1219,   999,   167,   269,   277,
     283,   285,   296,   324,   340,   345,   357,   364,   513,   518,
     525,   547,   552,  1353,  1354,  1362,  1371,  1372,  1378,  1379,
    1385,  1386,  1396,  1416,  1420,  1486,  1487,  1517,  1518,  1521,
    1522,  1538,   971,   972,   138,   967,   978,   979,   970,  1155,
    1579,  1113,   506,   869,   832,   666,  1005,   415,   501,   517,
     560,   599,   628,   637,  1471,    26,   943,   943,   636,    24,
      26,   857,  1503,  1503,   478,   478,   415,   501,   517,   560,
     599,   628,   637,  1468,  1472,   518,  1502,   478,   478,   478,
     478,  1497,  1497,  1497,   478,   478,   478,   478,  1005,   478,
       5,   593,  1425,  1430,  1005,    18,    19,    20,    21,   139,
     140,   141,   142,   143,   144,  1524,  1472,  1472,   468,     5,
     440,   440,   933,   506,     5,   440,   839,   809,  1130,   809,
     293,   306,   408,   478,   523,   539,  1400,  1401,  1406,  1408,
     478,  1005,  1347,  1348,    26,   478,  1005,  1327,  1340,  1408,
    1410,   478,  1005,  1337,   478,  1327,  1333,     5,  1005,    25,
    1005,  1005,    25,  1008,  1165,  1005,    25,  1005,  1005,  1005,
    1575,  1458,   642,   478,   478,   889,  1458,     5,   672,   478,
    1558,    25,  1010,  1236,  1236,  1510,  1146,   910,   910,   910,
     993,   994,   478,  1162,  1194,  1044,  1045,  1046,  1458,   672,
    1510,   953,  1568,  1068,  1162,   791,   671,   910,   400,  1205,
     603,  1204,  1560,  1005,    20,  1005,  1192,  1561,     5,  1555,
     663,  1211,   116,   118,   120,   664,   672,   881,  1181,  1184,
     961,    18,    19,   478,  1084,  1086,  1215,  1162,  1185,   992,
     910,   394,   642,    26,    26,   735,   201,  1267,   432,  1305,
    1270,  1261,     5,   664,  1262,  1566,  1005,    25,   953,   953,
     636,   997,   669,  1162,   750,  1005,  1005,   910,   389,   773,
     777,   625,   771,   779,    23,   282,  1135,  1139,   529,   928,
     529,  1256,   910,   505,  1172,   666,     5,  1091,   593,  1232,
    1162,  1535,  1537,   237,  1533,  1034,  1016,   953,   953,  1026,
    1027,  1048,  1048,    39,    41,    43,    44,    50,    51,   318,
     321,   323,   343,   353,   374,   397,   401,   477,  1047,  1049,
    1050,  1078,  1162,  1183,   593,   737,    26,   448,  1032,   371,
    1509,  1509,   186,   187,   484,   593,  1005,  1417,  1418,  1460,
    1458,  1458,  1458,  1355,  1458,  1458,  1005,  1519,   215,   428,
     443,   486,   497,   518,   525,   533,   555,   632,   638,  1387,
    1389,  1390,  1391,  1498,  1458,  1363,  1387,  1389,  1579,  1579,
     433,   980,  1162,   688,   689,   973,   974,   975,   528,   671,
     690,   691,   710,   983,   984,  1579,   809,    26,   830,    20,
    1005,   440,   478,   440,    24,    26,    25,    26,    25,    26,
     672,  1498,   440,   444,  1502,  1525,  1562,   408,   523,   632,
    1449,  1502,  1505,  1449,  1449,  1449,  1449,   666,  1505,  1500,
     562,  1426,  1427,  1428,  1458,   573,  1424,  1431,   381,   561,
     572,  1373,  1493,  1502,  1502,  1502,  1502,   672,   478,   672,
    1559,   903,   440,   830,   838,  1297,   809,  1287,   478,   478,
     478,  1344,  1408,   478,   478,   105,  1345,  1347,     5,  1339,
    1340,   111,   347,   367,   368,   369,   406,   418,   429,   446,
     456,   471,   519,   549,   559,   580,   584,   612,   621,  1450,
    1451,  1452,  1454,  1336,  1337,  1333,  1334,   710,  1331,   666,
     636,   440,   666,   636,   593,  1573,   478,   730,   731,  1005,
    1314,   928,   906,  1005,  1312,   663,  1208,   672,     5,     5,
       5,   626,   910,     5,   666,   530,   672,   671,   212,   214,
     318,   321,   793,   796,   797,  1078,   794,   795,  1005,   478,
    1006,   695,   696,  1209,   666,   506,   910,  1458,  1556,  1557,
    1558,   623,   663,  1212,  1005,  1005,   994,   995,   556,   953,
     889,     8,     8,   963,    26,    26,  1085,  1086,  1162,   367,
    1224,   113,   903,  1270,   266,  1272,  1278,  1579,     5,     5,
     440,   440,   766,  1005,   440,  1510,   762,   478,   478,   778,
     774,   409,   772,   910,   389,   775,   779,   643,  1080,  1140,
    1136,   411,  1134,  1135,   908,   672,  1168,    20,  1005,  1177,
    1187,    14,   530,  1233,  1234,  1502,  1562,  1184,  1579,  1028,
    1029,   597,  1004,   593,  1059,  1058,  1063,  1062,  1061,  1060,
     996,  1064,   996,  1065,  1057,  1056,  1054,  1053,  1079,   374,
    1050,  1055,   953,    46,    47,    48,    49,    52,    53,   145,
     382,   395,   458,   464,   503,   527,   537,   538,   543,   553,
     575,   578,   579,   583,   640,   651,   738,   739,  1076,  1077,
       5,    26,  1510,   296,  1162,   518,  1491,  1492,  1510,  1219,
    1485,  1487,   147,   147,   642,  1217,  1419,  1420,   478,  1397,
     198,  1431,  1458,   222,   319,  1523,   666,   672,   478,  1392,
    1392,   593,   671,     5,  1488,  1539,   391,   400,   424,   427,
     444,   548,   601,   608,   999,  1365,  1370,   672,   671,   982,
    1162,     5,   593,   976,   977,   685,   975,   981,  1005,   981,
     985,   986,   981,   374,   984,  1114,   474,    26,   943,   440,
      19,   440,   636,   440,    19,   440,   636,   415,   501,   517,
     560,   599,   628,   637,  1473,  1499,     5,  1472,     5,   440,
       5,  1502,     5,   440,  1502,  1502,  1502,  1502,  1005,   440,
     478,  1428,     5,  1005,  1464,     9,   342,   478,   490,  1434,
    1435,  1436,  1437,  1438,  1442,  1446,  1448,  1502,   417,  1422,
    1432,  1005,  1494,   665,  1449,   381,  1473,    26,  1473,   474,
     508,  1280,  1300,  1131,   508,  1242,  1274,   658,  1005,  1403,
    1405,  1458,  1462,  1463,  1407,  1462,  1407,     5,   440,  1345,
    1407,  1434,  1005,   440,  1348,     5,   440,   478,   478,   478,
    1472,  1472,   478,   478,   478,   478,   478,   254,   255,   256,
     448,  1409,  1411,     5,   440,     5,   440,  1005,  1005,    25,
    1005,  1005,    25,  1005,   910,  1005,  1324,  1325,     5,  1326,
    1327,   928,  1120,   666,  1326,   623,  1510,  1510,   910,   910,
     993,   556,   910,  1571,     5,  1045,    20,  1462,  1510,   794,
     802,   801,   803,  1005,  1009,   804,  1009,   239,   797,   800,
       5,  1048,   666,   910,     8,  1561,  1173,   666,     5,  1510,
     623,  1005,  1181,   928,   600,  1368,     5,   440,  1162,     5,
      26,  1162,   375,    25,  1302,   394,   394,   506,   666,   394,
     478,   751,   755,   748,  1579,  1579,   780,   776,   772,  1081,
      25,  1004,  1141,  1162,  1579,   910,   473,   506,   928,     5,
    1035,  1030,  1031,    26,   735,  1005,  1579,  1579,  1579,  1579,
    1579,  1579,     5,  1051,     5,  1052,  1579,  1579,  1579,  1579,
    1084,  1579,  1004,    25,    14,    14,     5,   440,    26,  1458,
    1498,  1479,   642,   642,  1354,  1484,  1485,  1420,  1398,  1462,
     663,   999,   478,  1358,  1005,  1520,  1519,  1393,  1462,   510,
    1394,  1395,  1460,  1458,  1391,  1499,    93,    94,    95,    96,
      97,   630,  1542,   910,   910,   600,  1366,   999,  1394,  1458,
       5,  1162,   981,  1579,  1579,     5,   988,   989,  1579,  1579,
     987,  1107,   873,   440,    26,    26,    26,    26,   478,  1430,
    1472,   672,  1472,  1472,   440,  1502,   440,   440,   440,   440,
    1427,  1429,  1427,  1437,  1497,  1434,  1502,  1497,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   300,   420,
     421,   476,   603,   669,   719,   720,  1445,  1447,  1423,  1501,
    1502,   495,  1421,  1433,   316,  1323,    26,  1374,  1375,  1376,
    1462,  1491,  1494,   440,   827,   121,   122,   124,   125,   126,
     224,   232,   266,   275,   304,   305,   349,   393,   448,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,  1277,
    1281,   185,   561,  1282,  1298,  1107,   208,   223,   224,   232,
     266,   275,   304,   349,   393,  1275,  1276,  1288,  1282,  1463,
     506,  1461,   440,     5,   666,     5,   440,   440,  1408,   440,
     440,  1340,    26,  1455,  1455,    26,   672,   478,   672,    26,
    1456,    26,    26,  1456,  1456,    25,  1465,   206,   306,   344,
     408,   422,   523,   539,  1402,  1412,  1413,  1414,  1415,  1337,
    1333,   666,   666,   585,   634,     5,   440,   731,     5,   440,
     908,   440,    20,   440,  1510,     5,   910,   613,   322,   740,
     741,   910,  1048,  1579,  1579,     5,   798,   506,   666,     5,
     799,  1579,   795,   593,    20,  1005,     5,  1005,  1199,   474,
      20,  1462,  1557,     8,  1510,   438,   705,   908,  1369,   962,
    1086,   714,  1222,   903,     5,   762,  1162,   747,   729,  1005,
    1162,   753,   440,   762,   762,  1579,  1579,  1084,  1138,    25,
    1142,  1162,   618,   958,  1173,   530,   909,  1092,  1234,   110,
     589,  1036,  1022,  1023,   666,   996,  1579,   996,  1579,   735,
      26,  1162,    26,  1162,   739,   440,   478,  1511,  1499,  1485,
    1485,  1477,     5,   440,   518,  1496,  1359,  1462,   526,  1356,
    1496,   672,     5,   440,     5,   593,  1489,    18,    19,   112,
     475,   478,   491,   530,   531,   543,   584,   623,   635,   647,
     648,   655,   658,  1005,  1465,  1497,  1526,  1528,  1547,  1548,
    1549,  1550,  1551,  1552,  1562,  1547,  1547,  1547,  1462,  1544,
    1546,  1543,  1544,  1545,  1540,  1367,   672,  1162,  1005,  1579,
    1579,  1579,  1579,   670,    19,   440,   440,   636,    19,   440,
     440,   636,    26,   440,   672,  1473,   672,   672,     5,   440,
     440,  1435,  1436,  1440,  1503,  1440,   478,  1497,  1440,   478,
    1497,  1440,    10,   297,   435,   437,  1502,     5,  1434,     5,
     585,   634,  1377,  1323,   672,   670,  1278,  1278,  1278,    25,
    1278,  1278,  1278,  1278,  1278,  1278,    25,    25,  1278,  1281,
    1162,  1189,  1190,   665,   494,  1243,  1579,    25,    25,    26,
      26,    26,    26,    26,    25,  1162,  1276,  1243,    26,  1402,
    1462,    20,  1005,  1462,  1345,   440,   440,     5,   440,  1473,
      26,  1473,     5,  1453,     5,   440,   440,   440,  1453,  1404,
    1458,   478,  1414,  1345,  1005,  1005,  1325,   669,   723,  1319,
    1320,  1321,  1327,    56,   133,   134,   292,   669,  1315,  1316,
    1317,   515,   888,  1315,     5,   423,  1510,     5,   478,   440,
     597,  1075,  1009,  1579,   732,    20,  1005,  1009,  1579,   953,
     910,  1510,     8,   953,  1184,  1579,    26,  1004,    25,  1303,
    1181,   474,   762,   752,   756,   440,  1579,  1004,   910,   956,
     474,  1038,  1037,   488,  1024,  1025,    20,  1005,  1512,  1513,
     600,  1495,  1480,  1478,  1462,  1498,   190,  1399,     5,   440,
    1357,  1520,  1462,  1395,  1394,  1495,  1550,  1550,  1549,   478,
     478,   478,   478,   478,   478,   478,  1005,   478,     5,   440,
      18,    19,    20,    21,  1524,   440,     5,   440,     5,    14,
     198,   573,  1541,  1184,  1394,   259,  1115,   869,    26,    26,
      26,    26,   440,  1473,  1473,  1473,  1427,   489,  1439,  1439,
    1443,  1444,  1465,  1562,  1439,  1443,  1439,  1440,  1502,  1501,
    1375,  1473,   839,   585,   634,  1191,     5,  1189,   109,   184,
     246,   248,   264,   272,   276,   301,  1244,  1245,  1299,  1115,
    1289,     5,   474,  1461,    26,   440,    26,  1457,   440,    26,
     440,   478,  1434,  1318,  1578,    26,  1321,    26,    26,  1318,
    1323,  1317,   996,   735,   423,  1510,   910,   742,   615,  1197,
      26,   735,   474,  1075,   440,  1510,   288,   735,   440,   440,
     478,   754,   394,   760,   440,   749,  1137,  1579,   506,   910,
    1579,  1004,     5,   440,  1184,  1430,  1499,  1462,   478,  1430,
     440,  1525,  1449,  1549,  1553,  1449,  1449,  1449,  1449,   666,
    1553,  1548,  1549,  1549,  1549,  1549,  1544,    14,  1545,  1548,
     999,  1434,   191,   663,  1388,    26,   440,   440,   440,   440,
    1441,  1465,  1506,     5,   440,   440,  1439,     7,  1190,  1246,
    1247,  1162,  1249,  1162,  1248,  1250,  1245,   287,   287,    26,
     440,   672,   440,  1405,   440,   887,  1510,   441,   250,   307,
     332,   341,   379,   387,   479,   649,   739,   743,   744,   478,
     666,   735,  1221,  1304,   757,   440,  1181,   760,   760,  1579,
     957,  1173,   622,  1072,  1513,  1493,  1430,   530,  1360,  1361,
    1502,  1493,   440,  1549,     5,   440,  1549,  1549,  1549,  1549,
    1005,   440,   478,  1005,   636,  1444,  1502,  1579,  1579,  1251,
    1579,  1252,  1579,  1579,   474,  1473,   440,   286,   397,   401,
     890,   891,   892,  1078,   991,   991,   991,   991,   991,   991,
      25,     5,   440,   910,    20,  1005,  1078,  1225,  1226,  1227,
     760,   762,   760,   289,   474,  1039,   735,     5,   440,   335,
     336,  1481,   440,  1549,   440,   440,   440,   440,  1547,    26,
    1579,  1579,   894,   893,   286,   892,   895,   744,     5,  1228,
     330,  1227,   758,  1579,  1361,    25,  1005,  1482,  1483,   440,
     440,   636,  1579,  1579,  1579,   910,  1579,   440,  1036,   666,
     666,     5,    26,   440,   759,  1005,  1005,  1483,   440,   211,
     394,   761,   666,  1181,  1005
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
#line 992 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 995 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 999 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1005 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1010 "fgl.yacc"
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
#line 1022 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1027 "fgl.yacc"
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
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1051 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1052 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1053 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1054 "fgl.yacc"
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
#line 1065 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1071 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1072 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1073 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1074 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1075 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1080 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1081 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1092 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1095 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1098 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1098 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1105 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1106 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1112 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1113 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1114 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1115 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1116 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1117 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1118 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1127 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1128 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1135 "fgl.yacc"
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
#line 1146 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1150 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1151 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1155 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1161 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1163 "fgl.yacc"
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
#line 1174 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1176 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1178 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1180 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1184 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1186 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1247 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1251 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1255 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1262 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1265 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1269 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1273 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1280 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1286 "fgl.yacc"
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
#line 1295 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1299 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1304 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1308 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1316 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1320 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1324 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1326 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1332 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1337 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1340 "fgl.yacc"
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
#line 1356 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1363 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1367 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1371 "fgl.yacc"
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
#line 1393 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1393 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1397 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1398 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1399 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1404 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1407 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1413 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1416 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1425 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1429 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1435 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1438 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1453 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1463 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1469 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1478 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1491 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1494 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1496 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1502 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1504 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1509 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1514 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1520 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1524 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1539 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1542 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1545 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1548 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1551 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1554 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1576 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1585 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1595 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 138:
#line 1609 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 139:
#line 1614 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 140:
#line 1617 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 141:
#line 1626 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 142:
#line 1632 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 147:
#line 1647 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 148:
#line 1651 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 149:
#line 1656 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 152:
#line 1666 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 153:
#line 1666 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 154:
#line 1667 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 155:
#line 1667 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 156:
#line 1668 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 157:
#line 1668 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 158:
#line 1669 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 159:
#line 1669 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 160:
#line 1670 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 161:
#line 1670 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 162:
#line 1678 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1682 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1688 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1692 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 166:
#line 1707 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 167:
#line 1710 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 168:
#line 1713 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 169:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 170:
#line 1719 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 171:
#line 1722 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 172:
#line 1731 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 173:
#line 1739 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1744 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 175:
#line 1757 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 176:
#line 1761 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 177:
#line 1776 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 178:
#line 1777 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 181:
#line 1785 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 182:
#line 1785 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 187:
#line 1794 "fgl.yacc"
    {in_define=1;}
    break;

  case 188:
#line 1794 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 189:
#line 1803 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1804 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 191:
#line 1805 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1808 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 194:
#line 1813 "fgl.yacc"
    { }
    break;

  case 195:
#line 1813 "fgl.yacc"
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
#line 1830 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 200:
#line 1834 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 205:
#line 1849 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1850 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 207:
#line 1851 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 208:
#line 1852 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 209:
#line 1857 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 211:
#line 1863 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 213:
#line 1872 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 214:
#line 1876 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 220:
#line 1892 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 221:
#line 1894 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 222:
#line 1895 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 224:
#line 1902 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 225:
#line 1902 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 226:
#line 1903 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 227:
#line 1904 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 228:
#line 1907 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 229:
#line 1909 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 231:
#line 1919 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 236:
#line 1934 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 237:
#line 1934 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 241:
#line 1940 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1941 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 243:
#line 1942 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1943 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 245:
#line 1944 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 246:
#line 1945 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 247:
#line 1946 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 248:
#line 1947 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 249:
#line 1948 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 250:
#line 1949 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 251:
#line 1952 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 252:
#line 1953 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1954 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 254:
#line 1955 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 255:
#line 1959 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1964 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 257:
#line 1969 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1973 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1976 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 260:
#line 1980 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 262:
#line 1981 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 264:
#line 1982 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 266:
#line 1983 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 267:
#line 1984 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1985 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 269:
#line 1986 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1987 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 271:
#line 1988 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 272:
#line 1991 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 273:
#line 1992 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 274:
#line 1993 "fgl.yacc"
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
#line 2028 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 278:
#line 2032 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2034 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 280:
#line 2036 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 281:
#line 2038 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 282:
#line 2043 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 283:
#line 2047 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 284:
#line 2047 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 285:
#line 2051 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 286:
#line 2052 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 287:
#line 2053 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 288:
#line 2054 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 289:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 290:
#line 2056 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 291:
#line 2058 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 292:
#line 2063 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 293:
#line 2063 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 294:
#line 2066 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 295:
#line 2068 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 296:
#line 2074 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 297:
#line 2076 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 298:
#line 2082 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 299:
#line 2090 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 300:
#line 2090 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 301:
#line 2093 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 302:
#line 2094 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 303:
#line 2095 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 304:
#line 2096 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 305:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 306:
#line 2098 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 307:
#line 2100 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 311:
#line 2121 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 315:
#line 2130 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 316:
#line 2132 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 317:
#line 2134 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 318:
#line 2136 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 319:
#line 2137 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 320:
#line 2138 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 321:
#line 2139 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 322:
#line 2140 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2145 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2152 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 325:
#line 2157 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2159 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2161 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 328:
#line 2162 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 329:
#line 2163 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 330:
#line 2164 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 331:
#line 2165 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 332:
#line 2166 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 333:
#line 2167 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 334:
#line 2170 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 335:
#line 2172 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 336:
#line 2178 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 337:
#line 2186 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2194 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 340:
#line 2198 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 341:
#line 2206 "fgl.yacc"
    {dim_push_record();}
    break;

  case 342:
#line 2207 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 343:
#line 2208 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 344:
#line 2209 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 350:
#line 2228 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 351:
#line 2240 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 352:
#line 2244 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 353:
#line 2247 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 354:
#line 2250 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 355:
#line 2251 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 356:
#line 2252 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 357:
#line 2253 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 358:
#line 2254 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 359:
#line 2260 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 360:
#line 2267 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 361:
#line 2272 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 362:
#line 2277 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 363:
#line 2282 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 364:
#line 2286 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 365:
#line 2295 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 366:
#line 2297 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 367:
#line 2302 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 373:
#line 2314 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 374:
#line 2318 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 375:
#line 2321 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 376:
#line 2325 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 377:
#line 2328 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 378:
#line 2332 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 379:
#line 2339 "fgl.yacc"
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
#line 2357 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 381:
#line 2363 "fgl.yacc"
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
#line 2387 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 383:
#line 2390 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 384:
#line 2405 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 385:
#line 2407 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 386:
#line 2409 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 387:
#line 2411 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 388:
#line 2413 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 389:
#line 2415 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 390:
#line 2416 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 391:
#line 2423 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 392:
#line 2425 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 393:
#line 2429 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 394:
#line 2431 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 395:
#line 2433 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 396:
#line 2435 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 397:
#line 2437 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 398:
#line 2439 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 399:
#line 2441 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 400:
#line 2447 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 401:
#line 2461 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 402:
#line 2464 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 407:
#line 2481 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 410:
#line 2487 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 411:
#line 2491 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 412:
#line 2496 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 416:
#line 2506 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 417:
#line 2507 "fgl.yacc"
    {inc_counter();}
    break;

  case 423:
#line 2513 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 424:
#line 2520 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 425:
#line 2520 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 427:
#line 2525 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 428:
#line 2529 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2535 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2543 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 431:
#line 2549 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 432:
#line 2558 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 433:
#line 2560 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 434:
#line 2567 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 435:
#line 2575 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 436:
#line 2579 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 437:
#line 2588 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 438:
#line 2593 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 439:
#line 2598 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 440:
#line 2602 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 441:
#line 2604 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 442:
#line 2607 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 443:
#line 2614 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 444:
#line 2622 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2634 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 446:
#line 2640 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 447:
#line 2646 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 450:
#line 2656 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 451:
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

  case 452:
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

  case 453:
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

  case 454:
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

  case 455:
#line 2761 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 456:
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

  case 457:
#line 2777 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 458:
#line 2781 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 459:
#line 2787 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 460:
#line 2790 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 461:
#line 2798 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 462:
#line 2802 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 463:
#line 2805 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 464:
#line 2811 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 465:
#line 2821 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 466:
#line 2826 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 467:
#line 2833 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 468:
#line 2836 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 469:
#line 2839 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 470:
#line 2844 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 471:
#line 2851 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 472:
#line 2856 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 473:
#line 2861 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 474:
#line 2866 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 475:
#line 2877 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 476:
#line 2885 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 477:
#line 2893 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 478:
#line 2898 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 479:
#line 2902 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 480:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 481:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 482:
#line 2915 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 483:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 484:
#line 2924 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 485:
#line 2928 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 486:
#line 2932 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 487:
#line 2936 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 488:
#line 2940 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 489:
#line 2944 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 490:
#line 2951 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 491:
#line 2961 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 492:
#line 2966 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 493:
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

  case 494:
#line 2982 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 495:
#line 2987 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 496:
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

  case 497:
#line 3004 "fgl.yacc"
    {chk4var=1;}
    break;

  case 498:
#line 3004 "fgl.yacc"
    {chk4var=0;}
    break;

  case 499:
#line 3004 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 500:
#line 3007 "fgl.yacc"
    {chk4var=1;}
    break;

  case 501:
#line 3007 "fgl.yacc"
    {chk4var=0;}
    break;

  case 502:
#line 3007 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 503:
#line 3011 "fgl.yacc"
    {chk4var=1;}
    break;

  case 504:
#line 3011 "fgl.yacc"
    {chk4var=0;}
    break;

  case 505:
#line 3011 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 506:
#line 3015 "fgl.yacc"
    {chk4var=1;}
    break;

  case 507:
#line 3015 "fgl.yacc"
    {chk4var=0;}
    break;

  case 508:
#line 3015 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 509:
#line 3019 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3025 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3031 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3037 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3043 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3049 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 515:
#line 3058 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 516:
#line 3064 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 517:
#line 3074 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 518:
#line 3075 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 521:
#line 3083 "fgl.yacc"
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
#line 3094 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 523:
#line 3095 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 524:
#line 3101 "fgl.yacc"
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
#line 3112 "fgl.yacc"
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
#line 3122 "fgl.yacc"
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
#line 3135 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 530:
#line 3140 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 531:
#line 3147 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 532:
#line 3151 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 533:
#line 3154 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 534:
#line 3157 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 535:
#line 3163 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 536:
#line 3166 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 537:
#line 3169 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 538:
#line 3186 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 539:
#line 3189 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 540:
#line 3195 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 541:
#line 3196 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 542:
#line 3197 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 544:
#line 3202 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 545:
#line 3203 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 546:
#line 3204 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 547:
#line 3205 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3207 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 549:
#line 3208 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 550:
#line 3209 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 551:
#line 3211 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 552:
#line 3212 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 554:
#line 3218 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 555:
#line 3222 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 556:
#line 3226 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 557:
#line 3231 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 558:
#line 3235 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 559:
#line 3250 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 560:
#line 3254 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 561:
#line 3255 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 562:
#line 3262 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 564:
#line 3279 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 565:
#line 3283 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 566:
#line 3289 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 567:
#line 3293 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 568:
#line 3302 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 569:
#line 3303 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 570:
#line 3315 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 571:
#line 3321 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 572:
#line 3329 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 579:
#line 3346 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 580:
#line 3348 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 581:
#line 3351 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 582:
#line 3353 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 587:
#line 3367 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 588:
#line 3369 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 589:
#line 3372 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 590:
#line 3374 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 603:
#line 3405 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 604:
#line 3407 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 605:
#line 3410 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 606:
#line 3412 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 607:
#line 3415 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 608:
#line 3417 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 609:
#line 3420 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 610:
#line 3422 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 611:
#line 3425 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 612:
#line 3427 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 613:
#line 3442 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 614:
#line 3458 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 615:
#line 3459 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 616:
#line 3460 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 617:
#line 3461 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 618:
#line 3462 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 619:
#line 3463 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 620:
#line 3464 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 624:
#line 3472 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 626:
#line 3478 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 627:
#line 3481 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 628:
#line 3486 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 629:
#line 3491 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 630:
#line 3494 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 631:
#line 3499 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 632:
#line 3504 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 633:
#line 3509 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 634:
#line 3516 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 635:
#line 3517 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 636:
#line 3524 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 637:
#line 3531 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 638:
#line 3533 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 639:
#line 3539 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 640:
#line 3544 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 641:
#line 3549 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 642:
#line 3554 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 643:
#line 3554 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 644:
#line 3557 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 645:
#line 3563 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 646:
#line 3568 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 647:
#line 3572 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 650:
#line 3580 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 651:
#line 3583 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 652:
#line 3586 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 653:
#line 3591 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 654:
#line 3596 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 655:
#line 3601 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 656:
#line 3608 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 658:
#line 3617 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 659:
#line 3679 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 661:
#line 3688 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 662:
#line 3697 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 664:
#line 3704 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 665:
#line 3707 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 666:
#line 3713 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 667:
#line 3719 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 668:
#line 3723 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 669:
#line 3727 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 670:
#line 3733 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 671:
#line 3737 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 672:
#line 3741 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 673:
#line 3746 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 674:
#line 3751 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 693:
#line 3792 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 694:
#line 3799 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 695:
#line 3801 "fgl.yacc"
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
#line 3820 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 699:
#line 3823 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 700:
#line 3825 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 701:
#line 3828 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 702:
#line 3832 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 703:
#line 3835 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 704:
#line 3841 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 705:
#line 3852 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 706:
#line 3853 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 707:
#line 3856 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 709:
#line 3862 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 710:
#line 3866 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 711:
#line 3867 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 712:
#line 3871 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 716:
#line 3886 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 717:
#line 3888 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 720:
#line 3897 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 721:
#line 3900 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 722:
#line 3904 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 723:
#line 3907 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 724:
#line 3910 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 725:
#line 3913 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 726:
#line 3916 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 727:
#line 3920 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 728:
#line 3923 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 729:
#line 3926 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 730:
#line 3929 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 731:
#line 3932 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 732:
#line 3935 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 733:
#line 3938 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 734:
#line 3941 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 735:
#line 3944 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 736:
#line 3945 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 737:
#line 3945 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 738:
#line 3946 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 739:
#line 3946 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 740:
#line 3947 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 741:
#line 3947 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 742:
#line 3948 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 743:
#line 3951 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 744:
#line 3952 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 745:
#line 3955 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 746:
#line 3963 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 747:
#line 3967 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 748:
#line 3973 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 749:
#line 3977 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 750:
#line 3982 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 751:
#line 3987 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 752:
#line 3992 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 753:
#line 3993 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 754:
#line 3994 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 755:
#line 3998 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 756:
#line 4002 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 757:
#line 4011 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 758:
#line 4016 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 759:
#line 4020 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 760:
#line 4027 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 761:
#line 4036 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 762:
#line 4042 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 763:
#line 4043 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 764:
#line 4044 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 765:
#line 4045 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 766:
#line 4048 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 768:
#line 4051 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 769:
#line 4058 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 770:
#line 4059 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 771:
#line 4060 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 772:
#line 4061 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 773:
#line 4062 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 774:
#line 4063 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 775:
#line 4064 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 776:
#line 4065 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 777:
#line 4066 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 778:
#line 4071 "fgl.yacc"
    {iskey=1;}
    break;

  case 779:
#line 4071 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 780:
#line 4073 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 781:
#line 4076 "fgl.yacc"
    {iskey=1;}
    break;

  case 782:
#line 4076 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 783:
#line 4078 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 784:
#line 4082 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 785:
#line 4085 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 786:
#line 4086 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 788:
#line 4089 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 794:
#line 4101 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 795:
#line 4102 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 796:
#line 4103 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 797:
#line 4104 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 798:
#line 4105 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 799:
#line 4106 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 800:
#line 4107 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 801:
#line 4108 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 802:
#line 4109 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 803:
#line 4110 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 804:
#line 4111 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 805:
#line 4112 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 806:
#line 4113 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 807:
#line 4114 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 808:
#line 4118 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 809:
#line 4136 "fgl.yacc"
    {chk4var=1;}
    break;

  case 810:
#line 4136 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 811:
#line 4139 "fgl.yacc"
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
#line 4163 "fgl.yacc"
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
#line 4181 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 815:
#line 4187 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 816:
#line 4193 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 817:
#line 4199 "fgl.yacc"
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
#line 4211 "fgl.yacc"
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
#line 4236 "fgl.yacc"
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
#line 4252 "fgl.yacc"
    {
	}
    break;

  case 831:
#line 4277 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 835:
#line 4285 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 851:
#line 4311 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 852:
#line 4312 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 853:
#line 4320 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 854:
#line 4325 "fgl.yacc"
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
#line 4341 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 856:
#line 4347 "fgl.yacc"
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
#line 4362 "fgl.yacc"
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
#line 4375 "fgl.yacc"
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
#line 4385 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 861:
#line 4392 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 862:
#line 4399 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 863:
#line 4405 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 864:
#line 4405 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 865:
#line 4410 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 866:
#line 4416 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 867:
#line 4424 "fgl.yacc"
    {
}
    break;

  case 871:
#line 4436 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 873:
#line 4444 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 874:
#line 4450 "fgl.yacc"
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
#line 4466 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 878:
#line 4470 "fgl.yacc"
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
#line 4483 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 881:
#line 4501 "fgl.yacc"
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
#line 4509 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 883:
#line 4515 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 884:
#line 4526 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 885:
#line 4530 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 886:
#line 4537 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 887:
#line 4544 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 888:
#line 4550 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 889:
#line 4555 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 892:
#line 4562 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 893:
#line 4563 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 894:
#line 4565 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 895:
#line 4566 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4569 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 897:
#line 4570 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 898:
#line 4571 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 899:
#line 4573 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 900:
#line 4578 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 901:
#line 4583 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 902:
#line 4590 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 906:
#line 4597 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 907:
#line 4599 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 908:
#line 4601 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 909:
#line 4609 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 910:
#line 4615 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 911:
#line 4619 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 914:
#line 4631 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 915:
#line 4634 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 916:
#line 4638 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 917:
#line 4641 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 919:
#line 4650 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 920:
#line 4653 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 921:
#line 4656 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 928:
#line 4672 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 929:
#line 4677 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 930:
#line 4677 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 931:
#line 4680 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 932:
#line 4708 "fgl.yacc"
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
#line 4765 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 936:
#line 4772 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 937:
#line 4776 "fgl.yacc"
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
#line 4819 "fgl.yacc"
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
#line 4867 "fgl.yacc"
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
#line 4881 "fgl.yacc"
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
#line 4905 "fgl.yacc"
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
#line 4965 "fgl.yacc"
    {
  int type,arrsize,size,level;
  //char buff2[256];
  char arrbuff[256];
//printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
	sprintf(yyval.str,"%s[%s]",yyvsp[-1].str,yyvsp[0].str);
  } else {


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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.3*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.4*/", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
  }
}

  mcnt++;
}
    break;

  case 950:
#line 5021 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 951:
#line 5026 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 952:
#line 5034 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 953:
#line 5039 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 954:
#line 5047 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 955:
#line 5053 "fgl.yacc"
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

  case 956:
#line 5085 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 957:
#line 5088 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 958:
#line 5090 "fgl.yacc"
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

  case 959:
#line 5131 "fgl.yacc"
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

  case 964:
#line 5184 "fgl.yacc"
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

  case 965:
#line 5236 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 967:
#line 5243 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 968:
#line 5249 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 969:
#line 5260 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 5267 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 972:
#line 5275 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 973:
#line 5278 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 974:
#line 5279 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 976:
#line 5281 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 977:
#line 5282 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 978:
#line 5285 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 979:
#line 5288 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 980:
#line 5294 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 981:
#line 5297 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 982:
#line 5301 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 983:
#line 5306 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 984:
#line 5314 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 985:
#line 5319 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 986:
#line 5326 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 987:
#line 5329 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 992:
#line 5342 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  A4GL_lex_printcomment("/*..array_r_varid..*/");

//printf("Got array %s %s\n",$<str>1,$<str>3);
if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
	// Its a variable
	//printf("gvd = true\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
	// Its an sql identifier or similar
	//printf("gvd = false\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
//printf("All done - ARRAY (array_r_varid) : %s\n",$<str>$);
}
    break;

  case 993:
#line 5361 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 994:
#line 5368 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 995:
#line 5375 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 996:
#line 5378 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 997:
#line 5392 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1002:
#line 5409 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1003:
#line 5414 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1004:
#line 5420 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1006:
#line 5427 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1007:
#line 5432 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5435 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1009:
#line 5436 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1010:
#line 5439 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1011:
#line 5440 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1012:
#line 5443 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1013:
#line 5444 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1014:
#line 5449 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1015:
#line 5456 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1016:
#line 5459 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1017:
#line 5465 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1018:
#line 5467 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1019:
#line 5469 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1020:
#line 5471 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1021:
#line 5474 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1022:
#line 5474 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1023:
#line 5475 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1024:
#line 5480 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1025:
#line 5488 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1026:
#line 5489 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1027:
#line 5494 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1028:
#line 5496 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1029:
#line 5498 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1033:
#line 5516 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1034:
#line 5517 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1035:
#line 5518 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1036:
#line 5519 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1037:
#line 5520 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1038:
#line 5521 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1039:
#line 5522 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1040:
#line 5523 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1041:
#line 5524 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1042:
#line 5525 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1043:
#line 5526 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1044:
#line 5527 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1045:
#line 5528 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1046:
#line 5529 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1047:
#line 5530 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1048:
#line 5531 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1049:
#line 5532 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1050:
#line 5533 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1051:
#line 5534 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1052:
#line 5535 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1053:
#line 5536 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1054:
#line 5537 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1055:
#line 5538 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1056:
#line 5539 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1057:
#line 5540 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1058:
#line 5541 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1059:
#line 5556 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1062:
#line 5565 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1063:
#line 5569 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1064:
#line 5573 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1065:
#line 5577 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1066:
#line 5581 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1068:
#line 5601 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1069:
#line 5606 "fgl.yacc"
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

  case 1070:
#line 5619 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1071:
#line 5620 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1072:
#line 5624 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1073:
#line 5629 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1074:
#line 5630 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1075:
#line 5634 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1079:
#line 5640 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1080:
#line 5643 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1082:
#line 5658 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1083:
#line 5662 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1084:
#line 5668 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1085:
#line 5669 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1086:
#line 5674 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1087:
#line 5675 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1088:
#line 5678 "fgl.yacc"
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

  case 1090:
#line 5705 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
			}
    break;

  case 1091:
#line 5709 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1092:
#line 5713 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1093:
#line 5717 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[0].str);
			}
    break;

  case 1099:
#line 5735 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1100:
#line 5741 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1101:
#line 5749 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1102:
#line 5755 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1103:
#line 5757 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1107:
#line 5767 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1108:
#line 5767 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1109:
#line 5772 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1110:
#line 5776 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1111:
#line 5781 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1112:
#line 5781 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1113:
#line 5785 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1114:
#line 5785 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1115:
#line 5786 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1116:
#line 5786 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1117:
#line 5787 "fgl.yacc"
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

  case 1118:
#line 5800 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1119:
#line 5801 "fgl.yacc"
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

  case 1120:
#line 5817 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1127:
#line 5829 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1128:
#line 5829 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1129:
#line 5835 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1130:
#line 5835 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1131:
#line 5838 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1132:
#line 5838 "fgl.yacc"
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

  case 1133:
#line 5854 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1134:
#line 5855 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1135:
#line 5856 "fgl.yacc"
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

  case 1136:
#line 5865 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1137:
#line 5877 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1143:
#line 5888 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1144:
#line 5893 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1145:
#line 5893 "fgl.yacc"
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

  case 1146:
#line 5914 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1147:
#line 5919 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1148:
#line 5925 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1149:
#line 5926 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1150:
#line 5927 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1151:
#line 5931 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1152:
#line 5932 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1153:
#line 5933 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1154:
#line 5934 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1155:
#line 5938 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1156:
#line 5948 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1157:
#line 5950 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1158:
#line 5955 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1159:
#line 5958 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1160:
#line 5963 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1161:
#line 5970 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1162:
#line 5977 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1163:
#line 5984 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1164:
#line 5993 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1165:
#line 6000 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1166:
#line 6007 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1167:
#line 6014 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1168:
#line 6021 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1173:
#line 6034 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1174:
#line 6035 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1175:
#line 6036 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1176:
#line 6037 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1177:
#line 6038 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1178:
#line 6039 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1179:
#line 6040 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1180:
#line 6041 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1181:
#line 6042 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1182:
#line 6043 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1185:
#line 6049 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1186:
#line 6050 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1187:
#line 6051 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1188:
#line 6052 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1193:
#line 6061 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1194:
#line 6062 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1195:
#line 6063 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1196:
#line 6064 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1197:
#line 6065 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1198:
#line 6066 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1199:
#line 6067 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1200:
#line 6068 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1201:
#line 6070 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1202:
#line 6071 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1203:
#line 6072 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1204:
#line 6073 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1205:
#line 6075 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1206:
#line 6076 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1207:
#line 6077 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1208:
#line 6078 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1212:
#line 6083 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1213:
#line 6084 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1217:
#line 6091 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1218:
#line 6099 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1219:
#line 6107 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1220:
#line 6119 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1221:
#line 6128 "fgl.yacc"
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

  case 1222:
#line 6139 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1223:
#line 6143 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1224:
#line 6147 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1225:
#line 6153 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1226:
#line 6158 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1227:
#line 6166 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1228:
#line 6169 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1229:
#line 6178 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1230:
#line 6189 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1232:
#line 6196 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1233:
#line 6204 "fgl.yacc"
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

  case 1234:
#line 6214 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1235:
#line 6217 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1236:
#line 6221 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1237:
#line 6229 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1238:
#line 6232 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1239:
#line 6238 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1240:
#line 6242 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1241:
#line 6246 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1242:
#line 6250 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1243:
#line 6254 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1244:
#line 6260 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1245:
#line 6261 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1246:
#line 6262 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1247:
#line 6263 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1248:
#line 6268 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1249:
#line 6270 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1250:
#line 6273 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1251:
#line 6277 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1252:
#line 6280 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1253:
#line 6287 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1254:
#line 6292 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1255:
#line 6293 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1256:
#line 6294 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1257:
#line 6295 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1258:
#line 6300 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1259:
#line 6301 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1260:
#line 6307 "fgl.yacc"
    {insql=1;}
    break;

  case 1261:
#line 6307 "fgl.yacc"
    {insql=0;}
    break;

  case 1262:
#line 6307 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1263:
#line 6312 "fgl.yacc"
    {insql=1;}
    break;

  case 1264:
#line 6312 "fgl.yacc"
    {insql=0;}
    break;

  case 1265:
#line 6312 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1266:
#line 6320 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1267:
#line 6321 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1269:
#line 6326 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1270:
#line 6331 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1271:
#line 6332 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1272:
#line 6333 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1273:
#line 6334 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1274:
#line 6335 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1276:
#line 6340 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1277:
#line 6340 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1279:
#line 6344 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1280:
#line 6348 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1281:
#line 6349 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1282:
#line 6352 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1283:
#line 6353 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1284:
#line 6356 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1285:
#line 6359 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1286:
#line 6362 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1287:
#line 6368 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6370 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1290:
#line 6383 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6387 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1292:
#line 6388 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1294:
#line 6393 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6396 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1296:
#line 6402 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1297:
#line 6405 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1298:
#line 6413 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6420 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1301:
#line 6424 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1302:
#line 6428 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1303:
#line 6434 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1304:
#line 6437 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1305:
#line 6446 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1306:
#line 6449 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1307:
#line 6452 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1308:
#line 6455 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1309:
#line 6458 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1310:
#line 6461 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1311:
#line 6464 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1312:
#line 6471 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1313:
#line 6474 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1314:
#line 6481 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6484 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1316:
#line 6490 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1317:
#line 6493 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1318:
#line 6500 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1319:
#line 6503 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1321:
#line 6511 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1323:
#line 6520 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1324:
#line 6523 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1325:
#line 6529 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1326:
#line 6532 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1327:
#line 6538 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1328:
#line 6545 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1329:
#line 6546 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1330:
#line 6550 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1331:
#line 6560 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1332:
#line 6563 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1333:
#line 6569 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1334:
#line 6571 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1335:
#line 6576 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1336:
#line 6577 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1337:
#line 6582 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1338:
#line 6583 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1339:
#line 6589 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1340:
#line 6590 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6617 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1350:
#line 6623 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1351:
#line 6626 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1352:
#line 6629 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1353:
#line 6635 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1355:
#line 6641 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1357:
#line 6652 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1358:
#line 6666 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1359:
#line 6675 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1360:
#line 6675 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1361:
#line 6680 "fgl.yacc"
    {insql=1;}
    break;

  case 1362:
#line 6680 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1363:
#line 6685 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1364:
#line 6688 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1365:
#line 6690 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1367:
#line 6697 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1368:
#line 6701 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1369:
#line 6705 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1370:
#line 6712 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1371:
#line 6715 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1372:
#line 6722 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1373:
#line 6726 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1374:
#line 6732 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1375:
#line 6737 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1376:
#line 6741 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1377:
#line 6747 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1378:
#line 6750 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1379:
#line 6756 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1380:
#line 6763 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1381:
#line 6767 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1382:
#line 6772 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1383:
#line 6782 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1384:
#line 6785 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1385:
#line 6787 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1386:
#line 6789 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1387:
#line 6791 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1388:
#line 6793 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1389:
#line 6795 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1390:
#line 6797 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1391:
#line 6803 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1392:
#line 6813 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1393:
#line 6820 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6826 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6829 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6836 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1402:
#line 6841 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1403:
#line 6846 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1404:
#line 6853 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1405:
#line 6854 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1406:
#line 6861 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1407:
#line 6872 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1408:
#line 6873 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6874 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1410:
#line 6877 "fgl.yacc"
    {insql=1;}
    break;

  case 1411:
#line 6877 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1412:
#line 6882 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1413:
#line 6887 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1415:
#line 6893 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1417:
#line 6897 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1418:
#line 6902 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1419:
#line 6907 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1420:
#line 6911 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1422:
#line 6917 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1423:
#line 6921 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1424:
#line 6928 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6929 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6930 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6931 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 6941 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1432:
#line 6942 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1433:
#line 6943 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6947 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1435:
#line 6948 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1438:
#line 6955 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 6958 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 6961 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 6966 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1446:
#line 6968 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1448:
#line 6974 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 6980 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1453:
#line 6990 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1454:
#line 6995 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 6997 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 7003 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1458:
#line 7006 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1460:
#line 7012 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1461:
#line 7020 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7035 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7041 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7046 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7047 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7049 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1472:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7060 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1474:
#line 7063 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1475:
#line 7066 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1476:
#line 7073 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7074 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1478:
#line 7075 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1479:
#line 7077 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1480:
#line 7090 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 7095 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1483:
#line 7099 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1484:
#line 7101 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1485:
#line 7108 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1486:
#line 7111 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1487:
#line 7117 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1488:
#line 7125 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1489:
#line 7129 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1490:
#line 7133 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1491:
#line 7137 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1492:
#line 7141 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1493:
#line 7144 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1494:
#line 7147 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1495:
#line 7155 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1496:
#line 7162 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1499:
#line 7171 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1500:
#line 7177 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1501:
#line 7180 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1502:
#line 7191 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 7198 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1504:
#line 7204 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1505:
#line 7207 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1506:
#line 7214 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1507:
#line 7221 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1509:
#line 7228 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1510:
#line 7234 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1511:
#line 7235 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7236 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1514:
#line 7240 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7245 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1517:
#line 7252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7257 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1519:
#line 7258 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1520:
#line 7261 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1521:
#line 7264 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1522:
#line 7269 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1523:
#line 7270 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1524:
#line 7275 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1525:
#line 7278 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1526:
#line 7284 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1527:
#line 7287 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1528:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1529:
#line 7296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1530:
#line 7302 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1531:
#line 7305 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1532:
#line 7312 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1533:
#line 7313 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1534:
#line 7342 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1535:
#line 7344 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1536:
#line 7348 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1538:
#line 7361 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1539:
#line 7364 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1540:
#line 7367 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1541:
#line 7370 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7378 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1544:
#line 7381 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1546:
#line 7387 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1548:
#line 7393 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1549:
#line 7396 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1550:
#line 7399 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1551:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1552:
#line 7405 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1553:
#line 7408 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1554:
#line 7411 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1555:
#line 7414 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1556:
#line 7419 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1558:
#line 7426 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1564:
#line 7434 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1565:
#line 7435 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1566:
#line 7440 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1567:
#line 7443 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1568:
#line 7447 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1569:
#line 7453 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1570:
#line 7454 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1571:
#line 7455 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1572:
#line 7456 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1577:
#line 7476 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 7480 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1580:
#line 7481 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1582:
#line 7484 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1583:
#line 7486 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1591:
#line 7495 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1592:
#line 7497 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1593:
#line 7499 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1595:
#line 7502 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1597:
#line 7505 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1601:
#line 7510 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1602:
#line 7512 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1603:
#line 7515 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1604:
#line 7516 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1605:
#line 7523 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7528 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1613:
#line 7544 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1614:
#line 7551 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1615:
#line 7555 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1616:
#line 7556 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1617:
#line 7557 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1618:
#line 7565 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1619:
#line 7566 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1620:
#line 7567 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1621:
#line 7578 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1622:
#line 7585 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1623:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1624:
#line 7591 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1625:
#line 7592 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1626:
#line 7600 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1627:
#line 7601 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1628:
#line 7602 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1630:
#line 7628 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1631:
#line 7629 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1632:
#line 7630 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1633:
#line 7634 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1634:
#line 7637 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1635:
#line 7643 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1636:
#line 7648 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1637:
#line 7653 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1639:
#line 7664 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1643:
#line 7682 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1644:
#line 7685 "fgl.yacc"
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

  case 1645:
#line 7698 "fgl.yacc"
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

  case 1646:
#line 7713 "fgl.yacc"
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

  case 1647:
#line 7725 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1648:
#line 7727 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1649:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1650:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1651:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1652:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1653:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1654:
#line 7730 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1655:
#line 7731 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1656:
#line 7734 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1657:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1658:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1659:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1660:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1661:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1662:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1663:
#line 7741 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1664:
#line 7744 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1679:
#line 7751 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1680:
#line 7754 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1681:
#line 7755 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7756 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1683:
#line 7760 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1684:
#line 7768 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1685:
#line 7768 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1686:
#line 7774 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1687:
#line 7774 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1688:
#line 7781 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1689:
#line 7781 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1690:
#line 7787 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1691:
#line 7787 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1692:
#line 7795 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1693:
#line 7796 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1694:
#line 7797 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1695:
#line 7800 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1696:
#line 7800 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1698:
#line 7804 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1699:
#line 7805 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1700:
#line 7816 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1701:
#line 7819 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1702:
#line 7825 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1703:
#line 7830 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1704:
#line 7838 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1705:
#line 7850 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1706:
#line 7851 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1707:
#line 7854 "fgl.yacc"
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

  case 1708:
#line 7869 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1709:
#line 7880 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1710:
#line 7883 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1711:
#line 7891 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1712:
#line 7900 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1713:
#line 7903 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1714:
#line 7907 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1715:
#line 7910 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1716:
#line 7911 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1718:
#line 7920 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1719:
#line 7921 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1720:
#line 7930 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1721:
#line 7939 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1722:
#line 7944 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1723:
#line 7945 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1724:
#line 7946 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1725:
#line 7947 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1726:
#line 7954 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1727:
#line 7957 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1728:
#line 7963 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1729:
#line 7966 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1730:
#line 7976 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1731:
#line 7985 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1732:
#line 7988 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1733:
#line 7991 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1734:
#line 7997 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1735:
#line 8003 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1736:
#line 8006 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1737:
#line 8007 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1738:
#line 8008 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1739:
#line 8009 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1740:
#line 8010 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1741:
#line 8013 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1742:
#line 8020 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1743:
#line 8022 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1744:
#line 8024 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1745:
#line 8026 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1746:
#line 8028 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1747:
#line 8029 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1748:
#line 8030 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1749:
#line 8031 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1750:
#line 8032 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1751:
#line 8033 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1752:
#line 8034 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1753:
#line 8036 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1754:
#line 8038 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1755:
#line 8040 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1756:
#line 8042 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1757:
#line 8044 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1758:
#line 8046 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1759:
#line 8048 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1760:
#line 8049 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1761:
#line 8051 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1762:
#line 8052 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1763:
#line 8053 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1764:
#line 8059 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1765:
#line 8060 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1767:
#line 8070 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1768:
#line 8078 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1769:
#line 8082 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1770:
#line 8089 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1771:
#line 8089 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1773:
#line 8093 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1774:
#line 8098 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1775:
#line 8098 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1777:
#line 8102 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1778:
#line 8106 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1781:
#line 8115 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1782:
#line 8115 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1787:
#line 8134 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1788:
#line 8135 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1791:
#line 8143 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1792:
#line 8149 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1795:
#line 8168 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1796:
#line 8169 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1797:
#line 8170 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1798:
#line 8171 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1799:
#line 8172 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1800:
#line 8173 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1801:
#line 8177 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1802:
#line 8178 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1803:
#line 8179 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1805:
#line 8184 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1806:
#line 8185 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1807:
#line 8189 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME (\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1808:
#line 8190 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s)",yyvsp[-1].str);}
    break;

  case 1809:
#line 8191 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1810:
#line 8192 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1811:
#line 8193 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1812:
#line 8194 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1813:
#line 8195 "fgl.yacc"
    {sprintf(yyval.str,
		"DATETIME(%s-%s-%s %s:%s:%s)",yyvsp[-10].str,yyvsp[-8].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1814:
#line 8197 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s %s:%s)",yyvsp[-8].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1815:
#line 8201 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1816:
#line 8202 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1817:
#line 8203 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1818:
#line 8207 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1819:
#line 8208 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s)",yyvsp[-1].str);}
    break;

  case 1820:
#line 8209 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1821:
#line 8210 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1822:
#line 8211 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1823:
#line 8212 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1824:
#line 8215 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1825:
#line 8219 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1827:
#line 8228 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1829:
#line 8233 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1830:
#line 8234 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2147:
#line 8559 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2148:
#line 8559 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2149:
#line 8566 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2150:
#line 8566 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2151:
#line 8654 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2152:
#line 8658 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2153:
#line 8660 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2154:
#line 8667 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2155:
#line 8671 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2156:
#line 8677 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2157:
#line 8685 "fgl.yacc"
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
#line 8695 "fgl.yacc"
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
#line 8705 "fgl.yacc"
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
#line 8717 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2161:
#line 8720 "fgl.yacc"
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
#line 8739 "fgl.yacc"
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
#line 8765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2164:
#line 8768 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2166:
#line 8777 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2167:
#line 8782 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2168:
#line 8785 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2169:
#line 8793 "fgl.yacc"
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
#line 8801 "fgl.yacc"
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
#line 8814 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2172:
#line 8817 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2173:
#line 8825 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2174:
#line 8828 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2175:
#line 8831 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2176:
#line 8839 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2177:
#line 8843 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2178:
#line 8846 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2179:
#line 8849 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2180:
#line 8852 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2181:
#line 8856 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2182:
#line 8857 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2183:
#line 8858 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2184:
#line 8859 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2185:
#line 8860 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2186:
#line 8866 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2187:
#line 8867 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2188:
#line 8868 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2189:
#line 8869 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2190:
#line 8870 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2191:
#line 8871 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2192:
#line 8872 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2193:
#line 8873 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2194:
#line 8874 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2195:
#line 8875 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 8876 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 8877 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 8878 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 8879 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2200:
#line 8880 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2201:
#line 8881 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2202:
#line 8886 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2203:
#line 8892 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2204:
#line 8893 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2205:
#line 8901 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2206:
#line 8903 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2208:
#line 8909 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2209:
#line 8913 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2210:
#line 8917 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2211:
#line 8933 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		char buff[1024];
			sprintf(buff,"%s",fgl_add_scope(yyvsp[0].str,0));

		print_push_variable(buff);

		strcpy(yyval.str,"?");

	} else {
		strcpy(yyval.str,yyvsp[0].str);
	}

}
    break;

  case 2212:
#line 8952 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2213:
#line 8954 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2214:
#line 8960 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2215:
#line 8961 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2216:
#line 8962 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2217:
#line 8963 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2221:
#line 8981 "fgl.yacc"
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
#line 9007 "fgl.yacc"
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

  case 2223:
#line 9062 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2224:
#line 9076 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2225:
#line 9079 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2226:
#line 9083 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2227:
#line 9098 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2228:
#line 9098 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2229:
#line 9104 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2230:
#line 9105 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2231:
#line 9108 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2232:
#line 9109 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2233:
#line 9110 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2234:
#line 9111 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2235:
#line 9112 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2236:
#line 9113 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2237:
#line 9114 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2238:
#line 9125 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2239:
#line 9129 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2240:
#line 9133 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2241:
#line 9137 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2242:
#line 9142 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2243:
#line 9146 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2244:
#line 9151 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2246:
#line 9159 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2248:
#line 9165 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2249:
#line 9171 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2250:
#line 9175 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2255:
#line 9193 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2256:
#line 9200 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2257:
#line 9210 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2258:
#line 9210 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19101 "y.tab.c"

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


#line 992 "fgl.yacc"

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



