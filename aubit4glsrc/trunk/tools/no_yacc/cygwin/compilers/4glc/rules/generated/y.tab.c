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
     NAME = 1652,
     UMINUS = 1653,
     COMMA = 1568,
     KW_OR = 1608,
     KW_AND = 1563,
     KW_USING = 1499,
     MATCHES = 1377,
     POWER = 1485,
     LESS_THAN = 1481,
     GREATER_THAN = 1395,
     EQUAL = 1558,
     GREATER_THAN_EQ = 1294,
     LESS_THAN_EQ = 1352,
     NOT_EQUAL = 1426,
     PLUS = 1594,
     MINUS = 1581,
     DIVIDE = 1514,
     MULTIPLY = 1486,
     MOD = 1582,
     COMMAND = 1359,
     NUMBER_VALUE = 1654,
     CHAR_VALUE = 1655,
     INT_VALUE = 1656,
     NAMED_GEN = 1657,
     CLINE = 1658,
     SQLLINE = 1659,
     KW_CSTART = 1660,
     KW_CEND = 1661,
     USER_DTYPE = 1662,
     SQL_TEXT = 1663,
     BEFORE_INSERT = 1000,
     BEFORE_DELETE = 1001,
     AFTER_INSERT = 1002,
     AFTER_DELETE = 1003,
     DELETE_ROW_EQUAL_TRUE = 1004,
     INSERT_ROW_EQUAL_TRUE = 1005,
     DELETE_ROW_EQUAL_FALSE = 1006,
     INSERT_ROW_EQUAL_FALSE = 1007,
     CURRENT_ROW_DISPLAY_EQUAL = 1008,
     MAXCOUNT = 1009,
     ALTER_TABLE = 1010,
     WHENEVER_ERROR_CONTINUE = 1011,
     WHENEVER_WARNING_CONTINUE = 1012,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1013,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1014,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1015,
     XSET_MULTIPLY_EQUAL = 1016,
     XSET_OPEN_BRACKET = 1017,
     NEWFORMATSHARED = 1018,
     CREATE_DATABASE = 1019,
     IMPORT_LEGACY_FUNCTION = 1020,
     ADD_CONSTRAINT = 1021,
     DROP_CONSTRAINT = 1022,
     AS_STATIC = 1023,
     NOT_FIELD_TOUCHED = 1024,
     LOCAL_FUNCTION = 1025,
     EVERY_ROW = 1026,
     ELIF = 1027,
     DOUBLE_PRECISION = 1028,
     COUNT_MULTIPLY = 1029,
     WAIT_FOR_KEY = 1030,
     AT_TERMINATION_CALL = 1031,
     TERMINATE_REPORT = 1032,
     TO_MAIN_CAPTION = 1033,
     CLEARSTAT = 1034,
     TO_MENUITEM = 1035,
     ID_TO_INT = 1036,
     TO_STATUSBOX = 1037,
     ASCII_HEIGHT_ALL = 1038,
     ASCII_WIDTH_ALL = 1039,
     IMPORT_DATATYPE = 1040,
     UP_BY = 1041,
     PAGE_TRAILER_SIZE = 1042,
     PAGE_HEADER_SIZE = 1043,
     FIRST_PAGE_HEADER_SIZE = 1044,
     BYTES_USE_AS_IMAGE = 1045,
     BYTES_USE_AS_ASCII = 1046,
     DOWN_BY = 1047,
     CLOSE_STATUSBOX = 1048,
     MODIFY_NEXT_SIZE = 1049,
     LOCK_MODE_PAGE = 1050,
     LOCK_MODE_ROW = 1051,
     TO_PIPE = 1052,
     TO_PRINTER = 1053,
     STATUSBOX = 1054,
     CONNECT_TO = 1055,
     FORMHANDLER_INPUT = 1056,
     UNITS_YEAR = 1057,
     UNITS_MONTH = 1058,
     UNITS_DAY = 1059,
     UNITS_HOUR = 1060,
     UNITS_MINUTE = 1061,
     UNITS_SECOND = 1062,
     NO_NEW_LINES = 1063,
     FIELDTOWIDGET = 1064,
     WITH_HOLD = 1065,
     SHOW_MENU = 1066,
     CWIS = 1067,
     CREATE_IDX = 1068,
     FORM_IS_COMPILED = 1069,
     PDF_REPORT = 1070,
     IMPORT_FUNCTION = 1071,
     PROMPT_MANY = 1072,
     POINTS = 1073,
     MM = 1074,
     INCHES = 1075,
     PREPEND = 1076,
     MEMBER_OF = 1077,
     MEMBER_FUNCTION = 1078,
     APPEND = 1079,
     TEMPLATE = 1080,
     END_TEMPLATE = 1081,
     SQLSICS = 1082,
     CREATE_SCHEMA = 1083,
     SQLSIRR = 1084,
     UPDATESTATS_T = 1085,
     SQLSICR = 1086,
     WHENEVER_SQLSUCCESS = 1087,
     WHENEVER_SQLWARNING = 1088,
     START_EXTERN = 1089,
     WHENEVER_ANY_ERROR = 1090,
     WHENEVER_NOT_FOUND = 1091,
     CONTINUE_CONSTRUCT = 1092,
     FOUNCONSTR = 1093,
     SQLSIDR = 1094,
     WHENEVER_SQLERROR = 1095,
     CREATE_TEMP_TABLE = 1096,
     CURRENT_WINDOW_IS = 1097,
     FIRST_PAGE_HEADER = 1098,
     ORDER_EXTERNAL_BY = 1099,
     SCROLL_CURSOR_FOR = 1100,
     SCROLL_CURSOR = 1101,
     SQL_INTERRUPT_OFF = 1102,
     STOP_ALL_EXTERNAL = 1103,
     WITH_CHECK_OPTION = 1104,
     WITH_GRANT_OPTION = 1105,
     SQLSLMNW = 1106,
     ADDCONSTUNIQ = 1107,
     CONTINUE_DISPLAY = 1108,
     CONTINUE_FOREACH = 1109,
     OUTPUT_TO_REPORT = 1110,
     SQL_INTERRUPT_ON = 1111,
     WHENEVER_SUCCESS = 1112,
     WHENEVER_WARNING = 1113,
     WHERE_CURRENT_OF = 1114,
     WITHOUT_DEFAULTS = 1115,
     FOCONSTR = 1116,
     SCALED_BY = 1117,
     CONTINUE_PROMPT = 1118,
     PDF_FUNCTION = 1119,
     DEFER_INTERRUPT = 1120,
     DISPLAY_BY_NAME = 1121,
     NOT_NULL_UNIQUE = 1122,
     SKIP_TO_TOP = 1123,
     TOP_OF_PAGE = 1124,
     SKIP_TO = 1125,
     SKIP_BY = 1126,
     WITHOUT_WAITING = 1127,
     BEFCONSTRUCT = 1128,
     SQLSLMW = 1129,
     WHENEVER_ERROR = 1130,
     AFTCONSTRUCT = 1131,
     ALL_PRIVILEGES = 1132,
     CLOSE_DATABASE = 1133,
     CONTINUE_INPUT = 1134,
     CONTINUE_WHILE = 1135,
     CREATE_SYNONYM = 1136,
     DROP_TABLE = 1137,
     EXIT_CONSTRUCT = 1138,
     INEXCLUSIVE = 1139,
     REPORT_TO_PRINTER = 1140,
     REPORT_TO_PIPE = 1141,
     SET_SESSION_TO = 1142,
     UPDATESTATS = 1143,
     WITHOUT_HEAD = 1144,
     CLEARSCR = 1145,
     WITH_B_LOG = 1146,
     AUTHORIZATION = 1147,
     BOTTOM_MARGIN = 1148,
     CLOSE_SESSION = 1149,
     CONTINUE_CASE = 1150,
     CONTINUE_MENU = 1151,
     DISPLAY_ARRAY = 1152,
     END_SQL = 1153,
     DOLLAR = 1154,
     END_CONSTRUCT = 1155,
     FIELD_TOUCHED = 1156,
     FINISH_REPORT = 1157,
     INFACC = 1158,
     INPUT_NO_WRAP = 1159,
     LOCKMODEPAGE = 1160,
     SETPMOFF = 1161,
     UNCONSTRAINED = 1162,
     PAGE_TRAILER = 1163,
     SETPMON = 1164,
     BEFGROUP = 1165,
     CLOSE_WINDOW = 1166,
     COMMENT_LINE = 1167,
     CONTINUE_FOR = 1168,
     CREATE_DB = 1169,
     CREATE_TABLE = 1170,
     DEFAULT_NULL = 1171,
     DELETE_USING = 1172,
     DISPLAY_FORM = 1173,
     END_FUNCTION = 1174,
     EXIT_DISPLAY = 1175,
     EXIT_FOREACH = 1176,
     EXIT_PROGRAM = 1177,
     INFCOLS = 1178,
     LOCKMODEROW = 1179,
     ON_EVERY_ROW = 1180,
     OPEN_SESSION = 1181,
     RIGHT_MARGIN = 1182,
     SELECT_USING = 1183,
     START_REPORT = 1184,
     UNLOCK_TABLE = 1185,
     UPDATE_USING = 1186,
     ACL_BUILTIN = 1187,
     AFTGROUP = 1188,
     INFIDX = 1189,
     INFSTAT = 1190,
     LEFT_MARGIN = 1191,
     PAGE_HEADER = 1192,
     ROLLBACK_W = 1193,
     SET_SESSION = 1194,
     SQLSEOFF = 1195,
     WITH_A_LOG = 1196,
     BEFDISP = 1197,
     BEFORE_MENU = 1198,
     CREATE_VIEW = 1199,
     DEFINE_TYPE = 1200,
     DELETE_FROM = 1201,
     END_DISPLAY = 1202,
     END_REPORT = 1203,
     END_FOREACH = 1204,
     END_FOR = 1205,
     END_GLOBALS = 1206,
     EXIT_PROMPT = 1207,
     EXTENT_SIZE = 1208,
     FOREIGN_KEY = 1209,
     HIDE_OPTION = 1210,
     HIDE_WINDOW = 1211,
     INSERT_INTO = 1212,
     IS_NOT_NULL = 1213,
     MOVE_WINDOW = 1214,
     NEXT_OPTION = 1215,
     NOT_MATCHES = 1216,
     ON_LAST_ROW = 1217,
     OPEN_WINDOW = 1218,
     OPEN_STATUSBOX = 1219,
     PAGE_LENGTH = 1220,
     PAGE_WIDTH = 1221,
     PRIMARY_KEY = 1222,
     PROMPT_LINE = 1223,
     RECORD_LIKE = 1224,
     ROLLFORWARD = 1225,
     SETBL = 1226,
     SHOW_OPTION = 1227,
     SHOW_WINDOW = 1228,
     SQLSEON = 1229,
     TO_DATABASE = 1230,
     USE_SESSION = 1231,
     WITH_NO_LOG = 1232,
     AFTDISP = 1233,
     BEFFIELD = 1234,
     INSHARE = 1235,
     UNLOCKTAB = 1236,
     AFTFIELD = 1237,
     ATTRIBUTES = 1238,
     BEFINP = 1239,
     BEGIN_WORK = 1240,
     CLEARWIN = 1241,
     CLOSE_FORM = 1242,
     DEFER_QUIT = 1243,
     DESCENDING = 1244,
     DROP_INDEX = 1245,
     END_PROMPT = 1246,
     END_RECORD = 1247,
     ERROR_LINE = 1248,
     EXIT_INPUT = 1249,
     EXIT_WHILE = 1250,
     FOR_UPDATE_OF = 1251,
     FOR_UPDATE = 1252,
     GET_FLDBUF = 1253,
     INITIALIZE = 1254,
     INPUT_WRAP = 1255,
     LOCK_TABLE = 1256,
     MSG_LINE = 1257,
     NOT_EXISTS = 1258,
     ON_ANY_KEY = 1259,
     REFERENCES = 1260,
     RENCOL = 1261,
     SET_CURSOR = 1262,
     SMALLFLOAT = 1263,
     SQLSUCCESS = 1264,
     TOP_MARGIN = 1265,
     WITH_ARRAY = 1266,
     ACCEPTKEY = 1267,
     ACCEPT = 1268,
     AFTINP = 1269,
     CLEARFORMTODEFAULTS = 1270,
     CLEARFORM = 1271,
     CLEAR_X_FORM = 1272,
     COMMIT_W = 1273,
     NEXTPAGE = 1274,
     PREVPAGE = 1275,
     CTRL_KEY = 1276,
     INFTABS = 1277,
     NEXTFIELD = 1278,
     NEXTFORM = 1279,
     RENTAB = 1280,
     ASCENDING = 1281,
     ASSOCIATE = 1282,
     CHARACTER = 1283,
     CONSTRUCT = 1284,
     DELIMITER = 1285,
     DOWNSHIFT = 1286,
     DROP_VIEW = 1287,
     END_INPUT = 1288,
     END_WHILE = 1289,
     EXCLUSIVE = 1290,
     EXIT_CASE = 1291,
     EXIT_MENU = 1292,
     FORM_LINE = 1293,
     INTERRUPT = 1295,
     INTO_TEMP = 1296,
     INVISIBLE = 1297,
     IN_MEMORY = 1298,
     LINKED_TO = 1299,
     LOAD_FROM = 1300,
     LOCKTAB = 1301,
     MENU_LINE = 1302,
     OPEN_FORM = 1303,
     OTHERWISE = 1304,
     PRECISION = 1305,
     PRIOR = 1306,
     PROCEDURE = 1307,
     REPORT_TO = 1308,
     RETURNING = 1309,
     UNDERLINE = 1310,
     UNLOAD_TO = 1311,
     BEFROW = 1312,
     UNLOAD_T = 1313,
     VARIABLE = 1314,
     ABSOLUTE = 1315,
     AFTROW = 1316,
     BUFFERED = 1317,
     CONSTANT = 1318,
     CONST = 1319,
     CONTINUE = 1320,
     DATABASE = 1321,
     DATETIME = 1322,
     DEFAULTS = 1323,
     DISTINCT = 1324,
     END_CASE = 1325,
     END_MAIN = 1326,
     END_MENU = 1327,
     END_TYPE = 1328,
     EXIT_FOR = 1329,
     EXTERNAL = 1330,
     FRACTION = 1331,
     FUNCTION = 1332,
     GROUP_BY = 1333,
     INTERVAL = 1334,
     KWMESSAGE = 1335,
     NOT_LIKE = 1336,
     NOT_NULL = 1337,
     PASSWORD = 1338,
     PREVIOUS = 1339,
     READONLY = 1340,
     REGISTER = 1341,
     RELATIVE = 1342,
     RESOURCE = 1343,
     SMALLINT = 1344,
     VALIDATE = 1345,
     WHENEVER = 1346,
     WITH_LOG = 1347,
     WORDWRAP = 1348,
     BY_NAME = 1349,
     IN_FILE = 1350,
     IS_NULL = 1351,
     AVERAGE = 1353,
     BETWEEN = 1354,
     CAPTION = 1355,
     CLIPPED = 1356,
     CLOSE_BRACKET = 1357,
     COLUMNS = 1358,
     COMMENT = 1360,
     CONNECT = 1361,
     CURRENT = 1362,
     DBYNAME = 1363,
     DECIMAL = 1364,
     DECLARE = 1365,
     DEFAULT = 1366,
     DISPLAY = 1367,
     ENDCODE = 1368,
     EXECUTE = 1369,
     FOREACH = 1370,
     FOREIGN = 1371,
     GLOBALS = 1372,
     INFIELD = 1373,
     INTEGER = 1374,
     KWWINDOW = 1375,
     MAGENTA = 1376,
     NUMERIC = 1378,
     OPTIONS = 1379,
     PERCENT = 1380,
     PREPARE = 1381,
     PROGRAM = 1382,
     RECOVER = 1383,
     REVERSE = 1384,
     SECTION = 1385,
     SESSION = 1386,
     SYNONYM = 1387,
     THRU = 1388,
     TRAILER = 1389,
     UPSHIFT = 1390,
     VARCHAR = 1391,
     WAITING = 1392,
     CLOSE_SHEV = 1393,
     CLOSE_SQUARE = 1394,
     KW_FALSE = 1396,
     NOT_IN = 1397,
     ONKEY = 1398,
     OPEN_BRACKET = 1399,
     BORDER = 1400,
     BOTTOM = 1401,
     COLUMN = 1402,
     COMMIT = 1403,
     CREATE = 1404,
     CURSOR = 1405,
     DEFINE = 1406,
     DELETE = 1407,
     DOUBLE = 1408,
     END_IF = 1409,
     ESCAPE = 1410,
     EXISTS = 1411,
     EXTEND = 1412,
     EXTENT = 1413,
     FINISH = 1414,
     FORMAT = 1415,
     HAVING = 1416,
     HEADER = 1417,
     INSERT = 1418,
     LOCATE = 1419,
     MARGIN = 1420,
     MEMORY = 1421,
     MINUTE = 1422,
     MODIFY = 1423,
     NORMAL = 1424,
     EQUAL_EQUAL = 1425,
     OPEN_SHEV = 1427,
     OPEN_SQUARE = 1428,
     OPTION = 1429,
     OUTPUT = 1430,
     PROMPT = 1431,
     PUBLIC = 1432,
     RECORD = 1433,
     REPORT = 1434,
     RETURN = 1435,
     REVOKE = 1436,
     SCHEMA = 1437,
     SCROLL_USING = 1438,
     SCROLL = 1439,
     SECOND = 1440,
     SELECT = 1441,
     SERIAL = 1442,
     SETL = 1443,
     SHARED = 1444,
     SPACES = 1445,
     UNIQUE = 1446,
     UNLOCK = 1447,
     UPDATE = 1448,
     VALUES = 1449,
     YELLOW = 1450,
     AFTER = 1451,
     KWLINE = 1452,
     KW_NULL = 1453,
     KW_TRUE = 1454,
     SINGLE_KEY = 1455,
     ALTER = 1456,
     ARRAY = 1457,
     ASCII = 1458,
     AUDIT = 1459,
     BLACK = 1460,
     BLINK = 1461,
     CHECK = 1462,
     CLEAR = 1463,
     CLOSE = 1464,
     CODE_C = 1465,
     COUNT = 1466,
     DEFER = 1467,
     ERROR = 1468,
     EVERY = 1469,
     FETCH = 1470,
     FIRST = 1471,
     FLOAT = 1472,
     FLUSH = 1473,
     FOUND = 1474,
     GRANT = 1475,
     GREEN = 1476,
     GROUP = 1477,
     INDEX = 1478,
     KWFORM = 1479,
     LABEL = 1480,
     LOCAL = 1482,
     MONEY = 1483,
     MONTH = 1484,
     ORDER = 1487,
     OUTER = 1488,
     PAUSE = 1489,
     PRINT_IMAGE = 1490,
     PRINT_FILE = 1491,
     PRINT = 1492,
     RIGHT = 1493,
     DOUBLE_COLON = 1494,
     SEMICOLON = 1495,
     SLEEP = 1496,
     TUPLE = 1497,
     UNION = 1498,
     WHERE = 1500,
     WHILE = 1501,
     WHITE = 1502,
     CCODE = 1503,
     ANSI = 1504,
     BLUE = 1505,
     BOLD = 1506,
     BYTE = 1507,
     FCALL = 1508,
     CASE = 1509,
     CHAR = 1510,
     CYAN = 1511,
     DATE = 1512,
     DESC = 1513,
     DOWN = 1515,
     TAB = 1516,
     DROP = 1517,
     ELSE = 1518,
     EXEC = 1519,
     EXIT = 1520,
     FREE = 1521,
     FROM = 1522,
     GOTO = 1523,
     HELP_FILE = 1524,
     LANG_FILE = 1525,
     HELP = 1526,
     HIDE = 1527,
     HOUR = 1528,
     INTO = 1529,
     LAST = 1530,
     LEFT = 1531,
     LIKE = 1532,
     MAIN = 1533,
     MENU = 1534,
     MODE = 1535,
     NEED = 1536,
     NEXT = 1537,
     NOCR = 1538,
     OPEN = 1539,
     QUIT = 1540,
     REAL = 1541,
     ROWS = 1542,
     SHOW = 1543,
     SIZE = 1544,
     SKIP = 1545,
     SOME = 1546,
     STEP = 1547,
     STOP = 1548,
     TEMP = 1549,
     TEXT = 1550,
     THEN = 1551,
     USER = 1552,
     WAIT = 1553,
     WHEN = 1554,
     WITH = 1555,
     WORK = 1556,
     YEAR = 1557,
     KW_IS = 1559,
     XSET = 1560,
     ADD = 1561,
     ALL = 1562,
     ANY = 1564,
     ASC = 1565,
     AVG = 1566,
     COLON = 1567,
     DAY = 1569,
     DBA = 1570,
     DEC = 1571,
     DIM = 1572,
     FKEY = 1573,
     FOR = 1574,
     KEY = 1575,
     KWNO = 1576,
     LET = 1577,
     LOG = 1578,
     XMAX = 1579,
     XMIN = 1580,
     NOT = 1583,
     PAD = 1584,
     PUT = 1585,
     RED = 1586,
     ROW = 1587,
     RUN = 1588,
     SQL = 1589,
     SUM = 1590,
     TOP = 1591,
     USE = 1592,
     ATSIGN = 1593,
     AS_TIFF = 1595,
     AS_GIF = 1596,
     AS_PNG = 1597,
     AS_JPEG = 1598,
     AS = 1599,
     AT = 1600,
     BY = 1601,
     DOT = 1602,
     GO = 1603,
     IF = 1604,
     IN = 1605,
     OF = 1606,
     ON = 1607,
     TO = 1609,
     UP = 1610,
     FONT_NAME = 1611,
     FONT_SIZE = 1612,
     PAPER_SIZE_IS_LETTER = 1613,
     PAPER_SIZE_IS_LEGAL = 1614,
     PAPER_SIZE_IS_A5 = 1615,
     PAPER_SIZE_IS_A4 = 1616,
     PAPER_SIZE_IS_LETTER_L = 1617,
     PAPER_SIZE_IS_LEGAL_L = 1618,
     PAPER_SIZE_IS_A5_L = 1619,
     PAPER_SIZE_IS_A4_L = 1620,
     FORMHANDLER = 1621,
     END_FORMHANDLER = 1622,
     BEFORE_EVENT = 1623,
     BEFORE_OPEN_FORM = 1624,
     AFTER_EVENT = 1625,
     BEFORE_CLOSE_FORM = 1626,
     BEFORE_ANY = 1627,
     AFTER_ANY = 1628,
     MENUHANDLER = 1629,
     END_MENUHANDLER = 1630,
     BEFORE_SHOW_MENU = 1631,
     DISABLE_PROGRAM = 1632,
     DISABLE_ALL = 1633,
     BUTTONS = 1634,
     CHECK_MENUITEM = 1635,
     DISABLE_FORM = 1636,
     DISABLE_MENUITEMS = 1637,
     DISABLE = 1638,
     ENABLE_FORM = 1639,
     ENABLE_MENUITEMS = 1640,
     ENABLE = 1641,
     KWFIELD = 1642,
     ICON = 1643,
     MESSAGEBOX = 1644,
     TO_DEFAULTS = 1645,
     UNCHECK_MENUITEM = 1646,
     BEFORE = 1647,
     INPUT = 1648,
     END = 1649,
     INT_TO_ID = 1650
   };
#endif
#define NAME 1652
#define UMINUS 1653
#define COMMA 1568
#define KW_OR 1608
#define KW_AND 1563
#define KW_USING 1499
#define MATCHES 1377
#define POWER 1485
#define LESS_THAN 1481
#define GREATER_THAN 1395
#define EQUAL 1558
#define GREATER_THAN_EQ 1294
#define LESS_THAN_EQ 1352
#define NOT_EQUAL 1426
#define PLUS 1594
#define MINUS 1581
#define DIVIDE 1514
#define MULTIPLY 1486
#define MOD 1582
#define COMMAND 1359
#define NUMBER_VALUE 1654
#define CHAR_VALUE 1655
#define INT_VALUE 1656
#define NAMED_GEN 1657
#define CLINE 1658
#define SQLLINE 1659
#define KW_CSTART 1660
#define KW_CEND 1661
#define USER_DTYPE 1662
#define SQL_TEXT 1663
#define BEFORE_INSERT 1000
#define BEFORE_DELETE 1001
#define AFTER_INSERT 1002
#define AFTER_DELETE 1003
#define DELETE_ROW_EQUAL_TRUE 1004
#define INSERT_ROW_EQUAL_TRUE 1005
#define DELETE_ROW_EQUAL_FALSE 1006
#define INSERT_ROW_EQUAL_FALSE 1007
#define CURRENT_ROW_DISPLAY_EQUAL 1008
#define MAXCOUNT 1009
#define ALTER_TABLE 1010
#define WHENEVER_ERROR_CONTINUE 1011
#define WHENEVER_WARNING_CONTINUE 1012
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1013
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1014
#define XSET_ident_DOT_MULTIPLY_EQUAL 1015
#define XSET_MULTIPLY_EQUAL 1016
#define XSET_OPEN_BRACKET 1017
#define NEWFORMATSHARED 1018
#define CREATE_DATABASE 1019
#define IMPORT_LEGACY_FUNCTION 1020
#define ADD_CONSTRAINT 1021
#define DROP_CONSTRAINT 1022
#define AS_STATIC 1023
#define NOT_FIELD_TOUCHED 1024
#define LOCAL_FUNCTION 1025
#define EVERY_ROW 1026
#define ELIF 1027
#define DOUBLE_PRECISION 1028
#define COUNT_MULTIPLY 1029
#define WAIT_FOR_KEY 1030
#define AT_TERMINATION_CALL 1031
#define TERMINATE_REPORT 1032
#define TO_MAIN_CAPTION 1033
#define CLEARSTAT 1034
#define TO_MENUITEM 1035
#define ID_TO_INT 1036
#define TO_STATUSBOX 1037
#define ASCII_HEIGHT_ALL 1038
#define ASCII_WIDTH_ALL 1039
#define IMPORT_DATATYPE 1040
#define UP_BY 1041
#define PAGE_TRAILER_SIZE 1042
#define PAGE_HEADER_SIZE 1043
#define FIRST_PAGE_HEADER_SIZE 1044
#define BYTES_USE_AS_IMAGE 1045
#define BYTES_USE_AS_ASCII 1046
#define DOWN_BY 1047
#define CLOSE_STATUSBOX 1048
#define MODIFY_NEXT_SIZE 1049
#define LOCK_MODE_PAGE 1050
#define LOCK_MODE_ROW 1051
#define TO_PIPE 1052
#define TO_PRINTER 1053
#define STATUSBOX 1054
#define CONNECT_TO 1055
#define FORMHANDLER_INPUT 1056
#define UNITS_YEAR 1057
#define UNITS_MONTH 1058
#define UNITS_DAY 1059
#define UNITS_HOUR 1060
#define UNITS_MINUTE 1061
#define UNITS_SECOND 1062
#define NO_NEW_LINES 1063
#define FIELDTOWIDGET 1064
#define WITH_HOLD 1065
#define SHOW_MENU 1066
#define CWIS 1067
#define CREATE_IDX 1068
#define FORM_IS_COMPILED 1069
#define PDF_REPORT 1070
#define IMPORT_FUNCTION 1071
#define PROMPT_MANY 1072
#define POINTS 1073
#define MM 1074
#define INCHES 1075
#define PREPEND 1076
#define MEMBER_OF 1077
#define MEMBER_FUNCTION 1078
#define APPEND 1079
#define TEMPLATE 1080
#define END_TEMPLATE 1081
#define SQLSICS 1082
#define CREATE_SCHEMA 1083
#define SQLSIRR 1084
#define UPDATESTATS_T 1085
#define SQLSICR 1086
#define WHENEVER_SQLSUCCESS 1087
#define WHENEVER_SQLWARNING 1088
#define START_EXTERN 1089
#define WHENEVER_ANY_ERROR 1090
#define WHENEVER_NOT_FOUND 1091
#define CONTINUE_CONSTRUCT 1092
#define FOUNCONSTR 1093
#define SQLSIDR 1094
#define WHENEVER_SQLERROR 1095
#define CREATE_TEMP_TABLE 1096
#define CURRENT_WINDOW_IS 1097
#define FIRST_PAGE_HEADER 1098
#define ORDER_EXTERNAL_BY 1099
#define SCROLL_CURSOR_FOR 1100
#define SCROLL_CURSOR 1101
#define SQL_INTERRUPT_OFF 1102
#define STOP_ALL_EXTERNAL 1103
#define WITH_CHECK_OPTION 1104
#define WITH_GRANT_OPTION 1105
#define SQLSLMNW 1106
#define ADDCONSTUNIQ 1107
#define CONTINUE_DISPLAY 1108
#define CONTINUE_FOREACH 1109
#define OUTPUT_TO_REPORT 1110
#define SQL_INTERRUPT_ON 1111
#define WHENEVER_SUCCESS 1112
#define WHENEVER_WARNING 1113
#define WHERE_CURRENT_OF 1114
#define WITHOUT_DEFAULTS 1115
#define FOCONSTR 1116
#define SCALED_BY 1117
#define CONTINUE_PROMPT 1118
#define PDF_FUNCTION 1119
#define DEFER_INTERRUPT 1120
#define DISPLAY_BY_NAME 1121
#define NOT_NULL_UNIQUE 1122
#define SKIP_TO_TOP 1123
#define TOP_OF_PAGE 1124
#define SKIP_TO 1125
#define SKIP_BY 1126
#define WITHOUT_WAITING 1127
#define BEFCONSTRUCT 1128
#define SQLSLMW 1129
#define WHENEVER_ERROR 1130
#define AFTCONSTRUCT 1131
#define ALL_PRIVILEGES 1132
#define CLOSE_DATABASE 1133
#define CONTINUE_INPUT 1134
#define CONTINUE_WHILE 1135
#define CREATE_SYNONYM 1136
#define DROP_TABLE 1137
#define EXIT_CONSTRUCT 1138
#define INEXCLUSIVE 1139
#define REPORT_TO_PRINTER 1140
#define REPORT_TO_PIPE 1141
#define SET_SESSION_TO 1142
#define UPDATESTATS 1143
#define WITHOUT_HEAD 1144
#define CLEARSCR 1145
#define WITH_B_LOG 1146
#define AUTHORIZATION 1147
#define BOTTOM_MARGIN 1148
#define CLOSE_SESSION 1149
#define CONTINUE_CASE 1150
#define CONTINUE_MENU 1151
#define DISPLAY_ARRAY 1152
#define END_SQL 1153
#define DOLLAR 1154
#define END_CONSTRUCT 1155
#define FIELD_TOUCHED 1156
#define FINISH_REPORT 1157
#define INFACC 1158
#define INPUT_NO_WRAP 1159
#define LOCKMODEPAGE 1160
#define SETPMOFF 1161
#define UNCONSTRAINED 1162
#define PAGE_TRAILER 1163
#define SETPMON 1164
#define BEFGROUP 1165
#define CLOSE_WINDOW 1166
#define COMMENT_LINE 1167
#define CONTINUE_FOR 1168
#define CREATE_DB 1169
#define CREATE_TABLE 1170
#define DEFAULT_NULL 1171
#define DELETE_USING 1172
#define DISPLAY_FORM 1173
#define END_FUNCTION 1174
#define EXIT_DISPLAY 1175
#define EXIT_FOREACH 1176
#define EXIT_PROGRAM 1177
#define INFCOLS 1178
#define LOCKMODEROW 1179
#define ON_EVERY_ROW 1180
#define OPEN_SESSION 1181
#define RIGHT_MARGIN 1182
#define SELECT_USING 1183
#define START_REPORT 1184
#define UNLOCK_TABLE 1185
#define UPDATE_USING 1186
#define ACL_BUILTIN 1187
#define AFTGROUP 1188
#define INFIDX 1189
#define INFSTAT 1190
#define LEFT_MARGIN 1191
#define PAGE_HEADER 1192
#define ROLLBACK_W 1193
#define SET_SESSION 1194
#define SQLSEOFF 1195
#define WITH_A_LOG 1196
#define BEFDISP 1197
#define BEFORE_MENU 1198
#define CREATE_VIEW 1199
#define DEFINE_TYPE 1200
#define DELETE_FROM 1201
#define END_DISPLAY 1202
#define END_REPORT 1203
#define END_FOREACH 1204
#define END_FOR 1205
#define END_GLOBALS 1206
#define EXIT_PROMPT 1207
#define EXTENT_SIZE 1208
#define FOREIGN_KEY 1209
#define HIDE_OPTION 1210
#define HIDE_WINDOW 1211
#define INSERT_INTO 1212
#define IS_NOT_NULL 1213
#define MOVE_WINDOW 1214
#define NEXT_OPTION 1215
#define NOT_MATCHES 1216
#define ON_LAST_ROW 1217
#define OPEN_WINDOW 1218
#define OPEN_STATUSBOX 1219
#define PAGE_LENGTH 1220
#define PAGE_WIDTH 1221
#define PRIMARY_KEY 1222
#define PROMPT_LINE 1223
#define RECORD_LIKE 1224
#define ROLLFORWARD 1225
#define SETBL 1226
#define SHOW_OPTION 1227
#define SHOW_WINDOW 1228
#define SQLSEON 1229
#define TO_DATABASE 1230
#define USE_SESSION 1231
#define WITH_NO_LOG 1232
#define AFTDISP 1233
#define BEFFIELD 1234
#define INSHARE 1235
#define UNLOCKTAB 1236
#define AFTFIELD 1237
#define ATTRIBUTES 1238
#define BEFINP 1239
#define BEGIN_WORK 1240
#define CLEARWIN 1241
#define CLOSE_FORM 1242
#define DEFER_QUIT 1243
#define DESCENDING 1244
#define DROP_INDEX 1245
#define END_PROMPT 1246
#define END_RECORD 1247
#define ERROR_LINE 1248
#define EXIT_INPUT 1249
#define EXIT_WHILE 1250
#define FOR_UPDATE_OF 1251
#define FOR_UPDATE 1252
#define GET_FLDBUF 1253
#define INITIALIZE 1254
#define INPUT_WRAP 1255
#define LOCK_TABLE 1256
#define MSG_LINE 1257
#define NOT_EXISTS 1258
#define ON_ANY_KEY 1259
#define REFERENCES 1260
#define RENCOL 1261
#define SET_CURSOR 1262
#define SMALLFLOAT 1263
#define SQLSUCCESS 1264
#define TOP_MARGIN 1265
#define WITH_ARRAY 1266
#define ACCEPTKEY 1267
#define ACCEPT 1268
#define AFTINP 1269
#define CLEARFORMTODEFAULTS 1270
#define CLEARFORM 1271
#define CLEAR_X_FORM 1272
#define COMMIT_W 1273
#define NEXTPAGE 1274
#define PREVPAGE 1275
#define CTRL_KEY 1276
#define INFTABS 1277
#define NEXTFIELD 1278
#define NEXTFORM 1279
#define RENTAB 1280
#define ASCENDING 1281
#define ASSOCIATE 1282
#define CHARACTER 1283
#define CONSTRUCT 1284
#define DELIMITER 1285
#define DOWNSHIFT 1286
#define DROP_VIEW 1287
#define END_INPUT 1288
#define END_WHILE 1289
#define EXCLUSIVE 1290
#define EXIT_CASE 1291
#define EXIT_MENU 1292
#define FORM_LINE 1293
#define INTERRUPT 1295
#define INTO_TEMP 1296
#define INVISIBLE 1297
#define IN_MEMORY 1298
#define LINKED_TO 1299
#define LOAD_FROM 1300
#define LOCKTAB 1301
#define MENU_LINE 1302
#define OPEN_FORM 1303
#define OTHERWISE 1304
#define PRECISION 1305
#define PRIOR 1306
#define PROCEDURE 1307
#define REPORT_TO 1308
#define RETURNING 1309
#define UNDERLINE 1310
#define UNLOAD_TO 1311
#define BEFROW 1312
#define UNLOAD_T 1313
#define VARIABLE 1314
#define ABSOLUTE 1315
#define AFTROW 1316
#define BUFFERED 1317
#define CONSTANT 1318
#define CONST 1319
#define CONTINUE 1320
#define DATABASE 1321
#define DATETIME 1322
#define DEFAULTS 1323
#define DISTINCT 1324
#define END_CASE 1325
#define END_MAIN 1326
#define END_MENU 1327
#define END_TYPE 1328
#define EXIT_FOR 1329
#define EXTERNAL 1330
#define FRACTION 1331
#define FUNCTION 1332
#define GROUP_BY 1333
#define INTERVAL 1334
#define KWMESSAGE 1335
#define NOT_LIKE 1336
#define NOT_NULL 1337
#define PASSWORD 1338
#define PREVIOUS 1339
#define READONLY 1340
#define REGISTER 1341
#define RELATIVE 1342
#define RESOURCE 1343
#define SMALLINT 1344
#define VALIDATE 1345
#define WHENEVER 1346
#define WITH_LOG 1347
#define WORDWRAP 1348
#define BY_NAME 1349
#define IN_FILE 1350
#define IS_NULL 1351
#define AVERAGE 1353
#define BETWEEN 1354
#define CAPTION 1355
#define CLIPPED 1356
#define CLOSE_BRACKET 1357
#define COLUMNS 1358
#define COMMENT 1360
#define CONNECT 1361
#define CURRENT 1362
#define DBYNAME 1363
#define DECIMAL 1364
#define DECLARE 1365
#define DEFAULT 1366
#define DISPLAY 1367
#define ENDCODE 1368
#define EXECUTE 1369
#define FOREACH 1370
#define FOREIGN 1371
#define GLOBALS 1372
#define INFIELD 1373
#define INTEGER 1374
#define KWWINDOW 1375
#define MAGENTA 1376
#define NUMERIC 1378
#define OPTIONS 1379
#define PERCENT 1380
#define PREPARE 1381
#define PROGRAM 1382
#define RECOVER 1383
#define REVERSE 1384
#define SECTION 1385
#define SESSION 1386
#define SYNONYM 1387
#define THRU 1388
#define TRAILER 1389
#define UPSHIFT 1390
#define VARCHAR 1391
#define WAITING 1392
#define CLOSE_SHEV 1393
#define CLOSE_SQUARE 1394
#define KW_FALSE 1396
#define NOT_IN 1397
#define ONKEY 1398
#define OPEN_BRACKET 1399
#define BORDER 1400
#define BOTTOM 1401
#define COLUMN 1402
#define COMMIT 1403
#define CREATE 1404
#define CURSOR 1405
#define DEFINE 1406
#define DELETE 1407
#define DOUBLE 1408
#define END_IF 1409
#define ESCAPE 1410
#define EXISTS 1411
#define EXTEND 1412
#define EXTENT 1413
#define FINISH 1414
#define FORMAT 1415
#define HAVING 1416
#define HEADER 1417
#define INSERT 1418
#define LOCATE 1419
#define MARGIN 1420
#define MEMORY 1421
#define MINUTE 1422
#define MODIFY 1423
#define NORMAL 1424
#define EQUAL_EQUAL 1425
#define OPEN_SHEV 1427
#define OPEN_SQUARE 1428
#define OPTION 1429
#define OUTPUT 1430
#define PROMPT 1431
#define PUBLIC 1432
#define RECORD 1433
#define REPORT 1434
#define RETURN 1435
#define REVOKE 1436
#define SCHEMA 1437
#define SCROLL_USING 1438
#define SCROLL 1439
#define SECOND 1440
#define SELECT 1441
#define SERIAL 1442
#define SETL 1443
#define SHARED 1444
#define SPACES 1445
#define UNIQUE 1446
#define UNLOCK 1447
#define UPDATE 1448
#define VALUES 1449
#define YELLOW 1450
#define AFTER 1451
#define KWLINE 1452
#define KW_NULL 1453
#define KW_TRUE 1454
#define SINGLE_KEY 1455
#define ALTER 1456
#define ARRAY 1457
#define ASCII 1458
#define AUDIT 1459
#define BLACK 1460
#define BLINK 1461
#define CHECK 1462
#define CLEAR 1463
#define CLOSE 1464
#define CODE_C 1465
#define COUNT 1466
#define DEFER 1467
#define ERROR 1468
#define EVERY 1469
#define FETCH 1470
#define FIRST 1471
#define FLOAT 1472
#define FLUSH 1473
#define FOUND 1474
#define GRANT 1475
#define GREEN 1476
#define GROUP 1477
#define INDEX 1478
#define KWFORM 1479
#define LABEL 1480
#define LOCAL 1482
#define MONEY 1483
#define MONTH 1484
#define ORDER 1487
#define OUTER 1488
#define PAUSE 1489
#define PRINT_IMAGE 1490
#define PRINT_FILE 1491
#define PRINT 1492
#define RIGHT 1493
#define DOUBLE_COLON 1494
#define SEMICOLON 1495
#define SLEEP 1496
#define TUPLE 1497
#define UNION 1498
#define WHERE 1500
#define WHILE 1501
#define WHITE 1502
#define CCODE 1503
#define ANSI 1504
#define BLUE 1505
#define BOLD 1506
#define BYTE 1507
#define FCALL 1508
#define CASE 1509
#define CHAR 1510
#define CYAN 1511
#define DATE 1512
#define DESC 1513
#define DOWN 1515
#define TAB 1516
#define DROP 1517
#define ELSE 1518
#define EXEC 1519
#define EXIT 1520
#define FREE 1521
#define FROM 1522
#define GOTO 1523
#define HELP_FILE 1524
#define LANG_FILE 1525
#define HELP 1526
#define HIDE 1527
#define HOUR 1528
#define INTO 1529
#define LAST 1530
#define LEFT 1531
#define LIKE 1532
#define MAIN 1533
#define MENU 1534
#define MODE 1535
#define NEED 1536
#define NEXT 1537
#define NOCR 1538
#define OPEN 1539
#define QUIT 1540
#define REAL 1541
#define ROWS 1542
#define SHOW 1543
#define SIZE 1544
#define SKIP 1545
#define SOME 1546
#define STEP 1547
#define STOP 1548
#define TEMP 1549
#define TEXT 1550
#define THEN 1551
#define USER 1552
#define WAIT 1553
#define WHEN 1554
#define WITH 1555
#define WORK 1556
#define YEAR 1557
#define KW_IS 1559
#define XSET 1560
#define ADD 1561
#define ALL 1562
#define ANY 1564
#define ASC 1565
#define AVG 1566
#define COLON 1567
#define DAY 1569
#define DBA 1570
#define DEC 1571
#define DIM 1572
#define FKEY 1573
#define FOR 1574
#define KEY 1575
#define KWNO 1576
#define LET 1577
#define LOG 1578
#define XMAX 1579
#define XMIN 1580
#define NOT 1583
#define PAD 1584
#define PUT 1585
#define RED 1586
#define ROW 1587
#define RUN 1588
#define SQL 1589
#define SUM 1590
#define TOP 1591
#define USE 1592
#define ATSIGN 1593
#define AS_TIFF 1595
#define AS_GIF 1596
#define AS_PNG 1597
#define AS_JPEG 1598
#define AS 1599
#define AT 1600
#define BY 1601
#define DOT 1602
#define GO 1603
#define IF 1604
#define IN 1605
#define OF 1606
#define ON 1607
#define TO 1609
#define UP 1610
#define FONT_NAME 1611
#define FONT_SIZE 1612
#define PAPER_SIZE_IS_LETTER 1613
#define PAPER_SIZE_IS_LEGAL 1614
#define PAPER_SIZE_IS_A5 1615
#define PAPER_SIZE_IS_A4 1616
#define PAPER_SIZE_IS_LETTER_L 1617
#define PAPER_SIZE_IS_LEGAL_L 1618
#define PAPER_SIZE_IS_A5_L 1619
#define PAPER_SIZE_IS_A4_L 1620
#define FORMHANDLER 1621
#define END_FORMHANDLER 1622
#define BEFORE_EVENT 1623
#define BEFORE_OPEN_FORM 1624
#define AFTER_EVENT 1625
#define BEFORE_CLOSE_FORM 1626
#define BEFORE_ANY 1627
#define AFTER_ANY 1628
#define MENUHANDLER 1629
#define END_MENUHANDLER 1630
#define BEFORE_SHOW_MENU 1631
#define DISABLE_PROGRAM 1632
#define DISABLE_ALL 1633
#define BUTTONS 1634
#define CHECK_MENUITEM 1635
#define DISABLE_FORM 1636
#define DISABLE_MENUITEMS 1637
#define DISABLE 1638
#define ENABLE_FORM 1639
#define ENABLE_MENUITEMS 1640
#define ENABLE 1641
#define KWFIELD 1642
#define ICON 1643
#define MESSAGEBOX 1644
#define TO_DEFAULTS 1645
#define UNCHECK_MENUITEM 1646
#define BEFORE 1647
#define INPUT 1648
#define END 1649
#define INT_TO_ID 1650




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
int 		in_sql=0;
int 		continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int 		in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int 		fcall_cnt=0;

struct 		rep_structure rep_struct;
struct 		pdf_rep_structure pdf_rep_struct;
struct 		form_attr form_attrib;
char *		make_sql_string(char *first,...);
void copy_gen (int a, int b);
char *get_namespace (char *s);
void set_yytext (char *s);

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
#line 198 "fgl.yacc"
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
#line 1563 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1575 "y.tab.c"

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9015

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  666
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  834
/* YYNRULES -- Number of rules. */
#define YYNRULES  1949
/* YYNRULES -- Number of states. */
#define YYNSTATES  3210

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1663

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
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,    14,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,    15,   384,   385,   386,   387,   388,   389,    22,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,     9,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,    12,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,    16,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,    11,   508,   509,   510,    10,    20,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,     8,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,    19,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,    13,   580,
     581,   582,   583,     7,   584,   585,   586,   587,     5,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,    18,    21,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,    17,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,     6,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,     2,     3,     4,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    15,    17,    19,    21,
      25,    27,    31,    35,    37,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    57,    59,    60,    66,    73,    75,
      79,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   114,   116,
     117,   123,   125,   129,   131,   133,   136,   139,   142,   145,
     148,   151,   154,   157,   161,   162,   170,   179,   186,   188,
     195,   196,   197,   207,   208,   209,   210,   219,   220,   221,
     232,   233,   234,   244,   245,   246,   247,   262,   263,   266,
     267,   270,   272,   273,   275,   277,   281,   283,   285,   287,
     289,   293,   294,   301,   302,   308,   310,   313,   315,   318,
     320,   321,   322,   326,   327,   328,   332,   333,   338,   339,
     344,   347,   350,   353,   355,   358,   361,   365,   367,   369,
     371,   374,   376,   378,   381,   383,   385,   386,   387,   393,
     401,   410,   411,   414,   416,   420,   422,   426,   430,   432,
     435,   436,   441,   442,   447,   448,   452,   453,   457,   458,
     462,   464,   468,   470,   474,   476,   478,   480,   482,   484,
     486,   491,   492,   497,   499,   501,   502,   504,   506,   509,
     510,   511,   517,   519,   521,   523,   527,   528,   531,   536,
     541,   546,   551,   554,   555,   560,   562,   564,   566,   569,
     571,   573,   577,   578,   580,   581,   589,   590,   603,   605,
     607,   609,   611,   613,   619,   623,   625,   627,   628,   633,
     634,   640,   641,   649,   651,   655,   657,   659,   660,   662,
     663,   664,   669,   671,   673,   675,   680,   685,   692,   694,
     697,   699,   701,   703,   705,   710,   717,   719,   724,   731,
     733,   735,   737,   739,   741,   743,   745,   748,   751,   753,
     755,   760,   762,   764,   765,   769,   773,   774,   777,   779,
     781,   783,   785,   787,   789,   792,   793,   796,   797,   801,
     802,   806,   808,   809,   813,   815,   817,   819,   821,   823,
     825,   828,   830,   831,   833,   834,   840,   842,   844,   846,
     851,   856,   863,   865,   867,   869,   871,   876,   883,   885,
     890,   897,   899,   901,   903,   905,   907,   910,   913,   915,
     920,   921,   929,   930,   943,   944,   949,   950,   956,   958,
     962,   965,   967,   971,   973,   974,   977,   980,   982,   985,
     991,   996,   999,  1004,  1010,  1014,  1015,  1016,  1028,  1029,
    1032,  1034,  1035,  1038,  1040,  1043,  1044,  1048,  1049,  1053,
    1054,  1058,  1063,  1069,  1071,  1073,  1075,  1077,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1108,  1110,  1112,  1114,  1116,  1119,  1121,  1123,
    1125,  1128,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1145,
    1147,  1149,  1151,  1153,  1156,  1158,  1160,  1162,  1166,  1168,
    1172,  1174,  1178,  1180,  1182,  1184,  1187,  1189,  1191,  1195,
    1200,  1205,  1208,  1211,  1213,  1215,  1217,  1219,  1221,  1225,
    1227,  1230,  1233,  1235,  1236,  1240,  1243,  1246,  1248,  1252,
    1257,  1262,  1268,  1274,  1276,  1278,  1281,  1284,  1289,  1294,
    1297,  1300,  1305,  1310,  1312,  1315,  1318,  1321,  1324,  1327,
    1330,  1333,  1336,  1339,  1342,  1345,  1348,  1351,  1354,  1355,
    1356,  1357,  1364,  1365,  1366,  1375,  1376,  1377,  1384,  1385,
    1386,  1393,  1394,  1395,  1402,  1403,  1404,  1411,  1417,  1423,
    1429,  1437,  1438,  1442,  1444,  1446,  1451,  1456,  1461,  1466,
    1471,  1476,  1478,  1480,  1482,  1484,  1489,  1494,  1497,  1500,
    1503,  1506,  1509,  1511,  1513,  1516,  1518,  1520,  1522,  1525,
    1530,  1537,  1544,  1548,  1554,  1560,  1564,  1566,  1568,  1572,
    1574,  1578,  1579,  1580,  1592,  1593,  1596,  1597,  1598,  1599,
    1608,  1609,  1610,  1621,  1622,  1624,  1625,  1627,  1629,  1632,
    1633,  1637,  1638,  1642,  1643,  1645,  1647,  1650,  1651,  1655,
    1656,  1660,  1664,  1666,  1671,  1675,  1677,  1681,  1683,  1687,
    1689,  1693,  1695,  1698,  1699,  1703,  1704,  1708,  1709,  1714,
    1715,  1720,  1721,  1726,  1729,  1733,  1735,  1739,  1741,  1743,
    1745,  1747,  1749,  1751,  1755,  1757,  1759,  1764,  1771,  1776,
    1780,  1787,  1791,  1798,  1800,  1802,  1804,  1806,  1808,  1810,
    1811,  1814,  1816,  1818,  1820,  1825,  1827,  1829,  1831,  1836,
    1840,  1847,  1851,  1858,  1860,  1862,  1865,  1867,  1869,  1871,
    1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,  1891,
    1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,
    1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,
    1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,
    1954,  1957,  1959,  1963,  1965,  1968,  1971,  1974,  1979,  1982,
    1985,  1990,  1991,  2000,  2001,  2003,  2005,  2007,  2008,  2010,
    2013,  2014,  2016,  2019,  2020,  2022,  2025,  2026,  2028,  2032,
    2033,  2036,  2037,  2045,  2046,  2047,  2051,  2052,  2053,  2061,
    2067,  2070,  2073,  2074,  2080,  2085,  2087,  2091,  2095,  2099,
    2100,  2103,  2104,  2106,  2108,  2111,  2112,  2117,  2118,  2123,
    2124,  2128,  2129,  2133,  2134,  2138,  2139,  2143,  2144,  2148,
    2149,  2154,  2155,  2160,  2161,  2165,  2166,  2170,  2171,  2175,
    2176,  2180,  2182,  2186,  2188,  2190,  2192,  2196,  2198,  2200,
    2202,  2206,  2208,  2212,  2215,  2220,  2222,  2224,  2226,  2227,
    2232,  2238,  2245,  2246,  2257,  2261,  2263,  2265,  2268,  2271,
    2272,  2275,  2277,  2280,  2284,  2288,  2292,  2296,  2298,  2300,
    2302,  2304,  2305,  2309,  2311,  2312,  2316,  2319,  2320,  2324,
    2326,  2330,  2332,  2336,  2337,  2340,  2342,  2344,  2346,  2348,
    2350,  2352,  2354,  2356,  2358,  2360,  2362,  2364,  2366,  2368,
    2370,  2372,  2374,  2376,  2377,  2378,  2386,  2388,  2390,  2393,
    2396,  2399,  2403,  2408,  2409,  2413,  2414,  2416,  2418,  2421,
    2423,  2425,  2427,  2429,  2430,  2432,  2434,  2437,  2440,  2442,
    2444,  2446,  2448,  2450,  2452,  2454,  2456,  2458,  2460,  2462,
    2464,  2466,  2467,  2469,  2471,  2473,  2475,  2477,  2478,  2479,
    2480,  2481,  2495,  2497,  2498,  2499,  2506,  2509,  2511,  2514,
    2517,  2519,  2521,  2524,  2526,  2528,  2530,  2531,  2535,  2538,
    2540,  2541,  2542,  2543,  2558,  2559,  2565,  2567,  2568,  2572,
    2573,  2581,  2582,  2588,  2590,  2593,  2594,  2596,  2598,  2600,
    2601,  2603,  2605,  2608,  2611,  2614,  2616,  2618,  2620,  2622,
    2626,  2628,  2630,  2631,  2632,  2640,  2642,  2645,  2646,  2650,
    2651,  2656,  2659,  2660,  2663,  2665,  2667,  2669,  2671,  2673,
    2675,  2677,  2678,  2682,  2683,  2685,  2687,  2689,  2691,  2694,
    2697,  2700,  2706,  2708,  2710,  2712,  2717,  2722,  2724,  2726,
    2728,  2730,  2733,  2736,  2740,  2747,  2749,  2753,  2755,  2757,
    2759,  2763,  2770,  2772,  2774,  2776,  2778,  2781,  2782,  2784,
    2786,  2790,  2792,  2796,  2798,  2802,  2804,  2808,  2810,  2812,
    2814,  2816,  2820,  2822,  2826,  2828,  2832,  2834,  2836,  2838,
    2842,  2845,  2846,  2848,  2850,  2855,  2857,  2861,  2863,  2867,
    2875,  2876,  2884,  2885,  2892,  2896,  2898,  2902,  2904,  2907,
    2913,  2914,  2922,  2923,  2926,  2927,  2929,  2935,  2938,  2944,
    2945,  2951,  2958,  2963,  2964,  2966,  2968,  2973,  2974,  2977,
    2978,  2984,  2989,  2992,  2994,  2998,  3001,  3004,  3007,  3010,
    3013,  3016,  3018,  3021,  3024,  3027,  3030,  3033,  3036,  3039,
    3042,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3063,  3065,
    3067,  3070,  3075,  3077,  3078,  3089,  3095,  3096,  3098,  3099,
    3102,  3104,  3107,  3108,  3112,  3114,  3115,  3120,  3121,  3124,
    3126,  3130,  3132,  3134,  3138,  3143,  3148,  3151,  3153,  3155,
    3157,  3158,  3160,  3168,  3171,  3174,  3177,  3180,  3183,  3185,
    3188,  3189,  3193,  3194,  3198,  3199,  3203,  3204,  3208,  3209,
    3213,  3214,  3219,  3220,  3225,  3227,  3229,  3231,  3233,  3235,
    3237,  3238,  3243,  3244,  3246,  3247,  3252,  3254,  3257,  3260,
    3263,  3264,  3266,  3268,  3271,  3274,  3275,  3278,  3282,  3286,
    3292,  3293,  3296,  3301,  3303,  3305,  3307,  3309,  3311,  3312,
    3314,  3316,  3320,  3323,  3329,  3332,  3338,  3344,  3350,  3356,
    3362,  3368,  3369,  3372,  3374,  3377,  3380,  3383,  3386,  3389,
    3392,  3394,  3397,  3400,  3403,  3406,  3408,  3411,  3414,  3417,
    3420,  3422,  3424,  3426,  3427,  3430,  3433,  3436,  3439,  3442,
    3445,  3448,  3451,  3454,  3456,  3458,  3460,  3462,  3464,  3466,
    3468,  3470,  3473,  3476,  3479,  3482,  3485,  3487,  3489,  3491,
    3492,  3496,  3499,  3500,  3501,  3502,  3503,  3504,  3505,  3521,
    3522,  3525,  3528,  3529,  3531,  3532,  3533,  3534,  3535,  3536,
    3537,  3553,  3556,  3557,  3558,  3559,  3570,  3571,  3573,  3577,
    3581,  3584,  3589,  3593,  3597,  3601,  3603,  3605,  3607,  3609,
    3611,  3613,  3614,  3615,  3623,  3624,  3625,  3634,  3638,  3641,
    3642,  3644,  3646,  3650,  3653,  3656,  3658,  3660,  3664,  3666,
    3668,  3671,  3673,  3677,  3679,  3683,  3685,  3687,  3689,  3691,
    3693,  3695,  3697,  3700,  3705,  3707,  3711,  3713,  3717,  3720,
    3725,  3727,  3731,  3733,  3736,  3741,  3743,  3747,  3749,  3751,
    3753,  3756,  3759,  3764,  3767,  3772,  3774,  3778,  3780,  3782,
    3784,  3787,  3789,  3791,  3793,  3795,  3797,  3800,  3807,  3814,
    3815,  3817,  3818,  3820,  3823,  3825,  3826,  3832,  3833,  3839,
    3841,  3842,  3846,  3848,  3852,  3854,  3858,  3860,  3862,  3863,
    3864,  3870,  3873,  3875,  3876,  3877,  3881,  3882,  3883,  3887,
    3889,  3891,  3893,  3895,  3897,  3899,  3902,  3905,  3910,  3914,
    3918,  3920,  3924,  3927,  3929,  3931,  3932,  3934,  3936,  3938,
    3940,  3941,  3943,  3947,  3949,  3951,  3952,  3956,  3958,  3960,
    3962,  3964,  3966,  3968,  3970,  3972,  3974,  3976,  3978,  3980,
    3988,  3989,  3991,  3993,  3995,  3997,  4001,  4003,  4005,  4007,
    4010,  4011,  4015,  4017,  4021,  4023,  4027,  4029,  4031,  4038,
    4039,  4043,  4045,  4049,  4050,  4052,  4057,  4063,  4066,  4068,
    4070,  4075,  4077,  4081,  4086,  4091,  4093,  4097,  4099,  4101,
    4103,  4106,  4108,  4113,  4114,  4116,  4117,  4119,  4121,  4124,
    4126,  4128,  4130,  4132,  4137,  4141,  4143,  4145,  4147,  4150,
    4152,  4154,  4157,  4160,  4162,  4166,  4169,  4172,  4174,  4178,
    4180,  4183,  4188,  4190,  4193,  4195,  4199,  4204,  4205,  4207,
    4208,  4210,  4211,  4213,  4215,  4219,  4221,  4225,  4227,  4230,
    4232,  4236,  4239,  4242,  4243,  4246,  4248,  4250,  4252,  4258,
    4262,  4268,  4272,  4274,  4278,  4280,  4282,  4283,  4285,  4289,
    4293,  4297,  4304,  4309,  4314,  4320,  4322,  4324,  4326,  4328,
    4330,  4332,  4334,  4336,  4338,  4340,  4342,  4343,  4345,  4347,
    4349,  4351,  4353,  4355,  4357,  4362,  4368,  4370,  4376,  4382,
    4384,  4386,  4388,  4393,  4395,  4400,  4402,  4410,  4412,  4414,
    4416,  4421,  4428,  4429,  4432,  4437,  4439,  4441,  4443,  4445,
    4447,  4449,  4451,  4455,  4457,  4459,  4463,  4465,  4466,  4470,
    4476,  4478,  4481,  4484,  4489,  4493,  4495,  4497,  4499,  4501,
    4503,  4505,  4508,  4511,  4512,  4516,  4517,  4521,  4523,  4525,
    4527,  4529,  4531,  4533,  4535,  4540,  4542,  4544,  4546,  4548,
    4550,  4552,  4554,  4559,  4561,  4563,  4565,  4567,  4569,  4571,
    4573,  4575,  4577,  4579,  4581,  4583,  4585,  4587,  4589,  4591,
    4595,  4596,  4605,  4606,  4616,  4617,  4625,  4626,  4636,  4637,
    4639,  4642,  4644,  4648,  4650,  4654,  4660,  4662,  4664,  4666,
    4668,  4671,  4672,  4673,  4682,  4688,  4690,  4692,  4699,  4700,
    4704,  4706,  4710,  4715,  4717,  4718,  4721,  4726,  4733,  4734,
    4736,  4738,  4740,  4742,  4746,  4748,  4751,  4754,  4756,  4758,
    4761,  4764,  4766,  4768,  4770,  4773,  4778,  4782,  4785,  4789,
    4793,  4797,  4799,  4801,  4803,  4805,  4807,  4809,  4815,  4821,
    4827,  4833,  4839,  4844,  4849,  4853,  4858,  4860,  4864,  4865,
    4867,  4873,  4881,  4887,  4888,  4891,  4893,  4895,  4896,  4900,
    4902,  4906,  4908,  4910,  4912,  4913,  4917,  4919,  4921,  4923,
    4925,  4930,  4937,  4939,  4941,  4944,  4948,  4950,  4952,  4954,
    4956,  4958,  4960,  4962,  4964,  4970,  4976,  4981,  4982,  4987,
    4989,  4992,  4994,  4996,  4998,  5001,  5004,  5005,  5006,  5013,
    5014,  5017,  5020,  5028,  5032,  5036,  5039,  5042,  5045,  5047,
    5051,  5053,  5057,  5059,  5063,  5065,  5069,  5071,  5073,  5075,
    5078,  5081,  5083,  5085,  5088,  5093,  5095,  5097,  5099,  5101,
    5103,  5105,  5109,  5112,  5116,  5120,  5124,  5130,  5136,  5142,
    5148,  5154,  5159,  5164,  5168,  5173,  5175,  5177,  5181,  5183,
    5186,  5188,  5190,  5192,  5196,  5202,  5204,  5206,  5208,  5210,
    5214,  5217,  5220,  5223,  5225,  5228,  5231,  5233,  5236,  5239,
    5242,  5244,  5248,  5251,  5253,  5256,  5258,  5261,  5263,  5264,
    5265,  5272,  5273,  5276,  5277,  5279,  5281,  5284,  5287,  5289,
    5291,  5296,  5300,  5302,  5306,  5308,  5311,  5317,  5320,  5323,
    5329,  5330,  5333,  5335,  5337,  5340,  5347,  5354,  5356,  5357,
    5359,  5362,  5364,  5367,  5368,  5371,  5373,  5375,  5377,  5379,
    5381,  5383,  5385,  5387,  5389,  5391,  5393,  5395,  5397,  5399,
    5401,  5403,  5405,  5407,  5409,  5411,  5413,  5415,  5417,  5419,
    5421,  5423,  5425,  5427,  5429,  5431,  5433,  5435,  5437,  5439,
    5441,  5443,  5445,  5447,  5449,  5451,  5453,  5455,  5457,  5459,
    5461,  5463,  5465,  5467,  5469,  5471,  5473,  5475,  5477,  5479,
    5481,  5483,  5485,  5487,  5489,  5491,  5493,  5495,  5497,  5499,
    5501,  5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,  5519,
    5521,  5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,  5539
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1031,     0,    -1,   197,    -1,   194,    -1,   122,   671,   423,
     593,   672,    -1,   136,    -1,  1097,    -1,    25,    -1,   673,
      -1,   672,     5,   673,    -1,   935,    -1,   427,   674,   388,
      -1,   674,   675,   674,    -1,    25,    -1,   676,    25,    -1,
    1097,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   678,    -1,    -1,
     271,   427,   679,   680,   388,    -1,   566,   427,    25,     5,
      25,   388,    -1,   681,    -1,   680,     5,   681,    -1,   487,
      -1,   528,    -1,   534,    -1,   503,    -1,   406,    -1,   603,
      -1,   525,    -1,   477,    -1,   413,    -1,   488,    -1,   342,
      -1,   529,    -1,   452,    -1,   329,    -1,   591,    -1,    96,
      -1,  1008,    -1,    -1,   683,    -1,    -1,   271,   427,   684,
     685,   388,    -1,   686,    -1,   685,     5,   686,    -1,   681,
      -1,   428,    -1,   601,    24,    -1,   200,   922,    -1,   326,
     922,    -1,   281,   922,    -1,   334,   922,    -1,   290,   922,
      -1,   256,   922,    -1,   531,   688,    -1,   867,   341,  1097,
      -1,    -1,   286,   427,  1484,   388,   341,   689,  1116,    -1,
     102,   427,   935,     5,    24,     5,    24,   388,    -1,   403,
     427,   927,   388,   341,  1097,    -1,  1234,    -1,   189,   427,
     886,   388,   341,  1097,    -1,    -1,    -1,  1097,   587,   935,
     427,   690,   704,   388,   691,   702,    -1,    -1,    -1,    -1,
     935,   427,   692,   704,   693,   388,   694,   702,    -1,    -1,
      -1,   471,  1431,   621,  1431,   427,   695,   704,   696,   388,
     702,    -1,    -1,    -1,   935,   518,   935,   427,   697,   704,
     698,   388,   702,    -1,    -1,    -1,    -1,   362,   707,   587,
     708,   455,   671,   423,   427,   699,   704,   700,   388,   701,
     703,    -1,    -1,   341,  1116,    -1,    -1,   341,  1116,    -1,
     160,    -1,    -1,   705,    -1,   706,    -1,   705,     5,   706,
      -1,   836,    -1,    24,    -1,   935,    -1,   935,    -1,   935,
     618,   935,    -1,    -1,   532,   843,   710,   713,   717,   714,
      -1,    -1,   532,   711,   712,   715,   714,    -1,   719,    -1,
     712,   719,    -1,   721,    -1,   713,   721,    -1,   357,    -1,
      -1,    -1,   336,   716,  1494,    -1,    -1,    -1,   336,   718,
    1494,    -1,    -1,   576,   843,   720,  1494,    -1,    -1,   576,
     843,   722,  1494,    -1,   275,   932,    -1,   199,   930,    -1,
      81,   930,    -1,   166,    -1,   182,  1437,    -1,   491,   929,
      -1,    29,   725,    30,    -1,   726,    -1,   728,    -1,   727,
      -1,   726,   727,    -1,    28,    -1,   729,    -1,   728,   729,
      -1,    27,    -1,   390,    -1,    -1,    -1,   317,   732,   734,
     733,   735,    -1,   381,  1097,   623,   736,   976,  1007,   677,
      -1,  1097,   623,   736,   976,   544,  1484,  1007,   677,    -1,
      -1,   738,   188,    -1,   737,    -1,   736,     5,   737,    -1,
     935,    -1,   935,   618,   935,    -1,   935,   618,    20,    -1,
     739,    -1,   738,   739,    -1,    -1,   267,   745,   740,  1494,
      -1,    -1,   270,   746,   741,  1494,    -1,    -1,  1010,   742,
    1494,    -1,    -1,   164,   743,  1494,    -1,    -1,   161,   744,
    1494,    -1,   939,    -1,   745,     5,   939,    -1,   939,    -1,
     746,     5,   939,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,   427,   836,   749,   388,
      -1,    -1,     5,   790,   624,   793,    -1,   153,    -1,   276,
      -1,    -1,   752,    -1,   753,    -1,   752,   753,    -1,    -1,
      -1,   434,   754,   756,   755,  1203,    -1,   803,    -1,  1474,
      -1,   759,    -1,   756,     5,   759,    -1,    -1,   758,   935,
      -1,   350,   757,   802,    24,    -1,   350,   757,   802,   935,
      -1,   350,   757,   802,   941,    -1,   350,   757,   802,    25,
      -1,   763,   779,    -1,    -1,   757,   350,   760,   761,    -1,
      25,    -1,    24,    -1,   941,    -1,    18,    25,    -1,   757,
      -1,   762,    -1,   763,     5,   762,    -1,    -1,   533,    -1,
      -1,   484,   455,   771,   423,   766,   622,   779,    -1,    -1,
     315,   764,   768,    25,   769,   299,   455,   770,   423,   767,
     622,   779,    -1,   427,    -1,   454,    -1,   388,    -1,   422,
      -1,    25,    -1,   772,     5,   772,     5,   772,    -1,   772,
       5,   772,    -1,   772,    -1,    25,    -1,    -1,   460,   774,
     756,   280,    -1,    -1,   257,   775,   757,   618,    20,    -1,
      -1,   331,   776,   757,   255,   427,   777,   388,    -1,   778,
      -1,   777,     5,   778,    -1,   757,    -1,   781,    -1,    -1,
      56,    -1,    -1,    -1,   782,   784,   783,   780,    -1,   765,
      -1,   773,    -1,   533,    -1,   533,   427,    25,   388,    -1,
     420,   427,    25,   388,    -1,   420,   427,    25,     5,    25,
     388,    -1,   404,    -1,   615,   757,    -1,   376,    -1,   506,
      -1,    87,    -1,   394,    -1,   394,   427,    25,   388,    -1,
     394,   427,    25,     5,    25,   388,    -1,   509,    -1,   509,
     427,    25,   388,    -1,   509,   427,    25,     5,    25,   388,
      -1,   499,    -1,   296,    -1,   535,    -1,   530,    -1,    78,
      -1,    79,    -1,   572,    -1,   354,   788,    -1,   366,   789,
      -1,   785,    -1,    31,    -1,   554,   786,   618,   787,    -1,
     757,    -1,   757,    -1,    -1,   790,   624,   793,    -1,   798,
     624,   801,    -1,    -1,   791,   792,    -1,   579,    -1,   510,
      -1,   588,    -1,   550,    -1,   450,    -1,   467,    -1,   363,
     795,    -1,    -1,   794,   792,    -1,    -1,   427,   797,   388,
      -1,    -1,   427,    25,   388,    -1,    25,    -1,    -1,   799,
     800,   796,    -1,   579,    -1,   510,    -1,   588,    -1,   550,
      -1,   450,    -1,   467,    -1,   363,   795,    -1,   800,    -1,
      -1,    13,    -1,    -1,   233,   935,   804,   615,   805,    -1,
     807,    -1,   810,    -1,   533,    -1,   533,   427,    25,   388,
      -1,   420,   427,    25,   388,    -1,   420,   427,    25,     5,
      25,   388,    -1,   404,    -1,   376,    -1,   506,    -1,   394,
      -1,   394,   427,    25,   388,    -1,   394,   427,    25,     5,
      25,   388,    -1,   509,    -1,   509,   427,    25,   388,    -1,
     509,   427,    25,     5,    25,   388,    -1,   499,    -1,   296,
      -1,   535,    -1,   530,    -1,   572,    -1,   354,   788,    -1,
     366,   789,    -1,   806,    -1,   554,   786,   618,   787,    -1,
      -1,   484,   455,   771,   423,   808,   622,   805,    -1,    -1,
     315,   764,   768,    25,   769,   299,   455,   770,   423,   809,
     622,   805,    -1,    -1,   460,   811,   813,   280,    -1,    -1,
     257,   812,   935,   618,    20,    -1,   814,    -1,   813,     5,
     814,    -1,   815,   805,    -1,   816,    -1,   815,     5,   816,
      -1,   935,    -1,    -1,   616,   926,    -1,    68,   935,    -1,
      66,    -1,   624,  1484,    -1,   624,   506,   935,   657,  1484,
      -1,   624,   506,   935,   386,    -1,    70,   935,    -1,   154,
     861,  1116,   825,    -1,   397,   861,   841,   817,   825,    -1,
     206,   932,   825,    -1,    -1,    -1,   185,   822,  1123,   624,
     935,   618,    20,   824,   677,   823,   826,    -1,    -1,   465,
     927,    -1,   677,    -1,    -1,   827,   235,    -1,   828,    -1,
     827,   828,    -1,    -1,   348,   829,  1494,    -1,    -1,   344,
     830,  1494,    -1,    -1,  1010,   831,  1494,    -1,   495,   861,
     842,   677,    -1,   495,   861,   842,   677,    63,    -1,   283,
      -1,   282,    -1,   209,    -1,   361,    -1,   171,    -1,   208,
      -1,   325,    -1,   324,    -1,   240,    -1,   168,    -1,   167,
      -1,   142,    -1,   201,    -1,   125,    -1,   141,    -1,   184,
      -1,   151,    -1,   210,    -1,   210,   843,    -1,   846,    -1,
     845,    -1,   850,    -1,   878,    -1,   836,   837,    -1,   879,
      -1,   881,    -1,   847,    -1,    18,   836,    -1,    17,   836,
      -1,   852,    -1,   860,    -1,   854,    -1,   472,    -1,   747,
      -1,   855,    -1,   856,    -1,   857,    -1,   858,    -1,   859,
      -1,   861,    -1,   861,   840,    -1,   843,    -1,   480,    -1,
     839,    -1,   840,     5,   839,    -1,   843,    -1,   841,     5,
     843,    -1,   843,    -1,   842,     5,   843,    -1,   836,    -1,
      17,    -1,    18,    -1,   600,   836,    -1,   481,    -1,   424,
      -1,   427,   836,   388,    -1,   439,   427,  1411,   388,    -1,
     291,   427,  1411,   388,    -1,   844,   941,    -1,   844,    25,
      -1,    24,    -1,   941,    -1,    25,    -1,   849,    -1,  1097,
      -1,  1097,   417,  1097,    -1,   848,    -1,   430,   836,    -1,
     389,   836,    -1,  1206,    -1,    -1,   504,   851,  1206,    -1,
       7,   836,    -1,     6,   836,    -1,   836,    -1,   853,     5,
     836,    -1,   621,   427,  1411,   388,    -1,   425,   427,  1411,
     388,    -1,   621,   427,   861,   853,   388,    -1,   425,   427,
     861,   853,   388,    -1,   383,    -1,   246,    -1,     9,   836,
      -1,   249,   836,    -1,     9,   836,   438,    24,    -1,   249,
     836,   438,    24,    -1,   554,   836,    -1,   368,   836,    -1,
     554,   836,   438,    24,    -1,   368,   836,   438,    24,    -1,
     387,    -1,     8,   836,    -1,    17,   836,    -1,    18,   836,
      -1,    20,   836,    -1,    19,   836,    -1,    21,   836,    -1,
      10,   836,    -1,    13,   836,    -1,   453,   836,    -1,    11,
     836,    -1,    12,   836,    -1,    16,   836,    -1,    15,   836,
      -1,    14,   836,    -1,    -1,    -1,    -1,   935,   427,   863,
     704,   864,   388,    -1,    -1,    -1,   935,   518,   935,   427,
     865,   704,   866,   388,    -1,    -1,    -1,   535,   427,   868,
     836,   869,   388,    -1,    -1,    -1,   510,   427,   870,   836,
     871,   388,    -1,    -1,    -1,   588,   427,   872,   836,   873,
     388,    -1,    -1,    -1,   579,   427,   874,   836,   875,   388,
      -1,   366,   427,   882,   388,   877,    -1,   354,   427,    24,
     388,   876,    -1,   354,   427,    25,   388,   876,    -1,   354,
     427,    25,   587,    25,   388,   876,    -1,    -1,  1391,   624,
    1392,    -1,   789,    -1,   867,    -1,   286,   427,  1484,   388,
      -1,    97,   427,   927,   388,    -1,    69,   427,   927,   388,
      -1,   403,   427,   927,   388,    -1,   189,   427,   886,   388,
      -1,    57,   427,   886,   388,    -1,   880,    -1,   862,    -1,
    1387,    -1,   535,    -1,   419,   427,   836,   388,    -1,   319,
     427,   836,   388,    -1,   485,   836,    -1,   440,   748,    -1,
     836,   106,    -1,   836,   107,    -1,   836,   108,    -1,    24,
      -1,   883,    -1,    18,   883,    -1,   885,    -1,   884,    -1,
      25,    -1,    25,    25,    -1,    25,    25,   587,    25,    -1,
      25,    25,   587,    25,   587,    25,    -1,    25,    25,   587,
      25,   587,    23,    -1,    25,   587,    25,    -1,    25,   587,
      25,   587,    25,    -1,    25,   587,    25,   587,    23,    -1,
      25,   587,    23,    -1,    23,    -1,    25,    -1,    25,    18,
      25,    -1,   927,    -1,   886,     5,   927,    -1,    -1,    -1,
     593,  1097,    13,   843,   624,   843,   890,   888,  1494,   889,
     238,    -1,    -1,   569,   843,    -1,    -1,    -1,    -1,   400,
     892,   929,   893,  1292,   894,  1494,   237,    -1,    -1,    -1,
     636,   935,   896,   751,   897,  1041,   899,   898,   904,   637,
      -1,    -1,   909,    -1,    -1,   900,    -1,   901,    -1,   900,
     901,    -1,    -1,   638,   902,  1494,    -1,    -1,   639,   903,
    1494,    -1,    -1,   905,    -1,   906,    -1,   905,   906,    -1,
      -1,   640,   907,  1494,    -1,    -1,   641,   908,  1494,    -1,
     910,   914,   321,    -1,    89,    -1,    89,   911,   544,   912,
      -1,    89,   381,   913,    -1,  1097,    -1,   911,     5,  1097,
      -1,   935,    -1,   912,     5,   935,    -1,  1097,    -1,   913,
       5,  1097,    -1,   915,    -1,   914,   915,    -1,    -1,   642,
     916,  1494,    -1,    -1,   643,   917,  1494,    -1,    -1,   662,
     912,   918,  1494,    -1,    -1,   478,   912,   919,  1494,    -1,
      -1,   623,   912,   920,  1494,    -1,   543,   928,    -1,   552,
      18,    25,    -1,   552,    -1,   498,    17,    25,    -1,   498,
      -1,    25,    -1,  1097,    -1,    24,    -1,   940,    -1,   843,
      -1,   924,     5,   924,    -1,   925,    -1,   935,    -1,   665,
     427,   935,   388,    -1,   935,   618,   665,   427,   935,   388,
      -1,   935,   455,   674,   423,    -1,   935,   618,    20,    -1,
     935,   455,   674,   423,   618,    20,    -1,   935,   618,   935,
      -1,   935,   455,   674,   423,   618,   935,    -1,   936,    -1,
     936,    -1,   936,    -1,   936,    -1,   936,    -1,   936,    -1,
      -1,   548,    25,    -1,  1493,    -1,   937,    -1,  1493,    -1,
     346,   427,   938,   388,    -1,  1100,    -1,    24,    -1,   935,
      -1,   935,   455,   674,   423,    -1,   935,   618,    20,    -1,
     935,   455,   674,   423,   618,    20,    -1,   935,   618,   935,
      -1,   935,   455,   674,   423,   618,   935,    -1,  1097,    -1,
      23,    -1,   618,    25,    -1,   370,    -1,   489,    -1,   490,
      -1,   387,    -1,   491,    -1,   350,    -1,   317,    -1,   493,
      -1,   456,    -1,   534,    -1,   445,    -1,   589,    -1,   393,
      -1,   486,    -1,   479,    -1,   557,    -1,   396,    -1,   355,
      -1,   494,    -1,   318,    -1,   536,    -1,   277,    -1,   591,
      -1,   653,    -1,   537,    -1,   319,    -1,   539,    -1,   401,
      -1,   439,    -1,   579,    -1,   510,    -1,   588,    -1,   472,
      -1,   375,    -1,   390,    -1,   435,    -1,   377,    -1,   438,
      -1,   419,    -1,   384,    -1,   342,    -1,   556,    -1,   535,
      -1,   545,  1476,    -1,   650,   945,    -1,   946,    -1,   945,
       5,   946,    -1,   935,    -1,   661,   945,    -1,   652,   945,
      -1,   653,  1484,    -1,   651,   932,   657,  1484,    -1,   655,
     945,    -1,   656,  1484,    -1,   654,   932,   657,  1484,    -1,
      -1,   659,   951,   841,   956,   958,   960,   952,   954,    -1,
      -1,   953,    -1,   647,    -1,   648,    -1,    -1,   955,    -1,
     341,  1097,    -1,    -1,   957,    -1,   386,   841,    -1,    -1,
     959,    -1,   658,    25,    -1,    -1,   961,    -1,   649,    25,
     962,    -1,    -1,   396,    25,    -1,    -1,   620,   843,   573,
     964,  1494,   965,   437,    -1,    -1,    -1,   540,   966,  1494,
      -1,    -1,    -1,    60,   967,   843,   573,   968,  1494,   965,
      -1,   104,   935,   427,    25,   388,    -1,    53,   935,    -1,
      73,   935,    -1,    -1,   287,  1128,   972,   624,   480,    -1,
     287,  1128,   554,   973,    -1,   974,    -1,   973,     5,   974,
      -1,   786,   618,  1383,    -1,   786,   618,    20,    -1,    -1,
     977,   321,    -1,    -1,   148,    -1,   978,    -1,   977,   978,
      -1,    -1,   267,   996,   979,  1494,    -1,    -1,   270,   997,
     980,  1494,    -1,    -1,   348,   981,  1494,    -1,    -1,   344,
     982,  1494,    -1,    -1,  1010,   983,  1494,    -1,    -1,   302,
     984,  1494,    -1,    -1,   272,   985,  1494,    -1,    -1,   662,
     994,   986,  1494,    -1,    -1,   478,   992,   987,  1494,    -1,
      -1,    34,   988,  1494,    -1,    -1,    33,   989,  1494,    -1,
      -1,    36,   990,  1494,    -1,    -1,    35,   991,  1494,    -1,
     993,    -1,   992,     5,   993,    -1,   446,    -1,   435,    -1,
     995,    -1,   994,     5,   995,    -1,   446,    -1,   435,    -1,
     927,    -1,   996,     5,   927,    -1,   927,    -1,   997,     5,
     927,    -1,   311,  1000,    -1,   312,   935,   657,  1000,    -1,
     559,    -1,   371,    -1,   927,    -1,    -1,   663,  1003,  1002,
     975,    -1,   381,  1116,   976,   934,   677,    -1,  1116,   976,
     544,  1484,   934,   677,    -1,    -1,   484,  1123,   976,   544,
     935,   618,    20,   934,  1004,   677,    -1,   466,  1484,  1006,
      -1,   625,    -1,   537,    -1,    74,    25,    -1,    80,    25,
      -1,    -1,   548,    25,    -1,  1009,    -1,    41,    24,    -1,
     493,    13,    25,    -1,   493,    13,  1097,    -1,    42,    13,
      25,    -1,    42,    13,  1097,    -1,    38,    -1,    40,    -1,
      37,    -1,    39,    -1,    -1,   426,  1011,  1017,    -1,   292,
      -1,    -1,   594,  1013,  1017,    -1,   300,  1019,    -1,    -1,
     594,  1016,  1017,    -1,  1019,    -1,   427,  1018,   388,    -1,
    1019,    -1,  1018,     5,  1019,    -1,    -1,  1020,  1021,    -1,
     592,    -1,   309,    -1,   327,    -1,   301,    -1,   482,    -1,
     438,    -1,   625,    -1,   548,    -1,   537,    -1,   462,    -1,
     435,    -1,   538,    -1,   553,    -1,   517,    -1,   307,    -1,
     308,    -1,    24,    -1,   507,    -1,    -1,    -1,   596,  1024,
    1121,  1025,    13,   861,  1026,    -1,   480,    -1,   842,    -1,
     216,  1097,    -1,   205,  1097,    -1,   219,  1097,    -1,   447,
    1097,   330,    -1,   447,  1097,   382,   923,    -1,    -1,  1033,
    1032,  1036,    -1,    -1,  1034,    -1,  1035,    -1,  1034,  1035,
      -1,   970,    -1,  1040,    -1,  1056,    -1,  1042,    -1,    -1,
    1037,    -1,  1039,    -1,  1037,  1039,    -1,    64,   935,    -1,
    1044,    -1,  1050,    -1,  1062,    -1,  1216,    -1,  1226,    -1,
    1083,    -1,  1474,    -1,   895,    -1,   724,    -1,   969,    -1,
     730,    -1,   724,    -1,  1474,    -1,    -1,   724,    -1,  1474,
      -1,   752,    -1,   364,    -1,    58,    -1,    -1,    -1,    -1,
      -1,  1043,  1045,   935,   427,  1046,  1114,   388,  1047,   751,
    1048,  1041,  1494,  1049,    -1,   207,    -1,    -1,    -1,   555,
    1051,   751,  1052,  1494,   358,    -1,   462,   838,    -1,   861,
      -1,   861,   841,    -1,   353,  1395,    -1,  1057,    -1,  1058,
      -1,  1057,  1058,    -1,  1059,    -1,  1040,    -1,  1055,    -1,
      -1,   402,  1060,  1061,    -1,   751,   239,    -1,   923,    -1,
      -1,    -1,    -1,   111,   935,   110,   935,   427,  1063,  1114,
     388,  1064,   751,  1065,  1041,  1494,  1049,    -1,    -1,   556,
    1067,  1082,  1073,  1068,    -1,   359,    -1,    -1,   231,  1070,
    1494,    -1,    -1,    22,  1074,  1075,  1076,   934,  1071,  1494,
      -1,    -1,    22,  1074,   934,  1072,  1494,    -1,  1069,    -1,
    1073,  1069,    -1,    -1,  1012,    -1,    24,    -1,  1097,    -1,
      -1,  1097,    -1,    24,    -1,   248,  1080,    -1,   260,  1081,
      -1,   243,  1081,    -1,   583,    -1,    24,    -1,  1097,    -1,
    1080,    -1,  1081,     5,  1080,    -1,  1097,    -1,    24,    -1,
      -1,    -1,   644,   935,  1084,   751,  1085,  1086,   645,    -1,
    1087,    -1,  1086,  1087,    -1,    -1,   646,  1088,  1494,    -1,
      -1,   623,   935,  1089,  1494,    -1,  1093,  1091,    -1,    -1,
     678,  1095,    -1,  1096,    -1,  1092,    -1,   957,    -1,   959,
      -1,   961,    -1,   953,    -1,   955,    -1,    -1,   367,  1094,
     842,    -1,    -1,    63,    -1,    63,    -1,  1098,    -1,  1100,
      -1,   187,  1100,    -1,  1100,   618,    -1,  1099,  1104,    -1,
    1099,   935,   455,  1108,   423,    -1,  1105,    -1,   935,    -1,
    1101,    -1,   935,   454,  1103,   422,    -1,   935,   454,  1103,
     422,    -1,  1097,    -1,    24,    -1,    20,    -1,   935,    -1,
     935,  1107,    -1,   935,  1107,    -1,   455,  1108,   423,    -1,
     455,  1108,   423,   455,  1108,   423,    -1,  1109,    -1,  1108,
       5,  1109,    -1,   674,    -1,  1111,    -1,  1113,    -1,  1111,
     618,  1112,    -1,  1111,   618,   935,   455,  1108,   423,    -1,
     935,    -1,  1102,    -1,    20,    -1,   935,    -1,   935,  1107,
      -1,    -1,  1115,    -1,  1117,    -1,  1115,     5,  1117,    -1,
    1118,    -1,  1116,     5,  1118,    -1,   935,    -1,   935,   618,
     935,    -1,  1097,    -1,  1097,   417,  1097,    -1,    24,    -1,
     941,    -1,    25,    -1,  1120,    -1,  1119,     5,  1120,    -1,
    1097,    -1,  1097,   417,  1097,    -1,  1122,    -1,  1121,     5,
    1122,    -1,  1110,    -1,  1097,    -1,  1125,    -1,  1124,     5,
    1125,    -1,  1097,  1126,    -1,    -1,   585,    -1,   536,    -1,
     935,   455,  1108,   423,    -1,  1129,    -1,  1128,     5,  1129,
      -1,  1097,    -1,  1097,   417,  1097,    -1,   251,   931,   616,
     925,   577,  1486,   682,    -1,    -1,   616,   427,   843,     5,
     843,   388,  1132,    -1,    -1,   566,   427,   843,     5,   843,
     388,    -1,   252,   935,  1131,    -1,   935,    -1,   335,   933,
    1136,    -1,  1137,    -1,   544,   843,    -1,  1138,  1139,  1144,
       8,  1134,    -1,    -1,   616,  1140,   427,   843,     5,   843,
     388,    -1,    -1,   554,   936,    -1,    -1,   347,    -1,   214,
    1437,   263,  1469,  1143,    -1,   561,   928,    -1,   561,   928,
       8,   861,   841,    -1,    -1,   615,   574,  1431,   370,  1431,
      -1,   615,   574,  1431,     5,   370,  1431,    -1,   615,  1431,
       5,  1431,    -1,    -1,   647,    -1,   648,    -1,    88,  1469,
    1146,  1147,    -1,    -1,   615,  1469,    -1,    -1,   615,   574,
    1431,     8,  1431,    -1,   574,  1431,     8,  1431,    -1,   408,
    1149,    -1,  1150,    -1,  1149,     5,  1150,    -1,   200,   922,
      -1,   281,   922,    -1,   326,   922,    -1,   334,   922,    -1,
     290,   922,    -1,   256,   922,    -1,  1014,    -1,   435,  1015,
      -1,   446,  1015,    -1,   559,  1015,    -1,   371,  1015,    -1,
     548,  1015,    -1,   546,   923,    -1,   547,   923,    -1,   397,
     678,    -1,   663,   678,    -1,   288,    -1,   192,    -1,   149,
      -1,   126,    -1,   144,    -1,   135,    -1,  1436,   410,  1154,
     544,  1152,    -1,  1097,    -1,    24,    -1,   399,  1154,    -1,
     399,  1154,     8,  1116,    -1,   936,    -1,    -1,   458,  1163,
     677,   593,  1158,  1097,   934,   677,  1156,  1159,    -1,   458,
    1163,   677,   341,  1097,    -1,    -1,   533,    -1,    -1,  1160,
     279,    -1,  1161,    -1,  1160,  1161,    -1,    -1,  1010,  1162,
    1494,    -1,   842,    -1,    -1,   602,   928,  1165,  1166,    -1,
      -1,   544,  1167,    -1,  1168,    -1,  1167,     5,  1168,    -1,
    1423,    -1,   480,    -1,   217,  1171,    86,    -1,   217,  1171,
     624,  1170,    -1,   217,  1171,    85,  1170,    -1,   217,  1171,
      -1,    24,    -1,   940,    -1,   935,    -1,    -1,   476,    -1,
     143,  1171,  1172,   427,   861,  1054,   388,    -1,   190,  1171,
      -1,    65,  1171,    -1,  1207,  1215,    -1,   443,    59,    -1,
     443,  1178,    -1,  1179,    -1,  1178,  1179,    -1,    -1,   131,
    1180,  1494,    -1,    -1,   196,  1181,  1494,    -1,    -1,   225,
    1182,  1494,    -1,    -1,   213,  1183,  1494,    -1,    -1,   250,
    1184,  1494,    -1,    -1,   198,  1097,  1185,  1494,    -1,    -1,
     221,  1097,  1186,  1494,    -1,  1197,    -1,  1199,    -1,  1198,
      -1,  1188,    -1,  1224,    -1,  1191,    -1,    -1,   558,   843,
    1189,   479,    -1,    -1,   479,    -1,    -1,   567,   843,  1192,
    1190,    -1,   156,    -1,   627,  1211,    -1,   159,  1211,    -1,
     158,  1211,    -1,    -1,  1194,    -1,  1195,    -1,  1194,  1195,
      -1,  1204,  1196,    -1,    -1,   616,  1211,    -1,   516,  1193,
    1203,    -1,   515,  1431,  1203,    -1,   514,  1202,  1201,  1200,
    1203,    -1,    -1,   150,   836,    -1,   150,   836,     5,   836,
      -1,   611,    -1,   612,    -1,   613,    -1,   614,    -1,  1097,
      -1,    -1,   519,    -1,  1205,    -1,  1204,     5,  1205,    -1,
     843,  1238,    -1,   607,   427,   836,   388,  1223,    -1,    62,
    1223,    -1,   493,   427,    20,   388,  1223,    -1,   409,   427,
      20,   388,  1223,    -1,   384,   427,   836,   388,  1223,    -1,
     586,   427,   836,   388,  1223,    -1,   599,   427,   836,   388,
    1223,    -1,   598,   427,   836,   388,  1223,    -1,    -1,   457,
    1208,    -1,  1209,    -1,  1208,  1209,    -1,   224,    25,    -1,
     215,    25,    -1,   298,    25,    -1,   181,    25,    -1,   253,
      25,    -1,   173,    -1,   340,    24,    -1,   340,  1097,    -1,
     174,    24,    -1,   157,    24,    -1,  1214,    -1,  1210,  1214,
      -1,  1212,   106,    -1,  1212,   108,    -1,  1212,   107,    -1,
    1212,    -1,   941,    -1,    25,    -1,    -1,   457,  1210,    -1,
     224,  1211,    -1,   215,  1211,    -1,   298,  1211,    -1,   181,
    1211,    -1,   253,  1211,    -1,   254,  1211,    -1,   626,    24,
      -1,   627,  1211,    -1,   631,    -1,   628,    -1,   629,    -1,
     630,    -1,   635,    -1,   632,    -1,   633,    -1,   634,    -1,
      75,  1211,    -1,    76,  1211,    -1,    77,  1211,    -1,   340,
      24,    -1,   174,    24,    -1,   396,    -1,    71,    -1,    72,
      -1,    -1,   511,   617,  1124,    -1,   132,  1124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   461,  1217,   935,   427,  1218,
    1114,   388,  1219,   751,  1220,  1176,  1221,  1177,  1222,   236,
      -1,    -1,   523,   836,    -1,   513,  1225,    -1,    -1,  1152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,  1227,   935,
     427,  1228,  1114,   388,  1229,   751,  1230,  1233,  1231,  1177,
    1232,   236,    -1,  1213,  1215,    -1,    -1,    -1,    -1,   152,
     427,    24,     5,  1235,   704,  1236,   388,  1237,   702,    -1,
      -1,   380,    -1,   380,   215,    25,    -1,   380,   215,  1097,
      -1,   605,   843,    -1,   605,   843,   341,  1097,    -1,   605,
     843,   160,    -1,   605,   843,   575,    -1,   605,   843,   542,
      -1,  1241,    -1,   170,    -1,   320,    -1,   278,    -1,  1248,
      -1,  1243,    -1,    -1,    -1,   203,  1244,  1380,   427,  1245,
    1252,   388,    -1,    -1,    -1,   129,  1246,  1380,   427,  1247,
    1252,   388,  1249,    -1,   101,  1250,   388,    -1,    52,   936,
      -1,    -1,   265,    -1,  1251,    -1,  1250,     5,  1251,    -1,
     935,   585,    -1,   935,   536,    -1,   935,    -1,  1253,    -1,
    1252,     5,  1253,    -1,  1333,    -1,  1331,    -1,   118,   935,
      -1,   176,    -1,    43,   935,  1256,    -1,  1257,    -1,  1256,
       5,  1257,    -1,  1258,    -1,  1261,    -1,  1264,    -1,  1269,
      -1,  1270,    -1,  1268,    -1,  1267,    -1,   582,  1259,    -1,
     582,   427,  1260,   388,    -1,  1253,    -1,  1253,   662,   935,
      -1,  1259,    -1,  1260,     5,  1259,    -1,   539,  1263,    -1,
     539,   427,  1262,   388,    -1,  1263,    -1,  1262,     5,  1263,
      -1,   935,    -1,   451,  1266,    -1,   451,   427,  1265,   388,
      -1,  1266,    -1,  1265,     5,  1266,    -1,  1253,    -1,    83,
      -1,    84,    -1,    82,    25,    -1,    54,  1337,    -1,    54,
     427,  1271,   388,    -1,    55,  1272,    -1,    55,   427,  1271,
     388,    -1,  1337,    -1,  1271,     5,  1337,    -1,   935,    -1,
     262,    -1,   228,    -1,   162,  1275,    -1,   139,    -1,   127,
      -1,   117,    -1,   115,    -1,   119,    -1,   175,  1437,    -1,
     227,  1274,   456,  1431,   624,  1431,    -1,   295,   928,   456,
    1431,   624,  1431,    -1,    -1,  1437,    -1,    -1,   843,    -1,
     520,   843,    -1,   226,    -1,    -1,   245,  1279,  1380,  1282,
    1280,    -1,    -1,   476,  1281,   427,  1284,   388,    -1,  1417,
      -1,    -1,   427,  1283,   388,    -1,  1383,    -1,  1283,     5,
    1383,    -1,  1285,    -1,  1284,     5,  1285,    -1,  1423,    -1,
     480,    -1,    -1,    -1,   497,  1287,  1289,  1288,  1290,    -1,
    1294,   929,    -1,   929,    -1,    -1,    -1,   551,  1291,  1119,
      -1,    -1,    -1,   551,  1293,  1119,    -1,   498,    -1,   552,
      -1,   559,    -1,   371,    -1,   338,    -1,   392,    -1,   374,
     843,    -1,   347,   843,    -1,   234,  1380,   147,   929,    -1,
     234,  1380,  1353,    -1,   511,   617,  1298,    -1,  1299,    -1,
    1298,     5,  1299,    -1,  1300,  1301,    -1,    25,    -1,  1383,
      -1,    -1,   585,    -1,   536,    -1,   273,    -1,   306,    -1,
      -1,   323,    -1,   353,  1306,  1304,    -1,  1469,    -1,    24,
      -1,    -1,  1436,  1308,  1309,    -1,  1338,    -1,  1342,    -1,
    1303,    -1,  1438,    -1,  1302,    -1,  1295,    -1,  1296,    -1,
    1286,    -1,  1278,    -1,  1277,    -1,  1407,    -1,  1453,    -1,
     502,  1312,   623,  1380,   624,  1317,  1311,    -1,    -1,   138,
      -1,   165,    -1,  1313,    -1,  1314,    -1,  1313,     5,  1314,
      -1,   468,    -1,   446,    -1,   435,    -1,   475,  1315,    -1,
      -1,   427,  1316,   388,    -1,  1383,    -1,  1316,     5,  1383,
      -1,  1318,    -1,  1317,     5,  1318,    -1,   459,    -1,  1381,
      -1,   232,  1380,  1320,   615,  1417,  1322,    -1,    -1,   427,
    1321,   388,    -1,  1383,    -1,  1321,     5,  1383,    -1,    -1,
     137,    -1,   489,   427,  1356,   388,    -1,   242,   427,  1326,
     388,  1325,    -1,   293,  1327,    -1,  1328,    -1,  1380,    -1,
    1380,   427,  1328,   388,    -1,  1383,    -1,  1328,     5,  1383,
      -1,   473,   427,  1330,   388,    -1,   255,   427,  1330,   388,
      -1,  1383,    -1,  1330,     5,  1383,    -1,  1329,    -1,  1324,
      -1,  1323,    -1,   396,  1386,    -1,   204,    -1,   935,  1372,
    1334,  1335,    -1,    -1,  1332,    -1,    -1,  1336,    -1,  1337,
      -1,  1336,  1337,    -1,   369,    -1,   155,    -1,   473,    -1,
    1325,    -1,   489,   427,  1356,   388,    -1,   116,  1339,  1341,
      -1,  1340,    -1,  1381,    -1,  1342,    -1,  1341,  1342,    -1,
    1319,    -1,  1310,    -1,   444,  1356,    -1,   365,  1345,    -1,
    1422,    -1,  1345,     5,  1422,    -1,   523,  1356,    -1,   544,
    1348,    -1,  1349,    -1,  1348,     5,  1349,    -1,  1350,    -1,
     512,  1350,    -1,   512,   427,  1351,   388,    -1,  1380,    -1,
    1380,  1385,    -1,  1349,    -1,  1351,     5,  1349,    -1,  1347,
    1353,  1354,  1355,    -1,    -1,  1346,    -1,    -1,  1344,    -1,
      -1,  1343,    -1,  1357,    -1,  1356,     6,  1357,    -1,  1358,
      -1,  1357,     7,  1358,    -1,  1359,    -1,   600,  1359,    -1,
    1370,    -1,   427,  1356,   388,    -1,   439,  1418,    -1,   291,
    1418,    -1,    -1,   438,  1363,    -1,  1427,    -1,   935,    -1,
    1427,    -1,  1423,   621,   427,  1365,   388,    -1,  1423,   621,
    1418,    -1,  1423,   425,   427,  1365,   388,    -1,  1423,   425,
    1418,    -1,  1366,    -1,  1365,     5,  1366,    -1,  1473,    -1,
    1386,    -1,    -1,   600,    -1,  1423,  1367,   383,    -1,  1423,
    1367,   246,    -1,  1423,  1369,  1423,    -1,  1423,  1367,   385,
    1423,     7,  1423,    -1,  1423,   554,  1362,  1361,    -1,  1423,
     368,  1362,  1361,    -1,  1423,  1367,     9,  1362,  1361,    -1,
      13,    -1,    16,    -1,    11,    -1,    12,    -1,   249,    -1,
       9,    -1,    15,    -1,    14,    -1,  1368,    -1,  1364,    -1,
    1360,    -1,    -1,   583,    -1,   356,    -1,   473,    -1,  1373,
      -1,  1374,    -1,  1376,    -1,   533,    -1,   533,   427,  1377,
     388,    -1,   407,   427,  1378,  1375,   388,    -1,   469,    -1,
     394,   427,  1378,  1375,   388,    -1,   509,   427,  1378,  1375,
     388,    -1,   535,    -1,   404,    -1,   376,    -1,   354,  1393,
     624,  1394,    -1,   354,    -1,   366,  1393,   624,  1394,    -1,
     366,    -1,   366,  1393,   427,    25,   388,   624,  1394,    -1,
     572,    -1,   530,    -1,   420,    -1,   420,   427,    25,   388,
      -1,   420,   427,    25,     5,    25,   388,    -1,    -1,     5,
    1379,    -1,   499,   427,  1378,   388,    -1,   563,    -1,   296,
      -1,   499,    -1,    61,    -1,    25,    -1,    25,    -1,    25,
      -1,    24,   618,   935,    -1,    24,    -1,   935,    -1,   935,
     587,   935,    -1,   935,    -1,    -1,   455,    25,   423,    -1,
     455,    25,     5,    25,   423,    -1,  1384,    -1,   610,  1384,
      -1,   935,  1382,    -1,  1380,   618,   935,  1382,    -1,  1380,
     618,    20,    -1,   935,    -1,    24,    -1,   407,    -1,   941,
      -1,    25,    -1,  1388,    -1,   392,  1390,    -1,   392,  1389,
      -1,    -1,  1393,   624,  1394,    -1,    -1,  1391,   624,  1391,
      -1,   579,    -1,   510,    -1,   588,    -1,   550,    -1,   450,
      -1,   467,    -1,   363,    -1,   363,   427,    25,   388,    -1,
     579,    -1,   510,    -1,   588,    -1,   550,    -1,   450,    -1,
     467,    -1,   363,    -1,   363,   427,    25,   388,    -1,   579,
      -1,   510,    -1,   588,    -1,   550,    -1,   450,    -1,   467,
      -1,   363,    -1,   579,    -1,   510,    -1,   588,    -1,   550,
      -1,   450,    -1,   467,    -1,   363,    -1,   935,    -1,    24,
      -1,  1436,   500,   929,    -1,    -1,  1436,   395,   929,   433,
     593,  1405,  1398,  1402,    -1,    -1,  1436,   395,   929,   433,
      98,   593,  1406,  1399,  1402,    -1,    -1,  1436,   395,   929,
     133,  1406,  1400,  1402,    -1,    -1,  1436,   395,   929,   134,
      98,   593,  1406,  1401,  1402,    -1,    -1,   285,    -1,   284,
    1403,    -1,  1404,    -1,  1403,     5,  1404,    -1,   935,    -1,
     935,   618,   935,    -1,    24,   618,   935,   618,   935,    -1,
    1406,    -1,  1278,    -1,  1154,    -1,  1408,    -1,  1408,  1402,
      -1,    -1,    -1,   468,  1419,  1409,  1420,  1410,  1416,  1352,
    1414,    -1,   468,  1419,  1420,  1352,  1414,    -1,  1413,    -1,
    1431,    -1,   468,  1419,  1420,  1416,  1352,  1414,    -1,    -1,
     522,  1371,  1412,    -1,  1297,    -1,   328,  1415,  1249,    -1,
    1297,   328,  1415,  1249,    -1,   935,    -1,    -1,   551,  1119,
      -1,   468,  1419,  1420,  1352,    -1,   427,   468,  1419,  1420,
    1352,   388,    -1,    -1,   583,    -1,   356,    -1,   473,    -1,
    1421,    -1,  1420,     5,  1421,    -1,  1423,    -1,  1423,  1493,
      -1,  1423,   942,    -1,  1423,    -1,  1424,    -1,    18,  1424,
      -1,    17,  1424,    -1,  1425,    -1,  1473,    -1,  1418,    -1,
     610,   935,    -1,   610,   935,   618,   935,    -1,  1424,    19,
    1423,    -1,  1424,  1445,    -1,  1424,    20,  1423,    -1,  1424,
      17,  1423,    -1,  1424,    18,  1423,    -1,  1386,    -1,   481,
      -1,   424,    -1,   574,    -1,    20,    -1,    62,    -1,   586,
     427,  1371,  1423,   388,    -1,   598,   427,  1371,  1423,   388,
      -1,   599,   427,  1371,  1423,   388,    -1,   607,   427,  1371,
    1423,   388,    -1,   493,   427,  1371,  1423,   388,    -1,   935,
     427,  1426,   388,    -1,   535,   427,  1426,   388,    -1,   427,
    1423,   388,    -1,   440,   427,  1446,   388,    -1,  1423,    -1,
    1426,     5,  1423,    -1,    -1,  1386,    -1,  1436,   343,  1435,
    1430,  1412,    -1,  1436,   332,  1435,  1430,   245,  1380,  1432,
      -1,  1436,   332,  1435,  1430,  1097,    -1,    -1,   318,  1431,
      -1,    24,    -1,  1097,    -1,    -1,   427,  1433,   388,    -1,
    1434,    -1,  1433,     5,  1434,    -1,   935,    -1,    24,    -1,
    1097,    -1,    -1,   264,  1437,   593,    -1,   936,    -1,  1443,
      -1,  1442,    -1,  1439,    -1,   313,  1440,   624,  1440,    -1,
     294,  1440,   618,  1441,   624,  1441,    -1,   935,    -1,   935,
      -1,   218,   786,    -1,   289,   786,  1444,    -1,   268,    -1,
     172,    -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,   392,     5,  1393,   624,  1394,    -1,
    1383,     5,  1393,   624,  1394,    -1,   392,  1393,   624,  1394,
      -1,    -1,   606,  1448,  1449,   186,    -1,  1450,    -1,  1449,
    1450,    -1,    32,    -1,  1451,    -1,  1452,    -1,   187,  1473,
      -1,   551,  1119,    -1,    -1,    -1,   475,  1380,  1454,  1457,
    1455,  1456,    -1,    -1,   147,   929,    -1,   523,  1356,    -1,
      50,  1461,   388,    13,   427,  1462,   388,    -1,    46,  1462,
     388,    -1,    47,  1462,   388,    -1,   581,  1458,    -1,    49,
    1462,    -1,    48,  1462,    -1,  1460,    -1,  1458,     5,  1460,
      -1,  1383,    -1,  1459,    13,  1463,    -1,  1459,    -1,  1461,
       5,  1459,    -1,  1463,    -1,  1462,     5,  1463,    -1,   480,
      -1,  1464,    -1,  1465,    -1,    18,  1465,    -1,    17,  1465,
      -1,  1467,    -1,  1418,    -1,   610,   935,    -1,   610,   935,
     618,   935,    -1,  1466,    -1,  1386,    -1,   481,    -1,   424,
      -1,   574,    -1,    62,    -1,  1465,    19,  1464,    -1,  1465,
    1445,    -1,  1465,    20,  1464,    -1,  1465,    17,  1464,    -1,
    1465,    18,  1464,    -1,   586,   427,  1371,  1464,   388,    -1,
     598,   427,  1371,  1464,   388,    -1,   599,   427,  1371,  1464,
     388,    -1,   607,   427,  1371,  1464,   388,    -1,   493,   427,
    1371,  1464,   388,    -1,   935,   427,  1468,   388,    -1,   535,
     427,  1468,   388,    -1,   427,  1464,   388,    -1,   440,   427,
    1446,   388,    -1,  1473,    -1,  1464,    -1,  1468,     5,  1464,
      -1,  1470,    -1,   187,  1471,    -1,  1471,    -1,  1106,    -1,
     935,    -1,  1471,   618,  1472,    -1,    24,   618,  1471,   618,
    1472,    -1,    20,    -1,  1127,    -1,   935,    -1,  1470,    -1,
    1470,   417,  1470,    -1,   124,  1475,    -1,   128,  1475,    -1,
     123,  1475,    -1,    44,    -1,   163,  1475,    -1,   121,  1475,
      -1,    45,    -1,   146,  1475,    -1,   145,  1475,    -1,   120,
    1475,    -1,   352,    -1,   619,   624,  1476,    -1,   545,  1476,
      -1,   570,    -1,   531,  1477,    -1,   935,    -1,   587,   935,
      -1,   935,    -1,    -1,    -1,   524,  1479,   843,  1480,  1494,
     322,    -1,    -1,   657,  1484,    -1,    -1,   660,    -1,   178,
      -1,   274,   930,    -1,    67,   930,    -1,   304,    -1,   303,
      -1,   305,   932,  1481,  1482,    -1,   490,  1484,  1482,    -1,
     927,    -1,  1484,     5,   927,    -1,   100,    -1,   130,   930,
      -1,   843,   564,     5,   843,   389,    -1,   506,   843,    -1,
     261,   930,    -1,    99,  1489,     8,  1490,  1488,    -1,    -1,
     544,   843,    -1,   935,    -1,   935,    -1,   244,   930,    -1,
     247,   930,   624,   843,     5,   843,    -1,   247,   930,   617,
     843,     5,   843,    -1,    26,    -1,    -1,  1496,    -1,  1497,
    1203,    -1,  1495,    -1,  1496,  1495,    -1,    -1,  1498,  1499,
      -1,   667,    -1,   668,    -1,   669,    -1,   670,    -1,   687,
      -1,   709,    -1,   723,    -1,   724,    -1,   730,    -1,   731,
      -1,   750,    -1,   818,    -1,   819,    -1,   820,    -1,   821,
      -1,   832,    -1,   833,    -1,   834,    -1,   835,    -1,   887,
      -1,   891,    -1,   921,    -1,   943,    -1,   944,    -1,   947,
      -1,   948,    -1,   949,    -1,   950,    -1,   963,    -1,   971,
      -1,   998,    -1,   999,    -1,  1001,    -1,  1005,    -1,  1022,
      -1,  1023,    -1,  1027,    -1,  1028,    -1,  1029,    -1,  1030,
      -1,  1038,    -1,  1053,    -1,  1066,    -1,  1077,    -1,  1078,
      -1,  1079,    -1,  1090,    -1,  1130,    -1,  1133,    -1,  1135,
      -1,  1141,    -1,  1142,    -1,  1145,    -1,  1148,    -1,  1151,
      -1,  1153,    -1,  1155,    -1,  1157,    -1,  1164,    -1,  1169,
      -1,  1173,    -1,  1174,    -1,  1175,    -1,  1187,    -1,  1239,
      -1,  1240,    -1,  1242,    -1,  1254,    -1,  1255,    -1,  1273,
      -1,  1276,    -1,  1305,    -1,  1307,    -1,  1396,    -1,  1397,
      -1,  1428,    -1,  1429,    -1,  1447,    -1,  1474,    -1,  1478,
      -1,  1483,    -1,  1485,    -1,  1487,    -1,  1491,    -1,  1492,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   917,   917,   920,   923,   929,   935,   942,   946,   946,
     952,   975,   976,   977,   978,   979,   993,   994,   995,   996,
     997,  1002,  1003,  1014,  1017,  1020,  1020,  1024,  1027,  1028,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,  1050,  1053,  1054,  1057,
    1057,  1065,  1066,  1069,  1075,  1077,  1088,  1090,  1092,  1094,
    1098,  1100,  1162,  1166,  1170,  1170,  1181,  1185,  1189,  1190,
    1193,  1199,  1193,  1212,  1217,  1221,  1212,  1233,  1237,  1233,
    1245,  1250,  1245,  1269,  1276,  1280,  1268,  1306,  1306,  1310,
    1311,  1312,  1317,  1320,  1325,  1329,  1337,  1340,  1340,  1346,
    1350,  1365,  1363,  1381,  1381,  1396,  1396,  1399,  1399,  1403,
    1406,  1406,  1406,  1413,  1414,  1413,  1421,  1421,  1432,  1432,
    1451,  1454,  1457,  1460,  1463,  1466,  1479,  1484,  1484,  1485,
    1485,  1488,  1493,  1493,  1497,  1507,  1521,  1525,  1520,  1535,
    1541,  1549,  1550,  1553,  1553,  1556,  1560,  1565,  1572,  1572,
    1576,  1576,  1583,  1583,  1588,  1588,  1593,  1593,  1598,  1598,
    1611,  1612,  1620,  1621,  1638,  1641,  1644,  1647,  1650,  1653,
    1659,  1670,  1675,  1688,  1692,  1707,  1708,  1712,  1712,  1716,
    1716,  1716,  1717,  1718,  1723,  1723,  1726,  1726,  1735,  1736,
    1737,  1740,  1744,  1745,  1745,  1762,  1762,  1762,  1762,  1766,
    1773,  1774,  1777,  1777,  1780,  1780,  1789,  1786,  1802,  1802,
    1804,  1804,  1806,  1808,  1810,  1812,  1815,  1819,  1819,  1820,
    1820,  1824,  1824,  1836,  1836,  1841,  1845,  1847,  1848,  1851,
    1851,  1851,  1855,  1856,  1857,  1858,  1865,  1866,  1867,  1868,
    1871,  1872,  1873,  1874,  1878,  1883,  1888,  1892,  1895,  1899,
    1900,  1901,  1902,  1903,  1904,  1905,  1906,  1909,  1910,  1911,
    1943,  1947,  1949,  1951,  1951,  1958,  1962,  1962,  1966,  1967,
    1968,  1969,  1970,  1971,  1972,  1978,  1978,  1981,  1983,  1989,
    1991,  1997,  2005,  2005,  2008,  2009,  2010,  2011,  2012,  2013,
    2014,  2020,  2023,  2023,  2036,  2036,  2043,  2044,  2045,  2047,
    2048,  2050,  2052,  2053,  2054,  2055,  2060,  2066,  2072,  2073,
    2075,  2077,  2078,  2079,  2080,  2081,  2082,  2085,  2086,  2093,
    2101,  2101,  2109,  2106,  2121,  2121,  2123,  2123,  2131,  2131,
    2134,  2137,  2138,  2143,  2155,  2159,  2162,  2165,  2166,  2167,
    2168,  2169,  2174,  2181,  2187,  2192,  2196,  2192,  2207,  2209,
    2214,  2219,  2219,  2223,  2223,  2226,  2226,  2232,  2232,  2238,
    2238,  2254,  2257,  2271,  2273,  2275,  2277,  2279,  2281,  2283,
    2289,  2291,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2313,
    2328,  2331,  2344,  2345,  2346,  2347,  2348,  2352,  2353,  2354,
    2358,  2363,  2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,
    2378,  2379,  2384,  2384,  2389,  2389,  2392,  2398,  2406,  2412,
    2422,  2423,  2431,  2438,  2442,  2452,  2456,  2461,  2466,  2468,
    2478,  2491,  2499,  2512,  2517,  2523,  2528,  2533,  2534,  2540,
    2611,  2617,  2622,  2630,  2630,  2645,  2649,  2656,  2659,  2667,
    2678,  2688,  2694,  2703,  2708,  2716,  2719,  2722,  2727,  2734,
    2739,  2744,  2749,  2759,  2767,  2775,  2780,  2784,  2789,  2793,
    2797,  2804,  2807,  2810,  2814,  2818,  2822,  2826,  2834,  2844,
    2849,  2842,  2865,  2870,  2865,  2887,  2887,  2887,  2890,  2890,
    2890,  2893,  2893,  2893,  2896,  2896,  2896,  2899,  2905,  2911,
    2917,  2927,  2927,  2931,  2935,  2936,  2942,  2943,  2948,  2951,
    2960,  2969,  2970,  2973,  2978,  2984,  2988,  2992,  2995,  3001,
    3004,  3007,  3022,  3025,  3031,  3032,  3033,  3037,  3038,  3039,
    3040,  3041,  3043,  3044,  3045,  3047,  3048,  3052,  3053,  3058,
    3059,  3071,  3075,  3070,  3083,  3086,  3100,  3104,  3109,  3099,
    3129,  3135,  3129,  3149,  3149,  3151,  3152,  3156,  3156,  3160,
    3160,  3165,  3165,  3172,  3173,  3177,  3177,  3181,  3181,  3186,
    3186,  3193,  3197,  3198,  3199,  3204,  3204,  3207,  3207,  3211,
    3211,  3215,  3215,  3219,  3219,  3224,  3224,  3229,  3229,  3234,
    3234,  3239,  3239,  3255,  3272,  3273,  3274,  3275,  3276,  3277,
    3280,  3280,  3283,  3285,  3288,  3291,  3293,  3294,  3295,  3297,
    3299,  3301,  3303,  3307,  3314,  3316,  3322,  3327,  3332,  3337,
    3337,  3340,  3346,  3351,  3354,  3361,  3361,  3363,  3364,  3366,
    3368,  3370,  3372,  3376,  3385,  3385,  3392,  3393,  3394,  3395,
    3396,  3397,  3398,  3399,  3400,  3401,  3402,  3403,  3404,  3405,
    3406,  3407,  3408,  3409,  3410,  3411,  3412,  3413,  3414,  3415,
    3416,  3417,  3418,  3419,  3420,  3421,  3422,  3423,  3424,  3425,
    3426,  3427,  3428,  3429,  3430,  3431,  3432,  3433,  3434,  3446,
    3459,  3466,  3466,  3470,  3475,  3481,  3485,  3489,  3495,  3499,
    3503,  3509,  3509,  3517,  3518,  3522,  3522,  3526,  3527,  3530,
    3533,  3533,  3536,  3538,  3538,  3541,  3543,  3543,  3544,  3546,
    3546,  3555,  3553,  3565,  3565,  3565,  3568,  3570,  3568,  3577,
    3580,  3586,  3597,  3597,  3601,  3607,  3607,  3611,  3612,  3623,
    3624,  3626,  3628,  3633,  3633,  3637,  3636,  3643,  3642,  3648,
    3648,  3653,  3653,  3659,  3659,  3664,  3664,  3669,  3669,  3674,
    3674,  3679,  3679,  3684,  3684,  3687,  3687,  3690,  3690,  3693,
    3693,  3701,  3702,  3710,  3711,  3716,  3717,  3726,  3727,  3734,
    3735,  3743,  3744,  3753,  3758,  3763,  3764,  3765,  3769,  3768,
    3779,  3784,  3789,  3789,  3800,  3805,  3806,  3807,  3808,  3811,
    3811,  3814,  3819,  3820,  3821,  3822,  3823,  3824,  3825,  3826,
    3827,  3832,  3832,  3834,  3837,  3837,  3839,  3843,  3843,  3846,
    3847,  3850,  3850,  3855,  3855,  3858,  3859,  3860,  3861,  3862,
    3863,  3864,  3865,  3866,  3867,  3868,  3869,  3870,  3871,  3872,
    3873,  3874,  3878,  3896,  3896,  3896,  3922,  3933,  3940,  3946,
    3952,  3958,  3969,  3992,  3991,  4008,  4008,  4012,  4013,  4021,
    4022,  4023,  4024,  4031,  4032,  4034,  4035,  4039,  4044,  4045,
    4046,  4047,  4048,  4049,  4050,  4051,  4052,  4053,  4054,  4057,
    4057,  4059,  4059,  4059,  4061,  4065,  4065,  4074,  4079,  4095,
    4101,  4073,  4115,  4129,  4139,  4128,  4152,  4159,  4159,  4164,
    4169,  4174,  4175,  4178,  4178,  4178,  4181,  4181,  4189,  4195,
    4209,  4213,  4226,  4208,  4244,  4244,  4257,  4268,  4267,  4279,
    4275,  4292,  4289,  4302,  4302,  4304,  4305,  4307,  4308,  4311,
    4312,  4313,  4315,  4320,  4325,  4331,  4333,  4334,  4337,  4338,
    4341,  4343,  4352,  4358,  4352,  4369,  4370,  4374,  4374,  4384,
    4384,  4396,  4399,  4403,  4407,  4412,  4416,  4417,  4418,  4419,
    4420,  4424,  4424,  4426,  4426,  4429,  4438,  4486,  4486,  4489,
    4493,  4498,  4538,  4539,  4540,  4543,  4557,  4569,  4569,  4574,
    4575,  4581,  4640,  4696,  4701,  4708,  4713,  4721,  4727,  4756,
    4759,  4760,  4801,  4802,  4806,  4807,  4811,  4864,  4868,  4871,
    4877,  4888,  4895,  4903,  4903,  4906,  4907,  4908,  4909,  4910,
    4913,  4916,  4922,  4925,  4929,  4933,  4940,  4945,  4952,  4955,
    4961,  4963,  4963,  4963,  4967,  4987,  4994,  5001,  5004,  5018,
    5025,  5026,  5029,  5030,  5034,  5040,  5045,  5051,  5052,  5057,
    5061,  5061,  5065,  5066,  5069,  5070,  5074,  5082,  5085,  5091,
    5092,  5094,  5096,  5100,  5100,  5101,  5106,  5114,  5115,  5120,
    5121,  5123,  5136,  5138,  5139,  5141,  5144,  5147,  5150,  5154,
    5157,  5160,  5164,  5168,  5172,  5175,  5179,  5182,  5183,  5184,
    5187,  5190,  5193,  5196,  5199,  5202,  5205,  5221,  5229,  5229,
    5231,  5238,  5245,  5260,  5258,  5278,  5283,  5284,  5288,  5289,
    5291,  5292,  5294,  5294,  5302,  5311,  5311,  5321,  5322,  5325,
    5326,  5329,  5333,  5347,  5352,  5357,  5362,  5372,  5372,  5376,
    5379,  5379,  5381,  5391,  5400,  5407,  5409,  5413,  5416,  5416,
    5420,  5419,  5423,  5422,  5426,  5425,  5429,  5428,  5432,  5431,
    5434,  5434,  5450,  5449,  5471,  5472,  5473,  5474,  5475,  5476,
    5479,  5479,  5485,  5485,  5488,  5488,  5498,  5499,  5500,  5507,
    5519,  5520,  5523,  5524,  5527,  5530,  5530,  5535,  5539,  5544,
    5550,  5551,  5552,  5556,  5557,  5558,  5559,  5563,  5573,  5575,
    5580,  5583,  5588,  5594,  5601,  5608,  5617,  5624,  5631,  5638,
    5645,  5654,  5654,  5656,  5656,  5659,  5660,  5661,  5662,  5663,
    5664,  5665,  5666,  5667,  5668,  5671,  5671,  5674,  5675,  5676,
    5677,  5680,  5680,  5683,  5683,  5686,  5687,  5688,  5689,  5690,
    5691,  5692,  5693,  5695,  5696,  5697,  5698,  5700,  5701,  5702,
    5703,  5705,  5706,  5707,  5708,  5709,  5710,  5711,  5712,  5716,
    5722,  5730,  5741,  5750,  5761,  5765,  5769,  5775,  5740,  5788,
    5791,  5799,  5811,  5813,  5818,  5826,  5836,  5839,  5843,  5851,
    5817,  5860,  5864,  5868,  5872,  5864,  5882,  5883,  5884,  5885,
    5890,  5892,  5895,  5899,  5902,  5909,  5914,  5915,  5916,  5921,
    5922,  5928,  5928,  5928,  5933,  5933,  5933,  5944,  5945,  5951,
    5952,  5958,  5959,  5964,  5965,  5966,  5970,  5973,  5979,  5982,
    5990,  5991,  5997,  6004,  6007,  6016,  6019,  6022,  6025,  6028,
    6031,  6034,  6041,  6044,  6051,  6054,  6060,  6063,  6070,  6073,
    6080,  6081,  6086,  6090,  6093,  6099,  6102,  6108,  6115,  6116,
    6120,  6126,  6129,  6136,  6137,  6144,  6147,  6152,  6163,  6164,
    6165,  6166,  6167,  6168,  6169,  6170,  6171,  6174,  6177,  6183,
    6183,  6189,  6189,  6200,  6213,  6223,  6223,  6228,  6228,  6232,
    6236,  6237,  6243,  6244,  6249,  6253,  6260,  6263,  6270,  6274,
    6269,  6286,  6290,  6297,  6301,  6301,  6314,  6318,  6318,  6333,
    6335,  6337,  6339,  6341,  6343,  6345,  6347,  6353,  6363,  6370,
    6375,  6376,  6380,  6382,  6383,  6386,  6387,  6388,  6391,  6396,
    6403,  6404,  6410,  6422,  6423,  6426,  6426,  6431,  6436,  6441,
    6442,  6445,  6446,  6451,  6456,  6460,  6465,  6466,  6470,  6477,
    6481,  6482,  6487,  6489,  6493,  6494,  6498,  6499,  6500,  6501,
    6505,  6506,  6511,  6512,  6517,  6518,  6523,  6524,  6529,  6534,
    6535,  6540,  6541,  6545,  6546,  6551,  6558,  6563,  6568,  6572,
    6573,  6578,  6579,  6585,  6587,  6592,  6593,  6599,  6602,  6605,
    6612,  6614,  6626,  6631,  6632,  6635,  6637,  6644,  6647,  6653,
    6657,  6661,  6665,  6668,  6675,  6682,  6687,  6691,  6692,  6698,
    6701,  6712,  6719,  6725,  6728,  6735,  6742,  6748,  6749,  6755,
    6756,  6757,  6760,  6761,  6766,  6766,  6770,  6778,  6779,  6782,
    6785,  6790,  6791,  6796,  6799,  6805,  6808,  6814,  6817,  6823,
    6826,  6833,  6834,  6863,  6864,  6869,  6870,  6874,  6879,  6882,
    6885,  6888,  6894,  6895,  6899,  6902,  6905,  6906,  6911,  6914,
    6917,  6920,  6923,  6926,  6929,  6935,  6936,  6937,  6938,  6939,
    6941,  6943,  6944,  6949,  6952,  6956,  6962,  6963,  6964,  6965,
    6977,  6978,  6979,  6983,  6984,  6989,  6991,  6992,  6993,  6995,
    6996,  6997,  6998,  7000,  7001,  7003,  7004,  7006,  7007,  7008,
    7009,  7011,  7015,  7016,  7022,  7024,  7025,  7026,  7027,  7032,
    7036,  7040,  7044,  7045,  7049,  7050,  7060,  7068,  7069,  7070,
    7074,  7077,  7082,  7087,  7092,  7100,  7104,  7108,  7109,  7110,
    7115,  7118,  7121,  7125,  7126,  7130,  7131,  7135,  7135,  7135,
    7135,  7135,  7135,  7136,  7139,  7144,  7144,  7144,  7144,  7144,
    7144,  7146,  7149,  7155,  7155,  7155,  7155,  7155,  7155,  7155,
    7156,  7156,  7156,  7156,  7156,  7156,  7156,  7158,  7159,  7162,
    7171,  7171,  7176,  7176,  7182,  7182,  7187,  7187,  7194,  7195,
    7196,  7199,  7199,  7202,  7203,  7204,  7209,  7212,  7218,  7223,
    7231,  7244,  7245,  7242,  7263,  7273,  7276,  7281,  7293,  7296,
    7300,  7303,  7304,  7310,  7313,  7314,  7323,  7332,  7337,  7338,
    7339,  7340,  7348,  7351,  7357,  7360,  7363,  7369,  7378,  7381,
    7384,  7390,  7396,  7399,  7402,  7405,  7411,  7413,  7415,  7417,
    7419,  7421,  7422,  7423,  7424,  7425,  7426,  7427,  7429,  7431,
    7433,  7435,  7437,  7439,  7441,  7442,  7447,  7448,  7454,  7455,
    7458,  7467,  7471,  7478,  7478,  7482,  7482,  7487,  7487,  7491,
    7491,  7495,  7501,  7501,  7504,  7504,  7510,  7517,  7518,  7519,
    7523,  7524,  7527,  7528,  7532,  7538,  7548,  7549,  7557,  7558,
    7559,  7560,  7561,  7562,  7566,  7567,  7568,  7572,  7572,  7584,
    7585,  7589,  7590,  7591,  7595,  7601,  7688,  7692,  7688,  7701,
    7705,  7711,  7719,  7729,  7739,  7751,  7754,  7773,  7799,  7802,
    7808,  7811,  7816,  7819,  7827,  7835,  7848,  7851,  7859,  7862,
    7865,  7873,  7877,  7880,  7883,  7886,  7890,  7891,  7892,  7893,
    7894,  7900,  7901,  7902,  7903,  7904,  7905,  7906,  7907,  7908,
    7909,  7910,  7911,  7912,  7913,  7917,  7923,  7924,  7936,  7948,
    7948,  7952,  7953,  7954,  7955,  7959,  7960,  7961,  7966,  7980,
    8031,  8033,  8035,  8037,  8041,  8046,  8048,  8051,  8053,  8055,
    8059,  8062,  8067,  8072,  8076,  8085,  8086,  8090,  8102,  8105,
    8101,  8124,  8124,  8128,  8129,  8132,  8133,  8134,  8135,  8136,
    8137,  8138,  8143,  8144,  8148,  8151,  8156,  8160,  8165,  8169,
    8174,  8178,  8181,  8185,  8188,  8193,  8197,  8208,  8214,  8214,
    8215,  8216,  8223,  8232,  8232,  8234,  8235,  8236,  8237,  8238,
    8239,  8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,
    8249,  8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,
    8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,  8268,
    8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,  8278,
    8279,  8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,  8288,
    8289,  8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,
    8299,  8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,  8308,
    8309,  8310,  8311,  8312,  8313,  8314,  8315,  8316,  8317,  8318
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "UMINUS", "COMMA", "KW_OR", 
  "KW_AND", "KW_USING", "MATCHES", "POWER", "LESS_THAN", "GREATER_THAN", 
  "EQUAL", "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", "PLUS", 
  "MINUS", "DIVIDE", "MULTIPLY", "MOD", "COMMAND", "NUMBER_VALUE", 
  "CHAR_VALUE", "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART", 
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "BEFORE_INSERT", "BEFORE_DELETE", 
  "AFTER_INSERT", "AFTER_DELETE", "DELETE_ROW_EQUAL_TRUE", 
  "INSERT_ROW_EQUAL_TRUE", "DELETE_ROW_EQUAL_FALSE", 
  "INSERT_ROW_EQUAL_FALSE", "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", 
  "ALTER_TABLE", "WHENEVER_ERROR_CONTINUE", "WHENEVER_WARNING_CONTINUE", 
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL", 
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "CREATE_DATABASE", 
  "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
  "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", "UP_BY", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "DOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", "CONNECT_TO", 
  "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", 
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "NO_NEW_LINES", 
  "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "CWIS", "CREATE_IDX", 
  "FORM_IS_COMPILED", "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", 
  "POINTS", "MM", "INCHES", "PREPEND", "MEMBER_OF", "MEMBER_FUNCTION", 
  "APPEND", "TEMPLATE", "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", 
  "SQLSIRR", "UPDATESTATS_T", "SQLSICR", "WHENEVER_SQLSUCCESS", 
  "WHENEVER_SQLWARNING", "START_EXTERN", "WHENEVER_ANY_ERROR", 
  "WHENEVER_NOT_FOUND", "CONTINUE_CONSTRUCT", "FOUNCONSTR", "SQLSIDR", 
  "WHENEVER_SQLERROR", "CREATE_TEMP_TABLE", "CURRENT_WINDOW_IS", 
  "FIRST_PAGE_HEADER", "ORDER_EXTERNAL_BY", "SCROLL_CURSOR_FOR", 
  "SCROLL_CURSOR", "SQL_INTERRUPT_OFF", "STOP_ALL_EXTERNAL", 
  "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", "SQLSLMNW", "ADDCONSTUNIQ", 
  "CONTINUE_DISPLAY", "CONTINUE_FOREACH", "OUTPUT_TO_REPORT", 
  "SQL_INTERRUPT_ON", "WHENEVER_SUCCESS", "WHENEVER_WARNING", 
  "WHERE_CURRENT_OF", "WITHOUT_DEFAULTS", "FOCONSTR", "SCALED_BY", 
  "CONTINUE_PROMPT", "PDF_FUNCTION", "DEFER_INTERRUPT", "DISPLAY_BY_NAME", 
  "NOT_NULL_UNIQUE", "SKIP_TO_TOP", "TOP_OF_PAGE", "SKIP_TO", "SKIP_BY", 
  "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", "WHENEVER_ERROR", 
  "AFTCONSTRUCT", "ALL_PRIVILEGES", "CLOSE_DATABASE", "CONTINUE_INPUT", 
  "CONTINUE_WHILE", "CREATE_SYNONYM", "DROP_TABLE", "EXIT_CONSTRUCT", 
  "INEXCLUSIVE", "REPORT_TO_PRINTER", "REPORT_TO_PIPE", "SET_SESSION_TO", 
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
  "CHARACTER", "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", 
  "END_INPUT", "END_WHILE", "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", 
  "FORM_LINE", "INTERRUPT", "INTO_TEMP", "INVISIBLE", "IN_MEMORY", 
  "LINKED_TO", "LOAD_FROM", "LOCKTAB", "MENU_LINE", "OPEN_FORM", 
  "OTHERWISE", "PRECISION", "PRIOR", "PROCEDURE", "REPORT_TO", 
  "RETURNING", "UNDERLINE", "UNLOAD_TO", "BEFROW", "UNLOAD_T", "VARIABLE", 
  "ABSOLUTE", "AFTROW", "BUFFERED", "CONSTANT", "CONST", "CONTINUE", 
  "DATABASE", "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", "END_MAIN", 
  "END_MENU", "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", "FUNCTION", 
  "GROUP_BY", "INTERVAL", "KWMESSAGE", "NOT_LIKE", "NOT_NULL", "PASSWORD", 
  "PREVIOUS", "READONLY", "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", 
  "VALIDATE", "WHENEVER", "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", 
  "IS_NULL", "AVERAGE", "BETWEEN", "CAPTION", "CLIPPED", "CLOSE_BRACKET", 
  "COLUMNS", "COMMENT", "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", 
  "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", 
  "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", 
  "NUMERIC", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", 
  "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", 
  "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", 
  "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", "BOTTOM", 
  "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", 
  "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", 
  "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", 
  "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", 
  "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "RETURN", "REVOKE", 
  "SCHEMA", "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", 
  "SETL", "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", 
  "YELLOW", "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", 
  "ALTER", "ARRAY", "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", 
  "CLOSE", "CODE_C", "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", 
  "FLOAT", "FLUSH", "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", 
  "LABEL", "LOCAL", "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", 
  "PRINT_IMAGE", "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", 
  "SEMICOLON", "SLEEP", "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", 
  "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", "FCALL", "CASE", "CHAR", 
  "CYAN", "DATE", "DESC", "DOWN", "TAB", "DROP", "ELSE", "EXEC", "EXIT", 
  "FREE", "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", "HIDE", 
  "HOUR", "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", 
  "NEXT", "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", 
  "SOME", "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", 
  "WITH", "WORK", "YEAR", "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", 
  "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", 
  "KWNO", "LET", "LOG", "XMAX", "XMIN", "NOT", "PAD", "PUT", "RED", "ROW", 
  "RUN", "SQL", "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", "AS_GIF", 
  "AS_PNG", "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", "IF", "IN", "OF", 
  "ON", "TO", "UP", "FONT_NAME", "FONT_SIZE", "PAPER_SIZE_IS_LETTER", 
  "PAPER_SIZE_IS_LEGAL", "PAPER_SIZE_IS_A5", "PAPER_SIZE_IS_A4", 
  "PAPER_SIZE_IS_LETTER_L", "PAPER_SIZE_IS_LEGAL_L", "PAPER_SIZE_IS_A5_L", 
  "PAPER_SIZE_IS_A4_L", "FORMHANDLER", "END_FORMHANDLER", "BEFORE_EVENT", 
  "BEFORE_OPEN_FORM", "AFTER_EVENT", "BEFORE_CLOSE_FORM", "BEFORE_ANY", 
  "AFTER_ANY", "MENUHANDLER", "END_MENUHANDLER", "BEFORE_SHOW_MENU", 
  "DISABLE_PROGRAM", "DISABLE_ALL", "BUTTONS", "CHECK_MENUITEM", 
  "DISABLE_FORM", "DISABLE_MENUITEMS", "DISABLE", "ENABLE_FORM", 
  "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", "ICON", "MESSAGEBOX", 
  "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", 
  "INT_TO_ID", "$accept", "pause_screen_on_cmd", "pause_screen_off_cmd", 
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
  "@27", "@28", "bef_c_field_list", "aft_c_field_list", "interval_expr", 
  "extend_parameters", "op_datetime_qual", "defer_cmd", "define_section", 
  "define_multiple", "define_set", "@29", "@30", "def_part", 
  "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "array_variable", "@33", 
  "@34", "assoc_open_bracket", "assoc_close_bracket", "number_arr_assoc", 
  "number_arr_list", "number_value_arr", "record_variable", "@35", "@36", 
  "@37", "link_to_pk_list", "link_to_pk", "dtype_ident", "op_as_static", 
  "dtype2", "@38", "@39", "dtype", "like_var", "tab_name", "col_name", 
  "datetime_qual", "interval_qual", "dtime_start", "@40", "dtime_val", 
  "dtime_end", "@41", "opt_frac", "opt_unit_size", "dtfrac", "int_start", 
  "@42", "int_start_unit", "int_end", "op_equal", "dim_section", "@43", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@44", "@45", 
  "dim_record_variable", "@46", "@47", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@48", "@49", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@50", "@51", "@52", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@53", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@54", "@55", "@56", "@57", "function_callb", 
  "@58", "@59", "@60", "@61", "@62", "@63", "@64", "@65", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", "field_name_list", 
  "for_cmd", "@66", "@67", "for_step", "foreach_cmd", "@68", "@69", "@70", 
  "formhandler_def", "@71", "@72", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@73", "@74", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@75", "@76", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@77", "@78", "@79", "@80", "@81", "free_cmd", "line_no", 
  "file_name", "a_number", "coords", "display_coords", "field_name", 
  "cursor_name", "fetch_cursor_name", "win_name", "open_win_name", 
  "form_name", "open_form_name", "opt_help_no", "identifier", 
  "ident_or_var", "ident_p2", "var_or_string", "field_name2", "cvariable", 
  "real_number", "reserved_word", "goto_cmd", "check_menu_cmd", 
  "menu_item_list", "menu_item", "uncheck_menu_cmd", "disable_cmd", 
  "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@83", "op_else", "@84", "@85", "@86", "import_m", 
  "module_import", "init_cmd", "@87", "init_tab_list", "init_tab", 
  "end_input", "opt_defs", "field_commands", "field_command", "@88", 
  "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", 
  "@99", "@100", "a_ins_or_delete_row", "a_ins_or_delete", 
  "b_ins_or_delete_row", "b_ins_or_delete", "bef_field_list", 
  "aft_field_list", "next_field_cmd", "next_form_cmd", "next_field", 
  "input_cmd", "@101", "inp_rest", "@102", "scroll_cmd", "up_or_down", 
  "op_help", "input_array_attributes", "input_array_attributes_int", 
  "on_key_command", "@103", "key_val", "@104", "accept_key", 
  "single_key_val", "@105", "key_do", "key_value_list", "key_value", 
  "@106", "key_value_1", "label_cmd", "let_cmd", "@107", "@108", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@109", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@110", "@111", "@112", "@113", 
  "end_func_command", "main_def", "@114", "@115", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@116", 
  "glob_section", "mem_func_def", "@117", "@118", "@119", "menu_cmd", 
  "@120", "end_menu_command", "menu_block_command", "@121", "@122", 
  "@123", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@124", "@125", "menu_handler_elements", 
  "menu_handler_element", "@126", "@127", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "@128", "op_msg_wait", "msg_wait", 
  "variable", "var_int", "varsetidentdot", "var", "assoc_var_read", 
  "assoc_var_write", "assoc_sub", "dot_part_var", "array_r_variable", 
  "array_r_variable_or_ident", "arr_subscripts", "num_list", 
  "num_list_element", "let_variable", "let_var", "let_var_dot", 
  "let_array_r_variable", "op_param_var_list", "fparam_var_list", 
  "ibind_var_list", "func_def_var", "ibind_var", "obind_var_list", 
  "obind_var", "obind_var_let_list", "obind_let_var", "use_arr_var", 
  "obind_var_list_ord", "obind_var_ord", "optional_asc_desc", 
  "array_r_varid", "init_bind_var_list", "init_bind_var", 
  "open_window_cmd", "op_at_statusbox", "op_size_statusbox", 
  "open_statusbox_cmd", "formhandler_name", "open_form_cmd", 
  "open_form_rest", "open_form_gui", "op_at_gui", "op_like_gui", 
  "op_absolute", "open_session_cmd", "open_cursor_cmd", "user_details", 
  "op_disable", "connect_cmd", "op_connect_as", "con_user_details", 
  "options_cmd", "opt_options", "opt_allopts", "prepare_cmd", 
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@129", 
  "gui_prompt_cmd", "opt_char", "prompt_key_sec", "prompt_key_clause", 
  "on_key_command_prompt", "@130", "prompt_title", "put_cmd", "@131", 
  "put_from", "put_val_list", "put_val", "start_cmd", "rout", "rep_name", 
  "op_values", "output_cmd", "finish_cmd", "term_rep_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@132", "@133", "@134", "@135", "@136", "@137", "@138", "report_cmd", 
  "need_command", "@139", "op_lines", "skip_command", "@140", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@141", "@142", "@143", "@144", "@145", 
  "@146", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@147", "@148", "@149", "@150", "@151", "@152", "pdf_report_section", 
  "pdf_functions", "@153", "@154", "@155", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@156", "@157", 
  "@158", "@159", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@160", "ins_2_ss", "@161", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@162", "@163", "fetch_part", "opt_into_fetch_part", 
  "@164", "opt_foreach_into_fetch_part", "@165", "fetch_place", 
  "delete_statement_position", "delete_statement_search_ss", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "var_ident_qchar", "sql_cmd", 
  "@166", "sql_commands", "privilege_definition", "op_with_grant_option", 
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
  "op_escape", "pattern", "escape_character", "in_predicate_ss", 
  "in_value_list", "in_value_specification", "op_not", 
  "comparison_predicate_ss", "comp_op", "predicate_ss", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "authorization_identifier", "col_arr", "column_name", 
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@167", 
  "@168", "@169", "@170", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@171", "@172", 
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
  "units_qual", "extend_qual", "sql_block_cmd", "@173", "sql_block", 
  "sql_block_entry", "in_var", "sql_block_into", "update_statement_ss", 
  "@174", "@175", "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind_ss", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@176", "@177", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
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
       0,   256,  1651,  1652,  1653,  1568,  1608,  1563,  1499,  1377,
    1485,  1481,  1395,  1558,  1294,  1352,  1426,  1594,  1581,  1514,
    1486,  1582,  1359,  1654,  1655,  1656,  1657,  1658,  1659,  1660,
    1661,  1662,  1663,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,
    1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,
    1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,
    1287,  1288,  1289,  1290,  1291,  1292,  1293,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,
    1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1348,  1349,  1350,  1351,  1353,  1354,  1355,  1356,  1357,  1358,
    1360,  1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,  1378,  1379,  1380,
    1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,
    1391,  1392,  1393,  1394,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,
    1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1482,  1483,
    1484,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,  1500,  1501,  1502,  1503,  1504,  1505,  1506,
    1507,  1508,  1509,  1510,  1511,  1512,  1513,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,
    1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,
    1559,  1560,  1561,  1562,  1564,  1565,  1566,  1567,  1569,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,
    1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1593,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   666,   667,   668,   669,   670,   671,   671,   672,   672,
     673,   674,   674,   674,   674,   674,   675,   675,   675,   675,
     675,   676,   676,   677,   677,   679,   678,   678,   680,   680,
     681,   681,   681,   681,   681,   681,   681,   681,   681,   681,
     681,   681,   681,   681,   681,   681,   681,   682,   682,   684,
     683,   685,   685,   686,   686,   686,   686,   686,   686,   686,
     686,   686,   687,   688,   689,   688,   688,   688,   688,   688,
     690,   691,   688,   692,   693,   694,   688,   695,   696,   688,
     697,   698,   688,   699,   700,   701,   688,   702,   702,   703,
     703,   703,   704,   704,   705,   705,   706,   707,   707,   708,
     708,   710,   709,   711,   709,   712,   712,   713,   713,   714,
     715,   716,   715,   717,   718,   717,   720,   719,   722,   721,
     723,   723,   723,   723,   723,   723,   724,   725,   725,   726,
     726,   727,   728,   728,   729,   730,   732,   733,   731,   734,
     734,   735,   735,   736,   736,   737,   737,   737,   738,   738,
     740,   739,   741,   739,   742,   739,   743,   739,   744,   739,
     745,   745,   746,   746,   747,   747,   747,   747,   747,   747,
     748,   749,   749,   750,   750,   751,   751,   752,   752,   754,
     755,   753,   753,   753,   756,   756,   758,   757,   759,   759,
     759,   759,   759,   760,   759,   761,   761,   761,   761,   762,
     763,   763,   764,   764,   766,   765,   767,   765,   768,   768,
     769,   769,   770,   771,   771,   771,   772,   774,   773,   775,
     773,   776,   773,   777,   777,   778,   779,   780,   780,   782,
     783,   781,   784,   784,   784,   784,   784,   784,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   784,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   784,   784,   784,
     785,   786,   787,   788,   788,   789,   791,   790,   792,   792,
     792,   792,   792,   792,   792,   794,   793,   795,   795,   796,
     796,   797,   799,   798,   800,   800,   800,   800,   800,   800,
     800,   801,   802,   802,   804,   803,   805,   805,   805,   805,
     805,   805,   805,   805,   805,   805,   805,   805,   805,   805,
     805,   805,   805,   805,   805,   805,   805,   805,   805,   806,
     808,   807,   809,   807,   811,   810,   812,   810,   813,   813,
     814,   815,   815,   816,   817,   817,   817,   817,   817,   817,
     817,   817,   818,   819,   820,   822,   823,   821,   824,   824,
     825,   826,   826,   827,   827,   829,   828,   830,   828,   831,
     828,   832,   832,   833,   833,   833,   833,   833,   833,   833,
     833,   833,   834,   834,   834,   834,   834,   834,   834,   834,
     835,   835,   836,   836,   836,   836,   836,   836,   836,   836,
     836,   836,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   838,   838,   839,   839,   840,   840,   841,   841,
     842,   842,   843,   844,   844,   845,   845,   845,   845,   845,
     845,   846,   846,   847,   847,   847,   847,   848,   848,   849,
     850,   850,   850,   851,   850,   852,   852,   853,   853,   854,
     854,   854,   854,   855,   855,   856,   856,   856,   856,   856,
     856,   856,   856,   857,   858,   859,   859,   859,   859,   859,
     859,   860,   860,   860,   860,   860,   860,   860,   861,   863,
     864,   862,   865,   866,   862,   868,   869,   867,   870,   871,
     867,   872,   873,   867,   874,   875,   867,   867,   867,   867,
     867,   876,   876,   877,   878,   878,   878,   878,   878,   878,
     878,   878,   878,   879,   879,   880,   880,   880,   880,   881,
     881,   881,   882,   882,   883,   883,   883,   884,   884,   884,
     884,   884,   884,   884,   884,   884,   884,   885,   885,   886,
     886,   888,   889,   887,   890,   890,   892,   893,   894,   891,
     896,   897,   895,   898,   898,   899,   899,   900,   900,   902,
     901,   903,   901,   904,   904,   905,   905,   907,   906,   908,
     906,   909,   910,   910,   910,   911,   911,   912,   912,   913,
     913,   914,   914,   916,   915,   917,   915,   918,   915,   919,
     915,   920,   915,   921,   922,   922,   922,   922,   922,   922,
     923,   923,   924,   925,   926,   927,   927,   927,   927,   927,
     927,   927,   927,   928,   929,   930,   931,   932,   933,   934,
     934,   935,   936,   937,   937,   938,   938,   939,   939,   939,
     939,   939,   939,   940,   941,   941,   942,   942,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   942,
     942,   942,   942,   942,   942,   942,   942,   942,   942,   943,
     944,   945,   945,   946,   947,   948,   948,   948,   949,   949,
     949,   951,   950,   952,   952,   953,   953,   954,   954,   955,
     956,   956,   957,   958,   958,   959,   960,   960,   961,   962,
     962,   964,   963,   965,   966,   965,   967,   968,   965,   969,
     969,   970,   972,   971,   971,   973,   973,   974,   974,   975,
     975,   976,   976,   977,   977,   979,   978,   980,   978,   981,
     978,   982,   978,   983,   978,   984,   978,   985,   978,   986,
     978,   987,   978,   988,   978,   989,   978,   990,   978,   991,
     978,   992,   992,   993,   993,   994,   994,   995,   995,   996,
     996,   997,   997,   998,   999,  1000,  1000,  1000,  1002,  1001,
    1003,  1003,  1004,  1003,  1005,  1006,  1006,  1006,  1006,  1007,
    1007,  1008,  1009,  1009,  1009,  1009,  1009,  1009,  1009,  1009,
    1009,  1011,  1010,  1010,  1013,  1012,  1014,  1016,  1015,  1017,
    1017,  1018,  1018,  1020,  1019,  1021,  1021,  1021,  1021,  1021,
    1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,  1021,
    1021,  1021,  1022,  1024,  1025,  1023,  1026,  1026,  1027,  1028,
    1029,  1030,  1030,  1032,  1031,  1033,  1033,  1034,  1034,  1035,
    1035,  1035,  1035,  1036,  1036,  1037,  1037,  1038,  1039,  1039,
    1039,  1039,  1039,  1039,  1039,  1039,  1039,  1039,  1039,  1040,
    1040,  1041,  1041,  1041,  1042,  1043,  1043,  1045,  1046,  1047,
    1048,  1044,  1049,  1051,  1052,  1050,  1053,  1054,  1054,  1055,
    1056,  1057,  1057,  1058,  1058,  1058,  1060,  1059,  1061,  1061,
    1063,  1064,  1065,  1062,  1067,  1066,  1068,  1070,  1069,  1071,
    1069,  1072,  1069,  1073,  1073,  1074,  1074,  1075,  1075,  1076,
    1076,  1076,  1077,  1078,  1079,  1080,  1080,  1080,  1081,  1081,
    1082,  1082,  1084,  1085,  1083,  1086,  1086,  1088,  1087,  1089,
    1087,  1090,  1091,  1091,  1091,  1091,  1092,  1092,  1092,  1092,
    1092,  1094,  1093,  1095,  1095,  1096,  1097,  1098,  1098,  1099,
    1100,  1100,  1100,  1100,  1100,  1101,  1102,  1103,  1103,  1104,
    1104,  1105,  1106,  1107,  1107,  1108,  1108,  1109,  1110,  1111,
    1111,  1111,  1111,  1111,  1112,  1112,  1113,  1114,  1114,  1115,
    1115,  1116,  1116,  1117,  1117,  1118,  1118,  1118,  1118,  1118,
    1119,  1119,  1120,  1120,  1121,  1121,  1122,  1123,  1124,  1124,
    1125,  1126,  1126,  1126,  1127,  1128,  1128,  1129,  1129,  1130,
    1131,  1131,  1132,  1132,  1133,  1134,  1135,  1136,  1136,  1137,
    1138,  1138,  1139,  1139,  1140,  1140,  1141,  1142,  1142,  1143,
    1143,  1143,  1143,  1144,  1144,  1144,  1145,  1146,  1146,  1147,
    1147,  1147,  1148,  1149,  1149,  1150,  1150,  1150,  1150,  1150,
    1150,  1150,  1150,  1150,  1150,  1150,  1150,  1150,  1150,  1150,
    1150,  1150,  1150,  1150,  1150,  1150,  1150,  1151,  1152,  1152,
    1153,  1153,  1154,  1156,  1155,  1157,  1158,  1158,  1159,  1159,
    1160,  1160,  1162,  1161,  1163,  1165,  1164,  1166,  1166,  1167,
    1167,  1168,  1168,  1169,  1169,  1169,  1169,  1170,  1170,  1171,
    1172,  1172,  1173,  1174,  1175,  1176,  1177,  1177,  1178,  1178,
    1180,  1179,  1181,  1179,  1182,  1179,  1183,  1179,  1184,  1179,
    1185,  1179,  1186,  1179,  1187,  1187,  1187,  1187,  1187,  1187,
    1189,  1188,  1190,  1190,  1192,  1191,  1191,  1191,  1191,  1191,
    1193,  1193,  1194,  1194,  1195,  1196,  1196,  1197,  1198,  1199,
    1200,  1200,  1200,  1201,  1201,  1201,  1201,  1202,  1203,  1203,
    1204,  1204,  1205,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  1207,  1207,  1208,  1208,  1209,  1209,  1209,  1209,  1209,
    1209,  1209,  1209,  1209,  1209,  1210,  1210,  1211,  1211,  1211,
    1211,  1212,  1212,  1213,  1213,  1214,  1214,  1214,  1214,  1214,
    1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,
    1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1214,  1215,
    1215,  1215,  1217,  1218,  1219,  1220,  1221,  1222,  1216,  1223,
    1223,  1224,  1225,  1225,  1227,  1228,  1229,  1230,  1231,  1232,
    1226,  1233,  1235,  1236,  1237,  1234,  1238,  1238,  1238,  1238,
    1239,  1239,  1239,  1239,  1239,  1240,  1241,  1241,  1241,  1242,
    1242,  1244,  1245,  1243,  1246,  1247,  1243,  1248,  1248,  1249,
    1249,  1250,  1250,  1251,  1251,  1251,  1252,  1252,  1253,  1253,
    1254,  1254,  1255,  1256,  1256,  1257,  1257,  1257,  1257,  1257,
    1257,  1257,  1258,  1258,  1259,  1259,  1260,  1260,  1261,  1261,
    1262,  1262,  1263,  1264,  1264,  1265,  1265,  1266,  1267,  1267,
    1268,  1269,  1269,  1270,  1270,  1271,  1271,  1272,  1273,  1273,
    1273,  1273,  1273,  1273,  1273,  1273,  1273,  1273,  1273,  1274,
    1274,  1275,  1275,  1276,  1277,  1279,  1278,  1281,  1280,  1280,
    1282,  1282,  1283,  1283,  1284,  1284,  1285,  1285,  1287,  1288,
    1286,  1289,  1289,  1290,  1291,  1290,  1292,  1293,  1292,  1294,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  1295,  1296,  1297,
    1298,  1298,  1299,  1300,  1300,  1301,  1301,  1301,  1302,  1303,
    1304,  1304,  1305,  1306,  1306,  1308,  1307,  1309,  1309,  1309,
    1309,  1309,  1309,  1309,  1309,  1309,  1309,  1309,  1309,  1310,
    1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,  1314,  1314,
    1315,  1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,  1320,
    1320,  1321,  1321,  1322,  1322,  1323,  1324,  1325,  1326,  1327,
    1327,  1328,  1328,  1329,  1329,  1330,  1330,  1331,  1331,  1331,
    1332,  1332,  1333,  1334,  1334,  1335,  1335,  1336,  1336,  1337,
    1337,  1337,  1337,  1337,  1338,  1339,  1340,  1341,  1341,  1342,
    1342,  1343,  1344,  1345,  1345,  1346,  1347,  1348,  1348,  1349,
    1349,  1349,  1350,  1350,  1351,  1351,  1352,  1353,  1353,  1354,
    1354,  1355,  1355,  1356,  1356,  1357,  1357,  1358,  1358,  1359,
    1359,  1360,  1360,  1361,  1361,  1362,  1362,  1363,  1364,  1364,
    1364,  1364,  1365,  1365,  1366,  1366,  1367,  1367,  1368,  1368,
    1368,  1368,  1368,  1368,  1368,  1369,  1369,  1369,  1369,  1369,
    1369,  1369,  1369,  1370,  1370,  1370,  1371,  1371,  1371,  1371,
    1372,  1372,  1372,  1373,  1373,  1374,  1374,  1374,  1374,  1374,
    1374,  1374,  1374,  1374,  1374,  1374,  1374,  1374,  1374,  1374,
    1374,  1374,  1375,  1375,  1376,  1376,  1376,  1376,  1376,  1377,
    1378,  1379,  1380,  1380,  1380,  1380,  1381,  1382,  1382,  1382,
    1383,  1383,  1384,  1384,  1384,  1385,  1386,  1386,  1386,  1386,
    1386,  1387,  1388,  1389,  1389,  1390,  1390,  1391,  1391,  1391,
    1391,  1391,  1391,  1391,  1391,  1392,  1392,  1392,  1392,  1392,
    1392,  1392,  1392,  1393,  1393,  1393,  1393,  1393,  1393,  1393,
    1394,  1394,  1394,  1394,  1394,  1394,  1394,  1395,  1395,  1396,
    1398,  1397,  1399,  1397,  1400,  1397,  1401,  1397,  1402,  1402,
    1402,  1403,  1403,  1404,  1404,  1404,  1405,  1405,  1406,  1406,
    1407,  1409,  1410,  1408,  1411,  1412,  1412,  1413,  1414,  1414,
    1414,  1414,  1414,  1415,  1416,  1416,  1417,  1418,  1419,  1419,
    1419,  1419,  1420,  1420,  1421,  1421,  1421,  1422,  1423,  1423,
    1423,  1424,  1424,  1424,  1424,  1424,  1425,  1425,  1425,  1425,
    1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,
    1425,  1425,  1425,  1425,  1425,  1425,  1426,  1426,  1427,  1427,
    1428,  1429,  1429,  1430,  1430,  1431,  1431,  1432,  1432,  1433,
    1433,  1434,  1435,  1435,  1436,  1436,  1437,  1438,  1438,  1438,
    1439,  1439,  1440,  1441,  1442,  1443,  1444,  1444,  1445,  1445,
    1445,  1445,  1445,  1445,  1446,  1446,  1446,  1448,  1447,  1449,
    1449,  1450,  1450,  1450,  1451,  1452,  1454,  1455,  1453,  1456,
    1456,  1456,  1457,  1457,  1457,  1457,  1457,  1457,  1458,  1458,
    1459,  1460,  1461,  1461,  1462,  1462,  1463,  1463,  1464,  1464,
    1464,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1467,  1468,  1468,  1469,  1470,
    1470,  1471,  1471,  1471,  1471,  1472,  1472,  1472,  1473,  1473,
    1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,  1474,
    1475,  1475,  1475,  1475,  1475,  1476,  1476,  1477,  1479,  1480,
    1478,  1481,  1481,  1482,  1482,  1483,  1483,  1483,  1483,  1483,
    1483,  1483,  1484,  1484,  1485,  1485,  1486,  1486,  1487,  1487,
    1488,  1488,  1489,  1490,  1491,  1492,  1492,  1493,  1494,  1494,
    1495,  1496,  1496,  1498,  1497,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,
    1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499,  1499
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     5,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     5,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       5,     1,     3,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     0,     7,     8,     6,     1,     6,
       0,     0,     9,     0,     0,     0,     8,     0,     0,    10,
       0,     0,     9,     0,     0,     0,    14,     0,     2,     0,
       2,     1,     0,     1,     1,     3,     1,     1,     1,     1,
       3,     0,     6,     0,     5,     1,     2,     1,     2,     1,
       0,     0,     3,     0,     0,     3,     0,     4,     0,     4,
       2,     2,     2,     1,     2,     2,     3,     1,     1,     1,
       2,     1,     1,     2,     1,     1,     0,     0,     5,     7,
       8,     0,     2,     1,     3,     1,     3,     3,     1,     2,
       0,     4,     0,     4,     0,     3,     0,     3,     0,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       4,     0,     4,     1,     1,     0,     1,     1,     2,     0,
       0,     5,     1,     1,     1,     3,     0,     2,     4,     4,
       4,     4,     2,     0,     4,     1,     1,     1,     2,     1,
       1,     3,     0,     1,     0,     7,     0,    12,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     0,     4,     0,
       5,     0,     7,     1,     3,     1,     1,     0,     1,     0,
       0,     4,     1,     1,     1,     4,     4,     6,     1,     2,
       1,     1,     1,     1,     4,     6,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       4,     1,     1,     0,     3,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     0,     3,     0,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     1,     0,     5,     1,     1,     1,     4,
       4,     6,     1,     1,     1,     1,     4,     6,     1,     4,
       6,     1,     1,     1,     1,     1,     2,     2,     1,     4,
       0,     7,     0,    12,     0,     4,     0,     5,     1,     3,
       2,     1,     3,     1,     0,     2,     2,     1,     2,     5,
       4,     2,     4,     5,     3,     0,     0,    11,     0,     2,
       1,     0,     2,     1,     2,     0,     3,     0,     3,     0,
       3,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     2,     1,     1,     3,     4,
       4,     2,     2,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     1,     0,     3,     2,     2,     1,     3,     4,
       4,     5,     5,     1,     1,     2,     2,     4,     4,     2,
       2,     4,     4,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     0,
       0,     6,     0,     0,     8,     0,     0,     6,     0,     0,
       6,     0,     0,     6,     0,     0,     6,     5,     5,     5,
       7,     0,     3,     1,     1,     4,     4,     4,     4,     4,
       4,     1,     1,     1,     1,     4,     4,     2,     2,     2,
       2,     2,     1,     1,     2,     1,     1,     1,     2,     4,
       6,     6,     3,     5,     5,     3,     1,     1,     3,     1,
       3,     0,     0,    11,     0,     2,     0,     0,     0,     8,
       0,     0,    10,     0,     1,     0,     1,     1,     2,     0,
       3,     0,     3,     0,     1,     1,     2,     0,     3,     0,
       3,     3,     1,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     0,     3,     0,     3,     0,     4,     0,
       4,     0,     4,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     4,     6,     4,     3,
       6,     3,     6,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     4,     1,     1,     1,     4,     3,
       6,     3,     6,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     1,     2,     2,     2,     4,     2,     2,
       4,     0,     8,     0,     1,     1,     1,     0,     1,     2,
       0,     1,     2,     0,     1,     2,     0,     1,     3,     0,
       2,     0,     7,     0,     0,     3,     0,     0,     7,     5,
       2,     2,     0,     5,     4,     1,     3,     3,     3,     0,
       2,     0,     1,     1,     2,     0,     4,     0,     4,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     0,
       3,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     3,     2,     4,     1,     1,     1,     0,     4,
       5,     6,     0,    10,     3,     1,     1,     2,     2,     0,
       2,     1,     2,     3,     3,     3,     3,     1,     1,     1,
       1,     0,     3,     1,     0,     3,     2,     0,     3,     1,
       3,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     7,     1,     1,     2,     2,
       2,     3,     4,     0,     3,     0,     1,     1,     2,     1,
       1,     1,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     0,     0,     0,
       0,    13,     1,     0,     0,     6,     2,     1,     2,     2,
       1,     1,     2,     1,     1,     1,     0,     3,     2,     1,
       0,     0,     0,    14,     0,     5,     1,     0,     3,     0,
       7,     0,     5,     1,     2,     0,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     0,     0,     7,     1,     2,     0,     3,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     1,     1,     1,     1,     2,     2,
       2,     5,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     2,     2,     3,     6,     1,     3,     1,     1,     1,
       3,     6,     1,     1,     1,     1,     2,     0,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       2,     0,     1,     1,     4,     1,     3,     1,     3,     7,
       0,     7,     0,     6,     3,     1,     3,     1,     2,     5,
       0,     7,     0,     2,     0,     1,     5,     2,     5,     0,
       5,     6,     4,     0,     1,     1,     4,     0,     2,     0,
       5,     4,     2,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       2,     4,     1,     0,    10,     5,     0,     1,     0,     2,
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
       1,     0,     0,     7,     0,     0,     8,     3,     2,     0,
       1,     1,     3,     2,     2,     1,     1,     3,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     1,     3,     1,     3,     2,     4,
       1,     3,     1,     2,     4,     1,     3,     1,     1,     1,
       2,     2,     4,     2,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     6,     6,     0,
       1,     0,     1,     2,     1,     0,     5,     0,     5,     1,
       0,     3,     1,     3,     1,     3,     1,     1,     0,     0,
       5,     2,     1,     0,     0,     3,     0,     0,     3,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     3,     3,
       1,     3,     2,     1,     1,     0,     1,     1,     1,     1,
       0,     1,     3,     1,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       0,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       0,     3,     1,     3,     1,     3,     1,     1,     6,     0,
       3,     1,     3,     0,     1,     4,     5,     2,     1,     1,
       4,     1,     3,     4,     4,     1,     3,     1,     1,     1,
       2,     1,     4,     0,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     0,     2,     1,     1,     1,     5,     3,
       5,     3,     1,     3,     1,     1,     0,     1,     3,     3,
       3,     6,     4,     4,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     1,     5,     5,     1,
       1,     1,     4,     1,     4,     1,     7,     1,     1,     1,
       4,     6,     0,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     1,     0,     3,     5,
       1,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     8,     0,     9,     0,     7,     0,     9,     0,     1,
       2,     1,     3,     1,     3,     5,     1,     1,     1,     1,
       2,     0,     0,     8,     5,     1,     1,     6,     0,     3,
       1,     3,     4,     1,     0,     2,     4,     6,     0,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     1,     2,
       2,     1,     1,     1,     2,     4,     3,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     3,     0,     1,
       5,     7,     5,     0,     2,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       4,     6,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     0,     4,     1,
       2,     1,     1,     1,     2,     2,     0,     0,     6,     0,
       2,     2,     7,     3,     3,     2,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       2,     1,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     3,     5,     5,     5,     5,
       5,     4,     4,     3,     4,     1,     1,     3,     1,     2,
       1,     1,     1,     3,     5,     1,     1,     1,     1,     3,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     2,
       1,     3,     2,     1,     2,     1,     2,     1,     0,     0,
       6,     0,     2,     0,     1,     1,     2,     2,     1,     1,
       4,     3,     1,     3,     1,     2,     5,     2,     2,     5,
       0,     2,     1,     1,     2,     6,     6,     1,     0,     1,
       2,     1,     2,     0,     2,     1,     1,     1,     1,     1,
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
     835,     0,  1813,  1816,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   886,   179,   859,   864,   177,
     182,   839,     0,   833,   836,   837,   840,   842,   885,   841,
     880,   881,   883,   183,   134,   131,     0,   127,   129,   128,
     132,  1857,   711,   611,  1820,     0,     0,  1823,     0,  1819,
    1815,  1812,  1810,  1811,  1818,  1817,  1814,   294,  1618,  1617,
     879,   175,   186,   178,   183,     1,   843,   838,   884,   882,
     860,   126,   130,   133,  1827,  1824,     0,  1825,  1822,     0,
       0,   590,     0,     0,   176,   889,   953,   591,   887,   623,
     946,     0,   947,   954,   952,   186,   180,   199,     0,   184,
     200,   229,     0,   866,  1234,     0,     0,   865,   135,  1222,
     873,     0,     0,   856,   858,   855,   857,   834,   844,   845,
     867,   848,   849,   850,   853,   851,   852,   854,  1826,  1821,
       0,   948,   888,     0,     0,   961,   959,   960,   950,   949,
     292,   186,  1158,   193,   187,   186,   192,   226,     0,   710,
       0,     0,     0,     0,   175,   540,   922,   846,     0,   326,
     312,   202,   263,   282,   303,   305,   302,     0,   324,     0,
     311,   304,   308,   314,   298,   313,   186,   315,   295,   318,
     296,   297,   958,   957,     0,    21,    22,    13,     0,   967,
       0,    15,     0,   965,     0,   293,     0,   185,  1159,   181,
       0,   199,   201,   259,   253,   254,   242,   219,   250,   202,
     221,   263,   282,   240,   243,   238,     0,   217,     0,   249,
     241,   246,   252,   234,   251,   186,   255,   186,   232,   233,
     230,   258,     0,     0,     0,     0,   874,   175,   175,     0,
       0,   203,     0,   316,     0,     0,   317,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,   955,     0,    16,
      17,    19,    18,    20,     0,    14,     0,   963,     0,   624,
     188,   191,     0,   189,   190,     0,   196,   195,   194,   197,
     186,     0,   186,   256,   257,     0,     0,   186,     0,     0,
       0,     0,   239,   227,  1235,     0,     0,  1223,  1863,   541,
     923,   868,     0,   208,   209,     0,   275,   277,   272,   273,
     269,   271,   268,   270,   267,     0,   277,   288,   289,   285,
     287,   284,   286,   279,     0,     0,     0,   328,     0,   331,
     333,   216,     0,   215,     0,     0,   186,    11,    12,   966,
       0,   951,   625,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   228,   231,   977,   709,   890,   977,
       0,  1861,  1863,  1158,  1714,   861,     0,   977,     0,     0,
     264,     0,     0,   274,   291,   265,   290,     0,   283,     0,
     306,     0,   300,     0,   325,     0,   330,   320,     0,     0,
     309,   299,   262,   319,     0,     0,     0,     0,     0,   244,
       0,   236,   218,   204,     0,   247,   235,   260,   983,     0,
     978,   979,   977,     0,   875,  1862,  1860,     0,     0,     0,
       0,     0,     0,     0,     0,  1844,     0,  1324,  1323,     0,
    1325,     0,   376,  1322,  1264,     0,     5,  1321,   377,   374,
       0,   379,   173,   468,  1136,     0,     0,  1331,   123,   373,
     372,  1256,   367,     0,  1281,  1835,     0,   378,   345,     0,
       3,     2,     0,   375,  1261,     0,     0,   368,   365,   380,
       0,     0,     0,     0,  1329,  1319,   371,     0,     0,     0,
       0,     0,     0,     0,     0,  1318,     0,     0,     0,   174,
    1258,   364,   363,     0,     0,  1839,  1838,     0,     0,     0,
     136,  1257,   370,   369,     0,     0,   366,   941,   468,     0,
     536,     0,     0,     0,   468,     0,     0,     0,   468,   822,
    1232,     0,     0,  1140,     0,  1828,     0,   103,     0,     0,
     894,     0,     0,     0,     0,   823,     0,     0,  1737,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,     0,
       0,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,
    1874,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,
    1884,  1885,  1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,
    1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,
    1904,  1905,  1906,  1907,  1908,  1909,  1910,  1911,   932,  1912,
    1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,  1922,
    1923,  1924,  1925,  1926,  1927,  1928,  1127,  1129,  1124,  1126,
    1125,  1128,  1929,  1930,  1255,  1931,  1260,  1259,  1932,  1933,
    1934,  1935,  1936,  1937,  1938,  1939,  1940,  1941,  1385,  1942,
    1943,  1944,  1945,  1946,  1947,  1948,  1949,  1864,   862,   545,
     863,     0,   927,     0,   925,     0,   327,   210,   211,     0,
     276,   281,     0,     0,     0,     0,   329,   332,     0,   214,
       0,   964,   220,     0,   186,     0,     0,     0,     0,     0,
    1236,     0,     0,  1224,     0,     0,  1268,   612,   613,   847,
    1099,  1104,  1837,   605,   122,     0,     0,  1802,  1801,  1037,
    1798,  1800,  1852,     0,  1275,     0,  1271,  1280,     7,     0,
       6,     0,  1845,  1100,     0,  1192,  1191,  1139,  1190,  1138,
       0,     0,   423,   425,     0,  1229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1585,     0,     0,     0,
     417,     0,     0,     0,     0,   416,     0,     0,   433,     0,
     504,     0,     0,     0,     0,     0,     0,     0,   412,  1332,
       0,   383,   382,   389,   429,   426,   384,   502,   494,   385,
     387,   501,   388,   953,   424,   427,   432,  1320,   503,  1716,
    1326,   124,     0,  1103,   121,     0,   829,    23,   607,   381,
       0,   828,  1096,   830,     0,  1330,   916,   915,   918,   914,
     917,  1854,     0,   912,     0,   606,  1010,   913,  1848,     0,
    1836,   120,  1007,   712,  1005,     0,   603,  1831,   766,   765,
       0,   767,   595,   763,     0,     0,  1020,   608,  1384,  1380,
    1383,     0,     0,  1072,  1070,     0,  1064,  1066,  1065,  1063,
    1062,     0,     0,     0,  1061,     0,   803,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1051,  1042,
    1043,     0,  1084,   410,    23,   876,   402,  1842,     0,  1833,
     125,   604,     0,  1069,  1068,  1233,  1231,  1157,     0,  1705,
    1706,  1158,  1246,  1158,  1141,  1142,  1145,  1160,  1333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
     953,     0,    68,     0,   101,   583,   669,     0,  1130,  1027,
    1134,     0,     0,  1085,  1250,     0,     0,  1137,   673,   670,
     671,     0,   675,   676,     0,   678,   679,     0,   674,   987,
     989,     0,     0,   988,   768,   985,   721,   981,   945,     0,
       0,     0,     0,   685,   686,     0,     0,   943,   939,   940,
     936,   937,   938,   931,   935,   934,     0,     0,     0,     0,
       0,     0,   549,   551,   543,   546,   547,   929,  1863,   924,
     926,   869,     0,   278,   280,   307,   301,     0,     0,   310,
       0,   225,     0,   223,   245,   237,   229,   248,   984,   175,
     980,   891,   175,     0,     0,     0,  1308,  1309,     0,     0,
       0,  1282,  1283,  1285,  1286,  1287,  1291,  1290,  1288,  1289,
       0,     0,  1799,   962,     0,  1039,     0,     0,  1274,  1273,
       0,  1267,     0,  1563,  1564,     0,  1101,     0,    23,  1187,
    1189,  1188,   391,   390,     0,     0,  1164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,  1593,  1591,  1592,
    1588,  1590,  1587,  1589,  1581,     0,     0,     0,     0,     0,
     430,     0,     0,   508,   507,     0,     0,   478,   475,   484,
       0,   481,     0,     0,   415,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,   509,   510,
     511,   444,     0,     0,   443,   453,     0,     0,   395,     0,
       0,   396,   386,   392,   394,   397,   398,   399,   400,   401,
     393,   422,   421,   469,     0,     0,   997,     0,     0,   350,
      24,   344,     0,     0,  1093,     0,     0,     0,     0,     0,
       0,     0,  1014,  1715,     0,     0,   186,     0,     0,     0,
    1833,     0,     0,     0,     0,     0,   137,     0,     0,  1024,
    1016,  1017,  1022,  1381,  1382,   942,   334,   408,     0,   537,
     588,   587,   585,  1045,   589,  1050,  1046,  1049,   796,     0,
    1047,  1048,   797,  1055,  1059,  1052,  1053,  1057,  1058,  1056,
    1054,  1060,     0,   831,     0,     0,     0,   405,   406,   403,
     404,     0,     0,     0,   776,   775,   774,  1834,  1841,    23,
    1153,  1154,  1155,  1156,  1150,  1148,  1247,  1162,  1147,  1143,
       0,     0,  1144,  1829,     0,     0,     0,     0,    97,     0,
      98,     0,     0,     0,    73,     0,     0,     0,   110,   105,
       0,   921,     0,   920,     0,   468,  1132,     0,   972,   973,
     996,   968,   969,   824,   994,  1087,  1252,     0,  1254,  1253,
    1741,     0,     0,     0,  1739,  1742,  1743,   701,     0,     0,
       0,   690,   721,   721,   719,     0,     0,   722,     0,    25,
     689,   692,     0,   699,   695,   944,   933,  1712,  1713,  1703,
    1703,     0,     0,  1619,     0,   186,  1334,     0,     0,  1335,
    1378,   186,     0,  1379,     0,  1658,     0,  1348,     0,  1396,
    1395,  1394,  1392,  1393,  1391,  1389,  1386,  1460,  1459,  1387,
    1388,  1397,  1628,  1390,  1719,  1718,  1717,  1398,  1863,  1863,
     562,   553,   544,     0,   548,  1863,   928,   175,     0,   321,
     213,     0,   186,   222,   205,  1237,   175,  1225,  1450,     0,
    1449,     0,  1451,     0,  1452,  1311,     0,  1317,  1313,  1310,
       0,     0,     0,     0,     0,     0,  1307,  1303,  1439,  1438,
    1437,  1279,  1278,     0,  1302,  1298,     0,  1294,  1292,     0,
     616,     0,   615,     0,  1038,     0,     0,  1036,  1805,  1807,
    1806,  1803,  1853,  1850,  1272,     0,     0,     0,  1265,   468,
     342,     0,   529,  1230,     0,     0,     0,     0,  1658,     0,
       0,     0,     0,     0,   526,   512,   517,     0,   513,   516,
     515,     0,     0,     0,     0,     0,     0,   418,     0,   171,
       0,   434,     0,     0,     0,     0,     0,     0,     0,     0,
     436,   435,   454,   445,   460,   463,   464,   461,   467,   466,
     465,   455,   456,   458,   457,   459,   446,   450,   468,   462,
     449,   468,    92,     0,   428,     0,  1262,  1029,  1097,  1098,
    1095,  1094,     0,   919,     0,     0,   592,     0,     0,     0,
    1008,  1006,     0,   714,   715,     0,     0,  1832,  1840,     0,
       0,   599,     0,   601,   764,     0,   141,     0,  1018,  1025,
       0,     0,  1033,     0,   337,     0,     0,     0,     0,    23,
    1071,  1356,     0,     0,   821,   808,   819,   820,   806,   807,
     815,   810,   814,   809,   818,   813,   816,   812,   817,   805,
     811,   804,   803,  1044,   832,   411,     0,  1076,     0,  1843,
     777,   778,   361,     0,  1158,     0,  1161,  1146,  1863,     0,
       0,     0,     0,     0,     0,     0,    63,    92,     0,     0,
     116,   111,     0,   106,     0,   113,   107,   905,   897,   903,
       0,  1131,     0,  1133,  1135,     0,     0,   976,     0,     0,
       0,     0,  1086,  1251,  1808,  1744,   992,  1745,   990,  1738,
    1740,  1863,   672,   677,   680,   693,   691,   609,     0,   745,
     743,   749,   747,     0,     0,   737,   793,   735,   731,   729,
     791,     0,     0,   769,     0,   723,   733,   986,   982,     0,
       0,     0,     0,   698,     0,     0,     0,     0,     0,     0,
       0,  1566,     0,  1455,  1456,  1724,  1419,  1477,     0,     0,
    1722,     0,     0,  1660,  1661,  1659,  1641,  1746,     0,  1402,
    1408,  1407,  1406,  1410,     0,  1403,  1404,     0,  1629,  1640,
     550,   552,     0,     0,   565,   557,   559,     0,   554,   555,
       0,     0,   573,   575,     0,     0,   571,   930,   870,   212,
       0,     0,   224,  1193,   892,  1171,  1427,  1429,     0,  1315,
       0,     0,     0,     0,     0,  1305,     0,     0,  1558,  1556,
    1543,  1545,  1541,     0,  1540,     0,  1549,  1536,  1557,     0,
    1548,  1533,  1539,  1555,  1547,  1443,  1530,  1531,  1532,     0,
    1300,  1296,     0,     0,  1284,   614,     0,     0,     0,     0,
       0,  1849,     4,     8,    10,  1562,  1565,     0,   468,     0,
     500,   497,   496,   499,   495,     0,   420,   506,   491,   491,
       0,   514,     0,   518,     0,   282,  1229,     0,  1586,   498,
    1229,   505,   419,   266,     0,  1229,   479,   476,   485,  1229,
     482,  1229,  1229,  1229,     0,     0,     0,     0,     0,     0,
       0,     0,   470,    93,    94,    96,   472,     0,     0,     0,
    1026,     0,     0,     0,     0,     0,     0,     0,   186,   713,
       0,   596,   598,     0,     0,   158,   156,     0,     0,   138,
       0,   148,   154,   721,   143,   145,     0,  1023,  1034,  1035,
       0,   409,   336,   341,   594,   335,     0,   338,   343,  1357,
     538,   586,   584,   803,   798,   799,  1075,  1077,     0,   407,
     362,  1151,  1149,  1248,  1249,     0,     0,  1242,     0,     0,
       0,    99,     0,     0,    74,    80,    70,  1863,  1863,   109,
     104,   118,   114,     0,   108,   794,   906,   609,  1863,   896,
     895,   904,  1028,     0,     0,   974,   975,   970,   995,   468,
       0,     0,  1685,  1576,  1579,  1686,  1583,  1577,  1683,     0,
       0,  1092,  1682,     0,     0,  1684,     0,     0,     0,     0,
       0,  1802,  1578,  1088,  1089,  1681,  1580,  1673,  1091,  1668,
    1671,  1672,     0,     0,     0,   703,   696,   694,     0,    23,
       0,  1863,  1863,  1863,  1863,   759,   725,   761,   727,  1863,
    1863,  1863,  1863,   803,   754,   753,   741,   751,   758,   757,
     739,   755,   720,   724,  1863,   609,   789,   787,   790,   788,
       0,     0,    45,    43,    40,    34,    38,    42,    37,    30,
      39,     0,    33,    36,    31,    41,    32,    44,    35,     0,
      28,    46,   781,     0,   700,  1704,     0,  1702,  1658,  1700,
    1645,  1646,  1638,  1624,  1639,     0,     0,     0,  1067,  1454,
    1457,     0,     0,     0,     0,  1478,  1368,  1340,  1727,  1726,
    1725,     0,     0,     0,     0,  1363,     0,  1362,     0,  1364,
    1359,  1360,  1361,  1352,  1349,     0,     0,  1409,     0,     0,
       0,  1633,  1630,  1631,   564,   569,     0,     0,  1863,  1863,
     542,   556,   579,   567,   581,  1863,  1863,   577,   561,   572,
     861,   322,   206,     0,  1219,  1238,   861,     0,  1226,  1219,
       0,     0,  1312,     0,     0,     0,     0,     0,  1483,  1485,
    1487,  1525,  1524,  1523,  1489,  1506,  1314,     0,  1567,     0,
    1428,     0,  1431,  1570,     0,  1435,     0,  1304,     0,     0,
    1609,  1607,  1608,  1604,  1606,  1603,  1605,     0,     0,     0,
       0,     0,     0,     0,     0,  1441,     0,  1444,  1445,     0,
    1299,     0,  1293,  1295,  1804,     0,     0,     0,  1851,     0,
       0,  1276,   877,     0,   530,     0,  1662,  1664,   488,     0,
     489,     0,   528,     0,   525,   522,   493,   487,  1167,  1594,
    1166,     0,   170,  1165,     0,     0,     0,  1168,     0,  1170,
    1169,  1163,   447,   448,   452,   437,     0,   440,   451,     0,
     439,     0,     0,    92,     0,     0,     0,     0,  1327,  1856,
    1855,   593,     0,     0,    47,     0,   718,   717,   716,  1328,
       0,     0,   721,  1863,  1863,   150,   617,   160,   152,   162,
     142,   149,  1863,     0,     0,     0,     0,     0,     0,     0,
    1863,     0,   801,   609,     0,  1830,     0,    92,     0,    64,
       0,     0,     0,    77,     0,    92,    92,   117,   112,  1863,
    1863,   102,   803,   907,   901,   909,   908,   898,   534,   956,
       0,     0,  1670,  1669,  1582,     0,  1658,     0,     0,  1526,
       0,  1526,  1526,  1526,  1526,  1674,     0,     0,     0,     0,
       0,     0,  1728,  1729,  1730,  1731,  1732,  1733,  1677,  1809,
     993,   991,   706,   704,     0,   683,   697,   610,   770,     0,
     746,   744,   750,   748,     0,  1863,     0,  1863,   738,   736,
     732,   730,   792,     0,  1863,     0,  1863,   734,    23,   782,
       0,     0,     0,    26,     0,  1707,     0,  1628,     0,     0,
    1637,  1620,  1636,  1458,     0,  1421,     0,  1367,  1465,     0,
       0,  1723,     0,  1720,  1642,     0,     0,     0,     0,     0,
       0,  1747,  1366,  1365,  1353,  1351,     0,  1412,     0,  1405,
       0,     0,     0,     0,   566,   563,   558,   560,     0,  1863,
    1863,   574,   576,  1863,  1863,     0,     0,  1217,  1218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1216,     0,     0,  1204,  1205,  1206,  1203,  1208,  1209,  1210,
    1207,  1194,  1185,     0,     0,  1241,     0,  1863,     0,  1180,
       0,     0,     0,     0,     0,     0,     0,  1172,  1173,     0,
    1105,     0,  1316,     0,  1492,     0,  1506,  1491,  1488,     0,
    1453,     0,  1520,  1517,  1518,  1515,  1522,  1521,  1516,  1519,
    1698,     0,  1698,  1507,     0,     0,     0,  1571,     0,  1572,
       0,     0,     0,     0,  1434,  1306,  1433,  1425,     0,     0,
       0,  1560,  1552,  1552,     0,     0,  1552,  1559,     0,  1576,
    1440,  1442,  1446,  1447,  1301,  1297,  1041,     0,  1004,     9,
       0,  1269,   878,  1102,     0,     0,  1477,  1648,   647,   632,
     645,   651,   666,   631,   643,   626,   659,   662,   665,   629,
     660,   638,   642,   653,   664,   661,   663,   654,   636,   634,
     658,   640,   639,   627,   628,   630,   633,   644,   656,   635,
     668,   646,   650,   652,   667,   641,   655,   657,   637,   648,
     649,  1666,  1665,     0,   491,   519,     0,   275,   480,   477,
     486,   483,     0,   442,   441,   471,    95,   473,   348,  1263,
       0,     0,  1847,     0,     0,  1009,    48,     0,   600,   602,
     597,   779,   159,   157,     0,  1863,     0,     0,     0,  1863,
     155,   144,     0,   147,   146,     0,  1015,  1019,   340,     0,
    1358,     0,   803,   800,    23,  1152,     0,  1243,    69,     0,
       0,   100,    67,    92,    75,    81,     0,   119,   115,   795,
    1863,   911,   609,   910,     0,   531,     0,   826,   827,   825,
       0,     0,  1694,     0,     0,     0,  1528,  1529,  1527,     0,
    1696,     0,     0,     0,     0,     0,     0,     0,  1090,  1679,
    1680,  1676,  1678,     0,  1863,   702,   687,   684,     0,   760,
     726,   762,   728,   752,   742,   756,   740,   771,   785,   786,
     783,   784,    29,    27,     0,  1701,  1654,  1625,  1626,  1622,
    1628,     0,  1420,  1658,  1423,     0,  1342,  1337,  1336,  1339,
       0,  1654,     0,     0,  1780,  1778,     0,     0,  1766,  1777,
       0,     0,  1779,     0,     0,     0,     0,     0,  1802,  1776,
    1772,     0,  1764,  1767,  1768,  1775,  1771,  1795,     0,  1757,
    1756,  1760,  1762,     0,  1755,     0,  1758,  1749,  1354,  1350,
       0,  1411,     0,     0,  1634,  1632,   570,   568,   580,   582,
     578,     0,     0,   229,  1211,  1212,  1213,  1215,  1198,  1196,
    1195,  1199,  1200,  1197,  1214,  1201,  1202,  1186,  1001,  1221,
     998,     0,     0,  1239,     0,  1184,  1183,  1178,  1176,  1175,
    1179,  1177,  1181,  1182,  1174,  1227,  1430,  1490,  1484,  1486,
    1496,  1493,  1699,  1495,     0,  1501,  1493,     0,  1499,  1698,
    1509,  1508,     0,  1510,     0,  1426,  1432,  1574,  1567,  1436,
    1616,  1614,  1615,  1611,  1613,  1610,  1612,  1542,     0,  1544,
       0,     0,     0,     0,  1550,  1554,     0,  1534,  1448,  1040,
    1277,  1270,  1266,  1663,     0,  1466,  1467,  1469,  1472,  1479,
       0,     0,  1526,  1650,  1644,  1601,  1599,  1600,  1596,  1598,
    1595,  1597,   492,   490,     0,   524,   523,   172,   438,     0,
       0,    23,     0,     0,  1032,     0,    49,  1012,     0,    23,
     161,   151,     0,   619,   621,   163,   153,   779,     0,   339,
     539,   802,  1073,     0,     0,    65,     0,    78,    87,     0,
      71,   902,   899,   535,  1863,   971,  1584,     0,     0,     0,
       0,  1695,     0,     0,  1693,     0,     0,     0,     0,  1675,
    1692,     0,   705,   682,   688,   609,  1711,     0,  1709,     0,
       0,  1628,  1628,  1621,  1422,     0,  1424,  1418,     0,  1341,
       0,  1721,     0,  1770,  1769,     0,     0,  1526,     0,  1526,
    1526,  1526,  1526,  1773,     0,     0,  1753,     0,     0,     0,
       0,  1782,  1754,     0,     0,     0,     0,     0,     0,  1748,
       0,  1413,  1416,  1400,  1414,  1417,     0,   872,   871,   323,
     207,  1003,  1002,  1000,     0,  1220,  1106,  1110,  1112,     0,
    1116,     0,  1114,  1118,  1107,  1108,     0,   893,     0,  1698,
    1513,     0,  1502,  1505,  1504,  1512,     0,  1493,     0,     0,
    1568,  1573,     0,  1561,  1553,  1537,  1535,     0,  1538,     0,
    1470,     0,  1575,  1473,     0,  1480,  1481,  1653,  1269,     0,
       0,     0,     0,   521,   520,   474,   349,   346,     0,  1030,
       0,     0,     0,  1011,   780,   139,   618,    23,  1021,  1078,
      66,  1244,    83,     0,     0,    76,    87,    87,  1863,   532,
       0,     0,     0,     0,  1691,  1697,  1687,  1688,  1689,  1690,
     707,   772,     0,  1708,  1655,  1648,  1627,  1623,     0,  1343,
       0,  1648,  1793,     0,     0,  1796,     0,     0,     0,     0,
       0,     0,     0,  1765,  1784,  1785,  1781,  1783,  1763,     0,
    1759,  1761,  1750,  1751,  1355,     0,  1401,  1399,  1635,   999,
    1863,  1863,  1120,  1863,  1122,  1863,  1863,  1109,  1240,  1228,
    1494,  1497,     0,  1500,  1498,  1514,     0,     0,     0,  1551,
    1474,     0,  1468,  1462,  1463,  1667,     0,  1482,  1476,  1651,
    1373,  1369,  1370,  1375,  1374,  1649,  1269,     0,   351,  1031,
    1846,     0,     0,     0,     0,     0,     0,    54,     0,    53,
       0,    51,     0,     0,   140,  1082,  1074,     0,  1080,    87,
      92,    87,    88,    82,    72,   900,     0,  1657,     0,  1736,
       0,  1863,    23,  1710,  1647,  1656,  1347,     0,  1344,  1346,
    1643,  1794,     0,     0,  1792,     0,     0,     0,     0,  1774,
    1791,     0,  1415,  1111,  1113,  1863,  1117,  1863,  1115,  1119,
    1503,  1511,  1569,  1546,     0,  1471,     0,  1461,     0,  1377,
    1376,  1372,  1652,  1602,   357,   355,   347,     0,   353,   359,
      56,    61,    58,    60,    57,    59,    55,     0,    50,     0,
     620,   622,  1863,  1079,  1081,  1245,    84,    79,   533,  1734,
    1735,   703,   773,     0,  1338,  1790,  1797,  1786,  1787,  1788,
    1789,     0,  1121,  1123,  1475,  1464,  1371,  1863,  1863,   352,
     354,  1863,    52,     0,  1083,     0,   708,  1345,  1752,   358,
     356,   360,     0,    85,  1013,    89,    91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   551,   552,   553,   554,   709,  1732,  1733,   189,   264,
     190,  1129,  1130,  1620,  1969,  3079,  2515,  2516,  2961,  3080,
    3081,   555,   898,  2549,  2206,  2977,  1557,  2204,  2818,  2553,
    2973,  2205,  2819,  3090,  3195,  3205,  2975,  3208,  1782,  1783,
    1784,  1229,  1850,   556,  1240,   903,  1238,  1565,  1860,  1562,
    1858,  1863,  2210,  1239,  1857,  1566,  2209,   557,    17,    36,
      37,    38,    39,    40,   114,   560,   825,  1496,  1156,  1809,
    1813,  1814,  1810,  1811,  2525,  2529,  2182,  2174,  2173,  2175,
    2178,  1111,  1063,  1764,   561,    83,    84,    19,    62,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     677,  2336,   305,   659,  1680,   332,   333,   229,   287,   280,
     282,   982,   983,   146,   355,   147,   148,   293,   230,   231,
    1482,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   662,   247,   248,   323,   375,   196,    20,    80,   178,
     179,   180,   668,  2335,   181,   251,   240,   326,   327,   328,
     329,  1509,   562,   563,   564,   565,   782,  3068,  2791,  1131,
    3146,  3147,  3148,  3188,  3187,  3191,   566,   567,   568,   569,
     758,  1112,   865,  1198,  1199,  1166,   862,  1167,   760,   761,
     762,   763,   764,   765,   766,  1066,  1113,  2146,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,   714,   767,  1462,  2151,  2153,
    2789,   768,  1433,  2135,  1432,  2134,  1436,  2138,  1434,  2136,
    2118,  2127,   769,   770,   771,   772,  1417,  1418,  1419,  1420,
    1401,   570,  2824,  3096,  2565,   571,   835,  1511,  2190,   115,
     237,   365,  1331,   964,   965,   966,  1328,  1329,  1667,  1668,
    1669,  2028,  2029,  1332,  1333,  1663,  2032,  2024,  1675,  1676,
    2035,  2036,  2333,  2329,  2330,   572,  1173,    85,  1477,  1478,
    1825,   867,   815,   870,   692,   804,   787,   826,  1919,    86,
     693,   687,  1381,  2177,    87,   774,  2491,   573,   574,   919,
     920,   575,   576,   577,   578,   927,  2596,   948,  2843,   949,
    1595,   950,  1916,   951,  2255,   952,  1623,   579,  1591,  2254,
    2594,  2593,  3101,   116,    21,   580,  1147,  1483,  1484,  1613,
    1278,  1614,  1615,  2265,  2267,  1932,  1931,  1944,  1930,  1929,
    2276,  2274,  1922,  1921,  1924,  1923,  1936,  1937,  1940,  1941,
    1926,  1928,   581,   582,   823,   583,  1274,   934,  3102,   584,
    1206,  2799,  1971,  1972,  1616,  1933,  1866,  2212,   858,  1183,
    1532,  1834,  2191,  1835,  1179,  1531,   585,   586,   912,  1580,
    2569,   587,   588,   589,   590,    22,    66,    23,    24,    25,
     117,   118,   591,   119,    26,   649,    27,   120,   121,   158,
     367,  1337,  2040,  2898,   122,   154,   298,   592,  2113,    28,
      29,    30,    31,    32,    61,    88,   123,   412,  1346,  2046,
     593,   907,  1870,  1569,  1868,  2978,  2560,  1570,  1867,  2215,
    2562,   594,   595,   596,   798,   799,  1242,   124,   238,   366,
     653,   654,   968,  1335,   597,   953,   954,   598,   831,  1286,
     955,   775,    90,    91,    92,    93,  1249,   184,   138,    94,
     698,   135,   192,   193,  1250,  1251,  1877,  1252,   409,   410,
     936,   411,   937,  1587,  1588,  1253,  1254,  1127,  2699,  2700,
    2903,  1390,   813,   814,   599,  1142,  2963,   600,  2537,   601,
    1160,  1161,  1162,  1502,  1500,   602,   603,  1790,  1820,   604,
    1015,  1387,   605,   859,   860,   606,   875,   607,  1982,   608,
    2969,   609,  1838,  3086,  3087,  3088,  3162,   864,   610,  1255,
    1582,  1903,  1904,   611,  1470,   691,  1027,   612,   613,   614,
    2048,  2703,  2914,  2915,  3030,  3031,  3035,  3033,  3036,  3125,
    3127,   615,   616,  1244,  1574,   617,  1246,   883,   884,   885,
    1222,   618,   619,   620,  1544,  1214,   878,   199,   886,   887,
     776,  2049,  2377,  2378,  2361,   717,   718,  2044,  2362,  2365,
     125,   153,   359,   992,  1685,  2379,  2918,  1036,   621,   876,
     126,   150,   356,   989,  1683,  2366,  2916,  2045,   902,  2197,
    2814,  3089,  1217,   622,   623,   624,   625,   626,   785,  1788,
     711,  1737,   627,  2762,   705,   706,  2110,  1366,   628,   629,
    1001,  1002,  1003,  1378,  1722,  1004,  1719,  1375,  1005,  1694,
    1367,  1006,  1007,  1008,  1009,  1688,  1358,   630,   794,   777,
     631,  1309,  1310,  1638,  2628,  2860,  2300,  2625,  3107,  3108,
    1311,  1648,  2314,  2014,  2669,  2890,  1830,  2189,  2015,  1312,
    1313,  2773,  3061,  3062,  3063,  3141,  1314,  1315,  1164,   632,
     829,   633,   961,  1316,  1317,  3027,  1654,  1655,  1656,  2017,
    2316,  2893,  2894,  1318,  1992,  2294,  2857,  1368,  1369,  1354,
    2069,  1686,  2070,  1370,  2074,  1371,  2097,  1372,  2098,  2431,
    2432,  1689,  1319,  1632,  1633,  1989,  1320,  3057,  2945,  3053,
    1995,  2446,  2765,  2766,  2767,  3051,  2447,  1996,  2946,  3058,
    2057,  2058,  2059,  2060,  2061,  2920,  2721,  3040,  2062,  2921,
    2922,  2405,  2063,  2406,  2064,  2579,  1715,  1716,  1717,  2751,
    1718,  2428,  2422,  2934,  2071,  2895,  2409,  2661,  2073,  2943,
    1905,   778,  1906,  2224,  1054,  2119,  2782,  2087,  2747,    60,
     634,   635,  2620,  2852,  2287,  2851,  1659,  2022,  2023,  2291,
    1983,  1321,  1984,  2003,  2631,  1409,  1979,  1980,  2774,  2948,
    2850,  2624,  1907,  1646,  2115,  2116,  3054,  2065,  1909,  1910,
    2581,  2723,   636,   637,  1625,  1981,  2615,  2847,  2848,  1289,
     638,   780,  1323,  1324,  1641,  2302,  1325,  1326,  2000,  2248,
    2575,   639,   915,  1263,  1264,  1265,  1266,  1327,  2004,  2667,
    2889,  2311,  2664,  2665,  2666,  2663,  2651,  2652,  2653,  2654,
    2655,  2656,  3006,   699,  1584,   701,  1391,  1911,    64,    49,
      78,    75,   641,   889,  1548,  1150,  1208,   642,   868,   643,
    2164,   644,  1731,   703,  1393,   645,   646,    43,   360,   361,
     362,   363,   364,   647
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2636
static const short yypact[] =
{
    2304,  1285, -2636, -2636,   352,   588,   588,   588,   588,   588,
     588,   588,   588,   352,  1115, -2636, -2636, -2636,  1687, -2636,
   -2636, -2636,   374, -2636,  2304, -2636, -2636, -2636, -2636, -2636,
    1843, -2636, -2636, -2636, -2636, -2636,   369,   482, -2636,   405,
   -2636, -2636, -2636, -2636, -2636,   352,    71, -2636,   -96, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,  2510,   196, -2636, -2636, -2636,  3349, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636,   352, -2636, -2636,    71,
      25, -2636,   352,   590,  1687, -2636,   538, -2636, -2636, -2636,
   -2636,  1131,   266, -2636, -2636, -2636,   829,   553,   352, -2636,
   -2636,   901,   352, -2636, -2636,   352,   352, -2636, -2636, -2636,
   -2636,   352,   352, -2636, -2636, -2636, -2636, -2636,  3349, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
    5249,   266, -2636,   923,   386, -2636, -2636,   465, -2636, -2636,
     912,   196,   441, -2636, -2636, -2636, -2636, -2636,  8059, -2636,
     352,   562,   892,   352,  1687, -2636, -2636, -2636,   352, -2636,
   -2636,   472,  1019, -2636, -2636,   587, -2636,   610, -2636,   600,
   -2636, -2636,   638, -2636,   661, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,   682, -2636, -2636, -2636,   386,  1545,
    1096, -2636,   195, -2636,   386, -2636,   276, -2636, -2636, -2636,
     154, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   472,
   -2636,  1019, -2636, -2636,   705, -2636,   726, -2636,   693, -2636,
   -2636,   737, -2636,   751, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,   810,  1196,   352,   814, -2636,  1687,  1687,   823,
     352, -2636,   518, -2636,   643,  1073, -2636,   665,  1187,  1278,
    1332,   352,  1354,  1382,  1390, -2636,   753, -2636,   545, -2636,
   -2636, -2636, -2636, -2636,   386, -2636,   386,   971,   221, -2636,
   -2636, -2636,  1406, -2636, -2636,  1413, -2636, -2636, -2636, -2636,
   -2636,   518, -2636, -2636, -2636,  1416,  1443,   196,  1354,  1458,
    1463,   836, -2636,  1435, -2636,  1108,  1101, -2636,  1175, -2636,
   -2636, -2636,   917, -2636, -2636,  1516, -2636,  1116, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636,  1187,  1116, -2636, -2636, -2636,
   -2636, -2636, -2636,  1124,   183,   216,   205, -2636,  4714, -2636,
   -2636, -2636,  1122,  1552,   342,  1194, -2636, -2636,  1545, -2636,
     386, -2636, -2636, -2636,   972,  1563,  1347,   361,   378,   323,
    1181,   404,  1217, -2636, -2636, -2636,   352, -2636, -2636,   352,
    1248, -2636,  3268,   441,  4673,  2355,   282,   352,  1589,   372,
   -2636,  1073,  1599, -2636, -2636, -2636, -2636,  1600, -2636,  1602,
   -2636,  1606, -2636,   352, -2636,   352, -2636, -2636,  1354,  1607,
   -2636, -2636, -2636, -2636,   234,  1621,   372,  1218,  1619, -2636,
    1630, -2636, -2636, -2636,  1631, -2636, -2636, -2636,  1039,  1271,
    1659, -2636,   352,  1283, -2636, -2636, -2636,   352,   256,   352,
     352,   256,   256,   980,   352, -2636,   352, -2636, -2636,   352,
   -2636,   852, -2636, -2636, -2636,   256, -2636, -2636, -2636, -2636,
     352, -2636, -2636, -2636, -2636,    61,    61,  7141, -2636, -2636,
   -2636, -2636, -2636,   256, -2636, -2636,   256, -2636, -2636,   352,
   -2636, -2636,   256, -2636, -2636,   295,   256, -2636, -2636,  7141,
     256,   295,   352,   295,   256, -2636, -2636,    90,   256,   256,
      90,   256,   352,    90,   256, -2636,   256,   256,   256, -2636,
   -2636, -2636, -2636,   295,   256, -2636, -2636,   256,    53,   352,
   -2636, -2636, -2636, -2636,   256,  1002, -2636, -2636, -2636,   256,
   -2636,  8352,   295,  7141, -2636,    57,    57,   256, -2636, -2636,
    1003,   295,  1071,  7141,  7141, -2636,  1311,  7141,   256,    71,
   -2636,  7141,   256,  7141,   295, -2636,   256,  7141, -2636,  7141,
      61,   352,   256,   352,    57,   256,   352,    57, -2636,   352,
     178, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,    41, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   770, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   714,
   -2636,   352, -2636,   569, -2636,  1284, -2636, -2636, -2636,  1375,
   -2636, -2636,  1290,  1291,  1295,  1299, -2636, -2636,  1063,  1685,
    1303, -2636, -2636,  1396, -2636,  1308,  1310,  1077,  1312,   352,
   -2636,   352,  1313, -2636,   254,  1275, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636,  1086,  1150,  1250, -2636,  1092,
   -2636,  1090, -2636,  1701,  -209,   421, -2636, -2636, -2636,  1287,
   -2636,  1177, -2636,  1241,   193, -2636, -2636, -2636,  1373, -2636,
    7141,  7141, -2636, -2636,  1294,  1195,  1301,  1321,  1327,  1328,
    1334,  1335,  1337,  1338,  1341,  7141,  1193,  1342,  1343,  1351,
   -2636,  7141,  7141,  1352,  1356, -2636,  7141,  1358, -2636,  1359,
    1360,  1365,  1367,  1370,  1371,  1374,  7141,  1378,  6087, -2636,
      65, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636,   828, -2636,  1306, -2636, -2636, -2636, -2636,
   -2636, -2636,   295, -2636, -2636,  1177, -2636,    26, -2636, -2636,
    1461, -2636,    62, -2636,  1307, -2636, -2636, -2636, -2636,  1734,
   -2636, -2636,   318, -2636,  1161, -2636,  1179,  1734, -2636,  1147,
   -2636, -2636,  1389,    84, -2636,  1361, -2636,  1157, -2636, -2636,
    1392, -2636,  -179, -2636,  1163,   180,  -219, -2636,  1086,  1500,
   -2636,  7141,  7141, -2636,  1816,   256, -2636, -2636, -2636, -2636,
   -2636,   198,   198,   198, -2636,   198, -2636,   198,   198,  1240,
      26,  1240,  1240,  1118,  1118,  1240,  1240,    26, -2636,  1830,
   -2636,   568,  1835, -2636,    26, -2636,  6709, -2636,    95,    64,
   -2636, -2636,  7141, -2636, -2636, -2636, -2636, -2636,   894, -2636,
   -2636,   441,  1465,   441,  7141, -2636,    75, -2636, -2636,  7141,
    1420,  1421,  1424,  1425,  1227,  1427,  1071,  1360, -2636,  1512,
     872,  1269, -2636,  1281, -2636, -2636, -2636,  1162, -2636,  1851,
   -2636,  1847,   352, -2636,   103,   157,  1289, -2636, -2636,  1859,
   -2636,  1210,  1859,  1863,  1221,  1859,  1863,  7141,  1859, -2636,
   -2636,   193,   295, -2636, -2636,  1462,   345, -2636, -2636,  1453,
     295,  7141,  1454, -2636, -2636,  1857,  1864,  1821, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636,  1178,  1178,   256,   256,
     256,  1369, -2636, -2636,  1802,   714, -2636, -2636,   626, -2636,
   -2636, -2636,  1437, -2636, -2636, -2636, -2636,  5249,  1354, -2636,
    1438, -2636,   424, -2636, -2636, -2636, -2636, -2636, -2636,  1687,
   -2636, -2636,  1687,   771,   173,  1869, -2636, -2636,   397,   189,
     438,  1890, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
    1363,  1150,  1090, -2636,   980,  -244,  1254,   352, -2636, -2636,
     352, -2636,  1304,  1288,  1314,  1475, -2636,  1478,   135, -2636,
   -2636, -2636,  6607,  6607,    57,  7141, -2636,    57,    57,    57,
      57,  1439,  7141,  1440,  1449,  7141,  6087,  1482, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636,  1298,    57,  1891,  7141,  3643,
    6087,  1439,  7141, -2636,  6087,  1895,   446, -2636, -2636, -2636,
    7141, -2636,  7141,  7141,  6087,  7141,  7141,  7141,  7141,  7141,
    7141,  7141,  7141,  7141,  7141,  7141,  7141,  7141,  7141,  7141,
    7141,  7141, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,  7141,  7141, -2636, -2636,  1483,  7141, -2636,  7141,
    1492, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,   352,   295, -2636,  1300,  1494, -2636,
   -2636, -2636,   980,  1186, -2636,  1186,  1071,    90,  7141,  7141,
    7141,  1496, -2636, -2636,   295,   295, -2636,  1305,  1071,    57,
    1267,   352,   386,    48,    53,   295, -2636,  1309,  7141,  1581,
   -2636, -2636,  1376, -2636, -2636,  1835,   116, -2636,   193, -2636,
   -2636,  1916,  1918, -2636, -2636, -2636, -2636, -2636, -2636,   886,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,  8352, -2636,  1118,  7141,   -91, -2636, -2636,  1929,
   -2636,    57,  1912,  1913, -2636, -2636, -2636, -2636, -2636,   136,
   -2636, -2636, -2636, -2636,  1790, -2636,  1726, -2636, -2636, -2636,
    7141,    61, -2636, -2636,   352,  1923,    57,    57, -2636,  1372,
   -2636,    57,  1333,   295, -2636,   352,   352,  7141,   245, -2636,
    1379, -2636,   242, -2636,  1477, -2636,  1486,  7141,   943, -2636,
   -2636,  1355, -2636,  1963, -2636,  1430, -2636,   295, -2636, -2636,
   -2636,   980,   295,   200, -2636, -2636, -2636, -2636,   352,    57,
      57,   241,   345,  1822,  1058,   295,   193, -2636,  1431, -2636,
   -2636,  1964,  1951,  1583, -2636, -2636, -2636, -2636, -2636,  1662,
    1662,   343,  1433, -2636,   352, -2636, -2636,  1177,  1177, -2636,
   -2636, -2636,   352, -2636,   352,   442,  1177, -2636,   794, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,  1242, -2636, -2636, -2636, -2636, -2636,   149,   149,
     708,   914, -2636,   692, -2636,   626, -2636,  1687,  1957, -2636,
   -2636,  1957, -2636, -2636, -2636, -2636,  1687, -2636, -2636,  1177,
   -2636,   866, -2636,  1556, -2636, -2636,   866, -2636, -2636, -2636,
    1558,  1564,   346,  1574,  1576,  1340, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636,   352, -2636, -2636,   346,  1345, -2636,   254,
   -2636,  1617,   266,  1391, -2636,  1071,  1434, -2636, -2636,  1555,
   -2636, -2636, -2636,  1467, -2636,   352,   352,   352, -2636, -2636,
   -2636,   429, -2636,  6087,  1625,  1627,   430,   432,   442,  1628,
    4160,  1633,   -43,  1419, -2636, -2636,   156,  1634, -2636, -2636,
   -2636,  5035,  1994,  1193,  1637,  1638,  5298, -2636,  1639,  2121,
    1640, -2636,  7141,  7141,  7141,  5334,  7141,  5356,  5459,  5503,
    6132,  6190,  4224,  6356,  6396,  3507,  6142,  6516,  6526,  2061,
    6561,  6607,  6607,  7378,  7170,  1735,  5620,  5888,  1439,  6087,
    5927,  1439,  7141,  1615, -2636,   352, -2636,  1428, -2636, -2636,
   -2636, -2636,  1436, -2636,  2039,  2043, -2636,  2044,  1476,  7141,
   -2636, -2636,  1441,  2050, -2636,  1577,  1466,  1863, -2636,  1670,
     428, -2636,  1635, -2636, -2636,  1451,  1044,   352, -2636, -2636,
    1646,   256,   883,  7141, -2636,   352,   352,  7141,    44,    26,
    2056,  1535,  2063,  2066, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,  1665, -2636, -2636, -2636,   295,  1560,  6709, -2636,
   -2636, -2636,  2033,  7141,   441,   927, -2636, -2636,  1777,  2099,
    2101,   437,   451,   352,  1721,  1071, -2636,  7141,  1683,  1690,
   -2636, -2636,  1762, -2636,  7141,   367, -2636,  1526, -2636, -2636,
     612, -2636,  7141, -2636, -2636,  1499,   923, -2636,  1297,   352,
    2111,  7331, -2636, -2636,  1708, -2636,  1727,  2138, -2636, -2636,
   -2636,   120, -2636,  1863,  1863,  1488, -2636,  1597,  1603, -2636,
   -2636, -2636, -2636,    57,    57, -2636, -2636, -2636, -2636, -2636,
   -2636,   402,   552, -2636,   307, -2636, -2636, -2636, -2636,    57,
    4053,  2145,  2132, -2636,  1071,   812,   246,   169,  2064,    30,
    1003, -2636,   141, -2636, -2636, -2636,  1732,   108,  1177,   142,
   -2636,  1546,  1539, -2636, -2636, -2636, -2636, -2636,  1074, -2636,
   -2636, -2636, -2636,  1738,  1547,  2166, -2636,  1384, -2636, -2636,
   -2636, -2636,   295,   150, -2636, -2636, -2636,  1536,   914, -2636,
     352,   352, -2636, -2636,   352,   699, -2636, -2636, -2636, -2636,
    1749,  1751, -2636,  1719, -2636,  1720, -2636,  1753,   453, -2636,
    7345,   456,   134,   134,   457, -2636,   134,  7345, -2636, -2636,
    1286,  1286, -2636,  1755, -2636,  1757,  1758, -2636,  1759,  1760,
   -2636,  1764, -2636, -2636, -2636,   164, -2636, -2636, -2636,   458,
   -2636, -2636,   461,   352, -2636, -2636,  1254,  2181,  1071,   386,
    7141, -2636,  2190, -2636, -2636, -2636, -2636,   346, -2636,    57,
   -2636, -2636, -2636, -2636, -2636,  7640, -2636, -2636,  1193,  1193,
    2167, -2636,  2173,  1612,  1464, -2636,  1195,  1812, -2636, -2636,
    1195, -2636, -2636, -2636,  1815,  1195,  6087,  6087,  6087,  1195,
    6087,  1195,  1195,  1195,  2180,  2182,  2184,  7141,  1817,  2185,
    7141,  1832, -2636,  2205, -2636,  6087, -2636,  1604,   346,   161,
   -2636,  1071,  7141,  7141,  7141,  6902,  2216,   100, -2636, -2636,
    1071, -2636,  1605,   352,   352, -2636, -2636,   352,   352, -2636,
    1155, -2636, -2636,   348, -2636,  1613,  7141, -2636, -2636, -2636,
    2222, -2636, -2636, -2636, -2636, -2636,   352,  1863, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   295, -2636,
   -2636,  4124, -2636, -2636, -2636,  1921,  2214, -2636,  1903,  1905,
    1792,  1641,  1914,  1831, -2636, -2636, -2636,   620,  1900, -2636,
   -2636, -2636, -2636,  1762, -2636, -2636, -2636,   243,   809, -2636,
   -2636, -2636,  1964,  7141,  1839, -2636,  1818, -2636, -2636, -2636,
    7873,  7873, -2636,  1086, -2636, -2636,  1286, -2636, -2636,  7441,
    1844, -2636, -2636,  1845,  1852, -2636,  1853,  1854,  1856,  1860,
     352,   420, -2636,  2273, -2636, -2636, -2636, -2636, -2636,  1976,
   -2636, -2636,   980,   295,   295,   113,  1642, -2636,  2259,    26,
     352,   630,   630,   630,   630, -2636,  2281, -2636,  2283,   630,
     630,   630,   630,  1665, -2636, -2636,  2285, -2636, -2636, -2636,
    2287, -2636, -2636, -2636,   630,    98, -2636, -2636, -2636, -2636,
    2269,  2284, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,  2295, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   462,
   -2636, -2636, -2636,  2271, -2636, -2636,  1177, -2636,   442, -2636,
   -2636, -2636, -2636, -2636, -2636,  1705,  1707,   145, -2636,   141,
   -2636,   134,  1679,   256,  7345, -2636, -2636,  1882, -2636, -2636,
   -2636,   352,   352,  7640,   312, -2636,  7141, -2636,  7141, -2636,
   -2636, -2636, -2636, -2636, -2636,   256,   134, -2636,  1177,   965,
    1693,  1694,  2308, -2636,  2310, -2636,   295,   352,  -223,  -223,
   -2636, -2636,  2318, -2636,  2318,   721,   721,  2318, -2636, -2636,
    2355, -2636, -2636,  2570,   119, -2636,  2355,  2165, -2636,   119,
     134,   866, -2636,  1907,  7222,  1907,  2815,   190,  2320, -2636,
   -2636, -2636, -2636, -2636, -2636,   970, -2636,  1177,   520,  1944,
    2330,  1718, -2636, -2636,   464, -2636,   346, -2636,   466,   231,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,  1716,  -165,  2316,
    2316,  2322,  2316,  2316,  2325, -2636,   204, -2636,   866,   352,
   -2636,   346, -2636, -2636,  1725,  1071,  2337,   251, -2636,   352,
     469, -2636,  7141,  1965, -2636,   151, -2636,  3907, -2636,  1728,
   -2636,  1966, -2636,  2326, -2636,  1770, -2636, -2636, -2636, -2636,
   -2636,  1736, -2636, -2636,  1970,  1971,  1973, -2636,  1974, -2636,
   -2636, -2636, -2636, -2636, -2636,  6087,   470, -2636, -2636,   476,
   -2636,  1975,  7141,  7141,  2344,   478,  1071,  2360, -2636, -2636,
   -2636, -2636,  7141,  1804,  2095,  7141, -2636, -2636, -2636, -2636,
    1336,  1984,   348,  1255,  1255,  2368,  -139, -2636,  2369, -2636,
   -2636, -2636,  1255,   352,  1834,  1350,  2371,   352,  -103,   295,
    2142,   479, -2636,  1597,  7141, -2636,  2377,  7141,   295, -2636,
     852,   352,   295, -2636,  1995,  7141,  7141, -2636, -2636,   620,
    1900, -2636,  1665, -2636, -2636,  1212, -2636, -2636,  1819, -2636,
     386,  7012,  1942,  1942, -2636,  1766,   442,  1998,   111,   484,
    7640,   484,   484,   484,   484,  1773,  7640,  7331,  7640,  7640,
    7640,  7640, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,  1955,   931, -2636, -2636, -2636,  1775,
   -2636, -2636, -2636, -2636,    57,   630,    57,   630, -2636, -2636,
   -2636, -2636, -2636,   402,   630,   552,   630, -2636,    26, -2636,
     997,  1099,  4053, -2636,  2006,  1968,  7640,  1242,   169,   169,
   -2636, -2636, -2636, -2636,   483, -2636,  1933, -2636,  2391,   134,
     811, -2636,  1779, -2636,  2399,  7708,  7708,  7708,  7708,   134,
     134, -2636, -2636, -2636,  1855, -2636,   485, -2636,  1781, -2636,
     352,   352,  1384,   295, -2636,  2318, -2636, -2636,   352,   721,
     721, -2636, -2636,   721,  2203,  1791,  1793, -2636, -2636,    61,
      61,    61,  2388,    61,    61,    61,    61,    61,    61,  2390,
   -2636,  2392,    61, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,  2570, -2636,   295,  1800, -2636,  1977,  2203,  2395, -2636,
    2397,  2398,  2401,  2405,  2406,  2408,  1230,  2165, -2636,  1977,
   -2636,   493, -2636,  1954, -2636,   299,   380, -2636, -2636,  7345,
   -2636,  7345, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
     264,  2008,   264, -2636,  2010,   561,  7640, -2636,  2414, -2636,
    2149,   134,  1368,   134, -2636, -2636, -2636, -2636,  1450,  2418,
    1450, -2636,  2440,  2440,   495,  2058,  2440, -2636,  2059, -2636,
   -2636, -2636,   866, -2636, -2636, -2636, -2636,  1071, -2636, -2636,
     346,  2189,  1964, -2636,  7640,   296,  1934,   -25, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636,  1468,  1193,  1865,  1472, -2636, -2636, -2636,
   -2636, -2636,  7141, -2636, -2636, -2636, -2636, -2636,  1991, -2636,
     202,  1071, -2636,  2457,  2038, -2636, -2636,  2078, -2636, -2636,
   -2636,  1920, -2636, -2636,   352,  1255,   386,  1426,   352,  1255,
   -2636, -2636,    57, -2636, -2636,  7141, -2636, -2636, -2636,    57,
    2138,  2232, -2636, -2636,    26,  6087,  2446, -2636, -2636,   193,
    2048, -2636, -2636,  7141, -2636, -2636,  2084, -2636, -2636, -2636,
     809, -2636,  1597, -2636,  7141, -2636,   274, -2636,  1835, -2636,
    1450,  7640, -2636,   313,  2468,  2086, -2636, -2636, -2636,  7640,
   -2636,   499,  7640,  7640,  7640,  7640,   352,   500, -2636, -2636,
   -2636, -2636, -2636,  7141,  2040, -2636,  2139, -2636,  2462, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,   352, -2636,   110, -2636, -2636, -2636,
    1242,   134, -2636,   442,  2347,   501, -2636, -2636, -2636, -2636,
     352,  1936,  5430,  5430, -2636, -2636,  7763,  2065, -2636, -2636,
    2067,  2068, -2636,  2070,  2072,  2075,  2076,   352,   591, -2636,
   -2636,   508, -2636, -2636,  2594, -2636, -2636, -2636,   511,  2480,
    2480, -2636, -2636,   519,  2483,  2477, -2636,   112, -2636, -2636,
     134, -2636,   165,  1873, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,  2299,  5249, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   412,  2502,
   -2636,   295,  1517, -2636,  2299, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,  2320, -2636,
   -2636,  2071, -2636, -2636,   107, -2636,  2071,   107, -2636,   264,
   -2636, -2636,  7640, -2636,   288, -2636, -2636, -2636,  2055, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,  2123, -2636,
    2488,  2127,  2129,  2494, -2636, -2636,  2133, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,   209,  2517, -2636, -2636,   352,  2160,
     352,  1909,   484,  2201, -2636,  2103, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,  1487, -2636, -2636, -2636,  6087,  2144,
      57,    26,  2168,  1071, -2636,  7141, -2636,  1978,  2514,    26,
   -2636, -2636,   433, -2636, -2636, -2636, -2636,   133,  2152,  1863,
   -2636, -2636, -2636,  2153,  2154,  2056,  2116, -2636,  2204,  2159,
   -2636, -2636, -2636, -2636,  2312, -2636, -2636,   151,  1286,  1924,
    1286, -2636,  2163,  7640, -2636,  2164,  2169,  2170,  2171, -2636,
   -2636,  1980, -2636, -2636, -2636,  1597, -2636,   521, -2636,   295,
    2012,  1242,  1242, -2636, -2636,  7640, -2636, -2636,   134, -2636,
    2134, -2636,  2012,  2021,  2021,  2174,   111,   484,  7859,   484,
     484,   484,   484,  1945,  7859,  7708, -2636,  7859,  7859,  7859,
    7859, -2636, -2636,   134,  2552,   134,  7708,   256,  7345, -2636,
     295, -2636, -2636,   334, -2636, -2636,   352, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,   295,  2502, -2636, -2636, -2636,   295,
   -2636,   295, -2636, -2636,  1346, -2636,  2332, -2636,  2333,   204,
   -2636,   525, -2636, -2636, -2636, -2636,   529,  2071,  2559,  2545,
   -2636, -2636,  1947, -2636, -2636, -2636, -2636,  2188, -2636,   296,
   -2636,   296, -2636, -2636,  7640, -2636,  2140, -2636,  2189,   126,
     246,   352,  2548, -2636, -2636, -2636, -2636, -2636,  1071, -2636,
    2194,  8054,  2150, -2636, -2636, -2636,  1967,    26, -2636,    15,
   -2636, -2636, -2636,  2198,   193, -2636,  2204,  2204,   809, -2636,
    2199,  1972,  1450,  1979, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,   352, -2636,  2138,   -25, -2636, -2636,   151, -2636,
    7630,   -25, -2636,  2200,  7859, -2636,   531,  7859,  7859,  7859,
    7859,   352,   533, -2636, -2636, -2636, -2636, -2636, -2636,  2172,
   -2636, -2636, -2636,  2391,  2138,   165, -2636, -2636, -2636, -2636,
    1296,  1296, -2636,  1296, -2636,  1296,  1296, -2636, -2636, -2636,
   -2636, -2636,   188, -2636, -2636, -2636,  7640,  2175,  1450, -2636,
   -2636,   536, -2636,  2585, -2636, -2636,  7345, -2636, -2636, -2636,
   -2636,  2586, -2636,   524, -2636, -2636,  2189,  2206,   837, -2636,
   -2636,   198,   198,   198,   198,   198,   198, -2636,  2568, -2636,
     542, -2636,  7141,  1429, -2636, -2636, -2636,    54, -2636,  2204,
    7141,  2204,  2056, -2636, -2636, -2636,  2357, -2636,  1450, -2636,
    1450,   120,    26, -2636, -2636, -2636, -2636,   543, -2636, -2636,
   -2636, -2636,  2209,  7859, -2636,  2212,  2218,  2219,  2220, -2636,
   -2636,  7708, -2636, -2636, -2636,  1296, -2636,  1296, -2636, -2636,
   -2636, -2636, -2636, -2636,   296, -2636,  7640,  2391,   126, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,   835, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,  8054, -2636,  2599,
   -2636, -2636,   675, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,   113, -2636,  7630, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,   548, -2636, -2636, -2636, -2636, -2636,  1112,  1112, -2636,
   -2636,  1112, -2636,  7141, -2636,  2221, -2636, -2636, -2636, -2636,
   -2636, -2636,  2228, -2636, -2636,   166, -2636,   193, -2636,  2056
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2636, -2636, -2636, -2636, -2636,   419, -2636,   512,  -182, -2636,
   -2636,  -860,   167, -2636, -2636, -1555, -2636, -2636, -2636, -2636,
    -537, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -1814, -2636, -1538, -2636,
     471, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   759, -2636,
   -2636, -2636, -2636,  1386, -2636,  1060, -2636, -2636,   -54, -2636,
   -2636,  2590, -2636,  2596,  2272, -2636, -2636, -2636, -2636, -2636,
     833,   467, -2636,   830, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636,  -120,   364,   403, -2636, -2636,
    2352,    -2, -2636,  2503, -2636, -2636,  2504, -2636,  2442, -2636,
   -2636, -2636,  2372,  2263,  1320,  2366,  -296, -2636, -2636, -2636,
   -2636, -2636,  1323,  -972, -2636, -2636, -2636, -2636, -2636, -2636,
    -129,  2309,  2452,  -194,   906, -2636,  2300,   175, -2636,  2361,
   -2636, -2636, -2636, -2636,  2363, -2636, -2636, -2636, -2636,  -327,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,  2293, -2636,
    2294, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,  -884,
   -2636, -2636,  -466, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
    2186, -2636, -2636,  1145, -2636,  -887,  -816,  -279, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,   911, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636,  -470, -2636, -2636, -2636, -2636,
   -2636,  2176, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -1712, -2636, -2636, -2636, -2636, -2636, -2636,  1277, -2636, -2636,
    -471, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636,  1729, -2636, -2636, -2636, -2636,
    1024, -2636, -2636, -2636, -2636, -2636, -1379, -2636, -2636,  1020,
   -2636, -2636, -2636, -2636, -2636, -2636,  -822,  -453,   909,  1197,
   -2636,  -448,   849,  -833,  1151, -2636,   664, -2636, -1836,    -4,
    -375, -2636, -2636, -1755,   385,  1480, -2636, -2636, -2636,   735,
    1432, -2636, -2636, -2636, -2636, -2636, -2636,   450, -2636,   114,
   -2636,  1444, -2636,  1117, -2636,   798, -2636, -2636, -2636,  -460,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   918, -2636,
   -1196, -2636,  1103, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,   445, -2636,   444,
   -2636, -2636, -2636, -2636,  1568, -2636, -2636, -2636, -2636, -2636,
   -2636,   -83, -2636, -2636, -1479, -2636, -2636, -2636, -2636,   795,
   -2636, -1691, -2636,  -830, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,  2702,
   -2636, -2636, -2636,  2609,  2699,  -587, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636,    27, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636,  2700, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636,  1164, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,  -414,  2249, -2636, -2636, -2636, -2636,
   -2636,  2080, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636,  2187, -2636, -2636,   -37, -2636, -2636,  1159, -2636, -2636,
   -2636,  -690,  -181,  2470, -2636, -2636, -2636, -2636,   684, -2636,
    -711,  2060,  1469, -2134,   825, -2636,  1167,  1808,    49,  -155,
   -2636, -2636, -2636,  1608, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636,  1562, -2636,  1125, -2636,  -333, -2636,
   -2636, -2636, -2636, -2636, -2636,  -335, -2636, -2636, -2636, -2636,
   -2636, -2636,   522, -2636,  1622,   861, -2636, -2636, -2636, -2636,
   -2636,   382, -2636,  -152, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,  1879,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,  -314, -2636,  1548,
    1699, -2636, -2636,   390, -2636,  -395, -2636, -2636,   408,   722,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,   329, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2635, -2636,  1750,   984,  -978, -2636, -2636,
   -2636,  1394, -2636, -1343, -2636, -2636, -2636, -1315, -2636, -2636,
   -1305, -2636, -2636, -2636, -2636,  1418, -2636, -2636, -2636, -2636,
   -2636, -2636,   788, -2636, -2636, -2636, -2636, -2636, -2636,  -397,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636,  -361, -2636, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636, -2636,   760, -2636,
   -2636, -2636,  -247, -2636, -2636, -2636, -2636, -2636, -2636,   370,
   -2636, -2636,   731, -2636,  1087, -2636, -2636, -2636, -2636, -2636,
   -2636,  -961, -2636, -2636, -2636, -2636, -1434, -2636, -2636, -2636,
   -2636, -2636, -2636, -2585,    18, -2636, -2422,   338, -2636, -2636,
   -1670,   398,   399,   732, -2636, -2409, -2240, -2636, -2636,    66,
    -253, -2636, -2636, -2636, -2636, -2068, -2636, -2636, -2636, -1656,
   -2636, -2636,  -761, -2636,  -700,  1498,    58, -1499,   728, -2636,
     -31, -2636, -2636, -2636, -2636,  -669, -2636, -1655, -2284, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2182, -2636,   475, -2636,
   -1456, -2636,  1837, -2636, -2636,  -684,  -151, -2636, -1519,  -150,
     171,   504, -1258, -1384, -1951,   356,  -331, -1275,  -288, -2636,
     570,  -112, -2636, -2636,  1518,  -494, -2636, -2636,  -183,  1858,
   -2636,   910, -2636, -2636, -1245,   186, -2636, -2636, -2636, -1801,
     -56, -2636, -2636, -2636,  1554, -2636, -2636, -2636, -2636, -2636,
   -2636, -2636, -2636, -2199,   -67, -2636, -2245, -1867, -1762, -1048,
   -2636, -2636,   -49,  -432,  -393,  -455,  1100,  -549,     5,  2258,
     104, -2636, -2636, -2636, -2636, -2636,  1677, -2636,  -508, -2636,
   -2636, -2636, -2636, -2636, -2636, -2636, -2636,  -213,   890,  2466,
   -2636, -2636, -2636, -2636
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1860
static const short yytable[] =
{
      42,   386,  1169,  1028,  1196,    33,   258,  1013,   869,    57,
      59,  1025,   113,   268,  1344,  1165,  1178,  1812,   284,  1854,
    1175,  1176,  1377,  1177,  1745,  1180,  1181,  2079,   881,    33,
     700,  2214,  1355,  1721,   236,    70,   923,  2120,   832,   926,
    1271,    74,    77,   686,   866,   131,  2088,   256,   872,   416,
     821,   719,  2304,  2179,  1281,  2540,  1209,  1695,  1720,  1642,
      97,  2658,  2659,  2660,   113,  1970,   803,  1055,  1491,  1201,
      41,   127,   128,   830,    41,    77,  1597,  1598,   779,    41,
    1220,   779,   338,    41,   269,  1128,   715,   137,   269,  1145,
    1121,   788,   669,   140,   144,   779,   291,    41,   149,   779,
    1201,   151,   152,  1201,   938,  2617,   805,   155,   156,  2278,
    2662,   779,   700,   788,   796,  2444,    41,   299,   300,   816,
    2166,  1503,   788,   127,  1023,  1291,    41,  1293,  1986,   827,
     269,  1883,  1884,    41,   833,  1023,  2749,    41,  1201,    97,
    1276,  1195,   871,   201,  1400,   917,   232,  1133,  1134,   235,
    1023,  3060,    41,   816,   239,  2026,  2444,   816,  1023,   394,
      41,   816,  2726,  2582,  2583,  2584,  2585,   788,   759,  1202,
     788,    41,   275,  2252,  1752,  1203,   834,   269,   276,   277,
   -1858,  1753,  1504,   129,  1505,   879,  1506,    41,   379,  1260,
     789,    41,   273,  2072,  2075,    41,  2389,  2075,  1990,    41,
     266,   269,   929,   930,    41,   688,    41,  2792,   688,   688,
     383,   269,  1883,  1884,    41,    41,   269,   929,   930,    41,
    1272,   381,   688,  1170,    41,   292,   266,   269,  2429,  1884,
     296,  2225,  1260,  1023,   863,    41,   302,  2389, -1858,   266,
     688,  1012,  2272,   688,   882,   888,  1503,   330,   904,   688,
    1536,  2363,   908,   688,   910,  1993,   266,   688,   914,  2887,
     916,   688,  2419,  1256,  1567,   688,   688,  2213,   688,    41,
     879,   688,    41,   688,   688,   688,  1152,    82,   344,   266,
     346,   688,    41,  2538,   688,    97,  2826,   269,  2429,  1884,
      41,   688,  2034,  2929,   696,  2037,   688,   939,  2167,   269,
     270,   271,    41,  2770,   688,  2389,  1908,  1606,   993,   994,
     558,   648,   939,  3059,  1998,   688,  2526,  2925,  2828,   688,
    1023,    41,    41,   688,  2298,  1158,  3206,  1018,   141,   688,
    1385,  1812,   688,  3163,   392,  2616,   995,   996,   997,  3025,
    1599,  1600,  1601,  1602,  1261,  1749,  1606,   389,    82,  1542,
    1276,   392,   408,  2183,  3050,   408,  3052,  2544,  2305,  2306,
    2307,  2308,  2309,   408,    18,    82,   398,    82,  2095,   640,
     650,  1386,    41,  1297,    65,   696,  1019,  1428,    41,   330,
      82,   330,   940,   400,  2385,    82,  1589,  1261,    18,  2392,
    1299,  2393,  2394,  2395,  2396,  2397,  2398,  1159,  1377,    71,
    1187,  1188,  1232,   185,   186,  2980,   939,   939,   408,   404,
    1999,   187,    41,   684, -1858,   689,   690, -1858, -1858,   697,
     702,    63,   704,    41,   818,   707,  1020,   941,  2995,  1342,
      82,  3142,    34,    82,  1739,  1739,   690,  1201,  2853,  1153,
    3001,  1610,  1739,   773,  1257,   259,   260,   261,   262,   263,
     259,   260,   261,   262,   263,   690,  1201,  1510,  2051,  2420,
     871,  2051,  2076,  2099,    41,   773,  2101,  2282,   690,  2413,
    2117,  2413,  3026,  1568,  2440,  2502,  1627,  1628,   806,  2527,
    1610,  2502,    82,  2440,  2542,   384,  2771,    63,  2621,  2927,
    2670,   685,  2295,  1277,   822,   824,  1277,  2772,  2411,  1886,
    2753,   697,  1537,  2573,  2833,  2833,  2858,  3207,   725,   773,
      35,   822,   822,  2875,  1887,   685,  2875,  2317,  3045,   773,
     773,  2559,   900,   773,  2883,    77,  2992,   773,    79,   773,
    3042,  2292,  1407,   773,  3042,   773,  3113,   918,  3113,   918,
     822,  3134,   918,   822,  1750,   918,    95,  3157,  3173,  3184,
    1826,  2072,   863,  2875,  2539,  2293,  1383, -1858,  1577,   931,
    2096,  1155,   259,   260,   261,   262,   263,  1215,  1406,  1218,
    2729,   380,  2793,    82,  1603,  2226,  3105,  1604,  2390,  1605,
    1886,  1561,  1384,   871,   833,   871,  1402,  1200,  1360,  1404,
    1405,  1402,   942,   863,  2286,  1887,  1886,  1636,  1637,  1606,
    1356,  1361,   685,   402,   382,   882,  1647,   942,  1424,  1607,
    1223,  1887,   819,  1305,  2227,  2507,  1373,  2184,   267,  2417,
    2827,   700,   688,  1987,  2892,  1828,  1292,   941,  1942,  2399,
    2364,  1994,  1204,   906,  1567,  2888,  2939,  1305,  1146,  1360,
     130,  1487,  1472,  1308,   341,  1258,  1918,   967,  2325,  1687,
    1339,  1608,  1361,  2253,  1486,  1609,  1886,   671,    76,  2547,
   -1858,  2849,   932, -1858, -1858, -1858, -1858,  2555,  2556,  2996,
    2997,  1887,   981,   797,  2438,   988,  2080,   408,  1259,   272,
    1360,  2798,  1340,   272,  3018,  1872,  1135,  2717,   943,   944,
     945,  1221,   697,  1361,  2027,  2445,  1171,  2825,  3099,   946,
    1467,   942,   942,  1862,  2950,   998,   821,  1024,  1262,   820,
    2067,  2930,  1585,  1492,  1978,  2994,   773,   773,   820,  1552,
    1205,  2067,   820,  1473,  1207,   272,  2822,  2612,  2117,  2574,
     390,   773,  1507,  1610,    41,  2156,  2067,   773,   773,   700,
    1508,  1534,   773,  1754,  2067,   688,   688,   688,  2400,   399,
    1172,  1262,   773,  1539,  1758,  1551,  3024,  2303,  2435,  2111,
     657,  1593,  1594,  2081,  3133,   947,   401,  2752,  2572,  2800,
    2756,  2415,   272,  2805,  1778,  1572,  1629,  1781,  1402,  2386,
    2082,  1024,  2783,  1554,  2434,  1611, -1858, -1858, -1858, -1858,
   -1858,  1918,   405,   999,   658,  2384,   272,  2387,  1643,  3004,
    2626,  3007,  3008,  3009,  3010,  2401,   272,  2730,  2764,  1021,
    2111,   272,  1343,   188,  3169,  2013,  3170,  1740,  1743,  1363,
    1744,  1237,   272,  2083,  1362,  1848,  1547,   773,   773,   132,
     734, -1858,  2618,  2619,   141,  1364,  1000,  1934,    41,  1849,
    2576,  2052,  2571,  1568,  2066,  2077,  2100,  2236,  1935,  2102,
    2283,  1802,  2414,  2881,  2416,   738,  2966,  2441,  2503,  1474,
    1475,  1476,   773,  2084,  2504,  1376,  2509,  2543,   773,  1345,
    1363,  2622,  1347,  2671,  2865,   134,  3181,   708,    41,  1498,
     773,  2716,   272,  2754,   139,   773,  1364,  2834,  2840,  2859,
    1230,  1727,  2085,  2310,   272,    82,  2876, -1858,  1193,  2882,
   -1858,  2086, -1858,   143,  2998,   651,   145,  2884,  1248,  2993,
    1514,  1363,  2736,  3043,  2739,  1644,  1535,  3044,  2829,  3114,
     194,  3120, -1858,   773,  3135,   195,  1348,  1364,   652,  1738,
    3158,  3174, -1858,   337,  2402,  1138,  3198,   773,  1997,   747,
      44,   882,  1139,  1564,  2731,   303,  2732,   182,  2901,    41,
    1194, -1858,  1843,    41, -1858,  2580, -1858,  2577,  1560,  1649,
     198,  2580,  1908,  2589,  2590,  2591,  2592, -1858,  1575,  1612,
    1490,  1869,   304,  1382, -1858,  2408,  2521, -1858, -1858,  2392,
    2403,  2393,  2394,  2395,  2396,  2397,  2398,  1938,  1777,   233,
    1357,  1780,   133,   134,  1365,  1374,  1365,  2902,  1939,    82,
    1827,  2404,   234,  2192,   695,   241,    41,   697,  3013,  2991,
     697,  2117,  1389,  1392,   249,  2817,   704,  1184,  2874,  3021,
    2038,  1348,  2608,    41,  1191,  1645,   828,   873,    41,    41,
     822,   773,   752,   822,   822,   822,   822,   250,   773,    82,
   -1858,   773, -1858,   413,   754,   755,   134,  2650,  2650,  2650,
    2650,   655,   822,   757,   773,   252, -1858,  1976,   773,  2258,
    3139,  1853,  2881,  2881,  1349,   253,   773,  2578,   773,   773,
    3189,   773,   773,   773,   773,   773,   773,   773,   773,   773,
     773,   773,   773,   773,   773,   773,   773,   773,   254,  1662,
    2382,  1599,  1600,  1601,  1602,   879,   682,    41,   773,   773,
      41, -1858,   956,   773,   257,   773,  3005,  1397, -1858,  3140,
      82,  1945,  3005,   957,    82,  3014,  3015,  3016,  3017,    45,
    1463,   265,  2854,  1377,  2610,    41,  1817,  1606,   697,  1606,
    1975,  2733,   285,    46,   773,   773,   773,  2433, -1564,    58,
    1350,    41,    81,  2725,    41,   822,  2728,  1489,   288,  1493,
     822,   136,   811,   286,   773,  1925,  1927,    41,    47,  1349,
    2297,   817,  3093,  3094,   289,   958,  1635,   696, -1858,  2117,
    1670,  2891,  1639,  2981,   695,  2983,    41,  1670,   290,  3144,
     959,  3144,  2315,  3145,    82,  3145,  1241,  1515,    41,   696,
      82,   773,   651,  1516,  1517,  1518, -1858,   822,  1351, -1858,
    1796,  1023,  1287,    41,    41,  1805,   921,    48,  1806,   924,
    1468,  1013,    41,  1519,   969,   652,   773,  1678,  3023,  2399,
    1549,   295,   822,   822,  1821,  2442,  1684,   822,  1476,  1650,
    1842,  1558,  1559,   773,  2106,  1350,  2561,   294,    41,  2855,
    1651,   297,  3112,   773,  1352,  3115,  3116,  3117,  3118, -1858,
     301,  1228,   833,    41,  2712,  1123,    41,   697,    82,  1200,
    1353,  1610,  1652,  1610,   918,   822,   822,   306,  2112,  1653,
     960, -1858, -1858,   871,  1388,  3165,  2285,  3167,   922,  2623,
      41,   925,   133,   134,   928,  1861,    82,  2627,   688,   315,
    1631,  2114, -1858,  1024,  1024,  2157,  2117,  2158,  1640,  1234,
    1640,   713,  1024,   324,  2832,    82,  2169,  2835,  2836,  2837,
    2838,  1807,    34,    35,  1808,  1671,  1805,  1875,  2318,  1806,
     783,  1520,  1671,    41,  1521,  1603,   133,   134,  1604,  2423,
    1605,  2425,  2426,   792,  1672,  1673,  1606,    41,  2400,  1352,
     981,  1672,  1673,  2180, -1858,  1024,  1124, -1858,  1522,    82,
    1606,  3176,   962,   963,  1674,  1353,  2518,   325,  1365,  2999,
    1607,  1674,    41, -1858, -1858,    82,   781,  2574,  1523,  1374,
    2533,   336,  1365,    82,  2650,  2650,    41,   905,  2650,   331,
     790,   909,  -266, -1858,   795,   913,  3137,  1380,  2737,    41,
    1235,  1734,  1735,  1736,    41,  2401,   809,  1576,   134,    82,
    1650,  1698,  1608,  1524, -1858,  2568,  1609,   334,  2020,  2221,
      41,  1651,  2005,   890,   688,   335, -1858,    82,  2607, -1858,
     685,  2006,  1807,  1525,  1526,  1808,   340, -1858,   773,   773,
     773,   342,   773,  1652,  1527,   688,   307,  1413,   343,  1528,
    1653,   347,  1414, -1858,  1416,  2007,  2803,  1606,  2008,  3160,
    3064,  2108,    41,  2334,   353,    41, -1858,  2928,   773,  2367,
   -1858,  1787,  2760,   891,  1411,  1412,  2009,  1413,   348,  -266,
    1610,  2758,  1414,  1415,  1416,   773,  3104,  2907,  1529,  1029,
    1030,  1031,  3110,   351,  1610,  1294,  -266,  2124,   352,  2125,
    3085,   354, -1858,  1815, -1858,  2785,   357,  2786,    82,   773,
     892,  1822,  1823,   773,   822,  1210,  1211,  1212,  1213, -1858,
    2953,  1530,  2954,  2159,  2160,  1476,  2163, -1858,  1469,  2249,
    1469, -1858, -1858,   308,  2402, -1858,  1657,  1658,   358,  -266,
    1818,  1819, -1858, -1858,   773,   368,  1611,  2186, -1858,   773,
     309,   369,  2908,   372,  2909,   387, -1858, -1858,  2107,  1851,
     316,   377,  3166,   773,  1665,  1666,  1047,   388,  2985,  2910,
     773,  2126,   259,   260,   261,   262,   263,  2911,   773,  -266,
    2403,  2912,  2010,   694,  1876,  1248,  2906,  1901,   943,   944,
    2117,  1610,   391,   310,  2863,  2864,   712,  1295,   396,  3149,
     395,  2404,  2222,  2223,  2218,  1296,  2913,   893,  -266,   822,
     822,  1297,   397,  1298,   403,   406,   414,  -266,  3085,   656,
    2650,  2436,   833,   784,  1299,   822,  2650,  2650,   871,  2650,
    2650,  2650,  2650,   311,   661,   663,  2011,   664,  2650,   801,
     802,   665,   670,  2012,  1024,   808,  1699,   317,   810,  3064,
     871,   672,  1300,  1048,   675,   674,  1185,  1186,  2907,  2080,
    1189,  1190,   312,  2021,   318,   676,   678,   679,  1301,   680,
    1049,   313,  2510,  1302,   681,   732,  2033,  2033,  3149,  3055,
    2033,   683,   971,   894,   972,  1303,   274,   733,   973,   974,
     279, -1858,  1304,   975,  2812,   977,  1901,   976,  2068,  2068,
     978,   979,  2068,  1901,  1700,   980,   984,   319,   985,   986,
     987,   991,  1010,  1050,  1011,   134,  1701,  1014,  1016,  1017,
    1022,  2900,  2811,  2908,   895,  2909,  1702,  1026,  1035,  2103,
    1612,  1034,  1389,  1125,  1132,  3109,   773,  2312,  1037,  2313,
    2910,     2,     3,  1365,  1703,   822,  2081,   320,  2911,  1137,
    1143,  1901,  2912,  1051,  1704,  2768,  2650,  1705,  1038,  2650,
    2650,  2650,  2650,  2082,  1039,  1040,  2657,  2657,  2657,  2657,
    1706,  1041,  1042,  1136,  1043,  1044,   321,  2913,  1045,  1056,
    1057,  3131,  1052,   773,   688,   322,   773,  1140,  1058,  1061,
     688,  1053,   896,  1062,  1365,  1065,  1067,  1068,   773,   773,
     773,   773,  1069,  2068,  1070,  1141,  2083,  1071,  1072,  2171,
    1815,  1073,   688,  2176,  2176,  1075,  1144,     5,     6,  1707,
       7,     8,   773,  2740,  1149,     9,  2599,  1148,  2601,  1151,
    1154,   749,  2188,  1163,  1168,  1092,  1093,  1094,  1095,  1096,
    1097,  2775,    10,    11,  1182,  1192,  2084,  1305,  2815,  1708,
    1195,  1098,  1099,  1100,  1306,  1216,   897,  1224,  1225,  1709,
      12,  1226,  1227,  1233,  1231,  2650,  1236,  1237,  1336,  1245,
    1247,  3055,  1267,  2650,  1268,  2085,  1307,  1269,  1201,   773,
    1710,  1308,     1,  1711,  2086,  1712,  1901,  1901,  1270,  1275,
    1279,  1282,  1283,  2512,  1285,  1901,  2517,     2,     3,  1284,
     751,  1330,  1338,  1341,  1359,  1379,  2235,  1395,  3109,   753,
    2741,  1397,  1398,  1713,  2492,  1399,  1396,  1408,   697,  1422,
    1458,  1425,  1714,   833,   833,  1430,  2259,  2742,  2776,  1461,
      13,  1466,  1423,  1479,  1465,   716,   716,  1207,  1499,  1485,
    1501,  2957,  1497,  1512,  1538,  2777,  1513,  1540,  1541,  2965,
    1543,  1545,   863,  2759,  2684,  2685,  2686,  1550,  2688,  2689,
    2690,  2691,  2692,  2693,  1555,  1564,  1571,  2696,  1013,  1553,
    2743,  2240,  2241,     5,     6,  1573,     7,     8,  1579,  1503,
    1277,     9,  1024,  1578,  1581,  1619,  1621,  1630,  2778,  1622,
    1624,  1101,  1679,  1690,  1102,  1692,   648,  2068,    10,    11,
    1901,  1693,   648,  2238,  2239,  2240,  2241,  2301,  1640,  1901,
    2744,  1696,   773,  1697,   773,  1725,    12,  1723,  1728,  1726,
    1729,  1730,  2068,  1741,  1024,  1742,  1746,  2794,  2779,  1757,
     716,  1748,  1755,  2033,  2807,  1759,  1760,  1762,  1765,  2745,
     933,  2809,  2242,  2243,  2244,  2245,  2246,  2247,  2746,  2566,
    2879,  2880,  1786,  1789,  1792,   650,  2068,  2780,  1793,  1794,
    1901,   650,  1901,  1795,  3022,  1798,  2781,  1799,  1801,  1797,
    1791,  1276,  1803,  2068,  2768,  2430,  2242,  2243,  2244,  2245,
    2246,  2247,  1365,  1816,  1804,   688,   688,  1086,  1087,  1088,
    1089,  1090,  1091,  2657,  2657,  2128,  1829,  2657,  1831,  2130,
    1800,  1832,  1833,  1837,  2133,  1374,  1840,  1365,  2137, -1858,
    2139,  2140,  2141,  1103,  1846,  1734,  1847,  3084,   773,  1852,
    1855,  2242,  2243,  2244,  2245,  2246,  2247,  1856,  1104,  1859,
    1865,    16,  1105,  1873,  1879,  1912,  1763,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1914,  1913,  1918,   946,  1920,   773,   773,
    1973,  1092,  1093,  1094,  1095,  1096,  1097,  1974,   773,  1991,
    1106,   773,  1985,  2002,  2001,  2016,  2519,  1098,  1099,  1100,
    2018,  2019,  2041,  2030,  2042,  2924,  2043,  2047,  2924,  1815,
    2050,  2534,  2089,  2536,  2090,  2091,  2092,  2093,  1107,  2105,
     773,  2094,  2121,   773,   933,  2109,    14,  2551,  2122,  2123,
    2129,   773,   773,  2132,  2142,  2147,  2143,  1108,  2144,  2148,
    2152,  1092,  1093,  1094,  1095,  1096,  1097,   773,  1660,  1661,
    2150,  2165,  2154,  2170,  2068,  1677,  1901,  1098,  1099,  1100,
    2187,  2185,  1901,  1901,  1901,  1901,  1901,  1901,  2196,  2768,
    1122,  2768,  3172,  2195,  2198,    15,  2199,  2200,    89,  3150,
    3151,  3152,  3153,  3154,  3155,  2202,  2808, -1858,  2203,  2201,
     822,  2219,   822,  3092,    50,    51,    52,    53,    54,    55,
      56,  2228,  2229,  2220,  2649,  2649,  2649,  2649,  2237,  2230,
    2231,  2232,  1901,  2233,  2257,  2823,  2264,  2234,  2266,  1109,
    2273,   945,  2275,  2279,  2296,  2068,  2284,  2280,  2288,  2959,
    2289,  2648,  2648,  2648,  2648,  2068,  2068,  1101,  2281,  2299,
    1102,  2320,  2321,  2322,  2841,  2323,  2673,  2674,  2021,  2657,
     183,   191,  2368,  2328,  2677,  2657,  2657,  2391,  2657,  2657,
    2657,  2657,  2410,     1,  2383,  2411,  2412,  2657,  2369,  2370,
    2418,  2421,  2956, -1803,  2802,  2437,  2371,  2424,     2,     3,
    2427,  2495,  2493,  2443,  2494,  2899,  1110,  2496,  2498,  2499,
    2497,  2500,  2501,  2505,  2508,  2511,  2514,  1101,  2513,  2722,
    1102,  2722,  2520,  2524,  2528,   191,  2535,     4,  2532, -1858,
    2372,   191,  2546,  2554,     1,  1901,  2572,  1901,  2564,  2373,
    2570,  2586,  2595,  2598,  2613,  2614,  2720,  2389,  2720,     2,
       3,  2623,  1901,  2630,  2444,  2672,  2668,  2068,  2738,  2068,
   -1858,   933,  2687,  2682,  2694,  2683,  2695,  2701,  2374,  2705,
    2702,  2706,  2226,  2707,     5,     6,  2708,     7,     8,  1103,
    2709,  2710,     9,  2711,  2768,  2724,  1365,  2727,  1845,  2734,
    1901,  1024,  1349,  2748,  1104,  2750,  2755,  2757,  1105,    10,
      11,   191,  2784,   191,  2761,  2657,  2790,  1994,  2657,  2657,
    2657,  2657,  2795,  2375,  3069,  2796,  2797,    12,  2798,  2810,
    2813,  2816,  2820,  2830,  2831,     5,     6, -1858,     7,     8,
     940,  1915,  2845,     9,  2856,  2875,  1106,  2849,  2885,  1103,
    2886,  2896,  2866,  2924,  2867,  2868,  3209,  2869,   773,  2870,
      10,    11,  2871,  2872,  1104,  2376,  2897,  2904,  1105,  2919,
    2408,  2932,   871,  2933,  1107,  2935,  2960,  2936,    12,  2937,
    2176,  2938,  2941,  2804,  2176,  2944,  2949,   191,   822,  2951,
    2952,   773,  2955,  1108,    81,   822,    41,    13,  2958,  2964,
    2968,  2970,  2971,  2972,  2962,  2974,  1106,  2976,  2982,   773,
   -1858,  2984,  2986,  2990,     2,     3,  2445,  2987,  2988,  2989,
     773,  3000,  3002,  3011,  2657,  3019,  3046,  1901,  3038,  3039,
    3047,  3048,  2657,  3067,  1107,  1901,  3049,  3082,  1901,  1901,
    1901,  1901,  2839,  3070,  3056,  3083,  3091,  3097,  3111,   773,
    3136,  3138,  3156,  1108,  3143,  3168,  3098,  3175,  3132,  3121,
    3177,  2649,  2649,  3100,  3193,  2649,  3178,  3179,  3180,  3203,
    2846,  2877,  2878,  2879,  2880,  1109,  3204,  2068,   710,  2550,
    3192,  2439,  2211,  2506,  1563,  1864,  2301,    72,  2648,  2648,
       5,     6,  2648,     7,     8,    73,   559,  2172,     9,   349,
    2181,  2337,  2338,  2873,   197,  2339,  2340,  2341,   933,   202,
    2531,   281,   786,   345,   350,    10,    11,    14,   791,   673,
     793,  1681,   407,   283,   800,  1682,  2068,   800,  1631,  2131,
     800,   660,  2787,    12,   688,  1109,   666,   376,   374,   667,
     812,  3190,  1110,  1839,  2242,  2243,  2244,  2245,  2246,  2247,
    1751,  2149,  2031,  2923,  1334,  2039,  2923,    82,  2722,   861,
    1592,   716,   899,  2161,  1824,  2597,    15,   874,   877,   880,
    2844,  3196,  1917,   901,  2256,  1596,  2168,  1943,  2603,  2605,
     697,   911,  1494,   697,  2967,  2720,    67,   157,  1901,    68,
      69,  2917,   807,   970,  1871,  1874,   339,   935,    16,  2251,
    1273,   990,  1110,    13,  2342,  1618,  1878,  2207,  2208,  3029,
    2905,  2343,  3164,  1481,  1533,  1988,   933,  1471,  2217,  2588,
    1024,  2715,  3037,  1219,  2942,  1431,  2947,  2714,  1546,  2697,
    1394,  2380,  2155,  1724,  1691,  2290,  3197,  3186,  3122,  2319,
    2735,  2381,  2940,  2078,  2769,  2344,   822,  2718,  2388,  3130,
    2719,   773,  1634,  2926,  2345,  2407,  2931,  2675,  1322,  3065,
    2763,  3066,  2862,  3159,  2629,  3185,  2587,  3041,  1626,  3103,
    3003,  2260,  2261,  2262,  2263,  1290,  2861,  1590,  3020,  2268,
    2269,  2270,  2271,  2346,  2347,  3012,  2104,  1488,   415,  1901,
       0,     0,  1880,  1881,  2277,  1882,     0,  2649,   269,  1883,
    1884,    41,     0,  2649,  2649,     0,  2649,  2649,  2649,  2649,
       0,  1901,     0,     0,  2068,  2649,     0,     0,     0,     0,
       0,     0,  2068,     0,  2648,     0,     0,     0,  2348,     0,
    2648,  2648,     0,  2648,  2648,  2648,  2648,  1885,     0,  2068,
       0,  2068,  2648,     0,  1901,     0,     0,     0,  2722,     0,
       0,     0,  3028,     0,     0,     0,     0,     0,     0,     0,
       0,   935,     0,     0,     0,     0,  1032,  1033,     0,     0,
    2349,     0,     0,     0,  3202,     0,     0,     0,  2326,  2327,
       0,  1046,     0,     0,     0,  2331,  2332,  1059,  1060,     0,
       0,     0,  1064,     0,     0,  1024,     0,  1024,     0,     0,
    1901,     0,  1074,     0,    16,  2068,     0,  2947,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2350,     0,     0,  1126,
       0,     0,     0,  2649,     0,     0,  2649,  2649,  2649,  2649,
       0,     0,     0,     0,     0,     0,     0,     0,  2846,     0,
       0,     0,     0,     0,     0,     0,  1901,     0,     0,     0,
    2648,     0,   696,  2648,  2648,  2648,  2648,  3119,     0,     0,
       0,  2923,  1157,     0,     0,     0,     0,     0,     0,     0,
       0,  1631,     0,     0,     0,     0,     0,     0,  1174,  1174,
    1174,     0,  1174,     0,  1174,  1174,     0,     0,   697,     0,
      89,    89,  1901,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1901,     0,     0,     0,     0,     0,     0,     0,
       0,  1902,     0,  2522,  2523,     0,     0,     0,     0,     0,
       0,     0,  2530,     0,     0,     0,     0,     0,   773,  3161,
    2541,     0,  2649,   880,     0,     0,   773,     0,     0,     0,
    2649,     0,     0,     0,  1243,     0,     0,     0,     0,  2557,
    2558,     0,     0,     0,     0,     0,  2053,     0,     0,  2648,
       0,     0,     0,     0,     0,     0,     0,  2648,   935,  1126,
       0,     0,     0,     0,     0,     0,     0,  1280,     0,     0,
    1024,     0,  1901,     0,  2068,     0,     0,     0,     0,     0,
       0,     0,     0,  1288,  1288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2600,     0,  2602,     0,     0,
       0,     0,     0,     0,  2604,     0,  2606,     0,     0,  1901,
    1902,     0,     0,     0,     0,     0,     0,  1902,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   773,
       0,     0,     0,     0,     0,     0,  2351,  2352,  2353,  2354,
    2355,  2356,  2357,  2358,  2359,  2360,     0,  1886,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2678,
    2679,  1403,  1887,  2680,  2681,  1902,     0,     0,  1410,     0,
       0,  1421,     0,     0,     0,     0,     0,     0,     0,  1888,
       0,     0,  2054,     0,  1426,     0,     0,     0,  1429,     0,
       0,     0,     0,     0,  2055,  1890,  1435,  2704,  1437,  1438,
       0,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1456,  1457,
   -1859,     0,     0,  1459,     0,  1460,  1892,     0,     0,     0,
       0, -1859, -1859, -1859, -1859,     0,     0,     0,  1893,     0,
       0,     0,  1464,     0,     0,     0,     0,     0,     0,     0,
      89,     0,    89,   880,   800,     0,     0,     0, -1859,     0,
       0,  1480,   812,     0,     0,   880,     0,     0,     0,   191,
       0,     0,  1495,     0,     0,     0,     0,     0,     0,     0,
    1894,     0,     0,     0,     0,   935,     0, -1859,     0,     0,
    1902,  1902,     0,     0,     0,     0,     0,     0,     0,  1902,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,  1895,
       0,     0,     0,     2,     3,     0,     0,     0,     0, -1859,
       0,  1896,   102,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,  1897,  1898,  2801,     0,     0,     0,  2806,
    1556,     0,  1899,     0,     0,  1900,     0,     0,     0, -1859,
       0,     0, -1859,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,  1586,
    2821,     0,   104,   105,     0,     0, -1859,     0,     0,     0,
     106,     0,  1617,   935, -1859,     0, -1859,     0,     0,     5,
       6,     0,     7,     8,  1902, -1859,     0,     9,     0,     0,
       0, -1859,     0,  1902,  2842,     0,     0,     0,     0, -1859,
       0,     0,     0, -1859,    10,    11,     0,     0,     0, -1859,
       0,     0,     0, -1859, -1859, -1859, -1859,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,  1664, -1859,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,  1902, -1859,  1902,     0, -1859,     0,
   -1859,     0,     0,     0,     0,     0,     0, -1859,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1859,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1859,     0,   880,     0,     0,     0,  1902,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1859,
   -1859,     0,     0,     0,     0,     0,     0,  1092,  1093,  1094,
    1095,  1096,  1097,     0, -1859,     0,     0,     0,     0,     0,
       0,     0, -1859,  1098,  1099,  1100, -1859,     0,  1766,  1767,
    1768,     0,  1770,     0,     0, -1859, -1859, -1859,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1785,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -1859,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1859,     0,     0,     0,     0,
    1902,     0,     0,   107,  2979,     0,  1902,  1902,  1902,  1902,
    1902,  1902,     0,  1836,     0,     0,     0,     0,     0,  1841,
       0,     0,  1844,  1092,  1093,  1094,  1095,  1096,  1097,   108,
       0,     0,   880,  1785,     0,     0, -1859,     0,     0,  1098,
    1099,  1100,     0,  1101,     0,     0,  1102,     0,     0,     0,
       0,     0,     0,   183,     0,     0,  1902,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1902,  1902,  1902,  1902,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1859,     0,
     109,   880,  1977,   880,     0,     0,     0,   874,     0,   716,
     716,   716,     0,   716,   716,   716,   716,   716,   716,     0,
       0,     0,   716,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -1859,     0,     0,     0,     0,  2025,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3095,  1902,
       0,  1902,     0,     0,     0,  1103,     0,     0,     0,     0,
    1902,     0,  1902,     0,     0,     0,  1902,     0,     0,  1101,
    1104, -1859,  1102,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110, -1859, -1859, -1859, -1859, -1859,
   -1859, -1859,     0, -1859, -1859,   880,   191,     0,     0,     0,
    3123,  3124,     0,  3126,  1902,  3128,  3129,     0,     0,     0,
   -1859,     0,  1106,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,  2145,     0,     0,  2145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   880,     0,   880,  1108,
       0,     0,     0,     0,     0,   111,     0,   880,     0,     0,
       0,  3171,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1103,     0,     0,     0,  3182,     0,  3183,     0,     0,
       0,     0,     0,     0,     0,  2193,  1104,     0,     0,   933,
    1105,  1427,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1902,  3194,     0,  2216,     0,     0,     0,     0,  1902,
       0,  1109,  1902,  1902,  1902,  1902,     0,     0,  1106,     0,
       0,     0,     0,     0,     0,     0,     0,  3199,  3200,     0,
       0,  3201,     0,     0,     0,     0,     0,     0,     0,     0,
    1946,  1947,  1948,  1949,  1950,  1951,  1107,     0,     0,     0,
    2250,  1586,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1902,  1902,     0,  1108,  1902,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,  2194,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,  1952,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,     0,     0,  2448,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,  1902,     0,     0,  1902,     0,  1902,
       0,     0,  1902,  2324,  1092,  1093,  1094,  1095,  1096,  1097,
       0,     0,     0,     0,  2449,  2450,  2451,     0,     0,     0,
    1098,  1099,  1100,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,  2452,
    1092,  1093,  1094,  1095,  1096,  1097,     0,  2453,     0,     0,
       0,     0,  2454,     0,  1110,     0,  1098,  1099,  1100,     0,
       0,     0,     0,     0,     0,     0,     0,  2455,     0,     0,
       0,     0,  2456,     0,  2457,     0,     0,     0,     0,     0,
       0,  2458,   880,     0,  2459,     0,     0,  2460,     0,     0,
    2461,     0,     0,  2462,     0,     0,     0,     0,  2463,     0,
       0,     0,     0,  1902,  1092,  1093,  1094,  1095,  1096,  1097,
       0,     0,     0,     0,     0,     0,  2464,     0,     0,     0,
    1098,  1099,  1100,     0,     0,  1902,     0,     0,  1785,  1785,
       0,     0,  2465,   880,     0,  2466,  2467,     0,  1902,     0,
       0,     0,  2468,     0,  1902,  1902,     0,  1902,  1902,  1902,
    1902,     0,     0,  2469,     0,     0,  1902,     0,  1902,     0,
    1101,     0,     0,  1102,     0,     0,  1586,     0,     0,  2470,
    2545,     0,  1953,  1785,     0,  2548,  2471,   710,     0,  2552,
       0,  1785,  1785,  2472,     0,  1954,  2473,  2474,  2475,  1902,
    2476,  2477,  2563,     0,     0,     0,  1101,   191,     0,  1102,
       0,     0,     0,     0,     0,     0,     0,  2478,     0,     0,
       0,     0,     0,     0,  1902,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2479,  2480,  2481,  2482,     0,  2483,     0,     0,     0,
       0,     0,     0,     0,   933,     0,     0,     0,     0,  1955,
       0,     0,     0,  2484,  2485,     0,  1956,  2609,  2611,     0,
    1101,     0,     0,  1102,     0,     0,     0,     0,     0,     0,
    1902,     0,     0,     0,  1902,     0,  2486,  1902,  1902,  1902,
    1902,     0,  1103,     0,     0,  2487,  2488,     0,  2489,     0,
       0,     0,     0,     0,     0,  1957,     0,  1104,     0,     0,
    2676,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1902,     0,     0,     0,  1902,     0,  1103,     0,
    1958,     0,     0,     0,     0,     0,  1902,     0,     0,     0,
    1959,  1960,     0,  1104,     0,     0,  1961,  1105,  1747,  1106,
    2698,     0,     0,     0,     0,     0,  1962,     0,     0,     0,
    2490,     0,     0,  2713,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,  1963,     0,
       0,  1964,  1965,     0,     0,  1106,     0,  1966,     0,     0,
       0,     0,  1103,  1902,     0,     0,  1108,     0,     0,     0,
       0,  1902,     0,     0,     0,     0,     0,  1104,     0,     0,
       0,  1105,     0,  1107,     0,     0,  1902,     0,     0,     0,
       0,     0,     0,     0,   880,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1967,     0,     0,     0,     0,  1106,
       0,     0,     0,  1902,     0,     0,  1968,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,  1109,     0,
       0,     0,     0,     0,     0,     0,     0,   933,  2788,     0,
       0,     0,     0,     0,     0,     0,  1108,     0,   880,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,  1109,     0,   417,     2,     3,   385,
       0,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   935,   419,   420,  1785,
     421,     0,     0,     0,     0,  1110,     0,     0,     0,     0,
       0,     0,     0,     0,   422,     0,     0,     0,     0,     0,
       0,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   424,   425,   426,     0,     0,     0,  1109,     0,
       0,  1110,     0,     0,     0,     0,     0,     0,   427,     0,
     428,   429,   430,     5,     6,   431,     7,     8,   432,     0,
     433,     9,   434,   435,     0,     0,     0,     0,     0,   436,
       0,     0,   437,     0,   438,   439,   440,     0,    10,    11,
       0,     0,     0,     0,   441,     0,   442,   443,     0,   444,
       0,   445,   446,     0,     0,   447,    12,     0,     0,   448,
     449,   450,     0,   451,   452,  1110,     0,     0,   453,   454,
       0,   455,     0,     0,     0,   456,     0,   457,   458,     0,
       0,     0,     0,   459,     0,     0,     0,   460,     0,     0,
     461,     0,   462,     0,   463,     0,   464,     0,   465,   466,
       0,   467,   468,   469,     0,     0,     0,   470,  2698,   471,
     472,     0,   473,     0,     0,     0,     0,     0,     0,     0,
     474,   475,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,     0,   477,   478,     0,     0,
     479,   480,     0,     0,   481,   482,     0,     0,     0,     0,
       0,     0,     0,   483,   484,   485,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   488,   489,
       0,   490,     0,     0,     0,   491,   492,     0,     0,     0,
     493,     0,     0,     0,     0,     0,     0,     0,   494,     0,
       0,   159,     0,     0,     0,     0,   495,   496,   497,     0,
     880,     0,     0,     0,   498,   499,     0,     0,     0,     0,
     500,     0,     0,   501,     0,     0,     0,   502,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
     160,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,     0,     0,   161,
       0,     0,     0,     0,   506,     0,  1586,     0,     0,     0,
     507,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,   162,     0,
     508,     0,   509,   510,     0,     0,     0,  1586,     0,     0,
     163,   511,     0,     0,     0,     0,     0,     0,     0,     0,
     164,  2698,     0,     0,     0,     0,  3032,     0,  3034,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
     512,     0,     0,     0,     0,  1092,  1093,  1094,  1095,  1096,
    1097,   513,     0,     0,   167,   514,     0,   880,     0,   515,
       0,  1098,  1099,  1100,     0,   880,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   935,     0,   516,   517,     0,     0,     0,   518,     0,
       0,     0,     0,     0,   168,     0,     0,     0,     0,     0,
     519,     0,     0,     0,     0,     0,   520,   521,   522,   523,
       0,     0,     0,   524,     0,     0,     0,   525,   169,     0,
       0,     0,     0,     0,   526,   527,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,   528,     0,   529,     0,
     171,     0,     0,   172,     0,     0,     0,     0,     0,   530,
       0,   531,     0,     0,   532,     0,     0,     0,     0,     0,
     533,     0,     0,     0,   173,     0,     0,   174,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,  1174,  1174,
    1174,  1174,  1174,  1174,     0,     0,   534,     0,   176,   535,
       0,     0,     0,     0,     0,   536,  1785,     0,   537,   538,
       0,  1101,     0,     0,  1102,     0,   177,     0,     0,     0,
       0,     0,     0,   539,     0,     0,     0,     0,     0,     0,
     540,     0,     0,     0,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
       0,     0,     0,   541,   542,   543,   544,   545,   546,   547,
       0,     0,   548,     0,   549,     0,   550,     0,     0,     0,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,     0,
       0,     0,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1092,  1093,
    1094,  1095,  1096,  1097,   935,     0,     0,     0,     0,     0,
       0,     0,     0,  1103,  1098,  1099,  1100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,     0,
       0,     0,  1105,  1756,  1092,  1093,  1094,  1095,  1096,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,  1099,  1100,     0,     0,     0,  1092,  1093,  1094,  1095,
    1096,  1097,     0,   269,  1883,  1884,    41,     0,     0,     0,
    1106,     0,  1098,  1099,  1100,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,  2634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,  1108,     0,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,   160,     0,  1102,     0,  1092,
    1093,  1094,  1095,  1096,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,  1098,  1099,  1100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1101,     0,     0,  1102,     0,     0,     0,     0,     0,  1109,
       0,     0,     0,  1092,  1093,  1094,  1095,  1096,  1097,     0,
       0,     0,  1101,   162,     0,  1102,     0,     0,     0,  1098,
    1099,  1100,     0,     0,     0,   163,     0,   696,     0,     0,
       0,     0,     0,     0,     0,   164,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,  1110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,     0,     0,  1105,  1761,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,     0,  1101,     0,     0,  1102,   168,
    1092,  1093,  1094,  1095,  1096,  1097,     0,  1104,     0,     0,
       0,  1105,  1769,  1106,  1103,     0,  1098,  1099,  1100,     0,
       0,     0,     0,   169,     0,     0,     0,     0,     0,  1104,
       0,     0,     0,  1105,  1771,     0,     0,     0,   170,  1101,
       0,  1107,  1102,     0,     0,   171,     0,     0,   172,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,  1106,   174,     0,   175,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,  1108,     0,     0,  1107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,  1886,     0,     0,     0,     0,  1103,  1108,     0,
       0,     0,     0,     0,     0,     0,     0,  1887,     0,     0,
       0,     0,  1104,     0,     0,     0,  1105,  1772,     0,     0,
       0,     0,  1109,     0,  2635,     0,     0,  2636,     0,     0,
       0,     0,     0,     0,     0,     0,  1101,     0,     0,  1102,
    2637,  1103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1106,     0,  1104,     0,  1109,     0,
    1105,  1773,     0,     0,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1109,  2639,  1107,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,  2640,     0,     0,     0,     0,  1106,     0,
       0,  1108,     0,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,  1110,  1107,     0,     0,     0,
       0,     0,     0,     0,     0,  2641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1108,     0,  1110,  1092,  1093,
    1094,  1095,  1096,  1097,     0,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,  1098,  1099,  1100,     0,     0,     0,
       0,     0,     0,  1104,  2642,     0,     0,  1105,     0,     0,
       0,     0,     0,  1109,     0,     0,  2643,  1092,  1093,  1094,
    1095,  1096,  1097,     0,     0,     0,     0,     0,  2644,  2645,
       0,     0,     0,  1098,  1099,  1100,     0,  2646,     0,     0,
    2647,     0,     0,     0,     0,  1106,     0,     0,   272,     0,
       0,     0,     0,     0,     0,     0,     0,  1109,  1775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,     0,     0,     0,     0,     0,
    1110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,     0,     0,  1102,     0,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,     0,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,  1109,     0,  1102,  1092,  1093,  1094,
    1095,  1096,  1097,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,  1099,  1100,     0,     0,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1092,  1093,  1094,  1095,  1096,  1097,     0,     0,
       0,     0,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,  1110,     0,     0,     0,     0,     0,     0,  1098,  1099,
    1100,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,     0,     0,  1105,     0,     0,     0,     0,
    1092,  1093,  1094,  1095,  1096,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1103,  1098,  1099,  1100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,  1106,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1776,     0,     0,     0,
       0,     0,     0,  1101,     0,     0,  1102,     0,     0,     0,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1106,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,     0,  1779,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1101,     0,
    1107,  1102,     0,     0,     0,     0,     0,     0,  1101,     0,
       0,  1102,     0,     0,     0,     0,     0,     0,     0,  1108,
       0,     0,     0,     0,     0,     0,     0,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1101,     0,     0,  1102,
       0,     0,  1109,     0,     0,     0,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,  1098,  1099,  1100,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,  1105,     0,     0,     0,     0,     0,
       0,  1109,     0,     0,     0,     0,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,     0,     0,     0,     0,     0,     0,
    1103,     0,  1098,  1099,  1100,     0,     0,     0,     0,  1110,
    1103,     0,  1106,     0,     0,  1104,     0,     0,     0,  1105,
       0,     0,     0,     0,     0,  1104,     0,     0,     0,  1105,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
    1107,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1110,     0,
       0,     0,     0,     0,     0,     0,     0,  1106,  1103,  1108,
       0,     0,     0,     0,     0,     0,     0,  1106,     0,     0,
       0,     0,     0,  1104,     0,     0,     0,  1105,  1087,  1088,
    1089,  1090,  1091,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,  1101,     0,  1108,  1102,  1092,  1093,  1094,  1095,
    1096,  1097,     0,     0,  1108,  1106,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,     0,  1089,  1090,  1091,     0,
       0,     0,  1098,  1099,  1100,     0,     0,     0,     0,     0,
       0,  1109,  1101,  1107,     0,  1102,     0,     0,     0,     0,
       0,  1092,  1093,  1094,  1095,  1096,  1097,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,     0,  1098,  1099,  1100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1109,  1092,  1093,  1094,
    1095,  1096,  1097,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,     0,  1098,  1099,  1100,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,   720,   721,     0,     0,
       0,     0,   269,   722,   723,    41,     0,     0,     0,  1104,
       0,     0,     0,  1105,  1109,     0,     0,     0,     0,     0,
       0,     0,     0,  1110,     0,     0,     0,     0,     0,     0,
       0,     0,  1101,  1110,  1103,  1102,   724,     0,     0,     0,
       0,   725,  1101,     0,     0,  1102,     0,     0,   726,  1104,
       0,  1106,     0,  1105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1774,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,  1101,     0,  1107,
    1102,  1110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,     0,  1101,     0,     0,  1102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,    82,     0,   728,  1104,
       0,     0,     0,  1105,     0,     0,     0,     0,     0,  1104,
    1109,     0,     0,  1105,     0,     0,     0,     0,     0,   720,
     721,     0,     0,     0,     0,   269,   722,   723,    41,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1106,     0,     0,  1104,     0,     0,     0,  1105,     0,
    1109,  1106,     0,     0,     0,     0,     0,     0,     0,   724,
       0,     0,     0,     0,   725,     0,     0,     0,     0,  1107,
       0,   726,     0,     0,     0,  1103,     0,  1110,     0,  1107,
       0,     0,     0,     0,     0,     0,  1106,     0,  1108,     0,
    1104,     0,     0,     0,  1105,   729,     0,     0,  1108,   727,
     730,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,  1110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   731,   720,
     721,     0,  1106,  1108,     0,   269,   722,   723,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,   732,     0,     0,     0,     0,     0,   724,
    1109,     0,     0,     0,   725,   733,     0,     0,     0,  1108,
    1109,   726,     0,     0,     0,     0,     0,     0,     0,    82,
       0,   728,     0,   734,     0,     0,     0,     0,   735,     0,
       0,   736,     0,     0,     0,     0,     0,     0,     0,   727,
       0,     0,   737,     0,     0,  1109,     0,     0,   738,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   739,     0,
       0,     0,     0,   740,     0,     0,   741,  1110,     0,   742,
       0,     0,     0,     0,     0,     0,     0,  1110,   743,   744,
       0,     0,     0,     0,     0,     0,     0,     0,   720,   721,
       0,  1109,     0,     0,   269,   722,   723,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,     0,   729,  1197,
     745,  1091,     0,   730,   746,     0,     0,     0,   724,    82,
       0,   728,   747,   725,     0,     0,     0,     0,     0,     0,
     726,     0,     0,   748,     0,     0,     0,     0,     0,   749,
       0,   731,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   727,  1880,
    1881,     0,  1882,     0,   750,   269,  1883,  1884,    41,     0,
       0,     0,     0,     0,     0,     0,   732,     0,     0,     0,
    1092,  1093,  1094,  1095,  1096,  1097,     0,     0,   733,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,     0,
       0,     0,     0,     0,  1885,     0,   734,     0,   751,     0,
       0,   735,     0,     0,   736,   752,     0,   753,   729,     0,
       0,     0,     0,   730,     0,   737,     0,   754,   755,   756,
       0,   738,     0,     0,     0,     0,   757,     0,     0,     0,
       0,   739,     0,     0,     0,     0,   740,   272,    82,   741,
     728,   731,   742,     0,     0,     0,     0,     0,     0,     0,
       0,   743,   744,     0,     0,     0,     0,     0,  1880,  1881,
       0,  1882,     0,     0,   269,  1883,  1884,    41,     0,     0,
       0,     0,  1880,  1881,     0,  1882,   732,     0,   269,  1883,
    1884,    41,     0,     0,     0,     0,     0,     0,   733,     0,
       0,     0,     0,   745,     0,     0,     0,   746,     0,     0,
       0,     0,     0,  1885,     0,   747,   734,     0,  1090,  1091,
       0,   735,     0,     0,   736,     0,   748,  1885,  2162,   696,
       0,     0,   749,     0,     0,   737,  1101,     0,     0,  1102,
       0,   738,     0,     0,     0,     0,     0,   729,     0,     0,
       0,   739,   730,     0,     0,     0,   740,   750,     0,   741,
       0,     0,   742,     0,     0,     0,     0,     0,     0,     0,
       0,   743,   744,     0,     0,     0,     0,     0,  1880,  1881,
     731,  1882,     0,     0,   269,  1883,  1884,    41,  1092,  1093,
    1094,  1095,  1096,  1097,     0,     0,     0,     0,     0,     0,
       0,   751,     0,     0,  1098,  1099,  1100,     0,   752,     0,
     753,     0,  2567,   745,     0,   732,     0,   746,     0,     0,
     754,   755,   756,  1885,     0,   747,     0,   733,     0,   757,
       0,     0,     0,  2053,     0,     0,   748,     0,   696,     0,
     272,     0,   749,     0,     0,   734,     0,     0,     0,     0,
     735,     0,   696,   736,     0,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,   737,     0,     0,   750,     0,     0,
     738,     0,     0,  1104,     0,     0,     0,  1105,     0,     0,
     739,     0,     0,     0,     0,   740,     0,     0,   741,     0,
       0,   742,     0,     0,     0,     0,     0,     0,     0,     0,
     743,   744,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,     0,     0,     0,  1106,     0,     0,   752,     0,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     754,   755,   756,     0,  1886,     0,     0,     0,     0,   757,
       0,     0,   745,  1107,  1101,     0,   746,  1102,   696,  1887,
     272,     0,     0,     0,   747,     0,  2053,     0,     0,     0,
       0,     0,  1108,     0,     0,   748,  1888,  1880,  1881,  2054,
    1882,   749,     0,   269,  1883,  1884,    41,  1880,  1881,     0,
    1882,  2055,  1890,   269,  1883,  1884,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   750,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2226,     0,  1885,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1885,  1892,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1893,     0,     0,     0,     0,
     751,     0,     0,  1886,  1109,  2632,  2633,   752,     0,   753,
       0,   269,  1883,  1884,    41,     0,     0,  1886,  1887,   754,
     755,   756,     0,     0,     0,     0,  1103,     0,   757,     0,
       0,     0,  1887,     0,     0,  1888,     0,  1894,  1889,   272,
       0,  1104,     0,     0,     0,  1105,     0,     0,     0,  1888,
    2634,  1890,  2054,     0,     0,     0,     0,     0,     0,     0,
    2632,  2633,     0,     0,  2055,  1890,   269,  1883,  1884,    41,
       0,  1110,     0,     0,     0,     0,  1895,     0,     0,     0,
       0,     0,     0,  1106,     0,     0,     0,     0,  1896,     0,
       0,  1891,  1892,     0,     0,     0,     0,   696,     0,     0,
    1897,  1898,  2056,     0,  1893,  2634,  1892,   696,     0,  1899,
       0,  1107,  1900,  1886,     0,     0,     0,     0,  1893,     0,
     272,     0,     0,     0,     0,     0,     0,     0,  1887,     0,
    1108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1888,  1894,     0,  1889,     0,
       0,     0,     0,     0,     0,     0,  2632,  2633,     0,     0,
    1894,  1890,   269,  1883,  1884,    41,     0,     0,     0,     0,
       0,     0,     0,  1882,     0,   696,   269,  1883,  1884,    41,
       0,     0,     0,     0,     0,  1895,     0,     0,     0,  2226,
       0,     0,     0,     0,     0,     0,     0,  1896,     0,  1895,
       0,  2634,  1892,     0,     0,     0,     0,     0,     0,  1897,
    1898,  1896,  1109,     0,  1893,  1885,     0,     0,  1899,     0,
       0,  1900,     0,  1897,  1898,  2056,     0,     0,     0,   272,
     696,     0,  1899,     0,     0,  1900,     0,     0,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1894,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1895,     0,     0,     0,     0,
       0,     0,  1886,     0,     0,     0,     0,  1896,     0,     0,
       0,     0,  1886,     0,     0,     0,     0,  1887,     0,  1897,
    1898,     0,     0,     0,     0,     0,   696,  1887,  1899,     0,
       0,  1900,     0,     0,  1888,     0,     0,  1889,     0,   272,
     696,     0,     0,     0,  1888,     0,     0,  1889,     0,     0,
    1890,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1890,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,  1946,  1947,  1948,  1949,  1950,  1951,     0,     0,     0,
    1886,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3106,  1892,     0,     0,     0,  1887,     0,     0,     0,     0,
       0,  1892,     0,  1893,     0,     0,     0,     0,     0,     0,
       0,     0,  2635,  1893,     0,  2636,     0,   204,   205,     0,
       0,     0,     0,     0,     0,     0,   206,     0,  2637,     0,
    1952,     0,     0,     0,     0,  1886,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1894,     0,     0,     0,     0,
    1887,     0,     0,     0,     0,  1894,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2635,  2638,  2639,
    2636,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2640,     0,  2637,  1895,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1895,     0,  1896,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1896,     0,  1897,  1898,
       0,  2226,     0,     0,     0,     0,     0,  1899,  1897,  1898,
    1900,     0,     0,  2641,  2639,     0,     0,  1899,   272,     0,
    1900,  1886,     0,     0,  3071,     0,  2640,     0,   272,     0,
       0,     0,     0,     0,     0,  1886,  1887,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1887,     0,  2642,  2635,     0,     0,  2636,     0,     0,     0,
       0,     0,     0,     0,  2643,     0,     0,  1888,  2641,  2637,
    1889,     0,     0,     0,     0,     0,  2644,  2645,     0,     0,
    3072,     0,     0,  1890,     0,  2646,   207,     0,  2647,     0,
       0,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,     0,  3073,     0,  2642,     0,     0,
    2639,     0,     0,     0,  3074,     0,     0,     0,     0,  2643,
       0,     0,  2640,     0,  1892,   208,     0,     0,     0,     0,
       0,  2644,  2645,     0,     0,     0,  1893,     0,     0,     0,
    2646,     0,     0,  2647,   209,     0,     0,     0,     0,     0,
    3075,   272,     0,  1953,     0,     0,     0,     0,  3076,     0,
     210,     0,     0,     0,  2641,     0,  1954,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1894,     0,
       0,     0,     0,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,     0,     0,     0,     0,
       0,     0,     0,  2642,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2643,     0,  1895,     0,     0,
       0,     0,     0,   214,     0,     0,     0,  2644,  2645,  1896,
    1955,     0,     0,   215,     0,     0,  2646,  1956,     0,  2647,
       0,  1897,  1898,     0,     0,     0,     0,   272,   836,   216,
    1899,     0,  3077,  1900,     0,     0,     0,   837,     0,     0,
       0,   272,     0,     0,     0,     0,   838,     0,     0,     0,
       0,   839,     0,     0,     0,     0,  1957,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1958,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1959,  1960,   218,   840,     0,     0,  1961,     0,     0,
       0,     0,   841,     0,     0,     0,     0,  1962,   219,     0,
       0,     0,     0,     0,     0,   220,     0,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1963,
       0,     0,  1964,  1965,     0,     0,     0,     0,  1966,   222,
       0,     0,   223,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   842,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,   843,     0,     0,     0,     0,     0,     0,
     844,     0,   845,     0,     0,  1967,     0,     0,     0,     0,
       0,     0,   846,     0,     0,  3078,     0,  1968,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,     0,     0,     0,   847,     0,
       0,     0,     0,     0,     0,     0,   848,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   849,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   850,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   851,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   852,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   853,   854,
     855,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   856,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   857
};

static const short yycheck[] =
{
       4,   328,   835,   714,   864,     0,   188,   697,   516,    13,
      14,   711,    66,   194,   986,   831,   846,  1496,   212,  1557,
     842,   843,  1000,   845,  1408,   847,   848,  1697,   522,    24,
     423,  1867,   993,  1376,   154,    30,   544,  1749,   508,   547,
     927,    45,    46,   418,   514,    82,  1701,   176,   518,   363,
     498,   446,  2003,  1808,   941,  2189,   872,  1362,  1373,  1304,
      62,  2306,  2307,  2308,   118,  1620,   480,   736,    20,     5,
      26,    66,    76,   505,    26,    79,  1272,  1273,   453,    26,
       5,   456,   264,    26,    23,   785,    25,    91,    23,     5,
      25,   466,   388,    95,    98,   470,   225,    26,   102,   474,
       5,   105,   106,     5,    63,  2287,   481,   111,   112,  1945,
    2309,   486,   505,   488,    24,     5,    26,   237,   238,   494,
      20,     5,   497,   118,    24,   958,    26,   960,    98,   504,
      23,    24,    25,    26,   509,    24,  2420,    26,     5,   141,
       5,     5,   517,   145,  1028,   540,   150,    85,    86,   153,
      24,    25,    26,   528,   158,     5,     5,   532,    24,   340,
      26,   536,  2402,  2231,  2232,  2233,  2234,   542,   447,    74,
     545,    26,    18,    60,    18,    80,   509,    23,    24,    25,
      60,    25,    66,    79,    68,    24,    70,    26,     5,    32,
     469,    26,   196,  1692,  1693,    26,     6,  1696,  1632,    26,
       5,    23,    24,    25,    26,   418,    26,     5,   421,   422,
       5,    23,    24,    25,    26,    26,    23,    24,    25,    26,
     931,     5,   435,    25,    26,   227,     5,    23,    24,    25,
     234,  1886,    32,    24,   513,    26,   240,     6,    89,     5,
     453,   696,  1933,   456,   523,   524,     5,   251,   527,   462,
     341,   132,   531,   466,   533,   147,     5,   470,   537,   147,
     539,   474,   427,   160,    22,   478,   479,    24,   481,    26,
      24,   484,    26,   486,   487,   488,   455,   187,   280,     5,
     282,   494,    26,   386,   497,   287,  2570,    23,    24,    25,
      26,   504,  1671,     5,   187,  1674,   509,   271,  1797,    23,
      24,    25,    26,   328,   517,     6,  1581,   292,    54,    55,
     364,   365,   271,  2948,   172,   528,   455,  2726,     5,   532,
      24,    26,    26,   536,  1994,   544,   160,   536,     5,   542,
     574,  1810,   545,   279,   336,  2286,    82,    83,    84,     5,
      33,    34,    35,    36,   187,   388,   292,     5,   187,  1209,
       5,   353,   356,     5,  2939,   359,  2941,  2193,    46,    47,
      48,    49,    50,   367,     0,   187,     5,   187,   204,   364,
     365,   615,    26,   232,     0,   187,   585,  1061,    26,   383,
     187,   385,   341,     5,  2054,   187,   186,   187,    24,     9,
     245,    11,    12,    13,    14,    15,    16,   616,  1376,    30,
     853,   854,   896,    17,    18,  2827,   271,   271,   412,     5,
     268,    25,    26,   417,   637,   419,   420,   640,   641,   423,
     424,    18,   426,    26,   371,   429,     5,   386,  2850,     5,
     187,  3066,    27,   187,     5,     5,   440,     5,  2620,   618,
    2862,   426,     5,   447,   341,    17,    18,    19,    20,    21,
      17,    18,    19,    20,    21,   459,     5,  1168,     5,   624,
     835,     5,     5,     5,    26,   469,     5,     5,   472,     5,
    1745,     5,   138,   231,     5,     5,   133,   134,   482,   618,
     426,     5,   187,     5,     5,   280,   511,    84,     5,  2729,
       5,   346,  1991,   148,   498,   499,   148,   522,     5,   392,
       5,   505,   593,   392,     5,     5,     5,   341,    62,   513,
      28,   515,   516,     5,   407,   346,     5,  2016,  2927,   523,
     524,  2212,   526,   527,     5,   529,     5,   531,   624,   533,
       5,  1987,  1040,   537,     5,   539,     5,   541,     5,   543,
     544,     5,   546,   547,   587,   549,   350,     5,     5,  3134,
     506,  2050,   831,     5,   657,  1989,  1011,   437,  1248,   381,
     396,   381,    17,    18,    19,    20,    21,   881,  1039,   883,
       9,   388,   370,   187,   267,   468,  2998,   270,   388,   272,
     392,   336,  1014,   958,   959,   960,  1034,   866,   242,  1037,
    1038,  1039,   566,   872,  1978,   407,   392,  1297,  1298,   292,
     427,   255,   346,   280,   388,   884,  1306,   566,  1056,   302,
     889,   407,   559,   468,  1889,  2153,   427,  1813,   423,   388,
    2571,  1014,   835,   593,   459,  1509,   959,   386,   321,   249,
     511,   523,   537,   529,    22,   523,   427,   468,   554,   242,
     615,  1149,  1136,   502,   423,   542,   548,   651,  2027,  1349,
     977,   344,   255,   540,  1148,   348,   392,   423,   587,  2197,
     540,   551,   484,    33,    34,    35,    36,  2205,  2206,  2851,
    2852,   407,   674,   583,   423,   679,   363,   681,   575,   618,
     242,   548,   978,   618,  2883,  1572,   624,   388,   647,   648,
     649,   616,   696,   255,   544,   544,   498,   423,  2982,   658,
    1132,   566,   566,   336,  2772,   451,  1154,   711,   551,   665,
     610,   423,  1261,   665,   468,  2849,   720,   721,   665,  1227,
     625,   610,   665,  1137,   660,   618,  2562,  2282,  2003,  2228,
     388,   735,   616,   426,    26,   574,   610,   741,   742,  1132,
     624,  1194,   746,   587,   610,   958,   959,   960,   368,   388,
     552,   551,   756,  1201,  1423,  1226,  2890,  2002,  2101,  1737,
     388,  1269,  1270,   450,  3048,   598,   388,  2423,   388,  2524,
    2426,  2076,   618,  2528,  1458,  1245,   433,  1461,  1226,  2054,
     467,   785,  2494,  1231,  2099,   478,   637,   638,   639,   640,
     641,   548,   388,   539,   422,  2053,   618,  2055,   356,  2867,
    2299,  2869,  2870,  2871,  2872,   425,   618,   246,   512,   388,
    1788,   618,   388,   427,  3098,  1648,  3100,   388,   388,   473,
     388,   576,   618,   510,   427,   388,  1221,   831,   832,   239,
     384,    22,  2288,  2289,     5,   489,   582,   435,    26,   388,
     356,   388,  2226,   231,   388,   388,   388,   427,   446,   388,
     388,   423,   388,  2654,   388,   409,   423,   388,   388,  1138,
    1139,  1140,   866,   550,   388,   427,   388,   388,   872,   989,
     473,   388,   992,   388,  2636,   455,  3121,    25,    26,  1158,
     884,   388,   618,   388,   618,   889,   489,   388,   388,   388,
     894,  1385,   579,   581,   618,   187,   388,   267,   330,   388,
     270,   588,   272,   350,  2855,   623,     5,   388,   912,   388,
      24,   473,  2411,   388,  2413,   473,  1195,   388,  2573,   388,
     455,   388,   292,   927,   388,    13,   155,   489,   646,  1399,
     388,   388,   302,   388,   554,   617,   388,   941,  1638,   493,
     352,  1220,   624,   576,   383,   427,   385,    24,   536,    26,
     382,   321,    25,    26,   279,  2230,   336,   473,  1237,   165,
     519,  2236,  2237,  2238,  2239,  2240,  2241,   292,  1247,   662,
    1152,   359,   454,  1010,   344,   455,  2172,   357,   348,     9,
     600,    11,    12,    13,    14,    15,    16,   435,  1458,   427,
     994,  1461,   454,   455,   998,   999,  1000,   585,   446,   187,
    1508,   621,   110,  1833,    24,   533,    26,  1011,  2875,  2845,
    1014,  2286,  1016,  1017,   427,  2553,  1020,   850,   427,  2886,
     321,   155,    25,    26,   857,   583,    24,    24,    26,    26,
    1034,  1035,   586,  1037,  1038,  1039,  1040,   427,  1042,   187,
     231,  1045,   321,   359,   598,   599,   455,  2305,  2306,  2307,
    2308,   367,  1056,   607,  1058,   455,   426,   245,  1062,  1919,
     536,  1555,  2863,  2864,   293,   427,  1070,   583,  1072,  1073,
     235,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,   427,   381,
    2051,    33,    34,    35,    36,    24,   412,    26,  1102,  1103,
      26,   426,   332,  1107,   422,  1109,  2868,   587,   478,   585,
     187,  1619,  2874,   343,   187,  2877,  2878,  2879,  2880,   531,
    1124,    25,  2621,  2101,    25,    26,  1501,   292,  1132,   292,
    1624,  2406,   427,   545,  1138,  1139,  1140,  2098,   618,    24,
     369,    26,    24,  2401,    26,  1149,  2404,  1151,   455,  1153,
    1154,    20,   488,   427,  1158,  1603,  1604,    26,   570,   293,
    1993,   497,  2976,  2977,   427,   395,  1295,   187,   359,  2444,
     478,  2670,  1301,  2828,    24,  2830,    26,   478,   427,   344,
     410,   344,  2015,   348,   187,   348,    24,   301,    26,   187,
     187,  1195,   623,   307,   308,   309,   576,  1201,   427,   478,
    1479,    24,    24,    26,    26,   161,   542,   619,   164,   545,
      24,  1901,    26,   327,   645,   646,  1220,  1337,  2888,   249,
    1224,    25,  1226,  1227,  1503,  2112,  1346,  1231,  1507,   435,
    1544,  1235,  1236,  1237,  1728,   369,    24,   427,    26,  2623,
     446,   427,  3004,  1247,   473,  3007,  3008,  3009,  3010,   623,
     427,    24,  1627,    26,    24,   427,    26,  1261,   187,  1538,
     489,   426,   468,   426,  1268,  1269,  1270,   624,  1738,   475,
     500,   645,   646,  1648,    20,  3089,  1976,  3091,   543,   468,
      26,   546,   454,   455,   549,  1564,   187,   476,  1501,   624,
    1294,  1739,   662,  1297,  1298,  1789,  2571,  1791,  1302,   427,
    1304,   440,  1306,    25,  2579,   187,  1800,  2582,  2583,  2584,
    2585,   267,    27,    28,   270,   623,   161,    20,  2018,   164,
     459,   435,   623,    26,   438,   267,   454,   455,   270,  2090,
     272,  2092,  2093,   472,   642,   643,   292,    26,   368,   473,
    1342,   642,   643,   188,   623,  1349,   518,   235,   462,   187,
     292,  3113,   638,   639,   662,   489,    20,    25,  1362,  2858,
     302,   662,    26,   642,   643,   187,   456,  2866,   482,  1373,
      20,   618,  1376,   187,  2632,  2633,    26,   528,  2636,    25,
     470,   532,   363,   662,   474,   536,  3056,    24,    20,    26,
     518,  1395,  1396,  1397,    26,   425,   486,   454,   455,   187,
     435,    61,   344,   517,   292,  2221,   348,    25,    24,  1879,
      26,   446,   338,   102,  1627,    25,   161,   187,  2278,   164,
     346,   347,   267,   537,   538,   270,   455,   131,  1432,  1433,
    1434,    25,  1436,   468,   548,  1648,   363,    18,    25,   553,
     475,    25,    23,   188,    25,   371,    20,   292,   374,    20,
    2949,  1730,    26,  2040,   618,    26,   344,  2732,  1462,  2046,
     348,  1465,  2440,   152,    24,    25,   392,    18,    25,   450,
     426,  2432,    23,    24,    25,  1479,  2995,   131,   592,   106,
     107,   108,  3001,    25,   426,   116,   467,    23,    25,    25,
    2969,    56,   196,  1497,   198,    23,   388,    25,   187,  1503,
     189,  1505,  1506,  1507,  1508,   611,   612,   613,   614,   213,
      23,   625,    25,  1792,  1793,  1794,  1795,   221,  1133,  1912,
    1135,   225,   267,   450,   554,   270,   284,   285,   427,   510,
     647,   648,   236,   358,  1538,   618,   478,  1816,   426,  1543,
     467,    25,   196,   427,   198,   423,   250,   292,  1729,  1553,
     363,   427,  3090,  1557,   640,   641,   363,     5,  2833,   213,
    1564,  1755,    17,    18,    19,    20,    21,   221,  1572,   550,
     600,   225,   498,   422,  1578,  1579,    59,  1581,   647,   648,
    2855,   426,   388,   510,  2632,  2633,   435,   218,    25,  3068,
     618,   621,  1880,  1881,  1873,   226,   250,   286,   579,  1603,
    1604,   232,   255,   234,   423,   388,   358,   588,  3087,    20,
    2868,  2105,  1987,   462,   245,  1619,  2874,  2875,  1993,  2877,
    2878,  2879,  2880,   550,    25,    25,   552,    25,  2886,   478,
     479,    25,    25,   559,  1638,   484,   296,   450,   487,  3138,
    2015,    20,   273,   450,    25,   427,   851,   852,   131,   363,
     855,   856,   579,  1657,   467,    25,    25,   618,   289,   388,
     467,   588,  2156,   294,     5,   354,  1670,  1671,  3147,  2944,
    1674,   388,   388,   362,   299,   306,   196,   366,   388,   388,
     200,   426,   313,   388,  2544,   622,  1690,   388,  1692,  1693,
       5,   388,  1696,  1697,   354,   299,   388,   510,   388,   622,
     388,   388,   427,   510,   618,   455,   366,   615,   618,     8,
     423,  2683,  2542,   196,   403,   198,   376,   476,   523,  1723,
     662,   427,  1726,   417,   263,  3000,  1730,  2006,   427,  2008,
     213,    44,    45,  1737,   394,  1739,   450,   550,   221,     5,
     593,  1745,   225,   550,   404,  2445,  3004,   407,   427,  3007,
    3008,  3009,  3010,   467,   427,   427,  2305,  2306,  2307,  2308,
     420,   427,   427,   456,   427,   427,   579,   250,   427,   427,
     427,  3046,   579,  1777,  1987,   588,  1780,   616,   427,   427,
    1993,   588,   471,   427,  1788,   427,   427,   427,  1792,  1793,
    1794,  1795,   427,  1797,   427,   616,   510,   427,   427,  1803,
    1804,   427,  2015,  1807,  1808,   427,   417,   120,   121,   469,
     123,   124,  1816,   363,   657,   128,  2264,   456,  2266,   427,
     657,   510,  1826,   323,     8,    90,    91,    92,    93,    94,
      95,   363,   145,   146,   594,     5,   550,   468,  2549,   499,
       5,   106,   107,   108,   475,   380,   535,   427,   427,   509,
     163,   427,   427,   341,   427,  3113,   587,   576,   968,     8,
      13,  3136,   573,  3121,     5,   579,   497,   657,     5,  1873,
     530,   502,    29,   533,   588,   535,  1880,  1881,   657,   417,
     427,   427,    25,  2162,    63,  1889,  2165,    44,    45,    25,
     579,    89,   455,   455,    25,     5,  1900,   593,  3173,   588,
     450,   587,   427,   563,  2117,   427,   618,   468,  1912,   427,
     427,    20,   572,  2288,  2289,    20,  1920,   467,   450,   427,
     233,   427,   624,   427,   624,   445,   446,   660,   347,   624,
     554,  2791,   623,    17,     5,   467,    18,    25,    25,  2799,
     150,   215,  2221,  2437,  2339,  2340,  2341,    24,  2343,  2344,
    2345,  2346,  2347,  2348,   621,   576,   479,  2352,  2648,   587,
     510,    19,    20,   120,   121,   479,   123,   124,     5,     5,
     148,   128,  1976,   618,   544,   544,    25,   544,   510,   396,
     318,   246,    25,   427,   249,   427,  2040,  1991,   145,   146,
    1994,   427,  2046,    17,    18,    19,    20,  2001,  2002,  2003,
     550,   427,  2006,   427,  2008,   388,   163,   662,   574,   618,
     455,   544,  2016,   388,  2018,   388,   388,  2511,   550,    25,
     540,   388,   388,  2027,  2532,   388,   388,   388,   388,   579,
     550,  2539,    90,    91,    92,    93,    94,    95,   588,  2220,
      19,    20,   427,   615,     5,  2040,  2050,   579,     5,     5,
    2054,  2046,  2056,   577,  2887,     5,   588,   480,   388,   618,
     624,     5,   427,  2067,  2764,  2096,    90,    91,    92,    93,
      94,    95,  2076,   427,   623,  2288,  2289,    16,    17,    18,
      19,    20,    21,  2632,  2633,  1756,   551,  2636,    25,  1760,
     624,    25,   427,   533,  1765,  2099,    63,  2101,  1769,   322,
    1771,  1772,  1773,   368,     5,  2109,     5,  2967,  2112,   388,
     427,    90,    91,    92,    93,    94,    95,   427,   383,   357,
     594,   434,   387,   624,    13,   417,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     5,   417,   548,   658,   544,  2152,  2153,
       5,    90,    91,    92,    93,    94,    95,    25,  2162,   427,
     425,  2165,    98,   624,   618,   427,  2170,   106,   107,   108,
     623,     5,   423,   637,   423,  2724,   457,   457,  2727,  2183,
     427,  2185,   427,  2187,   427,   427,   427,   427,   453,     8,
    2194,   427,    25,  2197,   714,     5,   353,  2201,    25,   587,
     388,  2205,  2206,   388,    24,   388,    24,   472,    24,    24,
       5,    90,    91,    92,    93,    94,    95,  2221,  1328,  1329,
     388,     5,   618,   618,  2228,  1335,  2230,   106,   107,   108,
       8,   618,  2236,  2237,  2238,  2239,  2240,  2241,    24,  2939,
     760,  2941,  3102,   322,   341,   402,   341,   455,    61,  3071,
    3072,  3073,  3074,  3075,  3076,   341,  2535,   357,   427,   618,
    2264,   422,  2266,  2974,     6,     7,     8,     9,    10,    11,
      12,   427,   427,   455,  2305,  2306,  2307,  2308,     5,   427,
     427,   427,  2286,   427,    25,  2564,     5,   427,     5,   554,
       5,   649,     5,    24,   615,  2299,    25,    13,   593,  2793,
     593,  2305,  2306,  2307,  2308,  2309,  2310,   246,    13,   427,
     249,   618,   618,     5,  2593,     5,  2320,  2321,  2322,  2868,
     133,   134,   157,     5,  2328,  2874,  2875,     7,  2877,  2878,
    2879,  2880,   388,    29,   427,     5,   618,  2886,   173,   174,
     624,    25,  2790,   618,  2526,     8,   181,    25,    44,    45,
      25,    25,   624,   388,   388,  2682,   621,   587,   388,   388,
     624,   388,   388,   388,    20,     5,   271,   246,   564,  2400,
     249,  2402,   388,     5,     5,   188,     5,    73,   544,   237,
     215,   194,     5,   388,    29,  2389,   388,  2391,   569,   224,
     624,   618,   437,   618,   388,   427,  2400,     6,  2402,    44,
      45,   468,  2406,   624,     5,   624,   551,  2411,  2412,  2413,
     207,   931,    24,   622,    24,   622,    24,   617,   253,    24,
     443,    24,   468,    25,   120,   121,    25,   123,   124,   368,
      25,    25,   128,    25,  3134,   427,  2440,   427,  1548,    25,
    2444,  2445,   293,    25,   383,     5,   388,   388,   387,   145,
     146,   264,   587,   266,   265,  3004,   465,   523,  3007,  3008,
    3009,  3010,     5,   298,  2958,   427,   388,   163,   548,   237,
      24,   423,   388,     5,   388,   120,   121,   437,   123,   124,
     341,  1591,    20,   128,   137,     5,   425,   551,     5,   368,
      13,   618,   427,  3042,   427,   427,  3207,   427,  2502,   427,
     145,   146,   427,   427,   383,   340,   207,     5,   387,   438,
     455,   388,  2887,    25,   453,   388,  2795,   388,   163,    25,
    2524,   388,     5,  2527,  2528,   365,   617,   340,  2532,   328,
     427,  2535,   388,   472,    24,  2539,    26,   233,   370,    25,
     388,   388,   388,   427,   566,   341,   425,   388,   624,  2553,
     238,   388,   388,   573,    44,    45,   544,   388,   388,   388,
    2564,   427,   388,   618,  3113,    13,     7,  2571,   236,   236,
      25,   624,  3121,    25,   453,  2579,   388,   427,  2582,  2583,
    2584,  2585,  2586,   389,   444,   618,   388,   388,   388,  2593,
       5,     5,    24,   472,   388,   238,   624,   388,   423,   427,
     388,  2632,  2633,   624,     5,  2636,   388,   388,   388,   388,
    2614,    17,    18,    19,    20,   554,   388,  2621,   431,  2200,
    3157,  2109,  1863,  2152,  1238,  1565,  2630,    37,  2632,  2633,
     120,   121,  2636,   123,   124,    39,   364,  1804,   128,   287,
    1810,    71,    72,  2647,   141,    75,    76,    77,  1168,   145,
    2183,   209,   465,   281,   288,   145,   146,   353,   471,   396,
     473,  1341,   353,   211,   477,  1342,  2670,   480,  2672,  1763,
     483,   371,  2497,   163,  2887,   554,   383,   316,   315,   385,
     493,  3147,   621,  1538,    90,    91,    92,    93,    94,    95,
    1413,  1780,  1668,  2724,   965,  1675,  2727,   187,  2729,   512,
    1268,  1221,   526,  1794,  1507,  2255,   402,   520,   521,   522,
    2596,  3171,  1595,   526,  1916,  1271,  1798,  1614,  2273,  2275,
    2724,   534,  1154,  2727,  2807,  2729,    24,   118,  2732,    30,
      30,  2704,   483,   653,  1570,  1576,   266,   550,   434,  1914,
     932,   681,   621,   233,   174,  1276,  1579,  1857,  1858,  2904,
    2701,   181,  3087,  1145,  1192,  1630,  1276,  1135,  1868,  2237,
    2764,  2379,  2914,   884,  2768,  1066,  2770,  2377,  1220,  2361,
    1020,  2049,  1788,  1379,  1356,  1987,  3173,  3138,  3025,  2019,
    2410,  2050,  2764,  1696,  2446,   215,  2790,  2389,  2056,  3042,
    2391,  2795,  1294,  2727,   224,  2067,  2738,  2322,   961,  2950,
    2444,  2951,  2631,  3082,  2300,  3136,  2236,  2919,  1290,  2992,
    2866,  1921,  1922,  1923,  1924,   957,  2630,  1263,  2885,  1929,
    1930,  1931,  1932,   253,   254,  2874,  1726,  1150,   362,  2833,
      -1,    -1,    17,    18,  1944,    20,    -1,  2868,    23,    24,
      25,    26,    -1,  2874,  2875,    -1,  2877,  2878,  2879,  2880,
      -1,  2855,    -1,    -1,  2858,  2886,    -1,    -1,    -1,    -1,
      -1,    -1,  2866,    -1,  2868,    -1,    -1,    -1,   298,    -1,
    2874,  2875,    -1,  2877,  2878,  2879,  2880,    62,    -1,  2883,
      -1,  2885,  2886,    -1,  2888,    -1,    -1,    -1,  2919,    -1,
      -1,    -1,  2896,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   714,    -1,    -1,    -1,    -1,   720,   721,    -1,    -1,
     340,    -1,    -1,    -1,  3193,    -1,    -1,    -1,  2028,  2029,
      -1,   735,    -1,    -1,    -1,  2035,  2036,   741,   742,    -1,
      -1,    -1,   746,    -1,    -1,  2939,    -1,  2941,    -1,    -1,
    2944,    -1,   756,    -1,   434,  2949,    -1,  2951,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,   782,
      -1,    -1,    -1,  3004,    -1,    -1,  3007,  3008,  3009,  3010,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2992,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3000,    -1,    -1,    -1,
    3004,    -1,   187,  3007,  3008,  3009,  3010,  3011,    -1,    -1,
      -1,  3042,   825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3025,    -1,    -1,    -1,    -1,    -1,    -1,   841,   842,
     843,    -1,   845,    -1,   847,   848,    -1,    -1,  3042,    -1,
     853,   854,  3046,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3056,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1581,    -1,  2173,  2174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2182,    -1,    -1,    -1,    -1,    -1,  3082,  3083,
    2190,    -1,  3113,   896,    -1,    -1,  3090,    -1,    -1,    -1,
    3121,    -1,    -1,    -1,   907,    -1,    -1,    -1,    -1,  2209,
    2210,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,  3113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3121,   931,   932,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,    -1,
    3134,    -1,  3136,    -1,  3138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   956,   957,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2265,    -1,  2267,    -1,    -1,
      -1,    -1,    -1,    -1,  2274,    -1,  2276,    -1,    -1,  3173,
    1690,    -1,    -1,    -1,    -1,    -1,    -1,  1697,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3193,
      -1,    -1,    -1,    -1,    -1,    -1,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2329,
    2330,  1035,   407,  2333,  2334,  1745,    -1,    -1,  1042,    -1,
      -1,  1045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,    -1,   427,    -1,  1058,    -1,    -1,    -1,  1062,    -1,
      -1,    -1,    -1,    -1,   439,   440,  1070,  2367,  1072,  1073,
      -1,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1102,  1103,
      22,    -1,    -1,  1107,    -1,  1109,   481,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,   493,    -1,
      -1,    -1,  1125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1133,    -1,  1135,  1136,  1137,    -1,    -1,    -1,    60,    -1,
      -1,  1144,  1145,    -1,    -1,  1148,    -1,    -1,    -1,  1152,
      -1,    -1,  1155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    -1,  1168,    -1,    89,    -1,    -1,
    1880,  1881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1889,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,  1194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,   131,
      -1,   586,    53,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,   598,   599,  2525,    -1,    -1,    -1,  2529,
    1233,    -1,   607,    -1,    -1,   610,    -1,    -1,    -1,   161,
      -1,    -1,   164,   618,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1257,    -1,    -1,    -1,    -1,  1262,
    2560,    -1,   103,   104,    -1,    -1,   188,    -1,    -1,    -1,
     111,    -1,  1275,  1276,   196,    -1,   198,    -1,    -1,   120,
     121,    -1,   123,   124,  1994,   207,    -1,   128,    -1,    -1,
      -1,   213,    -1,  2003,  2594,    -1,    -1,    -1,    -1,   221,
      -1,    -1,    -1,   225,   145,   146,    -1,    -1,    -1,   231,
      -1,    -1,    -1,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,  1330,   250,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,  2054,   267,  2056,    -1,   270,    -1,
     272,    -1,    -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     302,    -1,  1385,    -1,    -1,    -1,  2096,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    -1,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   344,   106,   107,   108,   348,    -1,  1432,  1433,
    1434,    -1,  1436,    -1,    -1,   357,   358,   359,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1462,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,
    2230,    -1,    -1,   364,  2824,    -1,  2236,  2237,  2238,  2239,
    2240,  2241,    -1,  1536,    -1,    -1,    -1,    -1,    -1,  1543,
      -1,    -1,  1545,    90,    91,    92,    93,    94,    95,   390,
      -1,    -1,  1555,  1557,    -1,    -1,   478,    -1,    -1,   106,
     107,   108,    -1,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,  1576,    -1,    -1,  2286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2305,  2306,  2307,  2308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   540,    -1,
     461,  1624,  1625,  1626,    -1,    -1,    -1,  1630,    -1,  2339,
    2340,  2341,    -1,  2343,  2344,  2345,  2346,  2347,  2348,    -1,
      -1,    -1,  2352,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,    -1,  1662,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2978,  2389,
      -1,  2391,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,
    2400,    -1,  2402,    -1,    -1,    -1,  2406,    -1,    -1,   246,
     383,   623,   249,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   555,   637,   638,   639,   640,   641,
     642,   643,    -1,   645,   646,  1728,  1729,    -1,    -1,    -1,
    3030,  3031,    -1,  3033,  2444,  3035,  3036,    -1,    -1,    -1,
     662,    -1,   425,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,    -1,    -1,  1777,    -1,    -1,  1780,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1789,    -1,  1791,   472,
      -1,    -1,    -1,    -1,    -1,   636,    -1,  1800,    -1,    -1,
      -1,  3101,    -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   368,    -1,    -1,    -1,  3125,    -1,  3127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1838,   383,    -1,    -1,  2549,
     387,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2571,  3162,    -1,  1867,    -1,    -1,    -1,    -1,  2579,
      -1,   554,  2582,  2583,  2584,  2585,    -1,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3187,  3188,    -1,
      -1,  3191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,   453,    -1,    -1,    -1,
    1913,  1914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2632,  2633,    -1,   472,  2636,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,
      -1,    -1,    -1,    -1,  2724,    -1,    -1,  2727,    -1,  2729,
      -1,    -1,  2732,  2026,    90,    91,    92,    93,    94,    95,
      -1,    -1,    -1,    -1,   317,   318,   319,    -1,    -1,    -1,
     106,   107,   108,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,   342,
      90,    91,    92,    93,    94,    95,    -1,   350,    -1,    -1,
      -1,    -1,   355,    -1,   621,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,   375,    -1,   377,    -1,    -1,    -1,    -1,    -1,
      -1,   384,  2105,    -1,   387,    -1,    -1,   390,    -1,    -1,
     393,    -1,    -1,   396,    -1,    -1,    -1,    -1,   401,    -1,
      -1,    -1,    -1,  2833,    90,    91,    92,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,  2855,    -1,    -1,  2152,  2153,
      -1,    -1,   435,  2156,    -1,   438,   439,    -1,  2868,    -1,
      -1,    -1,   445,    -1,  2874,  2875,    -1,  2877,  2878,  2879,
    2880,    -1,    -1,   456,    -1,    -1,  2886,    -1,  2888,    -1,
     246,    -1,    -1,   249,    -1,    -1,  2189,    -1,    -1,   472,
    2194,    -1,   329,  2197,    -1,  2198,   479,  2200,    -1,  2202,
      -1,  2205,  2206,   486,    -1,   342,   489,   490,   491,  2919,
     493,   494,  2215,    -1,    -1,    -1,   246,  2220,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,  2944,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   534,   535,   536,   537,    -1,   539,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2974,    -1,    -1,    -1,    -1,   406,
      -1,    -1,    -1,   556,   557,    -1,   413,  2280,  2281,    -1,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
    3000,    -1,    -1,    -1,  3004,    -1,   579,  3007,  3008,  3009,
    3010,    -1,   368,    -1,    -1,   588,   589,    -1,   591,    -1,
      -1,    -1,    -1,    -1,    -1,   452,    -1,   383,    -1,    -1,
    2323,   387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3042,    -1,    -1,    -1,  3046,    -1,   368,    -1,
     477,    -1,    -1,    -1,    -1,    -1,  3056,    -1,    -1,    -1,
     487,   488,    -1,   383,    -1,    -1,   493,   387,   388,   425,
    2363,    -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,    -1,
     653,    -1,    -1,  2376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   525,    -1,
      -1,   528,   529,    -1,    -1,   425,    -1,   534,    -1,    -1,
      -1,    -1,   368,  3113,    -1,    -1,   472,    -1,    -1,    -1,
      -1,  3121,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,
      -1,   387,    -1,   453,    -1,    -1,  3136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2437,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   591,    -1,    -1,    -1,    -1,   425,
      -1,    -1,    -1,  3173,    -1,    -1,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   554,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3207,  2502,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,  2511,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2526,   554,    -1,    43,    44,    45,     5,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2549,    64,    65,  2553,
      67,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,    -1,    -1,    -1,   554,    -1,
      -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,   139,    -1,   141,   142,   143,    -1,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   154,    -1,   156,
      -1,   158,   159,    -1,    -1,   162,   163,    -1,    -1,   166,
     167,   168,    -1,   170,   171,   621,    -1,    -1,   175,   176,
      -1,   178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,    -1,    -1,
     197,    -1,   199,    -1,   201,    -1,   203,    -1,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,  2701,   216,
     217,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,   243,   244,    -1,    -1,
     247,   248,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   261,   262,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,
      -1,   278,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,
     287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,
      -1,   257,    -1,    -1,    -1,    -1,   303,   304,   305,    -1,
    2793,    -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,
     317,    -1,    -1,   320,    -1,    -1,    -1,   324,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,
     296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,   315,
      -1,    -1,    -1,    -1,   361,    -1,  2849,    -1,    -1,    -1,
     367,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   354,    -1,
     397,    -1,   399,   400,    -1,    -1,    -1,  2890,    -1,    -1,
     366,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,  2904,    -1,    -1,    -1,    -1,  2909,    -1,  2911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,    -1,
     447,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,   458,    -1,    -1,   420,   462,    -1,  2950,    -1,   466,
      -1,   106,   107,   108,    -1,  2958,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2974,    -1,   490,   491,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,
     507,    -1,    -1,    -1,    -1,    -1,   513,   514,   515,   516,
      -1,    -1,    -1,   520,    -1,    -1,    -1,   524,   484,    -1,
      -1,    -1,    -1,    -1,   531,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   499,    -1,    -1,   543,    -1,   545,    -1,
     506,    -1,    -1,   509,    -1,    -1,    -1,    -1,    -1,   556,
      -1,   558,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,   530,    -1,    -1,   533,    -1,   535,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3071,  3072,
    3073,  3074,  3075,  3076,    -1,    -1,   593,    -1,   554,   596,
      -1,    -1,    -1,    -1,    -1,   602,  3090,    -1,   605,   606,
      -1,   246,    -1,    -1,   249,    -1,   572,    -1,    -1,    -1,
      -1,    -1,    -1,   620,    -1,    -1,    -1,    -1,    -1,    -1,
     627,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,   650,   651,   652,   653,   654,   655,   656,
      -1,    -1,   659,    -1,   661,    -1,   663,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,  3207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   368,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,
      -1,    -1,   387,   388,    90,    91,    92,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
     425,    -1,   106,   107,   108,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   472,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   296,    -1,   249,    -1,    90,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   315,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   554,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    -1,
      -1,    -1,   246,   354,    -1,   249,    -1,    -1,    -1,   106,
     107,   108,    -1,    -1,    -1,   366,    -1,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,   394,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   404,    -1,    -1,   621,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,    -1,    -1,    -1,   387,   388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   368,    -1,    -1,   246,    -1,    -1,   249,   460,
      90,    91,    92,    93,    94,    95,    -1,   383,    -1,    -1,
      -1,   387,   388,   425,   368,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,   383,
      -1,    -1,    -1,   387,   388,    -1,    -1,    -1,   499,   246,
      -1,   453,   249,    -1,    -1,   506,    -1,    -1,   509,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   530,
      -1,   425,   533,    -1,   535,    -1,    -1,   453,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   554,    -1,    -1,   472,    -1,    -1,   453,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   572,   392,    -1,    -1,    -1,    -1,   368,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,
      -1,    -1,   383,    -1,    -1,    -1,   387,   388,    -1,    -1,
      -1,    -1,   554,    -1,   424,    -1,    -1,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,   249,
     440,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   425,    -1,   383,    -1,   554,    -1,
     387,   388,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     554,   481,   453,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,   425,    -1,
      -1,   472,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,   621,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   472,    -1,   621,    90,    91,
      92,    93,    94,    95,    -1,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,   383,   574,    -1,    -1,   387,    -1,    -1,
      -1,    -1,    -1,   554,    -1,    -1,   586,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,   598,   599,
      -1,    -1,    -1,   106,   107,   108,    -1,   607,    -1,    -1,
     610,    -1,    -1,    -1,    -1,   425,    -1,    -1,   618,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,    -1,    -1,   249,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   554,    -1,   249,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,   106,   107,
     108,   621,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   368,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,    -1,    -1,   425,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     472,    -1,    -1,    -1,    -1,   438,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   246,    -1,
     453,   249,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,   249,
      -1,    -1,   554,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
     383,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,   554,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     368,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,   621,
     368,    -1,   425,    -1,    -1,   383,    -1,    -1,    -1,   387,
      -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,   387,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
     453,    15,    16,    17,    18,    19,    20,    21,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,   368,   472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,
      -1,    -1,    -1,   383,    -1,    -1,    -1,   387,    17,    18,
      19,    20,    21,    -1,    -1,   453,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,
      -1,    -1,   246,    -1,   472,   249,    90,    91,    92,    93,
      94,    95,    -1,    -1,   472,   425,    90,    91,    92,    93,
      94,    95,   106,   107,   108,    -1,    19,    20,    21,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,   554,   246,   453,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   554,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,   621,    -1,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   368,    -1,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,   383,
      -1,    -1,    -1,   387,   554,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   621,   368,   249,    57,    -1,    -1,    -1,
      -1,    62,   246,    -1,    -1,   249,    -1,    -1,    69,   383,
      -1,   425,    -1,   387,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,   246,    -1,   453,
     249,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,
      -1,    -1,    -1,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   368,    -1,   187,    -1,   189,   383,
      -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,   383,
     554,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,   368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   425,    -1,    -1,   383,    -1,    -1,    -1,   387,    -1,
     554,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,   453,
      -1,    69,    -1,    -1,    -1,   368,    -1,   621,    -1,   453,
      -1,    -1,    -1,    -1,    -1,    -1,   425,    -1,   472,    -1,
     383,    -1,    -1,    -1,   387,   286,    -1,    -1,   472,    97,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   453,    -1,    -1,   621,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    17,
      18,    -1,   425,   472,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,    -1,    -1,   354,    -1,    -1,    -1,    -1,    -1,    57,
     554,    -1,    -1,    -1,    62,   366,    -1,    -1,    -1,   472,
     554,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   189,    -1,   384,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,   403,    -1,    -1,   554,    -1,    -1,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,
      -1,    -1,    -1,   424,    -1,    -1,   427,   621,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,   439,   440,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,   554,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,   286,   480,
     481,    21,    -1,   291,   485,    -1,    -1,    -1,    57,   187,
      -1,   189,   493,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,   510,
      -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    17,
      18,    -1,    20,    -1,   535,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    62,    -1,   384,    -1,   579,    -1,
      -1,   389,    -1,    -1,   392,   586,    -1,   588,   286,    -1,
      -1,    -1,    -1,   291,    -1,   403,    -1,   598,   599,   600,
      -1,   409,    -1,    -1,    -1,    -1,   607,    -1,    -1,    -1,
      -1,   419,    -1,    -1,    -1,    -1,   424,   618,   187,   427,
     189,   319,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,   440,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,   354,    -1,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,   481,    -1,    -1,    -1,   485,    -1,    -1,
      -1,    -1,    -1,    62,    -1,   493,   384,    -1,    20,    21,
      -1,   389,    -1,    -1,   392,    -1,   504,    62,   506,   187,
      -1,    -1,   510,    -1,    -1,   403,   246,    -1,    -1,   249,
      -1,   409,    -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,
      -1,   419,   291,    -1,    -1,    -1,   424,   535,    -1,   427,
      -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   439,   440,    -1,    -1,    -1,    -1,    -1,    17,    18,
     319,    20,    -1,    -1,    23,    24,    25,    26,    90,    91,
      92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,    -1,    -1,   106,   107,   108,    -1,   586,    -1,
     588,    -1,   480,   481,    -1,   354,    -1,   485,    -1,    -1,
     598,   599,   600,    62,    -1,   493,    -1,   366,    -1,   607,
      -1,    -1,    -1,   291,    -1,    -1,   504,    -1,   187,    -1,
     618,    -1,   510,    -1,    -1,   384,    -1,    -1,    -1,    -1,
     389,    -1,   187,   392,    -1,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,   403,    -1,    -1,   535,    -1,    -1,
     409,    -1,    -1,   383,    -1,    -1,    -1,   387,    -1,    -1,
     419,    -1,    -1,    -1,    -1,   424,    -1,    -1,   427,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     439,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,    -1,    -1,    -1,   425,    -1,    -1,   586,    -1,
     588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     598,   599,   600,    -1,   392,    -1,    -1,    -1,    -1,   607,
      -1,    -1,   481,   453,   246,    -1,   485,   249,   187,   407,
     618,    -1,    -1,    -1,   493,    -1,   291,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,   504,   424,    17,    18,   427,
      20,   510,    -1,    23,    24,    25,    26,    17,    18,    -1,
      20,   439,   440,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     468,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,
     579,    -1,    -1,   392,   554,    17,    18,   586,    -1,   588,
      -1,    23,    24,    25,    26,    -1,    -1,   392,   407,   598,
     599,   600,    -1,    -1,    -1,    -1,   368,    -1,   607,    -1,
      -1,    -1,   407,    -1,    -1,   424,    -1,   535,   427,   618,
      -1,   383,    -1,    -1,    -1,   387,    -1,    -1,    -1,   424,
      62,   440,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,   439,   440,    23,    24,    25,    26,
      -1,   621,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,   586,    -1,
      -1,   480,   481,    -1,    -1,    -1,    -1,   187,    -1,    -1,
     598,   599,   600,    -1,   493,    62,   481,   187,    -1,   607,
      -1,   453,   610,   392,    -1,    -1,    -1,    -1,   493,    -1,
     618,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,    -1,
     472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   424,   535,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
     535,   440,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,   187,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,   574,
      -1,    62,   481,    -1,    -1,    -1,    -1,    -1,    -1,   598,
     599,   586,   554,    -1,   493,    62,    -1,    -1,   607,    -1,
      -1,   610,    -1,   598,   599,   600,    -1,    -1,    -1,   618,
     187,    -1,   607,    -1,    -1,   610,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   618,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,    -1,   586,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,    -1,   407,    -1,   598,
     599,    -1,    -1,    -1,    -1,    -1,   187,   407,   607,    -1,
      -1,   610,    -1,    -1,   424,    -1,    -1,   427,    -1,   618,
     187,    -1,    -1,    -1,   424,    -1,    -1,   427,    -1,    -1,
     440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,   481,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,   481,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,   493,    -1,   427,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,   440,    -1,
      96,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,
     407,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,   480,   481,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   493,    -1,   440,   574,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   574,    -1,   586,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,   598,   599,
      -1,   468,    -1,    -1,    -1,    -1,    -1,   607,   598,   599,
     610,    -1,    -1,   535,   481,    -1,    -1,   607,   618,    -1,
     610,   392,    -1,    -1,   200,    -1,   493,    -1,   618,    -1,
      -1,    -1,    -1,    -1,    -1,   392,   407,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,    -1,   574,   424,    -1,    -1,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   586,    -1,    -1,   424,   535,   440,
     427,    -1,    -1,    -1,    -1,    -1,   598,   599,    -1,    -1,
     256,    -1,    -1,   440,    -1,   607,   257,    -1,   610,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   618,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   281,    -1,   574,    -1,    -1,
     481,    -1,    -1,    -1,   290,    -1,    -1,    -1,    -1,   586,
      -1,    -1,   493,    -1,   481,   296,    -1,    -1,    -1,    -1,
      -1,   598,   599,    -1,    -1,    -1,   493,    -1,    -1,    -1,
     607,    -1,    -1,   610,   315,    -1,    -1,    -1,    -1,    -1,
     326,   618,    -1,   329,    -1,    -1,    -1,    -1,   334,    -1,
     331,    -1,    -1,    -1,   535,    -1,   342,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   574,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   586,    -1,   574,    -1,    -1,
      -1,    -1,    -1,   394,    -1,    -1,    -1,   598,   599,   586,
     406,    -1,    -1,   404,    -1,    -1,   607,   413,    -1,   610,
      -1,   598,   599,    -1,    -1,    -1,    -1,   618,   126,   420,
     607,    -1,   428,   610,    -1,    -1,    -1,   135,    -1,    -1,
      -1,   618,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,   452,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   487,   488,   484,   192,    -1,    -1,   493,    -1,    -1,
      -1,    -1,   200,    -1,    -1,    -1,    -1,   503,   499,    -1,
      -1,    -1,    -1,    -1,    -1,   506,    -1,    -1,   509,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
      -1,    -1,   528,   529,    -1,    -1,    -1,    -1,   534,   530,
      -1,    -1,   533,    -1,   535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   572,    -1,   281,    -1,    -1,    -1,    -1,    -1,    -1,
     288,    -1,   290,    -1,    -1,   591,    -1,    -1,    -1,    -1,
      -1,    -1,   300,    -1,    -1,   601,    -1,   603,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   615,    -1,    -1,    -1,   326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,   547,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   663
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    44,    45,    73,   120,   121,   123,   124,   128,
     145,   146,   163,   233,   353,   402,   434,   724,   752,   753,
     803,   970,  1031,  1033,  1034,  1035,  1040,  1042,  1055,  1056,
    1057,  1058,  1059,  1474,    27,    28,   725,   726,   727,   728,
     729,    26,   935,  1493,   352,   531,   545,   570,   619,  1475,
    1475,  1475,  1475,  1475,  1475,  1475,  1475,   935,    24,   935,
    1395,  1060,   754,   753,  1474,     0,  1032,  1035,  1040,  1058,
    1474,    30,   727,   729,   935,  1477,   587,   935,  1476,   624,
     804,    24,   187,   751,   752,   923,   935,   940,  1061,  1097,
    1098,  1099,  1100,  1101,  1105,   350,   756,   757,   758,   759,
     762,   763,    53,    58,   103,   104,   111,   364,   390,   461,
     555,   636,   644,   724,   730,   895,   969,  1036,  1037,  1039,
    1043,  1044,  1050,  1062,  1083,  1216,  1226,  1474,   935,  1476,
     615,  1100,   239,   454,   455,  1107,    20,   935,  1104,   618,
     757,     5,   755,   350,   935,     5,   779,   781,   782,   935,
    1227,   935,   935,  1217,  1051,   935,   935,  1039,  1045,   257,
     296,   315,   354,   366,   376,   394,   404,   420,   460,   484,
     499,   506,   509,   530,   533,   535,   554,   572,   805,   806,
     807,   810,    24,  1097,  1103,    17,    18,    25,   427,   674,
     676,  1097,  1108,  1109,   455,    13,   802,   759,   519,  1203,
     760,   757,   762,    31,    78,    79,    87,   257,   296,   315,
     331,   354,   366,   376,   394,   404,   420,   460,   484,   499,
     506,   509,   530,   533,   535,   554,   572,   615,   765,   773,
     784,   785,   935,   427,   110,   935,   751,   896,  1084,   935,
     812,   533,   764,   788,   790,   791,   789,   798,   799,   427,
     427,   811,   455,   427,   427,   757,   786,   422,   674,    17,
      18,    19,    20,    21,   675,    25,     5,   423,  1108,    23,
      24,    25,   618,   935,   941,    18,    24,    25,   761,   941,
     775,   764,   776,   788,   789,   427,   427,   774,   455,   427,
     427,   786,   757,   783,   427,    25,   935,   427,  1052,   751,
     751,   427,   935,   427,   454,   768,   624,   363,   450,   467,
     510,   550,   579,   588,   792,   624,   363,   450,   467,   510,
     550,   579,   588,   800,    25,    25,   813,   814,   815,   816,
     935,    25,   771,   772,    25,    25,   618,   388,   674,  1109,
     455,   423,    25,    25,   757,   768,   757,    25,    25,   756,
     771,    25,    25,   618,    56,   780,  1228,   388,   427,  1218,
    1494,  1495,  1496,  1497,  1498,   897,  1085,  1046,   618,    25,
     793,   794,   427,   795,   800,   801,   795,   427,   796,     5,
     388,     5,   388,     5,   280,     5,   805,   423,     5,     5,
     388,   388,   757,   787,  1108,   618,    25,   255,     5,   388,
       5,   388,   280,   423,     5,   388,   388,   787,   935,  1114,
    1115,  1117,  1063,  1114,   358,  1495,  1203,    43,    52,    64,
      65,    67,    81,    88,    99,   100,   101,   115,   117,   118,
     119,   122,   125,   127,   129,   130,   136,   139,   141,   142,
     143,   151,   153,   154,   156,   158,   159,   162,   166,   167,
     168,   170,   171,   175,   176,   178,   182,   184,   185,   190,
     194,   197,   199,   201,   203,   205,   206,   208,   209,   210,
     214,   216,   217,   219,   227,   228,   240,   243,   244,   247,
     248,   251,   252,   260,   261,   262,   264,   274,   275,   276,
     278,   282,   283,   287,   295,   303,   304,   305,   311,   312,
     317,   320,   324,   325,   335,   353,   361,   367,   397,   399,
     400,   408,   447,   458,   462,   466,   490,   491,   495,   507,
     513,   514,   515,   516,   520,   524,   531,   532,   543,   545,
     556,   558,   561,   567,   593,   596,   602,   605,   606,   620,
     627,   650,   651,   652,   653,   654,   655,   656,   659,   661,
     663,   667,   668,   669,   670,   687,   709,   723,   724,   730,
     731,   750,   818,   819,   820,   821,   832,   833,   834,   835,
     887,   891,   921,   943,   944,   947,   948,   949,   950,   963,
     971,   998,   999,  1001,  1005,  1022,  1023,  1027,  1028,  1029,
    1030,  1038,  1053,  1066,  1077,  1078,  1079,  1090,  1093,  1130,
    1133,  1135,  1141,  1142,  1145,  1148,  1151,  1153,  1155,  1157,
    1164,  1169,  1173,  1174,  1175,  1187,  1188,  1191,  1197,  1198,
    1199,  1224,  1239,  1240,  1241,  1242,  1243,  1248,  1254,  1255,
    1273,  1276,  1305,  1307,  1396,  1397,  1428,  1429,  1436,  1447,
    1474,  1478,  1483,  1485,  1487,  1491,  1492,  1499,   724,  1041,
    1474,   623,   646,  1086,  1087,  1114,    20,   388,   422,   769,
     792,    25,   797,    25,    25,    25,   814,   816,   808,   772,
      25,   423,    20,   769,   427,    25,    25,   766,    25,   618,
     388,     5,  1114,   388,   935,   346,   936,   937,  1493,   935,
     935,  1171,   930,   936,   930,    24,   187,   935,  1106,  1469,
    1470,  1471,   935,  1489,   935,  1250,  1251,   935,    25,   671,
    1097,  1246,   930,  1171,   861,    25,   941,  1211,  1212,  1211,
      17,    18,    24,    25,    57,    62,    69,    97,   189,   286,
     291,   319,   354,   366,   384,   389,   392,   403,   409,   419,
     424,   427,   430,   439,   440,   481,   485,   493,   504,   510,
     535,   579,   586,   588,   598,   599,   600,   607,   836,   843,
     844,   845,   846,   847,   848,   849,   850,   862,   867,   878,
     879,   880,   881,   935,   941,  1097,  1206,  1275,  1387,   936,
    1437,  1437,   822,  1171,   930,  1244,  1097,   932,   936,   843,
    1437,  1097,  1171,  1097,  1274,  1437,    24,   583,  1080,  1081,
    1097,   930,   930,  1080,   931,   936,   935,  1081,   930,  1437,
     930,   932,  1097,  1128,  1129,   928,   936,   932,   371,   559,
     665,   927,   935,  1000,   935,   732,   933,   936,    24,  1306,
    1469,  1094,   861,   936,  1154,   892,   126,   135,   144,   149,
     192,   200,   256,   281,   288,   290,   300,   326,   334,   371,
     397,   435,   446,   546,   547,   548,   559,   663,  1014,  1149,
    1150,  1097,   842,   843,  1163,   838,   861,   927,  1484,  1484,
     929,   936,   861,    24,  1097,  1152,  1225,  1097,  1202,    24,
    1097,  1431,   843,  1193,  1194,  1195,  1204,  1205,   843,  1479,
     102,   152,   189,   286,   362,   403,   471,   535,   688,   867,
     935,  1097,  1234,   711,   843,   928,  1476,  1067,   843,   928,
     843,  1097,  1024,   928,   843,  1448,   843,  1211,   935,   945,
     946,   932,   945,  1484,   932,   945,  1484,   951,   945,    24,
      25,   381,   484,   941,  1003,  1097,  1116,  1118,    63,   271,
     341,   386,   566,   647,   648,   649,   658,   678,   953,   955,
     957,   959,   961,  1091,  1092,  1096,   332,   343,   395,   410,
     500,  1308,   638,   639,   899,   900,   901,   935,  1088,   645,
    1087,   388,   299,   388,   388,   388,   388,   622,     5,   388,
     299,   757,   777,   778,   388,   388,   622,   388,   935,  1229,
    1117,   388,  1219,    54,    55,    82,    83,    84,   451,   539,
     582,  1256,  1257,  1258,  1261,  1264,  1267,  1268,  1269,  1270,
     427,   618,  1471,  1107,   615,  1146,   618,     8,   536,   585,
       5,   388,   423,    24,   935,  1380,   476,  1172,  1116,   106,
     107,   108,   836,   836,   427,   523,  1223,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   836,   363,   450,   467,
     510,   550,   579,   588,  1390,  1391,   427,   427,   427,   836,
     836,   427,   427,   748,   836,   427,   851,   427,   427,   427,
     427,   427,   427,   427,   836,   427,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    90,    91,    92,    93,    94,    95,   106,   107,
     108,   246,   249,   368,   383,   387,   425,   453,   472,   554,
     621,   747,   837,   852,   854,   855,   856,   857,   858,   859,
     860,    25,   941,   427,   518,   417,  1097,  1123,  1380,   677,
     678,   825,   263,    85,    86,   624,   456,     5,   617,   624,
     616,   616,  1131,   593,   417,     5,   554,   972,   456,   657,
    1481,   427,   455,   618,   657,   381,   734,  1097,   544,   616,
    1136,  1137,  1138,   323,  1304,   842,   841,   843,     8,   929,
      25,   498,   552,   922,  1097,   922,   922,   922,  1019,  1020,
     922,   922,   594,  1015,   678,  1015,  1015,   923,   923,  1015,
    1015,   678,     5,   330,   382,     5,   677,   480,   839,   840,
     843,     5,    74,    80,   537,   625,  1006,   660,  1482,   842,
     611,   612,   613,   614,  1201,  1203,   380,  1238,  1203,  1195,
       5,   616,  1196,   843,   427,   427,   427,   427,    24,   707,
     935,   427,  1431,   341,   427,   518,   587,   576,   712,   719,
     710,    24,  1082,  1097,  1189,     8,  1192,    13,   935,  1102,
    1110,  1111,  1113,  1121,  1122,  1165,   160,   341,   542,   575,
      32,   187,   551,  1449,  1450,  1451,  1452,   573,     5,   657,
     657,   841,  1116,  1123,  1002,   417,     5,   148,   976,   427,
    1097,   841,   427,    25,    25,    63,  1095,    24,  1097,  1435,
    1435,   929,  1154,   929,   116,   218,   226,   232,   234,   245,
     273,   289,   294,   306,   313,   468,   475,   497,   502,  1277,
    1278,  1286,  1295,  1296,  1302,  1303,  1309,  1310,  1319,  1338,
    1342,  1407,  1408,  1438,  1439,  1442,  1443,  1453,   902,   903,
      89,   898,   909,   910,   901,  1089,  1494,  1047,   455,   805,
     772,   455,     5,   388,   779,   751,  1064,   751,   155,   293,
     369,   427,   473,   489,  1325,  1337,   427,   935,  1272,    25,
     242,   255,   427,   473,   489,   935,  1253,  1266,  1323,  1324,
    1329,  1331,  1333,   427,   935,  1263,   427,  1253,  1259,     5,
      24,   938,  1100,  1471,  1469,   574,   615,  1147,    20,   935,
    1127,  1472,   935,  1490,  1251,   593,   618,   587,   427,   427,
     825,   886,   927,   836,   927,   927,   886,  1484,   468,  1411,
     836,    24,    25,    18,    23,    24,    25,   882,   883,   884,
     885,   836,   427,   624,   927,    20,   836,   388,  1411,   836,
      20,  1206,   870,   868,   874,   836,   872,   836,   836,   836,
     836,   836,   836,   836,   836,   836,   836,   836,   836,   836,
     836,   836,   836,   836,   836,   836,   836,   836,   427,   836,
     836,   427,   863,   935,  1097,   624,   427,  1469,    24,   940,
    1170,  1170,  1431,  1080,   843,   843,   843,   924,   925,   427,
    1097,  1129,   786,   973,   974,   624,  1431,  1484,  1482,   935,
     674,    20,   665,   935,  1000,  1097,   733,   623,   843,   347,
    1140,   554,  1139,     5,    66,    68,    70,   616,   624,   817,
    1116,   893,    17,    18,    24,   301,   307,   308,   309,   327,
     435,   438,   462,   482,   517,   537,   538,   548,   553,   592,
     625,  1021,  1016,  1150,   923,   843,   341,   593,     5,   927,
      25,    25,   677,   150,  1200,   215,  1205,  1211,  1480,   935,
      24,   886,  1484,   587,   927,   621,  1097,   692,   935,   935,
     843,   336,   715,   719,   576,   713,   721,    22,   231,  1069,
    1073,   479,   861,   479,  1190,   843,   454,  1107,   618,     5,
    1025,   544,  1166,  1097,  1470,  1473,  1097,  1119,  1120,   186,
    1450,   964,   946,  1484,  1484,   956,   957,   976,   976,    33,
      34,    35,    36,   267,   270,   272,   292,   302,   344,   348,
     426,   478,   662,   975,   977,   978,  1010,  1097,  1118,   544,
     679,    25,   396,   962,   318,  1430,  1430,   133,   134,   433,
     544,   935,  1339,  1340,  1381,   786,  1380,  1380,  1279,   786,
     935,  1440,  1440,   356,   473,   583,  1419,  1380,  1287,   165,
     435,   446,   468,   475,  1312,  1313,  1314,   284,   285,  1402,
    1494,  1494,   381,   911,  1097,   640,   641,   904,   905,   906,
     478,   623,   642,   643,   662,   914,   915,  1494,   751,    25,
     770,   770,   778,  1230,   751,  1220,  1327,  1380,  1271,  1337,
     427,  1271,   427,   427,  1265,  1266,   427,   427,    61,   296,
     354,   366,   376,   394,   404,   407,   420,   469,   499,   509,
     530,   533,   535,   563,   572,  1372,  1373,  1374,  1376,  1262,
    1263,  1259,  1260,   662,  1257,   388,   618,  1431,   574,   455,
     544,  1488,   672,   673,   935,   935,   935,  1247,   861,     5,
     388,   388,   388,   388,   388,  1419,   388,   388,   388,   388,
     587,   883,    18,    25,   587,   388,   388,    25,  1391,   388,
     388,   388,   388,     5,   749,   388,   836,   836,   836,   388,
     836,   388,   388,   388,   438,   438,   438,   861,  1411,   438,
     861,  1411,   704,   705,   706,   836,   427,   935,  1245,   615,
    1143,   624,     5,     5,     5,   577,   843,   618,     5,   480,
     624,   388,   423,   427,   623,   161,   164,   267,   270,   735,
     738,   739,  1010,   736,   737,   935,   427,   936,   647,   648,
    1144,   843,   935,   935,   925,   926,   506,  1484,   825,   551,
    1292,    25,    25,   427,  1017,  1019,  1097,   533,  1158,   839,
      63,   836,  1203,    25,  1097,  1494,     5,     5,   388,   388,
     708,   935,   388,  1431,   704,   427,   427,   720,   716,   357,
     714,   843,   336,   717,   721,   594,  1012,  1074,  1070,   359,
    1068,  1069,   841,   624,  1103,    20,   935,  1112,  1122,    13,
      17,    18,    20,    24,    25,    62,   392,   407,   424,   427,
     440,   480,   481,   493,   535,   574,   586,   598,   599,   607,
     610,   935,   941,  1167,  1168,  1386,  1388,  1418,  1423,  1424,
    1425,  1473,   417,   417,     5,  1494,   958,   959,   548,   934,
     544,   989,   988,   991,   990,   927,   996,   927,   997,   985,
     984,   982,   981,  1011,   435,   446,   992,   993,   435,   446,
     994,   995,   321,   978,   983,  1484,    37,    38,    39,    40,
      41,    42,    96,   329,   342,   406,   413,   452,   477,   487,
     488,   493,   503,   525,   528,   529,   534,   591,   603,   680,
     681,  1008,  1009,     5,    25,  1431,   245,  1097,   468,  1412,
    1413,  1431,  1154,  1406,  1408,    98,    98,   593,  1152,  1341,
    1342,   427,  1320,   147,   523,  1346,  1353,  1380,   172,   268,
    1444,   618,   624,  1409,  1454,   338,   347,   371,   374,   392,
     498,   552,   559,   929,  1289,  1294,   427,  1315,   623,     5,
      24,   935,  1403,  1404,   913,  1097,     5,   544,   907,   908,
     637,   906,   912,   935,   912,   916,   917,   912,   321,   915,
    1048,   423,   423,   457,  1213,  1233,  1065,   457,  1176,  1207,
     427,     5,   388,   291,   427,   439,   600,  1356,  1357,  1358,
    1359,  1360,  1364,  1368,  1370,  1423,   388,   610,   935,  1326,
    1328,  1380,  1383,  1384,  1330,  1383,     5,   388,  1330,  1356,
     363,   450,   467,   510,   550,   579,   588,  1393,  1393,   427,
     427,   427,   427,   427,   427,   204,   396,  1332,  1334,     5,
     388,     5,   388,   935,  1472,     8,  1431,  1108,   843,     5,
    1252,  1253,   861,  1054,   927,  1420,  1421,  1423,   876,  1391,
     876,    25,    25,   587,    23,    25,   789,   877,  1223,   388,
    1223,   790,   388,  1223,   871,   869,   875,  1223,   873,  1223,
    1223,  1223,    24,    24,    24,   836,   853,   388,    24,   853,
     388,   864,     5,   865,   618,  1252,   574,  1431,  1431,   843,
     843,   924,   506,   843,  1486,     5,    20,  1383,   974,  1431,
     618,   935,   736,   744,   743,   745,   935,   939,   746,   939,
     188,   739,   742,     5,   976,   618,   843,     8,   935,  1293,
     894,  1018,  1019,  1097,     5,   322,    24,  1235,   341,   341,
     455,   618,   341,   427,   693,   697,   690,  1494,  1494,   722,
     718,   714,  1013,    24,   934,  1075,  1097,  1494,   843,   422,
     455,   861,  1424,  1424,  1389,  1393,   468,  1423,   427,   427,
     427,   427,   427,   427,   427,   935,   427,     5,    17,    18,
      19,    20,    90,    91,    92,    93,    94,    95,  1445,  1470,
    1097,  1120,    60,   540,   965,   960,   961,    25,   677,   935,
    1494,  1494,  1494,  1494,     5,   979,     5,   980,  1494,  1494,
    1494,  1494,  1017,     5,   987,     5,   986,  1494,   934,    24,
      13,    13,     5,   388,    25,  1380,  1419,  1400,   593,   593,
    1278,  1405,  1406,  1342,  1321,  1383,   615,   929,  1356,   427,
    1282,   935,  1441,  1440,  1420,    46,    47,    48,    49,    50,
     581,  1457,   843,   843,  1288,   929,  1316,  1383,  1380,  1314,
     618,   618,     5,     5,  1097,   912,  1494,  1494,     5,   919,
     920,  1494,  1494,   918,  1041,   809,   767,    71,    72,    75,
      76,    77,   174,   181,   215,   224,   253,   254,   298,   340,
     396,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,  1210,  1214,   132,   511,  1215,  1231,  1041,   157,   173,
     174,   181,   215,   224,   253,   298,   340,  1208,  1209,  1221,
    1215,  1328,  1337,   427,  1418,  1356,  1423,  1418,  1359,     6,
     388,     7,     9,    11,    12,    13,    14,    15,    16,   249,
     368,   425,   554,   600,   621,  1367,  1369,  1384,   455,  1382,
     388,     5,   618,     5,   388,  1266,   388,   388,   624,   427,
     624,    25,  1378,  1378,    25,  1378,  1378,    25,  1377,    24,
    1386,  1335,  1336,  1337,  1263,  1259,  1431,     8,   423,   673,
       5,   388,   841,   388,     5,   544,  1347,  1352,   277,   317,
     318,   319,   342,   350,   355,   370,   375,   377,   384,   387,
     390,   393,   396,   401,   419,   435,   438,   439,   445,   456,
     472,   479,   486,   489,   490,   491,   493,   494,   510,   534,
     535,   536,   537,   539,   556,   557,   579,   588,   589,   591,
     653,   942,  1493,   624,   388,    25,   587,   624,   388,   388,
     388,   388,     5,   388,   388,   388,   706,   704,    20,   388,
    1431,     5,   843,   564,   271,   682,   683,   843,    20,   935,
     388,   976,  1494,  1494,     5,   740,   455,   618,     5,   741,
    1494,   737,   544,    20,   935,     5,   935,  1134,   386,   657,
    1119,  1494,     5,   388,   934,   836,     5,   704,  1097,   689,
     671,   935,  1097,   695,   388,   704,   704,  1494,  1494,  1017,
    1072,    24,  1076,  1097,   569,   890,  1108,   480,   842,  1026,
     624,  1419,   388,   392,  1383,  1446,   356,   473,   583,  1371,
    1423,  1426,  1371,  1371,  1371,  1371,   618,  1426,  1168,  1423,
    1423,  1423,  1423,   967,   966,   437,   952,   953,   618,   927,
    1494,   927,  1494,   993,  1494,   995,  1494,   677,    25,  1097,
      25,  1097,   681,   388,   427,  1432,  1420,  1402,  1406,  1406,
    1398,     5,   388,   468,  1417,  1283,  1383,   476,  1280,  1417,
     624,  1410,    17,    18,    62,   424,   427,   440,   480,   481,
     493,   535,   574,   586,   598,   599,   607,   610,   935,  1386,
    1418,  1462,  1463,  1464,  1465,  1466,  1467,  1473,  1462,  1462,
    1462,  1383,  1459,  1461,  1458,  1459,  1460,  1455,   551,  1290,
       5,   388,   624,   935,   935,  1404,  1097,   935,  1494,  1494,
    1494,  1494,   622,   622,  1211,  1211,  1211,    24,  1211,  1211,
    1211,  1211,  1211,  1211,    24,    24,  1211,  1214,  1097,  1124,
    1125,   617,   443,  1177,  1494,    24,    24,    25,    25,    25,
      25,    25,    24,  1097,  1209,  1177,   388,   388,  1357,  1358,
     935,  1362,  1386,  1427,   427,  1418,  1362,   427,  1418,     9,
     246,   383,   385,  1423,    25,  1325,  1383,    20,   935,  1383,
     363,   450,   467,   510,   550,   579,   588,  1394,    25,  1394,
       5,  1375,  1375,     5,   388,   388,  1375,   388,  1337,  1431,
    1253,   265,  1249,  1421,   512,  1348,  1349,  1350,  1380,  1353,
     328,   511,   522,  1297,  1414,   363,   450,   467,   510,   550,
     579,   588,  1392,   876,   587,    23,    25,   793,   836,   866,
     465,   824,     5,   370,  1431,     5,   427,   388,   548,  1007,
     939,  1494,   674,    20,   935,   939,  1494,  1484,   843,  1484,
     237,  1019,   677,    24,  1236,  1116,   423,   704,   694,   698,
     388,  1494,   934,   843,   888,   423,  1394,  1420,     5,  1393,
       5,   388,  1423,     5,   388,  1423,  1423,  1423,  1423,   935,
     388,   843,  1494,   954,   955,    20,   935,  1433,  1434,   551,
    1416,  1401,  1399,  1402,  1383,  1419,   137,  1322,     5,   388,
    1281,  1441,  1416,  1465,  1465,  1464,   427,   427,   427,   427,
     427,   427,   427,   935,   427,     5,   388,    17,    18,    19,
      20,  1445,   388,     5,   388,     5,    13,   147,   523,  1456,
    1291,  1383,   459,  1317,  1318,  1381,   618,   207,  1049,   805,
     779,   536,   585,  1126,     5,  1124,    59,   131,   196,   198,
     213,   221,   225,   250,  1178,  1179,  1232,  1049,  1222,   438,
    1361,  1365,  1366,  1386,  1473,  1361,  1365,  1362,  1423,     5,
     423,  1382,   388,    25,  1379,   388,   388,    25,   388,   427,
    1350,     5,   935,  1385,   365,  1344,  1354,   935,  1415,   617,
    1371,   328,   427,    23,    25,   388,   927,   677,   370,  1431,
     843,   684,   566,  1132,    25,   677,   423,  1007,   388,  1156,
     388,   388,   427,   696,   341,   702,   388,   691,  1071,  1494,
    1352,  1393,   624,  1393,   388,  1423,   388,   388,   388,   388,
     573,   934,     5,   388,  1119,  1352,  1402,  1402,  1420,  1383,
     427,  1352,   388,  1446,  1371,  1464,  1468,  1371,  1371,  1371,
    1371,   618,  1468,  1463,  1464,  1464,  1464,  1464,  1459,    13,
    1460,  1463,   929,  1356,  1119,     5,   138,  1311,   935,  1125,
    1180,  1181,  1097,  1183,  1097,  1182,  1184,  1179,   236,   236,
    1363,  1427,     5,   388,   388,  1361,     7,    25,   624,   388,
    1349,  1351,  1349,  1345,  1422,  1423,   444,  1343,  1355,  1249,
      25,  1298,  1299,  1300,  1383,  1412,  1415,    25,   823,  1431,
     389,   200,   256,   281,   290,   326,   334,   428,   601,   681,
     685,   686,   427,   618,   677,  1010,  1159,  1160,  1161,  1237,
     699,   388,  1116,   702,   702,  1494,   889,   388,   624,  1394,
     624,   968,  1004,  1434,  1414,  1352,   480,  1284,  1285,  1423,
    1414,   388,  1464,     5,   388,  1464,  1464,  1464,  1464,   935,
     388,   427,  1318,  1494,  1494,  1185,  1494,  1186,  1494,  1494,
    1366,  1423,   423,  1394,     5,   388,     5,  1356,     5,   536,
     585,  1301,  1249,   388,   344,   348,   826,   827,   828,  1010,
     922,   922,   922,   922,   922,   922,    24,     5,   388,   843,
      20,   935,  1162,   279,  1161,   702,   704,   702,   238,  1394,
    1394,  1494,   677,     5,   388,   388,  1464,   388,   388,   388,
     388,  1462,  1494,  1494,  1349,  1422,  1299,   830,   829,   235,
     828,   831,   686,     5,  1494,   700,   965,  1285,   388,  1494,
    1494,  1494,   843,   388,   388,   701,   160,   341,   703,  1116
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
#line 917 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 920 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 924 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 930 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 935 "fgl.yacc"
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
#line 947 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 952 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,
		"unregister_func(\"%s\",%s%s);\n",
			yyvsp[0].str,
			(char *)get_namespace(yyvsp[0].str),
			yyvsp[0].str
	);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 975 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 976 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 977 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 978 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 979 "fgl.yacc"
    {
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    a4gl_yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 16:
#line 993 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 994 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 995 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 996 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 997 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1002 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1003 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1014 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1017 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1020 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1020 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1027 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1028 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1034 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1035 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1036 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1037 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1038 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1039 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1040 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1041 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1042 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1043 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1044 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1045 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1046 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1047 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1049 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1057 "fgl.yacc"
    {
A4GL_debug("win_attributes_def");
start_state("attribute",1);
A4GL_debug("Started states");
form_attrib.attrib=0;}
    break;

  case 50:
#line 1061 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1065 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1066 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1070 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1076 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1078 "fgl.yacc"
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

  case 56:
#line 1089 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1091 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1093 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1095 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1099 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1101 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1162 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1166 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1170 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1173 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 66:
#line 1181 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1186 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1190 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 70:
#line 1193 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1199 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
 A4GL_debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 72:
#line 1208 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1212 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1217 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1221 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1229 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1233 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1237 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1239 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1245 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1250 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1253 "fgl.yacc"
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

  case 83:
#line 1269 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1276 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1280 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1284 "fgl.yacc"
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

  case 87:
#line 1306 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1306 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1310 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1311 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1312 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1317 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1320 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1326 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1329 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1341 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1347 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1350 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1365 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1375 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1381 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1390 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1403 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1406 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1408 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1414 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1416 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1421 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1426 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1432 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1436 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1451 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1454 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1457 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1460 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1463 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1466 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1488 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1497 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1507 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1521 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1525 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1528 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1536 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0])"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1542 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0])"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1557 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1561 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1566 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1576 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1579 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1583 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1585 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1588 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1590 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1593 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1595 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1598 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1601 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1611 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1612 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1620 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1621 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1638 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1641 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1644 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1647 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1650 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1653 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1662 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1670 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1675 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1688 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1692 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1707 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1708 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1716 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1716 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1726 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1726 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1735 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1736 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1737 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1740 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1745 "fgl.yacc"
    { }
    break;

  case 194:
#line 1745 "fgl.yacc"
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
#line 1762 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1766 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1780 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1789 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1793 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1809 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1811 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1812 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1819 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1819 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1820 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1821 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1824 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1826 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1836 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1851 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1851 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1857 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1858 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1865 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1866 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1867 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1868 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1871 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1872 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1873 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1874 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1878 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1883 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1888 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1892 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1895 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1899 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1900 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1901 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1902 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1903 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1904 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1905 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1906 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1909 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1910 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1911 "fgl.yacc"
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

  case 260:
#line 1943 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1947 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1949 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1951 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1953 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1958 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1962 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1962 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1966 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1967 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1968 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1969 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1970 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1971 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1973 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 1978 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 1978 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 1981 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 1983 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 1989 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 1991 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 1997 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2005 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2005 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2008 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2009 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2010 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2011 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2012 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2013 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2015 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2036 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2045 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2047 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2049 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2051 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2052 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2053 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2054 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2055 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2060 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2067 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2072 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2074 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2076 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2077 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2078 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2079 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2080 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2081 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2082 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2085 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2087 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2093 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2101 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2109 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2113 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2121 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2122 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2123 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2124 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2143 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2155 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2159 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2162 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2165 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2166 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2167 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2168 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2169 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2175 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2182 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2187 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2192 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2196 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2199 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2207 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2209 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2214 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2226 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2229 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2232 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2235 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2238 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2241 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2254 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2257 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2272 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2274 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2276 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2278 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2280 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2282 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2283 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2290 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2292 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2296 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2298 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2300 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2302 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2304 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2306 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2308 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2314 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2328 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2331 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2348 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2354 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2358 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2363 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2373 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 402:
#line 2384 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 403:
#line 2384 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 405:
#line 2389 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null()");}
    break;

  case 406:
#line 2393 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2399 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2407 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2413 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2422 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 411:
#line 2424 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 412:
#line 2431 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 413:
#line 2439 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 414:
#line 2443 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 415:
#line 2452 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 416:
#line 2457 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 417:
#line 2462 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 418:
#line 2466 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 419:
#line 2468 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_EXISTS);");
}
    break;

  case 420:
#line 2478 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTEXISTS);");
}
    break;

  case 421:
#line 2492 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 422:
#line 2500 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2512 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2518 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2524 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 428:
#line 2534 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 429:
#line 2540 "fgl.yacc"
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

  case 430:
#line 2612 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2618 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2622 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 433:
#line 2630 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 434:
#line 2630 "fgl.yacc"
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

  case 435:
#line 2646 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 436:
#line 2650 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 437:
#line 2656 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 438:
#line 2659 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 439:
#line 2667 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN_SELECT);");
}
    break;

  case 440:
#line 2678 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN_SELECT);");
}
    break;

  case 441:
#line 2688 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 442:
#line 2694 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 443:
#line 2704 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 444:
#line 2709 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2716 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 446:
#line 2719 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 447:
#line 2722 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 448:
#line 2727 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 449:
#line 2734 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 450:
#line 2739 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2744 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 452:
#line 2749 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2760 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 454:
#line 2768 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 455:
#line 2776 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 456:
#line 2781 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 457:
#line 2785 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 458:
#line 2790 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 459:
#line 2794 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 460:
#line 2798 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 461:
#line 2804 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 462:
#line 2807 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2811 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 464:
#line 2815 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 465:
#line 2819 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 466:
#line 2823 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 467:
#line 2827 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 468:
#line 2834 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 469:
#line 2844 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 470:
#line 2849 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 471:
#line 2855 "fgl.yacc"
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

  case 472:
#line 2865 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 473:
#line 2870 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 474:
#line 2873 "fgl.yacc"
    {
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");A4GL_pop_args(_retvars);A4GL_push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;

  case 475:
#line 2887 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 476:
#line 2887 "fgl.yacc"
    {chk4var=0;}
    break;

  case 477:
#line 2887 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 478:
#line 2890 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 479:
#line 2890 "fgl.yacc"
    {chk4var=0;}
    break;

  case 480:
#line 2890 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 481:
#line 2893 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 482:
#line 2893 "fgl.yacc"
    {chk4var=0;}
    break;

  case 483:
#line 2893 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 484:
#line 2896 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 485:
#line 2896 "fgl.yacc"
    {chk4var=0;}
    break;

  case 486:
#line 2896 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 487:
#line 2899 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 488:
#line 2905 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2911 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2917 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2927 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 492:
#line 2928 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 495:
#line 2936 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);

}
    break;

  case 496:
#line 2942 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 497:
#line 2943 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 498:
#line 2948 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 499:
#line 2952 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_inp_io,sizeof(_inp_io),%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 500:
#line 2961 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_inp_io,sizeof(_inp_io),%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 503:
#line 2973 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 504:
#line 2978 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 505:
#line 2985 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 506:
#line 2989 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 507:
#line 2992 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 508:
#line 2995 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 509:
#line 3001 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 510:
#line 3004 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3007 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3022 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 513:
#line 3025 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3031 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 515:
#line 3032 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 516:
#line 3033 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 518:
#line 3038 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 519:
#line 3039 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 520:
#line 3040 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3041 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3043 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3044 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3045 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3047 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3048 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 528:
#line 3054 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 530:
#line 3059 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 531:
#line 3071 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 532:
#line 3075 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 533:
#line 3076 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 534:
#line 3083 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 536:
#line 3100 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 537:
#line 3104 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 538:
#line 3109 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 539:
#line 3113 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 540:
#line 3129 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 541:
#line 3135 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 542:
#line 3143 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 549:
#line 3160 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 550:
#line 3162 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 551:
#line 3165 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 552:
#line 3167 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 557:
#line 3181 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 558:
#line 3183 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 559:
#line 3186 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 560:
#line 3188 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 573:
#line 3219 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 574:
#line 3221 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 575:
#line 3224 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 576:
#line 3226 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 577:
#line 3229 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 578:
#line 3231 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 579:
#line 3234 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 580:
#line 3236 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 581:
#line 3239 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 582:
#line 3241 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 583:
#line 3256 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 584:
#line 3272 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 585:
#line 3273 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 586:
#line 3274 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 587:
#line 3275 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 588:
#line 3276 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 589:
#line 3277 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 593:
#line 3285 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 595:
#line 3291 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 596:
#line 3293 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 597:
#line 3294 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 598:
#line 3296 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 599:
#line 3298 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 600:
#line 3300 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 601:
#line 3302 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 602:
#line 3304 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 603:
#line 3307 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 604:
#line 3314 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 605:
#line 3316 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 606:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 607:
#line 3327 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 608:
#line 3332 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3337 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 610:
#line 3337 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 611:
#line 3340 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 612:
#line 3346 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[0].str) ;
			}
    break;

  case 613:
#line 3351 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 614:
#line 3355 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 617:
#line 3363 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 618:
#line 3365 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 619:
#line 3367 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 620:
#line 3369 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 621:
#line 3371 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 622:
#line 3373 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 623:
#line 3376 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 625:
#line 3385 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 669:
#line 3446 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 670:
#line 3460 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 672:
#line 3467 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 673:
#line 3470 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 674:
#line 3476 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 675:
#line 3482 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 676:
#line 3486 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 677:
#line 3490 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 678:
#line 3496 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 679:
#line 3500 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 680:
#line 3504 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 681:
#line 3509 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 682:
#line 3514 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 701:
#line 3555 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 702:
#line 3560 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 704:
#line 3565 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 706:
#line 3568 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 707:
#line 3570 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 708:
#line 3573 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 709:
#line 3577 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 710:
#line 3580 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 711:
#line 3586 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 712:
#line 3597 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 713:
#line 3598 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 714:
#line 3601 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 716:
#line 3607 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 717:
#line 3611 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 718:
#line 3612 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 721:
#line 3626 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 722:
#line 3628 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 725:
#line 3637 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 726:
#line 3639 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 727:
#line 3643 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 728:
#line 3645 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 729:
#line 3648 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 730:
#line 3650 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3653 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 732:
#line 3656 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 733:
#line 3659 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 734:
#line 3661 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 735:
#line 3664 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 736:
#line 3666 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 737:
#line 3669 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 738:
#line 3671 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 739:
#line 3674 "fgl.yacc"
    {A4GL_lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 740:
#line 3676 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 741:
#line 3679 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 742:
#line 3681 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 743:
#line 3684 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_DELETE");
	}
    break;

  case 744:
#line 3686 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 745:
#line 3687 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INSERT");
	}
    break;

  case 746:
#line 3689 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 747:
#line 3690 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_DELETE");
	}
    break;

  case 748:
#line 3692 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 749:
#line 3693 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INSERT");
	}
    break;

  case 750:
#line 3695 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 751:
#line 3701 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 752:
#line 3702 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 753:
#line 3710 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 754:
#line 3711 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 755:
#line 3716 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 756:
#line 3717 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		A4GL_generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 757:
#line 3726 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 758:
#line 3727 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 759:
#line 3734 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 760:
#line 3735 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 761:
#line 3743 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 762:
#line 3744 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 763:
#line 3753 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 764:
#line 3758 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 765:
#line 3763 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 766:
#line 3764 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 768:
#line 3769 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 769:
#line 3772 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 770:
#line 3780 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 771:
#line 3785 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 772:
#line 3789 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 773:
#line 3791 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 774:
#line 3800 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 775:
#line 3805 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 776:
#line 3806 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 777:
#line 3807 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 778:
#line 3808 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 779:
#line 3811 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 791:
#line 3832 "fgl.yacc"
    {iskey=1;}
    break;

  case 792:
#line 3832 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 793:
#line 3834 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 794:
#line 3837 "fgl.yacc"
    {iskey=1;}
    break;

  case 795:
#line 3837 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 796:
#line 3839 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 797:
#line 3843 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 798:
#line 3843 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 799:
#line 3846 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 800:
#line 3847 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 802:
#line 3850 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 803:
#line 3855 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 804:
#line 3855 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 809:
#line 3862 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 810:
#line 3863 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 811:
#line 3864 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 812:
#line 3865 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 813:
#line 3866 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 814:
#line 3867 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 815:
#line 3868 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 816:
#line 3869 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 817:
#line 3870 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 818:
#line 3871 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 819:
#line 3872 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 820:
#line 3873 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 821:
#line 3874 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 822:
#line 3878 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 823:
#line 3896 "fgl.yacc"
    {chk4var=1;}
    break;

  case 824:
#line 3896 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 825:
#line 3899 "fgl.yacc"
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
	}

}
    break;

  case 826:
#line 3922 "fgl.yacc"
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

  case 828:
#line 3940 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 829:
#line 3946 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 830:
#line 3952 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 831:
#line 3958 "fgl.yacc"
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

  case 832:
#line 3969 "fgl.yacc"
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

  case 833:
#line 3992 "fgl.yacc"
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

  case 836:
#line 4008 "fgl.yacc"
    {
	}
    break;

  case 843:
#line 4031 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 847:
#line 4039 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 865:
#line 4065 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 866:
#line 4066 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 867:
#line 4074 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 868:
#line 4079 "fgl.yacc"
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

  case 869:
#line 4095 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 870:
#line 4101 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 872:
#line 4116 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 873:
#line 4129 "fgl.yacc"
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

  case 874:
#line 4139 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 875:
#line 4146 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 876:
#line 4153 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 877:
#line 4159 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 878:
#line 4159 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 879:
#line 4164 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 880:
#line 4169 "fgl.yacc"
    {
}
    break;

  case 886:
#line 4181 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 888:
#line 4189 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 889:
#line 4195 "fgl.yacc"
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

  case 890:
#line 4209 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 891:
#line 4213 "fgl.yacc"
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

  case 892:
#line 4226 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 894:
#line 4244 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 895:
#line 4251 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 896:
#line 4257 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 897:
#line 4268 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 898:
#line 4272 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 899:
#line 4279 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 900:
#line 4286 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 901:
#line 4292 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 902:
#line 4297 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 905:
#line 4304 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 906:
#line 4305 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 907:
#line 4307 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 908:
#line 4308 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 909:
#line 4311 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 910:
#line 4312 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 911:
#line 4313 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 912:
#line 4315 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 913:
#line 4320 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 914:
#line 4325 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 915:
#line 4332 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 919:
#line 4339 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 920:
#line 4341 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 921:
#line 4343 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 922:
#line 4352 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 923:
#line 4358 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 924:
#line 4362 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 927:
#line 4374 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 928:
#line 4379 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 929:
#line 4384 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 930:
#line 4387 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 931:
#line 4396 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 932:
#line 4399 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 933:
#line 4403 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 934:
#line 4407 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 941:
#line 4424 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 943:
#line 4426 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 944:
#line 4426 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 945:
#line 4429 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 946:
#line 4439 "fgl.yacc"
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
n=scan_variable(buff);

  A4GL_debug("scan variable returns -> %d\n",n);

  if (n == -1&&buff[0]!=' ') {
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           a4gl_yyerror(buff2);
           exit (0);
  }
  if (strstr(buff,".*") && n!=-2) {
		char *ptr;
		printf("WARNING : Using a .* on a non-record - %s\n",yyvsp[0].str);
		ptr=strstr(buff,".*");
		*ptr=0;
		strcpy(yyval.str,buff);
  }
 
  mcnt = 0;
}
    break;

  case 948:
#line 4486 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 950:
#line 4493 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 951:
#line 4498 "fgl.yacc"
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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", buff, (int)scan_variable (buff), yyvsp[-1].str);

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 955:
#line 4544 "fgl.yacc"
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

  case 956:
#line 4558 "fgl.yacc"
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

  case 961:
#line 4582 "fgl.yacc"
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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.1*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.2*/", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
    break;

  case 962:
#line 4641 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char buff2[256];
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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.3*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.4*/", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
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

  case 963:
#line 4696 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 964:
#line 4701 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 965:
#line 4709 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 966:
#line 4714 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 967:
#line 4722 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 968:
#line 4728 "fgl.yacc"
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

  mcnt = 0;
}
    break;

  case 969:
#line 4756 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 970:
#line 4759 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 971:
#line 4761 "fgl.yacc"
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0)", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 976:
#line 4812 "fgl.yacc"
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
        sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0)", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0)", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 977:
#line 4864 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 979:
#line 4871 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 980:
#line 4877 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 981:
#line 4888 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 982:
#line 4895 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 984:
#line 4903 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 985:
#line 4906 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 986:
#line 4907 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 988:
#line 4909 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 989:
#line 4910 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 990:
#line 4913 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 991:
#line 4916 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 992:
#line 4922 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 993:
#line 4925 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 994:
#line 4929 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 995:
#line 4933 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 996:
#line 4940 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 997:
#line 4945 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 998:
#line 4952 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 999:
#line 4955 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 1004:
#line 4968 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  A4GL_lex_printcomment("/*..array_r_varid..*/");

printf("Got array %s %s\n",yyvsp[-3].str,yyvsp[-1].str);
if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
	// Its a variable
	//printf("gvd = true\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
	// Its an sql identifier or similar
	//printf("gvd = false\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
printf("All done - ARRAY (array_r_varid) : %s\n",yyval.str);
}
    break;

  case 1005:
#line 4987 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1006:
#line 4994 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1007:
#line 5001 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1008:
#line 5004 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1009:
#line 5018 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1014:
#line 5035 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1015:
#line 5040 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1016:
#line 5046 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1018:
#line 5053 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1019:
#line 5058 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1020:
#line 5061 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1021:
#line 5062 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1022:
#line 5065 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1023:
#line 5066 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1024:
#line 5069 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1025:
#line 5070 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1026:
#line 5075 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1027:
#line 5082 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1028:
#line 5085 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1029:
#line 5091 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1030:
#line 5093 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5095 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1032:
#line 5097 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1033:
#line 5100 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1034:
#line 5100 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1035:
#line 5101 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1036:
#line 5106 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1037:
#line 5114 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1038:
#line 5115 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5120 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1040:
#line 5122 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1041:
#line 5124 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1045:
#line 5141 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1046:
#line 5144 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1047:
#line 5147 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1048:
#line 5150 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1049:
#line 5154 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1050:
#line 5157 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1051:
#line 5160 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1052:
#line 5164 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1053:
#line 5168 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1054:
#line 5172 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1055:
#line 5175 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1056:
#line 5179 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1057:
#line 5182 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1058:
#line 5183 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1059:
#line 5184 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1060:
#line 5187 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1061:
#line 5190 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1062:
#line 5193 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1063:
#line 5196 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1064:
#line 5199 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1065:
#line 5202 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1066:
#line 5205 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1067:
#line 5222 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1070:
#line 5232 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1071:
#line 5239 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1073:
#line 5260 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1074:
#line 5265 "fgl.yacc"
    {
		if (strcmp(yyvsp[-5].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-4].str);
                pop_blockcommand("PROMPT");
                A4GL_lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1075:
#line 5278 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1076:
#line 5283 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1077:
#line 5284 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1078:
#line 5288 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1082:
#line 5294 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1083:
#line 5296 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1085:
#line 5311 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1086:
#line 5315 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1087:
#line 5321 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1088:
#line 5322 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1089:
#line 5325 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1090:
#line 5326 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1091:
#line 5329 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1093:
#line 5348 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1094:
#line 5353 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1095:
#line 5358 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1096:
#line 5363 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1102:
#line 5385 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1103:
#line 5392 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1104:
#line 5401 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1105:
#line 5407 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1106:
#line 5409 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1110:
#line 5420 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1111:
#line 5421 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1112:
#line 5423 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1113:
#line 5424 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1114:
#line 5426 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1115:
#line 5427 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1116:
#line 5429 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1117:
#line 5430 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1118:
#line 5432 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1119:
#line 5433 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1120:
#line 5434 "fgl.yacc"
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
#line 5448 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1122:
#line 5450 "fgl.yacc"
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
#line 5467 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1130:
#line 5479 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1131:
#line 5479 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1132:
#line 5485 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1133:
#line 5485 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1134:
#line 5488 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1135:
#line 5488 "fgl.yacc"
    {
char buff[256];
strcpy(buff,yyvsp[0].str);
if (buff[0]=='1') {
	print_skip_lines();
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(yyvsp[-2].str);
}
start_state("KWLINE",0); 
}
    break;

  case 1136:
#line 5498 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1137:
#line 5499 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1138:
#line 5500 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1139:
#line 5507 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1140:
#line 5519 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1146:
#line 5530 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1147:
#line 5535 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1148:
#line 5539 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1149:
#line 5544 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1150:
#line 5550 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1151:
#line 5551 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1152:
#line 5552 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1153:
#line 5556 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1154:
#line 5557 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1155:
#line 5558 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1156:
#line 5559 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1157:
#line 5563 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1158:
#line 5573 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1159:
#line 5575 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1160:
#line 5580 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1161:
#line 5583 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1162:
#line 5588 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1163:
#line 5595 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1164:
#line 5602 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1165:
#line 5609 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1166:
#line 5618 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1167:
#line 5625 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1168:
#line 5632 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1169:
#line 5639 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1170:
#line 5646 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1175:
#line 5659 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1176:
#line 5660 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1177:
#line 5661 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1178:
#line 5662 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1179:
#line 5663 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1180:
#line 5664 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1181:
#line 5665 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1182:
#line 5666 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1183:
#line 5667 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1184:
#line 5668 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1187:
#line 5674 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1188:
#line 5675 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1189:
#line 5676 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1190:
#line 5677 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1195:
#line 5686 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1196:
#line 5687 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1197:
#line 5688 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1198:
#line 5689 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1199:
#line 5690 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1200:
#line 5691 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1201:
#line 5692 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1202:
#line 5693 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1203:
#line 5695 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1204:
#line 5696 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1205:
#line 5697 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1206:
#line 5698 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1207:
#line 5700 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1208:
#line 5701 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1209:
#line 5702 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1210:
#line 5703 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1214:
#line 5708 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1215:
#line 5709 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1219:
#line 5716 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1220:
#line 5723 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1221:
#line 5730 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1222:
#line 5741 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1223:
#line 5750 "fgl.yacc"
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

  case 1224:
#line 5761 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1225:
#line 5765 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1226:
#line 5769 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1227:
#line 5775 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1228:
#line 5780 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1229:
#line 5788 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1230:
#line 5791 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1231:
#line 5800 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1232:
#line 5811 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1234:
#line 5818 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1235:
#line 5826 "fgl.yacc"
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

  case 1236:
#line 5836 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1237:
#line 5839 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1238:
#line 5843 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1239:
#line 5851 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1240:
#line 5854 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1241:
#line 5860 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1242:
#line 5864 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1243:
#line 5868 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1244:
#line 5872 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1245:
#line 5876 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1246:
#line 5882 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1247:
#line 5883 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1248:
#line 5884 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1249:
#line 5885 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1250:
#line 5890 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1251:
#line 5892 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1252:
#line 5895 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1253:
#line 5899 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1254:
#line 5902 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1255:
#line 5909 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1256:
#line 5914 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1257:
#line 5915 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1258:
#line 5916 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1259:
#line 5921 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1260:
#line 5922 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1261:
#line 5928 "fgl.yacc"
    {insql=1;}
    break;

  case 1262:
#line 5928 "fgl.yacc"
    {insql=0;}
    break;

  case 1263:
#line 5928 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1264:
#line 5933 "fgl.yacc"
    {insql=1;}
    break;

  case 1265:
#line 5933 "fgl.yacc"
    {insql=0;}
    break;

  case 1266:
#line 5933 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1267:
#line 5944 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1268:
#line 5945 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1269:
#line 5951 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1270:
#line 5953 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1272:
#line 5960 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1273:
#line 5964 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1274:
#line 5965 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1276:
#line 5970 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1277:
#line 5973 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1278:
#line 5979 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1279:
#line 5982 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1280:
#line 5990 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1282:
#line 5997 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1283:
#line 6004 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1284:
#line 6007 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1285:
#line 6016 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1286:
#line 6019 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1287:
#line 6022 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1288:
#line 6025 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1289:
#line 6028 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1290:
#line 6031 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1291:
#line 6034 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1292:
#line 6041 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1293:
#line 6044 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1294:
#line 6051 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6054 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1296:
#line 6060 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1297:
#line 6063 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1298:
#line 6070 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1299:
#line 6073 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1301:
#line 6081 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1303:
#line 6090 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1304:
#line 6093 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1305:
#line 6099 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1306:
#line 6102 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1307:
#line 6108 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1308:
#line 6115 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1309:
#line 6116 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1310:
#line 6120 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1311:
#line 6126 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1312:
#line 6129 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1314:
#line 6137 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1315:
#line 6144 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1316:
#line 6147 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1320:
#line 6165 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1326:
#line 6171 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1327:
#line 6174 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1328:
#line 6177 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1329:
#line 6183 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1331:
#line 6189 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1333:
#line 6200 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1334:
#line 6214 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1335:
#line 6223 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1336:
#line 6223 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1337:
#line 6228 "fgl.yacc"
    {insql=1;}
    break;

  case 1338:
#line 6228 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1339:
#line 6233 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1340:
#line 6236 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1341:
#line 6238 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1343:
#line 6245 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6249 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1345:
#line 6253 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1346:
#line 6260 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1347:
#line 6263 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1348:
#line 6270 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1349:
#line 6274 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1350:
#line 6278 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1351:
#line 6287 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1352:
#line 6291 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1353:
#line 6297 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1354:
#line 6301 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1355:
#line 6307 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1356:
#line 6314 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1357:
#line 6318 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1358:
#line 6323 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1359:
#line 6333 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1360:
#line 6336 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1361:
#line 6338 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1362:
#line 6340 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1363:
#line 6342 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1364:
#line 6344 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1365:
#line 6346 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1366:
#line 6348 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1367:
#line 6354 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1368:
#line 6364 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1369:
#line 6371 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1371:
#line 6377 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6386 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6391 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1379:
#line 6396 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1380:
#line 6403 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1381:
#line 6404 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1382:
#line 6411 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1383:
#line 6422 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1384:
#line 6423 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1385:
#line 6426 "fgl.yacc"
    {insql=1;}
    break;

  case 1386:
#line 6426 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1387:
#line 6431 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1388:
#line 6436 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1390:
#line 6442 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1392:
#line 6446 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1393:
#line 6451 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1394:
#line 6456 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1395:
#line 6460 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1397:
#line 6466 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1398:
#line 6470 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1399:
#line 6478 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6481 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1401:
#line 6483 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1402:
#line 6488 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1405:
#line 6495 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6502 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6505 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1411:
#line 6507 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1413:
#line 6513 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6519 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6529 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1419:
#line 6534 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1420:
#line 6536 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6542 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6545 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1425:
#line 6551 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1426:
#line 6559 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6564 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1430:
#line 6574 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1432:
#line 6580 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1433:
#line 6586 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6588 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 6594 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 6599 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1438:
#line 6602 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1439:
#line 6605 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1440:
#line 6613 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 6615 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1442:
#line 6626 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1443:
#line 6631 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1445:
#line 6635 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1446:
#line 6637 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1447:
#line 6644 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1448:
#line 6647 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1449:
#line 6653 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1450:
#line 6657 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1451:
#line 6661 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1452:
#line 6665 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1453:
#line 6668 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1454:
#line 6676 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1455:
#line 6683 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1458:
#line 6692 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 6698 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1460:
#line 6701 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1461:
#line 6712 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1462:
#line 6719 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1463:
#line 6725 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1464:
#line 6728 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1465:
#line 6735 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1466:
#line 6742 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1468:
#line 6749 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1469:
#line 6755 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1470:
#line 6756 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 6757 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1473:
#line 6761 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1475:
#line 6766 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1476:
#line 6773 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1477:
#line 6778 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1478:
#line 6779 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1479:
#line 6782 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1480:
#line 6785 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1481:
#line 6790 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1482:
#line 6791 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1483:
#line 6796 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1484:
#line 6799 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1485:
#line 6805 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1486:
#line 6808 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1487:
#line 6814 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1488:
#line 6817 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1489:
#line 6823 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1490:
#line 6826 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1491:
#line 6833 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1492:
#line 6834 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1493:
#line 6863 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1494:
#line 6865 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 6879 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1499:
#line 6882 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1500:
#line 6885 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1501:
#line 6888 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 6896 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1504:
#line 6899 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1506:
#line 6905 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1508:
#line 6911 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1509:
#line 6914 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1510:
#line 6917 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1511:
#line 6920 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1512:
#line 6923 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1513:
#line 6926 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1514:
#line 6929 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1516:
#line 6936 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1521:
#line 6943 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1522:
#line 6944 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1523:
#line 6949 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1524:
#line 6952 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1525:
#line 6956 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1526:
#line 6962 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1527:
#line 6963 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1528:
#line 6964 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1529:
#line 6965 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1534:
#line 6985 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1535:
#line 6990 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1536:
#line 6991 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1538:
#line 6994 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1542:
#line 6999 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1544:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1546:
#line 7005 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1550:
#line 7010 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1551:
#line 7012 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1552:
#line 7015 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1553:
#line 7016 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1554:
#line 7023 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1558:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1562:
#line 7044 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1563:
#line 7045 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1564:
#line 7049 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1565:
#line 7050 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1567:
#line 7068 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1568:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1569:
#line 7070 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1570:
#line 7074 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1571:
#line 7077 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1572:
#line 7083 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1573:
#line 7088 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1574:
#line 7093 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1576:
#line 7104 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1581:
#line 7119 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1582:
#line 7122 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7125 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1584:
#line 7127 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1585:
#line 7130 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1586:
#line 7132 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1588:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1589:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1590:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1591:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1592:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1593:
#line 7136 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1594:
#line 7139 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1595:
#line 7144 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1596:
#line 7144 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1597:
#line 7144 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1598:
#line 7144 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1599:
#line 7144 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1600:
#line 7144 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1601:
#line 7146 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1602:
#line 7149 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1617:
#line 7158 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1618:
#line 7159 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1619:
#line 7163 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1620:
#line 7171 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1621:
#line 7171 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1622:
#line 7176 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1623:
#line 7176 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1624:
#line 7182 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1625:
#line 7182 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1626:
#line 7187 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1627:
#line 7187 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1628:
#line 7194 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1629:
#line 7195 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1630:
#line 7196 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1634:
#line 7203 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1635:
#line 7204 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1636:
#line 7209 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1637:
#line 7212 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1638:
#line 7218 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1639:
#line 7223 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1640:
#line 7232 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1641:
#line 7244 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1642:
#line 7245 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1643:
#line 7248 "fgl.yacc"
    {
		char *ptr;
                ptr=make_sql_string("SELECT ",yyvsp[-6].str, yyvsp[-4].sql_string," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);

		yyval.sql_string=strdup(print_select_all(ptr));
		free(ptr);
		free(yyvsp[-4].sql_string);
		free(yyvsp[-2].sql_string);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);
}
    break;

  case 1644:
#line 7263 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1645:
#line 7273 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1646:
#line 7276 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1647:
#line 7284 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1648:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1649:
#line 7296 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1650:
#line 7300 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1651:
#line 7303 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1652:
#line 7304 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1654:
#line 7313 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1655:
#line 7314 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1656:
#line 7323 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1657:
#line 7332 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1658:
#line 7337 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1659:
#line 7338 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1660:
#line 7339 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1661:
#line 7340 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1662:
#line 7348 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1663:
#line 7351 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1664:
#line 7357 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1665:
#line 7360 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1666:
#line 7363 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1667:
#line 7369 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1668:
#line 7378 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1669:
#line 7381 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1670:
#line 7384 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1671:
#line 7390 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1672:
#line 7396 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1673:
#line 7399 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1674:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1675:
#line 7405 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1676:
#line 7412 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1677:
#line 7414 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1678:
#line 7416 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1679:
#line 7418 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1680:
#line 7420 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1681:
#line 7421 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1682:
#line 7422 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1683:
#line 7423 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1684:
#line 7424 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1685:
#line 7425 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1686:
#line 7426 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1687:
#line 7428 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1688:
#line 7430 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1689:
#line 7432 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1690:
#line 7434 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1691:
#line 7436 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1692:
#line 7438 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1693:
#line 7440 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1694:
#line 7441 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1695:
#line 7443 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1696:
#line 7447 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1697:
#line 7448 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1700:
#line 7458 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1701:
#line 7467 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1702:
#line 7471 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1703:
#line 7478 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1704:
#line 7478 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1706:
#line 7482 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1707:
#line 7487 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1708:
#line 7487 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1710:
#line 7491 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1711:
#line 7495 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1714:
#line 7504 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1715:
#line 7504 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1720:
#line 7523 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1721:
#line 7524 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1724:
#line 7532 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1725:
#line 7538 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1728:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1729:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1730:
#line 7559 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1731:
#line 7560 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1732:
#line 7561 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1733:
#line 7562 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1734:
#line 7566 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1735:
#line 7567 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1736:
#line 7568 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1737:
#line 7572 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1738:
#line 7576 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1740:
#line 7585 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1742:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1743:
#line 7591 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1744:
#line 7595 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1745:
#line 7601 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1746:
#line 7688 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1747:
#line 7692 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1748:
#line 7694 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1749:
#line 7701 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1750:
#line 7705 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1751:
#line 7711 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1752:
#line 7719 "fgl.yacc"
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

  case 1753:
#line 7729 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1754:
#line 7739 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1755:
#line 7751 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1756:
#line 7754 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 1757:
#line 7773 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 1758:
#line 7799 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1759:
#line 7802 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1761:
#line 7811 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1762:
#line 7816 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1763:
#line 7819 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1764:
#line 7827 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1765:
#line 7835 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1766:
#line 7848 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1767:
#line 7851 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1768:
#line 7859 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1769:
#line 7862 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1770:
#line 7865 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1771:
#line 7873 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1772:
#line 7877 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1773:
#line 7880 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1774:
#line 7883 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1775:
#line 7886 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1776:
#line 7890 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1777:
#line 7891 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1778:
#line 7892 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1779:
#line 7893 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1780:
#line 7894 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1781:
#line 7900 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1782:
#line 7901 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1783:
#line 7902 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1784:
#line 7903 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1785:
#line 7904 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1786:
#line 7905 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1787:
#line 7906 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1788:
#line 7907 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1789:
#line 7908 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1790:
#line 7909 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1791:
#line 7910 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1792:
#line 7911 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1793:
#line 7912 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1794:
#line 7913 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);printf("C14\n");}
    break;

  case 1795:
#line 7917 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1796:
#line 7923 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1797:
#line 7924 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1798:
#line 7937 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1799:
#line 7948 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1803:
#line 7954 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1804:
#line 7955 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1808:
#line 7967 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
	{
		int z = 0,a = 0;
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);
		z-=a;
		yyval.sql_string=strdup(A4GL_set_var_sql(z));

	} else {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
}
    break;

  case 1809:
#line 7981 "fgl.yacc"
    {
char r1[256];
char r2[256];
char buff[256];
char was_str[40000];
char *ptr1;
char *ptr2;
int aa;
int z = 0,a = 0;
struct variable *v_r;
struct variable *v_1;
struct variable *v_2;
struct variable *v_loop;
        strcpy(was_str,"");


	split_record(yyvsp[0].str,&v_r,&v_1,&v_2);

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
	yyval.sql_string=strdup(was_str);
}
    break;

  case 1810:
#line 8032 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1811:
#line 8034 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1812:
#line 8036 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1813:
#line 8037 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1814:
#line 8042 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1815:
#line 8047 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1816:
#line 8048 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1817:
#line 8052 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1818:
#line 8054 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1819:
#line 8056 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1820:
#line 8059 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1821:
#line 8063 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1822:
#line 8068 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1823:
#line 8073 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1824:
#line 8077 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1826:
#line 8087 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1828:
#line 8102 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1829:
#line 8105 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1830:
#line 8109 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1833:
#line 8128 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1834:
#line 8129 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1835:
#line 8132 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1836:
#line 8133 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1837:
#line 8134 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1838:
#line 8135 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1839:
#line 8136 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1840:
#line 8137 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1841:
#line 8138 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1842:
#line 8143 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1843:
#line 8144 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1844:
#line 8148 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1845:
#line 8152 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1846:
#line 8156 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1847:
#line 8160 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1848:
#line 8165 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1849:
#line 8169 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1850:
#line 8174 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1852:
#line 8182 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1854:
#line 8188 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1855:
#line 8194 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1856:
#line 8198 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1861:
#line 8216 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1862:
#line 8223 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1863:
#line 8232 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1864:
#line 8232 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17062 "y.tab.c"

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


#line 8327 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber(char *c)
{
	char *ptr;
	char *ptr2;
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



