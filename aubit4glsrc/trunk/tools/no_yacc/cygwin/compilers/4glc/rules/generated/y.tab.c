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
#define YYLAST   8397

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  666
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  827
/* YYNRULES -- Number of rules. */
#define YYNRULES  1895
/* YYNRULES -- Number of states. */
#define YYNSTATES  3154

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
    1840,  1847,  1851,  1858,  1860,  1862,  1865,  1868,  1871,  1873,
    1877,  1879,  1882,  1885,  1888,  1893,  1896,  1899,  1904,  1905,
    1914,  1915,  1917,  1919,  1921,  1922,  1924,  1927,  1928,  1930,
    1933,  1934,  1936,  1939,  1940,  1942,  1946,  1947,  1950,  1951,
    1959,  1960,  1961,  1965,  1966,  1967,  1975,  1981,  1984,  1987,
    1988,  1994,  1999,  2001,  2005,  2009,  2013,  2014,  2017,  2018,
    2020,  2022,  2025,  2026,  2031,  2032,  2037,  2038,  2042,  2043,
    2047,  2048,  2052,  2053,  2057,  2058,  2062,  2063,  2067,  2068,
    2072,  2073,  2077,  2078,  2082,  2084,  2088,  2090,  2094,  2097,
    2102,  2104,  2106,  2108,  2109,  2114,  2120,  2127,  2128,  2139,
    2143,  2145,  2147,  2150,  2153,  2154,  2157,  2159,  2162,  2166,
    2170,  2174,  2178,  2180,  2182,  2184,  2186,  2187,  2191,  2193,
    2194,  2198,  2201,  2202,  2206,  2208,  2212,  2214,  2218,  2219,
    2222,  2224,  2226,  2228,  2230,  2232,  2234,  2236,  2238,  2240,
    2242,  2244,  2246,  2248,  2250,  2252,  2254,  2256,  2258,  2259,
    2260,  2268,  2270,  2272,  2275,  2278,  2281,  2285,  2290,  2291,
    2295,  2296,  2298,  2300,  2303,  2305,  2307,  2309,  2311,  2312,
    2314,  2316,  2319,  2322,  2324,  2326,  2328,  2330,  2332,  2334,
    2336,  2338,  2340,  2342,  2344,  2346,  2348,  2349,  2351,  2353,
    2355,  2357,  2359,  2360,  2361,  2362,  2363,  2377,  2379,  2380,
    2381,  2388,  2391,  2393,  2396,  2399,  2401,  2403,  2406,  2408,
    2410,  2412,  2413,  2417,  2420,  2422,  2423,  2424,  2425,  2440,
    2441,  2447,  2449,  2450,  2454,  2455,  2463,  2464,  2470,  2472,
    2475,  2476,  2478,  2480,  2482,  2483,  2485,  2487,  2490,  2493,
    2496,  2498,  2500,  2502,  2504,  2508,  2510,  2512,  2513,  2514,
    2522,  2524,  2527,  2528,  2532,  2533,  2538,  2541,  2542,  2545,
    2547,  2549,  2551,  2553,  2555,  2557,  2559,  2560,  2564,  2565,
    2567,  2569,  2571,  2573,  2576,  2579,  2582,  2588,  2597,  2599,
    2601,  2603,  2608,  2613,  2615,  2617,  2619,  2621,  2624,  2627,
    2631,  2638,  2640,  2644,  2646,  2648,  2650,  2654,  2661,  2671,
    2673,  2675,  2677,  2679,  2682,  2683,  2685,  2687,  2691,  2693,
    2697,  2699,  2703,  2705,  2709,  2711,  2713,  2715,  2717,  2721,
    2723,  2727,  2729,  2733,  2735,  2737,  2739,  2743,  2746,  2747,
    2749,  2751,  2756,  2758,  2762,  2764,  2768,  2776,  2777,  2785,
    2786,  2793,  2797,  2799,  2803,  2805,  2808,  2814,  2815,  2823,
    2824,  2827,  2828,  2830,  2836,  2839,  2845,  2846,  2852,  2859,
    2864,  2865,  2867,  2869,  2874,  2875,  2878,  2879,  2885,  2890,
    2893,  2895,  2899,  2902,  2905,  2908,  2911,  2914,  2917,  2919,
    2922,  2925,  2928,  2931,  2934,  2937,  2940,  2943,  2946,  2948,
    2950,  2952,  2954,  2956,  2958,  2964,  2966,  2968,  2971,  2976,
    2978,  2979,  2990,  2996,  2997,  2999,  3000,  3003,  3005,  3008,
    3009,  3013,  3015,  3016,  3021,  3022,  3025,  3027,  3031,  3033,
    3035,  3039,  3044,  3049,  3052,  3054,  3056,  3058,  3059,  3061,
    3069,  3072,  3075,  3078,  3081,  3084,  3086,  3089,  3090,  3094,
    3095,  3099,  3100,  3104,  3105,  3109,  3110,  3114,  3115,  3120,
    3121,  3126,  3128,  3130,  3132,  3134,  3136,  3138,  3139,  3144,
    3145,  3147,  3148,  3153,  3155,  3158,  3161,  3164,  3165,  3167,
    3169,  3172,  3175,  3176,  3179,  3183,  3187,  3193,  3194,  3197,
    3202,  3204,  3206,  3208,  3210,  3212,  3213,  3215,  3217,  3221,
    3224,  3230,  3233,  3239,  3245,  3251,  3257,  3263,  3269,  3270,
    3273,  3275,  3278,  3281,  3284,  3287,  3290,  3293,  3295,  3298,
    3301,  3304,  3307,  3309,  3312,  3315,  3318,  3321,  3323,  3325,
    3327,  3328,  3331,  3334,  3337,  3340,  3343,  3346,  3349,  3352,
    3355,  3357,  3359,  3361,  3363,  3365,  3367,  3369,  3371,  3374,
    3377,  3380,  3383,  3386,  3388,  3390,  3392,  3393,  3397,  3400,
    3401,  3402,  3403,  3404,  3405,  3406,  3422,  3423,  3426,  3429,
    3430,  3432,  3433,  3434,  3435,  3436,  3437,  3438,  3454,  3457,
    3458,  3459,  3460,  3471,  3472,  3474,  3478,  3482,  3485,  3490,
    3494,  3498,  3502,  3504,  3506,  3508,  3510,  3512,  3514,  3515,
    3516,  3524,  3525,  3526,  3535,  3539,  3542,  3543,  3545,  3547,
    3551,  3554,  3557,  3559,  3561,  3565,  3567,  3569,  3572,  3574,
    3578,  3580,  3584,  3586,  3588,  3590,  3592,  3594,  3596,  3598,
    3601,  3606,  3608,  3612,  3614,  3618,  3621,  3626,  3628,  3632,
    3634,  3637,  3642,  3644,  3648,  3650,  3652,  3654,  3657,  3660,
    3665,  3668,  3673,  3675,  3679,  3681,  3683,  3685,  3688,  3690,
    3692,  3694,  3696,  3698,  3701,  3708,  3715,  3716,  3718,  3719,
    3721,  3724,  3726,  3727,  3733,  3734,  3740,  3742,  3743,  3747,
    3749,  3753,  3755,  3759,  3761,  3763,  3764,  3765,  3771,  3774,
    3776,  3777,  3778,  3782,  3783,  3784,  3788,  3790,  3792,  3794,
    3796,  3798,  3800,  3803,  3806,  3811,  3815,  3819,  3821,  3825,
    3828,  3830,  3832,  3833,  3835,  3837,  3839,  3841,  3842,  3844,
    3848,  3850,  3852,  3853,  3857,  3859,  3861,  3863,  3865,  3867,
    3869,  3871,  3873,  3875,  3877,  3879,  3881,  3889,  3890,  3892,
    3894,  3896,  3898,  3902,  3904,  3906,  3908,  3911,  3912,  3916,
    3918,  3922,  3924,  3928,  3930,  3932,  3939,  3940,  3944,  3946,
    3950,  3951,  3953,  3958,  3964,  3967,  3969,  3971,  3976,  3978,
    3982,  3987,  3992,  3994,  3998,  4000,  4002,  4004,  4007,  4009,
    4014,  4015,  4017,  4018,  4020,  4022,  4025,  4027,  4029,  4031,
    4033,  4038,  4042,  4044,  4046,  4048,  4051,  4053,  4055,  4058,
    4061,  4063,  4067,  4070,  4073,  4075,  4079,  4081,  4084,  4089,
    4091,  4094,  4096,  4100,  4105,  4106,  4108,  4109,  4111,  4112,
    4114,  4116,  4120,  4122,  4126,  4128,  4131,  4133,  4137,  4140,
    4143,  4144,  4147,  4149,  4151,  4153,  4159,  4163,  4169,  4173,
    4175,  4179,  4181,  4183,  4184,  4186,  4190,  4194,  4198,  4205,
    4210,  4215,  4221,  4223,  4225,  4227,  4229,  4231,  4233,  4235,
    4237,  4239,  4241,  4243,  4244,  4246,  4248,  4250,  4252,  4254,
    4256,  4258,  4263,  4269,  4271,  4277,  4283,  4285,  4287,  4289,
    4294,  4296,  4301,  4303,  4311,  4313,  4315,  4317,  4322,  4329,
    4330,  4333,  4338,  4340,  4342,  4344,  4346,  4348,  4350,  4352,
    4356,  4358,  4360,  4364,  4366,  4367,  4371,  4377,  4379,  4382,
    4385,  4390,  4394,  4396,  4398,  4400,  4402,  4404,  4406,  4409,
    4412,  4413,  4417,  4418,  4422,  4424,  4426,  4428,  4430,  4432,
    4434,  4436,  4441,  4443,  4445,  4447,  4449,  4451,  4453,  4455,
    4460,  4462,  4464,  4466,  4468,  4470,  4472,  4474,  4476,  4478,
    4480,  4482,  4484,  4486,  4488,  4490,  4492,  4496,  4497,  4506,
    4507,  4517,  4518,  4526,  4527,  4537,  4538,  4540,  4543,  4545,
    4549,  4551,  4555,  4561,  4563,  4565,  4567,  4569,  4572,  4573,
    4574,  4583,  4589,  4591,  4593,  4600,  4601,  4605,  4607,  4611,
    4616,  4618,  4619,  4622,  4627,  4634,  4635,  4637,  4639,  4641,
    4643,  4647,  4649,  4652,  4654,  4656,  4659,  4662,  4664,  4666,
    4668,  4671,  4676,  4680,  4683,  4687,  4691,  4695,  4697,  4699,
    4701,  4703,  4705,  4707,  4713,  4719,  4725,  4731,  4737,  4742,
    4747,  4751,  4756,  4758,  4762,  4763,  4765,  4771,  4779,  4785,
    4786,  4789,  4791,  4793,  4794,  4798,  4800,  4804,  4806,  4808,
    4810,  4811,  4815,  4817,  4819,  4821,  4823,  4828,  4835,  4837,
    4839,  4842,  4846,  4848,  4850,  4852,  4854,  4856,  4858,  4860,
    4862,  4868,  4874,  4879,  4880,  4885,  4887,  4890,  4892,  4894,
    4896,  4899,  4902,  4903,  4904,  4911,  4912,  4915,  4918,  4926,
    4930,  4934,  4937,  4940,  4943,  4945,  4949,  4951,  4955,  4957,
    4961,  4963,  4967,  4969,  4971,  4973,  4976,  4979,  4981,  4983,
    4986,  4991,  4993,  4995,  4997,  4999,  5001,  5003,  5007,  5010,
    5014,  5018,  5022,  5028,  5034,  5040,  5046,  5052,  5057,  5062,
    5066,  5071,  5073,  5075,  5079,  5081,  5084,  5086,  5088,  5090,
    5094,  5100,  5102,  5104,  5106,  5108,  5112,  5115,  5118,  5121,
    5123,  5126,  5129,  5131,  5134,  5137,  5140,  5142,  5146,  5149,
    5151,  5154,  5156,  5159,  5161,  5162,  5163,  5170,  5171,  5174,
    5175,  5177,  5179,  5182,  5185,  5187,  5189,  5194,  5198,  5200,
    5204,  5206,  5209,  5215,  5218,  5221,  5227,  5228,  5231,  5233,
    5235,  5238,  5245,  5252,  5254,  5255,  5257,  5260,  5262,  5265,
    5266,  5269,  5271,  5273,  5275,  5277,  5279,  5281,  5283,  5285,
    5287,  5289,  5291,  5293,  5295,  5297,  5299,  5301,  5303,  5305,
    5307,  5309,  5311,  5313,  5315,  5317,  5319,  5321,  5323,  5325,
    5327,  5329,  5331,  5333,  5335,  5337,  5339,  5341,  5343,  5345,
    5347,  5349,  5351,  5353,  5355,  5357,  5359,  5361,  5363,  5365,
    5367,  5369,  5371,  5373,  5375,  5377,  5379,  5381,  5383,  5385,
    5387,  5389,  5391,  5393,  5395,  5397,  5399,  5401,  5403,  5405,
    5407,  5409,  5411,  5413,  5415,  5417,  5419,  5421,  5423,  5425,
    5427,  5429,  5431,  5433,  5435,  5437
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1024,     0,    -1,   197,    -1,   194,    -1,   122,   671,   423,
     593,   672,    -1,   136,    -1,  1090,    -1,    25,    -1,   673,
      -1,   672,     5,   673,    -1,   935,    -1,   427,   674,   388,
      -1,   674,   675,   674,    -1,    25,    -1,   676,    25,    -1,
    1090,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   678,    -1,    -1,
     271,   427,   679,   680,   388,    -1,   566,   427,    25,     5,
      25,   388,    -1,   681,    -1,   680,     5,   681,    -1,   487,
      -1,   528,    -1,   534,    -1,   503,    -1,   406,    -1,   603,
      -1,   525,    -1,   477,    -1,   413,    -1,   488,    -1,   342,
      -1,   529,    -1,   452,    -1,   329,    -1,   591,    -1,    96,
      -1,  1001,    -1,    -1,   683,    -1,    -1,   271,   427,   684,
     685,   388,    -1,   686,    -1,   685,     5,   686,    -1,   681,
      -1,   428,    -1,   601,    24,    -1,   200,   922,    -1,   326,
     922,    -1,   281,   922,    -1,   334,   922,    -1,   290,   922,
      -1,   256,   922,    -1,   531,   688,    -1,   867,   341,  1090,
      -1,    -1,   286,   427,  1477,   388,   341,   689,  1109,    -1,
     102,   427,   935,     5,    24,     5,    24,   388,    -1,   403,
     427,   927,   388,   341,  1090,    -1,  1227,    -1,   189,   427,
     886,   388,   341,  1090,    -1,    -1,    -1,  1090,   587,   935,
     427,   690,   704,   388,   691,   702,    -1,    -1,    -1,    -1,
     935,   427,   692,   704,   693,   388,   694,   702,    -1,    -1,
      -1,   471,  1424,   621,  1424,   427,   695,   704,   696,   388,
     702,    -1,    -1,    -1,   935,   518,   935,   427,   697,   704,
     698,   388,   702,    -1,    -1,    -1,    -1,   362,   707,   587,
     708,   455,   671,   423,   427,   699,   704,   700,   388,   701,
     703,    -1,    -1,   341,  1109,    -1,    -1,   341,  1109,    -1,
     160,    -1,    -1,   705,    -1,   706,    -1,   705,     5,   706,
      -1,   836,    -1,    24,    -1,   935,    -1,   935,    -1,   935,
     618,   935,    -1,    -1,   532,   843,   710,   713,   717,   714,
      -1,    -1,   532,   711,   712,   715,   714,    -1,   719,    -1,
     712,   719,    -1,   721,    -1,   713,   721,    -1,   357,    -1,
      -1,    -1,   336,   716,  1487,    -1,    -1,    -1,   336,   718,
    1487,    -1,    -1,   576,   843,   720,  1487,    -1,    -1,   576,
     843,   722,  1487,    -1,   275,   932,    -1,   199,   930,    -1,
      81,   930,    -1,   166,    -1,   182,  1430,    -1,   491,   929,
      -1,    29,   725,    30,    -1,   726,    -1,   728,    -1,   727,
      -1,   726,   727,    -1,    28,    -1,   729,    -1,   728,   729,
      -1,    27,    -1,   390,    -1,    -1,    -1,   317,   732,   734,
     733,   735,    -1,   381,  1090,   623,   736,   975,  1000,   677,
      -1,  1090,   623,   736,   975,   544,  1477,  1000,   677,    -1,
      -1,   738,   188,    -1,   737,    -1,   736,     5,   737,    -1,
     935,    -1,   935,   618,   935,    -1,   935,   618,    20,    -1,
     739,    -1,   738,   739,    -1,    -1,   267,   745,   740,  1487,
      -1,    -1,   270,   746,   741,  1487,    -1,    -1,  1003,   742,
    1487,    -1,    -1,   164,   743,  1487,    -1,    -1,   161,   744,
    1487,    -1,   939,    -1,   745,     5,   939,    -1,   939,    -1,
     746,     5,   939,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,   427,   836,   749,   388,
      -1,    -1,     5,   790,   624,   793,    -1,   153,    -1,   276,
      -1,    -1,   752,    -1,   753,    -1,   752,   753,    -1,    -1,
      -1,   434,   754,   756,   755,  1196,    -1,   803,    -1,  1467,
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
      66,    -1,   624,  1477,    -1,   624,   506,   935,   657,  1477,
      -1,   624,   506,   935,   386,    -1,    70,   935,    -1,   154,
     861,  1109,   825,    -1,   397,   861,   841,   817,   825,    -1,
     206,   932,   825,    -1,    -1,    -1,   185,   822,  1116,   624,
     935,   618,    20,   824,   677,   823,   826,    -1,    -1,   465,
     927,    -1,   677,    -1,    -1,   827,   235,    -1,   828,    -1,
     827,   828,    -1,    -1,   348,   829,  1487,    -1,    -1,   344,
     830,  1487,    -1,    -1,  1003,   831,  1487,    -1,   495,   861,
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
      -1,   427,   836,   388,    -1,   439,   427,  1404,   388,    -1,
     291,   427,  1404,   388,    -1,   844,   941,    -1,   844,    25,
      -1,    24,    -1,   941,    -1,    25,    -1,   849,    -1,  1090,
      -1,  1090,   417,  1090,    -1,   848,    -1,   430,   836,    -1,
     389,   836,    -1,  1199,    -1,    -1,   504,   851,  1199,    -1,
       7,   836,    -1,     6,   836,    -1,   836,    -1,   853,     5,
     836,    -1,   621,   427,  1404,   388,    -1,   425,   427,  1404,
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
     427,    25,   587,    25,   388,   876,    -1,    -1,  1384,   624,
    1385,    -1,   789,    -1,   867,    -1,   286,   427,  1477,   388,
      -1,    97,   427,   927,   388,    -1,    69,   427,   927,   388,
      -1,   403,   427,   927,   388,    -1,   189,   427,   886,   388,
      -1,    57,   427,   886,   388,    -1,   880,    -1,   862,    -1,
    1380,    -1,   535,    -1,   419,   427,   836,   388,    -1,   319,
     427,   836,   388,    -1,   485,   836,    -1,   440,   748,    -1,
     836,   106,    -1,   836,   107,    -1,   836,   108,    -1,    24,
      -1,   883,    -1,    18,   883,    -1,   885,    -1,   884,    -1,
      25,    -1,    25,    25,    -1,    25,    25,   587,    25,    -1,
      25,    25,   587,    25,   587,    25,    -1,    25,    25,   587,
      25,   587,    23,    -1,    25,   587,    25,    -1,    25,   587,
      25,   587,    25,    -1,    25,   587,    25,   587,    23,    -1,
      25,   587,    23,    -1,    23,    -1,    25,    -1,    25,    18,
      25,    -1,   927,    -1,   886,     5,   927,    -1,    -1,    -1,
     593,  1090,    13,   843,   624,   843,   890,   888,  1487,   889,
     238,    -1,    -1,   569,   843,    -1,    -1,    -1,    -1,   400,
     892,   929,   893,  1285,   894,  1487,   237,    -1,    -1,    -1,
     636,   935,   896,   751,   897,  1034,   899,   898,   904,   637,
      -1,    -1,   909,    -1,    -1,   900,    -1,   901,    -1,   900,
     901,    -1,    -1,   638,   902,  1487,    -1,    -1,   639,   903,
    1487,    -1,    -1,   905,    -1,   906,    -1,   905,   906,    -1,
      -1,   640,   907,  1487,    -1,    -1,   641,   908,  1487,    -1,
     910,   914,   321,    -1,    89,    -1,    89,   911,   544,   912,
      -1,    89,   381,   913,    -1,  1090,    -1,   911,     5,  1090,
      -1,   935,    -1,   912,     5,   935,    -1,  1090,    -1,   913,
       5,  1090,    -1,   915,    -1,   914,   915,    -1,    -1,   642,
     916,  1487,    -1,    -1,   643,   917,  1487,    -1,    -1,   662,
     912,   918,  1487,    -1,    -1,   478,   912,   919,  1487,    -1,
      -1,   623,   912,   920,  1487,    -1,   543,   928,    -1,   552,
      18,    25,    -1,   552,    -1,   498,    17,    25,    -1,   498,
      -1,    25,    -1,  1090,    -1,    24,    -1,   940,    -1,   843,
      -1,   924,     5,   924,    -1,   925,    -1,   935,    -1,   665,
     427,   935,   388,    -1,   935,   618,   665,   427,   935,   388,
      -1,   935,   455,   674,   423,    -1,   935,   618,    20,    -1,
     935,   455,   674,   423,   618,    20,    -1,   935,   618,   935,
      -1,   935,   455,   674,   423,   618,   935,    -1,   936,    -1,
     936,    -1,   936,    -1,   936,    -1,   936,    -1,   936,    -1,
      -1,   548,    25,    -1,  1486,    -1,   937,    -1,  1486,    -1,
     346,   427,   938,   388,    -1,  1093,    -1,    24,    -1,   935,
      -1,   935,   455,   674,   423,    -1,   935,   618,    20,    -1,
     935,   455,   674,   423,   618,    20,    -1,   935,   618,   935,
      -1,   935,   455,   674,   423,   618,   935,    -1,  1090,    -1,
      23,    -1,   618,    25,    -1,   545,  1469,    -1,   650,   944,
      -1,   945,    -1,   944,     5,   945,    -1,   935,    -1,   661,
     944,    -1,   652,   944,    -1,   653,  1477,    -1,   651,   932,
     657,  1477,    -1,   655,   944,    -1,   656,  1477,    -1,   654,
     932,   657,  1477,    -1,    -1,   659,   950,   841,   955,   957,
     959,   951,   953,    -1,    -1,   952,    -1,   647,    -1,   648,
      -1,    -1,   954,    -1,   341,  1090,    -1,    -1,   956,    -1,
     386,   841,    -1,    -1,   958,    -1,   658,    25,    -1,    -1,
     960,    -1,   649,    25,   961,    -1,    -1,   396,    25,    -1,
      -1,   620,   843,   573,   963,  1487,   964,   437,    -1,    -1,
      -1,   540,   965,  1487,    -1,    -1,    -1,    60,   966,   843,
     573,   967,  1487,   964,    -1,   104,   935,   427,    25,   388,
      -1,    53,   935,    -1,    73,   935,    -1,    -1,   287,  1121,
     971,   624,   480,    -1,   287,  1121,   554,   972,    -1,   973,
      -1,   972,     5,   973,    -1,   786,   618,  1376,    -1,   786,
     618,    20,    -1,    -1,   976,   321,    -1,    -1,   148,    -1,
     977,    -1,   976,   977,    -1,    -1,   267,   989,   978,  1487,
      -1,    -1,   270,   990,   979,  1487,    -1,    -1,   348,   980,
    1487,    -1,    -1,   344,   981,  1487,    -1,    -1,  1003,   982,
    1487,    -1,    -1,   302,   983,  1487,    -1,    -1,   272,   984,
    1487,    -1,    -1,    34,   985,  1487,    -1,    -1,    33,   986,
    1487,    -1,    -1,    36,   987,  1487,    -1,    -1,    35,   988,
    1487,    -1,   927,    -1,   989,     5,   927,    -1,   927,    -1,
     990,     5,   927,    -1,   311,   993,    -1,   312,   935,   657,
     993,    -1,   559,    -1,   371,    -1,   927,    -1,    -1,   663,
     996,   995,   974,    -1,   381,  1109,   975,   934,   677,    -1,
    1109,   975,   544,  1477,   934,   677,    -1,    -1,   484,  1116,
     975,   544,   935,   618,    20,   934,   997,   677,    -1,   466,
    1477,   999,    -1,   625,    -1,   537,    -1,    74,    25,    -1,
      80,    25,    -1,    -1,   548,    25,    -1,  1002,    -1,    41,
      24,    -1,   493,    13,    25,    -1,   493,    13,  1090,    -1,
      42,    13,    25,    -1,    42,    13,  1090,    -1,    38,    -1,
      40,    -1,    37,    -1,    39,    -1,    -1,   426,  1004,  1010,
      -1,   292,    -1,    -1,   594,  1006,  1010,    -1,   300,  1012,
      -1,    -1,   594,  1009,  1010,    -1,  1012,    -1,   427,  1011,
     388,    -1,  1012,    -1,  1011,     5,  1012,    -1,    -1,  1013,
    1014,    -1,   592,    -1,   309,    -1,   327,    -1,   301,    -1,
     482,    -1,   438,    -1,   625,    -1,   548,    -1,   537,    -1,
     462,    -1,   435,    -1,   538,    -1,   553,    -1,   517,    -1,
     307,    -1,   308,    -1,    24,    -1,   507,    -1,    -1,    -1,
     596,  1017,  1114,  1018,    13,   861,  1019,    -1,   480,    -1,
     842,    -1,   216,  1090,    -1,   205,  1090,    -1,   219,  1090,
      -1,   447,  1090,   330,    -1,   447,  1090,   382,   923,    -1,
      -1,  1026,  1025,  1029,    -1,    -1,  1027,    -1,  1028,    -1,
    1027,  1028,    -1,   969,    -1,  1033,    -1,  1049,    -1,  1035,
      -1,    -1,  1030,    -1,  1032,    -1,  1030,  1032,    -1,    64,
     935,    -1,  1037,    -1,  1043,    -1,  1055,    -1,  1209,    -1,
    1219,    -1,  1076,    -1,  1467,    -1,   895,    -1,   724,    -1,
     968,    -1,   730,    -1,   724,    -1,  1467,    -1,    -1,   724,
      -1,  1467,    -1,   752,    -1,   364,    -1,    58,    -1,    -1,
      -1,    -1,    -1,  1036,  1038,   935,   427,  1039,  1107,   388,
    1040,   751,  1041,  1034,  1487,  1042,    -1,   207,    -1,    -1,
      -1,   555,  1044,   751,  1045,  1487,   358,    -1,   462,   838,
      -1,   861,    -1,   861,   841,    -1,   353,  1388,    -1,  1050,
      -1,  1051,    -1,  1050,  1051,    -1,  1052,    -1,  1033,    -1,
    1048,    -1,    -1,   402,  1053,  1054,    -1,   751,   239,    -1,
     923,    -1,    -1,    -1,    -1,   111,   935,   110,   935,   427,
    1056,  1107,   388,  1057,   751,  1058,  1034,  1487,  1042,    -1,
      -1,   556,  1060,  1075,  1066,  1061,    -1,   359,    -1,    -1,
     231,  1063,  1487,    -1,    -1,    22,  1067,  1068,  1069,   934,
    1064,  1487,    -1,    -1,    22,  1067,   934,  1065,  1487,    -1,
    1062,    -1,  1066,  1062,    -1,    -1,  1005,    -1,    24,    -1,
    1090,    -1,    -1,  1090,    -1,    24,    -1,   248,  1073,    -1,
     260,  1074,    -1,   243,  1074,    -1,   583,    -1,    24,    -1,
    1090,    -1,  1073,    -1,  1074,     5,  1073,    -1,  1090,    -1,
      24,    -1,    -1,    -1,   644,   935,  1077,   751,  1078,  1079,
     645,    -1,  1080,    -1,  1079,  1080,    -1,    -1,   646,  1081,
    1487,    -1,    -1,   623,   935,  1082,  1487,    -1,  1086,  1084,
      -1,    -1,   678,  1088,    -1,  1089,    -1,  1085,    -1,   956,
      -1,   958,    -1,   960,    -1,   952,    -1,   954,    -1,    -1,
     367,  1087,   842,    -1,    -1,    63,    -1,    63,    -1,  1091,
      -1,  1093,    -1,   187,  1093,    -1,  1093,   618,    -1,  1092,
    1097,    -1,  1092,   935,   455,  1101,   423,    -1,  1092,   935,
     455,  1101,   423,   455,  1101,   423,    -1,  1098,    -1,   935,
      -1,  1094,    -1,   935,   454,  1096,   422,    -1,   935,   454,
    1096,   422,    -1,  1090,    -1,    24,    -1,    20,    -1,   935,
      -1,   935,  1100,    -1,   935,  1100,    -1,   455,  1101,   423,
      -1,   455,  1101,   423,   455,  1101,   423,    -1,  1102,    -1,
    1101,     5,  1102,    -1,   674,    -1,  1104,    -1,  1106,    -1,
    1104,   618,  1105,    -1,  1104,   618,   935,   455,  1101,   423,
      -1,  1104,   618,   935,   455,  1101,   423,   455,  1101,   423,
      -1,   935,    -1,  1095,    -1,    20,    -1,   935,    -1,   935,
    1100,    -1,    -1,  1108,    -1,  1110,    -1,  1108,     5,  1110,
      -1,  1111,    -1,  1109,     5,  1111,    -1,   935,    -1,   935,
     618,   935,    -1,  1090,    -1,  1090,   417,  1090,    -1,    24,
      -1,   941,    -1,    25,    -1,  1113,    -1,  1112,     5,  1113,
      -1,  1090,    -1,  1090,   417,  1090,    -1,  1115,    -1,  1114,
       5,  1115,    -1,  1103,    -1,  1090,    -1,  1118,    -1,  1117,
       5,  1118,    -1,  1090,  1119,    -1,    -1,   585,    -1,   536,
      -1,   935,   455,  1101,   423,    -1,  1122,    -1,  1121,     5,
    1122,    -1,  1090,    -1,  1090,   417,  1090,    -1,   251,   931,
     616,   925,   577,  1479,   682,    -1,    -1,   616,   427,   843,
       5,   843,   388,  1125,    -1,    -1,   566,   427,   843,     5,
     843,   388,    -1,   252,   935,  1124,    -1,   935,    -1,   335,
     933,  1129,    -1,  1130,    -1,   544,   843,    -1,  1131,  1132,
    1137,     8,  1127,    -1,    -1,   616,  1133,   427,   843,     5,
     843,   388,    -1,    -1,   554,   936,    -1,    -1,   347,    -1,
     214,  1430,   263,  1462,  1136,    -1,   561,   928,    -1,   561,
     928,     8,   861,   841,    -1,    -1,   615,   574,  1424,   370,
    1424,    -1,   615,   574,  1424,     5,   370,  1424,    -1,   615,
    1424,     5,  1424,    -1,    -1,   647,    -1,   648,    -1,    88,
    1462,  1139,  1140,    -1,    -1,   615,  1462,    -1,    -1,   615,
     574,  1424,     8,  1424,    -1,   574,  1424,     8,  1424,    -1,
     408,  1142,    -1,  1143,    -1,  1142,     5,  1143,    -1,   200,
     922,    -1,   281,   922,    -1,   326,   922,    -1,   334,   922,
      -1,   290,   922,    -1,   256,   922,    -1,  1007,    -1,   435,
    1008,    -1,   446,  1008,    -1,   559,  1008,    -1,   371,  1008,
      -1,   548,  1008,    -1,   546,   923,    -1,   547,   923,    -1,
     397,   678,    -1,   663,   678,    -1,   288,    -1,   192,    -1,
     149,    -1,   126,    -1,   144,    -1,   135,    -1,  1429,   410,
    1147,   544,  1145,    -1,  1090,    -1,    24,    -1,   399,  1147,
      -1,   399,  1147,     8,  1109,    -1,   936,    -1,    -1,   458,
    1156,   677,   593,  1151,  1090,   934,   677,  1149,  1152,    -1,
     458,  1156,   677,   341,  1090,    -1,    -1,   533,    -1,    -1,
    1153,   279,    -1,  1154,    -1,  1153,  1154,    -1,    -1,  1003,
    1155,  1487,    -1,   842,    -1,    -1,   602,   928,  1158,  1159,
      -1,    -1,   544,  1160,    -1,  1161,    -1,  1160,     5,  1161,
      -1,  1416,    -1,   480,    -1,   217,  1164,    86,    -1,   217,
    1164,   624,  1163,    -1,   217,  1164,    85,  1163,    -1,   217,
    1164,    -1,    24,    -1,   940,    -1,   935,    -1,    -1,   476,
      -1,   143,  1164,  1165,   427,   861,  1047,   388,    -1,   190,
    1164,    -1,    65,  1164,    -1,  1200,  1208,    -1,   443,    59,
      -1,   443,  1171,    -1,  1172,    -1,  1171,  1172,    -1,    -1,
     131,  1173,  1487,    -1,    -1,   196,  1174,  1487,    -1,    -1,
     225,  1175,  1487,    -1,    -1,   213,  1176,  1487,    -1,    -1,
     250,  1177,  1487,    -1,    -1,   198,  1090,  1178,  1487,    -1,
      -1,   221,  1090,  1179,  1487,    -1,  1190,    -1,  1192,    -1,
    1191,    -1,  1181,    -1,  1217,    -1,  1184,    -1,    -1,   558,
     843,  1182,   479,    -1,    -1,   479,    -1,    -1,   567,   843,
    1185,  1183,    -1,   156,    -1,   627,  1204,    -1,   159,  1204,
      -1,   158,  1204,    -1,    -1,  1187,    -1,  1188,    -1,  1187,
    1188,    -1,  1197,  1189,    -1,    -1,   616,  1204,    -1,   516,
    1186,  1196,    -1,   515,  1424,  1196,    -1,   514,  1195,  1194,
    1193,  1196,    -1,    -1,   150,   836,    -1,   150,   836,     5,
     836,    -1,   611,    -1,   612,    -1,   613,    -1,   614,    -1,
    1090,    -1,    -1,   519,    -1,  1198,    -1,  1197,     5,  1198,
      -1,   843,  1231,    -1,   607,   427,   836,   388,  1216,    -1,
      62,  1216,    -1,   493,   427,    20,   388,  1216,    -1,   409,
     427,    20,   388,  1216,    -1,   384,   427,   836,   388,  1216,
      -1,   586,   427,   836,   388,  1216,    -1,   599,   427,   836,
     388,  1216,    -1,   598,   427,   836,   388,  1216,    -1,    -1,
     457,  1201,    -1,  1202,    -1,  1201,  1202,    -1,   224,    25,
      -1,   215,    25,    -1,   298,    25,    -1,   181,    25,    -1,
     253,    25,    -1,   173,    -1,   340,    24,    -1,   340,  1090,
      -1,   174,    24,    -1,   157,    24,    -1,  1207,    -1,  1203,
    1207,    -1,  1205,   106,    -1,  1205,   108,    -1,  1205,   107,
      -1,  1205,    -1,   941,    -1,    25,    -1,    -1,   457,  1203,
      -1,   224,  1204,    -1,   215,  1204,    -1,   298,  1204,    -1,
     181,  1204,    -1,   253,  1204,    -1,   254,  1204,    -1,   626,
      24,    -1,   627,  1204,    -1,   631,    -1,   628,    -1,   629,
      -1,   630,    -1,   635,    -1,   632,    -1,   633,    -1,   634,
      -1,    75,  1204,    -1,    76,  1204,    -1,    77,  1204,    -1,
     340,    24,    -1,   174,    24,    -1,   396,    -1,    71,    -1,
      72,    -1,    -1,   511,   617,  1117,    -1,   132,  1117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   461,  1210,   935,   427,
    1211,  1107,   388,  1212,   751,  1213,  1169,  1214,  1170,  1215,
     236,    -1,    -1,   523,   836,    -1,   513,  1218,    -1,    -1,
    1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,  1220,
     935,   427,  1221,  1107,   388,  1222,   751,  1223,  1226,  1224,
    1170,  1225,   236,    -1,  1206,  1208,    -1,    -1,    -1,    -1,
     152,   427,    24,     5,  1228,   704,  1229,   388,  1230,   702,
      -1,    -1,   380,    -1,   380,   215,    25,    -1,   380,   215,
    1090,    -1,   605,   843,    -1,   605,   843,   341,  1090,    -1,
     605,   843,   160,    -1,   605,   843,   575,    -1,   605,   843,
     542,    -1,  1234,    -1,   170,    -1,   320,    -1,   278,    -1,
    1241,    -1,  1236,    -1,    -1,    -1,   203,  1237,  1373,   427,
    1238,  1245,   388,    -1,    -1,    -1,   129,  1239,  1373,   427,
    1240,  1245,   388,  1242,    -1,   101,  1243,   388,    -1,    52,
     936,    -1,    -1,   265,    -1,  1244,    -1,  1243,     5,  1244,
      -1,   935,   585,    -1,   935,   536,    -1,   935,    -1,  1246,
      -1,  1245,     5,  1246,    -1,  1326,    -1,  1324,    -1,   118,
     935,    -1,   176,    -1,    43,   935,  1249,    -1,  1250,    -1,
    1249,     5,  1250,    -1,  1251,    -1,  1254,    -1,  1257,    -1,
    1262,    -1,  1263,    -1,  1261,    -1,  1260,    -1,   582,  1252,
      -1,   582,   427,  1253,   388,    -1,  1246,    -1,  1246,   662,
     935,    -1,  1252,    -1,  1253,     5,  1252,    -1,   539,  1256,
      -1,   539,   427,  1255,   388,    -1,  1256,    -1,  1255,     5,
    1256,    -1,   935,    -1,   451,  1259,    -1,   451,   427,  1258,
     388,    -1,  1259,    -1,  1258,     5,  1259,    -1,  1246,    -1,
      83,    -1,    84,    -1,    82,    25,    -1,    54,  1330,    -1,
      54,   427,  1264,   388,    -1,    55,  1265,    -1,    55,   427,
    1264,   388,    -1,  1330,    -1,  1264,     5,  1330,    -1,   935,
      -1,   262,    -1,   228,    -1,   162,  1268,    -1,   139,    -1,
     127,    -1,   117,    -1,   115,    -1,   119,    -1,   175,  1430,
      -1,   227,  1267,   456,  1424,   624,  1424,    -1,   295,   928,
     456,  1424,   624,  1424,    -1,    -1,  1430,    -1,    -1,   843,
      -1,   520,   843,    -1,   226,    -1,    -1,   245,  1272,  1373,
    1275,  1273,    -1,    -1,   476,  1274,   427,  1277,   388,    -1,
    1410,    -1,    -1,   427,  1276,   388,    -1,  1376,    -1,  1276,
       5,  1376,    -1,  1278,    -1,  1277,     5,  1278,    -1,  1416,
      -1,   480,    -1,    -1,    -1,   497,  1280,  1282,  1281,  1283,
      -1,  1287,   929,    -1,   929,    -1,    -1,    -1,   551,  1284,
    1112,    -1,    -1,    -1,   551,  1286,  1112,    -1,   498,    -1,
     552,    -1,   559,    -1,   371,    -1,   338,    -1,   392,    -1,
     374,   843,    -1,   347,   843,    -1,   234,  1373,   147,   929,
      -1,   234,  1373,  1346,    -1,   511,   617,  1291,    -1,  1292,
      -1,  1291,     5,  1292,    -1,  1293,  1294,    -1,    25,    -1,
    1376,    -1,    -1,   585,    -1,   536,    -1,   273,    -1,   306,
      -1,    -1,   323,    -1,   353,  1299,  1297,    -1,  1462,    -1,
      24,    -1,    -1,  1429,  1301,  1302,    -1,  1331,    -1,  1335,
      -1,  1296,    -1,  1431,    -1,  1295,    -1,  1288,    -1,  1289,
      -1,  1279,    -1,  1271,    -1,  1270,    -1,  1400,    -1,  1446,
      -1,   502,  1305,   623,  1373,   624,  1310,  1304,    -1,    -1,
     138,    -1,   165,    -1,  1306,    -1,  1307,    -1,  1306,     5,
    1307,    -1,   468,    -1,   446,    -1,   435,    -1,   475,  1308,
      -1,    -1,   427,  1309,   388,    -1,  1376,    -1,  1309,     5,
    1376,    -1,  1311,    -1,  1310,     5,  1311,    -1,   459,    -1,
    1374,    -1,   232,  1373,  1313,   615,  1410,  1315,    -1,    -1,
     427,  1314,   388,    -1,  1376,    -1,  1314,     5,  1376,    -1,
      -1,   137,    -1,   489,   427,  1349,   388,    -1,   242,   427,
    1319,   388,  1318,    -1,   293,  1320,    -1,  1321,    -1,  1373,
      -1,  1373,   427,  1321,   388,    -1,  1376,    -1,  1321,     5,
    1376,    -1,   473,   427,  1323,   388,    -1,   255,   427,  1323,
     388,    -1,  1376,    -1,  1323,     5,  1376,    -1,  1322,    -1,
    1317,    -1,  1316,    -1,   396,  1379,    -1,   204,    -1,   935,
    1365,  1327,  1328,    -1,    -1,  1325,    -1,    -1,  1329,    -1,
    1330,    -1,  1329,  1330,    -1,   369,    -1,   155,    -1,   473,
      -1,  1318,    -1,   489,   427,  1349,   388,    -1,   116,  1332,
    1334,    -1,  1333,    -1,  1374,    -1,  1335,    -1,  1334,  1335,
      -1,  1312,    -1,  1303,    -1,   444,  1349,    -1,   365,  1338,
      -1,  1415,    -1,  1338,     5,  1415,    -1,   523,  1349,    -1,
     544,  1341,    -1,  1342,    -1,  1341,     5,  1342,    -1,  1343,
      -1,   512,  1343,    -1,   512,   427,  1344,   388,    -1,  1373,
      -1,  1373,  1378,    -1,  1342,    -1,  1344,     5,  1342,    -1,
    1340,  1346,  1347,  1348,    -1,    -1,  1339,    -1,    -1,  1337,
      -1,    -1,  1336,    -1,  1350,    -1,  1349,     6,  1350,    -1,
    1351,    -1,  1350,     7,  1351,    -1,  1352,    -1,   600,  1352,
      -1,  1363,    -1,   427,  1349,   388,    -1,   439,  1411,    -1,
     291,  1411,    -1,    -1,   438,  1356,    -1,  1420,    -1,   935,
      -1,  1420,    -1,  1416,   621,   427,  1358,   388,    -1,  1416,
     621,  1411,    -1,  1416,   425,   427,  1358,   388,    -1,  1416,
     425,  1411,    -1,  1359,    -1,  1358,     5,  1359,    -1,  1466,
      -1,  1379,    -1,    -1,   600,    -1,  1416,  1360,   383,    -1,
    1416,  1360,   246,    -1,  1416,  1362,  1416,    -1,  1416,  1360,
     385,  1416,     7,  1416,    -1,  1416,   554,  1355,  1354,    -1,
    1416,   368,  1355,  1354,    -1,  1416,  1360,     9,  1355,  1354,
      -1,    13,    -1,    16,    -1,    11,    -1,    12,    -1,   249,
      -1,     9,    -1,    15,    -1,    14,    -1,  1361,    -1,  1357,
      -1,  1353,    -1,    -1,   583,    -1,   356,    -1,   473,    -1,
    1366,    -1,  1367,    -1,  1369,    -1,   533,    -1,   533,   427,
    1370,   388,    -1,   407,   427,  1371,  1368,   388,    -1,   469,
      -1,   394,   427,  1371,  1368,   388,    -1,   509,   427,  1371,
    1368,   388,    -1,   535,    -1,   404,    -1,   376,    -1,   354,
    1386,   624,  1387,    -1,   354,    -1,   366,  1386,   624,  1387,
      -1,   366,    -1,   366,  1386,   427,    25,   388,   624,  1387,
      -1,   572,    -1,   530,    -1,   420,    -1,   420,   427,    25,
     388,    -1,   420,   427,    25,     5,    25,   388,    -1,    -1,
       5,  1372,    -1,   499,   427,  1371,   388,    -1,   563,    -1,
     296,    -1,   499,    -1,    61,    -1,    25,    -1,    25,    -1,
      25,    -1,    24,   618,   935,    -1,    24,    -1,   935,    -1,
     935,   587,   935,    -1,   935,    -1,    -1,   455,    25,   423,
      -1,   455,    25,     5,    25,   423,    -1,  1377,    -1,   610,
    1377,    -1,   935,  1375,    -1,  1373,   618,   935,  1375,    -1,
    1373,   618,    20,    -1,   935,    -1,    24,    -1,   407,    -1,
     941,    -1,    25,    -1,  1381,    -1,   392,  1383,    -1,   392,
    1382,    -1,    -1,  1386,   624,  1387,    -1,    -1,  1384,   624,
    1384,    -1,   579,    -1,   510,    -1,   588,    -1,   550,    -1,
     450,    -1,   467,    -1,   363,    -1,   363,   427,    25,   388,
      -1,   579,    -1,   510,    -1,   588,    -1,   550,    -1,   450,
      -1,   467,    -1,   363,    -1,   363,   427,    25,   388,    -1,
     579,    -1,   510,    -1,   588,    -1,   550,    -1,   450,    -1,
     467,    -1,   363,    -1,   579,    -1,   510,    -1,   588,    -1,
     550,    -1,   450,    -1,   467,    -1,   363,    -1,   935,    -1,
      24,    -1,  1429,   500,   929,    -1,    -1,  1429,   395,   929,
     433,   593,  1398,  1391,  1395,    -1,    -1,  1429,   395,   929,
     433,    98,   593,  1399,  1392,  1395,    -1,    -1,  1429,   395,
     929,   133,  1399,  1393,  1395,    -1,    -1,  1429,   395,   929,
     134,    98,   593,  1399,  1394,  1395,    -1,    -1,   285,    -1,
     284,  1396,    -1,  1397,    -1,  1396,     5,  1397,    -1,   935,
      -1,   935,   618,   935,    -1,    24,   618,   935,   618,   935,
      -1,  1399,    -1,  1271,    -1,  1147,    -1,  1401,    -1,  1401,
    1395,    -1,    -1,    -1,   468,  1412,  1402,  1413,  1403,  1409,
    1345,  1407,    -1,   468,  1412,  1413,  1345,  1407,    -1,  1406,
      -1,  1424,    -1,   468,  1412,  1413,  1409,  1345,  1407,    -1,
      -1,   522,  1364,  1405,    -1,  1290,    -1,   328,  1408,  1242,
      -1,  1290,   328,  1408,  1242,    -1,   935,    -1,    -1,   551,
    1112,    -1,   468,  1412,  1413,  1345,    -1,   427,   468,  1412,
    1413,  1345,   388,    -1,    -1,   583,    -1,   356,    -1,   473,
      -1,  1414,    -1,  1413,     5,  1414,    -1,  1416,    -1,  1416,
     935,    -1,  1416,    -1,  1417,    -1,    18,  1417,    -1,    17,
    1417,    -1,  1418,    -1,  1466,    -1,  1411,    -1,   610,   935,
      -1,   610,   935,   618,   935,    -1,  1417,    19,  1416,    -1,
    1417,  1438,    -1,  1417,    20,  1416,    -1,  1417,    17,  1416,
      -1,  1417,    18,  1416,    -1,  1379,    -1,   481,    -1,   424,
      -1,   574,    -1,    20,    -1,    62,    -1,   586,   427,  1364,
    1416,   388,    -1,   598,   427,  1364,  1416,   388,    -1,   599,
     427,  1364,  1416,   388,    -1,   607,   427,  1364,  1416,   388,
      -1,   493,   427,  1364,  1416,   388,    -1,   935,   427,  1419,
     388,    -1,   535,   427,  1419,   388,    -1,   427,  1416,   388,
      -1,   440,   427,  1439,   388,    -1,  1416,    -1,  1419,     5,
    1416,    -1,    -1,  1379,    -1,  1429,   343,  1428,  1423,  1405,
      -1,  1429,   332,  1428,  1423,   245,  1373,  1425,    -1,  1429,
     332,  1428,  1423,  1090,    -1,    -1,   318,  1424,    -1,    24,
      -1,  1090,    -1,    -1,   427,  1426,   388,    -1,  1427,    -1,
    1426,     5,  1427,    -1,   935,    -1,    24,    -1,  1090,    -1,
      -1,   264,  1430,   593,    -1,   936,    -1,  1436,    -1,  1435,
      -1,  1432,    -1,   313,  1433,   624,  1433,    -1,   294,  1433,
     618,  1434,   624,  1434,    -1,   935,    -1,   935,    -1,   218,
     786,    -1,   289,   786,  1437,    -1,   268,    -1,   172,    -1,
      90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,   392,     5,  1386,   624,  1387,    -1,  1376,     5,
    1386,   624,  1387,    -1,   392,  1386,   624,  1387,    -1,    -1,
     606,  1441,  1442,   186,    -1,  1443,    -1,  1442,  1443,    -1,
      32,    -1,  1444,    -1,  1445,    -1,   187,  1466,    -1,   551,
    1112,    -1,    -1,    -1,   475,  1373,  1447,  1450,  1448,  1449,
      -1,    -1,   147,   929,    -1,   523,  1349,    -1,    50,  1454,
     388,    13,   427,  1455,   388,    -1,    46,  1455,   388,    -1,
      47,  1455,   388,    -1,   581,  1451,    -1,    49,  1455,    -1,
      48,  1455,    -1,  1453,    -1,  1451,     5,  1453,    -1,  1376,
      -1,  1452,    13,  1456,    -1,  1452,    -1,  1454,     5,  1452,
      -1,  1456,    -1,  1455,     5,  1456,    -1,   480,    -1,  1457,
      -1,  1458,    -1,    18,  1458,    -1,    17,  1458,    -1,  1460,
      -1,  1411,    -1,   610,   935,    -1,   610,   935,   618,   935,
      -1,  1459,    -1,  1379,    -1,   481,    -1,   424,    -1,   574,
      -1,    62,    -1,  1458,    19,  1457,    -1,  1458,  1438,    -1,
    1458,    20,  1457,    -1,  1458,    17,  1457,    -1,  1458,    18,
    1457,    -1,   586,   427,  1364,  1457,   388,    -1,   598,   427,
    1364,  1457,   388,    -1,   599,   427,  1364,  1457,   388,    -1,
     607,   427,  1364,  1457,   388,    -1,   493,   427,  1364,  1457,
     388,    -1,   935,   427,  1461,   388,    -1,   535,   427,  1461,
     388,    -1,   427,  1457,   388,    -1,   440,   427,  1439,   388,
      -1,  1466,    -1,  1457,    -1,  1461,     5,  1457,    -1,  1463,
      -1,   187,  1464,    -1,  1464,    -1,  1099,    -1,   935,    -1,
    1464,   618,  1465,    -1,    24,   618,  1464,   618,  1465,    -1,
      20,    -1,  1120,    -1,   935,    -1,  1463,    -1,  1463,   417,
    1463,    -1,   124,  1468,    -1,   128,  1468,    -1,   123,  1468,
      -1,    44,    -1,   163,  1468,    -1,   121,  1468,    -1,    45,
      -1,   146,  1468,    -1,   145,  1468,    -1,   120,  1468,    -1,
     352,    -1,   619,   624,  1469,    -1,   545,  1469,    -1,   570,
      -1,   531,  1470,    -1,   935,    -1,   587,   935,    -1,   935,
      -1,    -1,    -1,   524,  1472,   843,  1473,  1487,   322,    -1,
      -1,   657,  1477,    -1,    -1,   660,    -1,   178,    -1,   274,
     930,    -1,    67,   930,    -1,   304,    -1,   303,    -1,   305,
     932,  1474,  1475,    -1,   490,  1477,  1475,    -1,   927,    -1,
    1477,     5,   927,    -1,   100,    -1,   130,   930,    -1,   843,
     564,     5,   843,   389,    -1,   506,   843,    -1,   261,   930,
      -1,    99,  1482,     8,  1483,  1481,    -1,    -1,   544,   843,
      -1,   935,    -1,   935,    -1,   244,   930,    -1,   247,   930,
     624,   843,     5,   843,    -1,   247,   930,   617,   843,     5,
     843,    -1,    26,    -1,    -1,  1489,    -1,  1490,  1196,    -1,
    1488,    -1,  1489,  1488,    -1,    -1,  1491,  1492,    -1,   667,
      -1,   668,    -1,   669,    -1,   670,    -1,   687,    -1,   709,
      -1,   723,    -1,   724,    -1,   730,    -1,   731,    -1,   750,
      -1,   818,    -1,   819,    -1,   820,    -1,   821,    -1,   832,
      -1,   833,    -1,   834,    -1,   835,    -1,   887,    -1,   891,
      -1,   921,    -1,   942,    -1,   943,    -1,   946,    -1,   947,
      -1,   948,    -1,   949,    -1,   962,    -1,   970,    -1,   991,
      -1,   992,    -1,   994,    -1,   998,    -1,  1015,    -1,  1016,
      -1,  1020,    -1,  1021,    -1,  1022,    -1,  1023,    -1,  1031,
      -1,  1046,    -1,  1059,    -1,  1070,    -1,  1071,    -1,  1072,
      -1,  1083,    -1,  1123,    -1,  1126,    -1,  1128,    -1,  1134,
      -1,  1135,    -1,  1138,    -1,  1141,    -1,  1144,    -1,  1146,
      -1,  1148,    -1,  1150,    -1,  1157,    -1,  1162,    -1,  1166,
      -1,  1167,    -1,  1168,    -1,  1180,    -1,  1232,    -1,  1233,
      -1,  1235,    -1,  1247,    -1,  1248,    -1,  1266,    -1,  1269,
      -1,  1298,    -1,  1300,    -1,  1389,    -1,  1390,    -1,  1421,
      -1,  1422,    -1,  1440,    -1,  1467,    -1,  1471,    -1,  1476,
      -1,  1478,    -1,  1480,    -1,  1484,    -1,  1485,    -1
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
    3368,  3370,  3372,  3376,  3385,  3385,  3446,  3459,  3466,  3466,
    3470,  3475,  3481,  3485,  3489,  3495,  3499,  3503,  3509,  3509,
    3517,  3518,  3522,  3522,  3526,  3527,  3530,  3533,  3533,  3536,
    3538,  3538,  3541,  3543,  3543,  3544,  3546,  3546,  3555,  3553,
    3565,  3565,  3565,  3568,  3570,  3568,  3577,  3580,  3586,  3597,
    3597,  3601,  3607,  3607,  3611,  3612,  3623,  3624,  3626,  3628,
    3633,  3633,  3637,  3636,  3643,  3642,  3648,  3648,  3653,  3653,
    3659,  3659,  3664,  3664,  3669,  3669,  3674,  3674,  3677,  3677,
    3680,  3680,  3683,  3683,  3725,  3726,  3734,  3735,  3744,  3749,
    3754,  3755,  3756,  3760,  3759,  3770,  3775,  3780,  3780,  3791,
    3796,  3797,  3798,  3799,  3802,  3802,  3805,  3810,  3811,  3812,
    3813,  3814,  3815,  3816,  3817,  3818,  3823,  3823,  3825,  3828,
    3828,  3830,  3834,  3834,  3837,  3838,  3841,  3841,  3846,  3846,
    3849,  3850,  3851,  3852,  3853,  3854,  3855,  3856,  3857,  3858,
    3859,  3860,  3861,  3862,  3863,  3864,  3865,  3869,  3887,  3887,
    3887,  3913,  3924,  3931,  3937,  3943,  3949,  3960,  3983,  3982,
    3999,  3999,  4003,  4004,  4012,  4013,  4014,  4015,  4022,  4023,
    4025,  4026,  4030,  4035,  4036,  4037,  4038,  4039,  4040,  4041,
    4042,  4043,  4044,  4045,  4048,  4048,  4050,  4050,  4050,  4052,
    4056,  4056,  4065,  4070,  4086,  4092,  4064,  4106,  4120,  4130,
    4119,  4143,  4150,  4150,  4155,  4160,  4165,  4166,  4169,  4169,
    4169,  4172,  4172,  4180,  4186,  4200,  4204,  4217,  4199,  4235,
    4235,  4248,  4259,  4258,  4270,  4266,  4283,  4280,  4293,  4293,
    4295,  4296,  4298,  4299,  4302,  4303,  4304,  4306,  4311,  4316,
    4322,  4324,  4325,  4328,  4329,  4332,  4334,  4343,  4349,  4343,
    4360,  4361,  4365,  4365,  4375,  4375,  4387,  4390,  4394,  4398,
    4403,  4407,  4408,  4409,  4410,  4411,  4415,  4415,  4417,  4417,
    4420,  4429,  4477,  4477,  4480,  4484,  4488,  4530,  4572,  4573,
    4574,  4577,  4591,  4603,  4603,  4608,  4609,  4615,  4675,  4732,
    4737,  4744,  4749,  4757,  4763,  4792,  4795,  4796,  4837,  4880,
    4881,  4885,  4886,  4890,  4943,  4947,  4950,  4956,  4967,  4974,
    4982,  4982,  4985,  4986,  4987,  4988,  4989,  4992,  4995,  5001,
    5004,  5008,  5012,  5019,  5024,  5031,  5034,  5040,  5042,  5042,
    5042,  5046,  5066,  5073,  5080,  5083,  5097,  5104,  5105,  5108,
    5109,  5113,  5119,  5124,  5130,  5131,  5136,  5140,  5140,  5144,
    5145,  5148,  5149,  5153,  5161,  5164,  5170,  5171,  5173,  5175,
    5179,  5179,  5180,  5185,  5193,  5194,  5199,  5200,  5202,  5215,
    5217,  5218,  5220,  5223,  5226,  5229,  5233,  5236,  5239,  5243,
    5247,  5251,  5254,  5258,  5261,  5262,  5263,  5266,  5269,  5272,
    5275,  5278,  5281,  5284,  5300,  5308,  5308,  5310,  5317,  5324,
    5339,  5337,  5357,  5362,  5363,  5367,  5368,  5370,  5371,  5373,
    5373,  5381,  5390,  5390,  5400,  5401,  5404,  5405,  5408,  5412,
    5426,  5431,  5436,  5441,  5451,  5451,  5455,  5458,  5458,  5460,
    5470,  5479,  5486,  5488,  5492,  5495,  5495,  5499,  5498,  5502,
    5501,  5505,  5504,  5508,  5507,  5511,  5510,  5513,  5513,  5529,
    5528,  5550,  5551,  5552,  5553,  5554,  5555,  5558,  5558,  5564,
    5564,  5567,  5567,  5577,  5578,  5579,  5586,  5598,  5599,  5602,
    5603,  5606,  5609,  5609,  5614,  5618,  5623,  5629,  5630,  5631,
    5635,  5636,  5637,  5638,  5642,  5652,  5654,  5659,  5662,  5667,
    5673,  5680,  5687,  5696,  5703,  5710,  5717,  5724,  5733,  5733,
    5735,  5735,  5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,
    5746,  5747,  5750,  5750,  5753,  5754,  5755,  5756,  5759,  5759,
    5762,  5762,  5765,  5766,  5767,  5768,  5769,  5770,  5771,  5772,
    5774,  5775,  5776,  5777,  5779,  5780,  5781,  5782,  5784,  5785,
    5786,  5787,  5788,  5789,  5790,  5791,  5795,  5801,  5809,  5820,
    5829,  5840,  5844,  5848,  5854,  5819,  5867,  5870,  5878,  5890,
    5892,  5897,  5905,  5915,  5918,  5922,  5930,  5896,  5939,  5943,
    5947,  5951,  5943,  5961,  5962,  5963,  5964,  5969,  5971,  5974,
    5978,  5981,  5988,  5993,  5994,  5995,  6000,  6001,  6007,  6007,
    6007,  6012,  6012,  6012,  6023,  6024,  6030,  6031,  6037,  6038,
    6043,  6044,  6045,  6049,  6052,  6058,  6061,  6069,  6070,  6076,
    6083,  6086,  6095,  6098,  6101,  6104,  6107,  6110,  6113,  6120,
    6123,  6130,  6133,  6139,  6142,  6149,  6152,  6159,  6160,  6165,
    6169,  6172,  6178,  6181,  6187,  6194,  6195,  6199,  6205,  6208,
    6215,  6216,  6223,  6226,  6231,  6242,  6243,  6244,  6245,  6246,
    6247,  6248,  6249,  6250,  6253,  6256,  6262,  6262,  6268,  6268,
    6279,  6292,  6302,  6302,  6307,  6307,  6311,  6315,  6316,  6322,
    6323,  6328,  6332,  6339,  6342,  6349,  6353,  6348,  6365,  6369,
    6376,  6380,  6380,  6393,  6397,  6397,  6412,  6414,  6416,  6418,
    6420,  6422,  6424,  6426,  6432,  6442,  6449,  6454,  6455,  6459,
    6461,  6462,  6465,  6466,  6467,  6470,  6475,  6482,  6483,  6489,
    6501,  6502,  6505,  6505,  6510,  6515,  6520,  6521,  6524,  6525,
    6530,  6535,  6539,  6544,  6545,  6549,  6556,  6560,  6561,  6566,
    6568,  6572,  6573,  6577,  6578,  6579,  6580,  6584,  6585,  6590,
    6591,  6596,  6597,  6602,  6603,  6608,  6613,  6614,  6619,  6620,
    6624,  6625,  6630,  6637,  6642,  6647,  6651,  6652,  6657,  6658,
    6664,  6666,  6671,  6672,  6678,  6681,  6684,  6691,  6693,  6705,
    6710,  6711,  6714,  6716,  6723,  6726,  6732,  6736,  6740,  6744,
    6747,  6754,  6761,  6766,  6770,  6771,  6777,  6780,  6791,  6798,
    6804,  6807,  6814,  6821,  6827,  6828,  6834,  6835,  6836,  6839,
    6840,  6845,  6845,  6849,  6857,  6858,  6861,  6864,  6869,  6870,
    6875,  6878,  6884,  6887,  6893,  6896,  6902,  6905,  6912,  6913,
    6942,  6943,  6948,  6949,  6953,  6958,  6961,  6964,  6967,  6973,
    6974,  6978,  6981,  6984,  6985,  6990,  6993,  6996,  6999,  7002,
    7005,  7008,  7014,  7015,  7016,  7017,  7018,  7020,  7022,  7023,
    7028,  7031,  7035,  7041,  7042,  7043,  7044,  7056,  7057,  7058,
    7062,  7063,  7068,  7070,  7071,  7072,  7074,  7075,  7076,  7077,
    7079,  7080,  7082,  7083,  7085,  7086,  7087,  7088,  7090,  7094,
    7095,  7101,  7103,  7104,  7105,  7106,  7111,  7115,  7119,  7123,
    7124,  7128,  7129,  7139,  7147,  7148,  7149,  7153,  7156,  7161,
    7166,  7171,  7179,  7183,  7187,  7188,  7189,  7194,  7197,  7200,
    7204,  7205,  7209,  7210,  7214,  7214,  7214,  7214,  7214,  7214,
    7215,  7218,  7223,  7223,  7223,  7223,  7223,  7223,  7225,  7228,
    7234,  7234,  7234,  7234,  7234,  7234,  7234,  7235,  7235,  7235,
    7235,  7235,  7235,  7235,  7237,  7238,  7241,  7250,  7250,  7255,
    7255,  7261,  7261,  7266,  7266,  7273,  7274,  7275,  7278,  7278,
    7281,  7282,  7283,  7288,  7291,  7297,  7302,  7310,  7323,  7324,
    7321,  7342,  7352,  7355,  7360,  7372,  7375,  7379,  7382,  7383,
    7389,  7392,  7393,  7402,  7411,  7416,  7417,  7418,  7419,  7427,
    7430,  7436,  7439,  7450,  7459,  7462,  7465,  7471,  7477,  7480,
    7483,  7486,  7492,  7494,  7496,  7498,  7500,  7502,  7503,  7504,
    7505,  7506,  7507,  7508,  7510,  7512,  7514,  7516,  7518,  7520,
    7522,  7523,  7528,  7529,  7535,  7536,  7539,  7548,  7552,  7559,
    7559,  7563,  7563,  7568,  7568,  7572,  7572,  7576,  7582,  7582,
    7585,  7585,  7591,  7598,  7599,  7600,  7604,  7605,  7608,  7609,
    7613,  7619,  7629,  7630,  7638,  7639,  7640,  7641,  7642,  7643,
    7647,  7648,  7649,  7653,  7653,  7665,  7666,  7670,  7671,  7672,
    7676,  7682,  7769,  7773,  7769,  7782,  7786,  7792,  7800,  7810,
    7820,  7832,  7835,  7854,  7880,  7883,  7889,  7892,  7897,  7900,
    7908,  7916,  7929,  7932,  7940,  7943,  7946,  7954,  7958,  7961,
    7964,  7967,  7971,  7972,  7973,  7974,  7975,  7981,  7982,  7983,
    7984,  7985,  7986,  7987,  7988,  7989,  7990,  7991,  7992,  7993,
    7994,  7998,  8004,  8005,  8017,  8029,  8029,  8033,  8034,  8035,
    8036,  8040,  8041,  8042,  8047,  8061,  8112,  8114,  8116,  8118,
    8122,  8127,  8129,  8132,  8134,  8136,  8140,  8143,  8148,  8153,
    8157,  8166,  8167,  8171,  8183,  8186,  8182,  8205,  8205,  8209,
    8210,  8213,  8214,  8215,  8216,  8217,  8218,  8219,  8224,  8225,
    8229,  8232,  8237,  8241,  8246,  8250,  8255,  8259,  8262,  8266,
    8269,  8274,  8278,  8289,  8295,  8295,  8296,  8297,  8304,  8313,
    8313,  8315,  8316,  8317,  8318,  8319,  8320,  8321,  8322,  8323,
    8324,  8325,  8326,  8327,  8328,  8329,  8330,  8331,  8332,  8333,
    8334,  8335,  8336,  8337,  8338,  8339,  8340,  8341,  8342,  8343,
    8344,  8345,  8346,  8347,  8348,  8349,  8350,  8351,  8352,  8353,
    8354,  8355,  8356,  8357,  8358,  8359,  8360,  8361,  8362,  8363,
    8364,  8365,  8366,  8367,  8368,  8369,  8370,  8371,  8372,  8373,
    8374,  8375,  8376,  8377,  8378,  8379,  8380,  8381,  8382,  8383,
    8384,  8385,  8386,  8387,  8388,  8389,  8390,  8391,  8392,  8393,
    8394,  8395,  8396,  8397,  8398,  8399
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
  "real_number", "goto_cmd", "check_menu_cmd", "menu_item_list", 
  "menu_item", "uncheck_menu_cmd", "disable_cmd", "enable_cmd", 
  "msg_box_cmd", "@82", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@83", "op_else", "@84", "@85", "@86", "import_m", 
  "module_import", "init_cmd", "@87", "init_tab_list", "init_tab", 
  "end_input", "opt_defs", "field_commands", "field_command", "@88", 
  "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", 
  "bef_field_list", "aft_field_list", "next_field_cmd", "next_form_cmd", 
  "next_field", "input_cmd", "@99", "inp_rest", "@100", "scroll_cmd", 
  "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@101", "key_val", 
  "@102", "accept_key", "single_key_val", "@103", "key_do", 
  "key_value_list", "key_value", "@104", "key_value_1", "label_cmd", 
  "let_cmd", "@105", "@106", "op_expr_null", "linked_cmd", 
  "linked_del_cmd", "linked_upd_cmd", "locate_cmd", "module", "@107", 
  "op_module_header", "module_header", "module_entry", "func_main_def", 
  "func_or_main2", "at_term_cmd", "func_or_main", "module_code", 
  "op_code", "module_define_section", "ldeffunction", "func_def", "@108", 
  "@109", "@110", "@111", "end_func_command", "main_def", "@112", "@113", 
  "return_cmd", "op_fgl_expr_list", "db_section", 
  "module_globals_section", "actual_globals_section", "xglobals_entry", 
  "globals_entry", "@114", "glob_section", "mem_func_def", "@115", "@116", 
  "@117", "menu_cmd", "@118", "end_menu_command", "menu_block_command", 
  "@119", "@120", "@121", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@122", "@123", "menu_handler_elements", 
  "menu_handler_element", "@124", "@125", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "@126", "op_msg_wait", "msg_wait", 
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
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@127", 
  "gui_prompt_cmd", "opt_char", "prompt_key_sec", "prompt_key_clause", 
  "on_key_command_prompt", "@128", "prompt_title", "put_cmd", "@129", 
  "put_from", "put_val_list", "put_val", "start_cmd", "rout", "rep_name", 
  "op_values", "output_cmd", "finish_cmd", "term_rep_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@130", "@131", "@132", "@133", "@134", "@135", "@136", "report_cmd", 
  "need_command", "@137", "op_lines", "skip_command", "@138", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@139", "@140", "@141", "@142", "@143", 
  "@144", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@145", "@146", "@147", "@148", "@149", "@150", "pdf_report_section", 
  "pdf_functions", "@151", "@152", "@153", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@154", "@155", 
  "@156", "@157", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@158", "ins_2_ss", "@159", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@160", "@161", "fetch_part", "opt_into_fetch_part", 
  "@162", "opt_foreach_into_fetch_part", "@163", "fetch_place", 
  "delete_statement_position", "delete_statement_search_ss", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "var_ident_qchar", "sql_cmd", 
  "@164", "sql_commands", "privilege_definition", "op_with_grant_option", 
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
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@165", 
  "@166", "@167", "@168", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@169", "@170", 
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
  "units_qual", "extend_qual", "sql_block_cmd", "@171", "sql_block", 
  "sql_block_entry", "in_var", "sql_block_into", "update_statement_ss", 
  "@172", "@173", "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind_ss", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@174", "@175", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@176", "commands_all1", 0
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
     939,   939,   939,   940,   941,   941,   942,   943,   944,   944,
     945,   946,   947,   947,   947,   948,   948,   948,   950,   949,
     951,   951,   952,   952,   953,   953,   954,   955,   955,   956,
     957,   957,   958,   959,   959,   960,   961,   961,   963,   962,
     964,   965,   964,   966,   967,   964,   968,   968,   969,   971,
     970,   970,   972,   972,   973,   973,   974,   974,   975,   975,
     976,   976,   978,   977,   979,   977,   980,   977,   981,   977,
     982,   977,   983,   977,   984,   977,   985,   977,   986,   977,
     987,   977,   988,   977,   989,   989,   990,   990,   991,   992,
     993,   993,   993,   995,   994,   996,   996,   997,   996,   998,
     999,   999,   999,   999,  1000,  1000,  1001,  1002,  1002,  1002,
    1002,  1002,  1002,  1002,  1002,  1002,  1004,  1003,  1003,  1006,
    1005,  1007,  1009,  1008,  1010,  1010,  1011,  1011,  1013,  1012,
    1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,
    1014,  1014,  1014,  1014,  1014,  1014,  1014,  1015,  1017,  1018,
    1016,  1019,  1019,  1020,  1021,  1022,  1023,  1023,  1025,  1024,
    1026,  1026,  1027,  1027,  1028,  1028,  1028,  1028,  1029,  1029,
    1030,  1030,  1031,  1032,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1033,  1033,  1034,  1034,  1034,  1035,
    1036,  1036,  1038,  1039,  1040,  1041,  1037,  1042,  1044,  1045,
    1043,  1046,  1047,  1047,  1048,  1049,  1050,  1050,  1051,  1051,
    1051,  1053,  1052,  1054,  1054,  1056,  1057,  1058,  1055,  1060,
    1059,  1061,  1063,  1062,  1064,  1062,  1065,  1062,  1066,  1066,
    1067,  1067,  1068,  1068,  1069,  1069,  1069,  1070,  1071,  1072,
    1073,  1073,  1073,  1074,  1074,  1075,  1075,  1077,  1078,  1076,
    1079,  1079,  1081,  1080,  1082,  1080,  1083,  1084,  1084,  1084,
    1084,  1085,  1085,  1085,  1085,  1085,  1087,  1086,  1088,  1088,
    1089,  1090,  1091,  1091,  1092,  1093,  1093,  1093,  1093,  1093,
    1093,  1094,  1095,  1096,  1096,  1097,  1097,  1098,  1099,  1100,
    1100,  1101,  1101,  1102,  1103,  1104,  1104,  1104,  1104,  1104,
    1104,  1105,  1105,  1106,  1107,  1107,  1108,  1108,  1109,  1109,
    1110,  1110,  1111,  1111,  1111,  1111,  1111,  1112,  1112,  1113,
    1113,  1114,  1114,  1115,  1116,  1117,  1117,  1118,  1119,  1119,
    1119,  1120,  1121,  1121,  1122,  1122,  1123,  1124,  1124,  1125,
    1125,  1126,  1127,  1128,  1129,  1129,  1130,  1131,  1131,  1132,
    1132,  1133,  1133,  1134,  1135,  1135,  1136,  1136,  1136,  1136,
    1137,  1137,  1137,  1138,  1139,  1139,  1140,  1140,  1140,  1141,
    1142,  1142,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,
    1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,
    1143,  1143,  1143,  1143,  1144,  1145,  1145,  1146,  1146,  1147,
    1149,  1148,  1150,  1151,  1151,  1152,  1152,  1153,  1153,  1155,
    1154,  1156,  1158,  1157,  1159,  1159,  1160,  1160,  1161,  1161,
    1162,  1162,  1162,  1162,  1163,  1163,  1164,  1165,  1165,  1166,
    1167,  1168,  1169,  1170,  1170,  1171,  1171,  1173,  1172,  1174,
    1172,  1175,  1172,  1176,  1172,  1177,  1172,  1178,  1172,  1179,
    1172,  1180,  1180,  1180,  1180,  1180,  1180,  1182,  1181,  1183,
    1183,  1185,  1184,  1184,  1184,  1184,  1184,  1186,  1186,  1187,
    1187,  1188,  1189,  1189,  1190,  1191,  1192,  1193,  1193,  1193,
    1194,  1194,  1194,  1194,  1195,  1196,  1196,  1197,  1197,  1198,
    1199,  1199,  1199,  1199,  1199,  1199,  1199,  1199,  1200,  1200,
    1201,  1201,  1202,  1202,  1202,  1202,  1202,  1202,  1202,  1202,
    1202,  1202,  1203,  1203,  1204,  1204,  1204,  1204,  1205,  1205,
    1206,  1206,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,
    1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,  1207,
    1207,  1207,  1207,  1207,  1207,  1207,  1208,  1208,  1208,  1210,
    1211,  1212,  1213,  1214,  1215,  1209,  1216,  1216,  1217,  1218,
    1218,  1220,  1221,  1222,  1223,  1224,  1225,  1219,  1226,  1228,
    1229,  1230,  1227,  1231,  1231,  1231,  1231,  1232,  1232,  1232,
    1232,  1232,  1233,  1234,  1234,  1234,  1235,  1235,  1237,  1238,
    1236,  1239,  1240,  1236,  1241,  1241,  1242,  1242,  1243,  1243,
    1244,  1244,  1244,  1245,  1245,  1246,  1246,  1247,  1247,  1248,
    1249,  1249,  1250,  1250,  1250,  1250,  1250,  1250,  1250,  1251,
    1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,  1256,
    1257,  1257,  1258,  1258,  1259,  1260,  1260,  1261,  1262,  1262,
    1263,  1263,  1264,  1264,  1265,  1266,  1266,  1266,  1266,  1266,
    1266,  1266,  1266,  1266,  1266,  1266,  1267,  1267,  1268,  1268,
    1269,  1270,  1272,  1271,  1274,  1273,  1273,  1275,  1275,  1276,
    1276,  1277,  1277,  1278,  1278,  1280,  1281,  1279,  1282,  1282,
    1283,  1284,  1283,  1285,  1286,  1285,  1287,  1287,  1287,  1287,
    1287,  1287,  1287,  1287,  1288,  1289,  1290,  1291,  1291,  1292,
    1293,  1293,  1294,  1294,  1294,  1295,  1296,  1297,  1297,  1298,
    1299,  1299,  1301,  1300,  1302,  1302,  1302,  1302,  1302,  1302,
    1302,  1302,  1302,  1302,  1302,  1302,  1303,  1304,  1304,  1305,
    1305,  1306,  1306,  1307,  1307,  1307,  1307,  1308,  1308,  1309,
    1309,  1310,  1310,  1311,  1311,  1312,  1313,  1313,  1314,  1314,
    1315,  1315,  1316,  1317,  1318,  1319,  1320,  1320,  1321,  1321,
    1322,  1322,  1323,  1323,  1324,  1324,  1324,  1325,  1325,  1326,
    1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,  1330,  1330,
    1330,  1331,  1332,  1333,  1334,  1334,  1335,  1335,  1336,  1337,
    1338,  1338,  1339,  1340,  1341,  1341,  1342,  1342,  1342,  1343,
    1343,  1344,  1344,  1345,  1346,  1346,  1347,  1347,  1348,  1348,
    1349,  1349,  1350,  1350,  1351,  1351,  1352,  1352,  1353,  1353,
    1354,  1354,  1355,  1355,  1356,  1357,  1357,  1357,  1357,  1358,
    1358,  1359,  1359,  1360,  1360,  1361,  1361,  1361,  1361,  1361,
    1361,  1361,  1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1363,  1363,  1363,  1364,  1364,  1364,  1364,  1365,  1365,  1365,
    1366,  1366,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,
    1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1368,
    1368,  1369,  1369,  1369,  1369,  1369,  1370,  1371,  1372,  1373,
    1373,  1373,  1373,  1374,  1375,  1375,  1375,  1376,  1376,  1377,
    1377,  1377,  1378,  1379,  1379,  1379,  1379,  1379,  1380,  1381,
    1382,  1382,  1383,  1383,  1384,  1384,  1384,  1384,  1384,  1384,
    1384,  1384,  1385,  1385,  1385,  1385,  1385,  1385,  1385,  1385,
    1386,  1386,  1386,  1386,  1386,  1386,  1386,  1387,  1387,  1387,
    1387,  1387,  1387,  1387,  1388,  1388,  1389,  1391,  1390,  1392,
    1390,  1393,  1390,  1394,  1390,  1395,  1395,  1395,  1396,  1396,
    1397,  1397,  1397,  1398,  1398,  1399,  1399,  1400,  1402,  1403,
    1401,  1404,  1405,  1405,  1406,  1407,  1407,  1407,  1407,  1407,
    1408,  1409,  1409,  1410,  1411,  1412,  1412,  1412,  1412,  1413,
    1413,  1414,  1414,  1415,  1416,  1416,  1416,  1417,  1417,  1417,
    1417,  1417,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1419,  1419,  1420,  1420,  1421,  1422,  1422,  1423,
    1423,  1424,  1424,  1425,  1425,  1426,  1426,  1427,  1428,  1428,
    1429,  1429,  1430,  1431,  1431,  1431,  1432,  1432,  1433,  1434,
    1435,  1436,  1437,  1437,  1438,  1438,  1438,  1438,  1438,  1438,
    1439,  1439,  1439,  1441,  1440,  1442,  1442,  1443,  1443,  1443,
    1444,  1445,  1447,  1448,  1446,  1449,  1449,  1449,  1450,  1450,
    1450,  1450,  1450,  1450,  1451,  1451,  1452,  1453,  1454,  1454,
    1455,  1455,  1456,  1456,  1457,  1457,  1457,  1458,  1458,  1458,
    1458,  1458,  1458,  1458,  1458,  1458,  1458,  1459,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,
    1459,  1460,  1461,  1461,  1462,  1463,  1463,  1464,  1464,  1464,
    1464,  1465,  1465,  1465,  1466,  1466,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1467,  1468,  1468,  1468,  1468,
    1468,  1469,  1469,  1470,  1472,  1473,  1471,  1474,  1474,  1475,
    1475,  1476,  1476,  1476,  1476,  1476,  1476,  1476,  1477,  1477,
    1478,  1478,  1479,  1479,  1480,  1480,  1481,  1481,  1482,  1483,
    1484,  1485,  1485,  1486,  1487,  1487,  1488,  1489,  1489,  1491,
    1490,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492
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
       6,     3,     6,     1,     1,     2,     2,     2,     1,     3,
       1,     2,     2,     2,     4,     2,     2,     4,     0,     8,
       0,     1,     1,     1,     0,     1,     2,     0,     1,     2,
       0,     1,     2,     0,     1,     3,     0,     2,     0,     7,
       0,     0,     3,     0,     0,     7,     5,     2,     2,     0,
       5,     4,     1,     3,     3,     3,     0,     2,     0,     1,
       1,     2,     0,     4,     0,     4,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     1,     3,     1,     3,     2,     4,
       1,     1,     1,     0,     4,     5,     6,     0,    10,     3,
       1,     1,     2,     2,     0,     2,     1,     2,     3,     3,
       3,     3,     1,     1,     1,     1,     0,     3,     1,     0,
       3,     2,     0,     3,     1,     3,     1,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     1,     1,     2,     2,     2,     3,     4,     0,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     0,     0,     0,     0,    13,     1,     0,     0,
       6,     2,     1,     2,     2,     1,     1,     2,     1,     1,
       1,     0,     3,     2,     1,     0,     0,     0,    14,     0,
       5,     1,     0,     3,     0,     7,     0,     5,     1,     2,
       0,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     0,     0,     7,
       1,     2,     0,     3,     0,     4,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     1,
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
       1,     1,     1,     1,     5,     1,     1,     2,     4,     1,
       0,    10,     5,     0,     1,     0,     2,     1,     2,     0,
       3,     1,     0,     4,     0,     2,     1,     3,     1,     1,
       3,     4,     4,     2,     1,     1,     1,     0,     1,     7,
       2,     2,     2,     2,     2,     1,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       1,     0,     4,     1,     2,     2,     2,     0,     1,     1,
       2,     2,     0,     2,     3,     3,     5,     0,     2,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     3,     2,
       5,     2,     5,     5,     5,     5,     5,     5,     0,     2,
       1,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     0,     3,     2,     0,
       0,     0,     0,     0,     0,    15,     0,     2,     2,     0,
       1,     0,     0,     0,     0,     0,     0,    15,     2,     0,
       0,     0,    10,     0,     1,     3,     3,     2,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     0,     0,     8,     3,     2,     0,     1,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     3,     1,     3,     2,     4,     1,     3,     1,
       2,     4,     1,     3,     1,     1,     1,     2,     2,     4,
       2,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     6,     6,     0,     1,     0,     1,
       2,     1,     0,     5,     0,     5,     1,     0,     3,     1,
       3,     1,     3,     1,     1,     0,     0,     5,     2,     1,
       0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     3,
       1,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     0,     3,     1,
       3,     1,     3,     1,     1,     6,     0,     3,     1,     3,
       0,     1,     4,     5,     2,     1,     1,     4,     1,     3,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     4,
       0,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       4,     3,     1,     1,     1,     2,     1,     1,     2,     2,
       1,     3,     2,     2,     1,     3,     1,     2,     4,     1,
       2,     1,     3,     4,     0,     1,     0,     1,     0,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     2,     2,
       0,     2,     1,     1,     1,     5,     3,     5,     3,     1,
       3,     1,     1,     0,     1,     3,     3,     3,     6,     4,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     1,     5,     5,     1,     1,     1,     4,
       1,     4,     1,     7,     1,     1,     1,     4,     6,     0,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     0,     3,     5,     1,     2,     2,
       4,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     8,     0,
       9,     0,     7,     0,     9,     0,     1,     2,     1,     3,
       1,     3,     5,     1,     1,     1,     1,     2,     0,     0,
       8,     5,     1,     1,     6,     0,     3,     1,     3,     4,
       1,     0,     2,     4,     6,     0,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       2,     4,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     5,     5,     4,     4,
       3,     4,     1,     3,     0,     1,     5,     7,     5,     0,
       2,     1,     1,     0,     3,     1,     3,     1,     1,     1,
       0,     3,     1,     1,     1,     1,     4,     6,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     4,     0,     4,     1,     2,     1,     1,     1,
       2,     2,     0,     0,     6,     0,     2,     2,     7,     3,
       3,     2,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     2,     2,     1,     1,     2,
       4,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     3,     5,     5,     5,     5,     5,     4,     4,     3,
       4,     1,     1,     3,     1,     2,     1,     1,     1,     3,
       5,     1,     1,     1,     1,     3,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     1,     3,     2,     1,
       2,     1,     2,     1,     0,     0,     6,     0,     2,     0,
       1,     1,     2,     2,     1,     1,     4,     3,     1,     3,
       1,     2,     5,     2,     2,     5,     0,     2,     1,     1,
       2,     6,     6,     1,     0,     1,     2,     1,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     780,     0,  1759,  1762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   831,   179,   804,   809,   177,
     182,   784,     0,   778,   781,   782,   785,   787,   830,   786,
     825,   826,   828,   183,   134,   131,     0,   127,   129,   128,
     132,  1803,   668,   611,  1766,     0,     0,  1769,     0,  1765,
    1761,  1758,  1756,  1757,  1764,  1763,  1760,   294,  1565,  1564,
     824,   175,   186,   178,   183,     1,   788,   783,   829,   827,
     805,   126,   130,   133,  1773,  1770,     0,  1771,  1768,     0,
       0,   590,     0,     0,   176,   834,   899,   591,   832,   623,
     891,     0,   892,   900,   898,   186,   180,   199,     0,   184,
     200,   229,     0,   811,  1181,     0,     0,   810,   135,  1169,
     818,     0,     0,   801,   803,   800,   802,   779,   789,   790,
     812,   793,   794,   795,   798,   796,   797,   799,  1772,  1767,
       0,   893,   833,     0,     0,   907,   905,   906,   895,   894,
     292,   186,  1105,   193,   187,   186,   192,   226,     0,   667,
       0,     0,     0,     0,   175,   540,   867,   791,     0,   326,
     312,   202,   263,   282,   303,   305,   302,     0,   324,     0,
     311,   304,   308,   314,   298,   313,   186,   315,   295,   318,
     296,   297,   904,   903,     0,    21,    22,    13,     0,   913,
       0,    15,     0,   911,     0,   293,     0,   185,  1106,   181,
       0,   199,   201,   259,   253,   254,   242,   219,   250,   202,
     221,   263,   282,   240,   243,   238,     0,   217,     0,   249,
     241,   246,   252,   234,   251,   186,   255,   186,   232,   233,
     230,   258,     0,     0,     0,     0,   819,   175,   175,     0,
       0,   203,     0,   316,     0,     0,   317,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,   901,     0,    16,
      17,    19,    18,    20,     0,    14,     0,   909,     0,   624,
     188,   191,     0,   189,   190,     0,   196,   195,   194,   197,
     186,     0,   186,   256,   257,     0,     0,   186,     0,     0,
       0,     0,   239,   227,  1182,     0,     0,  1170,  1809,   541,
     868,   813,     0,   208,   209,     0,   275,   277,   272,   273,
     269,   271,   268,   270,   267,     0,   277,   288,   289,   285,
     287,   284,   286,   279,     0,     0,     0,   328,     0,   331,
     333,   216,     0,   215,     0,     0,   186,    11,    12,   912,
       0,   896,   625,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   228,   231,   924,   666,   835,   924,
       0,  1807,  1809,  1105,  1660,   806,     0,   924,     0,     0,
     264,     0,     0,   274,   291,   265,   290,     0,   283,     0,
     306,     0,   300,     0,   325,     0,   330,   320,     0,     0,
     309,   299,   262,   319,     0,     0,     0,     0,     0,     0,
     244,     0,   236,   218,   204,     0,   247,   235,   260,   930,
       0,   925,   926,   924,     0,   820,  1808,  1806,     0,     0,
       0,     0,     0,     0,     0,     0,  1790,     0,  1271,  1270,
       0,  1272,     0,   376,  1269,  1211,     0,     5,  1268,   377,
     374,     0,   379,   173,   468,  1083,     0,     0,  1278,   123,
     373,   372,  1203,   367,     0,  1228,  1781,     0,   378,   345,
       0,     3,     2,     0,   375,  1208,     0,     0,   368,   365,
     380,     0,     0,     0,     0,  1276,  1266,   371,     0,     0,
       0,     0,     0,     0,     0,     0,  1265,     0,     0,     0,
     174,  1205,   364,   363,     0,     0,  1785,  1784,     0,     0,
       0,   136,  1204,   370,   369,     0,     0,   366,   886,   468,
       0,   536,     0,     0,     0,   468,     0,     0,     0,   468,
     767,  1179,     0,     0,  1087,     0,  1774,     0,   103,     0,
       0,   839,     0,     0,     0,     0,   768,     0,     0,  1683,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   638,
       0,     0,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,
    1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,
    1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,   877,
    1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,  1872,  1873,  1874,  1074,  1076,  1071,
    1073,  1072,  1075,  1875,  1876,  1202,  1877,  1207,  1206,  1878,
    1879,  1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1332,
    1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,  1810,   807,
     545,   808,     0,   872,     0,   870,     0,   327,   210,   211,
       0,   276,   281,     0,     0,     0,     0,   329,   332,     0,
     214,     0,   910,     0,   220,     0,   186,     0,     0,     0,
       0,     0,  1183,     0,     0,  1171,     0,     0,  1215,   612,
     613,   792,  1046,  1051,  1783,   605,   122,     0,     0,  1748,
    1747,   984,  1744,  1746,  1798,     0,  1222,     0,  1218,  1227,
       7,     0,     6,     0,  1791,  1047,     0,  1139,  1138,  1086,
    1137,  1085,     0,     0,   423,   425,     0,  1176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1532,     0,
       0,     0,   417,     0,     0,     0,     0,   416,     0,     0,
     433,     0,   504,     0,     0,     0,     0,     0,     0,     0,
     412,  1279,     0,   383,   382,   389,   429,   426,   384,   502,
     494,   385,   387,   501,   388,   899,   424,   427,   432,  1267,
     503,  1662,  1273,   124,     0,  1050,   121,     0,   774,    23,
     607,   381,     0,   773,  1043,   775,     0,  1277,   861,   860,
     863,   859,   862,  1800,     0,   857,     0,   606,   957,   858,
    1794,     0,  1782,   120,   954,   669,   952,     0,   603,  1777,
     711,   710,     0,   712,   595,   708,     0,     0,   967,   608,
    1331,  1327,  1330,     0,     0,  1019,  1017,     0,  1011,  1013,
    1012,  1010,  1009,     0,     0,     0,  1008,     0,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     998,   989,   990,     0,  1031,   410,    23,   821,   402,  1788,
       0,  1779,   125,   604,     0,  1016,  1015,  1180,  1178,  1104,
       0,  1651,  1652,  1105,  1193,  1105,  1088,  1089,  1092,  1107,
    1280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,   899,     0,    68,     0,   101,   583,   626,     0,
    1077,   974,  1081,     0,     0,  1032,  1197,     0,     0,  1084,
     630,   627,   628,     0,   632,   633,     0,   635,   636,     0,
     631,   934,   936,     0,     0,   935,   713,   932,   678,   928,
     890,     0,     0,     0,     0,   642,   643,     0,     0,   888,
     884,   885,   881,   882,   883,   876,   880,   879,     0,     0,
       0,     0,     0,     0,   549,   551,   543,   546,   547,   874,
    1809,   869,   871,   814,     0,   278,   280,   307,   301,     0,
       0,   310,   897,     0,   225,     0,   223,   245,   237,   229,
     248,   931,   175,   927,   836,   175,     0,     0,     0,  1255,
    1256,     0,     0,     0,  1229,  1230,  1232,  1233,  1234,  1238,
    1237,  1235,  1236,     0,     0,  1745,   908,     0,   986,     0,
       0,  1221,  1220,     0,  1214,     0,  1510,  1511,     0,  1048,
       0,    23,  1134,  1136,  1135,   391,   390,     0,     0,  1111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
    1540,  1538,  1539,  1535,  1537,  1534,  1536,  1528,     0,     0,
       0,     0,     0,   430,     0,     0,   508,   507,     0,     0,
     478,   475,   484,     0,   481,     0,     0,   415,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   165,   166,   167,   168,
     169,   509,   510,   511,   444,     0,     0,   443,   453,     0,
       0,   395,     0,     0,   396,   386,   392,   394,   397,   398,
     399,   400,   401,   393,   422,   421,   469,     0,     0,   944,
       0,     0,   350,    24,   344,     0,     0,  1040,     0,     0,
       0,     0,     0,     0,     0,   961,  1661,     0,     0,   186,
       0,     0,     0,  1779,     0,     0,     0,     0,     0,   137,
       0,     0,   971,   963,   964,   969,  1328,  1329,   887,   334,
     408,     0,   537,   588,   587,   585,   992,   589,   997,   993,
     996,   741,     0,   994,   995,   742,  1002,  1006,   999,  1000,
    1004,  1005,  1003,  1001,  1007,     0,   776,     0,     0,     0,
     405,   406,   403,   404,     0,     0,     0,   721,   720,   719,
    1780,  1787,    23,  1100,  1101,  1102,  1103,  1097,  1095,  1194,
    1109,  1094,  1090,     0,     0,  1091,  1775,     0,     0,     0,
       0,    97,     0,    98,     0,     0,     0,    73,     0,     0,
       0,   110,   105,     0,   866,     0,   865,     0,   468,  1079,
       0,   919,   920,   943,   914,   915,   769,   941,  1034,  1199,
       0,  1201,  1200,  1687,     0,     0,     0,  1685,  1688,  1689,
     658,     0,     0,     0,   647,   678,   678,   676,     0,     0,
     679,     0,    25,   646,   649,     0,   656,   652,   889,   878,
    1658,  1659,  1649,  1649,     0,     0,  1566,     0,   186,  1281,
       0,     0,  1282,  1325,   186,     0,  1326,     0,  1605,     0,
    1295,     0,  1343,  1342,  1341,  1339,  1340,  1338,  1336,  1333,
    1407,  1406,  1334,  1335,  1344,  1575,  1337,  1665,  1664,  1663,
    1345,  1809,  1809,   562,   553,   544,     0,   548,  1809,   873,
     175,     0,   321,   213,     0,   186,   222,   205,  1184,   175,
    1172,  1397,     0,  1396,     0,  1398,     0,  1399,  1258,     0,
    1264,  1260,  1257,     0,     0,     0,     0,     0,     0,  1254,
    1250,  1386,  1385,  1384,  1226,  1225,     0,  1249,  1245,     0,
    1241,  1239,     0,   616,     0,   615,     0,   985,     0,     0,
     983,  1751,  1753,  1752,  1749,  1799,  1796,  1219,     0,     0,
       0,  1212,   468,   342,     0,   529,  1177,     0,     0,     0,
       0,  1605,     0,     0,     0,     0,     0,   526,   512,   517,
       0,   513,   516,   515,     0,     0,     0,     0,     0,     0,
     418,     0,   171,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,   436,   435,   454,   445,   460,   463,   464,
     461,   467,   466,   465,   455,   456,   458,   457,   459,   446,
     450,   468,   462,   449,   468,    92,     0,   428,     0,  1209,
     976,  1044,  1045,  1042,  1041,     0,   864,     0,     0,   592,
       0,     0,     0,   955,   953,     0,   671,   672,     0,     0,
    1778,  1786,     0,     0,   599,     0,   601,   709,     0,   141,
       0,   965,   972,     0,     0,   980,     0,   337,     0,     0,
       0,     0,    23,  1018,  1303,     0,     0,   766,   753,   764,
     765,   751,   752,   760,   755,   759,   754,   763,   758,   761,
     757,   762,   750,   756,   749,   748,   991,   777,   411,     0,
    1023,     0,  1789,   722,   723,   361,     0,  1105,     0,  1108,
    1093,  1809,     0,     0,     0,     0,     0,     0,     0,    63,
      92,     0,     0,   116,   111,     0,   106,     0,   113,   107,
     850,   842,   848,     0,  1078,     0,  1080,  1082,     0,     0,
     923,     0,     0,     0,     0,  1033,  1198,  1754,  1690,   939,
    1691,   937,  1684,  1686,  1809,   629,   634,   637,   650,   648,
     609,     0,   698,   696,   702,   700,     0,     0,   694,   738,
     692,   688,   686,   736,   714,     0,   680,   690,   933,   929,
       0,     0,     0,     0,   655,     0,     0,     0,     0,     0,
       0,     0,  1513,     0,  1402,  1403,  1670,  1366,  1424,     0,
       0,  1668,     0,     0,  1607,  1608,  1606,  1588,  1692,     0,
    1349,  1355,  1354,  1353,  1357,     0,  1350,  1351,     0,  1576,
    1587,   550,   552,     0,     0,   565,   557,   559,     0,   554,
     555,     0,     0,   573,   575,     0,     0,   571,   875,   815,
     212,     0,     0,   224,  1140,   837,  1118,  1374,  1376,     0,
    1262,     0,     0,     0,     0,     0,  1252,     0,     0,  1505,
    1503,  1490,  1492,  1488,     0,  1487,     0,  1496,  1483,  1504,
       0,  1495,  1480,  1486,  1502,  1494,  1390,  1477,  1478,  1479,
       0,  1247,  1243,     0,     0,  1231,   614,     0,     0,     0,
       0,     0,  1795,     4,     8,    10,  1509,  1512,     0,   468,
       0,   500,   497,   496,   499,   495,     0,   420,   506,   491,
     491,     0,   514,     0,   518,     0,   282,  1176,     0,  1533,
     498,  1176,   505,   419,   266,     0,  1176,   479,   476,   485,
    1176,   482,  1176,  1176,  1176,     0,     0,     0,     0,     0,
       0,     0,     0,   470,    93,    94,    96,   472,     0,     0,
       0,   973,     0,     0,     0,     0,     0,     0,     0,   186,
     670,     0,   596,   598,     0,     0,   158,   156,     0,     0,
     138,     0,   148,   154,   678,   143,   145,     0,   970,   981,
     982,     0,   409,   336,   341,   594,   335,     0,   338,   343,
    1304,   538,   586,   584,   748,   743,   744,  1022,  1024,     0,
     407,   362,  1098,  1096,  1195,  1196,     0,     0,  1189,     0,
       0,     0,    99,     0,     0,    74,    80,    70,  1809,  1809,
     109,   104,   118,   114,     0,   108,   739,   851,   609,  1809,
     841,   840,   849,   975,     0,     0,   921,   922,   916,   942,
     468,     0,     0,  1631,  1523,  1526,  1632,  1530,  1524,  1629,
       0,     0,  1039,  1628,     0,     0,  1630,     0,     0,     0,
       0,     0,  1748,  1525,  1035,  1036,  1627,  1527,  1619,  1038,
    1614,  1617,  1618,     0,     0,     0,   660,   653,   651,     0,
      23,     0,  1809,  1809,  1809,  1809,   704,   682,   706,   684,
    1809,  1809,  1809,  1809,   748,   677,   681,  1809,   609,   734,
     732,   735,   733,     0,     0,    45,    43,    40,    34,    38,
      42,    37,    30,    39,     0,    33,    36,    31,    41,    32,
      44,    35,     0,    28,    46,   726,     0,   657,  1650,     0,
    1648,  1605,  1646,  1592,  1593,  1585,  1571,  1586,     0,     0,
       0,  1014,  1401,  1404,     0,     0,     0,     0,  1425,  1315,
    1287,  1673,  1672,  1671,     0,     0,     0,     0,  1310,     0,
    1309,     0,  1311,  1306,  1307,  1308,  1299,  1296,     0,     0,
    1356,     0,     0,     0,  1580,  1577,  1578,   564,   569,     0,
       0,  1809,  1809,   542,   556,   579,   567,   581,  1809,  1809,
     577,   561,   572,   806,   322,   206,     0,  1166,  1185,   806,
       0,  1173,  1166,     0,     0,  1259,     0,     0,     0,     0,
       0,  1430,  1432,  1434,  1472,  1471,  1470,  1436,  1453,  1261,
       0,  1514,     0,  1375,     0,  1378,  1517,     0,  1382,     0,
    1251,     0,     0,  1556,  1554,  1555,  1551,  1553,  1550,  1552,
       0,     0,     0,     0,     0,     0,     0,     0,  1388,     0,
    1391,  1392,     0,  1246,     0,  1240,  1242,  1750,     0,     0,
       0,  1797,     0,     0,  1223,   822,     0,   530,     0,  1609,
    1611,   488,     0,   489,     0,   528,     0,   525,   522,   493,
     487,  1114,  1541,  1113,     0,   170,  1112,     0,     0,     0,
    1115,     0,  1117,  1116,  1110,   447,   448,   452,   437,     0,
     440,   451,     0,   439,     0,     0,    92,     0,     0,     0,
       0,  1274,  1802,  1801,   593,     0,     0,    47,     0,   675,
     674,   673,  1275,     0,     0,   678,  1809,  1809,   150,   617,
     160,   152,   162,   142,   149,  1809,     0,     0,     0,     0,
       0,     0,     0,  1809,     0,   746,   609,     0,  1776,     0,
      92,     0,    64,     0,     0,     0,    77,     0,    92,    92,
     117,   112,  1809,  1809,   102,   748,   852,   846,   854,   853,
     843,   534,   902,     0,     0,  1616,  1615,  1529,     0,  1605,
       0,     0,  1473,     0,  1473,  1473,  1473,  1473,  1620,     0,
       0,     0,     0,     0,     0,  1674,  1675,  1676,  1677,  1678,
    1679,  1623,  1755,   940,   938,   663,   661,     0,   640,   654,
     610,   715,     0,   699,   697,   703,   701,     0,  1809,     0,
    1809,   695,   693,   689,   687,   737,   691,    23,   727,     0,
       0,     0,    26,     0,  1653,     0,  1575,     0,     0,  1584,
    1567,  1583,  1405,     0,  1368,     0,  1314,  1412,     0,     0,
    1669,     0,  1666,  1589,     0,     0,     0,     0,     0,     0,
    1693,  1313,  1312,  1300,  1298,     0,  1359,     0,  1352,     0,
       0,     0,     0,   566,   563,   558,   560,     0,  1809,  1809,
     574,   576,  1809,  1809,     0,     0,  1164,  1165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1163,
       0,     0,  1151,  1152,  1153,  1150,  1155,  1156,  1157,  1154,
    1141,  1132,     0,     0,  1188,     0,  1809,     0,  1127,     0,
       0,     0,     0,     0,     0,     0,  1119,  1120,     0,  1052,
       0,  1263,     0,  1439,     0,  1453,  1438,  1435,     0,  1400,
       0,  1467,  1464,  1465,  1462,  1469,  1468,  1463,  1466,  1644,
       0,  1644,  1454,     0,     0,     0,  1518,     0,  1519,     0,
       0,     0,     0,  1381,  1253,  1380,  1372,     0,     0,     0,
    1507,  1499,  1499,     0,     0,  1499,  1506,     0,  1523,  1387,
    1389,  1393,  1394,  1248,  1244,   988,     0,   951,     9,     0,
    1216,   823,  1049,     0,     0,  1424,  1595,  1612,     0,   491,
     519,     0,   275,   480,   477,   486,   483,     0,   442,   441,
     471,    95,   473,   348,  1210,     0,     0,  1793,     0,     0,
     956,    48,     0,   600,   602,   597,   724,   159,   157,     0,
    1809,     0,     0,     0,  1809,   155,   144,     0,   147,   146,
       0,   962,   966,   340,     0,  1305,     0,   748,   745,    23,
    1099,     0,  1190,    69,     0,     0,   100,    67,    92,    75,
      81,     0,   119,   115,   740,  1809,   856,   609,   855,     0,
     531,     0,   771,   772,   770,     0,     0,  1640,     0,     0,
       0,  1475,  1476,  1474,     0,  1642,     0,     0,     0,     0,
       0,     0,     0,  1037,  1625,  1626,  1622,  1624,     0,  1809,
     659,   644,   641,     0,   705,   683,   707,   685,   716,   730,
     731,   728,   729,    29,    27,     0,  1647,  1601,  1572,  1573,
    1569,  1575,     0,  1367,  1605,  1370,     0,  1289,  1284,  1283,
    1286,     0,  1601,     0,     0,  1726,  1724,     0,     0,  1712,
    1723,     0,     0,  1725,     0,     0,     0,     0,     0,  1748,
    1722,  1718,     0,  1710,  1713,  1714,  1721,  1717,  1741,     0,
    1703,  1702,  1706,  1708,     0,  1701,     0,  1704,  1695,  1301,
    1297,     0,  1358,     0,     0,  1581,  1579,   570,   568,   580,
     582,   578,     0,     0,   229,  1158,  1159,  1160,  1162,  1145,
    1143,  1142,  1146,  1147,  1144,  1161,  1148,  1149,  1133,   948,
    1168,   945,     0,     0,  1186,     0,  1131,  1130,  1125,  1123,
    1122,  1126,  1124,  1128,  1129,  1121,  1174,  1377,  1437,  1431,
    1433,  1443,  1440,  1645,  1442,     0,  1448,  1440,     0,  1446,
    1644,  1456,  1455,     0,  1457,     0,  1373,  1379,  1521,  1514,
    1383,  1563,  1561,  1562,  1558,  1560,  1557,  1559,  1489,     0,
    1491,     0,     0,     0,     0,  1497,  1501,     0,  1481,  1395,
     987,  1224,  1217,  1213,  1610,     0,  1413,  1414,  1416,  1419,
    1426,     0,     0,  1473,  1597,  1591,  1548,  1546,  1547,  1543,
    1545,  1542,  1544,   492,   490,     0,   524,   523,   172,   438,
       0,     0,    23,     0,     0,   979,     0,    49,   959,     0,
      23,   161,   151,     0,   619,   621,   163,   153,   724,     0,
     339,   539,   747,  1020,     0,     0,    65,     0,    78,    87,
       0,    71,   847,   844,   535,  1809,   917,  1531,     0,     0,
       0,     0,  1641,     0,     0,  1639,     0,     0,     0,     0,
    1621,  1638,     0,   662,   639,   645,   609,  1657,     0,  1655,
       0,     0,  1575,  1575,  1568,  1369,     0,  1371,  1365,     0,
    1288,     0,  1667,     0,  1716,  1715,     0,     0,  1473,     0,
    1473,  1473,  1473,  1473,  1719,     0,     0,  1699,     0,     0,
       0,     0,  1728,  1700,     0,     0,     0,     0,     0,     0,
    1694,     0,  1360,  1363,  1347,  1361,  1364,     0,   817,   816,
     323,   207,   950,   949,   947,     0,  1167,  1053,  1057,  1059,
       0,  1063,     0,  1061,  1065,  1054,  1055,     0,   838,     0,
    1644,  1460,     0,  1449,  1452,  1451,  1459,     0,  1440,     0,
       0,  1515,  1520,     0,  1508,  1500,  1484,  1482,     0,  1485,
       0,  1417,     0,  1522,  1420,     0,  1427,  1428,  1600,  1216,
       0,     0,     0,     0,   521,   520,   474,   349,   346,     0,
     977,     0,     0,     0,   958,   725,   139,   618,    23,   968,
    1025,    66,  1191,    83,     0,     0,    76,    87,    87,  1809,
     532,     0,     0,     0,     0,     0,  1637,  1643,  1633,  1634,
    1635,  1636,   664,   717,     0,  1654,  1602,  1595,  1574,  1570,
       0,  1290,     0,  1595,  1739,     0,     0,  1742,     0,     0,
       0,     0,     0,     0,     0,  1711,  1730,  1731,  1727,  1729,
    1709,     0,  1705,  1707,  1696,  1697,  1302,     0,  1348,  1346,
    1582,   946,  1809,  1809,  1067,  1809,  1069,  1809,  1809,  1056,
    1187,  1175,  1441,  1444,     0,  1447,  1445,  1461,     0,     0,
       0,  1498,  1421,     0,  1415,  1409,  1410,  1613,     0,  1429,
    1423,  1598,  1320,  1316,  1317,  1322,  1321,  1596,  1216,     0,
     351,   978,  1792,     0,     0,     0,     0,     0,     0,    54,
       0,    53,     0,    51,     0,     0,   140,  1029,  1021,     0,
    1027,    87,    92,    87,    88,    82,    72,   845,     0,     0,
    1604,     0,  1682,     0,  1809,    23,  1656,  1594,  1603,  1294,
       0,  1291,  1293,  1590,  1740,     0,     0,  1738,     0,     0,
       0,     0,  1720,  1737,     0,  1362,  1058,  1060,  1809,  1064,
    1809,  1062,  1066,  1450,  1458,  1516,  1493,     0,  1418,     0,
    1408,     0,  1324,  1323,  1319,  1599,  1549,   357,   355,   347,
       0,   353,   359,    56,    61,    58,    60,    57,    59,    55,
       0,    50,     0,   620,   622,  1809,  1026,  1028,  1192,    84,
      79,   533,   918,  1680,  1681,   660,   718,     0,  1285,  1736,
    1743,  1732,  1733,  1734,  1735,     0,  1068,  1070,  1422,  1411,
    1318,  1809,  1809,   352,   354,  1809,    52,     0,  1030,     0,
     665,  1292,  1698,   358,   356,   360,     0,    85,   960,    89,
      91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   552,   553,   554,   555,   711,  1733,  1734,   189,   264,
     190,  1132,  1133,  1621,  1962,  3021,  2460,  2461,  2902,  3022,
    3023,   556,   900,  2494,  2199,  2918,  1560,  2197,  2759,  2498,
    2914,  2198,  2760,  3032,  3139,  3149,  2916,  3152,  1783,  1784,
    1785,  1232,  1851,   557,  1243,   905,  1241,  1568,  1861,  1565,
    1859,  1864,  2203,  1242,  1858,  1569,  2202,   558,    17,    36,
      37,    38,    39,    40,   114,   561,   827,  1499,  1159,  1810,
    1814,  1815,  1811,  1812,  2470,  2474,  2175,  2167,  2166,  2168,
    2171,  1114,  1066,  1765,   562,    83,    84,    19,    62,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     679,  2325,   305,   660,  1681,   332,   333,   229,   287,   280,
     282,   985,   986,   146,   355,   147,   148,   293,   230,   231,
    1485,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   663,   247,   248,   323,   375,   196,    20,    80,   178,
     179,   180,   669,  2324,   181,   251,   240,   326,   327,   328,
     329,  1512,   563,   564,   565,   566,   784,  3010,  2732,  1134,
    3089,  3090,  3091,  3132,  3131,  3135,   567,   568,   569,   570,
     760,  1115,   867,  1201,  1202,  1169,   864,  1170,   762,   763,
     764,   765,   766,   767,   768,  1069,  1116,  2139,  1117,  1118,
    1119,  1120,  1121,  1122,  1123,   716,   769,  1465,  2144,  2146,
    2730,   770,  1436,  2128,  1435,  2127,  1439,  2131,  1437,  2129,
    2111,  2120,   771,   772,   773,   774,  1420,  1421,  1422,  1423,
    1404,   571,  2765,  3038,  2510,   572,   837,  1514,  2183,   115,
     237,   365,  1334,   966,   967,   968,  1331,  1332,  1668,  1669,
    1670,  2021,  2022,  1335,  1336,  1664,  2025,  2017,  1676,  1677,
    2028,  2029,  2322,  2318,  2319,   573,  1176,    85,  1480,  1481,
    1826,   869,   817,   872,   694,   806,   789,   828,  1920,    86,
     695,   689,  1384,  2170,    87,   776,   574,   575,   921,   922,
     576,   577,   578,   579,   929,  2541,   950,  2784,   951,  1598,
     952,  1917,   953,  2248,   954,  1624,   580,  1594,  2247,  2539,
    2538,  3044,   116,    21,   581,  1150,  1486,  1487,  1614,  1281,
    1615,  1616,  2258,  2260,  1933,  1932,  1937,  1931,  1930,  1923,
    1922,  1925,  1924,  1927,  1929,   582,   583,   825,   584,  1277,
     936,  3045,   585,  1209,  2740,  1964,  1965,  1617,  1934,  1867,
    2205,   860,  1186,  1535,  1835,  2184,  1836,  1182,  1534,   586,
     587,   914,  1583,  2514,   588,   589,   590,   591,    22,    66,
      23,    24,    25,   117,   118,   592,   119,    26,   650,    27,
     120,   121,   158,   367,  1340,  2033,  2839,   122,   154,   298,
     593,  2106,    28,    29,    30,    31,    32,    61,    88,   123,
     413,  1349,  2039,   594,   909,  1871,  1572,  1869,  2919,  2505,
    1573,  1868,  2208,  2507,   595,   596,   597,   800,   801,  1245,
     124,   238,   366,   654,   655,   970,  1338,   598,   955,   956,
     599,   833,  1289,   957,   777,    90,    91,    92,    93,  1252,
     184,   138,    94,   700,   135,   192,   193,  1253,  1254,  1878,
    1255,   410,   411,   938,   412,   939,  1590,  1591,  1256,  1257,
    1130,  2640,  2641,  2844,  1393,   815,   816,   600,  1145,  2904,
     601,  2482,   602,  1163,  1164,  1165,  1505,  1503,   603,   604,
    1791,  1821,   605,  1018,  1390,   606,   861,   862,   607,   877,
     608,  1975,   609,  2910,   610,  1839,  3028,  3029,  3030,  3105,
     866,   611,  1258,  1585,  1904,  1905,   612,  1473,   693,  1030,
     613,   614,   615,  2041,  2644,  2855,  2856,  2972,  2973,  2977,
    2975,  2978,  3068,  3070,   616,   617,  1247,  1577,   618,  1249,
     885,   886,   887,  1225,   619,   620,   621,  1547,  1217,   880,
     199,   888,   889,   778,  2042,  2366,  2367,  2350,   719,   720,
    2037,  2351,  2354,   125,   153,   359,   995,  1686,  2368,  2859,
    1039,   622,   878,   126,   150,   356,   992,  1684,  2355,  2857,
    2038,   904,  2190,  2755,  3031,  1220,   623,   624,   625,   626,
     627,   787,  1789,   713,  1738,   628,  2703,   707,   708,  2103,
    1369,   629,   630,  1004,  1005,  1006,  1381,  1723,  1007,  1720,
    1378,  1008,  1695,  1370,  1009,  1010,  1011,  1012,  1689,  1361,
     631,   796,   779,   632,  1312,  1313,  1639,  2569,  2801,  2289,
    2566,  3050,  3051,  1314,  1649,  2303,  2007,  2610,  2831,  1831,
    2182,  2008,  1315,  1316,  2714,  3003,  3004,  3005,  3084,  1317,
    1318,  1167,   633,   831,   634,   963,  1319,  1320,  2969,  1655,
    1656,  1657,  2010,  2305,  2834,  2835,  1321,  1985,  2283,  2798,
    1371,  1372,  1357,  2062,  1687,  2063,  1373,  2067,  1374,  2090,
    1375,  2091,  2420,  2421,  1690,  1322,  1633,  1634,  1982,  1323,
    2999,  2886,  2995,  1988,  2435,  2706,  2707,  2708,  2993,  2436,
    1989,  2887,  3000,  2050,  2051,  2052,  2053,  2054,  2861,  2662,
    2982,  2055,  2862,  2863,  2394,  2056,  2395,  2057,  2524,  1716,
    1717,  1718,  2692,  1719,  2417,  2411,  2875,  2064,  2836,  2398,
    2602,  2066,  2884,  1906,   780,  1907,  2217,  1057,  2112,  2723,
    2080,  2688,    60,   635,   636,  2561,  2793,  2276,  2792,  1660,
    2015,  2016,  2280,  1976,  1324,  1977,  1996,  2572,  1412,  1972,
    1973,  2715,  2889,  2791,  2565,  1908,  1647,  2108,  2109,  2996,
    2058,  1910,  1911,  2526,  2664,   637,   638,  1626,  1974,  2556,
    2788,  2789,  1292,   639,   782,  1326,  1327,  1642,  2291,  1328,
    1329,  1993,  2241,  2520,   640,   917,  1266,  1267,  1268,  1269,
    1330,  1997,  2608,  2830,  2300,  2605,  2606,  2607,  2604,  2592,
    2593,  2594,  2595,  2596,  2597,  2948,   701,  1587,   703,  1394,
    1912,    64,    49,    78,    75,   642,   891,  1551,  1153,  1211,
     643,   870,   644,  2157,   645,  1732,   705,  1396,   646,   647,
      43,   360,   361,   362,   363,   364,   648
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2521
static const short yypact[] =
{
    1990,  1211, -2521, -2521,   316,   522,   522,   522,   522,   522,
     522,   522,   522,   316,   847, -2521, -2521, -2521,  1617, -2521,
   -2521, -2521,   357, -2521,  1990, -2521, -2521, -2521, -2521, -2521,
    3017, -2521, -2521, -2521, -2521, -2521,   343,   349, -2521,   359,
   -2521, -2521, -2521, -2521, -2521,   316,    57, -2521,  -178, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521,  2491,   149, -2521, -2521, -2521,   225, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521,   316, -2521, -2521,    57,
     -62, -2521,   316,   607,  1617, -2521,   -24, -2521, -2521, -2521,
   -2521,  1147,    93, -2521, -2521, -2521,   870,   535,   316, -2521,
   -2521,   888,   316, -2521, -2521,   316,   316, -2521, -2521, -2521,
   -2521,   316,   316, -2521, -2521, -2521, -2521, -2521,   225, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    4407,    93, -2521,   947,   416, -2521, -2521,   482, -2521, -2521,
     914,   149,   426, -2521, -2521, -2521, -2521, -2521,  7770, -2521,
     316,   505,   855,   316,  1617, -2521, -2521, -2521,   316, -2521,
   -2521,   453,   849, -2521, -2521,   552, -2521,   568, -2521,   566,
   -2521, -2521,   604, -2521,   635, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521,   651, -2521, -2521, -2521,   416,  1580,
    1108, -2521,   199, -2521,   416, -2521,   236, -2521, -2521, -2521,
     102, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,   453,
   -2521,   849, -2521, -2521,   677, -2521,   709, -2521,   705, -2521,
   -2521,   757, -2521,   772, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521,   790,  1204,   316,   843, -2521,  1617,  1617,   868,
     316, -2521,   508, -2521,   545,   920, -2521,   700,  1086,  1317,
    1329,   316,  1332,  1341,  1353, -2521,   770, -2521,   985, -2521,
   -2521, -2521, -2521, -2521,   416, -2521,   416,   954,   213, -2521,
   -2521, -2521,  1395, -2521, -2521,  1409, -2521, -2521, -2521, -2521,
   -2521,   508, -2521, -2521, -2521,  1460,  1462,   149,  1332,  1467,
    1469,   880, -2521,  1447, -2521,  1137,  1084, -2521,  1169, -2521,
   -2521, -2521,   911, -2521, -2521,  1507, -2521,  1112, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  1086,  1112, -2521, -2521, -2521,
   -2521, -2521, -2521,  1117,   178,   200,   234, -2521,  2473, -2521,
   -2521, -2521,  1141,  1560,   212,  1185, -2521, -2521,  1580, -2521,
     416,  1119, -2521, -2521,   958,  1547,  1333,   221,   241,   274,
    1156,   280,  1201, -2521, -2521, -2521,   316, -2521, -2521,   316,
    1232, -2521,  4199,   426,  4903,  2207,   582,   316,  1572,   413,
   -2521,   920,  1568, -2521, -2521, -2521, -2521,  1569, -2521,  1570,
   -2521,  1582, -2521,   316, -2521,   316, -2521, -2521,  1332,  1583,
   -2521, -2521, -2521, -2521,   232,   416,  1585,   413,  1182,  1586,
   -2521,  1588, -2521, -2521, -2521,  1589, -2521, -2521, -2521,   999,
    1227,  1620, -2521,   316,  1243, -2521, -2521, -2521,   316,   247,
     316,   316,   247,   247,   968,   316, -2521,   316, -2521, -2521,
     316, -2521,   763, -2521, -2521, -2521,   247, -2521, -2521, -2521,
   -2521,   316, -2521, -2521, -2521, -2521,   120,   120,  7176, -2521,
   -2521, -2521, -2521, -2521,   247, -2521, -2521,   247, -2521, -2521,
     316, -2521, -2521,   247, -2521, -2521,   385,   247, -2521, -2521,
    7176,   247,   385,   316,   385,   247, -2521, -2521,   134,   247,
     247,   134,   247,   316,   134,   247, -2521,   247,   247,   247,
   -2521, -2521, -2521, -2521,   385,   247, -2521, -2521,   247,    42,
     316, -2521, -2521, -2521, -2521,   247,  1006, -2521, -2521, -2521,
     247, -2521,  2602,   385,  7176, -2521,    38,    38,   247, -2521,
   -2521,  1019,   385,  1028,  7176,  7176, -2521,  1489,  7176,   247,
      57, -2521,  7176,   247,  7176,   385, -2521,   247,  7176, -2521,
    7176,   120,   316,   247,   316,    38,   247,   316,    38, -2521,
     316,   285, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,    87,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,   946,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
     456, -2521,   316, -2521,   723, -2521,  1249, -2521, -2521, -2521,
    1340, -2521, -2521,  1252,  1254,  1260,  1267, -2521, -2521,  1023,
    1652,  1271, -2521,   272, -2521,  1361, -2521,  1275,  1276,  1047,
    1282,   316, -2521,   316,  1285, -2521,   394,  1248, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,  1054,  1022,  1222,
   -2521,  1064, -2521,  1065, -2521,  1676,  -218,   292, -2521, -2521,
   -2521,  1262, -2521,  1144, -2521,  1210,   188, -2521, -2521, -2521,
    1013, -2521,  7176,  7176, -2521, -2521,  1261,  1173,  1265,  1272,
    1278,  1279,  1281,  1283,  1286,  1287,  1292,  7176,  1116,  1294,
    1295,  1298, -2521,  7176,  7176,  1299,  1301, -2521,  7176,  1303,
   -2521,  1304,  1305,  1308,  1316,  1321,  1323,  1331,  7176,  1337,
    6231, -2521,   154, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,   871, -2521,  1327, -2521, -2521,
   -2521, -2521, -2521, -2521,   385, -2521, -2521,  1144, -2521,    67,
   -2521, -2521,  1448, -2521,   158, -2521,  1290, -2521, -2521, -2521,
   -2521,  1751, -2521, -2521,  -170, -2521,  1143, -2521,  1149,  1751,
   -2521,  1167, -2521, -2521,  1351,   100, -2521,  1325, -2521,  1100,
   -2521, -2521,  1345, -2521,  -148, -2521,  1122,   196,   -35, -2521,
    1054,  1450, -2521,  7176,  7176, -2521,  1776,   247, -2521, -2521,
   -2521, -2521, -2521,   126,   126,   126, -2521,   126, -2521,   126,
     126,  1199,    67,  1199,  1199,  1034,  1034,  1199,  1199,    67,
   -2521,  1783, -2521,     7,  1791, -2521,    67, -2521,  6789, -2521,
     104,    50, -2521, -2521,  7176, -2521, -2521, -2521, -2521, -2521,
     956, -2521, -2521,   426,  1415,   426,  7176, -2521,    72, -2521,
   -2521,  7176,  1370,  1371,  1375,  1376,  1184,  1379,  1028,  1305,
   -2521,  1470,   970,  1221, -2521,  1239, -2521, -2521, -2521,  1040,
   -2521,  1808, -2521,  1805,   316, -2521,   258,    65,  1246, -2521,
   -2521,  1815, -2521,  1168,  1815,  1816,  1170,  1815,  1816,  7176,
    1815, -2521, -2521,   188,   385, -2521, -2521,  1407,   403, -2521,
   -2521,  1403,   385,  7176,  1408, -2521, -2521,  1814,  1817,  1775,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,  1079,  1079,
     247,   247,   247,  3068, -2521, -2521,  1755,   456, -2521, -2521,
     794, -2521, -2521, -2521,  1398, -2521, -2521, -2521, -2521,  4407,
    1332, -2521, -2521,  1399, -2521,   339, -2521, -2521, -2521, -2521,
   -2521, -2521,  1617, -2521, -2521,  1617,   863,   148,  1831, -2521,
   -2521,   364,   219,   366,  1852, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521,  1194,  1022,  1065, -2521,   968,   362,  1160,
     316, -2521, -2521,   316, -2521,  1269,  1240,  1273,  1434, -2521,
    1436,    79, -2521, -2521, -2521,  2670,  2670,    38,  7176, -2521,
      38,    38,    38,    38,  1396,  7176,  1427,  1420,  7176,  6231,
    1441, -2521, -2521, -2521, -2521, -2521, -2521, -2521,  1250,    38,
    1849,  7176,  3818,  6231,  1396,  7176, -2521,  6231,  1853,   383,
   -2521, -2521, -2521,  7176, -2521,  7176,  7176,  6231,  7176,  7176,
    7176,  7176,  7176,  7176,  7176,  7176,  7176,  7176,  7176,  7176,
    7176,  7176,  7176,  7176,  7176, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  7176,  7176, -2521, -2521,  1449,
    7176, -2521,  7176,  1464, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,   316,   385, -2521,
    1274,  1466, -2521, -2521, -2521,   968,  1121, -2521,  1121,  1028,
     134,  7176,  7176,  7176,  1468, -2521, -2521,   385,   385, -2521,
    1288,  1028,    38,  1236,   316,   416,    92,    42,   385, -2521,
    1277,  7176,  1558, -2521, -2521,  1352, -2521, -2521,  1791,   157,
   -2521,   188, -2521, -2521,  1890,  1893, -2521, -2521, -2521, -2521,
   -2521, -2521,   936, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  2602, -2521,  1034,  7176,   -22,
   -2521, -2521,  1903, -2521,    38,  1888,  1889, -2521, -2521, -2521,
   -2521, -2521,    95, -2521, -2521, -2521, -2521,  1765, -2521,  1701,
   -2521, -2521, -2521,  7176,   120, -2521, -2521,   316,  1904,    38,
      38, -2521,  1342, -2521,    38,  1309,   385, -2521,   316,   316,
    7176,    62, -2521,  1356, -2521,   266, -2521,  1455, -2521,  1456,
    7176,  1026, -2521, -2521,  1318, -2521,  1932, -2521,  1397, -2521,
     385, -2521, -2521, -2521,   968,   385,   136, -2521, -2521, -2521,
   -2521,   316,    38,    38,   248,   403,  1794,  2400,   385,   188,
   -2521,  1400, -2521, -2521,  1934,  1918,  1559, -2521, -2521, -2521,
   -2521, -2521,  1636,  1636,   169,  1412, -2521,   316, -2521, -2521,
    1144,  1144, -2521, -2521, -2521,   316, -2521,   316,   -58,  1144,
   -2521,   787, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  1216, -2521, -2521, -2521, -2521,
   -2521,    52,    52,   365,   878, -2521,   549, -2521,   794, -2521,
    1617,  1936, -2521, -2521,  1936, -2521, -2521, -2521, -2521,  1617,
   -2521, -2521,  1144, -2521,   758, -2521,  1532, -2521, -2521,   758,
   -2521, -2521, -2521,  1535,  1540,   208,  1541,  1543,  2083, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521,   316, -2521, -2521,   208,
    1312, -2521,   394, -2521,  1587,    93,  1358, -2521,  1028,  1411,
   -2521, -2521,  1523, -2521, -2521, -2521,  1442, -2521,   316,   316,
     316, -2521, -2521, -2521,   342, -2521,  6231,  1593,  1599,   373,
     382,   -58,  1600,  4070,  1605,   -48,  1404, -2521, -2521,    96,
    1606, -2521, -2521, -2521,  5233,  1973,  1116,  1618,  1621,  5265,
   -2521,  1626,  3261,  1627, -2521,  7176,  7176,  7176,  5569,  7176,
    5714,  5738,  5782,  3314,  6408,  6352,  4497,  6375,  4547,  6541,
    6673,  5314,  6416,  6621,  2670,  2670,  2535,  7353,  2032,  5907,
    5959,  1396,  6231,  6205,  1396,  7176,  1581, -2521,   316, -2521,
    1402, -2521, -2521, -2521, -2521,  1394, -2521,  2015,  2017, -2521,
    2018,  1451,  7176, -2521, -2521,  1418,  2020, -2521,  1549,  1413,
    1816, -2521,  1639,   467, -2521,  1611, -2521, -2521,  1421,  1043,
     316, -2521, -2521,  1614,   247,   900,  7176, -2521,   316,   316,
    7176,    43,    67,  2041,  1497,  2024,  2025, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  1625, -2521, -2521, -2521,   385,
    1521,  6789, -2521, -2521, -2521,  1992,  7176,   426,   833, -2521,
   -2521,  1735,  2055,  2056,   391,   407,   316,  1674,  1028, -2521,
    7176,  1637,  1643, -2521, -2521,  1709, -2521,  7176,   227, -2521,
    1477, -2521, -2521,   497, -2521,  7176, -2521, -2521,  1452,   947,
   -2521,  1245,   316,  2059,  7291, -2521, -2521,  1656, -2521,  1657,
    2070, -2521, -2521, -2521,   130, -2521,  1816,  1816,  1423, -2521,
    1530,  1538, -2521, -2521, -2521, -2521,    38,    38, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  1813, -2521, -2521, -2521, -2521,
      38,  7470,  2074,  2062, -2521,  1028,   742,   182,   106,  1991,
      -2,  1019, -2521,   239, -2521, -2521, -2521,  1664,   128,  1144,
     559, -2521,  1475,  1471, -2521, -2521, -2521, -2521, -2521,   637,
   -2521, -2521, -2521, -2521,  1667,  1474,  2094, -2521,  1230, -2521,
   -2521, -2521, -2521,   385,    99, -2521, -2521, -2521,  1463,   878,
   -2521,   316,   316, -2521, -2521,   316,   523, -2521, -2521, -2521,
   -2521,  1680,  1685, -2521,  1655, -2521,  1659, -2521,  1682,   414,
   -2521,  6819,   417,   167,   167,   419, -2521,   167,  6819, -2521,
   -2521,  1257,  1257, -2521,  1690, -2521,  1692,  1693, -2521,  1702,
    1703, -2521,  1704, -2521, -2521, -2521,    85, -2521, -2521, -2521,
     420, -2521, -2521,   424,   316, -2521, -2521,  1160,  2120,  1028,
     416,  7176, -2521,  2127, -2521, -2521, -2521, -2521,   208, -2521,
      38, -2521, -2521, -2521, -2521, -2521,  6561, -2521, -2521,  1116,
    1116,  2108, -2521,  2112,  1556,  1284, -2521,  1173,  1758, -2521,
   -2521,  1173, -2521, -2521, -2521,  1759,  1173,  6231,  6231,  6231,
    1173,  6231,  1173,  1173,  1173,  2124,  2125,  2126,  7176,  1764,
    2131,  7176,  1768, -2521,  2153, -2521,  6231, -2521,  1542,   208,
     147, -2521,  1028,  7176,  7176,  7176,  6918,  2158,   161, -2521,
   -2521,  1028, -2521,  1546,   316,   316, -2521, -2521,   316,   316,
   -2521,  1010, -2521, -2521,   811, -2521,  1550,  7176, -2521, -2521,
   -2521,  2157, -2521, -2521, -2521, -2521, -2521,   316,  1816, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,   385,
   -2521, -2521,  3421, -2521, -2521, -2521,  1847,  2147, -2521,  1832,
    1839,  1724,  1563,  1841,  1760, -2521, -2521, -2521,   -41,  1828,
   -2521, -2521, -2521, -2521,  1709, -2521, -2521, -2521,   156,   690,
   -2521, -2521, -2521,  1934,  7176,  1766, -2521,  1734, -2521, -2521,
   -2521,  1359,  1359, -2521,  1054, -2521, -2521,  1257, -2521, -2521,
    7521,  1777, -2521, -2521,  1779,  1780, -2521,  1781,  1782,  1784,
    1785,   316,   377, -2521,  2186, -2521, -2521, -2521, -2521, -2521,
    2247, -2521, -2521,   968,   385,   385,    73,  1544, -2521,  2167,
      67,   316,  1977,  1977,  1977,  1977, -2521,  2197, -2521,  2208,
    1977,  1977,  1977,  1977,  1625, -2521, -2521,  1977,   119, -2521,
   -2521, -2521, -2521,  2190,  2202, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521,  2203, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521,   427, -2521, -2521, -2521,  2195, -2521, -2521,  1144,
   -2521,   -58, -2521, -2521, -2521, -2521, -2521, -2521,  1628,  1629,
     129, -2521,   239, -2521,   167,  1609,   247,  6819, -2521, -2521,
    1804, -2521, -2521, -2521,   316,   316,  6561,   218, -2521,  7176,
   -2521,  7176, -2521, -2521, -2521, -2521, -2521, -2521,   247,   167,
   -2521,  1144,   892,  1619,  1622,  2227, -2521,  2229, -2521,   385,
     316,   894,   894, -2521, -2521,  2230, -2521,  2230,   539,   539,
    2230, -2521, -2521,  2207, -2521, -2521,  5271,    31, -2521,  2207,
    1067, -2521,    31,   167,   758, -2521,  1811,   923,  1811,  7305,
     243,  2234, -2521, -2521, -2521, -2521, -2521, -2521,   388, -2521,
    1144,   557,  1854,  2238,  1630, -2521, -2521,   430, -2521,   208,
   -2521,   433,   294, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    1632,  -121,  2221,  2221,  2235,  2221,  2221,  2237, -2521,   141,
   -2521,   758,   316, -2521,   208, -2521, -2521,  1641,  1028,  2246,
     275, -2521,   316,   435, -2521,  7176,  1880, -2521,   118, -2521,
     316, -2521,  1648, -2521,  1885, -2521,  2250, -2521,  1689, -2521,
   -2521, -2521, -2521, -2521,  1653, -2521, -2521,  1892,  1894,  1897,
   -2521,  1899, -2521, -2521, -2521, -2521, -2521, -2521,  6231,   438,
   -2521, -2521,   446, -2521,  1900,  7176,  7176,  2269,   448,  1028,
    2292, -2521, -2521, -2521, -2521,  7176,  1736,  2028,  7176, -2521,
   -2521, -2521, -2521,  1268,  1913,   811,  1123,  1123,  2297,   -87,
   -2521,  2298, -2521, -2521, -2521,  1123,   316,  1767,  1314,  2303,
     316,   -45,   385,  2072,   459, -2521,  1530,  7176, -2521,  2309,
    7176,   385, -2521,   763,   316,   385, -2521,  1927,  7176,  7176,
   -2521, -2521,   -41,  1828, -2521,  1625, -2521, -2521,  1125, -2521,
   -2521,  1748, -2521,   416,  7047,  1790,  1790, -2521,  1694,   -58,
    1935,    91,   313,  6561,   313,   313,   313,   313,  1706,  6561,
    7291,  6561,  6561,  6561,  6561, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,  1883,   903, -2521,
   -2521, -2521,  1708, -2521, -2521, -2521, -2521,    38,  1977,    38,
    1977, -2521, -2521, -2521, -2521, -2521, -2521,    67, -2521,   841,
     853,  7470, -2521,  1945,  1902,  6561,  1216,   106,   106, -2521,
   -2521, -2521, -2521,   460, -2521,  1866, -2521,  2330,   167,   485,
   -2521,  1720, -2521,  2340,  7613,  7613,  7613,  7613,   167,   167,
   -2521, -2521, -2521,  1795, -2521,   462, -2521,  1723, -2521,   316,
     316,  1230,   385, -2521,  2230, -2521, -2521,   316,   539,   539,
   -2521, -2521,   539,  2141,  1727,  1728, -2521, -2521,   120,   120,
     120,  2331,   120,   120,   120,   120,   120,   120,  2332, -2521,
    2333,   120, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    5271, -2521,   385,  1737, -2521,  1915,  2141,  2338, -2521,  2339,
    2341,  2342,  2343,  2344,  2346,  1164,  1067, -2521,  1915, -2521,
     469, -2521,  1896, -2521,   318,   893, -2521, -2521,  6819, -2521,
    6819, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,   176,
    1948,   176, -2521,  1950,   541,  6561, -2521,  2353, -2521,  2087,
     167,  1319,   167, -2521, -2521, -2521, -2521,  1454,  2356,  1454,
   -2521,  2377,  2377,   475,  1996,  2377, -2521,  1998, -2521, -2521,
   -2521,   758, -2521, -2521, -2521, -2521,  1028, -2521, -2521,   208,
    2123,  1934, -2521,  6561,   162,  1867,   300, -2521,  1695,  1116,
    1806,  1330, -2521, -2521, -2521, -2521, -2521,  7176, -2521, -2521,
   -2521, -2521, -2521,  1929, -2521,   269,  1028, -2521,  2390,  1972,
   -2521, -2521,  2013, -2521, -2521, -2521,  1856, -2521, -2521,   316,
    1123,   416,  1338,   316,  1123, -2521, -2521,    38, -2521, -2521,
    7176, -2521, -2521, -2521,    38,  2070,  2168, -2521, -2521,    67,
    6231,  2382, -2521, -2521,   188,  1984, -2521, -2521,  7176, -2521,
   -2521,  2022, -2521, -2521, -2521,   690, -2521,  1530, -2521,  7176,
   -2521,   276, -2521,  1791, -2521,  1454,  6561, -2521,   401,  2412,
    2030, -2521, -2521, -2521,  6561, -2521,   477,  6561,  6561,  6561,
    6561,   316,   489, -2521, -2521, -2521, -2521, -2521,  7176,  1985,
   -2521,  2080, -2521,  2403, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,   316, -2521,    69, -2521, -2521,
   -2521,  1216,   167, -2521,   -58,  2289,   493, -2521, -2521, -2521,
   -2521,   316,  1876,  3581,  3581, -2521, -2521,  7733,  2001, -2521,
   -2521,  2004,  2005, -2521,  2014,  2019,  2021,  2023,   316,   669,
   -2521, -2521,   495, -2521, -2521,  2993, -2521, -2521, -2521,   496,
    2435,  2435, -2521, -2521,   500,  2437,  2431, -2521,   229, -2521,
   -2521,   167, -2521,   133,  1827, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521,  2240,  4407, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,   -74,
    2446, -2521,   385,  1431, -2521,  2240, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,  2234,
   -2521, -2521,  2016, -2521, -2521,   172, -2521,  2016,   172, -2521,
     176, -2521, -2521,  6561, -2521,   279, -2521, -2521, -2521,  2000,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,  2068,
   -2521,  2433,  2073,  2075,  2439, -2521, -2521,  2078, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,   205,  2455, -2521, -2521,   316,
    2097,   316,  1850,   313,  2142, -2521,  2044, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  1437, -2521, -2521, -2521,  6231,
    2084,    38,    67,  2104,  1028, -2521,  7176, -2521,  1909,  2454,
      67, -2521, -2521,   472, -2521, -2521, -2521, -2521,   123,  2093,
    1816, -2521, -2521, -2521,  2095,  2096,  2041,  2064, -2521,  2145,
    2109, -2521, -2521, -2521, -2521,  2260,  2046, -2521,   118,  1257,
    1875,  1257, -2521,  2119,  6561, -2521,  2121,  2122,  2128,  2130,
   -2521, -2521,  1938, -2521, -2521, -2521,  1530, -2521,   501, -2521,
     385,  1969,  1216,  1216, -2521, -2521,  6561, -2521, -2521,   167,
   -2521,  2092, -2521,  1969,  2469,  2469,  2133,    91,   313,  7779,
     313,   313,   313,   313,  1910,  7779,  7613, -2521,  7779,  7779,
    7779,  7779, -2521, -2521,   167,  2501,   167,  7613,   247,  6819,
   -2521,   385, -2521, -2521,   320, -2521, -2521,   316, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,   385,  2446, -2521, -2521, -2521,
     385, -2521,   385, -2521, -2521,  1616, -2521,  2286, -2521,  2293,
     141, -2521,   503, -2521, -2521, -2521, -2521,   510,  2016,  2523,
    2506, -2521, -2521,  1908, -2521, -2521, -2521, -2521,  2149, -2521,
     162, -2521,   162, -2521, -2521,  6561, -2521,  2089, -2521,  2123,
     231,   182,   316,  2513, -2521, -2521, -2521, -2521, -2521,  1028,
   -2521,  2151,  4207,  2114, -2521, -2521, -2521,  1928,    67, -2521,
     101, -2521, -2521, -2521,  2159,   188, -2521,  2145,  2145,   690,
   -2521,   416,  2161,  1926,  1454,  1933, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521,   316, -2521,  2070,   300, -2521, -2521,
     118, -2521,  7552,   300, -2521,  2165,  7779, -2521,   511,  7779,
    7779,  7779,  7779,   316,   512, -2521, -2521, -2521, -2521, -2521,
   -2521,  2138, -2521, -2521, -2521,  2330,  2070,   133, -2521, -2521,
   -2521, -2521,  1871,  1871, -2521,  1871, -2521,  1871,  1871, -2521,
   -2521, -2521, -2521, -2521,   268, -2521, -2521, -2521,  6561,  2143,
    1454, -2521, -2521,   513, -2521,  2563, -2521, -2521,  6819, -2521,
   -2521, -2521, -2521,  2566, -2521,   387, -2521, -2521,  2123,  2184,
     630, -2521, -2521,   126,   126,   126,   126,   126,   126, -2521,
    2550, -2521,   524, -2521,  7176,  1366, -2521, -2521, -2521,   518,
   -2521,  2145,  7176,  2145,  2041, -2521, -2521, -2521,  2337,   282,
   -2521,  1454, -2521,  1454,   130,    67, -2521, -2521, -2521, -2521,
     527, -2521, -2521, -2521, -2521,  2188,  7779, -2521,  2191,  2192,
    2199,  2200, -2521, -2521,  7613, -2521, -2521, -2521,  1871, -2521,
    1871, -2521, -2521, -2521, -2521, -2521, -2521,   162, -2521,  6561,
    2330,   231, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
     905, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    4207, -2521,  2573, -2521, -2521,   570, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,    73, -2521,  7552, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,   532, -2521, -2521, -2521, -2521,
   -2521,  1057,  1057, -2521, -2521,  1057, -2521,  7176, -2521,  2201,
   -2521, -2521, -2521, -2521, -2521, -2521,  2205, -2521, -2521,   615,
   -2521,   188, -2521,  2041
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2521, -2521, -2521, -2521, -2521,   390, -2521,   483,  -185, -2521,
   -2521,  -861,  -279, -2521, -2521, -1555, -2521, -2521, -2521, -2521,
    -510, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -1963, -2521, -1541, -2521,
     449, -2521, -2521, -2521, -2521, -2521, -2521, -2521,   727, -2521,
   -2521, -2521, -2521,  1354, -2521,  1029, -2521, -2521,   -60, -2521,
   -2521,  2559, -2521,  2560,  2236, -2521, -2521, -2521, -2521, -2521,
     793,   425, -2521,   791, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,   -98,   436,  1045, -2521, -2521,
    2317,    74, -2521,  2464, -2521, -2521,  2461, -2521,  2399, -2521,
   -2521, -2521,  2329,  2220,  1280,  2335,  -315, -2521, -2521, -2521,
   -2521, -2521,  1289,  -978, -2521, -2521, -2521, -2521, -2521, -2521,
    -140,  2267,  2410,  -196,   867, -2521,  2261,   191, -2521,  2319,
   -2521, -2521, -2521, -2521,  2323, -2521, -2521, -2521, -2521,  -327,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,  2256, -2521,
    2255, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,  -901,
   -2521, -2521,  -446, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    2152, -2521, -2521,  1104, -2521,  -903,  -811,  1968, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,   866, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  -439, -2521, -2521, -2521, -2521,
   -2521,  2129, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -1696, -2521, -2521, -2521, -2521, -2521, -2521,  1234, -2521, -2521,
    -707, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  1681, -2521, -2521, -2521, -2521,
     982, -2521, -2521, -2521, -2521, -2521, -1168, -2521, -2521,   976,
   -2521, -2521, -2521, -2521, -2521, -2521,  -817,  -541,   864,  1148,
   -2521,  -481,   800,  -825,   987, -2521,   997, -2521, -1822,    -4,
    -376, -2521, -2521, -1747,   327,  1324, -2521, -2521,   281,  1389,
   -2521, -2521, -2521, -2521, -2521, -2521,   415, -2521,   121, -2521,
    1401, -2521,  1070, -2521,   754, -2521, -2521, -2521,  -442, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,   875, -2521, -1227,
   -2521,  1061, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,  1520, -2521, -2521,
   -2521, -2521, -2521, -2521,   -69, -2521, -2521, -1484, -2521, -2521,
   -2521, -2521,   659, -2521, -1595, -2521,  -834, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521,  2656, -2521, -2521, -2521,  2568,  2654,  -585, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521,    51, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521,  2665, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521,  1124, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,  -416,  2214, -2521,
   -2521, -2521, -2521, -2521,  2045, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521,  1838, -2521, -2521,   -47, -2521, -2521,
    1127, -2521, -2521, -2521,  -686,  -192,  2434, -2521, -2521, -2521,
   -2521,   891, -2521,  -712,  2026,  1424, -2094,   789, -2521,  1126,
    1778,    68,  -134, -2521, -2521, -2521,  1565, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521,  1519, -2521,  1085,
   -2521,  -363, -2521, -2521, -2521, -2521, -2521, -2521,  -314, -2521,
   -2521, -2521, -2521, -2521, -2521,   487, -2521,  1584,   670, -2521,
   -2521, -2521, -2521, -2521,   350, -2521,  -136, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521,  1834, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    -338, -2521,  1498,  1654, -2521, -2521,   360, -2521,  -410, -2521,
   -2521,   375,   689, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    -123, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2432, -2521,  1710,   945,
    -972, -2521, -2521, -2521,  1357, -2521, -1334, -2521, -2521, -2521,
   -1337, -2521, -2521, -1318, -2521, -2521, -2521, -2521,  1381, -2521,
   -2521, -2521, -2521, -2521, -2521,   755, -2521, -2521, -2521, -2521,
   -2521, -2521,  -379, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521,  -340, -2521, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
   -2521,   730, -2521, -2521, -2521,  -224, -2521, -2521, -2521, -2521,
   -2521, -2521,   346, -2521, -2521,   706, -2521,  1053, -2521, -2521,
   -2521, -2521, -2521, -2521,  -979, -2521, -2521, -2521, -2521, -1357,
   -2521, -2521, -2521, -2521, -2521, -2521, -2520,    47, -2521, -1777,
     319, -2521, -2521, -1675,   378,   379,   704, -2521, -2105, -1997,
   -2521, -2521,    89,  -229, -2521, -2521, -2521, -2521, -1894, -2521,
   -2521, -2521, -1365, -2521, -2521,  -764, -2521,  -705,  1461,    88,
   -1604,   708, -2521,  -407, -2521, -2521, -2521, -2521,  -679, -2521,
   -1678, -2265, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2166,
   -2521,   455, -2521, -1708, -2521,  1810, -2521, -2521,  -699,  -117,
   -2521, -1461,  -113,   203,   494, -1118, -1377, -1958,   352,  -297,
   -1116,  -323, -2521,   558,   -71, -2521, -2521,  1493,  -516, -2521,
   -2521,  -144,  1840, -2521,   857, -2521, -2521, -1246,   220, -2521,
   -2521, -2521, -1837,   -14, -2521, -2521, -2521,  1534, -2521, -2521,
   -2521, -2521, -2521, -2521, -2521, -2521, -2206,   -28, -2521, -2244,
   -1792, -1234, -1019, -2521, -2521,   -11,  -435,  -403,  -372,  1080,
   -1197,    20,  1941,    77, -2521, -2521, -2521, -2521, -2521,  1660,
   -2521,  -488, -2521, -2521, -2521, -2521, -2521, -2521, -2521, -2521,
    -247,  1851,  2444, -2521, -2521, -2521, -2521
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1806
static const short yytable[] =
{
      42,   386,   268,   258,  1031,  1199,   113,   883,  1028,    57,
      59,  1347,  1172,  1016,  1181,  1813,   284,  1358,   823,  1855,
      33,   702,  1168,  2072,  2081,   417,  1274,  1178,  1179,   871,
    1180,  1380,  1183,  1184,  1746,   131,   256,   721,  2293,  1721,
    1284,    74,    77,   688,    33,  1722,  2207,  1696,  1600,  1601,
      70,  2599,  2600,  2601,  2113,  1204,   236,   925,   113,  1058,
     928,  1643,  2172,  1212,    41,   805,  1963,  1588,    41,    41,
     834,   832,   128,   670,  2433,    77,   868,  1223,   781,   338,
     874,   781,  1131,    41,  1279,   291,   127,   137,  2485,  2065,
    2068,   790,  2603,  2068,   144,   781,  1979,  1263,   149,   781,
    1198,   151,   152,   702,  2019,  1148,   807,   155,   156,  1204,
    2558,   781,  1494,   790,  1753,  1026,  2267,    41,    41,   818,
     275,  1754,   790,  2433,  1204,   269,   276,   277,  1204,   829,
    1403,   919,    41,  2245,   835,  1294,    97,  1296,   127,   299,
     300, -1804,   873,   269,  2690,   717,   232,   836,   394,   235,
     940,  1173,    41,   818,   239,    41,   129,   818,   798,    41,
      41,   818,  1506,  2352,   269,  2418,  1885,   790,  1263,   140,
     790,   881,   690,    41,    41,   690,   690,   269,  1205,  1124,
    2206,  2159,    41,   379,  1206,  1026,  1026,    41,    41,   690,
   -1804,  1026,   273,    41,  2160,   269,  1884,  1885,    41,   269,
    2418,  1885,    41,   673,   266,   381,   881,   690,    41,  2218,
     690,   269,   931,   932,    41,    97,   690,   389,   266,   201,
     690,  1275,    41,  1507,   690,  1508,   399,  1509,   690,  1026,
     296,    41,   690,   690,    41,   690,   302,   266,   690,   383,
     690,   690,   690,  1136,  1137,    41,   401,   330,   690,  2378,
    2767,   690,  1264,  1506,     1,  1026,  3002,    41,   690,   269,
     270,   271,    41,   690,  2294,  2295,  2296,  2297,  2298,     2,
       3,   690,  2281,    41,  2733,  1986,  1983,   266,   102,   141,
     266,   266,   690,   103,  2870,   405,   690,   266,  1570,  2088,
     690,   269,  1884,  1885,    41, -1804,   690,  1023,  1644,   690,
    2378,   292,  1628,  1629,   559,   649,  2408,  1155,   269,   931,
     932,    41,  2287,    82,  1190,  1191, -1804,  2557,  1021,  1539,
     949,    82,  1592,  1264,  2378,  2967,  1015,  1813,   104,   105,
    2527,  2528,  2529,  2530,    82,  1409,   106,  1196,   941,  2265,
    1750,  2483,    41,    82,  1345,     5,     6,  1740,     7,     8,
     941,  1545,   409,     9,   344,   409,   346,    65,   941,   698,
    2992,    97,  2994,   409,  2489,  1431,   941,  1022,  2471,    82,
      10,    11,  2374,    71,  1302,    82,  2828,    35,  1740,   330,
    2284,   330,  1235,    82,   641,   651,    34,  1204,    12,  1197,
      41,    41,    41,  1609,  2667,  2794,  1740,  2381,  1564,  2382,
    2383,  2384,  2385,  2386,  2387,  2306,  2769,  1380,  1279,   409,
     392,    41,  1204,   820,   686,  1645,   691,   692,  1259,  2044,
     699,   704,  2044,   706,  2069,  2092,   709,   392,   942,  2094,
     133,   134,  2271,   185,   186,  2402,    18,   692,  2402,  2065,
    2429,   187,    41,  2447,   775,   727,    79,  1141,   996,   997,
    1363,  2447,   687,  2429,  1142,   698,   692,  3001,  2968,  1513,
      18,   873,  2842,  1364,  2487,  2562,   775,  2611,  1909,   692,
    1156,  1300,    82,   943,  2400,   687,   998,   999,  1000,   808,
    2694,  2089,  2774,  2518,   259,   260,   261,   262,   263,   259,
     260,   261,   262,   263,  2774,   824,   826,  1571,  2799,    95,
    2816,  2816,   699,  2409,  2027,  2824,  2934,  2030,  2984,  1161,
     775,  2843,   824,   824,   384,  2984,  3056,  3056,  3077,  1570,
     775,   775,  1554,   902,   775,  1646,    77,  1613,   775,  3100,
     775,  2472,  3117,  1887,   775, -1804,   775,  2816,   920,  1751,
     920,   824,  2353,   920,   824,  1218,   920,  1221,  1888,  1827,
    2670,  1280,    82,   130,   403,  1410,  1405,  3128,  2768,  1407,
    1408,  1405,  2866,  1863,  1887,  1580,   380, -1804,  1887,  2559,
    2560,  1540,    82,  1187,  1308,  1359,  3085,  1158,  1427,  1888,
    1194,  1162,  1387,  1888,   873,   835,   873,  2177,   382,   107,
     690,  1980,  2833,   687,  2275,  1637,  1638,  1308,  1295,  1260,
     390,   821,  1630,    82,  1648,  2452,  1363,   908,  1363,   400,
    2504,  1829,  2484,  2246,   702,   108,  1265,  2519,  2960,  1364,
    2790,  1364,   267,  1475,  1174,  2282,  2938,  2939,  2711,   402,
    2110,  2379,  2880,   944,   943,  1489,   341,  2388,  1240,  2734,
    2219,  1207,  1386,  2020,    76,   944,  1376,  1688,   969,  2492,
    1971,  1987,  1342,   944,  1149,   672,  1537,  2500,  2501,  3042,
    1887,   944,  2434,    41,  1490,  1343,   933,  1919,   406,  2521,
   -1804,  2739,  1873,  2868,  2705,  1888,   823,   991,  1175,   409,
    1024,  1366,  2406,  1755,  2567,  2763,   109,  1265,  1224, -1804,
   -1804, -1804, -1804, -1804,   699,   982,  2936,  1367,  2427,  2766,
    1470,  2060,  2871,   822,  1919,  3112,  2658,   822,   822,  1027,
    1210,   139, -1804,   690,   690,   690,  2553,   799,   775,   775,
     272,  2149,  2741,  1542,  1476,  3076,  2746,  1346,  1571,  1208,
    1741,  1991,   702,   775,   945,   946,   947,  2966,   272,   775,
     775,  1311,  1555,  2724,   775,   948,  1663,  1759,  1405,  2292,
     984,  2404,  2829,  1557,   775,  2423,  2389,  1495,  2822,   272,
    2424,  1744,  1779,  2987,  2073,  1782,  2104,   736,    41,   934,
    1745,  2060,   272,  1510,  2220,  3150,  3113,  2060,  3114,  1849,
     110,  1511,  1138,  1027,  1596,  1597,  2522,  2671,   710,    41,
     272,  1365,   740,  1379,   272,  1850,  2677,  3106,  2680,  2299,
    1261,   658,  2045,  1567,  2229,  2059,   272,  2070,  2093,  1575,
    1609,  2712,  2095,  2390,  1550,  2272,  2176,  2104,  2403,  2891,
    3125,  2405,  2713,  2430,  2006,   924,  2448,  1992,   927,   775,
     775,   930,   134,  1262,  2449,   659,  2454,  1366,  2940,  1366,
    2770,  2060,  2516,   188,  2031,  1001,   132,  2488,  2563, -1804,
    2612,  2074,  2314,  1367,   272,  1367,  1870,  2657,  1844,    41,
   -1804,   111, -1804,  2695,   775,  2775,  2549,    41,  2075,   112,
     775,    58,  1728,    41,    44,   141,   749,  2781,  2551,    41,
    2110,  2800,   775,  2817,  2823,   143,   272,   775,  2825,  2935,
    1803,  2985,  1233,   145,  1348,  2907,  2523,  1350,  2986,  3057,
    3063,  3078,  2381,   272,  2382,  2383,  2384,  2385,  2386,  2387,
    1251,  2076,  3101,  1351,  2946,  3118,  2949,  2950,  2951,  2952,
    3142, -1804,  1609,  3082,  2672,   775,  2673,   195,  2373,    82,
    2376,  2375,   233,  1002,  1990,   303,  1388,   194,  2466,   775,
    1881,  1882,  2391,  1883,  1613,   198,   269,  1884,  1885,    41,
      82,  2077,  1650,  2564,  3035,  3036,  3151,  2758,  2795,  1280,
    1517,  2568,   304,  1739,  2933,   234,  1385,  2822,  2822,   754,
    1493,   182,  3083,    41,  3087,  1998,  1003,  1389,  3088,   249,
    2078,   756,   757,   687,  1999,  1886,   241,  1969,  2392,  2079,
     759,  2922,   697,  1360,    41,   250, -1804,  1368,  1377,  1368,
    2185,  1671,   259,   260,   261,   262,   263,  2832,  2000,  2393,
     699,  2001,  2397,   699,  2937,  1392,  1395, -1804,  1351,   706,
      82,   252,  1778,  1828,  2955,  1781,  2943,  1671,    82,  2002,
     830,   253,    41,   824,   775,  2963,   824,   824,   824,   824,
      82,   775,  1854,   875,   775,    41,   697,  2693,    41, -1804,
    2697,  1352,   881,    45,    41,   824,  1613,   775,    81,  2251,
      41,   775,   254,    63,  1244,  2371,    41,    46,  3108,   775,
    3110,   775,   775,   257,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,  2923,    47,  2925,   964,   965,  2815,  2598,  2598,  2598,
    2598,   775,   775,  1290,   285,    41,   775,  2525,   775,  1968,
     698,   715,  2422,  2525,  1909,  2534,  2535,  2536,  2537,  1032,
    1033,  1034,  1380,  1466,   134,  1926,  1928,  1353,  1818,    63,
     785,   699,  1938,   265,    82,  2003,   286,   775,   775,   775,
    3133,    48,  2388,   794,  1400,  1471,  1672,    41,   824,  2506,
    1492,    41,  1496,   824,  2965,   698,  1352,   775,  1636,  2110,
     288,  2286, -1804,  3048,  1640,  1673,  1674,   136,  1026,   306,
      41,  1806,  1672,    41,  1807, -1511,  2591,  2591,  2591,  2591,
    1391, -1804, -1804,  2304,   289,  1675,    41,  2796,  2653,  2004,
      41,  1673,  1674,   698,   775,  2941,  2005,  1609,  2173,   290,
     824, -1804,  2431,  2519,  1806,   652,    82,  1807,  1231,  1843,
      41,  1675,  -266,  2099,  2046,    82,  1016,   294,  1383,   775,
      41,    82,  1651,  1552,  2357,   824,   824,    82,   653,   295,
     824,  1355,  1353,  1652,  1561,  1562,   775,  1518,    34,    35,
    2358,  2359,  1679,  1519,  1520,  1521,   775,  1356,  2360,  3087,
     414,  1685,   835,  3088,  2013,  1653,    41,   690,   656,  2107,
     699,  2389,  1654,  1522,  2274,  1876,    82,   920,   824,   824,
     297,    41,  2666,   873,  2150,  2669,  2151,  1808,   958,  2674,
    1809,  2517,  2361,   307, -1804,  2162,  3006, -1804,  2463,   959,
    1354,  2362, -1804,  1632,    41,   301,  1027,  1027,  1126,  -266,
    2105,  1641,  1609,  1641,   684,  1027,  2307,  2117,    82,  2118,
    1808, -1804,    82,  1809,   783,  1887,  -266,  2110,  2390,  2412,
    2363,  2414,  2415,  3080,   315,   133,   134,  1651,   792,   907,
    1888,  1613,   797,   911,  2478,  1609,  1355,   915,  1652,  2678,
      41,   960,   324,  2806,   811,    41,   652,  1889,  1027, -1804,
    2047,    82,  1356,  2726,   325,  2727,   961,   331,  2744,  -266,
    1653,  1368,  2048,  1891,    41,  2364,   334,  1654,   971,   653,
     308,  1523,  1377,   337,  1524,  1368,  2598,  2598,   335,  1883,
    2598,   690,   269,  1884,  1885,    41,  3103,   309,   336,  1127,
   -1804,  2219,    41, -1804,  1735,  1736,  1737,  1237,  1525,  -266,
    2110, -1804,   690,  2513,  1893, -1804,  2548,  2365,  2773,   340,
     696,  2776,  2777,  2778,  2779, -1804,  1894, -1804,  1526,   984,
     342,  1886,  1416,   714,   133,   134,  3027,  1417,  -266,  1419,
     310,   775,   775,   775,   343,   775,  1613,  -266,  1416, -1804,
   -1804,  2214,  2699,  1417,  1418,  1419,   962,  2391,  2323,   316,
     786,  1414,  1415,  1527,  2356,  2591,  2591,  2701,  1895,  2591,
    2894,   775,  2895,  1472,  1788,  1472,   803,   804,  2865,  1613,
     311,  2865,   810,  1528,  1529,   812,  3047,  3006,   775,  1050,
    1579,   134,  3053, -1804,  1530,   347,   813,   348,  1238,  1531,
    2847,  3109,   351,  2392,   352,   819,  1816,  1896,   353,   312,
    1658,  1659,   775,   354,  1823,  1824,   775,   824,   313,  1897,
    2242,   358,  1188,  1189,  2393,    41,  1192,  1193,  1666,  1667,
     274,  1898,  1899,  2049,   279,   357,  3092, -1804,  1532,   368,
    1900, -1804,   369,  1901, -1804, -1804,   317,   775,  2100,   372,
     923,   272,   775,   926,   377,  3027,   698,  1819,  1820, -1804,
     945,   946,  1852,   318,  2804,  2805,   775,  2869,  2215,  2216,
    2119,  1533,  2848,   775,   387,   388,  1051,  1213,  1214,  1215,
    1216,   775,   397,   391,   395,  2947,   396,  1877,  1251,   404,
    1902,  2947,  2425,  1052,  2956,  2957,  2958,  2959,   398,   407,
     415,   892,   657,   662,   664,   665,   319,   259,   260,   261,
     262,   263,   824,   824,   835,   674,  3092,   666,   671,   676,
     873,   677,  2598,   678,   680,   682,   824,   681,  2598,  2598,
    2073,  2598,  2598,  2598,  2598,   683,  1053,  2849,  2753,  2850,
    2598,   685,   873,  2455,  2121,  1027,   320,   973,  2123,   974,
     975,   893,   976,  2126,  2851,   979,  2841,  2130,   977,  2132,
    2133,  2134,  2852,  2752,  2014,   978,  2853,   980,  2927,   981,
     983,     2,     3,   987,   988,   321,  1054,  2026,  2026,   989,
     990,  2026,  1014,   994,   322,  1013,    82,   134,   894,  1017,
    2110,  2854,  2419,  1019,  1020,  1025,  1029,  1902,  1037,  2061,
    2061,  2591,  1040,  2061,  1902,  1055,  1038,  2591,  2591,  1041,
    2591,  2591,  2591,  2591,  1056,  1042,  1043,  2074,  1044,  2591,
    1045,  1135,  3055,  1046,  1047,  3058,  3059,  3060,  3061,  1048,
    2096,  1059,  1060,  1392,  2075,  1061,  1064,   775,  1065,  2709,
    1068,  1070,  1071,   690,  1368,  1072,   824,     5,     6,   690,
       7,     8,  1902,  1073,  1128,     9,  1139,  2848,  1074,  2598,
    1075,  1887,  2598,  2598,  2598,  2598,  1140,  1152,  1076,  1143,
    1146,   690,    10,    11,  1078,  1144,  1888,  2076,  1147,  2997,
     718,   718,  1154,  1166,   775,   895,  2544,   775,  2546,  1157,
      12,  1151,  2756,  1889,  1171,  1368,  1890,  2865,  1195,   775,
     775,   775,   775,  1185,  2061,  1219,  1198,  1227,  1228,  1891,
    2164,  1816,  1229,  1230,  2169,  2169,  1234,  2077,  1239,  2233,
    2234,  1236,  2849,   775,  2850,  1240,  1248,  2681,  1250,  1270,
    1271,  1204,  3120,  2181,  1278,  1272,  3052,  1273,  2591,  2851,
    1282,  2591,  2591,  2591,  2591,  1285,  2078,  2852,  1288,  1286,
    1893,  2853,  1287,   734,  1333,  2079,  1602,  1603,  1604,  1605,
      13,   896,  1894,  1341,  1344,   735,  1362,  1382,  1399,  2598,
    1400,  1401,  1398,  1402,  1411,   718,  2854,  2598,  1425,  1428,
     775,  2898,  3074,  1433,  1426,   935,  1461,  1902,  1902,  2906,
    2235,  2236,  2237,  2238,  2239,  2240,  1902,  2590,  2590,  2590,
    2590,  1464,   897,  1469,  1895,  1482,  1210,  2228,  1468,    89,
    1500,   835,   835,  1016,  2682,  1502,  1504,  1515,  1541,   699,
    2700,  1516,  1488,  1543,  1544,  1546,  1548,  2252,  2625,  2626,
    2627,  2683,  2629,  2630,  2631,  2632,  2633,  2634,  1553,  1556,
    1558,  2637,  1567,  1896,  1574,  1576,  1581,  1582,  2591,  1506,
    2735,  1584,  1280,  1622,  1620,  1897,  2591,    50,    51,    52,
      53,    54,    55,    56,  1625,  1623,  1631,  1898,  1899,  1691,
     898,  1680,  1693,  2997,  2684,  1027,  1900,  1694,  1697,  1901,
    1698,   183,   191,   649,  1724,  1726,  1727,   272,  1730,   649,
    2061,  1742,  2663,  1902,  2663,  1729,  1731,  1743,  1747,  2748,
    2290,  1641,  1902,  1749,  1756,   775,  2750,   775,  1758,   751,
    2709,  3052, -1804,  2964,  2685,  2061,  1760,  1027,  1787,  1761,
   -1804, -1804, -1804, -1804,  1763,  1766,  2026,  1790,  1792,     1,
    1793,  2511,  1794,  1795,   899,  1799,   191,  1802,  1796,  1800,
     690,   690,   191,  2686,     2,     3,  1798,  1801,  1804,  2061,
     935,  1817,  2687,  1902,  1805,  1902,  1279,  3026,  1830,  1832,
    1833,    16,  1834,   651,  1838,  1841,  2061, -1804,  2716,   651,
    1847,  1848,  1853,     4,  1856,  1368,  1860, -1804,   753, -1804,
    1857,  1866,  1880,  1913,  1914,  1915,  1874,   755,  1919,  1966,
    1606,   948,  1921,  1607, -1804,  1608,  1125,  1967,  1377,  1978,
    1368,  1984, -1804,  1994,  2009,  1995, -1804,  2011,  1735,  2012,
    2023,   775,   191,  2034,   191,  1609,  2437, -1804,  2035,  2043,
       5,     6,  2036,     7,     8,  1610,  2040,  2082,     9,  2083,
    2084, -1804,  1095,  1096,  1097,  1098,  1099,  1100,  2098,  2085,
    2086,  2087,  2102,  2114,  1935,    10,    11,  2115,  1101,  1102,
    1103,   775,   775,  2116,  1699,  2717,  2122,  2125,  2135,  2136,
    2137,   775,  2140,    12,   775,  2141,  2143,  1611,  2145,  2464,
    2147,  1612,  2718,  2158,  2163,  2180,  2590,  2590,  2178,  2188,
    2590,  2189,  1816,  2191,  2479,  2709,  2481,  2709,   191,  2193,
    2192,  2194,  2195,   775,  3116, -1804,   775,  2196,  2212,  2213,
    2496,  2230,  2250,   947,   775,   775,  3093,  3094,  3095,  3096,
    3097,  3098,  2257,  3034,  2221,  2719,  2222,  2223,  2224,  2225,
     775,  2226,  2227,  2259,  2268,  2269,  2270,  2061,  2900,  1902,
    2273,  2277,  2278,    13,  2285,  1902,  1902,  1902,  1902,  1902,
    1902,  2288,  2311,   191,  2312,  2317,     1,  2309,  2372,  1613,
    2310,  2380,  2399,  2400, -1804,  2720,  2410, -1804,  2401, -1804,
    2897,     2,     3,   824,  2426,   824,  2407,   935,  2864, -1749,
    2413,  2864,  2416,  2663,  2231,  2232,  2233,  2234,  2432, -1804,
     712,  1902,  2438,  2439,  2721,  2440,  2441,  2442,  1104, -1804,
    2443,  1105,  2444,  2722,  2061,  2445,  2743,  2446,  2450,  2453,
    2589,  2589,  2589,  2589,  2061,  2061,  2840,  2456, -1804,  2459,
    2458,  2465,  2469,  2473,   788,  2614,  2615,  2014,  2480, -1804,
     793,  2477,   795,  2618,  2491,  2499,   802,  2509,  2515,   802,
    2540, -1804,   802,  2517,  2531, -1804,  2543,     5,     6,  2555,
       7,     8,   814,  2554,  2564,     9,  2378,  2235,  2236,  2237,
    2238,  2239,  2240,    14,  2571,  2433,  2609,  2613, -1804,  2623,
    2624,   863,    10,    11,  2642,  2628,  2635,  2636,  2643,   876,
     879,   882,  2646,  2647,  2219,   903,  2648,  2649,  2650,  2651,
      12,  2652,  2709,   913,  1902,  2665,  1902,  2668,  2675,  1700,
    1352,  2689,  2691,  3011,  2696,  2661,  2698,  2661,  2702,   937,
    1987,  1902,    15,  2725,  2731,  2736,  2061,  2679,  2061,  2737,
    1106,  2738,  2590, -1804,  2739,  2751,  2754,  2757,  2590,  2590,
    2761,  2590,  2590,  2590,  2590,  1107,   761,  2771,  2772,  1108,
    2590,   942, -1804,  2786,    16,  1368,  2797,  2790,  2807,  1902,
    1027,  2808,  2809,  1602,  1603,  1604,  1605,  1701,   791,  3153,
    2816,  2810,  2826,   775,  2827,  2837,  2811,  2838,  2812,  1702,
    2813,  2845,   873,  2663,  2860,  2397,  2873,  1109,  2874,  1703,
    2882,  2876,  2885,  2877,  2878,  2169,  2879,  2890,  2745,  2169,
    2892,  2893,  2896,   824,  2899,  2903,   775,  1704,   385,  2905,
     824,  2909,   865,  2911,  2912,  1110,  2915,  1705,  2820,  2821,
    1706,  2913,   884,   890,   775,   935,   906,  2917, -1804,  2924,
     910,  2921,   912,  1707,  1111,   775,   916,  2926,   918,  2928,
    2929,  2932,  1902,  2434,  2961,    81,  2930,    41,  2931,  2942,
    1902,  2944,  2980,  1902,  1902,  1902,  1902,  2780,  2953,  2981,
    2988,  2989,  2990,  2998,   775,     2,     3,  2991,  3009,  2590,
    3012,  3024,  2590,  2590,  2590,  2590,  3025,  3033,   718,  3040,
    3041,  2787,  1708,  3054,   937,  1093,  1094,  3043,  2061,  2235,
    2236,  2237,  2238,  2239,  2240,  3064,  3075,  2290,  3079,  2589,
    2589,  3081,  3086,  2589,  3099,  3111,  3119,  2864,  3137,  3121,
    3122,   690,  1709,  2495,  2814,  2428,  1112,  3123,  3124,  3147,
    3136,  2204,  1710,  3148,  2451,  1566,    72,  1865,  2165,    73,
     560,  2476,  2174,   935,   349,   197,   202,  2061,   281,  1632,
     345,     5,     6,  1711,     7,     8,  1712,   675,  1713,     9,
     408,   283,  1129,   350,  1682,  1095,  1096,  1097,  1098,  1099,
    1100,  2124,   661,  2728,  1683,   376,    10,    11,   374,   667,
     668,  1101,  1102,  1103,  3134,  1840,  1714,  2142,  1337,  2590,
    1752,  2024,  2032,  1113,    12,  1715,   901,  2590,  1825,  2154,
    1595,   699,  2785,  2542,   699,  1160,  2661,  1606,  1918,  1902,
    1607,  2249,  1608,  3140,  2161,  1599,  1936,  1497,    82,  2908,
      67,  1177,  1177,  1177,    68,  1177,   157,  1177,  1177,  1092,
    1093,  1094,  1609,    89,    89,    69,  2858,  1872,   809,   972,
     339,  1027,  1610,  1619,  2244,  2883,  1875,  2888,  1879,   993,
    2846,  2971,  1276,  1484,  1536,  3107,  1981,  2533,  2656,  2979,
    1222,  1549,  1474,  1434,    13,  2638,  2655,   824,   838,  3039,
     159,  2369,   775,  1397,  2148,  2279,   882,   839,  3141,  1725,
    1692,  3130,  2308,  3065,  1611,  2676,   840,  1246,  1612,  2370,
    2071,   841,  2881,  2377,  2710,  3073,  2659,  2867,  1635,  2660,
    1095,  1096,  1097,  1098,  1099,  1100,  2616,  2872,  2396,   160,
    1902,   937,  1129,  1325,  3007,  2803,  1101,  1102,  1103,  3008,
    1283,  1104,  3129,  2570,  1105,  2704,  1627,  2532,   161,  2983,
    3046,  2802,  1902,  2945,   842,  2061,  1291,  1291,  2962,  1293,
    1593,   865,   843,  2061,  2954,  2589,   416,  2097,     0,     0,
       0,  2589,  2589,  1491,  2589,  2589,  2589,  2589,     0,     0,
    2061,  1339,  2061,  2589,     0,  1902,  1613,   162,     0,     0,
       0,     0,     0,  2970,     0,     0,  1203,     0,     0,   163,
       0,     0,   865,     0,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,   884,     0,     0,     0,   844,  1226,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,     0,     0,     0,  1035,  1036,  1027,   166,  1027,     0,
       0,  1902,     0,   845,     0,     0,  2061,     0,  2888,  1049,
     846,     0,   847,   167,     0,  1062,  1063,     0,     0,     0,
    1067,     0,   848,  1106,     0,     0,     0,     0,  1903,     0,
    1077,     0,     0,     0,     0,     0,  1104,     0,  1107,  1105,
       0,     0,  1108,     0,     0,    16,     0,     0,   849,     0,
    2787,     0,     0,   168,     0,     0,   850,     0,  1902,     0,
       0,     0,  2589,     0,     0,  2589,  2589,  2589,  2589,  3062,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
    1109,     0,     0,  1632,     0,     0,  1467,     0,     0,     0,
       0,     0,   170,   851,    89,     0,    89,   882,   802,   171,
     699,     0,   172,     0,  1902,  1483,   814,     0,  1110,   882,
       0,     0,     0,   191,  1902,     0,  1498,     0,     0,   852,
       0,     0,     0,   173,     0,     0,   174,  1111,   175,   937,
    2818,  2819,  2820,  2821,     0,  1903,     0,     0,     0,     0,
     775,  3104,  1903,     0,     0,     0,     0,   176,   775,     0,
       0,     0,     0,     0,     0,    89,     0,   853,  1106,     0,
       0,     0,     0,     0,     0,   177,     1,     0,   854,     0,
       0,     0,  2589,  1107,     0,     0,     0,  1108,     0,     0,
    2589,     2,     3,     0,     0,     0,     0,     0,     0,     0,
    1903,     0,     0,  1027,  1559,  1902,     0,  2061,     0,     0,
       0,     0,     0,  2235,  2236,  2237,  2238,  2239,  2240,  1112,
       0,     0,     0,     0,     0,  1109,     0,     0,  1586,     0,
       0,     0,     0,  1589,     0,     0,     0,     0,     0,  1477,
    1478,  1479,     0,  1902,     0,     0,  1618,   937,     0,     0,
       0,     0,     0,  1110,     0,     0,     0,     0,     0,  1501,
       0,     0,     0,   775,     0,     0,     0,     5,     6,     0,
       7,     8,  1111,     0,     0,     9,     0,     0,   855,   856,
     857,     0,     0,     0,     0,     0,  1113,     0,     0,     0,
       0,   858,    10,    11,     0,     0,  1538,     0,     0,     0,
       0,  1665,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,  1661,  1662,  1297,     0,     0,     0,     0,  1678,
    1406,   884,     0,     0,     0,     0,     0,  1413,     0,     0,
    1424,     0,     0,     0,     0,  1903,  1903,     0,  1563,     0,
       0,     0,     0,  1429,  1903,     0,     0,  1432,  1578,     0,
       0,     0,     0,     0,  1112,  1438,   882,  1440,  1441,     0,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1456,  1457,  1458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1459,  1460,     0,
       0,     0,  1462,     0,  1463,   859,  1764,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,  1298,     0,     0,     0,
       0,  1113,     0,     0,  1299,     0,     0,     0,     0,     0,
    1300,     0,  1301,     0,     0,     0,     0,     0,     0,     0,
       0,  1903,     0,  1302,     0,     0,     0,     0,     0,     0,
    1903,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,
       0,  1303,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1095,  1096,  1097,  1098,  1099,  1100,  1304,     0,     0,
       0,     0,  1305,     0,     0,     0,     0,  1101,  1102,  1103,
      14,  1903,     0,  1903,  1306,     0,     0,  1837,     0,     0,
       0,  1307,     0,     0,     0,     0,  1845,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   882,     0,     0,     0,
       0,     0,  1846,     0,  1095,  1096,  1097,  1098,  1099,  1100,
       0,     0,     0,  1903,     0,     0,     0,   183,     0,    15,
    1101,  1102,  1103,     0,     0,     0,  2187,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,  1916,     0,     0,     0,     0,
    1797,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   882,  1970,   882,     0,     0,     0,   876,
       0,     0,     0,     0,  1822,     0,     0,     0,  1479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2018,     0,     0,     0,     0,     0,  1104,     0,  1203,
    1105,  1095,  1096,  1097,  1098,  1099,  1100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1101,  1102,  1103,
       0,     0,     0,     0,     0,  1862,  1308,     0,     0,     0,
       0,     0,     0,  1309,     0,     0,     0,  1903,     0,     0,
       0,     0,     0,  1903,  1903,  1903,  1903,  1903,  1903,     0,
    1104,     0,     0,  1105,     0,  1310,     0,   882,   191,     0,
    1311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1767,  1768,  1769,
       0,  1771,     0,     0,     0,     0,     0,     0,     0,  1903,
       0,     0,     0,     0,   269,  1884,  1885,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1786,  1903,  1903,
    1903,  1903,     0,     0,     0,     0,     0,     0,   882,  1106,
     882,     0,     0,     0,     0,     0,     0,     0,     0,   882,
       0,     0,     0,  2575,  1107,     0,     0,     0,  1108,     0,
       0,     0,   718,   718,   718,     0,   718,   718,   718,   718,
     718,   718,     0,     0,     0,   718,     0,  1104,     0,     0,
    1105,     0,     0,     0,     0,     0,     0,  2186,     0,     0,
       0,     0,  1106,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,  1842,  2101,
       0,  1108,  1903,     0,  1903,     0,  2209,     0,     0,  2200,
    2201,     0,  1786,  1903,  1110,  1903,     0,     0,     0,  1903,
    2210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,     0,     0,  1109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2243,  1589,     0,     0,     0,  1903,     0,     0,
       0,  2152,  2153,  1479,  2156,     0,     0,  1110,   698,     0,
       0,     0,     0,  2253,  2254,  2255,  2256,     0,     0,     0,
       0,  2261,  2262,  2263,  2264,  2179,  1111,     0,  2266,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,  1112,     0,     0,   935,     0,
       0,     0,     0,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1903,     0,  2211,     0,     0,     0,  1109,     0,  1903,     0,
       0,  1903,  1903,  1903,  1903,     0,     0,  2313,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,  2315,  2316,  1110,     0,     0,     0,     0,  2320,
    2321,     0,  1113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,  1903,  1903,     0,
       0,  1903,     0,     0,     0,     0,     0,     0,  1095,  1096,
    1097,  1098,  1099,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,  1102,  1103,     0,     0,     0,
    2138,     0,     0,  2138,     0,  1113,   882,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2301,     0,  2302,
       0,     0,     0,  1887,     0,  1112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   882,  1888,  1903,
       0,     0,  1903,     0,  1903,     0,     0,  1903,     0,     0,
       0,     0,     0,     0,     0,  2576,     0,     0,  2577,     0,
       0,     0,     0,     0,     0,     0,     0,  2467,  2468,     0,
    1589,  2578,     0,     0,     0,     0,  2475,     0,     0,  2493,
       0,   712,     0,  2497,  2486,     0,     0,     0,     0,     0,
       0,     0,  1113,     0,     0,     0,  2508,     0,     0,     0,
       0,   191,     0,  2502,  2503,     0,     0,     0,     0,     0,
       0,     0,  2580,     0,  1104,     0,     0,  1105,     0,     0,
       0,     0,     0,     0,  2581,     0,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,  1903,     0,
       0,     0,     0,     0,     0,     0,     0,  2550,  2552,  2545,
       0,  2547,     0,     0,     0,     0,  2582,     0,     0,     0,
    1903,     0,     0,  2457,     0,     0,  2462,     0,     0,     0,
       0,     0,     0,  1903,     0,     0,     0,     0,     0,  1903,
    1903,     0,  1903,  1903,  1903,  1903,     0,     0,     0,     0,
    2617,  1903,     0,  1903,     0,  2583,     0,     0,     0,     0,
    1095,  1096,  1097,  1098,  1099,  1100,     0,  2584,     0,  2619,
    2620,     0,     0,  2621,  2622,     0,  1101,  1102,  1103,  2585,
    2586,     0,   865,     0,  1903,     0,  1106,     0,  2587,     0,
    2639,  2588,     0,     0,     0,     0,     0,     0,     0,   272,
       0,  1107,     0,  2654,     0,  1108,  1430,  2645,     0,  1903,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1805,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1805, -1805, -1805, -1805,     0,     0,     0,   935,
       0,     0,     0,  1109,  1939,  1940,  1941,  1942,  1943,  1944,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1805,
       0,     0,     0,     0,   882,     0,  1903,     0,     0,     0,
    1903,  1110,     0,  1903,  1903,  1903,  1903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1805,     0,
    1111,     0,     0,     0,   882,     0,     0,  1786,  1786,     0,
       0,     0,     0,  1945,     0,     0,     0,     0,  1903,   191,
       0,     0,  1903,     0,     0,     0,  1104,     0,     0,  1105,
       0,  2742,  1903,     0,     0,  2747,     0,     0,     0,     0,
   -1805,     0,   937,     0,     0,     0,     0,     0,     0,  2490,
       0,     0,  1786,     0,     0,     0,     0,     0,     0,     0,
    1786,  1786,     0,     0,     0,     0,  2762,     0,     0,     0,
   -1805,     0,     0, -1805,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,     0,
    1903,     0,     0,     0,     0,     0,     0, -1805,  1903,     0,
    2783,     0,     0,     0,     0, -1805,     0, -1805,     0,     0,
       0,     0,     0,  1903,     0,     0, -1805,  3013,     0,     0,
       0,     0, -1805,     0,     0,     0,     0,     0,     0,     0,
   -1805,     0,     0,     0, -1805,     0,     0,     0,     0,     0,
   -1805,     0,     0,     0, -1805, -1805, -1805, -1805,  1106,  1113,
       0,  1903,     0,     0,     0,     0,     0,     0,  2749, -1805,
       0,     0,     0,  1107,     0,     0,     0,  1108,  1748,     0,
       0,     0,     0,  3014,     0,     0, -1805,     0,     0, -1805,
       0, -1805,     0,     0,     0,   935,     0,  2764, -1805,     0,
    2639,     0,     0,     0,     0,     0,     0,     0,  3015,     0,
       0, -1805,     0,     0,     0,  1109,     0,  3016,     0,     0,
       0, -1805,     0,     0,     0,     0,  2782,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
   -1805, -1805,     0,  1110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3017,     0, -1805,  1946,     0,     0,     0,
       0,  3018,  1111, -1805,     0,     0,     0, -1805,     0,  1947,
       0,     0,     0,     0,     0,     0, -1805, -1805, -1805,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,   882,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,  1096,  1097,
    1098,  1099,  1100,     0,     0,     0,     0,     0,     0,  2729,
       0,     0,     0,  1101,  1102,  1103,     0,     0,     0,     0,
       0,     0,     0,  1948,     0,     0,  2920,     0,     0,     0,
    1949,     0,     0,     0,  1112, -1805,     0,     0,  1589,     0,
       0,     0,     0,     0,     0,  3019, -1805,  1095,  1096,  1097,
    1098,  1099,  1100,     0,     0,     0,     0,     0,     0,     0,
    1786,     0,     0,  1101,  1102,  1103,     0,     0,     0,  1950,
       0,     0,     0,     0,   159,     0,     0,     0,     0,  1589,
       0,     0,     0,     0,     0,     0,     0, -1805,     0,     0,
       0,     0,     0,  2639,  1951,     0,     0,     0,  2974,     0,
    2976,  1113,     0,     0,  1952,  1953,     0,     0,     0,     0,
    1954,     0,     0,   160,  2901,     0,     0,     0,     0,     0,
    1955,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,   882,
       0,     0,  1956,     0,     0,  1957,  1958,   882,     0, -1805,
       0,  1959,     0,  1104,     0,     0,  1105,     0,     0,     0,
       0,     0,     0,   937,     0,     0,     0,     0,     0,   191,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
    3037,     0,     0,   163,     0, -1805,     0,     0,     0,     0,
       0,     0,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,     0,     0,  1105,     0,  1960,     0,
       0,   165,     0,     0,     0,     0,     0,     0,  3020,     0,
    1961,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1805,  3066,  3067,     0,  3069,   167,  3071,  3072,
       0,     0,     0,     0,     0,     0, -1805, -1805, -1805, -1805,
   -1805, -1805, -1805,     0, -1805, -1805,     0,     0,     0,     0,
       0,  1177,  1177,  1177,  1177,  1177,  1177,     0,     0,     0,
       0, -1805,     0,     0,     0,  1106,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,     0,  1108,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,  3115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,   171,     0,  1106,   172,     0,     0,  3126,
       0,  3127,  1109,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     1,     0,  1108,  1775,     0,   173,     0,     0,
     174,     0,   175,     0,     0,     0,   418,     2,     3,     0,
    1110,     0,     0,     0,     0,   419,  3138,     0,     0,     0,
       0,   176,     0,     0,     0,     0,     0,   420,   421,  1111,
     422,     0,  1109,     0,     0,     0,     0,     0,     0,   177,
       0,     0,  3143,  3144,   423,     0,  3145,     0,     0,   937,
       0,   424,  3102,     0,     0,     0,     0,     0,     0,     0,
    1110,     0,   425,   426,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   428,  1111,
     429,   430,   431,     5,     6,   432,     7,     8,   433,     0,
     434,     9,   435,   436,     0,     0,     0,     0,     0,   437,
       0,     0,   438,     0,   439,   440,   441,     0,    10,    11,
       0,  1112,     0,     0,   442,     0,   443,   444,     0,   445,
       0,   446,   447,     0,     0,   448,    12,     0,     0,   449,
     450,   451,     0,   452,   453,     0,     0,     0,   454,   455,
       0,   456,     0,     0,     0,   457,     0,   458,   459,     0,
       0,     0,     0,   460,     0,     0,     0,   461,     0,     0,
     462,  1112,   463,     0,   464,  3146,   465,     0,   466,   467,
       0,   468,   469,   470,     0,     0,     0,   471,  1113,   472,
     473,     0,   474,     0,     0,     0,     0,     0,     0,     0,
     475,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   477,     0,     0,   478,   479,     0,     0,
     480,   481,     0,     0,   482,   483,     0,     0,     0,     0,
       0,     0,     0,   484,   485,   486,     0,   487,  1113,     0,
       0,     0,     0,     0,     0,     0,     0,   488,   489,   490,
       0,   491,     0,     0,  1786,   492,   493,     0,     0,     0,
     494,     0,     0,     0,     0,     0,     0,     0,   495,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   498,     0,
       0,     0,     0,     0,   499,   500,     0,     0,     0,     0,
     501,     0,     0,   502,     0,     0,     0,   503,   504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,   506,     0,     0,     0,
       0,     0,     0,     0,   507,     0,     0,     0,     0,     0,
     508,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
     509,     0,   510,   511,     0,     0,     0,     0,     0,     0,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1095,  1096,  1097,  1098,  1099,  1100,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,  1101,
    1102,  1103,  2326,  2327,     0,     0,  2328,  2329,  2330,     0,
     513,     0,     0,     0,     0,  1095,  1096,  1097,  1098,  1099,
    1100,   514,     0,     0,     0,   515,     0,     0,     0,   516,
       0,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,   518,     0,     0,     0,   519,     0,
       0,     0,     0,     0,  1095,  1096,  1097,  1098,  1099,  1100,
     520,     0,     0,     0,     0,     0,   521,   522,   523,   524,
    1101,  1102,  1103,   525,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,   527,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2331,   529,     0,   530,     0,
       0,     0,  2332,     0,     0,     0,     0,     0,     0,   531,
       0,   532,     0,     0,   533,     0,     0,     0,     0,     0,
     534,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,  1105,     0,     0,     0,  2333,     0,     0,     0,
       0,     0,     0,     0,     0,  2334,   535,     0,     0,   536,
       0,     0,     0,     0,     0,   537,     0,     0,   538,   539,
       0,  1104,     0,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,   540,  2335,  2336,     0,     0,     0,     0,
     541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   542,   543,   544,   545,   546,   547,   548,
    1104,     0,   549,  1105,   550,     0,   551,     0,     0,  2337,
       0,     0,     0,     0,     0,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2338,     0,     0,     0,     0,  1107,     0,     0,     0,
    1108,  1757,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,  1108,  1762,     0,     0,     0,     0,  1109,  1095,
    1096,  1097,  1098,  1099,  1100,     0,     0,  2339,     0,     0,
       0,     0,     0,     0,     0,  1101,  1102,  1103,     0,     0,
       0,     0,  1106,     0,     0,     0,  1110,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,  1108,     0,     0,     0,  1111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,     0,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,  1111,     0,  1109,
       0,     0,     0,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1111,  1112,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,
       0,     0,     0,     0,     0,  1104,     0,     0,  1105,  1112,
    1101,  1102,  1103,     0,     0,     0,     0,     0,  1095,  1096,
    1097,  1098,  1099,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,     0,  1113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,  1095,  1096,  1097,  1098,  1099,  1100,     0,     0,
       0,     0,     0,     0,     0,     0,  1113,     0,  1101,  1102,
    1103,     0,     0,     0,     0,     0,     0,  2340,  2341,  2342,
    2343,  2344,  2345,  2346,  2347,  2348,  2349,     0,     0,     0,
       0,     0,     0,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,     0,     0,     0,  1113,     0,  1106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,     0,  1108,  1770,     0,     0,
    1104,     0,     0,  1105,     0,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,  1104,     0,     0,  1105,     0,     0,
       0,     0,     0,     0,  1109,     0,     0,  1095,  1096,  1097,
    1098,  1099,  1100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,  1102,  1103,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,     0,  1104,     0,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,     0,     0,  1095,
    1096,  1097,  1098,  1099,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1101,  1102,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,  1108,  1772,     0,     0,     0,  1106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1107,     0,  1112,     0,  1108,  1773,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1106,     0,     0,  1104,     0,     0,  1105,     0,     0,     0,
       0,     0,     0,  1109,     0,  1107,     0,  1110,     0,  1108,
    1774,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1111,     0,     0,     0,
    1113,  1110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1104,     0,  1109,  1105,     0,
    1111,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
       0,     0,     0,     0,     0,  1110,     0,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,  1111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,  1106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,  1112,     0,  1108,  1095,  1096,  1097,  1098,  1099,
    1100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,  1095,  1096,  1097,  1098,  1099,  1100,  1106,     0,     0,
       0,     0,  1109,     0,     0,  1113,  1112,  1101,  1102,  1103,
       0,     0,  1107,     0,     0,  1776,  1108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
    1110,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,  1111,
       0,     0,     0,     0,  1109,     0,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1777,     0,     0,
       0,     0,     0,  1113,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,  1111,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,
       0,     0,  1095,  1096,  1097,  1098,  1099,  1100,     0,     0,
       0,  1104,     0,     0,  1105,     0,     0,     0,  1101,  1102,
    1103,  1112,     0,     0,     0,  1095,  1096,  1097,  1098,  1099,
    1100,     0,     0,     0,     0,     0,     0,  1104,     0,     0,
    1105,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1095,  1096,
    1097,  1098,  1099,  1100,     0,     0,  1095,  1096,  1097,  1098,
    1099,  1100,     0,  1112,  1101,  1102,  1103,     0,     0,     0,
       0,     0,  1101,  1102,  1103,     0,     0,     0,  1113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1106,     0,     0,     0,     0,  1881,  1882,
    1113,  1883,     0,     0,   269,  1884,  1885,    41,  1107,     0,
       0,     0,  1108,     0,     0,     0,     0,     0,  1104,  1106,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,  1108,     0,
       0,  1104,     0,  1886,  1105,     0,     0,     0,     0,     0,
    1109,  1095,  1096,  1097,  1098,  1099,  1100,     0,  1090,  1091,
    1092,  1093,  1094,  1780,     0,     0,     0,  1101,  1102,  1103,
       0,     0,     0,     0,  1104,     0,  1109,  1105,  1110,     0,
       0,     0,  1104,     0,     0,  1105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1111,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,     0,     0,     0,
       0,  1095,  1096,  1097,  1098,  1099,  1100,     0,     0,     0,
    1106,     0,     0,     0,     0,     0,     0,  1101,  1102,  1103,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,  1108,
       0,     0,     0,  1106,     0,     0,     0,     0,   698,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,  1112,
       0,     0,  1108,  1095,  1096,  1097,  1098,  1099,  1100,     0,
       0,     0,     0,     0,     0,     0,  1106,  1109,     0,  1101,
    1102,  1103,     0,     0,  1106,  1112,     0,  1104,     0,     0,
    1105,  1107,     0,     0,     0,  1108,     0,     0,     0,  1107,
    1109,     0,     0,  1108,     0,  1110,   722,   723,     0,     0,
       0,     0,   269,   724,   725,    41,     0,     0,     0,     0,
       0,     0,     0,     0,  1111,     0,  1113,     0,  1110,     0,
       0,     0,     0,  1109,     0,     0,  1881,  1882,     0,  1883,
       0,  1109,   269,  1884,  1885,    41,   726,  1111,     0,     0,
       0,   727,  1113,     0,     0,     0,     0,     0,   728,     0,
       0,  1110,     0,     0,     0,     0,     0,  1104,     0,  1110,
    1105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1111,  1886,     0,     0,     0,     0,   729,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,  1105,     0,  1107,     0,     0,     0,  1108,  1112,
       0,     0,     0,     0,     0,   722,   723,     0,     0,     0,
       0,   269,   724,   725,    41,     0,     0,     0,     0,     0,
       0,     0,     0,  1887,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,  1109,     0,  1888,     0,
    1112,     0,     0,  1113,     0,   726,    82,     0,   730,     0,
     727,     0,     0,     0,     0,  1889,     0,   728,  1890,  1106,
       0,     0,     0,     0,  1110,     0,  1113,     0,     0,     0,
       0,  1891,     0,     0,  1107,     0,   698,     0,  1108,     0,
       0,     0,     0,  1111,     0,   729,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
       0,  1106,  1893,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,  1894,     0,  1107,     0,     0,     0,
    1108,     0,     0,     0,   722,   723,     0,     0,     0,     0,
     269,   724,   725,    41,  1110,   731,     0,     0,     0,     0,
     732,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,  1112,  1895,     0,  1109,     0,
       0,     0,     0,     0,   726,    82,     0,   730,   733,   727,
    2046,     0,     0,     0,     0,     0,   728,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
       0,     0,     0,     0,     0,  1896,     0,     0,     0,     0,
       0,     0,     0,   734,   729,  1111,     0,  1897,     0,     0,
       0,     0,     0,     0,     0,   735,     0,     0,     0,  1898,
    1899,     0,  1113,     0,     0,     0,     0,     0,  1900,     0,
       0,  1901,     0,   736,     0,  1112,     0,     0,   737,   272,
       0,   738,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   739,   722,   723,     0,     0,     0,   740,   269,
     724,   725,    41,     0,   731,     0,     0,     0,   741,   732,
       0,  1887,     0,   742,     0,     0,   743,     0,     0,   744,
       0,     0,     0,     0,     0,     0,  1888,  1112,   745,   746,
       0,     0,     0,   726,    82,     0,   730,   733,   727,     0,
       0,     0,  1113,  1889,     0,   728,  2047,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2048,  1891,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1200,
     747,     0,   734,   729,   748,     0,     0,     0,     0,     0,
       0,     0,   749,     0,   735,     0,     0,     0,     0,     0,
       0,     0,     0,   750,  1113,     0,     0,     0,     0,   751,
    1893,     0,   736,     0,     0,     0,     0,   737,  1881,  1882,
     738,  1883,  1894,     0,   269,  1884,  1885,    41,     0,     0,
       0,   739,  1881,  1882,   752,  1883,     0,   740,   269,  1884,
    1885,    41,     0,   731,     0,     0,     0,   741,   732,     0,
       0,     0,   742,     0,     0,   743,     0,     0,   744,     0,
       0,     0,     0,  1886,  1895,     0,     0,   745,   746,     0,
       0,     0,     0,    82,     0,   730,   733,  1886,   753,     0,
       0,     0,     0,     0,  1094,   754,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,   757,   758,
       0,     0,     0,  1896,     0,     0,   759,     0,     0,   747,
       0,   734,     0,   748,     0,  1897,     0,   272,     0,     0,
       0,   749,     0,   735,     0,     0,     0,  1898,  1899,  2049,
       0,     0,   750,     0,  2155,     0,  1900,     0,   751,  1901,
       0,   736,     0,     0,     0,     0,   737,   272,     0,   738,
       0,     0,     0,  1095,  1096,  1097,  1098,  1099,  1100,     0,
     739,     0,     0,   752,     0,     0,   740,     0,     0,  1101,
    1102,  1103,   731,     0,     0,     0,   741,   732,     0,     0,
       0,   742,     0,     0,   743,     0,     0,   744,   698,     0,
       0,     0,     0,     0,     0,     0,   745,   746,     0,     0,
       0,     0,   698,     0,     0,   733,     0,   753,     0,     0,
       0,     0,     0,     0,   754,     0,   755,  1939,  1940,  1941,
    1942,  1943,  1944,     0,     0,     0,   756,   757,   758,     0,
       0,     0,     0,     0,     0,   759,     0,  2512,   747,     0,
     734,     0,   748,     0,     0,     0,   272,     0,  1881,  1882,
     749,  1883,   735,     0,   269,  1884,  1885,    41,     0,     0,
       0,   750,     0,     0,     0,     0,     0,   751,     0,     0,
     736,     0,     0,     0,     0,   737,  1945,     0,   738,  1881,
    1882,     0,  1883,     0,     0,   269,  1884,  1885,    41,   739,
       0,     0,   752,  1886,     0,   740,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   741,  2046,     0,     0,  1104,
     742,     0,  1105,   743,     0,     0,   744,     0,     0,     0,
       0,     0,     0,     0,  1886,   745,   746,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   753,     0,     0,     0,
    2573,  2574,     0,   754,     0,   755,   269,  1884,  1885,    41,
       0,     0,     0,     0,     0,   756,   757,   758,     0,     0,
       0,     0,     0,     0,   759,     0,     0,   747,     0,     0,
       0,   748,     0,     0,     0,   272,     0,     0,     0,   749,
       0,     0,     0,     0,     0,  2575,     0,     0,     0,     0,
     750,     0,     0,  1887,     0,     0,   751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1887,  1888,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   698,     0,
       0,   752,  1888,     0,     0,  1889,     0,     0,  1890,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,  1889,
       0,  1891,  2047,     0,     0,     0,  1107,     0,     0,   698,
    1108,     0,     0,     0,  2048,  1891,     0,     0,     0,     0,
    2573,  2574,     0,     0,     0,   753,   269,  1884,  1885,    41,
       0,     0,   754,     0,   755,     0,     0,     0,     0,     0,
       0,  1892,  1893,     0,   756,   757,   758,     0,  1109,     0,
       0,     0,     0,   759,  1894,     0,  1893,     0,     0,     0,
       0,     0,     0,     0,   272,  2575,  2573,  2574,  1894,  1946,
     698,   203,   269,  1884,  1885,    41,  1110,     0,     0,     0,
       0,     0,  1947,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,  1895,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1895,  2575,     0,     0,     0,     0,     0,     0,   204,   205,
       0,     0,     0,     0,     0,     0,     0,   206,     0,     0,
       0,     0,     0,     0,     0,  1896,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1948,  1897,     0,  1896,
       0,     0,     0,  1949,     0,     0,     0,     0,     0,  1898,
    1899,  1897,     0,     0,     0,     0,     0,     0,  1900,     0,
       0,  1901,     0,  1898,  1899,     0,     0,  1112,     0,   272,
       0,     0,  1900,  1887,     0,  1901,     0,     0,     0,     0,
     698,     0,  1950,   272,     0,     0,     0,     0,  1888,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1887,  1889,     0,  1951,  1890,     0,
       0,     0,     0,     0,     0,     0,     0,  1952,  1953,  1888,
       0,  1891,     0,  1954,     0,     0,   698,     0,     0,     0,
       0,     0,     0,  1955,  1113,     0,  1889,     0,     0,  1890,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2219,
       0,     0,  1891,     0,     0,  1956,     0,     0,  1957,  1958,
       0,     0,  1893,     0,  1959,  1887,     0,     0,     0,     0,
       0,     0,     0,     0,  1894,     0,     0,     0,     0,     0,
    1888,     0,     0,     0,     0,     0,     0,   207,     0,     0,
       0,     0,  3049,  1893,     0,     0,     0,  2576,     0,     0,
    2577,     0,     0,     0,     0,  1894,     0,     0,     0,     0,
       0,     0,     0,  2578,     0,     0,  1895,     0,     0,     0,
       0,  1960,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,  1961,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,  1895,     0,     0,
       0,     0,     0,  2579,  2580,  1896,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,  2581,  1897,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1898,
    1899,     0,     0,     0,   211,  1887,  1896,     0,  1900,     0,
       0,  1901,     0,     0,     0,     0,   212,     0,  1897,   272,
    1888,     0,     0,     0,     0,     0,   213,     0,  2582,     0,
    1898,  1899,     0,     0,     0,     0,     0,  2576,     0,  1900,
    2577,     0,  1901,     0,   214,     0,     0,     0,     0,     0,
     272,  1887,     0,  2578,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1888,  2583,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,  2584,
       0,  2219,     0,  2576,     0,     0,  2577,     0,     0,     0,
       0,  2585,  2586,     0,  2580,     0,     0,     0,     0,  2578,
    2587,     0,     0,  2588,     0,     0,  2581,     0,     0,     0,
     217,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,     0,     0,     0,     0,     0,
    2580,     0,     0,     0,     0,     0,     0,     0,  2582,   219,
       0,     0,  2581,     0,     0,     0,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,     0,   223,     0,   224,     0,  2583,     0,     0,
       0,     0,     0,     0,  2582,     0,     0,     0,     0,  2584,
       0,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,  2585,  2586,     0,     0,     0,     0,     0,     0,     0,
    2587,     0,   226,  2588,     0,     0,     0,     0,     0,     0,
       0,   272,     0,  2583,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2585,  2586,     0,
       0,     0,     0,     0,     0,   227,  2587,     0,     0,  2588,
       0,     0,     0,     0,     0,     0,     0,   272
};

static const short yycheck[] =
{
       4,   328,   194,   188,   716,   866,    66,   523,   713,    13,
      14,   989,   837,   699,   848,  1499,   212,   996,   499,  1560,
       0,   424,   833,  1698,  1702,   363,   929,   844,   845,   517,
     847,  1003,   849,   850,  1411,    82,   176,   447,  1996,  1376,
     943,    45,    46,   419,    24,  1379,  1868,  1365,  1275,  1276,
      30,  2295,  2296,  2297,  1750,     5,   154,   545,   118,   738,
     548,  1307,  1809,   874,    26,   481,  1621,  1264,    26,    26,
     509,   506,    76,   388,     5,    79,   515,     5,   454,   264,
     519,   457,   787,    26,     5,   225,    66,    91,  2182,  1693,
    1694,   467,  2298,  1697,    98,   471,    98,    32,   102,   475,
       5,   105,   106,   506,     5,     5,   482,   111,   112,     5,
    2276,   487,    20,   489,    18,    24,  1938,    26,    26,   495,
      18,    25,   498,     5,     5,    23,    24,    25,     5,   505,
    1031,   541,    26,    60,   510,   960,    62,   962,   118,   237,
     238,    89,   518,    23,  2409,    25,   150,   510,   340,   153,
      63,    25,    26,   529,   158,    26,    79,   533,    24,    26,
      26,   537,     5,   132,    23,    24,    25,   543,    32,    95,
     546,    24,   419,    26,    26,   422,   423,    23,    74,    25,
      24,    20,    26,     5,    80,    24,    24,    26,    26,   436,
      60,    24,   196,    26,  1798,    23,    24,    25,    26,    23,
      24,    25,    26,   395,     5,     5,    24,   454,    26,  1887,
     457,    23,    24,    25,    26,   141,   463,     5,     5,   145,
     467,   933,    26,    66,   471,    68,     5,    70,   475,    24,
     234,    26,   479,   480,    26,   482,   240,     5,   485,     5,
     487,   488,   489,    85,    86,    26,     5,   251,   495,     6,
    2515,   498,   187,     5,    29,    24,    25,    26,   505,    23,
      24,    25,    26,   510,    46,    47,    48,    49,    50,    44,
      45,   518,  1980,    26,     5,   147,  1633,     5,    53,     5,
       5,     5,   529,    58,     5,     5,   533,     5,    22,   204,
     537,    23,    24,    25,    26,   336,   543,     5,   356,   546,
       6,   227,   133,   134,   364,   365,   427,   455,    23,    24,
      25,    26,  1987,   187,   855,   856,   357,  2275,   536,   341,
     599,   187,   186,   187,     6,     5,   698,  1811,   103,   104,
    2224,  2225,  2226,  2227,   187,  1042,   111,   330,   271,  1934,
     388,   386,    26,   187,     5,   120,   121,     5,   123,   124,
     271,  1212,   356,   128,   280,   359,   282,     0,   271,   187,
    2880,   287,  2882,   367,  2186,  1064,   271,   585,   455,   187,
     145,   146,  2047,    30,   245,   187,   147,    28,     5,   383,
    1984,   385,   898,   187,   364,   365,    27,     5,   163,   382,
      26,    26,    26,   292,  2391,  2561,     5,     9,   336,    11,
      12,    13,    14,    15,    16,  2009,     5,  1379,     5,   413,
     336,    26,     5,   371,   418,   473,   420,   421,   160,     5,
     424,   425,     5,   427,     5,     5,   430,   353,   341,     5,
     454,   455,     5,    17,    18,     5,     0,   441,     5,  2043,
       5,    25,    26,     5,   448,    62,   624,   617,    54,    55,
     242,     5,   346,     5,   624,   187,   460,  2889,   138,  1171,
      24,   837,   536,   255,     5,     5,   470,     5,  1584,   473,
     618,   232,   187,   386,     5,   346,    82,    83,    84,   483,
       5,   396,     5,   392,    17,    18,    19,    20,    21,    17,
      18,    19,    20,    21,     5,   499,   500,   231,     5,   350,
       5,     5,   506,   624,  1672,     5,     5,  1675,     5,   544,
     514,   585,   516,   517,   280,     5,     5,     5,     5,    22,
     524,   525,  1229,   527,   528,   583,   530,   426,   532,     5,
     534,   618,     5,   392,   538,   576,   540,     5,   542,   587,
     544,   545,   511,   547,   548,   883,   550,   885,   407,   506,
       9,   148,   187,   615,   280,  1043,  1037,  3077,  2516,  1040,
    1041,  1042,  2667,   336,   392,  1251,   388,   437,   392,  2277,
    2278,   593,   187,   852,   468,   427,  3008,   381,  1059,   407,
     859,   616,  1017,   407,   960,   961,   962,  1814,   388,   364,
     837,   593,   459,   346,  1971,  1300,  1301,   468,   961,   341,
     388,   559,   433,   187,  1309,  2146,   242,   530,   242,   388,
    2205,  1512,   657,   540,  1017,   390,   551,  2221,  2824,   255,
     551,   255,   423,  1139,   498,  1982,  2792,  2793,   328,   388,
    1746,   388,   427,   566,   386,  1151,   423,   249,   576,   370,
     468,   537,  1014,   544,   587,   566,   427,  1352,   652,  2190,
     468,   523,   979,   566,   554,   423,  1197,  2198,  2199,  2924,
     392,   566,   544,    26,  1152,   980,   381,   548,   388,   356,
     540,   548,  1575,  2670,   512,   407,  1157,   681,   552,   683,
     388,   473,   388,   587,  2288,  2507,   461,   551,   616,   637,
     638,   639,   640,   641,   698,   423,  2790,   489,   423,   423,
    1135,   610,   423,   665,   548,   423,   388,   665,   665,   713,
     660,   618,    22,   960,   961,   962,  2271,   583,   722,   723,
     618,   574,  2469,  1204,  1140,  2990,  2473,   388,   231,   625,
     388,   172,  1135,   737,   647,   648,   649,  2831,   618,   743,
     744,   502,  1230,  2439,   748,   658,   381,  1426,  1229,  1995,
     676,  2069,   523,  1234,   758,  2092,   368,   665,  2595,   618,
    2094,   388,  1461,  2868,   363,  1464,  1738,   384,    26,   484,
     388,   610,   618,   616,  1890,   160,  3041,   610,  3043,   388,
     555,   624,   624,   787,  1272,  1273,   473,   246,    25,    26,
     618,   427,   409,   427,   618,   388,  2400,   279,  2402,   581,
     542,   388,   388,   576,   427,   388,   618,   388,   388,  1248,
     292,   511,   388,   425,  1224,   388,     5,  1789,   388,  2713,
    3064,   388,   522,   388,  1649,   544,   388,   268,   547,   833,
     834,   550,   455,   575,   388,   422,   388,   473,  2796,   473,
    2518,   610,  2219,   427,   321,   451,   239,   388,   388,   279,
     388,   450,  2020,   489,   618,   489,   359,   388,    25,    26,
     321,   636,   292,   388,   868,   388,    25,    26,   467,   644,
     874,    24,  1388,    26,   352,     5,   493,   388,    25,    26,
    1996,   388,   886,   388,   388,   350,   618,   891,   388,   388,
     423,   388,   896,     5,   992,   423,   583,   995,   388,   388,
     388,   388,     9,   618,    11,    12,    13,    14,    15,    16,
     914,   510,   388,   155,  2808,   388,  2810,  2811,  2812,  2813,
     388,   231,   292,   536,   383,   929,   385,    13,  2046,   187,
    2048,  2047,   427,   539,  1639,   427,   574,   455,  2165,   943,
      17,    18,   554,    20,   426,   519,    23,    24,    25,    26,
     187,   550,   165,   468,  2917,  2918,   341,  2498,  2562,   148,
      24,   476,   454,  1402,  2786,   110,  1013,  2804,  2805,   586,
    1155,    24,   585,    26,   344,   338,   582,   615,   348,   427,
     579,   598,   599,   346,   347,    62,   533,   245,   600,   588,
     607,  2768,    24,   997,    26,   427,   426,  1001,  1002,  1003,
    1834,   478,    17,    18,    19,    20,    21,  2611,   371,   621,
    1014,   374,   455,  1017,  2791,  1019,  1020,   478,   155,  1023,
     187,   455,  1461,  1511,  2816,  1464,  2803,   478,   187,   392,
      24,   427,    26,  1037,  1038,  2827,  1040,  1041,  1042,  1043,
     187,  1045,  1558,    24,  1048,    26,    24,  2412,    26,   359,
    2415,   293,    24,   531,    26,  1059,   426,  1061,    24,  1920,
      26,  1065,   427,    18,    24,  2044,    26,   545,  3031,  1073,
    3033,  1075,  1076,   422,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  2769,   570,  2771,   638,   639,   427,  2294,  2295,  2296,
    2297,  1105,  1106,    24,   427,    26,  1110,  2223,  1112,  1625,
     187,   441,  2091,  2229,  2230,  2231,  2232,  2233,  2234,   106,
     107,   108,  2094,  1127,   455,  1606,  1607,   369,  1504,    84,
     460,  1135,  1620,    25,   187,   498,   427,  1141,  1142,  1143,
     235,   619,   249,   473,   587,    24,   623,    26,  1152,    24,
    1154,    26,  1156,  1157,  2829,   187,   293,  1161,  1298,  2275,
     455,  1986,   623,  2940,  1304,   642,   643,    20,    24,   624,
      26,   161,   623,    26,   164,   618,  2294,  2295,  2296,  2297,
      20,   642,   643,  2008,   427,   662,    26,  2564,    24,   552,
      26,   642,   643,   187,  1198,  2799,   559,   292,   188,   427,
    1204,   662,  2105,  2807,   161,   623,   187,   164,    24,  1547,
      26,   662,   363,  1729,   291,   187,  1902,   427,    24,  1223,
      26,   187,   435,  1227,   157,  1229,  1230,   187,   646,    25,
    1234,   473,   369,   446,  1238,  1239,  1240,   301,    27,    28,
     173,   174,  1340,   307,   308,   309,  1250,   489,   181,   344,
     359,  1349,  1628,   348,    24,   468,    26,  1504,   367,  1740,
    1264,   368,   475,   327,  1969,    20,   187,  1271,  1272,  1273,
     427,    26,  2390,  1649,  1790,  2393,  1792,   267,   332,  2395,
     270,   388,   215,   363,   161,  1801,  2890,   164,    20,   343,
     427,   224,   235,  1297,    26,   427,  1300,  1301,   427,   450,
    1739,  1305,   292,  1307,   413,  1309,  2011,    23,   187,    25,
     267,   188,   187,   270,   457,   392,   467,  2433,   425,  2083,
     253,  2085,  2086,  2998,   624,   454,   455,   435,   471,   529,
     407,   426,   475,   533,    20,   292,   473,   537,   446,    20,
      26,   395,    25,  2577,   487,    26,   623,   424,  1352,   292,
     427,   187,   489,    23,    25,    25,   410,    25,    20,   510,
     468,  1365,   439,   440,    26,   298,    25,   475,   645,   646,
     450,   435,  1376,   388,   438,  1379,  2573,  2574,    25,    20,
    2577,  1628,    23,    24,    25,    26,    20,   467,   618,   518,
     267,   468,    26,   270,  1398,  1399,  1400,   427,   462,   550,
    2516,   344,  1649,  2214,   481,   348,  2267,   340,  2524,   455,
     423,  2527,  2528,  2529,  2530,   292,   493,   623,   482,  1345,
      25,    62,    18,   436,   454,   455,  2910,    23,   579,    25,
     510,  1435,  1436,  1437,    25,  1439,   426,   588,    18,   645,
     646,  1880,  2421,    23,    24,    25,   500,   554,  2033,   363,
     463,    24,    25,   517,  2039,  2573,  2574,  2429,   535,  2577,
      23,  1465,    25,  1136,  1468,  1138,   479,   480,  2665,   426,
     550,  2668,   485,   537,   538,   488,  2937,  3081,  1482,   363,
     454,   455,  2943,   426,   548,    25,   489,    25,   518,   553,
      59,  3032,    25,   600,    25,   498,  1500,   574,   618,   579,
     284,   285,  1506,    56,  1508,  1509,  1510,  1511,   588,   586,
    1913,   427,   853,   854,   621,    26,   857,   858,   640,   641,
     196,   598,   599,   600,   200,   388,  3010,   358,   592,   618,
     607,   637,    25,   610,   640,   641,   450,  1541,  1730,   427,
     543,   618,  1546,   546,   427,  3029,   187,   647,   648,   426,
     647,   648,  1556,   467,  2573,  2574,  1560,  2673,  1881,  1882,
    1756,   625,   131,  1567,   423,     5,   450,   611,   612,   613,
     614,  1575,    25,   388,   455,  2809,   618,  1581,  1582,   423,
    1584,  2815,  2098,   467,  2818,  2819,  2820,  2821,   255,   388,
     358,   102,    20,    25,    25,    25,   510,    17,    18,    19,
      20,    21,  1606,  1607,  1980,    20,  3090,    25,    25,   427,
    1986,    25,  2809,    25,    25,   388,  1620,   618,  2815,  2816,
     363,  2818,  2819,  2820,  2821,     5,   510,   196,  2489,   198,
    2827,   388,  2008,  2149,  1757,  1639,   550,   388,  1761,   299,
     388,   152,   388,  1766,   213,   622,  2624,  1770,   388,  1772,
    1773,  1774,   221,  2487,  1658,   388,   225,     5,  2774,   388,
     299,    44,    45,   388,   388,   579,   550,  1671,  1672,   622,
     388,  1675,   618,   388,   588,   427,   187,   455,   189,   615,
    2796,   250,  2089,   618,     8,   423,   476,  1691,   427,  1693,
    1694,  2809,   427,  1697,  1698,   579,   523,  2815,  2816,   427,
    2818,  2819,  2820,  2821,   588,   427,   427,   450,   427,  2827,
     427,   263,  2946,   427,   427,  2949,  2950,  2951,  2952,   427,
    1724,   427,   427,  1727,   467,   427,   427,  1731,   427,  2434,
     427,   427,   427,  1980,  1738,   427,  1740,   120,   121,  1986,
     123,   124,  1746,   427,   417,   128,   456,   131,   427,  2946,
     427,   392,  2949,  2950,  2951,  2952,     5,   657,   427,   616,
     593,  2008,   145,   146,   427,   616,   407,   510,   417,  2885,
     446,   447,   427,   323,  1778,   286,  2257,  1781,  2259,   657,
     163,   456,  2494,   424,     8,  1789,   427,  2984,     5,  1793,
    1794,  1795,  1796,   594,  1798,   380,     5,   427,   427,   440,
    1804,  1805,   427,   427,  1808,  1809,   427,   550,   587,    19,
      20,   341,   196,  1817,   198,   576,     8,   363,    13,   573,
       5,     5,  3056,  1827,   417,   657,  2942,   657,  2946,   213,
     427,  2949,  2950,  2951,  2952,   427,   579,   221,    63,    25,
     481,   225,    25,   354,    89,   588,    33,    34,    35,    36,
     233,   362,   493,   455,   455,   366,    25,     5,   618,  3056,
     587,   427,   593,   427,   468,   541,   250,  3064,   427,    20,
    1874,  2732,  2988,    20,   624,   551,   427,  1881,  1882,  2740,
      90,    91,    92,    93,    94,    95,  1890,  2294,  2295,  2296,
    2297,   427,   403,   427,   535,   427,   660,  1901,   624,    61,
     623,  2277,  2278,  2589,   450,   347,   554,    17,     5,  1913,
    2426,    18,   624,    25,    25,   150,   215,  1921,  2328,  2329,
    2330,   467,  2332,  2333,  2334,  2335,  2336,  2337,    24,   587,
     621,  2341,   576,   574,   479,   479,   618,     5,  3056,     5,
    2456,   544,   148,    25,   544,   586,  3064,     6,     7,     8,
       9,    10,    11,    12,   318,   396,   544,   598,   599,   427,
     471,    25,   427,  3079,   510,  1969,   607,   427,   427,   610,
     427,   133,   134,  2033,   662,   388,   618,   618,   455,  2039,
    1984,   388,  2389,  1987,  2391,   574,   544,   388,   388,  2477,
    1994,  1995,  1996,   388,   388,  1999,  2484,  2001,    25,   510,
    2705,  3117,   131,  2828,   550,  2009,   388,  2011,   427,   388,
      33,    34,    35,    36,   388,   388,  2020,   615,   624,    29,
       5,  2213,     5,     5,   535,     5,   188,   388,   577,   480,
    2277,  2278,   194,   579,    44,    45,   618,   624,   427,  2043,
     716,   427,   588,  2047,   623,  2049,     5,  2908,   551,    25,
      25,   434,   427,  2033,   533,    63,  2060,   322,   363,  2039,
       5,     5,   388,    73,   427,  2069,   357,   196,   579,   198,
     427,   594,    13,   417,   417,     5,   624,   588,   548,     5,
     267,   658,   544,   270,   213,   272,   762,    25,  2092,    98,
    2094,   427,   221,   618,   427,   624,   225,   623,  2102,     5,
     637,  2105,   264,   423,   266,   292,  2110,   236,   423,   427,
     120,   121,   457,   123,   124,   302,   457,   427,   128,   427,
     427,   250,    90,    91,    92,    93,    94,    95,     8,   427,
     427,   427,     5,    25,   321,   145,   146,    25,   106,   107,
     108,  2145,  2146,   587,    61,   450,   388,   388,    24,    24,
      24,  2155,   388,   163,  2158,    24,   388,   344,     5,  2163,
     618,   348,   467,     5,   618,     8,  2573,  2574,   618,   322,
    2577,    24,  2176,   341,  2178,  2880,  2180,  2882,   340,   455,
     341,   618,   341,  2187,  3045,   357,  2190,   427,   422,   455,
    2194,     5,    25,   649,  2198,  2199,  3013,  3014,  3015,  3016,
    3017,  3018,     5,  2915,   427,   510,   427,   427,   427,   427,
    2214,   427,   427,     5,    24,    13,    13,  2221,  2734,  2223,
      25,   593,   593,   233,   615,  2229,  2230,  2231,  2232,  2233,
    2234,   427,     5,   395,     5,     5,    29,   618,   427,   426,
     618,     7,   388,     5,   267,   550,    25,   270,   618,   272,
    2731,    44,    45,  2257,     8,  2259,   624,   933,  2665,   618,
      25,  2668,    25,  2670,    17,    18,    19,    20,   388,   292,
     432,  2275,   624,   388,   579,    25,   587,   624,   246,   302,
     388,   249,   388,   588,  2288,   388,  2471,   388,   388,    20,
    2294,  2295,  2296,  2297,  2298,  2299,  2623,     5,   321,   271,
     564,   388,     5,     5,   466,  2309,  2310,  2311,     5,   237,
     472,   544,   474,  2317,     5,   388,   478,   569,   624,   481,
     437,   344,   484,   388,   618,   348,   618,   120,   121,   427,
     123,   124,   494,   388,   468,   128,     6,    90,    91,    92,
      93,    94,    95,   353,   624,     5,   551,   624,   207,   622,
     622,   513,   145,   146,   617,    24,    24,    24,   443,   521,
     522,   523,    24,    24,   468,   527,    25,    25,    25,    25,
     163,    25,  3077,   535,  2378,   427,  2380,   427,    25,   296,
     293,    25,     5,  2899,   388,  2389,   388,  2391,   265,   551,
     523,  2395,   402,   587,   465,     5,  2400,  2401,  2402,   427,
     368,   388,  2809,   426,   548,   237,    24,   423,  2815,  2816,
     388,  2818,  2819,  2820,  2821,   383,   448,     5,   388,   387,
    2827,   341,   437,    20,   434,  2429,   137,   551,   427,  2433,
    2434,   427,   427,    33,    34,    35,    36,   354,   470,  3151,
       5,   427,     5,  2447,    13,   618,   427,   207,   427,   366,
     427,     5,  2828,  2860,   438,   455,   388,   425,    25,   376,
       5,   388,   365,   388,    25,  2469,   388,   617,  2472,  2473,
     328,   427,   388,  2477,   370,   566,  2480,   394,     5,    25,
    2484,   388,   514,   388,   388,   453,   341,   404,    19,    20,
     407,   427,   524,   525,  2498,  1171,   528,   388,   238,   624,
     532,   455,   534,   420,   472,  2509,   538,   388,   540,   388,
     388,   573,  2516,   544,    13,    24,   388,    26,   388,   427,
    2524,   388,   236,  2527,  2528,  2529,  2530,  2531,   618,   236,
       7,    25,   624,   444,  2538,    44,    45,   388,    25,  2946,
     389,   427,  2949,  2950,  2951,  2952,   618,   388,  1224,   388,
     624,  2555,   469,   388,   716,    20,    21,   624,  2562,    90,
      91,    92,    93,    94,    95,   427,   423,  2571,     5,  2573,
    2574,     5,   388,  2577,    24,   238,   388,  2984,     5,   388,
     388,  2828,   499,  2193,  2588,  2102,   554,   388,   388,   388,
    3100,  1864,   509,   388,  2145,  1241,    37,  1568,  1805,    39,
     364,  2176,  1811,  1279,   287,   141,   145,  2611,   209,  2613,
     281,   120,   121,   530,   123,   124,   533,   397,   535,   128,
     353,   211,   784,   288,  1344,    90,    91,    92,    93,    94,
      95,  1764,   371,  2442,  1345,   316,   145,   146,   315,   383,
     385,   106,   107,   108,  3090,  1541,   563,  1781,   967,  3056,
    1416,  1669,  1676,   621,   163,   572,   527,  3064,  1510,  1795,
    1271,  2665,  2541,  2248,  2668,   827,  2670,   267,  1598,  2673,
     270,  1917,   272,  3115,  1799,  1274,  1615,  1157,   187,  2748,
      24,   843,   844,   845,    30,   847,   118,   849,   850,    19,
      20,    21,   292,   855,   856,    30,  2645,  1573,   484,   654,
     266,  2705,   302,  1279,  1915,  2709,  1579,  2711,  1582,   683,
    2642,  2845,   934,  1148,  1195,  3029,  1631,  2230,  2368,  2855,
     886,  1223,  1138,  1069,   233,  2350,  2366,  2731,   126,  2921,
     257,  2042,  2736,  1023,  1789,  1980,   898,   135,  3117,  1382,
    1359,  3081,  2012,  2967,   344,  2399,   144,   909,   348,  2043,
    1697,   149,  2705,  2049,  2435,  2984,  2378,  2668,  1297,  2380,
      90,    91,    92,    93,    94,    95,  2311,  2679,  2060,   296,
    2774,   933,   934,   963,  2891,  2572,   106,   107,   108,  2892,
     942,   246,  3079,  2289,   249,  2433,  1293,  2229,   315,  2860,
    2934,  2571,  2796,  2807,   192,  2799,   958,   959,  2826,   959,
    1266,   833,   200,  2807,  2815,  2809,   362,  1727,    -1,    -1,
      -1,  2815,  2816,  1153,  2818,  2819,  2820,  2821,    -1,    -1,
    2824,   970,  2826,  2827,    -1,  2829,   426,   354,    -1,    -1,
      -1,    -1,    -1,  2837,    -1,    -1,   868,    -1,    -1,   366,
      -1,    -1,   874,    -1,    -1,    -1,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,   886,    -1,    -1,    -1,   256,   891,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,
      -1,    -1,    -1,    -1,   722,   723,  2880,   404,  2882,    -1,
      -1,  2885,    -1,   281,    -1,    -1,  2890,    -1,  2892,   737,
     288,    -1,   290,   420,    -1,   743,   744,    -1,    -1,    -1,
     748,    -1,   300,   368,    -1,    -1,    -1,    -1,  1584,    -1,
     758,    -1,    -1,    -1,    -1,    -1,   246,    -1,   383,   249,
      -1,    -1,   387,    -1,    -1,   434,    -1,    -1,   326,    -1,
    2934,    -1,    -1,   460,    -1,    -1,   334,    -1,  2942,    -1,
      -1,    -1,  2946,    -1,    -1,  2949,  2950,  2951,  2952,  2953,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,    -1,    -1,
     425,    -1,    -1,  2967,    -1,    -1,  1128,    -1,    -1,    -1,
      -1,    -1,   499,   371,  1136,    -1,  1138,  1139,  1140,   506,
    2984,    -1,   509,    -1,  2988,  1147,  1148,    -1,   453,  1151,
      -1,    -1,    -1,  1155,  2998,    -1,  1158,    -1,    -1,   397,
      -1,    -1,    -1,   530,    -1,    -1,   533,   472,   535,  1171,
      17,    18,    19,    20,    -1,  1691,    -1,    -1,    -1,    -1,
    3024,  3025,  1698,    -1,    -1,    -1,    -1,   554,  3032,    -1,
      -1,    -1,    -1,    -1,    -1,  1197,    -1,   435,   368,    -1,
      -1,    -1,    -1,    -1,    -1,   572,    29,    -1,   446,    -1,
      -1,    -1,  3056,   383,    -1,    -1,    -1,   387,    -1,    -1,
    3064,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1746,    -1,    -1,  3077,  1236,  3079,    -1,  3081,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,   554,
      -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,  1260,    -1,
      -1,    -1,    -1,  1265,    -1,    -1,    -1,    -1,    -1,  1141,
    1142,  1143,    -1,  3117,    -1,    -1,  1278,  1279,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,  1161,
      -1,    -1,    -1,  3137,    -1,    -1,    -1,   120,   121,    -1,
     123,   124,   472,    -1,    -1,   128,    -1,    -1,   546,   547,
     548,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,
      -1,   559,   145,   146,    -1,    -1,  1198,    -1,    -1,    -1,
      -1,  1333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    -1,  1331,  1332,   116,    -1,    -1,    -1,    -1,  1338,
    1038,  1223,    -1,    -1,    -1,    -1,    -1,  1045,    -1,    -1,
    1048,    -1,    -1,    -1,    -1,  1881,  1882,    -1,  1240,    -1,
      -1,    -1,    -1,  1061,  1890,    -1,    -1,  1065,  1250,    -1,
      -1,    -1,    -1,    -1,   554,  1073,  1388,  1075,  1076,    -1,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1105,  1106,    -1,
      -1,    -1,  1110,    -1,  1112,   663,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,   621,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
     232,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1987,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
    1996,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,   289,    -1,    -1,
      -1,    -1,   294,    -1,    -1,    -1,    -1,   106,   107,   108,
     353,  2047,    -1,  2049,   306,    -1,    -1,  1539,    -1,    -1,
      -1,   313,    -1,    -1,    -1,    -1,  1548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1558,    -1,    -1,    -1,
      -1,    -1,  1551,    -1,    90,    91,    92,    93,    94,    95,
      -1,    -1,    -1,  2089,    -1,    -1,    -1,  1579,    -1,   402,
     106,   107,   108,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,  1594,    -1,    -1,    -1,    -1,
    1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1625,  1626,  1627,    -1,    -1,    -1,  1631,
      -1,    -1,    -1,    -1,  1506,    -1,    -1,    -1,  1510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1663,    -1,    -1,    -1,    -1,    -1,   246,    -1,  1541,
     249,    90,    91,    92,    93,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,  1567,   468,    -1,    -1,    -1,
      -1,    -1,    -1,   475,    -1,    -1,    -1,  2223,    -1,    -1,
      -1,    -1,    -1,  2229,  2230,  2231,  2232,  2233,  2234,    -1,
     246,    -1,    -1,   249,    -1,   497,    -1,  1729,  1730,    -1,
     502,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1435,  1436,  1437,
      -1,  1439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2275,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,  2294,  2295,
    2296,  2297,    -1,    -1,    -1,    -1,    -1,    -1,  1790,   368,
    1792,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,
      -1,    -1,    -1,    62,   383,    -1,    -1,    -1,   387,    -1,
      -1,    -1,  2328,  2329,  2330,    -1,  2332,  2333,  2334,  2335,
    2336,  2337,    -1,    -1,    -1,  2341,    -1,   246,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,  1839,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,  1546,  1731,
      -1,   387,  2378,    -1,  2380,    -1,  1868,    -1,    -1,  1858,
    1859,    -1,  1560,  2389,   453,  2391,    -1,    -1,    -1,  2395,
    1869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1914,  1915,    -1,    -1,    -1,  2433,    -1,    -1,
      -1,  1793,  1794,  1795,  1796,    -1,    -1,   453,   187,    -1,
      -1,    -1,    -1,  1922,  1923,  1924,  1925,    -1,    -1,    -1,
      -1,  1930,  1931,  1932,  1933,  1817,   472,    -1,  1937,   368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,   387,    -1,
      -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,  2494,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    2516,    -1,  1874,    -1,    -1,    -1,   425,    -1,  2524,    -1,
      -1,  2527,  2528,  2529,  2530,    -1,    -1,  2019,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,  2021,  2022,   453,    -1,    -1,    -1,    -1,  2028,
    2029,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,  2573,  2574,    -1,
      -1,  2577,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,
    1778,    -1,    -1,  1781,    -1,   621,  2098,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1999,    -1,  2001,
      -1,    -1,    -1,   392,    -1,   554,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2149,   407,  2665,
      -1,    -1,  2668,    -1,  2670,    -1,    -1,  2673,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2166,  2167,    -1,
    2182,   440,    -1,    -1,    -1,    -1,  2175,    -1,    -1,  2191,
      -1,  2193,    -1,  2195,  2183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,    -1,  2208,    -1,    -1,    -1,
      -1,  2213,    -1,  2202,  2203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   481,    -1,   246,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,   493,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,  2774,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2269,  2270,  2258,
      -1,  2260,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,
    2796,    -1,    -1,  2155,    -1,    -1,  2158,    -1,    -1,    -1,
      -1,    -1,    -1,  2809,    -1,    -1,    -1,    -1,    -1,  2815,
    2816,    -1,  2818,  2819,  2820,  2821,    -1,    -1,    -1,    -1,
    2312,  2827,    -1,  2829,    -1,   574,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    94,    95,    -1,   586,    -1,  2318,
    2319,    -1,    -1,  2322,  2323,    -1,   106,   107,   108,   598,
     599,    -1,  2214,    -1,  2860,    -1,   368,    -1,   607,    -1,
    2352,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   618,
      -1,   383,    -1,  2365,    -1,   387,   388,  2356,    -1,  2885,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,  2915,
      -1,    -1,    -1,   425,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,  2426,    -1,  2942,    -1,    -1,    -1,
    2946,   453,    -1,  2949,  2950,  2951,  2952,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
     472,    -1,    -1,    -1,  2456,    -1,    -1,  2145,  2146,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,  2984,  2471,
      -1,    -1,  2988,    -1,    -1,    -1,   246,    -1,    -1,   249,
      -1,  2470,  2998,    -1,    -1,  2474,    -1,    -1,    -1,    -1,
     131,    -1,  2494,    -1,    -1,    -1,    -1,    -1,    -1,  2187,
      -1,    -1,  2190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2198,  2199,    -1,    -1,    -1,    -1,  2505,    -1,    -1,    -1,
     161,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3056,    -1,    -1,    -1,    -1,    -1,    -1,   188,  3064,    -1,
    2539,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,
      -1,    -1,    -1,  3079,    -1,    -1,   207,   200,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,   235,   236,   237,   238,   368,   621,
      -1,  3117,    -1,    -1,    -1,    -1,    -1,    -1,  2480,   250,
      -1,    -1,    -1,   383,    -1,    -1,    -1,   387,   388,    -1,
      -1,    -1,    -1,   256,    -1,    -1,   267,    -1,    -1,   270,
      -1,   272,    -1,    -1,    -1,  3151,    -1,  2509,   279,    -1,
    2642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,
      -1,   292,    -1,    -1,    -1,   425,    -1,   290,    -1,    -1,
      -1,   302,    -1,    -1,    -1,    -1,  2538,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
     321,   322,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   326,    -1,   336,   329,    -1,    -1,    -1,
      -1,   334,   472,   344,    -1,    -1,    -1,   348,    -1,   342,
      -1,    -1,    -1,    -1,    -1,    -1,   357,   358,   359,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,  2734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,  2447,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,  2765,    -1,    -1,    -1,
     413,    -1,    -1,    -1,   554,   426,    -1,    -1,  2790,    -1,
      -1,    -1,    -1,    -1,    -1,   428,   437,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2498,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,   452,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,  2831,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,
      -1,    -1,    -1,  2845,   477,    -1,    -1,    -1,  2850,    -1,
    2852,   621,    -1,    -1,   487,   488,    -1,    -1,    -1,    -1,
     493,    -1,    -1,   296,  2736,    -1,    -1,    -1,    -1,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   315,    -1,    -1,    -1,    -1,    -1,    -1,  2891,
      -1,    -1,   525,    -1,    -1,   528,   529,  2899,    -1,   540,
      -1,   534,    -1,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,  2915,    -1,    -1,    -1,    -1,    -1,  2921,
      -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2919,    -1,    -1,   366,    -1,   576,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,   249,    -1,   591,    -1,
      -1,   394,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,
     603,   404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   623,  2972,  2973,    -1,  2975,   420,  2977,  2978,
      -1,    -1,    -1,    -1,    -1,    -1,   637,   638,   639,   640,
     641,   642,   643,    -1,   645,   646,    -1,    -1,    -1,    -1,
      -1,  3013,  3014,  3015,  3016,  3017,  3018,    -1,    -1,    -1,
      -1,   662,    -1,    -1,    -1,   368,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,    -1,  3044,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   499,    -1,    -1,    -1,
      -1,    -1,    -1,   506,    -1,   368,   509,    -1,    -1,  3068,
      -1,  3070,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,    -1,    29,    -1,   387,   438,    -1,   530,    -1,    -1,
     533,    -1,   535,    -1,    -1,    -1,    43,    44,    45,    -1,
     453,    -1,    -1,    -1,    -1,    52,  3105,    -1,    -1,    -1,
      -1,   554,    -1,    -1,    -1,    -1,    -1,    64,    65,   472,
      67,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,   572,
      -1,    -1,  3131,  3132,    81,    -1,  3135,    -1,    -1,  3151,
      -1,    88,  3024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,    -1,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   472,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    -1,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,   139,    -1,   141,   142,   143,    -1,   145,   146,
      -1,   554,    -1,    -1,   151,    -1,   153,   154,    -1,   156,
      -1,   158,   159,    -1,    -1,   162,   163,    -1,    -1,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,   175,   176,
      -1,   178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,    -1,    -1,
     197,   554,   199,    -1,   201,  3137,   203,    -1,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,   621,   216,
     217,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,    -1,   243,   244,    -1,    -1,
     247,   248,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   261,   262,    -1,   264,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,
      -1,   278,    -1,    -1,  3032,   282,   283,    -1,    -1,    -1,
     287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   303,   304,   305,    -1,
      -1,    -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,
     317,    -1,    -1,   320,    -1,    -1,    -1,   324,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,
     367,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
     397,    -1,   399,   400,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,   106,
     107,   108,    71,    72,    -1,    -1,    75,    76,    77,    -1,
     447,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,   458,    -1,    -1,    -1,   462,    -1,    -1,    -1,   466,
      -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,   491,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    94,    95,
     507,    -1,    -1,    -1,    -1,    -1,   513,   514,   515,   516,
     106,   107,   108,   520,    -1,    -1,    -1,   524,    -1,    -1,
      -1,    -1,    -1,    -1,   531,   532,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,   543,    -1,   545,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   556,
      -1,   558,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,   249,    -1,    -1,    -1,   215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   593,    -1,    -1,   596,
      -1,    -1,    -1,    -1,    -1,   602,    -1,    -1,   605,   606,
      -1,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   620,   253,   254,    -1,    -1,    -1,    -1,
     627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   650,   651,   652,   653,   654,   655,   656,
     246,    -1,   659,   249,   661,    -1,   663,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   340,    -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,
     387,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,
      -1,    -1,   387,   388,    -1,    -1,    -1,    -1,   425,    90,
      91,    92,    93,    94,    95,    -1,    -1,   396,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,   453,    -1,    -1,    -1,
     425,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,
      -1,   387,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,   472,    -1,   425,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,   554,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    90,    91,    92,    93,    94,    95,
      -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,   249,   554,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,   621,    -1,   368,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   383,    -1,    -1,    -1,   387,   388,    -1,    -1,
     246,    -1,    -1,   249,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,   246,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,   425,    -1,    -1,    90,    91,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,
      -1,   387,   388,    -1,    -1,    -1,   368,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,    -1,   554,    -1,   387,   388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   425,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     368,    -1,    -1,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,   425,    -1,   383,    -1,   453,    -1,   387,
     388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,
     621,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,    -1,   425,   249,    -1,
     472,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,   472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,    -1,   554,    -1,   387,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,   368,    -1,    -1,
      -1,    -1,   425,    -1,    -1,   621,   554,   106,   107,   108,
      -1,    -1,   383,    -1,    -1,   438,   387,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
     453,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,   472,
      -1,    -1,    -1,    -1,   425,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   438,    -1,    -1,
      -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   453,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,   472,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    95,    -1,    -1,
      -1,   246,    -1,    -1,   249,    -1,    -1,    -1,   106,   107,
     108,   554,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
     249,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    -1,    -1,    90,    91,    92,    93,
      94,    95,    -1,   554,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,    -1,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    17,    18,
     621,    20,    -1,    -1,    23,    24,    25,    26,   383,    -1,
      -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,   246,   368,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,   387,    -1,
      -1,   246,    -1,    62,   249,    -1,    -1,    -1,    -1,    -1,
     425,    90,    91,    92,    93,    94,    95,    -1,    17,    18,
      19,    20,    21,   438,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,   246,    -1,   425,   249,   453,    -1,
      -1,    -1,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,
      -1,    -1,    -1,    -1,   453,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    94,    95,    -1,    -1,    -1,
     368,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,   387,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,   554,
      -1,    -1,   387,    90,    91,    92,    93,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   368,   425,    -1,   106,
     107,   108,    -1,    -1,   368,   554,    -1,   246,    -1,    -1,
     249,   383,    -1,    -1,    -1,   387,    -1,    -1,    -1,   383,
     425,    -1,    -1,   387,    -1,   453,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   472,    -1,   621,    -1,   453,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    17,    18,    -1,    20,
      -1,   425,    23,    24,    25,    26,    57,   472,    -1,    -1,
      -1,    62,   621,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,   453,    -1,    -1,    -1,    -1,    -1,   246,    -1,   453,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     472,    62,    -1,    -1,    -1,    -1,    97,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,   368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,   249,    -1,   383,    -1,    -1,    -1,   387,   554,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   554,    -1,    -1,    -1,   425,    -1,   407,    -1,
     554,    -1,    -1,   621,    -1,    57,   187,    -1,   189,    -1,
      62,    -1,    -1,    -1,    -1,   424,    -1,    69,   427,   368,
      -1,    -1,    -1,    -1,   453,    -1,   621,    -1,    -1,    -1,
      -1,   440,    -1,    -1,   383,    -1,   187,    -1,   387,    -1,
      -1,    -1,    -1,   472,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,
      -1,   368,   481,    -1,    -1,    -1,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   493,    -1,   383,    -1,    -1,    -1,
     387,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,   453,   286,    -1,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   472,    -1,   554,   535,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    57,   187,    -1,   189,   319,    62,
     291,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,    97,   472,    -1,   586,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,   598,
     599,    -1,   621,    -1,    -1,    -1,    -1,    -1,   607,    -1,
      -1,   610,    -1,   384,    -1,   554,    -1,    -1,   389,   618,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   403,    17,    18,    -1,    -1,    -1,   409,    23,
      24,    25,    26,    -1,   286,    -1,    -1,    -1,   419,   291,
      -1,   392,    -1,   424,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   554,   439,   440,
      -1,    -1,    -1,    57,   187,    -1,   189,   319,    62,    -1,
      -1,    -1,   621,   424,    -1,    69,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,   440,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
     481,    -1,   354,    97,   485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   493,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   504,   621,    -1,    -1,    -1,    -1,   510,
     481,    -1,   384,    -1,    -1,    -1,    -1,   389,    17,    18,
     392,    20,   493,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,   403,    17,    18,   535,    20,    -1,   409,    23,    24,
      25,    26,    -1,   286,    -1,    -1,    -1,   419,   291,    -1,
      -1,    -1,   424,    -1,    -1,   427,    -1,    -1,   430,    -1,
      -1,    -1,    -1,    62,   535,    -1,    -1,   439,   440,    -1,
      -1,    -1,    -1,   187,    -1,   189,   319,    62,   579,    -1,
      -1,    -1,    -1,    -1,    21,   586,    -1,   588,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,   599,   600,
      -1,    -1,    -1,   574,    -1,    -1,   607,    -1,    -1,   481,
      -1,   354,    -1,   485,    -1,   586,    -1,   618,    -1,    -1,
      -1,   493,    -1,   366,    -1,    -1,    -1,   598,   599,   600,
      -1,    -1,   504,    -1,   506,    -1,   607,    -1,   510,   610,
      -1,   384,    -1,    -1,    -1,    -1,   389,   618,    -1,   392,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    -1,
     403,    -1,    -1,   535,    -1,    -1,   409,    -1,    -1,   106,
     107,   108,   286,    -1,    -1,    -1,   419,   291,    -1,    -1,
      -1,   424,    -1,    -1,   427,    -1,    -1,   430,   187,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   439,   440,    -1,    -1,
      -1,    -1,   187,    -1,    -1,   319,    -1,   579,    -1,    -1,
      -1,    -1,    -1,    -1,   586,    -1,   588,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,   598,   599,   600,    -1,
      -1,    -1,    -1,    -1,    -1,   607,    -1,   480,   481,    -1,
     354,    -1,   485,    -1,    -1,    -1,   618,    -1,    17,    18,
     493,    20,   366,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,
     384,    -1,    -1,    -1,    -1,   389,    96,    -1,   392,    17,
      18,    -1,    20,    -1,    -1,    23,    24,    25,    26,   403,
      -1,    -1,   535,    62,    -1,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   419,   291,    -1,    -1,   246,
     424,    -1,   249,   427,    -1,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,   439,   440,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,    -1,
      17,    18,    -1,   586,    -1,   588,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,   598,   599,   600,    -1,    -1,
      -1,    -1,    -1,    -1,   607,    -1,    -1,   481,    -1,    -1,
      -1,   485,    -1,    -1,    -1,   618,    -1,    -1,    -1,   493,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
     504,    -1,    -1,   392,    -1,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,   407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,
      -1,   535,   407,    -1,    -1,   424,    -1,    -1,   427,    -1,
      -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,
      -1,   440,   427,    -1,    -1,    -1,   383,    -1,    -1,   187,
     387,    -1,    -1,    -1,   439,   440,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,   579,    23,    24,    25,    26,
      -1,    -1,   586,    -1,   588,    -1,    -1,    -1,    -1,    -1,
      -1,   480,   481,    -1,   598,   599,   600,    -1,   425,    -1,
      -1,    -1,    -1,   607,   493,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   618,    62,    17,    18,   493,   329,
     187,    31,    23,    24,    25,    26,   453,    -1,    -1,    -1,
      -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   472,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,    62,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   406,   586,    -1,   574,
      -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,   598,
     599,   586,    -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,
      -1,   610,    -1,   598,   599,    -1,    -1,   554,    -1,   618,
      -1,    -1,   607,   392,    -1,   610,    -1,    -1,    -1,    -1,
     187,    -1,   452,   618,    -1,    -1,    -1,    -1,   407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   392,   424,    -1,   477,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,   488,   407,
      -1,   440,    -1,   493,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   503,   621,    -1,   424,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,
      -1,    -1,   440,    -1,    -1,   525,    -1,    -1,   528,   529,
      -1,    -1,   481,    -1,   534,   392,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,
     407,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   480,   481,    -1,    -1,    -1,   424,    -1,    -1,
     427,    -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,   535,    -1,    -1,    -1,
      -1,   591,    -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,
      -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   315,    -1,   535,    -1,    -1,
      -1,    -1,    -1,   480,   481,   574,    -1,    -1,    -1,    -1,
      -1,   331,    -1,    -1,    -1,    -1,   493,   586,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,
     599,    -1,    -1,    -1,   354,   392,   574,    -1,   607,    -1,
      -1,   610,    -1,    -1,    -1,    -1,   366,    -1,   586,   618,
     407,    -1,    -1,    -1,    -1,    -1,   376,    -1,   535,    -1,
     598,   599,    -1,    -1,    -1,    -1,    -1,   424,    -1,   607,
     427,    -1,   610,    -1,   394,    -1,    -1,    -1,    -1,    -1,
     618,   392,    -1,   440,   404,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   574,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,
      -1,   468,    -1,   424,    -1,    -1,   427,    -1,    -1,    -1,
      -1,   598,   599,    -1,   481,    -1,    -1,    -1,    -1,   440,
     607,    -1,    -1,   610,    -1,    -1,   493,    -1,    -1,    -1,
     460,   618,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   484,    -1,    -1,    -1,    -1,    -1,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   499,
      -1,    -1,   493,    -1,    -1,    -1,   506,    -1,    -1,   509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     530,    -1,    -1,   533,    -1,   535,    -1,   574,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,   586,
      -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,
      -1,   598,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     607,    -1,   572,   610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   618,    -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,   599,    -1,
      -1,    -1,    -1,    -1,    -1,   615,   607,    -1,    -1,   610,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   618
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    44,    45,    73,   120,   121,   123,   124,   128,
     145,   146,   163,   233,   353,   402,   434,   724,   752,   753,
     803,   969,  1024,  1026,  1027,  1028,  1033,  1035,  1048,  1049,
    1050,  1051,  1052,  1467,    27,    28,   725,   726,   727,   728,
     729,    26,   935,  1486,   352,   531,   545,   570,   619,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,   935,    24,   935,
    1388,  1053,   754,   753,  1467,     0,  1025,  1028,  1033,  1051,
    1467,    30,   727,   729,   935,  1470,   587,   935,  1469,   624,
     804,    24,   187,   751,   752,   923,   935,   940,  1054,  1090,
    1091,  1092,  1093,  1094,  1098,   350,   756,   757,   758,   759,
     762,   763,    53,    58,   103,   104,   111,   364,   390,   461,
     555,   636,   644,   724,   730,   895,   968,  1029,  1030,  1032,
    1036,  1037,  1043,  1055,  1076,  1209,  1219,  1467,   935,  1469,
     615,  1093,   239,   454,   455,  1100,    20,   935,  1097,   618,
     757,     5,   755,   350,   935,     5,   779,   781,   782,   935,
    1220,   935,   935,  1210,  1044,   935,   935,  1032,  1038,   257,
     296,   315,   354,   366,   376,   394,   404,   420,   460,   484,
     499,   506,   509,   530,   533,   535,   554,   572,   805,   806,
     807,   810,    24,  1090,  1096,    17,    18,    25,   427,   674,
     676,  1090,  1101,  1102,   455,    13,   802,   759,   519,  1196,
     760,   757,   762,    31,    78,    79,    87,   257,   296,   315,
     331,   354,   366,   376,   394,   404,   420,   460,   484,   499,
     506,   509,   530,   533,   535,   554,   572,   615,   765,   773,
     784,   785,   935,   427,   110,   935,   751,   896,  1077,   935,
     812,   533,   764,   788,   790,   791,   789,   798,   799,   427,
     427,   811,   455,   427,   427,   757,   786,   422,   674,    17,
      18,    19,    20,    21,   675,    25,     5,   423,  1101,    23,
      24,    25,   618,   935,   941,    18,    24,    25,   761,   941,
     775,   764,   776,   788,   789,   427,   427,   774,   455,   427,
     427,   786,   757,   783,   427,    25,   935,   427,  1045,   751,
     751,   427,   935,   427,   454,   768,   624,   363,   450,   467,
     510,   550,   579,   588,   792,   624,   363,   450,   467,   510,
     550,   579,   588,   800,    25,    25,   813,   814,   815,   816,
     935,    25,   771,   772,    25,    25,   618,   388,   674,  1102,
     455,   423,    25,    25,   757,   768,   757,    25,    25,   756,
     771,    25,    25,   618,    56,   780,  1221,   388,   427,  1211,
    1487,  1488,  1489,  1490,  1491,   897,  1078,  1039,   618,    25,
     793,   794,   427,   795,   800,   801,   795,   427,   796,     5,
     388,     5,   388,     5,   280,     5,   805,   423,     5,     5,
     388,   388,   757,   787,  1101,   455,   618,    25,   255,     5,
     388,     5,   388,   280,   423,     5,   388,   388,   787,   935,
    1107,  1108,  1110,  1056,  1107,   358,  1488,  1196,    43,    52,
      64,    65,    67,    81,    88,    99,   100,   101,   115,   117,
     118,   119,   122,   125,   127,   129,   130,   136,   139,   141,
     142,   143,   151,   153,   154,   156,   158,   159,   162,   166,
     167,   168,   170,   171,   175,   176,   178,   182,   184,   185,
     190,   194,   197,   199,   201,   203,   205,   206,   208,   209,
     210,   214,   216,   217,   219,   227,   228,   240,   243,   244,
     247,   248,   251,   252,   260,   261,   262,   264,   274,   275,
     276,   278,   282,   283,   287,   295,   303,   304,   305,   311,
     312,   317,   320,   324,   325,   335,   353,   361,   367,   397,
     399,   400,   408,   447,   458,   462,   466,   490,   491,   495,
     507,   513,   514,   515,   516,   520,   524,   531,   532,   543,
     545,   556,   558,   561,   567,   593,   596,   602,   605,   606,
     620,   627,   650,   651,   652,   653,   654,   655,   656,   659,
     661,   663,   667,   668,   669,   670,   687,   709,   723,   724,
     730,   731,   750,   818,   819,   820,   821,   832,   833,   834,
     835,   887,   891,   921,   942,   943,   946,   947,   948,   949,
     962,   970,   991,   992,   994,   998,  1015,  1016,  1020,  1021,
    1022,  1023,  1031,  1046,  1059,  1070,  1071,  1072,  1083,  1086,
    1123,  1126,  1128,  1134,  1135,  1138,  1141,  1144,  1146,  1148,
    1150,  1157,  1162,  1166,  1167,  1168,  1180,  1181,  1184,  1190,
    1191,  1192,  1217,  1232,  1233,  1234,  1235,  1236,  1241,  1247,
    1248,  1266,  1269,  1298,  1300,  1389,  1390,  1421,  1422,  1429,
    1440,  1467,  1471,  1476,  1478,  1480,  1484,  1485,  1492,   724,
    1034,  1467,   623,   646,  1079,  1080,  1107,    20,   388,   422,
     769,   792,    25,   797,    25,    25,    25,   814,   816,   808,
     772,    25,   423,  1101,    20,   769,   427,    25,    25,   766,
      25,   618,   388,     5,  1107,   388,   935,   346,   936,   937,
    1486,   935,   935,  1164,   930,   936,   930,    24,   187,   935,
    1099,  1462,  1463,  1464,   935,  1482,   935,  1243,  1244,   935,
      25,   671,  1090,  1239,   930,  1164,   861,    25,   941,  1204,
    1205,  1204,    17,    18,    24,    25,    57,    62,    69,    97,
     189,   286,   291,   319,   354,   366,   384,   389,   392,   403,
     409,   419,   424,   427,   430,   439,   440,   481,   485,   493,
     504,   510,   535,   579,   586,   588,   598,   599,   600,   607,
     836,   843,   844,   845,   846,   847,   848,   849,   850,   862,
     867,   878,   879,   880,   881,   935,   941,  1090,  1199,  1268,
    1380,   936,  1430,  1430,   822,  1164,   930,  1237,  1090,   932,
     936,   843,  1430,  1090,  1164,  1090,  1267,  1430,    24,   583,
    1073,  1074,  1090,   930,   930,  1073,   931,   936,   935,  1074,
     930,  1430,   930,   932,  1090,  1121,  1122,   928,   936,   932,
     371,   559,   665,   927,   935,   993,   935,   732,   933,   936,
      24,  1299,  1462,  1087,   861,   936,  1147,   892,   126,   135,
     144,   149,   192,   200,   256,   281,   288,   290,   300,   326,
     334,   371,   397,   435,   446,   546,   547,   548,   559,   663,
    1007,  1142,  1143,  1090,   842,   843,  1156,   838,   861,   927,
    1477,  1477,   929,   936,   861,    24,  1090,  1145,  1218,  1090,
    1195,    24,  1090,  1424,   843,  1186,  1187,  1188,  1197,  1198,
     843,  1472,   102,   152,   189,   286,   362,   403,   471,   535,
     688,   867,   935,  1090,  1227,   711,   843,   928,  1469,  1060,
     843,   928,   843,  1090,  1017,   928,   843,  1441,   843,  1204,
     935,   944,   945,   932,   944,  1477,   932,   944,  1477,   950,
     944,    24,    25,   381,   484,   941,   996,  1090,  1109,  1111,
      63,   271,   341,   386,   566,   647,   648,   649,   658,   678,
     952,   954,   956,   958,   960,  1084,  1085,  1089,   332,   343,
     395,   410,   500,  1301,   638,   639,   899,   900,   901,   935,
    1081,   645,  1080,   388,   299,   388,   388,   388,   388,   622,
       5,   388,   423,   299,   757,   777,   778,   388,   388,   622,
     388,   935,  1222,  1110,   388,  1212,    54,    55,    82,    83,
      84,   451,   539,   582,  1249,  1250,  1251,  1254,  1257,  1260,
    1261,  1262,  1263,   427,   618,  1464,  1100,   615,  1139,   618,
       8,   536,   585,     5,   388,   423,    24,   935,  1373,   476,
    1165,  1109,   106,   107,   108,   836,   836,   427,   523,  1216,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   836,
     363,   450,   467,   510,   550,   579,   588,  1383,  1384,   427,
     427,   427,   836,   836,   427,   427,   748,   836,   427,   851,
     427,   427,   427,   427,   427,   427,   427,   836,   427,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    90,    91,    92,    93,    94,
      95,   106,   107,   108,   246,   249,   368,   383,   387,   425,
     453,   472,   554,   621,   747,   837,   852,   854,   855,   856,
     857,   858,   859,   860,    25,   941,   427,   518,   417,  1090,
    1116,  1373,   677,   678,   825,   263,    85,    86,   624,   456,
       5,   617,   624,   616,   616,  1124,   593,   417,     5,   554,
     971,   456,   657,  1474,   427,   455,   618,   657,   381,   734,
    1090,   544,   616,  1129,  1130,  1131,   323,  1297,   842,   841,
     843,     8,   929,    25,   498,   552,   922,  1090,   922,   922,
     922,  1012,  1013,   922,   922,   594,  1008,   678,  1008,  1008,
     923,   923,  1008,  1008,   678,     5,   330,   382,     5,   677,
     480,   839,   840,   843,     5,    74,    80,   537,   625,   999,
     660,  1475,   842,   611,   612,   613,   614,  1194,  1196,   380,
    1231,  1196,  1188,     5,   616,  1189,   843,   427,   427,   427,
     427,    24,   707,   935,   427,  1424,   341,   427,   518,   587,
     576,   712,   719,   710,    24,  1075,  1090,  1182,     8,  1185,
      13,   935,  1095,  1103,  1104,  1106,  1114,  1115,  1158,   160,
     341,   542,   575,    32,   187,   551,  1442,  1443,  1444,  1445,
     573,     5,   657,   657,   841,  1109,  1116,   995,   417,     5,
     148,   975,   427,  1090,   841,   427,    25,    25,    63,  1088,
      24,  1090,  1428,  1428,   929,  1147,   929,   116,   218,   226,
     232,   234,   245,   273,   289,   294,   306,   313,   468,   475,
     497,   502,  1270,  1271,  1279,  1288,  1289,  1295,  1296,  1302,
    1303,  1312,  1331,  1335,  1400,  1401,  1431,  1432,  1435,  1436,
    1446,   902,   903,    89,   898,   909,   910,   901,  1082,  1487,
    1040,   455,   805,   772,   455,     5,   388,   779,   751,  1057,
     751,   155,   293,   369,   427,   473,   489,  1318,  1330,   427,
     935,  1265,    25,   242,   255,   427,   473,   489,   935,  1246,
    1259,  1316,  1317,  1322,  1324,  1326,   427,   935,  1256,   427,
    1246,  1252,     5,    24,   938,  1093,  1464,  1462,   574,   615,
    1140,    20,   935,  1120,  1465,   935,  1483,  1244,   593,   618,
     587,   427,   427,   825,   886,   927,   836,   927,   927,   886,
    1477,   468,  1404,   836,    24,    25,    18,    23,    24,    25,
     882,   883,   884,   885,   836,   427,   624,   927,    20,   836,
     388,  1404,   836,    20,  1199,   870,   868,   874,   836,   872,
     836,   836,   836,   836,   836,   836,   836,   836,   836,   836,
     836,   836,   836,   836,   836,   836,   836,   836,   836,   836,
     836,   427,   836,   836,   427,   863,   935,  1090,   624,   427,
    1462,    24,   940,  1163,  1163,  1424,  1073,   843,   843,   843,
     924,   925,   427,  1090,  1122,   786,   972,   973,   624,  1424,
    1477,  1475,   935,   674,    20,   665,   935,   993,  1090,   733,
     623,   843,   347,  1133,   554,  1132,     5,    66,    68,    70,
     616,   624,   817,  1109,   893,    17,    18,    24,   301,   307,
     308,   309,   327,   435,   438,   462,   482,   517,   537,   538,
     548,   553,   592,   625,  1014,  1009,  1143,   923,   843,   341,
     593,     5,   927,    25,    25,   677,   150,  1193,   215,  1198,
    1204,  1473,   935,    24,   886,  1477,   587,   927,   621,  1090,
     692,   935,   935,   843,   336,   715,   719,   576,   713,   721,
      22,   231,  1062,  1066,   479,   861,   479,  1183,   843,   454,
    1100,   618,     5,  1018,   544,  1159,  1090,  1463,  1466,  1090,
    1112,  1113,   186,  1443,   963,   945,  1477,  1477,   955,   956,
     975,   975,    33,    34,    35,    36,   267,   270,   272,   292,
     302,   344,   348,   426,   974,   976,   977,  1003,  1090,  1111,
     544,   679,    25,   396,   961,   318,  1423,  1423,   133,   134,
     433,   544,   935,  1332,  1333,  1374,   786,  1373,  1373,  1272,
     786,   935,  1433,  1433,   356,   473,   583,  1412,  1373,  1280,
     165,   435,   446,   468,   475,  1305,  1306,  1307,   284,   285,
    1395,  1487,  1487,   381,   911,  1090,   640,   641,   904,   905,
     906,   478,   623,   642,   643,   662,   914,   915,  1487,   751,
      25,   770,   770,   778,  1223,   751,  1213,  1320,  1373,  1264,
    1330,   427,  1264,   427,   427,  1258,  1259,   427,   427,    61,
     296,   354,   366,   376,   394,   404,   407,   420,   469,   499,
     509,   530,   533,   535,   563,   572,  1365,  1366,  1367,  1369,
    1255,  1256,  1252,  1253,   662,  1250,   388,   618,  1424,   574,
     455,   544,  1481,   672,   673,   935,   935,   935,  1240,   861,
       5,   388,   388,   388,   388,   388,  1412,   388,   388,   388,
     388,   587,   883,    18,    25,   587,   388,   388,    25,  1384,
     388,   388,   388,   388,     5,   749,   388,   836,   836,   836,
     388,   836,   388,   388,   388,   438,   438,   438,   861,  1404,
     438,   861,  1404,   704,   705,   706,   836,   427,   935,  1238,
     615,  1136,   624,     5,     5,     5,   577,   843,   618,     5,
     480,   624,   388,   423,   427,   623,   161,   164,   267,   270,
     735,   738,   739,  1003,   736,   737,   935,   427,   936,   647,
     648,  1137,   843,   935,   935,   925,   926,   506,  1477,   825,
     551,  1285,    25,    25,   427,  1010,  1012,  1090,   533,  1151,
     839,    63,   836,  1196,    25,  1090,  1487,     5,     5,   388,
     388,   708,   935,   388,  1424,   704,   427,   427,   720,   716,
     357,   714,   843,   336,   717,   721,   594,  1005,  1067,  1063,
     359,  1061,  1062,   841,   624,  1096,    20,   935,  1105,  1115,
      13,    17,    18,    20,    24,    25,    62,   392,   407,   424,
     427,   440,   480,   481,   493,   535,   574,   586,   598,   599,
     607,   610,   935,   941,  1160,  1161,  1379,  1381,  1411,  1416,
    1417,  1418,  1466,   417,   417,     5,  1487,   957,   958,   548,
     934,   544,   986,   985,   988,   987,   927,   989,   927,   990,
     984,   983,   981,   980,  1004,   321,   977,   982,  1477,    37,
      38,    39,    40,    41,    42,    96,   329,   342,   406,   413,
     452,   477,   487,   488,   493,   503,   525,   528,   529,   534,
     591,   603,   680,   681,  1001,  1002,     5,    25,  1424,   245,
    1090,   468,  1405,  1406,  1424,  1147,  1399,  1401,    98,    98,
     593,  1145,  1334,  1335,   427,  1313,   147,   523,  1339,  1346,
    1373,   172,   268,  1437,   618,   624,  1402,  1447,   338,   347,
     371,   374,   392,   498,   552,   559,   929,  1282,  1287,   427,
    1308,   623,     5,    24,   935,  1396,  1397,   913,  1090,     5,
     544,   907,   908,   637,   906,   912,   935,   912,   916,   917,
     912,   321,   915,  1041,   423,   423,   457,  1206,  1226,  1058,
     457,  1169,  1200,   427,     5,   388,   291,   427,   439,   600,
    1349,  1350,  1351,  1352,  1353,  1357,  1361,  1363,  1416,   388,
     610,   935,  1319,  1321,  1373,  1376,  1377,  1323,  1376,     5,
     388,  1323,  1349,   363,   450,   467,   510,   550,   579,   588,
    1386,  1386,   427,   427,   427,   427,   427,   427,   204,   396,
    1325,  1327,     5,   388,     5,   388,   935,  1465,     8,  1424,
    1101,   843,     5,  1245,  1246,   861,  1047,   927,  1413,  1414,
    1416,   876,  1384,   876,    25,    25,   587,    23,    25,   789,
     877,  1216,   388,  1216,   790,   388,  1216,   871,   869,   875,
    1216,   873,  1216,  1216,  1216,    24,    24,    24,   836,   853,
     388,    24,   853,   388,   864,     5,   865,   618,  1245,   574,
    1424,  1424,   843,   843,   924,   506,   843,  1479,     5,    20,
    1376,   973,  1424,   618,   935,   736,   744,   743,   745,   935,
     939,   746,   939,   188,   739,   742,     5,   975,   618,   843,
       8,   935,  1286,   894,  1011,  1012,  1090,     5,   322,    24,
    1228,   341,   341,   455,   618,   341,   427,   693,   697,   690,
    1487,  1487,   722,   718,   714,  1006,    24,   934,  1068,  1090,
    1487,   843,   422,   455,   861,  1417,  1417,  1382,  1386,   468,
    1416,   427,   427,   427,   427,   427,   427,   427,   935,   427,
       5,    17,    18,    19,    20,    90,    91,    92,    93,    94,
      95,  1438,  1463,  1090,  1113,    60,   540,   964,   959,   960,
      25,   677,   935,  1487,  1487,  1487,  1487,     5,   978,     5,
     979,  1487,  1487,  1487,  1487,  1010,  1487,   934,    24,    13,
      13,     5,   388,    25,  1373,  1412,  1393,   593,   593,  1271,
    1398,  1399,  1335,  1314,  1376,   615,   929,  1349,   427,  1275,
     935,  1434,  1433,  1413,    46,    47,    48,    49,    50,   581,
    1450,   843,   843,  1281,   929,  1309,  1376,  1373,  1307,   618,
     618,     5,     5,  1090,   912,  1487,  1487,     5,   919,   920,
    1487,  1487,   918,  1034,   809,   767,    71,    72,    75,    76,
      77,   174,   181,   215,   224,   253,   254,   298,   340,   396,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
    1203,  1207,   132,   511,  1208,  1224,  1034,   157,   173,   174,
     181,   215,   224,   253,   298,   340,  1201,  1202,  1214,  1208,
    1321,  1330,   427,  1411,  1349,  1416,  1411,  1352,     6,   388,
       7,     9,    11,    12,    13,    14,    15,    16,   249,   368,
     425,   554,   600,   621,  1360,  1362,  1377,   455,  1375,   388,
       5,   618,     5,   388,  1259,   388,   388,   624,   427,   624,
      25,  1371,  1371,    25,  1371,  1371,    25,  1370,    24,  1379,
    1328,  1329,  1330,  1256,  1252,  1424,     8,   423,   673,     5,
     388,   841,   388,     5,   544,  1340,  1345,   935,   624,   388,
      25,   587,   624,   388,   388,   388,   388,     5,   388,   388,
     388,   706,   704,    20,   388,  1424,     5,   843,   564,   271,
     682,   683,   843,    20,   935,   388,   975,  1487,  1487,     5,
     740,   455,   618,     5,   741,  1487,   737,   544,    20,   935,
       5,   935,  1127,   386,   657,  1112,  1487,     5,   388,   934,
     836,     5,   704,  1090,   689,   671,   935,  1090,   695,   388,
     704,   704,  1487,  1487,  1010,  1065,    24,  1069,  1090,   569,
     890,  1101,   480,   842,  1019,   624,  1412,   388,   392,  1376,
    1439,   356,   473,   583,  1364,  1416,  1419,  1364,  1364,  1364,
    1364,   618,  1419,  1161,  1416,  1416,  1416,  1416,   966,   965,
     437,   951,   952,   618,   927,  1487,   927,  1487,   677,    25,
    1090,    25,  1090,   681,   388,   427,  1425,  1413,  1395,  1399,
    1399,  1391,     5,   388,   468,  1410,  1276,  1376,   476,  1273,
    1410,   624,  1403,    17,    18,    62,   424,   427,   440,   480,
     481,   493,   535,   574,   586,   598,   599,   607,   610,   935,
    1379,  1411,  1455,  1456,  1457,  1458,  1459,  1460,  1466,  1455,
    1455,  1455,  1376,  1452,  1454,  1451,  1452,  1453,  1448,   551,
    1283,     5,   388,   624,   935,   935,  1397,  1090,   935,  1487,
    1487,  1487,  1487,   622,   622,  1204,  1204,  1204,    24,  1204,
    1204,  1204,  1204,  1204,  1204,    24,    24,  1204,  1207,  1090,
    1117,  1118,   617,   443,  1170,  1487,    24,    24,    25,    25,
      25,    25,    25,    24,  1090,  1202,  1170,   388,   388,  1350,
    1351,   935,  1355,  1379,  1420,   427,  1411,  1355,   427,  1411,
       9,   246,   383,   385,  1416,    25,  1318,  1376,    20,   935,
    1376,   363,   450,   467,   510,   550,   579,   588,  1387,    25,
    1387,     5,  1368,  1368,     5,   388,   388,  1368,   388,  1330,
    1424,  1246,   265,  1242,  1414,   512,  1341,  1342,  1343,  1373,
    1346,   328,   511,   522,  1290,  1407,   363,   450,   467,   510,
     550,   579,   588,  1385,   876,   587,    23,    25,   793,   836,
     866,   465,   824,     5,   370,  1424,     5,   427,   388,   548,
    1000,   939,  1487,   674,    20,   935,   939,  1487,  1477,   843,
    1477,   237,  1012,   677,    24,  1229,  1109,   423,   704,   694,
     698,   388,  1487,   934,   843,   888,   423,  1387,  1413,     5,
    1386,     5,   388,  1416,     5,   388,  1416,  1416,  1416,  1416,
     935,   388,   843,  1487,   953,   954,    20,   935,  1426,  1427,
     551,  1409,  1394,  1392,  1395,  1376,  1412,   137,  1315,     5,
     388,  1274,  1434,  1409,  1458,  1458,  1457,   427,   427,   427,
     427,   427,   427,   427,   935,   427,     5,   388,    17,    18,
      19,    20,  1438,   388,     5,   388,     5,    13,   147,   523,
    1449,  1284,  1376,   459,  1310,  1311,  1374,   618,   207,  1042,
     805,   779,   536,   585,  1119,     5,  1117,    59,   131,   196,
     198,   213,   221,   225,   250,  1171,  1172,  1225,  1042,  1215,
     438,  1354,  1358,  1359,  1379,  1466,  1354,  1358,  1355,  1416,
       5,   423,  1375,   388,    25,  1372,   388,   388,    25,   388,
     427,  1343,     5,   935,  1378,   365,  1337,  1347,   935,  1408,
     617,  1364,   328,   427,    23,    25,   388,   927,   677,   370,
    1424,   843,   684,   566,  1125,    25,   677,   423,  1000,   388,
    1149,   388,   388,   427,   696,   341,   702,   388,   691,  1064,
    1487,   455,  1345,  1386,   624,  1386,   388,  1416,   388,   388,
     388,   388,   573,   934,     5,   388,  1112,  1345,  1395,  1395,
    1413,  1376,   427,  1345,   388,  1439,  1364,  1457,  1461,  1364,
    1364,  1364,  1364,   618,  1461,  1456,  1457,  1457,  1457,  1457,
    1452,    13,  1453,  1456,   929,  1349,  1112,     5,   138,  1304,
     935,  1118,  1173,  1174,  1090,  1176,  1090,  1175,  1177,  1172,
     236,   236,  1356,  1420,     5,   388,   388,  1354,     7,    25,
     624,   388,  1342,  1344,  1342,  1338,  1415,  1416,   444,  1336,
    1348,  1242,    25,  1291,  1292,  1293,  1376,  1405,  1408,    25,
     823,  1424,   389,   200,   256,   281,   290,   326,   334,   428,
     601,   681,   685,   686,   427,   618,   677,  1003,  1152,  1153,
    1154,  1230,   699,   388,  1109,   702,   702,  1487,   889,  1101,
     388,   624,  1387,   624,   967,   997,  1427,  1407,  1345,   480,
    1277,  1278,  1416,  1407,   388,  1457,     5,   388,  1457,  1457,
    1457,  1457,   935,   388,   427,  1311,  1487,  1487,  1178,  1487,
    1179,  1487,  1487,  1359,  1416,   423,  1387,     5,   388,     5,
    1349,     5,   536,   585,  1294,  1242,   388,   344,   348,   826,
     827,   828,  1003,   922,   922,   922,   922,   922,   922,    24,
       5,   388,   843,    20,   935,  1155,   279,  1154,   702,   704,
     702,   238,   423,  1387,  1387,  1487,   677,     5,   388,   388,
    1457,   388,   388,   388,   388,  1455,  1487,  1487,  1342,  1415,
    1292,   830,   829,   235,   828,   831,   686,     5,  1487,   700,
     964,  1278,   388,  1487,  1487,  1487,   843,   388,   388,   701,
     160,   341,   703,  1109
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
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1542 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
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
	sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");A4GL_pop_args(_retvars);A4GL_push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
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
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
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

  case 626:
#line 3446 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 627:
#line 3460 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 629:
#line 3467 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 630:
#line 3470 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 631:
#line 3476 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 632:
#line 3482 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 633:
#line 3486 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 634:
#line 3490 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 635:
#line 3496 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 636:
#line 3500 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 637:
#line 3504 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 638:
#line 3509 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 639:
#line 3514 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 658:
#line 3555 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 659:
#line 3560 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 661:
#line 3565 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 663:
#line 3568 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 664:
#line 3570 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 665:
#line 3573 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 666:
#line 3577 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 667:
#line 3580 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 668:
#line 3586 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 669:
#line 3597 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 670:
#line 3598 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 671:
#line 3601 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 673:
#line 3607 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 674:
#line 3611 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 675:
#line 3612 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 678:
#line 3626 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 679:
#line 3628 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 682:
#line 3637 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 683:
#line 3639 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 684:
#line 3643 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 685:
#line 3645 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 686:
#line 3648 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 687:
#line 3650 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 688:
#line 3653 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 689:
#line 3656 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 690:
#line 3659 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 691:
#line 3661 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 692:
#line 3664 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 693:
#line 3666 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 694:
#line 3669 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 695:
#line 3671 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 696:
#line 3674 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 697:
#line 3676 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 698:
#line 3677 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 699:
#line 3679 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 700:
#line 3680 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 701:
#line 3682 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 702:
#line 3683 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 703:
#line 3685 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 704:
#line 3725 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 705:
#line 3726 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 706:
#line 3734 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 707:
#line 3735 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 708:
#line 3744 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 709:
#line 3749 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 710:
#line 3754 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 711:
#line 3755 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 713:
#line 3760 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 714:
#line 3763 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 715:
#line 3771 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 716:
#line 3776 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 717:
#line 3780 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 718:
#line 3782 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 719:
#line 3791 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 720:
#line 3796 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 721:
#line 3797 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 722:
#line 3798 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 723:
#line 3799 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 724:
#line 3802 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 736:
#line 3823 "fgl.yacc"
    {iskey=1;}
    break;

  case 737:
#line 3823 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 738:
#line 3825 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 739:
#line 3828 "fgl.yacc"
    {iskey=1;}
    break;

  case 740:
#line 3828 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 741:
#line 3830 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 742:
#line 3834 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 743:
#line 3834 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 744:
#line 3837 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 745:
#line 3838 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 747:
#line 3841 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 748:
#line 3846 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 749:
#line 3846 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 754:
#line 3853 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 755:
#line 3854 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 756:
#line 3855 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 757:
#line 3856 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 758:
#line 3857 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 759:
#line 3858 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 760:
#line 3859 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 761:
#line 3860 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 762:
#line 3861 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 763:
#line 3862 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 764:
#line 3863 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 765:
#line 3864 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 766:
#line 3865 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 767:
#line 3869 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 768:
#line 3887 "fgl.yacc"
    {chk4var=1;}
    break;

  case 769:
#line 3887 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 770:
#line 3890 "fgl.yacc"
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

  case 771:
#line 3913 "fgl.yacc"
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

  case 773:
#line 3931 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 774:
#line 3937 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3943 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 776:
#line 3949 "fgl.yacc"
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

  case 777:
#line 3960 "fgl.yacc"
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

  case 778:
#line 3983 "fgl.yacc"
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

  case 781:
#line 3999 "fgl.yacc"
    {
	}
    break;

  case 788:
#line 4022 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 792:
#line 4030 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 810:
#line 4056 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 811:
#line 4057 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 812:
#line 4065 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 813:
#line 4070 "fgl.yacc"
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

  case 814:
#line 4086 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 815:
#line 4092 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 817:
#line 4107 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 818:
#line 4120 "fgl.yacc"
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

  case 819:
#line 4130 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 820:
#line 4137 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 821:
#line 4144 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 822:
#line 4150 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 823:
#line 4150 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 824:
#line 4155 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 825:
#line 4160 "fgl.yacc"
    {
}
    break;

  case 831:
#line 4172 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 833:
#line 4180 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 834:
#line 4186 "fgl.yacc"
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

  case 835:
#line 4200 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 836:
#line 4204 "fgl.yacc"
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

  case 837:
#line 4217 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 839:
#line 4235 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	do_print_menu_1();
	}
    break;

  case 840:
#line 4242 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 841:
#line 4248 "fgl.yacc"
    {
   print_end_menu_1(get_blk_no());
   add_continue_blockcommand ("MENU");
print_end_menu_2(get_blk_no());
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 842:
#line 4259 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 843:
#line 4263 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 844:
#line 4270 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 845:
#line 4277 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 846:
#line 4283 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 847:
#line 4288 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 850:
#line 4295 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 851:
#line 4296 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 852:
#line 4298 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 853:
#line 4299 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 854:
#line 4302 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 855:
#line 4303 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 856:
#line 4304 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 857:
#line 4306 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,get_blk_no());
}
    break;

  case 858:
#line 4311 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,get_blk_no());
}
    break;

  case 859:
#line 4316 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,get_blk_no());
}
    break;

  case 860:
#line 4323 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 864:
#line 4330 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 865:
#line 4332 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 866:
#line 4334 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 867:
#line 4343 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 868:
#line 4349 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 869:
#line 4353 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 872:
#line 4365 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 873:
#line 4370 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 874:
#line 4375 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 875:
#line 4378 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 876:
#line 4387 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 877:
#line 4390 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 878:
#line 4394 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 879:
#line 4398 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 886:
#line 4415 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 888:
#line 4417 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 889:
#line 4417 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 890:
#line 4420 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4430 "fgl.yacc"
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

  case 893:
#line 4477 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 895:
#line 4484 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 896:
#line 4488 "fgl.yacc"
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
      	dec_counter();

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 897:
#line 4530 "fgl.yacc"
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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", buff2, (int)scan_variable (buff2), yyvsp[-4].str);
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

  case 901:
#line 4578 "fgl.yacc"
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

  case 902:
#line 4592 "fgl.yacc"
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

  case 907:
#line 4616 "fgl.yacc"
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
        sprintf (yyval.str, " a4gl_substr(%s , 0x%x , %s , 0 ) /*1.1*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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

  case 908:
#line 4676 "fgl.yacc"
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

  case 909:
#line 4732 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 910:
#line 4737 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4745 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 912:
#line 4750 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 913:
#line 4758 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 914:
#line 4764 "fgl.yacc"
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

  case 915:
#line 4792 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 916:
#line 4795 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 917:
#line 4797 "fgl.yacc"
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M4 */", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 918:
#line 4838 "fgl.yacc"
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%x,%s,0) /* M1 */", buff, a, yyvsp[-1].str);
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

  case 923:
#line 4891 "fgl.yacc"
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
        sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M2 */", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M3 */", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 924:
#line 4943 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 926:
#line 4950 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 927:
#line 4956 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 928:
#line 4967 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 929:
#line 4974 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 931:
#line 4982 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 932:
#line 4985 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 933:
#line 4986 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 935:
#line 4988 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 936:
#line 4989 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 4992 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 938:
#line 4995 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 939:
#line 5001 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 940:
#line 5004 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 941:
#line 5008 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 942:
#line 5012 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 5019 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 944:
#line 5024 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 945:
#line 5031 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 946:
#line 5034 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 951:
#line 5047 "fgl.yacc"
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

  case 952:
#line 5066 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 953:
#line 5073 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5080 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 955:
#line 5083 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 956:
#line 5097 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 961:
#line 5114 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 962:
#line 5119 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 963:
#line 5125 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 965:
#line 5132 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 966:
#line 5137 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 967:
#line 5140 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 968:
#line 5141 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 969:
#line 5144 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 970:
#line 5145 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 971:
#line 5148 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 972:
#line 5149 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 973:
#line 5154 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 974:
#line 5161 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 975:
#line 5164 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 976:
#line 5170 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 977:
#line 5172 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 978:
#line 5174 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 979:
#line 5176 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 980:
#line 5179 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 981:
#line 5179 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 982:
#line 5180 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 983:
#line 5185 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 984:
#line 5193 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 985:
#line 5194 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 986:
#line 5199 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 987:
#line 5201 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 988:
#line 5203 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 5220 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 993:
#line 5223 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 994:
#line 5226 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 995:
#line 5229 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 996:
#line 5233 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 997:
#line 5236 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 998:
#line 5239 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 999:
#line 5243 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5247 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5251 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1002:
#line 5254 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1003:
#line 5258 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1004:
#line 5261 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1005:
#line 5262 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5263 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1007:
#line 5266 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1008:
#line 5269 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1009:
#line 5272 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1010:
#line 5275 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1011:
#line 5278 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1012:
#line 5281 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1013:
#line 5284 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1014:
#line 5301 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1017:
#line 5311 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1018:
#line 5318 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1020:
#line 5339 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1021:
#line 5344 "fgl.yacc"
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

  case 1022:
#line 5357 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1023:
#line 5362 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1024:
#line 5363 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1025:
#line 5367 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1029:
#line 5373 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1030:
#line 5375 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1032:
#line 5390 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1033:
#line 5394 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1034:
#line 5400 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1035:
#line 5401 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1036:
#line 5404 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1037:
#line 5405 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1038:
#line 5408 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1040:
#line 5427 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1041:
#line 5432 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1042:
#line 5437 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1043:
#line 5442 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1049:
#line 5464 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1050:
#line 5471 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1051:
#line 5480 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1052:
#line 5486 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1053:
#line 5488 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1057:
#line 5499 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1058:
#line 5500 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1059:
#line 5502 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1060:
#line 5503 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1061:
#line 5505 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1062:
#line 5506 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1063:
#line 5508 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1064:
#line 5509 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1065:
#line 5511 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1066:
#line 5512 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1067:
#line 5513 "fgl.yacc"
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

  case 1068:
#line 5527 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1069:
#line 5529 "fgl.yacc"
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

  case 1070:
#line 5546 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1077:
#line 5558 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1078:
#line 5558 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1079:
#line 5564 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1080:
#line 5564 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1081:
#line 5567 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1082:
#line 5567 "fgl.yacc"
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

  case 1083:
#line 5577 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1084:
#line 5578 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1085:
#line 5579 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1086:
#line 5586 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1087:
#line 5598 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1093:
#line 5609 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1094:
#line 5614 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1095:
#line 5618 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1096:
#line 5623 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1097:
#line 5629 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1098:
#line 5630 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1099:
#line 5631 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1100:
#line 5635 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1101:
#line 5636 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1102:
#line 5637 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1103:
#line 5638 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1104:
#line 5642 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1105:
#line 5652 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1106:
#line 5654 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1107:
#line 5659 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1108:
#line 5662 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1109:
#line 5667 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1110:
#line 5674 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1111:
#line 5681 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1112:
#line 5688 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1113:
#line 5697 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1114:
#line 5704 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1115:
#line 5711 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1116:
#line 5718 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1117:
#line 5725 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1122:
#line 5738 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1123:
#line 5739 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1124:
#line 5740 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1125:
#line 5741 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5742 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5743 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1128:
#line 5744 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1129:
#line 5745 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1130:
#line 5746 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1131:
#line 5747 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1134:
#line 5753 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1135:
#line 5754 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1136:
#line 5755 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1137:
#line 5756 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1142:
#line 5765 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1143:
#line 5766 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1144:
#line 5767 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1145:
#line 5768 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1146:
#line 5769 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5770 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5771 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1149:
#line 5772 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5774 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1151:
#line 5775 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1152:
#line 5776 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1153:
#line 5777 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1154:
#line 5779 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1155:
#line 5780 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1156:
#line 5781 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1157:
#line 5782 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1161:
#line 5787 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1162:
#line 5788 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1166:
#line 5795 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1167:
#line 5802 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1168:
#line 5809 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1169:
#line 5820 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1170:
#line 5829 "fgl.yacc"
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

  case 1171:
#line 5840 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1172:
#line 5844 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1173:
#line 5848 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1174:
#line 5854 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1175:
#line 5859 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1176:
#line 5867 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1177:
#line 5870 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1178:
#line 5879 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1179:
#line 5890 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1181:
#line 5897 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1182:
#line 5905 "fgl.yacc"
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

  case 1183:
#line 5915 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1184:
#line 5918 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1185:
#line 5922 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1186:
#line 5930 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1187:
#line 5933 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1188:
#line 5939 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1189:
#line 5943 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1190:
#line 5947 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1191:
#line 5951 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1192:
#line 5955 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1193:
#line 5961 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1194:
#line 5962 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1195:
#line 5963 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1196:
#line 5964 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1197:
#line 5969 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1198:
#line 5971 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1199:
#line 5974 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1200:
#line 5978 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1201:
#line 5981 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1202:
#line 5988 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1203:
#line 5993 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1204:
#line 5994 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1205:
#line 5995 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1206:
#line 6000 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1207:
#line 6001 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1208:
#line 6007 "fgl.yacc"
    {insql=1;}
    break;

  case 1209:
#line 6007 "fgl.yacc"
    {insql=0;}
    break;

  case 1210:
#line 6007 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1211:
#line 6012 "fgl.yacc"
    {insql=1;}
    break;

  case 1212:
#line 6012 "fgl.yacc"
    {insql=0;}
    break;

  case 1213:
#line 6012 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1214:
#line 6023 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1215:
#line 6024 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1216:
#line 6030 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1217:
#line 6032 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1219:
#line 6039 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1220:
#line 6043 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1221:
#line 6044 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1223:
#line 6049 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1224:
#line 6052 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1225:
#line 6058 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1226:
#line 6061 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6069 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1229:
#line 6076 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1230:
#line 6083 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1231:
#line 6086 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1232:
#line 6095 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1233:
#line 6098 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1234:
#line 6101 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1235:
#line 6104 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1236:
#line 6107 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6110 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6113 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6120 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1240:
#line 6123 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1241:
#line 6130 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1242:
#line 6133 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1243:
#line 6139 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1244:
#line 6142 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1245:
#line 6149 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1246:
#line 6152 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1248:
#line 6160 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1250:
#line 6169 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1251:
#line 6172 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1252:
#line 6178 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1253:
#line 6181 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1254:
#line 6187 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1255:
#line 6194 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1256:
#line 6195 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1257:
#line 6199 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1258:
#line 6205 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1259:
#line 6208 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1261:
#line 6216 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1262:
#line 6223 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6226 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1267:
#line 6244 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1273:
#line 6250 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1274:
#line 6253 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1275:
#line 6256 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1276:
#line 6262 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1278:
#line 6268 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1280:
#line 6279 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1281:
#line 6293 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1282:
#line 6302 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1283:
#line 6302 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1284:
#line 6307 "fgl.yacc"
    {insql=1;}
    break;

  case 1285:
#line 6307 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1286:
#line 6312 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1287:
#line 6315 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6317 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6324 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6328 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1292:
#line 6332 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1293:
#line 6339 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 6342 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1295:
#line 6349 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1296:
#line 6353 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1297:
#line 6357 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1298:
#line 6366 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1299:
#line 6370 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1300:
#line 6376 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1301:
#line 6380 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1302:
#line 6386 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1303:
#line 6393 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1304:
#line 6397 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1305:
#line 6402 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1306:
#line 6412 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1307:
#line 6415 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1308:
#line 6417 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1309:
#line 6419 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1310:
#line 6421 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1311:
#line 6423 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1312:
#line 6425 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6427 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1314:
#line 6433 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1315:
#line 6443 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1316:
#line 6450 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1318:
#line 6456 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1322:
#line 6465 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1325:
#line 6470 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1326:
#line 6475 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1327:
#line 6482 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1328:
#line 6483 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1329:
#line 6490 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1330:
#line 6501 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1331:
#line 6502 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1332:
#line 6505 "fgl.yacc"
    {insql=1;}
    break;

  case 1333:
#line 6505 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1334:
#line 6510 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1335:
#line 6515 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1337:
#line 6521 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1339:
#line 6525 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1340:
#line 6530 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1341:
#line 6535 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1342:
#line 6539 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1344:
#line 6545 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1345:
#line 6549 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1346:
#line 6557 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1347:
#line 6560 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1348:
#line 6562 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1349:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1352:
#line 6574 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1356:
#line 6581 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1357:
#line 6584 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1358:
#line 6586 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1360:
#line 6592 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1362:
#line 6598 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6608 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1366:
#line 6613 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1367:
#line 6615 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1369:
#line 6621 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6624 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1372:
#line 6630 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1373:
#line 6638 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6643 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 6653 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6659 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6665 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6667 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6673 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6678 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1385:
#line 6681 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1386:
#line 6684 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1387:
#line 6692 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6694 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1389:
#line 6705 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1390:
#line 6710 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1392:
#line 6714 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1393:
#line 6716 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1394:
#line 6723 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1395:
#line 6726 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1396:
#line 6732 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1397:
#line 6736 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1398:
#line 6740 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1399:
#line 6744 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1400:
#line 6747 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1401:
#line 6755 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1402:
#line 6762 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1405:
#line 6771 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1406:
#line 6777 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1407:
#line 6780 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1408:
#line 6791 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1409:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6804 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1411:
#line 6807 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1412:
#line 6814 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6821 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1415:
#line 6828 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1416:
#line 6834 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1417:
#line 6835 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6836 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1420:
#line 6840 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6845 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1423:
#line 6852 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1424:
#line 6857 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1425:
#line 6858 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1426:
#line 6861 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1427:
#line 6864 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1428:
#line 6869 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1429:
#line 6870 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1430:
#line 6875 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1431:
#line 6878 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1432:
#line 6884 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1433:
#line 6887 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1434:
#line 6893 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1435:
#line 6896 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 6902 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1437:
#line 6905 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1438:
#line 6912 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1439:
#line 6913 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1440:
#line 6942 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1441:
#line 6944 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 6958 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1446:
#line 6961 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 6964 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1448:
#line 6967 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 6978 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1453:
#line 6984 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 6990 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1456:
#line 6993 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1457:
#line 6996 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1458:
#line 6999 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7002 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1460:
#line 7005 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7008 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1463:
#line 7015 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1468:
#line 7022 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1469:
#line 7023 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1470:
#line 7028 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1471:
#line 7031 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7035 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7041 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7042 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1475:
#line 7043 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1476:
#line 7044 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1481:
#line 7064 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7070 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1485:
#line 7073 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7078 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7081 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7084 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7089 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7091 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7094 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1500:
#line 7095 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1501:
#line 7102 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7107 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1509:
#line 7123 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1510:
#line 7124 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1511:
#line 7128 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1512:
#line 7129 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1514:
#line 7147 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1515:
#line 7148 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1516:
#line 7149 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1517:
#line 7153 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1518:
#line 7156 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7162 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1520:
#line 7167 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1521:
#line 7172 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1523:
#line 7183 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1528:
#line 7198 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1529:
#line 7201 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 7204 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1531:
#line 7206 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1532:
#line 7209 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1533:
#line 7211 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1534:
#line 7214 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1535:
#line 7214 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1536:
#line 7214 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1537:
#line 7214 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1538:
#line 7214 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1539:
#line 7214 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1540:
#line 7215 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1541:
#line 7218 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1542:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1543:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1544:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1545:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1546:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1547:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1548:
#line 7225 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1549:
#line 7228 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1564:
#line 7237 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1565:
#line 7238 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1566:
#line 7242 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1567:
#line 7250 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1568:
#line 7250 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1569:
#line 7255 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1570:
#line 7255 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1571:
#line 7261 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1572:
#line 7261 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1573:
#line 7266 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1574:
#line 7266 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1575:
#line 7273 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1576:
#line 7274 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1577:
#line 7275 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1581:
#line 7282 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7283 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7288 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1584:
#line 7291 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1585:
#line 7297 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1586:
#line 7302 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1587:
#line 7311 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1588:
#line 7323 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1589:
#line 7324 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1590:
#line 7327 "fgl.yacc"
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

  case 1591:
#line 7342 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1592:
#line 7352 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1593:
#line 7355 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1594:
#line 7363 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1595:
#line 7372 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1596:
#line 7375 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1597:
#line 7379 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1598:
#line 7382 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1599:
#line 7383 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1601:
#line 7392 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1602:
#line 7393 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1603:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1604:
#line 7411 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1605:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1606:
#line 7417 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1607:
#line 7418 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1608:
#line 7419 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1609:
#line 7427 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7430 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1611:
#line 7436 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7439 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1613:
#line 7450 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1614:
#line 7459 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1615:
#line 7462 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1616:
#line 7465 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7471 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7477 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7480 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7483 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1621:
#line 7486 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1622:
#line 7493 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1623:
#line 7495 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1624:
#line 7497 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1625:
#line 7499 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7501 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7502 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1628:
#line 7503 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1629:
#line 7504 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1630:
#line 7505 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1631:
#line 7506 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1632:
#line 7507 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1633:
#line 7509 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1634:
#line 7511 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1635:
#line 7513 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1636:
#line 7515 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7517 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7519 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7521 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7522 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7524 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1642:
#line 7528 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1643:
#line 7529 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1646:
#line 7539 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1647:
#line 7548 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1648:
#line 7552 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1649:
#line 7559 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1650:
#line 7559 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1652:
#line 7563 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1653:
#line 7568 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1654:
#line 7568 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1656:
#line 7572 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1657:
#line 7576 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1660:
#line 7585 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1661:
#line 7585 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1666:
#line 7604 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1667:
#line 7605 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1670:
#line 7613 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1671:
#line 7619 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1674:
#line 7638 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1675:
#line 7639 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1676:
#line 7640 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1677:
#line 7641 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1678:
#line 7642 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1679:
#line 7643 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1680:
#line 7647 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1681:
#line 7648 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7649 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1683:
#line 7653 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1684:
#line 7657 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1686:
#line 7666 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1688:
#line 7671 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1689:
#line 7672 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1690:
#line 7676 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1691:
#line 7682 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1692:
#line 7769 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1693:
#line 7773 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1694:
#line 7775 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1695:
#line 7782 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1696:
#line 7786 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1697:
#line 7792 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1698:
#line 7800 "fgl.yacc"
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

  case 1699:
#line 7810 "fgl.yacc"
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

  case 1700:
#line 7820 "fgl.yacc"
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

  case 1701:
#line 7832 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1702:
#line 7835 "fgl.yacc"
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

  case 1703:
#line 7854 "fgl.yacc"
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

  case 1704:
#line 7880 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1705:
#line 7883 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1707:
#line 7892 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1708:
#line 7897 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1709:
#line 7900 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1710:
#line 7908 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1711:
#line 7916 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1712:
#line 7929 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1713:
#line 7932 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1714:
#line 7940 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1715:
#line 7943 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1716:
#line 7946 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1717:
#line 7954 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1718:
#line 7958 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1719:
#line 7961 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1720:
#line 7964 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1721:
#line 7967 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1722:
#line 7971 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1723:
#line 7972 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1724:
#line 7973 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1725:
#line 7974 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1726:
#line 7975 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1727:
#line 7981 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1728:
#line 7982 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1729:
#line 7983 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1730:
#line 7984 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 7985 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1732:
#line 7986 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1733:
#line 7987 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1734:
#line 7988 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1735:
#line 7989 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1736:
#line 7990 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1737:
#line 7991 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1738:
#line 7992 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1739:
#line 7993 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1740:
#line 7994 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);printf("C14\n");}
    break;

  case 1741:
#line 7998 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1742:
#line 8004 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1743:
#line 8005 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1744:
#line 8018 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1745:
#line 8029 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1749:
#line 8035 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1750:
#line 8036 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1754:
#line 8048 "fgl.yacc"
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

  case 1755:
#line 8062 "fgl.yacc"
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

  case 1756:
#line 8113 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 8115 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 8117 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1759:
#line 8118 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1760:
#line 8123 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1761:
#line 8128 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1762:
#line 8129 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1763:
#line 8133 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8135 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8137 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1766:
#line 8140 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1767:
#line 8144 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1768:
#line 8149 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1769:
#line 8154 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1770:
#line 8158 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1772:
#line 8168 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1774:
#line 8183 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1775:
#line 8186 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1776:
#line 8190 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1779:
#line 8209 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1780:
#line 8210 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1781:
#line 8213 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1782:
#line 8214 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1783:
#line 8215 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1784:
#line 8216 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1785:
#line 8217 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1786:
#line 8218 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1787:
#line 8219 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1788:
#line 8224 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1789:
#line 8225 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1790:
#line 8229 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1791:
#line 8233 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1792:
#line 8237 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1793:
#line 8241 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1794:
#line 8246 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1795:
#line 8250 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1796:
#line 8255 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1798:
#line 8263 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1800:
#line 8269 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1801:
#line 8275 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1802:
#line 8279 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1807:
#line 8297 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1808:
#line 8304 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1809:
#line 8313 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1810:
#line 8313 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 16897 "y.tab.c"

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


#line 8408 "fgl.yacc"

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



