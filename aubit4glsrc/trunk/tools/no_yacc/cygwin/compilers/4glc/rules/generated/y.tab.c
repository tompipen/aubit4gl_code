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
     NAME = 1696,
     UMINUS = 1697,
     COMMA = 1603,
     KW_OR = 1643,
     KW_AND = 1598,
     KW_USING = 1535,
     NOT = 1618,
     MATCHES = 1414,
     POWER = 1521,
     LESS_THAN = 1517,
     GREATER_THAN = 1432,
     EQUAL = 1593,
     GREATER_THAN_EQ = 1331,
     LESS_THAN_EQ = 1389,
     NOT_EQUAL = 1463,
     PLUS = 1629,
     MINUS = 1616,
     MULTIPLY = 1522,
     DIVIDE = 1549,
     MOD = 1617,
     COMMAND = 1396,
     NUMBER_VALUE = 1698,
     CHAR_VALUE = 1699,
     INT_VALUE = 1700,
     NAMED_GEN = 1701,
     CLINE = 1702,
     SQLLINE = 1703,
     KW_CSTART = 1704,
     KW_CEND = 1705,
     USER_DTYPE = 1706,
     SQL_TEXT = 1707,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     BEFORE_INSERT = 1004,
     CONCAT_PIPES = 1005,
     BEFORE_DELETE = 1006,
     AFTER_INSERT = 1007,
     AFTER_DELETE = 1008,
     EXECUTE_IMMEDIATE = 1009,
     DELETE_ROW_EQUAL_TRUE = 1010,
     INSERT_ROW_EQUAL_TRUE = 1011,
     DELETE_ROW_EQUAL_FALSE = 1012,
     INSERT_ROW_EQUAL_FALSE = 1013,
     CURRENT_ROW_DISPLAY_EQUAL = 1014,
     MAXCOUNT = 1015,
     ALTER_TABLE = 1016,
     WHENEVER_ERROR_CONTINUE = 1017,
     WHENEVER_ANY_ERROR_CONTINUE = 1018,
     WHENEVER_WARNING_CONTINUE = 1019,
     WHENEVER_SQLSUCCESS_CONTINUE = 1020,
     WHENEVER_SQLWARNING_CONTINUE = 1021,
     WHENEVER_NOT_FOUND_CONTINUE = 1022,
     WHENEVER_SQLERROR_CONTINUE = 1023,
     WHENEVER_SUCCESS_CONTINUE = 1024,
     WHENEVER_ERROR_GOTO = 1025,
     WHENEVER_ANY_ERROR_GOTO = 1026,
     WHENEVER_WARNING_GOTO = 1027,
     WHENEVER_SQLSUCCESS_GOTO = 1028,
     WHENEVER_SQLWARNING_GOTO = 1029,
     WHENEVER_NOT_FOUND_GOTO = 1030,
     WHENEVER_SQLERROR_GOTO = 1031,
     WHENEVER_SUCCESS_GOTO = 1032,
     WHENEVER_ERROR_CALL = 1033,
     WHENEVER_ANY_ERROR_CALL = 1034,
     WHENEVER_WARNING_CALL = 1035,
     WHENEVER_SQLSUCCESS_CALL = 1036,
     WHENEVER_SQLWARNING_CALL = 1037,
     WHENEVER_NOT_FOUND_CALL = 1038,
     WHENEVER_SQLERROR_CALL = 1039,
     WHENEVER_SUCCESS_CALL = 1040,
     WHENEVER_ERROR_STOP = 1041,
     WHENEVER_ANY_ERROR_STOP = 1042,
     WHENEVER_WARNING_STOP = 1043,
     WHENEVER_SQLSUCCESS_STOP = 1044,
     WHENEVER_SQLWARNING_STOP = 1045,
     WHENEVER_NOT_FOUND_STOP = 1046,
     WHENEVER_SQLERROR_STOP = 1047,
     WHENEVER_SUCCESS_STOP = 1048,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1049,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1050,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1051,
     XSET_MULTIPLY_EQUAL = 1052,
     XSET_OPEN_BRACKET = 1053,
     NEWFORMATSHARED = 1054,
     CREATE_DATABASE = 1055,
     IMPORT_LEGACY_FUNCTION = 1056,
     ADD_CONSTRAINT = 1057,
     DROP_CONSTRAINT = 1058,
     AS_STATIC = 1059,
     NOT_FIELD_TOUCHED = 1060,
     LOCAL_FUNCTION = 1061,
     EVERY_ROW = 1062,
     ELIF = 1063,
     DOUBLE_PRECISION = 1064,
     COUNT_MULTIPLY = 1065,
     WAIT_FOR_KEY = 1066,
     AT_TERMINATION_CALL = 1067,
     TERMINATE_REPORT = 1068,
     TO_MAIN_CAPTION = 1069,
     CLEARSTAT = 1070,
     TO_MENUITEM = 1071,
     ID_TO_INT = 1072,
     TO_STATUSBOX = 1073,
     ASCII_HEIGHT_ALL = 1074,
     ASCII_WIDTH_ALL = 1075,
     IMPORT_DATATYPE = 1076,
     PAGE_TRAILER_SIZE = 1077,
     PAGE_HEADER_SIZE = 1078,
     FIRST_PAGE_HEADER_SIZE = 1079,
     BYTES_USE_AS_IMAGE = 1080,
     BYTES_USE_AS_ASCII = 1081,
     KWUP_BY = 1082,
     KWDOWN_BY = 1083,
     CLOSE_STATUSBOX = 1084,
     MODIFY_NEXT_SIZE = 1085,
     LOCK_MODE_PAGE = 1086,
     LOCK_MODE_ROW = 1087,
     TO_PIPE = 1088,
     TO_PRINTER = 1089,
     STATUSBOX = 1090,
     CONNECT_TO = 1091,
     FORMHANDLER_INPUT = 1092,
     UNITS_YEAR = 1093,
     UNITS_MONTH = 1094,
     UNITS_DAY = 1095,
     UNITS_HOUR = 1096,
     UNITS_MINUTE = 1097,
     UNITS_SECOND = 1098,
     NO_NEW_LINES = 1099,
     FIELDTOWIDGET = 1100,
     WITH_HOLD = 1101,
     SHOW_MENU = 1102,
     CWIS = 1103,
     CREATE_IDX = 1104,
     FORM_IS_COMPILED = 1105,
     PDF_REPORT = 1106,
     IMPORT_FUNCTION = 1107,
     PROMPT_MANY = 1108,
     POINTS = 1109,
     MM = 1110,
     INCHES = 1111,
     PREPEND = 1112,
     MEMBER_OF = 1113,
     MEMBER_FUNCTION = 1114,
     APPEND = 1115,
     TEMPLATE = 1116,
     END_TEMPLATE = 1117,
     SQLSICS = 1118,
     CREATE_SCHEMA = 1119,
     SQLSIRR = 1120,
     UPDATESTATS_T = 1121,
     SQLSICR = 1122,
     WHENEVER_SQLSUCCESS = 1123,
     WHENEVER_SQLWARNING = 1124,
     WHENEVER_ANY_ERROR = 1125,
     WHENEVER_NOT_FOUND = 1126,
     WHENEVER_SQLERROR = 1127,
     WHENEVER_SUCCESS = 1128,
     WHENEVER_WARNING = 1129,
     WHENEVER_ERROR = 1130,
     START_EXTERN = 1131,
     CONTINUE_CONSTRUCT = 1132,
     FOUNCONSTR = 1133,
     SQLSIDR = 1134,
     CREATE_TEMP_TABLE = 1135,
     CURRENT_WINDOW_IS = 1136,
     FIRST_PAGE_HEADER = 1137,
     ORDER_EXTERNAL_BY = 1138,
     SCROLL_CURSOR_FOR = 1139,
     SCROLL_CURSOR = 1140,
     SQL_INTERRUPT_OFF = 1141,
     STOP_ALL_EXTERNAL = 1142,
     WITH_CHECK_OPTION = 1143,
     WITH_GRANT_OPTION = 1144,
     SQLSLMNW = 1145,
     ADDCONSTUNIQ = 1146,
     CONTINUE_DISPLAY = 1147,
     CONTINUE_FOREACH = 1148,
     OUTPUT_TO_REPORT = 1149,
     SQL_INTERRUPT_ON = 1150,
     WHERE_CURRENT_OF = 1151,
     WITHOUT_DEFAULTS = 1152,
     FOCONSTR = 1153,
     SCALED_BY = 1154,
     CONTINUE_PROMPT = 1155,
     PDF_FUNCTION = 1156,
     DEFER_INTERRUPT = 1157,
     DISPLAY_BY_NAME = 1158,
     NOT_NULL_UNIQUE = 1159,
     SKIP_TO_TOP = 1160,
     TOP_OF_PAGE = 1161,
     SKIP_TO = 1162,
     SKIP_BY = 1163,
     WITHOUT_WAITING = 1164,
     BEFCONSTRUCT = 1165,
     SQLSLMW = 1166,
     AFTCONSTRUCT = 1167,
     ALL_PRIVILEGES = 1168,
     CLOSE_DATABASE = 1169,
     CONTINUE_INPUT = 1170,
     CONTINUE_WHILE = 1171,
     CREATE_SYNONYM = 1172,
     DROP_TABLE = 1173,
     EXIT_CONSTRUCT = 1174,
     INEXCLUSIVE = 1175,
     REPORT_TO_PRINTER = 1176,
     REPORT_TO_PIPE = 1177,
     RETURN = 1178,
     SET_SESSION_TO = 1179,
     UPDATESTATS = 1180,
     WITHOUT_HEAD = 1181,
     CLEARSCR = 1182,
     WITH_B_LOG = 1183,
     AUTHORIZATION = 1184,
     BOTTOM_MARGIN = 1185,
     CLOSE_SESSION = 1186,
     CONTINUE_CASE = 1187,
     CONTINUE_MENU = 1188,
     DISPLAY_ARRAY = 1189,
     END_SQL = 1190,
     DOLLAR = 1191,
     END_CONSTRUCT = 1192,
     FIELD_TOUCHED = 1193,
     FINISH_REPORT = 1194,
     INFACC = 1195,
     INPUT_NO_WRAP = 1196,
     LOCKMODEPAGE = 1197,
     SETPMOFF = 1198,
     UNCONSTRAINED = 1199,
     PAGE_TRAILER = 1200,
     SETPMON = 1201,
     BEFGROUP = 1202,
     CLOSE_WINDOW = 1203,
     COMMENT_LINE = 1204,
     CONTINUE_FOR = 1205,
     CREATE_DB = 1206,
     CREATE_TABLE = 1207,
     DEFAULT_NULL = 1208,
     DELETE_USING = 1209,
     DISPLAY_FORM = 1210,
     END_FUNCTION = 1211,
     EXIT_DISPLAY = 1212,
     EXIT_FOREACH = 1213,
     EXIT_PROGRAM = 1214,
     INFCOLS = 1215,
     LOCKMODEROW = 1216,
     ON_EVERY_ROW = 1217,
     OPEN_SESSION = 1218,
     RIGHT_MARGIN = 1219,
     SELECT_USING = 1220,
     START_REPORT = 1221,
     UNLOCK_TABLE = 1222,
     UPDATE_USING = 1223,
     ACL_BUILTIN = 1224,
     AFTGROUP = 1225,
     INFIDX = 1226,
     INFSTAT = 1227,
     LEFT_MARGIN = 1228,
     PAGE_HEADER = 1229,
     ROLLBACK_W = 1230,
     SET_SESSION = 1231,
     SQLSEOFF = 1232,
     WITH_A_LOG = 1233,
     BEFDISP = 1234,
     BEFORE_MENU = 1235,
     CREATE_VIEW = 1236,
     DEFINE_TYPE = 1237,
     DELETE_FROM = 1238,
     END_DISPLAY = 1239,
     END_REPORT = 1240,
     END_FOREACH = 1241,
     END_FOR = 1242,
     END_GLOBALS = 1243,
     EXIT_PROMPT = 1244,
     EXTENT_SIZE = 1245,
     FOREIGN_KEY = 1246,
     HIDE_OPTION = 1247,
     HIDE_WINDOW = 1248,
     INSERT_INTO = 1249,
     IS_NOT_NULL = 1250,
     MOVE_WINDOW = 1251,
     NEXT_OPTION = 1252,
     NOT_MATCHES = 1253,
     ON_LAST_ROW = 1254,
     OPEN_WINDOW = 1255,
     OPEN_STATUSBOX = 1256,
     PAGE_LENGTH = 1257,
     PAGE_WIDTH = 1258,
     PRIMARY_KEY = 1259,
     PROMPT_LINE = 1260,
     RECORD_LIKE = 1261,
     ROLLFORWARD = 1262,
     SETBL = 1263,
     SHOW_OPTION = 1264,
     SHOW_WINDOW = 1265,
     SQLSEON = 1266,
     TO_DATABASE = 1267,
     USE_SESSION = 1268,
     WITH_NO_LOG = 1269,
     AFTDISP = 1270,
     BEFFIELD = 1271,
     INSHARE = 1272,
     UNLOCKTAB = 1273,
     AFTFIELD = 1274,
     ATTRIBUTES = 1275,
     BEFINP = 1276,
     BEGIN_WORK = 1277,
     CLEARWIN = 1278,
     CLOSE_FORM = 1279,
     DEFER_QUIT = 1280,
     DESCENDING = 1281,
     DROP_INDEX = 1282,
     END_PROMPT = 1283,
     END_RECORD = 1284,
     ERROR_LINE = 1285,
     EXIT_INPUT = 1286,
     EXIT_WHILE = 1287,
     FOR_UPDATE_OF = 1288,
     FOR_UPDATE = 1289,
     GET_FLDBUF = 1290,
     INITIALIZE = 1291,
     INPUT_WRAP = 1292,
     LOCK_TABLE = 1293,
     MSG_LINE = 1294,
     NOT_EXISTS = 1295,
     ON_ANY_KEY = 1296,
     REFERENCES = 1297,
     RENCOL = 1298,
     SET_CURSOR = 1299,
     SMALLFLOAT = 1300,
     SQLSUCCESS = 1301,
     TOP_MARGIN = 1302,
     WITH_ARRAY = 1303,
     ACCEPTKEY = 1304,
     ACCEPT = 1305,
     AFTINP = 1306,
     CLEARFORMTODEFAULTS = 1307,
     CLEARFORM = 1308,
     CLEAR_X_FORM = 1309,
     COMMIT_W = 1310,
     NEXTPAGE = 1311,
     PREVPAGE = 1312,
     CTRL_KEY = 1313,
     INFTABS = 1314,
     NEXTFIELD = 1315,
     NEXTFORM = 1316,
     RENTAB = 1317,
     ASCENDING = 1318,
     ASSOCIATE = 1319,
     CHAR = 1320,
     CONSTRUCT = 1321,
     DELIMITER = 1322,
     DOWNSHIFT = 1323,
     DROP_VIEW = 1324,
     END_INPUT = 1325,
     END_WHILE = 1326,
     EXCLUSIVE = 1327,
     EXIT_CASE = 1328,
     EXIT_MENU = 1329,
     FORM_LINE = 1330,
     INTERRUPT = 1332,
     INTO_TEMP = 1333,
     INVISIBLE = 1334,
     IN_MEMORY = 1335,
     LINKED_TO = 1336,
     LOAD_FROM = 1337,
     LOCKTAB = 1338,
     MENU_LINE = 1339,
     OPEN_FORM = 1340,
     OTHERWISE = 1341,
     PRECISION = 1342,
     PRIOR = 1343,
     PROCEDURE = 1344,
     REPORT_TO = 1345,
     RETURNING = 1346,
     UNDERLINE = 1347,
     UNLOAD_TO = 1348,
     BEFROW = 1349,
     UNLOAD_T = 1350,
     VARIABLE = 1351,
     ABSOLUTE = 1352,
     AFTROW = 1353,
     BUFFERED = 1354,
     CONSTANT = 1355,
     CONST = 1356,
     CONTINUE = 1357,
     DATABASE = 1358,
     DATETIME = 1359,
     DEFAULTS = 1360,
     DISTINCT = 1361,
     END_CASE = 1362,
     END_MAIN = 1363,
     END_MENU = 1364,
     END_TYPE = 1365,
     EXIT_FOR = 1366,
     EXTERNAL = 1367,
     FRACTION = 1368,
     FUNCTION = 1369,
     GROUP_BY = 1370,
     INTERVAL = 1371,
     KWMESSAGE = 1372,
     NOT_LIKE = 1373,
     NOT_ILIKE = 1374,
     NOT_NULL = 1375,
     PASSWORD = 1376,
     PREVIOUS = 1377,
     READONLY = 1378,
     REGISTER = 1379,
     RELATIVE = 1380,
     RESOURCE = 1381,
     SMALLINT = 1382,
     VALIDATE = 1383,
     WITH_LOG = 1384,
     WORDWRAP = 1385,
     BY_NAME = 1386,
     IN_FILE = 1387,
     IS_NULL = 1388,
     AVERAGE = 1390,
     BETWEEN = 1391,
     CAPTION = 1392,
     CLIPPED = 1393,
     CLOSE_BRACKET = 1394,
     COLUMNS = 1395,
     COMMENT = 1397,
     CONNECT = 1398,
     CURRENT = 1399,
     DBYNAME = 1400,
     DECIMAL = 1401,
     DECLARE = 1402,
     DEFAULT = 1403,
     DISPLAY = 1404,
     ENDCODE = 1405,
     EXECUTE = 1406,
     FOREACH = 1407,
     FOREIGN = 1408,
     GLOBALS = 1409,
     INFIELD = 1410,
     INTEGER = 1411,
     KWWINDOW = 1412,
     MAGENTA = 1413,
     NUMERIC = 1415,
     OPTIONS = 1416,
     PERCENT = 1417,
     PREPARE = 1418,
     PROGRAM = 1419,
     RECOVER = 1420,
     REVERSE = 1421,
     SECTION = 1422,
     SESSION = 1423,
     SYNONYM = 1424,
     THRU = 1425,
     TRAILER = 1426,
     UPSHIFT = 1427,
     VARCHAR = 1428,
     WAITING = 1429,
     CLOSE_SHEV = 1430,
     CLOSE_SQUARE = 1431,
     KW_FALSE = 1433,
     NOT_IN = 1434,
     ONKEY = 1435,
     OPEN_BRACKET = 1436,
     BORDER = 1437,
     BOTTOM = 1438,
     COLUMN = 1439,
     COMMIT = 1440,
     CREATE = 1441,
     CURSOR = 1442,
     DEFINE = 1443,
     DELETE = 1444,
     DOUBLE = 1445,
     END_IF = 1446,
     ESCAPE = 1447,
     EXISTS = 1448,
     EXTEND = 1449,
     EXTENT = 1450,
     FINISH = 1451,
     FORMAT = 1452,
     HAVING = 1453,
     HEADER = 1454,
     INSERT = 1455,
     LOCATE = 1456,
     MARGIN = 1457,
     MEMORY = 1458,
     MINUTE = 1459,
     MODIFY = 1460,
     NORMAL = 1461,
     EQUAL_EQUAL = 1462,
     OPEN_SHEV = 1464,
     OPEN_SQUARE = 1465,
     OPTION = 1466,
     OUTPUT = 1467,
     PROMPT = 1468,
     PUBLIC = 1469,
     RECORD = 1470,
     REPORT = 1471,
     REVOKE = 1472,
     SCHEMA = 1473,
     SCROLL_USING = 1474,
     SCROLL = 1475,
     SECOND = 1476,
     SELECT = 1477,
     SERIAL = 1478,
     SETL = 1479,
     SHARED = 1480,
     SPACES = 1481,
     UNIQUE = 1482,
     UNLOCK = 1483,
     UPDATE = 1484,
     VALUES = 1485,
     YELLOW = 1486,
     AFTER = 1487,
     KWLINE = 1488,
     KW_NULL = 1489,
     KW_TRUE = 1490,
     SINGLE_KEY = 1491,
     ALTER = 1492,
     ARRAY = 1493,
     ASCII = 1494,
     AUDIT = 1495,
     BLACK = 1496,
     BLINK = 1497,
     CHECK = 1498,
     CLEAR = 1499,
     CLOSE = 1500,
     CODE_C = 1501,
     COUNT = 1502,
     DEFER = 1503,
     ERROR = 1504,
     EVERY = 1505,
     FETCH = 1506,
     FIRST = 1507,
     FLOAT = 1508,
     FLUSH = 1509,
     FOUND = 1510,
     GRANT = 1511,
     GREEN = 1512,
     GROUP = 1513,
     INDEX = 1514,
     KWFORM = 1515,
     LABEL = 1516,
     LOCAL = 1518,
     MONEY = 1519,
     MONTH = 1520,
     ORDER = 1523,
     OUTER = 1524,
     PAUSE = 1525,
     PRINT_IMAGE = 1526,
     PRINT_FILE = 1527,
     PRINT = 1528,
     RIGHT = 1529,
     DOUBLE_COLON = 1530,
     SEMICOLON = 1531,
     SLEEP = 1532,
     TUPLE = 1533,
     UNION = 1534,
     WHERE = 1536,
     WHILE = 1537,
     WHITE = 1538,
     CCODE = 1539,
     ANSI = 1540,
     BLUE = 1541,
     BOLD = 1542,
     BYTE = 1543,
     FCALL = 1544,
     CASE = 1545,
     CYAN = 1546,
     DATE = 1547,
     DESC = 1548,
     KWDOWN = 1550,
     TAB = 1551,
     DROP = 1552,
     ELSE = 1553,
     EXEC = 1554,
     EXIT = 1555,
     FREE = 1556,
     FROM = 1557,
     GOTO = 1558,
     HELP_FILE = 1559,
     LANG_FILE = 1560,
     HELP = 1561,
     HIDE = 1562,
     HOUR = 1563,
     INTO = 1564,
     LAST = 1565,
     LEFT = 1566,
     LIKE = 1567,
     MAIN = 1568,
     MENU = 1569,
     MODE = 1570,
     NEED = 1571,
     NEXT = 1572,
     NOCR = 1573,
     OPEN = 1574,
     QUIT = 1575,
     REAL = 1576,
     ROWS = 1577,
     SHOW = 1578,
     SIZE = 1579,
     SKIP = 1580,
     SOME = 1581,
     STEP = 1582,
     STOP = 1583,
     TEMP = 1584,
     TEXT = 1585,
     THEN = 1586,
     USER = 1587,
     WAIT = 1588,
     WHEN = 1589,
     WITH = 1590,
     WORK = 1591,
     YEAR = 1592,
     KW_IS = 1594,
     XSET = 1595,
     ADD = 1596,
     ALL = 1597,
     ANY = 1599,
     ASC = 1600,
     AVG = 1601,
     COLON = 1602,
     DAY = 1604,
     DBA = 1605,
     DEC = 1606,
     DIM = 1607,
     FKEY = 1608,
     FOR = 1609,
     KEY = 1610,
     KWNO = 1611,
     LET = 1612,
     LOG = 1613,
     XMAX = 1614,
     XMIN = 1615,
     PAD = 1619,
     PUT = 1620,
     RED = 1621,
     ROW = 1622,
     RUN = 1623,
     SQL = 1624,
     SUM = 1625,
     TOP = 1626,
     USE = 1627,
     ATSIGN = 1628,
     AS_TIFF = 1630,
     AS_GIF = 1631,
     AS_PNG = 1632,
     AS_JPEG = 1633,
     AS = 1634,
     AT = 1635,
     BY = 1636,
     DOT = 1637,
     GO = 1638,
     IF = 1639,
     IN = 1640,
     OF = 1641,
     ON = 1642,
     TO = 1644,
     KWUP = 1645,
     FONT_NAME = 1646,
     FONT_SIZE = 1647,
     PAPER_SIZE_IS_LETTER = 1648,
     PAPER_SIZE_IS_LEGAL = 1649,
     PAPER_SIZE_IS_A5 = 1650,
     PAPER_SIZE_IS_A4 = 1651,
     PAPER_SIZE_IS_LETTER_L = 1652,
     PAPER_SIZE_IS_LEGAL_L = 1653,
     PAPER_SIZE_IS_A5_L = 1654,
     PAPER_SIZE_IS_A4_L = 1655,
     FORMHANDLER = 1656,
     END_FORMHANDLER = 1657,
     BEFORE_EVENT = 1658,
     BEFORE_OPEN_FORM = 1659,
     AFTER_EVENT = 1660,
     BEFORE_CLOSE_FORM = 1661,
     BEFORE_ANY = 1662,
     AFTER_ANY = 1663,
     MENUHANDLER = 1664,
     END_MENUHANDLER = 1665,
     BEFORE_SHOW_MENU = 1666,
     DISABLE_PROGRAM = 1667,
     DISABLE_ALL = 1668,
     BUTTONS = 1669,
     CHECK_MENUITEM = 1670,
     DISABLE_FORM = 1671,
     DISABLE_MENUITEMS = 1672,
     DISABLE = 1673,
     ENABLE_FORM = 1674,
     ENABLE_MENUITEMS = 1675,
     ENABLE = 1676,
     KWFIELD = 1677,
     ICON = 1678,
     MESSAGEBOX = 1679,
     TO_DEFAULTS = 1680,
     UNCHECK_MENUITEM = 1681,
     BEFORE = 1682,
     INPUT = 1683,
     END = 1684,
     INT_TO_ID = 1685,
     TIMEOUT = 1686,
     OFF = 1687,
     WITH_1_DIMENSION = 1688,
     WITH_2_DIMENSION = 1689,
     WITH_3_DIMENSION = 1690,
     TILDE = 1691,
     ILIKE = 1692,
     FGL_ISDYNARR_ALLOCATED = 1693,
     FGL_DYNARR_EXTENTSIZE = 1694
   };
#endif
#define NAME 1696
#define UMINUS 1697
#define COMMA 1603
#define KW_OR 1643
#define KW_AND 1598
#define KW_USING 1535
#define NOT 1618
#define MATCHES 1414
#define POWER 1521
#define LESS_THAN 1517
#define GREATER_THAN 1432
#define EQUAL 1593
#define GREATER_THAN_EQ 1331
#define LESS_THAN_EQ 1389
#define NOT_EQUAL 1463
#define PLUS 1629
#define MINUS 1616
#define MULTIPLY 1522
#define DIVIDE 1549
#define MOD 1617
#define COMMAND 1396
#define NUMBER_VALUE 1698
#define CHAR_VALUE 1699
#define INT_VALUE 1700
#define NAMED_GEN 1701
#define CLINE 1702
#define SQLLINE 1703
#define KW_CSTART 1704
#define KW_CEND 1705
#define USER_DTYPE 1706
#define SQL_TEXT 1707
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define BEFORE_INSERT 1004
#define CONCAT_PIPES 1005
#define BEFORE_DELETE 1006
#define AFTER_INSERT 1007
#define AFTER_DELETE 1008
#define EXECUTE_IMMEDIATE 1009
#define DELETE_ROW_EQUAL_TRUE 1010
#define INSERT_ROW_EQUAL_TRUE 1011
#define DELETE_ROW_EQUAL_FALSE 1012
#define INSERT_ROW_EQUAL_FALSE 1013
#define CURRENT_ROW_DISPLAY_EQUAL 1014
#define MAXCOUNT 1015
#define ALTER_TABLE 1016
#define WHENEVER_ERROR_CONTINUE 1017
#define WHENEVER_ANY_ERROR_CONTINUE 1018
#define WHENEVER_WARNING_CONTINUE 1019
#define WHENEVER_SQLSUCCESS_CONTINUE 1020
#define WHENEVER_SQLWARNING_CONTINUE 1021
#define WHENEVER_NOT_FOUND_CONTINUE 1022
#define WHENEVER_SQLERROR_CONTINUE 1023
#define WHENEVER_SUCCESS_CONTINUE 1024
#define WHENEVER_ERROR_GOTO 1025
#define WHENEVER_ANY_ERROR_GOTO 1026
#define WHENEVER_WARNING_GOTO 1027
#define WHENEVER_SQLSUCCESS_GOTO 1028
#define WHENEVER_SQLWARNING_GOTO 1029
#define WHENEVER_NOT_FOUND_GOTO 1030
#define WHENEVER_SQLERROR_GOTO 1031
#define WHENEVER_SUCCESS_GOTO 1032
#define WHENEVER_ERROR_CALL 1033
#define WHENEVER_ANY_ERROR_CALL 1034
#define WHENEVER_WARNING_CALL 1035
#define WHENEVER_SQLSUCCESS_CALL 1036
#define WHENEVER_SQLWARNING_CALL 1037
#define WHENEVER_NOT_FOUND_CALL 1038
#define WHENEVER_SQLERROR_CALL 1039
#define WHENEVER_SUCCESS_CALL 1040
#define WHENEVER_ERROR_STOP 1041
#define WHENEVER_ANY_ERROR_STOP 1042
#define WHENEVER_WARNING_STOP 1043
#define WHENEVER_SQLSUCCESS_STOP 1044
#define WHENEVER_SQLWARNING_STOP 1045
#define WHENEVER_NOT_FOUND_STOP 1046
#define WHENEVER_SQLERROR_STOP 1047
#define WHENEVER_SUCCESS_STOP 1048
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1049
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1050
#define XSET_ident_DOT_MULTIPLY_EQUAL 1051
#define XSET_MULTIPLY_EQUAL 1052
#define XSET_OPEN_BRACKET 1053
#define NEWFORMATSHARED 1054
#define CREATE_DATABASE 1055
#define IMPORT_LEGACY_FUNCTION 1056
#define ADD_CONSTRAINT 1057
#define DROP_CONSTRAINT 1058
#define AS_STATIC 1059
#define NOT_FIELD_TOUCHED 1060
#define LOCAL_FUNCTION 1061
#define EVERY_ROW 1062
#define ELIF 1063
#define DOUBLE_PRECISION 1064
#define COUNT_MULTIPLY 1065
#define WAIT_FOR_KEY 1066
#define AT_TERMINATION_CALL 1067
#define TERMINATE_REPORT 1068
#define TO_MAIN_CAPTION 1069
#define CLEARSTAT 1070
#define TO_MENUITEM 1071
#define ID_TO_INT 1072
#define TO_STATUSBOX 1073
#define ASCII_HEIGHT_ALL 1074
#define ASCII_WIDTH_ALL 1075
#define IMPORT_DATATYPE 1076
#define PAGE_TRAILER_SIZE 1077
#define PAGE_HEADER_SIZE 1078
#define FIRST_PAGE_HEADER_SIZE 1079
#define BYTES_USE_AS_IMAGE 1080
#define BYTES_USE_AS_ASCII 1081
#define KWUP_BY 1082
#define KWDOWN_BY 1083
#define CLOSE_STATUSBOX 1084
#define MODIFY_NEXT_SIZE 1085
#define LOCK_MODE_PAGE 1086
#define LOCK_MODE_ROW 1087
#define TO_PIPE 1088
#define TO_PRINTER 1089
#define STATUSBOX 1090
#define CONNECT_TO 1091
#define FORMHANDLER_INPUT 1092
#define UNITS_YEAR 1093
#define UNITS_MONTH 1094
#define UNITS_DAY 1095
#define UNITS_HOUR 1096
#define UNITS_MINUTE 1097
#define UNITS_SECOND 1098
#define NO_NEW_LINES 1099
#define FIELDTOWIDGET 1100
#define WITH_HOLD 1101
#define SHOW_MENU 1102
#define CWIS 1103
#define CREATE_IDX 1104
#define FORM_IS_COMPILED 1105
#define PDF_REPORT 1106
#define IMPORT_FUNCTION 1107
#define PROMPT_MANY 1108
#define POINTS 1109
#define MM 1110
#define INCHES 1111
#define PREPEND 1112
#define MEMBER_OF 1113
#define MEMBER_FUNCTION 1114
#define APPEND 1115
#define TEMPLATE 1116
#define END_TEMPLATE 1117
#define SQLSICS 1118
#define CREATE_SCHEMA 1119
#define SQLSIRR 1120
#define UPDATESTATS_T 1121
#define SQLSICR 1122
#define WHENEVER_SQLSUCCESS 1123
#define WHENEVER_SQLWARNING 1124
#define WHENEVER_ANY_ERROR 1125
#define WHENEVER_NOT_FOUND 1126
#define WHENEVER_SQLERROR 1127
#define WHENEVER_SUCCESS 1128
#define WHENEVER_WARNING 1129
#define WHENEVER_ERROR 1130
#define START_EXTERN 1131
#define CONTINUE_CONSTRUCT 1132
#define FOUNCONSTR 1133
#define SQLSIDR 1134
#define CREATE_TEMP_TABLE 1135
#define CURRENT_WINDOW_IS 1136
#define FIRST_PAGE_HEADER 1137
#define ORDER_EXTERNAL_BY 1138
#define SCROLL_CURSOR_FOR 1139
#define SCROLL_CURSOR 1140
#define SQL_INTERRUPT_OFF 1141
#define STOP_ALL_EXTERNAL 1142
#define WITH_CHECK_OPTION 1143
#define WITH_GRANT_OPTION 1144
#define SQLSLMNW 1145
#define ADDCONSTUNIQ 1146
#define CONTINUE_DISPLAY 1147
#define CONTINUE_FOREACH 1148
#define OUTPUT_TO_REPORT 1149
#define SQL_INTERRUPT_ON 1150
#define WHERE_CURRENT_OF 1151
#define WITHOUT_DEFAULTS 1152
#define FOCONSTR 1153
#define SCALED_BY 1154
#define CONTINUE_PROMPT 1155
#define PDF_FUNCTION 1156
#define DEFER_INTERRUPT 1157
#define DISPLAY_BY_NAME 1158
#define NOT_NULL_UNIQUE 1159
#define SKIP_TO_TOP 1160
#define TOP_OF_PAGE 1161
#define SKIP_TO 1162
#define SKIP_BY 1163
#define WITHOUT_WAITING 1164
#define BEFCONSTRUCT 1165
#define SQLSLMW 1166
#define AFTCONSTRUCT 1167
#define ALL_PRIVILEGES 1168
#define CLOSE_DATABASE 1169
#define CONTINUE_INPUT 1170
#define CONTINUE_WHILE 1171
#define CREATE_SYNONYM 1172
#define DROP_TABLE 1173
#define EXIT_CONSTRUCT 1174
#define INEXCLUSIVE 1175
#define REPORT_TO_PRINTER 1176
#define REPORT_TO_PIPE 1177
#define RETURN 1178
#define SET_SESSION_TO 1179
#define UPDATESTATS 1180
#define WITHOUT_HEAD 1181
#define CLEARSCR 1182
#define WITH_B_LOG 1183
#define AUTHORIZATION 1184
#define BOTTOM_MARGIN 1185
#define CLOSE_SESSION 1186
#define CONTINUE_CASE 1187
#define CONTINUE_MENU 1188
#define DISPLAY_ARRAY 1189
#define END_SQL 1190
#define DOLLAR 1191
#define END_CONSTRUCT 1192
#define FIELD_TOUCHED 1193
#define FINISH_REPORT 1194
#define INFACC 1195
#define INPUT_NO_WRAP 1196
#define LOCKMODEPAGE 1197
#define SETPMOFF 1198
#define UNCONSTRAINED 1199
#define PAGE_TRAILER 1200
#define SETPMON 1201
#define BEFGROUP 1202
#define CLOSE_WINDOW 1203
#define COMMENT_LINE 1204
#define CONTINUE_FOR 1205
#define CREATE_DB 1206
#define CREATE_TABLE 1207
#define DEFAULT_NULL 1208
#define DELETE_USING 1209
#define DISPLAY_FORM 1210
#define END_FUNCTION 1211
#define EXIT_DISPLAY 1212
#define EXIT_FOREACH 1213
#define EXIT_PROGRAM 1214
#define INFCOLS 1215
#define LOCKMODEROW 1216
#define ON_EVERY_ROW 1217
#define OPEN_SESSION 1218
#define RIGHT_MARGIN 1219
#define SELECT_USING 1220
#define START_REPORT 1221
#define UNLOCK_TABLE 1222
#define UPDATE_USING 1223
#define ACL_BUILTIN 1224
#define AFTGROUP 1225
#define INFIDX 1226
#define INFSTAT 1227
#define LEFT_MARGIN 1228
#define PAGE_HEADER 1229
#define ROLLBACK_W 1230
#define SET_SESSION 1231
#define SQLSEOFF 1232
#define WITH_A_LOG 1233
#define BEFDISP 1234
#define BEFORE_MENU 1235
#define CREATE_VIEW 1236
#define DEFINE_TYPE 1237
#define DELETE_FROM 1238
#define END_DISPLAY 1239
#define END_REPORT 1240
#define END_FOREACH 1241
#define END_FOR 1242
#define END_GLOBALS 1243
#define EXIT_PROMPT 1244
#define EXTENT_SIZE 1245
#define FOREIGN_KEY 1246
#define HIDE_OPTION 1247
#define HIDE_WINDOW 1248
#define INSERT_INTO 1249
#define IS_NOT_NULL 1250
#define MOVE_WINDOW 1251
#define NEXT_OPTION 1252
#define NOT_MATCHES 1253
#define ON_LAST_ROW 1254
#define OPEN_WINDOW 1255
#define OPEN_STATUSBOX 1256
#define PAGE_LENGTH 1257
#define PAGE_WIDTH 1258
#define PRIMARY_KEY 1259
#define PROMPT_LINE 1260
#define RECORD_LIKE 1261
#define ROLLFORWARD 1262
#define SETBL 1263
#define SHOW_OPTION 1264
#define SHOW_WINDOW 1265
#define SQLSEON 1266
#define TO_DATABASE 1267
#define USE_SESSION 1268
#define WITH_NO_LOG 1269
#define AFTDISP 1270
#define BEFFIELD 1271
#define INSHARE 1272
#define UNLOCKTAB 1273
#define AFTFIELD 1274
#define ATTRIBUTES 1275
#define BEFINP 1276
#define BEGIN_WORK 1277
#define CLEARWIN 1278
#define CLOSE_FORM 1279
#define DEFER_QUIT 1280
#define DESCENDING 1281
#define DROP_INDEX 1282
#define END_PROMPT 1283
#define END_RECORD 1284
#define ERROR_LINE 1285
#define EXIT_INPUT 1286
#define EXIT_WHILE 1287
#define FOR_UPDATE_OF 1288
#define FOR_UPDATE 1289
#define GET_FLDBUF 1290
#define INITIALIZE 1291
#define INPUT_WRAP 1292
#define LOCK_TABLE 1293
#define MSG_LINE 1294
#define NOT_EXISTS 1295
#define ON_ANY_KEY 1296
#define REFERENCES 1297
#define RENCOL 1298
#define SET_CURSOR 1299
#define SMALLFLOAT 1300
#define SQLSUCCESS 1301
#define TOP_MARGIN 1302
#define WITH_ARRAY 1303
#define ACCEPTKEY 1304
#define ACCEPT 1305
#define AFTINP 1306
#define CLEARFORMTODEFAULTS 1307
#define CLEARFORM 1308
#define CLEAR_X_FORM 1309
#define COMMIT_W 1310
#define NEXTPAGE 1311
#define PREVPAGE 1312
#define CTRL_KEY 1313
#define INFTABS 1314
#define NEXTFIELD 1315
#define NEXTFORM 1316
#define RENTAB 1317
#define ASCENDING 1318
#define ASSOCIATE 1319
#define CHAR 1320
#define CONSTRUCT 1321
#define DELIMITER 1322
#define DOWNSHIFT 1323
#define DROP_VIEW 1324
#define END_INPUT 1325
#define END_WHILE 1326
#define EXCLUSIVE 1327
#define EXIT_CASE 1328
#define EXIT_MENU 1329
#define FORM_LINE 1330
#define INTERRUPT 1332
#define INTO_TEMP 1333
#define INVISIBLE 1334
#define IN_MEMORY 1335
#define LINKED_TO 1336
#define LOAD_FROM 1337
#define LOCKTAB 1338
#define MENU_LINE 1339
#define OPEN_FORM 1340
#define OTHERWISE 1341
#define PRECISION 1342
#define PRIOR 1343
#define PROCEDURE 1344
#define REPORT_TO 1345
#define RETURNING 1346
#define UNDERLINE 1347
#define UNLOAD_TO 1348
#define BEFROW 1349
#define UNLOAD_T 1350
#define VARIABLE 1351
#define ABSOLUTE 1352
#define AFTROW 1353
#define BUFFERED 1354
#define CONSTANT 1355
#define CONST 1356
#define CONTINUE 1357
#define DATABASE 1358
#define DATETIME 1359
#define DEFAULTS 1360
#define DISTINCT 1361
#define END_CASE 1362
#define END_MAIN 1363
#define END_MENU 1364
#define END_TYPE 1365
#define EXIT_FOR 1366
#define EXTERNAL 1367
#define FRACTION 1368
#define FUNCTION 1369
#define GROUP_BY 1370
#define INTERVAL 1371
#define KWMESSAGE 1372
#define NOT_LIKE 1373
#define NOT_ILIKE 1374
#define NOT_NULL 1375
#define PASSWORD 1376
#define PREVIOUS 1377
#define READONLY 1378
#define REGISTER 1379
#define RELATIVE 1380
#define RESOURCE 1381
#define SMALLINT 1382
#define VALIDATE 1383
#define WITH_LOG 1384
#define WORDWRAP 1385
#define BY_NAME 1386
#define IN_FILE 1387
#define IS_NULL 1388
#define AVERAGE 1390
#define BETWEEN 1391
#define CAPTION 1392
#define CLIPPED 1393
#define CLOSE_BRACKET 1394
#define COLUMNS 1395
#define COMMENT 1397
#define CONNECT 1398
#define CURRENT 1399
#define DBYNAME 1400
#define DECIMAL 1401
#define DECLARE 1402
#define DEFAULT 1403
#define DISPLAY 1404
#define ENDCODE 1405
#define EXECUTE 1406
#define FOREACH 1407
#define FOREIGN 1408
#define GLOBALS 1409
#define INFIELD 1410
#define INTEGER 1411
#define KWWINDOW 1412
#define MAGENTA 1413
#define NUMERIC 1415
#define OPTIONS 1416
#define PERCENT 1417
#define PREPARE 1418
#define PROGRAM 1419
#define RECOVER 1420
#define REVERSE 1421
#define SECTION 1422
#define SESSION 1423
#define SYNONYM 1424
#define THRU 1425
#define TRAILER 1426
#define UPSHIFT 1427
#define VARCHAR 1428
#define WAITING 1429
#define CLOSE_SHEV 1430
#define CLOSE_SQUARE 1431
#define KW_FALSE 1433
#define NOT_IN 1434
#define ONKEY 1435
#define OPEN_BRACKET 1436
#define BORDER 1437
#define BOTTOM 1438
#define COLUMN 1439
#define COMMIT 1440
#define CREATE 1441
#define CURSOR 1442
#define DEFINE 1443
#define DELETE 1444
#define DOUBLE 1445
#define END_IF 1446
#define ESCAPE 1447
#define EXISTS 1448
#define EXTEND 1449
#define EXTENT 1450
#define FINISH 1451
#define FORMAT 1452
#define HAVING 1453
#define HEADER 1454
#define INSERT 1455
#define LOCATE 1456
#define MARGIN 1457
#define MEMORY 1458
#define MINUTE 1459
#define MODIFY 1460
#define NORMAL 1461
#define EQUAL_EQUAL 1462
#define OPEN_SHEV 1464
#define OPEN_SQUARE 1465
#define OPTION 1466
#define OUTPUT 1467
#define PROMPT 1468
#define PUBLIC 1469
#define RECORD 1470
#define REPORT 1471
#define REVOKE 1472
#define SCHEMA 1473
#define SCROLL_USING 1474
#define SCROLL 1475
#define SECOND 1476
#define SELECT 1477
#define SERIAL 1478
#define SETL 1479
#define SHARED 1480
#define SPACES 1481
#define UNIQUE 1482
#define UNLOCK 1483
#define UPDATE 1484
#define VALUES 1485
#define YELLOW 1486
#define AFTER 1487
#define KWLINE 1488
#define KW_NULL 1489
#define KW_TRUE 1490
#define SINGLE_KEY 1491
#define ALTER 1492
#define ARRAY 1493
#define ASCII 1494
#define AUDIT 1495
#define BLACK 1496
#define BLINK 1497
#define CHECK 1498
#define CLEAR 1499
#define CLOSE 1500
#define CODE_C 1501
#define COUNT 1502
#define DEFER 1503
#define ERROR 1504
#define EVERY 1505
#define FETCH 1506
#define FIRST 1507
#define FLOAT 1508
#define FLUSH 1509
#define FOUND 1510
#define GRANT 1511
#define GREEN 1512
#define GROUP 1513
#define INDEX 1514
#define KWFORM 1515
#define LABEL 1516
#define LOCAL 1518
#define MONEY 1519
#define MONTH 1520
#define ORDER 1523
#define OUTER 1524
#define PAUSE 1525
#define PRINT_IMAGE 1526
#define PRINT_FILE 1527
#define PRINT 1528
#define RIGHT 1529
#define DOUBLE_COLON 1530
#define SEMICOLON 1531
#define SLEEP 1532
#define TUPLE 1533
#define UNION 1534
#define WHERE 1536
#define WHILE 1537
#define WHITE 1538
#define CCODE 1539
#define ANSI 1540
#define BLUE 1541
#define BOLD 1542
#define BYTE 1543
#define FCALL 1544
#define CASE 1545
#define CYAN 1546
#define DATE 1547
#define DESC 1548
#define KWDOWN 1550
#define TAB 1551
#define DROP 1552
#define ELSE 1553
#define EXEC 1554
#define EXIT 1555
#define FREE 1556
#define FROM 1557
#define GOTO 1558
#define HELP_FILE 1559
#define LANG_FILE 1560
#define HELP 1561
#define HIDE 1562
#define HOUR 1563
#define INTO 1564
#define LAST 1565
#define LEFT 1566
#define LIKE 1567
#define MAIN 1568
#define MENU 1569
#define MODE 1570
#define NEED 1571
#define NEXT 1572
#define NOCR 1573
#define OPEN 1574
#define QUIT 1575
#define REAL 1576
#define ROWS 1577
#define SHOW 1578
#define SIZE 1579
#define SKIP 1580
#define SOME 1581
#define STEP 1582
#define STOP 1583
#define TEMP 1584
#define TEXT 1585
#define THEN 1586
#define USER 1587
#define WAIT 1588
#define WHEN 1589
#define WITH 1590
#define WORK 1591
#define YEAR 1592
#define KW_IS 1594
#define XSET 1595
#define ADD 1596
#define ALL 1597
#define ANY 1599
#define ASC 1600
#define AVG 1601
#define COLON 1602
#define DAY 1604
#define DBA 1605
#define DEC 1606
#define DIM 1607
#define FKEY 1608
#define FOR 1609
#define KEY 1610
#define KWNO 1611
#define LET 1612
#define LOG 1613
#define XMAX 1614
#define XMIN 1615
#define PAD 1619
#define PUT 1620
#define RED 1621
#define ROW 1622
#define RUN 1623
#define SQL 1624
#define SUM 1625
#define TOP 1626
#define USE 1627
#define ATSIGN 1628
#define AS_TIFF 1630
#define AS_GIF 1631
#define AS_PNG 1632
#define AS_JPEG 1633
#define AS 1634
#define AT 1635
#define BY 1636
#define DOT 1637
#define GO 1638
#define IF 1639
#define IN 1640
#define OF 1641
#define ON 1642
#define TO 1644
#define KWUP 1645
#define FONT_NAME 1646
#define FONT_SIZE 1647
#define PAPER_SIZE_IS_LETTER 1648
#define PAPER_SIZE_IS_LEGAL 1649
#define PAPER_SIZE_IS_A5 1650
#define PAPER_SIZE_IS_A4 1651
#define PAPER_SIZE_IS_LETTER_L 1652
#define PAPER_SIZE_IS_LEGAL_L 1653
#define PAPER_SIZE_IS_A5_L 1654
#define PAPER_SIZE_IS_A4_L 1655
#define FORMHANDLER 1656
#define END_FORMHANDLER 1657
#define BEFORE_EVENT 1658
#define BEFORE_OPEN_FORM 1659
#define AFTER_EVENT 1660
#define BEFORE_CLOSE_FORM 1661
#define BEFORE_ANY 1662
#define AFTER_ANY 1663
#define MENUHANDLER 1664
#define END_MENUHANDLER 1665
#define BEFORE_SHOW_MENU 1666
#define DISABLE_PROGRAM 1667
#define DISABLE_ALL 1668
#define BUTTONS 1669
#define CHECK_MENUITEM 1670
#define DISABLE_FORM 1671
#define DISABLE_MENUITEMS 1672
#define DISABLE 1673
#define ENABLE_FORM 1674
#define ENABLE_MENUITEMS 1675
#define ENABLE 1676
#define KWFIELD 1677
#define ICON 1678
#define MESSAGEBOX 1679
#define TO_DEFAULTS 1680
#define UNCHECK_MENUITEM 1681
#define BEFORE 1682
#define INPUT 1683
#define END 1684
#define INT_TO_ID 1685
#define TIMEOUT 1686
#define OFF 1687
#define WITH_1_DIMENSION 1688
#define WITH_2_DIMENSION 1689
#define WITH_3_DIMENSION 1690
#define TILDE 1691
#define ILIKE 1692
#define FGL_ISDYNARR_ALLOCATED 1693
#define FGL_DYNARR_EXTENTSIZE 1694




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
#line 210 "fgl.yacc"
typedef union YYSTYPE {



	//char	str[3100];  /* This would core dump in CygWin on call to */
	char	str[1024];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;
	char *sql_string;
	struct generic_entry_list *list;
	struct generic_entry *entry;
	struct generic_entry_ident *ident;
	struct generic_entry_variable *variable;
	struct generic_entry_literal *literal;
	int 	integer_val;
	float 	float_val;
	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1663 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1675 "y.tab.c"

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10292

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  710
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  836
/* YYNRULES -- Number of rules. */
#define YYNRULES  2229
/* YYNRULES -- Number of states. */
#define YYNSTATES  3510

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1707

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
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,    15,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,    16,
     422,   423,   424,   425,   426,   427,    23,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,    10,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,    13,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,    17,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,    12,   545,   546,
     547,    11,    20,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,     8,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,    21,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,    14,   616,   617,   618,   619,     7,   620,
     621,   622,   623,     5,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,    19,    22,     9,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,    18,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,     6,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,     2,     3,     4,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33
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
     687,   689,   694,   699,   706,   708,   711,   713,   715,   717,
     719,   724,   731,   733,   738,   745,   747,   749,   751,   753,
     755,   757,   759,   762,   765,   767,   769,   774,   776,   778,
     779,   783,   787,   788,   791,   793,   795,   797,   799,   801,
     803,   806,   807,   810,   811,   815,   816,   820,   822,   823,
     827,   829,   831,   833,   835,   837,   839,   842,   844,   845,
     847,   848,   854,   856,   858,   860,   865,   870,   877,   879,
     881,   883,   885,   890,   897,   899,   904,   911,   913,   915,
     917,   919,   921,   924,   927,   929,   934,   935,   943,   944,
     957,   958,   963,   964,   970,   972,   976,   979,   981,   985,
     987,   988,   991,   994,   996,   999,  1005,  1010,  1013,  1018,
    1024,  1028,  1029,  1030,  1042,  1043,  1046,  1048,  1049,  1052,
    1054,  1056,  1059,  1060,  1064,  1065,  1069,  1070,  1074,  1077,
    1080,  1083,  1088,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1133,  1135,  1137,  1139,  1141,  1144,  1146,  1148,
    1150,  1153,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1179,  1181,  1184,  1186,  1188,  1190,  1194,
    1196,  1200,  1202,  1206,  1208,  1210,  1212,  1215,  1217,  1219,
    1223,  1228,  1233,  1236,  1239,  1241,  1243,  1245,  1247,  1249,
    1253,  1255,  1258,  1261,  1263,  1264,  1268,  1271,  1274,  1276,
    1280,  1285,  1290,  1296,  1302,  1304,  1306,  1309,  1312,  1317,
    1322,  1325,  1328,  1333,  1338,  1340,  1343,  1346,  1349,  1352,
    1355,  1358,  1361,  1364,  1367,  1370,  1373,  1376,  1379,  1382,
    1383,  1384,  1385,  1392,  1393,  1394,  1403,  1404,  1405,  1412,
    1413,  1414,  1421,  1422,  1423,  1430,  1431,  1432,  1439,  1445,
    1451,  1457,  1465,  1470,  1477,  1478,  1482,  1484,  1486,  1491,
    1496,  1501,  1506,  1511,  1516,  1518,  1520,  1522,  1524,  1529,
    1534,  1537,  1540,  1543,  1546,  1549,  1551,  1553,  1556,  1558,
    1560,  1562,  1565,  1570,  1577,  1584,  1588,  1594,  1600,  1604,
    1606,  1608,  1612,  1614,  1618,  1619,  1620,  1632,  1633,  1636,
    1637,  1638,  1639,  1649,  1650,  1654,  1655,  1656,  1667,  1668,
    1670,  1671,  1673,  1675,  1678,  1679,  1683,  1684,  1688,  1689,
    1691,  1693,  1696,  1697,  1701,  1702,  1706,  1710,  1712,  1717,
    1721,  1723,  1727,  1729,  1733,  1735,  1739,  1741,  1744,  1745,
    1749,  1750,  1754,  1755,  1760,  1761,  1766,  1767,  1772,  1775,
    1779,  1781,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,
    1803,  1805,  1807,  1812,  1819,  1824,  1828,  1835,  1839,  1846,
    1848,  1850,  1852,  1854,  1856,  1858,  1859,  1862,  1864,  1866,
    1868,  1873,  1875,  1877,  1879,  1884,  1888,  1895,  1899,  1906,
    1908,  1910,  1913,  1916,  1918,  1921,  1924,  1926,  1930,  1932,
    1935,  1938,  1941,  1946,  1949,  1952,  1957,  1958,  1967,  1968,
    1970,  1972,  1974,  1975,  1977,  1980,  1981,  1983,  1986,  1987,
    1989,  1992,  1993,  1995,  1999,  2000,  2003,  2004,  2005,  2014,
    2015,  2016,  2020,  2021,  2022,  2030,  2036,  2039,  2042,  2043,
    2049,  2054,  2056,  2060,  2064,  2068,  2069,  2072,  2074,  2075,
    2077,  2079,  2082,  2083,  2088,  2089,  2094,  2095,  2099,  2100,
    2104,  2105,  2109,  2110,  2114,  2115,  2119,  2120,  2124,  2125,
    2129,  2130,  2134,  2135,  2139,  2141,  2145,  2147,  2151,  2154,
    2159,  2161,  2163,  2165,  2166,  2171,  2177,  2184,  2185,  2196,
    2200,  2203,  2206,  2208,  2210,  2211,  2214,  2216,  2219,  2223,
    2227,  2231,  2235,  2237,  2239,  2241,  2243,  2244,  2248,  2250,
    2251,  2255,  2258,  2261,  2263,  2267,  2269,  2273,  2275,  2277,
    2279,  2281,  2283,  2285,  2287,  2289,  2291,  2293,  2295,  2297,
    2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,  2314,  2315,
    2323,  2325,  2327,  2330,  2333,  2336,  2340,  2345,  2346,  2350,
    2351,  2353,  2355,  2358,  2360,  2362,  2364,  2366,  2367,  2369,
    2371,  2374,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,
    2393,  2395,  2397,  2399,  2400,  2402,  2404,  2406,  2408,  2409,
    2410,  2411,  2412,  2426,  2428,  2429,  2430,  2437,  2440,  2442,
    2445,  2448,  2451,  2453,  2455,  2458,  2460,  2462,  2464,  2465,
    2469,  2472,  2474,  2475,  2476,  2477,  2492,  2493,  2499,  2501,
    2502,  2506,  2507,  2515,  2516,  2522,  2524,  2527,  2528,  2530,
    2532,  2534,  2535,  2537,  2539,  2542,  2545,  2548,  2550,  2552,
    2554,  2556,  2560,  2562,  2564,  2565,  2566,  2574,  2576,  2579,
    2580,  2584,  2585,  2590,  2593,  2594,  2597,  2599,  2601,  2603,
    2605,  2607,  2609,  2611,  2615,  2616,  2618,  2620,  2622,  2624,
    2627,  2630,  2633,  2639,  2648,  2650,  2652,  2654,  2659,  2664,
    2666,  2668,  2670,  2672,  2675,  2678,  2682,  2689,  2691,  2695,
    2697,  2699,  2701,  2705,  2712,  2722,  2724,  2726,  2728,  2730,
    2733,  2734,  2736,  2738,  2742,  2744,  2748,  2750,  2754,  2756,
    2760,  2762,  2764,  2766,  2768,  2772,  2774,  2778,  2780,  2784,
    2786,  2788,  2790,  2794,  2797,  2798,  2800,  2802,  2807,  2809,
    2813,  2815,  2819,  2827,  2828,  2836,  2837,  2844,  2848,  2850,
    2854,  2856,  2859,  2865,  2866,  2874,  2875,  2878,  2879,  2881,
    2887,  2890,  2896,  2897,  2903,  2910,  2915,  2916,  2918,  2920,
    2925,  2926,  2929,  2930,  2936,  2941,  2944,  2946,  2950,  2953,
    2956,  2959,  2962,  2965,  2968,  2970,  2973,  2976,  2979,  2982,
    2985,  2988,  2991,  2994,  2997,  2999,  3001,  3003,  3005,  3007,
    3009,  3015,  3017,  3019,  3022,  3027,  3030,  3032,  3033,  3045,
    3046,  3049,  3055,  3056,  3058,  3059,  3062,  3064,  3067,  3068,
    3072,  3074,  3075,  3080,  3081,  3084,  3086,  3090,  3092,  3094,
    3098,  3103,  3108,  3111,  3113,  3115,  3117,  3118,  3120,  3128,
    3131,  3134,  3137,  3140,  3143,  3145,  3148,  3149,  3153,  3154,
    3158,  3159,  3163,  3164,  3168,  3169,  3173,  3174,  3179,  3180,
    3185,  3187,  3189,  3191,  3193,  3195,  3197,  3198,  3203,  3204,
    3206,  3207,  3212,  3214,  3217,  3220,  3223,  3224,  3226,  3228,
    3231,  3234,  3235,  3238,  3242,  3246,  3252,  3253,  3256,  3261,
    3263,  3265,  3267,  3269,  3271,  3272,  3274,  3276,  3280,  3283,
    3289,  3292,  3298,  3304,  3310,  3316,  3322,  3328,  3329,  3332,
    3334,  3337,  3340,  3343,  3346,  3349,  3352,  3354,  3357,  3360,
    3363,  3366,  3368,  3371,  3374,  3377,  3380,  3382,  3384,  3386,
    3387,  3390,  3393,  3396,  3399,  3402,  3405,  3408,  3411,  3414,
    3416,  3418,  3420,  3422,  3424,  3426,  3428,  3430,  3433,  3436,
    3439,  3442,  3445,  3447,  3449,  3451,  3452,  3456,  3459,  3460,
    3461,  3462,  3463,  3464,  3465,  3481,  3482,  3485,  3488,  3489,
    3491,  3492,  3493,  3494,  3495,  3496,  3497,  3513,  3516,  3517,
    3518,  3519,  3530,  3531,  3533,  3537,  3541,  3544,  3549,  3553,
    3557,  3561,  3563,  3565,  3567,  3569,  3571,  3573,  3574,  3575,
    3583,  3584,  3585,  3594,  3602,  3605,  3606,  3608,  3610,  3614,
    3617,  3620,  3622,  3624,  3628,  3630,  3632,  3635,  3637,  3641,
    3643,  3647,  3649,  3651,  3653,  3655,  3657,  3659,  3661,  3664,
    3669,  3671,  3675,  3677,  3681,  3684,  3689,  3691,  3695,  3697,
    3700,  3705,  3707,  3711,  3713,  3715,  3717,  3720,  3723,  3728,
    3731,  3736,  3738,  3742,  3744,  3746,  3748,  3751,  3753,  3755,
    3757,  3759,  3761,  3764,  3771,  3778,  3779,  3781,  3782,  3784,
    3787,  3789,  3790,  3796,  3797,  3803,  3805,  3806,  3810,  3812,
    3816,  3818,  3822,  3824,  3826,  3827,  3828,  3834,  3836,  3839,
    3841,  3842,  3843,  3847,  3848,  3849,  3853,  3855,  3857,  3859,
    3861,  3863,  3865,  3868,  3871,  3876,  3880,  3884,  3886,  3890,
    3893,  3895,  3897,  3898,  3900,  3902,  3904,  3906,  3907,  3909,
    3913,  3915,  3919,  3921,  3922,  3926,  3928,  3930,  3932,  3934,
    3936,  3938,  3940,  3942,  3944,  3946,  3948,  3950,  3958,  3959,
    3961,  3963,  3965,  3967,  3971,  3973,  3975,  3977,  3980,  3981,
    3985,  3987,  3991,  3993,  3997,  3999,  4001,  4008,  4009,  4013,
    4015,  4019,  4020,  4022,  4027,  4033,  4036,  4038,  4040,  4045,
    4047,  4051,  4056,  4061,  4063,  4067,  4069,  4071,  4073,  4076,
    4078,  4083,  4084,  4086,  4087,  4089,  4091,  4094,  4096,  4098,
    4100,  4102,  4107,  4111,  4113,  4115,  4117,  4120,  4122,  4124,
    4127,  4130,  4132,  4136,  4139,  4142,  4144,  4148,  4150,  4153,
    4158,  4160,  4163,  4165,  4169,  4174,  4175,  4177,  4178,  4180,
    4181,  4183,  4185,  4189,  4191,  4195,  4197,  4200,  4202,  4206,
    4209,  4212,  4213,  4216,  4218,  4220,  4226,  4230,  4236,  4240,
    4242,  4246,  4248,  4250,  4251,  4253,  4257,  4261,  4265,  4272,
    4277,  4282,  4287,  4292,  4298,  4300,  4302,  4304,  4306,  4308,
    4310,  4312,  4314,  4316,  4318,  4320,  4322,  4323,  4325,  4327,
    4329,  4331,  4333,  4335,  4337,  4342,  4348,  4350,  4356,  4362,
    4364,  4366,  4368,  4373,  4375,  4380,  4382,  4390,  4392,  4394,
    4396,  4401,  4408,  4409,  4412,  4417,  4419,  4421,  4423,  4425,
    4427,  4429,  4431,  4435,  4437,  4439,  4443,  4445,  4446,  4450,
    4456,  4458,  4461,  4464,  4469,  4473,  4475,  4477,  4479,  4481,
    4483,  4485,  4488,  4491,  4492,  4496,  4497,  4501,  4503,  4505,
    4507,  4509,  4511,  4513,  4515,  4520,  4522,  4524,  4526,  4528,
    4530,  4532,  4534,  4539,  4541,  4543,  4545,  4547,  4549,  4551,
    4553,  4555,  4557,  4559,  4561,  4563,  4565,  4567,  4572,  4574,
    4578,  4580,  4584,  4585,  4593,  4594,  4603,  4604,  4611,  4612,
    4621,  4622,  4624,  4627,  4629,  4633,  4635,  4639,  4645,  4647,
    4649,  4651,  4653,  4655,  4656,  4657,  4667,  4673,  4675,  4677,
    4684,  4685,  4689,  4691,  4695,  4700,  4702,  4703,  4706,  4711,
    4718,  4719,  4721,  4723,  4725,  4727,  4731,  4733,  4736,  4738,
    4740,  4743,  4746,  4748,  4750,  4752,  4755,  4760,  4764,  4767,
    4771,  4775,  4779,  4781,  4783,  4785,  4787,  4789,  4791,  4797,
    4803,  4809,  4815,  4821,  4826,  4831,  4835,  4840,  4842,  4846,
    4848,  4854,  4862,  4868,  4869,  4872,  4874,  4876,  4877,  4881,
    4883,  4887,  4889,  4891,  4893,  4894,  4898,  4900,  4902,  4904,
    4906,  4911,  4918,  4920,  4922,  4925,  4929,  4931,  4933,  4935,
    4937,  4939,  4941,  4943,  4945,  4951,  4957,  4962,  4963,  4968,
    4970,  4973,  4975,  4977,  4979,  4981,  4983,  4985,  4987,  4989,
    4991,  4993,  4995,  4997,  4999,  5001,  5003,  5005,  5007,  5009,
    5011,  5013,  5015,  5017,  5019,  5021,  5023,  5025,  5027,  5029,
    5031,  5033,  5035,  5037,  5039,  5041,  5043,  5045,  5047,  5049,
    5051,  5053,  5055,  5057,  5059,  5061,  5063,  5065,  5067,  5069,
    5071,  5073,  5075,  5077,  5079,  5081,  5083,  5085,  5087,  5089,
    5091,  5093,  5095,  5097,  5099,  5101,  5103,  5105,  5107,  5109,
    5111,  5113,  5115,  5117,  5119,  5121,  5123,  5125,  5127,  5129,
    5131,  5133,  5135,  5137,  5139,  5141,  5143,  5145,  5147,  5149,
    5151,  5153,  5155,  5157,  5159,  5161,  5163,  5165,  5167,  5169,
    5171,  5173,  5175,  5177,  5179,  5181,  5183,  5185,  5187,  5189,
    5191,  5193,  5195,  5197,  5199,  5201,  5203,  5205,  5207,  5209,
    5211,  5213,  5215,  5217,  5219,  5221,  5223,  5225,  5227,  5229,
    5231,  5233,  5235,  5237,  5239,  5241,  5243,  5245,  5247,  5249,
    5251,  5253,  5255,  5257,  5259,  5261,  5263,  5265,  5267,  5269,
    5271,  5273,  5275,  5277,  5279,  5281,  5283,  5285,  5287,  5289,
    5291,  5293,  5295,  5297,  5299,  5301,  5303,  5305,  5307,  5309,
    5311,  5313,  5315,  5317,  5319,  5321,  5323,  5325,  5327,  5329,
    5331,  5333,  5335,  5337,  5339,  5341,  5343,  5345,  5347,  5349,
    5351,  5353,  5355,  5357,  5359,  5361,  5363,  5365,  5367,  5369,
    5371,  5373,  5375,  5377,  5379,  5381,  5383,  5385,  5387,  5389,
    5391,  5393,  5395,  5397,  5399,  5401,  5403,  5405,  5407,  5409,
    5411,  5413,  5415,  5417,  5419,  5421,  5423,  5425,  5427,  5429,
    5431,  5433,  5435,  5437,  5439,  5441,  5443,  5445,  5447,  5449,
    5451,  5453,  5455,  5457,  5459,  5461,  5463,  5465,  5467,  5469,
    5471,  5473,  5475,  5477,  5479,  5481,  5483,  5485,  5487,  5489,
    5491,  5493,  5495,  5497,  5499,  5501,  5503,  5505,  5507,  5509,
    5511,  5513,  5515,  5517,  5519,  5521,  5523,  5525,  5527,  5529,
    5531,  5533,  5535,  5537,  5539,  5541,  5543,  5545,  5547,  5549,
    5551,  5553,  5555,  5557,  5559,  5561,  5563,  5565,  5567,  5569,
    5571,  5573,  5575,  5577,  5579,  5581,  5583,  5585,  5587,  5589,
    5591,  5593,  5595,  5597,  5599,  5601,  5603,  5605,  5607,  5609,
    5611,  5613,  5614,  5618,  5619,  5623,  5624,  5625,  5632,  5633,
    5636,  5639,  5647,  5651,  5655,  5658,  5661,  5664,  5666,  5670,
    5672,  5676,  5678,  5682,  5684,  5688,  5690,  5692,  5694,  5697,
    5700,  5702,  5704,  5707,  5712,  5714,  5716,  5718,  5720,  5722,
    5724,  5728,  5731,  5735,  5739,  5743,  5749,  5755,  5761,  5767,
    5773,  5778,  5783,  5787,  5792,  5794,  5796,  5800,  5801,  5807,
    5809,  5813,  5817,  5821,  5823,  5826,  5828,  5830,  5832,  5836,
    5842,  5844,  5846,  5848,  5850,  5854,  5855,  5856,  5863,  5864,
    5867,  5868,  5870,  5872,  5875,  5878,  5880,  5882,  5887,  5891,
    5893,  5897,  5899,  5902,  5908,  5911,  5914,  5920,  5921,  5924,
    5926,  5928,  5931,  5938,  5945,  5947,  5948,  5950,  5953,  5955,
    5958,  5959,  5962,  5964,  5966,  5968,  5970,  5972,  5974,  5976,
    5978,  5980,  5982,  5984,  5986,  5988,  5990,  5992,  5994,  5996,
    5998,  6000,  6002,  6004,  6006,  6008,  6010,  6012,  6014,  6016,
    6018,  6020,  6022,  6024,  6026,  6028,  6030,  6032,  6034,  6036,
    6038,  6040,  6042,  6044,  6046,  6048,  6050,  6052,  6054,  6056,
    6058,  6060,  6062,  6064,  6066,  6068,  6070,  6072,  6074,  6076,
    6078,  6080,  6082,  6084,  6086,  6088,  6090,  6092,  6094,  6096,
    6098,  6100,  6102,  6104,  6106,  6108,  6110,  6112,  6114,  6116,
    6118,  6120,  6122,  6124,  6126,  6128,  6130,  6132,  6134,  6136
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1074,     0,    -1,   235,    -1,   232,    -1,   165,   715,   461,
     629,   716,    -1,   176,    -1,  1139,    -1,    26,    -1,   717,
      -1,   716,     5,   717,    -1,   985,    -1,   465,   718,   426,
      -1,   718,   719,   718,    -1,    26,    -1,   720,    26,    -1,
    1139,    -1,   927,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   722,
      -1,    -1,   309,   465,   723,   724,   426,    -1,   602,   465,
      26,     5,    26,   426,    -1,   725,    -1,   724,     5,   725,
      -1,   524,    -1,   565,    -1,   570,    -1,   540,    -1,   444,
      -1,   638,    -1,   562,    -1,   514,    -1,   451,    -1,   525,
      -1,   380,    -1,   566,    -1,   490,    -1,   367,    -1,   627,
      -1,   133,    -1,  1053,    -1,    -1,   727,    -1,    -1,   309,
     465,   728,   729,   426,    -1,   730,    -1,   729,     5,   730,
      -1,   725,    -1,   466,    -1,   636,    25,    -1,   238,   972,
      -1,   364,   972,    -1,   319,   972,    -1,   372,   972,    -1,
     328,   972,    -1,   294,   972,    -1,   568,   732,    -1,   916,
     379,  1139,    -1,    -1,   324,   465,  1530,   426,   379,   733,
    1158,    -1,   139,   465,   985,     5,    25,     5,    25,   426,
      -1,   441,   465,   977,   426,   379,  1139,    -1,  1277,    -1,
     227,   465,   935,   426,   379,  1139,    -1,    -1,    -1,  1139,
     623,   985,   465,   734,   748,   426,   735,   746,    -1,    -1,
      -1,    -1,   985,   465,   736,   748,   737,   426,   738,   746,
      -1,    -1,    -1,   508,  1475,   656,  1475,   465,   739,   748,
     740,   426,   746,    -1,    -1,    -1,   985,   555,   985,   465,
     741,   748,   742,   426,   746,    -1,    -1,    -1,    -1,   400,
     751,   623,   752,   493,   715,   461,   465,   743,   748,   744,
     426,   745,   747,    -1,    -1,   379,  1158,    -1,    -1,   379,
    1158,    -1,   198,    -1,    -1,   749,    -1,   750,    -1,   749,
       5,   750,    -1,   885,    -1,    25,    -1,   985,    -1,   985,
      -1,   985,   653,   985,    -1,    -1,   569,   892,   754,   757,
     761,   758,    -1,    -1,   569,   755,   756,   759,   758,    -1,
     763,    -1,   756,   763,    -1,   765,    -1,   757,   765,    -1,
     395,    -1,    -1,    -1,   374,   760,  1540,    -1,    -1,    -1,
     374,   762,  1540,    -1,    -1,   612,   892,   764,  1540,    -1,
      -1,   612,   892,   766,  1540,    -1,   313,   982,    -1,   237,
     980,    -1,   118,   980,    -1,   203,    -1,   220,  1481,    -1,
     528,   979,    -1,    30,   769,    31,    -1,   770,    -1,   772,
      -1,   771,    -1,   770,   771,    -1,    29,    -1,   773,    -1,
     772,   773,    -1,    28,    -1,   428,    -1,    -1,    -1,   355,
     776,   778,   777,   779,    -1,   419,  1139,   658,   780,  1027,
    1052,   721,    -1,  1139,   658,   780,  1027,   580,  1530,  1052,
     721,    -1,    -1,   782,   226,    -1,   781,    -1,   780,     5,
     781,    -1,   985,    -1,   985,   653,   985,    -1,   985,   653,
      20,    -1,   783,    -1,   782,   783,    -1,    -1,   305,   789,
     784,  1540,    -1,    -1,   308,   790,   785,  1540,    -1,    -1,
    1055,   786,  1540,    -1,    -1,   201,   787,  1540,    -1,    -1,
     199,   788,  1540,    -1,   989,    -1,   789,     5,   989,    -1,
     989,    -1,   790,     5,   989,    -1,   127,    -1,   128,    -1,
     129,    -1,   130,    -1,   131,    -1,   132,    -1,   465,   885,
     793,   426,    -1,    -1,     5,   836,   659,   839,    -1,   191,
      -1,   314,    -1,    -1,   796,    -1,   797,    -1,   796,   797,
      -1,    -1,    -1,   472,   798,   800,   799,  1246,    -1,   849,
      -1,   803,    -1,   800,     5,   803,    -1,    -1,   802,   985,
      -1,   388,   801,   848,    25,    -1,   388,   801,   848,   985,
      -1,   388,   801,   848,   991,    -1,   388,   801,   848,    26,
      -1,   807,   825,    -1,    -1,   801,   388,   804,   805,    -1,
      26,    -1,    25,    -1,   991,    -1,    19,    26,    -1,   801,
      -1,   806,    -1,   807,     5,   806,    -1,    -1,   354,    -1,
      -1,   703,    -1,   704,    -1,   705,    -1,    -1,   521,   493,
     817,   461,   811,   657,   825,    -1,    -1,    34,   809,   812,
     657,   825,    -1,    -1,   353,   808,   814,    26,   815,   337,
     493,   816,   461,   813,   657,   825,    -1,   465,    -1,   492,
      -1,   426,    -1,   460,    -1,    26,    -1,   818,     5,   818,
       5,   818,    -1,   818,     5,   818,    -1,   818,    -1,    26,
      -1,    -1,   498,   820,   800,   318,    -1,    -1,   295,   821,
     801,   653,    20,    -1,    -1,   369,   822,   801,   293,   465,
     823,   426,    -1,   824,    -1,   823,     5,   824,    -1,   801,
      -1,   827,    -1,    -1,    93,    -1,    -1,    -1,   828,   830,
     829,   826,    -1,   810,    -1,   819,    -1,   354,    -1,   354,
     465,    26,   426,    -1,   458,   465,    26,   426,    -1,   458,
     465,    26,     5,    26,   426,    -1,   442,    -1,   650,   801,
      -1,   415,    -1,   543,    -1,   124,    -1,   432,    -1,   432,
     465,    26,   426,    -1,   432,   465,    26,     5,    26,   426,
      -1,   546,    -1,   546,   465,    26,   426,    -1,   546,   465,
      26,     5,    26,   426,    -1,   536,    -1,   334,    -1,   571,
      -1,   567,    -1,   114,    -1,   115,    -1,   608,    -1,   392,
     834,    -1,   404,   835,    -1,   831,    -1,    32,    -1,   590,
     832,   653,   833,    -1,   801,    -1,   801,    -1,    -1,   836,
     659,   839,    -1,   844,   659,   847,    -1,    -1,   837,   838,
      -1,   615,    -1,   547,    -1,   624,    -1,   586,    -1,   488,
      -1,   504,    -1,   401,   841,    -1,    -1,   840,   838,    -1,
      -1,   465,   843,   426,    -1,    -1,   465,    26,   426,    -1,
      26,    -1,    -1,   845,   846,   842,    -1,   615,    -1,   547,
      -1,   624,    -1,   586,    -1,   488,    -1,   504,    -1,   401,
     841,    -1,   846,    -1,    -1,    14,    -1,    -1,   271,   985,
     850,   650,   851,    -1,   853,    -1,   856,    -1,   354,    -1,
     354,   465,    26,   426,    -1,   458,   465,    26,   426,    -1,
     458,   465,    26,     5,    26,   426,    -1,   442,    -1,   415,
      -1,   543,    -1,   432,    -1,   432,   465,    26,   426,    -1,
     432,   465,    26,     5,    26,   426,    -1,   546,    -1,   546,
     465,    26,   426,    -1,   546,   465,    26,     5,    26,   426,
      -1,   536,    -1,   334,    -1,   571,    -1,   567,    -1,   608,
      -1,   392,   834,    -1,   404,   835,    -1,   852,    -1,   590,
     832,   653,   833,    -1,    -1,   521,   493,   817,   461,   854,
     657,   851,    -1,    -1,   353,   808,   814,    26,   815,   337,
     493,   816,   461,   855,   657,   851,    -1,    -1,   498,   857,
     859,   318,    -1,    -1,   295,   858,   985,   653,    20,    -1,
     860,    -1,   859,     5,   860,    -1,   861,   851,    -1,   862,
      -1,   861,     5,   862,    -1,   985,    -1,    -1,   651,   976,
      -1,   105,   985,    -1,   103,    -1,   659,  1530,    -1,   659,
     543,   985,   692,  1530,    -1,   659,   543,   985,   424,    -1,
     107,   985,    -1,   192,   910,  1158,   871,    -1,   435,   910,
     890,   863,   871,    -1,   244,   982,   871,    -1,    -1,    -1,
     223,   868,  1165,   659,   985,   653,    20,   870,   721,   869,
     872,    -1,    -1,   502,   977,    -1,   721,    -1,    -1,   873,
     273,    -1,   273,    -1,   874,    -1,   873,   874,    -1,    -1,
     386,   875,  1540,    -1,    -1,   382,   876,  1540,    -1,    -1,
    1055,   877,  1540,    -1,    36,  1139,    -1,    37,  1139,    -1,
      35,  1139,    -1,   532,   910,   891,   721,    -1,   532,   910,
     891,   721,   100,    -1,   321,    -1,   320,    -1,   247,    -1,
     399,    -1,   208,    -1,   246,    -1,   363,    -1,   362,    -1,
     278,    -1,   205,    -1,   204,    -1,   182,    -1,   239,    -1,
     166,    -1,   181,    -1,   222,    -1,   189,    -1,   248,    -1,
     248,   892,    -1,   895,    -1,   894,    -1,   899,    -1,   927,
      -1,   885,   886,    -1,   928,    -1,   930,    -1,   896,    -1,
      19,   885,    -1,    18,   885,    -1,   901,    -1,   909,    -1,
     903,    -1,   509,    -1,   791,    -1,   904,    -1,   905,    -1,
     906,    -1,   907,    -1,   908,    -1,    39,   885,    -1,   910,
      -1,   910,   889,    -1,   892,    -1,   517,    -1,   888,    -1,
     889,     5,   888,    -1,   892,    -1,   890,     5,   892,    -1,
     892,    -1,   891,     5,   892,    -1,   885,    -1,    18,    -1,
      19,    -1,     9,   885,    -1,   518,    -1,   462,    -1,   465,
     885,   426,    -1,   477,   465,  1455,   426,    -1,   329,   465,
    1455,   426,    -1,   893,   991,    -1,   893,    26,    -1,    25,
      -1,   991,    -1,    26,    -1,   898,    -1,  1139,    -1,  1139,
     455,  1139,    -1,   897,    -1,   468,   885,    -1,   427,   885,
      -1,  1249,    -1,    -1,   541,   900,  1249,    -1,     7,   885,
      -1,     6,   885,    -1,   885,    -1,   902,     5,   885,    -1,
     656,   465,  1455,   426,    -1,   463,   465,  1455,   426,    -1,
     656,   465,   910,   902,   426,    -1,   463,   465,   910,   902,
     426,    -1,   421,    -1,   284,    -1,    10,   885,    -1,   287,
     885,    -1,    10,   885,   476,    25,    -1,   287,   885,   476,
      25,    -1,   590,   885,    -1,   406,   885,    -1,   590,   885,
     476,    25,    -1,   406,   885,   476,    25,    -1,   425,    -1,
       8,   885,    -1,    18,   885,    -1,    19,   885,    -1,    20,
     885,    -1,    21,   885,    -1,    22,   885,    -1,    11,   885,
      -1,    14,   885,    -1,   491,   885,    -1,    12,   885,    -1,
      13,   885,    -1,    17,   885,    -1,    16,   885,    -1,    15,
     885,    -1,    -1,    -1,    -1,   985,   465,   912,   748,   913,
     426,    -1,    -1,    -1,   985,   555,   985,   465,   914,   748,
     915,   426,    -1,    -1,    -1,   571,   465,   917,   885,   918,
     426,    -1,    -1,    -1,   547,   465,   919,   885,   920,   426,
      -1,    -1,    -1,   624,   465,   921,   885,   922,   426,    -1,
      -1,    -1,   615,   465,   923,   885,   924,   426,    -1,   404,
     465,   931,   426,   926,    -1,   392,   465,    25,   426,   925,
      -1,   392,   465,    26,   426,   925,    -1,   392,   465,    26,
     623,    26,   426,   925,    -1,   708,   465,  1139,   426,    -1,
     709,   465,  1139,     5,    26,   426,    -1,    -1,  1435,   659,
    1436,    -1,   835,    -1,   916,    -1,   324,   465,  1530,   426,
      -1,   134,   465,   977,   426,    -1,   106,   465,   977,   426,
      -1,   441,   465,  1530,   426,    -1,   227,   465,  1530,   426,
      -1,    94,   465,  1530,   426,    -1,   929,    -1,   911,    -1,
    1431,    -1,   571,    -1,   457,   465,   885,   426,    -1,   357,
     465,   885,   426,    -1,   522,   885,    -1,   478,   792,    -1,
     885,   143,    -1,   885,   144,    -1,   885,   145,    -1,    25,
      -1,   932,    -1,    19,   932,    -1,   934,    -1,   933,    -1,
      26,    -1,    26,    26,    -1,    26,    26,   623,    26,    -1,
      26,    26,   623,    26,   623,    26,    -1,    26,    26,   623,
      26,   623,    24,    -1,    26,   623,    26,    -1,    26,   623,
      26,   623,    26,    -1,    26,   623,    26,   623,    24,    -1,
      26,   623,    24,    -1,    24,    -1,    26,    -1,    26,    19,
      26,    -1,   977,    -1,   935,     5,   977,    -1,    -1,    -1,
     629,  1139,    14,   892,   659,   892,   939,   937,  1540,   938,
     276,    -1,    -1,   605,   892,    -1,    -1,    -1,    -1,   438,
     941,   979,   942,   944,  1336,   943,  1540,   275,    -1,    -1,
       8,   910,   890,    -1,    -1,    -1,   671,   985,   946,   795,
     947,  1084,   949,   948,   954,   672,    -1,    -1,   959,    -1,
      -1,   950,    -1,   951,    -1,   950,   951,    -1,    -1,   673,
     952,  1540,    -1,    -1,   674,   953,  1540,    -1,    -1,   955,
      -1,   956,    -1,   955,   956,    -1,    -1,   675,   957,  1540,
      -1,    -1,   676,   958,  1540,    -1,   960,   964,   359,    -1,
     126,    -1,   126,   961,   580,   962,    -1,   126,   419,   963,
      -1,  1139,    -1,   961,     5,  1139,    -1,   985,    -1,   962,
       5,   985,    -1,  1139,    -1,   963,     5,  1139,    -1,   965,
      -1,   964,   965,    -1,    -1,   677,   966,  1540,    -1,    -1,
     678,   967,  1540,    -1,    -1,   697,   962,   968,  1540,    -1,
      -1,   515,   962,   969,  1540,    -1,    -1,   658,   962,   970,
    1540,    -1,   579,   978,    -1,   588,    19,    26,    -1,   588,
      -1,   535,    18,    26,    -1,   535,    -1,    26,    -1,  1139,
      -1,   702,    -1,    25,    -1,   990,    -1,   892,    -1,   974,
       5,   974,    -1,   975,    -1,   985,    -1,   700,   465,   985,
     426,    -1,   985,   653,   700,   465,   985,   426,    -1,   985,
     493,   718,   461,    -1,   985,   653,    20,    -1,   985,   493,
     718,   461,   653,    20,    -1,   985,   653,   985,    -1,   985,
     493,   718,   461,   653,   985,    -1,   986,    -1,   986,    -1,
     986,    -1,   986,    -1,   986,    -1,   986,    -1,    -1,   584,
      26,    -1,  1539,    -1,   987,    -1,  1539,    -1,   384,   465,
     988,   426,    -1,  1142,    -1,    25,    -1,   985,    -1,   985,
     493,   718,   461,    -1,   985,   653,    20,    -1,   985,   493,
     718,   461,   653,    20,    -1,   985,   653,   985,    -1,   985,
     493,   718,   461,   653,   985,    -1,  1139,    -1,    24,    -1,
     653,    26,    -1,   581,   993,    -1,   985,    -1,   623,   985,
      -1,   685,   995,    -1,   996,    -1,   995,     5,   996,    -1,
     985,    -1,   696,   995,    -1,   687,   995,    -1,   688,  1530,
      -1,   686,   982,   692,  1530,    -1,   690,   995,    -1,   691,
    1530,    -1,   689,   982,   692,  1530,    -1,    -1,   694,  1001,
     890,  1006,  1008,  1010,  1002,  1004,    -1,    -1,  1003,    -1,
     682,    -1,   683,    -1,    -1,  1005,    -1,   379,  1139,    -1,
      -1,  1007,    -1,   424,   890,    -1,    -1,  1009,    -1,   693,
      26,    -1,    -1,  1011,    -1,   684,    26,  1012,    -1,    -1,
     434,    26,    -1,    -1,    -1,   655,   892,   609,  1014,  1540,
    1015,  1016,   475,    -1,    -1,    -1,   576,  1017,  1540,    -1,
      -1,    -1,    97,  1018,   892,   609,  1019,  1540,  1016,    -1,
     141,   985,   465,    26,   426,    -1,    90,   985,    -1,   110,
     985,    -1,    -1,   325,  1170,  1023,   659,   517,    -1,   325,
    1170,   590,  1024,    -1,  1025,    -1,  1024,     5,  1025,    -1,
     832,   653,  1427,    -1,   832,   653,    20,    -1,    -1,  1028,
     359,    -1,   359,    -1,    -1,   186,    -1,  1029,    -1,  1028,
    1029,    -1,    -1,   305,  1041,  1030,  1540,    -1,    -1,   308,
    1042,  1031,  1540,    -1,    -1,   386,  1032,  1540,    -1,    -1,
     382,  1033,  1540,    -1,    -1,  1055,  1034,  1540,    -1,    -1,
     340,  1035,  1540,    -1,    -1,   310,  1036,  1540,    -1,    -1,
      40,  1037,  1540,    -1,    -1,    38,  1038,  1540,    -1,    -1,
      42,  1039,  1540,    -1,    -1,    41,  1040,  1540,    -1,   977,
      -1,  1041,     5,   977,    -1,   977,    -1,  1042,     5,   977,
      -1,   349,  1045,    -1,   350,   985,   692,  1045,    -1,   595,
      -1,   410,    -1,   977,    -1,    -1,   698,  1048,  1047,  1026,
      -1,   419,  1158,  1027,   984,   721,    -1,  1158,  1027,   580,
    1530,   984,   721,    -1,    -1,   521,  1165,  1027,   580,   985,
     653,    20,   984,  1049,   721,    -1,   503,  1530,  1051,    -1,
     116,    26,    -1,   117,    26,    -1,   660,    -1,   573,    -1,
      -1,   584,    26,    -1,  1054,    -1,    48,    25,    -1,   530,
      14,    26,    -1,   530,    14,  1139,    -1,    49,    14,    26,
      -1,    49,    14,  1139,    -1,    45,    -1,    47,    -1,    44,
      -1,    46,    -1,    -1,   464,  1056,  1061,    -1,   330,    -1,
      -1,   630,  1058,  1061,    -1,   338,  1063,    -1,   630,  1061,
      -1,  1063,    -1,   465,  1062,   426,    -1,  1063,    -1,  1062,
       5,  1063,    -1,  1064,    -1,   628,    -1,   347,    -1,   365,
      -1,   339,    -1,   519,    -1,   476,    -1,   660,    -1,   584,
      -1,   573,    -1,   212,    -1,   473,    -1,   484,    -1,   574,
      -1,   589,    -1,   554,    -1,   345,    -1,   346,    -1,    25,
      -1,   544,    -1,    -1,    -1,   632,  1067,  1163,  1068,    14,
     910,  1069,    -1,   517,    -1,   891,    -1,   254,  1139,    -1,
     243,  1139,    -1,   257,  1139,    -1,   485,  1139,   368,    -1,
     485,  1139,   420,   973,    -1,    -1,  1076,  1075,  1079,    -1,
      -1,  1077,    -1,  1078,    -1,  1077,  1078,    -1,  1021,    -1,
    1083,    -1,  1099,    -1,  1085,    -1,    -1,  1080,    -1,  1082,
      -1,  1080,  1082,    -1,   101,   985,    -1,  1087,    -1,  1093,
      -1,  1105,    -1,  1259,    -1,  1269,    -1,  1126,    -1,   945,
      -1,   768,    -1,  1020,    -1,   774,    -1,   768,    -1,    -1,
     768,    -1,   796,    -1,   402,    -1,    95,    -1,    -1,    -1,
      -1,    -1,  1086,  1088,   985,   465,  1089,  1156,   426,  1090,
     795,  1091,  1084,  1540,  1092,    -1,   245,    -1,    -1,    -1,
     591,  1094,   795,  1095,  1540,   396,    -1,   212,   887,    -1,
     910,    -1,   910,   890,    -1,   391,  1439,    -1,   501,  1439,
      -1,  1100,    -1,  1101,    -1,  1100,  1101,    -1,  1102,    -1,
    1083,    -1,  1098,    -1,    -1,   440,  1103,  1104,    -1,   795,
     277,    -1,   973,    -1,    -1,    -1,    -1,   148,   985,   147,
     985,   465,  1106,  1156,   426,  1107,   795,  1108,  1084,  1540,
    1092,    -1,    -1,   592,  1110,  1125,  1116,  1111,    -1,   397,
      -1,    -1,   269,  1113,  1540,    -1,    -1,    23,  1117,  1118,
    1119,   984,  1114,  1540,    -1,    -1,    23,  1117,   984,  1115,
    1540,    -1,  1112,    -1,  1116,  1112,    -1,    -1,  1057,    -1,
      25,    -1,  1139,    -1,    -1,  1139,    -1,    25,    -1,   286,
    1123,    -1,   298,  1124,    -1,   281,  1124,    -1,   619,    -1,
      25,    -1,  1139,    -1,  1123,    -1,  1124,     5,  1123,    -1,
    1139,    -1,    25,    -1,    -1,    -1,   679,   985,  1127,   795,
    1128,  1129,   680,    -1,  1130,    -1,  1129,  1130,    -1,    -1,
     681,  1131,  1540,    -1,    -1,   658,   985,  1132,  1540,    -1,
    1136,  1134,    -1,    -1,   722,  1137,    -1,  1138,    -1,  1135,
      -1,  1007,    -1,  1009,    -1,  1011,    -1,  1003,    -1,  1005,
      -1,   405,   910,   890,    -1,    -1,   100,    -1,   100,    -1,
    1140,    -1,  1142,    -1,   225,  1142,    -1,  1142,   653,    -1,
    1141,  1146,    -1,  1141,   985,   493,  1150,   461,    -1,  1141,
     985,   493,  1150,   461,   493,  1150,   461,    -1,  1147,    -1,
     985,    -1,  1143,    -1,   985,   492,  1145,   460,    -1,   985,
     492,  1145,   460,    -1,  1139,    -1,    25,    -1,    20,    -1,
     985,    -1,   985,  1149,    -1,   985,  1149,    -1,   493,  1150,
     461,    -1,   493,  1150,   461,   493,  1150,   461,    -1,  1151,
      -1,  1150,     5,  1151,    -1,   718,    -1,  1153,    -1,  1155,
      -1,  1153,   653,  1154,    -1,  1153,   653,   985,   493,  1150,
     461,    -1,  1153,   653,   985,   493,  1150,   461,   493,  1150,
     461,    -1,   985,    -1,  1144,    -1,    20,    -1,   985,    -1,
     985,  1149,    -1,    -1,  1157,    -1,  1159,    -1,  1157,     5,
    1159,    -1,  1160,    -1,  1158,     5,  1160,    -1,   985,    -1,
     985,   653,   985,    -1,  1139,    -1,  1139,   455,  1139,    -1,
      25,    -1,   991,    -1,    26,    -1,  1162,    -1,  1161,     5,
    1162,    -1,  1139,    -1,  1139,   455,  1139,    -1,  1164,    -1,
    1163,     5,  1164,    -1,  1152,    -1,  1139,    -1,  1167,    -1,
    1166,     5,  1167,    -1,  1139,  1168,    -1,    -1,   621,    -1,
     572,    -1,   985,   493,  1150,   461,    -1,  1171,    -1,  1170,
       5,  1171,    -1,  1139,    -1,  1139,   455,  1139,    -1,   289,
     981,   651,   975,   613,  1532,   726,    -1,    -1,   651,   465,
     892,     5,   892,   426,  1174,    -1,    -1,   602,   465,   892,
       5,   892,   426,    -1,   290,   985,  1173,    -1,   985,    -1,
     373,   983,  1178,    -1,  1179,    -1,   580,   892,    -1,  1180,
    1181,  1186,     8,  1176,    -1,    -1,   651,  1182,   465,   892,
       5,   892,   426,    -1,    -1,   590,   986,    -1,    -1,   385,
      -1,   252,  1481,   301,  1519,  1185,    -1,   597,   978,    -1,
     597,   978,     8,   910,   890,    -1,    -1,   650,   610,  1475,
     409,  1475,    -1,   650,   610,  1475,     5,   409,  1475,    -1,
     650,  1475,     5,  1475,    -1,    -1,   682,    -1,   683,    -1,
     125,  1519,  1188,  1189,    -1,    -1,   650,  1519,    -1,    -1,
     650,   610,  1475,     8,  1475,    -1,   610,  1475,     8,  1475,
      -1,   446,  1191,    -1,  1192,    -1,  1191,     5,  1192,    -1,
     238,   972,    -1,   319,   972,    -1,   364,   972,    -1,   372,
     972,    -1,   328,   972,    -1,   294,   972,    -1,  1059,    -1,
     473,  1060,    -1,   484,  1060,    -1,   595,  1060,    -1,   410,
    1060,    -1,   584,  1060,    -1,   582,   973,    -1,   583,   973,
      -1,   435,   722,    -1,   698,   722,    -1,   326,    -1,   230,
      -1,   187,    -1,   167,    -1,   184,    -1,   175,    -1,  1480,
     448,  1196,   580,  1194,    -1,  1139,    -1,    25,    -1,   437,
    1196,    -1,   437,  1196,     8,  1158,    -1,    43,  1194,    -1,
     986,    -1,    -1,   496,  1206,   721,   629,  1201,  1139,  1199,
     984,   721,  1198,  1202,    -1,    -1,   701,    26,    -1,   496,
    1206,   721,   379,  1139,    -1,    -1,   354,    -1,    -1,  1203,
     317,    -1,  1204,    -1,  1203,  1204,    -1,    -1,  1055,  1205,
    1540,    -1,   891,    -1,    -1,   637,   978,  1208,  1209,    -1,
      -1,   580,  1210,    -1,  1211,    -1,  1210,     5,  1211,    -1,
    1467,    -1,   517,    -1,   255,  1214,   123,    -1,   255,  1214,
     659,  1213,    -1,   255,  1214,   122,  1213,    -1,   255,  1214,
      -1,    25,    -1,   990,    -1,   985,    -1,    -1,   513,    -1,
     183,  1214,  1215,   465,   910,  1097,   426,    -1,   228,  1214,
      -1,   102,  1214,    -1,  1250,  1258,    -1,   481,    96,    -1,
     481,  1221,    -1,  1222,    -1,  1221,  1222,    -1,    -1,   171,
    1223,  1540,    -1,    -1,   234,  1224,  1540,    -1,    -1,   263,
    1225,  1540,    -1,    -1,   251,  1226,  1540,    -1,    -1,   288,
    1227,  1540,    -1,    -1,   236,  1139,  1228,  1540,    -1,    -1,
     259,  1139,  1229,  1540,    -1,  1240,    -1,  1242,    -1,  1241,
      -1,  1231,    -1,  1267,    -1,  1234,    -1,    -1,   594,   892,
    1232,   516,    -1,    -1,   516,    -1,    -1,   603,    26,  1235,
    1233,    -1,   194,    -1,   662,  1254,    -1,   197,  1254,    -1,
     196,  1254,    -1,    -1,  1237,    -1,  1238,    -1,  1237,  1238,
      -1,  1247,  1239,    -1,    -1,   651,  1254,    -1,   553,  1236,
    1246,    -1,   552,  1475,  1246,    -1,   551,  1245,  1244,  1243,
    1246,    -1,    -1,   188,   885,    -1,   188,   885,     5,   885,
      -1,   646,    -1,   647,    -1,   648,    -1,   649,    -1,  1139,
      -1,    -1,   556,    -1,  1248,    -1,  1247,     5,  1248,    -1,
     892,  1281,    -1,   642,   465,   885,   426,  1266,    -1,    99,
    1266,    -1,   530,   465,    20,   426,  1266,    -1,   447,   465,
      20,   426,  1266,    -1,   422,   465,   885,   426,  1266,    -1,
     622,   465,   885,   426,  1266,    -1,   635,   465,   885,   426,
    1266,    -1,   634,   465,   885,   426,  1266,    -1,    -1,   495,
    1251,    -1,  1252,    -1,  1251,  1252,    -1,   262,    26,    -1,
     253,    26,    -1,   336,    26,    -1,   219,    26,    -1,   291,
      26,    -1,   210,    -1,   378,    25,    -1,   378,  1139,    -1,
     211,    25,    -1,   195,    25,    -1,  1257,    -1,  1253,  1257,
      -1,  1255,   143,    -1,  1255,   145,    -1,  1255,   144,    -1,
    1255,    -1,   991,    -1,    26,    -1,    -1,   495,  1253,    -1,
     262,  1254,    -1,   253,  1254,    -1,   336,  1254,    -1,   219,
    1254,    -1,   291,  1254,    -1,   292,  1254,    -1,   661,    25,
      -1,   662,  1254,    -1,   666,    -1,   663,    -1,   664,    -1,
     665,    -1,   670,    -1,   667,    -1,   668,    -1,   669,    -1,
     111,  1254,    -1,   112,  1254,    -1,   113,  1254,    -1,   378,
      25,    -1,   211,    25,    -1,   434,    -1,   108,    -1,   109,
      -1,    -1,   548,   652,  1166,    -1,   172,  1166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   499,  1260,   985,   465,  1261,
    1156,   426,  1262,   795,  1263,  1219,  1264,  1220,  1265,   274,
      -1,    -1,   560,   885,    -1,   550,  1268,    -1,    -1,  1194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,  1270,   985,
     465,  1271,  1156,   426,  1272,   795,  1273,  1276,  1274,  1220,
    1275,   274,    -1,  1256,  1258,    -1,    -1,    -1,    -1,   190,
     465,    25,     5,  1278,   748,  1279,   426,  1280,   746,    -1,
      -1,   418,    -1,   418,   253,    26,    -1,   418,   253,  1139,
      -1,   640,   892,    -1,   640,   892,   379,  1139,    -1,   640,
     892,   198,    -1,   640,   892,   611,    -1,   640,   892,   578,
      -1,  1284,    -1,   207,    -1,   358,    -1,   316,    -1,  1291,
      -1,  1286,    -1,    -1,    -1,   241,  1287,  1424,   465,  1288,
    1295,   426,    -1,    -1,    -1,   169,  1289,  1424,   465,  1290,
    1295,   426,  1292,    -1,   138,  1424,   658,  1424,   465,  1293,
     426,    -1,    89,   986,    -1,    -1,   303,    -1,  1294,    -1,
    1293,     5,  1294,    -1,   985,   621,    -1,   985,   572,    -1,
     985,    -1,  1296,    -1,  1295,     5,  1296,    -1,  1377,    -1,
    1375,    -1,   155,   985,    -1,   214,    -1,    50,   985,  1299,
      -1,  1300,    -1,  1299,     5,  1300,    -1,  1301,    -1,  1304,
      -1,  1307,    -1,  1312,    -1,  1313,    -1,  1311,    -1,  1310,
      -1,   618,  1302,    -1,   618,   465,  1303,   426,    -1,  1296,
      -1,  1296,   697,   985,    -1,  1302,    -1,  1303,     5,  1302,
      -1,   575,  1306,    -1,   575,   465,  1305,   426,    -1,  1306,
      -1,  1305,     5,  1306,    -1,   985,    -1,   489,  1309,    -1,
     489,   465,  1308,   426,    -1,  1309,    -1,  1308,     5,  1309,
      -1,  1296,    -1,   120,    -1,   121,    -1,   119,    26,    -1,
      91,  1381,    -1,    91,   465,  1314,   426,    -1,    92,  1315,
      -1,    92,   465,  1314,   426,    -1,  1381,    -1,  1314,     5,
    1381,    -1,   985,    -1,   300,    -1,   266,    -1,   200,  1318,
      -1,   179,    -1,   168,    -1,   154,    -1,   152,    -1,   156,
      -1,   213,  1481,    -1,   265,  1317,   494,  1475,   659,  1475,
      -1,   333,   978,   494,  1475,   659,  1475,    -1,    -1,  1481,
      -1,    -1,   892,    -1,   557,   892,    -1,   264,    -1,    -1,
     283,  1322,  1424,  1325,  1323,    -1,    -1,   513,  1324,   465,
    1327,   426,    -1,  1461,    -1,    -1,   465,  1326,   426,    -1,
    1427,    -1,  1326,     5,  1427,    -1,  1328,    -1,  1327,     5,
    1328,    -1,  1467,    -1,   517,    -1,    -1,    -1,   534,  1330,
    1333,  1331,  1334,    -1,   986,    -1,  1338,   979,    -1,   979,
      -1,    -1,    -1,   587,  1335,  1161,    -1,    -1,    -1,   587,
    1337,  1161,    -1,   535,    -1,   588,    -1,   595,    -1,   410,
      -1,   376,    -1,   430,    -1,   413,   892,    -1,   385,   892,
      -1,   272,  1424,   185,   979,    -1,   272,  1424,  1397,    -1,
     548,   652,  1342,    -1,  1343,    -1,  1342,     5,  1343,    -1,
    1344,  1345,    -1,    26,    -1,  1427,    -1,    -1,   621,    -1,
     572,    -1,   311,    -1,   344,    -1,    -1,   361,    -1,   391,
    1350,  1348,    -1,  1519,    -1,  1519,   645,   985,    -1,    25,
      -1,    -1,  1480,  1352,  1353,    -1,  1382,    -1,  1386,    -1,
    1347,    -1,  1482,    -1,  1346,    -1,  1339,    -1,  1340,    -1,
    1329,    -1,  1321,    -1,  1320,    -1,  1451,    -1,  1499,    -1,
     539,  1356,   658,  1424,   659,  1361,  1355,    -1,    -1,   178,
      -1,   202,    -1,  1357,    -1,  1358,    -1,  1357,     5,  1358,
      -1,   505,    -1,   484,    -1,   473,    -1,   512,  1359,    -1,
      -1,   465,  1360,   426,    -1,  1427,    -1,  1360,     5,  1427,
      -1,  1362,    -1,  1361,     5,  1362,    -1,   497,    -1,  1425,
      -1,   270,  1424,  1364,   650,  1461,  1366,    -1,    -1,   465,
    1365,   426,    -1,  1427,    -1,  1365,     5,  1427,    -1,    -1,
     177,    -1,   526,   465,  1400,   426,    -1,   280,   465,  1370,
     426,  1369,    -1,   331,  1371,    -1,  1372,    -1,  1424,    -1,
    1424,   465,  1372,   426,    -1,  1427,    -1,  1372,     5,  1427,
      -1,   510,   465,  1374,   426,    -1,   293,   465,  1374,   426,
      -1,  1427,    -1,  1374,     5,  1427,    -1,  1373,    -1,  1368,
      -1,  1367,    -1,   434,  1430,    -1,   242,    -1,   985,  1416,
    1378,  1379,    -1,    -1,  1376,    -1,    -1,  1380,    -1,  1381,
      -1,  1380,  1381,    -1,   408,    -1,   193,    -1,   510,    -1,
    1369,    -1,   526,   465,  1400,   426,    -1,   153,  1383,  1385,
      -1,  1384,    -1,  1425,    -1,  1386,    -1,  1385,  1386,    -1,
    1363,    -1,  1354,    -1,   482,  1400,    -1,   403,  1389,    -1,
    1466,    -1,  1389,     5,  1466,    -1,   560,  1400,    -1,   580,
    1392,    -1,  1393,    -1,  1392,     5,  1393,    -1,  1394,    -1,
     549,  1394,    -1,   549,   465,  1395,   426,    -1,  1424,    -1,
    1424,  1429,    -1,  1393,    -1,  1395,     5,  1393,    -1,  1391,
    1397,  1398,  1399,    -1,    -1,  1390,    -1,    -1,  1388,    -1,
      -1,  1387,    -1,  1401,    -1,  1400,     6,  1401,    -1,  1402,
      -1,  1401,     7,  1402,    -1,  1403,    -1,     9,  1403,    -1,
    1414,    -1,   465,  1400,   426,    -1,   477,  1462,    -1,   329,
    1462,    -1,    -1,   476,  1407,    -1,  1468,    -1,  1471,    -1,
    1467,   656,   465,  1409,   426,    -1,  1467,   656,  1462,    -1,
    1467,   463,   465,  1409,   426,    -1,  1467,   463,  1462,    -1,
    1410,    -1,  1409,     5,  1410,    -1,  1523,    -1,  1430,    -1,
      -1,     9,    -1,  1467,  1411,   421,    -1,  1467,  1411,   284,
      -1,  1467,  1413,  1467,    -1,  1467,  1411,   423,  1467,     7,
    1467,    -1,  1467,   590,  1406,  1405,    -1,  1467,   406,  1406,
    1405,    -1,  1467,   707,  1406,  1405,    -1,  1467,   407,  1406,
    1405,    -1,  1467,  1411,    10,  1406,  1405,    -1,    14,    -1,
      17,    -1,    12,    -1,    13,    -1,   287,    -1,    10,    -1,
     706,    -1,    16,    -1,    15,    -1,  1412,    -1,  1408,    -1,
    1404,    -1,    -1,   619,    -1,   394,    -1,   510,    -1,  1417,
      -1,  1418,    -1,  1420,    -1,   354,    -1,   354,   465,  1421,
     426,    -1,   445,   465,  1422,  1419,   426,    -1,   506,    -1,
     432,   465,  1422,  1419,   426,    -1,   546,   465,  1422,  1419,
     426,    -1,   571,    -1,   442,    -1,   415,    -1,   392,  1437,
     659,  1438,    -1,   392,    -1,   404,  1437,   659,  1438,    -1,
     404,    -1,   404,  1437,   465,    26,   426,   659,  1438,    -1,
     608,    -1,   567,    -1,   458,    -1,   458,   465,    26,   426,
      -1,   458,   465,    26,     5,    26,   426,    -1,    -1,     5,
    1423,    -1,   536,   465,  1422,   426,    -1,   599,    -1,   334,
      -1,   536,    -1,    98,    -1,    26,    -1,    26,    -1,    26,
      -1,    25,   653,   985,    -1,    25,    -1,   985,    -1,   985,
     623,   985,    -1,   985,    -1,    -1,   493,    26,   461,    -1,
     493,    26,     5,    26,   461,    -1,  1428,    -1,   645,  1428,
      -1,   985,  1426,    -1,  1424,   653,   985,  1426,    -1,  1424,
     653,    20,    -1,   985,    -1,    25,    -1,   445,    -1,   991,
      -1,    26,    -1,  1432,    -1,   430,  1434,    -1,   430,  1433,
      -1,    -1,  1437,   659,  1438,    -1,    -1,  1435,   659,  1435,
      -1,   615,    -1,   547,    -1,   624,    -1,   586,    -1,   488,
      -1,   504,    -1,   401,    -1,   401,   465,    26,   426,    -1,
     615,    -1,   547,    -1,   624,    -1,   586,    -1,   488,    -1,
     504,    -1,   401,    -1,   401,   465,    26,   426,    -1,   615,
      -1,   547,    -1,   624,    -1,   586,    -1,   488,    -1,   504,
      -1,   401,    -1,   615,    -1,   547,    -1,   624,    -1,   586,
      -1,   488,    -1,   504,    -1,   401,    -1,   401,   465,    26,
     426,    -1,   985,    -1,   985,   645,   985,    -1,    25,    -1,
    1480,   537,   979,    -1,    -1,  1480,   433,  1332,   471,   629,
    1449,  1442,    -1,    -1,  1480,   433,  1332,   471,   135,   629,
    1450,  1443,    -1,    -1,  1480,   433,  1332,   173,  1450,  1444,
      -1,    -1,  1480,   433,  1332,   174,   135,   629,  1450,  1445,
      -1,    -1,   323,    -1,   322,  1447,    -1,  1448,    -1,  1447,
       5,  1448,    -1,   985,    -1,   985,   653,   985,    -1,    25,
     653,   985,   653,   985,    -1,  1450,    -1,  1321,    -1,  1196,
      -1,  1452,    -1,  1452,    -1,    -1,    -1,   505,  1463,  1453,
    1464,  1454,  1460,  1396,  1458,  1446,    -1,   505,  1463,  1464,
    1396,  1458,    -1,  1457,    -1,  1475,    -1,   505,  1463,  1464,
    1460,  1396,  1458,    -1,    -1,   559,  1415,  1456,    -1,  1341,
      -1,   366,  1459,  1292,    -1,  1341,   366,  1459,  1292,    -1,
     985,    -1,    -1,   587,  1161,    -1,   505,  1463,  1464,  1396,
      -1,   465,   505,  1463,  1464,  1396,   426,    -1,    -1,   619,
      -1,   394,    -1,   510,    -1,  1465,    -1,  1464,     5,  1465,
      -1,  1467,    -1,  1467,   985,    -1,  1467,    -1,  1468,    -1,
      19,  1468,    -1,    18,  1468,    -1,  1469,    -1,  1523,    -1,
    1462,    -1,   645,   985,    -1,   645,   985,   653,   985,    -1,
    1468,    21,  1467,    -1,  1468,  1489,    -1,  1468,    20,  1467,
      -1,  1468,    18,  1467,    -1,  1468,    19,  1467,    -1,  1430,
      -1,   518,    -1,   462,    -1,   610,    -1,    20,    -1,    99,
      -1,   622,   465,  1415,  1467,   426,    -1,   634,   465,  1415,
    1467,   426,    -1,   635,   465,  1415,  1467,   426,    -1,   642,
     465,  1415,  1467,   426,    -1,   530,   465,  1415,  1467,   426,
      -1,   985,   465,  1470,   426,    -1,   571,   465,  1470,   426,
      -1,   465,  1467,   426,    -1,   478,   465,  1490,   426,    -1,
    1467,    -1,  1470,     5,  1467,    -1,  1430,    -1,  1480,   381,
    1479,  1474,  1456,    -1,  1480,   370,  1479,  1474,   283,  1424,
    1476,    -1,  1480,   370,  1479,  1474,  1139,    -1,    -1,   356,
    1475,    -1,    25,    -1,  1139,    -1,    -1,   465,  1477,   426,
      -1,  1478,    -1,  1477,     5,  1478,    -1,   985,    -1,    25,
      -1,  1139,    -1,    -1,   302,  1481,   629,    -1,   986,    -1,
    1487,    -1,  1486,    -1,  1483,    -1,   351,  1484,   659,  1484,
      -1,   332,  1484,   653,  1485,   659,  1485,    -1,   985,    -1,
     985,    -1,   256,   832,    -1,   327,   832,  1488,    -1,   306,
      -1,   209,    -1,   127,    -1,   128,    -1,   129,    -1,   130,
      -1,   131,    -1,   132,    -1,   430,     5,  1437,   659,  1438,
      -1,  1523,     5,  1437,   659,  1438,    -1,   430,  1437,   659,
    1438,    -1,    -1,   641,  1492,  1493,   224,    -1,  1494,    -1,
    1493,  1494,    -1,    33,    -1,  1495,    -1,  1497,    -1,   385,
      -1,   339,    -1,   258,    -1,   618,    -1,   515,    -1,   619,
      -1,   520,    -1,   564,    -1,   620,    -1,   149,    -1,   521,
      -1,   650,    -1,   621,    -1,   352,    -1,   522,    -1,   353,
      -1,   651,    -1,   645,    -1,   309,    -1,   523,    -1,   218,
      -1,   422,    -1,   622,    -1,   697,    -1,   423,    -1,   524,
      -1,   525,    -1,   565,    -1,   566,    -1,   466,    -1,   467,
      -1,   387,    -1,   684,    -1,   652,    -1,   567,    -1,   424,
      -1,   569,    -1,   563,    -1,   354,    -1,   526,    -1,   527,
      -1,   425,    -1,   528,    -1,   426,    -1,   461,    -1,   529,
      -1,   623,    -1,   468,    -1,   427,    -1,     5,    -1,    23,
      -1,   428,    -1,   469,    -1,   429,    -1,   389,    -1,   388,
      -1,   355,    -1,   530,    -1,   470,    -1,   430,    -1,   471,
      -1,   570,    -1,   391,    -1,   571,    -1,   392,    -1,   624,
      -1,   625,    -1,   431,    -1,   626,    -1,   432,    -1,   433,
      -1,   434,    -1,   393,    -1,   531,    -1,   472,    -1,   473,
      -1,   356,    -1,   572,    -1,   315,    -1,   627,    -1,   688,
      -1,   435,    -1,   394,    -1,    21,    -1,   653,    -1,   474,
      -1,   357,    -1,   575,    -1,    97,    -1,   576,    -1,   691,
      -1,   436,    -1,    14,    -1,   532,    -1,   476,    -1,   533,
      -1,   361,    -1,   577,    -1,   437,    -1,   477,    -1,   578,
      -1,   478,    -1,   479,    -1,   400,    -1,   568,    -1,   534,
      -1,   134,    -1,   227,    -1,   480,    -1,   535,    -1,   628,
      -1,   536,    -1,   537,    -1,   629,    -1,   438,    -1,   439,
      -1,   481,    -1,   671,    -1,   126,    -1,   139,    -1,   538,
      -1,   401,    -1,   579,    -1,   580,    -1,   402,    -1,   324,
      -1,   440,    -1,   654,    -1,   581,    -1,   539,    -1,    13,
      -1,   540,    -1,   541,    -1,   482,    -1,   483,    -1,   584,
      -1,   585,    -1,   586,    -1,   693,    -1,   106,    -1,   655,
      -1,   656,    -1,   145,    -1,   542,    -1,   441,    -1,   325,
      -1,   698,    -1,   484,    -1,   442,    -1,   365,    -1,   404,
      -1,   700,    -1,   367,    -1,   630,    -1,   573,    -1,   692,
      -1,   543,    -1,   516,    -1,   405,    -1,   631,    -1,   660,
      -1,   443,    -1,     7,    -1,   462,    -1,   616,    -1,   517,
      -1,     6,    -1,   518,    -1,     8,    -1,   588,    -1,   589,
      -1,    12,    -1,   632,    -1,   590,    -1,   545,    -1,   485,
      -1,   633,    -1,   444,    -1,   591,    -1,   486,    -1,    10,
      -1,    49,    -1,   487,    -1,   592,    -1,   679,    -1,   694,
      -1,    19,    -1,   488,    -1,   144,    -1,    22,    -1,   593,
      -1,   489,    -1,   546,    -1,   547,    -1,    20,    -1,   594,
      -1,   595,    -1,   345,    -1,   596,    -1,   490,    -1,     9,
      -1,   445,    -1,   657,    -1,   702,    -1,   658,    -1,   597,
      -1,   465,    -1,   493,    -1,   494,    -1,   446,    -1,   548,
      -1,   374,    -1,   549,    -1,   495,    -1,   636,    -1,   409,
      -1,   550,    -1,   190,    -1,   140,    -1,   447,    -1,    18,
      -1,   143,    -1,   375,    -1,   448,    -1,   146,    -1,   410,
      -1,   346,    -1,   553,    -1,   376,    -1,   377,    -1,   449,
      -1,   496,    -1,   497,    -1,   637,    -1,   598,    -1,   411,
      -1,   599,    -1,   498,    -1,   450,    -1,   638,    -1,   331,
      -1,   412,    -1,   413,    -1,   499,    -1,   414,    -1,   212,
      -1,   379,    -1,   451,    -1,   500,    -1,   554,    -1,   296,
      -1,   639,    -1,   600,    -1,   640,    -1,   501,    -1,   503,
      -1,   504,    -1,   452,    -1,   505,    -1,   556,    -1,   506,
      -1,   453,    -1,   508,    -1,   601,    -1,   519,    -1,   602,
      -1,   603,    -1,   557,    -1,   334,    -1,   415,    -1,   604,
      -1,   509,    -1,   641,    -1,   335,    -1,   124,    -1,   605,
      -1,   606,    -1,   642,    -1,   454,    -1,   574,    -1,   607,
      -1,   150,    -1,   608,    -1,   609,    -1,   455,    -1,   701,
      -1,   659,    -1,   643,    -1,   456,    -1,   558,    -1,   233,
      -1,   380,    -1,   559,    -1,   510,    -1,   511,    -1,   512,
      -1,   457,    -1,   644,    -1,   610,    -1,   416,    -1,   513,
      -1,   458,    -1,   384,    -1,   611,    -1,   459,    -1,   612,
      -1,   560,    -1,   561,    -1,   562,    -1,   613,    -1,   418,
      -1,   614,    -1,   634,    -1,   635,    -1,   617,    -1,   615,
      -1,   514,    -1,    -1,   225,  1496,  1523,    -1,    -1,   587,
    1498,  1161,    -1,    -1,    -1,   512,  1424,  1500,  1503,  1501,
    1502,    -1,    -1,   185,   979,    -1,   560,  1400,    -1,    87,
    1507,   426,    14,   465,  1508,   426,    -1,    83,  1508,   426,
      -1,    84,  1508,   426,    -1,   617,  1504,    -1,    86,  1508,
      -1,    85,  1508,    -1,  1506,    -1,  1504,     5,  1506,    -1,
    1427,    -1,  1505,    14,  1509,    -1,  1505,    -1,  1507,     5,
    1505,    -1,  1509,    -1,  1508,     5,  1509,    -1,   517,    -1,
    1510,    -1,  1511,    -1,    19,  1511,    -1,    18,  1511,    -1,
    1513,    -1,  1462,    -1,   645,   985,    -1,   645,   985,   653,
     985,    -1,  1512,    -1,  1430,    -1,   518,    -1,   462,    -1,
     610,    -1,    99,    -1,  1511,    21,  1510,    -1,  1511,  1489,
      -1,  1511,    20,  1510,    -1,  1511,    18,  1510,    -1,  1511,
      19,  1510,    -1,   622,   465,  1415,  1510,   426,    -1,   634,
     465,  1415,  1510,   426,    -1,   635,   465,  1415,  1510,   426,
      -1,   642,   465,  1415,  1510,   426,    -1,   530,   465,  1415,
    1510,   426,    -1,   985,   465,  1514,   426,    -1,   571,   465,
    1514,   426,    -1,   465,  1510,   426,    -1,   478,   465,  1490,
     426,    -1,  1523,    -1,  1510,    -1,  1514,     5,  1510,    -1,
      -1,   416,  1170,   590,  1516,  1517,    -1,  1518,    -1,  1517,
       5,  1518,    -1,   832,   653,  1427,    -1,   832,   653,    20,
      -1,  1520,    -1,   225,  1521,    -1,  1521,    -1,  1148,    -1,
     985,    -1,  1521,   653,  1522,    -1,    25,   653,  1521,   653,
    1522,    -1,    20,    -1,  1169,    -1,   985,    -1,  1520,    -1,
    1520,   455,  1520,    -1,    -1,    -1,   561,  1525,   892,  1526,
    1540,   360,    -1,    -1,   692,  1530,    -1,    -1,   695,    -1,
     216,    -1,   312,   980,    -1,   104,   980,    -1,   342,    -1,
     341,    -1,   343,   982,  1527,  1528,    -1,   527,  1530,  1528,
      -1,   977,    -1,  1530,     5,   977,    -1,   137,    -1,   170,
     980,    -1,   892,   600,     5,   892,   427,    -1,   543,   892,
      -1,   299,   980,    -1,   136,  1535,     8,  1536,  1534,    -1,
      -1,   580,   892,    -1,   985,    -1,   985,    -1,   282,   980,
      -1,   285,   980,   659,   892,     5,   892,    -1,   285,   980,
     652,   892,     5,   892,    -1,    27,    -1,    -1,  1542,    -1,
    1543,  1246,    -1,  1541,    -1,  1542,  1541,    -1,    -1,  1544,
    1545,    -1,   711,    -1,   712,    -1,   713,    -1,   714,    -1,
     731,    -1,   753,    -1,   767,    -1,   768,    -1,   774,    -1,
     775,    -1,   794,    -1,   864,    -1,   865,    -1,   866,    -1,
     867,    -1,   878,    -1,   879,    -1,   880,    -1,   881,    -1,
     882,    -1,   883,    -1,   884,    -1,   936,    -1,   940,    -1,
     971,    -1,   992,    -1,   994,    -1,   997,    -1,   998,    -1,
     999,    -1,  1000,    -1,  1013,    -1,  1022,    -1,  1043,    -1,
    1044,    -1,  1046,    -1,  1050,    -1,  1065,    -1,  1066,    -1,
    1070,    -1,  1071,    -1,  1072,    -1,  1073,    -1,  1081,    -1,
    1096,    -1,  1109,    -1,  1120,    -1,  1121,    -1,  1122,    -1,
    1133,    -1,  1172,    -1,  1175,    -1,  1177,    -1,  1183,    -1,
    1184,    -1,  1187,    -1,  1190,    -1,  1193,    -1,  1195,    -1,
    1197,    -1,  1200,    -1,  1207,    -1,  1212,    -1,  1216,    -1,
    1217,    -1,  1218,    -1,  1230,    -1,  1282,    -1,  1283,    -1,
    1285,    -1,  1297,    -1,  1298,    -1,  1316,    -1,  1319,    -1,
    1349,    -1,  1351,    -1,  1440,    -1,  1441,    -1,  1472,    -1,
    1473,    -1,  1491,    -1,  1515,    -1,  1524,    -1,  1529,    -1,
    1531,    -1,  1533,    -1,  1537,    -1,  1538,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   973,   973,   976,   979,   985,   991,   998,  1002,  1002,
    1008,  1031,  1032,  1033,  1034,  1035,  1046,  1055,  1056,  1057,
    1058,  1059,  1064,  1065,  1076,  1079,  1082,  1082,  1086,  1089,
    1090,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1115,  1116,
    1119,  1119,  1134,  1135,  1138,  1144,  1146,  1157,  1159,  1161,
    1163,  1167,  1169,  1231,  1235,  1239,  1239,  1249,  1253,  1256,
    1257,  1264,  1270,  1264,  1283,  1288,  1292,  1283,  1304,  1308,
    1304,  1316,  1321,  1316,  1340,  1347,  1351,  1339,  1377,  1377,
    1381,  1382,  1383,  1388,  1391,  1396,  1400,  1408,  1411,  1411,
    1417,  1421,  1436,  1434,  1452,  1452,  1467,  1467,  1470,  1470,
    1474,  1477,  1477,  1477,  1484,  1485,  1484,  1492,  1492,  1503,
    1503,  1522,  1525,  1528,  1531,  1534,  1537,  1550,  1555,  1555,
    1556,  1556,  1559,  1564,  1564,  1568,  1578,  1592,  1597,  1591,
    1608,  1614,  1622,  1623,  1626,  1626,  1629,  1633,  1638,  1645,
    1645,  1649,  1649,  1657,  1657,  1663,  1663,  1669,  1669,  1675,
    1675,  1689,  1690,  1698,  1699,  1716,  1719,  1722,  1725,  1728,
    1731,  1737,  1748,  1753,  1766,  1770,  1785,  1786,  1790,  1790,
    1794,  1794,  1794,  1795,  1800,  1800,  1803,  1803,  1812,  1813,
    1814,  1817,  1821,  1822,  1822,  1839,  1839,  1839,  1839,  1843,
    1850,  1851,  1854,  1854,  1858,  1859,  1860,  1861,  1866,  1866,
    1872,  1872,  1881,  1878,  1894,  1894,  1896,  1896,  1898,  1900,
    1902,  1904,  1907,  1911,  1911,  1912,  1912,  1916,  1916,  1928,
    1928,  1933,  1937,  1939,  1940,  1943,  1943,  1943,  1947,  1948,
    1949,  1950,  1957,  1958,  1959,  1960,  1963,  1964,  1965,  1966,
    1970,  1975,  1980,  1984,  1987,  1991,  1992,  1993,  1994,  1995,
    1996,  1997,  1998,  2001,  2002,  2003,  2035,  2039,  2041,  2043,
    2043,  2050,  2054,  2054,  2058,  2059,  2060,  2061,  2062,  2063,
    2064,  2070,  2070,  2073,  2075,  2081,  2083,  2089,  2097,  2097,
    2100,  2101,  2102,  2103,  2104,  2105,  2106,  2112,  2115,  2115,
    2128,  2128,  2135,  2136,  2137,  2139,  2140,  2142,  2144,  2145,
    2146,  2147,  2152,  2158,  2164,  2165,  2167,  2169,  2170,  2171,
    2172,  2173,  2174,  2177,  2178,  2185,  2193,  2193,  2201,  2198,
    2213,  2213,  2215,  2215,  2223,  2223,  2226,  2229,  2230,  2235,
    2247,  2251,  2254,  2257,  2258,  2259,  2260,  2261,  2266,  2273,
    2279,  2284,  2289,  2284,  2302,  2304,  2309,  2314,  2314,  2314,
    2318,  2318,  2321,  2321,  2328,  2328,  2335,  2335,  2346,  2364,
    2370,  2394,  2397,  2411,  2413,  2415,  2417,  2419,  2421,  2423,
    2429,  2431,  2435,  2437,  2439,  2441,  2443,  2445,  2447,  2453,
    2468,  2471,  2484,  2485,  2486,  2487,  2488,  2492,  2493,  2494,
    2498,  2503,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,
    2518,  2519,  2520,  2527,  2527,  2532,  2532,  2535,  2541,  2549,
    2555,  2565,  2566,  2574,  2581,  2585,  2595,  2599,  2604,  2609,
    2611,  2614,  2620,  2628,  2641,  2646,  2652,  2657,  2662,  2663,
    2669,  2740,  2746,  2751,  2759,  2759,  2774,  2778,  2785,  2788,
    2796,  2800,  2803,  2809,  2818,  2823,  2831,  2834,  2837,  2842,
    2849,  2854,  2859,  2864,  2874,  2882,  2890,  2895,  2899,  2904,
    2908,  2912,  2919,  2922,  2925,  2929,  2933,  2937,  2941,  2949,
    2959,  2964,  2957,  2980,  2985,  2980,  3002,  3002,  3002,  3005,
    3005,  3005,  3009,  3009,  3009,  3013,  3013,  3013,  3017,  3023,
    3029,  3035,  3041,  3047,  3057,  3057,  3061,  3065,  3066,  3077,
    3078,  3084,  3094,  3104,  3114,  3115,  3118,  3123,  3129,  3133,
    3137,  3140,  3146,  3149,  3152,  3169,  3172,  3178,  3179,  3180,
    3184,  3185,  3186,  3187,  3188,  3190,  3191,  3192,  3194,  3195,
    3199,  3200,  3205,  3206,  3218,  3222,  3217,  3230,  3233,  3247,
    3251,  3257,  3246,  3270,  3271,  3283,  3289,  3283,  3303,  3303,
    3305,  3306,  3310,  3310,  3314,  3314,  3319,  3319,  3326,  3327,
    3331,  3331,  3335,  3335,  3340,  3340,  3347,  3351,  3352,  3353,
    3358,  3358,  3361,  3361,  3365,  3365,  3369,  3369,  3373,  3373,
    3378,  3378,  3383,  3383,  3388,  3388,  3393,  3393,  3409,  3426,
    3427,  3428,  3429,  3430,  3431,  3432,  3435,  3435,  3438,  3440,
    3443,  3446,  3448,  3449,  3450,  3452,  3454,  3456,  3458,  3462,
    3469,  3471,  3477,  3482,  3487,  3492,  3492,  3495,  3501,  3506,
    3509,  3516,  3516,  3518,  3519,  3521,  3523,  3525,  3527,  3531,
    3540,  3540,  3602,  3607,  3608,  3616,  3623,  3623,  3627,  3632,
    3638,  3642,  3646,  3652,  3656,  3660,  3666,  3666,  3674,  3675,
    3679,  3679,  3683,  3684,  3687,  3690,  3690,  3693,  3695,  3695,
    3698,  3700,  3700,  3701,  3703,  3703,  3712,  3719,  3710,  3741,
    3741,  3741,  3744,  3746,  3744,  3753,  3756,  3762,  3773,  3773,
    3777,  3783,  3783,  3787,  3788,  3799,  3800,  3801,  3804,  3806,
    3811,  3811,  3815,  3814,  3822,  3821,  3828,  3828,  3834,  3834,
    3841,  3841,  3847,  3847,  3853,  3853,  3859,  3859,  3863,  3863,
    3867,  3867,  3871,  3871,  3881,  3882,  3890,  3891,  3900,  3905,
    3910,  3911,  3912,  3916,  3915,  3928,  3933,  3938,  3938,  3954,
    3960,  3961,  3962,  3963,  3966,  3966,  3969,  3976,  3977,  3978,
    3979,  3980,  3981,  3982,  3983,  3984,  3989,  3989,  3991,  3994,
    3994,  3996,  4000,  4003,  4004,  4007,  4007,  4012,  4015,  4016,
    4017,  4018,  4019,  4020,  4021,  4022,  4023,  4024,  4025,  4026,
    4027,  4028,  4029,  4030,  4031,  4032,  4036,  4054,  4054,  4054,
    4081,  4092,  4099,  4105,  4111,  4117,  4128,  4151,  4150,  4167,
    4167,  4171,  4172,  4180,  4181,  4182,  4183,  4190,  4191,  4193,
    4194,  4198,  4203,  4204,  4205,  4206,  4207,  4208,  4209,  4210,
    4211,  4212,  4215,  4217,  4217,  4219,  4223,  4223,  4232,  4237,
    4253,  4259,  4231,  4273,  4287,  4297,  4286,  4310,  4317,  4317,
    4322,  4328,  4336,  4341,  4342,  4345,  4345,  4345,  4348,  4348,
    4356,  4362,  4376,  4380,  4393,  4375,  4411,  4411,  4425,  4436,
    4435,  4447,  4443,  4460,  4457,  4470,  4470,  4472,  4473,  4475,
    4476,  4479,  4480,  4481,  4483,  4488,  4493,  4499,  4501,  4502,
    4505,  4506,  4509,  4511,  4520,  4526,  4520,  4537,  4538,  4542,
    4542,  4552,  4552,  4564,  4567,  4570,  4573,  4577,  4581,  4582,
    4583,  4584,  4585,  4589,  4594,  4594,  4597,  4623,  4682,  4682,
    4685,  4689,  4693,  4736,  4778,  4779,  4780,  4783,  4797,  4809,
    4809,  4814,  4815,  4821,  4881,  4938,  4943,  4950,  4955,  4963,
    4969,  5003,  5006,  5007,  5048,  5091,  5092,  5096,  5097,  5101,
    5154,  5158,  5161,  5167,  5178,  5185,  5193,  5193,  5196,  5197,
    5198,  5199,  5200,  5203,  5206,  5212,  5215,  5219,  5224,  5232,
    5237,  5244,  5247,  5253,  5255,  5255,  5255,  5259,  5279,  5286,
    5293,  5296,  5310,  5317,  5318,  5321,  5322,  5326,  5332,  5337,
    5343,  5344,  5349,  5353,  5353,  5357,  5358,  5361,  5362,  5366,
    5374,  5377,  5383,  5384,  5386,  5388,  5392,  5392,  5393,  5398,
    5406,  5407,  5412,  5413,  5415,  5428,  5430,  5431,  5433,  5436,
    5439,  5442,  5446,  5449,  5452,  5456,  5460,  5464,  5467,  5471,
    5474,  5475,  5476,  5479,  5482,  5485,  5488,  5491,  5494,  5497,
    5513,  5521,  5521,  5523,  5530,  5534,  5539,  5554,  5552,  5572,
    5573,  5577,  5582,  5583,  5587,  5588,  5590,  5591,  5593,  5593,
    5602,  5611,  5611,  5621,  5622,  5627,  5628,  5631,  5644,  5658,
    5663,  5668,  5673,  5683,  5683,  5687,  5690,  5690,  5692,  5702,
    5711,  5718,  5720,  5724,  5727,  5727,  5731,  5730,  5738,  5737,
    5748,  5747,  5754,  5753,  5757,  5756,  5759,  5759,  5775,  5774,
    5796,  5797,  5798,  5799,  5800,  5801,  5804,  5804,  5810,  5810,
    5813,  5813,  5829,  5830,  5831,  5840,  5852,  5853,  5856,  5857,
    5860,  5863,  5863,  5868,  5888,  5893,  5899,  5900,  5901,  5905,
    5906,  5907,  5908,  5912,  5922,  5924,  5929,  5932,  5937,  5943,
    5950,  5957,  5966,  5973,  5980,  5987,  5994,  6003,  6003,  6005,
    6005,  6008,  6009,  6010,  6011,  6012,  6013,  6014,  6015,  6016,
    6017,  6020,  6020,  6023,  6024,  6025,  6026,  6029,  6029,  6032,
    6032,  6035,  6036,  6037,  6038,  6039,  6040,  6041,  6042,  6044,
    6045,  6046,  6047,  6049,  6050,  6051,  6052,  6054,  6055,  6056,
    6057,  6058,  6059,  6060,  6061,  6065,  6072,  6081,  6093,  6102,
    6113,  6117,  6121,  6127,  6092,  6140,  6143,  6151,  6163,  6165,
    6170,  6178,  6188,  6191,  6195,  6203,  6169,  6212,  6216,  6220,
    6224,  6216,  6234,  6235,  6236,  6237,  6242,  6244,  6247,  6251,
    6254,  6261,  6266,  6267,  6268,  6273,  6274,  6280,  6280,  6280,
    6285,  6285,  6285,  6296,  6297,  6303,  6304,  6316,  6317,  6322,
    6323,  6324,  6328,  6331,  6337,  6340,  6348,  6349,  6355,  6362,
    6365,  6374,  6377,  6380,  6383,  6386,  6389,  6392,  6399,  6402,
    6409,  6412,  6418,  6421,  6428,  6431,  6438,  6439,  6444,  6448,
    6451,  6457,  6460,  6466,  6473,  6474,  6478,  6484,  6487,  6494,
    6495,  6502,  6505,  6510,  6521,  6522,  6523,  6524,  6525,  6526,
    6527,  6528,  6529,  6532,  6535,  6541,  6541,  6547,  6547,  6558,
    6571,  6581,  6581,  6586,  6586,  6590,  6594,  6595,  6601,  6602,
    6607,  6611,  6618,  6621,  6628,  6632,  6627,  6641,  6645,  6649,
    6656,  6660,  6660,  6673,  6677,  6677,  6692,  6694,  6696,  6698,
    6700,  6702,  6704,  6706,  6712,  6722,  6729,  6734,  6735,  6739,
    6742,  6743,  6746,  6747,  6748,  6751,  6756,  6763,  6764,  6770,
    6782,  6783,  6784,  6787,  6787,  6792,  6797,  6802,  6803,  6806,
    6807,  6812,  6817,  6821,  6826,  6827,  6831,  6838,  6842,  6843,
    6848,  6850,  6854,  6855,  6859,  6860,  6861,  6862,  6866,  6867,
    6872,  6873,  6878,  6879,  6884,  6885,  6890,  6895,  6896,  6901,
    6902,  6906,  6907,  6912,  6919,  6924,  6929,  6933,  6934,  6939,
    6940,  6946,  6948,  6953,  6954,  6960,  6963,  6966,  6973,  6975,
    6989,  6994,  6995,  6998,  7000,  7007,  7010,  7016,  7020,  7024,
    7028,  7031,  7038,  7045,  7050,  7054,  7055,  7061,  7064,  7075,
    7082,  7088,  7091,  7098,  7105,  7111,  7112,  7118,  7119,  7120,
    7123,  7124,  7129,  7129,  7133,  7141,  7142,  7145,  7148,  7153,
    7154,  7159,  7162,  7168,  7171,  7177,  7180,  7186,  7189,  7196,
    7197,  7226,  7227,  7232,  7240,  7245,  7248,  7251,  7254,  7260,
    7261,  7265,  7268,  7271,  7272,  7277,  7280,  7283,  7286,  7289,
    7292,  7295,  7298,  7303,  7309,  7310,  7311,  7312,  7313,  7315,
    7316,  7318,  7319,  7324,  7327,  7331,  7337,  7338,  7339,  7340,
    7352,  7353,  7354,  7358,  7359,  7364,  7366,  7367,  7368,  7370,
    7371,  7372,  7373,  7375,  7376,  7378,  7379,  7381,  7382,  7383,
    7384,  7386,  7390,  7391,  7397,  7399,  7400,  7401,  7402,  7407,
    7411,  7415,  7419,  7426,  7430,  7431,  7441,  7450,  7451,  7452,
    7456,  7459,  7464,  7469,  7474,  7482,  7486,  7490,  7491,  7492,
    7497,  7500,  7503,  7517,  7531,  7544,  7545,  7549,  7549,  7549,
    7549,  7549,  7549,  7550,  7553,  7558,  7558,  7558,  7558,  7558,
    7558,  7560,  7563,  7569,  7569,  7569,  7569,  7569,  7569,  7569,
    7570,  7570,  7570,  7570,  7570,  7570,  7570,  7570,  7573,  7574,
    7575,  7578,  7587,  7587,  7593,  7593,  7600,  7600,  7606,  7606,
    7614,  7615,  7616,  7619,  7619,  7622,  7623,  7624,  7635,  7638,
    7644,  7649,  7656,  7669,  7670,  7667,  7688,  7699,  7702,  7707,
    7719,  7722,  7726,  7729,  7730,  7736,  7739,  7740,  7749,  7758,
    7763,  7764,  7765,  7766,  7773,  7776,  7782,  7785,  7795,  7804,
    7807,  7810,  7816,  7822,  7825,  7828,  7831,  7837,  7839,  7841,
    7843,  7845,  7847,  7848,  7849,  7850,  7851,  7852,  7853,  7855,
    7857,  7859,  7861,  7863,  7865,  7867,  7868,  7873,  7874,  7881,
    7884,  7893,  7897,  7904,  7904,  7908,  7908,  7913,  7913,  7917,
    7917,  7921,  7927,  7927,  7930,  7930,  7936,  7943,  7944,  7945,
    7949,  7950,  7953,  7954,  7958,  7964,  7974,  7975,  7983,  7984,
    7985,  7986,  7987,  7988,  7992,  7993,  7994,  7998,  7998,  8010,
    8011,  8015,  8016,  8017,  8018,  8019,  8020,  8021,  8022,  8023,
    8024,  8025,  8026,  8027,  8028,  8029,  8030,  8031,  8032,  8033,
    8034,  8035,  8036,  8037,  8038,  8039,  8040,  8041,  8042,  8043,
    8044,  8045,  8046,  8047,  8048,  8049,  8050,  8051,  8052,  8053,
    8054,  8055,  8056,  8057,  8058,  8059,  8060,  8061,  8062,  8063,
    8064,  8065,  8066,  8067,  8068,  8069,  8070,  8071,  8072,  8073,
    8074,  8075,  8076,  8077,  8078,  8079,  8080,  8081,  8082,  8083,
    8084,  8085,  8086,  8087,  8088,  8089,  8090,  8091,  8092,  8093,
    8094,  8095,  8096,  8097,  8098,  8099,  8100,  8101,  8102,  8103,
    8104,  8105,  8106,  8107,  8108,  8109,  8110,  8111,  8112,  8113,
    8114,  8115,  8116,  8117,  8118,  8119,  8120,  8121,  8122,  8123,
    8124,  8125,  8126,  8127,  8128,  8129,  8130,  8131,  8132,  8133,
    8134,  8135,  8136,  8137,  8138,  8139,  8140,  8141,  8142,  8143,
    8144,  8145,  8146,  8147,  8148,  8149,  8150,  8151,  8152,  8153,
    8154,  8155,  8156,  8157,  8158,  8159,  8160,  8161,  8162,  8163,
    8164,  8165,  8166,  8167,  8168,  8169,  8170,  8171,  8172,  8173,
    8174,  8175,  8176,  8177,  8178,  8179,  8180,  8181,  8182,  8183,
    8184,  8185,  8186,  8187,  8188,  8189,  8190,  8191,  8192,  8193,
    8194,  8195,  8196,  8197,  8198,  8199,  8200,  8201,  8202,  8203,
    8204,  8205,  8206,  8207,  8208,  8209,  8210,  8211,  8212,  8213,
    8214,  8215,  8216,  8217,  8218,  8219,  8220,  8221,  8222,  8223,
    8224,  8225,  8226,  8227,  8228,  8229,  8230,  8231,  8232,  8233,
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
    8334,  8342,  8342,  8349,  8349,  8437,  8441,  8437,  8450,  8454,
    8460,  8468,  8478,  8488,  8500,  8503,  8522,  8548,  8551,  8557,
    8560,  8565,  8568,  8576,  8584,  8597,  8600,  8608,  8611,  8614,
    8622,  8626,  8629,  8632,  8635,  8639,  8640,  8641,  8642,  8643,
    8649,  8650,  8651,  8652,  8653,  8654,  8655,  8656,  8657,  8658,
    8659,  8660,  8661,  8662,  8666,  8672,  8673,  8681,  8681,  8689,
    8689,  8693,  8697,  8712,  8733,  8733,  8737,  8738,  8739,  8740,
    8750,  8751,  8752,  8757,  8783,  8857,  8860,  8856,  8879,  8879,
    8883,  8884,  8887,  8888,  8889,  8890,  8891,  8892,  8893,  8898,
    8899,  8903,  8906,  8911,  8915,  8920,  8924,  8929,  8933,  8936,
    8940,  8943,  8948,  8952,  8963,  8969,  8969,  8970,  8971,  8978,
    8987,  8987,  8989,  8990,  8991,  8992,  8993,  8994,  8995,  8996,
    8997,  8998,  8999,  9000,  9001,  9002,  9003,  9004,  9005,  9006,
    9007,  9008,  9009,  9010,  9011,  9012,  9013,  9014,  9015,  9016,
    9017,  9018,  9019,  9020,  9021,  9022,  9023,  9024,  9025,  9026,
    9027,  9028,  9029,  9030,  9031,  9032,  9033,  9034,  9035,  9036,
    9037,  9038,  9039,  9040,  9041,  9042,  9043,  9044,  9045,  9046,
    9047,  9048,  9049,  9050,  9051,  9052,  9053,  9054,  9055,  9056,
    9057,  9058,  9059,  9060,  9061,  9062,  9063,  9064,  9065,  9066,
    9067,  9068,  9069,  9070,  9071,  9072,  9073,  9074,  9075,  9076
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", "CONCAT_PIPES", 
  "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", "EXECUTE_IMMEDIATE", 
  "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", 
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
  "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
  "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "KWUP_BY", "KWDOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", "CONNECT_TO", 
  "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", 
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "NO_NEW_LINES", 
  "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "CWIS", "CREATE_IDX", 
  "FORM_IS_COMPILED", "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", 
  "POINTS", "MM", "INCHES", "PREPEND", "MEMBER_OF", "MEMBER_FUNCTION", 
  "APPEND", "TEMPLATE", "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", 
  "SQLSIRR", "UPDATESTATS_T", "SQLSICR", "WHENEVER_SQLSUCCESS", 
  "WHENEVER_SQLWARNING", "WHENEVER_ANY_ERROR", "WHENEVER_NOT_FOUND", 
  "WHENEVER_SQLERROR", "WHENEVER_SUCCESS", "WHENEVER_WARNING", 
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
  "INPUT_NO_WRAP", "LOCKMODEPAGE", "SETPMOFF", "UNCONSTRAINED", 
  "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", 
  "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", "DEFAULT_NULL", 
  "DELETE_USING", "DISPLAY_FORM", "END_FUNCTION", "EXIT_DISPLAY", 
  "EXIT_FOREACH", "EXIT_PROGRAM", "INFCOLS", "LOCKMODEROW", 
  "ON_EVERY_ROW", "OPEN_SESSION", "RIGHT_MARGIN", "SELECT_USING", 
  "START_REPORT", "UNLOCK_TABLE", "UPDATE_USING", "ACL_BUILTIN", 
  "AFTGROUP", "INFIDX", "INFSTAT", "LEFT_MARGIN", "PAGE_HEADER", 
  "ROLLBACK_W", "SET_SESSION", "SQLSEOFF", "WITH_A_LOG", "BEFDISP", 
  "BEFORE_MENU", "CREATE_VIEW", "DEFINE_TYPE", "DELETE_FROM", 
  "END_DISPLAY", "END_REPORT", "END_FOREACH", "END_FOR", "END_GLOBALS", 
  "EXIT_PROMPT", "EXTENT_SIZE", "FOREIGN_KEY", "HIDE_OPTION", 
  "HIDE_WINDOW", "INSERT_INTO", "IS_NOT_NULL", "MOVE_WINDOW", 
  "NEXT_OPTION", "NOT_MATCHES", "ON_LAST_ROW", "OPEN_WINDOW", 
  "OPEN_STATUSBOX", "PAGE_LENGTH", "PAGE_WIDTH", "PRIMARY_KEY", 
  "PROMPT_LINE", "RECORD_LIKE", "ROLLFORWARD", "SETBL", "SHOW_OPTION", 
  "SHOW_WINDOW", "SQLSEON", "TO_DATABASE", "USE_SESSION", "WITH_NO_LOG", 
  "AFTDISP", "BEFFIELD", "INSHARE", "UNLOCKTAB", "AFTFIELD", "ATTRIBUTES", 
  "BEFINP", "BEGIN_WORK", "CLEARWIN", "CLOSE_FORM", "DEFER_QUIT", 
  "DESCENDING", "DROP_INDEX", "END_PROMPT", "END_RECORD", "ERROR_LINE", 
  "EXIT_INPUT", "EXIT_WHILE", "FOR_UPDATE_OF", "FOR_UPDATE", "GET_FLDBUF", 
  "INITIALIZE", "INPUT_WRAP", "LOCK_TABLE", "MSG_LINE", "NOT_EXISTS", 
  "ON_ANY_KEY", "REFERENCES", "RENCOL", "SET_CURSOR", "SMALLFLOAT", 
  "SQLSUCCESS", "TOP_MARGIN", "WITH_ARRAY", "ACCEPTKEY", "ACCEPT", 
  "AFTINP", "CLEARFORMTODEFAULTS", "CLEARFORM", "CLEAR_X_FORM", 
  "COMMIT_W", "NEXTPAGE", "PREVPAGE", "CTRL_KEY", "INFTABS", "NEXTFIELD", 
  "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", "CHAR", "CONSTRUCT", 
  "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", "END_WHILE", 
  "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", "FORM_LINE", "INTERRUPT", 
  "INTO_TEMP", "INVISIBLE", "IN_MEMORY", "LINKED_TO", "LOAD_FROM", 
  "LOCKTAB", "MENU_LINE", "OPEN_FORM", "OTHERWISE", "PRECISION", "PRIOR", 
  "PROCEDURE", "REPORT_TO", "RETURNING", "UNDERLINE", "UNLOAD_TO", 
  "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", "AFTROW", "BUFFERED", 
  "CONSTANT", "CONST", "CONTINUE", "DATABASE", "DATETIME", "DEFAULTS", 
  "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", "END_TYPE", "EXIT_FOR", 
  "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", "INTERVAL", "KWMESSAGE", 
  "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", "READONLY", 
  "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", "WITH_LOG", 
  "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", "AVERAGE", "BETWEEN", 
  "CAPTION", "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "COMMENT", "CONNECT", 
  "CURRENT", "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", 
  "ENDCODE", "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", 
  "INTEGER", "KWWINDOW", "MAGENTA", "NUMERIC", "OPTIONS", "PERCENT", 
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
  "FGL_ISDYNARR_ALLOCATED", "FGL_DYNARR_EXTENTSIZE", "$accept", 
  "pause_screen_on_cmd", "pause_screen_off_cmd", "start_rpc_cmd", 
  "stop_rpc_cmd", "valid_port", "remote_func_list", "remote_func", 
  "arr_expr", "arr_next_math", "arr_int_sign", "opt_attributes", 
  "attributes_def", "@1", "attribs_sec", "attribute", "win_attributes", 
  "win_attributes_def", "@2", "wattribs_sec", "wattribute", "call_cmd", 
  "call_ext", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", 
  "@12", "@13", "@14", "@15", "opt_return", "opt_return_remote", 
  "opt_func_call_args", "func_call_args", "func_arg", "remote_host_name", 
  "remote_func_name", "case_cmd", "@16", "@17", "when_unit", 
  "when_unit_expr", "end_case_command", "op_otherwise_command", "@18", 
  "op_otherwise_command_expr", "@19", "when_command", "@20", 
  "when_command_expr", "@21", "close_cmd", "code_cmd", "emb_code", 
  "sql_code", "sql_code_part", "c_code", "c_code_part", "comment_cmd", 
  "construct_cmd", "@22", "@23", "constr_rest", "end_constr", 
  "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@24", "@25", "@26", "@27", "@28", 
  "bef_c_field_list", "aft_c_field_list", "interval_expr", 
  "extend_parameters", "op_datetime_qual", "defer_cmd", "define_section", 
  "define_multiple", "define_set", "@29", "@30", "def_part", 
  "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@33", "@34", "@35", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@36", "@37", "@38", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@39", "@40", "dtype", 
  "like_var", "tab_name", "col_name", "datetime_qual", "interval_qual", 
  "dtime_start", "@41", "dtime_val", "dtime_end", "@42", "opt_frac", 
  "opt_unit_size", "dtfrac", "int_start", "@43", "int_start_unit", 
  "int_end", "op_equal", "dim_section", "@44", "dim_dtype", 
  "dim_like_var", "dim_array_variable", "@45", "@46", 
  "dim_record_variable", "@47", "@48", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@49", "@50", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@51", "@52", "@53", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@54", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@55", "@56", "@57", "@58", "function_callb", 
  "@59", "@60", "@61", "@62", "@63", "@64", "@65", "@66", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", "field_name_list", 
  "for_cmd", "@67", "@68", "for_step", "foreach_cmd", "@69", "@70", "@71", 
  "opt_foreach_using_part", "formhandler_def", "@72", "@73", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@74", 
  "@75", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@76", "@77", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@78", "@79", "@80", 
  "@81", "@82", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2", "cvariable", "real_number", "goto_cmd", 
  "label_goto", "check_menu_cmd", "menu_item_list", "menu_item", 
  "uncheck_menu_cmd", "disable_cmd", "enable_cmd", "msg_box_cmd", "@83", 
  "op_disable_msg", "gm_disable_msg", "op_returning_msg", 
  "gm_returning_msg", "op_caption", "gm_caption", "op_icon", "gm_icon", 
  "op_buttons", "gm_buttons", "op_def_but", "if_cmd", "@84", "@85", 
  "op_else", "@86", "@87", "@88", "import_m", "module_import", "init_cmd", 
  "@89", "init_tab_list", "init_tab", "end_input", "opt_defs", 
  "field_commands", "field_command", "@90", "@91", "@92", "@93", "@94", 
  "@95", "@96", "@97", "@98", "@99", "@100", "bef_field_list", 
  "aft_field_list", "next_field_cmd", "next_form_cmd", "next_field", 
  "input_cmd", "@101", "inp_rest", "@102", "scroll_cmd", "up_or_down", 
  "op_help", "input_array_attributes", "input_array_attributes_int", 
  "on_key_command", "@103", "key_val", "@104", "accept_key", 
  "single_key_val", "key_do", "key_value_list", "key_value", 
  "key_value_1", "label_cmd", "let_cmd", "@105", "@106", "op_expr_null", 
  "linked_cmd", "linked_del_cmd", "linked_upd_cmd", "locate_cmd", 
  "module", "@107", "op_module_header", "module_header", "module_entry", 
  "func_main_def", "func_or_main2", "at_term_cmd", "func_or_main", 
  "module_code", "op_code", "module_define_section", "ldeffunction", 
  "func_def", "@108", "@109", "@110", "@111", "end_func_command", 
  "main_def", "@112", "@113", "return_cmd", "op_fgl_expr_list", 
  "db_section", "module_globals_section", "actual_globals_section", 
  "xglobals_entry", "globals_entry", "@114", "glob_section", 
  "mem_func_def", "@115", "@116", "@117", "menu_cmd", "@118", 
  "end_menu_command", "menu_block_command", "@119", "@120", "@121", 
  "menu_commands", "opt_key", "menu_opt_name", "menu_optional_desc", 
  "next_option_cmd", "show_option_cmd", "hide_option_cmd", "opt_name", 
  "opt_name_list", "menu_title", "menu_def", "@122", "@123", 
  "menu_handler_elements", "menu_handler_element", "@124", "@125", 
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
  "@126", "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@127", "prompt_title", 
  "put_cmd", "@128", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@129", "@130", "@131", "@132", "@133", "@134", "@135", 
  "report_cmd", "need_command", "@136", "op_lines", "skip_command", 
  "@137", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@138", "@139", "@140", "@141", "@142", 
  "@143", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@144", "@145", "@146", "@147", "@148", "@149", "pdf_report_section", 
  "pdf_functions", "@150", "@151", "@152", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@153", "@154", 
  "@155", "@156", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@157", "ins_2_ss", "@158", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@159", "@160", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@161", "opt_foreach_into_fetch_part", "@162", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@163", 
  "sql_commands", "privilege_definition", "op_with_grant_option", 
  "privileges", "action_list", "action", "op_grant_column_list", 
  "grant_column_list", "grantee_list", "grantee", "view_definition_ss", 
  "op_view_column_list", "view_column_list", "op_with_check_option", 
  "check_constraint_definition_ss", "referential_constraint_definition", 
  "references_specification", "references_columns", 
  "referenced_table_and_columns", "references_column_list", 
  "unique_constraint_definition", "unique_column_list", 
  "table_constraint_definition_ss", "default_clause", 
  "ct_column_definiton_ss", "op_default_clause", 
  "op_column_constraint_list_ss", "column_constraint_list_ss", 
  "column_constraint_ss", "schema_ss", "schema_authorization_clause", 
  "schema_authorization_identifier", "schema_element_list_ss", 
  "schema_element_ss", "having_clause_ss", "group_by_clause_ss", 
  "column_specification_list_ss", "where_clause_ss", "from_clause", 
  "table_reference_list", "table_reference", "tname", "tname_list", 
  "table_expression_ss", "op_where_clause_ss", "op_group_by_clause_ss", 
  "op_having_clause_ss", "search_condition_ss", "boolean_term_ss", 
  "boolean_factor_ss", "boolean_primary_ss", "exists_predicate_ss", 
  "op_escape", "pattern_ss", "escape_character", "in_predicate_ss", 
  "in_value_list", "in_value_specification", "op_not", 
  "comparison_predicate_ss", "comp_op", "predicate_ss", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "authorization_identifier", "col_arr", "column_name", 
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@164", 
  "@165", "@166", "@167", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@168", "@169", 
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
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@170", "sql_block", 
  "sql_block_entry", "in_var", "@171", "sql_block_into", "@172", 
  "update_statement_ss", "@173", "@174", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "validate_cmd", "@175", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "while_cmd", "@176", "@177", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "fld_list", "current_win_cmd", "window_type", 
  "show_cmd", "op_mnfile", "menu_name", "menu_handler", "hide_cmd", 
  "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@178", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1695,  1696,  1697,  1603,  1643,  1598,  1535,  1618,
    1414,  1521,  1517,  1432,  1593,  1331,  1389,  1463,  1629,  1616,
    1522,  1549,  1617,  1396,  1698,  1699,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,
    1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,
    1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,  1386,
    1387,  1388,  1390,  1391,  1392,  1393,  1394,  1395,  1397,  1398,
    1399,  1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,
    1409,  1410,  1411,  1412,  1413,  1415,  1416,  1417,  1418,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
    1461,  1462,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,  1491,
    1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,  1501,
    1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1518,  1519,  1520,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1536,  1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,
    1546,  1547,  1548,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,
    1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,  1594,  1595,  1596,  1597,
    1599,  1600,  1601,  1602,  1604,  1605,  1606,  1607,  1608,  1609,
    1610,  1611,  1612,  1613,  1614,  1615,  1619,  1620,  1621,  1622,
    1623,  1624,  1625,  1626,  1627,  1628,  1630,  1631,  1632,  1633,
    1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   710,   711,   712,   713,   714,   715,   715,   716,   716,
     717,   718,   718,   718,   718,   718,   718,   719,   719,   719,
     719,   719,   720,   720,   721,   721,   723,   722,   722,   724,
     724,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     725,   725,   725,   725,   725,   725,   725,   725,   726,   726,
     728,   727,   729,   729,   730,   730,   730,   730,   730,   730,
     730,   730,   730,   731,   732,   733,   732,   732,   732,   732,
     732,   734,   735,   732,   736,   737,   738,   732,   739,   740,
     732,   741,   742,   732,   743,   744,   745,   732,   746,   746,
     747,   747,   747,   748,   748,   749,   749,   750,   751,   751,
     752,   752,   754,   753,   755,   753,   756,   756,   757,   757,
     758,   759,   760,   759,   761,   762,   761,   764,   763,   766,
     765,   767,   767,   767,   767,   767,   767,   768,   769,   769,
     770,   770,   771,   772,   772,   773,   774,   776,   777,   775,
     778,   778,   779,   779,   780,   780,   781,   781,   781,   782,
     782,   784,   783,   785,   783,   786,   783,   787,   783,   788,
     783,   789,   789,   790,   790,   791,   791,   791,   791,   791,
     791,   792,   793,   793,   794,   794,   795,   795,   796,   796,
     798,   799,   797,   797,   800,   800,   802,   801,   803,   803,
     803,   803,   803,   804,   803,   805,   805,   805,   805,   806,
     807,   807,   808,   808,   809,   809,   809,   809,   811,   810,
     812,   810,   813,   810,   814,   814,   815,   815,   816,   817,
     817,   817,   818,   820,   819,   821,   819,   822,   819,   823,
     823,   824,   825,   826,   826,   828,   829,   827,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   831,   832,   833,   834,
     834,   835,   837,   836,   838,   838,   838,   838,   838,   838,
     838,   840,   839,   841,   841,   842,   842,   843,   845,   844,
     846,   846,   846,   846,   846,   846,   846,   847,   848,   848,
     850,   849,   851,   851,   851,   851,   851,   851,   851,   851,
     851,   851,   851,   851,   851,   851,   851,   851,   851,   851,
     851,   851,   851,   851,   851,   852,   854,   853,   855,   853,
     857,   856,   858,   856,   859,   859,   860,   861,   861,   862,
     863,   863,   863,   863,   863,   863,   863,   863,   864,   865,
     866,   868,   869,   867,   870,   870,   871,   872,   872,   872,
     873,   873,   875,   874,   876,   874,   877,   874,   878,   879,
     880,   881,   881,   882,   882,   882,   882,   882,   882,   882,
     882,   882,   883,   883,   883,   883,   883,   883,   883,   883,
     884,   884,   885,   885,   885,   885,   885,   885,   885,   885,
     885,   885,   886,   886,   886,   886,   886,   886,   886,   886,
     886,   886,   886,   887,   887,   888,   888,   889,   889,   890,
     890,   891,   891,   892,   893,   893,   894,   894,   894,   894,
     894,   894,   895,   895,   896,   896,   896,   896,   897,   897,
     898,   899,   899,   899,   900,   899,   901,   901,   902,   902,
     903,   903,   903,   903,   904,   904,   905,   905,   905,   905,
     905,   905,   905,   905,   906,   907,   908,   908,   908,   908,
     908,   908,   909,   909,   909,   909,   909,   909,   909,   910,
     912,   913,   911,   914,   915,   911,   917,   918,   916,   919,
     920,   916,   921,   922,   916,   923,   924,   916,   916,   916,
     916,   916,   916,   916,   925,   925,   926,   927,   927,   927,
     927,   927,   927,   927,   927,   927,   928,   928,   929,   929,
     929,   929,   930,   930,   930,   931,   931,   932,   932,   932,
     933,   933,   933,   933,   933,   933,   933,   933,   933,   933,
     934,   934,   935,   935,   937,   938,   936,   939,   939,   941,
     942,   943,   940,   944,   944,   946,   947,   945,   948,   948,
     949,   949,   950,   950,   952,   951,   953,   951,   954,   954,
     955,   955,   957,   956,   958,   956,   959,   960,   960,   960,
     961,   961,   962,   962,   963,   963,   964,   964,   966,   965,
     967,   965,   968,   965,   969,   965,   970,   965,   971,   972,
     972,   972,   972,   972,   972,   972,   973,   973,   974,   975,
     976,   977,   977,   977,   977,   977,   977,   977,   977,   978,
     979,   980,   981,   982,   983,   984,   984,   985,   986,   987,
     987,   988,   988,   989,   989,   989,   989,   989,   989,   990,
     991,   991,   992,   993,   993,   994,   995,   995,   996,   997,
     998,   998,   998,   999,   999,   999,  1001,  1000,  1002,  1002,
    1003,  1003,  1004,  1004,  1005,  1006,  1006,  1007,  1008,  1008,
    1009,  1010,  1010,  1011,  1012,  1012,  1014,  1015,  1013,  1016,
    1017,  1016,  1018,  1019,  1016,  1020,  1020,  1021,  1023,  1022,
    1022,  1024,  1024,  1025,  1025,  1026,  1026,  1026,  1027,  1027,
    1028,  1028,  1030,  1029,  1031,  1029,  1032,  1029,  1033,  1029,
    1034,  1029,  1035,  1029,  1036,  1029,  1037,  1029,  1038,  1029,
    1039,  1029,  1040,  1029,  1041,  1041,  1042,  1042,  1043,  1044,
    1045,  1045,  1045,  1047,  1046,  1048,  1048,  1049,  1048,  1050,
    1051,  1051,  1051,  1051,  1052,  1052,  1053,  1054,  1054,  1054,
    1054,  1054,  1054,  1054,  1054,  1054,  1056,  1055,  1055,  1058,
    1057,  1059,  1060,  1061,  1061,  1062,  1062,  1063,  1064,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1065,  1067,  1068,  1066,
    1069,  1069,  1070,  1071,  1072,  1073,  1073,  1075,  1074,  1076,
    1076,  1077,  1077,  1078,  1078,  1078,  1078,  1079,  1079,  1080,
    1080,  1081,  1082,  1082,  1082,  1082,  1082,  1082,  1082,  1082,
    1082,  1082,  1083,  1084,  1084,  1085,  1086,  1086,  1088,  1089,
    1090,  1091,  1087,  1092,  1094,  1095,  1093,  1096,  1097,  1097,
    1098,  1098,  1099,  1100,  1100,  1101,  1101,  1101,  1103,  1102,
    1104,  1104,  1106,  1107,  1108,  1105,  1110,  1109,  1111,  1113,
    1112,  1114,  1112,  1115,  1112,  1116,  1116,  1117,  1117,  1118,
    1118,  1119,  1119,  1119,  1120,  1121,  1122,  1123,  1123,  1123,
    1124,  1124,  1125,  1125,  1127,  1128,  1126,  1129,  1129,  1131,
    1130,  1132,  1130,  1133,  1134,  1134,  1134,  1134,  1135,  1135,
    1135,  1135,  1135,  1136,  1137,  1137,  1138,  1139,  1140,  1140,
    1141,  1142,  1142,  1142,  1142,  1142,  1142,  1143,  1144,  1145,
    1145,  1146,  1146,  1147,  1148,  1149,  1149,  1150,  1150,  1151,
    1152,  1153,  1153,  1153,  1153,  1153,  1153,  1154,  1154,  1155,
    1156,  1156,  1157,  1157,  1158,  1158,  1159,  1159,  1160,  1160,
    1160,  1160,  1160,  1161,  1161,  1162,  1162,  1163,  1163,  1164,
    1165,  1166,  1166,  1167,  1168,  1168,  1168,  1169,  1170,  1170,
    1171,  1171,  1172,  1173,  1173,  1174,  1174,  1175,  1176,  1177,
    1178,  1178,  1179,  1180,  1180,  1181,  1181,  1182,  1182,  1183,
    1184,  1184,  1185,  1185,  1185,  1185,  1186,  1186,  1186,  1187,
    1188,  1188,  1189,  1189,  1189,  1190,  1191,  1191,  1192,  1192,
    1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,
    1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,  1192,
    1193,  1194,  1194,  1195,  1195,  1195,  1196,  1198,  1197,  1199,
    1199,  1200,  1201,  1201,  1202,  1202,  1203,  1203,  1205,  1204,
    1206,  1208,  1207,  1209,  1209,  1210,  1210,  1211,  1211,  1212,
    1212,  1212,  1212,  1213,  1213,  1214,  1215,  1215,  1216,  1217,
    1218,  1219,  1220,  1220,  1221,  1221,  1223,  1222,  1224,  1222,
    1225,  1222,  1226,  1222,  1227,  1222,  1228,  1222,  1229,  1222,
    1230,  1230,  1230,  1230,  1230,  1230,  1232,  1231,  1233,  1233,
    1235,  1234,  1234,  1234,  1234,  1234,  1236,  1236,  1237,  1237,
    1238,  1239,  1239,  1240,  1241,  1242,  1243,  1243,  1243,  1244,
    1244,  1244,  1244,  1245,  1246,  1246,  1247,  1247,  1248,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1250,  1250,  1251,
    1251,  1252,  1252,  1252,  1252,  1252,  1252,  1252,  1252,  1252,
    1252,  1253,  1253,  1254,  1254,  1254,  1254,  1255,  1255,  1256,
    1256,  1257,  1257,  1257,  1257,  1257,  1257,  1257,  1257,  1257,
    1257,  1257,  1257,  1257,  1257,  1257,  1257,  1257,  1257,  1257,
    1257,  1257,  1257,  1257,  1257,  1258,  1258,  1258,  1260,  1261,
    1262,  1263,  1264,  1265,  1259,  1266,  1266,  1267,  1268,  1268,
    1270,  1271,  1272,  1273,  1274,  1275,  1269,  1276,  1278,  1279,
    1280,  1277,  1281,  1281,  1281,  1281,  1282,  1282,  1282,  1282,
    1282,  1283,  1284,  1284,  1284,  1285,  1285,  1287,  1288,  1286,
    1289,  1290,  1286,  1291,  1291,  1292,  1292,  1293,  1293,  1294,
    1294,  1294,  1295,  1295,  1296,  1296,  1297,  1297,  1298,  1299,
    1299,  1300,  1300,  1300,  1300,  1300,  1300,  1300,  1301,  1301,
    1302,  1302,  1303,  1303,  1304,  1304,  1305,  1305,  1306,  1307,
    1307,  1308,  1308,  1309,  1310,  1310,  1311,  1312,  1312,  1313,
    1313,  1314,  1314,  1315,  1316,  1316,  1316,  1316,  1316,  1316,
    1316,  1316,  1316,  1316,  1316,  1317,  1317,  1318,  1318,  1319,
    1320,  1322,  1321,  1324,  1323,  1323,  1325,  1325,  1326,  1326,
    1327,  1327,  1328,  1328,  1330,  1331,  1329,  1332,  1333,  1333,
    1334,  1335,  1334,  1336,  1337,  1336,  1338,  1338,  1338,  1338,
    1338,  1338,  1338,  1338,  1339,  1340,  1341,  1342,  1342,  1343,
    1344,  1344,  1345,  1345,  1345,  1346,  1347,  1348,  1348,  1349,
    1350,  1350,  1350,  1352,  1351,  1353,  1353,  1353,  1353,  1353,
    1353,  1353,  1353,  1353,  1353,  1353,  1353,  1354,  1355,  1355,
    1356,  1356,  1357,  1357,  1358,  1358,  1358,  1358,  1359,  1359,
    1360,  1360,  1361,  1361,  1362,  1362,  1363,  1364,  1364,  1365,
    1365,  1366,  1366,  1367,  1368,  1369,  1370,  1371,  1371,  1372,
    1372,  1373,  1373,  1374,  1374,  1375,  1375,  1375,  1376,  1376,
    1377,  1378,  1378,  1379,  1379,  1380,  1380,  1381,  1381,  1381,
    1381,  1381,  1382,  1383,  1384,  1385,  1385,  1386,  1386,  1387,
    1388,  1389,  1389,  1390,  1391,  1392,  1392,  1393,  1393,  1393,
    1394,  1394,  1395,  1395,  1396,  1397,  1397,  1398,  1398,  1399,
    1399,  1400,  1400,  1401,  1401,  1402,  1402,  1403,  1403,  1404,
    1404,  1405,  1405,  1406,  1407,  1408,  1408,  1408,  1408,  1409,
    1409,  1410,  1410,  1411,  1411,  1412,  1412,  1412,  1412,  1412,
    1412,  1412,  1412,  1412,  1413,  1413,  1413,  1413,  1413,  1413,
    1413,  1413,  1413,  1414,  1414,  1414,  1415,  1415,  1415,  1415,
    1416,  1416,  1416,  1417,  1417,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1419,  1419,  1420,  1420,  1420,  1420,  1420,  1421,
    1422,  1423,  1424,  1424,  1424,  1424,  1425,  1426,  1426,  1426,
    1427,  1427,  1428,  1428,  1428,  1429,  1430,  1430,  1430,  1430,
    1430,  1431,  1432,  1433,  1433,  1434,  1434,  1435,  1435,  1435,
    1435,  1435,  1435,  1435,  1435,  1436,  1436,  1436,  1436,  1436,
    1436,  1436,  1436,  1437,  1437,  1437,  1437,  1437,  1437,  1437,
    1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1439,  1439,
    1439,  1440,  1442,  1441,  1443,  1441,  1444,  1441,  1445,  1441,
    1446,  1446,  1446,  1447,  1447,  1448,  1448,  1448,  1449,  1449,
    1450,  1450,  1451,  1453,  1454,  1452,  1455,  1456,  1456,  1457,
    1458,  1458,  1458,  1458,  1458,  1459,  1460,  1460,  1461,  1462,
    1463,  1463,  1463,  1463,  1464,  1464,  1465,  1465,  1466,  1467,
    1467,  1467,  1468,  1468,  1468,  1468,  1468,  1469,  1469,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,  1470,  1471,
    1472,  1473,  1473,  1474,  1474,  1475,  1475,  1476,  1476,  1477,
    1477,  1478,  1479,  1479,  1480,  1480,  1481,  1482,  1482,  1482,
    1483,  1483,  1484,  1485,  1486,  1487,  1488,  1488,  1489,  1489,
    1489,  1489,  1489,  1489,  1490,  1490,  1490,  1492,  1491,  1493,
    1493,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1496,  1495,  1498,  1497,  1500,  1501,  1499,  1502,  1502,
    1502,  1503,  1503,  1503,  1503,  1503,  1503,  1504,  1504,  1505,
    1506,  1507,  1507,  1508,  1508,  1509,  1509,  1510,  1510,  1510,
    1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,  1511,
    1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,  1512,
    1512,  1512,  1512,  1512,  1513,  1514,  1514,  1516,  1515,  1517,
    1517,  1518,  1518,  1519,  1520,  1520,  1521,  1521,  1521,  1521,
    1522,  1522,  1522,  1523,  1523,  1525,  1526,  1524,  1527,  1527,
    1528,  1528,  1529,  1529,  1529,  1529,  1529,  1529,  1529,  1530,
    1530,  1531,  1531,  1532,  1532,  1533,  1533,  1534,  1534,  1535,
    1536,  1537,  1538,  1538,  1539,  1540,  1540,  1541,  1542,  1542,
    1544,  1543,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,
    1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545,  1545
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
       1,     4,     4,     6,     1,     2,     1,     1,     1,     1,
       4,     6,     1,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     1,     1,     0,
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
       2,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
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
       1,     3,     1,     3,     0,     0,    11,     0,     2,     0,
       0,     0,     9,     0,     3,     0,     0,    10,     0,     1,
       0,     1,     1,     2,     0,     3,     0,     3,     0,     1,
       1,     2,     0,     3,     0,     3,     3,     1,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     0,     3,
       0,     3,     0,     4,     0,     4,     0,     4,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     4,     6,     4,     3,     6,     3,     6,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       4,     1,     1,     1,     4,     3,     6,     3,     6,     1,
       1,     2,     2,     1,     2,     2,     1,     3,     1,     2,
       2,     2,     4,     2,     2,     4,     0,     8,     0,     1,
       1,     1,     0,     1,     2,     0,     1,     2,     0,     1,
       2,     0,     1,     3,     0,     2,     0,     0,     8,     0,
       0,     3,     0,     0,     7,     5,     2,     2,     0,     5,
       4,     1,     3,     3,     3,     0,     2,     1,     0,     1,
       1,     2,     0,     4,     0,     4,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     1,     3,     1,     3,     2,     4,
       1,     1,     1,     0,     4,     5,     6,     0,    10,     3,
       2,     2,     1,     1,     0,     2,     1,     2,     3,     3,
       3,     3,     1,     1,     1,     1,     0,     3,     1,     0,
       3,     2,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     7,
       1,     1,     2,     2,     2,     3,     4,     0,     3,     0,
       1,     1,     2,     1,     1,     1,     1,     0,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     0,     0,
       0,     0,    13,     1,     0,     0,     6,     2,     1,     2,
       2,     2,     1,     1,     2,     1,     1,     1,     0,     3,
       2,     1,     0,     0,     0,    14,     0,     5,     1,     0,
       3,     0,     7,     0,     5,     1,     2,     0,     1,     1,
       1,     0,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     0,     0,     7,     1,     2,     0,
       3,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     2,
       2,     2,     5,     8,     1,     1,     1,     4,     4,     1,
       1,     1,     1,     2,     2,     3,     6,     1,     3,     1,
       1,     1,     3,     6,     9,     1,     1,     1,     1,     2,
       0,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     3,     2,     0,     1,     1,     4,     1,     3,
       1,     3,     7,     0,     7,     0,     6,     3,     1,     3,
       1,     2,     5,     0,     7,     0,     2,     0,     1,     5,
       2,     5,     0,     5,     6,     4,     0,     1,     1,     4,
       0,     2,     0,     5,     4,     2,     1,     3,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     2,     4,     2,     1,     0,    11,     0,
       2,     5,     0,     1,     0,     2,     1,     2,     0,     3,
       1,     0,     4,     0,     2,     1,     3,     1,     1,     3,
       4,     4,     2,     1,     1,     1,     0,     1,     7,     2,
       2,     2,     2,     2,     1,     2,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     1,
       0,     4,     1,     2,     2,     2,     0,     1,     1,     2,
       2,     0,     2,     3,     3,     5,     0,     2,     4,     1,
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
       3,     1,     1,     1,     1,     1,     1,     0,     0,     7,
       0,     0,     8,     7,     2,     0,     1,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     3,     1,     3,     2,     4,     1,     3,     1,     2,
       4,     1,     3,     1,     1,     1,     2,     2,     4,     2,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     6,     6,     0,     1,     0,     1,     2,
       1,     0,     5,     0,     5,     1,     0,     3,     1,     3,
       1,     3,     1,     1,     0,     0,     5,     1,     2,     1,
       0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     3,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     0,     1,
       1,     1,     1,     3,     1,     1,     1,     2,     0,     3,
       1,     3,     1,     3,     1,     1,     6,     0,     3,     1,
       3,     0,     1,     4,     5,     2,     1,     1,     4,     1,
       3,     4,     4,     1,     3,     1,     1,     1,     2,     1,
       4,     0,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     4,     3,     1,     1,     1,     2,     1,     1,     2,
       2,     1,     3,     2,     2,     1,     3,     1,     2,     4,
       1,     2,     1,     3,     4,     0,     1,     0,     1,     0,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     2,
       2,     0,     2,     1,     1,     5,     3,     5,     3,     1,
       3,     1,     1,     0,     1,     3,     3,     3,     6,     4,
       4,     4,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     1,     5,     5,     1,
       1,     1,     4,     1,     4,     1,     7,     1,     1,     1,
       4,     6,     0,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     1,     0,     3,     5,
       1,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     3,     0,     7,     0,     8,     0,     6,     0,     8,
       0,     1,     2,     1,     3,     1,     3,     5,     1,     1,
       1,     1,     1,     0,     0,     9,     5,     1,     1,     6,
       0,     3,     1,     3,     4,     1,     0,     2,     4,     6,
       0,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     2,     4,     3,     2,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     4,     4,     3,     4,     1,     3,     1,
       5,     7,     5,     0,     2,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       4,     6,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     0,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     0,     3,     0,     3,     0,     0,     6,     0,     2,
       2,     7,     3,     3,     2,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     2,
       1,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     3,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     1,     3,     0,     5,     1,
       3,     3,     3,     1,     2,     1,     1,     1,     3,     5,
       1,     1,     1,     1,     3,     0,     0,     6,     0,     2,
       0,     1,     1,     2,     2,     1,     1,     4,     3,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     799,     0,     0,     0,     0,   848,   180,     0,   822,   825,
     178,   183,   803,     0,   797,   800,   801,   804,   806,   847,
     805,   842,   843,   845,   135,   132,     0,   128,   130,   129,
     133,  2134,   687,   627,   300,  1590,  1588,   840,   176,   186,
     841,   179,     1,   807,   802,   846,   844,   127,   131,   134,
       0,     0,   606,     0,     0,   177,   851,   915,   607,   849,
     639,   907,     0,   908,   916,   914,   186,   181,   199,     0,
     184,   200,   235,     0,   827,  1200,     0,     0,   826,   136,
    1188,   834,     0,     0,   819,   821,   818,   820,   798,   808,
     809,   828,   812,   813,   814,   817,   815,   816,     0,  1589,
     909,   850,     0,     0,   923,   921,   922,   911,   910,   298,
     186,  1124,   193,   187,   186,   192,   232,     0,   686,     0,
       0,     0,     0,   176,   555,   884,   810,     0,   332,   318,
     202,   304,   269,   288,   309,   311,   308,     0,   330,     0,
     317,   310,   314,   320,   319,   186,   321,   301,   324,   302,
     303,   920,   919,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   929,     0,   515,   507,
      16,   514,   915,    15,     0,   927,     0,   299,     0,   185,
    1125,   182,     0,   199,   201,   265,   204,   259,   260,   248,
     225,   256,   202,   240,   227,   269,   288,   246,   249,   244,
       0,   223,     0,   255,   247,   252,   258,   257,   186,   261,
     186,   238,   239,   236,   264,     0,     0,     0,     0,   835,
     176,   176,     0,     0,   203,     0,     0,   322,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,   267,     0,
     917,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,     0,     0,     0,   640,   434,   436,
    1195,     0,     0,     0,  1555,     0,   428,     0,     0,     0,
     427,     0,   444,   517,     0,     0,     0,     0,     0,   520,
       0,   393,   392,   399,   440,   437,   394,   395,   397,   398,
     435,   438,   443,   516,   489,   486,   495,   492,     0,     0,
      17,    18,    19,    20,    21,     0,    14,   480,     0,     0,
     925,     0,   188,   191,   189,   190,     0,   196,   195,   194,
     197,   205,   206,   207,   210,   186,     0,     0,   186,   262,
     263,     0,     0,   186,     0,     0,     0,   245,   233,  1201,
       0,     0,  1189,  2140,   556,   885,   829,     0,   214,   215,
       0,     0,   281,   283,   278,   279,   275,   277,   274,   276,
     273,     0,   283,   294,   295,   291,   293,   290,   292,   285,
       0,     0,     0,   334,     0,   337,   339,   222,     0,   221,
       0,   186,     0,  2119,   611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   539,   525,   530,     0,   526,   529,
     528,     0,     0,    11,   172,   426,   401,   400,     0,  1130,
       0,     0,   442,  1563,  1561,  1562,  1558,  1560,  1557,  1559,
    1551,     0,     0,     0,   441,     0,     0,     0,     0,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   522,   523,   524,   455,
       0,     0,   454,   464,     0,     0,   405,     0,     0,   406,
     396,   402,   404,   407,   408,   409,   410,   411,   403,   433,
     432,     0,     0,     0,     0,     0,     0,     0,    12,    93,
       0,   928,     0,   912,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   234,   237,   940,   685,
     852,   940,     0,  2138,  2140,  1124,  1684,   823,     0,   940,
       0,     0,   305,   270,     0,     0,   280,   297,   271,   296,
       0,   289,     0,   312,     0,   306,     0,   331,     0,   336,
     326,     0,     0,   315,   268,   325,     0,     0,     0,     0,
     513,   510,   509,   512,   508,   519,   504,   504,     0,   527,
       0,   531,     0,   288,   511,   518,   272,     0,  1196,  1630,
       0,     0,     0,     0,     0,   429,     0,     0,   445,     0,
       0,     0,     0,   447,   446,   465,   456,   471,   474,   475,
     472,   478,   477,   476,   466,   467,   468,   469,   470,   412,
     457,   461,   479,   473,   460,   479,   439,   490,   487,   496,
     493,   502,     0,   481,    94,    95,    97,   483,     0,     0,
     235,     0,     0,   241,     0,     0,   250,     0,   242,   224,
     208,     0,   253,   266,   946,     0,   941,   942,   940,     0,
     836,  2139,  2137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2121,     0,  1290,  1289,     0,
    1291,     0,   386,  1288,  1230,     0,     5,  1287,   387,   384,
       0,   389,   174,   479,  1102,     0,     0,  1297,   124,   383,
     382,  1222,   377,   479,     0,  1247,  2112,     0,   388,   351,
       0,     3,     2,     0,   385,  1227,     0,     0,   378,   375,
     390,     0,     0,     0,     0,  1295,  1285,   381,     0,     0,
       0,     0,     0,     0,     0,     0,  1284,     0,     0,     0,
     175,  1224,   374,   373,     0,     0,  2116,  2115,     0,     0,
       0,   137,  1223,   380,   379,     0,     0,   376,   479,     0,
     479,     0,   549,     0,     0,     0,     0,     0,     0,   479,
     786,  1198,     0,     0,  1106,     0,  2105,     0,   104,     0,
       0,   856,     0,     0,     0,     0,   787,     0,     0,  1707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   656,
       0,     0,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,  2171,  2172,  2173,  2174,  2175,  2176,  2177,  2178,  2179,
    2180,  2181,  2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,
    2190,  2191,   894,  2192,  2193,  2194,  2195,  2196,  2197,  2198,
    2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,  2207,  2208,
    1093,  1095,  1090,  1092,  1091,  1094,  2209,  2210,  1221,  2211,
    1226,  1225,  2212,  2213,  2214,  2215,  2216,  2217,  2218,  2219,
    2220,  2221,  1353,  2222,  2223,  2224,  2225,  2226,  2227,  2228,
    2229,  2141,   824,   560,     0,   889,     0,   887,     0,   333,
     216,   217,     0,   282,   287,     0,     0,     0,     0,   335,
     338,     0,   220,     0,     0,     0,   615,     0,   617,  2120,
     499,     0,   500,     0,   541,     0,   538,   535,   506,   498,
       0,   171,  1632,  1633,  1631,     0,   431,  1195,     0,  1556,
    1195,   430,  1195,  1195,  1195,  1195,  1195,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,   926,     0,   211,   226,     0,   186,     0,
       0,     0,     0,     0,  1202,     0,     0,  1190,   370,   368,
     369,  1032,  1031,  1035,     0,     0,  1234,   628,   629,   811,
    1065,  1070,  2114,   621,   123,     0,     0,  2097,  2096,  1000,
    2093,  2095,  2129,     0,  1533,  1534,     0,  1246,     7,     0,
       6,     0,  2122,  1066,     0,  1158,  1157,  1105,  1156,  1104,
     423,  1298,  1286,   837,   413,  1686,  1292,   125,     0,  1069,
     122,     0,   793,    24,   623,   391,     0,   792,  1062,   794,
       0,  1296,   878,   877,   880,   876,   879,  2131,     0,   874,
       0,   622,   973,   875,  2125,     0,  2113,   121,   970,   688,
     968,     0,   619,  2108,   731,   730,   732,   728,     0,     0,
     983,   624,  1352,  1347,  1350,     0,     0,     0,  1036,  1033,
       0,  1027,  1029,  1028,  1026,  1025,     0,     0,     0,  1024,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1014,  1005,  1006,     0,  1050,   421,    24,
       0,  2110,   126,   620,     0,  1199,  1197,  1123,     0,  1675,
    1676,  1124,  1212,  1124,  1107,  1108,  1111,  1126,  1299,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,   915,
       0,    69,     0,   102,   598,     0,   643,   642,     0,  1096,
     990,  1100,     0,     0,  1051,  1216,     0,     0,  1103,   648,
     645,   646,     0,   650,   651,     0,   653,   654,     0,   649,
     950,   952,     0,     0,   951,   733,   948,   698,   944,   906,
       0,     0,     0,     0,   660,   661,     0,     0,   904,   901,
     902,   898,   899,   900,   893,   897,   896,     0,     0,     0,
       0,     0,     0,   564,   566,   558,   561,   562,   891,  2140,
     886,   888,   830,     0,   284,   286,   313,   307,     0,     0,
     316,   612,   614,     0,     0,   504,   532,     0,   281,     0,
       0,  1656,  1546,  1549,  1657,  1553,  1547,  1654,     0,     0,
    1653,     0,     0,  1655,     0,     0,     0,     0,     0,  2097,
    1548,  1652,  1550,  1644,     0,  1634,  1636,  1639,  1642,  2103,
    1643,  1133,  1564,  1132,  1131,  1134,  1136,  1135,  1129,   458,
     459,   463,   448,     0,   451,   462,     0,   450,   491,   488,
     497,   494,   503,   482,    96,   484,   913,     0,   231,     0,
     229,   251,   243,   235,   254,   947,   176,   943,   853,   176,
       0,     0,     0,  1274,  1275,     0,     0,     0,  1248,  1249,
    1251,  1252,  1253,  1257,  1256,  1254,  1255,     0,     0,  2094,
     924,     0,  1002,     0,     0,     0,     0,     0,     0,     0,
    1067,     0,    24,  1153,  1155,  1154,   416,   417,   414,   415,
     960,     0,     0,   356,    25,   350,     0,     0,  1059,     0,
       0,     0,     0,     0,     0,     0,   977,  1685,     0,     0,
     186,     0,     0,     0,  2110,     0,     0,   138,     0,     0,
     987,   979,   980,   985,  1348,  1349,     0,   903,   419,  2087,
     340,     0,   550,   603,   602,   600,   605,  1008,   604,  1013,
    1009,  1012,   785,   777,   771,   783,   784,   769,   770,   778,
     773,   779,   772,   782,   776,   780,   775,   781,   768,   774,
     761,   767,  1010,  1011,     0,  1018,  1022,  1015,  1016,  1020,
    1021,  1019,  1017,  1023,     0,   795,     0,     0,     0,     0,
       0,   743,   742,   739,  2111,  2118,    24,  1119,  1120,  1121,
    1122,  1116,  1114,  1213,  1128,  1113,  1109,     0,     0,  1110,
    2106,     0,     0,     0,     0,    98,     0,    99,     0,     0,
       0,    74,     0,     0,     0,   111,   106,     0,   644,   883,
       0,   882,     0,   479,  1098,     0,   935,   936,   959,   930,
     931,   788,   957,  1053,  1218,     0,  1220,  1219,  1763,  1880,
    1876,  1882,  1914,  1894,  1885,  1844,  1806,  1934,  1900,  1908,
    1797,  1903,  1764,  1711,  1895,  1802,  1853,  1988,  1832,  1820,
    1833,  1932,  1935,  1902,  1856,  1938,  1723,  1995,  1931,  1959,
    1734,  2031,  1821,  2004,  1716,  1964,  1732,  1792,  1839,  1859,
    1954,  1982,  1987,  1715,  1911,  1940,  1727,  1729,  1752,  1770,
    1790,  1800,  1810,  1863,  1866,  1925,  1936,  1942,  1943,  1960,
    2005,  2016,  1714,  1745,  1769,  1768,  1776,  1778,  1786,  1796,
    1817,  1835,  1838,  1864,  1872,  1929,  1939,  1949,  1955,  1956,
    1958,  1983,  2013,  2024,  1735,  1738,  1749,  1755,  1757,  1762,
    1765,  1767,  1773,  1781,  1783,  1784,  1785,  1795,  1805,  1812,
    1828,  1829,  1840,  1858,  1862,  1875,  1891,  1915,  1923,  1933,
    1937,  1944,  1952,  1961,  1971,  1975,  1992,  1998,  2002,  2010,
    2015,  2018,  1758,  1877,  1920,  1743,  1744,  1761,  1766,  1772,
    1774,  1788,  1789,  1799,  1808,  1813,  1815,  1816,  1822,  1830,
    1847,  1848,  1861,  1889,  1893,  1896,  1901,  1905,  1913,  1921,
    1922,  1927,  1945,  1946,  1951,  1957,  1962,  1968,  1969,  1970,
    1972,  1974,  1976,  1985,  2007,  2008,  2009,  2014,  2030,  1718,
    1871,  1879,  1881,  1978,  1720,  1724,  1728,  1733,  1739,  1740,
    1753,  1754,  1756,  1759,  1771,  1787,  1807,  1809,  1819,  1823,
    1825,  1826,  1834,  1843,  1845,  1846,  1857,  1870,  1888,  1906,
    1907,  1924,  1926,  1930,  1941,  1963,  1973,  1981,  2003,  2006,
    2020,  2021,  2022,  1751,  1721,  1741,  1742,  1748,  1818,  1750,
    1775,  1777,  1791,  1868,  1993,  1801,  1803,  1811,  1814,  1836,
    1837,  1842,  1849,  1850,  1851,  2033,  1883,  1884,  1887,  1892,
    1897,  1904,  1909,  1910,  1912,  1919,  1948,  1950,  1966,  1977,
    1979,  1980,  1984,  1989,  1990,  1994,  1996,  1997,  2012,  2017,
    2019,  2023,  2025,  2029,  1878,  2028,  1717,  1719,  1722,  1726,
    1736,  1760,  1779,  1780,  1782,  1793,  1824,  1827,  1867,  1873,
    1886,  1890,  2026,  2027,  1928,  1947,  1953,  1965,  1967,  1986,
    1991,  2001,  2011,  1731,  1725,  1730,  1747,  1798,  1841,  1854,
    1855,  1916,  1918,  2000,  1874,  1831,  1898,  1746,  1794,  1804,
    1869,  1852,  1899,  1737,  1860,  1865,  1999,  1917,     0,  1709,
    1712,  1713,   676,     0,     0,     0,   665,   698,   698,   695,
       0,     0,   699,     0,    26,   664,   667,     0,   674,   670,
     905,   895,  1682,  1683,  1673,  1673,  1317,     0,     0,  1591,
       0,   186,  1300,     0,     0,  1301,  1345,   186,     0,  1346,
       0,  1630,     0,  1314,     0,  1364,  1363,  1362,  1360,  1361,
    1359,  1357,  1354,  1428,  1427,  1355,  1356,  1365,  1612,  1358,
    1689,  1688,  1687,  1366,  2140,  2140,   577,   568,   559,     0,
     563,  2140,   890,   176,     0,   327,   219,     0,     0,  1571,
    1569,  1570,  1566,  1568,  1565,  1567,   505,   501,     0,   537,
     536,   173,  1641,  1640,  1579,  1577,  1578,  1574,  1576,  1573,
    1575,  1552,     0,  1630,     0,     0,  1496,     0,  1496,  1496,
    1496,  1496,  1645,     0,     0,     0,  1445,  1620,  1637,     0,
       0,     0,     0,  1698,  1699,  1700,  1701,  1702,  1703,  1648,
       0,     0,   453,   452,     0,     0,   186,   228,   209,  1203,
     176,  1191,  1418,     0,  1417,     0,  1419,     0,  1420,  1277,
       0,  1283,  1279,  1276,     0,     0,     0,     0,     0,     0,
    1273,  1269,  1407,  1406,  1405,  1245,  1244,     0,  1268,  1264,
       0,  1260,  1258,     0,   632,     0,   631,     0,  1001,     0,
       0,   999,  2100,  2102,  2101,  2098,  2130,  2127,  1532,  1535,
       0,     0,  1231,   479,   348,     0,     0,  1228,   992,  1063,
    1064,  1061,  1060,     0,   881,     0,     0,   608,     0,     0,
       0,   971,   969,     0,   690,   691,     0,     0,  2109,  2117,
     729,     0,   142,     0,   981,   988,     0,     0,   996,  1351,
       0,   186,   343,     0,     0,     0,     0,    24,  1034,   553,
       0,     0,     0,   762,   763,  1007,   796,   422,     0,  1042,
     740,   741,   371,     0,  1124,     0,  1127,  1112,  2140,     0,
       0,     0,   542,     0,     0,     0,     0,    64,    93,     0,
       0,   117,   112,     0,   107,     0,   114,   108,   867,   859,
     865,     0,  1097,     0,  1099,  1101,     0,     0,   939,     0,
       0,     0,     0,  1052,  1217,     0,     0,  1708,  1710,  2140,
     647,   652,   655,   668,   666,   625,     0,   718,   716,   722,
     720,     0,     0,   714,   758,   712,   697,   708,   706,   756,
     734,     0,   700,   710,   949,   945,     0,     0,     0,     0,
     673,     0,     0,     0,     0,     0,     0,     0,  1536,     0,
    1423,  1424,  1694,  1387,  1445,     0,     0,  1692,     0,     0,
    1613,  2035,     0,  1370,  1376,  1375,  1374,  1378,     0,  1371,
    1372,   565,   567,     0,     0,   580,   572,   574,     0,   569,
     570,     0,     0,   588,   590,     0,     0,   586,   892,   831,
     218,     0,   616,   618,   613,     0,   534,   533,     0,     0,
    1665,     0,     0,     0,  1498,  1499,  1497,     0,  1667,     0,
       0,     0,     0,     0,     0,     0,  1635,     0,  1434,  1435,
    1437,  1440,     0,  1446,  1447,     0,     0,  1496,  1622,  1616,
    1650,  1651,  1649,  1647,  2104,   449,   485,     0,   230,  1159,
     854,  1137,  1395,  1397,     0,  1281,     0,     0,     0,     0,
       0,  1271,     0,     0,  1528,  1526,  1503,  1513,  1515,  1511,
       0,  1510,     0,  1519,  1506,  1527,     0,  1518,  1509,  1525,
    1517,  1411,  1500,  1501,  1502,     0,  1266,  1262,     0,     0,
    1250,   630,     0,     0,     0,     0,     0,  2126,     0,     4,
       8,    10,     0,   479,   418,     0,     0,     0,   989,     0,
       0,     0,     0,     0,     0,     0,   186,   689,     0,     0,
     159,   157,     0,     0,   139,     0,   149,   155,   698,   144,
     146,     0,   986,   997,   998,     0,   420,     0,  2088,  2089,
     342,   347,   610,   341,     0,   344,   349,   479,  1323,   601,
     599,     0,   765,  1041,  1043,     0,   372,  1117,  1115,  1214,
    1215,     0,     0,  1208,     0,     0,     0,     0,   100,     0,
       0,    75,    81,    71,  2140,  2140,   110,   105,   119,   115,
       0,   109,   759,   868,   625,  2140,   858,   857,   866,   991,
       0,     0,   937,   938,   932,   958,   479,  1058,  1054,  1055,
    1057,  2032,   955,  2034,   953,   677,   671,   669,     0,    24,
       0,  2140,  2140,  2140,  2140,   724,   702,   726,   704,  2140,
    2140,  2140,  2140,     0,   696,   701,  2140,   625,   754,   752,
     755,   753,     0,     0,    46,    44,    41,    35,    39,    43,
      38,    31,    40,     0,    34,    37,    32,    42,    33,    45,
      36,     0,    29,    47,   746,     0,   675,  1674,     0,  1672,
    1630,  1670,  1617,  1618,  1610,  1596,  1611,     0,     0,     0,
    1030,  1422,  1425,     0,     0,     0,  1335,  1306,  1697,  1696,
    1695,     0,     0,     0,     0,  1330,     0,  1329,     0,  1331,
    1326,  1327,  1328,  1319,  1315,     0,     0,  1377,     0,     0,
     579,   584,     0,     0,  2140,  2140,   557,   571,   594,   582,
     596,  2140,  2140,   592,   576,   587,   823,   328,     0,  1586,
    1584,  1585,  1581,  1583,  1580,  1582,  1554,     0,     0,     0,
    1666,     0,     0,     0,  1664,     0,     0,     0,     0,  1646,
    1663,     0,  1438,     0,  1545,  1441,     0,     0,     0,     0,
    1433,  1451,  1453,  1455,  1495,  1494,  1493,  1457,  1473,     0,
    1448,  1449,  1625,  1235,     0,     0,     0,   212,     0,  1185,
    1204,   823,     0,  1192,  1185,     0,     0,  1278,     0,  1280,
       0,  1537,     0,  1396,     0,  1399,  1540,     0,  1403,     0,
    1270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1409,     0,  1412,  1413,     0,  1265,     0,  1259,  1261,
    2099,     0,     0,     0,  2128,  1241,     0,  1237,     0,     0,
    1242,   838,     0,     0,     0,     0,     0,  1293,  2133,  2132,
     609,     0,     0,    48,     0,   694,   693,   692,  1294,   698,
    2140,  2140,   151,   633,   161,   153,   163,   143,   150,  2140,
       0,     0,     0,     0,     0,     0,   186,     0,     0,  1324,
     551,     0,   764,  1039,     0,  2107,     0,    93,   543,     0,
      65,     0,     0,     0,    78,     0,    93,    93,   118,   113,
    2140,  2140,   103,     0,   869,   863,   871,   870,   860,   547,
     918,     0,     0,     0,     0,     0,   679,   658,   672,   626,
     735,     0,   719,   717,   723,   721,     0,  2140,     0,  2140,
     715,   713,   709,   707,   757,   711,    24,   747,     0,     0,
       0,    27,     0,  1677,     0,  1597,     0,     0,  1609,  1592,
    1608,  1426,     0,  1389,     0,  1334,     0,     0,  1693,     0,
    1690,  1614,     0,     0,     0,     0,     0,     0,  2036,  1333,
    1332,  1320,  1318,     0,  1380,     0,  1373,     0,   581,   578,
     573,   575,     0,  2140,  2140,   589,   591,  2140,  2140,     0,
    1572,     0,     0,     0,     0,     0,  1662,  1668,  1658,  1659,
    1660,  1661,  1442,     0,  1436,  1456,     0,  1460,     0,  1473,
    1459,     0,     0,  1474,  1489,  1486,  1487,  1484,  1492,  1491,
    1485,  1488,     0,     0,     0,     0,     0,  1490,     0,     0,
       0,  1430,  1431,  1638,     0,  1450,  1444,  1236,  1623,  1340,
    1336,  1337,  1342,  1341,  1621,  1235,     0,  1183,  1184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1182,     0,     0,  1170,  1171,  1172,  1169,  1174,  1175,  1176,
    1173,  1160,  1151,     0,     0,  1207,     0,  2140,     0,  1146,
       0,     0,     0,     0,     0,     0,     0,  1138,  1139,     0,
    1071,     0,  1282,  1421,  1541,     0,  1542,     0,     0,     0,
       0,  1402,  1272,  1401,  1393,  1529,     0,     0,     0,     0,
    1530,  1522,  1522,     0,     0,  1522,  1546,  1408,  1410,  1414,
    1415,  1267,  1263,  1004,     0,   967,  1240,  1239,     0,  1233,
       9,     0,  1235,   839,  1068,   354,  1229,     0,     0,  2124,
       0,     0,   972,    49,     0,   744,   160,   158,     0,  2140,
       0,     0,     0,  2140,   156,   145,     0,   148,   147,     0,
     978,   982,  2092,  2091,  2090,   346,     0,   554,     0,  2140,
     766,     0,   625,  1118,     0,  1209,    70,     0,     0,   101,
      68,    93,    76,    82,     0,   120,   116,   760,  2140,   873,
     625,   872,     0,   544,     0,   790,   791,   789,  1056,   956,
     954,   682,   680,     0,   662,   659,     0,   725,   703,   727,
     705,   736,   750,   751,   748,   749,    30,    28,     0,  1671,
    1626,  1598,  1594,  1593,     0,  1388,  1630,  1391,     0,  1308,
    1303,  1302,  1305,     0,  1626,     0,     0,  2069,  2067,     0,
       0,  2055,  2066,     0,     0,  2068,     0,     0,     0,     0,
       0,  2097,  2065,  2061,     0,  2053,  2056,  2057,  2064,  2060,
    2084,     0,  2046,  2045,  2049,  2051,     0,  2044,     0,  2047,
    2038,  1321,  1316,     0,  1379,     0,   585,   583,   595,   597,
     593,     0,     0,     0,  1629,     0,  1706,     0,     0,  1439,
    1458,  1452,  1454,  1461,  1463,  1461,     0,  1468,  1461,     0,
    1466,  1461,     0,  1476,  1475,     0,  1477,     0,  1429,     0,
    1344,  1343,  1339,  1624,   235,  1177,  1178,  1179,  1181,  1164,
    1162,  1161,  1165,  1166,  1163,  1180,  1167,  1168,  1152,   964,
    1187,   961,     0,     0,  1205,     0,  1150,  1149,  1144,  1142,
    1141,  1145,  1143,  1147,  1148,  1140,  1193,  1398,     0,  1394,
    1400,  1544,  1537,  1404,  1504,  1512,     0,  1514,     0,     0,
       0,     0,  1520,  1524,     0,  1416,  1003,  1238,  1243,  1232,
       0,    24,     0,     0,   995,     0,    50,   975,     0,    24,
     162,   152,     0,   635,   637,   164,   154,   744,     0,   345,
    1325,     0,  1040,    24,     0,     0,    66,     0,    79,    88,
       0,    72,   864,   861,   548,  2140,   933,     0,  2140,   678,
     657,   663,   625,  1681,     0,  1679,     0,     0,  1599,  1595,
    1390,     0,  1392,  1386,     0,  1307,     0,  1691,     0,  2059,
    2058,     0,     0,  1496,     0,  1496,  1496,  1496,  1496,  2062,
       0,     0,  2042,     0,     0,     0,     0,  2071,  2043,     0,
       0,     0,     0,     0,     0,  2037,     0,  1381,  1384,  1368,
    1382,  1385,   833,   832,   329,  1587,  1704,  1705,  1443,     0,
    1480,  1482,     0,  1469,  1472,  1471,  1479,     0,  1481,  1461,
       0,  1432,  1338,   213,   966,   965,   963,     0,  1186,  1072,
    1076,  1078,     0,  1082,     0,  1080,  1084,  1073,  1074,     0,
     855,     0,     0,  1538,  1543,     0,  1531,  1523,  1507,  1505,
       0,  1508,   355,   352,     0,   993,     0,     0,     0,   974,
     745,   140,   634,    24,   984,   552,  1037,    67,  1210,    84,
       0,     0,    77,    88,    88,  2140,   545,     0,     0,   681,
     737,     0,  1678,  1627,  1620,     0,  1309,     0,  1620,  2082,
       0,     0,  2085,     0,     0,     0,     0,     0,     0,     0,
    2054,  2073,  2074,  2072,  2070,  2052,     0,  2048,  2050,  2039,
    2040,  1322,     0,  1369,  1367,  1462,  1669,  1464,     0,  1467,
    1465,  1483,     0,   962,  2140,  2140,  1086,  2140,  1088,  2140,
    2140,  1075,  1206,  1194,     0,     0,  1521,   357,   994,  2123,
       0,     0,     0,     0,     0,     0,    55,     0,    54,     0,
      52,     0,     0,   141,  1044,    88,    93,    88,    89,    83,
      73,   862,     0,     0,   683,    24,  1680,  1619,  1628,  1313,
       0,  1310,  1312,  1600,  2083,     0,     0,  2081,     0,     0,
       0,     0,  2063,  2080,     0,  1383,  1470,  1478,  1077,  1079,
    2140,  1083,  2140,  1081,  1085,  1539,  1516,   359,   364,   362,
     353,     0,   360,   366,    57,    62,    59,    61,    58,    60,
      56,     0,    51,     0,   636,   638,  1048,  1038,     0,  1046,
    1211,    85,    80,   546,   934,  2140,   738,     0,  1304,     0,
    1601,  1615,  2079,  2086,  2075,  2076,  2077,  2078,     0,  1087,
    1089,  2140,  2140,   358,   361,  2140,    53,     0,  2140,  1045,
    1047,     0,   679,  1311,     0,  1605,  1602,  1603,  2041,   365,
     363,   367,     0,  1049,    86,   684,     0,     0,     0,   976,
      90,     0,  1606,  1604,    92,     0,    87,     0,    91,  1607
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   792,   793,   794,   795,  1009,  2289,  2290,   176,   315,
     177,  1343,  1344,  2137,  2441,  3378,  2912,  2913,  3287,  3379,
    3380,   796,  1137,  2947,  2667,  3304,  2078,  2665,  3169,  2951,
    3300,  2666,  3170,  3386,  3481,  3500,  3302,  3506,   623,   624,
     625,  1456,  2357,   797,  1467,  1142,  1465,  2086,  2367,  2083,
    2365,  2370,  2671,  1466,  2364,  2087,  2670,   798,     8,    26,
      27,    28,    29,    30,    85,   801,  1069,  2032,  1367,  2314,
    2318,  2319,  2315,  2316,  2919,  2923,  2639,  2631,  2630,  2632,
    2635,   479,   263,   577,   802,    54,    55,    10,    39,   111,
      67,   248,    69,    70,   192,   329,    71,    72,   235,   334,
     221,   971,   505,  2816,   360,   902,  2191,   388,   389,   222,
     343,   335,   338,  1289,  1290,   115,   517,   116,   117,   348,
     223,   224,  2023,   555,   237,   240,   238,   239,   370,   533,
     534,   536,   541,   905,   241,   242,   379,   538,   188,    11,
      50,   147,   148,   149,   911,  2759,   150,   245,   233,   382,
     383,   384,   385,  2047,   803,   804,   805,   806,  1028,  3367,
    3141,  1345,  3430,  3431,  3432,  3472,  3471,  3475,   807,   808,
     809,   810,   811,   812,   813,  1020,   480,  1023,  1337,  1338,
    1377,  1107,  1378,   290,   291,   292,   293,   294,   295,   296,
     437,   481,  1273,   482,   483,   484,   485,   486,   487,   488,
     950,   178,   499,   960,   962,  1944,   179,   493,   956,   492,
     955,   495,   958,   494,   957,   920,   929,   297,   298,   181,
     299,   407,   408,   409,   410,  2071,   814,  3175,  3392,  2963,
     815,  1080,  2049,  2939,  2338,    86,   230,   527,  1877,  1205,
    1206,  1207,  1874,  1875,  2178,  2179,  2180,  2494,  2495,  1878,
    1879,  2174,  2498,  2490,  2186,  2187,  2501,  2502,  2757,  2753,
    2754,   816,  1387,    56,  2018,  2019,  2333,   393,  1061,  1112,
     992,  1050,  1033,  1070,  2399,   182,   993,   987,  1985,  2634,
      58,   300,   817,  1147,   818,  1160,  1161,   819,   820,   821,
     822,  1168,  2974,  1189,  3180,  1190,  2113,  1191,  2396,  1192,
    2687,  1193,  2140,   823,  2109,  2686,  2973,  3178,  3177,  3455,
      87,    12,   824,  1361,  2024,  2025,  2130,  1823,  2131,  2132,
    2697,  2699,  2412,  2411,  2416,  2410,  2409,  2402,  2401,  2404,
    2403,  2406,  2408,   825,   826,  1067,   827,  1819,  1175,  3395,
     828,  1433,  3149,  2443,  2444,  2133,  2413,  2373,  2673,  1103,
    1415,  2053,  2341,  2054,  1411,   829,   830,  1153,  2101,  2967,
     831,   832,   833,   834,    13,    43,    14,    15,    16,    88,
      89,   835,    90,    17,   893,    18,    91,    92,   127,   529,
    1883,  2506,  3233,    93,   123,   353,   836,  2612,    19,    20,
      21,    22,    23,    38,    59,    94,   648,  1950,  2561,   837,
    1148,  2377,  2090,  2375,  3305,  2958,  2091,  2374,  2676,  2960,
     838,   839,   840,  1044,  1045,  1470,    95,   231,   528,   896,
     897,  1209,  1881,   841,  1194,  1195,   842,  1831,  1196,   301,
      61,    62,    63,    64,  1477,   153,   107,    65,   998,   104,
     184,   185,  1478,  1479,  2384,  1480,   645,   646,  1177,   647,
    1178,  2393,  2394,  1481,  1482,  1341,  3100,  3101,  3256,  1994,
    1059,  1060,   843,  1356,  3289,   844,  2931,   845,  1371,  1372,
    1373,  2038,  2036,   846,   847,  2298,  2325,   848,  1322,  1991,
     849,  1104,  1105,   850,   983,   851,  2454,   852,  3384,  2942,
     853,  2345,  3447,  3448,  3449,  3478,  1109,   854,  1483,  2103,
    2388,  2389,   855,  2011,   991,  1331,   856,   857,   858,  2563,
    3104,  3267,  3268,  3354,  3355,  3359,  3357,  3360,  3420,  3422,
     859,   860,  1472,  2095,   861,  1474,  1123,  1124,  1125,  1449,
     862,   863,   864,  2064,  1441,  1118,   191,  1126,  1127,   302,
    2564,  2857,  2858,  2841,  1017,  1018,  2559,  2842,  2845,    96,
     122,   521,  1299,  2241,  2859,  3271,   419,   865,  1116,    97,
     119,   518,  1296,  2239,  2846,  3269,  2560,  1141,  2657,  3165,
    3385,  1444,   866,   867,   868,   869,   870,  1031,  2296,  1011,
    2292,   871,  2808,  2606,  2607,  2609,  1970,   872,   873,  1308,
    1309,  1310,  1982,  2278,  1311,  2275,  1979,  1312,  2250,  1971,
    1313,  1314,  1315,  1316,  2244,  1962,   874,  1040,  1022,   875,
    1855,  1856,  2155,  3001,  3196,  2727,  2998,  3400,  3401,  1857,
    2162,  2741,  1837,  2484,  3042,  3226,  2650,  2938,  2485,  1858,
    1859,  2228,  2810,  2811,  2812,  3082,  1860,  1861,  1375,   876,
    1073,   877,  1202,  1862,  1863,  3344,  2168,  2169,  2170,  2487,
    2743,  3229,  3230,  1864,  2464,  2722,  3193,  1972,  1973,  1958,
    2572,  2242,  2573,  1974,  2577,  1975,  2593,  1976,  2594,  2888,
    2889,  2245,  1865,  2149,  2150,  2461,  1866,  2805,  2550,  2801,
    2223,  1926,  2218,  2219,  2220,  2773,  1927,  2224,  2551,  2806,
    2540,  2541,  2542,  2543,  2544,  3240,  3063,  3345,  2545,  3242,
    3243,  2799,  2546,  2800,  2547,  2207,  2271,  2272,  2273,  3129,
    2274,  2876,  2881,  3277,  2574,  3231,  2866,  3034,  2576,  2535,
    1251,   303,  1252,  1911,   430,   921,  1896,  1912,  2516,    37,
     878,   879,  2993,  3189,  2715,  3188,  3461,  3486,  3487,  2719,
    2455,  1867,  2456,  2473,  3004,   580,  2451,  2452,  2229,  2553,
    3187,  2997,  1253,   935,  1254,  1255,  2802,  2548,  1257,  1258,
    2209,  3347,   880,   881,  2142,  2453,  2989,  3184,  3185,  1834,
     882,  1026,  1869,  1870,  2158,  2729,  1871,  1872,  2470,  1939,
    2202,   883,  1156,  1808,  1809,  1810,  2105,  1811,  2106,  1873,
    2474,  3040,  3225,  2738,  3037,  3038,  3039,  3036,  3024,  3025,
    3026,  3027,  3028,  3029,  3323,   884,  2041,  2328,  2329,   999,
    1259,  1001,  1995,  1260,   885,  1129,  2068,  1364,  1435,   886,
     395,   887,  2623,   888,  2287,  1003,  1997,   889,   890,    33,
     522,   523,   524,   525,   526,   891
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2926
static const short yypact[] =
{
     605,   397,   248,   248,  1208, -2926, -2926,  1208, -2926,    -6,
   -2926, -2926, -2926,   295, -2926,   605, -2926, -2926, -2926, -2926,
   -2926,   187, -2926, -2926, -2926, -2926,   337,   412, -2926,   490,
   -2926, -2926, -2926, -2926, -2926, -2926,   158, -2926,   340,   507,
   -2926, -2926, -2926,   402, -2926, -2926, -2926, -2926, -2926, -2926,
     302,   248, -2926,   248,   560,    -6, -2926,   535, -2926, -2926,
   -2926, -2926,  1161,   281, -2926, -2926, -2926,   962,   603,   248,
   -2926, -2926,  1002,   248, -2926, -2926,   248,   248, -2926, -2926,
   -2926, -2926,   248,   248, -2926, -2926, -2926, -2926, -2926,   402,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  2540, -2926,
     281, -2926,   284,  3134, -2926, -2926,   538, -2926, -2926,  1025,
     507,   492, -2926, -2926, -2926, -2926, -2926,  9493, -2926,   248,
     601,   924,   248,    -6, -2926, -2926, -2926,   248, -2926, -2926,
     720,   615,   982, -2926, -2926,   618, -2926,   624, -2926,   608,
   -2926, -2926,   645, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926,   666, -2926, -2926, -2926,   680,   685,   691,
     703,   718,   729,   759,   779,   785,   795,  3134,   831,  4606,
     848,   886,   894,   900,   903,   913,  1700,  1105, -2926, -2926,
   -2926, -2926,   797, -2926,   146, -2926,  3134, -2926,   143, -2926,
   -2926, -2926,   116, -2926, -2926, -2926,  1063, -2926, -2926, -2926,
   -2926, -2926,   720,   923, -2926,   982, -2926, -2926,   933, -2926,
     961, -2926,   808, -2926, -2926,   966, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,   969,  1246,   248,  1008, -2926,
      -6,    -6,  1013,   248, -2926,   -28,  1308, -2926,   747,  1016,
   -2926,   788,  1024,  1392,  1441,   248,  1461,  1464, -2926,   858,
   -2926,    36,    36,    36,    36,    36,  4606,  1190,  1679,    36,
    4606,   943,  4606, -2926,  4606,  4606,  4606, -2926, -2926, -2926,
     957,  1057,  1060,  4606,  1027,  1072, -2926,  4606,  4606,  1104,
   -2926,  1108, -2926,   886,  1119,  1126,  1130,  1138,  1531,  8898,
      86, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  1153, -2926, -2926, -2926, -2926, -2926, -2926,   826,   826,
   -2926, -2926, -2926, -2926, -2926,  3134, -2926, -2926,   248,  3134,
    1118,   157, -2926, -2926, -2926, -2926,  1588, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926,   -28,  1592, -2926, -2926,
   -2926,  1606,  1610,   507,  1461,  1620,  1005, -2926,  1536, -2926,
    1229,  1195, -2926,  1273, -2926, -2926, -2926,  1030, -2926, -2926,
    1640,  1265, -2926,  1220, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  1024,  1220, -2926, -2926, -2926, -2926, -2926, -2926,  1230,
     166,   240,   242, -2926,  2407, -2926, -2926, -2926,  1233,  1694,
     267, -2926,  1236, -2926,   330,   294,  1276,  1280,   308,   358,
    7525,  1282,  -165,  1255, -2926, -2926,    77,  1286, -2926, -2926,
   -2926,   368,  7584, -2926,  4092,  8735,  2502,  2502,  4606, -2926,
    1209,  4606,  8898,  1251, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  1064,  1709,  7625,  8898,  1209,  1715,   379,  4606,  4606,
    4606,  4606, -2926,  4606,  4606,  4606,  4606,  4606,  4606,  4606,
    4606,  4606,  4606,  4606,  4606,  4606,  4606,  4606,  4606,  4606,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
    4606,  4606, -2926, -2926,  1271,  4606, -2926,  4606,  1275, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,   826,  4606,  4606,  4606,  4606,  1325,  1747,  1700,  4606,
    1289, -2926,  3134,  1283, -2926,  1116,  1109,  1749,  1351,  1486,
     396,   399,   249,  1326,   406, -2926, -2926, -2926,   248, -2926,
   -2926,   248,  1390, -2926,  5017,   492,  6931,  1759,   -68,   248,
    1770,   669, -2926, -2926,  1016,  1765, -2926, -2926, -2926, -2926,
    1768, -2926,  1769, -2926,  1781, -2926,   248, -2926,   248, -2926,
   -2926,  1461,  1782, -2926, -2926, -2926,   248,  3134,    30,    36,
   -2926, -2926, -2926, -2926, -2926, -2926,  1027,  1027,  1783, -2926,
    1784,  1191,  1259, -2926, -2926, -2926, -2926,  1395,  8898,   425,
    1396,  7686,  1797,  1027,  1401, -2926,  1403,  1406, -2926,  8125,
    8172,  8317,  8352,  8943,  8976,  8735,  4166,  9078,  9149,  1938,
    9157,  9319,  3158,  9351,  2502,  2502,  4850,  4850,  3303,  8898,
    8382,  8412,  1209,  8898,  8639,  1209, -2926,  8898,  8898,  8898,
    8898, -2926,  1813, -2926,  1835, -2926,  8898, -2926,   210,  3134,
   -2926,  1824,   669, -2926,  1380,  1821, -2926,  1823, -2926, -2926,
   -2926,  1825, -2926, -2926,  1199,  1427,  1849, -2926,   248,  1436,
   -2926, -2926, -2926,   826,   826,   826,   883,   248,   193,   248,
     248,   193,   193,   889,   248, -2926,  1310, -2926, -2926,   248,
   -2926,   950, -2926, -2926, -2926,   193, -2926, -2926, -2926, -2926,
     248, -2926, -2926, -2926, -2926,   105,   105,  4606, -2926, -2926,
   -2926, -2926, -2926, -2926,   193, -2926, -2926,   193, -2926, -2926,
     248, -2926, -2926,   193, -2926, -2926,   826,   193, -2926, -2926,
    4606,   193,   826,   248,   826,   193, -2926, -2926,   155,   193,
     193,   155,   193,   248,   155,   193, -2926,   193,   193,   193,
   -2926, -2926, -2926, -2926,   826,   193, -2926, -2926,   193,    64,
     248, -2926, -2926, -2926, -2926,   193,   893, -2926, -2926,   826,
   -2926,   193, -2926,  3224,   826,  4606,    36,    36,   193, -2926,
   -2926,   883,   826,   953,  4606,  4606, -2926,   658,  4606,   193,
      91, -2926,  4606,   193,  1838,   826, -2926,   193,  4606, -2926,
    4606,   105,   248,   193,   248,    36,   193,   248,    36, -2926,
     248,   202, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,   257, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,   749, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926,   741,   248, -2926,   762, -2926,  1439, -2926,
   -2926, -2926,  1530, -2926, -2926,  1442,  1444,  1446,  1458, -2926,
   -2926,  1232,  1885,  1465,  1468,   377, -2926,  1438, -2926, -2926,
   -2926,  1240, -2926,  1478, -2926,  1879, -2926,  1285, -2926, -2926,
    1250, -2926, -2926, -2926, -2926,  9359, -2926,   957,  1485, -2926,
     957, -2926,   957,   957,   957,   957,   957,  1887,  1889,  1891,
    4606,  1491,  1893,  4606,  1493,  1498,  1499,  1500,  1513,  1514,
    1515,  4606,  4606, -2926,   216, -2926, -2926,  1608, -2926,  1517,
    1537,  1305,  1539,   248, -2926,   248,  1541, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926,   393,  1504, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,  1317,  1369,  1480, -2926,  1321,
   -2926,  1323, -2926,  1966,  1327,  1356,  1324, -2926, -2926,  1520,
   -2926,  1310, -2926,  1470,    80, -2926, -2926, -2926,  1059, -2926,
    8898, -2926, -2926, -2926,  3370, -2926, -2926, -2926,   826, -2926,
   -2926,  1310, -2926,   -50, -2926, -2926,  1683, -2926,    35, -2926,
    1492, -2926, -2926, -2926, -2926,  1980, -2926, -2926,   573, -2926,
    1339, -2926,  1340,  1980, -2926,  1364, -2926, -2926,  1543,   127,
   -2926,  1502, -2926,  1309, -2926, -2926, -2926, -2926,  1311,   744,
    -263, -2926,  1317,  1639,  1357,  4606,   176,  4606, -2926,  1997,
     193, -2926, -2926, -2926, -2926, -2926,    38,    38,    38, -2926,
      38,  1603,    38,    38,  1376,   -50,  1376,  1376,   993,   993,
    1376,  1376,   -50, -2926,  2002, -2926,   -13,  2004, -2926,   -50,
      67,    40, -2926, -2926,  4606, -2926, -2926, -2926,  1110, -2926,
   -2926,   492,  1593,   492,  4606, -2926,    74, -2926, -2926,  4606,
    1545,  1547,  1548,  1549,  1454,  1550,   953, -2926,  1637,   948,
    1394, -2926,  1407, -2926, -2926,   248, -2926, -2926,  1028, -2926,
    2010, -2926,  2006,   248, -2926,   224,  6300,  1414, -2926, -2926,
    2016, -2926,  1332,  2016,  2020,  1335,  2016,  2020,  4606,  2016,
   -2926, -2926,    80,   826, -2926, -2926,  1573,   786, -2926, -2926,
    1564,   826,  4606,  1565, -2926, -2926,  2007,  2008,  1932, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926,  1077,  1077,   193,
     193,   193,  2232, -2926, -2926,  1909,   741, -2926, -2926,   813,
   -2926, -2926, -2926,  1544, -2926, -2926, -2926, -2926,  2540,  1461,
   -2926, -2926,  1383,   248,  1131,  1027,  1415,  1526, -2926,  5209,
    5209, -2926,  1317, -2926, -2926,  1145, -2926, -2926,  5024,  1574,
   -2926,  1575,  1578, -2926,  1582,  1584,  1585,  1587,   248,   672,
   -2926, -2926, -2926, -2926,   117, -2926,   248,  1669, -2926,  1598,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,  8898,   413, -2926, -2926,   414, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926,  1561, -2926,   415,
   -2926, -2926, -2926, -2926, -2926, -2926,    -6, -2926, -2926,    -6,
     674,   147,  2029, -2926, -2926,   352,   203,   607,  2052, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926,  1533,  1369,  1323,
   -2926,   889,  -302,  1268,   248,   248,   248,  1310,  1429,  1595,
   -2926,  1596,    93, -2926, -2926, -2926, -2926, -2926,  2057, -2926,
   -2926,  1405,  1612, -2926, -2926, -2926,   889,  1086, -2926,  1086,
     953,   155,  4606,  4606,  4606,  1613, -2926, -2926,   826,   826,
   -2926,  1416,   953,    36,  1385,    64,   826, -2926,  1413,  4606,
    1699, -2926, -2926,  1495, -2926, -2926,   248,  2081, -2926, -2926,
      92,    80, -2926, -2926,  2070,  2071, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926,   981, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926,  3224, -2926,   993,  4606,  -106,  2063,
    2065, -2926, -2926, -2926, -2926, -2926,   103, -2926, -2926, -2926,
   -2926,  1904, -2926,  1840, -2926, -2926, -2926,  4606,   105, -2926,
   -2926,   248,  2069,    36,    36, -2926,  1473, -2926,    36,  1443,
     826, -2926,   248,   248,  4606,  -133, -2926,  1489, -2926, -2926,
     327, -2926,  1589, -2926,  1591,  4606,  1009, -2926, -2926,  1455,
   -2926,  2105, -2926,  1532, -2926,   826, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  5602, -2926,
   -2926, -2926, -2926,   248,    36,    36,   219,   786,  1925,   947,
     826,    80, -2926,  1534, -2926, -2926,  2081,  2087,  1681, -2926,
   -2926, -2926, -2926, -2926,  1760,  1760, -2926,   129,  1538, -2926,
     248, -2926, -2926,  1310,  1310, -2926, -2926, -2926,   248, -2926,
     248,   425,  1310, -2926,   736, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926,   134,   134,   807,   945, -2926,   967,
   -2926,   813, -2926,    -6,  2091, -2926, -2926,  1312,  1695,  1658,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  1555, -2926,
   -2926, -2926,  1751,  1751, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,  1466,   425,  1701,   836,   523,  9359,   523,   523,
     523,   523,  1475,  9359,  9359,   243,  1566,   664, -2926,  9359,
    9359,  9359,  9359, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
     889,  4606, -2926, -2926,  1703,  2091, -2926, -2926, -2926, -2926,
      -6, -2926, -2926,  1310, -2926,   704, -2926,  1665, -2926, -2926,
     704, -2926, -2926, -2926,  1666,  1667,   288,  1668,  1670,  1076,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926,   248, -2926, -2926,
     288,  1440, -2926,   393, -2926,  1710,   281,  1490, -2926,   953,
    1528, -2926, -2926,  1649, -2926, -2926, -2926,  1567, -2926, -2926,
    1684,   248, -2926, -2926, -2926,  3370,   248, -2926,  1494, -2926,
   -2926, -2926, -2926,  1487, -2926,  2145,  2146, -2926,  2147,  1542,
    4606, -2926, -2926,  1501,  2151, -2926,  1641,  1505,  2020, -2926,
   -2926,  1503,  1092,   248, -2926, -2926,  1702,   193,   941, -2926,
    4606, -2926, -2926,   248,   248,  4606,    41,   -50,  2161,  2160,
    2143,  2144,  1603, -2926, -2926, -2926, -2926, -2926,   826,  1818,
   -2926, -2926,  2073,  4606,   492,   976, -2926, -2926,  1814,  2170,
    2173,   416, -2926,   423,   248,  1758,   953, -2926,  4606,  1721,
    1724, -2926, -2926,  1796, -2926,  4606,   315, -2926,  1568, -2926,
   -2926,   183, -2926,  4606, -2926, -2926,  1535,   284, -2926,  1350,
     248,  2179,  9126, -2926, -2926,   889,   826, -2926, -2926,   108,
   -2926,  2020,  2020,  1506, -2926,  1616,  1621, -2926, -2926, -2926,
   -2926,    36,    36, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  1434, -2926, -2926, -2926, -2926,    36,  3630,  2191,  2176,
   -2926,   953,   845,   237,   119,  2082,    15,   883, -2926,   403,
   -2926, -2926, -2926,  1739,    59,  1310,   182, -2926,  1553,  1557,
   -2926, -2926,   481, -2926, -2926, -2926, -2926,  1753,  1569,  2216,
   -2926, -2926, -2926,   826,   168, -2926, -2926, -2926,  1552,   945,
   -2926,   248,   248, -2926, -2926,   248,   509, -2926, -2926, -2926,
   -2926,  1767, -2926, -2926, -2926,  2200, -2926, -2926,  1146,  9359,
   -2926,   307,  1803,  2225, -2926, -2926, -2926,  9359, -2926,   426,
    9359,  9359,  9359,  9359,   248,   434, -2926,   322,  2227, -2926,
   -2926,   248,  4874, -2926,  1831,   248,  1583,   523,  1873, -2926,
   -2926, -2926, -2926, -2926, -2926,  8898, -2926,  1779, -2926,  1748,
   -2926,  1750, -2926,  1777,   438, -2926,  4874,   444,   111,   111,
     448, -2926,   111,  4874, -2926, -2926,  1790,  1145,  1145, -2926,
    1799, -2926,  1801,  1806, -2926,  1807,  1808, -2926, -2926, -2926,
   -2926,     0, -2926, -2926, -2926,   449, -2926, -2926,   460,   248,
   -2926, -2926,  1268,  2240,   953,  3134,  4606, -2926,   248,  2244,
   -2926, -2926,   288, -2926, -2926,  1609,   288,   160, -2926,   953,
    4606,  4606,  4606,  3926,  2263,   101, -2926, -2926,   953,   248,
   -2926, -2926,   248,   248, -2926,   926, -2926, -2926,   908, -2926,
    1617,  4606, -2926, -2926, -2926,  2266, -2926,  1622,  2271, -2926,
   -2926, -2926, -2926, -2926,   248,  2020, -2926, -2926,  1691, -2926,
   -2926,   464, -2926, -2926, -2926,   826, -2926,  7374, -2926, -2926,
   -2926,  1919,  2256, -2926,    36,  1905,  1906,  1794,  1630,  1910,
    1826, -2926, -2926, -2926,  -140,  1897, -2926, -2926, -2926, -2926,
    1796, -2926, -2926, -2926,   231,   756, -2926, -2926, -2926,  2081,
    4606,  1828, -2926,  1800, -2926, -2926, -2926, -2926,  2291, -2926,
   -2926, -2926,  1843,  2294, -2926, -2926,  1618, -2926,  2274,   -50,
     248,  1855,  1855,  1855,  1855, -2926,  2299, -2926,  2303,  1855,
    1855,  1855,  1855,   981, -2926, -2926,  1855,    96, -2926, -2926,
   -2926, -2926,  2284,  2304, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926,  2306, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,   476, -2926, -2926, -2926,  2295, -2926, -2926,  1310, -2926,
     425, -2926, -2926, -2926, -2926, -2926, -2926,  1693,  1696,   167,
   -2926,   403, -2926,   111,  1674,   193, -2926,  1861, -2926, -2926,
   -2926,   248,   248,  9359,   207, -2926,  4606, -2926,  4606, -2926,
   -2926, -2926, -2926, -2926, -2926,   193,   111, -2926,  1310,   595,
    2322, -2926,   826,   248,   873,   873, -2926, -2926,  2323, -2926,
    2323,   620,   620,  2323, -2926, -2926,  1759, -2926,  1908,  1865,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926,   117,  1145,  1672,
   -2926,  1145,  1911,  9359, -2926,  1912,  1913,  1914,  1915, -2926,
   -2926,   243, -2926,   243, -2926, -2926,  4888,  1870,  4108,  1870,
    2330,  2335, -2926, -2926, -2926, -2926, -2926, -2926,   268,  9359,
   -2926,  1863, -2926,  2043,    68,   237,   248, -2926,  5054,    47,
   -2926,  1759,  1197, -2926,    47,   111,   704, -2926,   205, -2926,
    1310,   594,  1921,  2343,  1697, -2926, -2926,   486, -2926,   288,
   -2926,   493,   346,  2325,  1698,  -169,  2328,  2328,  2329,  2328,
    2328, -2926,   152, -2926,   704,   248, -2926,   288, -2926, -2926,
    1705,   953,  2348,   218, -2926,  -164,   495, -2926,   248,   497,
   -2926,  4606,  1934,  2341,   499,   953,  2357, -2926, -2926, -2926,
   -2926,  4606,  1764,  2056,  4606, -2926, -2926, -2926, -2926,   908,
    1050,  1050,  2361,   450, -2926,  2362, -2926, -2926, -2926,  1050,
     248,  1788,  1412,  2364,   248,   173, -2926,  -212,  4606, -2926,
   -2926,  1603, -2926,  1673,  4606, -2926,  2365,  4606, -2926,   826,
   -2926,   950,   248,   826, -2926,  1945,  4606,  4606, -2926, -2926,
    -140,  1897, -2926,   981, -2926, -2926,  1111, -2926, -2926,  1771,
   -2926,  3134,  4317,  9126,   826,   826,    94,   944, -2926, -2926,
   -2926,  1720, -2926, -2926, -2926, -2926,    36,  1855,    36,  1855,
   -2926, -2926, -2926, -2926, -2926, -2926,   -50, -2926,  1033,  1184,
    3630, -2926,  1949,  1916,  9359, -2926,   119,   119, -2926, -2926,
   -2926, -2926,   500, -2926,  1872, -2926,   111,  -149, -2926,  1719,
   -2926,  2374,  2492,  2492,  2492,  2492,   111,   111, -2926, -2926,
   -2926,  1793, -2926,   502, -2926,  1723, -2926,   826, -2926,  2323,
   -2926, -2926,   248,   620,   620, -2926, -2926,   620,  2139,  1730,
   -2926,  2363,  1962,  1731,  1146,  1732, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926,   506, -2926, -2926,  1888, -2926,   394,   223,
   -2926,  4874,  4874, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,  5209,  5209,  1927,  5209,  1929, -2926,  5209,   537,
    9359,  2390, -2926, -2926,  4874, -2926, -2926, -2926, -2926, -2926,
    2391, -2926,  -139, -2926, -2926,  2043,  1742, -2926, -2926,   105,
     105,   105,  2377,   105,   105,   105,   105,   105,   105,  2378,
   -2926,  2379,   105, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  5054, -2926,   826,  1754, -2926,  1924,  2139,  2382, -2926,
    2383,  2384,  2385,  2388,  2389,  2392,  1137,  1197, -2926,  1924,
   -2926,   519, -2926, -2926, -2926,  2393, -2926,  2078,   111,  1428,
     111, -2926, -2926, -2926, -2926, -2926,  1990,  1146,  2394,  1146,
   -2926,  2412,  2412,   525,  1995,  2412, -2926, -2926, -2926,   704,
   -2926, -2926, -2926, -2926,   953, -2926, -2926, -2926,   248, -2926,
   -2926,   288,  2043,  2081, -2926,  1920, -2926,   211,   953, -2926,
    2418,  1959, -2926, -2926,  1999,  1842, -2926, -2926,   248,  1050,
    3134,  1457,   248,  1050, -2926, -2926,    36, -2926, -2926,  4606,
   -2926, -2926, -2926, -2926, -2926, -2926,    36,  2081,   826,  2152,
   -2926,  2402,  1616,  8898,  2405, -2926, -2926,    80,  1974, -2926,
   -2926,  4606, -2926, -2926,  2011, -2926, -2926, -2926,   756, -2926,
    1616, -2926,  4606, -2926,   320, -2926,  2004, -2926, -2926, -2926,
   -2926, -2926, -2926,  1961,  2059, -2926,  2419, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   248, -2926,
     109, -2926, -2926, -2926,   111, -2926,   425,  2264,   528, -2926,
   -2926, -2926, -2926,   248,  1853,  9027,  9027, -2926, -2926,  4466,
    1977, -2926, -2926,  1978,  1979, -2926,  1983,  1984,  1985,  1987,
     248,   676, -2926, -2926,   530, -2926, -2926,  1729, -2926, -2926,
   -2926,   531,  2440,  2440, -2926, -2926,   540,  2449,  2441, -2926,
      82, -2926, -2926,   111, -2926,   163, -2926, -2926, -2926, -2926,
   -2926,  2211,  2540,  2032, -2926,  1146, -2926,  1146,   243, -2926,
   -2926,  2335, -2926,  1986,  1669,  1986,   262, -2926,  1986,   262,
   -2926,  1986,  5209, -2926, -2926,  9359, -2926,  9359,  2330,    68,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   365,
    2454, -2926,   826,  1342, -2926,  2211, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   338, -2926,
   -2926, -2926,  1967, -2926, -2926, -2926,  2037, -2926,  2442,  2040,
    2046,  2447, -2926, -2926,  2048, -2926, -2926, -2926, -2926, -2926,
      36,   -50,  2067,   953, -2926,  4606, -2926,  1875,  2452,   -50,
   -2926, -2926,   395, -2926, -2926, -2926, -2926,   118,  2053,  2020,
    2294,  2205, -2926,   -50,  2055,  2061,  2161,  2017, -2926,  2104,
    2066, -2926, -2926, -2926, -2926,  2209,  1996,  4606,  2019, -2926,
   -2926, -2926,  1616, -2926,   544, -2926,   826,  1917, -2926, -2926,
   -2926,  9359, -2926, -2926,   111, -2926,  2034, -2926,  1917,  1805,
    1805,  2074,   836,   523,  8055,   523,   523,   523,   523,  1848,
    8055,  2492, -2926,  8055,  8055,  8055,  8055, -2926, -2926,   111,
    2489,   111,  2492,   193,  4874, -2926,   826, -2926, -2926,   293,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   152,
   -2926, -2926,   558, -2926, -2926, -2926, -2926,   571, -2926,  1986,
    2499, -2926, -2926, -2926, -2926, -2926, -2926,   826,  2454, -2926,
   -2926, -2926,   826, -2926,   826, -2926, -2926,  1529, -2926,  2233,
   -2926,  2234,  2487, -2926, -2926,  1866, -2926, -2926, -2926, -2926,
    2088, -2926, -2926, -2926,   953, -2926,  2093,  9654,  2062, -2926,
   -2926, -2926,  1880,   -50, -2926, -2926, -2926, -2926, -2926, -2926,
    2100,    80, -2926,  2104,  2104,   756, -2926,  3134,  1923, -2926,
   -2926,   248, -2926,  2294,   664,   117, -2926,  9248,   664, -2926,
    2109,  8055, -2926,   582,  8055,  8055,  8055,  8055,   248,   584,
   -2926, -2926, -2926, -2926, -2926, -2926,  2077, -2926, -2926, -2926,
    2330,  2294,   163, -2926, -2926, -2926, -2926, -2926,   345, -2926,
   -2926, -2926,  9359, -2926,  1423,  1423, -2926,  1423, -2926,  1423,
    1423, -2926, -2926, -2926,  2084,  1146, -2926,  1041, -2926, -2926,
      38,    38,    38,    38,    38,    38, -2926,  2514, -2926,   589,
   -2926,  4606,  1479, -2926,   -20,  2104,  4606,  2104,  2161, -2926,
   -2926, -2926,  2270,   339, -2926,   -50, -2926, -2926, -2926, -2926,
     593, -2926, -2926,  1331, -2926,  2122,  8055, -2926,  2125,  2130,
    2131,  2132, -2926, -2926,  2492, -2926, -2926, -2926, -2926, -2926,
    1423, -2926,  1423, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  1103, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  9654, -2926,  2555, -2926, -2926, -2926, -2926,   629, -2926,
   -2926, -2926, -2926, -2926, -2926,   108, -2926,  9248, -2926,  1590,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   596, -2926,
   -2926,  1270,  1270, -2926, -2926,  1270, -2926,  4606,   775, -2926,
   -2926,  2135,    94, -2926,  1918,  1922,  2557, -2926, -2926, -2926,
   -2926, -2926,  2140, -2926, -2926, -2926,   248,   248,  1590, -2926,
      50,  1926, -2926, -2926, -2926,    80, -2926,   248,  2161, -2926
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2926, -2926, -2926, -2926, -2926,   -96, -2926,   -41,  -163, -2926,
   -2926, -1090,  -439, -2926, -2926, -2004, -2926, -2926, -2926, -2926,
    -871, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -1950, -2926,  -929, -2926,
    1611, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   204, -2926,
   -2926, -2926, -2926,  1113, -2926,   487, -2926, -2926,   -31, -2926,
   -2926,  2558, -2926,  2553,  2060, -2926, -2926, -2926, -2926, -2926,
     278,   -52, -2926,   274, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,   -77,   869,   983, -2926, -2926,
    2247,    49, -2926,  2482, -2926, -2926,  2483, -2926,  2396, -2926,
   -2926, -2926, -2926, -2926,  2260,  1968,   657,  2259,  -469, -2926,
   -2926, -2926, -2926, -2926,   659,  -617, -2926, -2926, -2926, -2926,
   -2926, -2926,  -134,  2089,  2403,     1,  2031, -2926,  2075,  1382,
   -2926,  2239, -2926, -2926, -2926, -2926,  2241, -2926, -2926, -2926,
   -2926,  -375, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
    2068, -2926,  2076, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -1285, -2926, -2926,  -816, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,  -117, -2926, -2926,   611, -2926,
   -1052, -1099,  -576, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,  1664, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
    -584, -2926, -2926, -2926, -2926, -2926,  1851, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,  -480, -2926,   -97, -2926, -2926,
   -2926, -2926,  2218, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  1417, -2926, -2926, -2926, -2926,   443, -2926, -2926, -2926,
   -2926, -2926, -1885, -2926, -2926,   439, -2926, -2926, -2926, -2926,
   -2926, -2926, -1058,  -663,   324,   583, -2926,  -245,   767, -1064,
    1269, -2926,   778, -2926, -2332,    -2,  -136, -2926, -2926, -2169,
     241,   952, -2926, -2926, -2926,   740,   814, -2926, -2926, -2926,
   -2926, -2926, -2926,   -51, -2926,  -339, -2926,   821, -2926,   526,
   -2926,   245, -2926, -2926, -2926, -2926,  -838, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,   342, -2926, -1756, -2926,   520,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926,  1287, -2926, -2926, -2926, -2926,
   -2926, -2926,  -507, -2926, -2926, -1995, -2926, -2926, -2926, -2926,
     580, -2068, -2926, -1071, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  2638, -2926,
   -2926, -2926,  2565,  2634, -2123, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,  -449, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926,  2637, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,   572, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926,  -648,  1940, -2926, -2926, -2926, -2926, -2926,
    1766, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  2517,
   -2926, -2926,   -25, -2926, -2926,   568, -2926, -2926, -2926,  -975,
    -183,  2347, -2926, -2926, -2926, -2926,   513, -2926, -1000,  1692,
     847, -2290,   -16, -2926,   570,  1507,  -431,  -585, -2926, -2926,
    1930,  1314, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926,  1252, -2926,  -735, -2926,  -586, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926,  -773, -2926, -2926, -2926, -2926, -2926,
   -2926,    -5, -2926,  1336,   343, -2926, -2926, -2926, -2926, -2926,
    -173, -2926,  -580, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  1571, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926,  -498, -2926,  1241,  2252,
   -2926, -2926,  -167, -2926,  -567, -2926, -2926,  -150,   128, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926,   891, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2441, -2926,  -205,   401, -1297, -2926, -2926, -2926,
     715, -2926, -1888, -2926, -2926, -2926, -1894, -2926, -2926, -1853,
   -2926, -2926, -2926, -2926,   739, -2926, -2926, -2926, -2926, -2926,
   -2926,   250, -2926, -2926, -2926, -2926, -2926, -2926,  -757, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926,  -378, -2926, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,   222, -2926,
   -2926, -2926,  -629, -2926, -2926, -2926, -2926, -2926, -2926,  -153,
   -2926, -2926,   150, -2926,   466, -2926, -2926, -2926, -2926, -2926,
   -2926, -1282, -2926, -2926, -2926, -2926, -1941, -2926, -2926, -2926,
   -2926, -2926, -2926, -2330,   504, -2926, -2469,   562, -2926, -2926,
   -2187,   -62,   -60,   189, -2926, -1804, -1741, -2926, -2926,  -346,
    -621, -2926, -2926, -2926, -2926, -1865, -2926, -2926, -2926, -2005,
   -2926, -2926, -1048, -2926,  -645,   888,  -396, -2039,   159, -2926,
   -1543, -2926, -2926, -2926, -2926,     5, -2926, -1211, -2518,  2729,
   -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  -760, -2926,
   -2188, -2926,  1540, -2926, -2926,   463,   184, -2926, -2925,   190,
    -264,    16,  -301, -1811, -2155,   823,  -329,  -808, -1206, -2926,
     828, -2926, -2926, -2926,   914,  -746, -2926, -2926,  -559,  1556,
   -2926,   548, -2926, -2926, -1781,  -250, -2926, -2926, -2926, -2027,
    -447, -2926, -2926, -2926,   951, -2926, -2926, -2926, -2926, -2926,
   -2926, -2926, -2926, -2926, -2926, -2581,  -465, -2926, -2657, -2395,
   -2056, -1343, -2926, -2926,  -452, -2926, -2926, -2926,   121,  -656,
    -622,  -411,   480, -1829, -2926, -2926, -2926, -2926,  1399, -2926,
    -216, -2926, -2926, -2926, -2926, -2926, -2926, -2926, -2926,  -252,
    1563,  2245, -2926, -2926, -2926, -2926
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2137
static const short yytable[] =
{
      32,    34,    36,   321,   261,    36,   180,   396,   397,   549,
    1981,   249,    84,   965,  1332,  1436,  1382,  1121,  1959,  1428,
    1410,  1006,  1320,  1902,  1903,  1380,  1115,   652,   100,  1389,
    1390,   953,  1391,  1285,  1412,  1413,    57,  2317,   398,   399,
    2160,  1000,  2675,   411,  2517,   559,   229,  2004,  2762,    99,
     916,    57,   289,  2210,  2211,  2212,  2213,    31,    84,  2568,
     106,  2115,  2116,    31,  1383,    31,  2582,   113,    31,  2159,
     180,   118,   559,  1049,   120,   121,  3031,  3032,  3033,  1447,
     124,   125,   912,  2276,   346,  2706,  2203,   922,    68,   180,
    1074,    31,  2277,  1004,  2809,    31,   570,  2040,  1821,  1014,
      57,   559,  2199,   571,   267,  1170,  1171,    31,  1427,  1024,
     267,  1021,   489,  2251,  1924,   109,  1816,   225,    31,  1019,
     228,  2625,  1924,   559,  1000,   232,  1004,  1256,    31,   267,
    1826,  1015,  1359,  2442,  1035,   326,  1004,  1839,    31,   400,
     267,   327,   328,   412,  2636,   414,    31,   415,   416,   417,
    2458,   319,   498,   354,   355,  3035,   422,  1347,  1348,    68,
     433,   434,   319,   193,  1075,  1079,  1077,   267,   322,   323,
      31,   542,  1817,  2492,    31,  1114,   267,  2886,  1233,  1108,
    1042,  1359,    31,  1429,  1430,  1119,   324,    31,  1122,  1128,
      31,  2971,  1143,  2932,    31,  2042,  1149,  2043,  1004,  2044,
      31,  2772,  1155,  2774,  1157, -2135,  2088,   340,  2462,  2575,
    2578,  2781,  2935,  2578,  1158,   319,  3142,     1,   180,  2843,
      31,   319,   180,   319,  2040,   351,   267,  1170,  1171,    31,
      31,   357,  2783,  2784, -2135,  2785,  2786,  2787,  2788,  2789,
    2790,  2082,  2591,   386,  2465,   544,  3056,   546,  3504,   394,
     394,   394,   394,   394,   110, -2135,  2674,   394,    31,  1180,
   -2135,   567,  1119,    53,    31,     3,  2626,  3223,  1004,   347,
      31,  2720,   552,  2058,  1320,    31,  2391,  2783,  2784,   431,
    2785,  2786,  2787,  2788,  2789,  2790,   267,  1232,  1233,    31,
    2732,  2733,  2734,  2735,  2736,    42,  2878,  2500,  3342,   559,
    2503,   578,  2144,  2145,   581,    53,    57,    57,  1989,   151,
    2124,    31,  2518,   559,   919,    31,   500,  1369,  2731,   628,
    2317,   589,   590,   591,   592,   319,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,  3272,   319,  2704,  2062,  1004,  1990,    31,
    2088,  2778,  2781,   610,   611,  1425,  2996,  1179,   613,  3125,
     614,  3127,  2555,   559,  3000,    52,  1329,    31,    47,   267,
    1232,  1233,    31,   559,  3083,   617,   618,   619,   620,    31,
      53,  2048,   626,  2758,   506,    53,  1342,   509,  1370,  3397,
    1459,  2468,    68,  3403,   915,   310,   311,   312,   313,   314,
    2781,   635,  1180,  1188,   637,   180,   988,  1426,  2896,   988,
     988,   641,  1180,   310,   311,   312,   313,   314,  1941,  1941,
    1946,  2354,  1484,   988,  2723,    24,    25,    53,   559,  3505,
    1914,  2523,     1,  3080,  2592,  1419,  1420,   358,  2847,  2523,
     554,    25,   988,  2566,  2129,   988,   964,  2744,  1339,  2566,
    1845,   988,  2089,  2579,  2595,   988,    53,  2897,   568,   988,
     180,  3139,    53,   988,   359,  2597,     6,   988,   988,  2651,
     988,  3343, -2135,   988,  1064,   988,   988,   988,   270,  1464,
    2936,  2710,  3081,   988,  1300,  1301,   988,   996,  2469,    57,
    2879,  2870,    73,   988,  1066,   799,   892,    74,  2870,   988,
    2898,  2098,  2901,   985,  2901,  2994,   988,  3043,    31,    53,
    2791,  3058,  1302,  1303,  1304,  2813,   644,   988,    24,   644,
    2721,   988,   986,  2059,  2868,   988,  2575,   644,  2991,  2992,
    3131,   988,   180,  3194,   988,  3211,  3211,  3236,  1108,  3237,
    1110,  1111,    75,    76,   386,  3219,   386,  3072,  1122,  3311,
      77,   985,  1183,  1450,   914,  2791,   918,   394,  1025,  2990,
     547,  1025,  2641,  3348,   554,    53,  1180,   639,  1964,  1164,
     996,  1034,  1167,  1384,   928,  1025,  3348,   985,     4,  1025,
    2376,  1965,  1235, -2135,  2334,  1319,  1051,  3406,   939,  3406,
     894,  1025,   543,  1034,  3441,  2844,  2089,  1236,  3457,  1062,
    2146,  3211,  1034,  1485,  2013,  2957,  2933,   320,  2749,  1071,
    3163,     3,  1960,   895,  1838,  1078,  2027,  3078,   503,  2222,
    3143,  1172,  1113,  1442,  1851,  1445,  1385,     5,  3173,  2792,
    2793,  2863,  1964,  1062,    31,     1,  1181,  1062,  3335,  2714,
    1431,  1062,  3224,  1182,  2459,  1965,   644,  1034,  3160,  2200,
    1034,    57,    57,    57,    57,   984,  1416,   989,   990,  1065,
    3228,   997,  1002,  1423,  1005,  1988,   545,  1007,  1977,    57,
    2972,   963,  1851,  1843,  2792,  2793,  1948,  1286,   990,  2895,
    2398,  1182,  2000,  1981, -2135,    31,  2794,  2999,     7,  2369,
    2008,  2730,  1235,   553,  1349,  1183,  3186,  1925,   990,  1000,
     572,  2891,  3148,  2014,    57,  1183,  2986,  1236,  1904,  2892,
      57,   990,    57,  2570,  1145,     2,    57,  1360,  3314,    57,
     560,  1052,    57,  1173,  1000,  1448,  2872,  1432,  3238,  3318,
     917,  2794,    57,   288,   563,  1434,   392,   394,  1068,   288,
    1386,   392,  2450,  2045,   997,  1897,  2570,    57,  2493,  3150,
    1886,  2046,    57,  3155,   394,   394,  2570,  3468,   288,    57,
      57,    57,  2336,  2056,   392,  1139,  1379,  1913,  1146,   288,
    2615,    31,  2874,    57,  1043,  1235,  2015,  2016,  2017, -2135,
    1159,  3176,  1159,   394,   564,  1159,   394,  2531,  1159,    57,
    1236,  1821,  2217,  2034,   574,  1905,   288,  1130,  1967,  3273,
    3454,   272,  1486,    51,    78,   288, -2135, -2135, -2135, -2135,
   -2135,  1906,     6,  2795,  1968,  2398,  3330,  1966,  2570,   932,
    3060,  3073,   636,   557,  2737,   638,   275,  3338,   988,  3120,
      79,  3123,   642,  1272,    31,  1487,  1272,   101,  1222,  1942,
    1943,  1947,  2355,  1885,   626,   626,  3398,  3426,  1131,  2356,
    3310,  2057,  2524,    31,  1907,   288,  3292,  2475,  2795,  1183,
    2530,   995,  1967,    31,  2567,   985,  2476,  1952,  2504,     9,
    2569,  1122,    31,  2915,  2580,  2596,     3,  3130,  1968,  2796,
    3134,  2067,  1305,    53,     9,  1132,  2598,  1964,  2081,  2093,
    2652,  2477,  1208,  1908,  2478,    66,  3313,  1952,   586,  2096,
    1965,    80,  2711,  3030,  3030,  3030,  3030,  1987,   981,   281,
      31,  2479,  2871,  2640,   995,   288,    31,  2204,  1072,  2873,
      31,  2899,  1909,  2902,  2796,  2906,  2995,  2085,  3044,  2797,
    2798,  1910,  3059,  1249,   108,   933,  3341,  3254,  2163,  1184,
    1185,  1186,  1854,  2920,  1113,  3117,  3479,   988,   988,   988,
    1187,  3132,    98,  3201,  3195,  3190,  3212,  3218,  3074,  2124,
    3075,   310,   311,   312,   313,   314,  3220,   110,  1306,    53,
    3312,  1295,  1822,   644,  2797,  2798,  1008,    31,  1119, -2135,
      31,  2342,  1133,   558,  3349,  2117,  3255,  2118,  2119,  2120,
    2519,   112,    41,    81,   997,  2610,     4,  3350,   288,  2610,
    3217,   284,  2349,    31,  3227,  1953,  1392,   114,  3407,  1005,
    3413,  1307,    57,   285,   286,  3442,  2480,  1288,    52,  3458,
      31,   287,  3488,  1013,  2181, -2135,    57,   102,   103,  1005,
    2225,   186,    53,  2205,   649,  1953,  3315,  3340,    41,   187,
    2813,  2379,   898,  1029,   934,     5,  2584,  2585,   190,  2887,
     163,    53,  3065,  1469,  3068,    31,  1038,  3071,  1134,  2982,
      31,   996,   164,  1836,  1078,  1113,   226,    57,  2164,  2481,
      53,   227,  1980,    82,   234,   951,  2482,     6,   954,  2165,
     236,    83,  1954,   243,    57,    57,    57,  2865,    57,   244,
      57,    57, -2135,  2129,  1822,   900,    57,    57,  2483,  1135,
    2166,   246,  1832,  2921,    31, -2135,     7,  2167,    53,  2208,
     247,  2009,  1954,    31,   996,  2208,  1256,  1967,   996,  1197,
    1066,  2230,  2231,  2232,  2233,  2310,   250,  2311,  2448,   901,
    1198,   316,  1457,  1968,    57, -2135,  2959,  1923,    31,  1955,
     325,  3210,  2206,  1468,   330,   251,    57,  2028,  3322,  2361,
     252,  1476,  2637, -2135,  3322,  3316,   253,  3331,  3332,  3333,
    3334,   976,  3113,  1366,    31,   103,  1136,  2182,   254,   103,
      57,    57,  3217,  3217,  2254,    53,  3030,  3030,    53,    57,
    3030,   105,  1199,   255,  1956,  3191,  2183,  2184,    31,  3022,
    3022,  3022,  3022,  1393,   256,    57,    57,  1200,  2153,  2154,
    1957,    53,  1333,  1334,  1335,   170,  2185,  2161,  2072,  2164,
    2984,    31,  2226,  2075,  1956,   401,   402,  1326,    53,  1949,
    2165,  1888,  1951,  2227,   257,  1352,  2173,  1249,  1249,   171,
    1957,  2312,  1353,    35,  2313,    31,  1249,  3245,  2073, -2135,
    3245,  2166,   490,  2283,   258,  1027,  1922, -1534,  2167, -2135,
     259, -2135,  2121,    53,  1928,  2122,  2124,  2123,    53,  1036,
     260,  3241,   317,  1041,  3246,  3405,  2201,  3248,  3408,  3409,
    3410,  3411,   350,   172,   403,  1055, -2135,  2124, -2135,   404,
    2221,   406,   173,   926,  2862,   927,  1201,  2125,  1992,   102,
     103,  2310,  1986,  2311,  2390,    31,   262, -2135, -2135,  1961,
    1981,   344,    53,  1969,  1978,  1969,  2126,  2763,  2243,  2690,
    2765,    53,  2890,   304,  3427,    57,   997, -2135,  2234,   997,
    1394,  1993,  1996,  1998,  1999,  1005,  1395,  1396,  1397,  2127,
    2360,  3249,  2192,  2128,   361,  1004,    53,    31,  3321,    31,
    3324,  3325,  3326,  3327,   997,    57,  1398,    57,    57,    57,
    3463,   305,   318,  3389,  3390, -2135,    57,    57, -2135,   306,
      57,   394,    53,   394,    57,   307,   174,   175,   308,   413,
    2382,  2124,  3433,  2203,  2039,  3030,  3473,    31,   309,    57,
   -2135,  3030,  3030,  -272,  3030,  3030,  3030,  3030,   337,  3446,
    2129,  1256,  2848,  3030,   995,  2447,    31,  2312,   341,  2522,
    2313,  2725,  2525,  2526,  2527,  2528,   362,  2849,  2850,    53,
    2255,  2129,  2460,  1461,  1203,  1204,  2851,   363,   380,  2293,
     894,  2742,  2124,  3428,    57,   372,   342,  3429,   423,  1339,
    2256,   345,  2927,  2124,   349,  3450,  3433,  3452,  3259,    31,
     102,   103,  1210,   895,  2304,  3351,  2052,   371,  3121,  2069,
    2852,   394,   394,  3446,  1399,    31,   394,  1400,    57,  2853,
    2079,  2080,  3022,  3022,  2326,  1401,  3022,   381,  2257,  2017,
    -272, -2135,  2117,   352,  2118,  2119,  2120,  3153,   356,  1455,
    2258,    31,  2181,    57,    31,  3428,  -272,   387,  2854,  3429,
     390,  2259,  3030, -2135, -2135,  3030,  3030,  3030,  3030,  3444,
    1402,  2097,   103,  1462,   364,  2129,    31,  1057,  2260,  2368,
    2467,   391,   373,  3260, -2135,   424,  1063,   418,  2261,  3245,
     365,  2262,   420,  3244,  1163,   421,  3244,  1166,   374,  -272,
    1169,   425,  1889,  2855,  2263,  1403,  1144,   432,  2602,  2882,
    1150,  2884,  2885, -2135,  1154, -2135,  1904,  2509, -2135, -2135,
    1899,  2616,  1900,  2617,  1404,  1405,  2129,   442,  1984,  2903,
      31,  1162,  2628,   366,  1165,  1406,  2348,  2129,  -272,   435,
    1407,   375,  2221,   436,   426,  2856,  3261,  3030,  3262,  2196,
    2940,  2197,  2264,  2966,   438,  3030,  3064,  3064,  2010,  3064,
    2010,   439,  3064,  3263, -2135,   440,  2937,  -272,  2111,  2112,
   -2135,  3264,   367,   441,  3138,  3265,  -272,  3135,   491,  1408,
     376,   502,  2265,   427,   504,  3484,  2981,    31,   508,  1890,
    2176,  2177,  2266,  2323,  2324,  2182,  1184,  1185,  1392,   516,
    3266,   368,   510,  1905,  2510,  1891,   511,  1016,  1016,   377,
     369,  1409,   428,  2267,  2183,  2184,   514,  2268,   378,  1906,
    2511,   429, -2135,  3459,  3460,   519, -2135, -2135,   515, -2135,
     520,  3022,  3199,  3200,  2185,  1256,   531,  3022,  3022, -2135,
    3022,  3022,  3022,  3022, -2135,  2269,  1417,  1418,  1892,  3022,
    1421,  1422, -2135,   530,  2270,   535, -2135,  1929,  1930,  1931,
    1932,   532,  1907,  2512,   550,   540,  3346, -2135,   403,   551,
    3260,   556,   561,   404,   405,   406,   562,  2152,   566,  2611,
    2604, -2135,   573,  2156,   579,  2767,   582,  1893,   310,   311,
     312,   313,   314,   583,  2618,  2619,  2017,  2622,  2945,   584,
    2779,  1908,  2513,  1016, -2135,   587,   612,  2953,  2954,  2121,
     615,  2803,  2122,  1174,  2123,  2643,  1894,  3213,  3214,  3215,
    3216,   621,   622,  2648,   627,  1895,  1437,  1438,  1439,  1440,
    1909,  2514,   631,  3261,  2124,  3262,   331,   332,   333,  1910,
    2515,  1931,  1932,   630,  2125,   632,   629,   633,  3022,   634,
    3263,  3022,  3022,  3022,  3022,   988,   650,   640,  3264,     1,
     899,   904,  3265,  2414,   906,   907,  1933,  1934,  1935,  1936,
    1937,  1938,  2682,  2713,  2679,  3244,  2189,   908,   913,   923,
     924,  1159,   394,   394,   925,  1393,  2127,  3266,    57,    57,
    2128,   931,   936,   938,  2235,  3215,  3216,   940,  1261,   941,
    2335,  1263,   942,  1264,  1265,  1266,  1267,  1268,  2148,   959,
     961,  1005,  1005,  2745,   966,   968,  2157,   969,  2157,   970,
    1005,   972,   973,   974,   975,  2893,  1933,  1934,  1935,  1936,
    1937,  1938,   977,  3022,  1151,  1212,  3064,  1213,  1214,  2907,
    1215,  3022,  1216,  2240,    57,  2390,  2405,  2407,  1933,  1934,
    1935,  1936,  1937,  1938,  1217,  2193,  2221,  1250,  2221,  1218,
    1219,  1220,   988, -2135,  1221, -2135, -2135, -2135,  2129,  1224,
    2739,  2322,  2740,  1223,  1225,  1226,  1256,  2327,  1227,  1228,
     988,  1262,  1269,   997,  1270,  1249,  1271,  1274,  1275,  1277,
    2417,  1249,  1249,  1005,  1278,  1279,  1280,  1249,  1249,  1249,
    1249,   994,  1933,  1934,  1935,  1936,  1937,  1938,   997,  1281,
    1282,  1283,  1394,  1291,  1012,  1287,  2347,  3166,  1395,  1396,
    1397,  1005,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   626,  1293,  1292,  1969,  1294,  1174,  1298,  1398,  1317,
    1318,  1321,  1030,   103,  1324,  1978,  1323,   459,  1969,  1326,
    1325,  1328,  1327,  1330,  1346,  1351,  1350,    57,  1047,  1048,
    1354,  1355,  3076,  1357,  1054,  1288,  1362,  1056,  1358,  2291,
    1374,  1363,  1376,  1365,  2295,  1381,  1414,  1424,  1078,  1427,
    1451,  1443,  1452,  1453,  1454,  1458,  1460,  1463,  1473,  1464,
    1475,  1813,  3168,  1812,  1814,   559,  1113,  1815,  1820,  1824,
    1827,  2320,  1830,  1828,  1829,  1876,  1887,  1884,  1898,  1915,
    1916,  2330,  2331,  1917,   394,  2909,  1320,  1918,  2914,  1919,
    1920,  3283,  1921,  1940,  1945,  1963,    57,  1983,  2001,  3291,
    2002,  2003,  2005,    57,  2006,   460,   461,   462,   463,   464,
     465,  2033,  2358,  3296,    57,  2026,  1399,  2007,  2020,  1400,
    1434,   466,   467,   468,  2035,  2037,  2040,  1401,  2050,  2060,
    2051,  2061,  2063,  2065,  2070,    57,  2074,  2383,  1476,  2076,
    1249,  2085,  2603,   997,    57,  2092,  1108,  2094,  2099,  2658,
    2100,  1822,  2102,  2138,  2136,  2139,  2141,  2190,  2147,   394,
     394,  2194,  1402,  2195,  1174,  2198,  2222,  2200,  2214,  2236,
    2246,  2248,  2249,  2252,   394,  2253,  2281,  2279,  2284,    57,
      57,    57,  2285,  2282,  2297,    57,  2299,  2286,  3136,  2288,
    2300,  2301,  2302,  1005,  2305,  2303,  2306,  1403,  2307,  3339,
   -2135,  2309,  3144, -2135,  2308, -2135,  1821,  2321,  2337,  2339,
    2340,    57,  2344,  2346, -2135,  2352,  1404,  1405,  2353,  2499,
    2499,  1250,  1250,  2499,  2359, -2135,  2362,  1406,   180,  2363,
    1250,  2366,  1407,  2386,  2380, -2135,  2445,  1249,  2372,  1187,
    2398,  2400,  2446,  3383,  2463,  1249,  2471,   988,  1249,  1249,
    1249,  1249,  2529,   988, -2135,  1005,  2472,  2457,  2486,  2534,
    1249,  2489,   469,  2552,  2496,   470,  2508,  2488,  2507,  2520,
    2521,  1408,  2533,   988,  2549,  2554,  2777, -2135,  2780,  2556,
    2557, -2135,  2565,  2558,  1249,  2562,  2571,  2571,  2601,  2608,
    2571,  1249,  3085,  3086,  3087,  2583,  3089,  3090,  3091,  3092,
    3093,  3094,  2613,  1409,  2586,  3097,  2587,  3250,  2624,  2803,
    2642,  2588,  2589,  2590,  2644,  2645,  2646,  2599,  2649,  2655,
    1993,  2656,    57,  2662,  2659,  2660,  2605,  2661,  2680,  2663,
    1969,  2664, -2135,  2681,  1969,    57,  2683,    57,  2684,  2685,
    2689,  3388,  1186,  2571,  2696,  3456,    57,  2320,  2698,  2707,
    2633,  2633,  3434,  3435,  3436,  3437,  3438,  3439,  2708, -2135,
    2709,  2712,  2716,  1078,  2724,  2717,  2726,  2747,  2752,  1113,
    2761,  2764,  2647,  1174,  2760,  2776,  2781,  2766,  2768,  2769,
    2770,  2771,  2782,    57,   471,  2804,  2807,  2867,  2868,  1113,
    2869,  2875,   394,  3158,  2880,  2883,  2894,  2877, -2098,   472,
    2904,  2905,  2908,   473,  2910,  2911,  2918,  2922,  2926,  2929,
    2944,  2952,    57,  2976,  2941,  2987,  2962,  2996,  3003,  1924,
    3041,  2988,  3045,  1256, -2135,  1840,  3174,  3052,  3054,  3053,
    3055,  3057,  3066,  1913,  3069,  3077,  3079,  3285,  2691,  3084,
    1016,   474,  3088,  3095,  3096,  3103,  3102,  3106,  3107,  1953,
    3108,  3109,   548,  2221,  3110,  3111,  3124,  3128,  3112,  3118,
    3126,  3133,  3140,  3145,  3146,  3147,  3148, -2135,  3162,   475,
    3164,  3023,  3023,  3023,  3023,  3167,  3179,  3171,  1181,  3182,
    3186,  3192,  3202,  3203,  3204,  3211,  1005,   476,  3205,  3206,
    3207,  2977,  3208,  2979,  3221,  3222,  3232,  3451,  3235,  3257,
    2865,  2571,  3239,  3275,   988,   988,  3278,  3253,  3276,  2728,
    2157,  1249,  3279,  3280,  3281,   892,  3284,  3288,  3290,  3294,
    3295,  3297,  3299,  3301,  2571, -2135,  1005,  3298,  1841,  3307,
      57,  2499,  3303,  3067, -2135,  3070,  1842,  1925,  2964,  3317,
    3319,  3328,  1843,  3336,  1844,  3508,  3352,  3362,  3363,  3402,
    3005,  3006,  2327,  3364,  3366,  1845,   267,  1232,  1233,    31,
    3369,  1249,   456,   457,   458,  3365,  3387,  3381,   477,  1005,
     892,  1005,  3394,  3382,  1249,  3404,  1249,  2943,  3368,  3440,
     626,   459,  3414,  1846,  3417,  3425,  3453,  1249,  3462,   626,
     626,  3464,  2571,    57,  2552,    60,  3465,  3466,  3467,  1847,
    3477,  3494,  3498,  2571,  1848,  2948,  3499,  2900,  2571,  3286,
    3476,  3496,  1284,  2371,  2672,  3497,  1849,  1969,  2084,  3507,
    1078,  1078,    49,  1850,   180,    48,   800,  2629,  2925,  2638,
     512,  3007,   189,  1978,   478,  1969,   507,   194,   336,    57,
     967,  3308,  2237,   513,   643,  2238,  2291,   930,   339,   903,
    1901,   539,   537,    57,   909,  3474,  2294,  1276,  1138,   152,
     183,   569,  2497,  1880,   910,  2505,  2620,  2110,  2332,   460,
     461,   462,   463,   464,   465,  3181,  2975,  2114,  2320,  2397,
    2928,  2688,  2930,  2571,  3495,   466,   467,   468,  2627,  3402,
    3293,  2415,  2030,    44,   126,    45,  3270,    57,    46,    57,
    2949,    57,  1211,  2378,  1053,  2381,   501,  1297,  2135,  2970,
    2385,  3258,  3353,  2022,    57,  3480,  2055,  3234,  2968,  1076,
    1818,  1249,    57,    57,   183,  2012,  3116,  3361,  2066,   588,
    3115,  3098,  2860,  3137,   394,  1446,   394,  2614,  2280,  2247,
    3483,  3252,   128,   183,  3023,  3023,    57,    57,  3023,  2718,
    3157,  2746,  1249,  3415,  3119,  2861,  2466,   996,  2581,  3061,
    3159,  2532,  3062,  3247,  2571,  2775,  3274,  3416,  2151,  2864,
    3021,  3021,  3021,  3021,  2571,  2571,    40,  1851,  3503,  2814,
    3198,   129,  1868,  3002,  1852,    57,  2815,  2216,  3251,  2143,
    3047,  2215,  3396,  3197,  1835,  3320,  3337,  3152,  3329,  2108,
     130,   131,  2600,  2029,     0,     0,  1853,  2934,     0,   651,
       0,  1854,  1882,  1174,     0,     0,     0,     0,     0,  1249,
    1249,     0,     0,     0,     0,     0,   469,     0,     0,   470,
    1249,  1249,     0,  1249,     0,     0,  1249,     0,  1249,   132,
       0,     0,  1249,     0,     0,  3443,     0,     0,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   180,     0,   496,   497,     0,     0,     0,
       0,     0,   183,     0,   626,   128,   183,     0,     0,   135,
       0,    57,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,  2571,  3122,  2571,  1250,
       0,     0,     0,     0,   129,  1250,  1250,     0,     0,     0,
       0,  1250,  1250,  1250,  1250,     0,     0,     0,     0,     0,
       0,     0,    57,   130,   131,  3282,  2605,     0,     0,  1969,
       0,  3492,     0,  3023,     0,   138,    57,     0,   471,  3023,
    3023,     0,  3023,  3023,  3023,  3023,  2633,     0,     0,  3154,
    2633,  3023,  1235,   472,   394,     0,     0,   473,   139,     0,
       0,     0,   132,     0,   394,     0,    57,  1236,     0,     0,
       0,     0,     0,   140,   133,    57,     0,     0,     0,     0,
     141,     0,     0,   142,  3008,   134,     0,  3009,     0,     0,
       0,     0,     0,     0,     0,   474,     0,     0,     0,     0,
    3010,   988,   135,     0,   143,     0,     0,     0,   144,     0,
       0,     0,   136,     0,     0,     0,  3183,     0,     0,     0,
       0,     0,  2571,   475,     0,     0,     0,   145,   137,     0,
       0,  2728,     0,  3021,  3021,     0,     0,  3021,   616,  3011,
    3012,   476,     0,     0,     0,   146,     0,     0,  3209,   183,
    3023,     0,  3013,  3023,  3023,  3023,  3023,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,  2571,     0,  2148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1250,     0,  1005,     0,     0,     0,
       0,   139,     0,  3014,   997,     0,     0,   997,     0,     0,
    1249,     0,     0,  1249,   183,  1249,   140,  2571,     0,     0,
       0,     0,     0,   141,     0,     0,   142,  1113,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
      57,     0,  3015,     0,     0,  3023,     0,   143,     0,     0,
       0,   144,     0,  3023,  3016,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3393,     0,  3017,  3018,     0,     0,
     145,     0,     0,     0,  3019,     0,     0,  3020,   394,     0,
       0,    57,     0,     0,     0,   288,   183,     0,   146,     0,
       0,  1250,   154,   155,     0,     0,     0,     0,   478,  1250,
     156,    31,  1250,  1250,  1250,  1250,     0,     0,     0,     0,
     978,   979,   980,   982,  1250,   453,   454,   455,   456,   457,
     458,     0,     0,     0,    57,     0,     0,     0,  1010,  1249,
       0,     0,  2571,     0,     0,     0,     0,   459,  1250,     0,
     997,     0,  3021,     0,     0,  1250,     0,     0,  3021,  3021,
     180,  3021,  3021,  3021,  3021,     0,     0,  2571,     0,  2571,
    3021,     0,  1249,  1032,    57,     0,     0,     0,   157,  1037,
       0,  1039,     0,     0,     0,  1046,     0,     0,  1046,     0,
     158,  1046,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1058,     0,     0,     0,    57,     0,     0,     0,     0,
      57,     0,    57,     0,     0,     0,  1058,     0,   159,   626,
       0,  1106,     0,     0,     0,     0,     0,     0,   982,  1117,
    1120,     0,    57,     0,  1140,   460,   461,   462,   463,   464,
     465,     0,  1152,     0,     0,     0,     0,     0,     0,    57,
       0,   466,   467,   468,     0,     0,     0,     0,  1176,  3183,
       0,     0,     0,     0,     0,  1249,     0,     0,     0,  3021,
       0,     0,  3021,  3021,  3021,  3021,  3412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2148,     0,   459,     0,     0,     0,   997,     0,     0,     0,
    1249,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,   160,     0,     0,     0,     0,     0,     0,    57,    57,
      57,    57,    57,    57,     0,     0,     0,     0,     0,   264,
    3445,     0,     0,     0,     0,     0,     0,     0,   265,   266,
       0,  1081,     0,     0,   267,   268,   269,    31,     0,  1082,
       0,     0,     0,     0,  3021,     0,     0,     0,  1083,     0,
       0,  1084,  3021,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1250,     0,     0,     0,     0,
     460,   461,   462,   463,   464,   465,     0,  2171,  2172,     0,
       0,     0,   469,     0,  2188,   470,   466,   467,   468,     0,
       0,     0,     0,     0,  1085,  1249,     0,  3485,   161,     0,
       0,     0,  1086,     0,   157,     0,     0,     0,     0,   270,
       0,     0,     0,     0,     0,  1250,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1250,     0,
    1250,   162,     0,     0,  3501,  3502,  3485,     0,     0,     0,
       0,  1250,     0,    57,   159,  3509,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1087,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,  1176,     0,     0,     0,     0,     0,     0,   164,     0,
       0,     0,     0,  1088,  1250,  1340,     0,     0,     0,     0,
    1089,     0,  1090,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1091,     0,   471,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,   472,
       0,     0,     0,   473,     0,     0,  1368,   469,  1092,     0,
     470,   166,     0,     0,     0,    53,  1093,   160,     0,   167,
       0,     0,     0,  1388,  1388,  1388,     0,  1388,     0,  1388,
    1388,     0,   168,     0,     0,    60,    60,     0,     0,     0,
       0,   474,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2351,     0,     0,  1094,  1250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   475,
       0,     0,     0,  1120,     0,     0,   169,     0,     0,  1095,
       0,     0,     0,     0,     0,  1471,  1250,   476,     0,     0,
       0,     0,  2395,     0,  2418,  2419,  2420,  2421,  2422,  2423,
       0,   170,     0,     0,  1250,  1250,  1250,  1250,     0,  1176,
    1340,     0,     0,     0,   161,     0,     0,  1096,  1825,   271,
       0,     0,     0,     0,     0,   171,     0,     0,  1097,   471,
       0,     0,     0,     0,  1833,  1833,     0,     0,     0,     0,
       0,     0,     0,     0,   472,     0,     0,   162,   473,     0,
       0,     0,     0,  1250,  1250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1250,  1250,     0,  1250,   477,   172,
    1250,     0,  1250,     0,     0,     0,  1250,     0,   173,     0,
       0,     0,   163,  2424,     0,     0,   474,     0,     0,     0,
       0,  1016,  1016,  1016,   164,  1016,  1016,  1016,  1016,  1016,
    1016,     0,     0,     0,  1016,     0,     0,     0,     0,     0,
       0,     0,   272,     0,   475,     0,     0,   273,     0,     0,
     274,     0,     0,     0,     0,     0,  1098,  1099,  1100,     0,
       0,   165,   476,     0,   478,     0,     0,   275,     0,  1101,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
       0,     0,   276,     0,     0,   277,     0,     0,   278,     0,
       0,     0,   174,   175,     0,     0,     0,   279,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,     0,    60,  1120,  1046,     0,
       0,     0,     0,     0,     0,  2021,  1058,     0,     0,  1120,
       0,     0,     0,  2031,     0,     0,     0,  1336,   280,     0,
       0,     0,   169,   477,     0,     0,     0,     0,  1176,  1174,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,  1102,     0,     0,     0,     0,  2668,  2669,     0,
       0,     0,     0,     0,     0,   264,     0,     0,  2678,     0,
       0,   283,     0,    60,   265,   266,     0,     0,     0,     0,
     267,   268,   269,    31,     0,     0,     0,  1250,  1250,   478,
       0,  1250,     0,     0,  2692,  2693,  2694,  2695,     0,     0,
       0,     0,  2700,  2701,  2702,  2703,     0,  2077,     0,  2705,
       0,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,   284,     0,   173,     0,     0,  2425,     0,     0,
       0,     0,  2104,     0,   285,   286,     0,     0,     0,     0,
    2426,     0,   287,     0,     0,     0,     0,     0,  1250,     0,
     157,  1250,     0,   288,  1250,   270,     0,  1250,     0,  1250,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2750,  2751,     0,
     159,     0,     0,     0,  2755,  2756,     0,     0,     0,     0,
       0,     0,     0,     0,  2427,     0,     0,     0,   174,   175,
       0,  2428,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   443,   444,
     445,     0,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,     0,     0,  2536,     0,     0,
    2429,     0,     0,     0,     0,     0,  1229,  1230,  1231,     0,
       0,   459,   267,  1232,  1233,    31,     0,     0,     0,     0,
       0,     0,     0,  1250,  2430,     0,     0,     0,     0,     0,
       0,    53,     0,   160,  2431,  2432,  1250,     0,     0,     0,
    2433,     0,  1250,  1250,     0,  1250,  1250,  1250,  1250,     0,
    2434,     0,     0,     0,  1250,     0,  1250,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,     0,
       0,  1250,  2435,  2916,  2917,  2436,  2437,     0,     0,     0,
    2438,     0,  2924,     0,     0,   459,     0,  1234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,     0,     0,     0,     0,     0,
       0,     0,     0,  2955,  2956,   466,   467,   468,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,  1174,     0,   271,     0,  2439,     0,     0,
    2978,     0,  2980,     0,     0,     0,     0,     0,  2440,  1250,
       0,     0,     0,  1250,     0,     0,  1250,  1250,  1250,  1250,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,   461,   462,   463,   464,   465,     0,
    1250,     0,     0,     0,  1250,     0,     0,     0,     0,   466,
     467,   468,     0,     0,     0,     0,  3048,  3049,   163,     0,
    3050,  3051,     0,     0,     0,     0,   264,     0,     0,     0,
     164,     0,     0,   996,     0,   265,   266,  2134,  1176,     0,
       0,   267,   268,   269,    31,     0,     0,     0,   272,     0,
       0,     0,     0,   273,     0,     0,   274,     0,  1250,     0,
       0,     0,     0,     0,     0,     0,  1250,   165,     0,     0,
       0,     0,     0,   275,     0,     0,   469,     0,     0,   470,
       0,     0,     0,   166,     0,     0,     0,     0,   276,     0,
       0,   277,     0,  2175,   278,     0,     0,     0,     0,     0,
       0,     0,     0,   279,   168,     0,     0,     0,     0,  1250,
    3105,   157,     0,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2537,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,   169,     0,
     469,   159,     0,   470,     0,     0,   281,  1174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,  2621,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,  3151,     0,  3005,  3006,  3156,     0,     0,     0,
     267,  1232,  1233,    31,     0,     0,     0,   283,   471,     0,
       0,     0,  3161,     0,     0,     0,  1120,     0,     0,     0,
       0,     0,     0,   472,     0,     0,     0,   473,     0,     0,
       0,  3172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1235,     0,
       0,   172,    53,     0,   160,     0,     0,     0,   284,     0,
     173,     0,     0,  1236,     0,   474,     0,     0,     0,     0,
     285,   286,     0,     0,     0,  3007,     0,     0,   287,     0,
    1237,     0,   471,  2538,     0,  2343,     0,     0,     0,   288,
       0,     0,  2350,   475,     0,  2539,  1239,   472,     0,     0,
       0,   473,     0,  1120,     0,     0,     0,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1913,   152,   264,     0,     0,     0,     0,
       0,     0,     0,  2392,   265,   266,  1240,     0,     0,   474,
     267,   268,   269,    31,   174,   175,     0,     0,  1241,     0,
       0,   161,   947,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   475,  1120,  2449,
    1120,     0,     0,     0,   982,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   476,     0,     0,     0,  1242,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
    2491,   996,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,     0,     0,     0,   270,     0,     0,     0,   163,
       0,     0,   158,     0,     0,     0,     0,     0,  1243,     0,
       0,   164,     0,     0,     0,     0,     0,     0,     0,     0,
    1244,     0,     0,     0,     0,     0,     0,     0,  3306,   272,
     159,  3309,  1245,  1246,   273,     0,     0,   274,   478,     0,
    1247,     0,     0,  1248,     0,     0,   477,     0,   165,     0,
       0,   288,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,   276,
       0,     0,   277,     0,     0,   278,     0,     0,     0,     0,
       0,     0,     0,     0,   279,   168,     0,     0,     0,     0,
       0,  1120,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1120,     0,  1120,     0,     0,     0,
       0,     0,   478,     0,     0,  1120,     0,     0,     0,     0,
       0,    53,     0,   160,  2965,   280,     0,     0,     0,   169,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,  2653,     0,   170,     0,     0,     0,  3391,     0,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2536,     0,     0,     0,     0,   283,   459,
       0,  2677,  1229,  1230,  1231,     0,  1235,     0,   267,  1232,
    1233,    31,     0,     0,     0,     0,  1229,  1230,  1231,     0,
       0,  1236,   267,  1232,  1233,    31,     0,  3418,  3419,     0,
    3421,     0,  3423,  3424,     0,     0,     0,     0,  3008,     0,
     161,  3009,   172,     0,     0,   271,     0,     0,     0,   284,
       0,   173,     0,     0,  3010,     0,     0,     0,     0,     0,
       0,   285,   286,     0,     0,     0,     0,     0,     0,   287,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
     288,  1913,     0,  1234,     0,     0,     0,   460,   461,   462,
     463,   464,   465,  3469,  3012,  3470,     0,  1234,     0,     0,
       0,     0,     0,   466,   467,   468,  3013,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2748,
     164,     0,     0,     0,     0,     0,     0,     0,  3482,     0,
       0,     0,     0,     0,     0,   174,   175,     0,   272,     0,
       0,     0,     0,   273,  3489,  3490,   274,  3014,  3491,     0,
   -2136,  3493,  1229,  1230,  1231,     0,     0,   165,   267,  1232,
    1233,    31,     0,   275,     0, -2136,     0, -2136, -2136, -2136,
       0,     0,     0,   166,     0,     0,     0,     0,   276,     0,
       0,   277,  1120,     0,   278,     0,  3015,     0,     0,     0,
       0,     0,     0,   279,   168,     0,     0,     0,  3016,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   996,
    3017,  3018,     0,     0,     0,     0,     0,     0,  3019,     0,
       0,  3020,     0,   996, -2136,     0,     0,     0,  1120,   288,
       0,     0,     0,  1234,   280,     0,     0,     0,   169,     0,
       0,     0,  1120,     0,   469,     0,   281,   470,     0,     0,
       0,     0,     0, -2136,     0,     0,     0,   282,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,  2817,  2818,     0,  2819,  2820,  2821,     0,     0,
       0,     0,     0,     0,     0,     0,  2946,   283,  1010,     0,
    2950,     0,     0,     0,     0,     0,     0,     0, -2136,     0,
       0,     0,     0,  2961,     0,     0,     0,     0,   183,     0,
       0,  2969,  2392,  2537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2136,  2537, -2136,     0,
       0,   172,     0,     0,     0,  2983,  2985,     0,   284,  1231,
     173,     0,     0,   267,  1232,  1233,    31,     0,     0,     0,
     285,   286,     0, -2136,     0,     0,     0,     0,   287,   996,
       0, -2136,     0, -2136,     0,     0,   471,     0,     0,   288,
       0,     0, -2136,     0,  3046,  2822,     0,     0, -2136,     0,
       0,   472,     0,  2823,     0,   473, -2136,     0,     0,     0,
   -2136,     0,     0,     0,     0,     0, -2136,     0,     0,     0,
   -2136, -2136, -2136, -2136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1235, -2136,     0,  2824,  1234,     0,
       0,     0,     0,   474,   174,   175,  2825,     0,  1235,  1236,
       0,     0, -2136,     0,     0, -2136,     0, -2136,     0,     0,
       0,     0,     0,  1236, -2136,     0,  1237,     0,     0,  2538,
       0,   475,     0,     0,     0,  2826,  2827, -2136,     0,     0,
    1237,  2539,  1239,  2538,     0,     0,     0, -2136,     0,   476,
    3099,     0,     0,     0,     0,  2539,  1239,     0,     0,     0,
       0,     0,     0,  3114,     0,     0, -2136, -2136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2828, -2136,  1240,     0,     0,     0,     0,     0,     0, -2136,
       0,     0,     0, -2136,  1241,     0,  1240,     0,     0,     0,
       0,  1120, -2136, -2136, -2136,     0,     0,     0,  1241,     0,
       0,     0,     0,     0,     0,  1120,     0,     0,     0,     0,
       0,     0,  2829,     0,   996,     0,     0,   183,     0,     0,
     477,     0,     0,     0,     0,  1242,     0,     0,     0,     0,
       0,     0,     0,     0,  1235,  2392,     0,     0,     0,  1242,
       0,     0,     0,     0,  1176,     0,     0,     0,     0,  1236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2136,     0,     0,  1243,     0,  1237,     0,  2830,  1238,
       0,     0, -2136,     0,     0,     0,  1244,     0,  1243,     0,
       0,     0,  1239,     0,     0,     0,   478,     0,  1245,  1246,
    1244,     0,     0,     0,     0,     0,  1247,     0,     0,  1248,
       0,     0,  1245,  1246,     0,     0,     0,   288,     0,  1913,
    1247,     0, -2136,  1248,     0,     0,     0,     0,     0,     0,
       0,   288,  1240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2136,     0,  1242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1488,  1489,  1490,
    1491,  1492,  1493,     0,  1494,  1495,  1496,     0,     0,  3099,
    1497,  1498,  1499,  1500,  1501,  1502,     0,     0,     0, -2136,
       0,     0,     0,     0,  1243,  1503,     0,     0,     0,  1235,
       0,     0,     0,     0,     0,     0,  1244,     0,     0,     0,
       0,  1504,     0,     0,  1236,     0,     0,     0,  1245,  1246,
    1120,     0,     0,     0,     0,     0,  1247,     0,     0,  1248,
       0,  1237,     0,     0,  1238, -2136,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1239,     0, -2136,
   -2136, -2136, -2136, -2136, -2136, -2136,     0, -2136, -2136,  1505,
       0,     0,     0,  2392,     0,     0,     0,     0,  1506,     0,
       0,     0,     0,     0, -2136,  2831,  2832,  2833,  2834,  2835,
    2836,  2837,  2838,  2839,  2840,     0,  1507,  1240,  1508,     0,
       0,     0,     0,     0,     0,     0,  1509,     0,     0,  1241,
       0,  1510,  1511,  2392,     0,  1512,  1513,  1514,  1515,     0,
       0,  1516,  1517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3099,     0,     0,     0,     0,  3356,
    1242,  3358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1518,     0,     0,     0,     0,     0,     0,     0,
       0,  1120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1519,     0,     0,     0,  1176,  1243,
    1520,     0,     0,     0,   183,     0,  2107,  1521,     0,  1522,
       0,  1244,     0,     0,     0,  1523,     0,     0,     0,     0,
       0,     0,     0,  1245,  1246,     0,     0,     0,     0,     0,
       0,  1247,     0,     0,  1248,     0,     0,     0,     0,     0,
    1524,     0,   288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1388,  1388,  1388,
    1388,  1388,  1388,     0,     0,     0,     0,     0,  1525,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1526,     0,     0,     0,     0,     0,  1527,     0,     0,
       0,     0,     0,     0,     0,     0,  1528,  1529,     0,     0,
       0,     0,     0,  1530,     0,     0,  1531,  1532,     0,     0,
       0,  1533,     0,     0,     0,     0,     0,  1534,  1535,     0,
       0,     0,     0,     0,  1536,  1537,  1538,  1539,  1540,  1541,
       0,     0,     0,  1542,     0,     0,     0,  1543,     0,  1544,
       0,     0,     0,     0,     0,     0,  1545,  1546,  1547,  1548,
       0,  1549,  1550,     0,     0,     0,  1551,  1552,     0,  1553,
    1554,  1555,     0,  1556,  1557,  1558,  1559,     0,     0,     0,
       0,     0,  1560,  1561,  1562,     0,  1563,  1564,     0,     0,
       0,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,     0,
    1573,     0,  1176,     0,  1574,  1575,  1576,  1577,  1578,  1579,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,
    1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,
    1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,
    1610,  1611,     0,  1612,  1613,     0,     0,  1614,  1615,  1616,
    1617,  1618,  1619,  1620,  1621,  1622,  1623,     0,  1624,  1625,
    1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,
    1636,  1637,  1638,     0,     0,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,  1646,  1647,     0,  1648,  1649,  1650,  1651,     0,
    1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,
    1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,     0,  1688,  1689,  1690,
    1691,  1692,  1693,     0,     0,  1694,  1695,     0,  1696,  1697,
    1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,
    1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,
    1718,  1719,  1720,  1721,     0,     0,  1722,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,     0,     0,
       0,     0,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1795,     0,     0,     0,     0,     0,     0,
       0,  1796,     0,     0,     0,     0,  1797,     0,     0,     0,
    1798,     0,     0,  1799,  1800,  1801,  1802,     0,     0,  1803,
    1804,     0,  1805,  1806,  1807,  1488,  1489,  1490,  1491,  1492,
    1493,     0,  1494,  1495,  1496,     0,     0,     0,  1497,  1498,
    1499,  1500,  1501,  1502,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1504,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1505,     0,     0,
       0,     0,     0,     0,     0,     0,  1506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1507,     0,  1508,     0,     0,     0,
       0,     0,     0,     0,  1509,     0,     0,     0,     0,  1510,
    1511,     0,     0,  1512,  1513,  1514,  1515,     0,     0,  1516,
    1517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1518,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1519,     0,     0,     0,     0,     0,  1520,     0,
       0,     0,     0,     0,     0,  1521,     0,  1522,     0,     0,
       0,     0,     0,  1523,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1525,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1526,
       0,     0,     0,     0,     0,  1527,     0,     0,     0,     0,
       0,     0,     0,     0,  1528,  1529,     0,     0,     0,     0,
       0,  1530,     0,     0,  1531,  1532,     0,     0,     0,  1533,
       0,     0,     0,     0,     0,  1534,  1535,     0,     0,     0,
       0,     0,  1536,  1537,  1538,  1539,  1540,  1541,     0,     0,
       0,  1542,     0,     0,     0,  1543,     0,  1544,     0,     0,
       0,     0,     0,     0,  1545,  1546,  1547,  1548,     0,  1549,
    1550,     0,     0,     0,  1551,  1552,     0,  1553,  1554,  1555,
       0,  1556,  1557,  1558,  1559,     0,     0,     0,     0,     0,
    1560,  1561,  1562,     0,  1563,  1564,     0,     0,     0,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,     0,  1573,     0,
       0,     0,  1574,  1575,  1576,  1577,  1578,  1579,  1580,  1581,
    1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,
    1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,
       0,  1612,  1613,     0,     0,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,     0,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,
    1638,     0,     0,  1639,  1640,  1641,  1642,  1643,  1644,  1645,
    1646,  1647,     0,  1648,  1649,  1650,  1651,     0,  1652,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,     0,  1688,  1689,  1690,  1691,  1692,
    1693,     0,     0,  1694,  1695,     0,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,     0,     0,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,
    1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,
    1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,
    1778,  1779,  1780,  1781,  1782,  1783,     0,     0,     0,     0,
    1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,
    1794,     1,     0,     0,     0,     0,   653,   654,   655,     0,
       0,  1795,     0,     0,   656,     0,     0,     0,     0,  1796,
       0,   657,     0,     0,  1797,     0,     0,     0,  1798,     0,
       0,  1799,  1800,  1801,  1802,     0,     0,  1803,  1804,     0,
    1805,  1806,  1807,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     658,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   659,   660,     0,   661,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   662,
       0,     0,     0,     0,     0,     0,   663,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   664,   665,   666,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   667,     0,   668,   669,   670,     0,     0,
       0,     0,     0,     0,     0,     0,   671,   672,     0,   673,
     674,   675,     0,     0,     0,     0,     0,   676,     0,     0,
     677,     0,   678,   679,   680,     0,     0,     0,     0,     0,
     681,     0,   682,   683,     0,   684,     0,   685,   686,     0,
       0,   687,     0,     0,   688,   689,   690,     0,   691,   692,
       0,     0,     0,   693,   694,   695,     0,   696,     0,     0,
       0,   697,     0,   698,   699,     0,     0,     0,     0,   700,
       0,     0,     0,   701,     0,     0,   702,     0,   703,     0,
     704,     0,   705,     0,   706,   707,     0,   708,   709,   710,
       0,     0,     0,   711,     0,   712,   713,     0,   714,     0,
       0,     0,     0,     0,     0,     0,   715,   716,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   717,
       0,     0,   718,   719,     0,     0,   720,   721,     0,     0,
     722,   723,     0,     0,     0,     0,     0,     0,     0,   724,
     725,   726,     0,   727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   728,   729,   730,     0,   731,     0,     0,
       0,   732,   733,     0,     0,     0,   734,     0,     0,     0,
       0,     0,     0,     0,   735,     0,     0,     0,     0,     0,
       0,     0,   736,   737,   738,     0,     0,     0,     0,     0,
     739,   740,     0,     0,     0,     0,   741,     0,     0,   742,
       0,     0,     0,   743,   744,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   746,     0,     0,     0,     0,     0,     0,     0,
     747,     0,     0,     0,     0,     0,   748,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     0,     0,     0,   750,     0,   751,   752,
       0,     0,     0,     0,     0,     0,     0,   753,     0,  2654,
     443,   444,   445,     0,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,     0,     0,   754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   757,   758,
       0,     0,     0,   759,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   760,     0,     0,     0,     0,
       0,   761,   762,   763,   764,     0,     0,     0,   765,     0,
       0,     0,   766,     0,     0,     0,     0,     0,     0,   767,
     768,   460,   461,   462,   463,   464,   465,     0,     0,     0,
     769,     0,   770,     0,     0,     0,     0,   466,   467,   468,
       0,     0,     0,   771,     0,   772,     0,     0,   773,     0,
       0,   443,   444,   445,   774,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     775,     0,     0,   776,   459,     0,     0,     0,   777,     0,
       0,   778,   779,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   780,     0,     0,     0,
     443,   444,   445,   781,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   782,   783,   784,   785,
     786,   787,   788,   459,     0,   789,     0,   790,     0,   791,
       0,   443,   444,   445,     0,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,     0,
       0,     0,   460,   461,   462,   463,   464,   465,   469,     0,
       0,   470,     0,     0,   459,     0,     0,     0,   466,   467,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   443,   444,   445,     0,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,     0,
       0,   460,   461,   462,   463,   464,   465,     0,     0,     0,
       0,     0,     0,     0,     0,   459,     0,   466,   467,   468,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   460,   461,   462,   463,   464,   465,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,   467,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
       0,     0,   470,   460,   461,   462,   463,   464,   465,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     467,   468,     0,     0,     0,     0,     0,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,     0,     0,   469,     0,
       0,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
       0,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
     473,   565,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
     469,     0,     0,   470,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,   473,
     575,     0,     0,     0,     0,     0,   475,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,   471,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,   474,     0,     0,
     473,   585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3005,  3006,   475,     0,     0,     0,   267,
    1232,  1233,    31,     0,     0,     0,     0,     0,   474,     0,
       0,     0,   471,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,   473,   937,     0,     0,   477,   475,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   443,   444,   445,   476,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,   474,
       0,     0,     0,     0,  3007,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,   475,   443,   444,
     445,   478,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   459,     0,     0,     0,   477,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   460,   461,   462,   463,   464,   465,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,   467,
     468,     0,     0,     0,     0,     0,   477,     0,     0,     0,
     996,   478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   466,   467,   468,     0,     0,
       0,     0,     0,   443,   444,   445,     0,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
       0,     0,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,     0,   443,   444,
     445,     0,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   443,   444,
     445,   459,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,     0,     0,     0,     0,   469,
       0,     0,   470,     0,     0,     0,     0,     0,   443,   444,
     445,   459,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   460,   461,   462,   463,   464,   465,
       0,   459,     0,     0,     0,     0,   469,     0,     0,   470,
     466,   467,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,  1235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   466,   467,   468,     0,     0,
    1236,     0,     0,     0,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,     0,     0,  3008,     0,     0,
    3009,     0,     0,     0,     0,   466,   467,   468,     0,     0,
       0,   471,     0,  3010,     0,     0,     0,     0,     0,   460,
     461,   462,   463,   464,   465,     0,   472,     0,     0,     0,
     473,   943,     0,     0,     0,   466,   467,   468,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3012,     0,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,  3013,     0,     0,   474,     0,
       0,     0,     0,   472,     0,     0,     0,   473,   944,     0,
       0,   469,     0,     0,   470,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   475,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3014,     0,     0,     0,
       0,     0,     0,     0,   476,   474,   469,     0,     0,   470,
       0,     0,     0,     0,     0,   443,   444,   445,     0,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,     0,   475,     0,  3015,   469,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,  3016,   459,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,  3017,
    3018,     0,     0,     0,     0,     0,   469,  3019,     0,   470,
    3020,     0,     0,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,     0,     0,   477,     0,     0,     0,     0,
       0,     0,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,   473,   945,     0,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   471,     0,
       0,     0,   477,     0,     0,     0,   460,   461,   462,   463,
     464,   465,     0,   472,   459,     0,     0,   473,   946,     0,
     474,   478,   466,   467,   468,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,     0,     0,     0,   473,   475,     0,
       0,     0,     0,     0,     0,   474,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,   476,     0,   478,     0,
       0,     0,     0,   472,     0,     0,     0,   473,     0,     0,
       0,     0,     0,   475,     0,   474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   948,     0,
       0,   476,   460,   461,   462,   463,   464,   465,     0,     0,
       0,     0,     0,   475,     0,   474,     0,     0,   466,   467,
     468,     0,     0,     0,     0,     0,     0,     0,   949,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,   443,   444,   445,   477,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   476,     0,   469,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   459,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
     444,   445,     0,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,     0,     0,     0,     0,
       0,     0,   477,   478,     0,     0,     0,     0,     0,     0,
       0,     0,   459,     0,   445,     0,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,     0,
       0,     0,   477,     0,     0,     0,     0,     0,   478,     0,
       0,     0,     0,     0,     0,   459,     0,     0,     0,   469,
       0,     0,   470,     0,     0,   460,   461,   462,   463,   464,
     465,     0,     0,     0,     0,     0,     0,     0,   478,     0,
       0,   466,   467,   468,     0,   471,     0,     0,     0,     0,
       0,   267,  1232,  1233,    31,     0,     0,     0,     0,     0,
     472,     0,     0,     0,   473,     0,     0,     0,   478,     0,
     460,   461,   462,   463,   464,   465,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   467,   468,     0,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,     0,   474,   460,   461,   462,   463,   464,   465,     0,
       0,     0,     0,     0,     0,   952,     0,   459,     0,   466,
     467,   468,     0,     0,     0,     0,  3007,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,     0,     0,  1229,  1230,  1231,     0,   476,     0,
     267,  1232,  1233,    31,     0,     0,   472,     0,     0,     0,
     473,     0,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   451,   452,   453,   454,   455,   456,   457,   458,
       0,     0,   469,     0,     0,   470,     0,     0,   459,     0,
       0,     0,     0,     0,     0,     0,   459,     0,   474,     0,
       0,     0,     0,     0,     0,   460,   461,   462,   463,   464,
     465,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,   467,   468,     0,  1234,   475,   469,     0,   477,
     470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,   996,     0,     0,     0,     0,     0,     0,     0,
     469,     0,     0,   470,     0,     0,  1229,  1230,  1231,     0,
       0,     0,   267,  1232,  1233,    31,   460,   461,   462,   463,
     464,   465,     0,     0,   460,   461,   462,   463,   464,   465,
       0,     0,   466,   467,   468,   478,     0,     0,     0,     0,
     466,   467,   468,     0,   471,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   472,
       0,     0,     0,   473,     0,   477,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,   453,   454,   455,   456,
     457,   458,     0,     0,     0,     0,     0,  1234,     0,   471,
       0,   996,     0,     0,     0,     0,     0,     0,   459,     0,
       0,   474,   469,     0,   472,   470,     0,     0,   473,   454,
     455,   456,   457,   458,     0,     0,     0,  1229,  1230,  1231,
       0,     0,   471,   267,  1232,  1233,    31,     0,     0,   475,
     459,   478,     0,     0,     0,     0,     0,   472,     0,     0,
       0,   473,     0,     0,     0,     0,   474,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,   475,     0,   470,     0,     0,   474,
       0,   469,     0,     0,   470,     0,   460,   461,   462,   463,
     464,   465,   476,     0,     0,     0,     0,  1235,  1234,     0,
       0,     0,   466,   467,   468,     0,     0,   475,     0,     0,
       0,     0,  1236,   996,     0,     0,     0,     0,   460,   461,
     462,   463,   464,   465,   471,   476,     0,     0,   477,  3008,
       0,     0,  3009,     0,   466,   467,   468,     0,     0,   472,
       0,     0,     0,   473,     0,  3010,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,   196,     0,     0,
       0,     0,     0,   477,     0,     0,     0,     0,     0,     0,
       0,   474,     0,     0,     0,  3012,     0,     0,     0,     0,
       0,     0,     0,     0,   478,   471,  1235,  3013,     0,     0,
       0,     0,     0,   471,     0,     0,   477,     0,     0,   475,
     472,  1236,     0,     0,   473,     0,     0,     0,   472,     0,
       0,     0,   473,     0,   996,     0,     0,   476,  1237,     0,
       0,  1238,     0,     0,     0,     0,     0,     0,  3014,   478,
       0,     0,     0,   469,  1239,     0,   470,   197,   198,     0,
       0,     0,   474,     0,     0,     0,     0,   199,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   478,     0,     0,   469,     0,  3015,   470,     0,
     475,     0,     0,  2387,  1240,     0,     0,     0,   475,  3016,
       0,     0,     0,     0,     0,     0,  1241,     0,   476,     0,
       0,  3017,  3018,     0,     0,     0,   476,     0,   477,  3019,
       0,     0,  3020,     0,     0,     0,     0,     0,  1235,     0,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1236,     0,     0,     0,  1242,  2418,  2419,
    2420,  2421,  2422,  2423,     0,     0,     0,     0,     0,     0,
    1237,     0,     0,  1238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   471,  1239,     0,     0,     0,
       0,     0,     0,     0,   478,     0,  1243,     0,     0,   477,
     472,     0,     0,     0,   473,     0,     0,   477,  1244,     0,
       0,     0,     0,     0,     0,     0,     0,   471,     0,     0,
    1245,  1246,     0,     0,     0,  3399,  1240,     0,  1247,     0,
       0,  1248,   472,     0,     0,     0,   473,     0,  1241,   288,
       0,     0,   474,     0,     0,     0,     0,  2424,   200,  1235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1236,   478,     0,     0,     0,     0,
     475,     0,     0,   478,   474,     0,     0,     0,     0,  1242,
       0,  1237,     0,     0,  1238,     0,     0,   201,   476,     0,
       0,     0,     0,     0,     0,     0,     0,  1239,     0,     0,
       0,     0,   475,     0,     0,     0,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1243,     0,
     476,     0,   204,     0,     0,     0,     0,     0,     0,     0,
    1244,     0,     0,     0,     0,     0,     0,  1240,     0,     0,
       0,     0,  1245,  1246,     0,   205,     0,     0,     0,  1241,
    1247,     0,  3370,  1248,     0,     0,     0,   206,     0,     0,
       0,   288,     0,     0,     0,     0,     0,     0,   207,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
    1242,     0,     0,     0,     0,   209,     0,     0,     0,     0,
       0,   477,     0,     0,     0,     0,     0,     0,  3371,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1243,
       0,     0,     0,  3372,     0,   478,     0,     0,     0,     0,
       0,  1244,  3373,     0,     0,     0,     0,     0,     0,     0,
       0,   211,     0,  1245,  1246,     0,     0,     0,     0,     0,
       0,  1247,     0,     0,  1248,     0,     0,   478,     0,     0,
       0,     0,   288,     0,   212,     0,     0,     0,  3374,     0,
       0,  2425,     0,     0,     0,     0,  3375,     0,     0,   213,
       0,     0,     0,     0,  2426,     0,   214,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,     0,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2427,     0,
       0,   219,     0,     0,     0,  2428,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3376,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,  2429,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2431,  2432,
       0,     0,     0,     0,  2433,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2435,     0,     0,  2436,
    2437,     0,     0,     0,  2438,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2439,     0,     0,     0,     0,     0,     0,     0,     0,
    3377,     0,  2440
};

static const short yycheck[] =
{
       2,     3,     4,   186,   167,     7,   103,   252,   253,   384,
    1307,   145,    43,   630,  1014,  1114,  1080,   763,  1300,  1109,
    1091,   666,   997,  1229,  1230,  1077,   761,   525,    53,  1087,
    1088,   615,  1090,   962,  1092,  1093,    38,  2032,   254,   255,
    1851,   663,  2374,   259,  2199,     5,   123,  1332,  2517,    51,
      20,    53,   169,  1918,  1919,  1920,  1921,    27,    89,  2246,
      62,  1817,  1818,    27,    26,    27,  2253,    69,    27,  1850,
     167,    73,     5,   721,    76,    77,  2733,  2734,  2735,     5,
      82,    83,   551,  1977,   218,  2417,  1915,   567,    39,   186,
     746,    27,  1980,    25,    26,    27,    19,     5,     5,   683,
     102,     5,  1913,    26,    24,    25,    26,    27,     5,   693,
      24,   687,    26,  1966,     5,    66,  1168,   119,    27,   686,
     122,    20,     5,     5,   746,   127,    25,   935,    27,    24,
    1182,    26,     5,  2137,   710,    19,    25,  1201,    27,   256,
      24,    25,    26,   260,  2313,   262,    27,   264,   265,   266,
     135,     5,   315,   230,   231,  2736,   273,   122,   123,   110,
     277,   278,     5,   114,   748,   751,   750,    24,    25,    26,
      27,     5,  1172,     5,    27,   759,    24,    25,    26,   755,
      25,     5,    27,   116,   117,    25,   188,    27,   764,   765,
      27,    97,   768,    20,    27,   103,   772,   105,    25,   107,
      27,  2531,   778,  2533,   780,    97,    23,   206,  2149,  2248,
    2249,     6,   424,  2252,   781,     5,     5,    30,   315,   172,
      27,     5,   319,     5,     5,   227,    24,    25,    26,    27,
      27,   233,     9,    10,   374,    12,    13,    14,    15,    16,
      17,   374,   242,   245,   185,     5,  2764,     5,   198,   251,
     252,   253,   254,   255,     5,   395,    25,   259,    27,   309,
     126,   426,    25,   225,    27,   271,  2305,   185,    25,   220,
      27,  2459,     5,   379,  1249,    27,  2105,     9,    10,   274,
      12,    13,    14,    15,    16,    17,    24,    25,    26,    27,
      83,    84,    85,    86,    87,     0,   465,  2182,     5,     5,
    2185,   418,   173,   174,   421,   225,   308,   309,   610,    25,
     330,    27,     5,     5,   559,    27,   318,   580,  2473,   502,
    2315,   438,   439,   440,   441,     5,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,     5,     5,  2413,  1436,    25,   650,    27,
      23,  2538,     6,   470,   471,   368,   505,   100,   475,  2877,
     477,  2879,  2227,     5,   513,    25,  1011,    27,    31,    24,
      25,    26,    27,     5,  2815,   492,   493,   494,   495,    27,
     225,  1381,   499,  2506,   335,   225,  1031,   338,   651,  3314,
    1136,   209,   343,  3318,   557,    18,    19,    20,    21,    22,
       6,     5,   309,   842,     5,   502,   658,   420,   572,   661,
     662,     5,   309,    18,    19,    20,    21,    22,     5,     5,
       5,     5,   198,   675,  2463,    28,    29,   225,     5,   379,
    1238,     5,    30,   572,   434,  1098,  1099,   465,  2561,     5,
     391,    29,   694,     5,   464,   697,   629,  2486,  1024,     5,
     283,   703,   269,     5,     5,   707,   225,   621,   623,   711,
     557,  2902,   225,   715,   492,     5,   472,   719,   720,     5,
     722,   178,   612,   725,   410,   727,   728,   729,    99,   612,
     692,     5,   621,   735,    91,    92,   738,   225,   306,   491,
     659,     5,    90,   745,   739,   526,   527,    95,     5,   751,
       5,  1476,     5,   384,     5,     5,   758,     5,    27,   225,
     287,     5,   119,   120,   121,  2554,   518,   769,    28,   521,
    2461,   773,   658,   629,     5,   777,  2565,   529,  2716,  2717,
       5,   783,   629,     5,   786,     5,     5,  3055,  1114,  3057,
     756,   757,   140,   141,   546,     5,   548,    10,  1124,     5,
     148,   384,   602,  1129,   556,   287,   558,   559,   694,  2714,
     318,   697,  2318,     5,   515,   225,   309,   318,   280,   785,
     225,   707,   788,   535,   573,   711,     5,   384,   391,   715,
     397,   293,   430,   475,   543,   996,   722,     5,   583,     5,
     658,   727,   426,   729,     5,   548,   269,   445,     5,   735,
     471,     5,   738,   379,  1350,  2673,  2645,   461,  2493,   745,
    2942,   271,   465,   681,  1200,   751,  1362,  2804,   461,   560,
     409,   419,   758,  1121,   505,  1123,   588,   440,  2960,   406,
     407,   426,   280,   769,    27,    30,   379,   773,  3219,  2450,
     573,   777,   560,   424,   629,   293,   648,   783,  2938,   426,
     786,   653,   654,   655,   656,   657,  1095,   659,   660,   595,
     497,   663,   664,  1102,   666,  1321,   426,   669,   465,   671,
     576,   461,   505,   270,   406,   407,  1293,   461,   680,   461,
     584,   424,  1327,  1980,   576,    27,   463,  2726,   501,   374,
    1346,  2472,   430,   426,   659,   602,   587,   580,   700,  1321,
     623,  2595,   584,  1351,   706,   602,  2710,   445,   401,  2597,
     712,   713,   714,   645,   623,   110,   718,   590,  3187,   721,
     426,   723,   724,   521,  1346,   651,  2579,   660,  3058,  3198,
     700,   463,   734,   653,   426,   695,   700,   739,   740,   653,
     702,   700,   505,   651,   746,  1225,   645,   749,   580,  2918,
    1219,   659,   754,  2922,   756,   757,   645,  3414,   653,   761,
     762,   763,  2047,  1426,   700,   767,   590,   505,   770,   653,
     610,    27,   426,   775,   619,   430,  1352,  1353,  1354,    23,
     782,   461,   784,   785,   426,   787,   788,   465,   790,   791,
     445,     5,   549,  1369,   426,   488,   653,   139,   510,   461,
     461,   422,   578,   645,   402,   653,   672,   673,   674,   675,
     676,   504,   472,   590,   526,   584,  3211,   465,   645,   394,
     426,   284,   426,   493,   617,   426,   447,  3222,  1080,  2868,
     428,  2870,   426,   950,    27,   611,   953,   277,   461,   426,
     426,   426,   426,  1218,   961,   962,  3315,  3365,   190,   426,
    3182,  1427,   426,    27,   547,   653,   461,   376,   590,   602,
     426,    25,   510,    27,   426,   384,   385,   193,   359,     0,
     426,  1447,    27,  2629,   426,   426,   271,  2882,   526,   656,
    2885,  1448,   489,   225,    15,   227,   426,   280,  1464,  1473,
     426,   410,   894,   586,   413,   388,  3186,   193,   435,  1475,
     293,   499,   426,  2732,  2733,  2734,  2735,  1318,    25,   530,
      27,   430,   426,     5,    25,   653,    27,   394,    25,   426,
      27,   426,   615,   426,   656,   426,   426,   612,   426,   706,
     707,   624,   426,   935,   653,   510,  3226,   572,   202,   682,
     683,   684,   539,   493,  1080,   426,   317,  1199,  1200,  1201,
     693,   426,   650,  3009,   426,  2994,   426,   426,   421,   330,
     423,    18,    19,    20,    21,    22,   426,     5,   575,   225,
     426,   973,   186,   975,   706,   707,    26,    27,    25,   359,
      27,  2052,   324,   653,   426,    38,   621,    40,    41,    42,
    2201,   388,     9,   591,   996,  2292,   391,   426,   653,  2296,
    3027,   622,    26,    27,  3043,   331,    25,     5,   426,  1011,
     426,   618,  1014,   634,   635,   426,   535,   968,    25,   426,
      27,   642,   426,   680,   515,   269,  1028,   492,   493,  1031,
     366,   493,   225,   510,   521,   331,  3191,  3224,    55,    14,
    3079,  2093,   529,   700,   619,   440,  2257,  2258,   556,  2592,
     392,   225,  2793,    25,  2795,    27,   713,  2798,   400,    26,
      27,   225,   404,  1199,  1200,  1201,   465,  1069,   473,   588,
     225,   147,   465,   671,   354,   612,   595,   472,   615,   484,
     465,   679,   408,   465,  1086,  1087,  1088,   493,  1090,   465,
    1092,  1093,   317,   464,   186,   426,  1098,  1099,  2162,   441,
     505,   493,    25,   653,    27,   330,   501,   512,   225,  1917,
     465,    25,   408,    27,   225,  1923,  1924,   510,   225,   370,
    1365,  1929,  1930,  1931,  1932,   199,   460,   201,   283,   460,
     381,    26,  1134,   526,  1136,   515,    25,   465,    27,   465,
     188,   465,   619,  1145,   192,   465,  1148,  1363,  3204,  2078,
     465,  1153,   226,   397,  3210,  3194,   465,  3213,  3214,  3215,
    3216,   648,    25,   419,    27,   493,   508,   658,   465,   493,
    1172,  1173,  3199,  3200,    98,   225,  3005,  3006,   225,  1181,
    3009,    20,   433,   465,   510,  2996,   677,   678,    27,  2732,
    2733,  2734,  2735,   212,   465,  1197,  1198,   448,  1843,  1844,
     526,   225,   143,   144,   145,   547,   697,  1852,  1453,   473,
      26,    27,   548,  1458,   510,    25,    26,   623,   225,  1296,
     484,  1223,  1299,   559,   465,   652,   419,  1229,  1230,   571,
     526,   305,   659,    25,   308,    27,  1238,  3066,  1454,   464,
    3069,   505,   290,  1989,   465,   697,  1248,   653,   512,   199,
     465,   201,   305,   225,  1256,   308,   330,   310,   225,   711,
     465,  3065,   465,   715,  3068,  3321,   430,  3071,  3324,  3325,
    3326,  3327,    26,   615,    19,   727,   226,   330,   658,    24,
    1925,    26,   624,    24,  2566,    26,   537,   340,    20,   492,
     493,   199,  1317,   201,  2102,    27,   465,   677,   678,  1301,
    2597,   493,   225,  1305,  1306,  1307,   359,  2518,  1953,  2399,
    2521,   225,  2594,   465,   273,  1317,  1318,   697,  1940,  1321,
     339,  1323,  1324,  1325,  1326,  1327,   345,   346,   347,   382,
    2076,  3072,    20,   386,    26,    25,   225,    27,  3203,    27,
    3205,  3206,  3207,  3208,  1346,  1347,   365,  1349,  1350,  1351,
    3406,   465,   555,  3303,  3304,   305,  1358,  1359,   308,   465,
    1362,  1363,   225,  1365,  1366,   465,   708,   709,   465,   426,
      20,   330,  3367,  3202,  1376,  3204,   273,    27,   465,  1381,
     330,  3210,  3211,   401,  3213,  3214,  3215,  3216,   465,  3384,
     464,  2199,   195,  3222,    25,  2141,    27,   305,   465,  2207,
     308,  2465,  2210,  2211,  2212,  2213,   659,   210,   211,   225,
     334,   464,  2147,   465,   673,   674,   219,   401,    26,  2003,
     658,  2485,   330,   382,  1426,   401,   465,   386,   401,  2005,
     354,   465,    20,   330,   465,  3385,  3431,  3387,    96,    27,
     492,   493,   680,   681,  2020,  3249,   465,   659,    20,  1451,
     253,  1453,  1454,  3448,   473,    27,  1458,   476,  1460,   262,
    1462,  1463,  3005,  3006,  2040,   484,  3009,    26,   392,  2045,
     488,   658,    38,   465,    40,    41,    42,    20,   465,    25,
     404,    27,   515,  1485,    27,   382,   504,    26,   291,   386,
      26,   415,  3321,   680,   681,  3324,  3325,  3326,  3327,    20,
     519,   492,   493,   555,   488,   464,    27,   729,   432,  2085,
    2155,   653,   488,   171,   464,   488,   738,   560,   442,  3348,
     504,   445,   465,  3066,   784,   465,  3069,   787,   504,   547,
     790,   504,   401,   336,   458,   554,   769,   465,  2284,  2587,
     773,  2589,  2590,   273,   777,   672,   401,   401,   675,   676,
      24,  2297,    26,  2299,   573,   574,   464,    26,    25,  2611,
      27,   783,  2308,   547,   786,   584,  2064,   464,   586,   465,
     589,   547,  2217,   465,   547,   378,   234,  3406,   236,    24,
    2651,    26,   506,  2682,   465,  3414,  2792,  2793,  1347,  2795,
    1349,   465,  2798,   251,   171,   465,  2648,   615,  1814,  1815,
     330,   259,   586,   465,  2901,   263,   624,  2889,   455,   628,
     586,   493,   536,   586,    26,    25,  2706,    27,    26,   488,
     675,   676,   546,   682,   683,   658,   682,   683,    25,    93,
     288,   615,    26,   488,   488,   504,    26,   685,   686,   615,
     624,   660,   615,   567,   677,   678,    26,   571,   624,   504,
     504,   624,   382,   322,   323,   426,   386,   234,   653,   236,
     465,  3204,  3005,  3006,   697,  2473,    26,  3210,  3211,   396,
    3213,  3214,  3215,  3216,   251,   599,  1096,  1097,   547,  3222,
    1100,  1101,   259,   653,   608,   465,   263,    18,    19,    20,
      21,   426,   547,   547,   461,   465,  3239,   274,    19,     5,
     171,   465,   426,    24,    25,    26,   426,  1841,   426,  2293,
    2286,   288,   426,  1847,   505,  2523,   465,   586,    18,    19,
      20,    21,    22,   659,  2300,  2301,  2302,  2303,  2657,    20,
    2538,   586,   586,   781,   464,    20,   465,  2666,  2667,   305,
     465,  2549,   308,   791,   310,  2321,   615,    18,    19,    20,
      21,   426,     5,  2337,   465,   624,   646,   647,   648,   649,
     615,   615,   653,   234,   330,   236,   703,   704,   705,   624,
     624,    20,    21,   657,   340,    26,   493,   426,  3321,   293,
     251,  3324,  3325,  3326,  3327,  2037,   396,   461,   259,    30,
      20,    26,   263,   359,    26,    26,   127,   128,   129,   130,
     131,   132,  2386,  2448,  2380,  3348,  1883,    26,    26,    26,
      26,  1813,  1814,  1815,   623,   212,   382,   288,  1820,  1821,
     386,   426,   426,    26,  1941,    20,    21,   426,   937,   426,
    2046,   940,   426,   942,   943,   944,   945,   946,  1840,    26,
       5,  1843,  1844,  2488,    20,   465,  1848,    26,  1850,    26,
    1852,    26,   653,   426,     5,  2601,   127,   128,   129,   130,
     131,   132,   426,  3406,    26,   426,  3072,   337,   426,  2615,
     426,  3414,   426,  1950,  1876,  2683,  2121,  2122,   127,   128,
     129,   130,   131,   132,   426,  1887,  2531,   935,  2533,   657,
       5,   426,  2144,    38,   426,    40,    41,    42,   464,   659,
    2476,  2037,  2478,   465,   426,    26,  2714,  2041,   623,   659,
    2162,   426,    25,  1915,    25,  1917,    25,   426,    25,   426,
    2136,  1923,  1924,  1925,   426,   426,   426,  1929,  1930,  1931,
    1932,   662,   127,   128,   129,   130,   131,   132,  1940,   426,
     426,   426,   339,   426,   675,   337,  2063,  2947,   345,   346,
     347,  1953,    14,    15,    16,    17,    18,    19,    20,    21,
      22,  2078,   657,   426,  1966,   426,  1014,   426,   365,   465,
     653,   650,   703,   493,     8,  1977,   653,    39,  1980,   623,
     653,   461,   658,   513,   301,     5,   494,  1989,   719,   720,
     651,   651,  2800,   629,   725,  1946,   494,   728,   455,  2001,
     361,   692,   645,   692,  2006,     8,   630,     5,  2144,     5,
     465,   418,   465,   465,   465,   465,   379,   623,     8,   612,
      14,     5,  2951,   609,   692,     5,  2162,   692,   455,   465,
     465,  2033,   100,    26,    26,   126,   653,   493,   623,   465,
     465,  2043,  2044,   465,  2046,  2621,  3021,   465,  2624,   465,
     465,  3141,   465,   455,   493,    26,  2058,     5,   629,  3149,
     465,   465,     5,  2065,   659,   127,   128,   129,   130,   131,
     132,   658,  2074,  3163,  2076,   659,   473,   465,   465,   476,
     695,   143,   144,   145,   385,   590,     5,   484,    18,    26,
      19,    26,   188,   253,    25,  2097,   623,  2099,  2100,   656,
    2102,   612,  2285,  2105,  2106,   516,  2682,   516,   653,  2354,
       5,   186,   580,    26,   580,   434,   356,    26,   580,  2121,
    2122,   426,   519,   465,  1172,   659,   560,   426,   653,   426,
     465,   465,   465,   465,  2136,   465,   426,   697,   610,  2141,
    2142,  2143,   493,   653,   650,  2147,   659,   580,  2894,   465,
       5,     5,     5,  2155,   653,   613,     5,   554,   517,  3223,
     305,   658,  2908,   308,   659,   310,     5,   465,     8,    26,
      26,  2173,   354,   100,   360,     5,   573,   574,     5,  2181,
    2182,  1229,  1230,  2185,   426,   330,   465,   584,  2285,   465,
    1238,   395,   589,    14,   659,   340,     5,  2199,   630,   693,
     584,   580,    26,  3293,   465,  2207,   653,  2459,  2210,  2211,
    2212,  2213,  2214,  2465,   359,  2217,   659,   135,   465,  2221,
    2222,     5,   284,  2225,   672,   287,    26,   658,   461,   426,
       5,   628,     5,  2485,   403,   652,  2537,   382,  2539,   366,
     461,   386,   465,   495,  2246,   495,  2248,  2249,     8,     5,
    2252,  2253,  2819,  2820,  2821,   465,  2823,  2824,  2825,  2826,
    2827,  2828,   653,   660,   465,  2832,   465,  3075,     5,  3077,
     653,   465,   465,   465,     8,   653,     5,  2279,   587,   360,
    2282,    25,  2284,   653,   379,   379,  2288,   493,   460,   379,
    2292,   465,   395,   493,  2296,  2297,     5,  2299,   455,     5,
      26,  3301,   684,  2305,     5,  3395,  2308,  2309,     5,    25,
    2312,  2313,  3370,  3371,  3372,  3373,  3374,  3375,    14,   464,
      14,    26,   629,  2459,   650,   629,   465,     5,     5,  2465,
     465,   659,  2334,  1381,   426,   465,     6,   426,   426,   426,
     426,   426,     7,  2345,   406,   482,   303,   426,     5,  2485,
     653,    26,  2354,  2929,    26,    26,     8,   659,   653,   421,
     426,    20,     5,   425,   600,   309,     5,     5,   580,     5,
       5,   426,  2374,   653,   701,   426,   605,   505,   659,     5,
     587,   465,   659,  3191,   245,   153,  2962,   657,   426,    26,
     659,   659,   465,   505,   465,     5,     5,  3143,  2400,   657,
    1448,   463,    25,    25,    25,   481,   652,    25,    25,   331,
      26,    26,     5,  3058,    26,    26,   426,     5,    26,    26,
      26,   426,   502,     5,   465,   426,   584,   275,    26,   491,
      25,  2732,  2733,  2734,  2735,   461,   475,   426,   379,    20,
     587,   177,   465,   465,   465,     5,  2448,   509,   465,   465,
     465,  2696,   465,  2698,     5,    14,   245,  3386,   426,     5,
     493,  2463,   476,   426,  2716,  2717,   426,  3084,    26,  2471,
    2472,  2473,   426,    26,   426,  2506,   409,   602,    26,   426,
     275,   426,   465,   379,  2486,   276,  2488,   426,   256,   493,
    2492,  2493,   426,  2794,   475,  2796,   264,   580,  2681,   465,
     426,   653,   270,    14,   272,  3505,     7,   274,   274,  3317,
      18,    19,  2646,    26,   426,   283,    24,    25,    26,    27,
     427,  2523,    20,    21,    22,   659,   426,   465,   590,  2531,
    2561,  2533,   609,   653,  2536,   426,  2538,  2654,  3284,    25,
    2657,    39,   465,   311,  3352,   461,   276,  2549,   426,  2666,
    2667,   426,  2554,  2555,  2556,    38,   426,   426,   426,   327,
       5,   426,     5,  2565,   332,  2661,   426,  2608,  2570,  3145,
    3441,   653,   961,  2086,  2370,   653,   344,  2579,  1465,   653,
    2716,  2717,    29,   351,  2681,    27,   526,  2309,  2640,  2315,
     343,    99,   110,  2595,   656,  2597,   336,   114,   202,  2601,
     632,  3177,  1945,   344,   515,  1946,  2608,   576,   205,   534,
    1228,   372,   371,  2615,   546,  3431,  2005,   953,   767,   102,
     103,   403,  2179,  1206,   548,  2186,  2302,  1813,  2045,   127,
     128,   129,   130,   131,   132,  2974,  2687,  1816,  2640,  2113,
    2642,  2396,  2644,  2645,  3482,   143,   144,   145,  2306,  3457,
    3157,  2131,  1365,    15,    89,    21,  3105,  2659,    21,  2661,
    2662,  2663,   896,  2091,   724,  2097,   319,   975,  1821,  2685,
    2100,  3102,  3257,  1359,  2676,  3448,  1424,  3052,  2683,   749,
    1173,  2683,  2684,  2685,   167,  1349,  2859,  3267,  1447,   437,
    2857,  2841,  2564,  2898,  2696,  1124,  2698,  2296,  1983,  1960,
    3457,  3079,   295,   186,  3005,  3006,  2708,  2709,  3009,  2459,
    2926,  2489,  2714,  3342,  2867,  2565,  2154,   225,  2252,  2781,
    2936,  2217,  2782,  3069,  2726,  2536,  3122,  3348,  1840,  2570,
    2732,  2733,  2734,  2735,  2736,  2737,     7,   505,  3498,  2555,
    3004,   334,  1202,  2727,   512,  2747,  2556,  1924,  3077,  1835,
    2752,  1923,  3311,  3003,  1198,  3202,  3221,  2920,  3210,  1808,
     353,   354,  2282,  1364,    -1,    -1,   534,  2646,    -1,   524,
      -1,   539,  1209,  1821,    -1,    -1,    -1,    -1,    -1,  2781,
    2782,    -1,    -1,    -1,    -1,    -1,   284,    -1,    -1,   287,
    2792,  2793,    -1,  2795,    -1,    -1,  2798,    -1,  2800,   392,
      -1,    -1,  2804,    -1,    -1,  3381,    -1,    -1,    -1,    -1,
      -1,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   415,  2920,    -1,   308,   309,    -1,    -1,    -1,
      -1,    -1,   315,    -1,  2951,   295,   319,    -1,    -1,   432,
      -1,  2843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,    -1,    -1,    -1,  2856,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   458,  2868,  2869,  2870,  1917,
      -1,    -1,    -1,    -1,   334,  1923,  1924,    -1,    -1,    -1,
      -1,  1929,  1930,  1931,  1932,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2894,   353,   354,  3140,  2898,    -1,    -1,  2901,
      -1,  3477,    -1,  3204,    -1,   498,  2908,    -1,   406,  3210,
    3211,    -1,  3213,  3214,  3215,  3216,  2918,    -1,    -1,  2921,
    2922,  3222,   430,   421,  2926,    -1,    -1,   425,   521,    -1,
      -1,    -1,   392,    -1,  2936,    -1,  2938,   445,    -1,    -1,
      -1,    -1,    -1,   536,   404,  2947,    -1,    -1,    -1,    -1,
     543,    -1,    -1,   546,   462,   415,    -1,   465,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,
     478,  3223,   432,    -1,   567,    -1,    -1,    -1,   571,    -1,
      -1,    -1,   442,    -1,    -1,    -1,  2988,    -1,    -1,    -1,
      -1,    -1,  2994,   491,    -1,    -1,    -1,   590,   458,    -1,
      -1,  3003,    -1,  3005,  3006,    -1,    -1,  3009,   491,   517,
     518,   509,    -1,    -1,    -1,   608,    -1,    -1,  3020,   502,
    3321,    -1,   530,  3324,  3325,  3326,  3327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,
      -1,  3043,    -1,  3045,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2102,    -1,  3058,    -1,    -1,    -1,
      -1,   521,    -1,   571,  3066,    -1,    -1,  3069,    -1,    -1,
    3072,    -1,    -1,  3075,   557,  3077,   536,  3079,    -1,    -1,
      -1,    -1,    -1,   543,    -1,    -1,   546,  3223,    -1,    -1,
      -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3102,    -1,   610,    -1,    -1,  3406,    -1,   567,    -1,    -1,
      -1,   571,    -1,  3414,   622,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3307,    -1,   634,   635,    -1,    -1,
     590,    -1,    -1,    -1,   642,    -1,    -1,   645,  3140,    -1,
      -1,  3143,    -1,    -1,    -1,   653,   629,    -1,   608,    -1,
      -1,  2199,    18,    19,    -1,    -1,    -1,    -1,   656,  2207,
      26,    27,  2210,  2211,  2212,  2213,    -1,    -1,    -1,    -1,
     653,   654,   655,   656,  2222,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,  3186,    -1,    -1,    -1,   671,  3191,
      -1,    -1,  3194,    -1,    -1,    -1,    -1,    39,  2246,    -1,
    3202,    -1,  3204,    -1,    -1,  2253,    -1,    -1,  3210,  3211,
    3307,  3213,  3214,  3215,  3216,    -1,    -1,  3219,    -1,  3221,
    3222,    -1,  3224,   706,  3226,    -1,    -1,    -1,    94,   712,
      -1,   714,    -1,    -1,    -1,   718,    -1,    -1,   721,    -1,
     106,   724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   734,    -1,    -1,    -1,  3257,    -1,    -1,    -1,    -1,
    3262,    -1,  3264,    -1,    -1,    -1,   749,    -1,   134,  3386,
      -1,   754,    -1,    -1,    -1,    -1,    -1,    -1,   761,   762,
     763,    -1,  3284,    -1,   767,   127,   128,   129,   130,   131,
     132,    -1,   775,    -1,    -1,    -1,    -1,    -1,    -1,  3301,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   791,  3311,
      -1,    -1,    -1,    -1,    -1,  3317,    -1,    -1,    -1,  3321,
      -1,    -1,  3324,  3325,  3326,  3327,  3328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3342,    -1,    39,    -1,    -1,    -1,  3348,    -1,    -1,    -1,
    3352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,  3370,  3371,
    3372,  3373,  3374,  3375,    -1,    -1,    -1,    -1,    -1,     9,
    3382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,   167,    -1,    -1,    24,    25,    26,    27,    -1,   175,
      -1,    -1,    -1,    -1,  3406,    -1,    -1,    -1,   184,    -1,
      -1,   187,  3414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2473,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,   131,   132,    -1,  1874,  1875,    -1,
      -1,    -1,   284,    -1,  1881,   287,   143,   144,   145,    -1,
      -1,    -1,    -1,    -1,   230,  3457,    -1,  3459,   324,    -1,
      -1,    -1,   238,    -1,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,  2523,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2536,    -1,
    2538,   357,    -1,    -1,  3496,  3497,  3498,    -1,    -1,    -1,
      -1,  2549,    -1,  3505,   134,  3507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,
      -1,  1014,    -1,    -1,    -1,    -1,    -1,    -1,   404,    -1,
      -1,    -1,    -1,   319,  2592,  1028,    -1,    -1,    -1,    -1,
     326,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   338,    -1,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,   421,
      -1,    -1,    -1,   425,    -1,    -1,  1069,   284,   364,    -1,
     287,   457,    -1,    -1,    -1,   225,   372,   227,    -1,   465,
      -1,    -1,    -1,  1086,  1087,  1088,    -1,  1090,    -1,  1092,
    1093,    -1,   478,    -1,    -1,  1098,  1099,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2068,    -1,    -1,   410,  2683,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,
      -1,    -1,    -1,  1136,    -1,    -1,   522,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,  1148,  2714,   509,    -1,    -1,
      -1,    -1,  2109,    -1,    44,    45,    46,    47,    48,    49,
      -1,   547,    -1,    -1,  2732,  2733,  2734,  2735,    -1,  1172,
    1173,    -1,    -1,    -1,   324,    -1,    -1,   473,  1181,   329,
      -1,    -1,    -1,    -1,    -1,   571,    -1,    -1,   484,   406,
      -1,    -1,    -1,    -1,  1197,  1198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,   357,   425,    -1,
      -1,    -1,    -1,  2781,  2782,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2792,  2793,    -1,  2795,   590,   615,
    2798,    -1,  2800,    -1,    -1,    -1,  2804,    -1,   624,    -1,
      -1,    -1,   392,   133,    -1,    -1,   463,    -1,    -1,    -1,
      -1,  2819,  2820,  2821,   404,  2823,  2824,  2825,  2826,  2827,
    2828,    -1,    -1,    -1,  2832,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   422,    -1,   491,    -1,    -1,   427,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,   582,   583,   584,    -1,
      -1,   441,   509,    -1,   656,    -1,    -1,   447,    -1,   595,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,
      -1,    -1,   462,    -1,    -1,   465,    -1,    -1,   468,    -1,
      -1,    -1,   708,   709,    -1,    -1,    -1,   477,   478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1347,    -1,  1349,  1350,  1351,    -1,
      -1,    -1,    -1,    -1,    -1,  1358,  1359,    -1,    -1,  1362,
      -1,    -1,    -1,  1366,    -1,    -1,    -1,   517,   518,    -1,
      -1,    -1,   522,   590,    -1,    -1,    -1,    -1,  1381,  2947,
     530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   541,    -1,    -1,    -1,    -1,    -1,   547,    -1,    -1,
      -1,    -1,   698,    -1,    -1,    -1,    -1,  2364,  2365,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,  2375,    -1,
      -1,   571,    -1,  1426,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,  3005,  3006,   656,
      -1,  3009,    -1,    -1,  2401,  2402,  2403,  2404,    -1,    -1,
      -1,    -1,  2409,  2410,  2411,  2412,    -1,  1460,    -1,  2416,
      -1,    -1,    -1,    -1,    -1,   615,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,   624,    -1,    -1,   367,    -1,    -1,
      -1,    -1,  1485,    -1,   634,   635,    -1,    -1,    -1,    -1,
     380,    -1,   642,    -1,    -1,    -1,    -1,    -1,  3066,    -1,
      94,  3069,    -1,   653,  3072,    99,    -1,  3075,    -1,  3077,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2494,  2495,    -1,
     134,    -1,    -1,    -1,  2501,  2502,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,   708,   709,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,     9,    -1,    -1,
     490,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    39,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3191,   514,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,   524,   525,  3204,    -1,    -1,    -1,
     530,    -1,  3210,  3211,    -1,  3213,  3214,  3215,  3216,    -1,
     540,    -1,    -1,    -1,  3222,    -1,  3224,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,  3239,   562,  2630,  2631,   565,   566,    -1,    -1,    -1,
     570,    -1,  2639,    -1,    -1,    39,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2670,  2671,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,  3301,    -1,   329,    -1,   627,    -1,    -1,
    2697,    -1,  2699,    -1,    -1,    -1,    -1,    -1,   638,  3317,
      -1,    -1,    -1,  3321,    -1,    -1,  3324,  3325,  3326,  3327,
      -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,   131,   132,    -1,
    3348,    -1,    -1,    -1,  3352,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,  2753,  2754,   392,    -1,
    2757,  2758,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
     404,    -1,    -1,   225,    -1,    18,    19,  1820,  1821,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,   422,    -1,
      -1,    -1,    -1,   427,    -1,    -1,   430,    -1,  3406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3414,   441,    -1,    -1,
      -1,    -1,    -1,   447,    -1,    -1,   284,    -1,    -1,   287,
      -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,   462,    -1,
      -1,   465,    -1,  1876,   468,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   477,   478,    -1,    -1,    -1,    -1,  3457,
    2847,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   329,    -1,    -1,
      -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,   522,    -1,
     284,   134,    -1,   287,    -1,    -1,   530,  3505,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,    -1,   543,
      -1,    -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2919,    -1,    18,    19,  2923,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,   571,   406,    -1,
      -1,    -1,  2939,    -1,    -1,    -1,  1989,    -1,    -1,    -1,
      -1,    -1,    -1,   421,    -1,    -1,    -1,   425,    -1,    -1,
      -1,  2958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,
      -1,   615,   225,    -1,   227,    -1,    -1,    -1,   622,    -1,
     624,    -1,    -1,   445,    -1,   463,    -1,    -1,    -1,    -1,
     634,   635,    -1,    -1,    -1,    99,    -1,    -1,   642,    -1,
     462,    -1,   406,   465,    -1,  2058,    -1,    -1,    -1,   653,
      -1,    -1,  2065,   491,    -1,   477,   478,   421,    -1,    -1,
      -1,   425,    -1,  2076,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   505,  2097,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2106,    18,    19,   518,    -1,    -1,   463,
      24,    25,    26,    27,   708,   709,    -1,    -1,   530,    -1,
      -1,   324,   476,    -1,    -1,    -1,   329,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   491,  2141,  2142,
    2143,    -1,    -1,    -1,  2147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,   509,    -1,    -1,    -1,   571,
      -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2173,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,   392,
      -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,   610,    -1,
      -1,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3175,   422,
     134,  3178,   634,   635,   427,    -1,    -1,   430,   656,    -1,
     642,    -1,    -1,   645,    -1,    -1,   590,    -1,   441,    -1,
      -1,   653,    -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,   462,
      -1,    -1,   465,    -1,    -1,   468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   477,   478,    -1,    -1,    -1,    -1,
      -1,  2284,  2285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2297,    -1,  2299,    -1,    -1,    -1,
      -1,    -1,   656,    -1,    -1,  2308,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,   517,   518,    -1,    -1,    -1,   522,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,    -1,
      -1,    -1,  2345,    -1,   547,    -1,    -1,    -1,  3305,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,   571,    39,
      -1,  2374,    18,    19,    20,    -1,   430,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,   445,    24,    25,    26,    27,    -1,  3354,  3355,    -1,
    3357,    -1,  3359,  3360,    -1,    -1,    -1,    -1,   462,    -1,
     324,   465,   615,    -1,    -1,   329,    -1,    -1,    -1,   622,
      -1,   624,    -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,
      -1,   634,   635,    -1,    -1,    -1,    -1,    -1,    -1,   642,
      -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,
     653,   505,    -1,    99,    -1,    -1,    -1,   127,   128,   129,
     130,   131,   132,  3420,   518,  3422,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   530,    -1,   392,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2492,
     404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3455,    -1,
      -1,    -1,    -1,    -1,    -1,   708,   709,    -1,   422,    -1,
      -1,    -1,    -1,   427,  3471,  3472,   430,   571,  3475,    -1,
      23,  3478,    18,    19,    20,    -1,    -1,   441,    24,    25,
      26,    27,    -1,   447,    -1,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,   462,    -1,
      -1,   465,  2555,    -1,   468,    -1,   610,    -1,    -1,    -1,
      -1,    -1,    -1,   477,   478,    -1,    -1,    -1,   622,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     634,   635,    -1,    -1,    -1,    -1,    -1,    -1,   642,    -1,
      -1,   645,    -1,   225,    97,    -1,    -1,    -1,  2601,   653,
      -1,    -1,    -1,    99,   518,    -1,    -1,    -1,   522,    -1,
      -1,    -1,  2615,    -1,   284,    -1,   530,   287,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,   541,    -1,    -1,
      -1,    -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,    -1,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2659,   571,  2661,    -1,
    2663,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,  2676,    -1,    -1,    -1,    -1,  2681,    -1,
      -1,  2684,  2685,   329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   329,   201,    -1,
      -1,   615,    -1,    -1,    -1,  2708,  2709,    -1,   622,    20,
     624,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
     634,   635,    -1,   226,    -1,    -1,    -1,    -1,   642,   225,
      -1,   234,    -1,   236,    -1,    -1,   406,    -1,    -1,   653,
      -1,    -1,   245,    -1,  2747,   211,    -1,    -1,   251,    -1,
      -1,   421,    -1,   219,    -1,   425,   259,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
     273,   274,   275,   276,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   430,   288,    -1,   253,    99,    -1,
      -1,    -1,    -1,   463,   708,   709,   262,    -1,   430,   445,
      -1,    -1,   305,    -1,    -1,   308,    -1,   310,    -1,    -1,
      -1,    -1,    -1,   445,   317,    -1,   462,    -1,    -1,   465,
      -1,   491,    -1,    -1,    -1,   291,   292,   330,    -1,    -1,
     462,   477,   478,   465,    -1,    -1,    -1,   340,    -1,   509,
    2843,    -1,    -1,    -1,    -1,   477,   478,    -1,    -1,    -1,
      -1,    -1,    -1,  2856,    -1,    -1,   359,   360,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,   374,   518,    -1,    -1,    -1,    -1,    -1,    -1,   382,
      -1,    -1,    -1,   386,   530,    -1,   518,    -1,    -1,    -1,
      -1,  2894,   395,   396,   397,    -1,    -1,    -1,   530,    -1,
      -1,    -1,    -1,    -1,    -1,  2908,    -1,    -1,    -1,    -1,
      -1,    -1,   378,    -1,   225,    -1,    -1,  2920,    -1,    -1,
     590,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   430,  2938,    -1,    -1,    -1,   571,
      -1,    -1,    -1,    -1,  2947,    -1,    -1,    -1,    -1,   445,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   464,    -1,    -1,   610,    -1,   462,    -1,   434,   465,
      -1,    -1,   475,    -1,    -1,    -1,   622,    -1,   610,    -1,
      -1,    -1,   478,    -1,    -1,    -1,   656,    -1,   634,   635,
     622,    -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,   645,
      -1,    -1,   634,   635,    -1,    -1,    -1,   653,    -1,   505,
     642,    -1,   515,   645,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   653,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   576,    -1,   571,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    -1,  3102,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,   612,
      -1,    -1,    -1,    -1,   610,    33,    -1,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    49,    -1,    -1,   445,    -1,    -1,    -1,   634,   635,
    3143,    -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,   645,
      -1,   462,    -1,    -1,   465,   658,    -1,   653,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,   672,
     673,   674,   675,   676,   677,   678,    -1,   680,   681,    97,
      -1,    -1,    -1,  3186,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,   697,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,    -1,   124,   518,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,   530,
      -1,   139,   140,  3226,    -1,   143,   144,   145,   146,    -1,
      -1,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3257,    -1,    -1,    -1,    -1,  3262,
     571,  3264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,  3301,   610,
     218,    -1,    -1,    -1,  3307,    -1,   224,   225,    -1,   227,
      -1,   622,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   634,   635,    -1,    -1,    -1,    -1,    -1,
      -1,   642,    -1,    -1,   645,    -1,    -1,    -1,    -1,    -1,
     258,    -1,   653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3370,  3371,  3372,
    3373,  3374,  3375,    -1,    -1,    -1,    -1,    -1,   296,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   309,    -1,    -1,    -1,    -1,    -1,   315,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,    -1,    -1,
      -1,    -1,    -1,   331,    -1,    -1,   334,   335,    -1,    -1,
      -1,   339,    -1,    -1,    -1,    -1,    -1,   345,   346,    -1,
      -1,    -1,    -1,    -1,   352,   353,   354,   355,   356,   357,
      -1,    -1,    -1,   361,    -1,    -1,    -1,   365,    -1,   367,
      -1,    -1,    -1,    -1,    -1,    -1,   374,   375,   376,   377,
      -1,   379,   380,    -1,    -1,    -1,   384,   385,    -1,   387,
     388,   389,    -1,   391,   392,   393,   394,    -1,    -1,    -1,
      -1,    -1,   400,   401,   402,    -1,   404,   405,    -1,    -1,
      -1,   409,   410,   411,   412,   413,   414,   415,   416,    -1,
     418,    -1,  3505,    -1,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,    -1,   461,   462,    -1,    -1,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,    -1,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,    -1,    -1,   493,   494,   495,   496,   497,
     498,   499,   500,   501,    -1,   503,   504,   505,   506,    -1,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,    -1,   545,   546,   547,
     548,   549,   550,    -1,    -1,   553,   554,    -1,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,    -1,    -1,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,    -1,    -1,
      -1,    -1,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   671,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   679,    -1,    -1,    -1,    -1,   684,    -1,    -1,    -1,
     688,    -1,    -1,   691,   692,   693,   694,    -1,    -1,   697,
     698,    -1,   700,   701,   702,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,   315,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   324,   325,    -1,    -1,    -1,    -1,
      -1,   331,    -1,    -1,   334,   335,    -1,    -1,    -1,   339,
      -1,    -1,    -1,    -1,    -1,   345,   346,    -1,    -1,    -1,
      -1,    -1,   352,   353,   354,   355,   356,   357,    -1,    -1,
      -1,   361,    -1,    -1,    -1,   365,    -1,   367,    -1,    -1,
      -1,    -1,    -1,    -1,   374,   375,   376,   377,    -1,   379,
     380,    -1,    -1,    -1,   384,   385,    -1,   387,   388,   389,
      -1,   391,   392,   393,   394,    -1,    -1,    -1,    -1,    -1,
     400,   401,   402,    -1,   404,   405,    -1,    -1,    -1,   409,
     410,   411,   412,   413,   414,   415,   416,    -1,   418,    -1,
      -1,    -1,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
      -1,   461,   462,    -1,    -1,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,    -1,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,    -1,    -1,   493,   494,   495,   496,   497,   498,   499,
     500,   501,    -1,   503,   504,   505,   506,    -1,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,    -1,   545,   546,   547,   548,   549,
     550,    -1,    -1,   553,   554,    -1,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,    -1,    -1,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,    -1,    -1,    -1,    -1,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     660,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,   671,    -1,    -1,    43,    -1,    -1,    -1,    -1,   679,
      -1,    50,    -1,    -1,   684,    -1,    -1,    -1,   688,    -1,
      -1,   691,   692,   693,   694,    -1,    -1,   697,   698,    -1,
     700,   701,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,   154,   155,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,    -1,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
     179,    -1,   181,   182,   183,    -1,    -1,    -1,    -1,    -1,
     189,    -1,   191,   192,    -1,   194,    -1,   196,   197,    -1,
      -1,   200,    -1,    -1,   203,   204,   205,    -1,   207,   208,
      -1,    -1,    -1,   212,   213,   214,    -1,   216,    -1,    -1,
      -1,   220,    -1,   222,   223,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,   232,    -1,    -1,   235,    -1,   237,    -1,
     239,    -1,   241,    -1,   243,   244,    -1,   246,   247,   248,
      -1,    -1,    -1,   252,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
      -1,    -1,   281,   282,    -1,    -1,   285,   286,    -1,    -1,
     289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,
     299,   300,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,    -1,   316,    -1,    -1,
      -1,   320,   321,    -1,    -1,    -1,   325,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,   342,   343,    -1,    -1,    -1,    -1,    -1,
     349,   350,    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,
      -1,    -1,    -1,   362,   363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     399,    -1,    -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,   437,   438,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,    -1,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   496,    -1,    -1,
      -1,    -1,    -1,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,
      -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,
      -1,   550,   551,   552,   553,    -1,    -1,    -1,   557,    -1,
      -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,   568,
     569,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
     579,    -1,   581,    -1,    -1,    -1,    -1,   143,   144,   145,
      -1,    -1,    -1,   592,    -1,   594,    -1,    -1,   597,    -1,
      -1,     6,     7,     8,   603,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     629,    -1,    -1,   632,    39,    -1,    -1,    -1,   637,    -1,
      -1,   640,   641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,    -1,
       6,     7,     8,   662,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   685,   686,   687,   688,
     689,   690,   691,    39,    -1,   694,    -1,   696,    -1,   698,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,   284,    -1,
      -1,   287,    -1,    -1,    39,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,   143,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,   287,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,   284,    -1,
      -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
     425,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,
     284,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,    -1,
     406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,   425,
     426,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     656,   406,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,   463,    -1,    -1,
     425,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,   491,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   463,    -1,
      -1,    -1,   406,   509,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,   425,   426,    -1,    -1,   590,   491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,   509,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   463,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   590,    -1,    -1,   491,     6,     7,
       8,   656,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   509,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,
     225,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    39,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,   284,
      -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    39,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,   132,
      -1,    39,    -1,    -1,    -1,    -1,   284,    -1,    -1,   287,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,   430,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,
     445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,    -1,    -1,   462,    -1,    -1,
     465,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,
      -1,   406,    -1,   478,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,   131,   132,    -1,   421,    -1,    -1,    -1,
     425,   426,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,   406,    -1,
      -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,   463,    -1,
      -1,    -1,    -1,   421,    -1,    -1,    -1,   425,   426,    -1,
      -1,   284,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   509,   463,   284,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,   491,    -1,   610,   284,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    39,    -1,
      -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   634,
     635,    -1,    -1,    -1,    -1,    -1,   284,   642,    -1,   287,
     645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,
      -1,    -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,   425,   426,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   406,    -1,
      -1,    -1,   590,    -1,    -1,    -1,   127,   128,   129,   130,
     131,   132,    -1,   421,    39,    -1,    -1,   425,   426,    -1,
     463,   656,   143,   144,   145,    -1,    -1,    -1,   406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   421,    -1,    -1,    -1,   425,   491,    -1,
      -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,   406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,   656,    -1,
      -1,    -1,    -1,   421,    -1,    -1,    -1,   425,    -1,    -1,
      -1,    -1,    -1,   491,    -1,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,   509,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,   491,    -1,   463,    -1,    -1,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,   509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,     6,     7,     8,   590,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   509,    -1,   284,    -1,    -1,   287,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   590,   656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,   656,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,   284,
      -1,    -1,   287,    -1,    -1,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,
      -1,   143,   144,   145,    -1,   406,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
     421,    -1,    -1,    -1,   425,    -1,    -1,    -1,   656,    -1,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,   463,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   476,    -1,    39,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
     491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    18,    19,    20,    -1,   509,    -1,
      24,    25,    26,    27,    -1,    -1,   421,    -1,    -1,    -1,
     425,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,   284,    -1,    -1,   287,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,   463,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,    99,   491,   284,    -1,   590,
     287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     284,    -1,    -1,   287,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,   127,   128,   129,   130,
     131,   132,    -1,    -1,   127,   128,   129,   130,   131,   132,
      -1,    -1,   143,   144,   145,   656,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,    -1,   425,    -1,   590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    99,    -1,   406,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,   463,   284,    -1,   421,   287,    -1,    -1,   425,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,   406,    24,    25,    26,    27,    -1,    -1,   491,
      39,   656,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,   425,    -1,    -1,    -1,    -1,   463,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,   491,    -1,   287,    -1,    -1,   463,
      -1,   284,    -1,    -1,   287,    -1,   127,   128,   129,   130,
     131,   132,   509,    -1,    -1,    -1,    -1,   430,    99,    -1,
      -1,    -1,   143,   144,   145,    -1,    -1,   491,    -1,    -1,
      -1,    -1,   445,   225,    -1,    -1,    -1,    -1,   127,   128,
     129,   130,   131,   132,   406,   509,    -1,    -1,   590,   462,
      -1,    -1,   465,    -1,   143,   144,   145,    -1,    -1,   421,
      -1,    -1,    -1,   425,    -1,   478,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   656,   406,   430,   530,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,   590,    -1,    -1,   491,
     421,   445,    -1,    -1,   425,    -1,    -1,    -1,   421,    -1,
      -1,    -1,   425,    -1,   225,    -1,    -1,   509,   462,    -1,
      -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,   571,   656,
      -1,    -1,    -1,   284,   478,    -1,   287,   114,   115,    -1,
      -1,    -1,   463,    -1,    -1,    -1,    -1,   124,    -1,    -1,
     463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   656,    -1,    -1,   284,    -1,   610,   287,    -1,
     491,    -1,    -1,   517,   518,    -1,    -1,    -1,   491,   622,
      -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,   509,    -1,
      -1,   634,   635,    -1,    -1,    -1,   509,    -1,   590,   642,
      -1,    -1,   645,    -1,    -1,    -1,    -1,    -1,   430,    -1,
     653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   445,    -1,    -1,    -1,   571,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
     462,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   478,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   656,    -1,   610,    -1,    -1,   590,
     421,    -1,    -1,    -1,   425,    -1,    -1,   590,   622,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,
     634,   635,    -1,    -1,    -1,   517,   518,    -1,   642,    -1,
      -1,   645,   421,    -1,    -1,    -1,   425,    -1,   530,   653,
      -1,    -1,   463,    -1,    -1,    -1,    -1,   133,   295,   430,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   445,   656,    -1,    -1,    -1,    -1,
     491,    -1,    -1,   656,   463,    -1,    -1,    -1,    -1,   571,
      -1,   462,    -1,    -1,   465,    -1,    -1,   334,   509,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,
      -1,    -1,   491,    -1,    -1,    -1,   353,   354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,
     509,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,   634,   635,    -1,   392,    -1,    -1,    -1,   530,
     642,    -1,   238,   645,    -1,    -1,    -1,   404,    -1,    -1,
      -1,   653,    -1,    -1,    -1,    -1,    -1,    -1,   415,   590,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,
     571,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,   294,    -1,
      -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,
      -1,    -1,    -1,   319,    -1,   656,    -1,    -1,    -1,    -1,
      -1,   622,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   498,    -1,   634,   635,    -1,    -1,    -1,    -1,    -1,
      -1,   642,    -1,    -1,   645,    -1,    -1,   656,    -1,    -1,
      -1,    -1,   653,    -1,   521,    -1,    -1,    -1,   364,    -1,
      -1,   367,    -1,    -1,    -1,    -1,   372,    -1,    -1,   536,
      -1,    -1,    -1,    -1,   380,    -1,   543,    -1,    -1,   546,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,   608,    -1,    -1,    -1,   451,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   650,   490,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,   525,
      -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,   565,
     566,    -1,    -1,    -1,   570,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     636,    -1,   638
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,   110,   271,   391,   440,   472,   501,   768,   796,
     797,   849,  1021,  1074,  1076,  1077,  1078,  1083,  1085,  1098,
    1099,  1100,  1101,  1102,    28,    29,   769,   770,   771,   772,
     773,    27,   985,  1539,   985,    25,   985,  1439,  1103,   798,
    1439,   797,     0,  1075,  1078,  1083,  1101,    31,   771,   773,
     850,   645,    25,   225,   795,   796,   973,   985,   990,  1104,
    1139,  1140,  1141,  1142,  1143,  1147,   388,   800,   801,   802,
     803,   806,   807,    90,    95,   140,   141,   148,   402,   428,
     499,   591,   671,   679,   768,   774,   945,  1020,  1079,  1080,
    1082,  1086,  1087,  1093,  1105,  1126,  1259,  1269,   650,   985,
    1142,   277,   492,   493,  1149,    20,   985,  1146,   653,   801,
       5,   799,   388,   985,     5,   825,   827,   828,   985,  1270,
     985,   985,  1260,  1094,   985,   985,  1082,  1088,   295,   334,
     353,   354,   392,   404,   415,   432,   442,   458,   498,   521,
     536,   543,   546,   567,   571,   590,   608,   851,   852,   853,
     856,    25,  1139,  1145,    18,    19,    26,    94,   106,   134,
     227,   324,   357,   392,   404,   441,   457,   465,   478,   522,
     547,   571,   615,   624,   708,   709,   718,   720,   911,   916,
     927,   929,   985,  1139,  1150,  1151,   493,    14,   848,   803,
     556,  1246,   804,   801,   806,    32,    34,   114,   115,   124,
     295,   334,   353,   354,   369,   392,   404,   415,   432,   442,
     458,   498,   521,   536,   543,   546,   567,   571,   590,   608,
     650,   810,   819,   830,   831,   985,   465,   147,   985,   795,
     946,  1127,   985,   858,   354,   808,   465,   834,   836,   837,
     835,   844,   845,   465,   465,   857,   493,   465,   801,   832,
     460,   465,   465,   465,   465,   465,   465,   465,   465,   465,
     465,   718,   465,   792,     9,    18,    19,    24,    25,    26,
      99,   329,   422,   427,   430,   447,   462,   465,   468,   477,
     518,   530,   541,   571,   622,   634,   635,   642,   653,   885,
     893,   894,   895,   896,   897,   898,   899,   927,   928,   930,
     991,  1139,  1249,  1431,   465,   465,   465,   465,   465,   465,
      18,    19,    20,    21,    22,   719,    26,   465,   555,     5,
     461,  1150,    25,    26,   985,   991,    19,    25,    26,   805,
     991,   703,   704,   705,   809,   821,   808,   465,   822,   834,
     835,   465,   465,   820,   493,   465,   832,   801,   829,   465,
      26,   985,   465,  1095,   795,   795,   465,   985,   465,   492,
     814,    26,   659,   401,   488,   504,   547,   586,   615,   624,
     838,   659,   401,   488,   504,   547,   586,   615,   624,   846,
      26,    26,   859,   860,   861,   862,   985,    26,   817,   818,
      26,   653,   700,   977,   985,  1530,   977,   977,  1530,  1530,
     885,    25,    26,    19,    24,    25,    26,   931,   932,   933,
     934,  1530,   885,   426,   885,   885,   885,   885,   560,  1266,
     465,   465,   885,   401,   488,   504,   547,   586,   615,   624,
    1434,  1435,   465,   885,   885,   465,   465,   900,   465,   465,
     465,   465,    26,     6,     7,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    39,
     127,   128,   129,   130,   131,   132,   143,   144,   145,   284,
     287,   406,   421,   425,   463,   491,   509,   590,   656,   791,
     886,   901,   903,   904,   905,   906,   907,   908,   909,    26,
     991,   455,   919,   917,   923,   921,  1139,  1139,   718,   912,
     985,  1151,   493,   461,    26,   812,   801,   814,    26,   801,
      26,    26,   800,   817,    26,   653,    93,   826,  1271,   426,
     465,  1261,  1540,  1541,  1542,  1543,  1544,   947,  1128,  1089,
     653,    26,   426,   839,   840,   465,   841,   846,   847,   841,
     465,   842,     5,   426,     5,   426,     5,   318,     5,   851,
     461,     5,     5,   426,   801,   833,   465,   493,   653,     5,
     426,   426,   426,   426,   426,   426,   426,   426,   623,   932,
      19,    26,   623,   426,   426,   426,     5,   793,   885,   505,
    1455,   885,   465,   659,    20,   426,  1455,    20,  1249,   885,
     885,   885,   885,   885,   885,   885,   885,   885,   885,   885,
     885,   885,   885,   885,   885,   885,   885,   885,   885,   885,
     885,   885,   465,   885,   885,   465,  1139,   885,   885,   885,
     885,   426,     5,   748,   749,   750,   885,   465,  1150,   493,
     657,   653,    26,   426,   293,     5,   426,     5,   426,   318,
     461,     5,   426,   833,   985,  1156,  1157,  1159,  1106,  1156,
     396,  1541,  1246,    35,    36,    37,    43,    50,    89,   101,
     102,   104,   118,   125,   136,   137,   138,   152,   154,   155,
     156,   165,   166,   168,   169,   170,   176,   179,   181,   182,
     183,   189,   191,   192,   194,   196,   197,   200,   203,   204,
     205,   207,   208,   212,   213,   214,   216,   220,   222,   223,
     228,   232,   235,   237,   239,   241,   243,   244,   246,   247,
     248,   252,   254,   255,   257,   265,   266,   278,   281,   282,
     285,   286,   289,   290,   298,   299,   300,   302,   312,   313,
     314,   316,   320,   321,   325,   333,   341,   342,   343,   349,
     350,   355,   358,   362,   363,   373,   391,   399,   405,   416,
     435,   437,   438,   446,   485,   496,   503,   527,   528,   532,
     544,   550,   551,   552,   553,   557,   561,   568,   569,   579,
     581,   592,   594,   597,   603,   629,   632,   637,   640,   641,
     655,   662,   685,   686,   687,   688,   689,   690,   691,   694,
     696,   698,   711,   712,   713,   714,   731,   753,   767,   768,
     774,   775,   794,   864,   865,   866,   867,   878,   879,   880,
     881,   882,   883,   884,   936,   940,   971,   992,   994,   997,
     998,   999,  1000,  1013,  1022,  1043,  1044,  1046,  1050,  1065,
    1066,  1070,  1071,  1072,  1073,  1081,  1096,  1109,  1120,  1121,
    1122,  1133,  1136,  1172,  1175,  1177,  1183,  1184,  1187,  1190,
    1193,  1195,  1197,  1200,  1207,  1212,  1216,  1217,  1218,  1230,
    1231,  1234,  1240,  1241,  1242,  1267,  1282,  1283,  1284,  1285,
    1286,  1291,  1297,  1298,  1316,  1319,  1349,  1351,  1440,  1441,
    1472,  1473,  1480,  1491,  1515,  1524,  1529,  1531,  1533,  1537,
    1538,  1545,   768,  1084,   658,   681,  1129,  1130,  1156,    20,
     426,   460,   815,   838,    26,   843,    26,    26,    26,   860,
     862,   854,   818,    26,   985,   718,    20,   700,   985,   977,
     925,  1435,   925,    26,    26,   623,    24,    26,   835,   926,
     836,   426,   394,   510,   619,  1463,   426,   426,    26,  1435,
     426,   426,   426,   426,   426,   426,   426,   476,   476,   476,
     910,  1455,   476,   910,  1455,   920,   918,   924,   922,    26,
     913,     5,   914,   461,  1150,   825,    20,   815,   465,    26,
      26,   811,    26,   653,   426,     5,  1156,   426,  1139,  1139,
    1139,    25,  1139,  1194,   985,   384,   986,   987,  1539,   985,
     985,  1214,   980,   986,   980,    25,   225,   985,  1148,  1519,
    1520,  1521,   985,  1535,    25,   985,  1424,   985,    26,   715,
    1139,  1289,   980,  1214,   910,    26,   991,  1254,  1255,  1254,
     885,   892,  1318,   887,   910,   986,  1481,  1481,   868,  1214,
     980,  1287,  1139,   982,   986,   892,  1481,  1139,  1214,  1139,
    1317,  1481,    25,   619,  1123,  1124,  1139,   980,   980,  1123,
     981,   986,   985,  1124,   980,  1481,   980,   982,  1139,  1170,
    1171,   978,   986,   982,   410,   595,   977,  1045,   985,   776,
     983,   986,    25,  1350,  1519,   910,  1170,   910,   986,  1196,
     941,   167,   175,   184,   187,   230,   238,   294,   319,   326,
     328,   338,   364,   372,   410,   435,   473,   484,   582,   583,
     584,   595,   698,  1059,  1191,  1192,  1139,   891,   892,  1206,
    1530,  1530,   979,   986,   910,  1194,  1268,  1139,  1245,    25,
    1139,  1475,   892,  1236,  1237,  1238,  1247,  1248,   892,  1525,
     139,   190,   227,   324,   400,   441,   508,   732,   916,   985,
    1139,  1277,   755,   892,   978,   623,   985,   993,  1110,   892,
     978,    26,  1139,  1067,   978,   892,  1492,   892,  1254,   985,
     995,   996,   982,   995,  1530,   982,   995,  1530,  1001,   995,
      25,    26,   419,   521,   991,  1048,  1139,  1158,  1160,   100,
     309,   379,   424,   602,   682,   683,   684,   693,   722,  1003,
    1005,  1007,  1009,  1011,  1134,  1135,  1138,   370,   381,   433,
     448,   537,  1352,   673,   674,   949,   950,   951,   985,  1131,
     680,  1130,   426,   337,   426,   426,   426,   426,   657,     5,
     426,   426,   461,   465,   659,   426,    26,   623,   659,    18,
      19,    20,    25,    26,    99,   430,   445,   462,   465,   478,
     518,   530,   571,   610,   622,   634,   635,   642,   645,   985,
     991,  1430,  1432,  1462,  1464,  1465,  1467,  1468,  1469,  1520,
    1523,  1266,   426,  1266,  1266,  1266,  1266,  1266,  1266,    25,
      25,    25,   885,   902,   426,    25,   902,   426,   426,   426,
     426,   426,   426,   426,   750,   748,   461,   337,   801,   823,
     824,   426,   426,   657,   426,   985,  1272,  1159,   426,  1262,
      91,    92,   119,   120,   121,   489,   575,   618,  1299,  1300,
    1301,  1304,  1307,  1310,  1311,  1312,  1313,   465,   653,  1521,
    1149,   650,  1188,   653,     8,   653,   623,   658,   461,  1424,
     513,  1215,  1158,   143,   144,   145,   517,   888,   889,   892,
    1139,  1165,  1424,   721,   722,   871,   301,   122,   123,   659,
     494,     5,   652,   659,   651,   651,  1173,   629,   455,     5,
     590,  1023,   494,   692,  1527,   692,   419,   778,  1139,   580,
     651,  1178,  1179,  1180,   361,  1348,   645,   890,   892,   590,
     890,     8,   979,    26,   535,   588,   702,   972,  1139,   972,
     972,   972,    25,   212,   339,   345,   346,   347,   365,   473,
     476,   484,   519,   554,   573,   574,   584,   589,   628,   660,
    1063,  1064,   972,   972,   630,  1060,   722,  1060,  1060,   973,
     973,  1060,  1060,   722,     5,   368,   420,     5,   721,   116,
     117,   573,   660,  1051,   695,  1528,   891,   646,   647,   648,
     649,  1244,  1246,   418,  1281,  1246,  1238,     5,   651,  1239,
     892,   465,   465,   465,   465,    25,   751,   985,   465,  1475,
     379,   465,   555,   623,   612,   756,   763,   754,   985,    25,
    1125,  1139,  1232,     8,  1235,    14,   985,  1144,  1152,  1153,
    1155,  1163,  1164,  1208,   198,   379,   578,   611,     5,     6,
       7,     8,     9,    10,    12,    13,    14,    18,    19,    20,
      21,    22,    23,    33,    49,    97,   106,   124,   126,   134,
     139,   140,   143,   144,   145,   146,   149,   150,   190,   212,
     218,   225,   227,   233,   258,   296,   309,   315,   324,   325,
     331,   334,   335,   339,   345,   346,   352,   353,   354,   355,
     356,   357,   361,   365,   367,   374,   375,   376,   377,   379,
     380,   384,   385,   387,   388,   389,   391,   392,   393,   394,
     400,   401,   402,   404,   405,   409,   410,   411,   412,   413,
     414,   415,   416,   418,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   461,   462,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   503,   504,
     505,   506,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   545,   546,
     547,   548,   549,   550,   553,   554,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   671,   679,   684,   688,   691,
     692,   693,   694,   697,   698,   700,   701,   702,  1493,  1494,
    1495,  1497,   609,     5,   692,   692,   890,  1158,  1165,  1047,
     455,     5,   186,  1027,   465,  1139,   890,   465,    26,    26,
     100,  1137,    25,  1139,  1479,  1479,   986,  1332,  1196,   979,
     153,   256,   264,   270,   272,   283,   311,   327,   332,   344,
     351,   505,   512,   534,   539,  1320,  1321,  1329,  1339,  1340,
    1346,  1347,  1353,  1354,  1363,  1382,  1386,  1451,  1452,  1482,
    1483,  1486,  1487,  1499,   952,   953,   126,   948,   959,   960,
     951,  1132,  1540,  1090,   493,   851,   818,   653,   985,   401,
     488,   504,   547,   586,   615,   624,  1436,   925,   623,    24,
      26,   839,  1468,  1468,   401,   488,   504,   547,   586,   615,
     624,  1433,  1437,   505,  1467,   465,   465,   465,   465,   465,
     465,   465,   985,   465,     5,   580,  1391,  1396,   985,    18,
      19,    20,    21,   127,   128,   129,   130,   131,   132,  1489,
     455,     5,   426,   426,   915,   493,     5,   426,   825,   795,
    1107,   795,   193,   331,   408,   465,   510,   526,  1369,  1381,
     465,   985,  1315,    26,   280,   293,   465,   510,   526,   985,
    1296,  1309,  1367,  1368,  1373,  1375,  1377,   465,   985,  1306,
     465,  1296,  1302,     5,    25,   988,  1142,  1521,  1519,   610,
     650,  1189,    20,   985,  1169,  1522,   985,  1536,   985,   985,
    1424,   629,   465,   465,   871,     5,   659,   465,  1519,    25,
     990,  1213,  1213,  1475,  1123,   892,   892,   892,   974,   975,
     465,  1139,  1171,   832,  1024,  1025,   659,  1475,  1530,  1528,
    1045,  1139,   777,   658,   892,   385,  1182,   590,  1181,   985,
       5,  1516,   103,   105,   107,   651,   659,   863,  1158,   942,
      18,    19,   465,  1061,  1063,  1192,   973,   892,   379,   629,
      26,    26,   721,   188,  1243,   253,  1248,  1254,  1526,   985,
      25,   935,   977,  1530,   623,   977,   656,  1139,   736,   985,
     985,   892,   374,   759,   763,   612,   757,   765,    23,   269,
    1112,  1116,   516,   910,   516,  1233,   892,   492,  1149,   653,
       5,  1068,   580,  1209,  1139,  1496,  1498,   224,  1494,  1014,
     996,  1530,  1530,  1006,  1007,  1027,  1027,    38,    40,    41,
      42,   305,   308,   310,   330,   340,   359,   382,   386,   464,
    1026,  1028,  1029,  1055,  1139,  1160,   580,   723,    26,   434,
    1012,   356,  1474,  1474,   173,   174,   471,   580,   985,  1383,
    1384,  1425,   832,  1424,  1424,  1322,   832,   985,  1484,  1484,
    1463,  1424,  1330,   202,   473,   484,   505,   512,  1356,  1357,
    1358,  1540,  1540,   419,   961,  1139,   675,   676,   954,   955,
     956,   515,   658,   677,   678,   697,   964,   965,  1540,   795,
      26,   816,    20,   985,   426,   465,    24,    26,   659,  1463,
     426,   430,  1490,  1523,   394,   510,   619,  1415,  1467,  1470,
    1415,  1415,  1415,  1415,   653,  1470,  1465,   549,  1392,  1393,
    1394,  1424,   560,  1390,  1397,   366,   548,   559,  1341,  1458,
    1467,  1467,  1467,  1467,  1520,   885,   426,   816,   824,  1273,
     795,  1263,  1371,  1424,  1314,  1381,   465,  1314,   465,   465,
    1308,  1309,   465,   465,    98,   334,   354,   392,   404,   415,
     432,   442,   445,   458,   506,   536,   546,   567,   571,   599,
     608,  1416,  1417,  1418,  1420,  1305,  1306,  1302,  1303,   697,
    1300,   426,   653,  1475,   610,   493,   580,  1534,   465,   716,
     717,   985,  1290,   910,   888,   985,  1288,   650,  1185,   659,
       5,     5,     5,   613,   892,   653,     5,   517,   659,   658,
     199,   201,   305,   308,   779,   782,   783,  1055,   780,   781,
     985,   465,   986,   682,   683,  1186,   892,   832,  1517,  1518,
     985,   985,   975,   976,   543,  1530,   871,     8,   944,    26,
      26,  1062,  1063,  1139,   354,  1201,   100,   885,  1246,    26,
    1139,  1540,     5,     5,     5,   426,   426,   752,   985,   426,
    1475,   748,   465,   465,   764,   760,   395,   758,   892,   374,
     761,   765,   630,  1057,  1117,  1113,   397,  1111,  1112,   890,
     659,  1145,    20,   985,  1154,  1164,    14,   517,  1210,  1211,
    1467,  1523,  1139,  1161,  1162,  1540,  1008,  1009,   584,   984,
     580,  1038,  1037,  1040,  1039,   977,  1041,   977,  1042,  1036,
    1035,  1033,  1032,  1056,   359,  1029,  1034,  1530,    44,    45,
      46,    47,    48,    49,   133,   367,   380,   444,   451,   490,
     514,   524,   525,   530,   540,   562,   565,   566,   570,   627,
     638,   724,   725,  1053,  1054,     5,    26,  1475,   283,  1139,
     505,  1456,  1457,  1475,  1196,  1450,  1452,   135,   135,   629,
    1194,  1385,  1386,   465,  1364,   185,  1397,  1424,   209,   306,
    1488,   653,   659,  1453,  1500,   376,   385,   410,   413,   430,
     535,   588,   595,   979,  1333,  1338,   465,  1359,   658,     5,
     963,  1139,     5,   580,   957,   958,   672,   956,   962,   985,
     962,   966,   967,   962,   359,   965,  1091,   461,    26,   401,
     488,   504,   547,   586,   615,   624,  1438,  1464,     5,  1437,
     426,     5,  1467,     5,   426,  1467,  1467,  1467,  1467,   985,
     426,   465,  1394,     5,   985,  1429,     9,   329,   465,   477,
    1400,  1401,  1402,  1403,  1404,  1408,  1412,  1414,  1467,   403,
    1388,  1398,   985,  1459,   652,  1415,   366,   461,   495,  1256,
    1276,  1108,   495,  1219,  1250,   465,     5,   426,  1400,   426,
     645,   985,  1370,  1372,  1424,  1427,  1428,  1374,  1427,     5,
     426,  1374,  1400,   465,  1437,  1437,   465,   465,   465,   465,
     465,   242,   434,  1376,  1378,     5,   426,     5,   426,   985,
    1522,     8,  1475,  1150,   892,   985,  1293,  1294,     5,  1295,
    1296,   910,  1097,   653,  1295,   610,  1475,  1475,   892,   892,
     974,   543,   892,  1532,     5,    20,  1427,  1025,  1475,   780,
     788,   787,   789,   985,   989,   790,   989,   226,   783,   786,
       5,  1027,   653,   892,     8,   653,     5,   985,   910,   587,
    1336,     5,   426,  1139,     5,   360,    25,  1278,   977,   379,
     379,   493,   653,   379,   465,   737,   741,   734,  1540,  1540,
     766,   762,   758,  1058,    25,   984,  1118,  1139,  1540,   892,
     460,   493,   910,     5,   455,     5,  1015,  1010,  1011,    26,
     721,   985,  1540,  1540,  1540,  1540,     5,  1030,     5,  1031,
    1540,  1540,  1540,  1540,  1061,  1540,   984,    25,    14,    14,
       5,   426,    26,  1424,  1463,  1444,   629,   629,  1321,  1449,
    1450,  1386,  1365,  1427,   650,   979,   465,  1325,   985,  1485,
    1484,  1464,    83,    84,    85,    86,    87,   617,  1503,   892,
     892,  1331,   979,  1360,  1427,  1424,  1358,     5,  1139,   962,
    1540,  1540,     5,   969,   970,  1540,  1540,   968,  1084,   855,
     426,   465,  1396,  1437,   659,  1437,   426,  1467,   426,   426,
     426,   426,  1393,  1395,  1393,  1403,   465,  1462,  1400,  1467,
    1462,     6,     7,     9,    10,    12,    13,    14,    15,    16,
      17,   287,   406,   407,   463,   590,   656,   706,   707,  1411,
    1413,  1389,  1466,  1467,   482,  1387,  1399,   303,  1292,    26,
    1342,  1343,  1344,  1427,  1456,  1459,   813,   108,   109,   111,
     112,   113,   211,   219,   253,   262,   291,   292,   336,   378,
     434,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,  1253,  1257,   172,   548,  1258,  1274,  1084,   195,   210,
     211,   219,   253,   262,   291,   336,   378,  1251,  1252,  1264,
    1258,  1372,  1381,   426,  1428,   493,  1426,   426,     5,   653,
       5,   426,  1309,   426,   426,    26,  1421,   659,   465,   659,
      26,  1422,  1422,    26,  1422,  1422,    25,  1430,  1379,  1380,
    1381,  1306,  1302,  1475,     8,   461,   572,   621,     5,   426,
     717,     5,   426,   890,   426,    20,   426,  1475,     5,   892,
     600,   309,   726,   727,   892,  1027,  1540,  1540,     5,   784,
     493,   653,     5,   785,  1540,   781,   580,    20,   985,     5,
     985,  1176,    20,  1427,  1518,   424,   692,   890,  1337,   943,
    1063,   701,  1199,   885,     5,   748,  1139,   733,   715,   985,
    1139,   739,   426,   748,   748,  1540,  1540,  1061,  1115,    25,
    1119,  1139,   605,   939,  1150,   517,   891,  1069,  1211,  1139,
    1162,    97,   576,  1016,  1002,  1003,   653,   977,  1540,   977,
    1540,   721,    26,  1139,    26,  1139,   725,   426,   465,  1476,
    1464,  1450,  1450,  1442,     5,   426,   505,  1461,  1326,  1427,
     513,  1323,  1461,   659,  1454,    18,    19,    99,   462,   465,
     478,   517,   518,   530,   571,   610,   622,   634,   635,   642,
     645,   985,  1430,  1462,  1508,  1509,  1510,  1511,  1512,  1513,
    1523,  1508,  1508,  1508,  1427,  1505,  1507,  1504,  1505,  1506,
    1501,   587,  1334,     5,   426,   659,  1139,   985,  1540,  1540,
    1540,  1540,   657,    26,   426,   659,  1438,   659,     5,   426,
     426,  1401,  1402,  1406,  1468,  1406,   465,  1462,  1406,   465,
    1462,  1406,    10,   284,   421,   423,  1467,     5,  1400,     5,
     572,   621,  1345,  1292,   657,  1254,  1254,  1254,    25,  1254,
    1254,  1254,  1254,  1254,  1254,    25,    25,  1254,  1257,  1139,
    1166,  1167,   652,   481,  1220,  1540,    25,    25,    26,    26,
      26,    26,    26,    25,  1139,  1252,  1220,   426,    26,  1369,
    1427,    20,   985,  1427,   426,  1438,    26,  1438,     5,  1419,
    1419,     5,   426,   426,  1419,  1381,  1475,  1294,  1296,  1292,
     502,   870,     5,   409,  1475,     5,   465,   426,   584,  1052,
     989,  1540,   718,    20,   985,   989,  1540,  1530,   892,  1530,
    1161,  1540,    26,   984,    25,  1279,  1158,   461,   748,   738,
     742,   426,  1540,   984,   892,   937,   461,  1018,  1017,   475,
    1004,  1005,    20,   985,  1477,  1478,   587,  1460,  1445,  1443,
    1427,  1463,   177,  1366,     5,   426,  1324,  1485,  1460,  1511,
    1511,  1510,   465,   465,   465,   465,   465,   465,   465,   985,
     465,     5,   426,    18,    19,    20,    21,  1489,   426,     5,
     426,     5,    14,   185,   560,  1502,  1335,  1427,   497,  1361,
    1362,  1425,   245,  1092,   851,   426,  1438,  1438,  1393,   476,
    1405,  1405,  1409,  1410,  1430,  1523,  1405,  1409,  1405,  1406,
    1467,  1466,  1343,   825,   572,   621,  1168,     5,  1166,    96,
     171,   234,   236,   251,   259,   263,   288,  1221,  1222,  1275,
    1092,  1265,     5,   461,  1426,   426,    26,  1423,   426,   426,
      26,   426,   977,   721,   409,  1475,   892,   728,   602,  1174,
      26,   721,   461,  1052,   426,   275,   721,   426,   426,   465,
     740,   379,   746,   426,   735,  1114,  1540,   493,   892,  1540,
     984,     5,   426,  1161,  1396,  1464,  1427,   465,  1396,   426,
    1490,  1415,  1510,  1514,  1415,  1415,  1415,  1415,   653,  1514,
    1509,  1510,  1510,  1510,  1510,  1505,    14,  1506,  1509,   979,
    1400,  1161,     5,   178,  1355,  1407,  1430,  1471,     5,   426,
     426,  1405,     7,  1167,  1223,  1224,  1139,  1226,  1139,  1225,
    1227,  1222,   274,   274,    26,   659,   426,   869,  1475,   427,
     238,   294,   319,   328,   364,   372,   466,   636,   725,   729,
     730,   465,   653,   721,  1198,  1280,   743,   426,  1158,   746,
     746,  1540,   938,  1150,   609,  1049,  1478,  1458,  1396,   517,
    1327,  1328,  1467,  1458,   426,  1510,     5,   426,  1510,  1510,
    1510,  1510,   985,   426,   465,  1362,  1410,  1467,  1540,  1540,
    1228,  1540,  1229,  1540,  1540,   461,  1438,   273,   382,   386,
     872,   873,   874,  1055,   972,   972,   972,   972,   972,   972,
      25,     5,   426,   892,    20,   985,  1055,  1202,  1203,  1204,
     746,   748,   746,   276,   461,  1019,   721,     5,   426,   322,
     323,  1446,   426,  1510,   426,   426,   426,   426,  1508,  1540,
    1540,   876,   875,   273,   874,   877,   730,     5,  1205,   317,
    1204,   744,  1540,  1328,    25,   985,  1447,  1448,   426,  1540,
    1540,  1540,   892,  1540,   426,  1016,   653,   653,     5,   426,
     745,   985,   985,  1448,   198,   379,   747,   653,  1158,   985
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
#line 973 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 976 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 980 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 986 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 991 "fgl.yacc"
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
#line 1003 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1008 "fgl.yacc"
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
#line 1031 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1032 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1033 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1034 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1035 "fgl.yacc"
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
#line 1046 "fgl.yacc"
    {
	struct expr_str *ptr;
	char buff2[1024];
	char buff[1024];
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1055 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1056 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1057 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1058 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1059 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1064 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1065 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1076 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1082 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1089 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1090 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1096 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1097 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1098 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1099 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1100 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1101 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1102 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1103 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1104 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1105 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1106 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1107 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1108 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1109 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1110 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1111 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1112 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1119 "fgl.yacc"
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
#line 1130 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1134 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1135 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1139 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1145 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1147 "fgl.yacc"
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
#line 1158 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1160 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1162 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1164 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1168 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1170 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1231 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1235 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1239 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 66:
#line 1246 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1249 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1253 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1257 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 71:
#line 1264 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1270 "fgl.yacc"
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
#line 1279 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 74:
#line 1283 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1288 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1292 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1300 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 78:
#line 1304 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1308 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1310 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1316 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1321 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1324 "fgl.yacc"
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
#line 1340 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1347 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1351 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1355 "fgl.yacc"
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
#line 1377 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1377 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1381 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1382 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1383 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1388 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1391 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1397 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1400 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1412 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1418 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1421 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1436 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1446 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1452 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1461 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1474 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1477 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1479 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1485 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1487 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1492 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1497 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1503 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1507 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1522 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1525 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1528 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1531 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1534 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1537 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1559 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1568 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1578 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1592 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1597 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1600 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1609 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1615 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1630 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1634 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1639 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1649 "fgl.yacc"
    {
		A4GL_add_event(-97,yyvsp[0].str);
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1653 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 153:
#line 1657 "fgl.yacc"
    {
		A4GL_add_event(-98,yyvsp[0].str);
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1660 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 155:
#line 1663 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 156:
#line 1666 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 157:
#line 1669 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 158:
#line 1672 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1675 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 160:
#line 1679 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 161:
#line 1689 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1690 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1698 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 164:
#line 1699 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 165:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1719 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1722 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1725 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1728 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1731 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1740 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1748 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1753 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1766 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1770 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1785 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1786 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1794 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1794 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1803 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1803 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1812 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1813 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1814 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1817 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1822 "fgl.yacc"
    { }
    break;

  case 194:
#line 1822 "fgl.yacc"
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
#line 1839 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1843 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1858 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1859 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1860 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1861 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1866 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1872 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1881 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1885 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1901 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1903 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1904 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1911 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1911 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1912 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1913 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1916 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1918 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1928 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1943 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1943 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1949 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1950 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 242:
#line 1957 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 243:
#line 1958 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 244:
#line 1959 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 245:
#line 1960 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 246:
#line 1963 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 247:
#line 1964 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 248:
#line 1965 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1966 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 250:
#line 1970 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 251:
#line 1975 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1980 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 253:
#line 1984 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1987 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1991 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 256:
#line 1992 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 257:
#line 1993 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 258:
#line 1994 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 259:
#line 1995 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1996 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 261:
#line 1997 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1998 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 263:
#line 2001 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 264:
#line 2002 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 265:
#line 2003 "fgl.yacc"
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

  case 266:
#line 2035 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 267:
#line 2039 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 2041 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2043 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 270:
#line 2045 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 271:
#line 2050 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 272:
#line 2054 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 273:
#line 2054 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 274:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 275:
#line 2059 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 276:
#line 2060 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 277:
#line 2061 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 278:
#line 2062 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 279:
#line 2063 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 280:
#line 2065 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 281:
#line 2070 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 282:
#line 2070 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 283:
#line 2073 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 284:
#line 2075 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 285:
#line 2081 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2083 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 287:
#line 2089 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 288:
#line 2097 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 289:
#line 2097 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 290:
#line 2100 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 291:
#line 2101 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 292:
#line 2102 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 293:
#line 2103 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 294:
#line 2104 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 295:
#line 2105 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 296:
#line 2107 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 300:
#line 2128 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 304:
#line 2137 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 305:
#line 2139 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 306:
#line 2141 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2143 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 308:
#line 2144 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 309:
#line 2145 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 310:
#line 2146 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 311:
#line 2147 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 312:
#line 2152 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2159 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2164 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 315:
#line 2166 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2168 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2169 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 318:
#line 2170 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 319:
#line 2171 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 320:
#line 2172 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 321:
#line 2173 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 322:
#line 2174 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 323:
#line 2177 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 324:
#line 2179 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 325:
#line 2185 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 326:
#line 2193 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 328:
#line 2201 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2205 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 330:
#line 2213 "fgl.yacc"
    {dim_push_record();}
    break;

  case 331:
#line 2214 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 332:
#line 2215 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 333:
#line 2216 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 339:
#line 2235 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 340:
#line 2247 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 341:
#line 2251 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 342:
#line 2254 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 343:
#line 2257 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 344:
#line 2258 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 345:
#line 2259 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 346:
#line 2260 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 347:
#line 2261 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 348:
#line 2267 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 349:
#line 2274 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 350:
#line 2279 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 351:
#line 2284 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 352:
#line 2289 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 353:
#line 2293 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 354:
#line 2302 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 355:
#line 2304 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 356:
#line 2309 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 362:
#line 2321 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 363:
#line 2325 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 364:
#line 2328 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 365:
#line 2332 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 366:
#line 2335 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 367:
#line 2339 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 368:
#line 2346 "fgl.yacc"
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

  case 369:
#line 2364 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 370:
#line 2370 "fgl.yacc"
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

  case 371:
#line 2394 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 372:
#line 2397 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 373:
#line 2412 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 374:
#line 2414 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 375:
#line 2416 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 376:
#line 2418 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 377:
#line 2420 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 378:
#line 2422 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 379:
#line 2423 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 380:
#line 2430 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 381:
#line 2432 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 382:
#line 2436 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 383:
#line 2438 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 384:
#line 2440 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 385:
#line 2442 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 386:
#line 2444 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 387:
#line 2446 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 388:
#line 2448 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 389:
#line 2454 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 390:
#line 2468 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 391:
#line 2471 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 396:
#line 2488 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 399:
#line 2494 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 400:
#line 2498 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 401:
#line 2503 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 405:
#line 2513 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 406:
#line 2514 "fgl.yacc"
    {inc_counter();}
    break;

  case 412:
#line 2520 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 413:
#line 2527 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 414:
#line 2527 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 416:
#line 2532 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 417:
#line 2536 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 418:
#line 2542 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2550 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2556 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2565 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 422:
#line 2567 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 423:
#line 2574 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 424:
#line 2582 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 425:
#line 2586 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 426:
#line 2595 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 427:
#line 2600 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 428:
#line 2605 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 429:
#line 2609 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 430:
#line 2611 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 431:
#line 2614 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 432:
#line 2621 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 433:
#line 2629 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 434:
#line 2641 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2647 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2653 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 439:
#line 2663 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 440:
#line 2669 "fgl.yacc"
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
               		strcpy(yyval.str,"A4GL_push_variable(&rep.page_no,2);");
                  		}
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&rep.line_no,2);");
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

  case 441:
#line 2741 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 442:
#line 2747 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2751 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 444:
#line 2759 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 445:
#line 2759 "fgl.yacc"
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

  case 446:
#line 2775 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 447:
#line 2779 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 448:
#line 2785 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 449:
#line 2788 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 450:
#line 2796 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 451:
#line 2800 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 452:
#line 2803 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 453:
#line 2809 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 454:
#line 2819 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 455:
#line 2824 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2831 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 457:
#line 2834 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 458:
#line 2837 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 459:
#line 2842 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 460:
#line 2849 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 461:
#line 2854 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2859 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 463:
#line 2864 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2875 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 465:
#line 2883 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 466:
#line 2891 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 467:
#line 2896 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 468:
#line 2900 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 469:
#line 2905 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 470:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 471:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 472:
#line 2919 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 473:
#line 2922 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 475:
#line 2930 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 476:
#line 2934 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 477:
#line 2938 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 478:
#line 2942 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 479:
#line 2949 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 480:
#line 2959 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 481:
#line 2964 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 482:
#line 2970 "fgl.yacc"
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

  case 483:
#line 2980 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 484:
#line 2985 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 485:
#line 2988 "fgl.yacc"
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

  case 486:
#line 3002 "fgl.yacc"
    {chk4var=1;}
    break;

  case 487:
#line 3002 "fgl.yacc"
    {chk4var=0;}
    break;

  case 488:
#line 3002 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 489:
#line 3005 "fgl.yacc"
    {chk4var=1;}
    break;

  case 490:
#line 3005 "fgl.yacc"
    {chk4var=0;}
    break;

  case 491:
#line 3005 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 492:
#line 3009 "fgl.yacc"
    {chk4var=1;}
    break;

  case 493:
#line 3009 "fgl.yacc"
    {chk4var=0;}
    break;

  case 494:
#line 3009 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 495:
#line 3013 "fgl.yacc"
    {chk4var=1;}
    break;

  case 496:
#line 3013 "fgl.yacc"
    {chk4var=0;}
    break;

  case 497:
#line 3013 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 498:
#line 3017 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3023 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3029 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3035 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3041 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 503:
#line 3047 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3057 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 505:
#line 3058 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 508:
#line 3066 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 509:
#line 3077 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 510:
#line 3078 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 511:
#line 3084 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",yyvsp[-1].str); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 512:
#line 3095 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 513:
#line 3105 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 516:
#line 3118 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 517:
#line 3123 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 518:
#line 3130 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 519:
#line 3134 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 520:
#line 3137 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 521:
#line 3140 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 522:
#line 3146 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 523:
#line 3149 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 524:
#line 3152 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3169 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 526:
#line 3172 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 527:
#line 3178 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 528:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 529:
#line 3180 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 531:
#line 3185 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 532:
#line 3186 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 533:
#line 3187 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3188 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3190 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3191 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3192 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3194 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3195 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 541:
#line 3201 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 543:
#line 3206 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 544:
#line 3218 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 545:
#line 3222 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 546:
#line 3223 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 547:
#line 3230 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 549:
#line 3247 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 550:
#line 3251 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 551:
#line 3257 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 552:
#line 3261 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 553:
#line 3270 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 554:
#line 3271 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 555:
#line 3283 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 556:
#line 3289 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 557:
#line 3297 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 564:
#line 3314 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 565:
#line 3316 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3319 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 567:
#line 3321 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3335 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 573:
#line 3337 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3340 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 575:
#line 3342 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 588:
#line 3373 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 589:
#line 3375 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 590:
#line 3378 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 591:
#line 3380 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 592:
#line 3383 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 593:
#line 3385 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 594:
#line 3388 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 595:
#line 3390 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 596:
#line 3393 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 597:
#line 3395 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 598:
#line 3410 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 599:
#line 3426 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 600:
#line 3427 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 601:
#line 3428 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 602:
#line 3429 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 603:
#line 3430 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 604:
#line 3431 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 605:
#line 3432 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 609:
#line 3440 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 611:
#line 3446 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 612:
#line 3448 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 613:
#line 3449 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 614:
#line 3451 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 615:
#line 3453 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 616:
#line 3455 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 617:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 618:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 619:
#line 3462 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 620:
#line 3469 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 621:
#line 3471 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 622:
#line 3477 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3482 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 624:
#line 3487 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 625:
#line 3492 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 626:
#line 3492 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 627:
#line 3495 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 628:
#line 3501 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 629:
#line 3506 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 630:
#line 3510 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 633:
#line 3518 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 634:
#line 3520 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 635:
#line 3522 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 636:
#line 3524 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 637:
#line 3526 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 638:
#line 3528 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 639:
#line 3531 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 641:
#line 3540 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 642:
#line 3602 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 644:
#line 3608 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 645:
#line 3617 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 647:
#line 3624 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 648:
#line 3627 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 649:
#line 3633 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 650:
#line 3639 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 651:
#line 3643 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 652:
#line 3647 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 653:
#line 3653 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 654:
#line 3657 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 655:
#line 3661 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 656:
#line 3666 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 657:
#line 3671 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 676:
#line 3712 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 677:
#line 3719 "fgl.yacc"
    {
		int a;
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 678:
#line 3722 "fgl.yacc"
    {
		char wt;
		print_if_end();
	        wt=get_curr_report_stack_whytype();
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

  case 680:
#line 3741 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 682:
#line 3744 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 683:
#line 3746 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 684:
#line 3749 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 685:
#line 3753 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 686:
#line 3756 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 687:
#line 3762 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 688:
#line 3773 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 689:
#line 3774 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 690:
#line 3777 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 692:
#line 3783 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 693:
#line 3787 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 694:
#line 3788 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 698:
#line 3804 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 699:
#line 3806 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 702:
#line 3815 "fgl.yacc"
    {
		A4GL_add_event(-97,yyvsp[0].str);
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 703:
#line 3818 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 704:
#line 3822 "fgl.yacc"
    {
		A4GL_add_event(-98,yyvsp[0].str);
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 705:
#line 3825 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 706:
#line 3828 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 707:
#line 3831 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 708:
#line 3834 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 709:
#line 3838 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 710:
#line 3841 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 711:
#line 3844 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 712:
#line 3847 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 713:
#line 3850 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 714:
#line 3853 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 715:
#line 3856 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 716:
#line 3859 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 717:
#line 3862 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 718:
#line 3863 "fgl.yacc"
    {
		A4GL_add_event(-14,"");
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 719:
#line 3866 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 720:
#line 3867 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 721:
#line 3870 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 722:
#line 3871 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 723:
#line 3874 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 724:
#line 3881 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 725:
#line 3882 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"%s",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 726:
#line 3890 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 727:
#line 3891 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"%s",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 728:
#line 3900 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 729:
#line 3905 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 730:
#line 3910 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 731:
#line 3911 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 733:
#line 3916 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 734:
#line 3920 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 735:
#line 3929 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 736:
#line 3934 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 737:
#line 3938 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 738:
#line 3945 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 739:
#line 3954 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 740:
#line 3960 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 741:
#line 3961 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 742:
#line 3962 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 743:
#line 3963 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 744:
#line 3966 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 746:
#line 3969 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 747:
#line 3976 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 748:
#line 3977 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 749:
#line 3978 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 750:
#line 3979 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 751:
#line 3980 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 752:
#line 3981 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 753:
#line 3982 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 754:
#line 3983 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 755:
#line 3984 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 756:
#line 3989 "fgl.yacc"
    {iskey=1;}
    break;

  case 757:
#line 3989 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 758:
#line 3991 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 759:
#line 3994 "fgl.yacc"
    {iskey=1;}
    break;

  case 760:
#line 3994 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 761:
#line 3996 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 762:
#line 4000 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 763:
#line 4003 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 764:
#line 4004 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 766:
#line 4007 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 772:
#line 4019 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 773:
#line 4020 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 774:
#line 4021 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 775:
#line 4022 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 776:
#line 4023 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 777:
#line 4024 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 778:
#line 4025 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 779:
#line 4026 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 780:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 781:
#line 4028 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 782:
#line 4029 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 783:
#line 4030 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 784:
#line 4031 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 785:
#line 4032 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 786:
#line 4036 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 787:
#line 4054 "fgl.yacc"
    {chk4var=1;}
    break;

  case 788:
#line 4054 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 789:
#line 4057 "fgl.yacc"
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

  case 790:
#line 4081 "fgl.yacc"
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

  case 792:
#line 4099 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 793:
#line 4105 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 794:
#line 4111 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 795:
#line 4117 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-1].str);
if (vtype!=11&&vtype!=12) {
a4gl_yyerror("Only Byte & Text may be located...");
YYERROR;
}
print_locate('M',yyvsp[-1].str,"0");


}
    break;

  case 796:
#line 4128 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-2].str);
if (vtype!=11&&vtype!=12) {
a4gl_yyerror("Only Byte & Text may be located...");
YYERROR;
}

print_locate('F',yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 797:
#line 4151 "fgl.yacc"
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

  case 800:
#line 4167 "fgl.yacc"
    {
	}
    break;

  case 807:
#line 4190 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 811:
#line 4198 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 826:
#line 4223 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 827:
#line 4224 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 828:
#line 4232 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 829:
#line 4237 "fgl.yacc"
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

  case 830:
#line 4253 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 831:
#line 4259 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 833:
#line 4274 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 834:
#line 4287 "fgl.yacc"
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

  case 835:
#line 4297 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 836:
#line 4304 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 837:
#line 4311 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 838:
#line 4317 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 839:
#line 4317 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 840:
#line 4322 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 841:
#line 4328 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 842:
#line 4336 "fgl.yacc"
    {
}
    break;

  case 848:
#line 4348 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 850:
#line 4356 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 851:
#line 4362 "fgl.yacc"
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

  case 852:
#line 4376 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 853:
#line 4380 "fgl.yacc"
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

  case 854:
#line 4393 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 856:
#line 4411 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 857:
#line 4419 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 858:
#line 4425 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 859:
#line 4436 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 860:
#line 4440 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 861:
#line 4447 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 862:
#line 4454 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 863:
#line 4460 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 864:
#line 4465 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 867:
#line 4472 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 868:
#line 4473 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 869:
#line 4475 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 870:
#line 4476 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4479 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 872:
#line 4480 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 873:
#line 4481 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 874:
#line 4483 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 875:
#line 4488 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 876:
#line 4493 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 877:
#line 4500 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 881:
#line 4507 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 882:
#line 4509 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 883:
#line 4511 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 884:
#line 4520 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 885:
#line 4526 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 886:
#line 4530 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 889:
#line 4542 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 890:
#line 4547 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 891:
#line 4552 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 892:
#line 4555 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 894:
#line 4567 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 895:
#line 4570 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 896:
#line 4573 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 903:
#line 4589 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 904:
#line 4594 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 905:
#line 4594 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 906:
#line 4597 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 907:
#line 4624 "fgl.yacc"
    {
char buff[256];
char buff2[256];
char c;
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

  case 909:
#line 4682 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 911:
#line 4689 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 912:
#line 4693 "fgl.yacc"
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

  case 913:
#line 4736 "fgl.yacc"
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

  case 917:
#line 4784 "fgl.yacc"
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

  case 918:
#line 4798 "fgl.yacc"
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

  case 923:
#line 4822 "fgl.yacc"
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

  case 924:
#line 4882 "fgl.yacc"
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

  case 925:
#line 4938 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 926:
#line 4943 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 927:
#line 4951 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 928:
#line 4956 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 929:
#line 4964 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 930:
#line 4970 "fgl.yacc"
    {
char buff[256];
char c;
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

  case 931:
#line 5003 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 932:
#line 5006 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 933:
#line 5008 "fgl.yacc"
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

  case 934:
#line 5049 "fgl.yacc"
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

  case 939:
#line 5102 "fgl.yacc"
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

  case 940:
#line 5154 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 942:
#line 5161 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 943:
#line 5167 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 944:
#line 5178 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 945:
#line 5185 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 947:
#line 5193 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 948:
#line 5196 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 949:
#line 5197 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 951:
#line 5199 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 952:
#line 5200 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 953:
#line 5203 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 954:
#line 5206 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5212 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 956:
#line 5215 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 957:
#line 5219 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 958:
#line 5224 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 959:
#line 5232 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 960:
#line 5237 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 961:
#line 5244 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 962:
#line 5247 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5260 "fgl.yacc"
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

  case 968:
#line 5279 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5286 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 5293 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 971:
#line 5296 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 972:
#line 5310 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 977:
#line 5327 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 978:
#line 5332 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 979:
#line 5338 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 981:
#line 5345 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 982:
#line 5350 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 983:
#line 5353 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 984:
#line 5354 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 985:
#line 5357 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 986:
#line 5358 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 987:
#line 5361 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 988:
#line 5362 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 989:
#line 5367 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 990:
#line 5374 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 991:
#line 5377 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 992:
#line 5383 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 993:
#line 5385 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 994:
#line 5387 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 995:
#line 5389 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 996:
#line 5392 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 997:
#line 5392 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 998:
#line 5393 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 999:
#line 5398 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1000:
#line 5406 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1001:
#line 5407 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1002:
#line 5412 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1003:
#line 5414 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1004:
#line 5416 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5433 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1009:
#line 5436 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1010:
#line 5439 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1011:
#line 5442 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1012:
#line 5446 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1013:
#line 5449 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1014:
#line 5452 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1015:
#line 5456 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1016:
#line 5460 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1017:
#line 5464 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1018:
#line 5467 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1019:
#line 5471 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1020:
#line 5474 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1021:
#line 5475 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1022:
#line 5476 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1023:
#line 5479 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1024:
#line 5482 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1025:
#line 5485 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1026:
#line 5488 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1027:
#line 5491 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1028:
#line 5494 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1029:
#line 5497 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1030:
#line 5514 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1033:
#line 5524 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1034:
#line 5530 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1035:
#line 5534 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1037:
#line 5554 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1038:
#line 5559 "fgl.yacc"
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

  case 1039:
#line 5572 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1040:
#line 5573 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1041:
#line 5577 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1042:
#line 5582 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1043:
#line 5583 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1044:
#line 5587 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1048:
#line 5593 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1049:
#line 5596 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1051:
#line 5611 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1052:
#line 5615 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1053:
#line 5621 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1054:
#line 5622 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1055:
#line 5627 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1056:
#line 5628 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1057:
#line 5631 "fgl.yacc"
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

  case 1059:
#line 5659 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1060:
#line 5664 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1061:
#line 5669 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1062:
#line 5674 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1068:
#line 5696 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1069:
#line 5703 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1070:
#line 5712 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1071:
#line 5718 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1072:
#line 5720 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1076:
#line 5731 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1077:
#line 5732 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1078:
#line 5738 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1079:
#line 5742 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1080:
#line 5748 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1081:
#line 5749 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1082:
#line 5754 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1083:
#line 5755 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1084:
#line 5757 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1085:
#line 5758 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5759 "fgl.yacc"
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

  case 1087:
#line 5773 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5775 "fgl.yacc"
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

  case 1089:
#line 5792 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1096:
#line 5804 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1097:
#line 5804 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1098:
#line 5810 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1099:
#line 5810 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1100:
#line 5813 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1101:
#line 5813 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	if (if_print_stack_cnt==0) if_print_section[0]=0;
	if (get_curr_report_stack_whytype()=='T') {
		if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=(int)n;
	}
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1102:
#line 5829 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1103:
#line 5830 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1104:
#line 5831 "fgl.yacc"
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

  case 1105:
#line 5840 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1106:
#line 5852 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1112:
#line 5863 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1113:
#line 5868 "fgl.yacc"
    {
	char wt;
	print_report_print(0,yyvsp[0].str,0);
	wt=get_curr_report_stack_whytype();
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
		if (get_curr_report_stack_whytype()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
}
    break;

  case 1114:
#line 5888 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1115:
#line 5893 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1116:
#line 5899 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1117:
#line 5900 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1118:
#line 5901 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1119:
#line 5905 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1120:
#line 5906 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1121:
#line 5907 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1122:
#line 5908 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1123:
#line 5912 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1124:
#line 5922 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1125:
#line 5924 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1126:
#line 5929 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1127:
#line 5932 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1128:
#line 5937 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1129:
#line 5944 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1130:
#line 5951 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1131:
#line 5958 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1132:
#line 5967 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1133:
#line 5974 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1134:
#line 5981 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1135:
#line 5988 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1136:
#line 5995 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1141:
#line 6008 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1142:
#line 6009 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1143:
#line 6010 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 6011 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1145:
#line 6012 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1146:
#line 6013 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1147:
#line 6014 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1148:
#line 6015 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1149:
#line 6016 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1150:
#line 6017 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1153:
#line 6023 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1154:
#line 6024 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1155:
#line 6025 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1156:
#line 6026 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1161:
#line 6035 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1162:
#line 6036 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1163:
#line 6037 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1164:
#line 6038 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6039 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1166:
#line 6040 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6041 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1168:
#line 6042 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1169:
#line 6044 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1170:
#line 6045 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1171:
#line 6046 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1172:
#line 6047 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1173:
#line 6049 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1174:
#line 6050 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1175:
#line 6051 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1176:
#line 6052 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1180:
#line 6057 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1181:
#line 6058 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1185:
#line 6065 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1186:
#line 6073 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1187:
#line 6081 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1188:
#line 6093 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1189:
#line 6102 "fgl.yacc"
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

  case 1190:
#line 6113 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1191:
#line 6117 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1192:
#line 6121 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1193:
#line 6127 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1194:
#line 6132 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1195:
#line 6140 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1196:
#line 6143 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1197:
#line 6152 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1198:
#line 6163 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1200:
#line 6170 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1201:
#line 6178 "fgl.yacc"
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

  case 1202:
#line 6188 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1203:
#line 6191 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1204:
#line 6195 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1205:
#line 6203 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1206:
#line 6206 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1207:
#line 6212 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1208:
#line 6216 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1209:
#line 6220 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1210:
#line 6224 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1211:
#line 6228 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1212:
#line 6234 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1213:
#line 6235 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1214:
#line 6236 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1215:
#line 6237 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1216:
#line 6242 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1217:
#line 6244 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1218:
#line 6247 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1219:
#line 6251 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1220:
#line 6254 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1221:
#line 6261 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1222:
#line 6266 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1223:
#line 6267 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1224:
#line 6268 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1225:
#line 6273 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1226:
#line 6274 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1227:
#line 6280 "fgl.yacc"
    {insql=1;}
    break;

  case 1228:
#line 6280 "fgl.yacc"
    {insql=0;}
    break;

  case 1229:
#line 6280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1230:
#line 6285 "fgl.yacc"
    {insql=1;}
    break;

  case 1231:
#line 6285 "fgl.yacc"
    {insql=0;}
    break;

  case 1232:
#line 6285 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1233:
#line 6296 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s ",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1234:
#line 6297 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1235:
#line 6303 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1236:
#line 6305 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1238:
#line 6318 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1239:
#line 6322 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1240:
#line 6323 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1242:
#line 6328 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6331 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1244:
#line 6337 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6340 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1246:
#line 6348 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1248:
#line 6355 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1249:
#line 6362 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 6365 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1251:
#line 6374 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1252:
#line 6377 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1253:
#line 6380 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1254:
#line 6383 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6386 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6389 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1257:
#line 6392 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1258:
#line 6399 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1259:
#line 6402 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1260:
#line 6409 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 6412 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1262:
#line 6418 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6421 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1264:
#line 6428 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1265:
#line 6431 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1267:
#line 6439 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1269:
#line 6448 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1270:
#line 6451 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1271:
#line 6457 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1272:
#line 6460 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1273:
#line 6466 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 6473 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1275:
#line 6474 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1276:
#line 6478 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1277:
#line 6484 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1278:
#line 6487 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1280:
#line 6495 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1281:
#line 6502 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1282:
#line 6505 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1286:
#line 6523 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1292:
#line 6529 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1293:
#line 6532 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1294:
#line 6535 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1295:
#line 6541 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1297:
#line 6547 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1299:
#line 6558 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1300:
#line 6572 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1301:
#line 6581 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1302:
#line 6581 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1303:
#line 6586 "fgl.yacc"
    {insql=1;}
    break;

  case 1304:
#line 6586 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1305:
#line 6591 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1306:
#line 6594 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1307:
#line 6596 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1309:
#line 6603 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1310:
#line 6607 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1311:
#line 6611 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1312:
#line 6618 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1313:
#line 6621 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1314:
#line 6628 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1315:
#line 6632 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1316:
#line 6636 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1317:
#line 6641 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1318:
#line 6646 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1319:
#line 6650 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1320:
#line 6656 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1321:
#line 6660 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1322:
#line 6666 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1323:
#line 6673 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1324:
#line 6677 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1325:
#line 6682 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1326:
#line 6692 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1327:
#line 6695 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1328:
#line 6697 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1329:
#line 6699 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1330:
#line 6701 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6703 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1332:
#line 6705 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1333:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1334:
#line 6713 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1335:
#line 6723 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1336:
#line 6730 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1338:
#line 6736 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1339:
#line 6739 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6746 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1345:
#line 6751 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1346:
#line 6756 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1347:
#line 6763 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1348:
#line 6764 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1349:
#line 6771 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1350:
#line 6782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1351:
#line 6783 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1352:
#line 6784 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1353:
#line 6787 "fgl.yacc"
    {insql=1;}
    break;

  case 1354:
#line 6787 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1355:
#line 6792 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1356:
#line 6797 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1358:
#line 6803 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1360:
#line 6807 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1361:
#line 6812 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1362:
#line 6817 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1363:
#line 6821 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1365:
#line 6827 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1366:
#line 6831 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1367:
#line 6839 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1368:
#line 6842 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1369:
#line 6844 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1370:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1373:
#line 6856 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 6863 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6866 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1379:
#line 6868 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6874 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6880 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6890 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1387:
#line 6895 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1388:
#line 6897 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1390:
#line 6903 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6906 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6912 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1394:
#line 6920 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1398:
#line 6935 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6941 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6947 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6949 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6955 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6960 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1406:
#line 6963 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1407:
#line 6966 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1408:
#line 6974 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6976 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1410:
#line 6989 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6994 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1413:
#line 6998 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1414:
#line 7000 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1415:
#line 7007 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1416:
#line 7010 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1417:
#line 7016 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1418:
#line 7020 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1419:
#line 7024 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1420:
#line 7028 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1421:
#line 7031 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1422:
#line 7039 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1423:
#line 7046 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1426:
#line 7055 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1427:
#line 7061 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1428:
#line 7064 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1429:
#line 7075 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1430:
#line 7082 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1431:
#line 7088 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1432:
#line 7091 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 7098 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1434:
#line 7105 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1436:
#line 7112 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1437:
#line 7118 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1438:
#line 7119 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 7120 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1441:
#line 7124 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7129 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1444:
#line 7136 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1445:
#line 7141 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1446:
#line 7142 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1447:
#line 7145 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1448:
#line 7148 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1449:
#line 7153 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1450:
#line 7154 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1451:
#line 7159 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1452:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1453:
#line 7168 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1454:
#line 7171 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1455:
#line 7177 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1456:
#line 7180 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 7186 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 7189 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1459:
#line 7196 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1460:
#line 7197 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1461:
#line 7226 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1462:
#line 7228 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1463:
#line 7232 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1465:
#line 7245 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1466:
#line 7248 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1467:
#line 7251 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1468:
#line 7254 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1470:
#line 7262 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 7265 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1473:
#line 7271 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7277 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1476:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1477:
#line 7283 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1478:
#line 7286 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1479:
#line 7289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1480:
#line 7292 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1481:
#line 7295 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7298 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1483:
#line 7303 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1485:
#line 7310 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1491:
#line 7318 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1492:
#line 7319 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1493:
#line 7324 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1494:
#line 7327 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1495:
#line 7331 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1496:
#line 7337 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1497:
#line 7338 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1498:
#line 7339 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1499:
#line 7340 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1504:
#line 7360 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7365 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1508:
#line 7369 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7374 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 7377 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7380 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1520:
#line 7385 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1521:
#line 7387 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7390 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1523:
#line 7391 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1524:
#line 7398 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 7403 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1532:
#line 7419 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1533:
#line 7426 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1534:
#line 7430 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1535:
#line 7431 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1537:
#line 7450 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1538:
#line 7451 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1539:
#line 7452 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1540:
#line 7456 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1541:
#line 7459 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1542:
#line 7465 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1543:
#line 7470 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1544:
#line 7475 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1546:
#line 7486 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1551:
#line 7501 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1552:
#line 7504 "fgl.yacc"
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

  case 1553:
#line 7517 "fgl.yacc"
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

  case 1554:
#line 7532 "fgl.yacc"
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

  case 1555:
#line 7544 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1556:
#line 7546 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1557:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1558:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1559:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1560:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1561:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1562:
#line 7549 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1563:
#line 7550 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1564:
#line 7553 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1565:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1566:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1567:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1568:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1569:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1570:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1571:
#line 7560 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1572:
#line 7563 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1587:
#line 7570 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1588:
#line 7573 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1589:
#line 7574 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1590:
#line 7575 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1591:
#line 7579 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1592:
#line 7587 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1593:
#line 7587 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1594:
#line 7593 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1595:
#line 7593 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1596:
#line 7600 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1597:
#line 7600 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1598:
#line 7606 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1599:
#line 7606 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1600:
#line 7614 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1601:
#line 7615 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1602:
#line 7616 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1603:
#line 7619 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1604:
#line 7619 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1606:
#line 7623 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7624 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1608:
#line 7635 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1609:
#line 7638 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1610:
#line 7644 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1611:
#line 7649 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7657 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1613:
#line 7669 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1614:
#line 7670 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1615:
#line 7673 "fgl.yacc"
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

  case 1616:
#line 7688 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1617:
#line 7699 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1618:
#line 7702 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1619:
#line 7710 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1620:
#line 7719 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1621:
#line 7722 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1622:
#line 7726 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1623:
#line 7729 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1624:
#line 7730 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1626:
#line 7739 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1627:
#line 7740 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1628:
#line 7749 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1629:
#line 7758 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1630:
#line 7763 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1631:
#line 7764 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1632:
#line 7765 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1633:
#line 7766 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1634:
#line 7773 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1635:
#line 7776 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1636:
#line 7782 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1637:
#line 7785 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1638:
#line 7795 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1639:
#line 7804 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1640:
#line 7807 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1641:
#line 7810 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1642:
#line 7816 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1643:
#line 7822 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1644:
#line 7825 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1645:
#line 7828 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1646:
#line 7831 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1647:
#line 7838 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1648:
#line 7840 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1649:
#line 7842 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1650:
#line 7844 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1651:
#line 7846 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1652:
#line 7847 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1653:
#line 7848 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1654:
#line 7849 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1655:
#line 7850 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1656:
#line 7851 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1657:
#line 7852 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1658:
#line 7854 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1659:
#line 7856 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1660:
#line 7858 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7860 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1662:
#line 7862 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1663:
#line 7864 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1664:
#line 7866 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1665:
#line 7867 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1666:
#line 7869 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1667:
#line 7873 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1668:
#line 7874 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1670:
#line 7884 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1671:
#line 7893 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1672:
#line 7897 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1673:
#line 7904 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1674:
#line 7904 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1676:
#line 7908 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1677:
#line 7913 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1678:
#line 7913 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1680:
#line 7917 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1681:
#line 7921 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1684:
#line 7930 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1685:
#line 7930 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1690:
#line 7949 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1691:
#line 7950 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1694:
#line 7958 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1695:
#line 7964 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1698:
#line 7983 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1699:
#line 7984 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1700:
#line 7985 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1701:
#line 7986 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1702:
#line 7987 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1703:
#line 7988 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1704:
#line 7992 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1705:
#line 7993 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1706:
#line 7994 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1707:
#line 7998 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1708:
#line 8002 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1710:
#line 8011 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1712:
#line 8016 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1713:
#line 8017 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2031:
#line 8342 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2032:
#line 8342 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2033:
#line 8349 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2034:
#line 8349 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2035:
#line 8437 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2036:
#line 8441 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2037:
#line 8443 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2038:
#line 8450 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2039:
#line 8454 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2040:
#line 8460 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2041:
#line 8468 "fgl.yacc"
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

  case 2042:
#line 8478 "fgl.yacc"
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

  case 2043:
#line 8488 "fgl.yacc"
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

  case 2044:
#line 8500 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2045:
#line 8503 "fgl.yacc"
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

  case 2046:
#line 8522 "fgl.yacc"
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

  case 2047:
#line 8548 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2048:
#line 8551 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2050:
#line 8560 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2051:
#line 8565 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2052:
#line 8568 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2053:
#line 8576 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2054:
#line 8584 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2055:
#line 8597 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2056:
#line 8600 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2057:
#line 8608 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2058:
#line 8611 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2059:
#line 8614 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2060:
#line 8622 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2061:
#line 8626 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2062:
#line 8629 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2063:
#line 8632 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2064:
#line 8635 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2065:
#line 8639 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2066:
#line 8640 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2067:
#line 8641 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2068:
#line 8642 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2069:
#line 8643 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2070:
#line 8649 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2071:
#line 8650 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2072:
#line 8651 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2073:
#line 8652 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2074:
#line 8653 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2075:
#line 8654 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2076:
#line 8655 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2077:
#line 8656 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2078:
#line 8657 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2079:
#line 8658 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8659 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8660 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8661 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2083:
#line 8662 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2084:
#line 8666 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2085:
#line 8672 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2086:
#line 8673 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2087:
#line 8681 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2088:
#line 8683 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2090:
#line 8689 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2091:
#line 8693 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2092:
#line 8697 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2093:
#line 8713 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		char c;
		char buff[1024];
			sprintf(buff,"%s",fgl_add_scope(yyvsp[0].str,0));

		print_push_variable(buff);

		strcpy(yyval.str,"?");

	} else {
		strcpy(yyval.str,yyvsp[0].str);
	}

}
    break;

  case 2094:
#line 8733 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2098:
#line 8739 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2099:
#line 8740 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2103:
#line 8758 "fgl.yacc"
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

  case 2104:
#line 8784 "fgl.yacc"
    {
char r1[256];
//char r2[256];
char buff[256];
char was_str[40000];
//char *ptr1;
//char *ptr2;
//int aa;
int z = 0,a = 0;
struct variable *v_r;
struct variable *v_1;
struct variable *v_2;
struct variable *v_loop;
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

  case 2105:
#line 8857 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2106:
#line 8860 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2107:
#line 8864 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2110:
#line 8883 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2111:
#line 8884 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2112:
#line 8887 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2113:
#line 8888 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2114:
#line 8889 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2115:
#line 8890 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2116:
#line 8891 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2117:
#line 8892 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2118:
#line 8893 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2119:
#line 8898 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2120:
#line 8899 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2121:
#line 8903 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2122:
#line 8907 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2123:
#line 8911 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2124:
#line 8915 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2125:
#line 8920 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2126:
#line 8924 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2127:
#line 8929 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2129:
#line 8937 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2131:
#line 8943 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2132:
#line 8949 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2133:
#line 8953 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2138:
#line 8971 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2139:
#line 8978 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2140:
#line 8987 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2141:
#line 8987 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18162 "y.tab.c"

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


#line 9085 "fgl.yacc"

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



