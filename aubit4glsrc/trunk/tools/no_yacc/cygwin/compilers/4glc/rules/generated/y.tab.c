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
     NAME = 1653,
     UMINUS = 1654,
     COMMA = 1569,
     KW_OR = 1609,
     KW_AND = 1564,
     KW_USING = 1500,
     MATCHES = 1378,
     POWER = 1486,
     LESS_THAN = 1482,
     GREATER_THAN = 1396,
     EQUAL = 1559,
     GREATER_THAN_EQ = 1295,
     LESS_THAN_EQ = 1353,
     NOT_EQUAL = 1427,
     PLUS = 1595,
     MINUS = 1582,
     DIVIDE = 1515,
     MULTIPLY = 1487,
     MOD = 1583,
     COMMAND = 1360,
     NUMBER_VALUE = 1655,
     CHAR_VALUE = 1656,
     INT_VALUE = 1657,
     NAMED_GEN = 1658,
     CLINE = 1659,
     SQLLINE = 1660,
     KW_CSTART = 1661,
     KW_CEND = 1662,
     USER_DTYPE = 1663,
     SQL_TEXT = 1664,
     BEFORE_INSERT = 1000,
     CONCAT_PIPES = 1001,
     BEFORE_DELETE = 1002,
     AFTER_INSERT = 1003,
     AFTER_DELETE = 1004,
     DELETE_ROW_EQUAL_TRUE = 1005,
     INSERT_ROW_EQUAL_TRUE = 1006,
     DELETE_ROW_EQUAL_FALSE = 1007,
     INSERT_ROW_EQUAL_FALSE = 1008,
     CURRENT_ROW_DISPLAY_EQUAL = 1009,
     MAXCOUNT = 1010,
     ALTER_TABLE = 1011,
     WHENEVER_ERROR_CONTINUE = 1012,
     WHENEVER_WARNING_CONTINUE = 1013,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1014,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1015,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1016,
     XSET_MULTIPLY_EQUAL = 1017,
     XSET_OPEN_BRACKET = 1018,
     NEWFORMATSHARED = 1019,
     CREATE_DATABASE = 1020,
     IMPORT_LEGACY_FUNCTION = 1021,
     ADD_CONSTRAINT = 1022,
     DROP_CONSTRAINT = 1023,
     AS_STATIC = 1024,
     NOT_FIELD_TOUCHED = 1025,
     LOCAL_FUNCTION = 1026,
     EVERY_ROW = 1027,
     ELIF = 1028,
     DOUBLE_PRECISION = 1029,
     COUNT_MULTIPLY = 1030,
     WAIT_FOR_KEY = 1031,
     AT_TERMINATION_CALL = 1032,
     TERMINATE_REPORT = 1033,
     TO_MAIN_CAPTION = 1034,
     CLEARSTAT = 1035,
     TO_MENUITEM = 1036,
     ID_TO_INT = 1037,
     TO_STATUSBOX = 1038,
     ASCII_HEIGHT_ALL = 1039,
     ASCII_WIDTH_ALL = 1040,
     IMPORT_DATATYPE = 1041,
     UP_BY = 1042,
     PAGE_TRAILER_SIZE = 1043,
     PAGE_HEADER_SIZE = 1044,
     FIRST_PAGE_HEADER_SIZE = 1045,
     BYTES_USE_AS_IMAGE = 1046,
     BYTES_USE_AS_ASCII = 1047,
     DOWN_BY = 1048,
     CLOSE_STATUSBOX = 1049,
     MODIFY_NEXT_SIZE = 1050,
     LOCK_MODE_PAGE = 1051,
     LOCK_MODE_ROW = 1052,
     TO_PIPE = 1053,
     TO_PRINTER = 1054,
     STATUSBOX = 1055,
     CONNECT_TO = 1056,
     FORMHANDLER_INPUT = 1057,
     UNITS_YEAR = 1058,
     UNITS_MONTH = 1059,
     UNITS_DAY = 1060,
     UNITS_HOUR = 1061,
     UNITS_MINUTE = 1062,
     UNITS_SECOND = 1063,
     NO_NEW_LINES = 1064,
     FIELDTOWIDGET = 1065,
     WITH_HOLD = 1066,
     SHOW_MENU = 1067,
     CWIS = 1068,
     CREATE_IDX = 1069,
     FORM_IS_COMPILED = 1070,
     PDF_REPORT = 1071,
     IMPORT_FUNCTION = 1072,
     PROMPT_MANY = 1073,
     POINTS = 1074,
     MM = 1075,
     INCHES = 1076,
     PREPEND = 1077,
     MEMBER_OF = 1078,
     MEMBER_FUNCTION = 1079,
     APPEND = 1080,
     TEMPLATE = 1081,
     END_TEMPLATE = 1082,
     SQLSICS = 1083,
     CREATE_SCHEMA = 1084,
     SQLSIRR = 1085,
     UPDATESTATS_T = 1086,
     SQLSICR = 1087,
     WHENEVER_SQLSUCCESS = 1088,
     WHENEVER_SQLWARNING = 1089,
     START_EXTERN = 1090,
     WHENEVER_ANY_ERROR = 1091,
     WHENEVER_NOT_FOUND = 1092,
     CONTINUE_CONSTRUCT = 1093,
     FOUNCONSTR = 1094,
     SQLSIDR = 1095,
     WHENEVER_SQLERROR = 1096,
     CREATE_TEMP_TABLE = 1097,
     CURRENT_WINDOW_IS = 1098,
     FIRST_PAGE_HEADER = 1099,
     ORDER_EXTERNAL_BY = 1100,
     SCROLL_CURSOR_FOR = 1101,
     SCROLL_CURSOR = 1102,
     SQL_INTERRUPT_OFF = 1103,
     STOP_ALL_EXTERNAL = 1104,
     WITH_CHECK_OPTION = 1105,
     WITH_GRANT_OPTION = 1106,
     SQLSLMNW = 1107,
     ADDCONSTUNIQ = 1108,
     CONTINUE_DISPLAY = 1109,
     CONTINUE_FOREACH = 1110,
     OUTPUT_TO_REPORT = 1111,
     SQL_INTERRUPT_ON = 1112,
     WHENEVER_SUCCESS = 1113,
     WHENEVER_WARNING = 1114,
     WHERE_CURRENT_OF = 1115,
     WITHOUT_DEFAULTS = 1116,
     FOCONSTR = 1117,
     SCALED_BY = 1118,
     CONTINUE_PROMPT = 1119,
     PDF_FUNCTION = 1120,
     DEFER_INTERRUPT = 1121,
     DISPLAY_BY_NAME = 1122,
     NOT_NULL_UNIQUE = 1123,
     SKIP_TO_TOP = 1124,
     TOP_OF_PAGE = 1125,
     SKIP_TO = 1126,
     SKIP_BY = 1127,
     WITHOUT_WAITING = 1128,
     BEFCONSTRUCT = 1129,
     SQLSLMW = 1130,
     WHENEVER_ERROR = 1131,
     AFTCONSTRUCT = 1132,
     ALL_PRIVILEGES = 1133,
     CLOSE_DATABASE = 1134,
     CONTINUE_INPUT = 1135,
     CONTINUE_WHILE = 1136,
     CREATE_SYNONYM = 1137,
     DROP_TABLE = 1138,
     EXIT_CONSTRUCT = 1139,
     INEXCLUSIVE = 1140,
     REPORT_TO_PRINTER = 1141,
     REPORT_TO_PIPE = 1142,
     SET_SESSION_TO = 1143,
     UPDATESTATS = 1144,
     WITHOUT_HEAD = 1145,
     CLEARSCR = 1146,
     WITH_B_LOG = 1147,
     AUTHORIZATION = 1148,
     BOTTOM_MARGIN = 1149,
     CLOSE_SESSION = 1150,
     CONTINUE_CASE = 1151,
     CONTINUE_MENU = 1152,
     DISPLAY_ARRAY = 1153,
     END_SQL = 1154,
     DOLLAR = 1155,
     END_CONSTRUCT = 1156,
     FIELD_TOUCHED = 1157,
     FINISH_REPORT = 1158,
     INFACC = 1159,
     INPUT_NO_WRAP = 1160,
     LOCKMODEPAGE = 1161,
     SETPMOFF = 1162,
     UNCONSTRAINED = 1163,
     PAGE_TRAILER = 1164,
     SETPMON = 1165,
     BEFGROUP = 1166,
     CLOSE_WINDOW = 1167,
     COMMENT_LINE = 1168,
     CONTINUE_FOR = 1169,
     CREATE_DB = 1170,
     CREATE_TABLE = 1171,
     DEFAULT_NULL = 1172,
     DELETE_USING = 1173,
     DISPLAY_FORM = 1174,
     END_FUNCTION = 1175,
     EXIT_DISPLAY = 1176,
     EXIT_FOREACH = 1177,
     EXIT_PROGRAM = 1178,
     INFCOLS = 1179,
     LOCKMODEROW = 1180,
     ON_EVERY_ROW = 1181,
     OPEN_SESSION = 1182,
     RIGHT_MARGIN = 1183,
     SELECT_USING = 1184,
     START_REPORT = 1185,
     UNLOCK_TABLE = 1186,
     UPDATE_USING = 1187,
     ACL_BUILTIN = 1188,
     AFTGROUP = 1189,
     INFIDX = 1190,
     INFSTAT = 1191,
     LEFT_MARGIN = 1192,
     PAGE_HEADER = 1193,
     ROLLBACK_W = 1194,
     SET_SESSION = 1195,
     SQLSEOFF = 1196,
     WITH_A_LOG = 1197,
     BEFDISP = 1198,
     BEFORE_MENU = 1199,
     CREATE_VIEW = 1200,
     DEFINE_TYPE = 1201,
     DELETE_FROM = 1202,
     END_DISPLAY = 1203,
     END_REPORT = 1204,
     END_FOREACH = 1205,
     END_FOR = 1206,
     END_GLOBALS = 1207,
     EXIT_PROMPT = 1208,
     EXTENT_SIZE = 1209,
     FOREIGN_KEY = 1210,
     HIDE_OPTION = 1211,
     HIDE_WINDOW = 1212,
     INSERT_INTO = 1213,
     IS_NOT_NULL = 1214,
     MOVE_WINDOW = 1215,
     NEXT_OPTION = 1216,
     NOT_MATCHES = 1217,
     ON_LAST_ROW = 1218,
     OPEN_WINDOW = 1219,
     OPEN_STATUSBOX = 1220,
     PAGE_LENGTH = 1221,
     PAGE_WIDTH = 1222,
     PRIMARY_KEY = 1223,
     PROMPT_LINE = 1224,
     RECORD_LIKE = 1225,
     ROLLFORWARD = 1226,
     SETBL = 1227,
     SHOW_OPTION = 1228,
     SHOW_WINDOW = 1229,
     SQLSEON = 1230,
     TO_DATABASE = 1231,
     USE_SESSION = 1232,
     WITH_NO_LOG = 1233,
     AFTDISP = 1234,
     BEFFIELD = 1235,
     INSHARE = 1236,
     UNLOCKTAB = 1237,
     AFTFIELD = 1238,
     ATTRIBUTES = 1239,
     BEFINP = 1240,
     BEGIN_WORK = 1241,
     CLEARWIN = 1242,
     CLOSE_FORM = 1243,
     DEFER_QUIT = 1244,
     DESCENDING = 1245,
     DROP_INDEX = 1246,
     END_PROMPT = 1247,
     END_RECORD = 1248,
     ERROR_LINE = 1249,
     EXIT_INPUT = 1250,
     EXIT_WHILE = 1251,
     FOR_UPDATE_OF = 1252,
     FOR_UPDATE = 1253,
     GET_FLDBUF = 1254,
     INITIALIZE = 1255,
     INPUT_WRAP = 1256,
     LOCK_TABLE = 1257,
     MSG_LINE = 1258,
     NOT_EXISTS = 1259,
     ON_ANY_KEY = 1260,
     REFERENCES = 1261,
     RENCOL = 1262,
     SET_CURSOR = 1263,
     SMALLFLOAT = 1264,
     SQLSUCCESS = 1265,
     TOP_MARGIN = 1266,
     WITH_ARRAY = 1267,
     ACCEPTKEY = 1268,
     ACCEPT = 1269,
     AFTINP = 1270,
     CLEARFORMTODEFAULTS = 1271,
     CLEARFORM = 1272,
     CLEAR_X_FORM = 1273,
     COMMIT_W = 1274,
     NEXTPAGE = 1275,
     PREVPAGE = 1276,
     CTRL_KEY = 1277,
     INFTABS = 1278,
     NEXTFIELD = 1279,
     NEXTFORM = 1280,
     RENTAB = 1281,
     ASCENDING = 1282,
     ASSOCIATE = 1283,
     CHARACTER = 1284,
     CONSTRUCT = 1285,
     DELIMITER = 1286,
     DOWNSHIFT = 1287,
     DROP_VIEW = 1288,
     END_INPUT = 1289,
     END_WHILE = 1290,
     EXCLUSIVE = 1291,
     EXIT_CASE = 1292,
     EXIT_MENU = 1293,
     FORM_LINE = 1294,
     INTERRUPT = 1296,
     INTO_TEMP = 1297,
     INVISIBLE = 1298,
     IN_MEMORY = 1299,
     LINKED_TO = 1300,
     LOAD_FROM = 1301,
     LOCKTAB = 1302,
     MENU_LINE = 1303,
     OPEN_FORM = 1304,
     OTHERWISE = 1305,
     PRECISION = 1306,
     PRIOR = 1307,
     PROCEDURE = 1308,
     REPORT_TO = 1309,
     RETURNING = 1310,
     UNDERLINE = 1311,
     UNLOAD_TO = 1312,
     BEFROW = 1313,
     UNLOAD_T = 1314,
     VARIABLE = 1315,
     ABSOLUTE = 1316,
     AFTROW = 1317,
     BUFFERED = 1318,
     CONSTANT = 1319,
     CONST = 1320,
     CONTINUE = 1321,
     DATABASE = 1322,
     DATETIME = 1323,
     DEFAULTS = 1324,
     DISTINCT = 1325,
     END_CASE = 1326,
     END_MAIN = 1327,
     END_MENU = 1328,
     END_TYPE = 1329,
     EXIT_FOR = 1330,
     EXTERNAL = 1331,
     FRACTION = 1332,
     FUNCTION = 1333,
     GROUP_BY = 1334,
     INTERVAL = 1335,
     KWMESSAGE = 1336,
     NOT_LIKE = 1337,
     NOT_NULL = 1338,
     PASSWORD = 1339,
     PREVIOUS = 1340,
     READONLY = 1341,
     REGISTER = 1342,
     RELATIVE = 1343,
     RESOURCE = 1344,
     SMALLINT = 1345,
     VALIDATE = 1346,
     WHENEVER = 1347,
     WITH_LOG = 1348,
     WORDWRAP = 1349,
     BY_NAME = 1350,
     IN_FILE = 1351,
     IS_NULL = 1352,
     AVERAGE = 1354,
     BETWEEN = 1355,
     CAPTION = 1356,
     CLIPPED = 1357,
     CLOSE_BRACKET = 1358,
     COLUMNS = 1359,
     COMMENT = 1361,
     CONNECT = 1362,
     CURRENT = 1363,
     DBYNAME = 1364,
     DECIMAL = 1365,
     DECLARE = 1366,
     DEFAULT = 1367,
     DISPLAY = 1368,
     ENDCODE = 1369,
     EXECUTE = 1370,
     FOREACH = 1371,
     FOREIGN = 1372,
     GLOBALS = 1373,
     INFIELD = 1374,
     INTEGER = 1375,
     KWWINDOW = 1376,
     MAGENTA = 1377,
     NUMERIC = 1379,
     OPTIONS = 1380,
     PERCENT = 1381,
     PREPARE = 1382,
     PROGRAM = 1383,
     RECOVER = 1384,
     REVERSE = 1385,
     SECTION = 1386,
     SESSION = 1387,
     SYNONYM = 1388,
     THRU = 1389,
     TRAILER = 1390,
     UPSHIFT = 1391,
     VARCHAR = 1392,
     WAITING = 1393,
     CLOSE_SHEV = 1394,
     CLOSE_SQUARE = 1395,
     KW_FALSE = 1397,
     NOT_IN = 1398,
     ONKEY = 1399,
     OPEN_BRACKET = 1400,
     BORDER = 1401,
     BOTTOM = 1402,
     COLUMN = 1403,
     COMMIT = 1404,
     CREATE = 1405,
     CURSOR = 1406,
     DEFINE = 1407,
     DELETE = 1408,
     DOUBLE = 1409,
     END_IF = 1410,
     ESCAPE = 1411,
     EXISTS = 1412,
     EXTEND = 1413,
     EXTENT = 1414,
     FINISH = 1415,
     FORMAT = 1416,
     HAVING = 1417,
     HEADER = 1418,
     INSERT = 1419,
     LOCATE = 1420,
     MARGIN = 1421,
     MEMORY = 1422,
     MINUTE = 1423,
     MODIFY = 1424,
     NORMAL = 1425,
     EQUAL_EQUAL = 1426,
     OPEN_SHEV = 1428,
     OPEN_SQUARE = 1429,
     OPTION = 1430,
     OUTPUT = 1431,
     PROMPT = 1432,
     PUBLIC = 1433,
     RECORD = 1434,
     REPORT = 1435,
     RETURN = 1436,
     REVOKE = 1437,
     SCHEMA = 1438,
     SCROLL_USING = 1439,
     SCROLL = 1440,
     SECOND = 1441,
     SELECT = 1442,
     SERIAL = 1443,
     SETL = 1444,
     SHARED = 1445,
     SPACES = 1446,
     UNIQUE = 1447,
     UNLOCK = 1448,
     UPDATE = 1449,
     VALUES = 1450,
     YELLOW = 1451,
     AFTER = 1452,
     KWLINE = 1453,
     KW_NULL = 1454,
     KW_TRUE = 1455,
     SINGLE_KEY = 1456,
     ALTER = 1457,
     ARRAY = 1458,
     ASCII = 1459,
     AUDIT = 1460,
     BLACK = 1461,
     BLINK = 1462,
     CHECK = 1463,
     CLEAR = 1464,
     CLOSE = 1465,
     CODE_C = 1466,
     COUNT = 1467,
     DEFER = 1468,
     ERROR = 1469,
     EVERY = 1470,
     FETCH = 1471,
     FIRST = 1472,
     FLOAT = 1473,
     FLUSH = 1474,
     FOUND = 1475,
     GRANT = 1476,
     GREEN = 1477,
     GROUP = 1478,
     INDEX = 1479,
     KWFORM = 1480,
     LABEL = 1481,
     LOCAL = 1483,
     MONEY = 1484,
     MONTH = 1485,
     ORDER = 1488,
     OUTER = 1489,
     PAUSE = 1490,
     PRINT_IMAGE = 1491,
     PRINT_FILE = 1492,
     PRINT = 1493,
     RIGHT = 1494,
     DOUBLE_COLON = 1495,
     SEMICOLON = 1496,
     SLEEP = 1497,
     TUPLE = 1498,
     UNION = 1499,
     WHERE = 1501,
     WHILE = 1502,
     WHITE = 1503,
     CCODE = 1504,
     ANSI = 1505,
     BLUE = 1506,
     BOLD = 1507,
     BYTE = 1508,
     FCALL = 1509,
     CASE = 1510,
     CHAR = 1511,
     CYAN = 1512,
     DATE = 1513,
     DESC = 1514,
     DOWN = 1516,
     TAB = 1517,
     DROP = 1518,
     ELSE = 1519,
     EXEC = 1520,
     EXIT = 1521,
     FREE = 1522,
     FROM = 1523,
     GOTO = 1524,
     HELP_FILE = 1525,
     LANG_FILE = 1526,
     HELP = 1527,
     HIDE = 1528,
     HOUR = 1529,
     INTO = 1530,
     LAST = 1531,
     LEFT = 1532,
     LIKE = 1533,
     MAIN = 1534,
     MENU = 1535,
     MODE = 1536,
     NEED = 1537,
     NEXT = 1538,
     NOCR = 1539,
     OPEN = 1540,
     QUIT = 1541,
     REAL = 1542,
     ROWS = 1543,
     SHOW = 1544,
     SIZE = 1545,
     SKIP = 1546,
     SOME = 1547,
     STEP = 1548,
     STOP = 1549,
     TEMP = 1550,
     TEXT = 1551,
     THEN = 1552,
     USER = 1553,
     WAIT = 1554,
     WHEN = 1555,
     WITH = 1556,
     WORK = 1557,
     YEAR = 1558,
     KW_IS = 1560,
     XSET = 1561,
     ADD = 1562,
     ALL = 1563,
     ANY = 1565,
     ASC = 1566,
     AVG = 1567,
     COLON = 1568,
     DAY = 1570,
     DBA = 1571,
     DEC = 1572,
     DIM = 1573,
     FKEY = 1574,
     FOR = 1575,
     KEY = 1576,
     KWNO = 1577,
     LET = 1578,
     LOG = 1579,
     XMAX = 1580,
     XMIN = 1581,
     NOT = 1584,
     PAD = 1585,
     PUT = 1586,
     RED = 1587,
     ROW = 1588,
     RUN = 1589,
     SQL = 1590,
     SUM = 1591,
     TOP = 1592,
     USE = 1593,
     ATSIGN = 1594,
     AS_TIFF = 1596,
     AS_GIF = 1597,
     AS_PNG = 1598,
     AS_JPEG = 1599,
     AS = 1600,
     AT = 1601,
     BY = 1602,
     DOT = 1603,
     GO = 1604,
     IF = 1605,
     IN = 1606,
     OF = 1607,
     ON = 1608,
     TO = 1610,
     UP = 1611,
     FONT_NAME = 1612,
     FONT_SIZE = 1613,
     PAPER_SIZE_IS_LETTER = 1614,
     PAPER_SIZE_IS_LEGAL = 1615,
     PAPER_SIZE_IS_A5 = 1616,
     PAPER_SIZE_IS_A4 = 1617,
     PAPER_SIZE_IS_LETTER_L = 1618,
     PAPER_SIZE_IS_LEGAL_L = 1619,
     PAPER_SIZE_IS_A5_L = 1620,
     PAPER_SIZE_IS_A4_L = 1621,
     FORMHANDLER = 1622,
     END_FORMHANDLER = 1623,
     BEFORE_EVENT = 1624,
     BEFORE_OPEN_FORM = 1625,
     AFTER_EVENT = 1626,
     BEFORE_CLOSE_FORM = 1627,
     BEFORE_ANY = 1628,
     AFTER_ANY = 1629,
     MENUHANDLER = 1630,
     END_MENUHANDLER = 1631,
     BEFORE_SHOW_MENU = 1632,
     DISABLE_PROGRAM = 1633,
     DISABLE_ALL = 1634,
     BUTTONS = 1635,
     CHECK_MENUITEM = 1636,
     DISABLE_FORM = 1637,
     DISABLE_MENUITEMS = 1638,
     DISABLE = 1639,
     ENABLE_FORM = 1640,
     ENABLE_MENUITEMS = 1641,
     ENABLE = 1642,
     KWFIELD = 1643,
     ICON = 1644,
     MESSAGEBOX = 1645,
     TO_DEFAULTS = 1646,
     UNCHECK_MENUITEM = 1647,
     BEFORE = 1648,
     INPUT = 1649,
     END = 1650,
     INT_TO_ID = 1651
   };
#endif
#define NAME 1653
#define UMINUS 1654
#define COMMA 1569
#define KW_OR 1609
#define KW_AND 1564
#define KW_USING 1500
#define MATCHES 1378
#define POWER 1486
#define LESS_THAN 1482
#define GREATER_THAN 1396
#define EQUAL 1559
#define GREATER_THAN_EQ 1295
#define LESS_THAN_EQ 1353
#define NOT_EQUAL 1427
#define PLUS 1595
#define MINUS 1582
#define DIVIDE 1515
#define MULTIPLY 1487
#define MOD 1583
#define COMMAND 1360
#define NUMBER_VALUE 1655
#define CHAR_VALUE 1656
#define INT_VALUE 1657
#define NAMED_GEN 1658
#define CLINE 1659
#define SQLLINE 1660
#define KW_CSTART 1661
#define KW_CEND 1662
#define USER_DTYPE 1663
#define SQL_TEXT 1664
#define BEFORE_INSERT 1000
#define CONCAT_PIPES 1001
#define BEFORE_DELETE 1002
#define AFTER_INSERT 1003
#define AFTER_DELETE 1004
#define DELETE_ROW_EQUAL_TRUE 1005
#define INSERT_ROW_EQUAL_TRUE 1006
#define DELETE_ROW_EQUAL_FALSE 1007
#define INSERT_ROW_EQUAL_FALSE 1008
#define CURRENT_ROW_DISPLAY_EQUAL 1009
#define MAXCOUNT 1010
#define ALTER_TABLE 1011
#define WHENEVER_ERROR_CONTINUE 1012
#define WHENEVER_WARNING_CONTINUE 1013
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1014
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1015
#define XSET_ident_DOT_MULTIPLY_EQUAL 1016
#define XSET_MULTIPLY_EQUAL 1017
#define XSET_OPEN_BRACKET 1018
#define NEWFORMATSHARED 1019
#define CREATE_DATABASE 1020
#define IMPORT_LEGACY_FUNCTION 1021
#define ADD_CONSTRAINT 1022
#define DROP_CONSTRAINT 1023
#define AS_STATIC 1024
#define NOT_FIELD_TOUCHED 1025
#define LOCAL_FUNCTION 1026
#define EVERY_ROW 1027
#define ELIF 1028
#define DOUBLE_PRECISION 1029
#define COUNT_MULTIPLY 1030
#define WAIT_FOR_KEY 1031
#define AT_TERMINATION_CALL 1032
#define TERMINATE_REPORT 1033
#define TO_MAIN_CAPTION 1034
#define CLEARSTAT 1035
#define TO_MENUITEM 1036
#define ID_TO_INT 1037
#define TO_STATUSBOX 1038
#define ASCII_HEIGHT_ALL 1039
#define ASCII_WIDTH_ALL 1040
#define IMPORT_DATATYPE 1041
#define UP_BY 1042
#define PAGE_TRAILER_SIZE 1043
#define PAGE_HEADER_SIZE 1044
#define FIRST_PAGE_HEADER_SIZE 1045
#define BYTES_USE_AS_IMAGE 1046
#define BYTES_USE_AS_ASCII 1047
#define DOWN_BY 1048
#define CLOSE_STATUSBOX 1049
#define MODIFY_NEXT_SIZE 1050
#define LOCK_MODE_PAGE 1051
#define LOCK_MODE_ROW 1052
#define TO_PIPE 1053
#define TO_PRINTER 1054
#define STATUSBOX 1055
#define CONNECT_TO 1056
#define FORMHANDLER_INPUT 1057
#define UNITS_YEAR 1058
#define UNITS_MONTH 1059
#define UNITS_DAY 1060
#define UNITS_HOUR 1061
#define UNITS_MINUTE 1062
#define UNITS_SECOND 1063
#define NO_NEW_LINES 1064
#define FIELDTOWIDGET 1065
#define WITH_HOLD 1066
#define SHOW_MENU 1067
#define CWIS 1068
#define CREATE_IDX 1069
#define FORM_IS_COMPILED 1070
#define PDF_REPORT 1071
#define IMPORT_FUNCTION 1072
#define PROMPT_MANY 1073
#define POINTS 1074
#define MM 1075
#define INCHES 1076
#define PREPEND 1077
#define MEMBER_OF 1078
#define MEMBER_FUNCTION 1079
#define APPEND 1080
#define TEMPLATE 1081
#define END_TEMPLATE 1082
#define SQLSICS 1083
#define CREATE_SCHEMA 1084
#define SQLSIRR 1085
#define UPDATESTATS_T 1086
#define SQLSICR 1087
#define WHENEVER_SQLSUCCESS 1088
#define WHENEVER_SQLWARNING 1089
#define START_EXTERN 1090
#define WHENEVER_ANY_ERROR 1091
#define WHENEVER_NOT_FOUND 1092
#define CONTINUE_CONSTRUCT 1093
#define FOUNCONSTR 1094
#define SQLSIDR 1095
#define WHENEVER_SQLERROR 1096
#define CREATE_TEMP_TABLE 1097
#define CURRENT_WINDOW_IS 1098
#define FIRST_PAGE_HEADER 1099
#define ORDER_EXTERNAL_BY 1100
#define SCROLL_CURSOR_FOR 1101
#define SCROLL_CURSOR 1102
#define SQL_INTERRUPT_OFF 1103
#define STOP_ALL_EXTERNAL 1104
#define WITH_CHECK_OPTION 1105
#define WITH_GRANT_OPTION 1106
#define SQLSLMNW 1107
#define ADDCONSTUNIQ 1108
#define CONTINUE_DISPLAY 1109
#define CONTINUE_FOREACH 1110
#define OUTPUT_TO_REPORT 1111
#define SQL_INTERRUPT_ON 1112
#define WHENEVER_SUCCESS 1113
#define WHENEVER_WARNING 1114
#define WHERE_CURRENT_OF 1115
#define WITHOUT_DEFAULTS 1116
#define FOCONSTR 1117
#define SCALED_BY 1118
#define CONTINUE_PROMPT 1119
#define PDF_FUNCTION 1120
#define DEFER_INTERRUPT 1121
#define DISPLAY_BY_NAME 1122
#define NOT_NULL_UNIQUE 1123
#define SKIP_TO_TOP 1124
#define TOP_OF_PAGE 1125
#define SKIP_TO 1126
#define SKIP_BY 1127
#define WITHOUT_WAITING 1128
#define BEFCONSTRUCT 1129
#define SQLSLMW 1130
#define WHENEVER_ERROR 1131
#define AFTCONSTRUCT 1132
#define ALL_PRIVILEGES 1133
#define CLOSE_DATABASE 1134
#define CONTINUE_INPUT 1135
#define CONTINUE_WHILE 1136
#define CREATE_SYNONYM 1137
#define DROP_TABLE 1138
#define EXIT_CONSTRUCT 1139
#define INEXCLUSIVE 1140
#define REPORT_TO_PRINTER 1141
#define REPORT_TO_PIPE 1142
#define SET_SESSION_TO 1143
#define UPDATESTATS 1144
#define WITHOUT_HEAD 1145
#define CLEARSCR 1146
#define WITH_B_LOG 1147
#define AUTHORIZATION 1148
#define BOTTOM_MARGIN 1149
#define CLOSE_SESSION 1150
#define CONTINUE_CASE 1151
#define CONTINUE_MENU 1152
#define DISPLAY_ARRAY 1153
#define END_SQL 1154
#define DOLLAR 1155
#define END_CONSTRUCT 1156
#define FIELD_TOUCHED 1157
#define FINISH_REPORT 1158
#define INFACC 1159
#define INPUT_NO_WRAP 1160
#define LOCKMODEPAGE 1161
#define SETPMOFF 1162
#define UNCONSTRAINED 1163
#define PAGE_TRAILER 1164
#define SETPMON 1165
#define BEFGROUP 1166
#define CLOSE_WINDOW 1167
#define COMMENT_LINE 1168
#define CONTINUE_FOR 1169
#define CREATE_DB 1170
#define CREATE_TABLE 1171
#define DEFAULT_NULL 1172
#define DELETE_USING 1173
#define DISPLAY_FORM 1174
#define END_FUNCTION 1175
#define EXIT_DISPLAY 1176
#define EXIT_FOREACH 1177
#define EXIT_PROGRAM 1178
#define INFCOLS 1179
#define LOCKMODEROW 1180
#define ON_EVERY_ROW 1181
#define OPEN_SESSION 1182
#define RIGHT_MARGIN 1183
#define SELECT_USING 1184
#define START_REPORT 1185
#define UNLOCK_TABLE 1186
#define UPDATE_USING 1187
#define ACL_BUILTIN 1188
#define AFTGROUP 1189
#define INFIDX 1190
#define INFSTAT 1191
#define LEFT_MARGIN 1192
#define PAGE_HEADER 1193
#define ROLLBACK_W 1194
#define SET_SESSION 1195
#define SQLSEOFF 1196
#define WITH_A_LOG 1197
#define BEFDISP 1198
#define BEFORE_MENU 1199
#define CREATE_VIEW 1200
#define DEFINE_TYPE 1201
#define DELETE_FROM 1202
#define END_DISPLAY 1203
#define END_REPORT 1204
#define END_FOREACH 1205
#define END_FOR 1206
#define END_GLOBALS 1207
#define EXIT_PROMPT 1208
#define EXTENT_SIZE 1209
#define FOREIGN_KEY 1210
#define HIDE_OPTION 1211
#define HIDE_WINDOW 1212
#define INSERT_INTO 1213
#define IS_NOT_NULL 1214
#define MOVE_WINDOW 1215
#define NEXT_OPTION 1216
#define NOT_MATCHES 1217
#define ON_LAST_ROW 1218
#define OPEN_WINDOW 1219
#define OPEN_STATUSBOX 1220
#define PAGE_LENGTH 1221
#define PAGE_WIDTH 1222
#define PRIMARY_KEY 1223
#define PROMPT_LINE 1224
#define RECORD_LIKE 1225
#define ROLLFORWARD 1226
#define SETBL 1227
#define SHOW_OPTION 1228
#define SHOW_WINDOW 1229
#define SQLSEON 1230
#define TO_DATABASE 1231
#define USE_SESSION 1232
#define WITH_NO_LOG 1233
#define AFTDISP 1234
#define BEFFIELD 1235
#define INSHARE 1236
#define UNLOCKTAB 1237
#define AFTFIELD 1238
#define ATTRIBUTES 1239
#define BEFINP 1240
#define BEGIN_WORK 1241
#define CLEARWIN 1242
#define CLOSE_FORM 1243
#define DEFER_QUIT 1244
#define DESCENDING 1245
#define DROP_INDEX 1246
#define END_PROMPT 1247
#define END_RECORD 1248
#define ERROR_LINE 1249
#define EXIT_INPUT 1250
#define EXIT_WHILE 1251
#define FOR_UPDATE_OF 1252
#define FOR_UPDATE 1253
#define GET_FLDBUF 1254
#define INITIALIZE 1255
#define INPUT_WRAP 1256
#define LOCK_TABLE 1257
#define MSG_LINE 1258
#define NOT_EXISTS 1259
#define ON_ANY_KEY 1260
#define REFERENCES 1261
#define RENCOL 1262
#define SET_CURSOR 1263
#define SMALLFLOAT 1264
#define SQLSUCCESS 1265
#define TOP_MARGIN 1266
#define WITH_ARRAY 1267
#define ACCEPTKEY 1268
#define ACCEPT 1269
#define AFTINP 1270
#define CLEARFORMTODEFAULTS 1271
#define CLEARFORM 1272
#define CLEAR_X_FORM 1273
#define COMMIT_W 1274
#define NEXTPAGE 1275
#define PREVPAGE 1276
#define CTRL_KEY 1277
#define INFTABS 1278
#define NEXTFIELD 1279
#define NEXTFORM 1280
#define RENTAB 1281
#define ASCENDING 1282
#define ASSOCIATE 1283
#define CHARACTER 1284
#define CONSTRUCT 1285
#define DELIMITER 1286
#define DOWNSHIFT 1287
#define DROP_VIEW 1288
#define END_INPUT 1289
#define END_WHILE 1290
#define EXCLUSIVE 1291
#define EXIT_CASE 1292
#define EXIT_MENU 1293
#define FORM_LINE 1294
#define INTERRUPT 1296
#define INTO_TEMP 1297
#define INVISIBLE 1298
#define IN_MEMORY 1299
#define LINKED_TO 1300
#define LOAD_FROM 1301
#define LOCKTAB 1302
#define MENU_LINE 1303
#define OPEN_FORM 1304
#define OTHERWISE 1305
#define PRECISION 1306
#define PRIOR 1307
#define PROCEDURE 1308
#define REPORT_TO 1309
#define RETURNING 1310
#define UNDERLINE 1311
#define UNLOAD_TO 1312
#define BEFROW 1313
#define UNLOAD_T 1314
#define VARIABLE 1315
#define ABSOLUTE 1316
#define AFTROW 1317
#define BUFFERED 1318
#define CONSTANT 1319
#define CONST 1320
#define CONTINUE 1321
#define DATABASE 1322
#define DATETIME 1323
#define DEFAULTS 1324
#define DISTINCT 1325
#define END_CASE 1326
#define END_MAIN 1327
#define END_MENU 1328
#define END_TYPE 1329
#define EXIT_FOR 1330
#define EXTERNAL 1331
#define FRACTION 1332
#define FUNCTION 1333
#define GROUP_BY 1334
#define INTERVAL 1335
#define KWMESSAGE 1336
#define NOT_LIKE 1337
#define NOT_NULL 1338
#define PASSWORD 1339
#define PREVIOUS 1340
#define READONLY 1341
#define REGISTER 1342
#define RELATIVE 1343
#define RESOURCE 1344
#define SMALLINT 1345
#define VALIDATE 1346
#define WHENEVER 1347
#define WITH_LOG 1348
#define WORDWRAP 1349
#define BY_NAME 1350
#define IN_FILE 1351
#define IS_NULL 1352
#define AVERAGE 1354
#define BETWEEN 1355
#define CAPTION 1356
#define CLIPPED 1357
#define CLOSE_BRACKET 1358
#define COLUMNS 1359
#define COMMENT 1361
#define CONNECT 1362
#define CURRENT 1363
#define DBYNAME 1364
#define DECIMAL 1365
#define DECLARE 1366
#define DEFAULT 1367
#define DISPLAY 1368
#define ENDCODE 1369
#define EXECUTE 1370
#define FOREACH 1371
#define FOREIGN 1372
#define GLOBALS 1373
#define INFIELD 1374
#define INTEGER 1375
#define KWWINDOW 1376
#define MAGENTA 1377
#define NUMERIC 1379
#define OPTIONS 1380
#define PERCENT 1381
#define PREPARE 1382
#define PROGRAM 1383
#define RECOVER 1384
#define REVERSE 1385
#define SECTION 1386
#define SESSION 1387
#define SYNONYM 1388
#define THRU 1389
#define TRAILER 1390
#define UPSHIFT 1391
#define VARCHAR 1392
#define WAITING 1393
#define CLOSE_SHEV 1394
#define CLOSE_SQUARE 1395
#define KW_FALSE 1397
#define NOT_IN 1398
#define ONKEY 1399
#define OPEN_BRACKET 1400
#define BORDER 1401
#define BOTTOM 1402
#define COLUMN 1403
#define COMMIT 1404
#define CREATE 1405
#define CURSOR 1406
#define DEFINE 1407
#define DELETE 1408
#define DOUBLE 1409
#define END_IF 1410
#define ESCAPE 1411
#define EXISTS 1412
#define EXTEND 1413
#define EXTENT 1414
#define FINISH 1415
#define FORMAT 1416
#define HAVING 1417
#define HEADER 1418
#define INSERT 1419
#define LOCATE 1420
#define MARGIN 1421
#define MEMORY 1422
#define MINUTE 1423
#define MODIFY 1424
#define NORMAL 1425
#define EQUAL_EQUAL 1426
#define OPEN_SHEV 1428
#define OPEN_SQUARE 1429
#define OPTION 1430
#define OUTPUT 1431
#define PROMPT 1432
#define PUBLIC 1433
#define RECORD 1434
#define REPORT 1435
#define RETURN 1436
#define REVOKE 1437
#define SCHEMA 1438
#define SCROLL_USING 1439
#define SCROLL 1440
#define SECOND 1441
#define SELECT 1442
#define SERIAL 1443
#define SETL 1444
#define SHARED 1445
#define SPACES 1446
#define UNIQUE 1447
#define UNLOCK 1448
#define UPDATE 1449
#define VALUES 1450
#define YELLOW 1451
#define AFTER 1452
#define KWLINE 1453
#define KW_NULL 1454
#define KW_TRUE 1455
#define SINGLE_KEY 1456
#define ALTER 1457
#define ARRAY 1458
#define ASCII 1459
#define AUDIT 1460
#define BLACK 1461
#define BLINK 1462
#define CHECK 1463
#define CLEAR 1464
#define CLOSE 1465
#define CODE_C 1466
#define COUNT 1467
#define DEFER 1468
#define ERROR 1469
#define EVERY 1470
#define FETCH 1471
#define FIRST 1472
#define FLOAT 1473
#define FLUSH 1474
#define FOUND 1475
#define GRANT 1476
#define GREEN 1477
#define GROUP 1478
#define INDEX 1479
#define KWFORM 1480
#define LABEL 1481
#define LOCAL 1483
#define MONEY 1484
#define MONTH 1485
#define ORDER 1488
#define OUTER 1489
#define PAUSE 1490
#define PRINT_IMAGE 1491
#define PRINT_FILE 1492
#define PRINT 1493
#define RIGHT 1494
#define DOUBLE_COLON 1495
#define SEMICOLON 1496
#define SLEEP 1497
#define TUPLE 1498
#define UNION 1499
#define WHERE 1501
#define WHILE 1502
#define WHITE 1503
#define CCODE 1504
#define ANSI 1505
#define BLUE 1506
#define BOLD 1507
#define BYTE 1508
#define FCALL 1509
#define CASE 1510
#define CHAR 1511
#define CYAN 1512
#define DATE 1513
#define DESC 1514
#define DOWN 1516
#define TAB 1517
#define DROP 1518
#define ELSE 1519
#define EXEC 1520
#define EXIT 1521
#define FREE 1522
#define FROM 1523
#define GOTO 1524
#define HELP_FILE 1525
#define LANG_FILE 1526
#define HELP 1527
#define HIDE 1528
#define HOUR 1529
#define INTO 1530
#define LAST 1531
#define LEFT 1532
#define LIKE 1533
#define MAIN 1534
#define MENU 1535
#define MODE 1536
#define NEED 1537
#define NEXT 1538
#define NOCR 1539
#define OPEN 1540
#define QUIT 1541
#define REAL 1542
#define ROWS 1543
#define SHOW 1544
#define SIZE 1545
#define SKIP 1546
#define SOME 1547
#define STEP 1548
#define STOP 1549
#define TEMP 1550
#define TEXT 1551
#define THEN 1552
#define USER 1553
#define WAIT 1554
#define WHEN 1555
#define WITH 1556
#define WORK 1557
#define YEAR 1558
#define KW_IS 1560
#define XSET 1561
#define ADD 1562
#define ALL 1563
#define ANY 1565
#define ASC 1566
#define AVG 1567
#define COLON 1568
#define DAY 1570
#define DBA 1571
#define DEC 1572
#define DIM 1573
#define FKEY 1574
#define FOR 1575
#define KEY 1576
#define KWNO 1577
#define LET 1578
#define LOG 1579
#define XMAX 1580
#define XMIN 1581
#define NOT 1584
#define PAD 1585
#define PUT 1586
#define RED 1587
#define ROW 1588
#define RUN 1589
#define SQL 1590
#define SUM 1591
#define TOP 1592
#define USE 1593
#define ATSIGN 1594
#define AS_TIFF 1596
#define AS_GIF 1597
#define AS_PNG 1598
#define AS_JPEG 1599
#define AS 1600
#define AT 1601
#define BY 1602
#define DOT 1603
#define GO 1604
#define IF 1605
#define IN 1606
#define OF 1607
#define ON 1608
#define TO 1610
#define UP 1611
#define FONT_NAME 1612
#define FONT_SIZE 1613
#define PAPER_SIZE_IS_LETTER 1614
#define PAPER_SIZE_IS_LEGAL 1615
#define PAPER_SIZE_IS_A5 1616
#define PAPER_SIZE_IS_A4 1617
#define PAPER_SIZE_IS_LETTER_L 1618
#define PAPER_SIZE_IS_LEGAL_L 1619
#define PAPER_SIZE_IS_A5_L 1620
#define PAPER_SIZE_IS_A4_L 1621
#define FORMHANDLER 1622
#define END_FORMHANDLER 1623
#define BEFORE_EVENT 1624
#define BEFORE_OPEN_FORM 1625
#define AFTER_EVENT 1626
#define BEFORE_CLOSE_FORM 1627
#define BEFORE_ANY 1628
#define AFTER_ANY 1629
#define MENUHANDLER 1630
#define END_MENUHANDLER 1631
#define BEFORE_SHOW_MENU 1632
#define DISABLE_PROGRAM 1633
#define DISABLE_ALL 1634
#define BUTTONS 1635
#define CHECK_MENUITEM 1636
#define DISABLE_FORM 1637
#define DISABLE_MENUITEMS 1638
#define DISABLE 1639
#define ENABLE_FORM 1640
#define ENABLE_MENUITEMS 1641
#define ENABLE 1642
#define KWFIELD 1643
#define ICON 1644
#define MESSAGEBOX 1645
#define TO_DEFAULTS 1646
#define UNCHECK_MENUITEM 1647
#define BEFORE 1648
#define INPUT 1649
#define END 1650
#define INT_TO_ID 1651




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
int isin_command (char *cmd_type);
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
char *do_clobbering(char *f,char *s);


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
#line 202 "fgl.yacc"
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
#line 1569 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1581 "y.tab.c"

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
#define YYLAST   8768

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  667
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  827
/* YYNRULES -- Number of rules. */
#define YYNRULES  1896
/* YYNRULES -- Number of states. */
#define YYNSTATES  3156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1664

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
     323,   324,   325,   326,   327,    14,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,    15,   385,   386,   387,   388,   389,   390,
      22,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,     9,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,    12,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,    16,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,    11,   509,   510,   511,    10,    20,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
       8,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,    19,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,    13,
     581,   582,   583,   584,     7,   585,   586,   587,   588,     5,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,    18,    21,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,    17,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,     6,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,     2,     3,     4,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32
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
    1147,  1149,  1151,  1154,  1156,  1159,  1161,  1163,  1165,  1169,
    1171,  1175,  1177,  1181,  1183,  1185,  1187,  1190,  1192,  1194,
    1198,  1203,  1208,  1211,  1214,  1216,  1218,  1220,  1222,  1224,
    1228,  1230,  1233,  1236,  1238,  1239,  1243,  1246,  1249,  1251,
    1255,  1260,  1265,  1271,  1277,  1279,  1281,  1284,  1287,  1292,
    1297,  1300,  1303,  1308,  1313,  1315,  1318,  1321,  1324,  1327,
    1330,  1333,  1336,  1339,  1342,  1345,  1348,  1351,  1354,  1357,
    1358,  1359,  1360,  1367,  1368,  1369,  1378,  1379,  1380,  1387,
    1388,  1389,  1396,  1397,  1398,  1405,  1406,  1407,  1414,  1420,
    1426,  1432,  1440,  1441,  1445,  1447,  1449,  1454,  1459,  1464,
    1469,  1474,  1479,  1481,  1483,  1485,  1487,  1492,  1497,  1500,
    1503,  1506,  1509,  1512,  1514,  1516,  1519,  1521,  1523,  1525,
    1528,  1533,  1540,  1547,  1551,  1557,  1563,  1567,  1569,  1571,
    1575,  1577,  1581,  1582,  1583,  1595,  1596,  1599,  1600,  1601,
    1602,  1611,  1612,  1613,  1624,  1625,  1627,  1628,  1630,  1632,
    1635,  1636,  1640,  1641,  1645,  1646,  1648,  1650,  1653,  1654,
    1658,  1659,  1663,  1667,  1669,  1674,  1678,  1680,  1684,  1686,
    1690,  1692,  1696,  1698,  1701,  1702,  1706,  1707,  1711,  1712,
    1717,  1718,  1723,  1724,  1729,  1732,  1736,  1738,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1758,  1760,  1762,  1767,  1774,
    1779,  1783,  1790,  1794,  1801,  1803,  1805,  1807,  1809,  1811,
    1813,  1814,  1817,  1819,  1821,  1823,  1828,  1830,  1832,  1834,
    1839,  1843,  1850,  1854,  1861,  1863,  1865,  1868,  1871,  1874,
    1876,  1880,  1882,  1885,  1888,  1891,  1896,  1899,  1902,  1907,
    1908,  1917,  1918,  1920,  1922,  1924,  1925,  1927,  1930,  1931,
    1933,  1936,  1937,  1939,  1942,  1943,  1945,  1949,  1950,  1953,
    1954,  1962,  1963,  1964,  1968,  1969,  1970,  1978,  1984,  1987,
    1990,  1991,  1997,  2002,  2004,  2008,  2012,  2016,  2017,  2020,
    2021,  2023,  2025,  2028,  2029,  2034,  2035,  2040,  2041,  2045,
    2046,  2050,  2051,  2055,  2056,  2060,  2061,  2065,  2066,  2070,
    2071,  2075,  2076,  2080,  2081,  2085,  2087,  2091,  2093,  2097,
    2100,  2105,  2107,  2109,  2111,  2112,  2117,  2123,  2130,  2131,
    2142,  2146,  2148,  2150,  2153,  2156,  2157,  2160,  2162,  2165,
    2169,  2173,  2177,  2181,  2183,  2185,  2187,  2189,  2190,  2194,
    2196,  2197,  2201,  2204,  2205,  2209,  2211,  2215,  2217,  2221,
    2222,  2225,  2227,  2229,  2231,  2233,  2235,  2237,  2239,  2241,
    2243,  2245,  2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,
    2262,  2263,  2271,  2273,  2275,  2278,  2281,  2284,  2288,  2293,
    2294,  2298,  2299,  2301,  2303,  2306,  2308,  2310,  2312,  2314,
    2315,  2317,  2319,  2322,  2325,  2327,  2329,  2331,  2333,  2335,
    2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,  2352,  2354,
    2356,  2358,  2360,  2362,  2363,  2364,  2365,  2366,  2380,  2382,
    2383,  2384,  2391,  2394,  2396,  2399,  2402,  2404,  2406,  2409,
    2411,  2413,  2415,  2416,  2420,  2423,  2425,  2426,  2427,  2428,
    2443,  2444,  2450,  2452,  2453,  2457,  2458,  2466,  2467,  2473,
    2475,  2478,  2479,  2481,  2483,  2485,  2486,  2488,  2490,  2493,
    2496,  2499,  2501,  2503,  2505,  2507,  2511,  2513,  2515,  2516,
    2517,  2525,  2527,  2530,  2531,  2535,  2536,  2541,  2544,  2545,
    2548,  2550,  2552,  2554,  2556,  2558,  2560,  2562,  2563,  2567,
    2568,  2570,  2572,  2574,  2576,  2579,  2582,  2585,  2591,  2600,
    2602,  2604,  2606,  2611,  2616,  2618,  2620,  2622,  2624,  2627,
    2630,  2634,  2641,  2643,  2647,  2649,  2651,  2653,  2657,  2664,
    2674,  2676,  2678,  2680,  2682,  2685,  2686,  2688,  2690,  2694,
    2696,  2700,  2702,  2706,  2708,  2712,  2714,  2716,  2718,  2720,
    2724,  2726,  2730,  2732,  2736,  2738,  2740,  2742,  2746,  2749,
    2750,  2752,  2754,  2759,  2761,  2765,  2767,  2771,  2779,  2780,
    2788,  2789,  2796,  2800,  2802,  2806,  2808,  2811,  2817,  2818,
    2826,  2827,  2830,  2831,  2833,  2839,  2842,  2848,  2849,  2855,
    2862,  2867,  2868,  2870,  2872,  2877,  2878,  2881,  2882,  2888,
    2893,  2896,  2898,  2902,  2905,  2908,  2911,  2914,  2917,  2920,
    2922,  2925,  2928,  2931,  2934,  2937,  2940,  2943,  2946,  2949,
    2951,  2953,  2955,  2957,  2959,  2961,  2967,  2969,  2971,  2974,
    2979,  2981,  2982,  2993,  2999,  3000,  3002,  3003,  3006,  3008,
    3011,  3012,  3016,  3018,  3019,  3024,  3025,  3028,  3030,  3034,
    3036,  3038,  3042,  3047,  3052,  3055,  3057,  3059,  3061,  3062,
    3064,  3072,  3075,  3078,  3081,  3084,  3087,  3089,  3092,  3093,
    3097,  3098,  3102,  3103,  3107,  3108,  3112,  3113,  3117,  3118,
    3123,  3124,  3129,  3131,  3133,  3135,  3137,  3139,  3141,  3142,
    3147,  3148,  3150,  3151,  3156,  3158,  3161,  3164,  3167,  3168,
    3170,  3172,  3175,  3178,  3179,  3182,  3186,  3190,  3196,  3197,
    3200,  3205,  3207,  3209,  3211,  3213,  3215,  3216,  3218,  3220,
    3224,  3227,  3233,  3236,  3242,  3248,  3254,  3260,  3266,  3272,
    3273,  3276,  3278,  3281,  3284,  3287,  3290,  3293,  3296,  3298,
    3301,  3304,  3307,  3310,  3312,  3315,  3318,  3321,  3324,  3326,
    3328,  3330,  3331,  3334,  3337,  3340,  3343,  3346,  3349,  3352,
    3355,  3358,  3360,  3362,  3364,  3366,  3368,  3370,  3372,  3374,
    3377,  3380,  3383,  3386,  3389,  3391,  3393,  3395,  3396,  3400,
    3403,  3404,  3405,  3406,  3407,  3408,  3409,  3425,  3426,  3429,
    3432,  3433,  3435,  3436,  3437,  3438,  3439,  3440,  3441,  3457,
    3460,  3461,  3462,  3463,  3474,  3475,  3477,  3481,  3485,  3488,
    3493,  3497,  3501,  3505,  3507,  3509,  3511,  3513,  3515,  3517,
    3518,  3519,  3527,  3528,  3529,  3538,  3542,  3545,  3546,  3548,
    3550,  3554,  3557,  3560,  3562,  3564,  3568,  3570,  3572,  3575,
    3577,  3581,  3583,  3587,  3589,  3591,  3593,  3595,  3597,  3599,
    3601,  3604,  3609,  3611,  3615,  3617,  3621,  3624,  3629,  3631,
    3635,  3637,  3640,  3645,  3647,  3651,  3653,  3655,  3657,  3660,
    3663,  3668,  3671,  3676,  3678,  3682,  3684,  3686,  3688,  3691,
    3693,  3695,  3697,  3699,  3701,  3704,  3711,  3718,  3719,  3721,
    3722,  3724,  3727,  3729,  3730,  3736,  3737,  3743,  3745,  3746,
    3750,  3752,  3756,  3758,  3762,  3764,  3766,  3767,  3768,  3774,
    3777,  3779,  3780,  3781,  3785,  3786,  3787,  3791,  3793,  3795,
    3797,  3799,  3801,  3803,  3806,  3809,  3814,  3818,  3822,  3824,
    3828,  3831,  3833,  3835,  3836,  3838,  3840,  3842,  3844,  3845,
    3847,  3851,  3853,  3855,  3856,  3860,  3862,  3864,  3866,  3868,
    3870,  3872,  3874,  3876,  3878,  3880,  3882,  3884,  3892,  3893,
    3895,  3897,  3899,  3901,  3905,  3907,  3909,  3911,  3914,  3915,
    3919,  3921,  3925,  3927,  3931,  3933,  3935,  3942,  3943,  3947,
    3949,  3953,  3954,  3956,  3961,  3967,  3970,  3972,  3974,  3979,
    3981,  3985,  3990,  3995,  3997,  4001,  4003,  4005,  4007,  4010,
    4012,  4017,  4018,  4020,  4021,  4023,  4025,  4028,  4030,  4032,
    4034,  4036,  4041,  4045,  4047,  4049,  4051,  4054,  4056,  4058,
    4061,  4064,  4066,  4070,  4073,  4076,  4078,  4082,  4084,  4087,
    4092,  4094,  4097,  4099,  4103,  4108,  4109,  4111,  4112,  4114,
    4115,  4117,  4119,  4123,  4125,  4129,  4131,  4134,  4136,  4140,
    4143,  4146,  4147,  4150,  4152,  4154,  4156,  4162,  4166,  4172,
    4176,  4178,  4182,  4184,  4186,  4187,  4189,  4193,  4197,  4201,
    4208,  4213,  4218,  4224,  4226,  4228,  4230,  4232,  4234,  4236,
    4238,  4240,  4242,  4244,  4246,  4247,  4249,  4251,  4253,  4255,
    4257,  4259,  4261,  4266,  4272,  4274,  4280,  4286,  4288,  4290,
    4292,  4297,  4299,  4304,  4306,  4314,  4316,  4318,  4320,  4325,
    4332,  4333,  4336,  4341,  4343,  4345,  4347,  4349,  4351,  4353,
    4355,  4359,  4361,  4363,  4367,  4369,  4370,  4374,  4380,  4382,
    4385,  4388,  4393,  4397,  4399,  4401,  4403,  4405,  4407,  4409,
    4412,  4415,  4416,  4420,  4421,  4425,  4427,  4429,  4431,  4433,
    4435,  4437,  4439,  4444,  4446,  4448,  4450,  4452,  4454,  4456,
    4458,  4463,  4465,  4467,  4469,  4471,  4473,  4475,  4477,  4479,
    4481,  4483,  4485,  4487,  4489,  4491,  4493,  4495,  4499,  4500,
    4509,  4510,  4520,  4521,  4529,  4530,  4540,  4541,  4543,  4546,
    4548,  4552,  4554,  4558,  4564,  4566,  4568,  4570,  4572,  4575,
    4576,  4577,  4586,  4592,  4594,  4596,  4603,  4604,  4608,  4610,
    4614,  4619,  4621,  4622,  4625,  4630,  4637,  4638,  4640,  4642,
    4644,  4646,  4650,  4652,  4655,  4657,  4659,  4662,  4665,  4667,
    4669,  4671,  4674,  4679,  4683,  4686,  4690,  4694,  4698,  4700,
    4702,  4704,  4706,  4708,  4710,  4716,  4722,  4728,  4734,  4740,
    4745,  4750,  4754,  4759,  4761,  4765,  4766,  4768,  4774,  4782,
    4788,  4789,  4792,  4794,  4796,  4797,  4801,  4803,  4807,  4809,
    4811,  4813,  4814,  4818,  4820,  4822,  4824,  4826,  4831,  4838,
    4840,  4842,  4845,  4849,  4851,  4853,  4855,  4857,  4859,  4861,
    4863,  4865,  4871,  4877,  4882,  4883,  4888,  4890,  4893,  4895,
    4897,  4899,  4902,  4905,  4906,  4907,  4914,  4915,  4918,  4921,
    4929,  4933,  4937,  4940,  4943,  4946,  4948,  4952,  4954,  4958,
    4960,  4964,  4966,  4970,  4972,  4974,  4976,  4979,  4982,  4984,
    4986,  4989,  4994,  4996,  4998,  5000,  5002,  5004,  5006,  5010,
    5013,  5017,  5021,  5025,  5031,  5037,  5043,  5049,  5055,  5060,
    5065,  5069,  5074,  5076,  5078,  5082,  5084,  5087,  5089,  5091,
    5093,  5097,  5103,  5105,  5107,  5109,  5111,  5115,  5118,  5121,
    5124,  5126,  5129,  5132,  5134,  5137,  5140,  5143,  5145,  5149,
    5152,  5154,  5157,  5159,  5162,  5164,  5165,  5166,  5173,  5174,
    5177,  5178,  5180,  5182,  5185,  5188,  5190,  5192,  5197,  5201,
    5203,  5207,  5209,  5212,  5218,  5221,  5224,  5230,  5231,  5234,
    5236,  5238,  5241,  5248,  5255,  5257,  5258,  5260,  5263,  5265,
    5268,  5269,  5272,  5274,  5276,  5278,  5280,  5282,  5284,  5286,
    5288,  5290,  5292,  5294,  5296,  5298,  5300,  5302,  5304,  5306,
    5308,  5310,  5312,  5314,  5316,  5318,  5320,  5322,  5324,  5326,
    5328,  5330,  5332,  5334,  5336,  5338,  5340,  5342,  5344,  5346,
    5348,  5350,  5352,  5354,  5356,  5358,  5360,  5362,  5364,  5366,
    5368,  5370,  5372,  5374,  5376,  5378,  5380,  5382,  5384,  5386,
    5388,  5390,  5392,  5394,  5396,  5398,  5400,  5402,  5404,  5406,
    5408,  5410,  5412,  5414,  5416,  5418,  5420,  5422,  5424,  5426,
    5428,  5430,  5432,  5434,  5436,  5438,  5440
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1025,     0,    -1,   198,    -1,   195,    -1,   123,   672,   424,
     594,   673,    -1,   137,    -1,  1091,    -1,    25,    -1,   674,
      -1,   673,     5,   674,    -1,   936,    -1,   428,   675,   389,
      -1,   675,   676,   675,    -1,    25,    -1,   677,    25,    -1,
    1091,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   679,    -1,    -1,
     272,   428,   680,   681,   389,    -1,   567,   428,    25,     5,
      25,   389,    -1,   682,    -1,   681,     5,   682,    -1,   488,
      -1,   529,    -1,   535,    -1,   504,    -1,   407,    -1,   604,
      -1,   526,    -1,   478,    -1,   414,    -1,   489,    -1,   343,
      -1,   530,    -1,   453,    -1,   330,    -1,   592,    -1,    97,
      -1,  1002,    -1,    -1,   684,    -1,    -1,   272,   428,   685,
     686,   389,    -1,   687,    -1,   686,     5,   687,    -1,   682,
      -1,   429,    -1,   602,    24,    -1,   201,   923,    -1,   327,
     923,    -1,   282,   923,    -1,   335,   923,    -1,   291,   923,
      -1,   257,   923,    -1,   532,   689,    -1,   868,   342,  1091,
      -1,    -1,   287,   428,  1478,   389,   342,   690,  1110,    -1,
     103,   428,   936,     5,    24,     5,    24,   389,    -1,   404,
     428,   928,   389,   342,  1091,    -1,  1228,    -1,   190,   428,
     887,   389,   342,  1091,    -1,    -1,    -1,  1091,   588,   936,
     428,   691,   705,   389,   692,   703,    -1,    -1,    -1,    -1,
     936,   428,   693,   705,   694,   389,   695,   703,    -1,    -1,
      -1,   472,  1425,   622,  1425,   428,   696,   705,   697,   389,
     703,    -1,    -1,    -1,   936,   519,   936,   428,   698,   705,
     699,   389,   703,    -1,    -1,    -1,    -1,   363,   708,   588,
     709,   456,   672,   424,   428,   700,   705,   701,   389,   702,
     704,    -1,    -1,   342,  1110,    -1,    -1,   342,  1110,    -1,
     161,    -1,    -1,   706,    -1,   707,    -1,   706,     5,   707,
      -1,   837,    -1,    24,    -1,   936,    -1,   936,    -1,   936,
     619,   936,    -1,    -1,   533,   844,   711,   714,   718,   715,
      -1,    -1,   533,   712,   713,   716,   715,    -1,   720,    -1,
     713,   720,    -1,   722,    -1,   714,   722,    -1,   358,    -1,
      -1,    -1,   337,   717,  1488,    -1,    -1,    -1,   337,   719,
    1488,    -1,    -1,   577,   844,   721,  1488,    -1,    -1,   577,
     844,   723,  1488,    -1,   276,   933,    -1,   200,   931,    -1,
      82,   931,    -1,   167,    -1,   183,  1431,    -1,   492,   930,
      -1,    29,   726,    30,    -1,   727,    -1,   729,    -1,   728,
      -1,   727,   728,    -1,    28,    -1,   730,    -1,   729,   730,
      -1,    27,    -1,   391,    -1,    -1,    -1,   318,   733,   735,
     734,   736,    -1,   382,  1091,   624,   737,   976,  1001,   678,
      -1,  1091,   624,   737,   976,   545,  1478,  1001,   678,    -1,
      -1,   739,   189,    -1,   738,    -1,   737,     5,   738,    -1,
     936,    -1,   936,   619,   936,    -1,   936,   619,    20,    -1,
     740,    -1,   739,   740,    -1,    -1,   268,   746,   741,  1488,
      -1,    -1,   271,   747,   742,  1488,    -1,    -1,  1004,   743,
    1488,    -1,    -1,   165,   744,  1488,    -1,    -1,   162,   745,
    1488,    -1,   940,    -1,   746,     5,   940,    -1,   940,    -1,
     747,     5,   940,    -1,    91,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,    96,    -1,   428,   837,   750,   389,
      -1,    -1,     5,   791,   625,   794,    -1,   154,    -1,   277,
      -1,    -1,   753,    -1,   754,    -1,   753,   754,    -1,    -1,
      -1,   435,   755,   757,   756,  1197,    -1,   804,    -1,  1468,
      -1,   760,    -1,   757,     5,   760,    -1,    -1,   759,   936,
      -1,   351,   758,   803,    24,    -1,   351,   758,   803,   936,
      -1,   351,   758,   803,   942,    -1,   351,   758,   803,    25,
      -1,   764,   780,    -1,    -1,   758,   351,   761,   762,    -1,
      25,    -1,    24,    -1,   942,    -1,    18,    25,    -1,   758,
      -1,   763,    -1,   764,     5,   763,    -1,    -1,   534,    -1,
      -1,   485,   456,   772,   424,   767,   623,   780,    -1,    -1,
     316,   765,   769,    25,   770,   300,   456,   771,   424,   768,
     623,   780,    -1,   428,    -1,   455,    -1,   389,    -1,   423,
      -1,    25,    -1,   773,     5,   773,     5,   773,    -1,   773,
       5,   773,    -1,   773,    -1,    25,    -1,    -1,   461,   775,
     757,   281,    -1,    -1,   258,   776,   758,   619,    20,    -1,
      -1,   332,   777,   758,   256,   428,   778,   389,    -1,   779,
      -1,   778,     5,   779,    -1,   758,    -1,   782,    -1,    -1,
      57,    -1,    -1,    -1,   783,   785,   784,   781,    -1,   766,
      -1,   774,    -1,   534,    -1,   534,   428,    25,   389,    -1,
     421,   428,    25,   389,    -1,   421,   428,    25,     5,    25,
     389,    -1,   405,    -1,   616,   758,    -1,   377,    -1,   507,
      -1,    88,    -1,   395,    -1,   395,   428,    25,   389,    -1,
     395,   428,    25,     5,    25,   389,    -1,   510,    -1,   510,
     428,    25,   389,    -1,   510,   428,    25,     5,    25,   389,
      -1,   500,    -1,   297,    -1,   536,    -1,   531,    -1,    79,
      -1,    80,    -1,   573,    -1,   355,   789,    -1,   367,   790,
      -1,   786,    -1,    31,    -1,   555,   787,   619,   788,    -1,
     758,    -1,   758,    -1,    -1,   791,   625,   794,    -1,   799,
     625,   802,    -1,    -1,   792,   793,    -1,   580,    -1,   511,
      -1,   589,    -1,   551,    -1,   451,    -1,   468,    -1,   364,
     796,    -1,    -1,   795,   793,    -1,    -1,   428,   798,   389,
      -1,    -1,   428,    25,   389,    -1,    25,    -1,    -1,   800,
     801,   797,    -1,   580,    -1,   511,    -1,   589,    -1,   551,
      -1,   451,    -1,   468,    -1,   364,   796,    -1,   801,    -1,
      -1,    13,    -1,    -1,   234,   936,   805,   616,   806,    -1,
     808,    -1,   811,    -1,   534,    -1,   534,   428,    25,   389,
      -1,   421,   428,    25,   389,    -1,   421,   428,    25,     5,
      25,   389,    -1,   405,    -1,   377,    -1,   507,    -1,   395,
      -1,   395,   428,    25,   389,    -1,   395,   428,    25,     5,
      25,   389,    -1,   510,    -1,   510,   428,    25,   389,    -1,
     510,   428,    25,     5,    25,   389,    -1,   500,    -1,   297,
      -1,   536,    -1,   531,    -1,   573,    -1,   355,   789,    -1,
     367,   790,    -1,   807,    -1,   555,   787,   619,   788,    -1,
      -1,   485,   456,   772,   424,   809,   623,   806,    -1,    -1,
     316,   765,   769,    25,   770,   300,   456,   771,   424,   810,
     623,   806,    -1,    -1,   461,   812,   814,   281,    -1,    -1,
     258,   813,   936,   619,    20,    -1,   815,    -1,   814,     5,
     815,    -1,   816,   806,    -1,   817,    -1,   816,     5,   817,
      -1,   936,    -1,    -1,   617,   927,    -1,    69,   936,    -1,
      67,    -1,   625,  1478,    -1,   625,   507,   936,   658,  1478,
      -1,   625,   507,   936,   387,    -1,    71,   936,    -1,   155,
     862,  1110,   826,    -1,   398,   862,   842,   818,   826,    -1,
     207,   933,   826,    -1,    -1,    -1,   186,   823,  1117,   625,
     936,   619,    20,   825,   678,   824,   827,    -1,    -1,   466,
     928,    -1,   678,    -1,    -1,   828,   236,    -1,   829,    -1,
     828,   829,    -1,    -1,   349,   830,  1488,    -1,    -1,   345,
     831,  1488,    -1,    -1,  1004,   832,  1488,    -1,   496,   862,
     843,   678,    -1,   496,   862,   843,   678,    64,    -1,   284,
      -1,   283,    -1,   210,    -1,   362,    -1,   172,    -1,   209,
      -1,   326,    -1,   325,    -1,   241,    -1,   169,    -1,   168,
      -1,   143,    -1,   202,    -1,   126,    -1,   142,    -1,   185,
      -1,   152,    -1,   211,    -1,   211,   844,    -1,   847,    -1,
     846,    -1,   851,    -1,   879,    -1,   837,   838,    -1,   880,
      -1,   882,    -1,   848,    -1,    18,   837,    -1,    17,   837,
      -1,   853,    -1,   861,    -1,   855,    -1,   473,    -1,   748,
      -1,   856,    -1,   857,    -1,   858,    -1,   859,    -1,   860,
      -1,    34,   837,    -1,   862,    -1,   862,   841,    -1,   844,
      -1,   481,    -1,   840,    -1,   841,     5,   840,    -1,   844,
      -1,   842,     5,   844,    -1,   844,    -1,   843,     5,   844,
      -1,   837,    -1,    17,    -1,    18,    -1,   601,   837,    -1,
     482,    -1,   425,    -1,   428,   837,   389,    -1,   440,   428,
    1405,   389,    -1,   292,   428,  1405,   389,    -1,   845,   942,
      -1,   845,    25,    -1,    24,    -1,   942,    -1,    25,    -1,
     850,    -1,  1091,    -1,  1091,   418,  1091,    -1,   849,    -1,
     431,   837,    -1,   390,   837,    -1,  1200,    -1,    -1,   505,
     852,  1200,    -1,     7,   837,    -1,     6,   837,    -1,   837,
      -1,   854,     5,   837,    -1,   622,   428,  1405,   389,    -1,
     426,   428,  1405,   389,    -1,   622,   428,   862,   854,   389,
      -1,   426,   428,   862,   854,   389,    -1,   384,    -1,   247,
      -1,     9,   837,    -1,   250,   837,    -1,     9,   837,   439,
      24,    -1,   250,   837,   439,    24,    -1,   555,   837,    -1,
     369,   837,    -1,   555,   837,   439,    24,    -1,   369,   837,
     439,    24,    -1,   388,    -1,     8,   837,    -1,    17,   837,
      -1,    18,   837,    -1,    20,   837,    -1,    19,   837,    -1,
      21,   837,    -1,    10,   837,    -1,    13,   837,    -1,   454,
     837,    -1,    11,   837,    -1,    12,   837,    -1,    16,   837,
      -1,    15,   837,    -1,    14,   837,    -1,    -1,    -1,    -1,
     936,   428,   864,   705,   865,   389,    -1,    -1,    -1,   936,
     519,   936,   428,   866,   705,   867,   389,    -1,    -1,    -1,
     536,   428,   869,   837,   870,   389,    -1,    -1,    -1,   511,
     428,   871,   837,   872,   389,    -1,    -1,    -1,   589,   428,
     873,   837,   874,   389,    -1,    -1,    -1,   580,   428,   875,
     837,   876,   389,    -1,   367,   428,   883,   389,   878,    -1,
     355,   428,    24,   389,   877,    -1,   355,   428,    25,   389,
     877,    -1,   355,   428,    25,   588,    25,   389,   877,    -1,
      -1,  1385,   625,  1386,    -1,   790,    -1,   868,    -1,   287,
     428,  1478,   389,    -1,    98,   428,   928,   389,    -1,    70,
     428,   928,   389,    -1,   404,   428,   928,   389,    -1,   190,
     428,   887,   389,    -1,    58,   428,   887,   389,    -1,   881,
      -1,   863,    -1,  1381,    -1,   536,    -1,   420,   428,   837,
     389,    -1,   320,   428,   837,   389,    -1,   486,   837,    -1,
     441,   749,    -1,   837,   107,    -1,   837,   108,    -1,   837,
     109,    -1,    24,    -1,   884,    -1,    18,   884,    -1,   886,
      -1,   885,    -1,    25,    -1,    25,    25,    -1,    25,    25,
     588,    25,    -1,    25,    25,   588,    25,   588,    25,    -1,
      25,    25,   588,    25,   588,    23,    -1,    25,   588,    25,
      -1,    25,   588,    25,   588,    25,    -1,    25,   588,    25,
     588,    23,    -1,    25,   588,    23,    -1,    23,    -1,    25,
      -1,    25,    18,    25,    -1,   928,    -1,   887,     5,   928,
      -1,    -1,    -1,   594,  1091,    13,   844,   625,   844,   891,
     889,  1488,   890,   239,    -1,    -1,   570,   844,    -1,    -1,
      -1,    -1,   401,   893,   930,   894,  1286,   895,  1488,   238,
      -1,    -1,    -1,   637,   936,   897,   752,   898,  1035,   900,
     899,   905,   638,    -1,    -1,   910,    -1,    -1,   901,    -1,
     902,    -1,   901,   902,    -1,    -1,   639,   903,  1488,    -1,
      -1,   640,   904,  1488,    -1,    -1,   906,    -1,   907,    -1,
     906,   907,    -1,    -1,   641,   908,  1488,    -1,    -1,   642,
     909,  1488,    -1,   911,   915,   322,    -1,    90,    -1,    90,
     912,   545,   913,    -1,    90,   382,   914,    -1,  1091,    -1,
     912,     5,  1091,    -1,   936,    -1,   913,     5,   936,    -1,
    1091,    -1,   914,     5,  1091,    -1,   916,    -1,   915,   916,
      -1,    -1,   643,   917,  1488,    -1,    -1,   644,   918,  1488,
      -1,    -1,   663,   913,   919,  1488,    -1,    -1,   479,   913,
     920,  1488,    -1,    -1,   624,   913,   921,  1488,    -1,   544,
     929,    -1,   553,    18,    25,    -1,   553,    -1,   499,    17,
      25,    -1,   499,    -1,    25,    -1,  1091,    -1,    24,    -1,
     941,    -1,   844,    -1,   925,     5,   925,    -1,   926,    -1,
     936,    -1,   666,   428,   936,   389,    -1,   936,   619,   666,
     428,   936,   389,    -1,   936,   456,   675,   424,    -1,   936,
     619,    20,    -1,   936,   456,   675,   424,   619,    20,    -1,
     936,   619,   936,    -1,   936,   456,   675,   424,   619,   936,
      -1,   937,    -1,   937,    -1,   937,    -1,   937,    -1,   937,
      -1,   937,    -1,    -1,   549,    25,    -1,  1487,    -1,   938,
      -1,  1487,    -1,   347,   428,   939,   389,    -1,  1094,    -1,
      24,    -1,   936,    -1,   936,   456,   675,   424,    -1,   936,
     619,    20,    -1,   936,   456,   675,   424,   619,    20,    -1,
     936,   619,   936,    -1,   936,   456,   675,   424,   619,   936,
      -1,  1091,    -1,    23,    -1,   619,    25,    -1,   546,  1470,
      -1,   651,   945,    -1,   946,    -1,   945,     5,   946,    -1,
     936,    -1,   662,   945,    -1,   653,   945,    -1,   654,  1478,
      -1,   652,   933,   658,  1478,    -1,   656,   945,    -1,   657,
    1478,    -1,   655,   933,   658,  1478,    -1,    -1,   660,   951,
     842,   956,   958,   960,   952,   954,    -1,    -1,   953,    -1,
     648,    -1,   649,    -1,    -1,   955,    -1,   342,  1091,    -1,
      -1,   957,    -1,   387,   842,    -1,    -1,   959,    -1,   659,
      25,    -1,    -1,   961,    -1,   650,    25,   962,    -1,    -1,
     397,    25,    -1,    -1,   621,   844,   574,   964,  1488,   965,
     438,    -1,    -1,    -1,   541,   966,  1488,    -1,    -1,    -1,
      61,   967,   844,   574,   968,  1488,   965,    -1,   105,   936,
     428,    25,   389,    -1,    54,   936,    -1,    74,   936,    -1,
      -1,   288,  1122,   972,   625,   481,    -1,   288,  1122,   555,
     973,    -1,   974,    -1,   973,     5,   974,    -1,   787,   619,
    1377,    -1,   787,   619,    20,    -1,    -1,   977,   322,    -1,
      -1,   149,    -1,   978,    -1,   977,   978,    -1,    -1,   268,
     990,   979,  1488,    -1,    -1,   271,   991,   980,  1488,    -1,
      -1,   349,   981,  1488,    -1,    -1,   345,   982,  1488,    -1,
      -1,  1004,   983,  1488,    -1,    -1,   303,   984,  1488,    -1,
      -1,   273,   985,  1488,    -1,    -1,    35,   986,  1488,    -1,
      -1,    33,   987,  1488,    -1,    -1,    37,   988,  1488,    -1,
      -1,    36,   989,  1488,    -1,   928,    -1,   990,     5,   928,
      -1,   928,    -1,   991,     5,   928,    -1,   312,   994,    -1,
     313,   936,   658,   994,    -1,   560,    -1,   372,    -1,   928,
      -1,    -1,   664,   997,   996,   975,    -1,   382,  1110,   976,
     935,   678,    -1,  1110,   976,   545,  1478,   935,   678,    -1,
      -1,   485,  1117,   976,   545,   936,   619,    20,   935,   998,
     678,    -1,   467,  1478,  1000,    -1,   626,    -1,   538,    -1,
      75,    25,    -1,    81,    25,    -1,    -1,   549,    25,    -1,
    1003,    -1,    42,    24,    -1,   494,    13,    25,    -1,   494,
      13,  1091,    -1,    43,    13,    25,    -1,    43,    13,  1091,
      -1,    39,    -1,    41,    -1,    38,    -1,    40,    -1,    -1,
     427,  1005,  1011,    -1,   293,    -1,    -1,   595,  1007,  1011,
      -1,   301,  1013,    -1,    -1,   595,  1010,  1011,    -1,  1013,
      -1,   428,  1012,   389,    -1,  1013,    -1,  1012,     5,  1013,
      -1,    -1,  1014,  1015,    -1,   593,    -1,   310,    -1,   328,
      -1,   302,    -1,   483,    -1,   439,    -1,   626,    -1,   549,
      -1,   538,    -1,   463,    -1,   436,    -1,   539,    -1,   554,
      -1,   518,    -1,   308,    -1,   309,    -1,    24,    -1,   508,
      -1,    -1,    -1,   597,  1018,  1115,  1019,    13,   862,  1020,
      -1,   481,    -1,   843,    -1,   217,  1091,    -1,   206,  1091,
      -1,   220,  1091,    -1,   448,  1091,   331,    -1,   448,  1091,
     383,   924,    -1,    -1,  1027,  1026,  1030,    -1,    -1,  1028,
      -1,  1029,    -1,  1028,  1029,    -1,   970,    -1,  1034,    -1,
    1050,    -1,  1036,    -1,    -1,  1031,    -1,  1033,    -1,  1031,
    1033,    -1,    65,   936,    -1,  1038,    -1,  1044,    -1,  1056,
      -1,  1210,    -1,  1220,    -1,  1077,    -1,  1468,    -1,   896,
      -1,   725,    -1,   969,    -1,   731,    -1,   725,    -1,  1468,
      -1,    -1,   725,    -1,  1468,    -1,   753,    -1,   365,    -1,
      59,    -1,    -1,    -1,    -1,    -1,  1037,  1039,   936,   428,
    1040,  1108,   389,  1041,   752,  1042,  1035,  1488,  1043,    -1,
     208,    -1,    -1,    -1,   556,  1045,   752,  1046,  1488,   359,
      -1,   463,   839,    -1,   862,    -1,   862,   842,    -1,   354,
    1389,    -1,  1051,    -1,  1052,    -1,  1051,  1052,    -1,  1053,
      -1,  1034,    -1,  1049,    -1,    -1,   403,  1054,  1055,    -1,
     752,   240,    -1,   924,    -1,    -1,    -1,    -1,   112,   936,
     111,   936,   428,  1057,  1108,   389,  1058,   752,  1059,  1035,
    1488,  1043,    -1,    -1,   557,  1061,  1076,  1067,  1062,    -1,
     360,    -1,    -1,   232,  1064,  1488,    -1,    -1,    22,  1068,
    1069,  1070,   935,  1065,  1488,    -1,    -1,    22,  1068,   935,
    1066,  1488,    -1,  1063,    -1,  1067,  1063,    -1,    -1,  1006,
      -1,    24,    -1,  1091,    -1,    -1,  1091,    -1,    24,    -1,
     249,  1074,    -1,   261,  1075,    -1,   244,  1075,    -1,   584,
      -1,    24,    -1,  1091,    -1,  1074,    -1,  1075,     5,  1074,
      -1,  1091,    -1,    24,    -1,    -1,    -1,   645,   936,  1078,
     752,  1079,  1080,   646,    -1,  1081,    -1,  1080,  1081,    -1,
      -1,   647,  1082,  1488,    -1,    -1,   624,   936,  1083,  1488,
      -1,  1087,  1085,    -1,    -1,   679,  1089,    -1,  1090,    -1,
    1086,    -1,   957,    -1,   959,    -1,   961,    -1,   953,    -1,
     955,    -1,    -1,   368,  1088,   843,    -1,    -1,    64,    -1,
      64,    -1,  1092,    -1,  1094,    -1,   188,  1094,    -1,  1094,
     619,    -1,  1093,  1098,    -1,  1093,   936,   456,  1102,   424,
      -1,  1093,   936,   456,  1102,   424,   456,  1102,   424,    -1,
    1099,    -1,   936,    -1,  1095,    -1,   936,   455,  1097,   423,
      -1,   936,   455,  1097,   423,    -1,  1091,    -1,    24,    -1,
      20,    -1,   936,    -1,   936,  1101,    -1,   936,  1101,    -1,
     456,  1102,   424,    -1,   456,  1102,   424,   456,  1102,   424,
      -1,  1103,    -1,  1102,     5,  1103,    -1,   675,    -1,  1105,
      -1,  1107,    -1,  1105,   619,  1106,    -1,  1105,   619,   936,
     456,  1102,   424,    -1,  1105,   619,   936,   456,  1102,   424,
     456,  1102,   424,    -1,   936,    -1,  1096,    -1,    20,    -1,
     936,    -1,   936,  1101,    -1,    -1,  1109,    -1,  1111,    -1,
    1109,     5,  1111,    -1,  1112,    -1,  1110,     5,  1112,    -1,
     936,    -1,   936,   619,   936,    -1,  1091,    -1,  1091,   418,
    1091,    -1,    24,    -1,   942,    -1,    25,    -1,  1114,    -1,
    1113,     5,  1114,    -1,  1091,    -1,  1091,   418,  1091,    -1,
    1116,    -1,  1115,     5,  1116,    -1,  1104,    -1,  1091,    -1,
    1119,    -1,  1118,     5,  1119,    -1,  1091,  1120,    -1,    -1,
     586,    -1,   537,    -1,   936,   456,  1102,   424,    -1,  1123,
      -1,  1122,     5,  1123,    -1,  1091,    -1,  1091,   418,  1091,
      -1,   252,   932,   617,   926,   578,  1480,   683,    -1,    -1,
     617,   428,   844,     5,   844,   389,  1126,    -1,    -1,   567,
     428,   844,     5,   844,   389,    -1,   253,   936,  1125,    -1,
     936,    -1,   336,   934,  1130,    -1,  1131,    -1,   545,   844,
      -1,  1132,  1133,  1138,     8,  1128,    -1,    -1,   617,  1134,
     428,   844,     5,   844,   389,    -1,    -1,   555,   937,    -1,
      -1,   348,    -1,   215,  1431,   264,  1463,  1137,    -1,   562,
     929,    -1,   562,   929,     8,   862,   842,    -1,    -1,   616,
     575,  1425,   371,  1425,    -1,   616,   575,  1425,     5,   371,
    1425,    -1,   616,  1425,     5,  1425,    -1,    -1,   648,    -1,
     649,    -1,    89,  1463,  1140,  1141,    -1,    -1,   616,  1463,
      -1,    -1,   616,   575,  1425,     8,  1425,    -1,   575,  1425,
       8,  1425,    -1,   409,  1143,    -1,  1144,    -1,  1143,     5,
    1144,    -1,   201,   923,    -1,   282,   923,    -1,   327,   923,
      -1,   335,   923,    -1,   291,   923,    -1,   257,   923,    -1,
    1008,    -1,   436,  1009,    -1,   447,  1009,    -1,   560,  1009,
      -1,   372,  1009,    -1,   549,  1009,    -1,   547,   924,    -1,
     548,   924,    -1,   398,   679,    -1,   664,   679,    -1,   289,
      -1,   193,    -1,   150,    -1,   127,    -1,   145,    -1,   136,
      -1,  1430,   411,  1148,   545,  1146,    -1,  1091,    -1,    24,
      -1,   400,  1148,    -1,   400,  1148,     8,  1110,    -1,   937,
      -1,    -1,   459,  1157,   678,   594,  1152,  1091,   935,   678,
    1150,  1153,    -1,   459,  1157,   678,   342,  1091,    -1,    -1,
     534,    -1,    -1,  1154,   280,    -1,  1155,    -1,  1154,  1155,
      -1,    -1,  1004,  1156,  1488,    -1,   843,    -1,    -1,   603,
     929,  1159,  1160,    -1,    -1,   545,  1161,    -1,  1162,    -1,
    1161,     5,  1162,    -1,  1417,    -1,   481,    -1,   218,  1165,
      87,    -1,   218,  1165,   625,  1164,    -1,   218,  1165,    86,
    1164,    -1,   218,  1165,    -1,    24,    -1,   941,    -1,   936,
      -1,    -1,   477,    -1,   144,  1165,  1166,   428,   862,  1048,
     389,    -1,   191,  1165,    -1,    66,  1165,    -1,  1201,  1209,
      -1,   444,    60,    -1,   444,  1172,    -1,  1173,    -1,  1172,
    1173,    -1,    -1,   132,  1174,  1488,    -1,    -1,   197,  1175,
    1488,    -1,    -1,   226,  1176,  1488,    -1,    -1,   214,  1177,
    1488,    -1,    -1,   251,  1178,  1488,    -1,    -1,   199,  1091,
    1179,  1488,    -1,    -1,   222,  1091,  1180,  1488,    -1,  1191,
      -1,  1193,    -1,  1192,    -1,  1182,    -1,  1218,    -1,  1185,
      -1,    -1,   559,   844,  1183,   480,    -1,    -1,   480,    -1,
      -1,   568,   844,  1186,  1184,    -1,   157,    -1,   628,  1205,
      -1,   160,  1205,    -1,   159,  1205,    -1,    -1,  1188,    -1,
    1189,    -1,  1188,  1189,    -1,  1198,  1190,    -1,    -1,   617,
    1205,    -1,   517,  1187,  1197,    -1,   516,  1425,  1197,    -1,
     515,  1196,  1195,  1194,  1197,    -1,    -1,   151,   837,    -1,
     151,   837,     5,   837,    -1,   612,    -1,   613,    -1,   614,
      -1,   615,    -1,  1091,    -1,    -1,   520,    -1,  1199,    -1,
    1198,     5,  1199,    -1,   844,  1232,    -1,   608,   428,   837,
     389,  1217,    -1,    63,  1217,    -1,   494,   428,    20,   389,
    1217,    -1,   410,   428,    20,   389,  1217,    -1,   385,   428,
     837,   389,  1217,    -1,   587,   428,   837,   389,  1217,    -1,
     600,   428,   837,   389,  1217,    -1,   599,   428,   837,   389,
    1217,    -1,    -1,   458,  1202,    -1,  1203,    -1,  1202,  1203,
      -1,   225,    25,    -1,   216,    25,    -1,   299,    25,    -1,
     182,    25,    -1,   254,    25,    -1,   174,    -1,   341,    24,
      -1,   341,  1091,    -1,   175,    24,    -1,   158,    24,    -1,
    1208,    -1,  1204,  1208,    -1,  1206,   107,    -1,  1206,   109,
      -1,  1206,   108,    -1,  1206,    -1,   942,    -1,    25,    -1,
      -1,   458,  1204,    -1,   225,  1205,    -1,   216,  1205,    -1,
     299,  1205,    -1,   182,  1205,    -1,   254,  1205,    -1,   255,
    1205,    -1,   627,    24,    -1,   628,  1205,    -1,   632,    -1,
     629,    -1,   630,    -1,   631,    -1,   636,    -1,   633,    -1,
     634,    -1,   635,    -1,    76,  1205,    -1,    77,  1205,    -1,
      78,  1205,    -1,   341,    24,    -1,   175,    24,    -1,   397,
      -1,    72,    -1,    73,    -1,    -1,   512,   618,  1118,    -1,
     133,  1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,
    1211,   936,   428,  1212,  1108,   389,  1213,   752,  1214,  1170,
    1215,  1171,  1216,   237,    -1,    -1,   524,   837,    -1,   514,
    1219,    -1,    -1,  1146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,  1221,   936,   428,  1222,  1108,   389,  1223,   752,
    1224,  1227,  1225,  1171,  1226,   237,    -1,  1207,  1209,    -1,
      -1,    -1,    -1,   153,   428,    24,     5,  1229,   705,  1230,
     389,  1231,   703,    -1,    -1,   381,    -1,   381,   216,    25,
      -1,   381,   216,  1091,    -1,   606,   844,    -1,   606,   844,
     342,  1091,    -1,   606,   844,   161,    -1,   606,   844,   576,
      -1,   606,   844,   543,    -1,  1235,    -1,   171,    -1,   321,
      -1,   279,    -1,  1242,    -1,  1237,    -1,    -1,    -1,   204,
    1238,  1374,   428,  1239,  1246,   389,    -1,    -1,    -1,   130,
    1240,  1374,   428,  1241,  1246,   389,  1243,    -1,   102,  1244,
     389,    -1,    53,   937,    -1,    -1,   266,    -1,  1245,    -1,
    1244,     5,  1245,    -1,   936,   586,    -1,   936,   537,    -1,
     936,    -1,  1247,    -1,  1246,     5,  1247,    -1,  1327,    -1,
    1325,    -1,   119,   936,    -1,   177,    -1,    44,   936,  1250,
      -1,  1251,    -1,  1250,     5,  1251,    -1,  1252,    -1,  1255,
      -1,  1258,    -1,  1263,    -1,  1264,    -1,  1262,    -1,  1261,
      -1,   583,  1253,    -1,   583,   428,  1254,   389,    -1,  1247,
      -1,  1247,   663,   936,    -1,  1253,    -1,  1254,     5,  1253,
      -1,   540,  1257,    -1,   540,   428,  1256,   389,    -1,  1257,
      -1,  1256,     5,  1257,    -1,   936,    -1,   452,  1260,    -1,
     452,   428,  1259,   389,    -1,  1260,    -1,  1259,     5,  1260,
      -1,  1247,    -1,    84,    -1,    85,    -1,    83,    25,    -1,
      55,  1331,    -1,    55,   428,  1265,   389,    -1,    56,  1266,
      -1,    56,   428,  1265,   389,    -1,  1331,    -1,  1265,     5,
    1331,    -1,   936,    -1,   263,    -1,   229,    -1,   163,  1269,
      -1,   140,    -1,   128,    -1,   118,    -1,   116,    -1,   120,
      -1,   176,  1431,    -1,   228,  1268,   457,  1425,   625,  1425,
      -1,   296,   929,   457,  1425,   625,  1425,    -1,    -1,  1431,
      -1,    -1,   844,    -1,   521,   844,    -1,   227,    -1,    -1,
     246,  1273,  1374,  1276,  1274,    -1,    -1,   477,  1275,   428,
    1278,   389,    -1,  1411,    -1,    -1,   428,  1277,   389,    -1,
    1377,    -1,  1277,     5,  1377,    -1,  1279,    -1,  1278,     5,
    1279,    -1,  1417,    -1,   481,    -1,    -1,    -1,   498,  1281,
    1283,  1282,  1284,    -1,  1288,   930,    -1,   930,    -1,    -1,
      -1,   552,  1285,  1113,    -1,    -1,    -1,   552,  1287,  1113,
      -1,   499,    -1,   553,    -1,   560,    -1,   372,    -1,   339,
      -1,   393,    -1,   375,   844,    -1,   348,   844,    -1,   235,
    1374,   148,   930,    -1,   235,  1374,  1347,    -1,   512,   618,
    1292,    -1,  1293,    -1,  1292,     5,  1293,    -1,  1294,  1295,
      -1,    25,    -1,  1377,    -1,    -1,   586,    -1,   537,    -1,
     274,    -1,   307,    -1,    -1,   324,    -1,   354,  1300,  1298,
      -1,  1463,    -1,    24,    -1,    -1,  1430,  1302,  1303,    -1,
    1332,    -1,  1336,    -1,  1297,    -1,  1432,    -1,  1296,    -1,
    1289,    -1,  1290,    -1,  1280,    -1,  1272,    -1,  1271,    -1,
    1401,    -1,  1447,    -1,   503,  1306,   624,  1374,   625,  1311,
    1305,    -1,    -1,   139,    -1,   166,    -1,  1307,    -1,  1308,
      -1,  1307,     5,  1308,    -1,   469,    -1,   447,    -1,   436,
      -1,   476,  1309,    -1,    -1,   428,  1310,   389,    -1,  1377,
      -1,  1310,     5,  1377,    -1,  1312,    -1,  1311,     5,  1312,
      -1,   460,    -1,  1375,    -1,   233,  1374,  1314,   616,  1411,
    1316,    -1,    -1,   428,  1315,   389,    -1,  1377,    -1,  1315,
       5,  1377,    -1,    -1,   138,    -1,   490,   428,  1350,   389,
      -1,   243,   428,  1320,   389,  1319,    -1,   294,  1321,    -1,
    1322,    -1,  1374,    -1,  1374,   428,  1322,   389,    -1,  1377,
      -1,  1322,     5,  1377,    -1,   474,   428,  1324,   389,    -1,
     256,   428,  1324,   389,    -1,  1377,    -1,  1324,     5,  1377,
      -1,  1323,    -1,  1318,    -1,  1317,    -1,   397,  1380,    -1,
     205,    -1,   936,  1366,  1328,  1329,    -1,    -1,  1326,    -1,
      -1,  1330,    -1,  1331,    -1,  1330,  1331,    -1,   370,    -1,
     156,    -1,   474,    -1,  1319,    -1,   490,   428,  1350,   389,
      -1,   117,  1333,  1335,    -1,  1334,    -1,  1375,    -1,  1336,
      -1,  1335,  1336,    -1,  1313,    -1,  1304,    -1,   445,  1350,
      -1,   366,  1339,    -1,  1416,    -1,  1339,     5,  1416,    -1,
     524,  1350,    -1,   545,  1342,    -1,  1343,    -1,  1342,     5,
    1343,    -1,  1344,    -1,   513,  1344,    -1,   513,   428,  1345,
     389,    -1,  1374,    -1,  1374,  1379,    -1,  1343,    -1,  1345,
       5,  1343,    -1,  1341,  1347,  1348,  1349,    -1,    -1,  1340,
      -1,    -1,  1338,    -1,    -1,  1337,    -1,  1351,    -1,  1350,
       6,  1351,    -1,  1352,    -1,  1351,     7,  1352,    -1,  1353,
      -1,   601,  1353,    -1,  1364,    -1,   428,  1350,   389,    -1,
     440,  1412,    -1,   292,  1412,    -1,    -1,   439,  1357,    -1,
    1421,    -1,   936,    -1,  1421,    -1,  1417,   622,   428,  1359,
     389,    -1,  1417,   622,  1412,    -1,  1417,   426,   428,  1359,
     389,    -1,  1417,   426,  1412,    -1,  1360,    -1,  1359,     5,
    1360,    -1,  1467,    -1,  1380,    -1,    -1,   601,    -1,  1417,
    1361,   384,    -1,  1417,  1361,   247,    -1,  1417,  1363,  1417,
      -1,  1417,  1361,   386,  1417,     7,  1417,    -1,  1417,   555,
    1356,  1355,    -1,  1417,   369,  1356,  1355,    -1,  1417,  1361,
       9,  1356,  1355,    -1,    13,    -1,    16,    -1,    11,    -1,
      12,    -1,   250,    -1,     9,    -1,    15,    -1,    14,    -1,
    1362,    -1,  1358,    -1,  1354,    -1,    -1,   584,    -1,   357,
      -1,   474,    -1,  1367,    -1,  1368,    -1,  1370,    -1,   534,
      -1,   534,   428,  1371,   389,    -1,   408,   428,  1372,  1369,
     389,    -1,   470,    -1,   395,   428,  1372,  1369,   389,    -1,
     510,   428,  1372,  1369,   389,    -1,   536,    -1,   405,    -1,
     377,    -1,   355,  1387,   625,  1388,    -1,   355,    -1,   367,
    1387,   625,  1388,    -1,   367,    -1,   367,  1387,   428,    25,
     389,   625,  1388,    -1,   573,    -1,   531,    -1,   421,    -1,
     421,   428,    25,   389,    -1,   421,   428,    25,     5,    25,
     389,    -1,    -1,     5,  1373,    -1,   500,   428,  1372,   389,
      -1,   564,    -1,   297,    -1,   500,    -1,    62,    -1,    25,
      -1,    25,    -1,    25,    -1,    24,   619,   936,    -1,    24,
      -1,   936,    -1,   936,   588,   936,    -1,   936,    -1,    -1,
     456,    25,   424,    -1,   456,    25,     5,    25,   424,    -1,
    1378,    -1,   611,  1378,    -1,   936,  1376,    -1,  1374,   619,
     936,  1376,    -1,  1374,   619,    20,    -1,   936,    -1,    24,
      -1,   408,    -1,   942,    -1,    25,    -1,  1382,    -1,   393,
    1384,    -1,   393,  1383,    -1,    -1,  1387,   625,  1388,    -1,
      -1,  1385,   625,  1385,    -1,   580,    -1,   511,    -1,   589,
      -1,   551,    -1,   451,    -1,   468,    -1,   364,    -1,   364,
     428,    25,   389,    -1,   580,    -1,   511,    -1,   589,    -1,
     551,    -1,   451,    -1,   468,    -1,   364,    -1,   364,   428,
      25,   389,    -1,   580,    -1,   511,    -1,   589,    -1,   551,
      -1,   451,    -1,   468,    -1,   364,    -1,   580,    -1,   511,
      -1,   589,    -1,   551,    -1,   451,    -1,   468,    -1,   364,
      -1,   936,    -1,    24,    -1,  1430,   501,   930,    -1,    -1,
    1430,   396,   930,   434,   594,  1399,  1392,  1396,    -1,    -1,
    1430,   396,   930,   434,    99,   594,  1400,  1393,  1396,    -1,
      -1,  1430,   396,   930,   134,  1400,  1394,  1396,    -1,    -1,
    1430,   396,   930,   135,    99,   594,  1400,  1395,  1396,    -1,
      -1,   286,    -1,   285,  1397,    -1,  1398,    -1,  1397,     5,
    1398,    -1,   936,    -1,   936,   619,   936,    -1,    24,   619,
     936,   619,   936,    -1,  1400,    -1,  1272,    -1,  1148,    -1,
    1402,    -1,  1402,  1396,    -1,    -1,    -1,   469,  1413,  1403,
    1414,  1404,  1410,  1346,  1408,    -1,   469,  1413,  1414,  1346,
    1408,    -1,  1407,    -1,  1425,    -1,   469,  1413,  1414,  1410,
    1346,  1408,    -1,    -1,   523,  1365,  1406,    -1,  1291,    -1,
     329,  1409,  1243,    -1,  1291,   329,  1409,  1243,    -1,   936,
      -1,    -1,   552,  1113,    -1,   469,  1413,  1414,  1346,    -1,
     428,   469,  1413,  1414,  1346,   389,    -1,    -1,   584,    -1,
     357,    -1,   474,    -1,  1415,    -1,  1414,     5,  1415,    -1,
    1417,    -1,  1417,   936,    -1,  1417,    -1,  1418,    -1,    18,
    1418,    -1,    17,  1418,    -1,  1419,    -1,  1467,    -1,  1412,
      -1,   611,   936,    -1,   611,   936,   619,   936,    -1,  1418,
      19,  1417,    -1,  1418,  1439,    -1,  1418,    20,  1417,    -1,
    1418,    17,  1417,    -1,  1418,    18,  1417,    -1,  1380,    -1,
     482,    -1,   425,    -1,   575,    -1,    20,    -1,    63,    -1,
     587,   428,  1365,  1417,   389,    -1,   599,   428,  1365,  1417,
     389,    -1,   600,   428,  1365,  1417,   389,    -1,   608,   428,
    1365,  1417,   389,    -1,   494,   428,  1365,  1417,   389,    -1,
     936,   428,  1420,   389,    -1,   536,   428,  1420,   389,    -1,
     428,  1417,   389,    -1,   441,   428,  1440,   389,    -1,  1417,
      -1,  1420,     5,  1417,    -1,    -1,  1380,    -1,  1430,   344,
    1429,  1424,  1406,    -1,  1430,   333,  1429,  1424,   246,  1374,
    1426,    -1,  1430,   333,  1429,  1424,  1091,    -1,    -1,   319,
    1425,    -1,    24,    -1,  1091,    -1,    -1,   428,  1427,   389,
      -1,  1428,    -1,  1427,     5,  1428,    -1,   936,    -1,    24,
      -1,  1091,    -1,    -1,   265,  1431,   594,    -1,   937,    -1,
    1437,    -1,  1436,    -1,  1433,    -1,   314,  1434,   625,  1434,
      -1,   295,  1434,   619,  1435,   625,  1435,    -1,   936,    -1,
     936,    -1,   219,   787,    -1,   290,   787,  1438,    -1,   269,
      -1,   173,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,   393,     5,  1387,   625,  1388,
      -1,  1377,     5,  1387,   625,  1388,    -1,   393,  1387,   625,
    1388,    -1,    -1,   607,  1442,  1443,   187,    -1,  1444,    -1,
    1443,  1444,    -1,    32,    -1,  1445,    -1,  1446,    -1,   188,
    1467,    -1,   552,  1113,    -1,    -1,    -1,   476,  1374,  1448,
    1451,  1449,  1450,    -1,    -1,   148,   930,    -1,   524,  1350,
      -1,    51,  1455,   389,    13,   428,  1456,   389,    -1,    47,
    1456,   389,    -1,    48,  1456,   389,    -1,   582,  1452,    -1,
      50,  1456,    -1,    49,  1456,    -1,  1454,    -1,  1452,     5,
    1454,    -1,  1377,    -1,  1453,    13,  1457,    -1,  1453,    -1,
    1455,     5,  1453,    -1,  1457,    -1,  1456,     5,  1457,    -1,
     481,    -1,  1458,    -1,  1459,    -1,    18,  1459,    -1,    17,
    1459,    -1,  1461,    -1,  1412,    -1,   611,   936,    -1,   611,
     936,   619,   936,    -1,  1460,    -1,  1380,    -1,   482,    -1,
     425,    -1,   575,    -1,    63,    -1,  1459,    19,  1458,    -1,
    1459,  1439,    -1,  1459,    20,  1458,    -1,  1459,    17,  1458,
      -1,  1459,    18,  1458,    -1,   587,   428,  1365,  1458,   389,
      -1,   599,   428,  1365,  1458,   389,    -1,   600,   428,  1365,
    1458,   389,    -1,   608,   428,  1365,  1458,   389,    -1,   494,
     428,  1365,  1458,   389,    -1,   936,   428,  1462,   389,    -1,
     536,   428,  1462,   389,    -1,   428,  1458,   389,    -1,   441,
     428,  1440,   389,    -1,  1467,    -1,  1458,    -1,  1462,     5,
    1458,    -1,  1464,    -1,   188,  1465,    -1,  1465,    -1,  1100,
      -1,   936,    -1,  1465,   619,  1466,    -1,    24,   619,  1465,
     619,  1466,    -1,    20,    -1,  1121,    -1,   936,    -1,  1464,
      -1,  1464,   418,  1464,    -1,   125,  1469,    -1,   129,  1469,
      -1,   124,  1469,    -1,    45,    -1,   164,  1469,    -1,   122,
    1469,    -1,    46,    -1,   147,  1469,    -1,   146,  1469,    -1,
     121,  1469,    -1,   353,    -1,   620,   625,  1470,    -1,   546,
    1470,    -1,   571,    -1,   532,  1471,    -1,   936,    -1,   588,
     936,    -1,   936,    -1,    -1,    -1,   525,  1473,   844,  1474,
    1488,   323,    -1,    -1,   658,  1478,    -1,    -1,   661,    -1,
     179,    -1,   275,   931,    -1,    68,   931,    -1,   305,    -1,
     304,    -1,   306,   933,  1475,  1476,    -1,   491,  1478,  1476,
      -1,   928,    -1,  1478,     5,   928,    -1,   101,    -1,   131,
     931,    -1,   844,   565,     5,   844,   390,    -1,   507,   844,
      -1,   262,   931,    -1,   100,  1483,     8,  1484,  1482,    -1,
      -1,   545,   844,    -1,   936,    -1,   936,    -1,   245,   931,
      -1,   248,   931,   625,   844,     5,   844,    -1,   248,   931,
     618,   844,     5,   844,    -1,    26,    -1,    -1,  1490,    -1,
    1491,  1197,    -1,  1489,    -1,  1490,  1489,    -1,    -1,  1492,
    1493,    -1,   668,    -1,   669,    -1,   670,    -1,   671,    -1,
     688,    -1,   710,    -1,   724,    -1,   725,    -1,   731,    -1,
     732,    -1,   751,    -1,   819,    -1,   820,    -1,   821,    -1,
     822,    -1,   833,    -1,   834,    -1,   835,    -1,   836,    -1,
     888,    -1,   892,    -1,   922,    -1,   943,    -1,   944,    -1,
     947,    -1,   948,    -1,   949,    -1,   950,    -1,   963,    -1,
     971,    -1,   992,    -1,   993,    -1,   995,    -1,   999,    -1,
    1016,    -1,  1017,    -1,  1021,    -1,  1022,    -1,  1023,    -1,
    1024,    -1,  1032,    -1,  1047,    -1,  1060,    -1,  1071,    -1,
    1072,    -1,  1073,    -1,  1084,    -1,  1124,    -1,  1127,    -1,
    1129,    -1,  1135,    -1,  1136,    -1,  1139,    -1,  1142,    -1,
    1145,    -1,  1147,    -1,  1149,    -1,  1151,    -1,  1158,    -1,
    1163,    -1,  1167,    -1,  1168,    -1,  1169,    -1,  1181,    -1,
    1233,    -1,  1234,    -1,  1236,    -1,  1248,    -1,  1249,    -1,
    1267,    -1,  1270,    -1,  1299,    -1,  1301,    -1,  1390,    -1,
    1391,    -1,  1422,    -1,  1423,    -1,  1441,    -1,  1468,    -1,
    1472,    -1,  1477,    -1,  1479,    -1,  1481,    -1,  1485,    -1,
    1486,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   922,   922,   925,   928,   934,   940,   947,   951,   951,
     957,   980,   981,   982,   983,   984,   998,   999,  1000,  1001,
    1002,  1007,  1008,  1019,  1022,  1025,  1025,  1029,  1032,  1033,
    1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1058,  1059,  1062,
    1062,  1070,  1071,  1074,  1080,  1082,  1093,  1095,  1097,  1099,
    1103,  1105,  1167,  1171,  1175,  1175,  1186,  1190,  1194,  1195,
    1198,  1204,  1198,  1217,  1222,  1226,  1217,  1238,  1242,  1238,
    1250,  1255,  1250,  1274,  1281,  1285,  1273,  1311,  1311,  1315,
    1316,  1317,  1322,  1325,  1330,  1334,  1342,  1345,  1345,  1351,
    1355,  1370,  1368,  1386,  1386,  1401,  1401,  1404,  1404,  1408,
    1411,  1411,  1411,  1418,  1419,  1418,  1426,  1426,  1437,  1437,
    1456,  1459,  1462,  1465,  1468,  1471,  1484,  1489,  1489,  1490,
    1490,  1493,  1498,  1498,  1502,  1512,  1526,  1530,  1525,  1540,
    1546,  1554,  1555,  1558,  1558,  1561,  1565,  1570,  1577,  1577,
    1581,  1581,  1588,  1588,  1593,  1593,  1598,  1598,  1603,  1603,
    1616,  1617,  1625,  1626,  1643,  1646,  1649,  1652,  1655,  1658,
    1664,  1675,  1680,  1693,  1697,  1712,  1713,  1717,  1717,  1721,
    1721,  1721,  1722,  1723,  1728,  1728,  1731,  1731,  1740,  1741,
    1742,  1745,  1749,  1750,  1750,  1767,  1767,  1767,  1767,  1771,
    1778,  1779,  1782,  1782,  1785,  1785,  1794,  1791,  1807,  1807,
    1809,  1809,  1811,  1813,  1815,  1817,  1820,  1824,  1824,  1825,
    1825,  1829,  1829,  1841,  1841,  1846,  1850,  1852,  1853,  1856,
    1856,  1856,  1860,  1861,  1862,  1863,  1870,  1871,  1872,  1873,
    1876,  1877,  1878,  1879,  1883,  1888,  1893,  1897,  1900,  1904,
    1905,  1906,  1907,  1908,  1909,  1910,  1911,  1914,  1915,  1916,
    1948,  1952,  1954,  1956,  1956,  1963,  1967,  1967,  1971,  1972,
    1973,  1974,  1975,  1976,  1977,  1983,  1983,  1986,  1988,  1994,
    1996,  2002,  2010,  2010,  2013,  2014,  2015,  2016,  2017,  2018,
    2019,  2025,  2028,  2028,  2041,  2041,  2048,  2049,  2050,  2052,
    2053,  2055,  2057,  2058,  2059,  2060,  2065,  2071,  2077,  2078,
    2080,  2082,  2083,  2084,  2085,  2086,  2087,  2090,  2091,  2098,
    2106,  2106,  2114,  2111,  2126,  2126,  2128,  2128,  2136,  2136,
    2139,  2142,  2143,  2148,  2160,  2164,  2167,  2170,  2171,  2172,
    2173,  2174,  2179,  2186,  2192,  2197,  2201,  2197,  2212,  2214,
    2219,  2224,  2224,  2228,  2228,  2231,  2231,  2237,  2237,  2243,
    2243,  2259,  2262,  2276,  2278,  2280,  2282,  2284,  2286,  2288,
    2294,  2296,  2300,  2302,  2304,  2306,  2308,  2310,  2312,  2318,
    2333,  2336,  2349,  2350,  2351,  2352,  2353,  2357,  2358,  2359,
    2363,  2368,  2375,  2376,  2377,  2378,  2379,  2380,  2381,  2382,
    2383,  2384,  2385,  2392,  2392,  2397,  2397,  2400,  2406,  2414,
    2420,  2430,  2431,  2439,  2446,  2450,  2460,  2464,  2469,  2474,
    2476,  2486,  2499,  2507,  2520,  2525,  2531,  2536,  2541,  2542,
    2548,  2619,  2625,  2630,  2638,  2638,  2653,  2657,  2664,  2667,
    2675,  2686,  2696,  2702,  2711,  2716,  2724,  2727,  2730,  2735,
    2742,  2747,  2752,  2757,  2767,  2775,  2783,  2788,  2792,  2797,
    2801,  2805,  2812,  2815,  2818,  2822,  2826,  2830,  2834,  2842,
    2852,  2857,  2850,  2873,  2878,  2873,  2895,  2895,  2895,  2898,
    2898,  2898,  2901,  2901,  2901,  2904,  2904,  2904,  2907,  2913,
    2919,  2925,  2935,  2935,  2939,  2943,  2944,  2950,  2951,  2956,
    2959,  2968,  2977,  2978,  2981,  2986,  2992,  2996,  3000,  3003,
    3009,  3012,  3015,  3032,  3035,  3041,  3042,  3043,  3047,  3048,
    3049,  3050,  3051,  3053,  3054,  3055,  3057,  3058,  3062,  3063,
    3068,  3069,  3081,  3085,  3080,  3093,  3096,  3110,  3114,  3119,
    3109,  3139,  3145,  3139,  3159,  3159,  3161,  3162,  3166,  3166,
    3170,  3170,  3175,  3175,  3182,  3183,  3187,  3187,  3191,  3191,
    3196,  3196,  3203,  3207,  3208,  3209,  3214,  3214,  3217,  3217,
    3221,  3221,  3225,  3225,  3229,  3229,  3234,  3234,  3239,  3239,
    3244,  3244,  3249,  3249,  3265,  3282,  3283,  3284,  3285,  3286,
    3287,  3290,  3290,  3293,  3295,  3298,  3301,  3303,  3304,  3305,
    3307,  3309,  3311,  3313,  3317,  3324,  3326,  3332,  3337,  3342,
    3347,  3347,  3350,  3356,  3361,  3364,  3371,  3371,  3373,  3374,
    3376,  3378,  3380,  3382,  3386,  3395,  3395,  3457,  3469,  3476,
    3476,  3480,  3485,  3491,  3495,  3499,  3505,  3509,  3513,  3519,
    3519,  3527,  3528,  3532,  3532,  3536,  3537,  3540,  3543,  3543,
    3546,  3548,  3548,  3551,  3553,  3553,  3554,  3556,  3556,  3565,
    3563,  3575,  3575,  3575,  3578,  3580,  3578,  3587,  3590,  3596,
    3607,  3607,  3611,  3617,  3617,  3621,  3622,  3633,  3634,  3636,
    3638,  3643,  3643,  3647,  3646,  3653,  3652,  3658,  3658,  3663,
    3663,  3669,  3669,  3674,  3674,  3679,  3679,  3684,  3684,  3687,
    3687,  3690,  3690,  3693,  3693,  3735,  3736,  3744,  3745,  3754,
    3759,  3764,  3765,  3766,  3770,  3769,  3780,  3785,  3790,  3790,
    3801,  3806,  3807,  3808,  3809,  3812,  3812,  3815,  3820,  3821,
    3822,  3823,  3824,  3825,  3826,  3827,  3828,  3833,  3833,  3835,
    3838,  3838,  3840,  3844,  3844,  3847,  3848,  3851,  3851,  3856,
    3856,  3859,  3860,  3861,  3862,  3863,  3864,  3865,  3866,  3867,
    3868,  3869,  3870,  3871,  3872,  3873,  3874,  3875,  3879,  3897,
    3897,  3897,  3923,  3934,  3941,  3947,  3953,  3959,  3970,  3993,
    3992,  4009,  4009,  4013,  4014,  4022,  4023,  4024,  4025,  4032,
    4033,  4035,  4036,  4040,  4045,  4046,  4047,  4048,  4049,  4050,
    4051,  4052,  4053,  4054,  4055,  4058,  4058,  4060,  4060,  4060,
    4062,  4066,  4066,  4075,  4080,  4096,  4102,  4074,  4116,  4130,
    4140,  4129,  4153,  4160,  4160,  4165,  4170,  4175,  4176,  4179,
    4179,  4179,  4182,  4182,  4190,  4196,  4210,  4214,  4227,  4209,
    4245,  4245,  4258,  4269,  4268,  4280,  4276,  4293,  4290,  4303,
    4303,  4305,  4306,  4308,  4309,  4312,  4313,  4314,  4316,  4321,
    4326,  4332,  4334,  4335,  4338,  4339,  4342,  4344,  4353,  4359,
    4353,  4370,  4371,  4375,  4375,  4385,  4385,  4397,  4400,  4404,
    4408,  4413,  4417,  4418,  4419,  4420,  4421,  4425,  4425,  4427,
    4427,  4430,  4439,  4487,  4487,  4490,  4494,  4498,  4540,  4582,
    4583,  4584,  4587,  4601,  4613,  4613,  4618,  4619,  4625,  4685,
    4742,  4747,  4754,  4759,  4767,  4773,  4802,  4805,  4806,  4847,
    4890,  4891,  4895,  4896,  4900,  4953,  4957,  4960,  4966,  4977,
    4984,  4992,  4992,  4995,  4996,  4997,  4998,  4999,  5002,  5005,
    5011,  5014,  5018,  5022,  5029,  5034,  5041,  5044,  5050,  5052,
    5052,  5052,  5056,  5076,  5083,  5090,  5093,  5107,  5114,  5115,
    5118,  5119,  5123,  5129,  5134,  5140,  5141,  5146,  5150,  5150,
    5154,  5155,  5158,  5159,  5163,  5171,  5174,  5180,  5181,  5183,
    5185,  5189,  5189,  5190,  5195,  5203,  5204,  5209,  5210,  5212,
    5225,  5227,  5228,  5230,  5233,  5236,  5239,  5243,  5246,  5249,
    5253,  5257,  5261,  5264,  5268,  5271,  5272,  5273,  5276,  5279,
    5282,  5285,  5288,  5291,  5294,  5310,  5318,  5318,  5320,  5327,
    5334,  5349,  5347,  5367,  5372,  5373,  5377,  5378,  5380,  5381,
    5383,  5383,  5391,  5400,  5400,  5410,  5411,  5414,  5415,  5418,
    5422,  5436,  5441,  5446,  5451,  5461,  5461,  5465,  5468,  5468,
    5470,  5480,  5489,  5496,  5498,  5502,  5505,  5505,  5509,  5508,
    5512,  5511,  5515,  5514,  5518,  5517,  5521,  5520,  5523,  5523,
    5539,  5538,  5560,  5561,  5562,  5563,  5564,  5565,  5568,  5568,
    5574,  5574,  5577,  5577,  5587,  5588,  5589,  5596,  5608,  5609,
    5612,  5613,  5616,  5619,  5619,  5624,  5628,  5633,  5639,  5640,
    5641,  5645,  5646,  5647,  5648,  5652,  5662,  5664,  5669,  5672,
    5677,  5683,  5690,  5697,  5706,  5713,  5720,  5727,  5734,  5743,
    5743,  5745,  5745,  5748,  5749,  5750,  5751,  5752,  5753,  5754,
    5755,  5756,  5757,  5760,  5760,  5763,  5764,  5765,  5766,  5769,
    5769,  5772,  5772,  5775,  5776,  5777,  5778,  5779,  5780,  5781,
    5782,  5784,  5785,  5786,  5787,  5789,  5790,  5791,  5792,  5794,
    5795,  5796,  5797,  5798,  5799,  5800,  5801,  5805,  5811,  5819,
    5830,  5839,  5850,  5854,  5858,  5864,  5829,  5877,  5880,  5888,
    5900,  5902,  5907,  5915,  5925,  5928,  5932,  5940,  5906,  5949,
    5953,  5957,  5961,  5953,  5971,  5972,  5973,  5974,  5979,  5981,
    5984,  5988,  5991,  5998,  6003,  6004,  6005,  6010,  6011,  6017,
    6017,  6017,  6022,  6022,  6022,  6033,  6034,  6040,  6041,  6053,
    6054,  6059,  6060,  6061,  6065,  6068,  6074,  6077,  6085,  6086,
    6092,  6099,  6102,  6111,  6114,  6117,  6120,  6123,  6126,  6129,
    6136,  6139,  6146,  6149,  6155,  6158,  6165,  6168,  6175,  6176,
    6181,  6185,  6188,  6194,  6197,  6203,  6210,  6211,  6215,  6221,
    6224,  6231,  6232,  6239,  6242,  6247,  6258,  6259,  6260,  6261,
    6262,  6263,  6264,  6265,  6266,  6269,  6272,  6278,  6278,  6284,
    6284,  6295,  6308,  6318,  6318,  6323,  6323,  6327,  6331,  6332,
    6338,  6339,  6344,  6348,  6355,  6358,  6365,  6369,  6364,  6381,
    6385,  6392,  6396,  6396,  6409,  6413,  6413,  6428,  6430,  6432,
    6434,  6436,  6438,  6440,  6442,  6448,  6458,  6465,  6470,  6471,
    6475,  6477,  6478,  6481,  6482,  6483,  6486,  6491,  6498,  6499,
    6505,  6517,  6518,  6521,  6521,  6526,  6531,  6536,  6537,  6540,
    6541,  6546,  6551,  6555,  6560,  6561,  6565,  6572,  6576,  6577,
    6582,  6584,  6588,  6589,  6593,  6594,  6595,  6596,  6600,  6601,
    6606,  6607,  6612,  6613,  6618,  6619,  6624,  6629,  6630,  6635,
    6636,  6640,  6641,  6646,  6653,  6658,  6663,  6667,  6668,  6673,
    6674,  6680,  6682,  6687,  6688,  6694,  6697,  6700,  6707,  6709,
    6723,  6728,  6729,  6732,  6734,  6741,  6744,  6750,  6754,  6758,
    6762,  6765,  6772,  6779,  6784,  6788,  6789,  6795,  6798,  6809,
    6816,  6822,  6825,  6832,  6839,  6845,  6846,  6852,  6853,  6854,
    6857,  6858,  6863,  6863,  6867,  6875,  6876,  6879,  6882,  6887,
    6888,  6893,  6896,  6902,  6905,  6911,  6914,  6920,  6923,  6930,
    6931,  6960,  6961,  6966,  6967,  6971,  6976,  6979,  6982,  6985,
    6991,  6992,  6996,  6999,  7002,  7003,  7008,  7011,  7014,  7017,
    7020,  7023,  7026,  7032,  7033,  7034,  7035,  7036,  7038,  7040,
    7041,  7046,  7049,  7053,  7059,  7060,  7061,  7062,  7074,  7075,
    7076,  7080,  7081,  7086,  7088,  7089,  7090,  7092,  7093,  7094,
    7095,  7097,  7098,  7100,  7101,  7103,  7104,  7105,  7106,  7108,
    7112,  7113,  7119,  7121,  7122,  7123,  7124,  7129,  7133,  7137,
    7141,  7142,  7146,  7147,  7157,  7166,  7167,  7168,  7172,  7175,
    7180,  7185,  7190,  7198,  7202,  7206,  7207,  7208,  7213,  7216,
    7219,  7223,  7224,  7228,  7229,  7233,  7233,  7233,  7233,  7233,
    7233,  7234,  7237,  7242,  7242,  7242,  7242,  7242,  7242,  7244,
    7247,  7253,  7253,  7253,  7253,  7253,  7253,  7253,  7254,  7254,
    7254,  7254,  7254,  7254,  7254,  7256,  7257,  7260,  7269,  7269,
    7274,  7274,  7280,  7280,  7285,  7285,  7292,  7293,  7294,  7297,
    7297,  7300,  7301,  7302,  7307,  7310,  7316,  7321,  7329,  7342,
    7343,  7340,  7361,  7371,  7374,  7379,  7391,  7394,  7398,  7401,
    7402,  7408,  7411,  7412,  7421,  7430,  7435,  7436,  7437,  7438,
    7446,  7449,  7455,  7458,  7468,  7477,  7480,  7483,  7489,  7495,
    7498,  7501,  7504,  7510,  7512,  7514,  7516,  7518,  7520,  7521,
    7522,  7523,  7524,  7525,  7526,  7528,  7530,  7532,  7534,  7536,
    7538,  7540,  7541,  7546,  7547,  7553,  7554,  7557,  7566,  7570,
    7577,  7577,  7581,  7581,  7586,  7586,  7590,  7590,  7594,  7600,
    7600,  7603,  7603,  7609,  7616,  7617,  7618,  7622,  7623,  7626,
    7627,  7631,  7637,  7647,  7648,  7656,  7657,  7658,  7659,  7660,
    7661,  7665,  7666,  7667,  7671,  7671,  7683,  7684,  7688,  7689,
    7690,  7694,  7700,  7787,  7791,  7787,  7800,  7804,  7810,  7818,
    7828,  7838,  7850,  7853,  7872,  7898,  7901,  7907,  7910,  7915,
    7918,  7926,  7934,  7947,  7950,  7958,  7961,  7964,  7972,  7976,
    7979,  7982,  7985,  7989,  7990,  7991,  7992,  7993,  7999,  8000,
    8001,  8002,  8003,  8004,  8005,  8006,  8007,  8008,  8009,  8010,
    8011,  8012,  8016,  8022,  8023,  8035,  8047,  8047,  8051,  8052,
    8053,  8054,  8058,  8059,  8060,  8065,  8091,  8142,  8144,  8146,
    8148,  8152,  8157,  8159,  8162,  8164,  8166,  8170,  8173,  8178,
    8183,  8187,  8196,  8197,  8201,  8213,  8216,  8212,  8235,  8235,
    8239,  8240,  8243,  8244,  8245,  8246,  8247,  8248,  8249,  8254,
    8255,  8259,  8262,  8267,  8271,  8276,  8280,  8285,  8289,  8292,
    8296,  8299,  8304,  8308,  8319,  8325,  8325,  8326,  8327,  8334,
    8343,  8343,  8345,  8346,  8347,  8348,  8349,  8350,  8351,  8352,
    8353,  8354,  8355,  8356,  8357,  8358,  8359,  8360,  8361,  8362,
    8363,  8364,  8365,  8366,  8367,  8368,  8369,  8370,  8371,  8372,
    8373,  8374,  8375,  8376,  8377,  8378,  8379,  8380,  8381,  8382,
    8383,  8384,  8385,  8386,  8387,  8388,  8389,  8390,  8391,  8392,
    8393,  8394,  8395,  8396,  8397,  8398,  8399,  8400,  8401,  8402,
    8403,  8404,  8405,  8406,  8407,  8408,  8409,  8410,  8411,  8412,
    8413,  8414,  8415,  8416,  8417,  8418,  8419,  8420,  8421,  8422,
    8423,  8424,  8425,  8426,  8427,  8428,  8429
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "BEFORE_INSERT", "CONCAT_PIPES", 
  "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", 
  "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", 
  "WHENEVER_ERROR_CONTINUE", "WHENEVER_WARNING_CONTINUE", 
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
       0,   256,  1652,  1653,  1654,  1569,  1609,  1564,  1500,  1378,
    1486,  1482,  1396,  1559,  1295,  1353,  1427,  1595,  1582,  1515,
    1487,  1583,  1360,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
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
    1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,
    1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1348,  1349,  1350,  1351,  1352,  1354,  1355,  1356,  1357,  1358,
    1359,  1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1379,  1380,
    1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,
    1391,  1392,  1393,  1394,  1395,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1423,  1424,  1425,  1426,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,
    1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,  1483,
    1484,  1485,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,  1499,  1501,  1502,  1503,  1504,  1505,  1506,
    1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,
    1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,
    1558,  1560,  1561,  1562,  1563,  1565,  1566,  1567,  1568,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,
    1581,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1593,  1594,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   667,   668,   669,   670,   671,   672,   672,   673,   673,
     674,   675,   675,   675,   675,   675,   676,   676,   676,   676,
     676,   677,   677,   678,   678,   680,   679,   679,   681,   681,
     682,   682,   682,   682,   682,   682,   682,   682,   682,   682,
     682,   682,   682,   682,   682,   682,   682,   683,   683,   685,
     684,   686,   686,   687,   687,   687,   687,   687,   687,   687,
     687,   687,   688,   689,   690,   689,   689,   689,   689,   689,
     691,   692,   689,   693,   694,   695,   689,   696,   697,   689,
     698,   699,   689,   700,   701,   702,   689,   703,   703,   704,
     704,   704,   705,   705,   706,   706,   707,   708,   708,   709,
     709,   711,   710,   712,   710,   713,   713,   714,   714,   715,
     716,   717,   716,   718,   719,   718,   721,   720,   723,   722,
     724,   724,   724,   724,   724,   724,   725,   726,   726,   727,
     727,   728,   729,   729,   730,   731,   733,   734,   732,   735,
     735,   736,   736,   737,   737,   738,   738,   738,   739,   739,
     741,   740,   742,   740,   743,   740,   744,   740,   745,   740,
     746,   746,   747,   747,   748,   748,   748,   748,   748,   748,
     749,   750,   750,   751,   751,   752,   752,   753,   753,   755,
     756,   754,   754,   754,   757,   757,   759,   758,   760,   760,
     760,   760,   760,   761,   760,   762,   762,   762,   762,   763,
     764,   764,   765,   765,   767,   766,   768,   766,   769,   769,
     770,   770,   771,   772,   772,   772,   773,   775,   774,   776,
     774,   777,   774,   778,   778,   779,   780,   781,   781,   783,
     784,   782,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     786,   787,   788,   789,   789,   790,   792,   791,   793,   793,
     793,   793,   793,   793,   793,   795,   794,   796,   796,   797,
     797,   798,   800,   799,   801,   801,   801,   801,   801,   801,
     801,   802,   803,   803,   805,   804,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   807,
     809,   808,   810,   808,   812,   811,   813,   811,   814,   814,
     815,   816,   816,   817,   818,   818,   818,   818,   818,   818,
     818,   818,   819,   820,   821,   823,   824,   822,   825,   825,
     826,   827,   827,   828,   828,   830,   829,   831,   829,   832,
     829,   833,   833,   834,   834,   834,   834,   834,   834,   834,
     834,   834,   835,   835,   835,   835,   835,   835,   835,   835,
     836,   836,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   838,   839,   839,   840,   840,   841,   841,   842,
     842,   843,   843,   844,   845,   845,   846,   846,   846,   846,
     846,   846,   847,   847,   848,   848,   848,   848,   849,   849,
     850,   851,   851,   851,   852,   851,   853,   853,   854,   854,
     855,   855,   855,   855,   856,   856,   857,   857,   857,   857,
     857,   857,   857,   857,   858,   859,   860,   860,   860,   860,
     860,   860,   861,   861,   861,   861,   861,   861,   861,   862,
     864,   865,   863,   866,   867,   863,   869,   870,   868,   871,
     872,   868,   873,   874,   868,   875,   876,   868,   868,   868,
     868,   868,   877,   877,   878,   879,   879,   879,   879,   879,
     879,   879,   879,   879,   880,   880,   881,   881,   881,   881,
     882,   882,   882,   883,   883,   884,   884,   884,   885,   885,
     885,   885,   885,   885,   885,   885,   885,   885,   886,   886,
     887,   887,   889,   890,   888,   891,   891,   893,   894,   895,
     892,   897,   898,   896,   899,   899,   900,   900,   901,   901,
     903,   902,   904,   902,   905,   905,   906,   906,   908,   907,
     909,   907,   910,   911,   911,   911,   912,   912,   913,   913,
     914,   914,   915,   915,   917,   916,   918,   916,   919,   916,
     920,   916,   921,   916,   922,   923,   923,   923,   923,   923,
     923,   924,   924,   925,   926,   927,   928,   928,   928,   928,
     928,   928,   928,   928,   929,   930,   931,   932,   933,   934,
     935,   935,   936,   937,   938,   938,   939,   939,   940,   940,
     940,   940,   940,   940,   941,   942,   942,   943,   944,   945,
     945,   946,   947,   948,   948,   948,   949,   949,   949,   951,
     950,   952,   952,   953,   953,   954,   954,   955,   956,   956,
     957,   958,   958,   959,   960,   960,   961,   962,   962,   964,
     963,   965,   966,   965,   967,   968,   965,   969,   969,   970,
     972,   971,   971,   973,   973,   974,   974,   975,   975,   976,
     976,   977,   977,   979,   978,   980,   978,   981,   978,   982,
     978,   983,   978,   984,   978,   985,   978,   986,   978,   987,
     978,   988,   978,   989,   978,   990,   990,   991,   991,   992,
     993,   994,   994,   994,   996,   995,   997,   997,   998,   997,
     999,  1000,  1000,  1000,  1000,  1001,  1001,  1002,  1003,  1003,
    1003,  1003,  1003,  1003,  1003,  1003,  1003,  1005,  1004,  1004,
    1007,  1006,  1008,  1010,  1009,  1011,  1011,  1012,  1012,  1014,
    1013,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1016,  1018,
    1019,  1017,  1020,  1020,  1021,  1022,  1023,  1024,  1024,  1026,
    1025,  1027,  1027,  1028,  1028,  1029,  1029,  1029,  1029,  1030,
    1030,  1031,  1031,  1032,  1033,  1033,  1033,  1033,  1033,  1033,
    1033,  1033,  1033,  1033,  1033,  1034,  1034,  1035,  1035,  1035,
    1036,  1037,  1037,  1039,  1040,  1041,  1042,  1038,  1043,  1045,
    1046,  1044,  1047,  1048,  1048,  1049,  1050,  1051,  1051,  1052,
    1052,  1052,  1054,  1053,  1055,  1055,  1057,  1058,  1059,  1056,
    1061,  1060,  1062,  1064,  1063,  1065,  1063,  1066,  1063,  1067,
    1067,  1068,  1068,  1069,  1069,  1070,  1070,  1070,  1071,  1072,
    1073,  1074,  1074,  1074,  1075,  1075,  1076,  1076,  1078,  1079,
    1077,  1080,  1080,  1082,  1081,  1083,  1081,  1084,  1085,  1085,
    1085,  1085,  1086,  1086,  1086,  1086,  1086,  1088,  1087,  1089,
    1089,  1090,  1091,  1092,  1092,  1093,  1094,  1094,  1094,  1094,
    1094,  1094,  1095,  1096,  1097,  1097,  1098,  1098,  1099,  1100,
    1101,  1101,  1102,  1102,  1103,  1104,  1105,  1105,  1105,  1105,
    1105,  1105,  1106,  1106,  1107,  1108,  1108,  1109,  1109,  1110,
    1110,  1111,  1111,  1112,  1112,  1112,  1112,  1112,  1113,  1113,
    1114,  1114,  1115,  1115,  1116,  1117,  1118,  1118,  1119,  1120,
    1120,  1120,  1121,  1122,  1122,  1123,  1123,  1124,  1125,  1125,
    1126,  1126,  1127,  1128,  1129,  1130,  1130,  1131,  1132,  1132,
    1133,  1133,  1134,  1134,  1135,  1136,  1136,  1137,  1137,  1137,
    1137,  1138,  1138,  1138,  1139,  1140,  1140,  1141,  1141,  1141,
    1142,  1143,  1143,  1144,  1144,  1144,  1144,  1144,  1144,  1144,
    1144,  1144,  1144,  1144,  1144,  1144,  1144,  1144,  1144,  1144,
    1144,  1144,  1144,  1144,  1144,  1145,  1146,  1146,  1147,  1147,
    1148,  1150,  1149,  1151,  1152,  1152,  1153,  1153,  1154,  1154,
    1156,  1155,  1157,  1159,  1158,  1160,  1160,  1161,  1161,  1162,
    1162,  1163,  1163,  1163,  1163,  1164,  1164,  1165,  1166,  1166,
    1167,  1168,  1169,  1170,  1171,  1171,  1172,  1172,  1174,  1173,
    1175,  1173,  1176,  1173,  1177,  1173,  1178,  1173,  1179,  1173,
    1180,  1173,  1181,  1181,  1181,  1181,  1181,  1181,  1183,  1182,
    1184,  1184,  1186,  1185,  1185,  1185,  1185,  1185,  1187,  1187,
    1188,  1188,  1189,  1190,  1190,  1191,  1192,  1193,  1194,  1194,
    1194,  1195,  1195,  1195,  1195,  1196,  1197,  1197,  1198,  1198,
    1199,  1200,  1200,  1200,  1200,  1200,  1200,  1200,  1200,  1201,
    1201,  1202,  1202,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1204,  1204,  1205,  1205,  1205,  1205,  1206,
    1206,  1207,  1207,  1208,  1208,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1208,  1208,  1208,  1209,  1209,  1209,
    1211,  1212,  1213,  1214,  1215,  1216,  1210,  1217,  1217,  1218,
    1219,  1219,  1221,  1222,  1223,  1224,  1225,  1226,  1220,  1227,
    1229,  1230,  1231,  1228,  1232,  1232,  1232,  1232,  1233,  1233,
    1233,  1233,  1233,  1234,  1235,  1235,  1235,  1236,  1236,  1238,
    1239,  1237,  1240,  1241,  1237,  1242,  1242,  1243,  1243,  1244,
    1244,  1245,  1245,  1245,  1246,  1246,  1247,  1247,  1248,  1248,
    1249,  1250,  1250,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,  1256,  1256,
    1257,  1258,  1258,  1259,  1259,  1260,  1261,  1261,  1262,  1263,
    1263,  1264,  1264,  1265,  1265,  1266,  1267,  1267,  1267,  1267,
    1267,  1267,  1267,  1267,  1267,  1267,  1267,  1268,  1268,  1269,
    1269,  1270,  1271,  1273,  1272,  1275,  1274,  1274,  1276,  1276,
    1277,  1277,  1278,  1278,  1279,  1279,  1281,  1282,  1280,  1283,
    1283,  1284,  1285,  1284,  1286,  1287,  1286,  1288,  1288,  1288,
    1288,  1288,  1288,  1288,  1288,  1289,  1290,  1291,  1292,  1292,
    1293,  1294,  1294,  1295,  1295,  1295,  1296,  1297,  1298,  1298,
    1299,  1300,  1300,  1302,  1301,  1303,  1303,  1303,  1303,  1303,
    1303,  1303,  1303,  1303,  1303,  1303,  1303,  1304,  1305,  1305,
    1306,  1306,  1307,  1307,  1308,  1308,  1308,  1308,  1309,  1309,
    1310,  1310,  1311,  1311,  1312,  1312,  1313,  1314,  1314,  1315,
    1315,  1316,  1316,  1317,  1318,  1319,  1320,  1321,  1321,  1322,
    1322,  1323,  1323,  1324,  1324,  1325,  1325,  1325,  1326,  1326,
    1327,  1328,  1328,  1329,  1329,  1330,  1330,  1331,  1331,  1331,
    1331,  1331,  1332,  1333,  1334,  1335,  1335,  1336,  1336,  1337,
    1338,  1339,  1339,  1340,  1341,  1342,  1342,  1343,  1343,  1343,
    1344,  1344,  1345,  1345,  1346,  1347,  1347,  1348,  1348,  1349,
    1349,  1350,  1350,  1351,  1351,  1352,  1352,  1353,  1353,  1354,
    1354,  1355,  1355,  1356,  1356,  1357,  1358,  1358,  1358,  1358,
    1359,  1359,  1360,  1360,  1361,  1361,  1362,  1362,  1362,  1362,
    1362,  1362,  1362,  1363,  1363,  1363,  1363,  1363,  1363,  1363,
    1363,  1364,  1364,  1364,  1365,  1365,  1365,  1365,  1366,  1366,
    1366,  1367,  1367,  1368,  1368,  1368,  1368,  1368,  1368,  1368,
    1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,
    1369,  1369,  1370,  1370,  1370,  1370,  1370,  1371,  1372,  1373,
    1374,  1374,  1374,  1374,  1375,  1376,  1376,  1376,  1377,  1377,
    1378,  1378,  1378,  1379,  1380,  1380,  1380,  1380,  1380,  1381,
    1382,  1383,  1383,  1384,  1384,  1385,  1385,  1385,  1385,  1385,
    1385,  1385,  1385,  1386,  1386,  1386,  1386,  1386,  1386,  1386,
    1386,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1388,  1388,
    1388,  1388,  1388,  1388,  1388,  1389,  1389,  1390,  1392,  1391,
    1393,  1391,  1394,  1391,  1395,  1391,  1396,  1396,  1396,  1397,
    1397,  1398,  1398,  1398,  1399,  1399,  1400,  1400,  1401,  1403,
    1404,  1402,  1405,  1406,  1406,  1407,  1408,  1408,  1408,  1408,
    1408,  1409,  1410,  1410,  1411,  1412,  1413,  1413,  1413,  1413,
    1414,  1414,  1415,  1415,  1416,  1417,  1417,  1417,  1418,  1418,
    1418,  1418,  1418,  1419,  1419,  1419,  1419,  1419,  1419,  1419,
    1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,
    1419,  1419,  1419,  1420,  1420,  1421,  1421,  1422,  1423,  1423,
    1424,  1424,  1425,  1425,  1426,  1426,  1427,  1427,  1428,  1429,
    1429,  1430,  1430,  1431,  1432,  1432,  1432,  1433,  1433,  1434,
    1435,  1436,  1437,  1438,  1438,  1439,  1439,  1439,  1439,  1439,
    1439,  1440,  1440,  1440,  1442,  1441,  1443,  1443,  1444,  1444,
    1444,  1445,  1446,  1448,  1449,  1447,  1450,  1450,  1450,  1451,
    1451,  1451,  1451,  1451,  1451,  1452,  1452,  1453,  1454,  1455,
    1455,  1456,  1456,  1457,  1457,  1458,  1458,  1458,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1460,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,
    1460,  1460,  1461,  1462,  1462,  1463,  1464,  1464,  1465,  1465,
    1465,  1465,  1466,  1466,  1466,  1467,  1467,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1469,  1469,  1469,
    1469,  1469,  1470,  1470,  1471,  1473,  1474,  1472,  1475,  1475,
    1476,  1476,  1477,  1477,  1477,  1477,  1477,  1477,  1477,  1478,
    1478,  1479,  1479,  1480,  1480,  1481,  1481,  1482,  1482,  1483,
    1484,  1485,  1486,  1486,  1487,  1488,  1488,  1489,  1490,  1490,
    1492,  1491,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493
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
       1,     1,     2,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     3,
       4,     4,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     0,     3,     2,     2,     1,     3,
       4,     4,     5,     5,     1,     1,     2,     2,     4,     4,
       2,     2,     4,     4,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       0,     0,     6,     0,     0,     8,     0,     0,     6,     0,
       0,     6,     0,     0,     6,     0,     0,     6,     5,     5,
       5,     7,     0,     3,     1,     1,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     4,     4,     2,     2,
       2,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       4,     6,     6,     3,     5,     5,     3,     1,     1,     3,
       1,     3,     0,     0,    11,     0,     2,     0,     0,     0,
       8,     0,     0,    10,     0,     1,     0,     1,     1,     2,
       0,     3,     0,     3,     0,     1,     1,     2,     0,     3,
       0,     3,     3,     1,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     0,     3,     0,     3,     0,     4,
       0,     4,     0,     4,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     6,     4,
       3,     6,     3,     6,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     4,     1,     1,     1,     4,
       3,     6,     3,     6,     1,     1,     2,     2,     2,     1,
       3,     1,     2,     2,     2,     4,     2,     2,     4,     0,
       8,     0,     1,     1,     1,     0,     1,     2,     0,     1,
       2,     0,     1,     2,     0,     1,     3,     0,     2,     0,
       7,     0,     0,     3,     0,     0,     7,     5,     2,     2,
       0,     5,     4,     1,     3,     3,     3,     0,     2,     0,
       1,     1,     2,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     1,     3,     1,     3,     2,
       4,     1,     1,     1,     0,     4,     5,     6,     0,    10,
       3,     1,     1,     2,     2,     0,     2,     1,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     0,     3,     1,
       0,     3,     2,     0,     3,     1,     3,     1,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     7,     1,     1,     2,     2,     2,     3,     4,     0,
       3,     0,     1,     1,     2,     1,     1,     1,     1,     0,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     0,     0,     0,     0,    13,     1,     0,
       0,     6,     2,     1,     2,     2,     1,     1,     2,     1,
       1,     1,     0,     3,     2,     1,     0,     0,     0,    14,
       0,     5,     1,     0,     3,     0,     7,     0,     5,     1,
       2,     0,     1,     1,     1,     0,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     3,     1,     1,     0,     0,
       7,     1,     2,     0,     3,     0,     4,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       1,     1,     1,     1,     2,     2,     2,     5,     8,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     2,     2,
       3,     6,     1,     3,     1,     1,     1,     3,     6,     9,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     2,     0,
       1,     1,     4,     1,     3,     1,     3,     7,     0,     7,
       0,     6,     3,     1,     3,     1,     2,     5,     0,     7,
       0,     2,     0,     1,     5,     2,     5,     0,     5,     6,
       4,     0,     1,     1,     4,     0,     2,     0,     5,     4,
       2,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     5,     1,     1,     2,     4,
       1,     0,    10,     5,     0,     1,     0,     2,     1,     2,
       0,     3,     1,     0,     4,     0,     2,     1,     3,     1,
       1,     3,     4,     4,     2,     1,     1,     1,     0,     1,
       7,     2,     2,     2,     2,     2,     1,     2,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     1,     0,     4,     1,     2,     2,     2,     0,     1,
       1,     2,     2,     0,     2,     3,     3,     5,     0,     2,
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
       3,     3,     3,     1,     1,     1,     1,     1,     1,     0,
       0,     7,     0,     0,     8,     3,     2,     0,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     3,     1,     3,     2,     4,     1,     3,
       1,     2,     4,     1,     3,     1,     1,     1,     2,     2,
       4,     2,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     6,     6,     0,     1,     0,
       1,     2,     1,     0,     5,     0,     5,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     0,     0,     5,     2,
       1,     0,     0,     3,     0,     0,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     3,     1,     3,
       2,     1,     1,     0,     1,     1,     1,     1,     0,     1,
       3,     1,     1,     0,     3,     1,     1,     1,     1,     1,
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
       2,     0,     2,     1,     1,     1,     5,     3,     5,     3,
       1,     3,     1,     1,     0,     1,     3,     3,     3,     6,
       4,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     1,     5,     5,     1,     1,     1,
       4,     1,     4,     1,     7,     1,     1,     1,     4,     6,
       0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     1,     0,     3,     5,     1,     2,
       2,     4,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     8,
       0,     9,     0,     7,     0,     9,     0,     1,     2,     1,
       3,     1,     3,     5,     1,     1,     1,     1,     2,     0,
       0,     8,     5,     1,     1,     6,     0,     3,     1,     3,
       4,     1,     0,     2,     4,     6,     0,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     2,     4,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     3,     0,     1,     5,     7,     5,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     0,     4,     1,     2,     1,     1,
       1,     2,     2,     0,     0,     6,     0,     2,     2,     7,
       3,     3,     2,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     2,     1,     1,
       2,     4,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     5,     5,     5,     5,     5,     4,     4,
       3,     4,     1,     1,     3,     1,     2,     1,     1,     1,
       3,     5,     1,     1,     1,     1,     3,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     1,     3,     2,
       1,     2,     1,     2,     1,     0,     0,     6,     0,     2,
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
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     781,     0,  1760,  1763,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   832,   179,   805,   810,   177,
     182,   785,     0,   779,   782,   783,   786,   788,   831,   787,
     826,   827,   829,   183,   134,   131,     0,   127,   129,   128,
     132,  1804,   669,   612,  1767,     0,     0,  1770,     0,  1766,
    1762,  1759,  1757,  1758,  1765,  1764,  1761,   294,  1566,  1565,
     825,   175,   186,   178,   183,     1,   789,   784,   830,   828,
     806,   126,   130,   133,  1774,  1771,     0,  1772,  1769,     0,
       0,   591,     0,     0,   176,   835,   900,   592,   833,   624,
     892,     0,   893,   901,   899,   186,   180,   199,     0,   184,
     200,   229,     0,   812,  1182,     0,     0,   811,   135,  1170,
     819,     0,     0,   802,   804,   801,   803,   780,   790,   791,
     813,   794,   795,   796,   799,   797,   798,   800,  1773,  1768,
       0,   894,   834,     0,     0,   908,   906,   907,   896,   895,
     292,   186,  1106,   193,   187,   186,   192,   226,     0,   668,
       0,     0,     0,     0,   175,   541,   868,   792,     0,   326,
     312,   202,   263,   282,   303,   305,   302,     0,   324,     0,
     311,   304,   308,   314,   298,   313,   186,   315,   295,   318,
     296,   297,   905,   904,     0,    21,    22,    13,     0,   914,
       0,    15,     0,   912,     0,   293,     0,   185,  1107,   181,
       0,   199,   201,   259,   253,   254,   242,   219,   250,   202,
     221,   263,   282,   240,   243,   238,     0,   217,     0,   249,
     241,   246,   252,   234,   251,   186,   255,   186,   232,   233,
     230,   258,     0,     0,     0,     0,   820,   175,   175,     0,
       0,   203,     0,   316,     0,     0,   317,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,   902,     0,    16,
      17,    19,    18,    20,     0,    14,     0,   910,     0,   625,
     188,   191,     0,   189,   190,     0,   196,   195,   194,   197,
     186,     0,   186,   256,   257,     0,     0,   186,     0,     0,
       0,     0,   239,   227,  1183,     0,     0,  1171,  1810,   542,
     869,   814,     0,   208,   209,     0,   275,   277,   272,   273,
     269,   271,   268,   270,   267,     0,   277,   288,   289,   285,
     287,   284,   286,   279,     0,     0,     0,   328,     0,   331,
     333,   216,     0,   215,     0,     0,   186,    11,    12,   913,
       0,   897,   626,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   228,   231,   925,   667,   836,   925,
       0,  1808,  1810,  1106,  1661,   807,     0,   925,     0,     0,
     264,     0,     0,   274,   291,   265,   290,     0,   283,     0,
     306,     0,   300,     0,   325,     0,   330,   320,     0,     0,
     309,   299,   262,   319,     0,     0,     0,     0,     0,     0,
     244,     0,   236,   218,   204,     0,   247,   235,   260,   931,
       0,   926,   927,   925,     0,   821,  1809,  1807,     0,     0,
       0,     0,     0,     0,     0,     0,  1791,     0,  1272,  1271,
       0,  1273,     0,   376,  1270,  1212,     0,     5,  1269,   377,
     374,     0,   379,   173,   469,  1084,     0,     0,  1279,   123,
     373,   372,  1204,   367,     0,  1229,  1782,     0,   378,   345,
       0,     3,     2,     0,   375,  1209,     0,     0,   368,   365,
     380,     0,     0,     0,     0,  1277,  1267,   371,     0,     0,
       0,     0,     0,     0,     0,     0,  1266,     0,     0,     0,
     174,  1206,   364,   363,     0,     0,  1786,  1785,     0,     0,
       0,   136,  1205,   370,   369,     0,     0,   366,   887,   469,
       0,   537,     0,     0,     0,   469,     0,     0,     0,   469,
     768,  1180,     0,     0,  1088,     0,  1775,     0,   103,     0,
       0,   840,     0,     0,     0,     0,   769,     0,     0,  1684,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   639,
       0,     0,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,   878,
    1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,
    1869,  1870,  1871,  1872,  1873,  1874,  1875,  1075,  1077,  1072,
    1074,  1073,  1076,  1876,  1877,  1203,  1878,  1208,  1207,  1879,
    1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,  1333,
    1889,  1890,  1891,  1892,  1893,  1894,  1895,  1896,  1811,   808,
     546,   809,     0,   873,     0,   871,     0,   327,   210,   211,
       0,   276,   281,     0,     0,     0,     0,   329,   332,     0,
     214,     0,   911,     0,   220,     0,   186,     0,     0,     0,
       0,     0,  1184,     0,     0,  1172,     0,     0,  1216,   613,
     614,   793,  1047,  1052,  1784,   606,   122,     0,     0,  1749,
    1748,   985,  1745,  1747,  1799,     0,  1223,     0,  1219,  1228,
       7,     0,     6,     0,  1792,  1048,     0,  1140,  1139,  1087,
    1138,  1086,     0,     0,   424,   426,     0,  1177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1533,     0,
       0,     0,   418,     0,     0,     0,     0,   417,     0,     0,
     434,     0,   505,     0,     0,     0,     0,     0,     0,     0,
     413,  1280,     0,   383,   382,   389,   430,   427,   384,   503,
     495,   385,   387,   502,   388,   900,   425,   428,   433,  1268,
     504,  1663,  1274,   124,     0,  1051,   121,     0,   775,    23,
     608,   381,     0,   774,  1044,   776,     0,  1278,   862,   861,
     864,   860,   863,  1801,     0,   858,     0,   607,   958,   859,
    1795,     0,  1783,   120,   955,   670,   953,     0,   604,  1778,
     712,   711,     0,   713,   596,   709,     0,     0,   968,   609,
    1332,  1328,  1331,     0,     0,  1020,  1018,     0,  1012,  1014,
    1013,  1011,  1010,     0,     0,     0,  1009,     0,   749,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     999,   990,   991,     0,  1032,   411,    23,   822,   403,  1789,
       0,  1780,   125,   605,     0,  1017,  1016,  1181,  1179,  1105,
       0,  1652,  1653,  1106,  1194,  1106,  1089,  1090,  1093,  1108,
    1281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,   900,     0,    68,     0,   101,   584,   627,     0,
    1078,   975,  1082,     0,     0,  1033,  1198,     0,     0,  1085,
     631,   628,   629,     0,   633,   634,     0,   636,   637,     0,
     632,   935,   937,     0,     0,   936,   714,   933,   679,   929,
     891,     0,     0,     0,     0,   643,   644,     0,     0,   889,
     885,   886,   882,   883,   884,   877,   881,   880,     0,     0,
       0,     0,     0,     0,   550,   552,   544,   547,   548,   875,
    1810,   870,   872,   815,     0,   278,   280,   307,   301,     0,
       0,   310,   898,     0,   225,     0,   223,   245,   237,   229,
     248,   932,   175,   928,   837,   175,     0,     0,     0,  1256,
    1257,     0,     0,     0,  1230,  1231,  1233,  1234,  1235,  1239,
    1238,  1236,  1237,     0,     0,  1746,   909,     0,   987,     0,
       0,  1222,  1221,     0,  1215,     0,  1511,  1512,     0,  1049,
       0,    23,  1135,  1137,  1136,   391,   390,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   432,
    1541,  1539,  1540,  1536,  1538,  1535,  1537,  1529,     0,     0,
       0,     0,     0,   431,     0,     0,   509,   508,     0,     0,
     479,   476,   485,     0,   482,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   510,   511,   512,   445,     0,     0,   444,   454,
       0,     0,   395,     0,     0,   396,   386,   392,   394,   397,
     398,   399,   400,   401,   393,   423,   422,   470,     0,     0,
     945,     0,     0,   350,    24,   344,     0,     0,  1041,     0,
       0,     0,     0,     0,     0,     0,   962,  1662,     0,     0,
     186,     0,     0,     0,  1780,     0,     0,     0,     0,     0,
     137,     0,     0,   972,   964,   965,   970,  1329,  1330,   888,
     334,   409,     0,   538,   589,   588,   586,   993,   590,   998,
     994,   997,   742,     0,   995,   996,   743,  1003,  1007,  1000,
    1001,  1005,  1006,  1004,  1002,  1008,     0,   777,     0,     0,
       0,   406,   407,   404,   405,     0,     0,     0,   722,   721,
     720,  1781,  1788,    23,  1101,  1102,  1103,  1104,  1098,  1096,
    1195,  1110,  1095,  1091,     0,     0,  1092,  1776,     0,     0,
       0,     0,    97,     0,    98,     0,     0,     0,    73,     0,
       0,     0,   110,   105,     0,   867,     0,   866,     0,   469,
    1080,     0,   920,   921,   944,   915,   916,   770,   942,  1035,
    1200,     0,  1202,  1201,  1688,     0,     0,     0,  1686,  1689,
    1690,   659,     0,     0,     0,   648,   679,   679,   677,     0,
       0,   680,     0,    25,   647,   650,     0,   657,   653,   890,
     879,  1659,  1660,  1650,  1650,     0,     0,  1567,     0,   186,
    1282,     0,     0,  1283,  1326,   186,     0,  1327,     0,  1606,
       0,  1296,     0,  1344,  1343,  1342,  1340,  1341,  1339,  1337,
    1334,  1408,  1407,  1335,  1336,  1345,  1576,  1338,  1666,  1665,
    1664,  1346,  1810,  1810,   563,   554,   545,     0,   549,  1810,
     874,   175,     0,   321,   213,     0,   186,   222,   205,  1185,
     175,  1173,  1398,     0,  1397,     0,  1399,     0,  1400,  1259,
       0,  1265,  1261,  1258,     0,     0,     0,     0,     0,     0,
    1255,  1251,  1387,  1386,  1385,  1227,  1226,     0,  1250,  1246,
       0,  1242,  1240,     0,   617,     0,   616,     0,   986,     0,
       0,   984,  1752,  1754,  1753,  1750,  1800,  1797,  1220,     0,
       0,     0,  1213,   469,   342,     0,   530,  1178,     0,     0,
       0,     0,  1606,     0,     0,     0,     0,     0,   527,   513,
     518,     0,   514,   517,   516,     0,     0,     0,     0,     0,
       0,   419,     0,   171,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,   437,   436,   455,   446,   461,   464,
     465,   462,   468,   467,   466,   456,   457,   459,   458,   460,
     402,   447,   451,   469,   463,   450,   469,    92,     0,   429,
       0,  1210,   977,  1045,  1046,  1043,  1042,     0,   865,     0,
       0,   593,     0,     0,     0,   956,   954,     0,   672,   673,
       0,     0,  1779,  1787,     0,     0,   600,     0,   602,   710,
       0,   141,     0,   966,   973,     0,     0,   981,     0,   337,
       0,     0,     0,     0,    23,  1019,  1304,     0,     0,   767,
     754,   765,   766,   752,   753,   761,   756,   760,   755,   764,
     759,   762,   758,   763,   751,   757,   750,   749,   992,   778,
     412,     0,  1024,     0,  1790,   723,   724,   361,     0,  1106,
       0,  1109,  1094,  1810,     0,     0,     0,     0,     0,     0,
       0,    63,    92,     0,     0,   116,   111,     0,   106,     0,
     113,   107,   851,   843,   849,     0,  1079,     0,  1081,  1083,
       0,     0,   924,     0,     0,     0,     0,  1034,  1199,  1755,
    1691,   940,  1692,   938,  1685,  1687,  1810,   630,   635,   638,
     651,   649,   610,     0,   699,   697,   703,   701,     0,     0,
     695,   739,   693,   689,   687,   737,   715,     0,   681,   691,
     934,   930,     0,     0,     0,     0,   656,     0,     0,     0,
       0,     0,     0,     0,  1514,     0,  1403,  1404,  1671,  1367,
    1425,     0,     0,  1669,     0,     0,  1608,  1609,  1607,  1589,
    1693,     0,  1350,  1356,  1355,  1354,  1358,     0,  1351,  1352,
       0,  1577,  1588,   551,   553,     0,     0,   566,   558,   560,
       0,   555,   556,     0,     0,   574,   576,     0,     0,   572,
     876,   816,   212,     0,     0,   224,  1141,   838,  1119,  1375,
    1377,     0,  1263,     0,     0,     0,     0,     0,  1253,     0,
       0,  1506,  1504,  1491,  1493,  1489,     0,  1488,     0,  1497,
    1484,  1505,     0,  1496,  1481,  1487,  1503,  1495,  1391,  1478,
    1479,  1480,     0,  1248,  1244,     0,     0,  1232,   615,     0,
       0,     0,     0,     0,  1796,     4,     8,    10,  1510,  1513,
       0,   469,     0,   501,   498,   497,   500,   496,     0,   421,
     507,   492,   492,     0,   515,     0,   519,     0,   282,  1177,
       0,  1534,   499,  1177,   506,   420,   266,     0,  1177,   480,
     477,   486,  1177,   483,  1177,  1177,  1177,     0,     0,     0,
       0,     0,     0,     0,     0,   471,    93,    94,    96,   473,
       0,     0,     0,   974,     0,     0,     0,     0,     0,     0,
       0,   186,   671,     0,   597,   599,     0,     0,   158,   156,
       0,     0,   138,     0,   148,   154,   679,   143,   145,     0,
     971,   982,   983,     0,   410,   336,   341,   595,   335,     0,
     338,   343,  1305,   539,   587,   585,   749,   744,   745,  1023,
    1025,     0,   408,   362,  1099,  1097,  1196,  1197,     0,     0,
    1190,     0,     0,     0,    99,     0,     0,    74,    80,    70,
    1810,  1810,   109,   104,   118,   114,     0,   108,   740,   852,
     610,  1810,   842,   841,   850,   976,     0,     0,   922,   923,
     917,   943,   469,     0,     0,  1632,  1524,  1527,  1633,  1531,
    1525,  1630,     0,     0,  1040,  1629,     0,     0,  1631,     0,
       0,     0,     0,     0,  1749,  1526,  1036,  1037,  1628,  1528,
    1620,  1039,  1615,  1618,  1619,     0,     0,     0,   661,   654,
     652,     0,    23,     0,  1810,  1810,  1810,  1810,   705,   683,
     707,   685,  1810,  1810,  1810,  1810,   749,   678,   682,  1810,
     610,   735,   733,   736,   734,     0,     0,    45,    43,    40,
      34,    38,    42,    37,    30,    39,     0,    33,    36,    31,
      41,    32,    44,    35,     0,    28,    46,   727,     0,   658,
    1651,     0,  1649,  1606,  1647,  1593,  1594,  1586,  1572,  1587,
       0,     0,     0,  1015,  1402,  1405,     0,     0,     0,     0,
    1426,  1316,  1288,  1674,  1673,  1672,     0,     0,     0,     0,
    1311,     0,  1310,     0,  1312,  1307,  1308,  1309,  1300,  1297,
       0,     0,  1357,     0,     0,     0,  1581,  1578,  1579,   565,
     570,     0,     0,  1810,  1810,   543,   557,   580,   568,   582,
    1810,  1810,   578,   562,   573,   807,   322,   206,     0,  1167,
    1186,   807,     0,  1174,  1167,     0,     0,  1260,     0,     0,
       0,     0,     0,  1431,  1433,  1435,  1473,  1472,  1471,  1437,
    1454,  1262,     0,  1515,     0,  1376,     0,  1379,  1518,     0,
    1383,     0,  1252,     0,     0,  1557,  1555,  1556,  1552,  1554,
    1551,  1553,     0,     0,     0,     0,     0,     0,     0,     0,
    1389,     0,  1392,  1393,     0,  1247,     0,  1241,  1243,  1751,
       0,     0,     0,  1798,     0,     0,  1224,   823,     0,   531,
       0,  1610,  1612,   489,     0,   490,     0,   529,     0,   526,
     523,   494,   488,  1115,  1542,  1114,     0,   170,  1113,     0,
       0,     0,  1116,     0,  1118,  1117,  1111,   448,   449,   453,
     438,     0,   441,   452,     0,   440,     0,     0,    92,     0,
       0,     0,     0,  1275,  1803,  1802,   594,     0,     0,    47,
       0,   676,   675,   674,  1276,     0,     0,   679,  1810,  1810,
     150,   618,   160,   152,   162,   142,   149,  1810,     0,     0,
       0,     0,     0,     0,     0,  1810,     0,   747,   610,     0,
    1777,     0,    92,     0,    64,     0,     0,     0,    77,     0,
      92,    92,   117,   112,  1810,  1810,   102,   749,   853,   847,
     855,   854,   844,   535,   903,     0,     0,  1617,  1616,  1530,
       0,  1606,     0,     0,  1474,     0,  1474,  1474,  1474,  1474,
    1621,     0,     0,     0,     0,     0,     0,  1675,  1676,  1677,
    1678,  1679,  1680,  1624,  1756,   941,   939,   664,   662,     0,
     641,   655,   611,   716,     0,   700,   698,   704,   702,     0,
    1810,     0,  1810,   696,   694,   690,   688,   738,   692,    23,
     728,     0,     0,     0,    26,     0,  1654,     0,  1576,     0,
       0,  1585,  1568,  1584,  1406,     0,  1369,     0,  1315,  1413,
       0,     0,  1670,     0,  1667,  1590,     0,     0,     0,     0,
       0,     0,  1694,  1314,  1313,  1301,  1299,     0,  1360,     0,
    1353,     0,     0,     0,     0,   567,   564,   559,   561,     0,
    1810,  1810,   575,   577,  1810,  1810,     0,     0,  1165,  1166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1164,     0,     0,  1152,  1153,  1154,  1151,  1156,  1157,
    1158,  1155,  1142,  1133,     0,     0,  1189,     0,  1810,     0,
    1128,     0,     0,     0,     0,     0,     0,     0,  1120,  1121,
       0,  1053,     0,  1264,     0,  1440,     0,  1454,  1439,  1436,
       0,  1401,     0,  1468,  1465,  1466,  1463,  1470,  1469,  1464,
    1467,  1645,     0,  1645,  1455,     0,     0,     0,  1519,     0,
    1520,     0,     0,     0,     0,  1382,  1254,  1381,  1373,     0,
       0,     0,  1508,  1500,  1500,     0,     0,  1500,  1507,     0,
    1524,  1388,  1390,  1394,  1395,  1249,  1245,   989,     0,   952,
       9,     0,  1217,   824,  1050,     0,     0,  1425,  1596,  1613,
       0,   492,   520,     0,   275,   481,   478,   487,   484,     0,
     443,   442,   472,    95,   474,   348,  1211,     0,     0,  1794,
       0,     0,   957,    48,     0,   601,   603,   598,   725,   159,
     157,     0,  1810,     0,     0,     0,  1810,   155,   144,     0,
     147,   146,     0,   963,   967,   340,     0,  1306,     0,   749,
     746,    23,  1100,     0,  1191,    69,     0,     0,   100,    67,
      92,    75,    81,     0,   119,   115,   741,  1810,   857,   610,
     856,     0,   532,     0,   772,   773,   771,     0,     0,  1641,
       0,     0,     0,  1476,  1477,  1475,     0,  1643,     0,     0,
       0,     0,     0,     0,     0,  1038,  1626,  1627,  1623,  1625,
       0,  1810,   660,   645,   642,     0,   706,   684,   708,   686,
     717,   731,   732,   729,   730,    29,    27,     0,  1648,  1602,
    1573,  1574,  1570,  1576,     0,  1368,  1606,  1371,     0,  1290,
    1285,  1284,  1287,     0,  1602,     0,     0,  1727,  1725,     0,
       0,  1713,  1724,     0,     0,  1726,     0,     0,     0,     0,
       0,  1749,  1723,  1719,     0,  1711,  1714,  1715,  1722,  1718,
    1742,     0,  1704,  1703,  1707,  1709,     0,  1702,     0,  1705,
    1696,  1302,  1298,     0,  1359,     0,     0,  1582,  1580,   571,
     569,   581,   583,   579,     0,     0,   229,  1159,  1160,  1161,
    1163,  1146,  1144,  1143,  1147,  1148,  1145,  1162,  1149,  1150,
    1134,   949,  1169,   946,     0,     0,  1187,     0,  1132,  1131,
    1126,  1124,  1123,  1127,  1125,  1129,  1130,  1122,  1175,  1378,
    1438,  1432,  1434,  1444,  1441,  1646,  1443,     0,  1449,  1441,
       0,  1447,  1645,  1457,  1456,     0,  1458,     0,  1374,  1380,
    1522,  1515,  1384,  1564,  1562,  1563,  1559,  1561,  1558,  1560,
    1490,     0,  1492,     0,     0,     0,     0,  1498,  1502,     0,
    1482,  1396,   988,  1225,  1218,  1214,  1611,     0,  1414,  1415,
    1417,  1420,  1427,     0,     0,  1474,  1598,  1592,  1549,  1547,
    1548,  1544,  1546,  1543,  1545,   493,   491,     0,   525,   524,
     172,   439,     0,     0,    23,     0,     0,   980,     0,    49,
     960,     0,    23,   161,   151,     0,   620,   622,   163,   153,
     725,     0,   339,   540,   748,  1021,     0,     0,    65,     0,
      78,    87,     0,    71,   848,   845,   536,  1810,   918,  1532,
       0,     0,     0,     0,  1642,     0,     0,  1640,     0,     0,
       0,     0,  1622,  1639,     0,   663,   640,   646,   610,  1658,
       0,  1656,     0,     0,  1576,  1576,  1569,  1370,     0,  1372,
    1366,     0,  1289,     0,  1668,     0,  1717,  1716,     0,     0,
    1474,     0,  1474,  1474,  1474,  1474,  1720,     0,     0,  1700,
       0,     0,     0,     0,  1729,  1701,     0,     0,     0,     0,
       0,     0,  1695,     0,  1361,  1364,  1348,  1362,  1365,     0,
     818,   817,   323,   207,   951,   950,   948,     0,  1168,  1054,
    1058,  1060,     0,  1064,     0,  1062,  1066,  1055,  1056,     0,
     839,     0,  1645,  1461,     0,  1450,  1453,  1452,  1460,     0,
    1441,     0,     0,  1516,  1521,     0,  1509,  1501,  1485,  1483,
       0,  1486,     0,  1418,     0,  1523,  1421,     0,  1428,  1429,
    1601,  1217,     0,     0,     0,     0,   522,   521,   475,   349,
     346,     0,   978,     0,     0,     0,   959,   726,   139,   619,
      23,   969,  1026,    66,  1192,    83,     0,     0,    76,    87,
      87,  1810,   533,     0,     0,     0,     0,     0,  1638,  1644,
    1634,  1635,  1636,  1637,   665,   718,     0,  1655,  1603,  1596,
    1575,  1571,     0,  1291,     0,  1596,  1740,     0,     0,  1743,
       0,     0,     0,     0,     0,     0,     0,  1712,  1731,  1732,
    1728,  1730,  1710,     0,  1706,  1708,  1697,  1698,  1303,     0,
    1349,  1347,  1583,   947,  1810,  1810,  1068,  1810,  1070,  1810,
    1810,  1057,  1188,  1176,  1442,  1445,     0,  1448,  1446,  1462,
       0,     0,     0,  1499,  1422,     0,  1416,  1410,  1411,  1614,
       0,  1430,  1424,  1599,  1321,  1317,  1318,  1323,  1322,  1597,
    1217,     0,   351,   979,  1793,     0,     0,     0,     0,     0,
       0,    54,     0,    53,     0,    51,     0,     0,   140,  1030,
    1022,     0,  1028,    87,    92,    87,    88,    82,    72,   846,
       0,     0,  1605,     0,  1683,     0,  1810,    23,  1657,  1595,
    1604,  1295,     0,  1292,  1294,  1591,  1741,     0,     0,  1739,
       0,     0,     0,     0,  1721,  1738,     0,  1363,  1059,  1061,
    1810,  1065,  1810,  1063,  1067,  1451,  1459,  1517,  1494,     0,
    1419,     0,  1409,     0,  1325,  1324,  1320,  1600,  1550,   357,
     355,   347,     0,   353,   359,    56,    61,    58,    60,    57,
      59,    55,     0,    50,     0,   621,   623,  1810,  1027,  1029,
    1193,    84,    79,   534,   919,  1681,  1682,   661,   719,     0,
    1286,  1737,  1744,  1733,  1734,  1735,  1736,     0,  1069,  1071,
    1423,  1412,  1319,  1810,  1810,   352,   354,  1810,    52,     0,
    1031,     0,   666,  1293,  1699,   358,   356,   360,     0,    85,
     961,    89,    91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   552,   553,   554,   555,   711,  1735,  1736,   189,   264,
     190,  1133,  1134,  1623,  1964,  3023,  2462,  2463,  2904,  3024,
    3025,   556,   900,  2496,  2201,  2920,  1562,  2199,  2761,  2500,
    2916,  2200,  2762,  3034,  3141,  3151,  2918,  3154,  1785,  1786,
    1787,  1233,  1853,   557,  1244,   905,  1242,  1570,  1863,  1567,
    1861,  1866,  2205,  1243,  1860,  1571,  2204,   558,    17,    36,
      37,    38,    39,    40,   114,   561,   827,  1501,  1160,  1812,
    1816,  1817,  1813,  1814,  2472,  2476,  2177,  2169,  2168,  2170,
    2173,  1115,  1066,  1767,   562,    83,    84,    19,    62,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     679,  2327,   305,   660,  1683,   332,   333,   229,   287,   280,
     282,   985,   986,   146,   355,   147,   148,   293,   230,   231,
    1487,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   663,   247,   248,   323,   375,   196,    20,    80,   178,
     179,   180,   669,  2326,   181,   251,   240,   326,   327,   328,
     329,  1514,   563,   564,   565,   566,   784,  3012,  2734,  1135,
    3091,  3092,  3093,  3134,  3133,  3137,   567,   568,   569,   570,
     760,  1116,   867,  1202,  1203,  1170,   864,  1171,   762,   763,
     764,   765,   766,   767,   768,  1069,  1117,  2141,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,   716,   769,  1467,  2146,  2148,
    2732,   770,  1437,  2130,  1436,  2129,  1440,  2133,  1438,  2131,
    2113,  2122,   771,   772,   773,   774,  1421,  1422,  1423,  1424,
    1405,   571,  2767,  3040,  2512,   572,   837,  1516,  2185,   115,
     237,   365,  1335,   966,   967,   968,  1332,  1333,  1670,  1671,
    1672,  2023,  2024,  1336,  1337,  1666,  2027,  2019,  1678,  1679,
    2030,  2031,  2324,  2320,  2321,   573,  1177,    85,  1482,  1483,
    1828,   869,   817,   872,   694,   806,   789,   828,  1922,    86,
     695,   689,  1385,  2172,    87,   776,   574,   575,   921,   922,
     576,   577,   578,   579,   929,  2543,   950,  2786,   951,  1600,
     952,  1919,   953,  2250,   954,  1626,   580,  1596,  2249,  2541,
    2540,  3046,   116,    21,   581,  1151,  1488,  1489,  1616,  1282,
    1617,  1618,  2260,  2262,  1935,  1934,  1939,  1933,  1932,  1925,
    1924,  1927,  1926,  1929,  1931,   582,   583,   825,   584,  1278,
     936,  3047,   585,  1210,  2742,  1966,  1967,  1619,  1936,  1869,
    2207,   860,  1187,  1537,  1837,  2186,  1838,  1183,  1536,   586,
     587,   914,  1585,  2516,   588,   589,   590,   591,    22,    66,
      23,    24,    25,   117,   118,   592,   119,    26,   650,    27,
     120,   121,   158,   367,  1341,  2035,  2841,   122,   154,   298,
     593,  2108,    28,    29,    30,    31,    32,    61,    88,   123,
     413,  1350,  2041,   594,   909,  1873,  1574,  1871,  2921,  2507,
    1575,  1870,  2210,  2509,   595,   596,   597,   800,   801,  1246,
     124,   238,   366,   654,   655,   970,  1339,   598,   955,   956,
     599,   833,  1290,   957,   777,    90,    91,    92,    93,  1253,
     184,   138,    94,   700,   135,   192,   193,  1254,  1255,  1880,
    1256,   410,   411,   938,   412,   939,  1592,  1593,  1257,  1258,
    1131,  2642,  2643,  2846,  1394,   815,   816,   600,  1146,  2906,
     601,  2484,   602,  1164,  1165,  1166,  1507,  1505,   603,   604,
    1793,  1823,   605,  1018,  1391,   606,   861,   862,   607,   877,
     608,  1977,   609,  2912,   610,  1841,  3030,  3031,  3032,  3107,
     866,   611,  1259,  1587,  1906,  1907,   612,  1475,   693,  1030,
     613,   614,   615,  2043,  2646,  2857,  2858,  2974,  2975,  2979,
    2977,  2980,  3070,  3072,   616,   617,  1248,  1579,   618,  1250,
     885,   886,   887,  1226,   619,   620,   621,  1549,  1218,   880,
     199,   888,   889,   778,  2044,  2368,  2369,  2352,   719,   720,
    2039,  2353,  2356,   125,   153,   359,   995,  1688,  2370,  2861,
    1039,   622,   878,   126,   150,   356,   992,  1686,  2357,  2859,
    2040,   904,  2192,  2757,  3033,  1221,   623,   624,   625,   626,
     627,   787,  1791,   713,  1740,   628,  2705,   707,   708,  2105,
    1370,   629,   630,  1004,  1005,  1006,  1382,  1725,  1007,  1722,
    1379,  1008,  1697,  1371,  1009,  1010,  1011,  1012,  1691,  1362,
     631,   796,   779,   632,  1313,  1314,  1641,  2571,  2803,  2291,
    2568,  3052,  3053,  1315,  1651,  2305,  2009,  2612,  2833,  1833,
    2184,  2010,  1316,  1317,  2716,  3005,  3006,  3007,  3086,  1318,
    1319,  1168,   633,   831,   634,   963,  1320,  1321,  2971,  1657,
    1658,  1659,  2012,  2307,  2836,  2837,  1322,  1987,  2285,  2800,
    1372,  1373,  1358,  2064,  1689,  2065,  1374,  2069,  1375,  2092,
    1376,  2093,  2422,  2423,  1692,  1323,  1635,  1636,  1984,  1324,
    3001,  2888,  2997,  1990,  2437,  2708,  2709,  2710,  2995,  2438,
    1991,  2889,  3002,  2052,  2053,  2054,  2055,  2056,  2863,  2664,
    2984,  2057,  2864,  2865,  2396,  2058,  2397,  2059,  2526,  1718,
    1719,  1720,  2694,  1721,  2419,  2413,  2877,  2066,  2838,  2400,
    2604,  2068,  2886,  1908,   780,  1909,  2219,  1057,  2114,  2725,
    2082,  2690,    60,   635,   636,  2563,  2795,  2278,  2794,  1662,
    2017,  2018,  2282,  1978,  1325,  1979,  1998,  2574,  1413,  1974,
    1975,  2717,  2891,  2793,  2567,  1910,  1649,  2110,  2111,  2998,
    2060,  1912,  1913,  2528,  2666,   637,   638,  1628,  1976,  2558,
    2790,  2791,  1293,   639,   782,  1327,  1328,  1644,  2293,  1329,
    1330,  1995,  2243,  2522,   640,   917,  1267,  1268,  1269,  1270,
    1331,  1999,  2610,  2832,  2302,  2607,  2608,  2609,  2606,  2594,
    2595,  2596,  2597,  2598,  2599,  2950,   701,  1589,   703,  1395,
    1914,    64,    49,    78,    75,   642,   891,  1553,  1154,  1212,
     643,   870,   644,  2159,   645,  1734,   705,  1397,   646,   647,
      43,   360,   361,   362,   363,   364,   648
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2387
static const short yypact[] =
{
    3000,   960, -2387, -2387,   327,   480,   480,   480,   480,   480,
     480,   480,   480,   327,  1131, -2387, -2387, -2387,  2304, -2387,
   -2387, -2387,   366, -2387,  3000, -2387, -2387, -2387, -2387, -2387,
    2740, -2387, -2387, -2387, -2387, -2387,   359,   373, -2387,   412,
   -2387, -2387, -2387, -2387, -2387,   327,    62, -2387,  -183, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,  2599,   223, -2387, -2387, -2387,  2944, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,   327, -2387, -2387,    62,
    -113, -2387,   327,   561,  2304, -2387,   873, -2387, -2387, -2387,
   -2387,   958,   204, -2387, -2387, -2387,   843,   507,   327, -2387,
   -2387,   900,   327, -2387, -2387,   327,   327, -2387, -2387, -2387,
   -2387,   327,   327, -2387, -2387, -2387, -2387, -2387,  2944, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
    5015,   204, -2387,   791,   380, -2387, -2387,   489, -2387, -2387,
     909,   223,   476, -2387, -2387, -2387, -2387, -2387,  7546, -2387,
     327,   538,   903,   327,  2304, -2387, -2387, -2387,   327, -2387,
   -2387,   495,   553, -2387, -2387,   617, -2387,   645, -2387,   641,
   -2387, -2387,   673, -2387,   686, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387,   706, -2387, -2387, -2387,   380,  1516,
    1175, -2387,   164, -2387,   380, -2387,   170, -2387, -2387, -2387,
      92, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,   495,
   -2387,   553, -2387, -2387,   781, -2387,   802, -2387,   716, -2387,
   -2387,   829, -2387,   839, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,   846,  1246,   327,   850, -2387,  2304,  2304,   853,
     327, -2387,   519, -2387,   689,   832, -2387,   696,   994,  1307,
    1321,   327,  1325,  1344,  1375, -2387,   785, -2387,   988, -2387,
   -2387, -2387, -2387, -2387,   380, -2387,   380,   953,   250, -2387,
   -2387, -2387,  1389, -2387, -2387,  1392, -2387, -2387, -2387, -2387,
   -2387,   519, -2387, -2387, -2387,  1395,  1419,   223,  1325,  1425,
    1430,   849, -2387,  1408, -2387,  1094,  1048, -2387,  1128, -2387,
   -2387, -2387,   880, -2387, -2387,  1490, -2387,  1095, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387,   994,  1095, -2387, -2387, -2387,
   -2387, -2387, -2387,  1099,   192,   216,   351, -2387,  1488, -2387,
   -2387, -2387,  1114,  1546,   224,  1171, -2387, -2387,  1516, -2387,
     380,  1122, -2387, -2387,   962,  1550,  1328,   233,   238,   455,
    1183,   271,  1206, -2387, -2387, -2387,   327, -2387, -2387,   327,
    1240, -2387,  4009,   476,  4974,  1822,  -303,   327,  1588,   588,
   -2387,   832,  1584, -2387, -2387, -2387, -2387,  1592, -2387,  1595,
   -2387,  1596, -2387,   327, -2387,   327, -2387, -2387,  1325,  1597,
   -2387, -2387, -2387, -2387,   251,   380,  1606,   588,  1196,  1602,
   -2387,  1610, -2387, -2387, -2387,  1611, -2387, -2387, -2387,  1034,
    1249,  1650, -2387,   327,  1269, -2387, -2387, -2387,   327,   253,
     327,   327,   253,   253,   882,   327, -2387,   327, -2387, -2387,
     327, -2387,   872, -2387, -2387, -2387,   253, -2387, -2387, -2387,
   -2387,   327, -2387, -2387, -2387, -2387,   118,   118,  7416, -2387,
   -2387, -2387, -2387, -2387,   253, -2387, -2387,   253, -2387, -2387,
     327, -2387, -2387,   253, -2387, -2387,   875,   253, -2387, -2387,
    7416,   253,   875,   327,   875,   253, -2387, -2387,   102,   253,
     253,   102,   253,   327,   102,   253, -2387,   253,   253,   253,
   -2387, -2387, -2387, -2387,   875,   253, -2387, -2387,   253,    57,
     327, -2387, -2387, -2387, -2387,   253,   939, -2387, -2387, -2387,
     253, -2387,  8104,   875,  7416, -2387,    48,    48,   253, -2387,
   -2387,  1006,   875,  1072,  7416,  7416, -2387,  1687,  7416,   253,
      62, -2387,  7416,   253,  7416,   875, -2387,   253,  7416, -2387,
    7416,   118,   327,   253,   327,    48,   253,   327,    48, -2387,
     327,   408, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,   113,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,   710,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
     863, -2387,   327, -2387,   537, -2387,  1270, -2387, -2387, -2387,
    1366, -2387, -2387,  1274,  1278,  1285,  1291, -2387, -2387,  1058,
    1677,  1294, -2387,   268, -2387,  1386, -2387,  1299,  1304,  1064,
    1305,   327, -2387,   327,  1308, -2387,   409,  1262, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1079,  1363,  1243,
   -2387,  1084, -2387,  1088, -2387,  1695,  -210,   302, -2387, -2387,
   -2387,  1284, -2387,  1402, -2387,  1232,   140, -2387, -2387, -2387,
    1387, -2387,  7416,  7416, -2387, -2387,  1290,  1195,  1292,  1293,
    1296,  1302,  1303,  1306,  1311,  1312,  1314,  7416,  1060,  1317,
    1319,  1320, -2387,  7416,  7416,  1334,  1335, -2387,  7416,  1336,
   -2387,  1337,  1339,  1345,  1346,  1347,  1349,  1350,  7416,  1353,
    6368, -2387,   127, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387,   747, -2387,  1309, -2387, -2387,
   -2387, -2387, -2387, -2387,   875, -2387, -2387,  1402, -2387,    -8,
   -2387, -2387,  1468, -2387,    72, -2387,  1276, -2387, -2387, -2387,
   -2387,  1748, -2387, -2387,   309, -2387,  1139, -2387,  1165,  1748,
   -2387,  1194, -2387, -2387,  1371,   115, -2387,  1338, -2387,  1140,
   -2387, -2387,  1372, -2387,  -148, -2387,  1150,   612,   326, -2387,
    1079,  1496, -2387,  7416,  7416, -2387,  1803,   253, -2387, -2387,
   -2387, -2387, -2387,   266,   266,   266, -2387,   266, -2387,   266,
     266,  1226,    -8,  1226,  1226,  1111,  1111,  1226,  1226,    -8,
   -2387,  1817, -2387,    20,  1818, -2387,    -8, -2387,  6908, -2387,
      81,    61, -2387, -2387,  7416, -2387, -2387, -2387, -2387, -2387,
    1032, -2387, -2387,   476,  1443,   476,  7416, -2387,    64, -2387,
   -2387,  7416,  1398,  1399,  1400,  1401,  1427,  1403,  1072,  1339,
   -2387,  1497,   777,  1242, -2387,  1267, -2387, -2387, -2387,  1119,
   -2387,  1830, -2387,  1837,   327, -2387,   -10,   101,  1280, -2387,
   -2387,  1851, -2387,  1199,  1851,  1853,  1201,  1851,  1853,  7416,
    1851, -2387, -2387,   140,   875, -2387, -2387,  1442,   279, -2387,
   -2387,  1438,   875,  7416,  1441, -2387, -2387,  1848,  1857,  1812,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1147,  1147,
     253,   253,   253,  2516, -2387, -2387,  1794,   863, -2387, -2387,
     784, -2387, -2387, -2387,  1429, -2387, -2387, -2387, -2387,  5015,
    1325, -2387, -2387,  1433, -2387,   312, -2387, -2387, -2387, -2387,
   -2387, -2387,  2304, -2387, -2387,  2304,   811,   181,  1861, -2387,
   -2387,   625,   226,   708,  1887, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387,  1448,  1363,  1088, -2387,   882,  -175,  1042,
     327, -2387, -2387,   327, -2387,  1318,  1277,  1310,  1467, -2387,
    1469,    95, -2387, -2387, -2387,  6804,  6804,    48,  7416, -2387,
      48,    48,    48,    48,  1432,  7416,  1495,  1653,  7416,  6368,
    1474, -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1281,    48,
    1885,  7416,  4384,  6368,  1432,  7416, -2387,  6368,  1888,   459,
   -2387, -2387, -2387,  7416, -2387,  7416,  7416,  6368,  7416,  7416,
    7416,  7416,  7416,  7416,  7416,  7416,  7416,  7416,  7416,  7416,
    7416,  7416,  7416,  7416,  7416,  7416, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,  7416,  7416, -2387, -2387,
    1482,  7416, -2387,  7416,  1485, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,   327,   875,
   -2387,  1295,  1486, -2387, -2387, -2387,   882,  1191, -2387,  1191,
    1072,   102,  7416,  7416,  7416,  1489, -2387, -2387,   875,   875,
   -2387,  1329,  1072,    48,  1255,   327,   380,    59,    57,   875,
   -2387,  1300,  7416,  1583, -2387, -2387,  1377, -2387, -2387,  1818,
     104, -2387,   140, -2387, -2387,  1916,  1923, -2387, -2387, -2387,
   -2387, -2387, -2387,   335, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,  8104, -2387,  1111,  7416,
     262, -2387, -2387,  1937, -2387,    48,  1920,  1928, -2387, -2387,
   -2387, -2387, -2387,    99, -2387, -2387, -2387, -2387,  1804, -2387,
    1740, -2387, -2387, -2387,  7416,   118, -2387, -2387,   327,  1935,
      48,    48, -2387,  1373, -2387,    48,  1341,   875, -2387,   327,
     327,  7416,    35, -2387,  1393, -2387,   293, -2387,  1484, -2387,
    1492,  7416,  1087, -2387, -2387,  1352, -2387,  1961, -2387,  1431,
   -2387,   875, -2387, -2387, -2387,   882,   875,   151, -2387, -2387,
   -2387, -2387,   327,    48,    48,   252,   279,  1828,  1357,   875,
     140, -2387,  1434, -2387, -2387,  1973,  1955,  1587, -2387, -2387,
   -2387, -2387, -2387,  1668,  1668,   290,  1444, -2387,   327, -2387,
   -2387,  1402,  1402, -2387, -2387, -2387,   327, -2387,   327,   -87,
    1402, -2387,   672, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,  1261, -2387, -2387, -2387,
   -2387, -2387,   171,   171,   646,   914, -2387,   728, -2387,   784,
   -2387,  2304,  1966, -2387, -2387,  1966, -2387, -2387, -2387, -2387,
    2304, -2387, -2387,  1402, -2387,   748, -2387,  1568, -2387, -2387,
     748, -2387, -2387, -2387,  1574,  1576,   214,  1582,  1585,  2433,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   327, -2387, -2387,
     214,  1348, -2387,   409, -2387,  1625,   204,  1396, -2387,  1072,
    1445, -2387, -2387,  1560, -2387, -2387, -2387,  1472, -2387,   327,
     327,   327, -2387, -2387, -2387,   328, -2387,  6368,  1632,  1636,
     342,   368,   -87,  1637,  4584,  1638,   -46,  1000, -2387, -2387,
      71,  1646, -2387, -2387, -2387,  4779,  2011,  1060,  1648,  1655,
    5598, -2387,  1659,  3273,  1660, -2387,  7416,  7416,  7416,  5633,
    7416,  5662,  5768,  5797,  6419,  4440,  6247,  6468,  6532,  6634,
    3375,  6668,  4606,  6795,  1231,  6804,  6804,  3092,  6903,  2505,
    6368,  5918,  6083,  1432,  6368,  6218,  1432,  7416,  1623, -2387,
     327, -2387,  1423, -2387, -2387, -2387, -2387,  1428, -2387,  2047,
    2050, -2387,  2057,  1478,  7416, -2387, -2387,  1446,  2058, -2387,
    1589,  1439,  1853, -2387,  1683,   466, -2387,  1645, -2387, -2387,
    1454,  1063,   327, -2387, -2387,  1651,   253,   918,  7416, -2387,
     327,   327,  7416,    47,    -8,  2061,  1530,  2056,  2060, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1658, -2387, -2387,
   -2387,   875,  1553,  6908, -2387, -2387, -2387,  2024,  7416,   476,
     905, -2387, -2387,  1766,  2088,  2089,   375,   378,   327,  1707,
    1072, -2387,  7416,  1669,  1670, -2387, -2387,  1743, -2387,  7416,
     414, -2387,  1504, -2387, -2387,   547, -2387,  7416, -2387, -2387,
    1477,   791, -2387,  1108,   327,  2091,  4873, -2387, -2387,  1689,
   -2387,  1691,  2114, -2387, -2387, -2387,    36, -2387,  1853,  1853,
    1461, -2387,  1572,  1577, -2387, -2387, -2387, -2387,    48,    48,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1330, -2387, -2387,
   -2387, -2387,    48,  3681,  2118,  2100, -2387,  1072,   744,   220,
     180,  2027,    40,  1006, -2387,     6, -2387, -2387, -2387,  1699,
      65,  1402,   169, -2387,  1509,  1505, -2387, -2387, -2387, -2387,
   -2387,   142, -2387, -2387, -2387, -2387,  1709,  1514,  2134, -2387,
    1460, -2387, -2387, -2387, -2387,   875,   119, -2387, -2387, -2387,
    1502,   914, -2387,   327,   327, -2387, -2387,   327,   543, -2387,
   -2387, -2387, -2387,  1717,  1728, -2387,  1696, -2387,  1697, -2387,
    1729,   399, -2387,  7585,   410,   121,   121,   413, -2387,   121,
    7585, -2387, -2387,  1121,  1121, -2387,  1730, -2387,  1732,  1736,
   -2387,  1737,  1738, -2387,  1739, -2387, -2387, -2387,   650, -2387,
   -2387, -2387,   417, -2387, -2387,   425,   327, -2387, -2387,  1042,
    2155,  1072,   380,  7416, -2387,  2163, -2387, -2387, -2387, -2387,
     214, -2387,    48, -2387, -2387, -2387, -2387, -2387,  7727, -2387,
   -2387,  1060,  1060,  2144, -2387,  2145,  1591,  1487, -2387,  1195,
    1782, -2387, -2387,  1195, -2387, -2387, -2387,  1783,  1195,  6368,
    6368,  6368,  1195,  6368,  1195,  1195,  1195,  2149,  2151,  2153,
    7416,  1791,  2157,  7416,  1793, -2387,  2178, -2387,  6368, -2387,
    1565,   214,   152, -2387,  1072,  7416,  7416,  7416,  7053,  2181,
     185, -2387, -2387,  1072, -2387,  1571,   327,   327, -2387, -2387,
     327,   327, -2387,  1130, -2387, -2387,   352, -2387,  1575,  7416,
   -2387, -2387, -2387,  2183, -2387, -2387, -2387, -2387, -2387,   327,
    1853, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,   875, -2387, -2387,  3907, -2387, -2387, -2387,  1870,  2171,
   -2387,  1858,  1863,  1747,  1580,  1864,  1779, -2387, -2387, -2387,
     554,  1850, -2387, -2387, -2387, -2387,  1743, -2387, -2387, -2387,
     211,   596, -2387, -2387, -2387,  1973,  7416,  1786, -2387,  1755,
   -2387, -2387, -2387,  7946,  7946, -2387,  1079, -2387, -2387,  1121,
   -2387, -2387,  7189,  1785, -2387, -2387,  1787,  1789, -2387,  1790,
    1796,  1797,  1813,   327,   -98, -2387,  2209, -2387, -2387, -2387,
   -2387, -2387,  1741, -2387, -2387,   882,   875,   875,    83,  1590,
   -2387,  2197,    -8,   327,  1735,  1735,  1735,  1735, -2387,  2237,
   -2387,  2239,  1735,  1735,  1735,  1735,  1658, -2387, -2387,  1735,
     116, -2387, -2387, -2387, -2387,  2226,  2238, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,  2240, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387,   431, -2387, -2387, -2387,  2227, -2387,
   -2387,  1402, -2387,   -87, -2387, -2387, -2387, -2387, -2387, -2387,
    1664,  1665,   129, -2387,     6, -2387,   121,  1644,   253,  7585,
   -2387, -2387,  1826, -2387, -2387, -2387,   327,   327,  7727,   344,
   -2387,  7416, -2387,  7416, -2387, -2387, -2387, -2387, -2387, -2387,
     253,   121, -2387,  1402,   980,  1642,  1647,  2258, -2387,  2259,
   -2387,   875,   327,   719,   719, -2387, -2387,  2260, -2387,  2260,
     545,   545,  2260, -2387, -2387,  1822, -2387, -2387,  3559,    75,
   -2387,  1822,  1343, -2387,    75,   121,   748, -2387,  1840,  7506,
    1840,  2051,   257,  2262, -2387, -2387, -2387, -2387, -2387, -2387,
     434, -2387,  1402,   800,  1883,  2270,  1661, -2387, -2387,   435,
   -2387,   214, -2387,   446,   289, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,  1652,   -26,  2253,  2253,  2254,  2253,  2253,  2257,
   -2387,   156, -2387,   748,   327, -2387,   214, -2387, -2387,  1666,
    1072,  2275,   276, -2387,   327,   453, -2387,  7416,  1895, -2387,
     122, -2387,   327, -2387,  1662, -2387,  1899, -2387,  2265, -2387,
    1703, -2387, -2387, -2387, -2387, -2387,  1674, -2387, -2387,  1911,
    1912,  1913, -2387,  1914, -2387, -2387, -2387, -2387, -2387, -2387,
    6368,   457, -2387, -2387,   458, -2387,  1915,  7416,  7416,  2285,
     462,  1072,  2301, -2387, -2387, -2387, -2387,  7416,  1745,  2039,
    7416, -2387, -2387, -2387, -2387,  1184,  1924,   352,  1186,  1186,
    2307,  -142, -2387,  2309, -2387, -2387, -2387,  1186,   327,  1772,
    1203,  2313,   327,  -100,   875,  2081,   463, -2387,  1572,  7416,
   -2387,  2315,  7416,   875, -2387,   872,   327,   875, -2387,  1932,
    7416,  7416, -2387, -2387,   554,  1850, -2387,  1658, -2387, -2387,
    1264, -2387, -2387,  1752, -2387,   380,  7329,  1938,  1938, -2387,
    1698,   -87,  1936,    79,   -22,  7727,   -22,   -22,   -22,   -22,
    1705,  7727,  4873,  7727,  7727,  7727,  7727, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1890,
     921, -2387, -2387, -2387,  1710, -2387, -2387, -2387, -2387,    48,
    1735,    48,  1735, -2387, -2387, -2387, -2387, -2387, -2387,    -8,
   -2387,   934,   956,  3681, -2387,  1941,  1903,  7727,  1261,   180,
     180, -2387, -2387, -2387, -2387,   468, -2387,  1866, -2387,  2327,
     121,   683, -2387,  1711, -2387,  2332,  7807,  7807,  7807,  7807,
     121,   121, -2387, -2387, -2387,  1788, -2387,   470, -2387,  1713,
   -2387,   327,   327,  1460,   875, -2387,  2260, -2387, -2387,   327,
     545,   545, -2387, -2387,   545,  2131,  1719,  1721, -2387, -2387,
     118,   118,   118,  2321,   118,   118,   118,   118,   118,   118,
    2322, -2387,  2330,   118, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,  3559, -2387,   875,  1733, -2387,  1919,  2131,  2331,
   -2387,  2333,  2334,  2335,  2339,  2340,  2341,  1289,  1343, -2387,
    1919, -2387,   473, -2387,  1889, -2387,   319,   203, -2387, -2387,
    7585, -2387,  7585, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,   208,  1939,   208, -2387,  1940,   585,  7727, -2387,  2344,
   -2387,  2062,   121,  1233,   121, -2387, -2387, -2387, -2387,  1298,
    2345,  1298, -2387,  2366,  2366,   477,  1984,  2366, -2387,  1985,
   -2387, -2387, -2387,   748, -2387, -2387, -2387, -2387,  1072, -2387,
   -2387,   214,  2109,  1973, -2387,  7727,   225,  1855,   508, -2387,
    1301,  1060,  1792,  1491, -2387, -2387, -2387, -2387, -2387,  7416,
   -2387, -2387, -2387, -2387, -2387,  1917, -2387,   255,  1072, -2387,
    2372,  1953, -2387, -2387,  1993, -2387, -2387, -2387,  1836, -2387,
   -2387,   327,  1186,   380,  1316,   327,  1186, -2387, -2387,    48,
   -2387, -2387,  7416, -2387, -2387, -2387,    48,  2114,  2148, -2387,
   -2387,    -8,  6368,  2364, -2387, -2387,   140,  1968, -2387, -2387,
    7416, -2387, -2387,  2001, -2387, -2387, -2387,   596, -2387,  1572,
   -2387,  7416, -2387,   281, -2387,  1818, -2387,  1298,  7727, -2387,
     329,  2389,  2006, -2387, -2387, -2387,  7727, -2387,   483,  7727,
    7727,  7727,  7727,   327,   486, -2387, -2387, -2387, -2387, -2387,
    7416,  1958, -2387,  2055, -2387,  2381, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   327, -2387,    88,
   -2387, -2387, -2387,  1261,   121, -2387,   -87,  2264,   494, -2387,
   -2387, -2387, -2387,   327,  1852,   977,   977, -2387, -2387,  7862,
    1975, -2387, -2387,  1977,  1978, -2387,  1979,  1981,  1982,  1983,
     327,   -91, -2387, -2387,   506, -2387, -2387,  1844, -2387, -2387,
   -2387,   510,  2407,  2407, -2387, -2387,   511,  2408,  2401, -2387,
     206, -2387, -2387,   121, -2387,   176,  1798, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387,  2207,  5015, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,  -176,  2411, -2387,   875,  1065, -2387,  2207, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,  2262, -2387, -2387,  1980, -2387, -2387,   162, -2387,  1980,
     162, -2387,   208, -2387, -2387,  7727, -2387,   291, -2387, -2387,
   -2387,  1962, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,  2031, -2387,  2396,  2033,  2034,  2399, -2387, -2387,  2041,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   245,  2429, -2387,
   -2387,   327,  2069,   327,  1819,   -22,  2107, -2387,  2010, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1501, -2387, -2387,
   -2387,  6368,  2052,    48,    -8,  2071,  1072, -2387,  7416, -2387,
    1872,  2418,    -8, -2387, -2387,   487, -2387, -2387, -2387, -2387,
     120,  2059,  1853, -2387, -2387, -2387,  2063,  2064,  2061,  2018,
   -2387,  2105,  2066, -2387, -2387, -2387, -2387,  2210,  2000, -2387,
     122,  1121,  1832,  1121, -2387,  2072,  7727, -2387,  2073,  2075,
    2076,  2077, -2387, -2387,  1884, -2387, -2387, -2387,  1572, -2387,
     513, -2387,   875,  1929,  1261,  1261, -2387, -2387,  7727, -2387,
   -2387,   121, -2387,  2032, -2387,  1929,  2040,  2040,  2080,    79,
     -22,  7939,   -22,   -22,   -22,   -22,  1854,  7939,  7807, -2387,
    7939,  7939,  7939,  7939, -2387, -2387,   121,  2464,   121,  7807,
     253,  7585, -2387,   875, -2387, -2387,   288, -2387, -2387,   327,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   875,  2411, -2387,
   -2387, -2387,   875, -2387,   875, -2387, -2387,  1529, -2387,  2243,
   -2387,  2244,   156, -2387,   514, -2387, -2387, -2387, -2387,   524,
    1980,  2476,  2459, -2387, -2387,  1860, -2387, -2387, -2387, -2387,
    2097, -2387,   225, -2387,   225, -2387, -2387,  7727, -2387,  2043,
   -2387,  2109,   165,   220,   327,  2465, -2387, -2387, -2387, -2387,
   -2387,  1072, -2387,  2099,  8108,  2065, -2387, -2387, -2387,  1875,
      -8, -2387,     8, -2387, -2387, -2387,  2108,   140, -2387,  2105,
    2105,   596, -2387,   380,  2110,  1873,  1298,  1876, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,   327, -2387,  2114,   508,
   -2387, -2387,   122, -2387,  7675,   508, -2387,  2113,  7939, -2387,
     526,  7939,  7939,  7939,  7939,   327,   532, -2387, -2387, -2387,
   -2387, -2387, -2387,  2078, -2387, -2387, -2387,  2327,  2114,   176,
   -2387, -2387, -2387, -2387,  1417,  1417, -2387,  1417, -2387,  1417,
    1417, -2387, -2387, -2387, -2387, -2387,   202, -2387, -2387, -2387,
    7727,  2079,  1298, -2387, -2387,   534, -2387,  2503, -2387, -2387,
    7585, -2387, -2387, -2387, -2387,  2504, -2387,   382, -2387, -2387,
    2109,  2121,  1061, -2387, -2387,   266,   266,   266,   266,   266,
     266, -2387,  2488, -2387,   540, -2387,  7416,  1333, -2387, -2387,
   -2387,   693, -2387,  2105,  7416,  2105,  2061, -2387, -2387, -2387,
    2274,   304, -2387,  1298, -2387,  1298,    36,    -8, -2387, -2387,
   -2387, -2387,   546, -2387, -2387, -2387, -2387,  2126,  7939, -2387,
    2128,  2129,  2130,  2132, -2387, -2387,  7807, -2387, -2387, -2387,
    1417, -2387,  1417, -2387, -2387, -2387, -2387, -2387, -2387,   225,
   -2387,  7727,  2327,   165, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,  1019, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,  8108, -2387,  2515, -2387, -2387,   772, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,    83, -2387,  7675,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   548, -2387, -2387,
   -2387, -2387, -2387,  1037,  1037, -2387, -2387,  1037, -2387,  7416,
   -2387,  2135, -2387, -2387, -2387, -2387, -2387, -2387,  2141, -2387,
   -2387,   138, -2387,   140, -2387,  2061
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2387, -2387, -2387, -2387, -2387,   336, -2387,   419,  -184, -2387,
   -2387,  -827,   264, -2387, -2387, -1553, -2387, -2387, -2387, -2387,
    -570, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -1575, -2387, -1545, -2387,
     388, -2387, -2387, -2387, -2387, -2387, -2387, -2387,   671, -2387,
   -2387, -2387, -2387,  1313, -2387,   971, -2387, -2387,   -60, -2387,
   -2387,  2506, -2387,  2508,  2180, -2387, -2387, -2387, -2387, -2387,
     741,   372, -2387,   738, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387,  -107,   952,   294, -2387, -2387,
    2267,    -5, -2387,  2415, -2387, -2387,  2412, -2387,  2349, -2387,
   -2387, -2387,  2278,  2164,  1218,  2276,  -304, -2387, -2387, -2387,
   -2387, -2387,  1219,  -975, -2387, -2387, -2387, -2387, -2387, -2387,
    -149,  2213,  2356,  -197,   804, -2387,  2202,   124, -2387,  2261,
   -2387, -2387, -2387, -2387,  2263, -2387, -2387, -2387, -2387,  -327,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,  2191, -2387,
    2194, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,  -893,
   -2387, -2387,  -516, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
    1604, -2387, -2387,  1039, -2387,  -895,  -813,  -266, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   797, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387,  -483, -2387, -2387, -2387, -2387,
   -2387,  2067, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -1693, -2387, -2387, -2387, -2387, -2387, -2387,  1166, -2387, -2387,
    -819, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387,  1617, -2387, -2387, -2387, -2387,
     917, -2387, -2387, -2387, -2387, -2387, -1394, -2387, -2387,   907,
   -2387, -2387, -2387, -2387, -2387, -2387,  -782,  -443,   795,  1081,
   -2387,  -462,   633,  -825,  1012, -2387,   774, -2387, -1826,    -4,
    -376, -2387, -2387, -1765,   411,  1554, -2387, -2387,   834,  1332,
   -2387, -2387, -2387, -2387, -2387, -2387,   355, -2387,    63, -2387,
    1327, -2387,  1007, -2387,   691, -2387, -2387, -2387,  -509, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,   814, -2387, -1226,
   -2387,   999, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1459, -2387, -2387,
   -2387, -2387, -2387, -2387,  -132, -2387, -2387, -1490, -2387, -2387,
   -2387, -2387,   387, -2387, -1636, -2387,  -841, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,  2596, -2387, -2387, -2387,  2509,  2591,  -661, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,   -23, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387,  2598, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,  1054, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  -425,  2146, -2387,
   -2387, -2387, -2387, -2387,  1986, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387,  2068, -2387, -2387,   -59, -2387, -2387,
    1050, -2387, -2387, -2387,  -691,  -192,  2368, -2387, -2387, -2387,
   -2387,   527, -2387,  -713,  1949,  1355, -2107,   720, -2387,  1052,
    1712,    -3,  -208, -2387, -2387, -2387,  1494, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387,  1451, -2387,  1015,
   -2387,  -350, -2387, -2387, -2387, -2387, -2387, -2387,  -378, -2387,
   -2387, -2387, -2387, -2387, -2387,   422, -2387,  1517,   497, -2387,
   -2387, -2387, -2387, -2387,   285, -2387,  -200, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387,  1774, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
    -335, -2387,  1440,  1598, -2387, -2387,   306, -2387,  -409, -2387,
   -2387,   320,   614, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
      42, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2086, -2387,  1678,   884,
    -984, -2387, -2387, -2387,  1322, -2387, -1349, -2387, -2387, -2387,
   -1353, -2387, -2387, -1326, -2387, -2387, -2387, -2387,  1340, -2387,
   -2387, -2387, -2387, -2387, -2387,   694, -2387, -2387, -2387, -2387,
   -2387, -2387,  -441, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387,  -402, -2387, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
   -2387,   688, -2387, -2387, -2387,  -265, -2387, -2387, -2387, -2387,
   -2387, -2387,   305, -2387, -2387,   663, -2387,  1013, -2387, -2387,
   -2387, -2387, -2387, -2387,  -980, -2387, -2387, -2387, -2387, -1370,
   -2387, -2387, -2387, -2387, -2387, -2387, -1968,     7, -2387, -2386,
     282, -2387, -2387, -1667,   333,   334,   667, -2387, -2372, -2090,
   -2387, -2387,    52,  -259, -2387, -2387, -2387, -2387, -2028, -2387,
   -2387, -2387, -1198, -2387, -2387,  -648, -2387,  -695,  1435,    51,
   -1454,   674, -2387,   740, -2387, -2387, -2387, -2387,  -678, -2387,
   -1679, -2293, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2000,
   -2387,   424, -2387, -1430, -2387,  1775, -2387, -2387,  -890,  -153,
   -2387, -1532,  -152,   167,   456, -1106, -1390, -1953,   313,  -337,
     624,  -321, -2387,   522,  -112, -2387, -2387,  1462,  -510, -2387,
   -2387,  -182,  1799, -2387,   954, -2387, -2387, -1244,   184, -2387,
   -2387, -2387, -1758,   -50, -2387, -2387, -2387,  1498, -2387, -2387,
   -2387, -2387, -2387, -2387, -2387, -2387, -2128,   -67, -2387, -2244,
   -1975, -1643,  -989, -2387, -2387,   -53,  -424,  -394,  -353,  1038,
    -705,     5,  2139,   105, -2387, -2387, -2387, -2387, -2387,  1612,
   -2387,  -496, -2387, -2387, -2387, -2387, -2387, -2387, -2387, -2387,
    -169,  1172,  2409, -2387, -2387, -2387, -2387
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1807
static const short yytable[] =
{
      42,   386,   268,  1031,   258,    33,   113,  1182,  1016,    57,
      59,  1815,  1173,   883,  1348,   284,  1359,  1857,  1028,  1381,
    1169,   871,  1748,   131,  1723,  2083,   834,   256,   417,    33,
     702,  1724,   868,  2074,  1275,    70,   874,   823,   721,  1200,
    1698,    74,    77,   688,  2209,  2295,  2174,   236,  1285,   925,
    1602,  1603,   928,  2601,  2602,  2603,   805,    97,   113,  2115,
    1058,  1213,  1179,  1180,  1645,  1181,  1205,  1184,  1185,  1224,
    1965,   127,   128,    41,    41,    77,   291,  2487,   781,  1496,
     338,   781,   832,    41,   670,    41,  1205,   137,    41,  1755,
     140,   790,  1132,  2435,   144,   781,  1756, -1805,   149,   781,
    1280,   151,   152,  1026,  1199,    41,   807,   155,   156,  1508,
     275,   781,   702,   790,  2269,   269,   276,   277,  2692,   818,
    1149,  1205,   790,   127,  2021,  1205,   798,  2435,    41,   829,
     299,   300,   919,  1264,   835,  1295,    97,  1297,  1404,  1981,
     201,   269,   873,   717,  2247,  1026,   232,    41,   394,   235,
     269,  1260,  1125,   818,   239,    41,  1206,   818,  1137,  1138,
     836,   818,  1207,   269,   931,   932,    41,   790,    41,   266,
     790,  1509,  2605,  1510,  1432,  1511,   881,   940,    41,   269,
    2420,  1887,   761,  1264,   129,   269,  1886,  1887,    41,  1026,
    3004,    41,   273,   269,   270,   271,    41,   379,  2529,  2530,
    2531,  2532,    41,   673,   791,  2161,    41,    41,  2354,  1026,
    2220,    41,  2383,  1988,  2384,  2385,  2386,  2387,  2388,  2389,
    1276,   381,   292,  1410,  2769,   269,  1886,  1887,    41,   389,
     296,   269,  2420,  1887,    41,  2208,   302,    41,   399,  1301,
      41,  2067,  2070,   401,   881,  2070,    41,   330,   865,  1026,
     690,    41,    41,   690,   690,   266,   266,  1508,   884,   890,
    2735, -1805,   906,  2380,   941,  1985,   910,   690,   912,  1026,
    1646,    41,   916,   266,   918,   344,   405,   346,  2560,    41,
    2029,   266,    97,  2032,  1280,   690,   266,  2485,   690,  1265,
      82,  1174,    41,  2969,   690,  2380,  2872,  2868,   690,  3152,
    2267,  1611,   690,  2669,   559,   649,   690,  1023,  1156,   266,
     690,   690,    63,   690,  2473,  1572,   690,  1346,   690,   690,
     690,   652,  2289,  1815,  2559,  2380,   690,  1021,    82,   690,
    2231,   392,  1261,  1742,  2771,  2523,   690,  2817,  1594,  1265,
      82,   690,  1993,  1752,   653,  1015,  2162,  1742,   392,   690,
     698,  1197,   409,    41,  2830,   409,   383,  2178,   134,  1519,
     690,  2844,  2491,   409,   690,   134,    65,   941,   690,   641,
     651,   941,  1566,  1205,   690,  1303,  1022,   690,    63,   330,
    1742,   330,  2376,  1205,  2924,   941,  1547,  1647,  1236,    71,
     698,  2296,  2297,  2298,  2299,  2300,  1381,   185,   186,    82,
    1389,    35,  2410,  1198,  2046,   187,    41,  2939,    82,   409,
    2845,  1556,  1191,  1192,   686,  2046,   691,   692,  2071,  2945,
     699,   704,  2094,   706,  1630,  1631,   709,  2970,  1281,   820,
    2096,   269,   931,   932,    41,  1615,  2273,   692,  1994,    34,
    2404,  1390,    79,  2383,   775,  2384,  2385,  2386,  2387,  2388,
    2389,  2404,  2524,  2390,    82,   942,   692,  1364,  2431,  1515,
     141,   873,  2449,  2449,   996,   997,   775,  2431,  2489,   692,
    1365,  1157,  2520,  2564, -1805,  2613,   687,  2474,  2402,   808,
    3153,  2000,  2696,   259,   260,   261,   262,   263,  2776,   687,
    2001,  2776,   998,   999,  1000,   824,   826,  1648,  2989,  2801,
     943,  1281,   699,   130,   259,   260,   261,   262,   263,  1312,
     775,  2818,   824,   824,  2002,  2818,  2826,  2003,  2936,  2986,
     775,   775,   727,   902,   775,  1573,    77,   687,   775,  2986,
     775,  3058,  2286,  1262,   775,  2004,   775,  3058,   920,  3079,
     920,   824,  1753,   920,   824,  3102,   920,  1411,  1219,  1889,
    1222,  3119,  2283,  2818,  1829,  1889,  3050,  2308,  2486,   944,
    1590,  1582,  2525,  2796,  1890,  2770,  1263,   865,    82,  1572,
    1890,  2506,  2391,  1781,    95,  1406,  1784, -1805,  1408,  1409,
    1406,   380,  2870,  2277,   873,   835,   873,  2355,   267,  1989,
    2179,  2067,  2519,  1388,  2672,  1889,    82,  1428,  1309,  2411,
     687,  1889,  1204,  2454,  1541,   382,  1639,  1640,   865,  1360,
    1890,  1296,  1241,   390,  2284,  1650,  1890,   821, -1805,  1208,
     884,  1831,   400,   702,  2248,  1227,  2736,   402,  2316,  2392,
    1477,  2221,   384,  3044,  1982,   908,  2835,  1520,    41,   943,
    2792,  2005,  1491,  1521,  1522,  1523,  2381,  2494,   969,  1309,
      76,    41,  1343,  1266,  1377,  2502,  2503,  1492,  1690,  1757,
     406,  1387,   944,  1524,  2022,  1921,   944,  2436,   690,  2741,
    1150,   984,    41,  2882,   341,   672,  1344,   991,  2408,   409,
     944,  1225,  1875,  2765,  2390,  2938,   799,  2893,  1367,  1973,
    2062,  1024,   982,  2075,   699,  2006,   823,  1139,  2962,  3078,
    2429,  1347,  2007,  1266,  1368,  2768,  2743,  1209,  2660,  1027,
    2748,   272,  1472,   822,   822,  2873,  1478,  1743,   775,   775,
    2555,  1512,  1211,   822,  1632,  1497,  2968,  2151,  3114,  1513,
    2831,  1746,  2062,   775,    41,  1557,   403,   272,  2707,   775,
     775,  2425,   702,  1544,   775,  2406,   272,  2426,  2726,  1761,
    3115,  1865,  3116,  2294,   775,  1539,  2106,  1747,  2393,   272,
    1921,   945,   946,   947,  1851,  1175,  1577,  1852,  1406,  2521,
      41,  1525,   948,  1559,  1526,   272,  2062,  1598,  1599,  1573,
    2076,   272,  2948,  1027,  2951,  2952,  2953,  2954,  2047,   272,
     933,   690,   690,   690,  2940,  2941,  2062,  2077,  1527,  2061,
      82,   132,  2072,  2391,  2394,  3003,  2095,  2106,   188, -1805,
   -1805, -1805, -1805, -1805,  2097,   182,  1552,    41,  1528,  1176,
    2274,   272,  3127,   139,  2405,  2395,  2008,   272, -1805,   775,
     775,  2518,  2673,    44,    82,  2407,  2569,  2713,  1652,  2824,
    2078,  2772,  2432,  2957,   736,  2942,  2450,  2451,   141,  2561,
    2562,  2456,  2490,  1529,  2965,  2090,  1542,  2565,   143,  2614,
    2392,  1001,  2659,   949,   775,  2033,  2697, -1805,  1364,   740,
     775,  1162,  2777,  1530,  1531,  2783,  1479,  1480,  1481,  1730,
    2079,  1365,   775,  2802,  1532,  1349,   414,   775,  1351,  1533,
    1805, -1805,  1234,   934,   656,  2819,  1503,   710,    41,  2825,
    2827,    41,  2937,  2987,  1352,   145,   697,  1872,    41,  2080,
    1252,  2909, -1805,  2988,  2994,  3059,  2996,  -266,  2081,  3084,
    1741,  3065,   195,  3080,  3087,   775,  2301,  1142,  1534,  3103,
    1846,    41,    82,  1540,  1143,  3120,  2808,  3144,   715,   775,
     684,  2468,  2375,  1163,  2378,   194,  1992,   303,  2679,  1002,
    2682,  1364,    18,   749,  1386,  2760, -1805,   785,   884,  2551,
      41,  1535,  2935,   830,  1365,    41,   233,  1352,  3085,  2674,
     794,  2675,  1495,  3108,   304,  1565,    18,   658,   136,    82,
    1780,  2553,    41,  1783,    41,  1580,  1611,    34,    35,  2393,
    1971,  1569,  1003,  1361,  1159,  2187,   198,  1369,  1378,  1369,
     269,  1886,  1887,    41,  -266,   259,   260,   261,   262,   263,
     699,   659,    45,   699,   234,  1393,  1396,  1830,  1417,   706,
    2714,  -266,  1673,  1418, -1805,  1420,    46,   272,  1665,   241,
     875,  2715,    41,   824,   775,  2394,   824,   824,   824,   824,
    2577,   775,  1353,   958,   775,   249,   754,  2091,  2824,  2824,
    1856,    47, -1805,  1366,   959,   824,  2395,   775,   756,   757,
      82,   775,  1392,    82,  -266, -1805,  2373,   759,    41,   775,
     698,   775,   775,   250,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,  2925,    82,  2927,  2253,   881,   252,    41,  1367,
      48,   253,   775,   775,  -266,  1353,   960,   775,  1653,   775,
    2797,  3130,  1381,  2424,   254,  1368,  1188,  1970,  1354,  1654,
    1615,   961,    82,  1195,  1468,  2849,  1940,   698,  1878,   257,
    1820, -1805,   699,  -266,    41,    81,  1380,    41,   775,   775,
     775,  1655,  -266,  1245,    82,    41,  1928,  1930,  1656,   824,
    1638,  1494,  2566,  1498,   824,    58,  1642,    41,   775,  2834,
    2570,   652,   907,  2288,  2967,   698,   911,  1674,  2949, -1805,
     915,  1291,   288,    41,  2949,  1127,  2798,  2958,  2959,  2960,
    2961,  1354,  1367,   971,   653,  2306,  1675,  1676, -1805, -1805,
    2593,  2593,  2593,  2593,    82,   775,   307,  2850,  1368, -1805,
     265,   824,   133,   134,  2465,  1238,  1677,  1673, -1805,   285,
      41,   962,  2433,  1016,  1845,  1473,  2695,    41,  1799,  2699,
     775,  2101,  1356,  2480,  1554,  1808,   824,   824,  1809,    41,
     286,   824,   133,   134,  1681,  1563,  1564,   775,  1357,  1355,
    1189,  1190,  1824,  1687,  1193,  1194,  1481,   775,  1090,  1091,
    1092,  1093,  1094,  2680,   835,  3135,  2399,   289,  2107,    41,
      82,   699,  2851,   813,  2852,  1095,  1128,   290,   920,   824,
     824,   295,   819, -1805,   294,   873,  2276,  1204,   297,  2853,
    2109,   301,  2152,   308,  2153,  1356,  2668,  2854,  2508,  2671,
      41,  2855,  1808,  2164,  1634,  1809,  1239,  1027,  1027,    82,
     309,  1357,  1643,  1864,  1643,  3057,  1027,    82,  3060,  3061,
    3062,  3063,  1611,  2655,   306,    41,  2856,   923,  2309,  2175,
     926,   315,  1096,  1097,  1098,  1099,  1100,  1101,   133,   134,
   -1805,  1810,   324,  3082,  1811,    82,  2746,   690,  1102,  1103,
    1104,   984,    41,   310,  3037,  3038,   325,  2943, -1805,  1027,
     331, -1805,  1674,  3105,  1611,  2521,  1611, -1805,   316,    41,
   -1805, -1805,  1369,  1604,  3089,  1605,  1606,  1607,  3090,   334,
    1889,  1675,  1676,  1378,  2325, -1805,  1369,   337,   924,    82,
    2358,   927, -1805,   311,   930,  1890, -1805,   697,  1401,    41,
    1604,  1677,  1605,  1606,  1607,  1737,  1738,  1739,  1810,  2216,
     335,  1811,  2578,  2515,   336,  2579,  3089,  3049, -1805,   340,
    3090,   783,   312,  3055,   342,  3122,  1653,   343,  2580, -1512,
     347,   313,  3029,  1611,  1050,   792,  1026,  1654,    41,   797,
   -1805, -1805,   775,   775,   775,   696,   775,  2414,  3008,  2416,
    2417,   811,  2550,  2701,   348,   317,  1615,  2703,   714,  1655,
     351,  1232,    82,    41, -1805,   352,  1656, -1805,  3110,  2582,
    3112,   690,   318,   775, -1805,   354,  1790,  2103,   353,  2593,
    2593,  2583,  1384,  2593,    41,   786,   358,    82,  1105, -1805,
     775,  1106,   690,   357,  2015,  2075,    41, -1805,  1615,  3111,
    1615,   803,   804,   385,  1032,  1033,  1034,   810,  1818,   368,
     812,  2359,   964,   965,   775,   319,  1825,  1826,   775,   824,
    2119,  1051,  2120,  2584,  2728,   369,  2729,  2360,  2361,  1415,
    1416,  2244,  3094,   372,  2896,  2362,  2897,   377,  1052,  2154,
    2155,  1481,  2158,   259,   260,   261,   262,   263,   387,   775,
    2102,  3029,  1581,   134,   775,   320,  1660,  1661,  1474, -1805,
    1474,   388,  2585,  2181,  1854,  1668,  1669,  1615,   775,  2363,
     391,  2121,  2217,  2218,  2586,   775,  1821,  1822,  2364,   945,
     946,  1053,  2076,   775,   321,   397,  2587,  2588,   395,  1879,
    1252,   396,  1904,   322,   398,  2589,  2806,  2807,  2590,  2077,
    2427,  2600,  2600,  2600,  2600,   407,   272,  2365,  1608,   415,
    1107,  1609,  3094,  1610,   824,   824,   835,   404,   657,   662,
    2213,  1054,   873, -1805, -1805,  1108, -1805,   664,   824,  1109,
     665,   666,   671,  1611,   676,  1608,   674,   677,  1609,  3008,
    1610, -1805,  2078,  1612,   873,   678,   680,  1027,   682, -1805,
    1055,  2457,  2366, -1805,  1214,  1215,  1216,  1217,  2754,  1056,
    1611,  2843,  1937,   681, -1805,   683,  2016,  1110,   685,   973,
    1612,  2850,  2683,   975,  2755,  2718,   974,   976, -1805,  2028,
    2028,  1417,  2079,  2028,   977,  1613,  1418,  1419,  1420,  1614,
     978,   979,   980,   981,  2367,  1111,   983,   989,   987,  1904,
    1013,  2063,  2063,   988,   990,  2063,  1904,   994,  1014,   134,
    1017,  2080,  1613,  1020,  1112,  2593,  1614,  1019,  1025,  1029,
    2081,  2593,  2593,    41,  2593,  2593,  2593,  2593,  1037,  1038,
    1040,  1041,  2098,  2593,  1042,  1393,  2851,  1129,  2852,   775,
    1043,  1044,  1136,  1140,  1045,  2303,  1369,  2304,   824,  1046,
    1047,  2711,  1048,  2853,  1904,  1059,   159,  1060,  1061,  2684,
     274,  2854,  2719,  1141,   279,  2855,  1144,  1615,  2233,  2234,
    2235,  2236,  1064,  1065,  1068,  1070,  2685,  1071, -1805,  2720,
   -1805, -1805, -1805,  1072,  1073,  1074,   775,  1075,  1076,   775,
    2856,  1078,  1145,  2758,  1615,   160,  1113,  1369,  1147,  1148,
     892,   775,   775,   775,   775,  1152,  2063,  2546,  1153,  2548,
    1155,  2123,  2166,  1818,   161,  2125,  2171,  2171,  1158,  2686,
    2128,  1172,  2721,   690,  2132,   775,  2134,  2135,  2136,   690,
    1167,  1186,  1196,  1199,  1220,  2183,  1228,  1229,  1230,  1231,
    1240,  1235,  2237,  2238,  2239,  2240,  2241,  2242,  1249,  1237,
     893,   690,  2593,   162,  1241,  2593,  2593,  2593,  2593,  2687,
    1251,     1,  2722,  1114,  1271,   163,  1272,  1273,  1205,  1274,
    1279,  2820,  2821,  2822,  2823,   164,  1283,     2,     3,  1286,
    2600,  2600,   775,  1287,  2600,    82,  1289,   894,  2688,  1904,
    1904,  2723,  1288,   165,  1334,  1342,  1363,  2689,  1904,  1345,
    2724,  2459,  1383,   166,  2464,  1402,  1400,  1403,  1401,  2230,
    1016,  1412,  1426,   835,   835,  1429,  1427,  2900,  1434,   167,
    1463,   699,  1399,  1466,  1471,  2908,  1211,  1484,  2702,  2254,
    1470,  2627,  2628,  2629,  1502,  2631,  2632,  2633,  2634,  2635,
    2636,  1504,  1506,  1517,  2639,  2237,  2238,  2239,  2240,  2241,
    2242,  1518,  1543,     5,     6,  1545,     7,     8,  2737,   168,
     865,     9,  2593,  1546,  1490,  1548,  1550,  2235,  2236,  1555,
    2593,  1558,  2867,  1560,  1576,  2867,  1584,  1027,    10,    11,
    1569,  1583,  1578,   169,   895,   649,  1586,  1281,  1508,  1622,
    1624,   649,  2063,  2750,  1625,  1904,    12,  1627,   170,  1633,
    2752,  1682,  2292,  1643,  1904,   171,  1693,   775,   172,   775,
     718,   718,  1695, -1805,  1696,  2966, -1805,  2063, -1805,  1027,
    1699,  1726,  2711,  1700,  1728,  1729,  1732,  1733,  2028,   173,
    1731,  1744,   174,  2513,   175,  1745,  1749,  1751, -1805,  2237,
    2238,  2239,  2240,  2241,  2242,  1758,  1760,  1762, -1805,  1792,
     651,  2063,   734,   176,  1763,  1904,   651,  1904,  1765,  1768,
     896,  1789,  1795,  1794,   735,  1796,  1798, -1805,  2063,  2822,
    2823,   177,  1797,  1801,  1803,  1800,  1280,  1369,  1883,  1884,
    1802,  1885,  1804,  1806,   269,  1886,  1887,    41,  1807,  1819,
   -1805,  1834,  1832,  3028, -1805,  1835,  1836,  1840,  1843, -1805,
    1378,   897,  1369,  1849,  1850,   718,  1855,  1858,  1859,  1868,
    1737,  1862,  1876,   775,  1882,   935,  2600,  1915,  2439,  1916,
     690,   690,  2600,  2600,  1888,  2600,  2600,  2600,  2600,  1917,
     948,  1921,  1923,  1968,  2600,  1969,  1980,  1986,  1996,    89,
    1997,  2237,  2238,  2239,  2240,  2241,  2242,  2011,  2013,  2014,
    2025,  2036,  1340,   775,   775,    50,    51,    52,    53,    54,
      55,    56,  2037,   775,  2038,  2042,   775,  2045,  2084,   898,
    2085,  2466, -1805,  2100,  2086,  2087,  2088,  2089,  2104,  2116,
    2117,  2124,  2127,  2137,  1818,  2138,  2481,  2139,  2483,  2118,
    2142,  2143,  2145,  2147,  2149,   775,  2160,  2711,   775,  2711,
    2165,  2182,  2498,  2190,  2180,  2191,   775,   775,   751,  2196,
    2193,   183,   191,  2195,  3036,  2194,  2197,  2198, -1805,  2214,
    1911,  2215,   775,  2223,  2232,  2224,  2751,  2225,  2226,  2063,
    3118,  1904,  2252,   899,  2227,  2228,  2902,  1904,  1904,  1904,
    1904,  1904,  1904,  3095,  3096,  3097,  3098,  3099,  3100,   698,
     947,  2229,  2259,  2600,  2261,  2766,  2600,  2600,  2600,  2600,
    2270,  2271,  2275,  2272,  2290,   824,   191,   824,  2279,  2280,
    2287,  2311,   191,  2313,  2314,  2319,  2312,   753,  2374,  2382,
     935,  2899,  2401,  1904,  2784,  2402,   755,  2409,  2412,  2415,
    2403,  2867,  2418,  2428,  2434, -1750,  2063,  2440,  2441,  2745,
    2442,  2443,  2591,  2591,  2591,  2591,  2063,  2063,  2842,  2444,
    2445,  2446,  2447,  2448,  2452,  2455,  2458,  2616,  2617,  2016,
    2460,  2461,  2471,  2467,  2475,  2620,  1126,  2479,  2482, -1805,
    2493,  2501,  2511,  2517,  2533,  2519,  1035,  1036,  2542,  2545,
    2556,  2557,   191,  2380,   191,  2566,  2573,  2435,  2615, -1805,
    2611,  1049,  2625,  2048,  2626,  2630,  2637,  1062,  1063,     2,
       3,  2644,  1067,  2600,  2638,  2648,  1353,  2649,  2221,  2650,
    2651,  2600,  1077,  2645,  2652,  2653,  2654,  2667,  2670,  2677,
    2691,  2693,  2112,  2698,  2700,  2704,  1904,  2738,  1904,  1989,
    2727,  2739,  2740,  2733,  2711,  2741,  2753,  2663,  2756,  2663,
    2763,  3013,  2759,  1904,  2773,  2774, -1805,   942,  2063,  2681,
    2063,  2788,  2799,  2809,  2792,  2810,  2811,  2812,   191,  2813,
    2814,  2815,  2818,  2828,  2829,  2840,  2847,  2839,  2399,  2862,
    2875,  2876,  2878,  2879,  2880,     5,     6,  1369,     7,     8,
    2881,  1904,  1027,     9,  2884,  2887,  2894,  2892,  2895,  2905,
    3155,  2898,  2901,  2907,  1889,   775,  2915,  2917,  2911, -1805,
      10,    11,  2913,  2914,   873,  2919,  2923,  2926,  2934,  1890,
    2944,  2928,  2930,   191,  2931,  2932,  2933,  2171,    12,  2946,
    2747,  2171,  2903,  2955,  2436,   824,  1891,  2963,   775,  2049,
    2982,  2983,   824,  2990,  2991,  2992,  2993,   935,  3000,  3014,
    3011,  2050,  1893,  3026,  3027,  1701,   775,  3035,  3043,  3042,
     712,  3045,  3056,  3077,  1663,  1664,  3066,   775,  3081,  3083,
    3088,  1680,  3101,  3113,  1904,  3121,  2222,  3123,  3124,  3125,
    3139,  3126,  1904,  2430,  3149,  1904,  1904,  1904,  1904,  2782,
    3150,  2497,  3138,  1895,   788,  2453,   775,  2206,    13,  1095,
     793,  1867,   795,    72,   560,  1896,   802,    73,  2167,   802,
    2478,  2176,   802,  2789,   349,  1568,   197,   202,   281,   345,
    2063,   675,   814,  1684,   350,  1685,   408,   283,  2730,  2292,
    2126,  2591,  2591,   661,   667,  2591,  3136,   376,   374,   668,
    2144,   863,  1842,  1754,  1338,  2034,  2816,  1897,  2026,   876,
     879,   882,  2156,  1827,   901,   903,  1096,  1097,  1098,  1099,
    1100,  1101,  1601,   913,  1597,  2544,  2787,  1920,  3142,  2063,
    2251,  1634,  1102,  1103,  1104,  2163,  1938,  1499,  2910,   937,
      67,    68,  2112,    81,  2860,    41,  1898,   157,    69,  1874,
     809,  1877,   993,  1298,   339,  1621,  1881,  2246,  1899,  2973,
     972,  2848,  1407,  1486,     2,     3,  1277,  1538,  1983,  1414,
    1900,  1901,  1425,  3109,  2535,  2658,  1476,  2981,  2371,  1902,
    1223,   690,  1903,   699,  1551,  1430,   699,  1435,  2663,  1433,
     272,  1904,  2640,  2377,  2657,  2150,  2281,  1439,  3143,  1441,
    1442,  3132,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
    1694,  1398,  2310,  1027,  3067,  1727,  2678,  2885,  2372,  2890,
    1461,  1462,  2073,  2661,  2883,  1464,  2662,  1465,  2379,  2712,
       5,     6,  2869,     7,     8,  1848,   935,  3075,     9,   824,
    1702,  3041,  2874,  1637,   775,  1299,  2398,  2618,  1326,    16,
    3009,  2805,  3010,  1300,  3131,    10,    11,  2572,  2706,  1301,
    2985,  1302,  1105,  2534,  3048,  1106,  1629,  2804,  1294,  2947,
    3104,  2964,  1303,    12,  2956,  1595,  1493,  2099,  1918,     1,
       0,   416,  1904,     0,     0,     0,     0,     0,     0,   718,
       0,     0,     0,     0,   937,     2,     3,    82,  1703,     0,
    1304,     0,     0,     0,  1904,     0,     0,  2063,     0,     0,
    1704,     0,     0,     0,     0,  2063,  1305,  2591,     0,     0,
    1705,  1306,     0,  2591,  2591,     0,  2591,  2591,  2591,  2591,
       0,     0,  2063,  1307,  2063,  2591,     0,  1904,  1706,     0,
    1308,  2421,     0,    13,   935,  2972,     0,     0,  1707,     0,
       0,  1708,     0,     0,     0,     0,     0,     0,     0,  2527,
       0,     0,  1130,     0,  1709,  2527,  1911,  2536,  2537,  2538,
    2539,     5,     6,     0,     7,     8,     0,     0,     0,     9,
       0,     0,     0,  3148,  1107,     0,     0,     0,  1027,     0,
    1027,     0,     0,  1904,     0,     0,    10,    11,  2063,  1108,
    2890,     0,     0,  1109,     0,  1161,     0,     0,     0,     0,
       0,  2112,     0,  1710,    12,     0,     0,     0,     0,     0,
       0,  1178,  1178,  1178,     0,  1178,     0,  1178,  1178,     0,
       0,     0,     0,    89,    89,     0,     0,     0,     0,     0,
       0,  1110,  2789,  1711,     0,     0,     0,     0,     0,     0,
    1904,     0,     0,  1712,  2591,     0,     0,  2591,  2591,  2591,
    2591,  3064,     0,     0,     0,     0,     0,     0,     0,  1111,
       0,     0,     0,     0,  1713,  1634,   882,  1714,     0,  1715,
       0,     0,     0,     1,     0,     0,     0,  1247,  1112,     0,
       0,     0,   699,     0,     0,  1309,  1904,     0,     0,     2,
       3,     0,  1310,     0,     0,     0,  1904,  1716,   102,     0,
       0,   937,  1130,   103,     0,     0,  1717,     0,     0,     0,
    1284,     0,     0,     0,  1311,     0,     0,     0,     0,  1312,
       0,  2676,   775,  3106,     0,     0,  1292,  1292,     0,     1,
     775,     0,  2202,  2203,    16,     0,  2592,  2592,  2592,  2592,
    1769,  1770,  1771,  2212,  1773,     2,     3,     0,   104,   105,
       0,     0,     0,     0,  2591,     0,   106,     0,     0,  2112,
    1113,     0,  2591,     0,     0,     5,     6,     0,     7,     8,
       0,  1788,     0,     9,     4,  1027,     0,  1904,     0,  2063,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,    14,     0,  2255,  2256,  2257,  2258,
       0,     0,     0,     0,  2263,  2264,  2265,  2266,    12,     0,
       0,  2268,  1093,  1094,     0,  1904,     0,     0,     0,     0,
       0,     5,     6,     0,     7,     8,  1095,  1114,     0,     9,
       0,  2665,     0,  2665,     0,   775,     0,     0,     0,     0,
    1905,     0,  2112,    15,     0,     0,    10,    11,     0,     0,
    2775,     0,  1844,  2778,  2779,  2780,  2781,     0,     0,     0,
       0,     0,     0,     0,    12,     0,  1788,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,     0,     0,     0,     0,  2317,  2318,  1469,     0,  1102,
    1103,  1104,  2322,  2323,     0,    89,     0,    89,   882,   802,
       0,     0,     0,     0,     0,     0,  1485,   814,     0,     0,
     882,     0,     0,     0,   191,     0,     0,  1500,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
     937,     0,     0,     0,     0,     0,     0,  1905,     0,     0,
       0,     0,     0,     0,  1905,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1766,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,  2871,
       0,     0,  1905,     0,     0,  1561,     0,  1095,     0,   107,
       0,     0,     0,     0,     0,  2592,  2592,     0,     0,  2592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1588,
       0,     0,     0,     0,  1591,   108,     0,     0,     0,  1105,
    2469,  2470,  1106,     0,     0,     0,     0,  1620,   937,  2477,
       0,     0,     0,     0,    14,     0,     0,  2488,     0,     0,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,     0,     0,     0,  2504,  2505,     0,     0,
    1102,  1103,  1104,     0,  2140,     0,     0,  2140,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
    2929,     0,  1667,    15,     0,     0,   109,  2866,     0,  1095,
    2866,     0,  2665,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2547,     0,  2549,    16,     0,  1905,  1905,     0,
       0,     0,     0,     0,     0,     0,  1905,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   882,     0,     0,
       0,  1107,     0,     0,     0,     0,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,     0,     0,  1108,     0,     0,     0,
    1109,     0,  1102,  1103,  1104,     0,     0,     0,     0,     0,
       0,     0,  2621,  2622,     0,     0,  2623,  2624,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2999,     0,     0,     0,     0,     0,     0,  1110,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
    2647,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1905,     0,     0,  1111,     0,     0,     0,
       0,  2592,  1905,     0,     0,     0,     0,  2592,  2592,     0,
    2592,  2592,  2592,  2592,     0,  1112,     0,     0,  3054,  2592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2665,  1905,     0,  1905,     0,     0,     0,  1839,
       0,     0,     0,     0,  3076,     0,     0,     0,  1847,     0,
       0,     0,  1105,     0,     0,  1106,     0,     0,   882,     0,
       0,  2328,  2329,     0,     0,  2330,  2331,  2332,     0,     0,
       0,     0,  1107,     0,  2744,  1905,     0,  1113,  2749,   183,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2764,
       0,     0,     0,     0,     0,     0,     0,     0,  2592,     0,
       0,  2592,  2592,  2592,  2592,   882,  1972,   882,     0,  1110,
       0,   876,     0,     0,     0,  2999,     0,     0,     0,     0,
       0,     0,     0,  2785,  1114,     0,     0,     0,     0,  1941,
    1942,  1943,  1944,  1945,  1946,     0,  2866,  1111,     0,     0,
       0,     0,     0,  2020,  2333,     0,     0,     0,     0,     0,
       0,  2334,     0,  3054,  1107,     0,  1112,     0,     0,     0,
       0,  1788,  1788,     0,     0,     0,     0,     0,     0,  1108,
       0,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2335,     0,     0,  1947,  1905,
       0,     0,     0,     0,  2336,  1905,  1905,  1905,  1905,  1905,
    1905,     0,     0,  2492,     0,     0,  1788,     0,  2592,   882,
     191,  1110,     0,     0,  1788,  1788,  2592,     0,     0,     0,
       0,     0,     0,  2337,  2338,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,  1111,
       0,  1905,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
    1905,  1905,  1905,  1905,     0,     0,     0,     0,  2339,     0,
     882,     0,   882,     0,     0,     0,     0,     0,     0,     0,
       0,   882,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   718,   718,   718,     0,   718,   718,
     718,   718,   718,   718,     0,  1114,     0,   718,     0,     0,
    2340,     0,     0,     0,     0,     0,     0,     0,     0,  2188,
       0,     0,  2189,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
    1113,     0,     0,     0,  1905,     0,  1905,     0,  2211,  2922,
       0,  1095,     0,     0,     0,  1905,     0,  1905,     0,     0,
       0,  1905,     0,     0,     0,     0,  2341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2245,  1591,     0,     0,     0,  1905,
       0,     0,     0,     0,     0,     0,     0,  1114,  1096,  1097,
    1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,
       0,  1948,     0,     0,  1102,  1103,  1104,     0,     0,     0,
       0,     0,     0,     0,  1949,     0,     0,     0,     0,     0,
       0, -1806,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1806,     0, -1806, -1806, -1806,     0,     0,     0,
     935,     0,     0,  2731,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1806,     0,  1905,     0,     0,     0,     0,     0,     0,     0,
    1905,     0,     0,  1905,  1905,  1905,  1905,     0,  1950,  2315,
       0,     0,     0,  3039,     0,  1951,     0,     0,     0, -1806,
       0,     0,     0,     0,  1788,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1905,
    1905,     0,     0,  1905,  1952,     0,     0,     0,     0,     0,
       0, -1806,     0,     0,     0,     0,  3068,  3069,     0,  3071,
       0,  3073,  3074,     0,  1105,     0,     0,  1106,     0,  1953,
       0,     0,     0,     0,     0,     0,     0,     0,   882,  1954,
    1955, -1806,     0,     0, -1806,  1956,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1957,  2342,  2343,  2344,  2345,
    2346,  2347,  2348,  2349,  2350,  2351,     0,     0, -1806,     0,
       0,     0,     0,     0,     0,     0, -1806,  1958, -1806,     0,
    1959,  1960,     0,     0,     0,     0,  1961, -1806,  3117,   882,
       0,  1905,     0, -1806,  1905,     0,  1905,     0,     0,  1905,
       0, -1806,     0,     0,     0, -1806,     0,     0,     0,     0,
       0, -1806,  3128,     0,  3129, -1806, -1806, -1806, -1806,     0,
       0,     0,  1591,     0,     0,     0,     0,     0,     0,     0,
   -1806,  2495,     0,   712,     0,  2499,     0,     0,     0,     0,
       0,     0,     0,  1962,     0,     0,  1107, -1806,  2510,  3140,
   -1806,     0, -1806,   191,     0,  1963,     0,     0,     0, -1806,
       0,  1108,     0,     0,     0,  1109,     0,     0,     0,     0,
       0,     0, -1806,     0,     0,  3145,  3146,     0,     0,  3147,
       0,     0, -1806,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1905, -1806, -1806,  1110,     0,     0,     0,     0,     0,  2552,
    2554,     0,     0,     0,     0,     0, -1806,     0,     0,     0,
       0,     0,  1905,     0, -1806,     0,     0,     0, -1806,     0,
       0,  1111,     0,     0,     0,  1905,     0, -1806, -1806, -1806,
       0,  1905,  1905,     0,  1905,  1905,  1905,  1905,     0,     0,
    1112,     0,  2619,  1905,     0,  1905,     0,     0,     0,     0,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1905,     0,  1095,     0,
       0,     0,  2641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2656, -1806,     0,     0,     0,
       0,  1905,     0,     0,     0,     0,     0, -1806,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1113,     0,     0,     0,     0,     0,     0,     0,
       0,   935,     0,     0,  1095,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,     0,     0,     0,     0,     0, -1806,     0,
       0,  1102,  1103,  1104,     0,     0,   882,     0,  1905,     0,
       0,     0,  1905,     0,     0,  1905,  1905,  1905,  1905,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   882,     0,     0,  1114,
       0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,
    1905,   191,     0,     0,  1905,     0,     0,  1102,  1103,  1104,
   -1806,     0,     0,     0,  1905,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   937,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1806,     0,     0,     0,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,
       0,     0,  1905,     0,     0,     0,     0,     0,  1095,     0,
    1905,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,
       0,  1105,     0, -1806,  1106,  1905,     0,     0,  1788,     0,
    1095,     0,     0,     0,     0,     0,     0, -1806, -1806, -1806,
   -1806, -1806, -1806, -1806,     0, -1806, -1806,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1806,  1905,     0,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,     0,     0,     0,     0,  1105,     0,     0,
    1106,  1102,  1103,  1104,     0,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,   935,     0,     0,
       0,     0,  2641,  1102,  1103,  1104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,  1109,  1431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,   882,     0,     0,     0,     0,  1107,
    1110,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1108,     0,     0,     0,  1109,     0,
       0,  1105,     0,     0,  1106,     0,     0,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,  1106,  1112,     0,     0,
    1591,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,  1103,  1104,     0,
    1883,  1884,     0,  1885,  1111,     0,   269,  1886,  1887,    41,
       0,  1591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,  2641,     0,     0,     0,     0,
    2976,     0,  2978,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1888,     0,     0,  1113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,     0,     0,     0,     0,     0,
       0,   882,     0,     0,     0,     0,     0,     0,  1108,   882,
       0,     0,  1109,  1750,     0,  1107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   937,     0,     0,     0,     0,
    1108,   191,     0,     0,  1109,  1113,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,  1114,     0,     0,     0,
    1110,     0,     0,     0,     0,     0,     0,     0,   418,     2,
       3,     0,     0,     0,     0,     0,  1105,   419,     0,  1106,
       0,     0,  1110,     0,     0,     0,     0,     0,  1111,   420,
     421,     0,   422,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   423,  1112,     0,     0,
    1111,   698,  1114,   424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,   426,   427,     0,     0,  1112,
       0,     0,     0,  1178,  1178,  1178,  1178,  1178,  1178,     0,
     428,     0,   429,   430,   431,     5,     6,   432,     7,     8,
     433,     0,   434,     9,   435,   436,     0,     0,     0,     0,
       0,   437,     0,     0,   438,     0,   439,   440,   441,     0,
      10,    11,     0,     0,     0,     0,   442,     0,   443,   444,
       0,   445,     0,   446,   447,     0,     0,   448,    12,  1113,
       0,   449,   450,   451,     0,   452,   453,     0,  1107,     0,
     454,   455,     0,   456,     0,     0,     0,   457,     0,   458,
     459,  1113,     0,  1108,     0,   460,     0,  1109,  1759,   461,
       0,     0,   462,     0,   463,     0,   464,     0,   465,     0,
     466,   467,     0,   468,   469,   470,     0,     0,     0,   471,
       0,   472,   473,     0,   474,     0,     0,     0,     0,     0,
       0,     0,   475,   476,     0,  1110,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,   477,     0,     0,   478,   479,
       0,   937,   480,   481,     0,     0,   482,   483,  1114,     0,
       0,     0,     0,  1111,     0,   484,   485,   486,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
     489,   490,  1112,   491,     0,     0,     0,   492,   493,     0,
       0,     0,   494,     0,     0,     0,  1889,     0,     0,     0,
     495,     0,     0,   159,     0,     0,     0,     0,   496,   497,
     498,  1890,     0,     0,     0,     0,   499,   500,     0,     0,
       0,     0,   501,     0,     0,   502,     0,     0,  1891,   503,
     504,  1892,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,   160,     0,  1893,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   506,     0,
       0,   161,     0,     0,  1113,     0,   507,     0,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1894,  1895,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,  1896,     0,     0,
     162,     0,   509,     0,   510,   511,     0,     0,     0,     0,
       0,     0,   163,   512,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,     0,     0,     0,     0,     0,     0,     0,  1897,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,   513,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   514,     0,     0,   167,   515,     0,     0,
       0,   516,     0,     0,     0,     0,     0,     0,  1898,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1899,     0,     0,     0,     0,   517,   518,     0,     0,     0,
     519,     0,  1900,  1901,     0,     0,   168,     0,     0,     0,
       0,  1902,   520,     0,  1903,     0,     0,     0,   521,   522,
     523,   524,   272,     0,     0,   525,     0,     0,     0,   526,
     169,     0,     0,     0,     0,     0,   527,   528,     0,     0,
       0,     0,     0,     0,     0,   170,     0,     0,   529,     0,
     530,     0,   171,     0,     0,   172,     0,     0,     0,     0,
       0,   531,     0,   532,     0,     0,   533,     0,     0,     0,
       0,     0,   534,     0,     0,     0,   173,     0,     0,   174,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   535,     0,
     176,   536,     0,     0,     0,     0,     0,   537,     0,     0,
     538,   539,     0,     0,     0,     0,     0,     0,   177,     0,
       0,     0,     0,     0,     0,   540,     0,     0,     0,     0,
       0,     0,   541,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,   542,   543,   544,   545,   546,
     547,   548,  1095,     0,   549,     0,   550,     0,   551,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
    1103,  1104,     0,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1095,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,  1106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,     0,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,  1103,  1104,     0,     0,  1105,
       0,     0,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,  1764,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,  1105,     0,  1108,  1106,     0,
       0,  1109,  1772,     0,  1110,  1102,  1103,  1104,     0,     0,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,  1108,  1106,     0,     0,
    1109,  1774,  1111,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1111,  1110,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1111,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,  1113,     0,     0,  1109,  1775,     0,     0,
       0,     0,     0,     0,     0,  1105,  1107,     0,  1106,     0,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,  1108,     0,     0,     0,  1109,  1776,     0,  1113,     0,
    1102,  1103,  1104,     0,  1110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
    1114,     0,  1111,  1110,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1111,  1095,     0,     0,  1114,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
    1112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1095,     0,     0,  1114,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,  1113,     0,  1102,  1103,  1104,     0,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,  1110,     0,     0,     0,     0,     0,
       0,     0,  1113,     0,  1102,  1103,  1104,  1778,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1111,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1114,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,     0,     0,     0,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,  1095,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,  1105,     0,  1108,  1106,     0,
       0,  1109,     0,  1113,     0,  1102,  1103,  1104,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,  1105,     0,     0,  1106,     0,     0,
       0,     0,  1095,     0,     0,     0,     0,     0,     0,  1110,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
       0,     0,  1779,     0,     0,     0,  1102,  1103,  1104,     0,
       0,     0,     0,     0,     0,     0,     0,  1111,     0,     0,
    1114,     0,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,  1112,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,  1107,     0,  1106,     0,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,  1108,     0,     0,     0,  1109,     0,     0,  1113,  1102,
    1103,  1104,     0,     0,  1110,     0,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,  1782,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,     0,  1095,  1106,
       0,     0,  1111,  1110,     0,     0,     0,     0,     0,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1111,  1095,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,  1106,     0,
    1112,     0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,  1113,     0,  1102,  1103,  1104,     0,  1105,
       0,     0,  1106,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,     0,
       0,     0,  1113,  1108,     0,     0,     0,  1109,     0,     0,
       0,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
       0,     0,  1111,  1092,  1093,  1094,     0,     0,     0,  1095,
       0,     0,     0,     0,     0,     0,     0,  1107,  1095,     0,
    1114,  1112,     0,     0,     0,  1110,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,  1111,     0,     0,     0,     0,     0,     0,
       0,  1105,     0,     0,  1106,     0,  1096,  1097,  1098,  1099,
    1100,  1101,  1112,     0,  1110,  1096,  1097,  1098,  1099,  1100,
    1101,  1107,  1102,  1103,  1104,     0,     0,  1777,     0,     0,
       0,  1102,  1103,  1104,     0,  1105,  1108,     0,  1106,     0,
    1109,     0,  1111,  1113,  1094,   722,   723,     0,     0,     0,
       0,   269,   724,   725,    41,     0,     0,  1095,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,     0,     0,     0,     0,   726,     0,     0,     0,
       0,   727,     0,     0,  1113,     0,     0,     0,   728,     0,
       0,     0,     0,     0,     0,     0,  1111,     0,     0,     0,
    1114,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,  1107,     0,  1112,   729,     0,     0,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,  1109,  1113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,  1114,  1105,     0,     0,  1106,     0,     0,     0,     0,
       0,  1105,  1108,     0,  1106,     0,  1109,     0,     0,     0,
    1110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     722,   723,     0,     0,     0,     0,   269,   724,   725,    41,
       0,     0,     0,     0,     0,     0,     0,  1113,  1111,     0,
    1114,     0,     0,     0,  1110,     0,    82,     0,   730,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,     0,
       0,   726,     0,     0,     0,     0,   727,     0,     0,     0,
       0,     0,  1111,   728,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,   729,     0,  1106,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,     0,     0,     0,     0,  1108,
       0,     0,     0,  1109,     0,     0,     0,     0,  1108,  1113,
       0,     0,  1109,     0,     0,   731,     0,     0,     0,     0,
     732,     0,     0,     0,     0,     0,  1883,  1884,     0,  1885,
       0,     0,   269,  1886,  1887,    41,     0,     0,     0,     0,
       0,  1110,     0,  1113,     0,     0,     0,     0,   733,     0,
    1110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,   730,     0,     0,     0,     0,     0,  1111,
       0,     0,  1888,     0,     0,     0,  1114,     0,  1111,     0,
       0,     0,     0,   734,     0,     0,     0,     0,  1112,     0,
       0,     0,  1107,     0,     0,   735,     0,  1112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
    1114,  1109,     0,   736,     0,     0,     0,     0,   737,     0,
       0,   738,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   739,     0,     0,     0,     0,     0,   740,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   741,  1110,
       0,     0,     0,   742,     0,     0,   743,     0,     0,   744,
     731,     0,     0,     0,     0,   732,   722,   723,   745,   746,
    1113,     0,   269,   724,   725,    41,     0,  1111,     0,  1113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   733,     0,     0,  1112,   698,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   726,     0,  1201,
     747,     0,   727,     0,   748,     0,     0,     0,     0,   728,
       0,     0,   749,     0,     0,     0,     0,     0,   734,     0,
       0,     0,     0,   750,     0,     0,     0,  1114,     0,   751,
     735,     0,     0,     0,     0,     0,  1114,   729,     0,     0,
       0,     0,     0,   722,   723,     0,     0,     0,   736,   269,
     724,   725,    41,   737,   752,     0,   738,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   739,  1113,     0,
       0,     0,     0,   740,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   741,   726,     0,     0,     0,   742,   727,
       0,   743,     0,     0,   744,     0,   728,     0,   753,     0,
       0,     0,     0,   745,   746,   754,     0,   755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   756,   757,   758,
       0,     0,     0,     0,   729,     0,   759,    82,     0,   730,
       0,     0,     0,  1883,  1884,  1114,  1885,   272,     0,   269,
    1886,  1887,    41,     0,     0,   747,     0,     0,     0,   748,
       0,     0,     0,     0,     0,     0,     0,   749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   750,     0,
    2157,     0,     0,     0,   751,     0,     0,     0,     0,  1888,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,  1889,     0,     0,     0,     0,     0,     0,   752,
       0,     0,     0,     0,     0,     0,     0,  1890,     0,     0,
       0,     0,  1883,  1884,    82,  1885,   730,     0,   269,  1886,
    1887,    41,     0,     0,  1891,     0,   731,  1892,     0,     0,
       0,   732,     0,     0,     0,   204,   205,     0,     0,     0,
    1893,     0,     0,   753,   206,     0,     0,     0,     0,     0,
     754,     0,   755,     0,     0,     0,     0,     0,  1888,   733,
       0,     0,   756,   757,   758,     0,     0,     0,  2221,     0,
       0,   759,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1895,   272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1896,   734,     0,     0,     0,     0,     0,
       0,     0,  1883,  1884,   698,  1885,   735,     0,   269,  1886,
    1887,    41,     0,   731,     0,     0,     0,     0,   732,     0,
       0,     0,     0,     0,   736,     0,     0,     0,     0,   737,
       0,     0,   738,     0,     0,  1897,     0,     0,     0,     0,
       0,     0,     0,   739,     0,     0,   733,     0,  1888,   740,
       0,     0,     0,     0,  1883,  1884,     0,  1885,     0,   741,
     269,  1886,  1887,    41,   742,     0,     0,   743,     0,     0,
     744,     0,     0,     0,  1898,     0,     0,     0,     0,   745,
     746,   734,     0,   698,     0,     0,  1899,     0,     0,     0,
       0,     0,     0,   735,     0,     0,     0,     0,  1900,  1901,
    1888,     0,     0,     0,     0,     0,     0,  1902,  2048,     0,
    1903,   736,     0,     0,   207,     0,   737,     0,   272,   738,
    2514,   747,     0,     0,     0,   748,     0,     0,     0,     0,
     739,     0,     0,   749,  2575,  2576,   740,     0,     0,     0,
     269,  1886,  1887,    41,   750,     0,   741,     0,     0,     0,
     751,   742,     0,   208,   743,     0,     0,   744,     0,     0,
       0,     0,     0,     0,     0,     0,   745,   746,     0,     0,
       0,     0,   209,   698,     0,   752,     0,     0,     0,     0,
    2577,     0,     0,     0,     0,     0,     0,  2048,   210,  2575,
    2576,     0,     0,     0,     0,   269,  1886,  1887,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   747,  1889,
       0,   211,   748,     0,     0,     0,     0,     0,     0,   753,
     749,     0,     0,   212,  1890,   698,   754,     0,   755,     0,
       0,   750,     0,   213,     0,  2577,     0,   751,   756,   757,
     758,  1891,     0,     0,  2049,     0,     0,   759,     0,     0,
       0,   214,     0,     0,     0,     0,  2050,  1893,   272,     0,
       0,   215,   752,     0,     0,     0,  2575,  2576,     0,     0,
       0,     0,   269,  1886,  1887,    41,  1885,   216,     0,   269,
    1886,  1887,    41,     0,     0,  2221,     0,     0,  1889,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1895,     0,
       0,     0,     0,  1890,     0,   698,   753,     0,     0,     0,
    1896,     0,  2577,   754,     0,   755,     0,   217,     0,  1888,
    1891,     0,     0,  2049,     0,   756,   757,   758,     0,     0,
       0,     0,     0,     0,   759,  2050,  1893,     0,     0,     0,
       0,   218,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,  1897,     0,     0,     0,   219,     0,     0,     0,
     698,     0,     0,   220,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1895,  1889,     0,
       0,     0,     0,     0,     0,     0,     0,   222,     0,  1896,
     223,  1898,   224,  1890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1899,     0,     0,     0,     0,     0,     0,
    1891,   225,     0,  1892,     0,  1900,  1901,  2051,     0,     0,
       0,     0,     0,     0,  1902,     0,  1893,  1903,     0,   226,
    1889,  1897,     0,     0,     0,   272,     0,   698,     0,     0,
       0,     0,     0,     0,   698,  1890,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1941,  1942,  1943,  1944,
    1945,  1946,  1891,     0,     0,  1892,  3051,  1895,     0,     0,
    1898,     0,   227,     0,     0,     0,     0,     0,  1893,  1896,
       0,     0,  1899,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1900,  1901,  2051,     0,     0,     0,
       0,     0,     0,  1902,     0,     0,  1903,     0,     0,     0,
    1889,     0,     0,     0,   272,  1947,     0,     0,     0,  1895,
       0,  1897,     0,     0,     0,  1890,     0,     0,     0,     0,
       0,  1896,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   838,  2578,     0,     0,  2579,     0,     0,     0,     0,
     839,     0,     0,     0,     0,     0,     0,     0,  2580,   840,
    1898,     0,     0,     0,   841,  1889,     0,     0,     0,     0,
       0,     0,  1899,  1897,     0,     0,     0,     0,     0,     0,
    1890,     0,     0,     0,  1900,  1901,     0,     0,     0,     0,
       0,     0,     0,  1902,     0,     0,  1903,  2578,  2581,  2582,
    2579,     0,     0,     0,   272,     0,     0,   842,     0,     0,
       0,  2583,  1898,  2580,     0,   843,     0,     0,     0,  3015,
       0,     0,     0,     0,  1899,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1900,  1901,     0,     0,
       0,  2221,  1889,     0,     0,  1902,     0,     0,  1903,  1889,
       0,     0,     0,  2584,  2582,     0,   272,  1890,     0,     0,
       0,     0,     0,     0,  1890,     0,  2583,     0,     0,     0,
       0,   844,     0,     0,  2578,  3016,     0,  2579,     0,     0,
       0,  1891,     0,     0,  1892,     0,     0,     0,     0,     0,
    2580,     0,  2585,     0,     0,     0,   845,  1893,     0,     0,
    3017,     0,     0,   846,  2586,   847,     0,     0,  2584,  3018,
       0,     0,     0,     0,     0,   848,  2587,  2588,     0,     0,
       0,     0,     0,     0,     0,  2589,     0,     0,  2590,     0,
       0,  2582,     0,     0,     0,     0,   272,     0,  1895,     0,
       0,   849,     0,  2583,     0,  3019,     0,  2585,  1948,   850,
    1896,     0,     0,  3020,     0,     0,     0,     0,     0,  2586,
       0,  1949,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2587,  2588,     0,     0,     0,     0,     0,     0,     0,
    2589,     0,     0,  2590,     0,  2584,   851,     0,     0,     0,
       0,   272,  1897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   852,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2585,  1950,     0,     0,     0,     0,
       0,  1898,  1951,     0,     0,     0,  2586,     0,     0,     0,
       0,     0,     0,  1899,     0,     0,     0,  3021,  2587,  2588,
     853,     0,     0,     0,     0,  1900,  1901,  2589,     0,     0,
    2590,   854,     0,     0,  1902,     0,     0,  1903,   272,     0,
       0,  1952,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1953,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1954,  1955,     0,     0,
       0,     0,  1956,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1957,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1958,     0,     0,  1959,  1960,     0,
       0,     0,     0,  1961,     0,     0,     0,     0,     0,     0,
       0,   855,   856,   857,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   858,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1962,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3022,     0,  1963,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   859
};

static const short yycheck[] =
{
       4,   328,   194,   716,   188,     0,    66,   848,   699,    13,
      14,  1501,   837,   523,   989,   212,   996,  1562,   713,  1003,
     833,   517,  1412,    82,  1377,  1704,   509,   176,   363,    24,
     424,  1380,   515,  1700,   929,    30,   519,   499,   447,   866,
    1366,    45,    46,   419,  1870,  1998,  1811,   154,   943,   545,
    1276,  1277,   548,  2297,  2298,  2299,   481,    62,   118,  1752,
     738,   874,   844,   845,  1308,   847,     5,   849,   850,     5,
    1623,    66,    76,    26,    26,    79,   225,  2184,   454,    20,
     264,   457,   506,    26,   388,    26,     5,    91,    26,    18,
      95,   467,   787,     5,    98,   471,    25,    61,   102,   475,
       5,   105,   106,    24,     5,    26,   482,   111,   112,     5,
      18,   487,   506,   489,  1940,    23,    24,    25,  2411,   495,
       5,     5,   498,   118,     5,     5,    24,     5,    26,   505,
     237,   238,   541,    32,   510,   960,   141,   962,  1031,    99,
     145,    23,   518,    25,    61,    24,   150,    26,   340,   153,
      23,   161,    25,   529,   158,    26,    75,   533,    86,    87,
     510,   537,    81,    23,    24,    25,    26,   543,    26,     5,
     546,    67,  2300,    69,  1064,    71,    24,    64,    26,    23,
      24,    25,   448,    32,    79,    23,    24,    25,    26,    24,
      25,    26,   196,    23,    24,    25,    26,     5,  2226,  2227,
    2228,  2229,    26,   395,   470,    20,    26,    26,   133,    24,
    1889,    26,     9,   148,    11,    12,    13,    14,    15,    16,
     933,     5,   227,  1042,  2517,    23,    24,    25,    26,     5,
     234,    23,    24,    25,    26,    24,   240,    26,     5,   233,
      26,  1695,  1696,     5,    24,  1699,    26,   251,   514,    24,
     419,    26,    26,   422,   423,     5,     5,     5,   524,   525,
       5,    90,   528,     6,   272,  1635,   532,   436,   534,    24,
     357,    26,   538,     5,   540,   280,     5,   282,  2278,    26,
    1674,     5,   287,  1677,     5,   454,     5,   387,   457,   188,
     188,    25,    26,     5,   463,     6,     5,  2669,   467,   161,
    1936,   293,   471,  2393,   364,   365,   475,     5,   456,     5,
     479,   480,    18,   482,   456,    22,   485,     5,   487,   488,
     489,   624,  1989,  1813,  2277,     6,   495,   537,   188,   498,
     428,   336,   342,     5,     5,   357,   505,   428,   187,   188,
     188,   510,   173,   389,   647,   698,  1800,     5,   353,   518,
     188,   331,   356,    26,   148,   359,     5,     5,   456,    24,
     529,   537,  2188,   367,   533,   456,     0,   272,   537,   364,
     365,   272,   337,     5,   543,   246,   586,   546,    84,   383,
       5,   385,  2049,     5,  2770,   272,  1213,   474,   898,    30,
     188,    47,    48,    49,    50,    51,  1380,    17,    18,   188,
     575,    28,   428,   383,     5,    25,    26,  2793,   188,   413,
     586,  1230,   855,   856,   418,     5,   420,   421,     5,  2805,
     424,   425,     5,   427,   134,   135,   430,   139,   149,   372,
       5,    23,    24,    25,    26,   427,     5,   441,   269,    27,
       5,   616,   625,     9,   448,    11,    12,    13,    14,    15,
      16,     5,   474,   250,   188,   342,   460,   243,     5,  1172,
       5,   837,     5,     5,    55,    56,   470,     5,     5,   473,
     256,   619,   393,     5,   438,     5,   347,   619,     5,   483,
     342,   339,     5,    17,    18,    19,    20,    21,     5,   347,
     348,     5,    83,    84,    85,   499,   500,   584,  2870,     5,
     387,   149,   506,   616,    17,    18,    19,    20,    21,   503,
     514,     5,   516,   517,   372,     5,     5,   375,     5,     5,
     524,   525,    63,   527,   528,   232,   530,   347,   532,     5,
     534,     5,  1986,   543,   538,   393,   540,     5,   542,     5,
     544,   545,   588,   547,   548,     5,   550,  1043,   883,   393,
     885,     5,  1982,     5,   507,   393,  2942,  2011,   658,   567,
    1265,  1252,   584,  2563,   408,  2518,   576,   833,   188,    22,
     408,  2207,   369,  1463,   351,  1037,  1466,   541,  1040,  1041,
    1042,   389,  2672,  1973,   960,   961,   962,   512,   424,   524,
    1816,  2045,   389,  1017,     9,   393,   188,  1059,   469,   625,
     347,   393,   868,  2148,   342,   389,  1301,  1302,   874,   428,
     408,   961,   577,   389,  1984,  1310,   408,   560,    22,   538,
     886,  1514,   389,  1017,   541,   891,   371,   389,  2022,   426,
    1140,   469,   281,  2926,   594,   530,   460,   302,    26,   387,
     552,   499,  1152,   308,   309,   310,   389,  2192,   652,   469,
     588,    26,   979,   552,   428,  2200,  2201,  1153,  1353,   588,
     389,  1014,   567,   328,   545,   549,   567,   545,   837,   549,
     555,   676,    26,   428,   424,   424,   980,   681,   389,   683,
     567,   617,  1577,  2509,   250,  2792,   584,  2715,   474,   469,
     611,   389,   424,   364,   698,   553,  1158,   625,  2826,  2992,
     424,   389,   560,   552,   490,   424,  2471,   626,   389,   713,
    2475,   619,  1136,   666,   666,   424,  1141,   389,   722,   723,
    2273,   617,   661,   666,   434,   666,  2833,   575,   424,   625,
     524,   389,   611,   737,    26,  1231,   281,   619,   513,   743,
     744,  2094,  1136,  1205,   748,  2071,   619,  2096,  2441,  1427,
    3043,   337,  3045,  1997,   758,  1198,  1740,   389,   555,   619,
     549,   648,   649,   650,   389,   499,  1249,   389,  1230,  2223,
      26,   436,   659,  1235,   439,   619,   611,  1273,  1274,   232,
     451,   619,  2810,   787,  2812,  2813,  2814,  2815,   389,   619,
     382,   960,   961,   962,  2794,  2795,   611,   468,   463,   389,
     188,   240,   389,   369,   601,  2891,   389,  1791,   428,   638,
     639,   640,   641,   642,   389,    24,  1225,    26,   483,   553,
     389,   619,  3066,   619,   389,   622,  1651,   619,   232,   833,
     834,  2221,   247,   353,   188,   389,  2290,   329,   166,  2597,
     511,  2520,   389,  2818,   385,  2798,   389,   389,     5,  2279,
    2280,   389,   389,   518,  2829,   205,   594,   389,   351,   389,
     426,   452,   389,   599,   868,   322,   389,   322,   243,   410,
     874,   545,   389,   538,   539,   389,  1142,  1143,  1144,  1389,
     551,   256,   886,   389,   549,   992,   359,   891,   995,   554,
     424,   337,   896,   485,   367,   389,  1162,    25,    26,   389,
     389,    26,   389,   389,   156,     5,    24,   360,    26,   580,
     914,   424,   358,   389,  2882,   389,  2884,   364,   589,   537,
    1403,   389,    13,   389,  3010,   929,   582,   618,   593,   389,
      25,    26,   188,  1199,   625,   389,  2579,   389,   441,   943,
     413,  2167,  2048,   617,  2050,   456,  1641,   428,  2402,   540,
    2404,   243,     0,   494,  1013,  2500,   360,   460,  1224,    25,
      26,   626,  2788,    24,   256,    26,   428,   156,   586,   384,
     473,   386,  1156,   280,   455,  1241,    24,   389,    20,   188,
    1463,    25,    26,  1466,    26,  1251,   293,    27,    28,   555,
     246,   577,   583,   997,   382,  1836,   520,  1001,  1002,  1003,
      23,    24,    25,    26,   451,    17,    18,    19,    20,    21,
    1014,   423,   532,  1017,   111,  1019,  1020,  1513,    18,  1023,
     512,   468,   479,    23,   479,    25,   546,   619,   382,   534,
      24,   523,    26,  1037,  1038,   601,  1040,  1041,  1042,  1043,
      63,  1045,   294,   333,  1048,   428,   587,   397,  2806,  2807,
    1560,   571,   280,   428,   344,  1059,   622,  1061,   599,   600,
     188,  1065,    20,   188,   511,   293,  2046,   608,    26,  1073,
     188,  1075,  1076,   428,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  2771,   188,  2773,  1922,    24,   456,    26,   474,
     620,   428,  1106,  1107,   551,   294,   396,  1111,   436,  1113,
    2564,  3079,  2096,  2093,   428,   490,   852,  1627,   370,   447,
     427,   411,   188,   859,  1128,    60,  1622,   188,    20,   423,
    1506,   577,  1136,   580,    26,    24,   428,    26,  1142,  1143,
    1144,   469,   589,    24,   188,    26,  1608,  1609,   476,  1153,
    1299,  1155,   469,  1157,  1158,    24,  1305,    26,  1162,  2613,
     477,   624,   529,  1988,  2831,   188,   533,   624,  2811,   624,
     537,    24,   456,    26,  2817,   428,  2566,  2820,  2821,  2822,
    2823,   370,   474,   646,   647,  2010,   643,   644,   643,   644,
    2296,  2297,  2298,  2299,   188,  1199,   364,   132,   490,   427,
      25,  1205,   455,   456,    20,   428,   663,   479,   663,   428,
      26,   501,  2107,  1904,  1549,    24,  2414,    26,  1484,  2417,
    1224,  1731,   474,    20,  1228,   162,  1230,  1231,   165,    26,
     428,  1235,   455,   456,  1341,  1239,  1240,  1241,   490,   428,
     853,   854,  1508,  1350,   857,   858,  1512,  1251,    17,    18,
      19,    20,    21,    20,  1630,   236,   456,   428,  1741,    26,
     188,  1265,   197,   489,   199,    34,   519,   428,  1272,  1273,
    1274,    25,   498,   236,   428,  1651,  1971,  1543,   428,   214,
    1742,   428,  1792,   451,  1794,   474,  2392,   222,    24,  2395,
      26,   226,   162,  1803,  1298,   165,   519,  1301,  1302,   188,
     468,   490,  1306,  1569,  1308,  2948,  1310,   188,  2951,  2952,
    2953,  2954,   293,    24,   625,    26,   251,   543,  2013,   189,
     546,   625,    91,    92,    93,    94,    95,    96,   455,   456,
     293,   268,    25,  3000,   271,   188,    20,  1506,   107,   108,
     109,  1346,    26,   511,  2919,  2920,    25,  2801,   162,  1353,
      25,   165,   624,    20,   293,  2809,   293,   638,   364,    26,
     641,   642,  1366,    33,   345,    35,    36,    37,   349,    25,
     393,   643,   644,  1377,  2035,   189,  1380,   389,   544,   188,
    2041,   547,   345,   551,   550,   408,   349,    24,   588,    26,
      33,   663,    35,    36,    37,  1399,  1400,  1401,   268,  1882,
      25,   271,   425,  2216,   619,   428,   345,  2939,   624,   456,
     349,   457,   580,  2945,    25,  3058,   436,    25,   441,   619,
      25,   589,  2912,   293,   364,   471,    24,   447,    26,   475,
     646,   647,  1436,  1437,  1438,   423,  1440,  2085,  2892,  2087,
    2088,   487,  2269,  2423,    25,   451,   427,  2431,   436,   469,
      25,    24,   188,    26,   268,    25,   476,   271,  3033,   482,
    3035,  1630,   468,  1467,   427,    57,  1470,  1733,   619,  2575,
    2576,   494,    24,  2579,    26,   463,   428,   188,   247,   293,
    1484,   250,  1651,   389,    24,   364,    26,   359,   427,  3034,
     427,   479,   480,     5,   107,   108,   109,   485,  1502,   619,
     488,   158,   639,   640,  1508,   511,  1510,  1511,  1512,  1513,
      23,   451,    25,   536,    23,    25,    25,   174,   175,    24,
      25,  1915,  3012,   428,    23,   182,    25,   428,   468,  1795,
    1796,  1797,  1798,    17,    18,    19,    20,    21,   424,  1543,
    1732,  3031,   455,   456,  1548,   551,   285,   286,  1137,   132,
    1139,     5,   575,  1819,  1558,   641,   642,   427,  1562,   216,
     389,  1758,  1883,  1884,   587,  1569,   648,   649,   225,   648,
     649,   511,   451,  1577,   580,    25,   599,   600,   456,  1583,
    1584,   619,  1586,   589,   256,   608,  2575,  2576,   611,   468,
    2100,  2296,  2297,  2298,  2299,   389,   619,   254,   268,   359,
     369,   271,  3092,   273,  1608,  1609,  1982,   424,    20,    25,
    1876,   551,  1988,   427,   197,   384,   199,    25,  1622,   388,
      25,    25,    25,   293,   428,   268,    20,    25,   271,  3083,
     273,   214,   511,   303,  2010,    25,    25,  1641,   389,   222,
     580,  2151,   299,   226,   612,   613,   614,   615,  2489,   589,
     293,  2626,   322,   619,   237,     5,  1660,   426,   389,   389,
     303,   132,   364,   389,  2491,   364,   300,   389,   251,  1673,
    1674,    18,   551,  1677,   389,   345,    23,    24,    25,   349,
     389,   623,     5,   389,   341,   454,   300,   623,   389,  1693,
     428,  1695,  1696,   389,   389,  1699,  1700,   389,   619,   456,
     616,   580,   345,     8,   473,  2811,   349,   619,   424,   477,
     589,  2817,  2818,    26,  2820,  2821,  2822,  2823,   428,   524,
     428,   428,  1726,  2829,   428,  1729,   197,   418,   199,  1733,
     428,   428,   264,   457,   428,  2001,  1740,  2003,  1742,   428,
     428,  2436,   428,   214,  1748,   428,   258,   428,   428,   451,
     196,   222,   451,     5,   200,   226,   617,   427,    17,    18,
      19,    20,   428,   428,   428,   428,   468,   428,    33,   468,
      35,    36,    37,   428,   428,   428,  1780,   428,   428,  1783,
     251,   428,   617,  2496,   427,   297,   555,  1791,   594,   418,
     103,  1795,  1796,  1797,  1798,   457,  1800,  2259,   658,  2261,
     428,  1759,  1806,  1807,   316,  1763,  1810,  1811,   658,   511,
    1768,     8,   511,  1982,  1772,  1819,  1774,  1775,  1776,  1988,
     324,   595,     5,     5,   381,  1829,   428,   428,   428,   428,
     588,   428,    91,    92,    93,    94,    95,    96,     8,   342,
     153,  2010,  2948,   355,   577,  2951,  2952,  2953,  2954,   551,
      13,    29,   551,   622,   574,   367,     5,   658,     5,   658,
     418,    17,    18,    19,    20,   377,   428,    45,    46,   428,
    2575,  2576,  1876,    25,  2579,   188,    64,   190,   580,  1883,
    1884,   580,    25,   395,    90,   456,    25,   589,  1892,   456,
     589,  2157,     5,   405,  2160,   428,   619,   428,   588,  1903,
    2591,   469,   428,  2279,  2280,    20,   625,  2734,    20,   421,
     428,  1915,   594,   428,   428,  2742,   661,   428,  2428,  1923,
     625,  2330,  2331,  2332,   624,  2334,  2335,  2336,  2337,  2338,
    2339,   348,   555,    17,  2343,    91,    92,    93,    94,    95,
      96,    18,     5,   121,   122,    25,   124,   125,  2458,   461,
    2216,   129,  3058,    25,   625,   151,   216,    19,    20,    24,
    3066,   588,  2667,   622,   480,  2670,     5,  1971,   146,   147,
     577,   619,   480,   485,   287,  2035,   545,   149,     5,   545,
      25,  2041,  1986,  2479,   397,  1989,   164,   319,   500,   545,
    2486,    25,  1996,  1997,  1998,   507,   428,  2001,   510,  2003,
     446,   447,   428,   268,   428,  2830,   271,  2011,   273,  2013,
     428,   663,  2707,   428,   389,   619,   456,   545,  2022,   531,
     575,   389,   534,  2215,   536,   389,   389,   389,   293,    91,
      92,    93,    94,    95,    96,   389,    25,   389,   303,   616,
    2035,  2045,   355,   555,   389,  2049,  2041,  2051,   389,   389,
     363,   428,     5,   625,   367,     5,   578,   322,  2062,    19,
      20,   573,     5,     5,   625,   619,     5,  2071,    17,    18,
     481,    20,   389,   428,    23,    24,    25,    26,   624,   428,
     345,    25,   552,  2910,   349,    25,   428,   534,    64,   323,
    2094,   404,  2096,     5,     5,   541,   389,   428,   428,   595,
    2104,   358,   625,  2107,    13,   551,  2811,   418,  2112,   418,
    2279,  2280,  2817,  2818,    63,  2820,  2821,  2822,  2823,     5,
     659,   549,   545,     5,  2829,    25,    99,   428,   619,    61,
     625,    91,    92,    93,    94,    95,    96,   428,   624,     5,
     638,   424,   970,  2147,  2148,     6,     7,     8,     9,    10,
      11,    12,   424,  2157,   458,   458,  2160,   428,   428,   472,
     428,  2165,   427,     8,   428,   428,   428,   428,     5,    25,
      25,   389,   389,    24,  2178,    24,  2180,    24,  2182,   588,
     389,    24,   389,     5,   619,  2189,     5,  2882,  2192,  2884,
     619,     8,  2196,   323,   619,    24,  2200,  2201,   511,   619,
     342,   133,   134,   456,  2917,   342,   342,   428,   358,   423,
    1586,   456,  2216,   428,     5,   428,  2482,   428,   428,  2223,
    3047,  2225,    25,   536,   428,   428,  2736,  2231,  2232,  2233,
    2234,  2235,  2236,  3015,  3016,  3017,  3018,  3019,  3020,   188,
     650,   428,     5,  2948,     5,  2511,  2951,  2952,  2953,  2954,
      24,    13,    25,    13,   428,  2259,   188,  2261,   594,   594,
     616,   619,   194,     5,     5,     5,   619,   580,   428,     7,
     716,  2733,   389,  2277,  2540,     5,   589,   625,    25,    25,
     619,  2986,    25,     8,   389,   619,  2290,   625,   389,  2473,
      25,   588,  2296,  2297,  2298,  2299,  2300,  2301,  2625,   625,
     389,   389,   389,   389,   389,    20,     5,  2311,  2312,  2313,
     565,   272,     5,   389,     5,  2319,   762,   545,     5,   238,
       5,   389,   570,   625,   619,   389,   722,   723,   438,   619,
     389,   428,   264,     6,   266,   469,   625,     5,   625,   208,
     552,   737,   623,   292,   623,    24,    24,   743,   744,    45,
      46,   618,   748,  3058,    24,    24,   294,    24,   469,    25,
      25,  3066,   758,   444,    25,    25,    25,   428,   428,    25,
      25,     5,  1748,   389,   389,   266,  2380,     5,  2382,   524,
     588,   428,   389,   466,  3079,   549,   238,  2391,    24,  2393,
     389,  2901,   424,  2397,     5,   389,   438,   342,  2402,  2403,
    2404,    20,   138,   428,   552,   428,   428,   428,   340,   428,
     428,   428,     5,     5,    13,   208,     5,   619,   456,   439,
     389,    25,   389,   389,    25,   121,   122,  2431,   124,   125,
     389,  2435,  2436,   129,     5,   366,   329,   618,   428,   567,
    3153,   389,   371,    25,   393,  2449,   428,   342,   389,   239,
     146,   147,   389,   389,  2830,   389,   456,   625,   574,   408,
     428,   389,   389,   395,   389,   389,   389,  2471,   164,   389,
    2474,  2475,  2738,   619,   545,  2479,   425,    13,  2482,   428,
     237,   237,  2486,     7,    25,   625,   389,   933,   445,   390,
      25,   440,   441,   428,   619,    62,  2500,   389,   625,   389,
     432,   625,   389,   424,  1332,  1333,   428,  2511,     5,     5,
     389,  1339,    24,   239,  2518,   389,  1892,   389,   389,   389,
       5,   389,  2526,  2104,   389,  2529,  2530,  2531,  2532,  2533,
     389,  2195,  3102,   482,   466,  2147,  2540,  1866,   234,    34,
     472,  1570,   474,    37,   364,   494,   478,    39,  1807,   481,
    2178,  1813,   484,  2557,   287,  1242,   141,   145,   209,   281,
    2564,   397,   494,  1345,   288,  1346,   353,   211,  2444,  2573,
    1766,  2575,  2576,   371,   383,  2579,  3092,   316,   315,   385,
    1783,   513,  1543,  1417,   967,  1678,  2590,   536,  1671,   521,
     522,   523,  1797,  1512,   527,   527,    91,    92,    93,    94,
      95,    96,  1275,   535,  1272,  2250,  2543,  1600,  3117,  2613,
    1919,  2615,   107,   108,   109,  1801,  1617,  1158,  2750,   551,
      24,    30,  1998,    24,  2647,    26,   575,   118,    30,  1575,
     484,  1581,   683,   117,   266,  1280,  1584,  1917,   587,  2847,
     654,  2644,  1038,  1149,    45,    46,   934,  1196,  1633,  1045,
     599,   600,  1048,  3031,  2232,  2370,  1139,  2857,  2044,   608,
     886,  2830,   611,  2667,  1224,  1061,  2670,  1069,  2672,  1065,
     619,  2675,  2352,  2049,  2368,  1791,  1982,  1073,  3119,  1075,
    1076,  3083,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1360,  1023,  2014,  2707,  2969,  1383,  2401,  2711,  2045,  2713,
    1106,  1107,  1699,  2380,  2707,  1111,  2382,  1113,  2051,  2437,
     121,   122,  2670,   124,   125,  1553,  1172,  2986,   129,  2733,
     297,  2923,  2681,  1298,  2738,   219,  2062,  2313,   963,   435,
    2893,  2574,  2894,   227,  3081,   146,   147,  2291,  2435,   233,
    2862,   235,   247,  2231,  2936,   250,  1294,  2573,   959,  2809,
    3026,  2828,   246,   164,  2817,  1267,  1154,  1729,  1596,    29,
      -1,   362,  2776,    -1,    -1,    -1,    -1,    -1,    -1,  1225,
      -1,    -1,    -1,    -1,   716,    45,    46,   188,   355,    -1,
     274,    -1,    -1,    -1,  2798,    -1,    -1,  2801,    -1,    -1,
     367,    -1,    -1,    -1,    -1,  2809,   290,  2811,    -1,    -1,
     377,   295,    -1,  2817,  2818,    -1,  2820,  2821,  2822,  2823,
      -1,    -1,  2826,   307,  2828,  2829,    -1,  2831,   395,    -1,
     314,  2091,    -1,   234,  1280,  2839,    -1,    -1,   405,    -1,
      -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2225,
      -1,    -1,   784,    -1,   421,  2231,  2232,  2233,  2234,  2235,
    2236,   121,   122,    -1,   124,   125,    -1,    -1,    -1,   129,
      -1,    -1,    -1,  3139,   369,    -1,    -1,    -1,  2882,    -1,
    2884,    -1,    -1,  2887,    -1,    -1,   146,   147,  2892,   384,
    2894,    -1,    -1,   388,    -1,   827,    -1,    -1,    -1,    -1,
      -1,  2277,    -1,   470,   164,    -1,    -1,    -1,    -1,    -1,
      -1,   843,   844,   845,    -1,   847,    -1,   849,   850,    -1,
      -1,    -1,    -1,   855,   856,    -1,    -1,    -1,    -1,    -1,
      -1,   426,  2936,   500,    -1,    -1,    -1,    -1,    -1,    -1,
    2944,    -1,    -1,   510,  2948,    -1,    -1,  2951,  2952,  2953,
    2954,  2955,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,
      -1,    -1,    -1,    -1,   531,  2969,   898,   534,    -1,   536,
      -1,    -1,    -1,    29,    -1,    -1,    -1,   909,   473,    -1,
      -1,    -1,  2986,    -1,    -1,   469,  2990,    -1,    -1,    45,
      46,    -1,   476,    -1,    -1,    -1,  3000,   564,    54,    -1,
      -1,   933,   934,    59,    -1,    -1,   573,    -1,    -1,    -1,
     942,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,   503,
      -1,  2397,  3026,  3027,    -1,    -1,   958,   959,    -1,    29,
    3034,    -1,  1860,  1861,   435,    -1,  2296,  2297,  2298,  2299,
    1436,  1437,  1438,  1871,  1440,    45,    46,    -1,   104,   105,
      -1,    -1,    -1,    -1,  3058,    -1,   112,    -1,    -1,  2435,
     555,    -1,  3066,    -1,    -1,   121,   122,    -1,   124,   125,
      -1,  1467,    -1,   129,    74,  3079,    -1,  3081,    -1,  3083,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,    -1,    -1,   354,    -1,  1924,  1925,  1926,  1927,
      -1,    -1,    -1,    -1,  1932,  1933,  1934,  1935,   164,    -1,
      -1,  1939,    20,    21,    -1,  3119,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,   124,   125,    34,   622,    -1,   129,
      -1,  2391,    -1,  2393,    -1,  3139,    -1,    -1,    -1,    -1,
    1586,    -1,  2518,   403,    -1,    -1,   146,   147,    -1,    -1,
    2526,    -1,  1548,  2529,  2530,  2531,  2532,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,    -1,  1562,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,  2023,  2024,  1129,    -1,   107,
     108,   109,  2030,  2031,    -1,  1137,    -1,  1139,  1140,  1141,
      -1,    -1,    -1,    -1,    -1,    -1,  1148,  1149,    -1,    -1,
    1152,    -1,    -1,    -1,  1156,    -1,    -1,  1159,    -1,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
    1172,    -1,    -1,    -1,    -1,    -1,    -1,  1693,    -1,    -1,
      -1,    -1,    -1,    -1,  1700,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,  2675,
      -1,    -1,  1748,    -1,    -1,  1237,    -1,    34,    -1,   365,
      -1,    -1,    -1,    -1,    -1,  2575,  2576,    -1,    -1,  2579,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,
      -1,    -1,    -1,    -1,  1266,   391,    -1,    -1,    -1,   247,
    2168,  2169,   250,    -1,    -1,    -1,    -1,  1279,  1280,  2177,
      -1,    -1,    -1,    -1,   354,    -1,    -1,  2185,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,  2204,  2205,    -1,    -1,
     107,   108,   109,    -1,  1780,    -1,    -1,  1783,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
    2776,    -1,  1334,   403,    -1,    -1,   462,  2667,    -1,    34,
    2670,    -1,  2672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2260,    -1,  2262,   435,    -1,  1883,  1884,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1892,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1389,    -1,    -1,
      -1,   369,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,
     388,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2320,  2321,    -1,    -1,  2324,  2325,    -1,    -1,
     556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2887,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,
     247,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
    2358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1989,    -1,    -1,   454,    -1,    -1,    -1,
      -1,  2811,  1998,    -1,    -1,    -1,    -1,  2817,  2818,    -1,
    2820,  2821,  2822,  2823,    -1,   473,    -1,    -1,  2944,  2829,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2862,  2049,    -1,  2051,    -1,    -1,    -1,  1541,
      -1,    -1,    -1,    -1,  2990,    -1,    -1,    -1,  1550,    -1,
      -1,    -1,   247,    -1,    -1,   250,    -1,    -1,  1560,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    -1,    -1,
      -1,    -1,   369,    -1,  2472,  2091,    -1,   555,  2476,  1581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2948,    -1,
      -1,  2951,  2952,  2953,  2954,  1627,  1628,  1629,    -1,   426,
      -1,  1633,    -1,    -1,    -1,  3081,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2541,   622,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    -1,  2986,   454,    -1,    -1,
      -1,    -1,    -1,  1665,   175,    -1,    -1,    -1,    -1,    -1,
      -1,   182,    -1,  3119,   369,    -1,   473,    -1,    -1,    -1,
      -1,  2147,  2148,    -1,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    97,  2225,
      -1,    -1,    -1,    -1,   225,  2231,  2232,  2233,  2234,  2235,
    2236,    -1,    -1,  2189,    -1,    -1,  2192,    -1,  3058,  1731,
    1732,   426,    -1,    -1,  2200,  2201,  3066,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,   454,
      -1,  2277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,    -1,
    2296,  2297,  2298,  2299,    -1,    -1,    -1,    -1,   299,    -1,
    1792,    -1,  1794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2330,  2331,  2332,    -1,  2334,  2335,
    2336,  2337,  2338,  2339,    -1,   622,    -1,  2343,    -1,    -1,
     341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1841,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
     555,    -1,    -1,    -1,  2380,    -1,  2382,    -1,  1870,  2767,
      -1,    34,    -1,    -1,    -1,  2391,    -1,  2393,    -1,    -1,
      -1,  2397,    -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1916,  1917,    -1,    -1,    -1,  2435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   330,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    35,    36,    37,    -1,    -1,    -1,
    2496,    -1,    -1,  2449,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,  2518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2526,    -1,    -1,  2529,  2530,  2531,  2532,    -1,   407,  2021,
      -1,    -1,    -1,  2921,    -1,   414,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,  2500,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2575,
    2576,    -1,    -1,  2579,   453,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,  2974,  2975,    -1,  2977,
      -1,  2979,  2980,    -1,   247,    -1,    -1,   250,    -1,   478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2100,   488,
     489,   162,    -1,    -1,   165,   494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   504,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   526,   199,    -1,
     529,   530,    -1,    -1,    -1,    -1,   535,   208,  3046,  2151,
      -1,  2667,    -1,   214,  2670,    -1,  2672,    -1,    -1,  2675,
      -1,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,   232,  3070,    -1,  3072,   236,   237,   238,   239,    -1,
      -1,    -1,  2184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,  2193,    -1,  2195,    -1,  2197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   592,    -1,    -1,   369,   268,  2210,  3107,
     271,    -1,   273,  2215,    -1,   604,    -1,    -1,    -1,   280,
      -1,   384,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,
      -1,    -1,   293,    -1,    -1,  3133,  3134,    -1,    -1,  3137,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2776,   322,   323,   426,    -1,    -1,    -1,    -1,    -1,  2271,
    2272,    -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,
      -1,    -1,  2798,    -1,   345,    -1,    -1,    -1,   349,    -1,
      -1,   454,    -1,    -1,    -1,  2811,    -1,   358,   359,   360,
      -1,  2817,  2818,    -1,  2820,  2821,  2822,  2823,    -1,    -1,
     473,    -1,  2314,  2829,    -1,  2831,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2862,    -1,    34,    -1,
      -1,    -1,  2354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2367,   427,    -1,    -1,    -1,
      -1,  2887,    -1,    -1,    -1,    -1,    -1,   438,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2917,    -1,    -1,    34,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,
      -1,   107,   108,   109,    -1,    -1,  2428,    -1,  2944,    -1,
      -1,    -1,  2948,    -1,    -1,  2951,  2952,  2953,  2954,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2458,    -1,    -1,   622,
      -1,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
    2986,  2473,    -1,    -1,  2990,    -1,    -1,   107,   108,   109,
     541,    -1,    -1,    -1,  3000,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2496,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   577,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,  3058,    -1,    -1,    -1,    -1,    -1,    34,    -1,
    3066,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,   247,    -1,   624,   250,  3081,    -1,    -1,  3034,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,   638,   639,   640,
     641,   642,   643,   644,    -1,   646,   647,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   663,  3119,    -1,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,
     250,   107,   108,   109,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,  3153,    -1,    -1,
      -1,    -1,  2644,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,   388,   389,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,  2736,    -1,    -1,    -1,    -1,   369,
     426,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,   388,    -1,
      -1,   247,    -1,    -1,   250,    -1,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,    -1,    -1,   250,   473,    -1,    -1,
    2792,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      17,    18,    -1,    20,   454,    -1,    23,    24,    25,    26,
      -1,  2833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   473,    -1,  2847,    -1,    -1,    -1,    -1,
    2852,    -1,  2854,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,   555,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2893,    -1,    -1,    -1,    -1,    -1,    -1,   384,  2901,
      -1,    -1,   388,   389,    -1,   369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2917,    -1,    -1,    -1,    -1,
     384,  2923,    -1,    -1,   388,   555,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,   622,    -1,    -1,    -1,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,   247,    53,    -1,   250,
      -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,   454,    65,
      66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,   473,    -1,    -1,
     454,   188,   622,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,   473,
      -1,    -1,    -1,  3015,  3016,  3017,  3018,  3019,  3020,    -1,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    -1,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,   140,    -1,   142,   143,   144,    -1,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,   155,
      -1,   157,    -1,   159,   160,    -1,    -1,   163,   164,   555,
      -1,   167,   168,   169,    -1,   171,   172,    -1,   369,    -1,
     176,   177,    -1,   179,    -1,    -1,    -1,   183,    -1,   185,
     186,   555,    -1,   384,    -1,   191,    -1,   388,   389,   195,
      -1,    -1,   198,    -1,   200,    -1,   202,    -1,   204,    -1,
     206,   207,    -1,   209,   210,   211,    -1,    -1,    -1,   215,
      -1,   217,   218,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,    -1,   426,   622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,   244,   245,
      -1,  3153,   248,   249,    -1,    -1,   252,   253,   622,    -1,
      -1,    -1,    -1,   454,    -1,   261,   262,   263,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     276,   277,   473,   279,    -1,    -1,    -1,   283,   284,    -1,
      -1,    -1,   288,    -1,    -1,    -1,   393,    -1,    -1,    -1,
     296,    -1,    -1,   258,    -1,    -1,    -1,    -1,   304,   305,
     306,   408,    -1,    -1,    -1,    -1,   312,   313,    -1,    -1,
      -1,    -1,   318,    -1,    -1,   321,    -1,    -1,   425,   325,
     326,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,    -1,   297,    -1,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,
      -1,   316,    -1,    -1,   555,    -1,   362,    -1,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   481,   482,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   391,    -1,   494,    -1,    -1,
     355,    -1,   398,    -1,   400,   401,    -1,    -1,    -1,    -1,
      -1,    -1,   367,   409,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   536,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     405,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   459,    -1,    -1,   421,   463,    -1,    -1,
      -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,   575,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     587,    -1,    -1,    -1,    -1,   491,   492,    -1,    -1,    -1,
     496,    -1,   599,   600,    -1,    -1,   461,    -1,    -1,    -1,
      -1,   608,   508,    -1,   611,    -1,    -1,    -1,   514,   515,
     516,   517,   619,    -1,    -1,   521,    -1,    -1,    -1,   525,
     485,    -1,    -1,    -1,    -1,    -1,   532,   533,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   500,    -1,    -1,   544,    -1,
     546,    -1,   507,    -1,    -1,   510,    -1,    -1,    -1,    -1,
      -1,   557,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,   568,    -1,    -1,    -1,   531,    -1,    -1,   534,
      -1,   536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,
     555,   597,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,
     606,   607,    -1,    -1,    -1,    -1,    -1,    -1,   573,    -1,
      -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,
      -1,    -1,   628,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,   651,   652,   653,   654,   655,
     656,   657,    34,    -1,   660,    -1,   662,    -1,   664,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
     247,    -1,    -1,   250,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,   247,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,   388,   389,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,   247,    -1,   384,   250,    -1,
      -1,   388,   389,    -1,   426,   107,   108,   109,    -1,    -1,
      -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,    -1,   384,   250,    -1,    -1,
     388,   389,   454,    -1,    -1,    -1,    -1,    -1,    -1,   426,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,   426,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,   473,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   473,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,   555,    -1,    -1,   388,   389,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   369,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      -1,   384,    -1,    -1,    -1,   388,   389,    -1,   555,    -1,
     107,   108,   109,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,    -1,
     622,    -1,   454,   426,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    34,    -1,    -1,   622,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
     473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,   622,    -1,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,   388,    -1,    -1,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   555,    -1,   107,   108,   109,    -1,    -1,
     247,    -1,    -1,   250,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,   107,   108,   109,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     622,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   369,    34,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,   247,    -1,   384,   250,    -1,
      -1,   388,    -1,   555,    -1,   107,   108,   109,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,   247,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,   426,
      91,    92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   439,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,
     622,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,   473,    -1,    -1,    91,
      92,    93,    94,    95,    96,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,   388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   369,    -1,   250,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    -1,
      -1,   384,    -1,    -1,    -1,   388,    -1,    -1,   555,   107,
     108,   109,    -1,    -1,   426,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,    -1,    34,   250,
      -1,    -1,   454,   426,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    34,    -1,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,   250,    -1,
     473,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,   388,    -1,    -1,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   555,    -1,   107,   108,   109,    -1,   247,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   369,    -1,
      -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,   384,    -1,    -1,    -1,   388,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,   454,    19,    20,    21,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,    34,    -1,
     622,   473,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,   388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,    -1,    -1,   250,    -1,    91,    92,    93,    94,
      95,    96,   473,    -1,   426,    91,    92,    93,    94,    95,
      96,   369,   107,   108,   109,    -1,    -1,   439,    -1,    -1,
      -1,   107,   108,   109,    -1,   247,   384,    -1,   250,    -1,
     388,    -1,   454,   555,    21,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    34,    -1,    -1,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,   555,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,
     622,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      -1,    -1,    -1,   369,    -1,   473,    98,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,   388,   555,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,
      -1,   622,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,   247,   384,    -1,   250,    -1,   388,    -1,    -1,    -1,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,   454,    -1,
     622,    -1,    -1,    -1,   426,    -1,   188,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,   454,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,    98,    -1,   250,   622,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,   384,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,   384,   555,
      -1,    -1,   388,    -1,    -1,   287,    -1,    -1,    -1,    -1,
     292,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,   426,    -1,   555,    -1,    -1,    -1,    -1,   320,    -1,
     426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,   190,    -1,    -1,    -1,    -1,    -1,   454,
      -1,    -1,    63,    -1,    -1,    -1,   622,    -1,   454,    -1,
      -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,   473,    -1,
      -1,    -1,   369,    -1,    -1,   367,    -1,   473,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,
     622,   388,    -1,   385,    -1,    -1,    -1,    -1,   390,    -1,
      -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   404,    -1,    -1,    -1,    -1,    -1,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,   426,
      -1,    -1,    -1,   425,    -1,    -1,   428,    -1,    -1,   431,
     287,    -1,    -1,    -1,    -1,   292,    17,    18,   440,   441,
     555,    -1,    23,    24,    25,    26,    -1,   454,    -1,   555,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   320,    -1,    -1,   473,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,   481,
     482,    -1,    63,    -1,   486,    -1,    -1,    -1,    -1,    70,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,   355,    -1,
      -1,    -1,    -1,   505,    -1,    -1,    -1,   622,    -1,   511,
     367,    -1,    -1,    -1,    -1,    -1,   622,    98,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,   385,    23,
      24,    25,    26,   390,   536,    -1,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,   555,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    58,    -1,    -1,    -1,   425,    63,
      -1,   428,    -1,    -1,   431,    -1,    70,    -1,   580,    -1,
      -1,    -1,    -1,   440,   441,   587,    -1,   589,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,   600,   601,
      -1,    -1,    -1,    -1,    98,    -1,   608,   188,    -1,   190,
      -1,    -1,    -1,    17,    18,   622,    20,   619,    -1,    23,
      24,    25,    26,    -1,    -1,   482,    -1,    -1,    -1,   486,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   505,    -1,
     507,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,   536,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,
      -1,    -1,    17,    18,   188,    20,   190,    -1,    23,    24,
      25,    26,    -1,    -1,   425,    -1,   287,   428,    -1,    -1,
      -1,   292,    -1,    -1,    -1,    79,    80,    -1,    -1,    -1,
     441,    -1,    -1,   580,    88,    -1,    -1,    -1,    -1,    -1,
     587,    -1,   589,    -1,    -1,    -1,    -1,    -1,    63,   320,
      -1,    -1,   599,   600,   601,    -1,    -1,    -1,   469,    -1,
      -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   494,   355,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,   188,    20,   367,    -1,    23,    24,
      25,    26,    -1,   287,    -1,    -1,    -1,    -1,   292,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,   390,
      -1,    -1,   393,    -1,    -1,   536,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   404,    -1,    -1,   320,    -1,    63,   410,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,   420,
      23,    24,    25,    26,   425,    -1,    -1,   428,    -1,    -1,
     431,    -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,   440,
     441,   355,    -1,   188,    -1,    -1,   587,    -1,    -1,    -1,
      -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,   599,   600,
      63,    -1,    -1,    -1,    -1,    -1,    -1,   608,   292,    -1,
     611,   385,    -1,    -1,   258,    -1,   390,    -1,   619,   393,
     481,   482,    -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,
     404,    -1,    -1,   494,    17,    18,   410,    -1,    -1,    -1,
      23,    24,    25,    26,   505,    -1,   420,    -1,    -1,    -1,
     511,   425,    -1,   297,   428,    -1,    -1,   431,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,   441,    -1,    -1,
      -1,    -1,   316,   188,    -1,   536,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,   292,   332,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,   393,
      -1,   355,   486,    -1,    -1,    -1,    -1,    -1,    -1,   580,
     494,    -1,    -1,   367,   408,   188,   587,    -1,   589,    -1,
      -1,   505,    -1,   377,    -1,    63,    -1,   511,   599,   600,
     601,   425,    -1,    -1,   428,    -1,    -1,   608,    -1,    -1,
      -1,   395,    -1,    -1,    -1,    -1,   440,   441,   619,    -1,
      -1,   405,   536,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    20,   421,    -1,    23,
      24,    25,    26,    -1,    -1,   469,    -1,    -1,   393,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,    -1,
      -1,    -1,    -1,   408,    -1,   188,   580,    -1,    -1,    -1,
     494,    -1,    63,   587,    -1,   589,    -1,   461,    -1,    63,
     425,    -1,    -1,   428,    -1,   599,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,   440,   441,    -1,    -1,    -1,
      -1,   485,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,
      -1,    -1,   536,    -1,    -1,    -1,   500,    -1,    -1,    -1,
     188,    -1,    -1,   507,    -1,    -1,   510,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,   393,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,   494,
     534,   575,   536,   408,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,
     425,   555,    -1,   428,    -1,   599,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,   441,   611,    -1,   573,
     393,   536,    -1,    -1,    -1,   619,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,   425,    -1,    -1,   428,   481,   482,    -1,    -1,
     575,    -1,   616,    -1,    -1,    -1,    -1,    -1,   441,   494,
      -1,    -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   599,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,   608,    -1,    -1,   611,    -1,    -1,    -1,
     393,    -1,    -1,    -1,   619,    97,    -1,    -1,    -1,   482,
      -1,   536,    -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   425,    -1,    -1,   428,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,   145,
     575,    -1,    -1,    -1,   150,   393,    -1,    -1,    -1,    -1,
      -1,    -1,   587,   536,    -1,    -1,    -1,    -1,    -1,    -1,
     408,    -1,    -1,    -1,   599,   600,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   608,    -1,    -1,   611,   425,   481,   482,
     428,    -1,    -1,    -1,   619,    -1,    -1,   193,    -1,    -1,
      -1,   494,   575,   441,    -1,   201,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,   587,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   599,   600,    -1,    -1,
      -1,   469,   393,    -1,    -1,   608,    -1,    -1,   611,   393,
      -1,    -1,    -1,   536,   482,    -1,   619,   408,    -1,    -1,
      -1,    -1,    -1,    -1,   408,    -1,   494,    -1,    -1,    -1,
      -1,   257,    -1,    -1,   425,   257,    -1,   428,    -1,    -1,
      -1,   425,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,
     441,    -1,   575,    -1,    -1,    -1,   282,   441,    -1,    -1,
     282,    -1,    -1,   289,   587,   291,    -1,    -1,   536,   291,
      -1,    -1,    -1,    -1,    -1,   301,   599,   600,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,   611,    -1,
      -1,   482,    -1,    -1,    -1,    -1,   619,    -1,   482,    -1,
      -1,   327,    -1,   494,    -1,   327,    -1,   575,   330,   335,
     494,    -1,    -1,   335,    -1,    -1,    -1,    -1,    -1,   587,
      -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   599,   600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,   611,    -1,   536,   372,    -1,    -1,    -1,
      -1,   619,   536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   575,   407,    -1,    -1,    -1,    -1,
      -1,   575,   414,    -1,    -1,    -1,   587,    -1,    -1,    -1,
      -1,    -1,    -1,   587,    -1,    -1,    -1,   429,   599,   600,
     436,    -1,    -1,    -1,    -1,   599,   600,   608,    -1,    -1,
     611,   447,    -1,    -1,   608,    -1,    -1,   611,   619,    -1,
      -1,   453,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,   489,    -1,    -1,
      -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   526,    -1,    -1,   529,   530,    -1,
      -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   547,   548,   549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     602,    -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   664
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    45,    46,    74,   121,   122,   124,   125,   129,
     146,   147,   164,   234,   354,   403,   435,   725,   753,   754,
     804,   970,  1025,  1027,  1028,  1029,  1034,  1036,  1049,  1050,
    1051,  1052,  1053,  1468,    27,    28,   726,   727,   728,   729,
     730,    26,   936,  1487,   353,   532,   546,   571,   620,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,   936,    24,   936,
    1389,  1054,   755,   754,  1468,     0,  1026,  1029,  1034,  1052,
    1468,    30,   728,   730,   936,  1471,   588,   936,  1470,   625,
     805,    24,   188,   752,   753,   924,   936,   941,  1055,  1091,
    1092,  1093,  1094,  1095,  1099,   351,   757,   758,   759,   760,
     763,   764,    54,    59,   104,   105,   112,   365,   391,   462,
     556,   637,   645,   725,   731,   896,   969,  1030,  1031,  1033,
    1037,  1038,  1044,  1056,  1077,  1210,  1220,  1468,   936,  1470,
     616,  1094,   240,   455,   456,  1101,    20,   936,  1098,   619,
     758,     5,   756,   351,   936,     5,   780,   782,   783,   936,
    1221,   936,   936,  1211,  1045,   936,   936,  1033,  1039,   258,
     297,   316,   355,   367,   377,   395,   405,   421,   461,   485,
     500,   507,   510,   531,   534,   536,   555,   573,   806,   807,
     808,   811,    24,  1091,  1097,    17,    18,    25,   428,   675,
     677,  1091,  1102,  1103,   456,    13,   803,   760,   520,  1197,
     761,   758,   763,    31,    79,    80,    88,   258,   297,   316,
     332,   355,   367,   377,   395,   405,   421,   461,   485,   500,
     507,   510,   531,   534,   536,   555,   573,   616,   766,   774,
     785,   786,   936,   428,   111,   936,   752,   897,  1078,   936,
     813,   534,   765,   789,   791,   792,   790,   799,   800,   428,
     428,   812,   456,   428,   428,   758,   787,   423,   675,    17,
      18,    19,    20,    21,   676,    25,     5,   424,  1102,    23,
      24,    25,   619,   936,   942,    18,    24,    25,   762,   942,
     776,   765,   777,   789,   790,   428,   428,   775,   456,   428,
     428,   787,   758,   784,   428,    25,   936,   428,  1046,   752,
     752,   428,   936,   428,   455,   769,   625,   364,   451,   468,
     511,   551,   580,   589,   793,   625,   364,   451,   468,   511,
     551,   580,   589,   801,    25,    25,   814,   815,   816,   817,
     936,    25,   772,   773,    25,    25,   619,   389,   675,  1103,
     456,   424,    25,    25,   758,   769,   758,    25,    25,   757,
     772,    25,    25,   619,    57,   781,  1222,   389,   428,  1212,
    1488,  1489,  1490,  1491,  1492,   898,  1079,  1040,   619,    25,
     794,   795,   428,   796,   801,   802,   796,   428,   797,     5,
     389,     5,   389,     5,   281,     5,   806,   424,     5,     5,
     389,   389,   758,   788,  1102,   456,   619,    25,   256,     5,
     389,     5,   389,   281,   424,     5,   389,   389,   788,   936,
    1108,  1109,  1111,  1057,  1108,   359,  1489,  1197,    44,    53,
      65,    66,    68,    82,    89,   100,   101,   102,   116,   118,
     119,   120,   123,   126,   128,   130,   131,   137,   140,   142,
     143,   144,   152,   154,   155,   157,   159,   160,   163,   167,
     168,   169,   171,   172,   176,   177,   179,   183,   185,   186,
     191,   195,   198,   200,   202,   204,   206,   207,   209,   210,
     211,   215,   217,   218,   220,   228,   229,   241,   244,   245,
     248,   249,   252,   253,   261,   262,   263,   265,   275,   276,
     277,   279,   283,   284,   288,   296,   304,   305,   306,   312,
     313,   318,   321,   325,   326,   336,   354,   362,   368,   398,
     400,   401,   409,   448,   459,   463,   467,   491,   492,   496,
     508,   514,   515,   516,   517,   521,   525,   532,   533,   544,
     546,   557,   559,   562,   568,   594,   597,   603,   606,   607,
     621,   628,   651,   652,   653,   654,   655,   656,   657,   660,
     662,   664,   668,   669,   670,   671,   688,   710,   724,   725,
     731,   732,   751,   819,   820,   821,   822,   833,   834,   835,
     836,   888,   892,   922,   943,   944,   947,   948,   949,   950,
     963,   971,   992,   993,   995,   999,  1016,  1017,  1021,  1022,
    1023,  1024,  1032,  1047,  1060,  1071,  1072,  1073,  1084,  1087,
    1124,  1127,  1129,  1135,  1136,  1139,  1142,  1145,  1147,  1149,
    1151,  1158,  1163,  1167,  1168,  1169,  1181,  1182,  1185,  1191,
    1192,  1193,  1218,  1233,  1234,  1235,  1236,  1237,  1242,  1248,
    1249,  1267,  1270,  1299,  1301,  1390,  1391,  1422,  1423,  1430,
    1441,  1468,  1472,  1477,  1479,  1481,  1485,  1486,  1493,   725,
    1035,  1468,   624,   647,  1080,  1081,  1108,    20,   389,   423,
     770,   793,    25,   798,    25,    25,    25,   815,   817,   809,
     773,    25,   424,  1102,    20,   770,   428,    25,    25,   767,
      25,   619,   389,     5,  1108,   389,   936,   347,   937,   938,
    1487,   936,   936,  1165,   931,   937,   931,    24,   188,   936,
    1100,  1463,  1464,  1465,   936,  1483,   936,  1244,  1245,   936,
      25,   672,  1091,  1240,   931,  1165,   862,    25,   942,  1205,
    1206,  1205,    17,    18,    24,    25,    58,    63,    70,    98,
     190,   287,   292,   320,   355,   367,   385,   390,   393,   404,
     410,   420,   425,   428,   431,   440,   441,   482,   486,   494,
     505,   511,   536,   580,   587,   589,   599,   600,   601,   608,
     837,   844,   845,   846,   847,   848,   849,   850,   851,   863,
     868,   879,   880,   881,   882,   936,   942,  1091,  1200,  1269,
    1381,   937,  1431,  1431,   823,  1165,   931,  1238,  1091,   933,
     937,   844,  1431,  1091,  1165,  1091,  1268,  1431,    24,   584,
    1074,  1075,  1091,   931,   931,  1074,   932,   937,   936,  1075,
     931,  1431,   931,   933,  1091,  1122,  1123,   929,   937,   933,
     372,   560,   666,   928,   936,   994,   936,   733,   934,   937,
      24,  1300,  1463,  1088,   862,   937,  1148,   893,   127,   136,
     145,   150,   193,   201,   257,   282,   289,   291,   301,   327,
     335,   372,   398,   436,   447,   547,   548,   549,   560,   664,
    1008,  1143,  1144,  1091,   843,   844,  1157,   839,   862,   928,
    1478,  1478,   930,   937,   862,    24,  1091,  1146,  1219,  1091,
    1196,    24,  1091,  1425,   844,  1187,  1188,  1189,  1198,  1199,
     844,  1473,   103,   153,   190,   287,   363,   404,   472,   536,
     689,   868,   936,  1091,  1228,   712,   844,   929,  1470,  1061,
     844,   929,   844,  1091,  1018,   929,   844,  1442,   844,  1205,
     936,   945,   946,   933,   945,  1478,   933,   945,  1478,   951,
     945,    24,    25,   382,   485,   942,   997,  1091,  1110,  1112,
      64,   272,   342,   387,   567,   648,   649,   650,   659,   679,
     953,   955,   957,   959,   961,  1085,  1086,  1090,   333,   344,
     396,   411,   501,  1302,   639,   640,   900,   901,   902,   936,
    1082,   646,  1081,   389,   300,   389,   389,   389,   389,   623,
       5,   389,   424,   300,   758,   778,   779,   389,   389,   623,
     389,   936,  1223,  1111,   389,  1213,    55,    56,    83,    84,
      85,   452,   540,   583,  1250,  1251,  1252,  1255,  1258,  1261,
    1262,  1263,  1264,   428,   619,  1465,  1101,   616,  1140,   619,
       8,   537,   586,     5,   389,   424,    24,   936,  1374,   477,
    1166,  1110,   107,   108,   109,   837,   837,   428,   524,  1217,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   837,
     364,   451,   468,   511,   551,   580,   589,  1384,  1385,   428,
     428,   428,   837,   837,   428,   428,   749,   837,   428,   852,
     428,   428,   428,   428,   428,   428,   428,   837,   428,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    34,    91,    92,    93,    94,
      95,    96,   107,   108,   109,   247,   250,   369,   384,   388,
     426,   454,   473,   555,   622,   748,   838,   853,   855,   856,
     857,   858,   859,   860,   861,    25,   942,   428,   519,   418,
    1091,  1117,  1374,   678,   679,   826,   264,    86,    87,   625,
     457,     5,   618,   625,   617,   617,  1125,   594,   418,     5,
     555,   972,   457,   658,  1475,   428,   456,   619,   658,   382,
     735,  1091,   545,   617,  1130,  1131,  1132,   324,  1298,   843,
     842,   844,     8,   930,    25,   499,   553,   923,  1091,   923,
     923,   923,  1013,  1014,   923,   923,   595,  1009,   679,  1009,
    1009,   924,   924,  1009,  1009,   679,     5,   331,   383,     5,
     678,   481,   840,   841,   844,     5,    75,    81,   538,   626,
    1000,   661,  1476,   843,   612,   613,   614,   615,  1195,  1197,
     381,  1232,  1197,  1189,     5,   617,  1190,   844,   428,   428,
     428,   428,    24,   708,   936,   428,  1425,   342,   428,   519,
     588,   577,   713,   720,   711,    24,  1076,  1091,  1183,     8,
    1186,    13,   936,  1096,  1104,  1105,  1107,  1115,  1116,  1159,
     161,   342,   543,   576,    32,   188,   552,  1443,  1444,  1445,
    1446,   574,     5,   658,   658,   842,  1110,  1117,   996,   418,
       5,   149,   976,   428,  1091,   842,   428,    25,    25,    64,
    1089,    24,  1091,  1429,  1429,   930,  1148,   930,   117,   219,
     227,   233,   235,   246,   274,   290,   295,   307,   314,   469,
     476,   498,   503,  1271,  1272,  1280,  1289,  1290,  1296,  1297,
    1303,  1304,  1313,  1332,  1336,  1401,  1402,  1432,  1433,  1436,
    1437,  1447,   903,   904,    90,   899,   910,   911,   902,  1083,
    1488,  1041,   456,   806,   773,   456,     5,   389,   780,   752,
    1058,   752,   156,   294,   370,   428,   474,   490,  1319,  1331,
     428,   936,  1266,    25,   243,   256,   428,   474,   490,   936,
    1247,  1260,  1317,  1318,  1323,  1325,  1327,   428,   936,  1257,
     428,  1247,  1253,     5,    24,   939,  1094,  1465,  1463,   575,
     616,  1141,    20,   936,  1121,  1466,   936,  1484,  1245,   594,
     619,   588,   428,   428,   826,   887,   928,   837,   928,   928,
     887,  1478,   469,  1405,   837,    24,    25,    18,    23,    24,
      25,   883,   884,   885,   886,   837,   428,   625,   928,    20,
     837,   389,  1405,   837,    20,  1200,   871,   869,   875,   837,
     873,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   428,   837,   837,   428,   864,   936,  1091,
     625,   428,  1463,    24,   941,  1164,  1164,  1425,  1074,   844,
     844,   844,   925,   926,   428,  1091,  1123,   787,   973,   974,
     625,  1425,  1478,  1476,   936,   675,    20,   666,   936,   994,
    1091,   734,   624,   844,   348,  1134,   555,  1133,     5,    67,
      69,    71,   617,   625,   818,  1110,   894,    17,    18,    24,
     302,   308,   309,   310,   328,   436,   439,   463,   483,   518,
     538,   539,   549,   554,   593,   626,  1015,  1010,  1144,   924,
     844,   342,   594,     5,   928,    25,    25,   678,   151,  1194,
     216,  1199,  1205,  1474,   936,    24,   887,  1478,   588,   928,
     622,  1091,   693,   936,   936,   844,   337,   716,   720,   577,
     714,   722,    22,   232,  1063,  1067,   480,   862,   480,  1184,
     844,   455,  1101,   619,     5,  1019,   545,  1160,  1091,  1464,
    1467,  1091,  1113,  1114,   187,  1444,   964,   946,  1478,  1478,
     956,   957,   976,   976,    33,    35,    36,    37,   268,   271,
     273,   293,   303,   345,   349,   427,   975,   977,   978,  1004,
    1091,  1112,   545,   680,    25,   397,   962,   319,  1424,  1424,
     134,   135,   434,   545,   936,  1333,  1334,  1375,   787,  1374,
    1374,  1273,   787,   936,  1434,  1434,   357,   474,   584,  1413,
    1374,  1281,   166,   436,   447,   469,   476,  1306,  1307,  1308,
     285,   286,  1396,  1488,  1488,   382,   912,  1091,   641,   642,
     905,   906,   907,   479,   624,   643,   644,   663,   915,   916,
    1488,   752,    25,   771,   771,   779,  1224,   752,  1214,  1321,
    1374,  1265,  1331,   428,  1265,   428,   428,  1259,  1260,   428,
     428,    62,   297,   355,   367,   377,   395,   405,   408,   421,
     470,   500,   510,   531,   534,   536,   564,   573,  1366,  1367,
    1368,  1370,  1256,  1257,  1253,  1254,   663,  1251,   389,   619,
    1425,   575,   456,   545,  1482,   673,   674,   936,   936,   936,
    1241,   862,     5,   389,   389,   389,   389,   389,  1413,   389,
     389,   389,   389,   588,   884,    18,    25,   588,   389,   389,
      25,  1385,   389,   389,   389,   389,     5,   750,   389,   837,
     837,   837,   389,   837,   389,   389,   389,   439,   439,   439,
     862,  1405,   439,   862,  1405,   705,   706,   707,   837,   428,
     936,  1239,   616,  1137,   625,     5,     5,     5,   578,   844,
     619,     5,   481,   625,   389,   424,   428,   624,   162,   165,
     268,   271,   736,   739,   740,  1004,   737,   738,   936,   428,
     937,   648,   649,  1138,   844,   936,   936,   926,   927,   507,
    1478,   826,   552,  1286,    25,    25,   428,  1011,  1013,  1091,
     534,  1152,   840,    64,   837,  1197,    25,  1091,  1488,     5,
       5,   389,   389,   709,   936,   389,  1425,   705,   428,   428,
     721,   717,   358,   715,   844,   337,   718,   722,   595,  1006,
    1068,  1064,   360,  1062,  1063,   842,   625,  1097,    20,   936,
    1106,  1116,    13,    17,    18,    20,    24,    25,    63,   393,
     408,   425,   428,   441,   481,   482,   494,   536,   575,   587,
     599,   600,   608,   611,   936,   942,  1161,  1162,  1380,  1382,
    1412,  1417,  1418,  1419,  1467,   418,   418,     5,  1488,   958,
     959,   549,   935,   545,   987,   986,   989,   988,   928,   990,
     928,   991,   985,   984,   982,   981,  1005,   322,   978,   983,
    1478,    38,    39,    40,    41,    42,    43,    97,   330,   343,
     407,   414,   453,   478,   488,   489,   494,   504,   526,   529,
     530,   535,   592,   604,   681,   682,  1002,  1003,     5,    25,
    1425,   246,  1091,   469,  1406,  1407,  1425,  1148,  1400,  1402,
      99,    99,   594,  1146,  1335,  1336,   428,  1314,   148,   524,
    1340,  1347,  1374,   173,   269,  1438,   619,   625,  1403,  1448,
     339,   348,   372,   375,   393,   499,   553,   560,   930,  1283,
    1288,   428,  1309,   624,     5,    24,   936,  1397,  1398,   914,
    1091,     5,   545,   908,   909,   638,   907,   913,   936,   913,
     917,   918,   913,   322,   916,  1042,   424,   424,   458,  1207,
    1227,  1059,   458,  1170,  1201,   428,     5,   389,   292,   428,
     440,   601,  1350,  1351,  1352,  1353,  1354,  1358,  1362,  1364,
    1417,   389,   611,   936,  1320,  1322,  1374,  1377,  1378,  1324,
    1377,     5,   389,  1324,  1350,   364,   451,   468,   511,   551,
     580,   589,  1387,  1387,   428,   428,   428,   428,   428,   428,
     205,   397,  1326,  1328,     5,   389,     5,   389,   936,  1466,
       8,  1425,  1102,   844,     5,  1246,  1247,   862,  1048,   928,
    1414,  1415,  1417,   877,  1385,   877,    25,    25,   588,    23,
      25,   790,   878,  1217,   389,  1217,   791,   389,  1217,   872,
     870,   876,  1217,   874,  1217,  1217,  1217,    24,    24,    24,
     837,   854,   389,    24,   854,   389,   865,     5,   866,   619,
    1246,   575,  1425,  1425,   844,   844,   925,   507,   844,  1480,
       5,    20,  1377,   974,  1425,   619,   936,   737,   745,   744,
     746,   936,   940,   747,   940,   189,   740,   743,     5,   976,
     619,   844,     8,   936,  1287,   895,  1012,  1013,  1091,     5,
     323,    24,  1229,   342,   342,   456,   619,   342,   428,   694,
     698,   691,  1488,  1488,   723,   719,   715,  1007,    24,   935,
    1069,  1091,  1488,   844,   423,   456,   862,  1418,  1418,  1383,
    1387,   469,  1417,   428,   428,   428,   428,   428,   428,   428,
     936,   428,     5,    17,    18,    19,    20,    91,    92,    93,
      94,    95,    96,  1439,  1464,  1091,  1114,    61,   541,   965,
     960,   961,    25,   678,   936,  1488,  1488,  1488,  1488,     5,
     979,     5,   980,  1488,  1488,  1488,  1488,  1011,  1488,   935,
      24,    13,    13,     5,   389,    25,  1374,  1413,  1394,   594,
     594,  1272,  1399,  1400,  1336,  1315,  1377,   616,   930,  1350,
     428,  1276,   936,  1435,  1434,  1414,    47,    48,    49,    50,
      51,   582,  1451,   844,   844,  1282,   930,  1310,  1377,  1374,
    1308,   619,   619,     5,     5,  1091,   913,  1488,  1488,     5,
     920,   921,  1488,  1488,   919,  1035,   810,   768,    72,    73,
      76,    77,    78,   175,   182,   216,   225,   254,   255,   299,
     341,   397,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,  1204,  1208,   133,   512,  1209,  1225,  1035,   158,
     174,   175,   182,   216,   225,   254,   299,   341,  1202,  1203,
    1215,  1209,  1322,  1331,   428,  1412,  1350,  1417,  1412,  1353,
       6,   389,     7,     9,    11,    12,    13,    14,    15,    16,
     250,   369,   426,   555,   601,   622,  1361,  1363,  1378,   456,
    1376,   389,     5,   619,     5,   389,  1260,   389,   389,   625,
     428,   625,    25,  1372,  1372,    25,  1372,  1372,    25,  1371,
      24,  1380,  1329,  1330,  1331,  1257,  1253,  1425,     8,   424,
     674,     5,   389,   842,   389,     5,   545,  1341,  1346,   936,
     625,   389,    25,   588,   625,   389,   389,   389,   389,     5,
     389,   389,   389,   707,   705,    20,   389,  1425,     5,   844,
     565,   272,   683,   684,   844,    20,   936,   389,   976,  1488,
    1488,     5,   741,   456,   619,     5,   742,  1488,   738,   545,
      20,   936,     5,   936,  1128,   387,   658,  1113,  1488,     5,
     389,   935,   837,     5,   705,  1091,   690,   672,   936,  1091,
     696,   389,   705,   705,  1488,  1488,  1011,  1066,    24,  1070,
    1091,   570,   891,  1102,   481,   843,  1020,   625,  1413,   389,
     393,  1377,  1440,   357,   474,   584,  1365,  1417,  1420,  1365,
    1365,  1365,  1365,   619,  1420,  1162,  1417,  1417,  1417,  1417,
     967,   966,   438,   952,   953,   619,   928,  1488,   928,  1488,
     678,    25,  1091,    25,  1091,   682,   389,   428,  1426,  1414,
    1396,  1400,  1400,  1392,     5,   389,   469,  1411,  1277,  1377,
     477,  1274,  1411,   625,  1404,    17,    18,    63,   425,   428,
     441,   481,   482,   494,   536,   575,   587,   599,   600,   608,
     611,   936,  1380,  1412,  1456,  1457,  1458,  1459,  1460,  1461,
    1467,  1456,  1456,  1456,  1377,  1453,  1455,  1452,  1453,  1454,
    1449,   552,  1284,     5,   389,   625,   936,   936,  1398,  1091,
     936,  1488,  1488,  1488,  1488,   623,   623,  1205,  1205,  1205,
      24,  1205,  1205,  1205,  1205,  1205,  1205,    24,    24,  1205,
    1208,  1091,  1118,  1119,   618,   444,  1171,  1488,    24,    24,
      25,    25,    25,    25,    25,    24,  1091,  1203,  1171,   389,
     389,  1351,  1352,   936,  1356,  1380,  1421,   428,  1412,  1356,
     428,  1412,     9,   247,   384,   386,  1417,    25,  1319,  1377,
      20,   936,  1377,   364,   451,   468,   511,   551,   580,   589,
    1388,    25,  1388,     5,  1369,  1369,     5,   389,   389,  1369,
     389,  1331,  1425,  1247,   266,  1243,  1415,   513,  1342,  1343,
    1344,  1374,  1347,   329,   512,   523,  1291,  1408,   364,   451,
     468,   511,   551,   580,   589,  1386,   877,   588,    23,    25,
     794,   837,   867,   466,   825,     5,   371,  1425,     5,   428,
     389,   549,  1001,   940,  1488,   675,    20,   936,   940,  1488,
    1478,   844,  1478,   238,  1013,   678,    24,  1230,  1110,   424,
     705,   695,   699,   389,  1488,   935,   844,   889,   424,  1388,
    1414,     5,  1387,     5,   389,  1417,     5,   389,  1417,  1417,
    1417,  1417,   936,   389,   844,  1488,   954,   955,    20,   936,
    1427,  1428,   552,  1410,  1395,  1393,  1396,  1377,  1413,   138,
    1316,     5,   389,  1275,  1435,  1410,  1459,  1459,  1458,   428,
     428,   428,   428,   428,   428,   428,   936,   428,     5,   389,
      17,    18,    19,    20,  1439,   389,     5,   389,     5,    13,
     148,   524,  1450,  1285,  1377,   460,  1311,  1312,  1375,   619,
     208,  1043,   806,   780,   537,   586,  1120,     5,  1118,    60,
     132,   197,   199,   214,   222,   226,   251,  1172,  1173,  1226,
    1043,  1216,   439,  1355,  1359,  1360,  1380,  1467,  1355,  1359,
    1356,  1417,     5,   424,  1376,   389,    25,  1373,   389,   389,
      25,   389,   428,  1344,     5,   936,  1379,   366,  1338,  1348,
     936,  1409,   618,  1365,   329,   428,    23,    25,   389,   928,
     678,   371,  1425,   844,   685,   567,  1126,    25,   678,   424,
    1001,   389,  1150,   389,   389,   428,   697,   342,   703,   389,
     692,  1065,  1488,   456,  1346,  1387,   625,  1387,   389,  1417,
     389,   389,   389,   389,   574,   935,     5,   389,  1113,  1346,
    1396,  1396,  1414,  1377,   428,  1346,   389,  1440,  1365,  1458,
    1462,  1365,  1365,  1365,  1365,   619,  1462,  1457,  1458,  1458,
    1458,  1458,  1453,    13,  1454,  1457,   930,  1350,  1113,     5,
     139,  1305,   936,  1119,  1174,  1175,  1091,  1177,  1091,  1176,
    1178,  1173,   237,   237,  1357,  1421,     5,   389,   389,  1355,
       7,    25,   625,   389,  1343,  1345,  1343,  1339,  1416,  1417,
     445,  1337,  1349,  1243,    25,  1292,  1293,  1294,  1377,  1406,
    1409,    25,   824,  1425,   390,   201,   257,   282,   291,   327,
     335,   429,   602,   682,   686,   687,   428,   619,   678,  1004,
    1153,  1154,  1155,  1231,   700,   389,  1110,   703,   703,  1488,
     890,  1102,   389,   625,  1388,   625,   968,   998,  1428,  1408,
    1346,   481,  1278,  1279,  1417,  1408,   389,  1458,     5,   389,
    1458,  1458,  1458,  1458,   936,   389,   428,  1312,  1488,  1488,
    1179,  1488,  1180,  1488,  1488,  1360,  1417,   424,  1388,     5,
     389,     5,  1350,     5,   537,   586,  1295,  1243,   389,   345,
     349,   827,   828,   829,  1004,   923,   923,   923,   923,   923,
     923,    24,     5,   389,   844,    20,   936,  1156,   280,  1155,
     703,   705,   703,   239,   424,  1388,  1388,  1488,   678,     5,
     389,   389,  1458,   389,   389,   389,   389,  1456,  1488,  1488,
    1343,  1416,  1293,   831,   830,   236,   829,   832,   687,     5,
    1488,   701,   965,  1279,   389,  1488,  1488,  1488,   844,   389,
     389,   702,   161,   342,   704,  1110
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
#line 922 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 925 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 929 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 935 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 940 "fgl.yacc"
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
#line 952 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 957 "fgl.yacc"
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
#line 980 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 981 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 982 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 983 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 984 "fgl.yacc"
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
#line 998 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 999 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 1000 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 1001 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 1002 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1007 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1008 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1019 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1022 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1025 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1025 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1032 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1033 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1039 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1040 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1041 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1042 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1043 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1044 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1045 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1046 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1047 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1049 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1051 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1052 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1053 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1054 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1062 "fgl.yacc"
    {
A4GL_debug("win_attributes_def");
start_state("attribute",1);
A4GL_debug("Started states");
form_attrib.attrib=0;}
    break;

  case 50:
#line 1066 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1070 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1071 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1075 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1081 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1083 "fgl.yacc"
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
#line 1094 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1096 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1098 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1100 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1104 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1106 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1167 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1171 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1175 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1178 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 66:
#line 1186 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1191 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1195 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 70:
#line 1198 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1204 "fgl.yacc"
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
#line 1213 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1217 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1222 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1226 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1234 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1238 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1242 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1244 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1250 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1255 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1258 "fgl.yacc"
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
#line 1274 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1281 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1285 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1289 "fgl.yacc"
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
#line 1311 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1311 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1315 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1316 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1317 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1322 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1325 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1331 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1334 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1346 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1352 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1355 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1370 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1380 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1386 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1395 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1408 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1411 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1413 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1419 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1421 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1426 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1431 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1437 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1441 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1456 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1459 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1462 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1465 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1468 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1471 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1493 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1502 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1512 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1526 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1530 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1533 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1541 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1547 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1562 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1566 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1571 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1581 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1584 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1588 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1590 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1593 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1595 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1598 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1600 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1603 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1606 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1616 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1617 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1625 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1626 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1643 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1646 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1649 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1652 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1655 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1658 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1667 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1675 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1680 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1693 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1697 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1712 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1713 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1721 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1721 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1731 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1731 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1740 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1741 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1742 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1745 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1750 "fgl.yacc"
    { }
    break;

  case 194:
#line 1750 "fgl.yacc"
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
#line 1767 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1771 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1785 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1794 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1798 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1814 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1816 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1817 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1824 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1824 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1825 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1826 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1829 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1831 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1841 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1856 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1856 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1862 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1863 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1870 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1871 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1872 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1873 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1876 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1877 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1878 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1879 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1883 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1888 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1893 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1897 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1900 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1904 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1905 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1906 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1907 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1908 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1909 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1910 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1911 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1914 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1915 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1916 "fgl.yacc"
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
#line 1948 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1952 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1954 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1956 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1958 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1963 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1967 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1967 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1971 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1972 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1973 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1974 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1975 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1976 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1978 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 1983 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 1983 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 1986 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 1988 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 1994 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 1996 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2002 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2010 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2010 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2013 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2014 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2015 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2016 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2017 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2018 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2020 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2041 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2050 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2052 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2054 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2056 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2057 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2058 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2059 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2060 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2065 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2072 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2077 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2079 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2081 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2082 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2083 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2084 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2085 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2086 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2087 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2090 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2092 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2098 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2106 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2114 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2118 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2126 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2127 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2128 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2129 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2148 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2160 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2164 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2167 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2170 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2171 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2172 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2173 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2174 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2180 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2187 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2192 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2197 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2201 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2204 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2212 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2214 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2219 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2231 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2234 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2237 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2240 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2243 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2246 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2259 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2262 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2277 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2279 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2281 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2283 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2285 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2287 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2288 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2295 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2297 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2301 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2303 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2305 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2307 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2309 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2311 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2313 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2319 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2333 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2336 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2353 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2359 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2363 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2368 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2378 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 402:
#line 2385 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2392 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2392 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2397 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null()");}
    break;

  case 407:
#line 2401 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2407 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2415 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2421 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2430 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2432 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2439 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2447 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2451 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2460 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2465 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2470 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2474 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2476 "fgl.yacc"
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

  case 421:
#line 2486 "fgl.yacc"
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

  case 422:
#line 2500 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2508 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2520 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2526 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2532 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2542 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2548 "fgl.yacc"
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

  case 431:
#line 2620 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2626 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2630 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 434:
#line 2638 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2638 "fgl.yacc"
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

  case 436:
#line 2654 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2658 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2664 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2667 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2675 "fgl.yacc"
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

  case 441:
#line 2686 "fgl.yacc"
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

  case 442:
#line 2696 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2702 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2712 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2717 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2724 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2727 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2730 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2735 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2742 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2747 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2752 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2757 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2768 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2776 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2784 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2789 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2793 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2798 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2802 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2806 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2812 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2815 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2819 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2823 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2827 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2831 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2835 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2842 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2852 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2857 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2863 "fgl.yacc"
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

  case 473:
#line 2873 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2878 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2881 "fgl.yacc"
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

  case 476:
#line 2895 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 477:
#line 2895 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2895 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 479:
#line 2898 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 480:
#line 2898 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2898 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 482:
#line 2901 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 483:
#line 2901 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2901 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 485:
#line 2904 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 486:
#line 2904 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2904 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 488:
#line 2907 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2913 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2919 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2925 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2935 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2936 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2944 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);

}
    break;

  case 497:
#line 2950 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2951 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 499:
#line 2956 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 500:
#line 2960 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_inp_io,sizeof(_inp_io),%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 501:
#line 2969 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_inp_io,sizeof(_inp_io),%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 504:
#line 2981 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 2986 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 2993 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 2997 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3000 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3003 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3009 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3012 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3015 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3032 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3035 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3041 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3042 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3043 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3048 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3049 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3050 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3051 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3053 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3054 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3055 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3057 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3058 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3064 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3069 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3081 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 533:
#line 3085 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 534:
#line 3086 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 535:
#line 3093 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 537:
#line 3110 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 538:
#line 3114 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 539:
#line 3119 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 540:
#line 3123 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 541:
#line 3139 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 542:
#line 3145 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 543:
#line 3153 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 550:
#line 3170 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 551:
#line 3172 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 552:
#line 3175 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 553:
#line 3177 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 558:
#line 3191 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 559:
#line 3193 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3196 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 561:
#line 3198 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3229 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 575:
#line 3231 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3234 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 577:
#line 3236 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3239 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 579:
#line 3241 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3244 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 581:
#line 3246 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3249 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 583:
#line 3251 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3266 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 585:
#line 3282 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 586:
#line 3283 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 587:
#line 3284 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 588:
#line 3285 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 589:
#line 3286 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 590:
#line 3287 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 594:
#line 3295 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 596:
#line 3301 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 597:
#line 3303 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 598:
#line 3304 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 599:
#line 3306 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 600:
#line 3308 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 601:
#line 3310 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 602:
#line 3312 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 603:
#line 3314 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3317 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 605:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 606:
#line 3326 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 607:
#line 3332 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 608:
#line 3337 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3342 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3347 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 611:
#line 3347 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 612:
#line 3350 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 613:
#line 3356 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[0].str) ;
			}
    break;

  case 614:
#line 3361 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 615:
#line 3365 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 618:
#line 3373 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 619:
#line 3375 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 620:
#line 3377 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 621:
#line 3379 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 622:
#line 3381 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 623:
#line 3383 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3386 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 626:
#line 3395 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 627:
#line 3457 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 628:
#line 3470 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 630:
#line 3477 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 631:
#line 3480 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 632:
#line 3486 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 633:
#line 3492 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 634:
#line 3496 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 635:
#line 3500 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3506 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 637:
#line 3510 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 638:
#line 3514 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3519 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 640:
#line 3524 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 659:
#line 3565 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 660:
#line 3570 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 662:
#line 3575 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 664:
#line 3578 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 665:
#line 3580 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 666:
#line 3583 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 667:
#line 3587 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 668:
#line 3590 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 669:
#line 3596 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 670:
#line 3607 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 671:
#line 3608 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 672:
#line 3611 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 674:
#line 3617 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 675:
#line 3621 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 676:
#line 3622 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 679:
#line 3636 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 680:
#line 3638 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 683:
#line 3647 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 684:
#line 3649 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 685:
#line 3653 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 686:
#line 3655 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 687:
#line 3658 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 688:
#line 3660 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3663 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 690:
#line 3666 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 691:
#line 3669 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 692:
#line 3671 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 693:
#line 3674 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 694:
#line 3676 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 695:
#line 3679 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 696:
#line 3681 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 697:
#line 3684 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 698:
#line 3686 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 699:
#line 3687 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 700:
#line 3689 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 701:
#line 3690 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 702:
#line 3692 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3693 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 704:
#line 3695 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3735 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 706:
#line 3736 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 707:
#line 3744 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 708:
#line 3745 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 709:
#line 3754 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 710:
#line 3759 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 711:
#line 3764 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 712:
#line 3765 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 714:
#line 3770 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 715:
#line 3773 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 716:
#line 3781 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 717:
#line 3786 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 718:
#line 3790 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 719:
#line 3792 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 720:
#line 3801 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 721:
#line 3806 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 722:
#line 3807 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 723:
#line 3808 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 724:
#line 3809 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 725:
#line 3812 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 737:
#line 3833 "fgl.yacc"
    {iskey=1;}
    break;

  case 738:
#line 3833 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 739:
#line 3835 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 740:
#line 3838 "fgl.yacc"
    {iskey=1;}
    break;

  case 741:
#line 3838 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 742:
#line 3840 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 743:
#line 3844 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 744:
#line 3844 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 745:
#line 3847 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 746:
#line 3848 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 748:
#line 3851 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 749:
#line 3856 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 750:
#line 3856 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 755:
#line 3863 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 756:
#line 3864 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 757:
#line 3865 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 758:
#line 3866 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 759:
#line 3867 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 760:
#line 3868 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 761:
#line 3869 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 762:
#line 3870 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 763:
#line 3871 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 764:
#line 3872 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 765:
#line 3873 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 766:
#line 3874 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 767:
#line 3875 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 768:
#line 3879 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 769:
#line 3897 "fgl.yacc"
    {chk4var=1;}
    break;

  case 770:
#line 3897 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 771:
#line 3900 "fgl.yacc"
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

  case 772:
#line 3923 "fgl.yacc"
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

  case 774:
#line 3941 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3947 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 3953 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 777:
#line 3959 "fgl.yacc"
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

  case 778:
#line 3970 "fgl.yacc"
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

  case 779:
#line 3993 "fgl.yacc"
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

  case 782:
#line 4009 "fgl.yacc"
    {
	}
    break;

  case 789:
#line 4032 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 793:
#line 4040 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 811:
#line 4066 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 812:
#line 4067 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 813:
#line 4075 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 814:
#line 4080 "fgl.yacc"
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

  case 815:
#line 4096 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 816:
#line 4102 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 818:
#line 4117 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 819:
#line 4130 "fgl.yacc"
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

  case 820:
#line 4140 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 821:
#line 4147 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 822:
#line 4154 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 823:
#line 4160 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 824:
#line 4160 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 825:
#line 4165 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 826:
#line 4170 "fgl.yacc"
    {
}
    break;

  case 832:
#line 4182 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 834:
#line 4190 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 835:
#line 4196 "fgl.yacc"
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

  case 836:
#line 4210 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 837:
#line 4214 "fgl.yacc"
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

  case 838:
#line 4227 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 840:
#line 4245 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	do_print_menu_1();
	}
    break;

  case 841:
#line 4252 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 842:
#line 4258 "fgl.yacc"
    {
   print_end_menu_1(get_blk_no());
   add_continue_blockcommand ("MENU");
print_end_menu_2(get_blk_no());
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 843:
#line 4269 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 844:
#line 4273 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 845:
#line 4280 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 846:
#line 4287 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 847:
#line 4293 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 848:
#line 4298 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 851:
#line 4305 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 852:
#line 4306 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 853:
#line 4308 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 854:
#line 4309 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 855:
#line 4312 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 856:
#line 4313 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 857:
#line 4314 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 858:
#line 4316 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,get_blk_no());
}
    break;

  case 859:
#line 4321 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,get_blk_no());
}
    break;

  case 860:
#line 4326 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,get_blk_no());
}
    break;

  case 861:
#line 4333 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 865:
#line 4340 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 866:
#line 4342 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 867:
#line 4344 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 868:
#line 4353 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 869:
#line 4359 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 870:
#line 4363 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 873:
#line 4375 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 874:
#line 4380 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 875:
#line 4385 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 876:
#line 4388 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 877:
#line 4397 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 878:
#line 4400 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 879:
#line 4404 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 880:
#line 4408 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 887:
#line 4425 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 889:
#line 4427 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 890:
#line 4427 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4430 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 892:
#line 4440 "fgl.yacc"
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

  case 894:
#line 4487 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4494 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 897:
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
      	dec_counter();

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 898:
#line 4540 "fgl.yacc"
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

  case 902:
#line 4588 "fgl.yacc"
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

  case 903:
#line 4602 "fgl.yacc"
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

  case 908:
#line 4626 "fgl.yacc"
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

  case 909:
#line 4686 "fgl.yacc"
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

  case 910:
#line 4742 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4747 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 912:
#line 4755 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 913:
#line 4760 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 914:
#line 4768 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 915:
#line 4774 "fgl.yacc"
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

  case 916:
#line 4802 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 917:
#line 4805 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 918:
#line 4807 "fgl.yacc"
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

  case 919:
#line 4848 "fgl.yacc"
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

  case 924:
#line 4901 "fgl.yacc"
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

  case 925:
#line 4953 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 927:
#line 4960 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 928:
#line 4966 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 929:
#line 4977 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 930:
#line 4984 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 932:
#line 4992 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 933:
#line 4995 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 934:
#line 4996 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 936:
#line 4998 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 4999 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 938:
#line 5002 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 939:
#line 5005 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 940:
#line 5011 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 941:
#line 5014 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 942:
#line 5018 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 943:
#line 5022 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 944:
#line 5029 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 945:
#line 5034 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 946:
#line 5041 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 947:
#line 5044 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 952:
#line 5057 "fgl.yacc"
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

  case 953:
#line 5076 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5083 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5090 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 956:
#line 5093 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 957:
#line 5107 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 962:
#line 5124 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 963:
#line 5129 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 964:
#line 5135 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 966:
#line 5142 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 967:
#line 5147 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 968:
#line 5150 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 969:
#line 5151 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 970:
#line 5154 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 971:
#line 5155 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 972:
#line 5158 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 973:
#line 5159 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 974:
#line 5164 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 975:
#line 5171 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 976:
#line 5174 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 977:
#line 5180 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 978:
#line 5182 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 979:
#line 5184 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 980:
#line 5186 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 981:
#line 5189 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 982:
#line 5189 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 983:
#line 5190 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 984:
#line 5195 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 985:
#line 5203 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 986:
#line 5204 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 987:
#line 5209 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 988:
#line 5211 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 989:
#line 5213 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 993:
#line 5230 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 994:
#line 5233 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 995:
#line 5236 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 996:
#line 5239 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 997:
#line 5243 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 998:
#line 5246 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 999:
#line 5249 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5253 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5257 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1002:
#line 5261 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1003:
#line 5264 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1004:
#line 5268 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1005:
#line 5271 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5272 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1007:
#line 5273 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1008:
#line 5276 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1009:
#line 5279 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1010:
#line 5282 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1011:
#line 5285 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1012:
#line 5288 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1013:
#line 5291 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1014:
#line 5294 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1015:
#line 5311 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1018:
#line 5321 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1019:
#line 5328 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1021:
#line 5349 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1022:
#line 5354 "fgl.yacc"
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

  case 1023:
#line 5367 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1024:
#line 5372 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1025:
#line 5373 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1026:
#line 5377 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1030:
#line 5383 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1031:
#line 5385 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1033:
#line 5400 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1034:
#line 5404 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1035:
#line 5410 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1036:
#line 5411 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1037:
#line 5414 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1038:
#line 5415 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1039:
#line 5418 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1041:
#line 5437 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1042:
#line 5442 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1043:
#line 5447 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1044:
#line 5452 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1050:
#line 5474 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1051:
#line 5481 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1052:
#line 5490 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1053:
#line 5496 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1054:
#line 5498 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1058:
#line 5509 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1059:
#line 5510 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1060:
#line 5512 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1061:
#line 5513 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1062:
#line 5515 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1063:
#line 5516 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1064:
#line 5518 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1065:
#line 5519 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1066:
#line 5521 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1067:
#line 5522 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1068:
#line 5523 "fgl.yacc"
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

  case 1069:
#line 5537 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1070:
#line 5539 "fgl.yacc"
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

  case 1071:
#line 5556 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1078:
#line 5568 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1079:
#line 5568 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1080:
#line 5574 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1081:
#line 5574 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1082:
#line 5577 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1083:
#line 5577 "fgl.yacc"
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

  case 1084:
#line 5587 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1085:
#line 5588 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1086:
#line 5589 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1087:
#line 5596 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1088:
#line 5608 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1094:
#line 5619 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1095:
#line 5624 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1096:
#line 5628 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1097:
#line 5633 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1098:
#line 5639 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1099:
#line 5640 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1100:
#line 5641 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1101:
#line 5645 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1102:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1103:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1104:
#line 5648 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1105:
#line 5652 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1106:
#line 5662 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1107:
#line 5664 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1108:
#line 5669 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1109:
#line 5672 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1110:
#line 5677 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1111:
#line 5684 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1112:
#line 5691 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1113:
#line 5698 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1114:
#line 5707 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1115:
#line 5714 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1116:
#line 5721 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1117:
#line 5728 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1118:
#line 5735 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1123:
#line 5748 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1124:
#line 5749 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1125:
#line 5750 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5751 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5752 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1128:
#line 5753 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1129:
#line 5754 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1130:
#line 5755 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1131:
#line 5756 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1132:
#line 5757 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1135:
#line 5763 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1136:
#line 5764 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1137:
#line 5765 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1138:
#line 5766 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1143:
#line 5775 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1144:
#line 5776 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1145:
#line 5777 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1146:
#line 5778 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5779 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5780 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1149:
#line 5781 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1150:
#line 5782 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1151:
#line 5784 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1152:
#line 5785 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1153:
#line 5786 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1154:
#line 5787 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1155:
#line 5789 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1156:
#line 5790 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1157:
#line 5791 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1158:
#line 5792 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1162:
#line 5797 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1163:
#line 5798 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1167:
#line 5805 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1168:
#line 5812 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1169:
#line 5819 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1170:
#line 5830 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1171:
#line 5839 "fgl.yacc"
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

  case 1172:
#line 5850 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1173:
#line 5854 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1174:
#line 5858 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1175:
#line 5864 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1176:
#line 5869 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1177:
#line 5877 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1178:
#line 5880 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1179:
#line 5889 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1180:
#line 5900 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1182:
#line 5907 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1183:
#line 5915 "fgl.yacc"
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

  case 1184:
#line 5925 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1185:
#line 5928 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1186:
#line 5932 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1187:
#line 5940 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1188:
#line 5943 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1189:
#line 5949 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1190:
#line 5953 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1191:
#line 5957 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1192:
#line 5961 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1193:
#line 5965 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1194:
#line 5971 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1195:
#line 5972 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1196:
#line 5973 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1197:
#line 5974 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1198:
#line 5979 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1199:
#line 5981 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1200:
#line 5984 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1201:
#line 5988 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1202:
#line 5991 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1203:
#line 5998 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1204:
#line 6003 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1205:
#line 6004 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1206:
#line 6005 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1207:
#line 6010 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1208:
#line 6011 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1209:
#line 6017 "fgl.yacc"
    {insql=1;}
    break;

  case 1210:
#line 6017 "fgl.yacc"
    {insql=0;}
    break;

  case 1211:
#line 6017 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1212:
#line 6022 "fgl.yacc"
    {insql=1;}
    break;

  case 1213:
#line 6022 "fgl.yacc"
    {insql=0;}
    break;

  case 1214:
#line 6022 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1215:
#line 6033 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1216:
#line 6034 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1217:
#line 6040 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1218:
#line 6042 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1220:
#line 6055 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1221:
#line 6059 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1222:
#line 6060 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1224:
#line 6065 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1225:
#line 6068 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1226:
#line 6074 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6077 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1228:
#line 6085 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1230:
#line 6092 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1231:
#line 6099 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1232:
#line 6102 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1233:
#line 6111 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1234:
#line 6114 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1235:
#line 6117 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1236:
#line 6120 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6123 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6126 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6129 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1240:
#line 6136 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1241:
#line 6139 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1242:
#line 6146 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6149 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1244:
#line 6155 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6158 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1246:
#line 6165 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1247:
#line 6168 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1249:
#line 6176 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1251:
#line 6185 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1252:
#line 6188 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1253:
#line 6194 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1254:
#line 6197 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1255:
#line 6203 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1256:
#line 6210 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1257:
#line 6211 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1258:
#line 6215 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1259:
#line 6221 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1260:
#line 6224 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1262:
#line 6232 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1263:
#line 6239 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1264:
#line 6242 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1268:
#line 6260 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1274:
#line 6266 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1275:
#line 6269 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1276:
#line 6272 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1277:
#line 6278 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1279:
#line 6284 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1281:
#line 6295 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1282:
#line 6309 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1283:
#line 6318 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1284:
#line 6318 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1285:
#line 6323 "fgl.yacc"
    {insql=1;}
    break;

  case 1286:
#line 6323 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1287:
#line 6328 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1288:
#line 6331 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1289:
#line 6333 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6340 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1292:
#line 6344 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1293:
#line 6348 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1294:
#line 6355 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6358 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1296:
#line 6365 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1297:
#line 6369 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1298:
#line 6373 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1299:
#line 6382 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1300:
#line 6386 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1301:
#line 6392 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1302:
#line 6396 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1303:
#line 6402 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1304:
#line 6409 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1305:
#line 6413 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1306:
#line 6418 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1307:
#line 6428 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1308:
#line 6431 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1309:
#line 6433 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1310:
#line 6435 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1311:
#line 6437 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1312:
#line 6439 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6441 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6443 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1315:
#line 6449 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1316:
#line 6459 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1317:
#line 6466 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1319:
#line 6472 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6481 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1326:
#line 6486 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1327:
#line 6491 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1328:
#line 6498 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1329:
#line 6499 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1330:
#line 6506 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1331:
#line 6517 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1332:
#line 6518 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1333:
#line 6521 "fgl.yacc"
    {insql=1;}
    break;

  case 1334:
#line 6521 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1335:
#line 6526 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1336:
#line 6531 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1338:
#line 6537 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1340:
#line 6541 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1341:
#line 6546 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1342:
#line 6551 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1343:
#line 6555 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1345:
#line 6561 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1346:
#line 6565 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1347:
#line 6573 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6576 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1349:
#line 6578 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1350:
#line 6583 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1353:
#line 6590 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1357:
#line 6597 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6600 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1359:
#line 6602 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6608 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6614 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6624 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1367:
#line 6629 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1368:
#line 6631 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6637 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1371:
#line 6640 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1373:
#line 6646 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1374:
#line 6654 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6659 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6669 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6675 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6681 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6683 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6689 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6694 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1386:
#line 6697 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1387:
#line 6700 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1388:
#line 6708 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6710 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1390:
#line 6723 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1391:
#line 6728 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6732 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1394:
#line 6734 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1395:
#line 6741 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1396:
#line 6744 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1397:
#line 6750 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1398:
#line 6754 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1399:
#line 6758 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1400:
#line 6762 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1401:
#line 6765 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1402:
#line 6773 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1403:
#line 6780 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1406:
#line 6789 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1407:
#line 6795 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1408:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6809 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6816 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6822 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6825 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6832 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6839 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1416:
#line 6846 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1417:
#line 6852 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1418:
#line 6853 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6854 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1421:
#line 6858 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6863 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1424:
#line 6870 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1425:
#line 6875 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1426:
#line 6876 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1427:
#line 6879 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1428:
#line 6882 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1429:
#line 6887 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1430:
#line 6888 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1431:
#line 6893 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1432:
#line 6896 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 6902 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 6905 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 6911 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1436:
#line 6914 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1437:
#line 6920 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 6923 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1439:
#line 6930 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1440:
#line 6931 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1441:
#line 6960 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1442:
#line 6962 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 6976 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1447:
#line 6979 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1448:
#line 6982 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1449:
#line 6985 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1451:
#line 6993 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1452:
#line 6996 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1454:
#line 7002 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1456:
#line 7008 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1457:
#line 7011 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1458:
#line 7014 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7017 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1460:
#line 7020 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7023 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1462:
#line 7026 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1464:
#line 7033 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1469:
#line 7040 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1470:
#line 7041 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1471:
#line 7046 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7049 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7053 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1474:
#line 7059 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1476:
#line 7061 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1477:
#line 7062 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1482:
#line 7082 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7087 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7088 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1486:
#line 7091 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1490:
#line 7096 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7099 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 7102 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7107 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7109 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7112 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1501:
#line 7113 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1502:
#line 7120 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 7125 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1510:
#line 7141 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1511:
#line 7142 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1512:
#line 7146 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1513:
#line 7147 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1515:
#line 7166 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1516:
#line 7167 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1517:
#line 7168 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1518:
#line 7172 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7175 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1520:
#line 7181 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1521:
#line 7186 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1522:
#line 7191 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1524:
#line 7202 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1529:
#line 7217 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1530:
#line 7220 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1531:
#line 7223 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1532:
#line 7225 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1533:
#line 7228 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1534:
#line 7230 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1535:
#line 7233 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1536:
#line 7233 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1537:
#line 7233 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1538:
#line 7233 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1539:
#line 7233 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1540:
#line 7233 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1541:
#line 7234 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1542:
#line 7237 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1543:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1544:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1545:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1546:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1547:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1548:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1549:
#line 7244 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1550:
#line 7247 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1565:
#line 7256 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1566:
#line 7257 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1567:
#line 7261 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1568:
#line 7269 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1569:
#line 7269 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1570:
#line 7274 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1571:
#line 7274 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1572:
#line 7280 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1573:
#line 7280 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1574:
#line 7285 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1575:
#line 7285 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1576:
#line 7292 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1577:
#line 7293 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1578:
#line 7294 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1582:
#line 7301 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7302 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1584:
#line 7307 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1585:
#line 7310 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1586:
#line 7316 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1587:
#line 7321 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1588:
#line 7330 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1589:
#line 7342 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1590:
#line 7343 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1591:
#line 7346 "fgl.yacc"
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

  case 1592:
#line 7361 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1593:
#line 7371 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1594:
#line 7374 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1595:
#line 7382 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1596:
#line 7391 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1597:
#line 7394 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1598:
#line 7398 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1599:
#line 7401 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1600:
#line 7402 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1602:
#line 7411 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1603:
#line 7412 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1604:
#line 7421 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1605:
#line 7430 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1606:
#line 7435 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1607:
#line 7436 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1608:
#line 7437 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1609:
#line 7438 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1610:
#line 7446 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7449 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1612:
#line 7455 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1613:
#line 7458 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1614:
#line 7468 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1615:
#line 7477 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1616:
#line 7480 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7483 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1618:
#line 7489 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7495 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7498 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1621:
#line 7501 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1622:
#line 7504 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1623:
#line 7511 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1624:
#line 7513 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1625:
#line 7515 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7517 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7519 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1628:
#line 7520 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1629:
#line 7521 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1630:
#line 7522 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1631:
#line 7523 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1632:
#line 7524 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1633:
#line 7525 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1634:
#line 7527 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1635:
#line 7529 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1636:
#line 7531 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7533 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7535 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7537 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7539 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7540 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7542 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1643:
#line 7546 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1644:
#line 7547 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1647:
#line 7557 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1648:
#line 7566 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1649:
#line 7570 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1650:
#line 7577 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1651:
#line 7577 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1653:
#line 7581 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1654:
#line 7586 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1655:
#line 7586 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1657:
#line 7590 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1658:
#line 7594 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1661:
#line 7603 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1662:
#line 7603 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1667:
#line 7622 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1668:
#line 7623 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1671:
#line 7631 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1672:
#line 7637 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1675:
#line 7656 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1676:
#line 7657 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1677:
#line 7658 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1678:
#line 7659 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1679:
#line 7660 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1680:
#line 7661 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1681:
#line 7665 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7666 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1683:
#line 7667 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1684:
#line 7671 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1685:
#line 7675 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1687:
#line 7684 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1689:
#line 7689 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1690:
#line 7690 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1691:
#line 7694 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1692:
#line 7700 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1693:
#line 7787 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1694:
#line 7791 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1695:
#line 7793 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1696:
#line 7800 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1697:
#line 7804 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1698:
#line 7810 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1699:
#line 7818 "fgl.yacc"
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

  case 1700:
#line 7828 "fgl.yacc"
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
#line 7838 "fgl.yacc"
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

  case 1702:
#line 7850 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1703:
#line 7853 "fgl.yacc"
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
#line 7872 "fgl.yacc"
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

  case 1705:
#line 7898 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1706:
#line 7901 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1708:
#line 7910 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1709:
#line 7915 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1710:
#line 7918 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1711:
#line 7926 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1712:
#line 7934 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1713:
#line 7947 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1714:
#line 7950 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1715:
#line 7958 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1716:
#line 7961 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1717:
#line 7964 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1718:
#line 7972 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1719:
#line 7976 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1720:
#line 7979 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1721:
#line 7982 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1722:
#line 7985 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1723:
#line 7989 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1724:
#line 7990 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1725:
#line 7991 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1726:
#line 7992 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1727:
#line 7993 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1728:
#line 7999 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1729:
#line 8000 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1730:
#line 8001 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 8002 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1732:
#line 8003 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1733:
#line 8004 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1734:
#line 8005 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1735:
#line 8006 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1736:
#line 8007 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1737:
#line 8008 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1738:
#line 8009 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1739:
#line 8010 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1740:
#line 8011 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1741:
#line 8012 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);printf("C14\n");}
    break;

  case 1742:
#line 8016 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1743:
#line 8022 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1744:
#line 8023 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1745:
#line 8036 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1746:
#line 8047 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1750:
#line 8053 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1751:
#line 8054 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1755:
#line 8066 "fgl.yacc"
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
		yyval.sql_string=strdup(A4GL_set_var_sql(z));

	} else { 
		// Its a column
		yyval.sql_string=strdup(get_column_transform(yyvsp[0].str));
	}
}
    break;

  case 1756:
#line 8092 "fgl.yacc"
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

  case 1757:
#line 8143 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 8145 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1759:
#line 8147 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1760:
#line 8148 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1761:
#line 8153 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1762:
#line 8158 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1763:
#line 8159 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1764:
#line 8163 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8165 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1766:
#line 8167 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1767:
#line 8170 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1768:
#line 8174 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1769:
#line 8179 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1770:
#line 8184 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1771:
#line 8188 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1773:
#line 8198 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1775:
#line 8213 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1776:
#line 8216 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1777:
#line 8220 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1780:
#line 8239 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1781:
#line 8240 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1782:
#line 8243 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1783:
#line 8244 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1784:
#line 8245 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1785:
#line 8246 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1786:
#line 8247 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1787:
#line 8248 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1788:
#line 8249 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1789:
#line 8254 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1790:
#line 8255 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1791:
#line 8259 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1792:
#line 8263 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1793:
#line 8267 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1794:
#line 8271 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1795:
#line 8276 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1796:
#line 8280 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1797:
#line 8285 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1799:
#line 8293 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1801:
#line 8299 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1802:
#line 8305 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1803:
#line 8309 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1808:
#line 8327 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1809:
#line 8334 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1810:
#line 8343 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1811:
#line 8343 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17007 "y.tab.c"

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


#line 8438 "fgl.yacc"

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



