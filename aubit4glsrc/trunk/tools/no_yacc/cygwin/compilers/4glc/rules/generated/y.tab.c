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
#define YYLAST   10365

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  724
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  857
/* YYNRULES -- Number of rules. */
#define YYNRULES  2320
/* YYNRULES -- Number of states. */
#define YYNSTATES  3671

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
     289,   291,   295,   296,   303,   304,   310,   312,   315,   317,
     320,   322,   323,   324,   328,   329,   330,   334,   335,   340,
     341,   346,   349,   352,   355,   357,   360,   363,   367,   369,
     371,   373,   376,   378,   380,   383,   385,   387,   388,   389,
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
    1164,  1166,  1168,  1170,  1172,  1174,  1176,  1179,  1181,  1183,
    1185,  1188,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1211,  1214,  1216,  1219,  1221,  1223,  1225,  1229,
    1231,  1235,  1237,  1241,  1243,  1245,  1247,  1250,  1252,  1254,
    1258,  1263,  1268,  1271,  1274,  1276,  1278,  1280,  1282,  1284,
    1288,  1290,  1293,  1296,  1298,  1299,  1303,  1306,  1309,  1311,
    1315,  1320,  1325,  1331,  1337,  1339,  1341,  1344,  1347,  1352,
    1357,  1360,  1363,  1368,  1373,  1375,  1378,  1381,  1384,  1387,
    1390,  1393,  1396,  1399,  1402,  1405,  1408,  1411,  1414,  1417,
    1418,  1419,  1420,  1427,  1428,  1429,  1438,  1439,  1440,  1447,
    1448,  1449,  1456,  1457,  1458,  1465,  1466,  1467,  1474,  1480,
    1486,  1492,  1500,  1505,  1512,  1513,  1517,  1519,  1521,  1526,
    1531,  1536,  1541,  1546,  1551,  1553,  1555,  1557,  1559,  1564,
    1569,  1572,  1575,  1578,  1581,  1584,  1586,  1588,  1591,  1593,
    1595,  1597,  1600,  1605,  1612,  1619,  1623,  1629,  1635,  1639,
    1641,  1643,  1647,  1649,  1653,  1655,  1659,  1660,  1661,  1662,
    1672,  1673,  1677,  1678,  1679,  1690,  1691,  1693,  1694,  1696,
    1698,  1701,  1702,  1706,  1707,  1711,  1712,  1714,  1716,  1719,
    1720,  1724,  1725,  1729,  1733,  1735,  1740,  1744,  1746,  1750,
    1752,  1756,  1758,  1762,  1764,  1767,  1768,  1772,  1773,  1777,
    1778,  1783,  1784,  1789,  1790,  1795,  1796,  1797,  1809,  1810,
    1813,  1816,  1820,  1822,  1826,  1828,  1830,  1832,  1834,  1836,
    1838,  1840,  1844,  1846,  1848,  1853,  1860,  1865,  1869,  1876,
    1880,  1887,  1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,
    1904,  1907,  1909,  1911,  1913,  1918,  1920,  1922,  1924,  1929,
    1933,  1940,  1944,  1951,  1953,  1955,  1958,  1961,  1963,  1966,
    1969,  1971,  1975,  1977,  1980,  1983,  1986,  1991,  1994,  1997,
    2002,  2003,  2012,  2013,  2015,  2017,  2019,  2020,  2022,  2025,
    2026,  2028,  2031,  2032,  2034,  2037,  2038,  2040,  2044,  2045,
    2048,  2049,  2050,  2059,  2060,  2061,  2065,  2066,  2067,  2075,
    2081,  2084,  2087,  2088,  2094,  2099,  2101,  2105,  2109,  2113,
    2115,  2116,  2119,  2121,  2122,  2124,  2126,  2129,  2130,  2135,
    2136,  2141,  2142,  2146,  2147,  2151,  2152,  2156,  2157,  2161,
    2162,  2166,  2167,  2171,  2172,  2176,  2177,  2181,  2182,  2186,
    2187,  2191,  2192,  2196,  2198,  2202,  2204,  2208,  2211,  2216,
    2218,  2220,  2222,  2223,  2228,  2234,  2241,  2242,  2253,  2257,
    2260,  2263,  2265,  2267,  2268,  2271,  2273,  2276,  2280,  2284,
    2288,  2292,  2294,  2296,  2298,  2300,  2301,  2305,  2307,  2308,
    2312,  2315,  2318,  2320,  2324,  2326,  2330,  2332,  2334,  2336,
    2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,  2356,
    2358,  2360,  2362,  2364,  2366,  2368,  2370,  2371,  2372,  2380,
    2382,  2384,  2387,  2390,  2393,  2397,  2402,  2403,  2407,  2408,
    2410,  2412,  2415,  2417,  2419,  2421,  2423,  2425,  2427,  2428,
    2430,  2432,  2435,  2438,  2440,  2442,  2444,  2446,  2448,  2450,
    2452,  2454,  2456,  2458,  2460,  2462,  2463,  2465,  2467,  2469,
    2471,  2472,  2473,  2474,  2475,  2489,  2491,  2492,  2493,  2500,
    2503,  2505,  2508,  2511,  2514,  2516,  2518,  2521,  2523,  2524,
    2528,  2531,  2533,  2535,  2537,  2538,  2539,  2540,  2555,  2556,
    2557,  2565,  2567,  2570,  2571,  2575,  2576,  2581,  2582,  2588,
    2590,  2591,  2595,  2596,  2604,  2605,  2611,  2613,  2616,  2617,
    2619,  2621,  2623,  2624,  2626,  2628,  2631,  2634,  2637,  2639,
    2641,  2643,  2645,  2649,  2651,  2653,  2656,  2657,  2660,  2662,
    2664,  2666,  2668,  2670,  2672,  2674,  2678,  2679,  2681,  2683,
    2685,  2687,  2690,  2693,  2696,  2702,  2711,  2713,  2715,  2717,
    2722,  2727,  2729,  2731,  2733,  2735,  2738,  2741,  2745,  2752,
    2754,  2758,  2760,  2762,  2764,  2768,  2775,  2785,  2787,  2789,
    2791,  2793,  2796,  2797,  2799,  2801,  2805,  2807,  2811,  2813,
    2817,  2819,  2823,  2825,  2827,  2829,  2831,  2835,  2837,  2841,
    2843,  2847,  2849,  2851,  2853,  2857,  2860,  2861,  2863,  2865,
    2870,  2872,  2876,  2878,  2882,  2890,  2891,  2899,  2900,  2907,
    2911,  2913,  2917,  2919,  2922,  2928,  2929,  2937,  2938,  2941,
    2942,  2944,  2950,  2953,  2959,  2960,  2966,  2973,  2978,  2979,
    2981,  2983,  2989,  2990,  2993,  2994,  3000,  3005,  3008,  3010,
    3014,  3017,  3020,  3023,  3026,  3029,  3032,  3034,  3037,  3040,
    3043,  3046,  3049,  3052,  3055,  3057,  3059,  3061,  3063,  3066,
    3069,  3071,  3073,  3075,  3077,  3079,  3081,  3087,  3089,  3091,
    3094,  3099,  3104,  3111,  3114,  3116,  3117,  3129,  3130,  3133,
    3139,  3140,  3142,  3143,  3146,  3148,  3151,  3152,  3156,  3158,
    3159,  3164,  3165,  3168,  3170,  3174,  3176,  3178,  3182,  3187,
    3192,  3195,  3197,  3199,  3201,  3202,  3204,  3212,  3215,  3218,
    3221,  3224,  3227,  3229,  3232,  3233,  3237,  3238,  3242,  3243,
    3247,  3248,  3252,  3253,  3257,  3258,  3263,  3264,  3269,  3271,
    3273,  3275,  3277,  3279,  3281,  3282,  3287,  3288,  3290,  3291,
    3296,  3298,  3301,  3304,  3307,  3308,  3310,  3312,  3315,  3318,
    3319,  3322,  3323,  3328,  3332,  3338,  3339,  3342,  3347,  3349,
    3351,  3353,  3355,  3357,  3358,  3360,  3362,  3366,  3369,  3375,
    3378,  3384,  3390,  3396,  3402,  3408,  3414,  3415,  3418,  3420,
    3423,  3426,  3429,  3432,  3435,  3438,  3440,  3443,  3446,  3449,
    3452,  3454,  3457,  3460,  3463,  3466,  3468,  3470,  3472,  3473,
    3476,  3479,  3482,  3485,  3488,  3491,  3494,  3497,  3500,  3502,
    3504,  3506,  3508,  3510,  3512,  3514,  3516,  3519,  3522,  3525,
    3528,  3531,  3533,  3535,  3537,  3538,  3542,  3545,  3546,  3547,
    3548,  3549,  3550,  3551,  3567,  3568,  3571,  3574,  3575,  3577,
    3578,  3579,  3580,  3581,  3582,  3583,  3599,  3602,  3603,  3604,
    3605,  3616,  3617,  3619,  3623,  3627,  3630,  3635,  3639,  3643,
    3647,  3649,  3652,  3655,  3658,  3661,  3663,  3665,  3666,  3667,
    3676,  3677,  3678,  3688,  3689,  3691,  3693,  3696,  3699,  3702,
    3705,  3707,  3709,  3711,  3712,  3714,  3716,  3719,  3722,  3725,
    3734,  3737,  3740,  3745,  3748,  3749,  3751,  3753,  3757,  3760,
    3763,  3765,  3767,  3771,  3773,  3775,  3778,  3780,  3784,  3788,
    3792,  3794,  3798,  3800,  3802,  3804,  3806,  3808,  3810,  3812,
    3815,  3820,  3822,  3826,  3828,  3832,  3835,  3840,  3842,  3846,
    3848,  3851,  3856,  3858,  3862,  3864,  3866,  3868,  3871,  3875,
    3880,  3883,  3888,  3889,  3892,  3895,  3900,  3902,  3906,  3908,
    3910,  3912,  3915,  3917,  3919,  3921,  3923,  3925,  3928,  3935,
    3942,  3943,  3945,  3946,  3948,  3951,  3953,  3954,  3960,  3961,
    3967,  3969,  3970,  3974,  3976,  3980,  3982,  3986,  3988,  3990,
    3991,  3996,  3998,  4001,  4003,  4004,  4005,  4009,  4010,  4011,
    4015,  4017,  4019,  4021,  4023,  4025,  4027,  4030,  4033,  4038,
    4042,  4046,  4048,  4052,  4055,  4057,  4059,  4060,  4062,  4064,
    4066,  4068,  4069,  4071,  4075,  4077,  4081,  4083,  4084,  4088,
    4090,  4092,  4094,  4096,  4098,  4100,  4102,  4104,  4106,  4108,
    4110,  4112,  4120,  4127,  4132,  4137,  4139,  4141,  4143,  4144,
    4146,  4149,  4151,  4153,  4155,  4157,  4161,  4164,  4166,  4168,
    4171,  4173,  4175,  4176,  4180,  4182,  4186,  4188,  4192,  4194,
    4196,  4203,  4204,  4208,  4210,  4214,  4215,  4217,  4222,  4228,
    4231,  4233,  4235,  4240,  4242,  4246,  4251,  4256,  4261,  4263,
    4267,  4269,  4271,  4273,  4276,  4278,  4280,  4282,  4287,  4288,
    4290,  4291,  4293,  4295,  4298,  4301,  4303,  4305,  4307,  4309,
    4311,  4316,  4318,  4322,  4324,  4326,  4328,  4331,  4333,  4335,
    4338,  4341,  4343,  4347,  4350,  4353,  4355,  4359,  4361,  4364,
    4369,  4371,  4374,  4376,  4380,  4385,  4386,  4388,  4389,  4391,
    4392,  4394,  4396,  4400,  4402,  4406,  4408,  4411,  4413,  4417,
    4420,  4423,  4424,  4427,  4429,  4431,  4437,  4441,  4447,  4451,
    4453,  4457,  4459,  4461,  4462,  4464,  4468,  4472,  4476,  4483,
    4488,  4493,  4498,  4503,  4509,  4511,  4513,  4515,  4517,  4519,
    4521,  4523,  4525,  4527,  4529,  4531,  4533,  4534,  4536,  4538,
    4540,  4542,  4544,  4546,  4548,  4553,  4554,  4556,  4561,  4563,
    4569,  4575,  4577,  4579,  4581,  4583,  4585,  4590,  4592,  4597,
    4604,  4609,  4611,  4616,  4618,  4626,  4628,  4630,  4632,  4637,
    4644,  4645,  4648,  4653,  4655,  4657,  4659,  4661,  4663,  4665,
    4667,  4671,  4673,  4675,  4679,  4685,  4689,  4695,  4703,  4707,
    4709,  4711,  4715,  4721,  4725,  4731,  4739,  4741,  4742,  4746,
    4752,  4754,  4757,  4760,  4765,  4769,  4771,  4773,  4775,  4777,
    4779,  4782,  4785,  4786,  4790,  4791,  4795,  4797,  4799,  4801,
    4803,  4805,  4807,  4809,  4814,  4816,  4818,  4820,  4822,  4824,
    4826,  4828,  4833,  4835,  4837,  4839,  4841,  4843,  4845,  4847,
    4849,  4851,  4853,  4855,  4857,  4859,  4861,  4866,  4868,  4872,
    4874,  4878,  4879,  4887,  4888,  4897,  4898,  4905,  4906,  4915,
    4916,  4918,  4921,  4923,  4927,  4929,  4933,  4939,  4941,  4943,
    4945,  4947,  4949,  4950,  4951,  4961,  4967,  4969,  4971,  4978,
    4979,  4983,  4985,  4989,  4994,  4996,  4997,  5000,  5005,  5012,
    5013,  5015,  5017,  5019,  5021,  5025,  5027,  5030,  5032,  5034,
    5037,  5040,  5042,  5044,  5046,  5049,  5052,  5055,  5058,  5063,
    5067,  5070,  5074,  5078,  5082,  5084,  5086,  5088,  5090,  5092,
    5094,  5100,  5106,  5112,  5118,  5124,  5129,  5134,  5138,  5143,
    5145,  5149,  5151,  5157,  5165,  5171,  5172,  5175,  5177,  5179,
    5180,  5184,  5186,  5190,  5192,  5194,  5196,  5197,  5201,  5203,
    5205,  5207,  5209,  5214,  5221,  5223,  5225,  5228,  5232,  5234,
    5236,  5238,  5240,  5242,  5244,  5246,  5248,  5254,  5260,  5265,
    5266,  5271,  5273,  5276,  5278,  5280,  5282,  5284,  5286,  5288,
    5290,  5292,  5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,
    5310,  5312,  5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,
    5330,  5332,  5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,
    5350,  5352,  5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,
    5370,  5372,  5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,
    5390,  5392,  5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,
    5410,  5412,  5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,
    5430,  5432,  5434,  5436,  5438,  5440,  5442,  5444,  5446,  5448,
    5450,  5452,  5454,  5456,  5458,  5460,  5462,  5464,  5466,  5468,
    5470,  5472,  5474,  5476,  5478,  5480,  5482,  5484,  5486,  5488,
    5490,  5492,  5494,  5496,  5498,  5500,  5502,  5504,  5506,  5508,
    5510,  5512,  5514,  5516,  5518,  5520,  5522,  5524,  5526,  5528,
    5530,  5532,  5534,  5536,  5538,  5540,  5542,  5544,  5546,  5548,
    5550,  5552,  5554,  5556,  5558,  5560,  5562,  5564,  5566,  5568,
    5570,  5572,  5574,  5576,  5578,  5580,  5582,  5584,  5586,  5588,
    5590,  5592,  5594,  5596,  5598,  5600,  5602,  5604,  5606,  5608,
    5610,  5612,  5614,  5616,  5618,  5620,  5622,  5624,  5626,  5628,
    5630,  5632,  5634,  5636,  5638,  5640,  5642,  5644,  5646,  5648,
    5650,  5652,  5654,  5656,  5658,  5660,  5662,  5664,  5666,  5668,
    5670,  5672,  5674,  5676,  5678,  5680,  5682,  5684,  5686,  5688,
    5690,  5692,  5694,  5696,  5698,  5700,  5702,  5704,  5706,  5708,
    5710,  5712,  5714,  5716,  5718,  5720,  5722,  5724,  5726,  5728,
    5730,  5732,  5734,  5736,  5738,  5740,  5742,  5744,  5746,  5748,
    5750,  5752,  5754,  5756,  5758,  5760,  5762,  5764,  5766,  5768,
    5770,  5772,  5774,  5776,  5778,  5780,  5782,  5784,  5786,  5788,
    5790,  5792,  5794,  5796,  5798,  5800,  5802,  5804,  5806,  5808,
    5810,  5812,  5814,  5816,  5818,  5820,  5822,  5824,  5826,  5828,
    5830,  5832,  5834,  5836,  5838,  5840,  5842,  5844,  5846,  5848,
    5850,  5852,  5854,  5856,  5858,  5860,  5862,  5864,  5866,  5868,
    5870,  5872,  5874,  5876,  5878,  5880,  5882,  5884,  5886,  5888,
    5890,  5892,  5894,  5896,  5898,  5900,  5902,  5904,  5906,  5908,
    5910,  5912,  5914,  5915,  5919,  5920,  5924,  5925,  5926,  5933,
    5934,  5937,  5940,  5948,  5952,  5956,  5959,  5962,  5965,  5967,
    5971,  5973,  5977,  5979,  5983,  5985,  5989,  5991,  5993,  5995,
    5998,  6001,  6003,  6005,  6008,  6013,  6015,  6017,  6019,  6021,
    6023,  6025,  6029,  6032,  6036,  6040,  6044,  6050,  6056,  6062,
    6068,  6074,  6079,  6084,  6088,  6093,  6095,  6097,  6101,  6102,
    6108,  6110,  6114,  6118,  6122,  6124,  6127,  6129,  6131,  6133,
    6137,  6143,  6145,  6147,  6149,  6151,  6155,  6157,  6158,  6159,
    6166,  6167,  6170,  6171,  6173,  6175,  6178,  6181,  6183,  6185,
    6190,  6194,  6196,  6199,  6205,  6208,  6211,  6217,  6218,  6221,
    6223,  6225,  6228,  6235,  6242,  6244,  6245,  6247,  6250,  6252,
    6255,  6256,  6259,  6261,  6263,  6265,  6267,  6269,  6271,  6273,
    6275,  6277,  6279,  6281,  6283,  6285,  6287,  6289,  6291,  6293,
    6295,  6297,  6299,  6301,  6303,  6305,  6307,  6309,  6311,  6313,
    6315,  6317,  6319,  6321,  6323,  6325,  6327,  6329,  6331,  6333,
    6335,  6337,  6339,  6341,  6343,  6345,  6347,  6349,  6351,  6353,
    6355,  6357,  6359,  6361,  6363,  6365,  6367,  6369,  6371,  6373,
    6375,  6377,  6379,  6381,  6383,  6385,  6387,  6389,  6391,  6393,
    6395,  6397,  6399,  6401,  6403,  6405,  6407,  6409,  6411,  6413,
    6415,  6417,  6419,  6421,  6423,  6425,  6427,  6429,  6431,  6433,
    6435
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
       5,   764,    -1,   903,    -1,    25,    -1,  1005,    -1,  1005,
      -1,  1005,   666,  1005,    -1,    -1,   582,   910,   768,   771,
     775,   772,    -1,    -1,   582,   769,   770,   773,   772,    -1,
     777,    -1,   770,   777,    -1,   779,    -1,   771,   779,    -1,
     409,    -1,    -1,    -1,   389,   774,  1575,    -1,    -1,    -1,
     389,   776,  1575,    -1,    -1,   625,   910,   778,  1575,    -1,
      -1,   625,   910,   780,  1575,    -1,   326,  1002,    -1,   249,
    1000,    -1,   131,  1000,    -1,   216,    -1,   233,  1516,    -1,
     541,   999,    -1,    30,   783,    31,    -1,   784,    -1,   786,
      -1,   785,    -1,   784,   785,    -1,    29,    -1,   787,    -1,
     786,   787,    -1,    28,    -1,   442,    -1,    -1,    -1,   370,
     790,   792,   791,   793,    -1,   433,  1162,   671,   794,  1048,
    1075,   735,    -1,  1162,   671,   794,  1048,   593,   953,  1075,
     735,    -1,    -1,   796,   239,    -1,   795,    -1,   794,     5,
     795,    -1,  1005,    -1,  1005,   666,  1005,    -1,  1005,   666,
      20,    -1,   797,    -1,   796,   797,    -1,    -1,   318,   803,
     798,  1575,    -1,    -1,   321,   804,   799,  1575,    -1,    -1,
    1078,   800,  1575,    -1,    -1,   214,   801,  1575,    -1,    -1,
     212,   802,  1575,    -1,  1009,    -1,   803,     5,  1009,    -1,
    1009,    -1,   804,     5,  1009,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    -1,   143,    -1,   144,    -1,   478,   903,
     807,   440,    -1,    -1,     5,   854,   672,   857,    -1,   204,
      -1,   327,    -1,    -1,   810,    -1,   811,    -1,   810,   811,
      -1,    -1,    -1,   485,   812,   814,   813,  1270,    -1,   867,
      -1,   817,    -1,   814,     5,   817,    -1,    -1,   816,  1005,
      -1,   403,   815,   866,    25,    -1,   403,   815,   866,  1005,
      -1,   403,   815,   866,  1011,    -1,   403,   815,   866,    26,
      -1,   821,   839,    -1,    -1,   815,   403,   818,   819,    -1,
      26,    -1,    25,    -1,  1011,    -1,    19,    26,    -1,   815,
      -1,   820,    -1,   821,     5,   820,    -1,    -1,   367,    -1,
      -1,   716,    -1,   717,    -1,   718,    -1,    -1,   534,   506,
     831,   474,   825,   670,   839,    -1,    -1,    35,   823,   826,
     670,   839,    -1,    -1,   366,   822,   828,    26,   829,   350,
     506,   830,   474,   827,   670,   839,    -1,   478,    -1,   505,
      -1,   440,    -1,   473,    -1,    26,    -1,   832,     5,   832,
       5,   832,    -1,   832,     5,   832,    -1,   832,    -1,    26,
      -1,    -1,   511,   834,   814,   331,    -1,    -1,   308,   835,
     815,   666,    20,    -1,    -1,   384,   836,   815,   306,   478,
     837,   440,    -1,   838,    -1,   837,     5,   838,    -1,   815,
      -1,   841,    -1,    -1,   106,    -1,    -1,    -1,   842,   844,
     843,   840,    -1,   824,    -1,   833,    -1,   367,    -1,   368,
      -1,   367,   478,    26,   440,    -1,   368,   478,    26,   440,
      -1,   471,   478,    26,   440,    -1,   471,   478,    26,     5,
      26,   440,    -1,   369,   478,    26,   440,    -1,   369,   478,
      26,     5,    26,   440,    -1,   456,    -1,   663,   815,    -1,
     429,    -1,   556,    -1,   137,    -1,   446,    -1,   446,   478,
      26,   440,    -1,   446,   478,    26,     5,    26,   440,    -1,
     559,    -1,   559,   478,    26,   440,    -1,   559,   478,    26,
       5,    26,   440,    -1,    -1,   549,   845,   848,    -1,    -1,
     111,   846,   848,    -1,    -1,   347,   847,   848,    -1,   584,
      -1,   580,    -1,   127,    -1,   128,    -1,   621,    -1,   406,
     852,    -1,   418,   853,    -1,   849,    -1,    32,    -1,    -1,
     478,    26,   440,    -1,   603,   850,   666,   851,    -1,   815,
      -1,   815,    -1,    -1,   854,   672,   857,    -1,   862,   672,
     865,    -1,    -1,   855,   856,    -1,   628,    -1,   560,    -1,
     637,    -1,   599,    -1,   501,    -1,   517,    -1,   415,   859,
      -1,    -1,   858,   856,    -1,    -1,   478,   861,   440,    -1,
      -1,   478,    26,   440,    -1,    26,    -1,    -1,   863,   864,
     860,    -1,   628,    -1,   560,    -1,   637,    -1,   599,    -1,
     501,    -1,   517,    -1,   415,   859,    -1,   864,    -1,    -1,
      14,    -1,    -1,   284,  1005,   868,   663,   869,    -1,   871,
      -1,   874,    -1,   367,    -1,   367,   478,    26,   440,    -1,
     471,   478,    26,   440,    -1,   471,   478,    26,     5,    26,
     440,    -1,   456,    -1,   429,    -1,   556,    -1,   446,    -1,
     446,   478,    26,   440,    -1,   446,   478,    26,     5,    26,
     440,    -1,   559,    -1,   559,   478,    26,   440,    -1,   559,
     478,    26,     5,    26,   440,    -1,   549,    -1,   347,    -1,
     584,    -1,   580,    -1,   621,    -1,   406,   852,    -1,   418,
     853,    -1,   870,    -1,   603,   850,   666,   851,    -1,    -1,
     534,   506,   831,   474,   872,   670,   869,    -1,    -1,   366,
     822,   828,    26,   829,   350,   506,   830,   474,   873,   670,
     869,    -1,    -1,   511,   875,   877,   331,    -1,    -1,   308,
     876,  1005,   666,    20,    -1,   878,    -1,   877,     5,   878,
      -1,   879,   869,    -1,   880,    -1,   879,     5,   880,    -1,
    1005,    -1,    -1,   664,   995,    -1,   118,  1005,    -1,   116,
      -1,   672,   953,    -1,   672,   556,  1005,   705,   953,    -1,
     672,   556,  1005,   438,    -1,   120,  1005,    -1,   205,   928,
    1181,   889,    -1,   449,   928,   908,   881,   889,    -1,   258,
    1002,   889,    -1,    -1,    -1,   236,   886,  1188,   672,  1005,
     666,    20,   888,   735,   887,   890,    -1,    -1,   515,   996,
      -1,   735,    -1,    -1,   891,   286,    -1,   286,    -1,   892,
      -1,   891,   892,    -1,    -1,   401,   893,  1575,    -1,    -1,
     397,   894,  1575,    -1,    -1,  1078,   895,  1575,    -1,    37,
    1162,    -1,    38,  1162,    -1,    36,  1162,    -1,   545,   928,
     909,   735,    -1,   545,   928,   909,   735,   113,    -1,   262,
      -1,   262,   910,    -1,   334,    -1,   333,    -1,   261,    -1,
     413,    -1,   221,    -1,   260,    -1,   378,    -1,   377,    -1,
     291,    -1,   218,    -1,   217,    -1,   195,    -1,   251,    -1,
     179,    -1,   194,    -1,   235,    -1,   202,    -1,   913,    -1,
     912,    -1,   917,    -1,   945,    -1,   903,   904,    -1,   946,
      -1,   948,    -1,   914,    -1,    19,   903,    -1,    18,   903,
      -1,   919,    -1,   927,    -1,   921,    -1,   522,    -1,   805,
      -1,   922,    -1,   923,    -1,   924,    -1,   925,    -1,   926,
      -1,    40,   903,    -1,   928,    -1,   928,   907,    -1,   910,
      -1,   530,    -1,   906,    -1,   907,     5,   906,    -1,   910,
      -1,   908,     5,   910,    -1,   910,    -1,   909,     5,   910,
      -1,   903,    -1,    18,    -1,    19,    -1,     9,   903,    -1,
     531,    -1,   475,    -1,   478,   903,   440,    -1,   490,   478,
    1490,   440,    -1,   342,   478,  1490,   440,    -1,   911,  1011,
      -1,   911,    26,    -1,    25,    -1,  1011,    -1,    26,    -1,
     916,    -1,  1162,    -1,  1162,   468,  1162,    -1,   915,    -1,
     481,   903,    -1,   441,   903,    -1,  1273,    -1,    -1,   554,
     918,  1273,    -1,     7,   903,    -1,     6,   903,    -1,   903,
      -1,   920,     5,   903,    -1,   669,   478,  1490,   440,    -1,
     476,   478,  1490,   440,    -1,   669,   478,   928,   920,   440,
      -1,   476,   478,   928,   920,   440,    -1,   435,    -1,   297,
      -1,    10,   903,    -1,   300,   903,    -1,    10,   903,   489,
      25,    -1,   300,   903,   489,    25,    -1,   603,   903,    -1,
     420,   903,    -1,   603,   903,   489,    25,    -1,   420,   903,
     489,    25,    -1,   439,    -1,     8,   903,    -1,    18,   903,
      -1,    19,   903,    -1,    20,   903,    -1,    21,   903,    -1,
      22,   903,    -1,    11,   903,    -1,    14,   903,    -1,   504,
     903,    -1,    12,   903,    -1,    13,   903,    -1,    17,   903,
      -1,    16,   903,    -1,    15,   903,    -1,    -1,    -1,    -1,
    1005,   478,   930,   762,   931,   440,    -1,    -1,    -1,  1005,
     568,  1005,   478,   932,   762,   933,   440,    -1,    -1,    -1,
     584,   478,   935,   903,   936,   440,    -1,    -1,    -1,   560,
     478,   937,   903,   938,   440,    -1,    -1,    -1,   637,   478,
     939,   903,   940,   440,    -1,    -1,    -1,   628,   478,   941,
     903,   942,   440,    -1,   418,   478,   949,   440,   944,    -1,
     406,   478,    25,   440,   943,    -1,   406,   478,    26,   440,
     943,    -1,   406,   478,    26,   636,    26,   440,   943,    -1,
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
      -1,    -1,   452,   956,   999,   957,   959,  1368,   958,  1575,
     288,    -1,    -1,     8,   928,   908,    -1,    -1,    -1,   684,
    1005,   961,   809,   962,  1107,   964,   963,   969,   685,    -1,
      -1,   974,    -1,    -1,   965,    -1,   966,    -1,   965,   966,
      -1,    -1,   686,   967,  1575,    -1,    -1,   687,   968,  1575,
      -1,    -1,   970,    -1,   971,    -1,   970,   971,    -1,    -1,
     688,   972,  1575,    -1,    -1,   689,   973,  1575,    -1,   975,
     979,   374,    -1,   138,    -1,   138,   976,   593,   977,    -1,
     138,   433,   978,    -1,  1162,    -1,   976,     5,  1162,    -1,
    1005,    -1,   977,     5,  1005,    -1,  1162,    -1,   978,     5,
    1162,    -1,   980,    -1,   979,   980,    -1,    -1,   690,   981,
    1575,    -1,    -1,   691,   982,  1575,    -1,    -1,   710,   977,
     983,  1575,    -1,    -1,   528,   977,   984,  1575,    -1,    -1,
     671,   977,   985,  1575,    -1,    -1,    -1,   642,  1162,    14,
     910,   672,   910,   989,   987,  1575,   988,   289,    -1,    -1,
     618,   910,    -1,   592,   998,    -1,   601,    19,    26,    -1,
     601,    -1,   548,    18,    26,    -1,   548,    -1,    26,    -1,
    1162,    -1,   715,    -1,    25,    -1,  1010,    -1,   910,    -1,
     993,     5,   993,    -1,   994,    -1,  1005,    -1,   713,   478,
    1005,   440,    -1,  1005,   666,   713,   478,  1005,   440,    -1,
    1005,   506,   732,   474,    -1,  1005,   666,    20,    -1,  1005,
     506,   732,   474,   666,    20,    -1,  1005,   666,  1005,    -1,
    1005,   506,   732,   474,   666,  1005,    -1,   996,    -1,    25,
      -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,
      -1,  1006,    -1,    -1,   597,    26,    -1,  1574,    -1,  1007,
      -1,  1574,    -1,   399,   478,  1008,   440,    -1,  1165,    -1,
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
     668,   910,   622,  1034,  1575,  1035,  1036,   488,    -1,    -1,
      -1,   589,  1037,  1575,    -1,    -1,    -1,   110,  1038,   910,
     622,  1039,  1575,  1036,    -1,   155,  1005,   478,    26,   440,
      -1,   101,  1005,    -1,   123,  1005,    -1,    -1,   338,  1193,
    1043,   672,   530,    -1,   338,  1193,   603,  1044,    -1,  1045,
      -1,  1044,     5,  1045,    -1,  1046,   666,  1462,    -1,  1046,
     666,    20,    -1,  1458,    -1,    -1,  1049,   374,    -1,   374,
      -1,    -1,   199,    -1,  1050,    -1,  1049,  1050,    -1,    -1,
     318,  1064,  1051,  1575,    -1,    -1,   321,  1065,  1052,  1575,
      -1,    -1,   401,  1053,  1575,    -1,    -1,   397,  1054,  1575,
      -1,    -1,  1078,  1055,  1575,    -1,    -1,   353,  1056,  1575,
      -1,    -1,   323,  1057,  1575,    -1,    -1,    41,  1058,  1575,
      -1,    -1,    39,  1059,  1575,    -1,    -1,    51,  1060,  1575,
      -1,    -1,    50,  1061,  1575,    -1,    -1,    44,  1062,  1575,
      -1,    -1,    43,  1063,  1575,    -1,   996,    -1,  1064,     5,
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
    1101,    -1,  1100,  1101,    -1,  1041,    -1,  1106,    -1,  1559,
      -1,  1122,    -1,  1108,    -1,  1121,    -1,    -1,  1103,    -1,
    1105,    -1,  1103,  1105,    -1,   114,  1005,    -1,  1110,    -1,
    1116,    -1,  1128,    -1,  1283,    -1,  1293,    -1,  1132,    -1,
     960,    -1,   782,    -1,  1040,    -1,   788,    -1,  1559,    -1,
     782,    -1,    -1,   782,    -1,   810,    -1,   416,    -1,   108,
      -1,    -1,    -1,    -1,    -1,  1109,  1111,  1005,   478,  1112,
    1179,   440,  1113,   809,  1114,  1107,  1575,  1115,    -1,   259,
      -1,    -1,    -1,   604,  1117,   809,  1118,  1575,   410,    -1,
     225,   905,    -1,   928,    -1,   928,   908,    -1,   405,  1474,
      -1,   514,  1474,    -1,  1123,    -1,  1124,    -1,  1123,  1124,
      -1,  1125,    -1,    -1,   454,  1126,  1127,    -1,   809,   290,
      -1,   992,    -1,  1106,    -1,  1121,    -1,    -1,    -1,    -1,
     162,  1005,   161,  1005,   478,  1129,  1179,   440,  1130,   809,
    1131,  1107,  1575,  1115,    -1,    -1,    -1,   692,  1005,  1133,
     809,  1134,  1135,   693,    -1,  1136,    -1,  1135,  1136,    -1,
      -1,   694,  1137,  1575,    -1,    -1,   671,  1005,  1138,  1575,
      -1,    -1,   605,  1140,  1155,  1146,  1141,    -1,   411,    -1,
      -1,   282,  1143,  1575,    -1,    -1,    23,  1147,  1148,  1149,
    1004,  1144,  1575,    -1,    -1,    23,  1147,  1004,  1145,  1575,
      -1,  1142,    -1,  1146,  1142,    -1,    -1,  1080,    -1,    25,
      -1,  1162,    -1,    -1,  1162,    -1,    25,    -1,   299,  1153,
      -1,   311,  1154,    -1,   294,  1154,    -1,   632,    -1,    25,
      -1,  1162,    -1,  1153,    -1,  1154,     5,  1153,    -1,  1162,
      -1,    25,    -1,  1159,  1157,    -1,    -1,   736,  1160,    -1,
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
    1162,    -1,   302,  1001,   664,   994,   626,  1567,   740,    -1,
      -1,   664,   478,   910,     5,   910,   440,  1197,    -1,    -1,
     615,   478,   910,     5,   910,   440,    -1,   303,  1005,  1196,
      -1,  1005,    -1,   388,  1003,  1201,    -1,  1202,    -1,   593,
     910,    -1,  1203,  1204,  1209,     8,  1199,    -1,    -1,   664,
    1205,   478,   910,     5,   910,   440,    -1,    -1,   603,  1006,
      -1,    -1,   400,    -1,   265,  1516,   314,  1554,  1208,    -1,
     610,   998,    -1,   610,   998,     8,   928,   908,    -1,    -1,
     663,   623,  1510,   423,  1510,    -1,   663,   623,  1510,     5,
     423,  1510,    -1,   663,  1510,     5,  1510,    -1,    -1,   695,
      -1,   696,    -1,   443,   672,  1554,  1211,  1212,    -1,    -1,
     663,  1554,    -1,    -1,   663,   623,  1510,     8,  1510,    -1,
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
      -1,    -1,  1078,  1228,  1575,    -1,   909,    -1,    -1,   650,
     998,  1231,  1232,    -1,    -1,   593,  1233,    -1,  1234,    -1,
    1233,     5,  1234,    -1,  1502,    -1,   530,    -1,   268,  1237,
     136,    -1,   268,  1237,   672,  1236,    -1,   268,  1237,   135,
    1236,    -1,   268,  1237,    -1,    25,    -1,  1010,    -1,  1005,
      -1,    -1,   526,    -1,   196,  1237,  1238,   478,   928,  1120,
     440,    -1,   241,  1237,    -1,   115,  1237,    -1,  1274,  1282,
      -1,   494,   109,    -1,   494,  1244,    -1,  1245,    -1,  1244,
    1245,    -1,    -1,   184,  1246,  1575,    -1,    -1,   246,  1247,
    1575,    -1,    -1,   276,  1248,  1575,    -1,    -1,   264,  1249,
    1575,    -1,    -1,   301,  1250,  1575,    -1,    -1,   248,  1162,
    1251,  1575,    -1,    -1,   272,  1162,  1252,  1575,    -1,  1263,
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
      26,    -1,    56,    26,    -1,   133,    -1,   134,    -1,  1574,
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
      -1,   405,  1382,  1380,    -1,  1554,    -1,  1554,   658,  1005,
      -1,    25,    -1,    -1,  1515,  1384,  1385,    -1,  1416,    -1,
    1420,    -1,  1379,    -1,  1517,    -1,  1378,    -1,  1371,    -1,
    1372,    -1,  1362,    -1,  1354,    -1,  1353,    -1,  1486,    -1,
    1534,    -1,   552,  1389,   671,  1458,   672,  1394,  1388,    -1,
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
      -1,  1444,    -1,  1443,     5,  1444,    -1,  1558,    -1,  1465,
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
    1504,    -1,  1558,    -1,  1497,    -1,   632,  1497,    -1,   633,
    1497,    -1,   617,  1497,    -1,   658,  1005,    -1,   658,  1005,
     666,  1005,    -1,  1503,    21,  1502,    -1,  1503,  1524,    -1,
    1503,    20,  1502,    -1,  1503,    18,  1502,    -1,  1503,    19,
    1502,    -1,  1465,    -1,   531,    -1,   475,    -1,   623,    -1,
      20,    -1,   112,    -1,   635,   478,  1449,  1502,   440,    -1,
     647,   478,  1449,  1502,   440,    -1,   648,   478,  1449,  1502,
     440,    -1,   655,   478,  1449,  1502,   440,    -1,   543,   478,
    1449,  1502,   440,    -1,  1005,   478,  1505,   440,    -1,   584,
     478,  1505,   440,    -1,   478,  1502,   440,    -1,   491,   478,
    1525,   440,    -1,  1502,    -1,  1505,     5,  1502,    -1,  1465,
      -1,  1515,   396,  1514,  1509,  1491,    -1,  1515,   385,  1514,
    1509,   296,  1458,  1511,    -1,  1515,   385,  1514,  1509,  1162,
      -1,    -1,   371,  1510,    -1,    25,    -1,  1162,    -1,    -1,
     478,  1512,   440,    -1,  1513,    -1,  1512,     5,  1513,    -1,
    1005,    -1,    25,    -1,  1162,    -1,    -1,   315,  1516,   642,
      -1,  1006,    -1,  1522,    -1,  1521,    -1,  1518,    -1,   364,
    1519,   672,  1519,    -1,   345,  1458,   666,  1520,   672,  1520,
      -1,  1005,    -1,  1005,    -1,   269,  1458,    -1,   340,  1458,
    1523,    -1,   319,    -1,   222,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    -1,   143,    -1,   144,    -1,   444,     5,
    1472,   672,  1473,    -1,  1558,     5,  1472,   672,  1473,    -1,
     444,  1472,   672,  1473,    -1,    -1,   654,  1527,  1528,   237,
      -1,  1529,    -1,  1528,  1529,    -1,    33,    -1,  1530,    -1,
    1532,    -1,   400,    -1,   352,    -1,   271,    -1,   631,    -1,
     528,    -1,   632,    -1,   533,    -1,   577,    -1,   633,    -1,
     163,    -1,   534,    -1,   663,    -1,   634,    -1,   365,    -1,
     535,    -1,   366,    -1,   664,    -1,   658,    -1,   322,    -1,
     536,    -1,   231,    -1,   436,    -1,   635,    -1,   710,    -1,
     437,    -1,   537,    -1,   538,    -1,   578,    -1,   579,    -1,
     479,    -1,   480,    -1,   402,    -1,   697,    -1,   665,    -1,
     580,    -1,   438,    -1,   582,    -1,   576,    -1,   367,    -1,
     539,    -1,   540,    -1,   439,    -1,   541,    -1,   440,    -1,
     474,    -1,   542,    -1,   636,    -1,   481,    -1,   441,    -1,
       5,    -1,    23,    -1,   442,    -1,   482,    -1,   443,    -1,
     404,    -1,   403,    -1,   370,    -1,   543,    -1,   483,    -1,
     444,    -1,   484,    -1,   583,    -1,   405,    -1,   584,    -1,
     406,    -1,   637,    -1,   638,    -1,   445,    -1,   639,    -1,
     446,    -1,   447,    -1,   448,    -1,   407,    -1,   544,    -1,
     485,    -1,   486,    -1,   371,    -1,   585,    -1,   328,    -1,
     640,    -1,   701,    -1,   449,    -1,   408,    -1,    21,    -1,
     666,    -1,   487,    -1,   372,    -1,   588,    -1,   110,    -1,
     589,    -1,   704,    -1,   450,    -1,    14,    -1,   545,    -1,
     489,    -1,   546,    -1,   376,    -1,   590,    -1,   451,    -1,
     490,    -1,   591,    -1,   491,    -1,   492,    -1,   414,    -1,
     581,    -1,   547,    -1,   146,    -1,   240,    -1,   493,    -1,
     548,    -1,   641,    -1,   549,    -1,   550,    -1,   642,    -1,
     452,    -1,   453,    -1,   494,    -1,   684,    -1,   138,    -1,
     153,    -1,   551,    -1,   415,    -1,   592,    -1,   593,    -1,
     416,    -1,   337,    -1,   454,    -1,   667,    -1,   594,    -1,
     552,    -1,    13,    -1,   553,    -1,   554,    -1,   495,    -1,
     496,    -1,   597,    -1,   598,    -1,   599,    -1,   706,    -1,
     119,    -1,   668,    -1,   669,    -1,   159,    -1,   555,    -1,
     455,    -1,   338,    -1,   711,    -1,   497,    -1,   456,    -1,
     380,    -1,   418,    -1,   713,    -1,   382,    -1,   643,    -1,
     586,    -1,   705,    -1,   556,    -1,   529,    -1,   419,    -1,
     644,    -1,   673,    -1,   457,    -1,     7,    -1,   475,    -1,
     629,    -1,   530,    -1,     6,    -1,   531,    -1,     8,    -1,
     601,    -1,   602,    -1,    12,    -1,   645,    -1,   603,    -1,
     558,    -1,   498,    -1,   646,    -1,   458,    -1,   604,    -1,
     499,    -1,    10,    -1,    53,    -1,   500,    -1,   605,    -1,
     692,    -1,   707,    -1,    19,    -1,   501,    -1,   158,    -1,
      22,    -1,   606,    -1,   502,    -1,   559,    -1,   560,    -1,
      20,    -1,   607,    -1,   608,    -1,   358,    -1,   609,    -1,
     503,    -1,     9,    -1,   670,    -1,   715,    -1,   671,    -1,
     610,    -1,   478,    -1,   506,    -1,   507,    -1,   459,    -1,
     561,    -1,   389,    -1,   562,    -1,   508,    -1,   649,    -1,
     423,    -1,   563,    -1,   203,    -1,   154,    -1,   460,    -1,
      18,    -1,   157,    -1,   390,    -1,   461,    -1,   160,    -1,
     424,    -1,   359,    -1,   566,    -1,   391,    -1,   392,    -1,
     462,    -1,   509,    -1,   510,    -1,   650,    -1,   611,    -1,
     425,    -1,   612,    -1,   511,    -1,   463,    -1,   651,    -1,
     344,    -1,   426,    -1,   427,    -1,   512,    -1,   428,    -1,
     225,    -1,   394,    -1,   464,    -1,   513,    -1,   567,    -1,
     309,    -1,   652,    -1,   613,    -1,   653,    -1,   514,    -1,
     516,    -1,   517,    -1,   465,    -1,   518,    -1,   569,    -1,
     519,    -1,   466,    -1,   521,    -1,   614,    -1,   532,    -1,
     615,    -1,   616,    -1,   570,    -1,   347,    -1,   429,    -1,
     617,    -1,   522,    -1,   654,    -1,   348,    -1,   137,    -1,
     618,    -1,   619,    -1,   655,    -1,   467,    -1,   587,    -1,
     620,    -1,   164,    -1,   621,    -1,   622,    -1,   468,    -1,
     714,    -1,   672,    -1,   656,    -1,   469,    -1,   571,    -1,
     245,    -1,   395,    -1,   572,    -1,   523,    -1,   524,    -1,
     525,    -1,   470,    -1,   657,    -1,   623,    -1,   430,    -1,
     526,    -1,   471,    -1,   399,    -1,   624,    -1,   472,    -1,
     625,    -1,   573,    -1,   574,    -1,   575,    -1,   626,    -1,
     432,    -1,   627,    -1,   647,    -1,   648,    -1,   630,    -1,
     628,    -1,   527,    -1,    -1,   238,  1531,  1558,    -1,    -1,
     600,  1533,  1184,    -1,    -1,    -1,   525,  1458,  1535,  1538,
    1536,  1537,    -1,    -1,   198,   999,    -1,   573,  1434,    -1,
      97,  1542,   440,    14,   478,  1543,   440,    -1,    93,  1543,
     440,    -1,    94,  1543,   440,    -1,   630,  1539,    -1,    96,
    1543,    -1,    95,  1543,    -1,  1541,    -1,  1539,     5,  1541,
      -1,  1462,    -1,  1540,    14,  1544,    -1,  1540,    -1,  1542,
       5,  1540,    -1,  1544,    -1,  1543,     5,  1544,    -1,   530,
      -1,  1545,    -1,  1546,    -1,    19,  1546,    -1,    18,  1546,
      -1,  1548,    -1,  1497,    -1,   658,  1005,    -1,   658,  1005,
     666,  1005,    -1,  1547,    -1,  1465,    -1,   531,    -1,   475,
      -1,   623,    -1,   112,    -1,  1546,    21,  1545,    -1,  1546,
    1524,    -1,  1546,    20,  1545,    -1,  1546,    18,  1545,    -1,
    1546,    19,  1545,    -1,   635,   478,  1449,  1545,   440,    -1,
     647,   478,  1449,  1545,   440,    -1,   648,   478,  1449,  1545,
     440,    -1,   655,   478,  1449,  1545,   440,    -1,   543,   478,
    1449,  1545,   440,    -1,  1005,   478,  1549,   440,    -1,   584,
     478,  1549,   440,    -1,   478,  1545,   440,    -1,   491,   478,
    1525,   440,    -1,  1558,    -1,  1545,    -1,  1549,     5,  1545,
      -1,    -1,   430,  1193,   603,  1551,  1552,    -1,  1553,    -1,
    1552,     5,  1553,    -1,  1458,   666,  1462,    -1,  1458,   666,
      20,    -1,  1555,    -1,   238,  1556,    -1,  1556,    -1,  1171,
      -1,  1005,    -1,  1556,   666,  1557,    -1,    25,   666,  1556,
     666,  1557,    -1,    20,    -1,  1192,    -1,  1005,    -1,  1555,
      -1,  1555,   468,  1555,    -1,    34,    -1,    -1,    -1,   574,
    1561,   910,  1562,  1575,   375,    -1,    -1,   705,   953,    -1,
      -1,   708,    -1,   229,    -1,   325,  1000,    -1,   117,  1000,
      -1,   355,    -1,   354,    -1,   356,  1002,  1563,  1564,    -1,
     540,   953,  1564,    -1,   151,    -1,   183,  1000,    -1,   910,
     613,     5,   910,   441,    -1,   556,   910,    -1,   312,  1000,
      -1,   148,  1570,     8,  1571,  1569,    -1,    -1,   593,   910,
      -1,  1005,    -1,  1005,    -1,   295,  1000,    -1,   298,  1000,
     672,   910,     5,   910,    -1,   298,  1000,   665,   910,     5,
     910,    -1,    27,    -1,    -1,  1577,    -1,  1578,  1270,    -1,
    1576,    -1,  1577,  1576,    -1,    -1,  1579,  1580,    -1,   725,
      -1,   726,    -1,   727,    -1,   728,    -1,   745,    -1,   767,
      -1,   781,    -1,   782,    -1,   788,    -1,   789,    -1,   808,
      -1,   882,    -1,   883,    -1,   884,    -1,   885,    -1,   896,
      -1,   897,    -1,   898,    -1,   899,    -1,   900,    -1,   901,
      -1,   902,    -1,   955,    -1,   986,    -1,   990,    -1,  1012,
      -1,  1014,    -1,  1017,    -1,  1018,    -1,  1019,    -1,  1020,
      -1,  1033,    -1,  1042,    -1,  1066,    -1,  1067,    -1,  1069,
      -1,  1073,    -1,  1088,    -1,  1089,    -1,  1093,    -1,  1094,
      -1,  1095,    -1,  1096,    -1,  1104,    -1,  1119,    -1,  1139,
      -1,  1150,    -1,  1151,    -1,  1152,    -1,  1156,    -1,  1195,
      -1,  1198,    -1,  1200,    -1,  1206,    -1,  1207,    -1,  1210,
      -1,  1213,    -1,  1216,    -1,  1218,    -1,  1220,    -1,  1223,
      -1,  1230,    -1,  1235,    -1,  1239,    -1,  1240,    -1,  1241,
      -1,  1253,    -1,  1306,    -1,  1307,    -1,  1309,    -1,  1328,
      -1,  1329,    -1,  1349,    -1,  1352,    -1,  1381,    -1,  1383,
      -1,  1475,    -1,  1476,    -1,  1507,    -1,  1508,    -1,  1526,
      -1,  1550,    -1,  1559,    -1,  1560,    -1,  1565,    -1,  1566,
      -1,  1568,    -1,  1572,    -1,  1573,    -1
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
    1397,  1398,  1399,  1404,  1407,  1412,  1416,  1424,  1427,  1427,
    1433,  1437,  1452,  1450,  1468,  1468,  1483,  1483,  1486,  1486,
    1490,  1493,  1493,  1493,  1500,  1501,  1500,  1508,  1508,  1519,
    1519,  1538,  1541,  1544,  1547,  1550,  1553,  1566,  1571,  1571,
    1572,  1572,  1575,  1580,  1580,  1584,  1594,  1608,  1613,  1607,
    1624,  1630,  1638,  1639,  1642,  1642,  1645,  1649,  1654,  1661,
    1661,  1665,  1665,  1666,  1666,  1667,  1667,  1668,  1668,  1669,
    1669,  1677,  1681,  1687,  1691,  1706,  1709,  1712,  1715,  1718,
    1721,  1727,  1738,  1743,  1756,  1760,  1775,  1776,  1780,  1780,
    1784,  1784,  1784,  1785,  1790,  1790,  1793,  1793,  1802,  1803,
    1804,  1807,  1811,  1812,  1812,  1829,  1829,  1829,  1829,  1833,
    1840,  1841,  1844,  1844,  1848,  1849,  1850,  1851,  1856,  1856,
    1862,  1862,  1871,  1868,  1884,  1884,  1886,  1886,  1888,  1890,
    1892,  1894,  1897,  1901,  1901,  1902,  1902,  1906,  1906,  1918,
    1918,  1923,  1927,  1929,  1930,  1933,  1933,  1933,  1937,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,
    1951,  1952,  1953,  1954,  1958,  1963,  1968,  1972,  1975,  1979,
    1979,  1980,  1980,  1981,  1981,  1982,  1983,  1984,  1985,  1986,
    1987,  1990,  1991,  1992,  2022,  2022,  2027,  2031,  2033,  2035,
    2035,  2042,  2046,  2046,  2050,  2051,  2052,  2053,  2054,  2055,
    2056,  2062,  2062,  2065,  2067,  2073,  2075,  2081,  2089,  2089,
    2092,  2093,  2094,  2095,  2096,  2097,  2098,  2104,  2107,  2107,
    2120,  2120,  2127,  2128,  2129,  2131,  2132,  2134,  2136,  2137,
    2138,  2139,  2144,  2150,  2156,  2157,  2159,  2161,  2162,  2163,
    2164,  2165,  2166,  2169,  2170,  2177,  2185,  2185,  2193,  2190,
    2205,  2205,  2207,  2207,  2215,  2215,  2218,  2221,  2222,  2227,
    2239,  2243,  2246,  2249,  2250,  2251,  2252,  2253,  2258,  2265,
    2271,  2276,  2281,  2276,  2294,  2296,  2301,  2306,  2306,  2306,
    2310,  2310,  2313,  2313,  2320,  2320,  2327,  2327,  2338,  2356,
    2362,  2386,  2389,  2404,  2407,  2420,  2422,  2424,  2426,  2428,
    2430,  2432,  2438,  2440,  2444,  2446,  2448,  2450,  2452,  2454,
    2456,  2462,  2476,  2477,  2478,  2479,  2480,  2484,  2485,  2486,
    2490,  2495,  2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2512,  2519,  2519,  2524,  2524,  2527,  2533,  2541,
    2547,  2557,  2558,  2566,  2573,  2577,  2587,  2591,  2596,  2601,
    2603,  2606,  2612,  2620,  2633,  2638,  2644,  2649,  2654,  2655,
    2661,  2732,  2743,  2752,  2760,  2760,  2775,  2779,  2786,  2789,
    2797,  2801,  2804,  2810,  2819,  2824,  2832,  2835,  2838,  2843,
    2850,  2855,  2860,  2865,  2875,  2883,  2891,  2896,  2900,  2905,
    2909,  2913,  2920,  2923,  2926,  2930,  2934,  2938,  2942,  2950,
    2960,  2965,  2958,  2981,  2986,  2981,  3003,  3003,  3003,  3006,
    3006,  3006,  3010,  3010,  3010,  3014,  3014,  3014,  3018,  3024,
    3030,  3036,  3042,  3048,  3058,  3058,  3062,  3066,  3067,  3078,
    3079,  3085,  3095,  3105,  3115,  3116,  3119,  3124,  3130,  3134,
    3138,  3141,  3147,  3150,  3153,  3170,  3173,  3179,  3180,  3181,
    3185,  3186,  3187,  3188,  3189,  3191,  3192,  3193,  3195,  3196,
    3200,  3201,  3206,  3210,  3215,  3219,  3234,  3238,  3244,  3233,
    3257,  3258,  3270,  3276,  3270,  3290,  3290,  3292,  3293,  3297,
    3297,  3301,  3301,  3306,  3306,  3313,  3314,  3318,  3318,  3322,
    3322,  3327,  3327,  3334,  3338,  3339,  3340,  3345,  3345,  3348,
    3348,  3352,  3352,  3356,  3356,  3360,  3360,  3365,  3365,  3370,
    3370,  3375,  3375,  3380,  3380,  3396,  3400,  3395,  3408,  3411,
    3425,  3442,  3443,  3444,  3445,  3446,  3447,  3448,  3451,  3451,
    3454,  3456,  3459,  3462,  3465,  3470,  3475,  3478,  3483,  3488,
    3493,  3500,  3501,  3508,  3515,  3517,  3523,  3528,  3533,  3538,
    3538,  3541,  3547,  3552,  3555,  3562,  3562,  3564,  3567,  3570,
    3575,  3580,  3585,  3592,  3601,  3601,  3663,  3671,  3672,  3680,
    3687,  3687,  3691,  3696,  3702,  3706,  3710,  3716,  3720,  3724,
    3730,  3730,  3738,  3739,  3743,  3743,  3747,  3748,  3751,  3754,
    3754,  3757,  3759,  3759,  3762,  3764,  3764,  3765,  3767,  3767,
    3776,  3783,  3774,  3804,  3804,  3804,  3807,  3809,  3807,  3816,
    3819,  3825,  3836,  3836,  3840,  3846,  3846,  3850,  3851,  3855,
    3865,  3866,  3867,  3870,  3872,  3877,  3877,  3881,  3880,  3888,
    3887,  3894,  3894,  3900,  3900,  3907,  3907,  3913,  3913,  3919,
    3919,  3925,  3925,  3929,  3929,  3930,  3930,  3931,  3931,  3932,
    3932,  3936,  3936,  3947,  3951,  3957,  3961,  3966,  3971,  3976,
    3977,  3978,  3982,  3981,  3994,  3999,  4004,  4004,  4020,  4026,
    4027,  4028,  4029,  4032,  4032,  4035,  4042,  4043,  4044,  4045,
    4046,  4047,  4048,  4049,  4050,  4055,  4055,  4057,  4060,  4060,
    4062,  4066,  4069,  4070,  4073,  4073,  4078,  4081,  4082,  4083,
    4084,  4085,  4086,  4087,  4088,  4089,  4090,  4091,  4092,  4093,
    4094,  4095,  4096,  4097,  4098,  4102,  4120,  4120,  4120,  4147,
    4158,  4165,  4171,  4177,  4183,  4195,  4220,  4219,  4236,  4236,
    4240,  4241,  4249,  4250,  4251,  4252,  4253,  4254,  4261,  4262,
    4264,  4265,  4269,  4274,  4275,  4276,  4277,  4278,  4279,  4280,
    4281,  4282,  4283,  4284,  4287,  4289,  4289,  4291,  4295,  4295,
    4304,  4309,  4325,  4331,  4303,  4345,  4359,  4369,  4358,  4382,
    4389,  4389,  4394,  4400,  4408,  4413,  4414,  4417,  4420,  4420,
    4428,  4434,  4445,  4446,  4450,  4454,  4467,  4449,  4480,  4486,
    4480,  4497,  4498,  4502,  4502,  4509,  4509,  4524,  4524,  4538,
    4549,  4548,  4560,  4556,  4573,  4570,  4583,  4583,  4585,  4586,
    4588,  4589,  4592,  4593,  4594,  4596,  4601,  4606,  4612,  4614,
    4615,  4618,  4619,  4622,  4624,  4631,  4634,  4637,  4640,  4644,
    4648,  4649,  4650,  4651,  4652,  4656,  4661,  4661,  4664,  4691,
    4749,  4749,  4752,  4756,  4760,  4803,  4845,  4846,  4847,  4850,
    4864,  4876,  4876,  4881,  4882,  4888,  4948,  5005,  5010,  5017,
    5022,  5030,  5036,  5069,  5072,  5073,  5114,  5157,  5158,  5162,
    5163,  5167,  5220,  5224,  5227,  5233,  5244,  5251,  5259,  5259,
    5262,  5263,  5264,  5265,  5266,  5269,  5272,  5278,  5281,  5285,
    5290,  5298,  5303,  5310,  5313,  5319,  5321,  5321,  5321,  5325,
    5345,  5352,  5359,  5362,  5376,  5383,  5384,  5387,  5388,  5392,
    5398,  5403,  5409,  5410,  5415,  5419,  5419,  5423,  5424,  5427,
    5428,  5432,  5440,  5443,  5449,  5450,  5452,  5454,  5458,  5458,
    5459,  5464,  5472,  5473,  5478,  5479,  5481,  5494,  5496,  5497,
    5500,  5501,  5502,  5503,  5504,  5505,  5506,  5507,  5508,  5509,
    5510,  5511,  5512,  5513,  5514,  5515,  5516,  5517,  5518,  5519,
    5520,  5521,  5522,  5523,  5524,  5525,  5539,  5547,  5547,  5549,
    5553,  5557,  5561,  5565,  5570,  5585,  5583,  5603,  5604,  5608,
    5613,  5614,  5618,  5619,  5621,  5622,  5624,  5624,  5633,  5642,
    5642,  5652,  5653,  5658,  5659,  5662,  5675,  5689,  5693,  5697,
    5701,  5710,  5710,  5714,  5717,  5717,  5719,  5725,  5733,  5739,
    5741,  5745,  5748,  5748,  5751,  5751,  5756,  5756,  5765,  5765,
    5769,  5769,  5770,  5770,  5771,  5771,  5785,  5785,  5805,  5806,
    5807,  5808,  5809,  5810,  5813,  5813,  5819,  5819,  5822,  5822,
    5838,  5839,  5840,  5849,  5861,  5862,  5865,  5866,  5869,  5872,
    5872,  5877,  5877,  5898,  5903,  5909,  5910,  5911,  5915,  5916,
    5917,  5918,  5922,  5932,  5934,  5939,  5942,  5947,  5953,  5960,
    5967,  5976,  5983,  5990,  5997,  6004,  6013,  6013,  6015,  6015,
    6018,  6019,  6020,  6021,  6022,  6023,  6024,  6025,  6026,  6027,
    6030,  6030,  6033,  6034,  6035,  6036,  6039,  6039,  6042,  6042,
    6045,  6046,  6047,  6048,  6049,  6050,  6051,  6052,  6054,  6055,
    6056,  6057,  6059,  6060,  6061,  6062,  6064,  6065,  6066,  6067,
    6068,  6069,  6070,  6071,  6075,  6082,  6091,  6103,  6112,  6123,
    6127,  6131,  6137,  6102,  6150,  6153,  6161,  6173,  6175,  6180,
    6188,  6198,  6201,  6205,  6213,  6179,  6222,  6226,  6230,  6234,
    6226,  6244,  6245,  6246,  6247,  6252,  6254,  6257,  6261,  6264,
    6271,  6276,  6277,  6278,  6279,  6284,  6285,  6291,  6291,  6291,
    6296,  6296,  6296,  6304,  6305,  6309,  6310,  6315,  6316,  6317,
    6318,  6319,  6322,  6324,  6324,  6327,  6328,  6332,  6333,  6336,
    6337,  6340,  6343,  6346,  6352,  6353,  6365,  6366,  6371,  6372,
    6373,  6377,  6380,  6386,  6389,  6397,  6398,  6404,  6408,  6412,
    6418,  6421,  6430,  6433,  6436,  6439,  6442,  6445,  6448,  6455,
    6458,  6465,  6468,  6474,  6477,  6484,  6487,  6494,  6495,  6500,
    6504,  6507,  6513,  6516,  6522,  6529,  6530,  6534,  6544,  6547,
    6553,  6555,  6560,  6561,  6565,  6567,  6573,  6574,  6587,  6599,
    6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,  6610,  6613,
    6619,  6619,  6625,  6625,  6636,  6649,  6659,  6659,  6664,  6664,
    6668,  6672,  6673,  6679,  6680,  6685,  6689,  6696,  6699,  6706,
    6705,  6716,  6720,  6724,  6731,  6734,  6734,  6747,  6751,  6751,
    6766,  6768,  6770,  6772,  6774,  6776,  6778,  6780,  6786,  6796,
    6803,  6808,  6809,  6813,  6816,  6817,  6820,  6821,  6822,  6825,
    6830,  6837,  6838,  6844,  6856,  6857,  6858,  6861,  6861,  6866,
    6871,  6876,  6877,  6880,  6881,  6886,  6891,  6895,  6900,  6901,
    6905,  6912,  6913,  6914,  6915,  6920,  6921,  6922,  6925,  6926,
    6927,  6931,  6932,  6933,  6937,  6938,  6942,  6943,  6944,  6945,
    6946,  6947,  6950,  6951,  6956,  6957,  6962,  6963,  6968,  6969,
    6974,  6979,  6980,  6985,  6986,  6990,  6991,  6996,  7003,  7008,
    7013,  7017,  7018,  7023,  7024,  7030,  7031,  7032,  7037,  7038,
    7044,  7047,  7050,  7057,  7058,  7059,  7060,  7074,  7079,  7080,
    7083,  7085,  7092,  7095,  7101,  7109,  7113,  7117,  7121,  7125,
    7128,  7131,  7138,  7145,  7150,  7154,  7155,  7161,  7164,  7175,
    7182,  7188,  7191,  7198,  7205,  7211,  7212,  7218,  7219,  7220,
    7223,  7224,  7229,  7229,  7233,  7241,  7242,  7245,  7248,  7253,
    7254,  7259,  7262,  7268,  7271,  7277,  7280,  7286,  7289,  7296,
    7297,  7326,  7327,  7332,  7340,  7345,  7348,  7351,  7354,  7360,
    7361,  7365,  7368,  7371,  7372,  7377,  7380,  7383,  7386,  7389,
    7392,  7395,  7398,  7403,  7409,  7410,  7411,  7412,  7413,  7415,
    7416,  7418,  7419,  7424,  7427,  7431,  7437,  7438,  7439,  7440,
    7452,  7453,  7454,  7458,  7459,  7463,  7464,  7465,  7466,  7467,
    7469,  7471,  7472,  7473,  7474,  7475,  7476,  7477,  7478,  7480,
    7482,  7484,  7485,  7487,  7488,  7490,  7491,  7492,  7493,  7495,
    7499,  7500,  7506,  7508,  7509,  7510,  7511,  7516,  7520,  7524,
    7528,  7535,  7539,  7540,  7541,  7549,  7550,  7551,  7562,  7569,
    7574,  7575,  7576,  7584,  7585,  7586,  7603,  7612,  7613,  7614,
    7618,  7621,  7626,  7631,  7636,  7644,  7648,  7653,  7654,  7662,
    7665,  7668,  7682,  7696,  7709,  7710,  7714,  7714,  7714,  7714,
    7714,  7714,  7715,  7718,  7723,  7723,  7723,  7723,  7723,  7723,
    7725,  7728,  7734,  7734,  7734,  7734,  7734,  7734,  7734,  7735,
    7735,  7735,  7735,  7735,  7735,  7735,  7735,  7738,  7739,  7740,
    7743,  7752,  7752,  7758,  7758,  7765,  7765,  7771,  7771,  7779,
    7780,  7781,  7784,  7784,  7787,  7788,  7789,  7800,  7803,  7809,
    7814,  7821,  7834,  7835,  7832,  7853,  7864,  7867,  7872,  7884,
    7887,  7891,  7894,  7895,  7901,  7904,  7905,  7914,  7923,  7928,
    7929,  7930,  7931,  7938,  7941,  7947,  7950,  7960,  7969,  7972,
    7975,  7981,  7987,  7990,  7991,  7992,  7993,  7994,  7997,  8003,
    8005,  8007,  8009,  8011,  8013,  8014,  8015,  8016,  8017,  8018,
    8019,  8021,  8023,  8025,  8027,  8029,  8031,  8033,  8034,  8039,
    8040,  8047,  8050,  8058,  8062,  8069,  8069,  8073,  8073,  8078,
    8078,  8082,  8082,  8086,  8092,  8092,  8095,  8095,  8101,  8108,
    8109,  8110,  8114,  8115,  8118,  8119,  8123,  8129,  8139,  8140,
    8148,  8149,  8150,  8151,  8152,  8153,  8157,  8158,  8159,  8163,
    8163,  8175,  8176,  8180,  8181,  8182,  8183,  8184,  8185,  8186,
    8187,  8188,  8189,  8190,  8191,  8192,  8193,  8194,  8195,  8196,
    8197,  8198,  8199,  8200,  8201,  8202,  8203,  8204,  8205,  8206,
    8207,  8208,  8209,  8210,  8211,  8212,  8213,  8214,  8215,  8216,
    8217,  8218,  8219,  8220,  8221,  8222,  8223,  8224,  8225,  8226,
    8227,  8228,  8229,  8230,  8231,  8232,  8233,  8234,  8235,  8236,
    8237,  8238,  8239,  8240,  8241,  8242,  8243,  8244,  8245,  8246,
    8247,  8248,  8249,  8250,  8251,  8252,  8253,  8254,  8255,  8256,
    8257,  8258,  8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,
    8267,  8268,  8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,
    8277,  8278,  8279,  8280,  8281,  8282,  8283,  8284,  8285,  8286,
    8287,  8288,  8289,  8290,  8291,  8292,  8293,  8294,  8295,  8296,
    8297,  8298,  8299,  8300,  8301,  8302,  8303,  8304,  8305,  8306,
    8307,  8308,  8309,  8310,  8311,  8312,  8313,  8314,  8315,  8316,
    8317,  8318,  8319,  8320,  8321,  8322,  8323,  8324,  8325,  8326,
    8327,  8328,  8329,  8330,  8331,  8332,  8333,  8334,  8335,  8336,
    8337,  8338,  8339,  8340,  8341,  8342,  8343,  8344,  8345,  8346,
    8347,  8348,  8349,  8350,  8351,  8352,  8353,  8354,  8355,  8356,
    8357,  8358,  8359,  8360,  8361,  8362,  8363,  8364,  8365,  8366,
    8367,  8368,  8369,  8370,  8371,  8372,  8373,  8374,  8375,  8376,
    8377,  8378,  8379,  8380,  8381,  8382,  8383,  8385,  8386,  8387,
    8388,  8389,  8390,  8391,  8392,  8393,  8394,  8395,  8396,  8397,
    8398,  8399,  8400,  8401,  8402,  8403,  8404,  8405,  8406,  8407,
    8408,  8409,  8410,  8411,  8412,  8413,  8414,  8415,  8416,  8417,
    8418,  8419,  8420,  8421,  8422,  8423,  8424,  8425,  8426,  8427,
    8428,  8429,  8430,  8431,  8432,  8433,  8434,  8435,  8436,  8437,
    8438,  8439,  8440,  8441,  8442,  8443,  8444,  8445,  8446,  8447,
    8448,  8449,  8450,  8451,  8452,  8453,  8454,  8455,  8456,  8457,
    8458,  8459,  8460,  8461,  8462,  8463,  8464,  8465,  8466,  8467,
    8468,  8469,  8470,  8471,  8472,  8473,  8474,  8475,  8476,  8477,
    8478,  8479,  8480,  8481,  8482,  8483,  8484,  8485,  8486,  8487,
    8488,  8489,  8490,  8491,  8492,  8493,  8494,  8495,  8496,  8497,
    8498,  8499,  8507,  8507,  8514,  8514,  8602,  8606,  8602,  8615,
    8619,  8625,  8633,  8643,  8653,  8665,  8668,  8687,  8713,  8716,
    8722,  8725,  8730,  8733,  8741,  8749,  8762,  8765,  8773,  8776,
    8779,  8787,  8791,  8794,  8797,  8800,  8804,  8805,  8806,  8807,
    8808,  8814,  8815,  8816,  8817,  8818,  8819,  8820,  8821,  8822,
    8823,  8824,  8825,  8826,  8827,  8831,  8837,  8838,  8846,  8846,
    8854,  8854,  8858,  8862,  8877,  8897,  8899,  8905,  8906,  8907,
    8908,  8918,  8919,  8920,  8925,  8951,  9007,  9021,  9024,  9020,
    9043,  9043,  9049,  9050,  9053,  9054,  9055,  9056,  9057,  9058,
    9059,  9070,  9073,  9078,  9082,  9087,  9091,  9096,  9100,  9103,
    9107,  9110,  9115,  9119,  9130,  9136,  9136,  9137,  9138,  9145,
    9155,  9155,  9157,  9158,  9159,  9160,  9161,  9162,  9163,  9164,
    9165,  9166,  9167,  9168,  9169,  9170,  9171,  9172,  9173,  9174,
    9175,  9176,  9177,  9178,  9179,  9180,  9181,  9182,  9183,  9184,
    9185,  9186,  9187,  9188,  9189,  9190,  9191,  9192,  9193,  9194,
    9195,  9196,  9197,  9198,  9199,  9200,  9201,  9202,  9203,  9204,
    9205,  9206,  9207,  9208,  9209,  9210,  9211,  9212,  9213,  9214,
    9215,  9216,  9217,  9218,  9219,  9220,  9221,  9222,  9223,  9224,
    9225,  9226,  9227,  9228,  9229,  9230,  9231,  9232,  9233,  9234,
    9235,  9236,  9237,  9238,  9239,  9240,  9241,  9242,  9243,  9244,
    9245
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
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "exit_prog_cmd", 
  "ext_cmd", "continue_cmd", "fgl_expr_c", "fgl_next", 
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
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@175", "sql_block", 
  "sql_block_entry", "in_var", "@176", "sql_block_into", "@177", 
  "update_statement_ss", "@178", "@179", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "validate_cmd", "@180", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "whenever_cmd", "while_cmd", "@181", "@182", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "current_win_cmd", 
  "window_type", "show_cmd", "op_mnfile", "menu_name", "menu_handler", 
  "hide_cmd", "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@183", "commands_all1", 0
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
     761,   761,   761,   762,   762,   763,   763,   764,   765,   765,
     766,   766,   768,   767,   769,   767,   770,   770,   771,   771,
     772,   773,   774,   773,   775,   776,   775,   778,   777,   780,
     779,   781,   781,   781,   781,   781,   781,   782,   783,   783,
     784,   784,   785,   786,   786,   787,   788,   790,   791,   789,
     792,   792,   793,   793,   794,   794,   795,   795,   795,   796,
     796,   798,   797,   799,   797,   800,   797,   801,   797,   802,
     797,   803,   803,   804,   804,   805,   805,   805,   805,   805,
     805,   806,   807,   807,   808,   808,   809,   809,   810,   810,
     812,   813,   811,   811,   814,   814,   816,   815,   817,   817,
     817,   817,   817,   818,   817,   819,   819,   819,   819,   820,
     821,   821,   822,   822,   823,   823,   823,   823,   825,   824,
     826,   824,   827,   824,   828,   828,   829,   829,   830,   831,
     831,   831,   832,   834,   833,   835,   833,   836,   833,   837,
     837,   838,   839,   840,   840,   842,   843,   841,   844,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   845,
     844,   846,   844,   847,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   848,   848,   849,   850,   851,   852,
     852,   853,   855,   854,   856,   856,   856,   856,   856,   856,
     856,   858,   857,   859,   859,   860,   860,   861,   863,   862,
     864,   864,   864,   864,   864,   864,   864,   865,   866,   866,
     868,   867,   869,   869,   869,   869,   869,   869,   869,   869,
     869,   869,   869,   869,   869,   869,   869,   869,   869,   869,
     869,   869,   869,   869,   869,   870,   872,   871,   873,   871,
     875,   874,   876,   874,   877,   877,   878,   879,   879,   880,
     881,   881,   881,   881,   881,   881,   881,   881,   882,   883,
     884,   886,   887,   885,   888,   888,   889,   890,   890,   890,
     891,   891,   893,   892,   894,   892,   895,   892,   896,   897,
     898,   899,   899,   900,   900,   901,   901,   901,   901,   901,
     901,   901,   901,   901,   902,   902,   902,   902,   902,   902,
     902,   902,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,   905,   905,   906,   906,   907,   907,   908,
     908,   909,   909,   910,   911,   911,   912,   912,   912,   912,
     912,   912,   913,   913,   914,   914,   914,   914,   915,   915,
     916,   917,   917,   917,   918,   917,   919,   919,   920,   920,
     921,   921,   921,   921,   922,   922,   923,   923,   923,   923,
     923,   923,   923,   923,   924,   925,   926,   926,   926,   926,
     926,   926,   927,   927,   927,   927,   927,   927,   927,   928,
     930,   931,   929,   932,   933,   929,   935,   936,   934,   937,
     938,   934,   939,   940,   934,   941,   942,   934,   934,   934,
     934,   934,   934,   934,   943,   943,   944,   945,   945,   945,
     945,   945,   945,   945,   945,   945,   946,   946,   947,   947,
     947,   947,   948,   948,   948,   949,   949,   950,   950,   950,
     951,   951,   951,   951,   951,   951,   951,   951,   951,   951,
     952,   952,   953,   953,   954,   954,   956,   957,   958,   955,
     959,   959,   961,   962,   960,   963,   963,   964,   964,   965,
     965,   967,   966,   968,   966,   969,   969,   970,   970,   972,
     971,   973,   971,   974,   975,   975,   975,   976,   976,   977,
     977,   978,   978,   979,   979,   981,   980,   982,   980,   983,
     980,   984,   980,   985,   980,   987,   988,   986,   989,   989,
     990,   991,   991,   991,   991,   991,   991,   991,   992,   992,
     993,   994,   995,   996,   996,   996,   996,   996,   996,   996,
     996,   997,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1004,  1005,  1006,  1007,  1007,  1008,  1008,  1009,  1009,  1009,
    1009,  1009,  1009,  1010,  1011,  1011,  1012,  1013,  1013,  1014,
    1015,  1015,  1016,  1017,  1018,  1018,  1018,  1019,  1019,  1019,
    1021,  1020,  1022,  1022,  1023,  1023,  1024,  1024,  1025,  1026,
    1026,  1027,  1028,  1028,  1029,  1030,  1030,  1031,  1032,  1032,
    1034,  1035,  1033,  1036,  1037,  1036,  1038,  1039,  1036,  1040,
    1040,  1041,  1043,  1042,  1042,  1044,  1044,  1045,  1045,  1046,
    1047,  1047,  1047,  1048,  1048,  1049,  1049,  1051,  1050,  1052,
    1050,  1053,  1050,  1054,  1050,  1055,  1050,  1056,  1050,  1057,
    1050,  1058,  1050,  1059,  1050,  1060,  1050,  1061,  1050,  1062,
    1050,  1063,  1050,  1064,  1064,  1065,  1065,  1066,  1067,  1068,
    1068,  1068,  1070,  1069,  1071,  1071,  1072,  1071,  1073,  1074,
    1074,  1074,  1074,  1075,  1075,  1076,  1077,  1077,  1077,  1077,
    1077,  1077,  1077,  1077,  1077,  1079,  1078,  1078,  1081,  1080,
    1082,  1083,  1084,  1084,  1085,  1085,  1086,  1087,  1087,  1087,
    1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,
    1087,  1087,  1087,  1087,  1087,  1088,  1090,  1091,  1089,  1092,
    1092,  1093,  1094,  1095,  1096,  1096,  1098,  1097,  1099,  1099,
    1100,  1100,  1101,  1101,  1101,  1101,  1101,  1101,  1102,  1102,
    1103,  1103,  1104,  1105,  1105,  1105,  1105,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,  1106,  1107,  1107,  1108,  1109,  1109,
    1111,  1112,  1113,  1114,  1110,  1115,  1117,  1118,  1116,  1119,
    1120,  1120,  1121,  1121,  1122,  1123,  1123,  1124,  1126,  1125,
    1127,  1127,  1127,  1127,  1129,  1130,  1131,  1128,  1133,  1134,
    1132,  1135,  1135,  1137,  1136,  1138,  1136,  1140,  1139,  1141,
    1143,  1142,  1144,  1142,  1145,  1142,  1146,  1146,  1147,  1147,
    1148,  1148,  1149,  1149,  1149,  1150,  1151,  1152,  1153,  1153,
    1153,  1154,  1154,  1155,  1155,  1156,  1157,  1157,  1157,  1157,
    1158,  1158,  1158,  1158,  1158,  1159,  1160,  1160,  1161,  1162,
    1163,  1163,  1164,  1165,  1165,  1165,  1165,  1165,  1165,  1166,
    1167,  1168,  1168,  1169,  1169,  1170,  1171,  1172,  1172,  1173,
    1173,  1174,  1175,  1176,  1176,  1176,  1176,  1176,  1176,  1177,
    1177,  1178,  1179,  1179,  1180,  1180,  1181,  1181,  1182,  1182,
    1183,  1183,  1183,  1183,  1183,  1184,  1184,  1185,  1185,  1186,
    1186,  1187,  1188,  1189,  1189,  1190,  1191,  1191,  1191,  1192,
    1193,  1193,  1194,  1194,  1195,  1196,  1196,  1197,  1197,  1198,
    1199,  1200,  1201,  1201,  1202,  1203,  1203,  1204,  1204,  1205,
    1205,  1206,  1207,  1207,  1208,  1208,  1208,  1208,  1209,  1209,
    1209,  1210,  1211,  1211,  1212,  1212,  1212,  1213,  1214,  1214,
    1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,  1215,
    1215,  1215,  1215,  1215,  1215,  1215,  1216,  1217,  1217,  1218,
    1218,  1218,  1218,  1218,  1219,  1221,  1220,  1222,  1222,  1223,
    1224,  1224,  1225,  1225,  1226,  1226,  1228,  1227,  1229,  1231,
    1230,  1232,  1232,  1233,  1233,  1234,  1234,  1235,  1235,  1235,
    1235,  1236,  1236,  1237,  1238,  1238,  1239,  1240,  1241,  1242,
    1243,  1243,  1244,  1244,  1246,  1245,  1247,  1245,  1248,  1245,
    1249,  1245,  1250,  1245,  1251,  1245,  1252,  1245,  1253,  1253,
    1253,  1253,  1253,  1253,  1255,  1254,  1256,  1256,  1258,  1257,
    1257,  1257,  1257,  1257,  1259,  1259,  1260,  1260,  1261,  1262,
    1262,  1264,  1263,  1265,  1266,  1267,  1267,  1267,  1268,  1268,
    1268,  1268,  1269,  1270,  1270,  1271,  1271,  1272,  1273,  1273,
    1273,  1273,  1273,  1273,  1273,  1273,  1274,  1274,  1275,  1275,
    1276,  1276,  1276,  1276,  1276,  1276,  1276,  1276,  1276,  1276,
    1277,  1277,  1278,  1278,  1278,  1278,  1279,  1279,  1280,  1280,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1282,  1282,  1282,  1284,  1285,  1286,
    1287,  1288,  1289,  1283,  1290,  1290,  1291,  1292,  1292,  1294,
    1295,  1296,  1297,  1298,  1299,  1293,  1300,  1302,  1303,  1304,
    1301,  1305,  1305,  1305,  1305,  1306,  1306,  1306,  1306,  1306,
    1307,  1308,  1308,  1308,  1308,  1309,  1309,  1311,  1312,  1310,
    1313,  1314,  1310,  1315,  1315,  1316,  1316,  1317,  1317,  1317,
    1317,  1317,  1318,  1319,  1319,  1320,  1320,  1321,  1321,  1322,
    1322,  1322,  1322,  1322,  1323,  1323,  1324,  1324,  1325,  1325,
    1325,  1326,  1326,  1327,  1327,  1328,  1328,  1329,  1329,  1329,
    1330,  1330,  1331,  1331,  1331,  1331,  1331,  1331,  1331,  1332,
    1332,  1333,  1333,  1334,  1334,  1335,  1335,  1336,  1336,  1337,
    1338,  1338,  1339,  1339,  1340,  1341,  1341,  1342,  1343,  1343,
    1344,  1344,  1345,  1345,  1346,  1346,  1347,  1347,  1348,  1349,
    1349,  1349,  1349,  1349,  1349,  1349,  1349,  1349,  1349,  1349,
    1350,  1350,  1351,  1351,  1352,  1353,  1355,  1354,  1357,  1356,
    1356,  1358,  1358,  1359,  1359,  1360,  1360,  1361,  1361,  1363,
    1362,  1364,  1365,  1365,  1366,  1367,  1366,  1368,  1369,  1368,
    1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,  1371,  1372,
    1373,  1374,  1374,  1375,  1376,  1376,  1377,  1377,  1377,  1378,
    1379,  1380,  1380,  1381,  1382,  1382,  1382,  1384,  1383,  1385,
    1385,  1385,  1385,  1385,  1385,  1385,  1385,  1385,  1385,  1385,
    1385,  1386,  1386,  1386,  1386,  1387,  1387,  1387,  1388,  1388,
    1388,  1389,  1389,  1389,  1390,  1390,  1391,  1391,  1391,  1391,
    1391,  1391,  1392,  1392,  1393,  1393,  1394,  1394,  1395,  1395,
    1396,  1397,  1397,  1398,  1398,  1399,  1399,  1400,  1401,  1402,
    1403,  1404,  1404,  1405,  1405,  1406,  1406,  1406,  1407,  1407,
    1408,  1408,  1408,  1409,  1409,  1409,  1409,  1410,  1411,  1411,
    1412,  1412,  1413,  1413,  1414,  1415,  1415,  1415,  1415,  1415,
    1415,  1415,  1416,  1417,  1418,  1419,  1419,  1420,  1420,  1421,
    1422,  1423,  1423,  1424,  1425,  1426,  1426,  1427,  1427,  1427,
    1428,  1428,  1429,  1429,  1430,  1431,  1431,  1432,  1432,  1433,
    1433,  1434,  1434,  1435,  1435,  1436,  1436,  1437,  1437,  1438,
    1438,  1439,  1439,  1440,  1441,  1442,  1442,  1442,  1442,  1443,
    1443,  1444,  1444,  1445,  1445,  1446,  1446,  1446,  1446,  1446,
    1446,  1446,  1446,  1446,  1447,  1447,  1447,  1447,  1447,  1447,
    1447,  1447,  1447,  1448,  1448,  1448,  1449,  1449,  1449,  1449,
    1450,  1450,  1450,  1451,  1451,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,  1452,
    1453,  1453,  1454,  1454,  1454,  1454,  1454,  1455,  1456,  1457,
    1458,  1458,  1458,  1458,  1458,  1458,  1458,  1458,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1460,  1461,  1461,  1461,
    1462,  1462,  1463,  1463,  1463,  1464,  1465,  1465,  1465,  1465,
    1466,  1467,  1468,  1468,  1469,  1469,  1470,  1470,  1470,  1470,
    1470,  1470,  1470,  1470,  1471,  1471,  1471,  1471,  1471,  1471,
    1471,  1471,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1474,  1474,  1474,
    1475,  1477,  1476,  1478,  1476,  1479,  1476,  1480,  1476,  1481,
    1481,  1481,  1482,  1482,  1483,  1483,  1483,  1484,  1484,  1485,
    1485,  1486,  1488,  1489,  1487,  1490,  1491,  1491,  1492,  1493,
    1493,  1493,  1493,  1493,  1494,  1495,  1495,  1496,  1497,  1498,
    1498,  1498,  1498,  1499,  1499,  1500,  1500,  1501,  1502,  1502,
    1502,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1504,  1505,
    1505,  1506,  1507,  1508,  1508,  1509,  1509,  1510,  1510,  1511,
    1511,  1512,  1512,  1513,  1514,  1514,  1515,  1515,  1516,  1517,
    1517,  1517,  1518,  1518,  1519,  1520,  1521,  1522,  1523,  1523,
    1524,  1524,  1524,  1524,  1524,  1524,  1525,  1525,  1525,  1527,
    1526,  1528,  1528,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1531,  1530,  1533,  1532,  1535,  1536,  1534,  1537,
    1537,  1537,  1538,  1538,  1538,  1538,  1538,  1538,  1539,  1539,
    1540,  1541,  1542,  1542,  1543,  1543,  1544,  1544,  1545,  1545,
    1545,  1546,  1546,  1546,  1546,  1546,  1546,  1546,  1546,  1546,
    1546,  1547,  1547,  1547,  1547,  1547,  1547,  1547,  1547,  1547,
    1547,  1547,  1547,  1547,  1547,  1548,  1549,  1549,  1551,  1550,
    1552,  1552,  1553,  1553,  1554,  1555,  1555,  1556,  1556,  1556,
    1556,  1557,  1557,  1557,  1558,  1558,  1559,  1561,  1562,  1560,
    1563,  1563,  1564,  1564,  1565,  1565,  1565,  1565,  1565,  1565,
    1565,  1566,  1566,  1567,  1567,  1568,  1568,  1569,  1569,  1570,
    1571,  1572,  1573,  1573,  1574,  1575,  1575,  1576,  1577,  1577,
    1579,  1578,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,  1580,
    1580
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
       1,     3,     0,     6,     0,     5,     1,     2,     1,     2,
       1,     0,     0,     3,     0,     0,     3,     0,     4,     0,
       4,     2,     2,     2,     1,     2,     2,     3,     1,     1,
       1,     2,     1,     1,     2,     1,     1,     0,     0,     5,
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
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     3,
       4,     4,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     0,     3,     2,     2,     1,     3,
       4,     4,     5,     5,     1,     1,     2,     2,     4,     4,
       2,     2,     4,     4,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       0,     0,     6,     0,     0,     8,     0,     0,     6,     0,
       0,     6,     0,     0,     6,     0,     0,     6,     5,     5,
       5,     7,     4,     6,     0,     3,     1,     1,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     4,     4,
       2,     2,     2,     2,     2,     1,     1,     2,     1,     1,
       1,     2,     4,     6,     6,     3,     5,     5,     3,     1,
       1,     3,     1,     3,     1,     3,     0,     0,     0,     9,
       0,     3,     0,     0,    10,     0,     1,     0,     1,     1,
       2,     0,     3,     0,     3,     0,     1,     1,     2,     0,
       3,     0,     3,     3,     1,     4,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     0,     3,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     0,    11,     0,     2,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     4,     6,     4,     3,     6,     3,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     4,     1,     1,     1,     4,     3,
       6,     3,     6,     1,     1,     2,     2,     1,     2,     2,
       1,     3,     1,     2,     2,     2,     4,     2,     2,     4,
       0,     8,     0,     1,     1,     1,     0,     1,     2,     0,
       1,     2,     0,     1,     2,     0,     1,     3,     0,     2,
       0,     0,     8,     0,     0,     3,     0,     0,     7,     5,
       2,     2,     0,     5,     4,     1,     3,     3,     3,     1,
       0,     2,     1,     0,     1,     1,     2,     0,     4,     0,
       4,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     1,     3,     1,     3,     2,     4,     1,
       1,     1,     0,     4,     5,     6,     0,    10,     3,     2,
       2,     1,     1,     0,     2,     1,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     0,     3,     1,     0,     3,
       2,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     7,     1,
       1,     2,     2,     2,     3,     4,     0,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       0,     0,     0,     0,    13,     1,     0,     0,     6,     2,
       1,     2,     2,     2,     1,     1,     2,     1,     0,     3,
       2,     1,     1,     1,     0,     0,     0,    14,     0,     0,
       7,     1,     2,     0,     3,     0,     4,     0,     5,     1,
       0,     3,     0,     7,     0,     5,     1,     2,     0,     1,
       1,     1,     0,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     2,     2,     2,     5,     8,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     2,     2,     3,     6,     1,
       3,     1,     1,     1,     3,     6,     9,     1,     1,     1,
       1,     2,     0,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     2,     0,     1,     1,     4,
       1,     3,     1,     3,     7,     0,     7,     0,     6,     3,
       1,     3,     1,     2,     5,     0,     7,     0,     2,     0,
       1,     5,     2,     5,     0,     5,     6,     4,     0,     1,
       1,     5,     0,     2,     0,     5,     4,     2,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     1,     1,     2,
       4,     4,     6,     2,     1,     0,    11,     0,     2,     5,
       0,     1,     0,     2,     1,     2,     0,     3,     1,     0,
       4,     0,     2,     1,     3,     1,     1,     3,     4,     4,
       2,     1,     1,     1,     0,     1,     7,     2,     2,     2,
       2,     2,     1,     2,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     1,     0,     4,
       1,     2,     2,     2,     0,     1,     1,     2,     2,     0,
       2,     0,     4,     3,     5,     0,     2,     4,     1,     1,
       1,     1,     1,     0,     1,     1,     3,     2,     5,     2,
       5,     5,     5,     5,     5,     5,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     1,     1,     1,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     0,     3,     2,     0,     0,     0,
       0,     0,     0,    15,     0,     2,     2,     0,     1,     0,
       0,     0,     0,     0,     0,    15,     2,     0,     0,     0,
      10,     0,     1,     3,     3,     2,     4,     3,     3,     3,
       1,     2,     2,     2,     2,     1,     1,     0,     0,     8,
       0,     0,     9,     0,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     0,     1,     1,     2,     2,     2,     8,
       2,     2,     4,     2,     0,     1,     1,     3,     2,     2,
       1,     1,     3,     1,     1,     2,     1,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     3,     1,     3,     2,     4,     1,     3,     1,
       2,     4,     1,     3,     1,     1,     1,     2,     3,     4,
       2,     4,     0,     2,     2,     4,     1,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     6,     6,
       0,     1,     0,     1,     2,     1,     0,     5,     0,     5,
       1,     0,     3,     1,     3,     1,     3,     1,     1,     0,
       4,     1,     2,     1,     0,     0,     3,     0,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     3,
       3,     1,     3,     2,     1,     1,     0,     1,     1,     1,
       1,     0,     1,     3,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     6,     4,     4,     1,     1,     1,     0,     1,
       2,     1,     1,     1,     1,     3,     2,     1,     1,     2,
       1,     1,     0,     3,     1,     3,     1,     3,     1,     1,
       6,     0,     3,     1,     3,     0,     1,     4,     5,     2,
       1,     1,     4,     1,     3,     4,     4,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     4,     0,     1,
       0,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     2,
       2,     1,     3,     2,     2,     1,     3,     1,     2,     4,
       1,     2,     1,     3,     4,     0,     1,     0,     1,     0,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     2,
       2,     0,     2,     1,     1,     5,     3,     5,     3,     1,
       3,     1,     1,     0,     1,     3,     3,     3,     6,     4,
       4,     4,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     4,     1,     5,
       5,     1,     1,     1,     1,     1,     4,     1,     4,     6,
       4,     1,     4,     1,     7,     1,     1,     1,     4,     6,
       0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     5,     3,     5,     7,     3,     1,
       1,     3,     5,     3,     5,     7,     1,     0,     3,     5,
       1,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       2,     2,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     0,     7,     0,     8,     0,     6,     0,     8,     0,
       1,     2,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     1,     0,     0,     9,     5,     1,     1,     6,     0,
       3,     1,     3,     4,     1,     0,     2,     4,     6,     0,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     2,     2,     2,     2,     4,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     4,     4,     3,     4,     1,
       3,     1,     5,     7,     5,     0,     2,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     0,     3,     1,     1,
       1,     1,     4,     6,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     4,     0,
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
       1,     1,     0,     3,     0,     3,     0,     0,     6,     0,
       2,     2,     7,     3,     3,     2,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       2,     1,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     3,     5,     5,     5,     5,
       5,     4,     4,     3,     4,     1,     1,     3,     0,     5,
       1,     3,     3,     3,     1,     2,     1,     1,     1,     3,
       5,     1,     1,     1,     1,     3,     1,     0,     0,     6,
       0,     2,     0,     1,     1,     2,     2,     1,     1,     4,
       3,     1,     2,     5,     2,     2,     5,     0,     2,     1,
       1,     2,     6,     6,     1,     0,     1,     2,     1,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     818,     0,  2196,     0,     0,     0,   868,   180,     0,   844,
     847,   178,   183,   822,     0,   816,   819,   820,   823,   826,
     827,   825,   864,   865,   867,   824,   135,   132,     0,   128,
     130,   129,   133,  2224,   701,   641,   310,  1679,  1677,   862,
     176,   186,   863,   179,     1,   828,   821,   866,   127,   131,
     134,     0,     0,   618,     0,     0,   177,   871,   937,   619,
     872,   873,   869,   653,   929,     0,   930,   938,   936,   186,
     181,   199,     0,   184,   200,   235,     0,   849,  1229,     0,
       0,   848,   136,  1217,   856,     0,     0,   840,   842,   839,
     841,   817,   829,   830,   850,   833,   834,   835,   838,   836,
     837,   843,     0,  1678,   931,   870,     0,     0,   945,   943,
     944,   933,   932,   308,   186,  1153,   193,   187,   186,   192,
     232,     0,   700,     0,     0,     0,     0,   176,   562,   878,
     831,     0,   342,   328,   202,   314,   279,   298,   319,   321,
     318,     0,   340,     0,   327,   320,   324,   330,   329,   186,
     331,   311,   334,   312,   313,   942,   941,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     951,     0,   525,   517,    16,   524,   937,    15,     0,   949,
       0,   309,     0,   185,  1154,   182,     0,   199,   201,   273,
     204,   261,   267,   268,   252,   225,   263,   202,   240,   241,
       0,   227,   279,   298,   250,   253,   248,     0,   223,     0,
     259,   251,   256,   266,   265,   186,   269,   186,   238,   239,
     236,   272,     0,     0,     0,     0,   857,   176,   176,     0,
       0,   203,     0,     0,   332,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,   277,     0,   939,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     531,     0,     0,     0,   654,   444,   446,  1224,     0,     0,
       0,  1644,     0,   438,     0,     0,     0,   437,     0,   454,
     527,     0,     0,     0,     0,     0,   530,     0,   403,   402,
     409,   450,   447,   404,   405,   407,   408,   445,   448,   453,
     526,   499,   496,   505,   502,     0,     0,    17,    18,    19,
      20,    21,     0,    14,   490,     0,     0,   947,     0,   188,
     191,   189,   190,     0,   196,   195,   194,   197,   205,   206,
     207,   210,   274,   186,   274,     0,     0,     0,     0,   186,
     270,   271,     0,     0,   186,     0,   274,     0,     0,   249,
     233,  1230,     0,     0,  1218,  2230,   563,   879,   851,     0,
     214,   215,     0,     0,   291,   293,   288,   289,   285,   287,
     284,   286,   283,     0,   293,   304,   305,   301,   303,   300,
     302,   295,     0,     0,     0,   344,     0,   347,   349,   222,
       0,   221,     0,   186,     0,     0,   552,   623,     0,     0,
       0,     0,     0,     0,     0,     0,   549,   535,   540,     0,
     536,   539,   538,   632,     0,   631,   554,     0,    11,   172,
     436,   411,   410,     0,  1159,     0,     0,   452,  1652,  1650,
    1651,  1647,  1649,  1646,  1648,  1640,     0,     0,     0,   451,
       0,     0,     0,     0,     0,     0,     0,   655,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   532,   533,   534,   465,     0,     0,   464,   474,     0,
       0,   415,     0,     0,   416,   406,   412,   414,   417,   418,
     419,   420,   421,   413,   443,   442,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   950,     0,   934,   198,
       0,     0,   262,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,   186,   234,   237,   962,
     699,   874,   962,     0,  2228,  2230,  1153,  1776,   845,     0,
     962,     0,     0,   315,   280,     0,     0,   290,   307,   281,
     306,     0,   299,     0,   322,     0,   316,     0,   341,     0,
     346,   336,     0,     0,   325,   278,   335,     0,     0,   523,
       0,     0,   520,   519,   522,   518,   529,   514,   514,     0,
     537,     0,   541,     0,   298,     0,   521,   528,   282,     0,
    1225,  1719,     0,     0,     0,     0,     0,   439,     0,     0,
     455,     0,     0,     0,     0,   457,   456,   475,   466,   481,
     484,   485,   482,   488,   487,   486,   476,   477,   478,   479,
     480,   422,   467,   471,   489,   483,   470,   489,   449,   500,
     497,   506,   503,   512,     0,   491,    94,    95,    97,   493,
       0,     0,   235,     0,     0,     0,   242,   243,     0,   246,
       0,     0,   254,     0,   244,   224,   208,     0,   257,   276,
     968,     0,   963,   964,   962,     0,   858,  2229,  2227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2211,     0,  1345,  1344,     0,  1346,
       0,   398,  1343,  1260,     0,     5,  1342,   399,   396,     0,
     401,   174,   489,  1130,     0,     0,  1352,   124,   395,   394,
       0,     0,   389,   489,     0,  1296,  2204,     0,   400,   361,
       0,     3,     2,     0,   397,  1257,     0,     0,   390,   387,
     383,     0,     0,     0,     0,  1350,  1340,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1339,     0,     0,     0,
     175,     0,   386,   385,     0,     0,  2208,  2207,     0,     0,
       0,   137,     0,   392,   391,     0,     0,   388,   489,     0,
       0,   489,     0,   556,     0,     0,     0,     0,     0,     0,
     489,   805,  1227,     0,     0,  1141,     0,  2197,     0,   104,
       0,     0,   887,     0,     0,     0,     0,   806,     0,     0,
    1799,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     670,     0,     0,  2232,  2233,  2234,  2235,  2236,  2237,  2238,
    2239,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,  2248,
    2249,  2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,  2258,
    2259,  2260,  2261,  2262,  2263,  2264,  2265,  2266,  2267,  2268,
    2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,  2277,  2278,
    2279,  2280,  2281,   916,  2282,  2283,  2284,  2285,  2286,  2287,
    2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,
    2298,  1121,  1123,  1118,  1120,  1119,  1122,  2299,  2300,  1250,
    2301,  1256,  1255,  2302,  2303,  2304,  2305,  2306,  2307,  2308,
    2309,  2310,  2311,  1407,  2312,  2313,  2314,  2315,  2316,  2317,
    2318,  2319,  2320,  2231,   846,   567,     0,   883,     0,   881,
       0,   343,   216,   217,     0,   292,   297,     0,     0,     0,
       0,   345,   348,     0,   220,     0,     0,   553,     0,   627,
       0,   629,   509,     0,   510,     0,   551,     0,   548,   545,
     516,   508,   555,     0,   171,  1721,  1722,  1720,     0,   441,
    1224,     0,  1645,  1224,   440,  1224,  1224,  1224,  1224,  1224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   948,     0,   211,   275,
     226,     0,     0,   186,     0,     0,     0,     0,     0,  1231,
       0,     0,  1219,   380,   378,   379,  1254,  1058,  1057,  1063,
       0,  1619,  1620,     0,     0,  1280,   642,   643,  1281,  1611,
    1612,  1283,   832,  1093,  1098,  2206,   635,   123,  2219,     0,
       0,  1295,     7,     0,     6,     0,  2212,  1094,     0,  1187,
    1186,  1133,  1185,  1132,   433,  1353,  1341,     0,  1251,   859,
     423,  1778,  1347,   125,     0,  1097,   122,     0,   812,    24,
     637,   384,     0,   811,  1090,   813,     0,  1351,   909,   908,
     911,   907,   910,  2221,     0,   905,     0,   636,   995,   906,
    2215,     0,  2205,   121,  1253,   992,   702,   990,     0,   633,
    2200,   750,   749,   751,   747,     0,     0,  1252,  1005,   638,
    1406,     0,  2188,  2187,  1401,  1404,  2184,  2186,     0,     0,
       0,     0,  1064,  1059,     0,  1044,  1045,  1046,  1047,  1053,
    1055,  1054,  1052,  1051,     0,     0,     0,  1050,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1036,  1027,  1028,   977,     0,   975,  1078,   431,    24,
       0,  2202,   126,   634,     0,  1228,  1226,  1152,     0,  1767,
    1768,  1153,  1134,  1354,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,   937,     0,    69,     0,   102,   610,
       0,   657,   656,     0,  1124,  1012,  1128,     0,     0,  1079,
    1245,     0,     0,  1131,   662,   659,   660,     0,   664,   665,
       0,   667,   668,     0,   663,   972,   974,     0,     0,   973,
     752,   970,   713,   966,   928,     0,     0,     0,     0,   674,
     675,     0,     0,   926,   923,   924,   920,   921,   922,   915,
     919,   918,     0,     0,     0,     0,     0,     0,   571,   573,
     565,   568,   569,   885,  2230,   880,   882,   852,     0,   294,
     296,   323,   317,     0,     0,   326,   624,   626,     0,     0,
     514,   542,     0,   291,     0,     0,  1748,  1636,  1638,  1749,
    1642,  1746,     0,     0,  1745,     0,     0,     0,  1747,     0,
       0,     0,     0,     0,     0,     0,  2188,  1637,  1744,  1639,
    1733,     0,  1723,  1725,  1728,  1731,  2194,  1732,  1162,  1653,
    1161,  1160,  1163,  1165,  1164,  1158,   468,   469,   473,   458,
       0,   461,   472,     0,   460,   501,   498,   507,   504,   513,
     492,    96,   494,   935,     0,   247,   231,     0,   229,   255,
     245,   235,   258,   969,   176,   965,   875,   176,     0,     0,
       0,  1325,  1326,     0,     0,     0,  1297,  1300,  1302,  1303,
    1304,  1308,  1307,  1305,  1306,     0,     0,     0,  1298,  1299,
       0,     0,     0,     0,     0,     0,     0,     0,  1095,     0,
      24,  1182,  1184,  1183,     0,   426,   427,   424,   425,   982,
       0,     0,   366,    25,   360,     0,     0,  1087,     0,     0,
       0,     0,     0,     0,     0,   999,  1777,     0,     0,     0,
       0,     0,     0,  2202,     0,     0,   138,     0,     0,  1009,
    1001,  1002,  1007,     0,     0,  2185,   946,  1402,  1403,     0,
       0,   925,   429,  2178,  1022,   350,     0,     0,   557,   615,
     614,   612,   617,  1030,   616,  1035,  1031,  1034,   804,   796,
     790,   802,   803,   788,   789,   797,   792,   798,   791,   801,
     795,   799,   794,   800,   787,   793,   780,   786,  1032,  1033,
       0,  1040,  1048,  1037,  1038,  1042,  1043,  1041,  1039,  1049,
       0,     0,     0,   814,     0,     0,     0,     0,     0,   762,
     761,   758,  2203,  2210,    24,  1148,  1149,  1150,  1151,  1145,
    1143,  1241,  1153,  1135,  1136,  1139,  1155,  2198,     0,     0,
       0,     0,    98,     0,    99,     0,     0,     0,    74,     0,
       0,     0,   111,   106,     0,   658,   914,     0,   913,     0,
     489,  1126,     0,   957,   958,   981,   952,   953,   807,   979,
    1081,  1247,     0,  1249,  1248,  1855,  1972,  1968,  1974,  2006,
    1986,  1977,  1936,  1898,  2025,  1992,  2000,  1889,  1995,  1856,
    1803,  1987,  1894,  1945,  2079,  1924,  1912,  1925,  2023,  2026,
    1994,  1948,  2029,  1815,  2086,  2022,  2050,  1826,  2122,  1913,
    2095,  1808,  2055,  1824,  1884,  1931,  1951,  2045,  2073,  2078,
    1807,  2003,  2031,  1819,  1821,  1844,  1862,  1882,  1892,  1902,
    1955,  1958,  2016,  2027,  2033,  2034,  2051,  2096,  2107,  1806,
    1837,  1861,  1860,  1868,  1870,  1878,  1888,  1909,  1927,  1930,
    1956,  1964,  2020,  2030,  2040,  2046,  2047,  2049,  2074,  2104,
    2115,  1827,  1830,  1841,  1847,  1849,  1854,  1857,  1859,  1865,
    1873,  1875,  1876,  1877,  1887,  1897,  1904,  1920,  1921,  1932,
    1950,  1954,  1967,  1983,  2014,  2024,  2028,  2035,  2043,  2052,
    2062,  2066,  2083,  2089,  2093,  2101,  2106,  2109,  1850,  1969,
    2011,  1835,  1836,  1853,  1858,  1864,  1866,  1880,  1881,  1891,
    1900,  1905,  1907,  1908,  1914,  1922,  1939,  1940,  1953,  1981,
    1985,  1988,  1993,  1997,  2005,  2012,  2013,  2018,  2036,  2037,
    2042,  2048,  2053,  2059,  2060,  2061,  2063,  2065,  2067,  2076,
    2098,  2099,  2100,  2105,  2121,  1810,  1963,  1971,  1973,  2069,
    1812,  1816,  1820,  1825,  1831,  1832,  1845,  1846,  1848,  1851,
    1863,  1879,  1899,  1901,  1911,  1915,  1917,  1918,  1926,  1935,
    1937,  1938,  1949,  1962,  1980,  1998,  1999,  2015,  2017,  2021,
    2032,  2054,  2064,  2072,  2094,  2097,  2111,  2112,  2113,  1843,
    1813,  1833,  1834,  1840,  1910,  1842,  1867,  1869,  1883,  1960,
    2084,  1893,  1895,  1903,  1906,  1928,  1929,  1934,  1941,  1942,
    1943,  2124,  1975,  1976,  1979,  1984,  1989,  1996,  2001,  2002,
    2004,  2010,  2039,  2041,  2057,  2068,  2070,  2071,  2075,  2080,
    2081,  2085,  2087,  2088,  2103,  2108,  2110,  2114,  2116,  2120,
    1970,  2119,  1809,  1811,  1814,  1818,  1828,  1852,  1871,  1872,
    1874,  1885,  1916,  1919,  1959,  1965,  1978,  1982,  2117,  2118,
    2019,  2038,  2044,  2056,  2058,  2077,  2082,  2092,  2102,  1823,
    1817,  1822,  1839,  1890,  1933,  1946,  1947,  2007,  2009,  2091,
    1966,  1923,  1990,  1838,  1886,  1896,  1961,  1944,  1991,  1829,
    1952,  1957,  2090,  2008,     0,  1801,  1804,  1805,   690,     0,
       0,     0,   679,   713,   713,   710,     0,     0,   714,     0,
      26,   678,   681,     0,   688,   684,   927,   917,  1774,  1775,
    1765,  1765,  1371,     0,     0,  1680,     0,     0,  1355,     0,
       0,  1356,  1399,     0,     0,  1400,     0,     0,  1719,     0,
    1369,     0,  1418,  1417,  1416,  1414,  1415,  1413,  1411,  1408,
    1498,  1497,  1409,  1410,  1419,  1701,  1412,  1781,  1780,  1779,
    1420,  2230,  2230,   584,   575,   566,     0,   570,  2230,   884,
     176,     0,   337,   219,     0,     0,  1660,  1658,  1659,  1655,
    1657,  1654,  1656,   515,   511,     0,   547,   546,   173,  1730,
    1729,  1668,  1666,  1667,  1663,  1665,  1662,  1664,  1641,     0,
    1719,     0,     0,  1566,     0,     0,  1736,  1734,  1735,  1566,
    1566,  1566,  1566,  1737,     0,     0,     0,  1515,  1709,  1726,
       0,     0,     0,     0,  1790,  1791,  1792,  1793,  1794,  1795,
    1740,     0,     0,   463,   462,     0,     0,   186,   228,   209,
    1232,   176,  1220,     0,     0,     0,     0,     0,     0,  1472,
    1471,  1470,  1332,     0,  1338,  1334,  1336,  1327,     0,  1575,
    1324,  1320,  1294,  1293,     0,  1319,  1315,     0,  1311,  1309,
       0,  1618,     0,  1621,  1623,   646,     0,   645,  1610,     0,
    1613,  1615,  2220,  2217,     0,     0,  1261,   489,   358,  1282,
       0,     0,  1258,  1014,  1091,  1092,  1089,  1088,     0,   912,
       0,     0,   620,     0,     0,     0,   993,   991,   704,   705,
       0,   709,     0,     0,  2201,  2209,   748,     0,   142,     0,
    1003,  1010,     0,     0,  1018,     0,  1405,  2191,  2193,  2192,
    2189,     0,     0,     0,  1024,   353,     0,     0,     0,     0,
      24,  1060,  1061,   560,     0,     0,     0,   781,   782,  1029,
     978,   976,   815,   432,     0,  1070,   759,   760,   381,     0,
    1153,  1242,  1157,  1142,  1137,     0,     0,  1138,  2230,     0,
       0,     0,     0,     0,     0,     0,    64,    93,     0,     0,
     117,   112,     0,   107,     0,   114,   108,   898,   890,   896,
       0,  1125,     0,  1127,  1129,     0,     0,   961,     0,     0,
       0,     0,  1080,  1246,     0,     0,  1800,  1802,  2230,   661,
     666,   669,   682,   680,   639,     0,   733,   731,   741,   739,
     737,   735,     0,     0,   729,   777,   727,   712,   723,   721,
     775,   753,     0,   715,   725,   971,   967,     0,     0,     0,
       0,   687,     0,     0,     0,     0,     0,     0,     0,  1626,
       0,  1493,  1494,  1786,  1451,  1515,     0,     0,     0,  1784,
       0,  1431,  1426,  1425,  1438,  1437,  1442,  1442,  1440,  1441,
    1432,  1427,     0,     0,  1433,  1434,  1702,  2126,     0,     0,
       0,   572,   574,     0,     0,   587,   579,   581,     0,   576,
     577,     0,     0,   595,   597,     0,     0,   593,   886,   853,
     218,     0,   628,   630,   625,     0,   544,   543,     0,     0,
    1757,     0,     0,     0,  1568,  1569,  1567,     0,  1759,     0,
       0,     0,     0,     0,     0,     0,  1724,     0,  1504,  1505,
    1507,  1510,     0,  1516,  1517,     0,     0,  1566,  1711,  1705,
    1742,  1743,  1741,  1739,  2195,   459,   495,     0,   230,  1188,
     876,  1166,     0,     0,     0,     0,  1332,     0,     0,     0,
    1328,     0,     0,     0,  1322,  1606,  1604,  1573,  1585,  1587,
    1591,  1593,  1584,  1578,  1583,  1597,  1576,  1605,  1581,  1596,
    1582,  1603,  1595,  1478,  1570,  1571,  1572,     0,  1317,  1313,
       0,     0,  1301,     0,     0,   644,     0,     0,     0,  2216,
       0,     4,     8,    10,     0,   489,   428,     0,     0,     0,
    1011,     0,     0,     0,     0,     0,     0,     0,     0,   703,
       0,     0,   159,   157,     0,     0,   139,     0,   149,   155,
     713,   144,   146,     0,  1008,  1019,  1020,     0,     0,     0,
     430,     0,  2179,  2180,  1023,     0,     0,  1021,   352,   357,
     622,   351,     0,   354,   359,     0,   489,  1377,   613,   611,
       0,   784,  1069,  1071,     0,   382,  1146,  1144,     0,  1156,
    1140,     0,     0,  1237,     0,     0,     0,   100,     0,     0,
      75,    81,    71,  2230,  2230,   110,   105,   119,   115,     0,
     109,   778,   899,   639,  2230,   889,   888,   897,  1013,     0,
       0,   959,   960,   954,   980,   489,  1086,  1082,  1083,  1085,
    2123,  2125,   691,   685,   683,     0,    24,     0,  2230,  2230,
    2230,  2230,  2230,  2230,   743,   717,   745,   719,  2230,  2230,
    2230,  2230,     0,   711,   716,  2230,   639,   773,   771,   774,
     772,     0,     0,    46,    44,    41,    35,    39,    43,    38,
      31,    40,     0,    34,    37,    32,    42,    33,    45,    36,
       0,    29,    47,   765,     0,   689,  1766,     0,  1764,  1719,
    1762,  1706,  1707,  1699,  1685,  1700,     0,     0,     0,  1056,
    1492,  1495,     0,     0,     0,  1389,  1361,  1789,  1788,  1787,
       0,     0,     0,  1436,  1439,     0,     0,     0,     0,     0,
    1384,     0,  1383,     0,  1385,  1380,  1381,  1382,  1373,  1374,
       0,     0,     0,   586,   591,     0,     0,  2230,  2230,   564,
     578,   601,   589,   603,  2230,  2230,   599,   583,   594,   845,
     338,     0,  1675,  1673,  1674,  1670,  1672,  1669,  1671,  1643,
       0,     0,     0,  1758,     0,     0,     0,  1756,     0,     0,
       0,     0,  1738,  1755,     0,  1508,     0,  1635,  1511,     0,
       0,     0,     0,  1503,  1521,  1523,  1525,  1565,  1564,  1563,
    1527,  1543,     0,  1518,  1519,  1714,  1284,     0,     0,     0,
     212,     0,  1214,  1233,   845,     0,  1221,  1214,     0,  1627,
       0,  1460,     0,  1463,  1630,     0,  1468,     0,     0,  1329,
    1330,     0,     0,  1333,  1335,  1337,     0,  1321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1476,  1475,
    1474,     0,  1479,  1480,     0,  1316,     0,  1310,  1312,  1622,
       0,  1624,  1614,     0,  1616,  2218,  1290,     0,  1286,     0,
       0,  1291,   860,     0,     0,     0,     0,     0,  1348,  2223,
    2222,   621,     0,     0,    48,     0,   706,   708,   707,  1349,
     713,  2230,  2230,   151,   647,   161,   153,   163,   143,   150,
    2230,     0,     0,     0,     0,     0,  2190,     0,     0,     0,
       0,     0,     0,  1062,     0,  1378,   558,     0,   783,  1067,
       0,  1243,  1244,  2199,     0,    93,     0,    65,     0,     0,
       0,    78,     0,    93,    93,   118,   113,  2230,  2230,   103,
       0,   900,   894,   902,   901,   891,   608,   940,     0,     0,
       0,   693,   672,   686,   640,   754,     0,   734,   732,   742,
     740,   738,   736,     0,  2230,     0,  2230,   730,   728,   724,
     722,   776,   726,    24,   766,     0,     0,     0,    27,     0,
    1769,     0,  1686,     0,     0,  1698,  1681,  1697,  1496,     0,
    1453,     0,  1388,     0,     0,  1785,     0,  1782,     0,  1444,
    1448,  1424,  1446,  1449,     0,  1435,  1703,     0,     0,     0,
       0,     0,     0,  2127,  1387,  1386,  1375,  1370,  1372,  1423,
       0,     0,   588,   585,   580,   582,     0,  2230,  2230,   596,
     598,  2230,  2230,     0,  1661,     0,     0,     0,     0,     0,
    1754,  1760,  1750,  1751,  1752,  1753,  1512,     0,  1506,  1526,
    1530,     0,  1543,  1529,     0,     0,  1544,  1559,  1556,  1557,
    1554,  1562,  1561,  1555,  1558,     0,     0,     0,     0,     0,
    1560,     0,     0,     0,  1500,  1501,  1727,     0,  1520,  1514,
    1285,  1712,  1394,  1390,  1391,  1396,  1395,  1710,  1284,     0,
    1212,  1213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1211,     0,     0,  1199,  1200,  1201,  1198,
    1203,  1204,  1205,  1202,  1189,  1180,     0,     0,  1236,     0,
    2230,     0,  1175,     0,     0,     0,     0,     0,     0,     0,
    1167,  1168,     0,  1099,  1631,     0,  1632,     0,     0,     0,
       0,  1467,  1466,  1332,  1465,  1457,  1323,  1607,     0,     0,
       0,     0,     0,     0,  1608,  1600,     0,     0,     0,  1600,
    1636,  1473,  1486,  1491,     0,  1488,  1485,  1487,     0,  1489,
    1477,  1481,  1482,  1332,  1318,  1314,     0,     0,  1289,  1288,
       0,  1273,     9,     0,  1263,   861,  1096,   364,  1263,     0,
       0,  2214,     0,     0,   994,    49,     0,   763,   160,   158,
       0,  2230,     0,     0,     0,  2230,   156,   145,     0,   148,
     147,     0,  1000,  1004,   989,  2183,  2182,  2181,     0,     0,
     356,     0,   561,     0,  2230,   785,     0,   639,  1147,     0,
    1238,    70,     0,     0,   101,    68,    93,    76,    82,     0,
     120,   116,   779,  2230,   904,   639,   903,     0,   605,     0,
     809,   810,   808,  1084,   696,   694,     0,   676,   673,     0,
     744,   718,   746,   720,   755,   769,   770,   767,   768,    30,
      28,     0,  1763,  1715,  1687,  1683,  1682,     0,  1452,  1719,
    1455,     0,  1363,  1358,  1357,  1360,     0,     0,  1443,     0,
       0,  1715,     0,     0,  2160,  2158,     0,     0,  2146,  2157,
       0,     0,  2159,     0,     0,     0,     0,     0,  2188,  2156,
    2152,     0,  2144,  2147,  2148,  2155,  2151,  2175,     0,  2137,
    2136,  2140,  2142,     0,  2135,     0,  2138,  2129,     0,     0,
     592,   590,   602,   604,   600,     0,     0,     0,  1718,     0,
    1798,     0,     0,  1509,  1528,  1522,  1524,  1531,  1533,  1531,
       0,  1538,  1531,     0,  1536,  1531,     0,  1546,  1545,     0,
    1547,     0,  1499,     0,  1398,  1397,  1393,  1713,   235,  1206,
    1207,  1208,  1210,  1193,  1191,  1190,  1194,  1195,  1192,  1209,
    1196,  1197,  1181,   986,  1216,   983,     0,     0,  1234,     0,
    1179,  1178,  1173,  1171,  1170,  1174,  1172,  1176,  1177,  1169,
    1222,     0,  1458,  1464,  1634,  1627,  1469,  1331,  1574,  1586,
       0,  1588,  1590,     0,  1592,     0,     0,     0,  1598,  1577,
    1602,     0,  1459,  1461,     0,  1483,  1484,  1625,  1617,  1287,
       0,     0,  1279,  1274,  1275,  1292,     0,  1270,  1271,     0,
       0,  1284,  1264,  1265,     0,    24,  1259,     0,     0,  1017,
       0,    50,   997,     0,    24,   162,   152,     0,   649,   651,
     164,   154,   763,     0,  1026,     0,   355,  1379,     0,  1068,
      24,     0,     0,    66,     0,    79,    88,     0,    72,   895,
     892,   609,  2230,   955,     0,  2230,   692,   671,   677,   639,
    1773,     0,  1771,     0,     0,  1688,  1684,  1454,     0,  1456,
    1450,     0,  1362,     0,  1783,  1445,  1447,  1422,     0,  2150,
    2149,     0,     0,  1566,     0,  1566,  1566,  1566,  1566,  2153,
       0,     0,  2133,     0,     0,     0,     0,  2162,  2134,     0,
       0,     0,     0,     0,     0,  2128,  1376,  1428,   855,   854,
     339,  1676,  1796,  1797,  1513,     0,  1550,  1552,     0,  1539,
    1542,  1541,  1549,     0,  1551,  1531,     0,  1502,  1392,   213,
     988,   987,   985,     0,  1215,  1100,  1104,  1106,     0,  1110,
       0,  1108,  1112,  1101,  1102,     0,   877,     0,     0,  1628,
    1633,     0,     0,  1609,  1601,  1579,     0,  1580,     0,     0,
    1277,  1272,  1278,  1276,  1269,  1268,  1267,  1262,  1266,   365,
     362,     0,  1015,     0,     0,     0,   996,   764,   140,   648,
      24,  1006,  1025,   559,  1065,    67,  1239,    84,     0,     0,
      77,    88,    88,  2230,   606,     0,     0,   695,   756,     0,
    1770,  1716,  1709,     0,  1364,     0,  1709,  2173,     0,     0,
    2176,     0,     0,     0,     0,     0,     0,     0,  2145,  2164,
    2165,  2163,  2161,  2143,     0,  2139,  2141,  2130,  2131,  1429,
       0,  1421,  1532,  1761,  1534,     0,  1537,  1535,  1553,     0,
     984,  2230,  2230,  1114,  2230,  1116,  2230,  2230,  1103,  1235,
    1223,     0,  1589,     0,  1599,     0,  1490,   367,  1016,  2213,
       0,     0,     0,     0,     0,     0,    55,     0,    54,     0,
      52,     0,     0,   141,  1072,    88,    93,    88,    89,    83,
      73,   893,     0,     0,   697,    24,  1772,  1708,  1717,  1368,
       0,  1365,  1367,  1689,  2174,     0,     0,  2172,     0,     0,
       0,     0,  2154,  2171,     0,  1430,  1540,  1548,  1105,  1107,
    2230,  1111,  2230,  1109,  1113,  1629,  1594,  1462,   369,   374,
     372,   363,     0,   370,   376,    57,    62,    59,    61,    58,
      60,    56,     0,    51,     0,   650,   652,  1076,  1066,     0,
    1074,  1240,    85,    80,   607,   956,  2230,   757,     0,  1359,
       0,  1690,  1704,  2170,  2177,  2166,  2167,  2168,  2169,     0,
    1115,  1117,  2230,  2230,   368,   371,  2230,    53,     0,  2230,
    1073,  1075,     0,   693,  1366,     0,  1694,  1691,  1692,  2132,
     375,   373,   377,     0,  1077,    86,   698,     0,     0,     0,
     998,    90,     0,  1695,  1693,    92,     0,    87,     0,    91,
    1696
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   823,   824,   825,   826,  1043,  2371,  2372,   180,   322,
     181,  1392,  1393,  2208,  2530,  3538,  3034,  3035,  3444,  3539,
    3540,   827,  1182,  3072,  2774,  3462,  2147,  2772,  3316,  3076,
    3458,  2773,  3317,  3546,  3642,  3661,  3460,  3667,   645,   646,
     647,  1513,  2446,   828,  1524,  1187,  1522,  2155,  2456,  2152,
    2454,  2459,  2778,  1523,  2453,  2156,  2777,   829,     9,    28,
      29,    30,    31,    32,    88,   832,  1106,  2088,  1416,  2396,
    2400,  2401,  2397,  2398,  3041,  3045,  2740,  2732,  2731,  2733,
    2736,   494,   270,   599,   833,    55,    56,    11,    41,   115,
      70,    71,    72,    73,   196,   336,    74,    75,   242,   341,
     228,  1006,   520,  2929,   372,   934,  2271,   400,   401,   229,
     354,   343,   349,  1337,  1338,   119,   538,   120,   121,   360,
     230,   356,   342,   344,   522,   231,   256,   576,   244,   247,
     245,   246,   382,   554,   555,   557,   562,   937,   248,   249,
     391,   559,   192,    12,    51,   151,   152,   153,   943,  2873,
     154,   252,   240,   394,   395,   396,   397,  2110,   834,   835,
     836,   837,  1064,  3527,  3285,  1394,  3591,  3592,  3593,  3633,
    3632,  3636,   838,   839,   840,   841,   842,   843,   844,  1054,
     495,  1059,  1386,  1387,  1431,  1157,  1432,   297,   298,   299,
     300,   301,   302,   303,   452,   496,  1320,   497,   498,   499,
     500,   501,   502,   503,   983,   182,   514,   993,   995,  2005,
     183,   508,   989,   507,   988,   510,   991,   509,   990,   952,
     961,   304,   305,   185,   306,   419,   420,   421,   422,   405,
     424,   845,  1124,  2113,  3064,  2427,    89,   237,   548,  1934,
    1250,  1251,  1252,  1931,  1932,  2258,  2259,  2260,  2587,  2588,
    1935,  1936,  2254,  2591,  2583,  2266,  2267,  2594,  2595,  2871,
    2867,  2868,   846,  3322,  3552,  3088,   847,  1443,    57,  2073,
    2074,  2421,   406,   426,  1098,  1162,  1035,  1086,  1069,  1108,
    2486,   186,  1036,  1026,  2046,  2735,    59,   307,   848,  1192,
     849,  1205,  1206,   850,   851,   852,   853,  1213,  3097,  1234,
    3327,  1235,  2182,  1236,  2483,  1237,  2792,  1238,  2211,   854,
    2178,  2791,  3096,  3325,  3324,  3616,    90,    13,   855,  1410,
    2078,  2079,  2080,  2201,  1879,  2202,  2203,  2804,  2806,  2501,
    2500,  2505,  2499,  2498,  2489,  2488,  2493,  2492,  2491,  2490,
    2495,  2497,   856,   857,  1104,   858,  1875,  1220,  3555,   859,
    1491,  3294,  2532,  2533,  2204,  2502,  2462,  2780,  1151,  1471,
    2117,  2430,  2118,  1467,   860,   861,  1198,  2170,  3092,   862,
     863,   864,   865,    14,    45,    15,    16,    17,    91,    92,
     866,    93,    18,   925,    19,    94,    95,   131,   550,  1940,
    2599,  3379,    96,   127,   365,   867,  2713,    20,    21,    22,
      23,    24,    40,    62,    97,   674,  2011,  2654,    98,   238,
     549,   928,   929,  1254,  1938,   868,  1193,  2466,  2159,  2464,
    3463,  3083,  2160,  2463,  2783,  3085,   869,   870,   871,  1080,
    1081,  1527,   872,  1239,  1240,   873,  1887,  1241,   308,    64,
      65,    66,    67,  1534,   157,   111,    68,  1113,   108,   188,
     189,  1535,  1536,  2473,  1537,   671,   672,  1222,   673,  1223,
    1155,  1156,  1538,  1539,  1390,  3224,  3225,  3402,  2099,  1096,
    1097,   874,  1405,  3446,   875,  3053,   876,  1420,  1421,  1422,
    2094,  2092,   877,   878,  2380,  2407,   879,  2104,  2417,   880,
    1152,  1153,   881,  1019,   882,  2543,   883,  3544,  3067,   884,
    2434,  3608,  3609,  3610,  3639,  1159,   885,  1540,  2172,  2477,
    2478,   886,  2066,  1034,  1379,   887,   888,   889,  2656,  3228,
    3413,  3414,  3511,  3512,  3516,  3514,  3517,  3580,  3582,   890,
     891,  1529,  2164,   892,  1531,  1502,  1503,  1504,  2137,   893,
    1172,   894,   895,  2130,  1499,  1168,   195,  1505,  1506,   309,
    2657,  2970,  2971,  2954,  1051,  1052,  2652,  2955,  2958,    99,
     126,   542,  1347,  2321,  2972,  3417,   434,   896,  1166,   100,
     123,   539,  1344,  2319,  2959,  3415,  2653,  1186,  2765,  3312,
    3545,  2132,   897,   898,   899,   900,   901,  1067,  2378,  1045,
    2374,  3281,  3282,  3283,  3430,  3272,  3273,  3274,   902,  2921,
    2707,  2708,  2710,  2030,   903,   904,  1356,  1357,  1358,  2039,
    2360,  1359,  2357,  2036,  1360,  2333,  2031,  1361,  1362,  1363,
    2325,  2330,  1364,  2025,  2026,   905,  1076,  1056,   906,  1912,
    1913,  2226,  3124,  3343,  2834,  3121,  3560,  3561,  1914,  2248,
    1893,  2579,  2857,  3168,  2756,  3063,  2580,  1915,  1916,  2308,
    2923,  2924,  2925,  3206,  1917,  1918,  1428,   907,  1114,   908,
    1247,  1919,  1920,  2242,  3501,  2243,  2244,  2245,  2563,  2838,
    2841,  2842,  1921,  2553,  2829,  3340,  2019,  2020,  3009,  2660,
    3262,  2661,  2021,  2665,  2032,  2692,  2033,  2693,  3010,  3011,
    3012,  3013,  1922,  2220,  2221,  2550,  1923,  2918,  2643,  2914,
    2303,  1987,  2298,  2299,  2300,  2887,  1988,  2304,  2644,  2919,
    2633,  2634,  2635,  2636,  2637,  3386,  3187,  3502,  2638,  3388,
    3389,  2912,  2639,  2913,  2640,  2287,  2353,  2354,  2355,  3256,
    2356,  2988,  2995,  3424,  2662,  1023,  2843,  2976,  3161,  2664,
    2628,  1298,   310,  1299,  1968,   445,   953,  1953,  1969,  2609,
      39,   909,   910,  3116,  3336,  2822,  3335,  3622,  3647,  3648,
    2826,  2544,  1924,  2545,  2568,  3131,   602,  2540,  2541,  2309,
    2646,  3334,  3120,  1300,   968,  1301,  1302,  2915,  2641,  1304,
    1305,  2289,  3504,   911,   912,  2213,  2542,  3112,  3331,  3332,
    1890,   913,  1062,  1926,  1927,  2230,  2836,  1928,  1929,  2559,
    2000,  2282,   914,  1201,  1864,  1865,  1866,  2174,  1867,  2175,
    1930,  2569,  3167,  3375,  2853,  3164,  3165,  3166,  3163,  3151,
    3152,  3153,  3154,  3155,  3156,  3481,   915,  2102,  2412,  2413,
    1115,  1306,  1117,  2100,  1307,    25,   917,  1174,  2138,  1413,
    1493,   918,   919,  2724,   920,  2369,  1039,  2053,   921,   922,
      35,   543,   544,   545,   546,   547,   923
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2762
static const short yypact[] =
{
     462,  1281, -2762,   488,   488,  1070, -2762, -2762,  1070, -2762,
      71, -2762, -2762, -2762,   357, -2762,   462, -2762, -2762, -2762,
   -2762, -2762,    86, -2762, -2762, -2762, -2762, -2762,   756,   771,
   -2762,   744, -2762, -2762, -2762, -2762, -2762, -2762,   231, -2762,
     521,   582, -2762, -2762, -2762,   476, -2762, -2762, -2762, -2762,
   -2762,   257,   488, -2762,   488,   664,    71, -2762,   940, -2762,
   -2762, -2762, -2762, -2762, -2762,   442,   333, -2762, -2762, -2762,
     894,   625,   488, -2762, -2762,  1011,   488, -2762, -2762,   488,
     488, -2762, -2762, -2762, -2762,   488,   488, -2762, -2762, -2762,
   -2762, -2762,   476, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  5879, -2762,   333, -2762,   819,  3371, -2762, -2762,
     527, -2762, -2762,  1105,   582,   624, -2762, -2762, -2762, -2762,
   -2762,  9660, -2762,   488,   692,  1019,   488,    71, -2762, -2762,
   -2762,   488, -2762, -2762,   837,   731,   691, -2762, -2762,   742,
   -2762,   748, -2762,   739, -2762, -2762,   796, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762,   793, -2762, -2762,
   -2762,   813,   826,   855,   860,   863,   869,   896,   912,   945,
     958,  3371,   999,  4994,  1012,  1028,  1045,  1051,  1055,  1085,
    1714,  1542, -2762, -2762, -2762, -2762,   790, -2762,   152, -2762,
    3371, -2762,   255, -2762, -2762, -2762,   171, -2762, -2762, -2762,
     607, -2762, -2762, -2762, -2762, -2762, -2762,   837,  1097,  1119,
    1133, -2762,   691, -2762, -2762,  1140, -2762,  1144, -2762,  1102,
   -2762, -2762,  1147, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  1150,  1609,   488,  1161, -2762,    71,    71,  1164,
     488, -2762,   402,  1620, -2762,   978,   893, -2762,   981,   920,
    1645,  1659,   488,  1671,  1679, -2762,  1013, -2762,    52,    52,
      52,    52,    52,  4994,  1426,  1590,    47,  4994,  1064,  4994,
   -2762,  4994,  4994,  4994, -2762, -2762, -2762,  1134,  1217,  1231,
    4994,  1186,  1249, -2762,  4994,  4994,  1272, -2762,  1275, -2762,
    1028,  1279,  1285,  1293,  1294,  1748,  8727,   127, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  1305, -2762,
   -2762, -2762, -2762, -2762, -2762,   408,   408, -2762, -2762, -2762,
   -2762, -2762,  3371, -2762, -2762,   488,  3371,  1269,   189, -2762,
   -2762, -2762, -2762,  1754, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  1308, -2762,  1308,   402,  1762,  1763,  1765, -2762,
   -2762, -2762,  1766,  1768,   582,  1671,  1308,  1770,  1131, -2762,
    1696, -2762,  1363,  1331, -2762,  1397, -2762, -2762, -2762,  1145,
   -2762, -2762,  1784,  1375, -2762,  1338, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762,   920,  1338, -2762, -2762, -2762, -2762, -2762,
   -2762,  1339,   164,   229,   188, -2762,  5129, -2762, -2762, -2762,
    1345,  1819,   233, -2762,  1348,   248, -2762,  -103,  1387,  1388,
     296,   383,  7605,  1392,   -76,  1440, -2762, -2762,   172,  1395,
   -2762, -2762, -2762, -2762,   389, -2762, -2762,  7767, -2762,  3305,
    8993,  1974,  1974,  4994, -2762,  1321,  4994,  8727,  1366, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762,  1173,  1816,  7815,  8727,
    1321,  1826,   399,  4994,  4994,  4994,  4994, -2762,  4994,  4994,
    4994,  4994,  4994,  4994,  4994,  4994,  4994,  4994,  4994,  4994,
    4994,  4994,  4994,  4994,  4994, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,  4994,  4994, -2762, -2762,  1370,
    4994, -2762,  4994,  1371, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762,   408,  4994,  4994,  4994,
    4994,  1410,  1847,  1714,  4994,  1377, -2762,  3371,  1350, -2762,
    1187,  1832, -2762,  1195, -2762,  1836,  1423,  1425,   403,  1564,
     405,   409,   327,  1398, -2762,   410, -2762, -2762, -2762,   488,
   -2762, -2762,   488,  1461, -2762,  6845,   624,  7149,  1849,  -145,
     488,  1863,   636, -2762, -2762,   893,  1858, -2762, -2762, -2762,
   -2762,  1860, -2762,  1861, -2762,  1862, -2762,   488, -2762,   488,
   -2762, -2762,  1671,  1864, -2762, -2762, -2762,   488,    52, -2762,
    3371,    44, -2762, -2762, -2762, -2762, -2762,  1186,  1186,  1865,
   -2762,  1869,  1262,  1127, -2762,    47, -2762, -2762, -2762,  1464,
    8727,   460,  1467,  7855,  1883,  1186,  1474, -2762,  1477,  1479,
   -2762,  7929,  8123,  8368,  8453,  8926,  4556,  8993,  8819,  9192,
    9162,  9247,  1525,  4085,  1533,  4470,  1974,  1974,  3116,  3116,
    4654,  8727,  8560,  8622,  1321,  8727,  8670,  1321, -2762,  8727,
    8727,  8727,  8727, -2762,  1886, -2762,  1916, -2762,  8727, -2762,
     215,  3371, -2762,  1482,  1911,   636, -2762, -2762,  1907, -2762,
    1457,  1912, -2762,  1917, -2762, -2762, -2762,  1918, -2762, -2762,
    1276,  1506,  1946, -2762,   488,  1517, -2762, -2762, -2762,   408,
     408,   408,   488,   995,   488,  1414,   265,   265,  1493,   488,
     488,   265,   265,   488, -2762,  1414, -2762, -2762,   488, -2762,
    1115, -2762, -2762, -2762,   265, -2762, -2762, -2762, -2762,   488,
   -2762, -2762, -2762, -2762,   141,   141,  4994, -2762, -2762, -2762,
    1493,  1493, -2762, -2762,   265, -2762, -2762,   265, -2762, -2762,
     488, -2762, -2762,   265, -2762, -2762,   408,   265, -2762, -2762,
    4994,   265,   408,   488,   408,   265, -2762, -2762,   202,   265,
     265,   202,   265,   488,   202,   265, -2762,   265,   265,   265,
   -2762,  1414, -2762, -2762,   408,   265, -2762, -2762,   265,    40,
     488, -2762,  1493, -2762, -2762,   265,  1048, -2762, -2762,   408,
    1295, -2762,   265, -2762,  9112,   408,  4994,    52,    52,   265,
   -2762, -2762,   995,   408,  1075, -2762,  4994, -2762,    33,  4994,
     265,    78, -2762,  4994,   265,  1933,   408, -2762,   265,  4994,
   -2762,  4994,   141,   488,   265,   488,    52,   265,   488,    52,
   -2762,   488,   187, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762,   510, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762,  1191, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,   786,   488, -2762,   542, -2762,
    1526, -2762, -2762, -2762,  1615, -2762, -2762,  1530,  1534,  1538,
    1539, -2762, -2762,  1303,  1970,  1544,  1545, -2762,   551, -2762,
    1508, -2762, -2762,  1320, -2762,  1557, -2762,  1973, -2762,  1380,
   -2762, -2762, -2762,  1328, -2762, -2762, -2762, -2762,  9354, -2762,
    1134,  1562, -2762,  1134, -2762,  1134,  1134,  1134,  1134,  1134,
    1982,  1986,  1988,  4994,  1577,  1993,  4994,  1581,  1584,  1586,
    1588,  1592,  1595,  1596,  4994,  4994, -2762,   294, -2762, -2762,
   -2762,  1688,  1599, -2762,  1602,  1603,  1374,  1605,   488, -2762,
     488,  1606, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
     340,  1391,  -265,  1361,  1576, -2762, -2762, -2762, -2762,  1393,
     361, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  2056,
    1394, -2762, -2762,  1593, -2762,  1493, -2762,  1540,   242, -2762,
   -2762, -2762,  1420, -2762,  8727, -2762, -2762,  1428, -2762, -2762,
    3676, -2762, -2762, -2762,   408, -2762, -2762,  1493, -2762,     4,
   -2762, -2762,  1757, -2762,   125, -2762,  1561, -2762, -2762, -2762,
   -2762,  2067, -2762, -2762,   610, -2762,  1416, -2762,  1417,  2067,
   -2762,  1441, -2762, -2762, -2762,  1617,   119, -2762,  1582, -2762,
    1385, -2762, -2762, -2762, -2762,  1386,   297, -2762,  -203, -2762,
    1427,  1499,  1591, -2762,  1716,  1436, -2762,  1430,  4994,   132,
    1099,  4994, -2762,   108,   265, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,    32,    32,    32, -2762,    32,   615,
      32,    32,  1455,     4,  1455,  1455,  1121,  1121,  1455,  1455,
       4, -2762,  2097, -2762,  1644,   493, -2762,  2117, -2762,     4,
      58,    41, -2762, -2762,  4994, -2762, -2762, -2762,   741, -2762,
   -2762,   624,  4994, -2762,  4994,  1646,  1647,  1648,  1651,  1555,
    1656,  1075, -2762,  1729,   792,  1501, -2762,  1510, -2762, -2762,
     488, -2762, -2762,  1142, -2762,  2131, -2762,  2127,   488, -2762,
      77,  6209,  1521, -2762, -2762,  2139, -2762,  1442,  2139,  2146,
    1449,  2139,  2146,  4994,  2139, -2762, -2762,   242,   408, -2762,
   -2762,  1689,   358, -2762, -2762,  1677,   408,  4994,  1678, -2762,
   -2762,  2133,  2135,  2054, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  1197,  1197,   265,   265,   265,  1535, -2762, -2762,
    2031,   786, -2762, -2762,   683, -2762, -2762, -2762,  1664, -2762,
   -2762, -2762, -2762,  5879,  1671, -2762, -2762,  1507,   488,  1241,
    1186,  1543,  1459, -2762,  3270,  3270, -2762,  1427, -2762, -2762,
    1248, -2762,  4808,  1697, -2762,  1698,  1702,  1703, -2762,  1703,
    1703,  1704,  1705,  1706,  1707,   488,     3, -2762, -2762, -2762,
   -2762,   221, -2762,   488,  2090, -2762,  1720, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  8727,
     412, -2762, -2762,   414, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,  1668, -2762, -2762,   416, -2762, -2762,
   -2762, -2762, -2762, -2762,    71, -2762, -2762,    71,   688,   245,
    2166, -2762, -2762,   600,   339,   705,  2190, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,   488,  1573,   488, -2762, -2762,
    1578,   488,  1604,   488,   488,  1493,  1556,  1719, -2762,  1721,
      87, -2762, -2762, -2762,  1493, -2762, -2762,  2195, -2762, -2762,
    1529,  1725, -2762, -2762, -2762,  1099,  1233, -2762,  1233,  1075,
     202,  4994,  4994,  4994,  1727, -2762, -2762,   408,   408,  1493,
    1546,  1075,    52,  1498,    40,   408, -2762,  1548,  4994,  1814,
   -2762, -2762,  1614,  1499,  1427,  1430, -2762, -2762, -2762,   488,
    1107,  2216, -2762, -2762,  1559,   158,   242,   408, -2762, -2762,
    2210,  2217, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
     632, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
    9112,   408,   408, -2762,  1121,  4994,   -13,  2211,  2215, -2762,
   -2762, -2762, -2762, -2762,    89, -2762, -2762, -2762, -2762,  2041,
   -2762,  1812,   624,  4994, -2762,    61, -2762, -2762,   488,  2220,
      52,    52, -2762,  1611, -2762,    47,  1580,   408, -2762,   488,
     488,  4994,     9, -2762,  1621, -2762, -2762,   590, -2762,  1722,
   -2762,  1723,  4994,  1054, -2762, -2762,  1589, -2762,  2251, -2762,
    1667, -2762,   408, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,  5498, -2762, -2762, -2762, -2762,   488,
      52,    52,   246,   358,  2058,  1687,   408,   242, -2762,  1670,
   -2762, -2762,  2216,  2239,  1818, -2762, -2762, -2762, -2762, -2762,
    1896,  1896, -2762,   182,  1675, -2762,   488,  1493, -2762,  1493,
    1493, -2762, -2762,  1493,  1493, -2762,   488,   751,   460,  1493,
   -2762,   751, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,   177,   177,   697,   902, -2762,   759, -2762,   683, -2762,
      71,  2243, -2762, -2762,  1130,  1830,  1795, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,  1610, -2762, -2762, -2762,  1785,
    1785, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  1607,
     460,  1835,   647,   648,  9354,  1759, -2762, -2762, -2762,   648,
     648,   648,   648,  1612,  9354,  9354,   289,  1708,   466, -2762,
    9354,  9354,  9354,  9354, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,  1099,  4994, -2762, -2762,  1842,  2243, -2762, -2762, -2762,
   -2762,    71, -2762,  1805,  1807,  1808,   788,  1815,  1817, -2762,
   -2762, -2762,  2187,   488, -2762,  2291, -2762, -2762,   535,  9511,
   -2762, -2762, -2762, -2762,   488, -2762, -2762,   535,  1587, -2762,
     340, -2762,  1635, -2762,  1680, -2762,  1875,   333, -2762,  1637,
   -2762,  1681, -2762,  1711,  1844,   488, -2762, -2762, -2762, -2762,
    3676,   488, -2762,  1660, -2762, -2762, -2762, -2762,  1658, -2762,
    2323,  2336, -2762,  2337,  1717,  4994, -2762, -2762,  2339, -2762,
    1690, -2762,  1823,  1682,  2146, -2762, -2762,  1684,   838,   488,
   -2762, -2762,  1879,   265,   993,  1693, -2762, -2762,  1856, -2762,
   -2762,  4994,  1493,  1099,  -170, -2762,   488,   488,  4994,    25,
       4,  2360,  1106,  2358,  2343,  2348,   615, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,   408,  2014, -2762, -2762,  2269,  4994,
     624,  2120, -2762, -2762, -2762,  4994,   141, -2762,  2008,  2384,
    2385,   433,   439,   488,  1953,  1075, -2762,  4994,  1919,  1921,
   -2762, -2762,  1987, -2762,  4994,    12, -2762,  1752, -2762, -2762,
     498, -2762,  4994, -2762, -2762,  1728,   819, -2762,  1287,   488,
    2387,  7050, -2762, -2762,  1099,   408, -2762, -2762,    39, -2762,
    2146,  2146,  1700, -2762,  1806,  1809, -2762, -2762, -2762, -2762,
   -2762, -2762,    52,    52, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  2329, -2762, -2762, -2762, -2762,    52,  9695,  2399,
    2381, -2762,  1075,   925,   293,   129,  2261,   -39,   995, -2762,
     146, -2762, -2762, -2762,  1932,   102,  1493,   206,  1745, -2762,
    1742, -2762, -2762, -2762, -2762, -2762,  1937,  1937, -2762, -2762,
   -2762, -2762,  1824,  1750,  2411, -2762, -2762, -2762,   514,  1746,
    1753, -2762, -2762,   408,   240, -2762, -2762, -2762,  1738,   902,
   -2762,   488,   488, -2762, -2762,   488,   612, -2762, -2762, -2762,
   -2762,  1951, -2762, -2762, -2762,  2403, -2762, -2762,  1283,  9354,
   -2762,   373,  1992,  2428, -2762, -2762, -2762,  9354, -2762,   443,
    9354,  9354,  9354,  9354,   488,   451, -2762,   264,  2429, -2762,
   -2762,   488,  4717, -2762,  2019,   488,  1772,   648,  2057, -2762,
   -2762, -2762, -2762, -2762, -2762,  8727, -2762,  1965, -2762,  1934,
   -2762,  1936,   148,   148,   148,   458,  2187,   148,  4717,   488,
   -2762,   472,   488,   479, -2762, -2762, -2762,  1962,  1963,  1967,
    1248,  1248, -2762,  1968, -2762,  1971,  1976,  1977,  1978, -2762,
   -2762, -2762, -2762,   976, -2762, -2762, -2762,   482, -2762, -2762,
     489,   488, -2762,   488,  1618, -2762,   488,  1653,  4994, -2762,
     488,  2438, -2762, -2762,   535, -2762, -2762,  1782,   535,   208,
   -2762,  1075,  4994,  4994,  4994,  3859,  2446,  1493,   190, -2762,
    1075,   488, -2762, -2762,   488,   488, -2762,  1122, -2762, -2762,
     397, -2762,  1786,  4994, -2762, -2762, -2762,  2453,  1107,  3371,
   -2762,  1796,  2458, -2762, -2762,  1075,  1841, -2762, -2762, -2762,
   -2762, -2762,   488,  2146, -2762,   242, -2762,  1866, -2762, -2762,
     490, -2762, -2762, -2762,   408, -2762,  4462, -2762,  1135, -2762,
   -2762,  2096,  2440, -2762,  2078,  2079,  1975,  1810,  2080,  1999,
   -2762, -2762, -2762,   -36,  2070, -2762, -2762, -2762, -2762,  1987,
   -2762, -2762, -2762,   300,   773, -2762, -2762, -2762,  2216,  4994,
    2007, -2762,  1979, -2762, -2762, -2762, -2762,  2477, -2762, -2762,
   -2762,  2481, -2762,  1790, -2762,  2464,     4,   488,  2547,  2547,
    2547,  2547,  2547,  2547, -2762,  2487, -2762,  2488,  2547,  2547,
    2547,  2547,   632, -2762, -2762,  2547,   113, -2762, -2762, -2762,
   -2762,  2469,  2483, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  2485, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
     494, -2762, -2762, -2762,  2474, -2762, -2762,  1493, -2762,   460,
   -2762, -2762, -2762, -2762, -2762, -2762,  1868,  1870,   103, -2762,
     146, -2762,   148,  1839,   265, -2762,  2025, -2762, -2762, -2762,
     488,   488,   148, -2762, -2762,   100,  1493,  1494,  9354,   209,
   -2762,  4994, -2762,  4994, -2762, -2762, -2762, -2762, -2762,  1913,
     265,   100,  1493,  2510, -2762,   408,   488,   743,   743, -2762,
   -2762,  2511, -2762,  2511,   630,   630,  2511, -2762, -2762,  1849,
   -2762,  2077,  2040, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
     221,  1248,  1848, -2762,  1248,  2081,  9354, -2762,  2082,  2085,
    2087,  2088, -2762, -2762,   289, -2762,   289, -2762, -2762,  5155,
    1703,  4421,  1703,  2513,  2522, -2762, -2762, -2762, -2762, -2762,
   -2762,   191,  9354, -2762,  2036, -2762,  2219,   197,   293,   488,
   -2762,  1657,   241, -2762,  1849,  2328, -2762,   241,  1493,   938,
    2093,  2532,  1872, -2762, -2762,   496, -2762,   500,   788, -2762,
   -2762,   513,   196, -2762, -2762, -2762,   535, -2762,  2516,  2516,
    2517,  1878,   400,  2518,  2529,  2535,  2518,  2518, -2762, -2762,
   -2762,   115, -2762,   859,   488, -2762,   535, -2762, -2762, -2762,
    1902, -2762, -2762,  1904, -2762, -2762,     1,   517, -2762,   488,
     537, -2762,  4994,  2132,  2553,   538,  1075,  2569, -2762, -2762,
   -2762, -2762,  4994,  1972,  2253,  4994, -2762, -2762, -2762, -2762,
     397,  1243,  1243,  2571,   -16, -2762,  2575, -2762, -2762, -2762,
    1243,   488,  1991,  1329,  2576,   488,  1926,   305,   219,  1493,
    2585,  1075,    -6,  2360,  4994, -2762, -2762,   615, -2762,  1881,
    4994, -2762, -2762, -2762,  2591,  4994,   408, -2762,  1115,   488,
     408, -2762,  2159,  4994,  4994, -2762, -2762,   -36,  2070, -2762,
     632, -2762, -2762,  1236, -2762, -2762,  1983, -2762,  3371,  4760,
    7050,    56,  1023, -2762, -2762, -2762,  1938, -2762, -2762, -2762,
   -2762, -2762, -2762,    52,  2547,    52,  2547, -2762, -2762, -2762,
   -2762, -2762, -2762,     4, -2762,  1251,  1318,  9695, -2762,  2162,
    2128,  9354, -2762,   129,   129, -2762, -2762, -2762, -2762,   539,
   -2762,  2089, -2762,   148,   165, -2762,  1939, -2762,   540, -2762,
   -2762,  2600, -2762, -2762,  2015, -2762,  2604,  9390,  9390,  9390,
    9390,   148,   148, -2762, -2762, -2762, -2762, -2762, -2762,  2600,
    1940,   408, -2762,  2511, -2762, -2762,   488,   630,   630, -2762,
   -2762,   630,  2351,  1944, -2762,  2589,  2176,  1945,  1283,  1948,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762,   547, -2762, -2762,
   -2762,   269,   167, -2762,  4717,  4717, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,  3270,  3270,  2140,  3270,  2147,
   -2762,  3270,   642,  9354,  2619, -2762, -2762,  4717, -2762, -2762,
   -2762, -2762, -2762,  2624, -2762,   330, -2762, -2762,  2219,  1960,
   -2762, -2762,   141,   141,   141,  2606,   141,   141,   141,   141,
     141,   141,  2608, -2762,  2609,   141, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,  1657, -2762,   408,  1989, -2762,  2143,
    2351,  2613, -2762,  2616,  2625,  2627,  2633,  2634,  2635,  1237,
    2328, -2762,  2143, -2762, -2762,  2636, -2762,  2298,   148,  1358,
     148, -2762, -2762,  2187, -2762, -2762, -2762, -2762,  2223,  2224,
     562,  1283,  2639,  1283, -2762,  2661,   563,  2227,  2228,  2661,
   -2762, -2762, -2762, -2762,  1493, -2762, -2762, -2762,  2191, -2762,
   -2762,   859, -2762,  2187, -2762, -2762,   488,   488, -2762, -2762,
     488,  -199, -2762,   535,   114,  2216, -2762,  2155,   114,   282,
    1075, -2762,  2666,  2196, -2762, -2762,  2235,  2083, -2762, -2762,
     488,  1243,  3371,  1364,   488,  1243, -2762, -2762,    52, -2762,
   -2762,  4994, -2762, -2762, -2762, -2762, -2762, -2762,  1075,  2668,
   -2762,    52,  2216,   408,  2390, -2762,  2653,  1806,  8727,  2656,
   -2762, -2762,   242,  2212, -2762, -2762,  4994, -2762, -2762,  2244,
   -2762, -2762, -2762,   773, -2762,  1806, -2762,  4994, -2762,   312,
   -2762,  2117, -2762, -2762, -2762, -2762,  2197,  2294, -2762,  2669,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,   488, -2762,    93, -2762, -2762, -2762,   148, -2762,   460,
    2500,   574, -2762, -2762, -2762, -2762,   488,   148, -2762,   100,
     100,  2092,  1472,  1472, -2762, -2762,  9416,  2222, -2762, -2762,
    2226,  2229, -2762,  2230,  2231,  2232,  2233,   488,   719, -2762,
   -2762,   577, -2762, -2762,  2206, -2762, -2762, -2762,   578,  2689,
    2689, -2762, -2762,   586,  2690,  2687, -2762,   236,   408,   100,
   -2762, -2762, -2762, -2762, -2762,  2443,  5879,  2265, -2762,  1283,
   -2762,  1283,   289, -2762, -2762,  2522, -2762,  2225,  2090,  2225,
     259, -2762,  2225,   259, -2762,  2225,  3270, -2762, -2762,  9354,
   -2762,  9354,  2513,   197, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762,   543,  2710, -2762,   408,  1453, -2762,  2443,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,   347, -2762, -2762, -2762,  2213, -2762, -2762, -2762, -2762,
    2691, -2762, -2762,  2276, -2762,  2692,  2280,  2696, -2762, -2762,
   -2762,  2283, -2762,  2246,  4717, -2762, -2762, -2762, -2762, -2762,
     488,  2699, -2762,  -199, -2762, -2762,  2702, -2762, -2762,  2703,
     488,  2219,   114, -2762,    52,     4, -2762,  2308,  1075, -2762,
    4994, -2762,  2118,  2706,     4, -2762, -2762,   941, -2762, -2762,
   -2762, -2762,   140,  2295, -2762,  1075,  2146,  2481,  2448, -2762,
       4,  2297,  2299,  2360,  2256, -2762,  2347,  2303, -2762, -2762,
   -2762, -2762,  2455,  2241,  4994,  2262, -2762, -2762, -2762,  1806,
   -2762,   596, -2762,   408,  2156, -2762, -2762, -2762,  9354, -2762,
   -2762,   148, -2762,  2273, -2762, -2762, -2762,  2600,  2156,  1935,
    1935,  2312,   647,   648,  9452,   648,   648,   648,   648,  2091,
    9452,  9390, -2762,  9452,  9452,  9452,  9452, -2762, -2762,   148,
    2739,   148,  9390,   265,  4717, -2762,  2481,    63, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,   115, -2762, -2762,   597, -2762,
   -2762, -2762, -2762,   601, -2762,  2225,  2747, -2762, -2762, -2762,
   -2762, -2762, -2762,   408,  2710, -2762, -2762, -2762,   408, -2762,
     408, -2762, -2762,  1476, -2762,  2468, -2762,  2471,  2730, -2762,
   -2762,  2319,  2098, -2762, -2762, -2762,  2320, -2762,   148,   271,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,  1075, -2762,  2321,  9714,  2286, -2762, -2762, -2762,  2095,
       4, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  2331,   242,
   -2762,  2347,  2347,   773, -2762,  3371,  2150, -2762, -2762,   488,
   -2762,  2481,   466,   221, -2762,  9169,   466, -2762,  2333,  9452,
   -2762,   603,  9452,  9452,  9452,  9452,   488,   609, -2762, -2762,
   -2762, -2762, -2762, -2762,  2290, -2762, -2762, -2762,  2513, -2762,
     488, -2762, -2762, -2762, -2762,   216, -2762, -2762, -2762,  9354,
   -2762,  1475,  1475, -2762,  1475, -2762,  1475,  1475, -2762, -2762,
   -2762,  2300, -2762,  1283, -2762,   611, -2762,  1170, -2762, -2762,
      32,    32,    32,    32,    32,    32, -2762,  2744, -2762,   619,
   -2762,  4994,  1402, -2762,    57,  2347,  4994,  2347,  2360, -2762,
   -2762, -2762,  2486,   353, -2762,     4, -2762, -2762, -2762, -2762,
     620, -2762, -2762,  1408, -2762,  2338,  9452, -2762,  2341,  2342,
    2344,  2345, -2762, -2762,  9390, -2762, -2762, -2762, -2762, -2762,
    1475, -2762,  1475, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  1184, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  9714, -2762,  2771, -2762, -2762, -2762, -2762,   723,
   -2762, -2762, -2762, -2762, -2762, -2762,    39, -2762,  9169, -2762,
    1669, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,   627,
   -2762, -2762,  1229,  1229, -2762, -2762,  1229, -2762,  4994,   777,
   -2762, -2762,  2349,    56, -2762,  2111,  2113,  2778, -2762, -2762,
   -2762, -2762, -2762,  2353, -2762, -2762, -2762,   488,   488,  1669,
   -2762,   161,  2125, -2762, -2762, -2762,   242, -2762,   488,  2360,
   -2762
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2762, -2762, -2762, -2762, -2762,    26, -2762,    88,  -158, -2762,
   -2762, -1098,  -219, -2762, -2762, -2101, -2762, -2762, -2762, -2762,
    -806, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2372, -2762,  -975, -2762,
    1804, -2762, -2762, -2762, -2762, -2762, -2762, -2762,   342, -2762,
   -2762, -2762, -2762,  1277, -2762,   649, -2762, -2762,   -35, -2762,
   -2762,  2776, -2762,  2777,  2267, -2762, -2762, -2762, -2762, -2762,
     418,    75, -2762,   422, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762,  -106,  1071,   420, -2762, -2762,
    2463,   -53, -2762,  2707, -2762, -2762,  2704, -2762,  2617, -2762,
   -2762, -2762, -2762, -2762,  2475,  2168,   820,  2470,  -530, -2762,
   -2762, -2762, -2762, -2762,   821,  -641, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,    51, -2762,  2602,  2293,  2620,    -4,
    2237, -2762,  2278,  1565, -2762,  2456, -2762, -2762, -2762, -2762,
    2454, -2762, -2762, -2762, -2762,  -388, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,  2272, -2762,  2274, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -1347, -2762, -2762,  -751, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  -125,
   -2762, -2762,   782, -2762, -1092, -1145,    85, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762,  1871, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,  -562, -2762, -2762, -2762, -2762, -2762,
    2052, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  -541,
   -2762,  -101, -2762, -2762, -2762, -2762,  2436, -2762, -2762,  -258,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  1601, -2762, -2762, -2762, -2762,   595, -2762, -2762,
   -2762, -2762, -2762, -1269, -2762, -2762,   589, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -1026,  -552,   475,
     752, -2762,  -216,  -560,   485, -1112,  1458, -2762,   708, -2762,
   -2373,    -3,  -646, -2762, -2762, -2269,   104,  1744, -2762, -2762,
   -2762,   713,   987, -2762, -2762, -2762, -2762, -2762, -2762,    69,
   -2762,  -235, -2762,   992, -2762,   684, -2762,   384, -2762, -2762,
   -2762, -2762,  -774, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,   484, -2762, -2762, -1835, -2762,   670, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762,  1462, -2762, -2762, -2762, -2762, -2762,
   -2762,  -425, -2762, -2762, -2043, -2762, -2762, -2762, -2762,   693,
   -2183, -2762, -1116, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762,  2862, -2762, -2762,
   -2762,  2787,  2840, -2223, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,  -343, -2762, -2762, -2762, -2762, -2762,  2849, -2762, -2762,
    2873, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762,  1969, -2762, -2762, -2762, -2762, -2762,   736, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  -626,
    2144, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  1747, -2762,
   -2762,   -27, -2762, -2762,   733, -2762, -2762, -2762, -1097,  -166,
    2578, -2762, -2762, -2762, -2762,  -137, -2762, -1039,  1891,  1029,
   -1423,  1429, -2762,   738,  1691,  -314,  -490, -2762, -2762,  2136,
    1509, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,  1438, -2762,  -770, -2762,  -630, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762,  -693, -2762, -2762, -2762, -2762, -2762, -2762,
     130, -2762,  1524,  -223, -2762, -2762, -2762, -2762, -2762,   -49,
   -2762,  -494, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762,  1421, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762,  -520, -2762,   794,  2473,
   -2762, -2762,   -44, -2762,  -627, -2762, -2762,   -24,   270, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762,   791, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,   -97, -2762,  -350,  -347, -2762, -2762,  -339, -2762, -2676,
   -2762,   -85,   558, -1330, -2762, -2762, -2762,   897, -2762, -1940,
   -2762, -2762, -2762, -1979, -2762, -2762, -1948, -2762, -2762, -2762,
   -2762, -2270, -2762,   915,   614, -2762, -2762, -2762, -2762, -2762,
     391, -2762, -2762, -2762, -2762, -2762, -2762,  -676, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762,  -260, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762,  1034, -2762,  1036, -2762,   382,   715, -2762,
   -2331,  -179, -2762, -2762, -2762, -2762, -2762, -2762,   -23, -2762,
   -2762,  -473, -2762, -1136, -1320, -2762, -2762, -2762, -2762, -2762,
     -55, -2762, -2762, -2762, -2762, -2762, -1911, -2762, -2762, -2762,
   -2762, -2762, -2762, -2362,   660, -2762, -2556,   734, -2762, -2762,
   -2275,    64,    65,   334, -2762, -2040, -2531, -2762, -2762,  -231,
    -538, -2762, -2762, -2762, -2762, -1895, -2762, -2762, -2762,   -31,
   -2762,   290,  -931, -2762,   249,  -229,  1076,  -274, -2029,   316,
   -2762, -1947, -2762, -2762, -2762, -2762,   -89, -2762, -1272, -2761,
    2970, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,  -680,
   -2762, -1784, -2762,  1736, -2762, -2762,   613,   336, -2762, -2097,
     337,  -144,   154,   204, -1877, -2245,  1006,  -209,  -961, -1257,
   -2762,  1009, -2762, -2762, -2762,  1103,  -758, -2762, -2762,  -474,
    1756, -2762,   959, -2762, -2762,   435,  -129, -2762, -2762, -2762,
   -2694,  -352, -2762, -2762, -2762,  1138, -2762, -2762, -2762, -2762,
   -2762, -2762, -2762, -2762, -2762, -2762, -2747,  -368, -2762, -2748,
   -2256, -1771, -1373, -2762, -2762,  -356, -2762, -2762, -2762,   256,
   -1088,  -746,  -814,   598,  -151,   173, -2762, -2762, -2762, -2762,
    1594, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762, -2762,
    -300,  1346,  2465, -2762, -2762, -2762, -2762
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2227
static const short yytable[] =
{
      34,    36,    38,   410,   411,    38,   184,  1303,   570,  1380,
      87,   998,  1438,   268,  2112,  1426,   113,  1959,  1960,  1494,
    1332,   236,  1165,  1466,   328,  2038,   678,   104,  2022,  1435,
    1116,  2246,  1434,  2058,  2610,   962,  1171,    58,  2184,  2185,
    1025,  1028,   944,   408,   409,  2399,   578,   954,   296,   103,
     425,    58,    33,  2672,  2876,  2358,  2670,    87,  1439,    33,
      33,  1486,   110,   578,   949,   197,  2135,    33,  3129,   117,
     184,    33,   423,   122,    33,   986,   124,   125,  1061,    33,
    2334,  1061,   128,   129,  2290,  2291,  2292,  2293,  1053,   184,
    2782,  1070,  1877,  2279,  1485,  1061,   255,  2359,  1985,  1061,
    3158,  3159,  3160,    58,  3162,    33,  1087,  2531,  2547,  1445,
    1446,  1061,  1447,  1070,  1468,  1469,  1436,  3180,   578,  1099,
     232,  1872,  1070,   235,  1408,  1085,  2737,    33,   239,  1109,
      33,   366,   367,  2813,  1895,  1882,  1122,  1408,   412,   274,
    3000,  1278,   427,  1163,   429,   578,   430,   431,   432, -2225,
    1048,   274,  1123,   504,  1099,   437,    33,   326,  1099,   448,
     449,  1060,  1099,  2101,   513,   274,  3094,  1049,  1070,   563,
    3276,  1070,   255,  1029,   359,    33,  2896,  2897,  1873,  2898,
    2899,  2900,  2901,  2902,  2903,  1203,  1175,  1487,  1488,   331,
     333,   591,   446,   567,   326,   274,   334,   335,   592,  1426,
    2896,  2897,  2894,  2898,  2899,  2900,  2901,  2902,  2903,   351,
    2727,   274,  1215,  1216,    33,  1029,  1118,    33,   101,  1121,
     326,   184,  1029,  2922,    33,   184,  1985,  1078,  1164,    33,
    3252,   363,  3254,  1169,   565,    33,  1176,   369,   573,  3055,
     274,  1277,  1278,    33,  1029,  2585,    33,  3277,  3278,   398,
    2859,  2101,  3207,   578,  3499,   407,   407,   407,   407,   407,
    1396,  1397,  2886,   407,  2888,   101,   274,  1215,  1216,    33,
      54,    54,    33,  1177,  2105,  2894,  2106,  2894,  2107,   274,
     329,   330,    33,   274,  1277,  1278,    33,  3287,  1541,  1029,
     523,    33,    33,  2663,  2666,  2666,   529,  1425,  2666,   326,
    2554,   578,  2847,  2848,  2849,  2850,  2851,  2063,   600,  2551,
     326,   603,    58,    58,  1029, -2225,    33,   326,  1169,  2811,
      33,  1971,   515,  2846,    33,  2781,  1225,    33,   611,   612,
     613,   614,   114,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     575,   650,  3418, -2225,  2399,     4,  2891,    44,   326,  2728,
     632,   633,   947,  1877,   588,   635,    33,   636,  2215,  2216,
    1178,  1366,  3665, -2225,  1116,  3189,  2872,  3192,  2611,   425,
    3195,  2124,   639,   640,   641,   642,  1027,  1027,   578,   648,
    1418,  1027,  1027,  1367,   595,   524,  2128,  2111,  2151,  1901,
    2195,  2458,  2741,   580,  1027,   675,  3279,   534,   658,  1225,
     661,  1225,  2648,   930,   663,   667,   184,  2002,  3382,  2002,
    3383,  2007,   948,  1516,  1027,    54,  2956,  1027,  2557,  1899,
      43,  2960,  3060,  1027,  3373,    33,  2167,  1027,   578,   167,
      54,  1027,  1348,  1349,   578,  1027,    54,  1179,  2616,  1027,
    1027,   168,  1027,  2415,  1111,  1027,  2616,  1027,  1027,  1027,
    3367,  1419,   109,  2668,  1101,  1027,  1040,  2904,  1027,    33,
    3270,  1542,  1350,  1351,  1352,  1027,    43,  2332,  1163,   184,
      54,  1984,  1027,   575,  2676,   997,  1047,  2694,  1180,  1027,
    3042,  2904,     1,  2416,  2696,  2757,     2,  1111,  1482,  2817,
    1027,  2980,  1024,    58,  1027,  2980,     1,  1065,  1027,   107,
       2,   277,   830,   924,  1027,    33,   972,  1027,  2980,   568,
    1074,  2157,  3020,  2830,  3271,  2558,   926, -2225,  1024,  1160,
    1161,    54,  1094,  2839,  2200,    54,   670,  1011,    54,   670,
       6,    33,  3023,  3023,  3117,  3127,    53,   670,    33,   927,
     184,     1,  3182,  1103,  1181,  3666,     7,  1878,  1209,  1280,
     589,  1212,    33,   581,   398,  2742,   398,  3250,  3257,   317,
     318,   319,   320,   321,   946,   407,  3113,    76,   951,  3341,
    1440,  2422,  3361,  3361,    77,     3,  3018,  2905,  2906, -2225,
     960,  3369,   407,   174,  1475,  1476,  1878,  3082,  1892,  1122,
    1163,  3469,  3505,  2548,   564,  3437,  3505,  2280,  3566,  2095,
    2840,  2905,  2906,  2157,  3566,  1894,  2978,   175,  2926,  1228,
    1217,  1908,  3493,  1224,  3602,  3618,   327,    33, -2225,  2125,
      78,    79,  3361,  1441,  1521,  3019,  2985,  2154,    80,  2828,
    1448,  2068,  3202,  2907,  1489,  3095,    54,  1908,  1102,  1116,
    3043,  1500,  3196,  2083,  1233,  3367,  3367,  1448,   665,  1907,
    1280,   176,  2821,   518,  1024,  3395,  2217,  2907,  1543,   566,
     177,   670,  1424,   574,    33,  2302,    58,    58,    58,  1016,
      58,  1020,  1022,  3119,  1227,  1030,  1032,  1033,   579,   996,
    1038,  3123,  1022,  3333,  3310,  1041,  2326,    58,  1911,  3061,
    2009,  1544,  1228,  1280,  1228,  3288,  1033,  2038,  1437,  3184,
    2485,  3526,  3320,  3247,  1190,  3014,  3109,  1030,  1030,  3056,
     916,  1218,  1409,  2023,    33,  2136,  3500,  1033,  2986,  1954,
    1415,  1490,    33,    58,  1943,  1433,   584,  3293,   404,    58,
    1033,    58,  2624,  3266,  3001,    58,     4,  1442,    58,  1492,
    1088,    58,  2481,   404,   178,   179,  3015,   950,  1022,    54,
     404,    58,  3586,  2424,  2827,   404,   407,  1105,  1333,  1030,
    2908,  3295,    26,  1112,  2069,  3300,    58,  1970,  3472,  3054,
    2158,   295,    58,  3280,   407,   407,  3323,    48,  1961,    58,
      58,    58,  3476,   295,  2908,  1184, -2225,  1398,  1191,  3347,
      27,  1055,  2957,    58,  3122,     4,  2658,   295,   593,  3374,
    1204,  2539,  1204,   407,  1986,  1204,   407,  2034,  1204,    58,
    3384,  3419,  2108,   585,  1027,  1071,  3629,  3615,  2013,   596,
    2109,  2716,  1225,  2586,  1079,   279,  2909,   295,  3377,  2852,
    1449,  2014,  1353,   659,   155,   662,    33,  2305,  2658,   664,
     668,  2297,  2003,   295,  2004,  2658,  2008,  1449,  1319,   282,
    2909,  1319, -2225, -2225, -2225, -2225, -2225,     5,   965,   648,
     648,  1158,  2158,  2444,  1962,  1942,  1483,  2658,  2992,  2445,
     370,  1173,   295,  2617,  1188,  1111,  2910,  2911,  1194,    52,
    1963,  2623,    81,  2013,  1200,  3037,  1202,  2485,  2669,   114,
    3149,  3149,  3149,  3149,  1226,  2570,  2014,   371,   295,  2465,
    2910,  2911,  2674,  1024,  2571,  3204,     6,  3558,    82,  2677,
     102,   295,  2695,  1253,  1472,   295,     5,  1484,  1354,  2697,
    2758,  1479,  2122,  1964,  2818,    54,  2981,  1031,  2572,  3197,
    2982,  2573,   288,  2015,  1027,  1027,  1027,     7,  1227,  3243,
    1336,  3246,    33,  2984,   105,  2144,  3468,  3021,  2574,   317,
     318,   319,   320,   321,  3205,  1296,  2231,  1450,  2162,  1057,
    1058,  1355,  1965,  1451,  1452,  1453,     8,  3024,  3028,  3118,
    3128,  2013,  2133,   966,  1450,    69,  2597,  3183,    83,  3429,
    1451,  1452,  1453,  2593,  2014,  1454,  2596,  1372,  2013,   112,
    2431,  1966,  3251,  3258, -2225,  1343,     7,   670,  2015,  2612,
    1967,  2014,  1454,  2288,  3342,  2414,   118,  3362,  3368,  1373,
    1017,  1107,    33,  2288,  1303,  1267,  3370,  2306,   116,  2310,
    2311,  2312,  2313,   190,   291,     8,  3470,  3506,  2307,  3114,
    3115,  3507,  1030,  3567,  2711,    58,   292,   293,  2711,  3573,
    2392,  3587,  2393,  3640,   294, -2225,  2284,    54,  2017,  3603,
    3619,    58,  2575,   608,  1030,  3002,  2195,  3649,  2681,  2682,
    2468,    10,  2993,  1110,  2018,    33,   932,  3198,  2028,  3199,
      84,  2013,   317,   318,   319,   320,   321,    10,  3337,  3549,
    3550,  2281,   967,  3473,  2014,    37,  2015,    33,  3345,  3498,
    1169,  1455,    33,    58,  1456,  3488,  -282, -2225,  1112,   933,
    2116,  1482,  1457,  2015,  2425,  2576,  3496,  1112,  1455,   191,
   -2225,  1456,  2577,  2017,  1424,  1228,    33,  2097,  3400,  1457,
    2253,    58,    58,    58,    33,    58,  2578,    58,    58,  2018,
    2261,  1042,    33,    58,    58,  1388,    53,  1458,    33,  3387,
    2272,   958,  3392,   959,  2084,  3394,  2394,    33, -2225,  2395,
      85,  2761,    33,    54,  1458,  3003,  2016,  1526,    86,    33,
     233,  2285,  2450,  3611,  2926,  3613,  1514,  3401,    58,  2232,
     234,  2195,  1459,  2037, -2225,  3149,  3149,  1525,  2667,  3149,
      58,  2671,  -282,   194,  2233,  1533,  2015,  3360,  1103,  1459,
    2200,  1460,  1461,  3004,   241,  1229,  1230,  1231,  -282,   243,
    2479,  2017,  1462,   926,    58,    58,  1232,  1463,  1460,  1461,
     250,  2537,  1888,    58,    33,   107,   251,  2018,  2017,  1462,
    2688,  2689,  2690,    54,  1463,  1255,   927,  2234,  2010,    58,
      58,  2012,  3338,  3390,  2018,   253,  3390,   984,  2235,  1158,
     987,  -282,  2141,  2142, -2225,  2314,  1464,  1501,  2064,  1507,
      33,  3084,  3237,    33,    33,  1945,   257,  3005,   324,  2236,
    1518,  1296,  1296,  1464,   254,  1401,  2237,  3105,    33,  1296,
    2286,  3006,  1402,  2262,  2238,  1189,  1111,  2261,  1465,  1195,
    -282,   258,  1983,  1199,  1377,   106,   107,   106,   107,   425,
    1989, -2225,  2263,  2264,   259,  1465,  2239,  2471,   375,    26,
      27,  2017,  3474,    54,    33,  2200,  1391,  2863,  1303,  -282,
   -2225, -2225,  2265,   338,   339,   340,  2615,  2018,  -282,  2618,
    2619,  2620,  2621,   260,  2392,   384,  2393,  1111,   261,  2877,
   -2225,   262,  2879,  2047,  3107,    33,  2024,   263,  2983,  3049,
    2029,  2035,  2029,    54, -2225,  3508,    33,  1116,   325,    54,
    1519,  2738,  2041,  2043,  2044,  3351,  2038,    58,  2048,  2050,
    2051,  2052,  1030,    54,   264,  3557, -2225, -2225,  3244,  3563,
      54,  1030,  3007,  2240,  3298,    33,  2753,  2449,  2795,  2241,
     265,    33,  1112,    58,   376,    58,    58,    58,  3008,  2663,
    1495,  1496,  1497,  1498,    58,    58,  1030,  3149,    58,   407,
     377,   407,    58,  3149,  3149,  3449,  3149,  3149,  3149,  3149,
    1112,   385,  3605,   266,  2691,  3149,  2096,  2098, -2225,    33,
    2262, -2225, -2225,    58,    58,    54,   267,   386,  3503,  1021,
    2394,    33,  2832,  2395,  2975,   106,   107,  2404,  2549,  2263,
    2264,   413,   414,   378,  2536, -2225,  3588, -2225,  3479,   415,
    3482,  3483,  3484,  3485,   416,  2195,   418,  1093,  2858,  2265,
    3634,    54,  1248,  1249,    54,    54,  1100,   269,    58,    58,
     387,    58, -2225,  1956,  3594,  1957,  2070,  2071,  2072,    54,
     311,  1976,   379,  1977,  1978,  2375,   274,  1277,  1278,    33,
    2065,  3607,  2065,  2090,   428,  2139,   312,   407,   407,  2440,
    1368,  1369,   407,  2195,    58, -2225,  2148,  2149,  1029,   388,
      33,   380,  1207,   313,  1424,  1210,    33,  2195,  1208,   314,
     381,  1211,  3149,   315,  1214,  3149,  3149,  3149,  3149,    58,
     466,   467,   468,   469,   470,   471,   472,   473,   389,  3594,
     468,   469,   470,   471,   472,   473,    54,   390,  3390,  2166,
     107, -2225,  3405,   316, -2225,   474,  3607,  3589,   323,  1122,
    2123,  3590, -2225,   474,  1372,   346,  1242,  1381,  1382,  1383,
    1512,  3589,    33,  3480,  3134,  3590, -2225,  1243,  1501,  3480,
    2256,  2257,  3489,  3490,  3491,  3492,  1373,   347,  2042,  2200,
      33,   438,  1163,  2045, -1612,    33,  2150,  1303,   355,   415,
    2437,   348,  2180,  2181,   416,   417,   418,  2165,   352,  3149,
    3025,  2717,   353,  2718,  2054,   357, -2225,  3149,   361,  2049,
   -2225,    33,  2729,  2059,  2276,   362,  2277,  3406,  1244,   364,
    3307,  3065,   368,  2700,  3091,    33,   373,  2200,  3188,  3188,
     374,  3188,  1245,   383,  3188,  2881,  1946,  2750,  2081, -2225,
    3406,  2200,  3062,  1961,   475,   476,   477,   478,   479,   480,
    2892,   392,   475,   476,   477,   478,   479,   480,  2703,   403,
      33,  2916,   481,   482,   483,   393,  1063,   439,  2405,  2406,
     481,   482,   483,  3275,  3645,   435,    33,   399,  2602,  3407,
    1072,  3408,  1896,   440,  1077,   402, -2225,   433,  3565,   436,
    1111,  3568,  3569,  3570,  3571,  3104,  1091,  3409,  1229,  1230,
   -2225, -2225,  3407, -2225,  3408,  3410,  2186,   447,  2187,  3411,
    2188,  2189,   317,   318,   319,   320,   321,  2190,  2191, -2225,
    3409,  1246,  1947,  3620,  3621,  3376,   441, -2225,  3410,  1962,
     450, -2225,  3411,   451,  3412,  2998,  2999,   453,  1948,  3349,
    3350,  1308, -2225,   454,  1310,  1963,  1311,  1312,  1313,  1314,
    1315,   455,   456,   506,   457,   517, -2225,  3412,  2930,  2931,
     519,  2932,  2933,  2934,  2603,   442,   521,    63,   526,   527,
    3070,   528,   530,  1027,   531,  3624,   535,   536,  3078,  3079,
    2604,  1949,   537,   540,  1897,  1992,  1993, -2225,  1964,   541,
     552,   551,  1898,  2712,   443,   553,   556,   561,  1899,   571,
    1900,  2283,   484,   444,   572,   485,   577,   582,   583,  2479,
     484,  1901,   587,   485,  2269,   594,   606,  1473,  1474,   601,
    1950,  1477,  1478,  2605,   604,   605,   609,  1965,   634,   637,
     643,  2423,   644,   156,   187,   649,   651,   652,   653,  1902,
    1303,   654,   655,   656,  2754,   657,  1204,   407,   407,  1951,
     660,   676,   666,    58,    58,  1903,  1966,  2315,  1952,     1,
    1904,  2935,  2606,   931,   936,  1967,   938,   939,   940,  2936,
     945,   955,  1905,  2219,  1030,   956,  1030,  1030,   957,  1906,
    1030,  1030,  1122,  2229,   964,  2320,  1030,   969,  1163,   971,
    3471,  2607,   992,  2789,   973,  1027,  1280,   974,   187,   975,
    2608,   994,   999,  2937,  1994,  1995,  1996,  1997,  1998,  1999,
      58,  1000,  2938,  1002,  1163,  1003,   332,   187,  1004,  3188,
     337,  2273,  1008,  1005,  1007,   486,  1009,  3135,  1027,  2506,
    3136,  1010,  3200,   486,  1336,  3365,  3366,  1012,  3029,  1196,
     487,  2939,  2940,  3137,   488,  1258,  1257,  1120,   487,  1112,
    1259,  1296,   488,  1263,  1260,  1264,  2494,  2496,  1261,  1262,
    2234,  1296,  1296,  1030,  1265,  1266,  1268,  1296,  1296,  1296,
    1296,  2235,  1269,  3059,   471,   472,   473,  1270,  1112,  1271,
    1273,   489,  1309,  3139,  2436,  2192,  2941,  1316,  2193,   489,
    2194,  1317,  2236,  1318,   474,  3140,  1272,  1321,  1322,  2237,
    2024,  1324,   648,  2480,  1325,  2029,  1326,  2238,  1327,   490,
    2195,  2035,  1328,  3313,  2029,  1329,  1330,   490,  1334,  1335,
    2196,   505,  1339,  1340,  1341,  1342,  1346,   491,  1907,  2239,
    2942,  1426,  2373,  1908,  1370,   491,  3141,  1365,  2377,  1371,
    1909,  2197,   511,   512,  1374,  1375,  1378,  1376,  1399,   187,
    1384,  1395,  1400,   187,  1994,  1995,  1996,  1997,  1998,  1999,
    1403,  1404,  1910,  1406,  2198,  1407,  2402,  1911,  2199,  1411,
    1412,  1414,  1427,  1423,  1429,  3142,  1430,   107,  1470,  1030,
    1112,  3315,  1480,  2418,  2419,  2943,   407,  3143,  1990,  1991,
    1992,  1993,  1481,   475,   476,   477,   478,   479,   480,  3144,
    3145,    58,  1485,  1517,  1508,  1509,  1510,  3146,   492,  1511,
    3147,   481,   482,   483,  1515,  1521,   492,  1520,   295,  1530,
    2447,  1532,    58,  1868,  1869,  1388,  2223,  1870,  2224,  2225,
    1037,   578,  2227,  2228,  1871,  1880,  1883,  1876,  2247,  1884,
    2386,  1885,  1046,    58,  2200,  2472,  1533,  1886,  1296,  1933,
    1941,  1112,    58,  1944,  2006,  1972,  1973,  1122,  1122,  1955,
    1974,  1975,  1979,  1980,  1981,  1982,  2410,  3440,  2001,   407,
     407,  1066,  2027,  2072,   493,  2040,  3448,  2056,  2055,  2057,
    2060,  2061,   493,  2062,   407,  2075,  1492,  1083,  1084,    58,
      58,    58,  3454,  1090,  2091,    58,  1092,  2093,  2082,  2089,
    1501,  2101,  2103,  1030,  3363,  3364,  3365,  3366,  2114,  1994,
    1995,  1996,  1997,  1998,  1999,  2301,  2115,  2126,  3396,  2457,
    2916,  2127,  2129,  2747,  2131,  2140,  2154,  2143,  1027,  2145,
      58,  2161,  2163,   638,  1027,  2168,  2169,  1878,  2592,  2592,
    2171,  3497,  2592,  2207,   187,  2209,  2210,  2212,  2218,  2270,
    2274,   484,  3289,  2275,   485,  2280,  1296,  1970,  2294,  2278,
    1027,  2302,  2316,  2322,  1296,  2323,  2324,  1296,  1296,  1296,
    1296,  2622,  2329,  2327,  1030,  2328,  2332,  2361,  2627,  1296,
    3304,  2363,  2645,  2366,  2368,  3209,  3210,  3211,   184,  3213,
    3214,  3215,  3216,  3217,  3218,  2365,  2364,  2367,  3221,  2659,
    2659,  2659,  2370,  2379,  2659,  1296,  2673,   187,  2382,  2024,
    2381,  2944,  2945,  2946,  2947,  2948,  2949,  2950,  2951,  2952,
    2953,  2383,  2384,  2385,  2387,  1994,  1995,  1996,  1997,  1998,
    1999,  2411,  3543,  2389,  2390,  2391,  2388,  2403,  2698,  2408,
    2699,  2701,  2409,  2702,  2704,  1877,  2426,  2706,  2186,  2428,
    2187,  2029,  2188,  2189,  2429,  2029,    58,  1303,    58,  2190,
    2191,  2433,  2435, -2225,  1030,  2659,  2438,    58,  2402,  2442,
    2443,  2734,  2734,  2448,   486,  2461,  2455,  2451,   187,  2452,
    2469,  2475,  2487,  2485,  2534,  2098,  1232,  2535,  2546,   487,
    2552,  2560,    58,   488,  2561,  2562,  2567,  2565,  2581,  2752,
    3548,  2566,    58,  2589,  2582,  2600,  1013,  1014,  1015,  2601,
    1018,    58,  2613,  2614,  2626,    58,  2642,  2647,  2649,  2650,
    2678,  2679,  2651,  2709,  2655,  2680,  2683,  1044,  2714,  2684,
     489,  2725,  2743,  2705,  2685,  2686,  2687,  3617,  1050,  1050,
      58,  2745,  2748,  2749,  2751,  2764,  2755,  2719,  2720,  2072,
    2723,  2763,  2766,  2767,  2770,  2556,  2769,  2771,   490, -2225,
    2787,  2768,  2790,  1068,  2796,  2788,  1482,  1231,  2744,  1073,
    2794,  1075,  2803,  2805,  2814,  1082,   491,  2815,  1082,  2816,
    2819,  1082,  2831,  2833,  3595,  3596,  3597,  3598,  3599,  3600,
    2823,  1095,  2824,  2856,  3562,  2861,  2866,  2874,  2875,  2894,
    2878,  2880,  2882,  1027,  1027,  2883,  1095,  2884,  2885,  2895,
    3442,  2917,  1154,  2977,  1030,  2920,  2961,  2978,  2979,  1018,
    1167,  1170,  2987,  2990,  2994,  1185,  2301,  3452,  3577,  2659,
    2991,  2962,  2963,  1197,  2786,  2996,  1050,  2835,  2229,  2659,
    2964,  2997,  2219,  1030,   924,  1296,  1219,  3399,  3016,  1221,
    3017,  3612,  3026,  3027,  3030,  3033,  3040,   492,  2219,  1030,
    3044,  3051,    58,  2592,  3048,  3032, -2225,  3100, -2225,  3102,
   -2225, -2225, -2189,  3058,  2965,  3066,  3069, -2225, -2225,  3077,
    1939,  3087,  3110,  2966,  3099,  3129,  3111,  3119,  3130,  1985,
   -2225,  3126,  3169,  1296,  3176,  3177,  3178,  3179,  3190,   924,
    3181,  1030,  3089,  1030,  3201,  3193,  1296,  3669,  1296,  3203,
    3208,  3212,  2967,  3219,  3220,  3068,  2081,  3227,  3230,  1296,
     648,  3231,  3004,   493,  2659,    58,  2645,  2192,   648,   648,
    2193,  3232,  2194,  3233,  3226,  2659,  2854,  3562,  2855,  3234,
    3235,  3236,  3241,  3248,  3249,  3253,  3255,  3259,  3260,  3264,
    3284,  3290,  2195,  2029,  3291,  3292,  3305,  2968, -2225,  3309,
    3293,  3311,  2196,  3528,  3318,  3326,  3314,   184,  1226,  3329,
    3339,  2035,  3333,  2029,  3361,  3371,  3157,  3157,  3157,  3157,
    3352,  3372,  3378,  2503,  3353,  3381,  2373,  3354,  3355,  3356,
    3357,  3358,  1297,    58,  3385,  3403,  3422,  3421,  3423,  2975,
    3425,  2969,  3426,  3427,  3428,  3432,  2198,  1163,  3434,  3435,
    2199,  3441,  3447,  3445,  3457,  3451,  3453,  3455,  2402,  3456,
    3050,  3459,  3052,  3461, -2225,  2659,  1030,  3465,    58,  1986,
   -2225,  3475,  3477,  3494,  3509,  3519,  3521,  3486,  3520,  3522,
    3524,  3542,  3529,    58,  3541,    58,  3074,    58,  3574,  3601,
    3523,  3547,  3554,  3564,  3585,  3614,  3638,  3657,  3623,  3658,
      58,  3625,  3626,  3659,  3627,  3628,  2820,  1296,  3380,  3655,
    3302,  3668,  1219,  3660,  3073,  1221,  3637,  3022,  1331,  2153,
     407,  2779,   407,  3306,  2460,    49,  2200,  3031,    50,  2730,
    3036,  1389,    58,    58,   831,  2844,  3047,   532,  1296,  2739,
     525,   193,   198,  1001,   345,   533,  2317,   358,  2318,   669,
    2659,  2860,   350,   935,  2890,   963,  2893,   558,  1958,   941,
     560,  3635,  2376,   942,  3148,  3148,  3148,  3148,  2659,  2659,
    1183,   590,  1937,  1417,  2590,  2598,  2179,  1323,    58,  2721,
    2420,  3098,  3328,  3171,  2183, -2225,  2484,  2793, -2225,  3656,
   -2225,  2726,  2504,  2301,  1158,  2301,  2086,  3450,    46,   130,
      60,  1444,  1444,  1444,  3297,  1444,  3416,  1444,  1444,    61,
   -2225,  1296,  1296,    63,    63,    47,  2467,  1256,  1089,  2470,
   -2225,  1345,  1296,  1296,   516,  1296,  2206,  2474,  1296,  1874,
    1296,  2121,  3404,  3510,  1296,  1119,  3641,  2077,  2119,  3518,
    3093, -2225,  2067,  3240,  2134,   610,  3239,  2973,  1170,  2439,
    3222,  3286,  3438,  3436,  3433,  3269,  2715,  2362,  2331,  2825,
    1528,   184,  3644,  3398, -2225,  2249,  2675,  2250, -2225,  2845,
    3346,   648,  2564,    58,  3242,  3525,  3265,  2625,  3185,  2555,
    3186,  1219,  3393,  2889,  1221,  1389,    58,  3576,  3261,  2989,
    3431,  3420,  2222,  1881,  2974,  2659,  3245,  2659,    42,  3664,
    3431,  3157,  3157,  1925,  2927,  3157,  2928,  3348,  3125,  1889,
    1889,  2296,  3397,  2295,  2214,  3556,  2837,  3344,  2411,  1891,
    3478,  1030,  2177,  3495,  3487,  3057,  2746,  2085,     0,     0,
     677,     0,     0,  3267,  3268,     0,     0,  2706,  1297,  1297,
    2029,     0,     0,     0, -2225,     0,  1297,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2734,     0,  3391,
    3299,  2734,  3391,     0,     0,   407,     0,     0,     0,     0,
       0,  3150,  3150,  3150,  3150,    58,     0,     0,   407,     0,
      58,     0,     0,     0,     0,     0,     0,     0,  3439,    58,
       0,     0,     0,  1027,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3330,     0,
       0,  3191,     0,  3194,  2659,     0,     0,     0,     0,     0,
       0,     0,     0,  2835,  2659,     0,  2219,  2219,     0,  3148,
    3148,     0,     0,  3148,     0,     0,  3303,     0,   473,     0,
       0,     0,     0,    63,  3359,    63,  1170,  1082,     0,     0,
       0,     0,     0,     0,  2076,  1095,   474,     0,  1170,     0,
       0,     0,  2087,     0,     0,    58,  2219,     0,     0,     0,
       0,     0,  3321,     0,     0,     0,     0,     0,     0,  1030,
    1219,     0,     0,  1221,  1154,     0,     0,  1112,     0,     0,
    1112,     0,     0,  1296,     0,     0,  1296,     0,  1296,     0,
    2659,  2283,     0,  3157,     0,     0,     0,     0,     0,  3157,
    3157,     0,  3157,  3157,  3157,  3157,     0,     0,     0,     0,
       0,  3157,     0,    58,     0,     0,     0,     0,  2120,  1154,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3263,     0,   475,   476,   477,   478,   479,
     480,  1296,     0,     0,  2146,     0,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,     0,  2251,  2252,     0,
       0,   407,     0,     0,  2268,    58,     0,     0,     0,  2173,
    1276,     0,     0,     0,   274,  1277,  1278,    33,     0,  3553,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
     598,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,  3157,     0,
      58,  3157,  3157,  3157,  3157,  1296,  3150,  3150,  2659,     0,
    3150,     0,     0,     0,     0,   474,     0,     0,     0,  1112,
       0,  3148,     0,     0,  3391,     0,     0,  3148,  3148,     0,
    3148,  3148,  3148,  3148,   184,     0,  2659,     0,  2659,  3148,
       0,  1296,     0,     0,     0,  3443,     0,     0,     0,     0,
       0,     0,  1279,     0,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,     0,     0,     0,   160,    33,     0,
      58,     0,     0,     0,     0,    58,     0,    58,     0,  3466,
       0,     0,     0,   484,     0,  3157,   485,     0,     0,     0,
       0,   648,     0,  3157,     0,  2659,     0,     0,     0,     0,
       0,  2301,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,     0,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,   481,   482,   483,     0,  3330,     0,     0,     0,
       0,     0,  1296,     0,     0,     0,  3148,     0,   161,  3148,
    3148,  3148,  3148,  3572,  2441,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,  3575,     0,     0,
       0,     0,  1112,     0,     0,     0,  1296,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,  2482,     0,     0,    58,    58,    58,
      58,    58,    58,     0,     0,     0,   486,     0,     0,  3606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,   488,     0,     0,  3150,     0,
       0,     0,     0,  3148,  3150,  3150,     0,  3150,  3150,  3150,
    3150,  3148,     0,     0,     0,     0,  3150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,   485,     0,     0,     0,    54,
       0,   164,     0,     0,     0,  1296,     0,  3646,     0,     0,
     490,  1219,     0,  2205,  1221,     0,  3604,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3662,  3663,  3646,     0,     0,     0,
       0,     0,     0,    58,     0,  3670,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2255,     0,     0,  3150,     0,   271,  3150,  3150,  3150,  3150,
       0,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,    33,     0,     0,     0,     0,   165,     0,
       0,     0,     0,     0,  1280,     0,     0,     0,  1297,   492,
       0,     0,     0,  3653,     0,   486,     0,     0,  1297,  1297,
       0,     0,     0,     0,  1297,  1297,  1297,  1297,     0,     0,
     487,     0,     0,   166,   488,  1281,     0,     0,  1282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1283,     0,     0,     0,     0,     0,     0,     0,     0,
    3150,     0,     0,     0,     0,     0,     0,   167,  3150,     0,
       0,   489,     0,   161,     0,   493,     0,     0,   277,   168,
       0,     0,     0,     0,     0,   162,     0,     0,     0,  2775,
    2776,  1284,     0,     0,     0,     0,     0,     0,     0,   490,
    2785,     0,     0,  1285,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   169,   491,     0,     0,
       0,     0,     0,     0,  2797,  2798,  2799,  2800,  2801,  2802,
       0,   170,     0,     0,  2807,  2808,  2809,  2810,     0,   171,
       0,  2812,     0,     0,  1286,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,     0,     0,     0,   271,     0,
       0,  2432,     0,     0,     0,     0,     0,   272,   273,     0,
    1050,     0,     0,   274,   275,   276,    33,  1287,     0,     0,
       0,     0,  1170,  1288,     0,     0,     0,     0,     0,     0,
       0,     0,  1289,  1290,     0,  1291,   173,     0,   492,     0,
       0,     0,     0,   156,    54,  1297,   164,  1292,  1293,     0,
       0,     0,  1154,     0,     0,  1294,     0,     0,  1295,     0,
       0,   174,     0,  2864,  2865,     0,   295,     0,     0,     0,
    2869,  2870,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,     0,     0,     0,  1170,
    2538,  1170,     0,     0,     0,  1018,   161,     0,     0,     0,
       0,   277,     0,     0,   493,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
    2584,     0,     0,     0,     0,   163,     0,     0,   177,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   278,     0,
       0,     0,     0,  1297,     0,     0,     0,     0,     0,     0,
       0,  1297,     0,     0,  1297,  1297,  1297,  1297,     0,     0,
       0,     0,     0,     0,     0,     0,  1297,     0,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1297,     0,     0,     0,     0,  3038,  3039,     0,
       0,     0,   167,     0,     0,     0,  3046,     0,     0,     0,
       0,     0,   178,   179,   168,     0,     0,    54,     0,   164,
       0,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   280,     0,     0,
     281,     0,     0,  3080,  3081,   474,  1170,     0,  1170,     0,
       0,   169,     0,     0,     0,     0,   282,  1170,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
    3101,   283,  3103,     0,   284,     0,   187,   285,     0,     0,
       0,     0,  1170,     0,     0,     0,   286,   172,     0,  1219,
       0,     0,  1221,     0,     0,     0,     0,     0,     0,     0,
       0,  2759,     0,     0,     0,  2762,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   278,     0,     0,     0,     0,  1385,   287,     0,     0,
    2784,   173,     0,  3172,  3173,     0,     0,  3174,  3175,   288,
       0,     0,     0,     0,   475,   476,   477,   478,   479,   480,
     289,   166,     0,     0,     0,     0,   174,     0,     0,     0,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     280,     0,     0,   281,   176,     0,  3229,     0,     0,     0,
       0,   291,  1297,   177,   169,     0,     0,     0,     0,   282,
       0,     0,     0,   292,   293,     0,     0,     0,     0,   170,
       0,   294,  2862,     0,   283,     0,     0,   284,     0,     0,
     285,     0,   295,     0,     0,     0,     0,     0,     0,   286,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1297,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1297,     0,  1297,     0,     0,     0,     0,
       0,     0,   484,     0,     0,   485,  1297,  3296,     0,     0,
     287,  3301,     0,     0,   173,  1170,     0,   178,   179,     0,
       0,     0,   288,     0,     0,     0,     0,     0,     0,     0,
    3308,     0,     0,   289,     0,  2722,     0,     0,     0,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3319,
    2629,     0,     0,     0,     0,  1297,     0,     0,     0,  1274,
    1275,  1276,     0,   290,     0,   274,  1277,  1278,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1170,     0,     0,     0,  2760,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,   176,   469,   470,
     471,   472,   473,     0,   291,     0,   177,     0,  1170,     0,
       0,     0,   474,     0,     0,   486,   292,   293,     0,     0,
     474,     0,     0,  3071,   294,  1044,     0,  3075,     0,     0,
     487,     0,     0,     0,   488,   295,     0,     0,     0,     0,
    3086,     0,     0,  1279,  1297,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,  3106,  3108,   460,  1297,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
     178,   179,     0,     0,     0,     0,     0,     0,     0,   490,
       0,  1297,  1297,  1297,  1297,     0,   474,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,   491,  3170,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,     0,     0,     0,     0,     0,  1297,  1297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1297,
    1297,     0,  1297,     0,     0,  1297,     0,  1297,     0,  1111,
       0,  1297,     0,     0,     0,     0,     0,     0,  3464,     0,
       0,  3467,     0,     0,     0,     0,  1050,  1050,  1050,     0,
    1050,  1050,  1050,  1050,  1050,  1050,     0,     0,   492,  1050,
       0,     0,     0,     0,   474,   475,   476,   477,   478,   479,
     480,     0,     0,  3223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,  3238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2629,     0,     0,     0,
       0,     0,     0,     0,     0,  1274,  1275,  1276,     0,     0,
       0,   274,  1277,  1278,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0,     0,   484,
       0,     0,   485,  2630,     0,     0,     0,   484,     0,   271,
     485,     0,     0,     0,     0,     0,     0,  1170,   272,   273,
       0,     0,     0,     0,   274,   275,   276,    33,     0,   187,
       0,     0,     0,   475,   476,   477,   478,   479,   480,     0,
       0,     0,     0,     0,     0,  1170,     0,     0,     0,  3551,
    1154,   481,   482,   483,     0,     0,  1219,     0,     0,  1221,
       0,     0,     0,     0,     0,     0,  1274,  1275,  1276,  1279,
       0,     0,   274,  1277,  1278,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   485,  3578,  3579,     0,
    3581,     0,  3583,  3584,     0,  1280,     0,   161,     0,     0,
       0,     0,   277,     0,     0,     0,  1297,  1297,     0,   162,
    1297,     0,   486,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,  1281,   487,     0,  2631,
       0,   488,     0,     0,     0,   487,   163,     0,     0,   488,
       0,  2632,  1283,     0,     0,  1154,     0,     0,     0,     0,
    1279,     0,     0,     0,     0,     0,  3630,     0,  3631,     0,
       0,     0,     0,     0,  1297,     0,     0,  1297,   489,  1970,
    1297,     0,     0,  1297,     0,  1297,   489,     0,     0,     0,
       0,   484,  1284,     0,   485,  1111,     0,     0,     0,     0,
       0,     0,  3643,     0,  1285,     0,   490,     0,     0,     0,
       0,     0,     0,  3223,   490,     0,   486,     0,  3650,  3651,
       0,     0,  3652,     0,   491,  3654,     0,     0,     0,     0,
       0,   487,   491,     0,     0,   488,     0,     0,    54,     0,
     164,     0,     0,   271,     0,  1286,     0,     0,  1297,     0,
       0,     0,   272,   273,     0,     0,     0,     0,   274,   275,
     276,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,  1170,     0,     0,  1287,     0,
       0,     0,     0,     0,  1288,     0,  1111,     0,     0,     0,
       0,     0,  1170,  1289,  1290,     0,  1291,     0,     0,  2630,
     490,     0,     0,     0,     0,   492,     0,     0,  1292,  1293,
       0,     0,     0,   492,   486,     0,  1294,     0,   491,  1295,
    1154,     0,  1297,     0,     0,     0,     0,   295,     0,   487,
       0,     0,     0,   488,     0,     0,     0,   165,  1297,     0,
       0,   161,   278,     0,  1297,  1297,   277,  1297,  1297,  1297,
    1297,     0,     0,   162,     0,     0,  1297,     0,  1297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1297,
     489,   493,   166,     0,   569,     0,     0,     0,     0,   493,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3223,     0,     0,     0,     0,  3513,     0,  3515,   490,   492,
       0,  1280,     0,     0,     0,     0,   167,     0,     0,     0,
       0,     0,     0,  1274,  1275,  1276,   491,     0,   168,   274,
    1277,  1278,    33,     0,     0,     0,     0,     0,  1170,     0,
       0,     0,  1281,     0,     0,  2631,   279,     0,     0,     0,
       0,   280,     0,  1219,   281,     0,  1221,  2632,  1283,     0,
       0,     0,   187,     0,     0,   169,     0,     0,     0,  1297,
     282,     0,     0,  1297,     0,   493,  1297,  1297,  1297,  1297,
     170,     0,    54,     0,   164,   283,     0,     0,   284,     0,
       0,   285,     0,     0,     0,     0,     0,     0,  1284,  1297,
     286,   172,  1280,  1297,     0,     0,     0,   492,     0,     0,
    1285,     0,     0,     0,     0,     0,     0,  1279,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1444,  1444,  1444,
    1444,  1444,  1444,  1281,     0,     0,  1282,     0,     0,     0,
    3090,   287,     0,     0,     0,   173,     0,     0,     0,  1283,
       0,  1286,     0,   288,     0,     0,     0,     0,     0,     0,
    1297,     0,     0,     0,   289,     0,     0,     0,  1297,     0,
     174,     0,     0,   493,     0,     0,  1970,     0,     0,     0,
       0,   165,     0,     0,  1287,     0,   278,     0,     0,  1284,
    1288,     0,     0,     0,   290,     0,     0,     0,     0,  1289,
    1290,  1285,  1291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1297,     0,  1292,  1293,   166,     0,     0,     0,
       0,     0,  1294,     0,     0,  1295,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,   176,     0,
       0,     0,  1286,  1111,     0,   291,     0,   177,     0,     0,
     167,     0,     0,     0,     0,     0,     0,   292,   293,     0,
    1219,     0,   168,  1221,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1287,   295,     0,     0,     0,
     279,  1288,     0,     0,     0,   280,     0,   132,   281,     0,
    1289,  1290,     0,  1291,     0,     0,     0,     0,     0,   169,
       0,     0,     0,     0,   282,  1292,  1293,     0,     0,     0,
       0,     0,     0,  1294,   170,     0,  1295,     0,     0,   283,
       0,     0,   284,     0,   295,   285,   133,     0,     0,     0,
       0,   178,   179,     0,   286,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,  2630,     0,     0,
       0,     0,     0,  1545,  1546,  1547,  1548,  1549,  1550,     0,
    1551,  1552,  1553,     0,     0,     0,  1554,  1555,  1556,  1557,
    1558,  1559,     0,     0,     0,   287,     0,     0,     0,   173,
       0,  1560,     0,     0,     0,   136,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   289,     0,
       0,  1561,     0,     0,   174,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,   290,     0,
       0,     0,     0,     0,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1280,
     141,     0,     0,     0,     0,     0,     0,     0,  1562,     0,
       0,     0,     0,     0,     0,     0,     0,  1563,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,   291,
    1281,   177,     0,  2631,     0,  1564,  1565,     0,     0,     0,
     142,   292,   293,     0,  1566,  2632,  1283,     0,     0,   294,
       0,  1567,  1568,     0,     0,  1569,  1570,  1571,  1572,     0,
     295,  1573,  1574,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,  1284,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1285,     0,
       0,  1575,     0,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,   148,     0,   178,   179,     0,     0,     0,
       0,     0,     0,  1576,     0,     0,     0,     0,     0,  1577,
       0,     0,   149,     0,     0,  2176,  1578,     0,  1579,  1286,
       0,     0,     0,  1580,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1581,
       0,     0,  1287,     0,     0,     0,     0,     0,  1288,     0,
       0,     0,     0,     0,     0,     0,     0,  1289,  1290,     0,
    1291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1292,  1293,     0,     0,     0,  1582,     0,     0,
    1294,     0,     0,  1295,     0,     0,     0,     0,     0,     0,
    1583,   295,     0,     0,     0,     0,  1584,     0,     0,     0,
       0,     0,     0,     0,     0,  1585,  1586,     0,     0,     0,
       0,     0,  1587,     0,     0,  1588,  1589,     0,     0,     0,
    1590,     0,     0,     0,     0,     0,  1591,  1592,     0,     0,
       0,     0,     0,  1593,  1594,  1595,     0,     0,  1596,  1597,
    1598,     0,     0,     0,  1599,     0,     0,     0,  1600,     0,
    1601,     0,     0,     0,     0,     0,     0,  1602,  1603,  1604,
    1605,     0,  1606,  1607,     0,     0,     0,  1608,  1609,     0,
    1610,  1611,  1612,  1613,  1614,  1615,  1616,     0,     0,     0,
       0,     0,  1617,  1618,  1619,     0,  1620,  1621,     0,     0,
       0,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,     0,
    1630,     0,     0,     0,  1631,  1632,  1633,  1634,  1635,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,
    1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,  1656,
    1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,  1666,
    1667,     0,  1668,  1669,     0,     0,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,     0,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,     0,     0,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,     0,  1704,  1705,  1706,  1707,     0,  1708,
    1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,
    1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,  1738,
    1739,  1740,  1741,  1742,  1743,     0,  1744,  1745,  1746,  1747,
    1748,  1749,     0,     0,  1750,  1751,     0,  1752,  1753,  1754,
    1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,
    1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,     0,     0,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
    1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,
    1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,  1832,
    1833,  1834,  1835,  1836,  1837,  1838,  1839,     0,     0,     0,
       0,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1851,     0,     0,     0,     0,   132,     0,     0,
    1852,     0,     0,     0,     0,  1853,     0,     0,     0,  1854,
       0,     0,  1855,  1856,  1857,  1858,     0,     0,  1859,  1860,
       0,  1861,  1862,  1863,  1545,  1546,  1547,  1548,  1549,  1550,
       0,  1551,  1552,  1553,     0,     0,   133,  1554,  1555,  1556,
    1557,  1558,  1559,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1560,     0,     0,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1561,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1562,
       0,     0,     0,     0,     0,   139,     0,     0,  1563,     0,
       0,     0,     0,     0,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1564,  1565,     0,     0,
     141,     0,     0,     0,     0,  1566,     0,     0,     0,     0,
       0,     0,  1567,  1568,     0,     0,  1569,  1570,  1571,  1572,
       0,     0,  1573,  1574,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1575,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,  1576,   145,     0,     0,   146,     0,
    1577,     0,     0,     0,     0,     0,     0,  1578,     0,  1579,
       0,     0,     0,     0,  1580,     0,     0,     0,     0,   147,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1581,     0,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1583,     0,     0,     0,     0,     0,  1584,     0,     0,
       0,     0,     0,     0,     0,     0,  1585,  1586,     0,     0,
       0,     0,     0,  1587,     0,     0,  1588,  1589,     0,     0,
       0,  1590,     0,     0,     0,     0,     0,  1591,  1592,     0,
       0,     0,     0,     0,  1593,  1594,  1595,     0,     0,  1596,
    1597,  1598,     0,     0,     0,  1599,     0,     0,     0,  1600,
       0,  1601,     0,     0,     0,     0,     0,     0,  1602,  1603,
    1604,  1605,     0,  1606,  1607,     0,     0,     0,  1608,  1609,
       0,  1610,  1611,  1612,  1613,  1614,  1615,  1616,     0,     0,
       0,     0,     0,  1617,  1618,  1619,     0,  1620,  1621,     0,
       0,     0,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
       0,  1630,     0,     0,     0,  1631,  1632,  1633,  1634,  1635,
    1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,
    1666,  1667,     0,  1668,  1669,     0,     0,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,     0,  1680,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,
    1692,  1693,  1694,     0,     0,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,     0,  1704,  1705,  1706,  1707,     0,
    1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,
    1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,     0,  1744,  1745,  1746,
    1747,  1748,  1749,     0,     0,  1750,  1751,     0,  1752,  1753,
    1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,
    1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,
    1774,  1775,  1776,  1777,     0,     0,  1778,  1779,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839, -2226,     0,
       0,     0,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,     0, -2226,     0, -2226,     0, -2226, -2226,
       0,     0,     0,  1851,     0, -2226, -2226,     0,     0,     0,
       0,  1852,     0,     0,     0,     0,  1853,     0,     0,     0,
    1854,     0,     0,  1855,  1856,  1857,  1858,     0,     0,  1859,
    1860,     0,  1861,  1862,  1863,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2226,     0, -2226,
       0,     0,     0,     0,     0,     0,     0,     0,  1274,  1275,
    1276,     0,     0,     0,   274,  1277,  1278,    33,     0,     0,
       0,     0,     0,     0, -2226,     0,     0,     0,     0,     0,
       0, -2226,     0, -2226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2226,     0,     0,     0,     0, -2226,
       0,     0,     0,     0,     0,     0,     0, -2226,     0,     0,
       0, -2226,     0,     0,     0,     0,     0, -2226,     0,     0,
       0, -2226, -2226, -2226, -2226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1279, -2226,     0,     0, -2226,     0, -2226,     0,
       0,     0,     0,     0,     0, -2226,     0,     0,     0,     1,
       0,     0,     0,     2,     0,   679,   680,   681, -2226,     0,
       0,   682,     0,     0,   683,     0,     0,     0, -2226,     0,
       0,     0,     0,   684,   685,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2226,
   -2226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2226,     0,     0,     0,     0,     0,
       0,     0, -2226,     0,     0,     0, -2226,     0,   686,   687,
       0,     0,     0,   688, -2226, -2226, -2226,     0,     0,     0,
       0,     0,     0,   689,   690,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     692,     0,     0,     0,     0,     0,     0,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,   693,     0,     0,
     694,   695,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   696,     0,   697,   698,   699,
       0,     0, -2226,     0,     0,     0,     0,   700,   701,     0,
     702,   703,   704, -2226,     0,     0,     0,     0,   705,     0,
       0,   706,     0,   707,   708,   709,     0,     0,     0,     0,
       0,   710,     0,   711,   712,     0,   713,     0,   714,   715,
       0,     0,   716,     0,     0,   717,   718,   719,   720,   721,
     722,     0,     0, -2226,   723,   724,   725,     0,   726,     0,
       0,     0,   727,     0,   728,   729,     0,     0,     0,     0,
     730,     0,     0,   731,     0,     0,   732,     0,   733,     0,
     734,     0,   735,     0,     0,     0,   736,   737,     0,   738,
     739,   740,     0,     0,   741,     0,   742,   743,     0,   744,
       0,     0,     0,     0,     0,     0,     0,   745,   746,     0,
       0,     0,     0,     0, -2226,     0,     0,     0,     0,     0,
     747,     0,     0,   748,   749,     0,     0,   750,   751,     0,
       0,   752,   753,     0,     0,     0,     0,     0,     0,     0,
     754,   755,   756,     0,   757,     0,     0,     0,     0,     0,
   -2226,     0,     0,     0,   758,   759,   760,     0,   761,     0,
       0,     0,   762,   763,     0,     0,     0,   764,     0,     0,
       0,     0,     0,     0,  1280,   765,     0,     0,     0,     0,
       0,     0,     0,   766,   767,   768,     0,     0,     0,     0,
       0,   769,   770,     0,     0,     0, -2226,     0,     0,   771,
       0,     0,   772,     0,     0,  1281,   773,   774,  1282,     0,
   -2226, -2226, -2226, -2226, -2226, -2226, -2226,   775, -2226, -2226,
       0,  1283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   776, -2226,     0,     0,     0,     0,
       0,     0,   777,     0,     0,     0,     0,     0,   778,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   779,
    2476,  1284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,   780,  1285,     0,     0,     0,     0,   781,     0,
     782,   783,     0,     0,     0,     0,     0,     0,   784,     0,
       0,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,  1286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,     0,   785,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   786,     0,
       0,     0,     0,     0,     0,   787,     0,  1287,     0,     0,
       0,     0,     0,  1288,     0,     0,     0,     0,     0,     0,
       0,     0,  1289,  1290,     0,  1291,     0,     0,     0,   788,
     789,     0,     0,     0,   790,     0,     0,  1292,  1293,     0,
       0,     0,     0,     0,     0,  1294,   791,     0,  1295,     0,
       0,     0,   792,   793,   794,   795,   295,     0,     0,   796,
       0,     0,     0,   797,     0,     0,     0,     0,     0,     0,
     798,   799,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   800,     0,   801,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,   802,     0,   803,     0,     0,   804,
       0,     0,   481,   482,   483,   805,     0,     0,     0,     0,
       0,     0,     0,   458,   459,   460,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,   806,     0,     0,   807,     0,     0,     0,     0,   808,
       0,     0,   809,   810,     0,     0,     0,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   811,     0,     0,
       0,   458,   459,   460,   812,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   813,   814,   815,
     816,   817,   818,   819,     0,   474,   820,     0,   821,     0,
     822,   458,   459,   460,     0,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   484,     0,     0,   485,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,     0,     0,
       0,     0,     0,     0,     0,   458,   459,   460,     0,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,   476,   477,   478,   479,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   481,   482,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,   488,   586,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,   485,   475,   476,
     477,   478,   479,   480,     0,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,   481,   482,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   490,
       0,     0,   484,     0,     0,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,     0,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,   484,     0,     0,   485,     0,     0,     0,     0,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,   488,   597,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,   485,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,   489,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,   488,   607,     0,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,   490,     0,     0,   493,   486,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,     0,   491,
     487,   489,     0,     0,   488,   970,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   490,
       0,     0,     0,     0,   487,     0,     0,     0,   488,   976,
     492,     0,     0,     0,   458,   459,   460,   491,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,   474,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   492,     0,
     484,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   490,     0,     0,   493,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,     0,     0,     0,     0,     0,     0,   492,   458,
     459,   460,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0,     0,     0,
       0,     0,     0,   474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   475,   476,   477,
     478,   479,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   481,   482,   483,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,   488,   977,     0,     0,   458,   459,   460,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,   493,   489,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,   458,   459,
     460,     0,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   491,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,     0,     0,   484,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,   458,   459,   460,     0,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,   481,   482,   483,
       0,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,   458,   459,   460,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     484,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,     0,     0,     0,     0,     0,   486,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,   488,   978,   475,
     476,   477,   478,   479,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,   482,   483,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,   489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,   474,
     485,     0,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,   490,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   481,   482,   483,     0,   487,     0,
     491,     0,   488,   979,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   485,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,   459,   460,     0,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,   490,   475,   476,
     477,   478,   479,   480,     0,     0,   474,   484,     0,     0,
     485,   492,     0,     0,     0,   491,   481,   482,   483,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,   488,
       0,     0,     0,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,   485,     0,     0,
       0,     0,     0,   474,     0,     0,   489,   493,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,   981,
       0,     0,     0,     0,     0,     0,   492,   487,     0,     0,
       0,   488,     0,     0,   490,   475,   476,   477,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   481,   482,   483,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,   488,
       0,   982,     0,     0,     0,     0,   484,     0,     0,   485,
       0,     0,   493,     0,     0,     0,   490,     0,     0,     0,
       0,     0,   475,   476,   477,   478,   479,   480,     0,     0,
       0,     0,     0,     0,   491,     0,   489,   486,     0,     0,
     481,   482,   483,     0,     0,     0,     0,     0,     0,   985,
       0,     0,   487,   492,     0,     0,   488,     0,     0,  1125,
    1126,  1127,  1128,     0,   490,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,  1274,  1275,  1276,
       0,     0,   491,   274,  1277,  1278,    33,     0,     0,     0,
       0,     0,   474,   489,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,   492,   485,     0,     0,   493,
       0,   490,   474,     0,     0,     0,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,     0,     0,   487,     0,     0,     0,   488,     0,
       0,   465,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,  1279,     0,     0,     0,     0,     0,   474,     0,     0,
     484,   493,  1129,   485,     0,   489,     0,     0,     0,     0,
    1130,   475,   476,   477,   478,   479,   480,     0,   980,  1131,
       0,     0,  1132,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,   490,     0,     0,     0,     0,     0,     0,
     492,   475,   476,   477,   478,   479,   480,     0,     0,   493,
       0,   491,     0,     0,     0,     0,   486,     0,     0,   481,
     482,   483,     0,     0,     0,  1133,     0,     0,     0,     0,
       0,   487,  1134,     0,     0,   488,     0,     0,     0,     0,
       0,     0,  1274,  1275,  1276,     0,     0,     0,   274,  1277,
    1278,    33,     0,     0,     0,     0,   475,   476,   477,   478,
     479,   480,     0,     0,     0,     0,   493,     0,     0,     0,
       0,     0,   489,     0,   481,   482,   483,  1111,  3132,  3133,
       0,     0,     0,   486,   274,  1277,  1278,    33,     0,  1135,
       0,     0,   492,     0,     0,     0,     0,     0,   487,     0,
     490,     0,   488,     0,  3132,  3133,     0,     0,     0,     0,
     274,  1277,  1278,    33,  1136,     0,     0,     0,   491,     0,
       0,  1137,     0,  1138,     0,     0,     0,     0,     0,   484,
       0,     0,   485,  1139,     0,     0,  1279,     0,     0,   489,
    3132,  3133,     0,     0,     0,     0,   274,  1277,  1278,    33,
       0,     0,     0,     0,     0,     0,     0,     0,   493,   484,
       0,  1140,   485,     0,     0,     0,     0,   490,     0,  1141,
       0,     0,  3134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3134,   492,
       0,     0,     0,     0,     0,     0,  1142,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1143,     0,     0,  3134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1111,     0,     0,   493,   492,   487,  1144,     0,
       0,   488,     0,     0,     0,     0,     0,     0,     0,  1145,
       0,     0,   486,  1280,     0,     0,     0,     0,     0,     0,
       0,     0,  2335,     0,     0,     0,     0,   487,  1111,     0,
       0,   488,     0,     0,     0,     0,     0,     0,   489,     0,
       0,     0,     0,     0,  1281,     0,     0,  1282,     0,     0,
       0,     0,     0,     0,  1111,     0,     0,     0,     0,     0,
    1283,     0,   493,     0,     0,     0,   490,   486,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,   491,     0,   488,     0,     0,     0,
    1111,     0,   199,     0,     0,   200,   490,     0,     0,  3559,
    1284,     0,     0,     0,     0,     0,     0,  1146,  1147,  1148,
       0,     0,  1285,     0,   491,     0,     0,     0,     0,     0,
    1149,     0,     0,   489,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2507,  2508,  2509,  2510,     0,     0,  2511,  2512,     0,
       0,   490,     0,  1286,     0,     0,     0,     0,     0,     0,
    2507,  2508,  2509,  2510,     0,   492,  2511,  2512,     0,   491,
       0,   201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1287,   202,   203,     0,
       0,     0,  1288,     0,     0,   492,     0,   204,  1280,     0,
       0,  1289,  1290,     0,  1291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1292,  1293,     0,     0,
       0,     0,     0,  1150,  1294,     0,     0,  1295,     0,  1281,
       0,   493,  1282,     0,  1280,   295,     0,     0,     0,     0,
    2513,     0,     0,     0,     0,  1283,     0,     0,     0,     0,
     492,     0,     0,     0,     0,     0,     0,     0,  2336,  2513,
    1280,   493,     0,     0,     0,  3135,     0,     0,  3136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2337,  2338,
    2339,  3137,     0,     0,     0,  1284,     0,     0,     0,     0,
       0,  3135,     0,     0,  3136,     0,  1280,  1285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3137,     0,     0,
       0,     0,     0,     0,     0,     0,   493,  2340,     0,     0,
    3138,  3139,     0,     0,     0,     0,     0,  3135,     0,  2341,
    3136,     0,     0,  3140,  1970,     0,     0,     0,  1286,     0,
    2342,     0,     0,  3137,     0,     0,     0,  3139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2343,     0,  3140,
       0,     0,     0,     0,  3530,     0,     0,  2344,   205,     0,
       0,  1287,     0,     0,  3141,     0,     0,  1288,     0,     0,
       0,     0,  2345,  3139,     0,     0,  1289,  1290,     0,  1291,
       0,     0,     0,     0,     0,  3140,     0,     0,     0,     0,
    3141,  1292,  1293,     0,     0,     0,     0,   206,     0,  1294,
       0,     0,  1295,  3142,     0,     0,     0,     0,     0,     0,
     295,  3531,     0,     0,     0,  3143,   207,   208,   209,   210,
    2346,     0,     0,     0,     0,     0,  3141,  3144,  3145,  3142,
       0,     0,     0,     0,   211,  3146,  3532,     0,  3147,     0,
       0,  3143,     0,     0,     0,  3533,   295,     0,     0,     0,
    2347,     0,     0,  3144,  3145,     0,   212,     0,     0,     0,
    2348,  3146,     0,     0,  3147,  3142,     0,  2514,   213,     0,
       0,     0,   295,     0,     0,     0,     0,  3143,     0,   214,
    2515,  2349,     0,  3534,     0,  2350,  2514,     0,     0,  3144,
    3145,  3535,     0,     0,     0,     0,   215,  3146,     0,  2515,
    3147,     0,     0,     0,     0,     0,   216,     0,   295,     0,
       0,     0,     0,  2351,     0,     0,     0,     0,     0,     0,
       0,   217,  2352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2516,     0,     0,     0,     0,     0,  2517,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,  2516,     0,     0,     0,     0,     0,  2517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3536,   219,     0,     0,     0,  2518,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
       0,     0,     0,     0,     0,     0,   221,  2518,     0,   222,
       0,     0,  2519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2520,  2521,     0,     0,     0,     0,  2522,     0,
     223,  2519,     0,     0,   224,     0,     0,     0,  2523,     0,
       0,  2520,  2521,     0,     0,     0,     0,  2522,     0,     0,
       0,     0,     0,   225,     0,     0,     0,  2523,     0,     0,
    2524,     0,     0,  2525,  2526,     0,     0,     0,  2527,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,  2524,
       0,     0,  2525,  2526,     0,     0,     0,  2527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2529,     0,     0,     0,
       0,     0,     0,     0,  2528,     0,     0,     0,     0,     0,
       0,     0,     0,  3537,     0,  2529
};

static const short yycheck[] =
{
       3,     4,     5,   261,   262,     8,   107,   968,   396,  1048,
      45,   652,  1124,   171,  1437,  1112,    69,  1274,  1275,  1164,
     995,   127,   792,  1139,   190,  1355,   546,    54,  1348,  1121,
     776,  1908,  1120,  1380,  2279,   595,   794,    40,  1873,  1874,
     686,   687,   572,   259,   260,  2088,     5,   588,   173,    52,
     266,    54,    27,  2328,  2610,  2034,  2326,    92,    26,    27,
      27,  1159,    65,     5,    20,   118,     5,    27,     5,    72,
     171,    27,    25,    76,    27,   637,    79,    80,   724,    27,
    2028,   727,    85,    86,  1979,  1980,  1981,  1982,   715,   190,
    2463,   737,     5,  1970,     5,   741,   149,  2037,     5,   745,
    2848,  2849,  2850,   106,  2851,    27,   752,  2208,   147,  1135,
    1136,   757,  1138,   759,  1140,  1141,     8,  2878,     5,   765,
     123,  1213,   768,   126,     5,   751,  2395,    27,   131,   775,
      27,   237,   238,  2506,  1246,  1227,   782,     5,   263,    24,
      25,    26,   267,   789,   269,     5,   271,   272,   273,   110,
     712,    24,   782,    26,   800,   280,    27,     5,   804,   284,
     285,   723,   808,     5,   322,    24,   110,    26,   814,     5,
      56,   817,   225,    25,   227,    27,     9,    10,  1217,    12,
      13,    14,    15,    16,    17,   812,   153,   129,   130,   192,
      19,    19,   281,     5,     5,    24,    25,    26,    26,  1296,
       9,    10,     6,    12,    13,    14,    15,    16,    17,   213,
      20,    24,    25,    26,    27,    25,   778,    27,    45,   781,
       5,   322,    25,    26,    27,   326,     5,    25,   790,    27,
    2991,   234,  2993,    25,     5,    27,   203,   240,     5,    20,
      24,    25,    26,    27,    25,     5,    27,   133,   134,   252,
    2581,     5,  2928,     5,   191,   258,   259,   260,   261,   262,
     135,   136,  2624,   266,  2626,    92,    24,    25,    26,    27,
     238,   238,    27,   240,   116,     6,   118,     6,   120,    24,
      25,    26,    27,    24,    25,    26,    27,     5,   211,    25,
     343,    27,    27,  2322,  2323,  2324,   349,  1111,  2327,     5,
     198,     5,    93,    94,    95,    96,    97,  1395,   433,  2220,
       5,   436,   315,   316,    25,   138,    27,     5,    25,  2502,
      27,  1282,   325,  2568,    27,    25,   322,    27,   453,   454,
     455,   456,     5,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     403,   517,     5,   389,  2397,   284,  2631,     0,     5,  2388,
     485,   486,   578,     5,   440,   490,    27,   492,   186,   187,
     337,   636,   211,   409,  1120,  2906,  2599,  2908,     5,   595,
    2911,   394,   507,   508,   509,   510,   686,   687,     5,   514,
     593,   691,   692,   658,     5,   344,  1494,  1436,   389,   296,
     343,   389,     5,   506,   704,   542,   292,   356,     5,   322,
       5,   322,  2307,   550,     5,     5,   517,     5,  3179,     5,
    3181,     5,   580,  1181,   724,   238,   185,   727,   222,   283,
      10,  2654,   438,   733,   198,    27,  1533,   737,     5,   406,
     238,   741,   102,   103,     5,   745,   238,   414,     5,   749,
     750,   418,   752,   623,   238,   755,     5,   757,   758,   759,
    3154,   664,    20,     5,   424,   765,   695,   300,   768,    27,
     669,   394,   132,   133,   134,   775,    56,     5,  1124,   580,
     238,   478,   782,   536,     5,   651,   709,     5,   455,   789,
     506,   300,    30,   663,     5,     5,    34,   238,     5,     5,
     800,     5,   399,   506,   804,     5,    30,   730,   808,   506,
      34,   112,   547,   548,   814,    27,   605,   817,     5,   331,
     743,    23,     5,  2552,   723,   319,   671,   488,   399,   787,
     788,   238,   761,  2562,   477,   238,   539,   674,   238,   542,
     454,    27,     5,     5,     5,     5,    25,   550,    27,   694,
     651,    30,     5,   769,   521,   394,   485,   199,   816,   444,
     636,   819,    27,   666,   567,  2400,   569,     5,     5,    18,
      19,    20,    21,    22,   577,   578,  2821,   101,   581,     5,
     548,   556,     5,     5,   108,   123,   585,   420,   421,   625,
     594,     5,   595,   560,  1146,  1147,   199,  2780,  1244,  1245,
    1246,     5,     5,   642,   440,  3281,     5,   440,     5,  1423,
     510,   420,   421,    23,     5,  1245,     5,   584,  2647,   615,
     433,   518,  3369,   113,     5,     5,   474,    27,   589,   642,
     154,   155,     5,   601,   625,   634,   440,   625,   162,  2550,
      25,  1399,  2917,   476,   586,   589,   238,   518,   608,  1395,
     666,  1171,    10,  1411,   873,  3349,  3350,    25,   331,   513,
     444,   628,  2539,   474,   399,  3196,   484,   476,   591,   440,
     637,   674,    25,   440,    27,   573,   679,   680,   681,   682,
     683,   684,   685,   518,   438,   688,   689,   690,   440,   474,
     693,   526,   695,   600,  3067,   698,  2016,   700,   552,   705,
    1341,   624,   615,   444,   615,   423,   709,  2037,   600,   440,
     597,   440,  3085,  2983,   636,  2694,  2817,   720,   721,  2748,
     547,   534,   603,   478,    27,   664,   663,   730,  2676,  1270,
     433,   673,    27,   736,  1264,   603,   440,   597,   713,   742,
     743,   744,   478,  3013,  2691,   748,   284,   715,   751,   708,
     753,   754,  2175,   713,   721,   722,  2696,   713,   761,   238,
     713,   764,  3523,  2110,  2548,   713,   769,   770,   474,   772,
     603,  3040,    28,   776,  1400,  3044,   779,   518,  3334,   474,
     282,   666,   785,   669,   787,   788,   474,    31,   415,   792,
     793,   794,  3348,   666,   603,   798,    23,   672,   801,  3130,
      29,   716,   561,   806,  2833,   284,   658,   666,   636,   573,
     813,   518,   815,   816,   593,   818,   819,   478,   821,   822,
    3182,   474,   664,   440,  1124,   740,  3574,   474,   293,   440,
     672,   623,   322,   593,   632,   436,   669,   666,  3169,   630,
     225,   306,   502,   440,    25,   440,    27,   381,   658,   440,
     440,   562,   440,   666,   440,   658,   440,   225,   983,   460,
     669,   986,   685,   686,   687,   688,   689,   405,   408,   994,
     995,   786,   282,   440,   501,  1263,   383,   658,   478,   440,
     478,   796,   666,   440,   799,   238,   719,   720,   803,   658,
     517,   440,   416,   293,   809,  2730,   811,   597,   440,     5,
    2847,  2848,  2849,  2850,   394,   391,   306,   505,   666,   411,
     719,   720,   440,   399,   400,   585,   454,  3473,   442,   440,
     663,   666,   440,   926,  1143,   666,   405,   434,   588,   440,
     440,  1150,  1484,   560,   440,   238,   440,   688,   424,   297,
     440,   427,   543,   408,  1244,  1245,  1246,   485,   438,  2978,
    1003,  2980,    27,   440,   290,  1515,  3329,   440,   444,    18,
      19,    20,    21,    22,   634,   968,   215,   352,  1530,   720,
     721,   631,   599,   358,   359,   360,   514,   440,   440,   440,
     440,   293,  1502,   523,   352,   403,   374,   440,   512,  3264,
     358,   359,   360,  2262,   306,   380,  2265,   636,   293,   666,
    2116,   628,   440,   440,   374,  1008,   485,  1010,   408,  2281,
     637,   306,   380,  1974,   440,  2103,     5,   440,   440,   658,
      25,   772,    27,  1984,  1985,   474,   440,   561,   403,  1990,
    1991,  1992,  1993,   506,   635,   514,   440,   440,   572,  2823,
    2824,   440,  1045,   440,  2374,  1048,   647,   648,  2378,   440,
     212,   440,   214,   330,   655,   282,   408,   238,   523,   440,
     440,  1064,   548,   450,  1067,   206,   343,   440,  2340,  2341,
    2162,     0,   672,    25,   539,    27,   440,   435,   478,   437,
     604,   293,    18,    19,    20,    21,    22,    16,  3117,  3461,
    3462,   444,   632,  3338,   306,    25,   408,    27,  3127,  3374,
      25,   486,    27,  1106,   489,  3361,   415,   330,  1111,   473,
     478,     5,   497,   408,     8,   601,  3372,  1120,   486,    14,
     343,   489,   608,   523,    25,   615,    27,    20,   585,   497,
     433,  1134,  1135,  1136,    27,  1138,  2248,  1140,  1141,   539,
     528,    26,    27,  1146,  1147,  1060,    25,   532,    27,  3189,
      20,    24,  3192,    26,  1412,  3195,   318,    27,   528,   321,
     684,    26,    27,   238,   532,   306,   478,    25,   692,    27,
     478,   523,  2147,  3545,  3203,  3547,  1179,   634,  1181,   428,
     161,   343,   567,   478,   411,  3132,  3133,  1190,  2324,  3136,
    1193,  2327,   501,   569,   443,  1198,   408,   478,  1414,   567,
     477,   586,   587,   344,   367,   695,   696,   697,   517,   478,
    2171,   523,   597,   671,  1217,  1218,   706,   602,   586,   587,
     478,   296,    25,  1226,    27,   506,   478,   539,   523,   597,
     254,   255,   256,   238,   602,   693,   694,   486,  1344,  1242,
    1243,  1347,  3119,  3190,   539,   506,  3193,   634,   497,  1164,
     637,   560,  1510,  1511,   477,  2001,   641,  1172,    25,  1174,
      27,    25,    25,    27,    27,  1268,   473,   408,   478,   518,
     478,  1274,  1275,   641,   478,   665,   525,    26,    27,  1282,
     632,   422,   672,   671,   533,   800,   238,   528,   673,   804,
     599,   478,  1295,   808,  1045,   505,   506,   505,   506,  1515,
    1303,   671,   690,   691,   478,   673,   555,    20,   415,    28,
      29,   523,  3341,   238,    27,   477,  1067,  2586,  2279,   628,
     690,   691,   710,   716,   717,   718,  2287,   539,   637,  2290,
    2291,  2292,  2293,   478,   212,   415,   214,   238,   478,  2611,
     710,   478,  2614,  1370,    26,    27,  1349,   478,  2668,    20,
    1353,  1354,  1355,   238,   671,  3395,    27,  2103,   568,   238,
     568,   239,  1365,  1366,  1367,  3136,  2696,  1370,  1371,  1372,
    1373,  1374,  1375,   238,   478,  3472,   693,   694,    20,  3476,
     238,  1384,   523,   632,    20,    27,  2425,  2145,  2486,   638,
     478,    27,  1395,  1396,   501,  1398,  1399,  1400,   539,  3428,
     659,   660,   661,   662,  1407,  1408,  1409,  3354,  1411,  1412,
     517,  1414,  1415,  3360,  3361,   474,  3363,  3364,  3365,  3366,
    1423,   501,    20,   478,   448,  3372,  1429,  1430,   685,    27,
     671,   688,   689,  1436,  1437,   238,   478,   517,  3385,    25,
     318,    27,  2554,   321,   506,   505,   506,  2093,  2218,   690,
     691,    25,    26,   560,  2212,   212,   286,   214,  3353,    19,
    3355,  3356,  3357,  3358,    24,   343,    26,   759,  2580,   710,
     286,   238,   686,   687,   238,   238,   768,   478,  1481,  1482,
     560,  1484,   239,    24,  3527,    26,  1401,  1402,  1403,   238,
     478,  1287,   599,  1289,  1290,  2057,    24,    25,    26,    27,
    1396,  3544,  1398,  1418,   440,  1508,   478,  1510,  1511,  2136,
     149,   150,  1515,   343,  1517,   286,  1519,  1520,    25,   599,
      27,   628,   814,   478,    25,   817,    27,   343,   815,   478,
     637,   818,  3479,   478,   821,  3482,  3483,  3484,  3485,  1542,
      15,    16,    17,    18,    19,    20,    21,    22,   628,  3592,
      17,    18,    19,    20,    21,    22,   238,   637,  3505,   505,
     506,   318,   109,   478,   321,    40,  3609,   397,    26,  2215,
    1485,   401,   343,    40,   636,   478,   385,   157,   158,   159,
      25,   397,    27,  3354,   112,   401,   343,   396,  1503,  3360,
     688,   689,  3363,  3364,  3365,  3366,   658,   478,    25,   477,
      27,   415,  2248,    25,   666,    27,  1521,  2568,   506,    19,
    2130,   478,  1870,  1871,    24,    25,    26,  1532,   478,  3566,
    2712,  2379,   478,  2381,  1375,   478,   397,  3574,   478,    25,
     401,    27,  2390,  1384,    24,    26,    26,   184,   447,   478,
    3063,  2757,   478,    25,  2789,    27,    26,   477,  2905,  2906,
     672,  2908,   461,   672,  2911,  2616,   415,  2415,  1409,   184,
     184,   477,  2754,   415,   139,   140,   141,   142,   143,   144,
    2631,    26,   139,   140,   141,   142,   143,   144,    25,   666,
      27,  2642,   157,   158,   159,    26,   727,   501,   695,   696,
     157,   158,   159,  3023,    25,   478,    27,    26,   415,   246,
     741,   248,   167,   517,   745,    26,   477,   573,  3479,   478,
     238,  3482,  3483,  3484,  3485,  2813,   757,   264,   695,   696,
     477,   246,   246,   248,   248,   272,    39,   478,    41,   276,
      43,    44,    18,    19,    20,    21,    22,    50,    51,   264,
     264,   550,   501,   335,   336,  3168,   560,   272,   272,   501,
     478,   276,   276,   478,   301,  2686,  2687,   478,   517,  3132,
    3133,   970,   287,   478,   973,   517,   975,   976,   977,   978,
     979,   478,   478,   468,    26,   506,   301,   301,   121,   122,
      26,   124,   125,   126,   501,   599,   478,    40,    26,    26,
    2765,    26,    26,  2093,    26,  3566,    26,   666,  2773,  2774,
     517,   560,   106,   440,   269,    20,    21,   410,   560,   478,
      26,   666,   277,  2375,   628,   440,   478,   478,   283,   474,
     285,  1972,   297,   637,     5,   300,   478,   440,   440,  2790,
     297,   296,   440,   300,  1940,   440,    20,  1144,  1145,   518,
     599,  1148,  1149,   560,   478,   672,    20,   599,   478,   478,
     440,  2109,     5,   106,   107,   478,   506,   670,    26,   324,
    2821,   666,    26,   440,  2426,   440,  1869,  1870,  1871,   628,
     306,   410,   474,  1876,  1877,   340,   628,  2002,   637,    30,
     345,   224,   599,    20,    26,   637,    26,    26,    26,   232,
      26,    26,   357,  1896,  1897,    26,  1899,  1900,   636,   364,
    1903,  1904,  2548,  1906,   440,  2011,  1909,   440,  2554,    26,
    3333,   628,    26,  2475,   440,  2215,   444,   440,   171,   440,
     637,     5,   440,   266,   139,   140,   141,   142,   143,   144,
    1933,    20,   275,    26,  2580,   478,   192,   190,    26,  3196,
     196,  1944,   666,    26,    26,   420,   440,   475,  2248,  2207,
     478,     5,  2913,   420,  2007,    20,    21,   440,  2716,    26,
     435,   304,   305,   491,   439,   350,   440,   672,   435,  1972,
     440,  1974,   439,   670,   440,     5,  2192,  2193,   440,   440,
     486,  1984,  1985,  1986,   440,   440,   478,  1990,  1991,  1992,
    1993,   497,   672,  2751,    20,    21,    22,   440,  2001,    26,
     672,   476,   440,   531,  2129,   318,   349,    25,   321,   476,
     323,    25,   518,    25,    40,   543,   636,   440,    25,   525,
    2023,   440,  2147,  2174,   440,  2028,   440,   533,   440,   504,
     343,  2034,   440,  3072,  2037,   440,   440,   504,   350,   440,
     353,   297,   440,   440,   670,   440,   440,   522,   513,   555,
     393,  3148,  2055,   518,   478,   522,   584,   666,  2061,   666,
     525,   374,   315,   316,     8,   671,   526,   474,   507,   322,
     642,   314,     5,   326,   139,   140,   141,   142,   143,   144,
     664,   664,   547,   642,   397,   468,  2089,   552,   401,   507,
     705,   705,   376,   666,   658,   623,   666,   506,   643,  2102,
    2103,  3076,     5,  2106,  2107,   448,  2109,   635,    18,    19,
      20,    21,   468,   139,   140,   141,   142,   143,   144,   647,
     648,  2124,     5,   394,   478,   478,   478,   655,   603,   478,
     658,   157,   158,   159,   478,   625,   603,   636,   666,     8,
    2143,    14,  2145,   622,     5,  2060,  1897,   705,  1899,  1900,
     692,     5,  1903,  1904,   705,   478,   478,   468,  1909,    26,
    2075,    26,   704,  2166,   477,  2168,  2169,   113,  2171,   138,
     506,  2174,  2175,   666,   506,   478,   478,  2823,  2824,   636,
     478,   478,   478,   478,   478,   478,  2101,  3285,   468,  2192,
    2193,   733,    26,  2108,   669,     5,  3294,   478,   642,   478,
       5,   672,   669,   478,  2207,   478,   708,   749,   750,  2212,
    2213,  2214,  3310,   755,   400,  2218,   758,   603,   672,   671,
    2135,     5,   663,  2226,    18,    19,    20,    21,    18,   139,
     140,   141,   142,   143,   144,  1986,    19,    26,  3199,  2154,
    3201,    26,   201,  2409,   432,    25,   625,   636,  2548,   669,
    2253,   529,   529,   506,  2554,   666,     5,   199,  2261,  2262,
     593,  3373,  2265,   593,   517,    26,   448,   371,   593,    26,
     440,   297,  3030,   478,   300,   440,  2279,   518,   666,   672,
    2580,   573,   440,   478,  2287,   478,   478,  2290,  2291,  2292,
    2293,  2294,   105,   478,  2297,   478,     5,   710,  2301,  2302,
    3058,   666,  2305,   666,   593,  2932,  2933,  2934,  2409,  2936,
    2937,  2938,  2939,  2940,  2941,   440,   636,   636,  2945,  2322,
    2323,  2324,   478,   663,  2327,  2328,  2329,   580,     5,  2332,
     672,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,     5,     5,   626,     5,   139,   140,   141,   142,   143,
     144,  2102,  3450,   530,   672,   671,   666,   478,  2361,   666,
    2363,  2364,   506,  2366,  2367,     5,     8,  2370,    39,    26,
      41,  2374,    43,    44,    26,  2378,  2379,  3338,  2381,    50,
      51,   367,   113,   375,  2387,  2388,   266,  2390,  2391,     5,
       5,  2394,  2395,   440,   420,   643,   409,   478,   651,   478,
     672,    14,   593,   597,     5,  2408,   706,    26,   147,   435,
     478,   666,  2415,   439,   672,   478,     5,   593,   672,  2422,
    3459,   671,  2425,   685,   671,   474,   679,   680,   681,    26,
     683,  2434,   440,     5,     5,  2438,   417,   665,   381,   474,
     478,   478,   508,     5,   508,   478,   478,   700,   666,   478,
     476,     5,   666,  2368,   478,   478,   478,  3555,   714,   715,
    2463,     8,   666,     5,   623,    25,   600,  2382,  2383,  2384,
    2385,   375,   394,   394,   394,  2226,   666,   478,   504,   409,
     473,   506,     5,   736,  2487,   506,     5,   697,  2403,   742,
      26,   744,     5,     5,    25,   748,   522,    14,   751,    14,
      26,   754,   663,   478,  3530,  3531,  3532,  3533,  3534,  3535,
     642,   764,   642,   600,  3475,     5,     5,   440,   478,     6,
     672,   440,   440,  2823,  2824,   440,   779,   440,   440,     7,
    3288,   495,   785,   440,  2537,   316,   208,     5,   666,   792,
     793,   794,    26,    26,    26,   798,  2297,  3305,  3509,  2552,
     672,   223,   224,   806,  2469,    26,   812,  2560,  2561,  2562,
     232,    26,  2565,  2566,  2599,  2568,   822,  3208,   666,   822,
     666,  3546,   440,    20,     5,   322,     5,   603,  2581,  2582,
       5,     5,  2585,  2586,   593,   613,    39,  2803,    41,  2805,
      43,    44,   666,     8,   266,   714,     5,    50,    51,   440,
    1254,   618,   440,   275,   666,     5,   478,   518,   593,     5,
     259,   672,   672,  2616,   670,    26,   440,   672,   478,  2654,
     672,  2624,  2788,  2626,     5,   478,  2629,  3666,  2631,     5,
     670,    25,   304,    25,    25,  2760,  2387,   494,    25,  2642,
    2765,    25,   344,   669,  2647,  2648,  2649,   318,  2773,  2774,
     321,    26,   323,    26,   665,  2658,  2571,  3618,  2573,    26,
      26,    26,    26,   440,   440,    26,     5,   440,   440,   478,
     515,     5,   343,  2676,   478,   440,     8,   349,   288,    26,
     597,    25,   353,  3441,   440,   488,   474,  2788,   394,    20,
     190,  2694,   600,  2696,     5,     5,  2847,  2848,  2849,  2850,
     478,    14,   259,   374,   478,   440,  2709,   478,   478,   478,
     478,   478,   968,  2716,   489,     5,   440,    26,    26,   506,
     440,   393,    26,   440,   478,    26,   397,  3373,    26,    26,
     401,   423,    26,   615,   478,   440,   288,   440,  2741,   440,
    2743,   394,  2745,   440,   289,  2748,  2749,   506,  2751,   593,
     488,   478,   440,    14,     7,   287,    26,   666,   287,   440,
     440,   666,   441,  2766,   478,  2768,  2769,  2770,   478,    25,
     672,   440,   622,   440,   474,   289,     5,   666,   440,   666,
    2783,   440,   440,     5,   440,   440,  2537,  2790,  3176,   440,
    3048,   666,  1048,   440,  2768,  1048,  3602,  2709,   994,  1522,
    2803,  2459,  2805,  3061,  2155,    29,   477,  2722,    31,  2391,
    2725,  1064,  2815,  2816,   547,  2566,  2741,   354,  2821,  2397,
     345,   114,   118,   655,   207,   355,  2006,   225,  2007,   536,
    2833,  2582,   212,   555,  2630,   598,  2632,   383,  1273,   567,
     384,  3592,  2060,   569,  2847,  2848,  2849,  2850,  2851,  2852,
     798,   415,  1251,  1106,  2259,  2266,  1869,   986,  2861,  2384,
    2108,  2792,  3097,  2866,  1872,   318,  2182,  2483,   321,  3643,
     323,  2387,  2202,  2624,  2789,  2626,  1414,  3302,    16,    92,
      40,  1134,  1135,  1136,  3042,  1138,  3229,  1140,  1141,    40,
     343,  2894,  2895,  1146,  1147,    22,  2160,   928,   754,  2166,
     353,  1010,  2905,  2906,   326,  2908,  1877,  2169,  2911,  1218,
    2913,  1482,  3226,  3403,  2917,   779,  3609,  1408,  1480,  3413,
    2790,   374,  1398,  2972,  1503,   452,  2970,  2657,  1181,  2135,
    2954,  3028,  3282,  3280,  3273,  3020,  2378,  2040,  2023,  2548,
    1193,  3042,  3618,  3203,   397,  1911,  2332,  1911,   401,  2567,
    3129,  3076,  2237,  2956,  2977,  3428,  3011,  2297,  2894,  2225,
    2895,  1217,  3193,  2629,  1217,  1218,  2969,  3505,  2999,  2679,
    3270,  3245,  1896,  1226,  2658,  2978,  2979,  2980,     8,  3659,
    3280,  3132,  3133,  1247,  2648,  3136,  2649,  3131,  2834,  1242,
    1243,  1985,  3201,  1984,  1891,  3469,  2561,  3126,  2749,  1243,
    3352,  3004,  1864,  3371,  3360,  2749,  2408,  1413,    -1,    -1,
     545,    -1,    -1,  3016,  3017,    -1,    -1,  3020,  1274,  1275,
    3023,    -1,    -1,    -1,   477,    -1,  1282,  3030,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3040,    -1,  3190,
    3043,  3044,  3193,    -1,    -1,  3048,    -1,    -1,    -1,    -1,
      -1,  2847,  2848,  2849,  2850,  3058,    -1,    -1,  3061,    -1,
    3063,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3284,  3072,
      -1,    -1,    -1,  3373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3111,    -1,
      -1,  2907,    -1,  2909,  3117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3126,  3127,    -1,  3129,  3130,    -1,  3132,
    3133,    -1,    -1,  3136,    -1,    -1,  3051,    -1,    22,    -1,
      -1,    -1,    -1,  1396,  3147,  1398,  1399,  1400,    -1,    -1,
      -1,    -1,    -1,    -1,  1407,  1408,    40,    -1,  1411,    -1,
      -1,    -1,  1415,    -1,    -1,  3168,  3169,    -1,    -1,    -1,
      -1,    -1,  3087,    -1,    -1,    -1,    -1,    -1,    -1,  3182,
    1436,    -1,    -1,  1436,  1437,    -1,    -1,  3190,    -1,    -1,
    3193,    -1,    -1,  3196,    -1,    -1,  3199,    -1,  3201,    -1,
    3203,  3352,    -1,  3354,    -1,    -1,    -1,    -1,    -1,  3360,
    3361,    -1,  3363,  3364,  3365,  3366,    -1,    -1,    -1,    -1,
      -1,  3372,    -1,  3226,    -1,    -1,    -1,    -1,  1481,  1482,
      -1,  1484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3004,    -1,   139,   140,   141,   142,   143,
     144,  3264,    -1,    -1,  1517,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,  1931,  1932,    -1,
      -1,  3284,    -1,    -1,  1938,  3288,    -1,    -1,    -1,  1542,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,  3465,
      -1,    -1,  3305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,  3479,    -1,
    3333,  3482,  3483,  3484,  3485,  3338,  3132,  3133,  3341,    -1,
    3136,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,  3352,
      -1,  3354,    -1,    -1,  3505,    -1,    -1,  3360,  3361,    -1,
    3363,  3364,  3365,  3366,  3465,    -1,  3369,    -1,  3371,  3372,
      -1,  3374,    -1,    -1,    -1,  3290,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
    3403,    -1,    -1,    -1,    -1,  3408,    -1,  3410,    -1,  3324,
      -1,    -1,    -1,   297,    -1,  3566,   300,    -1,    -1,    -1,
      -1,  3546,    -1,  3574,    -1,  3428,    -1,    -1,    -1,    -1,
      -1,  3182,    -1,    -1,    -1,    -1,    -1,    -1,  3441,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,  3459,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,  3469,    -1,    -1,    -1,
      -1,    -1,  3475,    -1,    -1,    -1,  3479,    -1,   107,  3482,
    3483,  3484,  3485,  3486,  2138,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,  3500,    -1,    -1,
      -1,    -1,  3505,    -1,    -1,    -1,  3509,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,  2178,    -1,    -1,  3530,  3531,  3532,
    3533,  3534,  3535,    -1,    -1,    -1,   420,    -1,    -1,  3542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   435,    -1,    -1,    -1,   439,    -1,    -1,  3354,    -1,
      -1,    -1,    -1,  3566,  3360,  3361,    -1,  3363,  3364,  3365,
    3366,  3574,    -1,    -1,    -1,    -1,  3372,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,   300,    -1,    -1,    -1,   238,
      -1,   240,    -1,    -1,    -1,  3618,    -1,  3620,    -1,    -1,
     504,  1877,    -1,  1876,  1877,    -1,  3541,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3657,  3658,  3659,    -1,    -1,    -1,
      -1,    -1,    -1,  3666,    -1,  3668,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1933,    -1,    -1,  3479,    -1,     9,  3482,  3483,  3484,  3485,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,   337,    -1,
      -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,  1974,   603,
      -1,    -1,    -1,  3638,    -1,   420,    -1,    -1,  1984,  1985,
      -1,    -1,    -1,    -1,  1990,  1991,  1992,  1993,    -1,    -1,
     435,    -1,    -1,   372,   439,   475,    -1,    -1,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3566,    -1,    -1,    -1,    -1,    -1,    -1,   406,  3574,    -1,
      -1,   476,    -1,   107,    -1,   669,    -1,    -1,   112,   418,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,  2453,
    2454,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,
    2464,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,   455,   522,    -1,    -1,
      -1,    -1,    -1,    -1,  2488,  2489,  2490,  2491,  2492,  2493,
      -1,   470,    -1,    -1,  2498,  2499,  2500,  2501,    -1,   478,
      -1,  2505,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,  2124,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
    2136,    -1,    -1,    24,    25,    26,    27,   617,    -1,    -1,
      -1,    -1,  2145,   623,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   632,   633,    -1,   635,   535,    -1,   603,    -1,
      -1,    -1,    -1,  2166,   238,  2171,   240,   647,   648,    -1,
      -1,    -1,  2175,    -1,    -1,   655,    -1,    -1,   658,    -1,
      -1,   560,    -1,  2587,  2588,    -1,   666,    -1,    -1,    -1,
    2594,  2595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,  2212,
    2213,  2214,    -1,    -1,    -1,  2218,   107,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   669,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,
    2253,    -1,    -1,    -1,    -1,   146,    -1,    -1,   637,    -1,
      -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,   342,    -1,
      -1,    -1,    -1,  2279,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2287,    -1,    -1,  2290,  2291,  2292,  2293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2302,    -1,   372,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2328,    -1,    -1,    -1,    -1,  2731,  2732,    -1,
      -1,    -1,   406,    -1,    -1,    -1,  2740,    -1,    -1,    -1,
      -1,    -1,   721,   722,   418,    -1,    -1,   238,    -1,   240,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,   436,    -1,    -1,    -1,    -1,   441,    -1,    -1,
     444,    -1,    -1,  2777,  2778,    40,  2379,    -1,  2381,    -1,
      -1,   455,    -1,    -1,    -1,    -1,   460,  2390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
    2804,   475,  2806,    -1,   478,    -1,  2409,   481,    -1,    -1,
      -1,    -1,  2415,    -1,    -1,    -1,   490,   491,    -1,  2425,
      -1,    -1,  2425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2434,    -1,    -1,    -1,  2438,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,
      -1,   342,    -1,    -1,    -1,    -1,   530,   531,    -1,    -1,
    2463,   535,    -1,  2867,  2868,    -1,    -1,  2871,  2872,   543,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
     554,   372,    -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     584,    -1,    -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
     441,    -1,    -1,   444,   628,    -1,  2960,    -1,    -1,    -1,
      -1,   635,  2568,   637,   455,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,   647,   648,    -1,    -1,    -1,    -1,   470,
      -1,   655,  2585,    -1,   475,    -1,    -1,   478,    -1,    -1,
     481,    -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,   490,
     491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2616,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2629,    -1,  2631,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,   300,  2642,  3041,    -1,    -1,
     531,  3045,    -1,    -1,   535,  2648,    -1,   721,   722,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3064,    -1,    -1,   554,    -1,   556,    -1,    -1,    -1,   560,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3083,
       9,    -1,    -1,    -1,    -1,  2691,    -1,    -1,    -1,    18,
      19,    20,    -1,   584,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2716,    -1,    -1,    -1,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,   628,    18,    19,
      20,    21,    22,    -1,   635,    -1,   637,    -1,  2751,    -1,
      -1,    -1,    40,    -1,    -1,   420,   647,   648,    -1,    -1,
      40,    -1,    -1,  2766,   655,  2768,    -1,  2770,    -1,    -1,
     435,    -1,    -1,    -1,   439,   666,    -1,    -1,    -1,    -1,
    2783,    -1,    -1,   112,  2790,  2788,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,  2815,  2816,     8,  2821,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
     721,   722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,  2847,  2848,  2849,  2850,    -1,    40,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,   522,  2861,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2894,  2895,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2905,
    2906,    -1,  2908,    -1,    -1,  2911,    -1,  2913,    -1,   238,
      -1,  2917,    -1,    -1,    -1,    -1,    -1,    -1,  3322,    -1,
      -1,  3325,    -1,    -1,    -1,    -1,  2932,  2933,  2934,    -1,
    2936,  2937,  2938,  2939,  2940,  2941,    -1,    -1,   603,  2945,
      -1,    -1,    -1,    -1,    40,   139,   140,   141,   142,   143,
     144,    -1,    -1,  2956,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,  2969,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,   297,
      -1,    -1,   300,   342,    -1,    -1,    -1,   297,    -1,     9,
     300,    -1,    -1,    -1,    -1,    -1,    -1,  3030,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,  3042,
      -1,    -1,    -1,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,  3058,    -1,    -1,    -1,  3463,
    3063,   157,   158,   159,    -1,    -1,  3072,    -1,    -1,  3072,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,   112,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   297,    -1,    -1,   300,  3511,  3512,    -1,
    3514,    -1,  3516,  3517,    -1,   444,    -1,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,  3132,  3133,    -1,   119,
    3136,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,   475,   435,    -1,   478,
      -1,   439,    -1,    -1,    -1,   435,   146,    -1,    -1,   439,
      -1,   490,   491,    -1,    -1,  3168,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,  3580,    -1,  3582,    -1,
      -1,    -1,    -1,    -1,  3190,    -1,    -1,  3193,   476,   518,
    3196,    -1,    -1,  3199,    -1,  3201,   476,    -1,    -1,    -1,
      -1,   297,   531,    -1,   300,   238,    -1,    -1,    -1,    -1,
      -1,    -1,  3616,    -1,   543,    -1,   504,    -1,    -1,    -1,
      -1,    -1,    -1,  3226,   504,    -1,   420,    -1,  3632,  3633,
      -1,    -1,  3636,    -1,   522,  3639,    -1,    -1,    -1,    -1,
      -1,   435,   522,    -1,    -1,   439,    -1,    -1,   238,    -1,
     240,    -1,    -1,     9,    -1,   584,    -1,    -1,  3264,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,    -1,  3288,    -1,    -1,   617,    -1,
      -1,    -1,    -1,    -1,   623,    -1,   238,    -1,    -1,    -1,
      -1,    -1,  3305,   632,   633,    -1,   635,    -1,    -1,   342,
     504,    -1,    -1,    -1,    -1,   603,    -1,    -1,   647,   648,
      -1,    -1,    -1,   603,   420,    -1,   655,    -1,   522,   658,
    3333,    -1,  3338,    -1,    -1,    -1,    -1,   666,    -1,   435,
      -1,    -1,    -1,   439,    -1,    -1,    -1,   337,  3354,    -1,
      -1,   107,   342,    -1,  3360,  3361,   112,  3363,  3364,  3365,
    3366,    -1,    -1,   119,    -1,    -1,  3372,    -1,  3374,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3385,
     476,   669,   372,    -1,     5,    -1,    -1,    -1,    -1,   669,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3403,    -1,    -1,    -1,    -1,  3408,    -1,  3410,   504,   603,
      -1,   444,    -1,    -1,    -1,    -1,   406,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,   522,    -1,   418,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,  3441,    -1,
      -1,    -1,   475,    -1,    -1,   478,   436,    -1,    -1,    -1,
      -1,   441,    -1,  3459,   444,    -1,  3459,   490,   491,    -1,
      -1,    -1,  3465,    -1,    -1,   455,    -1,    -1,    -1,  3475,
     460,    -1,    -1,  3479,    -1,   669,  3482,  3483,  3484,  3485,
     470,    -1,   238,    -1,   240,   475,    -1,    -1,   478,    -1,
      -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,   531,  3505,
     490,   491,   444,  3509,    -1,    -1,    -1,   603,    -1,    -1,
     543,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3530,  3531,  3532,
    3533,  3534,  3535,   475,    -1,    -1,   478,    -1,    -1,    -1,
     530,   531,    -1,    -1,    -1,   535,    -1,    -1,    -1,   491,
      -1,   584,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
    3566,    -1,    -1,    -1,   554,    -1,    -1,    -1,  3574,    -1,
     560,    -1,    -1,   669,    -1,    -1,   518,    -1,    -1,    -1,
      -1,   337,    -1,    -1,   617,    -1,   342,    -1,    -1,   531,
     623,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,   632,
     633,   543,   635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3618,    -1,   647,   648,   372,    -1,    -1,    -1,
      -1,    -1,   655,    -1,    -1,   658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    -1,   584,   238,    -1,   635,    -1,   637,    -1,    -1,
     406,    -1,    -1,    -1,    -1,    -1,    -1,   647,   648,    -1,
    3666,    -1,   418,  3666,    -1,   655,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   617,   666,    -1,    -1,    -1,
     436,   623,    -1,    -1,    -1,   441,    -1,   308,   444,    -1,
     632,   633,    -1,   635,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,   460,   647,   648,    -1,    -1,    -1,
      -1,    -1,    -1,   655,   470,    -1,   658,    -1,    -1,   475,
      -1,    -1,   478,    -1,   666,   481,   347,    -1,    -1,    -1,
      -1,   721,   722,    -1,   490,   491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   366,   367,   342,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,   531,    -1,    -1,    -1,   535,
      -1,    33,    -1,    -1,    -1,   406,    -1,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,   554,    -1,
      -1,    53,    -1,    -1,   560,    -1,    -1,    -1,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   446,    -1,    -1,   584,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
     471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,   635,
     475,   637,    -1,   478,    -1,   137,   138,    -1,    -1,    -1,
     511,   647,   648,    -1,   146,   490,   491,    -1,    -1,   655,
      -1,   153,   154,    -1,    -1,   157,   158,   159,   160,    -1,
     666,   163,   164,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,    -1,    -1,   556,   531,    -1,   559,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
      -1,    -1,    -1,   584,    -1,   721,   722,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,   603,    -1,    -1,   237,   238,    -1,   240,   584,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
      -1,    -1,   617,    -1,    -1,    -1,    -1,    -1,   623,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   632,   633,    -1,
     635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   647,   648,    -1,    -1,    -1,   309,    -1,    -1,
     655,    -1,    -1,   658,    -1,    -1,    -1,    -1,    -1,    -1,
     322,   666,    -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,
      -1,    -1,   344,    -1,    -1,   347,   348,    -1,    -1,    -1,
     352,    -1,    -1,    -1,    -1,    -1,   358,   359,    -1,    -1,
      -1,    -1,    -1,   365,   366,   367,    -1,    -1,   370,   371,
     372,    -1,    -1,    -1,   376,    -1,    -1,    -1,   380,    -1,
     382,    -1,    -1,    -1,    -1,    -1,    -1,   389,   390,   391,
     392,    -1,   394,   395,    -1,    -1,    -1,   399,   400,    -1,
     402,   403,   404,   405,   406,   407,   408,    -1,    -1,    -1,
      -1,    -1,   414,   415,   416,    -1,   418,   419,    -1,    -1,
      -1,   423,   424,   425,   426,   427,   428,   429,   430,    -1,
     432,    -1,    -1,    -1,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,    -1,   474,   475,    -1,    -1,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,    -1,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,    -1,    -1,   506,   507,   508,   509,   510,   511,
     512,   513,   514,    -1,   516,   517,   518,   519,    -1,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,    -1,   558,   559,   560,   561,
     562,   563,    -1,    -1,   566,   567,    -1,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,    -1,    -1,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,   658,    -1,    -1,    -1,
      -1,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   684,    -1,    -1,    -1,    -1,   308,    -1,    -1,
     692,    -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,   701,
      -1,    -1,   704,   705,   706,   707,    -1,    -1,   710,   711,
      -1,   713,   714,   715,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,   347,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,   366,   367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   446,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,    -1,    -1,
     471,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,   153,   154,    -1,    -1,   157,   158,   159,   160,
      -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,    -1,   225,   556,    -1,    -1,   559,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   580,
      -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     271,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,
      -1,    -1,    -1,   344,    -1,    -1,   347,   348,    -1,    -1,
      -1,   352,    -1,    -1,    -1,    -1,    -1,   358,   359,    -1,
      -1,    -1,    -1,    -1,   365,   366,   367,    -1,    -1,   370,
     371,   372,    -1,    -1,    -1,   376,    -1,    -1,    -1,   380,
      -1,   382,    -1,    -1,    -1,    -1,    -1,    -1,   389,   390,
     391,   392,    -1,   394,   395,    -1,    -1,    -1,   399,   400,
      -1,   402,   403,   404,   405,   406,   407,   408,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,    -1,   418,   419,    -1,
      -1,    -1,   423,   424,   425,   426,   427,   428,   429,   430,
      -1,   432,    -1,    -1,    -1,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,    -1,   474,   475,    -1,    -1,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,    -1,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,    -1,    -1,   506,   507,   508,   509,   510,
     511,   512,   513,   514,    -1,   516,   517,   518,   519,    -1,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,    -1,   558,   559,   560,
     561,   562,   563,    -1,    -1,   566,   567,    -1,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,    -1,    -1,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,    23,    -1,
      -1,    -1,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,    -1,    39,    -1,    41,    -1,    43,    44,
      -1,    -1,    -1,   684,    -1,    50,    51,    -1,    -1,    -1,
      -1,   692,    -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,
     701,    -1,    -1,   704,   705,   706,   707,    -1,    -1,   710,
     711,    -1,   713,   714,   715,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,   246,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,
      -1,   276,    -1,    -1,    -1,    -1,    -1,   282,    -1,    -1,
      -1,   286,   287,   288,   289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   318,    -1,    -1,   321,    -1,   323,    -1,
      -1,    -1,    -1,    -1,    -1,   330,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    -1,    36,    37,    38,   343,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,   353,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,
     375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   397,    -1,    -1,    -1,   401,    -1,    99,   100,
      -1,    -1,    -1,   104,   409,   410,   411,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   166,    -1,   168,   169,   170,
      -1,    -1,   477,    -1,    -1,    -1,    -1,   178,   179,    -1,
     181,   182,   183,   488,    -1,    -1,    -1,    -1,   189,    -1,
      -1,   192,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,   202,    -1,   204,   205,    -1,   207,    -1,   209,   210,
      -1,    -1,   213,    -1,    -1,   216,   217,   218,   219,   220,
     221,    -1,    -1,   528,   225,   226,   227,    -1,   229,    -1,
      -1,    -1,   233,    -1,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,   244,    -1,    -1,   247,    -1,   249,    -1,
     251,    -1,   253,    -1,    -1,    -1,   257,   258,    -1,   260,
     261,   262,    -1,    -1,   265,    -1,   267,   268,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,   279,    -1,
      -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,    -1,    -1,
     291,    -1,    -1,   294,   295,    -1,    -1,   298,   299,    -1,
      -1,   302,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,   312,   313,    -1,   315,    -1,    -1,    -1,    -1,    -1,
     625,    -1,    -1,    -1,   325,   326,   327,    -1,   329,    -1,
      -1,    -1,   333,   334,    -1,    -1,    -1,   338,    -1,    -1,
      -1,    -1,    -1,    -1,   444,   346,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,   355,   356,    -1,    -1,    -1,    -1,
      -1,   362,   363,    -1,    -1,    -1,   671,    -1,    -1,   370,
      -1,    -1,   373,    -1,    -1,   475,   377,   378,   478,    -1,
     685,   686,   687,   688,   689,   690,   691,   388,   693,   694,
      -1,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   405,   710,    -1,    -1,    -1,    -1,
      -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,   419,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,
     530,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,   443,   543,    -1,    -1,    -1,    -1,   449,    -1,
     451,   452,    -1,    -1,    -1,    -1,    -1,    -1,   459,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,   617,    -1,    -1,
      -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   632,   633,    -1,   635,    -1,    -1,    -1,   540,
     541,    -1,    -1,    -1,   545,    -1,    -1,   647,   648,    -1,
      -1,    -1,    -1,    -1,    -1,   655,   557,    -1,   658,    -1,
      -1,    -1,   563,   564,   565,   566,   666,    -1,    -1,   570,
      -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,
     581,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   592,    -1,   594,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   605,    -1,   607,    -1,    -1,   610,
      -1,    -1,   157,   158,   159,   616,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   642,    -1,    -1,   645,    -1,    -1,    -1,    -1,   650,
      -1,    -1,   653,   654,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,    -1,    -1,
      -1,     6,     7,     8,   675,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   698,   699,   700,
     701,   702,   703,   704,    -1,    40,   707,    -1,   709,    -1,
     711,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,   300,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     435,    -1,    -1,    -1,   439,   440,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   297,    -1,    -1,   300,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,   297,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,    -1,    -1,    -1,   439,   440,   603,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
     435,    -1,    -1,    -1,   439,   440,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   504,    -1,    -1,   669,   420,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,   522,
     435,   476,    -1,    -1,   439,   440,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,   440,
     603,    -1,    -1,    -1,     6,     7,     8,   522,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,
     297,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   504,    -1,    -1,   669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,   603,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,   157,   158,   159,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,
      -1,    -1,   439,   440,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,   141,   142,   143,   144,   669,   476,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   522,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,   297,    -1,    -1,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     297,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,   143,   144,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,
      -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   435,    -1,    -1,    -1,   439,   440,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,    40,
     300,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
     143,   144,   504,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,   435,    -1,
     522,    -1,   439,   440,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,
      -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,   139,   140,
     141,   142,   143,   144,    -1,    -1,    40,   297,    -1,    -1,
     300,   603,    -1,    -1,    -1,   522,   157,   158,   159,    -1,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   297,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,   476,   669,    -1,    -1,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    -1,    -1,   603,   435,    -1,    -1,
      -1,   439,    -1,    -1,   504,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,   157,   158,   159,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,
      -1,   489,    -1,    -1,    -1,    -1,   297,    -1,    -1,   300,
      -1,    -1,   669,    -1,    -1,    -1,   504,    -1,    -1,    -1,
      -1,    -1,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,   522,    -1,   476,   420,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,   435,   603,    -1,    -1,   439,    -1,    -1,    57,
      58,    59,    60,    -1,   504,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    18,    19,    20,
      -1,    -1,   522,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    40,   476,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   297,    -1,   603,   300,    -1,    -1,   669,
      -1,   504,    40,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,   439,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
     297,   669,   180,   300,    -1,   476,    -1,    -1,    -1,    -1,
     188,   139,   140,   141,   142,   143,   144,    -1,   489,   197,
      -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,
     603,   139,   140,   141,   142,   143,   144,    -1,    -1,   669,
      -1,   522,    -1,    -1,    -1,    -1,   420,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   435,   250,    -1,    -1,   439,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,
      -1,    -1,   476,    -1,   157,   158,   159,   238,    18,    19,
      -1,    -1,    -1,   420,    24,    25,    26,    27,    -1,   307,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,   435,    -1,
     504,    -1,   439,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,   332,    -1,    -1,    -1,   522,    -1,
      -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,   297,
      -1,    -1,   300,   351,    -1,    -1,   112,    -1,    -1,   476,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,   297,
      -1,   379,   300,    -1,    -1,    -1,    -1,   504,    -1,   387,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   603,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   297,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,    -1,    -1,   669,   603,   435,   486,    -1,
      -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,
      -1,    -1,   420,   444,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,   435,   238,    -1,
      -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,   475,    -1,    -1,   478,    -1,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     491,    -1,   669,    -1,    -1,    -1,   504,   420,   476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,    -1,   522,    -1,   439,    -1,    -1,    -1,
     238,    -1,    32,    -1,    -1,    35,   504,    -1,    -1,   530,
     531,    -1,    -1,    -1,    -1,    -1,    -1,   595,   596,   597,
      -1,    -1,   543,    -1,   522,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    -1,    -1,    52,    53,    -1,
      -1,   504,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,   603,    52,    53,    -1,   522,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   617,   127,   128,    -1,
      -1,    -1,   623,    -1,    -1,   603,    -1,   137,   444,    -1,
      -1,   632,   633,    -1,   635,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   647,   648,    -1,    -1,
      -1,    -1,    -1,   711,   655,    -1,    -1,   658,    -1,   475,
      -1,   669,   478,    -1,   444,   666,    -1,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   145,
     444,   669,    -1,    -1,    -1,   475,    -1,    -1,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,   368,
     369,   491,    -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,
      -1,   475,    -1,    -1,   478,    -1,   444,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   669,   406,    -1,    -1,
     530,   531,    -1,    -1,    -1,    -1,    -1,   475,    -1,   418,
     478,    -1,    -1,   543,   518,    -1,    -1,    -1,   584,    -1,
     429,    -1,    -1,   491,    -1,    -1,    -1,   531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,    -1,   543,
      -1,    -1,    -1,    -1,   250,    -1,    -1,   456,   308,    -1,
      -1,   617,    -1,    -1,   584,    -1,    -1,   623,    -1,    -1,
      -1,    -1,   471,   531,    -1,    -1,   632,   633,    -1,   635,
      -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,
     584,   647,   648,    -1,    -1,    -1,    -1,   347,    -1,   655,
      -1,    -1,   658,   623,    -1,    -1,    -1,    -1,    -1,    -1,
     666,   307,    -1,    -1,    -1,   635,   366,   367,   368,   369,
     519,    -1,    -1,    -1,    -1,    -1,   584,   647,   648,   623,
      -1,    -1,    -1,    -1,   384,   655,   332,    -1,   658,    -1,
      -1,   635,    -1,    -1,    -1,   341,   666,    -1,    -1,    -1,
     549,    -1,    -1,   647,   648,    -1,   406,    -1,    -1,    -1,
     559,   655,    -1,    -1,   658,   623,    -1,   382,   418,    -1,
      -1,    -1,   666,    -1,    -1,    -1,    -1,   635,    -1,   429,
     395,   580,    -1,   379,    -1,   584,   382,    -1,    -1,   647,
     648,   387,    -1,    -1,    -1,    -1,   446,   655,    -1,   395,
     658,    -1,    -1,    -1,    -1,    -1,   456,    -1,   666,    -1,
      -1,    -1,    -1,   612,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   471,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,   464,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   511,   458,    -1,    -1,    -1,    -1,    -1,   464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   479,   534,    -1,    -1,    -1,   503,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,
      -1,    -1,    -1,    -1,    -1,    -1,   556,   503,    -1,   559,
      -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,   538,    -1,    -1,    -1,    -1,   543,    -1,
     580,   527,    -1,    -1,   584,    -1,    -1,    -1,   553,    -1,
      -1,   537,   538,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      -1,    -1,    -1,   603,    -1,    -1,    -1,   553,    -1,    -1,
     575,    -1,    -1,   578,   579,    -1,    -1,    -1,   583,    -1,
      -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   575,
      -1,    -1,   578,   579,    -1,    -1,    -1,   583,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   651,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   649,    -1,   651
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   123,   284,   405,   454,   485,   514,   782,
     810,   811,   867,  1041,  1097,  1099,  1100,  1101,  1106,  1108,
    1121,  1122,  1123,  1124,  1125,  1559,    28,    29,   783,   784,
     785,   786,   787,    27,  1005,  1574,  1005,    25,  1005,  1474,
    1126,   812,  1474,   811,     0,  1098,  1101,  1124,    31,   785,
     787,   868,   658,    25,   238,   809,   810,   992,  1005,  1010,
    1106,  1121,  1127,  1162,  1163,  1164,  1165,  1166,  1170,   403,
     814,   815,   816,   817,   820,   821,   101,   108,   154,   155,
     162,   416,   442,   512,   604,   684,   692,   782,   788,   960,
    1040,  1102,  1103,  1105,  1109,  1110,  1116,  1128,  1132,  1283,
    1293,  1559,   663,  1005,  1165,   290,   505,   506,  1172,    20,
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
     844,   849,  1005,   478,   161,  1005,   809,   961,  1133,  1005,
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
     440,   478,  1285,  1575,  1576,  1577,  1578,  1579,   962,  1134,
    1112,   666,    26,   440,   857,   858,   478,   859,   864,   865,
     859,   478,   860,     5,   440,     5,   440,     5,   331,     5,
     869,   474,     5,     5,   440,   815,   851,   478,     5,   440,
     506,   666,   440,   440,   440,   440,   440,   440,   440,   636,
     950,    19,    26,   636,   440,     5,   440,   440,     5,   807,
     903,   518,  1490,   903,   478,   672,    20,   440,  1490,    20,
    1273,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   478,   903,   903,   478,  1162,   903,
     903,   903,   903,   440,     5,   762,   763,   764,   903,   478,
    1173,   506,   670,    26,   666,    26,   440,   440,     5,   440,
     306,     5,   440,     5,   440,   331,   474,     5,   440,   851,
    1005,  1179,  1180,  1182,  1129,  1179,   410,  1576,  1270,    36,
      37,    38,    42,    45,    54,    55,    99,   100,   104,   114,
     115,   117,   131,   148,   151,   152,   166,   168,   169,   170,
     178,   179,   181,   182,   183,   189,   192,   194,   195,   196,
     202,   204,   205,   207,   209,   210,   213,   216,   217,   218,
     219,   220,   221,   225,   226,   227,   229,   233,   235,   236,
     241,   244,   247,   249,   251,   253,   257,   258,   260,   261,
     262,   265,   267,   268,   270,   278,   279,   291,   294,   295,
     298,   299,   302,   303,   311,   312,   313,   315,   325,   326,
     327,   329,   333,   334,   338,   346,   354,   355,   356,   362,
     363,   370,   373,   377,   378,   388,   405,   413,   419,   430,
     443,   449,   451,   452,   459,   498,   509,   516,   540,   541,
     545,   557,   563,   564,   565,   566,   570,   574,   581,   582,
     592,   594,   605,   607,   610,   616,   642,   645,   650,   653,
     654,   668,   675,   698,   699,   700,   701,   702,   703,   704,
     707,   709,   711,   725,   726,   727,   728,   745,   767,   781,
     782,   788,   789,   808,   882,   883,   884,   885,   896,   897,
     898,   899,   900,   901,   902,   955,   986,   990,  1012,  1014,
    1017,  1018,  1019,  1020,  1033,  1042,  1066,  1067,  1069,  1073,
    1088,  1089,  1093,  1094,  1095,  1096,  1104,  1119,  1139,  1150,
    1151,  1152,  1156,  1159,  1195,  1198,  1200,  1206,  1207,  1210,
    1213,  1216,  1218,  1220,  1223,  1230,  1235,  1239,  1240,  1241,
    1253,  1254,  1257,  1263,  1265,  1266,  1291,  1306,  1307,  1308,
    1309,  1310,  1322,  1328,  1329,  1349,  1352,  1381,  1383,  1475,
    1476,  1507,  1508,  1515,  1526,  1550,  1559,  1560,  1565,  1566,
    1568,  1572,  1573,  1580,   782,  1107,   671,   694,  1135,  1136,
    1179,    20,   440,   473,   829,   856,    26,   861,    26,    26,
      26,   878,   880,   872,   832,    26,  1005,   996,   732,    20,
     713,  1005,   943,  1470,   943,    26,    26,   636,    24,    26,
     853,   944,   997,   854,   440,   408,   523,   632,  1498,   440,
     440,    26,  1470,   440,   440,   440,   440,   440,   440,   440,
     489,   489,   489,   928,  1490,   489,   928,  1490,   938,   936,
     942,   940,    26,   931,     5,   932,   474,  1173,   839,   440,
      20,   829,    26,   478,    26,    26,   825,    26,   666,   440,
       5,  1179,   440,  1162,  1162,  1162,  1005,    25,  1162,  1217,
    1005,    25,  1005,  1459,   399,  1006,  1007,  1574,  1006,    25,
    1005,  1458,  1005,  1005,  1237,  1000,  1006,  1000,  1005,  1570,
    1459,  1005,    26,   729,  1162,  1313,  1000,  1237,   928,    26,
    1011,  1278,  1279,  1278,   903,   910,  1351,  1458,  1458,   905,
     928,  1006,  1516,  1516,   886,  1237,  1000,  1311,  1162,  1002,
    1006,   910,  1516,  1162,  1237,  1162,  1350,  1516,    25,   632,
    1153,  1154,  1162,  1000,  1000,  1153,  1001,  1006,  1005,  1154,
    1000,  1516,  1000,  1002,  1459,  1162,  1193,  1194,   998,  1006,
    1002,   424,   608,   996,  1068,  1005,   790,  1458,  1003,  1006,
      25,   238,  1005,  1171,  1382,  1554,  1555,  1556,   928,  1193,
     672,   928,  1006,  1219,   956,    57,    58,    59,    60,   180,
     188,   197,   200,   243,   250,   307,   332,   339,   341,   351,
     379,   387,   424,   449,   486,   497,   595,   596,   597,   608,
     711,  1082,  1214,  1215,  1162,  1184,  1185,   909,   910,  1229,
     953,   953,   999,  1006,   928,  1217,  1292,  1162,  1269,    25,
    1162,  1510,  1264,   910,  1561,   153,   203,   240,   337,   414,
     455,   521,   746,   934,  1005,  1162,  1301,   769,   910,   998,
     636,  1005,  1013,  1140,   910,   998,    26,  1162,  1090,   998,
     910,  1527,   910,  1278,  1005,  1015,  1016,  1002,  1015,   953,
    1002,  1015,   953,  1021,  1015,    25,    26,   433,   534,  1011,
    1071,  1162,  1181,  1183,   113,   322,   394,   438,   615,   695,
     696,   697,   706,   736,  1023,  1025,  1027,  1029,  1031,  1157,
    1158,  1161,   385,   396,   447,   461,   550,  1384,   686,   687,
     964,   965,   966,  1005,  1137,   693,  1136,   440,   350,   440,
     440,   440,   440,   670,     5,   440,   440,   474,   478,   672,
     440,    26,   636,   672,    18,    19,    20,    25,    26,   112,
     444,   475,   478,   491,   531,   543,   584,   617,   623,   632,
     633,   635,   647,   648,   655,   658,  1005,  1011,  1465,  1467,
    1497,  1499,  1500,  1502,  1503,  1504,  1555,  1558,  1290,   440,
    1290,  1290,  1290,  1290,  1290,  1290,    25,    25,    25,   903,
     920,   440,    25,   920,   440,   440,   440,   440,   440,   440,
     440,   764,   762,   474,   350,   440,   815,   837,   838,   440,
     440,   670,   440,  1005,  1296,  1182,   440,  1286,   102,   103,
     132,   133,   134,   502,   588,   631,  1330,  1331,  1332,  1335,
    1338,  1341,  1342,  1343,  1346,   666,   636,   658,   149,   150,
     478,   666,   636,   658,     8,   671,   474,  1458,   526,  1238,
    1181,   157,   158,   159,   642,   530,   906,   907,   910,  1162,
    1188,  1458,   735,   736,   889,   314,   135,   136,   672,   507,
       5,   665,   672,   664,   664,  1196,   642,   468,     5,   603,
    1043,   507,   705,  1563,   705,   433,   792,  1162,   593,   664,
    1201,  1202,  1203,   666,    25,  1556,  1172,   376,  1380,   658,
     666,   908,   910,   603,  1554,   908,     8,   600,   999,    26,
     548,   601,   715,   991,  1162,   991,   991,   991,    25,   225,
     352,   358,   359,   360,   380,   486,   489,   497,   532,   567,
     586,   587,   597,   602,   641,   673,  1086,  1087,   991,   991,
     643,  1083,   736,  1083,  1083,   992,   992,  1083,  1083,   736,
       5,   468,     5,   383,   434,     5,   735,   129,   130,   586,
     673,  1074,   708,  1564,   909,   659,   660,   661,   662,  1268,
    1270,   910,  1259,  1260,  1261,  1271,  1272,   910,   478,   478,
     478,   478,    25,   765,  1005,   478,  1510,   394,   478,   568,
     636,   625,   770,   777,   768,  1005,    25,  1155,  1162,  1255,
       8,  1258,    14,  1005,  1167,  1175,  1176,  1178,  1186,  1187,
    1231,   211,   394,   591,   624,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    18,    19,    20,    21,    22,    23,
      33,    53,   110,   119,   137,   138,   146,   153,   154,   157,
     158,   159,   160,   163,   164,   203,   225,   231,   238,   240,
     245,   271,   309,   322,   328,   337,   338,   344,   347,   348,
     352,   358,   359,   365,   366,   367,   370,   371,   372,   376,
     380,   382,   389,   390,   391,   392,   394,   395,   399,   400,
     402,   403,   404,   405,   406,   407,   408,   414,   415,   416,
     418,   419,   423,   424,   425,   426,   427,   428,   429,   430,
     432,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   474,   475,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   516,   517,   518,   519,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   558,   559,   560,   561,   562,   563,
     566,   567,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   684,   692,   697,   701,   704,   705,   706,   707,   710,
     711,   713,   714,   715,  1528,  1529,  1530,  1532,   622,     5,
     705,   705,   908,  1181,  1188,  1070,   468,     5,   199,  1048,
     478,  1162,   908,   478,    26,    26,   113,  1160,    25,  1162,
    1514,  1514,  1006,  1364,  1219,   999,   167,   269,   277,   283,
     285,   296,   324,   340,   345,   357,   364,   513,   518,   525,
     547,   552,  1353,  1354,  1362,  1371,  1372,  1378,  1379,  1385,
    1386,  1396,  1416,  1420,  1486,  1487,  1517,  1518,  1521,  1522,
    1534,   967,   968,   138,   963,   974,   975,   966,  1138,  1575,
    1113,   506,   869,   832,   666,  1005,   415,   501,   517,   560,
     599,   628,   637,  1471,   943,   636,    24,    26,   857,  1503,
    1503,   415,   501,   517,   560,   599,   628,   637,  1468,  1472,
     518,  1502,   478,   478,   478,   478,  1497,  1497,  1497,   478,
     478,   478,   478,  1005,   478,     5,   593,  1425,  1430,  1005,
      18,    19,    20,    21,   139,   140,   141,   142,   143,   144,
    1524,   468,     5,   440,   440,   933,   506,     5,   440,   839,
     809,  1130,   809,   293,   306,   408,   478,   523,   539,  1400,
    1401,  1406,  1408,   478,  1005,  1347,  1348,    26,   478,  1005,
    1327,  1340,  1408,  1410,   478,  1005,  1337,   478,  1327,  1333,
       5,  1005,    25,  1005,  1005,    25,  1008,  1165,  1005,    25,
    1005,  1005,  1005,  1571,  1458,   642,   478,   478,   889,  1458,
       5,   672,   478,  1554,    25,  1010,  1236,  1236,  1510,  1153,
     910,   910,   910,   993,   994,   478,  1162,  1194,  1044,  1045,
    1046,  1458,   672,  1510,   953,  1564,  1068,  1162,   791,   671,
     910,   400,  1205,   603,  1204,  1556,  1005,    20,  1005,  1192,
    1557,     5,  1551,   663,  1211,   116,   118,   120,   664,   672,
     881,  1181,  1184,   957,    18,    19,   478,  1084,  1086,  1215,
    1162,  1185,   992,   910,   394,   642,    26,    26,   735,   201,
    1267,   432,  1305,  1270,  1261,     5,   664,  1262,  1562,  1005,
      25,   953,   953,   636,   997,   669,  1162,   750,  1005,  1005,
     910,   389,   773,   777,   625,   771,   779,    23,   282,  1142,
    1146,   529,   928,   529,  1256,   910,   505,  1172,   666,     5,
    1091,   593,  1232,  1162,  1531,  1533,   237,  1529,  1034,  1016,
     953,   953,  1026,  1027,  1048,  1048,    39,    41,    43,    44,
      50,    51,   318,   321,   323,   343,   353,   374,   397,   401,
     477,  1047,  1049,  1050,  1078,  1162,  1183,   593,   737,    26,
     448,  1032,   371,  1509,  1509,   186,   187,   484,   593,  1005,
    1417,  1418,  1460,  1458,  1458,  1458,  1355,  1458,  1458,  1005,
    1519,   215,   428,   443,   486,   497,   518,   525,   533,   555,
     632,   638,  1387,  1389,  1390,  1391,  1498,  1458,  1363,  1387,
    1389,  1575,  1575,   433,   976,  1162,   688,   689,   969,   970,
     971,   528,   671,   690,   691,   710,   979,   980,  1575,   809,
      26,   830,    20,  1005,   440,   478,    24,    26,   672,  1498,
     440,   444,  1525,  1558,   408,   523,   632,  1449,  1502,  1505,
    1449,  1449,  1449,  1449,   666,  1505,  1500,   562,  1426,  1427,
    1428,  1458,   573,  1424,  1431,   381,   561,   572,  1373,  1493,
    1502,  1502,  1502,  1502,  1555,   903,   440,   830,   838,  1297,
     809,  1287,   478,   478,   478,  1344,  1408,   478,   478,   105,
    1345,  1347,     5,  1339,  1340,   111,   347,   367,   368,   369,
     406,   418,   429,   446,   456,   471,   519,   549,   559,   580,
     584,   612,   621,  1450,  1451,  1452,  1454,  1336,  1337,  1333,
    1334,   710,  1331,   666,   636,   440,   666,   636,   593,  1569,
     478,   730,   731,  1005,  1314,   928,   906,  1005,  1312,   663,
    1208,   672,     5,     5,     5,   626,   910,     5,   666,   530,
     672,   671,   212,   214,   318,   321,   793,   796,   797,  1078,
     794,   795,  1005,   478,  1006,   695,   696,  1209,   666,   506,
     910,  1458,  1552,  1553,  1554,   623,   663,  1212,  1005,  1005,
     994,   995,   556,   953,   889,     8,     8,   959,    26,    26,
    1085,  1086,  1162,   367,  1224,   113,   903,  1270,   266,  1272,
    1278,  1575,     5,     5,   440,   440,   766,  1005,   440,  1510,
     762,   478,   478,   778,   774,   409,   772,   910,   389,   775,
     779,   643,  1080,  1147,  1143,   411,  1141,  1142,   908,   672,
    1168,    20,  1005,  1177,  1187,    14,   530,  1233,  1234,  1502,
    1558,  1184,  1575,  1028,  1029,   597,  1004,   593,  1059,  1058,
    1063,  1062,  1061,  1060,   996,  1064,   996,  1065,  1057,  1056,
    1054,  1053,  1079,   374,  1050,  1055,   953,    46,    47,    48,
      49,    52,    53,   145,   382,   395,   458,   464,   503,   527,
     537,   538,   543,   553,   575,   578,   579,   583,   640,   651,
     738,   739,  1076,  1077,     5,    26,  1510,   296,  1162,   518,
    1491,  1492,  1510,  1219,  1485,  1487,   147,   147,   642,  1217,
    1419,  1420,   478,  1397,   198,  1431,  1458,   222,   319,  1523,
     666,   672,   478,  1392,  1392,   593,   671,     5,  1488,  1535,
     391,   400,   424,   427,   444,   548,   601,   608,   999,  1365,
    1370,   672,   671,   978,  1162,     5,   593,   972,   973,   685,
     971,   977,  1005,   977,   981,   982,   977,   374,   980,  1114,
     474,    26,   415,   501,   517,   560,   599,   628,   637,  1473,
    1499,     5,  1472,   440,     5,  1502,     5,   440,  1502,  1502,
    1502,  1502,  1005,   440,   478,  1428,     5,  1005,  1464,     9,
     342,   478,   490,  1434,  1435,  1436,  1437,  1438,  1442,  1446,
    1448,  1502,   417,  1422,  1432,  1005,  1494,   665,  1449,   381,
     474,   508,  1280,  1300,  1131,   508,  1242,  1274,   658,  1005,
    1403,  1405,  1458,  1462,  1463,  1407,  1462,  1407,     5,   440,
    1345,  1407,  1434,  1005,   440,  1348,     5,   440,   478,   478,
     478,  1472,  1472,   478,   478,   478,   478,   478,   254,   255,
     256,   448,  1409,  1411,     5,   440,     5,   440,  1005,  1005,
      25,  1005,  1005,    25,  1005,   910,  1005,  1324,  1325,     5,
    1326,  1327,   928,  1120,   666,  1326,   623,  1510,  1510,   910,
     910,   993,   556,   910,  1567,     5,  1045,    20,  1462,  1510,
     794,   802,   801,   803,  1005,  1009,   804,  1009,   239,   797,
     800,     5,  1048,   666,   910,     8,  1557,  1173,   666,     5,
    1510,   623,  1005,  1181,   928,   600,  1368,     5,   440,  1162,
       5,    26,  1162,   375,    25,  1302,   394,   394,   506,   666,
     394,   478,   751,   755,   748,  1575,  1575,   780,   776,   772,
    1081,    25,  1004,  1148,  1162,  1575,   910,   473,   506,   928,
       5,  1035,  1030,  1031,    26,   735,  1005,  1575,  1575,  1575,
    1575,  1575,  1575,     5,  1051,     5,  1052,  1575,  1575,  1575,
    1575,  1084,  1575,  1004,    25,    14,    14,     5,   440,    26,
    1458,  1498,  1479,   642,   642,  1354,  1484,  1485,  1420,  1398,
    1462,   663,   999,   478,  1358,  1005,  1520,  1519,  1393,  1462,
     510,  1394,  1395,  1460,  1458,  1391,  1499,    93,    94,    95,
      96,    97,   630,  1538,   910,   910,   600,  1366,   999,  1394,
    1458,     5,  1162,   977,  1575,  1575,     5,   984,   985,  1575,
    1575,   983,  1107,   873,   440,   478,  1430,  1472,   672,  1472,
     440,  1502,   440,   440,   440,   440,  1427,  1429,  1427,  1437,
    1497,  1434,  1502,  1497,     6,     7,     9,    10,    12,    13,
      14,    15,    16,    17,   300,   420,   421,   476,   603,   669,
     719,   720,  1445,  1447,  1423,  1501,  1502,   495,  1421,  1433,
     316,  1323,    26,  1374,  1375,  1376,  1462,  1491,  1494,   827,
     121,   122,   124,   125,   126,   224,   232,   266,   275,   304,
     305,   349,   393,   448,   674,   675,   676,   677,   678,   679,
     680,   681,   682,   683,  1277,  1281,   185,   561,  1282,  1298,
    1107,   208,   223,   224,   232,   266,   275,   304,   349,   393,
    1275,  1276,  1288,  1282,  1463,   506,  1461,   440,     5,   666,
       5,   440,   440,  1408,   440,   440,  1340,    26,  1455,  1455,
      26,   672,   478,   672,    26,  1456,    26,    26,  1456,  1456,
      25,  1465,   206,   306,   344,   408,   422,   523,   539,  1402,
    1412,  1413,  1414,  1415,  1337,  1333,   666,   666,   585,   634,
       5,   440,   731,     5,   440,   908,   440,    20,   440,  1510,
       5,   910,   613,   322,   740,   741,   910,  1048,  1575,  1575,
       5,   798,   506,   666,     5,   799,  1575,   795,   593,    20,
    1005,     5,  1005,  1199,   474,    20,  1462,  1553,     8,  1510,
     438,   705,   908,  1369,   958,  1086,   714,  1222,   903,     5,
     762,  1162,   747,   729,  1005,  1162,   753,   440,   762,   762,
    1575,  1575,  1084,  1145,    25,  1149,  1162,   618,   989,  1173,
     530,   909,  1092,  1234,   110,   589,  1036,  1022,  1023,   666,
     996,  1575,   996,  1575,   735,    26,  1162,    26,  1162,   739,
     440,   478,  1511,  1499,  1485,  1485,  1477,     5,   440,   518,
    1496,  1359,  1462,   526,  1356,  1496,   672,     5,   440,     5,
     593,  1489,    18,    19,   112,   475,   478,   491,   530,   531,
     543,   584,   623,   635,   647,   648,   655,   658,  1005,  1465,
    1497,  1543,  1544,  1545,  1546,  1547,  1548,  1558,  1543,  1543,
    1543,  1462,  1540,  1542,  1539,  1540,  1541,  1536,  1367,   672,
    1162,  1005,  1575,  1575,  1575,  1575,   670,    26,   440,   672,
    1473,   672,     5,   440,   440,  1435,  1436,  1440,  1503,  1440,
     478,  1497,  1440,   478,  1497,  1440,    10,   297,   435,   437,
    1502,     5,  1434,     5,   585,   634,  1377,  1323,   670,  1278,
    1278,  1278,    25,  1278,  1278,  1278,  1278,  1278,  1278,    25,
      25,  1278,  1281,  1162,  1189,  1190,   665,   494,  1243,  1575,
      25,    25,    26,    26,    26,    26,    26,    25,  1162,  1276,
    1243,    26,  1402,  1462,    20,  1005,  1462,  1345,   440,   440,
       5,   440,  1473,    26,  1473,     5,  1453,     5,   440,   440,
     440,  1453,  1404,  1458,   478,  1414,  1345,  1005,  1005,  1325,
     669,   723,  1319,  1320,  1321,  1327,    56,   133,   134,   292,
     669,  1315,  1316,  1317,   515,   888,  1315,     5,   423,  1510,
       5,   478,   440,   597,  1075,  1009,  1575,   732,    20,  1005,
    1009,  1575,   953,   910,  1510,     8,   953,  1184,  1575,    26,
    1004,    25,  1303,  1181,   474,   762,   752,   756,   440,  1575,
    1004,   910,   987,   474,  1038,  1037,   488,  1024,  1025,    20,
    1005,  1512,  1513,   600,  1495,  1480,  1478,  1462,  1498,   190,
    1399,     5,   440,  1357,  1520,  1462,  1395,  1394,  1495,  1546,
    1546,  1545,   478,   478,   478,   478,   478,   478,   478,  1005,
     478,     5,   440,    18,    19,    20,    21,  1524,   440,     5,
     440,     5,    14,   198,   573,  1537,  1184,  1394,   259,  1115,
     869,   440,  1473,  1473,  1427,   489,  1439,  1439,  1443,  1444,
    1465,  1558,  1439,  1443,  1439,  1440,  1502,  1501,  1375,   839,
     585,   634,  1191,     5,  1189,   109,   184,   246,   248,   264,
     272,   276,   301,  1244,  1245,  1299,  1115,  1289,     5,   474,
    1461,    26,   440,    26,  1457,   440,    26,   440,   478,  1434,
    1318,  1574,    26,  1321,    26,    26,  1318,  1323,  1317,   996,
     735,   423,  1510,   910,   742,   615,  1197,    26,   735,   474,
    1075,   440,  1510,   288,   735,   440,   440,   478,   754,   394,
     760,   440,   749,  1144,  1575,   506,   910,  1575,  1004,     5,
     440,  1184,  1430,  1499,  1462,   478,  1430,   440,  1525,  1449,
    1545,  1549,  1449,  1449,  1449,  1449,   666,  1549,  1544,  1545,
    1545,  1545,  1545,  1540,    14,  1541,  1544,   999,  1434,   191,
     663,  1388,  1441,  1465,  1506,     5,   440,   440,  1439,     7,
    1190,  1246,  1247,  1162,  1249,  1162,  1248,  1250,  1245,   287,
     287,    26,   440,   672,   440,  1405,   440,   887,  1510,   441,
     250,   307,   332,   341,   379,   387,   479,   649,   739,   743,
     744,   478,   666,   735,  1221,  1304,   757,   440,  1181,   760,
     760,  1575,   988,  1173,   622,  1072,  1513,  1493,  1430,   530,
    1360,  1361,  1502,  1493,   440,  1545,     5,   440,  1545,  1545,
    1545,  1545,  1005,   440,   478,  1005,  1444,  1502,  1575,  1575,
    1251,  1575,  1252,  1575,  1575,   474,  1473,   440,   286,   397,
     401,   890,   891,   892,  1078,   991,   991,   991,   991,   991,
     991,    25,     5,   440,   910,    20,  1005,  1078,  1225,  1226,
    1227,   760,   762,   760,   289,   474,  1039,   735,     5,   440,
     335,   336,  1481,   440,  1545,   440,   440,   440,   440,  1543,
    1575,  1575,   894,   893,   286,   892,   895,   744,     5,  1228,
     330,  1227,   758,  1575,  1361,    25,  1005,  1482,  1483,   440,
    1575,  1575,  1575,   910,  1575,   440,  1036,   666,   666,     5,
     440,   759,  1005,  1005,  1483,   211,   394,   761,   666,  1181,
    1005
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

  case 99:
#line 1428 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1434 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1437 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1452 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1462 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1468 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1477 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1490 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1493 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1495 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1501 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1503 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1508 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1513 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1519 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1523 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1538 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1541 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1544 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1547 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1550 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1553 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1575 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1584 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1594 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1608 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1613 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1616 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1625 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1631 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1646 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1650 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1655 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1665 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1665 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1666 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1666 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1667 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1667 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1668 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1668 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1669 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1669 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1677 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1681 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1687 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1691 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1706 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1709 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1712 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1715 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1718 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1721 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1730 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1738 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1743 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1756 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1760 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1775 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1776 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1784 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1784 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1793 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1793 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1802 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1803 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1804 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1807 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1812 "fgl.yacc"
    { }
    break;

  case 194:
#line 1812 "fgl.yacc"
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
#line 1829 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1833 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1848 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1849 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1850 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1851 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1856 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1862 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1871 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1875 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1891 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1893 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1894 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1901 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1901 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1902 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1903 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1906 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1908 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1918 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1933 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1933 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1939 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1940 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1941 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1942 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1943 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1944 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1945 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1946 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1947 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1948 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1951 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1952 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1953 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1954 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1958 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1963 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1968 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1972 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1975 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1979 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1980 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1981 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1982 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1983 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1984 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1985 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1986 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1987 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1990 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1991 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1992 "fgl.yacc"
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
#line 2027 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2031 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2033 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2035 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2037 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2042 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2046 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2046 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2050 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2051 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2052 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2053 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2054 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2057 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2062 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2062 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2065 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2067 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2073 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2075 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2081 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2089 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2089 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2092 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2093 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2094 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2095 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2096 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2099 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2120 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2129 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2131 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2133 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 317:
#line 2135 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 318:
#line 2136 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2137 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2138 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2139 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2144 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2151 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2156 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2158 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2160 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2161 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2162 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2163 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2164 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2165 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2166 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2169 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2171 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2177 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2185 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2193 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2197 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2205 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2206 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2207 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2208 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2227 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2239 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2243 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2246 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2249 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2250 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2251 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2252 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2253 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2259 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2266 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2271 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2276 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2281 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2285 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2294 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2296 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2301 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2313 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2317 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2320 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2324 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2327 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2331 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2338 "fgl.yacc"
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
#line 2356 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2362 "fgl.yacc"
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
#line 2386 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2389 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2404 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 384:
#line 2407 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2421 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 386:
#line 2423 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 387:
#line 2425 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 388:
#line 2427 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 389:
#line 2429 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 390:
#line 2431 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 391:
#line 2432 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 392:
#line 2439 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 393:
#line 2441 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 394:
#line 2445 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 395:
#line 2447 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 396:
#line 2449 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 397:
#line 2451 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 398:
#line 2453 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 399:
#line 2455 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 400:
#line 2457 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 401:
#line 2463 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 406:
#line 2480 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 409:
#line 2486 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 410:
#line 2490 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 411:
#line 2495 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 415:
#line 2505 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 416:
#line 2506 "fgl.yacc"
    {inc_counter();}
    break;

  case 422:
#line 2512 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 423:
#line 2519 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 424:
#line 2519 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 426:
#line 2524 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 427:
#line 2528 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2534 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2542 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2548 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 431:
#line 2557 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 432:
#line 2559 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 433:
#line 2566 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 434:
#line 2574 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 435:
#line 2578 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 436:
#line 2587 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 437:
#line 2592 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 438:
#line 2597 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 439:
#line 2601 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 440:
#line 2603 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 441:
#line 2606 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 442:
#line 2613 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 443:
#line 2621 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2633 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2639 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 446:
#line 2645 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 449:
#line 2655 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 450:
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

  case 451:
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

  case 452:
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

  case 453:
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

  case 454:
#line 2760 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 455:
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

  case 456:
#line 2776 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 457:
#line 2780 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 458:
#line 2786 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 459:
#line 2789 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 460:
#line 2797 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 461:
#line 2801 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 462:
#line 2804 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 463:
#line 2810 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 464:
#line 2820 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 465:
#line 2825 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 466:
#line 2832 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 467:
#line 2835 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 468:
#line 2838 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 469:
#line 2843 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 470:
#line 2850 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 471:
#line 2855 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 472:
#line 2860 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 473:
#line 2865 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 474:
#line 2876 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 475:
#line 2884 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 476:
#line 2892 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 477:
#line 2897 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 478:
#line 2901 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 479:
#line 2906 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 480:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 481:
#line 2914 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 482:
#line 2920 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 483:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 484:
#line 2927 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 485:
#line 2931 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 486:
#line 2935 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 487:
#line 2939 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 488:
#line 2943 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 489:
#line 2950 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 490:
#line 2960 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 491:
#line 2965 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 492:
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

  case 493:
#line 2981 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 494:
#line 2986 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 495:
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

  case 496:
#line 3003 "fgl.yacc"
    {chk4var=1;}
    break;

  case 497:
#line 3003 "fgl.yacc"
    {chk4var=0;}
    break;

  case 498:
#line 3003 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 499:
#line 3006 "fgl.yacc"
    {chk4var=1;}
    break;

  case 500:
#line 3006 "fgl.yacc"
    {chk4var=0;}
    break;

  case 501:
#line 3006 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 502:
#line 3010 "fgl.yacc"
    {chk4var=1;}
    break;

  case 503:
#line 3010 "fgl.yacc"
    {chk4var=0;}
    break;

  case 504:
#line 3010 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 505:
#line 3014 "fgl.yacc"
    {chk4var=1;}
    break;

  case 506:
#line 3014 "fgl.yacc"
    {chk4var=0;}
    break;

  case 507:
#line 3014 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 508:
#line 3018 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3024 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3030 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3036 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3042 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 513:
#line 3048 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 514:
#line 3058 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 515:
#line 3059 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 518:
#line 3067 "fgl.yacc"
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

  case 519:
#line 3078 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 520:
#line 3079 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 521:
#line 3085 "fgl.yacc"
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

  case 522:
#line 3096 "fgl.yacc"
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

  case 523:
#line 3106 "fgl.yacc"
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

  case 526:
#line 3119 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 527:
#line 3124 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 528:
#line 3131 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 529:
#line 3135 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 530:
#line 3138 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 531:
#line 3141 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 532:
#line 3147 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 533:
#line 3150 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 534:
#line 3153 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 535:
#line 3170 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 536:
#line 3173 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 537:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 538:
#line 3180 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 539:
#line 3181 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 541:
#line 3186 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 542:
#line 3187 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 543:
#line 3188 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 544:
#line 3189 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 545:
#line 3191 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 546:
#line 3192 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 547:
#line 3193 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3195 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 549:
#line 3196 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 551:
#line 3202 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 552:
#line 3206 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 553:
#line 3210 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 554:
#line 3215 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 555:
#line 3219 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 556:
#line 3234 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 557:
#line 3238 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 558:
#line 3244 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 559:
#line 3248 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 560:
#line 3257 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 561:
#line 3258 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 562:
#line 3270 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 563:
#line 3276 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 564:
#line 3284 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 571:
#line 3301 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 572:
#line 3303 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 573:
#line 3306 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 574:
#line 3308 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 579:
#line 3322 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 580:
#line 3324 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 581:
#line 3327 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 582:
#line 3329 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 595:
#line 3360 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 596:
#line 3362 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 597:
#line 3365 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 598:
#line 3367 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 599:
#line 3370 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 600:
#line 3372 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 601:
#line 3375 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 602:
#line 3377 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 603:
#line 3380 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 604:
#line 3382 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 605:
#line 3396 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 606:
#line 3400 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 607:
#line 3401 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 608:
#line 3408 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 610:
#line 3426 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 611:
#line 3442 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 612:
#line 3443 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 613:
#line 3444 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 614:
#line 3445 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 615:
#line 3446 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 616:
#line 3447 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 617:
#line 3448 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 621:
#line 3456 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 623:
#line 3462 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 624:
#line 3465 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 625:
#line 3470 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 626:
#line 3475 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 627:
#line 3478 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 628:
#line 3483 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 629:
#line 3488 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 630:
#line 3493 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 631:
#line 3500 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 632:
#line 3501 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 633:
#line 3508 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 634:
#line 3515 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 635:
#line 3517 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 636:
#line 3523 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 637:
#line 3528 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 638:
#line 3533 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 639:
#line 3538 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 640:
#line 3538 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 641:
#line 3541 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 642:
#line 3547 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 643:
#line 3552 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 644:
#line 3556 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 647:
#line 3564 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 648:
#line 3567 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 649:
#line 3570 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 650:
#line 3575 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 651:
#line 3580 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 652:
#line 3585 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 653:
#line 3592 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 655:
#line 3601 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 656:
#line 3663 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 658:
#line 3672 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 659:
#line 3681 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 661:
#line 3688 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 662:
#line 3691 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 663:
#line 3697 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 664:
#line 3703 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 665:
#line 3707 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 666:
#line 3711 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 667:
#line 3717 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 668:
#line 3721 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 669:
#line 3725 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 670:
#line 3730 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 671:
#line 3735 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 690:
#line 3776 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 691:
#line 3783 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 692:
#line 3785 "fgl.yacc"
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

  case 694:
#line 3804 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 696:
#line 3807 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 697:
#line 3809 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 698:
#line 3812 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 699:
#line 3816 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 700:
#line 3819 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 701:
#line 3825 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 702:
#line 3836 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 703:
#line 3837 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 704:
#line 3840 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 706:
#line 3846 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 707:
#line 3850 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 708:
#line 3851 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 709:
#line 3855 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 713:
#line 3870 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 714:
#line 3872 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 717:
#line 3881 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 718:
#line 3884 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 719:
#line 3888 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 720:
#line 3891 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 721:
#line 3894 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 722:
#line 3897 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 3900 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 724:
#line 3904 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 725:
#line 3907 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 726:
#line 3910 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 727:
#line 3913 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 728:
#line 3916 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 729:
#line 3919 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 730:
#line 3922 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3925 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 732:
#line 3928 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 733:
#line 3929 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 734:
#line 3929 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 735:
#line 3930 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 736:
#line 3930 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 737:
#line 3931 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 738:
#line 3931 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 739:
#line 3932 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 740:
#line 3935 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 741:
#line 3936 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 742:
#line 3939 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 743:
#line 3947 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 744:
#line 3951 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 745:
#line 3957 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 746:
#line 3961 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 747:
#line 3966 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 748:
#line 3971 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 749:
#line 3976 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 750:
#line 3977 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 751:
#line 3978 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 752:
#line 3982 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 753:
#line 3986 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 754:
#line 3995 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 755:
#line 4000 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 756:
#line 4004 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 757:
#line 4011 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 758:
#line 4020 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 759:
#line 4026 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 760:
#line 4027 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 761:
#line 4028 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 762:
#line 4029 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 763:
#line 4032 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 765:
#line 4035 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 766:
#line 4042 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 767:
#line 4043 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 768:
#line 4044 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 769:
#line 4045 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 770:
#line 4046 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 771:
#line 4047 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 772:
#line 4048 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 773:
#line 4049 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 774:
#line 4050 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 775:
#line 4055 "fgl.yacc"
    {iskey=1;}
    break;

  case 776:
#line 4055 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 777:
#line 4057 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 778:
#line 4060 "fgl.yacc"
    {iskey=1;}
    break;

  case 779:
#line 4060 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 780:
#line 4062 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 781:
#line 4066 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 782:
#line 4069 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 783:
#line 4070 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 785:
#line 4073 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 791:
#line 4085 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 792:
#line 4086 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 793:
#line 4087 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 794:
#line 4088 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 795:
#line 4089 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 796:
#line 4090 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 797:
#line 4091 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 798:
#line 4092 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 799:
#line 4093 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 800:
#line 4094 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 801:
#line 4095 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 802:
#line 4096 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 803:
#line 4097 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 804:
#line 4098 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 805:
#line 4102 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 806:
#line 4120 "fgl.yacc"
    {chk4var=1;}
    break;

  case 807:
#line 4120 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 808:
#line 4123 "fgl.yacc"
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

  case 809:
#line 4147 "fgl.yacc"
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

  case 811:
#line 4165 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 812:
#line 4171 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 813:
#line 4177 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 814:
#line 4183 "fgl.yacc"
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

  case 815:
#line 4195 "fgl.yacc"
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

  case 816:
#line 4220 "fgl.yacc"
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

  case 819:
#line 4236 "fgl.yacc"
    {
	}
    break;

  case 828:
#line 4261 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 832:
#line 4269 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 848:
#line 4295 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 849:
#line 4296 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 850:
#line 4304 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 851:
#line 4309 "fgl.yacc"
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

  case 852:
#line 4325 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 853:
#line 4331 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 855:
#line 4346 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 856:
#line 4359 "fgl.yacc"
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

  case 857:
#line 4369 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 858:
#line 4376 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 859:
#line 4383 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 860:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 861:
#line 4389 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 862:
#line 4394 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 863:
#line 4400 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 864:
#line 4408 "fgl.yacc"
    {
}
    break;

  case 868:
#line 4420 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 870:
#line 4428 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 871:
#line 4434 "fgl.yacc"
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

  case 874:
#line 4450 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 875:
#line 4454 "fgl.yacc"
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

  case 876:
#line 4467 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 878:
#line 4480 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 879:
#line 4486 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 880:
#line 4490 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 883:
#line 4502 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 884:
#line 4505 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 885:
#line 4509 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 886:
#line 4512 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 887:
#line 4524 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 888:
#line 4532 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 889:
#line 4538 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 890:
#line 4549 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 891:
#line 4553 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 892:
#line 4560 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 893:
#line 4567 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 894:
#line 4573 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 895:
#line 4578 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 898:
#line 4585 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 899:
#line 4586 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 900:
#line 4588 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 901:
#line 4589 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 902:
#line 4592 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 903:
#line 4593 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 904:
#line 4594 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 905:
#line 4596 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 906:
#line 4601 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 907:
#line 4606 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 908:
#line 4613 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 912:
#line 4620 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 913:
#line 4622 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 914:
#line 4624 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 916:
#line 4634 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 917:
#line 4637 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 918:
#line 4640 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 925:
#line 4656 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 926:
#line 4661 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 927:
#line 4661 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 928:
#line 4664 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 929:
#line 4692 "fgl.yacc"
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

  case 931:
#line 4749 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 933:
#line 4756 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 934:
#line 4760 "fgl.yacc"
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

  case 935:
#line 4803 "fgl.yacc"
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

  case 939:
#line 4851 "fgl.yacc"
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

  case 940:
#line 4865 "fgl.yacc"
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

  case 945:
#line 4889 "fgl.yacc"
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

  case 946:
#line 4949 "fgl.yacc"
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

  case 947:
#line 5005 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 948:
#line 5010 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 949:
#line 5018 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 950:
#line 5023 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 951:
#line 5031 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 952:
#line 5037 "fgl.yacc"
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

  case 953:
#line 5069 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 954:
#line 5072 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 955:
#line 5074 "fgl.yacc"
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

  case 956:
#line 5115 "fgl.yacc"
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

  case 961:
#line 5168 "fgl.yacc"
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

  case 962:
#line 5220 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 964:
#line 5227 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 965:
#line 5233 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 966:
#line 5244 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5251 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5259 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 970:
#line 5262 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 971:
#line 5263 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 973:
#line 5265 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 974:
#line 5266 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 975:
#line 5269 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 976:
#line 5272 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 977:
#line 5278 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 978:
#line 5281 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 979:
#line 5285 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 980:
#line 5290 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 981:
#line 5298 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 982:
#line 5303 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 983:
#line 5310 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 984:
#line 5313 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 989:
#line 5326 "fgl.yacc"
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

  case 990:
#line 5345 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 991:
#line 5352 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 992:
#line 5359 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 993:
#line 5362 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 994:
#line 5376 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 999:
#line 5393 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1000:
#line 5398 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1001:
#line 5404 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1003:
#line 5411 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1004:
#line 5416 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1005:
#line 5419 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1006:
#line 5420 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1007:
#line 5423 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1008:
#line 5424 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1009:
#line 5427 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1010:
#line 5428 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1011:
#line 5433 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1012:
#line 5440 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1013:
#line 5443 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1014:
#line 5449 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1015:
#line 5451 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1016:
#line 5453 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1017:
#line 5455 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5458 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1019:
#line 5458 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1020:
#line 5459 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1021:
#line 5464 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1022:
#line 5472 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1023:
#line 5473 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1024:
#line 5478 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1025:
#line 5480 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1026:
#line 5482 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1030:
#line 5500 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1031:
#line 5501 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1032:
#line 5502 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1033:
#line 5503 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1034:
#line 5504 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1035:
#line 5505 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1036:
#line 5506 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1037:
#line 5507 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1038:
#line 5508 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1039:
#line 5509 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1040:
#line 5510 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1041:
#line 5511 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1042:
#line 5512 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1043:
#line 5513 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1044:
#line 5514 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1045:
#line 5515 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1046:
#line 5516 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1047:
#line 5517 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1048:
#line 5518 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1049:
#line 5519 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1050:
#line 5520 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1051:
#line 5521 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1052:
#line 5522 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1053:
#line 5523 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1054:
#line 5524 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1055:
#line 5525 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1056:
#line 5540 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1059:
#line 5549 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1060:
#line 5553 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1061:
#line 5557 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1062:
#line 5561 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1063:
#line 5565 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1065:
#line 5585 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1066:
#line 5590 "fgl.yacc"
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

  case 1067:
#line 5603 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1068:
#line 5604 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1069:
#line 5608 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1070:
#line 5613 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1071:
#line 5614 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1072:
#line 5618 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1076:
#line 5624 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1077:
#line 5627 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1079:
#line 5642 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1080:
#line 5646 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1081:
#line 5652 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1082:
#line 5653 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1083:
#line 5658 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1084:
#line 5659 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1085:
#line 5662 "fgl.yacc"
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

  case 1087:
#line 5689 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
			}
    break;

  case 1088:
#line 5693 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1089:
#line 5697 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1090:
#line 5701 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[0].str);
			}
    break;

  case 1096:
#line 5719 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1097:
#line 5725 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1098:
#line 5733 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1099:
#line 5739 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1100:
#line 5741 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1104:
#line 5751 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1105:
#line 5751 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1106:
#line 5756 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1107:
#line 5760 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1108:
#line 5765 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1109:
#line 5765 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1110:
#line 5769 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1111:
#line 5769 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1112:
#line 5770 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1113:
#line 5770 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1114:
#line 5771 "fgl.yacc"
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

  case 1115:
#line 5784 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1116:
#line 5785 "fgl.yacc"
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

  case 1117:
#line 5801 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1124:
#line 5813 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1125:
#line 5813 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1126:
#line 5819 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1127:
#line 5819 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1128:
#line 5822 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1129:
#line 5822 "fgl.yacc"
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

  case 1130:
#line 5838 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1131:
#line 5839 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1132:
#line 5840 "fgl.yacc"
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

  case 1133:
#line 5849 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1134:
#line 5861 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1140:
#line 5872 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1141:
#line 5877 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1142:
#line 5877 "fgl.yacc"
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

  case 1143:
#line 5898 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1144:
#line 5903 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1145:
#line 5909 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1146:
#line 5910 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1147:
#line 5911 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1148:
#line 5915 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1149:
#line 5916 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1150:
#line 5917 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1151:
#line 5918 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1152:
#line 5922 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1153:
#line 5932 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1154:
#line 5934 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1155:
#line 5939 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1156:
#line 5942 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1157:
#line 5947 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1158:
#line 5954 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1159:
#line 5961 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1160:
#line 5968 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1161:
#line 5977 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1162:
#line 5984 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1163:
#line 5991 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1164:
#line 5998 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1165:
#line 6005 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1170:
#line 6018 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1171:
#line 6019 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1172:
#line 6020 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1173:
#line 6021 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1174:
#line 6022 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1175:
#line 6023 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1176:
#line 6024 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1177:
#line 6025 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1178:
#line 6026 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1179:
#line 6027 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1182:
#line 6033 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1183:
#line 6034 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1184:
#line 6035 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1185:
#line 6036 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1190:
#line 6045 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1191:
#line 6046 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1192:
#line 6047 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1193:
#line 6048 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1194:
#line 6049 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1195:
#line 6050 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1196:
#line 6051 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1197:
#line 6052 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1198:
#line 6054 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1199:
#line 6055 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1200:
#line 6056 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1201:
#line 6057 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1202:
#line 6059 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1203:
#line 6060 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1204:
#line 6061 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1205:
#line 6062 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1209:
#line 6067 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1210:
#line 6068 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1214:
#line 6075 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1215:
#line 6083 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1216:
#line 6091 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1217:
#line 6103 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1218:
#line 6112 "fgl.yacc"
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

  case 1219:
#line 6123 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1220:
#line 6127 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1221:
#line 6131 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1222:
#line 6137 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1223:
#line 6142 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1224:
#line 6150 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1225:
#line 6153 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1226:
#line 6162 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1227:
#line 6173 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1229:
#line 6180 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1230:
#line 6188 "fgl.yacc"
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

  case 1231:
#line 6198 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1232:
#line 6201 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1233:
#line 6205 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1234:
#line 6213 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1235:
#line 6216 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1236:
#line 6222 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1237:
#line 6226 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1238:
#line 6230 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1239:
#line 6234 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1240:
#line 6238 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1241:
#line 6244 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1242:
#line 6245 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1243:
#line 6246 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1244:
#line 6247 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1245:
#line 6252 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1246:
#line 6254 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1247:
#line 6257 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1248:
#line 6261 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1249:
#line 6264 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1250:
#line 6271 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1251:
#line 6276 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1252:
#line 6277 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1253:
#line 6278 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1254:
#line 6279 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1255:
#line 6284 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1256:
#line 6285 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1257:
#line 6291 "fgl.yacc"
    {insql=1;}
    break;

  case 1258:
#line 6291 "fgl.yacc"
    {insql=0;}
    break;

  case 1259:
#line 6291 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1260:
#line 6296 "fgl.yacc"
    {insql=1;}
    break;

  case 1261:
#line 6296 "fgl.yacc"
    {insql=0;}
    break;

  case 1262:
#line 6296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1263:
#line 6304 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1264:
#line 6305 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1266:
#line 6310 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1267:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1268:
#line 6316 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1269:
#line 6317 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1270:
#line 6318 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1271:
#line 6319 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1273:
#line 6324 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1274:
#line 6324 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1276:
#line 6328 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1277:
#line 6332 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1278:
#line 6333 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1279:
#line 6336 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1280:
#line 6337 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1281:
#line 6340 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1282:
#line 6343 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1283:
#line 6346 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1284:
#line 6352 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1285:
#line 6354 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1287:
#line 6367 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1288:
#line 6371 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1289:
#line 6372 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1291:
#line 6377 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1292:
#line 6380 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1293:
#line 6386 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 6389 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6397 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1297:
#line 6404 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1298:
#line 6408 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1299:
#line 6412 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1300:
#line 6418 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1301:
#line 6421 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1302:
#line 6430 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1303:
#line 6433 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1304:
#line 6436 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1305:
#line 6439 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1306:
#line 6442 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1307:
#line 6445 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1308:
#line 6448 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1309:
#line 6455 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1310:
#line 6458 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1311:
#line 6465 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1312:
#line 6468 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1313:
#line 6474 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1314:
#line 6477 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1315:
#line 6484 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1316:
#line 6487 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1318:
#line 6495 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1320:
#line 6504 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1321:
#line 6507 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1322:
#line 6513 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1323:
#line 6516 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1324:
#line 6522 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1325:
#line 6529 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1326:
#line 6530 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1327:
#line 6534 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1328:
#line 6544 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1329:
#line 6547 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1330:
#line 6553 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1331:
#line 6555 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1332:
#line 6560 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1333:
#line 6561 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1334:
#line 6566 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1335:
#line 6567 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1336:
#line 6573 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1337:
#line 6574 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1341:
#line 6601 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1347:
#line 6607 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1348:
#line 6610 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1349:
#line 6613 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1350:
#line 6619 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1352:
#line 6625 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1354:
#line 6636 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1355:
#line 6650 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1356:
#line 6659 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1357:
#line 6659 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1358:
#line 6664 "fgl.yacc"
    {insql=1;}
    break;

  case 1359:
#line 6664 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1360:
#line 6669 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1361:
#line 6672 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1362:
#line 6674 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6681 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6685 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1366:
#line 6689 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1367:
#line 6696 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1368:
#line 6699 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1369:
#line 6706 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1370:
#line 6710 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1371:
#line 6716 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1372:
#line 6721 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1373:
#line 6725 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1374:
#line 6731 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1375:
#line 6734 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1376:
#line 6740 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
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
#line 6751 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1379:
#line 6756 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1380:
#line 6766 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1381:
#line 6769 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1382:
#line 6771 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1383:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1384:
#line 6775 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1385:
#line 6777 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1386:
#line 6779 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1387:
#line 6781 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1388:
#line 6787 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1389:
#line 6797 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1390:
#line 6804 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6810 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6813 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6820 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1399:
#line 6825 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1400:
#line 6830 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1401:
#line 6837 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1402:
#line 6838 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1403:
#line 6845 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1404:
#line 6856 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1405:
#line 6857 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6858 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1407:
#line 6861 "fgl.yacc"
    {insql=1;}
    break;

  case 1408:
#line 6861 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1409:
#line 6866 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1410:
#line 6871 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1412:
#line 6877 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1414:
#line 6881 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1415:
#line 6886 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1416:
#line 6891 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1417:
#line 6895 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1419:
#line 6901 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1420:
#line 6905 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1421:
#line 6912 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6913 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6914 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6915 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6925 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1429:
#line 6926 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1430:
#line 6927 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 6931 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1432:
#line 6932 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1435:
#line 6939 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 6942 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 6950 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1443:
#line 6952 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 6958 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1447:
#line 6964 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 6974 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1451:
#line 6979 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1452:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 6987 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 6990 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1457:
#line 6996 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1458:
#line 7004 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 7009 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7019 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7033 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7039 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7044 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1471:
#line 7047 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1472:
#line 7050 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7057 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1474:
#line 7058 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1475:
#line 7059 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1476:
#line 7061 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1477:
#line 7074 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1478:
#line 7079 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1480:
#line 7083 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1481:
#line 7085 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1482:
#line 7092 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1483:
#line 7095 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1484:
#line 7101 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1485:
#line 7109 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1486:
#line 7113 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1487:
#line 7117 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1488:
#line 7121 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1489:
#line 7125 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1490:
#line 7128 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1491:
#line 7131 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1492:
#line 7139 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1493:
#line 7146 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1496:
#line 7155 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1497:
#line 7161 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1498:
#line 7164 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1499:
#line 7175 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1500:
#line 7182 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1501:
#line 7188 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1502:
#line 7191 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 7198 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1504:
#line 7205 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1506:
#line 7212 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1507:
#line 7218 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1508:
#line 7219 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7220 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1511:
#line 7224 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1513:
#line 7229 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1514:
#line 7236 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1515:
#line 7241 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1516:
#line 7242 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1517:
#line 7245 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1518:
#line 7248 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1519:
#line 7253 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1520:
#line 7254 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1521:
#line 7259 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1522:
#line 7262 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1523:
#line 7268 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1524:
#line 7271 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1525:
#line 7277 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1526:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1527:
#line 7286 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1528:
#line 7289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1529:
#line 7296 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1530:
#line 7297 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1531:
#line 7326 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1532:
#line 7328 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1533:
#line 7332 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1535:
#line 7345 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1536:
#line 7348 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1537:
#line 7351 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1538:
#line 7354 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1540:
#line 7362 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1541:
#line 7365 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1543:
#line 7371 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1545:
#line 7377 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1546:
#line 7380 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1547:
#line 7383 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1548:
#line 7386 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1549:
#line 7389 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1550:
#line 7392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1551:
#line 7395 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1552:
#line 7398 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1553:
#line 7403 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1555:
#line 7410 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1561:
#line 7418 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1562:
#line 7419 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1563:
#line 7424 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1564:
#line 7427 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1565:
#line 7431 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1566:
#line 7437 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1567:
#line 7438 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1568:
#line 7439 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1569:
#line 7440 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1574:
#line 7460 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1576:
#line 7464 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1577:
#line 7465 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1579:
#line 7468 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1580:
#line 7470 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1588:
#line 7479 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7481 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1590:
#line 7483 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1592:
#line 7486 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1594:
#line 7489 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1598:
#line 7494 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1599:
#line 7496 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1600:
#line 7499 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1601:
#line 7500 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1602:
#line 7507 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1606:
#line 7512 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1610:
#line 7528 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1611:
#line 7535 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1612:
#line 7539 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1613:
#line 7540 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1614:
#line 7541 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1615:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1616:
#line 7550 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1617:
#line 7551 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1618:
#line 7562 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1619:
#line 7569 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1620:
#line 7574 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1621:
#line 7575 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1622:
#line 7576 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1623:
#line 7584 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1624:
#line 7585 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1625:
#line 7586 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1627:
#line 7612 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1628:
#line 7613 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1629:
#line 7614 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1630:
#line 7618 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1631:
#line 7621 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1632:
#line 7627 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1633:
#line 7632 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1634:
#line 7637 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1636:
#line 7648 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1640:
#line 7666 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1641:
#line 7669 "fgl.yacc"
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

  case 1642:
#line 7682 "fgl.yacc"
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

  case 1643:
#line 7697 "fgl.yacc"
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

  case 1644:
#line 7709 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1645:
#line 7711 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1646:
#line 7714 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1647:
#line 7714 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1648:
#line 7714 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1649:
#line 7714 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1650:
#line 7714 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1651:
#line 7714 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1652:
#line 7715 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1653:
#line 7718 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1654:
#line 7723 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1655:
#line 7723 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1656:
#line 7723 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1657:
#line 7723 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1658:
#line 7723 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1659:
#line 7723 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1660:
#line 7725 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1661:
#line 7728 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1676:
#line 7735 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1677:
#line 7738 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1678:
#line 7739 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1679:
#line 7740 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1680:
#line 7744 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1681:
#line 7752 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1682:
#line 7752 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1683:
#line 7758 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1684:
#line 7758 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1685:
#line 7765 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1686:
#line 7765 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1687:
#line 7771 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1688:
#line 7771 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1689:
#line 7779 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1690:
#line 7780 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1691:
#line 7781 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1692:
#line 7784 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1693:
#line 7784 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1695:
#line 7788 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1696:
#line 7789 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1697:
#line 7800 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1698:
#line 7803 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1699:
#line 7809 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1700:
#line 7814 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1701:
#line 7822 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1702:
#line 7834 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1703:
#line 7835 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1704:
#line 7838 "fgl.yacc"
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

  case 1705:
#line 7853 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1706:
#line 7864 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1707:
#line 7867 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1708:
#line 7875 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1709:
#line 7884 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1710:
#line 7887 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1711:
#line 7891 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1712:
#line 7894 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1713:
#line 7895 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1715:
#line 7904 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1716:
#line 7905 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1717:
#line 7914 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1718:
#line 7923 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1719:
#line 7928 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1720:
#line 7929 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1721:
#line 7930 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1722:
#line 7931 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1723:
#line 7938 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1724:
#line 7941 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1725:
#line 7947 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1726:
#line 7950 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1727:
#line 7960 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1728:
#line 7969 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1729:
#line 7972 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1730:
#line 7975 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1731:
#line 7981 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1732:
#line 7987 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1733:
#line 7990 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1734:
#line 7991 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1735:
#line 7992 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1736:
#line 7993 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1737:
#line 7994 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1738:
#line 7997 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1739:
#line 8004 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1740:
#line 8006 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1741:
#line 8008 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1742:
#line 8010 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1743:
#line 8012 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1744:
#line 8013 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1745:
#line 8014 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1746:
#line 8015 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1747:
#line 8016 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1748:
#line 8017 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1749:
#line 8018 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1750:
#line 8020 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1751:
#line 8022 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1752:
#line 8024 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1753:
#line 8026 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1754:
#line 8028 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1755:
#line 8030 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1756:
#line 8032 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1757:
#line 8033 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1758:
#line 8035 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1759:
#line 8039 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1760:
#line 8040 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1762:
#line 8050 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1763:
#line 8058 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1764:
#line 8062 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1765:
#line 8069 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1766:
#line 8069 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1768:
#line 8073 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1769:
#line 8078 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1770:
#line 8078 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1772:
#line 8082 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1773:
#line 8086 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1776:
#line 8095 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1777:
#line 8095 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1782:
#line 8114 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1783:
#line 8115 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1786:
#line 8123 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1787:
#line 8129 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1790:
#line 8148 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1791:
#line 8149 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1792:
#line 8150 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1793:
#line 8151 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1794:
#line 8152 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1795:
#line 8153 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1796:
#line 8157 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1797:
#line 8158 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1798:
#line 8159 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1799:
#line 8163 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1800:
#line 8167 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1802:
#line 8176 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1804:
#line 8181 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1805:
#line 8182 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2122:
#line 8507 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2123:
#line 8507 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2124:
#line 8514 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2125:
#line 8514 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2126:
#line 8602 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2127:
#line 8606 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2128:
#line 8608 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2129:
#line 8615 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2130:
#line 8619 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2131:
#line 8625 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2132:
#line 8633 "fgl.yacc"
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

  case 2133:
#line 8643 "fgl.yacc"
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

  case 2134:
#line 8653 "fgl.yacc"
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

  case 2135:
#line 8665 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2136:
#line 8668 "fgl.yacc"
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

  case 2137:
#line 8687 "fgl.yacc"
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

  case 2138:
#line 8713 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2139:
#line 8716 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2141:
#line 8725 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2142:
#line 8730 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2143:
#line 8733 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2144:
#line 8741 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2145:
#line 8749 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2146:
#line 8762 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2147:
#line 8765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2148:
#line 8773 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2149:
#line 8776 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2150:
#line 8779 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2151:
#line 8787 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2152:
#line 8791 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2153:
#line 8794 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2154:
#line 8797 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2155:
#line 8800 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2156:
#line 8804 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2157:
#line 8805 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2158:
#line 8806 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2159:
#line 8807 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2160:
#line 8808 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2161:
#line 8814 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2162:
#line 8815 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2163:
#line 8816 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2164:
#line 8817 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2165:
#line 8818 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2166:
#line 8819 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2167:
#line 8820 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2168:
#line 8821 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2169:
#line 8822 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2170:
#line 8823 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2171:
#line 8824 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2172:
#line 8825 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2173:
#line 8826 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2174:
#line 8827 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2175:
#line 8831 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2176:
#line 8837 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2177:
#line 8838 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2178:
#line 8846 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2179:
#line 8848 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2181:
#line 8854 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2182:
#line 8858 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2183:
#line 8862 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2184:
#line 8878 "fgl.yacc"
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

  case 2185:
#line 8897 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2186:
#line 8899 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2187:
#line 8905 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2188:
#line 8906 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2189:
#line 8907 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2190:
#line 8908 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2194:
#line 8926 "fgl.yacc"
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

  case 2195:
#line 8952 "fgl.yacc"
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

  case 2196:
#line 9007 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2197:
#line 9021 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2198:
#line 9024 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2199:
#line 9028 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2200:
#line 9043 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2201:
#line 9043 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2202:
#line 9049 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2203:
#line 9050 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2204:
#line 9053 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2205:
#line 9054 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2206:
#line 9055 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2207:
#line 9056 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2208:
#line 9057 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2209:
#line 9058 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2210:
#line 9059 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2211:
#line 9070 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2212:
#line 9074 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2213:
#line 9078 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2214:
#line 9082 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2215:
#line 9087 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2216:
#line 9091 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2217:
#line 9096 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2219:
#line 9104 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2221:
#line 9110 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2222:
#line 9116 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2223:
#line 9120 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2228:
#line 9138 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2229:
#line 9145 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2230:
#line 9155 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2231:
#line 9155 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18789 "y.tab.c"

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


#line 9254 "fgl.yacc"

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



