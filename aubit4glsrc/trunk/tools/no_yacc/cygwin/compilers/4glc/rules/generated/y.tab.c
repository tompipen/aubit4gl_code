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
     NOT = 1584,
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
#define NOT 1584
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
#line 206 "fgl.yacc"
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
#line 1573 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1585 "y.tab.c"

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
#define YYLAST   8764

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  667
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  827
/* YYNRULES -- Number of rules. */
#define YYNRULES  1894
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
     324,   325,   326,   327,   328,    15,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,    16,   386,   387,   388,   389,   390,   391,
      23,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,    10,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,    13,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,    17,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,    12,   510,   511,   512,    11,    21,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
       8,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,    20,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,    14,
     582,   583,   584,   585,     7,   586,   587,   588,   589,     5,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,    19,    22,     9,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,    18,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,     6,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,     2,     3,     4,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33
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
    2548,  2550,  2552,  2554,  2556,  2558,  2560,  2562,  2566,  2567,
    2569,  2571,  2573,  2575,  2578,  2581,  2584,  2590,  2599,  2601,
    2603,  2605,  2610,  2615,  2617,  2619,  2621,  2623,  2626,  2629,
    2633,  2640,  2642,  2646,  2648,  2650,  2652,  2656,  2663,  2673,
    2675,  2677,  2679,  2681,  2684,  2685,  2687,  2689,  2693,  2695,
    2699,  2701,  2705,  2707,  2711,  2713,  2715,  2717,  2719,  2723,
    2725,  2729,  2731,  2735,  2737,  2739,  2741,  2745,  2748,  2749,
    2751,  2753,  2758,  2760,  2764,  2766,  2770,  2778,  2779,  2787,
    2788,  2795,  2799,  2801,  2805,  2807,  2810,  2816,  2817,  2825,
    2826,  2829,  2830,  2832,  2838,  2841,  2847,  2848,  2854,  2861,
    2866,  2867,  2869,  2871,  2876,  2877,  2880,  2881,  2887,  2892,
    2895,  2897,  2901,  2904,  2907,  2910,  2913,  2916,  2919,  2921,
    2924,  2927,  2930,  2933,  2936,  2939,  2942,  2945,  2948,  2950,
    2952,  2954,  2956,  2958,  2960,  2966,  2968,  2970,  2973,  2978,
    2980,  2981,  2992,  2998,  2999,  3001,  3002,  3005,  3007,  3010,
    3011,  3015,  3017,  3018,  3023,  3024,  3027,  3029,  3033,  3035,
    3037,  3041,  3046,  3051,  3054,  3056,  3058,  3060,  3061,  3063,
    3071,  3074,  3077,  3080,  3083,  3086,  3088,  3091,  3092,  3096,
    3097,  3101,  3102,  3106,  3107,  3111,  3112,  3116,  3117,  3122,
    3123,  3128,  3130,  3132,  3134,  3136,  3138,  3140,  3141,  3146,
    3147,  3149,  3150,  3155,  3157,  3160,  3163,  3166,  3167,  3169,
    3171,  3174,  3177,  3178,  3181,  3185,  3189,  3195,  3196,  3199,
    3204,  3206,  3208,  3210,  3212,  3214,  3215,  3217,  3219,  3223,
    3226,  3232,  3235,  3241,  3247,  3253,  3259,  3265,  3271,  3272,
    3275,  3277,  3280,  3283,  3286,  3289,  3292,  3295,  3297,  3300,
    3303,  3306,  3309,  3311,  3314,  3317,  3320,  3323,  3325,  3327,
    3329,  3330,  3333,  3336,  3339,  3342,  3345,  3348,  3351,  3354,
    3357,  3359,  3361,  3363,  3365,  3367,  3369,  3371,  3373,  3376,
    3379,  3382,  3385,  3388,  3390,  3392,  3394,  3395,  3399,  3402,
    3403,  3404,  3405,  3406,  3407,  3408,  3424,  3425,  3428,  3431,
    3432,  3434,  3435,  3436,  3437,  3438,  3439,  3440,  3456,  3459,
    3460,  3461,  3462,  3473,  3474,  3476,  3480,  3484,  3487,  3492,
    3496,  3500,  3504,  3506,  3508,  3510,  3512,  3514,  3516,  3517,
    3518,  3526,  3527,  3528,  3537,  3541,  3544,  3545,  3547,  3549,
    3553,  3556,  3559,  3561,  3563,  3567,  3569,  3571,  3574,  3576,
    3580,  3582,  3586,  3588,  3590,  3592,  3594,  3596,  3598,  3600,
    3603,  3608,  3610,  3614,  3616,  3620,  3623,  3628,  3630,  3634,
    3636,  3639,  3644,  3646,  3650,  3652,  3654,  3656,  3659,  3662,
    3667,  3670,  3675,  3677,  3681,  3683,  3685,  3687,  3690,  3692,
    3694,  3696,  3698,  3700,  3703,  3710,  3717,  3718,  3720,  3721,
    3723,  3726,  3728,  3729,  3735,  3736,  3742,  3744,  3745,  3749,
    3751,  3755,  3757,  3761,  3763,  3765,  3766,  3767,  3773,  3775,
    3778,  3780,  3781,  3782,  3786,  3787,  3788,  3792,  3794,  3796,
    3798,  3800,  3802,  3804,  3807,  3810,  3815,  3819,  3823,  3825,
    3829,  3832,  3834,  3836,  3837,  3839,  3841,  3843,  3845,  3846,
    3848,  3852,  3854,  3856,  3857,  3861,  3863,  3865,  3867,  3869,
    3871,  3873,  3875,  3877,  3879,  3881,  3883,  3885,  3893,  3894,
    3896,  3898,  3900,  3902,  3906,  3908,  3910,  3912,  3915,  3916,
    3920,  3922,  3926,  3928,  3932,  3934,  3936,  3943,  3944,  3948,
    3950,  3954,  3955,  3957,  3962,  3968,  3971,  3973,  3975,  3980,
    3982,  3986,  3991,  3996,  3998,  4002,  4004,  4006,  4008,  4011,
    4013,  4018,  4019,  4021,  4022,  4024,  4026,  4029,  4031,  4033,
    4035,  4037,  4042,  4046,  4048,  4050,  4052,  4055,  4057,  4059,
    4062,  4065,  4067,  4071,  4074,  4077,  4079,  4083,  4085,  4088,
    4093,  4095,  4098,  4100,  4104,  4109,  4110,  4112,  4113,  4115,
    4116,  4118,  4120,  4124,  4126,  4130,  4132,  4135,  4137,  4141,
    4144,  4147,  4148,  4151,  4153,  4155,  4161,  4165,  4171,  4175,
    4177,  4181,  4183,  4185,  4186,  4188,  4192,  4196,  4200,  4207,
    4212,  4217,  4223,  4225,  4227,  4229,  4231,  4233,  4235,  4237,
    4239,  4241,  4243,  4245,  4246,  4248,  4250,  4252,  4254,  4256,
    4258,  4260,  4265,  4271,  4273,  4279,  4285,  4287,  4289,  4291,
    4296,  4298,  4303,  4305,  4313,  4315,  4317,  4319,  4324,  4331,
    4332,  4335,  4340,  4342,  4344,  4346,  4348,  4350,  4352,  4354,
    4358,  4360,  4362,  4366,  4368,  4369,  4373,  4379,  4381,  4384,
    4387,  4392,  4396,  4398,  4400,  4402,  4404,  4406,  4408,  4411,
    4414,  4415,  4419,  4420,  4424,  4426,  4428,  4430,  4432,  4434,
    4436,  4438,  4443,  4445,  4447,  4449,  4451,  4453,  4455,  4457,
    4462,  4464,  4466,  4468,  4470,  4472,  4474,  4476,  4478,  4480,
    4482,  4484,  4486,  4488,  4490,  4492,  4494,  4498,  4499,  4508,
    4509,  4519,  4520,  4528,  4529,  4539,  4540,  4542,  4545,  4547,
    4551,  4553,  4557,  4563,  4565,  4567,  4569,  4571,  4574,  4575,
    4576,  4585,  4591,  4593,  4595,  4602,  4603,  4607,  4609,  4613,
    4618,  4620,  4621,  4624,  4629,  4636,  4637,  4639,  4641,  4643,
    4645,  4649,  4651,  4654,  4656,  4658,  4661,  4664,  4666,  4668,
    4670,  4673,  4678,  4682,  4685,  4689,  4693,  4697,  4699,  4701,
    4703,  4705,  4707,  4709,  4715,  4721,  4727,  4733,  4739,  4744,
    4749,  4753,  4758,  4760,  4764,  4766,  4772,  4780,  4786,  4787,
    4790,  4792,  4794,  4795,  4799,  4801,  4805,  4807,  4809,  4811,
    4812,  4816,  4818,  4820,  4822,  4824,  4829,  4836,  4838,  4840,
    4843,  4847,  4849,  4851,  4853,  4855,  4857,  4859,  4861,  4863,
    4869,  4875,  4880,  4881,  4886,  4888,  4891,  4893,  4895,  4897,
    4900,  4903,  4904,  4905,  4912,  4913,  4916,  4919,  4927,  4931,
    4935,  4938,  4941,  4944,  4946,  4950,  4952,  4956,  4958,  4962,
    4964,  4968,  4970,  4972,  4974,  4977,  4980,  4982,  4984,  4987,
    4992,  4994,  4996,  4998,  5000,  5002,  5004,  5008,  5011,  5015,
    5019,  5023,  5029,  5035,  5041,  5047,  5053,  5058,  5063,  5067,
    5072,  5074,  5076,  5080,  5082,  5085,  5087,  5089,  5091,  5095,
    5101,  5103,  5105,  5107,  5109,  5113,  5116,  5119,  5122,  5124,
    5127,  5130,  5132,  5135,  5138,  5141,  5143,  5147,  5150,  5152,
    5155,  5157,  5160,  5162,  5163,  5164,  5171,  5172,  5175,  5176,
    5178,  5180,  5183,  5186,  5188,  5190,  5195,  5199,  5201,  5205,
    5207,  5210,  5216,  5219,  5222,  5228,  5229,  5232,  5234,  5236,
    5239,  5246,  5253,  5255,  5256,  5258,  5261,  5263,  5266,  5267,
    5270,  5272,  5274,  5276,  5278,  5280,  5282,  5284,  5286,  5288,
    5290,  5292,  5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,
    5310,  5312,  5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,
    5330,  5332,  5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,
    5350,  5352,  5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,
    5370,  5372,  5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,
    5390,  5392,  5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,
    5410,  5412,  5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,
    5430,  5432,  5434,  5436,  5438
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1025,     0,    -1,   199,    -1,   196,    -1,   124,   672,   425,
     595,   673,    -1,   138,    -1,  1090,    -1,    26,    -1,   674,
      -1,   673,     5,   674,    -1,   936,    -1,   429,   675,   390,
      -1,   675,   676,   675,    -1,    26,    -1,   677,    26,    -1,
    1090,    -1,    18,    -1,    19,    -1,    21,    -1,    20,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   679,    -1,    -1,
     273,   429,   680,   681,   390,    -1,   568,   429,    26,     5,
      26,   390,    -1,   682,    -1,   681,     5,   682,    -1,   489,
      -1,   530,    -1,   536,    -1,   505,    -1,   408,    -1,   604,
      -1,   527,    -1,   479,    -1,   415,    -1,   490,    -1,   344,
      -1,   531,    -1,   454,    -1,   331,    -1,   593,    -1,    98,
      -1,  1002,    -1,    -1,   684,    -1,    -1,   273,   429,   685,
     686,   390,    -1,   687,    -1,   686,     5,   687,    -1,   682,
      -1,   430,    -1,   602,    25,    -1,   202,   923,    -1,   328,
     923,    -1,   283,   923,    -1,   336,   923,    -1,   292,   923,
      -1,   258,   923,    -1,   533,   689,    -1,   868,   343,  1090,
      -1,    -1,   288,   429,  1478,   390,   343,   690,  1109,    -1,
     104,   429,   936,     5,    25,     5,    25,   390,    -1,   405,
     429,   928,   390,   343,  1090,    -1,  1227,    -1,   191,   429,
     887,   390,   343,  1090,    -1,    -1,    -1,  1090,   589,   936,
     429,   691,   705,   390,   692,   703,    -1,    -1,    -1,    -1,
     936,   429,   693,   705,   694,   390,   695,   703,    -1,    -1,
      -1,   473,  1425,   622,  1425,   429,   696,   705,   697,   390,
     703,    -1,    -1,    -1,   936,   520,   936,   429,   698,   705,
     699,   390,   703,    -1,    -1,    -1,    -1,   364,   708,   589,
     709,   457,   672,   425,   429,   700,   705,   701,   390,   702,
     704,    -1,    -1,   343,  1109,    -1,    -1,   343,  1109,    -1,
     162,    -1,    -1,   706,    -1,   707,    -1,   706,     5,   707,
      -1,   837,    -1,    25,    -1,   936,    -1,   936,    -1,   936,
     619,   936,    -1,    -1,   534,   844,   711,   714,   718,   715,
      -1,    -1,   534,   712,   713,   716,   715,    -1,   720,    -1,
     713,   720,    -1,   722,    -1,   714,   722,    -1,   359,    -1,
      -1,    -1,   338,   717,  1488,    -1,    -1,    -1,   338,   719,
    1488,    -1,    -1,   578,   844,   721,  1488,    -1,    -1,   578,
     844,   723,  1488,    -1,   277,   933,    -1,   201,   931,    -1,
      83,   931,    -1,   168,    -1,   184,  1431,    -1,   493,   930,
      -1,    30,   726,    31,    -1,   727,    -1,   729,    -1,   728,
      -1,   727,   728,    -1,    29,    -1,   730,    -1,   729,   730,
      -1,    28,    -1,   392,    -1,    -1,    -1,   319,   733,   735,
     734,   736,    -1,   383,  1090,   624,   737,   976,  1001,   678,
      -1,  1090,   624,   737,   976,   546,  1478,  1001,   678,    -1,
      -1,   739,   190,    -1,   738,    -1,   737,     5,   738,    -1,
     936,    -1,   936,   619,   936,    -1,   936,   619,    21,    -1,
     740,    -1,   739,   740,    -1,    -1,   269,   746,   741,  1488,
      -1,    -1,   272,   747,   742,  1488,    -1,    -1,  1004,   743,
    1488,    -1,    -1,   166,   744,  1488,    -1,    -1,   163,   745,
    1488,    -1,   940,    -1,   746,     5,   940,    -1,   940,    -1,
     747,     5,   940,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   429,   837,   750,   390,
      -1,    -1,     5,   791,   625,   794,    -1,   155,    -1,   278,
      -1,    -1,   753,    -1,   754,    -1,   753,   754,    -1,    -1,
      -1,   436,   755,   757,   756,  1196,    -1,   804,    -1,  1468,
      -1,   760,    -1,   757,     5,   760,    -1,    -1,   759,   936,
      -1,   352,   758,   803,    25,    -1,   352,   758,   803,   936,
      -1,   352,   758,   803,   942,    -1,   352,   758,   803,    26,
      -1,   764,   780,    -1,    -1,   758,   352,   761,   762,    -1,
      26,    -1,    25,    -1,   942,    -1,    19,    26,    -1,   758,
      -1,   763,    -1,   764,     5,   763,    -1,    -1,   535,    -1,
      -1,   486,   457,   772,   425,   767,   623,   780,    -1,    -1,
     317,   765,   769,    26,   770,   301,   457,   771,   425,   768,
     623,   780,    -1,   429,    -1,   456,    -1,   390,    -1,   424,
      -1,    26,    -1,   773,     5,   773,     5,   773,    -1,   773,
       5,   773,    -1,   773,    -1,    26,    -1,    -1,   462,   775,
     757,   282,    -1,    -1,   259,   776,   758,   619,    21,    -1,
      -1,   333,   777,   758,   257,   429,   778,   390,    -1,   779,
      -1,   778,     5,   779,    -1,   758,    -1,   782,    -1,    -1,
      58,    -1,    -1,    -1,   783,   785,   784,   781,    -1,   766,
      -1,   774,    -1,   535,    -1,   535,   429,    26,   390,    -1,
     422,   429,    26,   390,    -1,   422,   429,    26,     5,    26,
     390,    -1,   406,    -1,   616,   758,    -1,   378,    -1,   508,
      -1,    89,    -1,   396,    -1,   396,   429,    26,   390,    -1,
     396,   429,    26,     5,    26,   390,    -1,   511,    -1,   511,
     429,    26,   390,    -1,   511,   429,    26,     5,    26,   390,
      -1,   501,    -1,   298,    -1,   537,    -1,   532,    -1,    80,
      -1,    81,    -1,   574,    -1,   356,   789,    -1,   368,   790,
      -1,   786,    -1,    32,    -1,   556,   787,   619,   788,    -1,
     758,    -1,   758,    -1,    -1,   791,   625,   794,    -1,   799,
     625,   802,    -1,    -1,   792,   793,    -1,   581,    -1,   512,
      -1,   590,    -1,   552,    -1,   452,    -1,   469,    -1,   365,
     796,    -1,    -1,   795,   793,    -1,    -1,   429,   798,   390,
      -1,    -1,   429,    26,   390,    -1,    26,    -1,    -1,   800,
     801,   797,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   452,    -1,   469,    -1,   365,   796,    -1,   801,    -1,
      -1,    14,    -1,    -1,   235,   936,   805,   616,   806,    -1,
     808,    -1,   811,    -1,   535,    -1,   535,   429,    26,   390,
      -1,   422,   429,    26,   390,    -1,   422,   429,    26,     5,
      26,   390,    -1,   406,    -1,   378,    -1,   508,    -1,   396,
      -1,   396,   429,    26,   390,    -1,   396,   429,    26,     5,
      26,   390,    -1,   511,    -1,   511,   429,    26,   390,    -1,
     511,   429,    26,     5,    26,   390,    -1,   501,    -1,   298,
      -1,   537,    -1,   532,    -1,   574,    -1,   356,   789,    -1,
     368,   790,    -1,   807,    -1,   556,   787,   619,   788,    -1,
      -1,   486,   457,   772,   425,   809,   623,   806,    -1,    -1,
     317,   765,   769,    26,   770,   301,   457,   771,   425,   810,
     623,   806,    -1,    -1,   462,   812,   814,   282,    -1,    -1,
     259,   813,   936,   619,    21,    -1,   815,    -1,   814,     5,
     815,    -1,   816,   806,    -1,   817,    -1,   816,     5,   817,
      -1,   936,    -1,    -1,   617,   927,    -1,    70,   936,    -1,
      68,    -1,   625,  1478,    -1,   625,   508,   936,   658,  1478,
      -1,   625,   508,   936,   388,    -1,    72,   936,    -1,   156,
     862,  1109,   826,    -1,   399,   862,   842,   818,   826,    -1,
     208,   933,   826,    -1,    -1,    -1,   187,   823,  1116,   625,
     936,   619,    21,   825,   678,   824,   827,    -1,    -1,   467,
     928,    -1,   678,    -1,    -1,   828,   237,    -1,   829,    -1,
     828,   829,    -1,    -1,   350,   830,  1488,    -1,    -1,   346,
     831,  1488,    -1,    -1,  1004,   832,  1488,    -1,   497,   862,
     843,   678,    -1,   497,   862,   843,   678,    65,    -1,   285,
      -1,   284,    -1,   211,    -1,   363,    -1,   173,    -1,   210,
      -1,   327,    -1,   326,    -1,   242,    -1,   170,    -1,   169,
      -1,   144,    -1,   203,    -1,   127,    -1,   143,    -1,   186,
      -1,   153,    -1,   212,    -1,   212,   844,    -1,   847,    -1,
     846,    -1,   851,    -1,   879,    -1,   837,   838,    -1,   880,
      -1,   882,    -1,   848,    -1,    19,   837,    -1,    18,   837,
      -1,   853,    -1,   861,    -1,   855,    -1,   474,    -1,   748,
      -1,   856,    -1,   857,    -1,   858,    -1,   859,    -1,   860,
      -1,    35,   837,    -1,   862,    -1,   862,   841,    -1,   844,
      -1,   482,    -1,   840,    -1,   841,     5,   840,    -1,   844,
      -1,   842,     5,   844,    -1,   844,    -1,   843,     5,   844,
      -1,   837,    -1,    18,    -1,    19,    -1,     9,   837,    -1,
     483,    -1,   426,    -1,   429,   837,   390,    -1,   441,   429,
    1405,   390,    -1,   293,   429,  1405,   390,    -1,   845,   942,
      -1,   845,    26,    -1,    25,    -1,   942,    -1,    26,    -1,
     850,    -1,  1090,    -1,  1090,   419,  1090,    -1,   849,    -1,
     432,   837,    -1,   391,   837,    -1,  1199,    -1,    -1,   506,
     852,  1199,    -1,     7,   837,    -1,     6,   837,    -1,   837,
      -1,   854,     5,   837,    -1,   622,   429,  1405,   390,    -1,
     427,   429,  1405,   390,    -1,   622,   429,   862,   854,   390,
      -1,   427,   429,   862,   854,   390,    -1,   385,    -1,   248,
      -1,    10,   837,    -1,   251,   837,    -1,    10,   837,   440,
      25,    -1,   251,   837,   440,    25,    -1,   556,   837,    -1,
     370,   837,    -1,   556,   837,   440,    25,    -1,   370,   837,
     440,    25,    -1,   389,    -1,     8,   837,    -1,    18,   837,
      -1,    19,   837,    -1,    21,   837,    -1,    20,   837,    -1,
      22,   837,    -1,    11,   837,    -1,    14,   837,    -1,   455,
     837,    -1,    12,   837,    -1,    13,   837,    -1,    17,   837,
      -1,    16,   837,    -1,    15,   837,    -1,    -1,    -1,    -1,
     936,   429,   864,   705,   865,   390,    -1,    -1,    -1,   936,
     520,   936,   429,   866,   705,   867,   390,    -1,    -1,    -1,
     537,   429,   869,   837,   870,   390,    -1,    -1,    -1,   512,
     429,   871,   837,   872,   390,    -1,    -1,    -1,   590,   429,
     873,   837,   874,   390,    -1,    -1,    -1,   581,   429,   875,
     837,   876,   390,    -1,   368,   429,   883,   390,   878,    -1,
     356,   429,    25,   390,   877,    -1,   356,   429,    26,   390,
     877,    -1,   356,   429,    26,   589,    26,   390,   877,    -1,
      -1,  1385,   625,  1386,    -1,   790,    -1,   868,    -1,   288,
     429,  1478,   390,    -1,    99,   429,   928,   390,    -1,    71,
     429,   928,   390,    -1,   405,   429,  1478,   390,    -1,   191,
     429,  1478,   390,    -1,    59,   429,  1478,   390,    -1,   881,
      -1,   863,    -1,  1381,    -1,   537,    -1,   421,   429,   837,
     390,    -1,   321,   429,   837,   390,    -1,   487,   837,    -1,
     442,   749,    -1,   837,   108,    -1,   837,   109,    -1,   837,
     110,    -1,    25,    -1,   884,    -1,    19,   884,    -1,   886,
      -1,   885,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     589,    26,    -1,    26,    26,   589,    26,   589,    26,    -1,
      26,    26,   589,    26,   589,    24,    -1,    26,   589,    26,
      -1,    26,   589,    26,   589,    26,    -1,    26,   589,    26,
     589,    24,    -1,    26,   589,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   928,    -1,   887,     5,   928,
      -1,    -1,    -1,   595,  1090,    14,   844,   625,   844,   891,
     889,  1488,   890,   240,    -1,    -1,   571,   844,    -1,    -1,
      -1,    -1,   402,   893,   930,   894,  1286,   895,  1488,   239,
      -1,    -1,    -1,   637,   936,   897,   752,   898,  1035,   900,
     899,   905,   638,    -1,    -1,   910,    -1,    -1,   901,    -1,
     902,    -1,   901,   902,    -1,    -1,   639,   903,  1488,    -1,
      -1,   640,   904,  1488,    -1,    -1,   906,    -1,   907,    -1,
     906,   907,    -1,    -1,   641,   908,  1488,    -1,    -1,   642,
     909,  1488,    -1,   911,   915,   323,    -1,    91,    -1,    91,
     912,   546,   913,    -1,    91,   383,   914,    -1,  1090,    -1,
     912,     5,  1090,    -1,   936,    -1,   913,     5,   936,    -1,
    1090,    -1,   914,     5,  1090,    -1,   916,    -1,   915,   916,
      -1,    -1,   643,   917,  1488,    -1,    -1,   644,   918,  1488,
      -1,    -1,   663,   913,   919,  1488,    -1,    -1,   480,   913,
     920,  1488,    -1,    -1,   624,   913,   921,  1488,    -1,   545,
     929,    -1,   554,    19,    26,    -1,   554,    -1,   500,    18,
      26,    -1,   500,    -1,    26,    -1,  1090,    -1,    25,    -1,
     941,    -1,   844,    -1,   925,     5,   925,    -1,   926,    -1,
     936,    -1,   666,   429,   936,   390,    -1,   936,   619,   666,
     429,   936,   390,    -1,   936,   457,   675,   425,    -1,   936,
     619,    21,    -1,   936,   457,   675,   425,   619,    21,    -1,
     936,   619,   936,    -1,   936,   457,   675,   425,   619,   936,
      -1,   937,    -1,   937,    -1,   937,    -1,   937,    -1,   937,
      -1,   937,    -1,    -1,   550,    26,    -1,  1487,    -1,   938,
      -1,  1487,    -1,   348,   429,   939,   390,    -1,  1093,    -1,
      25,    -1,   936,    -1,   936,   457,   675,   425,    -1,   936,
     619,    21,    -1,   936,   457,   675,   425,   619,    21,    -1,
     936,   619,   936,    -1,   936,   457,   675,   425,   619,   936,
      -1,  1090,    -1,    24,    -1,   619,    26,    -1,   547,  1470,
      -1,   651,   945,    -1,   946,    -1,   945,     5,   946,    -1,
     936,    -1,   662,   945,    -1,   653,   945,    -1,   654,  1478,
      -1,   652,   933,   658,  1478,    -1,   656,   945,    -1,   657,
    1478,    -1,   655,   933,   658,  1478,    -1,    -1,   660,   951,
     842,   956,   958,   960,   952,   954,    -1,    -1,   953,    -1,
     648,    -1,   649,    -1,    -1,   955,    -1,   343,  1090,    -1,
      -1,   957,    -1,   388,   842,    -1,    -1,   959,    -1,   659,
      26,    -1,    -1,   961,    -1,   650,    26,   962,    -1,    -1,
     398,    26,    -1,    -1,   621,   844,   575,   964,  1488,   965,
     439,    -1,    -1,    -1,   542,   966,  1488,    -1,    -1,    -1,
      62,   967,   844,   575,   968,  1488,   965,    -1,   106,   936,
     429,    26,   390,    -1,    55,   936,    -1,    75,   936,    -1,
      -1,   289,  1121,   972,   625,   482,    -1,   289,  1121,   556,
     973,    -1,   974,    -1,   973,     5,   974,    -1,   787,   619,
    1377,    -1,   787,   619,    21,    -1,    -1,   977,   323,    -1,
      -1,   150,    -1,   978,    -1,   977,   978,    -1,    -1,   269,
     990,   979,  1488,    -1,    -1,   272,   991,   980,  1488,    -1,
      -1,   350,   981,  1488,    -1,    -1,   346,   982,  1488,    -1,
      -1,  1004,   983,  1488,    -1,    -1,   304,   984,  1488,    -1,
      -1,   274,   985,  1488,    -1,    -1,    36,   986,  1488,    -1,
      -1,    34,   987,  1488,    -1,    -1,    38,   988,  1488,    -1,
      -1,    37,   989,  1488,    -1,   928,    -1,   990,     5,   928,
      -1,   928,    -1,   991,     5,   928,    -1,   313,   994,    -1,
     314,   936,   658,   994,    -1,   561,    -1,   373,    -1,   928,
      -1,    -1,   664,   997,   996,   975,    -1,   383,  1109,   976,
     935,   678,    -1,  1109,   976,   546,  1478,   935,   678,    -1,
      -1,   486,  1116,   976,   546,   936,   619,    21,   935,   998,
     678,    -1,   468,  1478,  1000,    -1,   626,    -1,   539,    -1,
      76,    26,    -1,    82,    26,    -1,    -1,   550,    26,    -1,
    1003,    -1,    43,    25,    -1,   495,    14,    26,    -1,   495,
      14,  1090,    -1,    44,    14,    26,    -1,    44,    14,  1090,
      -1,    40,    -1,    42,    -1,    39,    -1,    41,    -1,    -1,
     428,  1005,  1011,    -1,   294,    -1,    -1,   596,  1007,  1011,
      -1,   302,  1013,    -1,    -1,   596,  1010,  1011,    -1,  1013,
      -1,   429,  1012,   390,    -1,  1013,    -1,  1012,     5,  1013,
      -1,    -1,  1014,  1015,    -1,   594,    -1,   311,    -1,   329,
      -1,   303,    -1,   484,    -1,   440,    -1,   626,    -1,   550,
      -1,   539,    -1,   464,    -1,   437,    -1,   540,    -1,   555,
      -1,   519,    -1,   309,    -1,   310,    -1,    25,    -1,   509,
      -1,    -1,    -1,   598,  1018,  1114,  1019,    14,   862,  1020,
      -1,   482,    -1,   843,    -1,   218,  1090,    -1,   207,  1090,
      -1,   221,  1090,    -1,   449,  1090,   332,    -1,   449,  1090,
     384,   924,    -1,    -1,  1027,  1026,  1030,    -1,    -1,  1028,
      -1,  1029,    -1,  1028,  1029,    -1,   970,    -1,  1034,    -1,
    1050,    -1,  1036,    -1,    -1,  1031,    -1,  1033,    -1,  1031,
    1033,    -1,    66,   936,    -1,  1038,    -1,  1044,    -1,  1056,
      -1,  1209,    -1,  1219,    -1,  1077,    -1,  1468,    -1,   896,
      -1,   725,    -1,   969,    -1,   731,    -1,   725,    -1,  1468,
      -1,    -1,   725,    -1,  1468,    -1,   753,    -1,   366,    -1,
      60,    -1,    -1,    -1,    -1,    -1,  1037,  1039,   936,   429,
    1040,  1107,   390,  1041,   752,  1042,  1035,  1488,  1043,    -1,
     209,    -1,    -1,    -1,   557,  1045,   752,  1046,  1488,   360,
      -1,   464,   839,    -1,   862,    -1,   862,   842,    -1,   355,
    1389,    -1,  1051,    -1,  1052,    -1,  1051,  1052,    -1,  1053,
      -1,  1034,    -1,  1049,    -1,    -1,   404,  1054,  1055,    -1,
     752,   241,    -1,   924,    -1,    -1,    -1,    -1,   113,   936,
     112,   936,   429,  1057,  1107,   390,  1058,   752,  1059,  1035,
    1488,  1043,    -1,    -1,   558,  1061,  1076,  1067,  1062,    -1,
     361,    -1,    -1,   233,  1064,  1488,    -1,    -1,    23,  1068,
    1069,  1070,   935,  1065,  1488,    -1,    -1,    23,  1068,   935,
    1066,  1488,    -1,  1063,    -1,  1067,  1063,    -1,    -1,  1006,
      -1,    25,    -1,  1090,    -1,    -1,  1090,    -1,    25,    -1,
     250,  1074,    -1,   262,  1075,    -1,   245,  1075,    -1,   585,
      -1,    25,    -1,  1090,    -1,  1074,    -1,  1075,     5,  1074,
      -1,  1090,    -1,    25,    -1,    -1,    -1,   645,   936,  1078,
     752,  1079,  1080,   646,    -1,  1081,    -1,  1080,  1081,    -1,
      -1,   647,  1082,  1488,    -1,    -1,   624,   936,  1083,  1488,
      -1,  1087,  1085,    -1,    -1,   679,  1088,    -1,  1089,    -1,
    1086,    -1,   957,    -1,   959,    -1,   961,    -1,   953,    -1,
     955,    -1,   369,   862,   842,    -1,    -1,    65,    -1,    65,
      -1,  1091,    -1,  1093,    -1,   189,  1093,    -1,  1093,   619,
      -1,  1092,  1097,    -1,  1092,   936,   457,  1101,   425,    -1,
    1092,   936,   457,  1101,   425,   457,  1101,   425,    -1,  1098,
      -1,   936,    -1,  1094,    -1,   936,   456,  1096,   424,    -1,
     936,   456,  1096,   424,    -1,  1090,    -1,    25,    -1,    21,
      -1,   936,    -1,   936,  1100,    -1,   936,  1100,    -1,   457,
    1101,   425,    -1,   457,  1101,   425,   457,  1101,   425,    -1,
    1102,    -1,  1101,     5,  1102,    -1,   675,    -1,  1104,    -1,
    1106,    -1,  1104,   619,  1105,    -1,  1104,   619,   936,   457,
    1101,   425,    -1,  1104,   619,   936,   457,  1101,   425,   457,
    1101,   425,    -1,   936,    -1,  1095,    -1,    21,    -1,   936,
      -1,   936,  1100,    -1,    -1,  1108,    -1,  1110,    -1,  1108,
       5,  1110,    -1,  1111,    -1,  1109,     5,  1111,    -1,   936,
      -1,   936,   619,   936,    -1,  1090,    -1,  1090,   419,  1090,
      -1,    25,    -1,   942,    -1,    26,    -1,  1113,    -1,  1112,
       5,  1113,    -1,  1090,    -1,  1090,   419,  1090,    -1,  1115,
      -1,  1114,     5,  1115,    -1,  1103,    -1,  1090,    -1,  1118,
      -1,  1117,     5,  1118,    -1,  1090,  1119,    -1,    -1,   587,
      -1,   538,    -1,   936,   457,  1101,   425,    -1,  1122,    -1,
    1121,     5,  1122,    -1,  1090,    -1,  1090,   419,  1090,    -1,
     253,   932,   617,   926,   579,  1480,   683,    -1,    -1,   617,
     429,   844,     5,   844,   390,  1125,    -1,    -1,   568,   429,
     844,     5,   844,   390,    -1,   254,   936,  1124,    -1,   936,
      -1,   337,   934,  1129,    -1,  1130,    -1,   546,   844,    -1,
    1131,  1132,  1137,     8,  1127,    -1,    -1,   617,  1133,   429,
     844,     5,   844,   390,    -1,    -1,   556,   937,    -1,    -1,
     349,    -1,   216,  1431,   265,  1463,  1136,    -1,   563,   929,
      -1,   563,   929,     8,   862,   842,    -1,    -1,   616,   576,
    1425,   372,  1425,    -1,   616,   576,  1425,     5,   372,  1425,
      -1,   616,  1425,     5,  1425,    -1,    -1,   648,    -1,   649,
      -1,    90,  1463,  1139,  1140,    -1,    -1,   616,  1463,    -1,
      -1,   616,   576,  1425,     8,  1425,    -1,   576,  1425,     8,
    1425,    -1,   410,  1142,    -1,  1143,    -1,  1142,     5,  1143,
      -1,   202,   923,    -1,   283,   923,    -1,   328,   923,    -1,
     336,   923,    -1,   292,   923,    -1,   258,   923,    -1,  1008,
      -1,   437,  1009,    -1,   448,  1009,    -1,   561,  1009,    -1,
     373,  1009,    -1,   550,  1009,    -1,   548,   924,    -1,   549,
     924,    -1,   399,   679,    -1,   664,   679,    -1,   290,    -1,
     194,    -1,   151,    -1,   128,    -1,   146,    -1,   137,    -1,
    1430,   412,  1147,   546,  1145,    -1,  1090,    -1,    25,    -1,
     401,  1147,    -1,   401,  1147,     8,  1109,    -1,   937,    -1,
      -1,   460,  1156,   678,   595,  1151,  1090,   935,   678,  1149,
    1152,    -1,   460,  1156,   678,   343,  1090,    -1,    -1,   535,
      -1,    -1,  1153,   281,    -1,  1154,    -1,  1153,  1154,    -1,
      -1,  1004,  1155,  1488,    -1,   843,    -1,    -1,   603,   929,
    1158,  1159,    -1,    -1,   546,  1160,    -1,  1161,    -1,  1160,
       5,  1161,    -1,  1417,    -1,   482,    -1,   219,  1164,    88,
      -1,   219,  1164,   625,  1163,    -1,   219,  1164,    87,  1163,
      -1,   219,  1164,    -1,    25,    -1,   941,    -1,   936,    -1,
      -1,   478,    -1,   145,  1164,  1165,   429,   862,  1048,   390,
      -1,   192,  1164,    -1,    67,  1164,    -1,  1200,  1208,    -1,
     445,    61,    -1,   445,  1171,    -1,  1172,    -1,  1171,  1172,
      -1,    -1,   133,  1173,  1488,    -1,    -1,   198,  1174,  1488,
      -1,    -1,   227,  1175,  1488,    -1,    -1,   215,  1176,  1488,
      -1,    -1,   252,  1177,  1488,    -1,    -1,   200,  1090,  1178,
    1488,    -1,    -1,   223,  1090,  1179,  1488,    -1,  1190,    -1,
    1192,    -1,  1191,    -1,  1181,    -1,  1217,    -1,  1184,    -1,
      -1,   560,   844,  1182,   481,    -1,    -1,   481,    -1,    -1,
     569,   844,  1185,  1183,    -1,   158,    -1,   628,  1204,    -1,
     161,  1204,    -1,   160,  1204,    -1,    -1,  1187,    -1,  1188,
      -1,  1187,  1188,    -1,  1197,  1189,    -1,    -1,   617,  1204,
      -1,   518,  1186,  1196,    -1,   517,  1425,  1196,    -1,   516,
    1195,  1194,  1193,  1196,    -1,    -1,   152,   837,    -1,   152,
     837,     5,   837,    -1,   612,    -1,   613,    -1,   614,    -1,
     615,    -1,  1090,    -1,    -1,   521,    -1,  1198,    -1,  1197,
       5,  1198,    -1,   844,  1231,    -1,   608,   429,   837,   390,
    1216,    -1,    64,  1216,    -1,   495,   429,    21,   390,  1216,
      -1,   411,   429,    21,   390,  1216,    -1,   386,   429,   837,
     390,  1216,    -1,   588,   429,   837,   390,  1216,    -1,   601,
     429,   837,   390,  1216,    -1,   600,   429,   837,   390,  1216,
      -1,    -1,   459,  1201,    -1,  1202,    -1,  1201,  1202,    -1,
     226,    26,    -1,   217,    26,    -1,   300,    26,    -1,   183,
      26,    -1,   255,    26,    -1,   175,    -1,   342,    25,    -1,
     342,  1090,    -1,   176,    25,    -1,   159,    25,    -1,  1207,
      -1,  1203,  1207,    -1,  1205,   108,    -1,  1205,   110,    -1,
    1205,   109,    -1,  1205,    -1,   942,    -1,    26,    -1,    -1,
     459,  1203,    -1,   226,  1204,    -1,   217,  1204,    -1,   300,
    1204,    -1,   183,  1204,    -1,   255,  1204,    -1,   256,  1204,
      -1,   627,    25,    -1,   628,  1204,    -1,   632,    -1,   629,
      -1,   630,    -1,   631,    -1,   636,    -1,   633,    -1,   634,
      -1,   635,    -1,    77,  1204,    -1,    78,  1204,    -1,    79,
    1204,    -1,   342,    25,    -1,   176,    25,    -1,   398,    -1,
      73,    -1,    74,    -1,    -1,   513,   618,  1117,    -1,   134,
    1117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,  1210,
     936,   429,  1211,  1107,   390,  1212,   752,  1213,  1169,  1214,
    1170,  1215,   238,    -1,    -1,   525,   837,    -1,   515,  1218,
      -1,    -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,  1220,   936,   429,  1221,  1107,   390,  1222,   752,  1223,
    1226,  1224,  1170,  1225,   238,    -1,  1206,  1208,    -1,    -1,
      -1,    -1,   154,   429,    25,     5,  1228,   705,  1229,   390,
    1230,   703,    -1,    -1,   382,    -1,   382,   217,    26,    -1,
     382,   217,  1090,    -1,   606,   844,    -1,   606,   844,   343,
    1090,    -1,   606,   844,   162,    -1,   606,   844,   577,    -1,
     606,   844,   544,    -1,  1234,    -1,   172,    -1,   322,    -1,
     280,    -1,  1241,    -1,  1236,    -1,    -1,    -1,   205,  1237,
    1374,   429,  1238,  1245,   390,    -1,    -1,    -1,   131,  1239,
    1374,   429,  1240,  1245,   390,  1242,    -1,   103,  1243,   390,
      -1,    54,   937,    -1,    -1,   267,    -1,  1244,    -1,  1243,
       5,  1244,    -1,   936,   587,    -1,   936,   538,    -1,   936,
      -1,  1246,    -1,  1245,     5,  1246,    -1,  1327,    -1,  1325,
      -1,   120,   936,    -1,   178,    -1,    45,   936,  1249,    -1,
    1250,    -1,  1249,     5,  1250,    -1,  1251,    -1,  1254,    -1,
    1257,    -1,  1262,    -1,  1263,    -1,  1261,    -1,  1260,    -1,
     584,  1252,    -1,   584,   429,  1253,   390,    -1,  1246,    -1,
    1246,   663,   936,    -1,  1252,    -1,  1253,     5,  1252,    -1,
     541,  1256,    -1,   541,   429,  1255,   390,    -1,  1256,    -1,
    1255,     5,  1256,    -1,   936,    -1,   453,  1259,    -1,   453,
     429,  1258,   390,    -1,  1259,    -1,  1258,     5,  1259,    -1,
    1246,    -1,    85,    -1,    86,    -1,    84,    26,    -1,    56,
    1331,    -1,    56,   429,  1264,   390,    -1,    57,  1265,    -1,
      57,   429,  1264,   390,    -1,  1331,    -1,  1264,     5,  1331,
      -1,   936,    -1,   264,    -1,   230,    -1,   164,  1268,    -1,
     141,    -1,   129,    -1,   119,    -1,   117,    -1,   121,    -1,
     177,  1431,    -1,   229,  1267,   458,  1425,   625,  1425,    -1,
     297,   929,   458,  1425,   625,  1425,    -1,    -1,  1431,    -1,
      -1,   844,    -1,   522,   844,    -1,   228,    -1,    -1,   247,
    1272,  1374,  1275,  1273,    -1,    -1,   478,  1274,   429,  1277,
     390,    -1,  1411,    -1,    -1,   429,  1276,   390,    -1,  1377,
      -1,  1276,     5,  1377,    -1,  1278,    -1,  1277,     5,  1278,
      -1,  1417,    -1,   482,    -1,    -1,    -1,   499,  1280,  1283,
    1281,  1284,    -1,   937,    -1,  1288,   930,    -1,   930,    -1,
      -1,    -1,   553,  1285,  1112,    -1,    -1,    -1,   553,  1287,
    1112,    -1,   500,    -1,   554,    -1,   561,    -1,   373,    -1,
     340,    -1,   394,    -1,   376,   844,    -1,   349,   844,    -1,
     236,  1374,   149,   930,    -1,   236,  1374,  1347,    -1,   513,
     618,  1292,    -1,  1293,    -1,  1292,     5,  1293,    -1,  1294,
    1295,    -1,    26,    -1,  1377,    -1,    -1,   587,    -1,   538,
      -1,   275,    -1,   308,    -1,    -1,   325,    -1,   355,  1300,
    1298,    -1,  1463,    -1,    25,    -1,    -1,  1430,  1302,  1303,
      -1,  1332,    -1,  1336,    -1,  1297,    -1,  1432,    -1,  1296,
      -1,  1289,    -1,  1290,    -1,  1279,    -1,  1271,    -1,  1270,
      -1,  1401,    -1,  1447,    -1,   504,  1306,   624,  1374,   625,
    1311,  1305,    -1,    -1,   140,    -1,   167,    -1,  1307,    -1,
    1308,    -1,  1307,     5,  1308,    -1,   470,    -1,   448,    -1,
     437,    -1,   477,  1309,    -1,    -1,   429,  1310,   390,    -1,
    1377,    -1,  1310,     5,  1377,    -1,  1312,    -1,  1311,     5,
    1312,    -1,   461,    -1,  1375,    -1,   234,  1374,  1314,   616,
    1411,  1316,    -1,    -1,   429,  1315,   390,    -1,  1377,    -1,
    1315,     5,  1377,    -1,    -1,   139,    -1,   491,   429,  1350,
     390,    -1,   244,   429,  1320,   390,  1319,    -1,   295,  1321,
      -1,  1322,    -1,  1374,    -1,  1374,   429,  1322,   390,    -1,
    1377,    -1,  1322,     5,  1377,    -1,   475,   429,  1324,   390,
      -1,   257,   429,  1324,   390,    -1,  1377,    -1,  1324,     5,
    1377,    -1,  1323,    -1,  1318,    -1,  1317,    -1,   398,  1380,
      -1,   206,    -1,   936,  1366,  1328,  1329,    -1,    -1,  1326,
      -1,    -1,  1330,    -1,  1331,    -1,  1330,  1331,    -1,   371,
      -1,   157,    -1,   475,    -1,  1319,    -1,   491,   429,  1350,
     390,    -1,   118,  1333,  1335,    -1,  1334,    -1,  1375,    -1,
    1336,    -1,  1335,  1336,    -1,  1313,    -1,  1304,    -1,   446,
    1350,    -1,   367,  1339,    -1,  1416,    -1,  1339,     5,  1416,
      -1,   525,  1350,    -1,   546,  1342,    -1,  1343,    -1,  1342,
       5,  1343,    -1,  1344,    -1,   514,  1344,    -1,   514,   429,
    1345,   390,    -1,  1374,    -1,  1374,  1379,    -1,  1343,    -1,
    1345,     5,  1343,    -1,  1341,  1347,  1348,  1349,    -1,    -1,
    1340,    -1,    -1,  1338,    -1,    -1,  1337,    -1,  1351,    -1,
    1350,     6,  1351,    -1,  1352,    -1,  1351,     7,  1352,    -1,
    1353,    -1,     9,  1353,    -1,  1364,    -1,   429,  1350,   390,
      -1,   441,  1412,    -1,   293,  1412,    -1,    -1,   440,  1357,
      -1,  1418,    -1,  1421,    -1,  1417,   622,   429,  1359,   390,
      -1,  1417,   622,  1412,    -1,  1417,   427,   429,  1359,   390,
      -1,  1417,   427,  1412,    -1,  1360,    -1,  1359,     5,  1360,
      -1,  1467,    -1,  1380,    -1,    -1,     9,    -1,  1417,  1361,
     385,    -1,  1417,  1361,   248,    -1,  1417,  1363,  1417,    -1,
    1417,  1361,   387,  1417,     7,  1417,    -1,  1417,   556,  1356,
    1355,    -1,  1417,   370,  1356,  1355,    -1,  1417,  1361,    10,
    1356,  1355,    -1,    14,    -1,    17,    -1,    12,    -1,    13,
      -1,   251,    -1,    10,    -1,    16,    -1,    15,    -1,  1362,
      -1,  1358,    -1,  1354,    -1,    -1,   585,    -1,   358,    -1,
     475,    -1,  1367,    -1,  1368,    -1,  1370,    -1,   535,    -1,
     535,   429,  1371,   390,    -1,   409,   429,  1372,  1369,   390,
      -1,   471,    -1,   396,   429,  1372,  1369,   390,    -1,   511,
     429,  1372,  1369,   390,    -1,   537,    -1,   406,    -1,   378,
      -1,   356,  1387,   625,  1388,    -1,   356,    -1,   368,  1387,
     625,  1388,    -1,   368,    -1,   368,  1387,   429,    26,   390,
     625,  1388,    -1,   574,    -1,   532,    -1,   422,    -1,   422,
     429,    26,   390,    -1,   422,   429,    26,     5,    26,   390,
      -1,    -1,     5,  1373,    -1,   501,   429,  1372,   390,    -1,
     565,    -1,   298,    -1,   501,    -1,    63,    -1,    26,    -1,
      26,    -1,    26,    -1,    25,   619,   936,    -1,    25,    -1,
     936,    -1,   936,   589,   936,    -1,   936,    -1,    -1,   457,
      26,   425,    -1,   457,    26,     5,    26,   425,    -1,  1378,
      -1,   611,  1378,    -1,   936,  1376,    -1,  1374,   619,   936,
    1376,    -1,  1374,   619,    21,    -1,   936,    -1,    25,    -1,
     409,    -1,   942,    -1,    26,    -1,  1382,    -1,   394,  1384,
      -1,   394,  1383,    -1,    -1,  1387,   625,  1388,    -1,    -1,
    1385,   625,  1385,    -1,   581,    -1,   512,    -1,   590,    -1,
     552,    -1,   452,    -1,   469,    -1,   365,    -1,   365,   429,
      26,   390,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   452,    -1,   469,    -1,   365,    -1,   365,   429,    26,
     390,    -1,   581,    -1,   512,    -1,   590,    -1,   552,    -1,
     452,    -1,   469,    -1,   365,    -1,   581,    -1,   512,    -1,
     590,    -1,   552,    -1,   452,    -1,   469,    -1,   365,    -1,
     936,    -1,    25,    -1,  1430,   502,   930,    -1,    -1,  1430,
     397,  1282,   435,   595,  1399,  1392,  1396,    -1,    -1,  1430,
     397,  1282,   435,   100,   595,  1400,  1393,  1396,    -1,    -1,
    1430,   397,  1282,   135,  1400,  1394,  1396,    -1,    -1,  1430,
     397,  1282,   136,   100,   595,  1400,  1395,  1396,    -1,    -1,
     287,    -1,   286,  1397,    -1,  1398,    -1,  1397,     5,  1398,
      -1,   936,    -1,   936,   619,   936,    -1,    25,   619,   936,
     619,   936,    -1,  1400,    -1,  1271,    -1,  1147,    -1,  1402,
      -1,  1402,  1396,    -1,    -1,    -1,   470,  1413,  1403,  1414,
    1404,  1410,  1346,  1408,    -1,   470,  1413,  1414,  1346,  1408,
      -1,  1407,    -1,  1425,    -1,   470,  1413,  1414,  1410,  1346,
    1408,    -1,    -1,   524,  1365,  1406,    -1,  1291,    -1,   330,
    1409,  1242,    -1,  1291,   330,  1409,  1242,    -1,   936,    -1,
      -1,   553,  1112,    -1,   470,  1413,  1414,  1346,    -1,   429,
     470,  1413,  1414,  1346,   390,    -1,    -1,   585,    -1,   358,
      -1,   475,    -1,  1415,    -1,  1414,     5,  1415,    -1,  1417,
      -1,  1417,   936,    -1,  1417,    -1,  1418,    -1,    19,  1418,
      -1,    18,  1418,    -1,  1419,    -1,  1467,    -1,  1412,    -1,
     611,   936,    -1,   611,   936,   619,   936,    -1,  1418,    20,
    1417,    -1,  1418,  1439,    -1,  1418,    21,  1417,    -1,  1418,
      18,  1417,    -1,  1418,    19,  1417,    -1,  1380,    -1,   483,
      -1,   426,    -1,   576,    -1,    21,    -1,    64,    -1,   588,
     429,  1365,  1417,   390,    -1,   600,   429,  1365,  1417,   390,
      -1,   601,   429,  1365,  1417,   390,    -1,   608,   429,  1365,
    1417,   390,    -1,   495,   429,  1365,  1417,   390,    -1,   936,
     429,  1420,   390,    -1,   537,   429,  1420,   390,    -1,   429,
    1417,   390,    -1,   442,   429,  1440,   390,    -1,  1417,    -1,
    1420,     5,  1417,    -1,  1380,    -1,  1430,   345,  1429,  1424,
    1406,    -1,  1430,   334,  1429,  1424,   247,  1374,  1426,    -1,
    1430,   334,  1429,  1424,  1090,    -1,    -1,   320,  1425,    -1,
      25,    -1,  1090,    -1,    -1,   429,  1427,   390,    -1,  1428,
      -1,  1427,     5,  1428,    -1,   936,    -1,    25,    -1,  1090,
      -1,    -1,   266,  1431,   595,    -1,   937,    -1,  1437,    -1,
    1436,    -1,  1433,    -1,   315,  1434,   625,  1434,    -1,   296,
    1434,   619,  1435,   625,  1435,    -1,   936,    -1,   936,    -1,
     220,   787,    -1,   291,   787,  1438,    -1,   270,    -1,   174,
      -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    97,    -1,   394,     5,  1387,   625,  1388,    -1,  1467,
       5,  1387,   625,  1388,    -1,   394,  1387,   625,  1388,    -1,
      -1,   607,  1442,  1443,   188,    -1,  1444,    -1,  1443,  1444,
      -1,    33,    -1,  1445,    -1,  1446,    -1,   189,  1467,    -1,
     553,  1112,    -1,    -1,    -1,   477,  1374,  1448,  1451,  1449,
    1450,    -1,    -1,   149,   930,    -1,   525,  1350,    -1,    52,
    1455,   390,    14,   429,  1456,   390,    -1,    48,  1456,   390,
      -1,    49,  1456,   390,    -1,   583,  1452,    -1,    51,  1456,
      -1,    50,  1456,    -1,  1454,    -1,  1452,     5,  1454,    -1,
    1377,    -1,  1453,    14,  1457,    -1,  1453,    -1,  1455,     5,
    1453,    -1,  1457,    -1,  1456,     5,  1457,    -1,   482,    -1,
    1458,    -1,  1459,    -1,    19,  1459,    -1,    18,  1459,    -1,
    1461,    -1,  1412,    -1,   611,   936,    -1,   611,   936,   619,
     936,    -1,  1460,    -1,  1380,    -1,   483,    -1,   426,    -1,
     576,    -1,    64,    -1,  1459,    20,  1458,    -1,  1459,  1439,
      -1,  1459,    21,  1458,    -1,  1459,    18,  1458,    -1,  1459,
      19,  1458,    -1,   588,   429,  1365,  1458,   390,    -1,   600,
     429,  1365,  1458,   390,    -1,   601,   429,  1365,  1458,   390,
      -1,   608,   429,  1365,  1458,   390,    -1,   495,   429,  1365,
    1458,   390,    -1,   936,   429,  1462,   390,    -1,   537,   429,
    1462,   390,    -1,   429,  1458,   390,    -1,   442,   429,  1440,
     390,    -1,  1467,    -1,  1458,    -1,  1462,     5,  1458,    -1,
    1464,    -1,   189,  1465,    -1,  1465,    -1,  1099,    -1,   936,
      -1,  1465,   619,  1466,    -1,    25,   619,  1465,   619,  1466,
      -1,    21,    -1,  1120,    -1,   936,    -1,  1464,    -1,  1464,
     419,  1464,    -1,   126,  1469,    -1,   130,  1469,    -1,   125,
    1469,    -1,    46,    -1,   165,  1469,    -1,   123,  1469,    -1,
      47,    -1,   148,  1469,    -1,   147,  1469,    -1,   122,  1469,
      -1,   354,    -1,   620,   625,  1470,    -1,   547,  1470,    -1,
     572,    -1,   533,  1471,    -1,   936,    -1,   589,   936,    -1,
     936,    -1,    -1,    -1,   526,  1473,   844,  1474,  1488,   324,
      -1,    -1,   658,  1478,    -1,    -1,   661,    -1,   180,    -1,
     276,   931,    -1,    69,   931,    -1,   306,    -1,   305,    -1,
     307,   933,  1475,  1476,    -1,   492,  1478,  1476,    -1,   928,
      -1,  1478,     5,   928,    -1,   102,    -1,   132,   931,    -1,
     844,   566,     5,   844,   391,    -1,   508,   844,    -1,   263,
     931,    -1,   101,  1483,     8,  1484,  1482,    -1,    -1,   546,
     844,    -1,   936,    -1,   936,    -1,   246,   931,    -1,   249,
     931,   625,   844,     5,   844,    -1,   249,   931,   618,   844,
       5,   844,    -1,    27,    -1,    -1,  1490,    -1,  1491,  1196,
      -1,  1489,    -1,  1490,  1489,    -1,    -1,  1492,  1493,    -1,
     668,    -1,   669,    -1,   670,    -1,   671,    -1,   688,    -1,
     710,    -1,   724,    -1,   725,    -1,   731,    -1,   732,    -1,
     751,    -1,   819,    -1,   820,    -1,   821,    -1,   822,    -1,
     833,    -1,   834,    -1,   835,    -1,   836,    -1,   888,    -1,
     892,    -1,   922,    -1,   943,    -1,   944,    -1,   947,    -1,
     948,    -1,   949,    -1,   950,    -1,   963,    -1,   971,    -1,
     992,    -1,   993,    -1,   995,    -1,   999,    -1,  1016,    -1,
    1017,    -1,  1021,    -1,  1022,    -1,  1023,    -1,  1024,    -1,
    1032,    -1,  1047,    -1,  1060,    -1,  1071,    -1,  1072,    -1,
    1073,    -1,  1084,    -1,  1123,    -1,  1126,    -1,  1128,    -1,
    1134,    -1,  1135,    -1,  1138,    -1,  1141,    -1,  1144,    -1,
    1146,    -1,  1148,    -1,  1150,    -1,  1157,    -1,  1162,    -1,
    1166,    -1,  1167,    -1,  1168,    -1,  1180,    -1,  1232,    -1,
    1233,    -1,  1235,    -1,  1247,    -1,  1248,    -1,  1266,    -1,
    1269,    -1,  1299,    -1,  1301,    -1,  1390,    -1,  1391,    -1,
    1422,    -1,  1423,    -1,  1441,    -1,  1468,    -1,  1472,    -1,
    1477,    -1,  1479,    -1,  1481,    -1,  1485,    -1,  1486,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   927,   927,   930,   933,   939,   945,   952,   956,   956,
     962,   985,   986,   987,   988,   989,  1003,  1004,  1005,  1006,
    1007,  1012,  1013,  1024,  1027,  1030,  1030,  1034,  1037,  1038,
    1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1063,  1064,  1067,
    1067,  1082,  1083,  1086,  1092,  1094,  1105,  1107,  1109,  1111,
    1115,  1117,  1179,  1183,  1187,  1187,  1193,  1197,  1200,  1201,
    1204,  1210,  1204,  1223,  1228,  1232,  1223,  1244,  1248,  1244,
    1256,  1261,  1256,  1280,  1287,  1291,  1279,  1317,  1317,  1321,
    1322,  1323,  1328,  1331,  1336,  1340,  1348,  1351,  1351,  1357,
    1361,  1376,  1374,  1392,  1392,  1407,  1407,  1410,  1410,  1414,
    1417,  1417,  1417,  1424,  1425,  1424,  1432,  1432,  1443,  1443,
    1462,  1465,  1468,  1471,  1474,  1477,  1490,  1495,  1495,  1496,
    1496,  1499,  1504,  1504,  1508,  1518,  1532,  1536,  1531,  1546,
    1552,  1560,  1561,  1564,  1564,  1567,  1571,  1576,  1583,  1583,
    1587,  1587,  1594,  1594,  1599,  1599,  1604,  1604,  1609,  1609,
    1622,  1623,  1631,  1632,  1649,  1652,  1655,  1658,  1661,  1664,
    1670,  1681,  1686,  1699,  1703,  1718,  1719,  1723,  1723,  1727,
    1727,  1727,  1728,  1729,  1734,  1734,  1737,  1737,  1746,  1747,
    1748,  1751,  1755,  1756,  1756,  1773,  1773,  1773,  1773,  1777,
    1784,  1785,  1788,  1788,  1791,  1791,  1800,  1797,  1813,  1813,
    1815,  1815,  1817,  1819,  1821,  1823,  1826,  1830,  1830,  1831,
    1831,  1835,  1835,  1847,  1847,  1852,  1856,  1858,  1859,  1862,
    1862,  1862,  1866,  1867,  1868,  1869,  1876,  1877,  1878,  1879,
    1882,  1883,  1884,  1885,  1889,  1894,  1899,  1903,  1906,  1910,
    1911,  1912,  1913,  1914,  1915,  1916,  1917,  1920,  1921,  1922,
    1954,  1958,  1960,  1962,  1962,  1969,  1973,  1973,  1977,  1978,
    1979,  1980,  1981,  1982,  1983,  1989,  1989,  1992,  1994,  2000,
    2002,  2008,  2016,  2016,  2019,  2020,  2021,  2022,  2023,  2024,
    2025,  2031,  2034,  2034,  2047,  2047,  2054,  2055,  2056,  2058,
    2059,  2061,  2063,  2064,  2065,  2066,  2071,  2077,  2083,  2084,
    2086,  2088,  2089,  2090,  2091,  2092,  2093,  2096,  2097,  2104,
    2112,  2112,  2120,  2117,  2132,  2132,  2134,  2134,  2142,  2142,
    2145,  2148,  2149,  2154,  2166,  2170,  2173,  2176,  2177,  2178,
    2179,  2180,  2185,  2192,  2198,  2203,  2207,  2203,  2218,  2220,
    2225,  2230,  2230,  2234,  2234,  2237,  2237,  2243,  2243,  2249,
    2249,  2265,  2268,  2282,  2284,  2286,  2288,  2290,  2292,  2294,
    2300,  2302,  2306,  2308,  2310,  2312,  2314,  2316,  2318,  2324,
    2339,  2342,  2355,  2356,  2357,  2358,  2359,  2363,  2364,  2365,
    2369,  2374,  2381,  2382,  2383,  2384,  2385,  2386,  2387,  2388,
    2389,  2390,  2391,  2398,  2398,  2403,  2403,  2406,  2412,  2420,
    2426,  2436,  2437,  2445,  2452,  2456,  2466,  2470,  2475,  2480,
    2482,  2492,  2505,  2513,  2526,  2531,  2537,  2542,  2547,  2548,
    2554,  2625,  2631,  2636,  2644,  2644,  2659,  2663,  2670,  2673,
    2681,  2692,  2702,  2708,  2717,  2722,  2730,  2733,  2736,  2741,
    2748,  2753,  2758,  2763,  2773,  2781,  2789,  2794,  2798,  2803,
    2807,  2811,  2818,  2821,  2824,  2828,  2832,  2836,  2840,  2848,
    2858,  2863,  2856,  2879,  2884,  2879,  2901,  2901,  2901,  2904,
    2904,  2904,  2907,  2907,  2907,  2910,  2910,  2910,  2913,  2919,
    2925,  2931,  2941,  2941,  2945,  2949,  2950,  2957,  2958,  2964,
    2968,  2978,  2988,  2989,  2992,  2997,  3003,  3007,  3011,  3014,
    3020,  3023,  3026,  3043,  3046,  3052,  3053,  3054,  3058,  3059,
    3060,  3061,  3062,  3064,  3065,  3066,  3068,  3069,  3073,  3074,
    3079,  3080,  3092,  3096,  3091,  3104,  3107,  3121,  3125,  3130,
    3120,  3150,  3156,  3150,  3170,  3170,  3172,  3173,  3177,  3177,
    3181,  3181,  3186,  3186,  3193,  3194,  3198,  3198,  3202,  3202,
    3207,  3207,  3214,  3218,  3219,  3220,  3225,  3225,  3228,  3228,
    3232,  3232,  3236,  3236,  3240,  3240,  3245,  3245,  3250,  3250,
    3255,  3255,  3260,  3260,  3276,  3293,  3294,  3295,  3296,  3297,
    3298,  3301,  3301,  3304,  3306,  3309,  3312,  3314,  3315,  3316,
    3318,  3320,  3322,  3324,  3328,  3335,  3337,  3343,  3348,  3353,
    3358,  3358,  3361,  3367,  3372,  3375,  3382,  3382,  3384,  3385,
    3387,  3389,  3391,  3393,  3397,  3406,  3406,  3468,  3480,  3487,
    3487,  3491,  3496,  3502,  3506,  3510,  3516,  3520,  3524,  3530,
    3530,  3538,  3539,  3543,  3543,  3547,  3548,  3551,  3554,  3554,
    3557,  3559,  3559,  3562,  3564,  3564,  3565,  3567,  3567,  3576,
    3574,  3586,  3586,  3586,  3589,  3591,  3589,  3598,  3601,  3607,
    3618,  3618,  3622,  3628,  3628,  3632,  3633,  3644,  3645,  3647,
    3649,  3654,  3654,  3658,  3657,  3664,  3663,  3669,  3669,  3674,
    3674,  3680,  3680,  3685,  3685,  3690,  3690,  3695,  3695,  3698,
    3698,  3701,  3701,  3704,  3704,  3746,  3747,  3755,  3756,  3765,
    3770,  3775,  3776,  3777,  3781,  3780,  3791,  3796,  3801,  3801,
    3817,  3822,  3823,  3824,  3825,  3828,  3828,  3831,  3838,  3839,
    3840,  3841,  3842,  3843,  3844,  3845,  3846,  3851,  3851,  3853,
    3856,  3856,  3858,  3862,  3862,  3865,  3866,  3869,  3869,  3874,
    3874,  3877,  3878,  3879,  3880,  3881,  3882,  3883,  3884,  3885,
    3886,  3887,  3888,  3889,  3890,  3891,  3892,  3893,  3897,  3915,
    3915,  3915,  3942,  3953,  3960,  3966,  3972,  3978,  3989,  4012,
    4011,  4028,  4028,  4032,  4033,  4041,  4042,  4043,  4044,  4051,
    4052,  4054,  4055,  4059,  4064,  4065,  4066,  4067,  4068,  4069,
    4070,  4071,  4072,  4073,  4074,  4077,  4077,  4079,  4079,  4079,
    4081,  4085,  4085,  4094,  4099,  4115,  4121,  4093,  4135,  4149,
    4159,  4148,  4172,  4179,  4179,  4184,  4189,  4194,  4195,  4198,
    4198,  4198,  4201,  4201,  4209,  4215,  4229,  4233,  4246,  4228,
    4264,  4264,  4278,  4289,  4288,  4300,  4296,  4313,  4310,  4323,
    4323,  4325,  4326,  4328,  4329,  4332,  4333,  4334,  4336,  4341,
    4346,  4352,  4354,  4355,  4358,  4359,  4362,  4364,  4373,  4379,
    4373,  4390,  4391,  4395,  4395,  4405,  4405,  4417,  4420,  4423,
    4426,  4430,  4434,  4435,  4436,  4437,  4438,  4442,  4447,  4447,
    4450,  4476,  4535,  4535,  4538,  4542,  4546,  4589,  4631,  4632,
    4633,  4636,  4650,  4662,  4662,  4667,  4668,  4674,  4734,  4791,
    4796,  4803,  4808,  4816,  4822,  4856,  4859,  4860,  4901,  4944,
    4945,  4949,  4950,  4954,  5007,  5011,  5014,  5020,  5031,  5038,
    5046,  5046,  5049,  5050,  5051,  5052,  5053,  5056,  5059,  5065,
    5068,  5072,  5076,  5083,  5088,  5095,  5098,  5104,  5106,  5106,
    5106,  5110,  5130,  5137,  5144,  5147,  5161,  5168,  5169,  5172,
    5173,  5177,  5183,  5188,  5194,  5195,  5200,  5204,  5204,  5208,
    5209,  5212,  5213,  5217,  5225,  5228,  5234,  5235,  5237,  5239,
    5243,  5243,  5244,  5249,  5257,  5258,  5263,  5264,  5266,  5279,
    5281,  5282,  5284,  5287,  5290,  5293,  5297,  5300,  5303,  5307,
    5311,  5315,  5318,  5322,  5325,  5326,  5327,  5330,  5333,  5336,
    5339,  5342,  5345,  5348,  5364,  5372,  5372,  5374,  5381,  5388,
    5403,  5401,  5421,  5426,  5427,  5431,  5432,  5434,  5435,  5437,
    5437,  5445,  5454,  5454,  5464,  5465,  5468,  5469,  5472,  5476,
    5490,  5495,  5500,  5505,  5515,  5515,  5519,  5522,  5522,  5524,
    5534,  5543,  5550,  5552,  5556,  5559,  5559,  5563,  5562,  5566,
    5565,  5569,  5568,  5572,  5571,  5575,  5574,  5577,  5577,  5593,
    5592,  5614,  5615,  5616,  5617,  5618,  5619,  5622,  5622,  5628,
    5628,  5631,  5631,  5641,  5642,  5643,  5650,  5662,  5663,  5666,
    5667,  5670,  5673,  5673,  5678,  5682,  5687,  5693,  5694,  5695,
    5699,  5700,  5701,  5702,  5706,  5716,  5718,  5723,  5726,  5731,
    5737,  5744,  5751,  5760,  5767,  5774,  5781,  5788,  5797,  5797,
    5799,  5799,  5802,  5803,  5804,  5805,  5806,  5807,  5808,  5809,
    5810,  5811,  5814,  5814,  5817,  5818,  5819,  5820,  5823,  5823,
    5826,  5826,  5829,  5830,  5831,  5832,  5833,  5834,  5835,  5836,
    5838,  5839,  5840,  5841,  5843,  5844,  5845,  5846,  5848,  5849,
    5850,  5851,  5852,  5853,  5854,  5855,  5859,  5865,  5873,  5884,
    5893,  5904,  5908,  5912,  5918,  5883,  5931,  5934,  5942,  5954,
    5956,  5961,  5969,  5979,  5982,  5986,  5994,  5960,  6003,  6007,
    6011,  6015,  6007,  6025,  6026,  6027,  6028,  6033,  6035,  6038,
    6042,  6045,  6052,  6057,  6058,  6059,  6064,  6065,  6071,  6071,
    6071,  6076,  6076,  6076,  6087,  6088,  6094,  6095,  6107,  6108,
    6113,  6114,  6115,  6119,  6122,  6128,  6131,  6139,  6140,  6146,
    6153,  6156,  6165,  6168,  6171,  6174,  6177,  6180,  6183,  6190,
    6193,  6200,  6203,  6209,  6212,  6219,  6222,  6229,  6230,  6235,
    6239,  6242,  6248,  6251,  6257,  6264,  6265,  6269,  6275,  6278,
    6285,  6286,  6293,  6296,  6301,  6312,  6313,  6314,  6315,  6316,
    6317,  6318,  6319,  6320,  6323,  6326,  6332,  6332,  6338,  6338,
    6349,  6362,  6372,  6372,  6377,  6377,  6381,  6385,  6386,  6392,
    6393,  6398,  6402,  6409,  6412,  6419,  6423,  6418,  6432,  6436,
    6440,  6447,  6451,  6451,  6464,  6468,  6468,  6483,  6485,  6487,
    6489,  6491,  6493,  6495,  6497,  6503,  6513,  6520,  6525,  6526,
    6530,  6532,  6533,  6536,  6537,  6538,  6541,  6546,  6553,  6554,
    6560,  6572,  6573,  6576,  6576,  6581,  6586,  6591,  6592,  6595,
    6596,  6601,  6606,  6610,  6615,  6616,  6620,  6627,  6631,  6632,
    6637,  6639,  6643,  6644,  6648,  6649,  6650,  6651,  6655,  6656,
    6661,  6662,  6667,  6668,  6673,  6674,  6679,  6684,  6685,  6690,
    6691,  6695,  6696,  6701,  6708,  6713,  6718,  6722,  6723,  6728,
    6729,  6735,  6737,  6742,  6743,  6749,  6752,  6755,  6762,  6764,
    6778,  6783,  6784,  6787,  6789,  6796,  6799,  6805,  6809,  6813,
    6817,  6820,  6827,  6834,  6839,  6843,  6844,  6850,  6853,  6864,
    6871,  6877,  6880,  6887,  6894,  6900,  6901,  6907,  6908,  6909,
    6912,  6913,  6918,  6918,  6922,  6930,  6931,  6934,  6937,  6942,
    6943,  6948,  6951,  6957,  6960,  6966,  6969,  6975,  6978,  6985,
    6986,  7015,  7016,  7021,  7029,  7034,  7037,  7040,  7043,  7049,
    7050,  7054,  7057,  7060,  7061,  7066,  7069,  7072,  7075,  7078,
    7081,  7084,  7090,  7091,  7092,  7093,  7094,  7096,  7098,  7099,
    7104,  7107,  7111,  7117,  7118,  7119,  7120,  7132,  7133,  7134,
    7138,  7139,  7144,  7146,  7147,  7148,  7150,  7151,  7152,  7153,
    7155,  7156,  7158,  7159,  7161,  7162,  7163,  7164,  7166,  7170,
    7171,  7177,  7179,  7180,  7181,  7182,  7187,  7191,  7195,  7199,
    7200,  7204,  7205,  7215,  7224,  7225,  7226,  7230,  7233,  7238,
    7243,  7248,  7256,  7260,  7264,  7265,  7266,  7271,  7274,  7277,
    7291,  7305,  7318,  7319,  7323,  7323,  7323,  7323,  7323,  7323,
    7324,  7327,  7332,  7332,  7332,  7332,  7332,  7332,  7334,  7337,
    7343,  7343,  7343,  7343,  7343,  7343,  7343,  7344,  7344,  7344,
    7344,  7344,  7344,  7344,  7346,  7347,  7350,  7359,  7359,  7365,
    7365,  7372,  7372,  7378,  7378,  7386,  7387,  7388,  7391,  7391,
    7394,  7395,  7396,  7401,  7404,  7410,  7415,  7423,  7436,  7437,
    7434,  7455,  7465,  7468,  7473,  7485,  7488,  7492,  7495,  7496,
    7502,  7505,  7506,  7515,  7524,  7529,  7530,  7531,  7532,  7539,
    7542,  7548,  7551,  7561,  7570,  7573,  7576,  7582,  7588,  7591,
    7594,  7597,  7603,  7605,  7607,  7609,  7611,  7613,  7614,  7615,
    7616,  7617,  7618,  7619,  7621,  7623,  7625,  7627,  7629,  7631,
    7633,  7634,  7639,  7640,  7647,  7650,  7659,  7663,  7670,  7670,
    7674,  7674,  7679,  7679,  7683,  7683,  7687,  7693,  7693,  7696,
    7696,  7702,  7709,  7710,  7711,  7715,  7716,  7719,  7720,  7724,
    7730,  7740,  7741,  7749,  7750,  7751,  7752,  7753,  7754,  7758,
    7759,  7760,  7764,  7764,  7776,  7777,  7781,  7782,  7783,  7787,
    7793,  7880,  7884,  7880,  7893,  7897,  7903,  7911,  7921,  7931,
    7943,  7946,  7965,  7991,  7994,  8000,  8003,  8008,  8011,  8019,
    8027,  8040,  8043,  8051,  8054,  8057,  8065,  8069,  8072,  8075,
    8078,  8082,  8083,  8084,  8085,  8086,  8092,  8093,  8094,  8095,
    8096,  8097,  8098,  8099,  8100,  8101,  8102,  8103,  8104,  8105,
    8109,  8115,  8116,  8128,  8149,  8149,  8153,  8154,  8155,  8156,
    8160,  8161,  8162,  8167,  8193,  8244,  8246,  8248,  8250,  8254,
    8259,  8261,  8264,  8266,  8268,  8272,  8275,  8280,  8285,  8289,
    8298,  8299,  8303,  8315,  8318,  8314,  8337,  8337,  8341,  8342,
    8345,  8346,  8347,  8348,  8349,  8350,  8351,  8356,  8357,  8361,
    8364,  8369,  8373,  8378,  8382,  8387,  8391,  8394,  8398,  8401,
    8406,  8410,  8421,  8427,  8427,  8428,  8429,  8436,  8445,  8445,
    8447,  8448,  8449,  8450,  8451,  8452,  8453,  8454,  8455,  8456,
    8457,  8458,  8459,  8460,  8461,  8462,  8463,  8464,  8465,  8466,
    8467,  8468,  8469,  8470,  8471,  8472,  8473,  8474,  8475,  8476,
    8477,  8478,  8479,  8480,  8481,  8482,  8483,  8484,  8485,  8486,
    8487,  8488,  8489,  8490,  8491,  8492,  8493,  8494,  8495,  8496,
    8497,  8498,  8499,  8500,  8501,  8502,  8503,  8504,  8505,  8506,
    8507,  8508,  8509,  8510,  8511,  8512,  8513,  8514,  8515,  8516,
    8517,  8518,  8519,  8520,  8521,  8522,  8523,  8524,  8525,  8526,
    8527,  8528,  8529,  8530,  8531
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
  "PLUS", "MINUS", "DIVIDE", "MULTIPLY", "MOD", "COMMAND", "NUMBER_VALUE", 
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
  "KWNO", "LET", "LOG", "XMAX", "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", 
  "SQL", "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", 
  "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", 
  "UP", "FONT_NAME", "FONT_SIZE", "PAPER_SIZE_IS_LETTER", 
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
  "gui_message", "msg_start", "op_msg_wait", "msg_wait", "variable", 
  "var_int", "varsetidentdot", "var", "assoc_var_read", "assoc_var_write", 
  "assoc_sub", "dot_part_var", "array_r_variable", 
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
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@126", 
  "gui_prompt_cmd", "opt_char", "prompt_key_sec", "prompt_key_clause", 
  "on_key_command_prompt", "@127", "prompt_title", "put_cmd", "@128", 
  "put_from", "put_val_list", "put_val", "start_cmd", "rout", "rep_name", 
  "op_values", "output_cmd", "finish_cmd", "term_rep_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@129", "@130", "@131", "@132", "@133", "@134", "@135", "report_cmd", 
  "need_command", "@136", "op_lines", "skip_command", "@137", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
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
  "sql_block_entry", "in_var", "sql_block_into", "update_statement_ss", 
  "@171", "@172", "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind_ss", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@173", "@174", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@175", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1652,  1653,  1654,  1569,  1609,  1564,  1500,  1584,
    1378,  1486,  1482,  1396,  1559,  1295,  1353,  1427,  1595,  1582,
    1515,  1487,  1583,  1360,  1655,  1656,  1657,  1658,  1659,  1660,
    1661,  1662,  1663,  1664,  1000,  1001,  1002,  1003,  1004,  1005,
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
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1296,
    1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1354,  1355,  1356,  1357,
    1358,  1359,  1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1379,
    1380,  1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1397,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1483,  1484,  1485,  1488,  1489,  1490,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1501,  1502,  1503,  1504,  1505,
    1506,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,  1516,
    1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,
    1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1560,  1561,  1562,  1563,  1565,  1566,  1567,  1568,
    1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,
    1580,  1581,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
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
    1085,  1085,  1086,  1086,  1086,  1086,  1086,  1087,  1088,  1088,
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
    1276,  1277,  1277,  1278,  1278,  1280,  1281,  1279,  1282,  1283,
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
    1354,  1355,  1355,  1356,  1357,  1358,  1358,  1358,  1358,  1359,
    1359,  1360,  1360,  1361,  1361,  1362,  1362,  1362,  1362,  1362,
    1362,  1362,  1363,  1363,  1363,  1363,  1363,  1363,  1363,  1363,
    1364,  1364,  1364,  1365,  1365,  1365,  1365,  1366,  1366,  1366,
    1367,  1367,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,
    1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1368,  1369,
    1369,  1370,  1370,  1370,  1370,  1370,  1371,  1372,  1373,  1374,
    1374,  1374,  1374,  1375,  1376,  1376,  1376,  1377,  1377,  1378,
    1378,  1378,  1379,  1380,  1380,  1380,  1380,  1380,  1381,  1382,
    1383,  1383,  1384,  1384,  1385,  1385,  1385,  1385,  1385,  1385,
    1385,  1385,  1386,  1386,  1386,  1386,  1386,  1386,  1386,  1386,
    1387,  1387,  1387,  1387,  1387,  1387,  1387,  1388,  1388,  1388,
    1388,  1388,  1388,  1388,  1389,  1389,  1390,  1392,  1391,  1393,
    1391,  1394,  1391,  1395,  1391,  1396,  1396,  1396,  1397,  1397,
    1398,  1398,  1398,  1399,  1399,  1400,  1400,  1401,  1403,  1404,
    1402,  1405,  1406,  1406,  1407,  1408,  1408,  1408,  1408,  1408,
    1409,  1410,  1410,  1411,  1412,  1413,  1413,  1413,  1413,  1414,
    1414,  1415,  1415,  1416,  1417,  1417,  1417,  1418,  1418,  1418,
    1418,  1418,  1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,
    1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,  1419,
    1419,  1419,  1420,  1420,  1421,  1422,  1423,  1423,  1424,  1424,
    1425,  1425,  1426,  1426,  1427,  1427,  1428,  1429,  1429,  1430,
    1430,  1431,  1432,  1432,  1432,  1433,  1433,  1434,  1435,  1436,
    1437,  1438,  1438,  1439,  1439,  1439,  1439,  1439,  1439,  1440,
    1440,  1440,  1442,  1441,  1443,  1443,  1444,  1444,  1444,  1445,
    1446,  1448,  1449,  1447,  1450,  1450,  1450,  1451,  1451,  1451,
    1451,  1451,  1451,  1452,  1452,  1453,  1454,  1455,  1455,  1456,
    1456,  1457,  1457,  1458,  1458,  1458,  1459,  1459,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1460,  1460,  1460,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,
    1461,  1462,  1462,  1463,  1464,  1464,  1465,  1465,  1465,  1465,
    1466,  1466,  1466,  1467,  1467,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1469,  1469,  1469,  1469,  1469,
    1470,  1470,  1471,  1473,  1474,  1472,  1475,  1475,  1476,  1476,
    1477,  1477,  1477,  1477,  1477,  1477,  1477,  1478,  1478,  1479,
    1479,  1480,  1480,  1481,  1481,  1482,  1482,  1483,  1484,  1485,
    1486,  1486,  1487,  1488,  1488,  1489,  1490,  1490,  1492,  1491,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,  1493,
    1493,  1493,  1493,  1493,  1493
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
       3,     1,     3,     1,     1,     0,     0,     5,     1,     2,
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
       2,     0,     2,     1,     1,     5,     3,     5,     3,     1,
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
       3,     4,     1,     3,     1,     5,     7,     5,     0,     2,
       1,     1,     0,     3,     1,     3,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     4,     6,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     0,     4,     1,     2,     1,     1,     1,     2,
       2,     0,     0,     6,     0,     2,     2,     7,     3,     3,
       2,     2,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     2,     1,     1,     2,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       3,     5,     5,     5,     5,     5,     4,     4,     3,     4,
       1,     1,     3,     1,     2,     1,     1,     1,     3,     5,
       1,     1,     1,     1,     3,     2,     2,     2,     1,     2,
       2,     1,     2,     2,     2,     1,     3,     2,     1,     2,
       1,     2,     1,     0,     0,     6,     0,     2,     0,     1,
       1,     2,     2,     1,     1,     4,     3,     1,     3,     1,
       2,     5,     2,     2,     5,     0,     2,     1,     1,     2,
       6,     6,     1,     0,     1,     2,     1,     2,     0,     2,
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
     781,     0,  1758,  1761,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   832,   179,   805,   810,   177,
     182,   785,     0,   779,   782,   783,   786,   788,   831,   787,
     826,   827,   829,   183,   134,   131,     0,   127,   129,   128,
     132,  1802,   669,   612,  1765,     0,     0,  1768,     0,  1764,
    1760,  1757,  1755,  1756,  1763,  1762,  1759,   294,  1565,  1564,
     825,   175,   186,   178,   183,     1,   789,   784,   830,   828,
     806,   126,   130,   133,  1772,  1769,     0,  1770,  1767,     0,
       0,   591,     0,     0,   176,   835,   899,   592,   833,   624,
     891,     0,   892,   900,   898,   186,   180,   199,     0,   184,
     200,   229,     0,   812,  1181,     0,     0,   811,   135,  1169,
     819,     0,     0,   802,   804,   801,   803,   780,   790,   791,
     813,   794,   795,   796,   799,   797,   798,   800,  1771,  1766,
       0,   893,   834,     0,     0,   907,   905,   906,   895,   894,
     292,   186,  1105,   193,   187,   186,   192,   226,     0,   668,
       0,     0,     0,     0,   175,   541,   868,   792,     0,   326,
     312,   202,   263,   282,   303,   305,   302,     0,   324,     0,
     311,   304,   308,   314,   298,   313,   186,   315,   295,   318,
     296,   297,   904,   903,     0,    21,    22,    13,     0,   913,
       0,    15,     0,   911,     0,   293,     0,   185,  1106,   181,
       0,   199,   201,   259,   253,   254,   242,   219,   250,   202,
     221,   263,   282,   240,   243,   238,     0,   217,     0,   249,
     241,   246,   252,   234,   251,   186,   255,   186,   232,   233,
     230,   258,     0,     0,     0,     0,   820,   175,   175,     0,
       0,   203,     0,   316,     0,     0,   317,     0,     0,     0,
       0,     0,     0,     0,     0,   261,     0,   901,     0,    16,
      17,    19,    18,    20,     0,    14,     0,   909,     0,   625,
     188,   191,     0,   189,   190,     0,   196,   195,   194,   197,
     186,     0,   186,   256,   257,     0,     0,   186,     0,     0,
       0,     0,   239,   227,  1182,     0,     0,  1170,  1808,   542,
     869,   814,     0,   208,   209,     0,   275,   277,   272,   273,
     269,   271,   268,   270,   267,     0,   277,   288,   289,   285,
     287,   284,   286,   279,     0,     0,     0,   328,     0,   331,
     333,   216,     0,   215,     0,     0,   186,    11,    12,   912,
       0,   896,   626,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   228,   231,   924,   667,   836,   924,
       0,  1806,  1808,  1105,  1659,   807,     0,   924,     0,     0,
     264,     0,     0,   274,   291,   265,   290,     0,   283,     0,
     306,     0,   300,     0,   325,     0,   330,   320,     0,     0,
     309,   299,   262,   319,     0,     0,     0,     0,     0,     0,
     244,     0,   236,   218,   204,     0,   247,   235,   260,   930,
       0,   925,   926,   924,     0,   821,  1807,  1805,     0,     0,
       0,     0,     0,     0,     0,     0,  1789,     0,  1271,  1270,
       0,  1272,     0,   376,  1269,  1211,     0,     5,  1268,   377,
     374,     0,   379,   173,   469,  1083,     0,     0,  1278,   123,
     373,   372,  1203,   367,     0,  1228,  1780,     0,   378,   345,
       0,     3,     2,     0,   375,  1208,     0,     0,   368,   365,
     380,     0,     0,     0,     0,  1276,  1266,   371,     0,     0,
       0,     0,     0,     0,     0,     0,  1265,     0,     0,     0,
     174,  1205,   364,   363,     0,     0,  1784,  1783,     0,     0,
       0,   136,  1204,   370,   369,     0,     0,   366,   469,   469,
       0,   537,     0,     0,     0,   469,     0,     0,     0,   469,
     768,  1179,     0,     0,  1087,     0,  1773,     0,   103,     0,
       0,   840,     0,     0,     0,     0,   769,     0,     0,  1682,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   639,
       0,     0,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,   878,
    1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,
    1867,  1868,  1869,  1870,  1871,  1872,  1873,  1074,  1076,  1071,
    1073,  1072,  1075,  1874,  1875,  1202,  1876,  1207,  1206,  1877,
    1878,  1879,  1880,  1881,  1882,  1883,  1884,  1885,  1886,  1333,
    1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1809,   808,
     546,   809,     0,   873,     0,   871,     0,   327,   210,   211,
       0,   276,   281,     0,     0,     0,     0,   329,   332,     0,
     214,     0,   910,     0,   220,     0,   186,     0,     0,     0,
       0,     0,  1183,     0,     0,  1171,     0,     0,  1215,   613,
     614,   793,  1046,  1051,  1782,   606,   122,     0,     0,  1747,
    1746,   984,  1743,  1745,  1797,     0,  1222,     0,  1218,  1227,
       7,     0,     6,     0,  1790,  1047,     0,  1139,  1138,  1086,
    1137,  1085,     0,     0,     0,   424,   426,     0,  1176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1532,
       0,     0,     0,   418,     0,     0,     0,     0,   417,     0,
       0,   434,     0,   505,     0,     0,     0,     0,     0,     0,
     413,  1279,     0,   383,   382,   389,   430,   427,   384,   503,
     495,   385,   387,   502,   388,   899,   425,   428,   433,  1267,
     504,  1661,  1273,   124,     0,  1050,   121,     0,   775,    23,
     608,   381,     0,   774,  1043,   776,     0,  1277,   862,   861,
     864,   860,   863,  1799,     0,   858,     0,   607,   957,   859,
    1793,     0,  1781,   120,   954,   670,   952,     0,   604,  1776,
     712,   711,     0,   713,   596,   709,     0,     0,   967,   609,
    1332,  1328,  1331,     0,     0,  1019,  1017,     0,  1011,  1013,
    1012,  1010,  1009,     0,     0,     0,  1008,     0,   749,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     998,   989,   990,     0,  1031,   411,    23,   822,   403,  1787,
       0,  1778,   125,   605,     0,  1016,  1015,  1180,  1178,  1104,
       0,  1650,  1651,  1105,  1193,  1105,  1088,  1089,  1092,  1107,
    1280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,   899,     0,    68,     0,   101,   584,   627,     0,
    1077,   974,  1081,     0,     0,  1032,  1197,     0,     0,  1084,
     631,   628,   629,     0,   633,   634,     0,   636,   637,     0,
     632,   934,   936,     0,     0,   935,   714,   932,   679,   928,
     890,     0,     0,     0,     0,   643,   644,     0,     0,   888,
     885,   886,   882,   883,   884,   877,   881,   880,     0,     0,
       0,     0,     0,     0,   550,   552,   544,   547,   548,   875,
    1808,   870,   872,   815,     0,   278,   280,   307,   301,     0,
       0,   310,   897,     0,   225,     0,   223,   245,   237,   229,
     248,   931,   175,   927,   837,   175,     0,     0,     0,  1255,
    1256,     0,     0,     0,  1229,  1230,  1232,  1233,  1234,  1238,
    1237,  1235,  1236,     0,     0,  1744,   908,     0,   986,     0,
       0,  1221,  1220,     0,  1214,     0,  1510,  1511,     0,  1048,
       0,    23,  1134,  1136,  1135,   416,   391,   390,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,  1540,  1538,  1539,  1535,  1537,  1534,  1536,  1528,     0,
       0,     0,     0,     0,   431,     0,     0,   509,   508,     0,
       0,   479,   476,   485,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   510,   511,   512,   445,     0,     0,   444,   454,
       0,     0,   395,     0,     0,   396,   386,   392,   394,   397,
     398,   399,   400,   401,   393,   423,   422,   470,     0,     0,
     944,     0,     0,   350,    24,   344,     0,     0,  1040,     0,
       0,     0,     0,     0,     0,     0,   961,  1660,     0,     0,
     186,     0,     0,     0,  1778,     0,     0,     0,     0,     0,
     137,     0,     0,   971,   963,   964,   969,  1329,  1330,   887,
     409,   334,     0,   538,   589,   588,   586,   992,   590,   997,
     993,   996,   742,     0,   994,   995,   743,  1002,  1006,   999,
    1000,  1004,  1005,  1003,  1001,  1007,     0,   777,     0,     0,
       0,   406,   407,   404,   405,     0,     0,     0,   722,   721,
     720,  1779,  1786,    23,  1100,  1101,  1102,  1103,  1097,  1095,
    1194,  1109,  1094,  1090,     0,     0,  1091,  1774,     0,     0,
       0,     0,    97,     0,    98,     0,     0,     0,    73,     0,
       0,     0,   110,   105,     0,   867,     0,   866,     0,   469,
    1079,     0,   919,   920,   943,   914,   915,   770,   941,  1034,
    1199,     0,  1201,  1200,  1686,     0,     0,     0,  1684,  1687,
    1688,   659,     0,     0,     0,   648,   679,   679,   677,     0,
       0,   680,     0,    25,   647,   650,     0,   657,   653,   889,
     879,  1657,  1658,  1648,  1648,  1298,     0,     0,  1566,     0,
     186,  1281,     0,     0,  1282,  1326,   186,     0,  1327,     0,
    1605,     0,  1295,     0,  1344,  1343,  1342,  1340,  1341,  1339,
    1337,  1334,  1408,  1407,  1335,  1336,  1345,  1575,  1338,  1664,
    1663,  1662,  1346,  1808,  1808,   563,   554,   545,     0,   549,
    1808,   874,   175,     0,   321,   213,     0,   186,   222,   205,
    1184,   175,  1172,  1398,     0,  1397,     0,  1399,     0,  1400,
    1258,     0,  1264,  1260,  1257,     0,     0,     0,     0,     0,
       0,  1254,  1250,  1387,  1386,  1385,  1226,  1225,     0,  1249,
    1245,     0,  1241,  1239,     0,   617,     0,   616,     0,   985,
       0,     0,   983,  1750,  1752,  1751,  1748,  1798,  1795,  1219,
       0,     0,     0,  1212,   469,   342,     0,  1177,     0,     0,
       0,     0,  1605,     0,     0,     0,     0,     0,   527,   513,
     518,     0,   514,   517,   516,     0,     0,     0,     0,     0,
       0,   419,     0,   171,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,   437,   436,   455,   446,   461,   464,
     465,   462,   468,   467,   466,   456,   457,   459,   458,   460,
     402,   447,   451,   469,   463,   450,   469,    92,     0,   429,
       0,  1209,   976,  1044,  1045,  1042,  1041,     0,   865,     0,
       0,   593,     0,     0,     0,   955,   953,     0,   672,   673,
       0,     0,  1777,  1785,     0,     0,   600,     0,   602,   710,
       0,   141,     0,   965,   972,     0,     0,   980,     0,   337,
       0,     0,     0,     0,    23,  1018,  1304,     0,     0,   767,
     754,   765,   766,   752,   753,   761,   756,   760,   755,   764,
     759,   762,   758,   763,   751,   757,   750,   749,   991,   778,
     412,     0,  1023,     0,  1788,   723,   724,   361,     0,  1105,
       0,  1108,  1093,  1808,     0,     0,     0,   530,     0,     0,
       0,     0,    63,    92,     0,     0,   116,   111,     0,   106,
       0,   113,   107,   851,   843,   849,     0,  1078,     0,  1080,
    1082,     0,     0,   923,     0,     0,     0,     0,  1033,  1198,
    1753,  1689,   939,  1690,   937,  1683,  1685,  1808,   630,   635,
     638,   651,   649,   610,     0,   699,   697,   703,   701,     0,
       0,   695,   739,   693,   689,   687,   737,   715,     0,   681,
     691,   933,   929,     0,     0,     0,     0,   656,     0,     0,
       0,     0,     0,     0,     0,  1513,     0,  1403,  1404,  1669,
    1367,  1425,     0,     0,  1667,     0,     0,  1607,  1608,  1606,
    1588,  1691,     0,  1350,  1356,  1355,  1354,  1358,     0,  1351,
    1352,     0,  1576,  1587,   551,   553,     0,     0,   566,   558,
     560,     0,   555,   556,     0,     0,   574,   576,     0,     0,
     572,   876,   816,   212,     0,     0,   224,  1140,   838,  1118,
    1375,  1377,     0,  1262,     0,     0,     0,     0,     0,  1252,
       0,     0,  1505,  1503,  1490,  1492,  1488,     0,  1487,     0,
    1496,  1483,  1504,     0,  1495,  1480,  1486,  1502,  1494,  1391,
    1477,  1478,  1479,     0,  1247,  1243,     0,     0,  1231,   615,
       0,     0,     0,     0,     0,  1794,     4,     8,    10,  1509,
    1512,     0,   469,   501,   498,   497,   500,   496,     0,   421,
     507,   492,   492,     0,   515,     0,   519,     0,   282,  1176,
       0,  1533,   499,  1176,   506,   420,   266,     0,  1176,   480,
     477,   486,  1176,   483,  1176,  1176,  1176,     0,     0,     0,
       0,     0,     0,     0,     0,   471,    93,    94,    96,   473,
       0,     0,     0,   973,     0,     0,     0,     0,     0,     0,
       0,   186,   671,     0,   597,   599,     0,     0,   158,   156,
       0,     0,   138,     0,   148,   154,   679,   143,   145,     0,
     970,   981,   982,     0,   410,   336,   341,   595,   335,     0,
     338,   343,  1305,   539,   587,   585,   749,   744,   745,  1022,
    1024,     0,   408,   362,  1098,  1096,  1195,  1196,     0,     0,
    1189,     0,     0,     0,     0,    99,     0,     0,    74,    80,
      70,  1808,  1808,   109,   104,   118,   114,     0,   108,   740,
     852,   610,  1808,   842,   841,   850,   975,     0,     0,   921,
     922,   916,   942,   469,     0,     0,  1631,  1523,  1526,  1632,
    1530,  1524,  1629,     0,     0,  1039,  1628,     0,     0,  1630,
       0,     0,     0,     0,     0,  1747,  1525,  1035,  1036,  1627,
    1527,  1619,  1038,  1614,  1617,  1618,     0,     0,     0,   661,
     654,   652,     0,    23,     0,  1808,  1808,  1808,  1808,   705,
     683,   707,   685,  1808,  1808,  1808,  1808,   749,   678,   682,
    1808,   610,   735,   733,   736,   734,     0,     0,    45,    43,
      40,    34,    38,    42,    37,    30,    39,     0,    33,    36,
      31,    41,    32,    44,    35,     0,    28,    46,   727,     0,
     658,  1649,     0,  1647,  1605,  1645,  1592,  1593,  1585,  1571,
    1586,     0,     0,     0,  1014,  1402,  1405,     0,     0,     0,
       0,  1426,  1316,  1287,  1672,  1671,  1670,     0,     0,     0,
       0,  1311,     0,  1310,     0,  1312,  1307,  1308,  1309,  1300,
    1296,     0,     0,  1357,     0,     0,     0,  1580,  1577,  1578,
     565,   570,     0,     0,  1808,  1808,   543,   557,   580,   568,
     582,  1808,  1808,   578,   562,   573,   807,   322,   206,     0,
    1166,  1185,   807,     0,  1173,  1166,     0,     0,  1259,     0,
       0,     0,     0,     0,  1431,  1433,  1435,  1472,  1471,  1470,
    1437,  1453,  1261,     0,  1514,     0,  1376,     0,  1379,  1517,
       0,  1383,     0,  1251,     0,     0,  1556,  1554,  1555,  1551,
    1553,  1550,  1552,     0,     0,     0,     0,     0,     0,     0,
       0,  1389,     0,  1392,  1393,     0,  1246,     0,  1240,  1242,
    1749,     0,     0,     0,  1796,     0,     0,  1223,   823,     0,
       0,  1609,  1611,   489,     0,   490,     0,   529,     0,   526,
     523,   494,   488,  1114,  1541,  1113,     0,   170,  1112,     0,
       0,     0,  1115,     0,  1117,  1116,  1110,   448,   449,   453,
     438,     0,   441,   452,     0,   440,     0,     0,    92,     0,
       0,     0,     0,  1274,  1801,  1800,   594,     0,     0,    47,
       0,   676,   675,   674,  1275,     0,     0,   679,  1808,  1808,
     150,   618,   160,   152,   162,   142,   149,  1808,     0,     0,
       0,     0,     0,     0,     0,  1808,     0,   747,   610,     0,
    1775,     0,    92,   531,     0,    64,     0,     0,     0,    77,
       0,    92,    92,   117,   112,  1808,  1808,   102,   749,   853,
     847,   855,   854,   844,   535,   902,     0,     0,  1616,  1615,
    1529,     0,  1605,     0,     0,  1473,     0,  1473,  1473,  1473,
    1473,  1620,     0,     0,     0,     0,     0,     0,  1673,  1674,
    1675,  1676,  1677,  1678,  1623,  1754,   940,   938,   664,   662,
       0,   641,   655,   611,   716,     0,   700,   698,   704,   702,
       0,  1808,     0,  1808,   696,   694,   690,   688,   738,   692,
      23,   728,     0,     0,     0,    26,     0,  1652,     0,  1575,
       0,     0,  1584,  1567,  1583,  1406,     0,  1369,     0,  1315,
    1413,     0,     0,  1668,     0,  1665,  1589,     0,     0,     0,
       0,     0,     0,  1692,  1314,  1313,  1301,  1299,     0,  1360,
       0,  1353,     0,     0,     0,     0,   567,   564,   559,   561,
       0,  1808,  1808,   575,   577,  1808,  1808,     0,     0,  1164,
    1165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1163,     0,     0,  1151,  1152,  1153,  1150,  1155,
    1156,  1157,  1154,  1141,  1132,     0,     0,  1188,     0,  1808,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,  1119,
    1120,     0,  1052,     0,  1263,  1436,     0,  1440,     0,  1453,
    1439,     0,  1401,     0,  1454,  1467,  1464,  1465,  1462,  1469,
    1468,  1463,  1466,     0,     0,     0,     0,     0,     0,  1518,
       0,  1519,     0,     0,     0,     0,  1382,  1253,  1381,  1373,
       0,     0,     0,  1507,  1499,  1499,     0,     0,  1499,  1506,
       0,  1523,  1388,  1390,  1394,  1395,  1248,  1244,   988,     0,
     951,     9,     0,  1216,   824,  1049,     0,     0,  1425,  1595,
    1612,     0,   492,   520,     0,   275,   481,   478,   487,   484,
       0,   443,   442,   472,    95,   474,   348,  1210,     0,     0,
    1792,     0,     0,   956,    48,     0,   601,   603,   598,   725,
     159,   157,     0,  1808,     0,     0,     0,  1808,   155,   144,
       0,   147,   146,     0,   962,   966,   340,     0,  1306,     0,
     749,   746,    23,  1099,     0,  1190,    69,     0,     0,   100,
      67,    92,    75,    81,     0,   119,   115,   741,  1808,   857,
     610,   856,     0,   532,     0,   772,   773,   771,     0,     0,
    1640,     0,     0,     0,  1475,  1476,  1474,     0,  1642,     0,
       0,     0,     0,     0,     0,     0,  1037,  1625,  1626,  1622,
    1624,     0,  1808,   660,   645,   642,     0,   706,   684,   708,
     686,   717,   731,   732,   729,   730,    29,    27,     0,  1646,
    1601,  1572,  1573,  1569,  1575,     0,  1368,  1605,  1371,     0,
    1289,  1284,  1283,  1286,     0,  1601,     0,     0,  1725,  1723,
       0,     0,  1711,  1722,     0,     0,  1724,     0,     0,     0,
       0,     0,  1747,  1721,  1717,     0,  1709,  1712,  1713,  1720,
    1716,  1740,     0,  1702,  1701,  1705,  1707,     0,  1700,     0,
    1703,  1694,  1302,  1297,     0,  1359,     0,     0,  1581,  1579,
     571,   569,   581,   583,   579,     0,     0,   229,  1158,  1159,
    1160,  1162,  1145,  1143,  1142,  1146,  1147,  1144,  1161,  1148,
    1149,  1133,   948,  1168,   945,     0,     0,  1186,     0,  1131,
    1130,  1125,  1123,  1122,  1126,  1124,  1128,  1129,  1121,  1174,
    1378,  1438,  1432,  1434,  1441,  1443,     0,  1448,  1441,     0,
    1446,     0,  1456,  1455,     0,  1457,     0,  1374,  1380,  1521,
    1514,  1384,  1563,  1561,  1562,  1558,  1560,  1557,  1559,  1489,
       0,  1491,     0,     0,     0,     0,  1497,  1501,     0,  1481,
    1396,   987,  1224,  1217,  1213,  1610,     0,  1414,  1415,  1417,
    1420,  1427,     0,     0,  1473,  1597,  1591,  1548,  1546,  1547,
    1543,  1545,  1542,  1544,   493,   491,     0,   525,   524,   172,
     439,     0,     0,    23,     0,     0,   979,     0,    49,   959,
       0,    23,   161,   151,     0,   620,   622,   163,   153,   725,
       0,   339,   540,   748,  1020,     0,     0,    65,     0,    78,
      87,     0,    71,   848,   845,   536,  1808,   917,  1531,     0,
       0,     0,  1641,     0,     0,     0,  1639,     0,     0,     0,
       0,  1621,  1638,     0,   663,   640,   646,   610,  1656,     0,
    1654,     0,     0,  1575,  1575,  1568,  1370,     0,  1372,  1366,
       0,  1288,     0,  1666,     0,  1715,  1714,     0,     0,  1473,
       0,  1473,  1473,  1473,  1473,  1718,     0,     0,  1698,     0,
       0,     0,     0,  1727,  1699,     0,     0,     0,     0,     0,
       0,  1693,     0,  1361,  1364,  1348,  1362,  1365,     0,   818,
     817,   323,   207,   950,   949,   947,     0,  1167,  1053,  1057,
    1059,     0,  1063,     0,  1061,  1065,  1054,  1055,     0,   839,
       0,     0,  1460,     0,  1449,  1452,  1451,  1459,     0,  1441,
       0,     0,  1515,  1520,     0,  1508,  1500,  1484,  1482,     0,
    1485,     0,  1418,     0,  1522,  1421,     0,  1428,  1429,  1600,
    1216,     0,     0,     0,     0,   522,   521,   475,   349,   346,
       0,   977,     0,     0,     0,   958,   726,   139,   619,    23,
     968,  1025,    66,  1191,    83,     0,     0,    76,    87,    87,
    1808,   533,     0,     0,     0,     0,     0,  1637,  1643,  1633,
    1634,  1635,  1636,   665,   718,     0,  1653,  1602,  1595,  1574,
    1570,     0,  1290,     0,  1595,  1738,     0,     0,  1741,     0,
       0,     0,     0,     0,     0,     0,  1710,  1729,  1730,  1726,
    1728,  1708,     0,  1704,  1706,  1695,  1696,  1303,     0,  1349,
    1347,  1582,   946,  1808,  1808,  1067,  1808,  1069,  1808,  1808,
    1056,  1187,  1175,  1442,  1644,  1444,     0,  1447,  1445,  1461,
       0,     0,     0,  1498,  1422,     0,  1416,  1410,  1411,  1613,
       0,  1430,  1424,  1598,  1321,  1317,  1318,  1323,  1322,  1596,
    1216,     0,   351,   978,  1791,     0,     0,     0,     0,     0,
       0,    54,     0,    53,     0,    51,     0,     0,   140,  1029,
    1021,     0,  1027,    87,    92,    87,    88,    82,    72,   846,
       0,     0,  1604,     0,  1681,     0,  1808,    23,  1655,  1594,
    1603,  1294,     0,  1291,  1293,  1590,  1739,     0,     0,  1737,
       0,     0,     0,     0,  1719,  1736,     0,  1363,  1058,  1060,
    1808,  1064,  1808,  1062,  1066,  1450,  1458,  1516,  1493,     0,
    1419,     0,  1409,     0,  1325,  1324,  1320,  1599,  1549,   357,
     355,   347,     0,   353,   359,    56,    61,    58,    60,    57,
      59,    55,     0,    50,     0,   621,   623,  1808,  1026,  1028,
    1192,    84,    79,   534,   918,  1679,  1680,   661,   719,     0,
    1285,  1735,  1742,  1731,  1732,  1733,  1734,     0,  1068,  1070,
    1423,  1412,  1319,  1808,  1808,   352,   354,  1808,    52,     0,
    1030,     0,   666,  1292,  1697,   358,   356,   360,     0,    85,
     960,    89,    91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   552,   553,   554,   555,   711,  1736,  1737,   189,   264,
     190,  1133,  1134,  1624,  1965,  3023,  2463,  2464,  2903,  3024,
    3025,   556,   900,  2497,  2202,  2919,  1563,  2200,  2760,  2501,
    2915,  2201,  2761,  3034,  3141,  3151,  2917,  3154,  1785,  1786,
    1787,  1233,  1854,   557,  1244,   905,  1242,  1571,  1864,  1568,
    1862,  1867,  2206,  1243,  1861,  1572,  2205,   558,    17,    36,
      37,    38,    39,    40,   114,   561,   827,  1501,  1160,  1812,
    1816,  1817,  1813,  1814,  2473,  2477,  2177,  2169,  2168,  2170,
    2173,  1115,  1067,  1767,   562,    83,    84,    19,    62,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     679,  2328,   305,   660,  1684,   332,   333,   229,   287,   280,
     282,   985,   986,   146,   355,   147,   148,   293,   230,   231,
    1487,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   663,   247,   248,   323,   375,   196,    20,    80,   178,
     179,   180,   669,  2327,   181,   251,   240,   326,   327,   328,
     329,  1514,   563,   564,   565,   566,   784,  3012,  2733,  1135,
    3091,  3092,  3093,  3134,  3133,  3137,   567,   568,   569,   570,
     760,  1116,   867,  1202,  1203,  1169,   864,  1170,   762,   763,
     764,   765,   766,   767,   768,  1070,  1117,  2141,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,   716,   769,  1467,  2146,  2148,
    2731,   770,  1437,  2130,  1436,  2129,  1440,  2133,  1438,  2131,
    2113,  2122,   771,   772,   773,   774,  1421,  1422,  1423,  1424,
    1556,   571,  2766,  3040,  2513,   572,   837,  1516,  2185,   115,
     237,   365,  1336,   966,   967,   968,  1333,  1334,  1671,  1672,
    1673,  2024,  2025,  1337,  1338,  1667,  2028,  2020,  1679,  1680,
    2031,  2032,  2325,  2321,  2322,   573,  1177,    85,  1482,  1483,
    1828,   869,   817,   872,   694,   806,   789,   828,  1923,    86,
     695,   689,  1386,  2172,    87,   776,   574,   575,   921,   922,
     576,   577,   578,   579,   929,  2544,   950,  2785,   951,  1601,
     952,  1920,   953,  2251,   954,  1627,   580,  1597,  2250,  2542,
    2541,  3046,   116,    21,   581,  1151,  1488,  1489,  1617,  1282,
    1618,  1619,  2261,  2263,  1936,  1935,  1940,  1934,  1933,  1926,
    1925,  1928,  1927,  1930,  1932,   582,   583,   825,   584,  1278,
     936,  3047,   585,  1210,  2741,  1967,  1968,  1620,  1937,  1870,
    2208,   860,  1187,  1537,  1837,  2186,  1838,  1183,  1536,   586,
     587,   914,  1586,  2517,   588,   589,   590,   591,    22,    66,
      23,    24,    25,   117,   118,   592,   119,    26,   650,    27,
     120,   121,   158,   367,  1342,  2036,  2840,   122,   154,   298,
     593,  2109,    28,    29,    30,    31,    32,    61,    88,   123,
     413,  1351,  2042,   594,   909,  1874,  1575,  1872,  2920,  2508,
    1576,  1871,  2211,  2510,   595,   596,   597,   800,   801,  1246,
     124,   238,   366,   654,   655,   970,  1340,   598,   955,   956,
     599,  1290,   957,   777,    90,    91,    92,    93,  1253,   184,
     138,    94,   700,   135,   192,   193,  1254,  1255,  1881,  1256,
     410,   411,   938,   412,   939,  1593,  1594,  1257,  1258,  1131,
    2643,  2644,  2845,  1395,   815,   816,   600,  1146,  2905,   601,
    2485,   602,  1164,  1165,  1166,  1507,  1505,   603,   604,  1793,
    1823,   605,  1018,  1392,   606,   861,   862,   607,   877,   608,
    1978,   609,  2911,   610,  1841,  3030,  3031,  3032,  3107,   866,
     611,  1259,  1588,  1907,  1908,   612,  1475,   693,  1030,   613,
     614,   615,  2044,  2647,  2856,  2857,  2973,  2974,  2978,  2976,
    2979,  3070,  3072,   616,   617,  1248,  1580,   618,  1250,   885,
     886,   887,  1226,   619,   620,   621,  1549,  1218,   880,   199,
     888,   889,   778,  2045,  2369,  2370,  2353,   719,   720,  2040,
    2354,  2357,   125,   153,   359,   995,  1689,  2371,  2860,  1040,
     622,   878,   126,   150,   356,   992,  1687,  2358,  2858,  2041,
     904,  2192,  2756,  3033,  1221,   623,   624,   625,   626,   627,
     787,  1791,   713,  1741,   628,  2704,   707,   708,  2106,  1371,
     629,   630,  1004,  1005,  1006,  1383,  1726,  1007,  1723,  1380,
    1008,  1698,  1372,  1009,  1010,  1011,  1012,  1692,  1363,   631,
     796,   779,   632,  1314,  1315,  1642,  2572,  2802,  2292,  2569,
    3052,  3053,  1316,  1652,  2306,  1296,  2010,  2613,  2832,  1833,
    2184,  2011,  1317,  1318,  2715,  3005,  3006,  3007,  3086,  1319,
    1320,  1168,   633,   831,   634,   963,  1321,  1322,  2970,  1658,
    1659,  1660,  2013,  2308,  2835,  2836,  1323,  1988,  2286,  2799,
    1373,  1374,  1359,  2065,  1690,  2066,  1375,  2070,  1376,  2093,
    1377,  2094,  2423,  2424,  1693,  1324,  1636,  1637,  1985,  1325,
    3001,  2887,  2997,  1991,  2438,  2707,  2708,  2709,  2995,  2439,
    1992,  2888,  3002,  2053,  2054,  2055,  2056,  2057,  2862,  2664,
    2983,  2058,  2863,  2864,  2397,  2059,  2398,  2060,  2527,  1719,
    1720,  1721,  2693,  1722,  2420,  2414,  2876,  2067,  2837,  2401,
    2605,  2069,  2885,  1909,   780,  1910,  2220,  1058,  2114,  2724,
    2083,  2689,    60,   635,   636,  2564,  2794,  2279,  2793,  1663,
    2018,  2019,  2283,  1979,  1326,  1980,  1999,  2575,  1413,  1975,
    1976,  2716,  2890,  2792,  2568,  1911,  1650,  2110,  2111,  2998,
    2061,  1913,  1914,  2529,  2985,   637,   638,  1629,  1977,  2559,
    2789,  2790,  1293,   639,   782,  1328,  1329,  1645,  2294,  1330,
    1331,  1996,  2244,  2522,   640,   917,  1267,  1268,  1269,  1270,
    1332,  2000,  2611,  2831,  2303,  2608,  2609,  2610,  2607,  2595,
    2596,  2597,  2598,  2599,  2600,  2949,   701,  1590,   703,  1396,
    1915,    64,    49,    78,    75,   642,   891,  1553,  1154,  1212,
     643,   870,   644,  2159,   645,  1735,   705,  1398,   646,   647,
      43,   360,   361,   362,   363,   364,   648
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2559
static const short yypact[] =
{
    1364,  1036, -2559, -2559,   253,   660,   660,   660,   660,   660,
     660,   660,   660,   253,   893, -2559, -2559, -2559,  1555, -2559,
   -2559, -2559,   345, -2559,  1364, -2559, -2559, -2559, -2559, -2559,
    2317, -2559, -2559, -2559, -2559, -2559,   329,   349, -2559,   337,
   -2559, -2559, -2559, -2559, -2559,   253,    93, -2559,  -200, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559,  2570,   222, -2559, -2559, -2559,  2042, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,   253, -2559, -2559,    93,
     -47, -2559,   253,   581,  1555, -2559,  1008, -2559, -2559, -2559,
   -2559,   327,   280, -2559, -2559, -2559,   846,   564,   253, -2559,
   -2559,   922,   253, -2559, -2559,   253,   253, -2559, -2559, -2559,
   -2559,   253,   253, -2559, -2559, -2559, -2559, -2559,  2042, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
    4204,   280, -2559,   908,   423, -2559, -2559,   477, -2559, -2559,
     924,   222,   426, -2559, -2559, -2559, -2559, -2559,  2048, -2559,
     253,   548,   873,   253,  1555, -2559, -2559, -2559,   253, -2559,
   -2559,   455,  1030, -2559, -2559,   577, -2559,   582, -2559,   570,
   -2559, -2559,   615, -2559,   626, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559,   636, -2559, -2559, -2559,   423,  1630,
    1066, -2559,   133, -2559,   423, -2559,   246, -2559, -2559, -2559,
     160, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   455,
   -2559,  1030, -2559, -2559,   672, -2559,   690, -2559,   649, -2559,
   -2559,   719, -2559,   728, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559,   733,  1140,   253,   746, -2559,  1555,  1555,   759,
     253, -2559,   -55, -2559,   559,  1120, -2559,   571,  1135,  1173,
    1199,   253,  1203,  1208,  1212, -2559,   627, -2559,  1002, -2559,
   -2559, -2559, -2559, -2559,   423, -2559,   423,   796,   142, -2559,
   -2559, -2559,  1261, -2559, -2559,  1265, -2559, -2559, -2559, -2559,
   -2559,   -55, -2559, -2559, -2559,  1276,  1292,   222,  1203,  1306,
    1315,   745, -2559,  1291, -2559,   962,   939, -2559,  1016, -2559,
   -2559, -2559,   765, -2559, -2559,  1361, -2559,   985, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,  1135,   985, -2559, -2559, -2559,
   -2559, -2559, -2559,  1001,   189,   241,   219, -2559,  3590, -2559,
   -2559, -2559,  1010,  1436,   244,  1063, -2559, -2559,  1630, -2559,
     423,  1011, -2559, -2559,   841,  1445,  1222,   262,   307,   272,
    1067,   309,  1107, -2559, -2559, -2559,   253, -2559, -2559,   253,
    1145, -2559,  4037,   426,  4928,  2326,  -202,   253,  1500,   499,
   -2559,  1120,  1499, -2559, -2559, -2559, -2559,  1510, -2559,  1512,
   -2559,  1519, -2559,   253, -2559,   253, -2559, -2559,  1203,  1521,
   -2559, -2559, -2559, -2559,   165,   423,  1532,   499,  1146,  1552,
   -2559,  1562, -2559, -2559, -2559,  1577, -2559, -2559, -2559,   991,
    1228,  1621, -2559,   253,  1246, -2559, -2559, -2559,   253,   204,
     253,   253,   204,   204,   915,   253, -2559,   253, -2559, -2559,
     253, -2559,  1005, -2559, -2559, -2559,   204, -2559, -2559, -2559,
   -2559,   253, -2559, -2559, -2559, -2559,    65,    65,  7326, -2559,
   -2559, -2559, -2559, -2559,   204, -2559, -2559,   204, -2559, -2559,
     253, -2559, -2559,   204, -2559, -2559,   854,   204, -2559, -2559,
    7326,   204,   854,   253,   854,   204, -2559, -2559,   108,   204,
     204,   108,   204,   253,   108,   204, -2559,   204,   204,   204,
   -2559, -2559, -2559, -2559,   854,   204, -2559, -2559,   204,    39,
     253, -2559, -2559, -2559, -2559,   204,   921, -2559, -2559, -2559,
     204, -2559,  7939,   854,  7326, -2559,    40,    40,   204, -2559,
   -2559,   947,   854,  1003,  7326,  7326, -2559,  1379,  7326,   204,
      93, -2559,  7326,   204,  7326,   854, -2559,   204,  7326, -2559,
    7326,    65,   253,   204,   253,    40,   204,   253,    40, -2559,
     253,   275, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   252,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   855,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
     862, -2559,   253, -2559,   798, -2559,  1253, -2559, -2559, -2559,
    1327, -2559, -2559,  1264,  1269,  1275,  1278, -2559, -2559,  1017,
    1678,  1304, -2559,   169, -2559,  1385, -2559,  1305,  1309,  1082,
    1316,   253, -2559,   253,  1317, -2559,   755,  1280, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1089,  1185,  1256,
   -2559,  1098, -2559,  1096, -2559,  1709,  -207,   313, -2559, -2559,
   -2559,  1297, -2559,  1188, -2559,  1243,   226, -2559, -2559, -2559,
    1476, -2559,  7326,  7326,  7326, -2559, -2559,  1295,  1206,  1299,
    1303,  1312,  1313,  1319,  1320,  1321,  1323,  1325,  7326,  1260,
    1326,  1328,  1337, -2559,  7326,  7326,  1338,  1341, -2559,  7326,
    1344, -2559,  1345,  1346,  1348,  1356,  1360,  1366,  1370,  1372,
    6428, -2559,    85, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,   881, -2559,  1339, -2559, -2559,
   -2559, -2559, -2559, -2559,   854, -2559, -2559,  1188, -2559,   -51,
   -2559, -2559,  1469, -2559,   175, -2559,  1288, -2559, -2559, -2559,
   -2559,  1733, -2559, -2559,  -158, -2559,  1139, -2559,  1187,  1733,
   -2559,  1214, -2559, -2559,  1392,    87, -2559,  1355, -2559,  1156,
   -2559, -2559,  1388, -2559,   452, -2559,  1161,   480,  -240, -2559,
    1089,  1495, -2559,  7326,  7326, -2559,  1813,   204, -2559, -2559,
   -2559, -2559, -2559,   293,   293,   293, -2559,   293, -2559,   293,
     293,  1226,   -51,  1226,  1226,  1090,  1090,  1226,  1226,   -51,
   -2559,  1819, -2559,    78,  1821, -2559,   -51, -2559,  6701, -2559,
      69,    54, -2559, -2559,  7326, -2559, -2559, -2559, -2559, -2559,
     948, -2559, -2559,   426,  1447,   426,  7326, -2559,    66, -2559,
   -2559,  7326,  1398,  1399,  1402,  1403,  1378,  1404,  1003,  1346,
   -2559,  1492,   964,  1254, -2559,  1266, -2559, -2559, -2559,  1125,
   -2559,  1834, -2559,  1831,   253, -2559,   220,   109,  1271, -2559,
   -2559,  1844, -2559,  1195,  1844,  1849,  1197,  1844,  1849,  7326,
    1844, -2559, -2559,   226,   854, -2559, -2559,  1438,   399, -2559,
   -2559,  1429,   854,  7326,  1432, -2559, -2559,  1842,  1848,  1811,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1147,  1147,
     204,   204,   204,  1241, -2559, -2559,  1779,   862, -2559, -2559,
     800, -2559, -2559, -2559,  1422, -2559, -2559, -2559, -2559,  4204,
    1203, -2559, -2559,  1425, -2559,   354, -2559, -2559, -2559, -2559,
   -2559, -2559,  1555, -2559, -2559,  1555,   696,   186,  1858, -2559,
   -2559,   100,   231,   748,  1880, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559,  1451,  1185,  1096, -2559,   915,   431,   459,
     253, -2559, -2559,   253, -2559,  1310,  1273,  1324,  1470, -2559,
    1485,    73, -2559, -2559, -2559,  6646,  3273,  3273,    40,  7326,
   -2559,    40,    40,    40,    40,  1428,  7326,  1572,  1393,  7326,
    6428,  1489, -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1300,
      40,  1900,  7326,  4868,  6428,  1428,  7326, -2559,  6428,  1903,
     151, -2559, -2559, -2559,  7326, -2559,  7326,  7326,  7326,  7326,
    7326,  7326,  7326,  7326,  7326,  7326,  7326,  7326,  7326,  7326,
    7326,  7326,  7326,  7326,  7326,  7326, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,  7326,  7326, -2559, -2559,
    1497,  7326, -2559,  7326,  1498, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   253,   854,
   -2559,  1307,  1501, -2559, -2559, -2559,   915,  1151, -2559,  1151,
    1003,   108,  7326,  7326,  7326,  1507, -2559, -2559,   854,   854,
   -2559,  1308,  1003,    40,  1267,   253,   423,    59,    39,   854,
   -2559,  1330,  7326,  1588, -2559, -2559,  1389, -2559, -2559,  1936,
   -2559,    71,   226, -2559, -2559,  1932,  1934, -2559, -2559, -2559,
   -2559, -2559, -2559,   318, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,  7939, -2559,  1090,  7326,
     -77, -2559, -2559,  1946, -2559,    40,  1929,  1933, -2559, -2559,
   -2559, -2559, -2559,    83, -2559, -2559, -2559, -2559,  1814, -2559,
    1748, -2559, -2559, -2559,  7326,    65, -2559, -2559,   253,  1945,
      40,    40, -2559,  1382, -2559,    40,  1350,   854, -2559,   253,
     253,  7326,   -62, -2559,  1396, -2559,   255, -2559,  1486, -2559,
    1494,  7326,  1157, -2559, -2559,  1359, -2559,  1974, -2559,  1434,
   -2559,   854, -2559, -2559, -2559,   915,   854,    96, -2559, -2559,
   -2559, -2559,   253,    40,    40,   269,   399,  1835,  1593,   854,
     226, -2559,  1435, -2559, -2559,  1936,  1958,  1589, -2559, -2559,
   -2559, -2559, -2559,  1668,  1668, -2559,   762,  1443, -2559,   253,
   -2559, -2559,  1188,  1188, -2559, -2559, -2559,   253, -2559,   253,
     509,  1188, -2559,   885, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1329, -2559, -2559,
   -2559, -2559, -2559,    89,    89,   665,   982, -2559,   498, -2559,
     800, -2559,  1555,  1964, -2559, -2559,  1964, -2559, -2559, -2559,
   -2559,  1555, -2559, -2559,  1188, -2559,   758, -2559,  1568, -2559,
   -2559,   758, -2559, -2559, -2559,  1573,  1578,   575,  1582,  1583,
    1753, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   253, -2559,
   -2559,   575,  1343, -2559,   755, -2559,  1623,   280,  1395, -2559,
    1003,  1439, -2559, -2559,  1561, -2559, -2559, -2559,  1478, -2559,
     253,   253,   253, -2559, -2559, -2559,   356,  6428,  1635,  1639,
     387,   388,   509,  1643,  5551,  1650,   -74,  1424, -2559, -2559,
     102,  1651, -2559, -2559, -2559,  5587,  2022,  1260,   390,  1654,
    5618, -2559,  1660,  3111,  1662, -2559,  7326,  7326,  7326,  5723,
    7326,  5749,  5872,  6173,  6497,  4391,  6646,  3723,  6767,  6988,
    7532,  7344,  5682,  2948,  3908,  3273,  3273,  2798,  3523,  7781,
    6428,  6214,  6322,  1428,  6428,  6374,  1428,  7326,  1624, -2559,
     253, -2559,  1442, -2559, -2559, -2559, -2559,  1440, -2559,  2055,
    2056, -2559,  2058,  1487,  7326, -2559, -2559,  1450,  2065, -2559,
    1591,  1449,  1849, -2559,  1681,   348, -2559,  1646, -2559, -2559,
    1454,   891,   253, -2559, -2559,  1652,   204,   973,  7326, -2559,
     253,   253,  7326,    56,   -51,  2077,  1530,  2060,  2061, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1655, -2559, -2559,
   -2559,   854,  1557,  6701, -2559, -2559, -2559,  2025,  7326,   426,
    1155, -2559, -2559,  1771,  2091,  2093,   391, -2559,   394,   253,
    1710,  1003, -2559,  7326,  1670,  1674, -2559, -2559,  1747, -2559,
    7326,   -12, -2559,  1511, -2559, -2559,   324, -2559,  7326, -2559,
   -2559,  1488,   908, -2559,  1182,   253,  2096,  7239, -2559, -2559,
    1699, -2559,  1700,  2115, -2559, -2559, -2559,   114, -2559,  1849,
    1849,  1463, -2559,  1574,  1579, -2559, -2559, -2559, -2559,    40,
      40, -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1168, -2559,
   -2559, -2559, -2559,    40,  8160,  2121,  2101, -2559,  1003,   238,
     284,   217,  2030,    14,   947, -2559,   164, -2559, -2559, -2559,
    1703,    63,  1188,   168, -2559,  1515,  1508, -2559, -2559, -2559,
   -2559, -2559,   797, -2559, -2559, -2559, -2559,  1706,  1516,  2131,
   -2559,  1468, -2559, -2559, -2559, -2559,   854,   118, -2559, -2559,
   -2559,  1503,   982, -2559,   253,   253, -2559, -2559,   253,   710,
   -2559, -2559, -2559, -2559,  1713,  1714, -2559,  1683, -2559,  1686,
   -2559,  1717,   397, -2559,  4830,   401,    70,    70,   402, -2559,
      70,  4830, -2559, -2559,  1371,  1371, -2559,  1721, -2559,  1725,
    1728, -2559,  1729,  1731, -2559,  1734, -2559, -2559, -2559,   134,
   -2559, -2559, -2559,   408, -2559, -2559,   413,   253, -2559, -2559,
     459,  2158,  1003,   423,  7326, -2559,  2164, -2559, -2559, -2559,
   -2559,   575, -2559, -2559, -2559, -2559, -2559, -2559,  7552, -2559,
   -2559,  1260,  1260,  2144, -2559,  2151,  1590,   977, -2559,  1206,
    1790, -2559, -2559,  1206, -2559, -2559, -2559,  1791,  1206,  6428,
    6428,  6428,  1206,  6428,  1206,  1206,  1206,  2157,  2159,  2161,
    7326,  1793,  2162,  7326,  1801, -2559,  2189, -2559,  6428, -2559,
    1576,   575,   173, -2559,  1003,  7326,  7326,  7326,  6887,  2191,
     146, -2559, -2559,  1003, -2559,  1580,   253,   253, -2559, -2559,
     253,   253, -2559,  1180, -2559, -2559,   837, -2559,  1581,  7326,
   -2559, -2559, -2559,  2200, -2559, -2559, -2559, -2559, -2559,   253,
    1849, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559,   854, -2559, -2559,  4526, -2559, -2559, -2559,  1885,  2185,
   -2559,    40,  1868,  1878,  1766,  1607,  1884,  1812, -2559, -2559,
   -2559,    -8,  1890, -2559, -2559, -2559, -2559,  1747, -2559, -2559,
   -2559,   136,   561, -2559, -2559, -2559,  1936,  7326,  1820, -2559,
    1786, -2559, -2559, -2559,  7830,  7830, -2559,  1089, -2559, -2559,
    1371, -2559, -2559,  7455,  1822, -2559, -2559,  1823,  1824, -2559,
    1826,  1828,  1836,  1843,   253,    32, -2559,  2258, -2559, -2559,
   -2559, -2559, -2559,  2184, -2559, -2559,   915,   854,   854,   129,
    1625, -2559,  2245,   -51,   253,  1514,  1514,  1514,  1514, -2559,
    2268, -2559,  2278,  1514,  1514,  1514,  1514,  1655, -2559, -2559,
    1514,   105, -2559, -2559, -2559, -2559,  2261,  2275, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,  2285, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,   414, -2559, -2559, -2559,  2266,
   -2559, -2559,  1188, -2559,   509, -2559, -2559, -2559, -2559, -2559,
   -2559,  1707,  1708,   156, -2559,   164, -2559,    70,  1685,   204,
    4830, -2559, -2559,  1875, -2559, -2559, -2559,   253,   253,  7552,
     240, -2559,  7326, -2559,  7326, -2559, -2559, -2559, -2559, -2559,
   -2559,   204,    70, -2559,  1188,  1033,  1687,  1692,  2300, -2559,
    2307, -2559,   854,   253,   916,   916, -2559, -2559,  2308, -2559,
    2308,   736,   736,  2308, -2559, -2559,  2326, -2559, -2559,  2884,
      26, -2559,  2326,  1622, -2559,    26,    70,   758, -2559,  6913,
    1886,  4162,  1886,   152,  2310, -2559, -2559, -2559, -2559, -2559,
   -2559,   753, -2559,  1188,   474,  1924,  2315,  1702, -2559, -2559,
     435, -2559,   575, -2559,   441,   276, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559,  1697,  -126,  2297,  2297,  2298,  2297,  2297,
    2302, -2559,   209, -2559,   758,   253, -2559,   575, -2559, -2559,
    1711,  1003,  2318,   191, -2559,   253,   443, -2559,  7326,  1939,
     121, -2559,   253, -2559,  1715, -2559,  1941, -2559,  2306, -2559,
    1750, -2559, -2559, -2559, -2559, -2559,  1716, -2559, -2559,  1952,
    1953,  1954, -2559,  1955, -2559, -2559, -2559, -2559, -2559, -2559,
    6428,   446, -2559, -2559,   448, -2559,  1959,  7326,  7326,  2327,
     453,  1003,  2345, -2559, -2559, -2559, -2559,  7326,  1785,  2079,
    7326, -2559, -2559, -2559, -2559,  1250,  1965,   837,  1410,  1410,
    2349,   537, -2559,  2352, -2559, -2559, -2559,  1410,   253,  1816,
    1251,  2354,   253,   411,   854,  2127,   454, -2559,  1574,  7326,
   -2559,  2355,  7326, -2559,   854, -2559,  1005,   253,   854, -2559,
    1977,  7326,  7326, -2559, -2559,    -8,  1890, -2559,  1655, -2559,
   -2559,  1238, -2559, -2559,  1797, -2559,   423,  7099,  1362,  1362,
   -2559,  1745,   509,  1981,   308,   520,  7552,   520,   520,   520,
     520,  1756,  7552,  7239,  7552,  7552,  7552,  7552, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
    1943,  1015, -2559, -2559, -2559,  1759, -2559, -2559, -2559, -2559,
      40,  1514,    40,  1514, -2559, -2559, -2559, -2559, -2559, -2559,
     -51, -2559,  1218,  1224,  8160, -2559,  1990,  1956,  7552,  1329,
     217,   217, -2559, -2559, -2559, -2559,   460, -2559,  1913, -2559,
    2378,    70,   -15, -2559,  1761, -2559,  2382,  7652,  7652,  7652,
    7652,    70,    70, -2559, -2559, -2559,  1839, -2559,   465, -2559,
    1763, -2559,   253,   253,  1468,   854, -2559,  2308, -2559, -2559,
     253,   736,   736, -2559, -2559,   736,  2186,  1770,  1773, -2559,
   -2559,    65,    65,    65,  2372,    65,    65,    65,    65,    65,
      65,  2373, -2559,  2377,    65, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559,  2884, -2559,   854,  1787, -2559,  1961,  2186,
    2384, -2559,  2385,  2381,  2386,  2388,  2389,  2391,  1239,  1622,
   -2559,  1961, -2559,   466, -2559, -2559,  1948, -2559,   288,   419,
   -2559,  4830, -2559,  4830, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559,  7830,  1982,  7830,  1991,   558,  7552, -2559,
    2393, -2559,  2108,    70,  1279,    70, -2559, -2559, -2559, -2559,
    1465,  2395,  1465, -2559,  2417,  2417,   470,  2033,  2417, -2559,
    2034, -2559, -2559, -2559,   758, -2559, -2559, -2559, -2559,  1003,
   -2559, -2559,   575,  2160,  1936, -2559,  7552,   184,  1904,     9,
   -2559,  1504,  1260,  1841,  1491, -2559, -2559, -2559, -2559, -2559,
    7326, -2559, -2559, -2559, -2559, -2559,  1968, -2559,   233,  1003,
   -2559,  2420,  2002, -2559, -2559,  2046, -2559, -2559, -2559,  1887,
   -2559, -2559,   253,  1410,   423,  1296,   253,  1410, -2559, -2559,
      40, -2559, -2559,  7326, -2559, -2559, -2559,    40,  2115,  2202,
   -2559, -2559,   -51,  6428,  2428, -2559, -2559,   226,  2020, -2559,
   -2559,  7326, -2559, -2559,  2067, -2559, -2559, -2559,   561, -2559,
    1574, -2559,  7326, -2559,   192, -2559,  1821, -2559,  1465,  7552,
   -2559,   336,  2069,  2450, -2559, -2559, -2559,  7552, -2559,   471,
    7552,  7552,  7552,  7552,   253,   472, -2559, -2559, -2559, -2559,
   -2559,  7326,  2019, -2559,  2117, -2559,  2440, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   253, -2559,
      80, -2559, -2559, -2559,  1329,    70, -2559,   509,  2323,   476,
   -2559, -2559, -2559, -2559,   253,  1910,  7574,  7574, -2559, -2559,
    7678,  2037, -2559, -2559,  2038,  2040, -2559,  2049,  2051,  2052,
    2057,   253,   551, -2559, -2559,   479, -2559, -2559,  2241, -2559,
   -2559, -2559,   485,  2470,  2470, -2559, -2559,   486,  2472,  2471,
   -2559,   120, -2559, -2559,    70, -2559,   128,  1869, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,  2280,  4204, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559,  -163,  2488, -2559,   854,  1805, -2559,  2280, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559,  2310, -2559,  2054,  2184,   202, -2559,  2054,   202,
   -2559,  7830, -2559, -2559,  7552, -2559,   197, -2559, -2559, -2559,
    2041, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
    2105, -2559,  2474,  2111,  2113,  2478, -2559, -2559,  2119, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,   232,  2502, -2559, -2559,
     253,  2146,   253,  1893,   520,  2187, -2559,  2085, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,  1502, -2559, -2559, -2559,
    6428,  2128,    40,   -51,  2147,  1003, -2559,  7326, -2559,  1957,
    2494,   -51, -2559, -2559,   365, -2559, -2559, -2559, -2559,   113,
    2132,  1849, -2559, -2559, -2559,  2134,  2142,  2077,  2092, -2559,
    2190,  2145, -2559, -2559, -2559, -2559,  2296,  2086, -2559,   121,
    1371,  1917, -2559,  1371,  2154,  7552, -2559,  2165,  2167,  2168,
    2170, -2559, -2559,  1973, -2559, -2559, -2559,  1574, -2559,   487,
   -2559,   854,  2005,  1329,  1329, -2559, -2559,  7552, -2559, -2559,
      70, -2559,  2123, -2559,  2005,  1942,  1942,  2172,   308,   520,
    7804,   520,   520,   520,   520,  1944,  7804,  7652, -2559,  7804,
    7804,  7804,  7804, -2559, -2559,    70,  2550,    70,  7652,   204,
    4830, -2559,   854, -2559, -2559,   290, -2559, -2559,   253, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,   854,  2488, -2559, -2559,
   -2559,   854, -2559,   854, -2559, -2559,  1636, -2559,  2328, -2559,
    2329,   209, -2559,   489, -2559, -2559, -2559, -2559,   493,  2054,
    2558,  2542, -2559, -2559,  1949, -2559, -2559, -2559, -2559,  2181,
   -2559,   184, -2559,   184, -2559, -2559,  7552, -2559,  2129, -2559,
    2160,   163,   284,   253,  2551, -2559, -2559, -2559, -2559, -2559,
    1003, -2559,  2193,  8137,  2149, -2559, -2559, -2559,  1962,   -51,
   -2559,    19, -2559, -2559, -2559,  2196,   226, -2559,  2190,  2190,
     561, -2559,   423,  2198,  1966,  1465,  1969, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,   253, -2559,  2115,     9, -2559,
   -2559,   121, -2559,  7538,     9, -2559,  2199,  7804, -2559,   495,
    7804,  7804,  7804,  7804,   253,   500, -2559, -2559, -2559, -2559,
   -2559, -2559,  2169, -2559, -2559, -2559,  2378,  2115,   128, -2559,
   -2559, -2559, -2559,  1446,  1446, -2559,  1446, -2559,  1446,  1446,
   -2559, -2559, -2559, -2559, -2559, -2559,   216, -2559, -2559, -2559,
    7552,  2176,  1465, -2559, -2559,   501, -2559,  2585, -2559, -2559,
    4830, -2559, -2559, -2559, -2559,  2598, -2559,   -84, -2559, -2559,
    2160,  2215,    44, -2559, -2559,   293,   293,   293,   293,   293,
     293, -2559,  2582, -2559,   503, -2559,  7326,  1340, -2559, -2559,
   -2559,    55, -2559,  2190,  7326,  2190,  2077, -2559, -2559, -2559,
    2369,   198, -2559,  1465, -2559,  1465,   114,   -51, -2559, -2559,
   -2559, -2559,   506, -2559, -2559, -2559, -2559,  2221,  7804, -2559,
    2223,  2224,  2225,  2229, -2559, -2559,  7652, -2559, -2559, -2559,
    1446, -2559,  1446, -2559, -2559, -2559, -2559, -2559, -2559,   184,
   -2559,  7552,  2378,   163, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559,   980, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559,  8137, -2559,  2613, -2559, -2559,   702, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,   129, -2559,  7538,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,   514, -2559, -2559,
   -2559, -2559, -2559,   981,   981, -2559, -2559,   981, -2559,  7326,
   -2559,  2230, -2559, -2559, -2559, -2559, -2559, -2559,  2231, -2559,
   -2559,   188, -2559,   226, -2559,  2077
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2559, -2559, -2559, -2559, -2559,   427, -2559,   519,  -183, -2559,
   -2559,  -855,   177, -2559, -2559, -1560, -2559, -2559, -2559, -2559,
    -477, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -1750, -2559, -1512, -2559,
     481, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   760, -2559,
   -2559, -2559, -2559,  1384, -2559,  1058, -2559, -2559,   -60, -2559,
   -2559,  2593, -2559,  2592,  2269, -2559, -2559, -2559, -2559, -2559,
     825,   456, -2559,   822, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,  -121,   976,   355, -2559, -2559,
    2350,   -26, -2559,  2497, -2559, -2559,  2495, -2559,  2432, -2559,
   -2559, -2559,  2361,  2246,  1298,  2357,  -306, -2559, -2559, -2559,
   -2559, -2559,  1301,  -974, -2559, -2559, -2559, -2559, -2559, -2559,
    -141,  2293,  2436,  -193,   883, -2559,  2279,   206, -2559,  2336,
   -2559, -2559, -2559, -2559,  2338, -2559, -2559, -2559, -2559,  -326,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,  2271, -2559,
    2270, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,  -907,
   -2559, -2559,  -435, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
    -125, -2559, -2559,  1113, -2559,  -807,  -851,  2068, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,   876, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,  -454, -2559, -2559, -2559, -2559,
   -2559,  2133, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -1700, -2559, -2559, -2559, -2559, -2559, -2559,  1244, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,  1691, -2559, -2559, -2559, -2559,
     994, -2559, -2559, -2559, -2559, -2559, -1267, -2559, -2559,   984,
   -2559, -2559, -2559, -2559, -2559, -2559,  -801,  -279,   871,  1159,
   -2559,  -482,   791,  -825,  1154, -2559,   730, -2559, -1851,    -4,
    -250, -2559, -2559, -1755,   430,  1094, -2559, -2559,   742,  1397,
   -2559, -2559, -2559, -2559, -2559, -2559,   422, -2559,   130, -2559,
    1400, -2559,  1075, -2559,   757, -2559, -2559, -2559,  -439, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,   879, -2559, -1238,
   -2559,  1064, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,  1525, -2559, -2559,
   -2559, -2559, -2559, -2559,   -65, -2559, -2559, -1485, -2559, -2559,
   -2559, -2559,   677, -2559, -1721, -2559,  -834, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559,  2661, -2559, -2559, -2559,  2568,  2658,  -671, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,    41, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559,  2660, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,  1115, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559,  -428,  2210, -2559,
   -2559, -2559, -2559, -2559,  2043, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559,  2018, -2559, -2559,   -42, -2559, -2559,  1116,
   -2559, -2559, -2559,  -691,  -190,  2433, -2559, -2559, -2559, -2559,
      30, -2559,  -715,  2021,  1421, -2116,   785, -2559,  1122,  1775,
      60,  -136, -2559, -2559, -2559,  1563, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,  1518, -2559,  1077, -2559,
    -378, -2559, -2559, -2559, -2559, -2559, -2559,  -318, -2559, -2559,
   -2559, -2559, -2559, -2559,   482, -2559,  1584,   875, -2559, -2559,
   -2559, -2559, -2559,   351, -2559,  -140, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559,  1833, -2559, -2559, -2559, -2559, -2559, -2559, -2559,  -338,
   -2559,  1496,  1656, -2559, -2559,   358, -2559,  -429, -2559, -2559,
     371,   680, -2559, -2559, -2559, -2559, -2559, -2559, -2559,   172,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2558, -2559,  1718,   938,  -981,
   -2559, -2559, -2559,  1347, -2559, -1347, -2559, -2559, -2559, -1348,
   -2559, -2559, -1335, -2559, -2559, -2559, -2559,  1369, -2559, -2559,
   -2559, -2559, -2559, -2559,   754, -2559, -2559, -2559, -2559, -2559,
   -2559,  -383, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559,  -345, -2559, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
   -2559,   724, -2559, -2559, -2559,  -228, -2559, -2559, -2559, -2559,
   -2559, -2559,   340, -2559, -2559,   697, -2559,  1044, -2559, -2559,
   -2559, -2559, -2559, -2559,  -951, -2559, -2559, -2559, -2559, -1350,
   -2559, -2559, -2559, -2559, -2559, -2559, -1953,    42, -2559, -1743,
     311, -2559, -2559, -1675,   364,   363,   698, -2559, -2360, -2120,
   -2559, -2559,    81,  -235, -2559, -2559, -2559, -2559, -1906, -2559,
   -2559, -2559, -1833, -2559, -2559,  -955, -2559,  -710,  1453,    75,
   -1519,   691, -2559,   -30, -2559, -2559, -2559, -2559,  -689, -2559,
   -1626, -2319, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2086,
   -2559,   439, -2559, -1182, -2559,  1794, -2559, -2559,  -731,  -134,
   -2559, -1513,  -137,   185,   469,  -705, -1388, -1971,   326,  -317,
   -1419, -1822, -2559,   531, -2559, -2559, -2559,  1471,  -510, -2559,
   -2559,  -169,  1808, -2559,   929, -2559, -2559, -1262,   194, -2559,
   -2559, -2559, -1685,   -39, -2559, -2559, -2559,  1505, -2559, -2559,
   -2559, -2559, -2559, -2559, -2559, -2559, -2171,   -57, -2559, -2194,
   -2464, -1562,  -901, -2559, -2559,   -43,  -436,  -403,  -479,  1045,
   -1057,     7,  2228,    74, -2559, -2559, -2559, -2559, -2559,  1620,
   -2559,  -488, -2559, -2559, -2559, -2559, -2559, -2559, -2559, -2559,
    -323,  1517,  2414, -2559, -2559, -2559, -2559
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1805
static const short yytable[] =
{
      42,  1031,   386,  1028,   268,   258,   113,    33,  1016,    57,
      59,  1200,  1173,   883,  1182,  1349,  1815,   823,   721,   284,
    2210,   702,  1382,  1213,  1748,   417,  2075,  1171,  2296,   871,
    1724,    33,  1699,   236,  1725,   256,    97,    70,  1603,  1604,
     131,    74,    77,  1179,  1180,  1360,  1181,  1646,  1184,  1185,
    1059,  1858,  2115,   805,   833,   834,  2174,   925,   113,  1205,
     928,   868,  2218,  2219,  1966,   874,    41,    41,  2488,   140,
     832,  1224,   128,   127,  1205,    77,  1508,  1132,  1280,  2084,
    1496,   338,   670,    41,   291,  2436,    41,   137,  1199,   269,
    2270,   717,  1149,  2691,   144,  1026,   690,    41,   149,   690,
     690,   151,   152,   702,  2602,  2603,  2604,   155,   156,   269,
    1205,  1125,   919,   690,  1982,    97,   299,   300,  1205,   201,
      41,  1755,  1275,  2022,  1405,   127,  2436,    41,  1756,  1264,
    2606,   690,   836,   798,   690,    41,  1285,  1298,   266,  1509,
     690,  1510,  1264,  1511,   690,  1206,   232,   266,   690,   235,
     394,  1207,   690,   129,   239,    41,   690,   690,  2381,   690,
    2355,  2209,   690,    41,   690,   690,   690,  2161,  1912,   688,
     266,  1026,   690,    41,   266,   690, -1803,  2068,  2071,   275,
   -1803,  2071,   690,    41,   269,   276,   277,   690,  1026,  3004,
      41,  2248,   273,  2561,   379,   690,   266,   266,   881,  2768,
      41,   292,  2871,   266,   781,   673,   690,   781,  1591,  1026,
     690,    41,  1989,    41,   690,   728,  2268,   790,  1276,  1015,
     690,   781,   941,   690,   383,   781,   269,  1887,  1888,    41,
     296,    41,   807,   269,  2421,  1888,   302,   781,  2734,   790,
     269,  1887,  1888,    41,    41,   818,   381,   330,   790,   389,
     269,   931,   932,    41,   344,   829,   346,  1026,    41,    41,
     835,    97,  1137,  1138,  2221,    41,  1541,   399,   873,  2829,
     269,   270,   271,    41,  1508,  2668,  1567,   141,  1573,   818,
      41,  2162,  2381,   818,  1595,  1265,  1986,   818,  2297,  2298,
    2299,  2300,  2301,   790,  2381,  2968,   790,    82,  1265,   269,
     931,   932,    41,  2411,   559,   649,  1162,  2560,  2867,   881,
     392,    41,   401,  1612,   405,  2290,  1752,   940,  1023,  1174,
      41,  2530,  2531,  2532,  2533,    82,  1866,   392,  1815,  2112,
   -1803,  1021,  3003,   697,  1432,    41,  3108,  2492,  1612,  2712,
    2091,  2770,  1994,  1519,  1365,    65,   941,  1573,   136,  1612,
    3152, -1803,   409,  2956,    41,   409,   941,  1366,  1547,  1347,
      71,  1205,    82,   409,  2964,    34,   259,   260,   261,   262,
     263,   641,   651,    63,   303,  2843,  2378,  1163,    35,   330,
    1022,   330,  1260,   259,   260,   261,   262,   263,  1236,   414,
    3089,   698,  1205,  1205,  3090,  1205,  1851,   656,  1302,  1205,
    1382,   304,  2047,  1304,  1280,   698,  2047,  2072,  2030,   409,
    1197,  2033,   820,  2095,   686,    82,   691,   692,  2097,  2274,
     699,   704,   652,   706,  2844,    79,   709,    82,  2384,  2385,
    2969,  2386,  2387,  2388,  2389,  2390,  2391,   692,  1995,    63,
    2405,   185,   186,   684,   775,   653,  2405,  1616,  2432,   187,
      41,  2450,  3087,  2450,  3084,  2567,   692,  1515,  2432,  2490,
    1142,  2232,  1198,  2571,    82,  2565,   775,  1143,  2287,   692,
    2614,  2403,  1616,    82,  2223,  2695,  2775,  2775,  2795,   808,
    1393,  2800,    82,  1616,  2817,  1972,    41,  2507,  1574,   134,
    2817,  2825,  2935,  2309,  2986,   824,   826,   698,  2986,  2412,
    3058,   384,   699,  3085,   687,  3058,  3079,    41,  3102,  2989,
     775,  3119,   824,   824,   690,  1753,  1241,   944,  1542,  2817,
     775,   775,  2713,   902,   775,   941,    77,  2068,   775,  1367,
     775,  3153,  2092,  2714,   775,  1388,   775,   737,   920,  2356,
     920,   824,  2382,   920,   824,  1219,   920,  1222,  2769,  1281,
    1406,  2869,   687, -1803,   403,  1410,  1411,  1574,   267,  1408,
    1409,  1583,   741,  1261,  1829,   687,  1570,   341,  2671,   130,
   -1803,  2665,  1428,  2665,    95,  1368,  1191,  1192,  2179,   380,
    2112,  1389,  2694,  1297, -1803,  2698,  2278,   873,  1990,  2834,
     672,  1369,  1640,  1641,   982,   942,  1890,  1035,  1036,  1037,
     821,  1651,    41,  1890,   908,  2735,  3044,  1831,  1208,  1983,
    1890,  1891,    82,  1050,   702,  1361,  2430,  2767,  1891,  1063,
    1064,  1520,  2872,  3114,  1068,  1891,  1310,  1521,  1522,  1523,
    1477,   382,  2379,  2791,   390,  2285,  2455,   690,   690,   690,
     943,   944,  1491,  1150,  1691,  2830,   750,  1524,   969,  1266,
     984,   944,   400,  1344,  2961,  1922, -1803,   943,   933,  2764,
    1378,  2881,  1266,  2740,  2023,  1492,  2409,  2437,  1313,    82,
    2392,  2249,  2222,  3078,  1345,  2937,   823,   991,  2661,   409,
    2495,  2063,    76,  1225,   272,  1873,  1922,  1310,  1512,  2503,
    2504,  1757,    41,   799,   699,  1209,  1513,   402,  2706,   406,
    1472,  2076,  2521,  1024,   272,   822,   822,  2939,  2940,  1027,
    1295,   835,   873,  1478,  2556,  1211,  2967,  2742,   775,   775,
     775,  2747,   822,  1544,  3115,  1497,  3116, -1803, -1803, -1803,
   -1803, -1803,  1781,   702,   775,  1784,  2295,  2407,  1761,   755,
     775,   775,  2725,  1558,  1348,   775,  1743,  2426,  1557,  2151,
    2427,   757,   758,  1560,  1974,  1525,  2317,  2063,  1526,   759,
    2107,   934,  2384,  2385,  1262,  2386,  2387,  2388,  2389,  2390,
    2391,  1876,  2570,  1805,  2063,    41,   949,  1746,  1747,   272,
    1762,  1852,  1527,  1027,  1853,  1599,  1600,  2048,  2077,  2393,
    2908,  2062,  2073,  1175, -1803,  1578,  1552,  1263,  2096,  2486,
    1139,  2284,  1528,  2098,  2275,  2078,  2672,  2528,  2892,  2520,
    2107,   996,   997,  2528,  1912,  2537,  2538,  2539,  2540,  1365,
     944,   272,   132,  2302,    41,  2406,  2941,  2009,   272,   775,
     775,  2408,  1366,  2433,  2519,   272,  2451,  1529,  2452,   998,
     999,  1000,  2178,  2457,  2491,   272,  2394,  1176,  2079,  2665,
    2566,   141,   188,  1353,    82,  2615,  2660,  1530,  1531,  2112,
    2696,  2776,  2782,  1159,   775,   272,  2801,  1647,  1532,  2818,
     775,  1350,  3127,  1533,  1352,  2824,  2826,  2936,  2524,  2987,
    1731,    41,   775,  2988,  2678,  3059,  2681,   775,  2080,   658,
    3065,  3080,  1234,  3103,   272,  2771,  3120,  1631,  1632,   139,
     945,   946,   947,  2947,  3144,  2950,  2951,  2952,  2953,  1156,
    1252,   948,  1534,  2823,  1407,  1353,   143,  2081,    58,  1539,
      41,  1414, -1803,   659,  1425,   775,  2082,   145,  2994,  2469,
    2996,  2400,  1993,   182,   194,    41,  2934,  1430,   195,   775,
     697,  1433,    41,  2673,  1535,  2674,   830,   198,    41,  1439,
    1742,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,
    1460,  1387,   875,  1495,    41,  2395,    18,   233,  1674,  2675,
    2816,  1461,  1462, -1803,  1648,   234,  1464,  1281,  1465,  2759,
     241,  1354,  1365,  1362,  2474,  2525, -1803,  1370,  1379,  1370,
      18,  2119,  2187,  2120,  2392,  1366,   249,  1390,   134,  1780,
     699,   250,  1783,   699,    44,  1394,  1397,  2112,  2807,   706,
     259,   260,   261,   262,   263,  1830,  2923,   252,   881,  1188,
      41,   710,    41,  2034,   824,   775,  1195,   824,   824,   824,
     824,  2396,   775,    82,   253,   775,  2796,  1391,  1666,  2938,
    1368,  1857,  1653,  1354,  1808,   254,   824,  1809,   775, -1803,
     257,  2944,   775,  1402,    34,    35,  1369,  1355,  2254,  2487,
     775,  1157,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   265, -1511,  1649,  2833,  2374,    82,  2562,  2563,
    2112,   285,   775,   775,   698,  2526,   288,   775,  2774,   775,
     698,  2777,  2778,  2779,  2780,    81,  1382,    41,  1971,   286,
    2823,  2823,  1675,  2393,  1468,  1356,  3130,  1929,  1931,  1355,
   -1803,  2415,   699,  2417,  2418,  1941,    82,  2001,   775,   775,
     775,  1676,  1677,  2425,  2924,   687,  2002,  2926,   289,   824,
    1245,  1494,    41,  1498,   824,  2966,  2475,   290,   775,  1639,
    1810,  1678,   294,  1811,  2289,  1643,   295,  2523,  3037,  3038,
    2003,  1357,  1291,  2004,    41,   297,  1473,  1381,    41,  2797,
    2394,  1846,    41,   690,   306,  1612,  2307,  1358,   301,   958,
    1674,  2005,    82,    45,    82,   775,   315,  1633,  3050,   324,
     959,   824,  1605,  1879,  1606,  1607,  1608,    46,  1001,    41,
     697,  1845,    41,  1026,  1016,    41, -1803,  3135, -1803,   813,
     775,  1682,  2102,  1368,  1554,   325,   824,   824,   819,   331,
    1688,   824,    47,  1357,   334,  1564,  1565,   775,   335,  1369,
    2601,  2601,  2601,  2601,  2552,    41,   336,   775,  2948,  1358,
    2554,    41,   960,   340,  2948,  2870,  1820,  2957,  2958,  2959,
    2960,   699,  2277,  2509,  2656,    41,    41,   961,   920,   824,
     824,  2466,  2481,   923,  1612, -1803,   926,    41,    41,    82,
      48,  2942,  2152,  3110,  2153,  3112,   924,   342,  2108,   927,
     274,   343,   930,  2164,   279,  1635,  1002,  2006,  1027,  1027,
    2679,  2434,   347,  1644,  2310,  1644,    41,  1027,   690,  2395,
    1127,  1769,  1770,  1771,    82,  1773,   715,  2745,   348,  1616,
     907,   984,  1654,    41,   911,  3082,  3089, -1803,   915,   690,
    3090, -1803,   351,  1655,  1675,   785,    82,   133,   134,  1003,
      82,   352,  1788,  1808,    82,  2377,  1809,  2380,   794,   354,
    1027,  2007,   357,  1676,  1677,  1656,  2928,   962,  2008,  1299,
   -1803,  3105,  1657,  1370,   353,  2326,  2516,    41,   358,  2193,
    2175,  2359,  3008,  1678,  1379,  2396, -1803,  1370,  2112, -1803,
   -1803,   835,  2236,  2237,   368,  3057,   783,   369,  3060,  3061,
    3062,  3063,   337,  1238,     1,  -266,  1738,  1739,  1740, -1803,
     792,  1128,   873,  1232,   797,    41,    41,    82,  1616, -1803,
       2,     3,  1417,    82,   372,  2551,   811,  1418,  1419,  1420,
     133,   134,   652,  1844, -1803,  3049,  3029,    82,    82,  2217,
     377,  3055,   775,   775,   775,   387,   775,  1609,  1788,     4,
    1610,   388,  1611,  1417,   971,   653, -1803, -1803,  1418,  1810,
    1420,  2702,  1811,   391,  2238,  2239,  2240,  2241,  2242,  2243,
     396,  1300,  1612,   775,   133,   134,  1790,  2999,   395,  1301,
    1654,   397,  1613,  2700,  1612,  1302,  1385,  1303,    41,   398,
     775,  1655,  -266,   892,  1239,   307,     5,     6,  1304,     7,
       8,  1938,   404,  2016,     9,    41,  3122,   407,  1818,  -266,
     316,   964,   965,  1656,   775,   415,  1825,  1826,   775,   824,
    1657,    10,    11,  2245,  1614,  2727,  1305,  2728,  1615,  2601,
    2601,   657,  3111,  2601,  3054,   662,  2895,  3094,  2896,    12,
    1189,  1190,  1306,   893,  1193,  1194,   664,  1307,   665,   775,
     718,   718,  -266,  2103,   775,   666,  3029,   671, -1803,  1308,
   -1803, -1803, -1803,   674, -1803,  1855,  1309, -1803, -1803,   775,
    1214,  1215,  1216,  1217,  3008,  2121,   775,  1474,    82,  1474,
     894,  3076,   308, -1803,   775,   676, -1803,   696,   677, -1803,
    1880,  1252,  -266,  1905,  1032,  1033,  1034,   317,   678,   309,
     714,  2428,  2594,  2594,  2594,  2594,  1616,  1415,  1416,    13,
   -1803,     2,     3,   680,   318,   824,   824,  3094,  1616,  2866,
     681,  -266,  2866,  1582,   134,  1661,  1662,   786,   682,   824,
    -266,  1821,  1822,  1669,  1670,  1051,   683,  1605,   974,  1606,
    1607,  1608,   310,   803,   804,   718,   685,  2754,  1027,   810,
     979,  2458,   812,   973, -1803,   935, -1803,   319,   259,   260,
     261,   262,   263,  2842,   975,  2140,  2753,  2017,  2140,   976,
     690, -1803,  2999,   945,   946,   977,   690,   895,   978, -1803,
    2029,  2029,   311, -1803,  2029,  2805,  2806,     5,     6, -1803,
       7,     8, -1803,   980, -1803,     9,   983,   320,   690,  2667,
    1905,  2670,  2064,  2064,   981,   987,  2064,  1905, -1803,   988,
    3054,   312,    10,    11, -1803,   989,   990,   994,  1014,  1013,
     313,  1310,  1052,   134,  1017,  1019,   321,  1020,  1311,    14,
      12,  1029,  1025,  2099,  1038,   322,  1394,  2710,  1041,  1053,
     775,  1039,  1042,   835,  1136,   735,  2076,  1370,  1141,   873,
    1312,  1043,  1044,   896,  1905,  1313,  1140,   736,  1045,  1046,
    1047,  2523,  1048,  2601,  1049,  1060,  1144,  1061,  1129,  2601,
    2601,   873,  2601,  2601,  2601,  2601,  1062,  1065,    15,  2849,
    1066,  2601,  1054,  1069,  1071,  1072,   775,  1073,  2547,   775,
    2549,  2360,  2757, -1803,   897,  1074, -1803,  1370, -1803,  1075,
      13,   775,   775,   775,   775,  1076,  2064,  2361,  2362,  1077,
      16,  1078,  2166,  1818,  1145,  2363,  2171,  2171, -1803,  1147,
     935,  1148,  1055,  1152,  1153,   775,  1702,  1155, -1803,  1158,
    1167,  1172,  1186,  2077,  1196,  2183,  1199,  1228,  1229,  1220,
    2682,  1230,  1231,  1235,  2850,  1237,  2851, -1803, -1803,  2364,
    2078,  1056,  1249,  1240,  1241,  1251,  1271,   824,  2365,  1272,
    1057,  2852,   898,  1273,  1205,  1274,  1126,  1279,  1283,  2853,
   -1803,  1286,  1609,  2854, -1803,  1610,  2848,  1611,  1287,  2717,
    1335,  2594,  2594,   775,  1288,  2594,  1289,  2366,  2899,  1343,
    1905,  1905,  1346,  2079,  1364,  1384,  2907,  1612,  2855,  1905,
    2601,   752,  1401,  2601,  2601,  2601,  2601,  1613,  1412,  1403,
    2231,  1016,  2628,  2629,  2630,  1400,  2632,  2633,  2634,  2635,
    2636,  2637,   699,  1402,  1404,  2640,   899,  2683,  1426,  2701,
    2255,  1429,  2367,  2080,  1434,  1427,  1463,  1466,  1211,  2866,
    1471,  2123,  1470,  1490,  2684,  2125,  1484,  1504,  2849,  1614,
    2128,  1508, -1803,  1615,  2132,  1506,  2134,  2135,  2136,  2736,
    1517,  1543,  2081,  1518,  1502,  1545,  2718,   690,   690,  1546,
     754,  2082,  2821,  2822,  2368,  1550,  1548,  1577,  1027,   756,
    1555,  1559,  1561,  2719,  1570,  1579,   649,  2685,  1584,  1585,
    1587,  1623,   649,  2064,  1625,  1281,  1905,  1626,  1628,  1634,
    1683,    16,  2749,  2293,  1644,  1905,  2710,  1694,   775,  2751,
     775,  2601,  1696,  2850,  2965,  2851,  1727,  1697,  2064,  2601,
    1027,  1700,  1701,  1729,  1730,  1732,  2720,  2686,  1733,  2029,
    2852,  1616,  1788,  1788,  1734,  1744,  2514,   935,  2853,  1745,
     835,   835,  2854,  1749,  2238,  2239,  2240,  2241,  2242,  2243,
    1751,  1758,  2064,   651,  1763,  1905,  2687,  1905,  1760,   651,
    1765,  1703,  1768,  1789,  3028,  2688,  2721,  2855,  1792,  2064,
    1795,  1796,  2422,  1797,  2493,  1794,  1798,  1788,  1370,  1800,
    1801,  1804,     1,  1802,  1803,  1806,  1788,  1788,  1807,    89,
     203,  1819,  1280,  1832,  1836,  2722,  1834,  1835,     2,     3,
    1843,  1379,  1840,  1370,  2723, -1803,  1849,   102,  1850,  1859,
    1856,  1738,   103,  1860,   775,  2594,  1863,  1869,  2440,  1704,
    1883,  2594,  2594,  1877,  2594,  2594,  2594,  2594,  1916,  1917,
    1918,  1705,   948,  2594,  1922,  1924,  1969,  1970,   204,   205,
    1981,  1706,  1987,  1998,  1997,  2012,  2015,   206,  2037,  2038,
    2014,  2026,  2039,   775,   775,  2043,  2046,   104,   105,  1707,
    2085,   183,   191,   775,  2086,   106,   775,  2087,  2088,  1708,
    2089,  2467,  1709,  2090,     5,     6,  2101,     7,     8,  2105,
    2116,  2710,     9,  2710,  1818,  1710,  2482,  2117,  2484,  2118,
    2124,  2127,  2137,  2142,  2138,   775,  2139,  2143,   775,    10,
      11,  2145,  3118,  2499,  2147,  2149,  2160,   775,   775,  2165,
    2180,  3036,  2234,  2235,  2236,  2237,   191,    12,  2182,  2190,
    2191,  2194,   191,   775,  3095,  3096,  3097,  3098,  3099,  3100,
     699,  2195,  1905,  2196,  1711,  2901,  2197,  2198,  1905,  1905,
    1905,  1905,  1905,  1905,    50,    51,    52,    53,    54,    55,
      56,  2199,  2594,  2216,  2215,  2594,  2594,  2594,  2594, -1803,
    2898,  2224,  2225,  2226,  1712,  2227,   824,  2228,   824,  2819,
    2820,  2821,  2822,  2233,  1713,  2229,   935,  2593,  2593,  2593,
    2593,  2253,  2230,  2260,  1905,   947,  2238,  2239,  2240,  2241,
    2242,  2243,   191,  2262,   191,  1714,  2271,  2064,  1715,  2272,
    1716,  2744,  2276,  2592,  2592,  2592,  2592,  2064,  2064,  2273,
    2841,  2288,  2280,  2281,  2291,  2314,  2312,   207,  2617,  2618,
    2017,  2313,  2315,  2320,  2402,  2376,  2621,  2383,  1717,   718,
    2403,  2404,  2410,  2413,  2416,  2730,  2429,  1718,  2419,  2435,
   -1748,  2442,  2443,  2238,  2239,  2240,  2241,  2242,  2243,  2444,
    2441,  2445,  2446,  2447,  2448,  2449,   208,     1,  2456,  2453,
    2459,  2461,  2462,  2594,  2472,  2468,     1,  2476,   191,  2483,
    2494,  2594,  2480,     2,     3,   209, -1803,  2502,  2512,  2710,
    2518,  2520,     2,     3,   935,  2534,  1788,  1905,  2546,  1905,
    2557,   210,  2543,  2567,  2381,  2558,  2574,  2436,  2616,  1905,
    3013,  1905,  2612,  2626,  1905, -1803,  2627,  2631,  2638,  2064,
    2680,  2064,  2639,  1354,   211,  2645,  2646,  2651,   107,  2649,
    2650,  2666,  2652,   191,  2653,  2654,   212,  2655,  2222,  2676,
    2669,  2690,  2692,  2697,  2699,  2737,   213,  2703,  1370,  1990,
    2726,  2738,  1905,  1027,   108,  2732,  2739,  2740,  3155,     5,
       6,  2752,     7,     8,   214,  2758,   775,     9,     5,     6,
     712,     7,     8,  2755,   215,  2773,     9,  2762, -1803,  2772,
     942,  2787,  2798,  2791,    10,    11,  2808,  2809,  2171,  2810,
     216,  2746,  2171,    10,    11,  2817,   824,  2827,  2811,   775,
    2812,  2813,    12,   824,   788,  2828,  2814,  1341,  2838,  2839,
     793,    12,   795,  2846,  2861,  2874,   802,   775,  2400,   802,
    2875,  2877,   802,  2878,  2879,   109,   690,  2883,   775,  2880,
     217,  2891,   814,  2886,  2894,  1905,   761,  2893,  2897,  2900,
    2906,  2914,  2910,  1905,  2912,  2904,  1905,  1905,  1905,  1905,
    2781,   863,  2913,  2916,   218,  2918, -1803,   775,   791,   876,
     879,   882,  2925,  2922,  2927,   903,  2593,  2593,  2933,   219,
    2593,  2437,  2943,   913,  2788,  2929,   220,  2930,  2931,   221,
    2932,  2064,  2945,  2954,  2962,  2990,  2981,  2982,  2991,   937,
    2293,  2993,  2592,  2592,  2992,  3000,  2592,  3011,  3026,   873,
     222,  3027,   865,   223,  3014,   224,  3035,  2815,  3042,  3056,
    3081,  3043,   884,   890,  3045,    81,   906,    41,  3066,   110,
     910,  3077,   912,  3083,   225,  3088,   916,  3101,   918,  3113,
    2064,  3121,  1635,  3123,  3124,  3125,     2,     3,  3139,  3126,
    3149,  3150,   226,  2498,  2431,  3138,  1569,  2207,  2454,  1868,
      72,    73,  2167,   560,  2479,  2176,  2865,   349,   197,  2865,
     202,   281,   345,   675,  1685,   350,   408,   283,  1686,  2126,
     661,  2729,   376,   374,   667,   668,  1842,  3136,  1339,  2144,
     901,  1754,   699,  2035,   227,   699,  2027,  1905,  2156,  1598,
    1905,  1827,    14,  2545,  2786,  1602,  1921,  2252,  3142,   111,
    2163,  1906,  1939,  1499,  2909,    67,   157,   112,    68,  2859,
      69,  1875,     5,     6,   809,     7,     8,   972,  1878,   339,
       9,  1622,  1027,  2247,   993,  2847,  2884,  1882,  2889,  1277,
    2972,  1984,  1486,  3109,  1538,  2536,  2980,    10,    11,  1223,
    1551,    15,  2659,  1476,  2641,  2372,  1435,  2658,   824,  2150,
    1695,  1728,  3041,   775,   937,    12,  3143,  2282,  3132,  2311,
    3067,  1399,  2677,  2373,  2074,  2662,  2663,  2375,  2882,  2711,
    2868,  3075,  1638,  2619,  2399,  2873,  3010,  1327,  3009,    82,
    2804,  2573,  2705,  2535,  3131,  1630,  3048,  1294,  2803,  2946,
    2963,  1905,  1596,  2955,  1493,  2100,   416,     0,     0,     0,
    2593,     0,     0,     0,     0,     0,  2593,  2593,  1906,  2593,
    2593,  2593,  2593,  1905,     0,  1906,  2064,     0,  2593,     0,
       0,     0,  1130,     0,   699,    13,  2592,     0,     0,     0,
       0,     0,  2592,  2592,     0,  2592,  2592,  2592,  2592,  1093,
    1094,  2064,     0,  2064,  2592,     0,  1905,     0,     0,     0,
       0,  2984,     0,  1095,  2971,     0,     0,     0,     0,     0,
       0,     0,  1906,     0,     0,  1161,     0,     0,     0,     0,
    1664,  1665,     0,     0,     0,     0,     0,  1681,     0,     0,
       0,  1178,  1178,  1178,     0,  1178,     0,  1178,  1178,     0,
       0,     0,     0,    89,    89,     0,     0,  1027,     0,  1027,
       0,     0,  1905,     0,     0,     0,     0,  2064,     0,  2889,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,  1103,  1104,  1788,
       0,     0,     0,     0,     0,     0,   882,  2593,     0,     0,
    2593,  2593,  2593,  2593,     0,     0,     0,  1247,     0,     0,
       0,  2788,     0,     0,     0,     0,  1204,     0,     0,  1905,
       0,     0,   865,  2592,     0,     0,  2592,  2592,  2592,  2592,
    3064,   937,  1130,     0,   884,     0,  2865,  2329,  2330,  1227,
    1284,  2331,  2332,  2333,  1635,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,  1292,  1292,  1906,  1906,
       0,     0,   699,  1095,     0,     0,  1905,  1906,     0,     0,
       0,     0,     0,     0,     0,     0,  1905,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   775,  3106,     0,     0,     0,     0,  2593,     0,
     775,     0,     0,     0,     0,     0,  2593,     0,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,  1105,     0,     0,  1106,
       0,     0,     0,     0,  2592,     0,  1102,  1103,  1104,     0,
    2334,     0,  2592,     0,     0,     0,     0,  2335,     0,     0,
    1848,     0,     0,     0,     0,  1027,     0,  1905,     0,  2064,
       0,     0,     0,     0,  1906,     0,     0,     0,     0,     0,
       0,     0,     0,  1906,     0,     0,     0,     0,     0,     0,
       0,  2336,     0,     0,     0,     0,     0,     0,     0,     0,
    2337,     0,     0,     0,  1919,  1905,  1766,  1079,  1080,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,   775,     0,     0,     0,  2338,
    2339,     0,     0,  1906,     0,  1906,  1095,  1469,     0,     0,
       0,     0,     0,     0,     0,    89,     0,    89,   882,   802,
       0,     0,     0,     0,     0,     0,  1485,   814,  1107,     0,
     882,     0,     0,     0,   191,     0,     0,  1500,     0,     0,
       0,     0,     0,  1108,  2340,     0,  1906,  1109,     0,     0,
     937,     0,     0,     0,     0,     0,  1105,     0,     0,  1106,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
    1479,  1480,  1481,     0,     0,     0,    89,     0,     0,  1102,
    1103,  1104,     0,     0,     0,  1110,  2341,     0,     0,     0,
    1503,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,  1562,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1540,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,  1589,
       0,     0,  2342,     0,  1592,     0,     0,     0,     0,     0,
       0,     0,   884,  1092,  1093,  1094,     0,  1621,   937,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1095,  1566,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,  1581,
    1906,     0,     0,     0,     0,     0,  1906,  1906,  1906,  1906,
    1906,  1906,     0,  1108,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1668,  1113,     0,     0,     0,     0,  1105,
       0,     0,  1106,     0,     0,  1096,  1097,  1098,  1099,  1100,
    1101,     0,  1906,     0,     0,  1110,     0,     0,  2203,  2204,
       0,  1102,  1103,  1104,     0,     0,     0,     0,     0,  2213,
       0,  1906,  1906,  1906,  1906,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,     0,   882,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,     0,  1112,     0,     0,   718,   718,   718,     0,   718,
     718,   718,   718,   718,   718,     0,     0,     0,   718,     0,
       0,     0,  2256,  2257,  2258,  2259,     0,     0,     0,     0,
    2264,  2265,  2266,  2267,     0,     0,     0,  2269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1906,     0,  1906,     0,     0,
       0,  1107,     0,     0,     0,     0,     0,  1906,     0,  1906,
       0,     0,  1906,     0,     0,     0,  1108,     0,     0,     0,
    1109,     0,     0,     0,  1113,     0,     0,     0,     0,     0,
       0,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  1105,     0,     0,  1106,     0,     0,     0,     0,     0,
    1906,     0,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,  2318,  2319,     0,     0,  1094,     0,     0,  2323,  2324,
       0,     0,  1799,     0,     0,     0,     0,     0,  1095,  1839,
       0,     0,     0,     0,     0,     0,  1111,     0,  1847,     0,
    1114,     0,     0,     0,     0,     0,  1824,     0,     0,   882,
    1481,     0,     0,     0,     0,  1112,     0,     0,     0,     0,
       0,   935,     0,     0,     0,   385,     0,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1204,     0,  1906,     0,  1096,  1097,  1098,  1099,  1100,
    1101,  1906,     0,     0,  1906,  1906,  1906,  1906,     0,     0,
       0,  1102,  1103,  1104,     0,     0,     0,     0,  1865,     0,
       0,     0,     0,  1107,     0,     0,   882,  1973,   882,     0,
       0,     0,   876,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,  1109,     0,     0,     0,     0,  1113,     0,     0,
    1906,  1906,     0,     0,  1906,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2021,  2470,  2471,     0,     0,     0,
       0,     0,     0,     0,  2478,     0,     0,     0,     0,     0,
    1110,     0,  2489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2505,  2506,     0,     0,     0,     0,  1111,     0,
       0,     0,     0,  1114,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,  1112,     0,     0,
     882,   191,     0,     0,     0,     0,     0,     0,  1095,     0,
    1906,     0,     0,  1906,     0,  1906,     0,     0,  1906,     0,
       0,  1105,     0,     0,  1106,     0,     0,     0,  2548,     0,
    2550,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2104,     0,     0,     0,     0,     0,     0,     0,
     882,     0,   882,     0,     0,  1096,  1097,  1098,  1099,  1100,
    1101,   882,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,  1102,  1103,  1104,     0,     0,     0,     0,  2622,  2623,
       0,     0,  2624,  2625,     0,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2188,
       0,     0,     0,  2154,  2155,  1481,  2158,     0,     0,  1906,
       0,     0,     0,     0,     0,     0,  2648,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2181,   160,  2212,
       0,  1906,     0,  1107,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,  1906,     0,     0,   161,  1108,     0,
    1906,  1906,  1109,  1906,  1906,  1906,  1906,     0,     0,     0,
       0,     0,  1906,     0,  1906,     0,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,  2246,  1592,     0,     0,     0,
       0,     0,     0,  1095,     0,  2214,   162,     0,     0,     0,
    1110,     0,     0,     0,     0,  1906,     0,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,  1105,     0,     0,  1106,     0,     0,     0,  1111,     0,
    1906,     0,     0,     0,     0,     0,   165,     0,     0,     0,
    2743,     0,     0,     0,  2748,     0,   166,  1112,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
     935,     0,   167,     0,     0,     0,  1102,  1103,  1104,     0,
       0,     0,     0,     0,     0,  2763,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1906,     0,     0,
    2316,  1906,     0,     0,  1906,  1906,  1906,  1906,     0,     0,
       0,     0,   168,     0,     0,     0,     0,     0,     0,  2784,
   -1804,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2304, -1804,  2305, -1804, -1804, -1804,   169,     0,     0,  1113,
    1906,     0,     0,     0,  1906,     0,     0,     0,     0,     0,
       0,   170,     0,  1107,  1906,     0,     0,     0,   171, -1804,
       0,   172,     0,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,   882,
       0,     0,   173,     0,     0,   174,     0,   175, -1804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,   176,     0,     0,     0,
    1110,     0,  1906,     0,     0,     0,  1105,     0,     0,  1106,
    1906,     0,     0,  1777,   177,     0,     0,     0,     0,   882,
   -1804,  2049,     0,     0,     0,  1906,     0,     0,  1111,     0,
    1884,  1885,     0,  1886,     0,     0,   269,  1887,  1888,    41,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,     0,
   -1804,     0,  1592, -1804,     0,     0,     0,     0,     0,     0,
       0,     0,  2496,  1906,   712,     0,  2500,     0,     0,     0,
       0,     0,     0,     0,     0,  2460,  1889, -1804,  2465,  2511,
       0,     0,     0,     0,   191, -1804,     0, -1804,     0,     0,
       0,     0,     0,     0,     0,     0, -1804,   935,     0,     0,
       0,     0, -1804,     0,     0,     0,     0,     0,     0,     0,
   -1804,     0,     0,     0, -1804,     0,     0,     0,     0,     0,
   -1804,     0,     0,     0, -1804, -1804, -1804, -1804,  1107,  1113,
       0,     0,     0,  2921,     0,   865,     0,     0,     0, -1804,
    2553,  2555,     0,  1108,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0, -1804,     0,     0, -1804,
       0, -1804,     0,     0,     0,     0,     0,     0, -1804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -1804,     0,  2620,     0,  1110,     0,     0,     0,     0,
       0, -1804,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,   698,     0,     0,     0,     0,     0,     0,     0,     0,
   -1804, -1804,     0,  1111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2642,     0, -1804,     0,     0,     0,     0,
       0,     0,  1112, -1804,     0,     0,  2657, -1804,     0,     0,
       0,     0,     0,     0,     0,     0, -1804, -1804, -1804,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3039,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   882,     0,     0,
       0,     0,     0,     0,     0,  2050,     0,     0,     0,     0,
       0,     0,     0,   159,  1113, -1804,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1804,   882,     0,     0,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
    3068,  3069,   191,  3071,     0,  3073,  3074,     0,     0,  1102,
    1103,  1104,   160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   937,     0, -1804,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,  2189,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,  2750,     0,     0,     0,     0,  1890,     0,     0,     0,
     162,  1095,     0,  3117,     0,     0,     0,     0,     0,     0,
       0,  1891,   163,     0,     0,     0,     0,     0,     0, -1804,
    2765,     0,   164,     0,     0,     0,     0,  3128,  1892,  3129,
       0,  2051,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,  2052,  1894,     0,     0,     0,     0,  2783,
     166,     0,     0,     0,     0, -1804,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,  3140,     0,   167,     0,     0,     0,
       0,     0,  2222,     0,  1102,  1103,  1104,     0,     0,  1105,
       0,     0,  1106,     0,     0,  1896,     0,     0,     0,     0,
    3145,  3146,     0,     0,  3147,     0,     0,  1897,     0,     0,
       0, -1804,     0,  2642,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0, -1804, -1804, -1804, -1804, -1804,
   -1804, -1804,     0, -1804, -1804,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,     0,     0,     0,     0,  1898,
   -1804,     0,     0,     0,     0,   170,     0,     0,     0,     0,
       0,     0,   171,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,  1899,   174,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
    1900,     0,     0,   882,     0,     0,     0,     0,     0,     0,
     176,  1107,  1901,  1902,     0,     0,     0,     0,     0,     0,
    1903,     0,     0,  1904,  1105,     0,  1108,  1106,   177,     0,
    1109,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2902,     0,     0,     0,  1592,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2049,
       0,     0,     0,     0,     0,     0,  1111,     0,  1884,  1885,
    1592,  1886,     0,     0,   269,  1887,  1888,    41,     0,     0,
       0,     0,     0,     0,  2642,  1112,     0,     0,     0,  2975,
       0,  2977,     0,     0,  1079,  1080,  1081,     0,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,  1889,     0,  1107,     0,     0,     0,
       0,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
     882,  1108,     0,     0,     0,  1109,     0,     0,   882,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   937,     0,     0,     0,     0,     0,
     191,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
       0,     0,     0,  1110,     0,     0,     0,     0,     1,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
       0,     0,     0,   418,     2,     3,  1102,  1103,  1104,     0,
       0,  1111,   419,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   420,   421,     0,   422,     0,     0,
    1112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,  1114,     0,     0,     0,     0,   424,   698,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   425,
     426,   427,     0,  1178,  1178,  1178,  1178,  1178,  1178,     0,
       0,     0,     0,     0,     0,   428,     0,   429,   430,   431,
       5,     6,   432,     7,     8,   433,     0,   434,     9,   435,
     436,     0,     0,     0,     0,     0,   437,     0,     0,   438,
       0,   439,   440,   441,     0,    10,    11,     0,     0,     0,
       0,   442,  1113,   443,   444,     0,   445,     0,   446,   447,
       0,     0,   448,    12,  3104,     0,   449,   450,   451,     0,
     452,   453,     0,     0,     0,   454,   455,     0,   456,     0,
       0,     0,   457,     0,   458,   459,  1105,     0,     0,  1106,
     460,     0,     0,  2050,   461,     0,     0,   462,     0,   463,
       0,   464,     0,   465,     0,   466,   467,     0,   468,   469,
     470,     0,     0,     0,   471,     0,   472,   473,  1114,   474,
       0,     0,     0,     0,     0,     0,     0,   475,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     477,   937,     0,   478,   479,     0,     0,   480,   481,     0,
       0,   482,   483,     0,     0,     0,     0,     0,     0,     0,
     484,   485,   486,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,   489,   490,  3148,   491,     0,
       0,     0,   492,   493,     0,     0,     0,   494,     0,     0,
       0,     0,     0,     0,  1890,   495,     0,     0,     0,     0,
       0,     0,     0,   496,   497,   498,     0,     0,  1107,  1891,
       0,   499,   500,     0,     0,     0,     0,   501,     0,     0,
     502,     0,     0,  1108,   503,   504,  1892,  1109,  1431,  2051,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,  2052,  1894,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,  1110,     0,   508,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1896,     0,     0,     0,     0,     0,     0,
     108,     0,     0,  1111,     0,  1897,     0,   509,     0,   510,
     511,     0,     0,     0,     0,     0,     0,     0,   512,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1898,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   514,     0,
       0,     0,   515,     0,     0,     0,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1899,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1900,     0,
     517,   518,     0,     0,  1113,   519,     0,     0,     0,     0,
    1901,  1902,     0,     0,     0,     0,     0,   520,  1903,     0,
       0,  1904,     0,   521,   522,   523,   524,     0,     0,   272,
     525,     0,     0,     0,   526,     0,     0,     0,     0,     0,
       0,   527,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   529,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   531,     0,   532,     0,
    1114,   533,     0,     0,     0,     0,     0,   534,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   535,     0,     0,   536,     0,     0,     0,
       0,   537,     0,     0,   538,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,   541,  1079,  1080,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,   542,
     543,   544,   545,   546,   547,   548,  1095,     0,   549,     0,
     550,     0,   551,  1079,  1080,  1081,     0,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,     0,  1079,  1080,  1081,     0,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,     0,     0,  1095,     0,     0,     0,     0,     0,  1102,
    1103,  1104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,  1103,  1104,  1079,
    1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1079,  1080,  1081,  1095,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,     0,  1095,     0,     0,     0,     0,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,     0,  1105,
       0,     0,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1102,  1103,  1104,     0,  1105,     0,     0,  1106,     0,
       0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,  1103,  1104,
       0,     0,     0,     0,     0,     0,  1105,     0,     0,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,  1079,  1080,
    1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,  1106,     0,     0,  1108,     0,     0,     0,
    1109,  1750,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,  1105,  1108,     0,  1106,     0,  1109,  1759,  1110,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,     0,     0,     0,     0,     0,  1105,     0,     0,
    1106,     0,     0,  1108,     0,     0,  1111,  1109,  1764,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1111,     0,     0,  1110,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,  1108,     0,     0,
       0,  1109,     0,  1111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,  1107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1113,  1108,  1110,
       0,     0,  1109,  1772,     0,     0,     0,     0,     0,  1107,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1108,     0,     0,  1111,  1109,  1774,
       0,     0,     0,  1113,     0,     0,     0,     0,     0,     0,
    1110,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,  1113,     0,  1110,     0,  1111,  1079,
    1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,  1112,     0,     0,
       0,     0,     0,     0,  1111,     0,     0,     0,  1095,  1114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1079,  1080,  1081,  1112,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,  1113,     0,
    1114,     0,  1107,     0,     0,     0,     0,     0,     0,  1095,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
       0,  1109,  1775,     0,     0,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,     0,  1114,  1113,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,  1103,  1104,     0,     0,  1111,  1079,  1080,
    1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1114,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,     0,     0,     0,     0,     0,     0,     0,     0,
    1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1095,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,  1105,     0,     0,  1106,     0,     0,     0,  1113,     0,
    1102,  1103,  1104,     0,  1079,  1080,  1081,     0,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1105,  1095,     0,  1106,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,  1103,  1104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1080,  1081,     0,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,     0,  1102,  1103,  1104,     0,
       0,     0,     0,  1107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,  1109,  1776,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,  1108,
    1110,     0,     0,  1109,     0,  1102,  1103,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1105,     0,     0,  1106,     0,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1110,     0,     0,     0,     0,     0,  1112,     0,     0,
       0,     0,     0,     0,  1778,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1111,
       0,     0,     0,     0,     0,     0,  1105,     0,     0,  1106,
       0,  1095,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,  1107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
     722,  1109,     0,     0,     0,     0,     0,     0,     0,   723,
     724,     0,     0,     0,     0,   269,   725,   726,    41,  1113,
       0,     0,     0,     0,     0,     0,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,  1107,  1105,     0,     0,  1106,  1110,
       0,     0,     0,     0,  1102,  1103,  1104,     0,     0,  1108,
     727,     0,  1779,  1109,     0,   728,     0,     0,     0,     0,
    1113,     0,   729,     0,     0,     0,     0,  1111,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,  1114,  1112,     0,  1107,     0,
     730,  1110,  1095,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,  1782,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1111,
       0,     0,     0,     0,     0,     0,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,  1113,     0,
       0,     0,  1108,  1111,     0,     0,  1109,     0,     0,     0,
      82,     0,   731,     0,  1105,     0,   722,  1106,     0,     0,
       0,     0,  1112,     0,     0,   723,   724,     0,     0,     0,
       0,   269,   725,   726,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,     0,
    1113,  1884,  1885,     0,  1886,     0,     0,   269,  1887,  1888,
      41,     0,     0,     0,  1114,     0,   727,     0,     0,     0,
       0,   728,  1111,     0,     0,     0,     0,     0,   729,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,  1889,     0,     0,
       0,     0,     0,     0,  1113,     0,   730,     0,     0,   732,
       0,     0,     0,     0,   733,     0,  1114,     0,     0,     0,
       0,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,  1105,  1107,     0,  1106,     0,
       0,     0,   734,  1095,     0,     0,     0,     0,     0,     0,
       0,  1108,     0,     0,     0,  1109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,     0,     0,  1113,     0,     0,     0,   735,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   736,
       0,     0,     0,  1110,     0,     0,    82,     0,   731,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,   737,     0,     0,
       0,     0,   738,     0,     0,   739,  1102,  1103,  1104,     0,
       0,  1111,   698,     0,     0,     0,   740,     0,   722,     0,
       0,     0,   741,     0,     0,     0,     0,   723,   724,  1114,
    1112,     0,   742,   269,   725,   726,    41,   743,     0,     0,
     744,     0,     0,   745,     0,     0,     0,  1107,     0,     0,
       0,     0,   746,   747,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,     0,   727,     0,
       0,     0,     0,   728,     0,     0,     0,     0,     0,     0,
     729,     0,     0,     0,     0,   732,     0,     0,     0,     0,
     733,     0,     0,  1201,   748,     0,     0,     0,   749,     0,
       0,     0,     0,     0,  1110,     0,   750,     0,   730,     0,
       0,     0,  1113,     0,     0,     0,  2050,   751,   734,     0,
       0,     0,     0,   752,     0,     0,     0,     0,     0,     0,
       0,     0,  1111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,     0,   753,  1106,
       0,  1112,     0,   735,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   736,     0,  1884,  1885,     0,
    1886,     0,     0,   269,  1887,  1888,    41,     0,  1114,     0,
       0,     0,     0,   737,     0,     0,     0,     0,   738,     0,
       0,   739,   754,     0,     0,     0,     0,     0,    82,   755,
     731,   756,   740,     0,     0,     0,     0,     0,   741,     0,
       0,   757,   758,  1889,     0,     0,     0,  1890,   742,   759,
       0,     0,     0,   743,     0,     0,   744,     0,     0,   745,
     272,     0,  1891,  1113,     0,     0,     0,     0,   746,   747,
       0,     0,     0,     0,     0,   722,     0,     0,     0,  1892,
       0,     0,  2051,     0,   723,   724,     0,     0,     0,     0,
     269,   725,   726,    41,  2052,  1894,     0,     0,  1107,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
     748,     0,     0,  1108,   749,     0,     0,  1109,     0,  1095,
       0,     0,   750,     0,     0,   727,     0,   732,     0,  1114,
     728,     0,   733,   751,     0,  2157,  1896,   729,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,  1897,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,     0,     0,
     734,     0,     0,     0,   753,   730,     0,     0,   698,     0,
       0,     0,     0,     0,     0,     0,  1096,  1097,  1098,  1099,
    1100,  1101,     0,  1111,     0,     0,     0,     0,     0,     0,
    1898,     0,  1102,  1103,  1104,   735,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,   736,   754,     0,
       0,     0,     0,  1884,  1885,   755,  1886,   756,     0,   269,
    1887,  1888,    41,     0,     0,   737,     0,   757,   758,  1899,
     738,     0,     0,   739,     0,   759,     0,     0,     0,     0,
       0,  1900,     0,     0,   740,     0,   272,     0,     0,     0,
     741,     0,     0,  1901,  1902,    82,     0,   731,     0,  1889,
     742,  1903,     0,     0,  1904,   743,     0,     0,   744,     0,
       0,   745,   272,     0,     0,     0,     0,     0,     0,     0,
     746,   747,     0,     0,  1113,     0,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,  1884,  1885,     0,  1886,
       0,     0,   269,  1887,  1888,    41,     0,  1095,     0,     0,
    1884,  1885,     0,  1886,     0,     0,   269,  1887,  1888,    41,
       0,  2515,   748,     0,     0,     0,   749,     0,     0,     0,
       0,     0,  1105,     0,   750,  1106,     0,     0,   269,  1887,
    1888,    41,  1889,     0,     0,   751,     0,     0,     0,     0,
    1114,   752,     0,     0,   732,     0,  1889,     0,     0,   733,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,  1890,     0,     0,   753,     0,  2578,     0,
    1102,  1103,  1104,     0,   698,     0,     0,   734,  1891,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1892,     0,     0,  1893,     0,
    2576,  2577,     0,     0,     0,     0,   269,  1887,  1888,    41,
     754,  1894,   735,     0,     0,     0,     0,   755,     0,   756,
       0,     0,     0,     0,   736,     0,  2576,  2577,     0,   757,
     758,     0,   269,  1887,  1888,    41,     0,   759,     0,     0,
       0,     0,   737,     0,  1107,     0,  2578,   738,   272,     0,
     739,  1895,  1896,     0,     0,     0,     0,   698,     0,  1108,
       0,   740,     0,  1109,  1897,     0,     0,   741,     0,     0,
       0,   698,  2578,     0,     0,     0,     0,   742,     0,     0,
       0,     0,   743,     0,     0,   744,     0,     0,   745,     0,
       0,     0,     0,   698,     0,     0,     0,   746,   747,     0,
       0,  1110,     0,     0,     0,     0,  1898,     0,     0,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   748,
       0,     0,     0,   749,     0,  1899,  1095,     0,  1112,     0,
       0,   750,  2576,  2577,     0,     0,     0,  1900,   269,  1887,
    1888,    41,   751,     0,     0,     0,     0,     0,   752,  1901,
    1902,   698,     0,     0,     0,     0,     0,  1903,     0,  1890,
    1904,  1886,     0,     0,   269,  1887,  1888,    41,   272,     0,
       0,     0,     0,   753,  1891,     0,     0,   698,  2578,     0,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,  1892,     0,     0,  1893,     0,     0,     0,     0,  1102,
    1103,  1104,     0,     0,  1889,     0,     0,  1894,     0,     0,
    1113,     0,  1107,     0,     0,     0,     0,   754,     0,     0,
       0,     0,     0,     0,   755,     0,   756,  1108,     0,     0,
       0,  1109,     0,     0,     0,  2222,   757,   758,     0,     0,
       0,     0,  1890,     0,   759,     0,     0,     0,  1896,     0,
       0,     0,     0,     0,     0,   272,  1890,  1891,     0,     0,
    1897,     0,     0,     0,     0,     0,     0,     0,     0,  1110,
       0,  1891,     0,     0,  1892,     0,  1114,  1893,  1890,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1892,     0,
    1894,  1893,     0,  1891,     0,     0,     0,  1111,     0,     0,
       0,     0,  1898,   698,  1894,     0,     0,     0,     0,     0,
    2579,     0,     0,  2580,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2581,     0,     0,   698,
    3051,  1896,     0,     0,     0,     0,     0,     0,     0,  1105,
       0,  1899,  1106,  1897,     0,  1896,     0,     0,     0,     0,
       0,     0,     0,  1900,     0,     0,  1890,  1897,     0,     0,
       0,     0,     0,     0,     0,  1901,  1902,  2583,     0,     0,
       0,  1891,     0,  1903,     0,     0,  1904,   838,     0,  2584,
       0,     0,  1890,     0,   272,  1898,   839,     0,  2579,     0,
       0,  2580,     0,     0,     0,   840,     0,  1891,  1113,  1898,
     841,     0,     0,     0,  2581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2579,     0,     0,  2580,     0,     0,
       0,  2585,     0,     0,  1899,     0,     0,     0,     0,     0,
    2581,     0,     0,     0,     0,     0,  1900,     0,  1899,     0,
       0,     0,     0,   842,  2582,  2583,     0,     0,  1901,  1902,
    1900,   843,     0,     0,     0,     0,  1903,  2584,  2222,  1904,
    2586,  1107,  1901,  1902,  1114,     0,     0,   272,     0,     0,
    1903,  2583,  2587,  1904,     0,     0,  1108,     0,     0,     0,
    1109,   272,     0,  2584,  2588,  2589,  1942,  1943,  1944,  1945,
    1946,  1947,  2590,     0,     0,  2591,     0,     0,     0,  2585,
       0,     0,     0,   272,     0,     0,     0,   844,  1890,  1942,
    1943,  1944,  1945,  1946,  1947,     0,     0,     0,  1110,     0,
       0,     0,     0,  1891,     0,  2585,     0,     0,     0,     0,
       0,     0,   845,     0,  1890,     0,     0,     0,  2586,   846,
    2579,   847,     0,  2580,     0,  1948,  1111,     0,     0,  1891,
    2587,   848,     0,     0,     0,     0,  2581,     0,     0,     0,
       0,     0,  2588,  2589,  2586,  1112,  1892,     0,  1948,  1893,
    2590,     0,     0,  2591,     0,     0,  2587,   849,     0,     0,
       0,   272,  1894,     0,     0,   850,     0,     0,  2588,  2589,
       0,     0,     0,     0,     0,     0,  2590,  2583,     0,  2591,
       0,     0,     0,     0,     0,     0,     0,   272,     0,  2584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   851,  1896,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1897,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1113,   852,  3015,
       0,  2585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1898,     0,     0,
       0,     0,     0,     0,     0,     0,   853,     0,     0,     0,
    2586,     0,     0,     0,     0,     0,     0,   854,     0,     0,
       0,     0,  2587,     0,     0,  3016,     0,     0,     0,     0,
       0,     0,     0,  1114,  2588,  2589,  1899,     0,     0,     0,
       0,     0,  2590,     0,     0,  2591,     0,     0,  1900,     0,
    3017,     0,     0,   272,     0,     0,     0,     0,     0,  3018,
    1901,  1902,     0,     0,     0,     0,     0,     0,  1903,     0,
       0,  1904,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3019,     0,     0,  1949,     0,
       0,     0,     0,  3020,     0,     0,     0,     0,     0,     0,
       0,  1950,     0,     0,     0,     0,     0,   855,   856,   857,
       0,  1949,     0,     0,     0,     0,     0,     0,     0,     0,
     858,     0,     0,     0,  1950,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1951,     0,     0,     0,     0,
       0,     0,  1952,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3021,  1951,     0,
       0,     0,     0,     0,     0,  1952,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   859,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1953,     0,  1954,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1955,  1956,     0,     0,
       0,     0,  1957,     0,     0,     0,     0,     0,     0,  1954,
       0,     0,  1958,     0,     0,     0,     0,     0,     0,  1955,
    1956,     0,     0,     0,     0,  1957,     0,     0,     0,     0,
       0,     0,     0,     0,  1959,  1958,     0,  1960,  1961,     0,
       0,     0,     0,  1962,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1959,     0,     0,
    1960,  1961,     0,     0,     0,     0,  1962,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1963,     0,     0,     0,     0,     0,     0,     0,     0,  3022,
       0,  1964,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1963,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1964
};

static const short yycheck[] =
{
       4,   716,   328,   713,   194,   188,    66,     0,   699,    13,
      14,   866,   837,   523,   848,   989,  1501,   499,   447,   212,
    1871,   424,  1003,   874,  1412,   363,  1701,   834,  1999,   517,
    1378,    24,  1367,   154,  1381,   176,    62,    30,  1276,  1277,
      82,    45,    46,   844,   845,   996,   847,  1309,   849,   850,
     739,  1563,  1752,   481,   508,   509,  1811,   545,   118,     5,
     548,   515,  1884,  1885,  1624,   519,    27,    27,  2184,    95,
     506,     5,    76,    66,     5,    79,     5,   787,     5,  1705,
      21,   264,   388,    27,   225,     5,    27,    91,     5,    24,
    1941,    26,     5,  2412,    98,    25,   419,    27,   102,   422,
     423,   105,   106,   506,  2298,  2299,  2300,   111,   112,    24,
       5,    26,   541,   436,   100,   141,   237,   238,     5,   145,
      27,    19,   929,     5,  1031,   118,     5,    27,    26,    33,
    2301,   454,   510,    25,   457,    27,   943,   962,     5,    68,
     463,    70,    33,    72,   467,    76,   150,     5,   471,   153,
     340,    82,   475,    79,   158,    27,   479,   480,     6,   482,
     134,    25,   485,    27,   487,   488,   489,    21,  1587,   419,
       5,    25,   495,    27,     5,   498,    62,  1696,  1697,    19,
      91,  1700,   505,    27,    24,    25,    26,   510,    25,    26,
      27,    62,   196,  2279,     5,   518,     5,     5,    25,  2518,
      27,   227,     5,     5,   454,   395,   529,   457,  1265,    25,
     533,    27,   149,    27,   537,    64,  1937,   467,   933,   698,
     543,   471,   273,   546,     5,   475,    24,    25,    26,    27,
     234,    27,   482,    24,    25,    26,   240,   487,     5,   489,
      24,    25,    26,    27,    27,   495,     5,   251,   498,     5,
      24,    25,    26,    27,   280,   505,   282,    25,    27,    27,
     510,   287,    87,    88,  1890,    27,   343,     5,   518,   149,
      24,    25,    26,    27,     5,  2395,   338,     5,    23,   529,
      27,  1800,     6,   533,   188,   189,  1636,   537,    48,    49,
      50,    51,    52,   543,     6,     5,   546,   189,   189,    24,
      25,    26,    27,   429,   364,   365,   546,  2278,  2668,    25,
     336,    27,     5,   294,     5,  1990,   390,    65,     5,    26,
      27,  2227,  2228,  2229,  2230,   189,   338,   353,  1813,  1748,
     338,   538,  2890,    25,  1065,    27,   281,  2188,   294,   330,
     206,     5,   174,    25,   244,     0,   273,    23,    21,   294,
     162,   359,   356,  2817,    27,   359,   273,   257,  1213,     5,
      31,     5,   189,   367,  2828,    28,    18,    19,    20,    21,
      22,   364,   365,    18,   429,   538,  2051,   617,    29,   383,
     587,   385,   162,    18,    19,    20,    21,    22,   898,   359,
     346,   189,     5,     5,   350,     5,     5,   367,   234,     5,
    1381,   456,     5,   247,     5,   189,     5,     5,  1675,   413,
     332,  1678,   373,     5,   418,   189,   420,   421,     5,     5,
     424,   425,   624,   427,   587,   625,   430,   189,     9,    10,
     140,    12,    13,    14,    15,    16,    17,   441,   270,    84,
       5,    18,    19,   413,   448,   647,     5,   428,     5,    26,
      27,     5,  3010,     5,   538,   470,   460,  1172,     5,     5,
     618,   429,   384,   478,   189,     5,   470,   625,  1987,   473,
       5,     5,   428,   189,  1893,     5,     5,     5,  2564,   483,
      21,     5,   189,   428,     5,   247,    27,  2208,   233,   457,
       5,     5,     5,  2012,     5,   499,   500,   189,     5,   625,
       5,   282,   506,   587,   348,     5,     5,    27,     5,  2869,
     514,     5,   516,   517,   837,   589,   578,   568,   595,     5,
     524,   525,   513,   527,   528,   273,   530,  2046,   532,   429,
     534,   343,   398,   524,   538,  1014,   540,   386,   542,   513,
     544,   545,   390,   547,   548,   883,   550,   885,  2519,   150,
    1038,  2671,   348,   439,   282,  1043,  1044,   233,   425,  1041,
    1042,  1252,   411,   343,   508,   348,   578,   425,    10,   616,
     578,  2393,  1060,  2395,   352,   475,   855,   856,  1816,   390,
    1999,  1017,  2415,   961,    23,  2418,  1974,   837,   525,   461,
     425,   491,  1302,  1303,   425,   343,   394,   722,   723,   724,
     561,  1311,    27,   394,   530,   372,  2925,  1514,   539,   595,
     394,   409,   189,   738,  1017,   429,   425,   425,   409,   744,
     745,   303,   425,   425,   749,   409,   470,   309,   310,   311,
    1140,   390,  2051,   553,   390,  1985,  2148,   960,   961,   962,
     388,   568,  1152,   556,  1354,   525,   495,   329,   652,   553,
     676,   568,   390,   979,  2825,   550,   542,   388,   383,  2510,
     429,   429,   553,   550,   546,  1153,   390,   546,   504,   189,
     251,   542,   470,  2992,   980,  2791,  1158,   681,   390,   683,
    2192,   611,   589,   617,   619,   361,   550,   470,   617,  2201,
    2202,   589,    27,   585,   698,   626,   625,   390,   514,   390,
    1136,   365,   394,   390,   619,   666,   666,  2793,  2794,   713,
     960,   961,   962,  1141,  2274,   661,  2832,  2472,   722,   723,
     724,  2476,   666,  1205,  3043,   666,  3045,   638,   639,   640,
     641,   642,  1463,  1136,   738,  1466,  1998,  2072,  1427,   588,
     744,   745,  2442,  1231,   390,   749,   390,  2095,  1230,   576,
    2097,   600,   601,  1235,   470,   437,  2023,   611,   440,   608,
    1741,   486,     9,    10,   544,    12,    13,    14,    15,    16,
      17,  1578,  2291,   425,   611,    27,   599,   390,   390,   619,
     390,   390,   464,   787,   390,  1273,  1274,   390,   452,   370,
     425,   390,   390,   500,   233,  1249,  1225,   577,   390,   388,
     625,  1983,   484,   390,   390,   469,   248,  2226,  2714,   390,
    1791,    56,    57,  2232,  2233,  2234,  2235,  2236,  2237,   244,
     568,   619,   241,   583,    27,   390,  2797,  1652,   619,   833,
     834,   390,   257,   390,  2222,   619,   390,   519,   390,    84,
      85,    86,     5,   390,   390,   619,   427,   554,   512,  2671,
     390,     5,   429,   157,   189,   390,   390,   539,   540,  2278,
     390,   390,   390,   383,   868,   619,   390,   358,   550,   390,
     874,   992,  3066,   555,   995,   390,   390,   390,   358,   390,
    1390,    27,   886,   390,  2403,   390,  2405,   891,   552,   390,
     390,   390,   896,   390,   619,  2521,   390,   135,   136,   619,
     648,   649,   650,  2809,   390,  2811,  2812,  2813,  2814,   457,
     914,   659,   594,  2598,  1039,   157,   352,   581,    25,  1198,
      27,  1046,   361,   424,  1049,   929,   590,     5,  2881,  2167,
    2883,   457,  1642,    25,   457,    27,  2787,  1062,    14,   943,
      25,  1066,    27,   385,   626,   387,    25,   521,    27,  1074,
    1404,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1013,    25,  1156,    27,   556,     0,   429,   480,  2398,
     429,  1106,  1107,   281,   475,   112,  1111,   150,  1113,  2501,
     535,   295,   244,   997,   457,   475,   294,  1001,  1002,  1003,
      24,    24,  1836,    26,   251,   257,   429,   576,   457,  1463,
    1014,   429,  1466,  1017,   354,  1019,  1020,  2436,  2580,  1023,
      18,    19,    20,    21,    22,  1513,  2769,   457,    25,   852,
      27,    26,    27,   323,  1038,  1039,   859,  1041,  1042,  1043,
    1044,   622,  1046,   189,   429,  1049,  2565,   616,   383,  2792,
     475,  1561,   167,   295,   163,   429,  1060,   166,  1062,   323,
     424,  2804,  1066,   589,    28,    29,   491,   371,  1923,   658,
    1074,   619,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,    26,   619,   585,  2614,  2047,   189,  2280,  2281,
    2519,   429,  1106,  1107,   189,   585,   457,  1111,  2527,  1113,
     189,  2530,  2531,  2532,  2533,    25,  2097,    27,  1628,   429,
    2805,  2806,   624,   370,  1128,   429,  3079,  1609,  1610,   371,
     428,  2086,  1136,  2088,  2089,  1623,   189,   340,  1142,  1143,
    1144,   643,   644,  2094,  2770,   348,   349,  2773,   429,  1153,
      25,  1155,    27,  1157,  1158,  2830,   619,   429,  1162,  1300,
     269,   663,   429,   272,  1989,  1306,    26,  2224,  2918,  2919,
     373,   475,    25,   376,    27,   429,    25,   429,    27,  2567,
     427,    26,    27,  1506,   625,   294,  2011,   491,   429,   334,
     480,   394,   189,   533,   189,  1199,   625,   435,  2941,    26,
     345,  1205,    34,    21,    36,    37,    38,   547,   453,    27,
      25,  1549,    27,    25,  1905,    27,   480,   237,   237,   489,
    1224,  1342,  1732,   475,  1228,    26,  1230,  1231,   498,    26,
    1351,  1235,   572,   475,    26,  1239,  1240,  1241,    26,   491,
    2297,  2298,  2299,  2300,    26,    27,   619,  1251,  2810,   491,
      26,    27,   397,   457,  2816,  2674,  1506,  2819,  2820,  2821,
    2822,  1265,  1972,    25,    25,    27,    27,   412,  1272,  1273,
    1274,    21,    21,   543,   294,   294,   546,    27,    27,   189,
     620,  2800,  1792,  3033,  1794,  3035,   544,    26,  1742,   547,
     196,    26,   550,  1803,   200,  1299,   541,   500,  1302,  1303,
      21,  2108,    26,  1307,  2014,  1309,    27,  1311,  1631,   556,
     429,  1436,  1437,  1438,   189,  1440,   441,    21,    26,   428,
     529,  1347,   437,    27,   533,  3000,   346,   346,   537,  1652,
     350,   350,    26,   448,   624,   460,   189,   456,   457,   584,
     189,    26,  1467,   163,   189,  2050,   166,  2052,   473,    58,
    1354,   554,   390,   643,   644,   470,  2775,   502,   561,   118,
     624,    21,   477,  1367,   619,  2036,  2217,    27,   429,  1851,
     190,  2042,  2891,   663,  1378,   622,   360,  1381,  2797,   643,
     644,  1631,    20,    21,   619,  2947,   457,    26,  2950,  2951,
    2952,  2953,   390,   429,    30,   365,  1400,  1401,  1402,   663,
     471,   520,  1652,    25,   475,    27,    27,   189,   428,   428,
      46,    47,    19,   189,   429,  2270,   487,    24,    25,    26,
     456,   457,   624,  1548,   624,  2938,  2911,   189,   189,  1883,
     429,  2944,  1436,  1437,  1438,   425,  1440,   269,  1563,    75,
     272,     5,   274,    19,   646,   647,   646,   647,    24,   269,
      26,  2432,   272,   390,    92,    93,    94,    95,    96,    97,
     619,   220,   294,  1467,   456,   457,  1470,  2886,   457,   228,
     437,    26,   304,  2424,   294,   234,    25,   236,    27,   257,
    1484,   448,   452,   104,   520,   365,   122,   123,   247,   125,
     126,   323,   425,    25,   130,    27,  3058,   390,  1502,   469,
     365,   639,   640,   470,  1508,   360,  1510,  1511,  1512,  1513,
     477,   147,   148,  1916,   346,    24,   275,    26,   350,  2576,
    2577,    21,  3034,  2580,  2943,    26,    24,  3012,    26,   165,
     853,   854,   291,   154,   857,   858,    26,   296,    26,  1543,
     446,   447,   512,  1733,  1548,    26,  3031,    26,    34,   308,
      36,    37,    38,    21,   638,  1559,   315,   641,   642,  1563,
     612,   613,   614,   615,  3083,  1758,  1570,  1137,   189,  1139,
     191,  2990,   452,   163,  1578,   429,   166,   423,    26,   133,
    1584,  1585,   552,  1587,   108,   109,   110,   452,    26,   469,
     436,  2101,  2297,  2298,  2299,  2300,   428,    25,    26,   235,
     190,    46,    47,    26,   469,  1609,  1610,  3092,   428,  2666,
     619,   581,  2669,   456,   457,   286,   287,   463,   390,  1623,
     590,   648,   649,   641,   642,   365,     5,    34,   301,    36,
      37,    38,   512,   479,   480,   541,   390,  2492,  1642,   485,
     623,  2151,   488,   390,   198,   551,   200,   512,    18,    19,
      20,    21,    22,  2627,   390,  1780,  2490,  1661,  1783,   390,
    1983,   215,  3081,   648,   649,   390,  1989,   288,   390,   223,
    1674,  1675,   552,   227,  1678,  2576,  2577,   122,   123,   269,
     125,   126,   272,     5,   238,   130,   301,   552,  2011,  2394,
    1694,  2396,  1696,  1697,   390,   390,  1700,  1701,   252,   390,
    3119,   581,   147,   148,   294,   623,   390,   390,   619,   429,
     590,   470,   452,   457,   616,   619,   581,     8,   477,   355,
     165,   478,   425,  1727,   429,   590,  1730,  2437,   429,   469,
    1734,   525,   429,  1983,   265,   356,   365,  1741,     5,  1989,
     499,   429,   429,   364,  1748,   504,   458,   368,   429,   429,
     429,  2808,   429,  2810,   429,   429,   617,   429,   419,  2816,
    2817,  2011,  2819,  2820,  2821,  2822,   429,   429,   404,   133,
     429,  2828,   512,   429,   429,   429,  1780,   429,  2260,  1783,
    2262,   159,  2497,   269,   405,   429,   272,  1791,   274,   429,
     235,  1795,  1796,  1797,  1798,   429,  1800,   175,   176,   429,
     436,   429,  1806,  1807,   617,   183,  1810,  1811,   294,   595,
     716,   419,   552,   458,   658,  1819,    63,   429,   304,   658,
     325,     8,   596,   452,     5,  1829,     5,   429,   429,   382,
     365,   429,   429,   429,   198,   343,   200,   323,   428,   217,
     469,   581,     8,   589,   578,    14,   575,  1851,   226,     5,
     590,   215,   473,   658,     5,   658,   762,   419,   429,   223,
     346,   429,   269,   227,   350,   272,    61,   274,    26,   365,
      91,  2576,  2577,  1877,    26,  2580,    65,   255,  2733,   457,
    1884,  1885,   457,   512,    26,     5,  2741,   294,   252,  1893,
    2947,   512,   619,  2950,  2951,  2952,  2953,   304,   470,   429,
    1904,  2592,  2331,  2332,  2333,   595,  2335,  2336,  2337,  2338,
    2339,  2340,  1916,   589,   429,  2344,   537,   452,   429,  2429,
    1924,    21,   300,   552,    21,   625,   429,   429,   661,  2986,
     429,  1759,   625,   625,   469,  1763,   429,   349,   133,   346,
    1768,     5,   428,   350,  1772,   556,  1774,  1775,  1776,  2459,
      18,     5,   581,    19,   624,    26,   452,  2280,  2281,    26,
     581,   590,    20,    21,   342,   217,   152,   481,  1972,   590,
      25,   589,   622,   469,   578,   481,  2036,   512,   619,     5,
     546,   546,  2042,  1987,    26,   150,  1990,   398,   320,   546,
      26,   436,  2480,  1997,  1998,  1999,  2706,   429,  2002,  2487,
    2004,  3058,   429,   198,  2829,   200,   663,   429,  2012,  3066,
    2014,   429,   429,   390,   619,   576,   512,   552,   457,  2023,
     215,   428,  2147,  2148,   546,   390,  2216,   933,   223,   390,
    2280,  2281,   227,   390,    92,    93,    94,    95,    96,    97,
     390,   390,  2046,  2036,   390,  2049,   581,  2051,    26,  2042,
     390,   298,   390,   429,  2909,   590,   552,   252,   616,  2063,
       5,     5,  2092,     5,  2189,   625,   579,  2192,  2072,   619,
       5,   390,    30,   482,   625,   429,  2201,  2202,   624,    61,
      32,   429,     5,   553,   429,   581,    26,    26,    46,    47,
      65,  2095,   535,  2097,   590,   324,     5,    55,     5,   429,
     390,  2105,    60,   429,  2108,  2810,   359,   596,  2112,   356,
      14,  2816,  2817,   625,  2819,  2820,  2821,  2822,   419,   419,
       5,   368,   659,  2828,   550,   546,     5,    26,    80,    81,
     100,   378,   429,   625,   619,   429,     5,    89,   425,   425,
     624,   638,   459,  2147,  2148,   459,   429,   105,   106,   396,
     429,   133,   134,  2157,   429,   113,  2160,   429,   429,   406,
     429,  2165,   409,   429,   122,   123,     8,   125,   126,     5,
      26,  2881,   130,  2883,  2178,   422,  2180,    26,  2182,   589,
     390,   390,    25,   390,    25,  2189,    25,    25,  2192,   147,
     148,   390,  3047,  2197,     5,   619,     5,  2201,  2202,   619,
     619,  2916,    18,    19,    20,    21,   188,   165,     8,   324,
      25,   343,   194,  2217,  3015,  3016,  3017,  3018,  3019,  3020,
    2224,   343,  2226,   457,   471,  2735,   619,   343,  2232,  2233,
    2234,  2235,  2236,  2237,     6,     7,     8,     9,    10,    11,
      12,   429,  2947,   457,   424,  2950,  2951,  2952,  2953,   359,
    2732,   429,   429,   429,   501,   429,  2260,   429,  2262,    18,
      19,    20,    21,     5,   511,   429,  1172,  2297,  2298,  2299,
    2300,    26,   429,     5,  2278,   650,    92,    93,    94,    95,
      96,    97,   264,     5,   266,   532,    25,  2291,   535,    14,
     537,  2474,    26,  2297,  2298,  2299,  2300,  2301,  2302,    14,
    2626,   616,   595,   595,   429,     5,   619,   259,  2312,  2313,
    2314,   619,     5,     5,   390,   429,  2320,     7,   565,  1225,
       5,   619,   625,    26,    26,  2450,     8,   574,    26,   390,
     619,   390,    26,    92,    93,    94,    95,    96,    97,   589,
     625,   625,   390,   390,   390,   390,   298,    30,    21,   390,
       5,   566,   273,  3058,     5,   390,    30,     5,   340,     5,
       5,  3066,   546,    46,    47,   317,   239,   390,   571,  3079,
     625,   390,    46,    47,  1280,   619,  2501,  2381,   619,  2383,
     390,   333,   439,   470,     6,   429,   625,     5,   625,  2393,
    2900,  2395,   553,   623,  2398,   209,   623,    25,    25,  2403,
    2404,  2405,    25,   295,   356,   618,   445,    26,   366,    25,
      25,   429,    26,   395,    26,    26,   368,    26,   470,    26,
     429,    26,     5,   390,   390,     5,   378,   267,  2432,   525,
     589,   429,  2436,  2437,   392,   467,   390,   550,  3153,   122,
     123,   239,   125,   126,   396,   425,  2450,   130,   122,   123,
     432,   125,   126,    25,   406,     5,   130,   390,   439,   390,
     343,    21,   139,   553,   147,   148,   429,   429,  2472,   429,
     422,  2475,  2476,   147,   148,     5,  2480,     5,   429,  2483,
     429,   429,   165,  2487,   466,    14,   429,   970,   619,   209,
     472,   165,   474,     5,   440,   390,   478,  2501,   457,   481,
      26,   390,   484,   390,    26,   463,  2829,     5,  2512,   390,
     462,   618,   494,   367,   429,  2519,   448,   330,   390,   372,
      26,   429,   390,  2527,   390,   568,  2530,  2531,  2532,  2533,
    2534,   513,   390,   343,   486,   390,   240,  2541,   470,   521,
     522,   523,   625,   457,   390,   527,  2576,  2577,   575,   501,
    2580,   546,   429,   535,  2558,   390,   508,   390,   390,   511,
     390,  2565,   390,   619,    14,     7,   238,   238,    26,   551,
    2574,   390,  2576,  2577,   625,   446,  2580,    26,   429,  2829,
     532,   619,   514,   535,   391,   537,   390,  2591,   390,   390,
       5,   625,   524,   525,   625,    25,   528,    27,   429,   557,
     532,   425,   534,     5,   556,   390,   538,    25,   540,   240,
    2614,   390,  2616,   390,   390,   390,    46,    47,     5,   390,
     390,   390,   574,  2196,  2105,  3102,  1242,  1867,  2147,  1571,
      37,    39,  1807,   364,  2178,  1813,  2666,   287,   141,  2669,
     145,   209,   281,   397,  1346,   288,   353,   211,  1347,  1766,
     371,  2445,   316,   315,   383,   385,  1543,  3092,   967,  1783,
     527,  1417,  2666,  1679,   616,  2669,  1672,  2671,  1797,  1272,
    2674,  1512,   355,  2251,  2544,  1275,  1601,  1920,  3117,   637,
    1801,  1587,  1618,  1158,  2749,    24,   118,   645,    30,  2648,
      30,  1576,   122,   123,   484,   125,   126,   654,  1582,   266,
     130,  1280,  2706,  1918,   683,  2645,  2710,  1585,  2712,   934,
    2846,  1634,  1149,  3031,  1196,  2233,  2856,   147,   148,   886,
    1224,   404,  2371,  1139,  2353,  2045,  1070,  2369,  2732,  1791,
    1361,  1384,  2922,  2737,   716,   165,  3119,  1983,  3083,  2015,
    2968,  1023,  2402,  2046,  1700,  2381,  2383,  2049,  2706,  2438,
    2669,  2986,  1299,  2314,  2063,  2680,  2893,   963,  2892,   189,
    2575,  2292,  2436,  2232,  3081,  1294,  2935,   959,  2574,  2808,
    2827,  2775,  1267,  2816,  1154,  1730,   362,    -1,    -1,    -1,
    2810,    -1,    -1,    -1,    -1,    -1,  2816,  2817,  1694,  2819,
    2820,  2821,  2822,  2797,    -1,  1701,  2800,    -1,  2828,    -1,
      -1,    -1,   784,    -1,  2808,   235,  2810,    -1,    -1,    -1,
      -1,    -1,  2816,  2817,    -1,  2819,  2820,  2821,  2822,    21,
      22,  2825,    -1,  2827,  2828,    -1,  2830,    -1,    -1,    -1,
      -1,  2861,    -1,    35,  2838,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1748,    -1,    -1,   827,    -1,    -1,    -1,    -1,
    1333,  1334,    -1,    -1,    -1,    -1,    -1,  1340,    -1,    -1,
      -1,   843,   844,   845,    -1,   847,    -1,   849,   850,    -1,
      -1,    -1,    -1,   855,   856,    -1,    -1,  2881,    -1,  2883,
      -1,    -1,  2886,    -1,    -1,    -1,    -1,  2891,    -1,  2893,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,  3034,
      -1,    -1,    -1,    -1,    -1,    -1,   898,  2947,    -1,    -1,
    2950,  2951,  2952,  2953,    -1,    -1,    -1,   909,    -1,    -1,
      -1,  2935,    -1,    -1,    -1,    -1,   868,    -1,    -1,  2943,
      -1,    -1,   874,  2947,    -1,    -1,  2950,  2951,  2952,  2953,
    2954,   933,   934,    -1,   886,    -1,  2986,    73,    74,   891,
     942,    77,    78,    79,  2968,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   958,   959,  1884,  1885,
      -1,    -1,  2986,    35,    -1,    -1,  2990,  1893,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3000,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3026,  3027,    -1,    -1,    -1,    -1,  3058,    -1,
    3034,    -1,    -1,    -1,    -1,    -1,  3066,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,  3058,    -1,   108,   109,   110,    -1,
     176,    -1,  3066,    -1,    -1,    -1,    -1,   183,    -1,    -1,
    1553,    -1,    -1,    -1,    -1,  3079,    -1,  3081,    -1,  3083,
      -1,    -1,    -1,    -1,  1990,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1999,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    -1,  1597,  3119,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,  3139,    -1,    -1,    -1,   255,
     256,    -1,    -1,  2049,    -1,  2051,    35,  1129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1137,    -1,  1139,  1140,  1141,
      -1,    -1,    -1,    -1,    -1,    -1,  1148,  1149,   370,    -1,
    1152,    -1,    -1,    -1,  1156,    -1,    -1,  1159,    -1,    -1,
      -1,    -1,    -1,   385,   300,    -1,  2092,   389,    -1,    -1,
    1172,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
    1142,  1143,  1144,    -1,    -1,    -1,  1198,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,   427,   342,    -1,    -1,    -1,
    1162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,  1237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1199,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,  1261,
      -1,    -1,   398,    -1,  1266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1224,    20,    21,    22,    -1,  1279,  1280,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,  1241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,  1251,
    2226,    -1,    -1,    -1,    -1,    -1,  2232,  2233,  2234,  2235,
    2236,  2237,    -1,   385,    -1,    -1,    -1,   389,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1335,   556,    -1,    -1,    -1,    -1,   248,
      -1,    -1,   251,    -1,    -1,    92,    93,    94,    95,    96,
      97,    -1,  2278,    -1,    -1,   427,    -1,    -1,  1861,  1862,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,  1872,
      -1,  2297,  2298,  2299,  2300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,  1390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,   474,    -1,    -1,  2331,  2332,  2333,    -1,  2335,
    2336,  2337,  2338,  2339,  2340,    -1,    -1,    -1,  2344,    -1,
      -1,    -1,  1925,  1926,  1927,  1928,    -1,    -1,    -1,    -1,
    1933,  1934,  1935,  1936,    -1,    -1,    -1,  1940,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2381,    -1,  2383,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,  2393,    -1,  2395,
      -1,    -1,  2398,    -1,    -1,    -1,   385,    -1,    -1,    -1,
     389,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
    2436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,  2024,  2025,    -1,    -1,    22,    -1,    -1,  2031,  2032,
      -1,    -1,  1484,    -1,    -1,    -1,    -1,    -1,    35,  1541,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,  1550,    -1,
     622,    -1,    -1,    -1,    -1,    -1,  1508,    -1,    -1,  1561,
    1512,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,  2497,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
    1582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1543,    -1,  2519,    -1,    92,    93,    94,    95,    96,
      97,  2527,    -1,    -1,  2530,  2531,  2532,  2533,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,  1570,    -1,
      -1,    -1,    -1,   370,    -1,    -1,  1628,  1629,  1630,    -1,
      -1,    -1,  1634,    -1,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,   389,    -1,    -1,    -1,    -1,   556,    -1,    -1,
    2576,  2577,    -1,    -1,  2580,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1666,  2168,  2169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2177,    -1,    -1,    -1,    -1,    -1,
     427,    -1,  2185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2205,  2206,    -1,    -1,    -1,    -1,   455,    -1,
      -1,    -1,    -1,   622,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   474,    -1,    -1,
    1732,  1733,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
    2666,    -1,    -1,  2669,    -1,  2671,    -1,    -1,  2674,    -1,
      -1,   248,    -1,    -1,   251,    -1,    -1,    -1,  2261,    -1,
    2263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1792,    -1,  1794,    -1,    -1,    92,    93,    94,    95,    96,
      97,  1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,  2321,  2322,
      -1,    -1,  2325,  2326,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1841,
      -1,    -1,    -1,  1795,  1796,  1797,  1798,    -1,    -1,  2775,
      -1,    -1,    -1,    -1,    -1,    -1,  2359,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1819,   298,  1871,
      -1,  2797,    -1,   370,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2810,    -1,    -1,   317,   385,    -1,
    2816,  2817,   389,  2819,  2820,  2821,  2822,    -1,    -1,    -1,
      -1,    -1,  2828,    -1,  2830,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,  1917,  1918,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,  1877,   356,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,  2861,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,
      -1,   248,    -1,    -1,   251,    -1,    -1,    -1,   455,    -1,
    2886,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
    2473,    -1,    -1,    -1,  2477,    -1,   406,   474,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
    2916,    -1,   422,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,  2508,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2943,    -1,    -1,
    2022,  2947,    -1,    -1,  2950,  2951,  2952,  2953,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,  2542,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2002,    34,  2004,    36,    37,    38,   486,    -1,    -1,   556,
    2986,    -1,    -1,    -1,  2990,    -1,    -1,    -1,    -1,    -1,
      -1,   501,    -1,   370,  3000,    -1,    -1,    -1,   508,    62,
      -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,  2101,
      -1,    -1,   532,    -1,    -1,   535,    -1,   537,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   622,   556,    -1,    -1,    -1,
     427,    -1,  3058,    -1,    -1,    -1,   248,    -1,    -1,   251,
    3066,    -1,    -1,   440,   574,    -1,    -1,    -1,    -1,  2151,
     133,     9,    -1,    -1,    -1,  3081,    -1,    -1,   455,    -1,
      18,    19,    -1,    21,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
     163,    -1,  2184,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2194,  3119,  2196,    -1,  2198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2157,    64,   190,  2160,  2211,
      -1,    -1,    -1,    -1,  2216,   198,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,  3153,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,   237,   238,   239,   240,   370,   556,
      -1,    -1,    -1,  2766,    -1,  2217,    -1,    -1,    -1,   252,
    2272,  2273,    -1,   385,    -1,    -1,    -1,   389,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,   272,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,    -1,  2315,    -1,   427,    -1,    -1,    -1,    -1,
      -1,   304,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,
      -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     323,   324,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2355,    -1,   338,    -1,    -1,    -1,    -1,
      -1,    -1,   474,   346,    -1,    -1,  2368,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   359,   360,   361,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2920,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2429,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,   556,   428,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   439,  2459,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
    2973,  2974,  2474,  2976,    -1,  2978,  2979,    -1,    -1,   108,
     109,   110,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2497,    -1,   480,    -1,    -1,
      -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,  2483,    -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,
     356,    35,    -1,  3046,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   409,   368,    -1,    -1,    -1,    -1,    -1,    -1,   542,
    2512,    -1,   378,    -1,    -1,    -1,    -1,  3070,   426,  3072,
      -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     396,    -1,    -1,   441,   442,    -1,    -1,    -1,    -1,  2541,
     406,    -1,    -1,    -1,    -1,   578,    -1,    -1,    92,    93,
      94,    95,    96,    97,  3107,    -1,   422,    -1,    -1,    -1,
      -1,    -1,   470,    -1,   108,   109,   110,    -1,    -1,   248,
      -1,    -1,   251,    -1,    -1,   483,    -1,    -1,    -1,    -1,
    3133,  3134,    -1,    -1,  3137,    -1,    -1,   495,    -1,    -1,
      -1,   624,    -1,  2645,    -1,    -1,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   638,   639,   640,   641,   642,
     643,   644,    -1,   646,   647,    -1,    -1,    -1,    -1,    -1,
     486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
     663,    -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,
      -1,    -1,   508,    -1,    -1,   511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,   576,   535,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     588,    -1,    -1,  2735,    -1,    -1,    -1,    -1,    -1,    -1,
     556,   370,   600,   601,    -1,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,   611,   248,    -1,   385,   251,   574,    -1,
     389,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2737,    -1,    -1,    -1,  2791,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    18,    19,
    2832,    21,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,  2846,   474,    -1,    -1,    -1,  2851,
      -1,  2853,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    64,    -1,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
    2892,   385,    -1,    -1,    -1,   389,    -1,    -1,  2900,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2916,    -1,    -1,    -1,    -1,    -1,
    2922,    -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    30,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,   108,   109,   110,    -1,
      -1,   455,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,   622,    -1,    -1,    -1,    -1,    90,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,    -1,  3015,  3016,  3017,  3018,  3019,  3020,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,   141,
      -1,   143,   144,   145,    -1,   147,   148,    -1,    -1,    -1,
      -1,   153,   556,   155,   156,    -1,   158,    -1,   160,   161,
      -1,    -1,   164,   165,  3026,    -1,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,   177,   178,    -1,   180,    -1,
      -1,    -1,   184,    -1,   186,   187,   248,    -1,    -1,   251,
     192,    -1,    -1,   293,   196,    -1,    -1,   199,    -1,   201,
      -1,   203,    -1,   205,    -1,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,   218,   219,   622,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,  3153,    -1,   245,   246,    -1,    -1,   249,   250,    -1,
      -1,   253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,   263,   264,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   276,   277,   278,  3139,   280,    -1,
      -1,    -1,   284,   285,    -1,    -1,    -1,   289,    -1,    -1,
      -1,    -1,    -1,    -1,   394,   297,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   305,   306,   307,    -1,    -1,   370,   409,
      -1,   313,   314,    -1,    -1,    -1,    -1,   319,    -1,    -1,
     322,    -1,    -1,   385,   326,   327,   426,   389,   390,   429,
      -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,
      -1,   441,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   363,    -1,    -1,    -1,   427,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,   455,    -1,   495,    -1,   399,    -1,   401,
     402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,
      -1,    -1,   464,    -1,    -1,    -1,   468,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,
     492,   493,    -1,    -1,   556,   497,    -1,    -1,    -1,    -1,
     600,   601,    -1,    -1,    -1,    -1,    -1,   509,   608,    -1,
      -1,   611,    -1,   515,   516,   517,   518,    -1,    -1,   619,
     522,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,   533,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,    -1,   547,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   558,    -1,   560,    -1,
     622,   563,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   595,    -1,    -1,   598,    -1,    -1,    -1,
      -1,   603,    -1,    -1,   606,   607,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,    -1,    -1,    -1,   628,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,   651,
     652,   653,   654,   655,   656,   657,    35,    -1,   660,    -1,
     662,    -1,   664,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    35,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,   248,    -1,    -1,   251,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,   385,    -1,    -1,    -1,
     389,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,   248,   385,    -1,   251,    -1,   389,   390,   427,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
     251,    -1,    -1,   385,    -1,    -1,   455,   389,   390,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   455,    -1,    -1,   427,    -1,    -1,    -1,    -1,
      -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,
      -1,   389,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,   385,   427,
      -1,    -1,   389,   390,    -1,    -1,    -1,    -1,    -1,   370,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,   455,   389,   390,
      -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,   556,    -1,   427,    -1,   455,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    35,   622,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,   474,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,   556,    -1,
     622,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,
      -1,   389,   390,    -1,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,   622,   556,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,   455,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   622,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,   248,    -1,    -1,   251,    -1,    -1,    -1,   556,    -1,
     108,   109,   110,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    35,    -1,   251,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,   389,   390,    -1,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,   385,
     427,    -1,    -1,   389,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    -1,    -1,   251,    -1,    -1,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,   440,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   455,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,
       9,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,   556,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,   370,   248,    -1,    -1,   251,   427,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,   385,
      59,    -1,   440,   389,    -1,    64,    -1,    -1,    -1,    -1,
     556,    -1,    71,    -1,    -1,    -1,    -1,   455,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,   622,   474,    -1,   370,    -1,
      99,   427,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,   440,    -1,    -1,   389,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   556,    -1,
      -1,    -1,   385,   455,    -1,    -1,   389,    -1,    -1,    -1,
     189,    -1,   191,    -1,   248,    -1,     9,   251,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
     556,    18,    19,    -1,    21,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,   622,    -1,    59,    -1,    -1,    -1,
      -1,    64,   455,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,   556,    -1,    99,    -1,    -1,   288,
      -1,    -1,    -1,    -1,   293,    -1,   622,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   248,   370,    -1,   251,    -1,
      -1,    -1,   321,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,    -1,   556,    -1,    -1,    -1,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,
      -1,    -1,    -1,   427,    -1,    -1,   189,    -1,   191,    -1,
      92,    93,    94,    95,    96,    97,    -1,   386,    -1,    -1,
      -1,    -1,   391,    -1,    -1,   394,   108,   109,   110,    -1,
      -1,   455,   189,    -1,    -1,    -1,   405,    -1,     9,    -1,
      -1,    -1,   411,    -1,    -1,    -1,    -1,    18,    19,   622,
     474,    -1,   421,    24,    25,    26,    27,   426,    -1,    -1,
     429,    -1,    -1,   432,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,   441,   442,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,    -1,    -1,   389,    -1,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,
     293,    -1,    -1,   482,   483,    -1,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,   427,    -1,   495,    -1,    99,    -1,
      -1,    -1,   556,    -1,    -1,    -1,   293,   506,   321,    -1,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,   537,   251,
      -1,   474,    -1,   356,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   368,    -1,    18,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    27,    -1,   622,    -1,
      -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,   391,    -1,
      -1,   394,   581,    -1,    -1,    -1,    -1,    -1,   189,   588,
     191,   590,   405,    -1,    -1,    -1,    -1,    -1,   411,    -1,
      -1,   600,   601,    64,    -1,    -1,    -1,   394,   421,   608,
      -1,    -1,    -1,   426,    -1,    -1,   429,    -1,    -1,   432,
     619,    -1,   409,   556,    -1,    -1,    -1,    -1,   441,   442,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,   426,
      -1,    -1,   429,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,   441,   442,    -1,    -1,   370,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     483,    -1,    -1,   385,   487,    -1,    -1,   389,    -1,    35,
      -1,    -1,   495,    -1,    -1,    59,    -1,   288,    -1,   622,
      64,    -1,   293,   506,    -1,   508,   483,    71,    -1,   512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
     321,    -1,    -1,    -1,   537,    99,    -1,    -1,   189,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,   108,   109,   110,   356,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,    -1,   368,   581,    -1,
      -1,    -1,    -1,    18,    19,   588,    21,   590,    -1,    24,
      25,    26,    27,    -1,    -1,   386,    -1,   600,   601,   576,
     391,    -1,    -1,   394,    -1,   608,    -1,    -1,    -1,    -1,
      -1,   588,    -1,    -1,   405,    -1,   619,    -1,    -1,    -1,
     411,    -1,    -1,   600,   601,   189,    -1,   191,    -1,    64,
     421,   608,    -1,    -1,   611,   426,    -1,    -1,   429,    -1,
      -1,   432,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     441,   442,    -1,    -1,   556,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    18,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    27,    -1,    35,    -1,    -1,
      18,    19,    -1,    21,    -1,    -1,    24,    25,    26,    27,
      -1,   482,   483,    -1,    -1,    -1,   487,    -1,    -1,    -1,
      -1,    -1,   248,    -1,   495,   251,    -1,    -1,    24,    25,
      26,    27,    64,    -1,    -1,   506,    -1,    -1,    -1,    -1,
     622,   512,    -1,    -1,   288,    -1,    64,    -1,    -1,   293,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,   394,    -1,    -1,   537,    -1,    64,    -1,
     108,   109,   110,    -1,   189,    -1,    -1,   321,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,   429,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
     581,   442,   356,    -1,    -1,    -1,    -1,   588,    -1,   590,
      -1,    -1,    -1,    -1,   368,    -1,    18,    19,    -1,   600,
     601,    -1,    24,    25,    26,    27,    -1,   608,    -1,    -1,
      -1,    -1,   386,    -1,   370,    -1,    64,   391,   619,    -1,
     394,   482,   483,    -1,    -1,    -1,    -1,   189,    -1,   385,
      -1,   405,    -1,   389,   495,    -1,    -1,   411,    -1,    -1,
      -1,   189,    64,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,    -1,   426,    -1,    -1,   429,    -1,    -1,   432,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,   441,   442,    -1,
      -1,   427,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,
      -1,    -1,    -1,   487,    -1,   576,    35,    -1,   474,    -1,
      -1,   495,    18,    19,    -1,    -1,    -1,   588,    24,    25,
      26,    27,   506,    -1,    -1,    -1,    -1,    -1,   512,   600,
     601,   189,    -1,    -1,    -1,    -1,    -1,   608,    -1,   394,
     611,    21,    -1,    -1,    24,    25,    26,    27,   619,    -1,
      -1,    -1,    -1,   537,   409,    -1,    -1,   189,    64,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,   426,    -1,    -1,   429,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    64,    -1,    -1,   442,    -1,    -1,
     556,    -1,   370,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,   590,   385,    -1,    -1,
      -1,   389,    -1,    -1,    -1,   470,   600,   601,    -1,    -1,
      -1,    -1,   394,    -1,   608,    -1,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,   619,   394,   409,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,   409,    -1,    -1,   426,    -1,   622,   429,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,
     442,   429,    -1,   409,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    -1,   537,   189,   442,    -1,    -1,    -1,    -1,    -1,
     426,    -1,    -1,   429,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,   189,
     482,   483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,   576,   251,   495,    -1,   483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   588,    -1,    -1,   394,   495,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   600,   601,   483,    -1,    -1,
      -1,   409,    -1,   608,    -1,    -1,   611,   128,    -1,   495,
      -1,    -1,   394,    -1,   619,   537,   137,    -1,   426,    -1,
      -1,   429,    -1,    -1,    -1,   146,    -1,   409,   556,   537,
     151,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,    -1,    -1,   429,    -1,    -1,
      -1,   537,    -1,    -1,   576,    -1,    -1,    -1,    -1,    -1,
     442,    -1,    -1,    -1,    -1,    -1,   588,    -1,   576,    -1,
      -1,    -1,    -1,   194,   482,   483,    -1,    -1,   600,   601,
     588,   202,    -1,    -1,    -1,    -1,   608,   495,   470,   611,
     576,   370,   600,   601,   622,    -1,    -1,   619,    -1,    -1,
     608,   483,   588,   611,    -1,    -1,   385,    -1,    -1,    -1,
     389,   619,    -1,   495,   600,   601,    39,    40,    41,    42,
      43,    44,   608,    -1,    -1,   611,    -1,    -1,    -1,   537,
      -1,    -1,    -1,   619,    -1,    -1,    -1,   258,   394,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    -1,   409,    -1,   537,    -1,    -1,    -1,    -1,
      -1,    -1,   283,    -1,   394,    -1,    -1,    -1,   576,   290,
     426,   292,    -1,   429,    -1,    98,   455,    -1,    -1,   409,
     588,   302,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,
      -1,    -1,   600,   601,   576,   474,   426,    -1,    98,   429,
     608,    -1,    -1,   611,    -1,    -1,   588,   328,    -1,    -1,
      -1,   619,   442,    -1,    -1,   336,    -1,    -1,   600,   601,
      -1,    -1,    -1,    -1,    -1,    -1,   608,   483,    -1,   611,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,   495,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   483,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,   399,   202,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,    -1,
     576,    -1,    -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,
      -1,    -1,   588,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,   600,   601,   576,    -1,    -1,    -1,
      -1,    -1,   608,    -1,    -1,   611,    -1,    -1,   588,    -1,
     283,    -1,    -1,   619,    -1,    -1,    -1,    -1,    -1,   292,
     600,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,
      -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,   331,    -1,
      -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   344,    -1,    -1,    -1,    -1,    -1,   548,   549,   550,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     561,    -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,   408,    -1,
      -1,    -1,    -1,    -1,    -1,   415,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   664,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,    -1,   479,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   489,   490,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   479,
      -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,   489,
     490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   527,   505,    -1,   530,   531,    -1,
      -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,
     530,   531,    -1,    -1,    -1,    -1,   536,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,
      -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   604
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    46,    47,    75,   122,   123,   125,   126,   130,
     147,   148,   165,   235,   355,   404,   436,   725,   753,   754,
     804,   970,  1025,  1027,  1028,  1029,  1034,  1036,  1049,  1050,
    1051,  1052,  1053,  1468,    28,    29,   726,   727,   728,   729,
     730,    27,   936,  1487,   354,   533,   547,   572,   620,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,   936,    25,   936,
    1389,  1054,   755,   754,  1468,     0,  1026,  1029,  1034,  1052,
    1468,    31,   728,   730,   936,  1471,   589,   936,  1470,   625,
     805,    25,   189,   752,   753,   924,   936,   941,  1055,  1090,
    1091,  1092,  1093,  1094,  1098,   352,   757,   758,   759,   760,
     763,   764,    55,    60,   105,   106,   113,   366,   392,   463,
     557,   637,   645,   725,   731,   896,   969,  1030,  1031,  1033,
    1037,  1038,  1044,  1056,  1077,  1209,  1219,  1468,   936,  1470,
     616,  1093,   241,   456,   457,  1100,    21,   936,  1097,   619,
     758,     5,   756,   352,   936,     5,   780,   782,   783,   936,
    1220,   936,   936,  1210,  1045,   936,   936,  1033,  1039,   259,
     298,   317,   356,   368,   378,   396,   406,   422,   462,   486,
     501,   508,   511,   532,   535,   537,   556,   574,   806,   807,
     808,   811,    25,  1090,  1096,    18,    19,    26,   429,   675,
     677,  1090,  1101,  1102,   457,    14,   803,   760,   521,  1196,
     761,   758,   763,    32,    80,    81,    89,   259,   298,   317,
     333,   356,   368,   378,   396,   406,   422,   462,   486,   501,
     508,   511,   532,   535,   537,   556,   574,   616,   766,   774,
     785,   786,   936,   429,   112,   936,   752,   897,  1078,   936,
     813,   535,   765,   789,   791,   792,   790,   799,   800,   429,
     429,   812,   457,   429,   429,   758,   787,   424,   675,    18,
      19,    20,    21,    22,   676,    26,     5,   425,  1101,    24,
      25,    26,   619,   936,   942,    19,    25,    26,   762,   942,
     776,   765,   777,   789,   790,   429,   429,   775,   457,   429,
     429,   787,   758,   784,   429,    26,   936,   429,  1046,   752,
     752,   429,   936,   429,   456,   769,   625,   365,   452,   469,
     512,   552,   581,   590,   793,   625,   365,   452,   469,   512,
     552,   581,   590,   801,    26,    26,   814,   815,   816,   817,
     936,    26,   772,   773,    26,    26,   619,   390,   675,  1102,
     457,   425,    26,    26,   758,   769,   758,    26,    26,   757,
     772,    26,    26,   619,    58,   781,  1221,   390,   429,  1211,
    1488,  1489,  1490,  1491,  1492,   898,  1079,  1040,   619,    26,
     794,   795,   429,   796,   801,   802,   796,   429,   797,     5,
     390,     5,   390,     5,   282,     5,   806,   425,     5,     5,
     390,   390,   758,   788,  1101,   457,   619,    26,   257,     5,
     390,     5,   390,   282,   425,     5,   390,   390,   788,   936,
    1107,  1108,  1110,  1057,  1107,   360,  1489,  1196,    45,    54,
      66,    67,    69,    83,    90,   101,   102,   103,   117,   119,
     120,   121,   124,   127,   129,   131,   132,   138,   141,   143,
     144,   145,   153,   155,   156,   158,   160,   161,   164,   168,
     169,   170,   172,   173,   177,   178,   180,   184,   186,   187,
     192,   196,   199,   201,   203,   205,   207,   208,   210,   211,
     212,   216,   218,   219,   221,   229,   230,   242,   245,   246,
     249,   250,   253,   254,   262,   263,   264,   266,   276,   277,
     278,   280,   284,   285,   289,   297,   305,   306,   307,   313,
     314,   319,   322,   326,   327,   337,   355,   363,   369,   399,
     401,   402,   410,   449,   460,   464,   468,   492,   493,   497,
     509,   515,   516,   517,   518,   522,   526,   533,   534,   545,
     547,   558,   560,   563,   569,   595,   598,   603,   606,   607,
     621,   628,   651,   652,   653,   654,   655,   656,   657,   660,
     662,   664,   668,   669,   670,   671,   688,   710,   724,   725,
     731,   732,   751,   819,   820,   821,   822,   833,   834,   835,
     836,   888,   892,   922,   943,   944,   947,   948,   949,   950,
     963,   971,   992,   993,   995,   999,  1016,  1017,  1021,  1022,
    1023,  1024,  1032,  1047,  1060,  1071,  1072,  1073,  1084,  1087,
    1123,  1126,  1128,  1134,  1135,  1138,  1141,  1144,  1146,  1148,
    1150,  1157,  1162,  1166,  1167,  1168,  1180,  1181,  1184,  1190,
    1191,  1192,  1217,  1232,  1233,  1234,  1235,  1236,  1241,  1247,
    1248,  1266,  1269,  1299,  1301,  1390,  1391,  1422,  1423,  1430,
    1441,  1468,  1472,  1477,  1479,  1481,  1485,  1486,  1493,   725,
    1035,  1468,   624,   647,  1080,  1081,  1107,    21,   390,   424,
     770,   793,    26,   798,    26,    26,    26,   815,   817,   809,
     773,    26,   425,  1101,    21,   770,   429,    26,    26,   767,
      26,   619,   390,     5,  1107,   390,   936,   348,   937,   938,
    1487,   936,   936,  1164,   931,   937,   931,    25,   189,   936,
    1099,  1463,  1464,  1465,   936,  1483,   936,  1243,  1244,   936,
      26,   672,  1090,  1239,   931,  1164,   862,    26,   942,  1204,
    1205,  1204,     9,    18,    19,    25,    26,    59,    64,    71,
      99,   191,   288,   293,   321,   356,   368,   386,   391,   394,
     405,   411,   421,   426,   429,   432,   441,   442,   483,   487,
     495,   506,   512,   537,   581,   588,   590,   600,   601,   608,
     837,   844,   845,   846,   847,   848,   849,   850,   851,   863,
     868,   879,   880,   881,   882,   936,   942,  1090,  1199,  1268,
    1381,   937,  1431,  1431,   823,  1164,   931,  1237,  1090,   933,
     937,   844,  1431,  1090,  1164,  1090,  1267,  1431,    25,   585,
    1074,  1075,  1090,   931,   931,  1074,   932,   937,   936,  1075,
     931,  1431,   931,   933,  1090,  1121,  1122,   929,   937,   933,
     373,   561,   666,   928,   936,   994,   936,   733,   934,   937,
      25,  1300,  1463,   862,   862,   937,  1147,   893,   128,   137,
     146,   151,   194,   202,   258,   283,   290,   292,   302,   328,
     336,   373,   399,   437,   448,   548,   549,   550,   561,   664,
    1008,  1142,  1143,  1090,   843,   844,  1156,   839,   862,   928,
    1478,  1478,   930,   937,   862,    25,  1090,  1145,  1218,  1090,
    1195,    25,  1090,  1425,   844,  1186,  1187,  1188,  1197,  1198,
     844,  1473,   104,   154,   191,   288,   364,   405,   473,   537,
     689,   868,   936,  1090,  1227,   712,   844,   929,  1470,  1061,
     844,   929,   844,  1090,  1018,   929,   844,  1442,   844,  1204,
     936,   945,   946,   933,   945,  1478,   933,   945,  1478,   951,
     945,    25,    26,   383,   486,   942,   997,  1090,  1109,  1111,
      65,   273,   343,   388,   568,   648,   649,   650,   659,   679,
     953,   955,   957,   959,   961,  1085,  1086,  1089,   334,   345,
     397,   412,   502,  1302,   639,   640,   900,   901,   902,   936,
    1082,   646,  1081,   390,   301,   390,   390,   390,   390,   623,
       5,   390,   425,   301,   758,   778,   779,   390,   390,   623,
     390,   936,  1222,  1110,   390,  1212,    56,    57,    84,    85,
      86,   453,   541,   584,  1249,  1250,  1251,  1254,  1257,  1260,
    1261,  1262,  1263,   429,   619,  1465,  1100,   616,  1139,   619,
       8,   538,   587,     5,   390,   425,    25,   936,  1374,   478,
    1165,  1109,   108,   109,   110,   837,   837,   837,   429,   525,
    1216,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     837,   365,   452,   469,   512,   552,   581,   590,  1384,  1385,
     429,   429,   429,   837,   837,   429,   429,   749,   837,   429,
     852,   429,   429,   429,   429,   429,   429,   429,   429,     6,
       7,     8,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    35,    92,    93,    94,    95,
      96,    97,   108,   109,   110,   248,   251,   370,   385,   389,
     427,   455,   474,   556,   622,   748,   838,   853,   855,   856,
     857,   858,   859,   860,   861,    26,   942,   429,   520,   419,
    1090,  1116,  1374,   678,   679,   826,   265,    87,    88,   625,
     458,     5,   618,   625,   617,   617,  1124,   595,   419,     5,
     556,   972,   458,   658,  1475,   429,   457,   619,   658,   383,
     735,  1090,   546,   617,  1129,  1130,  1131,   325,  1298,   842,
     844,   842,     8,   930,    26,   500,   554,   923,  1090,   923,
     923,   923,  1013,  1014,   923,   923,   596,  1009,   679,  1009,
    1009,   924,   924,  1009,  1009,   679,     5,   332,   384,     5,
     678,   482,   840,   841,   844,     5,    76,    82,   539,   626,
    1000,   661,  1476,   843,   612,   613,   614,   615,  1194,  1196,
     382,  1231,  1196,  1188,     5,   617,  1189,   844,   429,   429,
     429,   429,    25,   708,   936,   429,  1425,   343,   429,   520,
     589,   578,   713,   720,   711,    25,  1076,  1090,  1182,     8,
    1185,    14,   936,  1095,  1103,  1104,  1106,  1114,  1115,  1158,
     162,   343,   544,   577,    33,   189,   553,  1443,  1444,  1445,
    1446,   575,     5,   658,   658,   842,  1109,  1116,   996,   419,
       5,   150,   976,   429,  1090,   842,   429,    26,    26,    65,
    1088,    25,  1090,  1429,  1429,   937,  1282,  1147,   930,   118,
     220,   228,   234,   236,   247,   275,   291,   296,   308,   315,
     470,   477,   499,   504,  1270,  1271,  1279,  1289,  1290,  1296,
    1297,  1303,  1304,  1313,  1332,  1336,  1401,  1402,  1432,  1433,
    1436,  1437,  1447,   903,   904,    91,   899,   910,   911,   902,
    1083,  1488,  1041,   457,   806,   773,   457,     5,   390,   780,
     752,  1058,   752,   157,   295,   371,   429,   475,   491,  1319,
    1331,   429,   936,  1265,    26,   244,   257,   429,   475,   491,
     936,  1246,  1259,  1317,  1318,  1323,  1325,  1327,   429,   936,
    1256,   429,  1246,  1252,     5,    25,   939,  1093,  1465,  1463,
     576,   616,  1140,    21,   936,  1120,  1466,   936,  1484,  1244,
     595,   619,   589,   429,   429,   826,  1478,   837,   928,   928,
    1478,  1478,   470,  1405,   837,    25,    26,    19,    24,    25,
      26,   883,   884,   885,   886,   837,   429,   625,  1478,    21,
     837,   390,  1405,   837,    21,  1199,   871,   869,   875,   837,
     873,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   429,   837,   837,   429,   864,   936,  1090,
     625,   429,  1463,    25,   941,  1163,  1163,  1425,  1074,   844,
     844,   844,   925,   926,   429,  1090,  1122,   787,   973,   974,
     625,  1425,  1478,  1476,   936,   675,    21,   666,   936,   994,
    1090,   734,   624,   844,   349,  1133,   556,  1132,     5,    68,
      70,    72,   617,   625,   818,  1109,   894,    18,    19,    25,
     303,   309,   310,   311,   329,   437,   440,   464,   484,   519,
     539,   540,   550,   555,   594,   626,  1015,  1010,  1143,   924,
     844,   343,   595,     5,   928,    26,    26,   678,   152,  1193,
     217,  1198,  1204,  1474,   936,    25,   887,   928,  1478,   589,
     928,   622,  1090,   693,   936,   936,   844,   338,   716,   720,
     578,   714,   722,    23,   233,  1063,  1067,   481,   862,   481,
    1183,   844,   456,  1100,   619,     5,  1019,   546,  1159,  1090,
    1464,  1467,  1090,  1112,  1113,   188,  1444,   964,   946,  1478,
    1478,   956,   957,   976,   976,    34,    36,    37,    38,   269,
     272,   274,   294,   304,   346,   350,   428,   975,   977,   978,
    1004,  1090,  1111,   546,   680,    26,   398,   962,   320,  1424,
    1424,   135,   136,   435,   546,   936,  1333,  1334,  1375,   787,
    1374,  1374,  1272,   787,   936,  1434,  1434,   358,   475,   585,
    1413,  1374,  1280,   167,   437,   448,   470,   477,  1306,  1307,
    1308,   286,   287,  1396,  1488,  1488,   383,   912,  1090,   641,
     642,   905,   906,   907,   480,   624,   643,   644,   663,   915,
     916,  1488,   752,    26,   771,   771,   779,  1223,   752,  1213,
    1321,  1374,  1264,  1331,   429,  1264,   429,   429,  1258,  1259,
     429,   429,    63,   298,   356,   368,   378,   396,   406,   409,
     422,   471,   501,   511,   532,   535,   537,   565,   574,  1366,
    1367,  1368,  1370,  1255,  1256,  1252,  1253,   663,  1250,   390,
     619,  1425,   576,   457,   546,  1482,   673,   674,   936,   936,
     936,  1240,   862,   390,   390,   390,   390,   390,  1413,   390,
     390,   390,   390,   589,   884,    19,    26,   589,   390,   390,
      26,  1385,   390,   390,   390,   390,     5,   750,   390,   837,
     837,   837,   390,   837,   390,   390,   390,   440,   440,   440,
     862,  1405,   440,   862,  1405,   705,   706,   707,   837,   429,
     936,  1238,   616,  1136,   625,     5,     5,     5,   579,   844,
     619,     5,   482,   625,   390,   425,   429,   624,   163,   166,
     269,   272,   736,   739,   740,  1004,   737,   738,   936,   429,
     937,   648,   649,  1137,   844,   936,   936,   926,   927,   508,
    1478,   826,   553,  1286,    26,    26,   429,  1011,  1013,  1090,
     535,  1151,   840,    65,   837,  1196,    26,  1090,  1488,     5,
       5,     5,   390,   390,   709,   936,   390,  1425,   705,   429,
     429,   721,   717,   359,   715,   844,   338,   718,   722,   596,
    1006,  1068,  1064,   361,  1062,  1063,   842,   625,  1096,    21,
     936,  1105,  1115,    14,    18,    19,    21,    25,    26,    64,
     394,   409,   426,   429,   442,   482,   483,   495,   537,   576,
     588,   600,   601,   608,   611,   936,   942,  1160,  1161,  1380,
    1382,  1412,  1417,  1418,  1419,  1467,   419,   419,     5,  1488,
     958,   959,   550,   935,   546,   987,   986,   989,   988,   928,
     990,   928,   991,   985,   984,   982,   981,  1005,   323,   978,
     983,  1478,    39,    40,    41,    42,    43,    44,    98,   331,
     344,   408,   415,   454,   479,   489,   490,   495,   505,   527,
     530,   531,   536,   593,   604,   681,   682,  1002,  1003,     5,
      26,  1425,   247,  1090,   470,  1406,  1407,  1425,  1147,  1400,
    1402,   100,   100,   595,  1145,  1335,  1336,   429,  1314,   149,
     525,  1340,  1347,  1374,   174,   270,  1438,   619,   625,  1403,
    1448,   340,   349,   373,   376,   394,   500,   554,   561,   930,
    1283,  1288,   429,  1309,   624,     5,    25,   936,  1397,  1398,
     914,  1090,     5,   546,   908,   909,   638,   907,   913,   936,
     913,   917,   918,   913,   323,   916,  1042,   425,   425,   459,
    1206,  1226,  1059,   459,  1169,  1200,   429,     5,   390,     9,
     293,   429,   441,  1350,  1351,  1352,  1353,  1354,  1358,  1362,
    1364,  1417,   390,   611,   936,  1320,  1322,  1374,  1377,  1378,
    1324,  1377,     5,   390,  1324,  1350,   365,   452,   469,   512,
     552,   581,   590,  1387,  1387,   429,   429,   429,   429,   429,
     429,   206,   398,  1326,  1328,     5,   390,     5,   390,   936,
    1466,     8,  1425,  1101,   844,     5,  1245,  1246,   862,  1048,
    1414,  1415,  1417,   877,  1385,   877,    26,    26,   589,    24,
      26,   790,   878,  1216,   390,  1216,   791,   390,  1216,   872,
     870,   876,  1216,   874,  1216,  1216,  1216,    25,    25,    25,
     837,   854,   390,    25,   854,   390,   865,     5,   866,   619,
    1245,   576,  1425,  1425,   844,   844,   925,   508,   844,  1480,
       5,    21,  1377,   974,  1425,   619,   936,   737,   745,   744,
     746,   936,   940,   747,   940,   190,   740,   743,     5,   976,
     619,   844,     8,   936,  1287,   895,  1012,  1013,  1090,     5,
     324,    25,  1228,   928,   343,   343,   457,   619,   343,   429,
     694,   698,   691,  1488,  1488,   723,   719,   715,  1007,    25,
     935,  1069,  1090,  1488,   844,   424,   457,   862,  1418,  1418,
    1383,  1387,   470,  1417,   429,   429,   429,   429,   429,   429,
     429,   936,   429,     5,    18,    19,    20,    21,    92,    93,
      94,    95,    96,    97,  1439,  1464,  1090,  1113,    62,   542,
     965,   960,   961,    26,   678,   936,  1488,  1488,  1488,  1488,
       5,   979,     5,   980,  1488,  1488,  1488,  1488,  1011,  1488,
     935,    25,    14,    14,     5,   390,    26,  1374,  1413,  1394,
     595,   595,  1271,  1399,  1400,  1336,  1315,  1377,   616,   930,
    1350,   429,  1275,   936,  1435,  1434,  1414,    48,    49,    50,
      51,    52,   583,  1451,   844,   844,  1281,   930,  1310,  1377,
    1374,  1308,   619,   619,     5,     5,  1090,   913,  1488,  1488,
       5,   920,   921,  1488,  1488,   919,  1035,   810,   768,    73,
      74,    77,    78,    79,   176,   183,   217,   226,   255,   256,
     300,   342,   398,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,  1203,  1207,   134,   513,  1208,  1224,  1035,
     159,   175,   176,   183,   217,   226,   255,   300,   342,  1201,
    1202,  1214,  1208,  1322,  1331,  1353,   429,  1412,  1350,  1417,
    1412,     6,   390,     7,     9,    10,    12,    13,    14,    15,
      16,    17,   251,   370,   427,   556,   622,  1361,  1363,  1378,
     457,  1376,   390,     5,   619,     5,   390,  1259,   390,   390,
     625,   429,   625,    26,  1372,  1372,    26,  1372,  1372,    26,
    1371,    25,  1380,  1329,  1330,  1331,  1256,  1252,  1425,     8,
     425,   674,     5,   390,   842,   390,     5,   546,  1341,  1346,
     936,   625,   390,    26,   589,   625,   390,   390,   390,   390,
       5,   390,   390,   390,   707,   705,    21,   390,  1425,     5,
     844,   566,   273,   683,   684,   844,    21,   936,   390,   976,
    1488,  1488,     5,   741,   457,   619,     5,   742,  1488,   738,
     546,    21,   936,     5,   936,  1127,   388,   658,  1112,  1488,
       5,   390,   935,   837,     5,   705,  1090,   690,   672,   936,
    1090,   696,   390,   705,   705,  1488,  1488,  1011,  1066,    25,
    1070,  1090,   571,   891,  1101,   482,   843,  1020,   625,  1413,
     390,   394,  1440,  1467,   358,   475,   585,  1365,  1417,  1420,
    1365,  1365,  1365,  1365,   619,  1420,  1161,  1417,  1417,  1417,
    1417,   967,   966,   439,   952,   953,   619,   928,  1488,   928,
    1488,   678,    26,  1090,    26,  1090,   682,   390,   429,  1426,
    1414,  1396,  1400,  1400,  1392,     5,   390,   470,  1411,  1276,
    1377,   478,  1273,  1411,   625,  1404,    18,    19,    64,   426,
     429,   442,   482,   483,   495,   537,   576,   588,   600,   601,
     608,   611,   936,  1380,  1412,  1456,  1457,  1458,  1459,  1460,
    1461,  1467,  1456,  1456,  1456,  1377,  1453,  1455,  1452,  1453,
    1454,  1449,   553,  1284,     5,   390,   625,   936,   936,  1398,
    1090,   936,  1488,  1488,  1488,  1488,   623,   623,  1204,  1204,
    1204,    25,  1204,  1204,  1204,  1204,  1204,  1204,    25,    25,
    1204,  1207,  1090,  1117,  1118,   618,   445,  1170,  1488,    25,
      25,    26,    26,    26,    26,    26,    25,  1090,  1202,  1170,
     390,   390,  1351,  1352,  1356,  1418,   429,  1412,  1356,   429,
    1412,    10,   248,   385,   387,  1417,    26,  1319,  1377,    21,
     936,  1377,   365,   452,   469,   512,   552,   581,   590,  1388,
      26,  1388,     5,  1369,  1369,     5,   390,   390,  1369,   390,
    1331,  1425,  1246,   267,  1242,  1415,   514,  1342,  1343,  1344,
    1374,  1347,   330,   513,   524,  1291,  1408,   365,   452,   469,
     512,   552,   581,   590,  1386,   877,   589,    24,    26,   794,
     837,   867,   467,   825,     5,   372,  1425,     5,   429,   390,
     550,  1001,   940,  1488,   675,    21,   936,   940,  1488,  1478,
     844,  1478,   239,  1013,   678,    25,  1229,  1109,   425,   705,
     695,   699,   390,  1488,   935,   844,   889,   425,  1388,  1414,
       5,  1387,   390,     5,  1417,     5,   390,  1417,  1417,  1417,
    1417,   936,   390,   844,  1488,   954,   955,    21,   936,  1427,
    1428,   553,  1410,  1395,  1393,  1396,  1377,  1413,   139,  1316,
       5,   390,  1274,  1435,  1410,  1459,  1459,  1458,   429,   429,
     429,   429,   429,   429,   429,   936,   429,     5,   390,    18,
      19,    20,    21,  1439,   390,     5,   390,     5,    14,   149,
     525,  1450,  1285,  1377,   461,  1311,  1312,  1375,   619,   209,
    1043,   806,   780,   538,   587,  1119,     5,  1117,    61,   133,
     198,   200,   215,   223,   227,   252,  1171,  1172,  1225,  1043,
    1215,   440,  1355,  1359,  1360,  1380,  1467,  1355,  1359,  1356,
    1417,     5,   425,  1376,   390,    26,  1373,   390,   390,    26,
     390,   429,  1344,     5,   936,  1379,   367,  1338,  1348,   936,
    1409,   618,  1365,   330,   429,    24,    26,   390,   928,   678,
     372,  1425,   844,   685,   568,  1125,    26,   678,   425,  1001,
     390,  1149,   390,   390,   429,   697,   343,   703,   390,   692,
    1065,  1488,   457,  1346,  1387,   625,  1387,   390,  1417,   390,
     390,   390,   390,   575,   935,     5,   390,  1112,  1346,  1396,
    1396,  1414,  1377,   429,  1346,   390,  1440,  1365,  1458,  1462,
    1365,  1365,  1365,  1365,   619,  1462,  1457,  1458,  1458,  1458,
    1458,  1453,    14,  1454,  1457,   930,  1350,  1112,     5,   140,
    1305,   936,  1118,  1173,  1174,  1090,  1176,  1090,  1175,  1177,
    1172,   238,   238,  1357,  1380,  1421,     5,   390,   390,  1355,
       7,    26,   625,   390,  1343,  1345,  1343,  1339,  1416,  1417,
     446,  1337,  1349,  1242,    26,  1292,  1293,  1294,  1377,  1406,
    1409,    26,   824,  1425,   391,   202,   258,   283,   292,   328,
     336,   430,   602,   682,   686,   687,   429,   619,   678,  1004,
    1152,  1153,  1154,  1230,   700,   390,  1109,   703,   703,  1488,
     890,  1101,   390,   625,  1388,   625,   968,   998,  1428,  1408,
    1346,   482,  1277,  1278,  1417,  1408,   390,  1458,     5,   390,
    1458,  1458,  1458,  1458,   936,   390,   429,  1312,  1488,  1488,
    1178,  1488,  1179,  1488,  1488,  1360,  1417,   425,  1388,     5,
     390,     5,  1350,     5,   538,   587,  1295,  1242,   390,   346,
     350,   827,   828,   829,  1004,   923,   923,   923,   923,   923,
     923,    25,     5,   390,   844,    21,   936,  1155,   281,  1154,
     703,   705,   703,   240,   425,  1388,  1388,  1488,   678,     5,
     390,   390,  1458,   390,   390,   390,   390,  1456,  1488,  1488,
    1343,  1416,  1293,   831,   830,   237,   829,   832,   687,     5,
    1488,   701,   965,  1278,   390,  1488,  1488,  1488,   844,   390,
     390,   702,   162,   343,   704,  1109
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
#line 927 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 930 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 934 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 940 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 945 "fgl.yacc"
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
#line 957 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 962 "fgl.yacc"
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
#line 985 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 986 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 987 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 988 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 989 "fgl.yacc"
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
#line 1003 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 1004 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 1005 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 1006 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 1007 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1012 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1013 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1024 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1027 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1030 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1030 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1037 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1038 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1044 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1045 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1046 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1047 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1049 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1051 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1052 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1053 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1055 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1056 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1058 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1059 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 46:
#line 1060 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1067 "fgl.yacc"
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

  case 50:
#line 1078 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1083 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1087 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1093 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1095 "fgl.yacc"
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
#line 1106 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1108 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1110 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1112 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1116 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1118 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1179 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1183 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1187 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1190 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 66:
#line 1193 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1197 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1201 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1204 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1210 "fgl.yacc"
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
#line 1219 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1223 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1228 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1232 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1240 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1244 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1248 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1250 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1256 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1261 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1264 "fgl.yacc"
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
#line 1280 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1287 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1291 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1295 "fgl.yacc"
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
#line 1317 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1317 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1321 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1322 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1323 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1328 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1331 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1337 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1340 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1352 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1358 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1361 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1376 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1386 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1392 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1401 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1414 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1417 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1419 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1425 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1427 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1432 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1437 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1443 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1447 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1462 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1465 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1468 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1471 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1474 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1477 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1499 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1508 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1518 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1532 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1536 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1539 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1547 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1553 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1568 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1572 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1577 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1587 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1590 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1594 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1596 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1599 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1601 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1604 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1606 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1609 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1612 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1622 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1623 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1631 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1632 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1649 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1652 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1655 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1658 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1661 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1664 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1673 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1681 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1686 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1699 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1703 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1718 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1719 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1727 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1727 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1737 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1737 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1746 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1747 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1748 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1751 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1756 "fgl.yacc"
    { }
    break;

  case 194:
#line 1756 "fgl.yacc"
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
#line 1773 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1777 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1791 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1800 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1804 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1820 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1822 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1823 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1830 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1830 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1831 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1832 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1835 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1837 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1847 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1862 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1862 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1868 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1869 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1876 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1877 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1878 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1879 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1882 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1883 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1884 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1885 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1889 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1894 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1899 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1903 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1906 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1910 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1911 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1912 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1913 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1914 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1915 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1916 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1917 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1920 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1921 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1922 "fgl.yacc"
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
#line 1954 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1958 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1960 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1962 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1964 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1969 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1973 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1973 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1977 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1978 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1979 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1980 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1981 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1982 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1984 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 1989 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 1989 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 1992 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 1994 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 2000 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 2002 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2008 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2016 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2016 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2019 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2020 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2021 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2022 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2023 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2024 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2026 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2047 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2056 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2058 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2060 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2062 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2063 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2064 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2065 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2066 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2071 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2078 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2083 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2085 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2087 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2088 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2089 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2090 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2091 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2092 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2093 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2096 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2098 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2104 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2112 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2120 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2124 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2132 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2133 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2134 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2135 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2154 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2166 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2170 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2173 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2176 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2177 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2178 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2179 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2180 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2186 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2193 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2198 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2203 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2207 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2210 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2218 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2220 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2225 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2237 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2240 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2243 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2246 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2249 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2252 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2265 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2268 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2283 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2285 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2287 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2289 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2291 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2293 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2294 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2301 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2303 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2307 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2309 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2311 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2313 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2315 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2317 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2319 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2325 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2339 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2342 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2359 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2365 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2369 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2374 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2384 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 402:
#line 2391 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2398 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2398 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2403 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 407:
#line 2407 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2413 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2421 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2427 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2436 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2438 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2445 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2453 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2457 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2466 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2471 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2476 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2480 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2482 "fgl.yacc"
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
#line 2492 "fgl.yacc"
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
#line 2506 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2514 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2526 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2532 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2538 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2548 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2554 "fgl.yacc"
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
#line 2626 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2632 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2636 "fgl.yacc"
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
#line 2644 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2644 "fgl.yacc"
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
#line 2660 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2664 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2670 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2673 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2681 "fgl.yacc"
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
#line 2692 "fgl.yacc"
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
#line 2702 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2708 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2718 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2723 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2730 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2733 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2736 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2741 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2748 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2753 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2758 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2763 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2774 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2782 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2790 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2795 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2799 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2804 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2808 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2812 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2818 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2821 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2825 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2829 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2833 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2837 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2841 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2848 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2858 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2863 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2869 "fgl.yacc"
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
#line 2879 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2884 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2887 "fgl.yacc"
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

  case 476:
#line 2901 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 477:
#line 2901 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2901 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 479:
#line 2904 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 480:
#line 2904 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2904 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 482:
#line 2907 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 483:
#line 2907 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 485:
#line 2910 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 486:
#line 2910 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 488:
#line 2913 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2919 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2925 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2931 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2941 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2942 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2950 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_inp_io,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 497:
#line 2957 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2958 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 499:
#line 2964 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_inp_io,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 500:
#line 2969 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_inp_io,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 501:
#line 2979 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_inp_io,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 504:
#line 2992 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 2997 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 3004 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 3008 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3011 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3014 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3020 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3023 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3026 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3043 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3046 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3052 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3053 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3054 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3059 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3060 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3061 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3062 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3064 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3065 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3066 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3068 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3069 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3075 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3080 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3092 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 533:
#line 3096 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 534:
#line 3097 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 535:
#line 3104 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 537:
#line 3121 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 538:
#line 3125 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 539:
#line 3130 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 540:
#line 3134 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 541:
#line 3150 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 542:
#line 3156 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 543:
#line 3164 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 550:
#line 3181 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 551:
#line 3183 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 552:
#line 3186 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 553:
#line 3188 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 558:
#line 3202 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 559:
#line 3204 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3207 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 561:
#line 3209 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3240 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 575:
#line 3242 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3245 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 577:
#line 3247 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3250 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 579:
#line 3252 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3255 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 581:
#line 3257 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3260 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 583:
#line 3262 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3277 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 585:
#line 3293 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 586:
#line 3294 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 587:
#line 3295 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 588:
#line 3296 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 589:
#line 3297 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 590:
#line 3298 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 594:
#line 3306 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 596:
#line 3312 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 597:
#line 3314 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 598:
#line 3315 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 599:
#line 3317 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 600:
#line 3319 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 601:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 602:
#line 3323 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 603:
#line 3325 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3328 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 605:
#line 3335 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 606:
#line 3337 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 607:
#line 3343 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 608:
#line 3348 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3353 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3358 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 611:
#line 3358 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 612:
#line 3361 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 613:
#line 3367 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 614:
#line 3372 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 615:
#line 3376 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 618:
#line 3384 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 619:
#line 3386 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 620:
#line 3388 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 621:
#line 3390 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 622:
#line 3392 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 623:
#line 3394 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3397 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 626:
#line 3406 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 627:
#line 3468 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 628:
#line 3481 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 630:
#line 3488 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 631:
#line 3491 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 632:
#line 3497 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 633:
#line 3503 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 634:
#line 3507 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 635:
#line 3511 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3517 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 637:
#line 3521 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 638:
#line 3525 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3530 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 640:
#line 3535 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 659:
#line 3576 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 660:
#line 3581 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 662:
#line 3586 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 664:
#line 3589 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 665:
#line 3591 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 666:
#line 3594 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 667:
#line 3598 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 668:
#line 3601 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 669:
#line 3607 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 670:
#line 3618 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 671:
#line 3619 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 672:
#line 3622 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 674:
#line 3628 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 675:
#line 3632 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 676:
#line 3633 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 679:
#line 3647 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 680:
#line 3649 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 683:
#line 3658 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 684:
#line 3660 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 685:
#line 3664 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 686:
#line 3666 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 687:
#line 3669 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 688:
#line 3671 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3674 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 690:
#line 3677 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 691:
#line 3680 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 692:
#line 3682 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 693:
#line 3685 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 694:
#line 3687 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 695:
#line 3690 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 696:
#line 3692 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 697:
#line 3695 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 698:
#line 3697 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 699:
#line 3698 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 700:
#line 3700 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 701:
#line 3701 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 702:
#line 3703 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3704 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 704:
#line 3706 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3746 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 706:
#line 3747 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 707:
#line 3755 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 708:
#line 3756 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 709:
#line 3765 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 710:
#line 3770 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 711:
#line 3775 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 712:
#line 3776 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 714:
#line 3781 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 715:
#line 3784 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 716:
#line 3792 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 717:
#line 3797 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 718:
#line 3801 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 719:
#line 3808 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 720:
#line 3817 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 721:
#line 3822 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 722:
#line 3823 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 723:
#line 3824 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 724:
#line 3825 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 725:
#line 3828 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 727:
#line 3831 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 728:
#line 3838 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 729:
#line 3839 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 730:
#line 3840 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 731:
#line 3841 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 732:
#line 3842 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3843 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 734:
#line 3844 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 735:
#line 3845 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 736:
#line 3846 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 737:
#line 3851 "fgl.yacc"
    {iskey=1;}
    break;

  case 738:
#line 3851 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 739:
#line 3853 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 740:
#line 3856 "fgl.yacc"
    {iskey=1;}
    break;

  case 741:
#line 3856 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 742:
#line 3858 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 743:
#line 3862 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 744:
#line 3862 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 745:
#line 3865 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 746:
#line 3866 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 748:
#line 3869 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 749:
#line 3874 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 750:
#line 3874 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 755:
#line 3881 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 756:
#line 3882 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 757:
#line 3883 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 758:
#line 3884 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 759:
#line 3885 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 760:
#line 3886 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 761:
#line 3887 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 762:
#line 3888 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 763:
#line 3889 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 764:
#line 3890 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 765:
#line 3891 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 766:
#line 3892 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 767:
#line 3893 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 768:
#line 3897 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 769:
#line 3915 "fgl.yacc"
    {chk4var=1;}
    break;

  case 770:
#line 3915 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 771:
#line 3918 "fgl.yacc"
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

  case 772:
#line 3942 "fgl.yacc"
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
#line 3960 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3966 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 3972 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 777:
#line 3978 "fgl.yacc"
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
#line 3989 "fgl.yacc"
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
#line 4012 "fgl.yacc"
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
#line 4028 "fgl.yacc"
    {
	}
    break;

  case 789:
#line 4051 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 793:
#line 4059 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 811:
#line 4085 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 812:
#line 4086 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 813:
#line 4094 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 814:
#line 4099 "fgl.yacc"
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
#line 4115 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 816:
#line 4121 "fgl.yacc"
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
#line 4136 "fgl.yacc"
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
#line 4149 "fgl.yacc"
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
#line 4159 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 821:
#line 4166 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 822:
#line 4173 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 823:
#line 4179 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 824:
#line 4179 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 825:
#line 4184 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 826:
#line 4189 "fgl.yacc"
    {
}
    break;

  case 832:
#line 4201 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 834:
#line 4209 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 835:
#line 4215 "fgl.yacc"
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
#line 4229 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 837:
#line 4233 "fgl.yacc"
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
#line 4246 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 840:
#line 4264 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 841:
#line 4272 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 842:
#line 4278 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 843:
#line 4289 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 844:
#line 4293 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 845:
#line 4300 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 846:
#line 4307 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 847:
#line 4313 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 848:
#line 4318 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 851:
#line 4325 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 852:
#line 4326 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 853:
#line 4328 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 854:
#line 4329 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 855:
#line 4332 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 856:
#line 4333 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 857:
#line 4334 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 858:
#line 4336 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 859:
#line 4341 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 860:
#line 4346 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 861:
#line 4353 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 865:
#line 4360 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 866:
#line 4362 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 867:
#line 4364 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 868:
#line 4373 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 869:
#line 4379 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 870:
#line 4383 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 873:
#line 4395 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 874:
#line 4400 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 875:
#line 4405 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 876:
#line 4408 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 878:
#line 4420 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 879:
#line 4423 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 880:
#line 4426 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 887:
#line 4442 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 888:
#line 4447 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 889:
#line 4447 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 890:
#line 4450 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4477 "fgl.yacc"
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

  case 893:
#line 4535 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 895:
#line 4542 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 896:
#line 4546 "fgl.yacc"
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

  case 897:
#line 4589 "fgl.yacc"
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

  case 901:
#line 4637 "fgl.yacc"
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
#line 4651 "fgl.yacc"
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
#line 4675 "fgl.yacc"
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

  case 908:
#line 4735 "fgl.yacc"
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

  case 909:
#line 4791 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 910:
#line 4796 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4804 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 912:
#line 4809 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 913:
#line 4817 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 914:
#line 4823 "fgl.yacc"
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

  case 915:
#line 4856 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 916:
#line 4859 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 917:
#line 4861 "fgl.yacc"
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

  case 918:
#line 4902 "fgl.yacc"
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

  case 923:
#line 4955 "fgl.yacc"
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

  case 924:
#line 5007 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 926:
#line 5014 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 927:
#line 5020 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 928:
#line 5031 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 929:
#line 5038 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 931:
#line 5046 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 932:
#line 5049 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 933:
#line 5050 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 935:
#line 5052 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 936:
#line 5053 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 5056 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 938:
#line 5059 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 939:
#line 5065 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 940:
#line 5068 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 941:
#line 5072 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 942:
#line 5076 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 5083 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 944:
#line 5088 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 945:
#line 5095 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 946:
#line 5098 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 951:
#line 5111 "fgl.yacc"
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

  case 952:
#line 5130 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 953:
#line 5137 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5144 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 955:
#line 5147 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 956:
#line 5161 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 961:
#line 5178 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 962:
#line 5183 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 963:
#line 5189 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 965:
#line 5196 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 966:
#line 5201 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 967:
#line 5204 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 968:
#line 5205 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 969:
#line 5208 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 970:
#line 5209 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 971:
#line 5212 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 972:
#line 5213 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 973:
#line 5218 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 974:
#line 5225 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 975:
#line 5228 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 976:
#line 5234 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 977:
#line 5236 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 978:
#line 5238 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 979:
#line 5240 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 980:
#line 5243 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 981:
#line 5243 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 982:
#line 5244 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 983:
#line 5249 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 984:
#line 5257 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 985:
#line 5258 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 986:
#line 5263 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 987:
#line 5265 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 988:
#line 5267 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 5284 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 993:
#line 5287 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 994:
#line 5290 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 995:
#line 5293 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 996:
#line 5297 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 997:
#line 5300 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 998:
#line 5303 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 999:
#line 5307 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5311 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5315 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1002:
#line 5318 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1003:
#line 5322 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1004:
#line 5325 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1005:
#line 5326 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5327 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1007:
#line 5330 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1008:
#line 5333 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1009:
#line 5336 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1010:
#line 5339 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1011:
#line 5342 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1012:
#line 5345 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1013:
#line 5348 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1014:
#line 5365 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1017:
#line 5375 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1018:
#line 5382 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1020:
#line 5403 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1021:
#line 5408 "fgl.yacc"
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
#line 5421 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1023:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1024:
#line 5427 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1025:
#line 5431 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1029:
#line 5437 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1030:
#line 5439 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1032:
#line 5454 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1033:
#line 5458 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1034:
#line 5464 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1035:
#line 5465 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1036:
#line 5468 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1037:
#line 5469 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1038:
#line 5472 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1040:
#line 5491 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1041:
#line 5496 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1042:
#line 5501 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1043:
#line 5506 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1049:
#line 5528 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1050:
#line 5535 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1051:
#line 5544 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1052:
#line 5550 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1053:
#line 5552 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1057:
#line 5563 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1058:
#line 5564 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1059:
#line 5566 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1060:
#line 5567 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1061:
#line 5569 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1062:
#line 5570 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1063:
#line 5572 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1064:
#line 5573 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1065:
#line 5575 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1066:
#line 5576 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1067:
#line 5577 "fgl.yacc"
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
#line 5591 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1069:
#line 5593 "fgl.yacc"
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
#line 5610 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1077:
#line 5622 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1078:
#line 5622 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1079:
#line 5628 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1080:
#line 5628 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1081:
#line 5631 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1082:
#line 5631 "fgl.yacc"
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
#line 5641 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1084:
#line 5642 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1085:
#line 5643 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1086:
#line 5650 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1087:
#line 5662 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1093:
#line 5673 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1094:
#line 5678 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1095:
#line 5682 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1096:
#line 5687 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1097:
#line 5693 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1098:
#line 5694 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1099:
#line 5695 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1100:
#line 5699 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1101:
#line 5700 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1102:
#line 5701 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1103:
#line 5702 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1104:
#line 5706 "fgl.yacc"
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
#line 5716 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1106:
#line 5718 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1107:
#line 5723 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1108:
#line 5726 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1109:
#line 5731 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1110:
#line 5738 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1111:
#line 5745 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1112:
#line 5752 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1113:
#line 5761 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1114:
#line 5768 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1115:
#line 5775 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1116:
#line 5782 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1117:
#line 5789 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1122:
#line 5802 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1123:
#line 5803 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1124:
#line 5804 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1125:
#line 5805 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5806 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5807 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1128:
#line 5808 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1129:
#line 5809 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1130:
#line 5810 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1131:
#line 5811 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1134:
#line 5817 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1135:
#line 5818 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1136:
#line 5819 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1137:
#line 5820 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1142:
#line 5829 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1143:
#line 5830 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1144:
#line 5831 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1145:
#line 5832 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1146:
#line 5833 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5834 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5835 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1149:
#line 5836 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5838 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1151:
#line 5839 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1152:
#line 5840 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1153:
#line 5841 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1154:
#line 5843 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1155:
#line 5844 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1156:
#line 5845 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1157:
#line 5846 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1161:
#line 5851 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1162:
#line 5852 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1166:
#line 5859 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1167:
#line 5866 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1168:
#line 5873 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1169:
#line 5884 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1170:
#line 5893 "fgl.yacc"
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
#line 5904 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1172:
#line 5908 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1173:
#line 5912 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1174:
#line 5918 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1175:
#line 5923 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1176:
#line 5931 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1177:
#line 5934 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1178:
#line 5943 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1179:
#line 5954 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1181:
#line 5961 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1182:
#line 5969 "fgl.yacc"
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
#line 5979 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1184:
#line 5982 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1185:
#line 5986 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1186:
#line 5994 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1187:
#line 5997 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1188:
#line 6003 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1189:
#line 6007 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1190:
#line 6011 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1191:
#line 6015 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1192:
#line 6019 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1193:
#line 6025 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1194:
#line 6026 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1195:
#line 6027 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1196:
#line 6028 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1197:
#line 6033 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1198:
#line 6035 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1199:
#line 6038 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1200:
#line 6042 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1201:
#line 6045 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1202:
#line 6052 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1203:
#line 6057 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1204:
#line 6058 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1205:
#line 6059 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1206:
#line 6064 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1207:
#line 6065 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1208:
#line 6071 "fgl.yacc"
    {insql=1;}
    break;

  case 1209:
#line 6071 "fgl.yacc"
    {insql=0;}
    break;

  case 1210:
#line 6071 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1211:
#line 6076 "fgl.yacc"
    {insql=1;}
    break;

  case 1212:
#line 6076 "fgl.yacc"
    {insql=0;}
    break;

  case 1213:
#line 6076 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1214:
#line 6087 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1215:
#line 6088 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1216:
#line 6094 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1217:
#line 6096 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1219:
#line 6109 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1220:
#line 6113 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1221:
#line 6114 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1223:
#line 6119 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1224:
#line 6122 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1225:
#line 6128 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1226:
#line 6131 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6139 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1229:
#line 6146 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1230:
#line 6153 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1231:
#line 6156 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1232:
#line 6165 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1233:
#line 6168 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1234:
#line 6171 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1235:
#line 6174 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1236:
#line 6177 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6180 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6183 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6190 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1240:
#line 6193 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1241:
#line 6200 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1242:
#line 6203 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1243:
#line 6209 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1244:
#line 6212 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1245:
#line 6219 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1246:
#line 6222 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1248:
#line 6230 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1250:
#line 6239 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1251:
#line 6242 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1252:
#line 6248 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1253:
#line 6251 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1254:
#line 6257 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1255:
#line 6264 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1256:
#line 6265 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1257:
#line 6269 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1258:
#line 6275 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1259:
#line 6278 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1261:
#line 6286 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1262:
#line 6293 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1267:
#line 6314 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1273:
#line 6320 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1274:
#line 6323 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1275:
#line 6326 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1276:
#line 6332 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1278:
#line 6338 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1280:
#line 6349 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1281:
#line 6363 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1282:
#line 6372 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1283:
#line 6372 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1284:
#line 6377 "fgl.yacc"
    {insql=1;}
    break;

  case 1285:
#line 6377 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1286:
#line 6382 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1287:
#line 6385 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6387 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6394 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6398 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1292:
#line 6402 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1293:
#line 6409 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 6412 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1295:
#line 6419 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1296:
#line 6423 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1297:
#line 6427 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1298:
#line 6432 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1299:
#line 6437 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1300:
#line 6441 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1301:
#line 6447 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1302:
#line 6451 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1303:
#line 6457 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1304:
#line 6464 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1305:
#line 6468 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1306:
#line 6473 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1307:
#line 6483 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1308:
#line 6486 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1309:
#line 6488 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1310:
#line 6490 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1311:
#line 6492 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1312:
#line 6494 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6496 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6498 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1315:
#line 6504 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1316:
#line 6514 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1317:
#line 6521 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1319:
#line 6527 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6536 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1326:
#line 6541 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1327:
#line 6546 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1328:
#line 6553 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1329:
#line 6554 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1330:
#line 6561 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1331:
#line 6572 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1332:
#line 6573 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1333:
#line 6576 "fgl.yacc"
    {insql=1;}
    break;

  case 1334:
#line 6576 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1335:
#line 6581 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1336:
#line 6586 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1338:
#line 6592 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1340:
#line 6596 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1341:
#line 6601 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1342:
#line 6606 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1343:
#line 6610 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1345:
#line 6616 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1346:
#line 6620 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1347:
#line 6628 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6631 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1349:
#line 6633 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1350:
#line 6638 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1353:
#line 6645 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1357:
#line 6652 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6655 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1359:
#line 6657 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6663 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6669 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6679 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1367:
#line 6684 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1368:
#line 6686 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6692 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1371:
#line 6695 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1373:
#line 6701 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1374:
#line 6709 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6714 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6724 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6730 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6736 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6738 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6744 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6749 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1386:
#line 6752 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1387:
#line 6755 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1388:
#line 6763 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6765 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1390:
#line 6778 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1391:
#line 6783 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6787 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1394:
#line 6789 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1395:
#line 6796 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1396:
#line 6799 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1397:
#line 6805 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1398:
#line 6809 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1399:
#line 6813 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1400:
#line 6817 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1401:
#line 6820 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1402:
#line 6828 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1403:
#line 6835 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1406:
#line 6844 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1407:
#line 6850 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1408:
#line 6853 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6864 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6871 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6877 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6880 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6887 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6894 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1416:
#line 6901 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1417:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1418:
#line 6908 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6909 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1421:
#line 6913 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6918 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1424:
#line 6925 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1425:
#line 6930 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1426:
#line 6931 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1427:
#line 6934 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1428:
#line 6937 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1429:
#line 6942 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1430:
#line 6943 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1431:
#line 6948 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1432:
#line 6951 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 6957 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 6960 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 6966 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1436:
#line 6969 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1437:
#line 6975 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 6978 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1439:
#line 6985 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1440:
#line 6986 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1441:
#line 7015 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1442:
#line 7017 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7021 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1445:
#line 7034 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1446:
#line 7037 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 7040 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1448:
#line 7043 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 7051 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 7054 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1453:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 7066 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1456:
#line 7069 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1457:
#line 7072 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1458:
#line 7075 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7078 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1460:
#line 7081 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7084 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1463:
#line 7091 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1468:
#line 7098 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1469:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1470:
#line 7104 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1471:
#line 7107 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7111 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7117 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7118 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1475:
#line 7119 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1476:
#line 7120 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1481:
#line 7140 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7145 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7146 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1485:
#line 7149 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7154 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7157 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7160 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7165 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7167 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7170 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1500:
#line 7171 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1501:
#line 7178 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7183 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1509:
#line 7199 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1510:
#line 7200 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1511:
#line 7204 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1512:
#line 7205 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1514:
#line 7224 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1515:
#line 7225 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1516:
#line 7226 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1517:
#line 7230 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1518:
#line 7233 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7239 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1520:
#line 7244 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1521:
#line 7249 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1523:
#line 7260 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1528:
#line 7275 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1529:
#line 7278 "fgl.yacc"
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

  case 1530:
#line 7291 "fgl.yacc"
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

  case 1531:
#line 7306 "fgl.yacc"
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

  case 1532:
#line 7318 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1533:
#line 7320 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1534:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1535:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1536:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1537:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1538:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1539:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1540:
#line 7324 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1541:
#line 7327 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1542:
#line 7332 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1543:
#line 7332 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1544:
#line 7332 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1545:
#line 7332 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1546:
#line 7332 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1547:
#line 7332 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1548:
#line 7334 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1549:
#line 7337 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1564:
#line 7346 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1565:
#line 7347 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1566:
#line 7351 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1567:
#line 7359 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1568:
#line 7359 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1569:
#line 7365 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1570:
#line 7365 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1571:
#line 7372 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1572:
#line 7372 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1573:
#line 7378 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1574:
#line 7378 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1575:
#line 7386 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1576:
#line 7387 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1577:
#line 7388 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1581:
#line 7395 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7396 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7401 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1584:
#line 7404 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1585:
#line 7410 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1586:
#line 7415 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1587:
#line 7424 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1588:
#line 7436 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1589:
#line 7437 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1590:
#line 7440 "fgl.yacc"
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
#line 7455 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1592:
#line 7465 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1593:
#line 7468 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1594:
#line 7476 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1595:
#line 7485 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1596:
#line 7488 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1597:
#line 7492 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1598:
#line 7495 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1599:
#line 7496 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1601:
#line 7505 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1602:
#line 7506 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1603:
#line 7515 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1604:
#line 7524 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1605:
#line 7529 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1606:
#line 7530 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1607:
#line 7531 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1608:
#line 7532 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1609:
#line 7539 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7542 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1611:
#line 7548 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7551 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1613:
#line 7561 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1614:
#line 7570 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1615:
#line 7573 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1616:
#line 7576 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7582 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7588 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7591 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7594 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1621:
#line 7597 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1622:
#line 7604 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1623:
#line 7606 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1624:
#line 7608 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1625:
#line 7610 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7612 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7613 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1628:
#line 7614 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1629:
#line 7615 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1630:
#line 7616 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1631:
#line 7617 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1632:
#line 7618 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1633:
#line 7620 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1634:
#line 7622 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1635:
#line 7624 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1636:
#line 7626 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7628 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7630 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7632 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7633 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7635 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7639 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1643:
#line 7640 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1645:
#line 7650 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1646:
#line 7659 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1647:
#line 7663 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1648:
#line 7670 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1649:
#line 7670 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1651:
#line 7674 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1652:
#line 7679 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1653:
#line 7679 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1655:
#line 7683 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1656:
#line 7687 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1659:
#line 7696 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1660:
#line 7696 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1665:
#line 7715 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1666:
#line 7716 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1669:
#line 7724 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1670:
#line 7730 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1673:
#line 7749 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1674:
#line 7750 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1675:
#line 7751 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1676:
#line 7752 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1677:
#line 7753 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1678:
#line 7754 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1679:
#line 7758 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1680:
#line 7759 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1681:
#line 7760 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1682:
#line 7764 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1683:
#line 7768 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1685:
#line 7777 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1687:
#line 7782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1688:
#line 7783 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1689:
#line 7787 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1690:
#line 7793 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1691:
#line 7880 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1692:
#line 7884 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1693:
#line 7886 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1694:
#line 7893 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1695:
#line 7897 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1696:
#line 7903 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1697:
#line 7911 "fgl.yacc"
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

  case 1698:
#line 7921 "fgl.yacc"
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

  case 1699:
#line 7931 "fgl.yacc"
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
#line 7943 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1701:
#line 7946 "fgl.yacc"
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

  case 1702:
#line 7965 "fgl.yacc"
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
#line 7991 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1704:
#line 7994 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1706:
#line 8003 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1707:
#line 8008 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1708:
#line 8011 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1709:
#line 8019 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1710:
#line 8027 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1711:
#line 8040 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1712:
#line 8043 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1713:
#line 8051 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1714:
#line 8054 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1715:
#line 8057 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1716:
#line 8065 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1717:
#line 8069 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1718:
#line 8072 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1719:
#line 8075 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1720:
#line 8078 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1721:
#line 8082 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1722:
#line 8083 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1723:
#line 8084 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1724:
#line 8085 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1725:
#line 8086 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1726:
#line 8092 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1727:
#line 8093 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1728:
#line 8094 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1729:
#line 8095 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1730:
#line 8096 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 8097 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1732:
#line 8098 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1733:
#line 8099 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1734:
#line 8100 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1735:
#line 8101 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1736:
#line 8102 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1737:
#line 8103 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1738:
#line 8104 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1739:
#line 8105 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);printf("C14\n");}
    break;

  case 1740:
#line 8109 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1741:
#line 8115 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1742:
#line 8116 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1743:
#line 8129 "fgl.yacc"
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

  case 1744:
#line 8149 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1748:
#line 8155 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1749:
#line 8156 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1753:
#line 8168 "fgl.yacc"
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

  case 1754:
#line 8194 "fgl.yacc"
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

  case 1755:
#line 8245 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1756:
#line 8247 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 8249 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 8250 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1759:
#line 8255 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1760:
#line 8260 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 8261 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1762:
#line 8265 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1763:
#line 8267 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8269 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8272 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1766:
#line 8276 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1767:
#line 8281 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1768:
#line 8286 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1769:
#line 8290 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1771:
#line 8300 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1773:
#line 8315 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1774:
#line 8318 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1775:
#line 8322 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1778:
#line 8341 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1779:
#line 8342 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1780:
#line 8345 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1781:
#line 8346 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1782:
#line 8347 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1783:
#line 8348 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1784:
#line 8349 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1785:
#line 8350 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1786:
#line 8351 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1787:
#line 8356 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1788:
#line 8357 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1789:
#line 8361 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1790:
#line 8365 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1791:
#line 8369 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1792:
#line 8373 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1793:
#line 8378 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1794:
#line 8382 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1795:
#line 8387 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1797:
#line 8395 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1799:
#line 8401 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1800:
#line 8407 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1801:
#line 8411 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1806:
#line 8429 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1807:
#line 8436 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1808:
#line 8445 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1809:
#line 8445 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17153 "y.tab.c"

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


#line 8540 "fgl.yacc"

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



