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
     NAME = 1723,
     UMINUS = 1724,
     COMMA = 1625,
     KW_OR = 1665,
     KW_AND = 1620,
     KW_USING = 1557,
     NOT = 1640,
     MATCHES = 1438,
     POWER = 1543,
     LESS_THAN = 1539,
     GREATER_THAN = 1455,
     EQUAL = 1615,
     GREATER_THAN_EQ = 1357,
     LESS_THAN_EQ = 1414,
     NOT_EQUAL = 1486,
     PLUS = 1651,
     MINUS = 1638,
     MULTIPLY = 1544,
     DIVIDE = 1571,
     MOD = 1639,
     COMMAND = 1421,
     NUMBER_VALUE = 1725,
     CHAR_VALUE = 1726,
     INT_VALUE = 1727,
     NAMED_GEN = 1728,
     CLINE = 1729,
     SQLLINE = 1730,
     KW_CSTART = 1731,
     KW_CEND = 1732,
     USER_DTYPE = 1733,
     SQL_TEXT = 1734,
     KW_WHENEVER_SET = 1735,
     COMMENT = 1736,
     MEMBER_FUNCTION = 1000,
     MISC_INFX_SQL = 1001,
     AS_CONVERTABLE = 1002,
     FREE_REPORT = 1003,
     CONVERTING_TO_MANY = 1004,
     CONVERTING_TO = 1005,
     CONVERT_REPORT = 1006,
     DATETIME_VALUE = 1007,
     INTERVAL_VALUE = 1008,
     IN_LINE_MODE = 1009,
     IN_FORM_MODE = 1010,
     FGL_SIZEOF = 1011,
     IMPORT_PACKAGE = 1012,
     DYNAMIC_ARRAY = 1013,
     RESIZE_ARRAY = 1014,
     ALLOCATE_ARRAY = 1015,
     DEALLOCATE_ARRAY = 1016,
     AFTER_INSERT_DELETE = 1017,
     BEFORE_INSERT_DELETE = 1018,
     BEFORE_INSERT = 1019,
     CONCAT_PIPES = 1020,
     BEFORE_DELETE = 1021,
     DROP_TRIGGER = 1022,
     AFTER_INSERT = 1023,
     AFTER_DELETE = 1024,
     EXECUTE_IMMEDIATE = 1025,
     DELETE_ROW_EQUAL_TRUE = 1026,
     INSERT_ROW_EQUAL_TRUE = 1027,
     DELETE_ROW_EQUAL_FALSE = 1028,
     INSERT_ROW_EQUAL_FALSE = 1029,
     CURRENT_ROW_DISPLAY_EQUAL = 1030,
     MAXCOUNT = 1031,
     ALTER_TABLE = 1032,
     ALTER_INDEX = 1033,
     NEXT_SIZE = 1034,
     DISPLAY_ATTR_FORM = 1035,
     DISPLAY_ATTR_WINDOW = 1036,
     INPUT_ATTR_FORM = 1037,
     INPUT_ATTR_WINDOW = 1038,
     WHENEVER_ERROR_CONTINUE = 1039,
     WHENEVER_ANY_ERROR_CONTINUE = 1040,
     WHENEVER_WARNING_CONTINUE = 1041,
     WHENEVER_SQLSUCCESS_CONTINUE = 1042,
     WHENEVER_SQLWARNING_CONTINUE = 1043,
     WHENEVER_NOT_FOUND_CONTINUE = 1044,
     WHENEVER_SQLERROR_CONTINUE = 1045,
     WHENEVER_SUCCESS_CONTINUE = 1046,
     WHENEVER_ERROR_GOTO = 1047,
     WHENEVER_ANY_ERROR_GOTO = 1048,
     WHENEVER_WARNING_GOTO = 1049,
     WHENEVER_SQLSUCCESS_GOTO = 1050,
     WHENEVER_SQLWARNING_GOTO = 1051,
     WHENEVER_NOT_FOUND_GOTO = 1052,
     WHENEVER_SQLERROR_GOTO = 1053,
     WHENEVER_SUCCESS_GOTO = 1054,
     WHENEVER_ERROR_CALL = 1055,
     WHENEVER_ANY_ERROR_CALL = 1056,
     WHENEVER_WARNING_CALL = 1057,
     WHENEVER_SQLSUCCESS_CALL = 1058,
     WHENEVER_SQLWARNING_CALL = 1059,
     WHENEVER_NOT_FOUND_CALL = 1060,
     WHENEVER_SQLERROR_CALL = 1061,
     WHENEVER_SUCCESS_CALL = 1062,
     WHENEVER_ERROR_STOP = 1063,
     WHENEVER_ANY_ERROR_STOP = 1064,
     WHENEVER_WARNING_STOP = 1065,
     WHENEVER_SQLSUCCESS_STOP = 1066,
     WHENEVER_SQLWARNING_STOP = 1067,
     WHENEVER_NOT_FOUND_STOP = 1068,
     WHENEVER_SQLERROR_STOP = 1069,
     WHENEVER_SUCCESS_STOP = 1070,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1071,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1072,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1073,
     XSET_MULTIPLY_EQUAL = 1074,
     XSET_OPEN_BRACKET = 1075,
     NEWFORMATSHARED = 1076,
     CREATE_DATABASE = 1077,
     DROP_DATABASE = 1078,
     IMPORT_LEGACY_FUNCTION = 1079,
     ADD_CONSTRAINT = 1080,
     DROP_CONSTRAINT = 1081,
     DROP_SYNONYM = 1082,
     CONSTRAINT = 1083,
     AS_STATIC = 1084,
     NOT_FIELD_TOUCHED = 1085,
     LOCAL_FUNCTION = 1086,
     EVERY_ROW = 1087,
     ELIF = 1088,
     DOUBLE_PRECISION = 1089,
     COUNT_MULTIPLY = 1090,
     WAIT_FOR_KEY = 1091,
     AT_TERMINATION_CALL = 1092,
     TERMINATE_REPORT = 1093,
     TO_MAIN_CAPTION = 1094,
     CLEARSTAT = 1095,
     TO_MENUITEM = 1096,
     ID_TO_INT = 1097,
     TO_STATUSBOX = 1098,
     ASCII_HEIGHT_ALL = 1099,
     ASCII_WIDTH_ALL = 1100,
     IMPORT_DATATYPE = 1101,
     PAGE_TRAILER_SIZE = 1102,
     PAGE_HEADER_SIZE = 1103,
     FIRST_PAGE_HEADER_SIZE = 1104,
     BYTES_USE_AS_IMAGE = 1105,
     BYTES_USE_AS_ASCII = 1106,
     KWUP_BY = 1107,
     KWDOWN_BY = 1108,
     CLOSE_STATUSBOX = 1109,
     MODIFY_NEXT_SIZE = 1110,
     LOCK_MODE_PAGE = 1111,
     LOCK_MODE_ROW = 1112,
     TO_PIPE = 1113,
     TO_SCREEN = 1114,
     TO_PRINTER = 1115,
     STATUSBOX = 1116,
     FORMHANDLER_INPUT = 1117,
     UNITS_YEAR = 1118,
     UNITS_MONTH = 1119,
     UNITS_DAY = 1120,
     UNITS_HOUR = 1121,
     UNITS_MINUTE = 1122,
     UNITS_SECOND = 1123,
     NO_NEW_LINES = 1124,
     FIELDTOWIDGET = 1125,
     WITH_HOLD = 1126,
     SHOW_MENU = 1127,
     TO_CLUSTER = 1128,
     TO_NOT_CLUSTER = 1129,
     CWIS = 1130,
     CREATE_IDX = 1131,
     FORM_IS_COMPILED = 1132,
     PDF_REPORT = 1133,
     IMPORT_FUNCTION = 1134,
     PROMPT_MANY = 1135,
     POINTS = 1136,
     MM = 1137,
     INCHES = 1138,
     PREPEND = 1139,
     MEMBER_OF = 1140,
     APPEND = 1141,
     TEMPLATE = 1142,
     END_TEMPLATE = 1143,
     SQLSICS = 1144,
     CREATE_SCHEMA = 1145,
     SQLSIRR = 1146,
     UPDATESTATS_T = 1147,
     SQLSICR = 1148,
     WHENEVER_SQLSUCCESS = 1149,
     WHENEVER_SQLWARNING = 1150,
     WHENEVER_ANY_ERROR = 1151,
     WHENEVER_NOT_FOUND = 1152,
     WHENEVER_SQLERROR = 1153,
     WHENEVER_SUCCESS = 1154,
     WHENEVER_ERROR = 1155,
     START_EXTERN = 1156,
     CONTINUE_CONSTRUCT = 1157,
     FOUNCONSTR = 1158,
     SQLSIDR = 1159,
     CREATE_TEMP_TABLE = 1160,
     CURRENT_WINDOW_IS = 1161,
     FIRST_PAGE_HEADER = 1162,
     ORDER_EXTERNAL_BY = 1163,
     SCROLL_CURSOR_FOR = 1164,
     SCROLL_CURSOR = 1165,
     SQL_INTERRUPT_OFF = 1166,
     STOP_ALL_EXTERNAL = 1167,
     WITH_CHECK_OPTION = 1168,
     WITH_GRANT_OPTION = 1169,
     SQLSLMNW = 1170,
     ADDCONSTUNIQ = 1171,
     CONTINUE_DISPLAY = 1172,
     CONTINUE_FOREACH = 1173,
     OUTPUT_TO_REPORT = 1174,
     SQL_INTERRUPT_ON = 1175,
     WHERE_CURRENT_OF = 1176,
     WITHOUT_DEFAULTS = 1177,
     FOCONSTR = 1178,
     SCALED_BY = 1179,
     CONTINUE_PROMPT = 1180,
     PDF_FUNCTION = 1181,
     DEFER_INTERRUPT = 1182,
     DISPLAY_BY_NAME = 1183,
     NOT_NULL_UNIQUE = 1184,
     SKIP_TO_TOP = 1185,
     TOP_OF_PAGE = 1186,
     SKIP_TO = 1187,
     SKIP_BY = 1188,
     WITHOUT_WAITING = 1189,
     BEFCONSTRUCT = 1190,
     SQLSLMW = 1191,
     AFTCONSTRUCT = 1192,
     ALL_PRIVILEGES = 1193,
     CLOSE_DATABASE = 1194,
     CONTINUE_INPUT = 1195,
     CONTINUE_WHILE = 1196,
     CREATE_SYNONYM = 1197,
     DROP_TABLE = 1198,
     EXIT_CONSTRUCT = 1199,
     INEXCLUSIVE = 1200,
     REPORT_TO_PRINTER = 1201,
     REPORT_TO_PIPE = 1202,
     RETURN = 1203,
     SET_SESSION_TO = 1204,
     UPDATESTATS = 1205,
     WITHOUT_HEAD = 1206,
     CLEARSCR = 1207,
     WITH_B_LOG = 1208,
     AUTHORIZATION = 1209,
     BOTTOM_MARGIN = 1210,
     CLOSE_SESSION = 1211,
     CONTINUE_CASE = 1212,
     CONTINUE_MENU = 1213,
     DISPLAY_ARRAY = 1214,
     END_SQL = 1215,
     DOLLAR = 1216,
     END_CONSTRUCT = 1217,
     FIELD_TOUCHED = 1218,
     FINISH_REPORT = 1219,
     INFACC = 1220,
     INPUT_NO_WRAP = 1221,
     SETPMOFF = 1222,
     UNCONSTRAINED = 1223,
     PAGE_TRAILER = 1224,
     SETPMON = 1225,
     BEFGROUP = 1226,
     CLOSE_WINDOW = 1227,
     COMMENT_LINE = 1228,
     CONTINUE_FOR = 1229,
     CREATE_DB = 1230,
     CREATE_TABLE = 1231,
     DEFAULT_NULL = 1232,
     DEFAULT_TODAY = 1233,
     DEFAULT_USER = 1234,
     DELETE_USING = 1235,
     DISPLAY_FORM = 1236,
     END_FUNCTION = 1237,
     EXIT_DISPLAY = 1238,
     EXIT_FOREACH = 1239,
     EXIT_PROGRAM = 1240,
     INFCOLS = 1241,
     ON_EVERY_ROW = 1242,
     OPEN_SESSION = 1243,
     RIGHT_MARGIN = 1244,
     SELECT_USING = 1245,
     START_REPORT = 1246,
     UNLOCK_TABLE = 1247,
     UPDATE_USING = 1248,
     ACL_BUILTIN = 1249,
     AFTGROUP = 1250,
     INFIDX = 1251,
     INFSTAT = 1252,
     LEFT_MARGIN = 1253,
     PAGE_HEADER = 1254,
     ROLLBACK_W = 1255,
     SET_SESSION = 1256,
     SQLSEOFF = 1257,
     WITH_A_LOG = 1258,
     BEFDISP = 1259,
     BEFORE_MENU = 1260,
     CREATE_VIEW = 1261,
     DEFINE_TYPE = 1262,
     DELETE_FROM = 1263,
     END_DISPLAY = 1264,
     END_REPORT = 1265,
     END_FOREACH = 1266,
     END_FOR = 1267,
     END_GLOBALS = 1268,
     EXIT_PROMPT = 1269,
     EXTENT_SIZE = 1270,
     FOREIGN_KEY = 1271,
     HIDE_OPTION = 1272,
     HIDE_WINDOW = 1273,
     INSERT_INTO = 1274,
     IS_NOT_NULL = 1275,
     MOVE_WINDOW = 1276,
     NEXT_OPTION = 1277,
     NOT_MATCHES = 1278,
     ON_LAST_ROW = 1279,
     OPEN_WINDOW = 1280,
     OPEN_STATUSBOX = 1281,
     PAGE_LENGTH = 1282,
     PAGE_WIDTH = 1283,
     PRIMARY_KEY = 1284,
     PROMPT_LINE = 1285,
     RECORD_LIKE = 1286,
     ROLLFORWARD = 1287,
     SHOW_OPTION = 1288,
     SHOW_WINDOW = 1289,
     SQLSEON = 1290,
     TO_DATABASE = 1291,
     USE_SESSION = 1292,
     WITH_NO_LOG = 1293,
     AFTDISP = 1294,
     BEFFIELD = 1295,
     INSHARE = 1296,
     UNLOCKTAB = 1297,
     AFTFIELD = 1298,
     ATTRIBUTES = 1299,
     BEFINP = 1300,
     BEGIN_WORK = 1301,
     CLEARWIN = 1302,
     CLOSE_FORM = 1303,
     DEFER_QUIT = 1304,
     DESCENDING = 1305,
     DROP_INDEX = 1306,
     END_PROMPT = 1307,
     END_RECORD = 1308,
     ERROR_LINE = 1309,
     EXIT_INPUT = 1310,
     EXIT_WHILE = 1311,
     FOR_UPDATE_OF = 1312,
     FOR_UPDATE = 1313,
     GET_FLDBUF = 1314,
     INITIALIZE = 1315,
     INPUT_WRAP = 1316,
     LOCK_TABLE = 1317,
     MSG_LINE = 1318,
     NOT_EXISTS = 1319,
     ON_ANY_KEY = 1320,
     REFERENCES = 1321,
     RENCOL = 1322,
     SET_CURSOR = 1323,
     SMALLFLOAT = 1324,
     SQLSUCCESS = 1325,
     TOP_MARGIN = 1326,
     WITH_ARRAY = 1327,
     ACCEPTKEY = 1328,
     ACCEPT = 1329,
     AFTINP = 1330,
     CLEARFORMTODEFAULTS = 1331,
     CLEARFORM = 1332,
     CLEAR_X_FORM = 1333,
     COMMIT_W = 1334,
     NEXTPAGE = 1335,
     PREVPAGE = 1336,
     CTRL_KEY = 1337,
     INFTABS = 1338,
     NEXTFIELD = 1339,
     NEXTFORM = 1340,
     RENTAB = 1341,
     ASCENDING = 1342,
     ASSOCIATE = 1343,
     CHAR = 1344,
     NCHAR = 1345,
     NVARCHAR = 1346,
     CONSTRUCT = 1347,
     DELIMITER = 1348,
     DOWNSHIFT = 1349,
     DROP_VIEW = 1350,
     END_INPUT = 1351,
     END_WHILE = 1352,
     EXCLUSIVE = 1353,
     EXIT_CASE = 1354,
     EXIT_MENU = 1355,
     FORM_LINE = 1356,
     INTERRUPT = 1358,
     INTO_TEMP = 1359,
     INVISIBLE = 1360,
     IN_MEMORY = 1361,
     LINKED_TO = 1362,
     LOAD_FROM = 1363,
     LOCKTAB = 1364,
     MENU_LINE = 1365,
     OPEN_FORM = 1366,
     OTHERWISE = 1367,
     PRECISION = 1368,
     PRIOR = 1369,
     PROCEDURE = 1370,
     REPORT_TO = 1371,
     RETURNING = 1372,
     UNDERLINE = 1373,
     UNLOAD_TO = 1374,
     BEFROW = 1375,
     UNLOAD_T = 1376,
     VARIABLE = 1377,
     ABSOLUTE = 1378,
     AFTROW = 1379,
     BUFFERED = 1380,
     CONSTANT = 1381,
     CONST = 1382,
     DATABASE = 1383,
     DATETIME = 1384,
     DEFAULTS = 1385,
     DISTINCT = 1386,
     END_CASE = 1387,
     END_MAIN = 1388,
     END_MENU = 1389,
     END_TYPE = 1390,
     EXIT_FOR = 1391,
     EXTERNAL = 1392,
     FRACTION = 1393,
     FUNCTION = 1394,
     GROUP_BY = 1395,
     INTERVAL = 1396,
     KWMESSAGE = 1397,
     NOT_LIKE = 1398,
     NOT_ILIKE = 1399,
     NOT_NULL = 1400,
     PASSWORD = 1401,
     PREVIOUS = 1402,
     READONLY = 1403,
     REGISTER = 1404,
     RELATIVE = 1405,
     RESOURCE = 1406,
     SMALLINT = 1407,
     VALIDATE = 1408,
     WITH_LOG = 1409,
     WORDWRAP = 1410,
     BY_NAME = 1411,
     IN_FILE = 1412,
     IS_NULL = 1413,
     AVERAGE = 1415,
     BETWEEN = 1416,
     CAPTION = 1417,
     CLIPPED = 1418,
     CLOSE_BRACKET = 1419,
     COLUMNS = 1420,
     CONNECT = 1422,
     CURRENT = 1423,
     DBYNAME = 1424,
     DECIMAL = 1425,
     DECLARE = 1426,
     DEFAULT = 1427,
     DISPLAY = 1428,
     ENDCODE = 1429,
     EXECUTE = 1430,
     FOREACH = 1431,
     FOREIGN = 1432,
     GLOBALS = 1433,
     INFIELD = 1434,
     INTEGER = 1435,
     KWWINDOW = 1436,
     MAGENTA = 1437,
     OPTIONS = 1439,
     PERCENT = 1440,
     PREPARE = 1441,
     PROGRAM = 1442,
     RECOVER = 1443,
     REVERSE = 1444,
     SECTION = 1445,
     SESSION = 1446,
     SYNONYM = 1447,
     THRU = 1448,
     TRAILER = 1449,
     UPSHIFT = 1450,
     VARCHAR = 1451,
     WAITING = 1452,
     CLOSE_SHEV = 1453,
     CLOSE_SQUARE = 1454,
     KW_FALSE = 1456,
     NOT_IN = 1457,
     ONKEY = 1458,
     OPEN_BRACKET = 1459,
     BORDER = 1460,
     BOTTOM = 1461,
     COLUMN = 1462,
     COMMIT = 1463,
     CREATE = 1464,
     CURSOR = 1465,
     DEFINE = 1466,
     DELETE = 1467,
     DOUBLE = 1468,
     END_IF = 1469,
     ESCAPE = 1470,
     EXISTS = 1471,
     EXTEND = 1472,
     EXTENT = 1473,
     FINISH = 1474,
     FORMAT = 1475,
     HAVING = 1476,
     HEADER = 1477,
     INSERT = 1478,
     LOCATE = 1479,
     MARGIN = 1480,
     MEMORY = 1481,
     MINUTE = 1482,
     MODIFY = 1483,
     NORMAL = 1484,
     EQUAL_EQUAL = 1485,
     OPEN_SHEV = 1487,
     OPEN_SQUARE = 1488,
     OPTION = 1489,
     OUTPUT = 1490,
     PROMPT = 1491,
     PUBLIC = 1492,
     RECORD = 1493,
     REPORT = 1494,
     REVOKE = 1495,
     SCHEMA = 1496,
     SCROLL_USING = 1497,
     SCROLL = 1498,
     SECOND = 1499,
     SELECT = 1500,
     SERIAL = 1501,
     SHARED = 1502,
     SPACES = 1503,
     UNIQUE = 1504,
     UNLOCK = 1505,
     UPDATE = 1506,
     VALUES = 1507,
     YELLOW = 1508,
     AFTER = 1509,
     KWLINE = 1510,
     KW_NULL = 1511,
     KW_TRUE = 1512,
     SINGLE_KEY = 1513,
     ALTER = 1514,
     ARRAY = 1515,
     ASCII = 1516,
     AUDIT = 1517,
     BLACK = 1518,
     BLINK = 1519,
     CHECK = 1520,
     CLEAR = 1521,
     CLOSE = 1522,
     CODE_C = 1523,
     COUNT = 1524,
     DEFER = 1525,
     ERROR = 1526,
     EVERY = 1527,
     FETCH = 1528,
     FIRST = 1529,
     FLOAT = 1530,
     FLUSH = 1531,
     FOUND = 1532,
     GRANT = 1533,
     GREEN = 1534,
     GROUP = 1535,
     INDEX = 1536,
     KWFORM = 1537,
     LABEL = 1538,
     LOCAL = 1540,
     MONEY = 1541,
     MONTH = 1542,
     ORDER = 1545,
     OUTER = 1546,
     PAUSE = 1547,
     PRINT_IMAGE = 1548,
     PRINT_FILE = 1549,
     PRINT = 1550,
     RIGHT = 1551,
     DOUBLE_COLON = 1552,
     SEMICOLON = 1553,
     SLEEP = 1554,
     TUPLE = 1555,
     UNION = 1556,
     WHERE = 1558,
     WHILE = 1559,
     WHITE = 1560,
     CCODE = 1561,
     ANSI = 1562,
     BLUE = 1563,
     BOLD = 1564,
     BYTE = 1565,
     FCALL = 1566,
     CASE = 1567,
     CYAN = 1568,
     DATE = 1569,
     DESC = 1570,
     KWDOWN = 1572,
     TAB = 1573,
     DROP = 1574,
     ELSE = 1575,
     EXEC = 1576,
     EXIT = 1577,
     FREE = 1578,
     FROM = 1579,
     GOTO = 1580,
     HELP_FILE = 1581,
     LANG_FILE = 1582,
     HELP = 1583,
     HIDE = 1584,
     HOUR = 1585,
     INTO = 1586,
     LAST = 1587,
     LEFT = 1588,
     LIKE = 1589,
     MAIN = 1590,
     MENU = 1591,
     MODE = 1592,
     NEED = 1593,
     NEXT = 1594,
     NOCR = 1595,
     OPEN = 1596,
     QUIT = 1597,
     REAL = 1598,
     ROWS = 1599,
     SHOW = 1600,
     SIZE = 1601,
     SKIP = 1602,
     SOME = 1603,
     STEP = 1604,
     STOP = 1605,
     TEMP = 1606,
     TEXT = 1607,
     THEN = 1608,
     USER = 1609,
     WAIT = 1610,
     WHEN = 1611,
     WITH = 1612,
     WORK = 1613,
     YEAR = 1614,
     KW_IS = 1616,
     XSET = 1617,
     ADD = 1618,
     ALL = 1619,
     ANY = 1621,
     ASC = 1622,
     AVG = 1623,
     COLON = 1624,
     DAY = 1626,
     DBA = 1627,
     DEC = 1628,
     DIM = 1629,
     FKEY = 1630,
     FOR = 1631,
     KEY = 1632,
     KWNO = 1633,
     LET = 1634,
     LOG = 1635,
     XMAX = 1636,
     XMIN = 1637,
     PAD = 1641,
     PUT = 1642,
     RED = 1643,
     ROW = 1644,
     RUN = 1645,
     SQL = 1646,
     SUM = 1647,
     TOP = 1648,
     USE = 1649,
     ATSIGN = 1650,
     AS_TIFF = 1652,
     AS_GIF = 1653,
     AS_PNG = 1654,
     AS_JPEG = 1655,
     AS = 1656,
     AT = 1657,
     BY = 1658,
     DOT = 1659,
     GO = 1660,
     IF = 1661,
     IN = 1662,
     OF = 1663,
     ON = 1664,
     TO = 1666,
     KWUP = 1667,
     FONT_NAME = 1668,
     FONT_SIZE = 1669,
     PAPER_SIZE_IS_LETTER = 1670,
     PAPER_SIZE_IS_LEGAL = 1671,
     PAPER_SIZE_IS_A5 = 1672,
     PAPER_SIZE_IS_A4 = 1673,
     PAPER_SIZE_IS_LETTER_L = 1674,
     PAPER_SIZE_IS_LEGAL_L = 1675,
     PAPER_SIZE_IS_A5_L = 1676,
     PAPER_SIZE_IS_A4_L = 1677,
     FORMHANDLER = 1678,
     END_FORMHANDLER = 1679,
     BEFORE_EVENT = 1680,
     BEFORE_OPEN_FORM = 1681,
     AFTER_EVENT = 1682,
     BEFORE_CLOSE_FORM = 1683,
     BEFORE_ANY = 1684,
     AFTER_ANY = 1685,
     MENUHANDLER = 1686,
     END_MENUHANDLER = 1687,
     BEFORE_SHOW_MENU = 1688,
     DISABLE_PROGRAM = 1689,
     DISABLE_ALL = 1690,
     BUTTONS = 1691,
     CHECK_MENUITEM = 1692,
     DISABLE_FORM = 1693,
     DISABLE_MENUITEMS = 1694,
     DISABLE = 1695,
     ENABLE_FORM = 1696,
     ENABLE_MENUITEMS = 1697,
     ENABLE = 1698,
     KWFIELD = 1699,
     ICON = 1700,
     MESSAGEBOX = 1701,
     TO_DEFAULTS = 1702,
     UNCHECK_MENUITEM = 1703,
     BEFORE = 1704,
     INPUT = 1705,
     END = 1706,
     INT_TO_ID = 1707,
     TIMEOUT = 1708,
     OFF = 1709,
     WITH_1_DIMENSION = 1710,
     WITH_2_DIMENSION = 1711,
     WITH_3_DIMENSION = 1712,
     TILDE = 1713,
     ILIKE = 1714,
     FGL_ISDYNARR_ALLOCATED = 1715,
     FGL_DYNARR_EXTENTSIZE = 1716,
     FILLFACTOR = 1717,
     END_CLASS = 1718,
     KW_CLASS = 1719,
     EXTENDS = 1720,
     PIPE = 1721
   };
#endif
#define NAME 1723
#define UMINUS 1724
#define COMMA 1625
#define KW_OR 1665
#define KW_AND 1620
#define KW_USING 1557
#define NOT 1640
#define MATCHES 1438
#define POWER 1543
#define LESS_THAN 1539
#define GREATER_THAN 1455
#define EQUAL 1615
#define GREATER_THAN_EQ 1357
#define LESS_THAN_EQ 1414
#define NOT_EQUAL 1486
#define PLUS 1651
#define MINUS 1638
#define MULTIPLY 1544
#define DIVIDE 1571
#define MOD 1639
#define COMMAND 1421
#define NUMBER_VALUE 1725
#define CHAR_VALUE 1726
#define INT_VALUE 1727
#define NAMED_GEN 1728
#define CLINE 1729
#define SQLLINE 1730
#define KW_CSTART 1731
#define KW_CEND 1732
#define USER_DTYPE 1733
#define SQL_TEXT 1734
#define KW_WHENEVER_SET 1735
#define COMMENT 1736
#define MEMBER_FUNCTION 1000
#define MISC_INFX_SQL 1001
#define AS_CONVERTABLE 1002
#define FREE_REPORT 1003
#define CONVERTING_TO_MANY 1004
#define CONVERTING_TO 1005
#define CONVERT_REPORT 1006
#define DATETIME_VALUE 1007
#define INTERVAL_VALUE 1008
#define IN_LINE_MODE 1009
#define IN_FORM_MODE 1010
#define FGL_SIZEOF 1011
#define IMPORT_PACKAGE 1012
#define DYNAMIC_ARRAY 1013
#define RESIZE_ARRAY 1014
#define ALLOCATE_ARRAY 1015
#define DEALLOCATE_ARRAY 1016
#define AFTER_INSERT_DELETE 1017
#define BEFORE_INSERT_DELETE 1018
#define BEFORE_INSERT 1019
#define CONCAT_PIPES 1020
#define BEFORE_DELETE 1021
#define DROP_TRIGGER 1022
#define AFTER_INSERT 1023
#define AFTER_DELETE 1024
#define EXECUTE_IMMEDIATE 1025
#define DELETE_ROW_EQUAL_TRUE 1026
#define INSERT_ROW_EQUAL_TRUE 1027
#define DELETE_ROW_EQUAL_FALSE 1028
#define INSERT_ROW_EQUAL_FALSE 1029
#define CURRENT_ROW_DISPLAY_EQUAL 1030
#define MAXCOUNT 1031
#define ALTER_TABLE 1032
#define ALTER_INDEX 1033
#define NEXT_SIZE 1034
#define DISPLAY_ATTR_FORM 1035
#define DISPLAY_ATTR_WINDOW 1036
#define INPUT_ATTR_FORM 1037
#define INPUT_ATTR_WINDOW 1038
#define WHENEVER_ERROR_CONTINUE 1039
#define WHENEVER_ANY_ERROR_CONTINUE 1040
#define WHENEVER_WARNING_CONTINUE 1041
#define WHENEVER_SQLSUCCESS_CONTINUE 1042
#define WHENEVER_SQLWARNING_CONTINUE 1043
#define WHENEVER_NOT_FOUND_CONTINUE 1044
#define WHENEVER_SQLERROR_CONTINUE 1045
#define WHENEVER_SUCCESS_CONTINUE 1046
#define WHENEVER_ERROR_GOTO 1047
#define WHENEVER_ANY_ERROR_GOTO 1048
#define WHENEVER_WARNING_GOTO 1049
#define WHENEVER_SQLSUCCESS_GOTO 1050
#define WHENEVER_SQLWARNING_GOTO 1051
#define WHENEVER_NOT_FOUND_GOTO 1052
#define WHENEVER_SQLERROR_GOTO 1053
#define WHENEVER_SUCCESS_GOTO 1054
#define WHENEVER_ERROR_CALL 1055
#define WHENEVER_ANY_ERROR_CALL 1056
#define WHENEVER_WARNING_CALL 1057
#define WHENEVER_SQLSUCCESS_CALL 1058
#define WHENEVER_SQLWARNING_CALL 1059
#define WHENEVER_NOT_FOUND_CALL 1060
#define WHENEVER_SQLERROR_CALL 1061
#define WHENEVER_SUCCESS_CALL 1062
#define WHENEVER_ERROR_STOP 1063
#define WHENEVER_ANY_ERROR_STOP 1064
#define WHENEVER_WARNING_STOP 1065
#define WHENEVER_SQLSUCCESS_STOP 1066
#define WHENEVER_SQLWARNING_STOP 1067
#define WHENEVER_NOT_FOUND_STOP 1068
#define WHENEVER_SQLERROR_STOP 1069
#define WHENEVER_SUCCESS_STOP 1070
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1071
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1072
#define XSET_ident_DOT_MULTIPLY_EQUAL 1073
#define XSET_MULTIPLY_EQUAL 1074
#define XSET_OPEN_BRACKET 1075
#define NEWFORMATSHARED 1076
#define CREATE_DATABASE 1077
#define DROP_DATABASE 1078
#define IMPORT_LEGACY_FUNCTION 1079
#define ADD_CONSTRAINT 1080
#define DROP_CONSTRAINT 1081
#define DROP_SYNONYM 1082
#define CONSTRAINT 1083
#define AS_STATIC 1084
#define NOT_FIELD_TOUCHED 1085
#define LOCAL_FUNCTION 1086
#define EVERY_ROW 1087
#define ELIF 1088
#define DOUBLE_PRECISION 1089
#define COUNT_MULTIPLY 1090
#define WAIT_FOR_KEY 1091
#define AT_TERMINATION_CALL 1092
#define TERMINATE_REPORT 1093
#define TO_MAIN_CAPTION 1094
#define CLEARSTAT 1095
#define TO_MENUITEM 1096
#define ID_TO_INT 1097
#define TO_STATUSBOX 1098
#define ASCII_HEIGHT_ALL 1099
#define ASCII_WIDTH_ALL 1100
#define IMPORT_DATATYPE 1101
#define PAGE_TRAILER_SIZE 1102
#define PAGE_HEADER_SIZE 1103
#define FIRST_PAGE_HEADER_SIZE 1104
#define BYTES_USE_AS_IMAGE 1105
#define BYTES_USE_AS_ASCII 1106
#define KWUP_BY 1107
#define KWDOWN_BY 1108
#define CLOSE_STATUSBOX 1109
#define MODIFY_NEXT_SIZE 1110
#define LOCK_MODE_PAGE 1111
#define LOCK_MODE_ROW 1112
#define TO_PIPE 1113
#define TO_SCREEN 1114
#define TO_PRINTER 1115
#define STATUSBOX 1116
#define FORMHANDLER_INPUT 1117
#define UNITS_YEAR 1118
#define UNITS_MONTH 1119
#define UNITS_DAY 1120
#define UNITS_HOUR 1121
#define UNITS_MINUTE 1122
#define UNITS_SECOND 1123
#define NO_NEW_LINES 1124
#define FIELDTOWIDGET 1125
#define WITH_HOLD 1126
#define SHOW_MENU 1127
#define TO_CLUSTER 1128
#define TO_NOT_CLUSTER 1129
#define CWIS 1130
#define CREATE_IDX 1131
#define FORM_IS_COMPILED 1132
#define PDF_REPORT 1133
#define IMPORT_FUNCTION 1134
#define PROMPT_MANY 1135
#define POINTS 1136
#define MM 1137
#define INCHES 1138
#define PREPEND 1139
#define MEMBER_OF 1140
#define APPEND 1141
#define TEMPLATE 1142
#define END_TEMPLATE 1143
#define SQLSICS 1144
#define CREATE_SCHEMA 1145
#define SQLSIRR 1146
#define UPDATESTATS_T 1147
#define SQLSICR 1148
#define WHENEVER_SQLSUCCESS 1149
#define WHENEVER_SQLWARNING 1150
#define WHENEVER_ANY_ERROR 1151
#define WHENEVER_NOT_FOUND 1152
#define WHENEVER_SQLERROR 1153
#define WHENEVER_SUCCESS 1154
#define WHENEVER_ERROR 1155
#define START_EXTERN 1156
#define CONTINUE_CONSTRUCT 1157
#define FOUNCONSTR 1158
#define SQLSIDR 1159
#define CREATE_TEMP_TABLE 1160
#define CURRENT_WINDOW_IS 1161
#define FIRST_PAGE_HEADER 1162
#define ORDER_EXTERNAL_BY 1163
#define SCROLL_CURSOR_FOR 1164
#define SCROLL_CURSOR 1165
#define SQL_INTERRUPT_OFF 1166
#define STOP_ALL_EXTERNAL 1167
#define WITH_CHECK_OPTION 1168
#define WITH_GRANT_OPTION 1169
#define SQLSLMNW 1170
#define ADDCONSTUNIQ 1171
#define CONTINUE_DISPLAY 1172
#define CONTINUE_FOREACH 1173
#define OUTPUT_TO_REPORT 1174
#define SQL_INTERRUPT_ON 1175
#define WHERE_CURRENT_OF 1176
#define WITHOUT_DEFAULTS 1177
#define FOCONSTR 1178
#define SCALED_BY 1179
#define CONTINUE_PROMPT 1180
#define PDF_FUNCTION 1181
#define DEFER_INTERRUPT 1182
#define DISPLAY_BY_NAME 1183
#define NOT_NULL_UNIQUE 1184
#define SKIP_TO_TOP 1185
#define TOP_OF_PAGE 1186
#define SKIP_TO 1187
#define SKIP_BY 1188
#define WITHOUT_WAITING 1189
#define BEFCONSTRUCT 1190
#define SQLSLMW 1191
#define AFTCONSTRUCT 1192
#define ALL_PRIVILEGES 1193
#define CLOSE_DATABASE 1194
#define CONTINUE_INPUT 1195
#define CONTINUE_WHILE 1196
#define CREATE_SYNONYM 1197
#define DROP_TABLE 1198
#define EXIT_CONSTRUCT 1199
#define INEXCLUSIVE 1200
#define REPORT_TO_PRINTER 1201
#define REPORT_TO_PIPE 1202
#define RETURN 1203
#define SET_SESSION_TO 1204
#define UPDATESTATS 1205
#define WITHOUT_HEAD 1206
#define CLEARSCR 1207
#define WITH_B_LOG 1208
#define AUTHORIZATION 1209
#define BOTTOM_MARGIN 1210
#define CLOSE_SESSION 1211
#define CONTINUE_CASE 1212
#define CONTINUE_MENU 1213
#define DISPLAY_ARRAY 1214
#define END_SQL 1215
#define DOLLAR 1216
#define END_CONSTRUCT 1217
#define FIELD_TOUCHED 1218
#define FINISH_REPORT 1219
#define INFACC 1220
#define INPUT_NO_WRAP 1221
#define SETPMOFF 1222
#define UNCONSTRAINED 1223
#define PAGE_TRAILER 1224
#define SETPMON 1225
#define BEFGROUP 1226
#define CLOSE_WINDOW 1227
#define COMMENT_LINE 1228
#define CONTINUE_FOR 1229
#define CREATE_DB 1230
#define CREATE_TABLE 1231
#define DEFAULT_NULL 1232
#define DEFAULT_TODAY 1233
#define DEFAULT_USER 1234
#define DELETE_USING 1235
#define DISPLAY_FORM 1236
#define END_FUNCTION 1237
#define EXIT_DISPLAY 1238
#define EXIT_FOREACH 1239
#define EXIT_PROGRAM 1240
#define INFCOLS 1241
#define ON_EVERY_ROW 1242
#define OPEN_SESSION 1243
#define RIGHT_MARGIN 1244
#define SELECT_USING 1245
#define START_REPORT 1246
#define UNLOCK_TABLE 1247
#define UPDATE_USING 1248
#define ACL_BUILTIN 1249
#define AFTGROUP 1250
#define INFIDX 1251
#define INFSTAT 1252
#define LEFT_MARGIN 1253
#define PAGE_HEADER 1254
#define ROLLBACK_W 1255
#define SET_SESSION 1256
#define SQLSEOFF 1257
#define WITH_A_LOG 1258
#define BEFDISP 1259
#define BEFORE_MENU 1260
#define CREATE_VIEW 1261
#define DEFINE_TYPE 1262
#define DELETE_FROM 1263
#define END_DISPLAY 1264
#define END_REPORT 1265
#define END_FOREACH 1266
#define END_FOR 1267
#define END_GLOBALS 1268
#define EXIT_PROMPT 1269
#define EXTENT_SIZE 1270
#define FOREIGN_KEY 1271
#define HIDE_OPTION 1272
#define HIDE_WINDOW 1273
#define INSERT_INTO 1274
#define IS_NOT_NULL 1275
#define MOVE_WINDOW 1276
#define NEXT_OPTION 1277
#define NOT_MATCHES 1278
#define ON_LAST_ROW 1279
#define OPEN_WINDOW 1280
#define OPEN_STATUSBOX 1281
#define PAGE_LENGTH 1282
#define PAGE_WIDTH 1283
#define PRIMARY_KEY 1284
#define PROMPT_LINE 1285
#define RECORD_LIKE 1286
#define ROLLFORWARD 1287
#define SHOW_OPTION 1288
#define SHOW_WINDOW 1289
#define SQLSEON 1290
#define TO_DATABASE 1291
#define USE_SESSION 1292
#define WITH_NO_LOG 1293
#define AFTDISP 1294
#define BEFFIELD 1295
#define INSHARE 1296
#define UNLOCKTAB 1297
#define AFTFIELD 1298
#define ATTRIBUTES 1299
#define BEFINP 1300
#define BEGIN_WORK 1301
#define CLEARWIN 1302
#define CLOSE_FORM 1303
#define DEFER_QUIT 1304
#define DESCENDING 1305
#define DROP_INDEX 1306
#define END_PROMPT 1307
#define END_RECORD 1308
#define ERROR_LINE 1309
#define EXIT_INPUT 1310
#define EXIT_WHILE 1311
#define FOR_UPDATE_OF 1312
#define FOR_UPDATE 1313
#define GET_FLDBUF 1314
#define INITIALIZE 1315
#define INPUT_WRAP 1316
#define LOCK_TABLE 1317
#define MSG_LINE 1318
#define NOT_EXISTS 1319
#define ON_ANY_KEY 1320
#define REFERENCES 1321
#define RENCOL 1322
#define SET_CURSOR 1323
#define SMALLFLOAT 1324
#define SQLSUCCESS 1325
#define TOP_MARGIN 1326
#define WITH_ARRAY 1327
#define ACCEPTKEY 1328
#define ACCEPT 1329
#define AFTINP 1330
#define CLEARFORMTODEFAULTS 1331
#define CLEARFORM 1332
#define CLEAR_X_FORM 1333
#define COMMIT_W 1334
#define NEXTPAGE 1335
#define PREVPAGE 1336
#define CTRL_KEY 1337
#define INFTABS 1338
#define NEXTFIELD 1339
#define NEXTFORM 1340
#define RENTAB 1341
#define ASCENDING 1342
#define ASSOCIATE 1343
#define CHAR 1344
#define NCHAR 1345
#define NVARCHAR 1346
#define CONSTRUCT 1347
#define DELIMITER 1348
#define DOWNSHIFT 1349
#define DROP_VIEW 1350
#define END_INPUT 1351
#define END_WHILE 1352
#define EXCLUSIVE 1353
#define EXIT_CASE 1354
#define EXIT_MENU 1355
#define FORM_LINE 1356
#define INTERRUPT 1358
#define INTO_TEMP 1359
#define INVISIBLE 1360
#define IN_MEMORY 1361
#define LINKED_TO 1362
#define LOAD_FROM 1363
#define LOCKTAB 1364
#define MENU_LINE 1365
#define OPEN_FORM 1366
#define OTHERWISE 1367
#define PRECISION 1368
#define PRIOR 1369
#define PROCEDURE 1370
#define REPORT_TO 1371
#define RETURNING 1372
#define UNDERLINE 1373
#define UNLOAD_TO 1374
#define BEFROW 1375
#define UNLOAD_T 1376
#define VARIABLE 1377
#define ABSOLUTE 1378
#define AFTROW 1379
#define BUFFERED 1380
#define CONSTANT 1381
#define CONST 1382
#define DATABASE 1383
#define DATETIME 1384
#define DEFAULTS 1385
#define DISTINCT 1386
#define END_CASE 1387
#define END_MAIN 1388
#define END_MENU 1389
#define END_TYPE 1390
#define EXIT_FOR 1391
#define EXTERNAL 1392
#define FRACTION 1393
#define FUNCTION 1394
#define GROUP_BY 1395
#define INTERVAL 1396
#define KWMESSAGE 1397
#define NOT_LIKE 1398
#define NOT_ILIKE 1399
#define NOT_NULL 1400
#define PASSWORD 1401
#define PREVIOUS 1402
#define READONLY 1403
#define REGISTER 1404
#define RELATIVE 1405
#define RESOURCE 1406
#define SMALLINT 1407
#define VALIDATE 1408
#define WITH_LOG 1409
#define WORDWRAP 1410
#define BY_NAME 1411
#define IN_FILE 1412
#define IS_NULL 1413
#define AVERAGE 1415
#define BETWEEN 1416
#define CAPTION 1417
#define CLIPPED 1418
#define CLOSE_BRACKET 1419
#define COLUMNS 1420
#define CONNECT 1422
#define CURRENT 1423
#define DBYNAME 1424
#define DECIMAL 1425
#define DECLARE 1426
#define DEFAULT 1427
#define DISPLAY 1428
#define ENDCODE 1429
#define EXECUTE 1430
#define FOREACH 1431
#define FOREIGN 1432
#define GLOBALS 1433
#define INFIELD 1434
#define INTEGER 1435
#define KWWINDOW 1436
#define MAGENTA 1437
#define OPTIONS 1439
#define PERCENT 1440
#define PREPARE 1441
#define PROGRAM 1442
#define RECOVER 1443
#define REVERSE 1444
#define SECTION 1445
#define SESSION 1446
#define SYNONYM 1447
#define THRU 1448
#define TRAILER 1449
#define UPSHIFT 1450
#define VARCHAR 1451
#define WAITING 1452
#define CLOSE_SHEV 1453
#define CLOSE_SQUARE 1454
#define KW_FALSE 1456
#define NOT_IN 1457
#define ONKEY 1458
#define OPEN_BRACKET 1459
#define BORDER 1460
#define BOTTOM 1461
#define COLUMN 1462
#define COMMIT 1463
#define CREATE 1464
#define CURSOR 1465
#define DEFINE 1466
#define DELETE 1467
#define DOUBLE 1468
#define END_IF 1469
#define ESCAPE 1470
#define EXISTS 1471
#define EXTEND 1472
#define EXTENT 1473
#define FINISH 1474
#define FORMAT 1475
#define HAVING 1476
#define HEADER 1477
#define INSERT 1478
#define LOCATE 1479
#define MARGIN 1480
#define MEMORY 1481
#define MINUTE 1482
#define MODIFY 1483
#define NORMAL 1484
#define EQUAL_EQUAL 1485
#define OPEN_SHEV 1487
#define OPEN_SQUARE 1488
#define OPTION 1489
#define OUTPUT 1490
#define PROMPT 1491
#define PUBLIC 1492
#define RECORD 1493
#define REPORT 1494
#define REVOKE 1495
#define SCHEMA 1496
#define SCROLL_USING 1497
#define SCROLL 1498
#define SECOND 1499
#define SELECT 1500
#define SERIAL 1501
#define SHARED 1502
#define SPACES 1503
#define UNIQUE 1504
#define UNLOCK 1505
#define UPDATE 1506
#define VALUES 1507
#define YELLOW 1508
#define AFTER 1509
#define KWLINE 1510
#define KW_NULL 1511
#define KW_TRUE 1512
#define SINGLE_KEY 1513
#define ALTER 1514
#define ARRAY 1515
#define ASCII 1516
#define AUDIT 1517
#define BLACK 1518
#define BLINK 1519
#define CHECK 1520
#define CLEAR 1521
#define CLOSE 1522
#define CODE_C 1523
#define COUNT 1524
#define DEFER 1525
#define ERROR 1526
#define EVERY 1527
#define FETCH 1528
#define FIRST 1529
#define FLOAT 1530
#define FLUSH 1531
#define FOUND 1532
#define GRANT 1533
#define GREEN 1534
#define GROUP 1535
#define INDEX 1536
#define KWFORM 1537
#define LABEL 1538
#define LOCAL 1540
#define MONEY 1541
#define MONTH 1542
#define ORDER 1545
#define OUTER 1546
#define PAUSE 1547
#define PRINT_IMAGE 1548
#define PRINT_FILE 1549
#define PRINT 1550
#define RIGHT 1551
#define DOUBLE_COLON 1552
#define SEMICOLON 1553
#define SLEEP 1554
#define TUPLE 1555
#define UNION 1556
#define WHERE 1558
#define WHILE 1559
#define WHITE 1560
#define CCODE 1561
#define ANSI 1562
#define BLUE 1563
#define BOLD 1564
#define BYTE 1565
#define FCALL 1566
#define CASE 1567
#define CYAN 1568
#define DATE 1569
#define DESC 1570
#define KWDOWN 1572
#define TAB 1573
#define DROP 1574
#define ELSE 1575
#define EXEC 1576
#define EXIT 1577
#define FREE 1578
#define FROM 1579
#define GOTO 1580
#define HELP_FILE 1581
#define LANG_FILE 1582
#define HELP 1583
#define HIDE 1584
#define HOUR 1585
#define INTO 1586
#define LAST 1587
#define LEFT 1588
#define LIKE 1589
#define MAIN 1590
#define MENU 1591
#define MODE 1592
#define NEED 1593
#define NEXT 1594
#define NOCR 1595
#define OPEN 1596
#define QUIT 1597
#define REAL 1598
#define ROWS 1599
#define SHOW 1600
#define SIZE 1601
#define SKIP 1602
#define SOME 1603
#define STEP 1604
#define STOP 1605
#define TEMP 1606
#define TEXT 1607
#define THEN 1608
#define USER 1609
#define WAIT 1610
#define WHEN 1611
#define WITH 1612
#define WORK 1613
#define YEAR 1614
#define KW_IS 1616
#define XSET 1617
#define ADD 1618
#define ALL 1619
#define ANY 1621
#define ASC 1622
#define AVG 1623
#define COLON 1624
#define DAY 1626
#define DBA 1627
#define DEC 1628
#define DIM 1629
#define FKEY 1630
#define FOR 1631
#define KEY 1632
#define KWNO 1633
#define LET 1634
#define LOG 1635
#define XMAX 1636
#define XMIN 1637
#define PAD 1641
#define PUT 1642
#define RED 1643
#define ROW 1644
#define RUN 1645
#define SQL 1646
#define SUM 1647
#define TOP 1648
#define USE 1649
#define ATSIGN 1650
#define AS_TIFF 1652
#define AS_GIF 1653
#define AS_PNG 1654
#define AS_JPEG 1655
#define AS 1656
#define AT 1657
#define BY 1658
#define DOT 1659
#define GO 1660
#define IF 1661
#define IN 1662
#define OF 1663
#define ON 1664
#define TO 1666
#define KWUP 1667
#define FONT_NAME 1668
#define FONT_SIZE 1669
#define PAPER_SIZE_IS_LETTER 1670
#define PAPER_SIZE_IS_LEGAL 1671
#define PAPER_SIZE_IS_A5 1672
#define PAPER_SIZE_IS_A4 1673
#define PAPER_SIZE_IS_LETTER_L 1674
#define PAPER_SIZE_IS_LEGAL_L 1675
#define PAPER_SIZE_IS_A5_L 1676
#define PAPER_SIZE_IS_A4_L 1677
#define FORMHANDLER 1678
#define END_FORMHANDLER 1679
#define BEFORE_EVENT 1680
#define BEFORE_OPEN_FORM 1681
#define AFTER_EVENT 1682
#define BEFORE_CLOSE_FORM 1683
#define BEFORE_ANY 1684
#define AFTER_ANY 1685
#define MENUHANDLER 1686
#define END_MENUHANDLER 1687
#define BEFORE_SHOW_MENU 1688
#define DISABLE_PROGRAM 1689
#define DISABLE_ALL 1690
#define BUTTONS 1691
#define CHECK_MENUITEM 1692
#define DISABLE_FORM 1693
#define DISABLE_MENUITEMS 1694
#define DISABLE 1695
#define ENABLE_FORM 1696
#define ENABLE_MENUITEMS 1697
#define ENABLE 1698
#define KWFIELD 1699
#define ICON 1700
#define MESSAGEBOX 1701
#define TO_DEFAULTS 1702
#define UNCHECK_MENUITEM 1703
#define BEFORE 1704
#define INPUT 1705
#define END 1706
#define INT_TO_ID 1707
#define TIMEOUT 1708
#define OFF 1709
#define WITH_1_DIMENSION 1710
#define WITH_2_DIMENSION 1711
#define WITH_3_DIMENSION 1712
#define TILDE 1713
#define ILIKE 1714
#define FGL_ISDYNARR_ALLOCATED 1715
#define FGL_DYNARR_EXTENTSIZE 1716
#define FILLFACTOR 1717
#define END_CLASS 1718
#define KW_CLASS 1719
#define EXTENDS 1720
#define PIPE 1721




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
//void set_yytext (char *s);
int isin_command (char *cmd_type);
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
char *do_clobbering(char *f,char *s);
//void A4GL_copy_fbind_to_Obind(void);
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
#line 1734 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1746 "y.tab.c"

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
#define YYLAST   9737

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  739
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  877
/* YYNRULES -- Number of rules. */
#define YYNRULES  2073
/* YYNRULES -- Number of states. */
#define YYNSTATES  3520

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1736

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
     386,   387,   388,   389,   390,   391,   392,    15,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,    16,   449,   450,   451,   452,   453,
     454,    23,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,    10,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,    13,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,    17,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,    12,
     569,   570,   571,    11,    20,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,     8,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,    21,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,    14,   640,   641,   642,   643,
       7,   644,   645,   646,   647,     5,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,   658,   659,    19,    22,
       9,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,    18,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,     6,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   736,
     737,   738,     2,     3,     4,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35
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
    3412,  3414,  3418,  3420,  3422,  3426,  3431,  3436,  3440,  3444,
    3447,  3456,  3463,  3465,  3467,  3470,  3472,  3473,  3475,  3483,
    3486,  3490,  3499,  3506,  3509,  3512,  3515,  3518,  3520,  3523,
    3524,  3528,  3529,  3533,  3534,  3538,  3539,  3543,  3544,  3548,
    3549,  3554,  3555,  3560,  3562,  3564,  3566,  3568,  3570,  3572,
    3573,  3578,  3579,  3581,  3582,  3587,  3589,  3592,  3595,  3598,
    3599,  3601,  3603,  3606,  3609,  3610,  3613,  3614,  3619,  3621,
    3625,  3629,  3635,  3636,  3639,  3644,  3646,  3648,  3650,  3652,
    3654,  3655,  3657,  3659,  3663,  3666,  3672,  3675,  3681,  3687,
    3693,  3699,  3705,  3711,  3712,  3715,  3717,  3720,  3723,  3726,
    3729,  3732,  3735,  3737,  3740,  3743,  3746,  3749,  3751,  3754,
    3757,  3760,  3763,  3765,  3767,  3769,  3770,  3773,  3776,  3779,
    3782,  3785,  3788,  3791,  3794,  3797,  3799,  3801,  3803,  3805,
    3807,  3809,  3811,  3813,  3816,  3819,  3822,  3825,  3828,  3830,
    3832,  3834,  3835,  3839,  3842,  3843,  3844,  3845,  3846,  3847,
    3848,  3864,  3865,  3868,  3871,  3872,  3874,  3875,  3876,  3877,
    3878,  3879,  3880,  3896,  3899,  3900,  3901,  3902,  3913,  3914,
    3916,  3920,  3924,  3927,  3931,  3936,  3940,  3946,  3951,  3955,
    3959,  3961,  3963,  3965,  3968,  3971,  3974,  3977,  3979,  3981,
    3982,  3983,  3992,  3993,  3994,  4004,  4005,  4007,  4009,  4012,
    4015,  4018,  4021,  4023,  4025,  4027,  4028,  4030,  4032,  4035,
    4038,  4041,  4050,  4053,  4056,  4061,  4064,  4065,  4067,  4069,
    4073,  4076,  4079,  4081,  4083,  4087,  4089,  4091,  4094,  4096,
    4100,  4104,  4108,  4110,  4114,  4116,  4118,  4120,  4122,  4124,
    4126,  4128,  4131,  4136,  4138,  4142,  4144,  4148,  4151,  4156,
    4158,  4162,  4164,  4167,  4172,  4174,  4178,  4180,  4182,  4184,
    4187,  4191,  4196,  4199,  4204,  4205,  4208,  4211,  4216,  4218,
    4222,  4224,  4226,  4228,  4231,  4233,  4235,  4237,  4239,  4241,
    4244,  4251,  4258,  4259,  4261,  4262,  4264,  4267,  4269,  4270,
    4276,  4277,  4283,  4285,  4286,  4290,  4292,  4296,  4298,  4302,
    4304,  4306,  4307,  4312,  4314,  4317,  4319,  4320,  4321,  4325,
    4326,  4327,  4331,  4333,  4335,  4337,  4339,  4341,  4343,  4346,
    4349,  4354,  4358,  4362,  4364,  4368,  4371,  4373,  4375,  4376,
    4378,  4380,  4382,  4384,  4385,  4387,  4391,  4393,  4397,  4399,
    4400,  4404,  4406,  4408,  4410,  4412,  4414,  4416,  4418,  4420,
    4422,  4424,  4426,  4428,  4430,  4438,  4445,  4450,  4455,  4457,
    4459,  4461,  4462,  4464,  4467,  4469,  4471,  4473,  4475,  4479,
    4482,  4484,  4486,  4489,  4491,  4493,  4494,  4498,  4500,  4504,
    4506,  4510,  4512,  4514,  4521,  4522,  4526,  4528,  4532,  4533,
    4535,  4540,  4546,  4549,  4551,  4553,  4558,  4560,  4564,  4569,
    4574,  4579,  4581,  4585,  4587,  4589,  4591,  4594,  4596,  4598,
    4600,  4605,  4606,  4608,  4609,  4611,  4613,  4616,  4619,  4621,
    4623,  4625,  4627,  4629,  4634,  4636,  4640,  4642,  4644,  4646,
    4649,  4651,  4653,  4656,  4659,  4661,  4665,  4668,  4671,  4673,
    4677,  4679,  4682,  4687,  4689,  4692,  4696,  4698,  4702,  4707,
    4708,  4710,  4711,  4713,  4714,  4716,  4718,  4722,  4724,  4728,
    4730,  4733,  4735,  4739,  4742,  4745,  4746,  4749,  4751,  4753,
    4759,  4763,  4769,  4773,  4775,  4779,  4781,  4783,  4784,  4786,
    4790,  4794,  4798,  4805,  4810,  4815,  4820,  4825,  4831,  4833,
    4835,  4837,  4839,  4841,  4843,  4845,  4847,  4849,  4851,  4852,
    4854,  4856,  4858,  4860,  4862,  4864,  4866,  4871,  4872,  4874,
    4879,  4881,  4887,  4893,  4895,  4897,  4899,  4901,  4903,  4908,
    4910,  4915,  4922,  4927,  4929,  4934,  4936,  4944,  4946,  4948,
    4950,  4955,  4962,  4963,  4966,  4971,  4973,  4975,  4977,  4979,
    4981,  4983,  4985,  4989,  4991,  4993,  4997,  5003,  5007,  5013,
    5021,  5025,  5027,  5029,  5033,  5039,  5043,  5049,  5057,  5059,
    5060,  5064,  5070,  5072,  5075,  5078,  5083,  5087,  5089,  5091,
    5093,  5095,  5097,  5100,  5103,  5104,  5108,  5109,  5113,  5115,
    5117,  5119,  5121,  5123,  5125,  5127,  5132,  5134,  5136,  5138,
    5140,  5142,  5144,  5146,  5148,  5150,  5152,  5154,  5156,  5158,
    5160,  5165,  5167,  5171,  5173,  5177,  5178,  5186,  5187,  5196,
    5197,  5204,  5205,  5214,  5215,  5217,  5220,  5222,  5226,  5228,
    5232,  5238,  5240,  5242,  5244,  5246,  5248,  5249,  5250,  5260,
    5266,  5268,  5270,  5277,  5278,  5282,  5284,  5288,  5293,  5295,
    5296,  5299,  5304,  5311,  5312,  5314,  5316,  5318,  5320,  5324,
    5326,  5329,  5333,  5335,  5337,  5340,  5343,  5345,  5347,  5349,
    5352,  5355,  5358,  5361,  5366,  5370,  5373,  5377,  5381,  5385,
    5387,  5389,  5391,  5393,  5395,  5397,  5403,  5409,  5415,  5421,
    5427,  5432,  5437,  5441,  5446,  5448,  5450,  5452,  5456,  5458,
    5464,  5472,  5478,  5479,  5482,  5484,  5486,  5487,  5491,  5493,
    5497,  5499,  5501,  5503,  5504,  5508,  5510,  5512,  5514,  5516,
    5521,  5528,  5530,  5532,  5535,  5539,  5541,  5543,  5545,  5547,
    5549,  5551,  5553,  5555,  5561,  5567,  5572,  5578,  5580,  5585,
    5587,  5589,  5597,  5602,  5604,  5605,  5610,  5612,  5615,  5617,
    5619,  5621,  5622,  5626,  5627,  5631,  5632,  5633,  5640,  5641,
    5644,  5647,  5655,  5659,  5663,  5666,  5669,  5672,  5674,  5678,
    5680,  5684,  5686,  5690,  5692,  5696,  5698,  5700,  5702,  5705,
    5708,  5710,  5712,  5715,  5720,  5726,  5734,  5742,  5752,  5754,
    5756,  5758,  5760,  5762,  5764,  5768,  5771,  5775,  5779,  5783,
    5789,  5795,  5801,  5807,  5813,  5818,  5823,  5827,  5832,  5834,
    5836,  5838,  5840,  5844,  5845,  5851,  5853,  5857,  5861,  5865,
    5867,  5869,  5872,  5874,  5876,  5880,  5882,  5886,  5890,  5892,
    5894,  5896,  5900,  5903,  5907,  5914,  5916,  5920,  5922,  5924,
    5925,  5926,  5933,  5934,  5937,  5938,  5940,  5942,  5945,  5948,
    5950,  5952,  5957,  5961,  5963,  5966,  5972,  5975,  5978,  5984,
    5985,  5988,  5990,  5992,  5995,  6002,  6009,  6011,  6012,  6014,
    6017,  6019,  6022,  6023,  6026,  6028,  6030,  6032,  6034,  6036,
    6038,  6040,  6042,  6044,  6046,  6048,  6050,  6052,  6054,  6056,
    6058,  6060,  6062,  6064,  6066,  6068,  6070,  6072,  6074,  6076,
    6078,  6080,  6082,  6084,  6086,  6088,  6090,  6092,  6094,  6096,
    6098,  6100,  6102,  6104,  6106,  6108,  6110,  6112,  6114,  6116,
    6118,  6120,  6122,  6124,  6126,  6128,  6130,  6132,  6134,  6136,
    6138,  6140,  6142,  6144,  6146,  6148,  6150,  6152,  6154,  6156,
    6158,  6160,  6162,  6164,  6166,  6168,  6170,  6172,  6174,  6176,
    6178,  6180,  6182,  6184,  6186,  6188,  6190,  6192,  6194,  6196,
    6198,  6200,  6202,  6204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1121,     0,    -1,   261,    -1,   258,    -1,   192,   744,   486,
     653,   745,    -1,   203,    -1,  1184,    -1,    26,    -1,   746,
      -1,   745,     5,   746,    -1,  1028,    -1,   490,   747,   453,
      -1,   747,   748,   747,    -1,    26,    -1,   749,    26,    -1,
    1184,    -1,   968,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   751,
      -1,    -1,   335,   490,   752,   753,   453,    -1,   626,   490,
      26,     5,    26,   453,    -1,   754,    -1,   753,     5,   754,
      -1,   548,    -1,   589,    -1,   594,    -1,   564,    -1,   470,
      -1,   662,    -1,   586,    -1,   538,    -1,   476,    -1,   549,
      -1,   408,    -1,   590,    -1,   515,    -1,   395,    -1,   651,
      -1,   160,    -1,  1100,    -1,    -1,   756,    -1,    -1,   335,
     490,   757,   758,   453,    -1,   759,    -1,   758,     5,   759,
      -1,   754,    -1,   491,    -1,   660,    25,    -1,   264,  1014,
      -1,   392,  1014,    -1,   345,  1014,    -1,   400,  1014,    -1,
     354,  1014,    -1,   321,  1014,    -1,   592,   761,    -1,   957,
     407,  1184,    -1,    -1,   350,   490,   976,   453,   407,   762,
    1202,    -1,   168,   490,  1028,     5,    25,     5,    25,   453,
      -1,   467,   490,  1020,   453,   407,  1184,    -1,  1326,    -1,
     254,   490,   976,   453,   407,  1184,    -1,    -1,    -1,  1184,
     647,  1028,   490,   763,   779,   453,   764,   777,    -1,    -1,
      -1,  1184,    36,  1028,   490,   765,   779,   453,   766,   777,
      -1,    -1,    -1,    -1,  1028,   490,   767,   779,   768,   453,
     769,   777,    -1,    -1,    -1,   532,  1535,   680,  1535,   490,
     770,   779,   771,   453,   777,    -1,    -1,    -1,  1028,   579,
    1028,   490,   772,   779,   773,   453,   777,    -1,    -1,    -1,
      -1,   427,   782,   647,   783,   518,   744,   486,   490,   774,
     779,   775,   453,   776,   778,    -1,    -1,   407,  1202,    -1,
      -1,   407,  1202,    -1,   225,    -1,    -1,   780,    -1,   781,
      -1,   780,     5,   781,    -1,   926,    -1,   541,    -1,    25,
      -1,  1028,    -1,  1028,    -1,  1028,   677,  1028,    -1,    -1,
     593,   933,   785,   788,   792,   789,    -1,    -1,   593,   786,
     787,   790,   789,    -1,   794,    -1,   787,   794,    -1,   796,
      -1,   788,   796,    -1,   422,    -1,    -1,    -1,   402,   791,
    1610,    -1,    -1,    -1,   402,   793,  1610,    -1,    -1,   636,
     933,   795,  1610,    -1,    -1,   636,   933,   797,  1610,    -1,
      -1,    -1,    -1,   736,  1028,   799,   802,   800,   832,   801,
     803,   735,    -1,    -1,   737,  1028,    -1,   804,    -1,   803,
     804,    -1,  1136,    -1,   339,  1025,    -1,   263,  1023,    -1,
     145,  1023,    -1,   230,    -1,   247,  1541,    -1,   552,  1022,
      -1,    30,   807,    31,    -1,   808,    -1,   810,    -1,   809,
      -1,   808,   809,    -1,    29,    -1,   811,    -1,   810,   811,
      -1,    28,    -1,    -1,    -1,   383,   813,   815,   814,   816,
      -1,   446,  1184,   682,   817,  1072,  1099,   750,    -1,  1184,
     682,   817,  1072,   604,   976,  1099,   750,    -1,    -1,   819,
     253,    -1,   818,    -1,   817,     5,   818,    -1,  1028,    -1,
    1028,   677,  1028,    -1,  1028,   677,    20,    -1,   820,    -1,
     819,   820,    -1,    -1,   331,   826,   821,  1610,    -1,    -1,
     334,   827,   822,  1610,    -1,    -1,  1102,   823,  1610,    -1,
      -1,   228,   824,  1610,    -1,    -1,   226,   825,  1610,    -1,
    1032,    -1,   826,     5,  1032,    -1,  1032,    -1,   827,     5,
    1032,    -1,   154,    -1,   155,    -1,   156,    -1,   157,    -1,
     158,    -1,   159,    -1,   490,   926,   830,   453,    -1,    -1,
       5,   877,   683,   880,    -1,   218,    -1,   340,    -1,    -1,
     833,    -1,   834,    -1,   833,   834,    -1,    -1,    -1,   497,
     835,   837,   836,  1295,    -1,   890,    -1,   840,    -1,   837,
       5,   840,    -1,    -1,   839,  1028,    -1,   416,   838,   889,
      25,    -1,   416,   838,   889,  1028,    -1,   416,   838,   889,
    1034,    -1,   416,   838,   889,    26,    -1,   844,   863,    -1,
      -1,   838,   416,   841,   842,    -1,    26,    -1,    25,    -1,
    1034,    -1,    19,    26,    -1,   838,    -1,   843,    -1,   844,
       5,   843,    -1,    -1,   380,    -1,    -1,   727,    -1,   728,
      -1,   729,    -1,    -1,   545,   518,   854,   486,   848,   681,
     863,    -1,    -1,    49,   846,   849,   681,   863,    -1,    -1,
     379,   845,   851,    26,   852,   363,   518,   853,   486,   850,
     681,   863,    -1,   490,    -1,   517,    -1,   453,    -1,   485,
      -1,    26,    -1,   855,     5,   855,     5,   855,    -1,   855,
       5,   855,    -1,   855,    -1,    26,    -1,   838,    -1,   838,
     647,   838,    -1,   838,   669,   838,   647,   838,    -1,    -1,
     523,   858,   837,   344,    -1,    -1,   322,   859,   856,   677,
      20,    -1,    -1,   397,   860,   856,   320,   490,   861,   453,
      -1,   862,    -1,   861,     5,   862,    -1,   838,    -1,   865,
      -1,    -1,   120,    -1,    -1,    -1,   866,   868,   867,   864,
      -1,   847,    -1,   857,    -1,   380,    -1,   381,    -1,   380,
     490,    26,   453,    -1,   381,   490,    26,   453,    -1,   483,
     490,    26,   453,    -1,   483,   490,    26,     5,    26,   453,
      -1,   382,   490,    26,   453,    -1,   382,   490,    26,     5,
      26,   453,    -1,   468,    -1,   674,   838,    -1,   442,    -1,
     567,    -1,   152,    -1,   458,    -1,   458,   490,    26,   453,
      -1,   458,   490,    26,     5,    26,   453,    -1,   570,    -1,
     570,   490,    26,   453,    -1,   570,   490,    26,     5,    26,
     453,    -1,    -1,   560,   869,   872,    -1,    -1,   125,   870,
     872,    -1,    -1,   360,   871,   872,    -1,   595,    -1,   591,
      -1,   141,    -1,   142,    -1,   632,    -1,   419,   875,    -1,
     431,   876,    -1,   873,    -1,    32,    -1,    -1,   490,    26,
     453,    -1,   614,   856,   677,   874,    -1,   838,    -1,    -1,
     877,   683,   880,    -1,   885,   683,   888,    -1,    -1,   878,
     879,    -1,   639,    -1,   571,    -1,   648,    -1,   610,    -1,
     513,    -1,   529,    -1,   428,   882,    -1,    -1,   881,   879,
      -1,    -1,   490,   884,   453,    -1,    -1,   490,    26,   453,
      -1,    26,    -1,    -1,   886,   887,   883,    -1,   639,    -1,
     571,    -1,   648,    -1,   610,    -1,   513,    -1,   529,    -1,
     428,   882,    -1,   887,    -1,    -1,    14,    -1,    -1,   298,
    1028,   891,   674,   892,    -1,   894,    -1,   897,    -1,   380,
      -1,   380,   490,    26,   453,    -1,   483,   490,    26,   453,
      -1,   483,   490,    26,     5,    26,   453,    -1,   468,    -1,
     442,    -1,   567,    -1,   458,    -1,   458,   490,    26,   453,
      -1,   458,   490,    26,     5,    26,   453,    -1,   570,    -1,
     570,   490,    26,   453,    -1,   570,   490,    26,     5,    26,
     453,    -1,   560,    -1,   360,    -1,   595,    -1,   591,    -1,
     632,    -1,   419,   875,    -1,   431,   876,    -1,   893,    -1,
     614,   856,   677,   874,    -1,    -1,   545,   518,   854,   486,
     895,   681,   892,    -1,    -1,   379,   845,   851,    26,   852,
     363,   518,   853,   486,   896,   681,   892,    -1,    -1,   523,
     898,   900,   344,    -1,    -1,   322,   899,  1028,   677,    20,
      -1,   901,    -1,   900,     5,   901,    -1,   902,   892,    -1,
     903,    -1,   902,     5,   903,    -1,  1028,    -1,    -1,   675,
    1018,    -1,   132,  1028,    -1,   130,    -1,   683,   976,    -1,
     683,   567,  1028,   716,   976,    -1,   683,   567,  1028,   451,
      -1,   134,  1028,    -1,   219,   949,  1202,   912,    -1,   461,
     949,   931,   904,   912,    -1,   272,  1025,   912,    -1,    -1,
      -1,   250,   909,  1209,   683,  1028,   677,    20,   911,   750,
     910,   913,    -1,    -1,   527,  1019,    -1,   750,    -1,    -1,
     914,   300,    -1,   300,    -1,   915,    -1,   914,   915,    -1,
      -1,   414,   916,  1610,    -1,    -1,   410,   917,  1610,    -1,
      -1,  1102,   918,  1610,    -1,    51,  1184,    -1,    52,  1184,
      -1,    50,  1184,    -1,   556,   949,   932,   750,    -1,   556,
     949,   932,   750,   127,    -1,   276,    -1,   276,   933,    -1,
     347,    -1,   346,    -1,   275,    -1,   426,    -1,   235,    -1,
     274,    -1,   391,    -1,   390,    -1,   305,    -1,   232,    -1,
     231,    -1,   209,    -1,   265,    -1,   193,    -1,   208,    -1,
     249,    -1,   216,    -1,   934,    -1,   938,    -1,   968,    -1,
     926,   927,    -1,   969,    -1,   971,    -1,   935,    -1,    19,
     926,    -1,    18,   926,    -1,   940,    -1,   948,    -1,   942,
      -1,   533,    -1,   828,    -1,   943,    -1,   944,    -1,   945,
      -1,   946,    -1,   947,    -1,    56,   926,    -1,   949,    -1,
     949,   930,    -1,   933,    -1,   541,    -1,   929,    -1,   930,
       5,   929,    -1,   933,    -1,   931,     5,   933,    -1,   933,
      -1,   932,     5,   933,    -1,   926,    -1,     9,   926,    -1,
     542,    -1,   487,    -1,   490,   926,   453,    -1,   502,   490,
    1515,   453,    -1,   355,   490,  1515,   453,    -1,    25,    -1,
    1034,    -1,    26,    -1,   937,    -1,  1184,    -1,  1184,   480,
    1184,    -1,   936,    -1,   493,   926,    -1,   454,   926,    -1,
    1298,    -1,    -1,   565,   939,  1298,    -1,     7,   926,    -1,
       6,   926,    -1,   926,    -1,   941,     5,   926,    -1,   680,
     490,  1515,   453,    -1,   488,   490,  1515,   453,    -1,   680,
     490,   949,   941,   453,    -1,   488,   490,   949,   941,   453,
      -1,   448,    -1,   311,    -1,    10,   926,    -1,   314,   926,
      -1,    10,   926,   501,    25,    -1,   314,   926,   501,    25,
      -1,   614,   926,    -1,   433,   926,    -1,   614,   926,   501,
      25,    -1,   433,   926,   501,    25,    -1,   452,    -1,     8,
     926,    -1,    18,   926,    -1,    19,   926,    -1,    20,   926,
      -1,    21,   926,    -1,    22,   926,    -1,    11,   926,    -1,
      14,   926,    -1,   516,   926,    -1,    12,   926,    -1,    13,
     926,    -1,    17,   926,    -1,    16,   926,    -1,    15,   926,
      -1,    -1,    -1,    -1,  1028,   490,   951,   779,   952,   453,
      -1,    -1,    -1,  1028,   579,  1028,   490,   953,   779,   954,
     453,    -1,    -1,    -1,  1028,    36,  1028,   490,   955,   779,
     956,   453,    -1,    -1,    -1,   595,   490,   958,   926,   959,
     453,    -1,    -1,    -1,   571,   490,   960,   926,   961,   453,
      -1,    -1,    -1,   648,   490,   962,   926,   963,   453,    -1,
      -1,    -1,   639,   490,   964,   926,   965,   453,    -1,   431,
     490,   972,   453,   967,    -1,   419,   490,    25,   453,   966,
      -1,   419,   490,    26,   453,   966,    -1,   419,   490,    24,
     453,   966,    -1,   419,   490,    26,   647,    26,   453,   966,
      -1,   419,   490,    26,   647,    24,   453,   966,    -1,   419,
     490,    26,   647,    26,   647,    26,   453,   966,    -1,   419,
     490,    26,   647,    26,   647,    24,   453,   966,    -1,   419,
     490,    26,    26,   453,   966,    -1,   419,   490,    26,    26,
     647,    26,   453,   966,    -1,   419,   490,    26,    26,   647,
      26,   647,    26,   453,   966,    -1,   419,   490,    26,    26,
     647,    26,   647,    24,   453,   966,    -1,   419,   490,    26,
      19,    26,   453,   966,    -1,   419,   490,    26,    19,    26,
      19,    26,   453,   966,    -1,   419,   490,    26,    19,    26,
      26,   453,   966,    -1,   419,   490,    26,    19,    26,    19,
      26,    26,   453,   966,    -1,   419,   490,    26,    19,    26,
      19,    26,    26,   647,    26,   453,   966,    -1,   419,   490,
      26,    19,    26,    19,    26,    26,   647,    26,   647,    26,
     453,   966,    -1,   419,   490,    26,    19,    26,    19,    26,
      26,   647,    26,   647,    24,   453,   966,    -1,   419,   490,
      26,    19,    26,    26,   647,    26,   453,   966,    -1,   419,
     490,    26,    19,    26,    26,   647,    26,   647,    26,   453,
     966,    -1,   419,   490,    26,    19,    26,    26,   647,    26,
     647,    24,   453,   966,    -1,    47,   490,  1184,   453,    -1,
     732,   490,  1184,   453,    -1,   733,   490,  1184,     5,    26,
     453,    -1,    -1,   879,   683,   879,    -1,   876,    -1,   957,
      -1,   350,   490,   976,   453,    -1,   161,   490,  1019,   453,
      -1,   133,   490,  1019,   453,    -1,   467,   490,   977,   453,
      -1,   254,   490,   976,   453,    -1,   121,   490,   976,   453,
      -1,   970,    -1,   950,    -1,  1492,    -1,   595,    -1,   482,
     490,   926,   453,    -1,   385,   490,   926,   453,    -1,   546,
     926,    -1,   503,   829,    -1,   926,   172,    -1,   926,   173,
      -1,   926,   174,    -1,    25,    -1,   973,    -1,    19,   973,
      -1,   975,    -1,   974,    -1,    26,    -1,    26,    26,    -1,
      26,    26,   647,    26,    -1,    26,    26,   647,    26,   647,
      26,    -1,    26,    26,   647,    26,   647,    24,    -1,    26,
     647,    26,    -1,    26,   647,    26,   647,    26,    -1,    26,
     647,    26,   647,    24,    -1,    26,   647,    24,    -1,    24,
      -1,   677,    26,    -1,    26,    -1,    26,    19,    26,    -1,
    1019,    -1,   976,     5,  1019,    -1,  1020,    -1,   977,     5,
    1020,    -1,    -1,    -1,    -1,   464,   979,  1022,   980,   982,
    1394,   981,  1610,   302,    -1,    -1,     8,   949,   931,    -1,
      -1,    -1,   695,  1028,   984,   832,   985,  1133,   987,   986,
     992,   696,    -1,    -1,   997,    -1,    -1,   988,    -1,   989,
      -1,   988,   989,    -1,    -1,   697,   990,  1610,    -1,    -1,
     698,   991,  1610,    -1,    -1,   993,    -1,   994,    -1,   993,
     994,    -1,    -1,   699,   995,  1610,    -1,    -1,   700,   996,
    1610,    -1,   998,  1002,   387,    -1,   153,    -1,   153,   999,
     604,  1000,    -1,   153,   446,  1001,    -1,  1184,    -1,   999,
       5,  1184,    -1,  1028,    -1,  1000,     5,  1028,    -1,  1184,
      -1,  1001,     5,  1184,    -1,  1003,    -1,  1002,  1003,    -1,
      -1,   701,  1004,  1610,    -1,    -1,   702,  1005,  1610,    -1,
      -1,   721,  1000,  1006,  1610,    -1,    -1,   539,  1000,  1007,
    1610,    -1,    -1,   682,  1000,  1008,  1610,    -1,    -1,    -1,
     653,  1184,    14,   933,   683,   933,  1012,  1010,  1610,  1011,
     303,    -1,    -1,   629,   933,    -1,   603,  1021,    -1,   612,
      19,    26,    -1,   612,    -1,   559,    18,    26,    -1,   559,
      -1,    26,    -1,  1184,    -1,   726,    -1,    25,    -1,  1033,
      -1,   933,    -1,  1016,     5,  1016,    -1,  1017,    -1,  1028,
      -1,   724,   490,  1028,   453,    -1,  1028,   677,   724,   490,
    1028,   453,    -1,  1028,   518,   747,   486,    -1,  1028,   677,
      20,    -1,  1028,   518,   747,   486,   677,    20,    -1,  1028,
     677,  1028,    -1,  1028,   518,   747,   486,   677,  1028,    -1,
    1019,    -1,    25,    -1,  1029,    -1,  1029,    -1,  1029,    -1,
    1029,    -1,  1029,    -1,  1029,    -1,    -1,   608,    26,    -1,
    1609,    -1,  1030,    -1,  1609,    -1,   412,   490,  1031,   453,
      -1,  1187,    -1,    25,    -1,  1028,    -1,  1028,   518,   747,
     486,    -1,  1028,   677,    20,    -1,  1028,   518,   747,   486,
     677,    20,    -1,  1028,   677,  1028,    -1,  1028,   518,   747,
     486,   677,  1028,    -1,  1184,    -1,    24,    -1,   677,    26,
      -1,   605,  1036,    -1,  1028,    -1,   647,  1028,    -1,   709,
    1038,    -1,  1039,    -1,  1038,     5,  1039,    -1,  1028,    -1,
     720,  1038,    -1,   711,  1038,    -1,   712,   976,    -1,   710,
    1025,   716,   976,    -1,   714,  1038,    -1,   715,   976,    -1,
     713,  1025,   716,   976,    -1,    -1,   718,  1044,   931,  1049,
    1051,  1053,  1045,  1047,    -1,    -1,  1046,    -1,   706,    -1,
     707,    -1,    -1,  1048,    -1,   407,  1184,    -1,    -1,  1050,
      -1,   451,   931,    -1,    -1,  1052,    -1,   717,    26,    -1,
      -1,  1054,    -1,   708,    26,  1055,    -1,    -1,   460,    26,
      -1,    -1,    -1,   679,   933,   633,  1057,  1610,  1058,  1059,
     500,    -1,    -1,    -1,   600,  1060,  1610,    -1,    -1,    -1,
     124,  1061,   933,   633,  1062,  1610,  1059,    -1,   170,  1028,
     490,    26,   453,    -1,   115,  1028,    -1,    48,  1028,    -1,
     137,  1028,    -1,    -1,   351,  1213,  1067,   683,   541,    -1,
     351,  1213,   614,  1068,    -1,  1069,    -1,  1068,     5,  1069,
      -1,  1070,   677,  1488,    -1,  1070,   677,    20,    -1,  1484,
      -1,    -1,  1073,   387,    -1,   387,    -1,    -1,   213,    -1,
    1074,    -1,  1073,  1074,    -1,    -1,   331,  1088,  1075,  1610,
      -1,    -1,   334,  1089,  1076,  1610,    -1,    -1,   414,  1077,
    1610,    -1,    -1,   410,  1078,  1610,    -1,    -1,  1102,  1079,
    1610,    -1,    -1,   366,  1080,  1610,    -1,    -1,   336,  1081,
    1610,    -1,    -1,    57,  1082,  1610,    -1,    -1,    55,  1083,
    1610,    -1,    -1,    54,  1084,  1610,    -1,    -1,    53,  1085,
    1610,    -1,    -1,    60,  1086,  1610,    -1,    -1,    59,  1087,
    1610,    -1,  1019,    -1,  1088,     5,  1019,    -1,  1019,    -1,
    1089,     5,  1019,    -1,   375,  1092,    -1,   376,  1028,   716,
    1092,    -1,   619,    -1,   437,    -1,  1019,    -1,    -1,   722,
    1095,  1094,  1071,    -1,   446,  1202,  1072,  1027,   750,    -1,
    1202,  1072,   604,   976,  1027,   750,    -1,    -1,   545,  1209,
    1072,   604,  1028,   677,    20,  1027,  1096,   750,    -1,   528,
     976,  1098,    -1,   143,    26,    -1,   144,    26,    -1,   684,
      -1,   597,    -1,   143,  1184,    -1,   144,  1184,    -1,    -1,
     608,    26,    -1,  1101,    -1,    66,    25,    -1,   554,    14,
      26,    -1,   554,    14,  1184,    -1,    67,    14,    26,    -1,
      67,    14,  1184,    -1,    63,    -1,    65,    -1,    62,    -1,
      64,    -1,    -1,   489,  1103,  1108,    -1,   356,    -1,    -1,
     654,  1105,  1108,    -1,   364,  1110,    -1,   654,  1108,    -1,
    1110,    -1,   490,  1109,   453,    -1,  1110,    -1,  1109,     5,
    1110,    -1,  1111,    -1,   652,    -1,   373,    -1,   393,    -1,
     365,    -1,   543,    -1,   501,    -1,   684,    -1,   608,    -1,
     597,    -1,   239,    -1,   498,    -1,   509,    -1,   598,    -1,
     613,    -1,   578,    -1,   371,    -1,   372,    -1,    25,    -1,
     568,    -1,    -1,    -1,   656,  1114,  1207,  1115,    14,   949,
    1116,    -1,   541,    -1,   932,    -1,   281,  1184,    -1,   271,
    1184,    -1,   284,  1184,    -1,   510,  1205,   396,    -1,   510,
    1205,   447,  1015,    -1,  1122,    -1,  1123,    -1,   798,    -1,
      -1,  1125,  1124,  1128,    -1,    -1,  1126,    -1,  1127,    -1,
    1126,  1127,    -1,  1065,    -1,  1132,    -1,  1594,    -1,  1064,
      -1,  1148,    -1,  1134,    -1,  1147,    -1,    -1,  1129,    -1,
    1131,    -1,  1129,  1131,    -1,   128,  1028,    -1,  1136,    -1,
    1142,    -1,  1308,    -1,  1318,    -1,  1154,    -1,   983,    -1,
     806,    -1,  1063,    -1,  1594,    -1,   806,    -1,    -1,   806,
      -1,   833,    -1,   429,    -1,   122,    -1,    -1,    -1,    -1,
      -1,  1135,  1137,  1028,   490,  1138,  1200,   453,  1139,   832,
    1140,  1133,  1610,  1141,    -1,   273,    -1,    -1,    -1,   615,
    1143,   832,  1144,  1610,   423,    -1,   239,   928,    -1,   949,
      -1,   949,   931,    -1,   418,  1499,    -1,   526,  1499,    -1,
    1149,    -1,  1150,    -1,  1149,  1150,    -1,  1151,    -1,    -1,
     466,  1152,  1153,    -1,   832,   304,    -1,  1015,    -1,  1132,
      -1,  1147,    -1,    -1,    -1,   703,  1028,  1155,   832,  1156,
    1157,   704,    -1,  1158,    -1,  1157,  1158,    -1,    -1,   705,
    1159,  1610,    -1,    -1,   682,  1028,  1160,  1610,    -1,    -1,
     616,  1162,  1177,  1168,  1163,    -1,   424,    -1,    -1,   296,
    1165,  1610,    -1,    -1,    23,  1169,  1170,  1171,  1027,  1166,
    1610,    -1,    -1,    23,  1169,  1027,  1167,  1610,    -1,  1164,
      -1,  1168,  1164,    -1,    -1,  1104,    -1,    25,    -1,  1184,
      -1,    -1,  1184,    -1,    25,    -1,   313,  1175,    -1,   324,
    1176,    -1,   308,  1176,    -1,   643,    -1,    25,    -1,  1184,
      -1,  1175,    -1,  1176,     5,  1175,    -1,  1184,    -1,    25,
      -1,  1181,  1179,    -1,    -1,   751,  1182,    -1,  1183,    -1,
    1180,    -1,  1050,    -1,  1052,    -1,  1054,    -1,  1046,    -1,
    1048,    -1,   432,   949,   931,    -1,    -1,   127,    -1,   127,
      -1,  1185,    -1,  1187,    -1,   252,  1187,    -1,  1187,   677,
      -1,  1186,  1191,    -1,  1186,  1028,   518,  1194,   486,    -1,
    1186,  1028,   518,  1194,   486,   518,  1194,   486,    -1,  1192,
      -1,  1028,    -1,  1188,    -1,  1028,   517,  1190,   485,    -1,
    1028,   517,  1190,   485,    -1,  1184,    -1,    25,    -1,    20,
      -1,  1028,    -1,  1028,  1193,    -1,   518,  1194,   486,    -1,
     518,  1194,   486,   518,  1194,   486,    -1,  1195,    -1,  1194,
       5,  1195,    -1,   747,    -1,  1197,    -1,  1199,    -1,  1197,
     677,  1198,    -1,  1197,   677,  1028,   518,  1194,   486,    -1,
    1197,   677,  1028,   518,  1194,   486,   518,  1194,   486,    -1,
    1028,    -1,  1189,    -1,    20,    -1,  1028,    -1,  1028,  1193,
      -1,    -1,  1201,    -1,  1203,    -1,  1201,     5,  1203,    -1,
    1204,    -1,  1202,     5,  1204,    -1,  1028,    -1,  1028,   677,
    1028,    -1,  1184,    -1,  1184,   480,  1184,    -1,    25,    -1,
    1034,    -1,    26,    -1,  1206,    -1,  1205,     5,  1206,    -1,
    1184,    -1,  1184,   480,  1184,    -1,  1208,    -1,  1207,     5,
    1208,    -1,  1196,    -1,  1184,    -1,  1211,    -1,  1210,     5,
    1211,    -1,  1184,  1212,    -1,    -1,   645,    -1,   596,    -1,
    1214,    -1,  1213,     5,  1214,    -1,  1184,    -1,  1184,   480,
    1184,    -1,   316,  1024,   675,  1017,   637,  1602,   755,    -1,
      -1,   675,   490,   933,     5,   933,   453,  1217,    -1,    -1,
     626,   490,   933,     5,   933,   453,    -1,   317,  1028,  1216,
      -1,  1028,    -1,   401,  1026,  1221,    -1,  1222,    -1,   604,
     933,    -1,  1223,  1224,  1229,     8,  1219,    -1,    -1,   675,
    1225,   490,   933,     5,   933,   453,    -1,    -1,   614,  1029,
      -1,    -1,   413,    -1,   279,  1541,   327,  1583,  1228,    -1,
     621,  1022,    -1,   621,  1022,     8,   949,   931,    -1,    -1,
     674,   634,  1535,   436,  1535,    -1,   674,   634,  1535,     5,
     436,  1535,    -1,   674,  1535,     5,  1535,    -1,    -1,   706,
      -1,   707,    -1,   455,   683,  1583,  1231,  1232,    -1,    -1,
     674,  1583,    -1,    -1,   674,   634,  1535,     8,  1535,    -1,
     634,  1535,     8,  1535,    -1,   471,  1234,    -1,  1235,    -1,
    1234,     5,  1235,    -1,   264,  1014,    -1,   345,  1014,    -1,
     392,  1014,    -1,   400,  1014,    -1,   354,  1014,    -1,   321,
    1014,    -1,  1106,    -1,   498,  1107,    -1,   509,  1107,    -1,
     619,  1107,    -1,   437,  1107,    -1,   608,  1107,    -1,   606,
    1015,    -1,   607,  1015,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,   461,   751,    -1,   722,   751,    -1,   352,
      -1,   257,    -1,   214,    -1,   194,    -1,   202,    -1,   211,
      -1,   664,  1236,    -1,   738,  1237,    -1,    45,    -1,    46,
      -1,    45,    -1,    46,    -1,  1540,   473,  1241,   604,  1239,
      -1,  1184,    -1,    25,    -1,   463,  1241,    -1,   463,  1241,
       8,  1202,    -1,   463,  1241,   611,  1205,    -1,   463,  1241,
     611,  1205,     8,  1202,    -1,    61,  1239,    -1,  1029,    -1,
      -1,   521,  1251,   750,   653,  1246,  1184,  1244,  1027,   750,
    1243,  1247,    -1,    -1,   725,    26,    -1,   521,  1251,   750,
     407,  1184,    -1,    -1,   380,    -1,    -1,  1248,   343,    -1,
    1249,    -1,  1248,  1249,    -1,    -1,  1102,  1250,  1610,    -1,
     932,    -1,    -1,   661,  1021,  1253,  1254,    -1,    -1,   604,
    1255,    -1,  1256,    -1,  1255,     5,  1256,    -1,  1527,    -1,
     541,    -1,   282,  1261,   151,    -1,   282,  1261,   683,  1259,
      -1,   282,  1261,   149,  1259,    -1,   282,  1261,   150,    -1,
     282,  1261,    38,    -1,   282,  1261,    -1,    42,  1261,   683,
    1239,   674,  1239,     8,  1239,    -1,    42,  1261,   683,  1239,
     674,  1239,    -1,    25,    -1,  1033,    -1,    39,  1261,    -1,
    1028,    -1,    -1,   537,    -1,   210,  1261,  1262,   490,   949,
    1146,   453,    -1,   255,  1261,    -1,   255,  1261,    40,    -1,
     255,  1261,    41,  1239,   674,  1239,     8,  1239,    -1,   255,
    1261,    41,  1239,   674,  1239,    -1,   129,  1261,    -1,  1299,
    1307,    -1,   506,   123,    -1,   506,  1268,    -1,  1269,    -1,
    1268,  1269,    -1,    -1,   198,  1270,  1610,    -1,    -1,   260,
    1271,  1610,    -1,    -1,   290,  1272,  1610,    -1,    -1,   278,
    1273,  1610,    -1,    -1,   315,  1274,  1610,    -1,    -1,   262,
    1184,  1275,  1610,    -1,    -1,   286,  1184,  1276,  1610,    -1,
    1287,    -1,  1291,    -1,  1290,    -1,  1278,    -1,  1316,    -1,
    1281,    -1,    -1,   618,   933,  1279,   540,    -1,    -1,   540,
      -1,    -1,   627,    26,  1282,  1280,    -1,   221,    -1,   686,
    1303,    -1,   224,  1303,    -1,   223,  1303,    -1,    -1,  1284,
      -1,  1285,    -1,  1284,  1285,    -1,  1296,  1286,    -1,    -1,
     675,  1303,    -1,    -1,   577,  1288,  1283,  1295,    -1,  1535,
      -1,   490,  1535,   453,    -1,   576,  1289,  1295,    -1,   575,
    1294,  1293,  1292,  1295,    -1,    -1,   215,   926,    -1,   215,
     926,     5,   926,    -1,   670,    -1,   671,    -1,   672,    -1,
     673,    -1,  1184,    -1,    -1,   580,    -1,  1297,    -1,  1296,
       5,  1297,    -1,   933,  1330,    -1,   666,   490,   926,   453,
    1315,    -1,   126,  1315,    -1,   554,   490,    20,   453,  1315,
      -1,   472,   490,    20,   453,  1315,    -1,   449,   490,   926,
     453,  1315,    -1,   646,   490,   926,   453,  1315,    -1,   659,
     490,   926,   453,  1315,    -1,   658,   490,   926,   453,  1315,
      -1,    -1,   520,  1300,    -1,  1301,    -1,  1300,  1301,    -1,
     289,    26,    -1,   280,    26,    -1,   362,    26,    -1,   246,
      26,    -1,   318,    26,    -1,   237,    -1,   406,    25,    -1,
     406,  1184,    -1,   238,    25,    -1,   222,    25,    -1,  1306,
      -1,  1302,  1306,    -1,  1304,   172,    -1,  1304,   174,    -1,
    1304,   173,    -1,  1304,    -1,  1034,    -1,    26,    -1,    -1,
     520,  1302,    -1,   289,  1303,    -1,   280,  1303,    -1,   362,
    1303,    -1,   246,  1303,    -1,   318,  1303,    -1,   319,  1303,
      -1,   685,    25,    -1,   686,  1303,    -1,   690,    -1,   687,
      -1,   688,    -1,   689,    -1,   694,    -1,   691,    -1,   692,
      -1,   693,    -1,   138,  1303,    -1,   139,  1303,    -1,   140,
    1303,    -1,   406,    25,    -1,   238,    25,    -1,   460,    -1,
     135,    -1,   136,    -1,    -1,   572,   676,  1210,    -1,   199,
    1210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,  1309,
    1028,   490,  1310,  1200,   453,  1311,   832,  1312,  1266,  1313,
    1267,  1314,   301,    -1,    -1,   584,   926,    -1,   574,  1317,
      -1,    -1,  1239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,  1319,  1028,   490,  1320,  1200,   453,  1321,   832,  1322,
    1325,  1323,  1267,  1324,   301,    -1,  1305,  1307,    -1,    -1,
      -1,    -1,   217,   490,    25,     5,  1327,   779,  1328,   453,
    1329,   777,    -1,    -1,   445,    -1,   445,   280,    26,    -1,
     445,   280,  1184,    -1,   664,   933,    -1,   664,   933,  1332,
      -1,   664,   933,   407,  1184,    -1,   664,   933,   225,    -1,
     664,   933,  1332,   407,  1184,    -1,   664,   933,  1332,   225,
      -1,   664,   933,   635,    -1,   664,   933,   602,    -1,    46,
      -1,    45,    -1,  1334,    -1,   234,  1484,    -1,   386,  1484,
      -1,   342,  1485,    -1,    58,  1028,    -1,  1348,    -1,  1336,
      -1,    -1,    -1,   267,  1337,  1484,   490,  1338,  1352,   453,
    1341,    -1,    -1,    -1,   196,  1339,  1484,   490,  1340,  1352,
     453,  1341,  1349,    -1,    -1,  1342,    -1,  1343,    -1,  1342,
    1343,    -1,   680,  1344,    -1,   306,    26,    -1,    70,    26,
      -1,   147,    -1,   148,    -1,  1609,    -1,    -1,  1346,    -1,
    1347,    -1,  1346,  1347,    -1,   680,  1344,    -1,   734,    26,
      -1,   167,  1485,   682,  1484,   490,  1350,   453,  1345,    -1,
     113,  1029,    -1,   114,  1029,    -1,   233,  1484,   653,  1484,
      -1,   118,  1484,    -1,    -1,   329,    -1,  1351,    -1,  1350,
       5,  1351,    -1,  1028,   645,    -1,  1028,   596,    -1,  1028,
      -1,  1353,    -1,  1352,     5,  1353,    -1,  1436,    -1,  1434,
      -1,   183,  1028,    -1,   241,    -1,    68,  1028,  1356,    -1,
      69,  1485,   164,    -1,    69,  1485,   165,    -1,  1357,    -1,
    1356,     5,  1357,    -1,  1358,    -1,  1361,    -1,  1364,    -1,
    1369,    -1,  1372,    -1,  1368,    -1,  1367,    -1,   642,  1359,
      -1,   642,   490,  1360,   453,    -1,  1353,    -1,  1353,   721,
    1028,    -1,  1359,    -1,  1360,     5,  1359,    -1,   599,  1363,
      -1,   599,   490,  1362,   453,    -1,  1363,    -1,  1362,     5,
    1363,    -1,  1028,    -1,   514,  1366,    -1,   514,   490,  1365,
     453,    -1,  1366,    -1,  1365,     5,  1366,    -1,  1353,    -1,
     147,    -1,   148,    -1,   146,    26,    -1,   116,  1434,  1371,
      -1,   116,   490,  1370,   453,    -1,  1434,  1371,    -1,  1370,
       5,  1434,  1371,    -1,    -1,   119,  1028,    -1,   117,  1373,
      -1,   117,   490,  1373,   453,    -1,  1374,    -1,  1373,     5,
    1374,    -1,  1028,    -1,   326,    -1,   293,    -1,   227,  1377,
      -1,   206,    -1,   195,    -1,   182,    -1,   180,    -1,   184,
      -1,   240,  1541,    -1,   292,  1376,   519,  1535,   683,  1535,
      -1,   359,  1021,   519,  1535,   683,  1535,    -1,    -1,  1541,
      -1,    -1,   933,    -1,   581,   933,    -1,   291,    -1,    -1,
     310,  1381,  1484,  1384,  1382,    -1,    -1,   537,  1383,   490,
    1386,   453,    -1,  1521,    -1,    -1,   490,  1385,   453,    -1,
    1488,    -1,  1385,     5,  1488,    -1,  1387,    -1,  1386,     5,
    1387,    -1,  1527,    -1,   541,    -1,    -1,   558,  1389,  1391,
    1392,    -1,  1029,    -1,  1396,  1022,    -1,  1022,    -1,    -1,
      -1,   611,  1393,  1205,    -1,    -1,    -1,   611,  1395,  1205,
      -1,   559,    -1,   612,    -1,   619,    -1,   437,    -1,   404,
      -1,   456,    -1,   440,   933,    -1,   413,   933,    -1,   299,
    1484,   212,  1022,    -1,   299,  1484,  1457,    -1,   572,   676,
    1400,    -1,  1401,    -1,  1400,     5,  1401,    -1,  1402,  1403,
      -1,    26,    -1,  1488,    -1,    -1,   645,    -1,   596,    -1,
     337,    -1,   370,    -1,    -1,   389,    -1,   418,  1408,  1406,
      -1,  1583,    -1,  1583,   669,  1028,    -1,    25,    -1,    -1,
    1540,  1410,  1411,    -1,  1442,    -1,    37,    -1,  1446,    -1,
    1405,    -1,  1542,    -1,  1404,    -1,  1397,    -1,  1398,    -1,
    1388,    -1,  1380,    -1,  1379,    -1,  1511,    -1,  1563,    -1,
     563,  1415,   682,  1484,   683,  1420,  1414,    -1,   525,  1415,
     682,  1484,   604,  1420,    -1,   563,  1413,   683,  1420,    -1,
     525,  1413,   604,  1420,    -1,   455,    -1,   441,    -1,   649,
      -1,    -1,   205,    -1,   674,  1028,    -1,   229,    -1,   643,
      -1,  1416,    -1,  1417,    -1,  1416,     5,  1417,    -1,   530,
    1418,    -1,   509,    -1,   498,    -1,   536,  1418,    -1,   544,
      -1,   566,    -1,    -1,   490,  1419,   453,    -1,  1488,    -1,
    1419,     5,  1488,    -1,  1421,    -1,  1420,     5,  1421,    -1,
     522,    -1,  1486,    -1,   297,  1484,  1423,   674,  1521,  1425,
      -1,    -1,   490,  1424,   453,    -1,  1488,    -1,  1424,     5,
    1488,    -1,    -1,   204,    -1,   550,   490,  1460,   453,    -1,
     307,   490,  1429,   453,  1428,    -1,   357,  1430,    -1,  1431,
      -1,  1484,    -1,  1484,   490,  1431,   453,    -1,  1488,    -1,
    1431,     5,  1488,    -1,   534,   490,  1433,   453,    -1,   421,
     490,  1433,   453,    -1,   320,   490,  1433,   453,    -1,  1488,
      -1,  1433,     5,  1488,    -1,  1432,    -1,  1427,    -1,  1426,
      -1,   460,  1491,    -1,   270,    -1,   269,    -1,   268,    -1,
    1028,  1476,  1437,  1438,    -1,    -1,  1435,    -1,    -1,  1439,
      -1,  1440,    -1,  1439,  1440,    -1,  1441,  1371,    -1,   435,
      -1,   220,    -1,   534,    -1,   421,    -1,  1428,    -1,   550,
     490,  1460,   453,    -1,   320,    -1,   181,  1443,  1445,    -1,
    1444,    -1,  1486,    -1,  1446,    -1,  1445,  1446,    -1,  1422,
      -1,  1412,    -1,   507,  1460,    -1,   430,  1449,    -1,  1526,
      -1,  1449,     5,  1526,    -1,   584,  1460,    -1,   604,  1452,
      -1,  1453,    -1,  1452,     5,  1453,    -1,  1454,    -1,   573,
    1454,    -1,   573,   490,  1455,   453,    -1,  1484,    -1,  1484,
    1490,    -1,  1484,   674,  1490,    -1,  1453,    -1,  1455,     5,
    1453,    -1,  1451,  1457,  1458,  1459,    -1,    -1,  1450,    -1,
      -1,  1448,    -1,    -1,  1447,    -1,  1461,    -1,  1460,     6,
    1461,    -1,  1462,    -1,  1461,     7,  1462,    -1,  1463,    -1,
       9,  1463,    -1,  1474,    -1,   490,  1460,   453,    -1,   502,
    1522,    -1,   355,  1522,    -1,    -1,   501,  1467,    -1,  1528,
      -1,  1531,    -1,  1527,   680,   490,  1469,   453,    -1,  1527,
     680,  1522,    -1,  1527,   488,   490,  1469,   453,    -1,  1527,
     488,  1522,    -1,  1470,    -1,  1469,     5,  1470,    -1,  1589,
      -1,  1491,    -1,    -1,     9,    -1,  1527,  1471,   448,    -1,
    1527,  1471,   311,    -1,  1527,  1473,  1527,    -1,  1527,  1471,
     450,  1527,     7,  1527,    -1,  1527,   614,  1466,  1465,    -1,
    1527,   433,  1466,  1465,    -1,  1527,   731,  1466,  1465,    -1,
    1527,   434,  1466,  1465,    -1,  1527,  1471,    10,  1466,  1465,
      -1,    14,    -1,    17,    -1,    12,    -1,    13,    -1,   730,
      -1,    16,    -1,    15,    -1,  1472,    -1,  1468,    -1,  1464,
      -1,    -1,   643,    -1,   421,    -1,   534,    -1,  1477,    -1,
    1478,    -1,  1480,    -1,   380,    -1,   380,   490,  1481,   453,
      -1,    -1,   531,    -1,   531,   490,    26,   453,    -1,   458,
      -1,   458,   490,  1482,  1479,   453,    -1,   570,   490,  1482,
    1479,   453,    -1,   570,    -1,   595,    -1,   468,    -1,   442,
      -1,   381,    -1,   381,   490,  1481,   453,    -1,   382,    -1,
     382,   490,    26,   453,    -1,   382,   490,    26,     5,    26,
     453,    -1,   419,  1497,   683,  1498,    -1,   419,    -1,   431,
    1497,   683,  1498,    -1,   431,    -1,   431,  1497,   490,    26,
     453,   683,  1498,    -1,   632,    -1,   591,    -1,   483,    -1,
     483,   490,    26,   453,    -1,   483,   490,    26,     5,    26,
     453,    -1,    -1,     5,  1483,    -1,   560,   490,  1482,   453,
      -1,   623,    -1,   360,    -1,   560,    -1,   125,    -1,    26,
      -1,    26,    -1,    26,    -1,    25,   677,  1028,    -1,    25,
      -1,  1028,    -1,  1028,   647,  1028,    -1,  1028,   647,    25,
     677,  1028,    -1,  1028,   669,  1028,    -1,  1028,   669,  1028,
     647,  1028,    -1,  1028,   669,  1028,   647,    25,   677,  1028,
      -1,    25,   677,  1028,    -1,    25,    -1,  1028,    -1,  1028,
     647,  1028,    -1,  1028,   647,    25,   677,  1028,    -1,  1028,
     669,  1028,    -1,  1028,   669,  1028,   647,  1028,    -1,  1028,
     669,  1028,   647,    25,   677,  1028,    -1,  1028,    -1,    -1,
     518,    26,   486,    -1,   518,    26,     5,    26,   486,    -1,
    1489,    -1,   669,  1489,    -1,  1028,  1487,    -1,  1484,   677,
    1028,  1487,    -1,  1484,   677,    20,    -1,  1028,    -1,    25,
      -1,  1034,    -1,    26,    -1,  1493,    -1,   456,  1495,    -1,
     456,  1494,    -1,    -1,  1497,   683,  1498,    -1,    -1,  1496,
     683,  1496,    -1,   639,    -1,   571,    -1,   648,    -1,   610,
      -1,   513,    -1,   529,    -1,   428,    -1,   428,   490,    26,
     453,    -1,   639,    -1,   571,    -1,   648,    -1,   610,    -1,
     513,    -1,   529,    -1,   428,    -1,   639,    -1,   571,    -1,
     648,    -1,   610,    -1,   513,    -1,   529,    -1,   428,    -1,
     428,   490,    26,   453,    -1,  1028,    -1,  1028,   669,  1028,
      -1,    25,    -1,  1540,   561,  1022,    -1,    -1,  1540,   459,
    1390,   496,   653,  1509,  1502,    -1,    -1,  1540,   459,  1390,
     496,   162,   653,  1510,  1503,    -1,    -1,  1540,   459,  1390,
     200,  1510,  1504,    -1,    -1,  1540,   459,  1390,   201,   162,
     653,  1510,  1505,    -1,    -1,   349,    -1,   348,  1507,    -1,
    1508,    -1,  1507,     5,  1508,    -1,  1028,    -1,  1028,   677,
    1028,    -1,    25,   677,  1028,   677,  1028,    -1,  1510,    -1,
    1380,    -1,  1241,    -1,  1512,    -1,  1512,    -1,    -1,    -1,
     530,  1523,  1513,  1524,  1514,  1520,  1456,  1518,  1506,    -1,
     530,  1523,  1524,  1456,  1518,    -1,  1517,    -1,  1535,    -1,
     530,  1523,  1524,  1520,  1456,  1518,    -1,    -1,   583,  1475,
    1516,    -1,  1399,    -1,   394,  1519,  1349,    -1,  1399,   394,
    1519,  1349,    -1,  1028,    -1,    -1,   611,  1205,    -1,   530,
    1523,  1524,  1456,    -1,   490,   530,  1523,  1524,  1456,   453,
      -1,    -1,   643,    -1,   421,    -1,   534,    -1,  1525,    -1,
    1524,     5,  1525,    -1,  1527,    -1,  1527,  1028,    -1,  1527,
     674,  1028,    -1,  1527,    -1,  1528,    -1,    19,  1528,    -1,
      18,  1528,    -1,  1529,    -1,  1589,    -1,  1522,    -1,   643,
    1522,    -1,   644,  1522,    -1,   628,  1522,    -1,   669,  1028,
      -1,   669,  1028,   677,  1028,    -1,  1528,    21,  1527,    -1,
    1528,  1549,    -1,  1528,    20,  1527,    -1,  1528,    18,  1527,
      -1,  1528,    19,  1527,    -1,  1491,    -1,   542,    -1,   487,
      -1,   634,    -1,    20,    -1,   126,    -1,   646,   490,  1475,
    1527,   453,    -1,   658,   490,  1475,  1527,   453,    -1,   659,
     490,  1475,  1527,   453,    -1,   666,   490,  1475,  1527,   453,
      -1,   554,   490,  1475,  1527,   453,    -1,  1028,   490,  1530,
     453,    -1,   595,   490,  1530,   453,    -1,   490,  1527,   453,
      -1,   503,   490,  1550,   453,    -1,  1551,    -1,  1553,    -1,
    1527,    -1,  1530,     5,  1527,    -1,  1491,    -1,  1540,   409,
    1539,  1534,  1516,    -1,  1540,   398,  1539,  1534,   310,  1484,
    1536,    -1,  1540,   398,  1539,  1534,  1184,    -1,    -1,   384,
    1535,    -1,    25,    -1,  1184,    -1,    -1,   490,  1537,   453,
      -1,  1538,    -1,  1537,     5,  1538,    -1,  1028,    -1,    25,
      -1,  1184,    -1,    -1,   328,  1541,   653,    -1,  1029,    -1,
    1547,    -1,  1546,    -1,  1543,    -1,   377,  1544,   683,  1544,
      -1,   358,  1484,   677,  1545,   683,  1545,    -1,  1028,    -1,
    1028,    -1,   283,  1484,    -1,   353,  1484,  1548,    -1,   332,
      -1,   236,    -1,   154,    -1,   155,    -1,   156,    -1,   157,
      -1,   158,    -1,   159,    -1,   456,     5,  1497,   683,  1498,
      -1,  1589,     5,  1497,   683,  1498,    -1,   456,  1497,   683,
    1498,    -1,  1527,     5,  1497,   683,  1498,    -1,  1552,    -1,
    1552,  1497,   683,  1498,    -1,    43,    -1,  1554,    -1,  1554,
    1497,   490,    26,   453,   683,  1498,    -1,  1554,  1497,   683,
    1498,    -1,    44,    -1,    -1,   665,  1556,  1557,   251,    -1,
    1558,    -1,  1557,  1558,    -1,    33,    -1,  1559,    -1,  1561,
      -1,    -1,   252,  1560,  1589,    -1,    -1,   611,  1562,  1205,
      -1,    -1,    -1,   536,  1484,  1564,  1567,  1565,  1566,    -1,
      -1,   212,  1022,    -1,   584,  1460,    -1,   111,  1571,   453,
      14,   490,  1572,   453,    -1,   107,  1572,   453,    -1,   108,
    1572,   453,    -1,   641,  1568,    -1,   110,  1572,    -1,   109,
    1572,    -1,  1570,    -1,  1568,     5,  1570,    -1,  1488,    -1,
    1569,    14,  1573,    -1,  1569,    -1,  1571,     5,  1569,    -1,
    1573,    -1,  1572,     5,  1573,    -1,   541,    -1,  1574,    -1,
    1575,    -1,    19,  1575,    -1,    18,  1575,    -1,  1577,    -1,
    1522,    -1,   669,  1028,    -1,   669,  1028,   677,  1028,    -1,
     669,  1028,   518,    26,   486,    -1,   669,  1028,   677,  1028,
     518,    26,   486,    -1,   669,  1028,   518,    26,     5,    26,
     486,    -1,   669,  1028,   677,  1028,   518,    26,     5,    26,
     486,    -1,  1576,    -1,  1491,    -1,   542,    -1,   487,    -1,
     634,    -1,   126,    -1,  1575,    21,  1574,    -1,  1575,  1549,
      -1,  1575,    20,  1574,    -1,  1575,    18,  1574,    -1,  1575,
      19,  1574,    -1,   646,   490,  1475,  1574,   453,    -1,   658,
     490,  1475,  1574,   453,    -1,   659,   490,  1475,  1574,   453,
      -1,   666,   490,  1475,  1574,   453,    -1,   554,   490,  1475,
    1574,   453,    -1,  1028,   490,  1578,   453,    -1,   595,   490,
    1578,   453,    -1,   490,  1574,   453,    -1,   503,   490,  1550,
     453,    -1,  1551,    -1,  1553,    -1,  1589,    -1,  1574,    -1,
    1578,     5,  1574,    -1,    -1,   443,  1213,   614,  1580,  1581,
      -1,  1582,    -1,  1581,     5,  1582,    -1,  1484,   677,  1488,
      -1,  1484,   677,    20,    -1,  1585,    -1,  1585,    -1,   252,
    1586,    -1,  1586,    -1,  1587,    -1,    25,   677,  1587,    -1,
    1588,    -1,  1587,   677,  1588,    -1,  1587,   677,    20,    -1,
    1590,    -1,  1028,    -1,  1584,    -1,  1584,   480,  1584,    -1,
    1028,  1591,    -1,   518,  1592,   486,    -1,   518,  1592,   486,
     518,  1592,   486,    -1,  1593,    -1,  1592,     5,  1593,    -1,
     747,    -1,    34,    -1,    -1,    -1,   585,  1596,   933,  1597,
    1610,   388,    -1,    -1,   716,   976,    -1,    -1,   719,    -1,
     243,    -1,   338,  1023,    -1,   131,  1023,    -1,   368,    -1,
     367,    -1,   369,  1025,  1598,  1599,    -1,   551,   976,  1599,
      -1,   166,    -1,   197,  1023,    -1,   933,   624,     5,   933,
     454,    -1,   567,   933,    -1,   325,  1023,    -1,   163,  1605,
       8,  1606,  1604,    -1,    -1,   604,   933,    -1,  1028,    -1,
    1028,    -1,   309,  1023,    -1,   312,  1023,   683,   933,     5,
     933,    -1,   312,  1023,   676,   933,     5,   933,    -1,    27,
      -1,    -1,  1612,    -1,  1613,  1295,    -1,  1611,    -1,  1612,
    1611,    -1,    -1,  1614,  1615,    -1,   740,    -1,   741,    -1,
     742,    -1,   743,    -1,   760,    -1,   784,    -1,   805,    -1,
     806,    -1,   812,    -1,   831,    -1,   905,    -1,   906,    -1,
     907,    -1,   908,    -1,   919,    -1,   920,    -1,   921,    -1,
     922,    -1,   923,    -1,   924,    -1,   925,    -1,   978,    -1,
    1009,    -1,  1013,    -1,  1035,    -1,  1037,    -1,  1040,    -1,
    1041,    -1,  1042,    -1,  1043,    -1,  1056,    -1,  1066,    -1,
    1090,    -1,  1091,    -1,  1093,    -1,  1097,    -1,  1112,    -1,
    1113,    -1,  1117,    -1,  1118,    -1,  1119,    -1,  1120,    -1,
    1130,    -1,  1145,    -1,  1161,    -1,  1172,    -1,  1173,    -1,
    1174,    -1,  1178,    -1,  1215,    -1,  1218,    -1,  1220,    -1,
    1226,    -1,  1227,    -1,  1230,    -1,  1233,    -1,  1238,    -1,
    1240,    -1,  1242,    -1,  1245,    -1,  1252,    -1,  1257,    -1,
    1258,    -1,  1260,    -1,  1263,    -1,  1264,    -1,  1265,    -1,
    1277,    -1,  1331,    -1,  1333,    -1,  1335,    -1,  1354,    -1,
    1355,    -1,  1375,    -1,  1378,    -1,  1407,    -1,  1409,    -1,
    1500,    -1,  1501,    -1,  1532,    -1,  1533,    -1,  1555,    -1,
    1579,    -1,  1594,    -1,  1595,    -1,  1600,    -1,  1601,    -1,
    1603,    -1,  1607,    -1,  1608,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1015,  1015,  1018,  1021,  1027,  1033,  1040,  1044,  1044,
    1050,  1069,  1070,  1071,  1072,  1073,  1084,  1090,  1091,  1092,
    1093,  1094,  1099,  1100,  1111,  1114,  1117,  1117,  1121,  1124,
    1125,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1150,  1151,
    1154,  1154,  1169,  1170,  1173,  1179,  1181,  1192,  1194,  1196,
    1198,  1202,  1204,  1266,  1270,  1274,  1274,  1284,  1288,  1291,
    1292,  1301,  1307,  1301,  1321,  1327,  1321,  1343,  1348,  1352,
    1343,  1364,  1368,  1364,  1376,  1381,  1376,  1400,  1407,  1411,
    1399,  1437,  1437,  1441,  1442,  1443,  1448,  1451,  1456,  1460,
    1468,  1469,  1472,  1472,  1478,  1482,  1497,  1495,  1513,  1513,
    1528,  1528,  1531,  1531,  1535,  1538,  1538,  1538,  1545,  1546,
    1545,  1553,  1553,  1564,  1564,  1577,  1601,  1609,  1577,  1625,
    1630,  1638,  1639,  1643,  1653,  1656,  1659,  1662,  1665,  1668,
    1681,  1686,  1686,  1687,  1687,  1690,  1695,  1695,  1699,  1718,
    1723,  1717,  1734,  1740,  1748,  1749,  1752,  1752,  1755,  1759,
    1764,  1771,  1771,  1775,  1775,  1776,  1776,  1777,  1777,  1778,
    1778,  1779,  1779,  1787,  1791,  1797,  1801,  1816,  1819,  1822,
    1825,  1828,  1831,  1837,  1848,  1853,  1866,  1870,  1885,  1886,
    1890,  1890,  1894,  1894,  1894,  1895,  1900,  1900,  1903,  1903,
    1912,  1913,  1914,  1917,  1921,  1922,  1922,  1939,  1939,  1939,
    1939,  1943,  1950,  1951,  1954,  1954,  1958,  1959,  1960,  1961,
    1966,  1966,  1972,  1972,  1981,  1978,  1994,  1994,  1996,  1996,
    1998,  2000,  2002,  2004,  2007,  2012,  2013,  2015,  2020,  2020,
    2021,  2021,  2025,  2025,  2037,  2037,  2042,  2046,  2048,  2049,
    2052,  2052,  2052,  2056,  2057,  2058,  2059,  2060,  2061,  2062,
    2063,  2064,  2065,  2066,  2067,  2070,  2071,  2072,  2073,  2077,
    2082,  2087,  2091,  2094,  2098,  2098,  2099,  2099,  2100,  2100,
    2101,  2102,  2103,  2104,  2105,  2106,  2109,  2110,  2111,  2141,
    2141,  2146,  2151,  2153,  2153,  2160,  2164,  2164,  2168,  2169,
    2170,  2171,  2172,  2173,  2174,  2180,  2180,  2183,  2185,  2191,
    2193,  2199,  2207,  2207,  2210,  2211,  2212,  2213,  2214,  2215,
    2216,  2222,  2225,  2225,  2238,  2238,  2245,  2246,  2247,  2249,
    2250,  2251,  2255,  2256,  2257,  2258,  2263,  2269,  2275,  2276,
    2278,  2280,  2281,  2282,  2283,  2284,  2285,  2288,  2289,  2296,
    2304,  2304,  2312,  2309,  2324,  2324,  2326,  2326,  2334,  2334,
    2337,  2340,  2341,  2346,  2358,  2362,  2365,  2368,  2369,  2370,
    2371,  2372,  2377,  2384,  2390,  2395,  2400,  2395,  2413,  2415,
    2420,  2425,  2425,  2425,  2429,  2429,  2432,  2432,  2439,  2439,
    2446,  2446,  2457,  2475,  2481,  2505,  2508,  2523,  2526,  2539,
    2541,  2543,  2545,  2547,  2549,  2551,  2557,  2559,  2563,  2565,
    2567,  2569,  2571,  2573,  2575,  2581,  2598,  2599,  2600,  2601,
    2605,  2606,  2607,  2611,  2616,  2623,  2624,  2625,  2626,  2627,
    2628,  2629,  2630,  2631,  2632,  2633,  2640,  2640,  2645,  2645,
    2648,  2654,  2662,  2668,  2678,  2679,  2687,  2708,  2712,  2717,
    2722,  2724,  2727,  2745,  2750,  2756,  2761,  2766,  2767,  2773,
    2844,  2855,  2864,  2872,  2872,  2887,  2891,  2898,  2901,  2909,
    2913,  2916,  2922,  2931,  2936,  2944,  2947,  2950,  2955,  2962,
    2967,  2972,  2977,  2987,  2995,  3003,  3008,  3012,  3017,  3021,
    3025,  3032,  3035,  3038,  3042,  3046,  3050,  3054,  3062,  3072,
    3077,  3070,  3092,  3097,  3092,  3111,  3116,  3111,  3137,  3137,
    3137,  3140,  3140,  3140,  3144,  3144,  3144,  3148,  3148,  3148,
    3152,  3158,  3164,  3170,  3178,  3184,  3192,  3198,  3207,  3213,
    3220,  3227,  3236,  3242,  3248,  3255,  3261,  3267,  3273,  3281,
    3287,  3293,  3302,  3308,  3314,  3324,  3324,  3328,  3332,  3333,
    3344,  3345,  3351,  3361,  3371,  3381,  3382,  3385,  3390,  3396,
    3400,  3404,  3407,  3413,  3416,  3419,  3436,  3439,  3445,  3446,
    3447,  3451,  3452,  3453,  3454,  3455,  3457,  3458,  3459,  3461,
    3462,  3463,  3467,  3468,  3473,  3477,  3482,  3486,  3501,  3505,
    3511,  3500,  3524,  3525,  3537,  3543,  3537,  3557,  3557,  3559,
    3560,  3564,  3564,  3568,  3568,  3573,  3573,  3580,  3581,  3585,
    3585,  3589,  3589,  3594,  3594,  3601,  3605,  3606,  3607,  3612,
    3612,  3615,  3615,  3619,  3619,  3623,  3623,  3627,  3627,  3632,
    3632,  3637,  3637,  3642,  3642,  3647,  3647,  3663,  3667,  3662,
    3675,  3678,  3692,  3709,  3710,  3711,  3712,  3713,  3714,  3715,
    3718,  3718,  3721,  3723,  3726,  3729,  3732,  3737,  3742,  3745,
    3750,  3755,  3760,  3767,  3768,  3775,  3782,  3784,  3790,  3795,
    3800,  3805,  3805,  3808,  3814,  3819,  3822,  3829,  3829,  3831,
    3834,  3837,  3842,  3847,  3852,  3859,  3870,  3870,  3932,  3940,
    3941,  3949,  3956,  3956,  3960,  3965,  3971,  3975,  3979,  3985,
    3989,  3993,  3999,  3999,  4007,  4008,  4012,  4012,  4016,  4017,
    4020,  4023,  4023,  4026,  4028,  4028,  4031,  4033,  4033,  4034,
    4036,  4036,  4045,  4052,  4043,  4073,  4073,  4073,  4076,  4078,
    4076,  4085,  4088,  4095,  4100,  4111,  4111,  4115,  4121,  4121,
    4125,  4126,  4130,  4140,  4141,  4142,  4145,  4147,  4152,  4152,
    4156,  4155,  4163,  4162,  4169,  4169,  4175,  4175,  4182,  4182,
    4188,  4188,  4194,  4194,  4200,  4200,  4204,  4204,  4205,  4205,
    4206,  4206,  4207,  4207,  4211,  4211,  4222,  4226,  4232,  4236,
    4241,  4246,  4251,  4252,  4253,  4257,  4256,  4269,  4274,  4279,
    4279,  4295,  4301,  4302,  4303,  4304,  4305,  4315,  4329,  4329,
    4332,  4339,  4340,  4341,  4342,  4343,  4344,  4345,  4346,  4347,
    4352,  4352,  4354,  4357,  4357,  4359,  4363,  4366,  4367,  4370,
    4370,  4375,  4378,  4379,  4380,  4381,  4382,  4383,  4384,  4385,
    4386,  4387,  4388,  4389,  4390,  4391,  4392,  4393,  4394,  4395,
    4399,  4417,  4417,  4417,  4444,  4455,  4462,  4468,  4474,  4480,
    4492,  4515,  4516,  4519,  4523,  4522,  4540,  4540,  4544,  4545,
    4553,  4554,  4555,  4556,  4557,  4558,  4559,  4566,  4567,  4569,
    4570,  4574,  4579,  4580,  4581,  4582,  4583,  4584,  4585,  4586,
    4587,  4590,  4592,  4592,  4594,  4598,  4598,  4607,  4613,  4629,
    4635,  4606,  4649,  4663,  4674,  4662,  4687,  4694,  4694,  4699,
    4705,  4713,  4718,  4719,  4722,  4725,  4725,  4733,  4739,  4750,
    4751,  4759,  4765,  4759,  4776,  4777,  4781,  4781,  4788,  4788,
    4803,  4803,  4817,  4828,  4827,  4839,  4835,  4852,  4849,  4862,
    4862,  4864,  4865,  4867,  4868,  4871,  4872,  4873,  4875,  4880,
    4885,  4891,  4893,  4894,  4897,  4898,  4901,  4903,  4910,  4913,
    4916,  4919,  4923,  4927,  4928,  4929,  4930,  4931,  4935,  4940,
    4940,  4943,  4970,  5028,  5028,  5031,  5035,  5039,  5082,  5124,
    5125,  5126,  5129,  5143,  5155,  5155,  5160,  5161,  5167,  5232,
    5237,  5244,  5249,  5257,  5263,  5296,  5299,  5300,  5341,  5384,
    5385,  5389,  5390,  5394,  5447,  5452,  5456,  5461,  5472,  5479,
    5487,  5487,  5490,  5491,  5492,  5493,  5494,  5497,  5500,  5506,
    5509,  5513,  5518,  5526,  5531,  5538,  5540,  5546,  5548,  5548,
    5548,  5568,  5575,  5582,  5585,  5599,  5606,  5607,  5610,  5611,
    5615,  5621,  5626,  5632,  5633,  5638,  5642,  5642,  5646,  5647,
    5650,  5651,  5655,  5663,  5666,  5672,  5673,  5675,  5677,  5681,
    5681,  5682,  5687,  5695,  5696,  5701,  5702,  5704,  5717,  5719,
    5720,  5723,  5724,  5725,  5726,  5727,  5728,  5729,  5730,  5731,
    5732,  5733,  5734,  5735,  5736,  5737,  5738,  5739,  5740,  5741,
    5742,  5743,  5744,  5745,  5746,  5747,  5748,  5749,  5750,  5754,
    5755,  5759,  5760,  5774,  5782,  5782,  5784,  5788,  5792,  5796,
    5800,  5805,  5820,  5818,  5838,  5839,  5843,  5848,  5849,  5853,
    5854,  5856,  5857,  5859,  5859,  5868,  5877,  5877,  5887,  5888,
    5893,  5894,  5897,  5910,  5924,  5928,  5932,  5936,  5940,  5944,
    5954,  5957,  5962,  5962,  5966,  5971,  5974,  5974,  5976,  5982,
    5987,  5992,  5997,  6006,  6012,  6014,  6018,  6021,  6021,  6024,
    6024,  6029,  6029,  6038,  6038,  6042,  6042,  6043,  6043,  6044,
    6044,  6058,  6058,  6078,  6079,  6080,  6081,  6082,  6083,  6086,
    6086,  6092,  6092,  6095,  6095,  6111,  6112,  6113,  6122,  6134,
    6135,  6138,  6139,  6142,  6145,  6145,  6150,  6150,  6173,  6174,
    6180,  6185,  6191,  6192,  6193,  6197,  6198,  6199,  6200,  6204,
    6214,  6216,  6221,  6224,  6229,  6235,  6242,  6249,  6258,  6265,
    6272,  6279,  6286,  6295,  6295,  6297,  6297,  6300,  6301,  6302,
    6303,  6304,  6305,  6306,  6307,  6308,  6309,  6312,  6312,  6315,
    6316,  6317,  6318,  6321,  6321,  6324,  6324,  6327,  6328,  6329,
    6330,  6331,  6332,  6333,  6334,  6336,  6337,  6338,  6339,  6341,
    6342,  6343,  6344,  6346,  6347,  6348,  6349,  6350,  6351,  6352,
    6353,  6357,  6365,  6375,  6388,  6399,  6410,  6414,  6418,  6424,
    6387,  6437,  6440,  6448,  6460,  6462,  6467,  6477,  6487,  6490,
    6494,  6502,  6466,  6511,  6515,  6519,  6523,  6515,  6533,  6534,
    6535,  6536,  6541,  6542,  6543,  6544,  6545,  6546,  6547,  6548,
    6552,  6553,  6556,  6561,  6568,  6569,  6570,  6575,  6576,  6582,
    6582,  6582,  6587,  6587,  6587,  6595,  6596,  6600,  6601,  6606,
    6607,  6608,  6609,  6610,  6613,  6615,  6615,  6618,  6619,  6623,
    6624,  6627,  6628,  6631,  6634,  6637,  6643,  6644,  6656,  6657,
    6662,  6663,  6664,  6668,  6671,  6677,  6680,  6688,  6689,  6695,
    6699,  6703,  6709,  6712,  6721,  6724,  6727,  6730,  6733,  6736,
    6739,  6746,  6749,  6756,  6759,  6765,  6768,  6775,  6778,  6785,
    6786,  6791,  6795,  6798,  6804,  6807,  6813,  6820,  6821,  6825,
    6835,  6838,  6844,  6846,  6851,  6852,  6856,  6858,  6864,  6865,
    6878,  6890,  6891,  6892,  6893,  6894,  6895,  6896,  6897,  6898,
    6901,  6904,  6910,  6910,  6916,  6916,  6927,  6940,  6950,  6950,
    6955,  6955,  6959,  6963,  6964,  6970,  6971,  6976,  6980,  6987,
    6990,  6997,  6996,  7007,  7011,  7015,  7022,  7025,  7025,  7038,
    7042,  7042,  7057,  7059,  7061,  7063,  7065,  7067,  7069,  7071,
    7077,  7087,  7094,  7099,  7100,  7104,  7107,  7108,  7111,  7112,
    7113,  7116,  7121,  7128,  7129,  7136,  7148,  7149,  7150,  7153,
    7153,  7158,  7163,  7168,  7173,  7174,  7177,  7178,  7183,  7188,
    7192,  7197,  7198,  7202,  7209,  7210,  7211,  7212,  7217,  7218,
    7219,  7222,  7223,  7224,  7228,  7229,  7230,  7234,  7235,  7239,
    7240,  7241,  7242,  7243,  7244,  7247,  7248,  7253,  7254,  7259,
    7260,  7265,  7266,  7271,  7276,  7277,  7282,  7283,  7287,  7288,
    7293,  7300,  7305,  7310,  7314,  7315,  7320,  7321,  7327,  7330,
    7334,  7339,  7340,  7346,  7349,  7352,  7359,  7360,  7361,  7362,
    7376,  7381,  7382,  7385,  7387,  7394,  7397,  7403,  7411,  7415,
    7419,  7423,  7428,  7431,  7434,  7441,  7448,  7453,  7457,  7458,
    7464,  7467,  7478,  7485,  7491,  7494,  7501,  7508,  7514,  7515,
    7521,  7522,  7523,  7526,  7527,  7534,  7541,  7541,  7545,  7553,
    7554,  7557,  7560,  7565,  7566,  7571,  7574,  7580,  7583,  7589,
    7592,  7598,  7601,  7608,  7609,  7638,  7639,  7643,  7651,  7656,
    7659,  7662,  7665,  7671,  7672,  7676,  7679,  7682,  7683,  7688,
    7691,  7694,  7697,  7700,  7703,  7706,  7709,  7714,  7720,  7721,
    7722,  7723,  7726,  7727,  7728,  7733,  7736,  7740,  7746,  7747,
    7748,  7749,  7761,  7762,  7763,  7767,  7768,  7772,  7773,  7774,
    7775,  7776,  7778,  7787,  7794,  7795,  7796,  7797,  7798,  7799,
    7800,  7802,  7804,  7806,  7807,  7809,  7810,  7812,  7813,  7814,
    7815,  7817,  7821,  7822,  7828,  7830,  7831,  7832,  7833,  7838,
    7842,  7846,  7850,  7857,  7861,  7862,  7863,  7871,  7872,  7873,
    7884,  7891,  7896,  7897,  7898,  7906,  7907,  7908,  7925,  7934,
    7935,  7936,  7940,  7943,  7948,  7953,  7958,  7966,  7970,  7975,
    7976,  7984,  7987,  7990,  8004,  8018,  8031,  8032,  8036,  8036,
    8036,  8036,  8036,  8036,  8037,  8040,  8057,  8057,  8057,  8057,
    8057,  8057,  8057,  8058,  8058,  8058,  8058,  8058,  8058,  8058,
    8058,  8061,  8062,  8063,  8066,  8075,  8075,  8081,  8081,  8088,
    8088,  8094,  8094,  8102,  8103,  8104,  8107,  8107,  8110,  8111,
    8112,  8123,  8126,  8132,  8137,  8144,  8157,  8158,  8155,  8176,
    8187,  8190,  8195,  8207,  8210,  8214,  8217,  8218,  8228,  8231,
    8232,  8241,  8250,  8255,  8256,  8257,  8258,  8265,  8268,  8274,
    8277,  8284,  8296,  8305,  8308,  8311,  8317,  8325,  8328,  8329,
    8330,  8331,  8332,  8335,  8341,  8343,  8345,  8347,  8349,  8351,
    8352,  8353,  8354,  8355,  8356,  8357,  8359,  8361,  8363,  8365,
    8367,  8369,  8371,  8372,  8374,  8375,  8381,  8382,  8389,  8392,
    8400,  8404,  8411,  8411,  8415,  8415,  8420,  8420,  8424,  8424,
    8428,  8434,  8434,  8437,  8437,  8443,  8450,  8451,  8452,  8456,
    8457,  8460,  8461,  8465,  8471,  8481,  8482,  8490,  8491,  8492,
    8493,  8494,  8495,  8499,  8500,  8501,  8502,  8506,  8507,  8511,
    8527,  8528,  8529,  8533,  8547,  8547,  8559,  8560,  8564,  8565,
    8566,  8890,  8890,  8897,  8897,  8985,  8989,  8985,  8998,  9002,
    9008,  9016,  9026,  9036,  9048,  9051,  9070,  9096,  9099,  9105,
    9108,  9113,  9116,  9124,  9132,  9145,  9148,  9156,  9159,  9162,
    9170,  9174,  9175,  9176,  9177,  9178,  9179,  9180,  9181,  9185,
    9186,  9187,  9188,  9189,  9195,  9196,  9197,  9198,  9199,  9200,
    9201,  9202,  9203,  9204,  9205,  9206,  9207,  9208,  9209,  9210,
    9215,  9221,  9222,  9230,  9230,  9238,  9238,  9242,  9246,  9261,
    9276,  9282,  9284,  9292,  9293,  9297,  9298,  9301,  9308,  9311,
    9340,  9366,  9420,  9456,  9465,  9476,  9479,  9484,  9498,  9512,
    9515,  9511,  9534,  9534,  9540,  9541,  9544,  9545,  9546,  9547,
    9548,  9549,  9550,  9561,  9564,  9569,  9573,  9578,  9582,  9587,
    9591,  9594,  9598,  9601,  9606,  9610,  9621,  9627,  9627,  9628,
    9629,  9636,  9646,  9646,  9648,  9649,  9650,  9651,  9652,  9653,
    9654,  9655,  9656,  9657,  9658,  9659,  9660,  9661,  9662,  9663,
    9664,  9665,  9666,  9667,  9668,  9669,  9670,  9671,  9672,  9673,
    9674,  9675,  9676,  9677,  9678,  9679,  9680,  9681,  9682,  9683,
    9684,  9685,  9686,  9687,  9688,  9689,  9690,  9691,  9692,  9693,
    9694,  9695,  9696,  9697,  9698,  9699,  9700,  9701,  9702,  9703,
    9704,  9705,  9706,  9707,  9708,  9709,  9710,  9711,  9712,  9713,
    9714,  9715,  9716,  9717,  9718,  9719,  9720,  9721,  9722,  9723,
    9724,  9725,  9726,  9727,  9728,  9729,  9730,  9731,  9732,  9733,
    9734,  9735,  9736,  9737
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
  "MEMBER_FUNCTION", "MISC_INFX_SQL", "AS_CONVERTABLE", "FREE_REPORT", 
  "CONVERTING_TO_MANY", "CONVERTING_TO", "CONVERT_REPORT", 
  "DATETIME_VALUE", "INTERVAL_VALUE", "IN_LINE_MODE", "IN_FORM_MODE", 
  "FGL_SIZEOF", "IMPORT_PACKAGE", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "AFTER_INSERT_DELETE", 
  "BEFORE_INSERT_DELETE", "BEFORE_INSERT", "CONCAT_PIPES", 
  "BEFORE_DELETE", "DROP_TRIGGER", "AFTER_INSERT", "AFTER_DELETE", 
  "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
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
  "convert_cmd", "rout", "free_rep_cmd", "rep_name", "op_values", 
  "output_cmd", "finish_cmd", "term_rep_cmd", "report_section", 
  "format_section", "format_actions", "format_action", "@138", "@139", 
  "@140", "@141", "@142", "@143", "@144", "report_cmd", "need_command", 
  "@145", "op_lines", "skip_command", "@146", "opt_rep_expr_list", 
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
       0,   256,  1722,  1723,  1724,  1625,  1665,  1620,  1557,  1640,
    1438,  1543,  1539,  1455,  1615,  1357,  1414,  1486,  1651,  1638,
    1544,  1571,  1639,  1421,  1725,  1726,  1727,  1728,  1729,  1730,
    1731,  1732,  1733,  1734,  1735,  1736,  1000,  1001,  1002,  1003,
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
    1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1415,
    1416,  1417,  1418,  1419,  1420,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1437,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1454,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1482,  1483,  1484,  1485,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,
    1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1540,
    1541,  1542,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,
    1553,  1554,  1555,  1556,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1616,  1617,  1618,  1619,  1621,  1622,  1623,  1624,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,
    1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,
    1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   739,   740,   741,   742,   743,   744,   744,   745,   745,
     746,   747,   747,   747,   747,   747,   747,   748,   748,   748,
     748,   748,   749,   749,   750,   750,   752,   751,   751,   753,
     753,   754,   754,   754,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   755,   755,
     757,   756,   758,   758,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   760,   761,   762,   761,   761,   761,   761,
     761,   763,   764,   761,   765,   766,   761,   767,   768,   769,
     761,   770,   771,   761,   772,   773,   761,   774,   775,   776,
     761,   777,   777,   778,   778,   778,   779,   779,   780,   780,
     781,   781,   782,   782,   783,   783,   785,   784,   786,   784,
     787,   787,   788,   788,   789,   790,   791,   790,   792,   793,
     792,   795,   794,   797,   796,   799,   800,   801,   798,   802,
     802,   803,   803,   804,   805,   805,   805,   805,   805,   805,
     806,   807,   807,   808,   808,   809,   810,   810,   811,   813,
     814,   812,   815,   815,   816,   816,   817,   817,   818,   818,
     818,   819,   819,   821,   820,   822,   820,   823,   820,   824,
     820,   825,   820,   826,   826,   827,   827,   828,   828,   828,
     828,   828,   828,   829,   830,   830,   831,   831,   832,   832,
     833,   833,   835,   836,   834,   834,   837,   837,   839,   838,
     840,   840,   840,   840,   840,   841,   840,   842,   842,   842,
     842,   843,   844,   844,   845,   845,   846,   846,   846,   846,
     848,   847,   849,   847,   850,   847,   851,   851,   852,   852,
     853,   854,   854,   854,   855,   856,   856,   856,   858,   857,
     859,   857,   860,   857,   861,   861,   862,   863,   864,   864,
     866,   867,   865,   868,   868,   868,   868,   868,   868,   868,
     868,   868,   868,   868,   868,   868,   868,   868,   868,   868,
     868,   868,   868,   868,   869,   868,   870,   868,   871,   868,
     868,   868,   868,   868,   868,   868,   868,   868,   868,   872,
     872,   873,   874,   875,   875,   876,   878,   877,   879,   879,
     879,   879,   879,   879,   879,   881,   880,   882,   882,   883,
     883,   884,   886,   885,   887,   887,   887,   887,   887,   887,
     887,   888,   889,   889,   891,   890,   892,   892,   892,   892,
     892,   892,   892,   892,   892,   892,   892,   892,   892,   892,
     892,   892,   892,   892,   892,   892,   892,   892,   892,   893,
     895,   894,   896,   894,   898,   897,   899,   897,   900,   900,
     901,   902,   902,   903,   904,   904,   904,   904,   904,   904,
     904,   904,   905,   906,   907,   909,   910,   908,   911,   911,
     912,   913,   913,   913,   914,   914,   916,   915,   917,   915,
     918,   915,   919,   920,   921,   922,   922,   923,   923,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   925,   925,
     925,   925,   925,   925,   925,   925,   926,   926,   926,   926,
     926,   926,   926,   926,   926,   927,   927,   927,   927,   927,
     927,   927,   927,   927,   927,   927,   928,   928,   929,   929,
     930,   930,   931,   931,   932,   932,   933,   934,   934,   934,
     934,   934,   934,   935,   935,   935,   935,   936,   936,   937,
     938,   938,   938,   939,   938,   940,   940,   941,   941,   942,
     942,   942,   942,   943,   943,   944,   944,   944,   944,   944,
     944,   944,   944,   945,   946,   947,   947,   947,   947,   947,
     947,   948,   948,   948,   948,   948,   948,   948,   949,   951,
     952,   950,   953,   954,   950,   955,   956,   950,   958,   959,
     957,   960,   961,   957,   962,   963,   957,   964,   965,   957,
     957,   957,   957,   957,   957,   957,   957,   957,   957,   957,
     957,   957,   957,   957,   957,   957,   957,   957,   957,   957,
     957,   957,   957,   957,   957,   966,   966,   967,   968,   968,
     968,   968,   968,   968,   968,   968,   968,   969,   969,   970,
     970,   970,   970,   971,   971,   971,   972,   972,   973,   973,
     973,   974,   974,   974,   974,   974,   974,   974,   974,   974,
     974,   974,   975,   975,   976,   976,   977,   977,   979,   980,
     981,   978,   982,   982,   984,   985,   983,   986,   986,   987,
     987,   988,   988,   990,   989,   991,   989,   992,   992,   993,
     993,   995,   994,   996,   994,   997,   998,   998,   998,   999,
     999,  1000,  1000,  1001,  1001,  1002,  1002,  1004,  1003,  1005,
    1003,  1006,  1003,  1007,  1003,  1008,  1003,  1010,  1011,  1009,
    1012,  1012,  1013,  1014,  1014,  1014,  1014,  1014,  1014,  1014,
    1015,  1015,  1016,  1017,  1018,  1019,  1019,  1019,  1019,  1019,
    1019,  1019,  1019,  1020,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1027,  1028,  1029,  1030,  1030,  1031,  1031,  1032,
    1032,  1032,  1032,  1032,  1032,  1033,  1034,  1034,  1035,  1036,
    1036,  1037,  1038,  1038,  1039,  1040,  1041,  1041,  1041,  1042,
    1042,  1042,  1044,  1043,  1045,  1045,  1046,  1046,  1047,  1047,
    1048,  1049,  1049,  1050,  1051,  1051,  1052,  1053,  1053,  1054,
    1055,  1055,  1057,  1058,  1056,  1059,  1060,  1059,  1061,  1062,
    1059,  1063,  1063,  1064,  1065,  1067,  1066,  1066,  1068,  1068,
    1069,  1069,  1070,  1071,  1071,  1071,  1072,  1072,  1073,  1073,
    1075,  1074,  1076,  1074,  1077,  1074,  1078,  1074,  1079,  1074,
    1080,  1074,  1081,  1074,  1082,  1074,  1083,  1074,  1084,  1074,
    1085,  1074,  1086,  1074,  1087,  1074,  1088,  1088,  1089,  1089,
    1090,  1091,  1092,  1092,  1092,  1094,  1093,  1095,  1095,  1096,
    1095,  1097,  1098,  1098,  1098,  1098,  1098,  1098,  1099,  1099,
    1100,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,  1101,
    1103,  1102,  1102,  1105,  1104,  1106,  1107,  1108,  1108,  1109,
    1109,  1110,  1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,
    1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,  1111,
    1112,  1114,  1115,  1113,  1116,  1116,  1117,  1118,  1119,  1120,
    1120,  1121,  1121,  1122,  1124,  1123,  1125,  1125,  1126,  1126,
    1127,  1127,  1127,  1127,  1127,  1127,  1127,  1128,  1128,  1129,
    1129,  1130,  1131,  1131,  1131,  1131,  1131,  1131,  1131,  1131,
    1131,  1132,  1133,  1133,  1134,  1135,  1135,  1137,  1138,  1139,
    1140,  1136,  1141,  1143,  1144,  1142,  1145,  1146,  1146,  1147,
    1147,  1148,  1149,  1149,  1150,  1152,  1151,  1153,  1153,  1153,
    1153,  1155,  1156,  1154,  1157,  1157,  1159,  1158,  1160,  1158,
    1162,  1161,  1163,  1165,  1164,  1166,  1164,  1167,  1164,  1168,
    1168,  1169,  1169,  1170,  1170,  1171,  1171,  1171,  1172,  1173,
    1174,  1175,  1175,  1175,  1176,  1176,  1177,  1177,  1178,  1179,
    1179,  1179,  1179,  1180,  1180,  1180,  1180,  1180,  1181,  1182,
    1182,  1183,  1184,  1185,  1185,  1186,  1187,  1187,  1187,  1187,
    1187,  1187,  1188,  1189,  1190,  1190,  1191,  1191,  1192,  1193,
    1193,  1194,  1194,  1195,  1196,  1197,  1197,  1197,  1197,  1197,
    1197,  1198,  1198,  1199,  1200,  1200,  1201,  1201,  1202,  1202,
    1203,  1203,  1204,  1204,  1204,  1204,  1204,  1205,  1205,  1206,
    1206,  1207,  1207,  1208,  1209,  1210,  1210,  1211,  1212,  1212,
    1212,  1213,  1213,  1214,  1214,  1215,  1216,  1216,  1217,  1217,
    1218,  1219,  1220,  1221,  1221,  1222,  1223,  1223,  1224,  1224,
    1225,  1225,  1226,  1227,  1227,  1228,  1228,  1228,  1228,  1229,
    1229,  1229,  1230,  1231,  1231,  1232,  1232,  1232,  1233,  1234,
    1234,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,
    1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,
    1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1235,  1236,
    1236,  1237,  1237,  1238,  1239,  1239,  1240,  1240,  1240,  1240,
    1240,  1241,  1243,  1242,  1244,  1244,  1245,  1246,  1246,  1247,
    1247,  1248,  1248,  1250,  1249,  1251,  1253,  1252,  1254,  1254,
    1255,  1255,  1256,  1256,  1257,  1257,  1257,  1257,  1257,  1257,
    1258,  1258,  1259,  1259,  1260,  1261,  1262,  1262,  1263,  1264,
    1264,  1264,  1264,  1265,  1266,  1267,  1267,  1268,  1268,  1270,
    1269,  1271,  1269,  1272,  1269,  1273,  1269,  1274,  1269,  1275,
    1269,  1276,  1269,  1277,  1277,  1277,  1277,  1277,  1277,  1279,
    1278,  1280,  1280,  1282,  1281,  1281,  1281,  1281,  1281,  1283,
    1283,  1284,  1284,  1285,  1286,  1286,  1288,  1287,  1289,  1289,
    1290,  1291,  1292,  1292,  1292,  1293,  1293,  1293,  1293,  1294,
    1295,  1295,  1296,  1296,  1297,  1298,  1298,  1298,  1298,  1298,
    1298,  1298,  1298,  1299,  1299,  1300,  1300,  1301,  1301,  1301,
    1301,  1301,  1301,  1301,  1301,  1301,  1301,  1302,  1302,  1303,
    1303,  1303,  1303,  1304,  1304,  1305,  1305,  1306,  1306,  1306,
    1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,
    1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,
    1306,  1307,  1307,  1307,  1309,  1310,  1311,  1312,  1313,  1314,
    1308,  1315,  1315,  1316,  1317,  1317,  1319,  1320,  1321,  1322,
    1323,  1324,  1318,  1325,  1327,  1328,  1329,  1326,  1330,  1330,
    1330,  1330,  1331,  1331,  1331,  1331,  1331,  1331,  1331,  1331,
    1332,  1332,  1333,  1334,  1334,  1334,  1334,  1335,  1335,  1337,
    1338,  1336,  1339,  1340,  1336,  1341,  1341,  1342,  1342,  1343,
    1343,  1343,  1343,  1343,  1344,  1345,  1345,  1346,  1346,  1347,
    1347,  1348,  1348,  1348,  1348,  1348,  1349,  1349,  1350,  1350,
    1351,  1351,  1351,  1352,  1352,  1353,  1353,  1354,  1354,  1355,
    1355,  1355,  1356,  1356,  1357,  1357,  1357,  1357,  1357,  1357,
    1357,  1358,  1358,  1359,  1359,  1360,  1360,  1361,  1361,  1362,
    1362,  1363,  1364,  1364,  1365,  1365,  1366,  1367,  1367,  1368,
    1369,  1369,  1370,  1370,  1371,  1371,  1372,  1372,  1373,  1373,
    1374,  1375,  1375,  1375,  1375,  1375,  1375,  1375,  1375,  1375,
    1375,  1375,  1376,  1376,  1377,  1377,  1378,  1379,  1381,  1380,
    1383,  1382,  1382,  1384,  1384,  1385,  1385,  1386,  1386,  1387,
    1387,  1389,  1388,  1390,  1391,  1391,  1392,  1393,  1392,  1394,
    1395,  1394,  1396,  1396,  1396,  1396,  1396,  1396,  1396,  1396,
    1397,  1398,  1399,  1400,  1400,  1401,  1402,  1402,  1403,  1403,
    1403,  1404,  1405,  1406,  1406,  1407,  1408,  1408,  1408,  1410,
    1409,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  1412,  1412,  1412,  1412,  1413,  1413,
    1413,  1414,  1414,  1414,  1415,  1415,  1415,  1416,  1416,  1417,
    1417,  1417,  1417,  1417,  1417,  1418,  1418,  1419,  1419,  1420,
    1420,  1421,  1421,  1422,  1423,  1423,  1424,  1424,  1425,  1425,
    1426,  1427,  1428,  1429,  1430,  1430,  1431,  1431,  1432,  1432,
    1432,  1433,  1433,  1434,  1434,  1434,  1435,  1435,  1435,  1435,
    1436,  1437,  1437,  1438,  1438,  1439,  1439,  1440,  1441,  1441,
    1441,  1441,  1441,  1441,  1441,  1442,  1443,  1444,  1445,  1445,
    1446,  1446,  1447,  1448,  1449,  1449,  1450,  1451,  1452,  1452,
    1453,  1453,  1453,  1454,  1454,  1454,  1455,  1455,  1456,  1457,
    1457,  1458,  1458,  1459,  1459,  1460,  1460,  1461,  1461,  1462,
    1462,  1463,  1463,  1464,  1464,  1465,  1465,  1466,  1467,  1468,
    1468,  1468,  1468,  1469,  1469,  1470,  1470,  1471,  1471,  1472,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1474,  1474,  1474,  1475,  1475,
    1475,  1475,  1476,  1476,  1476,  1477,  1477,  1478,  1478,  1478,
    1478,  1478,  1478,  1478,  1478,  1478,  1478,  1478,  1478,  1478,
    1478,  1478,  1478,  1478,  1478,  1478,  1478,  1478,  1478,  1478,
    1478,  1478,  1479,  1479,  1480,  1480,  1480,  1480,  1480,  1481,
    1482,  1483,  1484,  1484,  1484,  1484,  1484,  1484,  1484,  1484,
    1485,  1485,  1485,  1485,  1485,  1485,  1485,  1485,  1486,  1487,
    1487,  1487,  1488,  1488,  1489,  1489,  1489,  1490,  1491,  1491,
    1491,  1491,  1492,  1493,  1494,  1494,  1495,  1495,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1497,  1497,  1497,  1497,
    1497,  1497,  1497,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1499,  1499,  1499,  1500,  1502,  1501,  1503,  1501,  1504,
    1501,  1505,  1501,  1506,  1506,  1506,  1507,  1507,  1508,  1508,
    1508,  1509,  1509,  1510,  1510,  1511,  1513,  1514,  1512,  1515,
    1516,  1516,  1517,  1518,  1518,  1518,  1518,  1518,  1519,  1520,
    1520,  1521,  1522,  1523,  1523,  1523,  1523,  1524,  1524,  1525,
    1525,  1525,  1526,  1527,  1527,  1527,  1528,  1528,  1528,  1528,
    1528,  1528,  1528,  1528,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1529,
    1529,  1529,  1529,  1529,  1529,  1529,  1530,  1530,  1531,  1532,
    1533,  1533,  1534,  1534,  1535,  1535,  1536,  1536,  1537,  1537,
    1538,  1539,  1539,  1540,  1540,  1541,  1542,  1542,  1542,  1543,
    1543,  1544,  1545,  1546,  1547,  1548,  1548,  1549,  1549,  1549,
    1549,  1549,  1549,  1550,  1550,  1550,  1550,  1551,  1551,  1552,
    1553,  1553,  1553,  1554,  1556,  1555,  1557,  1557,  1558,  1558,
    1558,  1560,  1559,  1562,  1561,  1564,  1565,  1563,  1566,  1566,
    1566,  1567,  1567,  1567,  1567,  1567,  1567,  1568,  1568,  1569,
    1570,  1571,  1571,  1572,  1572,  1573,  1573,  1574,  1574,  1574,
    1575,  1575,  1575,  1575,  1575,  1575,  1575,  1575,  1575,  1575,
    1575,  1575,  1575,  1575,  1576,  1576,  1576,  1576,  1576,  1576,
    1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,  1576,
    1577,  1578,  1578,  1580,  1579,  1581,  1581,  1582,  1582,  1583,
    1584,  1585,  1585,  1586,  1586,  1587,  1587,  1587,  1588,  1588,
    1589,  1589,  1590,  1591,  1591,  1592,  1592,  1593,  1594,  1596,
    1597,  1595,  1598,  1598,  1599,  1599,  1600,  1600,  1600,  1600,
    1600,  1600,  1600,  1601,  1601,  1602,  1602,  1603,  1603,  1604,
    1604,  1605,  1606,  1607,  1608,  1608,  1609,  1610,  1610,  1611,
    1612,  1612,  1614,  1613,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,  1615,
    1615,  1615,  1615,  1615
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
       1,     3,     1,     1,     3,     4,     4,     3,     3,     2,
       8,     6,     1,     1,     2,     1,     0,     1,     7,     2,
       3,     8,     6,     2,     2,     2,     2,     1,     2,     0,
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
       3,     3,     2,     3,     4,     3,     5,     4,     3,     3,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     0,
       0,     8,     0,     0,     9,     0,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     0,     1,     1,     2,     2,
       2,     8,     2,     2,     4,     2,     0,     1,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     1,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     1,     3,     1,     3,     2,     4,     1,
       3,     1,     2,     4,     1,     3,     1,     1,     1,     2,
       3,     4,     2,     4,     0,     2,     2,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       6,     6,     0,     1,     0,     1,     2,     1,     0,     5,
       0,     5,     1,     0,     3,     1,     3,     1,     3,     1,
       1,     0,     4,     1,     2,     1,     0,     0,     3,     0,
       0,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     3,     3,     1,     3,     2,     1,     1,     0,     1,
       1,     1,     1,     0,     1,     3,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     6,     4,     4,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     1,     3,     2,
       1,     1,     2,     1,     1,     0,     3,     1,     3,     1,
       3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
       4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       4,     0,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     3,     2,     2,     1,     3,
       1,     2,     4,     1,     2,     3,     1,     3,     4,     0,
       1,     0,     1,     0,     1,     1,     3,     1,     3,     1,
       2,     1,     3,     2,     2,     0,     2,     1,     1,     5,
       3,     5,     3,     1,     3,     1,     1,     0,     1,     3,
       3,     3,     6,     4,     4,     4,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     1,     4,
       1,     5,     5,     1,     1,     1,     1,     1,     4,     1,
       4,     6,     4,     1,     4,     1,     7,     1,     1,     1,
       4,     6,     0,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     5,     3,     5,     7,
       3,     1,     1,     3,     5,     3,     5,     7,     1,     0,
       3,     5,     1,     2,     2,     4,     3,     1,     1,     1,
       1,     1,     2,     2,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     1,     3,     0,     7,     0,     8,     0,
       6,     0,     8,     0,     1,     2,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     1,     0,     0,     9,     5,
       1,     1,     6,     0,     3,     1,     3,     4,     1,     0,
       2,     4,     6,     0,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     4,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     1,     1,     3,     1,     5,
       7,     5,     0,     2,     1,     1,     0,     3,     1,     3,
       1,     1,     1,     0,     3,     1,     1,     1,     1,     4,
       6,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     4,     5,     1,     4,     1,
       1,     7,     4,     1,     0,     4,     1,     2,     1,     1,
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
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     856,     0,  1948,     0,     0,     0,     0,   905,   192,     0,
       0,   853,   881,   884,   190,   195,   863,   860,     0,   851,
     852,   854,   857,   858,   861,   865,   866,   864,   901,   902,
     904,   862,   148,   145,     0,   141,   143,   142,   146,  1976,
     733,   673,   734,   324,  1723,  1721,   899,   188,   198,   900,
     125,   191,     1,   867,   859,   903,   140,   144,   147,     0,
       0,   650,     0,     0,   189,   908,   970,   651,   909,   910,
     906,   685,   962,     0,   963,   971,   969,   198,   193,   211,
       0,   196,   212,   250,   129,     0,   886,  1276,     0,   885,
    1264,   893,     0,     0,   878,   877,   879,   855,   868,   869,
     887,   872,   873,   876,   874,   875,   880,     0,  1722,   964,
     907,     0,     0,   978,   976,   977,   966,   965,   322,   198,
    1200,   205,   199,   198,   204,   247,     0,     0,   126,   732,
       0,     0,     0,   188,   594,   911,   870,     0,   356,   342,
     214,   328,   293,   312,   333,   335,   332,     0,   354,     0,
     341,   334,   338,   344,   343,   198,   345,   325,   348,   326,
     327,   975,   974,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   983,     0,   556,
     548,    16,   555,   970,    15,     0,   981,     0,   323,     0,
     197,  1201,   194,     0,   211,   213,   288,   216,   276,   282,
     283,   267,   240,   278,   214,   255,   256,     0,   242,   293,
     312,   265,   268,   263,     0,   238,     0,   274,   266,   271,
     281,   280,   198,   284,   198,   253,   254,   251,   287,   130,
     188,     0,     0,     0,   894,   188,   188,     0,     0,   215,
       0,     0,   346,     0,     0,   347,     0,     0,     0,     0,
       0,     0,     0,   235,     0,   972,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,     0,     0,   686,   453,   455,  1271,     0,     0,     0,
    1696,     0,   449,     0,     0,     0,   448,     0,   463,   558,
       0,     0,     0,     0,     0,   561,   416,   422,   459,   456,
     417,   418,   420,   421,   454,   457,   462,   557,   511,   508,
     517,   514,     0,     0,    17,    18,    19,    20,    21,     0,
      14,     0,   499,     0,     0,   979,     0,   200,   203,   201,
     202,     0,   208,   207,   206,   209,   217,   218,   219,   222,
     289,   198,   289,     0,     0,     0,     0,   198,   285,   286,
       0,     0,   198,     0,   289,     0,     0,   264,   248,   127,
    1277,     0,  1265,  1982,   595,   912,   888,     0,   226,   227,
       0,     0,   305,   307,   302,   303,   299,   301,   298,   300,
     297,     0,   307,   318,   319,   315,   317,   314,   316,   309,
       0,     0,     0,   358,     0,   361,   363,   234,     0,   233,
       0,   198,   198,   198,     0,     0,     0,   584,   655,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   566,
     571,     0,     0,   567,   570,   569,   664,     0,   663,   586,
       0,    11,   184,   447,   424,   423,     0,  1206,     0,     0,
     461,  1704,  1702,  1703,  1699,  1701,  1698,  1700,  1692,     0,
       0,     0,   460,     0,     0,     0,     0,     0,     0,     0,
     687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   563,   564,   565,   474,     0,     0,
     473,   483,     0,     0,   428,     0,     0,   429,   419,   425,
     427,   430,   431,   432,   433,   434,   426,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    96,     0,   982,     0,
     967,   210,     0,     0,   277,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,   198,   249,
     252,     0,   994,   731,   994,     0,  1980,  1982,  1200,  1823,
     882,     0,   994,     0,     0,   329,   294,     0,     0,   304,
     321,   295,   320,     0,   313,     0,   336,     0,   330,     0,
     355,     0,   360,   350,     0,     0,   339,   236,     0,   292,
     349,   542,     0,     0,   554,     0,     0,   551,   550,   553,
     549,   560,   545,   545,     0,     0,   545,     0,   568,     0,
     572,     0,   581,   312,     0,   552,   559,   296,     0,  1272,
    1763,     0,     0,     0,     0,     0,   450,     0,     0,   464,
       0,     0,     0,     0,   466,   465,   484,   475,   490,   493,
     494,   491,   497,   496,   495,   485,   486,   487,   488,   489,
     435,   476,   480,   498,   492,   479,   498,   458,   512,   509,
     518,   515,   543,     0,   505,   101,   500,    97,    98,   100,
     502,     0,     0,   250,     0,     0,     0,   257,   258,     0,
     261,     0,     0,   269,     0,   259,   239,   220,     0,   272,
     291,     0,   131,   133,  1000,     0,   995,   996,     0,   895,
    1981,  1979,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1963,
       0,  1397,  1396,     0,  1398,     0,   412,  1395,  1312,     0,
       5,  1394,   413,   410,     0,   415,   186,   498,  1175,     0,
       0,  1404,   137,   409,   408,     0,     0,   403,   498,     0,
    1348,  1956,     0,   414,   375,     0,     3,     2,     0,   411,
    1309,     0,     0,   404,   401,   397,     0,     0,     0,     0,
    1402,  1392,   407,     0,     0,     0,     0,     0,     0,     0,
       0,  1391,     0,     0,     0,   187,     0,   400,   399,     0,
       0,  1960,  1959,     0,     0,     0,   149,     0,   406,   405,
       0,     0,   402,   498,     0,     0,   498,     0,   588,     0,
       0,     0,     0,     0,     0,   498,   840,  1274,     0,     0,
    1186,     0,  1949,     0,   108,     0,     0,   920,     0,     0,
       0,     0,   841,     0,     0,  1854,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   702,     0,     0,  1984,  1985,
    1986,  1987,  1988,  1989,  1990,  1991,  1992,  1993,  1994,  1995,
    1996,  1997,  1998,  1999,  2000,  2001,  2002,  2003,  2004,  2005,
    2006,  2007,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,
    2016,  2017,  2018,  2019,  2020,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,  2031,  2032,   949,  2033,  2034,
    2035,  2036,  2037,  2038,  2039,  2040,  2041,  2042,  2043,  2044,
    2045,  2046,  2047,  2048,  2049,  2050,  2051,  1166,  1168,  1163,
    1165,  1164,  1167,  2052,  2053,  1302,  2054,  1308,  1307,  2055,
    2056,  2057,  2058,  2059,  2060,  2061,  2062,  2063,  2064,  1459,
    2065,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,  1983,
     883,   599,     0,   916,     0,   914,     0,   357,   228,   229,
       0,   306,   311,     0,     0,     0,     0,   359,   362,     0,
     232,     0,   198,     0,   585,     0,   659,     0,   661,     0,
     523,   521,     0,   545,     0,   522,     0,     0,   583,     0,
     579,   576,   547,   520,   587,     0,   183,  1765,  1766,  1764,
       0,   452,  1271,     0,  1697,  1271,   451,  1271,  1271,  1271,
    1271,  1271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,     0,    96,   980,
       0,   223,   290,   241,     0,     0,   198,     0,     0,     0,
       0,   128,   132,     0,  1278,     0,  1266,  1135,  1134,     0,
     394,   392,   393,  1306,  1095,  1094,  1100,     0,  1671,  1672,
       0,     0,  1332,   674,   675,  1333,  1663,  1664,  1335,   871,
    1143,  1958,   667,   136,  1971,     0,     0,  1347,     7,     0,
       6,     0,  1964,  1136,     0,  1234,  1233,  1178,  1232,  1177,
     446,  1405,  1393,     0,  1303,   896,   436,  1825,  1399,   138,
       0,  1139,   135,     0,   847,    24,   669,   398,     0,   846,
    1129,   848,     0,  1403,   942,   941,   944,   940,   943,  1973,
       0,   938,     0,   668,  1026,   939,  1967,     0,  1957,   134,
    1305,  1023,   735,  1021,     0,   665,  1952,   783,   782,   784,
     780,     0,     0,  1304,  1036,   670,  1458,     0,  1939,  1453,
    1456,  1929,  1932,  1933,  1935,  1938,     0,     0,     0,     0,
    1101,  1096,     0,  1075,  1076,  1077,  1078,  1084,  1085,  1086,
    1083,  1082,     0,     0,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1067,  1058,  1059,  1009,     0,  1007,  1115,   444,    24,
       0,  1954,   139,   666,     0,  1275,  1273,  1199,     0,  1814,
       0,  1815,  1200,  1188,  1179,  1406,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,   970,     0,    69,     0,
     106,   642,     0,   689,   688,     0,  1169,  1043,  1173,     0,
       0,  1116,  1292,     0,     0,  1176,   694,   691,   692,     0,
     696,   697,     0,   699,   700,     0,   695,  1004,  1006,     0,
       0,  1005,   785,  1002,   746,   998,   961,     0,     0,     0,
       0,   706,   707,     0,     0,   959,   956,   957,   953,   954,
     955,   948,   952,   951,     0,     0,     0,     0,     0,     0,
     603,   605,   597,   600,   601,   918,  1982,   913,   915,   889,
       0,   308,   310,   337,   331,     0,     0,   340,   237,   656,
     658,     0,     0,     0,     0,   545,   528,     0,   545,   545,
       0,   573,     0,   305,     0,     0,  1793,  1688,  1690,  1849,
    1853,  1794,  1694,  1791,     0,     0,  1790,     0,     0,     0,
    1792,     0,     0,     0,     0,     0,     0,     0,  1939,  1689,
    1789,  1691,  1778,     0,  1767,  1769,  1773,  1776,  1804,  1847,
    1805,  1850,  1940,  1930,  1777,  1209,  1705,  1208,  1207,  1210,
    1212,  1211,  1205,   477,   478,   482,   467,     0,   470,   481,
       0,   469,   513,   510,   519,   516,   544,   506,   501,    99,
     503,   968,     0,   262,   246,     0,   244,   270,   260,   250,
     273,  1001,   188,   997,   188,     0,     0,     0,     0,  1377,
    1378,     0,     0,     0,  1349,  1352,  1354,  1355,  1356,  1360,
    1359,  1357,  1358,     0,     0,     0,  1350,  1351,     0,     0,
       0,     0,     0,     0,     0,     0,  1137,     0,    24,  1229,
    1231,  1230,     0,   439,   440,   437,   438,  1014,     0,  1140,
       0,     0,   380,    25,   374,     0,  1128,     0,  1127,  1124,
       0,     0,     0,     0,     0,     0,     0,  1030,  1824,     0,
       0,     0,     0,     0,     0,  1954,     0,     0,   150,     0,
       0,  1040,  1032,  1033,  1038,     0,     0,  1931,     0,  1942,
    1454,  1455,     0,     0,   958,   442,  1923,  1053,   364,     0,
       0,   589,   647,   646,   644,   649,  1061,   648,  1066,  1062,
    1065,   839,   831,   825,   837,   838,   823,   824,   832,   827,
     833,   826,   836,   830,   834,   829,   835,   822,   828,   815,
     821,  1063,  1064,     0,  1071,  1079,  1068,  1069,  1073,  1074,
    1072,  1070,  1089,  1090,  1087,  1080,  1091,  1092,  1088,     0,
       0,     0,   849,     0,     0,     0,     0,     0,   795,   794,
     791,  1955,  1962,    24,  1195,  1196,  1197,  1198,  1192,     0,
    1190,  1288,  1200,  1180,  1181,  1184,  1202,  1950,     0,     0,
       0,     0,   102,     0,   103,     0,     0,     0,    77,     0,
       0,     0,     0,   115,   110,     0,   690,   947,     0,   946,
       0,   498,  1171,     0,   989,   990,  1013,   984,   985,   842,
    1011,  1118,  1301,  1300,  1295,     0,  1299,  1298,  1293,  1858,
    1861,  1863,     0,  1856,  1859,  1860,   722,     0,     0,     0,
     711,   746,   746,   743,     0,     0,   747,     0,    26,   710,
     713,     0,   720,   716,   960,   950,  1821,  1822,  1812,  1812,
    1423,     0,     0,  1724,  1462,     0,     0,  1407,     0,     0,
    1408,  1451,     0,     0,  1452,     0,     0,  1763,     0,  1421,
       0,  1471,  1470,  1469,  1467,  1468,  1466,  1464,  1460,  1551,
    1550,  1461,  1463,  1472,  1745,  1465,  1828,  1827,  1826,  1473,
    1982,  1982,   616,   607,   598,     0,   602,  1982,   917,   188,
       0,   351,   231,     0,     0,   546,     0,   545,     0,   532,
     545,     0,   525,   524,     0,     0,     0,   578,   577,   185,
    1775,  1774,  1712,  1710,  1711,  1707,  1709,  1706,  1708,  1693,
       0,  1763,     0,     0,  1618,     0,     0,  1781,  1779,  1780,
    1618,  1618,  1618,  1618,  1782,     0,     0,     0,  1569,  1753,
       0,  1770,     0,     0,     0,     0,  1837,  1838,  1839,  1840,
    1841,  1842,  1785,     0,     0,     0,     0,   472,   471,     0,
       0,     0,   198,   243,   221,  1279,  1267,     0,     0,     0,
       0,     0,     0,     0,  1525,  1524,  1523,  1384,     0,  1390,
    1386,  1388,  1379,     0,  1627,  1376,  1372,  1346,  1345,     0,
    1371,  1367,     0,  1363,  1361,     0,  1670,     0,  1673,  1675,
     678,     0,   677,  1662,     0,  1665,  1667,  1972,  1969,     0,
       0,  1313,   498,   372,  1334,     0,     0,     0,  1310,  1045,
    1132,  1133,  1126,  1125,     0,   945,     0,     0,   652,     0,
       0,     0,  1024,  1022,   737,   738,     0,   742,     0,     0,
    1953,  1961,   781,     0,   154,     0,  1034,  1041,     0,     0,
    1049,  1934,  1947,     0,  1945,  1457,  1937,  1936,     0,     0,
       0,  1055,   367,     0,     0,     0,     0,    24,  1097,  1098,
     592,     0,     0,     0,   816,   817,  1060,  1010,  1008,   850,
     445,     0,  1107,   792,   796,   793,   797,   395,     0,  1200,
    1189,  1289,  1204,  1187,  1182,     0,     0,  1183,  1982,     0,
       0,     0,     0,     0,     0,     0,    64,    96,     0,     0,
       0,   121,   116,     0,   111,     0,   118,   112,   931,   923,
     929,     0,  1170,     0,  1172,  1174,     0,     0,   993,     0,
       0,     0,     0,  1117,  1294,  1297,     0,     0,     0,  1855,
    1857,  1982,   693,   698,   701,   714,   712,   671,     0,   770,
     768,   766,   764,   774,   772,     0,     0,   762,   812,   760,
     745,   756,   754,   810,   786,     0,   748,   758,  1003,   999,
       0,     0,     0,     0,   719,     0,     0,     0,     0,     0,
       0,     0,  1678,     0,  1546,  1547,  1833,  1504,  1569,     0,
       0,     0,  1831,     0,  1484,  1479,  1478,  1491,  1490,  1495,
    1495,  1493,  1494,  1485,  1480,     0,     0,  1486,  1487,  1746,
    1865,     0,     0,     0,   604,   606,     0,     0,   619,   611,
     613,     0,   608,   609,     0,     0,   627,   629,     0,     0,
     625,   919,   890,   230,     0,   660,   662,   657,     0,   545,
     534,     0,   529,     0,     0,   545,   545,   575,   574,     0,
       0,  1802,  1694,     0,     0,  1777,  1620,  1621,  1619,     0,
    1806,     0,     0,     0,     0,     0,     0,     0,  1768,     0,
    1557,  1558,  1560,  1563,     0,  1570,  1571,     0,     0,  1618,
    1755,  1749,  1771,  1787,  1788,  1786,  1784,     0,     0,     0,
    1941,   468,   507,   504,     0,   245,  1235,  1213,     0,     0,
       0,     0,     0,  1384,     0,     0,     0,  1380,     0,     0,
       0,  1374,  1658,  1656,  1625,  1637,  1639,  1643,  1645,  1636,
    1630,  1635,  1649,  1628,  1657,  1633,  1648,  1634,  1655,  1647,
    1531,  1622,  1623,  1624,     0,  1369,  1365,     0,     0,  1353,
       0,     0,   676,     0,     0,     0,  1968,     0,     4,     8,
      10,     0,   498,   441,     0,     0,     0,     0,  1042,     0,
       0,     0,     0,     0,     0,     0,     0,   736,     0,     0,
     171,   169,     0,     0,   151,     0,   161,   167,   746,   156,
     158,     0,  1039,  1050,  1051,     0,     0,  1943,   443,     0,
    1924,  1925,  1054,     0,     0,  1052,   366,   371,   654,   365,
       0,   368,   373,     0,   498,  1429,   645,   643,     0,   819,
    1106,  1108,     0,   396,  1193,  1191,     0,  1203,  1185,     0,
       0,  1284,     0,     0,     0,   104,     0,     0,    78,    84,
      74,    71,  1982,  1982,   114,   109,   123,   119,     0,   113,
     813,   932,   671,  1982,   922,   921,   930,  1044,     0,     0,
     991,   992,   986,  1012,   498,  1123,  1119,  1120,  1122,  1296,
    1862,  1864,   723,   717,   715,     0,    24,     0,  1982,  1982,
    1982,  1982,  1982,  1982,   776,   750,   778,   752,  1982,  1982,
    1982,  1982,     0,   744,   749,  1982,   671,   808,   806,   809,
     807,     0,     0,    46,    44,    41,    35,    39,    43,    38,
      31,    40,     0,    34,    37,    32,    42,    33,    45,    36,
       0,    29,    47,   800,     0,   721,  1813,     0,  1811,  1763,
    1809,  1750,  1751,  1743,  1729,  1744,     0,     0,     0,  1093,
    1545,  1548,     0,     0,     0,  1441,  1413,  1836,  1835,  1834,
       0,     0,     0,  1489,  1492,     0,     0,     0,     0,     0,
    1436,     0,  1435,     0,  1437,  1432,  1433,  1434,  1425,  1426,
       0,     0,     0,   618,   623,     0,     0,  1982,  1982,   596,
     610,   633,   621,   635,  1982,  1982,   631,   615,   626,   882,
     352,   545,     0,   533,   545,     0,   545,   545,   527,   526,
    1719,  1717,  1718,  1714,  1716,  1713,  1715,  1695,     0,     0,
       0,     0,  1803,     0,     0,     0,  1801,     0,     0,     0,
       0,  1783,  1800,     0,  1561,     0,     0,  1687,  1564,     0,
       0,     0,     0,  1556,  1575,  1577,  1579,  1617,  1616,  1615,
    1581,  1597,     0,  1572,  1573,  1758,  1336,     0,     0,     0,
    1848,     0,  1852,   224,     0,  1261,  1280,     0,  1268,  1261,
    1131,     0,  1679,     0,  1513,     0,  1516,  1682,     0,  1521,
       0,     0,  1381,  1382,     0,     0,  1385,  1387,  1389,     0,
    1373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1529,  1528,  1527,     0,  1532,  1533,     0,  1368,     0,
    1362,  1364,  1674,     0,  1676,  1666,     0,  1668,  1970,  1342,
       0,  1338,     0,     0,  1343,   897,     0,     0,  1142,     0,
       0,     0,  1400,  1975,  1974,   653,     0,     0,    48,     0,
     739,   741,   740,  1401,   746,  1982,  1982,   163,   679,   173,
     165,   175,   155,   162,  1982,     0,     0,     0,     0,     0,
    1946,     0,     0,     0,     0,     0,     0,  1099,     0,  1430,
     590,     0,   818,  1104,     0,  1290,  1291,  1951,     0,    96,
       0,    65,     0,     0,     0,    81,     0,    96,    96,    96,
     122,   117,  1982,  1982,   107,     0,   933,   927,   935,   934,
     924,   640,   973,     0,     0,     0,   725,   704,   718,   672,
     787,     0,   771,   769,   767,   765,   775,   773,     0,  1982,
       0,  1982,   763,   761,   757,   755,   811,   759,    24,   801,
       0,     0,     0,    27,     0,  1816,     0,  1730,     0,     0,
    1742,  1725,  1741,  1549,     0,  1506,     0,  1440,     0,     0,
    1832,     0,  1829,     0,  1497,  1501,  1477,  1499,  1502,     0,
    1488,  1747,     0,     0,     0,     0,     0,     0,  1866,  1439,
    1438,  1427,  1422,  1424,  1476,     0,     0,   620,   617,   612,
     614,     0,  1982,  1982,   628,   630,  1982,  1982,     0,   535,
       0,   539,     0,     0,   531,   530,     0,     0,     0,     0,
       0,     0,  1799,  1807,  1795,  1796,  1797,  1798,  1566,     0,
    1559,  1565,  1580,  1584,     0,  1597,  1583,     0,     0,  1598,
    1610,  1611,  1608,  1614,  1613,  1609,     0,     0,     0,     0,
       0,  1612,     0,     0,     0,  1553,  1554,  1772,     0,  1574,
    1568,  1337,  1756,  1446,  1442,  1443,  1448,  1447,  1754,  1336,
       0,     0,  1259,  1260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1258,     0,     0,  1246,  1247,
    1248,  1245,  1250,  1251,  1252,  1249,  1236,  1227,     0,     0,
    1283,     0,     0,  1222,     0,     0,     0,     0,     0,     0,
       0,  1214,  1215,     0,  1144,     0,  1683,     0,  1684,     0,
       0,     0,     0,  1520,  1519,  1384,  1518,  1510,  1375,  1659,
       0,     0,     0,     0,     0,     0,  1660,  1652,     0,     0,
       0,  1652,  1688,  1526,  1539,  1544,     0,  1541,  1538,  1540,
       0,  1542,  1530,  1534,  1535,  1384,  1370,  1366,     0,     0,
    1341,  1340,     0,  1325,     9,     0,  1315,   898,  1138,   378,
       0,  1315,     0,     0,  1966,     0,     0,  1025,    49,     0,
     798,   172,   170,     0,  1982,     0,     0,     0,  1982,   168,
     157,     0,   160,   159,     0,  1031,  1035,     0,  1928,  1927,
    1926,     0,     0,   370,     0,   593,     0,  1982,   820,     0,
     671,  1194,     0,  1285,    70,     0,     0,   105,    68,    96,
      79,    85,     0,     0,   124,   120,   814,  1982,   937,   671,
     936,     0,   637,     0,   844,   845,   843,  1121,   728,   726,
       0,   708,   705,     0,   777,   751,   779,   753,   788,   804,
     805,   802,   803,    30,    28,     0,  1810,  1759,  1731,  1727,
    1726,     0,  1505,  1763,  1508,     0,  1415,  1410,  1409,  1412,
       0,     0,  1496,     0,     0,  1759,     0,     0,  1903,  1901,
       0,     0,  1885,  1900,     0,     0,  1902,     0,     0,     0,
       0,     0,  1939,  1899,  1891,  1918,  1919,     0,  1883,  1886,
    1887,  1898,  1890,  1920,     0,  1876,  1875,  1879,  1881,     0,
    1874,     0,  1877,  1868,     0,     0,   624,   622,   634,   636,
     632,     0,     0,   545,     0,   545,   545,     0,  1762,     0,
    1695,     0,     0,     0,  1562,  1582,  1576,  1578,  1585,  1587,
    1585,     0,  1592,  1585,     0,  1590,  1585,     0,  1600,  1599,
       0,  1601,     0,  1552,     0,  1450,  1449,  1445,  1757,     0,
     250,  1253,  1254,  1255,  1257,  1240,  1238,  1237,  1241,  1242,
    1239,  1256,  1243,  1244,  1228,  1018,  1263,  1015,     0,     0,
    1281,  1226,  1225,  1220,  1218,  1217,  1221,  1219,  1223,  1224,
    1216,  1269,  1130,     0,  1511,  1517,  1686,  1679,  1522,  1383,
    1626,  1638,     0,  1640,  1642,     0,  1644,     0,     0,     0,
    1650,  1629,  1654,     0,  1512,  1514,     0,  1536,  1537,  1677,
    1669,  1339,     0,     0,  1331,  1326,  1327,  1344,     0,  1322,
    1323,     0,     0,  1336,  1316,  1317,     0,    24,  1141,  1311,
       0,     0,  1048,     0,    50,  1028,     0,    24,   174,   164,
       0,   681,   683,   176,   166,   798,     0,  1944,  1057,     0,
     369,  1431,     0,  1105,    24,     0,     0,    66,     0,    82,
      91,     0,    75,    72,   928,   925,   641,  1982,   987,     0,
    1982,   724,   703,   709,   671,  1820,     0,  1818,     0,     0,
    1732,  1728,  1507,     0,  1509,  1503,     0,  1414,     0,  1830,
    1498,  1500,  1475,     0,  1889,  1888,     0,     0,  1618,     0,
    1618,  1618,  1618,  1618,  1892,     0,     0,  1872,     0,     0,
       0,     0,  1905,  1873,     0,     0,     0,     0,     0,     0,
    1867,  1428,  1481,   892,   891,   353,   536,     0,     0,   541,
     540,  1720,  1843,  1846,  1844,  1567,     0,  1604,  1606,     0,
    1593,  1596,  1595,  1603,     0,  1605,  1585,     0,  1555,  1444,
    1851,   225,  1020,  1019,  1017,     0,  1262,  1145,  1149,  1151,
       0,  1155,     0,  1153,  1157,  1146,  1147,     0,     0,     0,
    1680,  1685,     0,     0,  1661,  1653,  1631,     0,  1632,     0,
       0,  1329,  1324,  1330,  1328,  1321,  1320,  1319,  1314,  1318,
     379,   376,     0,  1046,     0,     0,     0,  1027,   799,   152,
     680,    24,  1037,  1056,   591,  1102,    67,  1286,    87,     0,
       0,    80,    91,    91,    91,  1982,   638,     0,     0,   727,
     789,     0,  1817,  1760,  1753,     0,  1416,     0,  1753,  1916,
       0,     0,  1921,     0,     0,     0,     0,     0,     0,     0,
       0,  1884,  1907,  1908,  1906,  1904,  1882,     0,  1878,  1880,
    1869,  1870,  1482,     0,  1474,   545,   545,  1586,  1808,  1588,
       0,  1591,  1589,  1607,     0,  1016,  1982,  1982,  1159,  1982,
    1161,  1982,  1982,  1148,  1282,  1270,     0,  1641,     0,  1651,
       0,  1543,   381,  1047,  1965,     0,     0,     0,     0,     0,
       0,    55,     0,    54,     0,    52,     0,     0,   153,  1109,
      91,    96,    91,    92,    86,    76,    73,   926,     0,     0,
     729,    24,  1819,  1752,  1761,  1420,     0,  1417,  1419,  1733,
    1917,     0,     0,  1915,     0,     0,     0,     0,     0,  1893,
    1914,     0,  1483,   538,   537,  1594,  1602,  1150,  1152,  1982,
    1156,  1982,  1154,  1158,  1681,  1646,  1515,   383,   388,   386,
     377,     0,   384,   390,    57,    62,    59,    61,    58,    60,
      56,     0,    51,     0,   682,   684,  1113,  1103,     0,  1111,
    1287,    88,    83,   639,   988,  1982,   790,     0,  1411,     0,
    1734,  1748,  1913,  1922,  1909,  1910,  1911,  1912,     0,  1894,
       0,     0,  1160,  1162,  1982,  1982,   382,   385,  1982,    53,
       0,  1982,  1110,  1112,     0,   725,  1418,     0,  1738,  1735,
    1736,     0,     0,  1871,   389,   387,   391,     0,  1114,    89,
     730,     0,     0,     0,  1896,     0,  1895,  1029,    93,     0,
    1739,  1737,     0,    95,     0,    90,     0,  1897,    94,  1740
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   848,   849,   850,   851,  1079,  2158,  2159,   187,   329,
     188,  1452,  1453,  1981,  2320,  3373,  2847,  2848,  3275,  3374,
    3375,   852,  1224,  2885,  2579,  3294,  2578,  3293,  1917,  2576,
    3140,  2889,  3289,  2577,  3141,  3381,  3484,  3508,  3291,  3515,
     666,   667,   668,  1583,  2234,   853,  1595,  1229,  1593,  1926,
    2245,  1923,  2243,  2248,  2583,  1594,  2242,  1927,  2582,    11,
      84,   240,   551,   128,   691,   692,   854,    12,    34,    35,
      36,    37,    38,   856,  1142,  1854,  1478,  2184,  2188,  2189,
    2185,  2186,  2854,  2858,  2544,  2536,  2535,  2537,  2540,   507,
     279,   618,   857,    63,    64,    14,    48,   120,    78,   263,
      80,    81,   203,   344,    82,    83,   250,   349,   235,  1039,
     532,  2741,   380,   960,  2044,   408,   409,   264,   236,   362,
     351,   357,  1395,  1396,   124,   550,   125,   126,   368,   237,
     364,   350,   352,   534,   238,   590,   252,   255,   253,   254,
     979,   566,   567,   569,   574,   963,   256,   257,   399,   571,
     199,    15,    59,   157,   158,   159,   969,  2678,   160,   260,
     248,   402,   403,   404,   405,  1877,   858,   859,   860,   861,
    1100,  3362,  3107,  1454,  3430,  3431,  3432,  3475,  3474,  3478,
     862,   863,   864,   865,   866,   867,   868,  1090,   508,  1095,
    1444,  1445,  1494,  1197,  1495,   306,   307,   308,   309,   310,
     465,   509,  1377,   510,   511,   512,   513,   514,   515,   516,
    1015,   189,   526,  1026,  1028,  1770,  1025,  1769,   190,   519,
    1021,   518,  1020,   521,  1023,   520,  1022,   980,   993,   311,
     312,   192,   313,   432,   433,   434,   435,   416,   437,   869,
    1162,  1880,  2877,  2215,    95,   245,   560,  1693,  1292,  1293,
    1294,  1690,  1691,  2031,  2032,  2033,  2377,  2378,  1694,  1695,
    2027,  2381,  2373,  2039,  2040,  2384,  2385,  2676,  2672,  2673,
     870,  3147,  3388,  2902,   871,  1506,    65,  1839,  1840,  2209,
     417,   439,  1134,  1202,  1071,  1122,  1105,  1144,  2276,    66,
    1072,  1063,  1811,  2539,    67,   314,   872,  1234,   873,  1247,
    1248,   874,   875,   876,   877,  1255,  2911,  1276,  3152,  1277,
    1955,  1278,  2273,  1279,  2597,  1280,  1984,   878,  1951,  2596,
    2910,  3150,  3149,  3455,    96,    16,    17,   879,  1472,  1844,
    1845,  1846,  1974,  1637,  1975,  1976,  2609,  2611,  2291,  2290,
    2295,  2289,  2288,  2281,  2280,  2279,  2278,  2283,  2282,  2285,
    2287,   880,   881,  1140,   882,  1633,  1262,  3391,   883,  1560,
    3117,  2322,  2323,  1977,  2292,  2251,  2585,  1191,  1534,  1884,
    2218,  1885,  1530,   884,   885,  1240,  1941,  2906,   886,   887,
     888,   889,    18,    19,    20,    53,    21,    22,    23,    97,
      98,   890,    99,    24,   951,    25,   100,   101,   137,   562,
    1699,  2389,  3204,   102,   133,   373,   891,  2516,    26,    27,
      28,    29,    30,    47,    70,   103,   246,   561,   954,   955,
    1296,  1697,   892,  1235,  2255,  1930,  2253,  3295,  2897,  1931,
    2252,  2588,  2899,   893,   894,   895,  1116,  1117,  1598,   896,
    1281,  1282,   897,  1645,  1283,   315,    72,    73,    74,    75,
    1605,   163,   116,    76,   113,   195,   196,  1606,  1607,  2262,
    1608,   695,   696,  1264,   697,  1265,  1195,  1196,  1609,  1610,
    1448,  3046,  3047,  3234,  1132,  1133,   898,  1467,  3277,   899,
    2866,   900,  1482,  1483,  1484,  1860,  1858,   901,   902,  2168,
    2195,   903,  1871,  2205,   904,  1192,  1193,  1544,  1548,   905,
    1056,   906,  2333,   907,  3379,  2880,   908,  2222,  3447,  3448,
    3449,  3481,  1199,   909,  1611,  1943,  2266,  2267,   910,   911,
    1832,   912,  1048,  1437,   913,   914,   915,  2458,  3050,  3245,
    3246,  3346,  3347,  3351,  3349,  3352,  3419,  3421,   916,   917,
    1600,  1935,   918,  1602,  1572,  1573,  1574,  1907,   919,  1214,
    1212,   920,   921,  1899,  1568,  1208,   202,  1575,  1576,   316,
    2459,  2781,  2782,  2766,  1087,  1088,  2455,  2767,  2770,   104,
     132,   554,  1404,  2107,  2783,  3248,   447,   922,  1206,   105,
     130,   552,  1402,  2106,  2771,  3247,  2456,  1228,  2569,  3136,
    3380,  1902,   923,  1618,   924,   925,   926,   927,  1103,  2166,
    1081,  2161,  3103,  3104,  3105,  3261,  3094,  3095,  3096,   928,
    2732,  2510,  2511,  2513,  1795,   929,   930,  1414,  1415,  1416,
    1804,  2147,  1417,  2144,  1801,  1418,  2120,  1796,  1419,  1420,
    1421,  2112,  2117,  1422,  1790,  1791,   931,  1112,  1092,   932,
    1671,  1672,  1999,  2938,  3168,  2639,  2935,  3396,  3397,  1673,
    2021,  1651,  2369,  2662,  2984,  2560,  2876,  2370,  1674,  1675,
    2090,  2734,  2735,  2736,  3027,  1676,  1677,  1491,   933,  1149,
     934,  1289,  1678,  1679,  2015,  3334,  2016,  2017,  2018,  2353,
    2643,  2646,  2647,  1680,  2343,  2634,  3165,  1784,  1785,  2821,
    2463,  3084,  2464,  1786,  2468,  1797,  2495,  1798,  2496,  2822,
    2823,  2824,  2825,  1681,  1993,  1994,  2340,  1682,  2729,  2443,
    2725,  2085,  1748,  2080,  2081,  2082,  2699,  1749,  2086,  2444,
    2730,  2433,  2434,  2435,  2436,  2437,  3217,  3008,  3337,  2438,
    3219,  3220,  2723,  2439,  2724,  2440,  2069,  2140,  2141,  2142,
    3078,  2143,  2800,  2807,  3255,  2465,  1060,  2648,  2788,  2977,
    2467,  2428,  1350,   317,  1351,  1729,   458,   459,  1730,  2407,
      46,   935,   936,  2930,  3161,  2627,  3160,  3461,  3489,  3490,
    2631,  2334,  1683,  2335,  2358,  2945,   621,  2330,  2331,  2091,
    2446,  3159,  2934,  1352,  1000,  1353,  1354,  2726,  2441,  1356,
    1357,  2071,  3339,   937,   938,  1986,  2332,  2926,  3156,  3157,
    1648,   939,  1098,  1685,  1686,  2003,  2641,  1687,  1688,  2349,
    1762,  2064,  1358,  1359,  1360,  1361,   940,  1243,  1622,  1623,
    1624,  1947,  1625,  1948,  1689,  2359,  2983,  3200,  2658,  2980,
    2981,  2982,  2979,  2967,  2968,  2969,  2970,  2971,  2972,  3313,
     941,  1869,  2200,  2201,  1150,  1362,  1363,  1152,  1153,  1154,
    1364,  1155,  1489,  1863,  1864,    31,   943,  1216,  1908,  1475,
    1562,   944,   945,  2528,   946,  2156,  1075,  1818,   947,   948,
      41,   555,   556,   557,   558,   559,   949
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2643
static const short yypact[] =
{
     264,  1028, -2643,   377,   377,   377,  1178, -2643, -2643,  1178,
     377, -2643, -2643,    43, -2643, -2643, -2643, -2643,   510, -2643,
   -2643, -2643,  1562, -2643, -2643, -2643, -2643, -2643,   237, -2643,
   -2643, -2643, -2643, -2643,   583,   782, -2643,   991, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,   367, -2643,   910,   695, -2643,
   -2643, -2643, -2643,   376, -2643, -2643, -2643, -2643, -2643,   475,
     377, -2643,   377,   853,    43, -2643,   833, -2643, -2643, -2643,
   -2643, -2643, -2643,   596,   499, -2643, -2643, -2643,  1227,   830,
     377, -2643, -2643,  1246,   582,   377, -2643, -2643,   377, -2643,
   -2643, -2643,   377,   377, -2643, -2643, -2643, -2643,   376, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643,  4918, -2643,   499,
   -2643,   896,  3583, -2643, -2643,   778, -2643, -2643,  1350,   695,
     792, -2643, -2643, -2643, -2643, -2643,  8833,   377, -2643, -2643,
     377,   887,   377,    43, -2643, -2643, -2643,   377, -2643, -2643,
    1002,   902,  1264, -2643, -2643,   933, -2643,   957, -2643,   997,
   -2643, -2643,  1033, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,  1044, -2643, -2643, -2643,  1043,  1071,  1074,
    1079,  1100,  1104,  1107,  1121,  1128,  1150,  1153,  3583,  1168,
    5291,  1174,  1182,  1201,  1204,  1215,  1218,  2121,  1635, -2643,
   -2643, -2643, -2643,   346, -2643,   143, -2643,  3583, -2643,   228,
   -2643, -2643, -2643,    97, -2643, -2643, -2643,   770, -2643, -2643,
   -2643, -2643, -2643, -2643,  1002,  1234,  1237,  1275, -2643,  1264,
   -2643, -2643,  1297, -2643,  1301, -2643,  1277, -2643, -2643,  1310,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
      43,  1325,  1642,  1342, -2643,    43,    43,  1354,   377, -2643,
     401,  1710, -2643,  1072,  1268, -2643,  1157,  1279,  1777,  1819,
     377,  1822,  1835,  -334,  1185, -2643,   261,    36,    36,    36,
      36,    36,  5291,  1521,   184,    54,  5291,   952,  5291, -2643,
    5291,  5291,  5291, -2643, -2643, -2643,  1280,  1373,  1378,  5291,
    1313,  1379, -2643,  5291,  5291,  1385, -2643,  1387, -2643,  1182,
    1391,  1393,  1396,  1398,  1856,  7612, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,  1407, -2643, -2643, -2643, -2643,
   -2643, -2643,   261,   261, -2643, -2643, -2643, -2643, -2643,  3583,
   -2643,   377, -2643,   377,  3583,  1372,   185, -2643, -2643, -2643,
   -2643,  1866, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
    1410, -2643,  1410,   401,  1871,  1878,  1879, -2643, -2643, -2643,
    1880,  1882,   695,  1822,  1410,  1883,  1240, -2643,  1805, -2643,
   -2643,  1471, -2643,  1503, -2643, -2643, -2643,  1251, -2643, -2643,
    1905,  1488, -2643,  1461, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643,  1279,  1461, -2643, -2643, -2643, -2643, -2643, -2643,  1470,
     297,   359,   536, -2643,  2425, -2643, -2643, -2643,  1478,  1960,
     366, -2643, -2643, -2643,  1513,  1481,   397, -2643,  -110,  1515,
    1519,   419,   434,  5598,  1522,  1528,   155,   109, -2643, -2643,
     159,  1948,  1535, -2643, -2643, -2643, -2643,   435, -2643, -2643,
    6539, -2643,  3869,  7742,  3103,  3103,  5291, -2643,  1452,  5291,
    7612,  1497, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  1307,
    1971,  6591,  7612,  1452,  1972,   720,  5291,  5291,  5291,  5291,
   -2643,  5291,  5291,  5291,  5291,  5291,  5291,  5291,  5291,  5291,
    5291,  5291,  5291,  5291,  5291,  5291,  5291,  5291, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  5291,  5291,
   -2643, -2643,  1505,  5291, -2643,  5291,  1512, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643,   261,  5291,  5291,
    5291,  5291,  1550,  1999,  2121,  1518,  3919,  1520, -2643,  3583,
    1487, -2643,  1332,  1985, -2643,  1337, -2643,  1990,  1565,  1566,
     440,  1704,   462,   489,   559,  1539, -2643,   500, -2643, -2643,
   -2643,   148,   377, -2643,   377,  1603, -2643,  5538,   792,  6065,
    1997,  -288,   377,  2009,   -73, -2643, -2643,  1268,  2004, -2643,
   -2643, -2643, -2643,  2010, -2643,  2011, -2643,  2012, -2643,   377,
   -2643,   377, -2643, -2643,  1822,  2014, -2643, -2643,  1394, -2643,
   -2643, -2643,   377,    36, -2643,  3583,    44, -2643, -2643, -2643,
   -2643, -2643,  1268,  1268,  2016,  -139,  1268,  1477, -2643,  2017,
    1401,  1534, -2643, -2643,    54, -2643, -2643, -2643,  1602,  7612,
     386,  1609,  6782,  2030,  1313,  1610, -2643,  1611,  1612, -2643,
    6803,  6856,  6877,  6909,  7663,  7685,  7742,  7709,  1241,  8065,
    8313,  5273,  4168,  4880,  5839,  3103,  3103,  4138,  4138,  1024,
    7612,  7120,  7437,  1452,  7612,  7488,  1452, -2643,  7612,  7612,
    7612,  7612, -2643,  2034, -2643, -2643, -2643,  2062, -2643,  7612,
   -2643,   190,  3583, -2643,  1615,  2054,   -73, -2643, -2643,  2049,
   -2643,  1587,  2053, -2643,  2056, -2643, -2643, -2643,  2057, -2643,
   -2643,   -14, -2643, -2643,  1408,  1634,  2084, -2643,  1644, -2643,
   -2643, -2643,   377,   377,   261,   261,   261,   377,   974,   377,
    1547,   284,   284,  1607,   377,   377,   284,   284,   377, -2643,
    1547, -2643, -2643,   377, -2643,   976, -2643, -2643, -2643,   284,
   -2643, -2643, -2643, -2643,   377, -2643, -2643, -2643, -2643,    78,
      78,  5291, -2643, -2643, -2643,  1607,  1607, -2643, -2643,   284,
   -2643, -2643,   284, -2643, -2643,   377, -2643, -2643,   284, -2643,
   -2643,   261,   284, -2643, -2643,  5291,   284,   261,   377,   261,
     284, -2643, -2643,   249,   284,   284,   249,   284,   377,   249,
     284, -2643,   284,   284,   284, -2643,  1547, -2643, -2643,   261,
     284, -2643, -2643,   284,    56,   377, -2643,  1607, -2643, -2643,
     284,  1041, -2643, -2643,   261,  1416, -2643,   284, -2643,  7920,
     261,  5291,    36,    36,   284, -2643, -2643,   974,   261,   380,
   -2643,  5291, -2643,  1659,  5291,   284,    51, -2643,  5291,   284,
    2074,   261, -2643,   284,  5291, -2643,  5291,    78,   377,   284,
     377,    36,   284,   377,    36, -2643,   377,   200, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643,   444, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  1112,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643,   735,   377, -2643,   676, -2643,  1648, -2643, -2643, -2643,
    1739, -2643, -2643,  1652,  1657,  1661,  1670, -2643, -2643,  1423,
    2119,  1679, -2643,  1691, -2643,   566, -2643,  1656, -2643,  1466,
   -2643, -2643,   425,  1268,  2127, -2643,  1702,   263, -2643,  2130,
   -2643,  1510, -2643, -2643, -2643,  1479, -2643, -2643, -2643, -2643,
    8517, -2643,  1280,  1707, -2643,  1280, -2643,  1280,  1280,  1280,
    1280,  1280,  2134,  2136,  2139,  5291,  1712,  2141,  5291,  1718,
    1722,  1724,  1725,  1728,  1729,  3919,  1730,  3919,  3919, -2643,
     241, -2643, -2643, -2643,  1811,  1731, -2643,  1732,  1733,  1506,
    1736, -2643, -2643,   377, -2643,   377, -2643, -2643, -2643,  1507,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643,   408,  1517,   692,
    1389,  1705, -2643, -2643, -2643, -2643,  1524,   701, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,  2184,  1516, -2643, -2643,  1711,
   -2643,  1607, -2643,  1662,   257, -2643, -2643, -2643,  1529, -2643,
    7612, -2643, -2643,  1564, -2643, -2643,  4401, -2643, -2643, -2643,
     261,  1588, -2643,  1607, -2643,  -123, -2643, -2643,  1873, -2643,
      99, -2643,  1701, -2643, -2643, -2643, -2643,  2216, -2643, -2643,
     491, -2643,  1551, -2643,  1556,  2216, -2643,  1569, -2643, -2643,
   -2643,  1745,    88, -2643,  1709, -2643,  1527, -2643, -2643, -2643,
   -2643,  1533,   262, -2643,  -226, -2643,  1557,  1651,  1715,  1846,
    1567, -2643, -2643,  1573, -2643, -2643,  5291,   112,  1133,  5291,
   -2643,   111,   284, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,    69,    69,    69, -2643,    69,  3364,    69,    69,
    1597,  -123,  1597,  1597,  1159,  1159,  1597,  1597,  1558,  -123,
    1639, -2643,  2247, -2643,  1773,   242, -2643,  2251, -2643,  -123,
      86,    35, -2643, -2643,  5291, -2643, -2643, -2643,  1148, -2643,
    1190, -2643,   792, -2643,  5291, -2643,  5291,  1767,  1769,  1771,
    1778,  1655,  1779,  1190, -2643,  1860,  1319,    90, -2643,  1643,
   -2643, -2643,   377, -2643, -2643,  1217, -2643,  2263, -2643,  2266,
     377, -2643,   213,   247,  1650, -2643, -2643,  2280, -2643,  1570,
    2280,  2282,  1574,  2280,  2282,  5291,  2280, -2643, -2643,   257,
     261, -2643, -2643,  1809,   317, -2643, -2643,  1802,   261,  5291,
    1803, -2643, -2643,  2269,  2270,  2170, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643,  1242,  1242,   284,   284,   284,  1476,
   -2643, -2643,  2151,   735, -2643, -2643,   774, -2643, -2643, -2643,
    1794, -2643, -2643, -2643, -2643,  4918,  1822, -2643, -2643, -2643,
    1632,   377,  1268,  2288,   347,  1268, -2643,   459,  1268,  1268,
    1664,  1669,  1687, -2643,  4051,  4051, -2643,  1557, -2643, -2643,
   -2643, -2643,  1328, -2643,  8225,  1827, -2643,  1828,  1830,  1832,
   -2643,  1832,  1832,  1833,  1836,  1839,  1844,   377,  -193, -2643,
   -2643, -2643, -2643,   115, -2643,    65,  1937, -2643, -2643,  1328,
   -2643,  1328,  1845, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  7612,   501, -2643, -2643,
     514, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,  1817, -2643, -2643,   522, -2643, -2643, -2643, -2643,
   -2643, -2643,    43, -2643,    43,   974,   697,   201,  2311, -2643,
   -2643,   564,   354,   795,  2333, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,   377,  1698,   377, -2643, -2643,  1706,   377,
    1721,   377,   377,  1607,  1688,  1850, -2643,  1853,   107, -2643,
   -2643, -2643,  1607, -2643, -2643,  2341, -2643, -2643,  1667, -2643,
     974,  1864, -2643, -2643, -2643,  1133, -2643,  1250, -2643, -2643,
    1250,  1190,   249,  5291,  5291,  5291,  1867, -2643, -2643,   261,
     261,  1607,  1673,  1190,    36,  1640,    56,   261, -2643,  1680,
    5291,  1950, -2643, -2643,  1747,   377,  1557, -2643,  3583, -2643,
   -2643, -2643,   377,  1139,  2359, -2643, -2643,  1692,   110,   257,
     261, -2643, -2643,  2347,  2351, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,  2725, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  7920,
     261,   261, -2643,  1159,  5291,    14,  1012,  1113, -2643, -2643,
   -2643, -2643, -2643,   127, -2643, -2643, -2643, -2643,  2156,  1922,
   -2643,  1931,   792,  5291, -2643,    92, -2643, -2643,   377,  2355,
      36,    36, -2643,  1734, -2643,    54,  1713,   261, -2643,   377,
     377,   377,  5291,   -70, -2643,  1750, -2643, -2643,   345, -2643,
    1847, -2643,  1849,  5291,  1180, -2643, -2643,  1717, -2643,  2390,
   -2643,  1793, -2643, -2643, -2643,   261, -2643, -2643,   173, -2643,
   -2643, -2643,   238, -2643, -2643, -2643, -2643,   377,    36,    36,
     183,   317,  2186,  2149,   261,   257, -2643,  1796, -2643, -2643,
    2359,  2375,  1944, -2643, -2643, -2643, -2643, -2643,  2025,  2025,
   -2643,   406,  1806, -2643, -2643,   377,  1607, -2643,  1607,  1607,
   -2643, -2643,  1607,  1607, -2643,   377,  1764,   386,  1607, -2643,
    1764, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
     265,   265,   393,  1016, -2643,   602, -2643,   774, -2643,    43,
    2388, -2643, -2643,  1392,  1962, -2643,   187,  1268,  2391, -2643,
    1268,  1740, -2643, -2643,  1963,  1965,  1744, -2643, -2643, -2643,
    1563,  1563, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
    1738,   386,  1966,  8590,   666,  8517,  1894, -2643, -2643, -2643,
     666,   666,   666,   666,  1754,  8517,  8517,   274,  1854,   760,
     377, -2643,  8517,  8517,  8517,  8517, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,  1758,  -198,  1133,  5291, -2643, -2643,  1980,
    1984,  2388, -2643, -2643, -2643, -2643, -2643,  1768,  1953,  1955,
    1957,   884,  1961,  1964, -2643, -2643, -2643,  2337,   377, -2643,
    2447, -2643, -2643,   292,  3130, -2643, -2643, -2643, -2643,   377,
   -2643, -2643,   292,  1742, -2643,   408, -2643,  1780, -2643,  1812,
   -2643,  2007,   499, -2643,  1784, -2643,  1818, -2643,  1862,  1974,
     377, -2643, -2643, -2643, -2643,  4401,   377,  1795, -2643,  1797,
   -2643, -2643, -2643, -2643,  1785, -2643,  2462,  2465, -2643,  2469,
    1838,  5291, -2643, -2643,  2472, -2643,  1810, -2643,  1938,  1798,
    2282, -2643, -2643,  1800,   942,   377, -2643, -2643,  2000,   284,
    1054,  1573,  2121,   311, -2643, -2643, -2643, -2643,  5291,  1607,
    1133,  -187, -2643,   377,   377,  5291,    16,  -123,  2483,  1329,
    2481,  2466,  2467,  3364, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643,   261,  2111, -2643, -2643, -2643, -2643,  2370,  5291,   792,
   -2643,  2218, -2643, -2643, -2643,  5291,    78, -2643,  2113,  2494,
    2495,   523,   527,   377,  2050,  1190, -2643,  3919,  2021,  2023,
    2028, -2643, -2643,  2080, -2643,  5291,   -66, -2643,  1852, -2643,
   -2643,   587, -2643,  5291, -2643, -2643,  1821,   896, -2643,  1397,
     377,  2493,  8320, -2643, -2643, -2643,   261,  1133,   261, -2643,
   -2643,    58, -2643,  2282,  2282,  1808, -2643,  1916,  1923, -2643,
   -2643, -2643, -2643, -2643, -2643,    36,    36, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,  3652, -2643, -2643, -2643, -2643,
      36,  3216,  2524,  2504, -2643,  1190,   925,   175,   140,  2371,
       4,   974, -2643,   584, -2643, -2643, -2643,  2044,    31,  1607,
     703,  1861, -2643,  1857, -2643, -2643, -2643, -2643, -2643,  2047,
    2047, -2643, -2643, -2643, -2643,  1939,  1859,  2540, -2643, -2643,
   -2643,   504,  1868,  1865, -2643, -2643,   261,   192, -2643, -2643,
   -2643,  1858,  1016, -2643,   377,   377, -2643, -2643,   377,   520,
   -2643, -2643, -2643, -2643,  2066, -2643, -2643, -2643,   483,  1268,
   -2643,   578, -2643,  2100,  2103,  1268,  1268, -2643, -2643,  1330,
    8517, -2643,   108,  2552,  2107,  2557, -2643, -2643, -2643,  8517,
   -2643,   528,  8517,  8517,  8517,  8517,   377,   529, -2643,   389,
    2559, -2643, -2643,    83,  7807, -2643,  2135,   377,  1891,   666,
    2175, -2643, -2643, -2643, -2643, -2643, -2643,  1330,  2545,  1330,
   -2643,  7612, -2643, -2643,  2086, -2643,  2058,  2059,   974,    80,
      80,    80,   530,  2337,    80,  7807,   377, -2643,   534,   377,
     537, -2643, -2643, -2643,  2083,  2087,  2090,  1328,  1328, -2643,
    2091, -2643,  2093,  2095,  2096,  2097, -2643, -2643, -2643, -2643,
    1106, -2643, -2643, -2643,   539, -2643, -2643,   542,   377, -2643,
     377,  1751, -2643,   377,  1789,  5291, -2643,   377,  2584, -2643,
   -2643,   292, -2643, -2643,  1917,   974,   292,   260, -2643,  1190,
    5291,  5291,  5291,  4716,  2590,  1607,   130, -2643,  1190,   377,
   -2643, -2643,   377,   377, -2643,   986, -2643, -2643,   324, -2643,
    1920,  5291, -2643, -2643, -2643,  2591,  3583,  2082, -2643,  1921,
    2596, -2643, -2643,  1190,  1968, -2643, -2643, -2643, -2643, -2643,
     377,  2282, -2643,   257, -2643,  1992, -2643, -2643,   545, -2643,
   -2643, -2643,   261, -2643,  5069, -2643,  1183, -2643, -2643,  2220,
    2579, -2643,  2199,  2202,  2092,  1934,  2205,  2123, -2643, -2643,
   -2643, -2643,   674,  2193, -2643, -2643, -2643, -2643,  2080, -2643,
   -2643, -2643,   268,   650, -2643, -2643, -2643,  2359,  5291,  2131,
   -2643,  2099, -2643, -2643, -2643, -2643,  2613, -2643, -2643, -2643,
   -2643,  2614, -2643,  1912, -2643,  2598,  -123,   377,  4028,  4028,
    4028,  4028,  4028,  4028, -2643,  2617, -2643,  2620,  4028,  4028,
    4028,  4028,  2725, -2643, -2643,  4028,    93, -2643, -2643, -2643,
   -2643,  2601,  2615, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,  2616, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
     552, -2643, -2643, -2643,  2602, -2643, -2643,  1607, -2643,   386,
   -2643, -2643, -2643, -2643, -2643, -2643,  1978,  1983,   131, -2643,
     584, -2643,    80,  1958,   284, -2643,  2143, -2643, -2643, -2643,
     377,   377,    80, -2643, -2643,   104,  1607,  1349,  8517,   325,
   -2643,  5291, -2643,  5291, -2643, -2643, -2643, -2643, -2643,  2029,
     284,   104,  1607,  2632, -2643,   261,   377,   920,   920, -2643,
   -2643,  2634, -2643,  2634,   590,   590,  2634, -2643, -2643,  1997,
   -2643,  1268,  2618, -2643,  1268,  1804,  1268,  1268, -2643, -2643,
    2153, -2643, -2643, -2643, -2643, -2643, -2643, -2643,   115,  1328,
    1973,  1328, -2643,  1328,  2188,  8517, -2643,  2204,  2206,  2207,
    2208, -2643, -2643,   274, -2643,   274,   377, -2643, -2643,  7936,
    1832,  3614,  1832,  2649,  2651, -2643, -2643, -2643, -2643, -2643,
   -2643,   441,  8517, -2643,  2155, -2643,  2334,   119,   175,   377,
   -2643,  2211, -2643, -2643,  5784,   125, -2643,  2026, -2643,   125,
    2657,  1607,   647,  2213,  2662,  1993, -2643, -2643,   555, -2643,
     556,   884, -2643, -2643,   563,   235, -2643, -2643, -2643,   292,
   -2643,  2643,  2643,  2646,  1991,  -172,  2647,  2652,  2653,  2647,
    2647, -2643, -2643, -2643,   196, -2643,  1260,   377, -2643,   292,
   -2643, -2643, -2643,  2008, -2643, -2643,  2015, -2643, -2643,   305,
     570, -2643,   377,   577, -2643,  5291,  2222,  2661,  2678,   595,
    1190,  2682, -2643, -2643, -2643, -2643,  5291,  2064,  2354,  5291,
   -2643, -2643, -2643, -2643,   324,  1060,  1060,  2686,   573, -2643,
    2688, -2643, -2643, -2643,  1060,   377,  2094,  1421,  2689,   377,
   -2643,  3583,   134,  1607,  2691,  1190,   174,  2483,  5291, -2643,
   -2643,  3364, -2643,  1975,  5291, -2643, -2643, -2643,  2692,  3919,
     261, -2643,   976,   377,   261, -2643,  2243,  3919,  3919,  3919,
   -2643, -2643,   674,  2193, -2643,  2725, -2643, -2643,  1254, -2643,
   -2643,  2072, -2643,  3583,  4984,  8320,    49,  1065, -2643, -2643,
   -2643,  2031, -2643, -2643, -2643, -2643, -2643, -2643,    36,  4028,
      36,  4028, -2643, -2643, -2643, -2643, -2643, -2643,  -123, -2643,
    1197,  1222,  3216, -2643,  2249,  2217,  8517, -2643,   140,   140,
   -2643, -2643, -2643, -2643,   608, -2643,  2173, -2643,    80,   769,
   -2643,  2027, -2643,   612, -2643, -2643,  2701, -2643, -2643,  2105,
   -2643,  2706,  8531,  8531,  8531,  8531,    80,    80, -2643, -2643,
   -2643, -2643, -2643, -2643,  2701,  2032,   261, -2643,  2634, -2643,
   -2643,   377,   590,   590, -2643, -2643,   590,  2439,  2036, -2643,
     580, -2643,  2265,  2267, -2643, -2643,  2697,  2271,  2043,  1330,
    2045,  2046, -2643, -2643, -2643, -2643, -2643, -2643, -2643,   614,
   -2643, -2643, -2643, -2643,   361,   202, -2643,  7807,  7807, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  4051,  4051,  2237,  4051,
    2240, -2643,  4051,   593,  8517,  2726, -2643, -2643,  7807, -2643,
   -2643, -2643, -2643, -2643,  2727, -2643,   711, -2643, -2643,  2334,
    2051,  2055, -2643, -2643,    78,    78,    78,  2710,    78,    78,
      78,    78,    78,    78,  2712, -2643,  2713,    78, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  5784, -2643,   261,  2063,
   -2643,  2234,  2719, -2643,  2723,  2728,  2730,  2732,  2733,  2735,
    1255,  2026, -2643,  2234, -2643,   974, -2643,  2736, -2643,  2392,
      80,  1464,    80, -2643, -2643,  2337, -2643, -2643, -2643, -2643,
    2298,  2299,   619,  1330,  2737,  1330, -2643,  2748,   628,  2312,
    2313,  2748, -2643, -2643, -2643, -2643,  1607, -2643, -2643, -2643,
    2277, -2643, -2643,  1260, -2643,  2337, -2643, -2643,   377,   377,
   -2643, -2643,   377,   177, -2643,   292,   186,  2359, -2643,  2241,
     974,   186,   310,  1190, -2643,  2764,  2287, -2643, -2643,  2325,
    2171, -2643, -2643,   377,  1060,  3583,  1499,   377,  1060, -2643,
   -2643,    36, -2643, -2643,  5291, -2643, -2643,   318, -2643, -2643,
   -2643,  1190,  2772, -2643,    36,  2359,   261,  2479, -2643,  2757,
    1916,  7612,  2759, -2643, -2643,   257,  2300, -2643, -2643,  3919,
   -2643, -2643,  2338,  2339, -2643, -2643, -2643,   650, -2643,  1916,
   -2643,  5291, -2643,   368, -2643,  2251, -2643, -2643, -2643, -2643,
    2290,  2386, -2643,  2774, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,   377, -2643,   113, -2643, -2643,
   -2643,    80, -2643,   386,  2592,   637, -2643, -2643, -2643, -2643,
     377,    80, -2643,   104,   104,  2187,  8787,  8787, -2643, -2643,
    8604,  2305, -2643, -2643,  2307,  2309, -2643,  2310,  2316,  2317,
    2320,   377,   585, -2643, -2643, -2643, -2643,   639, -2643, -2643,
    1979, -2643, -2643, -2643,   642,  2796,  2796, -2643, -2643,   648,
    2797,  2789, -2643,    84,   261,   104, -2643, -2643, -2643, -2643,
   -2643,  2538,  4918,  1268,  1807,  1268,  1268,  2362, -2643,  1330,
    2363,  1330,  1330,   274, -2643, -2643,  2651, -2643,  2322,  1937,
    2322,   236, -2643,  2322,   236, -2643,  2322,  4051, -2643, -2643,
    8517, -2643,  8517,  2649,   119, -2643, -2643, -2643, -2643,  1330,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,   718,  2807, -2643,   261,  1040,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,   370, -2643, -2643, -2643,  2296, -2643, -2643,
   -2643, -2643,  2791, -2643, -2643,  2374, -2643,  2798,  2380,  2802,
   -2643, -2643, -2643,  2381, -2643,  2345,  7807, -2643, -2643, -2643,
   -2643, -2643,   377,  2810, -2643,   177, -2643, -2643,  2812, -2643,
   -2643,  2813,   377,  2334,   186, -2643,    36,  -123, -2643, -2643,
    2404,  1190, -2643,  5291, -2643,  2215,  2816,  -123, -2643, -2643,
     576, -2643, -2643, -2643, -2643,   136,  2393, -2643, -2643,  1190,
    2282,  2614,  2541, -2643,  -123,  2394,  2395,  2483,  2365, -2643,
    2442,  2398, -2643, -2643, -2643, -2643, -2643,  2554,  2342,  5291,
    2364, -2643, -2643, -2643,  1916, -2643,   651, -2643,   261,  2255,
   -2643, -2643, -2643,  8517, -2643, -2643,    80, -2643,  2372, -2643,
   -2643, -2643,  2701,  2255,  1791,  1791,  2410,  8590,   666,  8626,
     666,   666,   666,   666,   606,  8626,  8531, -2643,  8626,  8626,
    8626,  8626, -2643, -2643,    80,  2851,    80,  8531,   284,  7807,
   -2643,  2614,    95, -2643, -2643, -2643, -2643,  2413,  2415, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,   196, -2643, -2643,   654,
   -2643, -2643, -2643, -2643,   660, -2643,  2322,  2862, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,   261,  2807, -2643, -2643, -2643,
     261, -2643,   261, -2643, -2643,  2112, -2643,  2569,  2573,  2850,
   -2643, -2643,  2424,  2196, -2643, -2643, -2643,  2428, -2643,    80,
     371, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,  1190, -2643,  2430,  9075,  2397, -2643, -2643, -2643,
    2212,  -123, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  2432,
     257, -2643,  2442,  2442,  2442,   650, -2643,  3583,  2258, -2643,
   -2643,   377, -2643,  2614,   760,   115, -2643,  8389,   760, -2643,
    2435,  8626, -2643,   672,  8626,  8626,  8626,  8626,  2866,   377,
     673, -2643, -2643, -2643, -2643, -2643, -2643,  2405, -2643, -2643,
   -2643,  2649, -2643,   377, -2643,  1268,  1268, -2643, -2643, -2643,
     208, -2643, -2643, -2643,  8517, -2643,  1998,  1998, -2643,  1998,
   -2643,  1998,  1998, -2643, -2643, -2643,  2408, -2643,  1330, -2643,
     675, -2643,  1188, -2643, -2643,    69,    69,    69,    69,    69,
      69, -2643,  2872, -2643,   679, -2643,  5291,  1523, -2643,   741,
    2442,  3919,  2442,  2483, -2643, -2643, -2643, -2643,  2600,   379,
   -2643,  -123, -2643, -2643, -2643, -2643,   682, -2643, -2643,  1431,
   -2643,  2451,  8626, -2643,  2452,  2453,  2454,  2457,   381,  2396,
   -2643,  8531, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  1998,
   -2643,  1998, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643,  1225, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643,  9075, -2643,  2906, -2643, -2643, -2643, -2643,   704, -2643,
   -2643, -2643, -2643, -2643, -2643,    58, -2643,  8389, -2643,  1829,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  2886, -2643,
    2887,   689, -2643, -2643,  1265,  1265, -2643, -2643,  1265, -2643,
    5291,  1004, -2643, -2643,  2464,    49, -2643,  2246,  2248,  2919,
   -2643,  2440,   383, -2643, -2643, -2643, -2643,  2476, -2643, -2643,
   -2643,   377,   377,  1829, -2643,  2908, -2643, -2643,   894,  2259,
   -2643, -2643,  2449, -2643,   257, -2643,   377, -2643,  2483, -2643
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2643, -2643, -2643, -2643, -2643,   373, -2643,   427,  -173, -2643,
   -2643, -1164,  -275, -2643, -2643, -1913, -2643, -2643, -2643, -2643,
    -499, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -1643, -2643,
    -970, -2643,  1919, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
     702, -2643, -2643, -2643, -2643,  1356, -2643,  1025, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,  2261, -2643,   -38, -2643, -2643,
    2918, -2643,  2917, -2643, -2643, -2643, -2643, -2643,   776,   412,
   -2643,   775, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,   -77,  1027,  1172, -2643, -2643,  2597,    17,
   -2643,  2842, -2643, -2643,  2839, -2643,  2749, -2643, -2643, -2643,
   -2643, -2643,  2612,  2291,  1195,  2605,  -534,  1171, -2643, -2643,
   -2643, -2643, -2643,  1199,  -663, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,   668, -2643,  2421,  2753,    18,  2356, -2643,
    -202,  1653, -2643,  2582, -2643, -2643, -2643, -2643,  2586, -2643,
   -2643, -2643, -2643,  -396, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,  2399, -2643,  2400, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -1247, -2643, -2643,  -456, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643,  -129, -2643, -2643,
    1154, -2643, -1071, -1192,  -635, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,  1970, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
    -623, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  2157, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643,  -590, -2643,   -98,
   -2643, -2643, -2643, -2643,  2562, -2643, -2643,  -240, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
    1693, -2643, -2643, -2643, -2643,   958, -2643, -2643, -2643, -2643,
   -2643, -1612, -2643, -2643,   945, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -1154,  -881,   819,  1118, -2643,
    -231,  -572,  -438,  -802,  1553, -2643,   870, -2643, -2185,    -3,
     244, -2643, -2643, -2080,  -111,  1484, -2643, -2643, -2643,   787,
    1367, -2643, -2643, -2643, -2643, -2643, -2643,   400, -2643,    87,
   -2643,  1369, -2643,  1046, -2643,   729, -2643, -2643, -2643, -2643,
    -482, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
     829, -2643, -2643, -1583, -2643,  1030, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643,  1530, -2643, -2643, -2643, -2643, -2643, -2643,
    -118, -2643, -2643, -1800, -2643, -2643, -2643, -2643,   484, -1983,
   -2643, -1160, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  2987, -2643,
   -2643, -2643,  2912,  2965,   624, -2643, -2643,  -243, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  2968, -2643,
   -2643,  2990, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  2068,
   -2643, -2643, -2643, -2643, -2643,  1093, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  -704,  2250, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643,  2361, -2643, -2643,   -44, -2643,
   -2643,  1088, -2643, -2643,  1422,  -168,  2693, -2643, -2643, -2643,
   -2643,  -151, -2643, -1080,  1986,  1395, -1489,  1483, -2643,  1092,
    1775,   -20,  -199, -2643,  2236,  1568, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  1493, -2643, -2643, -2643,
    -796, -2643,  -637, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
    -405, -2643, -2643, -2643, -2643, -2643, -2643,   454, -2643, -2643,
    1590, -2643,  1239, -2643, -2643, -2643, -2643, -2643,   269, -2643,
    -194, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  1480, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  -526, -2643,  1149,  2593,
   -2643, -2643,   275, -2643,  -699, -2643, -2643,   289,   600, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643,  1120, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,   219, -2643,   -43,   -40, -2643, -2643,   -32, -2643,
   -2302, -2643,   232,   904, -1377, -2643, -2643, -2643,  1263, -2643,
   -1736, -2643, -2643, -2643, -1746, -2643, -2643, -1720, -2643, -2643,
   -2643, -2643, -2054, -2643,  1283,   954, -2643, -2643, -2643, -2643,
   -2643,   736, -2643, -2643, -2643, -2643, -2643, -2643,  -382, -2643,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643,    52, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2643, -2643, -2643, -2643,  1409, -2643,  1411, -2643,   723,  1067,
   -2643, -2209,   139, -2643, -2643, -2643, -2643, -2643, -2643,   295,
   -2643, -2643,  -174, -2643,  -644, -1372, -2643, -2643, -2643, -2643,
   -2643,   266, -2643, -2643, -2643, -2643, -2643, -1666, -2643, -2643,
   -2643, -2643, -2643, -2643, -2186,  1008, -2643, -2346,  1090, -2643,
   -2643, -2068,   385,   387,   664, -2643, -1745, -1774, -2643, -2643,
      85,  -246, -2643, -2643, -2643, -2643, -1536, -2643, -2643, -2643,
     290, -2643,   618,  -706, -2643,  -574,   259,  1447,    38, -1804,
     645,   681,   278, -2643, -2643, -2643, -2643,  2484, -1275, -2071,
    3100, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,  -392,
   -2643, -1483, -2643,  1823, -2643, -2643,   680,   667, -2643, -2642,
     671,   171,   482,  -415, -1644, -1999,  1380,   105,  -140, -1279,
   -2643,  1386, -2643, -2643, -2643,  1486,  -810, -2643, -2643,  -165,
    1848, -2643,   601, -2643, -2643,   788,   198, -2643, -2643, -2643,
   -1986,   -35,  -270, -2643,   167, -2643, -2643, -2643, -2643,  1525,
   -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
   -2555,   -53, -2643, -2579, -1733, -1070, -1122, -2643, -2643,   -41,
   -2643, -2643, -2643,   592, -1089,  1383,  -762,  2002,  1666,  1660,
    -669, -2643, -2643,   603,   956,    89, -2643, -2643, -2643, -2643,
    1681, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643, -2643,
     734,  1140,  2604, -2643, -2643, -2643, -2643
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1979
static const short yytable[] =
{
      40,    42,    43,    45,  1438,   277,    45,    50,   582,  1213,
    1031,  1879,  1563,   981,   191,    94,   985,  1529,   109,  1508,
    1509,  1205,  1510,  2019,  1531,  1532,  2450,  1237,  2452,   336,
     421,   422,   701,  1018,  1787,  1555,  1803,   419,   420,  1151,
     593,  1089,   994,    39,   438,  1720,  1721,  2475,  1957,  1958,
     970,   305,   390,  2145,  2187,  1387,   244,   108,  1390,  2473,
      94,  2408,  2687,    39,   976,    79,  2146,  2587,  2321,  1497,
     115,    39,  1121,  2121,  2974,  2975,  2976,   122,    39,   436,
     191,    39,   129,    39,  1763,   131,  1764,  2060,  1498,   134,
     135,   593,    39,  1470,   118,  1502,    39,  1905,   593,   191,
    2943,  2978,   283,  2541,  1085,  1066,  1091,    39,    86,   193,
      39,  2618,  1635,  2409,  1084,  1868,   341,  1470,  1746,  1499,
    1746,   283,   342,   343,   239,  1096,  1590,   241,   427,   243,
    1107,    39,  1554,   428,   247,   430,    79,  1456,  1245,  1068,
     204,   593,   106,   423,  1066,  2733,    39,   440,   334,   442,
    2531,   443,   444,   445,  2868,  1066,   524,    39,    39,  1066,
     450,    39,  2664,   369,   461,   462,  2337,    39,   374,   375,
    1161,  1093,  1094,  2908,   604,   193,  1198,   193,   609,  1631,
    1156,   605, -1977,  1159,  1630,   610,  1215,   106,  1868,  1230,
     334,  1823,  1204,  1236,   193,   334,   339,  2375,  1640,  1242,
    1209,  1244,    39,   427,  2072,  2073,  2074,  2075,   428,   429,
     430,  2709,  1267,  2048,  2710,  2711,  2712,  2713,  2714,  2715,
     283,  2812,  1328,  1143,   283,  1257,  1258,    39,    39,  1556,
    1557,   191,   283,  1327,  1328,    39,   191,  2698,   359,  2700,
    1872,  2707,  1873,  2344,  1874,   377,   334,  1551,  1457,  1458,
    1459,   367,   283,   337,   338,    39,  3098,   406,  1612,  1613,
     283,  1327,  1328,    39,   418,   418,   418,   418,   418,   193,
      86,  1619,   418,   193,  1114,   193,    39,   193,   193,   193,
    1619,   283,  1257,  1258,    39,  1209,   193,    39,    39,    39,
     193,   193,  2098,  2586,     1,    39,  3198,  1745,     2,  1066,
    3332,    39,   575,  1538,  1539,  2466,  2469,  2469,   693,  2616,
    2469,    39,     3,   411,   983,  3110,  2196,   619,  2804,    39,
     622,    62,  1635,  2196,  2768,  1488,   193,  2341,   525,  2545,
     527,   193,  1922,  3099,  3100,   412,  2247,   630,   631,   632,
     633,     5,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,  2651,
    1501,   671,   974,  2704,   577,   961,  1829,  2707,  1928,   651,
     652,   585,  2532,   334,   654,  3249,   655,  2707,  1480,    79,
     958,    39,   331,   438,   334,  2187,  3468,  1231,  3505,   658,
     659,   660,   661,  1316,   952,  1241,  1151,   669,  1945,  1897,
    1569,     4,   593,   698,    39,  1209,     1,    39,   595,  2113,
       2,   956,   959,  1586,  1066,    89,    39,   953, -1977,  1878,
      39,  1891,   975,  2383,   593,  1803,  2386,    62,   587,   588,
     589,   191,  2652,  2653,  2654,  2655,  2656,  3028,  1614,   593,
     614,  1660,  1267,   193,  1313,   679,   193,  2203,   693,  1481,
    2709,  1314,    62,  2710,  2711,  2712,  2713,  2714,  2715,  2271,
    1147,  1446,  1267,   193,   193,   193,   193,   682,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,  2099,  1653,  2204,  1147,  1949,
    1620,    85,  3101,  1137,   684,   193,   193,   191,    86,  1620,
     193,    62,   193,  1270,  1030,   688,  1766,  1435,   984,    62,
      52,  2805,    62,    62,    62,   193,   193,   193,   193,  1766,
      62,   855,   950,   193,  1406,  1407,   193,  1772,   593,  1451,
    1636,    39,   593,  2415,  2415,  2471,  1722,  1636,  2635,  2119,
       8,   579,  2479,  1061,  2497,    87,    88,  2499,  2644,   694,
    2561,   694,  1061,  2448,  1408,  1409,  1410,  2622, -1977,   694,
    2792,  2792,     5,  1139,   119,   589,  1592,   596,  2792,  1198,
    1925,  1266,  1200,  1201,   191,  2832,   406,    89,   406,  1571,
    1946,  1577,  2835,  2210,   324,   325,   326,   327,   328,   973,
     418,    39,   193,   978,   324,   325,   326,   327,   328,  1778,
    2835,  1251,  2896,  3017,  1254,  2546,  1988,  1989,   606,  1777,
    1928,   418,  1779,  2931,    56,  2084,   114,  2941,  3000,  3003,
    1615,  1723,  1275,    39,  3072,  2873,  2645,  2927,  1503,   335,
    2212,   992,    62,  3079,  1269,  2716,  2717,  1724,  1552,  3326,
    2049,  1929,  3166,  2737,  3186,    62,  1259,  3186,   942,  2909,
    1652,  1834,  1332,  3194,  1827,  2061,  3301,  2338, -1977,  3340,
    3023,  1667,  3393,  1849,  1332,  3340,  3399,  1892,  3199,   193,
    1667,   530,  1889, -1977,  2633,  1138,  1029,  3402,  3402,  1725,
    2790,  1504,     6,  1558,  3441,  2626,  1570,  3457,  2797,  1553,
    2718,  1788,  1332,  1151,  3186,  3134,  1061,  2769,  1232,  1047,
    1047,  2275,  1471,     7,  1053,  2329,  1057,  1059,  1477,  2923,
    1067,  1069,  1047,  1780,  3145,  1074,  1319,  1059,  1726,  1747,
    1077,  1041,  1500,  2219,  3158,  1709,  1496,  1391,  1712,  1713,
       7,  1047,  3074,  1270,  3076,  3172,  1774,  1591,   193,  1750,
     415,  3069,  1067,  1067,  3116,  1260,  3111,  1727,  2869,  2461,
     576,  2826,  1047,  1270,  1561,   304,  1728,  2426,  1835,  2798,
     415,     8,   193,  2827,  2668,  1047,  1731,  1906,   977,  3333,
    1559,  3088,  1702,  3118,   304,  1124,  3202,  3123,   415,  1267,
     415,  2202,  1460,  1059,  2514,  1875,   431,  2410,  2461,  2514,
       9,   418,  1141,  1876,  1067,  1505,  2376,  2197,  1148,  2461,
    1707,  3268,   607,  2461,  3127,    89,   611,   997,   193,   418,
     418,    33,   578,  3304,  3005,  1616,  2719,  3215,   193,   586,
    1226,   193,    39,  1233,  3361,   193,  1782,  3308,  1836,  1837,
    1838,   193,  3471,   193,  2936,  1246,   332,  1246,   418,  2026,
    1246,   418,  1783,  1246,  1799,  1856,   286,  2079,  1617,  1621,
     594,  1268,  2484,  2485,  3148,  2632,  3250,  3092,  1621,  1819,
    1355,   431,  2257,   111,   112,  3454,  3102,  3469,  1824,  3506,
    1210,  1778,   599,   304,  2716,  2717,  2275,   304,  1315,  2423,
     580,  1658,  2720,  1929,  1779,   304,  1376,   600,   615,  1376,
    2874,   378,  1115,   680,  2520,  1269,   669,  1847,   669,   669,
      90,  2830,  1990,   686,  3018,   304,  1535,  2387,  2360,  1701,
    1320,  3093,  1710,   304,  1545,   683,  1061,  2361,   379,  1890,
     998,   161,  1411,    39,  1737,   333,  1738,  1739,  3212,  2718,
    3213,  3214,  2721,  2722,   304,    61,  2391,    39,  1571,  2347,
       1,  2362,   685,  3010,  2363,  3013, -1977,  2238,  3016,  1295,
    2831,  2850,    39,   689,  1767,  1062,  1065,  1921,  3230,  3394,
    2364, -1977, -1977, -1977, -1977, -1977,  2657,  1768,  1936,  3300,
     324,   325,   326,   327,   328,  1773,  2232, -1977,  1933,  1076,
    2233,  2416,  2422,  2472,  3192,  1780,  3065,  2477,  3068,  1308,
    2480,    91,  2498,  1097,  1708,  2500,  1097,  1348,  2562,  1054,
      10,    39,  1078,    39,  1778,  2623,  1106,  1412,  2793,  2794,
    1097,  2254,   193,  1914,  1097,   193,  2796,  1779,  3260,    32,
     536,  1123,   193,  2833,   193,   193,  1097,    13,  1106,   999,
    2836,  2394,   546,  2993,  1135,  2348,    60,  1106,  1893,    39,
    1401,  3019,   694,  3020,  1145,  1130,  1903,  3482,  2841,    13,
    1413,  1160,  1310,  1394,  1793,  2719,    32,    33,  1203,  2034,
    1968,  2932,  3280,  2365,  2065,  2942,  1146,  3004,    39,  1135,
    1270,    92,  3073,  1203, -1977,  3185, -1977,  1135,  1067,    93,
     487,  3080,  1996,  1106,  1997,  1998,  1106,  2066,  2000,  2001,
    3167,  2855,  3187,   193,  2020,  3193, -1977,  1968,  1782,  2795,
    1067,  3195,  1778,  1488,  3302,  2237,  1711,  3341,  1151,  1666,
    1705,    77,  2600,  3342,  1783,  1779,  2366,  2050,  1780,  3513,
    2052,  2720,  1803,  2367,  3318,  3403,  3410,  3162,  3426, -1977,
    2392,  3331,  3442,  2557,  2688,  3458,  2690,  3170,  2691,  1895,
      39,  2034,  3493,   627,  1148,  2928,  2929,  1670,    62,   107,
    1271,  1272,  1273,   193,  2087,  1148,   193,   110,  1486,  1866,
      39,  1274,    62,  3237,  3305,  2787,    39,  1463,  2180,   288,
    2181,  2721,  2722,  2083,  1464,  2326,   117,    62,   488,   489,
     490,   491,   492,   493,    61,    51,    39,  1781,  3192,  3192,
    1446,  1778,   291,  1973,  1732,  2339,   494,   495,   496,  2162,
    2067,   193,  2035,    44,  1779,    39,  2174,  2228,     5,  2565,
      39,   193,  2180,   193,  2181,  1209,  1780,    39,  1584,  2368,
    2737,  2036,  2037,  2919,    39,  2395,    62,  2994,    62,  1596,
    1973,  1782,   119,  2198,  1850,  2327,    51,  1604,  3238,  2542,
    1838,  2038,  1597,  3226,    39,  1139,   121,  1783,  2921,    39,
    2856,   123,   193,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,    62,  3218,   193,  1646,  3223,    39,
    1571,  3225, -1977,  2182,   297,  1830,  2183,    39,  2270,  2898,
    3058,    39,    39,  3319,  2035,  1802, -1977,  3425, -1977,  3163,
    2246, -1977, -1977,  1147,  1430,  2199,   197,   487,  1968,  2933,
    3239,  3514,  3240,  2036,  2037,  1780,  2937,  3025,  1704,  2068,
   -1977, -1977,  2460, -1977,  3232,  1862,  1431,  2182,  3241,   127,
    2183,  1348,  1348,  2038, -1664,  1775,  3242,  1776,     6,  1782,
    3243,  1348,  2088,  1016,  1551,   497,  1019,  2213,   498,  1424,
    1911,  1912,  1968,  2089,  1744,  1783,  1831, -1977,  1430,  1831,
     111,   112,  1751,  1099,   438,  3244,  3026,  2521,   952,  2522,
   -1977,  1425,  3306,  3233,   198,    62,   300,  1108,  2533,  2518,
    1431,  1113,   201,  2225,  2491,  2492,  2493,   242,   301,   302,
    1297,   953,   249,  1127,  1812,  1147,   303,  3131,  1953,  1954,
     191, -1977,   251,  2554, -1977,   488,   489,   490,   491,   492,
     493,  2878,  2905,   366,  1789,   441,  1203,     8,  1794,  1800,
    1794,    62,  2045,   494,   495,   496, -1977,  2260,  1782,    39,
    1806,  1808,  1809,   258,    39,  2346,  1813,  1815,  1816,  1817,
    1067,  1973,  1290,  1291,  1783,    62,     9,  3009,  3009,  1067,
    3009,  2862,    62,  3009,  2837,  1064,  1064,   259,    39,    62,
    1064,  1064,  1148,  3321,  2918,  2466, -1977,   499,  3097,  2393,
     193,   193,   193,  1064,  3329,  2398,  2399,  2470,  1067,    62,
    2474,   418,   500,   418,    62,  1973,   501,   193, -1977, -1977,
    2814,  3343,  1148,  1064,  3066,   193,  1064,  2875,  3427,  1865,
    1148,    39,  1064, -1977,    62,  3201,  1064,   346,   347,   348,
    1064,   986,    62,   987,  1064,  2083,    62,    62,  1064,  1064,
    1284,  1064,   502,  1654,  1064,   261,  1064,  1064,  1064,  3121,
    2508,  1285,   535,   262,  1064,  3476,    39,  1064,   541,   265,
    1650,  1160,  1203,   266,  1064,  2523,  2524,  1838,  2527,  2515,
     503,  1064,  2637,  3444,  1968,   424,   425,   426,  1064, -1977,
      39,   193,   497,  1426,  1427,   498,  2548,   504,   990,  1064,
     991,   267,  3433,  1064,   268, -1977,  2494,  1064,  2663,   269,
     193,  1286,  1058,  1064,    39,  1909,  1064,   418,   418,  3446,
    2815,  1968,   418,  1754,  1755,  1287,  1918,  1919,  1920,   193,
     270,  2558,     1,  2063,   271,  2070,     2,   272,  3428,  2883,
     193,  1847,  3429,  1542,  1543,  2070,  1355,  2891,  2892,  2893,
       3,   273,  2093,  2094,  2095,  2096, -1977,  2816,   274, -1977,
   -1977, -1977,  2042,  2591,  1246,   418,   418,  1250,  1449,  1450,
    1253,  3433,  1066,  1256,    39,  3428,  2211,  2101,   505,  3429,
     275,  2594,  3311,   276,  3314,  3315,  3316,  3317,  3446,  3384,
    3385,  3386,  1992,  1067,  1129,  1067,  1067,  1655,   278,  1067,
    1067,   330,  2002,  1136,   318,  1067,  1536,  1537,   371,  3303,
    1540,  1541,   319,  1288,   499, -1977,  1486,  1973,    39, -1977,
    1582,  2817,    39,   340,  1546,  1547,    39,   345,  1714,   500,
    1715,   320,  -296,   501,   321,  2818,   383,  1937,   112,     4,
    2046,  1439,  1440,  1441,   506,   322,   167,   392,   323,  1249,
    2842,  1717,  1252,  1718,  1973,  2029,  2030,  1756,  1757,  1758,
    1759,  1760,  1761,  1807,   354,    39,  2659,   355,  2660,   502,
    1348,  1810,  1348,    39,  2284,  2286,   381,  3450,  3009,  3452,
    2296,   451,  1348,  1348,  1067,  2872,  1814,  2092,    39,  1348,
    1348,  1348,  1348,  2625, -1977,   382,  1722,   503,  2400,  1656,
    2193,  2194,  1148,   193,  2053,   356,  2054,  1657,  2057,  2224,
    2058,  1271,  1272,  1658,   504,  1659,  2503,  -296,    39,  3459,
    3460,   384,  2649,  2810,  2811,  1789,  1660,   360,   669,  1394,
    1794,   361,   393,  -296,  2819,   363,  1800,   385,  2665,  1794,
     365,  2679,  2268,   400,  2681,  3137,  2684,  2685,   394,  1588,
    2820,  3190,  3191,  1661,  2506,   370,    39,  2160,  1564,  1565,
    1566,  1567,   193,  2164,  3174,  3175,   452,  1217,  2682,  1662,
    2683,  3207,   372,  3208,  1663,  -296,   111,   112,   193,   386,
     391,  1723,   453,  2401,   376,   401,  1664,  2007,   407,  2083,
     395,  2083,  2190,  1665,  3487,   505,    39,  1724,  2008,  2402,
       5,   410,   413,   448,   446,   193,  1067,  1148,   449,   460,
    2206,  2207,   193,   418,  -296,   463,  1218,   464,   387,  2009,
    3176,   466,   470,   467,   454,  2010,   468,   517,   469,   396,
     529,  2844,   531,  2011,  2849,   193,  1064,   538,  1589,  1725,
     533,  2403,   193,  -296,   539,   540,   542,   388,   543,   547,
    2235,    62,  -296,  1219,   193,  2012,   389,   548,   397,  3139,
    1355,   506,   193,   455,   553,   549, -1977,   398,   563,  2414,
     193,   564,  2417,  2418,  2419,  2420,  2261,  1604,  1726,  1348,
    2404,   565,  1049,  3271,  1148,  1756,  1757,  1758,  1759,  1760,
    1761,   568,   456,  3279,  1070,  1752,  1753,  1754,  1755,  1198,
     573,   457,   418,   418,   583,   584,   591,  1727,   597,  2405,
    3285,   592,   598,  1083,   612,   602,  1728,   418,  2406,  2199,
       6,   603,   620,  2973,  2973,  2973,  2973,   623,   613,  3062,
     624,   625,   628,  2004,  1101,   653,  1067,  3188,  3189,  3190,
    3191,  1666,   656,   662,   663,   672,  1667,  1110,   664,  1220,
     670,   674,  1668,   673,   675,  2703,   676,  2706,   677,   678,
    1064,  1064,  1064,  1862,   681,   687,   699,     1,     7,   957,
     962,  2382,  2382,  3112,  1669,  2382,   964,   965,   966,  1670,
     971,   972,   982,   988,  3108,  3031,  3032,  3033,   989,  3035,
    3036,  3037,  3038,  3039,  3040,   996,  1003,  1348,  3043,     8,
    1024,  3128,  1001,  1005,  1006,  1007,  1348,  1027,  1032,  1348,
    1348,  1348,  1348,  2421,  1033,  1035,  1067,  1036,   174,  1037,
    2427,  1348,  1038,  1040,  2445,  1043,  1221,  1044,     9,  1045,
     175,  1756,  1757,  1758,  1759,  1760,  1761,  1046,   191,  1158,
    1238,  1299,  1300,  2192,  1305,  1301,  2462,  2462,  2462,  3312,
    1302,  2462,  1348,  2476,  1303,  3312,  1789,  3378,  3322,  3323,
    3324,  3325,  1365,  1304,  1306,  1367,  1222,  1368,  1369,  1370,
    1371,  1372,  1307,  1756,  1757,  1758,  1759,  1760,  1761,   324,
     325,   326,   327,   328,  1309,  2501,  1311,  2502,  2504,  1312,
    2505,  2507,   193,  1317,  2509,  1318,  1321,  1322,  1794,  1373,
    1366,  1374,  1323,  1794,  1375,  1378,  1379,   193,   193,   193,
     193,  1381,  1067,  2462,  1392,  1382,  2190,  1383,  1384,  2538,
    2538,  1385,  1386,  1388,  1393,  1397,  1398,  1399,   193,  1400,
    1405,  1223,  1432,   193,  1423,  1428, -1977,  1434,  1433,  1436,
    1455,  1429,  1959,  1960,  1961,  2005,  1962,  2556,  1963,  1964,
    3383,  3434,  3435,  3436,  3437,  3438,  3439,  1442,  1355,  2006,
    1461,  1462,  1468,  1086,  1086,  1469,  1465,  3456,  1473,  3126,
     181,  1466,  1160,  1488,  1485,  1490,  1492,  2964,  2964,  2964,
    2964,  3401,  3085,  1474,  3404,  3405,  3406,  3407,  2772,  1476,
    1493,  1533,  1549,  1550,   182,   193,  1554,  1578, -1977,  1579,
   -1977,  1580,  2007,  2773,  2774,  1203,  3146,  1587,  1581,  1585,
    1073,  1601,  2775,  2008,  2601,  2693, -1977,  2973,  2973,  1592,
    1603,  2973,  1082,  1626, -1977,  1627,  1628,   593, -1977,  1634,
    1629,  2705,  1638,  1641,  2009,  1642,  1643,  1644,   183, -1977,
    2010,  3273,  2727,  3012,  1692,  3015,  2776,   184,  2011,  1703,
    3238,  1102,  1700, -1977,  1706,  2777,  1716,  1733,  1734,  3283,
    1735,  1086,  1736,  1740,  1067,  1765,  1741,  1119,  1120,  1742,
    2012,  1261,  3463,  1126,  1743,  1771,  1128,  1792,  1805,  2462,
    1821,  1820,  3222,  1822,  2778,  3222,  1825,  2640,  2002,  2462,
    1826,   950,  1992,  1067,  1828,  1348,  1848,  1841,   193,  1561,
     193,  1859,  1855,  1857,  1868,  1881,  1870,  3231,  1992,  1067,
    1882,  1898,  3239,  2382,  3240,  1900,  1901,  2914,  1862,  2916,
    1910,  1913,  2965,  2965,  2965,  2965,  1925,  1932,  2779,  1934,
    3241,   185,   186,  1915,  1939,  1940,  3330,  1942,  3242,  1636,
    1980,  1982,  3243,  3206,  1983,  3209,  3210,  2013,    71,  1985,
    1991,  3451,  1348,  2014,  2043,  2047,  2055,  2051,  2056,  2061,
    1067,  2059,  1067,  2427,  1731,  2903,  1348,  3244,  1348,  2083,
     581,  2076,  2780,  2102,  3518,  2881,  1698,  2103,  2084,  1348,
     669,  2097,  2108,  2109,  2462,  2110,  2445,  2111,   669,   669,
     669,  2114,  2119,   191,  2115,  2268,  2116,  2150,  2462,  2151,
    2152,  2153,  3363,  2148,  2157,  2154,  2155,  2170,  2169,  2165,
    2171,  2167,   162,   194,  2172,  2173,  1794,  2175,  3274,  2177,
    1965,  2178,  2179,  1966,  1349,  1967,  1355,  2176,  1635,  2214,
    2191,  2221,  2216,  2217,  1800,   191,  1794,  2223,  2226,  2230,
    2231, -1977,  2244,  2236,  2258,  1968,  2250,  2264,  2065,  2160,
    2973,  2239,   193,  2240,  3298,  1969,  2973,  2973,  2241,  2973,
    2973,  2973,  2973,   193,  2275,  1274,   193,  2277,  2973,  2324,
    2325,  2964,  2964,  2336,  2342,  2964,  1970,  2352,  2350,   194,
    2351,  2356,  2190,  2355,  2863,  2357,  2865,  2372,   193,  2462,
    1067,  2371,  2390,  2396,  2379,   193,  2397,  2411,   194,  1971,
    2412,   193,  2413,  1972,  2425,  2442,   193,  2447,  1261,  2449,
    2887,  2451,  2453,  2481,   193,   193,   193,  2482,  2454,  2457,
    2483,  2486,  1160,  2487,  3021,  2488,  2489,  2490,  1203,  2512,
     193,   193,  1348,  1064,  2517,  2529,  3205,  2547,  2552,  2549,
    2551,  2553,  2555,  2559,  2568,   418,  2570,   418,  2567,  2571,
    2572,  2573,  2574,  2575,  1203, -1977,  2592,  2593,  2595,  1551,
    1273,  3125,  2608,  1348,  2599,  2610,  2619,   414,  2624,  2620,
    2621,  2628,  2636,  2638,  3130,  2462,  2629,  2666,  1973,  2671,
    2661,  2692,  2973,  2686,  2680,  2973,  2973,  2973,  2973,  2962,
    2962,  2962,  2962,  2462,  2462,  2707,  2689,  2694,  2708,  2695,
    2696,  2697,  2728,  2731,  2740,  2785,  2789,  2790,  2987,  2799,
    2791,  3222,  2802,  2806,  2803,  2838,  2965,  2965,  2808,  2809,
    2965,  2839,  3120,   522,   523,  2828,  2840,  2843,  2845,  2846,
     194,  2853,  2829,  2857,  2864,   194,  2890,  2882,  2861,  2871,
    2879,  2901,  2924,  2933,  1348,  1348,  2943,  2925,  2913,  2944,
    2940,  1746, -1977,  1348,  1348,  2985,  1348,  2992,  2995,  1348,
    2996,  1348,  1064,  2997,  2998,  1348,  2999,  3011,  3001,  3002,
    3014,  3022,  3024,  2973,  3029,  3034,  3030,  3041,  3042,  3048,
    3049,  3443,  2973,  1261,  3051,  3413,  3414,   138,  3052,  2816,
    1511,  3070,  3071,  3077,  3053,  1064,  3054,   191,  3055,  3056,
     669,  3057,  3063,  3075,  2964,  3081,  3082,  3086,  3106,  3113,
    2964,  2964,  2813,  2964,  2964,  2964,  2964,  3114,  3115,  3116,
    3129, -1977,  2964,  3133,  3135,   139,  3138,  2462,  3067,  2462,
    3151,  3142,  3143,  1268,  3154,  3177,  3164,  3178,  3158,  3179,
    3180,  3186,  3196,  3197,   140,   141,  3181,  3182,  1349,  1349,
    3183,  3203,  3235,  1067,  2787,  3211, -1845,  3252,  1349,  2966,
    2966,  2966,  2966,  3216,  3254,  3089,  3090,  3253,  3257,  2509,
    2024,  2025,  1794,  3256,  3258,  3259,  3263,  2041,  3265,  3266,
    3272,  3276,  3278,  3284,   142,  3497,  3282,  3286,  3287,  3290,
    2538,  3292,   193,  3122,  2538,  3288,   143, -1977,   418,  1747,
    3297,   193,  3307,  3309, -1977,  3327,  3335,   144,  3336,  3344,
    3354,   418,  1160,  1160,  3355,  3270,  3356,  3357,   657,  3358,
    3227,  3359,  2727,   145,  3364,  3382,   193,  3376,  3400,  3377,
     194,  3390,  3408,   146,  3424,  3411,  2964,  3440,   193,  2964,
    2964,  2964,  2964,  3453,  3462,  3464,  3465,  3466,   147,  2965,
    3467,  3480,  3491,  3492,  3470,  2965,  2965,  3499,  2965,  2965,
    2965,  2965,  3155,  3501,  3503,  3502,  3504,  2965,  2462,  3507,
    2963,  2963,  2963,  2963,  3512,  3517,  3516,  2640,  2462,  2834,
    1992,  1992,  3479,  2962,  2962,  2886,  1389,  2962,   148,  1924,
    2584,  2249,  1042,    57,    58,  2534,   194,  2860,  3184,   544,
    2543,   200,   205,   353,  1512,   537,  2104,  1034,   545,   690,
     149,  2105,   358,   995,   572,  3477,  1719,   570,   967,  2163,
    1225,   968,  1992,  1261,  2388,   150,  1696,  2964,  1380,   608,
    2380,  2525,   151,  2208,  1952,   152,  2964,  2912,  3153,  1956,
    1067,  2274,  2598,  3500,  2530,  2294,  1852,  3281,  1148,    54,
     136,  1148,    68,  2677,  1348,    69,   153,  1348,    55,  1348,
     154,  2462,  1298,  1355,  2256,  2259,  1938,   528,  3236,  1125,
    1979,  1403,  2263,   194,  1888,  1632,  3345,  2063,  1843,   155,
    1157,  2965,  1886,  3483,  2965,  2965,  2965,  2965,  2229,  2907,
    1833,  3353,  3061,  1904,  2227,  3044,  3060,   156,   629,  2784,
    3109,  3269,  3267,  3264,  3091,  1050,  1051,  1052,  2149,  1055,
    2519,  2118,  1064,  2478,  2630,  3486,  3229,  2354,  1064,  2022,
    2650,  2023,  3171,  1348,  3064,  3360,  1080,  2424,  2345,  3087,
    1513,  2272,  3006,  2702,  3415,  3007,  1514,  1515,  1516,  3224,
    2801,  3083,  1995,   418,  1064,  3251,  2786,  2701,  1004,    49,
     193,  3511,  1684,  2966,  2966,  2738,  3173,  2966,  1517,  1261,
    2739,  2939,  1104,   484,   485,   486,  2078,  3228,  1109,  3389,
    1111,  2077,  2965,  1649,  1118,  1987,  3392,  1118,  3169,  2642,
    1118,  2965,  3310,  3328,  3320,  2870,   193,  1950,  2100,  1487,
    1131,  1861,  2550,  1867,  2867,     0,  1851,     0,     0,   487,
    1348,   700,     0,  2462,     0,  1131,     0,  3398,     0,     0,
       0,  1194,     0,     0,  1348,     0,  2962,     0,  1055,  1207,
    1211,     0,  2962,  2962,  1227,  2962,  2962,  2962,  2962,     0,
       0,  2462,  1239,  2462,  2962,     0,  1348,     0,     0,   191,
       0,     0,     0,     0,  3416,     0,     0,     0,  1263,     0,
       0,     0,     0,     0,     0,  1883,     0,  1349,     0,  1349,
       0,     0,     0,  1518,  2963,  2963,  1519,     0,  2963,  1349,
    1349,     0,     0,     0,  1520,     0,  1349,  1349,  1349,  1349,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   669,     0,     0,  2122,  2462,   488,   489,   490,
     491,   492,   493,     0,     0,     0,     0,     0,  1521,     0,
       0,     0,     0,     0,     0,   494,   495,   496,  2297,  2298,
    2299,  2300,  2301,  2302,     0,     0,     0,     0,     0,  3221,
       0,     0,  3221,     0,   193,     0,     0,     0,  3155,     0,
       0,     0,     0,  1522,  1348,     0,     0,     0,  2962,     0,
       0,  2962,  2962,  2962,  2962,     0,  3409,  3398,     0,     0,
       0,     0,  1523,  1524,     0,     0,     0,     0,     0,     0,
    3412,     0,     0,  1525,     0,     0,     0,  1148,  1526,     0,
       0,  1348,     0,     0,     0,     0,  2966,     0,     0,     0,
       0,     0,  2966,  2966,     0,  2966,  2966,  2966,  2966,     0,
       0,     0,  1064,  1064,  2966,     0,     0,     0,     0,     0,
       0,     0,     0,   193,  3445,     0,  2303,  1527,   193,     0,
       0,     0,  2580,  2581,     0,     0,     0,     0,     0,  1511,
    1086,     0,     0,  2590,     0,     0,     0,     0,     0,  2962,
       0,     0,     0,     0,     0,     0,     0,     0,  2962,  1528,
       0,     0,     0,     0,   497,     0,     0,   498,  2602,  2603,
    2604,  2605,  2606,  2607,     0,     0,  1349,     0,  2612,  2613,
    2614,  2615,     0,     0,     0,  2617,     0,     0,     0,     0,
       0,     0,  1203,     0,     0,  1263,     0,     0,     0,     0,
       0,     0,     0,     0,  1348,     0,  3488,  2963,     0,     0,
       0,  1447,     0,  2963,  2963,     0,  2963,  2963,  2963,  2963,
       0,     0,     0,     0,     0,  2963,     0,   193,  2966,     0,
       0,  2966,  2966,  2966,  2966,     0,     0,     0,     0,     0,
    2123,     0,     0,     0,  3338,     0,     0,     0,  3509,  3510,
    3488,     0,     0,  1479,     0,     0,     0,     0,     0,     0,
    2124,  2125,  2126,  3519,     0,     0,     0,  2669,  2670,     0,
       0,     0,     0,     0,  2674,  2675,     0,     0,     0,     0,
       0,     0,     0,  1507,  1507,  1507,   499,  1507,     0,  1507,
    1507,     0,     0,     0,  1349,    71,    71,     0,     0,  2127,
       0,   500,     0,  1349,     0,   501,  1349,  1349,  1349,  1349,
       0,  2128,     0,     0,     0,     0,     0,     0,  1349,  2966,
       0,  1211,  2129,     0,     0,     0,     0,     0,  2966,     0,
       0,     0,     0,     0,  1211,     0,     0,     0,  2130,  2963,
       0,   502,  2963,  2963,  2963,  2963,  1599,     0,  2131,  1349,
       0,   164,   165,  1512,     0,     0,     0,     0,     0,   166,
      39,  2304,     0,  2132,     0,     0,     0,     0,  3221,   503,
    1263,  1447,     0,  2429,  2305,     0,     0,     0,     0,  1639,
     167,     0,  1324,  1325,  1326,     0,   504,     0,   283,  1327,
    1328,    39,     0,     0,     0,  1647,  1647,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1329,  1330,     0,
       0,  2133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2851,  2852,     0,     0,     0,
    2963,     0,     0,     0,  2859,     0,  2306,     0,     0,  2963,
    2134,     0,  2307,     0,     0,     0,     0,  1261,     0,     0,
    2135,     0,     0,     0,   168,  1959,  1960,  1961,     0,  1962,
       0,  1963,  1964,     0,     0,     0,   169,   505,     0,     0,
       0,  2136,  2894,  2895,     0,  2137,     0,     0,     0,  1513,
       0,  2308,     0,     0,     0,  1514,  1515,  1516,     0,     0,
    1331,     0,     0,     0,   170,     0,     0,     0,     0,  2915,
       0,  2917,     0,  2138,  2309,     0,     0,  1517,     0,     0,
       0,     0,  2139,     0,  2310,  2311,  1055,     0,     0,     0,
    2312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2313,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2314,     0,     0,  2315,  2316,     0,     0,     0,
    2317,  1055,  2988,  2989,     0,     0,  2990,  2991,    71,     0,
       0,    71,  1211,  1118,     0,     0,  3262,     0,     0,     0,
    1842,  1131,     0,     0,  1211,    62,  3262,   171,  1853,     0,
       0,     0,  1349,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1263,  1194,  1518,     0,     0,  1519,  1147,  2318,     0,     0,
       0,     0,     0,  1520,   617,   471,   472,   473,  2319,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,  1349,
       0,     0,     0,     0,     0,     0,     0,  1521,     0,     0,
       0,  1887,  1194,  1349,    71,  1349,     0,  1894,  1896,     0,
       0,     0,     0,     0,     0,   487,  1349,     0,   280,     0,
       0,     0,  1064,   172,     0,     0,     0,   281,   282,     0,
       0,     0,  1522,   283,   284,   285,    39,     0,  1916,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1523,  1524,     0,     0,     0,   167,     0,   173,  2430,
       0,     0,  1525,     0,     0,     0,  1944,  1526,  1349,     0,
       0,     0,     0,  1965,     0,     0,  1966,     0,  1967,     0,
       0,     0,     0,     0,  3119,  1978,  1263,     0,  3124,     0,
       0,     0,   174,     0,     0,     0,     0,     0,  1968,     0,
       0,     0,     0,     0,   175,     0,  1527,  3132,  1969,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,  3144,     0,  2293,
     168,   494,   495,   496,     0,   286,     0,     0,  1528,     0,
     176,     0,   169,  2028,     0,     0,     0,     0,     0,     0,
       0,     0,  1971,     0,     0,   177,  1972,     0,     0,     0,
    1332,  1326,     0,   178,     0,   283,  1327,  1328,    39,  1349,
     170, -1977, -1977, -1977,     0, -1977,   179, -1977, -1977,     0,
       0,     0,     0,     0,  1329,  1330,     0,     0,     0,     0,
       0,  1333,     0,     0,  2431,     0,     0,     0,     0,     0,
    1349,     0,     0,     0,     0,     0,  2432,  1335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,  1349,  1349,  1349,  1349,
       0,  1973,     0,     0,  1731,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,  1336,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,  1337,     0,
       0,    62,     0,   171,     0,     0,     0,  1331,   182,     0,
     497,     0,     0,   498,   480,   481,   482,   483,   484,   485,
     486,  1349,  1349,     0,   487,     0,     0,     0,     0,     0,
    1349,  1349,     0,  1349,     0,     0,  1349,     0,  1349,  1338,
       0,     0,  1349,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,     0,   487,     0,     0,     0,  1086,  1086,
    1086,   184,  1086,  1086,  1086,  1086,  1086,  1086,     0,     0,
       0,  1086,  1339,     0,     0,     0,     0,     0,  1340,     0,
       0,     0,  2220,     0,     0,     0,     0,  1341,  1342,     0,
    1343,     0,     0,     0,     0,     0,     0,     0,     0,   172,
       0,     0,  1344,  1345,   287,     0,  1211,     0,     0,     0,
    1346,     0,     0,  1347,     0,     0,     0,  3296,     0,     0,
    3299,   304,   488,   489,   490,   491,   492,   493,   162,     0,
       0,     0,   499,  1147,   173,     0,     0,  2269,     0,  1194,
     494,   495,   496,     0,     0,   185,   186,   500,     0,     0,
       0,   501,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,     0,
     494,   495,   496,     0,     0,     0,  1211,  2328,  1211,     0,
     175,     0,  1055,     0,     0,     0,     0,   502,     0, -1977,
       0,     0, -1977,     0, -1977,     0,     0,     0,   288,  1261,
       0,     0,     0,   289,     0,   290,     0,     0,     0,     0,
       0,     0,     0,     0, -1977,   503,   176,  2374,     0,     0,
       0,   291,     0,     0, -1977,     0,     0,     0,     0,     0,
       0,   177,   504,     0,     0,     0,   292,     0,     0,   293,
     280,     0,   294,     0,     0, -1977,     0,     0,     0,   281,
     282,   295,   179,     0,     0,   283,   284,   285,    39,     0,
    1349,  1349,     0,     0,  1349,  3387,     0,     0, -1977,     0,
       0,     0, -1977,     0,     0,     0,     0,     0,   167,   497,
       0,     0,   498,     0,     0,     0,     0,     0,     0,     0,
     665,   296,     0,     0,     0,   180,     0,     0,     0,  1055,
       0,     0,     0,   297,     0,     0,     0,     0,     0,   497,
       0,     0,   498,   505,   298,     0,  3417,  3418,     0,  3420,
     181,  3422,  3423,     0,     0,  1349,     0,     0,  1349,     0,
       0,  1349,     0,     0,  1349,     0,  1349,  1332,     0,     0,
       0,     0,     0,     0,   299,     0,     0, -1977,     0,     0,
       0,     0,   168,     0,     0,     0,  1055,   286,  1211,     0,
    1211,     0,     0,     0,   169,     0,     0,     0,  1333,  1211,
       0,  1334,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,  1335,     0,     0,   194,   183,  3472,
       0,  3473,   170,     0,  1211,   300,     0,   184,     0,     0,
    1349,   499,     0,     0,  1263,     0,     0,   301,   302,     0,
       0,     0,     0,  2563,     0,   303,   500,  2566,     0,     0,
     501,     0,     0,  1336,     0,  3485,   304,     0,     0,     0,
       0,   499,     0,     0,     0,  1337,     0,     0,     0,     0,
       0,     0,     0,  2589,  3494,  3495,   500,     0,  3496,     0,
     501,  3498,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1338,  1349,     0,     0,
       0,   185,   186,    62,   503,   171,   502,     0,     0,     0,
       0,  1349,     0,  1349,     0,     0,     0,     0,     0,  1349,
    1349,   504,  1349,  1349,  1349,  1349,     0,     0,     0,  1339,
       0,  1349,     0,  1349,   503,  1340,     0,     0,     0,     0,
       0,     0,     0,     0,  1341,  1342,     0,  1343,     0,     0,
    1349,   504,     0,     0,     0,     0,     0,     0,     0,  1344,
    1345,     0,     0,     0,     0,     0,     0,  1346,     0,     0,
    1347,     0,     0,     0,     0,   280,     0,     0,   304,     0,
       0,     0,     0,     0,   281,   282,  2667,     0,     0,     0,
     283,   284,   285,    39,     0,     0,     0,     0,     0,     0,
       0,   172,   505,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1261,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,   173,     0,     0,     0,
       0,  1349,     0,     0,     0,  1349,     0,     0,  1349,  1349,
    1349,  1349,     0,     0,     0,     0,     0,     0,     0,  1211,
       0,     0,     0,     0,     0,     0,     0,     0,   506,     0,
     174,     0,     0,     0,  1349,     0,     0,     0,  1349,     0,
       0,     0,   175,     0,     0,     0,     0,   168,     0,     0,
       0,     0,   286,     0,     0,     0,     0,     0,   506,   169,
     288,     0,     0,     0,     0,   289,     0,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,   291,     0,     0,     0,   170,     0,     0,
       0,  1211,     0,   177,     0,     0,  1349,     0,   292,     0,
       0,   293,     0,     0,   294,  1349,     0,   481,   482,   483,
     484,   485,   486,   295,   179,     0,     0,     0,     0,     0,
       0,     0,   194,     0,     0,     0,  1211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2884,     0,  1080,     0,  2888,   487,     0,     0,     0,
       0,  1349,  1443,   296,     0,     0,     0,   180,     0,  2900,
       0,     0,     0,     0,   194,   297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   298,     0,    62,     0,
     171,     0,   181,     0,     0,     0,     0,     0,     0,     0,
       0,  2920,  2922,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,     0,     0,   299,     0,  1261,     0,
       0,     0,   281,   282,     0,     0,     0,     0,   283,   284,
     285,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2986,     0,     0,
       0,   167,     0,     0,   488,   489,   490,   491,   492,   493,
     183,     0,     0,     0,     0,     0,     0,   300,     0,   184,
       0,     0,   494,   495,   496,     0,     0,     0,     0,   301,
     302,     0,     0,     0,     0,     0,   172,   303,     0,     0,
       0,   287,     0,     0,  2564,   471,   472,   473,   304,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,   168,     0,     0,     0,     0,
     286,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,  3045,
       0,     0,     0,   185,   186,   174,     0,     0,     0,     0,
       0,  3059,     0,     0,     0,   170,  1055,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     289,     0,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,     0,   291,     0,
       0,   497,     0,     0,   498,     0,     0,     0,   177,     0,
       0,  1055,     0,   292,  1211,     0,   293,     0,     0,   294,
       0,     0,     0,     0,     0,     0,   194,     0,   295,   179,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,  1211,     0,     0,     0,    62,  1194,   171,     0,
     138,   494,   495,   496,     0,     0,  1263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,     0,     0,     0,   139,     0,
       0,   298,     0,  2526,     0,     0,     0,   181,   479,   480,
     481,   482,   483,   484,   485,   486,     0,   140,   141,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     282,   299,     0,   499,     0,   283,   284,   285,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   500,   487,
       0,     0,   501,     0,   172,     0,     0,   142,   167,   287,
       0,     0,     0,     0,     0,  1194,     0,     0,     0,   143,
       0,     0,     0,     0,     0,   183,     0,     0,     0,     0,
     144,     0,   300,     0,   184,     0,     0,     0,   502,   173,
       0,     0,     0,     0,   301,   302,   145,     0,     0,     0,
     497,     0,   303,   498,     0,     0,   146,     0,     0,     0,
       0,     0,     0,   304,     0,     0,   503,     0,     0,     0,
       0,   147,     0,   174,     0,     0,     0,     0,     0,  3045,
       0,     0,   168,   504,     0,   175,     0,   286,     0,     0,
       0,     0,     0,     0,   169,     0,     0,   488,   489,   490,
     491,   492,   493,   288,     0,     0,     0,     0,   289,     0,
     290,   148,     0,     0,     0,   494,   495,   496,   185,   186,
       0,   176,   170,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,   149,     0,     0,   177,     0,     0,     0,
       0,   292,  1211,     0,   293,     0,     0,   294,   150,     0,
       0,     0,     0,     0,     0,   151,   295,   179,   152,     0,
    1211,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,   153,
       0,     0,     0,   154,     0,     0,     0,   500,     0,  1194,
       0,   501,     0,     0,     0,  2904,   296,     0,     0,     0,
     180,     0,   155,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,    62,     0,   171,     0,     0,     0,   298,
     156,     0,     0,     0,     0,   181,     0,   502,     0,     0,
     506, -1978,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,     0,     0,   497,   503,     0,   498,     0,     0,
       0, -1978, -1978, -1978,     0, -1978,  3045, -1978, -1978,     0,
       0,  3348,   504,  3350,   471,   472,   473,     0,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,     0,     0,   183,     0,     0,     0,     0,     0,     0,
     300,     0,   184,  1211,     0,     0,     0,     0,     0,     0,
       0,   172,   301,   302,     0,     0,   287,     0,     0,     0,
     303,  1263,     0,     0,   487,     0,     0,     0,   194,     0,
       0,   304, -1978,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0, -1978,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
     174,     0,     0,     0,     0,     0,   185,   186,     0,     0,
       0,   500,   175,     0,     0,   501,  1507,  1507,  1507,  1507,
    1507,  1507,     0,     0,     0,     0, -1978,     0,     0,     0,
     288,     0,     0,     0,     0,   289,     0,   290,     0,   506,
       0,     0,   488,   489,   490,   491,   492,   493,   176,     0,
       0,   502,     0,   291, -1978,     0, -1978,     0,     0,     0,
     494,   495,   496,   177,     0,     0,     0,     0,   292,     0,
       0,   293,     0,     0,   294,     0,     0,     0,     0,   503,
       0, -1978,     0,   295,   179,     0,     0,     0, -1978,     0,
   -1978,     0,     0,     0,     0,     0,   504,     0,     0,     0,
       0, -1978,     0,     0,     0,     0, -1978,     0,     0,     0,
       0,     0,     0,     0, -1978,     0,     0,     0, -1978,     0,
       0,     0,     0,   296, -1978,     0,     0,   180, -1978, -1978,
   -1978, -1978,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,     0, -1978,     0,     0,   298,   482,   483,   484,
     485,   486,   181,     0,     0,     0,     0,     0,     0, -1978,
       0,     0, -1978,     0, -1978,  1263,     0,     0,     0,     0,
       0, -1978,     0,     0,     0,     0,   299,   505,     0,     0,
       0,     0,     0,     0, -1978,   487,     0,     0,     0,     0,
       0,     0,     0,     0, -1978,     0,     0,     0,     0,   497,
       0,     0,   498,     0,     0,     0,     0,     0,     0,  2742,
    2743,     0,  2744,  2745,  2746, -1978, -1978,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,   300,     0,   184,
   -1978,     0,     0,     0,     0,     0,     0,     0, -1978,   301,
     302,     0, -1978,   506,     0,     0,     0,   303,     0,     0,
   -1978, -1978, -1978,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,     0,     0,     0,
       0,     0,  2747,   185,   186,     0,     0, -1978,     0,     0,
    2748,   499,     0,     0,     0,     0,     0,     0, -1978,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
     501,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2749,     0,     0,     0,     0,     0,
       0,     0,     0,  2750,     0,     0,     0, -1978,     0,     0,
       0,     0,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     2,
       0,     0,  2751,  2752,   702,     0,     0,   703,     0,     0,
       0,     0,     0,     0,   503,   704,   705,   706,     0,     0,
       0,     0,     0,   707,     0,     0,   708,     0,     0,     0,
       0,   504,     0,   709,   710,     0,     0,     0, -1978,     0,
       0,     0,     0,     0,     0,     0,  2753,     0,     0,     0,
     497,     0,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -1978,     0,     0,     0,   711,   712,
       0,     0,     0,   713,     0,     0,     0,     0,     0,     0,
    2754,     0,     0,   714,   715,     0,   716,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     717,     0,   505,     0,     0,     0,     0,     0,     0,     0,
   -1978,     0,     0,     0,     0,     0,     0,     0,   718,     0,
       0,   719,   720,     0, -1978, -1978, -1978, -1978, -1978, -1978,
   -1978,     0, -1978, -1978,  2755,   721,     0,   722,   723,   724,
       0,     0,     0,     0,     0,     0,     0,   725,   726, -1978,
     727,   728,   729,     0,     0,     0,     0,     0,   730,     0,
       0,   731,   499,   732,   733,   734,     0,     0,   506,     0,
       0,   735,     0,   736,   737,     0,   738,   500,   739,   740,
       0,   501,   741,     0,     0,   742,   743,   744,   745,   746,
     747,     0,     0,     0,   748,   749,   750,     0,   751,     0,
       0,     0,   752,     0,   753,   754,     0,     0,     0,     0,
     755,     0,     0,   756,     0,     0,   757,   502,   758,     0,
     759,     0,   760,     0,     0,     0,   761,   762,     0,   763,
     764,   765,     0,     0,   766,     0,   767,   768,     0,   769,
       0,     0,     0,     0,     0,   503,     0,   770,   771,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     772,     0,   504,   773,   774,     0,     0,   775,   776,     0,
       0,   777,   778,     0,     0,     0,     0,     0,     0,   779,
     780,   781,     0,   782,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   783,   784,   785,     0,   786,     0,     0,
       0,   787,   788,     0,     0,     0,   789,     0,     0,     0,
       0,     0,     0,     0,   790,     0,     0,     0,     0,     0,
       0,     0,   791,   792,   793,     0,     0,     0,     0,     0,
     794,   795,     0,     0,     0,     0,     0,     0,   796,     0,
       0,   797,     0,   505,     0,   798,   799,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   800,     0,     0,  2756,
    2757,  2758,  2759,  2760,  2761,  2762,  2763,  2764,  2765,     0,
       0,     0,     0,   801,     0,     0,     0,     0,     0,     0,
       0,   802,     0,     0,     0,     0,     0,   803,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
     805,     0,     0,     0,     0,     0,   806,     0,   807,   808,
       0,     0,     0,     0,     0,     0,   809,     0,     0,     0,
       0,     0,     0,     0,     0,   471,   472,   473,     0,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   810,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   811,     0,     0,     0,
       0,     0,     0,   812,     0,   487,     0,   471,   472,   473,
       0,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,     0,     0,   813,   814,     0,     0,
       0,   815,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   816,     0,     0,     0,     0,     0,   817,
     818,   819,   820,     0,     0,     0,   821,   487,     0,     0,
     822,     0,     0,     0,     0,     0,     0,   823,   824,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   825,     0,
     826,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   827,     0,   828,     0,     0,   829,     0,     0,     0,
       0,     0,   830,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,     0,     0,     0,   831,     0,
       0,   832,     0,     0,     0,     0,   833,     0,     0,   834,
     835,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   836,   488,   489,   490,   491,   492,
     493,   837,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   496,     0,     0,     0,     0,
       0,     0,     0,     0,   838,   839,   840,   841,   842,   843,
     844,     0,     0,   845,     0,   846,     0,   847,   471,   472,
     473,     0,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,     0,     0,     0,     0,   471,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,   498,     0,     0,     0,     0,     0,   487,
       0,     0,   471,   472,   473,     0,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
       0,     0,     0,   471,   472,   473,     0,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
       0,     0,   497,     0,     0,   498,     0,     0,     0,     0,
       0,     0,   487,     0,     0,   471,   472,   473,     0,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,   487,     0,     0,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,   495,   496,   488,   489,   490,
     491,   492,   493,     0,     0,   487,     0,     0,     0,     0,
       0,     0,   499,     0,     0,   494,   495,   496,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   500,     0,     0,
       0,   501,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,     0,     0,     0,   499,     0,     0,   502,   494,   495,
     496,   488,   489,   490,   491,   492,   493,     0,     0,   500,
       0,     0,     0,   501,   626,     0,     0,     0,     0,   494,
     495,   496,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,   502,
       0,   494,   495,   496,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,     0,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,   497,     0,     0,   498,     0,     0,
       0,     0,     0,     0,   504,     0,   471,   472,   473,     0,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,     0,     0,
     498,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
       0,   498,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,     0,   506,
     497,     0,     0,   498,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,   501,  1002,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   500,     0,     0,     0,   501,  1008,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     502,   506,     0,     0,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,   502,   494,   495,   496,     0,     0,     0,   503,     0,
       0,     0,     0,     0,   500,     0,     0,     0,   501,  1009,
     499,     0,     0,     0,     0,   504,     0,     0,     0,   503,
       0,     0,     0,     0,     0,   500,     0,     0,     0,   501,
    1010,     0,     0,     0,     0,     0,   504,     0,     0,     0,
       0,     0,   499,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   500,     0,     0,
       0,   501,  1011,     0,     0,   502,     0,     0,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,     0,     0,   503,     0,     0,   505,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,   497,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,   504,   471,   472,   473,     0,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,   505,     0,   487,   471,   472,   473,     0,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,   499,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   500,     0,
       0,     0,   501,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,   488,   489,   490,   491,   492,   493,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   502,   494,
     495,   496,     0,     0,     0,     0,     0,     0,   471,   472,
     473,  1013,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,     0,   503,     0,     0,     0,
       0,     0,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,   504,     0,     0,     0,     0,     0,     0,
     494,   495,   496,     0,     0,     0,     0,     0,   487,     0,
     472,   473,     0,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,     0,     0,
       0,     0,     0,   473,     0,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,   505,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,     0,     0,   497,     0,
       0,   498,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,   495,   496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,   497,
     506,     0,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2429,   488,   489,   490,
     491,   492,   493,     0,     0,  1324,  1325,  1326,     0,     0,
       0,   283,  1327,  1328,    39,   494,   495,   496,     0,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
    1329,  1330,     0,     0,     0,     0,     0,   494,   495,   496,
       0,     0,     0,   488,   489,   490,   491,   492,   493,     0,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   496,     0,   500,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,   495,   496,     0,     0,     0,
       0,   499,     0,   497,     0,   502,   498,     0,     0,     0,
       0,     0,     0,  1331,     0,     0,   500,     0,  1014,     0,
     501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,  1324,  1325,  1326,     0,     0,     0,
     283,  1327,  1328,    39,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,   497,     0,   502,   498,     0,  1329,
    1330,     0,     0,     0,     0,     0,     0,     0,     0,  1017,
       0,  1163,  1164,  1165,  1166,     0,   497,     0,     0,   498,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,   504,     0,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,     0,     0,
       0,   505,     0,   497,     0,     0,   498,     0,     0,  1147,
     500,     0,  1331,     0,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
     502,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,   500,     0,     0,  1167,   501,     0,   506,   499,     0,
       0,   487,  1168,     0,     0,     0,     0,     0,   503,     0,
       0,  1169,     0,   500,  1170,     0,     0,   501,     0,     0,
       0,     0,   499,     0,     0,   504,     0,     0,     0,     0,
       0,   502,     0,     0,     0,     0,     0,   500,     0,     0,
       0,   501,  2430,     0,     0,     0,     0,     0,   506,     0,
       0,     0,     0,   502,     0,   499,     0,  1171,     0,   503,
       0,     0,     0,     0,  1172,     0,     0,     0,  1147,     0,
     500,     0,     0,     0,   501,     0,   504,   502,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
    1012,     0,     0,     0,     0,     0,     0,     0,   504,   488,
     489,   490,   491,   492,   493,   503,   505,     0,     0,     0,
     502,     0,     0,     0,     0,     0,     0,   494,   495,   496,
       0,  1173,   504,  1324,  1325,  1326,     0,     0,     0,   283,
    1327,  1328,    39,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,  1332,     0,  1174,     0,     0,  1329,  1330,
       0,     0,  1175,     0,  1176,   504,     0,   505,     0,     0,
       0,     0,     0,     0,  1177,     0,     0,     0,     0,     0,
       0,  2430,   506,     0,  1333,     0,     0,  2431,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2432,
    1335,     0,  1178,     0,     0,     0,     0,     0,     0,     0,
    1179,     0,     0,   505,     0,     0,     0,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,     0,  1324,  1325,
    1326,     0,     0,   506,   283,  1327,  1328,    39,     0,  1336,
       0,  1331,     0,     0,     0,     0,   505,  1180,     0,     0,
       0,  1337,     0,  1329,  1330,   506,     0,     0,     0,   487,
       0,     0,     0,     0,     0,     0,   497,     0,     0,   498,
       0,  1181,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,  1332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1338,     0,     0,     0,     0,  1324,  1325,  1326,
       0,     0,     0,   283,  1327,  1328,    39,     0,  1182,     0,
       0,     0,   506,  1333,     0,     0,  2431,     0,     0,  1183,
       0,     0,  1329,  1330,     0,  1339,     0,     0,  2432,  1335,
       0,  1340,     0,     0,     0,     0,  1331,     0,     0,     0,
    1341,  1342,     0,  1343,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1344,  1345,   488,   489,   490,
     491,   492,   493,  1346,     0,     0,  1347,  1147,  1336,     0,
       0,     0,     0,     0,   304,   494,   495,   496,     0,     0,
    1337,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   500,     0,  1331,     0,   501,     0,     0,
       0,     0,     0,     0,     0,     0,  1184,  1185,  1186,     0,
       0,  1338,     0,     0,     0,  1324,  1325,  1326,     0,  1187,
       0,   283,  1327,  1328,    39,     0,     0,     0,     0,  2946,
    2947,     0,     0,   502,     0,   283,  1327,  1328,    39,     0,
    1329,  1330,     0,     0,  1339,     0,     0,     0,     0,     0,
    1340,     0,  1147,     0,  1329,  1330,     0,     0,     0,  1341,
    1342,   503,  1343,     0,  1188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1344,  1345,     0,     0,   504,     0,
       0,     0,  1346,     0,     0,  1347,     0,     0,  1324,  1325,
    1326,     0,     0,   304,   283,  1327,  1328,    39,     0,     0,
       0,     0,  2946,  2947,   497,     0,     0,   498,   283,  1327,
    1328,    39,     0,  1329,  1330,     0,     0,     0,     0,     0,
       0,  1147,  1189,  1331,  2946,  2947,     0,  1329,  1330,     0,
     283,  1327,  1328,    39,     0,     0,     0,  2948,  1190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1329,
    1330,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,  1332,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1333,     0,     0,  1334,  1331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1335,     0,
    2948,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   499,     0,     0,     0,
       0,     0,  2948,     0,     0,  1731,     0,     0,     0,     0,
       0,   500,     0,     0,     0,   501,     0,  1336,     0,  1147,
       0,     0,     0,     0,     0,     0,  1332,     0,     0,  1337,
       0,     0,     0,  1147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   502,     0,     0,     0,     0,     0,  1333,     0,     0,
    1334,   283,  1327,  1328,    39,     0,     0,     0,     0,     0,
    1338,     0,     0,  1335,     0,     0,     0,     0,     0,   503,
    1329,  1330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1147,     0,     0,  1332,   504,     0,     0,     0,
       0,     0,     0,  1339,     0,     0,  1147,     0,     0,  1340,
       0,  2265,  1336,     0,     0,   206,     0,     0,  1341,  1342,
       0,  1343,     0,     0,  1337,     0,  1333,     0,  1147,  1334,
       0,     0,   207,  1344,  1345,     0,     0,     0,     0,     0,
       0,  1346,  1335,     0,  1347,     0,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2948,     0,  1338,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
    3395,  1336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1337,     0,     0,     0,     0,  1339,     0,
       0,     0,     0,     0,  1340,     0,     0,     0,   208,     0,
       0,     0,     0,  1341,  1342,     0,  1343,     0,     0,     0,
       0,     0,     0,  1332,   209,   210,     0,     0,  1344,  1345,
       0,     0,     0,     0,  1338,   211,  1346,  1332,     0,  1347,
       0,     0,     0,   506,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,  1333,     0,     0,  1334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1339,  2949,     0,
    1335,  2950,     0,  1340,     0,     0,     0,     0,     0,     0,
       0,     0,  1341,  1342,  2951,  1343,     0,     0,     0,  1147,
       0,     0,     0,     0,     0,     0,  2062,  1344,  1345,     0,
       0,     0,     0,     0,     0,  1346,     0,     0,  1347,  1336,
    1332,     0,     0,     0,     0,     0,   304,     0,     0,     0,
       0,  1337,  2952,  2953,     0,     0,     0,  1333,     0,     0,
    1334,     0,  1332,     0,     0,  2954,     0,     0,     0,     0,
       0,  2949,     0,  1335,  2950,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2951,     0,     0,
       0,     0,  1338,  2949,     0,     0,  2950,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2955,     0,     0,  2951,
       0,     0,  1336,     0,  1731,     0,     0,  2297,  2298,  2299,
    2300,  2301,  2302,     0,  1337,  1339,  2953,     0,     0,     0,
       0,  1340,     0,     0,     0,   212,     0,     0,  2954,     0,
    1341,  1342,     0,  1343,     0,  2956,     0,     0,  2953,     0,
       0,     0,     0,     0,     0,  1344,  1345,  2957,     0,     0,
    2954,     0,     0,  1346,     0,  1338,  1347,     0,     0,  2958,
    2959,     0,     0,   213,   304,     0,     0,  2960,     0,  2955,
    2961,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,   214,   215,   216,   217,     0,     0,  1339,     0,
       0,  2955,     0,     0,  1340,     0,     0,     0,     0,     0,
     218,     0,     0,  1341,  1342,  2303,  1343,     0,  2956,     0,
       0,     0,     0,  1332,     0,     0,     0,     0,  1344,  1345,
    2957,     0,   219,     0,     0,     0,  1346,     0,     0,  1347,
    2956,     0,  2958,  2959,   220,     0,     0,   304,     0,     0,
    2960,     0,  2957,  2961,  2949,   221,     0,  2950,     0,     0,
       0,   304,     0,     0,  2958,  2959,     0,     0,     0,     0,
    2951,   222,  2960,     0,     0,  2961,     0,     0,     0,     0,
       0,   223,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2953,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3365,
       0,  2954,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,     0,  2955,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,  3366,     0,     0,     0,
     228,     0,     0,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3367,  2956,     0,     0,   230,     0,     0,     0,   231,  3368,
       0,     0,     0,  2957,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2958,  2959,   232,     0,     0,
       0,     0,     0,  2960,     0,     0,  2961,     0,     0,     0,
       0,     0,     0,     0,   304,   233,     0,  3369,     0,     0,
    2304,     0,     0,     0,     0,  3370,     0,     0,     0,     0,
       0,     0,     0,  2305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2306,     0,     0,     0,     0,
       0,  2307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3371,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2310,  2311,     0,     0,     0,     0,  2312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2314,     0,     0,  2315,  2316,     0,     0,     0,  2317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2318,     0,     0,     0,
       0,     0,     0,     0,     0,  3372,     0,  2319
};

static const short yycheck[] =
{
       3,     4,     5,     6,  1084,   178,     9,    10,   404,   819,
     673,  1500,  1204,   603,   112,    53,   606,  1177,    62,  1173,
    1174,   817,  1176,  1667,  1178,  1179,  2097,   829,  2099,   197,
     270,   271,   558,   656,  1406,  1199,  1413,   268,   269,   801,
       5,   740,   614,    27,   275,  1324,  1325,  2115,  1631,  1632,
     584,   180,   254,  1799,  1854,  1025,   133,    60,  1028,  2113,
      98,  2060,  2408,    27,    20,    48,  1802,  2252,  1981,  1158,
      73,    27,   776,  1793,  2653,  2654,  2655,    80,    27,    25,
     178,    27,    85,    27,  1359,    88,  1361,  1731,  1159,    92,
      93,     5,    27,     5,    77,    26,    27,     5,     5,   197,
       5,  2656,    24,  2183,    26,    25,   741,    27,   122,   112,
      27,  2296,     5,     5,   737,     5,    19,     5,     5,     8,
       5,    24,    25,    26,   127,   748,    36,   130,    19,   132,
     765,    27,     5,    24,   137,    26,   119,    38,   837,   713,
     123,     5,    53,   272,    25,    26,    27,   276,     5,   278,
      20,   280,   281,   282,    20,    25,   329,    27,    27,    25,
     289,    27,  2371,   240,   293,   294,   162,    27,   245,   246,
     807,   745,   746,   124,    19,   178,   811,   180,    19,  1259,
     803,    26,   124,   806,  1255,    26,   821,    98,     5,   824,
       5,  1438,   815,   828,   197,     5,   199,     5,  1269,   834,
      25,   836,    27,    19,  1740,  1741,  1742,  1743,    24,    25,
      26,     9,   335,    26,    12,    13,    14,    15,    16,    17,
      24,    25,    26,   797,    24,    25,    26,    27,    27,   143,
     144,   329,    24,    25,    26,    27,   334,  2423,   220,  2425,
     130,     6,   132,   212,   134,   248,     5,     5,   149,   150,
     151,   234,    24,    25,    26,    27,    70,   260,    45,    46,
      24,    25,    26,    27,   267,   268,   269,   270,   271,   272,
     122,    33,   275,   276,    25,   278,    27,   280,   281,   282,
      33,    24,    25,    26,    27,    25,   289,    27,    27,    27,
     293,   294,   490,    25,    30,    27,   212,   490,    34,    25,
     205,    27,     5,  1184,  1185,  2109,  2110,  2111,   551,  2292,
    2114,    27,    48,   647,   453,     5,     5,   446,   490,    27,
     449,   252,     5,     5,   199,   518,   329,  1993,   331,     5,
     333,   334,   402,   147,   148,   669,   402,   466,   467,   468,
     469,   298,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,  2358,
    1162,   529,   593,  2431,     5,   567,  1455,     6,    23,   498,
     499,     5,  2176,     5,   503,     5,   505,     6,   604,   362,
     453,    27,    36,   614,     5,  2185,     5,   825,     5,   518,
     519,   520,   521,   983,   682,   833,  1158,   526,   225,  1563,
    1210,   137,     5,   554,    27,    25,    30,    27,   518,  1781,
      34,   562,   485,  1223,    25,   429,    27,   705,   153,  1499,
      27,   407,   595,  2035,     5,  1802,  2038,   252,   411,   412,
     413,   529,   107,   108,   109,   110,   111,  2739,   225,     5,
       5,   310,   335,   446,    19,     5,   449,   634,   691,   675,
       9,    26,   252,    12,    13,    14,    15,    16,    17,  1948,
     252,  1096,   335,   466,   467,   468,   469,     5,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   683,  1288,   674,   252,   251,
     252,   115,   306,   437,     5,   498,   499,   595,   122,   252,
     503,   252,   505,   626,   672,     5,     5,  1081,   647,   252,
       0,   683,   252,   252,   252,   518,   519,   520,   521,     5,
     252,   559,   560,   526,   116,   117,   529,     5,     5,  1103,
     213,    27,     5,     5,     5,     5,   428,   213,  2342,     5,
     497,     5,     5,   412,     5,   169,   170,     5,  2352,   552,
       5,   554,   412,  2089,   146,   147,   148,     5,   500,   562,
       5,     5,   298,   794,     5,   548,   636,   677,     5,  1204,
     636,   127,   812,   813,   672,     5,   579,   429,   581,  1214,
     407,  1216,     5,   567,    18,    19,    20,    21,    22,   592,
     593,    27,   595,   596,    18,    19,    20,    21,    22,   307,
       5,   841,  2585,    10,   844,  2188,   200,   201,   453,  1405,
      23,   614,   320,     5,    31,   584,    20,     5,  2689,     5,
     407,   513,   897,    27,     5,   451,   522,  2626,   559,   486,
    1877,   613,   252,     5,   451,   433,   434,   529,   396,  3194,
     453,   296,     5,  2447,     5,   252,   446,     5,   559,   600,
    1287,  1461,   456,     5,  1450,   453,     5,   653,   600,     5,
    2728,   530,  3304,  1473,   456,     5,  3308,   653,   584,   672,
     530,   486,  1553,    23,  2340,   619,   486,     5,     5,   571,
       5,   612,   418,   597,     5,  2329,  1212,     5,   453,   447,
     488,   490,   456,  1455,     5,  2880,   412,   572,   647,   702,
     703,   608,   614,   466,   707,   530,   709,   710,   446,  2622,
     713,   714,   715,   421,  2899,   718,   453,   720,   610,   604,
     723,   735,   611,  1883,   611,  1315,   614,   486,  1318,  1319,
     466,   734,  2803,   626,  2805,  2944,  1399,   647,   741,   674,
     724,  2795,   745,   746,   608,   545,   436,   639,  2552,   669,
     453,  2497,   755,   626,   719,   677,   648,   674,  1462,  2479,
     724,   497,   765,  2499,  2376,   768,   530,   675,   724,   674,
     684,  2825,  1306,  2853,   677,   778,  2985,  2857,   724,   335,
     724,  1870,   683,   786,  2161,   675,   677,  2062,   669,  2166,
     526,   794,   795,   683,   797,   726,   604,   486,   801,   669,
     453,  3103,   647,   669,   486,   429,   647,   421,   811,   812,
     813,    29,   453,  3159,   453,   602,   614,  3003,   821,   453,
     823,   824,    27,   826,   453,   828,   534,  3173,  1463,  1464,
    1465,   834,  3411,   836,  2638,   838,   490,   840,   841,   446,
     843,   844,   550,   846,   490,  1480,   126,   573,   635,   611,
     453,   407,  2127,  2128,   486,  2338,   486,   680,   611,  1433,
    1000,   677,  1933,   517,   518,   486,   680,   486,  1442,   486,
     490,   307,   453,   677,   433,   434,   608,   677,   453,   490,
     344,   297,   680,   296,   320,   677,  1015,   453,   453,  1018,
     716,   490,   643,   453,   634,   451,  1025,  1471,  1027,  1028,
     524,   596,   496,   344,   311,   677,  1181,   387,   404,  1305,
     647,   734,   453,   677,  1189,   453,   412,   413,   517,  1554,
     534,    25,   514,    27,  1339,   579,  1341,  1342,  2999,   488,
    3001,  3002,   730,   731,   677,    25,   453,    27,  1573,   236,
      30,   437,   453,  2717,   440,  2719,   296,  1917,  2722,   952,
     645,  2534,    27,   453,   453,   711,   712,  1592,  3029,  3305,
     456,   696,   697,   698,   699,   700,   641,   453,  1603,  3154,
      18,    19,    20,    21,    22,   453,   453,   387,  1601,   720,
     453,   453,   453,   453,  2970,   421,  2790,   453,  2792,   972,
     453,   615,   453,   749,   647,   453,   752,  1000,   453,    25,
     736,    27,    26,    27,   307,   453,   762,   599,   453,   453,
     766,   424,  1015,  1585,   770,  1018,   453,   320,  3086,    28,
     352,   777,  1025,   453,  1027,  1028,   782,     0,   784,   643,
     453,   453,   364,   453,   790,   332,   669,   793,    26,    27,
    1043,   448,  1045,   450,   800,   786,  1572,   343,   453,    22,
     642,   807,   486,  1036,   490,   614,    28,    29,   814,   539,
     356,   453,   486,   559,  1733,   453,    25,   453,    27,   825,
     626,   695,   453,   829,   424,   490,   402,   833,  1081,   703,
      56,   453,  1656,   839,  1658,  1659,   842,   421,  1662,  1663,
     453,   518,   453,  1096,  1668,   453,   422,   356,   534,  2471,
    1103,   453,   307,   518,   453,  1915,   647,   453,  1870,   525,
    1312,   416,  2276,   453,   550,   320,   612,  1707,   421,   225,
    1710,   680,  2499,   619,   518,   453,   453,  2931,   453,   539,
     647,  3199,   453,  2213,  2409,   453,  2411,  2941,  2413,    26,
      27,   539,   453,   463,  1147,  2628,  2629,   563,   252,   674,
     706,   707,   708,  1156,   394,  1158,  1159,   304,    25,    20,
      27,   717,   252,   123,  3163,   518,    27,   676,   226,   449,
     228,   730,   731,  1747,   683,  1985,   677,   252,   154,   155,
     156,   157,   158,   159,    25,    13,    27,   490,  3174,  3175,
    1825,   307,   472,   489,  1334,  1991,   172,   173,   174,  1822,
     534,  1204,   682,    25,   320,    27,  1841,  1906,   298,    26,
      27,  1214,   226,  1216,   228,    25,   421,    27,  1221,  2021,
    3024,   701,   702,    26,    27,   647,   252,   647,   252,  1232,
     489,   534,     5,  1868,  1474,   310,    64,  1240,   198,   253,
    1875,   721,    25,  3017,    27,  1476,   416,   550,    26,    27,
     677,     5,  1255,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   252,  3010,  1269,    25,  3013,    27,
    1905,  3016,   682,   331,   554,    25,   334,    27,  1947,    25,
      25,    27,    27,   677,   682,   490,   226,  3358,   228,  2933,
    1925,   701,   702,   252,   647,  1869,   518,    56,   356,   530,
     260,   407,   262,   701,   702,   421,   537,   596,  1311,   643,
     636,   721,  2108,   253,   596,  1488,   669,   331,   278,   737,
     334,  1324,  1325,   721,   677,  1402,   286,  1404,   418,   534,
     290,  1334,   572,   653,     5,   311,   656,     8,   314,   647,
    1580,  1581,   356,   583,  1347,   550,  1457,   343,   647,  1460,
     517,   518,  1355,   752,  1585,   315,   645,  2167,   682,  2169,
     356,   669,  3166,   645,    14,   252,   646,   766,  2178,  2165,
     669,   770,   580,  1899,   268,   269,   270,   490,   658,   659,
     704,   705,   380,   782,  1428,   252,   666,  2876,  1628,  1629,
    1488,   331,   490,  2203,   334,   154,   155,   156,   157,   158,
     159,  2561,  2594,   232,  1407,   453,  1162,   497,  1411,  1412,
    1413,   252,    20,   172,   173,   174,   356,    20,   534,    27,
    1423,  1424,  1425,   490,    27,  1999,  1429,  1430,  1431,  1432,
    1433,   489,   697,   698,   550,   252,   526,  2716,  2717,  1442,
    2719,    20,   252,  2722,  2515,   711,   712,   490,    27,   252,
     716,   717,  1455,  3186,  2618,  3259,   682,   433,  2835,  2049,
    1463,  1464,  1465,   729,  3197,  2055,  2056,  2111,  1471,   252,
    2114,  1474,   448,  1476,   252,   489,   452,  1480,   704,   705,
     220,  3226,  1485,   749,    20,  1488,   752,  2558,   300,  1492,
    1493,    27,   758,   489,   252,  2984,   762,   727,   728,   729,
     766,    24,   252,    26,   770,  2079,   252,   252,   774,   775,
     398,   777,   488,    37,   780,   518,   782,   783,   784,    20,
    2155,   409,   351,   490,   790,   300,    27,   793,   357,   485,
    1286,  1287,  1288,   490,   800,  2170,  2171,  2172,  2173,  2162,
     516,   807,  2344,    20,   356,    24,    25,    26,   814,   489,
      27,  1554,   311,   164,   165,   314,  2191,   533,    24,   825,
      26,   490,  3362,   829,   490,   300,   460,   833,  2370,   490,
    1573,   459,    25,   839,    27,  1578,   842,  1580,  1581,  3379,
     320,   356,  1585,    20,    21,   473,  1589,  1590,  1591,  1592,
     490,  2214,    30,  1733,   490,  1735,    34,   490,   410,  2569,
    1603,  2175,   414,    45,    46,  1745,  1746,  2577,  2578,  2579,
      48,   490,  1752,  1753,  1754,  1755,   696,   357,   490,   699,
     700,   356,  1699,  2258,  1627,  1628,  1629,   840,    40,    41,
     843,  3431,    25,   846,    27,   410,  1876,  1766,   614,   414,
     490,  2264,  3178,   490,  3180,  3181,  3182,  3183,  3448,  3292,
    3293,  3294,  1655,  1656,   784,  1658,  1659,   181,   490,  1662,
    1663,    26,  1665,   793,   490,  1668,  1182,  1183,    26,  3158,
    1186,  1187,   490,   561,   433,   410,    25,   489,    27,   414,
      25,   421,    27,   199,    45,    46,    27,   203,    24,   448,
      26,   490,   428,   452,   490,   435,   428,   517,   518,   137,
    1703,   172,   173,   174,   680,   490,    47,   428,   490,   839,
    2520,    24,   842,    26,   489,   699,   700,   154,   155,   156,
     157,   158,   159,    25,   490,    27,  2361,   490,  2363,   488,
    1733,    25,  1735,    27,  1965,  1966,    26,  3380,  3017,  3382,
    1980,   428,  1745,  1746,  1747,  2555,    25,  1750,    27,  1752,
    1753,  1754,  1755,  2327,   489,   683,   428,   516,   428,   283,
     706,   707,  1765,  1766,    24,   490,    26,   291,    24,  1898,
      26,   706,   707,   297,   533,   299,    25,   513,    27,   348,
     349,   513,  2356,  2489,  2490,  1788,   310,   490,  1917,  1772,
    1793,   490,   513,   529,   534,   518,  1799,   529,  2372,  1802,
     490,  2391,  1942,    26,  2394,  2885,  2396,  2397,   529,   490,
     550,    20,    21,   337,    25,   490,    27,  1820,   670,   671,
     672,   673,  1825,  1826,  2946,  2947,   513,   168,    24,   353,
      26,    24,   490,    26,   358,   571,   517,   518,  1841,   571,
     683,   513,   529,   513,   490,    26,   370,   498,    26,  2423,
     571,  2425,  1855,   377,    25,   614,    27,   529,   509,   529,
     298,    26,   677,   490,   584,  1868,  1869,  1870,   490,   490,
    1873,  1874,  1875,  1876,   610,   490,   217,   490,   610,   530,
    2950,   490,    26,   490,   571,   536,   490,   480,   490,   610,
     518,  2526,    26,   544,  2529,  1898,  1162,    26,   579,   571,
     490,   571,  1905,   639,    26,    26,    26,   639,    26,    26,
    1913,   252,   648,   254,  1917,   566,   648,   677,   639,  2889,
    2060,   680,  1925,   610,   453,   120,   423,   648,   677,  2069,
    1933,    26,  2072,  2073,  2074,  2075,  1939,  1940,   610,  1942,
     610,   453,   703,  3107,  1947,   154,   155,   156,   157,   158,
     159,   490,   639,  3117,   715,    18,    19,    20,    21,  2594,
     490,   648,  1965,  1966,   486,     5,   453,   639,   453,   639,
    3134,   490,   453,   734,    26,   453,   648,  1980,   648,  2553,
     418,   453,   530,  2652,  2653,  2654,  2655,   490,   453,  2785,
     683,    20,    20,   229,   755,   490,  1999,    18,    19,    20,
      21,   525,   490,   453,     5,   518,   530,   768,   490,   350,
     490,    26,   536,   681,   677,  2430,    26,  2432,   453,   453,
    1286,  1287,  1288,  2196,   320,   486,   423,    30,   466,    20,
      26,  2034,  2035,  2843,   558,  2038,    26,    26,    26,   563,
      26,   647,    26,    26,  2840,  2744,  2745,  2746,   647,  2748,
    2749,  2750,  2751,  2752,  2753,   453,    26,  2060,  2757,   497,
      26,  2871,   453,   453,   453,   453,  2069,     5,   453,  2072,
    2073,  2074,  2075,  2076,    20,    26,  2079,   490,   419,    26,
    2083,  2084,    26,    26,  2087,   677,   427,   453,   526,     5,
     431,   154,   155,   156,   157,   158,   159,   453,  2196,   683,
      26,   453,   363,  1859,   681,   453,  2109,  2110,  2111,  3179,
     453,  2114,  2115,  2116,   453,  3185,  2119,  3281,  3188,  3189,
    3190,  3191,  1002,   453,     5,  1005,   467,  1007,  1008,  1009,
    1010,  1011,   453,   154,   155,   156,   157,   158,   159,    18,
      19,    20,    21,    22,   453,  2148,   490,  2150,  2151,   683,
    2153,  2154,  2155,    26,  2157,   453,    26,   647,  2161,    25,
     453,    25,   683,  2166,    25,   453,    25,  2170,  2171,  2172,
    2173,   453,  2175,  2176,   363,   453,  2179,   453,   453,  2182,
    2183,   453,   453,   453,   453,   453,   453,   681,  2191,   453,
     683,   532,     8,  2196,   677,   490,   198,   486,   682,   537,
     327,   677,    53,    54,    55,   441,    57,  2210,    59,    60,
    3290,  3365,  3366,  3367,  3368,  3369,  3370,   653,  2358,   455,
     519,     5,   653,   739,   740,   480,   675,  3391,   519,  2864,
     571,   675,  1988,   518,   677,   389,   669,  2652,  2653,  2654,
    2655,  3311,  2816,   716,  3314,  3315,  3316,  3317,   222,   716,
     677,   654,     5,   480,   595,  2258,     5,   490,   260,   490,
     262,   490,   498,   237,   238,  2021,  2901,   407,   490,   490,
     717,     8,   246,   509,  2277,  2415,   278,  2946,  2947,   636,
      14,  2950,   729,   633,   286,     5,   716,     5,   290,   480,
     716,  2431,   490,   490,   530,    26,    26,   127,   639,   301,
     536,  3111,  2442,  2718,   153,  2720,   280,   648,   544,   677,
     198,   758,   518,   315,    26,   289,   647,   490,   490,  3129,
     490,   837,   490,   490,  2327,   480,   490,   774,   775,   490,
     566,   847,  3402,   780,   490,   518,   783,    26,     5,  2342,
     490,   653,  3011,   490,   318,  3014,     5,  2350,  2351,  2352,
     683,  2389,  2355,  2356,   490,  2358,   683,   490,  2361,   719,
    2363,   614,   682,   413,     5,    18,   674,  3030,  2371,  2372,
      19,   215,   260,  2376,   262,   453,   445,  2608,  2551,  2610,
      25,   647,  2652,  2653,  2654,  2655,   636,   540,   362,   540,
     278,   732,   733,   680,   677,     5,  3198,   604,   286,   213,
     604,    26,   290,  2993,   460,  2995,  2996,   643,    47,   384,
     604,  3381,  2415,   649,    26,   453,   453,    26,   453,   453,
    2423,   683,  2425,  2426,   530,  2593,  2429,   315,  2431,  3003,
       5,   677,   406,   453,  3514,  2564,  1296,   453,   584,  2442,
    2569,   683,   674,   490,  2447,   490,  2449,   490,  2577,  2578,
    2579,   490,     5,  2551,   490,  2595,   119,   677,  2461,   647,
     453,   677,  3272,   721,   490,   647,   604,     5,   683,   674,
       5,   674,   111,   112,     5,   637,  2479,     5,  3113,   541,
     331,   683,   682,   334,  1000,   336,  2626,   677,     5,     8,
     490,   380,    26,    26,  2497,  2593,  2499,   127,   280,     5,
       5,   388,   422,   453,   683,   356,   654,    14,  3177,  2512,
    3179,   490,  2515,   490,  3149,   366,  3185,  3186,   490,  3188,
    3189,  3190,  3191,  2526,   608,   717,  2529,   604,  3197,     5,
      26,  2946,  2947,   162,   490,  2950,   387,   490,   677,   178,
     683,   682,  2545,   604,  2547,     5,  2549,   682,  2551,  2552,
    2553,   683,   486,   453,   696,  2558,   453,     5,   197,   410,
     453,  2564,     5,   414,     5,   430,  2569,   676,  1084,   394,
    2573,    26,   486,   490,  2577,  2578,  2579,   490,   520,   520,
     490,   490,  2338,   490,  2724,   490,   490,   490,  2344,     5,
    2593,  2594,  2595,  1859,   677,     5,  2992,   677,   677,     8,
     518,     5,   634,   611,    25,  2608,   407,  2610,   388,   407,
     518,   677,   407,   490,  2370,   422,   485,   518,     5,     5,
     708,  2861,     5,  2626,    26,     5,    25,   266,    26,    14,
      14,   653,   674,   490,  2874,  2638,   653,     5,   489,     5,
     611,   453,  3311,   490,    26,  3314,  3315,  3316,  3317,  2652,
    2653,  2654,  2655,  2656,  2657,     6,   683,   453,     7,   453,
     453,   453,   507,   329,   453,     8,   453,     5,  2671,    26,
     677,  3340,    26,    26,   683,   453,  2946,  2947,    26,    26,
    2950,    20,  2855,   322,   323,   677,     8,     5,   624,   335,
     329,     5,   677,     5,     5,   334,   453,     5,   604,     8,
     725,   629,   453,   530,  2707,  2708,     5,   490,   677,   604,
     683,     5,   273,  2716,  2717,   683,  2719,   681,   453,  2722,
     453,  2724,  1988,    26,   453,  2728,   683,   490,   683,   683,
     490,     5,     5,  3402,   683,    25,   681,    25,    25,   676,
     506,  3376,  3411,  1259,    25,  3335,  3336,   322,    25,   357,
      25,   453,   453,     5,    26,  2021,    26,  2855,    26,    26,
    2889,    26,    26,    26,  3179,   453,   453,   490,   527,     5,
    3185,  3186,  2494,  3188,  3189,  3190,  3191,   490,   453,   608,
       8,   302,  3197,    26,    25,   360,   486,  2790,  2791,  2792,
     500,   453,   453,   407,    20,   490,   204,   490,   611,   490,
     490,     5,     5,    14,   379,   380,   490,   490,  1324,  1325,
     490,   273,     5,  2816,   518,   453,   453,    26,  1334,  2652,
    2653,  2654,  2655,   501,    26,  2828,  2829,   453,    26,  2832,
    1690,  1691,  2835,   453,   453,   490,    26,  1697,    26,    26,
     436,   626,    26,   302,   419,  3480,   453,   453,   453,   407,
    2853,   453,  2855,  2856,  2857,   490,   431,   303,  2861,   604,
     518,  2864,   490,   453,   500,    14,   453,   442,   453,     7,
     301,  2874,  2628,  2629,   301,  3106,    26,   453,   517,   683,
    3020,   453,  3022,   458,   454,   453,  2889,   490,   453,   677,
     529,   633,    26,   468,   486,   490,  3311,    25,  2901,  3314,
    3315,  3316,  3317,   303,   453,   453,   453,   453,   483,  3179,
     453,     5,    26,    26,   518,  3185,  3186,   453,  3188,  3189,
    3190,  3191,  2925,   677,     5,   677,   486,  3197,  2931,   453,
    2652,  2653,  2654,  2655,    26,   486,   677,  2940,  2941,  2512,
    2943,  2944,  3441,  2946,  2947,  2572,  1027,  2950,   523,  1593,
    2248,  1926,   691,    35,    37,  2179,   595,  2545,  2961,   362,
    2185,   119,   123,   214,   239,   353,  1771,   676,   363,   548,
     545,  1772,   219,   617,   392,  3431,  1323,   391,   579,  1825,
     823,   581,  2985,  1499,  2039,   560,  1293,  3402,  1018,   427,
    2032,  2172,   567,  1875,  1627,   570,  3411,  2597,  2911,  1630,
    3003,  1955,  2273,  3485,  2175,  1975,  1476,  3125,  3011,    22,
      98,  3014,    47,  2389,  3017,    47,   591,  3020,    28,  3022,
     595,  3024,   954,  3163,  1931,  1937,  1604,   334,  3048,   779,
    1635,  1045,  1940,   672,  1551,  1260,  3235,  3177,  1470,   614,
     804,  3311,  1549,  3448,  3314,  3315,  3316,  3317,  1908,  2595,
    1460,  3245,  2783,  1573,  1905,  2766,  2781,   632,   465,  2459,
    2841,  3104,  3102,  3095,  2832,   704,   705,   706,  1805,   708,
    2166,  1788,  2338,  2119,  2338,  3457,  3024,  2010,  2344,  1670,
    2357,  1670,  2943,  3086,  2789,  3259,   725,  2079,  1998,  2823,
     365,  1951,  2707,  2429,  3340,  2708,   371,   372,   373,  3014,
    2482,  2811,  1655,  3106,  2370,  3067,  2461,  2426,   624,     9,
    3113,  3503,  1289,  2946,  2947,  2448,  2945,  2950,   393,  1635,
    2449,  2639,   761,    20,    21,    22,  1746,  3022,   767,  3297,
     769,  1745,  3402,  1285,   773,  1649,  3301,   776,  2940,  2351,
     779,  3411,  3177,  3196,  3185,  2553,  3149,  1622,  1765,  1147,
     789,  1485,  2196,  1493,  2551,    -1,  1475,    -1,    -1,    56,
    3163,   557,    -1,  3166,    -1,   804,    -1,  3307,    -1,    -1,
      -1,   810,    -1,    -1,  3177,    -1,  3179,    -1,   817,   818,
     819,    -1,  3185,  3186,   823,  3188,  3189,  3190,  3191,    -1,
      -1,  3194,   831,  3196,  3197,    -1,  3199,    -1,    -1,  3297,
      -1,    -1,    -1,    -1,  3344,    -1,    -1,    -1,   847,    -1,
      -1,    -1,    -1,    -1,    -1,   490,    -1,  1733,    -1,  1735,
      -1,    -1,    -1,   498,  2946,  2947,   501,    -1,  2950,  1745,
    1746,    -1,    -1,    -1,   509,    -1,  1752,  1753,  1754,  1755,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3381,    -1,    -1,   125,  3259,   154,   155,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,   543,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,  3011,
      -1,    -1,  3014,    -1,  3297,    -1,    -1,    -1,  3301,    -1,
      -1,    -1,    -1,   578,  3307,    -1,    -1,    -1,  3311,    -1,
      -1,  3314,  3315,  3316,  3317,    -1,  3319,  3457,    -1,    -1,
      -1,    -1,   597,   598,    -1,    -1,    -1,    -1,    -1,    -1,
    3333,    -1,    -1,   608,    -1,    -1,    -1,  3340,   613,    -1,
      -1,  3344,    -1,    -1,    -1,    -1,  3179,    -1,    -1,    -1,
      -1,    -1,  3185,  3186,    -1,  3188,  3189,  3190,  3191,    -1,
      -1,    -1,  2628,  2629,  3197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3376,  3377,    -1,   160,   652,  3381,    -1,
      -1,    -1,  2242,  2243,    -1,    -1,    -1,    -1,    -1,    25,
    1906,    -1,    -1,  2253,    -1,    -1,    -1,    -1,    -1,  3402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3411,   684,
      -1,    -1,    -1,    -1,   311,    -1,    -1,   314,  2278,  2279,
    2280,  2281,  2282,  2283,    -1,    -1,  1942,    -1,  2288,  2289,
    2290,  2291,    -1,    -1,    -1,  2295,    -1,    -1,    -1,    -1,
      -1,    -1,  3198,    -1,    -1,  1084,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3457,    -1,  3459,  3179,    -1,    -1,
      -1,  1100,    -1,  3185,  3186,    -1,  3188,  3189,  3190,  3191,
      -1,    -1,    -1,    -1,    -1,  3197,    -1,  3480,  3311,    -1,
      -1,  3314,  3315,  3316,  3317,    -1,    -1,    -1,    -1,    -1,
     360,    -1,    -1,    -1,  3216,    -1,    -1,    -1,  3501,  3502,
    3503,    -1,    -1,  1142,    -1,    -1,    -1,    -1,    -1,    -1,
     380,   381,   382,  3516,    -1,    -1,    -1,  2377,  2378,    -1,
      -1,    -1,    -1,    -1,  2384,  2385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1172,  1173,  1174,   433,  1176,    -1,  1178,
    1179,    -1,    -1,    -1,  2060,  1184,  1185,    -1,    -1,   419,
      -1,   448,    -1,  2069,    -1,   452,  2072,  2073,  2074,  2075,
      -1,   431,    -1,    -1,    -1,    -1,    -1,    -1,  2084,  3402,
      -1,  1210,   442,    -1,    -1,    -1,    -1,    -1,  3411,    -1,
      -1,    -1,    -1,    -1,  1223,    -1,    -1,    -1,   458,  3311,
      -1,   488,  3314,  3315,  3316,  3317,  1235,    -1,   468,  2115,
      -1,    18,    19,   239,    -1,    -1,    -1,    -1,    -1,    26,
      27,   395,    -1,   483,    -1,    -1,    -1,    -1,  3340,   516,
    1259,  1260,    -1,     9,   408,    -1,    -1,    -1,    -1,  1268,
      47,    -1,    18,    19,    20,    -1,   533,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,  1284,  1285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2535,  2536,    -1,    -1,    -1,
    3402,    -1,    -1,    -1,  2544,    -1,   470,    -1,    -1,  3411,
     560,    -1,   476,    -1,    -1,    -1,    -1,  2213,    -1,    -1,
     570,    -1,    -1,    -1,   121,    53,    54,    55,    -1,    57,
      -1,    59,    60,    -1,    -1,    -1,   133,   614,    -1,    -1,
      -1,   591,  2582,  2583,    -1,   595,    -1,    -1,    -1,   365,
      -1,   515,    -1,    -1,    -1,   371,   372,   373,    -1,    -1,
     126,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,  2609,
      -1,  2611,    -1,   623,   538,    -1,    -1,   393,    -1,    -1,
      -1,    -1,   632,    -1,   548,   549,  1405,    -1,    -1,    -1,
     554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,    -1,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   586,    -1,    -1,   589,   590,    -1,    -1,    -1,
     594,  1450,  2672,  2673,    -1,    -1,  2676,  2677,  1457,    -1,
      -1,  1460,  1461,  1462,    -1,    -1,  3092,    -1,    -1,    -1,
    1469,  1470,    -1,    -1,  1473,   252,  3102,   254,  1477,    -1,
      -1,    -1,  2358,    -1,    -1,    -1,    -1,    -1,    -1,  1488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1499,  1500,   498,    -1,    -1,   501,   252,   651,    -1,    -1,
      -1,    -1,    -1,   509,     5,     6,     7,     8,   662,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2415,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      -1,  1550,  1551,  2429,  1553,  2431,    -1,  1556,  1557,    -1,
      -1,    -1,    -1,    -1,    -1,    56,  2442,    -1,     9,    -1,
      -1,    -1,  3198,   350,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,   578,    24,    25,    26,    27,    -1,  1587,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   597,   598,    -1,    -1,    -1,    47,    -1,   385,   355,
      -1,    -1,   608,    -1,    -1,    -1,  1615,   613,  2494,    -1,
      -1,    -1,    -1,   331,    -1,    -1,   334,    -1,   336,    -1,
      -1,    -1,    -1,    -1,  2854,  1634,  1635,    -1,  2858,    -1,
      -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,   356,    -1,
      -1,    -1,    -1,    -1,   431,    -1,   652,  2877,   366,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2897,    -1,   387,
     121,   172,   173,   174,    -1,   126,    -1,    -1,   684,    -1,
     467,    -1,   133,  1692,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   410,    -1,    -1,   482,   414,    -1,    -1,    -1,
     456,    20,    -1,   490,    -1,    24,    25,    26,    27,  2595,
     161,    53,    54,    55,    -1,    57,   503,    59,    60,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,   487,    -1,    -1,   490,    -1,    -1,    -1,    -1,    -1,
    2626,    -1,    -1,    -1,    -1,    -1,   502,   503,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,
      -1,    -1,    -1,    -1,    -1,    -1,  2652,  2653,  2654,  2655,
      -1,   489,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   571,    -1,   542,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,   252,    -1,   254,    -1,    -1,    -1,   126,   595,    -1,
     311,    -1,    -1,   314,    16,    17,    18,    19,    20,    21,
      22,  2707,  2708,    -1,    56,    -1,    -1,    -1,    -1,    -1,
    2716,  2717,    -1,  2719,    -1,    -1,  2722,    -1,  2724,   595,
      -1,    -1,  2728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   639,    -1,    56,    -1,    -1,    -1,  2744,  2745,
    2746,   648,  2748,  2749,  2750,  2751,  2752,  2753,    -1,    -1,
      -1,  2757,   628,    -1,    -1,    -1,    -1,    -1,   634,    -1,
      -1,    -1,  1891,    -1,    -1,    -1,    -1,   643,   644,    -1,
     646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,   658,   659,   355,    -1,  1915,    -1,    -1,    -1,
     666,    -1,    -1,   669,    -1,    -1,    -1,  3147,    -1,    -1,
    3150,   677,   154,   155,   156,   157,   158,   159,  1937,    -1,
      -1,    -1,   433,   252,   385,    -1,    -1,  1946,    -1,  1948,
     172,   173,   174,    -1,    -1,   732,   733,   448,    -1,    -1,
      -1,   452,   154,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,
     172,   173,   174,    -1,    -1,    -1,  1985,  1986,  1987,    -1,
     431,    -1,  1991,    -1,    -1,    -1,    -1,   488,    -1,   331,
      -1,    -1,   334,    -1,   336,    -1,    -1,    -1,   449,  2885,
      -1,    -1,    -1,   454,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   356,   516,   467,  2026,    -1,    -1,
      -1,   472,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   533,    -1,    -1,    -1,   487,    -1,    -1,   490,
       9,    -1,   493,    -1,    -1,   387,    -1,    -1,    -1,    18,
      19,   502,   503,    -1,    -1,    24,    25,    26,    27,    -1,
    2946,  2947,    -1,    -1,  2950,  3295,    -1,    -1,   410,    -1,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    47,   311,
      -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     541,   542,    -1,    -1,    -1,   546,    -1,    -1,    -1,  2108,
      -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,   311,
      -1,    -1,   314,   614,   565,    -1,  3346,  3347,    -1,  3349,
     571,  3351,  3352,    -1,    -1,  3011,    -1,    -1,  3014,    -1,
      -1,  3017,    -1,    -1,  3020,    -1,  3022,   456,    -1,    -1,
      -1,    -1,    -1,    -1,   595,    -1,    -1,   489,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,  2165,   126,  2167,    -1,
    2169,    -1,    -1,    -1,   133,    -1,    -1,    -1,   487,  2178,
      -1,   490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,
      -1,    -1,    -1,    -1,   503,    -1,    -1,  2196,   639,  3419,
      -1,  3421,   161,    -1,  2203,   646,    -1,   648,    -1,    -1,
    3086,   433,    -1,    -1,  2213,    -1,    -1,   658,   659,    -1,
      -1,    -1,    -1,  2222,    -1,   666,   448,  2226,    -1,    -1,
     452,    -1,    -1,   542,    -1,  3455,   677,    -1,    -1,    -1,
      -1,   433,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2252,  3474,  3475,   448,    -1,  3478,    -1,
     452,  3481,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   595,  3163,    -1,    -1,
      -1,   732,   733,   252,   516,   254,   488,    -1,    -1,    -1,
      -1,  3177,    -1,  3179,    -1,    -1,    -1,    -1,    -1,  3185,
    3186,   533,  3188,  3189,  3190,  3191,    -1,    -1,    -1,   628,
      -1,  3197,    -1,  3199,   516,   634,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   643,   644,    -1,   646,    -1,    -1,
    3216,   533,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   658,
     659,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,
     669,    -1,    -1,    -1,    -1,     9,    -1,    -1,   677,    -1,
      -1,    -1,    -1,    -1,    18,    19,  2375,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,   614,    -1,    -1,    -1,   355,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3290,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   614,    -1,    -1,    -1,   385,    -1,    -1,    -1,
      -1,  3307,    -1,    -1,    -1,  3311,    -1,    -1,  3314,  3315,
    3316,  3317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2448,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,    -1,
     419,    -1,    -1,    -1,  3340,    -1,    -1,    -1,  3344,    -1,
      -1,    -1,   431,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,   680,   133,
     449,    -1,    -1,    -1,    -1,   454,    -1,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,   161,    -1,    -1,
      -1,  2520,    -1,   482,    -1,    -1,  3402,    -1,   487,    -1,
      -1,   490,    -1,    -1,   493,  3411,    -1,    17,    18,    19,
      20,    21,    22,   502,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2551,    -1,    -1,    -1,  2555,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2570,    -1,  2572,    -1,  2574,    56,    -1,    -1,    -1,
      -1,  3457,   541,   542,    -1,    -1,    -1,   546,    -1,  2588,
      -1,    -1,    -1,    -1,  2593,   554,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   565,    -1,   252,    -1,
     254,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2620,  2621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,   595,    -1,  3514,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2666,    -1,    -1,
      -1,    47,    -1,    -1,   154,   155,   156,   157,   158,   159,
     639,    -1,    -1,    -1,    -1,    -1,    -1,   646,    -1,   648,
      -1,    -1,   172,   173,   174,    -1,    -1,    -1,    -1,   658,
     659,    -1,    -1,    -1,    -1,    -1,   350,   666,    -1,    -1,
      -1,   355,    -1,    -1,     5,     6,     7,     8,   677,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,  2768,
      -1,    -1,    -1,   732,   733,   419,    -1,    -1,    -1,    -1,
      -1,  2780,    -1,    -1,    -1,   161,  2785,   431,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,
     454,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,   472,    -1,
      -1,   311,    -1,    -1,   314,    -1,    -1,    -1,   482,    -1,
      -1,  2840,    -1,   487,  2843,    -1,   490,    -1,    -1,   493,
      -1,    -1,    -1,    -1,    -1,    -1,  2855,    -1,   502,   503,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,  2871,    -1,    -1,    -1,   252,  2876,   254,    -1,
     322,   172,   173,   174,    -1,    -1,  2885,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,
      -1,    -1,   546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,    -1,
      -1,   565,    -1,   567,    -1,    -1,    -1,   571,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   379,   380,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,   595,    -1,   433,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    56,
      -1,    -1,   452,    -1,   350,    -1,    -1,   419,    47,   355,
      -1,    -1,    -1,    -1,    -1,  2984,    -1,    -1,    -1,   431,
      -1,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,    -1,
     442,    -1,   646,    -1,   648,    -1,    -1,    -1,   488,   385,
      -1,    -1,    -1,    -1,   658,   659,   458,    -1,    -1,    -1,
     311,    -1,   666,   314,    -1,    -1,   468,    -1,    -1,    -1,
      -1,    -1,    -1,   677,    -1,    -1,   516,    -1,    -1,    -1,
      -1,   483,    -1,   419,    -1,    -1,    -1,    -1,    -1,  3048,
      -1,    -1,   121,   533,    -1,   431,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,    -1,   154,   155,   156,
     157,   158,   159,   449,    -1,    -1,    -1,    -1,   454,    -1,
     456,   523,    -1,    -1,    -1,   172,   173,   174,   732,   733,
      -1,   467,   161,    -1,    -1,    -1,   472,    -1,    -1,    -1,
      -1,    -1,    -1,   545,    -1,    -1,   482,    -1,    -1,    -1,
      -1,   487,  3111,    -1,   490,    -1,    -1,   493,   560,    -1,
      -1,    -1,    -1,    -1,    -1,   567,   502,   503,   570,    -1,
    3129,    -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,   591,
      -1,    -1,    -1,   595,    -1,    -1,    -1,   448,    -1,  3158,
      -1,   452,    -1,    -1,    -1,   541,   542,    -1,    -1,    -1,
     546,    -1,   614,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,   252,    -1,   254,    -1,    -1,    -1,   565,
     632,    -1,    -1,    -1,    -1,   571,    -1,   488,    -1,    -1,
     680,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   595,
      -1,    -1,    -1,    -1,   311,   516,    -1,   314,    -1,    -1,
      -1,    53,    54,    55,    -1,    57,  3235,    59,    60,    -1,
      -1,  3240,   533,  3242,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   639,    -1,    -1,    -1,    -1,    -1,    -1,
     646,    -1,   648,  3272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,   658,   659,    -1,    -1,   355,    -1,    -1,    -1,
     666,  3290,    -1,    -1,    56,    -1,    -1,    -1,  3297,    -1,
      -1,   677,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,
     419,    -1,    -1,    -1,    -1,    -1,   732,   733,    -1,    -1,
      -1,   448,   431,    -1,    -1,   452,  3365,  3366,  3367,  3368,
    3369,  3370,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     449,    -1,    -1,    -1,    -1,   454,    -1,   456,    -1,   680,
      -1,    -1,   154,   155,   156,   157,   158,   159,   467,    -1,
      -1,   488,    -1,   472,   226,    -1,   228,    -1,    -1,    -1,
     172,   173,   174,   482,    -1,    -1,    -1,    -1,   487,    -1,
      -1,   490,    -1,    -1,   493,    -1,    -1,    -1,    -1,   516,
      -1,   253,    -1,   502,   503,    -1,    -1,    -1,   260,    -1,
     262,    -1,    -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,   290,    -1,
      -1,    -1,    -1,   542,   296,    -1,    -1,   546,   300,   301,
     302,   303,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   315,    -1,    -1,   565,    18,    19,    20,
      21,    22,   571,    -1,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    -1,   334,    -1,   336,  3514,    -1,    -1,    -1,    -1,
      -1,   343,    -1,    -1,    -1,    -1,   595,   614,    -1,    -1,
      -1,    -1,    -1,    -1,   356,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,   311,
      -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,   138,   139,   140,   387,   388,    -1,    -1,    -1,
     639,    -1,    -1,    -1,    -1,    -1,    -1,   646,    -1,   648,
     402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,   658,
     659,    -1,   414,   680,    -1,    -1,    -1,   666,    -1,    -1,
     422,   423,   424,    -1,    -1,    -1,    -1,    -1,   677,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   732,   733,    -1,    -1,   489,    -1,    -1,
     246,   433,    -1,    -1,    -1,    -1,    -1,    -1,   500,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,
     452,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   289,    -1,    -1,    -1,   539,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      -1,    -1,   318,   319,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,   516,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,   533,    -1,    68,    69,    -1,    -1,    -1,   600,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,
     311,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   636,    -1,    -1,    -1,   113,   114,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     406,    -1,    -1,   128,   129,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,   166,   167,    -1,   696,   697,   698,   699,   700,   701,
     702,    -1,   704,   705,   460,   180,    -1,   182,   183,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   721,
     195,   196,   197,    -1,    -1,    -1,    -1,    -1,   203,    -1,
      -1,   206,   433,   208,   209,   210,    -1,    -1,   680,    -1,
      -1,   216,    -1,   218,   219,    -1,   221,   448,   223,   224,
      -1,   452,   227,    -1,    -1,   230,   231,   232,   233,   234,
     235,    -1,    -1,    -1,   239,   240,   241,    -1,   243,    -1,
      -1,    -1,   247,    -1,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,   258,    -1,    -1,   261,   488,   263,    -1,
     265,    -1,   267,    -1,    -1,    -1,   271,   272,    -1,   274,
     275,   276,    -1,    -1,   279,    -1,   281,   282,    -1,   284,
      -1,    -1,    -1,    -1,    -1,   516,    -1,   292,   293,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     305,    -1,   533,   308,   309,    -1,    -1,   312,   313,    -1,
      -1,   316,   317,    -1,    -1,    -1,    -1,    -1,    -1,   324,
     325,   326,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   338,   339,   340,    -1,   342,    -1,    -1,
      -1,   346,   347,    -1,    -1,    -1,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   367,   368,   369,    -1,    -1,    -1,    -1,    -1,
     375,   376,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,
      -1,   386,    -1,   614,    -1,   390,   391,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,    -1,
      -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   426,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,
     455,    -1,    -1,    -1,    -1,    -1,   461,    -1,   463,   464,
      -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,
      -1,    -1,    -1,   528,    -1,    56,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   551,   552,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,   574,
     575,   576,   577,    -1,    -1,    -1,   581,    56,    -1,    -1,
     585,    -1,    -1,    -1,    -1,    -1,    -1,   592,   593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,
     605,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   616,    -1,   618,    -1,    -1,   621,    -1,    -1,    -1,
      -1,    -1,   627,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,    -1,    -1,    -1,    -1,   653,    -1,
      -1,   656,    -1,    -1,    -1,    -1,   661,    -1,    -1,   664,
     665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   679,   154,   155,   156,   157,   158,
     159,   686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   709,   710,   711,   712,   713,   714,
     715,    -1,    -1,   718,    -1,   720,    -1,   722,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,   311,    -1,    -1,   314,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    56,    -1,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,   154,   155,   156,
     157,   158,   159,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,   433,    -1,    -1,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,
      -1,   452,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   433,    -1,    -1,   488,   172,   173,
     174,   154,   155,   156,   157,   158,   159,    -1,    -1,   448,
      -1,    -1,    -1,   452,   453,    -1,    -1,    -1,    -1,   172,
     173,   174,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,   488,
      -1,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   311,    -1,    -1,   314,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,
      -1,    -1,    -1,    -1,   311,    -1,    -1,   314,    -1,    -1,
      -1,    -1,    -1,    -1,   533,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,
     314,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,
      -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,   680,
     311,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,
     448,    -1,    -1,    -1,   452,   453,   433,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,   452,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     488,   680,    -1,    -1,   154,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,
      -1,   488,   172,   173,   174,    -1,    -1,    -1,   516,    -1,
      -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,   452,   453,
     433,    -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,   516,
      -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,   452,
     453,    -1,    -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,
      -1,    -1,   433,    -1,   488,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,
      -1,   452,   453,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,   516,    -1,    -1,   614,   488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     533,    -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
      -1,   311,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   533,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   680,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    56,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   680,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   433,    -1,    -1,    -1,   680,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,
      -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,   501,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   516,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    56,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,
      -1,   314,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    56,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,   311,
     680,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,   154,   155,   156,
     157,   158,   159,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,   172,   173,   174,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
     433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,    -1,   448,    -1,    -1,    -1,   452,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,
      -1,   433,    -1,   311,    -1,   488,   314,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,   448,    -1,   501,    -1,
     452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   516,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
     533,    -1,    -1,    -1,   311,    -1,   488,   314,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,
      -1,    71,    72,    73,    74,    -1,   311,    -1,    -1,   314,
      -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,   533,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,    -1,
      -1,   614,    -1,   311,    -1,    -1,   314,    -1,    -1,   252,
     448,    -1,   126,    -1,   452,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,
     488,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,   194,   452,    -1,   680,   433,    -1,
      -1,    56,   202,    -1,    -1,    -1,    -1,    -1,   516,    -1,
      -1,   211,    -1,   448,   214,    -1,    -1,   452,    -1,    -1,
      -1,    -1,   433,    -1,    -1,   533,    -1,    -1,    -1,    -1,
      -1,   488,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,
      -1,   452,   355,    -1,    -1,    -1,    -1,    -1,   680,    -1,
      -1,    -1,    -1,   488,    -1,   433,    -1,   257,    -1,   516,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   252,    -1,
     448,    -1,    -1,    -1,   452,    -1,   533,   488,    -1,    -1,
      -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,   154,
     155,   156,   157,   158,   159,   516,   614,    -1,    -1,    -1,
     488,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
      -1,   321,   533,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   516,    -1,
      -1,    -1,    -1,   456,    -1,   345,    -1,    -1,    43,    44,
      -1,    -1,   352,    -1,   354,   533,    -1,   614,    -1,    -1,
      -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,    -1,    -1,
      -1,   355,   680,    -1,   487,    -1,    -1,   490,    -1,   614,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   502,
     503,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,    -1,    -1,   614,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    18,    19,
      20,    -1,    -1,   680,    24,    25,    26,    27,    -1,   542,
      -1,   126,    -1,    -1,    -1,    -1,   614,   437,    -1,    -1,
      -1,   554,    -1,    43,    44,   680,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,    -1,   314,
      -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,
      -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   595,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,   498,    -1,
      -1,    -1,   680,   487,    -1,    -1,   490,    -1,    -1,   509,
      -1,    -1,    43,    44,    -1,   628,    -1,    -1,   502,   503,
      -1,   634,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
     643,   644,    -1,   646,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   658,   659,   154,   155,   156,
     157,   158,   159,   666,    -1,    -1,   669,   252,   542,    -1,
      -1,    -1,    -1,    -1,   677,   172,   173,   174,    -1,    -1,
     554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,    -1,   126,    -1,   452,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   606,   607,   608,    -1,
      -1,   595,    -1,    -1,    -1,    18,    19,    20,    -1,   619,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,   488,    -1,    24,    25,    26,    27,    -1,
      43,    44,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,
     634,    -1,   252,    -1,    43,    44,    -1,    -1,    -1,   643,
     644,   516,   646,    -1,   664,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   658,   659,    -1,    -1,   533,    -1,
      -1,    -1,   666,    -1,    -1,   669,    -1,    -1,    18,    19,
      20,    -1,    -1,   677,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    18,    19,   311,    -1,    -1,   314,    24,    25,
      26,    27,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,   252,   722,   126,    18,    19,    -1,    43,    44,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,   126,   738,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,
      -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,    -1,    -1,   490,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   503,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   680,   433,    -1,    -1,    -1,
      -1,    -1,   126,    -1,    -1,   530,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,   452,    -1,   542,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,   554,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   488,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
     490,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
     595,    -1,    -1,   503,    -1,    -1,    -1,    -1,    -1,   516,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,    -1,    -1,   456,   533,    -1,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,   252,    -1,    -1,   634,
      -1,   541,   542,    -1,    -1,    32,    -1,    -1,   643,   644,
      -1,   646,    -1,    -1,   554,    -1,   487,    -1,   252,   490,
      -1,    -1,    49,   658,   659,    -1,    -1,    -1,    -1,    -1,
      -1,   666,   503,    -1,   669,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   677,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   595,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,
     541,   542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    -1,    -1,    -1,   634,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,   643,   644,    -1,   646,    -1,    -1,    -1,
      -1,    -1,    -1,   456,   141,   142,    -1,    -1,   658,   659,
      -1,    -1,    -1,    -1,   595,   152,   666,   456,    -1,   669,
      -1,    -1,    -1,   680,    -1,    -1,    -1,   677,    -1,    -1,
      -1,    -1,    -1,    -1,   487,    -1,    -1,   490,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,   487,    -1,
     503,   490,    -1,   634,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,   644,   503,   646,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,   456,   658,   659,    -1,
      -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,   669,   542,
     456,    -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,    -1,
      -1,   554,   541,   542,    -1,    -1,    -1,   487,    -1,    -1,
     490,    -1,   456,    -1,    -1,   554,    -1,    -1,    -1,    -1,
      -1,   487,    -1,   503,   490,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,
      -1,    -1,   595,   487,    -1,    -1,   490,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   595,    -1,    -1,   503,
      -1,    -1,   542,    -1,   530,    -1,    -1,    62,    63,    64,
      65,    66,    67,    -1,   554,   628,   542,    -1,    -1,    -1,
      -1,   634,    -1,    -1,    -1,   322,    -1,    -1,   554,    -1,
     643,   644,    -1,   646,    -1,   634,    -1,    -1,   542,    -1,
      -1,    -1,    -1,    -1,    -1,   658,   659,   646,    -1,    -1,
     554,    -1,    -1,   666,    -1,   595,   669,    -1,    -1,   658,
     659,    -1,    -1,   360,   677,    -1,    -1,   666,    -1,   595,
     669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   677,    -1,
      -1,    -1,   379,   380,   381,   382,    -1,    -1,   628,    -1,
      -1,   595,    -1,    -1,   634,    -1,    -1,    -1,    -1,    -1,
     397,    -1,    -1,   643,   644,   160,   646,    -1,   634,    -1,
      -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,   658,   659,
     646,    -1,   419,    -1,    -1,    -1,   666,    -1,    -1,   669,
     634,    -1,   658,   659,   431,    -1,    -1,   677,    -1,    -1,
     666,    -1,   646,   669,   487,   442,    -1,   490,    -1,    -1,
      -1,   677,    -1,    -1,   658,   659,    -1,    -1,    -1,    -1,
     503,   458,   666,    -1,    -1,   669,    -1,    -1,    -1,    -1,
      -1,   468,    -1,   677,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
      -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,
      -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   560,    -1,    -1,   321,    -1,    -1,    -1,
     567,    -1,    -1,   570,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,   634,    -1,    -1,   591,    -1,    -1,    -1,   595,   354,
      -1,    -1,    -1,   646,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   658,   659,   614,    -1,    -1,
      -1,    -1,    -1,   666,    -1,    -1,   669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   677,   632,    -1,   392,    -1,    -1,
     395,    -1,    -1,    -1,    -1,   400,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   548,   549,    -1,    -1,    -1,    -1,   554,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   586,    -1,    -1,   589,   590,    -1,    -1,    -1,   594,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   651,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   660,    -1,   662
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    48,   137,   298,   418,   466,   497,   526,
     736,   798,   806,   833,   834,   890,  1064,  1065,  1121,  1122,
    1123,  1125,  1126,  1127,  1132,  1134,  1147,  1148,  1149,  1150,
    1151,  1594,    28,    29,   807,   808,   809,   810,   811,    27,
    1028,  1609,  1028,  1028,    25,  1028,  1499,  1152,   835,  1499,
    1028,   834,     0,  1124,  1127,  1150,    31,   809,   811,   891,
     669,    25,   252,   832,   833,  1015,  1028,  1033,  1132,  1147,
    1153,  1184,  1185,  1186,  1187,  1188,  1192,   416,   837,   838,
     839,   840,   843,   844,   799,   115,   122,   169,   170,   429,
     524,   615,   695,   703,   806,   983,  1063,  1128,  1129,  1131,
    1135,  1136,  1142,  1154,  1308,  1318,  1594,   674,  1028,  1187,
     304,   517,   518,  1193,    20,  1028,  1191,   677,   838,     5,
     836,   416,  1028,     5,   863,   865,   866,   737,   802,  1028,
    1319,  1028,  1309,  1143,  1028,  1028,  1131,  1137,   322,   360,
     379,   380,   419,   431,   442,   458,   468,   483,   523,   545,
     560,   567,   570,   591,   595,   614,   632,   892,   893,   894,
     897,    25,  1184,  1190,    18,    19,    26,    47,   121,   133,
     161,   254,   350,   385,   419,   431,   467,   482,   490,   503,
     546,   571,   595,   639,   648,   732,   733,   747,   749,   950,
     957,   968,   970,  1028,  1184,  1194,  1195,   518,    14,   889,
     840,   580,  1295,   841,   838,   843,    32,    49,   125,   141,
     142,   152,   322,   360,   379,   380,   381,   382,   397,   419,
     431,   442,   458,   468,   483,   523,   545,   560,   567,   570,
     591,   595,   614,   632,   674,   847,   857,   868,   873,  1028,
     800,  1028,   490,  1028,   832,   984,  1155,  1028,   899,   380,
     845,   490,   875,   877,   878,   876,   885,   886,   490,   490,
     898,   518,   490,   838,   856,   485,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   747,   490,   829,
       9,    18,    19,    24,    25,    26,   126,   355,   449,   454,
     456,   472,   487,   490,   493,   502,   542,   554,   565,   595,
     646,   658,   659,   666,   677,   926,   934,   935,   936,   937,
     938,   968,   969,   971,  1034,  1184,  1298,  1492,   490,   490,
     490,   490,   490,   490,    18,    19,    20,    21,    22,   748,
      26,    36,   490,   579,     5,   486,  1194,    25,    26,  1028,
    1034,    19,    25,    26,   842,  1034,   727,   728,   729,   846,
     870,   859,   871,   845,   490,   490,   490,   860,   875,   876,
     490,   490,   858,   518,   869,   490,   856,   838,   867,   832,
     490,    26,   490,  1144,   832,   832,   490,  1028,   490,   517,
     851,    26,   683,   428,   513,   529,   571,   610,   639,   648,
     879,   683,   428,   513,   529,   571,   610,   639,   648,   887,
      26,    26,   900,   901,   902,   903,  1028,    26,   854,   855,
      26,   647,   669,   677,  1184,   724,   976,  1019,  1028,  1019,
    1019,   976,   976,   926,    24,    25,    26,    19,    24,    25,
      26,   677,   972,   973,   974,   975,    25,   977,  1019,  1020,
     926,   453,   926,   926,   926,   926,   584,  1315,   490,   490,
     926,   428,   513,   529,   571,   610,   639,   648,  1495,  1496,
     490,   926,   926,   490,   490,   939,   490,   490,   490,   490,
      26,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    56,   154,   155,
     156,   157,   158,   159,   172,   173,   174,   311,   314,   433,
     448,   452,   488,   516,   533,   614,   680,   828,   927,   940,
     942,   943,   944,   945,   946,   947,   948,   480,   960,   958,
     964,   962,  1184,  1184,   747,  1028,   951,  1028,  1195,   518,
     486,    26,   849,   490,   872,   856,   872,   851,    26,    26,
      26,   856,    26,    26,   837,   854,   872,    26,   677,   120,
     864,   801,  1320,   453,  1310,  1610,  1611,  1612,  1613,  1614,
     985,  1156,  1138,   677,    26,   453,   880,   881,   490,   882,
     887,   888,   882,   490,   883,     5,   453,     5,   453,     5,
     344,     5,   892,   486,     5,     5,   453,   838,   838,   838,
     874,   453,   490,     5,   453,   518,   677,   453,   453,   453,
     453,   453,   453,   453,    19,    26,   453,   647,   973,    19,
      26,   647,    26,   453,     5,   453,   453,     5,   830,   926,
     530,  1515,   926,   490,   683,    20,   453,  1515,    20,  1298,
     926,   926,   926,   926,   926,   926,   926,   926,   926,   926,
     926,   926,   926,   926,   926,   926,   926,   926,   926,   926,
     926,   926,   926,   490,   926,   926,   490,  1184,   926,   926,
     926,   926,   453,     5,   490,   541,   779,   780,   781,   926,
     490,  1194,   518,   681,    26,   677,    26,   453,   453,     5,
     453,   320,     5,   453,     5,   453,   344,   486,     5,   453,
     874,   803,   804,  1136,  1028,  1200,  1201,  1203,  1200,   423,
    1611,  1295,    39,    42,    50,    51,    52,    58,    61,    68,
      69,   113,   114,   118,   128,   129,   131,   145,   163,   166,
     167,   180,   182,   183,   184,   192,   193,   195,   196,   197,
     203,   206,   208,   209,   210,   216,   218,   219,   221,   223,
     224,   227,   230,   231,   232,   233,   234,   235,   239,   240,
     241,   243,   247,   249,   250,   255,   258,   261,   263,   265,
     267,   271,   272,   274,   275,   276,   279,   281,   282,   284,
     292,   293,   305,   308,   309,   312,   313,   316,   317,   324,
     325,   326,   328,   338,   339,   340,   342,   346,   347,   351,
     359,   367,   368,   369,   375,   376,   383,   386,   390,   391,
     401,   418,   426,   432,   443,   455,   461,   463,   464,   471,
     510,   521,   528,   551,   552,   556,   568,   574,   575,   576,
     577,   581,   585,   592,   593,   603,   605,   616,   618,   621,
     627,   653,   656,   661,   664,   665,   679,   686,   709,   710,
     711,   712,   713,   714,   715,   718,   720,   722,   740,   741,
     742,   743,   760,   784,   805,   806,   812,   831,   905,   906,
     907,   908,   919,   920,   921,   922,   923,   924,   925,   978,
    1009,  1013,  1035,  1037,  1040,  1041,  1042,  1043,  1056,  1066,
    1090,  1091,  1093,  1097,  1112,  1113,  1117,  1118,  1119,  1120,
    1130,  1145,  1161,  1172,  1173,  1174,  1178,  1181,  1215,  1218,
    1220,  1226,  1227,  1230,  1233,  1238,  1240,  1242,  1245,  1252,
    1257,  1258,  1260,  1263,  1264,  1265,  1277,  1278,  1281,  1287,
    1290,  1291,  1316,  1331,  1333,  1334,  1335,  1336,  1348,  1354,
    1355,  1375,  1378,  1407,  1409,  1500,  1501,  1532,  1533,  1540,
    1555,  1579,  1594,  1595,  1600,  1601,  1603,  1607,  1608,  1615,
     806,  1133,   682,   705,  1157,  1158,  1200,    20,   453,   485,
     852,   879,    26,   884,    26,    26,    26,   901,   903,   895,
     855,    26,   647,  1028,  1019,   747,    20,   724,  1028,   879,
     966,   966,    26,   453,   647,   966,    24,    26,    26,   647,
      24,    26,   876,   967,  1020,   877,   453,   421,   534,   643,
    1523,   453,   453,    26,  1496,   453,   453,   453,   453,   453,
     453,   453,   501,   501,   501,   949,  1515,   501,   949,  1515,
     961,   959,   965,   963,    26,   955,   952,     5,   953,   486,
    1194,   863,   453,    20,   852,    26,   490,    26,    26,   848,
      26,   735,   804,   677,   453,     5,   453,  1028,  1261,  1261,
    1184,  1184,  1184,  1028,    25,  1184,  1239,  1028,    25,  1028,
    1485,   412,  1029,  1030,  1609,  1029,    25,  1028,  1484,  1028,
    1261,  1023,  1029,  1023,  1028,  1605,  1485,  1028,    26,   744,
    1184,  1339,  1023,  1261,   949,    26,  1034,  1303,  1304,  1303,
     926,   933,  1377,  1484,  1484,   928,   949,  1029,  1541,  1541,
     909,  1261,  1023,  1337,  1184,  1025,  1029,   933,  1541,  1184,
    1261,  1184,  1376,  1541,    25,   643,  1175,  1176,  1184,  1023,
    1023,  1175,  1024,  1029,  1028,  1176,  1023,  1541,  1023,  1025,
    1485,  1184,  1213,  1214,  1021,  1029,  1025,   437,   619,  1019,
    1092,  1028,   813,  1484,  1026,  1029,    25,   252,  1028,  1408,
    1583,  1585,  1586,  1587,  1588,  1590,   949,  1213,   683,   949,
    1029,  1241,   979,    71,    72,    73,    74,   194,   202,   211,
     214,   257,   264,   321,   345,   352,   354,   364,   392,   400,
     437,   461,   498,   509,   606,   607,   608,   619,   664,   722,
     738,  1106,  1234,  1235,  1184,  1205,  1206,   932,   933,  1251,
     976,   976,  1022,  1029,   949,  1239,  1317,  1184,  1294,    25,
     490,  1184,  1289,  1535,  1288,   933,  1596,   168,   217,   254,
     350,   427,   467,   532,   761,   957,  1028,  1184,  1326,   786,
     933,  1021,   647,  1028,  1036,  1162,   933,  1022,    26,  1184,
    1114,  1021,   933,  1556,   933,  1303,  1028,  1038,  1039,  1025,
    1038,   976,  1025,  1038,   976,  1044,  1038,    25,    26,   446,
     545,  1034,  1095,  1184,  1202,  1204,   127,   335,   407,   451,
     626,   706,   707,   708,   717,   751,  1046,  1048,  1050,  1052,
    1054,  1179,  1180,  1183,   398,   409,   459,   473,   561,  1410,
     697,   698,   987,   988,   989,  1028,  1159,   704,  1158,   453,
     363,   453,   453,   453,   453,   681,     5,   453,   838,   453,
     486,   490,   683,    19,    26,   453,   966,    26,   453,   453,
     647,    26,   647,   683,    18,    19,    20,    25,    26,    43,
      44,   126,   456,   487,   490,   503,   542,   554,   595,   628,
     634,   643,   644,   646,   658,   659,   666,   669,  1028,  1034,
    1491,  1493,  1522,  1524,  1525,  1527,  1528,  1529,  1551,  1552,
    1553,  1554,  1584,  1585,  1589,  1315,   453,  1315,  1315,  1315,
    1315,  1315,  1315,    25,    25,    25,   926,   941,   453,    25,
     941,   453,   453,   453,   453,   453,   453,   779,   453,   781,
     779,   486,   363,   453,   838,   861,   862,   453,   453,   681,
     453,  1028,  1321,  1203,  1311,   683,   116,   117,   146,   147,
     148,   514,   599,   642,  1356,  1357,  1358,  1361,  1364,  1367,
    1368,  1369,  1372,   677,   647,   669,   164,   165,   490,   677,
     647,   669,     8,   682,   486,  1484,   537,  1262,  1202,   172,
     173,   174,   653,   541,   929,   930,   933,  1184,  1209,    40,
      41,  1484,   750,   751,   912,   327,    38,   149,   150,   151,
     683,   519,     5,   676,   683,   675,   675,  1216,   653,   480,
       5,   614,  1067,   519,   716,  1598,   716,   446,   815,  1184,
     604,   675,  1221,  1222,  1223,   677,    25,  1586,   518,  1591,
     389,  1406,   669,   677,   931,   933,   614,  1583,   931,     8,
     611,  1022,    26,   559,   612,   726,  1014,  1184,  1014,  1014,
    1014,    25,   239,   365,   371,   372,   373,   393,   498,   501,
     509,   543,   578,   597,   598,   608,   613,   652,   684,  1110,
    1111,  1014,  1014,   654,  1107,   751,  1107,  1107,  1015,  1015,
    1107,  1107,    45,    46,  1236,   751,    45,    46,  1237,     5,
     480,     5,   396,   447,     5,   750,   143,   144,   597,   684,
    1098,   719,  1599,   932,   670,   671,   672,   673,  1293,  1535,
    1295,   933,  1283,  1284,  1285,  1296,  1297,   933,   490,   490,
     490,   490,    25,   782,  1028,   490,  1535,   407,   490,   579,
      36,   647,   636,   787,   794,   785,  1028,    25,  1177,  1184,
    1279,     8,  1282,    14,  1028,  1189,  1196,  1197,  1199,  1207,
    1208,  1253,    45,    46,   225,   407,   602,   635,  1332,    33,
     252,   611,  1557,  1558,  1559,  1561,   633,     5,   716,   716,
     931,  1202,  1209,  1094,   480,     5,   213,  1072,   490,  1184,
     931,   490,    26,    26,   127,  1182,    25,  1184,  1539,  1539,
    1029,  1390,  1241,  1022,    37,   181,   283,   291,   297,   299,
     310,   337,   353,   358,   370,   377,   525,   530,   536,   558,
     563,  1379,  1380,  1388,  1397,  1398,  1404,  1405,  1411,  1412,
    1422,  1442,  1446,  1511,  1512,  1542,  1543,  1546,  1547,  1563,
     990,   991,   153,   986,   997,   998,   989,  1160,  1610,  1139,
     518,   892,   855,   677,  1028,   879,    26,   453,   647,   966,
     453,   647,   966,   966,    24,    26,   647,    24,    26,   880,
    1528,  1528,   428,   513,   529,   571,   610,   639,   648,  1494,
    1497,   530,  1527,   490,   490,   490,   490,  1522,  1522,  1522,
     490,   490,   490,   490,  1028,   490,     5,   604,  1451,  1456,
     674,  1028,    18,    19,    20,    21,   154,   155,   156,   157,
     158,   159,  1549,  1497,  1497,   480,     5,   453,   453,   956,
     954,   518,     5,   453,   863,   832,   832,  1239,   307,   320,
     421,   490,   534,   550,  1426,  1427,  1432,  1434,   490,  1028,
    1373,  1374,    26,   490,  1028,  1353,  1366,  1434,  1436,   490,
    1028,  1363,   490,  1353,  1359,     5,  1028,    25,  1028,  1028,
      25,  1031,  1187,  1028,    25,  1028,  1028,  1028,  1606,  1484,
     653,   490,   490,   912,  1484,     5,   683,  1239,   490,  1583,
      25,  1033,  1259,  1259,  1535,  1175,   933,   933,   933,  1016,
    1017,   490,  1184,  1214,  1068,  1069,  1070,  1484,   683,  1535,
     976,  1599,  1092,  1184,   814,   682,   933,   413,  1225,   614,
    1224,  1587,   747,  1592,  1593,  1028,    20,  1588,     5,  1580,
     674,  1231,   130,   132,   134,   675,   683,   904,  1202,  1205,
     980,    18,    19,   490,  1108,  1110,  1235,  1184,  1206,  1015,
     933,   407,   653,    26,  1184,    26,  1184,   750,   215,  1292,
     453,   445,  1330,  1295,  1285,     5,   675,  1286,  1597,  1028,
      25,   976,   976,   647,  1020,   680,  1184,   767,  1028,  1028,
    1028,   933,   402,   790,   794,   636,   788,   796,    23,   296,
    1164,  1168,   540,   949,   540,  1280,   933,   517,  1193,   677,
       5,  1115,   604,  1254,  1184,   225,   407,  1560,  1562,   251,
    1558,  1057,  1039,   976,   976,  1049,  1050,  1072,  1072,    53,
      54,    55,    57,    59,    60,   331,   334,   336,   356,   366,
     387,   410,   414,   489,  1071,  1073,  1074,  1102,  1184,  1204,
     604,   752,    26,   460,  1055,   384,  1534,  1534,   200,   201,
     496,   604,  1028,  1443,  1444,  1486,  1484,  1484,  1484,  1381,
    1484,  1484,  1028,  1544,   229,   441,   455,   498,   509,   530,
     536,   544,   566,   643,   649,  1413,  1415,  1416,  1417,  1523,
    1484,  1389,  1413,  1415,  1610,  1610,   446,   999,  1184,   699,
     700,   992,   993,   994,   539,   682,   701,   702,   721,  1002,
    1003,  1610,   832,    26,   853,    20,  1028,   453,    26,   453,
     966,    26,   966,    24,    26,   453,   453,    24,    26,   683,
    1523,   453,   456,  1527,  1550,  1589,   421,   534,   643,  1475,
    1527,  1530,  1475,  1475,  1475,  1475,   677,  1530,  1525,   573,
    1452,  1453,  1454,  1484,   584,  1450,  1457,   394,   572,   583,
    1399,  1518,  1028,  1527,  1527,  1527,  1527,   683,   490,   683,
    1584,   926,   453,   453,   853,   862,  1322,  1312,   674,   490,
     490,   490,  1370,  1434,   490,   490,   119,  1371,  1373,     5,
    1365,  1366,   125,   360,   380,   381,   382,   419,   431,   442,
     458,   468,   483,   531,   560,   570,   591,   595,   623,   632,
    1476,  1477,  1478,  1480,  1362,  1363,  1359,  1360,   721,  1357,
     677,   647,   453,   677,   647,   604,  1604,   490,   745,   746,
    1028,  1340,   949,   929,  1028,   674,  1338,   674,  1228,   683,
       5,     5,     5,   637,   933,     5,   677,   541,   683,   682,
     226,   228,   331,   334,   816,   819,   820,  1102,   817,   818,
    1028,   490,  1029,   706,   707,  1229,     5,   486,   933,  1484,
    1581,  1582,  1583,   634,   674,  1232,  1028,  1028,  1017,  1018,
     567,   976,   912,     8,     8,   982,    26,    26,  1109,  1110,
    1184,   380,  1246,   127,   926,  1295,   280,  1297,  1303,  1610,
       5,     5,   453,   453,   783,  1028,   453,  1535,   779,   490,
     490,   490,   795,   791,   422,   789,   933,   402,   792,   796,
     654,  1104,  1169,  1165,   424,  1163,  1164,   931,   683,  1190,
      20,  1028,  1198,  1208,    14,   541,  1255,  1256,  1527,  1184,
    1589,  1205,  1610,  1051,  1052,   608,  1027,   604,  1085,  1084,
    1083,  1082,  1087,  1086,  1019,  1088,  1019,  1089,  1081,  1080,
    1078,  1077,  1103,   387,  1074,  1079,   976,    62,    63,    64,
      65,    66,    67,   160,   395,   408,   470,   476,   515,   538,
     548,   549,   554,   564,   586,   589,   590,   594,   651,   662,
     753,   754,  1100,  1101,     5,    26,  1535,   310,  1184,   530,
    1516,  1517,  1535,  1241,  1510,  1512,   162,   162,   653,  1239,
    1445,  1446,   490,  1423,   212,  1457,  1484,   236,   332,  1548,
     677,   683,   490,  1418,  1418,   604,   682,     5,  1513,  1564,
     404,   413,   437,   440,   456,   559,   612,   619,  1022,  1391,
    1396,   683,   682,  1001,  1184,     5,   604,   995,   996,   696,
     994,  1000,  1028,  1000,  1004,  1005,  1000,   387,  1003,  1140,
     486,   453,   647,   966,   453,   647,   453,   453,   966,   966,
     428,   513,   529,   571,   610,   639,   648,  1498,  1524,     5,
    1497,     5,   453,     5,  1527,     5,   453,  1527,  1527,  1527,
    1527,  1028,   453,   490,  1454,     5,   674,  1028,  1490,     9,
     355,   490,   502,  1460,  1461,  1462,  1463,  1464,  1468,  1472,
    1474,  1527,   430,  1448,  1458,  1028,  1519,   676,  1475,   394,
    1498,    26,  1498,   486,   520,  1305,  1325,   520,  1266,  1299,
    1239,   669,  1028,  1429,  1431,  1484,  1488,  1489,  1433,  1488,
    1433,     5,   453,  1371,  1433,  1460,  1028,   453,  1374,     5,
     453,   490,   490,   490,  1497,  1497,   490,   490,   490,   490,
     490,   268,   269,   270,   460,  1435,  1437,     5,   453,     5,
     453,  1028,  1028,    25,  1028,  1028,    25,  1028,   933,  1028,
    1350,  1351,     5,  1352,  1353,   949,  1146,   677,  1239,  1352,
     634,  1535,  1535,   933,   933,  1016,   567,   933,  1602,     5,
    1069,    20,  1488,  1535,   817,   825,   824,   826,  1028,  1032,
     827,  1032,   253,   820,   823,     5,  1072,   677,   933,     8,
    1593,   518,   677,     5,  1535,   634,  1028,  1202,   949,   611,
    1394,     5,   453,  1184,     5,    26,  1184,   388,    25,  1327,
     407,   407,   518,   677,   407,   490,   768,   772,   765,   763,
    1610,  1610,   797,   793,   789,  1105,    25,  1027,  1170,  1184,
    1610,   933,   485,   518,   949,     5,  1058,  1053,  1054,    26,
     750,  1028,  1610,  1610,  1610,  1610,  1610,  1610,     5,  1075,
       5,  1076,  1610,  1610,  1610,  1610,  1108,  1610,  1027,    25,
      14,    14,     5,   453,    26,  1484,  1523,  1504,   653,   653,
    1380,  1509,  1510,  1446,  1424,  1488,   674,  1022,   490,  1384,
    1028,  1545,  1544,  1419,  1488,   522,  1420,  1421,  1486,  1484,
    1417,  1524,   107,   108,   109,   110,   111,   641,  1567,   933,
     933,   611,  1392,  1022,  1420,  1484,     5,  1184,  1000,  1610,
    1610,     5,  1007,  1008,  1610,  1610,  1006,  1133,   896,   966,
      26,   966,    24,    26,   966,   966,   490,  1456,  1497,   683,
    1497,  1497,   453,  1527,   453,   453,   453,   453,  1453,  1455,
    1453,  1490,  1463,  1522,  1460,  1527,  1522,     6,     7,     9,
      12,    13,    14,    15,    16,    17,   433,   434,   488,   614,
     680,   730,   731,  1471,  1473,  1449,  1526,  1527,   507,  1447,
    1459,   329,  1349,    26,  1400,  1401,  1402,  1488,  1516,  1519,
     453,   850,   135,   136,   138,   139,   140,   238,   246,   280,
     289,   318,   319,   362,   406,   460,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   694,  1302,  1306,   199,   572,
    1307,  1323,   222,   237,   238,   246,   280,   289,   318,   362,
     406,  1300,  1301,  1313,  1307,     8,  1489,   518,  1487,   453,
       5,   677,     5,   453,   453,  1434,   453,   453,  1366,    26,
    1481,  1481,    26,   683,   490,   683,    26,  1482,    26,    26,
    1482,  1482,    25,  1491,   220,   320,   357,   421,   435,   534,
     550,  1428,  1438,  1439,  1440,  1441,  1363,  1359,   677,   677,
     596,   645,     5,   453,   746,     5,   453,   931,   453,    20,
       8,   453,  1535,     5,   933,   624,   335,   755,   756,   933,
    1072,  1610,  1610,     5,   821,   518,   677,     5,   822,  1610,
     818,   604,    20,  1028,     5,  1028,  1219,  1592,    20,  1488,
    1582,     8,  1535,   451,   716,   931,  1395,   981,  1110,   725,
    1244,   926,     5,   779,  1184,   762,   744,  1028,  1184,   770,
     453,   779,   779,   779,  1610,  1610,  1108,  1167,    25,  1171,
    1184,   629,  1012,  1194,   541,   932,  1116,  1256,   124,   600,
    1059,  1045,  1046,   677,  1019,  1610,  1019,  1610,   750,    26,
    1184,    26,  1184,   754,   453,   490,  1536,  1524,  1510,  1510,
    1502,     5,   453,   530,  1521,  1385,  1488,   537,  1382,  1521,
     683,     5,   453,     5,   604,  1514,    18,    19,   126,   487,
     490,   503,   541,   542,   554,   595,   634,   646,   658,   659,
     666,   669,  1028,  1491,  1522,  1551,  1553,  1572,  1573,  1574,
    1575,  1576,  1577,  1589,  1572,  1572,  1572,  1488,  1569,  1571,
    1568,  1569,  1570,  1565,  1393,   683,  1184,  1028,  1610,  1610,
    1610,  1610,   681,   453,   647,   453,   453,    26,   453,   683,
    1498,   683,   683,     5,   453,   453,  1461,  1462,  1466,  1528,
    1466,   490,  1522,  1466,   490,  1522,  1466,    10,   311,   448,
     450,  1527,     5,  1460,     5,   596,   645,  1403,  1349,   683,
     681,  1303,  1303,  1303,    25,  1303,  1303,  1303,  1303,  1303,
    1303,    25,    25,  1303,  1306,  1184,  1210,  1211,   676,   506,
    1267,    25,    25,    26,    26,    26,    26,    26,    25,  1184,
    1301,  1267,  1239,    26,  1428,  1488,    20,  1028,  1488,  1371,
     453,   453,     5,   453,  1498,    26,  1498,     5,  1479,     5,
     453,   453,   453,  1479,  1430,  1484,   490,  1440,  1371,  1028,
    1028,  1351,   680,   734,  1345,  1346,  1347,  1353,    70,   147,
     148,   306,   680,  1341,  1342,  1343,   527,   911,  1239,  1341,
       5,   436,  1535,     5,   490,   453,   608,  1099,  1032,  1610,
     747,    20,  1028,  1032,  1610,   976,   933,   486,  1535,     8,
     976,  1205,  1610,    26,  1027,    25,  1328,  1202,   486,   779,
     769,   773,   453,   453,  1610,  1027,   933,  1010,   486,  1061,
    1060,   500,  1047,  1048,    20,  1028,  1537,  1538,   611,  1520,
    1505,  1503,  1488,  1523,   204,  1425,     5,   453,  1383,  1545,
    1488,  1421,  1420,  1520,  1575,  1575,  1574,   490,   490,   490,
     490,   490,   490,   490,  1028,   490,     5,   453,    18,    19,
      20,    21,  1549,   453,     5,   453,     5,    14,   212,   584,
    1566,  1205,  1420,   273,  1141,   892,   966,    24,    26,   966,
     966,   453,  1498,  1498,  1498,  1453,   501,  1465,  1465,  1469,
    1470,  1491,  1589,  1465,  1469,  1465,  1466,  1527,  1526,  1401,
    1498,   863,   596,   645,  1212,     5,  1210,   123,   198,   260,
     262,   278,   286,   290,   315,  1268,  1269,  1324,  1314,     5,
     486,  1487,    26,   453,    26,  1483,   453,    26,   453,   490,
    1460,  1344,  1609,    26,  1347,    26,    26,  1344,  1349,  1343,
    1019,   750,   436,  1535,   933,   757,   626,  1217,    26,   750,
     486,  1099,   453,  1535,   302,   750,   453,   453,   490,   771,
     407,   777,   453,   766,   764,  1166,  1610,   518,   933,  1610,
    1027,     5,   453,  1205,  1456,  1524,  1488,   490,  1456,   453,
    1550,  1475,  1574,  1578,  1475,  1475,  1475,  1475,   518,   677,
    1578,  1573,  1574,  1574,  1574,  1574,  1569,    14,  1570,  1573,
    1022,  1460,   205,   674,  1414,   453,   453,  1467,  1491,  1531,
       5,   453,   453,  1465,     7,  1211,  1270,  1271,  1184,  1273,
    1184,  1272,  1274,  1269,   301,   301,    26,   453,   683,   453,
    1431,   453,   910,  1535,   454,   264,   321,   345,   354,   392,
     400,   491,   660,   754,   758,   759,   490,   677,   750,  1243,
    1329,   774,   453,  1202,   777,   777,   777,  1610,  1011,  1194,
     633,  1096,  1538,  1518,  1456,   541,  1386,  1387,  1527,  1518,
     453,  1574,     5,   453,  1574,  1574,  1574,  1574,    26,  1028,
     453,   490,  1028,   966,   966,  1470,  1527,  1610,  1610,  1275,
    1610,  1276,  1610,  1610,   486,  1498,   453,   300,   410,   414,
     913,   914,   915,  1102,  1014,  1014,  1014,  1014,  1014,  1014,
      25,     5,   453,   933,    20,  1028,  1102,  1247,  1248,  1249,
     777,   779,   777,   303,   486,  1062,   750,     5,   453,   348,
     349,  1506,   453,  1574,   453,   453,   453,   453,     5,   486,
     518,  1572,  1610,  1610,   917,   916,   300,   915,   918,   759,
       5,  1250,   343,  1249,   775,  1610,  1387,    25,  1028,  1507,
    1508,    26,    26,   453,  1610,  1610,  1610,   933,  1610,   453,
    1059,   677,   677,     5,   486,     5,   486,   453,   776,  1028,
    1028,  1508,    26,   225,   407,   778,   677,   486,  1202,  1028
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
#line 1015 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1018 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1022 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1028 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1033 "fgl.yacc"
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
#line 1045 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1050 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	//sprintf($<str>$, "A4GL_unregister_func(\"%s\",%s%s);\n", $<str>1, (char *)get_namespace($<str>1), $<str>1);
	sprintf(yyval.str, "A4GL_unregister_func(\"%s\");\n", yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1069 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1070 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1071 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1072 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1073 "fgl.yacc"
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
#line 1084 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1090 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1091 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1092 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1093 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1094 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1099 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1100 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1111 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1114 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1117 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1117 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1124 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1125 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1139 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1140 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1141 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1142 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1143 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1144 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1145 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1146 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1147 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1154 "fgl.yacc"
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
#line 1165 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1169 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1170 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1174 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1180 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1182 "fgl.yacc"
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
#line 1193 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1195 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1197 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1199 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1203 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1205 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1266 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1270 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1274 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1281 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1284 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1288 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1292 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1301 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1307 "fgl.yacc"
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
#line 1316 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1321 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1327 "fgl.yacc"
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
#line 1336 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 77:
#line 1343 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 78:
#line 1348 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 79:
#line 1352 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 80:
#line 1360 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 81:
#line 1364 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1368 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1370 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1376 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 85:
#line 1381 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 86:
#line 1384 "fgl.yacc"
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
#line 1400 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 88:
#line 1407 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 89:
#line 1411 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 90:
#line 1415 "fgl.yacc"
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
#line 1437 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 92:
#line 1437 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 93:
#line 1441 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 94:
#line 1442 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 95:
#line 1443 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 96:
#line 1448 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 97:
#line 1451 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 98:
#line 1457 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 99:
#line 1460 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 101:
#line 1469 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 103:
#line 1473 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 104:
#line 1479 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 105:
#line 1482 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 106:
#line 1497 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 107:
#line 1507 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1513 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 109:
#line 1522 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 114:
#line 1535 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 116:
#line 1538 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 117:
#line 1540 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 119:
#line 1546 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 120:
#line 1548 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 121:
#line 1553 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 122:
#line 1558 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 123:
#line 1564 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 124:
#line 1568 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 125:
#line 1577 "fgl.yacc"
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
#line 1601 "fgl.yacc"
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
#line 1609 "fgl.yacc"
    { 
		pop_record();in_record--;
		read_class(yyvsp[-2].str); 
		print_variables(); 
		class_set_parent();
		}
    break;

  case 128:
#line 1615 "fgl.yacc"
    {
		class_cnt++; 
		CLASS_print_reflector();
		dump_class();
		}
    break;

  case 129:
#line 1625 "fgl.yacc"
    {
	static char buff[256];
		strcpy(buff,"default_object");
		CLASS_set_parent_name(buff);
		strcpy(yyval.str,buff);
	}
    break;

  case 130:
#line 1630 "fgl.yacc"
    {
		CLASS_set_parent_name(yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 134:
#line 1653 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 135:
#line 1656 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 136:
#line 1659 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 137:
#line 1662 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 138:
#line 1665 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 139:
#line 1668 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 145:
#line 1690 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 148:
#line 1699 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 149:
#line 1718 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 150:
#line 1723 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 151:
#line 1726 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 152:
#line 1735 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 153:
#line 1741 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 158:
#line 1756 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 159:
#line 1760 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 160:
#line 1765 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 163:
#line 1775 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 164:
#line 1775 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 165:
#line 1776 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 166:
#line 1776 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 167:
#line 1777 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 168:
#line 1777 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 169:
#line 1778 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 170:
#line 1778 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 171:
#line 1779 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 172:
#line 1779 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 173:
#line 1787 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 174:
#line 1791 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 175:
#line 1797 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 176:
#line 1801 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 177:
#line 1816 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 178:
#line 1819 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 179:
#line 1822 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 180:
#line 1825 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 181:
#line 1828 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 182:
#line 1831 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 183:
#line 1840 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 184:
#line 1848 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(0x%x);",22); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 185:
#line 1853 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(0x%x);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 186:
#line 1866 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 187:
#line 1870 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 188:
#line 1885 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 189:
#line 1886 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 192:
#line 1894 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 193:
#line 1894 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 198:
#line 1903 "fgl.yacc"
    {in_define=1;}
    break;

  case 199:
#line 1903 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 200:
#line 1912 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 201:
#line 1913 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 202:
#line 1914 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 203:
#line 1917 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 205:
#line 1922 "fgl.yacc"
    { }
    break;

  case 206:
#line 1922 "fgl.yacc"
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
#line 1939 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 211:
#line 1943 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 216:
#line 1958 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 217:
#line 1959 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 218:
#line 1960 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 219:
#line 1961 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 220:
#line 1966 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 222:
#line 1972 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 224:
#line 1981 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 225:
#line 1985 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 231:
#line 2001 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 232:
#line 2003 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 233:
#line 2004 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 236:
#line 2013 "fgl.yacc"
    {
		sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 237:
#line 2015 "fgl.yacc"
    {
		sprintf(yyval.str,"%s@%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 238:
#line 2020 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 239:
#line 2020 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 240:
#line 2021 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 241:
#line 2022 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 242:
#line 2025 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 243:
#line 2027 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 245:
#line 2037 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 250:
#line 2052 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 251:
#line 2052 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 255:
#line 2058 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 256:
#line 2059 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 257:
#line 2060 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 258:
#line 2061 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 259:
#line 2062 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 260:
#line 2063 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 261:
#line 2064 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 262:
#line 2065 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 263:
#line 2066 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 264:
#line 2067 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 265:
#line 2070 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 266:
#line 2071 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 267:
#line 2072 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 268:
#line 2073 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 269:
#line 2077 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 270:
#line 2082 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 271:
#line 2087 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 272:
#line 2091 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 273:
#line 2094 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 274:
#line 2098 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 276:
#line 2099 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 278:
#line 2100 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 280:
#line 2101 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 281:
#line 2102 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 282:
#line 2103 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 283:
#line 2104 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 284:
#line 2105 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 285:
#line 2106 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 286:
#line 2109 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 287:
#line 2110 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 288:
#line 2111 "fgl.yacc"
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
#line 2146 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 292:
#line 2151 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2153 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 294:
#line 2155 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 295:
#line 2160 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 296:
#line 2164 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 297:
#line 2164 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 298:
#line 2168 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 299:
#line 2169 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 300:
#line 2170 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 301:
#line 2171 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 302:
#line 2172 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 303:
#line 2173 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 304:
#line 2175 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 305:
#line 2180 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 306:
#line 2180 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 307:
#line 2183 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 308:
#line 2185 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 309:
#line 2191 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 310:
#line 2193 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 311:
#line 2199 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 312:
#line 2207 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 313:
#line 2207 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 314:
#line 2210 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 315:
#line 2211 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 316:
#line 2212 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 317:
#line 2213 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 318:
#line 2214 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 319:
#line 2215 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 320:
#line 2217 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 324:
#line 2238 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 328:
#line 2247 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 329:
#line 2249 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 330:
#line 2250 "fgl.yacc"
    { dim_push_type("varchar",yyvsp[-1].str,0); }
    break;

  case 331:
#line 2251 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 332:
#line 2255 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 333:
#line 2256 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 334:
#line 2257 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 335:
#line 2258 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 336:
#line 2263 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 337:
#line 2270 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 338:
#line 2275 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 339:
#line 2277 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 340:
#line 2279 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 341:
#line 2280 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 342:
#line 2281 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 343:
#line 2282 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 344:
#line 2283 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 345:
#line 2284 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 346:
#line 2285 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 347:
#line 2288 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 348:
#line 2290 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 349:
#line 2296 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 350:
#line 2304 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 352:
#line 2312 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 353:
#line 2316 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 354:
#line 2324 "fgl.yacc"
    {dim_push_record();}
    break;

  case 355:
#line 2325 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 356:
#line 2326 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 357:
#line 2327 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 363:
#line 2346 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 364:
#line 2358 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 365:
#line 2362 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 366:
#line 2365 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 367:
#line 2368 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 368:
#line 2369 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 369:
#line 2370 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 370:
#line 2371 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 371:
#line 2372 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 372:
#line 2378 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 373:
#line 2385 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 374:
#line 2390 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 375:
#line 2395 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 376:
#line 2400 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 377:
#line 2404 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 378:
#line 2413 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 379:
#line 2415 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 380:
#line 2420 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 386:
#line 2432 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 387:
#line 2436 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 388:
#line 2439 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 389:
#line 2443 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 390:
#line 2446 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 391:
#line 2450 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 392:
#line 2457 "fgl.yacc"
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
#line 2475 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 394:
#line 2481 "fgl.yacc"
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
#line 2505 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 396:
#line 2508 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 397:
#line 2523 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 398:
#line 2526 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 399:
#line 2540 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 400:
#line 2542 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 401:
#line 2544 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 402:
#line 2546 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 403:
#line 2548 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 404:
#line 2550 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 405:
#line 2551 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 406:
#line 2558 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 407:
#line 2560 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 408:
#line 2564 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 409:
#line 2566 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 410:
#line 2568 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 411:
#line 2570 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 412:
#line 2572 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 413:
#line 2574 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 414:
#line 2576 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 415:
#line 2582 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 419:
#line 2601 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 422:
#line 2607 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 423:
#line 2611 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 424:
#line 2616 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 428:
#line 2626 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 429:
#line 2627 "fgl.yacc"
    {inc_counter();}
    break;

  case 435:
#line 2633 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 436:
#line 2640 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 437:
#line 2640 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 439:
#line 2645 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 440:
#line 2649 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 441:
#line 2655 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 442:
#line 2663 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 443:
#line 2669 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 444:
#line 2678 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 445:
#line 2680 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 446:
#line 2687 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 447:
#line 2708 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2713 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 449:
#line 2718 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 450:
#line 2722 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 451:
#line 2724 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 452:
#line 2727 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 453:
#line 2745 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 454:
#line 2751 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2757 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 458:
#line 2767 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 459:
#line 2773 "fgl.yacc"
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
#line 2845 "fgl.yacc"
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
#line 2856 "fgl.yacc"
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
#line 2864 "fgl.yacc"
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
#line 2872 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 464:
#line 2872 "fgl.yacc"
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
#line 2888 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 466:
#line 2892 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 467:
#line 2898 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 468:
#line 2901 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 469:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 470:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 471:
#line 2916 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 472:
#line 2922 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 473:
#line 2932 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 474:
#line 2937 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 475:
#line 2944 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 476:
#line 2947 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 477:
#line 2950 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 478:
#line 2955 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 479:
#line 2962 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 480:
#line 2967 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 481:
#line 2972 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 482:
#line 2977 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 483:
#line 2988 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 484:
#line 2996 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 485:
#line 3004 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 486:
#line 3009 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 487:
#line 3013 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 488:
#line 3018 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 489:
#line 3022 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 490:
#line 3026 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 491:
#line 3032 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 492:
#line 3035 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 493:
#line 3039 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 494:
#line 3043 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 495:
#line 3047 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 496:
#line 3051 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 497:
#line 3055 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 498:
#line 3062 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 499:
#line 3072 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 500:
#line 3077 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 501:
#line 3083 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		A4GL_debug("Print expr (1)");

		strcpy(yyval.str,A4GL_expr_for_call(yyvsp[-5].str,yyvsp[-1].str,lastlineno,infilename));
		yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 502:
#line 3092 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 503:
#line 3097 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 504:
#line 3100 "fgl.yacc"
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
#line 3111 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 506:
#line 3116 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 507:
#line 3119 "fgl.yacc"
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
#line 3137 "fgl.yacc"
    {chk4var=1;}
    break;

  case 509:
#line 3137 "fgl.yacc"
    {chk4var=0;}
    break;

  case 510:
#line 3137 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 511:
#line 3140 "fgl.yacc"
    {chk4var=1;}
    break;

  case 512:
#line 3140 "fgl.yacc"
    {chk4var=0;}
    break;

  case 513:
#line 3140 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 514:
#line 3144 "fgl.yacc"
    {chk4var=1;}
    break;

  case 515:
#line 3144 "fgl.yacc"
    {chk4var=0;}
    break;

  case 516:
#line 3144 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 517:
#line 3148 "fgl.yacc"
    {chk4var=1;}
    break;

  case 518:
#line 3148 "fgl.yacc"
    {chk4var=0;}
    break;

  case 519:
#line 3148 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 520:
#line 3152 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3158 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3164 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3170 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3178 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3184 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 526:
#line 3192 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 527:
#line 3198 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 528:
#line 3207 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 529:
#line 3213 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 530:
#line 3220 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 531:
#line 3227 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 532:
#line 3236 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 533:
#line 3242 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 534:
#line 3248 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 535:
#line 3255 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 536:
#line 3261 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 537:
#line 3267 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 538:
#line 3273 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 539:
#line 3281 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 540:
#line 3287 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 541:
#line 3293 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 542:
#line 3302 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 543:
#line 3308 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 544:
#line 3314 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 545:
#line 3324 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 546:
#line 3325 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 549:
#line 3333 "fgl.yacc"
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
#line 3344 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 551:
#line 3345 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 552:
#line 3351 "fgl.yacc"
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
#line 3362 "fgl.yacc"
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
#line 3372 "fgl.yacc"
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
#line 3385 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 558:
#line 3390 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 559:
#line 3397 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 560:
#line 3401 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 561:
#line 3404 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 562:
#line 3407 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 563:
#line 3413 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 564:
#line 3416 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 565:
#line 3419 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 566:
#line 3436 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 567:
#line 3439 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 568:
#line 3445 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 569:
#line 3446 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 570:
#line 3447 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 572:
#line 3452 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 573:
#line 3453 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 574:
#line 3454 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 575:
#line 3455 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 576:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 577:
#line 3458 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 578:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 579:
#line 3461 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 580:
#line 3462 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 581:
#line 3463 "fgl.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 583:
#line 3469 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 584:
#line 3473 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 585:
#line 3477 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 586:
#line 3482 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 587:
#line 3486 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 588:
#line 3501 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 589:
#line 3505 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 590:
#line 3511 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 591:
#line 3515 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 592:
#line 3524 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 593:
#line 3525 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 594:
#line 3537 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 595:
#line 3543 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 596:
#line 3551 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 603:
#line 3568 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 604:
#line 3570 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 605:
#line 3573 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 606:
#line 3575 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 611:
#line 3589 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 612:
#line 3591 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 613:
#line 3594 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 614:
#line 3596 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 627:
#line 3627 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 628:
#line 3629 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 629:
#line 3632 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 630:
#line 3634 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 631:
#line 3637 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 632:
#line 3639 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 633:
#line 3642 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 634:
#line 3644 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 635:
#line 3647 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 636:
#line 3649 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 637:
#line 3663 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 638:
#line 3667 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 639:
#line 3668 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 640:
#line 3675 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 642:
#line 3693 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 643:
#line 3709 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 644:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 645:
#line 3711 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 646:
#line 3712 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 647:
#line 3713 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 648:
#line 3714 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 649:
#line 3715 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 653:
#line 3723 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 655:
#line 3729 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 656:
#line 3732 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 657:
#line 3737 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 658:
#line 3742 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 659:
#line 3745 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 660:
#line 3750 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 661:
#line 3755 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 662:
#line 3760 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 663:
#line 3767 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 664:
#line 3768 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 665:
#line 3775 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 666:
#line 3782 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 667:
#line 3784 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 668:
#line 3790 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 669:
#line 3795 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 670:
#line 3800 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 671:
#line 3805 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 672:
#line 3805 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 673:
#line 3808 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 674:
#line 3814 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 675:
#line 3819 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 676:
#line 3823 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 679:
#line 3831 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 680:
#line 3834 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 681:
#line 3837 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 682:
#line 3842 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 683:
#line 3847 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 684:
#line 3852 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 685:
#line 3859 "fgl.yacc"
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
#line 3870 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 688:
#line 3932 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 690:
#line 3941 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 691:
#line 3950 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 693:
#line 3957 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 694:
#line 3960 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 695:
#line 3966 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 696:
#line 3972 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 697:
#line 3976 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 698:
#line 3980 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 699:
#line 3986 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 700:
#line 3990 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 701:
#line 3994 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 702:
#line 3999 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 703:
#line 4004 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 722:
#line 4045 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 723:
#line 4052 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 724:
#line 4054 "fgl.yacc"
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
#line 4073 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 728:
#line 4076 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 729:
#line 4078 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 730:
#line 4081 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 731:
#line 4085 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 732:
#line 4088 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 733:
#line 4095 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 734:
#line 4100 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 735:
#line 4111 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 736:
#line 4112 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 737:
#line 4115 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 739:
#line 4121 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 740:
#line 4125 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 741:
#line 4126 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 742:
#line 4130 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 746:
#line 4145 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 747:
#line 4147 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 750:
#line 4156 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 751:
#line 4159 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 752:
#line 4163 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 753:
#line 4166 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 754:
#line 4169 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 755:
#line 4172 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 756:
#line 4175 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 757:
#line 4179 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 758:
#line 4182 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 759:
#line 4185 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 760:
#line 4188 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 761:
#line 4191 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 762:
#line 4194 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 763:
#line 4197 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 764:
#line 4200 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 765:
#line 4203 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 766:
#line 4204 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 767:
#line 4204 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 768:
#line 4205 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 769:
#line 4205 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 770:
#line 4206 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 771:
#line 4206 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 772:
#line 4207 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 773:
#line 4210 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 774:
#line 4211 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 775:
#line 4214 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 776:
#line 4222 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 777:
#line 4226 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 778:
#line 4232 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 779:
#line 4236 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 780:
#line 4241 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 781:
#line 4246 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 782:
#line 4251 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 783:
#line 4252 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 784:
#line 4253 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 785:
#line 4257 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 786:
#line 4261 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 787:
#line 4270 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 788:
#line 4275 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 789:
#line 4279 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 790:
#line 4286 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 791:
#line 4295 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 792:
#line 4301 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 793:
#line 4302 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 794:
#line 4303 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 795:
#line 4304 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 796:
#line 4305 "fgl.yacc"
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
#line 4315 "fgl.yacc"
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
#line 4329 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 800:
#line 4332 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 801:
#line 4339 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 802:
#line 4340 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 803:
#line 4341 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 804:
#line 4342 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 805:
#line 4343 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 806:
#line 4344 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 807:
#line 4345 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 808:
#line 4346 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 809:
#line 4347 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 810:
#line 4352 "fgl.yacc"
    {iskey=1;}
    break;

  case 811:
#line 4352 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 812:
#line 4354 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 813:
#line 4357 "fgl.yacc"
    {iskey=1;}
    break;

  case 814:
#line 4357 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 815:
#line 4359 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 816:
#line 4363 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 817:
#line 4366 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 818:
#line 4367 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 820:
#line 4370 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 826:
#line 4382 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 827:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 828:
#line 4384 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 829:
#line 4385 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 830:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 831:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 832:
#line 4388 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 833:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 834:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 835:
#line 4391 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 836:
#line 4392 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 837:
#line 4393 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 838:
#line 4394 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 839:
#line 4395 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 840:
#line 4399 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 841:
#line 4417 "fgl.yacc"
    {chk4var=1;}
    break;

  case 842:
#line 4417 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 843:
#line 4420 "fgl.yacc"
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
#line 4444 "fgl.yacc"
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
#line 4462 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 847:
#line 4468 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 848:
#line 4474 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 849:
#line 4480 "fgl.yacc"
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
#line 4492 "fgl.yacc"
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
#line 4523 "fgl.yacc"
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
#line 4540 "fgl.yacc"
    {
	}
    break;

  case 867:
#line 4566 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 871:
#line 4574 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 885:
#line 4598 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 886:
#line 4599 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 887:
#line 4607 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 888:
#line 4613 "fgl.yacc"
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
#line 4629 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 890:
#line 4635 "fgl.yacc"
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
#line 4650 "fgl.yacc"
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
#line 4663 "fgl.yacc"
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
#line 4674 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 895:
#line 4681 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 896:
#line 4688 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 897:
#line 4694 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 898:
#line 4694 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 899:
#line 4699 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 900:
#line 4705 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 901:
#line 4713 "fgl.yacc"
    {
}
    break;

  case 905:
#line 4725 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 907:
#line 4733 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 908:
#line 4739 "fgl.yacc"
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
#line 4759 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 912:
#line 4765 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 913:
#line 4769 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 916:
#line 4781 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 917:
#line 4784 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 918:
#line 4788 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 919:
#line 4791 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 920:
#line 4803 "fgl.yacc"
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
#line 4811 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 922:
#line 4817 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 923:
#line 4828 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 924:
#line 4832 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 925:
#line 4839 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 926:
#line 4846 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 927:
#line 4852 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 928:
#line 4857 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 931:
#line 4864 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 932:
#line 4865 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 933:
#line 4867 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 934:
#line 4868 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 935:
#line 4871 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 936:
#line 4872 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 937:
#line 4873 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 938:
#line 4875 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 939:
#line 4880 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 940:
#line 4885 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 941:
#line 4892 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 945:
#line 4899 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 946:
#line 4901 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 947:
#line 4903 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 949:
#line 4913 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 950:
#line 4916 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 951:
#line 4919 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 958:
#line 4935 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 959:
#line 4940 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 960:
#line 4940 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 961:
#line 4943 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 962:
#line 4971 "fgl.yacc"
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
#line 5028 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 966:
#line 5035 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 967:
#line 5039 "fgl.yacc"
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
#line 5082 "fgl.yacc"
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
#line 5130 "fgl.yacc"
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
#line 5144 "fgl.yacc"
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
#line 5168 "fgl.yacc"
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
#line 5232 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 980:
#line 5237 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 981:
#line 5245 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 982:
#line 5250 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 983:
#line 5258 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 984:
#line 5264 "fgl.yacc"
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
#line 5296 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 986:
#line 5299 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 987:
#line 5301 "fgl.yacc"
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
#line 5342 "fgl.yacc"
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
#line 5395 "fgl.yacc"
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
#line 5447 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 996:
#line 5456 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 997:
#line 5461 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 998:
#line 5472 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 999:
#line 5479 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1001:
#line 5487 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1002:
#line 5490 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 1003:
#line 5491 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1005:
#line 5493 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1006:
#line 5494 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 1007:
#line 5497 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 1008:
#line 5500 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1009:
#line 5506 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 1010:
#line 5509 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1011:
#line 5513 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 1012:
#line 5518 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1013:
#line 5526 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 1014:
#line 5531 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 1015:
#line 5538 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 1016:
#line 5540 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1021:
#line 5568 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1022:
#line 5575 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1023:
#line 5582 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1024:
#line 5585 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1025:
#line 5599 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1030:
#line 5616 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1031:
#line 5621 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1032:
#line 5627 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1034:
#line 5634 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1035:
#line 5639 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1036:
#line 5642 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1037:
#line 5643 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1038:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1039:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1040:
#line 5650 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1041:
#line 5651 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1042:
#line 5656 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1043:
#line 5663 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1044:
#line 5666 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1045:
#line 5672 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1046:
#line 5674 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1047:
#line 5676 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1048:
#line 5678 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1049:
#line 5681 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1050:
#line 5681 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1051:
#line 5682 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1052:
#line 5687 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1053:
#line 5695 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1054:
#line 5696 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1055:
#line 5701 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1056:
#line 5703 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1057:
#line 5705 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1061:
#line 5723 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1062:
#line 5724 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1063:
#line 5725 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1064:
#line 5726 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1065:
#line 5727 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1066:
#line 5728 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1067:
#line 5729 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1068:
#line 5730 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1069:
#line 5731 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1070:
#line 5732 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1071:
#line 5733 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1072:
#line 5734 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1073:
#line 5735 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1074:
#line 5736 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1075:
#line 5737 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1076:
#line 5738 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1077:
#line 5739 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1078:
#line 5740 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1079:
#line 5741 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1080:
#line 5742 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1081:
#line 5743 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1082:
#line 5744 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1083:
#line 5745 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1084:
#line 5746 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1085:
#line 5747 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1086:
#line 5748 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1087:
#line 5749 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1088:
#line 5750 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1089:
#line 5754 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1090:
#line 5755 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1091:
#line 5759 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1092:
#line 5760 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1093:
#line 5775 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1096:
#line 5784 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1097:
#line 5788 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1098:
#line 5792 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1099:
#line 5796 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1100:
#line 5800 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1102:
#line 5820 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1103:
#line 5825 "fgl.yacc"
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
#line 5838 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1105:
#line 5839 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1106:
#line 5843 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1107:
#line 5848 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1108:
#line 5849 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1109:
#line 5853 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1113:
#line 5859 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1114:
#line 5862 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1116:
#line 5877 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1117:
#line 5881 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1118:
#line 5887 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1119:
#line 5888 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1120:
#line 5893 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1121:
#line 5894 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1122:
#line 5897 "fgl.yacc"
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
#line 5924 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
			}
    break;

  case 1125:
#line 5928 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1126:
#line 5932 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1127:
#line 5936 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("S","\"\"",yyvsp[-1].str);
			}
    break;

  case 1128:
#line 5940 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("C","\"\"",yyvsp[-1].str);
			}
    break;

  case 1129:
#line 5944 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[0].str);
			}
    break;

  case 1130:
#line 5954 "fgl.yacc"
    {
			print_convert_report(yyvsp[-6].str, yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1131:
#line 5957 "fgl.yacc"
    {
			print_convert_report(yyvsp[-4].str, yyvsp[-2].str,yyvsp[0].str,"\"\"");
		}
    break;

  case 1134:
#line 5966 "fgl.yacc"
    {
		print_free_convertable(yyvsp[0].str);
}
    break;

  case 1138:
#line 5976 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1139:
#line 5982 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		print_free_convertable(yyvsp[0].str); // Shouldn't really be needed - but they may have started it "AS CONVERTABLE"
		}
    break;

  case 1140:
#line 5987 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[-1].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[-1].str);
		// Can't free convertable here - developer needs to do that using FREE REPORT
	}
    break;

  case 1141:
#line 5992 "fgl.yacc"
    {
		print_finish_report(yyvsp[-6].str);
		print_convert_report(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
		print_free_convertable(yyvsp[-6].str);
	}
    break;

  case 1142:
#line 5997 "fgl.yacc"
    {
		print_finish_report(yyvsp[-4].str);
		print_convert_report(yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str,"\"\"");
		print_free_convertable(yyvsp[-4].str);
	}
    break;

  case 1143:
#line 6006 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1144:
#line 6012 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1145:
#line 6014 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1149:
#line 6024 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1150:
#line 6024 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1151:
#line 6029 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1152:
#line 6033 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1153:
#line 6038 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1154:
#line 6038 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1155:
#line 6042 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1156:
#line 6042 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1157:
#line 6043 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1158:
#line 6043 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1159:
#line 6044 "fgl.yacc"
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

  case 1160:
#line 6057 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1161:
#line 6058 "fgl.yacc"
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

  case 1162:
#line 6074 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1169:
#line 6086 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1170:
#line 6086 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1171:
#line 6092 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1172:
#line 6092 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1173:
#line 6095 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1174:
#line 6095 "fgl.yacc"
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

  case 1175:
#line 6111 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1176:
#line 6112 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1177:
#line 6113 "fgl.yacc"
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

  case 1178:
#line 6122 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1179:
#line 6134 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1185:
#line 6145 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1186:
#line 6150 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1187:
#line 6150 "fgl.yacc"
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

  case 1189:
#line 6174 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1190:
#line 6180 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1191:
#line 6185 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1192:
#line 6191 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1193:
#line 6192 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1194:
#line 6193 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1195:
#line 6197 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1196:
#line 6198 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1197:
#line 6199 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1198:
#line 6200 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1199:
#line 6204 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1200:
#line 6214 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1201:
#line 6216 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1202:
#line 6221 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1203:
#line 6224 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1204:
#line 6229 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1205:
#line 6236 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1206:
#line 6243 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1207:
#line 6250 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1208:
#line 6259 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1209:
#line 6266 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1210:
#line 6273 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1211:
#line 6280 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1212:
#line 6287 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1217:
#line 6300 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1218:
#line 6301 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1219:
#line 6302 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1220:
#line 6303 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1221:
#line 6304 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1222:
#line 6305 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1223:
#line 6306 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1224:
#line 6307 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1225:
#line 6308 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1226:
#line 6309 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1229:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1230:
#line 6316 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1231:
#line 6317 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1232:
#line 6318 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1237:
#line 6327 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1238:
#line 6328 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1239:
#line 6329 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1240:
#line 6330 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1241:
#line 6331 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1242:
#line 6332 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1243:
#line 6333 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1244:
#line 6334 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1245:
#line 6336 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1246:
#line 6337 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1247:
#line 6338 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1248:
#line 6339 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1249:
#line 6341 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1250:
#line 6342 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1251:
#line 6343 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1252:
#line 6344 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1256:
#line 6349 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1257:
#line 6350 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1261:
#line 6357 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1262:
#line 6366 "fgl.yacc"
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

  case 1263:
#line 6375 "fgl.yacc"
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

  case 1264:
#line 6388 "fgl.yacc"
    { 
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1265:
#line 6399 "fgl.yacc"
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

  case 1266:
#line 6410 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1267:
#line 6414 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1268:
#line 6418 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1269:
#line 6424 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1270:
#line 6429 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1271:
#line 6437 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1272:
#line 6440 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1273:
#line 6449 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1274:
#line 6460 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1276:
#line 6467 "fgl.yacc"
    {
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1277:
#line 6477 "fgl.yacc"
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

  case 1278:
#line 6487 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1279:
#line 6490 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1280:
#line 6494 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1281:
#line 6502 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1282:
#line 6505 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1283:
#line 6511 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1284:
#line 6515 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1285:
#line 6519 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1286:
#line 6523 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1287:
#line 6527 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1288:
#line 6533 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1289:
#line 6534 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1290:
#line 6535 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1291:
#line 6536 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1292:
#line 6541 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1293:
#line 6542 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1294:
#line 6543 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1295:
#line 6544 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1296:
#line 6545 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1297:
#line 6546 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1298:
#line 6547 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1299:
#line 6548 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1300:
#line 6552 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1301:
#line 6553 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1302:
#line 6556 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1303:
#line 6561 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1304:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1305:
#line 6569 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1306:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1307:
#line 6575 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1308:
#line 6576 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1309:
#line 6582 "fgl.yacc"
    {insql=1;}
    break;

  case 1310:
#line 6582 "fgl.yacc"
    {insql=0;}
    break;

  case 1311:
#line 6582 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1312:
#line 6587 "fgl.yacc"
    {insql=1;}
    break;

  case 1313:
#line 6587 "fgl.yacc"
    {insql=0;}
    break;

  case 1314:
#line 6587 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1315:
#line 6595 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1316:
#line 6596 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1318:
#line 6601 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1319:
#line 6606 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1320:
#line 6607 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1321:
#line 6608 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1322:
#line 6609 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1323:
#line 6610 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1325:
#line 6615 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1326:
#line 6615 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1328:
#line 6619 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1329:
#line 6623 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1330:
#line 6624 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1331:
#line 6627 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1332:
#line 6628 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1333:
#line 6631 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1334:
#line 6634 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1335:
#line 6637 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1336:
#line 6643 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1337:
#line 6645 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1339:
#line 6658 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6662 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1341:
#line 6663 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1343:
#line 6668 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1344:
#line 6671 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1345:
#line 6677 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1346:
#line 6680 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1347:
#line 6688 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1349:
#line 6695 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1350:
#line 6699 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1351:
#line 6703 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1352:
#line 6709 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1353:
#line 6712 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1354:
#line 6721 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1355:
#line 6724 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1356:
#line 6727 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1357:
#line 6730 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1358:
#line 6733 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1359:
#line 6736 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1360:
#line 6739 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1361:
#line 6746 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1362:
#line 6749 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1363:
#line 6756 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1364:
#line 6759 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1365:
#line 6765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1366:
#line 6768 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1367:
#line 6775 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1368:
#line 6778 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1370:
#line 6786 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1372:
#line 6795 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1373:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1374:
#line 6804 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1375:
#line 6807 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1376:
#line 6813 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1377:
#line 6820 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1378:
#line 6821 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1379:
#line 6825 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1380:
#line 6835 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1381:
#line 6838 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1382:
#line 6844 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1383:
#line 6846 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1384:
#line 6851 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1385:
#line 6852 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6857 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1387:
#line 6858 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1388:
#line 6864 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1389:
#line 6865 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6892 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6898 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1400:
#line 6901 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1401:
#line 6904 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1402:
#line 6910 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1404:
#line 6916 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1406:
#line 6927 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1407:
#line 6941 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1408:
#line 6950 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1409:
#line 6950 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1410:
#line 6955 "fgl.yacc"
    {insql=1;}
    break;

  case 1411:
#line 6955 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1412:
#line 6960 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1413:
#line 6963 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1414:
#line 6965 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1416:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6976 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1418:
#line 6980 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1419:
#line 6987 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1420:
#line 6990 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1421:
#line 6997 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1422:
#line 7001 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1423:
#line 7007 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1424:
#line 7012 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1425:
#line 7016 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1426:
#line 7022 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1427:
#line 7025 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1428:
#line 7031 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1429:
#line 7038 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1430:
#line 7042 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1431:
#line 7047 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1432:
#line 7057 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1433:
#line 7060 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1434:
#line 7062 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1435:
#line 7064 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1436:
#line 7066 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1437:
#line 7068 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1438:
#line 7070 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_RELATIVE);}
    break;

  case 1439:
#line 7072 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_ABSOLUTE);}
    break;

  case 1440:
#line 7078 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1441:
#line 7088 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1442:
#line 7095 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1444:
#line 7101 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7104 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1448:
#line 7111 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1451:
#line 7116 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1452:
#line 7121 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1453:
#line 7128 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1454:
#line 7129 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1455:
#line 7137 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1456:
#line 7148 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1457:
#line 7149 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1458:
#line 7150 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1459:
#line 7153 "fgl.yacc"
    {insql=1;}
    break;

  case 1460:
#line 7153 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1461:
#line 7158 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1462:
#line 7163 "fgl.yacc"
    {
			print_exec_sql(convstrsql(yyvsp[0].str));
			printf("Warning: Informix specific SQL @ line %d\n",yylineno);
			strcpy(yyval.str,"InfxSpecificSql");
	}
    break;

  case 1463:
#line 7168 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1465:
#line 7174 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1467:
#line 7178 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1468:
#line 7183 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1469:
#line 7188 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1470:
#line 7192 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1472:
#line 7198 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1473:
#line 7202 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1474:
#line 7209 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1475:
#line 7210 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 7211 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7212 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 7222 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1482:
#line 7223 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1483:
#line 7224 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7228 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1485:
#line 7229 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1488:
#line 7236 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7239 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7242 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 7247 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1496:
#line 7249 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7255 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7261 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 7271 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1504:
#line 7276 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1505:
#line 7278 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 7284 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7287 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1510:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1511:
#line 7301 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7306 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 7316 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7322 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7327 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7330 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1520:
#line 7335 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7341 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 7346 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1524:
#line 7349 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1525:
#line 7352 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1526:
#line 7359 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1527:
#line 7360 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1528:
#line 7361 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1529:
#line 7363 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1530:
#line 7376 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1531:
#line 7381 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1533:
#line 7385 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1534:
#line 7387 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1535:
#line 7394 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1536:
#line 7397 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1537:
#line 7403 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1538:
#line 7411 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1539:
#line 7415 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1540:
#line 7419 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1541:
#line 7423 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1542:
#line 7428 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1543:
#line 7431 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1544:
#line 7434 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1545:
#line 7442 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1546:
#line 7449 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1549:
#line 7458 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1550:
#line 7464 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1551:
#line 7467 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1552:
#line 7478 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1553:
#line 7485 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1554:
#line 7491 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1555:
#line 7494 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1556:
#line 7501 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1557:
#line 7508 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1559:
#line 7515 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1560:
#line 7521 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1561:
#line 7522 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1562:
#line 7523 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1564:
#line 7527 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1565:
#line 7534 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1567:
#line 7541 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1568:
#line 7548 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1569:
#line 7553 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1570:
#line 7554 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1571:
#line 7557 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1572:
#line 7560 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1573:
#line 7565 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1574:
#line 7566 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1575:
#line 7571 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1576:
#line 7574 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1577:
#line 7580 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1578:
#line 7583 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1579:
#line 7589 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1580:
#line 7592 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1581:
#line 7598 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1582:
#line 7601 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1583:
#line 7608 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1584:
#line 7609 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1585:
#line 7638 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1586:
#line 7639 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7643 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1589:
#line 7656 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1590:
#line 7659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1591:
#line 7662 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1592:
#line 7665 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1594:
#line 7673 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1595:
#line 7676 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1597:
#line 7682 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1599:
#line 7688 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1600:
#line 7691 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1601:
#line 7694 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1602:
#line 7697 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1603:
#line 7700 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1604:
#line 7703 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1605:
#line 7706 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1606:
#line 7709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1607:
#line 7714 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1609:
#line 7721 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1613:
#line 7727 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1614:
#line 7728 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1615:
#line 7733 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1616:
#line 7736 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1617:
#line 7740 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7746 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1619:
#line 7747 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1620:
#line 7748 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1621:
#line 7749 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1626:
#line 7769 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1628:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1629:
#line 7774 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1631:
#line 7777 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1632:
#line 7778 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1633:
#line 7787 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1640:
#line 7801 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1641:
#line 7803 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1642:
#line 7805 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1644:
#line 7808 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1646:
#line 7811 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1650:
#line 7816 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1651:
#line 7818 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1652:
#line 7821 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1653:
#line 7822 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1654:
#line 7829 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1658:
#line 7834 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1662:
#line 7850 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1663:
#line 7857 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1664:
#line 7861 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1665:
#line 7862 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1666:
#line 7863 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1667:
#line 7871 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1668:
#line 7872 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1669:
#line 7873 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1670:
#line 7884 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1671:
#line 7891 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1672:
#line 7896 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1673:
#line 7897 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1674:
#line 7898 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1675:
#line 7906 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1676:
#line 7907 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1677:
#line 7908 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1679:
#line 7934 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1680:
#line 7935 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1681:
#line 7936 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1682:
#line 7940 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1683:
#line 7943 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1684:
#line 7949 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1685:
#line 7954 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1686:
#line 7959 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1688:
#line 7970 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1692:
#line 7988 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1693:
#line 7991 "fgl.yacc"
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

  case 1694:
#line 8004 "fgl.yacc"
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

  case 1695:
#line 8019 "fgl.yacc"
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

  case 1696:
#line 8031 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1697:
#line 8033 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1698:
#line 8036 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1699:
#line 8036 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1700:
#line 8036 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1701:
#line 8036 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1702:
#line 8036 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1703:
#line 8036 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1704:
#line 8037 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1705:
#line 8040 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1720:
#line 8058 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1721:
#line 8061 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1722:
#line 8062 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1723:
#line 8063 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1724:
#line 8067 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1725:
#line 8075 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1726:
#line 8075 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1727:
#line 8081 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1728:
#line 8081 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1729:
#line 8088 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1730:
#line 8088 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1731:
#line 8094 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1732:
#line 8094 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1733:
#line 8102 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1734:
#line 8103 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1735:
#line 8104 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1736:
#line 8107 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1737:
#line 8107 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1739:
#line 8111 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1740:
#line 8112 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1741:
#line 8123 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1742:
#line 8126 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1743:
#line 8132 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1744:
#line 8137 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1745:
#line 8145 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1746:
#line 8157 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1747:
#line 8158 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1748:
#line 8161 "fgl.yacc"
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

  case 1749:
#line 8176 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1750:
#line 8187 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1751:
#line 8190 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1752:
#line 8198 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1753:
#line 8207 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1754:
#line 8210 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1755:
#line 8214 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1756:
#line 8217 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1757:
#line 8218 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1759:
#line 8231 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1760:
#line 8232 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1761:
#line 8241 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1762:
#line 8250 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1763:
#line 8255 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1764:
#line 8256 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1765:
#line 8257 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1766:
#line 8258 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
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
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1769:
#line 8274 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1770:
#line 8277 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1771:
#line 8284 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1772:
#line 8296 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1773:
#line 8305 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1774:
#line 8308 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1775:
#line 8311 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1776:
#line 8317 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1777:
#line 8325 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1778:
#line 8328 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1779:
#line 8329 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1780:
#line 8330 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1781:
#line 8331 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1782:
#line 8332 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1783:
#line 8335 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1784:
#line 8342 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1785:
#line 8344 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1786:
#line 8346 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1787:
#line 8348 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1788:
#line 8350 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1789:
#line 8351 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1790:
#line 8352 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1791:
#line 8353 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1792:
#line 8354 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1793:
#line 8355 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1794:
#line 8356 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1795:
#line 8358 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1796:
#line 8360 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1797:
#line 8362 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1798:
#line 8364 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1799:
#line 8366 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1800:
#line 8368 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1801:
#line 8370 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1802:
#line 8371 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1803:
#line 8373 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1804:
#line 8374 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1805:
#line 8375 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1806:
#line 8381 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1807:
#line 8382 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1809:
#line 8392 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1810:
#line 8400 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1811:
#line 8404 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1812:
#line 8411 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1813:
#line 8411 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1815:
#line 8415 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1816:
#line 8420 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1817:
#line 8420 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1819:
#line 8424 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1820:
#line 8428 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1823:
#line 8437 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1824:
#line 8437 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1829:
#line 8456 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1830:
#line 8457 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1833:
#line 8465 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1834:
#line 8471 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1837:
#line 8490 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1838:
#line 8491 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1839:
#line 8492 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1840:
#line 8493 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1841:
#line 8494 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1842:
#line 8495 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1843:
#line 8499 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1844:
#line 8500 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1845:
#line 8501 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1847:
#line 8506 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1848:
#line 8507 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1849:
#line 8511 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1850:
#line 8527 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1851:
#line 8528 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1852:
#line 8529 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1853:
#line 8533 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1854:
#line 8547 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1855:
#line 8551 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1857:
#line 8560 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1859:
#line 8565 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1860:
#line 8566 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1861:
#line 8890 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1862:
#line 8890 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1863:
#line 8897 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1864:
#line 8897 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1865:
#line 8985 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1866:
#line 8989 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1867:
#line 8991 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1868:
#line 8998 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1869:
#line 9002 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1870:
#line 9008 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1871:
#line 9016 "fgl.yacc"
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

  case 1872:
#line 9026 "fgl.yacc"
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

  case 1873:
#line 9036 "fgl.yacc"
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

  case 1874:
#line 9048 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1875:
#line 9051 "fgl.yacc"
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

  case 1876:
#line 9070 "fgl.yacc"
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

  case 1877:
#line 9096 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1878:
#line 9099 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1880:
#line 9108 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1881:
#line 9113 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1882:
#line 9116 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1883:
#line 9124 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1884:
#line 9132 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1885:
#line 9145 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1886:
#line 9148 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1887:
#line 9156 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1888:
#line 9159 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1889:
#line 9162 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1890:
#line 9170 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1891:
#line 9174 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1892:
#line 9175 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1893:
#line 9176 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1894:
#line 9177 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1895:
#line 9178 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1896:
#line 9179 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1897:
#line 9180 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1898:
#line 9181 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1899:
#line 9185 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1900:
#line 9186 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1901:
#line 9187 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1902:
#line 9188 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1903:
#line 9189 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1904:
#line 9195 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1905:
#line 9196 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1906:
#line 9197 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1907:
#line 9198 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1908:
#line 9199 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1909:
#line 9200 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1910:
#line 9201 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1911:
#line 9202 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1912:
#line 9203 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1913:
#line 9204 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1914:
#line 9205 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1915:
#line 9206 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1916:
#line 9207 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1917:
#line 9208 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1918:
#line 9209 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1919:
#line 9210 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1920:
#line 9215 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1921:
#line 9221 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1922:
#line 9222 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1923:
#line 9230 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1924:
#line 9232 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1926:
#line 9238 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1927:
#line 9242 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1928:
#line 9246 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1929:
#line 9262 "fgl.yacc"
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

  case 1930:
#line 9276 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1931:
#line 9282 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1932:
#line 9284 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1936:
#line 9298 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1937:
#line 9301 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1938:
#line 9308 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1939:
#line 9311 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1940:
#line 9341 "fgl.yacc"
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

  case 1941:
#line 9366 "fgl.yacc"
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

  case 1942:
#line 9421 "fgl.yacc"
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

  case 1943:
#line 9456 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1944:
#line 9465 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1945:
#line 9476 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1946:
#line 9479 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1947:
#line 9485 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1948:
#line 9498 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1949:
#line 9512 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1950:
#line 9515 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1951:
#line 9519 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1952:
#line 9534 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1953:
#line 9534 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1954:
#line 9540 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1955:
#line 9541 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1956:
#line 9544 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1957:
#line 9545 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1958:
#line 9546 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1959:
#line 9547 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1960:
#line 9548 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1961:
#line 9549 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1962:
#line 9550 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1963:
#line 9561 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1964:
#line 9565 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1965:
#line 9569 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1966:
#line 9573 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1967:
#line 9578 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1968:
#line 9582 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1969:
#line 9587 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1971:
#line 9595 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1973:
#line 9601 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1974:
#line 9607 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1975:
#line 9611 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1980:
#line 9629 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1981:
#line 9636 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1982:
#line 9646 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1983:
#line 9646 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19085 "y.tab.c"

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


#line 1015 "fgl.yacc"

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



