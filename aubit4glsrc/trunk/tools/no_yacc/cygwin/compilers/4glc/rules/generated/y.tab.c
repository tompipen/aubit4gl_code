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
     NAME = 1697,
     UMINUS = 1698,
     COMMA = 1604,
     KW_OR = 1644,
     KW_AND = 1599,
     KW_USING = 1536,
     NOT = 1619,
     MATCHES = 1415,
     POWER = 1522,
     LESS_THAN = 1518,
     GREATER_THAN = 1433,
     EQUAL = 1594,
     GREATER_THAN_EQ = 1333,
     LESS_THAN_EQ = 1390,
     NOT_EQUAL = 1464,
     PLUS = 1630,
     MINUS = 1617,
     MULTIPLY = 1523,
     DIVIDE = 1550,
     MOD = 1618,
     COMMAND = 1397,
     NUMBER_VALUE = 1699,
     CHAR_VALUE = 1700,
     INT_VALUE = 1701,
     NAMED_GEN = 1702,
     CLINE = 1703,
     SQLLINE = 1704,
     KW_CSTART = 1705,
     KW_CEND = 1706,
     USER_DTYPE = 1707,
     SQL_TEXT = 1708,
     KW_WHENEVER_SET = 1709,
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
     ALTER_INDEX = 1017,
     WHENEVER_ERROR_CONTINUE = 1018,
     WHENEVER_ANY_ERROR_CONTINUE = 1019,
     WHENEVER_WARNING_CONTINUE = 1020,
     WHENEVER_SQLSUCCESS_CONTINUE = 1021,
     WHENEVER_SQLWARNING_CONTINUE = 1022,
     WHENEVER_NOT_FOUND_CONTINUE = 1023,
     WHENEVER_SQLERROR_CONTINUE = 1024,
     WHENEVER_SUCCESS_CONTINUE = 1025,
     WHENEVER_ERROR_GOTO = 1026,
     WHENEVER_ANY_ERROR_GOTO = 1027,
     WHENEVER_WARNING_GOTO = 1028,
     WHENEVER_SQLSUCCESS_GOTO = 1029,
     WHENEVER_SQLWARNING_GOTO = 1030,
     WHENEVER_NOT_FOUND_GOTO = 1031,
     WHENEVER_SQLERROR_GOTO = 1032,
     WHENEVER_SUCCESS_GOTO = 1033,
     WHENEVER_ERROR_CALL = 1034,
     WHENEVER_ANY_ERROR_CALL = 1035,
     WHENEVER_WARNING_CALL = 1036,
     WHENEVER_SQLSUCCESS_CALL = 1037,
     WHENEVER_SQLWARNING_CALL = 1038,
     WHENEVER_NOT_FOUND_CALL = 1039,
     WHENEVER_SQLERROR_CALL = 1040,
     WHENEVER_SUCCESS_CALL = 1041,
     WHENEVER_ERROR_STOP = 1042,
     WHENEVER_ANY_ERROR_STOP = 1043,
     WHENEVER_WARNING_STOP = 1044,
     WHENEVER_SQLSUCCESS_STOP = 1045,
     WHENEVER_SQLWARNING_STOP = 1046,
     WHENEVER_NOT_FOUND_STOP = 1047,
     WHENEVER_SQLERROR_STOP = 1048,
     WHENEVER_SUCCESS_STOP = 1049,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1050,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1051,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1052,
     XSET_MULTIPLY_EQUAL = 1053,
     XSET_OPEN_BRACKET = 1054,
     NEWFORMATSHARED = 1055,
     CREATE_DATABASE = 1056,
     IMPORT_LEGACY_FUNCTION = 1057,
     ADD_CONSTRAINT = 1058,
     DROP_CONSTRAINT = 1059,
     AS_STATIC = 1060,
     NOT_FIELD_TOUCHED = 1061,
     LOCAL_FUNCTION = 1062,
     EVERY_ROW = 1063,
     ELIF = 1064,
     DOUBLE_PRECISION = 1065,
     COUNT_MULTIPLY = 1066,
     WAIT_FOR_KEY = 1067,
     AT_TERMINATION_CALL = 1068,
     TERMINATE_REPORT = 1069,
     TO_MAIN_CAPTION = 1070,
     CLEARSTAT = 1071,
     TO_MENUITEM = 1072,
     ID_TO_INT = 1073,
     TO_STATUSBOX = 1074,
     ASCII_HEIGHT_ALL = 1075,
     ASCII_WIDTH_ALL = 1076,
     IMPORT_DATATYPE = 1077,
     PAGE_TRAILER_SIZE = 1078,
     PAGE_HEADER_SIZE = 1079,
     FIRST_PAGE_HEADER_SIZE = 1080,
     BYTES_USE_AS_IMAGE = 1081,
     BYTES_USE_AS_ASCII = 1082,
     KWUP_BY = 1083,
     KWDOWN_BY = 1084,
     CLOSE_STATUSBOX = 1085,
     MODIFY_NEXT_SIZE = 1086,
     LOCK_MODE_PAGE = 1087,
     LOCK_MODE_ROW = 1088,
     TO_PIPE = 1089,
     TO_PRINTER = 1090,
     STATUSBOX = 1091,
     CONNECT_TO = 1092,
     FORMHANDLER_INPUT = 1093,
     UNITS_YEAR = 1094,
     UNITS_MONTH = 1095,
     UNITS_DAY = 1096,
     UNITS_HOUR = 1097,
     UNITS_MINUTE = 1098,
     UNITS_SECOND = 1099,
     NO_NEW_LINES = 1100,
     FIELDTOWIDGET = 1101,
     WITH_HOLD = 1102,
     SHOW_MENU = 1103,
     TO_CLUSTER = 1104,
     TO_NOT_CLUSTER = 1105,
     CWIS = 1106,
     CREATE_IDX = 1107,
     FORM_IS_COMPILED = 1108,
     PDF_REPORT = 1109,
     IMPORT_FUNCTION = 1110,
     PROMPT_MANY = 1111,
     POINTS = 1112,
     MM = 1113,
     INCHES = 1114,
     PREPEND = 1115,
     MEMBER_OF = 1116,
     MEMBER_FUNCTION = 1117,
     APPEND = 1118,
     TEMPLATE = 1119,
     END_TEMPLATE = 1120,
     SQLSICS = 1121,
     CREATE_SCHEMA = 1122,
     SQLSIRR = 1123,
     UPDATESTATS_T = 1124,
     SQLSICR = 1125,
     WHENEVER_SQLSUCCESS = 1126,
     WHENEVER_SQLWARNING = 1127,
     WHENEVER_ANY_ERROR = 1128,
     WHENEVER_NOT_FOUND = 1129,
     WHENEVER_SQLERROR = 1130,
     WHENEVER_SUCCESS = 1131,
     WHENEVER_ERROR = 1132,
     START_EXTERN = 1133,
     CONTINUE_CONSTRUCT = 1134,
     FOUNCONSTR = 1135,
     SQLSIDR = 1136,
     CREATE_TEMP_TABLE = 1137,
     CURRENT_WINDOW_IS = 1138,
     FIRST_PAGE_HEADER = 1139,
     ORDER_EXTERNAL_BY = 1140,
     SCROLL_CURSOR_FOR = 1141,
     SCROLL_CURSOR = 1142,
     SQL_INTERRUPT_OFF = 1143,
     STOP_ALL_EXTERNAL = 1144,
     WITH_CHECK_OPTION = 1145,
     WITH_GRANT_OPTION = 1146,
     SQLSLMNW = 1147,
     ADDCONSTUNIQ = 1148,
     CONTINUE_DISPLAY = 1149,
     CONTINUE_FOREACH = 1150,
     OUTPUT_TO_REPORT = 1151,
     SQL_INTERRUPT_ON = 1152,
     WHERE_CURRENT_OF = 1153,
     WITHOUT_DEFAULTS = 1154,
     FOCONSTR = 1155,
     SCALED_BY = 1156,
     CONTINUE_PROMPT = 1157,
     PDF_FUNCTION = 1158,
     DEFER_INTERRUPT = 1159,
     DISPLAY_BY_NAME = 1160,
     NOT_NULL_UNIQUE = 1161,
     SKIP_TO_TOP = 1162,
     TOP_OF_PAGE = 1163,
     SKIP_TO = 1164,
     SKIP_BY = 1165,
     WITHOUT_WAITING = 1166,
     BEFCONSTRUCT = 1167,
     SQLSLMW = 1168,
     AFTCONSTRUCT = 1169,
     ALL_PRIVILEGES = 1170,
     CLOSE_DATABASE = 1171,
     CONTINUE_INPUT = 1172,
     CONTINUE_WHILE = 1173,
     CREATE_SYNONYM = 1174,
     DROP_TABLE = 1175,
     EXIT_CONSTRUCT = 1176,
     INEXCLUSIVE = 1177,
     REPORT_TO_PRINTER = 1178,
     REPORT_TO_PIPE = 1179,
     RETURN = 1180,
     SET_SESSION_TO = 1181,
     UPDATESTATS = 1182,
     WITHOUT_HEAD = 1183,
     CLEARSCR = 1184,
     WITH_B_LOG = 1185,
     AUTHORIZATION = 1186,
     BOTTOM_MARGIN = 1187,
     CLOSE_SESSION = 1188,
     CONTINUE_CASE = 1189,
     CONTINUE_MENU = 1190,
     DISPLAY_ARRAY = 1191,
     END_SQL = 1192,
     DOLLAR = 1193,
     END_CONSTRUCT = 1194,
     FIELD_TOUCHED = 1195,
     FINISH_REPORT = 1196,
     INFACC = 1197,
     INPUT_NO_WRAP = 1198,
     LOCKMODEPAGE = 1199,
     SETPMOFF = 1200,
     UNCONSTRAINED = 1201,
     PAGE_TRAILER = 1202,
     SETPMON = 1203,
     BEFGROUP = 1204,
     CLOSE_WINDOW = 1205,
     COMMENT_LINE = 1206,
     CONTINUE_FOR = 1207,
     CREATE_DB = 1208,
     CREATE_TABLE = 1209,
     DEFAULT_NULL = 1210,
     DELETE_USING = 1211,
     DISPLAY_FORM = 1212,
     END_FUNCTION = 1213,
     EXIT_DISPLAY = 1214,
     EXIT_FOREACH = 1215,
     EXIT_PROGRAM = 1216,
     INFCOLS = 1217,
     LOCKMODEROW = 1218,
     ON_EVERY_ROW = 1219,
     OPEN_SESSION = 1220,
     RIGHT_MARGIN = 1221,
     SELECT_USING = 1222,
     START_REPORT = 1223,
     UNLOCK_TABLE = 1224,
     UPDATE_USING = 1225,
     ACL_BUILTIN = 1226,
     AFTGROUP = 1227,
     INFIDX = 1228,
     INFSTAT = 1229,
     LEFT_MARGIN = 1230,
     PAGE_HEADER = 1231,
     ROLLBACK_W = 1232,
     SET_SESSION = 1233,
     SQLSEOFF = 1234,
     WITH_A_LOG = 1235,
     BEFDISP = 1236,
     BEFORE_MENU = 1237,
     CREATE_VIEW = 1238,
     DEFINE_TYPE = 1239,
     DELETE_FROM = 1240,
     END_DISPLAY = 1241,
     END_REPORT = 1242,
     END_FOREACH = 1243,
     END_FOR = 1244,
     END_GLOBALS = 1245,
     EXIT_PROMPT = 1246,
     EXTENT_SIZE = 1247,
     FOREIGN_KEY = 1248,
     HIDE_OPTION = 1249,
     HIDE_WINDOW = 1250,
     INSERT_INTO = 1251,
     IS_NOT_NULL = 1252,
     MOVE_WINDOW = 1253,
     NEXT_OPTION = 1254,
     NOT_MATCHES = 1255,
     ON_LAST_ROW = 1256,
     OPEN_WINDOW = 1257,
     OPEN_STATUSBOX = 1258,
     PAGE_LENGTH = 1259,
     PAGE_WIDTH = 1260,
     PRIMARY_KEY = 1261,
     PROMPT_LINE = 1262,
     RECORD_LIKE = 1263,
     ROLLFORWARD = 1264,
     SETBL = 1265,
     SHOW_OPTION = 1266,
     SHOW_WINDOW = 1267,
     SQLSEON = 1268,
     TO_DATABASE = 1269,
     USE_SESSION = 1270,
     WITH_NO_LOG = 1271,
     AFTDISP = 1272,
     BEFFIELD = 1273,
     INSHARE = 1274,
     UNLOCKTAB = 1275,
     AFTFIELD = 1276,
     ATTRIBUTES = 1277,
     BEFINP = 1278,
     BEGIN_WORK = 1279,
     CLEARWIN = 1280,
     CLOSE_FORM = 1281,
     DEFER_QUIT = 1282,
     DESCENDING = 1283,
     DROP_INDEX = 1284,
     END_PROMPT = 1285,
     END_RECORD = 1286,
     ERROR_LINE = 1287,
     EXIT_INPUT = 1288,
     EXIT_WHILE = 1289,
     FOR_UPDATE_OF = 1290,
     FOR_UPDATE = 1291,
     GET_FLDBUF = 1292,
     INITIALIZE = 1293,
     INPUT_WRAP = 1294,
     LOCK_TABLE = 1295,
     MSG_LINE = 1296,
     NOT_EXISTS = 1297,
     ON_ANY_KEY = 1298,
     REFERENCES = 1299,
     RENCOL = 1300,
     SET_CURSOR = 1301,
     SMALLFLOAT = 1302,
     SQLSUCCESS = 1303,
     TOP_MARGIN = 1304,
     WITH_ARRAY = 1305,
     ACCEPTKEY = 1306,
     ACCEPT = 1307,
     AFTINP = 1308,
     CLEARFORMTODEFAULTS = 1309,
     CLEARFORM = 1310,
     CLEAR_X_FORM = 1311,
     COMMIT_W = 1312,
     NEXTPAGE = 1313,
     PREVPAGE = 1314,
     CTRL_KEY = 1315,
     INFTABS = 1316,
     NEXTFIELD = 1317,
     NEXTFORM = 1318,
     RENTAB = 1319,
     ASCENDING = 1320,
     ASSOCIATE = 1321,
     CHAR = 1322,
     CONSTRUCT = 1323,
     DELIMITER = 1324,
     DOWNSHIFT = 1325,
     DROP_VIEW = 1326,
     END_INPUT = 1327,
     END_WHILE = 1328,
     EXCLUSIVE = 1329,
     EXIT_CASE = 1330,
     EXIT_MENU = 1331,
     FORM_LINE = 1332,
     INTERRUPT = 1334,
     INTO_TEMP = 1335,
     INVISIBLE = 1336,
     IN_MEMORY = 1337,
     LINKED_TO = 1338,
     LOAD_FROM = 1339,
     LOCKTAB = 1340,
     MENU_LINE = 1341,
     OPEN_FORM = 1342,
     OTHERWISE = 1343,
     PRECISION = 1344,
     PRIOR = 1345,
     PROCEDURE = 1346,
     REPORT_TO = 1347,
     RETURNING = 1348,
     UNDERLINE = 1349,
     UNLOAD_TO = 1350,
     BEFROW = 1351,
     UNLOAD_T = 1352,
     VARIABLE = 1353,
     ABSOLUTE = 1354,
     AFTROW = 1355,
     BUFFERED = 1356,
     CONSTANT = 1357,
     CONST = 1358,
     DATABASE = 1359,
     DATETIME = 1360,
     DEFAULTS = 1361,
     DISTINCT = 1362,
     END_CASE = 1363,
     END_MAIN = 1364,
     END_MENU = 1365,
     END_TYPE = 1366,
     EXIT_FOR = 1367,
     EXTERNAL = 1368,
     FRACTION = 1369,
     FUNCTION = 1370,
     GROUP_BY = 1371,
     INTERVAL = 1372,
     KWMESSAGE = 1373,
     NOT_LIKE = 1374,
     NOT_ILIKE = 1375,
     NOT_NULL = 1376,
     PASSWORD = 1377,
     PREVIOUS = 1378,
     READONLY = 1379,
     REGISTER = 1380,
     RELATIVE = 1381,
     RESOURCE = 1382,
     SMALLINT = 1383,
     VALIDATE = 1384,
     WITH_LOG = 1385,
     WORDWRAP = 1386,
     BY_NAME = 1387,
     IN_FILE = 1388,
     IS_NULL = 1389,
     AVERAGE = 1391,
     BETWEEN = 1392,
     CAPTION = 1393,
     CLIPPED = 1394,
     CLOSE_BRACKET = 1395,
     COLUMNS = 1396,
     COMMENT = 1398,
     CONNECT = 1399,
     CURRENT = 1400,
     DBYNAME = 1401,
     DECIMAL = 1402,
     DECLARE = 1403,
     DEFAULT = 1404,
     DISPLAY = 1405,
     ENDCODE = 1406,
     EXECUTE = 1407,
     FOREACH = 1408,
     FOREIGN = 1409,
     GLOBALS = 1410,
     INFIELD = 1411,
     INTEGER = 1412,
     KWWINDOW = 1413,
     MAGENTA = 1414,
     NUMERIC = 1416,
     OPTIONS = 1417,
     PERCENT = 1418,
     PREPARE = 1419,
     PROGRAM = 1420,
     RECOVER = 1421,
     REVERSE = 1422,
     SECTION = 1423,
     SESSION = 1424,
     SYNONYM = 1425,
     THRU = 1426,
     TRAILER = 1427,
     UPSHIFT = 1428,
     VARCHAR = 1429,
     WAITING = 1430,
     CLOSE_SHEV = 1431,
     CLOSE_SQUARE = 1432,
     KW_FALSE = 1434,
     NOT_IN = 1435,
     ONKEY = 1436,
     OPEN_BRACKET = 1437,
     BORDER = 1438,
     BOTTOM = 1439,
     COLUMN = 1440,
     COMMIT = 1441,
     CREATE = 1442,
     CURSOR = 1443,
     DEFINE = 1444,
     DELETE = 1445,
     DOUBLE = 1446,
     END_IF = 1447,
     ESCAPE = 1448,
     EXISTS = 1449,
     EXTEND = 1450,
     EXTENT = 1451,
     FINISH = 1452,
     FORMAT = 1453,
     HAVING = 1454,
     HEADER = 1455,
     INSERT = 1456,
     LOCATE = 1457,
     MARGIN = 1458,
     MEMORY = 1459,
     MINUTE = 1460,
     MODIFY = 1461,
     NORMAL = 1462,
     EQUAL_EQUAL = 1463,
     OPEN_SHEV = 1465,
     OPEN_SQUARE = 1466,
     OPTION = 1467,
     OUTPUT = 1468,
     PROMPT = 1469,
     PUBLIC = 1470,
     RECORD = 1471,
     REPORT = 1472,
     REVOKE = 1473,
     SCHEMA = 1474,
     SCROLL_USING = 1475,
     SCROLL = 1476,
     SECOND = 1477,
     SELECT = 1478,
     SERIAL = 1479,
     SETL = 1480,
     SHARED = 1481,
     SPACES = 1482,
     UNIQUE = 1483,
     UNLOCK = 1484,
     UPDATE = 1485,
     VALUES = 1486,
     YELLOW = 1487,
     AFTER = 1488,
     KWLINE = 1489,
     KW_NULL = 1490,
     KW_TRUE = 1491,
     SINGLE_KEY = 1492,
     ALTER = 1493,
     ARRAY = 1494,
     ASCII = 1495,
     AUDIT = 1496,
     BLACK = 1497,
     BLINK = 1498,
     CHECK = 1499,
     CLEAR = 1500,
     CLOSE = 1501,
     CODE_C = 1502,
     COUNT = 1503,
     DEFER = 1504,
     ERROR = 1505,
     EVERY = 1506,
     FETCH = 1507,
     FIRST = 1508,
     FLOAT = 1509,
     FLUSH = 1510,
     FOUND = 1511,
     GRANT = 1512,
     GREEN = 1513,
     GROUP = 1514,
     INDEX = 1515,
     KWFORM = 1516,
     LABEL = 1517,
     LOCAL = 1519,
     MONEY = 1520,
     MONTH = 1521,
     ORDER = 1524,
     OUTER = 1525,
     PAUSE = 1526,
     PRINT_IMAGE = 1527,
     PRINT_FILE = 1528,
     PRINT = 1529,
     RIGHT = 1530,
     DOUBLE_COLON = 1531,
     SEMICOLON = 1532,
     SLEEP = 1533,
     TUPLE = 1534,
     UNION = 1535,
     WHERE = 1537,
     WHILE = 1538,
     WHITE = 1539,
     CCODE = 1540,
     ANSI = 1541,
     BLUE = 1542,
     BOLD = 1543,
     BYTE = 1544,
     FCALL = 1545,
     CASE = 1546,
     CYAN = 1547,
     DATE = 1548,
     DESC = 1549,
     KWDOWN = 1551,
     TAB = 1552,
     DROP = 1553,
     ELSE = 1554,
     EXEC = 1555,
     EXIT = 1556,
     FREE = 1557,
     FROM = 1558,
     GOTO = 1559,
     HELP_FILE = 1560,
     LANG_FILE = 1561,
     HELP = 1562,
     HIDE = 1563,
     HOUR = 1564,
     INTO = 1565,
     LAST = 1566,
     LEFT = 1567,
     LIKE = 1568,
     MAIN = 1569,
     MENU = 1570,
     MODE = 1571,
     NEED = 1572,
     NEXT = 1573,
     NOCR = 1574,
     OPEN = 1575,
     QUIT = 1576,
     REAL = 1577,
     ROWS = 1578,
     SHOW = 1579,
     SIZE = 1580,
     SKIP = 1581,
     SOME = 1582,
     STEP = 1583,
     STOP = 1584,
     TEMP = 1585,
     TEXT = 1586,
     THEN = 1587,
     USER = 1588,
     WAIT = 1589,
     WHEN = 1590,
     WITH = 1591,
     WORK = 1592,
     YEAR = 1593,
     KW_IS = 1595,
     XSET = 1596,
     ADD = 1597,
     ALL = 1598,
     ANY = 1600,
     ASC = 1601,
     AVG = 1602,
     COLON = 1603,
     DAY = 1605,
     DBA = 1606,
     DEC = 1607,
     DIM = 1608,
     FKEY = 1609,
     FOR = 1610,
     KEY = 1611,
     KWNO = 1612,
     LET = 1613,
     LOG = 1614,
     XMAX = 1615,
     XMIN = 1616,
     PAD = 1620,
     PUT = 1621,
     RED = 1622,
     ROW = 1623,
     RUN = 1624,
     SQL = 1625,
     SUM = 1626,
     TOP = 1627,
     USE = 1628,
     ATSIGN = 1629,
     AS_TIFF = 1631,
     AS_GIF = 1632,
     AS_PNG = 1633,
     AS_JPEG = 1634,
     AS = 1635,
     AT = 1636,
     BY = 1637,
     DOT = 1638,
     GO = 1639,
     IF = 1640,
     IN = 1641,
     OF = 1642,
     ON = 1643,
     TO = 1645,
     KWUP = 1646,
     FONT_NAME = 1647,
     FONT_SIZE = 1648,
     PAPER_SIZE_IS_LETTER = 1649,
     PAPER_SIZE_IS_LEGAL = 1650,
     PAPER_SIZE_IS_A5 = 1651,
     PAPER_SIZE_IS_A4 = 1652,
     PAPER_SIZE_IS_LETTER_L = 1653,
     PAPER_SIZE_IS_LEGAL_L = 1654,
     PAPER_SIZE_IS_A5_L = 1655,
     PAPER_SIZE_IS_A4_L = 1656,
     FORMHANDLER = 1657,
     END_FORMHANDLER = 1658,
     BEFORE_EVENT = 1659,
     BEFORE_OPEN_FORM = 1660,
     AFTER_EVENT = 1661,
     BEFORE_CLOSE_FORM = 1662,
     BEFORE_ANY = 1663,
     AFTER_ANY = 1664,
     MENUHANDLER = 1665,
     END_MENUHANDLER = 1666,
     BEFORE_SHOW_MENU = 1667,
     DISABLE_PROGRAM = 1668,
     DISABLE_ALL = 1669,
     BUTTONS = 1670,
     CHECK_MENUITEM = 1671,
     DISABLE_FORM = 1672,
     DISABLE_MENUITEMS = 1673,
     DISABLE = 1674,
     ENABLE_FORM = 1675,
     ENABLE_MENUITEMS = 1676,
     ENABLE = 1677,
     KWFIELD = 1678,
     ICON = 1679,
     MESSAGEBOX = 1680,
     TO_DEFAULTS = 1681,
     UNCHECK_MENUITEM = 1682,
     BEFORE = 1683,
     INPUT = 1684,
     END = 1685,
     INT_TO_ID = 1686,
     TIMEOUT = 1687,
     OFF = 1688,
     WITH_1_DIMENSION = 1689,
     WITH_2_DIMENSION = 1690,
     WITH_3_DIMENSION = 1691,
     TILDE = 1692,
     ILIKE = 1693,
     FGL_ISDYNARR_ALLOCATED = 1694,
     FGL_DYNARR_EXTENTSIZE = 1695
   };
#endif
#define NAME 1697
#define UMINUS 1698
#define COMMA 1604
#define KW_OR 1644
#define KW_AND 1599
#define KW_USING 1536
#define NOT 1619
#define MATCHES 1415
#define POWER 1522
#define LESS_THAN 1518
#define GREATER_THAN 1433
#define EQUAL 1594
#define GREATER_THAN_EQ 1333
#define LESS_THAN_EQ 1390
#define NOT_EQUAL 1464
#define PLUS 1630
#define MINUS 1617
#define MULTIPLY 1523
#define DIVIDE 1550
#define MOD 1618
#define COMMAND 1397
#define NUMBER_VALUE 1699
#define CHAR_VALUE 1700
#define INT_VALUE 1701
#define NAMED_GEN 1702
#define CLINE 1703
#define SQLLINE 1704
#define KW_CSTART 1705
#define KW_CEND 1706
#define USER_DTYPE 1707
#define SQL_TEXT 1708
#define KW_WHENEVER_SET 1709
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
#define ALTER_INDEX 1017
#define WHENEVER_ERROR_CONTINUE 1018
#define WHENEVER_ANY_ERROR_CONTINUE 1019
#define WHENEVER_WARNING_CONTINUE 1020
#define WHENEVER_SQLSUCCESS_CONTINUE 1021
#define WHENEVER_SQLWARNING_CONTINUE 1022
#define WHENEVER_NOT_FOUND_CONTINUE 1023
#define WHENEVER_SQLERROR_CONTINUE 1024
#define WHENEVER_SUCCESS_CONTINUE 1025
#define WHENEVER_ERROR_GOTO 1026
#define WHENEVER_ANY_ERROR_GOTO 1027
#define WHENEVER_WARNING_GOTO 1028
#define WHENEVER_SQLSUCCESS_GOTO 1029
#define WHENEVER_SQLWARNING_GOTO 1030
#define WHENEVER_NOT_FOUND_GOTO 1031
#define WHENEVER_SQLERROR_GOTO 1032
#define WHENEVER_SUCCESS_GOTO 1033
#define WHENEVER_ERROR_CALL 1034
#define WHENEVER_ANY_ERROR_CALL 1035
#define WHENEVER_WARNING_CALL 1036
#define WHENEVER_SQLSUCCESS_CALL 1037
#define WHENEVER_SQLWARNING_CALL 1038
#define WHENEVER_NOT_FOUND_CALL 1039
#define WHENEVER_SQLERROR_CALL 1040
#define WHENEVER_SUCCESS_CALL 1041
#define WHENEVER_ERROR_STOP 1042
#define WHENEVER_ANY_ERROR_STOP 1043
#define WHENEVER_WARNING_STOP 1044
#define WHENEVER_SQLSUCCESS_STOP 1045
#define WHENEVER_SQLWARNING_STOP 1046
#define WHENEVER_NOT_FOUND_STOP 1047
#define WHENEVER_SQLERROR_STOP 1048
#define WHENEVER_SUCCESS_STOP 1049
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1050
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1051
#define XSET_ident_DOT_MULTIPLY_EQUAL 1052
#define XSET_MULTIPLY_EQUAL 1053
#define XSET_OPEN_BRACKET 1054
#define NEWFORMATSHARED 1055
#define CREATE_DATABASE 1056
#define IMPORT_LEGACY_FUNCTION 1057
#define ADD_CONSTRAINT 1058
#define DROP_CONSTRAINT 1059
#define AS_STATIC 1060
#define NOT_FIELD_TOUCHED 1061
#define LOCAL_FUNCTION 1062
#define EVERY_ROW 1063
#define ELIF 1064
#define DOUBLE_PRECISION 1065
#define COUNT_MULTIPLY 1066
#define WAIT_FOR_KEY 1067
#define AT_TERMINATION_CALL 1068
#define TERMINATE_REPORT 1069
#define TO_MAIN_CAPTION 1070
#define CLEARSTAT 1071
#define TO_MENUITEM 1072
#define ID_TO_INT 1073
#define TO_STATUSBOX 1074
#define ASCII_HEIGHT_ALL 1075
#define ASCII_WIDTH_ALL 1076
#define IMPORT_DATATYPE 1077
#define PAGE_TRAILER_SIZE 1078
#define PAGE_HEADER_SIZE 1079
#define FIRST_PAGE_HEADER_SIZE 1080
#define BYTES_USE_AS_IMAGE 1081
#define BYTES_USE_AS_ASCII 1082
#define KWUP_BY 1083
#define KWDOWN_BY 1084
#define CLOSE_STATUSBOX 1085
#define MODIFY_NEXT_SIZE 1086
#define LOCK_MODE_PAGE 1087
#define LOCK_MODE_ROW 1088
#define TO_PIPE 1089
#define TO_PRINTER 1090
#define STATUSBOX 1091
#define CONNECT_TO 1092
#define FORMHANDLER_INPUT 1093
#define UNITS_YEAR 1094
#define UNITS_MONTH 1095
#define UNITS_DAY 1096
#define UNITS_HOUR 1097
#define UNITS_MINUTE 1098
#define UNITS_SECOND 1099
#define NO_NEW_LINES 1100
#define FIELDTOWIDGET 1101
#define WITH_HOLD 1102
#define SHOW_MENU 1103
#define TO_CLUSTER 1104
#define TO_NOT_CLUSTER 1105
#define CWIS 1106
#define CREATE_IDX 1107
#define FORM_IS_COMPILED 1108
#define PDF_REPORT 1109
#define IMPORT_FUNCTION 1110
#define PROMPT_MANY 1111
#define POINTS 1112
#define MM 1113
#define INCHES 1114
#define PREPEND 1115
#define MEMBER_OF 1116
#define MEMBER_FUNCTION 1117
#define APPEND 1118
#define TEMPLATE 1119
#define END_TEMPLATE 1120
#define SQLSICS 1121
#define CREATE_SCHEMA 1122
#define SQLSIRR 1123
#define UPDATESTATS_T 1124
#define SQLSICR 1125
#define WHENEVER_SQLSUCCESS 1126
#define WHENEVER_SQLWARNING 1127
#define WHENEVER_ANY_ERROR 1128
#define WHENEVER_NOT_FOUND 1129
#define WHENEVER_SQLERROR 1130
#define WHENEVER_SUCCESS 1131
#define WHENEVER_ERROR 1132
#define START_EXTERN 1133
#define CONTINUE_CONSTRUCT 1134
#define FOUNCONSTR 1135
#define SQLSIDR 1136
#define CREATE_TEMP_TABLE 1137
#define CURRENT_WINDOW_IS 1138
#define FIRST_PAGE_HEADER 1139
#define ORDER_EXTERNAL_BY 1140
#define SCROLL_CURSOR_FOR 1141
#define SCROLL_CURSOR 1142
#define SQL_INTERRUPT_OFF 1143
#define STOP_ALL_EXTERNAL 1144
#define WITH_CHECK_OPTION 1145
#define WITH_GRANT_OPTION 1146
#define SQLSLMNW 1147
#define ADDCONSTUNIQ 1148
#define CONTINUE_DISPLAY 1149
#define CONTINUE_FOREACH 1150
#define OUTPUT_TO_REPORT 1151
#define SQL_INTERRUPT_ON 1152
#define WHERE_CURRENT_OF 1153
#define WITHOUT_DEFAULTS 1154
#define FOCONSTR 1155
#define SCALED_BY 1156
#define CONTINUE_PROMPT 1157
#define PDF_FUNCTION 1158
#define DEFER_INTERRUPT 1159
#define DISPLAY_BY_NAME 1160
#define NOT_NULL_UNIQUE 1161
#define SKIP_TO_TOP 1162
#define TOP_OF_PAGE 1163
#define SKIP_TO 1164
#define SKIP_BY 1165
#define WITHOUT_WAITING 1166
#define BEFCONSTRUCT 1167
#define SQLSLMW 1168
#define AFTCONSTRUCT 1169
#define ALL_PRIVILEGES 1170
#define CLOSE_DATABASE 1171
#define CONTINUE_INPUT 1172
#define CONTINUE_WHILE 1173
#define CREATE_SYNONYM 1174
#define DROP_TABLE 1175
#define EXIT_CONSTRUCT 1176
#define INEXCLUSIVE 1177
#define REPORT_TO_PRINTER 1178
#define REPORT_TO_PIPE 1179
#define RETURN 1180
#define SET_SESSION_TO 1181
#define UPDATESTATS 1182
#define WITHOUT_HEAD 1183
#define CLEARSCR 1184
#define WITH_B_LOG 1185
#define AUTHORIZATION 1186
#define BOTTOM_MARGIN 1187
#define CLOSE_SESSION 1188
#define CONTINUE_CASE 1189
#define CONTINUE_MENU 1190
#define DISPLAY_ARRAY 1191
#define END_SQL 1192
#define DOLLAR 1193
#define END_CONSTRUCT 1194
#define FIELD_TOUCHED 1195
#define FINISH_REPORT 1196
#define INFACC 1197
#define INPUT_NO_WRAP 1198
#define LOCKMODEPAGE 1199
#define SETPMOFF 1200
#define UNCONSTRAINED 1201
#define PAGE_TRAILER 1202
#define SETPMON 1203
#define BEFGROUP 1204
#define CLOSE_WINDOW 1205
#define COMMENT_LINE 1206
#define CONTINUE_FOR 1207
#define CREATE_DB 1208
#define CREATE_TABLE 1209
#define DEFAULT_NULL 1210
#define DELETE_USING 1211
#define DISPLAY_FORM 1212
#define END_FUNCTION 1213
#define EXIT_DISPLAY 1214
#define EXIT_FOREACH 1215
#define EXIT_PROGRAM 1216
#define INFCOLS 1217
#define LOCKMODEROW 1218
#define ON_EVERY_ROW 1219
#define OPEN_SESSION 1220
#define RIGHT_MARGIN 1221
#define SELECT_USING 1222
#define START_REPORT 1223
#define UNLOCK_TABLE 1224
#define UPDATE_USING 1225
#define ACL_BUILTIN 1226
#define AFTGROUP 1227
#define INFIDX 1228
#define INFSTAT 1229
#define LEFT_MARGIN 1230
#define PAGE_HEADER 1231
#define ROLLBACK_W 1232
#define SET_SESSION 1233
#define SQLSEOFF 1234
#define WITH_A_LOG 1235
#define BEFDISP 1236
#define BEFORE_MENU 1237
#define CREATE_VIEW 1238
#define DEFINE_TYPE 1239
#define DELETE_FROM 1240
#define END_DISPLAY 1241
#define END_REPORT 1242
#define END_FOREACH 1243
#define END_FOR 1244
#define END_GLOBALS 1245
#define EXIT_PROMPT 1246
#define EXTENT_SIZE 1247
#define FOREIGN_KEY 1248
#define HIDE_OPTION 1249
#define HIDE_WINDOW 1250
#define INSERT_INTO 1251
#define IS_NOT_NULL 1252
#define MOVE_WINDOW 1253
#define NEXT_OPTION 1254
#define NOT_MATCHES 1255
#define ON_LAST_ROW 1256
#define OPEN_WINDOW 1257
#define OPEN_STATUSBOX 1258
#define PAGE_LENGTH 1259
#define PAGE_WIDTH 1260
#define PRIMARY_KEY 1261
#define PROMPT_LINE 1262
#define RECORD_LIKE 1263
#define ROLLFORWARD 1264
#define SETBL 1265
#define SHOW_OPTION 1266
#define SHOW_WINDOW 1267
#define SQLSEON 1268
#define TO_DATABASE 1269
#define USE_SESSION 1270
#define WITH_NO_LOG 1271
#define AFTDISP 1272
#define BEFFIELD 1273
#define INSHARE 1274
#define UNLOCKTAB 1275
#define AFTFIELD 1276
#define ATTRIBUTES 1277
#define BEFINP 1278
#define BEGIN_WORK 1279
#define CLEARWIN 1280
#define CLOSE_FORM 1281
#define DEFER_QUIT 1282
#define DESCENDING 1283
#define DROP_INDEX 1284
#define END_PROMPT 1285
#define END_RECORD 1286
#define ERROR_LINE 1287
#define EXIT_INPUT 1288
#define EXIT_WHILE 1289
#define FOR_UPDATE_OF 1290
#define FOR_UPDATE 1291
#define GET_FLDBUF 1292
#define INITIALIZE 1293
#define INPUT_WRAP 1294
#define LOCK_TABLE 1295
#define MSG_LINE 1296
#define NOT_EXISTS 1297
#define ON_ANY_KEY 1298
#define REFERENCES 1299
#define RENCOL 1300
#define SET_CURSOR 1301
#define SMALLFLOAT 1302
#define SQLSUCCESS 1303
#define TOP_MARGIN 1304
#define WITH_ARRAY 1305
#define ACCEPTKEY 1306
#define ACCEPT 1307
#define AFTINP 1308
#define CLEARFORMTODEFAULTS 1309
#define CLEARFORM 1310
#define CLEAR_X_FORM 1311
#define COMMIT_W 1312
#define NEXTPAGE 1313
#define PREVPAGE 1314
#define CTRL_KEY 1315
#define INFTABS 1316
#define NEXTFIELD 1317
#define NEXTFORM 1318
#define RENTAB 1319
#define ASCENDING 1320
#define ASSOCIATE 1321
#define CHAR 1322
#define CONSTRUCT 1323
#define DELIMITER 1324
#define DOWNSHIFT 1325
#define DROP_VIEW 1326
#define END_INPUT 1327
#define END_WHILE 1328
#define EXCLUSIVE 1329
#define EXIT_CASE 1330
#define EXIT_MENU 1331
#define FORM_LINE 1332
#define INTERRUPT 1334
#define INTO_TEMP 1335
#define INVISIBLE 1336
#define IN_MEMORY 1337
#define LINKED_TO 1338
#define LOAD_FROM 1339
#define LOCKTAB 1340
#define MENU_LINE 1341
#define OPEN_FORM 1342
#define OTHERWISE 1343
#define PRECISION 1344
#define PRIOR 1345
#define PROCEDURE 1346
#define REPORT_TO 1347
#define RETURNING 1348
#define UNDERLINE 1349
#define UNLOAD_TO 1350
#define BEFROW 1351
#define UNLOAD_T 1352
#define VARIABLE 1353
#define ABSOLUTE 1354
#define AFTROW 1355
#define BUFFERED 1356
#define CONSTANT 1357
#define CONST 1358
#define DATABASE 1359
#define DATETIME 1360
#define DEFAULTS 1361
#define DISTINCT 1362
#define END_CASE 1363
#define END_MAIN 1364
#define END_MENU 1365
#define END_TYPE 1366
#define EXIT_FOR 1367
#define EXTERNAL 1368
#define FRACTION 1369
#define FUNCTION 1370
#define GROUP_BY 1371
#define INTERVAL 1372
#define KWMESSAGE 1373
#define NOT_LIKE 1374
#define NOT_ILIKE 1375
#define NOT_NULL 1376
#define PASSWORD 1377
#define PREVIOUS 1378
#define READONLY 1379
#define REGISTER 1380
#define RELATIVE 1381
#define RESOURCE 1382
#define SMALLINT 1383
#define VALIDATE 1384
#define WITH_LOG 1385
#define WORDWRAP 1386
#define BY_NAME 1387
#define IN_FILE 1388
#define IS_NULL 1389
#define AVERAGE 1391
#define BETWEEN 1392
#define CAPTION 1393
#define CLIPPED 1394
#define CLOSE_BRACKET 1395
#define COLUMNS 1396
#define COMMENT 1398
#define CONNECT 1399
#define CURRENT 1400
#define DBYNAME 1401
#define DECIMAL 1402
#define DECLARE 1403
#define DEFAULT 1404
#define DISPLAY 1405
#define ENDCODE 1406
#define EXECUTE 1407
#define FOREACH 1408
#define FOREIGN 1409
#define GLOBALS 1410
#define INFIELD 1411
#define INTEGER 1412
#define KWWINDOW 1413
#define MAGENTA 1414
#define NUMERIC 1416
#define OPTIONS 1417
#define PERCENT 1418
#define PREPARE 1419
#define PROGRAM 1420
#define RECOVER 1421
#define REVERSE 1422
#define SECTION 1423
#define SESSION 1424
#define SYNONYM 1425
#define THRU 1426
#define TRAILER 1427
#define UPSHIFT 1428
#define VARCHAR 1429
#define WAITING 1430
#define CLOSE_SHEV 1431
#define CLOSE_SQUARE 1432
#define KW_FALSE 1434
#define NOT_IN 1435
#define ONKEY 1436
#define OPEN_BRACKET 1437
#define BORDER 1438
#define BOTTOM 1439
#define COLUMN 1440
#define COMMIT 1441
#define CREATE 1442
#define CURSOR 1443
#define DEFINE 1444
#define DELETE 1445
#define DOUBLE 1446
#define END_IF 1447
#define ESCAPE 1448
#define EXISTS 1449
#define EXTEND 1450
#define EXTENT 1451
#define FINISH 1452
#define FORMAT 1453
#define HAVING 1454
#define HEADER 1455
#define INSERT 1456
#define LOCATE 1457
#define MARGIN 1458
#define MEMORY 1459
#define MINUTE 1460
#define MODIFY 1461
#define NORMAL 1462
#define EQUAL_EQUAL 1463
#define OPEN_SHEV 1465
#define OPEN_SQUARE 1466
#define OPTION 1467
#define OUTPUT 1468
#define PROMPT 1469
#define PUBLIC 1470
#define RECORD 1471
#define REPORT 1472
#define REVOKE 1473
#define SCHEMA 1474
#define SCROLL_USING 1475
#define SCROLL 1476
#define SECOND 1477
#define SELECT 1478
#define SERIAL 1479
#define SETL 1480
#define SHARED 1481
#define SPACES 1482
#define UNIQUE 1483
#define UNLOCK 1484
#define UPDATE 1485
#define VALUES 1486
#define YELLOW 1487
#define AFTER 1488
#define KWLINE 1489
#define KW_NULL 1490
#define KW_TRUE 1491
#define SINGLE_KEY 1492
#define ALTER 1493
#define ARRAY 1494
#define ASCII 1495
#define AUDIT 1496
#define BLACK 1497
#define BLINK 1498
#define CHECK 1499
#define CLEAR 1500
#define CLOSE 1501
#define CODE_C 1502
#define COUNT 1503
#define DEFER 1504
#define ERROR 1505
#define EVERY 1506
#define FETCH 1507
#define FIRST 1508
#define FLOAT 1509
#define FLUSH 1510
#define FOUND 1511
#define GRANT 1512
#define GREEN 1513
#define GROUP 1514
#define INDEX 1515
#define KWFORM 1516
#define LABEL 1517
#define LOCAL 1519
#define MONEY 1520
#define MONTH 1521
#define ORDER 1524
#define OUTER 1525
#define PAUSE 1526
#define PRINT_IMAGE 1527
#define PRINT_FILE 1528
#define PRINT 1529
#define RIGHT 1530
#define DOUBLE_COLON 1531
#define SEMICOLON 1532
#define SLEEP 1533
#define TUPLE 1534
#define UNION 1535
#define WHERE 1537
#define WHILE 1538
#define WHITE 1539
#define CCODE 1540
#define ANSI 1541
#define BLUE 1542
#define BOLD 1543
#define BYTE 1544
#define FCALL 1545
#define CASE 1546
#define CYAN 1547
#define DATE 1548
#define DESC 1549
#define KWDOWN 1551
#define TAB 1552
#define DROP 1553
#define ELSE 1554
#define EXEC 1555
#define EXIT 1556
#define FREE 1557
#define FROM 1558
#define GOTO 1559
#define HELP_FILE 1560
#define LANG_FILE 1561
#define HELP 1562
#define HIDE 1563
#define HOUR 1564
#define INTO 1565
#define LAST 1566
#define LEFT 1567
#define LIKE 1568
#define MAIN 1569
#define MENU 1570
#define MODE 1571
#define NEED 1572
#define NEXT 1573
#define NOCR 1574
#define OPEN 1575
#define QUIT 1576
#define REAL 1577
#define ROWS 1578
#define SHOW 1579
#define SIZE 1580
#define SKIP 1581
#define SOME 1582
#define STEP 1583
#define STOP 1584
#define TEMP 1585
#define TEXT 1586
#define THEN 1587
#define USER 1588
#define WAIT 1589
#define WHEN 1590
#define WITH 1591
#define WORK 1592
#define YEAR 1593
#define KW_IS 1595
#define XSET 1596
#define ADD 1597
#define ALL 1598
#define ANY 1600
#define ASC 1601
#define AVG 1602
#define COLON 1603
#define DAY 1605
#define DBA 1606
#define DEC 1607
#define DIM 1608
#define FKEY 1609
#define FOR 1610
#define KEY 1611
#define KWNO 1612
#define LET 1613
#define LOG 1614
#define XMAX 1615
#define XMIN 1616
#define PAD 1620
#define PUT 1621
#define RED 1622
#define ROW 1623
#define RUN 1624
#define SQL 1625
#define SUM 1626
#define TOP 1627
#define USE 1628
#define ATSIGN 1629
#define AS_TIFF 1631
#define AS_GIF 1632
#define AS_PNG 1633
#define AS_JPEG 1634
#define AS 1635
#define AT 1636
#define BY 1637
#define DOT 1638
#define GO 1639
#define IF 1640
#define IN 1641
#define OF 1642
#define ON 1643
#define TO 1645
#define KWUP 1646
#define FONT_NAME 1647
#define FONT_SIZE 1648
#define PAPER_SIZE_IS_LETTER 1649
#define PAPER_SIZE_IS_LEGAL 1650
#define PAPER_SIZE_IS_A5 1651
#define PAPER_SIZE_IS_A4 1652
#define PAPER_SIZE_IS_LETTER_L 1653
#define PAPER_SIZE_IS_LEGAL_L 1654
#define PAPER_SIZE_IS_A5_L 1655
#define PAPER_SIZE_IS_A4_L 1656
#define FORMHANDLER 1657
#define END_FORMHANDLER 1658
#define BEFORE_EVENT 1659
#define BEFORE_OPEN_FORM 1660
#define AFTER_EVENT 1661
#define BEFORE_CLOSE_FORM 1662
#define BEFORE_ANY 1663
#define AFTER_ANY 1664
#define MENUHANDLER 1665
#define END_MENUHANDLER 1666
#define BEFORE_SHOW_MENU 1667
#define DISABLE_PROGRAM 1668
#define DISABLE_ALL 1669
#define BUTTONS 1670
#define CHECK_MENUITEM 1671
#define DISABLE_FORM 1672
#define DISABLE_MENUITEMS 1673
#define DISABLE 1674
#define ENABLE_FORM 1675
#define ENABLE_MENUITEMS 1676
#define ENABLE 1677
#define KWFIELD 1678
#define ICON 1679
#define MESSAGEBOX 1680
#define TO_DEFAULTS 1681
#define UNCHECK_MENUITEM 1682
#define BEFORE 1683
#define INPUT 1684
#define END 1685
#define INT_TO_ID 1686
#define TIMEOUT 1687
#define OFF 1688
#define WITH_1_DIMENSION 1689
#define WITH_2_DIMENSION 1690
#define WITH_3_DIMENSION 1691
#define TILDE 1692
#define ILIKE 1693
#define FGL_ISDYNARR_ALLOCATED 1694
#define FGL_DYNARR_EXTENTSIZE 1695




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
#line 212 "fgl.yacc"
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
#line 1671 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1683 "y.tab.c"

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
#define YYLAST   10126

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  712
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  839
/* YYNRULES -- Number of rules. */
#define YYNRULES  2240
/* YYNRULES -- Number of states. */
#define YYNSTATES  3524

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1709

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
     365,   366,   367,    15,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
      16,   424,   425,   426,   427,   428,   429,    23,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,    10,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,    13,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,    17,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,    12,   547,
     548,   549,    11,    20,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,     8,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
      21,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,    14,   618,   619,   620,   621,     7,
     622,   623,   624,   625,     5,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,    19,    22,     9,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
      18,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,     6,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,     2,     3,     4,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
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
    2049,  2054,  2056,  2060,  2064,  2068,  2070,  2071,  2074,  2076,
    2077,  2079,  2081,  2084,  2085,  2090,  2091,  2096,  2097,  2101,
    2102,  2106,  2107,  2111,  2112,  2116,  2117,  2121,  2122,  2126,
    2127,  2131,  2132,  2136,  2137,  2141,  2143,  2147,  2149,  2153,
    2156,  2161,  2163,  2165,  2167,  2168,  2173,  2179,  2186,  2187,
    2198,  2202,  2205,  2208,  2210,  2212,  2213,  2216,  2218,  2221,
    2225,  2229,  2233,  2237,  2239,  2241,  2243,  2245,  2246,  2250,
    2252,  2253,  2257,  2260,  2263,  2265,  2269,  2271,  2275,  2277,
    2279,  2281,  2283,  2285,  2287,  2289,  2291,  2293,  2295,  2297,
    2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,  2315,  2316,
    2317,  2325,  2327,  2329,  2332,  2335,  2338,  2342,  2347,  2348,
    2352,  2353,  2355,  2357,  2360,  2362,  2364,  2366,  2368,  2370,
    2372,  2373,  2375,  2377,  2380,  2383,  2385,  2387,  2389,  2391,
    2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2408,  2410,
    2412,  2414,  2416,  2417,  2418,  2419,  2420,  2434,  2436,  2437,
    2438,  2445,  2448,  2450,  2453,  2456,  2459,  2461,  2463,  2466,
    2468,  2469,  2473,  2476,  2478,  2480,  2482,  2483,  2484,  2485,
    2500,  2501,  2507,  2509,  2510,  2514,  2515,  2523,  2524,  2530,
    2532,  2535,  2536,  2538,  2540,  2542,  2543,  2545,  2547,  2550,
    2553,  2556,  2558,  2560,  2562,  2564,  2568,  2570,  2572,  2573,
    2574,  2582,  2584,  2587,  2588,  2592,  2593,  2598,  2601,  2602,
    2605,  2607,  2609,  2611,  2613,  2615,  2617,  2619,  2623,  2624,
    2626,  2628,  2630,  2632,  2635,  2638,  2641,  2647,  2656,  2658,
    2660,  2662,  2667,  2672,  2674,  2676,  2678,  2680,  2683,  2686,
    2690,  2697,  2699,  2703,  2705,  2707,  2709,  2713,  2720,  2730,
    2732,  2734,  2736,  2738,  2741,  2742,  2744,  2746,  2750,  2752,
    2756,  2758,  2762,  2764,  2768,  2770,  2772,  2774,  2776,  2780,
    2782,  2786,  2788,  2792,  2794,  2796,  2798,  2802,  2805,  2806,
    2808,  2810,  2815,  2817,  2821,  2823,  2827,  2835,  2836,  2844,
    2845,  2852,  2856,  2858,  2862,  2864,  2867,  2873,  2874,  2882,
    2883,  2886,  2887,  2889,  2895,  2898,  2904,  2905,  2911,  2918,
    2923,  2924,  2926,  2928,  2933,  2934,  2937,  2938,  2944,  2949,
    2952,  2954,  2958,  2961,  2964,  2967,  2970,  2973,  2976,  2978,
    2981,  2984,  2987,  2990,  2993,  2996,  2999,  3002,  3005,  3007,
    3009,  3011,  3013,  3015,  3017,  3023,  3025,  3027,  3030,  3035,
    3038,  3040,  3041,  3053,  3054,  3057,  3063,  3064,  3066,  3067,
    3070,  3072,  3075,  3076,  3080,  3082,  3083,  3088,  3089,  3092,
    3094,  3098,  3100,  3102,  3106,  3111,  3116,  3119,  3121,  3123,
    3125,  3126,  3128,  3136,  3139,  3142,  3145,  3148,  3151,  3153,
    3156,  3157,  3161,  3162,  3166,  3167,  3171,  3172,  3176,  3177,
    3181,  3182,  3187,  3188,  3193,  3195,  3197,  3199,  3201,  3203,
    3205,  3206,  3211,  3212,  3214,  3215,  3220,  3222,  3225,  3228,
    3231,  3232,  3234,  3236,  3239,  3242,  3243,  3246,  3250,  3254,
    3260,  3261,  3264,  3269,  3271,  3273,  3275,  3277,  3279,  3280,
    3282,  3284,  3288,  3291,  3297,  3300,  3306,  3312,  3318,  3324,
    3330,  3336,  3337,  3340,  3342,  3345,  3348,  3351,  3354,  3357,
    3360,  3362,  3365,  3368,  3371,  3374,  3376,  3379,  3382,  3385,
    3388,  3390,  3392,  3394,  3395,  3398,  3401,  3404,  3407,  3410,
    3413,  3416,  3419,  3422,  3424,  3426,  3428,  3430,  3432,  3434,
    3436,  3438,  3441,  3444,  3447,  3450,  3453,  3455,  3457,  3459,
    3460,  3464,  3467,  3468,  3469,  3470,  3471,  3472,  3473,  3489,
    3490,  3493,  3496,  3497,  3499,  3500,  3501,  3502,  3503,  3504,
    3505,  3521,  3524,  3525,  3526,  3527,  3538,  3539,  3541,  3545,
    3549,  3552,  3557,  3561,  3565,  3569,  3571,  3573,  3575,  3577,
    3579,  3581,  3582,  3583,  3591,  3592,  3593,  3602,  3610,  3613,
    3614,  3616,  3618,  3622,  3625,  3628,  3630,  3632,  3636,  3638,
    3640,  3643,  3645,  3649,  3653,  3657,  3659,  3663,  3665,  3667,
    3669,  3671,  3673,  3675,  3677,  3680,  3685,  3687,  3691,  3693,
    3697,  3700,  3705,  3707,  3711,  3713,  3716,  3721,  3723,  3727,
    3729,  3731,  3733,  3736,  3739,  3744,  3747,  3752,  3754,  3758,
    3760,  3762,  3764,  3767,  3769,  3771,  3773,  3775,  3777,  3780,
    3787,  3794,  3795,  3797,  3798,  3800,  3803,  3805,  3806,  3812,
    3813,  3819,  3821,  3822,  3826,  3828,  3832,  3834,  3838,  3840,
    3842,  3843,  3844,  3850,  3852,  3855,  3857,  3858,  3859,  3863,
    3864,  3865,  3869,  3871,  3873,  3875,  3877,  3879,  3881,  3884,
    3887,  3892,  3896,  3900,  3902,  3906,  3909,  3911,  3913,  3914,
    3916,  3918,  3920,  3922,  3923,  3925,  3929,  3931,  3935,  3937,
    3938,  3942,  3944,  3946,  3948,  3950,  3952,  3954,  3956,  3958,
    3960,  3962,  3964,  3966,  3974,  3975,  3977,  3979,  3981,  3983,
    3987,  3989,  3991,  3993,  3996,  3997,  4001,  4003,  4007,  4009,
    4013,  4015,  4017,  4024,  4025,  4029,  4031,  4035,  4036,  4038,
    4043,  4049,  4052,  4054,  4056,  4061,  4063,  4067,  4072,  4077,
    4079,  4083,  4085,  4087,  4089,  4092,  4094,  4099,  4100,  4102,
    4103,  4105,  4107,  4110,  4112,  4114,  4116,  4118,  4123,  4127,
    4129,  4131,  4133,  4136,  4138,  4140,  4143,  4146,  4148,  4152,
    4155,  4158,  4160,  4164,  4166,  4169,  4174,  4176,  4179,  4181,
    4185,  4190,  4191,  4193,  4194,  4196,  4197,  4199,  4201,  4205,
    4207,  4211,  4213,  4216,  4218,  4222,  4225,  4228,  4229,  4232,
    4234,  4236,  4242,  4246,  4252,  4256,  4258,  4262,  4264,  4266,
    4267,  4269,  4273,  4277,  4281,  4288,  4293,  4298,  4303,  4308,
    4314,  4316,  4318,  4320,  4322,  4324,  4326,  4328,  4330,  4332,
    4334,  4336,  4338,  4339,  4341,  4343,  4345,  4347,  4349,  4351,
    4353,  4358,  4364,  4366,  4372,  4378,  4380,  4382,  4384,  4389,
    4391,  4396,  4398,  4406,  4408,  4410,  4412,  4417,  4424,  4425,
    4428,  4433,  4435,  4437,  4439,  4441,  4443,  4445,  4447,  4451,
    4453,  4455,  4459,  4463,  4465,  4467,  4471,  4473,  4474,  4478,
    4484,  4486,  4489,  4492,  4497,  4501,  4503,  4505,  4507,  4509,
    4511,  4513,  4516,  4519,  4520,  4524,  4525,  4529,  4531,  4533,
    4535,  4537,  4539,  4541,  4543,  4548,  4550,  4552,  4554,  4556,
    4558,  4560,  4562,  4567,  4569,  4571,  4573,  4575,  4577,  4579,
    4581,  4583,  4585,  4587,  4589,  4591,  4593,  4595,  4600,  4602,
    4606,  4608,  4612,  4613,  4621,  4622,  4631,  4632,  4639,  4640,
    4649,  4650,  4652,  4655,  4657,  4661,  4663,  4667,  4673,  4675,
    4677,  4679,  4681,  4683,  4684,  4685,  4695,  4701,  4703,  4705,
    4712,  4713,  4717,  4719,  4723,  4728,  4730,  4731,  4734,  4739,
    4746,  4747,  4749,  4751,  4753,  4755,  4759,  4761,  4764,  4766,
    4768,  4771,  4774,  4776,  4778,  4780,  4783,  4788,  4792,  4795,
    4799,  4803,  4807,  4809,  4811,  4813,  4815,  4817,  4819,  4825,
    4831,  4837,  4843,  4849,  4854,  4859,  4863,  4868,  4870,  4874,
    4876,  4882,  4890,  4896,  4897,  4900,  4902,  4904,  4905,  4909,
    4911,  4915,  4917,  4919,  4921,  4922,  4926,  4928,  4930,  4932,
    4934,  4939,  4946,  4948,  4950,  4953,  4957,  4959,  4961,  4963,
    4965,  4967,  4969,  4971,  4973,  4979,  4985,  4990,  4991,  4996,
    4998,  5001,  5003,  5005,  5007,  5009,  5011,  5013,  5015,  5017,
    5019,  5021,  5023,  5025,  5027,  5029,  5031,  5033,  5035,  5037,
    5039,  5041,  5043,  5045,  5047,  5049,  5051,  5053,  5055,  5057,
    5059,  5061,  5063,  5065,  5067,  5069,  5071,  5073,  5075,  5077,
    5079,  5081,  5083,  5085,  5087,  5089,  5091,  5093,  5095,  5097,
    5099,  5101,  5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,
    5119,  5121,  5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,
    5139,  5141,  5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,
    5159,  5161,  5163,  5165,  5167,  5169,  5171,  5173,  5175,  5177,
    5179,  5181,  5183,  5185,  5187,  5189,  5191,  5193,  5195,  5197,
    5199,  5201,  5203,  5205,  5207,  5209,  5211,  5213,  5215,  5217,
    5219,  5221,  5223,  5225,  5227,  5229,  5231,  5233,  5235,  5237,
    5239,  5241,  5243,  5245,  5247,  5249,  5251,  5253,  5255,  5257,
    5259,  5261,  5263,  5265,  5267,  5269,  5271,  5273,  5275,  5277,
    5279,  5281,  5283,  5285,  5287,  5289,  5291,  5293,  5295,  5297,
    5299,  5301,  5303,  5305,  5307,  5309,  5311,  5313,  5315,  5317,
    5319,  5321,  5323,  5325,  5327,  5329,  5331,  5333,  5335,  5337,
    5339,  5341,  5343,  5345,  5347,  5349,  5351,  5353,  5355,  5357,
    5359,  5361,  5363,  5365,  5367,  5369,  5371,  5373,  5375,  5377,
    5379,  5381,  5383,  5385,  5387,  5389,  5391,  5393,  5395,  5397,
    5399,  5401,  5403,  5405,  5407,  5409,  5411,  5413,  5415,  5417,
    5419,  5421,  5423,  5425,  5427,  5429,  5431,  5433,  5435,  5437,
    5439,  5441,  5443,  5445,  5447,  5449,  5451,  5453,  5455,  5457,
    5459,  5461,  5463,  5465,  5467,  5469,  5471,  5473,  5475,  5477,
    5479,  5481,  5483,  5485,  5487,  5489,  5491,  5493,  5495,  5497,
    5499,  5501,  5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,
    5519,  5521,  5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,
    5539,  5541,  5543,  5545,  5547,  5549,  5551,  5553,  5555,  5557,
    5559,  5561,  5563,  5565,  5567,  5569,  5571,  5573,  5575,  5577,
    5579,  5581,  5583,  5585,  5587,  5589,  5591,  5593,  5595,  5597,
    5599,  5601,  5603,  5605,  5607,  5609,  5611,  5613,  5615,  5617,
    5619,  5621,  5623,  5625,  5627,  5629,  5631,  5633,  5635,  5637,
    5639,  5641,  5642,  5646,  5647,  5651,  5652,  5653,  5660,  5661,
    5664,  5667,  5675,  5679,  5683,  5686,  5689,  5692,  5694,  5698,
    5700,  5704,  5706,  5710,  5712,  5716,  5718,  5720,  5722,  5725,
    5728,  5730,  5732,  5735,  5740,  5742,  5744,  5746,  5748,  5750,
    5752,  5756,  5759,  5763,  5767,  5771,  5777,  5783,  5789,  5795,
    5801,  5806,  5811,  5815,  5820,  5822,  5824,  5828,  5829,  5835,
    5837,  5841,  5845,  5849,  5851,  5854,  5856,  5858,  5860,  5864,
    5870,  5872,  5874,  5876,  5878,  5882,  5884,  5885,  5886,  5893,
    5894,  5897,  5898,  5900,  5902,  5905,  5908,  5910,  5912,  5917,
    5921,  5923,  5925,  5928,  5934,  5937,  5940,  5946,  5947,  5950,
    5952,  5954,  5957,  5964,  5971,  5973,  5974,  5976,  5979,  5981,
    5984,  5985,  5988,  5990,  5992,  5994,  5996,  5998,  6000,  6002,
    6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,  6022,
    6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,  6042,
    6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,  6062,
    6064,  6066,  6068,  6070,  6072,  6074,  6076,  6078,  6080,  6082,
    6084,  6086,  6088,  6090,  6092,  6094,  6096,  6098,  6100,  6102,
    6104,  6106,  6108,  6110,  6112,  6114,  6116,  6118,  6120,  6122,
    6124,  6126,  6128,  6130,  6132,  6134,  6136,  6138,  6140,  6142,
    6144,  6146,  6148,  6150,  6152,  6154,  6156,  6158,  6160,  6162,
    6164
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1077,     0,    -1,   238,    -1,   235,    -1,   168,   717,   463,
     631,   718,    -1,   179,    -1,  1142,    -1,    26,    -1,   719,
      -1,   718,     5,   719,    -1,   987,    -1,   467,   720,   428,
      -1,   720,   721,   720,    -1,    26,    -1,   722,    26,    -1,
    1142,    -1,   929,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   724,
      -1,    -1,   312,   467,   725,   726,   428,    -1,   604,   467,
      26,     5,    26,   428,    -1,   727,    -1,   726,     5,   727,
      -1,   526,    -1,   567,    -1,   572,    -1,   542,    -1,   446,
      -1,   640,    -1,   564,    -1,   516,    -1,   453,    -1,   527,
      -1,   383,    -1,   568,    -1,   492,    -1,   370,    -1,   629,
      -1,   135,    -1,  1056,    -1,    -1,   729,    -1,    -1,   312,
     467,   730,   731,   428,    -1,   732,    -1,   731,     5,   732,
      -1,   727,    -1,   468,    -1,   638,    25,    -1,   241,   974,
      -1,   367,   974,    -1,   322,   974,    -1,   375,   974,    -1,
     331,   974,    -1,   297,   974,    -1,   570,   734,    -1,   918,
     382,  1142,    -1,    -1,   327,   467,  1535,   428,   382,   735,
    1161,    -1,   143,   467,   987,     5,    25,     5,    25,   428,
      -1,   443,   467,   979,   428,   382,  1142,    -1,  1280,    -1,
     230,   467,   937,   428,   382,  1142,    -1,    -1,    -1,  1142,
     625,   987,   467,   736,   750,   428,   737,   748,    -1,    -1,
      -1,    -1,   987,   467,   738,   750,   739,   428,   740,   748,
      -1,    -1,    -1,   510,  1479,   658,  1479,   467,   741,   750,
     742,   428,   748,    -1,    -1,    -1,   987,   557,   987,   467,
     743,   750,   744,   428,   748,    -1,    -1,    -1,    -1,   402,
     753,   625,   754,   495,   717,   463,   467,   745,   750,   746,
     428,   747,   749,    -1,    -1,   382,  1161,    -1,    -1,   382,
    1161,    -1,   201,    -1,    -1,   751,    -1,   752,    -1,   751,
       5,   752,    -1,   887,    -1,    25,    -1,   987,    -1,   987,
      -1,   987,   655,   987,    -1,    -1,   571,   894,   756,   759,
     763,   760,    -1,    -1,   571,   757,   758,   761,   760,    -1,
     765,    -1,   758,   765,    -1,   767,    -1,   759,   767,    -1,
     397,    -1,    -1,    -1,   377,   762,  1545,    -1,    -1,    -1,
     377,   764,  1545,    -1,    -1,   614,   894,   766,  1545,    -1,
      -1,   614,   894,   768,  1545,    -1,   316,   984,    -1,   240,
     982,    -1,   120,   982,    -1,   206,    -1,   223,  1485,    -1,
     530,   981,    -1,    30,   771,    31,    -1,   772,    -1,   774,
      -1,   773,    -1,   772,   773,    -1,    29,    -1,   775,    -1,
     774,   775,    -1,    28,    -1,   430,    -1,    -1,    -1,   358,
     778,   780,   779,   781,    -1,   421,  1142,   660,   782,  1030,
    1055,   723,    -1,  1142,   660,   782,  1030,   582,  1535,  1055,
     723,    -1,    -1,   784,   229,    -1,   783,    -1,   782,     5,
     783,    -1,   987,    -1,   987,   655,   987,    -1,   987,   655,
      20,    -1,   785,    -1,   784,   785,    -1,    -1,   308,   791,
     786,  1545,    -1,    -1,   311,   792,   787,  1545,    -1,    -1,
    1058,   788,  1545,    -1,    -1,   204,   789,  1545,    -1,    -1,
     202,   790,  1545,    -1,   991,    -1,   791,     5,   991,    -1,
     991,    -1,   792,     5,   991,    -1,   129,    -1,   130,    -1,
     131,    -1,   132,    -1,   133,    -1,   134,    -1,   467,   887,
     795,   428,    -1,    -1,     5,   838,   661,   841,    -1,   194,
      -1,   317,    -1,    -1,   798,    -1,   799,    -1,   798,   799,
      -1,    -1,    -1,   474,   800,   802,   801,  1249,    -1,   851,
      -1,   805,    -1,   802,     5,   805,    -1,    -1,   804,   987,
      -1,   391,   803,   850,    25,    -1,   391,   803,   850,   987,
      -1,   391,   803,   850,   993,    -1,   391,   803,   850,    26,
      -1,   809,   827,    -1,    -1,   803,   391,   806,   807,    -1,
      26,    -1,    25,    -1,   993,    -1,    19,    26,    -1,   803,
      -1,   808,    -1,   809,     5,   808,    -1,    -1,   357,    -1,
      -1,   705,    -1,   706,    -1,   707,    -1,    -1,   523,   495,
     819,   463,   813,   659,   827,    -1,    -1,    35,   811,   814,
     659,   827,    -1,    -1,   356,   810,   816,    26,   817,   340,
     495,   818,   463,   815,   659,   827,    -1,   467,    -1,   494,
      -1,   428,    -1,   462,    -1,    26,    -1,   820,     5,   820,
       5,   820,    -1,   820,     5,   820,    -1,   820,    -1,    26,
      -1,    -1,   500,   822,   802,   321,    -1,    -1,   298,   823,
     803,   655,    20,    -1,    -1,   372,   824,   803,   296,   467,
     825,   428,    -1,   826,    -1,   825,     5,   826,    -1,   803,
      -1,   829,    -1,    -1,    95,    -1,    -1,    -1,   830,   832,
     831,   828,    -1,   812,    -1,   821,    -1,   357,    -1,   357,
     467,    26,   428,    -1,   460,   467,    26,   428,    -1,   460,
     467,    26,     5,    26,   428,    -1,   444,    -1,   652,   803,
      -1,   417,    -1,   545,    -1,   126,    -1,   434,    -1,   434,
     467,    26,   428,    -1,   434,   467,    26,     5,    26,   428,
      -1,   548,    -1,   548,   467,    26,   428,    -1,   548,   467,
      26,     5,    26,   428,    -1,   538,    -1,   337,    -1,   573,
      -1,   569,    -1,   116,    -1,   117,    -1,   610,    -1,   394,
     836,    -1,   406,   837,    -1,   833,    -1,    32,    -1,   592,
     834,   655,   835,    -1,   803,    -1,   803,    -1,    -1,   838,
     661,   841,    -1,   846,   661,   849,    -1,    -1,   839,   840,
      -1,   617,    -1,   549,    -1,   626,    -1,   588,    -1,   490,
      -1,   506,    -1,   403,   843,    -1,    -1,   842,   840,    -1,
      -1,   467,   845,   428,    -1,    -1,   467,    26,   428,    -1,
      26,    -1,    -1,   847,   848,   844,    -1,   617,    -1,   549,
      -1,   626,    -1,   588,    -1,   490,    -1,   506,    -1,   403,
     843,    -1,   848,    -1,    -1,    14,    -1,    -1,   274,   987,
     852,   652,   853,    -1,   855,    -1,   858,    -1,   357,    -1,
     357,   467,    26,   428,    -1,   460,   467,    26,   428,    -1,
     460,   467,    26,     5,    26,   428,    -1,   444,    -1,   417,
      -1,   545,    -1,   434,    -1,   434,   467,    26,   428,    -1,
     434,   467,    26,     5,    26,   428,    -1,   548,    -1,   548,
     467,    26,   428,    -1,   548,   467,    26,     5,    26,   428,
      -1,   538,    -1,   337,    -1,   573,    -1,   569,    -1,   610,
      -1,   394,   836,    -1,   406,   837,    -1,   854,    -1,   592,
     834,   655,   835,    -1,    -1,   523,   495,   819,   463,   856,
     659,   853,    -1,    -1,   356,   810,   816,    26,   817,   340,
     495,   818,   463,   857,   659,   853,    -1,    -1,   500,   859,
     861,   321,    -1,    -1,   298,   860,   987,   655,    20,    -1,
     862,    -1,   861,     5,   862,    -1,   863,   853,    -1,   864,
      -1,   863,     5,   864,    -1,   987,    -1,    -1,   653,   978,
      -1,   107,   987,    -1,   105,    -1,   661,  1535,    -1,   661,
     545,   987,   694,  1535,    -1,   661,   545,   987,   426,    -1,
     109,   987,    -1,   195,   912,  1161,   873,    -1,   437,   912,
     892,   865,   873,    -1,   247,   984,   873,    -1,    -1,    -1,
     226,   870,  1168,   661,   987,   655,    20,   872,   723,   871,
     874,    -1,    -1,   504,   979,    -1,   723,    -1,    -1,   875,
     276,    -1,   276,    -1,   876,    -1,   875,   876,    -1,    -1,
     389,   877,  1545,    -1,    -1,   385,   878,  1545,    -1,    -1,
    1058,   879,  1545,    -1,    37,  1142,    -1,    38,  1142,    -1,
      36,  1142,    -1,   534,   912,   893,   723,    -1,   534,   912,
     893,   723,   102,    -1,   324,    -1,   323,    -1,   250,    -1,
     401,    -1,   211,    -1,   249,    -1,   366,    -1,   365,    -1,
     281,    -1,   208,    -1,   207,    -1,   185,    -1,   242,    -1,
     169,    -1,   184,    -1,   225,    -1,   192,    -1,   251,    -1,
     251,   894,    -1,   897,    -1,   896,    -1,   901,    -1,   929,
      -1,   887,   888,    -1,   930,    -1,   932,    -1,   898,    -1,
      19,   887,    -1,    18,   887,    -1,   903,    -1,   911,    -1,
     905,    -1,   511,    -1,   793,    -1,   906,    -1,   907,    -1,
     908,    -1,   909,    -1,   910,    -1,    40,   887,    -1,   912,
      -1,   912,   891,    -1,   894,    -1,   519,    -1,   890,    -1,
     891,     5,   890,    -1,   894,    -1,   892,     5,   894,    -1,
     894,    -1,   893,     5,   894,    -1,   887,    -1,    18,    -1,
      19,    -1,     9,   887,    -1,   520,    -1,   464,    -1,   467,
     887,   428,    -1,   479,   467,  1459,   428,    -1,   332,   467,
    1459,   428,    -1,   895,   993,    -1,   895,    26,    -1,    25,
      -1,   993,    -1,    26,    -1,   900,    -1,  1142,    -1,  1142,
     457,  1142,    -1,   899,    -1,   470,   887,    -1,   429,   887,
      -1,  1252,    -1,    -1,   543,   902,  1252,    -1,     7,   887,
      -1,     6,   887,    -1,   887,    -1,   904,     5,   887,    -1,
     658,   467,  1459,   428,    -1,   465,   467,  1459,   428,    -1,
     658,   467,   912,   904,   428,    -1,   465,   467,   912,   904,
     428,    -1,   423,    -1,   287,    -1,    10,   887,    -1,   290,
     887,    -1,    10,   887,   478,    25,    -1,   290,   887,   478,
      25,    -1,   592,   887,    -1,   408,   887,    -1,   592,   887,
     478,    25,    -1,   408,   887,   478,    25,    -1,   427,    -1,
       8,   887,    -1,    18,   887,    -1,    19,   887,    -1,    20,
     887,    -1,    21,   887,    -1,    22,   887,    -1,    11,   887,
      -1,    14,   887,    -1,   493,   887,    -1,    12,   887,    -1,
      13,   887,    -1,    17,   887,    -1,    16,   887,    -1,    15,
     887,    -1,    -1,    -1,    -1,   987,   467,   914,   750,   915,
     428,    -1,    -1,    -1,   987,   557,   987,   467,   916,   750,
     917,   428,    -1,    -1,    -1,   573,   467,   919,   887,   920,
     428,    -1,    -1,    -1,   549,   467,   921,   887,   922,   428,
      -1,    -1,    -1,   626,   467,   923,   887,   924,   428,    -1,
      -1,    -1,   617,   467,   925,   887,   926,   428,    -1,   406,
     467,   933,   428,   928,    -1,   394,   467,    25,   428,   927,
      -1,   394,   467,    26,   428,   927,    -1,   394,   467,    26,
     625,    26,   428,   927,    -1,   710,   467,  1142,   428,    -1,
     711,   467,  1142,     5,    26,   428,    -1,    -1,  1439,   661,
    1440,    -1,   837,    -1,   918,    -1,   327,   467,  1535,   428,
      -1,   136,   467,   979,   428,    -1,   108,   467,   979,   428,
      -1,   443,   467,  1535,   428,    -1,   230,   467,  1535,   428,
      -1,    96,   467,  1535,   428,    -1,   931,    -1,   913,    -1,
    1435,    -1,   573,    -1,   459,   467,   887,   428,    -1,   360,
     467,   887,   428,    -1,   524,   887,    -1,   480,   794,    -1,
     887,   147,    -1,   887,   148,    -1,   887,   149,    -1,    25,
      -1,   934,    -1,    19,   934,    -1,   936,    -1,   935,    -1,
      26,    -1,    26,    26,    -1,    26,    26,   625,    26,    -1,
      26,    26,   625,    26,   625,    26,    -1,    26,    26,   625,
      26,   625,    24,    -1,    26,   625,    26,    -1,    26,   625,
      26,   625,    26,    -1,    26,   625,    26,   625,    24,    -1,
      26,   625,    24,    -1,    24,    -1,    26,    -1,    26,    19,
      26,    -1,   979,    -1,   937,     5,   979,    -1,    -1,    -1,
     631,  1142,    14,   894,   661,   894,   941,   939,  1545,   940,
     279,    -1,    -1,   607,   894,    -1,    -1,    -1,    -1,   440,
     943,   981,   944,   946,  1339,   945,  1545,   278,    -1,    -1,
       8,   912,   892,    -1,    -1,    -1,   673,   987,   948,   797,
     949,  1087,   951,   950,   956,   674,    -1,    -1,   961,    -1,
      -1,   952,    -1,   953,    -1,   952,   953,    -1,    -1,   675,
     954,  1545,    -1,    -1,   676,   955,  1545,    -1,    -1,   957,
      -1,   958,    -1,   957,   958,    -1,    -1,   677,   959,  1545,
      -1,    -1,   678,   960,  1545,    -1,   962,   966,   362,    -1,
     128,    -1,   128,   963,   582,   964,    -1,   128,   421,   965,
      -1,  1142,    -1,   963,     5,  1142,    -1,   987,    -1,   964,
       5,   987,    -1,  1142,    -1,   965,     5,  1142,    -1,   967,
      -1,   966,   967,    -1,    -1,   679,   968,  1545,    -1,    -1,
     680,   969,  1545,    -1,    -1,   699,   964,   970,  1545,    -1,
      -1,   517,   964,   971,  1545,    -1,    -1,   660,   964,   972,
    1545,    -1,   581,   980,    -1,   590,    19,    26,    -1,   590,
      -1,   537,    18,    26,    -1,   537,    -1,    26,    -1,  1142,
      -1,   704,    -1,    25,    -1,   992,    -1,   894,    -1,   976,
       5,   976,    -1,   977,    -1,   987,    -1,   702,   467,   987,
     428,    -1,   987,   655,   702,   467,   987,   428,    -1,   987,
     495,   720,   463,    -1,   987,   655,    20,    -1,   987,   495,
     720,   463,   655,    20,    -1,   987,   655,   987,    -1,   987,
     495,   720,   463,   655,   987,    -1,   988,    -1,   988,    -1,
     988,    -1,   988,    -1,   988,    -1,   988,    -1,    -1,   586,
      26,    -1,  1544,    -1,   989,    -1,  1544,    -1,   387,   467,
     990,   428,    -1,  1145,    -1,    25,    -1,   987,    -1,   987,
     495,   720,   463,    -1,   987,   655,    20,    -1,   987,   495,
     720,   463,   655,    20,    -1,   987,   655,   987,    -1,   987,
     495,   720,   463,   655,   987,    -1,  1142,    -1,    24,    -1,
     655,    26,    -1,   583,   995,    -1,   987,    -1,   625,   987,
      -1,   687,   997,    -1,   998,    -1,   997,     5,   998,    -1,
     987,    -1,   698,   997,    -1,   689,   997,    -1,   690,  1535,
      -1,   688,   984,   694,  1535,    -1,   692,   997,    -1,   693,
    1535,    -1,   691,   984,   694,  1535,    -1,    -1,   696,  1003,
     892,  1008,  1010,  1012,  1004,  1006,    -1,    -1,  1005,    -1,
     684,    -1,   685,    -1,    -1,  1007,    -1,   382,  1142,    -1,
      -1,  1009,    -1,   426,   892,    -1,    -1,  1011,    -1,   695,
      26,    -1,    -1,  1013,    -1,   686,    26,  1014,    -1,    -1,
     436,    26,    -1,    -1,    -1,   657,   894,   611,  1016,  1545,
    1017,  1018,   477,    -1,    -1,    -1,   578,  1019,  1545,    -1,
      -1,    -1,    99,  1020,   894,   611,  1021,  1545,  1018,    -1,
     145,   987,   467,    26,   428,    -1,    92,   987,    -1,   112,
     987,    -1,    -1,   328,  1173,  1025,   661,   519,    -1,   328,
    1173,   592,  1026,    -1,  1027,    -1,  1026,     5,  1027,    -1,
    1028,   655,  1431,    -1,  1028,   655,    20,    -1,  1427,    -1,
      -1,  1031,   362,    -1,   362,    -1,    -1,   189,    -1,  1032,
      -1,  1031,  1032,    -1,    -1,   308,  1044,  1033,  1545,    -1,
      -1,   311,  1045,  1034,  1545,    -1,    -1,   389,  1035,  1545,
      -1,    -1,   385,  1036,  1545,    -1,    -1,  1058,  1037,  1545,
      -1,    -1,   343,  1038,  1545,    -1,    -1,   313,  1039,  1545,
      -1,    -1,    41,  1040,  1545,    -1,    -1,    39,  1041,  1545,
      -1,    -1,    43,  1042,  1545,    -1,    -1,    42,  1043,  1545,
      -1,   979,    -1,  1044,     5,   979,    -1,   979,    -1,  1045,
       5,   979,    -1,   352,  1048,    -1,   353,   987,   694,  1048,
      -1,   597,    -1,   412,    -1,   979,    -1,    -1,   700,  1051,
    1050,  1029,    -1,   421,  1161,  1030,   986,   723,    -1,  1161,
    1030,   582,  1535,   986,   723,    -1,    -1,   523,  1168,  1030,
     582,   987,   655,    20,   986,  1052,   723,    -1,   505,  1535,
    1054,    -1,   118,    26,    -1,   119,    26,    -1,   662,    -1,
     575,    -1,    -1,   586,    26,    -1,  1057,    -1,    49,    25,
      -1,   532,    14,    26,    -1,   532,    14,  1142,    -1,    50,
      14,    26,    -1,    50,    14,  1142,    -1,    46,    -1,    48,
      -1,    45,    -1,    47,    -1,    -1,   466,  1059,  1064,    -1,
     333,    -1,    -1,   632,  1061,  1064,    -1,   341,  1066,    -1,
     632,  1064,    -1,  1066,    -1,   467,  1065,   428,    -1,  1066,
      -1,  1065,     5,  1066,    -1,  1067,    -1,   630,    -1,   350,
      -1,   368,    -1,   342,    -1,   521,    -1,   478,    -1,   662,
      -1,   586,    -1,   575,    -1,   215,    -1,   475,    -1,   486,
      -1,   576,    -1,   591,    -1,   556,    -1,   348,    -1,   349,
      -1,    25,    -1,   546,    -1,    -1,    -1,   634,  1070,  1166,
    1071,    14,   912,  1072,    -1,   519,    -1,   893,    -1,   257,
    1142,    -1,   246,  1142,    -1,   260,  1142,    -1,   487,  1142,
     371,    -1,   487,  1142,   422,   975,    -1,    -1,  1079,  1078,
    1082,    -1,    -1,  1080,    -1,  1081,    -1,  1080,  1081,    -1,
    1023,    -1,  1086,    -1,  1528,    -1,  1102,    -1,  1088,    -1,
    1101,    -1,    -1,  1083,    -1,  1085,    -1,  1083,  1085,    -1,
     103,   987,    -1,  1090,    -1,  1096,    -1,  1108,    -1,  1262,
      -1,  1272,    -1,  1129,    -1,   947,    -1,   770,    -1,  1022,
      -1,   776,    -1,  1528,    -1,   770,    -1,    -1,   770,    -1,
     798,    -1,   404,    -1,    97,    -1,    -1,    -1,    -1,    -1,
    1089,  1091,   987,   467,  1092,  1159,   428,  1093,   797,  1094,
    1087,  1545,  1095,    -1,   248,    -1,    -1,    -1,   593,  1097,
     797,  1098,  1545,   398,    -1,   215,   889,    -1,   912,    -1,
     912,   892,    -1,   393,  1443,    -1,   503,  1443,    -1,  1103,
      -1,  1104,    -1,  1103,  1104,    -1,  1105,    -1,    -1,   442,
    1106,  1107,    -1,   797,   280,    -1,   975,    -1,  1086,    -1,
    1101,    -1,    -1,    -1,    -1,   152,   987,   151,   987,   467,
    1109,  1159,   428,  1110,   797,  1111,  1087,  1545,  1095,    -1,
      -1,   594,  1113,  1128,  1119,  1114,    -1,   399,    -1,    -1,
     272,  1116,  1545,    -1,    -1,    23,  1120,  1121,  1122,   986,
    1117,  1545,    -1,    -1,    23,  1120,   986,  1118,  1545,    -1,
    1115,    -1,  1119,  1115,    -1,    -1,  1060,    -1,    25,    -1,
    1142,    -1,    -1,  1142,    -1,    25,    -1,   289,  1126,    -1,
     301,  1127,    -1,   284,  1127,    -1,   621,    -1,    25,    -1,
    1142,    -1,  1126,    -1,  1127,     5,  1126,    -1,  1142,    -1,
      25,    -1,    -1,    -1,   681,   987,  1130,   797,  1131,  1132,
     682,    -1,  1133,    -1,  1132,  1133,    -1,    -1,   683,  1134,
    1545,    -1,    -1,   660,   987,  1135,  1545,    -1,  1139,  1137,
      -1,    -1,   724,  1140,    -1,  1141,    -1,  1138,    -1,  1009,
      -1,  1011,    -1,  1013,    -1,  1005,    -1,  1007,    -1,   407,
     912,   892,    -1,    -1,   102,    -1,   102,    -1,  1143,    -1,
    1145,    -1,   228,  1145,    -1,  1145,   655,    -1,  1144,  1149,
      -1,  1144,   987,   495,  1153,   463,    -1,  1144,   987,   495,
    1153,   463,   495,  1153,   463,    -1,  1150,    -1,   987,    -1,
    1146,    -1,   987,   494,  1148,   462,    -1,   987,   494,  1148,
     462,    -1,  1142,    -1,    25,    -1,    20,    -1,   987,    -1,
     987,  1152,    -1,   987,  1152,    -1,   495,  1153,   463,    -1,
     495,  1153,   463,   495,  1153,   463,    -1,  1154,    -1,  1153,
       5,  1154,    -1,   720,    -1,  1156,    -1,  1158,    -1,  1156,
     655,  1157,    -1,  1156,   655,   987,   495,  1153,   463,    -1,
    1156,   655,   987,   495,  1153,   463,   495,  1153,   463,    -1,
     987,    -1,  1147,    -1,    20,    -1,   987,    -1,   987,  1152,
      -1,    -1,  1160,    -1,  1162,    -1,  1160,     5,  1162,    -1,
    1163,    -1,  1161,     5,  1163,    -1,   987,    -1,   987,   655,
     987,    -1,  1142,    -1,  1142,   457,  1142,    -1,    25,    -1,
     993,    -1,    26,    -1,  1165,    -1,  1164,     5,  1165,    -1,
    1142,    -1,  1142,   457,  1142,    -1,  1167,    -1,  1166,     5,
    1167,    -1,  1155,    -1,  1142,    -1,  1170,    -1,  1169,     5,
    1170,    -1,  1142,  1171,    -1,    -1,   623,    -1,   574,    -1,
     987,   495,  1153,   463,    -1,  1174,    -1,  1173,     5,  1174,
      -1,  1142,    -1,  1142,   457,  1142,    -1,   292,   983,   653,
     977,   615,  1537,   728,    -1,    -1,   653,   467,   894,     5,
     894,   428,  1177,    -1,    -1,   604,   467,   894,     5,   894,
     428,    -1,   293,   987,  1176,    -1,   987,    -1,   376,   985,
    1181,    -1,  1182,    -1,   582,   894,    -1,  1183,  1184,  1189,
       8,  1179,    -1,    -1,   653,  1185,   467,   894,     5,   894,
     428,    -1,    -1,   592,   988,    -1,    -1,   388,    -1,   255,
    1485,   304,  1523,  1188,    -1,   599,   980,    -1,   599,   980,
       8,   912,   892,    -1,    -1,   652,   612,  1479,   411,  1479,
      -1,   652,   612,  1479,     5,   411,  1479,    -1,   652,  1479,
       5,  1479,    -1,    -1,   684,    -1,   685,    -1,   127,  1523,
    1191,  1192,    -1,    -1,   652,  1523,    -1,    -1,   652,   612,
    1479,     8,  1479,    -1,   612,  1479,     8,  1479,    -1,   448,
    1194,    -1,  1195,    -1,  1194,     5,  1195,    -1,   241,   974,
      -1,   322,   974,    -1,   367,   974,    -1,   375,   974,    -1,
     331,   974,    -1,   297,   974,    -1,  1062,    -1,   475,  1063,
      -1,   486,  1063,    -1,   597,  1063,    -1,   412,  1063,    -1,
     586,  1063,    -1,   584,   975,    -1,   585,   975,    -1,   437,
     724,    -1,   700,   724,    -1,   329,    -1,   233,    -1,   190,
      -1,   170,    -1,   187,    -1,   178,    -1,  1484,   450,  1199,
     582,  1197,    -1,  1142,    -1,    25,    -1,   439,  1199,    -1,
     439,  1199,     8,  1161,    -1,    44,  1197,    -1,   988,    -1,
      -1,   498,  1209,   723,   631,  1204,  1142,  1202,   986,   723,
    1201,  1205,    -1,    -1,   703,    26,    -1,   498,  1209,   723,
     382,  1142,    -1,    -1,   357,    -1,    -1,  1206,   320,    -1,
    1207,    -1,  1206,  1207,    -1,    -1,  1058,  1208,  1545,    -1,
     893,    -1,    -1,   639,   980,  1211,  1212,    -1,    -1,   582,
    1213,    -1,  1214,    -1,  1213,     5,  1214,    -1,  1471,    -1,
     519,    -1,   258,  1217,   125,    -1,   258,  1217,   661,  1216,
      -1,   258,  1217,   124,  1216,    -1,   258,  1217,    -1,    25,
      -1,   992,    -1,   987,    -1,    -1,   515,    -1,   186,  1217,
    1218,   467,   912,  1100,   428,    -1,   231,  1217,    -1,   104,
    1217,    -1,  1253,  1261,    -1,   483,    98,    -1,   483,  1224,
      -1,  1225,    -1,  1224,  1225,    -1,    -1,   174,  1226,  1545,
      -1,    -1,   237,  1227,  1545,    -1,    -1,   266,  1228,  1545,
      -1,    -1,   254,  1229,  1545,    -1,    -1,   291,  1230,  1545,
      -1,    -1,   239,  1142,  1231,  1545,    -1,    -1,   262,  1142,
    1232,  1545,    -1,  1243,    -1,  1245,    -1,  1244,    -1,  1234,
      -1,  1270,    -1,  1237,    -1,    -1,   596,   894,  1235,   518,
      -1,    -1,   518,    -1,    -1,   605,    26,  1238,  1236,    -1,
     197,    -1,   664,  1257,    -1,   200,  1257,    -1,   199,  1257,
      -1,    -1,  1240,    -1,  1241,    -1,  1240,  1241,    -1,  1250,
    1242,    -1,    -1,   653,  1257,    -1,   555,  1239,  1249,    -1,
     554,  1479,  1249,    -1,   553,  1248,  1247,  1246,  1249,    -1,
      -1,   191,   887,    -1,   191,   887,     5,   887,    -1,   648,
      -1,   649,    -1,   650,    -1,   651,    -1,  1142,    -1,    -1,
     558,    -1,  1251,    -1,  1250,     5,  1251,    -1,   894,  1284,
      -1,   644,   467,   887,   428,  1269,    -1,   101,  1269,    -1,
     532,   467,    20,   428,  1269,    -1,   449,   467,    20,   428,
    1269,    -1,   424,   467,   887,   428,  1269,    -1,   624,   467,
     887,   428,  1269,    -1,   637,   467,   887,   428,  1269,    -1,
     636,   467,   887,   428,  1269,    -1,    -1,   497,  1254,    -1,
    1255,    -1,  1254,  1255,    -1,   265,    26,    -1,   256,    26,
      -1,   339,    26,    -1,   222,    26,    -1,   294,    26,    -1,
     213,    -1,   381,    25,    -1,   381,  1142,    -1,   214,    25,
      -1,   198,    25,    -1,  1260,    -1,  1256,  1260,    -1,  1258,
     147,    -1,  1258,   149,    -1,  1258,   148,    -1,  1258,    -1,
     993,    -1,    26,    -1,    -1,   497,  1256,    -1,   265,  1257,
      -1,   256,  1257,    -1,   339,  1257,    -1,   222,  1257,    -1,
     294,  1257,    -1,   295,  1257,    -1,   663,    25,    -1,   664,
    1257,    -1,   668,    -1,   665,    -1,   666,    -1,   667,    -1,
     672,    -1,   669,    -1,   670,    -1,   671,    -1,   113,  1257,
      -1,   114,  1257,    -1,   115,  1257,    -1,   381,    25,    -1,
     214,    25,    -1,   436,    -1,   110,    -1,   111,    -1,    -1,
     550,   654,  1169,    -1,   175,  1169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   501,  1263,   987,   467,  1264,  1159,   428,
    1265,   797,  1266,  1222,  1267,  1223,  1268,   277,    -1,    -1,
     562,   887,    -1,   552,  1271,    -1,    -1,  1197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,  1273,   987,   467,  1274,
    1159,   428,  1275,   797,  1276,  1279,  1277,  1223,  1278,   277,
      -1,  1259,  1261,    -1,    -1,    -1,    -1,   193,   467,    25,
       5,  1281,   750,  1282,   428,  1283,   748,    -1,    -1,   420,
      -1,   420,   256,    26,    -1,   420,   256,  1142,    -1,   642,
     894,    -1,   642,   894,   382,  1142,    -1,   642,   894,   201,
      -1,   642,   894,   613,    -1,   642,   894,   580,    -1,  1287,
      -1,   210,    -1,   361,    -1,   319,    -1,  1294,    -1,  1289,
      -1,    -1,    -1,   244,  1290,  1427,   467,  1291,  1298,   428,
      -1,    -1,    -1,   172,  1292,  1427,   467,  1293,  1298,   428,
    1295,    -1,   142,  1428,   660,  1427,   467,  1296,   428,    -1,
      91,   988,    -1,    -1,   306,    -1,  1297,    -1,  1296,     5,
    1297,    -1,   987,   623,    -1,   987,   574,    -1,   987,    -1,
    1299,    -1,  1298,     5,  1299,    -1,  1380,    -1,  1378,    -1,
     159,   987,    -1,   217,    -1,    51,   987,  1302,    -1,    52,
    1428,   139,    -1,    52,  1428,   140,    -1,  1303,    -1,  1302,
       5,  1303,    -1,  1304,    -1,  1307,    -1,  1310,    -1,  1315,
      -1,  1316,    -1,  1314,    -1,  1313,    -1,   620,  1305,    -1,
     620,   467,  1306,   428,    -1,  1299,    -1,  1299,   699,   987,
      -1,  1305,    -1,  1306,     5,  1305,    -1,   577,  1309,    -1,
     577,   467,  1308,   428,    -1,  1309,    -1,  1308,     5,  1309,
      -1,   987,    -1,   491,  1312,    -1,   491,   467,  1311,   428,
      -1,  1312,    -1,  1311,     5,  1312,    -1,  1299,    -1,   122,
      -1,   123,    -1,   121,    26,    -1,    93,  1384,    -1,    93,
     467,  1317,   428,    -1,    94,  1318,    -1,    94,   467,  1317,
     428,    -1,  1384,    -1,  1317,     5,  1384,    -1,   987,    -1,
     303,    -1,   269,    -1,   203,  1321,    -1,   182,    -1,   171,
      -1,   158,    -1,   156,    -1,   160,    -1,   216,  1485,    -1,
     268,  1320,   496,  1479,   661,  1479,    -1,   336,   980,   496,
    1479,   661,  1479,    -1,    -1,  1485,    -1,    -1,   894,    -1,
     559,   894,    -1,   267,    -1,    -1,   286,  1325,  1427,  1328,
    1326,    -1,    -1,   515,  1327,   467,  1330,   428,    -1,  1465,
      -1,    -1,   467,  1329,   428,    -1,  1431,    -1,  1329,     5,
    1431,    -1,  1331,    -1,  1330,     5,  1331,    -1,  1471,    -1,
     519,    -1,    -1,    -1,   536,  1333,  1336,  1334,  1337,    -1,
     988,    -1,  1341,   981,    -1,   981,    -1,    -1,    -1,   589,
    1338,  1164,    -1,    -1,    -1,   589,  1340,  1164,    -1,   537,
      -1,   590,    -1,   597,    -1,   412,    -1,   379,    -1,   432,
      -1,   415,   894,    -1,   388,   894,    -1,   275,  1427,   188,
     981,    -1,   275,  1427,  1400,    -1,   550,   654,  1345,    -1,
    1346,    -1,  1345,     5,  1346,    -1,  1347,  1348,    -1,    26,
      -1,  1431,    -1,    -1,   623,    -1,   574,    -1,   314,    -1,
     347,    -1,    -1,   364,    -1,   393,  1353,  1351,    -1,  1523,
      -1,  1523,   647,   987,    -1,    25,    -1,    -1,  1484,  1355,
    1356,    -1,  1385,    -1,  1389,    -1,  1350,    -1,  1486,    -1,
    1349,    -1,  1342,    -1,  1343,    -1,  1332,    -1,  1324,    -1,
    1323,    -1,  1455,    -1,  1503,    -1,   541,  1359,   660,  1427,
     661,  1364,  1358,    -1,    -1,   181,    -1,   205,    -1,  1360,
      -1,  1361,    -1,  1360,     5,  1361,    -1,   507,    -1,   486,
      -1,   475,    -1,   514,  1362,    -1,    -1,   467,  1363,   428,
      -1,  1431,    -1,  1363,     5,  1431,    -1,  1365,    -1,  1364,
       5,  1365,    -1,   499,    -1,  1429,    -1,   273,  1427,  1367,
     652,  1465,  1369,    -1,    -1,   467,  1368,   428,    -1,  1431,
      -1,  1368,     5,  1431,    -1,    -1,   180,    -1,   528,   467,
    1403,   428,    -1,   283,   467,  1373,   428,  1372,    -1,   334,
    1374,    -1,  1375,    -1,  1427,    -1,  1427,   467,  1375,   428,
      -1,  1431,    -1,  1375,     5,  1431,    -1,   512,   467,  1377,
     428,    -1,   296,   467,  1377,   428,    -1,  1431,    -1,  1377,
       5,  1431,    -1,  1376,    -1,  1371,    -1,  1370,    -1,   436,
    1434,    -1,   245,    -1,   987,  1419,  1381,  1382,    -1,    -1,
    1379,    -1,    -1,  1383,    -1,  1384,    -1,  1383,  1384,    -1,
     410,    -1,   196,    -1,   512,    -1,  1372,    -1,   528,   467,
    1403,   428,    -1,   157,  1386,  1388,    -1,  1387,    -1,  1429,
      -1,  1389,    -1,  1388,  1389,    -1,  1366,    -1,  1357,    -1,
     484,  1403,    -1,   405,  1392,    -1,  1470,    -1,  1392,     5,
    1470,    -1,   562,  1403,    -1,   582,  1395,    -1,  1396,    -1,
    1395,     5,  1396,    -1,  1397,    -1,   551,  1397,    -1,   551,
     467,  1398,   428,    -1,  1427,    -1,  1427,  1433,    -1,  1396,
      -1,  1398,     5,  1396,    -1,  1394,  1400,  1401,  1402,    -1,
      -1,  1393,    -1,    -1,  1391,    -1,    -1,  1390,    -1,  1404,
      -1,  1403,     6,  1404,    -1,  1405,    -1,  1404,     7,  1405,
      -1,  1406,    -1,     9,  1406,    -1,  1417,    -1,   467,  1403,
     428,    -1,   479,  1466,    -1,   332,  1466,    -1,    -1,   478,
    1410,    -1,  1472,    -1,  1475,    -1,  1471,   658,   467,  1412,
     428,    -1,  1471,   658,  1466,    -1,  1471,   465,   467,  1412,
     428,    -1,  1471,   465,  1466,    -1,  1413,    -1,  1412,     5,
    1413,    -1,  1527,    -1,  1434,    -1,    -1,     9,    -1,  1471,
    1414,   423,    -1,  1471,  1414,   287,    -1,  1471,  1416,  1471,
      -1,  1471,  1414,   425,  1471,     7,  1471,    -1,  1471,   592,
    1409,  1408,    -1,  1471,   408,  1409,  1408,    -1,  1471,   709,
    1409,  1408,    -1,  1471,   409,  1409,  1408,    -1,  1471,  1414,
      10,  1409,  1408,    -1,    14,    -1,    17,    -1,    12,    -1,
      13,    -1,   290,    -1,    10,    -1,   708,    -1,    16,    -1,
      15,    -1,  1415,    -1,  1411,    -1,  1407,    -1,    -1,   621,
      -1,   396,    -1,   512,    -1,  1420,    -1,  1421,    -1,  1423,
      -1,   357,    -1,   357,   467,  1424,   428,    -1,   447,   467,
    1425,  1422,   428,    -1,   508,    -1,   434,   467,  1425,  1422,
     428,    -1,   548,   467,  1425,  1422,   428,    -1,   573,    -1,
     444,    -1,   417,    -1,   394,  1441,   661,  1442,    -1,   394,
      -1,   406,  1441,   661,  1442,    -1,   406,    -1,   406,  1441,
     467,    26,   428,   661,  1442,    -1,   610,    -1,   569,    -1,
     460,    -1,   460,   467,    26,   428,    -1,   460,   467,    26,
       5,    26,   428,    -1,    -1,     5,  1426,    -1,   538,   467,
    1425,   428,    -1,   601,    -1,   337,    -1,   538,    -1,   100,
      -1,    26,    -1,    26,    -1,    26,    -1,    25,   655,   987,
      -1,    25,    -1,   987,    -1,   987,   625,   987,    -1,    25,
     655,   987,    -1,    25,    -1,   987,    -1,   987,   625,   987,
      -1,   987,    -1,    -1,   495,    26,   463,    -1,   495,    26,
       5,    26,   463,    -1,  1432,    -1,   647,  1432,    -1,   987,
    1430,    -1,  1427,   655,   987,  1430,    -1,  1427,   655,    20,
      -1,   987,    -1,    25,    -1,   447,    -1,   993,    -1,    26,
      -1,  1436,    -1,   432,  1438,    -1,   432,  1437,    -1,    -1,
    1441,   661,  1442,    -1,    -1,  1439,   661,  1439,    -1,   617,
      -1,   549,    -1,   626,    -1,   588,    -1,   490,    -1,   506,
      -1,   403,    -1,   403,   467,    26,   428,    -1,   617,    -1,
     549,    -1,   626,    -1,   588,    -1,   490,    -1,   506,    -1,
     403,    -1,   403,   467,    26,   428,    -1,   617,    -1,   549,
      -1,   626,    -1,   588,    -1,   490,    -1,   506,    -1,   403,
      -1,   617,    -1,   549,    -1,   626,    -1,   588,    -1,   490,
      -1,   506,    -1,   403,    -1,   403,   467,    26,   428,    -1,
     987,    -1,   987,   647,   987,    -1,    25,    -1,  1484,   539,
     981,    -1,    -1,  1484,   435,  1335,   473,   631,  1453,  1446,
      -1,    -1,  1484,   435,  1335,   473,   137,   631,  1454,  1447,
      -1,    -1,  1484,   435,  1335,   176,  1454,  1448,    -1,    -1,
    1484,   435,  1335,   177,   137,   631,  1454,  1449,    -1,    -1,
     326,    -1,   325,  1451,    -1,  1452,    -1,  1451,     5,  1452,
      -1,   987,    -1,   987,   655,   987,    -1,    25,   655,   987,
     655,   987,    -1,  1454,    -1,  1324,    -1,  1199,    -1,  1456,
      -1,  1456,    -1,    -1,    -1,   507,  1467,  1457,  1468,  1458,
    1464,  1399,  1462,  1450,    -1,   507,  1467,  1468,  1399,  1462,
      -1,  1461,    -1,  1479,    -1,   507,  1467,  1468,  1464,  1399,
    1462,    -1,    -1,   561,  1418,  1460,    -1,  1344,    -1,   369,
    1463,  1295,    -1,  1344,   369,  1463,  1295,    -1,   987,    -1,
      -1,   589,  1164,    -1,   507,  1467,  1468,  1399,    -1,   467,
     507,  1467,  1468,  1399,   428,    -1,    -1,   621,    -1,   396,
      -1,   512,    -1,  1469,    -1,  1468,     5,  1469,    -1,  1471,
      -1,  1471,   987,    -1,  1471,    -1,  1472,    -1,    19,  1472,
      -1,    18,  1472,    -1,  1473,    -1,  1527,    -1,  1466,    -1,
     647,   987,    -1,   647,   987,   655,   987,    -1,  1472,    21,
    1471,    -1,  1472,  1493,    -1,  1472,    20,  1471,    -1,  1472,
      18,  1471,    -1,  1472,    19,  1471,    -1,  1434,    -1,   520,
      -1,   464,    -1,   612,    -1,    20,    -1,   101,    -1,   624,
     467,  1418,  1471,   428,    -1,   636,   467,  1418,  1471,   428,
      -1,   637,   467,  1418,  1471,   428,    -1,   644,   467,  1418,
    1471,   428,    -1,   532,   467,  1418,  1471,   428,    -1,   987,
     467,  1474,   428,    -1,   573,   467,  1474,   428,    -1,   467,
    1471,   428,    -1,   480,   467,  1494,   428,    -1,  1471,    -1,
    1474,     5,  1471,    -1,  1434,    -1,  1484,   384,  1483,  1478,
    1460,    -1,  1484,   373,  1483,  1478,   286,  1427,  1480,    -1,
    1484,   373,  1483,  1478,  1142,    -1,    -1,   359,  1479,    -1,
      25,    -1,  1142,    -1,    -1,   467,  1481,   428,    -1,  1482,
      -1,  1481,     5,  1482,    -1,   987,    -1,    25,    -1,  1142,
      -1,    -1,   305,  1485,   631,    -1,   988,    -1,  1491,    -1,
    1490,    -1,  1487,    -1,   354,  1488,   661,  1488,    -1,   335,
    1488,   655,  1489,   661,  1489,    -1,   987,    -1,   987,    -1,
     259,   834,    -1,   330,   834,  1492,    -1,   309,    -1,   212,
      -1,   129,    -1,   130,    -1,   131,    -1,   132,    -1,   133,
      -1,   134,    -1,   432,     5,  1441,   661,  1442,    -1,  1527,
       5,  1441,   661,  1442,    -1,   432,  1441,   661,  1442,    -1,
      -1,   643,  1496,  1497,   227,    -1,  1498,    -1,  1497,  1498,
      -1,    33,    -1,  1499,    -1,  1501,    -1,   388,    -1,   342,
      -1,   261,    -1,   620,    -1,   517,    -1,   621,    -1,   522,
      -1,   566,    -1,   622,    -1,   153,    -1,   523,    -1,   652,
      -1,   623,    -1,   355,    -1,   524,    -1,   356,    -1,   653,
      -1,   647,    -1,   312,    -1,   525,    -1,   221,    -1,   424,
      -1,   624,    -1,   699,    -1,   425,    -1,   526,    -1,   527,
      -1,   567,    -1,   568,    -1,   468,    -1,   469,    -1,   390,
      -1,   686,    -1,   654,    -1,   569,    -1,   426,    -1,   571,
      -1,   565,    -1,   357,    -1,   528,    -1,   529,    -1,   427,
      -1,   530,    -1,   428,    -1,   463,    -1,   531,    -1,   625,
      -1,   470,    -1,   429,    -1,     5,    -1,    23,    -1,   430,
      -1,   471,    -1,   431,    -1,   392,    -1,   391,    -1,   358,
      -1,   532,    -1,   472,    -1,   432,    -1,   473,    -1,   572,
      -1,   393,    -1,   573,    -1,   394,    -1,   626,    -1,   627,
      -1,   433,    -1,   628,    -1,   434,    -1,   435,    -1,   436,
      -1,   395,    -1,   533,    -1,   474,    -1,   475,    -1,   359,
      -1,   574,    -1,   318,    -1,   629,    -1,   690,    -1,   437,
      -1,   396,    -1,    21,    -1,   655,    -1,   476,    -1,   360,
      -1,   577,    -1,    99,    -1,   578,    -1,   693,    -1,   438,
      -1,    14,    -1,   534,    -1,   478,    -1,   535,    -1,   364,
      -1,   579,    -1,   439,    -1,   479,    -1,   580,    -1,   480,
      -1,   481,    -1,   402,    -1,   570,    -1,   536,    -1,   136,
      -1,   230,    -1,   482,    -1,   537,    -1,   630,    -1,   538,
      -1,   539,    -1,   631,    -1,   440,    -1,   441,    -1,   483,
      -1,   673,    -1,   128,    -1,   143,    -1,   540,    -1,   403,
      -1,   581,    -1,   582,    -1,   404,    -1,   327,    -1,   442,
      -1,   656,    -1,   583,    -1,   541,    -1,    13,    -1,   542,
      -1,   543,    -1,   484,    -1,   485,    -1,   586,    -1,   587,
      -1,   588,    -1,   695,    -1,   108,    -1,   657,    -1,   658,
      -1,   149,    -1,   544,    -1,   443,    -1,   328,    -1,   700,
      -1,   486,    -1,   444,    -1,   368,    -1,   406,    -1,   702,
      -1,   370,    -1,   632,    -1,   575,    -1,   694,    -1,   545,
      -1,   518,    -1,   407,    -1,   633,    -1,   662,    -1,   445,
      -1,     7,    -1,   464,    -1,   618,    -1,   519,    -1,     6,
      -1,   520,    -1,     8,    -1,   590,    -1,   591,    -1,    12,
      -1,   634,    -1,   592,    -1,   547,    -1,   487,    -1,   635,
      -1,   446,    -1,   593,    -1,   488,    -1,    10,    -1,    50,
      -1,   489,    -1,   594,    -1,   681,    -1,   696,    -1,    19,
      -1,   490,    -1,   148,    -1,    22,    -1,   595,    -1,   491,
      -1,   548,    -1,   549,    -1,    20,    -1,   596,    -1,   597,
      -1,   348,    -1,   598,    -1,   492,    -1,     9,    -1,   447,
      -1,   659,    -1,   704,    -1,   660,    -1,   599,    -1,   467,
      -1,   495,    -1,   496,    -1,   448,    -1,   550,    -1,   377,
      -1,   551,    -1,   497,    -1,   638,    -1,   411,    -1,   552,
      -1,   193,    -1,   144,    -1,   449,    -1,    18,    -1,   147,
      -1,   378,    -1,   450,    -1,   150,    -1,   412,    -1,   349,
      -1,   555,    -1,   379,    -1,   380,    -1,   451,    -1,   498,
      -1,   499,    -1,   639,    -1,   600,    -1,   413,    -1,   601,
      -1,   500,    -1,   452,    -1,   640,    -1,   334,    -1,   414,
      -1,   415,    -1,   501,    -1,   416,    -1,   215,    -1,   382,
      -1,   453,    -1,   502,    -1,   556,    -1,   299,    -1,   641,
      -1,   602,    -1,   642,    -1,   503,    -1,   505,    -1,   506,
      -1,   454,    -1,   507,    -1,   558,    -1,   508,    -1,   455,
      -1,   510,    -1,   603,    -1,   521,    -1,   604,    -1,   605,
      -1,   559,    -1,   337,    -1,   417,    -1,   606,    -1,   511,
      -1,   643,    -1,   338,    -1,   126,    -1,   607,    -1,   608,
      -1,   644,    -1,   456,    -1,   576,    -1,   609,    -1,   154,
      -1,   610,    -1,   611,    -1,   457,    -1,   703,    -1,   661,
      -1,   645,    -1,   458,    -1,   560,    -1,   236,    -1,   383,
      -1,   561,    -1,   512,    -1,   513,    -1,   514,    -1,   459,
      -1,   646,    -1,   612,    -1,   418,    -1,   515,    -1,   460,
      -1,   387,    -1,   613,    -1,   461,    -1,   614,    -1,   562,
      -1,   563,    -1,   564,    -1,   615,    -1,   420,    -1,   616,
      -1,   636,    -1,   637,    -1,   619,    -1,   617,    -1,   516,
      -1,    -1,   228,  1500,  1527,    -1,    -1,   589,  1502,  1164,
      -1,    -1,    -1,   514,  1427,  1504,  1507,  1505,  1506,    -1,
      -1,   188,   981,    -1,   562,  1403,    -1,    89,  1511,   428,
      14,   467,  1512,   428,    -1,    85,  1512,   428,    -1,    86,
    1512,   428,    -1,   619,  1508,    -1,    88,  1512,    -1,    87,
    1512,    -1,  1510,    -1,  1508,     5,  1510,    -1,  1431,    -1,
    1509,    14,  1513,    -1,  1509,    -1,  1511,     5,  1509,    -1,
    1513,    -1,  1512,     5,  1513,    -1,   519,    -1,  1514,    -1,
    1515,    -1,    19,  1515,    -1,    18,  1515,    -1,  1517,    -1,
    1466,    -1,   647,   987,    -1,   647,   987,   655,   987,    -1,
    1516,    -1,  1434,    -1,   520,    -1,   464,    -1,   612,    -1,
     101,    -1,  1515,    21,  1514,    -1,  1515,  1493,    -1,  1515,
      20,  1514,    -1,  1515,    18,  1514,    -1,  1515,    19,  1514,
      -1,   624,   467,  1418,  1514,   428,    -1,   636,   467,  1418,
    1514,   428,    -1,   637,   467,  1418,  1514,   428,    -1,   644,
     467,  1418,  1514,   428,    -1,   532,   467,  1418,  1514,   428,
      -1,   987,   467,  1518,   428,    -1,   573,   467,  1518,   428,
      -1,   467,  1514,   428,    -1,   480,   467,  1494,   428,    -1,
    1527,    -1,  1514,    -1,  1518,     5,  1514,    -1,    -1,   418,
    1173,   592,  1520,  1521,    -1,  1522,    -1,  1521,     5,  1522,
      -1,  1427,   655,  1431,    -1,  1427,   655,    20,    -1,  1524,
      -1,   228,  1525,    -1,  1525,    -1,  1151,    -1,   987,    -1,
    1525,   655,  1526,    -1,    25,   655,  1525,   655,  1526,    -1,
      20,    -1,  1172,    -1,   987,    -1,  1524,    -1,  1524,   457,
    1524,    -1,    34,    -1,    -1,    -1,   563,  1530,   894,  1531,
    1545,   363,    -1,    -1,   694,  1535,    -1,    -1,   697,    -1,
     219,    -1,   315,   982,    -1,   106,   982,    -1,   345,    -1,
     344,    -1,   346,   984,  1532,  1533,    -1,   529,  1535,  1533,
      -1,   937,    -1,   141,    -1,   173,   982,    -1,   894,   602,
       5,   894,   429,    -1,   545,   894,    -1,   302,   982,    -1,
     138,  1540,     8,  1541,  1539,    -1,    -1,   582,   894,    -1,
     987,    -1,   987,    -1,   285,   982,    -1,   288,   982,   661,
     894,     5,   894,    -1,   288,   982,   654,   894,     5,   894,
      -1,    27,    -1,    -1,  1547,    -1,  1548,  1249,    -1,  1546,
      -1,  1547,  1546,    -1,    -1,  1549,  1550,    -1,   713,    -1,
     714,    -1,   715,    -1,   716,    -1,   733,    -1,   755,    -1,
     769,    -1,   770,    -1,   776,    -1,   777,    -1,   796,    -1,
     866,    -1,   867,    -1,   868,    -1,   869,    -1,   880,    -1,
     881,    -1,   882,    -1,   883,    -1,   884,    -1,   885,    -1,
     886,    -1,   938,    -1,   942,    -1,   973,    -1,   994,    -1,
     996,    -1,   999,    -1,  1000,    -1,  1001,    -1,  1002,    -1,
    1015,    -1,  1024,    -1,  1046,    -1,  1047,    -1,  1049,    -1,
    1053,    -1,  1068,    -1,  1069,    -1,  1073,    -1,  1074,    -1,
    1075,    -1,  1076,    -1,  1084,    -1,  1099,    -1,  1112,    -1,
    1123,    -1,  1124,    -1,  1125,    -1,  1136,    -1,  1175,    -1,
    1178,    -1,  1180,    -1,  1186,    -1,  1187,    -1,  1190,    -1,
    1193,    -1,  1196,    -1,  1198,    -1,  1200,    -1,  1203,    -1,
    1210,    -1,  1215,    -1,  1219,    -1,  1220,    -1,  1221,    -1,
    1233,    -1,  1285,    -1,  1286,    -1,  1288,    -1,  1300,    -1,
    1301,    -1,  1319,    -1,  1322,    -1,  1352,    -1,  1354,    -1,
    1444,    -1,  1445,    -1,  1476,    -1,  1477,    -1,  1495,    -1,
    1519,    -1,  1528,    -1,  1529,    -1,  1534,    -1,  1536,    -1,
    1538,    -1,  1542,    -1,  1543,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   979,   979,   982,   985,   991,   997,  1004,  1008,  1008,
    1014,  1037,  1038,  1039,  1040,  1041,  1052,  1058,  1059,  1060,
    1061,  1062,  1067,  1068,  1079,  1082,  1085,  1085,  1089,  1092,
    1093,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1118,  1119,
    1122,  1122,  1137,  1138,  1141,  1147,  1149,  1160,  1162,  1164,
    1166,  1170,  1172,  1234,  1238,  1242,  1242,  1252,  1256,  1259,
    1260,  1267,  1273,  1267,  1286,  1291,  1295,  1286,  1307,  1311,
    1307,  1319,  1324,  1319,  1343,  1350,  1354,  1342,  1380,  1380,
    1384,  1385,  1386,  1391,  1394,  1399,  1403,  1411,  1414,  1414,
    1420,  1424,  1439,  1437,  1455,  1455,  1470,  1470,  1473,  1473,
    1477,  1480,  1480,  1480,  1487,  1488,  1487,  1495,  1495,  1506,
    1506,  1525,  1528,  1531,  1534,  1537,  1540,  1553,  1558,  1558,
    1559,  1559,  1562,  1567,  1567,  1571,  1581,  1595,  1600,  1594,
    1611,  1617,  1625,  1626,  1629,  1629,  1632,  1636,  1641,  1648,
    1648,  1652,  1652,  1653,  1653,  1654,  1654,  1655,  1655,  1656,
    1656,  1664,  1668,  1674,  1678,  1693,  1696,  1699,  1702,  1705,
    1708,  1714,  1725,  1730,  1743,  1747,  1762,  1763,  1767,  1767,
    1771,  1771,  1771,  1772,  1777,  1777,  1780,  1780,  1789,  1790,
    1791,  1794,  1798,  1799,  1799,  1816,  1816,  1816,  1816,  1820,
    1827,  1828,  1831,  1831,  1835,  1836,  1837,  1838,  1843,  1843,
    1849,  1849,  1858,  1855,  1871,  1871,  1873,  1873,  1875,  1877,
    1879,  1881,  1884,  1888,  1888,  1889,  1889,  1893,  1893,  1905,
    1905,  1910,  1914,  1916,  1917,  1920,  1920,  1920,  1924,  1925,
    1926,  1927,  1934,  1935,  1936,  1937,  1940,  1941,  1942,  1943,
    1947,  1952,  1957,  1961,  1964,  1968,  1969,  1970,  1971,  1972,
    1973,  1974,  1975,  1978,  1979,  1980,  2012,  2016,  2018,  2020,
    2020,  2027,  2031,  2031,  2035,  2036,  2037,  2038,  2039,  2040,
    2041,  2047,  2047,  2050,  2052,  2058,  2060,  2066,  2074,  2074,
    2077,  2078,  2079,  2080,  2081,  2082,  2083,  2089,  2092,  2092,
    2105,  2105,  2112,  2113,  2114,  2116,  2117,  2119,  2121,  2122,
    2123,  2124,  2129,  2135,  2141,  2142,  2144,  2146,  2147,  2148,
    2149,  2150,  2151,  2154,  2155,  2162,  2170,  2170,  2178,  2175,
    2190,  2190,  2192,  2192,  2200,  2200,  2203,  2206,  2207,  2212,
    2224,  2228,  2231,  2234,  2235,  2236,  2237,  2238,  2243,  2250,
    2256,  2261,  2266,  2261,  2279,  2281,  2286,  2291,  2291,  2291,
    2295,  2295,  2298,  2298,  2305,  2305,  2312,  2312,  2323,  2341,
    2347,  2371,  2374,  2388,  2390,  2392,  2394,  2396,  2398,  2400,
    2406,  2408,  2412,  2414,  2416,  2418,  2420,  2422,  2424,  2430,
    2445,  2448,  2461,  2462,  2463,  2464,  2465,  2469,  2470,  2471,
    2475,  2480,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,
    2495,  2496,  2497,  2504,  2504,  2509,  2509,  2512,  2518,  2526,
    2532,  2542,  2543,  2551,  2558,  2562,  2572,  2576,  2581,  2586,
    2588,  2591,  2597,  2605,  2618,  2623,  2629,  2634,  2639,  2640,
    2646,  2717,  2723,  2728,  2736,  2736,  2751,  2755,  2762,  2765,
    2773,  2777,  2780,  2786,  2795,  2800,  2808,  2811,  2814,  2819,
    2826,  2831,  2836,  2841,  2851,  2859,  2867,  2872,  2876,  2881,
    2885,  2889,  2896,  2899,  2902,  2906,  2910,  2914,  2918,  2926,
    2936,  2941,  2934,  2957,  2962,  2957,  2979,  2979,  2979,  2982,
    2982,  2982,  2986,  2986,  2986,  2990,  2990,  2990,  2994,  3000,
    3006,  3012,  3018,  3024,  3034,  3034,  3038,  3042,  3043,  3054,
    3055,  3061,  3071,  3081,  3091,  3092,  3095,  3100,  3106,  3110,
    3114,  3117,  3123,  3126,  3129,  3146,  3149,  3155,  3156,  3157,
    3161,  3162,  3163,  3164,  3165,  3167,  3168,  3169,  3171,  3172,
    3176,  3177,  3182,  3186,  3198,  3202,  3197,  3210,  3213,  3227,
    3231,  3237,  3226,  3250,  3251,  3263,  3269,  3263,  3283,  3283,
    3285,  3286,  3290,  3290,  3294,  3294,  3299,  3299,  3306,  3307,
    3311,  3311,  3315,  3315,  3320,  3320,  3327,  3331,  3332,  3333,
    3338,  3338,  3341,  3341,  3345,  3345,  3349,  3349,  3353,  3353,
    3358,  3358,  3363,  3363,  3368,  3368,  3373,  3373,  3389,  3406,
    3407,  3408,  3409,  3410,  3411,  3412,  3415,  3415,  3418,  3420,
    3423,  3426,  3429,  3434,  3439,  3442,  3447,  3452,  3457,  3464,
    3471,  3473,  3479,  3484,  3489,  3494,  3494,  3497,  3503,  3508,
    3511,  3518,  3518,  3520,  3523,  3526,  3531,  3536,  3541,  3548,
    3557,  3557,  3619,  3627,  3628,  3636,  3643,  3643,  3647,  3652,
    3658,  3662,  3666,  3672,  3676,  3680,  3686,  3686,  3694,  3695,
    3699,  3699,  3703,  3704,  3707,  3710,  3710,  3713,  3715,  3715,
    3718,  3720,  3720,  3721,  3723,  3723,  3732,  3739,  3730,  3760,
    3760,  3760,  3763,  3765,  3763,  3772,  3775,  3781,  3792,  3792,
    3796,  3802,  3802,  3806,  3807,  3811,  3821,  3822,  3823,  3826,
    3828,  3833,  3833,  3837,  3836,  3844,  3843,  3850,  3850,  3856,
    3856,  3863,  3863,  3869,  3869,  3875,  3875,  3881,  3881,  3885,
    3885,  3889,  3889,  3893,  3893,  3904,  3908,  3914,  3918,  3923,
    3928,  3933,  3934,  3935,  3939,  3938,  3951,  3956,  3961,  3961,
    3977,  3983,  3984,  3985,  3986,  3989,  3989,  3992,  3999,  4000,
    4001,  4002,  4003,  4004,  4005,  4006,  4007,  4012,  4012,  4014,
    4017,  4017,  4019,  4023,  4026,  4027,  4030,  4030,  4035,  4038,
    4039,  4040,  4041,  4042,  4043,  4044,  4045,  4046,  4047,  4048,
    4049,  4050,  4051,  4052,  4053,  4054,  4055,  4059,  4077,  4077,
    4077,  4104,  4115,  4122,  4128,  4134,  4140,  4151,  4174,  4173,
    4190,  4190,  4194,  4195,  4203,  4204,  4205,  4206,  4207,  4208,
    4215,  4216,  4218,  4219,  4223,  4228,  4229,  4230,  4231,  4232,
    4233,  4234,  4235,  4236,  4237,  4238,  4241,  4243,  4243,  4245,
    4249,  4249,  4258,  4263,  4279,  4285,  4257,  4299,  4313,  4323,
    4312,  4336,  4343,  4343,  4348,  4354,  4362,  4367,  4368,  4371,
    4374,  4374,  4382,  4388,  4399,  4400,  4404,  4408,  4421,  4403,
    4439,  4439,  4453,  4464,  4463,  4475,  4471,  4488,  4485,  4498,
    4498,  4500,  4501,  4503,  4504,  4507,  4508,  4509,  4511,  4516,
    4521,  4527,  4529,  4530,  4533,  4534,  4537,  4539,  4547,  4553,
    4547,  4564,  4565,  4569,  4569,  4576,  4576,  4585,  4588,  4591,
    4594,  4598,  4602,  4603,  4604,  4605,  4606,  4610,  4615,  4615,
    4618,  4644,  4702,  4702,  4705,  4709,  4713,  4756,  4798,  4799,
    4800,  4803,  4817,  4829,  4829,  4834,  4835,  4841,  4901,  4958,
    4963,  4970,  4975,  4983,  4989,  5022,  5025,  5026,  5067,  5110,
    5111,  5115,  5116,  5120,  5173,  5177,  5180,  5186,  5197,  5204,
    5212,  5212,  5215,  5216,  5217,  5218,  5219,  5222,  5225,  5231,
    5234,  5238,  5243,  5251,  5256,  5263,  5266,  5272,  5274,  5274,
    5274,  5278,  5298,  5305,  5312,  5315,  5329,  5336,  5337,  5340,
    5341,  5345,  5351,  5356,  5362,  5363,  5368,  5372,  5372,  5376,
    5377,  5380,  5381,  5385,  5393,  5396,  5402,  5403,  5405,  5407,
    5411,  5411,  5412,  5417,  5425,  5426,  5431,  5432,  5434,  5447,
    5449,  5450,  5452,  5455,  5458,  5461,  5465,  5468,  5471,  5475,
    5479,  5483,  5486,  5490,  5493,  5494,  5495,  5498,  5501,  5504,
    5507,  5510,  5513,  5516,  5532,  5540,  5540,  5542,  5549,  5553,
    5558,  5573,  5571,  5591,  5592,  5596,  5601,  5602,  5606,  5607,
    5609,  5610,  5612,  5612,  5621,  5630,  5630,  5640,  5641,  5646,
    5647,  5650,  5663,  5677,  5682,  5687,  5692,  5702,  5702,  5706,
    5709,  5709,  5711,  5721,  5730,  5737,  5739,  5743,  5746,  5746,
    5750,  5749,  5757,  5756,  5767,  5766,  5773,  5772,  5776,  5775,
    5778,  5778,  5794,  5793,  5815,  5816,  5817,  5818,  5819,  5820,
    5823,  5823,  5829,  5829,  5832,  5832,  5848,  5849,  5850,  5859,
    5871,  5872,  5875,  5876,  5879,  5882,  5882,  5887,  5907,  5912,
    5918,  5919,  5920,  5924,  5925,  5926,  5927,  5931,  5941,  5943,
    5948,  5951,  5956,  5962,  5969,  5976,  5985,  5992,  5999,  6006,
    6013,  6022,  6022,  6024,  6024,  6027,  6028,  6029,  6030,  6031,
    6032,  6033,  6034,  6035,  6036,  6039,  6039,  6042,  6043,  6044,
    6045,  6048,  6048,  6051,  6051,  6054,  6055,  6056,  6057,  6058,
    6059,  6060,  6061,  6063,  6064,  6065,  6066,  6068,  6069,  6070,
    6071,  6073,  6074,  6075,  6076,  6077,  6078,  6079,  6080,  6084,
    6091,  6100,  6112,  6121,  6132,  6136,  6140,  6146,  6111,  6159,
    6162,  6170,  6182,  6184,  6189,  6197,  6207,  6210,  6214,  6222,
    6188,  6231,  6235,  6239,  6243,  6235,  6253,  6254,  6255,  6256,
    6261,  6263,  6266,  6270,  6273,  6280,  6285,  6286,  6287,  6292,
    6293,  6299,  6299,  6299,  6304,  6304,  6304,  6315,  6316,  6322,
    6323,  6335,  6336,  6341,  6342,  6343,  6347,  6350,  6356,  6359,
    6367,  6368,  6374,  6378,  6382,  6388,  6391,  6400,  6403,  6406,
    6409,  6412,  6415,  6418,  6425,  6428,  6435,  6438,  6444,  6447,
    6454,  6457,  6464,  6465,  6470,  6474,  6477,  6483,  6486,  6492,
    6499,  6500,  6504,  6510,  6513,  6520,  6521,  6528,  6531,  6536,
    6547,  6548,  6549,  6550,  6551,  6552,  6553,  6554,  6555,  6558,
    6561,  6567,  6567,  6573,  6573,  6584,  6597,  6607,  6607,  6612,
    6612,  6616,  6620,  6621,  6627,  6628,  6633,  6637,  6644,  6647,
    6654,  6658,  6653,  6667,  6671,  6675,  6682,  6686,  6686,  6699,
    6703,  6703,  6718,  6720,  6722,  6724,  6726,  6728,  6730,  6732,
    6738,  6748,  6755,  6760,  6761,  6765,  6768,  6769,  6772,  6773,
    6774,  6777,  6782,  6789,  6790,  6796,  6808,  6809,  6810,  6813,
    6813,  6818,  6823,  6828,  6829,  6832,  6833,  6838,  6843,  6847,
    6852,  6853,  6857,  6864,  6868,  6869,  6874,  6876,  6880,  6881,
    6885,  6886,  6887,  6888,  6892,  6893,  6898,  6899,  6904,  6905,
    6910,  6911,  6916,  6921,  6922,  6927,  6928,  6932,  6933,  6938,
    6945,  6950,  6955,  6959,  6960,  6965,  6966,  6972,  6974,  6979,
    6980,  6986,  6989,  6992,  6999,  7001,  7015,  7020,  7021,  7024,
    7026,  7033,  7036,  7042,  7046,  7050,  7054,  7057,  7064,  7071,
    7076,  7080,  7081,  7087,  7090,  7101,  7108,  7114,  7117,  7124,
    7131,  7137,  7138,  7144,  7145,  7146,  7149,  7150,  7155,  7155,
    7159,  7167,  7168,  7171,  7174,  7179,  7180,  7185,  7188,  7194,
    7197,  7203,  7206,  7212,  7215,  7222,  7223,  7252,  7253,  7258,
    7266,  7271,  7274,  7277,  7280,  7286,  7287,  7291,  7294,  7297,
    7298,  7303,  7306,  7309,  7312,  7315,  7318,  7321,  7324,  7329,
    7335,  7336,  7337,  7338,  7339,  7341,  7342,  7344,  7345,  7350,
    7353,  7357,  7363,  7364,  7365,  7366,  7378,  7379,  7380,  7384,
    7385,  7390,  7392,  7393,  7394,  7396,  7397,  7398,  7399,  7401,
    7402,  7404,  7405,  7407,  7408,  7409,  7410,  7412,  7416,  7417,
    7423,  7425,  7426,  7427,  7428,  7433,  7437,  7441,  7445,  7452,
    7456,  7457,  7461,  7468,  7472,  7473,  7482,  7491,  7492,  7493,
    7497,  7500,  7505,  7510,  7515,  7523,  7527,  7531,  7532,  7533,
    7538,  7541,  7544,  7558,  7572,  7585,  7586,  7590,  7590,  7590,
    7590,  7590,  7590,  7591,  7594,  7599,  7599,  7599,  7599,  7599,
    7599,  7601,  7604,  7610,  7610,  7610,  7610,  7610,  7610,  7610,
    7611,  7611,  7611,  7611,  7611,  7611,  7611,  7611,  7614,  7615,
    7616,  7619,  7628,  7628,  7634,  7634,  7641,  7641,  7647,  7647,
    7655,  7656,  7657,  7660,  7660,  7663,  7664,  7665,  7676,  7679,
    7685,  7690,  7697,  7710,  7711,  7708,  7729,  7740,  7743,  7748,
    7760,  7763,  7767,  7770,  7771,  7777,  7780,  7781,  7790,  7799,
    7804,  7805,  7806,  7807,  7814,  7817,  7823,  7826,  7836,  7845,
    7848,  7851,  7857,  7863,  7866,  7869,  7872,  7878,  7880,  7882,
    7884,  7886,  7888,  7889,  7890,  7891,  7892,  7893,  7894,  7896,
    7898,  7900,  7902,  7904,  7906,  7908,  7909,  7914,  7915,  7922,
    7925,  7934,  7938,  7945,  7945,  7949,  7949,  7954,  7954,  7958,
    7958,  7962,  7968,  7968,  7971,  7971,  7977,  7984,  7985,  7986,
    7990,  7991,  7994,  7995,  7999,  8005,  8015,  8016,  8024,  8025,
    8026,  8027,  8028,  8029,  8033,  8034,  8035,  8039,  8039,  8051,
    8052,  8056,  8057,  8058,  8059,  8060,  8061,  8062,  8063,  8064,
    8065,  8066,  8067,  8068,  8069,  8070,  8071,  8072,  8073,  8074,
    8075,  8076,  8077,  8078,  8079,  8080,  8081,  8082,  8083,  8084,
    8085,  8086,  8087,  8088,  8089,  8090,  8091,  8092,  8093,  8094,
    8095,  8096,  8097,  8098,  8099,  8100,  8101,  8102,  8103,  8104,
    8105,  8106,  8107,  8108,  8109,  8110,  8111,  8112,  8113,  8114,
    8115,  8116,  8117,  8118,  8119,  8120,  8121,  8122,  8123,  8124,
    8125,  8126,  8127,  8128,  8129,  8130,  8131,  8132,  8133,  8134,
    8135,  8136,  8137,  8138,  8139,  8140,  8141,  8142,  8143,  8144,
    8145,  8146,  8147,  8148,  8149,  8150,  8151,  8152,  8153,  8154,
    8155,  8156,  8157,  8158,  8159,  8160,  8161,  8162,  8163,  8164,
    8165,  8166,  8167,  8168,  8169,  8170,  8171,  8172,  8173,  8174,
    8175,  8176,  8177,  8178,  8179,  8180,  8181,  8182,  8183,  8184,
    8185,  8186,  8187,  8188,  8189,  8190,  8191,  8192,  8193,  8194,
    8195,  8196,  8197,  8198,  8199,  8200,  8201,  8202,  8203,  8204,
    8205,  8206,  8207,  8208,  8209,  8210,  8211,  8212,  8213,  8214,
    8215,  8216,  8217,  8218,  8219,  8220,  8221,  8222,  8223,  8224,
    8225,  8226,  8227,  8228,  8229,  8230,  8231,  8232,  8233,  8234,
    8235,  8236,  8237,  8238,  8239,  8240,  8241,  8242,  8243,  8244,
    8245,  8246,  8247,  8248,  8249,  8250,  8251,  8252,  8253,  8254,
    8255,  8256,  8257,  8258,  8259,  8260,  8261,  8262,  8263,  8264,
    8265,  8266,  8267,  8268,  8269,  8270,  8271,  8272,  8273,  8274,
    8275,  8276,  8277,  8278,  8279,  8280,  8281,  8282,  8283,  8284,
    8285,  8286,  8287,  8288,  8289,  8290,  8291,  8292,  8293,  8294,
    8295,  8296,  8297,  8298,  8299,  8300,  8301,  8302,  8303,  8304,
    8305,  8306,  8307,  8308,  8309,  8310,  8311,  8312,  8313,  8314,
    8315,  8316,  8317,  8318,  8319,  8320,  8321,  8322,  8323,  8324,
    8325,  8326,  8327,  8328,  8329,  8330,  8331,  8332,  8333,  8334,
    8335,  8336,  8337,  8338,  8339,  8340,  8341,  8342,  8343,  8344,
    8345,  8346,  8347,  8348,  8349,  8350,  8351,  8352,  8353,  8354,
    8355,  8356,  8357,  8358,  8359,  8360,  8361,  8362,  8363,  8364,
    8365,  8366,  8367,  8368,  8369,  8370,  8371,  8372,  8373,  8374,
    8375,  8383,  8383,  8390,  8390,  8478,  8482,  8478,  8491,  8495,
    8501,  8509,  8519,  8529,  8541,  8544,  8563,  8589,  8592,  8598,
    8601,  8606,  8609,  8617,  8625,  8638,  8641,  8649,  8652,  8655,
    8663,  8667,  8670,  8673,  8676,  8680,  8681,  8682,  8683,  8684,
    8690,  8691,  8692,  8693,  8694,  8695,  8696,  8697,  8698,  8699,
    8700,  8701,  8702,  8703,  8707,  8713,  8714,  8722,  8722,  8730,
    8730,  8734,  8738,  8753,  8773,  8775,  8781,  8782,  8783,  8784,
    8794,  8795,  8796,  8801,  8827,  8883,  8897,  8900,  8896,  8919,
    8919,  8925,  8926,  8929,  8930,  8931,  8932,  8933,  8934,  8935,
    8941,  8953,  8956,  8961,  8965,  8970,  8974,  8979,  8983,  8986,
    8990,  8993,  8998,  9002,  9013,  9019,  9019,  9020,  9021,  9028,
    9038,  9038,  9040,  9041,  9042,  9043,  9044,  9045,  9046,  9047,
    9048,  9049,  9050,  9051,  9052,  9053,  9054,  9055,  9056,  9057,
    9058,  9059,  9060,  9061,  9062,  9063,  9064,  9065,  9066,  9067,
    9068,  9069,  9070,  9071,  9072,  9073,  9074,  9075,  9076,  9077,
    9078,  9079,  9080,  9081,  9082,  9083,  9084,  9085,  9086,  9087,
    9088,  9089,  9090,  9091,  9092,  9093,  9094,  9095,  9096,  9097,
    9098,  9099,  9100,  9101,  9102,  9103,  9104,  9105,  9106,  9107,
    9108,  9109,  9110,  9111,  9112,  9113,  9114,  9115,  9116,  9117,
    9118,  9119,  9120,  9121,  9122,  9123,  9124,  9125,  9126,  9127,
    9128
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
  "CONCAT_PIPES", "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", 
  "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", "ALTER_INDEX", 
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
  "FIELD_TOUCHED", "FINISH_REPORT", "INFACC", "INPUT_NO_WRAP", 
  "LOCKMODEPAGE", "SETPMOFF", "UNCONSTRAINED", "PAGE_TRAILER", "SETPMON", 
  "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", "CONTINUE_FOR", "CREATE_DB", 
  "CREATE_TABLE", "DEFAULT_NULL", "DELETE_USING", "DISPLAY_FORM", 
  "END_FUNCTION", "EXIT_DISPLAY", "EXIT_FOREACH", "EXIT_PROGRAM", 
  "INFCOLS", "LOCKMODEROW", "ON_EVERY_ROW", "OPEN_SESSION", 
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
  "CHAR", "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", 
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
  "COMMENT", "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", "DECLARE", 
  "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", "FOREIGN", 
  "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", "NUMERIC", 
  "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", "REVERSE", 
  "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", "UPSHIFT", 
  "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", "KW_FALSE", 
  "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", "BOTTOM", "COLUMN", 
  "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", "END_IF", 
  "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", "HAVING", 
  "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", "MODIFY", 
  "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", "OUTPUT", 
  "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", "SCHEMA", 
  "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", 
  "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", 
  "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", 
  "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", 
  "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", 
  "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", 
  "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", 
  "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", 
  "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", 
  "BOLD", "BYTE", "FCALL", "CASE", "CYAN", "DATE", "DESC", "KWDOWN", 
  "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", 
  "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", 
  "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", 
  "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", 
  "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", 
  "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", 
  "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", 
  "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", 
  "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", 
  "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "KWUP", "FONT_NAME", 
  "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
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
  "$accept", "pause_screen_on_cmd", "pause_screen_off_cmd", 
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
  "dtype2", "@39", "@40", "dtype", "like_var", "tab_name", "col_name", 
  "datetime_qual", "interval_qual", "dtime_start", "@41", "dtime_val", 
  "dtime_end", "@42", "opt_frac", "opt_unit_size", "dtfrac", "int_start", 
  "@43", "int_start_unit", "int_end", "op_equal", "dim_section", "@44", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@45", "@46", 
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
  "numeric_time_unit_small", "numeric_time_unit_big", 
  "field_name_list_as_struct", "for_cmd", "@67", "@68", "for_step", 
  "foreach_cmd", "@69", "@70", "@71", "opt_foreach_using_part", 
  "formhandler_def", "@72", "@73", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@74", "@75", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@76", "@77", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@78", "@79", "@80", "@81", "@82", "free_cmd", "line_no", 
  "file_name", "a_number", "coords", "display_coords", 
  "field_name_as_struct", "cursor_name", "fetch_cursor_name", "win_name", 
  "open_win_name", "form_name", "open_form_name", "opt_help_no", 
  "identifier", "ident_or_var", "ident_p2", "var_or_string", 
  "field_name2_as_struct", "cvariable", "real_number", "goto_cmd", 
  "label_goto", "check_menu_cmd", "menu_item_list", "menu_item", 
  "uncheck_menu_cmd", "disable_cmd", "enable_cmd", "msg_box_cmd", "@83", 
  "op_disable_msg", "gm_disable_msg", "op_returning_msg", 
  "gm_returning_msg", "op_caption", "gm_caption", "op_icon", "gm_icon", 
  "op_buttons", "gm_buttons", "op_def_but", "if_cmd", "@84", "@85", 
  "op_else", "@86", "@87", "@88", "import_m", "module_import", "init_cmd", 
  "@89", "init_tab_list", "init_tab", "init_table_name", "end_input", 
  "opt_defs", "field_commands", "field_command", "@90", "@91", "@92", 
  "@93", "@94", "@95", "@96", "@97", "@98", "@99", "@100", 
  "bef_field_list_as_struct", "aft_field_list_as_struct", 
  "next_field_cmd", "next_form_cmd", "next_field", "input_cmd", "@101", 
  "inp_rest", "@102", "scroll_cmd", "up_or_down", "op_help", 
  "input_array_attributes", "input_array_attributes_int", 
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
  "idx_name", "authorization_identifier", "col_arr", "column_name", 
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
  "var_ident_ibind_ss", "whenever_cmd", "while_cmd", "@176", "@177", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list_as_struct", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@178", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1696,  1697,  1698,  1604,  1644,  1599,  1536,  1619,
    1415,  1522,  1518,  1433,  1594,  1333,  1390,  1464,  1630,  1617,
    1523,  1550,  1618,  1397,  1699,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1000,  1001,  1002,  1003,  1004,
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
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1334,  1335,
    1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,
    1386,  1387,  1388,  1389,  1391,  1392,  1393,  1394,  1395,  1396,
    1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,
    1408,  1409,  1410,  1411,  1412,  1413,  1414,  1416,  1417,  1418,
    1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,
    1429,  1430,  1431,  1432,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1465,  1466,  1467,  1468,  1469,  1470,
    1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,  1516,  1517,  1519,  1520,  1521,
    1524,  1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,
    1534,  1535,  1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,
    1545,  1546,  1547,  1548,  1549,  1551,  1552,  1553,  1554,  1555,
    1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,
    1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1595,  1596,
    1597,  1598,  1600,  1601,  1602,  1603,  1605,  1606,  1607,  1608,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1620,  1621,
    1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,  1631,  1632,
    1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,
    1643,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   712,   713,   714,   715,   716,   717,   717,   718,   718,
     719,   720,   720,   720,   720,   720,   720,   721,   721,   721,
     721,   721,   722,   722,   723,   723,   725,   724,   724,   726,
     726,   727,   727,   727,   727,   727,   727,   727,   727,   727,
     727,   727,   727,   727,   727,   727,   727,   727,   728,   728,
     730,   729,   731,   731,   732,   732,   732,   732,   732,   732,
     732,   732,   732,   733,   734,   735,   734,   734,   734,   734,
     734,   736,   737,   734,   738,   739,   740,   734,   741,   742,
     734,   743,   744,   734,   745,   746,   747,   734,   748,   748,
     749,   749,   749,   750,   750,   751,   751,   752,   753,   753,
     754,   754,   756,   755,   757,   755,   758,   758,   759,   759,
     760,   761,   762,   761,   763,   764,   763,   766,   765,   768,
     767,   769,   769,   769,   769,   769,   769,   770,   771,   771,
     772,   772,   773,   774,   774,   775,   776,   778,   779,   777,
     780,   780,   781,   781,   782,   782,   783,   783,   783,   784,
     784,   786,   785,   787,   785,   788,   785,   789,   785,   790,
     785,   791,   791,   792,   792,   793,   793,   793,   793,   793,
     793,   794,   795,   795,   796,   796,   797,   797,   798,   798,
     800,   801,   799,   799,   802,   802,   804,   803,   805,   805,
     805,   805,   805,   806,   805,   807,   807,   807,   807,   808,
     809,   809,   810,   810,   811,   811,   811,   811,   813,   812,
     814,   812,   815,   812,   816,   816,   817,   817,   818,   819,
     819,   819,   820,   822,   821,   823,   821,   824,   821,   825,
     825,   826,   827,   828,   828,   830,   831,   829,   832,   832,
     832,   832,   832,   832,   832,   832,   832,   832,   832,   832,
     832,   832,   832,   832,   832,   832,   832,   832,   832,   832,
     832,   832,   832,   832,   832,   832,   833,   834,   835,   836,
     836,   837,   839,   838,   840,   840,   840,   840,   840,   840,
     840,   842,   841,   843,   843,   844,   844,   845,   847,   846,
     848,   848,   848,   848,   848,   848,   848,   849,   850,   850,
     852,   851,   853,   853,   853,   853,   853,   853,   853,   853,
     853,   853,   853,   853,   853,   853,   853,   853,   853,   853,
     853,   853,   853,   853,   853,   854,   856,   855,   857,   855,
     859,   858,   860,   858,   861,   861,   862,   863,   863,   864,
     865,   865,   865,   865,   865,   865,   865,   865,   866,   867,
     868,   870,   871,   869,   872,   872,   873,   874,   874,   874,
     875,   875,   877,   876,   878,   876,   879,   876,   880,   881,
     882,   883,   883,   884,   884,   884,   884,   884,   884,   884,
     884,   884,   885,   885,   885,   885,   885,   885,   885,   885,
     886,   886,   887,   887,   887,   887,   887,   887,   887,   887,
     887,   887,   888,   888,   888,   888,   888,   888,   888,   888,
     888,   888,   888,   889,   889,   890,   890,   891,   891,   892,
     892,   893,   893,   894,   895,   895,   896,   896,   896,   896,
     896,   896,   897,   897,   898,   898,   898,   898,   899,   899,
     900,   901,   901,   901,   902,   901,   903,   903,   904,   904,
     905,   905,   905,   905,   906,   906,   907,   907,   907,   907,
     907,   907,   907,   907,   908,   909,   910,   910,   910,   910,
     910,   910,   911,   911,   911,   911,   911,   911,   911,   912,
     914,   915,   913,   916,   917,   913,   919,   920,   918,   921,
     922,   918,   923,   924,   918,   925,   926,   918,   918,   918,
     918,   918,   918,   918,   927,   927,   928,   929,   929,   929,
     929,   929,   929,   929,   929,   929,   930,   930,   931,   931,
     931,   931,   932,   932,   932,   933,   933,   934,   934,   934,
     935,   935,   935,   935,   935,   935,   935,   935,   935,   935,
     936,   936,   937,   937,   939,   940,   938,   941,   941,   943,
     944,   945,   942,   946,   946,   948,   949,   947,   950,   950,
     951,   951,   952,   952,   954,   953,   955,   953,   956,   956,
     957,   957,   959,   958,   960,   958,   961,   962,   962,   962,
     963,   963,   964,   964,   965,   965,   966,   966,   968,   967,
     969,   967,   970,   967,   971,   967,   972,   967,   973,   974,
     974,   974,   974,   974,   974,   974,   975,   975,   976,   977,
     978,   979,   979,   979,   979,   979,   979,   979,   979,   980,
     981,   982,   983,   984,   985,   986,   986,   987,   988,   989,
     989,   990,   990,   991,   991,   991,   991,   991,   991,   992,
     993,   993,   994,   995,   995,   996,   997,   997,   998,   999,
    1000,  1000,  1000,  1001,  1001,  1001,  1003,  1002,  1004,  1004,
    1005,  1005,  1006,  1006,  1007,  1008,  1008,  1009,  1010,  1010,
    1011,  1012,  1012,  1013,  1014,  1014,  1016,  1017,  1015,  1018,
    1019,  1018,  1020,  1021,  1018,  1022,  1022,  1023,  1025,  1024,
    1024,  1026,  1026,  1027,  1027,  1028,  1029,  1029,  1029,  1030,
    1030,  1031,  1031,  1033,  1032,  1034,  1032,  1035,  1032,  1036,
    1032,  1037,  1032,  1038,  1032,  1039,  1032,  1040,  1032,  1041,
    1032,  1042,  1032,  1043,  1032,  1044,  1044,  1045,  1045,  1046,
    1047,  1048,  1048,  1048,  1050,  1049,  1051,  1051,  1052,  1051,
    1053,  1054,  1054,  1054,  1054,  1055,  1055,  1056,  1057,  1057,
    1057,  1057,  1057,  1057,  1057,  1057,  1057,  1059,  1058,  1058,
    1061,  1060,  1062,  1063,  1064,  1064,  1065,  1065,  1066,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1068,  1070,  1071,
    1069,  1072,  1072,  1073,  1074,  1075,  1076,  1076,  1078,  1077,
    1079,  1079,  1080,  1080,  1081,  1081,  1081,  1081,  1081,  1081,
    1082,  1082,  1083,  1083,  1084,  1085,  1085,  1085,  1085,  1085,
    1085,  1085,  1085,  1085,  1085,  1085,  1086,  1087,  1087,  1088,
    1089,  1089,  1091,  1092,  1093,  1094,  1090,  1095,  1097,  1098,
    1096,  1099,  1100,  1100,  1101,  1101,  1102,  1103,  1103,  1104,
    1106,  1105,  1107,  1107,  1107,  1107,  1109,  1110,  1111,  1108,
    1113,  1112,  1114,  1116,  1115,  1117,  1115,  1118,  1115,  1119,
    1119,  1120,  1120,  1121,  1121,  1122,  1122,  1122,  1123,  1124,
    1125,  1126,  1126,  1126,  1127,  1127,  1128,  1128,  1130,  1131,
    1129,  1132,  1132,  1134,  1133,  1135,  1133,  1136,  1137,  1137,
    1137,  1137,  1138,  1138,  1138,  1138,  1138,  1139,  1140,  1140,
    1141,  1142,  1143,  1143,  1144,  1145,  1145,  1145,  1145,  1145,
    1145,  1146,  1147,  1148,  1148,  1149,  1149,  1150,  1151,  1152,
    1152,  1153,  1153,  1154,  1155,  1156,  1156,  1156,  1156,  1156,
    1156,  1157,  1157,  1158,  1159,  1159,  1160,  1160,  1161,  1161,
    1162,  1162,  1163,  1163,  1163,  1163,  1163,  1164,  1164,  1165,
    1165,  1166,  1166,  1167,  1168,  1169,  1169,  1170,  1171,  1171,
    1171,  1172,  1173,  1173,  1174,  1174,  1175,  1176,  1176,  1177,
    1177,  1178,  1179,  1180,  1181,  1181,  1182,  1183,  1183,  1184,
    1184,  1185,  1185,  1186,  1187,  1187,  1188,  1188,  1188,  1188,
    1189,  1189,  1189,  1190,  1191,  1191,  1192,  1192,  1192,  1193,
    1194,  1194,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1196,  1197,  1197,  1198,  1198,  1198,
    1199,  1201,  1200,  1202,  1202,  1203,  1204,  1204,  1205,  1205,
    1206,  1206,  1208,  1207,  1209,  1211,  1210,  1212,  1212,  1213,
    1213,  1214,  1214,  1215,  1215,  1215,  1215,  1216,  1216,  1217,
    1218,  1218,  1219,  1220,  1221,  1222,  1223,  1223,  1224,  1224,
    1226,  1225,  1227,  1225,  1228,  1225,  1229,  1225,  1230,  1225,
    1231,  1225,  1232,  1225,  1233,  1233,  1233,  1233,  1233,  1233,
    1235,  1234,  1236,  1236,  1238,  1237,  1237,  1237,  1237,  1237,
    1239,  1239,  1240,  1240,  1241,  1242,  1242,  1243,  1244,  1245,
    1246,  1246,  1246,  1247,  1247,  1247,  1247,  1248,  1249,  1249,
    1250,  1250,  1251,  1252,  1252,  1252,  1252,  1252,  1252,  1252,
    1252,  1253,  1253,  1254,  1254,  1255,  1255,  1255,  1255,  1255,
    1255,  1255,  1255,  1255,  1255,  1256,  1256,  1257,  1257,  1257,
    1257,  1258,  1258,  1259,  1259,  1260,  1260,  1260,  1260,  1260,
    1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,
    1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1261,
    1261,  1261,  1263,  1264,  1265,  1266,  1267,  1268,  1262,  1269,
    1269,  1270,  1271,  1271,  1273,  1274,  1275,  1276,  1277,  1278,
    1272,  1279,  1281,  1282,  1283,  1280,  1284,  1284,  1284,  1284,
    1285,  1285,  1285,  1285,  1285,  1286,  1287,  1287,  1287,  1288,
    1288,  1290,  1291,  1289,  1292,  1293,  1289,  1294,  1294,  1295,
    1295,  1296,  1296,  1297,  1297,  1297,  1298,  1298,  1299,  1299,
    1300,  1300,  1301,  1301,  1301,  1302,  1302,  1303,  1303,  1303,
    1303,  1303,  1303,  1303,  1304,  1304,  1305,  1305,  1306,  1306,
    1307,  1307,  1308,  1308,  1309,  1310,  1310,  1311,  1311,  1312,
    1313,  1313,  1314,  1315,  1315,  1316,  1316,  1317,  1317,  1318,
    1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,
    1319,  1320,  1320,  1321,  1321,  1322,  1323,  1325,  1324,  1327,
    1326,  1326,  1328,  1328,  1329,  1329,  1330,  1330,  1331,  1331,
    1333,  1334,  1332,  1335,  1336,  1336,  1337,  1338,  1337,  1339,
    1340,  1339,  1341,  1341,  1341,  1341,  1341,  1341,  1341,  1341,
    1342,  1343,  1344,  1345,  1345,  1346,  1347,  1347,  1348,  1348,
    1348,  1349,  1350,  1351,  1351,  1352,  1353,  1353,  1353,  1355,
    1354,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,
    1356,  1356,  1356,  1357,  1358,  1358,  1359,  1359,  1360,  1360,
    1361,  1361,  1361,  1361,  1362,  1362,  1363,  1363,  1364,  1364,
    1365,  1365,  1366,  1367,  1367,  1368,  1368,  1369,  1369,  1370,
    1371,  1372,  1373,  1374,  1374,  1375,  1375,  1376,  1376,  1377,
    1377,  1378,  1378,  1378,  1379,  1379,  1380,  1381,  1381,  1382,
    1382,  1383,  1383,  1384,  1384,  1384,  1384,  1384,  1385,  1386,
    1387,  1388,  1388,  1389,  1389,  1390,  1391,  1392,  1392,  1393,
    1394,  1395,  1395,  1396,  1396,  1396,  1397,  1397,  1398,  1398,
    1399,  1400,  1400,  1401,  1401,  1402,  1402,  1403,  1403,  1404,
    1404,  1405,  1405,  1406,  1406,  1407,  1407,  1408,  1408,  1409,
    1410,  1411,  1411,  1411,  1411,  1412,  1412,  1413,  1413,  1414,
    1414,  1415,  1415,  1415,  1415,  1415,  1415,  1415,  1415,  1415,
    1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1416,  1417,
    1417,  1417,  1418,  1418,  1418,  1418,  1419,  1419,  1419,  1420,
    1420,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1422,  1422,
    1423,  1423,  1423,  1423,  1423,  1424,  1425,  1426,  1427,  1427,
    1427,  1427,  1428,  1428,  1428,  1428,  1429,  1430,  1430,  1430,
    1431,  1431,  1432,  1432,  1432,  1433,  1434,  1434,  1434,  1434,
    1434,  1435,  1436,  1437,  1437,  1438,  1438,  1439,  1439,  1439,
    1439,  1439,  1439,  1439,  1439,  1440,  1440,  1440,  1440,  1440,
    1440,  1440,  1440,  1441,  1441,  1441,  1441,  1441,  1441,  1441,
    1442,  1442,  1442,  1442,  1442,  1442,  1442,  1442,  1443,  1443,
    1443,  1444,  1446,  1445,  1447,  1445,  1448,  1445,  1449,  1445,
    1450,  1450,  1450,  1451,  1451,  1452,  1452,  1452,  1453,  1453,
    1454,  1454,  1455,  1457,  1458,  1456,  1459,  1460,  1460,  1461,
    1462,  1462,  1462,  1462,  1462,  1463,  1464,  1464,  1465,  1466,
    1467,  1467,  1467,  1467,  1468,  1468,  1469,  1469,  1470,  1471,
    1471,  1471,  1472,  1472,  1472,  1472,  1472,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1474,  1474,  1475,
    1476,  1477,  1477,  1478,  1478,  1479,  1479,  1480,  1480,  1481,
    1481,  1482,  1483,  1483,  1484,  1484,  1485,  1486,  1486,  1486,
    1487,  1487,  1488,  1489,  1490,  1491,  1492,  1492,  1493,  1493,
    1493,  1493,  1493,  1493,  1494,  1494,  1494,  1496,  1495,  1497,
    1497,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1500,  1499,  1502,  1501,  1504,  1505,  1503,  1506,  1506,
    1506,  1507,  1507,  1507,  1507,  1507,  1507,  1508,  1508,  1509,
    1510,  1511,  1511,  1512,  1512,  1513,  1513,  1514,  1514,  1514,
    1515,  1515,  1515,  1515,  1515,  1515,  1515,  1515,  1515,  1515,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1517,  1518,  1518,  1520,  1519,  1521,
    1521,  1522,  1522,  1523,  1524,  1524,  1525,  1525,  1525,  1525,
    1526,  1526,  1526,  1527,  1527,  1528,  1530,  1531,  1529,  1532,
    1532,  1533,  1533,  1534,  1534,  1534,  1534,  1534,  1534,  1534,
    1535,  1536,  1536,  1537,  1537,  1538,  1538,  1539,  1539,  1540,
    1541,  1542,  1543,  1543,  1544,  1545,  1545,  1546,  1547,  1547,
    1549,  1548,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550
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
       4,     1,     3,     3,     3,     1,     0,     2,     1,     0,
       1,     1,     2,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     1,     3,     1,     3,     2,
       4,     1,     1,     1,     0,     4,     5,     6,     0,    10,
       3,     2,     2,     1,     1,     0,     2,     1,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     0,     3,     1,
       0,     3,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     1,     1,     2,     2,     2,     3,     4,     0,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     0,     0,     0,     0,    13,     1,     0,     0,
       6,     2,     1,     2,     2,     2,     1,     1,     2,     1,
       0,     3,     2,     1,     1,     1,     0,     0,     0,    14,
       0,     5,     1,     0,     3,     0,     7,     0,     5,     1,
       2,     0,     1,     1,     1,     0,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     3,     1,     1,     0,     0,
       7,     1,     2,     0,     3,     0,     4,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     5,     8,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     2,     2,     3,
       6,     1,     3,     1,     1,     1,     3,     6,     9,     1,
       1,     1,     1,     2,     0,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     3,     2,     0,     1,
       1,     4,     1,     3,     1,     3,     7,     0,     7,     0,
       6,     3,     1,     3,     1,     2,     5,     0,     7,     0,
       2,     0,     1,     5,     2,     5,     0,     5,     6,     4,
       0,     1,     1,     4,     0,     2,     0,     5,     4,     2,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     2,     4,     2,
       1,     0,    11,     0,     2,     5,     0,     1,     0,     2,
       1,     2,     0,     3,     1,     0,     4,     0,     2,     1,
       3,     1,     1,     3,     4,     4,     2,     1,     1,     1,
       0,     1,     7,     2,     2,     2,     2,     2,     1,     2,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     1,     0,     4,     1,     2,     2,     2,
       0,     1,     1,     2,     2,     0,     2,     3,     3,     5,
       0,     2,     4,     1,     1,     1,     1,     1,     0,     1,
       1,     3,     2,     5,     2,     5,     5,     5,     5,     5,
       5,     0,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       1,     1,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     0,
       3,     2,     0,     0,     0,     0,     0,     0,    15,     0,
       2,     2,     0,     1,     0,     0,     0,     0,     0,     0,
      15,     2,     0,     0,     0,    10,     0,     1,     3,     3,
       2,     4,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     0,     7,     0,     0,     8,     7,     2,     0,
       1,     1,     3,     2,     2,     1,     1,     3,     1,     1,
       2,     1,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     1,     3,     1,     3,
       2,     4,     1,     3,     1,     2,     4,     1,     3,     1,
       1,     1,     2,     2,     4,     2,     4,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     6,
       6,     0,     1,     0,     1,     2,     1,     0,     5,     0,
       5,     1,     0,     3,     1,     3,     1,     3,     1,     1,
       0,     0,     5,     1,     2,     1,     0,     0,     3,     0,
       0,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     3,     3,     1,     3,     2,     1,     1,     0,     1,
       1,     1,     1,     0,     1,     3,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     0,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     0,     3,     1,     3,     1,     3,
       1,     1,     6,     0,     3,     1,     3,     0,     1,     4,
       5,     2,     1,     1,     4,     1,     3,     4,     4,     1,
       3,     1,     1,     1,     2,     1,     4,     0,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     4,     3,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     0,     2,     1,
       1,     5,     3,     5,     3,     1,     3,     1,     1,     0,
       1,     3,     3,     3,     6,     4,     4,     4,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     1,     5,     5,     1,     1,     1,     4,     1,
       4,     1,     7,     1,     1,     1,     4,     6,     0,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     1,     1,     3,     1,     0,     3,     5,
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
       1,     1,     1,     1,     3,     1,     0,     0,     6,     0,
       2,     0,     1,     1,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     5,     2,     2,     5,     0,     2,     1,
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
     800,     0,  2115,     0,     0,     0,   850,   180,     0,   826,
     829,   178,   183,   804,     0,   798,   801,   802,   805,   808,
     809,   807,   846,   847,   849,   806,   135,   132,     0,   128,
     130,   129,   133,  2144,   687,   627,   300,  1600,  1598,   844,
     176,   186,   845,   179,     1,   810,   803,   848,   127,   131,
     134,     0,     0,   606,     0,     0,   177,   853,   919,   607,
     854,   855,   851,   639,   911,     0,   912,   920,   918,   186,
     181,   199,     0,   184,   200,   235,     0,   831,  1204,     0,
       0,   830,   136,  1192,   838,     0,     0,   822,   824,   821,
     823,   799,   811,   812,   832,   815,   816,   817,   820,   818,
     819,   825,     0,  1599,   913,   852,     0,     0,   927,   925,
     926,   915,   914,   298,   186,  1128,   193,   187,   186,   192,
     232,     0,   686,     0,     0,     0,     0,   176,   555,   888,
     813,     0,   332,   318,   202,   304,   269,   288,   309,   311,
     308,     0,   330,     0,   317,   310,   314,   320,   319,   186,
     321,   301,   324,   302,   303,   924,   923,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     933,     0,   515,   507,    16,   514,   919,    15,     0,   931,
       0,   299,     0,   185,  1129,   182,     0,   199,   201,   265,
     204,   259,   260,   248,   225,   256,   202,   240,   227,   269,
     288,   246,   249,   244,     0,   223,     0,   255,   247,   252,
     258,   257,   186,   261,   186,   238,   239,   236,   264,     0,
       0,     0,     0,   839,   176,   176,     0,     0,   203,     0,
       0,   322,     0,     0,   323,     0,     0,     0,     0,     0,
       0,     0,   267,     0,   921,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   521,     0,     0,
       0,   640,   434,   436,  1199,     0,     0,     0,  1565,     0,
     428,     0,     0,     0,   427,     0,   444,   517,     0,     0,
       0,     0,     0,   520,     0,   393,   392,   399,   440,   437,
     394,   395,   397,   398,   435,   438,   443,   516,   489,   486,
     495,   492,     0,     0,    17,    18,    19,    20,    21,     0,
      14,   480,     0,     0,   929,     0,   188,   191,   189,   190,
       0,   196,   195,   194,   197,   205,   206,   207,   210,   186,
       0,     0,   186,   262,   263,     0,     0,   186,     0,     0,
       0,   245,   233,  1205,     0,     0,  1193,  2150,   556,   889,
     833,     0,   214,   215,     0,     0,   281,   283,   278,   279,
     275,   277,   274,   276,   273,     0,   283,   294,   295,   291,
     293,   290,   292,   285,     0,     0,     0,   334,     0,   337,
     339,   222,     0,   221,     0,   186,     0,  2130,   542,   611,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
     525,   530,     0,   526,   529,   528,     0,     0,    11,   172,
     426,   401,   400,     0,  1134,     0,     0,   442,  1573,  1571,
    1572,  1568,  1570,  1567,  1569,  1561,     0,     0,     0,   441,
       0,     0,     0,     0,     0,     0,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   522,   523,   524,   455,     0,     0,   454,   464,     0,
       0,   405,     0,     0,   406,   396,   402,   404,   407,   408,
     409,   410,   411,   403,   433,   432,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   932,     0,   916,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   234,   237,   944,   685,   856,   944,     0,  2148,  2150,
    1128,  1694,   827,     0,   944,     0,     0,   305,   270,     0,
       0,   280,   297,   271,   296,     0,   289,     0,   312,     0,
     306,     0,   331,     0,   336,   326,     0,     0,   315,   268,
     325,     0,     0,     0,     0,   513,   510,   509,   512,   508,
     519,   504,   504,     0,   527,     0,   531,     0,   288,   511,
     518,   272,     0,  1200,  1640,     0,     0,     0,     0,     0,
     429,     0,     0,   445,     0,     0,     0,     0,   447,   446,
     465,   456,   471,   474,   475,   472,   478,   477,   476,   466,
     467,   468,   469,   470,   412,   457,   461,   479,   473,   460,
     479,   439,   490,   487,   496,   493,   502,     0,   481,    94,
      95,    97,   483,     0,     0,   235,     0,     0,   241,     0,
       0,   250,     0,   242,   224,   208,     0,   253,   266,   950,
       0,   945,   946,   944,     0,   840,  2149,  2147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2131,     0,  1296,  1295,     0,  1297,     0,   386,  1294,
    1234,     0,     5,  1293,   387,   384,     0,   389,   174,   479,
    1106,     0,     0,  1303,   124,   383,   382,  1226,   377,   479,
       0,  1251,  2123,     0,   388,   351,     0,     3,     2,     0,
     385,  1231,     0,     0,   378,   375,   390,     0,     0,     0,
       0,  1301,  1291,   381,     0,     0,     0,     0,     0,     0,
       0,     0,  1290,     0,     0,     0,   175,  1228,   374,   373,
       0,     0,  2127,  2126,     0,     0,     0,   137,  1227,   380,
     379,     0,     0,   376,   479,     0,   479,     0,   549,     0,
       0,     0,     0,     0,     0,   479,   787,  1202,     0,     0,
    1110,     0,  2116,     0,   104,     0,     0,   860,     0,     0,
       0,     0,   788,     0,     0,  1717,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   656,     0,     0,  2152,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,
    2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,   898,  2202,
    2203,  2204,  2205,  2206,  2207,  2208,  2209,  2210,  2211,  2212,
    2213,  2214,  2215,  2216,  2217,  2218,  1097,  1099,  1094,  1096,
    1095,  1098,  2219,  2220,  1225,  2221,  1230,  1229,  2222,  2223,
    2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,  1359,  2232,
    2233,  2234,  2235,  2236,  2237,  2238,  2239,  2240,  2151,   828,
     560,     0,   893,     0,   891,     0,   333,   216,   217,     0,
     282,   287,     0,     0,     0,     0,   335,   338,     0,   220,
       0,     0,   543,     0,   615,     0,   617,   499,     0,   500,
       0,   541,     0,   538,   535,   506,   498,     0,   171,  1642,
    1643,  1641,     0,   431,  1199,     0,  1566,  1199,   430,  1199,
    1199,  1199,  1199,  1199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
     930,     0,   211,   226,     0,   186,     0,     0,     0,     0,
       0,  1206,     0,     0,  1194,   370,   368,   369,  1036,  1035,
    1039,     0,  1543,  1544,     0,     0,  1238,   628,   629,   814,
    1069,  1074,  2125,   621,   123,     0,     0,  2107,  2106,  1004,
    2103,  2105,  2139,     0,     0,  1250,     7,     0,     6,     0,
    2132,  1070,     0,  1162,  1161,  1109,  1160,  1108,   423,  1304,
    1292,   841,   413,  1696,  1298,   125,     0,  1073,   122,     0,
     794,    24,   623,   391,     0,   793,  1066,   795,     0,  1302,
     882,   881,   884,   880,   883,  2141,     0,   878,     0,   622,
     977,   879,  2135,     0,  2124,   121,   974,   688,   972,     0,
     619,  2119,   732,   731,   733,   729,     0,     0,   987,   624,
    1358,  1353,  1356,     0,     0,     0,  1040,  1037,     0,  1031,
    1033,  1032,  1030,  1029,     0,     0,     0,  1028,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1018,  1009,  1010,     0,  1054,   421,    24,     0,  2121,
     126,   620,     0,  1203,  1201,  1127,     0,  1685,  1686,  1128,
    1216,  1128,  1111,  1112,  1115,  1130,  1305,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,   919,     0,    69,
       0,   102,   598,     0,   643,   642,     0,  1100,   994,  1104,
       0,     0,  1055,  1220,     0,     0,  1107,   648,   645,   646,
       0,   650,   651,     0,   653,   654,     0,   649,   954,   956,
       0,     0,   955,   734,   952,   699,   948,   910,     0,     0,
       0,     0,   660,   661,     0,     0,   908,   905,   906,   902,
     903,   904,   897,   901,   900,     0,     0,     0,     0,     0,
       0,   564,   566,   558,   561,   562,   895,  2150,   890,   892,
     834,     0,   284,   286,   313,   307,     0,     0,   316,   612,
     614,     0,     0,   504,   532,     0,   281,     0,     0,  1666,
    1556,  1559,  1667,  1563,  1557,  1664,     0,     0,  1663,     0,
       0,  1665,     0,     0,     0,     0,     0,  2107,  1558,  1662,
    1560,  1654,     0,  1644,  1646,  1649,  1652,  2113,  1653,  1137,
    1574,  1136,  1135,  1138,  1140,  1139,  1133,   458,   459,   463,
     448,     0,   451,   462,     0,   450,   491,   488,   497,   494,
     503,   482,    96,   484,   917,     0,   231,     0,   229,   251,
     243,   235,   254,   951,   176,   947,   857,   176,     0,     0,
       0,  1280,  1281,     0,     0,     0,  1252,  1255,  1257,  1258,
    1259,  1263,  1262,  1260,  1261,     0,     0,  1253,  1254,     0,
       0,  2104,   928,     0,  1006,     0,     0,     0,     0,  1539,
    1540,     0,  1071,     0,    24,  1157,  1159,  1158,   416,   417,
     414,   415,   964,     0,     0,   356,    25,   350,     0,     0,
    1063,     0,     0,     0,     0,     0,     0,     0,   981,  1695,
       0,     0,     0,     0,     0,     0,  2121,     0,     0,   138,
       0,     0,   991,   983,   984,   989,  1354,  1355,     0,   907,
     419,  2097,   340,     0,   550,   603,   602,   600,   605,  1012,
     604,  1017,  1013,  1016,   786,   778,   772,   784,   785,   770,
     771,   779,   774,   780,   773,   783,   777,   781,   776,   782,
     769,   775,   762,   768,  1014,  1015,     0,  1022,  1026,  1019,
    1020,  1024,  1025,  1023,  1021,  1027,     0,   796,     0,     0,
       0,     0,     0,   744,   743,   740,  2122,  2129,    24,  1123,
    1124,  1125,  1126,  1120,  1118,  1217,  1132,  1117,  1113,     0,
       0,  1114,  2117,     0,     0,     0,     0,    98,     0,    99,
       0,     0,     0,    74,     0,     0,     0,   111,   106,     0,
     644,   887,     0,   886,     0,   479,  1102,     0,   939,   940,
     963,   934,   935,   789,   961,  1057,  1222,     0,  1224,  1223,
    1773,  1890,  1886,  1892,  1924,  1904,  1895,  1854,  1816,  1944,
    1910,  1918,  1807,  1913,  1774,  1721,  1905,  1812,  1863,  1998,
    1842,  1830,  1843,  1942,  1945,  1912,  1866,  1948,  1733,  2005,
    1941,  1969,  1744,  2041,  1831,  2014,  1726,  1974,  1742,  1802,
    1849,  1869,  1964,  1992,  1997,  1725,  1921,  1950,  1737,  1739,
    1762,  1780,  1800,  1810,  1820,  1873,  1876,  1935,  1946,  1952,
    1953,  1970,  2015,  2026,  1724,  1755,  1779,  1778,  1786,  1788,
    1796,  1806,  1827,  1845,  1848,  1874,  1882,  1939,  1949,  1959,
    1965,  1966,  1968,  1993,  2023,  2034,  1745,  1748,  1759,  1765,
    1767,  1772,  1775,  1777,  1783,  1791,  1793,  1794,  1795,  1805,
    1815,  1822,  1838,  1839,  1850,  1868,  1872,  1885,  1901,  1925,
    1933,  1943,  1947,  1954,  1962,  1971,  1981,  1985,  2002,  2008,
    2012,  2020,  2025,  2028,  1768,  1887,  1930,  1753,  1754,  1771,
    1776,  1782,  1784,  1798,  1799,  1809,  1818,  1823,  1825,  1826,
    1832,  1840,  1857,  1858,  1871,  1899,  1903,  1906,  1911,  1915,
    1923,  1931,  1932,  1937,  1955,  1956,  1961,  1967,  1972,  1978,
    1979,  1980,  1982,  1984,  1986,  1995,  2017,  2018,  2019,  2024,
    2040,  1728,  1881,  1889,  1891,  1988,  1730,  1734,  1738,  1743,
    1749,  1750,  1763,  1764,  1766,  1769,  1781,  1797,  1817,  1819,
    1829,  1833,  1835,  1836,  1844,  1853,  1855,  1856,  1867,  1880,
    1898,  1916,  1917,  1934,  1936,  1940,  1951,  1973,  1983,  1991,
    2013,  2016,  2030,  2031,  2032,  1761,  1731,  1751,  1752,  1758,
    1828,  1760,  1785,  1787,  1801,  1878,  2003,  1811,  1813,  1821,
    1824,  1846,  1847,  1852,  1859,  1860,  1861,  2043,  1893,  1894,
    1897,  1902,  1907,  1914,  1919,  1920,  1922,  1929,  1958,  1960,
    1976,  1987,  1989,  1990,  1994,  1999,  2000,  2004,  2006,  2007,
    2022,  2027,  2029,  2033,  2035,  2039,  1888,  2038,  1727,  1729,
    1732,  1736,  1746,  1770,  1789,  1790,  1792,  1803,  1834,  1837,
    1877,  1883,  1896,  1900,  2036,  2037,  1938,  1957,  1963,  1975,
    1977,  1996,  2001,  2011,  2021,  1741,  1735,  1740,  1757,  1808,
    1851,  1864,  1865,  1926,  1928,  2010,  1884,  1841,  1908,  1756,
    1804,  1814,  1879,  1862,  1909,  1747,  1870,  1875,  2009,  1927,
       0,  1719,  1722,  1723,   676,     0,     0,     0,   665,   699,
     699,   696,     0,     0,   700,     0,    26,   664,   667,     0,
     674,   670,   909,   899,  1692,  1693,  1683,  1683,  1323,     0,
       0,  1601,     0,   186,  1306,     0,     0,  1307,  1351,   186,
       0,  1352,     0,  1640,     0,  1320,     0,  1370,  1369,  1368,
    1366,  1367,  1365,  1363,  1360,  1434,  1433,  1361,  1362,  1371,
    1622,  1364,  1699,  1698,  1697,  1372,  2150,  2150,   577,   568,
     559,     0,   563,  2150,   894,   176,     0,   327,   219,     0,
       0,  1581,  1579,  1580,  1576,  1578,  1575,  1577,   505,   501,
       0,   537,   536,   173,  1651,  1650,  1589,  1587,  1588,  1584,
    1586,  1583,  1585,  1562,     0,  1640,     0,     0,  1502,     0,
    1502,  1502,  1502,  1502,  1655,     0,     0,     0,  1451,  1630,
    1647,     0,     0,     0,     0,  1708,  1709,  1710,  1711,  1712,
    1713,  1658,     0,     0,   453,   452,     0,     0,   186,   228,
     209,  1207,   176,  1195,  1424,     0,  1423,     0,  1425,     0,
    1426,  1283,     0,  1289,  1285,  1282,     0,     0,     0,     0,
       0,     0,  1279,  1275,  1413,  1412,  1411,  1249,  1248,     0,
    1274,  1270,     0,  1266,  1264,     0,  1542,  1545,   632,     0,
     631,     0,  1005,     0,     0,  1003,  2110,  2112,  2111,  2108,
    2140,  2137,     0,     0,     0,     0,  1235,   479,   348,     0,
       0,  1232,   996,  1067,  1068,  1065,  1064,     0,   885,     0,
       0,   608,     0,     0,     0,   975,   973,   690,   691,     0,
     695,     0,     0,  2120,  2128,   730,     0,   142,     0,   985,
     992,     0,     0,  1000,  1357,     0,     0,   343,     0,     0,
       0,     0,    24,  1038,   553,     0,     0,     0,   763,   764,
    1011,   797,   422,     0,  1046,   741,   742,   371,     0,  1128,
       0,  1131,  1116,  2150,     0,     0,     0,     0,     0,     0,
       0,    64,    93,     0,     0,   117,   112,     0,   107,     0,
     114,   108,   871,   863,   869,     0,  1101,     0,  1103,  1105,
       0,     0,   943,     0,     0,     0,     0,  1056,  1221,     0,
       0,  1718,  1720,  2150,   647,   652,   655,   668,   666,   625,
       0,   719,   717,   723,   721,     0,     0,   715,   759,   713,
     698,   709,   707,   757,   735,     0,   701,   711,   953,   949,
       0,     0,     0,     0,   673,     0,     0,     0,     0,     0,
       0,     0,  1546,     0,  1429,  1430,  1704,  1393,  1451,     0,
       0,  1702,     0,     0,  1623,  2045,     0,  1376,  1382,  1381,
    1380,  1384,     0,  1377,  1378,   565,   567,     0,     0,   580,
     572,   574,     0,   569,   570,     0,     0,   588,   590,     0,
       0,   586,   896,   835,   218,     0,   616,   618,   613,     0,
     534,   533,     0,     0,  1675,     0,     0,     0,  1504,  1505,
    1503,     0,  1677,     0,     0,     0,     0,     0,     0,     0,
    1645,     0,  1440,  1441,  1443,  1446,     0,  1452,  1453,     0,
       0,  1502,  1632,  1626,  1660,  1661,  1659,  1657,  2114,   449,
     485,     0,   230,  1163,   858,  1141,  1401,  1403,     0,  1287,
       0,     0,     0,     0,     0,  1277,     0,     0,  1534,  1532,
    1509,  1519,  1521,  1517,     0,  1516,     0,  1525,  1512,  1533,
       0,  1524,  1515,  1531,  1523,  1417,  1506,  1507,  1508,     0,
    1272,  1268,     0,     0,  1256,   630,     0,     0,     0,     0,
       0,  2136,     0,     4,     8,    10,  1538,  1541,     0,   479,
     418,     0,     0,     0,   993,     0,     0,     0,     0,     0,
       0,     0,     0,   689,     0,     0,   159,   157,     0,     0,
     139,     0,   149,   155,   699,   144,   146,     0,   990,  1001,
    1002,     0,   420,     0,  2098,  2099,   342,   347,   610,   341,
       0,   344,   349,   479,  1329,   601,   599,     0,   766,  1045,
    1047,     0,   372,  1121,  1119,  1218,  1219,     0,     0,  1212,
       0,     0,     0,   100,     0,     0,    75,    81,    71,  2150,
    2150,   110,   105,   119,   115,     0,   109,   760,   872,   625,
    2150,   862,   861,   870,   995,     0,     0,   941,   942,   936,
     962,   479,  1062,  1058,  1059,  1061,  2042,   959,  2044,   957,
     677,   671,   669,     0,    24,     0,  2150,  2150,  2150,  2150,
     725,   703,   727,   705,  2150,  2150,  2150,  2150,     0,   697,
     702,  2150,   625,   755,   753,   756,   754,     0,     0,    46,
      44,    41,    35,    39,    43,    38,    31,    40,     0,    34,
      37,    32,    42,    33,    45,    36,     0,    29,    47,   747,
       0,   675,  1684,     0,  1682,  1640,  1680,  1627,  1628,  1620,
    1606,  1621,     0,     0,     0,  1034,  1428,  1431,     0,     0,
       0,  1341,  1312,  1707,  1706,  1705,     0,     0,     0,     0,
    1336,     0,  1335,     0,  1337,  1332,  1333,  1334,  1325,  1321,
       0,     0,  1383,     0,     0,   579,   584,     0,     0,  2150,
    2150,   557,   571,   594,   582,   596,  2150,  2150,   592,   576,
     587,   827,   328,     0,  1596,  1594,  1595,  1591,  1593,  1590,
    1592,  1564,     0,     0,     0,  1676,     0,     0,     0,  1674,
       0,     0,     0,     0,  1656,  1673,     0,  1444,     0,  1555,
    1447,     0,     0,     0,     0,  1439,  1457,  1459,  1461,  1501,
    1500,  1499,  1463,  1479,     0,  1454,  1455,  1635,  1239,     0,
       0,     0,   212,     0,  1189,  1208,   827,     0,  1196,  1189,
       0,     0,  1284,     0,  1286,     0,  1547,     0,  1402,     0,
    1405,  1550,     0,  1409,     0,  1276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1415,     0,  1418,  1419,
       0,  1271,     0,  1265,  1267,  2109,     0,     0,     0,  2138,
    1245,     0,  1241,     0,     0,  1246,   842,     0,     0,     0,
       0,     0,  1299,  2143,  2142,   609,     0,     0,    48,     0,
     692,   694,   693,  1300,   699,  2150,  2150,   151,   633,   161,
     153,   163,   143,   150,  2150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1330,   551,     0,   765,  1043,     0,
    2118,     0,    93,     0,    65,     0,     0,     0,    78,     0,
      93,    93,   118,   113,  2150,  2150,   103,     0,   873,   867,
     875,   874,   864,   547,   922,     0,     0,     0,     0,     0,
     679,   658,   672,   626,   736,     0,   720,   718,   724,   722,
       0,  2150,     0,  2150,   716,   714,   710,   708,   758,   712,
      24,   748,     0,     0,     0,    27,     0,  1687,     0,  1607,
       0,     0,  1619,  1602,  1618,  1432,     0,  1395,     0,  1340,
       0,     0,  1703,     0,  1700,  1624,     0,     0,     0,     0,
       0,     0,  2046,  1339,  1338,  1326,  1324,     0,  1386,     0,
    1379,     0,   581,   578,   573,   575,     0,  2150,  2150,   589,
     591,  2150,  2150,     0,  1582,     0,     0,     0,     0,     0,
    1672,  1678,  1668,  1669,  1670,  1671,  1448,     0,  1442,  1462,
       0,  1466,     0,  1479,  1465,     0,     0,  1480,  1495,  1492,
    1493,  1490,  1498,  1497,  1491,  1494,     0,     0,     0,     0,
       0,  1496,     0,     0,     0,  1436,  1437,  1648,     0,  1456,
    1450,  1240,  1633,  1346,  1342,  1343,  1348,  1347,  1631,  1239,
       0,  1187,  1188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1186,     0,     0,  1174,  1175,  1176,
    1173,  1178,  1179,  1180,  1177,  1164,  1155,     0,     0,  1211,
       0,  2150,     0,  1150,     0,     0,     0,     0,     0,     0,
       0,  1142,  1143,     0,  1075,     0,  1288,  1427,  1551,     0,
    1552,     0,     0,     0,     0,  1408,  1278,  1407,  1399,  1535,
       0,     0,     0,     0,  1536,  1528,  1528,     0,     0,  1528,
    1556,  1414,  1416,  1420,  1421,  1273,  1269,  1008,     0,   971,
    1244,  1243,     0,  1237,     9,     0,  1239,   843,  1072,   354,
    1233,     0,     0,  2134,     0,     0,   976,    49,     0,   745,
     160,   158,     0,  2150,     0,     0,     0,  2150,   156,   145,
       0,   148,   147,     0,   982,   986,  2102,  2101,  2100,   346,
       0,   554,     0,  2150,   767,     0,   625,  1122,     0,  1213,
      70,     0,     0,   101,    68,    93,    76,    82,     0,   120,
     116,   761,  2150,   877,   625,   876,     0,   544,     0,   791,
     792,   790,  1060,   960,   958,   682,   680,     0,   662,   659,
       0,   726,   704,   728,   706,   737,   751,   752,   749,   750,
      30,    28,     0,  1681,  1636,  1608,  1604,  1603,     0,  1394,
    1640,  1397,     0,  1314,  1309,  1308,  1311,     0,  1636,     0,
       0,  2079,  2077,     0,     0,  2065,  2076,     0,     0,  2078,
       0,     0,     0,     0,     0,  2107,  2075,  2071,     0,  2063,
    2066,  2067,  2074,  2070,  2094,     0,  2056,  2055,  2059,  2061,
       0,  2054,     0,  2057,  2048,  1327,  1322,     0,  1385,     0,
     585,   583,   595,   597,   593,     0,     0,     0,  1639,     0,
    1716,     0,     0,  1445,  1464,  1458,  1460,  1467,  1469,  1467,
       0,  1474,  1467,     0,  1472,  1467,     0,  1482,  1481,     0,
    1483,     0,  1435,     0,  1350,  1349,  1345,  1634,   235,  1181,
    1182,  1183,  1185,  1168,  1166,  1165,  1169,  1170,  1167,  1184,
    1171,  1172,  1156,   968,  1191,   965,     0,     0,  1209,     0,
    1154,  1153,  1148,  1146,  1145,  1149,  1147,  1151,  1152,  1144,
    1197,  1404,     0,  1400,  1406,  1554,  1547,  1410,  1510,  1518,
       0,  1520,     0,     0,     0,     0,  1526,  1530,     0,  1422,
    1007,  1242,  1247,  1236,     0,    24,     0,     0,   999,     0,
      50,   979,     0,    24,   162,   152,     0,   635,   637,   164,
     154,   745,     0,   345,  1331,     0,  1044,    24,     0,     0,
      66,     0,    79,    88,     0,    72,   868,   865,   548,  2150,
     937,     0,  2150,   678,   657,   663,   625,  1691,     0,  1689,
       0,     0,  1609,  1605,  1396,     0,  1398,  1392,     0,  1313,
       0,  1701,     0,  2069,  2068,     0,     0,  1502,     0,  1502,
    1502,  1502,  1502,  2072,     0,     0,  2052,     0,     0,     0,
       0,  2081,  2053,     0,     0,     0,     0,     0,     0,  2047,
       0,  1387,  1390,  1374,  1388,  1391,   837,   836,   329,  1597,
    1714,  1715,  1449,     0,  1486,  1488,     0,  1475,  1478,  1477,
    1485,     0,  1487,  1467,     0,  1438,  1344,   213,   970,   969,
     967,     0,  1190,  1076,  1080,  1082,     0,  1086,     0,  1084,
    1088,  1077,  1078,     0,   859,     0,     0,  1548,  1553,     0,
    1537,  1529,  1513,  1511,     0,  1514,   355,   352,     0,   997,
       0,     0,     0,   978,   746,   140,   634,    24,   988,   552,
    1041,    67,  1214,    84,     0,     0,    77,    88,    88,  2150,
     545,     0,     0,   681,   738,     0,  1688,  1637,  1630,     0,
    1315,     0,  1630,  2092,     0,     0,  2095,     0,     0,     0,
       0,     0,     0,     0,  2064,  2083,  2084,  2082,  2080,  2062,
       0,  2058,  2060,  2049,  2050,  1328,     0,  1375,  1373,  1468,
    1679,  1470,     0,  1473,  1471,  1489,     0,   966,  2150,  2150,
    1090,  2150,  1092,  2150,  2150,  1079,  1210,  1198,     0,     0,
    1527,   357,   998,  2133,     0,     0,     0,     0,     0,     0,
      55,     0,    54,     0,    52,     0,     0,   141,  1048,    88,
      93,    88,    89,    83,    73,   866,     0,     0,   683,    24,
    1690,  1629,  1638,  1319,     0,  1316,  1318,  1610,  2093,     0,
       0,  2091,     0,     0,     0,     0,  2073,  2090,     0,  1389,
    1476,  1484,  1081,  1083,  2150,  1087,  2150,  1085,  1089,  1549,
    1522,   359,   364,   362,   353,     0,   360,   366,    57,    62,
      59,    61,    58,    60,    56,     0,    51,     0,   636,   638,
    1052,  1042,     0,  1050,  1215,    85,    80,   546,   938,  2150,
     739,     0,  1310,     0,  1611,  1625,  2089,  2096,  2085,  2086,
    2087,  2088,     0,  1091,  1093,  2150,  2150,   358,   361,  2150,
      53,     0,  2150,  1049,  1051,     0,   679,  1317,     0,  1615,
    1612,  1613,  2051,   365,   363,   367,     0,  1053,    86,   684,
       0,     0,     0,   980,    90,     0,  1616,  1614,    92,     0,
      87,     0,    91,  1617
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   798,   799,   800,   801,  1017,  2303,  2304,   180,   319,
     181,  1355,  1356,  2151,  2456,  3392,  2926,  2927,  3301,  3393,
    3394,   802,  1145,  2961,  2681,  3318,  2092,  2679,  3183,  2965,
    3314,  2680,  3184,  3400,  3495,  3514,  3316,  3520,   628,   629,
     630,  1468,  2372,   803,  1479,  1150,  1477,  2100,  2382,  2097,
    2380,  2385,  2685,  1478,  2379,  2101,  2684,   804,     9,    28,
      29,    30,    31,    32,    88,   807,  1077,  2047,  1379,  2330,
    2334,  2335,  2331,  2332,  2933,  2937,  2654,  2646,  2645,  2647,
    2650,   484,   267,   582,   808,    55,    56,    11,    41,   115,
      70,   252,    72,    73,   196,   333,    74,    75,   239,   338,
     225,   978,   510,  2830,   364,   909,  2205,   392,   393,   226,
     347,   339,   342,  1297,  1298,   119,   522,   120,   121,   352,
     227,   228,   253,   560,   241,   244,   242,   243,   374,   538,
     539,   541,   546,   912,   245,   246,   383,   543,   192,    12,
      51,   151,   152,   153,   918,  2773,   154,   249,   237,   386,
     387,   388,   389,  2062,   809,   810,   811,   812,  1036,  3381,
    3155,  1357,  3444,  3445,  3446,  3486,  3485,  3489,   813,   814,
     815,   816,   817,   818,   819,  1028,   485,  1031,  1349,  1350,
    1389,  1115,  1390,   294,   295,   296,   297,   298,   299,   300,
     442,   486,  1281,   487,   488,   489,   490,   491,   492,   493,
     957,   182,   504,   967,   969,  1956,   183,   498,   963,   497,
     962,   500,   965,   499,   964,   927,   936,   301,   302,   185,
     303,   412,   413,   414,   415,   397,   820,  3189,  3406,  2977,
     821,  1088,  2064,  2953,  2354,    89,   234,   532,  1889,  1213,
    1214,  1215,  1886,  1887,  2192,  2193,  2194,  2509,  2510,  1890,
    1891,  2188,  2513,  2505,  2200,  2201,  2516,  2517,  2771,  2767,
    2768,   822,  1399,    57,  2032,  2033,  2349,   398,  1069,  1120,
    1002,  1058,  1041,  1078,  2414,   186,  1003,   997,  1999,  2649,
      59,   304,   823,  1155,   824,  1168,  1169,   825,   826,   827,
     828,  1176,  2988,  1197,  3194,  1198,  2127,  1199,  2411,  1200,
    2701,  1201,  2154,   829,  2123,  2700,  2987,  3192,  3191,  3469,
      90,    13,   830,  1373,  2037,  2038,  2039,  2144,  1835,  2145,
    2146,  2711,  2713,  2427,  2426,  2431,  2425,  2424,  2417,  2416,
    2419,  2418,  2421,  2423,   831,   832,  1075,   833,  1831,  1183,
    3409,   834,  1445,  3163,  2458,  2459,  2147,  2428,  2388,  2687,
    1111,  1427,  2068,  2357,  2069,  1423,   835,   836,  1161,  2115,
    2981,   837,   838,   839,   840,    14,    45,    15,    16,    17,
      91,    92,   841,    93,    18,   900,    19,    94,    95,   131,
     534,  1895,  2521,  3247,    96,   127,   357,   842,  2627,    20,
      21,    22,    23,    24,    40,    62,    97,   653,  1962,  2576,
     843,  1156,  2392,  2104,  2390,  3319,  2972,  2105,  2389,  2690,
    2974,   844,   845,   846,  1052,  1053,  1482,    98,   235,   533,
     903,   904,  1217,  1893,   847,  1202,  1203,   848,  1843,  1204,
     305,    64,    65,    66,    67,  1489,   157,   111,    68,  1008,
     108,   188,   189,  1490,  1491,  2399,  1492,   650,   651,  1185,
     652,  1186,  2408,  2409,  1493,  1494,  1353,  3114,  3115,  3270,
    2008,  1067,  1068,   849,  1368,  3303,   850,  2945,   851,  1383,
    1384,  1385,  2053,  2051,   852,   853,  2314,  2341,   854,  1334,
    2005,   855,  1112,  1113,   856,   990,   857,  2469,   858,  3398,
    2956,   859,  2361,  3461,  3462,  3463,  3492,  1117,   860,  1495,
    2117,  2403,  2404,   861,  2025,  1001,  1343,   862,   863,   864,
    2578,  3118,  3281,  3282,  3368,  3369,  3373,  3371,  3374,  3434,
    3436,   865,   866,  1484,  2109,   867,  1486,  1131,  1132,  1133,
    1461,   868,   869,   870,  2079,  1453,  1126,   195,  1134,  1135,
     306,  2579,  2871,  2872,  2855,  1025,  1026,  2574,  2856,  2859,
      99,   126,   526,  1307,  2255,  2873,  3285,   424,   871,  1124,
     100,   123,   523,  1304,  2253,  2860,  3283,  2575,  1149,  2672,
    3179,  3399,  1456,   872,   873,   874,   875,   876,  1039,  2312,
    1019,  2308,   877,  2822,  2621,  2622,  2624,  1982,   878,   879,
    1316,  1317,  1318,  1994,  2292,  1319,  2289,  1991,  1320,  2264,
    1983,  1321,  1322,  1323,  1324,  2258,  1974,   880,  1048,  1030,
     881,  1867,  1868,  2169,  3015,  3210,  2741,  3012,  3414,  3415,
    1869,  2176,  2755,  1849,  2499,  3056,  3240,  2665,  2952,  2500,
    1870,  1871,  2242,  2824,  2825,  2826,  3096,  1872,  1873,  1387,
     882,  1081,   883,  1210,  1874,  1875,  3358,  2182,  2183,  2184,
    2502,  2757,  3243,  3244,  1876,  2479,  2736,  3207,  1984,  1985,
    1970,  2587,  2256,  2588,  1986,  2592,  1987,  2608,  1988,  2609,
    2902,  2903,  2259,  1877,  2163,  2164,  2476,  1878,  2819,  2565,
    2815,  2237,  1938,  2232,  2233,  2234,  2787,  1939,  2238,  2566,
    2820,  2555,  2556,  2557,  2558,  2559,  3254,  3077,  3359,  2560,
    3256,  3257,  2813,  2561,  2814,  2562,  2221,  2285,  2286,  2287,
    3143,  2288,  2890,  2895,  3291,  2589,   994,  3245,  2880,  3048,
    2591,  2550,  1259,   307,  1260,  1923,   435,   928,  1908,  1924,
    2531,    39,   884,   885,  3007,  3203,  2729,  3202,  3475,  3500,
    3501,  2733,  2470,  1879,  2471,  2488,  3018,   585,  2466,  2467,
    2243,  2568,  3201,  3011,  1261,   942,  1262,  1263,  2816,  2563,
    1265,  1266,  2223,  3361,   886,   887,  2156,  2468,  3003,  3198,
    3199,  1846,   888,  1034,  1881,  1882,  2172,  2743,  1883,  1884,
    2485,  1951,  2216,   889,  1164,  1820,  1821,  1822,  2119,  1823,
    2120,  1885,  2489,  3054,  3239,  2752,  3051,  3052,  3053,  3050,
    3038,  3039,  3040,  3041,  3042,  3043,  3337,   890,  2056,  2344,
    2345,  1009,  1267,  1011,  2009,  1268,    25,   892,  1137,  2083,
    1376,  1447,   893,   400,   894,  2638,   895,  2301,  1013,  2011,
     896,   897,    35,   527,   528,   529,   530,   531,   898
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2925
static const short yypact[] =
{
     899,   471, -2925,   255,   255,  1019, -2925, -2925,  1019, -2925,
     -29, -2925, -2925, -2925,   308, -2925,   899, -2925, -2925, -2925,
   -2925, -2925,   -77, -2925, -2925, -2925, -2925, -2925,   373,   540,
   -2925,   526, -2925, -2925, -2925, -2925, -2925, -2925,  -156, -2925,
     828,   172, -2925, -2925, -2925,    99, -2925, -2925, -2925, -2925,
   -2925,   -54,   255, -2925,   255,   372,   -29, -2925,   -34, -2925,
   -2925, -2925, -2925, -2925, -2925,   967,   280, -2925, -2925, -2925,
     868,   517,   255, -2925, -2925,   883,   255, -2925, -2925,   255,
     255, -2925, -2925, -2925, -2925,   255,   255, -2925, -2925, -2925,
   -2925, -2925,    99, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,  4312, -2925,   280, -2925,   339,  1258, -2925, -2925,
     454, -2925, -2925,   930,   172,   415, -2925, -2925, -2925, -2925,
   -2925,  9144, -2925,   255,   523,   807,   255,   -29, -2925, -2925,
   -2925,   255, -2925, -2925,   643,   556,   583, -2925, -2925,   597,
   -2925,   629, -2925,   564, -2925, -2925,   651, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925,   621, -2925, -2925,
   -2925,   659,   663,   676,   685,   712,   724,   728,   750,   753,
     765,  1258,   783,  4792,   805,   819,   875,   886,   916,   919,
    1507,  1228, -2925, -2925, -2925, -2925,   800, -2925,   160, -2925,
    1258, -2925,    89, -2925, -2925, -2925,    85, -2925, -2925, -2925,
     745, -2925, -2925, -2925, -2925, -2925,   643,  1001, -2925,   583,
   -2925, -2925,  1011, -2925,  1023, -2925,   809, -2925, -2925,  1032,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,  1041,
    1309,   255,  1046, -2925,   -29,   -29,  1069,   255, -2925,    61,
    1374, -2925,   756,   897, -2925,   781,   921,  1527,  1531,   255,
    1534,  1537, -2925,   931, -2925,    33,    33,    33,    33,    33,
    4792,   871,  1157,    33,  4792,   950,  4792, -2925,  4792,  4792,
    4792, -2925, -2925, -2925,  1029,  1122,  1133,  4792,   933,  1134,
   -2925,  4792,  4792,  1136, -2925,  1138, -2925,   819,  1139,  1146,
    1147,  1149,  1586,  8676,    55, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  1162, -2925, -2925, -2925, -2925,
   -2925, -2925,   832,   832, -2925, -2925, -2925, -2925, -2925,  1258,
   -2925, -2925,   255,  1258,  1125,   216, -2925, -2925, -2925, -2925,
    1595, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
      61,  1601, -2925, -2925, -2925,  1602,  1604,   172,  1534,  1606,
     979, -2925,  1540, -2925,  1208,  1172, -2925,  1247, -2925, -2925,
   -2925,   991, -2925, -2925,  1621,  1220, -2925,  1186, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,   921,  1186, -2925, -2925, -2925,
   -2925, -2925, -2925,  1191,   215,   218,   209, -2925,  2282, -2925,
   -2925, -2925,  1196,  1656,   219, -2925,  1195,  1658, -2925,  -230,
    1239,  1256,  1259,  1261,  1263,  7677,  1266,  -148,  1457, -2925,
   -2925,    93,  1267, -2925, -2925, -2925,  1269,  7736, -2925,  3545,
    8995,  2989,  2989,  4792, -2925,  1192,  4792,  8676,  1231, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,  1039,  1684,  7777,  8676,
    1192,  1689,   384,  4792,  4792,  4792,  4792, -2925,  4792,  4792,
    4792,  4792,  4792,  4792,  4792,  4792,  4792,  4792,  4792,  4792,
    4792,  4792,  4792,  4792,  4792, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  4792,  4792, -2925, -2925,  1244,
    4792, -2925,  4792,  1245, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,   832,  4792,  4792,  4792,
    4792,  1287,  1718,  1507,  4792,  1257, -2925,  1258,  1232, -2925,
    1067,  1075,  1702,  1304,  1438,   233,   237,   253,  1272,   258,
   -2925, -2925, -2925,   255, -2925, -2925,   255,  1339, -2925,  6793,
     415,  7081,  1710,  -262,   255,  1722,  -117, -2925, -2925,   897,
    1717, -2925, -2925, -2925, -2925,  1719, -2925,  1720, -2925,  1721,
   -2925,   255, -2925,   255, -2925, -2925,  1534,  1723, -2925, -2925,
   -2925,   255,    33,  1258,    36, -2925, -2925, -2925, -2925, -2925,
   -2925,   933,   933,  1724, -2925,  1730,  1140,  1081, -2925, -2925,
   -2925, -2925,  1329,  8676,   -99,  1331,  7840,  1737,   933,  1336,
   -2925,  1341,  1342, -2925,  7881,  8062,  8389,  8432,  8747,  3578,
    8995,  8933,  4852,  9099,  2581,  9143,  4673,  4821,  9175,  2989,
    2989,  4012,  4012,  1850,  8676,  8493,  8576,  1192,  8676,  8645,
    1192, -2925,  8676,  8676,  8676,  8676, -2925,  1750, -2925,  1778,
   -2925,  8676, -2925,   225,  1258, -2925,  1764,  -117, -2925,  1318,
    1760, -2925,  1762, -2925, -2925, -2925,  1763, -2925, -2925,  1135,
    1363,  1790, -2925,   255,  1372, -2925, -2925, -2925,   832,   832,
     832,  1013,   255,  1254,   183,   255,   255,   183,   183,  1018,
     255, -2925,  1254, -2925, -2925,   255, -2925,  1027, -2925, -2925,
   -2925,   183, -2925, -2925, -2925, -2925,   255, -2925, -2925, -2925,
   -2925,   126,   126,  4792, -2925, -2925, -2925, -2925, -2925, -2925,
     183, -2925, -2925,   183, -2925, -2925,   255, -2925, -2925,   183,
   -2925, -2925,   832,   183, -2925, -2925,  4792,   183,   832,   255,
     832,   183, -2925, -2925,   179,   183,   183,   179,   183,   255,
     179,   183, -2925,   183,   183,   183, -2925, -2925, -2925, -2925,
     832,   183, -2925, -2925,   183,    51,   255, -2925, -2925, -2925,
   -2925,   183,  1030, -2925, -2925,   832, -2925,   183, -2925,  9306,
     832,  4792,    33,    33,   183, -2925, -2925,  1013,   832,  1036,
    4792,  4792, -2925,   982,  4792,   183,    57, -2925,  4792,   183,
    1773,   832, -2925,   183,  4792, -2925,  4792,   126,   255,   183,
     255,    33,   183,   255,    33, -2925,   255,   175, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,   159, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,   915, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
     342,   255, -2925,   592, -2925,  1373, -2925, -2925, -2925,  1463,
   -2925, -2925,  1381,  1383,  1384,  1387, -2925, -2925,  1161,  1800,
    1398,  1399, -2925,   865, -2925,  1361, -2925, -2925,  1171, -2925,
    1406, -2925,  1809, -2925,  1212, -2925, -2925,  1183, -2925, -2925,
   -2925, -2925,  3140, -2925,  1029,  1414, -2925,  1029, -2925,  1029,
    1029,  1029,  1029,  1029,  1821,  1822,  1829,  4792,  1428,  1833,
    4792,  1432,  1434,  1435,  1437,  1439,  1440,  1442,  4792,  4792,
   -2925,   230, -2925, -2925,  1526, -2925,  1450,  1452,  1223,  1458,
     255, -2925,   255,  1464, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925,   387,  1238,  1270,  1129,  1427, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  1242,  1280,  1405, -2925,  1250,
   -2925,  1249, -2925,  1891,  1253, -2925, -2925,  1444, -2925,  1293,
   -2925,  1390,   131, -2925, -2925, -2925,  1369, -2925,  8676, -2925,
   -2925, -2925,  3405, -2925, -2925, -2925,   832, -2925, -2925,  1293,
   -2925,   -64, -2925, -2925,  1605, -2925,    87, -2925,  1419, -2925,
   -2925, -2925, -2925,  1905, -2925, -2925,   352, -2925,  1264, -2925,
    1268,  1905, -2925,  1285, -2925, -2925,  1465,   103, -2925,  1429,
   -2925,  1229, -2925, -2925, -2925, -2925,  1233,   181,  -189, -2925,
    1242,  1564,  1282,  4792,   163,  4792, -2925,  1923,   183, -2925,
   -2925, -2925, -2925, -2925,    41,    41,    41, -2925,    41,  2586,
      41,    41,  1305,   -64,  1305,  1305,  1054,  1054,  1305,  1305,
     -64, -2925,  1931, -2925,   575,  1940, -2925,   -64,   187,  1262,
   -2925, -2925,  4792, -2925, -2925, -2925,   975, -2925, -2925,   415,
    1535,   415,  4792, -2925,    69, -2925, -2925,  4792,  1484,  1489,
    1493,  1498,  1371,  1499,  1036, -2925,  1581,  1017,  1345, -2925,
    1353, -2925, -2925,   255, -2925, -2925,  1055, -2925,  1963, -2925,
    1964,   255, -2925,    -4,  6168,  1376, -2925, -2925,  1980, -2925,
    1294,  1980, -2925,  1296,  1980, -2925,  4792,  1980, -2925, -2925,
     131,   832, -2925, -2925,  1536,   777, -2925, -2925,  1524,   832,
    4792,  1528, -2925, -2925,  1970,  1975,  1900, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  1063,  1063,   183,   183,   183,
    2535, -2925, -2925,  1875,   342, -2925, -2925,   669, -2925, -2925,
   -2925,  1509, -2925, -2925, -2925, -2925,  4312,  1534, -2925, -2925,
    1358,   255,  1170,   933,  1391,  1389, -2925,  4922,  4922, -2925,
    1242, -2925, -2925,  1180, -2925, -2925,  4086,  1541, -2925,  1548,
    1551, -2925,  1552,  1554,  1555,  1556,   255,   -40, -2925, -2925,
   -2925, -2925,   174, -2925,   255,  2219, -2925,  1569, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    8676,   341, -2925, -2925,   370, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  1530, -2925,   376, -2925, -2925,
   -2925, -2925, -2925, -2925,   -29, -2925, -2925,   -29,   717,   204,
    2001, -2925, -2925,   381,   334,   522,  2023, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,   255,   255, -2925, -2925,  1413,
    1280,  1249, -2925,  1018,  -213,  1074,   255,  1293,  1400,  1375,
    1408,  1570, -2925,  1572,   119, -2925, -2925, -2925, -2925, -2925,
    2035, -2925, -2925,  1380,  1576, -2925, -2925, -2925,  1018,  1085,
   -2925,  1085,  1036,   179,  4792,  4792,  4792,  1577, -2925, -2925,
     832,   832,  1293,  1386,  1036,    33,  1262,    51,   832, -2925,
    1388,  4792,  1662, -2925, -2925,  1460, -2925, -2925,   255,  2049,
   -2925, -2925,    75,   131, -2925, -2925,  2041,  2043, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,  1814, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,  9306, -2925,  1054,  4792,
    -145,  2034,  2037, -2925, -2925, -2925, -2925, -2925,   130, -2925,
   -2925, -2925, -2925,  1873, -2925,  1810, -2925, -2925, -2925,  4792,
     126, -2925, -2925,   255,  2042,    33,    33, -2925,  1443, -2925,
      33,  1411,   832, -2925,   255,   255,  4792,    15, -2925,  1459,
   -2925, -2925,   247, -2925,  1557, -2925,  1558,  4792,   852, -2925,
   -2925,  1417, -2925,  2073, -2925,  1500, -2925,   832, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    5468, -2925, -2925, -2925, -2925,   255,    33,    33,   173,   777,
    1894,  1377,   832,   131, -2925,  1502, -2925, -2925,  2049,  2054,
    1650, -2925, -2925, -2925, -2925, -2925,  1731,  1731, -2925,   180,
    1510, -2925,   255, -2925, -2925,  1293,  1293, -2925, -2925, -2925,
     255, -2925,   255,   -99,  1293, -2925,   773, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,   148,   148,   567,   684,
   -2925,   591, -2925,   669, -2925,   -29,  2063, -2925, -2925,  1137,
    1665,  1628, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    1496, -2925, -2925, -2925,  1549,  1549, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925,  1436,   -99,  1668,   360,   530,  3140,
     530,   530,   530,   530,  1446,  3140,  3140,   182,  1542,   613,
   -2925,  3140,  3140,  3140,  3140, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,  1018,  4792, -2925, -2925,  1670,  2063, -2925, -2925,
   -2925, -2925,   -29, -2925, -2925,  1293, -2925,   668, -2925,  1632,
   -2925, -2925,   668, -2925, -2925, -2925,  1635,  1638,   322,  1639,
    1642,  1404, -2925, -2925, -2925, -2925, -2925, -2925, -2925,   255,
   -2925, -2925,   322,  1415, -2925,   387, -2925, -2925, -2925,  1687,
     280,  1466, -2925,  1036,  1506, -2925, -2925,  1624, -2925, -2925,
   -2925,  1538,  1655,   255,   255,   255, -2925, -2925, -2925,  3405,
     255, -2925,  1472, -2925, -2925, -2925, -2925,  1467, -2925,  2120,
    2121, -2925,  2124,  1516,  4792, -2925, -2925,  2129, -2925,  1480,
   -2925,  1617,  1477, -2925, -2925, -2925,  1479,   837,   255, -2925,
   -2925,  1674,   183,   737, -2925,  4792,  1293, -2925,   255,   255,
    4792,    37,   -64,  2137,  2135,  2118,  2122,  2586, -2925, -2925,
   -2925, -2925, -2925,   832,  1789, -2925, -2925,  2048,  4792,   415,
    1073, -2925, -2925,  1792,  2152,  2154,   400,  1732,   255,  1740,
    1036, -2925,  4792,  1698,  1703, -2925, -2925,  1772, -2925,  4792,
     203, -2925,  1539, -2925, -2925,   584, -2925,  4792, -2925, -2925,
    1522,   339, -2925,  1145,   255,  2172,  5108, -2925, -2925,  1018,
     832, -2925, -2925,   201, -2925, -2925, -2925,  1492, -2925,  1608,
    1609, -2925, -2925, -2925, -2925,    33,    33, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  1568, -2925, -2925, -2925, -2925,
      33,  4525,  2183,  2164, -2925,  1036,   241,   192,   367,  2060,
     -30,  1013, -2925,    -7, -2925, -2925, -2925,  1733,    -5,  1293,
     101, -2925,  1544,  1545, -2925, -2925,   617, -2925, -2925, -2925,
   -2925,  1734,  1543,  2197, -2925, -2925, -2925,   832,   176, -2925,
   -2925, -2925,  1533,   684, -2925,   255,   255, -2925, -2925,   255,
     558, -2925, -2925, -2925, -2925,  1742, -2925, -2925, -2925,  2182,
   -2925, -2925,  1486,  3140, -2925,   278,  1783,  2207, -2925, -2925,
   -2925,  3140, -2925,   407,  3140,  3140,  3140,  3140,   255,   409,
   -2925,   335,  2208, -2925, -2925,   255,  3964, -2925,  1811,   255,
    1560,   530,  1848, -2925, -2925, -2925, -2925, -2925, -2925,  8676,
   -2925,  1756, -2925,  1729, -2925,  1744, -2925,  1753,   418, -2925,
    3964,   424,   149,   149,   429, -2925,   149,  3964, -2925, -2925,
    1767,  1180,  1180, -2925,  1768, -2925,  1775,  1776, -2925,  1777,
    1779, -2925, -2925, -2925, -2925,    42, -2925, -2925, -2925,   432,
   -2925, -2925,   439,   255, -2925, -2925,  1074,  2221,  1036,  1258,
    4792, -2925,   255,  2222, -2925, -2925, -2925, -2925,   322, -2925,
   -2925,  1575,   322,   139, -2925,  1036,  4792,  4792,  4792,  3925,
    2226,  1293,   142, -2925,  1036,   255, -2925, -2925,   255,   255,
   -2925,   823, -2925, -2925,   833, -2925,  1590,  4792, -2925, -2925,
   -2925,  2240, -2925,  1594,  2246, -2925, -2925, -2925, -2925, -2925,
     255, -2925, -2925, -2925,  1661, -2925, -2925,   442, -2925, -2925,
   -2925,   832, -2925,  7525, -2925, -2925, -2925,  1893,  2236, -2925,
    1880,  1885,  1780,  1613,  1888,  1805, -2925, -2925, -2925,     3,
    1877, -2925, -2925, -2925, -2925,  1772, -2925, -2925, -2925,   188,
     593, -2925, -2925, -2925,  2049,  4792,  1816, -2925,  1781, -2925,
   -2925, -2925, -2925,  2274, -2925, -2925, -2925,  1823,  2277, -2925,
   -2925,  1597, -2925,  2258,   -64,   255,  1738,  1738,  1738,  1738,
   -2925,  2280, -2925,  2281,  1738,  1738,  1738,  1738,  1814, -2925,
   -2925,  1738,  1608, -2925, -2925, -2925, -2925,  2263,  2283, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,  2284, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,   447, -2925, -2925, -2925,
    2265, -2925, -2925,  1293, -2925,   -99, -2925, -2925, -2925, -2925,
   -2925, -2925,  1663,  1671,   324, -2925,    -7, -2925,   149,  1644,
     183, -2925,  1834, -2925, -2925, -2925,   255,   255,  3140,   547,
   -2925,  4792, -2925,  4792, -2925, -2925, -2925, -2925, -2925, -2925,
     183,   149, -2925,  1293,   973,  2298, -2925,   832,   255,   787,
     787, -2925, -2925,  2299, -2925,  2299,   618,   618,  2299, -2925,
   -2925,  1710, -2925,  1879,  1846, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,   174,  1180,  1653, -2925,  1180,  1889,  3140, -2925,
    1892,  1895,  1896,  1906, -2925, -2925,   182, -2925,   182, -2925,
   -2925,  6879,  1849,  3439,  1849,  2327,  2330, -2925, -2925, -2925,
   -2925, -2925, -2925,   797,  3140, -2925,  1854, -2925,  2033,   168,
     192,   255, -2925,  7943,    72, -2925,  1710,  1580, -2925,    72,
     149,   668, -2925,   186, -2925,  1293,   422,  1912,  2336,  1690,
   -2925, -2925,   449, -2925,   322, -2925,   453,   221,  2318,  1685,
    -160,  2328,  2328,  2329,  2328,  2328, -2925,   121, -2925,   668,
     255, -2925,   322, -2925, -2925,  1701,  1036,  2349,   244, -2925,
     315,   462, -2925,   255,   463, -2925,  4792,  1932,  2339,   477,
    1036,  2364, -2925, -2925, -2925, -2925,  4792,  1769,  2068,  4792,
   -2925, -2925, -2925, -2925,   833,   882,   882,  2376,  -217, -2925,
    2377, -2925, -2925, -2925,   882,   255,  1801,  1181,  2379,   255,
     150,  1293,  -149,  4792, -2925, -2925,  2586, -2925,  1688,  4792,
   -2925,  2382,  4792,   832, -2925,  1027,   255,   832, -2925,  1960,
    4792,  4792, -2925, -2925,     3,  1877, -2925,  1814, -2925, -2925,
    1117, -2925, -2925,  1785, -2925,  1258,  4208,  5108,   832,   832,
      60,   818, -2925, -2925, -2925,  1739, -2925, -2925, -2925, -2925,
      33,  1738,    33,  1738, -2925, -2925, -2925, -2925, -2925, -2925,
     -64, -2925,  1087,  1110,  4525, -2925,  1965,  1928,  3140, -2925,
     367,   367, -2925, -2925, -2925, -2925,   478, -2925,  1890, -2925,
     149,   -85, -2925,  1735, -2925,  2394,  8970,  8970,  8970,  8970,
     149,   149, -2925, -2925, -2925,  1812, -2925,   479, -2925,  1741,
   -2925,   832, -2925,  2299, -2925, -2925,   255,   618,   618, -2925,
   -2925,   618,  2155,  1745, -2925,  2380,  1979,  1747,  1486,  1748,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925,   483, -2925, -2925,
    1904, -2925,   411,   276, -2925,  3964,  3964, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,  4922,  4922,  1946,  4922,
    1947, -2925,  4922,   576,  3140,  2410, -2925, -2925,  3964, -2925,
   -2925, -2925, -2925, -2925,  2411, -2925,   336, -2925, -2925,  2033,
    1758, -2925, -2925,   126,   126,   126,  2393,   126,   126,   126,
     126,   126,   126,  2395, -2925,  2396,   126, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  7943, -2925,   832,  1765, -2925,
    1939,  2155,  2398, -2925,  2399,  2400,  2401,  2402,  2403,  2404,
    1142,  1580, -2925,  1939, -2925,   484, -2925, -2925, -2925,  2406,
   -2925,  2091,   149,  1203,   149, -2925, -2925, -2925, -2925, -2925,
    2005,  1486,  2408,  1486, -2925,  2430,  2430,   487,  2008,  2430,
   -2925, -2925, -2925,   668, -2925, -2925, -2925, -2925,  1036, -2925,
   -2925, -2925,   255, -2925, -2925,   322,  2033,  2049, -2925,  1934,
   -2925,   200,  1036, -2925,  2434,  1973, -2925, -2925,  2015,  1861,
   -2925, -2925,   255,   882,  1258,  1213,   255,   882, -2925, -2925,
      33, -2925, -2925,  4792, -2925, -2925, -2925, -2925, -2925, -2925,
      33,  2049,   832,  2170, -2925,  2423,  1608,  8676,  2425, -2925,
   -2925,   131,  1988, -2925, -2925,  4792, -2925, -2925,  2024, -2925,
   -2925, -2925,   593, -2925,  1608, -2925,  4792, -2925,   257, -2925,
    1940, -2925, -2925, -2925, -2925, -2925, -2925,  1976,  2072, -2925,
    2435, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,   255, -2925,   113, -2925, -2925, -2925,   149, -2925,
     -99,  2278,   491, -2925, -2925, -2925, -2925,   255,  1868,  4802,
    4802, -2925, -2925,  9192,  1992, -2925, -2925,  1994,  1996, -2925,
    1998,  1999,  2000,  2002,   255,   465, -2925, -2925,   497, -2925,
   -2925,  2234, -2925, -2925, -2925,   500,  2463,  2463, -2925, -2925,
     508,  2466,  2458, -2925,     2, -2925, -2925,   149, -2925,   171,
   -2925, -2925, -2925, -2925, -2925,  2225,  4312,  2046, -2925,  1486,
   -2925,  1486,   182, -2925, -2925,  2330, -2925,  2003,  2219,  2003,
     161, -2925,  2003,   161, -2925,  2003,  4922, -2925, -2925,  3140,
   -2925,  3140,  2327,   168, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925,   353,  2472, -2925,   832,  1175, -2925,  2225,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,   262, -2925, -2925, -2925,  1983, -2925, -2925, -2925,
    2051, -2925,  2454,  2058,  2059,  2456, -2925, -2925,  2061, -2925,
   -2925, -2925, -2925, -2925,    33,   -64,  2077,  1036, -2925,  4792,
   -2925,  1886,  2465,   -64, -2925, -2925,   881, -2925, -2925, -2925,
   -2925,  1861,  2064, -2925,  2277,  2215, -2925,   -64,  2066,  2067,
    2137,  2029, -2925,  2115,  2071, -2925, -2925, -2925, -2925,  2223,
    2011,  4792,  2026, -2925, -2925, -2925,  1608, -2925,   509, -2925,
     832,  1925, -2925, -2925, -2925,  3140, -2925, -2925,   149, -2925,
    2047, -2925,  1925,  2245,  2245,  2081,   360,   530,  9326,   530,
     530,   530,   530,  1855,  9326,  8970, -2925,  9326,  9326,  9326,
    9326, -2925, -2925,   149,  2499,   149,  8970,   183,  3964, -2925,
     832, -2925, -2925,   379, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925,   121, -2925, -2925,   512, -2925, -2925, -2925,
   -2925,   513, -2925,  2003,  2508, -2925, -2925, -2925, -2925, -2925,
   -2925,   832,  2472, -2925, -2925, -2925,   832, -2925,   832, -2925,
   -2925,  1770, -2925,  2239, -2925,  2241,  2491, -2925, -2925,  1858,
   -2925, -2925, -2925, -2925,  2092, -2925, -2925, -2925,  1036, -2925,
    2093,  9486,  2056, -2925, -2925, -2925,  1866,   -64, -2925, -2925,
   -2925, -2925, -2925, -2925,  2096,   131, -2925,  2115,  2115,   593,
   -2925,  1258,  1914, -2925, -2925,   255, -2925,  2277,   613,   174,
   -2925,  8817,   613, -2925,  2099,  9326, -2925,   519,  9326,  9326,
    9326,  9326,   255,   520, -2925, -2925, -2925, -2925, -2925, -2925,
    2062, -2925, -2925, -2925,  2327,  2277,   171, -2925, -2925, -2925,
   -2925, -2925,    74, -2925, -2925, -2925,  3140, -2925,  1681,  1681,
   -2925,  1681, -2925,  1681,  1681, -2925, -2925, -2925,  2065,  1486,
   -2925,  1064, -2925, -2925,    41,    41,    41,    41,    41,    41,
   -2925,  2505, -2925,   533, -2925,  4792,  1222, -2925,     4,  2115,
    4792,  2115,  2137, -2925, -2925, -2925,  2252,   269, -2925,   -64,
   -2925, -2925, -2925, -2925,   534, -2925, -2925,  1132, -2925,  2104,
    9326, -2925,  2105,  2106,  2108,  2109, -2925, -2925,  8970, -2925,
   -2925, -2925, -2925, -2925,  1681, -2925,  1681, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  1167, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  9486, -2925,  2533, -2925, -2925,
   -2925, -2925,   549, -2925, -2925, -2925, -2925, -2925, -2925,   201,
   -2925,  8817, -2925,  1508, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,   537, -2925, -2925,  1199,  1199, -2925, -2925,  1199,
   -2925,  4792,   610, -2925, -2925,  2111,    60, -2925,  1887,  1899,
    2542, -2925, -2925, -2925, -2925, -2925,  2112, -2925, -2925, -2925,
     255,   255,  1508, -2925,   189,  1902, -2925, -2925, -2925,   131,
   -2925,   255,  2137, -2925
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2925, -2925, -2925, -2925, -2925,  -126, -2925,   -68,  -168, -2925,
   -2925, -1098,   -73, -2925, -2925, -2024, -2925, -2925, -2925, -2925,
    -897, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -1954, -2925,  -959, -2925,
    1591, -2925, -2925, -2925, -2925, -2925, -2925, -2925,   177, -2925,
   -2925, -2925, -2925,  1083, -2925,   464, -2925, -2925,   -20, -2925,
   -2925,  2534, -2925,  2538,  2039, -2925, -2925, -2925, -2925, -2925,
     240,   -84, -2925,   242, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,   -91,   419,   911, -2925, -2925,
    2227,    16, -2925,  2461, -2925, -2925,  2468, -2925,  2366, -2925,
   -2925, -2925, -2925, -2925,  2243,  1944,   619,  2242,  -522, -2925,
   -2925, -2925, -2925, -2925,   626,  -628, -2925, -2925, -2925, -2925,
   -2925, -2925,  -209,  2084,  2378,    62,  2007, -2925,  2069,  1370,
   -2925,  2229, -2925, -2925, -2925, -2925,  2235, -2925, -2925, -2925,
   -2925,  -384, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    2074, -2925,  2070, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -1285, -2925, -2925,  -833, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  -128, -2925, -2925,   596, -2925,
   -1059, -1094,  -545, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,  1657, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    -593, -2925, -2925, -2925, -2925, -2925,  1843, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  -520, -2925,  -101, -2925, -2925,
   -2925, -2925,  2210, -2925, -2925,  1159, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925,  1412, -2925, -2925, -2925, -2925,   435, -2925, -2925, -2925,
   -2925, -2925, -1320, -2925, -2925,   430, -2925, -2925, -2925, -2925,
   -2925, -2925, -1057,  -763,   304,   569, -2925,  -248,   616, -1070,
     856, -2925,   405, -2925, -2335,    -3,  -138, -2925, -2925, -2224,
     235,  1953, -2925, -2925, -2925,   638,   806, -2925, -2925, -2925,
   -2925, -2925, -2925,   -69, -2925,  -355, -2925,   808, -2925,   507,
   -2925,   224, -2925, -2925, -2925, -2925,  -859, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,   319, -2925, -2925, -1782, -2925,
     496, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925,  1265, -2925, -2925, -2925,
   -2925, -2925, -2925,  -528, -2925, -2925, -1989, -2925, -2925, -2925,
   -2925,   467, -2144, -2925, -1069, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,  2631,
   -2925, -2925, -2925,  2556,  2609, -2119, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925,  -469, -2925, -2925, -2925, -2925, -2925,  2613,
   -2925, -2925,  2633, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925,   554, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925,  -666,  1930, -2925, -2925, -2925, -2925,
   -2925,  1759, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    2266, -2925, -2925,   -21, -2925, -2925,   550, -2925, -2925, -2925,
    -993,  -169,  2340, -2925, -2925, -2925, -2925,   612, -2925, -1007,
    1682,   834, -2649,   -33, -2925,   551,  1487,  -447,  -600, -2925,
   -2925,  1920,  1306, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925,  1243, -2925,  -735, -2925,  -636, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925,  -784, -2925, -2925, -2925, -2925,
   -2925, -2925,   -17, -2925,  1320,   525, -2925, -2925, -2925, -2925,
   -2925,  -190, -2925,  -597, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,  1553,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925,  -501, -2925,  1227,
    2247, -2925, -2925,  -181, -2925,  -661, -2925, -2925,  -164,   118,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925,   722, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2525, -2925,  -214,   388, -1298, -2925, -2925,
   -2925,   706, -2925, -1898, -2925, -2925, -2925, -1914, -2925, -2925,
   -1907, -2925, -2925, -2925, -2925,   730, -2925, -2925, -2925, -2925,
   -2925, -2925,   231, -2925, -2925, -2925, -2925, -2925, -2925,  -767,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925,  -387, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,   213,
   -2925, -2925, -2925,  -648, -2925, -2925, -2925, -2925, -2925, -2925,
    -163, -2925, -2925,   141, -2925,   456, -2925, -2925, -2925, -2925,
   -2925, -2925, -1288, -2925, -2925, -2925, -2925, -1892, -2925, -2925,
   -2925, -2925, -2925, -2925, -2289,   492, -2925, -2482,   559, -2925,
   -2925, -2214,   -71,   -65,   184, -2925, -1819, -2513, -2925, -2925,
    -351,  -629, -2925, -2925, -2925, -2925, -1840, -2925, -2925, -2925,
   -1779, -2925, -2925, -1063, -2925,  -984,  2079,   884,  -402, -1889,
     153, -2925, -1522, -2925, -2925, -2925, -2925,   -42, -2925, -1297,
   -2618,  2731, -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2925,
    -771, -2925, -2106, -2925,  1546, -2925, -2925,   572,   185, -2925,
   -2297,   178,  -266,    12, -2273, -1823, -2147,   821,  -337,  -820,
   -1214, -2925,   824, -2925, -2925, -2925,   913,  -747, -2925, -2925,
    -564,  1559, -2925,   774, -2925, -2925, -1797,  -253, -2925, -2925,
   -2925, -2015,  -449, -2925, -2925, -2925,   948, -2925, -2925, -2925,
   -2925, -2925, -2925, -2925, -2925, -2925, -2925, -2613,  -466, -2925,
   -2661, -2924, -1684, -1471, -2925, -2925,  -454, -2925, -2925, -2925,
     110,  -657,  -627,  -774,   476, -1587,   158, -2925, -2925, -2925,
   -2925,  1402, -2925,  -247, -2925, -2925, -2925, -2925, -2925, -2925,
   -2925, -2925,  -285,   890,  2250, -2925, -2925, -2925, -2925
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2147
static const short yytable[] =
{
      34,    36,    38,   265,   554,    38,   184,   972,   401,   402,
    1293,   403,   404,   350,  1332,  1344,   416,  1993,  1394,  1440,
    1971,   325,  1129,  1914,  1915,    87,  1392,   960,  1448,   657,
    1422,  1027,  1123,   104,   919,  1341,   233,    58,  1401,  1402,
    2174,  1403,  1010,  1424,  1425,   293,  2583,  2129,  2130,   103,
    2776,    58,   929,  2597,  2689,  1354,   924,    71,  2333,  2018,
      33,  1057,   110,    33,    33,  2173,  2532,  1395,    33,   117,
     184,  2265,    87,   122,  1459,  2290,   124,   125,    33,   271,
    2055,   494,   128,   129,    33,   113,  3045,  3046,  3047,   184,
    2224,  2225,  2226,  2227,  2291,  1082,  1022,  2720,   271,  1240,
    1241,    33,  2213,    58,   330,  2651,  1032,  2473,  1371,   271,
     331,   332,   575,   271,   326,   327,    33,  1828,  1936,   576,
     229,  1087,  1264,   232,  1833,  1010,  1166,  2457,   236,     1,
      71,  1838,   405,     2,   197,  1439,   417,  3049,   419,  1851,
     420,   421,   422,   358,   359,   271,  2900,  1241,  1029,   427,
     271,   503,  1023,   438,   439,   271,  1178,  1179,    33,  2985,
    3070,  1083,  2641,  1085,  1127,   323,    33,  1339,  1371,    33,
    2946,  1043,  1122,  1829,  1339,  1339,    33,    33,  2055,  1936,
    2057,  2507,  2058,  2480,  2059,   271,  1240,  1241,    33,   328,
    3237,    76,  2795,  1339,  2823,    33,    77,  1496,    33,   271,
    1178,  1179,    33,   101,  1050,  3156,    33,  1339,    33,    33,
      33,  1359,  1360,  2688,   551,    33,  1116,  1127,   184,    33,
     547,   323,   184,   549,   557,  1130,  1136,  2795,   355,  1151,
     323,    33,  1331,  1157,   361,   323,   436,  2073,   640,  1163,
     351,  1165,   642,    78,    79,     4,   390,  2857,  1188,   323,
     101,    80,   399,   399,   399,   399,   399,  2786,   114,  2788,
     399,  1187,   323,   646,  1332,   563,  1855,  3286,    33,    54,
    2102,  2477,   344,  3139,   323,  3141, -2145,  2949,  2934,  2791,
     572,  2794,    33,  2533,  2718,  2797,  2798,  2606,  2799,  2800,
    2801,  2802,  2803,  2804,  3079,   583,  3082,   939,   586,  3085,
   -2145,  3344,  1006,  3174,  3097,  1441,  1442,  2892,    44,    58,
      58,   907,  3352,  2483,   922,   594,   595,   596,   597,   505,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,  2138,   633,  2792,
    2217,  2745,  2333,  1431,  1432,   908,  1953,   615,   616,    33,
    2077,    33,   618,  2012,   619,   511,  2158,  2159,   514,    54,
    1339,    33,    33,    71,   155,     6,    33,    54,  2734,   622,
     623,   624,   625,  2590,  2593,  1953,   631,  2593,  1497,   998,
   -2145,  1958,   998,   998,  3356,  1005,  2063,    33,  2040,  1006,
    3518,  3153,  2096,  1381,    33,   923,   998,  1471,   901,  2003,
   -2145,  2570,  2772,    54,    48,   562,   184,    54,    33,    54,
    2484,   559,  2538,   940,  2538,   998,    54,  2795,   998,    10,
      54,   902,  3010,  2581,   998,   564,  1926,  1935,   998,  2581,
    3014,  1188,   998,  2642,  2594,    10,   998,  2610,  2935,  2004,
     998,   998,  1188,   998,  2612,     7,   998,  2666,   998,   998,
     998,  3250,  2724,  3251,  2884,   107,   998,  2861,  2884,   998,
     106,   107,   184,  1072,  1382,   971,   998,  2912,  2915,    54,
    2143,  1188,   998,  3037,  3037,  3037,  3037,   573,  2607,   998,
    1308,  1309,  2915,  3008,  3057,   274,  2074,  1351,  3072,  2882,
     998,    52,  3145,    58,   998,  2112,  3208,  1074,   998,    26,
      27,  2893,  3225,    81,   998,  3225,  1243,   998,  1310,  1311,
    1312,   805,   899,  3233,  3325,  1118,  1119,  3362,  3362,  2103,
     649,  1244,   941,   649,  3420,  3420,   996,  2463,   362,    82,
     552,   649,  2406,   184,  1866,  3081,   559,  3084,  3455,  3471,
    1191,  1189,  3225,  2971,  1172,  2950,   946,  1175,   390,    33,
     390,  3327,  2656,  1243,    26,   363,  2001,  2236,   921,   399,
    3357,   926,  1033,    69,  3238,  1033,  2805,    54,  1244,    27,
     995,  3519,  1850,  3263,   644,  1042,  1498,  1116,  1396,  1033,
    2384,  3004,  2350,  1033,  2735,  1190,  3086,  1130,  1006,  2737,
    1059,  3355,  1462,  1243,    33,  1033,  1180,  1042,   102,  1190,
      83,  2474,  1378,  1070,  3092,  1976,  1042,  2102,  1244,  1499,
    1857,  3157,  2758,  1079,  2877,  2027, -2145, -2145,  1977,  1086,
    3349,  3177,  2858,   324,  3005,  3006,  1121,  2042,  1454,  1476,
    1457,  1397,  2746,  2747,  2748,  2749,  2750,  1070,  2986,  3187,
     935,  1070,  2728,   548,    33,  1070,   550,   558,  1073,  2888,
     649,  1042,   105,  2160,  1042,    58,    58,    58,    58,   991,
     993,   641,   999,  1000,  1976,   643,  1007,  1012,  1925,   993,
    3242,  1972,  1015,  1960,    58,  2071,  2002,  1977, -2145,   508,
    2827,  1916,  1153,  1000,  2806,  2807,   647,  2886,   970,   891,
    2744,  2590,    84,  1294,  1993,  1372,  2905,  2028,  1181,  2465,
    3000,  2022,  3200,  1000,  2214,  1898,  1010,  2909,  3164,    58,
     292,   995,  3169,  1909,  2906,    58,  1000,    58,   577,  3328,
    3190,    58,  1460,  1191,    58,  3287,  1060,    58,  2060,   292,
    3332,  1010,  3468,  2231,  1191,   396,  2061,    58,   925,   396,
     292,  2808,   399,  1076,   292,  1398,  3037,  3037,  1361,  1007,
    3037,  2630,    58,   396,   995,  1391,  1937,    58,  2508,   399,
     399,  3440,  1443,  1191,    58,    58,    58,  3482,  1917,  1954,
    1147,  2947,    85,  1154,  2413,  1196,   292,  2352,    58, -2145,
      86,   292,  1833,  3252,  1918,  1167,   292,  1167,   399,  2585,
    1167,   399,  2215,  1167,    58,    54,  2585,  2585,  1955,  2082,
    1051,  1989,  2546,   998,  1959,  1976,  2797,  2798,   276,  2799,
    2800,  2801,  2802,  2803,  2804,  2585,   292,  2099,  1977,  2029,
    2030,  2031, -2145, -2145, -2145, -2145, -2145,  1919,  2370,  1280,
     292,  1863,  1280,   279,  1979,  2539,  2049,  2545,  2655,  3074,
     631,   631,  1897,  1192,  1193,  1194,  2582,  3412,  1978,  1444,
    1980,  3013,  2584,    53,  1195,    33,  2103,  2595,     1,    33,
    2611,  3324,  2929,  3087,  1964, -2145,  1920,  2613,  2809,  3493,
    2667,  2167,  2168,   114,  1863,  2725,  2515,  2885,  1313,  2518,
    2175,  2887,  2138,   314,   315,   316,   317,   318,   118,  2910,
    2913,  2916,  2107,  1979,  2072,  1921,   406,   407,  1216,   314,
     315,   316,   317,   318,  1922,  2920,  3009,  3058,   116,  1980,
    3094,  3073,  3131,  1964,  1130,  3146,   285,  2879,  2534,  3209,
    2519,    43,   998,   998,   998,  3226,  2218,  3268,  3232,     1,
   -2145,  2095,  3224,     2,  2810,   112,  3234,  3326,  2911,  1257,
    3363,  3364,  2110, -2145,   191,  3037,  1437,  3421,  3427,   190,
    1121,  3037,  3037,  2235,  3037,  3037,  3037,  3037,   231,  3095,
     107,  3456,  3472,  3037,  1314,  3502,  1834,    43,   314,   315,
     316,   317,   318,   194,  2599,  2600,  3269,  1303,  2177,   649,
   -2145,  2257,  2239,  2391,  2811,  2812,  -272,   109,  2187,  1992,
     230,  1296, -2145,  3134,    33,  3137,  2490,  1438,  2358,  3088,
     238,  3089,  1965,  1007,   995,  2491,  1364,  1315,   288,    33,
    2625,     3,   591,  1365,  2625,  2143,  1340,  1211,  1212,    58,
     289,   290,  1834,   240,  3354,  2326,  3231,  2327,   291,  2492,
    1428,  3411,  2493,    58,  1979,  3417,  1340,  1435,   988,  2326,
      33,  2327,  2219,  1005,    37,    33,    33,  2015,  2394,  2494,
    1980,  1965,  2652,  1016,    33,  1080,    54,    33,  3329,   250,
      54,  1127,  3037,    33,   247,  3037,  3037,  3037,  3037,  1848,
    1086,  1121,  2343,  -272,    58,  2195, -2145, -1540,  1966,    53,
    1481,    33,    33,   254, -2145,  2901, -2145,  2805,  1844,  -272,
      33,    58,    58,    58,  2006,    58,   248,    58,    58,  2365,
      33,    33,     4,    58,    58,   933,  2498,   934,  2195,  2222,
    2023, -2145,    33,  2996,    33,  2222,  1264,  3144,   251,  3204,
    3148,  2244,  2245,  2246,  2247,  1138,   255,  1966,  2043,  1074,
     256,  2328,  -272,  2376,  2329, -2145,  2998,    33,   654,  1469,
    1065,    58,  2973,   257,    33,  2328,   905,  3037,  2329,  1071,
    1480,  2220,   258,    58,  2495,  3037,  2138,  2206,  1488,  3044,
    3044,  3044,  3044,  2240,    33,  2397,  2751,  3127,  3241,    33,
    2138,  -272,    33,     4,  2241,  1139,   408,    58,    58,   259,
    1968,   409,   410,   411,  1967,  2482,    58,  3205,  2763,   958,
   -2145,   260,   961, -2145,  1170,   261,  1969,  1173,  3231,  3231,
    -272,  2941,    58,    58,  2827,  2806,  2807,  2496,    33,  -272,
      54,  1021,  1140,  1961,  2497, -2145,  1963,   262,  2196,  2087,
     263,     5,  2089,  3135,  3036,  3036,  3036,  3036,  1900,  1968,
      33,  1037,   264,  3167,  1257,  1257,  2777,  2197,  2198,  2779,
      33,    54,  3458,  1257,  1046,  1969,  1006,  2235,  2178,    33,
     266,  2196,   901,  1934,   320,    54,  2297,  2199,  1006,  2179,
    3255,  1940,  2808,  3260,    54,   983,  3262,   321,  1327,  1328,
    2197,  2198,   308,  3273,  1218,   902,   158,   159, -2145,   992,
    2180,    33,    54,    54,   160,    33,   309,  2181,  1205,  2143,
    2199,    54,     5,  2876,   106,   107,  2405, -2145, -2145,  1206,
     367,    54,     7,  2143,   348,  1005,  1973,    33,  2000,  1141,
    1981,  1990,  1981,    54,  1993,    54,  2704, -2145,  1339,  3330,
      33,  2904,  1996,  1997,   376,  2248,    58,  1007,  1230, -2145,
    1007,     8,  2007,  2010,  1340,   354,   428,  2040,    54,  3215,
    3441,     6,   310,  2375,  3306,    54,  2111,   107, -2145,  3274,
    1207, -2145, -2145,   311,   161,  1007,    58,   322,    58,    58,
      58,  2190,  2191,  3403,  3404,  1208,   162,    58,    58,  1340,
      54,    58,   399,     7,   399,    58,   167,  3335,   418,  3338,
    3339,  3340,  3341,   312,  1142,  2054,   313,   368,   168,  2809,
      58,  1152,  3447,  1264,   163,  1158,  1467,  2138,    33,  1162,
     365,  2537,     8,   369,  2540,  2541,  2542,  2543,  2462,  3460,
    2739,   377,  3275,  1911,  3276,  1912,  2131,   366,  2132,  2133,
    2134,  2339,  2340,   429,  2309,  1143,  2475,   378,  1171,  3277,
    2756,  1174,  3044,  3044,  1177,    58,  3044,  3278,  1998,   430,
      33,  3279,   375,  3487,  3365,  3464,   370,  3466,  2178,  3442,
     335,   336,   337,  3443,  1209,  2810,  3447,  3473,  3474,  2179,
    2084, -2145,   399,   399, -2145, -2145,  3280,   399,   341,    58,
     379,  2093,  2094,  3460,  1351, -2145,   408,  1035,   345,  2727,
    2180,   409,   431,   411,  1473,   371,    54,  2181,   164,  2320,
     346,  1044,  1144,  3259,    58,  1049,  3259,  3036,  3036,   349,
    2138,  3036,  1192,  1193,  2268,  2811,  2812,  1063,   353,   380,
    2342,   106,   107,   356,   372,  2031,  1345,  1346,  1347,  2759,
    2210,   432,  2211,   373,  1004,   314,   315,   316,   317,   318,
    2143,   174, -2145,  3498,  3336,    33,   360,  1020,   381,  2896,
    3336,  2898,  2899,  3345,  3346,  3347,  3348,   382,  3213,  3214,
     433,  2617,  3442,   384,  2383,   175,  3443,   385,  3258,   434,
     391,  3258,  2235,   394,  2235,  1038,  2631,  2917,  2632,  1943,
    1944,  1429,  1430,  1901,  1474,  1433,  1434,  2643,  2364,  2125,
    2126,  1055,  1056,  1916, -2145,   165,   395,  1062, -2145,   425,
    1064,   423,  3078,  3078,  2024,  3078,  2024,  2954,  3078,   176,
     426,   437,  2980,   440,  2951,   441,   443,  2131,   177,  2132,
    2133,  2134,   447,   444,   445,  3149,   446,  3152,   166,   496,
     507,   509,  2995,  1449,  1450,  1451,  1452,   513,   515,  2217,
     516,  3044,   519,  2143,   520,   521,   524,  3044,  3044,   525,
    3044,  3044,  3044,  3044,  2166, -2145,   535,   536,   537,  3044,
    2170,  3419,   167,   540,  3422,  3423,  3424,  3425,   545,   555,
    1902,   556,   561,   562,   168, -2145,  1269,   565,  1264,  1271,
    1917,  1272,  1273,  1274,  1275,  1276,  1903,  2343,  1945,  1946,
    1947,  1948,  1949,  1950,   566,  2135,  1918,   567,  2136,   568,
    2137,   569,   178,   179,   571,   578,  3036,   579,   587,   584,
     588,   169,  3036,  3036,   589,  3036,  3036,  3036,  3036,   592,
    2138,   617,   620,  2959,  3036,   626,  2626,   170,  2781,  1904,
    2139,  2967,  2968,   627,   632,   171,   635,   634,   637,  1919,
     636,  3360,   638,  2793,   639,   645,  3477,   655,   172,  2140,
       1,  2269,   906,   911,  2817,   913,   914,   915,  3044,   920,
     930,  3044,  3044,  3044,  3044,  2619,   931,   938,  1905,   943,
    2663,  2270,  2141,   945,   947,   932,  2142,   998,  1920,   948,
     949,  2633,  2634,  2031,  2637,  3259,   966, -2145,  2862, -2145,
   -2145, -2145,   173,   968,   973,   975,   976,  1906,   977,   979,
     980,   981,  2658,  2863,  2864,   982,  1907,  1921,  2271,  1159,
     984,  1220,  2865,  1221,  2203,  1227,  1922,   174,  2696,  1222,
    2272,  1223,  1224,  3036,  2351,  1225,  3036,  3036,  3036,  3036,
    1226,  2273,  1167,   399,   399,  2249,  1228,  1229,  1231,    58,
      58,   175,  1232,  3044,  1233,  1234,  2866,  1235,  2274,  1404,
    3258,  3044,  1270,  2143,  1236,  2867,  1277,  1278,  2275,  2162,
    2693,  2276,  1340,  1340,  1279, -2145,  1282,  2171,  1283,  2171,
    1285,  1340,  1286,  1287,  2277,  1288,  1295,  1289,  1290,  2907,
    1291,  2254,  3078,   998,  2868,   176,  2135,  2405,  1299,  2136,
    1300,  2137,  1301,  2921,   177,    58,  1302,  2420,  2422,  2524,
     464,   998,  1306,  1325,  1329,  1326,  2207,  1330,  3036,  1336,
     107,  2138,  1333,  2432,  1335,  1342,  3036,  1338,  1264,  1358,
    1363,  2139,  2278,  1337,  2338,  1362,  1369,  1366, -2145,  2869,
   -2145,  1367,  1370,  1375,  1007,  1374,  1257,  1377,  1386,  1388,
    2429,  1393,  1257,  1257,  1340, -2145,  1436,  1426,  1257,  1257,
    1257,  1257,  2279, -2145,  3274,  1439,  2753, -2145,  2754,  1007,
    2363,  1463,  2280,  2141,  3180,  1455,  1464,  2142, -2145,  1446,
    1465,  2870,  1340,  1472,   631,  1466,  1470,  1476,   178,   179,
    1475,  1485, -2145,  2281,  1296,  1981,  2525,  2282,  1487,   465,
     466,   467,   468,   469,   470,  1825,  1990,  1824,  1826,  1981,
    1827,  1836,  2526,  1832,  3090,  1839,  1840,   471,   472,   473,
      58,  1841,  1842,  1888,  1896,  2283,  3182,  3275,  1927,  3276,
    2305,  2306,  2307,  1899,  2284,  1928,  1910,  2311,  1929,  1930,
    1086,  1931,  1932,  1933,  3277,  1957,  1952,  1975,  1995,  1405,
    2014,  2013,  3278,  2015,  2143,  2527,  3279,  2016,  1121,  2017,
    2019,  2020,  1332,  2021,  2034,  2336, -2145,  2041,  2048, -2145,
    2050, -2145,  2052,  1340,  2055,  2346,  2347,  3297,   399,  2065,
    2075,  3280,  2066,  2076,  2078,  3305,  2080,  2085,  2088,  2090,
      58, -2145,  2113,  2099,  2528,  2106,  2108,    58,  2114,  3310,
    2152, -2145,  2116,  1834,  2150,  2373,  2153,    58,  2235,  2204,
    2155,  2923,  2161,  2208,  2928,  2209,  2214,  2212,  2250,  2260,
   -2145,  2228,  2262,  2529,  2236,  2263,  2266,  1894,    58,  2267,
    2398,  1488,  2530,  1257,  2293,  2295,  1007,    58,  2298,  2299,
    2300,  2296,  2302, -2145,  2313,  2316,  2317, -2145,  2315,  2318,
    2618,  2319,   399,   399,  2321,  2322,  2323,   474,  2324,  2325,
     475,  2337,  1833,  2353,  2355,   329,  2360,   399,  2356,   334,
    2362,  1116,    58,    58,    58, -2145,  1406,  2368,    58,  2369,
    2371,  3150,  1407,  1408,  1409,  2377,  1340,  3353,  2374,  2381,
    2378,  2387,  3099,  3100,  3101,  3158,  3103,  3104,  3105,  3106,
    3107,  3108,  1410,  2395,    58,  3111,  2401,  1195,  2460,   998,
    2461,  2415,  2514,  2514,  2413,   998,  2514,  2472,   184,  2486,
    2478,  2501,  2504,  2503, -2145,  2522,  2487,  2511,  2523,  3397,
    1257,  2535,  2536,  2548,  2569,   998,  2564,  2571,  1257,  2572,
    2580,  1257,  1257,  1257,  1257,  2544,  2573,  2623,  1340,  2616,
    2628,  2639,  2549,  1257,  2598,  2601,  2567,  1941,  1942,  1943,
    1944,  2577,  2602,  2603,  2604,  2657,  2605,   495,  2659,  2660,
    2664,  2661,  3227,  3228,  3229,  3230,  2670,  1257,   476,  2586,
    2586,  2671,  2673,  2586,  1257,  3229,  3230,  2674,  2676,  3264,
    2677,  2817,  2678,   477, -2145,  2675,  2695,   478,  2694,  2697,
    2698,  2067,  2699,  1194,  2703,  2710,  2712,   553,  2721,  1411,
    2614,  2726,  1412,  2007,  2730,    58,  2738,  2722,  2723,  2620,
    1413,  2740,  2731,  2761,  2766,  1981,    63,  2774,  3402,  1981,
      58,  3470,    58,  2775,  2778,   479,  2790,  2780,  1340,  2586,
    2782,    58,  2336,  2783,  2784,  2648,  2648,  3448,  3449,  3450,
    3451,  3452,  3453,  2795,  2785,  1414,  1086,  2796,  2818,  2821,
    2881,  2882,  1121,   480,  2889,  2883,  2891,  2662,  1945,  1946,
    1947,  1948,  1949,  1950,  2894,  2897, -2108,  2908,    58,  2919,
    2918,   481,  1121,  1945,  1946,  1947,  1948,  1949,  1950,  2922,
    1415,  2924,   156,   187,  1945,  1946,  1947,  1948,  1949,  1950,
    2925,  2932,  2936,  2940,  2943,  1264,    58,  2958,  2966,  1416,
    1417,  2955,  2976,  3001,  2990,  3002,  3017,  3010,  3172,  1936,
    1418,  3055,  3059, -2145,  3066,  1419,  3067,  3068,  3069,  3071,
    3299,  1925,  2705,  3080,  3083,  3091,  3093,  3098,  3102,  3116,
    3109,  3110,  3117,  3120,  3121,  1965,  3122,  3123,  3124,  3125,
    3126,  3188,  3132,  3138,  3140,  3142,  3147,   187,  3154,  3159,
    3160,  3465,   482,  3161,  1420,   998,   998,  3162, -2145,  3176,
    3178,  3181,  3185,  3193,  1189,  3196,   187,  3200,  3206,  3216,
    1340,  3217,  2991,  3218,  2993,  3219,  3220,  3221,  3225,  3222,
    3267,  3235,  3236,  3246,  3249,  2586,  1421,  3271,  2879,  3289,
    3290,  3253,  3294,  2742,  2171,  1257,  3292,  3293,  3298,  3295,
    3302,  3304,  3308,  3309,  3311,  3312,  3313,  3315,  2586,  3317,
    1340,   899, -2145, -2145,    58,  2514,  3321,  1937,   483,  3333,
    3342,  3416,  3522,  3350,  3331,  3366,  3376,  3378,  3377,  3379,
    3380,  3396,  3383,  3395,  3401,  3408,  2978,  3418,  3439,  3428,
    3454,  3467,  3476,  3478,  3479,  1257,  3480,  3481,  3491,  3508,
    3513,  2957,  3510,  1340,   631,  1340,  3431,  3512,  1257,  2962,
    1257,  3382,   631,   631,  3511,  2914,   899,  3521,  3490,  1292,
    2098,  1257,  2686,    49,  2386,  2644,  2586,    58,  2567,    50,
     806,  2939,   340,  2653,   517,   193,  2251,  2586,   501,   502,
     132,   974,  2586,   512,  2252,   187,   198,   343,   937,   187,
     518,  1981,  1086,  1086,   184,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   648,   544,  1913,  1990,   910,  1981,
     542,  1404,  3488,    58,  3300,  2310,  1146,  1284,   574,   133,
    2305,   464,  2635,   917,  2086,   916,  1892,    58,  2512,  2348,
    2520,  2124,  2989,  3195,  2412,  2702,  2128,  3509,   134,   135,
    2640,  2430,  2045,  3307,  1024,  1024,  3322,    46,   130,    60,
    3284,  3416,  2336,    61,  2942,    47,  2944,  2586,  1340,  2393,
    1061,  2396,  1219,   506,  1305,  2400,  2984,  2149,  1830,  3272,
      58,  3367,    58,  2963,    58,  1084,   136,  2036,  3494,  2070,
    2982,  2026,  3248,  3130,  3375,  1458,  2081,    58,   137,   593,
    3129,  3112,  1852,  3171,  1257,    58,    58,  2874,  3151,   138,
    2629,  2294,  2261,  3173,  3497,  2732,  3266,   399,  3429,   399,
     465,   466,   467,   468,   469,   470,   139,  2760,  3133,    58,
      58,  2875,  2596,  2547,  3075,  1257,   140,  2481,   471,   472,
     473,  3076,  3261,  3430,  3288,  2789,  2165,  2586,  2878,    42,
    1024,  3517,   141,  3035,  3035,  3035,  3035,  2586,  2586,  2829,
    1182,  1014,  3212,  3016,  3265,  2828,  1880,  2230,    58,  2229,
    2157,  3410,   621,  3061,  3211,  1847,  3166,  3334,  2122,  3351,
    3343,  2948,  2615,   187,     0,     0,  2185,  2186,  2044,   656,
       0,     0,   142,  2202,     0,     0,     0,     0,     0,     0,
       0,     0,  1257,  1257,  1853,     0,     0,     0,     0,     0,
       0,  1405,  1854,  1257,  1257,   143,  1257,     0,  1855,  1257,
    1856,  1257,     0,     0,     0,  1257,     0,     0,     0,     0,
     144,  1857,     0,     0,     0,     0,     0,   145,     0,   187,
     146,     0,     0,   184,     0,     0,     0,   631,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1858,
    3457,   147,     0,     0,    58,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1859,     0,    58,   474,     0,
    1860,   475,     0,     0,   149,     0,     0,     0,     0,  2586,
    3136,  2586,  1861,     0,     0,     0,     0,     0,     0,  1862,
       0,     0,   150,     0,     0,  1258,     0,     0,     0,     0,
     187,     0,     0,     0,     0,    58,  3296,     0,     0,  2620,
       0,     0,  1981,     0,     0,     0,     0,     0,     0,    58,
       0,     0,     0,     0,   985,   986,   987,   989,  1406,  2648,
       0,     0,  3168,  2648,  1407,  1408,  1409,   399,     0,     0,
       0,     0,     0,  1018,     0,     0,  3506,   399,     0,    58,
       0,     0,   998,     0,  1410,     0,     0,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2367,     0,  1182,     0,     0,  1040,     0,
       0,     0,     0,     0,  1045,     0,  1047,     0,     0,   476,
    1054,     0,     0,  1054,     0,     0,  1054,     0,     0,  3197,
       0,     0,     0,     0,   477,  2586,  1066,     0,   478,   461,
     462,   463,     0,  2410,  2742,     0,  3035,  3035,     0,     0,
    3035,  1066,     0,     0,     0,     0,  1114,     0,     0,   464,
       0,  3223,     0,   989,  1125,  1128,     0,     0,     0,  1148,
       0,     0,  1863,     0,     0,     0,   479,  1160,     0,  1864,
       0,     0,     0,     0,  2586,     0,  2162,     0,     0,     0,
       0,  1411,     0,  1184,  1412,     0,     0,     0,     0,  1340,
       0,  1865,  1413,     0,   480,     0,  1866,  1007,     0,     0,
    1007,     0,     0,  1257,     0,     0,  1257,     0,  1257,     0,
    2586,     0,   481,     0,     0,     0,     0,     0,     0,  1121,
       0,     0,     0,     0,     0,     0,     0,  1414,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,   465,   466,
     467,   468,   469,   470,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1182,     0,     0,   471,   472,   473,     0,
       0,     0,  1415,     0,     0,     0,     0,     0,     0,     0,
       0,   399,  3407,     0,    58,     0,     0,     0,  1237,  1238,
    1239,  1416,  1417,     0,   271,  1240,  1241,    33,     0,     0,
       0,     0,  1418,   482,     0,     0,     0,  1419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1258,  1258,     0,     0,     0,     0,     0,    58,     0,  1258,
       0,     0,  1257,     0,     0,  2586,     0,     0,     0,     0,
       0,     0,     0,  1007,     0,  3035,  1420,     0,     0,     0,
     184,  3035,  3035,     0,  3035,  3035,  3035,  3035,     0,     0,
    2586,     0,  2586,  3035,     0,  1257,     0,    58,     0,   483,
       0,  1242,     0,     0,     0,     0,     0,     0,  1421,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,  2682,
    2683,     0,   631,    58,     0,    58,   474,     0,     0,   475,
    2692,     0,     0,     0,     0,     0,     0,     0,  1184,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,  1352,     0,     0,     0,  2706,  2707,  2708,  2709,
       0,     0,    58,     0,  2714,  2715,  2716,  2717,     0,     0,
       0,  2719,  3197,     0,     0,     0,     0,     0,  1257,     0,
       0,     0,  3035,     0,     0,  3035,  3035,  3035,  3035,  3426,
       0,     0,     0,  1380,     0,     0,  1182,     0,     0,     0,
       0,     0,     0,  2162,     0,     0,     0,     0,     0,  1007,
    1400,  1400,  1400,  1257,  1400,     0,  1400,  1400,  1006,     0,
       0,     0,    63,    63,     0,     0,     0,     0,     0,     0,
       0,    58,    58,    58,    58,    58,    58,     0,     0,     0,
       0,     0,     0,  3459,     0,     0,     0,   476,     0,  2764,
    2765,     0,     0,     0,     0,     0,  2769,  2770,     0,     0,
    1128,     0,   477,  1024,   268,     0,   478,  3035,     0,     0,
       0,     0,  1483,   269,   270,  3035,     0,     0,     0,   271,
     272,   273,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1184,  1352,  2551,     0,
       0,     0,     0,     0,   479,  1837,     0,  1237,  1238,  1239,
       0,     0,     0,   271,  1240,  1241,    33,     0,  1257,     0,
    3499,  1845,  1845,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     481,   161,     0,     0,     0,     0,   274,  3515,  3516,  3499,
       0,     0,     0,   162,     0,     0,    58,     0,  3523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2930,  2931,     0,     0,     0,
    1242,   163,     0,     0,  2938,     0,     0,     0,     0,     0,
     581,   448,   449,   450,     0,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,  1243,     0,  2969,  2970,     0,     0,     0,     0,
       0,   482,     0,     0,     0,   464,   450,  1244,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,  2992,     0,  2994,  1245,     0,     0,  1246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,     0,
    1247,     0,     0,     0,     0,    63,     0,    63,  1128,  1054,
       0,     0,     0,    54,     0,   164,  2035,  1066,     0,     0,
    1128,     0,     0,     0,  2046,     0,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3062,  3063,  1184,
    1248,  3064,  3065,     0,     0,     0,     0,  1006,     0,     0,
       0,     0,  1249,     0,   465,   466,   467,   468,   469,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,   465,   466,   467,
     468,   469,   470,  1250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   471,   472,   473,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   275,  2091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3119,  1251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2118,  1252,   166,     0,     0,     0,     0,
       0,  2552,     0,     0,     0,     0,  1253,  1254,     0,     0,
       0,     0,     0,     0,  1255,     0,  1182,  1256,     0,     0,
       0,     0,     0,     0,     0,   292,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3165,     0,     0,     0,  3170,     0,   276,
       0,     0,   474,     0,   277,   475,     0,   278,     0,     0,
       0,     0,     0,  3175,     0,     0,     0,     0,   169,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,     0,
       0,     0,  3186,     0,   170,   474,     0,     0,   475,   280,
       0,  1243,   281,     0,     0,   282,     0,     0,     0,     0,
       0,     0,  1258,     0,   283,   172,  1244,     0,  1258,  1258,
       0,     0,     0,     0,  1258,  1258,  1258,  1258,     0,     0,
       0,     0,     0,  1245,     0,     0,  2553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2554,  1247,
       0,     0,     0,     0,  1348,   284,     0,     0,     0,   173,
       0,     0,     0,     0,   268,     0,     0,   285,     0,     0,
       0,     0,     0,   269,   270,     0,  1925,     0,   286,   271,
     272,   273,    33,   476,   174,     0,     0,     0,     0,  1248,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,  1249,   478,  2551,     0,     0,     0,     0,   287,     0,
       0,     0,  1237,  1238,  1239,     0,   476,     0,   271,  1240,
    1241,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   477,     0,     0,     0,   478,     0,     0,     0,     0,
     479,     0,  1250,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   176,     0,     0,     0,   274,     0,     0,   288,
       0,   177,     0,   162,   463,     0,     0,     0,   480,     0,
       0,   289,   290,   479,     0,     0,     0,     0,     0,   291,
       0,  1251,   464,     0,     0,     0,   481,     0,     0,     0,
     292,   163,     0,  1252,     0,  1242,     0,     0,     0,  1258,
       0,   480,     0,     0,     0,  1253,  1254,     0,     0,  3320,
       0,     0,  3323,  1255,     0,     0,  1256,     0,     0,   481,
       0,     0,     0,     0,   292,     0,     0,     0,  2148,  1184,
       0,     0,     0,     0,  1237,  1238,  1239,     0,     0,     0,
     271,  1240,  1241,    33,     0,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   482,     0,     0,
       0,   465,   466,   467,   468,   469,   470,     0,     0,     0,
       0,     0,     0,    54,  2189,   164,     0,     0,     0,   471,
     472,   473,     0,     0,     0,     0,  1258,     0,     0,     0,
     482,     0,     0,     0,  1258,     0,     0,  1258,  1258,  1258,
    1258,     0,     0,     0,     0,     0,     0,  1242,     0,  1258,
       0,     0,  1006,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   483,     0,     0,     0,     0,     0,  3405,
       0,     0,     0,  1258,     0,     0,     0,   268,     0,     0,
    1258,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,   271,   272,   273,    33,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   275,  3432,  3433,
       0,  3435,     0,  3437,  3438,     0,     0,     0,     0,  1128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2552,     0,     0,   474,
       0,     0,   475,     0,   161,     0,     0,     0,     0,   274,
       0,     0,     0,     0,  1006,     0,   162,     0,     0,   167,
       0,     0,     0,     0,  3483,     0,  3484,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,  2359,
       0,     0,     0,     0,   163,     0,  2366,     0,     0,   276,
       0,     0,     0,     0,   277,     0,  1128,   278,     0,  3496,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,     0,     0,   279,  3503,  3504,   156,     0,  3505,
       0,     0,  3507,     0,   170,     0,  2407,     0,     0,   280,
       0,     0,   281,     0,     0,   282,  1243,     0,     0,     0,
       0,     0,     0,     0,   283,   172,     0,     0,     0,     0,
       0,  1244,     0,     0,     0,     0,     0,     0,     0,     0,
     476,  1128,  2464,  1128,     0,     0,     0,   989,  1245,     0,
       0,  2553,     0,     0,     0,   477,    54,     0,   164,   478,
       0,  1258,     0,  2554,  1247,   284,     0,     0,     0,   173,
       0,     0,     0,  2506,     0,     0,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
    2636,     0,     0,     0,   174,     0,     0,   479,     0,     0,
       0,     0,     0,     0,  1248,     0,     0,     0,     0,     0,
       0,  1258,     0,     0,     0,     0,  1249,     0,   287,     0,
       0,     0,     0,     0,  1258,   480,  1258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1258,  1243,     0,
       0,     0,     0,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1244,     0,   165,     0,  1250,     0,     0,
     275,     0,   176,     0,     0,     0,     0,     0,     0,   288,
    1245,   177,     0,  1246,     0,     0,     0,     0,     0,     0,
    1258,   289,   290,     0,  1128,   187,  1247,     0,   166,   291,
    2433,  2434,  2435,  2436,  2437,  2438,  1251,     0,     0,  1128,
     292,  1128,     0,     0,     0,     0,     0,     0,  1252,     0,
    1128,     0,     0,  1925,     0,     0,     0,     0,     0,     0,
    1253,  1254,   167,     0,   482,     0,  1248,     0,  1255,     0,
     132,  1256,     0,     0,   168,     0,     0,     0,  1249,   292,
       0,     0,     0,     0,     0,     0,     0,  2668,     0,     0,
       0,     0,   276,     0,     0,   178,   179,   277,     0,     0,
     278,     0,     0,     0,     0,     0,     0,     0,     0,   133,
    1258,   169,     0,     0,     0,  2691,     0,   279,     0,  1250,
    2439,     0,     0,     0,     0,     0,     0,   170,   134,   135,
     483,     0,   280,     0,     0,   281,     0,     0,   282,     0,
       0,  1258,     0,     0,     0,     0,     0,   283,   172,   457,
     458,   459,   460,   461,   462,   463,     0,     0,  1251,  1258,
    1258,  1258,  1258,     0,     0,     0,   136,     0,     0,     0,
    1252,     0,     0,   464,     0,     0,     0,     0,   137,     0,
       0,     0,  1253,  1254,     0,     0,     0,  2979,   284,   138,
    1255,     0,   173,  1256,     0,     0,     0,     0,     0,     0,
     285,   292,     0,     0,     0,     0,   139,     0,  1258,  1258,
       0,   286,     0,     0,     0,     0,   140,   174,     0,  1258,
    1258,     0,  1258,     0,     0,  1258,     0,  1258,     0,     0,
       0,  1258,   141,  2762,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,  1024,  1024,  1024,     0,
    1024,  1024,  1024,  1024,  1024,  1024,     0,     0,     0,  1024,
       0,   268,   465,   466,   467,   468,   469,   470,     0,     0,
     269,   270,   142,     0,     0,     0,   271,   272,   273,    33,
     471,   472,   473,     0,     0,   176,   271,  1240,  1241,    33,
       0,     0,   288,     0,   177,   143,  1128,     0,   458,   459,
     460,   461,   462,   463,   289,   290,     0,     0,     0,     0,
     144,     0,   291,     0,     0,     0,     0,   145,     0,     0,
     146,   464,     0,   292,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,   147,  1128,     0,     0,   148,     0,     0,   161,     0,
       0,     0,   464,   274,     0,  2440,  1128,     0,     0,     0,
     162,     0,     0,  3021,   149,     0,     0,     0,  2441,     0,
       0,     0,     0,     0,  1182,     0,     0,     0,   178,   179,
       0,     0,   150,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2960,
       0,  1018,  1239,  2964,     0,     0,   271,  1240,  1241,    33,
     465,   466,   467,   468,   469,   470,  2975,     0,     0,     0,
     474,   187,     0,   475,  2983,  2407,     0,     0,   471,   472,
     473,  2442,  1258,  1258,     0,     0,  1258,     0,  2443,     0,
       0,   465,   466,   467,   468,   469,   470,     0,  2997,  2999,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2444,     0,     0,
      54,     0,   164,  1242,     0,     0,     0,  3060,     0,     0,
    1006,     0,     0,  1258,     0,     0,  1258,     0,     0,  1258,
       0,  2445,  1258,     0,  1258,     0,     0,     0,     0,     0,
       0,  2446,  2447,     0,     0,     0,     0,  2448,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2449,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,  2450,
       0,     0,  2451,  2452,     0,     0,   477,  2453,     0,     0,
     478,     0,     0,     0,     0,     0,     0,     0,   474,     0,
       0,   475,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,     0,  3113,   275,     0,  1237,  1238,  1239,     0,
       0,     0,   271,  1240,  1241,    33,  3128,     0,   479,   474,
       0,     0,   475,     0,     0,     0,     0,     0,     0,     0,
    1006,     0,   166,     0,  2454,     0,     0,     0,  1258,     0,
       0,     0,     0,     0,     0,  2455,   480,     0,     0,     0,
       0,  1258,     0,     0,  1128,     0,     0,  1258,  1258,     0,
    1258,  1258,  1258,  1258,   481,     0,   167,     0,  1128,  1258,
       0,  1258,     0,     0,     0,     0,     0,     0,   168,     0,
     187,     0,     0,     0,     0,     0,  1258,     0,     0,  1242,
       0,     0,     0,     0,     0,     0,   276,     0,  2407,     0,
       0,   277,     0,     0,   278,     0,     0,  1184,     0,   476,
       0,     0,     0,     0,  1243,   169,     0,     0,     0,     0,
       0,   279,     0,     0,   477,     0,     0,     0,   478,  1244,
       0,   170,     0,     0,     0,     0,   280,     0,     0,   281,
     476,     0,   282,     0,     0,   482,  3022,     0,  1182,  3023,
       0,   283,   172,     0,     0,   477,     0,     0,     0,   478,
       0,     0,  3024,     0,  1258,     0,   479,     0,  1258,     0,
       0,  1258,  1258,  1258,  1258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,   480,  1258,   173,   479,     0,  1258,
       0,     0,  3026,     0,   285,     0,     0,     0,     0,     0,
       0,   483,   481,     0,  3027,   286,  1006,     0,     0,     0,
       0,   174,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,  1243,     0,     0,     0,     0,     0,
       0,     0,     0,   481,     0,   287,     0,     0,     0,  1244,
       0,     0,     0,  1258,     0,  3028,     0,     0,     0,     0,
       0,  1258,  3113,     0,     0,     0,  1245,     0,     0,  1246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1247,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,   482,  3029,     0,   288,     0,   177,     0,
       0,     0,     0,  1128,  1258,     0,  3030,     0,   289,   290,
       0,     0,     0,     0,     0,     0,   291,     0,  3031,  3032,
       0,     0,  1248,     0,   482,     0,  3033,   292,     0,  3034,
       0,     0,     0,     0,  1249,     0,     0,   292,     0,     0,
       0,     0,     0,     0,     0,     0,  2407,     0,     0,     0,
       0,     0,  1182,  1500,  1501,  1502,  1503,  1504,  1505,   483,
    1506,  1507,  1508,     0,     0,     0,  1509,  1510,  1511,  1512,
    1513,  1514,     0,     0,     0,  1250,     0,     0,     0,     0,
       0,  1515,   178,   179,     0,     0,  2407,     0,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,  1516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1251,     0,     0,  3113,     0,     0,
    1243,     0,  3370,     0,  3372,     0,  1252,     0,     0,     0,
       0,     0,     0,     0,     0,  1244,     0,     0,  1253,  1254,
       0,     0,     0,     0,  1128,     0,  1255,  1517,     0,  1256,
       0,     0,  1245,     0,     0,  1246,  1518,   292,     0,     0,
       0,  1184,     0,     0,     0,     0,     0,   187,  1247,     0,
       0,     0,     0,     0,  1519,     0,  1520,     0,     0,     0,
       0,     0,     0,     0,  1521,     0,     0,     0,     0,     0,
       0,  1522,  1523,     0,     0,  1524,  1525,  1526,  1527,     0,
       0,  1528,  1529,     0,     0,     0,     0,  2402,  1248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1400,  1400,  1400,  1400,  1400,  1400,     0,     0,     0,     0,
       0,  1530,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1250,     0,  1531,     0,     0,     0,     0,     0,  1532,
       0,     0,     0,     0,     0,  2121,  1533,     0,  1534,     0,
       0,     0,     0,     0,  1535,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1251,     0,     0,     0,     0,     0,     0,     0,     0,  1536,
       0,     0,  1252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1253,  1254,     0,     0,     0,     0,
       0,     0,  1255,     0,     0,  1256,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,  1537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1538,     0,     0,     0,     0,  1184,  1539,     0,     0,     0,
       0,     0,     0,     0,     0,  1540,  1541,     0,     0,     0,
       0,     0,  1542,     0,     0,  1543,  1544,     0,     0,     0,
    1545,     0,     0,     0,     0,     0,  1546,  1547,     0,     0,
       0,     0,     0,  1548,  1549,  1550,  1551,  1552,  1553,     0,
       0,     0,  1554,     0,     0,     0,  1555,     0,  1556,     0,
       0,     0,     0,     0,     0,  1557,  1558,  1559,  1560,     0,
    1561,  1562,     0,     0,     0,  1563,  1564,     0,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,     0,     0,     0,     0,     0,
    1572,  1573,  1574,     0,  1575,  1576,     0,     0,     0,  1577,
    1578,  1579,  1580,  1581,  1582,  1583,  1584,     0,  1585,     0,
       0,     0,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,
    1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,
       0,  1624,  1625,     0,     0,  1626,  1627,  1628,  1629,  1630,
    1631,  1632,  1633,  1634,  1635,     0,  1636,  1637,  1638,  1639,
    1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,
    1650,     0,     0,  1651,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,  1659,     0,  1660,  1661,  1662,  1663,     0,  1664,  1665,
    1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,     0,  1700,  1701,  1702,  1703,  1704,
    1705,     0,     0,  1706,  1707,     0,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,
    1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,     0,     0,  1734,  1735,  1736,  1737,  1738,  1739,
    1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,
    1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,     0,     0,     0,     0,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1807,     0,     0,     0,     0,     0,     0,     0,  1808,
       0,     0,     0,     0,  1809,     0,     0,     0,  1810,     0,
       0,  1811,  1812,  1813,  1814,     0,     0,  1815,  1816,     0,
    1817,  1818,  1819,  1500,  1501,  1502,  1503,  1504,  1505,     0,
    1506,  1507,  1508,     0,     0,     0,  1509,  1510,  1511,  1512,
    1513,  1514,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1515,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1517,     0,     0,
       0,     0,     0,     0,     0,     0,  1518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1519,     0,  1520,     0,     0,     0,
       0,     0,     0,     0,  1521,     0,     0,     0,     0,     0,
       0,  1522,  1523,     0,     0,  1524,  1525,  1526,  1527,     0,
       0,  1528,  1529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1530,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1531,     0,     0,     0,     0,     0,  1532,
       0,     0,     0,     0,     0,     0,  1533,     0,  1534,     0,
       0,     0,     0,     0,  1535,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1538,     0,     0,     0,     0,     0,  1539,     0,     0,     0,
       0,     0,     0,     0,     0,  1540,  1541,     0,     0,     0,
       0,     0,  1542,     0,     0,  1543,  1544,     0,     0,     0,
    1545,     0,     0,     0,     0,     0,  1546,  1547,     0,     0,
       0,     0,     0,  1548,  1549,  1550,  1551,  1552,  1553,     0,
       0,     0,  1554,     0,     0,     0,  1555,     0,  1556,     0,
       0,     0,     0,     0,     0,  1557,  1558,  1559,  1560,     0,
    1561,  1562,     0,     0,     0,  1563,  1564,     0,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,     0,     0,     0,     0,     0,
    1572,  1573,  1574,     0,  1575,  1576,     0,     0,     0,  1577,
    1578,  1579,  1580,  1581,  1582,  1583,  1584,     0,  1585,     0,
       0,     0,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,
    1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,
       0,  1624,  1625,     0,     0,  1626,  1627,  1628,  1629,  1630,
    1631,  1632,  1633,  1634,  1635,     0,  1636,  1637,  1638,  1639,
    1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,
    1650,     0,     0,  1651,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,  1659,     0,  1660,  1661,  1662,  1663,     0,  1664,  1665,
    1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,     0,  1700,  1701,  1702,  1703,  1704,
    1705,     0,     0,  1706,  1707,     0,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,
    1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,     0,     0,  1734,  1735,  1736,  1737,  1738,  1739,
    1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,
    1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795, -2146,     0,     0,     0,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,     0, -2146,     0, -2146, -2146, -2146,     0,     0,     0,
       0,  1807,     0,     0,     0,     0,     0,     0,     0,  1808,
       0,     0,     0,     0,  1809,     0,     0,     0,  1810,     0,
       0,  1811,  1812,  1813,  1814,     0,     0,  1815,  1816,     0,
    1817,  1818,  1819,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2146,     0,     0,     0,     0,  1237,  1238,  1239,
       0,     0,     0,   271,  1240,  1241,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2146,     0, -2146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2146,     0,     0,     0,     0,     0,     0,     0,
   -2146,     0, -2146,     0,     0,     0,     0,     0,     0,     0,
       0, -2146,     0,     0,     0,     0,     0, -2146,     0,     0,
       0,     0,     0,     0,     0, -2146,     0,     0,     0, -2146,
       0,     0,     0,     0,     0, -2146,     0,     0,     0, -2146,
   -2146, -2146, -2146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2146,     0,     0, -2146,     0, -2146,  1006,     0,     0,
       0,     1,     0, -2146,     0,     2,     0,   658,   659,   660,
       0,     0,     0,     0,     0,   661, -2146,     0,     0,     0,
       0,     0,   662,   663,     0,     0, -2146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2146, -2146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2146,     0,   664,     0,     0,     0,     0,     0, -2146,     0,
       0,     0, -2146,     0,   665,   666,     0,   667,     0,     0,
   -2146, -2146, -2146,     0,     0,     0,     0,     0,     0,     0,
       0,   668,     0,     0,     0,     0,     0,     0,   669,     0,
       0,  2552,     0,     0,     0,     0,     0,     0,     0,   670,
       0,     0,   671,   672,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   673,     0,   674,
     675,   676,     0,     0,     0,     0,     0,     0,     0,   677,
     678,     0,   679,   680,   681,     0,     0,     0,     0, -2146,
     682,     0,     0,   683,     0,   684,   685,   686,     0,     0,
   -2146,     0,     0,   687,     0,   688,   689,     0,   690,     0,
     691,   692,     0,     0,   693,     0,     0,   694,   695,   696,
       0,   697,   698,     0,     0,     0,   699,   700,   701,     0,
     702,     0,     0,     0,   703,     0,   704,   705,     0,     0,
   -2146,  1243,   706,     0,     0,     0,   707,     0,     0,   708,
       0,   709,     0,   710,     0,   711,  1244,   712,   713,     0,
     714,   715,   716,     0,     0,     0,   717,     0,   718,   719,
       0,   720,     0,  1245,     0,     0,  2553,     0,     0,   721,
     722,     0,     0,     0,     0,     0,     0,     0,  2554,  1247,
       0,     0,   723,     0,     0,   724,   725,     0,     0,   726,
     727, -2146,     0,   728,   729,     0,     0,     0,     0,     0,
       0,     0,   730,   731,   732,     0,   733,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   734,   735,   736,  1248,
     737,     0,     0,     0,   738,   739,     0, -2146,     0,   740,
       0,  1249,     0,     0,     0,     0,     0,   741,     0,     0,
       0,     0,     0,     0,     0,   742,   743,   744,     0,     0,
       0,     0,     0,   745,   746,     0,     0,     0,     0,   747,
       0,     0,   748,     0,     0,     0,   749,   750,     0,     0,
       0,     0,  1250, -2146,     0,     0,     0,   751,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2146, -2146, -2146,
   -2146, -2146, -2146, -2146,   752, -2146, -2146,     0,     0,     0,
       0,     0,   753,     0,     0,     0,     0,     0,   754,     0,
       0,  1251, -2146,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,  1252,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,  1253,  1254,     0,   756,     0,
     757,   758,     0,  1255,     0,     0,  1256,     0,     0,   759,
    2669,   448,   449,   450,   292,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   464,     0,     0,   760,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   761,
       0,     0,     0,     0,     0,     0,   762,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     763,   764,     0,     0,     0,   765,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   766,     0,     0,
       0,     0,     0,   767,   768,   769,   770,     0,     0,     0,
     771,     0,     0,     0,   772,     0,     0,     0,     0,     0,
       0,   773,   774,     0,   465,   466,   467,   468,   469,   470,
       0,     0,   775,     0,   776,     0,     0,     0,     0,     0,
       0,     0,   471,   472,   473,   777,     0,   778,     0,     0,
     779,     0,     0,   448,   449,   450,   780,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   781,     0,     0,   782,     0,   464,     0,     0,
     783,     0,     0,   784,   785,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   786,     0,
       0,     0,   448,   449,   450,   787,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   788,   789,
     790,   791,   792,   793,   794,     0,   464,   795,     0,   796,
       0,   797,     0,   448,   449,   450,     0,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
       0,     0,     0,     0,     0,     0,   465,   466,   467,   468,
     469,   470,   474,     0,     0,   475,     0,   464,     0,     0,
       0,     0,     0,     0,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,   449,   450,     0,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,     0,     0,   465,   466,   467,   468,   469,
     470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,     0,     0,   471,   472,   473,     0,   448,   449,   450,
       0,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,     0,     0,   465,   466,   467,   468,
     469,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,     0,   471,   472,   473,     0,     0,     0,
       0,     0,     0,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,     0,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,     0,     0,   475,     0,   465,
     466,   467,   468,   469,   470,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   471,   472,   473,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     465,   466,   467,   468,   469,   470,     0,     0,   480,     0,
       0,     0,     0,   474,     0,     0,   475,     0,   471,   472,
     473,     0,     0,     0,     0,     0,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2831,  2832,     0,  2833,  2834,  2835,     0,
       0,     0,     0,     0,   474,     0,     0,   475,   448,   449,
     450,     0,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     477,     0,   464,     0,   478,   570,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   479,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2836,     0,   477,
       0,     0,     0,   478,   580,  2837,     0,     0,   474,     0,
     480,   475,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   483,     0,   476,     0,     0,   481,     0,
       0,   465,   466,   467,   468,   469,   470,     0,     0,  2838,
     477,   479,     0,     0,   478,   590,     0,     0,  2839,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,  2840,  2841,     0,
       0,     0,   479,     0,     0,     0,     0,   481,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   477,     0,     0,     0,   478,   944,   482,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2842,     0,     0,     0,     0,     0,   481,   476,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,   479,     0,     0,   478,   950,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2843,     0,     0,     0,   482,     0,
       0,     0,     0,   480,     0,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,   474,
       0,   481,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
       0,     0,     0,     0,   480,     0,     0,     0,     0,  2844,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   481,     0,   483,   448,   449,   450,     0,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,   482,     0,     0,   483,     0,     0,   448,   449,
     450,     0,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,     0,   464,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   477,     0,     0,     0,   478,
     951,     0,     0,     0,     0,     0,     0,     0,   483,   448,
     449,   450,     0,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,   465,   466,
     467,   468,   469,   470,     0,     0,     0,   479,     0,     0,
       0,     0,     0,   464,     0,     0,   471,   472,   473,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,   465,   466,   467,   468,   469,   470,     0,     0,     0,
       0,     0,     0,   481,     0,     0,     0,     0,     0,   471,
     472,   473,   448,   449,   450,     0,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,     0,  2845,  2846,  2847,  2848,
    2849,  2850,  2851,  2852,  2853,  2854,   464,     0,     0,     0,
       0,     0,   465,   466,   467,   468,   469,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,   448,   449,   450,   482,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,   475,
       0,     0,   448,   449,   450,   464,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,     0,
       0,     0,     0,     0,     0,   465,   466,   467,   468,   469,
     470,     0,     0,     0,     0,     0,   464,     0,     0,   474,
     483,     0,   475,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,   450,     0,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
       0,     0,     0,     0,   465,   466,   467,   468,   469,   470,
     474,     0,     0,   475,     0,     0,     0,   464,     0,     0,
       0,     0,   471,   472,   473,     0,     0,   476,     0,     0,
       0,     0,     0,     0,     0,   465,   466,   467,   468,   469,
     470,     0,   477,     0,     0,     0,   478,   952,     0,     0,
       0,     0,     0,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1237,  1238,  1239,     0,     0,
     476,   271,  1240,  1241,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,   477,     0,     0,     0,   478,
     953,     0,     0,   474,     0,     0,   475,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   465,   466,   467,   468,
     469,   470,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   471,   472,   473,   479,     0,     0,
     481,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,     0,  1242,     0,
     478,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,   474,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,   481,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,   479,     0,
       0,     0,     0,   474,     0,     0,   475,     0,     0,     0,
       0,   955,     0,   464,     0,     0,     0,     0,     0,     0,
       0,   482,     0,     0,   476,     0,   480,     0,  3019,  3020,
       0,     0,     0,     0,   271,  1240,  1241,    33,     0,   477,
       0,     0,     0,   478,   481,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,     0,     0,
       0,     0,     0,     0,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   464,     0,   475,     0,     0,
       0,   479,     0,     0,     0,  1006,     0,   483,     0,     0,
       0,     0,     0,   476,   956,     0,     0,     0,     0,     0,
       0,     0,   465,   466,   467,   468,   469,   470,   477,   480,
       0,  3021,   478,     0,     0,     0,     0,     0,     0,     0,
     471,   472,   473,     0,   476,   482,     0,   481,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,   477,
       0,     0,     0,   478,     0,     0,     0,     0,     0,     0,
     479,     0,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,     0,   959,   465,   466,   467,   468,   469,   470,
       0,     0,     0,     0,     0,     0,     0,     0,   480,   464,
       0,   479,   471,   472,   473,     0,     0,     0,     0,     0,
       0,   483,     0,     0,     0,   476,   481,     0,   456,   457,
     458,   459,   460,   461,   462,   463,     0,     0,   482,   480,
     477,     0,     0,     0,   478,     0,   199,     0,     0,   200,
       0,     0,     0,   464,     0,     0,     0,   481,     0,     0,
       0,     0,     0,   459,   460,   461,   462,   463,  1006,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3019,  3020,   479,     0,     0,   464,   271,  1240,  1241,    33,
     474,     0,     0,   475,     0,     0,     0,     0,   465,   466,
     467,   468,   469,   470,   483,     0,     0,   482,     0,     0,
     480,     0,     0,     0,     0,     0,   471,   472,   473,  1243,
       0,     0,     0,     0,     0,     0,     0,     0,   481,     0,
     201,   202,     0,     0,  1244,     0,     0,     0,   482,     0,
     203,     0,   465,   466,   467,   468,   469,   470,     0,     0,
       0,  1245,   474,     0,  1246,   475,     0,     0,     0,     0,
     471,   472,   473,  3021,     0,     0,     0,  1247,     0,     0,
       0,     0,     0,   483,   465,   466,   467,   468,   469,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,     0,  3413,  1248,     0,   482,
       0,   476,     0,     0,  3019,  3020,     0,     0,     0,  1249,
     271,  1240,  1241,    33,     0,     0,   477,     0,     0,     0,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,     0,     0,   475,
    1250,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,     0,  1243,   476,     0,   483,     0,     0,     0,     0,
       0,   954,     0,     0,     0,     0,     0,  1244,   477,     0,
    1006,     0,   478,     0,     0,     0,   480,  3021,     0,  1251,
     474,     0,     0,   475,  3022,     0,     0,  3023,     0,     0,
       0,  1252,   204,     0,   481,     0,     0,     0,     0,     0,
    3024,     0,     0,  1253,  1254,     0,     0,     0,     0,     0,
     479,  1255,   474,     0,  1256,   475,     0,     0,     0,     0,
       0,     0,   292,     0,     0,     0,  1089,     0,     0,     0,
       0,   205,     0,     0,  1090,     0,     0,     0,   480,  3025,
    3026,     0,     0,  1091,     0,     0,  1092,     0,     0,     0,
     206,   207,  3027,     0,     0,     0,   481,   476,     0,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,   477,     0,     0,   482,   478,     0,     0,     0,
       0,  2433,  2434,  2435,  2436,  2437,  2438,     0,   209,  1093,
       0,     0,     0,  3028,     0,     0,     0,  1094,     0,     0,
     210,   476,     0,     0,  1006,     0,     0,     0,     0,     0,
       0,   211,     0,     0,   479,     0,   477,     0,     0,     0,
     478,     0,     0,     0,     0,     0,     0,     0,   212,     0,
       0,     0,  3029,   476,     0,     0,     0,   482,   213,     0,
       0,   483,   480,     0,  3030,     0,     0,     0,   477,     0,
       0,     0,   478,  1095,   214,     0,  3031,  3032,   479,     0,
     481,     0,     0,     0,  3033,     0,     0,  3034,     0,     0,
       0,  2439,     0,     0,  1243,   292,     0,     0,  1096,     0,
       0,     0,     0,     0,     0,  1097,   480,  1098,     0,  1244,
     479,     0,     0,     0,   215,     0,     0,  1099,     0,     0,
       0,     0,     0,   483,   481,     0,  3022,     0,     0,  3023,
       0,     0,     0,     0,     0,     0,     0,   216,   480,     0,
       0,     0,  3024,  1100,     0,     0,     0,     0,     0,     0,
       0,  1101,   217,     0,     0,     0,   481,     0,     0,   218,
       0,   482,   219,     0,     0,     0,     0,     0,     0,  1925,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3026,   220,     0,     0,     0,   221,  1102,     0,
       0,     0,     0,     0,  3027,     0,     0,  3384,     0,     0,
       0,     0,     0,     0,     0,   482,   222,     0,     0,     0,
       0,     0,     0,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,     0,   483,  1243,     0,
       0,     0,     0,     0,     0,  3028,     0,   482,     0,     0,
       0,     0,     0,  1244,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,  3385,     0,     0,     0,     0,     0,     0,
    3022,     0,  1105,  3023,     0,     0,   224,     0,     0,     0,
       0,   483,     0,     0,  3029,     0,  3024,     0,  3386,     0,
       0,     0,     0,     0,     0,     0,  3030,  3387,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3031,  3032,
       0,     0,     0,   483,     0,     0,  3033,     0,     0,  3034,
       0,     0,     0,     0,     0,     0,  3026,   292,     0,     0,
       0,     0,     0,  3388,     0,     0,  2440,     0,  3027,     0,
       0,  3389,     0,     0,     0,     0,     0,     0,     0,  2441,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1106,  1107,  1108,     0,     0,     0,     0,     0,     0,  3028,
       0,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2442,     0,     0,     0,     0,     0,  3029,  2443,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3030,     0,     0,     0,  3390,     0,     0,     0,     0,     0,
       0,     0,  3031,  3032,     0,     0,     0,     0,     0,     0,
    3033,     0,     0,  3034,     0,     0,     0,     0,  2444,     0,
       0,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2445,     0,     0,     0,  1110,     0,     0,     0,
       0,     0,  2446,  2447,     0,     0,     0,     0,  2448,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2449,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2450,     0,     0,  2451,  2452,     0,     0,     0,  2453,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2454,     0,     0,     0,     0,
       0,     0,     0,     0,  3391,     0,  2455
};

static const short yycheck[] =
{
       3,     4,     5,   171,   388,     8,   107,   635,   256,   257,
     969,   258,   259,   222,  1007,  1022,   263,  1315,  1088,  1117,
    1308,   190,   769,  1237,  1238,    45,  1085,   620,  1122,   530,
    1099,   692,   767,    54,   556,  1019,   127,    40,  1095,  1096,
    1863,  1098,   669,  1100,  1101,   173,  2260,  1829,  1830,    52,
    2532,    54,   572,  2267,  2389,  1039,    20,    41,  2047,  1344,
      27,   727,    65,    27,    27,  1862,  2213,    26,    27,    72,
     171,  1978,    92,    76,     5,  1989,    79,    80,    27,    24,
       5,    26,    85,    86,    27,    69,  2747,  2748,  2749,   190,
    1930,  1931,  1932,  1933,  1992,   752,   689,  2432,    24,    25,
      26,    27,  1925,   106,    19,  2329,   699,   137,     5,    24,
      25,    26,    19,    24,    25,    26,    27,  1176,     5,    26,
     123,   757,   942,   126,     5,   752,   787,  2151,   131,    30,
     114,  1190,   260,    34,   118,     5,   264,  2750,   266,  1209,
     268,   269,   270,   234,   235,    24,    25,    26,   693,   277,
      24,   319,    26,   281,   282,    24,    25,    26,    27,    99,
    2778,   754,    20,   756,    25,     5,    27,    25,     5,    27,
      20,   716,   765,  1180,    25,    25,    27,    27,     5,     5,
     105,     5,   107,   188,   109,    24,    25,    26,    27,   192,
     188,    92,     6,    25,    26,    27,    97,   201,    27,    24,
      25,    26,    27,    45,    25,     5,    27,    25,    27,    27,
      27,   124,   125,    25,     5,    27,   761,    25,   319,    27,
       5,     5,   323,     5,     5,   770,   771,     6,   231,   774,
       5,    27,  1006,   778,   237,     5,   278,   382,     5,   784,
     224,   786,     5,   144,   145,   274,   249,   175,   312,     5,
      92,   152,   255,   256,   257,   258,   259,  2546,     5,  2548,
     263,   102,     5,     5,  1257,   495,   273,     5,    27,   228,
      23,  2163,   210,  2891,     5,  2893,   128,   426,   495,  2552,
     428,  2554,    27,     5,  2428,     9,    10,   245,    12,    13,
      14,    15,    16,    17,  2807,   423,  2809,   396,   426,  2812,
      99,  3225,   228,  2952,  2829,   118,   119,   467,     0,   312,
     313,   428,  3236,   212,   562,   443,   444,   445,   446,   322,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   333,   507,  2553,
    1927,  2488,  2331,  1106,  1107,   462,     5,   475,   476,    27,
    1448,    27,   480,  1337,   482,   339,   176,   177,   342,   228,
      25,    27,    27,   347,    25,   442,    27,   228,  2474,   497,
     498,   499,   500,  2262,  2263,     5,   504,  2266,   382,   664,
     377,     5,   667,   668,     5,    25,  1393,    27,  1372,   228,
     201,  2916,   377,   582,    27,   563,   681,  1144,   660,   612,
     397,  2241,  2521,   228,    31,     5,   507,   228,    27,   228,
     309,   395,     5,   512,     5,   700,   228,     6,   703,     0,
     228,   683,   507,     5,   709,   655,  1246,   467,   713,     5,
     515,   312,   717,  2322,     5,    16,   721,     5,   655,   652,
     725,   726,   312,   728,     5,   474,   731,     5,   733,   734,
     735,  3069,     5,  3071,     5,   495,   741,  2576,     5,   744,
     494,   495,   563,   412,   653,   634,   751,     5,     5,   228,
     466,   312,   757,  2746,  2747,  2748,  2749,   625,   436,   764,
      93,    94,     5,     5,     5,   101,   631,  1032,     5,     5,
     775,   647,     5,   496,   779,  1488,     5,   745,   783,    28,
      29,   661,     5,   404,   789,     5,   432,   792,   121,   122,
     123,   531,   532,     5,     5,   762,   763,     5,     5,   272,
     523,   447,   621,   526,     5,     5,   664,   286,   467,   430,
     321,   534,  2119,   634,   541,  2808,   520,  2810,     5,     5,
     604,   382,     5,  2687,   791,   694,   588,   794,   551,    27,
     553,  3200,  2334,   432,    28,   494,  1330,   562,   561,   562,
     181,   564,   700,   391,   562,   703,   290,   228,   447,    29,
     387,   382,  1208,  3086,   321,   713,   580,  1122,   537,   717,
     377,  2728,   545,   721,  2476,   426,    10,  1132,   228,  2478,
     728,  3240,  1137,   432,    27,   733,   421,   735,   652,   426,
     501,   631,   421,   741,  2818,   283,   744,    23,   447,   613,
     286,   411,  2501,   751,   428,  1362,    23,   614,   296,   757,
    3233,  2956,   550,   463,  2730,  2731,   764,  1374,  1129,   614,
    1131,   590,    85,    86,    87,    88,    89,   775,   578,  2974,
     578,   779,  2465,   428,    27,   783,   428,   428,   597,   428,
     653,   789,   280,   473,   792,   658,   659,   660,   661,   662,
     663,   428,   665,   666,   283,   428,   669,   670,   507,   672,
     499,   467,   675,  1301,   677,  1438,  1333,   296,   477,   463,
    2569,   403,   625,   686,   408,   409,   428,  2594,   463,   531,
    2487,  2580,   593,   463,  1992,   592,  2610,  1363,   523,   507,
    2724,  1358,   589,   706,   428,  1227,  1333,   463,  2932,   712,
     655,   387,  2936,  1233,  2612,   718,   719,   720,   625,  3201,
     463,   724,   653,   604,   727,   463,   729,   730,   653,   655,
    3212,  1358,   463,   551,   604,   702,   661,   740,   702,   702,
     655,   465,   745,   746,   655,   704,  3019,  3020,   661,   752,
    3023,   612,   755,   702,   387,   592,   582,   760,   582,   762,
     763,  3379,   575,   604,   767,   768,   769,  3428,   490,   428,
     773,  2660,   673,   776,   586,   848,   655,  2062,   781,   578,
     681,   655,     5,  3072,   506,   788,   655,   790,   791,   647,
     793,   794,   432,   796,   797,   228,   647,   647,   428,  1460,
     621,   467,   467,  1088,   428,   283,     9,    10,   424,    12,
      13,    14,    15,    16,    17,   647,   655,   614,   296,  1364,
    1365,  1366,   674,   675,   676,   677,   678,   549,   428,   957,
     655,   507,   960,   449,   512,   428,  1381,   428,     5,   428,
     968,   969,  1226,   684,   685,   686,   428,  3329,   467,   662,
     528,  2740,   428,    25,   695,    27,   272,   428,    30,    27,
     428,  3196,  2644,   287,   196,   272,   588,   428,   592,   320,
     428,  1855,  1856,     5,   507,   428,  2196,   428,   491,  2199,
    1864,   428,   333,    18,    19,    20,    21,    22,     5,   574,
     428,   428,  1485,   512,  1439,   617,    25,    26,   901,    18,
      19,    20,    21,    22,   626,   428,   428,   428,   391,   528,
     574,   428,   428,   196,  1459,   428,   532,   495,  2215,   428,
     362,    10,  1207,  1208,  1209,   428,   396,   574,   428,    30,
     320,  1476,   467,    34,   658,   655,   428,   428,   623,   942,
     428,   428,  1487,   333,    14,  3218,   371,   428,   428,   495,
    1088,  3224,  3225,  1937,  3227,  3228,  3229,  3230,   151,   623,
     495,   428,   428,  3236,   577,   428,   189,    56,    18,    19,
      20,    21,    22,   558,  2271,  2272,   623,   980,   205,   982,
     362,  1965,   369,   399,   708,   709,   403,    20,   421,   467,
     467,   975,   399,  2882,    27,  2884,   379,   422,  2067,   423,
     357,   425,   334,  1006,   387,   388,   654,   620,   624,    27,
    2308,   112,   440,   661,  2312,   466,  1019,   675,   676,  1022,
     636,   637,   189,   467,  3238,   202,  3041,   204,   644,   412,
    1103,  3328,   415,  1036,   512,  3332,  1039,  1110,    25,   202,
      27,   204,   512,    25,    25,    27,    27,   625,  2107,   432,
     528,   334,   229,    26,    27,    25,   228,    27,  3205,   495,
     228,    25,  3335,    27,   467,  3338,  3339,  3340,  3341,  1207,
    1208,  1209,  2056,   490,  1077,   517,   466,   655,   410,    25,
      25,    27,    27,   462,   202,  2607,   204,   290,    25,   506,
      27,  1094,  1095,  1096,    20,  1098,   467,  1100,  1101,    26,
      27,    27,   274,  1106,  1107,    24,  2176,    26,   517,  1929,
      25,   229,    27,    26,    27,  1935,  1936,  2896,   467,  3008,
    2899,  1941,  1942,  1943,  1944,   143,   467,   410,  1375,  1377,
     467,   308,   549,  2092,   311,   517,    26,    27,   526,  1142,
     735,  1144,    25,   467,    27,   308,   534,  3420,   311,   744,
    1153,   621,   467,  1156,   537,  3428,   333,    20,  1161,  2746,
    2747,  2748,  2749,   550,    27,    20,   619,    25,  3057,    27,
     333,   588,    27,   274,   561,   193,    19,  1180,  1181,   467,
     512,    24,    25,    26,   467,  2169,  1189,  3010,  2508,   617,
     308,   467,   620,   311,   789,   467,   528,   792,  3213,  3214,
     617,    20,  1205,  1206,  3093,   408,   409,   590,    27,   626,
     228,   686,   230,  1304,   597,   333,  1307,   467,   660,  1466,
     467,   393,  1470,    20,  2746,  2747,  2748,  2749,  1231,   512,
      27,   706,   467,    20,  1237,  1238,  2533,   679,   680,  2536,
      27,   228,    20,  1246,   719,   528,   228,  2231,   475,    27,
     467,   660,   660,  1256,    26,   228,  2003,   699,   228,   486,
    3079,  1264,   465,  3082,   228,   653,  3085,   467,   139,   140,
     679,   680,   467,    98,   682,   683,    18,    19,   660,    25,
     507,    27,   228,   228,    26,    27,   467,   514,   373,   466,
     699,   228,   393,  2581,   494,   495,  2116,   679,   680,   384,
     403,   228,   474,   466,   495,    25,  1309,    27,  1329,   327,
    1313,  1314,  1315,   228,  2612,   228,  2414,   699,    25,  3208,
      27,  2609,  1325,  1326,   403,  1952,  1329,  1330,   463,   660,
    1333,   503,  1335,  1336,  1337,    26,   403,  2321,   228,  3023,
     276,   442,   467,  2090,   463,   228,   494,   495,   466,   174,
     435,   682,   683,   467,    96,  1358,  1359,   557,  1361,  1362,
    1363,   677,   678,  3317,  3318,   450,   108,  1370,  1371,  1372,
     228,  1374,  1375,   474,  1377,  1378,   394,  3217,   428,  3219,
    3220,  3221,  3222,   467,   402,  1388,   467,   490,   406,   592,
    1393,   775,  3381,  2213,   136,   779,    25,   333,    27,   783,
      26,  2221,   503,   506,  2224,  2225,  2226,  2227,  2155,  3398,
    2480,   490,   237,    24,   239,    26,    39,   661,    41,    42,
      43,   684,   685,   490,  2017,   443,  2161,   506,   790,   254,
    2500,   793,  3019,  3020,   796,  1438,  3023,   262,    25,   506,
      27,   266,   661,   276,  3263,  3399,   549,  3401,   475,   385,
     705,   706,   707,   389,   539,   658,  3445,   325,   326,   486,
    1463,   674,  1465,  1466,   677,   678,   291,  1470,   467,  1472,
     549,  1474,  1475,  3462,  2019,   276,    19,   703,   467,  2463,
     507,    24,   549,    26,   467,   588,   228,   514,   230,  2034,
     467,   717,   510,  3080,  1497,   721,  3083,  3019,  3020,   467,
     333,  3023,   684,   685,   100,   708,   709,   733,   467,   588,
    2055,   494,   495,   467,   617,  2060,   147,   148,   149,  2503,
      24,   588,    26,   626,   668,    18,    19,    20,    21,    22,
     466,   549,   333,    25,  3218,    27,   467,   681,   617,  2602,
    3224,  2604,  2605,  3227,  3228,  3229,  3230,   626,  3019,  3020,
     617,  2298,   385,    26,  2099,   573,   389,    26,  3080,   626,
      26,  3083,  2546,    26,  2548,   709,  2313,  2626,  2315,    20,
      21,  1104,  1105,   403,   557,  1108,  1109,  2324,  2079,  1826,
    1827,   725,   726,   403,   385,   327,   655,   731,   389,   467,
     734,   562,  2806,  2807,  1359,  2809,  1361,  2666,  2812,   617,
     467,   467,  2696,   467,  2663,   467,   467,    39,   626,    41,
      42,    43,    26,   467,   467,  2903,   467,  2915,   360,   457,
     495,    26,  2720,   648,   649,   650,   651,    26,    26,  3216,
      26,  3218,    26,   466,   655,    95,   428,  3224,  3225,   467,
    3227,  3228,  3229,  3230,  1853,   398,   655,    26,   428,  3236,
    1859,  3335,   394,   467,  3338,  3339,  3340,  3341,   467,   463,
     490,     5,   467,     5,   406,   466,   944,   428,  2488,   947,
     490,   949,   950,   951,   952,   953,   506,  2661,   129,   130,
     131,   132,   133,   134,   428,   308,   506,   428,   311,   428,
     313,   428,   710,   711,   428,   428,  3218,   428,   467,   507,
     661,   443,  3224,  3225,    20,  3227,  3228,  3229,  3230,    20,
     333,   467,   467,  2672,  3236,   428,  2309,   459,  2538,   549,
     343,  2680,  2681,     5,   467,   467,   659,   495,    26,   549,
     655,  3253,   428,  2553,   296,   463,  3420,   398,   480,   362,
      30,   337,    20,    26,  2564,    26,    26,    26,  3335,    26,
      26,  3338,  3339,  3340,  3341,  2300,    26,   428,   588,   428,
    2353,   357,   385,    26,   428,   625,   389,  2052,   588,   428,
     428,  2316,  2317,  2318,  2319,  3362,    26,    39,   198,    41,
      42,    43,   524,     5,    20,   467,    26,   617,    26,    26,
     655,   428,  2337,   213,   214,     5,   626,   617,   394,    26,
     428,   428,   222,   340,  1895,     5,   626,   549,  2401,   428,
     406,   428,   428,  3335,  2061,   428,  3338,  3339,  3340,  3341,
     659,   417,  1825,  1826,  1827,  1953,   428,   428,   467,  1832,
    1833,   573,   661,  3420,   428,    26,   256,   625,   434,    25,
    3362,  3428,   428,   466,   661,   265,    25,    25,   444,  1852,
    2395,   447,  1855,  1856,    25,   174,   428,  1860,    25,  1862,
     428,  1864,   428,   428,   460,   428,   340,   428,   428,  2616,
     428,  1962,  3086,  2158,   294,   617,   308,  2697,   428,   311,
     428,   313,   659,  2630,   626,  1888,   428,  2135,  2136,   403,
      40,  2176,   428,   655,   467,   625,  1899,   655,  3420,     8,
     495,   333,   652,  2150,   655,   515,  3428,   463,  2728,   304,
       5,   343,   508,   660,  2052,   496,   631,   653,   237,   339,
     239,   653,   457,   694,  1927,   496,  1929,   694,   364,   647,
     362,     8,  1935,  1936,  1937,   254,     5,   632,  1941,  1942,
    1943,  1944,   538,   262,   174,     5,  2491,   266,  2493,  1952,
    2078,   467,   548,   385,  2961,   420,   467,   389,   277,   697,
     467,   381,  1965,   382,  2092,   467,   467,   614,   710,   711,
     625,     8,   291,   569,  1958,  1978,   490,   573,    14,   129,
     130,   131,   132,   133,   134,     5,  1989,   611,   694,  1992,
     694,   467,   506,   457,  2814,   467,    26,   147,   148,   149,
    2003,    26,   102,   128,   495,   601,  2965,   237,   467,   239,
    2013,  2014,  2015,   655,   610,   467,   625,  2020,   467,   467,
    2158,   467,   467,   467,   254,   495,   457,    26,     5,   215,
     655,   631,   262,   625,   466,   549,   266,   467,  2176,   467,
       5,   661,  3035,   467,   467,  2048,   308,   661,   660,   311,
     388,   313,   592,  2056,     5,  2058,  2059,  3155,  2061,    18,
      26,   291,    19,    26,   191,  3163,   256,    25,   625,   658,
    2073,   333,   655,   614,   588,   518,   518,  2080,     5,  3177,
      26,   343,   582,   189,   582,  2088,   436,  2090,  3072,    26,
     359,  2636,   582,   428,  2639,   467,   428,   661,   428,   467,
     362,   655,   467,   617,   562,   467,   467,  1217,  2111,   467,
    2113,  2114,   626,  2116,   699,   428,  2119,  2120,   612,   495,
     582,   655,   467,   385,   652,     5,     5,   389,   661,     5,
    2299,   615,  2135,  2136,     5,   655,   519,   287,   661,   660,
     290,   467,     5,     8,    26,   192,   357,  2150,    26,   196,
     102,  2696,  2155,  2156,  2157,   363,   342,     5,  2161,     5,
     428,  2908,   348,   349,   350,   467,  2169,  3237,   428,   397,
     467,   632,  2833,  2834,  2835,  2922,  2837,  2838,  2839,  2840,
    2841,  2842,   368,   661,  2187,  2846,    14,   695,     5,  2474,
      26,   582,  2195,  2196,   586,  2480,  2199,   137,  2299,   655,
     467,   467,     5,   660,   466,   463,   661,   674,    26,  3307,
    2213,   428,     5,     5,   654,  2500,   405,   369,  2221,   463,
     467,  2224,  2225,  2226,  2227,  2228,   497,     5,  2231,     8,
     655,     5,  2235,  2236,   467,   467,  2239,    18,    19,    20,
      21,   497,   467,   467,   467,   655,   467,   294,     8,   655,
     589,     5,    18,    19,    20,    21,   363,  2260,   408,  2262,
    2263,    25,   382,  2266,  2267,    20,    21,   382,   655,  3089,
     382,  3091,   467,   423,   397,   495,   495,   427,   462,     5,
     457,   467,     5,   686,    26,     5,     5,     5,    25,   475,
    2293,    26,   478,  2296,   631,  2298,   652,    14,    14,  2302,
     486,   467,   631,     5,     5,  2308,    40,   428,  3315,  2312,
    2313,  3409,  2315,   467,   661,   465,   467,   428,  2321,  2322,
     428,  2324,  2325,   428,   428,  2328,  2329,  3384,  3385,  3386,
    3387,  3388,  3389,     6,   428,   521,  2474,     7,   484,   306,
     428,     5,  2480,   493,    26,   655,   661,  2350,   129,   130,
     131,   132,   133,   134,    26,    26,   655,     8,  2361,    20,
     428,   511,  2500,   129,   130,   131,   132,   133,   134,     5,
     556,   602,   106,   107,   129,   130,   131,   132,   133,   134,
     312,     5,     5,   582,     5,  3205,  2389,     5,   428,   575,
     576,   703,   607,   428,   655,   467,   661,   507,  2943,     5,
     586,   589,   661,   248,   659,   591,    26,   428,   661,   661,
    3157,   507,  2415,   467,   467,     5,     5,   659,    25,   654,
      25,    25,   483,    25,    25,   334,    26,    26,    26,    26,
      26,  2976,    26,   428,    26,     5,   428,   171,   504,     5,
     467,  3400,   592,   428,   630,  2730,  2731,   586,   278,    26,
      25,   463,   428,   477,   382,    20,   190,   589,   180,   467,
    2463,   467,  2710,   467,  2712,   467,   467,   467,     5,   467,
    3098,     5,    14,   248,   428,  2478,   662,     5,   495,   428,
      26,   478,    26,  2486,  2487,  2488,   428,   428,   411,   428,
     604,    26,   428,   278,   428,   428,   467,   382,  2501,   428,
    2503,  2521,   279,   477,  2507,  2508,   495,   582,   658,   428,
     655,  3331,  3519,    14,   467,     7,   277,    26,   277,   661,
     428,   655,   429,   467,   428,   611,  2695,   428,   463,   467,
      25,   279,   428,   428,   428,  2538,   428,   428,     5,   428,
     428,  2669,   655,  2546,  2672,  2548,  3366,     5,  2551,  2675,
    2553,  3298,  2680,  2681,   655,  2623,  2576,   655,  3455,   968,
    1477,  2564,  2385,    29,  2100,  2325,  2569,  2570,  2571,    31,
     531,  2655,   206,  2331,   347,   114,  1957,  2580,   312,   313,
     298,   637,  2585,   340,  1958,   319,   118,   209,   581,   323,
     348,  2594,  2730,  2731,  2695,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   520,   376,  1236,  2610,   539,  2612,
     375,    25,  3445,  2616,  3159,  2019,   773,   960,   408,   337,
    2623,    40,  2318,   553,  1465,   551,  1214,  2630,  2193,  2060,
    2200,  1825,  2701,  2988,  2127,  2411,  1828,  3496,   356,   357,
    2321,  2145,  1377,  3171,   691,   692,  3191,    16,    92,    40,
    3119,  3471,  2655,    40,  2657,    22,  2659,  2660,  2661,  2105,
     730,  2111,   903,   323,   982,  2114,  2699,  1833,  1181,  3116,
    2673,  3271,  2675,  2676,  2677,   755,   394,  1371,  3462,  1436,
    2697,  1361,  3066,  2873,  3281,  1132,  1459,  2690,   406,   442,
    2871,  2855,   157,  2940,  2697,  2698,  2699,  2579,  2912,   417,
    2312,  1995,  1972,  2950,  3471,  2474,  3093,  2710,  3356,  2712,
     129,   130,   131,   132,   133,   134,   434,  2504,  2881,  2722,
    2723,  2580,  2266,  2231,  2795,  2728,   444,  2168,   147,   148,
     149,  2796,  3083,  3362,  3136,  2551,  1852,  2740,  2585,     8,
     787,  3512,   460,  2746,  2747,  2748,  2749,  2750,  2751,  2571,
     797,   672,  3018,  2741,  3091,  2570,  1210,  1936,  2761,  1935,
    1847,  3325,   496,  2766,  3017,  1206,  2934,  3216,  1820,  3235,
    3224,  2661,  2296,   507,    -1,    -1,  1886,  1887,  1376,   529,
      -1,    -1,   500,  1893,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2795,  2796,   259,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   267,  2806,  2807,   523,  2809,    -1,   273,  2812,
     275,  2814,    -1,    -1,    -1,  2818,    -1,    -1,    -1,    -1,
     538,   286,    -1,    -1,    -1,    -1,    -1,   545,    -1,   563,
     548,    -1,    -1,  2934,    -1,    -1,    -1,  2965,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   314,
    3395,   569,    -1,    -1,  2857,   573,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   330,    -1,  2870,   287,    -1,
     335,   290,    -1,    -1,   592,    -1,    -1,    -1,    -1,  2882,
    2883,  2884,   347,    -1,    -1,    -1,    -1,    -1,    -1,   354,
      -1,    -1,   610,    -1,    -1,   942,    -1,    -1,    -1,    -1,
     634,    -1,    -1,    -1,    -1,  2908,  3154,    -1,    -1,  2912,
      -1,    -1,  2915,    -1,    -1,    -1,    -1,    -1,    -1,  2922,
      -1,    -1,    -1,    -1,   658,   659,   660,   661,   342,  2932,
      -1,    -1,  2935,  2936,   348,   349,   350,  2940,    -1,    -1,
      -1,    -1,    -1,   677,    -1,    -1,  3491,  2950,    -1,  2952,
      -1,    -1,  3237,    -1,   368,    -1,    -1,    -1,  2961,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2083,    -1,  1022,    -1,    -1,   712,    -1,
      -1,    -1,    -1,    -1,   718,    -1,   720,    -1,    -1,   408,
     724,    -1,    -1,   727,    -1,    -1,   730,    -1,    -1,  3002,
      -1,    -1,    -1,    -1,   423,  3008,   740,    -1,   427,    20,
      21,    22,    -1,  2123,  3017,    -1,  3019,  3020,    -1,    -1,
    3023,   755,    -1,    -1,    -1,    -1,   760,    -1,    -1,    40,
      -1,  3034,    -1,   767,   768,   769,    -1,    -1,    -1,   773,
      -1,    -1,   507,    -1,    -1,    -1,   465,   781,    -1,   514,
      -1,    -1,    -1,    -1,  3057,    -1,  3059,    -1,    -1,    -1,
      -1,   475,    -1,   797,   478,    -1,    -1,    -1,    -1,  3072,
      -1,   536,   486,    -1,   493,    -1,   541,  3080,    -1,    -1,
    3083,    -1,    -1,  3086,    -1,    -1,  3089,    -1,  3091,    -1,
    3093,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,  3237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   521,    -1,    -1,
      -1,    -1,    -1,  3116,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1180,    -1,    -1,   147,   148,   149,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3154,  3321,    -1,  3157,    -1,    -1,    -1,    18,    19,
      20,   575,   576,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,   586,   592,    -1,    -1,    -1,   591,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1237,  1238,    -1,    -1,    -1,    -1,    -1,  3200,    -1,  1246,
      -1,    -1,  3205,    -1,    -1,  3208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3216,    -1,  3218,   630,    -1,    -1,    -1,
    3321,  3224,  3225,    -1,  3227,  3228,  3229,  3230,    -1,    -1,
    3233,    -1,  3235,  3236,    -1,  3238,    -1,  3240,    -1,   658,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,   662,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3271,  2379,
    2380,    -1,  3400,  3276,    -1,  3278,   287,    -1,    -1,   290,
    2390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1022,    -1,
      -1,    -1,    -1,    -1,    -1,  3298,    -1,    -1,    -1,    -1,
      -1,    -1,  1036,    -1,    -1,    -1,  2416,  2417,  2418,  2419,
      -1,    -1,  3315,    -1,  2424,  2425,  2426,  2427,    -1,    -1,
      -1,  2431,  3325,    -1,    -1,    -1,    -1,    -1,  3331,    -1,
      -1,    -1,  3335,    -1,    -1,  3338,  3339,  3340,  3341,  3342,
      -1,    -1,    -1,  1077,    -1,    -1,  1393,    -1,    -1,    -1,
      -1,    -1,    -1,  3356,    -1,    -1,    -1,    -1,    -1,  3362,
    1094,  1095,  1096,  3366,  1098,    -1,  1100,  1101,   228,    -1,
      -1,    -1,  1106,  1107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3384,  3385,  3386,  3387,  3388,  3389,    -1,    -1,    -1,
      -1,    -1,    -1,  3396,    -1,    -1,    -1,   408,    -1,  2509,
    2510,    -1,    -1,    -1,    -1,    -1,  2516,  2517,    -1,    -1,
    1144,    -1,   423,  1460,     9,    -1,   427,  3420,    -1,    -1,
      -1,    -1,  1156,    18,    19,  3428,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1180,  1181,     9,    -1,
      -1,    -1,    -1,    -1,   465,  1189,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,  3471,    -1,
    3473,  1205,  1206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    96,    -1,    -1,    -1,    -1,   101,  3510,  3511,  3512,
      -1,    -1,    -1,   108,    -1,    -1,  3519,    -1,  3521,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2645,  2646,    -1,    -1,    -1,
     101,   136,    -1,    -1,  2654,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,   432,    -1,  2684,  2685,    -1,    -1,    -1,    -1,
      -1,   592,    -1,    -1,    -1,    40,     8,   447,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,  2711,    -1,  2713,   464,    -1,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
     480,    -1,    -1,    -1,    -1,  1359,    -1,  1361,  1362,  1363,
      -1,    -1,    -1,   228,    -1,   230,  1370,  1371,    -1,    -1,
    1374,    -1,    -1,    -1,  1378,    -1,    -1,   658,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2767,  2768,  1393,
     520,  2771,  2772,    -1,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,   532,    -1,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1438,    -1,    -1,   129,   130,   131,
     132,   133,   134,   573,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,    -1,   332,  1472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2861,   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1497,   624,   360,    -1,    -1,    -1,    -1,
      -1,   332,    -1,    -1,    -1,    -1,   636,   637,    -1,    -1,
      -1,    -1,    -1,    -1,   644,    -1,  1833,   647,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   655,    -1,    -1,    -1,   394,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2933,    -1,    -1,    -1,  2937,    -1,   424,
      -1,    -1,   287,    -1,   429,   290,    -1,   432,    -1,    -1,
      -1,    -1,    -1,  2953,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2972,    -1,   459,   287,    -1,    -1,   290,   464,
      -1,   432,   467,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,    -1,  1929,    -1,   479,   480,   447,    -1,  1935,  1936,
      -1,    -1,    -1,    -1,  1941,  1942,  1943,  1944,    -1,    -1,
      -1,    -1,    -1,   464,    -1,    -1,   467,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,   480,
      -1,    -1,    -1,    -1,   519,   520,    -1,    -1,    -1,   524,
      -1,    -1,    -1,    -1,     9,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,   507,    -1,   543,    24,
      25,    26,    27,   408,   549,    -1,    -1,    -1,    -1,   520,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,
      -1,   532,   427,     9,    -1,    -1,    -1,    -1,   573,    -1,
      -1,    -1,    18,    19,    20,    -1,   408,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   423,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
     465,    -1,   573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,   617,    -1,    -1,    -1,   101,    -1,    -1,   624,
      -1,   626,    -1,   108,    22,    -1,    -1,    -1,   493,    -1,
      -1,   636,   637,   465,    -1,    -1,    -1,    -1,    -1,   644,
      -1,   612,    40,    -1,    -1,    -1,   511,    -1,    -1,    -1,
     655,   136,    -1,   624,    -1,   101,    -1,    -1,    -1,  2116,
      -1,   493,    -1,    -1,    -1,   636,   637,    -1,    -1,  3189,
      -1,    -1,  3192,   644,    -1,    -1,   647,    -1,    -1,   511,
      -1,    -1,    -1,    -1,   655,    -1,    -1,    -1,  1832,  1833,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,   710,   711,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   228,  1888,   230,    -1,    -1,    -1,   147,
     148,   149,    -1,    -1,    -1,    -1,  2213,    -1,    -1,    -1,
     592,    -1,    -1,    -1,  2221,    -1,    -1,  2224,  2225,  2226,
    2227,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,  2236,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,    -1,  3319,
      -1,    -1,    -1,  2260,    -1,    -1,    -1,     9,    -1,    -1,
    2267,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,   658,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,    -1,   332,  3368,  3369,
      -1,  3371,    -1,  3373,  3374,    -1,    -1,    -1,    -1,  2003,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,   287,
      -1,    -1,   290,    -1,    96,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,   228,    -1,   108,    -1,    -1,   394,
      -1,    -1,    -1,    -1,  3434,    -1,  3436,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2073,
      -1,    -1,    -1,    -1,   136,    -1,  2080,    -1,    -1,   424,
      -1,    -1,    -1,    -1,   429,    -1,  2090,   432,    -1,  3469,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,   449,  3485,  3486,  2111,    -1,  3489,
      -1,    -1,  3492,    -1,   459,    -1,  2120,    -1,    -1,   464,
      -1,    -1,   467,    -1,    -1,   470,   432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   479,   480,    -1,    -1,    -1,    -1,
      -1,   447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     408,  2155,  2156,  2157,    -1,    -1,    -1,  2161,   464,    -1,
      -1,   467,    -1,    -1,    -1,   423,   228,    -1,   230,   427,
      -1,  2488,    -1,   479,   480,   520,    -1,    -1,    -1,   524,
      -1,    -1,    -1,  2187,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,
     545,    -1,    -1,    -1,   549,    -1,    -1,   465,    -1,    -1,
      -1,    -1,    -1,    -1,   520,    -1,    -1,    -1,    -1,    -1,
      -1,  2538,    -1,    -1,    -1,    -1,   532,    -1,   573,    -1,
      -1,    -1,    -1,    -1,  2551,   493,  2553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2564,   432,    -1,
      -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   447,    -1,   327,    -1,   573,    -1,    -1,
     332,    -1,   617,    -1,    -1,    -1,    -1,    -1,    -1,   624,
     464,   626,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,
    2607,   636,   637,    -1,  2298,  2299,   480,    -1,   360,   644,
      45,    46,    47,    48,    49,    50,   612,    -1,    -1,  2313,
     655,  2315,    -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,
    2324,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
     636,   637,   394,    -1,   592,    -1,   520,    -1,   644,    -1,
     298,   647,    -1,    -1,   406,    -1,    -1,    -1,   532,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2361,    -1,    -1,
      -1,    -1,   424,    -1,    -1,   710,   711,   429,    -1,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,
    2697,   443,    -1,    -1,    -1,  2389,    -1,   449,    -1,   573,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   459,   356,   357,
     658,    -1,   464,    -1,    -1,   467,    -1,    -1,   470,    -1,
      -1,  2728,    -1,    -1,    -1,    -1,    -1,   479,   480,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   612,  2746,
    2747,  2748,  2749,    -1,    -1,    -1,   394,    -1,    -1,    -1,
     624,    -1,    -1,    40,    -1,    -1,    -1,    -1,   406,    -1,
      -1,    -1,   636,   637,    -1,    -1,    -1,   519,   520,   417,
     644,    -1,   524,   647,    -1,    -1,    -1,    -1,    -1,    -1,
     532,   655,    -1,    -1,    -1,    -1,   434,    -1,  2795,  2796,
      -1,   543,    -1,    -1,    -1,    -1,   444,   549,    -1,  2806,
    2807,    -1,  2809,    -1,    -1,  2812,    -1,  2814,    -1,    -1,
      -1,  2818,   460,  2507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   573,    -1,    -1,    -1,    -1,  2833,  2834,  2835,    -1,
    2837,  2838,  2839,  2840,  2841,  2842,    -1,    -1,    -1,  2846,
      -1,     9,   129,   130,   131,   132,   133,   134,    -1,    -1,
      18,    19,   500,    -1,    -1,    -1,    24,    25,    26,    27,
     147,   148,   149,    -1,    -1,   617,    24,    25,    26,    27,
      -1,    -1,   624,    -1,   626,   523,  2570,    -1,    17,    18,
      19,    20,    21,    22,   636,   637,    -1,    -1,    -1,    -1,
     538,    -1,   644,    -1,    -1,    -1,    -1,   545,    -1,    -1,
     548,    40,    -1,   655,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,   569,  2616,    -1,    -1,   573,    -1,    -1,    96,    -1,
      -1,    -1,    40,   101,    -1,   370,  2630,    -1,    -1,    -1,
     108,    -1,    -1,   101,   592,    -1,    -1,    -1,   383,    -1,
      -1,    -1,    -1,    -1,  2961,    -1,    -1,    -1,   710,   711,
      -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2673,
      -1,  2675,    20,  2677,    -1,    -1,    24,    25,    26,    27,
     129,   130,   131,   132,   133,   134,  2690,    -1,    -1,    -1,
     287,  2695,    -1,   290,  2698,  2699,    -1,    -1,   147,   148,
     149,   446,  3019,  3020,    -1,    -1,  3023,    -1,   453,    -1,
      -1,   129,   130,   131,   132,   133,   134,    -1,  2722,  2723,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,
     228,    -1,   230,   101,    -1,    -1,    -1,  2761,    -1,    -1,
     228,    -1,    -1,  3080,    -1,    -1,  3083,    -1,    -1,  3086,
      -1,   516,  3089,    -1,  3091,    -1,    -1,    -1,    -1,    -1,
      -1,   526,   527,    -1,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,
      -1,    -1,   567,   568,    -1,    -1,   423,   572,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,
      -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,
      -1,    -1,    -1,  2857,   332,    -1,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,  2870,    -1,   465,   287,
      -1,    -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,   360,    -1,   629,    -1,    -1,    -1,  3205,    -1,
      -1,    -1,    -1,    -1,    -1,   640,   493,    -1,    -1,    -1,
      -1,  3218,    -1,    -1,  2908,    -1,    -1,  3224,  3225,    -1,
    3227,  3228,  3229,  3230,   511,    -1,   394,    -1,  2922,  3236,
      -1,  3238,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
    2934,    -1,    -1,    -1,    -1,    -1,  3253,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,  2952,    -1,
      -1,   429,    -1,    -1,   432,    -1,    -1,  2961,    -1,   408,
      -1,    -1,    -1,    -1,   432,   443,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,   423,    -1,    -1,    -1,   427,   447,
      -1,   459,    -1,    -1,    -1,    -1,   464,    -1,    -1,   467,
     408,    -1,   470,    -1,    -1,   592,   464,    -1,  3315,   467,
      -1,   479,   480,    -1,    -1,   423,    -1,    -1,    -1,   427,
      -1,    -1,   480,    -1,  3331,    -1,   465,    -1,  3335,    -1,
      -1,  3338,  3339,  3340,  3341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   520,    -1,   493,  3362,   524,   465,    -1,  3366,
      -1,    -1,   520,    -1,   532,    -1,    -1,    -1,    -1,    -1,
      -1,   658,   511,    -1,   532,   543,   228,    -1,    -1,    -1,
      -1,   549,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   511,    -1,   573,    -1,    -1,    -1,   447,
      -1,    -1,    -1,  3420,    -1,   573,    -1,    -1,    -1,    -1,
      -1,  3428,  3116,    -1,    -1,    -1,   464,    -1,    -1,   467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,   617,
      -1,    -1,    -1,   592,   612,    -1,   624,    -1,   626,    -1,
      -1,    -1,    -1,  3157,  3471,    -1,   624,    -1,   636,   637,
      -1,    -1,    -1,    -1,    -1,    -1,   644,    -1,   636,   637,
      -1,    -1,   520,    -1,   592,    -1,   644,   655,    -1,   647,
      -1,    -1,    -1,    -1,   532,    -1,    -1,   655,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3200,    -1,    -1,    -1,
      -1,    -1,  3519,     5,     6,     7,     8,     9,    10,   658,
      12,    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,   573,    -1,    -1,    -1,    -1,
      -1,    33,   710,   711,    -1,    -1,  3240,    -1,    -1,    -1,
     658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   612,    -1,    -1,  3271,    -1,    -1,
     432,    -1,  3276,    -1,  3278,    -1,   624,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,   636,   637,
      -1,    -1,    -1,    -1,  3298,    -1,   644,    99,    -1,   647,
      -1,    -1,   464,    -1,    -1,   467,   108,   655,    -1,    -1,
      -1,  3315,    -1,    -1,    -1,    -1,    -1,  3321,   480,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,   147,   148,   149,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,   519,   520,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3384,  3385,  3386,  3387,  3388,  3389,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   573,    -1,   215,    -1,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   636,   637,    -1,    -1,    -1,    -1,
      -1,    -1,   644,    -1,    -1,   647,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   655,    -1,    -1,    -1,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,    -1,    -1,    -1,    -1,  3519,   318,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,    -1,   334,    -1,    -1,   337,   338,    -1,    -1,    -1,
     342,    -1,    -1,    -1,    -1,    -1,   348,   349,    -1,    -1,
      -1,    -1,    -1,   355,   356,   357,   358,   359,   360,    -1,
      -1,    -1,   364,    -1,    -1,    -1,   368,    -1,   370,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   378,   379,   380,    -1,
     382,   383,    -1,    -1,    -1,   387,   388,    -1,   390,   391,
     392,   393,   394,   395,   396,    -1,    -1,    -1,    -1,    -1,
     402,   403,   404,    -1,   406,   407,    -1,    -1,    -1,   411,
     412,   413,   414,   415,   416,   417,   418,    -1,   420,    -1,
      -1,    -1,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,   463,   464,    -1,    -1,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,    -1,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,    -1,    -1,   495,   496,   497,   498,   499,   500,   501,
     502,   503,    -1,   505,   506,   507,   508,    -1,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,    -1,   547,   548,   549,   550,   551,
     552,    -1,    -1,   555,   556,    -1,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,    -1,    -1,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,    -1,    -1,    -1,    -1,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   681,
      -1,    -1,    -1,    -1,   686,    -1,    -1,    -1,   690,    -1,
      -1,   693,   694,   695,   696,    -1,    -1,   699,   700,    -1,
     702,   703,   704,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,   147,   148,   149,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,   230,    -1,
      -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     312,    -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,    -1,   334,    -1,    -1,   337,   338,    -1,    -1,    -1,
     342,    -1,    -1,    -1,    -1,    -1,   348,   349,    -1,    -1,
      -1,    -1,    -1,   355,   356,   357,   358,   359,   360,    -1,
      -1,    -1,   364,    -1,    -1,    -1,   368,    -1,   370,    -1,
      -1,    -1,    -1,    -1,    -1,   377,   378,   379,   380,    -1,
     382,   383,    -1,    -1,    -1,   387,   388,    -1,   390,   391,
     392,   393,   394,   395,   396,    -1,    -1,    -1,    -1,    -1,
     402,   403,   404,    -1,   406,   407,    -1,    -1,    -1,   411,
     412,   413,   414,   415,   416,   417,   418,    -1,   420,    -1,
      -1,    -1,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,   463,   464,    -1,    -1,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,    -1,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,    -1,    -1,   495,   496,   497,   498,   499,   500,   501,
     502,   503,    -1,   505,   506,   507,   508,    -1,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,    -1,   547,   548,   549,   550,   551,
     552,    -1,    -1,   555,   556,    -1,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,    -1,    -1,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,    23,    -1,    -1,    -1,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,    -1,    39,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   681,
      -1,    -1,    -1,    -1,   686,    -1,    -1,    -1,   690,    -1,
      -1,   693,   694,   695,   696,    -1,    -1,   699,   700,    -1,
     702,   703,   704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,   266,
      -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,   276,
     277,   278,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   311,    -1,   313,   228,    -1,    -1,
      -1,    30,    -1,   320,    -1,    34,    -1,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    44,   333,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,   343,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   362,   363,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     377,    -1,    91,    -1,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,   389,    -1,   103,   104,    -1,   106,    -1,    -1,
     397,   398,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,
      -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
     169,    -1,   171,   172,   173,    -1,    -1,    -1,    -1,   466,
     179,    -1,    -1,   182,    -1,   184,   185,   186,    -1,    -1,
     477,    -1,    -1,   192,    -1,   194,   195,    -1,   197,    -1,
     199,   200,    -1,    -1,   203,    -1,    -1,   206,   207,   208,
      -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,
     219,    -1,    -1,    -1,   223,    -1,   225,   226,    -1,    -1,
     517,   432,   231,    -1,    -1,    -1,   235,    -1,    -1,   238,
      -1,   240,    -1,   242,    -1,   244,   447,   246,   247,    -1,
     249,   250,   251,    -1,    -1,    -1,   255,    -1,   257,   258,
      -1,   260,    -1,   464,    -1,    -1,   467,    -1,    -1,   268,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,   480,
      -1,    -1,   281,    -1,    -1,   284,   285,    -1,    -1,   288,
     289,   578,    -1,   292,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   301,   302,   303,    -1,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   315,   316,   317,   520,
     319,    -1,    -1,    -1,   323,   324,    -1,   614,    -1,   328,
      -1,   532,    -1,    -1,    -1,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   344,   345,   346,    -1,    -1,
      -1,    -1,    -1,   352,   353,    -1,    -1,    -1,    -1,   358,
      -1,    -1,   361,    -1,    -1,    -1,   365,   366,    -1,    -1,
      -1,    -1,   573,   660,    -1,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,   675,   676,
     677,   678,   679,   680,   393,   682,   683,    -1,    -1,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,   407,    -1,
      -1,   612,   699,    -1,    -1,    -1,    -1,    -1,    -1,   418,
      -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   430,    -1,    -1,    -1,   636,   637,    -1,   437,    -1,
     439,   440,    -1,   644,    -1,    -1,   647,    -1,    -1,   448,
       5,     6,     7,     8,   655,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     529,   530,    -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    -1,
      -1,    -1,    -1,   552,   553,   554,   555,    -1,    -1,    -1,
     559,    -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,
      -1,   570,   571,    -1,   129,   130,   131,   132,   133,   134,
      -1,    -1,   581,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   594,    -1,   596,    -1,    -1,
     599,    -1,    -1,     6,     7,     8,   605,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   631,    -1,    -1,   634,    -1,    40,    -1,    -1,
     639,    -1,    -1,   642,   643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,    -1,
      -1,    -1,     6,     7,     8,   664,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   687,   688,
     689,   690,   691,   692,   693,    -1,    40,   696,    -1,   698,
      -1,   700,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,   134,   287,    -1,    -1,   290,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,   147,   148,   149,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,   129,
     130,   131,   132,   133,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,   134,    -1,    -1,   493,    -1,
      -1,    -1,    -1,   287,    -1,    -1,   290,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,   287,    -1,    -1,   290,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     423,    -1,    40,    -1,   427,   428,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,    -1,   408,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,   423,
      -1,    -1,    -1,   427,   428,   222,    -1,    -1,   287,    -1,
     493,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   658,    -1,   408,    -1,    -1,   511,    -1,
      -1,   129,   130,   131,   132,   133,   134,    -1,    -1,   256,
     423,   465,    -1,    -1,   427,   428,    -1,    -1,   265,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   493,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,    -1,
      -1,    -1,   465,    -1,    -1,    -1,    -1,   511,   408,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   423,    -1,    -1,    -1,   427,   428,   592,
     493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,   511,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   423,   465,    -1,    -1,   427,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,   592,    -1,
      -1,    -1,    -1,   493,    -1,   658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,    -1,   287,
      -1,   511,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,
      -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,   658,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,   592,    -1,    -1,   658,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     408,    -1,    40,   592,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,   427,
     428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   658,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   129,   130,
     131,   132,   133,   134,    -1,    -1,    -1,   465,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,   147,   148,   149,   658,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,    40,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,   592,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   290,
      -1,    -1,     6,     7,     8,    40,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   287,
     658,    -1,   290,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
     287,    -1,    -1,   290,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,    -1,   408,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,    -1,   423,    -1,    -1,    -1,   427,   428,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
     408,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,   423,    -1,    -1,    -1,   427,
     428,    -1,    -1,   287,    -1,    -1,   290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,   134,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   465,    -1,    -1,
     511,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,   101,    -1,
     427,    -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,
      -1,    -1,   287,    -1,    -1,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   511,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   465,    -1,
      -1,    -1,    -1,   287,    -1,    -1,   290,    -1,    -1,    -1,
      -1,   478,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   592,    -1,    -1,   408,    -1,   493,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,   423,
      -1,    -1,    -1,   427,   511,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   287,    40,    -1,   290,    -1,    -1,
      -1,   465,    -1,    -1,    -1,   228,    -1,   658,    -1,    -1,
      -1,    -1,    -1,   408,   478,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,   134,   423,   493,
      -1,   101,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   408,   592,    -1,   511,    -1,    -1,
     658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
     465,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,   478,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   493,    40,
      -1,   465,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   658,    -1,    -1,    -1,   408,   511,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   592,   493,
     423,    -1,    -1,    -1,   427,    -1,    32,    -1,    -1,    35,
      -1,    -1,    -1,    40,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,   465,    -1,    -1,    40,    24,    25,    26,    27,
     287,    -1,    -1,   290,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,   134,   658,    -1,    -1,   592,    -1,    -1,
     493,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,
     116,   117,    -1,    -1,   447,    -1,    -1,    -1,   592,    -1,
     126,    -1,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,   464,   287,    -1,   467,   290,    -1,    -1,    -1,    -1,
     147,   148,   149,   101,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,   658,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   658,    -1,   519,   520,    -1,   592,
      -1,   408,    -1,    -1,    18,    19,    -1,    -1,    -1,   532,
      24,    25,    26,    27,    -1,    -1,   423,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   290,
     573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,
      -1,    -1,   432,   408,    -1,   658,    -1,    -1,    -1,    -1,
      -1,   478,    -1,    -1,    -1,    -1,    -1,   447,   423,    -1,
     228,    -1,   427,    -1,    -1,    -1,   493,   101,    -1,   612,
     287,    -1,    -1,   290,   464,    -1,    -1,   467,    -1,    -1,
      -1,   624,   298,    -1,   511,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,   636,   637,    -1,    -1,    -1,    -1,    -1,
     465,   644,   287,    -1,   647,   290,    -1,    -1,    -1,    -1,
      -1,    -1,   655,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,   337,    -1,    -1,   178,    -1,    -1,    -1,   493,   519,
     520,    -1,    -1,   187,    -1,    -1,   190,    -1,    -1,    -1,
     356,   357,   532,    -1,    -1,    -1,   511,   408,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,
      -1,    -1,   423,    -1,    -1,   592,   427,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    -1,   394,   233,
      -1,    -1,    -1,   573,    -1,    -1,    -1,   241,    -1,    -1,
     406,   408,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,   417,    -1,    -1,   465,    -1,   423,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,
      -1,    -1,   612,   408,    -1,    -1,    -1,   592,   444,    -1,
      -1,   658,   493,    -1,   624,    -1,    -1,    -1,   423,    -1,
      -1,    -1,   427,   297,   460,    -1,   636,   637,   465,    -1,
     511,    -1,    -1,    -1,   644,    -1,    -1,   647,    -1,    -1,
      -1,   135,    -1,    -1,   432,   655,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,   329,   493,   331,    -1,   447,
     465,    -1,    -1,    -1,   500,    -1,    -1,   341,    -1,    -1,
      -1,    -1,    -1,   658,   511,    -1,   464,    -1,    -1,   467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   523,   493,    -1,
      -1,    -1,   480,   367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   375,   538,    -1,    -1,    -1,   511,    -1,    -1,   545,
      -1,   592,   548,    -1,    -1,    -1,    -1,    -1,    -1,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   520,   569,    -1,    -1,    -1,   573,   412,    -1,
      -1,    -1,    -1,    -1,   532,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   592,   592,    -1,    -1,    -1,
      -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,    -1,   658,   432,    -1,
      -1,    -1,    -1,    -1,    -1,   573,    -1,   592,    -1,    -1,
      -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   475,    -1,   297,    -1,    -1,    -1,    -1,    -1,    -1,
     464,    -1,   486,   467,    -1,    -1,   652,    -1,    -1,    -1,
      -1,   658,    -1,    -1,   612,    -1,   480,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,   331,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,   637,
      -1,    -1,    -1,   658,    -1,    -1,   644,    -1,    -1,   647,
      -1,    -1,    -1,    -1,    -1,    -1,   520,   655,    -1,    -1,
      -1,    -1,    -1,   367,    -1,    -1,   370,    -1,   532,    -1,
      -1,   375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     584,   585,   586,    -1,    -1,    -1,    -1,    -1,    -1,   573,
      -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   446,    -1,    -1,    -1,    -1,    -1,   612,   453,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     624,    -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   636,   637,    -1,    -1,    -1,    -1,    -1,    -1,
     644,    -1,    -1,   647,    -1,    -1,    -1,    -1,   492,    -1,
      -1,   655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,    -1,   700,    -1,    -1,    -1,
      -1,    -1,   526,   527,    -1,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,    -1,    -1,   567,   568,    -1,    -1,    -1,   572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   638,    -1,   640
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   112,   274,   393,   442,   474,   503,   770,
     798,   799,   851,  1023,  1077,  1079,  1080,  1081,  1086,  1088,
    1101,  1102,  1103,  1104,  1105,  1528,    28,    29,   771,   772,
     773,   774,   775,    27,   987,  1544,   987,    25,   987,  1443,
    1106,   800,  1443,   799,     0,  1078,  1081,  1104,    31,   773,
     775,   852,   647,    25,   228,   797,   798,   975,   987,   992,
    1086,  1101,  1107,  1142,  1143,  1144,  1145,  1146,  1150,   391,
     802,   803,   804,   805,   808,   809,    92,    97,   144,   145,
     152,   404,   430,   501,   593,   673,   681,   770,   776,   947,
    1022,  1082,  1083,  1085,  1089,  1090,  1096,  1108,  1129,  1262,
    1272,  1528,   652,   987,  1145,   280,   494,   495,  1152,    20,
     987,  1149,   655,   803,     5,   801,   391,   987,     5,   827,
     829,   830,   987,  1273,   987,   987,  1263,  1097,   987,   987,
    1085,  1091,   298,   337,   356,   357,   394,   406,   417,   434,
     444,   460,   500,   523,   538,   545,   548,   569,   573,   592,
     610,   853,   854,   855,   858,    25,  1142,  1148,    18,    19,
      26,    96,   108,   136,   230,   327,   360,   394,   406,   443,
     459,   467,   480,   524,   549,   573,   617,   626,   710,   711,
     720,   722,   913,   918,   929,   931,   987,  1142,  1153,  1154,
     495,    14,   850,   805,   558,  1249,   806,   803,   808,    32,
      35,   116,   117,   126,   298,   337,   356,   357,   372,   394,
     406,   417,   434,   444,   460,   500,   523,   538,   545,   548,
     569,   573,   592,   610,   652,   812,   821,   832,   833,   987,
     467,   151,   987,   797,   948,  1130,   987,   860,   357,   810,
     467,   836,   838,   839,   837,   846,   847,   467,   467,   859,
     495,   467,   803,   834,   462,   467,   467,   467,   467,   467,
     467,   467,   467,   467,   467,   720,   467,   794,     9,    18,
      19,    24,    25,    26,   101,   332,   424,   429,   432,   449,
     464,   467,   470,   479,   520,   532,   543,   573,   624,   636,
     637,   644,   655,   887,   895,   896,   897,   898,   899,   900,
     901,   929,   930,   932,   993,  1142,  1252,  1435,   467,   467,
     467,   467,   467,   467,    18,    19,    20,    21,    22,   721,
      26,   467,   557,     5,   463,  1153,    25,    26,   987,   993,
      19,    25,    26,   807,   993,   705,   706,   707,   811,   823,
     810,   467,   824,   836,   837,   467,   467,   822,   495,   467,
     834,   803,   831,   467,    26,   987,   467,  1098,   797,   797,
     467,   987,   467,   494,   816,    26,   661,   403,   490,   506,
     549,   588,   617,   626,   840,   661,   403,   490,   506,   549,
     588,   617,   626,   848,    26,    26,   861,   862,   863,   864,
     987,    26,   819,   820,    26,   655,   702,   937,   979,   987,
    1535,   979,   979,  1535,  1535,   887,    25,    26,    19,    24,
      25,    26,   933,   934,   935,   936,  1535,   887,   428,   887,
     887,   887,   887,   562,  1269,   467,   467,   887,   403,   490,
     506,   549,   588,   617,   626,  1438,  1439,   467,   887,   887,
     467,   467,   902,   467,   467,   467,   467,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    40,   129,   130,   131,   132,   133,
     134,   147,   148,   149,   287,   290,   408,   423,   427,   465,
     493,   511,   592,   658,   793,   888,   903,   905,   906,   907,
     908,   909,   910,   911,    26,   993,   457,   921,   919,   925,
     923,  1142,  1142,   720,   914,   987,  1154,   495,   463,    26,
     814,   803,   816,    26,   803,    26,    26,   802,   819,    26,
     655,    95,   828,  1274,   428,   467,  1264,  1545,  1546,  1547,
    1548,  1549,   949,  1131,  1092,   655,    26,   428,   841,   842,
     467,   843,   848,   849,   843,   467,   844,     5,   428,     5,
     428,     5,   321,     5,   853,   463,     5,     5,   428,   803,
     835,   467,     5,   495,   655,   428,   428,   428,   428,   428,
     428,   428,   428,   625,   934,    19,    26,   625,   428,   428,
     428,     5,   795,   887,   507,  1459,   887,   467,   661,    20,
     428,  1459,    20,  1252,   887,   887,   887,   887,   887,   887,
     887,   887,   887,   887,   887,   887,   887,   887,   887,   887,
     887,   887,   887,   887,   887,   887,   887,   467,   887,   887,
     467,  1142,   887,   887,   887,   887,   428,     5,   750,   751,
     752,   887,   467,  1153,   495,   659,   655,    26,   428,   296,
       5,   428,     5,   428,   321,   463,     5,   428,   835,   987,
    1159,  1160,  1162,  1109,  1159,   398,  1546,  1249,    36,    37,
      38,    44,    51,    52,    91,   103,   104,   106,   120,   127,
     138,   141,   142,   156,   158,   159,   160,   168,   169,   171,
     172,   173,   179,   182,   184,   185,   186,   192,   194,   195,
     197,   199,   200,   203,   206,   207,   208,   210,   211,   215,
     216,   217,   219,   223,   225,   226,   231,   235,   238,   240,
     242,   244,   246,   247,   249,   250,   251,   255,   257,   258,
     260,   268,   269,   281,   284,   285,   288,   289,   292,   293,
     301,   302,   303,   305,   315,   316,   317,   319,   323,   324,
     328,   336,   344,   345,   346,   352,   353,   358,   361,   365,
     366,   376,   393,   401,   407,   418,   437,   439,   440,   448,
     487,   498,   505,   529,   530,   534,   546,   552,   553,   554,
     555,   559,   563,   570,   571,   581,   583,   594,   596,   599,
     605,   631,   634,   639,   642,   643,   657,   664,   687,   688,
     689,   690,   691,   692,   693,   696,   698,   700,   713,   714,
     715,   716,   733,   755,   769,   770,   776,   777,   796,   866,
     867,   868,   869,   880,   881,   882,   883,   884,   885,   886,
     938,   942,   973,   994,   996,   999,  1000,  1001,  1002,  1015,
    1024,  1046,  1047,  1049,  1053,  1068,  1069,  1073,  1074,  1075,
    1076,  1084,  1099,  1112,  1123,  1124,  1125,  1136,  1139,  1175,
    1178,  1180,  1186,  1187,  1190,  1193,  1196,  1198,  1200,  1203,
    1210,  1215,  1219,  1220,  1221,  1233,  1234,  1237,  1243,  1244,
    1245,  1270,  1285,  1286,  1287,  1288,  1289,  1294,  1300,  1301,
    1319,  1322,  1352,  1354,  1444,  1445,  1476,  1477,  1484,  1495,
    1519,  1528,  1529,  1534,  1536,  1538,  1542,  1543,  1550,   770,
    1087,   660,   683,  1132,  1133,  1159,    20,   428,   462,   817,
     840,    26,   845,    26,    26,    26,   862,   864,   856,   820,
      26,   987,   979,   720,    20,   702,   987,   927,  1439,   927,
      26,    26,   625,    24,    26,   837,   928,   838,   428,   396,
     512,   621,  1467,   428,   428,    26,  1439,   428,   428,   428,
     428,   428,   428,   428,   478,   478,   478,   912,  1459,   478,
     912,  1459,   922,   920,   926,   924,    26,   915,     5,   916,
     463,  1153,   827,    20,   817,   467,    26,    26,   813,    26,
     655,   428,     5,  1159,   428,  1142,  1142,  1142,    25,  1142,
    1197,   987,    25,   987,  1428,   387,   988,   989,  1544,   987,
     987,  1217,   982,   988,   982,    25,   228,   987,  1151,  1523,
    1524,  1525,   987,  1540,  1428,   987,    26,   717,  1142,  1292,
     982,  1217,   912,    26,   993,  1257,  1258,  1257,   887,   894,
    1321,   889,   912,   988,  1485,  1485,   870,  1217,   982,  1290,
    1142,   984,   988,   894,  1485,  1142,  1217,  1142,  1320,  1485,
      25,   621,  1126,  1127,  1142,   982,   982,  1126,   983,   988,
     987,  1127,   982,  1485,   982,   984,  1142,  1173,  1174,   980,
     988,   984,   412,   597,   979,  1048,   987,   778,   985,   988,
      25,  1353,  1523,   912,  1173,   912,   988,  1199,   943,   170,
     178,   187,   190,   233,   241,   297,   322,   329,   331,   341,
     367,   375,   412,   437,   475,   486,   584,   585,   586,   597,
     700,  1062,  1194,  1195,  1142,   893,   894,  1209,  1535,  1535,
     981,   988,   912,  1197,  1271,  1142,  1248,    25,  1142,  1479,
     894,  1239,  1240,  1241,  1250,  1251,   894,  1530,   143,   193,
     230,   327,   402,   443,   510,   734,   918,   987,  1142,  1280,
     757,   894,   980,   625,   987,   995,  1113,   894,   980,    26,
    1142,  1070,   980,   894,  1496,   894,  1257,   987,   997,   998,
     984,   997,  1535,   984,   997,  1535,  1003,   997,    25,    26,
     421,   523,   993,  1051,  1142,  1161,  1163,   102,   312,   382,
     426,   604,   684,   685,   686,   695,   724,  1005,  1007,  1009,
    1011,  1013,  1137,  1138,  1141,   373,   384,   435,   450,   539,
    1355,   675,   676,   951,   952,   953,   987,  1134,   682,  1133,
     428,   340,   428,   428,   428,   428,   659,     5,   428,   428,
     463,   467,   661,   428,    26,   625,   661,    18,    19,    20,
      25,    26,   101,   432,   447,   464,   467,   480,   520,   532,
     573,   612,   624,   636,   637,   644,   647,   987,   993,  1434,
    1436,  1466,  1468,  1469,  1471,  1472,  1473,  1524,  1527,  1269,
     428,  1269,  1269,  1269,  1269,  1269,  1269,    25,    25,    25,
     887,   904,   428,    25,   904,   428,   428,   428,   428,   428,
     428,   428,   752,   750,   463,   340,   803,   825,   826,   428,
     428,   659,   428,   987,  1275,  1162,   428,  1265,    93,    94,
     121,   122,   123,   491,   577,   620,  1302,  1303,  1304,  1307,
    1310,  1313,  1314,  1315,  1316,   655,   625,   139,   140,   467,
     655,  1525,  1152,   652,  1191,   655,     8,   660,   463,    25,
     987,  1427,   515,  1218,  1161,   147,   148,   149,   519,   890,
     891,   894,  1142,  1168,  1427,   723,   724,   873,   304,   124,
     125,   661,   496,     5,   654,   661,   653,   653,  1176,   631,
     457,     5,   592,  1025,   496,   694,  1532,   694,   421,   780,
    1142,   582,   653,  1181,  1182,  1183,   364,  1351,   647,   892,
     894,   592,   892,     8,   981,    26,   537,   590,   704,   974,
    1142,   974,   974,   974,    25,   215,   342,   348,   349,   350,
     368,   475,   478,   486,   521,   556,   575,   576,   586,   591,
     630,   662,  1066,  1067,   974,   974,   632,  1063,   724,  1063,
    1063,   975,   975,  1063,  1063,   724,     5,   371,   422,     5,
     723,   118,   119,   575,   662,  1054,   697,  1533,   893,   648,
     649,   650,   651,  1247,  1249,   420,  1284,  1249,  1241,     5,
     653,  1242,   894,   467,   467,   467,   467,    25,   753,   987,
     467,  1479,   382,   467,   557,   625,   614,   758,   765,   756,
     987,    25,  1128,  1142,  1235,     8,  1238,    14,   987,  1147,
    1155,  1156,  1158,  1166,  1167,  1211,   201,   382,   580,   613,
       5,     6,     7,     8,     9,    10,    12,    13,    14,    18,
      19,    20,    21,    22,    23,    33,    50,    99,   108,   126,
     128,   136,   143,   144,   147,   148,   149,   150,   153,   154,
     193,   215,   221,   228,   230,   236,   261,   299,   312,   318,
     327,   328,   334,   337,   338,   342,   348,   349,   355,   356,
     357,   358,   359,   360,   364,   368,   370,   377,   378,   379,
     380,   382,   383,   387,   388,   390,   391,   392,   393,   394,
     395,   396,   402,   403,   404,   406,   407,   411,   412,   413,
     414,   415,   416,   417,   418,   420,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   463,   464,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     505,   506,   507,   508,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     547,   548,   549,   550,   551,   552,   555,   556,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   673,   681,   686,
     690,   693,   694,   695,   696,   699,   700,   702,   703,   704,
    1497,  1498,  1499,  1501,   611,     5,   694,   694,   892,  1161,
    1168,  1050,   457,     5,   189,  1030,   467,  1142,   892,   467,
      26,    26,   102,  1140,    25,  1142,  1483,  1483,   988,  1335,
    1199,   981,   157,   259,   267,   273,   275,   286,   314,   330,
     335,   347,   354,   507,   514,   536,   541,  1323,  1324,  1332,
    1342,  1343,  1349,  1350,  1356,  1357,  1366,  1385,  1389,  1455,
    1456,  1486,  1487,  1490,  1491,  1503,   954,   955,   128,   950,
     961,   962,   953,  1135,  1545,  1093,   495,   853,   820,   655,
     987,   403,   490,   506,   549,   588,   617,   626,  1440,   927,
     625,    24,    26,   841,  1472,  1472,   403,   490,   506,   549,
     588,   617,   626,  1437,  1441,   507,  1471,   467,   467,   467,
     467,   467,   467,   467,   987,   467,     5,   582,  1394,  1399,
     987,    18,    19,    20,    21,   129,   130,   131,   132,   133,
     134,  1493,   457,     5,   428,   428,   917,   495,     5,   428,
     827,   797,  1110,   797,   196,   334,   410,   467,   512,   528,
    1372,  1384,   467,   987,  1318,    26,   283,   296,   467,   512,
     528,   987,  1299,  1312,  1370,  1371,  1376,  1378,  1380,   467,
     987,  1309,   467,  1299,  1305,     5,   987,   987,    25,   990,
    1145,  1525,  1523,   612,   652,  1192,    20,   987,  1172,  1526,
     987,  1541,  1427,   631,   655,   625,   467,   467,   873,     5,
     661,   467,  1523,    25,   992,  1216,  1216,  1479,  1126,   894,
     894,   894,   976,   977,   467,  1142,  1174,  1026,  1027,  1028,
    1427,   661,  1479,  1535,  1533,  1048,  1142,   779,   660,   894,
     388,  1185,   592,  1184,   987,     5,  1520,   105,   107,   109,
     653,   661,   865,  1161,   944,    18,    19,   467,  1064,  1066,
    1195,   975,   894,   382,   631,    26,    26,   723,   191,  1246,
     256,  1251,  1257,  1531,   987,    25,   937,  1535,   625,   979,
     658,  1142,   738,   987,   987,   894,   377,   761,   765,   614,
     759,   767,    23,   272,  1115,  1119,   518,   912,   518,  1236,
     894,   494,  1152,   655,     5,  1071,   582,  1212,  1142,  1500,
    1502,   227,  1498,  1016,   998,  1535,  1535,  1008,  1009,  1030,
    1030,    39,    41,    42,    43,   308,   311,   313,   333,   343,
     362,   385,   389,   466,  1029,  1031,  1032,  1058,  1142,  1163,
     582,   725,    26,   436,  1014,   359,  1478,  1478,   176,   177,
     473,   582,   987,  1386,  1387,  1429,   834,  1427,  1427,  1325,
     834,   987,  1488,  1488,  1467,  1427,  1333,   205,   475,   486,
     507,   514,  1359,  1360,  1361,  1545,  1545,   421,   963,  1142,
     677,   678,   956,   957,   958,   517,   660,   679,   680,   699,
     966,   967,  1545,   797,    26,   818,    20,   987,   428,   467,
      24,    26,   661,  1467,   428,   432,  1494,  1527,   396,   512,
     621,  1418,  1471,  1474,  1418,  1418,  1418,  1418,   655,  1474,
    1469,   551,  1395,  1396,  1397,  1427,   562,  1393,  1400,   369,
     550,   561,  1344,  1462,  1471,  1471,  1471,  1471,  1524,   887,
     428,   818,   826,  1276,   797,  1266,  1374,  1427,  1317,  1384,
     467,  1317,   467,   467,  1311,  1312,   467,   467,   100,   337,
     357,   394,   406,   417,   434,   444,   447,   460,   508,   538,
     548,   569,   573,   601,   610,  1419,  1420,  1421,  1423,  1308,
    1309,  1305,  1306,   699,  1303,   428,   655,  1479,   612,   495,
     582,  1539,   467,   718,   719,   987,   987,   987,  1293,   912,
     890,   987,  1291,   652,  1188,   661,     5,     5,     5,   615,
     894,     5,   655,   519,   661,   660,   202,   204,   308,   311,
     781,   784,   785,  1058,   782,   783,   987,   467,   988,   684,
     685,  1189,   894,  1427,  1521,  1522,   987,   987,   977,   978,
     545,  1535,   873,     8,   946,    26,    26,  1065,  1066,  1142,
     357,  1204,   102,   887,  1249,    26,  1142,  1545,     5,     5,
     428,   428,   754,   987,   428,  1479,   750,   467,   467,   766,
     762,   397,   760,   894,   377,   763,   767,   632,  1060,  1120,
    1116,   399,  1114,  1115,   892,   661,  1148,    20,   987,  1157,
    1167,    14,   519,  1213,  1214,  1471,  1527,  1142,  1164,  1165,
    1545,  1010,  1011,   586,   986,   582,  1041,  1040,  1043,  1042,
     979,  1044,   979,  1045,  1039,  1038,  1036,  1035,  1059,   362,
    1032,  1037,  1535,    45,    46,    47,    48,    49,    50,   135,
     370,   383,   446,   453,   492,   516,   526,   527,   532,   542,
     564,   567,   568,   572,   629,   640,   726,   727,  1056,  1057,
       5,    26,  1479,   286,  1142,   507,  1460,  1461,  1479,  1199,
    1454,  1456,   137,   137,   631,  1197,  1388,  1389,   467,  1367,
     188,  1400,  1427,   212,   309,  1492,   655,   661,  1457,  1504,
     379,   388,   412,   415,   432,   537,   590,   597,   981,  1336,
    1341,   467,  1362,   660,     5,   965,  1142,     5,   582,   959,
     960,   674,   958,   964,   987,   964,   968,   969,   964,   362,
     967,  1094,   463,    26,   403,   490,   506,   549,   588,   617,
     626,  1442,  1468,     5,  1441,   428,     5,  1471,     5,   428,
    1471,  1471,  1471,  1471,   987,   428,   467,  1397,     5,   987,
    1433,     9,   332,   467,   479,  1403,  1404,  1405,  1406,  1407,
    1411,  1415,  1417,  1471,   405,  1391,  1401,   987,  1463,   654,
    1418,   369,   463,   497,  1259,  1279,  1111,   497,  1222,  1253,
     467,     5,   428,  1403,   428,   647,   987,  1373,  1375,  1427,
    1431,  1432,  1377,  1431,     5,   428,  1377,  1403,   467,  1441,
    1441,   467,   467,   467,   467,   467,   245,   436,  1379,  1381,
       5,   428,     5,   428,   987,  1526,     8,  1479,  1153,   894,
     987,  1296,  1297,     5,  1298,  1299,   912,  1100,   655,  1298,
     612,  1479,  1479,   894,   894,   976,   545,   894,  1537,     5,
    1027,    20,  1431,  1479,   782,   790,   789,   791,   987,   991,
     792,   991,   229,   785,   788,     5,  1030,   655,   894,     8,
     655,     5,   987,   912,   589,  1339,     5,   428,  1142,     5,
     363,    25,  1281,   382,   382,   495,   655,   382,   467,   739,
     743,   736,  1545,  1545,   768,   764,   760,  1061,    25,   986,
    1121,  1142,  1545,   894,   462,   495,   912,     5,   457,     5,
    1017,  1012,  1013,    26,   723,   987,  1545,  1545,  1545,  1545,
       5,  1033,     5,  1034,  1545,  1545,  1545,  1545,  1064,  1545,
     986,    25,    14,    14,     5,   428,    26,  1427,  1467,  1448,
     631,   631,  1324,  1453,  1454,  1389,  1368,  1431,   652,   981,
     467,  1328,   987,  1489,  1488,  1468,    85,    86,    87,    88,
      89,   619,  1507,   894,   894,  1334,   981,  1363,  1431,  1427,
    1361,     5,  1142,   964,  1545,  1545,     5,   971,   972,  1545,
    1545,   970,  1087,   857,   428,   467,  1399,  1441,   661,  1441,
     428,  1471,   428,   428,   428,   428,  1396,  1398,  1396,  1406,
     467,  1466,  1403,  1471,  1466,     6,     7,     9,    10,    12,
      13,    14,    15,    16,    17,   290,   408,   409,   465,   592,
     658,   708,   709,  1414,  1416,  1392,  1470,  1471,   484,  1390,
    1402,   306,  1295,    26,  1345,  1346,  1347,  1431,  1460,  1463,
     815,   110,   111,   113,   114,   115,   214,   222,   256,   265,
     294,   295,   339,   381,   436,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,  1256,  1260,   175,   550,  1261,
    1277,  1087,   198,   213,   214,   222,   256,   265,   294,   339,
     381,  1254,  1255,  1267,  1261,  1375,  1384,   428,  1432,   495,
    1430,   428,     5,   655,     5,   428,  1312,   428,   428,    26,
    1424,   661,   467,   661,    26,  1425,  1425,    26,  1425,  1425,
      25,  1434,  1382,  1383,  1384,  1309,  1305,  1479,     8,   463,
     574,   623,     5,   428,   719,     5,   428,   892,   428,    20,
     428,  1479,     5,   894,   602,   312,   728,   729,   894,  1030,
    1545,  1545,     5,   786,   495,   655,     5,   787,  1545,   783,
     582,    20,   987,     5,   987,  1179,    20,  1431,  1522,   426,
     694,   892,  1340,   945,  1066,   703,  1202,   887,     5,   750,
    1142,   735,   717,   987,  1142,   741,   428,   750,   750,  1545,
    1545,  1064,  1118,    25,  1122,  1142,   607,   941,  1153,   519,
     893,  1072,  1214,  1142,  1165,    99,   578,  1018,  1004,  1005,
     655,   979,  1545,   979,  1545,   723,    26,  1142,    26,  1142,
     727,   428,   467,  1480,  1468,  1454,  1454,  1446,     5,   428,
     507,  1465,  1329,  1431,   515,  1326,  1465,   661,  1458,    18,
      19,   101,   464,   467,   480,   519,   520,   532,   573,   612,
     624,   636,   637,   644,   647,   987,  1434,  1466,  1512,  1513,
    1514,  1515,  1516,  1517,  1527,  1512,  1512,  1512,  1431,  1509,
    1511,  1508,  1509,  1510,  1505,   589,  1337,     5,   428,   661,
    1142,   987,  1545,  1545,  1545,  1545,   659,    26,   428,   661,
    1442,   661,     5,   428,   428,  1404,  1405,  1409,  1472,  1409,
     467,  1466,  1409,   467,  1466,  1409,    10,   287,   423,   425,
    1471,     5,  1403,     5,   574,   623,  1348,  1295,   659,  1257,
    1257,  1257,    25,  1257,  1257,  1257,  1257,  1257,  1257,    25,
      25,  1257,  1260,  1142,  1169,  1170,   654,   483,  1223,  1545,
      25,    25,    26,    26,    26,    26,    26,    25,  1142,  1255,
    1223,   428,    26,  1372,  1431,    20,   987,  1431,   428,  1442,
      26,  1442,     5,  1422,  1422,     5,   428,   428,  1422,  1384,
    1479,  1297,  1299,  1295,   504,   872,     5,   411,  1479,     5,
     467,   428,   586,  1055,   991,  1545,   720,    20,   987,   991,
    1545,  1535,   894,  1535,  1164,  1545,    26,   986,    25,  1282,
    1161,   463,   750,   740,   744,   428,  1545,   986,   894,   939,
     463,  1020,  1019,   477,  1006,  1007,    20,   987,  1481,  1482,
     589,  1464,  1449,  1447,  1431,  1467,   180,  1369,     5,   428,
    1327,  1489,  1464,  1515,  1515,  1514,   467,   467,   467,   467,
     467,   467,   467,   987,   467,     5,   428,    18,    19,    20,
      21,  1493,   428,     5,   428,     5,    14,   188,   562,  1506,
    1338,  1431,   499,  1364,  1365,  1429,   248,  1095,   853,   428,
    1442,  1442,  1396,   478,  1408,  1408,  1412,  1413,  1434,  1527,
    1408,  1412,  1408,  1409,  1471,  1470,  1346,   827,   574,   623,
    1171,     5,  1169,    98,   174,   237,   239,   254,   262,   266,
     291,  1224,  1225,  1278,  1095,  1268,     5,   463,  1430,   428,
      26,  1426,   428,   428,    26,   428,   979,   723,   411,  1479,
     894,   730,   604,  1177,    26,   723,   463,  1055,   428,   278,
     723,   428,   428,   467,   742,   382,   748,   428,   737,  1117,
    1545,   495,   894,  1545,   986,     5,   428,  1164,  1399,  1468,
    1431,   467,  1399,   428,  1494,  1418,  1514,  1518,  1418,  1418,
    1418,  1418,   655,  1518,  1513,  1514,  1514,  1514,  1514,  1509,
      14,  1510,  1513,   981,  1403,  1164,     5,   181,  1358,  1410,
    1434,  1475,     5,   428,   428,  1408,     7,  1170,  1226,  1227,
    1142,  1229,  1142,  1228,  1230,  1225,   277,   277,    26,   661,
     428,   871,  1479,   429,   241,   297,   322,   331,   367,   375,
     468,   638,   727,   731,   732,   467,   655,   723,  1201,  1283,
     745,   428,  1161,   748,   748,  1545,   940,  1153,   611,  1052,
    1482,  1462,  1399,   519,  1330,  1331,  1471,  1462,   428,  1514,
       5,   428,  1514,  1514,  1514,  1514,   987,   428,   467,  1365,
    1413,  1471,  1545,  1545,  1231,  1545,  1232,  1545,  1545,   463,
    1442,   276,   385,   389,   874,   875,   876,  1058,   974,   974,
     974,   974,   974,   974,    25,     5,   428,   894,    20,   987,
    1058,  1205,  1206,  1207,   748,   750,   748,   279,   463,  1021,
     723,     5,   428,   325,   326,  1450,   428,  1514,   428,   428,
     428,   428,  1512,  1545,  1545,   878,   877,   276,   876,   879,
     732,     5,  1208,   320,  1207,   746,  1545,  1331,    25,   987,
    1451,  1452,   428,  1545,  1545,  1545,   894,  1545,   428,  1018,
     655,   655,     5,   428,   747,   987,   987,  1452,   201,   382,
     749,   655,  1161,   987
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
#line 979 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 982 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 986 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 992 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 997 "fgl.yacc"
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
#line 1009 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1014 "fgl.yacc"
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
#line 1037 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1038 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1039 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1040 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1041 "fgl.yacc"
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
#line 1052 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1058 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1059 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1060 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1061 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1062 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1067 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1068 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1079 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1085 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1092 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1093 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1099 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1100 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1101 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1102 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1103 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1104 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1105 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1106 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1107 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1108 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1109 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1110 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1111 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1112 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1113 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1114 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1115 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1122 "fgl.yacc"
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
#line 1133 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1137 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1138 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1142 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1148 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1150 "fgl.yacc"
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
#line 1161 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1163 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1165 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1167 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1171 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1173 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1234 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1238 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1242 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1249 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1252 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1256 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1260 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1267 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1273 "fgl.yacc"
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
#line 1282 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 74:
#line 1286 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1291 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1295 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1303 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 78:
#line 1307 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1311 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1313 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1319 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1324 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1327 "fgl.yacc"
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
#line 1343 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1350 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1354 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1358 "fgl.yacc"
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
#line 1380 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1380 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1384 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1385 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1386 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1391 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1394 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1400 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1403 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1415 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1421 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1424 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1439 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1449 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1455 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1464 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1477 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1480 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1482 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1488 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1490 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1495 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1500 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1506 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1510 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1525 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1528 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1531 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1534 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1537 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1540 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1562 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1571 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1581 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1595 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1600 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1603 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1612 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1618 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1633 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1637 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1642 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1652 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1652 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1653 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1653 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1654 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1654 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1655 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1655 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1656 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1656 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1664 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1668 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1674 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1678 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1693 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1696 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1699 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1702 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1705 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1708 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1717 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1725 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1730 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1743 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1747 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1762 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1763 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1771 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1771 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1780 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1780 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1789 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1790 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1791 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1794 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1799 "fgl.yacc"
    { }
    break;

  case 194:
#line 1799 "fgl.yacc"
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
#line 1816 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1820 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1835 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1836 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1837 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1838 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1843 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1849 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1858 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1862 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1878 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1880 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1881 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1888 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1888 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1889 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1890 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1893 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1895 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1905 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1920 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1920 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1926 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1927 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 242:
#line 1934 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 243:
#line 1935 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 244:
#line 1936 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 245:
#line 1937 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 246:
#line 1940 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 247:
#line 1941 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 248:
#line 1942 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1943 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 250:
#line 1947 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 251:
#line 1952 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1957 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 253:
#line 1961 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1964 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1968 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 256:
#line 1969 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 257:
#line 1970 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 258:
#line 1971 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 259:
#line 1972 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1973 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 261:
#line 1974 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1975 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 263:
#line 1978 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 264:
#line 1979 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 265:
#line 1980 "fgl.yacc"
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
#line 2012 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 267:
#line 2016 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 2018 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2020 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 270:
#line 2022 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 271:
#line 2027 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 272:
#line 2031 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 273:
#line 2031 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 274:
#line 2035 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 275:
#line 2036 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 276:
#line 2037 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 277:
#line 2038 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 278:
#line 2039 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 279:
#line 2040 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 280:
#line 2042 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 281:
#line 2047 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 282:
#line 2047 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 283:
#line 2050 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 284:
#line 2052 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 285:
#line 2058 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2060 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 287:
#line 2066 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 288:
#line 2074 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 289:
#line 2074 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 290:
#line 2077 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 291:
#line 2078 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 292:
#line 2079 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 293:
#line 2080 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 294:
#line 2081 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 295:
#line 2082 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 296:
#line 2084 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 300:
#line 2105 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 304:
#line 2114 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 305:
#line 2116 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 306:
#line 2118 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2120 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 308:
#line 2121 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 309:
#line 2122 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 310:
#line 2123 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 311:
#line 2124 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 312:
#line 2129 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2136 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2141 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 315:
#line 2143 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2145 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2146 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 318:
#line 2147 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 319:
#line 2148 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 320:
#line 2149 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 321:
#line 2150 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 322:
#line 2151 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 323:
#line 2154 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 324:
#line 2156 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 325:
#line 2162 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 326:
#line 2170 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 328:
#line 2178 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2182 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 330:
#line 2190 "fgl.yacc"
    {dim_push_record();}
    break;

  case 331:
#line 2191 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 332:
#line 2192 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 333:
#line 2193 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 339:
#line 2212 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 340:
#line 2224 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 341:
#line 2228 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 342:
#line 2231 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 343:
#line 2234 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 344:
#line 2235 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 345:
#line 2236 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 346:
#line 2237 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 347:
#line 2238 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 348:
#line 2244 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 349:
#line 2251 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 350:
#line 2256 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 351:
#line 2261 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 352:
#line 2266 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 353:
#line 2270 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 354:
#line 2279 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 355:
#line 2281 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 356:
#line 2286 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 362:
#line 2298 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 363:
#line 2302 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 364:
#line 2305 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 365:
#line 2309 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 366:
#line 2312 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 367:
#line 2316 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 368:
#line 2323 "fgl.yacc"
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
#line 2341 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 370:
#line 2347 "fgl.yacc"
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
#line 2371 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 372:
#line 2374 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 373:
#line 2389 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 374:
#line 2391 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 375:
#line 2393 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 376:
#line 2395 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 377:
#line 2397 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 378:
#line 2399 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 379:
#line 2400 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 380:
#line 2407 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 381:
#line 2409 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 382:
#line 2413 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 383:
#line 2415 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 384:
#line 2417 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 385:
#line 2419 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 386:
#line 2421 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 387:
#line 2423 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 388:
#line 2425 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 389:
#line 2431 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 390:
#line 2445 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 391:
#line 2448 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 396:
#line 2465 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 399:
#line 2471 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 400:
#line 2475 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 401:
#line 2480 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 405:
#line 2490 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 406:
#line 2491 "fgl.yacc"
    {inc_counter();}
    break;

  case 412:
#line 2497 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 413:
#line 2504 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 414:
#line 2504 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 416:
#line 2509 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 417:
#line 2513 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 418:
#line 2519 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2527 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2533 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2542 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 422:
#line 2544 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 423:
#line 2551 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 424:
#line 2559 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 425:
#line 2563 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 426:
#line 2572 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 427:
#line 2577 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 428:
#line 2582 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 429:
#line 2586 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 430:
#line 2588 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 431:
#line 2591 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 432:
#line 2598 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 433:
#line 2606 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 434:
#line 2618 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2624 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2630 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 439:
#line 2640 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 440:
#line 2646 "fgl.yacc"
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
#line 2718 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 442:
#line 2724 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2728 "fgl.yacc"
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
#line 2736 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 445:
#line 2736 "fgl.yacc"
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
#line 2752 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 447:
#line 2756 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 448:
#line 2762 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 449:
#line 2765 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 450:
#line 2773 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 451:
#line 2777 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 452:
#line 2780 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 453:
#line 2786 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 454:
#line 2796 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 455:
#line 2801 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2808 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 457:
#line 2811 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 458:
#line 2814 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 459:
#line 2819 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 460:
#line 2826 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 461:
#line 2831 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2836 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 463:
#line 2841 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2852 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 465:
#line 2860 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 466:
#line 2868 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 467:
#line 2873 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 468:
#line 2877 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 469:
#line 2882 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 470:
#line 2886 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 471:
#line 2890 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 472:
#line 2896 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 473:
#line 2899 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2903 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 475:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 476:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 477:
#line 2915 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 478:
#line 2919 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 479:
#line 2926 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 480:
#line 2936 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 481:
#line 2941 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 482:
#line 2947 "fgl.yacc"
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
#line 2957 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 484:
#line 2962 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 485:
#line 2965 "fgl.yacc"
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
#line 2979 "fgl.yacc"
    {chk4var=1;}
    break;

  case 487:
#line 2979 "fgl.yacc"
    {chk4var=0;}
    break;

  case 488:
#line 2979 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 489:
#line 2982 "fgl.yacc"
    {chk4var=1;}
    break;

  case 490:
#line 2982 "fgl.yacc"
    {chk4var=0;}
    break;

  case 491:
#line 2982 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 492:
#line 2986 "fgl.yacc"
    {chk4var=1;}
    break;

  case 493:
#line 2986 "fgl.yacc"
    {chk4var=0;}
    break;

  case 494:
#line 2986 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 495:
#line 2990 "fgl.yacc"
    {chk4var=1;}
    break;

  case 496:
#line 2990 "fgl.yacc"
    {chk4var=0;}
    break;

  case 497:
#line 2990 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 498:
#line 2994 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3000 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3006 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3012 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3018 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 503:
#line 3024 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3034 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 505:
#line 3035 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 508:
#line 3043 "fgl.yacc"
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

  case 509:
#line 3054 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 510:
#line 3055 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 511:
#line 3061 "fgl.yacc"
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

  case 512:
#line 3072 "fgl.yacc"
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

  case 513:
#line 3082 "fgl.yacc"
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

  case 516:
#line 3095 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 517:
#line 3100 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 518:
#line 3107 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 519:
#line 3111 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 520:
#line 3114 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 521:
#line 3117 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 522:
#line 3123 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 523:
#line 3126 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 524:
#line 3129 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3146 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 526:
#line 3149 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 527:
#line 3155 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 528:
#line 3156 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 529:
#line 3157 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 531:
#line 3162 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 532:
#line 3163 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 533:
#line 3164 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3165 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3167 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3168 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3169 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3171 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3172 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 541:
#line 3178 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 542:
#line 3182 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 543:
#line 3186 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 544:
#line 3198 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 545:
#line 3202 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 546:
#line 3203 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 547:
#line 3210 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 549:
#line 3227 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 550:
#line 3231 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 551:
#line 3237 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 552:
#line 3241 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 553:
#line 3250 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 554:
#line 3251 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 555:
#line 3263 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 556:
#line 3269 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 557:
#line 3277 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 564:
#line 3294 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 565:
#line 3296 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3299 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 567:
#line 3301 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3315 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 573:
#line 3317 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3320 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 575:
#line 3322 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 588:
#line 3353 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 589:
#line 3355 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 590:
#line 3358 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 591:
#line 3360 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 592:
#line 3363 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 593:
#line 3365 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 594:
#line 3368 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 595:
#line 3370 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 596:
#line 3373 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 597:
#line 3375 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 598:
#line 3390 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 599:
#line 3406 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 600:
#line 3407 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 601:
#line 3408 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 602:
#line 3409 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 603:
#line 3410 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 604:
#line 3411 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 605:
#line 3412 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 609:
#line 3420 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 611:
#line 3426 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 612:
#line 3429 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 613:
#line 3434 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 614:
#line 3439 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 615:
#line 3442 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 616:
#line 3447 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 617:
#line 3452 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 618:
#line 3457 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 619:
#line 3464 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 620:
#line 3471 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 621:
#line 3473 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 622:
#line 3479 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3484 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 624:
#line 3489 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 625:
#line 3494 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 626:
#line 3494 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 627:
#line 3497 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 628:
#line 3503 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 629:
#line 3508 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 630:
#line 3512 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 633:
#line 3520 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",0); 
				}
    break;

  case 634:
#line 3523 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,0); 
				}
    break;

  case 635:
#line 3526 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 636:
#line 3531 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 637:
#line 3536 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 638:
#line 3541 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 639:
#line 3548 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 641:
#line 3557 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 642:
#line 3619 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 644:
#line 3628 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 645:
#line 3637 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 647:
#line 3644 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 648:
#line 3647 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 649:
#line 3653 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 650:
#line 3659 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 651:
#line 3663 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 652:
#line 3667 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 653:
#line 3673 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 654:
#line 3677 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 655:
#line 3681 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 656:
#line 3686 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 657:
#line 3691 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 676:
#line 3732 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 677:
#line 3739 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 678:
#line 3741 "fgl.yacc"
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
#line 3760 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 682:
#line 3763 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 683:
#line 3765 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 684:
#line 3768 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 685:
#line 3772 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 686:
#line 3775 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 687:
#line 3781 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 688:
#line 3792 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 689:
#line 3793 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 690:
#line 3796 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 692:
#line 3802 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 693:
#line 3806 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 694:
#line 3807 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 695:
#line 3811 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 699:
#line 3826 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 700:
#line 3828 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 703:
#line 3837 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 704:
#line 3840 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 705:
#line 3844 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 706:
#line 3847 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 707:
#line 3850 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 708:
#line 3853 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 709:
#line 3856 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 710:
#line 3860 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 711:
#line 3863 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 712:
#line 3866 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 713:
#line 3869 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 714:
#line 3872 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 715:
#line 3875 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 716:
#line 3878 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 717:
#line 3881 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 718:
#line 3884 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 719:
#line 3885 "fgl.yacc"
    {
		A4GL_add_event(-14,"");
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 720:
#line 3888 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 721:
#line 3889 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 722:
#line 3892 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 723:
#line 3893 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 724:
#line 3896 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 725:
#line 3904 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 726:
#line 3908 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 727:
#line 3914 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 728:
#line 3918 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 729:
#line 3923 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 730:
#line 3928 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 731:
#line 3933 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 732:
#line 3934 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 733:
#line 3935 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 734:
#line 3939 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 735:
#line 3943 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 736:
#line 3952 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 737:
#line 3957 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 738:
#line 3961 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 739:
#line 3968 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 740:
#line 3977 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 741:
#line 3983 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 742:
#line 3984 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 743:
#line 3985 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 744:
#line 3986 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 745:
#line 3989 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 747:
#line 3992 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 748:
#line 3999 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 749:
#line 4000 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 750:
#line 4001 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 751:
#line 4002 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 752:
#line 4003 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 753:
#line 4004 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 754:
#line 4005 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 755:
#line 4006 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 756:
#line 4007 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 757:
#line 4012 "fgl.yacc"
    {iskey=1;}
    break;

  case 758:
#line 4012 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 759:
#line 4014 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 760:
#line 4017 "fgl.yacc"
    {iskey=1;}
    break;

  case 761:
#line 4017 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 762:
#line 4019 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 763:
#line 4023 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 764:
#line 4026 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 765:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 767:
#line 4030 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 773:
#line 4042 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 774:
#line 4043 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 775:
#line 4044 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 776:
#line 4045 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 777:
#line 4046 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 778:
#line 4047 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 779:
#line 4048 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 780:
#line 4049 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 781:
#line 4050 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 782:
#line 4051 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 783:
#line 4052 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 784:
#line 4053 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 785:
#line 4054 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 786:
#line 4055 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 787:
#line 4059 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 788:
#line 4077 "fgl.yacc"
    {chk4var=1;}
    break;

  case 789:
#line 4077 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 790:
#line 4080 "fgl.yacc"
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

  case 791:
#line 4104 "fgl.yacc"
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

  case 793:
#line 4122 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 794:
#line 4128 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 795:
#line 4134 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 796:
#line 4140 "fgl.yacc"
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

  case 797:
#line 4151 "fgl.yacc"
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

  case 798:
#line 4174 "fgl.yacc"
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

  case 801:
#line 4190 "fgl.yacc"
    {
	}
    break;

  case 810:
#line 4215 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 814:
#line 4223 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 830:
#line 4249 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 831:
#line 4250 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 832:
#line 4258 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 833:
#line 4263 "fgl.yacc"
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

  case 834:
#line 4279 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 835:
#line 4285 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 837:
#line 4300 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 838:
#line 4313 "fgl.yacc"
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

  case 839:
#line 4323 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 840:
#line 4330 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 841:
#line 4337 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 842:
#line 4343 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 843:
#line 4343 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 844:
#line 4348 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 845:
#line 4354 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 846:
#line 4362 "fgl.yacc"
    {
}
    break;

  case 850:
#line 4374 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 852:
#line 4382 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 853:
#line 4388 "fgl.yacc"
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

  case 856:
#line 4404 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 857:
#line 4408 "fgl.yacc"
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

  case 858:
#line 4421 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 860:
#line 4439 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 861:
#line 4447 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 862:
#line 4453 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 863:
#line 4464 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 864:
#line 4468 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 865:
#line 4475 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 866:
#line 4482 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 867:
#line 4488 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 868:
#line 4493 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 871:
#line 4500 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 872:
#line 4501 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 873:
#line 4503 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 874:
#line 4504 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 875:
#line 4507 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 876:
#line 4508 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 877:
#line 4509 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 878:
#line 4511 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 879:
#line 4516 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 880:
#line 4521 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 881:
#line 4528 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 885:
#line 4535 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 886:
#line 4537 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 887:
#line 4539 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 888:
#line 4547 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 889:
#line 4553 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 890:
#line 4557 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 893:
#line 4569 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 894:
#line 4572 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 895:
#line 4576 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 896:
#line 4579 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 898:
#line 4588 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 899:
#line 4591 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 900:
#line 4594 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 907:
#line 4610 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 908:
#line 4615 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 909:
#line 4615 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 910:
#line 4618 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 911:
#line 4645 "fgl.yacc"
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

  case 913:
#line 4702 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 915:
#line 4709 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 916:
#line 4713 "fgl.yacc"
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

  case 917:
#line 4756 "fgl.yacc"
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

  case 921:
#line 4804 "fgl.yacc"
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

  case 922:
#line 4818 "fgl.yacc"
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

  case 927:
#line 4842 "fgl.yacc"
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

  case 928:
#line 4902 "fgl.yacc"
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

  case 929:
#line 4958 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 930:
#line 4963 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 931:
#line 4971 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 932:
#line 4976 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 933:
#line 4984 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 934:
#line 4990 "fgl.yacc"
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

  case 935:
#line 5022 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 936:
#line 5025 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 937:
#line 5027 "fgl.yacc"
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

  case 938:
#line 5068 "fgl.yacc"
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

  case 943:
#line 5121 "fgl.yacc"
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

  case 944:
#line 5173 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 946:
#line 5180 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 947:
#line 5186 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 948:
#line 5197 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 949:
#line 5204 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 951:
#line 5212 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 952:
#line 5215 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 953:
#line 5216 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 955:
#line 5218 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 956:
#line 5219 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 957:
#line 5222 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 958:
#line 5225 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 959:
#line 5231 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 960:
#line 5234 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 961:
#line 5238 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 962:
#line 5243 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 963:
#line 5251 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 964:
#line 5256 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 965:
#line 5263 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 966:
#line 5266 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 971:
#line 5279 "fgl.yacc"
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

  case 972:
#line 5298 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 973:
#line 5305 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 974:
#line 5312 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 975:
#line 5315 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 976:
#line 5329 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 981:
#line 5346 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 982:
#line 5351 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 983:
#line 5357 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 985:
#line 5364 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 986:
#line 5369 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 987:
#line 5372 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 988:
#line 5373 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 989:
#line 5376 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 990:
#line 5377 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 991:
#line 5380 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 992:
#line 5381 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 993:
#line 5386 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 994:
#line 5393 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 995:
#line 5396 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 996:
#line 5402 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 997:
#line 5404 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 998:
#line 5406 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 999:
#line 5408 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1000:
#line 5411 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1001:
#line 5411 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1002:
#line 5412 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1003:
#line 5417 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1004:
#line 5425 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1005:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1006:
#line 5431 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1007:
#line 5433 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5435 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1012:
#line 5452 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1013:
#line 5455 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1014:
#line 5458 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1015:
#line 5461 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1016:
#line 5465 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1017:
#line 5468 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1018:
#line 5471 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1019:
#line 5475 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1020:
#line 5479 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1021:
#line 5483 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1022:
#line 5486 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1023:
#line 5490 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1024:
#line 5493 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1025:
#line 5494 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1026:
#line 5495 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1027:
#line 5498 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1028:
#line 5501 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1029:
#line 5504 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1030:
#line 5507 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1031:
#line 5510 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1032:
#line 5513 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1033:
#line 5516 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1034:
#line 5533 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1037:
#line 5543 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1038:
#line 5549 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1039:
#line 5553 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1041:
#line 5573 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1042:
#line 5578 "fgl.yacc"
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

  case 1043:
#line 5591 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1044:
#line 5592 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1045:
#line 5596 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1046:
#line 5601 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1047:
#line 5602 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1048:
#line 5606 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1052:
#line 5612 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1053:
#line 5615 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1055:
#line 5630 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1056:
#line 5634 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1057:
#line 5640 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1058:
#line 5641 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1059:
#line 5646 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1060:
#line 5647 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1061:
#line 5650 "fgl.yacc"
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

  case 1063:
#line 5678 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1064:
#line 5683 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1065:
#line 5688 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1066:
#line 5693 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1072:
#line 5715 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1073:
#line 5722 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1074:
#line 5731 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1075:
#line 5737 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1076:
#line 5739 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1080:
#line 5750 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1081:
#line 5751 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1082:
#line 5757 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1083:
#line 5761 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1084:
#line 5767 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1085:
#line 5768 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1086:
#line 5773 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1087:
#line 5774 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5776 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1089:
#line 5777 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1090:
#line 5778 "fgl.yacc"
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

  case 1091:
#line 5792 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1092:
#line 5794 "fgl.yacc"
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

  case 1093:
#line 5811 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1100:
#line 5823 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1101:
#line 5823 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1102:
#line 5829 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1103:
#line 5829 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1104:
#line 5832 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1105:
#line 5832 "fgl.yacc"
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

  case 1106:
#line 5848 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1107:
#line 5849 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1108:
#line 5850 "fgl.yacc"
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

  case 1109:
#line 5859 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1110:
#line 5871 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1116:
#line 5882 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1117:
#line 5887 "fgl.yacc"
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

  case 1118:
#line 5907 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1119:
#line 5912 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1120:
#line 5918 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1121:
#line 5919 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1122:
#line 5920 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1123:
#line 5924 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1124:
#line 5925 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1125:
#line 5926 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1126:
#line 5927 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1127:
#line 5931 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1128:
#line 5941 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1129:
#line 5943 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1130:
#line 5948 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1131:
#line 5951 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1132:
#line 5956 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1133:
#line 5963 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1134:
#line 5970 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1135:
#line 5977 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1136:
#line 5986 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1137:
#line 5993 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1138:
#line 6000 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1139:
#line 6007 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1140:
#line 6014 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1145:
#line 6027 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1146:
#line 6028 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1147:
#line 6029 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1148:
#line 6030 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1149:
#line 6031 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1150:
#line 6032 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1151:
#line 6033 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1152:
#line 6034 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1153:
#line 6035 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1154:
#line 6036 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1157:
#line 6042 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1158:
#line 6043 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1159:
#line 6044 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1160:
#line 6045 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1165:
#line 6054 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1166:
#line 6055 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6056 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1168:
#line 6057 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1169:
#line 6058 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1170:
#line 6059 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1171:
#line 6060 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1172:
#line 6061 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1173:
#line 6063 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1174:
#line 6064 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1175:
#line 6065 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1176:
#line 6066 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1177:
#line 6068 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1178:
#line 6069 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1179:
#line 6070 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1180:
#line 6071 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1184:
#line 6076 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1185:
#line 6077 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1189:
#line 6084 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1190:
#line 6092 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1191:
#line 6100 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1192:
#line 6112 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1193:
#line 6121 "fgl.yacc"
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

  case 1194:
#line 6132 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1195:
#line 6136 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1196:
#line 6140 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1197:
#line 6146 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1198:
#line 6151 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1199:
#line 6159 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1200:
#line 6162 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1201:
#line 6171 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1202:
#line 6182 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1204:
#line 6189 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1205:
#line 6197 "fgl.yacc"
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

  case 1206:
#line 6207 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1207:
#line 6210 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1208:
#line 6214 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1209:
#line 6222 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1210:
#line 6225 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1211:
#line 6231 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1212:
#line 6235 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1213:
#line 6239 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1214:
#line 6243 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1215:
#line 6247 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1216:
#line 6253 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1217:
#line 6254 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1218:
#line 6255 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1219:
#line 6256 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1220:
#line 6261 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1221:
#line 6263 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1222:
#line 6266 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1223:
#line 6270 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1224:
#line 6273 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1225:
#line 6280 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1226:
#line 6285 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1227:
#line 6286 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1228:
#line 6287 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1229:
#line 6292 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1230:
#line 6293 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1231:
#line 6299 "fgl.yacc"
    {insql=1;}
    break;

  case 1232:
#line 6299 "fgl.yacc"
    {insql=0;}
    break;

  case 1233:
#line 6299 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1234:
#line 6304 "fgl.yacc"
    {insql=1;}
    break;

  case 1235:
#line 6304 "fgl.yacc"
    {insql=0;}
    break;

  case 1236:
#line 6304 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1237:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s ",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1238:
#line 6316 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1239:
#line 6322 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1240:
#line 6324 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1242:
#line 6337 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1243:
#line 6341 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1244:
#line 6342 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1246:
#line 6347 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1247:
#line 6350 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1248:
#line 6356 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1249:
#line 6359 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 6367 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1252:
#line 6374 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1253:
#line 6378 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1254:
#line 6382 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1255:
#line 6388 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1256:
#line 6391 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1257:
#line 6400 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1258:
#line 6403 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1259:
#line 6406 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1260:
#line 6409 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1261:
#line 6412 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1262:
#line 6415 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1263:
#line 6418 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1264:
#line 6425 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1265:
#line 6428 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1266:
#line 6435 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1267:
#line 6438 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1268:
#line 6444 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1269:
#line 6447 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1270:
#line 6454 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1271:
#line 6457 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1273:
#line 6465 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1275:
#line 6474 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1276:
#line 6477 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1277:
#line 6483 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1278:
#line 6486 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1279:
#line 6492 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1280:
#line 6499 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1281:
#line 6500 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1282:
#line 6504 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1283:
#line 6510 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1284:
#line 6513 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1286:
#line 6521 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1287:
#line 6528 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1288:
#line 6531 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1292:
#line 6549 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1298:
#line 6555 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1299:
#line 6558 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1300:
#line 6561 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1301:
#line 6567 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1303:
#line 6573 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1305:
#line 6584 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1306:
#line 6598 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1307:
#line 6607 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1308:
#line 6607 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1309:
#line 6612 "fgl.yacc"
    {insql=1;}
    break;

  case 1310:
#line 6612 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1311:
#line 6617 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1312:
#line 6620 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1313:
#line 6622 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1315:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1316:
#line 6633 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1317:
#line 6637 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1318:
#line 6644 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1319:
#line 6647 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1320:
#line 6654 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1321:
#line 6658 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1322:
#line 6662 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1323:
#line 6667 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1324:
#line 6672 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1325:
#line 6676 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1326:
#line 6682 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1327:
#line 6686 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1328:
#line 6692 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1329:
#line 6699 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1330:
#line 6703 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1331:
#line 6708 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1332:
#line 6718 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1333:
#line 6721 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1334:
#line 6723 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1335:
#line 6725 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1336:
#line 6727 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1337:
#line 6729 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1338:
#line 6731 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1339:
#line 6733 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1340:
#line 6739 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1341:
#line 6749 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1342:
#line 6756 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1345:
#line 6765 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6772 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1351:
#line 6777 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1352:
#line 6782 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1353:
#line 6789 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1354:
#line 6790 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1355:
#line 6797 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1356:
#line 6808 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1357:
#line 6809 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6810 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1359:
#line 6813 "fgl.yacc"
    {insql=1;}
    break;

  case 1360:
#line 6813 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1361:
#line 6818 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1362:
#line 6823 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1364:
#line 6829 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1366:
#line 6833 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1367:
#line 6838 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1368:
#line 6843 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1369:
#line 6847 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1371:
#line 6853 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1372:
#line 6857 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1373:
#line 6865 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6868 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1375:
#line 6870 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1376:
#line 6875 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1379:
#line 6882 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6889 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6892 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1385:
#line 6894 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6900 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6906 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6916 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1393:
#line 6921 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1394:
#line 6923 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6929 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6932 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1399:
#line 6938 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1400:
#line 6946 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6961 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6973 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6986 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1412:
#line 6989 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1413:
#line 6992 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1414:
#line 7000 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1416:
#line 7015 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1417:
#line 7020 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1419:
#line 7024 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1420:
#line 7026 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1421:
#line 7033 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1422:
#line 7036 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1423:
#line 7042 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1424:
#line 7046 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1425:
#line 7050 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1426:
#line 7054 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1427:
#line 7057 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1428:
#line 7065 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1429:
#line 7072 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1432:
#line 7081 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 7087 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 7090 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1435:
#line 7101 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 7108 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1437:
#line 7114 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 7117 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1439:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1440:
#line 7131 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1442:
#line 7138 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1443:
#line 7144 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1444:
#line 7145 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7146 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1447:
#line 7150 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1449:
#line 7155 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1450:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1451:
#line 7167 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1452:
#line 7168 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1453:
#line 7171 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1454:
#line 7174 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1455:
#line 7179 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1456:
#line 7180 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1457:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 7188 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7194 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1460:
#line 7197 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1461:
#line 7203 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1462:
#line 7206 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1463:
#line 7212 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1464:
#line 7215 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1465:
#line 7222 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1466:
#line 7223 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1467:
#line 7252 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1468:
#line 7254 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7258 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1471:
#line 7271 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1472:
#line 7274 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1473:
#line 7277 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1474:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1476:
#line 7288 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7291 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1479:
#line 7297 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1481:
#line 7303 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1482:
#line 7306 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1483:
#line 7309 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1484:
#line 7312 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1485:
#line 7315 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1486:
#line 7318 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1487:
#line 7321 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1488:
#line 7324 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1489:
#line 7329 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1491:
#line 7336 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1497:
#line 7344 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1498:
#line 7345 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1499:
#line 7350 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1500:
#line 7353 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1501:
#line 7357 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1502:
#line 7363 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1503:
#line 7364 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1504:
#line 7365 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1505:
#line 7366 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1510:
#line 7386 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7391 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7392 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1514:
#line 7395 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7400 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1520:
#line 7403 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7406 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1526:
#line 7411 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1527:
#line 7413 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1529:
#line 7417 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1530:
#line 7424 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1534:
#line 7429 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1538:
#line 7445 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1539:
#line 7452 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1540:
#line 7456 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1541:
#line 7457 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1542:
#line 7461 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1543:
#line 7468 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1544:
#line 7472 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1545:
#line 7473 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1547:
#line 7491 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1548:
#line 7492 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1549:
#line 7493 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1550:
#line 7497 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1551:
#line 7500 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1552:
#line 7506 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1553:
#line 7511 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1554:
#line 7516 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1556:
#line 7527 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1561:
#line 7542 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1562:
#line 7545 "fgl.yacc"
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

  case 1563:
#line 7558 "fgl.yacc"
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

  case 1564:
#line 7573 "fgl.yacc"
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

  case 1565:
#line 7585 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1566:
#line 7587 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1567:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1568:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1569:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1570:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1571:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1572:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1573:
#line 7591 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1574:
#line 7594 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1575:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1576:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1577:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1578:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1579:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1580:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1581:
#line 7601 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1582:
#line 7604 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1597:
#line 7611 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1598:
#line 7614 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1599:
#line 7615 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1600:
#line 7616 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1601:
#line 7620 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1602:
#line 7628 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1603:
#line 7628 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1604:
#line 7634 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1605:
#line 7634 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1606:
#line 7641 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1607:
#line 7641 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1608:
#line 7647 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1609:
#line 7647 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1610:
#line 7655 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1611:
#line 7656 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1612:
#line 7657 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1613:
#line 7660 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1614:
#line 7660 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1616:
#line 7664 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1617:
#line 7665 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1618:
#line 7676 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7679 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1620:
#line 7685 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1621:
#line 7690 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1622:
#line 7698 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1623:
#line 7710 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1624:
#line 7711 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1625:
#line 7714 "fgl.yacc"
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

  case 1626:
#line 7729 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1627:
#line 7740 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1628:
#line 7743 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1629:
#line 7751 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1630:
#line 7760 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1631:
#line 7763 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1632:
#line 7767 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1633:
#line 7770 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1634:
#line 7771 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1636:
#line 7780 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1637:
#line 7781 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1638:
#line 7790 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1639:
#line 7799 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1640:
#line 7804 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1641:
#line 7805 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1642:
#line 7806 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1643:
#line 7807 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1644:
#line 7814 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1645:
#line 7817 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1646:
#line 7823 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1647:
#line 7826 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1648:
#line 7836 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1649:
#line 7845 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1650:
#line 7848 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1651:
#line 7851 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1652:
#line 7857 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1653:
#line 7863 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1654:
#line 7866 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1655:
#line 7869 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1656:
#line 7872 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1657:
#line 7879 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1658:
#line 7881 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1659:
#line 7883 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1660:
#line 7885 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1661:
#line 7887 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1662:
#line 7888 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1663:
#line 7889 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1664:
#line 7890 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1665:
#line 7891 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1666:
#line 7892 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1667:
#line 7893 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1668:
#line 7895 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1669:
#line 7897 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1670:
#line 7899 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1671:
#line 7901 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1672:
#line 7903 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1673:
#line 7905 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1674:
#line 7907 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1675:
#line 7908 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1676:
#line 7910 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1677:
#line 7914 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1678:
#line 7915 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1680:
#line 7925 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1681:
#line 7934 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1682:
#line 7938 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1683:
#line 7945 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1684:
#line 7945 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1686:
#line 7949 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1687:
#line 7954 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1688:
#line 7954 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1690:
#line 7958 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1691:
#line 7962 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1694:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1695:
#line 7971 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1700:
#line 7990 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1701:
#line 7991 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1704:
#line 7999 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1705:
#line 8005 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1708:
#line 8024 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1709:
#line 8025 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1710:
#line 8026 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1711:
#line 8027 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1712:
#line 8028 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1713:
#line 8029 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1714:
#line 8033 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1715:
#line 8034 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1716:
#line 8035 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1717:
#line 8039 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1718:
#line 8043 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1720:
#line 8052 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1722:
#line 8057 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1723:
#line 8058 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2041:
#line 8383 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2042:
#line 8383 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2043:
#line 8390 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2044:
#line 8390 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2045:
#line 8478 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2046:
#line 8482 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2047:
#line 8484 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2048:
#line 8491 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2049:
#line 8495 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2050:
#line 8501 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2051:
#line 8509 "fgl.yacc"
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

  case 2052:
#line 8519 "fgl.yacc"
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

  case 2053:
#line 8529 "fgl.yacc"
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

  case 2054:
#line 8541 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2055:
#line 8544 "fgl.yacc"
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

  case 2056:
#line 8563 "fgl.yacc"
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

  case 2057:
#line 8589 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2058:
#line 8592 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2060:
#line 8601 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2061:
#line 8606 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2062:
#line 8609 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2063:
#line 8617 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2064:
#line 8625 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2065:
#line 8638 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2066:
#line 8641 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2067:
#line 8649 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2068:
#line 8652 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2069:
#line 8655 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2070:
#line 8663 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2071:
#line 8667 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2072:
#line 8670 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2073:
#line 8673 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2074:
#line 8676 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2075:
#line 8680 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2076:
#line 8681 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2077:
#line 8682 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2078:
#line 8683 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2079:
#line 8684 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2080:
#line 8690 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2081:
#line 8691 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2082:
#line 8692 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2083:
#line 8693 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2084:
#line 8694 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2085:
#line 8695 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2086:
#line 8696 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2087:
#line 8697 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2088:
#line 8698 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2089:
#line 8699 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2090:
#line 8700 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2091:
#line 8701 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2092:
#line 8702 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2093:
#line 8703 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2094:
#line 8707 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2095:
#line 8713 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2096:
#line 8714 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2097:
#line 8722 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2098:
#line 8724 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2100:
#line 8730 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2101:
#line 8734 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2102:
#line 8738 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2103:
#line 8754 "fgl.yacc"
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

  case 2104:
#line 8773 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2105:
#line 8775 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2106:
#line 8781 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2107:
#line 8782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2108:
#line 8783 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2109:
#line 8784 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2113:
#line 8802 "fgl.yacc"
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

  case 2114:
#line 8828 "fgl.yacc"
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

  case 2115:
#line 8883 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2116:
#line 8897 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2117:
#line 8900 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2118:
#line 8904 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2119:
#line 8919 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2120:
#line 8919 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2121:
#line 8925 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2122:
#line 8926 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2123:
#line 8929 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2124:
#line 8930 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2125:
#line 8931 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2126:
#line 8932 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2127:
#line 8933 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2128:
#line 8934 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2129:
#line 8935 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2130:
#line 8941 "fgl.yacc"
    {yyval.field_list=yyvsp[0].field_list;}
    break;

  case 2131:
#line 8953 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2132:
#line 8957 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2133:
#line 8961 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2134:
#line 8965 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2135:
#line 8970 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2136:
#line 8974 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2137:
#line 8979 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2139:
#line 8987 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2141:
#line 8993 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2142:
#line 8999 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2143:
#line 9003 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2148:
#line 9021 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2149:
#line 9028 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2150:
#line 9038 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2151:
#line 9038 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18261 "y.tab.c"

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


#line 9137 "fgl.yacc"

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



