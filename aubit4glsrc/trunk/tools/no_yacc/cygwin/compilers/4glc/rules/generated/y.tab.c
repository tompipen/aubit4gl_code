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
     COMMA = 1624,
     KW_OR = 1664,
     KW_AND = 1619,
     KW_USING = 1556,
     NOT = 1639,
     MATCHES = 1437,
     POWER = 1542,
     LESS_THAN = 1538,
     GREATER_THAN = 1454,
     EQUAL = 1614,
     GREATER_THAN_EQ = 1356,
     LESS_THAN_EQ = 1413,
     NOT_EQUAL = 1485,
     PLUS = 1650,
     MINUS = 1637,
     MULTIPLY = 1543,
     DIVIDE = 1570,
     MOD = 1638,
     COMMAND = 1420,
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
     DEFINE_NEW_TYPE = 1077,
     CREATE_DATABASE = 1078,
     DROP_DATABASE = 1079,
     IMPORT_LEGACY_FUNCTION = 1080,
     ADD_CONSTRAINT = 1081,
     DROP_CONSTRAINT = 1082,
     DROP_SYNONYM = 1083,
     CONSTRAINT = 1084,
     AS_STATIC = 1085,
     NOT_FIELD_TOUCHED = 1086,
     LOCAL_FUNCTION = 1087,
     EVERY_ROW = 1088,
     ELIF = 1089,
     DOUBLE_PRECISION = 1090,
     COUNT_MULTIPLY = 1091,
     WAIT_FOR_KEY = 1092,
     AT_TERMINATION_CALL = 1093,
     TERMINATE_REPORT = 1094,
     TO_MAIN_CAPTION = 1095,
     CLEARSTAT = 1096,
     TO_MENUITEM = 1097,
     ID_TO_INT = 1098,
     TO_STATUSBOX = 1099,
     ASCII_HEIGHT_ALL = 1100,
     ASCII_WIDTH_ALL = 1101,
     IMPORT_DATATYPE = 1102,
     PAGE_TRAILER_SIZE = 1103,
     PAGE_HEADER_SIZE = 1104,
     FIRST_PAGE_HEADER_SIZE = 1105,
     BYTES_USE_AS_IMAGE = 1106,
     BYTES_USE_AS_ASCII = 1107,
     KWUP_BY = 1108,
     KWDOWN_BY = 1109,
     CLOSE_STATUSBOX = 1110,
     MODIFY_NEXT_SIZE = 1111,
     LOCK_MODE_PAGE = 1112,
     LOCK_MODE_ROW = 1113,
     TO_PIPE = 1114,
     TO_SCREEN = 1115,
     TO_PRINTER = 1116,
     STATUSBOX = 1117,
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
     DELETE_FROM = 1262,
     END_DISPLAY = 1263,
     END_REPORT = 1264,
     END_FOREACH = 1265,
     END_FOR = 1266,
     END_GLOBALS = 1267,
     EXIT_PROMPT = 1268,
     EXTENT_SIZE = 1269,
     FOREIGN_KEY = 1270,
     HIDE_OPTION = 1271,
     HIDE_WINDOW = 1272,
     INSERT_INTO = 1273,
     IS_NOT_NULL = 1274,
     MOVE_WINDOW = 1275,
     NEXT_OPTION = 1276,
     NOT_MATCHES = 1277,
     ON_LAST_ROW = 1278,
     OPEN_WINDOW = 1279,
     OPEN_STATUSBOX = 1280,
     PAGE_LENGTH = 1281,
     PAGE_WIDTH = 1282,
     PRIMARY_KEY = 1283,
     PROMPT_LINE = 1284,
     RECORD_LIKE = 1285,
     ROLLFORWARD = 1286,
     SHOW_OPTION = 1287,
     SHOW_WINDOW = 1288,
     SQLSEON = 1289,
     TO_DATABASE = 1290,
     USE_SESSION = 1291,
     WITH_NO_LOG = 1292,
     AFTDISP = 1293,
     BEFFIELD = 1294,
     INSHARE = 1295,
     UNLOCKTAB = 1296,
     AFTFIELD = 1297,
     ATTRIBUTES = 1298,
     BEFINP = 1299,
     BEGIN_WORK = 1300,
     CLEARWIN = 1301,
     CLOSE_FORM = 1302,
     DEFER_QUIT = 1303,
     DESCENDING = 1304,
     DROP_INDEX = 1305,
     END_PROMPT = 1306,
     END_RECORD = 1307,
     ERROR_LINE = 1308,
     EXIT_INPUT = 1309,
     EXIT_WHILE = 1310,
     FOR_UPDATE_OF = 1311,
     FOR_UPDATE = 1312,
     GET_FLDBUF = 1313,
     INITIALIZE = 1314,
     INPUT_WRAP = 1315,
     LOCK_TABLE = 1316,
     MSG_LINE = 1317,
     NOT_EXISTS = 1318,
     ON_ANY_KEY = 1319,
     REFERENCES = 1320,
     RENCOL = 1321,
     SET_CURSOR = 1322,
     SMALLFLOAT = 1323,
     SQLSUCCESS = 1324,
     TOP_MARGIN = 1325,
     WITH_ARRAY = 1326,
     ACCEPTKEY = 1327,
     ACCEPT = 1328,
     AFTINP = 1329,
     CLEARFORMTODEFAULTS = 1330,
     CLEARFORM = 1331,
     CLEAR_X_FORM = 1332,
     COMMIT_W = 1333,
     NEXTPAGE = 1334,
     PREVPAGE = 1335,
     CTRL_KEY = 1336,
     INFTABS = 1337,
     NEXTFIELD = 1338,
     NEXTFORM = 1339,
     RENTAB = 1340,
     ASCENDING = 1341,
     ASSOCIATE = 1342,
     CHAR = 1343,
     NCHAR = 1344,
     NVARCHAR = 1345,
     CONSTRUCT = 1346,
     DELIMITER = 1347,
     DOWNSHIFT = 1348,
     DROP_VIEW = 1349,
     END_INPUT = 1350,
     END_WHILE = 1351,
     EXCLUSIVE = 1352,
     EXIT_CASE = 1353,
     EXIT_MENU = 1354,
     FORM_LINE = 1355,
     INTERRUPT = 1357,
     INTO_TEMP = 1358,
     INVISIBLE = 1359,
     IN_MEMORY = 1360,
     LINKED_TO = 1361,
     LOAD_FROM = 1362,
     LOCKTAB = 1363,
     MENU_LINE = 1364,
     OPEN_FORM = 1365,
     OTHERWISE = 1366,
     PRECISION = 1367,
     PRIOR = 1368,
     PROCEDURE = 1369,
     REPORT_TO = 1370,
     RETURNING = 1371,
     UNDERLINE = 1372,
     UNLOAD_TO = 1373,
     BEFROW = 1374,
     UNLOAD_T = 1375,
     VARIABLE = 1376,
     ABSOLUTE = 1377,
     AFTROW = 1378,
     BUFFERED = 1379,
     CONSTANT = 1380,
     CONST = 1381,
     DATABASE = 1382,
     DATETIME = 1383,
     DEFAULTS = 1384,
     DISTINCT = 1385,
     END_CASE = 1386,
     END_MAIN = 1387,
     END_MENU = 1388,
     END_TYPE = 1389,
     EXIT_FOR = 1390,
     EXTERNAL = 1391,
     FRACTION = 1392,
     FUNCTION = 1393,
     GROUP_BY = 1394,
     INTERVAL = 1395,
     KWMESSAGE = 1396,
     NOT_LIKE = 1397,
     NOT_ILIKE = 1398,
     NOT_NULL = 1399,
     PASSWORD = 1400,
     PREVIOUS = 1401,
     READONLY = 1402,
     REGISTER = 1403,
     RELATIVE = 1404,
     RESOURCE = 1405,
     SMALLINT = 1406,
     VALIDATE = 1407,
     WITH_LOG = 1408,
     WORDWRAP = 1409,
     BY_NAME = 1410,
     IN_FILE = 1411,
     IS_NULL = 1412,
     AVERAGE = 1414,
     BETWEEN = 1415,
     CAPTION = 1416,
     CLIPPED = 1417,
     CLOSE_BRACKET = 1418,
     COLUMNS = 1419,
     CONNECT = 1421,
     CURRENT = 1422,
     DBYNAME = 1423,
     DECIMAL = 1424,
     DECLARE = 1425,
     DEFAULT = 1426,
     DISPLAY = 1427,
     ENDCODE = 1428,
     EXECUTE = 1429,
     FOREACH = 1430,
     FOREIGN = 1431,
     GLOBALS = 1432,
     INFIELD = 1433,
     INTEGER = 1434,
     KWWINDOW = 1435,
     MAGENTA = 1436,
     OPTIONS = 1438,
     PERCENT = 1439,
     PREPARE = 1440,
     PROGRAM = 1441,
     RECOVER = 1442,
     REVERSE = 1443,
     SECTION = 1444,
     SESSION = 1445,
     SYNONYM = 1446,
     THRU = 1447,
     TRAILER = 1448,
     UPSHIFT = 1449,
     VARCHAR = 1450,
     WAITING = 1451,
     CLOSE_SHEV = 1452,
     CLOSE_SQUARE = 1453,
     KW_FALSE = 1455,
     NOT_IN = 1456,
     ONKEY = 1457,
     OPEN_BRACKET = 1458,
     BORDER = 1459,
     BOTTOM = 1460,
     COLUMN = 1461,
     COMMIT = 1462,
     CREATE = 1463,
     CURSOR = 1464,
     DEFINE = 1465,
     DELETE = 1466,
     DOUBLE = 1467,
     END_IF = 1468,
     ESCAPE = 1469,
     EXISTS = 1470,
     EXTEND = 1471,
     EXTENT = 1472,
     FINISH = 1473,
     FORMAT = 1474,
     HAVING = 1475,
     HEADER = 1476,
     INSERT = 1477,
     LOCATE = 1478,
     MARGIN = 1479,
     MEMORY = 1480,
     MINUTE = 1481,
     MODIFY = 1482,
     NORMAL = 1483,
     EQUAL_EQUAL = 1484,
     OPEN_SHEV = 1486,
     OPEN_SQUARE = 1487,
     OPTION = 1488,
     OUTPUT = 1489,
     PROMPT = 1490,
     PUBLIC = 1491,
     RECORD = 1492,
     REPORT = 1493,
     REVOKE = 1494,
     SCHEMA = 1495,
     SCROLL_USING = 1496,
     SCROLL = 1497,
     SECOND = 1498,
     SELECT = 1499,
     SERIAL = 1500,
     SHARED = 1501,
     SPACES = 1502,
     UNIQUE = 1503,
     UNLOCK = 1504,
     UPDATE = 1505,
     VALUES = 1506,
     YELLOW = 1507,
     AFTER = 1508,
     KWLINE = 1509,
     KW_NULL = 1510,
     KW_TRUE = 1511,
     SINGLE_KEY = 1512,
     ALTER = 1513,
     ARRAY = 1514,
     ASCII = 1515,
     AUDIT = 1516,
     BLACK = 1517,
     BLINK = 1518,
     CHECK = 1519,
     CLEAR = 1520,
     CLOSE = 1521,
     CODE_C = 1522,
     COUNT = 1523,
     DEFER = 1524,
     ERROR = 1525,
     EVERY = 1526,
     FETCH = 1527,
     FIRST = 1528,
     FLOAT = 1529,
     FLUSH = 1530,
     FOUND = 1531,
     GRANT = 1532,
     GREEN = 1533,
     GROUP = 1534,
     INDEX = 1535,
     KWFORM = 1536,
     LABEL = 1537,
     LOCAL = 1539,
     MONEY = 1540,
     MONTH = 1541,
     ORDER = 1544,
     OUTER = 1545,
     PAUSE = 1546,
     PRINT_IMAGE = 1547,
     PRINT_FILE = 1548,
     PRINT = 1549,
     RIGHT = 1550,
     DOUBLE_COLON = 1551,
     SEMICOLON = 1552,
     SLEEP = 1553,
     TUPLE = 1554,
     UNION = 1555,
     WHERE = 1557,
     WHILE = 1558,
     WHITE = 1559,
     CCODE = 1560,
     ANSI = 1561,
     BLUE = 1562,
     BOLD = 1563,
     BYTE = 1564,
     FCALL = 1565,
     CASE = 1566,
     CYAN = 1567,
     DATE = 1568,
     DESC = 1569,
     KWDOWN = 1571,
     TAB = 1572,
     DROP = 1573,
     ELSE = 1574,
     EXEC = 1575,
     EXIT = 1576,
     FREE = 1577,
     FROM = 1578,
     GOTO = 1579,
     HELP_FILE = 1580,
     LANG_FILE = 1581,
     HELP = 1582,
     HIDE = 1583,
     HOUR = 1584,
     INTO = 1585,
     LAST = 1586,
     LEFT = 1587,
     LIKE = 1588,
     MAIN = 1589,
     MENU = 1590,
     MODE = 1591,
     NEED = 1592,
     NEXT = 1593,
     NOCR = 1594,
     OPEN = 1595,
     QUIT = 1596,
     REAL = 1597,
     ROWS = 1598,
     SHOW = 1599,
     SIZE = 1600,
     SKIP = 1601,
     SOME = 1602,
     STEP = 1603,
     STOP = 1604,
     TEMP = 1605,
     TEXT = 1606,
     THEN = 1607,
     USER = 1608,
     WAIT = 1609,
     WHEN = 1610,
     WITH = 1611,
     WORK = 1612,
     YEAR = 1613,
     KW_IS = 1615,
     XSET = 1616,
     ADD = 1617,
     ALL = 1618,
     ANY = 1620,
     ASC = 1621,
     AVG = 1622,
     COLON = 1623,
     DAY = 1625,
     DBA = 1626,
     DEC = 1627,
     DIM = 1628,
     FKEY = 1629,
     FOR = 1630,
     KEY = 1631,
     KWNO = 1632,
     LET = 1633,
     LOG = 1634,
     XMAX = 1635,
     XMIN = 1636,
     PAD = 1640,
     PUT = 1641,
     RED = 1642,
     ROW = 1643,
     RUN = 1644,
     SQL = 1645,
     SUM = 1646,
     TOP = 1647,
     USE = 1648,
     ATSIGN = 1649,
     AS_TIFF = 1651,
     AS_GIF = 1652,
     AS_PNG = 1653,
     AS_JPEG = 1654,
     AS = 1655,
     AT = 1656,
     BY = 1657,
     DOT = 1658,
     GO = 1659,
     IF = 1660,
     IN = 1661,
     OF = 1662,
     ON = 1663,
     TO = 1665,
     KWUP = 1666,
     FONT_NAME = 1667,
     FONT_SIZE = 1668,
     PAPER_SIZE_IS_LETTER = 1669,
     PAPER_SIZE_IS_LEGAL = 1670,
     PAPER_SIZE_IS_A5 = 1671,
     PAPER_SIZE_IS_A4 = 1672,
     PAPER_SIZE_IS_LETTER_L = 1673,
     PAPER_SIZE_IS_LEGAL_L = 1674,
     PAPER_SIZE_IS_A5_L = 1675,
     PAPER_SIZE_IS_A4_L = 1676,
     FORMHANDLER = 1677,
     END_FORMHANDLER = 1678,
     BEFORE_EVENT = 1679,
     BEFORE_OPEN_FORM = 1680,
     AFTER_EVENT = 1681,
     BEFORE_CLOSE_FORM = 1682,
     BEFORE_ANY = 1683,
     AFTER_ANY = 1684,
     MENUHANDLER = 1685,
     END_MENUHANDLER = 1686,
     BEFORE_SHOW_MENU = 1687,
     DISABLE_PROGRAM = 1688,
     DISABLE_ALL = 1689,
     BUTTONS = 1690,
     CHECK_MENUITEM = 1691,
     DISABLE_FORM = 1692,
     DISABLE_MENUITEMS = 1693,
     DISABLE = 1694,
     ENABLE_FORM = 1695,
     ENABLE_MENUITEMS = 1696,
     ENABLE = 1697,
     KWFIELD = 1698,
     ICON = 1699,
     MESSAGEBOX = 1700,
     TO_DEFAULTS = 1701,
     UNCHECK_MENUITEM = 1702,
     BEFORE = 1703,
     INPUT = 1704,
     END = 1705,
     INT_TO_ID = 1706,
     TIMEOUT = 1707,
     OFF = 1708,
     WITH_1_DIMENSION = 1709,
     WITH_2_DIMENSION = 1710,
     WITH_3_DIMENSION = 1711,
     TILDE = 1712,
     ILIKE = 1713,
     FGL_ISDYNARR_ALLOCATED = 1714,
     FGL_DYNARR_EXTENTSIZE = 1715,
     FILLFACTOR = 1716,
     END_CLASS = 1717,
     KW_CLASS = 1718,
     EXTENDS = 1719,
     PIPE = 1720,
     FORMHANDLER_INPUT = 1721
   };
#endif
#define NAME 1723
#define UMINUS 1724
#define COMMA 1624
#define KW_OR 1664
#define KW_AND 1619
#define KW_USING 1556
#define NOT 1639
#define MATCHES 1437
#define POWER 1542
#define LESS_THAN 1538
#define GREATER_THAN 1454
#define EQUAL 1614
#define GREATER_THAN_EQ 1356
#define LESS_THAN_EQ 1413
#define NOT_EQUAL 1485
#define PLUS 1650
#define MINUS 1637
#define MULTIPLY 1543
#define DIVIDE 1570
#define MOD 1638
#define COMMAND 1420
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
#define DEFINE_NEW_TYPE 1077
#define CREATE_DATABASE 1078
#define DROP_DATABASE 1079
#define IMPORT_LEGACY_FUNCTION 1080
#define ADD_CONSTRAINT 1081
#define DROP_CONSTRAINT 1082
#define DROP_SYNONYM 1083
#define CONSTRAINT 1084
#define AS_STATIC 1085
#define NOT_FIELD_TOUCHED 1086
#define LOCAL_FUNCTION 1087
#define EVERY_ROW 1088
#define ELIF 1089
#define DOUBLE_PRECISION 1090
#define COUNT_MULTIPLY 1091
#define WAIT_FOR_KEY 1092
#define AT_TERMINATION_CALL 1093
#define TERMINATE_REPORT 1094
#define TO_MAIN_CAPTION 1095
#define CLEARSTAT 1096
#define TO_MENUITEM 1097
#define ID_TO_INT 1098
#define TO_STATUSBOX 1099
#define ASCII_HEIGHT_ALL 1100
#define ASCII_WIDTH_ALL 1101
#define IMPORT_DATATYPE 1102
#define PAGE_TRAILER_SIZE 1103
#define PAGE_HEADER_SIZE 1104
#define FIRST_PAGE_HEADER_SIZE 1105
#define BYTES_USE_AS_IMAGE 1106
#define BYTES_USE_AS_ASCII 1107
#define KWUP_BY 1108
#define KWDOWN_BY 1109
#define CLOSE_STATUSBOX 1110
#define MODIFY_NEXT_SIZE 1111
#define LOCK_MODE_PAGE 1112
#define LOCK_MODE_ROW 1113
#define TO_PIPE 1114
#define TO_SCREEN 1115
#define TO_PRINTER 1116
#define STATUSBOX 1117
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
#define DELETE_FROM 1262
#define END_DISPLAY 1263
#define END_REPORT 1264
#define END_FOREACH 1265
#define END_FOR 1266
#define END_GLOBALS 1267
#define EXIT_PROMPT 1268
#define EXTENT_SIZE 1269
#define FOREIGN_KEY 1270
#define HIDE_OPTION 1271
#define HIDE_WINDOW 1272
#define INSERT_INTO 1273
#define IS_NOT_NULL 1274
#define MOVE_WINDOW 1275
#define NEXT_OPTION 1276
#define NOT_MATCHES 1277
#define ON_LAST_ROW 1278
#define OPEN_WINDOW 1279
#define OPEN_STATUSBOX 1280
#define PAGE_LENGTH 1281
#define PAGE_WIDTH 1282
#define PRIMARY_KEY 1283
#define PROMPT_LINE 1284
#define RECORD_LIKE 1285
#define ROLLFORWARD 1286
#define SHOW_OPTION 1287
#define SHOW_WINDOW 1288
#define SQLSEON 1289
#define TO_DATABASE 1290
#define USE_SESSION 1291
#define WITH_NO_LOG 1292
#define AFTDISP 1293
#define BEFFIELD 1294
#define INSHARE 1295
#define UNLOCKTAB 1296
#define AFTFIELD 1297
#define ATTRIBUTES 1298
#define BEFINP 1299
#define BEGIN_WORK 1300
#define CLEARWIN 1301
#define CLOSE_FORM 1302
#define DEFER_QUIT 1303
#define DESCENDING 1304
#define DROP_INDEX 1305
#define END_PROMPT 1306
#define END_RECORD 1307
#define ERROR_LINE 1308
#define EXIT_INPUT 1309
#define EXIT_WHILE 1310
#define FOR_UPDATE_OF 1311
#define FOR_UPDATE 1312
#define GET_FLDBUF 1313
#define INITIALIZE 1314
#define INPUT_WRAP 1315
#define LOCK_TABLE 1316
#define MSG_LINE 1317
#define NOT_EXISTS 1318
#define ON_ANY_KEY 1319
#define REFERENCES 1320
#define RENCOL 1321
#define SET_CURSOR 1322
#define SMALLFLOAT 1323
#define SQLSUCCESS 1324
#define TOP_MARGIN 1325
#define WITH_ARRAY 1326
#define ACCEPTKEY 1327
#define ACCEPT 1328
#define AFTINP 1329
#define CLEARFORMTODEFAULTS 1330
#define CLEARFORM 1331
#define CLEAR_X_FORM 1332
#define COMMIT_W 1333
#define NEXTPAGE 1334
#define PREVPAGE 1335
#define CTRL_KEY 1336
#define INFTABS 1337
#define NEXTFIELD 1338
#define NEXTFORM 1339
#define RENTAB 1340
#define ASCENDING 1341
#define ASSOCIATE 1342
#define CHAR 1343
#define NCHAR 1344
#define NVARCHAR 1345
#define CONSTRUCT 1346
#define DELIMITER 1347
#define DOWNSHIFT 1348
#define DROP_VIEW 1349
#define END_INPUT 1350
#define END_WHILE 1351
#define EXCLUSIVE 1352
#define EXIT_CASE 1353
#define EXIT_MENU 1354
#define FORM_LINE 1355
#define INTERRUPT 1357
#define INTO_TEMP 1358
#define INVISIBLE 1359
#define IN_MEMORY 1360
#define LINKED_TO 1361
#define LOAD_FROM 1362
#define LOCKTAB 1363
#define MENU_LINE 1364
#define OPEN_FORM 1365
#define OTHERWISE 1366
#define PRECISION 1367
#define PRIOR 1368
#define PROCEDURE 1369
#define REPORT_TO 1370
#define RETURNING 1371
#define UNDERLINE 1372
#define UNLOAD_TO 1373
#define BEFROW 1374
#define UNLOAD_T 1375
#define VARIABLE 1376
#define ABSOLUTE 1377
#define AFTROW 1378
#define BUFFERED 1379
#define CONSTANT 1380
#define CONST 1381
#define DATABASE 1382
#define DATETIME 1383
#define DEFAULTS 1384
#define DISTINCT 1385
#define END_CASE 1386
#define END_MAIN 1387
#define END_MENU 1388
#define END_TYPE 1389
#define EXIT_FOR 1390
#define EXTERNAL 1391
#define FRACTION 1392
#define FUNCTION 1393
#define GROUP_BY 1394
#define INTERVAL 1395
#define KWMESSAGE 1396
#define NOT_LIKE 1397
#define NOT_ILIKE 1398
#define NOT_NULL 1399
#define PASSWORD 1400
#define PREVIOUS 1401
#define READONLY 1402
#define REGISTER 1403
#define RELATIVE 1404
#define RESOURCE 1405
#define SMALLINT 1406
#define VALIDATE 1407
#define WITH_LOG 1408
#define WORDWRAP 1409
#define BY_NAME 1410
#define IN_FILE 1411
#define IS_NULL 1412
#define AVERAGE 1414
#define BETWEEN 1415
#define CAPTION 1416
#define CLIPPED 1417
#define CLOSE_BRACKET 1418
#define COLUMNS 1419
#define CONNECT 1421
#define CURRENT 1422
#define DBYNAME 1423
#define DECIMAL 1424
#define DECLARE 1425
#define DEFAULT 1426
#define DISPLAY 1427
#define ENDCODE 1428
#define EXECUTE 1429
#define FOREACH 1430
#define FOREIGN 1431
#define GLOBALS 1432
#define INFIELD 1433
#define INTEGER 1434
#define KWWINDOW 1435
#define MAGENTA 1436
#define OPTIONS 1438
#define PERCENT 1439
#define PREPARE 1440
#define PROGRAM 1441
#define RECOVER 1442
#define REVERSE 1443
#define SECTION 1444
#define SESSION 1445
#define SYNONYM 1446
#define THRU 1447
#define TRAILER 1448
#define UPSHIFT 1449
#define VARCHAR 1450
#define WAITING 1451
#define CLOSE_SHEV 1452
#define CLOSE_SQUARE 1453
#define KW_FALSE 1455
#define NOT_IN 1456
#define ONKEY 1457
#define OPEN_BRACKET 1458
#define BORDER 1459
#define BOTTOM 1460
#define COLUMN 1461
#define COMMIT 1462
#define CREATE 1463
#define CURSOR 1464
#define DEFINE 1465
#define DELETE 1466
#define DOUBLE 1467
#define END_IF 1468
#define ESCAPE 1469
#define EXISTS 1470
#define EXTEND 1471
#define EXTENT 1472
#define FINISH 1473
#define FORMAT 1474
#define HAVING 1475
#define HEADER 1476
#define INSERT 1477
#define LOCATE 1478
#define MARGIN 1479
#define MEMORY 1480
#define MINUTE 1481
#define MODIFY 1482
#define NORMAL 1483
#define EQUAL_EQUAL 1484
#define OPEN_SHEV 1486
#define OPEN_SQUARE 1487
#define OPTION 1488
#define OUTPUT 1489
#define PROMPT 1490
#define PUBLIC 1491
#define RECORD 1492
#define REPORT 1493
#define REVOKE 1494
#define SCHEMA 1495
#define SCROLL_USING 1496
#define SCROLL 1497
#define SECOND 1498
#define SELECT 1499
#define SERIAL 1500
#define SHARED 1501
#define SPACES 1502
#define UNIQUE 1503
#define UNLOCK 1504
#define UPDATE 1505
#define VALUES 1506
#define YELLOW 1507
#define AFTER 1508
#define KWLINE 1509
#define KW_NULL 1510
#define KW_TRUE 1511
#define SINGLE_KEY 1512
#define ALTER 1513
#define ARRAY 1514
#define ASCII 1515
#define AUDIT 1516
#define BLACK 1517
#define BLINK 1518
#define CHECK 1519
#define CLEAR 1520
#define CLOSE 1521
#define CODE_C 1522
#define COUNT 1523
#define DEFER 1524
#define ERROR 1525
#define EVERY 1526
#define FETCH 1527
#define FIRST 1528
#define FLOAT 1529
#define FLUSH 1530
#define FOUND 1531
#define GRANT 1532
#define GREEN 1533
#define GROUP 1534
#define INDEX 1535
#define KWFORM 1536
#define LABEL 1537
#define LOCAL 1539
#define MONEY 1540
#define MONTH 1541
#define ORDER 1544
#define OUTER 1545
#define PAUSE 1546
#define PRINT_IMAGE 1547
#define PRINT_FILE 1548
#define PRINT 1549
#define RIGHT 1550
#define DOUBLE_COLON 1551
#define SEMICOLON 1552
#define SLEEP 1553
#define TUPLE 1554
#define UNION 1555
#define WHERE 1557
#define WHILE 1558
#define WHITE 1559
#define CCODE 1560
#define ANSI 1561
#define BLUE 1562
#define BOLD 1563
#define BYTE 1564
#define FCALL 1565
#define CASE 1566
#define CYAN 1567
#define DATE 1568
#define DESC 1569
#define KWDOWN 1571
#define TAB 1572
#define DROP 1573
#define ELSE 1574
#define EXEC 1575
#define EXIT 1576
#define FREE 1577
#define FROM 1578
#define GOTO 1579
#define HELP_FILE 1580
#define LANG_FILE 1581
#define HELP 1582
#define HIDE 1583
#define HOUR 1584
#define INTO 1585
#define LAST 1586
#define LEFT 1587
#define LIKE 1588
#define MAIN 1589
#define MENU 1590
#define MODE 1591
#define NEED 1592
#define NEXT 1593
#define NOCR 1594
#define OPEN 1595
#define QUIT 1596
#define REAL 1597
#define ROWS 1598
#define SHOW 1599
#define SIZE 1600
#define SKIP 1601
#define SOME 1602
#define STEP 1603
#define STOP 1604
#define TEMP 1605
#define TEXT 1606
#define THEN 1607
#define USER 1608
#define WAIT 1609
#define WHEN 1610
#define WITH 1611
#define WORK 1612
#define YEAR 1613
#define KW_IS 1615
#define XSET 1616
#define ADD 1617
#define ALL 1618
#define ANY 1620
#define ASC 1621
#define AVG 1622
#define COLON 1623
#define DAY 1625
#define DBA 1626
#define DEC 1627
#define DIM 1628
#define FKEY 1629
#define FOR 1630
#define KEY 1631
#define KWNO 1632
#define LET 1633
#define LOG 1634
#define XMAX 1635
#define XMIN 1636
#define PAD 1640
#define PUT 1641
#define RED 1642
#define ROW 1643
#define RUN 1644
#define SQL 1645
#define SUM 1646
#define TOP 1647
#define USE 1648
#define ATSIGN 1649
#define AS_TIFF 1651
#define AS_GIF 1652
#define AS_PNG 1653
#define AS_JPEG 1654
#define AS 1655
#define AT 1656
#define BY 1657
#define DOT 1658
#define GO 1659
#define IF 1660
#define IN 1661
#define OF 1662
#define ON 1663
#define TO 1665
#define KWUP 1666
#define FONT_NAME 1667
#define FONT_SIZE 1668
#define PAPER_SIZE_IS_LETTER 1669
#define PAPER_SIZE_IS_LEGAL 1670
#define PAPER_SIZE_IS_A5 1671
#define PAPER_SIZE_IS_A4 1672
#define PAPER_SIZE_IS_LETTER_L 1673
#define PAPER_SIZE_IS_LEGAL_L 1674
#define PAPER_SIZE_IS_A5_L 1675
#define PAPER_SIZE_IS_A4_L 1676
#define FORMHANDLER 1677
#define END_FORMHANDLER 1678
#define BEFORE_EVENT 1679
#define BEFORE_OPEN_FORM 1680
#define AFTER_EVENT 1681
#define BEFORE_CLOSE_FORM 1682
#define BEFORE_ANY 1683
#define AFTER_ANY 1684
#define MENUHANDLER 1685
#define END_MENUHANDLER 1686
#define BEFORE_SHOW_MENU 1687
#define DISABLE_PROGRAM 1688
#define DISABLE_ALL 1689
#define BUTTONS 1690
#define CHECK_MENUITEM 1691
#define DISABLE_FORM 1692
#define DISABLE_MENUITEMS 1693
#define DISABLE 1694
#define ENABLE_FORM 1695
#define ENABLE_MENUITEMS 1696
#define ENABLE 1697
#define KWFIELD 1698
#define ICON 1699
#define MESSAGEBOX 1700
#define TO_DEFAULTS 1701
#define UNCHECK_MENUITEM 1702
#define BEFORE 1703
#define INPUT 1704
#define END 1705
#define INT_TO_ID 1706
#define TIMEOUT 1707
#define OFF 1708
#define WITH_1_DIMENSION 1709
#define WITH_2_DIMENSION 1710
#define WITH_3_DIMENSION 1711
#define TILDE 1712
#define ILIKE 1713
#define FGL_ISDYNARR_ALLOCATED 1714
#define FGL_DYNARR_EXTENTSIZE 1715
#define FILLFACTOR 1716
#define END_CLASS 1717
#define KW_CLASS 1718
#define EXTENDS 1719
#define PIPE 1720
#define FORMHANDLER_INPUT 1721




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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9828

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  739
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  861
/* YYNRULES -- Number of rules. */
#define YYNRULES  2034
/* YYNRULES -- Number of states. */
#define YYNSTATES  3439

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
     386,   387,   388,   389,   390,   391,    15,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,    16,   448,   449,   450,   451,   452,   453,
      23,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,    10,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,    13,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,    17,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,    12,   568,
     569,   570,    11,    20,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,     8,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
      21,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,    14,   639,   640,   641,   642,     7,
     643,   644,   645,   646,     5,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,   658,    19,    22,     9,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
      18,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,     6,   682,   683,   684,   685,   686,
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
     374,   377,   379,   382,   384,   386,   388,   391,   394,   397,
     399,   402,   405,   409,   411,   413,   415,   418,   420,   422,
     425,   427,   428,   429,   435,   443,   452,   453,   456,   458,
     462,   464,   468,   472,   474,   477,   478,   483,   484,   489,
     490,   494,   495,   499,   500,   504,   506,   510,   512,   516,
     518,   520,   522,   524,   526,   528,   533,   534,   539,   541,
     543,   544,   546,   548,   551,   552,   553,   559,   560,   567,
     569,   573,   574,   577,   582,   587,   592,   597,   600,   604,
     606,   608,   610,   613,   615,   617,   621,   622,   624,   625,
     627,   629,   631,   632,   640,   641,   647,   648,   661,   663,
     665,   667,   669,   671,   677,   681,   683,   685,   687,   691,
     697,   698,   703,   704,   710,   711,   719,   721,   725,   727,
     729,   730,   732,   735,   737,   739,   741,   743,   748,   753,
     758,   765,   770,   777,   779,   781,   784,   786,   788,   790,
     792,   794,   799,   806,   808,   813,   820,   821,   825,   826,
     830,   831,   835,   837,   839,   841,   843,   845,   848,   851,
     853,   854,   858,   863,   865,   866,   870,   874,   875,   878,
     880,   882,   884,   886,   888,   890,   893,   894,   897,   898,
     902,   903,   907,   909,   910,   914,   916,   918,   920,   922,
     924,   926,   929,   931,   932,   934,   935,   938,   941,   943,
     946,   952,   957,   960,   965,   971,   975,   976,   977,   989,
     990,   993,   995,   996,   999,  1001,  1003,  1006,  1007,  1011,
    1012,  1016,  1017,  1021,  1024,  1027,  1030,  1035,  1041,  1043,
    1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,
    1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,  1084,
    1086,  1089,  1091,  1093,  1095,  1098,  1101,  1103,  1105,  1107,
    1109,  1111,  1113,  1115,  1117,  1119,  1121,  1124,  1126,  1129,
    1131,  1133,  1135,  1139,  1141,  1145,  1147,  1151,  1153,  1156,
    1158,  1160,  1164,  1169,  1174,  1176,  1178,  1180,  1182,  1184,
    1188,  1190,  1193,  1196,  1198,  1199,  1203,  1206,  1209,  1211,
    1215,  1220,  1225,  1231,  1237,  1239,  1241,  1244,  1247,  1252,
    1257,  1260,  1263,  1268,  1273,  1275,  1278,  1281,  1284,  1287,
    1290,  1293,  1296,  1299,  1302,  1305,  1308,  1311,  1314,  1317,
    1318,  1319,  1320,  1327,  1328,  1329,  1338,  1339,  1340,  1349,
    1350,  1351,  1358,  1359,  1360,  1367,  1368,  1369,  1376,  1377,
    1378,  1385,  1391,  1397,  1403,  1409,  1417,  1425,  1435,  1445,
    1452,  1461,  1472,  1483,  1491,  1501,  1510,  1521,  1534,  1549,
    1564,  1575,  1588,  1601,  1606,  1611,  1618,  1619,  1623,  1625,
    1627,  1632,  1637,  1642,  1647,  1652,  1657,  1659,  1661,  1663,
    1665,  1670,  1675,  1678,  1681,  1684,  1687,  1690,  1692,  1694,
    1697,  1699,  1701,  1703,  1706,  1711,  1718,  1725,  1729,  1735,
    1741,  1745,  1747,  1750,  1752,  1756,  1758,  1762,  1764,  1768,
    1769,  1770,  1771,  1781,  1782,  1786,  1787,  1788,  1799,  1800,
    1802,  1803,  1805,  1807,  1810,  1811,  1815,  1816,  1820,  1821,
    1823,  1825,  1828,  1829,  1833,  1834,  1838,  1842,  1844,  1849,
    1853,  1855,  1859,  1861,  1865,  1867,  1871,  1873,  1876,  1877,
    1881,  1882,  1886,  1887,  1892,  1893,  1898,  1899,  1904,  1905,
    1906,  1918,  1919,  1922,  1925,  1929,  1931,  1935,  1937,  1939,
    1941,  1943,  1945,  1947,  1949,  1953,  1955,  1957,  1962,  1969,
    1974,  1978,  1985,  1989,  1996,  1998,  2000,  2002,  2004,  2006,
    2008,  2010,  2012,  2013,  2016,  2018,  2020,  2022,  2027,  2029,
    2031,  2033,  2038,  2042,  2049,  2053,  2060,  2062,  2064,  2067,
    2070,  2072,  2075,  2078,  2080,  2084,  2086,  2089,  2092,  2095,
    2100,  2103,  2106,  2111,  2112,  2121,  2122,  2124,  2126,  2128,
    2129,  2131,  2134,  2135,  2137,  2140,  2141,  2143,  2146,  2147,
    2149,  2153,  2154,  2157,  2158,  2159,  2168,  2169,  2170,  2174,
    2175,  2176,  2184,  2190,  2193,  2196,  2199,  2200,  2206,  2211,
    2213,  2217,  2221,  2225,  2227,  2228,  2231,  2233,  2234,  2236,
    2238,  2241,  2242,  2247,  2248,  2253,  2254,  2258,  2259,  2263,
    2264,  2268,  2269,  2273,  2274,  2278,  2279,  2283,  2284,  2288,
    2289,  2293,  2294,  2298,  2299,  2303,  2304,  2308,  2310,  2314,
    2316,  2320,  2323,  2328,  2330,  2332,  2334,  2335,  2340,  2346,
    2353,  2354,  2365,  2369,  2372,  2375,  2377,  2379,  2382,  2385,
    2386,  2389,  2391,  2394,  2398,  2402,  2406,  2410,  2412,  2414,
    2416,  2418,  2419,  2423,  2425,  2426,  2430,  2433,  2436,  2438,
    2442,  2444,  2448,  2450,  2452,  2454,  2456,  2458,  2460,  2462,
    2464,  2466,  2468,  2470,  2472,  2474,  2476,  2478,  2480,  2482,
    2484,  2486,  2488,  2489,  2490,  2498,  2500,  2502,  2505,  2508,
    2511,  2515,  2520,  2522,  2524,  2526,  2527,  2531,  2532,  2534,
    2536,  2539,  2541,  2543,  2545,  2547,  2549,  2551,  2553,  2554,
    2556,  2558,  2561,  2564,  2566,  2568,  2570,  2572,  2574,  2576,
    2578,  2580,  2582,  2584,  2585,  2587,  2589,  2591,  2593,  2594,
    2595,  2596,  2597,  2611,  2613,  2614,  2615,  2622,  2625,  2627,
    2630,  2633,  2636,  2638,  2640,  2643,  2645,  2646,  2650,  2653,
    2655,  2657,  2659,  2660,  2661,  2669,  2671,  2674,  2675,  2679,
    2680,  2685,  2686,  2692,  2694,  2695,  2699,  2700,  2708,  2709,
    2715,  2717,  2720,  2721,  2723,  2725,  2727,  2728,  2730,  2732,
    2735,  2738,  2741,  2743,  2745,  2747,  2749,  2753,  2755,  2757,
    2760,  2761,  2764,  2766,  2768,  2770,  2772,  2774,  2776,  2778,
    2782,  2783,  2785,  2787,  2789,  2791,  2794,  2797,  2800,  2806,
    2815,  2817,  2819,  2821,  2826,  2831,  2833,  2835,  2837,  2839,
    2842,  2846,  2853,  2855,  2859,  2861,  2863,  2865,  2869,  2876,
    2886,  2888,  2890,  2892,  2894,  2897,  2898,  2900,  2902,  2906,
    2908,  2912,  2914,  2918,  2920,  2924,  2926,  2928,  2930,  2932,
    2936,  2938,  2942,  2944,  2948,  2950,  2952,  2954,  2958,  2961,
    2962,  2964,  2966,  2968,  2972,  2974,  2978,  2986,  2987,  2995,
    2996,  3003,  3007,  3009,  3013,  3015,  3018,  3024,  3025,  3033,
    3034,  3037,  3038,  3040,  3046,  3049,  3055,  3056,  3062,  3069,
    3074,  3075,  3077,  3079,  3085,  3086,  3089,  3090,  3096,  3101,
    3104,  3106,  3110,  3113,  3116,  3119,  3122,  3125,  3128,  3130,
    3133,  3136,  3139,  3142,  3145,  3148,  3151,  3153,  3155,  3157,
    3159,  3162,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3180,
    3183,  3185,  3187,  3189,  3191,  3197,  3199,  3201,  3204,  3209,
    3214,  3221,  3224,  3226,  3227,  3239,  3240,  3243,  3249,  3250,
    3252,  3253,  3256,  3258,  3261,  3262,  3266,  3268,  3269,  3274,
    3275,  3278,  3280,  3284,  3286,  3288,  3292,  3297,  3302,  3306,
    3310,  3313,  3322,  3329,  3331,  3333,  3336,  3338,  3339,  3341,
    3349,  3352,  3356,  3365,  3372,  3375,  3378,  3381,  3384,  3386,
    3389,  3390,  3394,  3395,  3399,  3400,  3404,  3405,  3409,  3410,
    3414,  3415,  3420,  3421,  3426,  3428,  3430,  3432,  3434,  3436,
    3438,  3439,  3444,  3445,  3447,  3448,  3453,  3455,  3458,  3461,
    3464,  3465,  3467,  3469,  3472,  3475,  3476,  3479,  3480,  3485,
    3487,  3491,  3495,  3501,  3502,  3505,  3510,  3512,  3514,  3516,
    3518,  3520,  3521,  3523,  3525,  3529,  3532,  3538,  3541,  3547,
    3553,  3559,  3565,  3571,  3577,  3578,  3581,  3583,  3586,  3589,
    3592,  3595,  3598,  3601,  3603,  3606,  3609,  3612,  3615,  3617,
    3620,  3623,  3626,  3629,  3631,  3633,  3635,  3636,  3639,  3642,
    3645,  3648,  3651,  3654,  3657,  3660,  3663,  3665,  3667,  3669,
    3671,  3673,  3675,  3677,  3679,  3682,  3685,  3688,  3691,  3694,
    3696,  3698,  3700,  3701,  3705,  3708,  3709,  3710,  3711,  3712,
    3713,  3714,  3730,  3731,  3734,  3737,  3738,  3740,  3741,  3742,
    3743,  3744,  3745,  3746,  3762,  3765,  3766,  3767,  3768,  3779,
    3780,  3782,  3786,  3790,  3793,  3797,  3802,  3806,  3812,  3817,
    3821,  3825,  3827,  3829,  3831,  3834,  3837,  3840,  3843,  3845,
    3847,  3848,  3849,  3858,  3859,  3860,  3870,  3871,  3873,  3875,
    3878,  3881,  3884,  3887,  3889,  3891,  3893,  3894,  3896,  3898,
    3901,  3904,  3907,  3916,  3919,  3922,  3927,  3930,  3931,  3933,
    3935,  3939,  3942,  3945,  3947,  3949,  3953,  3955,  3957,  3960,
    3962,  3966,  3970,  3974,  3976,  3980,  3982,  3984,  3986,  3988,
    3990,  3992,  3994,  3997,  4002,  4004,  4008,  4010,  4014,  4017,
    4022,  4024,  4028,  4030,  4033,  4038,  4040,  4044,  4046,  4048,
    4050,  4053,  4057,  4062,  4065,  4070,  4071,  4074,  4077,  4082,
    4084,  4088,  4090,  4092,  4094,  4097,  4099,  4101,  4103,  4105,
    4107,  4110,  4117,  4124,  4125,  4127,  4128,  4130,  4133,  4135,
    4136,  4142,  4143,  4149,  4151,  4152,  4156,  4158,  4162,  4164,
    4168,  4170,  4172,  4173,  4178,  4180,  4183,  4185,  4186,  4187,
    4191,  4192,  4193,  4197,  4199,  4201,  4203,  4205,  4207,  4209,
    4212,  4215,  4220,  4224,  4228,  4230,  4234,  4237,  4239,  4241,
    4242,  4244,  4246,  4248,  4250,  4251,  4253,  4257,  4259,  4263,
    4265,  4266,  4270,  4272,  4274,  4276,  4278,  4280,  4282,  4284,
    4286,  4288,  4290,  4292,  4294,  4296,  4304,  4311,  4316,  4321,
    4323,  4325,  4327,  4328,  4330,  4333,  4335,  4337,  4339,  4341,
    4345,  4348,  4350,  4352,  4355,  4357,  4359,  4360,  4364,  4366,
    4370,  4372,  4376,  4378,  4380,  4387,  4388,  4392,  4394,  4398,
    4399,  4401,  4406,  4412,  4415,  4417,  4419,  4424,  4426,  4430,
    4435,  4440,  4445,  4447,  4451,  4453,  4455,  4457,  4460,  4462,
    4464,  4466,  4471,  4472,  4474,  4475,  4477,  4479,  4482,  4485,
    4487,  4489,  4491,  4493,  4495,  4500,  4502,  4506,  4508,  4510,
    4512,  4515,  4517,  4519,  4522,  4525,  4527,  4531,  4534,  4537,
    4539,  4543,  4545,  4548,  4553,  4555,  4558,  4562,  4564,  4568,
    4573,  4574,  4576,  4577,  4579,  4580,  4582,  4584,  4588,  4590,
    4594,  4596,  4599,  4601,  4605,  4608,  4611,  4612,  4615,  4617,
    4619,  4625,  4629,  4635,  4639,  4641,  4645,  4647,  4649,  4650,
    4652,  4656,  4660,  4664,  4671,  4676,  4681,  4686,  4691,  4697,
    4699,  4701,  4703,  4705,  4707,  4709,  4711,  4713,  4715,  4717,
    4718,  4720,  4722,  4724,  4726,  4728,  4730,  4732,  4737,  4738,
    4740,  4745,  4747,  4753,  4759,  4761,  4763,  4765,  4767,  4769,
    4774,  4776,  4781,  4788,  4793,  4795,  4800,  4802,  4810,  4812,
    4814,  4816,  4821,  4828,  4829,  4832,  4837,  4839,  4841,  4843,
    4845,  4847,  4849,  4851,  4855,  4857,  4859,  4863,  4869,  4873,
    4879,  4887,  4891,  4893,  4895,  4899,  4905,  4909,  4915,  4923,
    4925,  4926,  4930,  4936,  4938,  4941,  4944,  4949,  4953,  4955,
    4957,  4959,  4961,  4963,  4966,  4969,  4970,  4974,  4975,  4979,
    4981,  4983,  4985,  4987,  4989,  4991,  4993,  4998,  5000,  5002,
    5004,  5006,  5008,  5010,  5012,  5014,  5016,  5018,  5020,  5022,
    5024,  5026,  5031,  5033,  5037,  5039,  5043,  5044,  5052,  5053,
    5062,  5063,  5070,  5071,  5080,  5081,  5083,  5086,  5088,  5092,
    5094,  5098,  5104,  5106,  5108,  5110,  5112,  5114,  5115,  5116,
    5126,  5132,  5134,  5136,  5143,  5144,  5148,  5150,  5154,  5159,
    5161,  5162,  5165,  5170,  5177,  5178,  5180,  5182,  5184,  5186,
    5190,  5192,  5195,  5199,  5201,  5203,  5206,  5209,  5211,  5213,
    5215,  5218,  5221,  5224,  5227,  5232,  5236,  5239,  5243,  5247,
    5251,  5253,  5255,  5257,  5259,  5261,  5263,  5269,  5275,  5281,
    5287,  5293,  5298,  5303,  5307,  5312,  5314,  5316,  5318,  5322,
    5324,  5330,  5338,  5344,  5345,  5348,  5350,  5352,  5353,  5357,
    5359,  5363,  5365,  5367,  5369,  5370,  5374,  5376,  5378,  5380,
    5382,  5387,  5394,  5396,  5398,  5401,  5405,  5407,  5409,  5411,
    5413,  5415,  5417,  5419,  5421,  5427,  5433,  5438,  5444,  5446,
    5451,  5453,  5455,  5463,  5468,  5470,  5471,  5476,  5478,  5481,
    5483,  5485,  5487,  5488,  5492,  5493,  5497,  5498,  5499,  5506,
    5507,  5510,  5513,  5521,  5525,  5529,  5532,  5535,  5538,  5540,
    5544,  5546,  5550,  5552,  5556,  5558,  5562,  5564,  5566,  5568,
    5571,  5574,  5576,  5578,  5581,  5586,  5592,  5600,  5608,  5618,
    5620,  5622,  5624,  5626,  5628,  5630,  5634,  5637,  5641,  5645,
    5649,  5655,  5661,  5667,  5673,  5679,  5684,  5689,  5693,  5698,
    5700,  5702,  5704,  5706,  5710,  5711,  5717,  5719,  5723,  5727,
    5731,  5733,  5735,  5738,  5740,  5742,  5746,  5748,  5752,  5756,
    5758,  5760,  5762,  5766,  5769,  5773,  5780,  5782,  5786,  5788,
    5790,  5791,  5792,  5799,  5800,  5803,  5804,  5806,  5808,  5811,
    5814,  5816,  5818,  5823,  5827,  5829,  5832,  5838,  5841,  5844,
    5850,  5851,  5854,  5856,  5858,  5861,  5868,  5875,  5877,  5878,
    5880,  5883,  5885,  5888,  5889,  5892,  5894,  5896,  5898,  5900,
    5902,  5904,  5906,  5908,  5910,  5912,  5914,  5916,  5918,  5920,
    5922,  5924,  5926,  5928,  5930,  5932,  5934,  5936,  5938,  5940,
    5942,  5944,  5946,  5948,  5950,  5952,  5954,  5956,  5958,  5960,
    5962,  5964,  5966,  5968,  5970,  5972,  5974,  5976,  5978,  5980,
    5982,  5984,  5986,  5988,  5990,  5992,  5994,  5996,  5998,  6000,
    6002,  6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,
    6022,  6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,
    6042,  6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,
    6062,  6064,  6066,  6068,  6070
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1105,     0,    -1,   261,    -1,   258,    -1,   192,   744,   485,
     652,   745,    -1,   203,    -1,  1168,    -1,    26,    -1,   746,
      -1,   745,     5,   746,    -1,  1012,    -1,   489,   747,   452,
      -1,   747,   748,   747,    -1,    26,    -1,   749,    26,    -1,
    1168,    -1,   952,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   751,
      -1,    -1,   334,   489,   752,   753,   452,    -1,   625,   489,
      26,     5,    26,   452,    -1,   754,    -1,   753,     5,   754,
      -1,   547,    -1,   588,    -1,   593,    -1,   563,    -1,   469,
      -1,   661,    -1,   585,    -1,   537,    -1,   475,    -1,   548,
      -1,   407,    -1,   589,    -1,   514,    -1,   394,    -1,   650,
      -1,   160,    -1,  1084,    -1,    -1,   756,    -1,    -1,   334,
     489,   757,   758,   452,    -1,   759,    -1,   758,     5,   759,
      -1,   754,    -1,   490,    -1,   659,    25,    -1,   264,   998,
      -1,   391,   998,    -1,   344,   998,    -1,   399,   998,    -1,
     353,   998,    -1,   320,   998,    -1,   591,   761,    -1,   941,
     406,  1168,    -1,    -1,   349,   489,   960,   452,   406,   762,
    1186,    -1,   168,   489,  1012,     5,    25,     5,    25,   452,
      -1,   466,   489,  1004,   452,   406,  1168,    -1,  1310,    -1,
     254,   489,   960,   452,   406,  1168,    -1,    -1,    -1,  1168,
     646,  1012,   489,   763,   779,   452,   764,   777,    -1,    -1,
      -1,  1168,    36,  1012,   489,   765,   779,   452,   766,   777,
      -1,    -1,    -1,    -1,  1012,   489,   767,   779,   768,   452,
     769,   777,    -1,    -1,    -1,   531,  1519,   679,  1519,   489,
     770,   779,   771,   452,   777,    -1,    -1,    -1,  1012,   578,
    1012,   489,   772,   779,   773,   452,   777,    -1,    -1,    -1,
      -1,   426,   782,   646,   783,   517,   744,   485,   489,   774,
     779,   775,   452,   776,   778,    -1,    -1,   406,  1186,    -1,
      -1,   406,  1186,    -1,   225,    -1,    -1,   780,    -1,   781,
      -1,   780,     5,   781,    -1,   910,    -1,   540,    -1,    25,
      -1,  1012,    -1,  1012,    -1,  1012,   676,  1012,    -1,    -1,
     592,   917,   785,   788,   792,   789,    -1,    -1,   592,   786,
     787,   790,   789,    -1,   794,    -1,   787,   794,    -1,   796,
      -1,   788,   796,    -1,   421,    -1,    -1,    -1,   401,   791,
    1594,    -1,    -1,    -1,   401,   793,  1594,    -1,    -1,   635,
     917,   795,  1594,    -1,    -1,   635,   917,   797,  1594,    -1,
      -1,    -1,    -1,   735,  1012,   799,   802,   800,   832,   801,
     803,   734,    -1,    -1,   736,  1012,    -1,   804,    -1,   803,
     804,    -1,  1120,    -1,  1116,    -1,  1578,    -1,   338,  1009,
      -1,   263,  1007,    -1,   146,  1007,    -1,   230,    -1,   247,
    1525,    -1,   551,  1006,    -1,    30,   807,    31,    -1,   808,
      -1,   810,    -1,   809,    -1,   808,   809,    -1,    29,    -1,
     811,    -1,   810,   811,    -1,    28,    -1,    -1,    -1,   382,
     813,   815,   814,   816,    -1,   445,  1168,   681,   817,  1056,
    1083,   750,    -1,  1168,   681,   817,  1056,   603,   960,  1083,
     750,    -1,    -1,   819,   253,    -1,   818,    -1,   817,     5,
     818,    -1,  1012,    -1,  1012,   676,  1012,    -1,  1012,   676,
      20,    -1,   820,    -1,   819,   820,    -1,    -1,   330,   826,
     821,  1594,    -1,    -1,   333,   827,   822,  1594,    -1,    -1,
    1086,   823,  1594,    -1,    -1,   228,   824,  1594,    -1,    -1,
     226,   825,  1594,    -1,  1016,    -1,   826,     5,  1016,    -1,
    1016,    -1,   827,     5,  1016,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   489,   910,
     830,   452,    -1,    -1,     5,   875,   682,   878,    -1,   218,
      -1,   339,    -1,    -1,   833,    -1,   834,    -1,   833,   834,
      -1,    -1,    -1,   496,   835,   838,   836,  1279,    -1,    -1,
     113,   837,   843,   673,   866,  1279,    -1,   841,    -1,   838,
       5,   841,    -1,    -1,   840,  1012,    -1,   415,   839,   887,
      25,    -1,   415,   839,   887,  1012,    -1,   415,   839,   887,
    1018,    -1,   415,   839,   887,    26,    -1,   844,   863,    -1,
     839,   415,   842,    -1,    26,    -1,    25,    -1,  1018,    -1,
      19,    26,    -1,   839,    -1,   843,    -1,   844,     5,   843,
      -1,    -1,   379,    -1,    -1,   726,    -1,   727,    -1,   728,
      -1,    -1,   544,   517,   854,   485,   848,   680,   863,    -1,
      -1,    49,   846,   849,   680,   863,    -1,    -1,   378,   845,
     851,    26,   852,   362,   517,   853,   485,   850,   680,   863,
      -1,   489,    -1,   516,    -1,   452,    -1,   484,    -1,    26,
      -1,   855,     5,   855,     5,   855,    -1,   855,     5,   855,
      -1,   855,    -1,    26,    -1,   839,    -1,   839,   646,   839,
      -1,   839,   668,   839,   646,   839,    -1,    -1,   522,   858,
     838,   343,    -1,    -1,   321,   859,   856,   676,    20,    -1,
      -1,   396,   860,   856,   319,   489,   861,   452,    -1,   862,
      -1,   861,     5,   862,    -1,   839,    -1,   865,    -1,    -1,
     121,    -1,   866,   864,    -1,   847,    -1,   857,    -1,   379,
      -1,   380,    -1,   379,   489,    26,   452,    -1,   380,   489,
      26,   452,    -1,   482,   489,    26,   452,    -1,   482,   489,
      26,     5,    26,   452,    -1,   381,   489,    26,   452,    -1,
     381,   489,    26,     5,    26,   452,    -1,   467,    -1,   530,
      -1,   673,   839,    -1,    32,    -1,   441,    -1,   566,    -1,
     153,    -1,   457,    -1,   457,   489,    26,   452,    -1,   457,
     489,    26,     5,    26,   452,    -1,   569,    -1,   569,   489,
      26,   452,    -1,   569,   489,    26,     5,    26,   452,    -1,
      -1,   559,   867,   870,    -1,    -1,   126,   868,   870,    -1,
      -1,   359,   869,   870,    -1,   594,    -1,   590,    -1,   142,
      -1,   143,    -1,   631,    -1,   418,   873,    -1,   430,   874,
      -1,   871,    -1,    -1,   489,    26,   452,    -1,   613,   856,
     676,   872,    -1,   839,    -1,    -1,   875,   682,   878,    -1,
     883,   682,   886,    -1,    -1,   876,   877,    -1,   638,    -1,
     570,    -1,   647,    -1,   609,    -1,   512,    -1,   528,    -1,
     427,   880,    -1,    -1,   879,   877,    -1,    -1,   489,   882,
     452,    -1,    -1,   489,    26,   452,    -1,    26,    -1,    -1,
     884,   885,   881,    -1,   638,    -1,   570,    -1,   647,    -1,
     609,    -1,   512,    -1,   528,    -1,   427,   880,    -1,   885,
      -1,    -1,    14,    -1,    -1,   674,  1002,    -1,   133,  1012,
      -1,   131,    -1,   682,   960,    -1,   682,   566,  1012,   715,
     960,    -1,   682,   566,  1012,   450,    -1,   135,  1012,    -1,
     219,   933,  1186,   896,    -1,   460,   933,   915,   888,   896,
      -1,   272,  1009,   896,    -1,    -1,    -1,   250,   893,  1193,
     682,  1012,   676,    20,   895,   750,   894,   897,    -1,    -1,
     526,  1003,    -1,   750,    -1,    -1,   898,   299,    -1,   299,
      -1,   899,    -1,   898,   899,    -1,    -1,   413,   900,  1594,
      -1,    -1,   409,   901,  1594,    -1,    -1,  1086,   902,  1594,
      -1,    51,  1168,    -1,    52,  1168,    -1,    50,  1168,    -1,
     555,   933,   916,   750,    -1,   555,   933,   916,   750,   128,
      -1,   276,    -1,   276,   917,    -1,   346,    -1,   345,    -1,
     275,    -1,   425,    -1,   235,    -1,   274,    -1,   390,    -1,
     389,    -1,   304,    -1,   232,    -1,   231,    -1,   209,    -1,
     265,    -1,   193,    -1,   208,    -1,   249,    -1,   216,    -1,
     918,    -1,   922,    -1,   952,    -1,   910,   911,    -1,   953,
      -1,   955,    -1,   919,    -1,    19,   910,    -1,    18,   910,
      -1,   924,    -1,   932,    -1,   926,    -1,   532,    -1,   828,
      -1,   927,    -1,   928,    -1,   929,    -1,   930,    -1,   931,
      -1,    56,   910,    -1,   933,    -1,   933,   914,    -1,   917,
      -1,   540,    -1,   913,    -1,   914,     5,   913,    -1,   917,
      -1,   915,     5,   917,    -1,   917,    -1,   916,     5,   917,
      -1,   910,    -1,     9,   910,    -1,   541,    -1,   486,    -1,
     489,   910,   452,    -1,   501,   489,  1499,   452,    -1,   354,
     489,  1499,   452,    -1,    25,    -1,  1018,    -1,    26,    -1,
     921,    -1,  1168,    -1,  1168,   479,  1168,    -1,   920,    -1,
     492,   910,    -1,   453,   910,    -1,  1282,    -1,    -1,   564,
     923,  1282,    -1,     7,   910,    -1,     6,   910,    -1,   910,
      -1,   925,     5,   910,    -1,   679,   489,  1499,   452,    -1,
     487,   489,  1499,   452,    -1,   679,   489,   933,   925,   452,
      -1,   487,   489,   933,   925,   452,    -1,   447,    -1,   310,
      -1,    10,   910,    -1,   313,   910,    -1,    10,   910,   500,
      25,    -1,   313,   910,   500,    25,    -1,   613,   910,    -1,
     432,   910,    -1,   613,   910,   500,    25,    -1,   432,   910,
     500,    25,    -1,   451,    -1,     8,   910,    -1,    18,   910,
      -1,    19,   910,    -1,    20,   910,    -1,    21,   910,    -1,
      22,   910,    -1,    11,   910,    -1,    14,   910,    -1,   515,
     910,    -1,    12,   910,    -1,    13,   910,    -1,    17,   910,
      -1,    16,   910,    -1,    15,   910,    -1,    -1,    -1,    -1,
    1012,   489,   935,   779,   936,   452,    -1,    -1,    -1,  1012,
     578,  1012,   489,   937,   779,   938,   452,    -1,    -1,    -1,
    1012,    36,  1012,   489,   939,   779,   940,   452,    -1,    -1,
      -1,   594,   489,   942,   910,   943,   452,    -1,    -1,    -1,
     570,   489,   944,   910,   945,   452,    -1,    -1,    -1,   647,
     489,   946,   910,   947,   452,    -1,    -1,    -1,   638,   489,
     948,   910,   949,   452,    -1,   430,   489,   956,   452,   951,
      -1,   418,   489,    25,   452,   950,    -1,   418,   489,    26,
     452,   950,    -1,   418,   489,    24,   452,   950,    -1,   418,
     489,    26,   646,    26,   452,   950,    -1,   418,   489,    26,
     646,    24,   452,   950,    -1,   418,   489,    26,   646,    26,
     646,    26,   452,   950,    -1,   418,   489,    26,   646,    26,
     646,    24,   452,   950,    -1,   418,   489,    26,    26,   452,
     950,    -1,   418,   489,    26,    26,   646,    26,   452,   950,
      -1,   418,   489,    26,    26,   646,    26,   646,    26,   452,
     950,    -1,   418,   489,    26,    26,   646,    26,   646,    24,
     452,   950,    -1,   418,   489,    26,    19,    26,   452,   950,
      -1,   418,   489,    26,    19,    26,    19,    26,   452,   950,
      -1,   418,   489,    26,    19,    26,    26,   452,   950,    -1,
     418,   489,    26,    19,    26,    19,    26,    26,   452,   950,
      -1,   418,   489,    26,    19,    26,    19,    26,    26,   646,
      26,   452,   950,    -1,   418,   489,    26,    19,    26,    19,
      26,    26,   646,    26,   646,    26,   452,   950,    -1,   418,
     489,    26,    19,    26,    19,    26,    26,   646,    26,   646,
      24,   452,   950,    -1,   418,   489,    26,    19,    26,    26,
     646,    26,   452,   950,    -1,   418,   489,    26,    19,    26,
      26,   646,    26,   646,    26,   452,   950,    -1,   418,   489,
      26,    19,    26,    26,   646,    26,   646,    24,   452,   950,
      -1,    47,   489,  1168,   452,    -1,   731,   489,  1168,   452,
      -1,   732,   489,  1168,     5,    26,   452,    -1,    -1,   877,
     682,   877,    -1,   874,    -1,   941,    -1,   349,   489,   960,
     452,    -1,   161,   489,  1003,   452,    -1,   134,   489,  1003,
     452,    -1,   466,   489,   961,   452,    -1,   254,   489,   960,
     452,    -1,   122,   489,   960,   452,    -1,   954,    -1,   934,
      -1,  1476,    -1,   594,    -1,   481,   489,   910,   452,    -1,
     384,   489,   910,   452,    -1,   545,   910,    -1,   502,   829,
      -1,   910,   172,    -1,   910,   173,    -1,   910,   174,    -1,
      25,    -1,   957,    -1,    19,   957,    -1,   959,    -1,   958,
      -1,    26,    -1,    26,    26,    -1,    26,    26,   646,    26,
      -1,    26,    26,   646,    26,   646,    26,    -1,    26,    26,
     646,    26,   646,    24,    -1,    26,   646,    26,    -1,    26,
     646,    26,   646,    26,    -1,    26,   646,    26,   646,    24,
      -1,    26,   646,    24,    -1,    24,    -1,   676,    26,    -1,
      26,    -1,    26,    19,    26,    -1,  1003,    -1,   960,     5,
    1003,    -1,  1004,    -1,   961,     5,  1004,    -1,    -1,    -1,
      -1,   463,   963,  1006,   964,   966,  1378,   965,  1594,   301,
      -1,    -1,     8,   933,   915,    -1,    -1,    -1,   694,  1012,
     968,   832,   969,  1117,   971,   970,   976,   695,    -1,    -1,
     981,    -1,    -1,   972,    -1,   973,    -1,   972,   973,    -1,
      -1,   696,   974,  1594,    -1,    -1,   697,   975,  1594,    -1,
      -1,   977,    -1,   978,    -1,   977,   978,    -1,    -1,   698,
     979,  1594,    -1,    -1,   699,   980,  1594,    -1,   982,   986,
     386,    -1,   738,    -1,   738,   983,   603,   984,    -1,   738,
     445,   985,    -1,  1168,    -1,   983,     5,  1168,    -1,  1012,
      -1,   984,     5,  1012,    -1,  1168,    -1,   985,     5,  1168,
      -1,   987,    -1,   986,   987,    -1,    -1,   700,   988,  1594,
      -1,    -1,   701,   989,  1594,    -1,    -1,   720,   984,   990,
    1594,    -1,    -1,   538,   984,   991,  1594,    -1,    -1,   681,
     984,   992,  1594,    -1,    -1,    -1,   652,  1168,    14,   917,
     682,   917,   996,   994,  1594,   995,   302,    -1,    -1,   628,
     917,    -1,   602,  1005,    -1,   611,    19,    26,    -1,   611,
      -1,   558,    18,    26,    -1,   558,    -1,    26,    -1,  1168,
      -1,   725,    -1,    25,    -1,  1017,    -1,   917,    -1,  1000,
       5,  1000,    -1,  1001,    -1,  1012,    -1,   723,   489,  1012,
     452,    -1,  1012,   676,   723,   489,  1012,   452,    -1,  1012,
     517,   747,   485,    -1,  1012,   676,    20,    -1,  1012,   517,
     747,   485,   676,    20,    -1,  1012,   676,  1012,    -1,  1012,
     517,   747,   485,   676,  1012,    -1,  1003,    -1,    25,    -1,
    1013,    -1,  1013,    -1,  1013,    -1,  1013,    -1,  1013,    -1,
    1013,    -1,    -1,   607,    26,    -1,  1593,    -1,  1014,    -1,
    1593,    -1,   411,   489,  1015,   452,    -1,  1171,    -1,    25,
      -1,  1012,    -1,  1012,   517,   747,   485,    -1,  1012,   676,
      20,    -1,  1012,   517,   747,   485,   676,    20,    -1,  1012,
     676,  1012,    -1,  1012,   517,   747,   485,   676,  1012,    -1,
    1168,    -1,    24,    -1,   676,    26,    -1,   604,  1020,    -1,
    1012,    -1,   646,  1012,    -1,   708,  1022,    -1,  1023,    -1,
    1022,     5,  1023,    -1,  1012,    -1,   719,  1022,    -1,   710,
    1022,    -1,   711,   960,    -1,   709,  1009,   715,   960,    -1,
     713,  1022,    -1,   714,   960,    -1,   712,  1009,   715,   960,
      -1,    -1,   717,  1028,   915,  1033,  1035,  1037,  1029,  1031,
      -1,    -1,  1030,    -1,   705,    -1,   706,    -1,    -1,  1032,
      -1,   406,  1168,    -1,    -1,  1034,    -1,   450,   915,    -1,
      -1,  1036,    -1,   716,    26,    -1,    -1,  1038,    -1,   707,
      26,  1039,    -1,    -1,   459,    26,    -1,    -1,    -1,   678,
     917,   632,  1041,  1594,  1042,  1043,   499,    -1,    -1,    -1,
     599,  1044,  1594,    -1,    -1,    -1,   125,  1045,   917,   632,
    1046,  1594,  1043,    -1,   170,  1012,   489,    26,   452,    -1,
     116,  1012,    -1,    48,  1012,    -1,   138,  1012,    -1,    -1,
     350,  1197,  1051,   682,   540,    -1,   350,  1197,   613,  1052,
      -1,  1053,    -1,  1052,     5,  1053,    -1,  1054,   676,  1472,
      -1,  1054,   676,    20,    -1,  1468,    -1,    -1,  1057,   386,
      -1,   386,    -1,    -1,   213,    -1,  1058,    -1,  1057,  1058,
      -1,    -1,   330,  1072,  1059,  1594,    -1,    -1,   333,  1073,
    1060,  1594,    -1,    -1,   413,  1061,  1594,    -1,    -1,   409,
    1062,  1594,    -1,    -1,  1086,  1063,  1594,    -1,    -1,   365,
    1064,  1594,    -1,    -1,   335,  1065,  1594,    -1,    -1,    57,
    1066,  1594,    -1,    -1,    55,  1067,  1594,    -1,    -1,    54,
    1068,  1594,    -1,    -1,    53,  1069,  1594,    -1,    -1,    60,
    1070,  1594,    -1,    -1,    59,  1071,  1594,    -1,  1003,    -1,
    1072,     5,  1003,    -1,  1003,    -1,  1073,     5,  1003,    -1,
     374,  1076,    -1,   375,  1012,   715,  1076,    -1,   618,    -1,
     436,    -1,  1003,    -1,    -1,   721,  1079,  1078,  1055,    -1,
     445,  1186,  1056,  1011,   750,    -1,  1186,  1056,   603,   960,
    1011,   750,    -1,    -1,   544,  1193,  1056,   603,  1012,   676,
      20,  1011,  1080,   750,    -1,   527,   960,  1082,    -1,   144,
      26,    -1,   145,    26,    -1,   683,    -1,   596,    -1,   144,
    1168,    -1,   145,  1168,    -1,    -1,   607,    26,    -1,  1085,
      -1,    66,    25,    -1,   553,    14,    26,    -1,   553,    14,
    1168,    -1,    67,    14,    26,    -1,    67,    14,  1168,    -1,
      63,    -1,    65,    -1,    62,    -1,    64,    -1,    -1,   488,
    1087,  1092,    -1,   355,    -1,    -1,   653,  1089,  1092,    -1,
     363,  1094,    -1,   653,  1092,    -1,  1094,    -1,   489,  1093,
     452,    -1,  1094,    -1,  1093,     5,  1094,    -1,  1095,    -1,
     651,    -1,   372,    -1,   392,    -1,   364,    -1,   542,    -1,
     500,    -1,   683,    -1,   607,    -1,   596,    -1,   239,    -1,
     497,    -1,   508,    -1,   597,    -1,   612,    -1,   577,    -1,
     370,    -1,   371,    -1,    25,    -1,   567,    -1,    -1,    -1,
     655,  1098,  1191,  1099,    14,   933,  1100,    -1,   540,    -1,
     916,    -1,   281,  1168,    -1,   271,  1168,    -1,   284,  1168,
      -1,   509,  1189,   395,    -1,   509,  1189,   446,   999,    -1,
    1106,    -1,  1107,    -1,   798,    -1,    -1,  1109,  1108,  1112,
      -1,    -1,  1110,    -1,  1111,    -1,  1110,  1111,    -1,  1049,
      -1,  1116,    -1,  1578,    -1,  1048,    -1,  1132,    -1,  1118,
      -1,  1131,    -1,    -1,  1113,    -1,  1115,    -1,  1113,  1115,
      -1,   129,  1012,    -1,  1120,    -1,  1126,    -1,  1292,    -1,
    1302,    -1,  1138,    -1,   967,    -1,   806,    -1,  1047,    -1,
    1578,    -1,   806,    -1,    -1,   806,    -1,   833,    -1,   428,
      -1,   123,    -1,    -1,    -1,    -1,    -1,  1119,  1121,  1012,
     489,  1122,  1184,   452,  1123,   832,  1124,  1117,  1594,  1125,
      -1,   273,    -1,    -1,    -1,   614,  1127,   832,  1128,  1594,
     422,    -1,   239,   912,    -1,   933,    -1,   933,   915,    -1,
     417,  1483,    -1,   525,  1483,    -1,  1133,    -1,  1134,    -1,
    1133,  1134,    -1,  1135,    -1,    -1,   465,  1136,  1137,    -1,
     832,   303,    -1,   999,    -1,  1116,    -1,  1131,    -1,    -1,
      -1,   702,  1012,  1139,   832,  1140,  1141,   703,    -1,  1142,
      -1,  1141,  1142,    -1,    -1,   704,  1143,  1594,    -1,    -1,
     681,  1012,  1144,  1594,    -1,    -1,   615,  1146,  1161,  1152,
    1147,    -1,   423,    -1,    -1,   296,  1149,  1594,    -1,    -1,
      23,  1153,  1154,  1155,  1011,  1150,  1594,    -1,    -1,    23,
    1153,  1011,  1151,  1594,    -1,  1148,    -1,  1152,  1148,    -1,
      -1,  1088,    -1,    25,    -1,  1168,    -1,    -1,  1168,    -1,
      25,    -1,   312,  1159,    -1,   323,  1160,    -1,   307,  1160,
      -1,   642,    -1,    25,    -1,  1168,    -1,  1159,    -1,  1160,
       5,  1159,    -1,  1168,    -1,    25,    -1,  1165,  1163,    -1,
      -1,   751,  1166,    -1,  1167,    -1,  1164,    -1,  1034,    -1,
    1036,    -1,  1038,    -1,  1030,    -1,  1032,    -1,   431,   933,
     915,    -1,    -1,   128,    -1,   128,    -1,  1169,    -1,  1171,
      -1,   252,  1171,    -1,  1171,   676,    -1,  1170,  1175,    -1,
    1170,  1012,   517,  1178,   485,    -1,  1170,  1012,   517,  1178,
     485,   517,  1178,   485,    -1,  1176,    -1,  1012,    -1,  1172,
      -1,  1012,   516,  1174,   484,    -1,  1012,   516,  1174,   484,
      -1,  1168,    -1,    25,    -1,    20,    -1,  1012,    -1,  1012,
    1177,    -1,   517,  1178,   485,    -1,   517,  1178,   485,   517,
    1178,   485,    -1,  1179,    -1,  1178,     5,  1179,    -1,   747,
      -1,  1181,    -1,  1183,    -1,  1181,   676,  1182,    -1,  1181,
     676,  1012,   517,  1178,   485,    -1,  1181,   676,  1012,   517,
    1178,   485,   517,  1178,   485,    -1,  1012,    -1,  1173,    -1,
      20,    -1,  1012,    -1,  1012,  1177,    -1,    -1,  1185,    -1,
    1187,    -1,  1185,     5,  1187,    -1,  1188,    -1,  1186,     5,
    1188,    -1,  1012,    -1,  1012,   676,  1012,    -1,  1168,    -1,
    1168,   479,  1168,    -1,    25,    -1,  1018,    -1,    26,    -1,
    1190,    -1,  1189,     5,  1190,    -1,  1168,    -1,  1168,   479,
    1168,    -1,  1192,    -1,  1191,     5,  1192,    -1,  1180,    -1,
    1168,    -1,  1195,    -1,  1194,     5,  1195,    -1,  1168,  1196,
      -1,    -1,   644,    -1,   595,    -1,  1198,    -1,  1197,     5,
    1198,    -1,  1168,    -1,  1168,   479,  1168,    -1,   315,  1008,
     674,  1001,   636,  1586,   755,    -1,    -1,   674,   489,   917,
       5,   917,   452,  1201,    -1,    -1,   625,   489,   917,     5,
     917,   452,    -1,   316,  1012,  1200,    -1,  1012,    -1,   400,
    1010,  1205,    -1,  1206,    -1,   603,   917,    -1,  1207,  1208,
    1213,     8,  1203,    -1,    -1,   674,  1209,   489,   917,     5,
     917,   452,    -1,    -1,   613,  1013,    -1,    -1,   412,    -1,
     279,  1525,   326,  1567,  1212,    -1,   620,  1006,    -1,   620,
    1006,     8,   933,   915,    -1,    -1,   673,   633,  1519,   435,
    1519,    -1,   673,   633,  1519,     5,   435,  1519,    -1,   673,
    1519,     5,  1519,    -1,    -1,   705,    -1,   706,    -1,   454,
     682,  1567,  1215,  1216,    -1,    -1,   673,  1567,    -1,    -1,
     673,   633,  1519,     8,  1519,    -1,   633,  1519,     8,  1519,
      -1,   470,  1218,    -1,  1219,    -1,  1218,     5,  1219,    -1,
     264,   998,    -1,   344,   998,    -1,   391,   998,    -1,   399,
     998,    -1,   353,   998,    -1,   320,   998,    -1,  1090,    -1,
     497,  1091,    -1,   508,  1091,    -1,   618,  1091,    -1,   436,
    1091,    -1,   607,  1091,    -1,   605,   999,    -1,   606,   999,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,   460,
     751,    -1,   721,   751,    -1,   351,    -1,   257,    -1,   214,
      -1,   194,    -1,   202,    -1,   211,    -1,   663,  1220,    -1,
     737,  1221,    -1,    45,    -1,    46,    -1,    45,    -1,    46,
      -1,  1524,   472,  1225,   603,  1223,    -1,  1168,    -1,    25,
      -1,   462,  1225,    -1,   462,  1225,     8,  1186,    -1,   462,
    1225,   610,  1189,    -1,   462,  1225,   610,  1189,     8,  1186,
      -1,    61,  1223,    -1,  1013,    -1,    -1,   520,  1235,   750,
     652,  1230,  1168,  1228,  1011,   750,  1227,  1231,    -1,    -1,
     724,    26,    -1,   520,  1235,   750,   406,  1168,    -1,    -1,
     379,    -1,    -1,  1232,   342,    -1,  1233,    -1,  1232,  1233,
      -1,    -1,  1086,  1234,  1594,    -1,   916,    -1,    -1,   660,
    1005,  1237,  1238,    -1,    -1,   603,  1239,    -1,  1240,    -1,
    1239,     5,  1240,    -1,  1511,    -1,   540,    -1,   282,  1245,
     152,    -1,   282,  1245,   682,  1243,    -1,   282,  1245,   150,
    1243,    -1,   282,  1245,   151,    -1,   282,  1245,    38,    -1,
     282,  1245,    -1,    42,  1245,   682,  1223,   673,  1223,     8,
    1223,    -1,    42,  1245,   682,  1223,   673,  1223,    -1,    25,
      -1,  1017,    -1,    39,  1245,    -1,  1012,    -1,    -1,   536,
      -1,   210,  1245,  1246,   489,   933,  1130,   452,    -1,   255,
    1245,    -1,   255,  1245,    40,    -1,   255,  1245,    41,  1223,
     673,  1223,     8,  1223,    -1,   255,  1245,    41,  1223,   673,
    1223,    -1,   130,  1245,    -1,  1283,  1291,    -1,   505,   124,
      -1,   505,  1252,    -1,  1253,    -1,  1252,  1253,    -1,    -1,
     198,  1254,  1594,    -1,    -1,   260,  1255,  1594,    -1,    -1,
     290,  1256,  1594,    -1,    -1,   278,  1257,  1594,    -1,    -1,
     314,  1258,  1594,    -1,    -1,   262,  1168,  1259,  1594,    -1,
      -1,   286,  1168,  1260,  1594,    -1,  1271,    -1,  1275,    -1,
    1274,    -1,  1262,    -1,  1300,    -1,  1265,    -1,    -1,   617,
     917,  1263,   539,    -1,    -1,   539,    -1,    -1,   626,    26,
    1266,  1264,    -1,   221,    -1,   685,  1287,    -1,   224,  1287,
      -1,   223,  1287,    -1,    -1,  1268,    -1,  1269,    -1,  1268,
    1269,    -1,  1280,  1270,    -1,    -1,   674,  1287,    -1,    -1,
     576,  1272,  1267,  1279,    -1,  1519,    -1,   489,  1519,   452,
      -1,   575,  1273,  1279,    -1,   574,  1278,  1277,  1276,  1279,
      -1,    -1,   215,   910,    -1,   215,   910,     5,   910,    -1,
     669,    -1,   670,    -1,   671,    -1,   672,    -1,  1168,    -1,
      -1,   579,    -1,  1281,    -1,  1280,     5,  1281,    -1,   917,
    1314,    -1,   665,   489,   910,   452,  1299,    -1,   127,  1299,
      -1,   553,   489,    20,   452,  1299,    -1,   471,   489,    20,
     452,  1299,    -1,   448,   489,   910,   452,  1299,    -1,   645,
     489,   910,   452,  1299,    -1,   658,   489,   910,   452,  1299,
      -1,   657,   489,   910,   452,  1299,    -1,    -1,   519,  1284,
      -1,  1285,    -1,  1284,  1285,    -1,   289,    26,    -1,   280,
      26,    -1,   361,    26,    -1,   246,    26,    -1,   317,    26,
      -1,   237,    -1,   405,    25,    -1,   405,  1168,    -1,   238,
      25,    -1,   222,    25,    -1,  1290,    -1,  1286,  1290,    -1,
    1288,   172,    -1,  1288,   174,    -1,  1288,   173,    -1,  1288,
      -1,  1018,    -1,    26,    -1,    -1,   519,  1286,    -1,   289,
    1287,    -1,   280,  1287,    -1,   361,  1287,    -1,   246,  1287,
      -1,   317,  1287,    -1,   318,  1287,    -1,   684,    25,    -1,
     685,  1287,    -1,   689,    -1,   686,    -1,   687,    -1,   688,
      -1,   693,    -1,   690,    -1,   691,    -1,   692,    -1,   139,
    1287,    -1,   140,  1287,    -1,   141,  1287,    -1,   405,    25,
      -1,   238,    25,    -1,   459,    -1,   136,    -1,   137,    -1,
      -1,   571,   675,  1194,    -1,   199,  1194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   523,  1293,  1012,   489,  1294,  1184,
     452,  1295,   832,  1296,  1250,  1297,  1251,  1298,   300,    -1,
      -1,   583,   910,    -1,   573,  1301,    -1,    -1,  1223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,  1303,  1012,   489,
    1304,  1184,   452,  1305,   832,  1306,  1309,  1307,  1251,  1308,
     300,    -1,  1289,  1291,    -1,    -1,    -1,    -1,   217,   489,
      25,     5,  1311,   779,  1312,   452,  1313,   777,    -1,    -1,
     444,    -1,   444,   280,    26,    -1,   444,   280,  1168,    -1,
     663,   917,    -1,   663,   917,  1316,    -1,   663,   917,   406,
    1168,    -1,   663,   917,   225,    -1,   663,   917,  1316,   406,
    1168,    -1,   663,   917,  1316,   225,    -1,   663,   917,   634,
      -1,   663,   917,   601,    -1,    46,    -1,    45,    -1,  1318,
      -1,   234,  1468,    -1,   385,  1468,    -1,   341,  1469,    -1,
      58,  1012,    -1,  1332,    -1,  1320,    -1,    -1,    -1,   267,
    1321,  1468,   489,  1322,  1336,   452,  1325,    -1,    -1,    -1,
     196,  1323,  1468,   489,  1324,  1336,   452,  1325,  1333,    -1,
      -1,  1326,    -1,  1327,    -1,  1326,  1327,    -1,   679,  1328,
      -1,   305,    26,    -1,    70,    26,    -1,   148,    -1,   149,
      -1,  1593,    -1,    -1,  1330,    -1,  1331,    -1,  1330,  1331,
      -1,   679,  1328,    -1,   733,    26,    -1,   167,  1469,   681,
    1468,   489,  1334,   452,  1329,    -1,   114,  1013,    -1,   115,
    1013,    -1,   233,  1468,   652,  1468,    -1,   119,  1468,    -1,
      -1,   328,    -1,  1335,    -1,  1334,     5,  1335,    -1,  1012,
     644,    -1,  1012,   595,    -1,  1012,    -1,  1337,    -1,  1336,
       5,  1337,    -1,  1420,    -1,  1418,    -1,   183,  1012,    -1,
     241,    -1,    68,  1012,  1340,    -1,    69,  1469,   164,    -1,
      69,  1469,   165,    -1,  1341,    -1,  1340,     5,  1341,    -1,
    1342,    -1,  1345,    -1,  1348,    -1,  1353,    -1,  1356,    -1,
    1352,    -1,  1351,    -1,   641,  1343,    -1,   641,   489,  1344,
     452,    -1,  1337,    -1,  1337,   720,  1012,    -1,  1343,    -1,
    1344,     5,  1343,    -1,   598,  1347,    -1,   598,   489,  1346,
     452,    -1,  1347,    -1,  1346,     5,  1347,    -1,  1012,    -1,
     513,  1350,    -1,   513,   489,  1349,   452,    -1,  1350,    -1,
    1349,     5,  1350,    -1,  1337,    -1,   148,    -1,   149,    -1,
     147,    26,    -1,   117,  1418,  1355,    -1,   117,   489,  1354,
     452,    -1,  1418,  1355,    -1,  1354,     5,  1418,  1355,    -1,
      -1,   120,  1012,    -1,   118,  1357,    -1,   118,   489,  1357,
     452,    -1,  1358,    -1,  1357,     5,  1358,    -1,  1012,    -1,
     325,    -1,   293,    -1,   227,  1361,    -1,   206,    -1,   195,
      -1,   182,    -1,   180,    -1,   184,    -1,   240,  1525,    -1,
     292,  1360,   518,  1519,   682,  1519,    -1,   358,  1005,   518,
    1519,   682,  1519,    -1,    -1,  1525,    -1,    -1,   917,    -1,
     580,   917,    -1,   291,    -1,    -1,   309,  1365,  1468,  1368,
    1366,    -1,    -1,   536,  1367,   489,  1370,   452,    -1,  1505,
      -1,    -1,   489,  1369,   452,    -1,  1472,    -1,  1369,     5,
    1472,    -1,  1371,    -1,  1370,     5,  1371,    -1,  1511,    -1,
     540,    -1,    -1,   557,  1373,  1375,  1376,    -1,  1013,    -1,
    1380,  1006,    -1,  1006,    -1,    -1,    -1,   610,  1377,  1189,
      -1,    -1,    -1,   610,  1379,  1189,    -1,   558,    -1,   611,
      -1,   618,    -1,   436,    -1,   403,    -1,   455,    -1,   439,
     917,    -1,   412,   917,    -1,   298,  1468,   212,  1006,    -1,
     298,  1468,  1441,    -1,   571,   675,  1384,    -1,  1385,    -1,
    1384,     5,  1385,    -1,  1386,  1387,    -1,    26,    -1,  1472,
      -1,    -1,   644,    -1,   595,    -1,   336,    -1,   369,    -1,
      -1,   388,    -1,   417,  1392,  1390,    -1,  1567,    -1,  1567,
     668,  1012,    -1,    25,    -1,    -1,  1524,  1394,  1395,    -1,
    1426,    -1,    37,    -1,  1430,    -1,  1389,    -1,  1526,    -1,
    1388,    -1,  1381,    -1,  1382,    -1,  1372,    -1,  1364,    -1,
    1363,    -1,  1495,    -1,  1547,    -1,   562,  1399,   681,  1468,
     682,  1404,  1398,    -1,   524,  1399,   681,  1468,   603,  1404,
      -1,   562,  1397,   682,  1404,    -1,   524,  1397,   603,  1404,
      -1,   454,    -1,   440,    -1,   648,    -1,    -1,   205,    -1,
     673,  1012,    -1,   229,    -1,   642,    -1,  1400,    -1,  1401,
      -1,  1400,     5,  1401,    -1,   529,  1402,    -1,   508,    -1,
     497,    -1,   535,  1402,    -1,   543,    -1,   565,    -1,    -1,
     489,  1403,   452,    -1,  1472,    -1,  1403,     5,  1472,    -1,
    1405,    -1,  1404,     5,  1405,    -1,   521,    -1,  1470,    -1,
     297,  1468,  1407,   673,  1505,  1409,    -1,    -1,   489,  1408,
     452,    -1,  1472,    -1,  1408,     5,  1472,    -1,    -1,   204,
      -1,   549,   489,  1444,   452,    -1,   306,   489,  1413,   452,
    1412,    -1,   356,  1414,    -1,  1415,    -1,  1468,    -1,  1468,
     489,  1415,   452,    -1,  1472,    -1,  1415,     5,  1472,    -1,
     533,   489,  1417,   452,    -1,   420,   489,  1417,   452,    -1,
     319,   489,  1417,   452,    -1,  1472,    -1,  1417,     5,  1472,
      -1,  1416,    -1,  1411,    -1,  1410,    -1,   459,  1475,    -1,
     270,    -1,   269,    -1,   268,    -1,  1012,  1460,  1421,  1422,
      -1,    -1,  1419,    -1,    -1,  1423,    -1,  1424,    -1,  1423,
    1424,    -1,  1425,  1355,    -1,   434,    -1,   220,    -1,   533,
      -1,   420,    -1,  1412,    -1,   549,   489,  1444,   452,    -1,
     319,    -1,   181,  1427,  1429,    -1,  1428,    -1,  1470,    -1,
    1430,    -1,  1429,  1430,    -1,  1406,    -1,  1396,    -1,   506,
    1444,    -1,   429,  1433,    -1,  1510,    -1,  1433,     5,  1510,
      -1,   583,  1444,    -1,   603,  1436,    -1,  1437,    -1,  1436,
       5,  1437,    -1,  1438,    -1,   572,  1438,    -1,   572,   489,
    1439,   452,    -1,  1468,    -1,  1468,  1474,    -1,  1468,   673,
    1474,    -1,  1437,    -1,  1439,     5,  1437,    -1,  1435,  1441,
    1442,  1443,    -1,    -1,  1434,    -1,    -1,  1432,    -1,    -1,
    1431,    -1,  1445,    -1,  1444,     6,  1445,    -1,  1446,    -1,
    1445,     7,  1446,    -1,  1447,    -1,     9,  1447,    -1,  1458,
      -1,   489,  1444,   452,    -1,   501,  1506,    -1,   354,  1506,
      -1,    -1,   500,  1451,    -1,  1512,    -1,  1515,    -1,  1511,
     679,   489,  1453,   452,    -1,  1511,   679,  1506,    -1,  1511,
     487,   489,  1453,   452,    -1,  1511,   487,  1506,    -1,  1454,
      -1,  1453,     5,  1454,    -1,  1573,    -1,  1475,    -1,    -1,
       9,    -1,  1511,  1455,   447,    -1,  1511,  1455,   310,    -1,
    1511,  1457,  1511,    -1,  1511,  1455,   449,  1511,     7,  1511,
      -1,  1511,   613,  1450,  1449,    -1,  1511,   432,  1450,  1449,
      -1,  1511,   730,  1450,  1449,    -1,  1511,   433,  1450,  1449,
      -1,  1511,  1455,    10,  1450,  1449,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   729,    -1,    16,    -1,    15,
      -1,  1456,    -1,  1452,    -1,  1448,    -1,    -1,   642,    -1,
     420,    -1,   533,    -1,  1461,    -1,  1462,    -1,  1464,    -1,
     379,    -1,   379,   489,  1465,   452,    -1,    -1,   530,    -1,
     530,   489,    26,   452,    -1,   457,    -1,   457,   489,  1466,
    1463,   452,    -1,   569,   489,  1466,  1463,   452,    -1,   569,
      -1,   594,    -1,   467,    -1,   441,    -1,   380,    -1,   380,
     489,  1465,   452,    -1,   381,    -1,   381,   489,    26,   452,
      -1,   381,   489,    26,     5,    26,   452,    -1,   418,  1481,
     682,  1482,    -1,   418,    -1,   430,  1481,   682,  1482,    -1,
     430,    -1,   430,  1481,   489,    26,   452,   682,  1482,    -1,
     631,    -1,   590,    -1,   482,    -1,   482,   489,    26,   452,
      -1,   482,   489,    26,     5,    26,   452,    -1,    -1,     5,
    1467,    -1,   559,   489,  1466,   452,    -1,   622,    -1,   359,
      -1,   559,    -1,   126,    -1,    26,    -1,    26,    -1,    26,
      -1,    25,   676,  1012,    -1,    25,    -1,  1012,    -1,  1012,
     646,  1012,    -1,  1012,   646,    25,   676,  1012,    -1,  1012,
     668,  1012,    -1,  1012,   668,  1012,   646,  1012,    -1,  1012,
     668,  1012,   646,    25,   676,  1012,    -1,    25,   676,  1012,
      -1,    25,    -1,  1012,    -1,  1012,   646,  1012,    -1,  1012,
     646,    25,   676,  1012,    -1,  1012,   668,  1012,    -1,  1012,
     668,  1012,   646,  1012,    -1,  1012,   668,  1012,   646,    25,
     676,  1012,    -1,  1012,    -1,    -1,   517,    26,   485,    -1,
     517,    26,     5,    26,   485,    -1,  1473,    -1,   668,  1473,
      -1,  1012,  1471,    -1,  1468,   676,  1012,  1471,    -1,  1468,
     676,    20,    -1,  1012,    -1,    25,    -1,  1018,    -1,    26,
      -1,  1477,    -1,   455,  1479,    -1,   455,  1478,    -1,    -1,
    1481,   682,  1482,    -1,    -1,  1480,   682,  1480,    -1,   638,
      -1,   570,    -1,   647,    -1,   609,    -1,   512,    -1,   528,
      -1,   427,    -1,   427,   489,    26,   452,    -1,   638,    -1,
     570,    -1,   647,    -1,   609,    -1,   512,    -1,   528,    -1,
     427,    -1,   638,    -1,   570,    -1,   647,    -1,   609,    -1,
     512,    -1,   528,    -1,   427,    -1,   427,   489,    26,   452,
      -1,  1012,    -1,  1012,   668,  1012,    -1,    25,    -1,  1524,
     560,  1006,    -1,    -1,  1524,   458,  1374,   495,   652,  1493,
    1486,    -1,    -1,  1524,   458,  1374,   495,   162,   652,  1494,
    1487,    -1,    -1,  1524,   458,  1374,   200,  1494,  1488,    -1,
      -1,  1524,   458,  1374,   201,   162,   652,  1494,  1489,    -1,
      -1,   348,    -1,   347,  1491,    -1,  1492,    -1,  1491,     5,
    1492,    -1,  1012,    -1,  1012,   676,  1012,    -1,    25,   676,
    1012,   676,  1012,    -1,  1494,    -1,  1364,    -1,  1225,    -1,
    1496,    -1,  1496,    -1,    -1,    -1,   529,  1507,  1497,  1508,
    1498,  1504,  1440,  1502,  1490,    -1,   529,  1507,  1508,  1440,
    1502,    -1,  1501,    -1,  1519,    -1,   529,  1507,  1508,  1504,
    1440,  1502,    -1,    -1,   582,  1459,  1500,    -1,  1383,    -1,
     393,  1503,  1333,    -1,  1383,   393,  1503,  1333,    -1,  1012,
      -1,    -1,   610,  1189,    -1,   529,  1507,  1508,  1440,    -1,
     489,   529,  1507,  1508,  1440,   452,    -1,    -1,   642,    -1,
     420,    -1,   533,    -1,  1509,    -1,  1508,     5,  1509,    -1,
    1511,    -1,  1511,  1012,    -1,  1511,   673,  1012,    -1,  1511,
      -1,  1512,    -1,    19,  1512,    -1,    18,  1512,    -1,  1513,
      -1,  1573,    -1,  1506,    -1,   642,  1506,    -1,   643,  1506,
      -1,   627,  1506,    -1,   668,  1012,    -1,   668,  1012,   676,
    1012,    -1,  1512,    21,  1511,    -1,  1512,  1533,    -1,  1512,
      20,  1511,    -1,  1512,    18,  1511,    -1,  1512,    19,  1511,
      -1,  1475,    -1,   541,    -1,   486,    -1,   633,    -1,    20,
      -1,   127,    -1,   645,   489,  1459,  1511,   452,    -1,   657,
     489,  1459,  1511,   452,    -1,   658,   489,  1459,  1511,   452,
      -1,   665,   489,  1459,  1511,   452,    -1,   553,   489,  1459,
    1511,   452,    -1,  1012,   489,  1514,   452,    -1,   594,   489,
    1514,   452,    -1,   489,  1511,   452,    -1,   502,   489,  1534,
     452,    -1,  1535,    -1,  1537,    -1,  1511,    -1,  1514,     5,
    1511,    -1,  1475,    -1,  1524,   408,  1523,  1518,  1500,    -1,
    1524,   397,  1523,  1518,   309,  1468,  1520,    -1,  1524,   397,
    1523,  1518,  1168,    -1,    -1,   383,  1519,    -1,    25,    -1,
    1168,    -1,    -1,   489,  1521,   452,    -1,  1522,    -1,  1521,
       5,  1522,    -1,  1012,    -1,    25,    -1,  1168,    -1,    -1,
     327,  1525,   652,    -1,  1013,    -1,  1531,    -1,  1530,    -1,
    1527,    -1,   376,  1528,   682,  1528,    -1,   357,  1468,   676,
    1529,   682,  1529,    -1,  1012,    -1,  1012,    -1,   283,  1468,
      -1,   352,  1468,  1532,    -1,   331,    -1,   236,    -1,   154,
      -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,   159,
      -1,   455,     5,  1481,   682,  1482,    -1,  1573,     5,  1481,
     682,  1482,    -1,   455,  1481,   682,  1482,    -1,  1511,     5,
    1481,   682,  1482,    -1,  1536,    -1,  1536,  1481,   682,  1482,
      -1,    43,    -1,  1538,    -1,  1538,  1481,   489,    26,   452,
     682,  1482,    -1,  1538,  1481,   682,  1482,    -1,    44,    -1,
      -1,   664,  1540,  1541,   251,    -1,  1542,    -1,  1541,  1542,
      -1,    33,    -1,  1543,    -1,  1545,    -1,    -1,   252,  1544,
    1573,    -1,    -1,   610,  1546,  1189,    -1,    -1,    -1,   535,
    1468,  1548,  1551,  1549,  1550,    -1,    -1,   212,  1006,    -1,
     583,  1444,    -1,   111,  1555,   452,    14,   489,  1556,   452,
      -1,   107,  1556,   452,    -1,   108,  1556,   452,    -1,   640,
    1552,    -1,   110,  1556,    -1,   109,  1556,    -1,  1554,    -1,
    1552,     5,  1554,    -1,  1472,    -1,  1553,    14,  1557,    -1,
    1553,    -1,  1555,     5,  1553,    -1,  1557,    -1,  1556,     5,
    1557,    -1,   540,    -1,  1558,    -1,  1559,    -1,    19,  1559,
      -1,    18,  1559,    -1,  1561,    -1,  1506,    -1,   668,  1012,
      -1,   668,  1012,   676,  1012,    -1,   668,  1012,   517,    26,
     485,    -1,   668,  1012,   676,  1012,   517,    26,   485,    -1,
     668,  1012,   517,    26,     5,    26,   485,    -1,   668,  1012,
     676,  1012,   517,    26,     5,    26,   485,    -1,  1560,    -1,
    1475,    -1,   541,    -1,   486,    -1,   633,    -1,   127,    -1,
    1559,    21,  1558,    -1,  1559,  1533,    -1,  1559,    20,  1558,
      -1,  1559,    18,  1558,    -1,  1559,    19,  1558,    -1,   645,
     489,  1459,  1558,   452,    -1,   657,   489,  1459,  1558,   452,
      -1,   658,   489,  1459,  1558,   452,    -1,   665,   489,  1459,
    1558,   452,    -1,   553,   489,  1459,  1558,   452,    -1,  1012,
     489,  1562,   452,    -1,   594,   489,  1562,   452,    -1,   489,
    1558,   452,    -1,   502,   489,  1534,   452,    -1,  1535,    -1,
    1537,    -1,  1573,    -1,  1558,    -1,  1562,     5,  1558,    -1,
      -1,   442,  1197,   613,  1564,  1565,    -1,  1566,    -1,  1565,
       5,  1566,    -1,  1468,   676,  1472,    -1,  1468,   676,    20,
      -1,  1569,    -1,  1569,    -1,   252,  1570,    -1,  1570,    -1,
    1571,    -1,    25,   676,  1571,    -1,  1572,    -1,  1571,   676,
    1572,    -1,  1571,   676,    20,    -1,  1574,    -1,  1012,    -1,
    1568,    -1,  1568,   479,  1568,    -1,  1012,  1575,    -1,   517,
    1576,   485,    -1,   517,  1576,   485,   517,  1576,   485,    -1,
    1577,    -1,  1576,     5,  1577,    -1,   747,    -1,    34,    -1,
      -1,    -1,   584,  1580,   917,  1581,  1594,   387,    -1,    -1,
     715,   960,    -1,    -1,   718,    -1,   243,    -1,   337,  1007,
      -1,   132,  1007,    -1,   367,    -1,   366,    -1,   368,  1009,
    1582,  1583,    -1,   550,   960,  1583,    -1,   166,    -1,   197,
    1007,    -1,   917,   623,     5,   917,   453,    -1,   566,   917,
      -1,   324,  1007,    -1,   163,  1589,     8,  1590,  1588,    -1,
      -1,   603,   917,    -1,  1012,    -1,  1012,    -1,   308,  1007,
      -1,   311,  1007,   682,   917,     5,   917,    -1,   311,  1007,
     675,   917,     5,   917,    -1,    27,    -1,    -1,  1596,    -1,
    1597,  1279,    -1,  1595,    -1,  1596,  1595,    -1,    -1,  1598,
    1599,    -1,   740,    -1,   741,    -1,   742,    -1,   743,    -1,
     760,    -1,   784,    -1,   805,    -1,   806,    -1,   812,    -1,
     831,    -1,   889,    -1,   890,    -1,   891,    -1,   892,    -1,
     903,    -1,   904,    -1,   905,    -1,   906,    -1,   907,    -1,
     908,    -1,   909,    -1,   962,    -1,   993,    -1,   997,    -1,
    1019,    -1,  1021,    -1,  1024,    -1,  1025,    -1,  1026,    -1,
    1027,    -1,  1040,    -1,  1050,    -1,  1074,    -1,  1075,    -1,
    1077,    -1,  1081,    -1,  1096,    -1,  1097,    -1,  1101,    -1,
    1102,    -1,  1103,    -1,  1104,    -1,  1114,    -1,  1129,    -1,
    1145,    -1,  1156,    -1,  1157,    -1,  1158,    -1,  1162,    -1,
    1199,    -1,  1202,    -1,  1204,    -1,  1210,    -1,  1211,    -1,
    1214,    -1,  1217,    -1,  1222,    -1,  1224,    -1,  1226,    -1,
    1229,    -1,  1236,    -1,  1241,    -1,  1242,    -1,  1244,    -1,
    1247,    -1,  1248,    -1,  1249,    -1,  1261,    -1,  1315,    -1,
    1317,    -1,  1319,    -1,  1338,    -1,  1339,    -1,  1359,    -1,
    1362,    -1,  1391,    -1,  1393,    -1,  1484,    -1,  1485,    -1,
    1516,    -1,  1517,    -1,  1539,    -1,  1563,    -1,  1578,    -1,
    1579,    -1,  1584,    -1,  1585,    -1,  1587,    -1,  1591,    -1,
    1592,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,  1015,  1015,  1018,  1021,  1027,  1033,  1040,  1044,  1044,
    1050,  1069,  1070,  1071,  1072,  1073,  1084,  1090,  1091,  1092,
    1093,  1094,  1099,  1100,  1111,  1114,  1117,  1117,  1123,  1126,
    1127,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1152,  1153,
    1156,  1156,  1173,  1174,  1177,  1183,  1185,  1196,  1198,  1200,
    1202,  1206,  1208,  1270,  1274,  1278,  1278,  1288,  1292,  1295,
    1296,  1305,  1311,  1305,  1325,  1331,  1325,  1347,  1352,  1356,
    1347,  1368,  1372,  1368,  1380,  1385,  1380,  1404,  1411,  1415,
    1403,  1441,  1441,  1445,  1446,  1447,  1452,  1455,  1460,  1464,
    1472,  1473,  1476,  1476,  1482,  1486,  1501,  1499,  1517,  1517,
    1532,  1532,  1535,  1535,  1539,  1542,  1542,  1542,  1549,  1550,
    1549,  1557,  1557,  1568,  1568,  1581,  1605,  1615,  1581,  1631,
    1636,  1644,  1645,  1649,  1650,  1651,  1662,  1665,  1668,  1671,
    1674,  1677,  1690,  1695,  1695,  1696,  1696,  1699,  1704,  1704,
    1708,  1727,  1732,  1726,  1743,  1749,  1757,  1758,  1761,  1761,
    1764,  1768,  1773,  1780,  1780,  1784,  1784,  1785,  1785,  1786,
    1786,  1787,  1787,  1788,  1788,  1796,  1800,  1806,  1810,  1825,
    1828,  1831,  1834,  1837,  1840,  1846,  1857,  1862,  1875,  1879,
    1892,  1895,  1904,  1905,  1910,  1913,  1910,  1916,  1916,  1921,
    1922,  1927,  1927,  1943,  1948,  1953,  1958,  1963,  1964,  1981,
    1982,  1983,  1984,  1992,  2002,  2003,  2007,  2008,  2013,  2016,
    2020,  2024,  2032,  2032,  2037,  2037,  2042,  2042,  2055,  2056,
    2061,  2062,  2067,  2072,  2077,  2082,  2090,  2095,  2096,  2100,
    2108,  2108,  2117,  2117,  2129,  2129,  2145,  2146,  2154,  2159,
    2163,  2164,  2168,  2173,  2174,  2175,  2179,  2183,  2190,  2197,
    2201,  2205,  2209,  2213,  2216,  2219,  2228,  2237,  2241,  2245,
    2249,  2255,  2261,  2267,  2273,  2279,  2285,  2285,  2289,  2289,
    2293,  2293,  2297,  2301,  2305,  2309,  2313,  2317,  2321,  2325,
    2358,  2359,  2364,  2373,  2382,  2385,  2394,  2402,  2402,  2414,
    2418,  2422,  2426,  2430,  2434,  2438,  2447,  2447,  2460,  2464,
    2474,  2478,  2487,  2498,  2498,  2508,  2512,  2516,  2520,  2524,
    2528,  2532,  2541,  2545,  2546,  2557,  2561,  2564,  2567,  2568,
    2569,  2570,  2571,  2576,  2583,  2589,  2594,  2599,  2594,  2612,
    2614,  2619,  2624,  2624,  2624,  2628,  2628,  2631,  2631,  2638,
    2638,  2645,  2645,  2656,  2674,  2680,  2704,  2707,  2722,  2725,
    2738,  2740,  2742,  2744,  2746,  2748,  2750,  2756,  2758,  2762,
    2764,  2766,  2768,  2770,  2772,  2774,  2780,  2797,  2798,  2799,
    2800,  2804,  2805,  2806,  2810,  2815,  2822,  2823,  2824,  2825,
    2826,  2827,  2828,  2829,  2830,  2831,  2832,  2839,  2839,  2844,
    2844,  2847,  2853,  2861,  2867,  2877,  2878,  2886,  2907,  2911,
    2916,  2921,  2923,  2926,  2944,  2949,  2955,  2960,  2965,  2966,
    2972,  3040,  3051,  3060,  3068,  3068,  3083,  3087,  3094,  3097,
    3105,  3109,  3112,  3118,  3127,  3132,  3140,  3143,  3146,  3151,
    3158,  3163,  3168,  3173,  3183,  3191,  3199,  3204,  3208,  3213,
    3217,  3221,  3228,  3231,  3234,  3238,  3242,  3246,  3250,  3258,
    3268,  3273,  3266,  3288,  3293,  3288,  3307,  3312,  3307,  3333,
    3333,  3333,  3336,  3336,  3336,  3340,  3340,  3340,  3344,  3344,
    3344,  3348,  3354,  3360,  3366,  3374,  3380,  3388,  3394,  3403,
    3409,  3416,  3423,  3432,  3438,  3444,  3451,  3457,  3463,  3469,
    3477,  3483,  3489,  3498,  3504,  3510,  3520,  3520,  3524,  3528,
    3529,  3540,  3541,  3547,  3557,  3567,  3577,  3578,  3581,  3586,
    3592,  3596,  3600,  3603,  3609,  3612,  3615,  3632,  3635,  3641,
    3642,  3643,  3647,  3648,  3649,  3650,  3651,  3653,  3654,  3655,
    3657,  3658,  3659,  3663,  3664,  3669,  3673,  3678,  3682,  3697,
    3701,  3707,  3696,  3720,  3721,  3733,  3739,  3733,  3754,  3754,
    3756,  3757,  3761,  3761,  3765,  3765,  3770,  3770,  3777,  3778,
    3782,  3782,  3786,  3786,  3791,  3791,  3798,  3802,  3803,  3804,
    3809,  3809,  3812,  3812,  3816,  3816,  3820,  3820,  3824,  3824,
    3829,  3829,  3834,  3834,  3839,  3839,  3844,  3844,  3860,  3864,
    3859,  3872,  3875,  3889,  3906,  3907,  3908,  3909,  3910,  3911,
    3912,  3915,  3915,  3918,  3920,  3923,  3926,  3929,  3934,  3939,
    3942,  3947,  3952,  3957,  3964,  3965,  3972,  3979,  3981,  3987,
    3992,  3997,  4002,  4002,  4005,  4011,  4016,  4019,  4026,  4026,
    4028,  4031,  4034,  4039,  4044,  4049,  4056,  4067,  4067,  4129,
    4137,  4138,  4146,  4153,  4153,  4157,  4162,  4168,  4172,  4176,
    4182,  4186,  4190,  4196,  4196,  4208,  4209,  4213,  4213,  4217,
    4218,  4221,  4224,  4224,  4227,  4229,  4229,  4232,  4234,  4234,
    4235,  4237,  4237,  4246,  4253,  4244,  4274,  4274,  4274,  4277,
    4279,  4277,  4286,  4289,  4296,  4301,  4312,  4312,  4316,  4322,
    4322,  4326,  4327,  4331,  4341,  4342,  4343,  4346,  4348,  4353,
    4353,  4357,  4356,  4364,  4363,  4370,  4370,  4376,  4376,  4383,
    4383,  4389,  4389,  4395,  4395,  4401,  4401,  4405,  4405,  4406,
    4406,  4407,  4407,  4408,  4408,  4412,  4412,  4423,  4427,  4433,
    4437,  4442,  4447,  4452,  4453,  4454,  4458,  4457,  4470,  4475,
    4480,  4480,  4496,  4502,  4503,  4504,  4505,  4506,  4516,  4530,
    4530,  4533,  4540,  4541,  4542,  4543,  4544,  4545,  4546,  4547,
    4548,  4553,  4553,  4555,  4558,  4558,  4560,  4564,  4567,  4568,
    4571,  4571,  4576,  4579,  4580,  4581,  4582,  4583,  4584,  4585,
    4586,  4587,  4588,  4589,  4590,  4591,  4592,  4593,  4594,  4595,
    4596,  4600,  4618,  4618,  4618,  4645,  4656,  4663,  4669,  4675,
    4681,  4693,  4716,  4717,  4720,  4724,  4723,  4741,  4741,  4745,
    4746,  4754,  4755,  4756,  4757,  4758,  4759,  4760,  4767,  4768,
    4770,  4771,  4775,  4780,  4781,  4782,  4783,  4784,  4785,  4786,
    4787,  4788,  4791,  4793,  4793,  4795,  4799,  4799,  4808,  4814,
    4830,  4836,  4807,  4850,  4864,  4875,  4863,  4888,  4895,  4895,
    4900,  4906,  4914,  4919,  4920,  4923,  4926,  4926,  4934,  4940,
    4951,  4952,  4960,  4966,  4960,  4977,  4978,  4982,  4982,  4989,
    4989,  5004,  5004,  5018,  5029,  5028,  5040,  5036,  5053,  5050,
    5063,  5063,  5065,  5066,  5068,  5069,  5072,  5073,  5074,  5076,
    5081,  5086,  5092,  5094,  5095,  5098,  5099,  5102,  5104,  5111,
    5114,  5117,  5120,  5124,  5128,  5129,  5130,  5131,  5132,  5136,
    5141,  5141,  5144,  5171,  5229,  5229,  5232,  5236,  5240,  5283,
    5325,  5326,  5327,  5330,  5344,  5356,  5356,  5361,  5362,  5368,
    5433,  5438,  5445,  5450,  5458,  5464,  5497,  5500,  5501,  5542,
    5585,  5586,  5590,  5591,  5595,  5648,  5653,  5657,  5662,  5673,
    5680,  5688,  5688,  5691,  5692,  5693,  5694,  5695,  5698,  5701,
    5707,  5710,  5714,  5719,  5727,  5732,  5739,  5741,  5747,  5749,
    5749,  5749,  5769,  5776,  5783,  5786,  5800,  5807,  5808,  5811,
    5812,  5816,  5822,  5827,  5833,  5834,  5839,  5843,  5843,  5847,
    5848,  5851,  5852,  5856,  5864,  5867,  5873,  5874,  5876,  5878,
    5882,  5882,  5883,  5888,  5896,  5897,  5902,  5903,  5905,  5918,
    5920,  5921,  5924,  5925,  5926,  5927,  5928,  5929,  5930,  5931,
    5932,  5933,  5934,  5935,  5936,  5937,  5938,  5939,  5940,  5941,
    5942,  5943,  5944,  5945,  5946,  5947,  5948,  5949,  5950,  5951,
    5955,  5956,  5960,  5961,  5975,  5983,  5983,  5985,  5989,  5993,
    5997,  6001,  6006,  6021,  6019,  6039,  6040,  6044,  6049,  6050,
    6054,  6055,  6057,  6058,  6060,  6060,  6069,  6078,  6078,  6088,
    6089,  6094,  6095,  6098,  6111,  6125,  6129,  6133,  6137,  6141,
    6145,  6155,  6158,  6163,  6163,  6167,  6172,  6175,  6175,  6177,
    6183,  6188,  6193,  6198,  6207,  6213,  6215,  6219,  6222,  6222,
    6225,  6225,  6230,  6230,  6239,  6239,  6243,  6243,  6244,  6244,
    6245,  6245,  6259,  6259,  6279,  6280,  6281,  6282,  6283,  6284,
    6287,  6287,  6295,  6295,  6298,  6298,  6316,  6317,  6318,  6327,
    6339,  6340,  6343,  6344,  6347,  6350,  6350,  6355,  6355,  6378,
    6379,  6385,  6390,  6396,  6397,  6398,  6402,  6403,  6404,  6405,
    6409,  6419,  6421,  6426,  6429,  6434,  6440,  6447,  6454,  6463,
    6470,  6477,  6484,  6491,  6500,  6500,  6502,  6502,  6505,  6506,
    6507,  6508,  6509,  6510,  6511,  6512,  6513,  6514,  6517,  6517,
    6520,  6521,  6522,  6523,  6526,  6526,  6529,  6529,  6532,  6533,
    6534,  6535,  6536,  6537,  6538,  6539,  6541,  6542,  6543,  6544,
    6546,  6547,  6548,  6549,  6551,  6552,  6553,  6554,  6555,  6556,
    6557,  6558,  6562,  6570,  6580,  6593,  6604,  6615,  6619,  6623,
    6629,  6592,  6642,  6645,  6653,  6665,  6667,  6672,  6682,  6692,
    6695,  6699,  6707,  6671,  6716,  6720,  6724,  6728,  6720,  6738,
    6739,  6740,  6741,  6746,  6747,  6748,  6749,  6750,  6751,  6752,
    6753,  6757,  6758,  6761,  6766,  6773,  6774,  6775,  6780,  6781,
    6787,  6787,  6787,  6792,  6792,  6792,  6800,  6801,  6805,  6806,
    6811,  6812,  6813,  6814,  6815,  6818,  6820,  6820,  6823,  6824,
    6828,  6829,  6832,  6833,  6836,  6839,  6842,  6848,  6849,  6861,
    6862,  6867,  6868,  6869,  6873,  6876,  6882,  6885,  6893,  6894,
    6900,  6904,  6908,  6914,  6917,  6926,  6929,  6932,  6935,  6938,
    6941,  6944,  6951,  6954,  6961,  6964,  6970,  6973,  6980,  6983,
    6990,  6991,  6996,  7000,  7003,  7009,  7012,  7018,  7025,  7026,
    7030,  7040,  7043,  7049,  7051,  7056,  7057,  7061,  7063,  7069,
    7070,  7083,  7095,  7096,  7097,  7098,  7099,  7100,  7101,  7102,
    7103,  7106,  7109,  7115,  7115,  7121,  7121,  7132,  7145,  7155,
    7155,  7160,  7160,  7164,  7168,  7169,  7175,  7176,  7181,  7185,
    7192,  7195,  7202,  7201,  7212,  7216,  7220,  7227,  7230,  7230,
    7243,  7247,  7247,  7262,  7264,  7266,  7268,  7270,  7272,  7274,
    7276,  7282,  7292,  7299,  7304,  7305,  7309,  7312,  7313,  7316,
    7317,  7318,  7321,  7326,  7333,  7334,  7341,  7353,  7354,  7355,
    7358,  7358,  7363,  7368,  7373,  7378,  7379,  7382,  7383,  7388,
    7393,  7397,  7402,  7403,  7407,  7414,  7415,  7416,  7417,  7422,
    7423,  7424,  7427,  7428,  7429,  7433,  7434,  7435,  7439,  7440,
    7444,  7445,  7446,  7447,  7448,  7449,  7452,  7453,  7458,  7459,
    7464,  7465,  7470,  7471,  7476,  7481,  7482,  7487,  7488,  7492,
    7493,  7498,  7505,  7510,  7515,  7519,  7520,  7525,  7526,  7532,
    7535,  7539,  7544,  7545,  7551,  7554,  7557,  7564,  7565,  7566,
    7567,  7581,  7586,  7587,  7590,  7592,  7599,  7602,  7608,  7616,
    7620,  7624,  7628,  7633,  7636,  7639,  7646,  7653,  7658,  7662,
    7663,  7669,  7672,  7683,  7690,  7696,  7699,  7706,  7713,  7719,
    7720,  7726,  7727,  7728,  7731,  7732,  7739,  7746,  7746,  7750,
    7758,  7759,  7762,  7765,  7770,  7771,  7776,  7779,  7785,  7788,
    7794,  7797,  7803,  7806,  7813,  7814,  7843,  7844,  7848,  7856,
    7861,  7864,  7867,  7870,  7876,  7877,  7881,  7884,  7887,  7888,
    7893,  7896,  7899,  7902,  7905,  7908,  7911,  7914,  7919,  7925,
    7926,  7927,  7928,  7931,  7932,  7933,  7938,  7941,  7945,  7951,
    7952,  7953,  7954,  7966,  7967,  7968,  7972,  7973,  7977,  7978,
    7979,  7980,  7981,  7983,  7992,  7999,  8000,  8001,  8002,  8003,
    8004,  8005,  8007,  8009,  8011,  8012,  8014,  8015,  8017,  8018,
    8019,  8020,  8022,  8026,  8027,  8033,  8035,  8036,  8037,  8038,
    8043,  8047,  8051,  8055,  8062,  8066,  8067,  8068,  8076,  8077,
    8078,  8089,  8096,  8101,  8102,  8103,  8111,  8112,  8113,  8130,
    8139,  8140,  8141,  8145,  8148,  8153,  8158,  8163,  8171,  8175,
    8180,  8181,  8189,  8192,  8195,  8209,  8223,  8236,  8237,  8241,
    8241,  8241,  8241,  8241,  8241,  8242,  8245,  8262,  8262,  8262,
    8262,  8262,  8262,  8262,  8263,  8263,  8263,  8263,  8263,  8263,
    8263,  8263,  8266,  8267,  8268,  8271,  8280,  8280,  8286,  8286,
    8293,  8293,  8299,  8299,  8307,  8308,  8309,  8312,  8312,  8315,
    8316,  8317,  8328,  8331,  8337,  8342,  8349,  8362,  8363,  8360,
    8381,  8392,  8395,  8400,  8412,  8415,  8419,  8422,  8423,  8433,
    8436,  8437,  8446,  8455,  8460,  8461,  8462,  8463,  8470,  8473,
    8479,  8482,  8489,  8501,  8510,  8513,  8516,  8522,  8530,  8533,
    8534,  8535,  8536,  8537,  8540,  8546,  8548,  8550,  8552,  8554,
    8556,  8557,  8558,  8559,  8560,  8561,  8562,  8564,  8566,  8568,
    8570,  8572,  8574,  8576,  8577,  8579,  8580,  8586,  8587,  8594,
    8597,  8605,  8609,  8616,  8616,  8620,  8620,  8625,  8625,  8629,
    8629,  8633,  8639,  8639,  8642,  8642,  8648,  8655,  8656,  8657,
    8661,  8662,  8665,  8666,  8670,  8676,  8686,  8687,  8695,  8696,
    8697,  8698,  8699,  8700,  8704,  8705,  8706,  8707,  8711,  8712,
    8716,  8732,  8733,  8734,  8738,  8752,  8752,  8764,  8765,  8769,
    8770,  8771,  9095,  9095,  9102,  9102,  9190,  9194,  9190,  9203,
    9207,  9213,  9221,  9231,  9241,  9253,  9256,  9275,  9301,  9304,
    9310,  9313,  9318,  9321,  9329,  9337,  9350,  9353,  9361,  9364,
    9367,  9375,  9379,  9380,  9381,  9382,  9383,  9384,  9385,  9386,
    9390,  9391,  9392,  9393,  9394,  9400,  9401,  9402,  9403,  9404,
    9405,  9406,  9407,  9408,  9409,  9410,  9411,  9412,  9413,  9414,
    9415,  9420,  9426,  9427,  9435,  9435,  9443,  9443,  9447,  9451,
    9466,  9481,  9487,  9489,  9497,  9498,  9502,  9503,  9506,  9513,
    9516,  9545,  9571,  9625,  9661,  9670,  9681,  9684,  9689,  9703,
    9717,  9720,  9716,  9739,  9739,  9745,  9746,  9749,  9750,  9751,
    9752,  9753,  9754,  9755,  9766,  9769,  9774,  9778,  9783,  9787,
    9792,  9796,  9799,  9803,  9806,  9811,  9815,  9826,  9832,  9832,
    9833,  9834,  9841,  9851,  9851,  9853,  9854,  9855,  9856,  9857,
    9858,  9859,  9860,  9861,  9862,  9863,  9864,  9865,  9866,  9867,
    9868,  9869,  9870,  9871,  9872,  9873,  9874,  9875,  9876,  9877,
    9878,  9879,  9880,  9881,  9882,  9883,  9884,  9885,  9886,  9887,
    9888,  9889,  9890,  9891,  9892,  9893,  9894,  9895,  9896,  9897,
    9898,  9899,  9900,  9901,  9902,  9903,  9904,  9905,  9906,  9907,
    9908,  9909,  9910,  9911,  9912,  9913,  9914,  9915,  9916,  9917,
    9918,  9919,  9920,  9921,  9922,  9923,  9924,  9925,  9926,  9927,
    9928,  9929,  9930,  9931,  9932,  9933,  9934,  9935,  9936,  9937,
    9938,  9939,  9940,  9941,  9942
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
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "DEFINE_NEW_TYPE", 
  "CREATE_DATABASE", "DROP_DATABASE", "IMPORT_LEGACY_FUNCTION", 
  "ADD_CONSTRAINT", "DROP_CONSTRAINT", "DROP_SYNONYM", "CONSTRAINT", 
  "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "KWUP_BY", "KWDOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_SCREEN", "TO_PRINTER", "STATUSBOX", 
  "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", 
  "UNITS_SECOND", "NO_NEW_LINES", "FIELDTOWIDGET", "WITH_HOLD", 
  "SHOW_MENU", "TO_CLUSTER", "TO_NOT_CLUSTER", "CWIS", "CREATE_IDX", 
  "FORM_IS_COMPILED", "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", 
  "POINTS", "MM", "INCHES", "PREPEND", "MEMBER_OF", "APPEND", "TEMPLATE", 
  "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", "SQLSIRR", "UPDATESTATS_T", 
  "SQLSICR", "WHENEVER_SQLSUCCESS", "WHENEVER_SQLWARNING", 
  "WHENEVER_ANY_ERROR", "WHENEVER_NOT_FOUND", "WHENEVER_SQLERROR", 
  "WHENEVER_SUCCESS", "WHENEVER_ERROR", "START_EXTERN", 
  "CONTINUE_CONSTRUCT", "FOUNCONSTR", "SQLSIDR", "CREATE_TEMP_TABLE", 
  "CURRENT_WINDOW_IS", "FIRST_PAGE_HEADER", "ORDER_EXTERNAL_BY", 
  "SCROLL_CURSOR_FOR", "SCROLL_CURSOR", "SQL_INTERRUPT_OFF", 
  "STOP_ALL_EXTERNAL", "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", 
  "SQLSLMNW", "ADDCONSTUNIQ", "CONTINUE_DISPLAY", "CONTINUE_FOREACH", 
  "OUTPUT_TO_REPORT", "SQL_INTERRUPT_ON", "WHERE_CURRENT_OF", 
  "WITHOUT_DEFAULTS", "FOCONSTR", "SCALED_BY", "CONTINUE_PROMPT", 
  "PDF_FUNCTION", "DEFER_INTERRUPT", "DISPLAY_BY_NAME", "NOT_NULL_UNIQUE", 
  "SKIP_TO_TOP", "TOP_OF_PAGE", "SKIP_TO", "SKIP_BY", "WITHOUT_WAITING", 
  "BEFCONSTRUCT", "SQLSLMW", "AFTCONSTRUCT", "ALL_PRIVILEGES", 
  "CLOSE_DATABASE", "CONTINUE_INPUT", "CONTINUE_WHILE", "CREATE_SYNONYM", 
  "DROP_TABLE", "EXIT_CONSTRUCT", "INEXCLUSIVE", "REPORT_TO_PRINTER", 
  "REPORT_TO_PIPE", "RETURN", "SET_SESSION_TO", "UPDATESTATS", 
  "WITHOUT_HEAD", "CLEARSCR", "WITH_B_LOG", "AUTHORIZATION", 
  "BOTTOM_MARGIN", "CLOSE_SESSION", "CONTINUE_CASE", "CONTINUE_MENU", 
  "DISPLAY_ARRAY", "END_SQL", "DOLLAR", "END_CONSTRUCT", "FIELD_TOUCHED", 
  "FINISH_REPORT", "INFACC", "INPUT_NO_WRAP", "SETPMOFF", "UNCONSTRAINED", 
  "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", 
  "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", "DEFAULT_NULL", 
  "DEFAULT_TODAY", "DEFAULT_USER", "DELETE_USING", "DISPLAY_FORM", 
  "END_FUNCTION", "EXIT_DISPLAY", "EXIT_FOREACH", "EXIT_PROGRAM", 
  "INFCOLS", "ON_EVERY_ROW", "OPEN_SESSION", "RIGHT_MARGIN", 
  "SELECT_USING", "START_REPORT", "UNLOCK_TABLE", "UPDATE_USING", 
  "ACL_BUILTIN", "AFTGROUP", "INFIDX", "INFSTAT", "LEFT_MARGIN", 
  "PAGE_HEADER", "ROLLBACK_W", "SET_SESSION", "SQLSEOFF", "WITH_A_LOG", 
  "BEFDISP", "BEFORE_MENU", "CREATE_VIEW", "DELETE_FROM", "END_DISPLAY", 
  "END_REPORT", "END_FOREACH", "END_FOR", "END_GLOBALS", "EXIT_PROMPT", 
  "EXTENT_SIZE", "FOREIGN_KEY", "HIDE_OPTION", "HIDE_WINDOW", 
  "INSERT_INTO", "IS_NOT_NULL", "MOVE_WINDOW", "NEXT_OPTION", 
  "NOT_MATCHES", "ON_LAST_ROW", "OPEN_WINDOW", "OPEN_STATUSBOX", 
  "PAGE_LENGTH", "PAGE_WIDTH", "PRIMARY_KEY", "PROMPT_LINE", 
  "RECORD_LIKE", "ROLLFORWARD", "SHOW_OPTION", "SHOW_WINDOW", "SQLSEON", 
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
  "SCROLL", "SECOND", "SELECT", "SERIAL", "SHARED", "SPACES", "UNIQUE", 
  "UNLOCK", "UPDATE", "VALUES", "YELLOW", "AFTER", "KWLINE", "KW_NULL", 
  "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", "ASCII", "AUDIT", "BLACK", 
  "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", "COUNT", "DEFER", "ERROR", 
  "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", "FOUND", "GRANT", "GREEN", 
  "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", "MONEY", "MONTH", "ORDER", 
  "OUTER", "PAUSE", "PRINT_IMAGE", "PRINT_FILE", "PRINT", "RIGHT", 
  "DOUBLE_COLON", "SEMICOLON", "SLEEP", "TUPLE", "UNION", "WHERE", 
  "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", "FCALL", 
  "CASE", "CYAN", "DATE", "DESC", "KWDOWN", "TAB", "DROP", "ELSE", "EXEC", 
  "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", 
  "HIDE", "HOUR", "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", 
  "NEED", "NEXT", "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", "SIZE", 
  "SKIP", "SOME", "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", "WAIT", 
  "WHEN", "WITH", "WORK", "YEAR", "KW_IS", "XSET", "ADD", "ALL", "ANY", 
  "ASC", "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", 
  "KWNO", "LET", "LOG", "XMAX", "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", 
  "SQL", "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", 
  "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", 
  "KWUP", "FONT_NAME", "FONT_SIZE", "PAPER_SIZE_IS_LETTER", 
  "PAPER_SIZE_IS_LEGAL", "PAPER_SIZE_IS_A5", "PAPER_SIZE_IS_A4", 
  "PAPER_SIZE_IS_LETTER_L", "PAPER_SIZE_IS_LEGAL_L", "PAPER_SIZE_IS_A5_L", 
  "PAPER_SIZE_IS_A4_L", "FORMHANDLER", "END_FORMHANDLER", "BEFORE_EVENT", 
  "BEFORE_OPEN_FORM", "AFTER_EVENT", "BEFORE_CLOSE_FORM", "BEFORE_ANY", 
  "AFTER_ANY", "MENUHANDLER", "END_MENUHANDLER", "BEFORE_SHOW_MENU", 
  "DISABLE_PROGRAM", "DISABLE_ALL", "BUTTONS", "CHECK_MENUITEM", 
  "DISABLE_FORM", "DISABLE_MENUITEMS", "DISABLE", "ENABLE_FORM", 
  "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", "ICON", "MESSAGEBOX", 
  "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", 
  "INT_TO_ID", "TIMEOUT", "OFF", "WITH_1_DIMENSION", "WITH_2_DIMENSION", 
  "WITH_3_DIMENSION", "TILDE", "ILIKE", "FGL_ISDYNARR_ALLOCATED", 
  "FGL_DYNARR_EXTENTSIZE", "FILLFACTOR", "END_CLASS", "KW_CLASS", 
  "EXTENDS", "PIPE", "FORMHANDLER_INPUT", "$accept", 
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
  "define_section", "define_multiple", "define_set", "@34", "@35", "@36", 
  "def_part", "define_ident", "@37", "def_part2", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@38", "@39", "@40", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "define_table_name", "record_variable", "@41", "@42", "@43", 
  "link_to_pk_list", "link_to_pk", "dtype_ident", "op_as_static", 
  "dtype2", "dtype", "@44", "@45", "@46", "op_prec", "like_var", 
  "col_name", "datetime_qual", "interval_qual", "dtime_start", "@47", 
  "dtime_val", "dtime_end", "@48", "opt_frac", "opt_unit_size", "dtfrac", 
  "int_start", "@49", "int_start_unit", "int_end", "op_equal", "opt_at", 
  "display_b_n_cmd", "display_cmd", "display_form_cmd", 
  "display_array_cmd", "@50", "@51", "opt_scroll", "display_attr", 
  "disp_rest", "disp_field_commands", "disp_field_command", "@52", "@53", 
  "@54", "alloc_arr_cmd", "dealloc_arr_cmd", "resize_arr_cmd", 
  "error_cmd", "exit_prog_cmd", "ext_cmd", "continue_cmd", "fgl_expr_c", 
  "fgl_next", "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "boolean_expr", 
  "literal_expr", "variable_entry_2", "variable_entry", 
  "report_only_expr", "@55", "and_or_expr", "inexpr_list", "in_expr", 
  "null_expr", "string_match_expr", "clip_expr", "using_expr", 
  "math_expr", "comparison_expr", "reset_cnt", "function_call_expr2", 
  "@56", "@57", "@58", "@59", "@60", "@61", "function_callb", "@62", 
  "@63", "@64", "@65", "@66", "@67", "@68", "@69", "op_extend_d", 
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
  "import_package", "module_import", "init_cmd", "@92", "init_tab_list", 
  "init_tab", "init_table_name", "end_input", "opt_defs", 
  "field_commands", "field_command", "@93", "@94", "@95", "@96", "@97", 
  "@98", "@99", "@100", "@101", "@102", "@103", "@104", "@105", 
  "bef_field_list_as_struct", "aft_field_list_as_struct", 
  "next_field_cmd", "next_form_cmd", "next_field", "input_cmd", "@106", 
  "inp_rest", "@107", "scroll_cmd", "up_or_down", "op_help", 
  "input_array_attributes", "input_array_attributes_int", 
  "on_key_command", "@108", "key_val", "@109", "accept_key", 
  "single_key_val", "key_do", "key_value_list", "key_value", 
  "key_value_1", "label_cmd", "let_cmd", "@110", "@111", "op_expr_null", 
  "linked_cmd", "linked_del_cmd", "linked_upd_cmd", "locate_cmd", 
  "module", "class_module", "trad_module", "@112", "op_module_header", 
  "module_header", "module_entry", "func_main_def", "func_or_main2", 
  "at_term_cmd", "func_or_main", "module_code", "op_code", 
  "module_define_section", "ldeffunction", "func_def", "@113", "@114", 
  "@115", "@116", "end_func_command", "main_def", "@117", "@118", 
  "return_cmd", "op_fgl_expr_list", "db_section", 
  "module_globals_section", "actual_globals_section", "xglobals_entry", 
  "globals_entry", "@119", "glob_section", "menu_def", "@120", "@121", 
  "menu_handler_elements", "menu_handler_element", "@122", "@123", 
  "menu_cmd", "@124", "end_menu_command", "menu_block_command", "@125", 
  "@126", "@127", "menu_commands", "opt_key", "menu_opt_name", 
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
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@128", 
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@129", "prompt_title", 
  "put_cmd", "@130", "put_from", "put_val_list", "put_val", "start_cmd", 
  "convert_cmd", "rout", "free_rep_cmd", "rep_name", "op_values", 
  "output_cmd", "finish_cmd", "term_rep_cmd", "report_section", 
  "format_section", "format_actions", "format_action", "@131", "@132", 
  "@133", "@134", "@135", "@136", "@137", "report_cmd", "need_command", 
  "@138", "op_lines", "skip_command", "@139", "opt_rep_expr_list", 
  "xrep_expr_list", "xxrep_expr_list", "opt_print_at", "print_command", 
  "@140", "pf_char_or_var", "print_file_command", "print_img_command", 
  "opt_scaling", "img_types", "blob_var", "opt_semi", "rep_expr_list", 
  "rep_expr", "rep_agg", "op_output_section", "output_commands", 
  "output_command", "pdf_output_commands", "nval", "nval_number", 
  "pdf_op_output_section", "pdf_output_command", "op_rep_order_by", 
  "report_def", "@141", "@142", "@143", "@144", "@145", "@146", 
  "rep_where", "pause_command", "pause_msg", "pdf_report_def", "@147", 
  "@148", "@149", "@150", "@151", "@152", "pdf_report_section", 
  "pdf_functions", "@153", "@154", "@155", "op_wordwrap", "run_cmd", 
  "run_mode", "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", 
  "@156", "@157", "@158", "@159", "opt_cr_table_extra", "cr_table_extra", 
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
  "@160", "ins_2_ss", "@161", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@162", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@163", "opt_foreach_into_fetch_part", "@164", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@165", 
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
  "dbase_name", "flush_cmd", "declare_cmd", "@166", "@167", "@168", 
  "@169", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@170", "@171", 
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
  "sql_block_cmd", "@172", "sql_block", "sql_block_entry", "in_var", 
  "@173", "sql_block_into", "@174", "update_statement_ss", "@175", "@176", 
  "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "validate_cmd", 
  "@177", "validate_tab_list", "validate_tab", "var_ident", 
  "var2_as_string", "var2_vu", "var3_vu", "var4_vu", "var4_item_vu", 
  "var_ident_ibind_ss", "array_r_variable_or_ident_vu", 
  "arr_subscripts_al", "num_list_nl", "num_list_element_nl", 
  "whenever_cmd", "while_cmd", "@178", "@179", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "current_win_cmd", "window_type", "show_cmd", 
  "op_mnfile", "menu_name", "menu_handler", "hide_cmd", "move_cmd", 
  "NAMED", "commands", "all_commands", "command1", "commands_all", "@180", 
  "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1722,  1723,  1724,  1624,  1664,  1619,  1556,  1639,
    1437,  1542,  1538,  1454,  1614,  1356,  1413,  1485,  1650,  1637,
    1543,  1570,  1638,  1420,  1725,  1726,  1727,  1728,  1729,  1730,
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
    1354,  1355,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,  1414,  1415,
    1416,  1417,  1418,  1419,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1482,  1483,  1484,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,
    1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1539,  1540,
    1541,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,
    1553,  1554,  1555,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1615,
    1616,  1617,  1618,  1620,  1621,  1622,  1623,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1640,
    1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1651,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
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
     802,   803,   803,   804,   804,   804,   805,   805,   805,   805,
     805,   805,   806,   807,   807,   808,   808,   809,   810,   810,
     811,   813,   814,   812,   815,   815,   816,   816,   817,   817,
     818,   818,   818,   819,   819,   821,   820,   822,   820,   823,
     820,   824,   820,   825,   820,   826,   826,   827,   827,   828,
     828,   828,   828,   828,   828,   829,   830,   830,   831,   831,
     832,   832,   833,   833,   835,   836,   834,   837,   834,   838,
     838,   840,   839,   841,   841,   841,   841,   841,   841,   842,
     842,   842,   842,   843,   844,   844,   845,   845,   846,   846,
     846,   846,   848,   847,   849,   847,   850,   847,   851,   851,
     852,   852,   853,   854,   854,   854,   855,   856,   856,   856,
     858,   857,   859,   857,   860,   857,   861,   861,   862,   863,
     864,   864,   865,   866,   866,   866,   866,   866,   866,   866,
     866,   866,   866,   866,   866,   866,   866,   866,   866,   866,
     866,   866,   866,   866,   866,   866,   867,   866,   868,   866,
     869,   866,   866,   866,   866,   866,   866,   866,   866,   866,
     870,   870,   871,   872,   873,   873,   874,   876,   875,   877,
     877,   877,   877,   877,   877,   877,   879,   878,   880,   880,
     881,   881,   882,   884,   883,   885,   885,   885,   885,   885,
     885,   885,   886,   887,   887,   888,   888,   888,   888,   888,
     888,   888,   888,   889,   890,   891,   893,   894,   892,   895,
     895,   896,   897,   897,   897,   898,   898,   900,   899,   901,
     899,   902,   899,   903,   904,   905,   906,   906,   907,   907,
     908,   908,   908,   908,   908,   908,   908,   908,   908,   909,
     909,   909,   909,   909,   909,   909,   909,   910,   910,   910,
     910,   910,   910,   910,   910,   910,   911,   911,   911,   911,
     911,   911,   911,   911,   911,   911,   911,   912,   912,   913,
     913,   914,   914,   915,   915,   916,   916,   917,   918,   918,
     918,   918,   918,   918,   919,   919,   919,   919,   920,   920,
     921,   922,   922,   922,   923,   922,   924,   924,   925,   925,
     926,   926,   926,   926,   927,   927,   928,   928,   928,   928,
     928,   928,   928,   928,   929,   930,   931,   931,   931,   931,
     931,   931,   932,   932,   932,   932,   932,   932,   932,   933,
     935,   936,   934,   937,   938,   934,   939,   940,   934,   942,
     943,   941,   944,   945,   941,   946,   947,   941,   948,   949,
     941,   941,   941,   941,   941,   941,   941,   941,   941,   941,
     941,   941,   941,   941,   941,   941,   941,   941,   941,   941,
     941,   941,   941,   941,   941,   941,   950,   950,   951,   952,
     952,   952,   952,   952,   952,   952,   952,   952,   953,   953,
     954,   954,   954,   954,   955,   955,   955,   956,   956,   957,
     957,   957,   958,   958,   958,   958,   958,   958,   958,   958,
     958,   958,   958,   959,   959,   960,   960,   961,   961,   963,
     964,   965,   962,   966,   966,   968,   969,   967,   970,   970,
     971,   971,   972,   972,   974,   973,   975,   973,   976,   976,
     977,   977,   979,   978,   980,   978,   981,   982,   982,   982,
     983,   983,   984,   984,   985,   985,   986,   986,   988,   987,
     989,   987,   990,   987,   991,   987,   992,   987,   994,   995,
     993,   996,   996,   997,   998,   998,   998,   998,   998,   998,
     998,   999,   999,  1000,  1001,  1002,  1003,  1003,  1003,  1003,
    1003,  1003,  1003,  1003,  1004,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1011,  1012,  1013,  1014,  1014,  1015,  1015,
    1016,  1016,  1016,  1016,  1016,  1016,  1017,  1018,  1018,  1019,
    1020,  1020,  1021,  1022,  1022,  1023,  1024,  1025,  1025,  1025,
    1026,  1026,  1026,  1028,  1027,  1029,  1029,  1030,  1030,  1031,
    1031,  1032,  1033,  1033,  1034,  1035,  1035,  1036,  1037,  1037,
    1038,  1039,  1039,  1041,  1042,  1040,  1043,  1044,  1043,  1045,
    1046,  1043,  1047,  1047,  1048,  1049,  1051,  1050,  1050,  1052,
    1052,  1053,  1053,  1054,  1055,  1055,  1055,  1056,  1056,  1057,
    1057,  1059,  1058,  1060,  1058,  1061,  1058,  1062,  1058,  1063,
    1058,  1064,  1058,  1065,  1058,  1066,  1058,  1067,  1058,  1068,
    1058,  1069,  1058,  1070,  1058,  1071,  1058,  1072,  1072,  1073,
    1073,  1074,  1075,  1076,  1076,  1076,  1078,  1077,  1079,  1079,
    1080,  1079,  1081,  1082,  1082,  1082,  1082,  1082,  1082,  1083,
    1083,  1084,  1085,  1085,  1085,  1085,  1085,  1085,  1085,  1085,
    1085,  1087,  1086,  1086,  1089,  1088,  1090,  1091,  1092,  1092,
    1093,  1093,  1094,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,  1095,
    1095,  1096,  1098,  1099,  1097,  1100,  1100,  1101,  1102,  1103,
    1104,  1104,  1105,  1105,  1106,  1108,  1107,  1109,  1109,  1110,
    1110,  1111,  1111,  1111,  1111,  1111,  1111,  1111,  1112,  1112,
    1113,  1113,  1114,  1115,  1115,  1115,  1115,  1115,  1115,  1115,
    1115,  1115,  1116,  1117,  1117,  1118,  1119,  1119,  1121,  1122,
    1123,  1124,  1120,  1125,  1127,  1128,  1126,  1129,  1130,  1130,
    1131,  1131,  1132,  1133,  1133,  1134,  1136,  1135,  1137,  1137,
    1137,  1137,  1139,  1140,  1138,  1141,  1141,  1143,  1142,  1144,
    1142,  1146,  1145,  1147,  1149,  1148,  1150,  1148,  1151,  1148,
    1152,  1152,  1153,  1153,  1154,  1154,  1155,  1155,  1155,  1156,
    1157,  1158,  1159,  1159,  1159,  1160,  1160,  1161,  1161,  1162,
    1163,  1163,  1163,  1163,  1164,  1164,  1164,  1164,  1164,  1165,
    1166,  1166,  1167,  1168,  1169,  1169,  1170,  1171,  1171,  1171,
    1171,  1171,  1171,  1172,  1173,  1174,  1174,  1175,  1175,  1176,
    1177,  1177,  1178,  1178,  1179,  1180,  1181,  1181,  1181,  1181,
    1181,  1181,  1182,  1182,  1183,  1184,  1184,  1185,  1185,  1186,
    1186,  1187,  1187,  1188,  1188,  1188,  1188,  1188,  1189,  1189,
    1190,  1190,  1191,  1191,  1192,  1193,  1194,  1194,  1195,  1196,
    1196,  1196,  1197,  1197,  1198,  1198,  1199,  1200,  1200,  1201,
    1201,  1202,  1203,  1204,  1205,  1205,  1206,  1207,  1207,  1208,
    1208,  1209,  1209,  1210,  1211,  1211,  1212,  1212,  1212,  1212,
    1213,  1213,  1213,  1214,  1215,  1215,  1216,  1216,  1216,  1217,
    1218,  1218,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,
    1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,
    1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,
    1220,  1220,  1221,  1221,  1222,  1223,  1223,  1224,  1224,  1224,
    1224,  1224,  1225,  1227,  1226,  1228,  1228,  1229,  1230,  1230,
    1231,  1231,  1232,  1232,  1234,  1233,  1235,  1237,  1236,  1238,
    1238,  1239,  1239,  1240,  1240,  1241,  1241,  1241,  1241,  1241,
    1241,  1242,  1242,  1243,  1243,  1244,  1245,  1246,  1246,  1247,
    1248,  1248,  1248,  1248,  1249,  1250,  1251,  1251,  1252,  1252,
    1254,  1253,  1255,  1253,  1256,  1253,  1257,  1253,  1258,  1253,
    1259,  1253,  1260,  1253,  1261,  1261,  1261,  1261,  1261,  1261,
    1263,  1262,  1264,  1264,  1266,  1265,  1265,  1265,  1265,  1265,
    1267,  1267,  1268,  1268,  1269,  1270,  1270,  1272,  1271,  1273,
    1273,  1274,  1275,  1276,  1276,  1276,  1277,  1277,  1277,  1277,
    1278,  1279,  1279,  1280,  1280,  1281,  1282,  1282,  1282,  1282,
    1282,  1282,  1282,  1282,  1283,  1283,  1284,  1284,  1285,  1285,
    1285,  1285,  1285,  1285,  1285,  1285,  1285,  1285,  1286,  1286,
    1287,  1287,  1287,  1287,  1288,  1288,  1289,  1289,  1290,  1290,
    1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,
    1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,
    1290,  1290,  1291,  1291,  1291,  1293,  1294,  1295,  1296,  1297,
    1298,  1292,  1299,  1299,  1300,  1301,  1301,  1303,  1304,  1305,
    1306,  1307,  1308,  1302,  1309,  1311,  1312,  1313,  1310,  1314,
    1314,  1314,  1314,  1315,  1315,  1315,  1315,  1315,  1315,  1315,
    1315,  1316,  1316,  1317,  1318,  1318,  1318,  1318,  1319,  1319,
    1321,  1322,  1320,  1323,  1324,  1320,  1325,  1325,  1326,  1326,
    1327,  1327,  1327,  1327,  1327,  1328,  1329,  1329,  1330,  1330,
    1331,  1331,  1332,  1332,  1332,  1332,  1332,  1333,  1333,  1334,
    1334,  1335,  1335,  1335,  1336,  1336,  1337,  1337,  1338,  1338,
    1339,  1339,  1339,  1340,  1340,  1341,  1341,  1341,  1341,  1341,
    1341,  1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,
    1346,  1346,  1347,  1348,  1348,  1349,  1349,  1350,  1351,  1351,
    1352,  1353,  1353,  1354,  1354,  1355,  1355,  1356,  1356,  1357,
    1357,  1358,  1359,  1359,  1359,  1359,  1359,  1359,  1359,  1359,
    1359,  1359,  1359,  1360,  1360,  1361,  1361,  1362,  1363,  1365,
    1364,  1367,  1366,  1366,  1368,  1368,  1369,  1369,  1370,  1370,
    1371,  1371,  1373,  1372,  1374,  1375,  1375,  1376,  1377,  1376,
    1378,  1379,  1378,  1380,  1380,  1380,  1380,  1380,  1380,  1380,
    1380,  1381,  1382,  1383,  1384,  1384,  1385,  1386,  1386,  1387,
    1387,  1387,  1388,  1389,  1390,  1390,  1391,  1392,  1392,  1392,
    1394,  1393,  1395,  1395,  1395,  1395,  1395,  1395,  1395,  1395,
    1395,  1395,  1395,  1395,  1395,  1396,  1396,  1396,  1396,  1397,
    1397,  1397,  1398,  1398,  1398,  1399,  1399,  1399,  1400,  1400,
    1401,  1401,  1401,  1401,  1401,  1401,  1402,  1402,  1403,  1403,
    1404,  1404,  1405,  1405,  1406,  1407,  1407,  1408,  1408,  1409,
    1409,  1410,  1411,  1412,  1413,  1414,  1414,  1415,  1415,  1416,
    1416,  1416,  1417,  1417,  1418,  1418,  1418,  1419,  1419,  1419,
    1419,  1420,  1421,  1421,  1422,  1422,  1423,  1423,  1424,  1425,
    1425,  1425,  1425,  1425,  1425,  1425,  1426,  1427,  1428,  1429,
    1429,  1430,  1430,  1431,  1432,  1433,  1433,  1434,  1435,  1436,
    1436,  1437,  1437,  1437,  1438,  1438,  1438,  1439,  1439,  1440,
    1441,  1441,  1442,  1442,  1443,  1443,  1444,  1444,  1445,  1445,
    1446,  1446,  1447,  1447,  1448,  1448,  1449,  1449,  1450,  1451,
    1452,  1452,  1452,  1452,  1453,  1453,  1454,  1454,  1455,  1455,
    1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1456,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1458,  1458,  1458,  1459,
    1459,  1459,  1459,  1460,  1460,  1460,  1461,  1461,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1463,  1463,  1464,  1464,  1464,  1464,  1464,
    1465,  1466,  1467,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,
    1471,  1471,  1471,  1472,  1472,  1473,  1473,  1473,  1474,  1475,
    1475,  1475,  1475,  1476,  1477,  1478,  1478,  1479,  1479,  1480,
    1480,  1480,  1480,  1480,  1480,  1480,  1480,  1481,  1481,  1481,
    1481,  1481,  1481,  1481,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1483,  1483,  1483,  1484,  1486,  1485,  1487,  1485,
    1488,  1485,  1489,  1485,  1490,  1490,  1490,  1491,  1491,  1492,
    1492,  1492,  1493,  1493,  1494,  1494,  1495,  1497,  1498,  1496,
    1499,  1500,  1500,  1501,  1502,  1502,  1502,  1502,  1502,  1503,
    1504,  1504,  1505,  1506,  1507,  1507,  1507,  1507,  1508,  1508,
    1509,  1509,  1509,  1510,  1511,  1511,  1511,  1512,  1512,  1512,
    1512,  1512,  1512,  1512,  1512,  1513,  1513,  1513,  1513,  1513,
    1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,
    1513,  1513,  1513,  1513,  1513,  1513,  1513,  1514,  1514,  1515,
    1516,  1517,  1517,  1518,  1518,  1519,  1519,  1520,  1520,  1521,
    1521,  1522,  1523,  1523,  1524,  1524,  1525,  1526,  1526,  1526,
    1527,  1527,  1528,  1529,  1530,  1531,  1532,  1532,  1533,  1533,
    1533,  1533,  1533,  1533,  1534,  1534,  1534,  1534,  1535,  1535,
    1536,  1537,  1537,  1537,  1538,  1540,  1539,  1541,  1541,  1542,
    1542,  1542,  1544,  1543,  1546,  1545,  1548,  1549,  1547,  1550,
    1550,  1550,  1551,  1551,  1551,  1551,  1551,  1551,  1552,  1552,
    1553,  1554,  1555,  1555,  1556,  1556,  1557,  1557,  1558,  1558,
    1558,  1559,  1559,  1559,  1559,  1559,  1559,  1559,  1559,  1559,
    1559,  1559,  1559,  1559,  1559,  1560,  1560,  1560,  1560,  1560,
    1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,  1560,
    1560,  1561,  1562,  1562,  1564,  1563,  1565,  1565,  1566,  1566,
    1567,  1568,  1569,  1569,  1570,  1570,  1571,  1571,  1571,  1572,
    1572,  1573,  1573,  1574,  1575,  1575,  1576,  1576,  1577,  1578,
    1580,  1581,  1579,  1582,  1582,  1583,  1583,  1584,  1584,  1584,
    1584,  1584,  1584,  1584,  1585,  1585,  1586,  1586,  1587,  1587,
    1588,  1588,  1589,  1590,  1591,  1592,  1592,  1593,  1594,  1594,
    1595,  1596,  1596,  1598,  1597,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599
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
       2,     1,     2,     1,     1,     1,     2,     2,     2,     1,
       2,     2,     3,     1,     1,     1,     2,     1,     1,     2,
       1,     0,     0,     5,     7,     8,     0,     2,     1,     3,
       1,     3,     3,     1,     2,     0,     4,     0,     4,     0,
       3,     0,     3,     0,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     0,     4,     1,     1,
       0,     1,     1,     2,     0,     0,     5,     0,     6,     1,
       3,     0,     2,     4,     4,     4,     4,     2,     3,     1,
       1,     1,     2,     1,     1,     3,     0,     1,     0,     1,
       1,     1,     0,     7,     0,     5,     0,    12,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     1,     3,     5,
       0,     4,     0,     5,     0,     7,     1,     3,     1,     1,
       0,     1,     2,     1,     1,     1,     1,     4,     4,     4,
       6,     4,     6,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     6,     1,     4,     6,     0,     3,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     2,     2,     1,
       0,     3,     4,     1,     0,     3,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     0,     2,     0,     3,
       0,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     1,     0,     2,     2,     1,     2,
       5,     4,     2,     4,     5,     3,     0,     0,    11,     0,
       2,     1,     0,     2,     1,     1,     2,     0,     3,     0,
       3,     0,     3,     2,     2,     2,     4,     5,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     3,     4,     4,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     0,     3,     2,     2,     1,     3,
       4,     4,     5,     5,     1,     1,     2,     2,     4,     4,
       2,     2,     4,     4,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       0,     0,     6,     0,     0,     8,     0,     0,     8,     0,
       0,     6,     0,     0,     6,     0,     0,     6,     0,     0,
       6,     5,     5,     5,     5,     7,     7,     9,     9,     6,
       8,    10,    10,     7,     9,     8,    10,    12,    14,    14,
      10,    12,    12,     4,     4,     6,     0,     3,     1,     1,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       4,     4,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     1,     1,     2,     4,     6,     6,     3,     5,     5,
       3,     1,     2,     1,     3,     1,     3,     1,     3,     0,
       0,     0,     9,     0,     3,     0,     0,    10,     0,     1,
       0,     1,     1,     2,     0,     3,     0,     3,     0,     1,
       1,     2,     0,     3,     0,     3,     3,     1,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     0,     3,
       0,     3,     0,     4,     0,     4,     0,     4,     0,     0,
      11,     0,     2,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     6,     4,
       3,     6,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     4,     1,     1,
       1,     4,     3,     6,     3,     6,     1,     1,     2,     2,
       1,     2,     2,     1,     3,     1,     2,     2,     2,     4,
       2,     2,     4,     0,     8,     0,     1,     1,     1,     0,
       1,     2,     0,     1,     2,     0,     1,     2,     0,     1,
       3,     0,     2,     0,     0,     8,     0,     0,     3,     0,
       0,     7,     5,     2,     2,     2,     0,     5,     4,     1,
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
       3,     4,     1,     1,     1,     0,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     0,     0,
       0,     0,    13,     1,     0,     0,     6,     2,     1,     2,
       2,     2,     1,     1,     2,     1,     0,     3,     2,     1,
       1,     1,     0,     0,     7,     1,     2,     0,     3,     0,
       4,     0,     5,     1,     0,     3,     0,     7,     0,     5,
       1,     2,     0,     1,     1,     1,     0,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     2,     2,     2,     5,     8,
       1,     1,     1,     4,     4,     1,     1,     1,     1,     2,
       3,     6,     1,     3,     1,     1,     1,     3,     6,     9,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     2,     0,
       1,     1,     1,     3,     1,     3,     7,     0,     7,     0,
       6,     3,     1,     3,     1,     2,     5,     0,     7,     0,
       2,     0,     1,     5,     2,     5,     0,     5,     6,     4,
       0,     1,     1,     5,     0,     2,     0,     5,     4,     2,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     5,     1,     1,     2,     4,     4,
       6,     2,     1,     0,    11,     0,     2,     5,     0,     1,
       0,     2,     1,     2,     0,     3,     1,     0,     4,     0,
       2,     1,     3,     1,     1,     3,     4,     4,     3,     3,
       2,     8,     6,     1,     1,     2,     1,     0,     1,     7,
       2,     3,     8,     6,     2,     2,     2,     2,     1,     2,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     1,     0,     4,     1,     2,     2,     2,
       0,     1,     1,     2,     2,     0,     2,     0,     4,     1,
       3,     3,     5,     0,     2,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     3,     2,     5,     2,     5,     5,
       5,     5,     5,     5,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     1,     1,     1,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     0,     3,     2,     0,     0,     0,     0,     0,
       0,    15,     0,     2,     2,     0,     1,     0,     0,     0,
       0,     0,     0,    15,     2,     0,     0,     0,    10,     0,
       1,     3,     3,     2,     3,     4,     3,     5,     4,     3,
       3,     1,     1,     1,     2,     2,     2,     2,     1,     1,
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
       1,     1,     1,     1,     1,     7,     6,     4,     4,     1,
       1,     1,     0,     1,     2,     1,     1,     1,     1,     3,
       2,     1,     1,     2,     1,     1,     0,     3,     1,     3,
       1,     3,     1,     1,     6,     0,     3,     1,     3,     0,
       1,     4,     5,     2,     1,     1,     4,     1,     3,     4,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     4,     0,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     2,     2,     1,     3,     2,     2,     1,
       3,     1,     2,     4,     1,     2,     3,     1,     3,     4,
       0,     1,     0,     1,     0,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     2,     2,     0,     2,     1,     1,
       5,     3,     5,     3,     1,     3,     1,     1,     0,     1,
       3,     3,     3,     6,     4,     4,     4,     4,     5,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     0,     7,     0,     8,
       0,     6,     0,     8,     0,     1,     2,     1,     3,     1,
       3,     5,     1,     1,     1,     1,     1,     0,     0,     9,
       5,     1,     1,     6,     0,     3,     1,     3,     4,     1,
       0,     2,     4,     6,     0,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     1,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     4,     3,     2,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       5,     4,     4,     3,     4,     1,     1,     1,     3,     1,
       5,     7,     5,     0,     2,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       4,     6,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     5,     1,     4,
       1,     1,     7,     4,     1,     0,     4,     1,     2,     1,
       1,     1,     0,     3,     0,     3,     0,     0,     6,     0,
       2,     2,     7,     3,     3,     2,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       2,     1,     1,     2,     4,     5,     7,     7,     9,     1,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     3,
       5,     5,     5,     5,     5,     4,     4,     3,     4,     1,
       1,     1,     1,     3,     0,     5,     1,     3,     3,     3,
       1,     1,     2,     1,     1,     3,     1,     3,     3,     1,
       1,     1,     3,     2,     3,     6,     1,     3,     1,     1,
       0,     0,     6,     0,     2,     0,     1,     1,     2,     2,
       1,     1,     4,     3,     1,     2,     5,     2,     2,     5,
       0,     2,     1,     1,     2,     6,     6,     1,     0,     1,
       2,     1,     2,     0,     2,     1,     1,     1,     1,     1,
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
     817,     0,  1909,     0,   197,     0,     0,   866,   194,     0,
       0,   814,   842,   845,   192,   824,   821,     0,   812,   813,
     815,   818,   819,   822,   826,   827,   825,   862,   863,   865,
     823,   150,   147,     0,   143,   145,   144,   148,  1937,   694,
     634,   201,   695,  1684,  1682,   860,   190,   201,   861,   125,
     193,     1,   828,   820,   864,   142,   146,   149,   213,     0,
       0,     0,   611,     0,     0,   191,   869,   931,   612,   870,
     871,   867,   646,   923,     0,   924,   932,   930,   201,   195,
     213,   199,   214,     0,   129,     0,   847,  1237,     0,   846,
    1225,   854,     0,     0,   839,   838,   840,   816,   829,   830,
     848,   833,   834,   837,   835,   836,   841,   202,     0,  1683,
     925,   868,     0,     0,   939,   937,   938,   927,   926,   323,
     201,  1161,     0,   201,   266,   218,   278,   284,   285,   269,
     242,   280,   216,   255,   256,     0,   244,   294,   313,   267,
     270,   263,     0,   240,   264,     0,   276,   268,   273,   283,
     282,   201,   286,   201,   253,   254,   207,   249,   250,   289,
       0,   126,   693,     0,     0,     0,   190,   555,   872,   831,
       0,  1161,   936,   935,     0,    22,    23,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   944,     0,
     517,   509,    16,   516,   931,    15,     0,   942,     0,   324,
       0,   200,  1162,   196,     0,   647,   210,   209,     0,   208,
     211,   215,   219,   220,   221,   224,   290,   201,   290,   217,
       0,     0,     0,     0,   201,   287,     0,     0,   288,     0,
       0,     0,     0,   201,     0,   290,     0,   237,     0,   265,
     251,   252,   130,   190,     0,     0,     0,   855,   190,   190,
       0,   198,   933,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,     0,     0,
     414,   416,  1232,     0,     0,     0,  1657,     0,   410,     0,
       0,     0,   409,     0,   424,   519,     0,     0,     0,     0,
     522,   377,   383,   420,   417,   378,   379,   381,   382,   415,
     418,   423,   518,   472,   469,   478,   475,     0,     0,    17,
      18,    19,    20,    21,     0,    14,     0,   460,     0,     0,
     940,     0,   203,   206,   204,   205,   212,   648,     0,     0,
     279,     0,   281,   228,   229,     0,     0,     0,     0,     0,
     306,   308,   303,   304,   300,   302,   299,   301,   298,     0,
     308,   319,   320,   316,   318,   315,   317,   310,     0,     0,
       0,   236,     0,   235,   277,     0,   201,   201,   201,   127,
    1238,     0,  1226,  1943,   556,   873,   849,     0,     0,     0,
     545,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   541,   527,   532,     0,     0,   528,   531,   530,   625,
       0,   624,   547,     0,    11,   186,   408,   385,   384,     0,
    1167,     0,     0,   422,  1665,  1663,  1664,  1660,  1662,  1659,
    1661,  1653,     0,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   180,   181,   182,   183,   184,   524,   525,   526,   435,
       0,     0,   434,   444,     0,     0,   389,     0,     0,   390,
     380,   386,   388,   391,   392,   393,   394,   395,   387,     0,
       0,     0,     0,     0,     0,     0,    12,     0,    96,     0,
     943,     0,   928,     0,     0,     0,     0,   257,   258,     0,
     261,     0,   295,     0,     0,   305,   322,   296,   321,     0,
     314,     0,   271,     0,   259,   241,   222,     0,     0,   274,
     238,     0,   293,   292,     0,   955,   692,   955,     0,  1941,
    1943,  1161,  1784,   843,     0,   955,   503,     0,     0,   515,
       0,     0,   512,   511,   514,   510,   521,   506,   506,     0,
       0,   506,     0,   529,     0,   533,     0,   542,   313,     0,
     513,   520,   297,     0,  1233,  1724,     0,     0,     0,     0,
       0,   411,     0,     0,   425,     0,     0,     0,     0,   427,
     426,   445,   436,   451,   454,   455,   452,   458,   457,   456,
     446,   447,   448,   449,   450,   396,   437,   441,   459,   453,
     440,   459,   419,   473,   470,   479,   476,   504,     0,   466,
     101,   461,    97,    98,   100,   463,     0,     0,   225,   291,
     243,   230,   231,     0,     0,   201,   307,   312,     0,     0,
       0,     0,     0,   234,     0,   201,     0,   131,   134,   133,
     135,   961,     0,   956,   957,     0,   856,  1942,  1940,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1924,     0,  1358,  1357,
       0,  1359,     0,   373,  1356,  1273,     0,     5,  1355,   374,
     371,     0,   376,   188,   459,  1136,     0,     0,  1365,   139,
     370,   369,     0,     0,   364,   459,     0,  1309,  1917,     0,
     375,   336,     0,     3,     2,     0,   372,  1270,     0,     0,
     365,   362,   358,     0,     0,     0,     0,  1363,  1353,   368,
       0,     0,     0,     0,     0,     0,     0,     0,  1352,     0,
       0,     0,   189,     0,   361,   360,     0,     0,  1921,  1920,
       0,     0,     0,   151,     0,   367,   366,     0,     0,   363,
     459,     0,     0,   459,     0,   549,     0,     0,     0,     0,
       0,     0,   459,   801,  1235,     0,     0,  1147,     0,  1910,
       0,   108,     0,     0,   881,     0,     0,     0,     0,   802,
       0,     0,  1815,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   663,     0,     0,  1945,  1946,  1947,  1948,  1949,
    1950,  1951,  1952,  1953,  1954,  1955,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,  1963,  1964,  1965,  1966,  1967,  1968,  1969,
    1970,  1971,  1972,  1973,  1974,  1975,  1976,  1977,  1978,  1979,
    1980,  1981,  1982,  1983,  1984,  1985,  1986,  1987,  1988,  1989,
    1990,  1991,  1992,  1993,   910,  1994,  1995,  1996,  1997,  1998,
    1999,  2000,  2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,
    2009,  2010,  2011,  2012,  1127,  1129,  1124,  1126,  1125,  1128,
    2013,  2014,  1263,  2015,  1269,  1268,  2016,  2017,  2018,  2019,
    2020,  2021,  2022,  2023,  2024,  2025,  1420,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  2033,  2034,  1944,   844,   560,     0,
     877,     0,   875,     0,     0,   546,     0,   620,     0,   622,
       0,   484,   482,     0,   506,     0,   483,     0,     0,   544,
       0,   540,   537,   508,   481,   548,     0,   185,  1726,  1727,
    1725,     0,   413,  1232,     0,  1658,  1232,   412,  1232,  1232,
    1232,  1232,  1232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,    96,
     941,     0,     0,   262,   248,     0,   246,   309,   311,   272,
     260,     0,     0,   275,   239,   128,   132,     0,  1239,     0,
    1227,  1096,  1095,     0,   355,   353,   354,  1267,  1056,  1055,
    1061,     0,  1632,  1633,     0,     0,  1293,   635,   636,  1294,
    1624,  1625,  1296,   832,  1104,  1919,   628,   138,  1932,     0,
       0,  1308,     7,     0,     6,     0,  1925,  1097,     0,  1195,
    1194,  1139,  1193,  1138,   407,  1366,  1354,     0,  1264,   857,
     397,  1786,  1360,   140,     0,  1100,   137,     0,   808,    24,
     630,   359,     0,   807,  1090,   809,     0,  1364,   903,   902,
     905,   901,   904,  1934,     0,   899,     0,   629,   987,   900,
    1928,     0,  1918,   136,  1266,   984,   696,   982,     0,   626,
    1913,   744,   743,   745,   741,     0,     0,  1265,   997,   631,
    1419,     0,  1900,  1414,  1417,  1890,  1893,  1894,  1896,  1899,
       0,     0,     0,     0,  1062,  1057,     0,  1036,  1037,  1038,
    1039,  1045,  1046,  1047,  1044,  1043,     0,     0,     0,  1042,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1028,  1019,  1020,   970,     0,
     968,  1076,   405,    24,     0,  1915,   141,   627,     0,  1236,
    1234,  1160,     0,  1775,     0,  1776,  1161,  1149,  1140,  1367,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
     931,     0,    69,     0,   106,   603,     0,   650,   649,     0,
    1130,  1004,  1134,     0,     0,  1077,  1253,     0,     0,  1137,
     655,   652,   653,     0,   657,   658,     0,   660,   661,     0,
     656,   965,   967,     0,     0,   966,   746,   963,   707,   959,
     922,     0,     0,     0,     0,   667,   668,     0,     0,   920,
     917,   918,   914,   915,   916,   909,   913,   912,     0,     0,
       0,     0,     0,     0,   564,   566,   558,   561,   562,   879,
    1943,   874,   876,   850,   617,   619,     0,     0,     0,     0,
     506,   489,     0,   506,   506,     0,   534,     0,   306,     0,
       0,  1754,  1649,  1651,  1810,  1814,  1755,  1655,  1752,     0,
       0,  1751,     0,     0,     0,  1753,     0,     0,     0,     0,
       0,     0,     0,  1900,  1650,  1750,  1652,  1739,     0,  1728,
    1730,  1734,  1737,  1765,  1808,  1766,  1811,  1901,  1891,  1738,
    1170,  1666,  1169,  1168,  1171,  1173,  1172,  1166,   438,   439,
     443,   428,     0,   431,   442,     0,   430,   474,   471,   480,
     477,   505,   467,   462,    99,   464,   929,     0,   201,   245,
     223,   233,   962,   190,   958,   190,     0,     0,     0,     0,
    1338,  1339,     0,     0,     0,  1310,  1313,  1315,  1316,  1317,
    1321,  1320,  1318,  1319,     0,     0,     0,  1311,  1312,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,     0,    24,
    1190,  1192,  1191,     0,   400,   401,   398,   399,   975,     0,
    1101,     0,     0,   341,    25,   335,     0,  1089,     0,  1088,
    1085,     0,     0,     0,     0,     0,     0,     0,   991,  1785,
       0,     0,     0,     0,     0,     0,  1915,     0,     0,   152,
       0,     0,  1001,   993,   994,   999,     0,     0,  1892,     0,
    1903,  1415,  1416,     0,     0,   919,   403,  1884,  1014,   325,
       0,     0,   550,   608,   607,   605,   610,  1022,   609,  1027,
    1023,  1026,   800,   792,   786,   798,   799,   784,   785,   793,
     788,   794,   787,   797,   791,   795,   790,   796,   783,   789,
     776,   782,  1024,  1025,     0,  1032,  1040,  1029,  1030,  1034,
    1035,  1033,  1031,  1050,  1051,  1048,  1041,  1052,  1053,  1049,
       0,     0,     0,   810,     0,     0,     0,     0,     0,   756,
     755,   752,  1916,  1923,    24,  1156,  1157,  1158,  1159,  1153,
       0,  1151,  1249,  1161,  1141,  1142,  1145,  1163,  1911,     0,
       0,     0,     0,   102,     0,   103,     0,     0,     0,    77,
       0,     0,     0,     0,   115,   110,     0,   651,   908,     0,
     907,     0,   459,  1132,     0,   950,   951,   974,   945,   946,
     803,   972,  1079,  1262,  1261,  1256,     0,  1260,  1259,  1254,
    1819,  1822,  1824,     0,  1817,  1820,  1821,   683,     0,     0,
       0,   672,   707,   707,   704,     0,     0,   708,     0,    26,
     671,   674,     0,   681,   677,   921,   911,  1782,  1783,  1773,
    1773,  1384,     0,     0,  1685,  1423,     0,     0,  1368,     0,
       0,  1369,  1412,     0,     0,  1413,     0,     0,  1724,     0,
    1382,     0,  1432,  1431,  1430,  1428,  1429,  1427,  1425,  1421,
    1512,  1511,  1422,  1424,  1433,  1706,  1426,  1789,  1788,  1787,
    1434,  1943,  1943,   577,   568,   559,     0,   563,  1943,   878,
     190,     0,     0,   507,     0,   506,     0,   493,   506,     0,
     486,   485,     0,     0,     0,   539,   538,   187,  1736,  1735,
    1673,  1671,  1672,  1668,  1670,  1667,  1669,  1654,     0,  1724,
       0,     0,  1579,     0,     0,  1742,  1740,  1741,  1579,  1579,
    1579,  1579,  1743,     0,     0,     0,  1530,  1714,     0,  1731,
       0,     0,     0,     0,  1798,  1799,  1800,  1801,  1802,  1803,
    1746,     0,     0,     0,     0,   433,   432,     0,     0,   232,
       0,   247,  1240,  1228,     0,     0,     0,     0,     0,     0,
       0,  1486,  1485,  1484,  1345,     0,  1351,  1347,  1349,  1340,
       0,  1588,  1337,  1333,  1307,  1306,     0,  1332,  1328,     0,
    1324,  1322,     0,  1631,     0,  1634,  1636,   639,     0,   638,
    1623,     0,  1626,  1628,  1933,  1930,     0,     0,  1274,   459,
     333,  1295,     0,     0,     0,  1271,  1006,  1093,  1094,  1087,
    1086,     0,   906,     0,     0,   613,     0,     0,     0,   985,
     983,   698,   699,     0,   703,     0,     0,  1914,  1922,   742,
       0,   156,     0,   995,  1002,     0,     0,  1010,  1895,  1908,
       0,  1906,  1418,  1898,  1897,     0,     0,     0,  1016,   328,
       0,     0,     0,     0,    24,  1058,  1059,   553,     0,     0,
       0,   777,   778,  1021,   971,   969,   811,   406,     0,  1068,
     753,   757,   754,   758,   356,     0,  1161,  1150,  1250,  1165,
    1148,  1143,     0,     0,  1144,  1943,     0,     0,     0,     0,
       0,     0,     0,    64,    96,     0,     0,     0,   121,   116,
       0,   111,     0,   118,   112,   892,   884,   890,     0,  1131,
       0,  1133,  1135,     0,     0,   954,     0,     0,     0,     0,
    1078,  1255,  1258,     0,     0,     0,  1816,  1818,  1943,   654,
     659,   662,   675,   673,   632,     0,   731,   729,   727,   725,
     735,   733,     0,     0,   723,   773,   721,   706,   717,   715,
     771,   747,     0,   709,   719,   964,   960,     0,     0,     0,
       0,   680,     0,     0,     0,     0,     0,     0,     0,  1639,
       0,  1507,  1508,  1794,  1465,  1530,     0,     0,     0,  1792,
       0,  1445,  1440,  1439,  1452,  1451,  1456,  1456,  1454,  1455,
    1446,  1441,     0,     0,  1447,  1448,  1707,  1826,     0,     0,
       0,   565,   567,     0,     0,   580,   572,   574,     0,   569,
     570,     0,     0,   588,   590,     0,     0,   586,   880,   851,
     621,   623,   618,     0,   506,   495,     0,   490,     0,     0,
     506,   506,   536,   535,     0,     0,  1763,  1655,     0,     0,
    1738,  1581,  1582,  1580,     0,  1767,     0,     0,     0,     0,
       0,     0,     0,  1729,     0,  1518,  1519,  1521,  1524,     0,
    1531,  1532,     0,     0,  1579,  1716,  1710,  1732,  1748,  1749,
    1747,  1745,     0,     0,     0,  1902,   429,   468,   465,   226,
    1196,  1174,     0,     0,     0,     0,     0,  1345,     0,     0,
       0,  1341,     0,     0,     0,  1335,  1619,  1617,  1586,  1598,
    1600,  1604,  1606,  1597,  1591,  1596,  1610,  1589,  1618,  1594,
    1609,  1595,  1616,  1608,  1492,  1583,  1584,  1585,     0,  1330,
    1326,     0,     0,  1314,     0,     0,   637,     0,     0,     0,
    1929,     0,     4,     8,    10,     0,   459,   402,     0,     0,
       0,     0,  1003,     0,     0,     0,     0,     0,     0,     0,
       0,   697,     0,     0,   173,   171,     0,     0,   153,     0,
     163,   169,   707,   158,   160,     0,  1000,  1011,  1012,     0,
       0,  1904,   404,     0,  1885,  1886,  1015,     0,     0,  1013,
     327,   332,   615,   326,     0,   329,   334,     0,   459,  1390,
     606,   604,     0,   780,  1067,  1069,     0,   357,  1154,  1152,
       0,  1164,  1146,     0,     0,  1245,     0,     0,     0,   104,
       0,     0,    78,    84,    74,    71,  1943,  1943,   114,   109,
     123,   119,     0,   113,   774,   893,   632,  1943,   883,   882,
     891,  1005,     0,     0,   952,   953,   947,   973,   459,  1084,
    1080,  1081,  1083,  1257,  1823,  1825,   684,   678,   676,     0,
      24,     0,  1943,  1943,  1943,  1943,  1943,  1943,   737,   711,
     739,   713,  1943,  1943,  1943,  1943,     0,   705,   710,  1943,
     632,   769,   767,   770,   768,     0,     0,    46,    44,    41,
      35,    39,    43,    38,    31,    40,     0,    34,    37,    32,
      42,    33,    45,    36,     0,    29,    47,   761,     0,   682,
    1774,     0,  1772,  1724,  1770,  1711,  1712,  1704,  1690,  1705,
       0,     0,     0,  1054,  1506,  1509,     0,     0,     0,  1402,
    1374,  1797,  1796,  1795,     0,     0,     0,  1450,  1453,     0,
       0,     0,     0,     0,  1397,     0,  1396,     0,  1398,  1393,
    1394,  1395,  1386,  1387,     0,     0,     0,   579,   584,     0,
       0,  1943,  1943,   557,   571,   594,   582,   596,  1943,  1943,
     592,   576,   587,   843,   506,     0,   494,   506,     0,   506,
     506,   488,   487,  1680,  1678,  1679,  1675,  1677,  1674,  1676,
    1656,     0,     0,     0,     0,  1764,     0,     0,     0,  1762,
       0,     0,     0,     0,  1744,  1761,     0,  1522,     0,     0,
    1648,  1525,     0,     0,     0,     0,  1517,  1536,  1538,  1540,
    1578,  1577,  1576,  1542,  1558,     0,  1533,  1534,  1719,  1297,
       0,     0,     0,  1809,     0,  1813,     0,     0,  1222,  1241,
       0,  1229,  1222,  1092,     0,  1640,     0,  1474,     0,  1477,
    1643,     0,  1482,     0,     0,  1342,  1343,     0,     0,  1346,
    1348,  1350,     0,  1334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1490,  1489,  1488,     0,  1493,  1494,
       0,  1329,     0,  1323,  1325,  1635,     0,  1637,  1627,     0,
    1629,  1931,  1303,     0,  1299,     0,     0,  1304,   858,     0,
       0,  1103,     0,     0,     0,  1361,  1936,  1935,   614,     0,
       0,    48,     0,   700,   702,   701,  1362,   707,  1943,  1943,
     165,   640,   175,   167,   177,   157,   164,  1943,     0,     0,
       0,     0,     0,  1907,     0,     0,     0,     0,     0,     0,
    1060,     0,  1391,   551,     0,   779,  1065,     0,  1251,  1252,
    1912,     0,    96,     0,    65,     0,     0,     0,    81,     0,
      96,    96,    96,   122,   117,  1943,  1943,   107,     0,   894,
     888,   896,   895,   885,   601,   934,     0,     0,     0,   686,
     665,   679,   633,   748,     0,   732,   730,   728,   726,   736,
     734,     0,  1943,     0,  1943,   724,   722,   718,   716,   772,
     720,    24,   762,     0,     0,     0,    27,     0,  1777,     0,
    1691,     0,     0,  1703,  1686,  1702,  1510,     0,  1467,     0,
    1401,     0,     0,  1793,     0,  1790,     0,  1458,  1462,  1438,
    1460,  1463,     0,  1449,  1708,     0,     0,     0,     0,     0,
       0,  1827,  1400,  1399,  1388,  1383,  1385,  1437,     0,     0,
     581,   578,   573,   575,     0,  1943,  1943,   589,   591,  1943,
    1943,   496,     0,   500,     0,     0,   492,   491,     0,     0,
       0,     0,     0,     0,  1760,  1768,  1756,  1757,  1758,  1759,
    1527,     0,  1520,  1526,  1541,  1545,     0,  1558,  1544,     0,
       0,  1559,  1571,  1572,  1569,  1575,  1574,  1570,     0,     0,
       0,     0,     0,  1573,     0,     0,     0,  1514,  1515,  1733,
       0,  1535,  1529,  1298,  1717,  1407,  1403,  1404,  1409,  1408,
    1715,  1297,     0,     0,  1220,  1221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1219,     0,     0,
    1207,  1208,  1209,  1206,  1211,  1212,  1213,  1210,  1197,  1188,
       0,     0,  1244,     0,     0,  1183,     0,     0,     0,     0,
       0,     0,     0,  1175,  1176,     0,  1105,     0,  1644,     0,
    1645,     0,     0,     0,     0,  1481,  1480,  1345,  1479,  1471,
    1336,  1620,     0,     0,     0,     0,     0,     0,  1621,  1613,
       0,     0,     0,  1613,  1649,  1487,  1500,  1505,     0,  1502,
    1499,  1501,     0,  1503,  1491,  1495,  1496,  1345,  1331,  1327,
       0,     0,  1302,  1301,     0,  1286,     9,     0,  1276,   859,
    1099,   339,     0,  1276,     0,     0,  1927,     0,     0,   986,
      49,     0,   759,   174,   172,     0,  1943,     0,     0,     0,
    1943,   170,   159,     0,   162,   161,     0,   992,   996,     0,
    1889,  1888,  1887,     0,     0,   331,     0,   554,     0,  1943,
     781,     0,   632,  1155,     0,  1246,    70,     0,     0,   105,
      68,    96,    79,    85,     0,     0,   124,   120,   775,  1943,
     898,   632,   897,     0,   598,     0,   805,   806,   804,  1082,
     689,   687,     0,   669,   666,     0,   738,   712,   740,   714,
     749,   765,   766,   763,   764,    30,    28,     0,  1771,  1720,
    1692,  1688,  1687,     0,  1466,  1724,  1469,     0,  1376,  1371,
    1370,  1373,     0,     0,  1457,     0,     0,  1720,     0,     0,
    1864,  1862,     0,     0,  1846,  1861,     0,     0,  1863,     0,
       0,     0,     0,     0,  1900,  1860,  1852,  1879,  1880,     0,
    1844,  1847,  1848,  1859,  1851,  1881,     0,  1837,  1836,  1840,
    1842,     0,  1835,     0,  1838,  1829,     0,     0,   585,   583,
     595,   597,   593,     0,   506,     0,   506,   506,     0,  1723,
       0,  1656,     0,     0,     0,  1523,  1543,  1537,  1539,  1546,
    1548,  1546,     0,  1553,  1546,     0,  1551,  1546,     0,  1561,
    1560,     0,  1562,     0,  1513,     0,  1411,  1410,  1406,  1718,
       0,   227,  1214,  1215,  1216,  1218,  1201,  1199,  1198,  1202,
    1203,  1200,  1217,  1204,  1205,  1189,   979,  1224,   976,     0,
       0,  1242,  1187,  1186,  1181,  1179,  1178,  1182,  1180,  1184,
    1185,  1177,  1230,  1091,     0,  1472,  1478,  1647,  1640,  1483,
    1344,  1587,  1599,     0,  1601,  1603,     0,  1605,     0,     0,
       0,  1611,  1590,  1615,     0,  1473,  1475,     0,  1497,  1498,
    1638,  1630,  1300,     0,     0,  1292,  1287,  1288,  1305,     0,
    1283,  1284,     0,     0,  1297,  1277,  1278,     0,    24,  1102,
    1272,     0,     0,  1009,     0,    50,   989,     0,    24,   176,
     166,     0,   642,   644,   178,   168,   759,     0,  1905,  1018,
       0,   330,  1392,     0,  1066,    24,     0,     0,    66,     0,
      82,    91,     0,    75,    72,   889,   886,   602,  1943,   948,
       0,  1943,   685,   664,   670,   632,  1781,     0,  1779,     0,
       0,  1693,  1689,  1468,     0,  1470,  1464,     0,  1375,     0,
    1791,  1459,  1461,  1436,     0,  1850,  1849,     0,     0,  1579,
       0,  1579,  1579,  1579,  1579,  1853,     0,     0,  1833,     0,
       0,     0,     0,  1866,  1834,     0,     0,     0,     0,     0,
       0,  1828,  1389,  1442,   853,   852,   497,     0,     0,   502,
     501,  1681,  1804,  1807,  1805,  1528,     0,  1565,  1567,     0,
    1554,  1557,  1556,  1564,     0,  1566,  1546,     0,  1516,  1405,
    1812,   981,   980,   978,     0,  1223,  1106,  1110,  1112,     0,
    1116,     0,  1114,  1118,  1107,  1108,     0,     0,     0,  1641,
    1646,     0,     0,  1622,  1614,  1592,     0,  1593,     0,     0,
    1290,  1285,  1291,  1289,  1282,  1281,  1280,  1275,  1279,   340,
     337,     0,  1007,     0,     0,     0,   988,   760,   154,   641,
      24,   998,  1017,   552,  1063,    67,  1247,    87,     0,     0,
      80,    91,    91,    91,  1943,   599,     0,     0,   688,   750,
       0,  1778,  1721,  1714,     0,  1377,     0,  1714,  1877,     0,
       0,  1882,     0,     0,     0,     0,     0,     0,     0,     0,
    1845,  1868,  1869,  1867,  1865,  1843,     0,  1839,  1841,  1830,
    1831,  1443,     0,  1435,   506,   506,  1547,  1769,  1549,     0,
    1552,  1550,  1568,     0,   977,  1943,  1943,  1120,  1943,  1122,
    1943,  1943,  1109,  1243,  1231,     0,  1602,     0,  1612,     0,
    1504,   342,  1008,  1926,     0,     0,     0,     0,     0,     0,
      55,     0,    54,     0,    52,     0,     0,   155,  1070,    91,
      96,    91,    92,    86,    76,    73,   887,     0,     0,   690,
      24,  1780,  1713,  1722,  1381,     0,  1378,  1380,  1694,  1878,
       0,     0,  1876,     0,     0,     0,     0,     0,  1854,  1875,
       0,  1444,   499,   498,  1555,  1563,  1111,  1113,  1943,  1117,
    1943,  1115,  1119,  1642,  1607,  1476,   344,   349,   347,   338,
       0,   345,   351,    57,    62,    59,    61,    58,    60,    56,
       0,    51,     0,   643,   645,  1074,  1064,     0,  1072,  1248,
      88,    83,   600,   949,  1943,   751,     0,  1372,     0,  1695,
    1709,  1874,  1883,  1870,  1871,  1872,  1873,     0,  1855,     0,
       0,  1121,  1123,  1943,  1943,   343,   346,  1943,    53,     0,
    1943,  1071,  1073,     0,   686,  1379,     0,  1699,  1696,  1697,
       0,     0,  1832,   350,   348,   352,     0,  1075,    89,   691,
       0,     0,     0,  1857,     0,  1856,   990,    93,     0,  1700,
    1698,     0,    95,     0,    90,     0,  1858,    94,  1701
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   805,   806,   807,   808,  1023,  2082,  2083,   198,   324,
     199,  1383,  1384,  1908,  2244,  3292,  2769,  2770,  3194,  3293,
    3294,   809,  1168,  2807,  2502,  3213,  2501,  3212,  1844,  2499,
    3061,  2811,  3208,  2500,  3062,  3300,  3403,  3427,  3210,  3434,
     621,   622,   623,  1514,  2158,   810,  1526,  1173,  1524,  1853,
    2169,  1850,  2167,  2172,  2506,  1525,  2166,  1854,  2505,    11,
      84,   253,   534,   161,   646,   647,   811,    12,    33,    34,
      35,    36,    37,   813,  1086,  1781,  1409,  2108,  2112,  2113,
    2109,  2110,  2776,  2780,  2467,  2459,  2458,  2460,  2463,   479,
     276,   573,   814,    64,    65,    14,    47,   121,    41,    79,
      80,    59,    81,   219,    82,    83,   230,   225,   154,   642,
     338,  2376,   345,   633,  1700,   372,   373,   248,   155,   243,
     227,   234,   975,   976,   156,   251,   157,   158,   245,   226,
     228,   340,   159,   533,   235,   238,   236,   237,   920,   512,
     513,   515,   520,   638,   239,   240,   367,   517,   210,  1804,
     815,   816,   817,   818,  1044,  3281,  3028,  1385,  3349,  3350,
    3351,  3394,  3393,  3397,   819,   820,   821,   822,   823,   824,
     825,  1034,   480,  1039,  1375,  1376,  1425,  1141,  1426,   301,
     302,   303,   304,   305,   438,   481,  1312,   482,   483,   484,
     485,   486,   487,   488,   956,   200,   498,   967,   969,  1698,
     966,  1697,   201,   491,   962,   490,   961,   493,   964,   492,
     963,   921,   934,   306,   307,   203,   308,   405,   406,   407,
     408,   389,   410,   826,  1106,  1807,  2799,  2139,    95,   258,
     543,  1624,  1236,  1237,  1238,  1621,  1622,  1958,  1959,  1960,
    2301,  2302,  1625,  1626,  1954,  2305,  2297,  1966,  1967,  2308,
    2309,  2599,  2595,  2596,   827,  3068,  3307,  2824,   828,  1437,
      66,  1766,  1767,  2133,   390,   412,  1078,  1146,  1015,  1066,
    1049,  1088,  2200,    67,  1016,  1007,  1738,  2462,    68,   309,
     829,  1178,   830,  1191,  1192,   831,   832,   833,   834,  1199,
    2833,  1220,  3073,  1221,  1882,  1222,  2197,  1223,  2520,  1224,
    1911,   835,  1878,  2519,  2832,  3071,  3070,  3374,    96,    15,
      16,   836,  1403,  1771,  1772,  1773,  1901,  1568,  1902,  1903,
    2532,  2534,  2215,  2214,  2219,  2213,  2212,  2205,  2204,  2203,
    2202,  2207,  2206,  2209,  2211,   837,   838,  1084,   839,  1564,
    1206,  3310,   840,  1491,  3038,  2246,  2247,  1904,  2216,  2175,
    2508,  1135,  1465,  1811,  2142,  1812,  1461,   841,   842,  1184,
    1868,  2828,   843,   844,   845,   846,    17,    18,    19,    52,
      20,    21,    22,    97,    98,   847,    99,    23,   908,    24,
     100,   101,   170,   545,  1630,  2313,  3125,   102,   166,   383,
     848,  2439,    25,    26,    27,    28,    29,    46,    71,   103,
     259,   544,   911,   912,  1240,  1628,   849,  1179,  2179,  1857,
    2177,  3214,  2819,  1858,  2176,  2511,  2821,   850,   851,   852,
    1060,  1061,  1529,   853,  1225,  1226,   854,  1576,  1227,   310,
      73,    74,    75,    76,  1536,   174,   117,    77,   114,   206,
     207,  1537,  1538,  2186,  1539,   652,   653,  1208,   654,  1209,
    1139,  1140,  1540,  1541,  1379,  2967,  2968,  3153,  1076,  1077,
     855,  1398,  3196,   856,  2788,   857,  1413,  1414,  1415,  1787,
    1785,   858,   859,  2092,  2119,   860,  1798,  2129,   861,  1136,
    1137,  1475,  1479,   862,  1000,   863,  2257,   864,  3298,  2802,
     865,  2146,  3366,  3367,  3368,  3400,  1143,   866,  1542,  1870,
    2190,  2191,   867,   868,  1759,   869,   992,  1368,   870,   871,
     872,  2381,  2971,  3164,  3165,  3265,  3266,  3270,  3268,  3271,
    3338,  3340,   873,   874,  1531,  1862,   875,  1533,  1503,  1504,
    1505,  1834,   876,  1158,  1156,   877,   878,  1826,  1499,  1152,
     213,  1506,  1507,   311,  2382,  2703,  2704,  2688,  1031,  1032,
    2378,  2689,  2692,   104,   165,   537,  1335,  2031,  2705,  3167,
     420,   879,  1150,   105,   163,   535,  1333,  2030,  2693,  3166,
    2379,  1172,  2492,  3057,  3299,  1829,   880,  1549,   881,   882,
     883,   884,  1047,  2090,  1025,  2085,  3024,  3025,  3026,  3180,
    3015,  3016,  3017,   885,  2654,  2433,  2434,  2436,  1722,   886,
     887,  1345,  1346,  1347,  1731,  2071,  1348,  2068,  1728,  1349,
    2044,  1723,  1350,  1351,  1352,  2036,  2041,  1353,  1717,  1718,
     888,  1056,  1036,   889,  1602,  1603,  1926,  2860,  3089,  2562,
    2857,  3315,  3316,  1604,  1948,  1582,  2293,  2585,  2906,  2483,
    2798,  2294,  1605,  1606,  2015,  2656,  2657,  2658,  2948,  1607,
    1608,  1422,   890,  1093,   891,  1233,  1609,  1610,  1942,  3253,
    1943,  1944,  1945,  2277,  2566,  2569,  2570,  1611,  2267,  2557,
    3086,  1711,  1712,  2743,  2386,  3005,  2387,  1713,  2391,  1724,
    2418,  1725,  2419,  2744,  2745,  2746,  2747,  1612,  1920,  1921,
    2264,  1613,  2651,  2366,  2647,  2010,  1676,  2005,  2006,  2007,
    2621,  1677,  2011,  2367,  2652,  2356,  2357,  2358,  2359,  2360,
    3137,  2929,  3256,  2361,  3139,  3140,  2645,  2362,  2646,  2363,
    1994,  2064,  2065,  2066,  2999,  2067,  2722,  2729,  3174,  2388,
    1004,  2571,  2710,  2899,  2390,  2351,  1285,   312,  1286,  1657,
     431,   432,  1658,  2330,    45,   892,   893,  2852,  3082,  2550,
    3081,  3380,  3408,  3409,  2554,  2258,  1614,  2259,  2282,  2867,
     576,  2254,  2255,  2016,  2369,  3080,  2856,  1287,   941,  1288,
    1289,  2648,  2364,  1291,  1292,  1996,  3258,   894,   895,  1913,
    2256,  2848,  3077,  3078,  1579,   896,  1042,  1616,  1617,  1930,
    2564,  1618,  1619,  2273,  1690,  1989,  1293,  1294,  1295,  1296,
     897,  1187,  1553,  1554,  1555,  1874,  1556,  1875,  1620,  2283,
    2905,  3121,  2581,  2902,  2903,  2904,  2901,  2889,  2890,  2891,
    2892,  2893,  2894,  3232,   898,  1796,  2124,  2125,  1094,  1297,
    1298,  1096,  1097,  1098,  1299,  1099,  1420,  1790,  1791,    30,
     900,  1160,  1835,  1406,  1493,   901,   902,  2451,   903,  2080,
    1019,  1745,   904,   905,    40,   538,   539,   540,   541,   542,
     906
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2616
static const short yypact[] =
{
     103,  1024, -2616,   134, -2616,   134,  1376, -2616, -2616,  1376,
     134, -2616, -2616,   113, -2616, -2616, -2616,   333, -2616, -2616,
   -2616,   449, -2616, -2616, -2616, -2616, -2616,  -188, -2616, -2616,
   -2616, -2616, -2616,   259,   355, -2616,   613, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,  -253, -2616,   952,   182, -2616, -2616,
   -2616, -2616,   388, -2616, -2616, -2616, -2616, -2616, -2616,   134,
       8,   134, -2616,   134,   680,   113, -2616,   789, -2616, -2616,
   -2616, -2616, -2616, -2616,  1348,   249, -2616, -2616, -2616,  1124,
     723, -2616, -2616,  7630,   436,   134, -2616, -2616,   134, -2616,
   -2616, -2616,   134,   134, -2616, -2616, -2616, -2616,   388, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  9045, -2616,
     249, -2616,   278,  2859, -2616, -2616,   667, -2616, -2616,  1175,
     182,   628,    96, -2616, -2616,   776, -2616, -2616, -2616, -2616,
   -2616, -2616,   844,   743,   766,   771, -2616,  1187, -2616, -2616,
     780, -2616,   791, -2616, -2616,   777, -2616, -2616,   821, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1212, -2616,
     134, -2616, -2616,   134,   873,   134,   113, -2616, -2616, -2616,
     134,   628, -2616, -2616,   921, -2616, -2616, -2616,   877,   925,
     940,   955,   963,   966,   986,   999,  1009,  1023,  1026,  2859,
    1034,  5153,  1038,  1043,  1072,  1075,  1088,  1093,  1860,  1432,
   -2616, -2616, -2616, -2616,   325, -2616,   326, -2616,  2859, -2616,
     195, -2616, -2616, -2616,  1527, -2616, -2616, -2616,  1566, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,  1108, -2616,  1108, -2616,
     696,  1574,  1603,  1623, -2616, -2616,   975,  1236, -2616,  1002,
    1239,  1667,  1671,   182,  1712,  1108,  1716,  -277,  1070, -2616,
   -2616, -2616, -2616,   113,  1180,  1733,  1313, -2616,   113,   113,
    1322, -2616, -2616,   878,    60,    60,    60,    60,    60,  5153,
    1548,   128,    51,  5153,  1179,  5153, -2616,  5153,  5153,  5153,
   -2616, -2616,  1145,  1329,  1334,  5153,  1305,  1341, -2616,  5153,
    5153,  1346, -2616,  1350, -2616,  1043,  1353,  1355,  1369,  1373,
    7375, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    1295, -2616, -2616, -2616, -2616, -2616, -2616,   878,   878, -2616,
   -2616, -2616, -2616, -2616,  2859, -2616,   134, -2616,   134,  2859,
    1351,   350, -2616, -2616, -2616, -2616, -2616, -2616,  1185,  1847,
   -2616,  1208, -2616, -2616, -2616,  1881,  1457,  1461,   131,  1596,
   -2616,  1427, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1239,
    1427, -2616, -2616, -2616, -2616, -2616, -2616,  1428,   358,   369,
     235, -2616,  1434,  1917, -2616,   378, -2616, -2616, -2616, -2616,
   -2616,  1483, -2616,  1514, -2616, -2616, -2616,  1485,  1453,   400,
   -2616,  -264,  1492,  1498,   403,   421,  4329,  1499,  1501,   115,
     120, -2616, -2616,   198,  1928,  1503, -2616, -2616, -2616, -2616,
     452, -2616, -2616,  6363, -2616,  4224,  7553,  8120,  8120,  5153,
   -2616,  1431,  5153,  7375,  1468, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616,  1282,  1936,  6554,  7375,  1431,  1945,   397,  5153,
    5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,
    5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    5153,  5153, -2616, -2616,  1478,  5153, -2616,  5153,  1479, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,   878,
    5153,  5153,  5153,  5153,  1518,  1966,  1860,  1486,  3630,  1487,
   -2616,  2859,  1455,  9045,  1525,  1959,   437, -2616, -2616,  1954,
   -2616,  1494, -2616,  1236,  1955, -2616, -2616, -2616, -2616,  1958,
   -2616,  1967, -2616,  1973, -2616, -2616, -2616,  1712,  1974, -2616,
   -2616,  1358, -2616, -2616,   290,   134, -2616,   134,  1570, -2616,
    5440,   628,  5838,  1977,   313,   134, -2616,   134,    60, -2616,
    2859,    40, -2616, -2616, -2616, -2616, -2616,  1236,  1236,  1982,
     464,  1236,  1391, -2616,  1984,  1377,  1621, -2616, -2616,    51,
   -2616, -2616, -2616,  1563,  7375,   738,  1572,  6575,  1996,  1305,
    1575, -2616,  1576,  1581, -2616,  6627,  6648,  6679,  6757,  7266,
    7486,  7553,  7908,  8108,  8314,  8460,  5361,  8345,  4994,  3331,
    8120,  8120,  4418,  4418,  3554,  7375,  7206,  7297,  1431,  7375,
    7318,  1431, -2616,  7375,  7375,  7375,  7375, -2616,  2000, -2616,
   -2616, -2616,  2029, -2616,  7375, -2616,   363,  2859, -2616, -2616,
   -2616, -2616, -2616,  1676,  1587, -2616, -2616, -2616,  1589,  1592,
    1605,  1609,  1362,  2043,  1612, -2616,    36, -2616, -2616, -2616,
   -2616,  1386,  1614,  2063, -2616,  1625, -2616, -2616, -2616,   134,
     134,   878,   878,   878,   134,   901,   134,  1649,   220,   220,
    1678,   134,   134,   220,   220,   134, -2616,  1649, -2616, -2616,
     134, -2616,   987, -2616, -2616, -2616,   220, -2616, -2616, -2616,
   -2616,   134, -2616, -2616, -2616, -2616,    57,    57,  5153, -2616,
   -2616, -2616,  1678,  1678, -2616, -2616,   220, -2616, -2616,   220,
   -2616, -2616,   134, -2616, -2616,   220, -2616, -2616,   878,   220,
   -2616, -2616,  5153,   220,   878,   134,   878,   220, -2616, -2616,
     104,   220,   220,   104,   220,   134,   104,   220, -2616,   220,
     220,   220, -2616,  1649, -2616, -2616,   878,   220, -2616, -2616,
     220,    24,   134, -2616,  1678, -2616, -2616,   220,   993, -2616,
   -2616,   878,  1398, -2616,   220, -2616,  3592,   878,  5153,    60,
      60,   220, -2616, -2616,   901,   878,   855, -2616,  5153, -2616,
    2193,  5153,   220,    74, -2616,  5153,   220,  2047,   878, -2616,
     220,  5153, -2616,  5153,    57,   134,   220,   134,    60,   220,
     134,    60, -2616,   134,   271, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   512, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,  1063, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,   841,   134,
   -2616,   675, -2616,  1631,  1632, -2616,   551, -2616,  1597, -2616,
    1407, -2616, -2616,   447,  1236,  2064, -2616,  1646,   472, -2616,
    2073, -2616,  1456, -2616, -2616, -2616,  1424, -2616, -2616, -2616,
   -2616,  8578, -2616,  1145,  1653, -2616,  1145, -2616,  1145,  1145,
    1145,  1145,  1145,  2082,  2083,  2084,  5153,  1659,  2088,  5153,
    1662,  1663,  1672,  1673,  1674,  1677,  3630,  1680,  3630,  3630,
   -2616,   368,  1611, -2616, -2616,   457, -2616, -2616, -2616, -2616,
   -2616,  9045,  1712, -2616, -2616, -2616, -2616,   134, -2616,   134,
   -2616, -2616, -2616,  1448, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,   468,  1459,   498,  1473,  1644, -2616, -2616, -2616, -2616,
    1464,   506, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  2128,
    1470, -2616, -2616,  1657, -2616,  1678, -2616,  1613,   218, -2616,
   -2616, -2616,  1439, -2616,  7375, -2616, -2616,  1493, -2616, -2616,
    4433, -2616, -2616, -2616,   878,  1584, -2616,  1678, -2616,   -98,
   -2616, -2616,  1826, -2616,   141, -2616,  1635, -2616, -2616, -2616,
   -2616,  2149, -2616, -2616,   809, -2616,  1481, -2616,  1482,  2149,
   -2616,  1505, -2616, -2616, -2616,  1681,   114, -2616,  1641, -2616,
    1452, -2616, -2616, -2616, -2616,  1458,   823, -2616,   327, -2616,
    1495,  1684,  1655,  1782,  1508, -2616, -2616,  1502, -2616, -2616,
    5153,   118,  1007,  5153, -2616,   116,   220, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,   176,   176,   176, -2616,
     176,  2236,   176,   176,  1528,   -98,  1528,  1528,  1013,  1013,
    1528,  1528,  1801,   -98,  1810, -2616,  2180, -2616,  1711,   832,
   -2616,  2188, -2616,   -98,    86,    32, -2616, -2616,  5153, -2616,
   -2616, -2616,  1099, -2616,  1064, -2616,   628, -2616,  5153, -2616,
    5153,  1705,  1707,  1710,  1713,  1691,  1714,  1064, -2616,  1798,
     848,    67, -2616,  1579, -2616, -2616,   134, -2616, -2616,  1166,
   -2616,  2197, -2616,  2201,   134, -2616,   233,   219,  1585, -2616,
   -2616,  2211, -2616,  1504,  2211,  2216,  1519,  2211,  2216,  5153,
    2211, -2616, -2616,   218,   878, -2616, -2616,  1744,   324, -2616,
   -2616,  1746,   878,  5153,  1747, -2616, -2616,  2212,  2213,  2113,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1178,  1178,
     220,   220,   220,  1404, -2616, -2616,  1506,   841, -2616, -2616,
     719, -2616, -2616, -2616, -2616,  1561,   134,  1236,  2219,   521,
    1236, -2616,   537,  1236,  1236,  1695,  1600,  1698, -2616,  8874,
    8874, -2616,  1495, -2616, -2616, -2616, -2616,  1331, -2616,  8465,
    1753, -2616,  1758,  1760,  1762, -2616,  1762,  1762,  1764,  1765,
    1767,  1768,   134,   130, -2616, -2616, -2616, -2616,   133, -2616,
      66,  2737, -2616, -2616,  1331, -2616,  1331,  1771, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,  7375,   460, -2616, -2616,   471, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616,  2232, -2616, -2616,
   -2616, -2616, -2616,   113, -2616,   113,   901,   744,   241,  2233,
   -2616, -2616,   591,   331,   822,  2255, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   134,  1702,   134, -2616, -2616,  1708,
     134,  1709,   134,   134,  1678,  1615,  1773, -2616,  1775,   194,
   -2616, -2616, -2616,  1678, -2616, -2616,  2260, -2616, -2616,  1586,
   -2616,   901,  1777, -2616, -2616, -2616,  1007, -2616,  1181, -2616,
   -2616,  1181,  1064,   104,  5153,  5153,  5153,  1780, -2616, -2616,
     878,   878,  1678,  1593,  1064,    60,  1560,    24,   878, -2616,
    1599,  5153,  1869, -2616, -2616,  1670,   134,  1495, -2616,  2859,
   -2616, -2616, -2616,   134,  1466,  2281, -2616, -2616,  1617,   125,
     218,   878, -2616, -2616,  2269,  2275, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   953, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    3592,   878,   878, -2616,  1013,  5153,   -88,  1121,  1210, -2616,
   -2616, -2616, -2616, -2616,   222, -2616, -2616, -2616, -2616,  2081,
    1836, -2616,  1855,   628,  5153, -2616,    79, -2616, -2616,   134,
    2276,    60,    60, -2616,  1654, -2616,    51,  1624,   878, -2616,
     134,   134,   134,  5153,   490, -2616,  1669, -2616, -2616,   379,
   -2616,  1763, -2616,  1766,  5153,  1237, -2616, -2616,  1630, -2616,
    2309, -2616,  1715, -2616, -2616, -2616,   878, -2616, -2616,   184,
   -2616, -2616, -2616,   226, -2616, -2616, -2616, -2616,   134,    60,
      60,   203,   324,  2095,  1730,   878,   218, -2616,  1717, -2616,
   -2616,  2281,  2289,  1857, -2616, -2616, -2616, -2616, -2616,  1934,
    1934, -2616,    84,  1718, -2616, -2616,   134,  1678, -2616,  1678,
    1678, -2616, -2616,  1678,  1678, -2616,   134,  1165,   738,  1678,
   -2616,  1165, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,  1423,  1423,   843,  1083, -2616,   941, -2616,   719, -2616,
     113,  1467,  1867, -2616,   197,  1236,  2300, -2616,  1236,  1719,
   -2616, -2616,  1876,  1877,  1736, -2616, -2616, -2616,  1831,  1831,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1648,   738,
    1879,  8710,   748,  8578,  1803, -2616, -2616, -2616,   748,   748,
     748,   748,  1658,  8578,  8578,   246,  1750,  -147,   134, -2616,
    8578,  8578,  8578,  8578, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,  1656,  -200,  1007,  5153, -2616, -2616,  1884,  1885, -2616,
    1854, -2616, -2616, -2616,  1675,  1851,  1861,  1865,   907,  1866,
    1871, -2616, -2616, -2616,  2224,   134, -2616,  2351, -2616, -2616,
     571,  3597, -2616, -2616, -2616, -2616,   134, -2616, -2616,   571,
    1638, -2616,   468, -2616,  1687, -2616,  1720, -2616,  1916,   249,
   -2616,  1694, -2616,  1725, -2616,  1774,  1887,   134, -2616, -2616,
   -2616, -2616,  4433,   134,  1706, -2616,  1721, -2616, -2616, -2616,
   -2616,  1703, -2616,  2375,  2379, -2616,  2381,  1752,  5153, -2616,
   -2616,  2384, -2616,  1724, -2616,  1850,  1726,  2216, -2616, -2616,
    1722,  1352,   134, -2616, -2616,  1902,   220,  1155,  1502,  1860,
     373, -2616, -2616, -2616, -2616,  5153,  1678,  1007,  -252, -2616,
     134,   134,  5153,    70,   -98,  2387,   946,  2385,  2376,  2380,
    2236, -2616, -2616, -2616, -2616, -2616, -2616, -2616,   878,  2030,
   -2616, -2616, -2616, -2616,  2284,  5153,   628, -2616,  2133, -2616,
   -2616, -2616,  5153,    57, -2616,  2027,  2410,  2411,   475,   479,
     134,  1968,  1064, -2616,  3630,  1929,  1937,  1938, -2616, -2616,
    2002, -2616,  5153,   491, -2616,  1778, -2616, -2616,   206, -2616,
    5153, -2616, -2616,  1751,   278, -2616,  1469,   134,  2415,  8510,
   -2616, -2616, -2616,   878,  1007,   878, -2616, -2616,     2, -2616,
    2216,  2216,  1727, -2616,  1830,  1835, -2616, -2616, -2616, -2616,
   -2616, -2616,    60,    60, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616,  1992, -2616, -2616, -2616, -2616,    60,  6467,  2435,
    2422, -2616,  1064,   854,   256,   169,  2279,    50,   901, -2616,
     588, -2616, -2616, -2616,  1961,   -87,  1678,   710,  1787, -2616,
    1769, -2616, -2616, -2616, -2616, -2616,  1963,  1963, -2616, -2616,
   -2616, -2616,  1853,  1785,  2449, -2616, -2616, -2616,   564,  1788,
    1796, -2616, -2616,   878,   199, -2616, -2616, -2616,  1781,  1083,
   -2616,   134,   134, -2616, -2616,   134,   534, -2616, -2616, -2616,
   -2616, -2616, -2616,   575,  1236, -2616,   578, -2616,  2016,  2031,
    1236,  1236, -2616, -2616,  1364,  8578, -2616,   401,  2474,  2033,
    2476, -2616, -2616, -2616,  8578, -2616,   480,  8578,  8578,  8578,
    8578,   134,   489, -2616,   144,  2477, -2616, -2616,    69,  7784,
   -2616,  2057,   134,  1812,   748,  2099, -2616, -2616, -2616, -2616,
   -2616, -2616,  1364,  2462,  1364, -2616,  7375, -2616, -2616, -2616,
    1975,  1981,   901,    91,    91,    91,   500,  2224,    91,  7784,
     134, -2616,   516,   134,   517, -2616, -2616, -2616,  2007,  2012,
    2013,  1331,  1331, -2616,  2014, -2616,  2015,  2017,  2018,  2019,
   -2616, -2616, -2616, -2616,  1052, -2616, -2616, -2616,   520, -2616,
   -2616,   528,   134, -2616,   134,  1761, -2616,   134,  1776,  5153,
   -2616,   134,  2500, -2616, -2616,   571, -2616, -2616,  1833,   901,
     571,   223, -2616,  1064,  5153,  5153,  5153,  4498,  2505,  1678,
      75, -2616,  1064,   134, -2616, -2616,   134,   134, -2616,  1288,
   -2616, -2616,   362, -2616,  1840,  5153, -2616, -2616, -2616,  2503,
    2859,  1995, -2616,  1841,  2514, -2616, -2616,  1064,  1888, -2616,
   -2616, -2616, -2616, -2616,   134,  2216, -2616,   218, -2616,  1913,
   -2616, -2616,   538, -2616, -2616, -2616,   878, -2616,  6311, -2616,
    1220, -2616, -2616,  2138,  2501, -2616,  2121,  2123,  2020,  1856,
    2125,  2045, -2616, -2616, -2616, -2616,   594,  2114, -2616, -2616,
   -2616, -2616,  2002, -2616, -2616, -2616,   277,   802, -2616, -2616,
   -2616,  2281,  5153,  2054, -2616,  2023, -2616, -2616, -2616, -2616,
    2534, -2616, -2616, -2616, -2616,  2536, -2616,  1837, -2616,  2517,
     -98,   134,  2109,  2109,  2109,  2109,  2109,  2109, -2616,  2540,
   -2616,  2542,  2109,  2109,  2109,  2109,   953, -2616, -2616,  2109,
     150, -2616, -2616, -2616, -2616,  2523,  2535, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,  2537, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   541, -2616, -2616, -2616,  2527, -2616,
   -2616,  1678, -2616,   738, -2616, -2616, -2616, -2616, -2616, -2616,
    1903,  1904,   108, -2616,   588, -2616,    91,  1886,   220, -2616,
    2065, -2616, -2616, -2616,   134,   134,    91, -2616, -2616,    82,
    1678,   807,  8578,   200, -2616,  5153, -2616,  5153, -2616, -2616,
   -2616, -2616, -2616,  1947,   220,    82,  1678,  2555, -2616,   878,
     134,   969,   969, -2616, -2616,  2556, -2616,  2556,   618,   618,
    2556, -2616, -2616,  1977,  1236,  2538, -2616,  1236,  1786,  1236,
    1236, -2616, -2616,  2076, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,   133,  1331,  1880,  1331, -2616,  1331,  2115,  8578, -2616,
    2116,  2117,  2118,  2119, -2616, -2616,   246, -2616,   246,   134,
   -2616, -2616,  8211,  1762,  7715,  1762,  2560,  2571, -2616, -2616,
   -2616, -2616, -2616, -2616,   501,  8578, -2616,  2074, -2616,  2251,
     156,   256,   134, -2616,  2129, -2616,  1906,  3729,   364, -2616,
    1821, -2616,   364,  2574,  1678,   778,  2131,  2579,  1911, -2616,
   -2616,   544, -2616,   546,   907, -2616, -2616,   547,   183, -2616,
   -2616, -2616,   571, -2616,  2562,  2562,  2563,  1908,   453,  2566,
    2567,  2568,  2566,  2566, -2616, -2616, -2616,   189, -2616,  1214,
     134, -2616,   571, -2616, -2616, -2616,  1919, -2616, -2616,  1920,
   -2616, -2616,  -181,   555, -2616,   134,   556, -2616,  5153,  2150,
    2581,  2595,   560,  1064,  2599, -2616, -2616, -2616, -2616,  5153,
    1986,  2278,  5153, -2616, -2616, -2616, -2616,   362,  1326,  1326,
    2608,  -185, -2616,  2609, -2616, -2616, -2616,  1326,   134,  2021,
    1480,  2610,   134, -2616,  2859,   138,  1678,  2612,  1064,  -222,
    2387,  5153, -2616, -2616,  2236, -2616,  1892,  5153, -2616, -2616,
   -2616,  2613,  3630,   878, -2616,   987,   134,   878, -2616,  2165,
    3630,  3630,  3630, -2616, -2616,   594,  2114, -2616,   953, -2616,
   -2616,  1184, -2616, -2616,  1993, -2616,  2859,  4883,  8510,     1,
    1189, -2616, -2616, -2616,  1946, -2616, -2616, -2616, -2616, -2616,
   -2616,    60,  2109,    60,  2109, -2616, -2616, -2616, -2616, -2616,
   -2616,   -98, -2616,  1274,  1276,  6467, -2616,  2173,  2140,  8578,
   -2616,   169,   169, -2616, -2616, -2616, -2616,   569, -2616,  2101,
   -2616,    91,  1022, -2616,  1950, -2616,   576, -2616, -2616,  2628,
   -2616, -2616,  2034, -2616,  2629,  5246,  5246,  5246,  5246,    91,
      91, -2616, -2616, -2616, -2616, -2616, -2616,  2628,  1957,   878,
   -2616,  2556, -2616, -2616,   134,   618,   618, -2616, -2616,   618,
    2367, -2616,   605, -2616,  2190,  2192, -2616, -2616,  2619,  2194,
    1976,  1364,  1978,  1979, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,   577, -2616, -2616, -2616, -2616,   191,   178, -2616,  7784,
    7784, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  8874,  8874,
    2159,  8874,  2160, -2616,  8874,   885,  8578,  2645, -2616, -2616,
    7784, -2616, -2616, -2616, -2616, -2616,  2650, -2616,   353, -2616,
   -2616,  2251,  1983,  9045, -2616, -2616,    57,    57,    57,  2631,
      57,    57,    57,    57,    57,    57,  2632, -2616,  2638,    57,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  3729, -2616,
     878,  1989, -2616,  2161,  2642, -2616,  2643,  2644,  2646,  2647,
    2648,  2653,  1195,  1821, -2616,  2161, -2616,   901, -2616,  2654,
   -2616,  2313,    91,  1539,    91, -2616, -2616,  2224, -2616, -2616,
   -2616, -2616,  2229,  2230,   579,  1364,  2658,  1364, -2616,  2666,
     583,  2235,  2237,  2666, -2616, -2616, -2616, -2616,  1678, -2616,
   -2616, -2616,  2196, -2616, -2616,  1214, -2616,  2224, -2616, -2616,
     134,   134, -2616, -2616,   134,  -303, -2616,   571,   164,  2281,
   -2616,  2162,   901,   164,   424,  1064, -2616,  2685,  2202, -2616,
   -2616,  2240,  2087, -2616, -2616,   134,  1326,  2859,  1568,   134,
    1326, -2616, -2616,    60, -2616, -2616,  5153, -2616, -2616,   375,
   -2616, -2616, -2616,  1064,  2687, -2616,    60,  2281,   878,  2398,
   -2616,  2675,  1830,  7375,  2677, -2616, -2616,   218,  2218, -2616,
   -2616,  3630, -2616, -2616,  2252,  2253, -2616, -2616, -2616,   802,
   -2616,  1830, -2616,  5153, -2616,   384, -2616,  2188, -2616, -2616,
   -2616, -2616,  2209,  2308, -2616,  2695, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616,   134, -2616,   161,
   -2616, -2616, -2616,    91, -2616,   738,  2512,   599, -2616, -2616,
   -2616, -2616,   134,    91, -2616,    82,    82,  2110,  5272,  5272,
   -2616, -2616,  8764,  2234, -2616, -2616,  2238,  2239, -2616,  2241,
    2242,  2243,  2245,   134,   632, -2616, -2616, -2616, -2616,   615,
   -2616, -2616,  2889, -2616, -2616, -2616,   616,  2716,  2716, -2616,
   -2616,   622,  2717,  2711, -2616,   291,   878,    82, -2616, -2616,
   -2616, -2616, -2616,  2453,  1236,  1795,  1236,  1236,  2277, -2616,
    1364,  2285,  1364,  1364,   246, -2616, -2616,  2571, -2616,  2246,
    2737,  2246,   407, -2616,  2246,   407, -2616,  2246,  8874, -2616,
   -2616,  8578, -2616,  8578,  2560,   156, -2616, -2616, -2616, -2616,
    1364, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,   414,  2733, -2616,   878,
    1607, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   387, -2616, -2616, -2616,  2222, -2616,
   -2616, -2616, -2616,  2715, -2616, -2616,  2291, -2616,  2719,  2297,
    2724, -2616, -2616, -2616,  2310, -2616,  2263,  7784, -2616, -2616,
   -2616, -2616, -2616,   134,  2734, -2616,  -303, -2616, -2616,  2738,
   -2616, -2616,  2740,   134,  2251,   164, -2616,    60,   -98, -2616,
   -2616,  2332,  1064, -2616,  5153, -2616,  2144,  2744,   -98, -2616,
   -2616,   574, -2616, -2616, -2616, -2616,   201,  2321, -2616, -2616,
    1064,  2216,  2536,  2478, -2616,   -98,  2325,  2330,  2387,  2295,
   -2616,  2382,  2334, -2616, -2616, -2616, -2616, -2616,  2487,  2273,
    5153,  2293, -2616, -2616, -2616,  1830, -2616,   627, -2616,   878,
    2191, -2616, -2616, -2616,  8578, -2616, -2616,    91, -2616,  2306,
   -2616, -2616, -2616,  2628,  2191,  2303,  2303,  2345,  8710,   748,
    8797,   748,   748,   748,   748,   385,  8797,  5246, -2616,  8797,
    8797,  8797,  8797, -2616, -2616,    91,  2784,    91,  5246,   220,
    7784, -2616,  2536,    83, -2616, -2616, -2616,  2347,  2348, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,   189, -2616, -2616,   629,
   -2616, -2616, -2616, -2616,   633, -2616,  2246,  2797, -2616, -2616,
   -2616, -2616, -2616, -2616,   878,  2733, -2616, -2616, -2616,   878,
   -2616,   878, -2616, -2616,  1285, -2616,  2506,  2507,  2779, -2616,
   -2616,  2360,  2132, -2616, -2616, -2616,  2365, -2616,    91,   293,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,  1064, -2616,  2366,  9167,  2329, -2616, -2616, -2616,  2145,
     -98, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  2370,   218,
   -2616,  2382,  2382,  2382,   802, -2616,  2859,  2195, -2616, -2616,
     134, -2616,  2536,  -147,   133, -2616,  8550,  -147, -2616,  2372,
    8797, -2616,   679,  8797,  8797,  8797,  8797,  2799,   134,   687,
   -2616, -2616, -2616, -2616, -2616, -2616,  2339, -2616, -2616, -2616,
    2560, -2616,   134, -2616,  1236,  1236, -2616, -2616, -2616,   151,
   -2616, -2616, -2616,  8578, -2616,  1610,  1610, -2616,  1610, -2616,
    1610,  1610, -2616, -2616, -2616,  2344, -2616,  1364, -2616,   699,
   -2616,  1226, -2616, -2616,   176,   176,   176,   176,   176,   176,
   -2616,  2805, -2616,   702, -2616,  5153,  1590, -2616,   545,  2382,
    3630,  2382,  2387, -2616, -2616, -2616, -2616,  2532,   390, -2616,
     -98, -2616, -2616, -2616, -2616,   798, -2616, -2616,  1555, -2616,
    2386,  8797, -2616,  2389,  2390,  2393,  2394,   391,  2319, -2616,
    5246, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1610, -2616,
    1610, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    1328, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    9167, -2616,  2832, -2616, -2616, -2616, -2616,   943, -2616, -2616,
   -2616, -2616, -2616, -2616,     2, -2616,  8550, -2616,  1811, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616,  2821, -2616,  2823,
     834, -2616, -2616,  1411,  1411, -2616, -2616,  1411, -2616,  5153,
     971, -2616, -2616,  2399,     1, -2616,  2176,  2177,  2849, -2616,
    2371,   394, -2616, -2616, -2616, -2616,  2403, -2616, -2616, -2616,
     134,   134,  1811, -2616,  2831, -2616, -2616,   663,  2182, -2616,
   -2616,  2383, -2616,   218, -2616,   134, -2616,  2387, -2616
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2616, -2616, -2616, -2616, -2616,   366, -2616,   429,  -179, -2616,
   -2616, -1130,    61, -2616, -2616, -1801, -2616, -2616, -2616, -2616,
    -493, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -1864, -2616,
    -958, -2616,  1905, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
     698, -2616, -2616, -2616, -2616,  1347, -2616,  1021, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616,  2244, -2616,   -43, -2616, -2616,
    2841, -2616,  2840, -2616, -2616, -2616, -2616, -2616,   779,   411,
   -2616,   772, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616,  -145,   377,   236, -2616, -2616, -2616,  2640,
     177, -2616,  2764, -2616,   239, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,  -377,  1406, -2616, -2616,
   -2616, -2616, -2616,  1569,  -489, -2616, -2616,  2790, -2616, -2616,
   -2616,   858, -2616, -2616, -2616,  2331,  2328, -2616,  -198,  1645,
   -2616,  2541, -2616, -2616, -2616, -2616,  2543, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -1144, -2616, -2616,
    -445, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,  -105, -2616, -2616,  1159, -2616, -1071, -1136,  1643, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,  1953, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,  -562, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616,  2134, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616,  -542, -2616,   -91, -2616, -2616, -2616, -2616,  2513, -2616,
   -2616,  -263, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,  1679, -2616, -2616, -2616, -2616,   956,
   -2616, -2616, -2616, -2616, -2616, -1711, -2616, -2616,   951, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -1076,
    -588,   824,  1116, -2616,  -242,  -524,   485,  -746,  1460, -2616,
     740, -2616, -2115,    -3,   337, -2616, -2616, -2038,  -365,  2022,
   -2616, -2616, -2616,   441,  1365, -2616, -2616, -2616, -2616, -2616,
   -2616,   402, -2616,    93, -2616,  1366, -2616,  1046, -2616,   733,
   -2616, -2616, -2616, -2616,  -471, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   835, -2616, -2616, -1498, -2616,  1035,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1529, -2616, -2616,
   -2616, -2616, -2616, -2616,  -107, -2616, -2616, -1752, -2616, -2616,
   -2616, -2616,   701, -1949, -2616, -1095, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616,  2920, -2616, -2616, -2616,  2845,   163,   634, -2616,
   -2616,  -134, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616,  2900, -2616, -2616,  2922, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616,  2039, -2616, -2616, -2616, -2616, -2616,  1095,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    -639,  2215, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  2035,
   -2616, -2616,   -45, -2616, -2616,  1090, -2616, -2616,  1420,  -207,
    2627, -2616, -2616, -2616, -2616,   882, -2616, -1003,  1969,  1393,
   -1414,  1475, -2616,  1094,  1756,    -5,  -189, -2616,  2205,  1573,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    1490, -2616, -2616, -2616,  -759, -2616,  -608, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,  -400, -2616, -2616, -2616, -2616, -2616,
   -2616,   455, -2616, -2616,  1580, -2616,   785, -2616, -2616, -2616,
   -2616, -2616,   270, -2616,  -187, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    1472, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    -140, -2616,  1146,  2544, -2616, -2616,   276, -2616,  -654, -2616,
   -2616,   292,   601, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
    1279, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,   224, -2616,   -41,   -37,
   -2616, -2616,   -28, -2616, -2422, -2616,   240,   899, -1306, -2616,
   -2616, -2616,  1258, -2616, -1649, -2616, -2616, -2616, -1634, -2616,
   -2616, -1621, -2616, -2616, -2616, -2616, -1989, -2616,  1280,   954,
   -2616, -2616, -2616, -2616, -2616,   734, -2616, -2616, -2616, -2616,
   -2616, -2616,  -376, -2616, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616,    54, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2616, -2616, -2616, -2616,  1400, -2616,
    1401, -2616,   722,  1068, -2616, -2183,   142, -2616, -2616, -2616,
   -2616, -2616, -2616,   295, -2616, -2616,  -170, -2616,  -692, -1283,
   -2616, -2616, -2616, -2616, -2616,   265, -2616, -2616, -2616, -2616,
   -2616, -1688, -2616, -2616, -2616, -2616, -2616, -2616, -2111,  1008,
   -2616, -2263,  1086, -2616, -2616, -1960,   386,   383,   662, -2616,
   -2615, -1722, -2616, -2616,    81,  -241, -2616, -2616, -2616, -2616,
   -1635, -2616, -2616, -2616,   284, -2616,   614,  -507, -2616,  -650,
     221,  1435,    34, -1383,   639,   676,   514, -2616, -2616, -2616,
   -2616,  2447, -1219, -1965,  3018, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616,  -394, -2616, -1375, -2616,  1797, -2616, -2616,
     817,   658, -2616, -2150,   660,   166,   473,   100, -1548, -1923,
    1360,    97,  -391, -1232, -2616,  1363, -2616, -2616, -2616,  1462,
    -628, -2616, -2616,  -171,  1822, -2616,   893, -2616, -2616,   781,
     179, -2616, -2616, -2616, -1787,   -46,  -923, -2616,    76, -2616,
   -2616, -2616, -2616,  1500, -2616, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616, -2430,   -62, -2616, -2504, -1975, -1848,
    -957, -2616, -2616,   -49, -2616, -2616, -2616,   584,  -996,  1368,
    -695,  1971,  1650,  1640, -1180, -2616, -2616,   585,   945,   159,
   -2616, -2616, -2616, -2616,  1664, -2616, -2616, -2616, -2616, -2616,
   -2616, -2616, -2616, -2616,   -61,  1370,  2528, -2616, -2616, -2616,
   -2616
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1940
static const short yytable[] =
{
      39,   331,    42,    44,   394,   395,    44,    49,  1322,    94,
     274,  1325,  1494,  1486,   628,  1149,   922,  1806,   110,   926,
    1012,   257,   202,   392,   393,  1369,  1460,  1648,  1649,  2111,
     411,   261,  1429,  1997,  1998,  1999,  2000,   548,  1730,   358,
    1181,  1439,  1440,  1033,  1441,   935,  1462,  1463,  2396,   959,
    1946,    38,  1037,  1038,  1714,    94,   107,  2373,   109,  2375,
     917,  2510,  2331,  1095,  1884,  1885,     1,    38,  2609,  2464,
       2,   116,  2896,  2897,  2898,  1691,   409,  1692,    38,  2398,
    2070,   215,   162,  1029,  1832,   164,   300,    38,  2865,   167,
     168,   548,  2069,    38,  1065,  2454,    38,    38,   202,  2045,
    1010,    38,    38,  1521,  1087,  2541,  1428,  2245,   379,    38,
     204,  1985,  2587,   384,   385,   214,  1010,   202,    38,  1401,
     215,   216,   217,  1401,  1430,  2268,  2830, -1938,  1561,  1058,
    1795,    38,  1028,     1,   559,    38,   509,     2,  1674,   400,
    1189,   560,  1571,  1040,   401,   496,   403,   400,  1157,  2900,
     643,     3,   401,   402,   403,   548,  1105,   252,  2790,    86,
     254,    38,   256,  1010,   396,    38,  1674,   260,   413,  1010,
     415,    38,   416,   417,   418,   215,  1262,  1263,    38,  1387,
     423,  1010,  2655,    38,   434,   435,   204,  2631,   204,  2629,
    2632,  2633,  2634,  2635,  2636,  2637,    38,  2629,  1100,  1566,
    1562,  1103,  1433,    38,  2299,   204,   548,   334,  1795,    69,
    1148,   106,  2261,   215,  2734,  1263,     4,   564,    58,   215,
     332,   333,    38,  1973,   565,  1750,     4,  1485,  2795,  1855,
    1487,  1488,  2265,   202,  3019,  2620,  1211,  2622,   202,  2949,
     120,     5,   215,  1201,  1202,    38,  2012,    38,  1153,    50,
      38,  2307,  1550,   550,  2310,   119,  1799,   106,  1800,  1550,
    1801,   391,   391,   391,   391,   391,   204,  2539,    38,   391,
     204,  1010,   204,    38,   204,   204,   204,     7,  1543,  1544,
      60,  1153,   204,    38,  1915,  1916,   204,   204,  3251,  2023,
      55,  1388,  1389,  1390,   626,   215,  1201,  1202,    38,  2629,
      58,    50,  2509,   172,    38,    38,   915,  2575,  2576,  2577,
    2578,  2579,  3020,  3021,   574,   636,  3138,   577,  1818,  3143,
       1,   204,  3145,   497,     2,   499,   204,   411,   247,  1566,
     249,   329,  2777,    51,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   329,    63,  2111,    38,  2574,
    1432,   326,   221,   521,  1824,   606,   607,  2468,   329,   376,
     609,   916,   610,   329,   523,  1366,  3013,    13,  2120,  2371,
    2120,  2127,  1251,   528,    32,   613,   614,   615,   616,   329,
    1756,   377,  3168,   624,  2626,   329,  3387,  1382,    13,  3424,
     649,   658,  1855,  1091,   247,   548,  2332,  1095,   548,  1872,
     202,   247,   551,    86,  2752,    61,   204,  1591,     1,   204,
     971,  2128,     2,  1730,  2013,  2037,   548,  1805,    63,  3031,
    3014,   215,  1262,  1263,    38,  2014,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   569,  1545,   202,
    1081,  2195,  1328,  2753,    89,  1694,  1248,   204,   204,  3022,
      63,  1551,   204,  1249,   204,    63,  1694,  1876,  1551,     1,
     548,  1990,  2024,     2,   548,  2338,  1584,   204,   204,   204,
     204,  2778,  1330,  2796,  2338,   204,  2009,     3,   204,   812,
     907, -1938,  1856,  3119,    85,  2394,  1144,  1145,    63,  1083,
    2631,    86,   649,  2632,  2633,  2634,  2635,  2636,  2637,  1005,
       6,  2043,  2402,    63,   282,  2420,  1500,  1214,  1211,    63,
      63,  3262,   651,  2422,   651,  1195,   202,  1567,  1198,  1517,
    1469,  1470,   651,  2484,   914,   391,  2545,   204,   919,  2714,
    1290,  2714,  2714,   530,   531,   532,  1211,    87,    88,  2818,
    2754,  2757,     4,  2690,  1819,  2757,   391,   561,     7,   319,
     320,   321,   322,   323,  2853,  1567,  2556,  1704,   525,  1917,
    1005,  2863,  2924,   510,  2993,  1337,  1338,     5,  3000,  2591,
    1873,    38,   319,   320,   321,   322,   323,    78,    38,     8,
    2831, -1938,  3187,  2568,  3087,  1331,  1267,  1008,  1008,     8,
    2638,  2639,  1008,  1008,  2469,  1339,  1340,  1341,    38,  1673,
    3107,  3107,  1754,  1583,   204,  1008,  2849,  3115,     9,  2178,
    1986,  1005,  3220,  2346,  3259,  2719,  2134,  1598,  3259,  1546,
    1210,    31,  1082,  2926,  1267,  1008,  2921,  1419,  1008,  1974,
    2389,  2392,  2392,  1213,  1008,  2392,   991,   991,  1008,  1091,
    2136,   997,  1008,  1001,  1003,  2640,  1008,  1011,  1013,   991,
    1008,  1008,  1018,  1008,  1003,  1856,  1008,  1021,  1008,  1008,
    1008,   108,  1489,  3093,  3321,  3245,  1008,  3055,   991,  1008,
    2944,  1095,  3321,   650,  2194,   204,  1008,   648,  1598,  1011,
    1011,   899,  2262,  1008,  2712,  2549,  3066,  3360,  1637,   991,
    1008,  1640,  1641,  1522,  1746,  2143,  1203,  2455,    89,   204,
    1176,  1008,   991,  1751,  3123,  1008,  1431,  1402,  2990,  1008,
    1715,  1427,  1068,   218,  1434,  1008,  1675,  3039,  1008,  1678,
    1003,  3044,  2349,  2384,  2845,  3280,  1059,   388,   391,  1085,
    1492,  1011,  1774,  1833,  1762,  1092,  3252,  2199,  3009,  2384,
    2995,   562,  2997,   918,  1761,   204,   391,   391,  2333,  1490,
     985,  3079,   218,  2749,   388,   204,  1776,  1170,   204,  2437,
    1177,  2720,   204,   388,  2437,  2253,  2748,  1435,   204,  2181,
     204,  2641,  1190,   388,  1190,   391,   404,  1190,   391,  1802,
    1190,  2126,  2300,  3376,   404,   650,  2384,  1803,  3037,   648,
     522,   330,   974,  3135,   327,  1204,    89,  3223,  2004,  1214,
    1726,   524,   984,  1391,  2384, -1938,  3390,   218,  1650,  1552,
     529,  3227,  2407,  2408,  1547,   502,  1552,  1482,    10,  3107,
    2580,   112,   113,  3023,   566,   284,  1211,  1214,   970,    38,
      38,  1311,   549,  1326,  1311,   554,  2443,  2642,  2121,  3032,
    3048,   624,  1267,   624,   624,   218,     6,  1548,   287,  3069,
      38,   218,  3169,   555,  3120,  3373,  3388,  1705,  1660,  3425,
    1153,    38,    38,  2558,  2199,  1589,  2162,  2555,  3432,   631,
    1706,  1849,  2171,  2567,   218,  2938,  1816,  1705,  1020,  1250,
    1895,  1436,  3237,   328,   570,    38,  1239,  2643,  2644,  1329,
    1706,    90,  1695,  1651,     7,  1219,   924,  2931,  1212,  2934,
    2311,   632,  2937,  1696,  1254,   118,   998,  2156,    38,  1652,
    1411,  2157,  2339,  2638,  2639,  2691,  1659,  1923,  1283,  1924,
    1925,  2345,  2726,  1927,  1928,     8,  2271,   218,  2946,  1947,
     293,  1482,  2395,   204,  2137,  3132,   204,  3133,  3134,  2772,
    3219,  3313,  1213,   204,  1074,   204,   204,  2284,  2400,  2403,
    1860,  1653,  2421,  1635,     9,  1005,  2285,    62,  1442,    38,
    2423,  1342,     1,   111,  1332,  3150,   651,  2659,  2640,  1638,
    2485,  1707,  1841,  2546,   909, -1938,  2715,  2947,  2716,  2718,
    2286,  1412,    91,  2287, -1938,  1006,  1009,  2755,  2758,  3151,
    1654,  1707,  2763,  1022,    38, -1938,  1501,   910,  1090,  2288,
      38,  2854,  1011,  1758,  3097,  2008,  1758,  2314,  2864,  2925,
    2317,  2994,  1417,  1900,    38,  3001,  1245,   204,    62,  1655,
      38,  2272,   296,  1041,  1011,  1008,  1041,  3179,  1656,  1633,
    1705,  3088,    31,    32,   297,   298,  1050,  2914,  3152,  3199,
    1041,  3238,   299,  1706,  1041,     4,  1343,  3108,  3114,  3433,
    2523,  1067,  1961,  3312,  3116,    63,  1041,  3318,  1050,  3221,
    1720,  3260,    92,   218,  1079,  3261,   342,  1050,  1092,  1153,
      93,    38,  2791,  1975,  1089,    63,  1977,   204, -1938,  1092,
     204,  1104,  1095,   374,  1709,  3113,    63,    63,  1147,  1344,
     925,  2717,  1597,  2610,  2641,  2612,  1730,  2613,  1255,  1079,
    1710,  3106,  2289,  1147,  1709,  1523,  1852,  1079,  1705,   120,
      63,  3322,  3240,  1050,  2480,  2727,  1050,  1214,   122,  3329,
    1710,  1706,  1777,  3248,  1355,   204,  2123,  1820,    38,  1419,
    1601,  3345,  1361,    63,  3361,   204, -1938,   204,   938,  2263,
    3250,  3224,  1515,  2251,  1707,  1083,  1356,  1636,  1991,  1008,
    1008,  1008,   160,  1527,  1362,  2290,  2850,  2851,  2858,  2152,
    2642,  1535,  2291,  1639,   208,   343,  1466,  2086,  1702,   209,
    1703,  1528,  1443,    38,  1476,  2939,   204,   319,   320,   321,
     322,   323,  2292,  1577,    63,    38,  1757,   212,    38,  2820,
     204,    38,   344,  1705,  2161,  1962,  3146,  1215,  1216,  1217,
    2979,  2315,    38,   229,  2318, -1938,  1706,  1483,  1218, -1938,
    2643,  2644,   231,  1708,  1963,  1964,  1822,    38,  1194,    63,
    1789,  1197,  1707,  1632,  1200,  1091,  2488,    38,  1838,  1839,
    3377,  2915,  3231,   582,  1965,   232,  1283,  1283,  3231,  1091,
     233,  3241,  3242,  3243,  3244,    63,  1283,  1175,  1408,   241,
    1988,   939,  1995,  2383,   411,  1185,  2270,  1709,  1484,  1672,
     242,  1992,  1995,  1290,  2250,  3401,  3412,  1679,  1953,  2018,
    2019,  2020,  2021,  1710,   244,  2709,  1880,  1881,  1895, -1938,
    2841,    38,  2843,    38,  1934,   112,   113,  3084,  3113,  3113,
     246,  1729,  3344, -1938,  1739,  1935,    63,  1444, -1938, -1938,
    2414,  2415,  2416,  1445,  1446,  1447, -1938,  1707,   202,  2986,
    2441,  2989,  2940,   250,  2941,  1716,  1936,  1519, -1938,  1721,
    1727,  1721,  1937,  2393,  1154,  1448,  2397,  3303,  3304,  3305,
    1938,  1733,  1735,  1736,  2008,  1709,   909,  1740,  1742,  1743,
    1744,  1011,   255,  1830,   112,   113,   263,  2759,   115,     6,
    1011,  1710,  1939,    63,  1665,    38,  1666,  1667,  1241,   910,
     940,  2827,  3320,  1092,  3052,  3323,  3324,  3325,  3326,  2800,
    1993,   204,   204,   204,  1931,  2895,  2895,  2895,  2895,  1011,
   -1938,    43,   391,    38,   391,   262,  2930,  2930,   204,  2930,
    2797,  2840,  2930,  1092,   264,   927,   204,   928,    63,   655,
    1792,  1092, -1938, -1938,  1361,   957,  1520,   913,   960,   265,
      63,  1900,  2316,    63,  2736,  3369,    63,  3371,  2321,  2322,
    1709,  1585,  1810,  1147,   266,   993,  1362,    63,     8,  1774,
    1449,  3018,   267,  1450, -1625,   268,  1710,  1014,   325, -1938,
    1228,  1451,    63,  2444,  3230,  2445,  3233,  3234,  3235,  3236,
    3083,  1229,    63,  3382,  2456,   269,  1027,     9,  2192,  1961,
    3091,  1073,   204,  3157,  1394,  1969,  1793,  1970,   270,  2184,
    1080,  1395,  3122,    38,    38,  1452,    38,  1045,   271,  2477,
    2784,   204,   222,   223,   224,   974,  1836,    38,   391,   391,
    1054,  2417,   272,   391,  2104,   273,  2105,  1845,  1846,  1847,
     204,  1230,  2560,   275,  2438,  3346,    63,   313,    63,  3352,
    1453,   204,   314,  2737,  2805,  1231,  1193,  1234,  1235,  1196,
    2135,  2465,  2813,  2814,  2815,  3158,  3365,  3159,  2586,  1454,
    1455,  2855, -1938,   336, -1938,  1190,   391,   391,  2859,  2987,
    1456,   315,  2659,  3160,   316,  1457,    38,  1581,  1104,  1147,
    2738,  3161,   397,   398,   399,  3162,  2481,   317,  2104, -1938,
    2105,  1895,   318,  1919,  1011,  1586,  1011,  1011,  3042,  2026,
    1011,  1011,   337,  1929,  1290,    38,  1011,   339,  3352,  3163,
     346,  2548,  1043,  2337,  1458,  1932,  2340,  2341,  2342,  2343,
    3363,  1370,  1371,  1372,  -297,  3365,  1052,    38,  2106,  1933,
    1057,  2107,  1962,  1232,  1380,  1381,  2517,  3395,  1971,   347,
    2572,   414,  1071,   341,  2739,  3347,  1459,  1357,  1358,  3348,
     349,  1963,  1964,  1895,  2220,   931,  2588,   932,  2740,   348,
    2208,  2210,  2887,  2887,  2887,  2887, -1938,   350,  1283, -1938,
    1283,  1965,  1934,   351, -1938,  3222,   360, -1938, -1938,   380,
    1283,  1283,  1011,  1935,  1002,  2017,    38,  1283,  1283,  1283,
    1283, -1938,  2106,  1895,   359,  2107,  2149,  1587,  2895,  2895,
    1092,   204,  2895,   368,  1936,  1588,  2008,   369,  2008,  -297,
    1937,  1589,  1590,  1010,  3225,    38,  2930,  1895,  1938,  1417,
   -1938,    38,  1716,  1591,  1900,  -297,  1513,  1721,    38,  1642,
    2148,  1643,  1645,  1727,  1646,  1008,  1721,  1734,   419,    38,
    1939,  3156,   424,  1737,  1741,    38,    38,  3347,   371,   624,
    1592,  3348,   375,  1978,  2084,  1979,   378,  2741,   352,   204,
    2088,   361,  3142,  1864,   113,  3142,  1593,  -297,  1650,   381,
    1982,  1594,  1983,  2742,   353,   204, -1938,   362,  1495,  1496,
    1497,  1498,  2601,  1595,   489,  2603,  1900,  2606,  2607,  2114,
    1596,  1956,  1957,  1886,  1887,  1888,  2426,  1889,    38,  1890,
    1891,  2323,   204,  1011,  1092,  2389,  -297,  2130,  2131,   204,
     391,  2429,   382,    38,  3058,  3157,   354,  1940, -1938,   363,
    2604,   386,  2605,  1941, -1938,  2764,  1900,   425,   421,  3127,
   -1938,  3128,   204,   422, -1938,  -297,  2123,  1467,  1468,   204,
     433,  1471,  1472,   426,  -297,   436,  3406,  2159,    38,   437,
    1900,   204,   439,  1651,   440,   355,  1473,  1474,   364,   204,
    2794,  1682,  1683,  3060,  1008,  1477,  1478,   204,   441,  1652,
    2117,  2118,   442,  2185,  1535,   503,  1283,  3158,   501,  3159,
   -1938,  1092, -1938,   504,   356,   427,  2324,   365,   319,   320,
     321,   322,   323,   357,   505,  3160,   366,  1008, -1938,   391,
     391,  1290,  2325,  3161,  1215,  1216, -1938,  3162,  3190, -1938,
   -1938,  1653,  3378,  3379,   391,  2732,  2733,   506,  3198,   507,
   -1938,  3095,  3096,   508,   428,   511,   514,   519,  1990,   526,
    2895,  3163,   527,  1011, -1938,  3204,  2895,  2895,  1597,  2895,
    2895,  2895,  2895,  1598,  2326,   536, -1938,   546,  2895,  1599,
    1654,  1789,   547,   429,   552,  2887,  2887,  2615,  2983,  2887,
     553,   557,   430,   558,   567,   568,   580,   578,  2306,  2306,
     575,  1600,  2306,  2627,   579,   583,  1601,   608,   611,  1655,
     617,   618,   627,  2327,  2649,   619,   625,   629,  1656,   630,
     634,   637,  1283,   635,   639,  1684,  1685,  1686,  1687,  1688,
    1689,  1283,   656,   640,  1283,  1283,  1283,  1283,  2344,   641,
     644,  1011,  2328,  3029,   645,  2350,  1283,     1,   923,  2368,
     929,  2329,  2952,  2953,  2954,   937,  2956,  2957,  2958,  2959,
    2960,  2961,   944,   930,   942,  2964,   965,   946,   947,   202,
    2385,  2385,  2385,   948,   968,  2385,  1283,  2399,   972,   973,
    1716,   977,   981,  2694,   978,  1886,  1887,  1888,   982,  1889,
    2895,  1890,  1891,  2895,  2895,  2895,  2895,   979,  2695,  2696,
    1892,   980,   987,  1893,   983,  1894,   988,  2697,   989,  2424,
    3297,  2425,  2427,  1182,  2428,  2430,   204,   990,  2432,  3142,
    1102,    72,  1721,  1243,  1244,  1895,  1246,  1721,  3006,  1247,
    1252,   204,   204,   204,   204,  1896,  1011,  2385,  1253,  1256,
    2114,  2698,  1257,  2461,  2461,  1301,  1258,  1308,  1309,  1310,
    2699,  1313,   204,  1314,  1316,  1317,  1897,   204, -1938, -1938,
   -1938, -1938, -1938,  2116,  1318,  1319,  1320,  2192,  1327,  1321,
    1336,  2479,  1323,  1359,  1017,  1354,  1363,  3033,  2700,  1898,
    1360,  2895,  1365,  1899,   220,  1373,  1026,   173,   205,  1367,
    2895,  1364,  1386,  1392,  1393,  1396,  1397,  1399,  1290,  1404,
    1400, -1938, -1938, -1938, -1938,  3049, -1938,  1405, -1938, -1938,
    1421,  1416,  1419,  1407,  2951,  1046,  1423,  2887,  1424,   204,
    3375,  1464,  2701,  2887,  2887,  1480,  2887,  2887,  2887,  2887,
    1481,  1063,  1064,  1485,  1509,  2887,  1510,  1070,  2524,  1511,
    1072,  1008,  1512,  1516,  1518,  1532,  3302,  1008,  3353,  3354,
    3355,  3356,  3357,  3358,  1523,  1534,  1558,  1557,  1900,  1559,
      38,   548,  1300,  1565,   205,  1302,  2702,  1303,  1304,  1305,
    1306,  1307,   335,  1008,  1560,  1569,  1572,  1631,  1573,  1574,
     178,  1575,  1661,   205,  1623,  1634,  1644,  1662,  1011,  1663,
    1693,  1664,  1104,  1668,  1669,  2942,  1670,  1671,  1699,  1719,
    1732,  1442,  1748,  2385,  1749,  1752,  1755,  1747,  1753,  1768,
     907,  2563,  1929,  2385,  2008,  1775,  1919,  1011,  1492,  1283,
    1782,  1784,   204,  1786,   204,  1147,  1795,  1808,  1827,  2836,
    1797,  2838,  1919,  1011,  1809,  1789,  1825,  2306,   387,  1828,
    1840,  1837,  1859,  1842,  1852,  1861,  1866,  2887,  1567,  2825,
    2887,  2887,  2887,  2887,  1867,  1909,  1910,  1912,  1869,  1972,
    1907,  1918,  1892,  3111,  3112,  1893,  1976,  1894,  1980,  1981,
    1984,  1986,  1659,  2009,  2001,  1283,  2027,  2028,  2022,  2029,
    2033,  1035,  3370,  1011,  2040,  1011,  2350,  1895,  2032,  1283,
    2034,  1283,   494,   495,  2035,  2038,  2043,  1896,  2072,   205,
    2039,  1161,  1283,  2074,   205,  1051,  2075,  2385,  2076,  2368,
    2077,  2078,  3126,  3249,  3129,  3130,  2081,  2079,  2217,  2089,
    2094,  2385,  2803,   202,  2095,  2093,  2096,   624,  2097,  2099,
    2101,  2115,  1566,  2138,  2091,   624,   624,   624,  2887,  1721,
    2100,  1898,  2140,  2103,  3192,  1899,  2141,  2887,  2102,  2145,
    1162,  1142,  2147,  2150, -1938,  2154,  2155,  1727,  2163,  1721,
    2160,  1159,  3202,  2168,  1174,   202,  2164,  2165,  1180,  2188,
    3437,  2174,  2084,  2182,  1186,   204,  1188,  2199,  2201, -1938,
    2248,  2260, -1938,  1218, -1938,    63,   204,  1163,  2249,   204,
    2266,  2275,  2276,  2625,  2281,  2628,  2279,  1684,  1685,  1686,
    1687,  1688,  1689,  2274, -1938,  2114,  2280,  2785,  2319,  2787,
    2295,   204,  2385,  1011, -1938,  1443,  2303,  2296,   204,  2334,
    1900,  2336,  2348,  2320,   204,  2335,  2365,  2370,  2374,   204,
    1008,  1008,  2372,  2809,  2377, -1938,  2404,   204,   204,   204,
    2380,  2405,  2406,  2409,  2410,  2435,  2411,  2412,  2413,  2440,
    2452,  2472,  2474,   204,   204,  1283,  2470,  2475, -1938,  2476,
    3046,  2478, -1938,  2482,   612,  2490,  2491,  2493,   391,  2494,
     391,  2497,  2496,  3051,  2498, -1938,   205,  2495,  2515,  2518,
    2516,  1482,  1164,  2522,  1217,  2531,  1283,  2533,  2542,  2543,
    3147,  2544,  2649,  2547,  2561,  2551,  2552,  2584,  2385,  2559,
    2589,  2594,  2611,  3282,  2602,  2608,  2629,  2614,  2616,  2617,
    2618,  2619,  2884,  2884,  2884,  2884,  2385,  2385,  2630,  2653,
    2650,  2662,  2707,  2711,  2712,   205,  2663,  2713,  2721,  2724,
    2725,  2909,  2728,  2730,  2731,  2750,  2751, -1938,  3041,  1104,
    1444,  2761,  2760,  2762,  2765,  1147,  1445,  1446,  1447,  2767,
    1629,   185,  2768,  2775,  2779,  2786,  2801,  2812,  2804,  1165,
    2793,  2823,  2835,   186,  2783,  2846,  1283,  1283,  1448,  2847,
    2855,  1147,  2862,  2865,  1674,  1283,  1283,  2866,  1283,  2907,
   -1938,  1283,  2916,  1283,  2917,  2918,  2919,  1283,  2932,  2935,
    2943,  2888,  2888,  2888,  2888,  2945,  2955,  2962,  2920,  1166,
    2922,  2923,   205,  2963,  2969,  2950,  2970,  2972,  2973,  2738,
    2974,  2998,  2975,  2976,  2977,  2886,  2886,  2886,  2886,  2978,
    2984,  2991,  2992,  1377,  2996,  3007,   202,  3002,  3027,  3003,
    3034,  3035,  3036,  1290,  3037,  3050,   994,   995,   996, -1938,
     999,  3054,  3056,  3059,  3063,  3064,   624,  1988,  3072,  2385,
    2988,  2385,  3332,  3333,  1212,  3075,  3085,  1024,  1030,  1030,
    3079,  3107,  3117,  3098,  1167,  3118,  3124,  3099,  3100,  3131,
    3101,  3102,  3103,  1449,  3104,  1011,  1450, -1806,  3154,  2709,
    2933,  3171,  2936,  3172,  1451,  3173,  3136,  3010,  3011,  3175,
    3176,  2432,  3178,  1048,  1721,  1680,  1681,  1682,  1683,  1053,
    3182,  1055,  3177,   192,  3184,  1062,  3185,  3191,  1062,  3195,
    3197,  1062,  2461,  3201,   204,  3043,  2461,  3205,  1452,  3203,
     391,  1075,  3206,   204,  3207,  3189,  3211,   193,  3209, -1938,
    3216,  1142, -1938,   391,  1675,  3226,  1075,  3228,  3246,  3254,
    3255,  1502,  1138,  1508,  3263,  3275,  3273,  3274,   204,   999,
    1151,  1155,  3276,  1453,  3277,  1171,  1030,  3278,  3295,  3283,
     204,  3296,  3301,  1183,  3319,  3327,  1205,  3309,  3330,  3343,
    3359,   194,  1454,  1455,  3372,  3317,  3389,  3399,  3381,  1207,
     195,  3383,  3384,  1456,  3076,  3385,  3386,  3410,  1457,  3411,
    2385,  3418,  3420,  3421,  3422,  3426,  3423,  3431,  3435,  2563,
    2385,  2808,  1919,  1919,  2756,  2884,  2884,  3398,  3436,  2884,
    2507,  1851,  3335,  1324,  2173,    56,    57,   175,   176,  2782,
    3105,  2466,  2457,   370,   211,   177,    38,  1458,  1104,  1104,
     986,  1684,  1685,  1686,  1687,  1688,  1689,  1701,   171,   933,
     936,   518,   516,  1647,  1919,  3396,   178,  3109,  3110,  3111,
    3112,  2087,  1315,   563,  1169,  2304,  1627,  2312,  2132,  1459,
    2448,  1011,  2834,  1879,   196,   197,  3074,  1883,  2198,  1092,
    2521,  2735,  1092,  3419,  2453,  1283,  1779,  2218,  1283,  3200,
    1283,    53,  2385,   169,  2888,  2888,    70,  2600,  2888,    54,
    1242,  1069,  3181,  2180,  2183,  1865,   500,  1815,  1334,  1906,
    1563,  2187,  3181,  1284,  3155,  3264,  1101,  3402,  2886,  2886,
    1813,  1760,  2886,  2829,  1770,  2982,  1831,  3272,  2151,  2981,
    2965,   179,   584,  2706,  3188,  3317,  3186,  3030,  3183,  2442,
    2073,  1951,  1952,   180,  3012,  2042,  2553,  2401,  1968,  3149,
    3405,  1949,  1950,  2573,  1283,  2278,  2985,  3092,  3279,  3308,
    3008,  2269,  2347,  2928,  2624,  2927,  3144,  3004,  3334,  2723,
     181,  1922,  3170,  2708,   391,  2623,   945,    48,  3430,  2660,
    1615,   204,  2661,  3094,  2003,  2861,  2002,  1763,  1764,  1765,
    3148,  3090,  1914,  1684,  1685,  1686,  1687,  1688,  1689,  3311,
    1205,  1580,  3229,  1877,  1783,  3247,  2565,  3239,  1008,  2789,
    2792,  2025,  1418,  1207,  1794,  2473,  1788,   204,   657,     0,
    1778,     0,     0,     0,     0,     0,     0,     0,     0,  1378,
       0,  1283,     0,     0,  2385,     0,     0,     0,     0,  2885,
    2885,  2885,  2885,     0,     0,  1283,     0,  2884,     0,     0,
       0,     0,     0,  2884,  2884,     0,  2884,  2884,  2884,  2884,
       0,    63,  2385,   182,  2385,  2884,     0,  1283,     0,     0,
       0,  1410,     0,     0,     0,   202,     0,     0,  1817,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1502,     0,     0,
       0,  1438,  1438,  1438,     0,  1438,     0,  1438,  1438,     0,
       0,     0,     0,    72,    72,     0,  1848,     0,     0,     0,
       0,     0,     0,     0,     0,  2385,  2888,  1863,     0,     0,
       0,     0,  2888,  2888,     0,  2888,  2888,  2888,  2888,  1155,
       0,     0,     0,     0,  2888,   624,     0,     0,     0,     0,
    2886,     0,  1155,     0,     0,  2153,  2886,  2886,   183,  2886,
    2886,  2886,  2886,   204,  1530,     0,     0,  3076,  2886,     0,
       0,     0,     0,  1283,     0,  1205,     0,  2884,     0,     0,
    2884,  2884,  2884,  2884,     0,  3328,     0,     0,  1207,  1378,
       0,     0,     0,   184,     0,     0,     0,  1570,  2196,  3331,
       0,     0,     0,     0,     0,     0,  1092,     0,     0,     0,
    1283,     0,     0,  1578,  1578,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
       0,  1284,  1284,     0,     0,     0,     0,     0,     0,   186,
       0,  1284,   204,  3364,     0,     0,     0,   204,     0,     0,
       0,     0,     0,     0,     0,     0,  2888,     0,     0,  2888,
    2888,  2888,  2888,     0,     0,     0,     0,     0,  2884,     0,
       0,     0,     0,     0,     0,   187,     0,  2884,     0,     0,
    2886,     0,     0,  2886,  2886,  2886,  2886,     0,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,   189,   454,
     455,   456,   457,   458,     0,     0,     0,     0,     0,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   999,     0,  1283,     0,  3407,     0,     0,     0,     0,
       0,     0,  2885,  2885,     0,     0,  2885,   459,     0,     0,
       0,     0,     0,     0,     0,  1377,   204,  2888,     0,     0,
       0,     0,     0,     0,   191,     0,  2888,     0,     0,     0,
       0,  2098,     0,     0,     0,     0,   999,  3428,  3429,  3407,
       0,  2886,     0,    72,     0,     0,    72,  1155,  1062,   192,
    2886,     0,  3438,     0,     0,  1769,  1075,     0,  2122,  1155,
       0,     0,     0,  1780,     0,  1765,  3141,     0,     0,  3141,
       0,     0,  1205,   193,   205,     0,  1147,     0,     0,     0,
       0,     0,     0,     0,     0,  1207,  1138,     0,     0,     0,
       0,     0,     0,     0,     0,  1502,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   460,   461,   462,   463,   464,
     465,     0,     0,     0,     0,  2170,     0,   194,     0,     0,
       0,     0,     0,   466,   467,   468,   195,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1814,  1138,     0,    72,
       0,     0,  1821,  1823,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2503,  2504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2513,     0,     0,
       0,     0,     0,  1843,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2525,  2526,  2527,  2528,  2529,  2530,     0,     0,
       0,  1871,  2535,  2536,  2537,  2538,     0,     0,  1205,  2540,
     196,   197,     0,     0,     0,     0,     0,     0,     0,     0,
    1905,  1207,     0,     0,     0,     0,     0,     0,     0,     0,
     459,     0,     0,     0,  2885,     0,     0,     0,     0,     0,
    2885,  2885,     0,  2885,  2885,  2885,  2885,     0,     0,     0,
       0,     0,  2885,     0,     0,     0,     0,     0,     0,   277,
       0,   469,     0,     0,   470,     0,     0,     0,   278,   279,
    3257,     0,     0,     0,   215,   280,   281,    38,  1955,     0,
       0,     0,     0,  1107,  1108,  1109,  1110,     0,     0,     0,
       0,  2592,  2593,     0,     0,     0,     0,   178,  2597,  2598,
       0,     0,     0,  1284,     0,  1284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1284,  1284,     0,     0,     0,
       0,     0,  1284,  1284,  1284,  1284,     0,     0,   460,   461,
     462,   463,   464,   465,     0,     0,     0,     0,     0,     0,
       0,     0,  2431,  2046,     0,     0,   466,   467,   468,     0,
       0,     0,     0,     0,     0,     0,     0,  2446,  2447,  1765,
    2450,     0,     0,     0,  2885,     0,     0,  2885,  2885,  2885,
    2885,     0,   179,     0,     0,     0,     0,   282,  2471,     0,
       0,     0,     0,   471,   180,     0,     0,     0,     0,     0,
       0,     0,     0,  3141,     0,     0,     0,     0,   472,     0,
       0,     0,   473,     0,     0,     0,  1111,     0,     0,     0,
       0,   181,     0,     0,  1112,     0,     0,     0,     0,     0,
       0,     0,     0,  1113,     0,     0,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,     0,
       0,     0,     0,     0,     0,  2514,     0,     0,  2773,  2774,
       0,     0,     0,     0,     0,  2885,     0,  2781,     0,     0,
       0,     0,     0,     0,  2885,     0,   475,     0,     0,  1115,
       0,     0,     0,  2144,     0,  1030,  1116,     0,     0,     0,
       0,     0,     0,   476,   469,  2664,  2665,   470,  2666,  2667,
    2668,     0,     0,     0,     0,  2816,  2817,  1155,     0,     0,
       0,     0,    63,     0,   182,     0,     0,     0,     0,     0,
       0,  1284,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,  2837,     0,  2839,     0,     0,     0,  2193,     0,
    1138,     0,  1117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2582,     0,
    2583,     0,     0,     0,     0,     0,  1118,     0,     0,     0,
       0,     0,     0,  1119,   477,  1120,     0,  1155,  2252,  1155,
       0,     0,     0,   999,     0,  1121,  2047,     0,     0,     0,
       0,     0,     0,     0,     0,  2910,  2911,  2669,     0,  2912,
    2913,     0,     0,     0,     0,  2670,  2048,  2049,  2050,   183,
       0,     0,     0,  1122,   283,     0,   471,     0,  2298,     0,
       0,  1123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   472,     0,     0,     0,   473,     0,  1284,     0,  2671,
     478,     0,     0,     0,   184,  2051,  1284,     0,  2672,  1284,
    1284,  1284,  1284,     0,     0,     0,     0,  2052,  1124,     0,
       0,  1284,     0,     0,     0,     0,     0,     0,  2053,     0,
       0,   474,     0,     0,     0,     0,  2673,  2674,   185,     0,
       0,     0,  1125,     0,  2054,     0,     0,     0,     0,     0,
     186,  1284,     0,     0,  2055,     0,     0,   999,     0,   475,
       0,     0,     0,     0,     0,     0,     0,     0,   284,  2056,
       0,     0,     0,   285,     0,   286,   476,     0,     0,  1126,
    2675,     0,  2766,     0,     0,  2771,   187,     0,     0,     0,
    1127,   287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,     0,     0,   288,     0,     0,   289,
       0,     0,   290,     0,   999,     0,  1155,  2057,  1155,     0,
       0,   291,   190,     0,  2676,     0,     0,  1155,     0,     0,
       0,     0,     0,     0,     0,     0,  3040,     0,     0,     0,
    3045,     0,     0,     0,     0,   205,  2058,     0,     0,  1205,
    1142,     0,  1155,     0,     0,     0,  2059,   477,     0,  3053,
     620,   292,  1207,     0,     0,   191,     0,     0,     0,     0,
       0,  2486,     0,   293,     0,  2489,     0,  2060,  2677,  3065,
       0,  2061,     0,     0,   294,     0,     0,  1128,  1129,  1130,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1131,  2512,     0,     0,     0,     0,     0,     0,     0,  2062,
       0,     0,     0,     0,   295,     0,     0,     0,  2063,   572,
     443,   444,   445,   478,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,     0,     0,     0,
       0,     0,     0,     0,     0,  1132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,     0,     0,   296,     0,   195,     0,     0,
     459,     0,     0,     0,     0,     0,     0,   297,   298,     0,
       0,     0,     0,     0,     0,   299,     0,     0,     0,     0,
       0,     0,     0,     0,  1284,     0,   218,     0,     0,     0,
       0,     0,     0,  1133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1134,
       0,     0,     0,     0,  2590,   443,   444,   445,     0,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,     0,     0,     0,     0,     0,     0,     0,     0,
    1284,   196,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1284,     0,  1284,     0,   460,   461,
     462,   463,   464,   465,     0,   459,     0,  1284,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   467,   468,     0,
       0,     0,     0,     0,     0,     0,  1155,     0,     0,     0,
       0,     0,     0,  2678,  2679,  2680,  2681,  2682,  2683,  2684,
    2685,  2686,  2687,     0,     0,     0,     0,     0,     0,  3047,
       0,     0,     0,     0,     0,     0,     0,     0,  3215,  1284,
     458,  3218,   277,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,     0,     0,     0,     0,   215,   280,   281,
      38,     0,     0,     0,     0,     0,  3067,     0,     0,     0,
       0,     0,     0,     0,   459,     0,     0,     0,  1155,     0,
     178,     0,     0,   460,   461,   462,   463,   464,   465,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,   467,   468,     0,     0,     0,   277,     0,   205,
       0,     0,     0,  1155,     0,     0,   278,   279,     0,     0,
       0,     0,   215,   280,   281,    38,     0,     0,  2806,     0,
    1024,     0,  2810,     0,   469,     0,     0,   470,     0,     0,
    1284,     0,     0,     0,     0,   178,  2822,     0,     0,     0,
       0,   205,     0,     0,     0,   179,     0,     0,     0,     0,
     282,     0,     0,     0,     0,     0,     0,   180,     0,     0,
       0,  1284,   460,   461,   462,   463,   464,   465,  2842,  2844,
       0,     0,     0,     0,  3306,     0,     0,     0,     0,     0,
     466,   467,   468,     0,   181,     0,     0,  1284,  1284,  1284,
    1284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,     0,     0,     0,  2908,   282,     0,     0,     0,     0,
       0,     0,   180,     0,     0,  3336,  3337,     0,  3339,   469,
    3341,  3342,   470,     0,     0,     0,     0,     0,     0,     0,
       0,  1284,  1284,     0,     0,     0,   471,     0,     0,   181,
    1284,  1284,     0,  1284,     0,     0,  1284,     0,  1284,     0,
       0,   472,  1284,     0,     0,   473,     0,  3193,     0,     0,
       0,     0,     0,     0,     0,    63,     0,   182,  1030,  1030,
    1030,     0,  1030,  1030,  1030,  1030,  1030,  1030,     0,     0,
       0,  1030,     0,     0,     0,     0,     0,     0,  3391,     0,
    3392,   474,     0,  3217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2966,     0,     0,   469,     0,
       0,   470,     0,     0,     0,     0,     0,  2980,     0,   475,
       0,     0,   999,     0,  3404,     0,     0,     0,     0,     0,
      63,     0,   182,     0,     0,     0,   476,     0,     0,     0,
       0,   471,     0,  3413,  3414,     0,     0,  3415,     0,     0,
    3417,     0,     0,     0,     0,     0,   472,     0,     0,     0,
     473,   556,   183,     0,     0,     0,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   999,     0,     0,
    1155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,   474,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1155,  1205,
       0,     0,     0,  1138,     0,     0,     0,   477,     0,     0,
       0,     0,  1207,     0,   475,     0,     0,   183,     0,     0,
     471,   185,   283,     0,     0,     0,     0,     0,     0,     0,
       0,   476,     0,   186,     0,   472,     0,     0,     0,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   184,     0,     0,     0,   285,     0,   286,     0,
    1284,  1284,   277,     0,  1284,     0,     0,     0,     0,   187,
       0,   278,   279,   478,   287,   474,     0,   215,   280,   281,
      38,     0,     0,     0,   188,     0,   185,     0,     0,   288,
       0,     0,   289,     0,     0,   290,     0,     0,   186,     0,
     178,     0,     0,   475,   291,   190,     0,     0,  3362,     0,
       0,  1138,   477,     0,     0,     0,   284,     0,     0,     0,
     476,   285,     0,   286,  1284,     0,     0,  1284,     0,     0,
    1284,     0,     0,  1284,   187,  1284,     0,     0,     0,   287,
       0,     0,     0,  1374,   292,     0,     0,     0,   191,   188,
       0,     0,     0,     0,   288,     0,   293,   289,     0,     0,
     290,     0,     0,     0,     0,     0,     0,   294,     0,   291,
     190,     0,     0,   192,  2966,   179,     0,     0,   478,     0,
     282,   453,   454,   455,   456,   457,   458,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,  1284,
       0,   477,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,  3416,   191,   181,     0,     0,     0,     0,     0,
     459,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,     0,  2449,     0,     0,  1155,   192,     0,
       0,   194,     0,     0,     0,     0,     0,     0,   296,     0,
     195,     0,     0,     0,     0,  1155,     0,     0,     0,     0,
     297,   298,   295,     0,     0,     0,     0,   478,   299,     0,
       0,     0,     0,     0,     0,     0,  1284,     0,     0,   218,
       0,     0,     0,     0,  1138,     0,     0,     0,     0,     0,
    1284,     0,  1284,     0,     0,     0,     0,     0,  1284,  1284,
       0,  1284,  1284,  1284,  1284,    63,   194,   182,     0,     0,
    1284,     0,  1284,   296,     0,   195,     0,     0,   460,   461,
     462,   463,   464,   465,     0,   297,   298,     0,  1284,     0,
       0,     0,   277,   299,   196,   197,   466,   467,   468,     0,
       0,   278,   279,     0,   218,     0,     0,   215,   280,   281,
      38,     0,     0,     0,     0,     0,     0,     0,     0,  2966,
       0,     0,     0,     0,  3267,     0,  3269,     0,     0,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1155,     0,     0,   196,
     197,  1205,   183,     0,     0,     0,     0,   283,     0,     0,
       0,     0,     0,     0,  1207,     0,     0,     0,  1284,     0,
       0,   205,  1284,     0,     0,  1284,  1284,  1284,  1284,     0,
       0,     0,     0,     0,  2868,  2869,     0,   184,     0,     0,
     215,  1262,  1263,    38,     0,   179,     0,     0,     0,     0,
     282,  1284,     0,     0,     0,  1284,     0,   180,     0,  1264,
    1265,     0,     0,     0,     0,     0,   215,  1262,  1263,    38,
       0,   185,     0,     0,   469,     0,     0,   470,     0,     0,
       0,     0,     0,   186,   181,  1264,  1265,     0,     0,  1438,
    1438,  1438,  1438,  1438,  1438,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,     0,   285,     0,   286,     0,
       0,     0,     0,  1284,     0,     0,     0,     0,     0,   187,
       0,     0,  1284,     0,   287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,     0,     0,     0,   288,
       0,     0,   289,  2870,     0,   290,   451,   452,   453,   454,
     455,   456,   457,   458,   291,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1284,  2870,
       0,     0,     0,     0,     0,    63,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   459,     0,     0,
       0,     0,     0,  2826,   292,     0,   471,     0,   191,     0,
       0,     0,     0,     0,     0,     0,   293,     0,     0,     0,
       0,   472,     0,     0,     0,   473,     0,   294,     0,     0,
       0,     0,     0,   192,     0,  1205,     0,     0,     0,     0,
       0,     0,     0, -1939,     0,     0,     0,     0,  1207,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1939, -1939, -1939,     0, -1939,  1091, -1939,
   -1939,     0,   183,     0,     0,     0,     0,   283,     0,   475,
       0,     0,     0,     0,     0,   460,   461,   462,   463,   464,
     465,   194,     0,     0,  1091,     0,   476,     0,   296,     0,
     195,     0,     0,   466,   467,   468,     0,   184,     0,     0,
     297,   298,     0,     0,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,     0,     0,     0,     0, -1939,     0,     0,     0,     0,
       0,   185,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,     0,     0,     0,   285,   477,   286,     0,
       0,     0,     0,     0,   196,   197,     0,     0,     0,   187,
       0,     0,     0,     0,   287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,     0,     0, -1939,   288,
       0,     0,   289,     0,     0,   290,     0,     0,     0,     0,
       0,     0,     0,     0,   291,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1939,     0, -1939,     0,
       0,   469,     0,   478,   470,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1939,   292,     0,     0,     0,   191,     0,
   -1939,  1267, -1939,     0,     0,     0,   293,     0,     0,     0,
       0,     0,     0, -1939,     0,     0,     0,   294, -1939,     0,
       0,     0,     0,   192,     0,     0, -1939,  1267,     0,     0,
   -1939,     0,  2871,     0,     0,  2872, -1939,     0,     0, -1939,
   -1939, -1939, -1939,     0,     0,     0,     0,   295,  2873,     0,
       0,     0,     0,     0, -1939,     0,     0,     0,  2871,     0,
       0,  2872,     0,     0,     0,     0,     0,     0,     0,     0,
   -1939,     0,     0, -1939,  2873, -1939,     0,     0,     0,     0,
       0,     0, -1939,     0,     0,     0,  2874,  2875,     0,     0,
       0,   194,     0,   471,     0, -1939,     0,     0,   296,  2876,
     195,     0,     0,     0,     0, -1939,     0,     0,   472,     0,
     297,   298,   473,  2875,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,  2876, -1939, -1939,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2877, -1939,     0,     0,     0,     0,     0,     0,   474, -1939,
       0,     0,     0, -1939,     0,     0,     0,     0,     0,     0,
       0, -1939, -1939, -1939,     0,     0,  2877,     0,     1,     0,
       0,     0,     2,     0,     0,     0,   475,   659,     0,  2878,
     660,     0,     0,     0,   196,   197,     0,     0,   661,   662,
     663,  2879,     0,   476,     0,     0,   664,     0,     0,   665,
       0,     0,     0,  2880,  2881,  2878,   666,   667,     0,     0,
       0,  2882,     0,     0,  2883,     0,     0,  2879,     0,     0,
       0,     0,   218,     0,     0,     0,     0,     0, -1939,  2880,
    2881,     0,     0,     0,     0,     0,     0,  2882,     0, -1939,
    2883,     0,     0,     0,     0,     0,     0,     0,   218,     0,
       0,     0,   668,   669,     0,     0,     0,   670,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   671,   672,     0,
     673,     0,     0,     0,   477,     0,     0,     0, -1939,     0,
       0,     0,     0,     0,   674,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   675,     0,     0,   676,   677,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   678,     0,
     679,   680,   681,     0,     0,     0,     0,     0,     0,     0,
     682,   683,     0,   684,   685,   686,     0,     0,     0, -1939,
     478,   687,     0,     0,   688,     0,   689,   690,   691,     0,
       0,     0,     0,     0,   692,     0,   693,   694,     0,   695,
       0,   696,   697,     0,     0,   698,     0,     0,   699,   700,
     701,   702,   703,   704,     0, -1939,     0,   705,   706,   707,
       0,   708,     0,     0,     0,   709,     0,   710,   711,     0,
       0,     0,     0,   712,     0,     0,   713,     0,     0,   714,
       0,   715,     0,   716,     0,   717,     0,     0,     0,   718,
     719,     0,   720,   721,   722,     0,     0,   723,     0,   724,
     725, -1939,   726,     0,     0,     0,     0,     0,     0,     0,
     727,   728,     0,     0,     0, -1939, -1939, -1939, -1939, -1939,
   -1939, -1939,   729, -1939, -1939,   730,   731,     0,     0,   732,
     733,     0,     0,   734,   735,     0,     0,     0,     0,     0,
   -1939,   736,   737,   738,     0,   739,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   740,   741,   742, -1939,   743,
       0,     0,     0,   744,   745,     0,     0,     0,   746,     0,
       0,     0,     0,     0,     0,     0,   747,     0,     0,     0,
       0,     0,     0,     0,   748,   749,   750,     0,     0,     0,
       0,     0,   751,   752,     0,     0,     0,     0,     0,     0,
     753,     0,     0,   754,     0,     0,     0,   755,   756,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   757,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   758,     0,     0,     0,     0,
       0,     0,     0,   759,     0,     0,     0,     0,     0,   760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     761,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   762,     0,     0,     0,     0,     0,   763,     0,
     764,   765,     0,     0,     0,     0,     0,     0,   766,     0,
       0,     0,     0,     0,     0,     0,  2487,   443,   444,   445,
       0,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   768,     0,
       0,     0,     0,     0,     0,   769,     0,   459,     0,   443,
     444,   445,     0,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,     0,     0,   770,   771,
       0,     0,     0,   772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   773,     0,     0,     0,     0,
       0,   774,   775,   776,   777,     0,     0,     0,   778,   459,
       0,     0,   779,     0,     0,     0,     0,     0,     0,   780,
     781,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,     0,   783,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   784,     0,   785,     0,     0,   786,     0,
       0,     0,     0,     0,   787,   460,   461,   462,   463,   464,
     465,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   466,   467,   468,     0,     0,     0,     0,
     788,     0,     0,   789,     0,     0,     0,     0,   790,     0,
       0,   791,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   793,   460,   461,   462,
     463,   464,   465,   794,     0,     0,     0,     0,     0,  2221,
    2222,  2223,  2224,  2225,  2226,   466,   467,   468,     0,     0,
       0,     0,     0,     0,     0,     0,   795,   796,   797,   798,
     799,   800,   801,     0,     0,   802,     0,   803,     0,   804,
     443,   444,   445,     0,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,     0,     0,     0,
       0,   443,   444,   445,     0,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     459,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,     0,     0,   470,     0,     0,  2227,     0,     0,
       0,   459,     0,   443,   444,   445,     0,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
       0,     0,     0,     0,   443,   444,   445,     0,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,     0,     0,   469,     0,     0,   470,     0,     0,     0,
       0,     0,     0,   459,     0,   443,   444,   445,     0,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,     0,     0,   459,     0,     0,     0,   460,   461,
     462,   463,   464,   465,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   467,   468,   460,
     461,   462,   463,   464,   465,   459,     0,     0,     0,     0,
       0,     0,     0,   471,     0,     0,     0,   466,   467,   468,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,   473,   443,   444,   445,     0,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
       0,   460,   461,   462,   463,   464,   465,     0,     0,     0,
       0,     0,     0,     0,     0,   471,     0,     0,   474,   466,
     467,   468,   460,   461,   462,   463,   464,   465,     0,     0,
     472,     0,     0,   459,   473,   571,     0,     0,     0,     0,
     466,   467,   468,     0,     0,     0,   475,     0,     0,     0,
       0,     0,     0,   460,   461,   462,   463,   464,   465,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
     474,   466,   467,   468,     0,     0,     0,     0,     0,     0,
       0,  2228,     0,     0,   469,     0,     0,   470,     0,     0,
       0,     0,     0,     0,  2229,     0,     0,     0,   475,     0,
       0,     0,     0,     0,     0,   469,     0,     0,   470,     0,
       0,     0,     0,     0,     0,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   460,   461,   462,   463,   464,   465,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,   466,
     467,   468,     0,     0,     0,     0,  2230,   469,     0,     0,
     470,     0,  2231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,     0,
       0,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,     0,     0,     0,
       0,  2232,     0,     0,     0,     0,   471,     0,     0,   469,
     478,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,   472,     0,     0,  2233,   473,   581,   471,     0,     0,
       0,     0,     0,     0,  2234,  2235,     0,     0,     0,     0,
    2236,     0,   472,     0,     0,     0,   473,   943,     0,     0,
    2237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2238,     0,     0,  2239,  2240,     0,     0,   471,
    2241,     0,   474,     0,     0,     0,     0,   469,     0,   475,
     470,     0,     0,     0,   472,     0,     0,     0,   473,   949,
     471,     0,     0,     0,     0,     0,   476,     0,     0,     0,
     475,     0,     0,     0,     0,   472,     0,     0,     0,   473,
     950,     0,     0,     0,     0,     0,     0,   476,     0,     0,
       0,   471,     0,     0,   474,     0,     0,  2242,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,  2243,     0,
     473,   951,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,     0,   475,     0,     0,   474,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,   477,   471,
       0,     0,     0,     0,   475,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   472,     0,     0,     0,   473,   952,
       0,   476,   443,   444,   445,     0,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,     0,
       0,     0,     0,   478,     0,     0,     0,     0,     0,     0,
     477,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
       0,   477,   459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,   444,   445,     0,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   476,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   443,   444,   445,   478,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
       0,     0,   459,     0,   443,   444,   445,   478,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,     0,     0,     0,     0,   478,     0,
     460,   461,   462,   463,   464,   465,     0,     0,     0,     0,
     477,     0,     0,     0,   459,     0,     0,     0,   466,   467,
     468,   443,   444,   445,     0,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,   461,   462,   463,   464,   465,     0,     0,     0,     0,
       0,   459,     0,     0,     0,     0,   478,     0,   466,   467,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   460,   461,   462,   463,   464,   465,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     467,   468,   460,   461,   462,   463,   464,   465,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     466,   467,   468,     0,   445,     0,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,     0,
       0,     0,     0,     0,     0,     0,   469,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,     0,     0,     0,     0,     0,
       0,     0,   459,     0,     0,     0,     0,   466,   467,   468,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   469,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   469,     0,   459,
     470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,     0,
       0,   470,     0,     0,     0,   123,     0,     0,   471,     0,
     460,   461,   462,   463,   464,   465,     0,     0,     0,     0,
       0,     0,     0,   472,     0,     0,     0,   473,   466,   467,
     468,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,     0,     0,   469,     0,     0,   470,     0,
       0,     0,     0,   474,     0,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,   954,   460,   461,   462,
     463,   464,   465,   472,     0,     0,     0,   473,     0,     0,
       0,   475,     0,     0,  2352,   466,   467,   468,     0,   471,
       0,     0,     0,  1259,  1260,  1261,     0,     0,   476,   215,
    1262,  1263,    38,     0,   472,     0,     0,     0,   473,     0,
     471,     0,     0,   474,     0,     0,   126,     0,  1264,  1265,
       0,     0,     0,     0,     0,   472,     0,     0,     0,   473,
       0,     0,   127,   128,     0,     0,     0,     0,     0,     0,
       0,   475,     0,   129,   474,     0,     0,     0,     0,     0,
       0,     0,     0,  2352,     0,     0,   469,   955,   476,   470,
       0,     0,  1259,  1260,  1261,   474,     0,   471,   215,  1262,
    1263,    38,   475,     0,     0,     0,     0,     0,   958,   477,
       0,     0,   472,     0,     0,     0,   473,  1264,  1265,   476,
       0,     0,     0,   475,     0,     0,     0,     0,     0,     0,
       0,     0,  1266,     0,     0,     0,     0,     0,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   469,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   477,
       0,     0,     0,     0,     0,   478,     0,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   476,     0,     0,
     477,  1266,     0,     0,     0,     0,     0,     0,   471,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   477,     0,   472,     0,     0,     0,   473,     0,     0,
       0,     0,     0,     0,     0,   478,     0,     0,     0,     0,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,     0,     0,  1091,     0,     0,
       0,     0,     0,   474,     0,     0,   478,     0,     0,     0,
       0,     0,     0,     0,     0,   471,     0,     0,   477,   131,
       0,     0,     0,     0,     0,     0,     0,   478,     0,     0,
     472,   475,     0,     0,   473,     0,     0,     0,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,   476,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1091,     0,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
     138,     0,   460,   461,   462,   463,   464,   465,   475,  2353,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
     466,   467,   468,     0,     0,   476,     0,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,     0,     0,     0,     0,     0,     0,     0,  2353,     0,
     456,   457,   458,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,   459,   478,   477,     0,     0,     0,
    1267,     0,     0,     0,   145,     0,   459,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,     0,     0,     0,     0,     0,   147,     0,     0,   148,
       0,  1268,     0,     0,  2354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2355,  1270,   469,     0,
     149,   470,     0,     0,   150,     0,     0,     0,     0,  1259,
    1260,  1261,   478,     0,     0,   215,  1262,  1263,    38,  1267,
       0,     0,     0,   151,  1659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1264,  1265,  1271,     0,     0,     0,
       0,   152,   460,   461,   462,   463,   464,   465,  1272,     0,
    1268,     0,     0,  2354,   460,   461,   462,   463,   464,   465,
     466,   467,   468,     0,     0,  2355,  1270,     0,     0,     0,
       0,     0,   466,   467,   468,     0,     0,     0,     0,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,  1273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1271,     0,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,  1272,  1266,     0,
     471,     0,  1274,     0,     0,     0,     0,     0,  1275,     0,
       0,     0,     0,     0,     0,   472,     0,  1276,  1277,   473,
    1278,   452,   453,   454,   455,   456,   457,   458,     0,     0,
     459,     0,  1279,  1280,     0,     0,     0,     0,  1273,     0,
    1281,     0,     0,  1282,     0,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,   474,     0,     0,     0,     0,
       0,   459,     0,     0,     0,     0,     0,     0,   953,     0,
       0,  1274,     0,     0,     0,     0,     0,  1275,   469,     0,
       0,   470,     0,   475,     0,     0,  1276,  1277,     0,  1278,
     469,     0,     0,   470,     0,     0,     0,     0,     0,     0,
     476,  1279,  1280,     0,     0,     0,     0,     0,     0,  1281,
       0,     0,  1282,     0,     0,     0,     0,     0,     0,     0,
     218,     0,     0,  1091,     0,     0,     0,     0,   460,   461,
     462,   463,   464,   465,   450,   451,   452,   453,   454,   455,
     456,   457,   458,  1259,  1260,  1261,   466,   467,   468,   215,
    1262,  1263,    38,     0,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,     0,     0,     0,  1264,  1265,
       0,     0,     0,     0,     0,     0,   459,   466,   467,   468,
       0,   477,     0,     0,     0,     0,     0,     0,  1259,  1260,
    1261,     0,     0,     0,   215,  1262,  1263,    38,     0,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,  1264,  1265,   472,     0,     0,     0,   473,
       0,     0,     0,     0,     0,  2353,     0,   472,  1259,  1260,
    1261,   473,     0,     0,   215,  1262,  1263,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   478,     0,     0,
       0,     0,  1266,  1264,  1265,   474,  1259,  1260,  1261,     0,
       0,     0,   215,  1262,  1263,    38,     0,   474,     0,     0,
       0,     0,     0,     0,   460,   461,   462,   463,   464,   465,
       0,  1264,  1265,   475,   469,     0,     0,   470,     0,     0,
       0,     0,   466,   467,   468,   475,     0,  1266,     0,     0,
     476,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   476,     0,     0,   469,     0,     0,   470,     0,
       0,     0,     0,     0,     0,     0,  1267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1268,     0,     0,
    2354,     0,     0,     0,     0,  1266,     0,     0,     0,     0,
       0,     0,  2355,  1270,     0,     0,     0,  1091,     0,     0,
       0,   477,     0,     0,     0,     0,     0,     0,  1259,  1260,
    1261,     0,     0,   477,   215,  1262,  1263,    38,     0,     0,
       0,     0,     0,     0,     0,     0,   471,     0,     0,     0,
       0,     0,  1271,  1264,  1265,     0,     0,     0,     0,     0,
       0,   472,  1091,     0,  1272,   473,     0,     0,     0,     0,
     469,     0,     0,   470,     0,     0,     0,   471,     0,     0,
       0,     0,  2868,  2869,     0,     0,     0,   478,   215,  1262,
    1263,    38,   472,     0,     0,     0,   473,     0,     0,   478,
       0,   474,  1091,     0,     0,  1273,     0,  1264,  1265,     0,
       0,     0,     0,     0,     0,  2868,  2869,     0,     0,     0,
       0,   215,  1262,  1263,    38,     0,     0,     0,     0,   475,
    1091,     0,   474,     0,     0,     0,     0,  1266,  1274,     0,
    1264,  1265,     0,     0,  1275,     0,   476,     0,     0,     0,
       0,     0,     0,  1276,  1277,     0,  1278,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,  1279,  1280,
       0,     0,     0,     0,     0,     0,  1281,   476,     0,  1282,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,  2870,   471,     0,  1261,     0,     0,     0,   215,  1262,
    1263,    38,     0,     0,     0,     0,     0,   472,     0,     0,
       0,   473,     0,     0,     0,     0,     0,  1264,  1265,     0,
    1267,     0,     0,     0,  2870,     0,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,     0,     0,
       0,  1268,     0,     0,  1269,     0,     0,     0,   477,     0,
       0,     0,  1091,     0,     0,  1267,     0,  1270,     0,     0,
       0,     0,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   476,   478,  1659,     0,  1268,     0,     0,  1269,
       0,  1266,     0,     0,     0,  1267,  1271,     0,     0,     0,
       0,     0,  1270,     0,     0,     0,  1091,     0,  1272,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,  1267,     0,     0,  1268,     0,     0,  1269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1091,
    2189,  1271,  1270,     0,     0,     0,     0,     0,     0,  1273,
       0,     0,     0,  1272,  1268,     0,     0,  1269,     0,     0,
       0,     0,     0,   477,     0,     0,     0,   124,     0,     0,
    1270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3314,  1271,  1274,     0,   125,     0,     0,     0,  1275,     0,
       0,     0,     0,  1272,  1273,     0,     0,  1276,  1277,     0,
    1278,     0,     0,     0,     0,     0,     0,     0,     0,  1271,
       0,     0,  1279,  1280,     0,     0,  1091,     0,     0,     0,
    1281,  1272,     0,  1282,     0,     0,     0,  1274,     0,   478,
       0,   218,     0,  1275,  1273,     0,     0,     0,     0,     0,
       0,     0,  1276,  1277,     0,  1278,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1987,     0,  1279,  1280,     0,
       0,   126,  1273,     0,     0,  1281,     0,  1274,  1282,     0,
       0,     0,     0,  1275,     0,     0,   218,   127,   128,     0,
       0,     0,  1276,  1277,     0,  1278,  1268,     0,   129,  1269,
       0,     0,     0,     0,     0,  1274,     0,  1279,  1280,     0,
       0,  1275,  1270,     0,     0,  1281,     0,     0,  1282,  1267,
    1276,  1277,     0,  1278,     0,     0,   218,     0,     0,  2221,
    2222,  2223,  2224,  2225,  2226,  1279,  1280,     0,     0,     0,
       0,     0,     0,  1281,     0,     0,  1282,     0,     0,     0,
    2871,  1271,  1267,  2872,   218,     0,     0,     0,     0,     0,
       0,     0,     0,  1272,     0,     0,  2873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2871,     0,     0,  2872,     0,     0,     0,
       0,     0,     0,  1659,     0,     0,     0,     0,     0,  2873,
       0,     0,     0,     0,  1273,  2875,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2876,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2227,     0,  1267,
       0,     0,     0,     0,     0,     0,     0,  1274,  2875,     0,
       0,     0,     0,  1275,     0,     0,     0,     0,     0,     0,
    2876,     0,  1276,  1277,     0,  1278,     0,     0,  2877,     0,
    1268,     0,     0,  1269,     0,     0,   130,  1279,  1280,     0,
       0,     0,     0,     0,     0,  1281,  1270,     0,  1282,     0,
       0,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,  2877,     0,     0,     0,     0,     0,  2878,     0,     0,
       0,     0,     0,     0,   131,     0,     0,     0,     0,  2879,
       0,     0,     0,     0,     0,  1271,     0,     0,     0,     0,
       0,  2880,  2881,   132,   133,   134,   135,  1272,     0,  2882,
    2878,  3284,  2883,     0,     0,     0,     0,     0,     0,     0,
     218,   136,  2879,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2880,  2881,     0,     0,     0,     0,
       0,     0,  2882,   137,     0,  2883,     0,     0,  1273,     0,
       0,     0,     0,   218,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,  3285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,   140,     0,     0,     0,     0,  1275,     0,     0,
       0,  3286,   141,     0,     0,     0,  1276,  1277,     0,  1278,
    3287,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,  1279,  1280,     0,     0,     0,     0,     0,     0,  1281,
       0,     0,  1282,     0,     0,     0,     0,     0,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,  3288,     0,
       0,  2228,     0,     0,     0,     0,  3289,   143,     0,     0,
       0,     0,     0,     0,  2229,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,     0,     0,     0,
       0,   147,     0,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,  2230,     0,     0,   150,
       0,     0,  2231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3290,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     0,
       0,  2232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2234,  2235,     0,     0,   153,     0,
    2236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2238,     0,     0,  2239,  2240,     0,     0,     0,
    2241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2242,     0,     0,
       0,     0,     0,     0,     0,     0,  3291,     0,  2243
};

static const short yycheck[] =
{
       3,   208,     5,     6,   267,   268,     9,    10,   966,    52,
     189,   969,  1148,  1143,   503,   774,   558,  1431,    63,   561,
     670,   166,   113,   265,   266,  1028,  1121,  1259,  1260,  1781,
     272,   171,  1103,  1668,  1669,  1670,  1671,     5,  1344,   237,
     786,  1117,  1118,   697,  1120,   569,  1122,  1123,  2037,   611,
    1598,    27,   702,   703,  1337,    98,    59,  2022,    61,  2024,
      20,  2176,  1985,   758,  1562,  1563,    30,    27,  2331,  2107,
      34,    74,  2576,  2577,  2578,  1294,    25,  1296,    27,  2039,
    1729,    24,    85,    26,     5,    88,   191,    27,     5,    92,
      93,     5,  1726,    27,   733,    20,    27,    27,   189,  1720,
      25,    27,    27,    36,   754,  2220,  1102,  1908,   253,    27,
     113,  1659,  2295,   258,   259,    19,    25,   208,    27,     5,
      24,    25,    26,     5,     8,   212,   125,   125,  1199,    25,
       5,    27,   694,    30,    19,    27,     5,    34,     5,    19,
     794,    26,  1213,   705,    24,   324,    26,    19,   776,  2579,
     527,    48,    24,    25,    26,     5,   764,   160,    20,   123,
     163,    27,   165,    25,   269,    27,     5,   170,   273,    25,
     275,    27,   277,   278,   279,    24,    25,    26,    27,    38,
     285,    25,    26,    27,   289,   290,   189,     9,   191,     6,
      12,    13,    14,    15,    16,    17,    27,     6,   760,     5,
    1203,   763,    26,    27,     5,   208,     5,   210,     5,    46,
     772,    52,   162,    24,    25,    26,   113,    19,    41,    24,
      25,    26,    27,    26,    26,  1369,   113,     5,   450,    23,
     144,   145,  1920,   324,    70,  2346,   334,  2348,   329,  2661,
       5,   138,    24,    25,    26,    27,   393,    27,    25,    13,
      27,  1962,    33,   517,  1965,    78,   131,    98,   133,    33,
     135,   264,   265,   266,   267,   268,   269,  2216,    27,   272,
     273,    25,   275,    27,   277,   278,   279,   465,    45,    46,
      41,    25,   285,    27,   200,   201,   289,   290,   205,   489,
      31,   150,   151,   152,   501,    24,    25,    26,    27,     6,
     123,    65,    25,    25,    27,    27,   548,   107,   108,   109,
     110,   111,   148,   149,   419,   513,  2931,   422,   406,  2934,
      30,   324,  2937,   326,    34,   328,   329,   569,   151,     5,
     153,     5,   517,     0,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,     5,   252,  2109,    27,  2282,
    1106,    36,   123,     5,  1494,   470,   471,     5,     5,   646,
     475,   550,   477,     5,     5,  1025,   679,     0,     5,  2014,
       5,   633,   924,     5,    29,   490,   491,   492,   493,     5,
    1386,   668,     5,   498,  2354,     5,     5,  1047,    21,     5,
     534,   541,    23,   252,   227,     5,     5,  1102,     5,   225,
     501,   234,   676,   123,   595,   668,   419,   309,    30,   422,
     627,   673,    34,  1729,   571,  1708,     5,  1430,   252,     5,
     733,    24,    25,    26,    27,   582,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     5,   225,   550,
     436,  1875,     5,   644,   428,     5,    19,   470,   471,   305,
     252,   252,   475,    26,   477,   252,     5,   251,   252,    30,
       5,  1661,   682,    34,     5,     5,  1232,   490,   491,   492,
     493,   676,   981,   715,     5,   498,   583,    48,   501,   542,
     543,   499,   296,   212,   116,     5,   769,   770,   252,   751,
       9,   123,   646,    12,    13,    14,    15,    16,    17,   411,
     417,     5,     5,   252,   127,     5,  1154,   625,   334,   252,
     252,  3146,   535,     5,   537,   798,   627,   213,   801,  1167,
    1128,  1129,   545,     5,   547,   548,     5,   550,   551,     5,
     941,     5,     5,   376,   377,   378,   334,   169,   170,  2508,
       5,     5,   113,   199,   652,     5,   569,   452,   465,    18,
      19,    20,    21,    22,     5,   213,  2264,  1336,   343,   495,
     411,     5,     5,   452,     5,   117,   118,   138,     5,  2300,
     406,    27,    18,    19,    20,    21,    22,   415,    27,   496,
     599,   599,  3024,   521,     5,   982,   455,   668,   669,   496,
     432,   433,   673,   674,  2112,   147,   148,   149,    27,   489,
       5,     5,  1381,  1231,   627,   686,  2549,     5,   525,   423,
     452,   411,     5,   489,     5,   452,   566,   529,     5,   406,
     128,    28,   618,   452,   455,   706,  2611,   517,   709,   452,
    2033,  2034,  2035,   450,   715,  2038,   659,   660,   719,   252,
    1804,   664,   723,   666,   667,   487,   727,   670,   671,   672,
     731,   732,   675,   734,   677,   296,   737,   680,   739,   740,
     741,   673,   596,  2866,     5,  3115,   747,  2802,   691,   750,
    2650,  1386,     5,   534,  1874,   698,   757,   534,   529,   702,
     703,   542,   652,   764,     5,  2253,  2821,     5,  1250,   712,
     771,  1253,  1254,   646,  1364,  1810,   445,  2100,   428,   722,
     646,   782,   725,  1373,  2907,   786,   610,   613,  2717,   790,
     489,   613,   735,   676,   558,   796,   603,  2775,   799,   673,
     743,  2779,   673,   668,  2545,   452,   642,   723,   751,   752,
     718,   754,  1402,   674,  1393,   758,   673,   607,  2747,   668,
    2725,   646,  2727,   723,  1392,   768,   769,   770,  1987,   683,
     734,   610,   676,  2422,   723,   778,  1404,   780,   781,  2085,
     783,  2402,   785,   723,  2090,   529,  2420,   611,   791,  1860,
     793,   613,   795,   723,   797,   798,   676,   800,   801,   674,
     803,  1797,   603,     5,   676,   646,   668,   682,   607,   646,
     452,   485,   635,  2924,   489,   544,   428,  3080,   572,   625,
     489,   452,   645,   682,   668,    23,  3330,   676,   427,   610,
     452,  3094,  2051,  2052,   601,   485,   610,     5,   735,     5,
     640,   516,   517,   679,   646,   448,   334,   625,   485,    27,
      27,   956,   452,   485,   959,   452,   633,   679,   485,   435,
     485,   966,   455,   968,   969,   676,   417,   634,   471,   485,
      27,   676,   485,   452,   583,   485,   485,   306,  1269,   485,
      25,    27,    27,  2266,   607,   297,  1844,  2262,   225,   452,
     319,   401,   401,  2276,   676,    10,  1484,   306,   677,   452,
     355,   725,   517,   578,   452,    27,   909,   729,   730,   452,
     319,   523,   452,   512,   465,   854,   452,  2639,   406,  2641,
     386,   484,  2644,   452,   452,   676,    25,   452,    27,   528,
     603,   452,   452,   432,   433,   571,   529,  1587,   941,  1589,
    1590,   452,   489,  1593,  1594,   496,   236,   676,   595,  1599,
     553,     5,   452,   956,     8,  2920,   959,  2922,  2923,  2457,
    3075,  3224,   450,   966,   743,   968,   969,   403,   452,   452,
    1532,   570,   452,   452,   525,   411,   412,    25,    25,    27,
     452,   513,    30,   303,   987,  2950,   989,  2370,   487,   452,
     452,   420,  1516,   452,   681,   401,   452,   644,   452,   452,
     436,   674,   614,   439,   386,   668,   669,   452,   452,   595,
     609,   420,   452,    26,    27,   421,  1156,   704,    25,   455,
      27,   452,  1025,  1388,  2872,  1675,  1391,   452,   452,   452,
     452,   452,    25,   488,    27,   452,   485,  1040,    25,   638,
      27,   331,   645,   706,  1047,  1106,   709,  3007,   647,  1247,
     306,   452,    28,    29,   657,   658,   719,   452,   644,   485,
     723,   676,   665,   319,   727,   113,   598,   452,   452,   406,
    2200,   734,   538,  3223,   452,   252,   739,  3227,   741,   452,
     489,   452,   694,   676,   747,   452,   228,   750,  1091,    25,
     702,    27,  2475,  1635,   757,   252,  1638,  1100,   296,  1102,
    1103,   764,  1797,   245,   533,  2892,   252,   252,   771,   641,
     646,  2394,   524,  2332,   613,  2334,  2422,  2336,   646,   782,
     549,   489,   558,   786,   533,   635,   635,   790,   306,     5,
     252,   452,  3107,   796,  2137,   682,   799,   625,   415,   452,
     549,   319,  1405,  3118,   646,  1148,  1796,    26,    27,   517,
     562,   452,   646,   252,   452,  1158,   538,  1160,   420,  1918,
    3120,  3084,  1165,   309,   420,  1407,   668,   646,   420,  1230,
    1231,  1232,   736,  1176,   668,   611,  2551,  2552,  2561,  1833,
     679,  1184,   618,   646,   517,   489,  1125,  1749,  1333,    14,
    1335,    25,   239,    27,  1133,   310,  1199,    18,    19,    20,
      21,    22,  1948,    25,   252,    27,    25,   579,    27,    25,
    1213,    27,   516,   306,  1842,   681,  2938,   705,   706,   707,
      25,   646,    27,   379,   646,   423,   319,   395,   716,   635,
     729,   730,   489,   489,   700,   701,    26,    27,   797,   252,
    1419,   800,   420,  1246,   803,   252,    26,    27,  1511,  1512,
     452,   646,  3100,   436,   720,   489,  1259,  1260,  3106,   252,
     489,  3109,  3110,  3111,  3112,   252,  1269,   782,   445,   489,
    1661,   533,  1663,  2032,  1516,   790,  1926,   533,   446,  1282,
     489,   533,  1673,  1674,  1912,   342,   452,  1290,   445,  1680,
    1681,  1682,  1683,   549,   517,   517,  1559,  1560,   355,   681,
      26,    27,    26,    27,   497,   516,   517,  2855,  3095,  3096,
     489,   489,  3277,   342,  1359,   508,   252,   364,   700,   701,
     268,   269,   270,   370,   371,   372,   355,   420,  1419,  2712,
    2089,  2714,   447,   121,   449,  1338,   529,   489,   720,  1342,
    1343,  1344,   535,  2035,   489,   392,  2038,  3211,  3212,  3213,
     543,  1354,  1355,  1356,  2004,   533,   681,  1360,  1361,  1362,
    1363,  1364,   489,  1503,   516,   517,   489,  2438,    20,   417,
    1373,   549,   565,   252,  1274,    27,  1276,  1277,   703,   704,
     642,  2517,  3230,  1386,  2798,  3233,  3234,  3235,  3236,  2484,
     642,  1394,  1395,  1396,   229,  2575,  2576,  2577,  2578,  1402,
     681,    25,  1405,    27,  1407,   484,  2638,  2639,  1411,  2641,
    2481,  2541,  2644,  1416,   489,    24,  1419,    26,   252,   537,
    1423,  1424,   703,   704,   646,   608,   578,   545,   611,   489,
     252,   488,  1974,   252,   220,  3299,   252,  3301,  1980,  1981,
     533,    37,   489,  1106,   489,   660,   668,   252,   496,  2099,
     497,  2757,   489,   500,   676,   489,   549,   672,    26,   488,
     397,   508,   252,  2091,  3099,  2093,  3101,  3102,  3103,  3104,
    2853,   408,   252,  3321,  2102,   489,   691,   525,  1869,   538,
    2863,   741,  1485,   198,   675,  1630,    20,    20,   489,    20,
     750,   682,  2906,    27,    27,   542,    27,   712,   489,  2127,
      20,  1504,   726,   727,   728,  1328,  1509,    27,  1511,  1512,
     725,   459,   489,  1516,   226,   489,   228,  1520,  1521,  1522,
    1523,   458,  2268,   489,  2086,   299,   252,   489,   252,  3281,
     577,  1534,   489,   319,  2492,   472,   796,   696,   697,   799,
    1803,   253,  2500,  2501,  2502,   260,  3298,   262,  2294,   596,
     597,   529,   226,    26,   228,  1558,  1559,  1560,   536,    20,
     607,   489,  2945,   278,   489,   612,    27,  1230,  1231,  1232,
     356,   286,    24,    25,    26,   290,  2138,   489,   226,   253,
     228,   355,   489,  1586,  1587,   181,  1589,  1590,    20,  1694,
    1593,  1594,    26,  1596,  1985,    27,  1599,   489,  3350,   314,
      26,  2251,   709,  1994,   651,   440,  1997,  1998,  1999,  2000,
      20,   172,   173,   174,   427,  3367,   723,    27,   330,   454,
     727,   333,   681,   560,    40,    41,  2188,   299,  1631,    26,
    2280,   452,   739,   227,   420,   409,   683,   164,   165,   413,
     234,   700,   701,   355,  1907,    24,  2296,    26,   434,    26,
    1892,  1893,  2575,  2576,  2577,  2578,   330,   682,  1661,   333,
    1663,   720,   497,   427,   695,  3079,   427,   698,   699,   489,
    1673,  1674,  1675,   508,    25,  1678,    27,  1680,  1681,  1682,
    1683,   355,   330,   355,   682,   333,  1826,   283,  2868,  2869,
    1693,  1694,  2872,    26,   529,   291,  2346,    26,  2348,   512,
     535,   297,   298,    25,  3087,    27,  2938,   355,   543,    25,
     299,    27,  1715,   309,   488,   528,    25,  1720,    27,    24,
    1825,    26,    24,  1726,    26,  1786,  1729,    25,   583,    27,
     565,   124,   427,    25,    25,    27,    27,   409,    26,  1844,
     336,   413,    26,    24,  1747,    26,   676,   533,   512,  1752,
    1753,   512,  2932,   516,   517,  2935,   352,   570,   427,    26,
      24,   357,    26,   549,   528,  1768,   355,   528,   669,   670,
     671,   672,  2314,   369,   479,  2317,   488,  2319,  2320,  1782,
     376,   698,   699,    53,    54,    55,    25,    57,    27,    59,
      60,   427,  1795,  1796,  1797,  3178,   609,  1800,  1801,  1802,
    1803,    25,   489,    27,  2807,   198,   570,   642,   198,   570,
      24,   489,    26,   648,   488,  2443,   488,   512,   489,    24,
     409,    26,  1825,   489,   413,   638,  2476,  1126,  1127,  1832,
     489,  1130,  1131,   528,   647,   489,    25,  1840,    27,   489,
     488,  1844,   489,   512,   489,   609,    45,    46,   609,  1852,
    2478,    20,    21,  2811,  1915,    45,    46,  1860,   489,   528,
     705,   706,   489,  1866,  1867,   680,  1869,   260,   517,   262,
     260,  1874,   262,    26,   638,   570,   512,   638,    18,    19,
      20,    21,    22,   647,   676,   278,   647,  1948,   278,  1892,
    1893,  2282,   528,   286,   705,   706,   286,   290,  3028,   488,
     290,   570,   347,   348,  1907,  2412,  2413,    26,  3038,   452,
     300,  2868,  2869,   452,   609,   319,   489,   489,  3098,   485,
    3100,   314,     5,  1926,   314,  3055,  3106,  3107,   524,  3109,
    3110,  3111,  3112,   529,   570,   452,   422,   452,  3118,   535,
     609,  2120,   489,   638,   452,  2868,  2869,  2338,  2707,  2872,
     452,   452,   647,   452,    26,   452,    20,   489,  1961,  1962,
     529,   557,  1965,  2354,   682,    20,   562,   489,   489,   638,
     452,     5,   517,   609,  2365,   489,   489,   452,   647,    20,
      26,    26,  1985,   489,    26,   154,   155,   156,   157,   158,
     159,  1994,   422,    26,  1997,  1998,  1999,  2000,  2001,    26,
      26,  2004,   638,  2762,   646,  2008,  2009,    30,    26,  2012,
      26,   647,  2666,  2667,  2668,   452,  2670,  2671,  2672,  2673,
    2674,  2675,    26,   646,   452,  2679,    26,   452,   452,  2120,
    2033,  2034,  2035,   452,     5,  2038,  2039,  2040,   362,   452,
    2043,   452,   680,   222,   452,    53,    54,    55,     5,    57,
    3230,    59,    60,  3233,  3234,  3235,  3236,   452,   237,   238,
     330,   452,   676,   333,   452,   335,   452,   246,     5,  2072,
    3200,  2074,  2075,    26,  2077,  2078,  2079,   452,  2081,  3259,
     682,    46,  2085,   452,   452,   355,   489,  2090,  2738,   682,
      26,  2094,  2095,  2096,  2097,   365,  2099,  2100,   452,    26,
    2103,   280,   646,  2106,  2107,   452,   682,    25,    25,    25,
     289,   452,  2115,    25,   452,   452,   386,  2120,   695,   696,
     697,   698,   699,  1786,   452,   452,   452,  2518,   517,   452,
     682,  2134,   452,   489,   674,   676,     8,  2765,   317,   409,
     676,  3321,   485,   413,   122,   652,   686,   112,   113,   536,
    3330,   681,   326,   518,     5,   674,   674,   652,  2549,   518,
     479,   738,    53,    54,    55,  2793,    57,   715,    59,    60,
     388,   676,   517,   715,  2663,   715,   668,  3100,   676,  2182,
    3310,   653,   361,  3106,  3107,     5,  3109,  3110,  3111,  3112,
     479,   731,   732,     5,   489,  3118,   489,   737,  2201,   489,
     740,  2262,   489,   489,   406,     8,  3209,  2268,  3284,  3285,
    3286,  3287,  3288,  3289,   635,    14,     5,   632,   488,   715,
      27,     5,   943,   479,   189,   946,   405,   948,   949,   950,
     951,   952,   210,  2294,   715,   489,   489,   676,    26,    26,
      47,   128,   489,   208,   738,    26,   646,   489,  2251,   489,
     479,   489,  1915,   489,   489,  2646,   489,   489,    26,    26,
       5,    25,   489,  2266,   489,     5,   489,   652,   682,   489,
    2313,  2274,  2275,  2276,  2924,   682,  2279,  2280,   718,  2282,
     681,   412,  2285,   613,  2287,  1948,     5,    18,   452,  2531,
     673,  2533,  2295,  2296,    19,  2474,   215,  2300,   263,   444,
     646,    25,   539,   679,   635,   539,   676,  3230,   213,  2516,
    3233,  3234,  3235,  3236,     5,    26,   459,   383,   603,   452,
     603,   603,   330,    20,    21,   333,    26,   335,   452,   452,
     682,   452,   529,   583,   676,  2338,   452,   452,   682,   485,
     489,   698,  3300,  2346,   120,  2348,  2349,   355,   673,  2352,
     489,  2354,   317,   318,   489,   489,     5,   365,   720,   324,
     489,   168,  2365,   676,   329,   722,   646,  2370,   452,  2372,
     676,   646,  2914,  3119,  2916,  2917,   489,   603,   386,   673,
       5,  2384,  2487,  2474,     5,   682,     5,  2492,   636,     5,
     540,   489,     5,     8,   673,  2500,  2501,  2502,  3321,  2402,
     676,   409,    26,   681,  3032,   413,    26,  3330,   682,   379,
     217,   768,   128,   280,   387,     5,     5,  2420,   489,  2422,
     452,   778,  3050,   421,   781,  2516,   489,   489,   785,    14,
    3433,   653,  2435,   682,   791,  2438,   793,   607,   603,   330,
       5,   162,   333,   716,   335,   252,  2449,   254,    26,  2452,
     489,   682,   489,  2353,     5,  2355,   603,   154,   155,   156,
     157,   158,   159,   676,   355,  2468,   681,  2470,   452,  2472,
     682,  2474,  2475,  2476,   365,   239,   695,   681,  2481,     5,
     488,     5,     5,   452,  2487,   452,   429,   675,    26,  2492,
    2551,  2552,   393,  2496,   519,   386,   489,  2500,  2501,  2502,
     519,   489,   489,   489,   489,     5,   489,   489,   489,   676,
       5,     8,   517,  2516,  2517,  2518,   676,   676,   409,     5,
    2783,   633,   413,   610,   489,   387,    25,   406,  2531,   406,
    2533,   406,   676,  2796,   489,   421,   501,   517,   484,     5,
     517,     5,   349,    26,   707,     5,  2549,     5,    25,    14,
    2941,    14,  2943,    26,   489,   652,   652,   610,  2561,   673,
       5,     5,   682,  3191,    26,   489,     6,   452,   452,   452,
     452,   452,  2575,  2576,  2577,  2578,  2579,  2580,     7,   328,
     506,   452,     8,   452,     5,   550,   680,   676,    26,    26,
     682,  2594,    26,    26,    26,   676,   676,   488,  2777,  2262,
     364,    20,   452,     8,     5,  2268,   370,   371,   372,   623,
    1240,   418,   334,     5,     5,     5,   724,   452,     5,   426,
       8,   628,   676,   430,   603,   452,  2629,  2630,   392,   489,
     529,  2294,   682,     5,     5,  2638,  2639,   603,  2641,   682,
     273,  2644,   452,  2646,   452,    26,   452,  2650,   489,   489,
       5,  2575,  2576,  2577,  2578,     5,    25,    25,   682,   466,
     682,   682,   627,    25,   675,   682,   505,    25,    25,   356,
      26,     5,    26,    26,    26,  2575,  2576,  2577,  2578,    26,
      26,   452,   452,  1040,    26,   489,  2777,   452,   526,   452,
       5,   489,   452,  3084,   607,     8,   661,   662,   663,   301,
     665,    26,    25,   485,   452,   452,  2811,  3098,   499,  2712,
    2713,  2714,  3254,  3255,   406,    20,   204,   682,   696,   697,
     610,     5,     5,   489,   531,    14,   273,   489,   489,   452,
     489,   489,   489,   497,   489,  2738,   500,   452,     5,   517,
    2640,    26,  2642,   452,   508,    26,   500,  2750,  2751,   452,
      26,  2754,   489,   718,  2757,    18,    19,    20,    21,   724,
      26,   726,   452,   570,    26,   730,    26,   435,   733,   625,
      26,   736,  2775,   452,  2777,  2778,  2779,   452,   542,   301,
    2783,   746,   452,  2786,   489,  3027,   452,   594,   406,   302,
     517,  1148,   499,  2796,   603,   489,   761,   452,    14,   452,
     452,  1158,   767,  1160,     7,    26,   300,   300,  2811,   774,
     775,   776,   452,   577,   682,   780,   794,   452,   489,   453,
    2823,   676,   452,   788,   452,    26,   804,   632,   489,   485,
      25,   638,   596,   597,   302,  3226,   517,     5,   452,   804,
     647,   452,   452,   607,  2847,   452,   452,    26,   612,    26,
    2853,   452,   676,   676,     5,   452,   485,    26,   676,  2862,
    2863,  2495,  2865,  2866,  2435,  2868,  2869,  3360,   485,  2872,
    2172,  1524,  3263,   968,  1853,    34,    36,    18,    19,  2468,
    2883,  2109,  2103,   243,   120,    26,    27,   651,  2551,  2552,
     646,   154,   155,   156,   157,   158,   159,  1328,   108,   568,
     572,   360,   359,  1258,  2907,  3350,    47,    18,    19,    20,
      21,  1752,   959,   400,   780,  1959,  1237,  1966,  1802,   683,
    2096,  2924,  2520,  1558,   731,   732,  2833,  1561,  1882,  2932,
    2197,  2417,  2935,  3404,  2099,  2938,  1407,  1902,  2941,  3046,
    2943,    21,  2945,    98,  2868,  2869,    46,  2313,  2872,    27,
     911,   736,  3013,  1858,  1864,  1535,   329,  1482,   989,  1566,
    1204,  1867,  3023,   941,  2969,  3154,   761,  3367,  2868,  2869,
    1480,  1391,  2872,  2518,  1401,  2705,  1504,  3164,  1832,  2703,
    2688,   122,   438,  2382,  3025,  3376,  3023,  2763,  3016,  2090,
    1732,  1621,  1622,   134,  2754,  1715,  2262,  2043,  1628,  2945,
    3376,  1601,  1601,  2281,  3007,  1937,  2711,  2865,  3178,  3216,
    2745,  1925,  2004,  2630,  2352,  2629,  2935,  2733,  3259,  2405,
     161,  1586,  2988,  2384,  3027,  2349,   579,     9,  3422,  2371,
    1233,  3034,  2372,  2867,  1674,  2562,  1673,  1394,  1395,  1396,
    2943,  2862,  1580,   154,   155,   156,   157,   158,   159,  3220,
    1028,  1229,  3098,  1553,  1411,  3117,  2275,  3106,  3119,  2474,
    2476,  1693,  1091,  1028,  1424,  2120,  1416,  3070,   540,    -1,
    1406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1044,
      -1,  3084,    -1,    -1,  3087,    -1,    -1,    -1,    -1,  2575,
    2576,  2577,  2578,    -1,    -1,  3098,    -1,  3100,    -1,    -1,
      -1,    -1,    -1,  3106,  3107,    -1,  3109,  3110,  3111,  3112,
      -1,   252,  3115,   254,  3117,  3118,    -1,  3120,    -1,    -1,
      -1,  1086,    -1,    -1,    -1,  3216,    -1,    -1,  1485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1504,    -1,    -1,
      -1,  1116,  1117,  1118,    -1,  1120,    -1,  1122,  1123,    -1,
      -1,    -1,    -1,  1128,  1129,    -1,  1523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3178,  3100,  1534,    -1,    -1,
      -1,    -1,  3106,  3107,    -1,  3109,  3110,  3111,  3112,  1154,
      -1,    -1,    -1,    -1,  3118,  3300,    -1,    -1,    -1,    -1,
    3100,    -1,  1167,    -1,    -1,  1835,  3106,  3107,   349,  3109,
    3110,  3111,  3112,  3216,  1179,    -1,    -1,  3220,  3118,    -1,
      -1,    -1,    -1,  3226,    -1,  1203,    -1,  3230,    -1,    -1,
    3233,  3234,  3235,  3236,    -1,  3238,    -1,    -1,  1203,  1204,
      -1,    -1,    -1,   384,    -1,    -1,    -1,  1212,  1878,  3252,
      -1,    -1,    -1,    -1,    -1,    -1,  3259,    -1,    -1,    -1,
    3263,    -1,    -1,  1228,  1229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,
      -1,  1259,  1260,    -1,    -1,    -1,    -1,    -1,    -1,   430,
      -1,  1269,  3295,  3296,    -1,    -1,    -1,  3300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3230,    -1,    -1,  3233,
    3234,  3235,  3236,    -1,    -1,    -1,    -1,    -1,  3321,    -1,
      -1,    -1,    -1,    -1,    -1,   466,    -1,  3330,    -1,    -1,
    3230,    -1,    -1,  3233,  3234,  3235,  3236,    -1,    -1,    -1,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1336,    -1,  3376,    -1,  3378,    -1,    -1,    -1,    -1,
      -1,    -1,  2868,  2869,    -1,    -1,  2872,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1752,  3399,  3321,    -1,    -1,
      -1,    -1,    -1,    -1,   545,    -1,  3330,    -1,    -1,    -1,
      -1,  1768,    -1,    -1,    -1,    -1,  1381,  3420,  3421,  3422,
      -1,  3321,    -1,  1388,    -1,    -1,  1391,  1392,  1393,   570,
    3330,    -1,  3435,    -1,    -1,  1400,  1401,    -1,  1795,  1404,
      -1,    -1,    -1,  1408,    -1,  1802,  2932,    -1,    -1,  2935,
      -1,    -1,  1430,   594,  1419,    -1,  3119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1430,  1431,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1832,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,  1852,    -1,   638,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   647,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1481,  1482,    -1,  1484,
      -1,    -1,  1487,  1488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2166,  2167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2177,    -1,    -1,
      -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2202,  2203,  2204,  2205,  2206,  2207,    -1,    -1,
      -1,  1546,  2212,  2213,  2214,  2215,    -1,    -1,  1566,  2219,
     731,   732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1565,  1566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,  3100,    -1,    -1,    -1,    -1,    -1,
    3106,  3107,    -1,  3109,  3110,  3111,  3112,    -1,    -1,    -1,
      -1,    -1,  3118,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,   310,    -1,    -1,   313,    -1,    -1,    -1,    18,    19,
    3136,    -1,    -1,    -1,    24,    25,    26,    27,  1623,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,  2301,  2302,    -1,    -1,    -1,    -1,    47,  2308,  2309,
      -1,    -1,    -1,  1661,    -1,  1663,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1673,  1674,    -1,    -1,    -1,
      -1,    -1,  1680,  1681,  1682,  1683,    -1,    -1,   154,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2079,   126,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2094,  2095,  2096,
    2097,    -1,    -1,    -1,  3230,    -1,    -1,  3233,  3234,  3235,
    3236,    -1,   122,    -1,    -1,    -1,    -1,   127,  2115,    -1,
      -1,    -1,    -1,   432,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3259,    -1,    -1,    -1,    -1,   447,    -1,
      -1,    -1,   451,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   161,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,    -1,  2182,    -1,    -1,  2458,  2459,
      -1,    -1,    -1,    -1,    -1,  3321,    -1,  2467,    -1,    -1,
      -1,    -1,    -1,    -1,  3330,    -1,   515,    -1,    -1,   257,
      -1,    -1,    -1,  1818,    -1,  1833,   264,    -1,    -1,    -1,
      -1,    -1,    -1,   532,   310,   136,   137,   313,   139,   140,
     141,    -1,    -1,    -1,    -1,  2505,  2506,  1842,    -1,    -1,
      -1,    -1,   252,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,  1869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1864,
      -1,    -1,  2532,    -1,  2534,    -1,    -1,    -1,  1873,    -1,
    1875,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2285,    -1,
    2287,    -1,    -1,    -1,    -1,    -1,   344,    -1,    -1,    -1,
      -1,    -1,    -1,   351,   613,   353,    -1,  1912,  1913,  1914,
      -1,    -1,    -1,  1918,    -1,   363,   359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2595,  2596,   238,    -1,  2599,
    2600,    -1,    -1,    -1,    -1,   246,   379,   380,   381,   349,
      -1,    -1,    -1,   391,   354,    -1,   432,    -1,  1953,    -1,
      -1,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   447,    -1,    -1,    -1,   451,    -1,  1985,    -1,   280,
     679,    -1,    -1,    -1,   384,   418,  1994,    -1,   289,  1997,
    1998,  1999,  2000,    -1,    -1,    -1,    -1,   430,   436,    -1,
      -1,  2009,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,
      -1,   487,    -1,    -1,    -1,    -1,   317,   318,   418,    -1,
      -1,    -1,   460,    -1,   457,    -1,    -1,    -1,    -1,    -1,
     430,  2039,    -1,    -1,   467,    -1,    -1,  2032,    -1,   515,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,   482,
      -1,    -1,    -1,   453,    -1,   455,   532,    -1,    -1,   497,
     361,    -1,  2449,    -1,    -1,  2452,   466,    -1,    -1,    -1,
     508,   471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   481,    -1,    -1,    -1,    -1,   486,    -1,    -1,   489,
      -1,    -1,   492,    -1,  2089,    -1,  2091,   530,  2093,    -1,
      -1,   501,   502,    -1,   405,    -1,    -1,  2102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2776,    -1,    -1,    -1,
    2780,    -1,    -1,    -1,    -1,  2120,   559,    -1,    -1,  2137,
    2517,    -1,  2127,    -1,    -1,    -1,   569,   613,    -1,  2799,
     540,   541,  2137,    -1,    -1,   545,    -1,    -1,    -1,    -1,
      -1,  2146,    -1,   553,    -1,  2150,    -1,   590,   459,  2819,
      -1,   594,    -1,    -1,   564,    -1,    -1,   605,   606,   607,
     570,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     618,  2176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,    -1,   594,    -1,    -1,    -1,   631,     5,
       6,     7,     8,   679,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,    -1,
      -1,    -1,    -1,    -1,    -1,   645,    -1,   647,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,   657,   658,    -1,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2282,    -1,   676,    -1,    -1,    -1,
      -1,    -1,    -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   737,
      -1,    -1,    -1,    -1,  2299,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2338,   731,   732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2352,    -1,  2354,    -1,   154,   155,
     156,   157,   158,   159,    -1,    56,    -1,  2365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2371,    -1,    -1,    -1,
      -1,    -1,    -1,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,    -1,    -1,    -1,    -1,    -1,    -1,  2786,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3068,  2417,
      22,  3071,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,  2823,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,  2443,    -1,
      47,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,    -1,    -1,    -1,     9,    -1,  2474,
      -1,    -1,    -1,  2478,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,  2493,    -1,
    2495,    -1,  2497,    -1,   310,    -1,    -1,   313,    -1,    -1,
    2518,    -1,    -1,    -1,    -1,    47,  2511,    -1,    -1,    -1,
      -1,  2516,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,  2549,   154,   155,   156,   157,   158,   159,  2543,  2544,
      -1,    -1,    -1,    -1,  3214,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,   161,    -1,    -1,  2575,  2576,  2577,
    2578,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,  2589,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,  3265,  3266,    -1,  3268,   310,
    3270,  3271,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2629,  2630,    -1,    -1,    -1,   432,    -1,    -1,   161,
    2638,  2639,    -1,  2641,    -1,    -1,  2644,    -1,  2646,    -1,
      -1,   447,  2650,    -1,    -1,   451,    -1,  3034,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,    -1,   254,  2666,  2667,
    2668,    -1,  2670,  2671,  2672,  2673,  2674,  2675,    -1,    -1,
      -1,  2679,    -1,    -1,    -1,    -1,    -1,    -1,  3338,    -1,
    3340,   487,    -1,  3070,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2690,    -1,    -1,   310,    -1,
      -1,   313,    -1,    -1,    -1,    -1,    -1,  2702,    -1,   515,
      -1,    -1,  2707,    -1,  3374,    -1,    -1,    -1,    -1,    -1,
     252,    -1,   254,    -1,    -1,    -1,   532,    -1,    -1,    -1,
      -1,   432,    -1,  3393,  3394,    -1,    -1,  3397,    -1,    -1,
    3400,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,
     451,   452,   349,    -1,    -1,    -1,    -1,   354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2762,    -1,    -1,
    2765,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2777,    -1,    -1,    -1,   487,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2793,  2807,
      -1,    -1,    -1,  2798,    -1,    -1,    -1,   613,    -1,    -1,
      -1,    -1,  2807,    -1,   515,    -1,    -1,   349,    -1,    -1,
     432,   418,   354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   532,    -1,   430,    -1,   447,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,   384,    -1,    -1,    -1,   453,    -1,   455,    -1,
    2868,  2869,     9,    -1,  2872,    -1,    -1,    -1,    -1,   466,
      -1,    18,    19,   679,   471,   487,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,   481,    -1,   418,    -1,    -1,   486,
      -1,    -1,   489,    -1,    -1,   492,    -1,    -1,   430,    -1,
      47,    -1,    -1,   515,   501,   502,    -1,    -1,  3295,    -1,
      -1,  2906,   613,    -1,    -1,    -1,   448,    -1,    -1,    -1,
     532,   453,    -1,   455,  2932,    -1,    -1,  2935,    -1,    -1,
    2938,    -1,    -1,  2941,   466,  2943,    -1,    -1,    -1,   471,
      -1,    -1,    -1,   540,   541,    -1,    -1,    -1,   545,   481,
      -1,    -1,    -1,    -1,   486,    -1,   553,   489,    -1,    -1,
     492,    -1,    -1,    -1,    -1,    -1,    -1,   564,    -1,   501,
     502,    -1,    -1,   570,  2969,   122,    -1,    -1,   679,    -1,
     127,    17,    18,    19,    20,    21,    22,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,  3007,
      -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,
      -1,    -1,  3399,   545,   161,    -1,    -1,    -1,    -1,    -1,
      56,   553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   564,    -1,   566,    -1,    -1,  3032,   570,    -1,
      -1,   638,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,
     647,    -1,    -1,    -1,    -1,  3050,    -1,    -1,    -1,    -1,
     657,   658,   594,    -1,    -1,    -1,    -1,   679,   665,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3084,    -1,    -1,   676,
      -1,    -1,    -1,    -1,  3079,    -1,    -1,    -1,    -1,    -1,
    3098,    -1,  3100,    -1,    -1,    -1,    -1,    -1,  3106,  3107,
      -1,  3109,  3110,  3111,  3112,   252,   638,   254,    -1,    -1,
    3118,    -1,  3120,   645,    -1,   647,    -1,    -1,   154,   155,
     156,   157,   158,   159,    -1,   657,   658,    -1,  3136,    -1,
      -1,    -1,     9,   665,   731,   732,   172,   173,   174,    -1,
      -1,    18,    19,    -1,   676,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3154,
      -1,    -1,    -1,    -1,  3159,    -1,  3161,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3191,    -1,    -1,   731,
     732,  3209,   349,    -1,    -1,    -1,    -1,   354,    -1,    -1,
      -1,    -1,    -1,    -1,  3209,    -1,    -1,    -1,  3226,    -1,
      -1,  3216,  3230,    -1,    -1,  3233,  3234,  3235,  3236,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,   384,    -1,    -1,
      24,    25,    26,    27,    -1,   122,    -1,    -1,    -1,    -1,
     127,  3259,    -1,    -1,    -1,  3263,    -1,   134,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,   418,    -1,    -1,   310,    -1,    -1,   313,    -1,    -1,
      -1,    -1,    -1,   430,   161,    43,    44,    -1,    -1,  3284,
    3285,  3286,  3287,  3288,  3289,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,   453,    -1,   455,    -1,
      -1,    -1,    -1,  3321,    -1,    -1,    -1,    -1,    -1,   466,
      -1,    -1,  3330,    -1,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,   486,
      -1,    -1,   489,   127,    -1,   492,    15,    16,    17,    18,
      19,    20,    21,    22,   501,   502,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3376,   127,
      -1,    -1,    -1,    -1,    -1,   252,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,   540,   541,    -1,   432,    -1,   545,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,
      -1,   447,    -1,    -1,    -1,   451,    -1,   564,    -1,    -1,
      -1,    -1,    -1,   570,    -1,  3433,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,  3433,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,    -1,
      -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    -1,    57,   252,    59,
      60,    -1,   349,    -1,    -1,    -1,    -1,   354,    -1,   515,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   638,    -1,    -1,   252,    -1,   532,    -1,   645,    -1,
     647,    -1,    -1,   172,   173,   174,    -1,   384,    -1,    -1,
     657,   658,    -1,    -1,    -1,    -1,    -1,    -1,   665,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,   453,   613,   455,    -1,
      -1,    -1,    -1,    -1,   731,   732,    -1,    -1,    -1,   466,
      -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,   198,   486,
      -1,    -1,   489,    -1,    -1,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   501,   502,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,   228,    -1,
      -1,   310,    -1,   679,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   541,    -1,    -1,    -1,   545,    -1,
     260,   455,   262,    -1,    -1,    -1,   553,    -1,    -1,    -1,
      -1,    -1,    -1,   273,    -1,    -1,    -1,   564,   278,    -1,
      -1,    -1,    -1,   570,    -1,    -1,   286,   455,    -1,    -1,
     290,    -1,   486,    -1,    -1,   489,   296,    -1,    -1,   299,
     300,   301,   302,    -1,    -1,    -1,    -1,   594,   502,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,   486,    -1,
      -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     330,    -1,    -1,   333,   502,   335,    -1,    -1,    -1,    -1,
      -1,    -1,   342,    -1,    -1,    -1,   540,   541,    -1,    -1,
      -1,   638,    -1,   432,    -1,   355,    -1,    -1,   645,   553,
     647,    -1,    -1,    -1,    -1,   365,    -1,    -1,   447,    -1,
     657,   658,   451,   541,    -1,    -1,    -1,    -1,   665,    -1,
      -1,    -1,    -1,    -1,    -1,   553,   386,   387,    -1,   676,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     594,   401,    -1,    -1,    -1,    -1,    -1,    -1,   487,   409,
      -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   422,   423,    -1,    -1,   594,    -1,    30,    -1,
      -1,    -1,    34,    -1,    -1,    -1,   515,    39,    -1,   633,
      42,    -1,    -1,    -1,   731,   732,    -1,    -1,    50,    51,
      52,   645,    -1,   532,    -1,    -1,    58,    -1,    -1,    61,
      -1,    -1,    -1,   657,   658,   633,    68,    69,    -1,    -1,
      -1,   665,    -1,    -1,   668,    -1,    -1,   645,    -1,    -1,
      -1,    -1,   676,    -1,    -1,    -1,    -1,    -1,   488,   657,
     658,    -1,    -1,    -1,    -1,    -1,    -1,   665,    -1,   499,
     668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,
      -1,    -1,   114,   115,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
     132,    -1,    -1,    -1,   613,    -1,    -1,    -1,   538,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    -1,    -1,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,
     182,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,   195,   196,   197,    -1,    -1,    -1,   599,
     679,   203,    -1,    -1,   206,    -1,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,   216,    -1,   218,   219,    -1,   221,
      -1,   223,   224,    -1,    -1,   227,    -1,    -1,   230,   231,
     232,   233,   234,   235,    -1,   635,    -1,   239,   240,   241,
      -1,   243,    -1,    -1,    -1,   247,    -1,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,   258,    -1,    -1,   261,
      -1,   263,    -1,   265,    -1,   267,    -1,    -1,    -1,   271,
     272,    -1,   274,   275,   276,    -1,    -1,   279,    -1,   281,
     282,   681,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     292,   293,    -1,    -1,    -1,   695,   696,   697,   698,   699,
     700,   701,   304,   703,   704,   307,   308,    -1,    -1,   311,
     312,    -1,    -1,   315,   316,    -1,    -1,    -1,    -1,    -1,
     720,   323,   324,   325,    -1,   327,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   337,   338,   339,   738,   341,
      -1,    -1,    -1,   345,   346,    -1,    -1,    -1,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   366,   367,   368,    -1,    -1,    -1,
      -1,    -1,   374,   375,    -1,    -1,    -1,    -1,    -1,    -1,
     382,    -1,    -1,   385,    -1,    -1,    -1,   389,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,   431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,   460,    -1,
     462,   463,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,    -1,
      -1,    -1,    -1,    -1,    -1,   527,    -1,    56,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   550,   551,
      -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,
      -1,   573,   574,   575,   576,    -1,    -1,    -1,   580,    56,
      -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,   591,
     592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     602,    -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   615,    -1,   617,    -1,    -1,   620,    -1,
      -1,    -1,    -1,    -1,   626,   154,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,    -1,
     652,    -1,    -1,   655,    -1,    -1,    -1,    -1,   660,    -1,
      -1,   663,   664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   678,   154,   155,   156,
     157,   158,   159,   685,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   708,   709,   710,   711,
     712,   713,   714,    -1,    -1,   717,    -1,   719,    -1,   721,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   310,    -1,    -1,   313,    -1,    -1,   160,    -1,    -1,
      -1,    56,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   310,    -1,    -1,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    56,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   154,
     155,   156,   157,   158,   159,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,    -1,    -1,    -1,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,
      -1,    -1,   451,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,   487,   172,
     173,   174,   154,   155,   156,   157,   158,   159,    -1,    -1,
     447,    -1,    -1,    56,   451,   452,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,    -1,    -1,   515,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,
     487,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   394,    -1,    -1,   310,    -1,    -1,   313,    -1,    -1,
      -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,   515,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,   313,    -1,
      -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,   172,
     173,   174,    -1,    -1,    -1,    -1,   469,   310,    -1,    -1,
     313,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,    -1,
      -1,   514,    -1,    -1,    -1,    -1,   432,    -1,    -1,   310,
     679,    -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   447,    -1,    -1,   537,   451,   452,   432,    -1,    -1,
      -1,    -1,    -1,    -1,   547,   548,    -1,    -1,    -1,    -1,
     553,    -1,   447,    -1,    -1,    -1,   451,   452,    -1,    -1,
     563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   487,   679,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,   588,   589,    -1,    -1,   432,
     593,    -1,   487,    -1,    -1,    -1,    -1,   310,    -1,   515,
     313,    -1,    -1,    -1,   447,    -1,    -1,    -1,   451,   452,
     432,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,
     515,    -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,   451,
     452,    -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,
      -1,   432,    -1,    -1,   487,    -1,    -1,   650,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,   661,    -1,
     451,   452,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,
      -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,   515,    -1,    -1,   487,   613,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,   432,
      -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,   451,   452,
      -1,   532,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,
      -1,   613,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   515,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   532,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   679,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    56,    -1,     6,     7,     8,   679,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,   679,    -1,
     154,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     613,    -1,    -1,    -1,    56,    -1,    -1,    -1,   172,   173,
     174,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,   679,    -1,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   154,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,   313,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   310,    -1,    -1,   313,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    56,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,   313,    -1,    -1,    -1,     5,    -1,    -1,   432,    -1,
     154,   155,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   447,    -1,    -1,    -1,   451,   172,   173,
     174,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,   313,    -1,
      -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,   432,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   500,   154,   155,   156,
     157,   158,   159,   447,    -1,    -1,    -1,   451,    -1,    -1,
      -1,   515,    -1,    -1,     9,   172,   173,   174,    -1,   432,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,   532,    24,
      25,    26,    27,    -1,   447,    -1,    -1,    -1,   451,    -1,
     432,    -1,    -1,   487,    -1,    -1,   126,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,   451,
      -1,    -1,   142,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   515,    -1,   153,   487,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,   310,   500,   532,   313,
      -1,    -1,    18,    19,    20,   487,    -1,   432,    24,    25,
      26,    27,   515,    -1,    -1,    -1,    -1,    -1,   500,   613,
      -1,    -1,   447,    -1,    -1,    -1,   451,    43,    44,   532,
      -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   487,   310,    -1,    -1,   313,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,
      -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,
     515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,
     613,   127,    -1,    -1,    -1,    -1,    -1,    -1,   432,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   613,    -1,   447,    -1,    -1,    -1,   451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,
      -1,   321,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,   487,    -1,    -1,   679,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,   613,   359,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,
     447,   515,    -1,    -1,   451,    -1,    -1,    -1,   378,   379,
     380,   381,    -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
     487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,
      -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,
     430,    -1,   154,   155,   156,   157,   158,   159,   515,   354,
      -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,    -1,   532,    -1,   457,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,    -1,   613,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     530,    -1,    -1,    -1,    56,   679,   613,    -1,    -1,    -1,
     455,    -1,    -1,    -1,   544,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
      -1,    -1,    -1,    -1,    -1,    -1,   566,    -1,    -1,   569,
      -1,   486,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   501,   502,   310,    -1,
     590,   313,    -1,    -1,   594,    -1,    -1,    -1,    -1,    18,
      19,    20,   679,    -1,    -1,    24,    25,    26,    27,   455,
      -1,    -1,    -1,   613,   529,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,   541,    -1,    -1,    -1,
      -1,   631,   154,   155,   156,   157,   158,   159,   553,    -1,
     486,    -1,    -1,   489,   154,   155,   156,   157,   158,   159,
     172,   173,   174,    -1,    -1,   501,   502,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   673,    -1,    -1,    -1,    -1,    -1,   594,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   541,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   553,   127,    -1,
     432,    -1,   627,    -1,    -1,    -1,    -1,    -1,   633,    -1,
      -1,    -1,    -1,    -1,    -1,   447,    -1,   642,   643,   451,
     645,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      56,    -1,   657,   658,    -1,    -1,    -1,    -1,   594,    -1,
     665,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   676,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,   500,    -1,
      -1,   627,    -1,    -1,    -1,    -1,    -1,   633,   310,    -1,
      -1,   313,    -1,   515,    -1,    -1,   642,   643,    -1,   645,
     310,    -1,    -1,   313,    -1,    -1,    -1,    -1,    -1,    -1,
     532,   657,   658,    -1,    -1,    -1,    -1,    -1,    -1,   665,
      -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,    -1,    -1,   252,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    18,    19,    20,   172,   173,   174,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    56,   172,   173,   174,
      -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   432,    43,    44,   447,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    -1,    -1,   354,    -1,   447,    18,    19,
      20,   451,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   679,    -1,    -1,
      -1,    -1,   127,    43,    44,   487,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,   487,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
      -1,    43,    44,   515,   310,    -1,    -1,   313,    -1,    -1,
      -1,    -1,   172,   173,   174,   515,    -1,   127,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   532,    -1,    -1,   310,    -1,    -1,   313,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,
     489,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   501,   502,    -1,    -1,    -1,   252,    -1,    -1,
      -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,   613,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,
      -1,    -1,   541,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,   447,   252,    -1,   553,   451,    -1,    -1,    -1,    -1,
     310,    -1,    -1,   313,    -1,    -1,    -1,   432,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,   679,    24,    25,
      26,    27,   447,    -1,    -1,    -1,   451,    -1,    -1,   679,
      -1,   487,   252,    -1,    -1,   594,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,   515,
     252,    -1,   487,    -1,    -1,    -1,    -1,   127,   627,    -1,
      43,    44,    -1,    -1,   633,    -1,   532,    -1,    -1,    -1,
      -1,    -1,    -1,   642,   643,    -1,   645,    -1,    -1,    -1,
     515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,   658,
      -1,    -1,    -1,    -1,    -1,    -1,   665,   532,    -1,   668,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,
      -1,   127,   432,    -1,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
     455,    -1,    -1,    -1,   127,    -1,    -1,   613,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,   486,    -1,    -1,   489,    -1,    -1,    -1,   613,    -1,
      -1,    -1,   252,    -1,    -1,   455,    -1,   502,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   532,   679,   529,    -1,   486,    -1,    -1,   489,
      -1,   127,    -1,    -1,    -1,   455,   541,    -1,    -1,    -1,
      -1,    -1,   502,    -1,    -1,    -1,   252,    -1,   553,    -1,
      -1,    -1,    -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,    -1,   486,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,
     540,   541,   502,    -1,    -1,    -1,    -1,    -1,    -1,   594,
      -1,    -1,    -1,   553,   486,    -1,    -1,   489,    -1,    -1,
      -1,    -1,    -1,   613,    -1,    -1,    -1,    32,    -1,    -1,
     502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     540,   541,   627,    -1,    49,    -1,    -1,    -1,   633,    -1,
      -1,    -1,    -1,   553,   594,    -1,    -1,   642,   643,    -1,
     645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,
      -1,    -1,   657,   658,    -1,    -1,   252,    -1,    -1,    -1,
     665,   553,    -1,   668,    -1,    -1,    -1,   627,    -1,   679,
      -1,   676,    -1,   633,   594,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   642,   643,    -1,   645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,    -1,   657,   658,    -1,
      -1,   126,   594,    -1,    -1,   665,    -1,   627,   668,    -1,
      -1,    -1,    -1,   633,    -1,    -1,   676,   142,   143,    -1,
      -1,    -1,   642,   643,    -1,   645,   486,    -1,   153,   489,
      -1,    -1,    -1,    -1,    -1,   627,    -1,   657,   658,    -1,
      -1,   633,   502,    -1,    -1,   665,    -1,    -1,   668,   455,
     642,   643,    -1,   645,    -1,    -1,   676,    -1,    -1,    62,
      63,    64,    65,    66,    67,   657,   658,    -1,    -1,    -1,
      -1,    -1,    -1,   665,    -1,    -1,   668,    -1,    -1,    -1,
     486,   541,   455,   489,   676,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   553,    -1,    -1,   502,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,    -1,    -1,   489,    -1,    -1,    -1,
      -1,    -1,    -1,   529,    -1,    -1,    -1,    -1,    -1,   502,
      -1,    -1,    -1,    -1,   594,   541,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,   541,    -1,
      -1,    -1,    -1,   633,    -1,    -1,    -1,    -1,    -1,    -1,
     553,    -1,   642,   643,    -1,   645,    -1,    -1,   594,    -1,
     486,    -1,    -1,   489,    -1,    -1,   321,   657,   658,    -1,
      -1,    -1,    -1,    -1,    -1,   665,   502,    -1,   668,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
      -1,   594,    -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,
      -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,    -1,   645,
      -1,    -1,    -1,    -1,    -1,   541,    -1,    -1,    -1,    -1,
      -1,   657,   658,   378,   379,   380,   381,   553,    -1,   665,
     633,   264,   668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,   396,   645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   657,   658,    -1,    -1,    -1,    -1,
      -1,    -1,   665,   418,    -1,   668,    -1,    -1,   594,    -1,
      -1,    -1,    -1,   676,    -1,   430,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,   320,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   627,   457,    -1,    -1,    -1,    -1,   633,    -1,    -1,
      -1,   344,   467,    -1,    -1,    -1,   642,   643,    -1,   645,
     353,    -1,    -1,    -1,    -1,    -1,    -1,   482,    -1,    -1,
      -1,   657,   658,    -1,    -1,    -1,    -1,    -1,    -1,   665,
      -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,
      -1,   394,    -1,    -1,    -1,    -1,   399,   522,    -1,    -1,
      -1,    -1,    -1,    -1,   407,   530,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,    -1,
      -1,   566,    -1,    -1,   569,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   590,   469,    -1,    -1,   594,
      -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,   613,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   631,    -1,    -1,    -1,
      -1,   514,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   547,   548,    -1,    -1,   673,    -1,
     553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,   588,   589,    -1,    -1,    -1,
     593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   650,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   659,    -1,   661
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,    48,   113,   138,   417,   465,   496,   525,
     735,   798,   806,   833,   834,  1048,  1049,  1105,  1106,  1107,
    1109,  1110,  1111,  1116,  1118,  1131,  1132,  1133,  1134,  1135,
    1578,    28,    29,   807,   808,   809,   810,   811,    27,  1012,
    1593,   837,  1012,    25,  1012,  1483,  1136,   835,  1483,  1012,
     834,     0,  1108,  1111,  1134,    31,   809,   811,   839,   840,
     843,   668,    25,   252,   832,   833,   999,  1012,  1017,  1116,
    1131,  1137,  1168,  1169,  1170,  1171,  1172,  1176,   415,   838,
     839,   841,   843,   844,   799,   116,   123,   169,   170,   428,
     523,   614,   694,   702,   806,   967,  1047,  1112,  1113,  1115,
    1119,  1120,  1126,  1138,  1292,  1302,  1578,  1012,   673,  1012,
    1171,   303,   516,   517,  1177,    20,  1012,  1175,   676,   839,
       5,   836,   415,     5,    32,    49,   126,   142,   143,   153,
     321,   359,   378,   379,   380,   381,   396,   418,   430,   441,
     457,   467,   482,   522,   530,   544,   559,   566,   569,   590,
     594,   613,   631,   673,   847,   857,   863,   865,   866,   871,
     736,   802,  1012,  1303,  1012,  1293,  1127,  1012,  1012,  1115,
    1121,   866,    25,  1168,  1174,    18,    19,    26,    47,   122,
     134,   161,   254,   349,   384,   418,   430,   466,   481,   489,
     502,   545,   570,   594,   638,   647,   731,   732,   747,   749,
     934,   941,   952,   954,  1012,  1168,  1178,  1179,   517,    14,
     887,   841,   579,  1279,    19,    24,    25,    26,   676,   842,
    1018,   843,   726,   727,   728,   846,   868,   859,   869,   379,
     845,   489,   489,   489,   860,   873,   875,   876,   874,   883,
     884,   489,   489,   858,   517,   867,   489,   839,   856,   839,
     121,   864,  1012,   800,  1012,   489,  1012,   832,   968,  1139,
    1012,  1279,   484,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   747,   489,   829,     9,    18,    19,
      25,    26,   127,   354,   448,   453,   455,   471,   486,   489,
     492,   501,   541,   553,   564,   594,   645,   657,   658,   665,
     910,   918,   919,   920,   921,   922,   952,   953,   955,  1018,
    1168,  1282,  1476,   489,   489,   489,   489,   489,   489,    18,
      19,    20,    21,    22,   748,    26,    36,   489,   578,     5,
     485,  1178,    25,    26,  1012,  1018,    26,    26,   849,   489,
     870,   856,   870,   489,   516,   851,    26,    26,    26,   856,
     682,   427,   512,   528,   570,   609,   638,   647,   877,   682,
     427,   512,   528,   570,   609,   638,   647,   885,    26,    26,
     838,    26,   854,   855,   870,    26,   646,   668,   676,   832,
     489,    26,   489,  1128,   832,   832,   489,  1168,   723,   960,
    1003,  1012,  1003,  1003,   960,   960,   910,    24,    25,    26,
      19,    24,    25,    26,   676,   956,   957,   958,   959,    25,
     961,  1003,  1004,   910,   452,   910,   910,   910,   910,   583,
    1299,   489,   489,   910,   427,   512,   528,   570,   609,   638,
     647,  1479,  1480,   489,   910,   910,   489,   489,   923,   489,
     489,   489,   489,     6,     7,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    56,
     154,   155,   156,   157,   158,   159,   172,   173,   174,   310,
     313,   432,   447,   451,   487,   515,   532,   613,   679,   828,
     911,   924,   926,   927,   928,   929,   930,   931,   932,   479,
     944,   942,   948,   946,  1168,  1168,   747,  1012,   935,  1012,
    1179,   517,   485,   680,    26,   676,    26,   452,   452,     5,
     452,   319,   878,   879,   489,   880,   885,   886,   880,   489,
     881,     5,   452,     5,   452,   343,   485,     5,     5,   452,
     839,   839,   839,   872,   801,  1304,   452,  1294,  1594,  1595,
    1596,  1597,  1598,   969,  1140,  1122,   452,   489,     5,   452,
     517,   676,   452,   452,   452,   452,   452,   452,   452,    19,
      26,   452,   646,   957,    19,    26,   646,    26,   452,     5,
     452,   452,     5,   830,   910,   529,  1499,   910,   489,   682,
      20,   452,  1499,    20,  1282,   910,   910,   910,   910,   910,
     910,   910,   910,   910,   910,   910,   910,   910,   910,   910,
     910,   910,   910,   910,   910,   910,   910,   910,   489,   910,
     910,   489,  1168,   910,   910,   910,   910,   452,     5,   489,
     540,   779,   780,   781,   910,   489,  1178,   517,   863,   452,
      20,   452,   484,   852,    26,   489,   877,    26,   882,    26,
      26,    26,   848,   855,    26,   646,   803,   804,  1116,  1120,
    1578,  1012,  1184,  1185,  1187,  1184,   422,  1595,  1279,    39,
      42,    50,    51,    52,    58,    61,    68,    69,   114,   115,
     119,   129,   130,   132,   146,   163,   166,   167,   180,   182,
     183,   184,   192,   193,   195,   196,   197,   203,   206,   208,
     209,   210,   216,   218,   219,   221,   223,   224,   227,   230,
     231,   232,   233,   234,   235,   239,   240,   241,   243,   247,
     249,   250,   255,   258,   261,   263,   265,   267,   271,   272,
     274,   275,   276,   279,   281,   282,   284,   292,   293,   304,
     307,   308,   311,   312,   315,   316,   323,   324,   325,   327,
     337,   338,   339,   341,   345,   346,   350,   358,   366,   367,
     368,   374,   375,   382,   385,   389,   390,   400,   417,   425,
     431,   442,   454,   460,   462,   463,   470,   509,   520,   527,
     550,   551,   555,   567,   573,   574,   575,   576,   580,   584,
     591,   592,   602,   604,   615,   617,   620,   626,   652,   655,
     660,   663,   664,   678,   685,   708,   709,   710,   711,   712,
     713,   714,   717,   719,   721,   740,   741,   742,   743,   760,
     784,   805,   806,   812,   831,   889,   890,   891,   892,   903,
     904,   905,   906,   907,   908,   909,   962,   993,   997,  1019,
    1021,  1024,  1025,  1026,  1027,  1040,  1050,  1074,  1075,  1077,
    1081,  1096,  1097,  1101,  1102,  1103,  1104,  1114,  1129,  1145,
    1156,  1157,  1158,  1162,  1165,  1199,  1202,  1204,  1210,  1211,
    1214,  1217,  1222,  1224,  1226,  1229,  1236,  1241,  1242,  1244,
    1247,  1248,  1249,  1261,  1262,  1265,  1271,  1274,  1275,  1300,
    1315,  1317,  1318,  1319,  1320,  1332,  1338,  1339,  1359,  1362,
    1391,  1393,  1484,  1485,  1516,  1517,  1524,  1539,  1563,  1578,
    1579,  1584,  1585,  1587,  1591,  1592,  1599,   806,  1117,   681,
     704,  1141,  1142,  1184,  1012,  1003,   747,    20,   723,  1012,
     877,   950,   950,    26,   452,   646,   950,    24,    26,    26,
     646,    24,    26,   874,   951,  1004,   875,   452,   420,   533,
     642,  1507,   452,   452,    26,  1480,   452,   452,   452,   452,
     452,   452,   452,   500,   500,   500,   933,  1499,   500,   933,
    1499,   945,   943,   949,   947,    26,   939,   936,     5,   937,
     485,  1178,   362,   452,   839,   861,   862,   452,   452,   452,
     452,   680,     5,   452,   839,   734,   804,   676,   452,     5,
     452,  1012,  1245,  1245,  1168,  1168,  1168,  1012,    25,  1168,
    1223,  1012,    25,  1012,  1469,   411,  1013,  1014,  1593,  1013,
      25,  1012,  1468,  1012,  1245,  1007,  1013,  1007,  1012,  1589,
    1469,  1012,    26,   744,  1168,  1323,  1007,  1245,   933,    26,
    1018,  1287,  1288,  1287,   910,   917,  1361,  1468,  1468,   912,
     933,  1013,  1525,  1525,   893,  1245,  1007,  1321,  1168,  1009,
    1013,   917,  1525,  1168,  1245,  1168,  1360,  1525,    25,   642,
    1159,  1160,  1168,  1007,  1007,  1159,  1008,  1013,  1012,  1160,
    1007,  1525,  1007,  1009,  1469,  1168,  1197,  1198,  1005,  1013,
    1009,   436,   618,  1003,  1076,  1012,   813,  1468,  1010,  1013,
      25,   252,  1012,  1392,  1567,  1569,  1570,  1571,  1572,  1574,
     933,  1197,   682,   933,  1013,  1225,   963,    71,    72,    73,
      74,   194,   202,   211,   214,   257,   264,   320,   344,   351,
     353,   363,   391,   399,   436,   460,   497,   508,   605,   606,
     607,   618,   663,   721,   737,  1090,  1218,  1219,  1168,  1189,
    1190,   916,   917,  1235,   960,   960,  1006,  1013,   933,  1223,
    1301,  1168,  1278,    25,   489,  1168,  1273,  1519,  1272,   917,
    1580,   168,   217,   254,   349,   426,   466,   531,   761,   941,
    1012,  1168,  1310,   786,   917,  1005,   646,  1012,  1020,  1146,
     917,  1006,    26,  1168,  1098,  1005,   917,  1540,   917,  1287,
    1012,  1022,  1023,  1009,  1022,   960,  1009,  1022,   960,  1028,
    1022,    25,    26,   445,   544,  1018,  1079,  1168,  1186,  1188,
     128,   334,   406,   450,   625,   705,   706,   707,   716,   751,
    1030,  1032,  1034,  1036,  1038,  1163,  1164,  1167,   397,   408,
     458,   472,   560,  1394,   696,   697,   971,   972,   973,  1012,
    1143,   703,  1142,   452,   452,   485,   489,   682,    19,    26,
     452,   950,    26,   452,   452,   646,    26,   646,   682,    18,
      19,    20,    25,    26,    43,    44,   127,   455,   486,   489,
     502,   541,   553,   594,   627,   633,   642,   643,   645,   657,
     658,   665,   668,  1012,  1018,  1475,  1477,  1506,  1508,  1509,
    1511,  1512,  1513,  1535,  1536,  1537,  1538,  1568,  1569,  1573,
    1299,   452,  1299,  1299,  1299,  1299,  1299,  1299,    25,    25,
      25,   910,   925,   452,    25,   925,   452,   452,   452,   452,
     452,   452,   779,   452,   781,   779,   485,   517,     5,   452,
     863,   855,  1012,  1305,  1187,  1295,   682,   117,   118,   147,
     148,   149,   513,   598,   641,  1340,  1341,  1342,  1345,  1348,
    1351,  1352,  1353,  1356,   676,   646,   668,   164,   165,   489,
     676,   646,   668,     8,   681,   485,  1468,   536,  1246,  1186,
     172,   173,   174,   652,   540,   913,   914,   917,  1168,  1193,
      40,    41,  1468,   750,   751,   896,   326,    38,   150,   151,
     152,   682,   518,     5,   675,   682,   674,   674,  1200,   652,
     479,     5,   613,  1051,   518,   715,  1582,   715,   445,   815,
    1168,   603,   674,  1205,  1206,  1207,   676,    25,  1570,   517,
    1575,   388,  1390,   668,   676,   915,   917,   613,  1567,   915,
       8,   610,  1006,    26,   558,   611,   725,   998,  1168,   998,
     998,   998,    25,   239,   364,   370,   371,   372,   392,   497,
     500,   508,   542,   577,   596,   597,   607,   612,   651,   683,
    1094,  1095,   998,   998,   653,  1091,   751,  1091,  1091,   999,
     999,  1091,  1091,    45,    46,  1220,   751,    45,    46,  1221,
       5,   479,     5,   395,   446,     5,   750,   144,   145,   596,
     683,  1082,   718,  1583,   916,   669,   670,   671,   672,  1277,
    1519,  1279,   917,  1267,  1268,  1269,  1280,  1281,   917,   489,
     489,   489,   489,    25,   782,  1012,   489,  1519,   406,   489,
     578,    36,   646,   635,   787,   794,   785,  1012,    25,  1161,
    1168,  1263,     8,  1266,    14,  1012,  1173,  1180,  1181,  1183,
    1191,  1192,  1237,    45,    46,   225,   406,   601,   634,  1316,
      33,   252,   610,  1541,  1542,  1543,  1545,   632,     5,   715,
     715,   915,  1186,  1193,  1078,   479,     5,   213,  1056,   489,
    1168,   915,   489,    26,    26,   128,  1166,    25,  1168,  1523,
    1523,  1013,  1374,  1225,  1006,    37,   181,   283,   291,   297,
     298,   309,   336,   352,   357,   369,   376,   524,   529,   535,
     557,   562,  1363,  1364,  1372,  1381,  1382,  1388,  1389,  1395,
    1396,  1406,  1426,  1430,  1495,  1496,  1526,  1527,  1530,  1531,
    1547,   974,   975,   738,   970,   981,   982,   973,  1144,  1594,
    1123,   676,  1012,   877,    26,   452,   646,   950,   452,   646,
     950,   950,    24,    26,   646,    24,    26,   878,  1512,  1512,
     427,   512,   528,   570,   609,   638,   647,  1478,  1481,   529,
    1511,   489,   489,   489,   489,  1506,  1506,  1506,   489,   489,
     489,   489,  1012,   489,     5,   603,  1435,  1440,   673,  1012,
      18,    19,    20,    21,   154,   155,   156,   157,   158,   159,
    1533,  1481,  1481,   479,     5,   452,   452,   940,   938,    26,
     853,   862,   832,   832,  1223,   306,   319,   420,   489,   533,
     549,  1410,  1411,  1416,  1418,   489,  1012,  1357,  1358,    26,
     489,  1012,  1337,  1350,  1418,  1420,   489,  1012,  1347,   489,
    1337,  1343,     5,  1012,    25,  1012,  1012,    25,  1015,  1171,
    1012,    25,  1012,  1012,  1012,  1590,  1468,   652,   489,   489,
     896,  1468,     5,   682,  1223,   489,  1567,    25,  1017,  1243,
    1243,  1519,  1159,   917,   917,   917,  1000,  1001,   489,  1168,
    1198,  1052,  1053,  1054,  1468,   682,  1519,   960,  1583,  1076,
    1168,   814,   681,   917,   412,  1209,   613,  1208,  1571,   747,
    1576,  1577,  1012,    20,  1572,     5,  1564,   673,  1215,   131,
     133,   135,   674,   682,   888,  1186,  1189,   964,    18,    19,
     489,  1092,  1094,  1219,  1168,  1190,   999,   917,   406,   652,
      26,  1168,    26,  1168,   750,   215,  1276,   452,   444,  1314,
    1279,  1269,     5,   674,  1270,  1581,  1012,    25,   960,   960,
     646,  1004,   679,  1168,   767,  1012,  1012,  1012,   917,   401,
     790,   794,   635,   788,   796,    23,   296,  1148,  1152,   539,
     933,   539,  1264,   917,   516,  1177,   676,     5,  1099,   603,
    1238,  1168,   225,   406,  1544,  1546,   251,  1542,  1041,  1023,
     960,   960,  1033,  1034,  1056,  1056,    53,    54,    55,    57,
      59,    60,   330,   333,   335,   355,   365,   386,   409,   413,
     488,  1055,  1057,  1058,  1086,  1168,  1188,   603,   752,    26,
     459,  1039,   383,  1518,  1518,   200,   201,   495,   603,  1012,
    1427,  1428,  1470,  1468,  1468,  1468,  1365,  1468,  1468,  1012,
    1528,   229,   440,   454,   497,   508,   529,   535,   543,   565,
     642,   648,  1397,  1399,  1400,  1401,  1507,  1468,  1373,  1397,
    1399,  1594,  1594,   445,   983,  1168,   698,   699,   976,   977,
     978,   538,   681,   700,   701,   720,   986,   987,  1594,   832,
      20,  1012,   452,    26,   452,   950,    26,   950,    24,    26,
     452,   452,    24,    26,   682,  1507,   452,   455,  1511,  1534,
    1573,   420,   533,   642,  1459,  1511,  1514,  1459,  1459,  1459,
    1459,   676,  1514,  1509,   572,  1436,  1437,  1438,  1468,   583,
    1434,  1441,   393,   571,   582,  1383,  1502,  1012,  1511,  1511,
    1511,  1511,   682,   489,   682,  1568,   910,   452,   452,   485,
    1306,  1296,   673,   489,   489,   489,  1354,  1418,   489,   489,
     120,  1355,  1357,     5,  1349,  1350,   126,   359,   379,   380,
     381,   418,   430,   441,   457,   467,   482,   530,   559,   569,
     590,   594,   622,   631,  1460,  1461,  1462,  1464,  1346,  1347,
    1343,  1344,   720,  1341,   676,   646,   452,   676,   646,   603,
    1588,   489,   745,   746,  1012,  1324,   933,   913,  1012,   673,
    1322,   673,  1212,   682,     5,     5,     5,   636,   917,     5,
     676,   540,   682,   681,   226,   228,   330,   333,   816,   819,
     820,  1086,   817,   818,  1012,   489,  1013,   705,   706,  1213,
       5,   485,   917,  1468,  1565,  1566,  1567,   633,   673,  1216,
    1012,  1012,  1001,  1002,   566,   960,   896,     8,     8,   966,
      26,    26,  1093,  1094,  1168,   379,  1230,   128,   910,  1279,
     280,  1281,  1287,  1594,     5,     5,   452,   452,   783,  1012,
     452,  1519,   779,   489,   489,   489,   795,   791,   421,   789,
     917,   401,   792,   796,   653,  1088,  1153,  1149,   423,  1147,
    1148,   915,   682,  1174,    20,  1012,  1182,  1192,    14,   540,
    1239,  1240,  1511,  1168,  1573,  1189,  1594,  1035,  1036,   607,
    1011,   603,  1069,  1068,  1067,  1066,  1071,  1070,  1003,  1072,
    1003,  1073,  1065,  1064,  1062,  1061,  1087,   386,  1058,  1063,
     960,    62,    63,    64,    65,    66,    67,   160,   394,   407,
     469,   475,   514,   537,   547,   548,   553,   563,   585,   588,
     589,   593,   650,   661,   753,   754,  1084,  1085,     5,    26,
    1519,   309,  1168,   529,  1500,  1501,  1519,  1225,  1494,  1496,
     162,   162,   652,  1223,  1429,  1430,   489,  1407,   212,  1441,
    1468,   236,   331,  1532,   676,   682,   489,  1402,  1402,   603,
     681,     5,  1497,  1548,   403,   412,   436,   439,   455,   558,
     611,   618,  1006,  1375,  1380,   682,   681,   985,  1168,     5,
     603,   979,   980,   695,   978,   984,  1012,   984,   988,   989,
     984,   386,   987,  1124,   452,   646,   950,   452,   646,   452,
     452,   950,   950,   427,   512,   528,   570,   609,   638,   647,
    1482,  1508,     5,  1481,     5,   452,     5,  1511,     5,   452,
    1511,  1511,  1511,  1511,  1012,   452,   489,  1438,     5,   673,
    1012,  1474,     9,   354,   489,   501,  1444,  1445,  1446,  1447,
    1448,  1452,  1456,  1458,  1511,   429,  1432,  1442,  1012,  1503,
     675,  1459,   393,  1482,    26,  1482,   850,   519,  1289,  1309,
     519,  1250,  1283,  1223,   668,  1012,  1413,  1415,  1468,  1472,
    1473,  1417,  1472,  1417,     5,   452,  1355,  1417,  1444,  1012,
     452,  1358,     5,   452,   489,   489,   489,  1481,  1481,   489,
     489,   489,   489,   489,   268,   269,   270,   459,  1419,  1421,
       5,   452,     5,   452,  1012,  1012,    25,  1012,  1012,    25,
    1012,   917,  1012,  1334,  1335,     5,  1336,  1337,   933,  1130,
     676,  1223,  1336,   633,  1519,  1519,   917,   917,  1000,   566,
     917,  1586,     5,  1053,    20,  1472,  1519,   817,   825,   824,
     826,  1012,  1016,   827,  1016,   253,   820,   823,     5,  1056,
     676,   917,     8,  1577,   517,   676,     5,  1519,   633,  1012,
    1186,   933,   610,  1378,     5,   452,  1168,     5,    26,  1168,
     387,    25,  1311,   406,   406,   517,   676,   406,   489,   768,
     772,   765,   763,  1594,  1594,   797,   793,   789,  1089,    25,
    1011,  1154,  1168,  1594,   917,   484,   517,   933,     5,  1042,
    1037,  1038,    26,   750,  1012,  1594,  1594,  1594,  1594,  1594,
    1594,     5,  1059,     5,  1060,  1594,  1594,  1594,  1594,  1092,
    1594,  1011,    25,    14,    14,     5,   452,    26,  1468,  1507,
    1488,   652,   652,  1364,  1493,  1494,  1430,  1408,  1472,   673,
    1006,   489,  1368,  1012,  1529,  1528,  1403,  1472,   521,  1404,
    1405,  1470,  1468,  1401,  1508,   107,   108,   109,   110,   111,
     640,  1551,   917,   917,   610,  1376,  1006,  1404,  1468,     5,
    1168,   984,  1594,  1594,     5,   991,   992,  1594,  1594,   990,
    1117,   950,    26,   950,    24,    26,   950,   950,   489,  1440,
    1481,   682,  1481,  1481,   452,  1511,   452,   452,   452,   452,
    1437,  1439,  1437,  1474,  1447,  1506,  1444,  1511,  1506,     6,
       7,     9,    12,    13,    14,    15,    16,    17,   432,   433,
     487,   613,   679,   729,   730,  1455,  1457,  1433,  1510,  1511,
     506,  1431,  1443,   328,  1333,    26,  1384,  1385,  1386,  1472,
    1500,  1503,   452,   680,   136,   137,   139,   140,   141,   238,
     246,   280,   289,   317,   318,   361,   405,   459,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,  1286,  1290,
     199,   571,  1291,  1307,   222,   237,   238,   246,   280,   289,
     317,   361,   405,  1284,  1285,  1297,  1291,     8,  1473,   517,
    1471,   452,     5,   676,     5,   452,   452,  1418,   452,   452,
    1350,    26,  1465,  1465,    26,   682,   489,   682,    26,  1466,
      26,    26,  1466,  1466,    25,  1475,   220,   319,   356,   420,
     434,   533,   549,  1412,  1422,  1423,  1424,  1425,  1347,  1343,
     676,   676,   595,   644,     5,   452,   746,     5,   452,   915,
     452,    20,     8,   452,  1519,     5,   917,   623,   334,   755,
     756,   917,  1056,  1594,  1594,     5,   821,   517,   676,     5,
     822,  1594,   818,   603,    20,  1012,     5,  1012,  1203,  1576,
      20,  1472,  1566,     8,  1519,   450,   715,   915,  1379,   965,
    1094,   724,  1228,   910,     5,   779,  1168,   762,   744,  1012,
    1168,   770,   452,   779,   779,   779,  1594,  1594,  1092,  1151,
      25,  1155,  1168,   628,   996,  1178,   540,   916,  1100,  1240,
     125,   599,  1043,  1029,  1030,   676,  1003,  1594,  1003,  1594,
     750,    26,  1168,    26,  1168,   754,   452,   489,  1520,  1508,
    1494,  1494,  1486,     5,   452,   529,  1505,  1369,  1472,   536,
    1366,  1505,   682,     5,   452,     5,   603,  1498,    18,    19,
     127,   486,   489,   502,   540,   541,   553,   594,   633,   645,
     657,   658,   665,   668,  1012,  1475,  1506,  1535,  1537,  1556,
    1557,  1558,  1559,  1560,  1561,  1573,  1556,  1556,  1556,  1472,
    1553,  1555,  1552,  1553,  1554,  1549,  1377,   682,  1168,  1012,
    1594,  1594,  1594,  1594,   452,   646,   452,   452,    26,   452,
     682,  1482,   682,   682,     5,   452,   452,  1445,  1446,  1450,
    1512,  1450,   489,  1506,  1450,   489,  1506,  1450,    10,   310,
     447,   449,  1511,     5,  1444,     5,   595,   644,  1387,  1333,
     682,   863,  1287,  1287,  1287,    25,  1287,  1287,  1287,  1287,
    1287,  1287,    25,    25,  1287,  1290,  1168,  1194,  1195,   675,
     505,  1251,    25,    25,    26,    26,    26,    26,    26,    25,
    1168,  1285,  1251,  1223,    26,  1412,  1472,    20,  1012,  1472,
    1355,   452,   452,     5,   452,  1482,    26,  1482,     5,  1463,
       5,   452,   452,   452,  1463,  1414,  1468,   489,  1424,  1355,
    1012,  1012,  1335,   679,   733,  1329,  1330,  1331,  1337,    70,
     148,   149,   305,   679,  1325,  1326,  1327,   526,   895,  1223,
    1325,     5,   435,  1519,     5,   489,   452,   607,  1083,  1016,
    1594,   747,    20,  1012,  1016,  1594,   960,   917,   485,  1519,
       8,   960,  1189,  1594,    26,  1011,    25,  1312,  1186,   485,
     779,   769,   773,   452,   452,  1594,  1011,   917,   994,   485,
    1045,  1044,   499,  1031,  1032,    20,  1012,  1521,  1522,   610,
    1504,  1489,  1487,  1472,  1507,   204,  1409,     5,   452,  1367,
    1529,  1472,  1405,  1404,  1504,  1559,  1559,  1558,   489,   489,
     489,   489,   489,   489,   489,  1012,   489,     5,   452,    18,
      19,    20,    21,  1533,   452,     5,   452,     5,    14,   212,
     583,  1550,  1189,  1404,   273,  1125,   950,    24,    26,   950,
     950,   452,  1482,  1482,  1482,  1437,   500,  1449,  1449,  1453,
    1454,  1475,  1573,  1449,  1453,  1449,  1450,  1511,  1510,  1385,
    1482,   595,   644,  1196,     5,  1194,   124,   198,   260,   262,
     278,   286,   290,   314,  1252,  1253,  1308,  1298,     5,   485,
    1471,    26,   452,    26,  1467,   452,    26,   452,   489,  1444,
    1328,  1593,    26,  1331,    26,    26,  1328,  1333,  1327,  1003,
     750,   435,  1519,   917,   757,   625,  1201,    26,   750,   485,
    1083,   452,  1519,   301,   750,   452,   452,   489,   771,   406,
     777,   452,   766,   764,  1150,  1594,   517,   917,  1594,  1011,
       5,   452,  1189,  1440,  1508,  1472,   489,  1440,   452,  1534,
    1459,  1558,  1562,  1459,  1459,  1459,  1459,   517,   676,  1562,
    1557,  1558,  1558,  1558,  1558,  1553,    14,  1554,  1557,  1006,
    1444,   205,   673,  1398,   452,   452,  1451,  1475,  1515,     5,
     452,   452,  1449,     7,  1195,  1254,  1255,  1168,  1257,  1168,
    1256,  1258,  1253,   300,   300,    26,   452,   682,   452,  1415,
     452,   894,  1519,   453,   264,   320,   344,   353,   391,   399,
     490,   659,   754,   758,   759,   489,   676,   750,  1227,  1313,
     774,   452,  1186,   777,   777,   777,  1594,   995,  1178,   632,
    1080,  1522,  1502,  1440,   540,  1370,  1371,  1511,  1502,   452,
    1558,     5,   452,  1558,  1558,  1558,  1558,    26,  1012,   452,
     489,  1012,   950,   950,  1454,  1511,  1594,  1594,  1259,  1594,
    1260,  1594,  1594,   485,  1482,   452,   299,   409,   413,   897,
     898,   899,  1086,   998,   998,   998,   998,   998,   998,    25,
       5,   452,   917,    20,  1012,  1086,  1231,  1232,  1233,   777,
     779,   777,   302,   485,  1046,   750,     5,   452,   347,   348,
    1490,   452,  1558,   452,   452,   452,   452,     5,   485,   517,
    1556,  1594,  1594,   901,   900,   299,   899,   902,   759,     5,
    1234,   342,  1233,   775,  1594,  1371,    25,  1012,  1491,  1492,
      26,    26,   452,  1594,  1594,  1594,   917,  1594,   452,  1043,
     676,   676,     5,   485,     5,   485,   452,   776,  1012,  1012,
    1492,    26,   225,   406,   778,   676,   485,  1186,  1012
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
    {
//start_state("attribute",1);
}
    break;

  case 27:
#line 1119 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
//start_state("attribute",0);
}
    break;

  case 29:
#line 1126 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1127 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1134 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1136 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1137 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1139 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1140 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1141 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1142 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1143 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1144 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1145 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1146 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1147 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1148 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1149 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1156 "fgl.yacc"
    {
A4GL_debug("win_attributes_def");
//start_state("attribute",1);
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
#line 1167 "fgl.yacc"
    {
//start_state("attribute",0);
strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1173 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1174 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1178 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1184 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1186 "fgl.yacc"
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
#line 1197 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1199 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1201 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1203 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1207 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1209 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1270 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1274 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1278 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1285 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1288 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1292 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1296 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1305 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1311 "fgl.yacc"
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
#line 1320 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1325 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1331 "fgl.yacc"
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
#line 1340 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 77:
#line 1347 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 78:
#line 1352 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 79:
#line 1356 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 80:
#line 1364 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 81:
#line 1368 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1372 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1374 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1380 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 85:
#line 1385 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 86:
#line 1388 "fgl.yacc"
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
#line 1404 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 88:
#line 1411 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 89:
#line 1415 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 90:
#line 1419 "fgl.yacc"
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
#line 1441 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 92:
#line 1441 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 93:
#line 1445 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 94:
#line 1446 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 95:
#line 1447 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 96:
#line 1452 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 97:
#line 1455 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 98:
#line 1461 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 99:
#line 1464 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 101:
#line 1473 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");inc_counter();}
    break;

  case 103:
#line 1477 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 104:
#line 1483 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 105:
#line 1486 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 106:
#line 1501 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 107:
#line 1511 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1517 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 109:
#line 1526 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 114:
#line 1539 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 116:
#line 1542 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 117:
#line 1544 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 119:
#line 1550 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 120:
#line 1552 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 121:
#line 1557 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 122:
#line 1562 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 123:
#line 1568 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 124:
#line 1572 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 125:
#line 1581 "fgl.yacc"
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
#line 1605 "fgl.yacc"
    { 
		char buff[256];
		printf("Calling read_class (%s,1)\n",yyvsp[0].str);  
		sprintf(buff,"\"%s\"",yyvsp[0].str);
		variable_action (-1, "_parent_name", buff, "c", "add_constant");
		/*
		if (strcmp($<str>$,"default_object")!=0) {
		}
		*/
	}
    break;

  case 127:
#line 1615 "fgl.yacc"
    { 
		pop_record();in_record--;
		read_class(yyvsp[-2].str,1); 
		print_variables(); 
		class_set_parent();
		}
    break;

  case 128:
#line 1621 "fgl.yacc"
    {
		class_cnt++; 
		CLASS_print_reflector();
		dump_class();
		}
    break;

  case 129:
#line 1631 "fgl.yacc"
    {
	static char buff[256];
		strcpy(buff,"default_object");
		CLASS_set_parent_name(buff);
		strcpy(yyval.str,buff);
	}
    break;

  case 130:
#line 1636 "fgl.yacc"
    {
		CLASS_set_parent_name(yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 136:
#line 1662 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 137:
#line 1665 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 138:
#line 1668 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 139:
#line 1671 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 140:
#line 1674 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 141:
#line 1677 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 147:
#line 1699 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 150:
#line 1708 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 151:
#line 1727 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 152:
#line 1732 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 153:
#line 1735 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 154:
#line 1744 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 155:
#line 1750 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 160:
#line 1765 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 161:
#line 1769 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 162:
#line 1774 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 165:
#line 1784 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 166:
#line 1784 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 167:
#line 1785 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 168:
#line 1785 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 169:
#line 1786 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 170:
#line 1786 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 171:
#line 1787 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 172:
#line 1787 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 173:
#line 1788 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 174:
#line 1788 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 175:
#line 1796 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 176:
#line 1800 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 177:
#line 1806 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 178:
#line 1810 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 179:
#line 1825 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 180:
#line 1828 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 181:
#line 1831 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 182:
#line 1834 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 183:
#line 1837 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 184:
#line 1840 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 185:
#line 1849 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 186:
#line 1857 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(0x%x);",22); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 187:
#line 1862 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(0x%x);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 188:
#line 1875 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 189:
#line 1879 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 190:
#line 1892 "fgl.yacc"
    {
		   strcpy(yyval.str,"");
		   
		}
    break;

  case 191:
#line 1895 "fgl.yacc"
    {
		   strcpy(yyval.str,"");
		   lastlineno=yylineno;
		   
		}
    break;

  case 194:
#line 1910 "fgl.yacc"
    {
		   dtypelist[0]=0;
		   A4GL_lex_printcomment("/* define */\n");
		}
    break;

  case 195:
#line 1913 "fgl.yacc"
    {
		   A4GL_lex_printcomment("/*end def */\n");
		}
    break;

  case 197:
#line 1916 "fgl.yacc"
    {push_scope(); set_current_variable_scope('T');}
    break;

  case 198:
#line 1916 "fgl.yacc"
    {pop_scope();}
    break;

  case 201:
#line 1927 "fgl.yacc"
    {
		   in_define=1;
		   
		}
    break;

  case 202:
#line 1930 "fgl.yacc"
    {
		   in_define=0;
		   strcpy(yyval.str,yyvsp[0].str);
                   set_yytext(yyval.str);
                   if (A4GL_bad_identifiers(yyval.str)) {
                            a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                   }
		   
		}
    break;

  case 203:
#line 1943 "fgl.yacc"
    {
		    add_constant('c',yyvsp[0].str,yyvsp[-2].str);
		    addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
		    
		}
    break;

  case 204:
#line 1948 "fgl.yacc"
    {
		    add_constant('C',yyvsp[0].str,yyvsp[-2].str);
		    addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
		    
		}
    break;

  case 205:
#line 1953 "fgl.yacc"
    {
		    add_constant('f',yyvsp[0].str,yyvsp[-2].str);
		   addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
		    
		}
    break;

  case 206:
#line 1958 "fgl.yacc"
    {
		    add_constant('i',yyvsp[0].str,yyvsp[-2].str);
		   addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
		    
		}
    break;

  case 208:
#line 1964 "fgl.yacc"
    {
		   char buff[20];
		   strncpy(buff,yyvsp[0].str,3);
		   if (buff[0]=='"') {
		    add_constant('c',yyvsp[0].str,yyvsp[-2].str);
		      }
		     else {
		    if (strchr(yyvsp[0].str,'.'))   add_constant('f',yyvsp[0].str,yyvsp[-2].str);
		       else  add_constant('i',yyvsp[0].str,yyvsp[-2].str);
		      }
		   addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
		   
		}
    break;

  case 212:
#line 1984 "fgl.yacc"
    {
		     sprintf(yyval.str,"-%p",yyvsp[0].str);
		   
		}
    break;

  case 213:
#line 1992 "fgl.yacc"
    {
			push_name(yyvsp[0].str,0);
		   addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
			strcpy(yyval.str,yyvsp[0].str);
		   
		}
    break;

  case 218:
#line 2013 "fgl.yacc"
    {
		   strcpy(yyval.str,"-1");
		   
		}
    break;

  case 219:
#line 2016 "fgl.yacc"
    {
		   strcpy(yyval.str,"-1");
		   
		}
    break;

  case 220:
#line 2020 "fgl.yacc"
    {
		   strcpy(yyval.str,"-2");
		   
		}
    break;

  case 221:
#line 2024 "fgl.yacc"
    {
		   strcpy(yyval.str,"-3");
		   
		}
    break;

  case 222:
#line 2032 "fgl.yacc"
    {
		    A4GL_debug("defines array %s",yyvsp[-1].str);
		    push_type(0,0,yyvsp[-1].str);
		   
		}
    break;

  case 224:
#line 2037 "fgl.yacc"
    {
		    A4GL_debug("defines array %s",yyvsp[0].str);
		    push_type(0,0,yyvsp[0].str);
		   
		}
    break;

  case 226:
#line 2042 "fgl.yacc"
    {
		    push_associate(yyvsp[-5].str,yyvsp[-1].str);
		    push_type(0,0,yyvsp[-1].str);
		   
		}
    break;

  case 227:
#line 2046 "fgl.yacc"
    {
		       /* void pop_associate (char *a);
		    */ pop_associate(0);
		   
		}
    break;

  case 233:
#line 2072 "fgl.yacc"
    {
		   sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
		    A4GL_debug("Triplet");
		   
		}
    break;

  case 234:
#line 2077 "fgl.yacc"
    {
		   sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str);
		    A4GL_debug("double");
		   
		}
    break;

  case 235:
#line 2082 "fgl.yacc"
    {
		   A4GL_debug("Single");
		   
		}
    break;

  case 238:
#line 2096 "fgl.yacc"
    {
		     sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);
		   
		}
    break;

  case 239:
#line 2100 "fgl.yacc"
    {
		     sprintf(yyval.str,"%s@%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
		   
		}
    break;

  case 240:
#line 2108 "fgl.yacc"
    {
		   push_record();
		   in_record++;
		   
		}
    break;

  case 241:
#line 2112 "fgl.yacc"
    {
		   pop_record();
		   in_record--;
		   
		}
    break;

  case 242:
#line 2117 "fgl.yacc"
    {
		   in_record++;
		   push_record();
		   A4GL_debug("Like\n");
		   
		}
    break;

  case 243:
#line 2122 "fgl.yacc"
    {
		   A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
		                     push_rectab(yyvsp[-2].str);
		                     pop_record();
		   in_record--;
		   
		}
    break;

  case 244:
#line 2129 "fgl.yacc"
    {
		     push_record();
		   A4GL_debug("Like\n");
		   
		}
    break;

  case 245:
#line 2133 "fgl.yacc"
    {
		       A4GL_debug("Table:%s\n",yyvsp[-4].str);
		       add_link_to(yyvsp[-4].str,yyvsp[-1].str);
		              A4GL_debug("Push record...\n");
		                     push_rectab(yyvsp[-4].str);
		                     pop_record();
		   
		}
    break;

  case 247:
#line 2146 "fgl.yacc"
    {
		    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		   
		}
    break;

  case 255:
#line 2175 "fgl.yacc"
    {
		   push_type("char","1",0);
		   
		}
    break;

  case 256:
#line 2179 "fgl.yacc"
    {
		   push_type("char","1",0);
		   
		}
    break;

  case 257:
#line 2183 "fgl.yacc"
    {
		    if (atoi(yyvsp[-1].str)==4) {
		    addmap("size=4","----",curr_func,yylineno,infilename);
		       }
		    push_type("char",yyvsp[-1].str,0);
		    
		}
    break;

  case 258:
#line 2190 "fgl.yacc"
    {
		    if (atoi(yyvsp[-1].str)==4) {
		    addmap("size=4","----",curr_func,yylineno,infilename);
		       }
		    push_type("char",yyvsp[-1].str,0);
		    
		}
    break;

  case 259:
#line 2197 "fgl.yacc"
    {
		   push_type("varchar",yyvsp[-1].str,0);
		   
		}
    break;

  case 260:
#line 2201 "fgl.yacc"
    {
		   push_type("varchar",yyvsp[-3].str,0);
		   
		}
    break;

  case 261:
#line 2205 "fgl.yacc"
    {
		   push_type("char",yyvsp[-1].str,0);
		   
		}
    break;

  case 262:
#line 2209 "fgl.yacc"
    {
		   push_type("char",yyvsp[-3].str,0);
		   
		}
    break;

  case 263:
#line 2213 "fgl.yacc"
    {
		   push_type("long",0,0);
		}
    break;

  case 264:
#line 2216 "fgl.yacc"
    {
		   push_type("long",0,0);
		}
    break;

  case 265:
#line 2219 "fgl.yacc"
    {
		    A4GL_debug("Using specified type...");
			if (find_dim(yyvsp[0].str)) {
		    		push_dim(yyvsp[0].str);
			}  else {
				a4gl_yyerror("Unknown datatype");
			}
		}
    break;

  case 266:
#line 2228 "fgl.yacc"
    {
		    	A4GL_debug("Using specified type...");
			if (find_dim(yyvsp[0].str)) {
		    		push_dim(yyvsp[0].str);
			}  else {
				a4gl_yyerror("Unknown datatype");
			}
		}
    break;

  case 267:
#line 2237 "fgl.yacc"
    {
		   push_type("int",0,0);
		   
		}
    break;

  case 268:
#line 2241 "fgl.yacc"
    {
		   push_type("form",0,0);
		   
		}
    break;

  case 269:
#line 2245 "fgl.yacc"
    {
		   push_type("form",0,0);
		   
		}
    break;

  case 270:
#line 2249 "fgl.yacc"
    {
		    char buff[256];
		       sprintf(buff,"%d",16*256+2);
		       push_type("fgldecimal",buff,0);
		       
		}
    break;

  case 271:
#line 2255 "fgl.yacc"
    {
		       char buff[256];
		       sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
		       push_type("fgldecimal",buff,0);
		   
		}
    break;

  case 272:
#line 2261 "fgl.yacc"
    {
		   char buff[256];
		   sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
		   push_type("fgldecimal",buff,0);
		   
		}
    break;

  case 273:
#line 2267 "fgl.yacc"
    {
		      char buff[256];
		      sprintf(buff,"%d",16*256+2);
		      push_type("fglmoney",buff,0);
		   
		}
    break;

  case 274:
#line 2273 "fgl.yacc"
    {
		     char buff[256];
		   sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
		      push_type("fglmoney",buff,0);
		   
		}
    break;

  case 275:
#line 2279 "fgl.yacc"
    {
		   char buff[256];
		   sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
		   push_type("fglmoney",buff,0);
		   
		}
    break;

  case 276:
#line 2285 "fgl.yacc"
    {
		   push_type("double",0,0);
		   
		}
    break;

  case 278:
#line 2289 "fgl.yacc"
    {
		   push_type("double",0,0);
		   
		}
    break;

  case 280:
#line 2293 "fgl.yacc"
    {
		   push_type("float",0,0);
		   
		}
    break;

  case 282:
#line 2297 "fgl.yacc"
    {
		   push_type("fgldate",0,0);
		   
		}
    break;

  case 283:
#line 2301 "fgl.yacc"
    {
		   push_type("fglbyte",0,0);
		   
		}
    break;

  case 284:
#line 2305 "fgl.yacc"
    {
		   push_type("fglbyte",0,0);
		   
		}
    break;

  case 285:
#line 2309 "fgl.yacc"
    {
		   push_type("fgltext",0,0);
		   
		}
    break;

  case 286:
#line 2313 "fgl.yacc"
    {
		   push_type("fgltext",0,0);
		   
		}
    break;

  case 287:
#line 2317 "fgl.yacc"
    {
		   push_type("struct_dtime",yyvsp[0].str,0);
		   
		}
    break;

  case 288:
#line 2321 "fgl.yacc"
    {
		   push_type("struct_ival",yyvsp[0].str,0);
		   
		}
    break;

  case 289:
#line 2325 "fgl.yacc"
    {
		   push_like(yyvsp[0].str);
		   A4GL_lex_printcomment("/*added(XXXXX)\n */");
		   
		}
    break;

  case 292:
#line 2364 "fgl.yacc"
    {
		   sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		    A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");
		   
		}
    break;

  case 293:
#line 2373 "fgl.yacc"
    {
		   A4GL_debug("--->%s\n",yyvsp[0].str);
		   strcpy(yyval.str,yyvsp[0].str);
		   
		}
    break;

  case 294:
#line 2382 "fgl.yacc"
    {
		   strcpy(yyval.str,"0");
		   
		}
    break;

  case 295:
#line 2385 "fgl.yacc"
    {
		   A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
		   sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
		    
		}
    break;

  case 296:
#line 2394 "fgl.yacc"
    {
		    sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
		    
		}
    break;

  case 297:
#line 2402 "fgl.yacc"
    {
		   //start_state("dtime_val",1);
		   
		}
    break;

  case 298:
#line 2405 "fgl.yacc"
    {
		   //start_state("dtime_val",0);
		    strcpy(yyval.str,yyvsp[0].str);
		   
		}
    break;

  case 299:
#line 2414 "fgl.yacc"
    {
		   strcpy(yyval.str,"1");
		   
		}
    break;

  case 300:
#line 2418 "fgl.yacc"
    {
		   strcpy(yyval.str,"2");
		   
		}
    break;

  case 301:
#line 2422 "fgl.yacc"
    {
		   strcpy(yyval.str,"3");
		   
		}
    break;

  case 302:
#line 2426 "fgl.yacc"
    {
		   strcpy(yyval.str,"4");
		   
		}
    break;

  case 303:
#line 2430 "fgl.yacc"
    {
		   strcpy(yyval.str,"5");
		   
		}
    break;

  case 304:
#line 2434 "fgl.yacc"
    {
		   strcpy(yyval.str,"6");
		   
		}
    break;

  case 305:
#line 2438 "fgl.yacc"
    {
		   A4GL_debug("opt_frac returns %s",yyvsp[0].str);
		   sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6);
		    
		}
    break;

  case 306:
#line 2447 "fgl.yacc"
    {
		   //start_state("dtime_val",1);
		   
		}
    break;

  case 307:
#line 2450 "fgl.yacc"
    {
		    A4GL_debug ("Got end");
		   //start_state("dtime_val",0);
		     strcpy(yyval.str,yyvsp[0].str);
		   
		}
    break;

  case 308:
#line 2460 "fgl.yacc"
    {
		   A4GL_debug("Nothing in fraction - assume 2");
		   strcpy(yyval.str,"2");
		   
		}
    break;

  case 309:
#line 2464 "fgl.yacc"
    {
		   A4GL_debug("Read fraction .. ");
		   A4GL_debug("    %s",yyvsp[-1].str);
		   strcpy(yyval.str,yyvsp[-1].str);
		   
		}
    break;

  case 310:
#line 2474 "fgl.yacc"
    {
		   A4GL_debug("Nothing in fraction - assume 2");
		   strcpy(yyval.str,"2");
		   
		}
    break;

  case 311:
#line 2478 "fgl.yacc"
    {
		   A4GL_debug("    %s",yyvsp[-1].str);
		   strcpy(yyval.str,yyvsp[-1].str);
		   
		}
    break;

  case 312:
#line 2487 "fgl.yacc"
    {
		   if (atoi(yyvsp[0].str)>5) {
		   a4gl_yyerror("Fraction values are between 0 and 5");
		      YYERROR;
		      }
		   
		}
    break;

  case 313:
#line 2498 "fgl.yacc"
    {
		   
		}
    break;

  case 314:
#line 2500 "fgl.yacc"
    {
		    sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));
		   
		}
    break;

  case 315:
#line 2508 "fgl.yacc"
    {
		   strcpy(yyval.str,"1");
		   
		}
    break;

  case 316:
#line 2512 "fgl.yacc"
    {
		   strcpy(yyval.str,"2");
		   
		}
    break;

  case 317:
#line 2516 "fgl.yacc"
    {
		   strcpy(yyval.str,"3");
		   
		}
    break;

  case 318:
#line 2520 "fgl.yacc"
    {
		   strcpy(yyval.str,"4");
		   
		}
    break;

  case 319:
#line 2524 "fgl.yacc"
    {
		   strcpy(yyval.str,"5");
		   
		}
    break;

  case 320:
#line 2528 "fgl.yacc"
    {
		   strcpy(yyval.str,"6");
		   
		}
    break;

  case 321:
#line 2532 "fgl.yacc"
    {
		   A4GL_debug("opt_frac returns %s",yyvsp[0].str);
		   sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6);
		    
		}
    break;

  case 325:
#line 2557 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 326:
#line 2561 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 327:
#line 2564 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 328:
#line 2567 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 329:
#line 2568 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 330:
#line 2569 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 331:
#line 2570 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 332:
#line 2571 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 333:
#line 2577 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 334:
#line 2584 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 335:
#line 2589 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 336:
#line 2594 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 337:
#line 2599 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 338:
#line 2603 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 339:
#line 2612 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 340:
#line 2614 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 341:
#line 2619 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 347:
#line 2631 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 348:
#line 2635 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 349:
#line 2638 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 350:
#line 2642 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 351:
#line 2645 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 352:
#line 2649 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 353:
#line 2656 "fgl.yacc"
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

  case 354:
#line 2674 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 355:
#line 2680 "fgl.yacc"
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

  case 356:
#line 2704 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 357:
#line 2707 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 358:
#line 2722 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 359:
#line 2725 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 360:
#line 2739 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 361:
#line 2741 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 362:
#line 2743 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 363:
#line 2745 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 364:
#line 2747 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 365:
#line 2749 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 366:
#line 2750 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 367:
#line 2757 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 368:
#line 2759 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 369:
#line 2763 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 370:
#line 2765 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 371:
#line 2767 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 372:
#line 2769 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 373:
#line 2771 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 374:
#line 2773 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 375:
#line 2775 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 376:
#line 2781 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2800 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 383:
#line 2806 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 384:
#line 2810 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 385:
#line 2815 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 389:
#line 2825 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 390:
#line 2826 "fgl.yacc"
    {inc_counter();}
    break;

  case 396:
#line 2832 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 397:
#line 2839 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 398:
#line 2839 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 400:
#line 2844 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);"); inc_counter();}
    break;

  case 401:
#line 2848 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 402:
#line 2854 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 403:
#line 2862 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 404:
#line 2868 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 405:
#line 2877 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 406:
#line 2879 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 407:
#line 2886 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 408:
#line 2907 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 409:
#line 2912 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 410:
#line 2917 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 411:
#line 2921 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 412:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 413:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 414:
#line 2944 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 415:
#line 2950 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 416:
#line 2956 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 419:
#line 2966 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 420:
#line 2972 "fgl.yacc"
    {
   		int a;
   		int incvcnt;
   		int flg=0;
		void *p1;

		if (strchr(yyvsp[0].str,'\n')==0) {
   			a=scan_variable(yyvsp[0].str);
		} else {
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

  case 421:
#line 3041 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 422:
#line 3052 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 423:
#line 3060 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 424:
#line 3068 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 425:
#line 3068 "fgl.yacc"
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

  case 426:
#line 3084 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 427:
#line 3088 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 428:
#line 3094 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 429:
#line 3097 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 430:
#line 3105 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 431:
#line 3109 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 432:
#line 3112 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 433:
#line 3118 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 434:
#line 3128 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 435:
#line 3133 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 436:
#line 3140 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 437:
#line 3143 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 438:
#line 3146 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 439:
#line 3151 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 440:
#line 3158 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 441:
#line 3163 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 442:
#line 3168 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 443:
#line 3173 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 444:
#line 3184 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 3192 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 446:
#line 3200 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 447:
#line 3205 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 448:
#line 3209 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 449:
#line 3214 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 450:
#line 3218 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 451:
#line 3222 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 452:
#line 3228 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 453:
#line 3231 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 454:
#line 3235 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 455:
#line 3239 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 456:
#line 3243 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 457:
#line 3247 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 458:
#line 3251 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 459:
#line 3258 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 460:
#line 3268 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 461:
#line 3273 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 462:
#line 3279 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		A4GL_debug("Print expr (1)");

		strcpy(yyval.str,A4GL_expr_for_call(yyvsp[-5].str,yyvsp[-1].str,lastlineno,infilename));
		yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 463:
#line 3288 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 464:
#line 3293 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 465:
#line 3296 "fgl.yacc"
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

  case 466:
#line 3307 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 467:
#line 3312 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 468:
#line 3315 "fgl.yacc"
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

  case 469:
#line 3333 "fgl.yacc"
    {chk4var=1;}
    break;

  case 470:
#line 3333 "fgl.yacc"
    {chk4var=0;}
    break;

  case 471:
#line 3333 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 472:
#line 3336 "fgl.yacc"
    {chk4var=1;}
    break;

  case 473:
#line 3336 "fgl.yacc"
    {chk4var=0;}
    break;

  case 474:
#line 3336 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 475:
#line 3340 "fgl.yacc"
    {chk4var=1;}
    break;

  case 476:
#line 3340 "fgl.yacc"
    {chk4var=0;}
    break;

  case 477:
#line 3340 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 478:
#line 3344 "fgl.yacc"
    {chk4var=1;}
    break;

  case 479:
#line 3344 "fgl.yacc"
    {chk4var=0;}
    break;

  case 480:
#line 3344 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 481:
#line 3348 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 482:
#line 3354 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 483:
#line 3360 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 484:
#line 3366 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 485:
#line 3374 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 486:
#line 3380 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 487:
#line 3388 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 488:
#line 3394 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 3403 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 3409 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 3416 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 3423 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 493:
#line 3432 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 494:
#line 3438 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 495:
#line 3444 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 496:
#line 3451 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 497:
#line 3457 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 498:
#line 3463 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3469 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3477 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3483 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3489 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 503:
#line 3498 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(sizeof(%s));",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3504 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 505:
#line 3510 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 506:
#line 3520 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 507:
#line 3521 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 510:
#line 3529 "fgl.yacc"
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

  case 511:
#line 3540 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 512:
#line 3541 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 513:
#line 3547 "fgl.yacc"
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

  case 514:
#line 3558 "fgl.yacc"
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

  case 515:
#line 3568 "fgl.yacc"
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

  case 518:
#line 3581 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 519:
#line 3586 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 520:
#line 3593 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 521:
#line 3597 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 522:
#line 3600 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 523:
#line 3603 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 524:
#line 3609 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3612 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 526:
#line 3615 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 527:
#line 3632 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 528:
#line 3635 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 529:
#line 3641 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 530:
#line 3642 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 531:
#line 3643 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 533:
#line 3648 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 534:
#line 3649 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3650 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3651 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3653 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3654 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3655 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 540:
#line 3657 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 541:
#line 3658 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 542:
#line 3659 "fgl.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 544:
#line 3665 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 545:
#line 3669 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 546:
#line 3673 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 547:
#line 3678 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 548:
#line 3682 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 549:
#line 3697 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 550:
#line 3701 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 551:
#line 3707 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 552:
#line 3711 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 553:
#line 3720 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 554:
#line 3721 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 555:
#line 3733 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		//start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 556:
#line 3739 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 557:
#line 3747 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
//start_state("formhandler",0);
}
    break;

  case 564:
#line 3765 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 565:
#line 3767 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3770 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 567:
#line 3772 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3786 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 573:
#line 3788 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3791 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 575:
#line 3793 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 588:
#line 3824 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 589:
#line 3826 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 590:
#line 3829 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 591:
#line 3831 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 592:
#line 3834 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 593:
#line 3836 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 594:
#line 3839 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 595:
#line 3841 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 596:
#line 3844 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 597:
#line 3846 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 598:
#line 3860 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 599:
#line 3864 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 600:
#line 3865 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 601:
#line 3872 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 603:
#line 3890 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 604:
#line 3906 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 605:
#line 3907 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 606:
#line 3908 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 607:
#line 3909 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 608:
#line 3910 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 609:
#line 3911 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 610:
#line 3912 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 614:
#line 3920 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 616:
#line 3926 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 617:
#line 3929 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 618:
#line 3934 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 619:
#line 3939 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 620:
#line 3942 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 621:
#line 3947 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 622:
#line 3952 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 623:
#line 3957 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 624:
#line 3964 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 625:
#line 3965 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 626:
#line 3972 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 627:
#line 3979 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 628:
#line 3981 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 629:
#line 3987 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 630:
#line 3992 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 631:
#line 3997 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 632:
#line 4002 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 633:
#line 4002 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 634:
#line 4005 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 635:
#line 4011 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 636:
#line 4016 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 637:
#line 4020 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 640:
#line 4028 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 641:
#line 4031 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 642:
#line 4034 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 643:
#line 4039 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 644:
#line 4044 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 645:
#line 4049 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 646:
#line 4056 "fgl.yacc"
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

  case 648:
#line 4067 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 649:
#line 4129 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 651:
#line 4138 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 652:
#line 4147 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 654:
#line 4154 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 655:
#line 4157 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 656:
#line 4163 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 657:
#line 4169 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 658:
#line 4173 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 659:
#line 4177 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 660:
#line 4183 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 661:
#line 4187 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 662:
#line 4191 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 663:
#line 4196 "fgl.yacc"
    {
//start_state("messagebox",1);
}
    break;

  case 664:
#line 4203 "fgl.yacc"
    {
//start_state("messagebox",0);
}
    break;

  case 683:
#line 4246 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 684:
#line 4253 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 685:
#line 4255 "fgl.yacc"
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

  case 687:
#line 4274 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 689:
#line 4277 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 690:
#line 4279 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 691:
#line 4282 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 692:
#line 4286 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 693:
#line 4289 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 694:
#line 4296 "fgl.yacc"
    {
		import_package(yyvsp[0].str);
	}
    break;

  case 695:
#line 4301 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 696:
#line 4312 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 697:
#line 4313 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 698:
#line 4316 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 700:
#line 4322 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 701:
#line 4326 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 702:
#line 4327 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 703:
#line 4331 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 707:
#line 4346 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 708:
#line 4348 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 711:
#line 4357 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 712:
#line 4360 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 713:
#line 4364 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 714:
#line 4367 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 715:
#line 4370 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 716:
#line 4373 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 717:
#line 4376 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 718:
#line 4380 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 719:
#line 4383 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 720:
#line 4386 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 721:
#line 4389 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 722:
#line 4392 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 4395 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 724:
#line 4398 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 4401 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 726:
#line 4404 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 727:
#line 4405 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 728:
#line 4405 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 729:
#line 4406 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 730:
#line 4406 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 731:
#line 4407 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 732:
#line 4407 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 733:
#line 4408 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 734:
#line 4411 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 735:
#line 4412 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 736:
#line 4415 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 737:
#line 4423 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 738:
#line 4427 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 739:
#line 4433 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 740:
#line 4437 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 741:
#line 4442 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 742:
#line 4447 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 743:
#line 4452 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 744:
#line 4453 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 745:
#line 4454 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 746:
#line 4458 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 747:
#line 4462 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 748:
#line 4471 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 749:
#line 4476 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 750:
#line 4480 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 751:
#line 4487 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 752:
#line 4496 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 753:
#line 4502 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 754:
#line 4503 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 755:
#line 4504 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 756:
#line 4505 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 757:
#line 4506 "fgl.yacc"
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

  case 758:
#line 4516 "fgl.yacc"
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

  case 759:
#line 4530 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 761:
#line 4533 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 762:
#line 4540 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 763:
#line 4541 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 764:
#line 4542 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 765:
#line 4543 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 766:
#line 4544 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 767:
#line 4545 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 768:
#line 4546 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 769:
#line 4547 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 770:
#line 4548 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 771:
#line 4553 "fgl.yacc"
    {iskey=1;}
    break;

  case 772:
#line 4553 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 773:
#line 4555 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 774:
#line 4558 "fgl.yacc"
    {iskey=1;}
    break;

  case 775:
#line 4558 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 776:
#line 4560 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 777:
#line 4564 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 778:
#line 4567 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 779:
#line 4568 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 781:
#line 4571 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 787:
#line 4583 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 788:
#line 4584 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 789:
#line 4585 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 790:
#line 4586 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 791:
#line 4587 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 792:
#line 4588 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 793:
#line 4589 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 794:
#line 4590 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 795:
#line 4591 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 796:
#line 4592 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 797:
#line 4593 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 798:
#line 4594 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 799:
#line 4595 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 800:
#line 4596 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 801:
#line 4600 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 802:
#line 4618 "fgl.yacc"
    {chk4var=1;}
    break;

  case 803:
#line 4618 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 804:
#line 4621 "fgl.yacc"
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

  case 805:
#line 4645 "fgl.yacc"
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

  case 807:
#line 4663 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 808:
#line 4669 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 809:
#line 4675 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 810:
#line 4681 "fgl.yacc"
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

  case 811:
#line 4693 "fgl.yacc"
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

  case 815:
#line 4724 "fgl.yacc"
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

  case 818:
#line 4741 "fgl.yacc"
    {
	}
    break;

  case 828:
#line 4767 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 832:
#line 4775 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 846:
#line 4799 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 847:
#line 4800 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 848:
#line 4808 "fgl.yacc"
    {
  if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 849:
#line 4814 "fgl.yacc"
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

  case 850:
#line 4830 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 851:
#line 4836 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 853:
#line 4851 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 854:
#line 4864 "fgl.yacc"
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

  case 855:
#line 4875 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 856:
#line 4882 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 857:
#line 4889 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 858:
#line 4895 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 859:
#line 4895 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 860:
#line 4900 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 861:
#line 4906 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 862:
#line 4914 "fgl.yacc"
    {
}
    break;

  case 866:
#line 4926 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 868:
#line 4934 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 869:
#line 4940 "fgl.yacc"
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

  case 872:
#line 4960 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 873:
#line 4966 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 874:
#line 4970 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 877:
#line 4982 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 878:
#line 4985 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 879:
#line 4989 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 880:
#line 4992 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 881:
#line 5004 "fgl.yacc"
    {
	//start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 882:
#line 5012 "fgl.yacc"
    {
	//start_state("menu",0);
	}
    break;

  case 883:
#line 5018 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 884:
#line 5029 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 885:
#line 5033 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 886:
#line 5040 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 887:
#line 5047 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 888:
#line 5053 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 889:
#line 5058 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 892:
#line 5065 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 893:
#line 5066 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 894:
#line 5068 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 895:
#line 5069 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 5072 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 897:
#line 5073 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 898:
#line 5074 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 899:
#line 5076 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 900:
#line 5081 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 901:
#line 5086 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 902:
#line 5093 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 906:
#line 5100 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 907:
#line 5102 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 908:
#line 5104 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 910:
#line 5114 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 911:
#line 5117 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 912:
#line 5120 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 919:
#line 5136 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 920:
#line 5141 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 921:
#line 5141 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 922:
#line 5144 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 923:
#line 5172 "fgl.yacc"
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

  case 925:
#line 5229 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 927:
#line 5236 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 928:
#line 5240 "fgl.yacc"
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

  case 929:
#line 5283 "fgl.yacc"
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

  case 933:
#line 5331 "fgl.yacc"
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

  case 934:
#line 5345 "fgl.yacc"
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

  case 939:
#line 5369 "fgl.yacc"
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

  case 940:
#line 5433 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 941:
#line 5438 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 942:
#line 5446 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 943:
#line 5451 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 944:
#line 5459 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 945:
#line 5465 "fgl.yacc"
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

  case 946:
#line 5497 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 947:
#line 5500 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 948:
#line 5502 "fgl.yacc"
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

  case 949:
#line 5543 "fgl.yacc"
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

  case 954:
#line 5596 "fgl.yacc"
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

  case 955:
#line 5648 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 957:
#line 5657 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 958:
#line 5662 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 959:
#line 5673 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 960:
#line 5680 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 962:
#line 5688 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 963:
#line 5691 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 964:
#line 5692 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 966:
#line 5694 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 967:
#line 5695 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 968:
#line 5698 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 969:
#line 5701 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 5707 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 971:
#line 5710 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 972:
#line 5714 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 973:
#line 5719 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 974:
#line 5727 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 975:
#line 5732 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 976:
#line 5739 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 977:
#line 5741 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 982:
#line 5769 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5776 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 984:
#line 5783 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 985:
#line 5786 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 986:
#line 5800 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 991:
#line 5817 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 992:
#line 5822 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 993:
#line 5828 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 995:
#line 5835 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 996:
#line 5840 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 997:
#line 5843 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 998:
#line 5844 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 999:
#line 5847 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1000:
#line 5848 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1001:
#line 5851 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1002:
#line 5852 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1003:
#line 5857 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1004:
#line 5864 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1005:
#line 5867 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1006:
#line 5873 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1007:
#line 5875 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5877 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1009:
#line 5879 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1010:
#line 5882 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1011:
#line 5882 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1012:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1013:
#line 5888 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1014:
#line 5896 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1015:
#line 5897 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1016:
#line 5902 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1017:
#line 5904 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5906 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1022:
#line 5924 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1023:
#line 5925 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1024:
#line 5926 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1025:
#line 5927 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1026:
#line 5928 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1027:
#line 5929 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1028:
#line 5930 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1029:
#line 5931 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1030:
#line 5932 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1031:
#line 5933 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1032:
#line 5934 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1033:
#line 5935 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1034:
#line 5936 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1035:
#line 5937 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1036:
#line 5938 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1037:
#line 5939 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1038:
#line 5940 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1039:
#line 5941 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1040:
#line 5942 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1041:
#line 5943 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1042:
#line 5944 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1043:
#line 5945 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1044:
#line 5946 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1045:
#line 5947 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1046:
#line 5948 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1047:
#line 5949 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1048:
#line 5950 "fgl.yacc"
    { print_options('r',yyvsp[0].str); }
    break;

  case 1049:
#line 5951 "fgl.yacc"
    { print_options('|',yyvsp[0].str); }
    break;

  case 1050:
#line 5955 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1051:
#line 5956 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1052:
#line 5960 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1053:
#line 5961 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1054:
#line 5976 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1057:
#line 5985 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1058:
#line 5989 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1059:
#line 5993 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1060:
#line 5997 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1061:
#line 6001 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1063:
#line 6021 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1064:
#line 6026 "fgl.yacc"
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

  case 1065:
#line 6039 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1066:
#line 6040 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1067:
#line 6044 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1068:
#line 6049 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1069:
#line 6050 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1070:
#line 6054 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1074:
#line 6060 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1075:
#line 6063 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1077:
#line 6078 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1078:
#line 6082 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1079:
#line 6088 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1080:
#line 6089 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1081:
#line 6094 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1082:
#line 6095 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1083:
#line 6098 "fgl.yacc"
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

  case 1085:
#line 6125 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
			}
    break;

  case 1086:
#line 6129 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1087:
#line 6133 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1088:
#line 6137 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("S","\"\"",yyvsp[-1].str);
			}
    break;

  case 1089:
#line 6141 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("C","\"\"",yyvsp[-1].str);
			}
    break;

  case 1090:
#line 6145 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[0].str);
			}
    break;

  case 1091:
#line 6155 "fgl.yacc"
    {
			print_convert_report(yyvsp[-6].str, yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1092:
#line 6158 "fgl.yacc"
    {
			print_convert_report(yyvsp[-4].str, yyvsp[-2].str,yyvsp[0].str,"\"\"");
		}
    break;

  case 1095:
#line 6167 "fgl.yacc"
    {
		print_free_convertable(yyvsp[0].str);
}
    break;

  case 1099:
#line 6177 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1100:
#line 6183 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		print_free_convertable(yyvsp[0].str); // Shouldn't really be needed - but they may have started it "AS CONVERTABLE"
		}
    break;

  case 1101:
#line 6188 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[-1].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[-1].str);
		// Can't free convertable here - developer needs to do that using FREE REPORT
	}
    break;

  case 1102:
#line 6193 "fgl.yacc"
    {
		print_finish_report(yyvsp[-6].str);
		print_convert_report(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
		print_free_convertable(yyvsp[-6].str);
	}
    break;

  case 1103:
#line 6198 "fgl.yacc"
    {
		print_finish_report(yyvsp[-4].str);
		print_convert_report(yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str,"\"\"");
		print_free_convertable(yyvsp[-4].str);
	}
    break;

  case 1104:
#line 6207 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1105:
#line 6213 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1106:
#line 6215 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1110:
#line 6225 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1111:
#line 6225 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1112:
#line 6230 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1113:
#line 6234 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1114:
#line 6239 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1115:
#line 6239 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1116:
#line 6243 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1117:
#line 6243 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1118:
#line 6244 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1119:
#line 6244 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1120:
#line 6245 "fgl.yacc"
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

  case 1121:
#line 6258 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1122:
#line 6259 "fgl.yacc"
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

  case 1123:
#line 6275 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1130:
#line 6287 "fgl.yacc"
    {
//start_state("skip",1);
}
    break;

  case 1131:
#line 6289 "fgl.yacc"
    {
	print_need_lines();
	//start_state("skip",0);
}
    break;

  case 1132:
#line 6295 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1133:
#line 6295 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1134:
#line 6298 "fgl.yacc"
    {
//start_state("KWLINE",1);
}
    break;

  case 1135:
#line 6300 "fgl.yacc"
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
//start_state("KWLINE",0); 
}
    break;

  case 1136:
#line 6316 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1137:
#line 6317 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1138:
#line 6318 "fgl.yacc"
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

  case 1139:
#line 6327 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1140:
#line 6339 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1146:
#line 6350 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1147:
#line 6355 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1148:
#line 6355 "fgl.yacc"
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

  case 1150:
#line 6379 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 1151:
#line 6385 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1152:
#line 6390 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1153:
#line 6396 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1154:
#line 6397 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1155:
#line 6398 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1156:
#line 6402 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1157:
#line 6403 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1158:
#line 6404 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1159:
#line 6405 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1160:
#line 6409 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1161:
#line 6419 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1162:
#line 6421 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1163:
#line 6426 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1164:
#line 6429 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1165:
#line 6434 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1166:
#line 6441 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1167:
#line 6448 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1168:
#line 6455 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1169:
#line 6464 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1170:
#line 6471 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1171:
#line 6478 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1172:
#line 6485 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1173:
#line 6492 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1178:
#line 6505 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1179:
#line 6506 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1180:
#line 6507 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1181:
#line 6508 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1182:
#line 6509 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1183:
#line 6510 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1184:
#line 6511 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1185:
#line 6512 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1186:
#line 6513 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1187:
#line 6514 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1190:
#line 6520 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1191:
#line 6521 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1192:
#line 6522 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1193:
#line 6523 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1198:
#line 6532 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1199:
#line 6533 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1200:
#line 6534 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1201:
#line 6535 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1202:
#line 6536 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1203:
#line 6537 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1204:
#line 6538 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1205:
#line 6539 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1206:
#line 6541 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1207:
#line 6542 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1208:
#line 6543 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1209:
#line 6544 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1210:
#line 6546 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1211:
#line 6547 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1212:
#line 6548 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1213:
#line 6549 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1217:
#line 6554 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1218:
#line 6555 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1222:
#line 6562 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1223:
#line 6571 "fgl.yacc"
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

  case 1224:
#line 6580 "fgl.yacc"
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

  case 1225:
#line 6593 "fgl.yacc"
    { 
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1226:
#line 6604 "fgl.yacc"
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

  case 1227:
#line 6615 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1228:
#line 6619 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1229:
#line 6623 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1230:
#line 6629 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1231:
#line 6634 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1232:
#line 6642 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1233:
#line 6645 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1234:
#line 6654 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1235:
#line 6665 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1237:
#line 6672 "fgl.yacc"
    {
    if (class_cnt>1) { a4gl_yyerror("You've already defined a class - you can't do any more now"); }

rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1238:
#line 6682 "fgl.yacc"
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

  case 1239:
#line 6692 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1240:
#line 6695 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1241:
#line 6699 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1242:
#line 6707 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1243:
#line 6710 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1244:
#line 6716 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1245:
#line 6720 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1246:
#line 6724 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1247:
#line 6728 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1248:
#line 6732 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1249:
#line 6738 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1250:
#line 6739 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1251:
#line 6740 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1252:
#line 6741 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1253:
#line 6746 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1254:
#line 6747 "fgl.yacc"
    { print_system_run(yyvsp[0].integer_val,0); }
    break;

  case 1255:
#line 6748 "fgl.yacc"
    { print_system_run(1,yyvsp[0].str); }
    break;

  case 1256:
#line 6749 "fgl.yacc"
    { print_system_run(2,0); }
    break;

  case 1257:
#line 6750 "fgl.yacc"
    { print_system_run(1+yyvsp[-2].integer_val,yyvsp[0].str); }
    break;

  case 1258:
#line 6751 "fgl.yacc"
    { print_system_run(2+yyvsp[-1].integer_val,0); }
    break;

  case 1259:
#line 6752 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1260:
#line 6753 "fgl.yacc"
    { print_system_run(0,0); }
    break;

  case 1261:
#line 6757 "fgl.yacc"
    {yyval.integer_val=512;}
    break;

  case 1262:
#line 6758 "fgl.yacc"
    {yyval.integer_val=256;}
    break;

  case 1263:
#line 6761 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1264:
#line 6766 "fgl.yacc"
    {
			if (A4GL_isyes(acl_getenv("A4GL_ADD_CASCADE"))) {
				sprintf(yyval.str, "%s %s CASCADE",yyvsp[-1].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str, "%s %s ",yyvsp[-1].str,yyvsp[0].str);
			}
		}
    break;

  case 1265:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1266:
#line 6774 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1267:
#line 6775 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1268:
#line 6780 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1269:
#line 6781 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1270:
#line 6787 "fgl.yacc"
    {insql=1;}
    break;

  case 1271:
#line 6787 "fgl.yacc"
    {insql=0;}
    break;

  case 1272:
#line 6787 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1273:
#line 6792 "fgl.yacc"
    {insql=1;}
    break;

  case 1274:
#line 6792 "fgl.yacc"
    {insql=0;}
    break;

  case 1275:
#line 6792 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1276:
#line 6800 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1277:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1279:
#line 6806 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1280:
#line 6811 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1281:
#line 6812 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1282:
#line 6813 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1283:
#line 6814 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1284:
#line 6815 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1286:
#line 6820 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1287:
#line 6820 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1289:
#line 6824 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6828 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1291:
#line 6829 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1292:
#line 6832 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1293:
#line 6833 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1294:
#line 6836 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1295:
#line 6839 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1296:
#line 6842 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1297:
#line 6848 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1298:
#line 6850 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1300:
#line 6863 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1301:
#line 6867 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1302:
#line 6868 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1304:
#line 6873 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1305:
#line 6876 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1306:
#line 6882 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1307:
#line 6885 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1308:
#line 6893 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1310:
#line 6900 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1311:
#line 6904 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1312:
#line 6908 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1313:
#line 6914 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1314:
#line 6917 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1315:
#line 6926 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1316:
#line 6929 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1317:
#line 6932 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1318:
#line 6935 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1319:
#line 6938 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1320:
#line 6941 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1321:
#line 6944 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1322:
#line 6951 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1323:
#line 6954 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1324:
#line 6961 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1325:
#line 6964 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1326:
#line 6970 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1327:
#line 6973 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1328:
#line 6980 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1329:
#line 6983 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1331:
#line 6991 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1333:
#line 7000 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1334:
#line 7003 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1335:
#line 7009 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1336:
#line 7012 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1337:
#line 7018 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1338:
#line 7025 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1339:
#line 7026 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1340:
#line 7030 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1341:
#line 7040 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1342:
#line 7043 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1343:
#line 7049 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1344:
#line 7051 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1345:
#line 7056 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1346:
#line 7057 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1347:
#line 7062 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1348:
#line 7063 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1349:
#line 7069 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1350:
#line 7070 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1354:
#line 7097 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1360:
#line 7103 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1361:
#line 7106 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1362:
#line 7109 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1363:
#line 7115 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1365:
#line 7121 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1367:
#line 7132 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1368:
#line 7146 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1369:
#line 7155 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1370:
#line 7155 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1371:
#line 7160 "fgl.yacc"
    {insql=1;}
    break;

  case 1372:
#line 7160 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1373:
#line 7165 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1374:
#line 7168 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1375:
#line 7170 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 7177 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 7181 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1379:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1380:
#line 7192 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1381:
#line 7195 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1382:
#line 7202 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1383:
#line 7206 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1384:
#line 7212 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1385:
#line 7217 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1386:
#line 7221 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1387:
#line 7227 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1388:
#line 7230 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1389:
#line 7236 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1390:
#line 7243 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1391:
#line 7247 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1392:
#line 7252 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1393:
#line 7262 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1394:
#line 7265 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1395:
#line 7267 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1396:
#line 7269 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1397:
#line 7271 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1398:
#line 7273 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1399:
#line 7275 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_RELATIVE);}
    break;

  case 1400:
#line 7277 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_long()",FETCH_ABSOLUTE);}
    break;

  case 1401:
#line 7283 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1402:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1403:
#line 7300 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 7306 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 7309 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 7316 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1412:
#line 7321 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1413:
#line 7326 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1414:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1415:
#line 7334 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1416:
#line 7342 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1417:
#line 7353 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1418:
#line 7354 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1419:
#line 7355 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1420:
#line 7358 "fgl.yacc"
    {insql=1;}
    break;

  case 1421:
#line 7358 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1422:
#line 7363 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1423:
#line 7368 "fgl.yacc"
    {
			print_exec_sql(convstrsql(yyvsp[0].str));
			printf("Warning: Informix specific SQL @ line %d\n",yylineno);
			strcpy(yyval.str,"InfxSpecificSql");
	}
    break;

  case 1424:
#line 7373 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1426:
#line 7379 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1428:
#line 7383 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1429:
#line 7388 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1430:
#line 7393 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1431:
#line 7397 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1433:
#line 7403 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1434:
#line 7407 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1435:
#line 7414 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 7415 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7416 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7417 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7427 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1443:
#line 7428 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1444:
#line 7429 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7433 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1446:
#line 7434 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1449:
#line 7441 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 7444 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1453:
#line 7447 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1456:
#line 7452 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1457:
#line 7454 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 7460 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 7466 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 7476 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1465:
#line 7481 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1466:
#line 7483 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7489 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7492 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1471:
#line 7498 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1472:
#line 7506 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7511 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 7521 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 7527 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 7532 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1480:
#line 7535 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1481:
#line 7540 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7546 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7551 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1485:
#line 7554 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1486:
#line 7557 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1487:
#line 7564 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7565 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1489:
#line 7566 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1490:
#line 7568 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1491:
#line 7581 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1492:
#line 7586 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1494:
#line 7590 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1495:
#line 7592 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1496:
#line 7599 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7602 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1498:
#line 7608 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1499:
#line 7616 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1500:
#line 7620 "fgl.yacc"
    {
		sprintf(yyval.str," NOT NULL UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1501:
#line 7624 "fgl.yacc"
    {
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1502:
#line 7628 "fgl.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		sprintf(yyval.str," UNIQUE ");
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1503:
#line 7633 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1504:
#line 7636 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1505:
#line 7639 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1506:
#line 7647 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1507:
#line 7654 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1510:
#line 7663 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1511:
#line 7669 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1512:
#line 7672 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1513:
#line 7683 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1514:
#line 7690 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1515:
#line 7696 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1516:
#line 7699 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1517:
#line 7706 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7713 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1520:
#line 7720 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1521:
#line 7726 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1522:
#line 7727 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 7728 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1525:
#line 7732 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_TABLE_ALIAS_AS"))) {
			sprintf(yyval.str,"%s AS %s",yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1526:
#line 7739 "fgl.yacc"
    {
			sprintf(yyval.str,"%s AS %s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1528:
#line 7746 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1529:
#line 7753 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1530:
#line 7758 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1531:
#line 7759 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1532:
#line 7762 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1533:
#line 7765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1534:
#line 7770 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1535:
#line 7771 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1536:
#line 7776 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1537:
#line 7779 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1538:
#line 7785 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1539:
#line 7788 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1540:
#line 7794 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1541:
#line 7797 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1542:
#line 7803 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1543:
#line 7806 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1544:
#line 7813 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1545:
#line 7814 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1546:
#line 7843 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1547:
#line 7844 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1548:
#line 7848 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1550:
#line 7861 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1551:
#line 7864 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1552:
#line 7867 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1553:
#line 7870 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1555:
#line 7878 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1556:
#line 7881 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1558:
#line 7887 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1560:
#line 7893 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1561:
#line 7896 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1562:
#line 7899 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1563:
#line 7902 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1564:
#line 7905 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1565:
#line 7908 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1566:
#line 7911 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1567:
#line 7914 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1568:
#line 7919 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1570:
#line 7926 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1574:
#line 7932 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1575:
#line 7933 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1576:
#line 7938 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1577:
#line 7941 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1578:
#line 7945 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1579:
#line 7951 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1580:
#line 7952 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1581:
#line 7953 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1582:
#line 7954 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1587:
#line 7974 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7978 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1590:
#line 7979 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1592:
#line 7982 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1593:
#line 7983 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			sprintf(yyval.str," DECIMAL %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
	}
    break;

  case 1594:
#line 7992 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
			strcpy(yyval.str,"DECIMAL");
		} else {
			strcpy(yyval.str,"MONEY");
		}
	}
    break;

  case 1601:
#line 8006 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1602:
#line 8008 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1603:
#line 8010 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1605:
#line 8013 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1607:
#line 8016 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1611:
#line 8021 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1612:
#line 8023 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1613:
#line 8026 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1614:
#line 8027 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1615:
#line 8034 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1619:
#line 8039 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1623:
#line 8055 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1624:
#line 8062 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1625:
#line 8066 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1626:
#line 8067 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1627:
#line 8068 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1628:
#line 8076 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1629:
#line 8077 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1630:
#line 8078 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1631:
#line 8089 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1632:
#line 8096 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1633:
#line 8101 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1634:
#line 8102 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1635:
#line 8103 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1636:
#line 8111 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1637:
#line 8112 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1638:
#line 8113 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1640:
#line 8139 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1641:
#line 8140 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1642:
#line 8141 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1643:
#line 8145 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1644:
#line 8148 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1645:
#line 8154 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1646:
#line 8159 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1647:
#line 8164 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1649:
#line 8175 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1653:
#line 8193 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1654:
#line 8196 "fgl.yacc"
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

  case 1655:
#line 8209 "fgl.yacc"
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

  case 1656:
#line 8224 "fgl.yacc"
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

  case 1657:
#line 8236 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1658:
#line 8238 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1659:
#line 8241 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1660:
#line 8241 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1661:
#line 8241 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1662:
#line 8241 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1663:
#line 8241 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1664:
#line 8241 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1665:
#line 8242 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1666:
#line 8245 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1681:
#line 8263 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1682:
#line 8266 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1683:
#line 8267 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1684:
#line 8268 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1685:
#line 8272 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1686:
#line 8280 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1687:
#line 8280 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1688:
#line 8286 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1689:
#line 8286 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1690:
#line 8293 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1691:
#line 8293 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1692:
#line 8299 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1693:
#line 8299 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1694:
#line 8307 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1695:
#line 8308 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1696:
#line 8309 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1697:
#line 8312 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1698:
#line 8312 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1700:
#line 8316 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1701:
#line 8317 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1702:
#line 8328 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1703:
#line 8331 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1704:
#line 8337 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1705:
#line 8342 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1706:
#line 8350 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1707:
#line 8362 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1708:
#line 8363 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1709:
#line 8366 "fgl.yacc"
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

  case 1710:
#line 8381 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1711:
#line 8392 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1712:
#line 8395 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1713:
#line 8403 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1714:
#line 8412 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1715:
#line 8415 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1716:
#line 8419 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1717:
#line 8422 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1718:
#line 8423 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1720:
#line 8436 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1721:
#line 8437 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1722:
#line 8446 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1723:
#line 8455 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1724:
#line 8460 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1725:
#line 8461 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1726:
#line 8462 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1727:
#line 8463 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1728:
#line 8470 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1729:
#line 8473 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1730:
#line 8479 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1731:
#line 8482 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1732:
#line 8489 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1733:
#line 8501 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1734:
#line 8510 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1735:
#line 8513 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1736:
#line 8516 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1737:
#line 8522 "fgl.yacc"
    {
			/*
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,$<sql_string>1);
			}
			*/
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1738:
#line 8530 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1739:
#line 8533 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1740:
#line 8534 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1741:
#line 8535 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1742:
#line 8536 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1743:
#line 8537 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1744:
#line 8540 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1745:
#line 8547 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1746:
#line 8549 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1747:
#line 8551 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1748:
#line 8553 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1749:
#line 8555 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1750:
#line 8556 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1751:
#line 8557 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1752:
#line 8558 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1753:
#line 8559 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1754:
#line 8560 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1755:
#line 8561 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1756:
#line 8563 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1757:
#line 8565 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1758:
#line 8567 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1759:
#line 8569 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1760:
#line 8571 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1761:
#line 8573 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1762:
#line 8575 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1763:
#line 8576 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1764:
#line 8578 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1765:
#line 8579 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1766:
#line 8580 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1767:
#line 8586 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1768:
#line 8587 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1770:
#line 8597 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1771:
#line 8605 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1772:
#line 8609 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1773:
#line 8616 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1774:
#line 8616 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1776:
#line 8620 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1777:
#line 8625 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1778:
#line 8625 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1780:
#line 8629 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1781:
#line 8633 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1784:
#line 8642 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1785:
#line 8642 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1790:
#line 8661 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1791:
#line 8662 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1794:
#line 8670 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1795:
#line 8676 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1798:
#line 8695 "fgl.yacc"
    {strcpy(yyval.str," UNITS YEAR");}
    break;

  case 1799:
#line 8696 "fgl.yacc"
    {strcpy(yyval.str," UNITS MONTH"); }
    break;

  case 1800:
#line 8697 "fgl.yacc"
    {strcpy(yyval.str," UNITS DAY"); }
    break;

  case 1801:
#line 8698 "fgl.yacc"
    {strcpy(yyval.str," UNITS HOUR"); }
    break;

  case 1802:
#line 8699 "fgl.yacc"
    {strcpy(yyval.str," UNITS MINUTE"); }
    break;

  case 1803:
#line 8700 "fgl.yacc"
    {strcpy(yyval.str," UNITS SECOND"); }
    break;

  case 1804:
#line 8704 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1805:
#line 8705 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1806:
#line 8706 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1808:
#line 8711 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1809:
#line 8712 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1810:
#line 8716 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1811:
#line 8732 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1812:
#line 8733 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1813:
#line 8734 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1814:
#line 8738 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1815:
#line 8752 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1816:
#line 8756 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1818:
#line 8765 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1820:
#line 8770 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1821:
#line 8771 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1822:
#line 9095 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1823:
#line 9095 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 1824:
#line 9102 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 1825:
#line 9102 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 1826:
#line 9190 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1827:
#line 9194 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1828:
#line 9196 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1829:
#line 9203 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1830:
#line 9207 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1831:
#line 9213 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1832:
#line 9221 "fgl.yacc"
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

  case 1833:
#line 9231 "fgl.yacc"
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

  case 1834:
#line 9241 "fgl.yacc"
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

  case 1835:
#line 9253 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1836:
#line 9256 "fgl.yacc"
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

  case 1837:
#line 9275 "fgl.yacc"
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

  case 1838:
#line 9301 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1839:
#line 9304 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1841:
#line 9313 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1842:
#line 9318 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1843:
#line 9321 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1844:
#line 9329 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1845:
#line 9337 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1846:
#line 9350 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1847:
#line 9353 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1848:
#line 9361 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1849:
#line 9364 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1850:
#line 9367 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1851:
#line 9375 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 1852:
#line 9379 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1853:
#line 9380 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 1854:
#line 9381 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 1855:
#line 9382 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1856:
#line 9383 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 1857:
#line 9384 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1858:
#line 9385 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 1859:
#line 9386 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1860:
#line 9390 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1861:
#line 9391 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1862:
#line 9392 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1863:
#line 9393 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1864:
#line 9394 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1865:
#line 9400 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1866:
#line 9401 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1867:
#line 9402 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1868:
#line 9403 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1869:
#line 9404 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1870:
#line 9405 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1871:
#line 9406 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1872:
#line 9407 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1873:
#line 9408 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1874:
#line 9409 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1875:
#line 9410 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1876:
#line 9411 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1877:
#line 9412 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1878:
#line 9413 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1879:
#line 9414 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1880:
#line 9415 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1881:
#line 9420 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1882:
#line 9426 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1883:
#line 9427 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1884:
#line 9435 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 1885:
#line 9437 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 1887:
#line 9443 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1888:
#line 9447 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 1889:
#line 9451 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 1890:
#line 9467 "fgl.yacc"
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

  case 1891:
#line 9481 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 1892:
#line 9487 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1893:
#line 9489 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1897:
#line 9503 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 1898:
#line 9506 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 1899:
#line 9513 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 1900:
#line 9516 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 1901:
#line 9546 "fgl.yacc"
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

  case 1902:
#line 9571 "fgl.yacc"
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

  case 1903:
#line 9626 "fgl.yacc"
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

  case 1904:
#line 9661 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 1905:
#line 9670 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 1906:
#line 9681 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 1907:
#line 9684 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 1908:
#line 9690 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 1909:
#line 9703 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 1910:
#line 9717 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1911:
#line 9720 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1912:
#line 9724 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1913:
#line 9739 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 1914:
#line 9739 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 1915:
#line 9745 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1916:
#line 9746 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1917:
#line 9749 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 1918:
#line 9750 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1919:
#line 9751 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1920:
#line 9752 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1921:
#line 9753 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1922:
#line 9754 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1923:
#line 9755 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 1924:
#line 9766 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1925:
#line 9770 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1926:
#line 9774 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1927:
#line 9778 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1928:
#line 9783 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1929:
#line 9787 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1930:
#line 9792 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1932:
#line 9800 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1934:
#line 9806 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1935:
#line 9812 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1936:
#line 9816 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1941:
#line 9834 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1942:
#line 9841 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1943:
#line 9851 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1944:
#line 9851 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19105 "y.tab.c"

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



