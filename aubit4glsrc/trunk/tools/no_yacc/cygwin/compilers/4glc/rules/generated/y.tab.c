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
#define YYLAST   8578

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
    1054,  1058,  1063,  1069,  1071,  1074,  1076,  1078,  1080,  1082,
    1084,  1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,
    1104,  1106,  1108,  1110,  1112,  1114,  1116,  1119,  1121,  1123,
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
    1575,  1577,  1581,  1582,  1583,  1584,  1593,  1594,  1595,  1606,
    1607,  1609,  1610,  1612,  1614,  1617,  1618,  1622,  1623,  1627,
    1628,  1630,  1632,  1635,  1636,  1640,  1641,  1645,  1649,  1651,
    1656,  1660,  1662,  1666,  1668,  1672,  1674,  1678,  1680,  1683,
    1684,  1688,  1689,  1693,  1694,  1699,  1700,  1705,  1706,  1711,
    1712,  1713,  1725,  1726,  1729,  1732,  1736,  1738,  1742,  1744,
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
    2443,  2444,  2445,  2453,  2455,  2458,  2459,  2463,  2464,  2469,
    2470,  2476,  2478,  2479,  2483,  2484,  2492,  2493,  2499,  2501,
    2504,  2505,  2507,  2509,  2511,  2512,  2514,  2516,  2519,  2522,
    2525,  2527,  2529,  2531,  2533,  2537,  2539,  2541,  2544,  2545,
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
     843,   678,    -1,   497,   862,   843,   678,    65,    -1,   212,
      -1,   212,   844,    -1,   285,    -1,   284,    -1,   211,    -1,
     363,    -1,   173,    -1,   210,    -1,   327,    -1,   326,    -1,
     242,    -1,   170,    -1,   169,    -1,   144,    -1,   203,    -1,
     127,    -1,   143,    -1,   186,    -1,   153,    -1,   847,    -1,
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
     429,   928,   390,    -1,   405,   429,   928,   390,    -1,   191,
     429,   887,   390,    -1,    59,   429,   887,   390,    -1,   881,
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
      -1,    -1,    -1,    -1,   402,   889,   930,   890,  1286,   891,
    1488,   239,    -1,    -1,    -1,   637,   936,   893,   752,   894,
    1035,   896,   895,   901,   638,    -1,    -1,   906,    -1,    -1,
     897,    -1,   898,    -1,   897,   898,    -1,    -1,   639,   899,
    1488,    -1,    -1,   640,   900,  1488,    -1,    -1,   902,    -1,
     903,    -1,   902,   903,    -1,    -1,   641,   904,  1488,    -1,
      -1,   642,   905,  1488,    -1,   907,   911,   323,    -1,    91,
      -1,    91,   908,   546,   909,    -1,    91,   383,   910,    -1,
    1090,    -1,   908,     5,  1090,    -1,   936,    -1,   909,     5,
     936,    -1,  1090,    -1,   910,     5,  1090,    -1,   912,    -1,
     911,   912,    -1,    -1,   643,   913,  1488,    -1,    -1,   644,
     914,  1488,    -1,    -1,   663,   909,   915,  1488,    -1,    -1,
     480,   909,   916,  1488,    -1,    -1,   624,   909,   917,  1488,
      -1,    -1,    -1,   595,  1090,    14,   844,   625,   844,   921,
     919,  1488,   920,   240,    -1,    -1,   571,   844,    -1,   545,
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
      -1,  1209,    -1,  1219,    -1,  1060,    -1,  1468,    -1,   892,
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
    1488,  1043,    -1,    -1,    -1,   645,   936,  1061,   752,  1062,
    1063,   646,    -1,  1064,    -1,  1063,  1064,    -1,    -1,   647,
    1065,  1488,    -1,    -1,   624,   936,  1066,  1488,    -1,    -1,
     558,  1068,  1083,  1074,  1069,    -1,   361,    -1,    -1,   233,
    1071,  1488,    -1,    -1,    23,  1075,  1076,  1077,   935,  1072,
    1488,    -1,    -1,    23,  1075,   935,  1073,  1488,    -1,  1070,
      -1,  1074,  1070,    -1,    -1,  1006,    -1,    25,    -1,  1090,
      -1,    -1,  1090,    -1,    25,    -1,   250,  1081,    -1,   262,
    1082,    -1,   245,  1082,    -1,   585,    -1,    25,    -1,  1090,
      -1,  1081,    -1,  1082,     5,  1081,    -1,  1090,    -1,    25,
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
      -1,    97,    -1,   394,     5,  1387,   625,  1388,    -1,  1377,
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
     918,    -1,   922,    -1,   943,    -1,   944,    -1,   947,    -1,
     948,    -1,   949,    -1,   950,    -1,   963,    -1,   971,    -1,
     992,    -1,   993,    -1,   995,    -1,   999,    -1,  1016,    -1,
    1017,    -1,  1021,    -1,  1022,    -1,  1023,    -1,  1024,    -1,
    1032,    -1,  1047,    -1,  1067,    -1,  1078,    -1,  1079,    -1,
    1080,    -1,  1084,    -1,  1123,    -1,  1126,    -1,  1128,    -1,
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
    1115,  1117,  1179,  1183,  1187,  1187,  1198,  1202,  1206,  1207,
    1210,  1216,  1210,  1229,  1234,  1238,  1229,  1250,  1254,  1250,
    1262,  1267,  1262,  1286,  1293,  1297,  1285,  1323,  1323,  1327,
    1328,  1329,  1334,  1337,  1342,  1346,  1354,  1357,  1357,  1363,
    1367,  1382,  1380,  1398,  1398,  1413,  1413,  1416,  1416,  1420,
    1423,  1423,  1423,  1430,  1431,  1430,  1438,  1438,  1449,  1449,
    1468,  1471,  1474,  1477,  1480,  1483,  1496,  1501,  1501,  1502,
    1502,  1505,  1510,  1510,  1514,  1524,  1538,  1542,  1537,  1552,
    1558,  1566,  1567,  1570,  1570,  1573,  1577,  1582,  1589,  1589,
    1593,  1593,  1600,  1600,  1605,  1605,  1610,  1610,  1615,  1615,
    1628,  1629,  1637,  1638,  1655,  1658,  1661,  1664,  1667,  1670,
    1676,  1687,  1692,  1705,  1709,  1724,  1725,  1729,  1729,  1733,
    1733,  1733,  1734,  1735,  1740,  1740,  1743,  1743,  1752,  1753,
    1754,  1757,  1761,  1762,  1762,  1779,  1779,  1779,  1779,  1783,
    1790,  1791,  1794,  1794,  1797,  1797,  1806,  1803,  1819,  1819,
    1821,  1821,  1823,  1825,  1827,  1829,  1832,  1836,  1836,  1837,
    1837,  1841,  1841,  1853,  1853,  1858,  1862,  1864,  1865,  1868,
    1868,  1868,  1872,  1873,  1874,  1875,  1882,  1883,  1884,  1885,
    1888,  1889,  1890,  1891,  1895,  1900,  1905,  1909,  1912,  1916,
    1917,  1918,  1919,  1920,  1921,  1922,  1923,  1926,  1927,  1928,
    1960,  1964,  1966,  1968,  1968,  1975,  1979,  1979,  1983,  1984,
    1985,  1986,  1987,  1988,  1989,  1995,  1995,  1998,  2000,  2006,
    2008,  2014,  2022,  2022,  2025,  2026,  2027,  2028,  2029,  2030,
    2031,  2037,  2040,  2040,  2053,  2053,  2060,  2061,  2062,  2064,
    2065,  2067,  2069,  2070,  2071,  2072,  2077,  2083,  2089,  2090,
    2092,  2094,  2095,  2096,  2097,  2098,  2099,  2102,  2103,  2110,
    2118,  2118,  2126,  2123,  2138,  2138,  2140,  2140,  2148,  2148,
    2151,  2154,  2155,  2160,  2172,  2176,  2179,  2182,  2183,  2184,
    2185,  2186,  2191,  2198,  2204,  2209,  2213,  2209,  2224,  2226,
    2231,  2236,  2236,  2240,  2240,  2243,  2243,  2249,  2249,  2255,
    2255,  2271,  2274,  2289,  2292,  2305,  2307,  2309,  2311,  2313,
    2315,  2317,  2323,  2325,  2329,  2331,  2333,  2335,  2337,  2339,
    2341,  2347,  2361,  2362,  2363,  2364,  2365,  2369,  2370,  2371,
    2375,  2380,  2387,  2388,  2389,  2390,  2391,  2392,  2393,  2394,
    2395,  2396,  2397,  2404,  2404,  2409,  2409,  2412,  2418,  2426,
    2432,  2442,  2443,  2451,  2458,  2462,  2472,  2476,  2481,  2486,
    2488,  2498,  2511,  2519,  2532,  2537,  2543,  2548,  2553,  2554,
    2560,  2631,  2637,  2642,  2650,  2650,  2665,  2669,  2676,  2679,
    2687,  2698,  2708,  2714,  2723,  2728,  2736,  2739,  2742,  2747,
    2754,  2759,  2764,  2769,  2779,  2787,  2795,  2800,  2804,  2809,
    2813,  2817,  2824,  2827,  2830,  2834,  2838,  2842,  2846,  2854,
    2864,  2869,  2862,  2885,  2890,  2885,  2907,  2907,  2907,  2910,
    2910,  2910,  2913,  2913,  2913,  2916,  2916,  2916,  2919,  2925,
    2931,  2937,  2947,  2947,  2951,  2955,  2956,  2962,  2963,  2968,
    2971,  2980,  2989,  2990,  2993,  2998,  3004,  3008,  3012,  3015,
    3021,  3024,  3027,  3044,  3047,  3053,  3054,  3055,  3059,  3060,
    3061,  3062,  3063,  3065,  3066,  3067,  3069,  3070,  3074,  3075,
    3080,  3081,  3093,  3097,  3102,  3092,  3122,  3128,  3122,  3142,
    3142,  3144,  3145,  3149,  3149,  3153,  3153,  3158,  3158,  3165,
    3166,  3170,  3170,  3174,  3174,  3179,  3179,  3186,  3190,  3191,
    3192,  3197,  3197,  3200,  3200,  3204,  3204,  3208,  3208,  3212,
    3212,  3217,  3217,  3222,  3222,  3227,  3227,  3232,  3232,  3248,
    3252,  3247,  3260,  3263,  3277,  3294,  3295,  3296,  3297,  3298,
    3299,  3302,  3302,  3305,  3307,  3310,  3313,  3315,  3316,  3317,
    3319,  3321,  3323,  3325,  3329,  3336,  3338,  3344,  3349,  3354,
    3359,  3359,  3362,  3368,  3373,  3376,  3383,  3383,  3385,  3386,
    3388,  3390,  3392,  3394,  3398,  3407,  3407,  3469,  3481,  3488,
    3488,  3492,  3497,  3503,  3507,  3511,  3517,  3521,  3525,  3531,
    3531,  3539,  3540,  3544,  3544,  3548,  3549,  3552,  3555,  3555,
    3558,  3560,  3560,  3563,  3565,  3565,  3566,  3568,  3568,  3577,
    3575,  3587,  3587,  3587,  3590,  3592,  3590,  3599,  3602,  3608,
    3619,  3619,  3623,  3629,  3629,  3633,  3634,  3645,  3646,  3648,
    3650,  3655,  3655,  3659,  3658,  3665,  3664,  3670,  3670,  3675,
    3675,  3681,  3681,  3686,  3686,  3691,  3691,  3696,  3696,  3699,
    3699,  3702,  3702,  3705,  3705,  3747,  3748,  3756,  3757,  3766,
    3771,  3776,  3777,  3778,  3782,  3781,  3792,  3797,  3802,  3802,
    3818,  3823,  3824,  3825,  3826,  3829,  3829,  3832,  3839,  3840,
    3841,  3842,  3843,  3844,  3845,  3846,  3847,  3852,  3852,  3854,
    3857,  3857,  3859,  3863,  3863,  3866,  3867,  3870,  3870,  3875,
    3875,  3878,  3879,  3880,  3881,  3882,  3883,  3884,  3885,  3886,
    3887,  3888,  3889,  3890,  3891,  3892,  3893,  3894,  3898,  3916,
    3916,  3916,  3943,  3954,  3961,  3967,  3973,  3979,  3990,  4013,
    4012,  4029,  4029,  4033,  4034,  4042,  4043,  4044,  4045,  4052,
    4053,  4055,  4056,  4060,  4065,  4066,  4067,  4068,  4069,  4070,
    4071,  4072,  4073,  4074,  4075,  4078,  4078,  4080,  4080,  4080,
    4082,  4086,  4086,  4095,  4100,  4116,  4122,  4094,  4136,  4150,
    4160,  4149,  4173,  4180,  4180,  4185,  4190,  4195,  4196,  4199,
    4199,  4199,  4202,  4202,  4210,  4216,  4230,  4234,  4247,  4229,
    4261,  4267,  4261,  4278,  4279,  4283,  4283,  4293,  4293,  4311,
    4311,  4325,  4336,  4335,  4347,  4343,  4360,  4357,  4370,  4370,
    4372,  4373,  4375,  4376,  4379,  4380,  4381,  4383,  4388,  4393,
    4399,  4401,  4402,  4405,  4406,  4409,  4411,  4418,  4421,  4424,
    4427,  4431,  4435,  4436,  4437,  4438,  4439,  4443,  4448,  4448,
    4451,  4477,  4536,  4536,  4539,  4543,  4547,  4590,  4632,  4633,
    4634,  4637,  4651,  4663,  4663,  4668,  4669,  4675,  4735,  4792,
    4797,  4804,  4809,  4817,  4823,  4857,  4860,  4861,  4902,  4945,
    4946,  4950,  4951,  4955,  5008,  5012,  5015,  5021,  5032,  5039,
    5047,  5047,  5050,  5051,  5052,  5053,  5054,  5057,  5060,  5066,
    5069,  5073,  5077,  5084,  5089,  5096,  5099,  5105,  5107,  5107,
    5107,  5111,  5131,  5138,  5145,  5148,  5162,  5169,  5170,  5173,
    5174,  5178,  5184,  5189,  5195,  5196,  5201,  5205,  5205,  5209,
    5210,  5213,  5214,  5218,  5226,  5229,  5235,  5236,  5238,  5240,
    5244,  5244,  5245,  5250,  5258,  5259,  5264,  5265,  5267,  5280,
    5282,  5283,  5285,  5288,  5291,  5294,  5298,  5301,  5304,  5308,
    5312,  5316,  5319,  5323,  5326,  5327,  5328,  5331,  5334,  5337,
    5340,  5343,  5346,  5349,  5365,  5373,  5373,  5375,  5382,  5389,
    5404,  5402,  5422,  5427,  5428,  5432,  5433,  5435,  5436,  5438,
    5438,  5446,  5455,  5455,  5465,  5466,  5469,  5470,  5473,  5477,
    5491,  5496,  5501,  5506,  5516,  5516,  5520,  5523,  5523,  5525,
    5535,  5544,  5551,  5553,  5557,  5560,  5560,  5564,  5563,  5567,
    5566,  5570,  5569,  5573,  5572,  5576,  5575,  5578,  5578,  5594,
    5593,  5615,  5616,  5617,  5618,  5619,  5620,  5623,  5623,  5629,
    5629,  5632,  5632,  5642,  5643,  5644,  5651,  5663,  5664,  5667,
    5668,  5671,  5674,  5674,  5679,  5683,  5688,  5694,  5695,  5696,
    5700,  5701,  5702,  5703,  5707,  5717,  5719,  5724,  5727,  5732,
    5738,  5745,  5752,  5761,  5768,  5775,  5782,  5789,  5798,  5798,
    5800,  5800,  5803,  5804,  5805,  5806,  5807,  5808,  5809,  5810,
    5811,  5812,  5815,  5815,  5818,  5819,  5820,  5821,  5824,  5824,
    5827,  5827,  5830,  5831,  5832,  5833,  5834,  5835,  5836,  5837,
    5839,  5840,  5841,  5842,  5844,  5845,  5846,  5847,  5849,  5850,
    5851,  5852,  5853,  5854,  5855,  5856,  5860,  5866,  5874,  5885,
    5894,  5905,  5909,  5913,  5919,  5884,  5932,  5935,  5943,  5955,
    5957,  5962,  5970,  5980,  5983,  5987,  5995,  5961,  6004,  6008,
    6012,  6016,  6008,  6026,  6027,  6028,  6029,  6034,  6036,  6039,
    6043,  6046,  6053,  6058,  6059,  6060,  6065,  6066,  6072,  6072,
    6072,  6077,  6077,  6077,  6088,  6089,  6095,  6096,  6108,  6109,
    6114,  6115,  6116,  6120,  6123,  6129,  6132,  6140,  6141,  6147,
    6154,  6157,  6166,  6169,  6172,  6175,  6178,  6181,  6184,  6191,
    6194,  6201,  6204,  6210,  6213,  6220,  6223,  6230,  6231,  6236,
    6240,  6243,  6249,  6252,  6258,  6265,  6266,  6270,  6276,  6279,
    6286,  6287,  6294,  6297,  6302,  6313,  6314,  6315,  6316,  6317,
    6318,  6319,  6320,  6321,  6324,  6327,  6333,  6333,  6339,  6339,
    6350,  6363,  6373,  6373,  6378,  6378,  6382,  6386,  6387,  6393,
    6394,  6399,  6403,  6410,  6413,  6420,  6424,  6419,  6433,  6437,
    6441,  6448,  6452,  6452,  6465,  6469,  6469,  6484,  6486,  6488,
    6490,  6492,  6494,  6496,  6498,  6504,  6514,  6521,  6526,  6527,
    6531,  6533,  6534,  6537,  6538,  6539,  6542,  6547,  6554,  6555,
    6561,  6573,  6574,  6577,  6577,  6582,  6587,  6592,  6593,  6596,
    6597,  6602,  6607,  6611,  6616,  6617,  6621,  6628,  6632,  6633,
    6638,  6640,  6644,  6645,  6649,  6650,  6651,  6652,  6656,  6657,
    6662,  6663,  6668,  6669,  6674,  6675,  6680,  6685,  6686,  6691,
    6692,  6696,  6697,  6702,  6709,  6714,  6719,  6723,  6724,  6729,
    6730,  6736,  6738,  6743,  6744,  6750,  6753,  6756,  6763,  6765,
    6779,  6784,  6785,  6788,  6790,  6797,  6800,  6806,  6810,  6814,
    6818,  6821,  6828,  6835,  6840,  6844,  6845,  6851,  6854,  6865,
    6872,  6878,  6881,  6888,  6895,  6901,  6902,  6908,  6909,  6910,
    6913,  6914,  6919,  6919,  6923,  6931,  6932,  6935,  6938,  6943,
    6944,  6949,  6952,  6958,  6961,  6967,  6970,  6976,  6979,  6986,
    6987,  7016,  7017,  7022,  7030,  7035,  7038,  7041,  7044,  7050,
    7051,  7055,  7058,  7061,  7062,  7067,  7070,  7073,  7076,  7079,
    7082,  7085,  7091,  7092,  7093,  7094,  7095,  7097,  7099,  7100,
    7105,  7108,  7112,  7118,  7119,  7120,  7121,  7133,  7134,  7135,
    7139,  7140,  7145,  7147,  7148,  7149,  7151,  7152,  7153,  7154,
    7156,  7157,  7159,  7160,  7162,  7163,  7164,  7165,  7167,  7171,
    7172,  7178,  7180,  7181,  7182,  7183,  7188,  7192,  7196,  7200,
    7201,  7205,  7206,  7216,  7225,  7226,  7227,  7231,  7234,  7239,
    7244,  7249,  7257,  7261,  7265,  7266,  7267,  7272,  7275,  7278,
    7292,  7306,  7319,  7320,  7324,  7324,  7324,  7324,  7324,  7324,
    7325,  7328,  7333,  7333,  7333,  7333,  7333,  7333,  7335,  7338,
    7344,  7344,  7344,  7344,  7344,  7344,  7344,  7345,  7345,  7345,
    7345,  7345,  7345,  7345,  7347,  7348,  7351,  7360,  7360,  7366,
    7366,  7373,  7373,  7379,  7379,  7387,  7388,  7389,  7392,  7392,
    7395,  7396,  7397,  7402,  7405,  7411,  7416,  7424,  7437,  7438,
    7435,  7456,  7466,  7469,  7474,  7486,  7489,  7493,  7496,  7497,
    7503,  7506,  7507,  7516,  7525,  7530,  7531,  7532,  7533,  7541,
    7544,  7550,  7553,  7563,  7572,  7575,  7578,  7584,  7590,  7593,
    7596,  7599,  7605,  7607,  7609,  7611,  7613,  7615,  7616,  7617,
    7618,  7619,  7620,  7621,  7623,  7625,  7627,  7629,  7631,  7633,
    7635,  7636,  7641,  7642,  7649,  7652,  7661,  7665,  7672,  7672,
    7676,  7676,  7681,  7681,  7685,  7685,  7689,  7695,  7695,  7698,
    7698,  7704,  7711,  7712,  7713,  7717,  7718,  7721,  7722,  7726,
    7732,  7742,  7743,  7751,  7752,  7753,  7754,  7755,  7756,  7760,
    7761,  7762,  7766,  7766,  7778,  7779,  7783,  7784,  7785,  7789,
    7795,  7882,  7886,  7882,  7895,  7899,  7905,  7913,  7923,  7933,
    7945,  7948,  7967,  7993,  7996,  8002,  8005,  8010,  8013,  8021,
    8029,  8042,  8045,  8053,  8056,  8059,  8067,  8071,  8074,  8077,
    8080,  8084,  8085,  8086,  8087,  8088,  8094,  8095,  8096,  8097,
    8098,  8099,  8100,  8101,  8102,  8103,  8104,  8105,  8106,  8107,
    8111,  8117,  8118,  8130,  8151,  8151,  8155,  8156,  8157,  8158,
    8162,  8163,  8164,  8169,  8195,  8246,  8248,  8250,  8252,  8256,
    8261,  8263,  8266,  8268,  8270,  8274,  8277,  8282,  8287,  8291,
    8300,  8301,  8305,  8317,  8320,  8316,  8339,  8339,  8343,  8344,
    8347,  8348,  8349,  8350,  8351,  8352,  8353,  8358,  8359,  8363,
    8366,  8371,  8375,  8380,  8384,  8389,  8393,  8396,  8400,  8403,
    8408,  8412,  8423,  8429,  8429,  8430,  8431,  8438,  8447,  8447,
    8449,  8450,  8451,  8452,  8453,  8454,  8455,  8456,  8457,  8458,
    8459,  8460,  8461,  8462,  8463,  8464,  8465,  8466,  8467,  8468,
    8469,  8470,  8471,  8472,  8473,  8474,  8475,  8476,  8477,  8478,
    8479,  8480,  8481,  8482,  8483,  8484,  8485,  8486,  8487,  8488,
    8489,  8490,  8491,  8492,  8493,  8494,  8495,  8496,  8497,  8498,
    8499,  8500,  8501,  8502,  8503,  8504,  8505,  8506,  8507,  8508,
    8509,  8510,  8511,  8512,  8513,  8514,  8515,  8516,  8517,  8518,
    8519,  8520,  8521,  8522,  8523,  8524,  8525,  8526,  8527,  8528,
    8529,  8530,  8531,  8532,  8533
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
  "disp_field_command", "@50", "@51", "@52", "error_cmd", "exit_prog_cmd", 
  "ext_cmd", "continue_cmd", "fgl_expr_c", "fgl_next", 
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
  "foreach_cmd", "@66", "@67", "@68", "formhandler_def", "@69", "@70", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@71", 
  "@72", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@73", "@74", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@75", "@76", "@77", 
  "@78", "@79", "for_cmd", "@80", "@81", "for_step", "free_cmd", 
  "line_no", "file_name", "a_number", "coords", "display_coords", 
  "field_name", "cursor_name", "fetch_cursor_name", "win_name", 
  "open_win_name", "form_name", "open_form_name", "opt_help_no", 
  "identifier", "ident_or_var", "ident_p2", "var_or_string", 
  "field_name2", "cvariable", "real_number", "goto_cmd", "check_menu_cmd", 
  "menu_item_list", "menu_item", "uncheck_menu_cmd", "disable_cmd", 
  "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", "gm_disable_msg", 
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
  "@117", "menu_def", "@118", "@119", "menu_handler_elements", 
  "menu_handler_element", "@120", "@121", "menu_cmd", "@122", 
  "end_menu_command", "menu_block_command", "@123", "@124", "@125", 
  "menu_commands", "opt_key", "menu_opt_name", "menu_optional_desc", 
  "next_option_cmd", "show_option_cmd", "hide_option_cmd", "opt_name", 
  "opt_name_list", "menu_title", "message_cmd", "msg_next", "gui_message", 
  "msg_start", "op_msg_wait", "msg_wait", "variable", "var_int", 
  "varsetidentdot", "var", "assoc_var_read", "assoc_var_write", 
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
  "units_qual", "extend_qual", "sql_block_cmd", "@170", "sql_block", 
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
     829,   833,   833,   834,   834,   835,   835,   835,   835,   835,
     835,   835,   835,   835,   836,   836,   836,   836,   836,   836,
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
     887,   887,   889,   890,   891,   888,   893,   894,   892,   895,
     895,   896,   896,   897,   897,   899,   898,   900,   898,   901,
     901,   902,   902,   904,   903,   905,   903,   906,   907,   907,
     907,   908,   908,   909,   909,   910,   910,   911,   911,   913,
     912,   914,   912,   915,   912,   916,   912,   917,   912,   919,
     920,   918,   921,   921,   922,   923,   923,   923,   923,   923,
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
    1061,  1062,  1060,  1063,  1063,  1065,  1064,  1066,  1064,  1068,
    1067,  1069,  1071,  1070,  1072,  1070,  1073,  1070,  1074,  1074,
    1075,  1075,  1076,  1076,  1077,  1077,  1077,  1078,  1079,  1080,
    1081,  1081,  1081,  1082,  1082,  1083,  1083,  1084,  1085,  1085,
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
       3,     4,     5,     1,     2,     1,     1,     1,     1,     1,
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
       5,     7,     0,     3,     1,     1,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     4,     4,     2,     2,
       2,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       4,     6,     6,     3,     5,     5,     3,     1,     1,     3,
       1,     3,     0,     0,     0,     8,     0,     0,    10,     0,
       1,     0,     1,     1,     2,     0,     3,     0,     3,     0,
       1,     1,     2,     0,     3,     0,     3,     3,     1,     4,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     0,
       3,     0,     3,     0,     4,     0,     4,     0,     4,     0,
       0,    11,     0,     2,     2,     3,     1,     3,     1,     1,
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
       0,     0,     7,     1,     2,     0,     3,     0,     4,     0,
       5,     1,     0,     3,     0,     7,     0,     5,     1,     2,
       0,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     2,     0,     2,
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
       0,     0,     0,     0,   175,   536,   840,   792,     0,   326,
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
       0,     0,   239,   227,  1182,     0,     0,  1170,  1808,   537,
     841,   814,     0,   208,   209,     0,   275,   277,   272,   273,
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
       0,  1272,     0,   378,  1269,  1211,     0,     5,  1268,   379,
     376,     0,   381,   173,   469,  1083,     0,     0,  1278,   123,
     375,   374,  1203,   369,     0,  1228,  1780,     0,   380,   345,
       0,     3,     2,     0,   377,  1208,     0,     0,   370,   367,
     363,     0,     0,     0,     0,  1276,  1266,   373,     0,     0,
       0,     0,     0,     0,     0,     0,  1265,     0,     0,     0,
     174,  1205,   366,   365,     0,     0,  1784,  1783,     0,     0,
       0,   136,  1204,   372,   371,     0,     0,   368,   469,   469,
       0,   532,     0,     0,     0,   469,     0,     0,     0,   469,
     768,  1179,     0,     0,  1087,     0,  1773,     0,   103,     0,
       0,   849,     0,     0,     0,     0,   769,     0,     0,  1682,
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
     541,   809,     0,   845,     0,   843,     0,   327,   210,   211,
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
     608,   364,     0,   774,  1043,   776,     0,  1277,   871,   870,
     873,   869,   872,  1799,     0,   867,     0,   607,   957,   868,
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
       0,     0,     0,     0,   545,   547,   539,   542,   543,   847,
    1808,   842,   844,   815,     0,   278,   280,   307,   301,     0,
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
     409,   334,     0,   533,   589,   588,   586,   992,   590,   997,
     993,   996,   742,     0,   994,   995,   743,  1002,  1006,   999,
    1000,  1004,  1005,  1003,  1001,  1007,     0,   777,     0,     0,
       0,   406,   407,   404,   405,     0,     0,     0,   722,   721,
     720,  1779,  1786,    23,  1100,  1101,  1102,  1103,  1097,  1095,
    1194,  1109,  1094,  1090,     0,     0,  1091,  1774,     0,     0,
       0,     0,    97,     0,    98,     0,     0,     0,    73,     0,
       0,     0,   110,   105,     0,   876,     0,   875,     0,   469,
    1079,     0,   919,   920,   943,   914,   915,   770,   941,  1034,
    1199,     0,  1201,  1200,  1686,     0,     0,     0,  1684,  1687,
    1688,   659,     0,     0,     0,   648,   679,   679,   677,     0,
       0,   680,     0,    25,   647,   650,     0,   657,   653,   889,
     879,  1657,  1658,  1648,  1648,  1298,     0,     0,  1566,     0,
     186,  1281,     0,     0,  1282,  1326,   186,     0,  1327,     0,
    1605,     0,  1295,     0,  1344,  1343,  1342,  1340,  1341,  1339,
    1337,  1334,  1408,  1407,  1335,  1336,  1345,  1575,  1338,  1664,
    1663,  1662,  1346,  1808,  1808,   558,   549,   540,     0,   544,
    1808,   846,   175,     0,   321,   213,     0,   186,   222,   205,
    1184,   175,  1172,  1398,     0,  1397,     0,  1399,     0,  1400,
    1258,     0,  1264,  1260,  1257,     0,     0,     0,     0,     0,
       0,  1254,  1250,  1387,  1386,  1385,  1226,  1225,     0,  1249,
    1245,     0,  1241,  1239,     0,   617,     0,   616,     0,   985,
       0,     0,   983,  1750,  1752,  1751,  1748,  1798,  1795,  1219,
       0,     0,     0,  1212,   469,   342,     0,   530,  1177,     0,
       0,     0,     0,  1605,     0,     0,     0,     0,     0,   527,
     513,   518,     0,   514,   517,   516,     0,     0,     0,     0,
       0,     0,   419,     0,   171,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,   437,   436,   455,   446,   461,
     464,   465,   462,   468,   467,   466,   456,   457,   459,   458,
     460,   402,   447,   451,   469,   463,   450,   469,    92,     0,
     429,     0,  1209,   976,  1044,  1045,  1042,  1041,     0,   874,
       0,     0,   593,     0,     0,     0,   955,   953,     0,   672,
     673,     0,     0,  1777,  1785,     0,     0,   600,     0,   602,
     710,     0,   141,     0,   965,   972,     0,     0,   980,     0,
     337,     0,     0,     0,     0,    23,  1018,  1304,     0,     0,
     767,   754,   765,   766,   752,   753,   761,   756,   760,   755,
     764,   759,   762,   758,   763,   751,   757,   750,   749,   991,
     778,   412,     0,  1023,     0,  1788,   723,   724,   361,     0,
    1105,     0,  1108,  1093,  1808,     0,     0,     0,     0,     0,
       0,     0,    63,    92,     0,     0,   116,   111,     0,   106,
       0,   113,   107,   860,   852,   858,     0,  1078,     0,  1080,
    1082,     0,     0,   923,     0,     0,     0,     0,  1033,  1198,
    1753,  1689,   939,  1690,   937,  1683,  1685,  1808,   630,   635,
     638,   651,   649,   610,     0,   699,   697,   703,   701,     0,
       0,   695,   739,   693,   689,   687,   737,   715,     0,   681,
     691,   933,   929,     0,     0,     0,     0,   656,     0,     0,
       0,     0,     0,     0,     0,  1513,     0,  1403,  1404,  1669,
    1367,  1425,     0,     0,  1667,     0,     0,  1607,  1608,  1606,
    1588,  1691,     0,  1350,  1356,  1355,  1354,  1358,     0,  1351,
    1352,     0,  1576,  1587,   546,   548,     0,     0,   561,   553,
     555,     0,   550,   551,     0,     0,   569,   571,     0,     0,
     567,   848,   816,   212,     0,     0,   224,  1140,   838,  1118,
    1375,  1377,     0,  1262,     0,     0,     0,     0,     0,  1252,
       0,     0,  1505,  1503,  1490,  1492,  1488,     0,  1487,     0,
    1496,  1483,  1504,     0,  1495,  1480,  1486,  1502,  1494,  1391,
    1477,  1478,  1479,     0,  1247,  1243,     0,     0,  1231,   615,
       0,     0,     0,     0,     0,  1794,     4,     8,    10,  1509,
    1512,     0,   469,     0,   501,   498,   497,   500,   496,     0,
     421,   507,   492,   492,     0,   515,     0,   519,     0,   282,
    1176,     0,  1533,   499,  1176,   506,   420,   266,     0,  1176,
     480,   477,   486,  1176,   483,  1176,  1176,  1176,     0,     0,
       0,     0,     0,     0,     0,     0,   471,    93,    94,    96,
     473,     0,     0,     0,   973,     0,     0,     0,     0,     0,
       0,     0,   186,   671,     0,   597,   599,     0,     0,   158,
     156,     0,     0,   138,     0,   148,   154,   679,   143,   145,
       0,   970,   981,   982,     0,   410,   336,   341,   595,   335,
       0,   338,   343,  1305,   534,   587,   585,   749,   744,   745,
    1022,  1024,     0,   408,   362,  1098,  1096,  1195,  1196,     0,
       0,  1189,     0,     0,     0,    99,     0,     0,    74,    80,
      70,  1808,  1808,   109,   104,   118,   114,     0,   108,   740,
     861,   610,  1808,   851,   850,   859,   975,     0,     0,   921,
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
     560,   565,     0,     0,  1808,  1808,   538,   552,   575,   563,
     577,  1808,  1808,   573,   557,   568,   807,   322,   206,     0,
    1166,  1185,   807,     0,  1173,  1166,     0,     0,  1259,     0,
       0,     0,     0,     0,  1431,  1433,  1435,  1472,  1471,  1470,
    1437,  1453,  1261,     0,  1514,     0,  1376,     0,  1379,  1517,
       0,  1383,     0,  1251,     0,     0,  1556,  1554,  1555,  1551,
    1553,  1550,  1552,     0,     0,     0,     0,     0,     0,     0,
       0,  1389,     0,  1392,  1393,     0,  1246,     0,  1240,  1242,
    1749,     0,     0,     0,  1796,     0,     0,  1223,   823,     0,
     531,     0,  1609,  1611,   489,     0,   490,     0,   529,     0,
     526,   523,   494,   488,  1114,  1541,  1113,     0,   170,  1112,
       0,     0,     0,  1115,     0,  1117,  1116,  1110,   448,   449,
     453,   438,     0,   441,   452,     0,   440,     0,     0,    92,
       0,     0,     0,     0,  1274,  1801,  1800,   594,     0,     0,
      47,     0,   676,   675,   674,  1275,     0,     0,   679,  1808,
    1808,   150,   618,   160,   152,   162,   142,   149,  1808,     0,
       0,     0,     0,     0,     0,     0,  1808,     0,   747,   610,
       0,  1775,     0,    92,     0,    64,     0,     0,     0,    77,
       0,    92,    92,   117,   112,  1808,  1808,   102,   749,   862,
     856,   864,   863,   853,   582,   902,     0,     0,  1616,  1615,
    1529,     0,  1605,     0,     0,  1473,     0,  1473,  1473,  1473,
    1473,  1620,     0,     0,     0,     0,     0,     0,  1673,  1674,
    1675,  1676,  1677,  1678,  1623,  1754,   940,   938,   664,   662,
       0,   641,   655,   611,   716,     0,   700,   698,   704,   702,
       0,  1808,     0,  1808,   696,   694,   690,   688,   738,   692,
      23,   728,     0,     0,     0,    26,     0,  1652,     0,  1575,
       0,     0,  1584,  1567,  1583,  1406,     0,  1369,     0,  1315,
    1413,     0,     0,  1668,     0,  1665,  1589,     0,     0,     0,
       0,     0,     0,  1692,  1314,  1313,  1301,  1299,     0,  1360,
       0,  1353,     0,     0,     0,     0,   562,   559,   554,   556,
       0,  1808,  1808,   570,   572,  1808,  1808,     0,     0,  1164,
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
      67,    92,    75,    81,     0,   119,   115,   741,  1808,   866,
     610,   865,     0,   579,     0,   772,   773,   771,     0,     0,
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
     566,   564,   576,   578,   574,     0,     0,   229,  1158,  1159,
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
       0,   339,   535,   748,  1020,     0,     0,    65,     0,    78,
      87,     0,    71,   857,   854,   583,  1808,   917,  1531,     0,
       0,     0,     0,  1641,     0,     0,  1639,     0,     0,     0,
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
    1808,   580,     0,     0,     0,     0,     0,  1637,  1643,  1633,
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
    1021,     0,  1027,    87,    92,    87,    88,    82,    72,   855,
       0,     0,  1604,     0,  1681,     0,  1808,    23,  1655,  1594,
    1603,  1294,     0,  1291,  1293,  1590,  1739,     0,     0,  1737,
       0,     0,     0,     0,  1719,  1736,     0,  1363,  1058,  1060,
    1808,  1064,  1808,  1062,  1066,  1450,  1458,  1516,  1493,     0,
    1419,     0,  1409,     0,  1325,  1324,  1320,  1599,  1549,   357,
     355,   347,     0,   353,   359,    56,    61,    58,    60,    57,
      59,    55,     0,    50,     0,   621,   623,  1808,  1026,  1028,
    1192,    84,    79,   581,   918,  1679,  1680,   661,   719,     0,
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
    2915,  2201,  2761,  3034,  3141,  3151,  2917,  3154,  1786,  1787,
    1788,  1233,  1854,   557,  1244,   905,  1242,  1571,  1864,  1568,
    1862,  1867,  2206,  1243,  1861,  1572,  2205,   558,    17,    36,
      37,    38,    39,    40,   114,   561,   827,  1502,  1160,  1813,
    1817,  1818,  1814,  1815,  2473,  2477,  2178,  2170,  2169,  2171,
    2174,  1115,  1067,  1768,   562,    83,    84,    19,    62,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     679,  2328,   305,   660,  1684,   332,   333,   229,   287,   280,
     282,   985,   986,   146,   355,   147,   148,   293,   230,   231,
    1488,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   663,   247,   248,   323,   375,   196,    20,    80,   178,
     179,   180,   669,  2327,   181,   251,   240,   326,   327,   328,
     329,  1515,   563,   564,   565,   566,   784,  3012,  2733,  1135,
    3091,  3092,  3093,  3134,  3133,  3137,   567,   568,   569,   570,
     760,  1116,   867,  1202,  1203,  1169,   864,  1170,   762,   763,
     764,   765,   766,   767,   768,  1070,  1117,  2142,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,   716,   769,  1468,  2147,  2149,
    2731,   770,  1438,  2131,  1437,  2130,  1441,  2134,  1439,  2132,
    2114,  2123,   771,   772,   773,   774,  1422,  1423,  1424,  1425,
    1406,   571,   837,  1517,  2186,   115,   237,   365,  1336,   966,
     967,   968,  1333,  1334,  1671,  1672,  1673,  2024,  2025,  1337,
    1338,  1667,  2028,  2020,  1679,  1680,  2031,  2032,  2325,  2321,
    2322,   572,  2766,  3040,  2513,   573,  1177,    85,  1483,  1484,
    1829,   869,   817,   872,   694,   806,   789,   828,  1923,    86,
     695,   689,  1386,  2173,    87,   776,   574,   575,   921,   922,
     576,   577,   578,   579,   929,  2544,   950,  2785,   951,  1601,
     952,  1920,   953,  2251,   954,  1627,   580,  1597,  2250,  2542,
    2541,  3046,   116,    21,   581,  1151,  1489,  1490,  1617,  1282,
    1618,  1619,  2261,  2263,  1936,  1935,  1940,  1934,  1933,  1926,
    1925,  1928,  1927,  1930,  1932,   582,   583,   825,   584,  1278,
     936,  3047,   585,  1210,  2741,  1967,  1968,  1620,  1937,  1870,
    2208,   860,  1187,  1538,  1838,  2187,  1839,  1183,  1537,   586,
     587,   914,  1586,  2517,   588,   589,   590,   591,    22,    66,
      23,    24,    25,   117,   118,   592,   119,    26,   650,    27,
     120,   121,   158,   367,  1342,  2036,  2840,   122,   154,   298,
     593,  2109,    28,    29,    30,    31,    32,    61,    88,   123,
     413,  1351,  2042,   124,   238,   366,   654,   655,   970,  1340,
     594,   909,  1874,  1575,  1872,  2920,  2508,  1576,  1871,  2211,
    2510,   595,   596,   597,   800,   801,  1246,   598,   955,   956,
     599,  1290,   957,   777,    90,    91,    92,    93,  1253,   184,
     138,    94,   700,   135,   192,   193,  1254,  1255,  1881,  1256,
     410,   411,   938,   412,   939,  1593,  1594,  1257,  1258,  1131,
    2643,  2644,  2845,  1395,   815,   816,   600,  1146,  2905,   601,
    2485,   602,  1164,  1165,  1166,  1508,  1506,   603,   604,  1794,
    1824,   605,  1018,  1392,   606,   861,   862,   607,   877,   608,
    1978,   609,  2911,   610,  1842,  3030,  3031,  3032,  3107,   866,
     611,  1259,  1588,  1907,  1908,   612,  1476,   693,  1030,   613,
     614,   615,  2044,  2647,  2856,  2857,  2973,  2974,  2978,  2976,
    2979,  3070,  3072,   616,   617,  1248,  1580,   618,  1250,   885,
     886,   887,  1226,   619,   620,   621,  1550,  1218,   880,   199,
     888,   889,   778,  2045,  2369,  2370,  2353,   719,   720,  2040,
    2354,  2357,   125,   153,   359,   995,  1689,  2371,  2860,  1040,
     622,   878,   126,   150,   356,   992,  1687,  2358,  2858,  2041,
     904,  2193,  2756,  3033,  1221,   623,   624,   625,   626,   627,
     787,  1792,   713,  1741,   628,  2704,   707,   708,  2106,  1371,
     629,   630,  1004,  1005,  1006,  1383,  1726,  1007,  1723,  1380,
    1008,  1698,  1372,  1009,  1010,  1011,  1012,  1692,  1363,   631,
     796,   779,   632,  1314,  1315,  1642,  2572,  2802,  2292,  2569,
    3052,  3053,  1316,  1652,  2306,  1296,  2010,  2613,  2832,  1834,
    2185,  2011,  1317,  1318,  2715,  3005,  3006,  3007,  3086,  1319,
    1320,  1168,   633,   831,   634,   963,  1321,  1322,  2970,  1658,
    1659,  1660,  2013,  2308,  2835,  2836,  1323,  1988,  2286,  2799,
    1373,  1374,  1359,  2065,  1690,  2066,  1375,  2070,  1376,  2093,
    1377,  2094,  2423,  2424,  1693,  1324,  1636,  1637,  1985,  1325,
    3001,  2887,  2997,  1991,  2438,  2707,  2708,  2709,  2995,  2439,
    1992,  2888,  3002,  2053,  2054,  2055,  2056,  2057,  2862,  2664,
    2983,  2058,  2863,  2864,  2397,  2059,  2398,  2060,  2527,  1719,
    1720,  1721,  2693,  1722,  2420,  2414,  2876,  2067,  2837,  2401,
    2605,  2069,  2885,  1909,   780,  1910,  2220,  1058,  2115,  2724,
    2083,  2689,    60,   635,   636,  2564,  2794,  2279,  2793,  1663,
    2018,  2019,  2283,  1979,  1326,  1980,  1999,  2575,  1414,  1975,
    1976,  2716,  2890,  2792,  2568,  1911,  1650,  2111,  2112,  2998,
    2061,  1913,  1914,  2529,  2985,   637,   638,  1629,  1977,  2559,
    2789,  2790,  1293,   639,   782,  1328,  1329,  1645,  2294,  1330,
    1331,  1996,  2244,  2523,   640,   917,  1267,  1268,  1269,  1270,
    1332,  2000,  2611,  2831,  2303,  2608,  2609,  2610,  2607,  2595,
    2596,  2597,  2598,  2599,  2600,  2949,   701,  1590,   703,  1396,
    1915,    64,    49,    78,    75,   642,   891,  1554,  1154,  1212,
     643,   870,   644,  2160,   645,  1735,   705,  1398,   646,   647,
      43,   360,   361,   362,   363,   364,   648
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2609
static const short yypact[] =
{
    1539,   974, -2609, -2609,   259,   524,   524,   524,   524,   524,
     524,   524,   524,   259,  1038, -2609, -2609, -2609,  1207, -2609,
   -2609, -2609,   323, -2609,  1539, -2609, -2609, -2609, -2609, -2609,
    1910, -2609, -2609, -2609, -2609, -2609,   313,   363, -2609,   379,
   -2609, -2609, -2609, -2609, -2609,   259,    70, -2609,  -201, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609,  1706,    91, -2609, -2609, -2609,   882, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,   259, -2609, -2609,    70,
    -136, -2609,   259,   268,  1207, -2609,   567, -2609, -2609, -2609,
   -2609,   318,    22, -2609, -2609, -2609,   744,   351,   259, -2609,
   -2609,   838,   259, -2609, -2609,   259,   259, -2609, -2609, -2609,
   -2609,   259,   259, -2609, -2609, -2609, -2609, -2609,   882, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
    2588,    22, -2609,   250,   370, -2609, -2609,   415, -2609, -2609,
     877,    91,   403, -2609, -2609, -2609, -2609, -2609,  7777, -2609,
     259,   480,   842,   259,  1207, -2609, -2609, -2609,   259, -2609,
   -2609,   456,   873, -2609, -2609,   599, -2609,   626, -2609,   655,
   -2609, -2609,   706, -2609,   717, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,   590, -2609, -2609, -2609,   370,  1791,
    1155, -2609,   164, -2609,   370, -2609,   171, -2609, -2609, -2609,
      97, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   456,
   -2609,   873, -2609, -2609,   727, -2609,   742, -2609,   732, -2609,
   -2609,   780, -2609,   790, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,   793,  1208,   259,   810, -2609,  1207,  1207,   827,
     259, -2609,   484, -2609,   654,  1065, -2609,   658,  1206,  1260,
    1289,   259,  1310,  1313,  1321, -2609,   739, -2609,   820, -2609,
   -2609, -2609, -2609, -2609,   370, -2609,   370,   938,   169, -2609,
   -2609, -2609,  1383, -2609, -2609,  1392, -2609, -2609, -2609, -2609,
   -2609,   484, -2609, -2609, -2609,  1396,  1414,    91,  1310,  1421,
    1427,   839, -2609,  1403, -2609,  1075,  1047, -2609,  1132, -2609,
   -2609, -2609,   887, -2609, -2609,  1485, -2609,  1094, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,  1206,  1094, -2609, -2609, -2609,
   -2609, -2609, -2609,  1104,   226,   262,   235, -2609,  3842, -2609,
   -2609, -2609,  1090,  1531,   282,  1149, -2609, -2609,  1791, -2609,
     370,  1089, -2609, -2609,   934,  1544,  1319,   286,   300,   317,
    1154,   306,  1192, -2609, -2609, -2609,   259, -2609, -2609,   259,
    1224, -2609,  4194,   403,  4923,  1594,   202,   259,  1567,   -53,
   -2609,  1065,  1572, -2609, -2609, -2609, -2609,  1573, -2609,  1575,
   -2609,  1576, -2609,   259, -2609,   259, -2609, -2609,  1310,  1577,
   -2609, -2609, -2609, -2609,   185,   370,  1587,   -53,  1181,  1589,
   -2609,  1592, -2609, -2609, -2609,  1595, -2609, -2609, -2609,  1001,
    1232,  1618, -2609,   259,  1236, -2609, -2609, -2609,   259,   181,
     259,   259,   181,   181,   933,   259, -2609,   259, -2609, -2609,
     259, -2609,   330, -2609, -2609, -2609,   181, -2609, -2609, -2609,
   -2609,   259, -2609, -2609, -2609, -2609,   105,   105,  7262, -2609,
   -2609, -2609, -2609, -2609,   181, -2609, -2609,   181, -2609, -2609,
     259, -2609, -2609,   181, -2609, -2609,   854,   181, -2609, -2609,
    7262,   181,   854,   259,   854,   181, -2609, -2609,   101,   181,
     181,   101,   181,   259,   101,   181, -2609,   181,   181,   181,
   -2609, -2609, -2609, -2609,   854,   181, -2609, -2609,   181,    46,
     259, -2609, -2609, -2609, -2609,   181,   959, -2609, -2609, -2609,
     181, -2609,  2134,   854,  7262, -2609,    61,    61,   181, -2609,
   -2609,   984,   854,   995,  7262,  7262, -2609,  1023,  7262,   181,
      70, -2609,  7262,   181,  7262,   854, -2609,   181,  7262, -2609,
    7262,   105,   259,   181,   259,    61,   181,   259,    61, -2609,
     259,   283, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   139,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   786,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
     651, -2609,   259, -2609,   647, -2609,  1241, -2609, -2609, -2609,
    1333, -2609, -2609,  1245,  1246,  1249,  1257, -2609, -2609,  1025,
    1644,  1262, -2609,   188, -2609,  1353, -2609,  1276,  1277,  1045,
    1286,   259, -2609,   259,  1287, -2609,   319,  1251, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1063,  1283,  1227,
   -2609,  1072, -2609,  1070, -2609,  1683,  -207,   307, -2609, -2609,
   -2609,  1269, -2609,  1419, -2609,  1217,   162, -2609, -2609, -2609,
    1243, -2609,  7262,  7262,  7262, -2609, -2609,  1270,  1173,  1271,
    1279,  1282,  1293,  1296,  1299,  1306,  1309,  1311,  7262,  1440,
    1314,  1315,  1318, -2609,  7262,  7262,  1320,  1322, -2609,  7262,
    1325, -2609,  1326,  1327,  1328,  1331,  1332,  1334,  1336,  1337,
    6566, -2609,   131, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,   992, -2609,  1348, -2609, -2609,
   -2609, -2609, -2609, -2609,   854, -2609, -2609,  1419, -2609,   -50,
   -2609, -2609,  1503, -2609,    77, -2609,  1247, -2609, -2609, -2609,
   -2609,  1765, -2609, -2609,   -57, -2609,  1156, -2609,  1158,  1765,
   -2609,  1177, -2609, -2609,  1357,   104, -2609,  1344, -2609,  1120,
   -2609, -2609,  1360, -2609,   515, -2609,  1127,   570,  -247, -2609,
    1063,  1461, -2609,  7262,  7262, -2609,  1782,   181, -2609, -2609,
   -2609, -2609, -2609,   211,   211,   211, -2609,   211, -2609,   211,
     211,  1195,   -50,  1195,  1195,  1024,  1024,  1195,  1195,   -50,
   -2609,  1801, -2609,     3,  1810, -2609,   -50, -2609,  6723, -2609,
     135,    54, -2609, -2609,  7262, -2609, -2609, -2609, -2609, -2609,
     950, -2609, -2609,   403,  1435,   403,  7262, -2609,    74, -2609,
   -2609,  7262,  1395,  1404,  1405,  1406,  1432,  1408,   995,  1327,
   -2609,  1480,  1022,  1252, -2609,  1272, -2609, -2609, -2609,  1096,
   -2609,  1830, -2609,  1834,   259, -2609,   279,   183,  1284, -2609,
   -2609,  1846, -2609,  1200,  1846,  1855,  1203,  1846,  1855,  7262,
    1846, -2609, -2609,   162,   854, -2609, -2609,  1443,   263, -2609,
   -2609,  1436,   854,  7262,  1438, -2609, -2609,  1838,  1843,  1805,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1145,  1145,
     181,   181,   181,  2414, -2609, -2609,  1781,   651, -2609, -2609,
     697, -2609, -2609, -2609,  1420, -2609, -2609, -2609, -2609,  2588,
    1310, -2609, -2609,  1422, -2609,   309, -2609, -2609, -2609, -2609,
   -2609, -2609,  1207, -2609, -2609,  1207,   911,   155,  1852, -2609,
   -2609,   346,   186,   550,  1878, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609,  1447,  1283,  1070, -2609,   933,   281,   401,
     259, -2609, -2609,   259, -2609,  1290,  1265,  1297,  1459, -2609,
    1462,   133, -2609, -2609, -2609,  2604,  7412,  7412,    61,  7262,
   -2609,    61,    61,    61,    61,  1428,  7262,  1068,  1117,  7262,
    6566,  1472, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1285,
      61,  1883,  7262,  4015,  6566,  1428,  7262, -2609,  6566,  1886,
     209, -2609, -2609, -2609,  7262, -2609,  7262,  7262,  7262,  7262,
    7262,  7262,  7262,  7262,  7262,  7262,  7262,  7262,  7262,  7262,
    7262,  7262,  7262,  7262,  7262,  7262, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  7262,  7262, -2609, -2609,
    1479,  7262, -2609,  7262,  1482, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   259,   854,
   -2609,  1302,  1486, -2609, -2609, -2609,   933,  1172, -2609,  1172,
     995,   101,  7262,  7262,  7262,  1489, -2609, -2609,   854,   854,
   -2609,  1323,   995,    61,  1253,   259,   370,    57,    46,   854,
   -2609,  1298,  7262,  1596, -2609, -2609,  1365, -2609, -2609,  1931,
   -2609,    75,   162, -2609, -2609,  1920,  1925, -2609, -2609, -2609,
   -2609, -2609, -2609,   340, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  2134, -2609,  1024,  7262,
      35, -2609, -2609,  1948, -2609,    61,  1928,  1929, -2609, -2609,
   -2609, -2609, -2609,   137, -2609, -2609, -2609, -2609,  1806, -2609,
    1744, -2609, -2609, -2609,  7262,   105, -2609, -2609,   259,  1937,
      61,    61, -2609,  1374, -2609,    61,  1342,   854, -2609,   259,
     259,  7262,   -97, -2609,  1387, -2609,   212, -2609,  1488, -2609,
    1491,  7262,   919, -2609, -2609,  1351, -2609,  1962, -2609,  1433,
   -2609,   854, -2609, -2609, -2609,   933,   854,    73, -2609, -2609,
   -2609, -2609,   259,    61,    61,   239,   263,  1823,  1356,   854,
     162, -2609,  1439, -2609, -2609,  1931,  1952,  1584, -2609, -2609,
   -2609, -2609, -2609,  1654,  1654, -2609,   715,  1441, -2609,   259,
   -2609, -2609,  1419,  1419, -2609, -2609, -2609,   259, -2609,   259,
     474,  1419, -2609,   803, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1113, -2609, -2609,
   -2609, -2609, -2609,    -5,    -5,   585,   843, -2609,   764, -2609,
     697, -2609,  1207,  1958, -2609, -2609,  1958, -2609, -2609, -2609,
   -2609,  1207, -2609, -2609,  1419, -2609,   758, -2609,  1559, -2609,
   -2609,   758, -2609, -2609, -2609,  1562,  1578,   331,  1582,  1586,
    2502, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   259, -2609,
   -2609,   331,  1338, -2609,   319, -2609,  1614,    22,  1398, -2609,
     995,  1437, -2609, -2609,  1561, -2609, -2609, -2609,  1477, -2609,
     259,   259,   259, -2609, -2609, -2609,   327, -2609,  6566,  1635,
    1636,   348,   361,   474,  1637,  5255,  1638,  -106,  1204, -2609,
   -2609,    98,  1641, -2609, -2609, -2609,  5582,  2008,  1440,  1648,
    1649,  5645, -2609,  1653,  3226,  1656, -2609,  7262,  7262,  7262,
    5750,  7262,  5806,  5911,  5967,  6603,  6629,  2604,  6668,  3974,
    2658,  6851,  4557,  6888,  3232,  1394,  7412,  7412,  7719,  1274,
    3630,  6566,  6072,  6135,  1428,  6566,  6385,  1428,  7262,  1615,
   -2609,   259, -2609,  1444, -2609, -2609, -2609, -2609,  1423, -2609,
    2046,  2047, -2609,  2049,  1483,  7262, -2609, -2609,  1445,  2051,
   -2609,  1583,  1442,  1855, -2609,  1679,   443, -2609,  1647, -2609,
   -2609,  1456,  1109,   259, -2609, -2609,  1655,   181,   757,  7262,
   -2609,   259,   259,  7262,    56,   -50,  2077,  1532,  2057,  2060,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1658, -2609,
   -2609, -2609,   854,  1555,  6723, -2609, -2609, -2609,  2032,  7262,
     403,   936, -2609, -2609,  1774,  2094,  2095,   380,   386,   259,
    1712,   995, -2609,  7262,  1676,  1677, -2609, -2609,  1748, -2609,
    7262,   293, -2609,  1512, -2609, -2609,   745, -2609,  7262, -2609,
   -2609,  1490,   250, -2609,   954,   259,  2096,  5847, -2609, -2609,
    1697, -2609,  1698,  2114, -2609, -2609, -2609,    96, -2609,  1855,
    1855,  1467, -2609,  1579,  1585, -2609, -2609, -2609, -2609,    61,
      61, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1553, -2609,
   -2609, -2609, -2609,    61,  7883,  2123,  2104, -2609,   995,   730,
     238,   273,  2033,    33,   984, -2609,    67, -2609, -2609, -2609,
    1707,    83,  1419,   166, -2609,  1516,  1513, -2609, -2609, -2609,
   -2609, -2609,   856, -2609, -2609, -2609, -2609,  1708,  1515,  2135,
   -2609,  1455, -2609, -2609, -2609, -2609,   854,   136, -2609, -2609,
   -2609,  1505,   843, -2609,   259,   259, -2609, -2609,   259,   634,
   -2609, -2609, -2609, -2609,  1721,  1722, -2609,  1689, -2609,  1690,
   -2609,  1726,   388, -2609,  7378,   394,   152,   152,   410, -2609,
     152,  7378, -2609, -2609,  1537,  1537, -2609,  1727, -2609,  1730,
    1731, -2609,  1732,  1734, -2609,  1735, -2609, -2609, -2609,    86,
   -2609, -2609, -2609,   413, -2609, -2609,   425,   259, -2609, -2609,
     401,  2142,   995,   370,  7262, -2609,  2160, -2609, -2609, -2609,
   -2609,   331, -2609,    61, -2609, -2609, -2609, -2609, -2609,  7602,
   -2609, -2609,  1440,  1440,  2143, -2609,  2146,  1591,  1492, -2609,
    1173,  1778, -2609, -2609,  1173, -2609, -2609, -2609,  1784,  1173,
    6566,  6566,  6566,  1173,  6566,  1173,  1173,  1173,  2151,  2153,
    2156,  7262,  1793,  2159,  7262,  1795, -2609,  2182, -2609,  6566,
   -2609,  1571,   331,   197, -2609,   995,  7262,  7262,  7262,  6944,
    2187,   141, -2609, -2609,   995, -2609,  1580,   259,   259, -2609,
   -2609,   259,   259, -2609,  1183, -2609, -2609,   275, -2609,  1581,
    7262, -2609, -2609, -2609,  2186, -2609, -2609, -2609, -2609, -2609,
     259,  1855, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,   854, -2609, -2609,  3530, -2609, -2609, -2609,  1871,
    2171, -2609,  1859,  1860,  1747,  1590,  1862,  1779, -2609, -2609,
   -2609,   476,  1848, -2609, -2609, -2609, -2609,  1748, -2609, -2609,
   -2609,   180,   756, -2609, -2609, -2609,  1931,  7262,  1786, -2609,
    1754, -2609, -2609, -2609,  4284,  4284, -2609,  1063, -2609, -2609,
    1537, -2609, -2609,  7465,  1785, -2609, -2609,  1787,  1788, -2609,
    1789,  1790,  1792,  1797,   259,   -96, -2609,  2219, -2609, -2609,
   -2609, -2609, -2609,  2249, -2609, -2609,   933,   854,   854,    63,
    1593, -2609,  2201,   -50,   259,  2058,  2058,  2058,  2058, -2609,
    2237, -2609,  2240,  2058,  2058,  2058,  2058,  1658, -2609, -2609,
    2058,    95, -2609, -2609, -2609, -2609,  2221,  2233, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,  2235, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,   435, -2609, -2609, -2609,  2224,
   -2609, -2609,  1419, -2609,   474, -2609, -2609, -2609, -2609, -2609,
   -2609,  1659,  1660,   256, -2609,    67, -2609,   152,  1643,   181,
    7378, -2609, -2609,  1822, -2609, -2609, -2609,   259,   259,  7602,
     203, -2609,  7262, -2609,  7262, -2609, -2609, -2609, -2609, -2609,
   -2609,   181,   152, -2609,  1419,  1130,  1634,  1642,  2252, -2609,
    2255, -2609,   854,   259,   859,   859, -2609, -2609,  2259, -2609,
    2259,   657,   657,  2259, -2609, -2609,  1594, -2609, -2609,  5326,
     182, -2609,  1594,  1680, -2609,   182,   152,   758, -2609,  7451,
    1847,  4275,  1847,   167,  2265, -2609, -2609, -2609, -2609, -2609,
   -2609,   477, -2609,  1419,   695,  1885,  2273,  1662, -2609, -2609,
     437, -2609,   331, -2609,   441,   252, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609,  1663,   342,  2253,  2253,  2257,  2253,  2253,
    2263, -2609,    66, -2609,   758,   259, -2609,   331, -2609, -2609,
    1671,   995,  2283,   194, -2609,   259,   444, -2609,  7262,  1911,
   -2609,   147, -2609,   259, -2609,  1678, -2609,  1914, -2609,  2280,
   -2609,  1718, -2609, -2609, -2609, -2609, -2609,  1687, -2609, -2609,
    1923,  1935,  1936, -2609,  1941, -2609, -2609, -2609, -2609, -2609,
   -2609,  6566,   454, -2609, -2609,   462, -2609,  1943,  7262,  7262,
    2294,   463,   995,  2314, -2609, -2609, -2609, -2609,  7262,  1768,
    2062,  7262, -2609, -2609, -2609, -2609,   969,  1947,   275,  1199,
    1199,  2333,   589, -2609,  2334, -2609, -2609, -2609,  1199,   259,
    1794,  1000,  2342,   259,   -84,   854,  2109,   465, -2609,  1579,
    7262, -2609,  2344,  7262,   854, -2609,   330,   259,   854, -2609,
    1963,  7262,  7262, -2609, -2609,   476,  1848, -2609,  1658, -2609,
   -2609,  1175, -2609, -2609,  1796, -2609,   370,  7175,  1500,  1500,
   -2609,  1736,   474,  1965,   145,   531,  7602,   531,   531,   531,
     531,  1737,  7602,  5847,  7602,  7602,  7602,  7602, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
    1918,   901, -2609, -2609, -2609,  1740, -2609, -2609, -2609, -2609,
      61,  2058,    61,  2058, -2609, -2609, -2609, -2609, -2609, -2609,
     -50, -2609,   991,  1005,  7883, -2609,  1970,  1934,  7602,  1113,
     273,   273, -2609, -2609, -2609, -2609,   468, -2609,  1894, -2609,
    2359,   152,   -80, -2609,  1741, -2609,  2363,  3320,  3320,  3320,
    3320,   152,   152, -2609, -2609, -2609,  1817, -2609,   471, -2609,
    1753, -2609,   259,   259,  1455,   854, -2609,  2259, -2609, -2609,
     259,   657,   657, -2609, -2609,   657,  2177,  1757,  1764, -2609,
   -2609,   105,   105,   105,  2365,   105,   105,   105,   105,   105,
     105,  2368, -2609,  2370,   105, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609,  5326, -2609,   854,  1770, -2609,  1951,  2177,
    2372, -2609,  2373,  2376,  2377,  2379,  2380,  2383,  1230,  1680,
   -2609,  1951, -2609,   472, -2609, -2609,  1940, -2609,   291,   438,
   -2609,  7378, -2609,  7378, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609,  4284,  1982,  4284,  1983,   563,  7602, -2609,
    2388, -2609,  2121,   152,  1084,   152, -2609, -2609, -2609, -2609,
    1551,  2396,  1551, -2609,  2418,  2418,   473,  2035,  2418, -2609,
    2037, -2609, -2609, -2609,   758, -2609, -2609, -2609, -2609,   995,
   -2609, -2609,   331,  2162,  1931, -2609,  7602,   218,  1905,   452,
   -2609,  1601,  1440,  1845,  1530, -2609, -2609, -2609, -2609, -2609,
    7262, -2609, -2609, -2609, -2609, -2609,  1968, -2609,   341,   995,
   -2609,  2432,  2010, -2609, -2609,  2052, -2609, -2609, -2609,  1891,
   -2609, -2609,   259,  1199,   370,  1148,   259,  1199, -2609, -2609,
      61, -2609, -2609,  7262, -2609, -2609, -2609,    61,  2114,  2205,
   -2609, -2609,   -50,  6566,  2420, -2609, -2609,   162,  2022, -2609,
   -2609,  7262, -2609, -2609,  2059, -2609, -2609, -2609,   756, -2609,
    1579, -2609,  7262, -2609,   207, -2609,  1810, -2609,  1551,  7602,
   -2609,   333,  2450,  2073, -2609, -2609, -2609,  7602, -2609,   483,
    7602,  7602,  7602,  7602,   259,   494, -2609, -2609, -2609, -2609,
   -2609,  7262,  2026, -2609,  2124, -2609,  2443, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   259, -2609,
      94, -2609, -2609, -2609,  1113,   152, -2609,   474,  2327,   496,
   -2609, -2609, -2609, -2609,   259,  1921,  7511,  7511, -2609, -2609,
    4897,  2044, -2609, -2609,  2048,  2053, -2609,  2056,  2064,  2065,
    2066,   259,   469, -2609, -2609,   506, -2609, -2609,  2364, -2609,
   -2609, -2609,   509,  2470,  2470, -2609, -2609,   510,  2473,  2466,
   -2609,   129, -2609, -2609,   152, -2609,   117,  1869, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,  2272,  2588, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,  -179,  2484, -2609,   854,  1814, -2609,  2272, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,  2265, -2609,  2063,  2249,   407, -2609,  2063,   407,
   -2609,  4284, -2609, -2609,  7602, -2609,   214, -2609, -2609, -2609,
    2034, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
    2108, -2609,  2474,  2116,  2119,  2478, -2609, -2609,  2129, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,   244,  2506, -2609, -2609,
     259,  2154,   259,  1895,   531,  2190, -2609,  2093, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  1549, -2609, -2609, -2609,
    6566,  2144,    61,   -50,  2152,   995, -2609,  7262, -2609,  1967,
    2510,   -50, -2609, -2609,   486, -2609, -2609, -2609, -2609,   115,
    2148,  1855, -2609, -2609, -2609,  2165,  2166,  2077,  2113, -2609,
    2200,  2167, -2609, -2609, -2609, -2609,  2320,  2106, -2609,   147,
    1537,  1939,  1537, -2609,  2176,  7602, -2609,  2178,  2184,  2185,
    2188, -2609, -2609,  2002, -2609, -2609, -2609,  1579, -2609,   511,
   -2609,   854,  2039,  1113,  1113, -2609, -2609,  7602, -2609, -2609,
     152, -2609,  2150, -2609,  2039,  2279,  2279,  2191,   145,   531,
    4947,   531,   531,   531,   531,  1961,  4947,  3320, -2609,  4947,
    4947,  4947,  4947, -2609, -2609,   152,  2569,   152,  3320,   181,
    7378, -2609,   854, -2609, -2609,   298, -2609, -2609,   259, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,   854,  2484, -2609, -2609,
   -2609,   854, -2609,   854, -2609, -2609,  1719, -2609,  2350, -2609,
    2351,    66, -2609,   517, -2609, -2609, -2609, -2609,   526,  2063,
    2579,  2566, -2609, -2609,  1973, -2609, -2609, -2609, -2609,  2209,
   -2609,   218, -2609,   218, -2609, -2609,  7602, -2609,  2155, -2609,
    2162,   201,   238,   259,  2574, -2609, -2609, -2609, -2609, -2609,
     995, -2609,  2212,  7974,  2175, -2609, -2609, -2609,  1986,   -50,
   -2609,   670, -2609, -2609, -2609,  2216,   162, -2609,  2200,  2200,
     756, -2609,   370,  2217,  1984,  1551,  1988, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,   259, -2609,  2114,   452, -2609,
   -2609,   147, -2609,  7689,   452, -2609,  2218,  4947, -2609,   527,
    4947,  4947,  4947,  4947,   259,   540, -2609, -2609, -2609, -2609,
   -2609, -2609,  2198, -2609, -2609, -2609,  2359,  2114,   117, -2609,
   -2609, -2609, -2609,  2025,  2025, -2609,  2025, -2609,  2025,  2025,
   -2609, -2609, -2609, -2609, -2609, -2609,   269, -2609, -2609, -2609,
    7602,  2203,  1551, -2609, -2609,   543, -2609,  2606, -2609, -2609,
    7378, -2609, -2609, -2609, -2609,  2624, -2609,  -176, -2609, -2609,
    2162,  2241,  1110, -2609, -2609,   211,   211,   211,   211,   211,
     211, -2609,  2605, -2609,   548, -2609,  7262,  1238, -2609, -2609,
   -2609,   573, -2609,  2200,  7262,  2200,  2077, -2609, -2609, -2609,
    2392,   215, -2609,  1551, -2609,  1551,    96,   -50, -2609, -2609,
   -2609, -2609,   557, -2609, -2609, -2609, -2609,  2243,  4947, -2609,
    2246,  2247,  2248,  2250, -2609, -2609,  3320, -2609, -2609, -2609,
    2025, -2609,  2025, -2609, -2609, -2609, -2609, -2609, -2609,   218,
   -2609,  7602,  2359,   201, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,   698, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,  7974, -2609,  2636, -2609, -2609,   624, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,    63, -2609,  7689,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,   562, -2609, -2609,
   -2609, -2609, -2609,  1086,  1086, -2609, -2609,  1086, -2609,  7262,
   -2609,  2254, -2609, -2609, -2609, -2609, -2609, -2609,  2256, -2609,
   -2609,   157, -2609,   162, -2609,  2077
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2609, -2609, -2609, -2609, -2609,   447, -2609,   542,  -182, -2609,
   -2609,  -859,  -310, -2609, -2609, -1564, -2609, -2609, -2609, -2609,
    -457, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -1676, -2609, -1540, -2609,
     501, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   784, -2609,
   -2609, -2609, -2609,  1411, -2609,  1083, -2609, -2609,   -37, -2609,
   -2609,  2618, -2609,  2617,  2293, -2609, -2609, -2609, -2609, -2609,
     850,   485, -2609,   845, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,  -126,   324,   241, -2609, -2609,
    2381,    -6, -2609,  2525, -2609, -2609,  2524, -2609,  2472, -2609,
   -2609, -2609,  2405,  2290,  1345,  2400,  -292, -2609, -2609, -2609,
   -2609, -2609,  1343,  -976, -2609, -2609, -2609, -2609, -2609, -2609,
    -132,  2339,  2483,  -198,   937, -2609,  2332,   264, -2609,  2391,
   -2609, -2609, -2609, -2609,  2401, -2609, -2609, -2609, -2609,  -324,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  2328, -2609,
    2330, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  -917,
   -2609, -2609,  -375, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
    2348, -2609, -2609,  1174, -2609,  -816,  -857,  -268, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,   935, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,  -482, -2609, -2609, -2609, -2609,
   -2609,  2193, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -1700, -2609, -2609, -2609, -2609, -2609, -2609,  1305, -2609, -2609,
    -693, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609,  1769, -2609, -2609, -2609, -2609,  1059, -2609, -2609, -2609,
   -2609, -2609, -1204, -2609, -2609,  1053, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  -781,  -607,   939,  1222,
   -2609,  -491,   678,  -832,  1193, -2609,   952, -2609, -1846,    -4,
    -169, -2609, -2609, -1747,   387,  1372, -2609, -2609,   876,  1466,
   -2609, -2609, -2609, -2609, -2609, -2609,   488, -2609,   196, -2609,
    1468, -2609,  1140, -2609,   822, -2609, -2609, -2609,  -373, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,   943, -2609, -1241,
   -2609,  1128, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,  1598, -2609, -2609,
   -2609, -2609, -2609, -2609,    -2, -2609, -2609, -1480, -2609, -2609,
   -2609, -2609,   690, -2609, -1622, -2609,  -837, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609,  2724, -2609, -2609, -2609,  2631,  2727,  -730, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,   111, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609,  2731, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609,  2110, -2609, -2609,
   -2609, -2609, -2609,  1186, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609,  -410,  2281, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609,  2018, -2609, -2609,   -62, -2609, -2609,  1187,
   -2609, -2609, -2609,  -687,  -192,  2497, -2609, -2609, -2609, -2609,
     702, -2609,  -715,  2087,  1493, -2111,   857, -2609,  1191,  1844,
     127,   -69, -2609, -2609, -2609,  1630, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  1599, -2609,  1146, -2609,
    -359, -2609, -2609, -2609, -2609, -2609, -2609,  -250, -2609, -2609,
   -2609, -2609, -2609, -2609,   549, -2609,  1645,   687, -2609, -2609,
   -2609, -2609, -2609,   412, -2609,   -71, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609,  1900, -2609, -2609, -2609, -2609, -2609, -2609, -2609,  -329,
   -2609,  1563,  1720, -2609, -2609,   419, -2609,  -407, -2609, -2609,
     436,   746, -2609, -2609, -2609, -2609, -2609, -2609, -2609,   741,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2608, -2609,  1771,  1007,  -987,
   -2609, -2609, -2609,  1413, -2609, -1333, -2609, -2609, -2609, -1347,
   -2609, -2609, -1317, -2609, -2609, -2609, -2609,  1431, -2609, -2609,
   -2609, -2609, -2609, -2609,   818, -2609, -2609, -2609, -2609, -2609,
   -2609,  -316, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609,  -278, -2609, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
   -2609,   792, -2609, -2609, -2609,  -160, -2609, -2609, -2609, -2609,
   -2609, -2609,   408, -2609, -2609,   763, -2609,  1111, -2609, -2609,
   -2609, -2609, -2609, -2609,  -981, -2609, -2609, -2609, -2609, -1500,
   -2609, -2609, -2609, -2609, -2609, -2609, -1975,   108, -2609, -1833,
     381, -2609, -2609, -1669,   439,   442,   773, -2609, -2434, -2116,
   -2609, -2609,   158,  -158, -2609, -2609, -2609, -2609, -1647, -2609,
   -2609, -2609, -1285, -2609, -2609,  -822, -2609,  -710,  1534,   149,
   -1645,   767, -2609,  -226, -2609, -2609, -2609, -2609,  -682, -2609,
   -1675, -2308, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2169,
   -2609,   521, -2609, -1783, -2609,  1873, -2609, -2609,  -904,   -55,
   -2609, -1616,   -54,   266,   546, -1107, -1389, -1961,   406,  -238,
    -112, -1823, -2609,   612, -2609, -2609, -2609,  1552,  -469, -2609,
   -2609,   -87,  1890, -2609,  1275, -2609, -2609, -1251,   276, -2609,
   -2609, -2609, -1705,    43, -2609, -2609, -2609,  1597, -2609, -2609,
   -2609, -2609, -2609, -2609, -2609, -2609, -2196,    26, -2609, -2253,
   -1873, -1634, -1019, -2609, -2609,    38,  -430,  -403,  -489,  1126,
    -499,    19,  2540,    81, -2609, -2609, -2609, -2609, -2609,  1703,
   -2609,  -478, -2609, -2609, -2609, -2609, -2609, -2609, -2609, -2609,
    -304,  1588,  2498, -2609, -2609, -2609, -2609
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1805
static const short yytable[] =
{
      42,  1031,   268,  1028,   386,  1173,   258,  1200,   823,    57,
      59,  1182,  1016,  1349,   284,  1360,  1382,  1213,  1171,    33,
     131,   702,  1816,  1858,  1749,  2210,   833,   834,   236,   113,
    2084,  1724,  2075,   868,   417,  1603,  1604,   874,  2296,   871,
     721,    74,    77,    33,   256,  2602,  2603,  2604,  1725,    70,
    1699,  2068,  2071,  2116,   883,  2071,    97,  1059,  1646,  1205,
    1966,  2218,  2219,  1179,  1180,  2175,  1181,   925,  1184,  1185,
     928,   805,   128,    41,  2488,    77,   832,  1132,  1497,  1224,
    1509,   113,   338,    41,    41,   127, -1803,   137,    41,   140,
     269,  2421,  1888,   291,   144,  2270,   670,    41,   149,  2436,
    1205,   151,   152,   702,  2691,  2606,  1264,   155,   156,  1149,
    2561,   299,   300,  1275,  1405,   690,   275,  1756,   690,   690,
    1205,   269,   276,   277,  1757,  2248,   798,  1285,    41,   269,
    1298,   717,   690,  1982,   919,    97,  1986,   127,  1280,   201,
    1205,  2022,  1199,  1510,    41,  1511,   232,  1512,   394,   235,
     690,   836,  2436,   690,   239,   269,  2163,  1125, -1803,   690,
     129,  1433,  2162,   690,  1137,  1138,  1026,   690,    41,   266,
    1026,   690,    41,  2381,   266,   690,   690,  1026,   690,    41,
     761,   690,    41,   690,   690,   690,   269,   931,   932,    41,
     266,   690,   273,   266,   690,   269,   270,   271,    41,   266,
    2284,   690,   791,   673,   940,  2209,   690,    41,    41,  1015,
    2768,  1206,   266,    41,   690,  2221,  1264,  1207,  1276,  2871,
     266,   292,   881,   941,    41,   690,  1026,  3004,    41,   690,
     296,   379,  1989,   690,  2867,  1573,   302,  1174,    41,   690,
     383,  1567,   690,  1026,  1509,    41,   865,   330,  1191,  1192,
     688,  2297,  2298,  2299,  2300,  2301,   884,   890,  2381,    63,
     906,  1595,  1265,   881,   910,    41,   912,   381,  1280,  1026,
     916,    41,   918,   728,   344,   182,   346,    41,  2829,  2668,
    2179,    97,  3003,    41,  1753,   781,    41,   389,   781,   949,
      82,   399,  2091,   269,  1887,  1888,    41,  2381,   790,  1162,
      41,  1302,   781,  2968,  2486,   401,   781,   269,   931,   932,
      41,   405,  1023,   807,  1347,  2268,  2355,  2560,   781,  3152,
     790,  2290,   141,    65,    18,    63,   818,   559,   649,   790,
     392,  1021,  1743,  2232,  1816,  1197,   829,   658,  2770,   136,
    1994,   835,  2287,  2492,    71,    41,  2734,   392,    18,   873,
    1411,    82,   409,  1743,  1548,   409,   710,    41,    41,  2843,
     818,   134,  3084,   409,   818,  1520,  1205,  2309,   818,    82,
    1163,   659,  1265,    41,   790,   996,   997,   790,  1542,   330,
    1022,   330,  2378,   641,   651,  1743,    82,  1198,   185,   186,
    2567,  1205,    35,  2047,  1382,  2795,   187,    41,  2571,  2047,
      82,  2068,  3087,   998,   999,  1000,   941,    34,  2844,   409,
     941,  3085,   941,  1281,   686,  2072,   691,   692,  2095,   820,
     699,   704,  1393,   706,    79,  1281,   709,    82,    41,  1236,
    2097,   269,  1887,  1888,    41,  2989,  1995,   692,  2969,    82,
    2274,  1260,  2405,    95,   775,  1574,  2405,  2384,  2385,  2432,
    2386,  2387,  2388,  2389,  2390,  2391,   692,  1516,   698,  2450,
    1890,   259,   260,   261,   262,   263,   775,  2450,  2432,   692,
    2490,  2030,    82,  2565,  2033,  1891,  2614,  2403,  2695,   808,
     130,  1241,   942,  1754,  2092,  2285,  2384,  2385,  2775,  2386,
    2387,  2388,  2389,  2390,  2391,   824,   826,  2562,  2563,  2775,
    3153,  2800,   699,  1304,   259,   260,   261,   262,   263,   132,
     775,  2817,   824,   824,  2817,  2825,  2935,   384,   944,    82,
     775,   775,  2986,   902,   775,  1388,    77,   943,   775,   687,
     775,  2986,  3058,   690,   775, -1803,   775,  1557,   920,  2521,
     920,   824,  1188,   920,   824,  3058,   920,  1407,  3079,  1195,
    1409,  1410,  1407,  3102,  1219,  2869,  1222,  2382,  2769,    82,
    1782,  1142,  3119,  1785,  1830,  1583,  1412,  2817,  1143,  1429,
    2665,  1313,  2665,  2671,  2487,  1365,  2180,    41,  2834,  2522,
    2530,  2531,  2532,  2533,  1361,  2278,  2507,  1389,  1366,   267,
    1365,  1540,  1640,  1641,   341,   737,   698,    41,  1832,   403,
    1204,  1651,  1297,  1366,   687,  2249,   865,   821,  1990,  2455,
     672,   908,    41,   982,   702,  1378,   380,  3044,   884,  2430,
     741,   687,  1261,  1227,  2939,  2940,  1266,   943,  1983,  2961,
    1543,  1866,  2767, -1803, -1803, -1803, -1803, -1803, -1803,  2872,
    3114,   139,  2409,  1521,  1691,  1922,  2570,  2791,   969,  1522,
    1523,  1524,   382,  2495,  2830,  1344,   690,   690,   690,    76,
    1150,  2503,  2504,  1890,  2764,  2740,   933,   823,   873,  1525,
     984,  1478,   390,  2881,  1208,  1493,   400,   991,  1891,   409,
    2937,  2661,  2023,  1492,  3078,   272,   799,  1758,  1345,  2392,
     402,  1225,  1513,  2437,   699,  2356,   406,  1024,  2076,  1348,
    1514,   944,  1139,   143,   750,   944,  1473,   944,  1974,  1027,
    2556,  1175,   822,  2735,  1545,  1211,   272,  1744,   775,   775,
     775,  2967,   822,  1498,   272,  2742,  1310,   822,  2392,  2747,
    1922,  1479,  2706,   702,   775,  3115,  1266,  3116,  1747,  1407,
     775,   775,  2725,  1310,  1560,   775,  1762,  2295,  2426,   141,
     272,  1748,  2063,  1558,  2107,  2407,  2063,    41,  2678,    82,
    2681,  1209,  1876,  2063,  2427,  1176,  1591,  1578,  1573,   934,
    1852,  2411,  1001,  2152,    82,  1367,  1853,  1526,  2048, -1803,
    1527,   272,  2712,  1027,  2062,  2077,  2302,   945,   946,   947,
     272,  1295,   835,   873,  1365,  1599,  1600,   755,   948,   188,
    2073,  1890,  2078,  2096,  1528,  2107,  1368,  1366,  2393,   757,
     758,  2672,  2063,  3127, -1803,  2098,  1891,   759,  1553,  2317,
    2009,  1368,  1369,  1262,  1529,  2275,   652,  2406,  2520,   775,
     775,  2408,  1647,  2519,  2433, -1803,  2941,  1369,   259,   260,
     261,   262,   263,   145,  2451,  2079,  2771,  2393,  2665,   653,
    1631,  1632,  2452,  2457,  3108,  2491,  1263,  1390,  2566,  1530,
    1002,  2615,  2660,  2696,   775,  2394,  1350,  1612,  1806,  1352,
     775,  1570,   194,  2776,  1480,  1481,  1482,  2222,    44,  1531,
    1532,    41,   775,    41,  2782,  2080,  2801,   775,   272,  2524,
    1533,   195,  1234,  2823,  1504,  1534,  2818,  1391,  2816,  2824,
    2826,  2936,   272,  1003,  2394, -1803,  2994,  2987,  2996,   233,
    1252,  2908,     1,   303,  2081,  1353,  2988,  3059, -1803,    82,
    2796,  1731,  1742,  2082,   198,   775,   134,  2469,     2,     3,
    3065,  1541,  1993,  3080,  1535,  3135,  2923,   102,  3103,   775,
     304,  2934,   103,  2377,  2956,  2380,  2807,  3120,  2673,  1648,
    2674,  1387,  3144,  1159,   234,  2964,   884,  2034,   697,  2938,
      41,  2759,  1847,    41,  1612,  2713,  1536,  2412,  1666,  2833,
    1653,  2944,  1156,  1566,  1496,  1879,  2714,  1972,  1574,  1381,
   -1803,    41,  1781,  1581,   830,  1784,    41,   104,   105, -1803,
    2466,   241,  1612,  1362,  2395,   106,    41,  1370,  1379,  1370,
    2188,  1616,    34,    35,     5,     6,  2525,     7,     8,   875,
     699,    41,     9,   699,   257,  1394,  1397,  2552,    41,   706,
     881,  2481,    41,   133,   134,  1368,   272,    41,   249,    10,
      11,  2554,    41,  2395,   824,   775,  1831,   824,   824,   824,
     824,  1369,   775,    82,  3089,   775,  2474,    12,  3090,    81,
      41,    41, -1803,  1354, -1803,   250,   824,    45,   775,  1649,
    2396,   414,   775,    58,  2254,    41,  2374,  2892,  1353,   656,
     775,    46,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,  1857,  1416,  1417,  2924,    47,  2926,  1616,  2396,
    2823,  2823,   775,   775,  3130,  2679,  1873,   775,  3050,   775,
    1382,    41,   252,  2425,  1674,   684,  2526, -1803,  1929,  1931,
     958,  1245,   698,    41,  1469,    82,  1616,   892,   715,  1355,
    2694,   959,   699,  2698,  1157,   253,  1418, -1803,   775,   775,
     775,  1419,  1420,  1421,    48,  1941,   254,   785,   698,   824,
    1633,  1495,  2400,  1499,   824,  2942,   285,  2289,   775,  1971,
     794,  2966,  2947,  2522,  2950,  2951,  2952,  2953,  1639,  2745,
    1291,   286,    41,    82,  1643,    41,  2948,   893,  2797,  2307,
      82,   265,  2948,   960,    82,  2957,  2958,  2959,  2960,   288,
    2594,  2594,  2594,  2594,    82,   775,  2001,  1474,   961,    41,
    2509,   824,    41,   690,   687,  2002,  1354,   907,  2475,   289,
     337,   911,    82,    82,   894,   915,  1682,  1800,  1016,   290,
     775,  1846,   294,  1418,  1555,  1688,   824,   824,  1419,  2003,
    1421,   824,  2004,  1357,   295,  1564,  1565,   775,  -266,   297,
    1654,  1825,  3037,  3038,  1674,  1482,  3008,   775,   107,  1358,
    2005,  1655,  2110,     2,     3,  2656,   301,    41,  1675,  3105,
    2108,   699,  2277,  2102,  2415,    41,  2417,  2418,   920,   824,
     824,   652,  1809,  1656,   108,  1810,  1204,  1676,  1677,   306,
    1657, -1803,  1355,   315,  1402,    82,   324,  2667,   962,  2670,
     964,   965,  2434,   971,   653,  1635,  1094,  1678,  1027,  1027,
   -1803, -1803,  1865,  1644,  2310,  1644,  2326,  1027,   697,  1095,
      41,   895,  2359,  3057, -1511,   325,  3060,  3061,  3062,  3063,
   -1803, -1803,  3049, -1803,  2153,  -266,  2154,   690,  3055,     5,
       6,  3082,     7,     8,    82,  2165,   331,     9,  1821,   334,
    1356,   984,  -266, -1803, -1803,   109,  1809,   335,   690,  1810,
    1027,  1032,  1033,  1034,    10,    11,  2006,  3110,   336,  3112,
    2516,    82, -1803,  1370,    82, -1803,  1096,  1097,  1098,  1099,
    1100,  1101,    12,  2176,  1379,  1582,   134,  1370,  1811,   735,
   -1803,  1812,  1102,  1103,  1104,  -266,  1357,   896,  1675, -1803,
    1605,   736,  1606,  1607,  1608,   340,  1738,  1739,  1740,  1661,
    1662,  2217,  1358,  1612,  1612,  1822,  1823,  1676,  1677,   342,
    2007,  2551,  1090,  1091,  1092,  1093,  1094,  2008,   343,    82,
     924,  1127,   347,   927,  3122,  -266,   930,  1678,   897,  1095,
     307,  3029, -1803,   775,   775,   775, -1803,   775,  3008,   110,
     348,   813,    13,  2700,  1026,  2702,    41,   351,   133,   134,
     819,  1238,  1811,   352,  -266,  1812,  3089,  1232,   353,    41,
    3090,   354,   835,  -266,   775,   357,  2104,  1791, -1803,  2594,
    2594, -1803,  1385,  2594,    41,  1912,   358,  1612,   133,   134,
    2016,   775,    41,   873,  1669,  1670,  1096,  1097,  1098,  1099,
    1100,  1101, -1803, -1803,  3111,   923,   898, -1803,   926,  1819,
   -1803, -1803,  1102,  1103,  1104,   775,   368,  1826,  1827,   775,
     824,   369,  1128,  2245, -1803,   387,  2120,   308,  2121,   111,
    2236,  2237,  1105,   372,  1475,  1106,  1475,   112,  2155,  2156,
    1482,  2159,  3094,   377,   309,   752,   388,  1616,  1616,   391,
     775,  2103,  1239,  1189,  1190,   775,   395,  1193,  1194,   945,
     946,  3029,  2182,   396,  2727,  1855,  2728,  2805,  2806,   775,
     899,  2122,  1214,  1215,  1216,  1217,   775,  1654,   274,     1,
     397,   316,   279,  2895,   775,  2896,   398,   310,  1655,   404,
    1880,  1252,   407,  1905,   415,     2,     3,  1605,   657,  1606,
    1607,  1608,  2238,  2239,  2240,  2241,  2242,  2243,   662,   664,
    1656,   665,   666,   671,   754,   824,   824,  1657,   674,  2214,
     676,  1616,  3094,   756,     4,   677,   696,   311,   678,   824,
     681,   680,   682,   683,     1,  1609,   685, -1803,  1610,   714,
    1611,   973,  2428,  2754,   974,   975,   976,  2113,  1027,   977,
       2,     3,  1105,    16,  1107,  1106,   312,   978,   979,   980,
    1612,  2842,   981,  2753,   983,   313,   786,  2017,   317,  1108,
    1613,     5,     6,  1109,     7,     8,   987,   988,   989,     9,
    2029,  2029,   803,   804,  2029,   318,   990,   994,   810,   690,
    1013,   812,  1014,  2458,   134,   690,    10,    11,  1017,  1019,
    1905,  1020,  2064,  2064,  1025,  1029,  2064,  1905,  1039,  1038,
    1041,  1110,  1614,  2594,    12,  1140,  1615,   690,  1042,  2594,
    2594,  1043,  2594,  2594,  2594,  2594,     5,     6,   319,     7,
       8,  2594,  1044,  2099,     9,  1045,  1394,  2710,  1046,  1111,
     775,    81,   783,    41,  2304,  1047,  2305,  1370,  1048,   824,
    1049,    10,    11,  1060,  1061,  1905,   792,  1062,  1112,  1065,
     797,  1066,     2,     3,  1069,  1071,  1072,  1073,   320,    12,
    1074,  1075,   811,  1076,  1107,  1077,  1078,  1129,  1136,  2547,
    1141,  2549,  1147,  1144,    13,  1145,  1148,   775,  1153,  1108,
     775,  2223,  2757,  1109,  1616,  1158,  1167,   321,  1370,  1155,
    1172,  1186,   775,   775,   775,   775,   322,  2064,  2601,  2601,
    2601,  2601,  1152,  2167,  1819,  1051,  1196,  2172,  2172,   259,
     260,   261,   262,   263,   835,  1199,   775,  1220,   718,   718,
     873,  1110,  1609,  1237,  1228,  1610,  2184,  1611,     5,     6,
    1113,     7,     8,  1229,  1230,  1231,     9,  1235,  1249,  2360,
    2594,  1240,   873,  2594,  2594,  2594,  2594,  1612,  1251,  1111,
    1241,  1272,  2849,    10,    11,  2361,  2362,  1613,  1273,  1271,
    1205,  1274,  1279,  2363,  1287,  1283,  2422,  1286,  1112,  1288,
    1289,    12,  1335,   775,  2899,  2848,  1938,  1343,  1364,  1346,
    1905,  1905,  2907,  1384,  1401,  1400,  1402,  2113,  1403,  1905,
    2460,  1404,  1052,  2465,    14,    82,  1114,  2364,  1413,  1614,
    2231,  1427,  2076,  1615,  1430,  1016,  2365,  1435,  1464,  1053,
    1428,  1467,   699,   718,  1211,  1472,  2682,  2850,  1485,  2851,
    2255,  1507,  1503,   935,  2628,  2629,  2630,  1471,  2632,  2633,
    2634,  2635,  2636,  2637,  2852,  2366,  1509,  2640,  1518,  2379,
       1,    13,  2853,    15,  1519,  1505,  2854,  2849,  1491,   865,
    1113,  2594,  1054,  1544,  1546,  1547,     2,     3,  1549,  2594,
    2701,  1551,  1556,  1559,  1561,  1570,  2717,  1585,  1027,  1577,
    1584,  2855,  1579,  1281,  1628,    16,   690,   690,  1625,  1587,
    2367,  1616,  1626,  2064,  1683,  1623,  1905,  1634,  1694,  2077,
    2736,  1696,  1055,  2293,  1644,  1905,  2710,  2965,   775,   649,
     775,  1727,  2749,  2683,  1729,   649,  2078,  1697,  2064,  2751,
    1027,  1700,  2850,  1732,  2851,  1701,  1114,  1730,  1733,  2029,
    2684,  1056,  2368,  1734,  2514,  1745,  1746,  1750,  1752,  2852,
    1057,  1759,     5,     6,  1761,     7,     8,  2853,  1763,  1764,
       9,  2854,  2064,  1766,  1790,  1905,  1769,  1905,  1795,  2079,
    3028,  1796,  1797,  2718,  1798,   651,  1802,    10,    11,  2064,
    1793,   651,  1799,  2685,  1801,  1803,  2855,  1804,  1370,  1805,
    2719,  2593,  2593,  2593,  2593,    12,  1807,  2601,  2601,    89,
    1808,  2601,  1280,  1835,  1820,  1833,  1836,  1837,   935,  2080,
    1841,  1379, -1803,  1370, -1803, -1803, -1803,  1844, -1803,  1850,
    1851,  1738,  1856,  2686,   775,  1859,  1860,  1863,  1869,  2440,
    1883,   835,   835,  2720,  2528,  1877,  1916,  1917,  2081,  1918,
    2528,  1912,  2537,  2538,  2539,  2540,   948,  2082,  1969,  1922,
    1970,  1924,  2687,  1981,  1126,  1997,  1987,  2012,  1998,  2014,
    2015,  2688,    16,  2026,   775,   775,  2037,  2038,  2039,  2043,
    2101,   183,   191,  2721,   775,  2046,  2085,   775, -1803,  2086,
    2087,  2088,  2467,  2089,  2090,  2105,  2113,  2866,  2125,  2117,
    2866,  2710,  2118,  2710,  2128,  1819,  2138,  2482,  2139,  2484,
    2119,  2140,  2722,  2143,  2144,  2146,   775,  2148,  3118,   775,
    2150,  2723,  2161,  2499,  2183,  2191,  2192,   775,   775,  2166,
    2181,  3036,  2194,  2195,  2196,  2198,   191, -1803,  2199,  2197,
    2215,  2216,   191,   775,  2224,  2750,  2225,  2226,  2227,  2228,
    2064,  2229,  1905, -1803,  2233, -1803,  2230,  2253,  1905,  1905,
    1905,  1905,  1905,  1905,  3095,  3096,  3097,  3098,  3099,  3100,
   -1803,  2898,  2260,   947,  2765,  2262,  2271,  2272, -1803,  2273,
    2276,  2291, -1803,  2312,  2280,  2281,   824,  2314,   824,  2288,
    2315,  2313,   838, -1803,  2320,    14,  2901,  2234,  2235,  2236,
    2237,   839,  2383,  2783,  1905,  2402,  2376, -1803,  2403,  2413,
     840,  2404,   191,  2416,   191,   841,  2675,  2064,  2410,  2419,
   -1748,  2429,  2744,  2592,  2592,  2592,  2592,  2064,  2064,  2821,
    2822,  2435,  2841,  2441,  2442,   935,  2443,  2444,  2617,  2618,
    2017,  2601,  2445,  2446,    15,  2456,  2621,  2601,  2601,  2459,
    2601,  2601,  2601,  2601,  2113,  2447,  2448, -1803,   842,  2601,
   -1803,  2449, -1803,  2453,  2461,  2462,   843,  2468,  2472,  2476,
    2480,  2238,  2239,  2240,  2241,  2242,  2243,  2483, -1803,  2494,
    2593,  2593, -1803,  2502,  2593,  2520,  2534,  2543,   191,  2546,
    2557,  2518, -1803,  2558,  2567,  2381,  2574,  2512,  2436,  2710,
    2612,  2238,  2239,  2240,  2241,  2242,  2243,  1905,  2616,  1905,
    2626, -1803,  2819,  2820,  2821,  2822, -1803,  2627,  2645,  1905,
    2631,  1905,   844,  2638,  1905,  2639,  2646,  2649,  2650,  2064,
    2680,  2064,  2651,  2652, -1803,  2653,  2654,  2113, -1803,  2655,
    2222,  2666,  2669,   191,  2676,  2774,  1354,   845,  2777,  2778,
    2779,  2780,  2690,  2692,   846,  2697,   847,  2699,  1370,  2703,
    1990,  3013,  1905,  1027,  2726,  2732,   848,  2737,  3155,  2738,
    2865,  2740,  2739,  2865,  2752,  2755,   775,  2758,  2601,  2762,
     712,  2601,  2601,  2601,  2601,  2772,  2238,  2239,  2240,  2241,
    2242,  2243,   849,  2773,  2787, -1803,  2798,   942,  2172,  2902,
     850,  2746,  2172,  2808,  2791,  2817,   824,  2809,  2827,   775,
    2828,  2839,  2810,   824,   788,  2811, -1803,  2866,  2838,  2846,
     793,  2400,   795,  2812,  2813,  2814,   802,   775,  2874,   802,
    2875,  2124,   802,  2861,  2879,  2126,  2877,   851,   775,  2878,
    2129,  2883,   814,  2891,  2133,  1905,  2135,  2136,  2137,  2880,
    2893,  2886,  2894,  1905,  2900,   690,  1905,  1905,  1905,  1905,
    2781,   863,  1299,   852,  2897,  2904,  2906,   775,  2910,   876,
     879,   882,  2914,  2916,   935,   903,    50,    51,    52,    53,
      54,    55,    56,   913,  2788,  2912,  2913,  2918,  1341,  2601,
   -1803,  2064,  2870,  2922,  2925,  1702,  2927,  2601,  2929,   937,
    2293,   853,  2592,  2592,  2930,  2931,  2592,  2933,  2932,  2943,
    2954,  2945,   854,  2962,  2593,  2437,  2990,  2815,  2981,  2982,
    2593,  2593,  2991,  2593,  2593,  2593,  2593,   718,  2992,  2993,
    3011,  3000,  2593,  3014,  3026,  3027,  3035,  3042,  3056,  3043,
    2064,  3081,  1635,  3045,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  3066,  3077,  3083,
    3101,  3088,  3113,  3121,  1300,  2984,  3123,  3124,  3125,  1095,
    3126,  3139,  1301,  2498,  3149,  3138,  3150,  2431,  1302,  2454,
    1303,  2207,   935,  1569,  1868,    72,    73,   560,  2168,  2177,
     873,  1304,   699,  2928,  2479,   699,   197,  1905,   349,   202,
    1905,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,   281,   855,   856,   857,  2113,   345,   675,   350,  1305,
    1686,  1685,   408,  1095,   283,   858,  1096,  1097,  1098,  1099,
    1100,  1101,  1027,   661,  2127,  1306,  2884,   376,  2889,  2729,
    1307,   667,  1102,  1103,  1104,   668,   374,  3136,  1843,  2145,
     901,  2593,  1308,  1755,  2593,  2593,  2593,  2593,   824,  1309,
    3041,  2027,  2035,   775,   937,  1828,  1339,  2157,  1598,  2545,
    2786,  1921,  2252,  1602,  3142,  2164,  1939,  2909,    67,   157,
    1096,  1097,  1098,  1099,  1100,  1101,  1500,    68,  3104,  2859,
    2865,    69,  1875,   339,   972,   809,  1102,  1103,  1104,  1878,
     993,  1905,  2847,  1622,  2999,  2247,  1882,  2972,  1277,  1487,
    1984,  3109,  2536,  2659,  1477,  2980,  1223,  1552,  2658,  2641,
    1436,  2372,  1695,  1905,  1399,  1539,  2064,  1728,   859,  2151,
    1703,  2282,  1130,  3143,  2064,  3132,  2592,  2311,  3067,  2373,
    2677,  2074,  2592,  2592,  2882,  2592,  2592,  2592,  2592,  2711,
    2662,  2064,  2375,  2064,  2592,  2663,  1905,  2868,  3075,  2873,
    2399,  3054,  2593,  1638,  2971,  2619,  1327,  3009,  2573,  3010,
    2593,  2804,  2705,  3131,  2535,  1161,  1630,   159,  3048,  1294,
    2803,  2946,  1105,  2963,  2955,  1106,  2100,  1494,  1704,     0,
     416,  1178,  1178,  1178,  1596,  1178,     0,  1178,  1178,     0,
    1705,  3148,     0,    89,    89,     0,     0,  1027,  3076,  1027,
    1706,     0,  1905,     0,  1310,     0,   160,  2064,     0,  2889,
       0,  1311,     0,     0,     0,     0,     0,     0,  1707,     0,
       0,     0,     0,     0,     0,   161,  1105,     0,  1708,  1106,
       0,  1709,     0,  1312,     0,     0,   882,     0,  1313,     0,
       0,  1664,  1665,     0,  1710,     0,     0,  1247,  1681,     0,
       0,  2788,     0,     0,     0,     0,     0,     0,     0,  1905,
       0,     0,     0,  2592,   162,     0,  2592,  2592,  2592,  2592,
    3064,   937,  1130,     0,     0,     0,   163,     0,     0,  1906,
    1284,     0,     0,     0,  1635,     0,   164,     0,     0,  2999,
       0,     0,     0,  1711,  1107,     0,  1292,  1292,     0,     0,
       0,     0,   699,     0,   165,     0,  1905,     0,     0,  1108,
       0,     0,     0,  1109,   166,     0,  1905,     0,     0,     0,
       0,     0,     0,  1712,     0,     0,     0,  3054,     0,     0,
     167,     0,     0,  1713,     0,     0,     0,     0,     0,     0,
       0,     0,   775,  3106,     0,     0,     0,     0,  1107,     0,
     775,  1110,     0,     0,  1714,     0,     0,  1715,     0,  1716,
       0,     0,     0,  1108,     0,     0,     0,  1109,     0,     0,
     168,     0,     0,     0,  2592,     0,     0,     0,     0,  1111,
       0,     0,  2592,     0,     0,     0,  1906,  1717,     0,     0,
    1035,  1036,  1037,  1906,   169,  1027,  1718,  1905,  1112,  2064,
       0,     0,     0,     0,     0,  1110,  1050,     0,     0,   170,
       0,     0,  1063,  1064,     0,     0,   171,  1068,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,  1905,     0,     0,     0,     0,
     173,  1906,     0,   174,     0,   175,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,   775,     0,     0,     0,     0,
       0,     0,  1849,     0,   176,     0,     0,  1470,     0,     0,
       0,     0,     0,     0,     0,    89,     0,    89,   882,   802,
    1113,     0,   177,     0,     0,     0,  1486,   814,     0,     0,
     882,     0,     0,     0,   191,     0,     0,  1501,     0,     0,
       0,     0,     0,     0,     0,  1919,     0,     0,     0,     0,
     937,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1113,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1114,     0,     0,     0,
       0,  1767,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1089,
    1090,  1091,  1092,  1093,  1094,  1562,  1906,  1906,     0,     0,
       0,  1095,     0,     0,     0,  1906,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1589,
    1114,     0,     0,     0,  1592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1621,   937,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,     0,  1102,  1103,  1104,     0,  2576,  2577,
    1102,  1103,  1104,     0,   269,  1887,  1888,    41,     0,     0,
       0,     0,     0,  1668,     0,     0,     0,     0,     0,     0,
       0,     0,  1906,     0,     0,     0,     0,     0,     0,     0,
       0,  1906,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2578,     0,     0,  1408,     0,     0,
       0,     0,     0,     0,  1415,     0,     0,  1426,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   882,     0,
    1431,     0,     0,     0,  1434,     0,     0,     0,     0,     0,
       0,  1906,  1440,  1906,  1442,  1443,  1444,  1445,  1446,  1447,
    1448,  1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,
    1458,  1459,  1460,  1461,     0,     0,     0,     0,     0,  2203,
    2204,     0,     0,     0,  1462,  1463,     0,     0,     0,  1465,
    2213,  1466,     0,     0,  1906,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,     0,  1106,     0,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   698,
       0,     0,     0,  2256,  2257,  2258,  2259,     0,     0,     0,
       0,  2264,  2265,  2266,  2267,     0,     0,     0,  2269,     0,
       0,     0,     0,     0,     0,  2190,  1079,  1080,  1081,     0,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,     0,     0,
    1840,     0,     0,     0,     0,  1095,     0,     0,     0,  1848,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   882,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,     0,  1906,     0,
     183,     0,  1107,     0,  1906,  1906,  1906,  1906,  1906,  1906,
       0,  1108,  2318,  2319,     0,  1109,     0,  1108,     0,  2323,
    2324,  1109,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,  1103,
    1104,     0,     0,     0,     0,     0,   882,  1973,   882,     0,
    1906,     0,   876,  1110,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,     0,     0,  1095,     0,     0,     0,  1906,
    1906,  1906,  1906,     0,     0,     0,     0,     0,     0,     0,
       0,  1111,     0,     0,  2021,     0,     0,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1112,     0,     0,   718,   718,   718,  1112,   718,   718,   718,
     718,   718,   718,     0,  1890,     0,   718,     0,     0,     0,
       0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,  1891,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,  1103,
    1104,     0,     0,     0,     0,     0,  2579,     0,     0,  2580,
     882,   191,     0,  1906,     0,  1906,     0,  2470,  2471,     0,
       0,     0,  2581,     0,     0,  1906,  2478,  1906,     0,     0,
    1906,     0,     0,     0,  2489,     0,     0,     0,  1105,     0,
       0,  1106,  1113,     0,     0,  1770,  1771,  1772,  1113,  1774,
       0,     0,     0,  2505,  2506,     0,     0,     0,     0,     0,
       0,     0,  2582,  2583,     0,     0,     0,     0,  1906,     0,
       0,   882,     0,   882,     0,  2584,  1789,     0,     0,     0,
       0,     0,   882,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   385,  1114,  2548,
       0,  2550,     0,     0,  1114,     0,     0,  2585,     0,     0,
    2189,     0,     0,     0,     0,     0,     0,     0,     0,   935,
       0,     0,     0,     0,     0,     0,     0,     0,  1105,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,  2212,
       0,  1906,     0,     0,     0,     0,  2586,  1845,     0,  1906,
    1107,     0,  1906,  1906,  1906,  1906,     0,     0,  2587,  2622,
    2623,  1789,     0,  2624,  2625,  1108,     0,     0,     0,  1109,
    2588,  2589,     0,     0,     0,     0,     0,     0,  2590,     0,
       0,  2591,     0,     0,     0,  2246,  1592,     0,     0,   272,
       0,     0,     0,     0,     0,     0,     0,  2648,  1906,  1906,
       0,     0,  1906,     0,     0,     0,     0,  1110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
    1107,     0,     0,     0,  1112,     0,     0,     0,     0,  1095,
       0,     0,     0,     0,     0,  1108,     0,     0,     0,  1109,
       0,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1906,     0,
    2316,  1906,     0,  1906,     0,     0,  1906,     0,     0,     0,
    1095,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  2743,     0,     0,     0,  2748,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,  1103,  1104,  1111,  1113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2763,     0,     0,     0,
       0,   159,     0,     0,  1112,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,     0,     0,   882,
       0,     0,     0,  1102,  1103,  1104,     0,     0,     0,  2141,
    2784,     0,  2141,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,     0,     0,     0,     0,  1906,     0,     0,
       0,     0,  1114,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1906,
     882,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1906,     0,     0,     0,  1113,     0,  1906,  1906,
       0,  1906,  1906,  1906,  1906,     0,     0,     0,   162,     0,
    1906,     0,  1906,  1592,     0,     0,     0,     0,     0,     0,
     163,     0,  2496,     0,   712,     0,  2500, -1804,     0,     0,
     164,     0,  1105,     0,     0,  1106,     0,     0, -1804,  2511,
   -1804, -1804, -1804,  1906,   191,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,  1114,     0,     0,     0, -1804,     0,  1906,     0,
       0,     0,     0,  1105,   167,     0,  1106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2049, -1804,     0,     0,   935,     0,
    2553,  2555,     0,  1884,  1885,     0,  1886,     0,     0,   269,
    1887,  1888,    41,     0,   168,  1886,     0,     0,   269,  1887,
    1888,    41,     0,     0,     0,  1906,     0,     0,     0,  1906,
       0,     0,  1906,  1906,  1906,  1906,     0, -1804,   169,     0,
       0,     0,     0,  2620,     0,     0,     0,     0,     0,  1889,
       0,     0,     0,   170,  1107,     0,     0,     0,  1889,     0,
     171,     0,     0,   172,  2921,     0,     0, -1804,  1906,  1108,
   -1804,     0,  1906,  1109,     0,     0,     0,     0,     0,     0,
       0,     0,  1906,  2642,   173,     0,     0,   174,     0,   175,
       0,     0,     0,     0, -1804,  1107,  2657,     0,     0,     0,
       0,     0, -1804,     0, -1804,     0,     0,     0,   176,     0,
    1108,  1110,     0, -1804,  1109,  1432,     0,     0,     0, -1804,
       0,     0,     0,     0,     0,     0,   177, -1804,     0,     0,
       0, -1804,     0,     0,     0,     0,     0, -1804,     0,  1111,
    1906, -1804, -1804, -1804, -1804,     0,     0,     0,  1906,     0,
       0,     0,  1110,     0,     0,     0, -1804,   882,  1112,     0,
       0,     0,     0,  1906,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1804,   698,     0, -1804,     0, -1804,     0,
    1111,     0,     0,   698,     0, -1804,     0,   882,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1804,  1112,
       0,  1906,   191,     0,     0,     0,  1789,  1789, -1804,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3039,     0,
       0,     0,     0,     0,     0,   937,     0, -1804, -1804,     0,
       0,     0,     0,     0,     0,   935,     0,     0,     0,     0,
    1113,     0, -1804,     0,     0,     0,     0,     0,  2493,     0,
   -1804,  1789,     0,     0, -1804,     0,     0,     0,     0,  1789,
    1789,     0,     0, -1804, -1804, -1804,     0,     0,     0,     0,
       0,  3068,  3069,     0,  3071,     0,  3073,  3074,  2050,     0,
       0,  1113,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,     0,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1804,  3117,     0,     0,  1114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,  3128,     0,
    3129,     0,     0,  2642,     0,  1102,  1103,  1104,     0,  1890,
       0,     0,     0,     0, -1804,     0,     0,     0,  1890,     0,
       0,     0,     0,     0,  1891,     0,     0,     0,     0,     0,
       0,     0,     0,  1891,     0,  3140,     0,     0,     0,     0,
       0,  1892,     0,     0,  2051,     0,     0,     0,     0,     0,
    1892,     0,     0,  1893,     0,     0,  2052,  1894,     0,     0,
       0,  3145,  3146,     0,     0,  3147,  1894,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1804,     0,     0,     0,
       0,     0,     0,     0,     0,  2222,     0,     0,     0,     0,
       0,     0,     0,   882,     0,     0,     0,     0,  1896,     0,
       0,     0,     0,     0,     0,     0,     0,  1896,     0,     0,
    1897,     0, -1804,     0,     0,     0,     0,     0,     0,  1897,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2730,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,  1106,  1592,
       0,     0,  1898,     0,     0,     0,     0,     0, -1804,     0,
       0,  1898,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1804, -1804, -1804, -1804, -1804, -1804, -1804,     0,
   -1804, -1804,     0,     0,     0,     0,     0,     0,     0,  1789,
    1592,  1899,     0,     0,     0,     0,     0, -1804,     0,     0,
    1899,     0,     0,  1900,  2642,     0,     0,     0,     0,  2975,
       0,  2977,  1900,     0,     0,  1901,  1902,     0,     0,     0,
       0,     0,     0,  1903,  1901,  1902,  1904,     0,     0,     0,
       0,     0,  1903,     0,   272,  1904,     0,     0,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
     882,     0,     0,     0,     0,  2576,  2577,     0,   882,     0,
       0,   269,  1887,  1888,    41,     0,     0,  1107,     0,     0,
       0,     0,     0,     0,   937,     0,     0,     0,     0,     0,
     191,     0,  1108,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,  2578,     0,     0,     0,  2576,  2577,     0,   418,     2,
       3,   269,  1887,  1888,    41,     0,     0,   419,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,   420,
     421,     0,   422,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   423,     0,     0,     0,
       0,  2578,  1111,   424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,   426,   427,     0,     0,     0,
       0,  1112,     0,  1178,  1178,  1178,  1178,  1178,  1178,     0,
     428,     0,   429,   430,   431,     5,     6,   432,     7,     8,
     433,     0,   434,     9,   435,   436,     0,     0,     0,     0,
       0,   437,     0,     0,   438,     0,   439,   440,   441,     0,
      10,    11,     0,     0,     0,     0,   442,     0,   443,   444,
       0,   445,     0,   446,   447,     0,   698,   448,    12,     0,
       0,   449,   450,   451,     0,   452,   453,     0,     0,     0,
     454,   455,     0,   456,     0,     0,     0,   457,     0,   458,
     459,     0,     0,  1113,     0,   460,     0,     0,     0,   461,
       0,     0,   462,     0,   463,     0,   464,     0,   465,     0,
     466,   467,     0,   468,   469,   470,   698,     0,     0,   471,
       0,   472,   473,     0,   474,     0,     0,     0,     0,     0,
       0,     0,   475,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   477,     0,     0,   478,   479,
       0,   937,   480,   481,     0,     0,   482,   483,     0,  1114,
       0,     0,     0,     0,     0,   484,   485,   486,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
     489,   490,     0,   491,     0,     0,     0,   492,   493,     0,
       0,     0,   494,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     498,     0,     0,     0,     0,     0,   499,   500,     0,     0,
       0,     0,   501,     0,     0,   502,     0,     0,     0,   503,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,   506,     0,
       0,     0,     0,     0,     0,     0,   507,     0,     0,     0,
    1095,  1890,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1891,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,   509,  2579,   510,   511,  2580,     0,     0,     0,
       0,     0,     0,   512,     0,     0,     0,     0,     0,  2581,
       0,  1890,     0,     0,     0,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,  1891,     0,     0,     0,
       0,     0,     0,  1102,  1103,  1104,     0,  2222,     0,     0,
       0,     0,   513,  2579,     0,     0,  2580,     0,     0,     0,
    2583,     0,  1789,   514,     0,     0,     0,   515,     0,  2581,
       0,   516,  2584,     0,     0,     0,     0,     0,     0,  2329,
    2330,     0,     0,  2331,  2332,  2333,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,   518,     0,     0,     0,
     519,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2583,     0,   520,     0,  2585,     0,     0,     0,   521,   522,
     523,   524,  2584,     0,     0,   525,     0,     0,     0,   526,
       0,     0,     0,     0,     0,     0,   527,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
     530,     0,     0,  2586,     0,     0,     0,     0,     0,     0,
       0,   531,     0,   532,  2585,  2587,   533,     0,     0,     0,
       0,     0,   534,     0,     0,     0,     0,  2588,  2589,     0,
       0,     0,  2334,  1105,     0,  2590,  1106,     0,  2591,  2335,
       0,     0,     0,     0,     0,     0,   272,     0,   535,     0,
       0,   536,     0,  2586,     0,     0,   537,     0,     0,   538,
     539,     0,     0,     0,     0,  2587,     0,     0,     0,     0,
       0,     0,     0,  2336,   540,     0,     0,  2588,  2589,     0,
       0,   541,  2337,     0,     0,  2590,     0,     0,  2591,     0,
       0,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,   542,   543,   544,   545,   546,   547,
     548,  2338,  2339,   549,     0,   550,     0,   551,  1079,  1080,
    1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,  1107,  2340,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,  1109,  1751,     0,     0,     0,     0,
       0,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  2341,     0,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
    1095,     0,  1110,     0,     0,     0,     0,     0,     0,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2342,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,  1103,  1104,  1079,  1080,  1081,     0,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1095,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1113,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,  1095,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,  1103,
    1104,     0,     0,     0,     0,  1884,  1885,     0,  1886,     0,
       0,   269,  1887,  1888,    41,     0,     0,  1114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,  1106,     0,  1096,  1097,
    1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,
       0,  1889,     0,     0,  1102,  1103,  1104,  1079,  1080,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,  1107,  2343,  2344,  2345,  2346,  2347,  2348,  2349,
    2350,  2351,  2352,     0,     0,     0,     0,  1108,     0,     0,
       0,  1109,  1760,  1079,  1080,  1081,     0,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,  1105,     0,
       0,  1106,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1110,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,  1102,
    1103,  1104,     0,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,  1109,  1765,   698,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,  1112,  1106,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,  1102,  1103,  1104,  1079,  1080,
    1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
    1107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1108,     0,     0,  1113,  1109,
    1773,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,  1105,
       0,     0,  1106,     0,  1096,  1097,  1098,  1099,  1100,  1101,
    1095,     0,     0,     0,     0,     0,  1107,  1110,     0,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,     0,     0,
       0,  1108,     0,     0,     0,  1109,  1775,     0,     0,     0,
       0,  1113,     0,     0,  1114,  1111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,  1106,     0,
       0,     0,     0,     0,  1112,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,  1110,     0,     0,     0,     0,     0,     0,
       0,  1890,     0,  1102,  1103,  1104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1891,     0,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,  1114,     0,     0,
       0,     0,     0,  1892,     0,     0,  1893,     0,     0,     0,
    1112,  1107,     0,     0,     0,     0,     0,     0,     0,  1894,
       0,     0,     0,     0,     0,     0,  1108,     0,     0,     0,
    1109,  1776,     0,     0,     0,     0,  1113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,  1106,     0,     0,     0,     0,     0,  1895,
    1896,     0,     0,     0,     0,     0,     0,  1107,  1110,     0,
       0,     0,  1897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,  1109,  1777,     0,     0,
       0,     0,  1113,     0,     0,     0,  1111,     0,     0,     0,
       0,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,  1898,  1112,  1106,     0,     0,     0,
       0,  1079,  1080,  1081,  1110,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,  1111,  1899,     0,     0,     0,     0,  1114,     0,
       0,     0,     0,     0,     0,  1900,     0,     0,     0,     0,
       0,  1112,  1107,     0,     0,     0,     0,  1901,  1902,     0,
       0,     0,     0,     0,     0,  1903,     0,  1108,  1904,     0,
       0,  1109,     0,     0,     0,     0,   272,  1113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,  1103,  1104,     0,     0,     0,  1110,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,  1779,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,  1113,  1109,     0,     0,  1111,     0,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1079,  1080,  1081,  1780,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1114,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1095,     0,     0,     0,     0,     0,     0,     0,  1112,
    1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,  1113,     0,
       0,     0,     0,  1105,     0,     0,  1106,  1081,  1095,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,  1095,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,  1103,  1104,     0,     0,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1113,     0,     0,  1114,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
       0,  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,
       0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,
       0,     0,   722,     0,     0,     0,     0,  1102,  1103,  1104,
       0,   723,   724,     0,     0,     0,     0,   269,   725,   726,
      41,     0,     0,     0,     0,  1107,     0,  1114,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,
    1108,     0,     0,     0,  1109,     0,  1102,  1103,  1104,     0,
       0,     0,   727,     0,     0,     0,     0,   728,     0,     0,
       0,     0,     0,     0,   729,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,  1105,     0,     0,  1106,     0,     0,
       0,     0,   730,     0,     0,  1783,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1105,     0,     0,  1106,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,  1105,     0,     0,
    1106,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,    82,     0,   731,     0,  1105,     0,     0,  1106,
       0,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,     0,     0,     0,
       0,  1113,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,  1108,     0,   722,     0,  1109,     0,     0,     0,  1102,
    1103,  1104,   723,   724,     0,     0,     0,     0,   269,   725,
     726,    41,     0,  1107,     0,     0,     0,     0,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,  1108,     0,
       0,     0,  1109,  1110,     0,     0,  1102,  1103,  1104,  1107,
       0,     0,     0,   727,     0,     0,     0,  1114,   728,     0,
       0,   732,     0,     0,  1108,   729,   733,     0,  1109,     0,
       0,  1111,     0,     0,     0,     0,     0,     0,     0,     0,
    1110,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
    1112,     0,     0,   730,   734,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,     0,     0,  1110,  1109,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,   735,
       0,     0,     0,     0,  1111,     0,     0,     0,     0,     0,
       0,   736,     0,     0,     0,  1110,     0,     0,     0,  1105,
       0,     0,  1106,  1112,     0,     0,     0,     0,  1778,   737,
       0,     0,     0,     0,   738,     0,     0,   739,     0,     0,
       0,     0,  1113,  1111,     0,     0,     0,     0,   740,     0,
       0,     0,     0,    82,   741,   731,  1105,     0,     0,  1106,
       0,     0,  1112,     0,   742,     0,     0,     0,     0,   743,
       0,     0,   744,     0,     0,   745,     0,     0,     0,  1113,
       0,     0,     0,     0,   746,   747,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,  1113,     0,     0,  1114,     0,
       0,     0,     0,   723,   724,     0,     0,     0,     0,   269,
     725,   726,    41,     0,     0,  1201,   748,     0,     0,     0,
     749,     0,     0,     0,     0,     0,     0,     0,   750,     0,
       0,  1107,     0,     0,  1113,  1114,     0,     0,     0,   751,
       0,     0,   732,     0,   727,   752,  1108,   733,     0,   728,
    1109,     0,     0,     0,     0,     0,   729,     0,     0,     0,
       0,  1114,     0,     0,     0,     0,     0,     0,  1107,     0,
     753,     0,     0,     0,     0,   734,     0,     0,     0,     0,
       0,   722,     0,  1108,   730,     0,     0,  1109,  1110,     0,
     723,   724,     0,     0,     0,     0,   269,   725,   726,    41,
    1114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     735,     0,     0,     0,   754,     0,  1111,     0,     0,     0,
       0,   755,   736,   756,     0,  1110,     0,     0,     0,     0,
       0,   727,     0,   757,   758,  1112,   728,     0,     0,     0,
     737,   759,     0,   729,     0,   738,     0,     0,   739,     0,
       0,     0,   272,  1111,     0,     0,     0,     0,     0,   740,
       0,     0,     0,     0,     0,   741,     0,     0,     0,     0,
       0,   730,  1112,     0,    82,   742,   731,     0,     0,     0,
     743,     0,     0,   744,     0,     0,   745,     0,     0,     0,
       0,     0,     0,     0,     0,   746,   747,  2049,     0,     0,
       0,     0,     0,     0,     0,     0,  1884,  1885,     0,  1886,
       0,     0,   269,  1887,  1888,    41,     0,  1113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   748,     0,     0,
       0,   749,  1092,  1093,  1094,     0,     0,     0,     0,   750,
       0,     0,  1889,     0,  1113,     0,     0,  1095,     0,     0,
     751,    82,  2158,   731,     0,     0,   752,     0,     0,     0,
       0,     0,     0,   732,     0,     0,     0,     0,   733,  1884,
    1885,     0,  1886,  1114,     0,   269,  1887,  1888,    41,     0,
       0,   753,     0,  1884,  1885,     0,  1886,     0,     0,   269,
    1887,  1888,    41,     0,     0,     0,   734,     0,     0,     0,
       0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
    1114,     0,     0,     0,     0,  1889,     0,     0,     0,     0,
    1102,  1103,  1104,     0,     0,   754,     0,     0,     0,  1889,
       0,   735,   755,     0,   756,   269,  1887,  1888,    41,     0,
       0,     0,     0,   736,   757,   758,     0,     0,     0,     0,
     732,     0,   759,     0,     0,   733,     0,     0,     0,     0,
       0,   737,     0,   272,     0,     0,   738,   698,     0,   739,
       0,     0,     0,     0,     0,  2578,     0,     0,     0,     0,
     740,     0,     0,   734,     0,     0,   741,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   742,     0,     0,     0,
       0,   743,     0,     0,   744,     0,     0,   745,     0,     0,
       0,     0,     0,     0,     0,     0,   746,   747,   735,     0,
    1884,  1885,     0,  1886,     0,     0,   269,  1887,  1888,    41,
     736,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     698,     0,     0,     0,     0,     0,     0,     0,   737,     0,
       0,     0,     0,   738,   698,     0,   739,  2515,   748,     0,
    1105,     0,   749,  1106,     0,     0,  1889,   740,     0,     0,
     750,  2050,     0,   741,     0,     0,     0,     0,     0,     0,
       0,   751,     0,   742,     0,     0,     0,   752,   743,     0,
       0,   744,     0,     0,   745,     0,     0,     0,     0,     0,
     698,     0,     0,   746,   747,     0,     0,  1884,  1885,     0,
    1886,     0,   753,   269,  1887,  1888,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1093,  1094,     0,     0,  2050,   748,     0,     0,     0,   749,
       0,     0,     0,  1889,  1095,     0,   754,   750,     0,     0,
       0,     0,     0,   755,     0,   756,     0,     0,   751,     0,
       0,     0,  1890,     0,   752,   757,   758,     0,     0,     0,
       0,     0,  1107,   759,     0,     0,     0,  1891,     0,     0,
       0,   698,     0,     0,   272,     0,     0,  1108,     0,   753,
       0,  1109,     0,     0,  1892,     0,     0,  2051,     0,   203,
       0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,  2052,
    1894,     0,     0,     0,     0,     0,     0,  1102,  1103,  1104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,   754,     0,  1890,     0,     0,     0,     0,
     755,     0,   756,     0,     0,     0,     0,   204,   205,  1890,
    1891,  1896,   757,   758,     0,     0,   206,  1111,     0,     0,
     759,     0,     0,  1897,  1891,     0,     0,  1892,   698,     0,
    2051,   272,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,  1892,  2052,  1894,  1893,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1890,     0,  1894,     0,     0,
       0,     0,     0,     0,     0,  1898,     0,     0,     0,     0,
    1891,     0,  1942,  1943,  1944,  1945,  1946,  1947,     0,     0,
       0,     0,     0,     0,  1896,  2222,     0,  2579,     0,     0,
    2580,     0,     0,     0,     0,     0,  1897,     0,  1896,     0,
       0,     0,     0,  2581,  1899,     0,     0,     0,     0,     0,
    1897,     0,     0,     0,     0,     0,  1900,  1105,  1113,     0,
    1106,     0,     0,     0,     0,     0,     0,     0,  1901,  1902,
       0,  1948,     0,     0,     0,     0,  1903,     0,  1898,  1904,
       0,     0,     0,     0,  2583,     0,  1890,   272,     0,     0,
       0,     0,  1898,     0,     0,     0,  2584,     0,     0,     0,
       0,  1891,     0,  1942,  1943,  1944,  1945,  1946,  1947,     0,
       0,     0,     0,     0,     0,     0,     0,  1899,  1892,     0,
       0,  1893,     0,     0,  1114,     0,   207,     0,     0,  1900,
       0,  1899,     0,     0,  1894,     0,     0,     0,  2585,     0,
       0,  1901,  1902,  1900,     0,     0,     0,     0,     0,  1903,
       0,     0,  1904,     0,     0,  1901,  1902,     0,     0,     0,
     272,     0,  1948,  1903,     0,   208,  1904,     0,     0,     0,
       0,     0,     0,  1890,   272,  1896,     0,  2586,     0,  1107,
       0,     0,     0,     0,   209,     0,     0,  1897,  1891,  2587,
       0,     0,     0,     0,  1108,     0,     0,     0,  1109,     0,
     210,  2588,  2589,     0,     0,  1892,     0,     0,  1893,  2590,
       0,     0,  2591,     0,     0,     0,     0,     0,     0,     0,
     272,  1894,     0,   211,     0,     0,     0,     0,     0,  1898,
       0,     0,     0,     0,     0,   212,  1110,     0,     0,     0,
       0,     0,     0,     0,     0,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3051,  1896,   214,  1111,     0,  3015,     0,  1899,     0,
       0,     0,     0,   215,  1897,     0,     0,     0,     0,     0,
    1900,     0,     0,  1112,     0,     0,     0,     0,     0,   216,
       0,     0,  1901,  1902,     0,     0,     0,     0,     0,     0,
    1903,     0,     0,  1904,  1949,     0,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,  1898,  1950,     0,     0,
       0,     0,  3016,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3017,     0,     0,
       0,     0,     0,   218,     0,  1899,  3018,     0,     0,     0,
       0,     0,     0,     0,     0,  1113,     0,  1900,   219,     0,
       0,     0,     0,     0,     0,   220,     0,     0,   221,  1901,
    1902,  1951,     0,     0,     0,     0,     0,  1903,  1952,     0,
    1904,     0,  3019,     0,     0,  1949,     0,     0,   272,   222,
    3020,     0,   223,     0,   224,     0,     0,     0,  1950,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,  1953,     0,     0,
       0,  1114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1954,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1955,  1956,     0,     0,     0,     0,  1957,     0,
       0,     0,  1951,     0,     0,     0,     0,     0,  1958,  1952,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3021,     0,     0,     0,     0,     0,
    1959,     0,     0,  1960,  1961,     0,     0,     0,     0,  1962,
       0,     0,     0,     0,     0,     0,     0,     0,  1953,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1954,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1955,  1956,     0,     0,     0,     0,  1957,
       0,     0,     0,     0,     0,     0,  1963,     0,     0,  1958,
       0,     0,     0,     0,     0,     0,     0,  1964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1959,     0,     0,  1960,  1961,     0,     0,     0,     0,
    1962,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1963,     0,     0,
       0,     0,     0,     0,     0,     0,  3022,     0,  1964
};

static const short yycheck[] =
{
       4,   716,   194,   713,   328,   837,   188,   866,   499,    13,
      14,   848,   699,   989,   212,   996,  1003,   874,   834,     0,
      82,   424,  1502,  1563,  1413,  1871,   508,   509,   154,    66,
    1705,  1378,  1701,   515,   363,  1276,  1277,   519,  1999,   517,
     447,    45,    46,    24,   176,  2298,  2299,  2300,  1381,    30,
    1367,  1696,  1697,  1753,   523,  1700,    62,   739,  1309,     5,
    1624,  1884,  1885,   844,   845,  1812,   847,   545,   849,   850,
     548,   481,    76,    27,  2185,    79,   506,   787,    21,     5,
       5,   118,   264,    27,    27,    66,    91,    91,    27,    95,
      24,    25,    26,   225,    98,  1941,   388,    27,   102,     5,
       5,   105,   106,   506,  2412,  2301,    33,   111,   112,     5,
    2279,   237,   238,   929,  1031,   419,    19,    19,   422,   423,
       5,    24,    25,    26,    26,    62,    25,   943,    27,    24,
     962,    26,   436,   100,   541,   141,  1636,   118,     5,   145,
       5,     5,     5,    68,    27,    70,   150,    72,   340,   153,
     454,   510,     5,   457,   158,    24,  1801,    26,    62,   463,
      79,  1065,    21,   467,    87,    88,    25,   471,    27,     5,
      25,   475,    27,     6,     5,   479,   480,    25,   482,    27,
     448,   485,    27,   487,   488,   489,    24,    25,    26,    27,
       5,   495,   196,     5,   498,    24,    25,    26,    27,     5,
    1983,   505,   470,   395,    65,    25,   510,    27,    27,   698,
    2518,    76,     5,    27,   518,  1890,    33,    82,   933,     5,
       5,   227,    25,   273,    27,   529,    25,    26,    27,   533,
     234,     5,   149,   537,  2668,    23,   240,    26,    27,   543,
       5,   338,   546,    25,     5,    27,   514,   251,   855,   856,
     419,    48,    49,    50,    51,    52,   524,   525,     6,    18,
     528,   188,   189,    25,   532,    27,   534,     5,     5,    25,
     538,    27,   540,    64,   280,    25,   282,    27,   149,  2395,
       5,   287,  2890,    27,   390,   454,    27,     5,   457,   599,
     189,     5,   206,    24,    25,    26,    27,     6,   467,   546,
      27,   234,   471,     5,   388,     5,   475,    24,    25,    26,
      27,     5,     5,   482,     5,  1937,   134,  2278,   487,   162,
     489,  1990,     5,     0,     0,    84,   495,   364,   365,   498,
     336,   538,     5,   429,  1814,   332,   505,   390,     5,    21,
     174,   510,  1987,  2189,    31,    27,     5,   353,    24,   518,
    1043,   189,   356,     5,  1213,   359,    26,    27,    27,   538,
     529,   457,   538,   367,   533,    25,     5,  2012,   537,   189,
     617,   424,   189,    27,   543,    56,    57,   546,   343,   383,
     587,   385,  2051,   364,   365,     5,   189,   384,    18,    19,
     470,     5,    29,     5,  1381,  2564,    26,    27,   478,     5,
     189,  2046,  3010,    84,    85,    86,   273,    28,   587,   413,
     273,   587,   273,   150,   418,     5,   420,   421,     5,   373,
     424,   425,    21,   427,   625,   150,   430,   189,    27,   898,
       5,    24,    25,    26,    27,  2869,   270,   441,   140,   189,
       5,   162,     5,   352,   448,   233,     5,     9,    10,     5,
      12,    13,    14,    15,    16,    17,   460,  1172,   189,     5,
     394,    18,    19,    20,    21,    22,   470,     5,     5,   473,
       5,  1675,   189,     5,  1678,   409,     5,     5,     5,   483,
     616,   578,   343,   589,   398,  1985,     9,    10,     5,    12,
      13,    14,    15,    16,    17,   499,   500,  2280,  2281,     5,
     343,     5,   506,   247,    18,    19,    20,    21,    22,   241,
     514,     5,   516,   517,     5,     5,     5,   282,   568,   189,
     524,   525,     5,   527,   528,  1014,   530,   388,   532,   348,
     534,     5,     5,   837,   538,   439,   540,  1230,   542,   394,
     544,   545,   852,   547,   548,     5,   550,  1038,     5,   859,
    1041,  1042,  1043,     5,   883,  2671,   885,   390,  2519,   189,
    1464,   618,     5,  1467,   508,  1252,  1044,     5,   625,  1060,
    2393,   504,  2395,    10,   658,   244,  1817,    27,   461,  2224,
    2227,  2228,  2229,  2230,   429,  1974,  2208,  1017,   257,   425,
     244,  1198,  1302,  1303,   425,   386,   189,    27,  1515,   282,
     868,  1311,   961,   257,   348,   542,   874,   561,   525,  2149,
     425,   530,    27,   425,  1017,   429,   390,  2925,   886,   425,
     411,   348,   343,   891,  2793,  2794,   553,   388,   595,  2825,
     595,   338,   425,   638,   639,   640,   641,   642,   542,   425,
     425,   619,   390,   303,  1354,   550,  2291,   553,   652,   309,
     310,   311,   390,  2193,   525,   979,   960,   961,   962,   589,
     556,  2201,  2202,   394,  2510,   550,   383,  1158,   837,   329,
     676,  1140,   390,   429,   539,  1153,   390,   681,   409,   683,
    2791,   390,   546,  1152,  2992,   619,   585,   589,   980,   251,
     390,   617,   617,   546,   698,   513,   390,   390,   365,   390,
     625,   568,   625,   352,   495,   568,  1136,   568,   470,   713,
    2274,   500,   666,   372,  1205,   661,   619,   390,   722,   723,
     724,  2832,   666,   666,   619,  2472,   470,   666,   251,  2476,
     550,  1141,   514,  1136,   738,  3043,   553,  3045,   390,  1230,
     744,   745,  2442,   470,  1235,   749,  1428,  1998,  2095,     5,
     619,   390,   611,  1231,  1741,  2072,   611,    27,  2403,   189,
    2405,   626,  1578,   611,  2097,   554,  1265,  1249,    23,   486,
     390,   429,   453,   576,   189,   429,   390,   437,   390,    23,
     440,   619,   330,   787,   390,   452,   583,   648,   649,   650,
     619,   960,   961,   962,   244,  1273,  1274,   588,   659,   429,
     390,   394,   469,   390,   464,  1792,   475,   257,   370,   600,
     601,   248,   611,  3066,   338,   390,   409,   608,  1225,  2023,
    1652,   475,   491,   544,   484,   390,   624,   390,   390,   833,
     834,   390,   358,  2222,   390,   359,  2797,   491,    18,    19,
      20,    21,    22,     5,   390,   512,  2521,   370,  2671,   647,
     135,   136,   390,   390,   281,   390,   577,   576,   390,   519,
     541,   390,   390,   390,   868,   427,   992,   294,   425,   995,
     874,   578,   457,   390,  1142,  1143,  1144,   470,   354,   539,
     540,    27,   886,    27,   390,   552,   390,   891,   619,   358,
     550,    14,   896,  2598,  1162,   555,   390,   616,   429,   390,
     390,   390,   619,   584,   427,   281,  2881,   390,  2883,   429,
     914,   425,    30,   429,   581,   157,   390,   390,   294,   189,
    2565,  1390,  1404,   590,   521,   929,   457,  2168,    46,    47,
     390,  1199,  1642,   390,   594,   237,  2769,    55,   390,   943,
     456,  2787,    60,  2050,  2817,  2052,  2580,   390,   385,   475,
     387,  1013,   390,   383,   112,  2828,  1224,   323,    25,  2792,
      27,  2501,    26,    27,   294,   513,   626,   625,   383,  2614,
     167,  2804,   457,  1241,  1156,    21,   524,   247,   233,   429,
     323,    27,  1464,  1251,    25,  1467,    27,   105,   106,   233,
      21,   535,   294,   997,   556,   113,    27,  1001,  1002,  1003,
    1837,   428,    28,    29,   122,   123,   475,   125,   126,    25,
    1014,    27,   130,  1017,   424,  1019,  1020,    26,    27,  1023,
      25,    21,    27,   456,   457,   475,   619,    27,   429,   147,
     148,    26,    27,   556,  1038,  1039,  1514,  1041,  1042,  1043,
    1044,   491,  1046,   189,   346,  1049,   457,   165,   350,    25,
      27,    27,   428,   295,   578,   429,  1060,   533,  1062,   585,
     622,   359,  1066,    25,  1923,    27,  2047,  2714,   157,   367,
    1074,   547,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1561,    25,    26,  2770,   572,  2772,   428,   622,
    2805,  2806,  1106,  1107,  3079,    21,   361,  1111,  2941,  1113,
    2097,    27,   457,  2094,   480,   413,   585,   361,  1609,  1610,
     334,    25,   189,    27,  1128,   189,   428,   104,   441,   371,
    2415,   345,  1136,  2418,   619,   429,    19,   480,  1142,  1143,
    1144,    24,    25,    26,   620,  1623,   429,   460,   189,  1153,
     435,  1155,   457,  1157,  1158,  2800,   429,  1989,  1162,  1628,
     473,  2830,  2809,  2808,  2811,  2812,  2813,  2814,  1300,    21,
      25,   429,    27,   189,  1306,    27,  2810,   154,  2567,  2011,
     189,    26,  2816,   397,   189,  2819,  2820,  2821,  2822,   457,
    2297,  2298,  2299,  2300,   189,  1199,   340,    25,   412,    27,
      25,  1205,    27,  1507,   348,   349,   295,   529,   619,   429,
     390,   533,   189,   189,   191,   537,  1342,  1485,  1905,   429,
    1224,  1550,   429,    19,  1228,  1351,  1230,  1231,    24,   373,
      26,  1235,   376,   475,    26,  1239,  1240,  1241,   365,   429,
     437,  1509,  2918,  2919,   480,  1513,  2891,  1251,   366,   491,
     394,   448,  1743,    46,    47,    25,   429,    27,   624,    21,
    1742,  1265,  1972,  1732,  2086,    27,  2088,  2089,  1272,  1273,
    1274,   624,   163,   470,   392,   166,  1544,   643,   644,   625,
     477,   624,   371,   625,   589,   189,    26,  2394,   502,  2396,
     639,   640,  2108,   646,   647,  1299,    22,   663,  1302,  1303,
     643,   644,  1570,  1307,  2014,  1309,  2036,  1311,    25,    35,
      27,   288,  2042,  2947,   619,    26,  2950,  2951,  2952,  2953,
     663,   624,  2938,   237,  1793,   452,  1795,  1631,  2944,   122,
     123,  3000,   125,   126,   189,  1804,    26,   130,  1507,    26,
     429,  1347,   469,   646,   647,   463,   163,    26,  1652,   166,
    1354,   108,   109,   110,   147,   148,   500,  3033,   619,  3035,
    2217,   189,   163,  1367,   189,   166,    92,    93,    94,    95,
      96,    97,   165,   190,  1378,   456,   457,  1381,   269,   356,
     294,   272,   108,   109,   110,   512,   475,   364,   624,   190,
      34,   368,    36,    37,    38,   457,  1400,  1401,  1402,   286,
     287,  1883,   491,   294,   294,   648,   649,   643,   644,    26,
     554,  2270,    18,    19,    20,    21,    22,   561,    26,   189,
     544,   429,    26,   547,  3058,   552,   550,   663,   405,    35,
     365,  2911,   346,  1437,  1438,  1439,   350,  1441,  3083,   557,
      26,   489,   235,  2424,    25,  2432,    27,    26,   456,   457,
     498,   429,   269,    26,   581,   272,   346,    25,   619,    27,
     350,    58,  1631,   590,  1468,   390,  1734,  1471,   269,  2576,
    2577,   272,    25,  2580,    27,  1587,   429,   294,   456,   457,
      25,  1485,    27,  1652,   641,   642,    92,    93,    94,    95,
      96,    97,   360,   294,  3034,   543,   473,   638,   546,  1503,
     641,   642,   108,   109,   110,  1509,   619,  1511,  1512,  1513,
    1514,    26,   520,  1916,   428,   425,    24,   452,    26,   637,
      20,    21,   248,   429,  1137,   251,  1139,   645,  1796,  1797,
    1798,  1799,  3012,   429,   469,   512,     5,   428,   428,   390,
    1544,  1733,   520,   853,   854,  1549,   457,   857,   858,   648,
     649,  3031,  1820,   619,    24,  1559,    26,  2576,  2577,  1563,
     537,  1759,   612,   613,   614,   615,  1570,   437,   196,    30,
      26,   365,   200,    24,  1578,    26,   257,   512,   448,   425,
    1584,  1585,   390,  1587,   360,    46,    47,    34,    21,    36,
      37,    38,    92,    93,    94,    95,    96,    97,    26,    26,
     470,    26,    26,    26,   581,  1609,  1610,   477,    21,  1877,
     429,   428,  3092,   590,    75,    26,   423,   552,    26,  1623,
     619,    26,   390,     5,    30,   269,   390,   428,   272,   436,
     274,   390,  2101,  2492,   301,   390,   390,  1749,  1642,   390,
      46,    47,   248,   436,   370,   251,   581,   390,   623,     5,
     294,  2627,   390,  2490,   301,   590,   463,  1661,   452,   385,
     304,   122,   123,   389,   125,   126,   390,   390,   623,   130,
    1674,  1675,   479,   480,  1678,   469,   390,   390,   485,  1983,
     429,   488,   619,  2152,   457,  1989,   147,   148,   616,   619,
    1694,     8,  1696,  1697,   425,   478,  1700,  1701,   525,   429,
     429,   427,   346,  2810,   165,   458,   350,  2011,   429,  2816,
    2817,   429,  2819,  2820,  2821,  2822,   122,   123,   512,   125,
     126,  2828,   429,  1727,   130,   429,  1730,  2437,   429,   455,
    1734,    25,   457,    27,  2002,   429,  2004,  1741,   429,  1743,
     429,   147,   148,   429,   429,  1749,   471,   429,   474,   429,
     475,   429,    46,    47,   429,   429,   429,   429,   552,   165,
     429,   429,   487,   429,   370,   429,   429,   419,   265,  2260,
       5,  2262,   595,   617,   235,   617,   419,  1781,   658,   385,
    1784,  1893,  2497,   389,   428,   658,   325,   581,  1792,   429,
       8,   596,  1796,  1797,  1798,  1799,   590,  1801,  2297,  2298,
    2299,  2300,   458,  1807,  1808,   365,     5,  1811,  1812,    18,
      19,    20,    21,    22,  1983,     5,  1820,   382,   446,   447,
    1989,   427,   269,   343,   429,   272,  1830,   274,   122,   123,
     556,   125,   126,   429,   429,   429,   130,   429,     8,   159,
    2947,   589,  2011,  2950,  2951,  2952,  2953,   294,    14,   455,
     578,     5,   133,   147,   148,   175,   176,   304,   658,   575,
       5,   658,   419,   183,    26,   429,  2092,   429,   474,    26,
      65,   165,    91,  1877,  2733,    61,   323,   457,    26,   457,
    1884,  1885,  2741,     5,   619,   595,   589,  1999,   429,  1893,
    2158,   429,   452,  2161,   355,   189,   622,   217,   470,   346,
    1904,   429,   365,   350,    21,  2592,   226,    21,   429,   469,
     625,   429,  1916,   541,   661,   429,   365,   198,   429,   200,
    1924,   556,   624,   551,  2331,  2332,  2333,   625,  2335,  2336,
    2337,  2338,  2339,  2340,   215,   255,     5,  2344,    18,  2051,
      30,   235,   223,   404,    19,   349,   227,   133,   625,  2217,
     556,  3058,   512,     5,    26,    26,    46,    47,   152,  3066,
    2429,   217,    25,   589,   622,   578,   365,     5,  1972,   481,
     619,   252,   481,   150,   320,   436,  2280,  2281,    26,   546,
     300,   428,   398,  1987,    26,   546,  1990,   546,   429,   452,
    2459,   429,   552,  1997,  1998,  1999,  2706,  2829,  2002,  2036,
    2004,   663,  2480,   452,   390,  2042,   469,   429,  2012,  2487,
    2014,   429,   198,   576,   200,   429,   622,   619,   457,  2023,
     469,   581,   342,   546,  2216,   390,   390,   390,   390,   215,
     590,   390,   122,   123,    26,   125,   126,   223,   390,   390,
     130,   227,  2046,   390,   429,  2049,   390,  2051,   625,   512,
    2909,     5,     5,   452,     5,  2036,     5,   147,   148,  2063,
     616,  2042,   579,   512,   619,   482,   252,   625,  2072,   390,
     469,  2297,  2298,  2299,  2300,   165,   429,  2576,  2577,    61,
     624,  2580,     5,    26,   429,   553,    26,   429,   716,   552,
     535,  2095,    34,  2097,    36,    37,    38,    65,   324,     5,
       5,  2105,   390,   552,  2108,   429,   429,   359,   596,  2113,
      14,  2280,  2281,   512,  2226,   625,   419,   419,   581,     5,
    2232,  2233,  2234,  2235,  2236,  2237,   659,   590,     5,   550,
      26,   546,   581,   100,   762,   619,   429,   429,   625,   624,
       5,   590,   436,   638,  2148,  2149,   425,   425,   459,   459,
       8,   133,   134,   552,  2158,   429,   429,  2161,   133,   429,
     429,   429,  2166,   429,   429,     5,  2278,  2666,   390,    26,
    2669,  2881,    26,  2883,   390,  2179,    25,  2181,    25,  2183,
     589,    25,   581,   390,    25,   390,  2190,     5,  3047,  2193,
     619,   590,     5,  2197,     8,   324,    25,  2201,  2202,   619,
     619,  2916,   343,   343,   457,   343,   188,   359,   429,   619,
     424,   457,   194,  2217,   429,  2483,   429,   429,   429,   429,
    2224,   429,  2226,   198,     5,   200,   429,    26,  2232,  2233,
    2234,  2235,  2236,  2237,  3015,  3016,  3017,  3018,  3019,  3020,
     215,  2732,     5,   650,  2512,     5,    25,    14,   223,    14,
      26,   429,   227,   619,   595,   595,  2260,     5,  2262,   616,
       5,   619,   128,   238,     5,   355,  2735,    18,    19,    20,
      21,   137,     7,  2541,  2278,   390,   429,   252,     5,    26,
     146,   619,   264,    26,   266,   151,  2398,  2291,   625,    26,
     619,     8,  2474,  2297,  2298,  2299,  2300,  2301,  2302,    20,
      21,   390,  2626,   625,   390,   933,    26,   589,  2312,  2313,
    2314,  2810,   625,   390,   404,    21,  2320,  2816,  2817,     5,
    2819,  2820,  2821,  2822,  2436,   390,   390,   269,   194,  2828,
     272,   390,   274,   390,   566,   273,   202,   390,     5,     5,
     546,    92,    93,    94,    95,    96,    97,     5,   239,     5,
    2576,  2577,   294,   390,  2580,   390,   619,   439,   340,   619,
     390,   625,   304,   429,   470,     6,   625,   571,     5,  3079,
     553,    92,    93,    94,    95,    96,    97,  2381,   625,  2383,
     623,   323,    18,    19,    20,    21,   209,   623,   618,  2393,
      25,  2395,   258,    25,  2398,    25,   445,    25,    25,  2403,
    2404,  2405,    26,    26,   346,    26,    26,  2519,   350,    26,
     470,   429,   429,   395,    26,  2527,   295,   283,  2530,  2531,
    2532,  2533,    26,     5,   290,   390,   292,   390,  2432,   267,
     525,  2900,  2436,  2437,   589,   467,   302,     5,  3153,   429,
    2666,   550,   390,  2669,   239,    25,  2450,   425,  2947,   390,
     432,  2950,  2951,  2952,  2953,     5,    92,    93,    94,    95,
      96,    97,   328,   390,    21,   439,   139,   343,  2472,  2737,
     336,  2475,  2476,   429,   553,     5,  2480,   429,     5,  2483,
      14,   209,   429,  2487,   466,   429,   428,  2986,   619,     5,
     472,   457,   474,   429,   429,   429,   478,  2501,   390,   481,
      26,  1760,   484,   440,    26,  1764,   390,   373,  2512,   390,
    1769,     5,   494,   618,  1773,  2519,  1775,  1776,  1777,   390,
     330,   367,   429,  2527,   372,  2829,  2530,  2531,  2532,  2533,
    2534,   513,   118,   399,   390,   568,    26,  2541,   390,   521,
     522,   523,   429,   343,  1172,   527,     6,     7,     8,     9,
      10,    11,    12,   535,  2558,   390,   390,   390,   970,  3058,
     240,  2565,  2674,   457,   625,    63,   390,  3066,   390,   551,
    2574,   437,  2576,  2577,   390,   390,  2580,   575,   390,   429,
     619,   390,   448,    14,  2810,   546,     7,  2591,   238,   238,
    2816,  2817,    26,  2819,  2820,  2821,  2822,  1225,   625,   390,
      26,   446,  2828,   391,   429,   619,   390,   390,   390,   625,
    2614,     5,  2616,   625,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   429,   425,     5,
      25,   390,   240,   390,   220,  2861,   390,   390,   390,    35,
     390,     5,   228,  2196,   390,  3102,   390,  2105,   234,  2148,
     236,  1867,  1280,  1242,  1571,    37,    39,   364,  1808,  1814,
    2829,   247,  2666,  2775,  2179,  2669,   141,  2671,   287,   145,
    2674,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   209,   548,   549,   550,  2797,   281,   397,   288,   275,
    1347,  1346,   353,    35,   211,   561,    92,    93,    94,    95,
      96,    97,  2706,   371,  1767,   291,  2710,   316,  2712,  2445,
     296,   383,   108,   109,   110,   385,   315,  3092,  1544,  1784,
     527,  2947,   308,  1418,  2950,  2951,  2952,  2953,  2732,   315,
    2922,  1672,  1679,  2737,   716,  1513,   967,  1798,  1272,  2251,
    2544,  1601,  1920,  1275,  3117,  1802,  1618,  2749,    24,   118,
      92,    93,    94,    95,    96,    97,  1158,    30,  3026,  2648,
    2986,    30,  1576,   266,   654,   484,   108,   109,   110,  1582,
     683,  2775,  2645,  1280,  2886,  1918,  1585,  2846,   934,  1149,
    1634,  3031,  2233,  2371,  1139,  2856,   886,  1224,  2369,  2353,
    1070,  2045,  1361,  2797,  1023,  1196,  2800,  1384,   664,  1792,
     298,  1983,   784,  3119,  2808,  3083,  2810,  2015,  2968,  2046,
    2402,  1700,  2816,  2817,  2706,  2819,  2820,  2821,  2822,  2438,
    2381,  2825,  2049,  2827,  2828,  2383,  2830,  2669,  2986,  2680,
    2063,  2943,  3058,  1299,  2838,  2314,   963,  2892,  2292,  2893,
    3066,  2575,  2436,  3081,  2232,   827,  1294,   259,  2935,   959,
    2574,  2808,   248,  2827,  2816,   251,  1730,  1154,   356,    -1,
     362,   843,   844,   845,  1267,   847,    -1,   849,   850,    -1,
     368,  3139,    -1,   855,   856,    -1,    -1,  2881,  2990,  2883,
     378,    -1,  2886,    -1,   470,    -1,   298,  2891,    -1,  2893,
      -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,   317,   248,    -1,   406,   251,
      -1,   409,    -1,   499,    -1,    -1,   898,    -1,   504,    -1,
      -1,  1333,  1334,    -1,   422,    -1,    -1,   909,  1340,    -1,
      -1,  2935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2943,
      -1,    -1,    -1,  2947,   356,    -1,  2950,  2951,  2952,  2953,
    2954,   933,   934,    -1,    -1,    -1,   368,    -1,    -1,  1587,
     942,    -1,    -1,    -1,  2968,    -1,   378,    -1,    -1,  3081,
      -1,    -1,    -1,   471,   370,    -1,   958,   959,    -1,    -1,
      -1,    -1,  2986,    -1,   396,    -1,  2990,    -1,    -1,   385,
      -1,    -1,    -1,   389,   406,    -1,  3000,    -1,    -1,    -1,
      -1,    -1,    -1,   501,    -1,    -1,    -1,  3119,    -1,    -1,
     422,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3026,  3027,    -1,    -1,    -1,    -1,   370,    -1,
    3034,   427,    -1,    -1,   532,    -1,    -1,   535,    -1,   537,
      -1,    -1,    -1,   385,    -1,    -1,    -1,   389,    -1,    -1,
     462,    -1,    -1,    -1,  3058,    -1,    -1,    -1,    -1,   455,
      -1,    -1,  3066,    -1,    -1,    -1,  1694,   565,    -1,    -1,
     722,   723,   724,  1701,   486,  3079,   574,  3081,   474,  3083,
      -1,    -1,    -1,    -1,    -1,   427,   738,    -1,    -1,   501,
      -1,    -1,   744,   745,    -1,    -1,   508,   749,    -1,   511,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,  3119,    -1,    -1,    -1,    -1,
     532,  1749,    -1,   535,    -1,   537,    -1,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,  3139,    -1,    -1,    -1,    -1,
      -1,    -1,  1554,    -1,   556,    -1,    -1,  1129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1137,    -1,  1139,  1140,  1141,
     556,    -1,   574,    -1,    -1,    -1,  1148,  1149,    -1,    -1,
    1152,    -1,    -1,    -1,  1156,    -1,    -1,  1159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1597,    -1,    -1,    -1,    -1,
    1172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   556,    -1,  1198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    17,
      18,    19,    20,    21,    22,  1237,  1884,  1885,    -1,    -1,
      -1,    35,    -1,    -1,    -1,  1893,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,
     622,    -1,    -1,    -1,  1266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1279,  1280,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    18,    19,
     108,   109,   110,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,  1335,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1999,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,  1039,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,    -1,    -1,  1049,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1390,    -1,
    1062,    -1,    -1,    -1,  1066,    -1,    -1,    -1,    -1,    -1,
      -1,  2049,  1074,  2051,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,    -1,    -1,    -1,    -1,    -1,  1861,
    1862,    -1,    -1,    -1,  1106,  1107,    -1,    -1,    -1,  1111,
    1872,  1113,    -1,    -1,  2092,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,   251,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
      -1,    -1,    -1,  1925,  1926,  1927,  1928,    -1,    -1,    -1,
      -1,  1933,  1934,  1935,  1936,    -1,    -1,    -1,  1940,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1542,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,  1551,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1561,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,  2226,    -1,
    1582,    -1,   370,    -1,  2232,  2233,  2234,  2235,  2236,  2237,
      -1,   385,  2024,  2025,    -1,   389,    -1,   385,    -1,  2031,
    2032,   389,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,  1628,  1629,  1630,    -1,
    2278,    -1,  1634,   427,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,  2297,
    2298,  2299,  2300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   455,    -1,    -1,  1666,    -1,    -1,   455,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,  2331,  2332,  2333,   474,  2335,  2336,  2337,
    2338,  2339,  2340,    -1,   394,    -1,  2344,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,   409,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,   429,
    1732,  1733,    -1,  2381,    -1,  2383,    -1,  2169,  2170,    -1,
      -1,    -1,   442,    -1,    -1,  2393,  2178,  2395,    -1,    -1,
    2398,    -1,    -1,    -1,  2186,    -1,    -1,    -1,   248,    -1,
      -1,   251,   556,    -1,    -1,  1437,  1438,  1439,   556,  1441,
      -1,    -1,    -1,  2205,  2206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   482,   483,    -1,    -1,    -1,    -1,  2436,    -1,
      -1,  1793,    -1,  1795,    -1,   495,  1468,    -1,    -1,    -1,
      -1,    -1,  1804,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,   622,  2261,
      -1,  2263,    -1,    -1,   622,    -1,    -1,   537,    -1,    -1,
    1842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1871,
      -1,  2519,    -1,    -1,    -1,    -1,   576,  1549,    -1,  2527,
     370,    -1,  2530,  2531,  2532,  2533,    -1,    -1,   588,  2321,
    2322,  1563,    -1,  2325,  2326,   385,    -1,    -1,    -1,   389,
     600,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,
      -1,   611,    -1,    -1,    -1,  1917,  1918,    -1,    -1,   619,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2359,  2576,  2577,
      -1,    -1,  2580,    -1,    -1,    -1,    -1,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     370,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,   389,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,  2666,    -1,
    2022,  2669,    -1,  2671,    -1,    -1,  2674,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,
      -1,  2473,    -1,    -1,    -1,  2477,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   455,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2508,    -1,    -1,    -1,
      -1,   259,    -1,    -1,   474,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,  2101,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,  1781,
    2542,    -1,  1784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    -1,    -1,    -1,    -1,  2775,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,   317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2797,
    2152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2810,    -1,    -1,    -1,   556,    -1,  2816,  2817,
      -1,  2819,  2820,  2821,  2822,    -1,    -1,    -1,   356,    -1,
    2828,    -1,  2830,  2185,    -1,    -1,    -1,    -1,    -1,    -1,
     368,    -1,  2194,    -1,  2196,    -1,  2198,    23,    -1,    -1,
     378,    -1,   248,    -1,    -1,   251,    -1,    -1,    34,  2211,
      36,    37,    38,  2861,  2216,    -1,    -1,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    62,    -1,  2886,    -1,
      -1,    -1,    -1,   248,   422,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    91,    -1,    -1,  2916,    -1,
    2272,  2273,    -1,    18,    19,    -1,    21,    -1,    -1,    24,
      25,    26,    27,    -1,   462,    21,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,  2943,    -1,    -1,    -1,  2947,
      -1,    -1,  2950,  2951,  2952,  2953,    -1,   133,   486,    -1,
      -1,    -1,    -1,  2315,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,   501,   370,    -1,    -1,    -1,    64,    -1,
     508,    -1,    -1,   511,  2766,    -1,    -1,   163,  2986,   385,
     166,    -1,  2990,   389,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3000,  2355,   532,    -1,    -1,   535,    -1,   537,
      -1,    -1,    -1,    -1,   190,   370,  2368,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,    -1,    -1,    -1,   556,    -1,
     385,   427,    -1,   209,   389,   390,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,   574,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,   233,    -1,   455,
    3058,   237,   238,   239,   240,    -1,    -1,    -1,  3066,    -1,
      -1,    -1,   427,    -1,    -1,    -1,   252,  2429,   474,    -1,
      -1,    -1,    -1,  3081,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   189,    -1,   272,    -1,   274,    -1,
     455,    -1,    -1,   189,    -1,   281,    -1,  2459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   474,
      -1,  3119,  2474,    -1,    -1,    -1,  2148,  2149,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2920,    -1,
      -1,    -1,    -1,    -1,    -1,  2497,    -1,   323,   324,    -1,
      -1,    -1,    -1,    -1,    -1,  3153,    -1,    -1,    -1,    -1,
     556,    -1,   338,    -1,    -1,    -1,    -1,    -1,  2190,    -1,
     346,  2193,    -1,    -1,   350,    -1,    -1,    -1,    -1,  2201,
    2202,    -1,    -1,   359,   360,   361,    -1,    -1,    -1,    -1,
      -1,  2973,  2974,    -1,  2976,    -1,  2978,  2979,   293,    -1,
      -1,   556,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   439,  3046,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,  3070,    -1,
    3072,    -1,    -1,  2645,    -1,   108,   109,   110,    -1,   394,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,   394,    -1,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   409,    -1,  3107,    -1,    -1,    -1,    -1,
      -1,   426,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,
     426,    -1,    -1,   429,    -1,    -1,   441,   442,    -1,    -1,
      -1,  3133,  3134,    -1,    -1,  3137,   442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2735,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,
     495,    -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2450,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,  2791,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,   624,    -1,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   638,   639,   640,   641,   642,   643,   644,    -1,
     646,   647,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2501,
    2832,   576,    -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,
     576,    -1,    -1,   588,  2846,    -1,    -1,    -1,    -1,  2851,
      -1,  2853,   588,    -1,    -1,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,   608,   600,   601,   611,    -1,    -1,    -1,
      -1,    -1,   608,    -1,   619,   611,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,    -1,    -1,
    2892,    -1,    -1,    -1,    -1,    18,    19,    -1,  2900,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,   370,    -1,    -1,
      -1,    -1,    -1,    -1,  2916,    -1,    -1,    -1,    -1,    -1,
    2922,    -1,   385,    -1,    -1,    -1,   389,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    18,    19,    -1,    45,    46,
      47,    24,    25,    26,    27,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    66,
      67,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    64,   455,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,    -1,
      -1,   474,    -1,  3015,  3016,  3017,  3018,  3019,  3020,    -1,
     117,    -1,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    -1,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,   141,    -1,   143,   144,   145,    -1,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   156,
      -1,   158,    -1,   160,   161,    -1,   189,   164,   165,    -1,
      -1,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
     177,   178,    -1,   180,    -1,    -1,    -1,   184,    -1,   186,
     187,    -1,    -1,   556,    -1,   192,    -1,    -1,    -1,   196,
      -1,    -1,   199,    -1,   201,    -1,   203,    -1,   205,    -1,
     207,   208,    -1,   210,   211,   212,   189,    -1,    -1,   216,
      -1,   218,   219,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,   245,   246,
      -1,  3153,   249,   250,    -1,    -1,   253,   254,    -1,   622,
      -1,    -1,    -1,    -1,    -1,   262,   263,   264,    -1,   266,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,
     277,   278,    -1,   280,    -1,    -1,    -1,   284,   285,    -1,
      -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,   306,
     307,    -1,    -1,    -1,    -1,    -1,   313,   314,    -1,    -1,
      -1,    -1,   319,    -1,    -1,   322,    -1,    -1,    -1,   326,
     327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     337,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   355,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
      35,   394,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,    -1,
      -1,    -1,   399,   426,   401,   402,   429,    -1,    -1,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,   442,
      -1,   394,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,   470,    -1,    -1,
      -1,    -1,   449,   426,    -1,    -1,   429,    -1,    -1,    -1,
     483,    -1,  3034,   460,    -1,    -1,    -1,   464,    -1,   442,
      -1,   468,   495,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,   493,    -1,    -1,    -1,
     497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     483,    -1,   509,    -1,   537,    -1,    -1,    -1,   515,   516,
     517,   518,   495,    -1,    -1,   522,    -1,    -1,    -1,   526,
      -1,    -1,    -1,    -1,    -1,    -1,   533,   534,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,
     547,    -1,    -1,   576,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   558,    -1,   560,   537,   588,   563,    -1,    -1,    -1,
      -1,    -1,   569,    -1,    -1,    -1,    -1,   600,   601,    -1,
      -1,    -1,   176,   248,    -1,   608,   251,    -1,   611,   183,
      -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,   595,    -1,
      -1,   598,    -1,   576,    -1,    -1,   603,    -1,    -1,   606,
     607,    -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   621,    -1,    -1,   600,   601,    -1,
      -1,   628,   226,    -1,    -1,   608,    -1,    -1,   611,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   651,   652,   653,   654,   655,   656,
     657,   255,   256,   660,    -1,   662,    -1,   664,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   370,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,   390,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   342,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      35,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   556,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,   251,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,   108,   109,   110,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   370,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,    -1,    -1,    -1,    -1,   385,    -1,    -1,
      -1,   389,   390,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,   251,    35,    92,    93,    94,    95,    96,    97,   427,
      -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,   390,   189,   455,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,    -1,   474,   251,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,   108,   109,   110,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,   556,   389,
     390,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   248,
      -1,    -1,   251,    -1,    92,    93,    94,    95,    96,    97,
      35,    -1,    -1,    -1,    -1,    -1,   370,   427,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,   389,   390,    -1,    -1,    -1,
      -1,   556,    -1,    -1,   622,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    92,    93,    94,
      95,    96,    97,   427,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   394,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,
      -1,   455,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,   426,    -1,    -1,   429,    -1,    -1,    -1,
     474,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,
     389,   390,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,   482,
     483,    -1,    -1,    -1,    -1,    -1,    -1,   370,   427,    -1,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,    -1,    -1,   389,   390,    -1,    -1,
      -1,    -1,   556,    -1,    -1,    -1,   455,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   537,   474,   251,    -1,    -1,    -1,
      -1,     6,     7,     8,   427,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,   455,   576,    -1,    -1,    -1,    -1,   622,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,
      -1,   474,   370,    -1,    -1,    -1,    -1,   600,   601,    -1,
      -1,    -1,    -1,    -1,    -1,   608,    -1,   385,   611,    -1,
      -1,   389,    -1,    -1,    -1,    -1,   619,   556,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,   556,   389,    -1,    -1,   455,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,   440,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   622,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   556,    -1,
      -1,    -1,    -1,   248,    -1,    -1,   251,     8,    35,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   556,    -1,    -1,   622,    92,    93,    94,    95,    96,
      97,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   370,    -1,   622,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,    -1,   108,   109,   110,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    99,    -1,    -1,   440,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,   189,    -1,   191,    -1,   248,    -1,    -1,   251,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,
      -1,   556,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,   385,    -1,     9,    -1,   389,    -1,    -1,    -1,   108,
     109,   110,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,   385,    -1,
      -1,    -1,   389,   427,    -1,    -1,   108,   109,   110,   370,
      -1,    -1,    -1,    59,    -1,    -1,    -1,   622,    64,    -1,
      -1,   288,    -1,    -1,   385,    71,   293,    -1,   389,    -1,
      -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,
     474,    -1,    -1,    99,   321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,    -1,    -1,   427,   389,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,   356,
      -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,
      -1,   368,    -1,    -1,    -1,   427,    -1,    -1,    -1,   248,
      -1,    -1,   251,   474,    -1,    -1,    -1,    -1,   440,   386,
      -1,    -1,    -1,    -1,   391,    -1,    -1,   394,    -1,    -1,
      -1,    -1,   556,   455,    -1,    -1,    -1,    -1,   405,    -1,
      -1,    -1,    -1,   189,   411,   191,   248,    -1,    -1,   251,
      -1,    -1,   474,    -1,   421,    -1,    -1,    -1,    -1,   426,
      -1,    -1,   429,    -1,    -1,   432,    -1,    -1,    -1,   556,
      -1,    -1,    -1,    -1,   441,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,   556,    -1,    -1,   622,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,   482,   483,    -1,    -1,    -1,
     487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,    -1,
      -1,   370,    -1,    -1,   556,   622,    -1,    -1,    -1,   506,
      -1,    -1,   288,    -1,    59,   512,   385,   293,    -1,    64,
     389,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,
     537,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,
      -1,     9,    -1,   385,    99,    -1,    -1,   389,   427,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
     622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     356,    -1,    -1,    -1,   581,    -1,   455,    -1,    -1,    -1,
      -1,   588,   368,   590,    -1,   427,    -1,    -1,    -1,    -1,
      -1,    59,    -1,   600,   601,   474,    64,    -1,    -1,    -1,
     386,   608,    -1,    71,    -1,   391,    -1,    -1,   394,    -1,
      -1,    -1,   619,   455,    -1,    -1,    -1,    -1,    -1,   405,
      -1,    -1,    -1,    -1,    -1,   411,    -1,    -1,    -1,    -1,
      -1,    99,   474,    -1,   189,   421,   191,    -1,    -1,    -1,
     426,    -1,    -1,   429,    -1,    -1,   432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   441,   442,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    27,    -1,   556,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,
      -1,   487,    20,    21,    22,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    64,    -1,   556,    -1,    -1,    35,    -1,    -1,
     506,   189,   508,   191,    -1,    -1,   512,    -1,    -1,    -1,
      -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,   293,    18,
      19,    -1,    21,   622,    -1,    24,    25,    26,    27,    -1,
      -1,   537,    -1,    18,    19,    -1,    21,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,   321,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
     622,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,   581,    -1,    -1,    -1,    64,
      -1,   356,   588,    -1,   590,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,   368,   600,   601,    -1,    -1,    -1,    -1,
     288,    -1,   608,    -1,    -1,   293,    -1,    -1,    -1,    -1,
      -1,   386,    -1,   619,    -1,    -1,   391,   189,    -1,   394,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
     405,    -1,    -1,   321,    -1,    -1,   411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,   426,    -1,    -1,   429,    -1,    -1,   432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,   442,   356,    -1,
      18,    19,    -1,    21,    -1,    -1,    24,    25,    26,    27,
     368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,
      -1,    -1,    -1,   391,   189,    -1,   394,   482,   483,    -1,
     248,    -1,   487,   251,    -1,    -1,    64,   405,    -1,    -1,
     495,   293,    -1,   411,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   506,    -1,   421,    -1,    -1,    -1,   512,   426,    -1,
      -1,   429,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,   441,   442,    -1,    -1,    18,    19,    -1,
      21,    -1,   537,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,   293,   483,    -1,    -1,    -1,   487,
      -1,    -1,    -1,    64,    35,    -1,   581,   495,    -1,    -1,
      -1,    -1,    -1,   588,    -1,   590,    -1,    -1,   506,    -1,
      -1,    -1,   394,    -1,   512,   600,   601,    -1,    -1,    -1,
      -1,    -1,   370,   608,    -1,    -1,    -1,   409,    -1,    -1,
      -1,   189,    -1,    -1,   619,    -1,    -1,   385,    -1,   537,
      -1,   389,    -1,    -1,   426,    -1,    -1,   429,    -1,    32,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,   441,
     442,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,   581,    -1,   394,    -1,    -1,    -1,    -1,
     588,    -1,   590,    -1,    -1,    -1,    -1,    80,    81,   394,
     409,   483,   600,   601,    -1,    -1,    89,   455,    -1,    -1,
     608,    -1,    -1,   495,   409,    -1,    -1,   426,   189,    -1,
     429,   619,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,   426,   441,   442,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   394,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,
     409,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,   483,   470,    -1,   426,    -1,    -1,
     429,    -1,    -1,    -1,    -1,    -1,   495,    -1,   483,    -1,
      -1,    -1,    -1,   442,   576,    -1,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,   588,   248,   556,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,   601,
      -1,    98,    -1,    -1,    -1,    -1,   608,    -1,   537,   611,
      -1,    -1,    -1,    -1,   483,    -1,   394,   619,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,   409,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   576,   426,    -1,
      -1,   429,    -1,    -1,   622,    -1,   259,    -1,    -1,   588,
      -1,   576,    -1,    -1,   442,    -1,    -1,    -1,   537,    -1,
      -1,   600,   601,   588,    -1,    -1,    -1,    -1,    -1,   608,
      -1,    -1,   611,    -1,    -1,   600,   601,    -1,    -1,    -1,
     619,    -1,    98,   608,    -1,   298,   611,    -1,    -1,    -1,
      -1,    -1,    -1,   394,   619,   483,    -1,   576,    -1,   370,
      -1,    -1,    -1,    -1,   317,    -1,    -1,   495,   409,   588,
      -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,   389,    -1,
     333,   600,   601,    -1,    -1,   426,    -1,    -1,   429,   608,
      -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     619,   442,    -1,   356,    -1,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    -1,    -1,    -1,   368,   427,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   483,   396,   455,    -1,   202,    -1,   576,    -1,
      -1,    -1,    -1,   406,   495,    -1,    -1,    -1,    -1,    -1,
     588,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   422,
      -1,    -1,   600,   601,    -1,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,   611,   331,    -1,    -1,    -1,    -1,    -1,
      -1,   619,    -1,    -1,    -1,    -1,   537,   344,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,    -1,    -1,
      -1,    -1,    -1,   486,    -1,   576,   292,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,   588,   501,    -1,
      -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,   511,   600,
     601,   408,    -1,    -1,    -1,    -1,    -1,   608,   415,    -1,
     611,    -1,   328,    -1,    -1,   331,    -1,    -1,   619,   532,
     336,    -1,   535,    -1,   537,    -1,    -1,    -1,   344,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   556,    -1,    -1,    -1,   454,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   489,   490,    -1,    -1,    -1,    -1,   495,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,   505,   415,
      -1,    -1,    -1,   616,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,
     527,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,   536,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   489,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,   505,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   527,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   602,    -1,   604
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
     557,   637,   645,   725,   731,   892,   969,  1030,  1031,  1033,
    1037,  1038,  1044,  1056,  1060,  1209,  1219,  1468,   936,  1470,
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
     785,   786,   936,   429,   112,   936,   752,   893,  1061,   936,
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
    1488,  1489,  1490,  1491,  1492,   894,  1062,  1040,   619,    26,
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
     836,   888,   918,   922,   943,   944,   947,   948,   949,   950,
     963,   971,   992,   993,   995,   999,  1016,  1017,  1021,  1022,
    1023,  1024,  1032,  1047,  1067,  1078,  1079,  1080,  1084,  1087,
    1123,  1126,  1128,  1134,  1135,  1138,  1141,  1144,  1146,  1148,
    1150,  1157,  1162,  1166,  1167,  1168,  1180,  1181,  1184,  1190,
    1191,  1192,  1217,  1232,  1233,  1234,  1235,  1236,  1241,  1247,
    1248,  1266,  1269,  1299,  1301,  1390,  1391,  1422,  1423,  1430,
    1441,  1468,  1472,  1477,  1479,  1481,  1485,  1486,  1493,   725,
    1035,  1468,   624,   647,  1063,  1064,  1107,    21,   390,   424,
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
    1081,  1082,  1090,   931,   931,  1081,   932,   937,   936,  1082,
     931,  1431,   931,   933,  1090,  1121,  1122,   929,   937,   933,
     373,   561,   666,   928,   936,   994,   936,   733,   934,   937,
      25,  1300,  1463,   862,   862,   937,  1147,   889,   128,   137,
     146,   151,   194,   202,   258,   283,   290,   292,   302,   328,
     336,   373,   399,   437,   448,   548,   549,   550,   561,   664,
    1008,  1142,  1143,  1090,   843,   844,  1156,   839,   862,   928,
    1478,  1478,   930,   937,   862,    25,  1090,  1145,  1218,  1090,
    1195,    25,  1090,  1425,   844,  1186,  1187,  1188,  1197,  1198,
     844,  1473,   104,   154,   191,   288,   364,   405,   473,   537,
     689,   868,   936,  1090,  1227,   712,   844,   929,  1470,  1068,
     844,   929,   844,  1090,  1018,   929,   844,  1442,   844,  1204,
     936,   945,   946,   933,   945,  1478,   933,   945,  1478,   951,
     945,    25,    26,   383,   486,   942,   997,  1090,  1109,  1111,
      65,   273,   343,   388,   568,   648,   649,   650,   659,   679,
     953,   955,   957,   959,   961,  1085,  1086,  1089,   334,   345,
     397,   412,   502,  1302,   639,   640,   896,   897,   898,   936,
    1065,   646,  1064,   390,   301,   390,   390,   390,   390,   623,
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
     589,   578,   713,   720,   711,    25,  1083,  1090,  1182,     8,
    1185,    14,   936,  1095,  1103,  1104,  1106,  1114,  1115,  1158,
     162,   343,   544,   577,    33,   189,   553,  1443,  1444,  1445,
    1446,   575,     5,   658,   658,   842,  1109,  1116,   996,   419,
       5,   150,   976,   429,  1090,   842,   429,    26,    26,    65,
    1088,    25,  1090,  1429,  1429,   937,  1282,  1147,   930,   118,
     220,   228,   234,   236,   247,   275,   291,   296,   308,   315,
     470,   477,   499,   504,  1270,  1271,  1279,  1289,  1290,  1296,
    1297,  1303,  1304,  1313,  1332,  1336,  1401,  1402,  1432,  1433,
    1436,  1437,  1447,   899,   900,    91,   895,   906,   907,   898,
    1066,  1488,  1041,   457,   806,   773,   457,     5,   390,   780,
     752,  1058,   752,   157,   295,   371,   429,   475,   491,  1319,
    1331,   429,   936,  1265,    26,   244,   257,   429,   475,   491,
     936,  1246,  1259,  1317,  1318,  1323,  1325,  1327,   429,   936,
    1256,   429,  1246,  1252,     5,    25,   939,  1093,  1465,  1463,
     576,   616,  1140,    21,   936,  1120,  1466,   936,  1484,  1244,
     595,   619,   589,   429,   429,   826,   887,   928,   837,   928,
     928,   887,  1478,   470,  1405,   837,    25,    26,    19,    24,
      25,    26,   883,   884,   885,   886,   837,   429,   625,   928,
      21,   837,   390,  1405,   837,    21,  1199,   871,   869,   875,
     837,   873,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   429,   837,   837,   429,   864,   936,
    1090,   625,   429,  1463,    25,   941,  1163,  1163,  1425,  1081,
     844,   844,   844,   925,   926,   429,  1090,  1122,   787,   973,
     974,   625,  1425,  1478,  1476,   936,   675,    21,   666,   936,
     994,  1090,   734,   624,   844,   349,  1133,   556,  1132,     5,
      68,    70,    72,   617,   625,   818,  1109,   890,    18,    19,
      25,   303,   309,   310,   311,   329,   437,   440,   464,   484,
     519,   539,   540,   550,   555,   594,   626,  1015,  1010,  1143,
     924,   844,   343,   595,     5,   928,    26,    26,   678,   152,
    1193,   217,  1198,  1204,  1474,   936,    25,   887,  1478,   589,
     928,   622,  1090,   693,   936,   936,   844,   338,   716,   720,
     578,   714,   722,    23,   233,  1070,  1074,   481,   862,   481,
    1183,   844,   456,  1100,   619,     5,  1019,   546,  1159,  1090,
    1464,  1467,  1090,  1112,  1113,   188,  1444,   964,   946,  1478,
    1478,   956,   957,   976,   976,    34,    36,    37,    38,   269,
     272,   274,   294,   304,   346,   350,   428,   975,   977,   978,
    1004,  1090,  1111,   546,   680,    26,   398,   962,   320,  1424,
    1424,   135,   136,   435,   546,   936,  1333,  1334,  1375,   787,
    1374,  1374,  1272,   787,   936,  1434,  1434,   358,   475,   585,
    1413,  1374,  1280,   167,   437,   448,   470,   477,  1306,  1307,
    1308,   286,   287,  1396,  1488,  1488,   383,   908,  1090,   641,
     642,   901,   902,   903,   480,   624,   643,   644,   663,   911,
     912,  1488,   752,    26,   771,   771,   779,  1223,   752,  1213,
    1321,  1374,  1264,  1331,   429,  1264,   429,   429,  1258,  1259,
     429,   429,    63,   298,   356,   368,   378,   396,   406,   409,
     422,   471,   501,   511,   532,   535,   537,   565,   574,  1366,
    1367,  1368,  1370,  1255,  1256,  1252,  1253,   663,  1250,   390,
     619,  1425,   576,   457,   546,  1482,   673,   674,   936,   936,
     936,  1240,   862,     5,   390,   390,   390,   390,   390,  1413,
     390,   390,   390,   390,   589,   884,    19,    26,   589,   390,
     390,    26,  1385,   390,   390,   390,   390,     5,   750,   390,
     837,   837,   837,   390,   837,   390,   390,   390,   440,   440,
     440,   862,  1405,   440,   862,  1405,   705,   706,   707,   837,
     429,   936,  1238,   616,  1136,   625,     5,     5,     5,   579,
     844,   619,     5,   482,   625,   390,   425,   429,   624,   163,
     166,   269,   272,   736,   739,   740,  1004,   737,   738,   936,
     429,   937,   648,   649,  1137,   844,   936,   936,   926,   927,
     508,  1478,   826,   553,  1286,    26,    26,   429,  1011,  1013,
    1090,   535,  1151,   840,    65,   837,  1196,    26,  1090,  1488,
       5,     5,   390,   390,   709,   936,   390,  1425,   705,   429,
     429,   721,   717,   359,   715,   844,   338,   718,   722,   596,
    1006,  1075,  1071,   361,  1069,  1070,   842,   625,  1096,    21,
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
     910,  1090,     5,   546,   904,   905,   638,   903,   909,   936,
     909,   913,   914,   909,   323,   912,  1042,   425,   425,   459,
    1206,  1226,  1059,   459,  1169,  1200,   429,     5,   390,     9,
     293,   429,   441,  1350,  1351,  1352,  1353,  1354,  1358,  1362,
    1364,  1417,   390,   611,   936,  1320,  1322,  1374,  1377,  1378,
    1324,  1377,     5,   390,  1324,  1350,   365,   452,   469,   512,
     552,   581,   590,  1387,  1387,   429,   429,   429,   429,   429,
     429,   206,   398,  1326,  1328,     5,   390,     5,   390,   936,
    1466,     8,  1425,  1101,   844,     5,  1245,  1246,   862,  1048,
     928,  1414,  1415,  1417,   877,  1385,   877,    26,    26,   589,
      24,    26,   790,   878,  1216,   390,  1216,   791,   390,  1216,
     872,   870,   876,  1216,   874,  1216,  1216,  1216,    25,    25,
      25,   837,   854,   390,    25,   854,   390,   865,     5,   866,
     619,  1245,   576,  1425,  1425,   844,   844,   925,   508,   844,
    1480,     5,    21,  1377,   974,  1425,   619,   936,   737,   745,
     744,   746,   936,   940,   747,   940,   190,   740,   743,     5,
     976,   619,   844,     8,   936,  1287,   891,  1012,  1013,  1090,
       5,   324,    25,  1228,   343,   343,   457,   619,   343,   429,
     694,   698,   691,  1488,  1488,   723,   719,   715,  1007,    25,
     935,  1076,  1090,  1488,   844,   424,   457,   862,  1418,  1418,
    1383,  1387,   470,  1417,   429,   429,   429,   429,   429,   429,
     429,   936,   429,     5,    18,    19,    20,    21,    92,    93,
      94,    95,    96,    97,  1439,  1464,  1090,  1113,    62,   542,
     965,   960,   961,    26,   678,   936,  1488,  1488,  1488,  1488,
       5,   979,     5,   980,  1488,  1488,  1488,  1488,  1011,  1488,
     935,    25,    14,    14,     5,   390,    26,  1374,  1413,  1394,
     595,   595,  1271,  1399,  1400,  1336,  1315,  1377,   616,   930,
    1350,   429,  1275,   936,  1435,  1434,  1414,    48,    49,    50,
      51,    52,   583,  1451,   844,   844,  1281,   930,  1310,  1377,
    1374,  1308,   619,   619,     5,     5,  1090,   909,  1488,  1488,
       5,   916,   917,  1488,  1488,   915,  1035,   810,   768,    73,
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
    1090,   696,   390,   705,   705,  1488,  1488,  1011,  1073,    25,
    1077,  1090,   571,   921,  1101,   482,   843,  1020,   625,  1413,
     390,   394,  1377,  1440,   358,   475,   585,  1365,  1417,  1420,
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
     695,   699,   390,  1488,   935,   844,   919,   425,  1388,  1414,
       5,  1387,     5,   390,  1417,     5,   390,  1417,  1417,  1417,
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
    1072,  1488,   457,  1346,  1387,   625,  1387,   390,  1417,   390,
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
     920,  1101,   390,   625,  1388,   625,   968,   998,  1428,  1408,
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
#line 1198 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1203 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1207 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 70:
#line 1210 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1216 "fgl.yacc"
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
#line 1225 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1229 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1234 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1238 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1246 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1250 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1254 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1256 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1262 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1267 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1270 "fgl.yacc"
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
#line 1286 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1293 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1297 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1301 "fgl.yacc"
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
#line 1323 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1323 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1327 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1328 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1329 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1334 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1337 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1343 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1346 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1358 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1364 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1367 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1382 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1392 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1398 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1407 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1420 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1423 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1425 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1431 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1433 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1438 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1443 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1449 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1453 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1468 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1471 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1474 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1477 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1480 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1483 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1505 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1514 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1524 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1538 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1542 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1545 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1553 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1559 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1574 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1578 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1583 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1593 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1596 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1600 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1602 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1605 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1607 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1610 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1612 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1615 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1618 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1628 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1629 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1637 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1638 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1655 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1658 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1661 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1664 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1667 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1670 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1679 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1687 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1692 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1705 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1709 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1724 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1725 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1733 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1733 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1743 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1743 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1752 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1753 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1754 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1757 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1762 "fgl.yacc"
    { }
    break;

  case 194:
#line 1762 "fgl.yacc"
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
#line 1779 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1783 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1797 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1806 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1810 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1826 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1828 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1829 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1836 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1836 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1837 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1838 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1841 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1843 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1853 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1868 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1868 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1874 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1875 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1882 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1883 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1884 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1885 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1888 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1889 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1890 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1891 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1895 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1900 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1905 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1909 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1912 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1916 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1917 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1918 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1919 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1920 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1921 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1922 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1923 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1926 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1927 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1928 "fgl.yacc"
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
#line 1960 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1964 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1966 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1968 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1970 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1975 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1979 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1979 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1983 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1984 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1985 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1986 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1987 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1988 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1990 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 1995 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 1995 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 1998 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 2000 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 2006 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 2008 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2014 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2022 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2022 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2025 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2026 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2027 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2028 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2029 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2030 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2032 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2053 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2062 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2064 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2066 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2068 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2069 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2070 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2071 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2072 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2077 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2084 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2089 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2091 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2093 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2094 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2095 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2096 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2097 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2098 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2099 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2102 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2104 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2110 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2118 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2126 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2130 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2138 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2139 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2140 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2141 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2160 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2172 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2176 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2179 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2182 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2183 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2184 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2185 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2186 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2192 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2199 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2204 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2209 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2213 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2216 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2224 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2226 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2231 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2243 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2246 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2249 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2252 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2255 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2258 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2271 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2274 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2289 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 364:
#line 2292 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 365:
#line 2306 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 366:
#line 2308 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 367:
#line 2310 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 368:
#line 2312 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 369:
#line 2314 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 370:
#line 2316 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 371:
#line 2317 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 372:
#line 2324 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 373:
#line 2326 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 374:
#line 2330 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 375:
#line 2332 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 376:
#line 2334 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 377:
#line 2336 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 378:
#line 2338 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 379:
#line 2340 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 380:
#line 2342 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 381:
#line 2348 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 386:
#line 2365 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2371 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2375 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2380 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2390 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 402:
#line 2397 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2404 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2404 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2409 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 407:
#line 2413 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2419 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2427 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2433 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2442 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2444 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2451 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2459 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2463 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2472 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2477 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2482 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2486 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2488 "fgl.yacc"
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
#line 2498 "fgl.yacc"
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
#line 2512 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2520 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2532 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2538 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2544 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2554 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2560 "fgl.yacc"
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
#line 2632 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2638 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2642 "fgl.yacc"
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
#line 2650 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2650 "fgl.yacc"
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
#line 2666 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2670 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2676 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2679 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2687 "fgl.yacc"
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
#line 2698 "fgl.yacc"
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
#line 2708 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2714 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2724 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2729 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2736 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2739 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2742 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2747 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2754 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2759 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2764 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2769 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2780 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2788 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2796 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2801 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2805 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2810 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2814 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2818 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2824 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2827 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2831 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2835 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2839 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2843 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2847 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2854 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2864 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2869 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2875 "fgl.yacc"
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
#line 2885 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2890 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2893 "fgl.yacc"
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
#line 2907 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 477:
#line 2907 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 479:
#line 2910 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 480:
#line 2910 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 482:
#line 2913 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 483:
#line 2913 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 485:
#line 2916 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 486:
#line 2916 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2916 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 488:
#line 2919 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2925 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2931 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2937 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2947 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2948 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2956 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);

}
    break;

  case 497:
#line 2962 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2963 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 499:
#line 2968 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 500:
#line 2972 "fgl.yacc"
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
#line 2981 "fgl.yacc"
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
#line 2993 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 2998 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 3005 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 3009 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3012 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3015 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3021 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3024 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3027 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3044 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3047 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3053 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3054 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3055 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3060 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3061 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3062 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3063 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3065 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3066 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3067 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3069 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3070 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3076 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3081 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3093 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 533:
#line 3097 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 534:
#line 3102 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 535:
#line 3106 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 536:
#line 3122 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 537:
#line 3128 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 538:
#line 3136 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 545:
#line 3153 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 546:
#line 3155 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 547:
#line 3158 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 548:
#line 3160 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 553:
#line 3174 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 554:
#line 3176 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 555:
#line 3179 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 556:
#line 3181 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 569:
#line 3212 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 570:
#line 3214 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 571:
#line 3217 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 572:
#line 3219 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 573:
#line 3222 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 574:
#line 3224 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 575:
#line 3227 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 576:
#line 3229 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 577:
#line 3232 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 578:
#line 3234 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 579:
#line 3248 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 580:
#line 3252 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 581:
#line 3253 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 582:
#line 3260 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 584:
#line 3278 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 585:
#line 3294 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 586:
#line 3295 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 587:
#line 3296 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 588:
#line 3297 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 589:
#line 3298 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 590:
#line 3299 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 594:
#line 3307 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 596:
#line 3313 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 597:
#line 3315 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 598:
#line 3316 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 599:
#line 3318 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 600:
#line 3320 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 601:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 602:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 603:
#line 3326 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3329 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 605:
#line 3336 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 606:
#line 3338 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 607:
#line 3344 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 608:
#line 3349 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3354 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3359 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 611:
#line 3359 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 612:
#line 3362 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 613:
#line 3368 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 614:
#line 3373 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 615:
#line 3377 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 618:
#line 3385 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 619:
#line 3387 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 620:
#line 3389 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 621:
#line 3391 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 622:
#line 3393 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 623:
#line 3395 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3398 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 626:
#line 3407 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 627:
#line 3469 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 628:
#line 3482 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 630:
#line 3489 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 631:
#line 3492 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 632:
#line 3498 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 633:
#line 3504 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 634:
#line 3508 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 635:
#line 3512 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3518 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 637:
#line 3522 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 638:
#line 3526 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3531 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 640:
#line 3536 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 659:
#line 3577 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 660:
#line 3582 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 662:
#line 3587 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 664:
#line 3590 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 665:
#line 3592 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 666:
#line 3595 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 667:
#line 3599 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 668:
#line 3602 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 669:
#line 3608 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 670:
#line 3619 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 671:
#line 3620 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 672:
#line 3623 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 674:
#line 3629 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 675:
#line 3633 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 676:
#line 3634 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 679:
#line 3648 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 680:
#line 3650 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 683:
#line 3659 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 684:
#line 3661 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 685:
#line 3665 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 686:
#line 3667 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 687:
#line 3670 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 688:
#line 3672 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3675 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 690:
#line 3678 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 691:
#line 3681 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 692:
#line 3683 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 693:
#line 3686 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 694:
#line 3688 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 695:
#line 3691 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 696:
#line 3693 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 697:
#line 3696 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 698:
#line 3698 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 699:
#line 3699 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 700:
#line 3701 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 701:
#line 3702 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 702:
#line 3704 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3705 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 704:
#line 3707 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3747 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 706:
#line 3748 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 707:
#line 3756 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 708:
#line 3757 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 709:
#line 3766 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 710:
#line 3771 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 711:
#line 3776 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 712:
#line 3777 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 714:
#line 3782 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 715:
#line 3785 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 716:
#line 3793 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 717:
#line 3798 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 718:
#line 3802 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 719:
#line 3809 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 720:
#line 3818 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 721:
#line 3823 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 722:
#line 3824 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 723:
#line 3825 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 724:
#line 3826 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 725:
#line 3829 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 727:
#line 3832 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 728:
#line 3839 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 729:
#line 3840 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 730:
#line 3841 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 731:
#line 3842 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 732:
#line 3843 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3844 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 734:
#line 3845 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 735:
#line 3846 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 736:
#line 3847 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 737:
#line 3852 "fgl.yacc"
    {iskey=1;}
    break;

  case 738:
#line 3852 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 739:
#line 3854 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 740:
#line 3857 "fgl.yacc"
    {iskey=1;}
    break;

  case 741:
#line 3857 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 742:
#line 3859 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 743:
#line 3863 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 744:
#line 3863 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 745:
#line 3866 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 746:
#line 3867 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 748:
#line 3870 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 749:
#line 3875 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 750:
#line 3875 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 755:
#line 3882 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 756:
#line 3883 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 757:
#line 3884 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 758:
#line 3885 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 759:
#line 3886 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 760:
#line 3887 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 761:
#line 3888 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 762:
#line 3889 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 763:
#line 3890 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 764:
#line 3891 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 765:
#line 3892 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 766:
#line 3893 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 767:
#line 3894 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 768:
#line 3898 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 769:
#line 3916 "fgl.yacc"
    {chk4var=1;}
    break;

  case 770:
#line 3916 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 771:
#line 3919 "fgl.yacc"
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
#line 3943 "fgl.yacc"
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
#line 3961 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3967 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 3973 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 777:
#line 3979 "fgl.yacc"
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
#line 3990 "fgl.yacc"
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
#line 4013 "fgl.yacc"
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
#line 4029 "fgl.yacc"
    {
	}
    break;

  case 789:
#line 4052 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 793:
#line 4060 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 811:
#line 4086 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 812:
#line 4087 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 813:
#line 4095 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 814:
#line 4100 "fgl.yacc"
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
#line 4116 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 816:
#line 4122 "fgl.yacc"
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
#line 4137 "fgl.yacc"
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
#line 4150 "fgl.yacc"
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
#line 4160 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 821:
#line 4167 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 822:
#line 4174 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 823:
#line 4180 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 824:
#line 4180 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 825:
#line 4185 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 826:
#line 4190 "fgl.yacc"
    {
}
    break;

  case 832:
#line 4202 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 834:
#line 4210 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 835:
#line 4216 "fgl.yacc"
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
#line 4230 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 837:
#line 4234 "fgl.yacc"
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
#line 4247 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 840:
#line 4261 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 841:
#line 4267 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 842:
#line 4271 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 845:
#line 4283 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 846:
#line 4288 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 847:
#line 4293 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 848:
#line 4296 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 849:
#line 4311 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 850:
#line 4319 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 851:
#line 4325 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 852:
#line 4336 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 853:
#line 4340 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 854:
#line 4347 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 855:
#line 4354 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 856:
#line 4360 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 857:
#line 4365 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 860:
#line 4372 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 861:
#line 4373 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 862:
#line 4375 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 863:
#line 4376 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 864:
#line 4379 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 865:
#line 4380 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 866:
#line 4381 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 867:
#line 4383 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 868:
#line 4388 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 869:
#line 4393 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 870:
#line 4400 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 874:
#line 4407 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 875:
#line 4409 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 876:
#line 4411 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 878:
#line 4421 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 879:
#line 4424 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 880:
#line 4427 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 887:
#line 4443 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 888:
#line 4448 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 889:
#line 4448 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 890:
#line 4451 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4478 "fgl.yacc"
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
#line 4536 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 895:
#line 4543 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 896:
#line 4547 "fgl.yacc"
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
#line 4590 "fgl.yacc"
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
#line 4638 "fgl.yacc"
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
#line 4652 "fgl.yacc"
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
#line 4676 "fgl.yacc"
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
#line 4736 "fgl.yacc"
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
#line 4792 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 910:
#line 4797 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4805 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 912:
#line 4810 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 913:
#line 4818 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 914:
#line 4824 "fgl.yacc"
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
#line 4857 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 916:
#line 4860 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 917:
#line 4862 "fgl.yacc"
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
#line 4903 "fgl.yacc"
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
#line 4956 "fgl.yacc"
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
#line 5008 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 926:
#line 5015 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 927:
#line 5021 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 928:
#line 5032 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 929:
#line 5039 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 931:
#line 5047 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 932:
#line 5050 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 933:
#line 5051 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 935:
#line 5053 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 936:
#line 5054 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 5057 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 938:
#line 5060 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 939:
#line 5066 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 940:
#line 5069 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 941:
#line 5073 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 942:
#line 5077 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 5084 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 944:
#line 5089 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 945:
#line 5096 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 946:
#line 5099 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 951:
#line 5112 "fgl.yacc"
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
#line 5131 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 953:
#line 5138 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5145 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 955:
#line 5148 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 956:
#line 5162 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 961:
#line 5179 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 962:
#line 5184 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 963:
#line 5190 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 965:
#line 5197 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 966:
#line 5202 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 967:
#line 5205 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 968:
#line 5206 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 969:
#line 5209 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 970:
#line 5210 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 971:
#line 5213 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 972:
#line 5214 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 973:
#line 5219 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 974:
#line 5226 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 975:
#line 5229 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 976:
#line 5235 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 977:
#line 5237 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 978:
#line 5239 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 979:
#line 5241 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 980:
#line 5244 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 981:
#line 5244 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 982:
#line 5245 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 983:
#line 5250 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 984:
#line 5258 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 985:
#line 5259 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 986:
#line 5264 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 987:
#line 5266 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 988:
#line 5268 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 5285 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 993:
#line 5288 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 994:
#line 5291 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 995:
#line 5294 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 996:
#line 5298 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 997:
#line 5301 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 998:
#line 5304 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 999:
#line 5308 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5312 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5316 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1002:
#line 5319 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1003:
#line 5323 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1004:
#line 5326 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1005:
#line 5327 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5328 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1007:
#line 5331 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1008:
#line 5334 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1009:
#line 5337 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1010:
#line 5340 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1011:
#line 5343 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1012:
#line 5346 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1013:
#line 5349 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1014:
#line 5366 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1017:
#line 5376 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1018:
#line 5383 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1020:
#line 5404 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1021:
#line 5409 "fgl.yacc"
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
#line 5422 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1023:
#line 5427 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1024:
#line 5428 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1025:
#line 5432 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1029:
#line 5438 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1030:
#line 5440 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1032:
#line 5455 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1033:
#line 5459 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1034:
#line 5465 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1035:
#line 5466 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1036:
#line 5469 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1037:
#line 5470 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1038:
#line 5473 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1040:
#line 5492 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1041:
#line 5497 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1042:
#line 5502 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1043:
#line 5507 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1049:
#line 5529 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1050:
#line 5536 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1051:
#line 5545 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1052:
#line 5551 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1053:
#line 5553 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1057:
#line 5564 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1058:
#line 5565 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1059:
#line 5567 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1060:
#line 5568 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1061:
#line 5570 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1062:
#line 5571 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1063:
#line 5573 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1064:
#line 5574 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1065:
#line 5576 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1066:
#line 5577 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1067:
#line 5578 "fgl.yacc"
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
#line 5592 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1069:
#line 5594 "fgl.yacc"
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
#line 5611 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1077:
#line 5623 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1078:
#line 5623 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1079:
#line 5629 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1080:
#line 5629 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1081:
#line 5632 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1082:
#line 5632 "fgl.yacc"
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
#line 5642 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1084:
#line 5643 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1085:
#line 5644 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1086:
#line 5651 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1087:
#line 5663 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1093:
#line 5674 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1094:
#line 5679 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1095:
#line 5683 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1096:
#line 5688 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1097:
#line 5694 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1098:
#line 5695 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1099:
#line 5696 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1100:
#line 5700 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1101:
#line 5701 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1102:
#line 5702 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1103:
#line 5703 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1104:
#line 5707 "fgl.yacc"
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
#line 5717 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1106:
#line 5719 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1107:
#line 5724 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1108:
#line 5727 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1109:
#line 5732 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1110:
#line 5739 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1111:
#line 5746 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1112:
#line 5753 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1113:
#line 5762 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1114:
#line 5769 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1115:
#line 5776 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1116:
#line 5783 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1117:
#line 5790 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1122:
#line 5803 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1123:
#line 5804 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1124:
#line 5805 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1125:
#line 5806 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5807 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5808 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1128:
#line 5809 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1129:
#line 5810 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1130:
#line 5811 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1131:
#line 5812 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1134:
#line 5818 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1135:
#line 5819 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1136:
#line 5820 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1137:
#line 5821 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1142:
#line 5830 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1143:
#line 5831 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1144:
#line 5832 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1145:
#line 5833 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1146:
#line 5834 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5835 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5836 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1149:
#line 5837 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5839 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1151:
#line 5840 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1152:
#line 5841 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1153:
#line 5842 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1154:
#line 5844 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1155:
#line 5845 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1156:
#line 5846 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1157:
#line 5847 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1161:
#line 5852 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1162:
#line 5853 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1166:
#line 5860 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1167:
#line 5867 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1168:
#line 5874 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1169:
#line 5885 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1170:
#line 5894 "fgl.yacc"
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
#line 5905 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1172:
#line 5909 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1173:
#line 5913 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1174:
#line 5919 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1175:
#line 5924 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1176:
#line 5932 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1177:
#line 5935 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1178:
#line 5944 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1179:
#line 5955 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1181:
#line 5962 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1182:
#line 5970 "fgl.yacc"
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
#line 5980 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1184:
#line 5983 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1185:
#line 5987 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1186:
#line 5995 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1187:
#line 5998 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1188:
#line 6004 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1189:
#line 6008 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1190:
#line 6012 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1191:
#line 6016 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1192:
#line 6020 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1193:
#line 6026 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1194:
#line 6027 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1195:
#line 6028 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1196:
#line 6029 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1197:
#line 6034 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1198:
#line 6036 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1199:
#line 6039 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1200:
#line 6043 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1201:
#line 6046 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1202:
#line 6053 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1203:
#line 6058 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1204:
#line 6059 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1205:
#line 6060 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1206:
#line 6065 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1207:
#line 6066 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1208:
#line 6072 "fgl.yacc"
    {insql=1;}
    break;

  case 1209:
#line 6072 "fgl.yacc"
    {insql=0;}
    break;

  case 1210:
#line 6072 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1211:
#line 6077 "fgl.yacc"
    {insql=1;}
    break;

  case 1212:
#line 6077 "fgl.yacc"
    {insql=0;}
    break;

  case 1213:
#line 6077 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1214:
#line 6088 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1215:
#line 6089 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1216:
#line 6095 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1217:
#line 6097 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1219:
#line 6110 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1220:
#line 6114 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1221:
#line 6115 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1223:
#line 6120 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1224:
#line 6123 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1225:
#line 6129 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1226:
#line 6132 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6140 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1229:
#line 6147 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1230:
#line 6154 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1231:
#line 6157 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1232:
#line 6166 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1233:
#line 6169 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1234:
#line 6172 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1235:
#line 6175 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1236:
#line 6178 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6181 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6184 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6191 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1240:
#line 6194 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1241:
#line 6201 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1242:
#line 6204 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1243:
#line 6210 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1244:
#line 6213 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1245:
#line 6220 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1246:
#line 6223 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1248:
#line 6231 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1250:
#line 6240 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1251:
#line 6243 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1252:
#line 6249 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1253:
#line 6252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1254:
#line 6258 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1255:
#line 6265 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1256:
#line 6266 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1257:
#line 6270 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1258:
#line 6276 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1259:
#line 6279 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1261:
#line 6287 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1262:
#line 6294 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6297 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1267:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1273:
#line 6321 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1274:
#line 6324 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1275:
#line 6327 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1276:
#line 6333 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1278:
#line 6339 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1280:
#line 6350 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1281:
#line 6364 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1282:
#line 6373 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1283:
#line 6373 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1284:
#line 6378 "fgl.yacc"
    {insql=1;}
    break;

  case 1285:
#line 6378 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1286:
#line 6383 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1287:
#line 6386 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6388 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6395 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6399 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1292:
#line 6403 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1293:
#line 6410 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 6413 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1295:
#line 6420 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1296:
#line 6424 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1297:
#line 6428 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1298:
#line 6433 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1299:
#line 6438 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1300:
#line 6442 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1301:
#line 6448 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1302:
#line 6452 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1303:
#line 6458 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1304:
#line 6465 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1305:
#line 6469 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1306:
#line 6474 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1307:
#line 6484 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1308:
#line 6487 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1309:
#line 6489 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1310:
#line 6491 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1311:
#line 6493 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1312:
#line 6495 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6497 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6499 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1315:
#line 6505 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1316:
#line 6515 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1317:
#line 6522 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1319:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6537 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1326:
#line 6542 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1327:
#line 6547 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1328:
#line 6554 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1329:
#line 6555 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1330:
#line 6562 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1331:
#line 6573 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1332:
#line 6574 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1333:
#line 6577 "fgl.yacc"
    {insql=1;}
    break;

  case 1334:
#line 6577 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1335:
#line 6582 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1336:
#line 6587 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1338:
#line 6593 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1340:
#line 6597 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1341:
#line 6602 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1342:
#line 6607 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1343:
#line 6611 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1345:
#line 6617 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1346:
#line 6621 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1347:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6632 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1349:
#line 6634 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1350:
#line 6639 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1353:
#line 6646 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1357:
#line 6653 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6656 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1359:
#line 6658 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6664 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6670 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6680 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1367:
#line 6685 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1368:
#line 6687 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6693 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1371:
#line 6696 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1373:
#line 6702 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1374:
#line 6710 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6715 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6725 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6731 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6737 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6739 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6745 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6750 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1386:
#line 6753 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1387:
#line 6756 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1388:
#line 6764 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6766 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1390:
#line 6779 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1391:
#line 6784 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6788 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1394:
#line 6790 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1395:
#line 6797 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1396:
#line 6800 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1397:
#line 6806 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1398:
#line 6810 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1399:
#line 6814 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1400:
#line 6818 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1401:
#line 6821 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1402:
#line 6829 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1403:
#line 6836 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1406:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1407:
#line 6851 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1408:
#line 6854 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6865 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6872 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6878 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6881 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6888 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6895 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1416:
#line 6902 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1417:
#line 6908 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1418:
#line 6909 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6910 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1421:
#line 6914 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6919 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1424:
#line 6926 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1425:
#line 6931 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1426:
#line 6932 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1427:
#line 6935 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1428:
#line 6938 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1429:
#line 6943 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1430:
#line 6944 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1431:
#line 6949 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1432:
#line 6952 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 6958 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 6961 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 6967 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1436:
#line 6970 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1437:
#line 6976 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 6979 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1439:
#line 6986 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1440:
#line 6987 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1441:
#line 7016 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1442:
#line 7018 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7022 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1445:
#line 7035 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1446:
#line 7038 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 7041 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1448:
#line 7044 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 7052 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 7055 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1453:
#line 7061 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 7067 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1456:
#line 7070 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1457:
#line 7073 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1458:
#line 7076 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7079 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1460:
#line 7082 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7085 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1463:
#line 7092 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1468:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1469:
#line 7100 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1470:
#line 7105 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1471:
#line 7108 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7112 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7118 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7119 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1475:
#line 7120 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1476:
#line 7121 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1481:
#line 7141 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7146 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7147 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1485:
#line 7150 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7155 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7158 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7161 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7166 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7168 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7171 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1500:
#line 7172 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1501:
#line 7179 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7184 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1509:
#line 7200 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1510:
#line 7201 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1511:
#line 7205 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1512:
#line 7206 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1514:
#line 7225 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1515:
#line 7226 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1516:
#line 7227 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1517:
#line 7231 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1518:
#line 7234 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7240 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1520:
#line 7245 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1521:
#line 7250 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1523:
#line 7261 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1528:
#line 7276 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1529:
#line 7279 "fgl.yacc"
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
#line 7292 "fgl.yacc"
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
#line 7307 "fgl.yacc"
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
#line 7319 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1533:
#line 7321 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1534:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1535:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1536:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1537:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1538:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1539:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1540:
#line 7325 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1541:
#line 7328 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1542:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1543:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1544:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1545:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1546:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1547:
#line 7333 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1548:
#line 7335 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1549:
#line 7338 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1564:
#line 7347 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1565:
#line 7348 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1566:
#line 7352 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1567:
#line 7360 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1568:
#line 7360 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1569:
#line 7366 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1570:
#line 7366 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1571:
#line 7373 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1572:
#line 7373 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1573:
#line 7379 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1574:
#line 7379 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1575:
#line 7387 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1576:
#line 7388 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1577:
#line 7389 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1581:
#line 7396 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7397 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7402 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1584:
#line 7405 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1585:
#line 7411 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1586:
#line 7416 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1587:
#line 7425 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1588:
#line 7437 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1589:
#line 7438 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1590:
#line 7441 "fgl.yacc"
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
#line 7456 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1592:
#line 7466 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1593:
#line 7469 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1594:
#line 7477 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1595:
#line 7486 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1596:
#line 7489 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1597:
#line 7493 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1598:
#line 7496 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1599:
#line 7497 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1601:
#line 7506 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1602:
#line 7507 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1603:
#line 7516 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1604:
#line 7525 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1605:
#line 7530 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1606:
#line 7531 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1607:
#line 7532 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1608:
#line 7533 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1609:
#line 7541 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7544 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1611:
#line 7550 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7553 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1613:
#line 7563 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1614:
#line 7572 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1615:
#line 7575 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1616:
#line 7578 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7584 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7590 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7593 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7596 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1621:
#line 7599 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1622:
#line 7606 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1623:
#line 7608 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1624:
#line 7610 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1625:
#line 7612 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7614 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7615 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1628:
#line 7616 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1629:
#line 7617 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1630:
#line 7618 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1631:
#line 7619 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1632:
#line 7620 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1633:
#line 7622 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1634:
#line 7624 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1635:
#line 7626 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1636:
#line 7628 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7630 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7632 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7634 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7635 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7637 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1642:
#line 7641 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1643:
#line 7642 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1645:
#line 7652 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1646:
#line 7661 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1647:
#line 7665 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1648:
#line 7672 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1649:
#line 7672 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1651:
#line 7676 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1652:
#line 7681 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1653:
#line 7681 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1655:
#line 7685 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1656:
#line 7689 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1659:
#line 7698 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1660:
#line 7698 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1665:
#line 7717 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1666:
#line 7718 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1669:
#line 7726 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1670:
#line 7732 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1673:
#line 7751 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1674:
#line 7752 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1675:
#line 7753 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1676:
#line 7754 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1677:
#line 7755 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1678:
#line 7756 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1679:
#line 7760 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1680:
#line 7761 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1681:
#line 7762 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7766 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1683:
#line 7770 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1685:
#line 7779 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1687:
#line 7784 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1688:
#line 7785 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1689:
#line 7789 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1690:
#line 7795 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1691:
#line 7882 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1692:
#line 7886 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1693:
#line 7888 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1694:
#line 7895 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1695:
#line 7899 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1696:
#line 7905 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1697:
#line 7913 "fgl.yacc"
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
#line 7923 "fgl.yacc"
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
#line 7933 "fgl.yacc"
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
#line 7945 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1701:
#line 7948 "fgl.yacc"
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
#line 7967 "fgl.yacc"
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
#line 7993 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1704:
#line 7996 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1706:
#line 8005 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1707:
#line 8010 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1708:
#line 8013 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1709:
#line 8021 "fgl.yacc"
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
#line 8029 "fgl.yacc"
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
#line 8042 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1712:
#line 8045 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1713:
#line 8053 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1714:
#line 8056 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1715:
#line 8059 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1716:
#line 8067 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1717:
#line 8071 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1718:
#line 8074 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1719:
#line 8077 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1720:
#line 8080 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1721:
#line 8084 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1722:
#line 8085 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1723:
#line 8086 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1724:
#line 8087 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1725:
#line 8088 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1726:
#line 8094 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1727:
#line 8095 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1728:
#line 8096 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1729:
#line 8097 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1730:
#line 8098 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 8099 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1732:
#line 8100 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1733:
#line 8101 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1734:
#line 8102 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1735:
#line 8103 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1736:
#line 8104 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1737:
#line 8105 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1738:
#line 8106 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1739:
#line 8107 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);printf("C14\n");}
    break;

  case 1740:
#line 8111 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1741:
#line 8117 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1742:
#line 8118 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1743:
#line 8131 "fgl.yacc"
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
#line 8151 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1748:
#line 8157 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1749:
#line 8158 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1753:
#line 8170 "fgl.yacc"
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
#line 8196 "fgl.yacc"
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
#line 8247 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1756:
#line 8249 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 8251 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 8252 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1759:
#line 8257 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1760:
#line 8262 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 8263 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1762:
#line 8267 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1763:
#line 8269 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8271 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8274 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1766:
#line 8278 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1767:
#line 8283 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1768:
#line 8288 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1769:
#line 8292 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1771:
#line 8302 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1773:
#line 8317 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1774:
#line 8320 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1775:
#line 8324 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1778:
#line 8343 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1779:
#line 8344 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1780:
#line 8347 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1781:
#line 8348 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1782:
#line 8349 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1783:
#line 8350 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1784:
#line 8351 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1785:
#line 8352 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1786:
#line 8353 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1787:
#line 8358 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1788:
#line 8359 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1789:
#line 8363 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1790:
#line 8367 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1791:
#line 8371 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1792:
#line 8375 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1793:
#line 8380 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1794:
#line 8384 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1795:
#line 8389 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1797:
#line 8397 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1799:
#line 8403 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1800:
#line 8409 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1801:
#line 8413 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1806:
#line 8431 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1807:
#line 8438 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1808:
#line 8447 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1809:
#line 8447 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17111 "y.tab.c"

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


#line 8542 "fgl.yacc"

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



