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
     PAGE_TRAILER_SIZE = 1042,
     PAGE_HEADER_SIZE = 1043,
     FIRST_PAGE_HEADER_SIZE = 1044,
     BYTES_USE_AS_IMAGE = 1045,
     BYTES_USE_AS_ASCII = 1046,
     KWUP_BY = 1047,
     KWDOWN_BY = 1048,
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
     KWDOWN = 1516,
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
     KWUP = 1611,
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
#define PAGE_TRAILER_SIZE 1042
#define PAGE_HEADER_SIZE 1043
#define FIRST_PAGE_HEADER_SIZE 1044
#define BYTES_USE_AS_IMAGE 1045
#define BYTES_USE_AS_ASCII 1046
#define KWUP_BY 1047
#define KWDOWN_BY 1048
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
#define KWDOWN 1516
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
#define KWUP 1611
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
#define YYLAST   8788

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  667
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  826
/* YYNRULES -- Number of rules. */
#define YYNRULES  1894
/* YYNRULES -- Number of states. */
#define YYNSTATES  3158

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
    1602,  1612,  1613,  1617,  1618,  1619,  1630,  1631,  1633,  1634,
    1636,  1638,  1641,  1642,  1646,  1647,  1651,  1652,  1654,  1656,
    1659,  1660,  1664,  1665,  1669,  1673,  1675,  1680,  1684,  1686,
    1690,  1692,  1696,  1698,  1702,  1704,  1707,  1708,  1712,  1713,
    1717,  1718,  1723,  1724,  1729,  1730,  1735,  1738,  1742,  1744,
    1748,  1750,  1752,  1754,  1756,  1758,  1760,  1764,  1766,  1768,
    1773,  1780,  1785,  1789,  1796,  1800,  1807,  1809,  1811,  1813,
    1815,  1817,  1819,  1820,  1823,  1825,  1827,  1829,  1834,  1836,
    1838,  1840,  1845,  1849,  1856,  1860,  1867,  1869,  1871,  1874,
    1877,  1880,  1882,  1886,  1888,  1891,  1894,  1897,  1902,  1905,
    1908,  1913,  1914,  1923,  1924,  1926,  1928,  1930,  1931,  1933,
    1936,  1937,  1939,  1942,  1943,  1945,  1948,  1949,  1951,  1955,
    1956,  1959,  1960,  1968,  1969,  1970,  1974,  1975,  1976,  1984,
    1990,  1993,  1996,  1997,  2003,  2008,  2010,  2014,  2018,  2022,
    2023,  2026,  2027,  2029,  2031,  2034,  2035,  2040,  2041,  2046,
    2047,  2051,  2052,  2056,  2057,  2061,  2062,  2066,  2067,  2071,
    2072,  2076,  2077,  2081,  2082,  2086,  2087,  2091,  2093,  2097,
    2099,  2103,  2106,  2111,  2113,  2115,  2117,  2118,  2123,  2129,
    2136,  2137,  2148,  2152,  2155,  2158,  2160,  2162,  2163,  2166,
    2168,  2171,  2175,  2179,  2183,  2187,  2189,  2191,  2193,  2195,
    2196,  2200,  2202,  2203,  2207,  2210,  2213,  2215,  2219,  2221,
    2225,  2227,  2229,  2231,  2233,  2235,  2237,  2239,  2241,  2243,
    2245,  2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,
    2264,  2265,  2273,  2275,  2277,  2280,  2283,  2286,  2290,  2295,
    2296,  2300,  2301,  2303,  2305,  2308,  2310,  2312,  2314,  2316,
    2317,  2319,  2321,  2324,  2327,  2329,  2331,  2333,  2335,  2337,
    2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,  2354,  2356,
    2358,  2360,  2362,  2364,  2365,  2366,  2367,  2368,  2382,  2384,
    2385,  2386,  2393,  2396,  2398,  2401,  2404,  2406,  2408,  2411,
    2413,  2415,  2417,  2418,  2422,  2425,  2427,  2428,  2429,  2430,
    2445,  2446,  2452,  2454,  2455,  2459,  2460,  2468,  2469,  2475,
    2477,  2480,  2481,  2483,  2485,  2487,  2488,  2490,  2492,  2495,
    2498,  2501,  2503,  2505,  2507,  2509,  2513,  2515,  2517,  2518,
    2519,  2527,  2529,  2532,  2533,  2537,  2538,  2543,  2546,  2547,
    2550,  2552,  2554,  2556,  2558,  2560,  2562,  2564,  2568,  2569,
    2571,  2573,  2575,  2577,  2580,  2583,  2586,  2592,  2601,  2603,
    2605,  2607,  2612,  2617,  2619,  2621,  2623,  2625,  2628,  2631,
    2635,  2642,  2644,  2648,  2650,  2652,  2654,  2658,  2665,  2675,
    2677,  2679,  2681,  2683,  2686,  2687,  2689,  2691,  2695,  2697,
    2701,  2703,  2707,  2709,  2713,  2715,  2717,  2719,  2721,  2725,
    2727,  2731,  2733,  2737,  2739,  2741,  2743,  2747,  2750,  2751,
    2753,  2755,  2760,  2762,  2766,  2768,  2772,  2780,  2781,  2789,
    2790,  2797,  2801,  2803,  2807,  2809,  2812,  2818,  2819,  2827,
    2828,  2831,  2832,  2834,  2840,  2843,  2849,  2850,  2856,  2863,
    2868,  2869,  2871,  2873,  2878,  2879,  2882,  2883,  2889,  2894,
    2897,  2899,  2903,  2906,  2909,  2912,  2915,  2918,  2921,  2923,
    2926,  2929,  2932,  2935,  2938,  2941,  2944,  2947,  2950,  2952,
    2954,  2956,  2958,  2960,  2962,  2968,  2970,  2972,  2975,  2980,
    2982,  2983,  2994,  3000,  3001,  3003,  3004,  3007,  3009,  3012,
    3013,  3017,  3019,  3020,  3025,  3026,  3029,  3031,  3035,  3037,
    3039,  3043,  3048,  3053,  3056,  3058,  3060,  3062,  3063,  3065,
    3073,  3076,  3079,  3082,  3085,  3088,  3090,  3093,  3094,  3098,
    3099,  3103,  3104,  3108,  3109,  3113,  3114,  3118,  3119,  3124,
    3125,  3130,  3132,  3134,  3136,  3138,  3140,  3142,  3143,  3148,
    3149,  3151,  3152,  3157,  3159,  3162,  3165,  3168,  3169,  3171,
    3173,  3176,  3179,  3180,  3183,  3187,  3191,  3197,  3198,  3201,
    3206,  3208,  3210,  3212,  3214,  3216,  3217,  3219,  3221,  3225,
    3228,  3234,  3237,  3243,  3249,  3255,  3261,  3267,  3273,  3274,
    3277,  3279,  3282,  3285,  3288,  3291,  3294,  3297,  3299,  3302,
    3305,  3308,  3311,  3313,  3316,  3319,  3322,  3325,  3327,  3329,
    3331,  3332,  3335,  3338,  3341,  3344,  3347,  3350,  3353,  3356,
    3359,  3361,  3363,  3365,  3367,  3369,  3371,  3373,  3375,  3378,
    3381,  3384,  3387,  3390,  3392,  3394,  3396,  3397,  3401,  3404,
    3405,  3406,  3407,  3408,  3409,  3410,  3426,  3427,  3430,  3433,
    3434,  3436,  3437,  3438,  3439,  3440,  3441,  3442,  3458,  3461,
    3462,  3463,  3464,  3475,  3476,  3478,  3482,  3486,  3489,  3494,
    3498,  3502,  3506,  3508,  3510,  3512,  3514,  3516,  3518,  3519,
    3520,  3528,  3529,  3530,  3539,  3543,  3546,  3547,  3549,  3551,
    3555,  3558,  3561,  3563,  3565,  3569,  3571,  3573,  3576,  3578,
    3582,  3584,  3588,  3590,  3592,  3594,  3596,  3598,  3600,  3602,
    3605,  3610,  3612,  3616,  3618,  3622,  3625,  3630,  3632,  3636,
    3638,  3641,  3646,  3648,  3652,  3654,  3656,  3658,  3661,  3664,
    3669,  3672,  3677,  3679,  3683,  3685,  3687,  3689,  3692,  3694,
    3696,  3698,  3700,  3702,  3705,  3712,  3719,  3720,  3722,  3723,
    3725,  3728,  3730,  3731,  3737,  3738,  3744,  3746,  3747,  3751,
    3753,  3757,  3759,  3763,  3765,  3767,  3768,  3769,  3775,  3777,
    3780,  3782,  3783,  3784,  3788,  3789,  3790,  3794,  3796,  3798,
    3800,  3802,  3804,  3806,  3809,  3812,  3817,  3821,  3825,  3827,
    3831,  3834,  3836,  3838,  3839,  3841,  3843,  3845,  3847,  3848,
    3850,  3854,  3856,  3858,  3859,  3863,  3865,  3867,  3869,  3871,
    3873,  3875,  3877,  3879,  3881,  3883,  3885,  3887,  3895,  3896,
    3898,  3900,  3902,  3904,  3908,  3910,  3912,  3914,  3917,  3918,
    3922,  3924,  3928,  3930,  3934,  3936,  3938,  3945,  3946,  3950,
    3952,  3956,  3957,  3959,  3964,  3970,  3973,  3975,  3977,  3982,
    3984,  3988,  3993,  3998,  4000,  4004,  4006,  4008,  4010,  4013,
    4015,  4020,  4021,  4023,  4024,  4026,  4028,  4031,  4033,  4035,
    4037,  4039,  4044,  4048,  4050,  4052,  4054,  4057,  4059,  4061,
    4064,  4067,  4069,  4073,  4076,  4079,  4081,  4085,  4087,  4090,
    4095,  4097,  4100,  4102,  4106,  4111,  4112,  4114,  4115,  4117,
    4118,  4120,  4122,  4126,  4128,  4132,  4134,  4137,  4139,  4143,
    4146,  4149,  4150,  4153,  4155,  4157,  4163,  4167,  4173,  4177,
    4179,  4183,  4185,  4187,  4188,  4190,  4194,  4198,  4202,  4209,
    4214,  4219,  4225,  4227,  4229,  4231,  4233,  4235,  4237,  4239,
    4241,  4243,  4245,  4247,  4248,  4250,  4252,  4254,  4256,  4258,
    4260,  4262,  4267,  4273,  4275,  4281,  4287,  4289,  4291,  4293,
    4298,  4300,  4305,  4307,  4315,  4317,  4319,  4321,  4326,  4333,
    4334,  4337,  4342,  4344,  4346,  4348,  4350,  4352,  4354,  4356,
    4360,  4362,  4364,  4368,  4370,  4371,  4375,  4381,  4383,  4386,
    4389,  4394,  4398,  4400,  4402,  4404,  4406,  4408,  4410,  4413,
    4416,  4417,  4421,  4422,  4426,  4428,  4430,  4432,  4434,  4436,
    4438,  4440,  4445,  4447,  4449,  4451,  4453,  4455,  4457,  4459,
    4464,  4466,  4468,  4470,  4472,  4474,  4476,  4478,  4480,  4482,
    4484,  4486,  4488,  4490,  4492,  4494,  4496,  4500,  4501,  4510,
    4511,  4521,  4522,  4530,  4531,  4541,  4542,  4544,  4547,  4549,
    4553,  4555,  4559,  4565,  4567,  4569,  4571,  4573,  4576,  4577,
    4578,  4587,  4593,  4595,  4597,  4604,  4605,  4609,  4611,  4615,
    4620,  4622,  4623,  4626,  4631,  4638,  4639,  4641,  4643,  4645,
    4647,  4651,  4653,  4656,  4658,  4660,  4663,  4666,  4668,  4670,
    4672,  4675,  4680,  4684,  4687,  4691,  4695,  4699,  4701,  4703,
    4705,  4707,  4709,  4711,  4717,  4723,  4729,  4735,  4741,  4746,
    4751,  4755,  4760,  4762,  4766,  4768,  4774,  4782,  4788,  4789,
    4792,  4794,  4796,  4797,  4801,  4803,  4807,  4809,  4811,  4813,
    4814,  4818,  4820,  4822,  4824,  4826,  4831,  4838,  4840,  4842,
    4845,  4849,  4851,  4853,  4855,  4857,  4859,  4861,  4863,  4865,
    4871,  4877,  4882,  4883,  4888,  4890,  4893,  4895,  4897,  4899,
    4902,  4905,  4906,  4907,  4914,  4915,  4918,  4921,  4929,  4933,
    4937,  4940,  4943,  4946,  4948,  4952,  4954,  4958,  4960,  4964,
    4966,  4970,  4972,  4974,  4976,  4979,  4982,  4984,  4986,  4989,
    4994,  4996,  4998,  5000,  5002,  5004,  5006,  5010,  5013,  5017,
    5021,  5025,  5031,  5037,  5043,  5049,  5055,  5060,  5065,  5069,
    5074,  5076,  5078,  5082,  5084,  5087,  5089,  5091,  5093,  5097,
    5103,  5105,  5107,  5109,  5111,  5115,  5118,  5121,  5124,  5126,
    5129,  5132,  5134,  5137,  5140,  5143,  5145,  5149,  5152,  5154,
    5157,  5159,  5162,  5164,  5165,  5166,  5173,  5174,  5177,  5178,
    5180,  5182,  5185,  5188,  5190,  5192,  5197,  5201,  5203,  5207,
    5209,  5212,  5218,  5221,  5224,  5230,  5231,  5234,  5236,  5238,
    5241,  5248,  5255,  5257,  5258,  5260,  5263,  5265,  5268,  5269,
    5272,  5274,  5276,  5278,  5280,  5282,  5284,  5286,  5288,  5290,
    5292,  5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,
    5312,  5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,  5330,
    5332,  5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,  5350,
    5352,  5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,  5370,
    5372,  5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,  5390,
    5392,  5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,  5410,
    5412,  5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,  5430,
    5432,  5434,  5436,  5438,  5440
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1024,     0,    -1,   199,    -1,   196,    -1,   124,   672,   425,
     595,   673,    -1,   138,    -1,  1089,    -1,    26,    -1,   674,
      -1,   673,     5,   674,    -1,   937,    -1,   429,   675,   390,
      -1,   675,   676,   675,    -1,    26,    -1,   677,    26,    -1,
    1089,    -1,    18,    -1,    19,    -1,    21,    -1,    20,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   679,    -1,    -1,
     273,   429,   680,   681,   390,    -1,   568,   429,    26,     5,
      26,   390,    -1,   682,    -1,   681,     5,   682,    -1,   489,
      -1,   530,    -1,   536,    -1,   505,    -1,   408,    -1,   604,
      -1,   527,    -1,   479,    -1,   415,    -1,   490,    -1,   344,
      -1,   531,    -1,   454,    -1,   331,    -1,   593,    -1,    98,
      -1,  1003,    -1,    -1,   684,    -1,    -1,   273,   429,   685,
     686,   390,    -1,   687,    -1,   686,     5,   687,    -1,   682,
      -1,   430,    -1,   602,    25,    -1,   202,   924,    -1,   328,
     924,    -1,   283,   924,    -1,   336,   924,    -1,   292,   924,
      -1,   258,   924,    -1,   533,   689,    -1,   868,   343,  1089,
      -1,    -1,   288,   429,  1477,   390,   343,   690,  1108,    -1,
     104,   429,   937,     5,    25,     5,    25,   390,    -1,   405,
     429,   929,   390,   343,  1089,    -1,  1226,    -1,   191,   429,
     887,   390,   343,  1089,    -1,    -1,    -1,  1089,   589,   937,
     429,   691,   705,   390,   692,   703,    -1,    -1,    -1,    -1,
     937,   429,   693,   705,   694,   390,   695,   703,    -1,    -1,
      -1,   473,  1424,   622,  1424,   429,   696,   705,   697,   390,
     703,    -1,    -1,    -1,   937,   520,   937,   429,   698,   705,
     699,   390,   703,    -1,    -1,    -1,    -1,   364,   708,   589,
     709,   457,   672,   425,   429,   700,   705,   701,   390,   702,
     704,    -1,    -1,   343,  1108,    -1,    -1,   343,  1108,    -1,
     162,    -1,    -1,   706,    -1,   707,    -1,   706,     5,   707,
      -1,   837,    -1,    25,    -1,   937,    -1,   937,    -1,   937,
     619,   937,    -1,    -1,   534,   844,   711,   714,   718,   715,
      -1,    -1,   534,   712,   713,   716,   715,    -1,   720,    -1,
     713,   720,    -1,   722,    -1,   714,   722,    -1,   359,    -1,
      -1,    -1,   338,   717,  1487,    -1,    -1,    -1,   338,   719,
    1487,    -1,    -1,   578,   844,   721,  1487,    -1,    -1,   578,
     844,   723,  1487,    -1,   277,   934,    -1,   201,   932,    -1,
      83,   932,    -1,   168,    -1,   184,  1430,    -1,   493,   931,
      -1,    30,   726,    31,    -1,   727,    -1,   729,    -1,   728,
      -1,   727,   728,    -1,    29,    -1,   730,    -1,   729,   730,
      -1,    28,    -1,   392,    -1,    -1,    -1,   319,   733,   735,
     734,   736,    -1,   383,  1089,   624,   737,   977,  1002,   678,
      -1,  1089,   624,   737,   977,   546,  1477,  1002,   678,    -1,
      -1,   739,   190,    -1,   738,    -1,   737,     5,   738,    -1,
     937,    -1,   937,   619,   937,    -1,   937,   619,    21,    -1,
     740,    -1,   739,   740,    -1,    -1,   269,   746,   741,  1487,
      -1,    -1,   272,   747,   742,  1487,    -1,    -1,  1005,   743,
    1487,    -1,    -1,   166,   744,  1487,    -1,    -1,   163,   745,
    1487,    -1,   941,    -1,   746,     5,   941,    -1,   941,    -1,
     747,     5,   941,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   429,   837,   750,   390,
      -1,    -1,     5,   791,   625,   794,    -1,   155,    -1,   278,
      -1,    -1,   753,    -1,   754,    -1,   753,   754,    -1,    -1,
      -1,   436,   755,   757,   756,  1195,    -1,   804,    -1,  1467,
      -1,   760,    -1,   757,     5,   760,    -1,    -1,   759,   937,
      -1,   352,   758,   803,    25,    -1,   352,   758,   803,   937,
      -1,   352,   758,   803,   943,    -1,   352,   758,   803,    26,
      -1,   764,   780,    -1,    -1,   758,   352,   761,   762,    -1,
      26,    -1,    25,    -1,   943,    -1,    19,    26,    -1,   758,
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
      -1,   501,    -1,   298,    -1,   537,    -1,   532,    -1,    79,
      -1,    80,    -1,   574,    -1,   356,   789,    -1,   368,   790,
      -1,   786,    -1,    32,    -1,   556,   787,   619,   788,    -1,
     758,    -1,   758,    -1,    -1,   791,   625,   794,    -1,   799,
     625,   802,    -1,    -1,   792,   793,    -1,   581,    -1,   512,
      -1,   590,    -1,   552,    -1,   452,    -1,   469,    -1,   365,
     796,    -1,    -1,   795,   793,    -1,    -1,   429,   798,   390,
      -1,    -1,   429,    26,   390,    -1,    26,    -1,    -1,   800,
     801,   797,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   452,    -1,   469,    -1,   365,   796,    -1,   801,    -1,
      -1,    14,    -1,    -1,   235,   937,   805,   616,   806,    -1,
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
     259,   813,   937,   619,    21,    -1,   815,    -1,   814,     5,
     815,    -1,   816,   806,    -1,   817,    -1,   816,     5,   817,
      -1,   937,    -1,    -1,   617,   928,    -1,    70,   937,    -1,
      68,    -1,   625,  1477,    -1,   625,   508,   937,   658,  1477,
      -1,   625,   508,   937,   388,    -1,    72,   937,    -1,   156,
     862,  1108,   826,    -1,   399,   862,   842,   818,   826,    -1,
     208,   934,   826,    -1,    -1,    -1,   187,   823,  1115,   625,
     937,   619,    21,   825,   678,   824,   827,    -1,    -1,   467,
     929,    -1,   678,    -1,    -1,   828,   237,    -1,   829,    -1,
     828,   829,    -1,    -1,   350,   830,  1487,    -1,    -1,   346,
     831,  1487,    -1,    -1,  1005,   832,  1487,    -1,   497,   862,
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
    1404,   390,    -1,   293,   429,  1404,   390,    -1,   845,   943,
      -1,   845,    26,    -1,    25,    -1,   943,    -1,    26,    -1,
     850,    -1,  1089,    -1,  1089,   419,  1089,    -1,   849,    -1,
     432,   837,    -1,   391,   837,    -1,  1198,    -1,    -1,   506,
     852,  1198,    -1,     7,   837,    -1,     6,   837,    -1,   837,
      -1,   854,     5,   837,    -1,   622,   429,  1404,   390,    -1,
     427,   429,  1404,   390,    -1,   622,   429,   862,   854,   390,
      -1,   427,   429,   862,   854,   390,    -1,   385,    -1,   248,
      -1,    10,   837,    -1,   251,   837,    -1,    10,   837,   440,
      25,    -1,   251,   837,   440,    25,    -1,   556,   837,    -1,
     370,   837,    -1,   556,   837,   440,    25,    -1,   370,   837,
     440,    25,    -1,   389,    -1,     8,   837,    -1,    18,   837,
      -1,    19,   837,    -1,    21,   837,    -1,    20,   837,    -1,
      22,   837,    -1,    11,   837,    -1,    14,   837,    -1,   455,
     837,    -1,    12,   837,    -1,    13,   837,    -1,    17,   837,
      -1,    16,   837,    -1,    15,   837,    -1,    -1,    -1,    -1,
     937,   429,   864,   705,   865,   390,    -1,    -1,    -1,   937,
     520,   937,   429,   866,   705,   867,   390,    -1,    -1,    -1,
     537,   429,   869,   837,   870,   390,    -1,    -1,    -1,   512,
     429,   871,   837,   872,   390,    -1,    -1,    -1,   590,   429,
     873,   837,   874,   390,    -1,    -1,    -1,   581,   429,   875,
     837,   876,   390,    -1,   368,   429,   883,   390,   878,    -1,
     356,   429,    25,   390,   877,    -1,   356,   429,    26,   390,
     877,    -1,   356,   429,    26,   589,    26,   390,   877,    -1,
      -1,  1384,   625,  1385,    -1,   790,    -1,   868,    -1,   288,
     429,  1477,   390,    -1,    99,   429,   929,   390,    -1,    71,
     429,   929,   390,    -1,   405,   429,  1477,   390,    -1,   191,
     429,  1477,   390,    -1,    59,   429,  1477,   390,    -1,   881,
      -1,   863,    -1,  1380,    -1,   537,    -1,   421,   429,   837,
     390,    -1,   321,   429,   837,   390,    -1,   487,   837,    -1,
     442,   749,    -1,   837,   108,    -1,   837,   109,    -1,   837,
     110,    -1,    25,    -1,   884,    -1,    19,   884,    -1,   886,
      -1,   885,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     589,    26,    -1,    26,    26,   589,    26,   589,    26,    -1,
      26,    26,   589,    26,   589,    24,    -1,    26,   589,    26,
      -1,    26,   589,    26,   589,    26,    -1,    26,   589,    26,
     589,    24,    -1,    26,   589,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   929,    -1,   887,     5,   929,
      -1,    -1,    -1,   595,  1089,    14,   844,   625,   844,   891,
     889,  1487,   890,   240,    -1,    -1,   571,   844,    -1,    -1,
      -1,    -1,   402,   893,   931,   894,   896,  1285,   895,  1487,
     239,    -1,    -1,     8,   862,   842,    -1,    -1,    -1,   637,
     937,   898,   752,   899,  1034,   901,   900,   906,   638,    -1,
      -1,   911,    -1,    -1,   902,    -1,   903,    -1,   902,   903,
      -1,    -1,   639,   904,  1487,    -1,    -1,   640,   905,  1487,
      -1,    -1,   907,    -1,   908,    -1,   907,   908,    -1,    -1,
     641,   909,  1487,    -1,    -1,   642,   910,  1487,    -1,   912,
     916,   323,    -1,    91,    -1,    91,   913,   546,   914,    -1,
      91,   383,   915,    -1,  1089,    -1,   913,     5,  1089,    -1,
     937,    -1,   914,     5,   937,    -1,  1089,    -1,   915,     5,
    1089,    -1,   917,    -1,   916,   917,    -1,    -1,   643,   918,
    1487,    -1,    -1,   644,   919,  1487,    -1,    -1,   663,   914,
     920,  1487,    -1,    -1,   480,   914,   921,  1487,    -1,    -1,
     624,   914,   922,  1487,    -1,   545,   930,    -1,   554,    19,
      26,    -1,   554,    -1,   500,    18,    26,    -1,   500,    -1,
      26,    -1,  1089,    -1,    25,    -1,   942,    -1,   844,    -1,
     926,     5,   926,    -1,   927,    -1,   937,    -1,   666,   429,
     937,   390,    -1,   937,   619,   666,   429,   937,   390,    -1,
     937,   457,   675,   425,    -1,   937,   619,    21,    -1,   937,
     457,   675,   425,   619,    21,    -1,   937,   619,   937,    -1,
     937,   457,   675,   425,   619,   937,    -1,   938,    -1,   938,
      -1,   938,    -1,   938,    -1,   938,    -1,   938,    -1,    -1,
     550,    26,    -1,  1486,    -1,   939,    -1,  1486,    -1,   348,
     429,   940,   390,    -1,  1092,    -1,    25,    -1,   937,    -1,
     937,   457,   675,   425,    -1,   937,   619,    21,    -1,   937,
     457,   675,   425,   619,    21,    -1,   937,   619,   937,    -1,
     937,   457,   675,   425,   619,   937,    -1,  1089,    -1,    24,
      -1,   619,    26,    -1,   547,  1469,    -1,   651,   946,    -1,
     947,    -1,   946,     5,   947,    -1,   937,    -1,   662,   946,
      -1,   653,   946,    -1,   654,  1477,    -1,   652,   934,   658,
    1477,    -1,   656,   946,    -1,   657,  1477,    -1,   655,   934,
     658,  1477,    -1,    -1,   660,   952,   842,   957,   959,   961,
     953,   955,    -1,    -1,   954,    -1,   648,    -1,   649,    -1,
      -1,   956,    -1,   343,  1089,    -1,    -1,   958,    -1,   388,
     842,    -1,    -1,   960,    -1,   659,    26,    -1,    -1,   962,
      -1,   650,    26,   963,    -1,    -1,   398,    26,    -1,    -1,
     621,   844,   575,   965,  1487,   966,   439,    -1,    -1,    -1,
     542,   967,  1487,    -1,    -1,    -1,    62,   968,   844,   575,
     969,  1487,   966,    -1,   106,   937,   429,    26,   390,    -1,
      55,   937,    -1,    75,   937,    -1,    -1,   289,  1120,   973,
     625,   482,    -1,   289,  1120,   556,   974,    -1,   975,    -1,
     974,     5,   975,    -1,   787,   619,  1376,    -1,   787,   619,
      21,    -1,    -1,   978,   323,    -1,    -1,   150,    -1,   979,
      -1,   978,   979,    -1,    -1,   269,   991,   980,  1487,    -1,
      -1,   272,   992,   981,  1487,    -1,    -1,   350,   982,  1487,
      -1,    -1,   346,   983,  1487,    -1,    -1,  1005,   984,  1487,
      -1,    -1,   304,   985,  1487,    -1,    -1,   274,   986,  1487,
      -1,    -1,    36,   987,  1487,    -1,    -1,    34,   988,  1487,
      -1,    -1,    38,   989,  1487,    -1,    -1,    37,   990,  1487,
      -1,   929,    -1,   991,     5,   929,    -1,   929,    -1,   992,
       5,   929,    -1,   313,   995,    -1,   314,   937,   658,   995,
      -1,   561,    -1,   373,    -1,   929,    -1,    -1,   664,   998,
     997,   976,    -1,   383,  1108,   977,   936,   678,    -1,  1108,
     977,   546,  1477,   936,   678,    -1,    -1,   486,  1115,   977,
     546,   937,   619,    21,   936,   999,   678,    -1,   468,  1477,
    1001,    -1,    81,    26,    -1,    82,    26,    -1,   626,    -1,
     539,    -1,    -1,   550,    26,    -1,  1004,    -1,    43,    25,
      -1,   495,    14,    26,    -1,   495,    14,  1089,    -1,    44,
      14,    26,    -1,    44,    14,  1089,    -1,    40,    -1,    42,
      -1,    39,    -1,    41,    -1,    -1,   428,  1006,  1011,    -1,
     294,    -1,    -1,   596,  1008,  1011,    -1,   302,  1013,    -1,
     596,  1011,    -1,  1013,    -1,   429,  1012,   390,    -1,  1013,
      -1,  1012,     5,  1013,    -1,  1014,    -1,   594,    -1,   311,
      -1,   329,    -1,   303,    -1,   484,    -1,   440,    -1,   626,
      -1,   550,    -1,   539,    -1,   464,    -1,   437,    -1,   540,
      -1,   555,    -1,   519,    -1,   309,    -1,   310,    -1,    25,
      -1,   509,    -1,    -1,    -1,   598,  1017,  1113,  1018,    14,
     862,  1019,    -1,   482,    -1,   843,    -1,   218,  1089,    -1,
     207,  1089,    -1,   221,  1089,    -1,   449,  1089,   332,    -1,
     449,  1089,   384,   925,    -1,    -1,  1026,  1025,  1029,    -1,
      -1,  1027,    -1,  1028,    -1,  1027,  1028,    -1,   971,    -1,
    1033,    -1,  1049,    -1,  1035,    -1,    -1,  1030,    -1,  1032,
      -1,  1030,  1032,    -1,    66,   937,    -1,  1037,    -1,  1043,
      -1,  1055,    -1,  1208,    -1,  1218,    -1,  1076,    -1,  1467,
      -1,   897,    -1,   725,    -1,   970,    -1,   731,    -1,   725,
      -1,  1467,    -1,    -1,   725,    -1,  1467,    -1,   753,    -1,
     366,    -1,    60,    -1,    -1,    -1,    -1,    -1,  1036,  1038,
     937,   429,  1039,  1106,   390,  1040,   752,  1041,  1034,  1487,
    1042,    -1,   209,    -1,    -1,    -1,   557,  1044,   752,  1045,
    1487,   360,    -1,   464,   839,    -1,   862,    -1,   862,   842,
      -1,   355,  1388,    -1,  1050,    -1,  1051,    -1,  1050,  1051,
      -1,  1052,    -1,  1033,    -1,  1048,    -1,    -1,   404,  1053,
    1054,    -1,   752,   241,    -1,   925,    -1,    -1,    -1,    -1,
     113,   937,   112,   937,   429,  1056,  1106,   390,  1057,   752,
    1058,  1034,  1487,  1042,    -1,    -1,   558,  1060,  1075,  1066,
    1061,    -1,   361,    -1,    -1,   233,  1063,  1487,    -1,    -1,
      23,  1067,  1068,  1069,   936,  1064,  1487,    -1,    -1,    23,
    1067,   936,  1065,  1487,    -1,  1062,    -1,  1066,  1062,    -1,
      -1,  1007,    -1,    25,    -1,  1089,    -1,    -1,  1089,    -1,
      25,    -1,   250,  1073,    -1,   262,  1074,    -1,   245,  1074,
      -1,   585,    -1,    25,    -1,  1089,    -1,  1073,    -1,  1074,
       5,  1073,    -1,  1089,    -1,    25,    -1,    -1,    -1,   645,
     937,  1077,   752,  1078,  1079,   646,    -1,  1080,    -1,  1079,
    1080,    -1,    -1,   647,  1081,  1487,    -1,    -1,   624,   937,
    1082,  1487,    -1,  1086,  1084,    -1,    -1,   679,  1087,    -1,
    1088,    -1,  1085,    -1,   958,    -1,   960,    -1,   962,    -1,
     954,    -1,   956,    -1,   369,   862,   842,    -1,    -1,    65,
      -1,    65,    -1,  1090,    -1,  1092,    -1,   189,  1092,    -1,
    1092,   619,    -1,  1091,  1096,    -1,  1091,   937,   457,  1100,
     425,    -1,  1091,   937,   457,  1100,   425,   457,  1100,   425,
      -1,  1097,    -1,   937,    -1,  1093,    -1,   937,   456,  1095,
     424,    -1,   937,   456,  1095,   424,    -1,  1089,    -1,    25,
      -1,    21,    -1,   937,    -1,   937,  1099,    -1,   937,  1099,
      -1,   457,  1100,   425,    -1,   457,  1100,   425,   457,  1100,
     425,    -1,  1101,    -1,  1100,     5,  1101,    -1,   675,    -1,
    1103,    -1,  1105,    -1,  1103,   619,  1104,    -1,  1103,   619,
     937,   457,  1100,   425,    -1,  1103,   619,   937,   457,  1100,
     425,   457,  1100,   425,    -1,   937,    -1,  1094,    -1,    21,
      -1,   937,    -1,   937,  1099,    -1,    -1,  1107,    -1,  1109,
      -1,  1107,     5,  1109,    -1,  1110,    -1,  1108,     5,  1110,
      -1,   937,    -1,   937,   619,   937,    -1,  1089,    -1,  1089,
     419,  1089,    -1,    25,    -1,   943,    -1,    26,    -1,  1112,
      -1,  1111,     5,  1112,    -1,  1089,    -1,  1089,   419,  1089,
      -1,  1114,    -1,  1113,     5,  1114,    -1,  1102,    -1,  1089,
      -1,  1117,    -1,  1116,     5,  1117,    -1,  1089,  1118,    -1,
      -1,   587,    -1,   538,    -1,   937,   457,  1100,   425,    -1,
    1121,    -1,  1120,     5,  1121,    -1,  1089,    -1,  1089,   419,
    1089,    -1,   253,   933,   617,   927,   579,  1479,   683,    -1,
      -1,   617,   429,   844,     5,   844,   390,  1124,    -1,    -1,
     568,   429,   844,     5,   844,   390,    -1,   254,   937,  1123,
      -1,   937,    -1,   337,   935,  1128,    -1,  1129,    -1,   546,
     844,    -1,  1130,  1131,  1136,     8,  1126,    -1,    -1,   617,
    1132,   429,   844,     5,   844,   390,    -1,    -1,   556,   938,
      -1,    -1,   349,    -1,   216,  1430,   265,  1462,  1135,    -1,
     563,   930,    -1,   563,   930,     8,   862,   842,    -1,    -1,
     616,   576,  1424,   372,  1424,    -1,   616,   576,  1424,     5,
     372,  1424,    -1,   616,  1424,     5,  1424,    -1,    -1,   648,
      -1,   649,    -1,    90,  1462,  1138,  1139,    -1,    -1,   616,
    1462,    -1,    -1,   616,   576,  1424,     8,  1424,    -1,   576,
    1424,     8,  1424,    -1,   410,  1141,    -1,  1142,    -1,  1141,
       5,  1142,    -1,   202,   924,    -1,   283,   924,    -1,   328,
     924,    -1,   336,   924,    -1,   292,   924,    -1,   258,   924,
      -1,  1009,    -1,   437,  1010,    -1,   448,  1010,    -1,   561,
    1010,    -1,   373,  1010,    -1,   550,  1010,    -1,   548,   925,
      -1,   549,   925,    -1,   399,   679,    -1,   664,   679,    -1,
     290,    -1,   194,    -1,   151,    -1,   128,    -1,   146,    -1,
     137,    -1,  1429,   412,  1146,   546,  1144,    -1,  1089,    -1,
      25,    -1,   401,  1146,    -1,   401,  1146,     8,  1108,    -1,
     938,    -1,    -1,   460,  1155,   678,   595,  1150,  1089,   936,
     678,  1148,  1151,    -1,   460,  1155,   678,   343,  1089,    -1,
      -1,   535,    -1,    -1,  1152,   281,    -1,  1153,    -1,  1152,
    1153,    -1,    -1,  1005,  1154,  1487,    -1,   843,    -1,    -1,
     603,   930,  1157,  1158,    -1,    -1,   546,  1159,    -1,  1160,
      -1,  1159,     5,  1160,    -1,  1416,    -1,   482,    -1,   219,
    1163,    88,    -1,   219,  1163,   625,  1162,    -1,   219,  1163,
      87,  1162,    -1,   219,  1163,    -1,    25,    -1,   942,    -1,
     937,    -1,    -1,   478,    -1,   145,  1163,  1164,   429,   862,
    1047,   390,    -1,   192,  1163,    -1,    67,  1163,    -1,  1199,
    1207,    -1,   445,    61,    -1,   445,  1170,    -1,  1171,    -1,
    1170,  1171,    -1,    -1,   133,  1172,  1487,    -1,    -1,   198,
    1173,  1487,    -1,    -1,   227,  1174,  1487,    -1,    -1,   215,
    1175,  1487,    -1,    -1,   252,  1176,  1487,    -1,    -1,   200,
    1089,  1177,  1487,    -1,    -1,   223,  1089,  1178,  1487,    -1,
    1189,    -1,  1191,    -1,  1190,    -1,  1180,    -1,  1216,    -1,
    1183,    -1,    -1,   560,   844,  1181,   481,    -1,    -1,   481,
      -1,    -1,   569,   844,  1184,  1182,    -1,   158,    -1,   628,
    1203,    -1,   161,  1203,    -1,   160,  1203,    -1,    -1,  1186,
      -1,  1187,    -1,  1186,  1187,    -1,  1196,  1188,    -1,    -1,
     617,  1203,    -1,   518,  1185,  1195,    -1,   517,  1424,  1195,
      -1,   516,  1194,  1193,  1192,  1195,    -1,    -1,   152,   837,
      -1,   152,   837,     5,   837,    -1,   612,    -1,   613,    -1,
     614,    -1,   615,    -1,  1089,    -1,    -1,   521,    -1,  1197,
      -1,  1196,     5,  1197,    -1,   844,  1230,    -1,   608,   429,
     837,   390,  1215,    -1,    64,  1215,    -1,   495,   429,    21,
     390,  1215,    -1,   411,   429,    21,   390,  1215,    -1,   386,
     429,   837,   390,  1215,    -1,   588,   429,   837,   390,  1215,
      -1,   601,   429,   837,   390,  1215,    -1,   600,   429,   837,
     390,  1215,    -1,    -1,   459,  1200,    -1,  1201,    -1,  1200,
    1201,    -1,   226,    26,    -1,   217,    26,    -1,   300,    26,
      -1,   183,    26,    -1,   255,    26,    -1,   175,    -1,   342,
      25,    -1,   342,  1089,    -1,   176,    25,    -1,   159,    25,
      -1,  1206,    -1,  1202,  1206,    -1,  1204,   108,    -1,  1204,
     110,    -1,  1204,   109,    -1,  1204,    -1,   943,    -1,    26,
      -1,    -1,   459,  1202,    -1,   226,  1203,    -1,   217,  1203,
      -1,   300,  1203,    -1,   183,  1203,    -1,   255,  1203,    -1,
     256,  1203,    -1,   627,    25,    -1,   628,  1203,    -1,   632,
      -1,   629,    -1,   630,    -1,   631,    -1,   636,    -1,   633,
      -1,   634,    -1,   635,    -1,    76,  1203,    -1,    77,  1203,
      -1,    78,  1203,    -1,   342,    25,    -1,   176,    25,    -1,
     398,    -1,    73,    -1,    74,    -1,    -1,   513,   618,  1116,
      -1,   134,  1116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     463,  1209,   937,   429,  1210,  1106,   390,  1211,   752,  1212,
    1168,  1213,  1169,  1214,   238,    -1,    -1,   525,   837,    -1,
     515,  1217,    -1,    -1,  1144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,  1219,   937,   429,  1220,  1106,   390,  1221,
     752,  1222,  1225,  1223,  1169,  1224,   238,    -1,  1205,  1207,
      -1,    -1,    -1,    -1,   154,   429,    25,     5,  1227,   705,
    1228,   390,  1229,   703,    -1,    -1,   382,    -1,   382,   217,
      26,    -1,   382,   217,  1089,    -1,   606,   844,    -1,   606,
     844,   343,  1089,    -1,   606,   844,   162,    -1,   606,   844,
     577,    -1,   606,   844,   544,    -1,  1233,    -1,   172,    -1,
     322,    -1,   280,    -1,  1240,    -1,  1235,    -1,    -1,    -1,
     205,  1236,  1373,   429,  1237,  1244,   390,    -1,    -1,    -1,
     131,  1238,  1373,   429,  1239,  1244,   390,  1241,    -1,   103,
    1242,   390,    -1,    54,   938,    -1,    -1,   267,    -1,  1243,
      -1,  1242,     5,  1243,    -1,   937,   587,    -1,   937,   538,
      -1,   937,    -1,  1245,    -1,  1244,     5,  1245,    -1,  1326,
      -1,  1324,    -1,   120,   937,    -1,   178,    -1,    45,   937,
    1248,    -1,  1249,    -1,  1248,     5,  1249,    -1,  1250,    -1,
    1253,    -1,  1256,    -1,  1261,    -1,  1262,    -1,  1260,    -1,
    1259,    -1,   584,  1251,    -1,   584,   429,  1252,   390,    -1,
    1245,    -1,  1245,   663,   937,    -1,  1251,    -1,  1252,     5,
    1251,    -1,   541,  1255,    -1,   541,   429,  1254,   390,    -1,
    1255,    -1,  1254,     5,  1255,    -1,   937,    -1,   453,  1258,
      -1,   453,   429,  1257,   390,    -1,  1258,    -1,  1257,     5,
    1258,    -1,  1245,    -1,    85,    -1,    86,    -1,    84,    26,
      -1,    56,  1330,    -1,    56,   429,  1263,   390,    -1,    57,
    1264,    -1,    57,   429,  1263,   390,    -1,  1330,    -1,  1263,
       5,  1330,    -1,   937,    -1,   264,    -1,   230,    -1,   164,
    1267,    -1,   141,    -1,   129,    -1,   119,    -1,   117,    -1,
     121,    -1,   177,  1430,    -1,   229,  1266,   458,  1424,   625,
    1424,    -1,   297,   930,   458,  1424,   625,  1424,    -1,    -1,
    1430,    -1,    -1,   844,    -1,   522,   844,    -1,   228,    -1,
      -1,   247,  1271,  1373,  1274,  1272,    -1,    -1,   478,  1273,
     429,  1276,   390,    -1,  1410,    -1,    -1,   429,  1275,   390,
      -1,  1376,    -1,  1275,     5,  1376,    -1,  1277,    -1,  1276,
       5,  1277,    -1,  1416,    -1,   482,    -1,    -1,    -1,   499,
    1279,  1282,  1280,  1283,    -1,   938,    -1,  1287,   931,    -1,
     931,    -1,    -1,    -1,   553,  1284,  1111,    -1,    -1,    -1,
     553,  1286,  1111,    -1,   500,    -1,   554,    -1,   561,    -1,
     373,    -1,   340,    -1,   394,    -1,   376,   844,    -1,   349,
     844,    -1,   236,  1373,   149,   931,    -1,   236,  1373,  1346,
      -1,   513,   618,  1291,    -1,  1292,    -1,  1291,     5,  1292,
      -1,  1293,  1294,    -1,    26,    -1,  1376,    -1,    -1,   587,
      -1,   538,    -1,   275,    -1,   308,    -1,    -1,   325,    -1,
     355,  1299,  1297,    -1,  1462,    -1,    25,    -1,    -1,  1429,
    1301,  1302,    -1,  1331,    -1,  1335,    -1,  1296,    -1,  1431,
      -1,  1295,    -1,  1288,    -1,  1289,    -1,  1278,    -1,  1270,
      -1,  1269,    -1,  1400,    -1,  1446,    -1,   504,  1305,   624,
    1373,   625,  1310,  1304,    -1,    -1,   140,    -1,   167,    -1,
    1306,    -1,  1307,    -1,  1306,     5,  1307,    -1,   470,    -1,
     448,    -1,   437,    -1,   477,  1308,    -1,    -1,   429,  1309,
     390,    -1,  1376,    -1,  1309,     5,  1376,    -1,  1311,    -1,
    1310,     5,  1311,    -1,   461,    -1,  1374,    -1,   234,  1373,
    1313,   616,  1410,  1315,    -1,    -1,   429,  1314,   390,    -1,
    1376,    -1,  1314,     5,  1376,    -1,    -1,   139,    -1,   491,
     429,  1349,   390,    -1,   244,   429,  1319,   390,  1318,    -1,
     295,  1320,    -1,  1321,    -1,  1373,    -1,  1373,   429,  1321,
     390,    -1,  1376,    -1,  1321,     5,  1376,    -1,   475,   429,
    1323,   390,    -1,   257,   429,  1323,   390,    -1,  1376,    -1,
    1323,     5,  1376,    -1,  1322,    -1,  1317,    -1,  1316,    -1,
     398,  1379,    -1,   206,    -1,   937,  1365,  1327,  1328,    -1,
      -1,  1325,    -1,    -1,  1329,    -1,  1330,    -1,  1329,  1330,
      -1,   371,    -1,   157,    -1,   475,    -1,  1318,    -1,   491,
     429,  1349,   390,    -1,   118,  1332,  1334,    -1,  1333,    -1,
    1374,    -1,  1335,    -1,  1334,  1335,    -1,  1312,    -1,  1303,
      -1,   446,  1349,    -1,   367,  1338,    -1,  1415,    -1,  1338,
       5,  1415,    -1,   525,  1349,    -1,   546,  1341,    -1,  1342,
      -1,  1341,     5,  1342,    -1,  1343,    -1,   514,  1343,    -1,
     514,   429,  1344,   390,    -1,  1373,    -1,  1373,  1378,    -1,
    1342,    -1,  1344,     5,  1342,    -1,  1340,  1346,  1347,  1348,
      -1,    -1,  1339,    -1,    -1,  1337,    -1,    -1,  1336,    -1,
    1350,    -1,  1349,     6,  1350,    -1,  1351,    -1,  1350,     7,
    1351,    -1,  1352,    -1,     9,  1352,    -1,  1363,    -1,   429,
    1349,   390,    -1,   441,  1411,    -1,   293,  1411,    -1,    -1,
     440,  1356,    -1,  1417,    -1,  1420,    -1,  1416,   622,   429,
    1358,   390,    -1,  1416,   622,  1411,    -1,  1416,   427,   429,
    1358,   390,    -1,  1416,   427,  1411,    -1,  1359,    -1,  1358,
       5,  1359,    -1,  1466,    -1,  1379,    -1,    -1,     9,    -1,
    1416,  1360,   385,    -1,  1416,  1360,   248,    -1,  1416,  1362,
    1416,    -1,  1416,  1360,   387,  1416,     7,  1416,    -1,  1416,
     556,  1355,  1354,    -1,  1416,   370,  1355,  1354,    -1,  1416,
    1360,    10,  1355,  1354,    -1,    14,    -1,    17,    -1,    12,
      -1,    13,    -1,   251,    -1,    10,    -1,    16,    -1,    15,
      -1,  1361,    -1,  1357,    -1,  1353,    -1,    -1,   585,    -1,
     358,    -1,   475,    -1,  1366,    -1,  1367,    -1,  1369,    -1,
     535,    -1,   535,   429,  1370,   390,    -1,   409,   429,  1371,
    1368,   390,    -1,   471,    -1,   396,   429,  1371,  1368,   390,
      -1,   511,   429,  1371,  1368,   390,    -1,   537,    -1,   406,
      -1,   378,    -1,   356,  1386,   625,  1387,    -1,   356,    -1,
     368,  1386,   625,  1387,    -1,   368,    -1,   368,  1386,   429,
      26,   390,   625,  1387,    -1,   574,    -1,   532,    -1,   422,
      -1,   422,   429,    26,   390,    -1,   422,   429,    26,     5,
      26,   390,    -1,    -1,     5,  1372,    -1,   501,   429,  1371,
     390,    -1,   565,    -1,   298,    -1,   501,    -1,    63,    -1,
      26,    -1,    26,    -1,    26,    -1,    25,   619,   937,    -1,
      25,    -1,   937,    -1,   937,   589,   937,    -1,   937,    -1,
      -1,   457,    26,   425,    -1,   457,    26,     5,    26,   425,
      -1,  1377,    -1,   611,  1377,    -1,   937,  1375,    -1,  1373,
     619,   937,  1375,    -1,  1373,   619,    21,    -1,   937,    -1,
      25,    -1,   409,    -1,   943,    -1,    26,    -1,  1381,    -1,
     394,  1383,    -1,   394,  1382,    -1,    -1,  1386,   625,  1387,
      -1,    -1,  1384,   625,  1384,    -1,   581,    -1,   512,    -1,
     590,    -1,   552,    -1,   452,    -1,   469,    -1,   365,    -1,
     365,   429,    26,   390,    -1,   581,    -1,   512,    -1,   590,
      -1,   552,    -1,   452,    -1,   469,    -1,   365,    -1,   365,
     429,    26,   390,    -1,   581,    -1,   512,    -1,   590,    -1,
     552,    -1,   452,    -1,   469,    -1,   365,    -1,   581,    -1,
     512,    -1,   590,    -1,   552,    -1,   452,    -1,   469,    -1,
     365,    -1,   937,    -1,    25,    -1,  1429,   502,   931,    -1,
      -1,  1429,   397,  1281,   435,   595,  1398,  1391,  1395,    -1,
      -1,  1429,   397,  1281,   435,   100,   595,  1399,  1392,  1395,
      -1,    -1,  1429,   397,  1281,   135,  1399,  1393,  1395,    -1,
      -1,  1429,   397,  1281,   136,   100,   595,  1399,  1394,  1395,
      -1,    -1,   287,    -1,   286,  1396,    -1,  1397,    -1,  1396,
       5,  1397,    -1,   937,    -1,   937,   619,   937,    -1,    25,
     619,   937,   619,   937,    -1,  1399,    -1,  1270,    -1,  1146,
      -1,  1401,    -1,  1401,  1395,    -1,    -1,    -1,   470,  1412,
    1402,  1413,  1403,  1409,  1345,  1407,    -1,   470,  1412,  1413,
    1345,  1407,    -1,  1406,    -1,  1424,    -1,   470,  1412,  1413,
    1409,  1345,  1407,    -1,    -1,   524,  1364,  1405,    -1,  1290,
      -1,   330,  1408,  1241,    -1,  1290,   330,  1408,  1241,    -1,
     937,    -1,    -1,   553,  1111,    -1,   470,  1412,  1413,  1345,
      -1,   429,   470,  1412,  1413,  1345,   390,    -1,    -1,   585,
      -1,   358,    -1,   475,    -1,  1414,    -1,  1413,     5,  1414,
      -1,  1416,    -1,  1416,   937,    -1,  1416,    -1,  1417,    -1,
      19,  1417,    -1,    18,  1417,    -1,  1418,    -1,  1466,    -1,
    1411,    -1,   611,   937,    -1,   611,   937,   619,   937,    -1,
    1417,    20,  1416,    -1,  1417,  1438,    -1,  1417,    21,  1416,
      -1,  1417,    18,  1416,    -1,  1417,    19,  1416,    -1,  1379,
      -1,   483,    -1,   426,    -1,   576,    -1,    21,    -1,    64,
      -1,   588,   429,  1364,  1416,   390,    -1,   600,   429,  1364,
    1416,   390,    -1,   601,   429,  1364,  1416,   390,    -1,   608,
     429,  1364,  1416,   390,    -1,   495,   429,  1364,  1416,   390,
      -1,   937,   429,  1419,   390,    -1,   537,   429,  1419,   390,
      -1,   429,  1416,   390,    -1,   442,   429,  1439,   390,    -1,
    1416,    -1,  1419,     5,  1416,    -1,  1379,    -1,  1429,   345,
    1428,  1423,  1405,    -1,  1429,   334,  1428,  1423,   247,  1373,
    1425,    -1,  1429,   334,  1428,  1423,  1089,    -1,    -1,   320,
    1424,    -1,    25,    -1,  1089,    -1,    -1,   429,  1426,   390,
      -1,  1427,    -1,  1426,     5,  1427,    -1,   937,    -1,    25,
      -1,  1089,    -1,    -1,   266,  1430,   595,    -1,   938,    -1,
    1436,    -1,  1435,    -1,  1432,    -1,   315,  1433,   625,  1433,
      -1,   296,  1433,   619,  1434,   625,  1434,    -1,   937,    -1,
     937,    -1,   220,   787,    -1,   291,   787,  1437,    -1,   270,
      -1,   174,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,   394,     5,  1386,   625,  1387,
      -1,  1466,     5,  1386,   625,  1387,    -1,   394,  1386,   625,
    1387,    -1,    -1,   607,  1441,  1442,   188,    -1,  1443,    -1,
    1442,  1443,    -1,    33,    -1,  1444,    -1,  1445,    -1,   189,
    1466,    -1,   553,  1111,    -1,    -1,    -1,   477,  1373,  1447,
    1450,  1448,  1449,    -1,    -1,   149,   931,    -1,   525,  1349,
      -1,    52,  1454,   390,    14,   429,  1455,   390,    -1,    48,
    1455,   390,    -1,    49,  1455,   390,    -1,   583,  1451,    -1,
      51,  1455,    -1,    50,  1455,    -1,  1453,    -1,  1451,     5,
    1453,    -1,  1376,    -1,  1452,    14,  1456,    -1,  1452,    -1,
    1454,     5,  1452,    -1,  1456,    -1,  1455,     5,  1456,    -1,
     482,    -1,  1457,    -1,  1458,    -1,    19,  1458,    -1,    18,
    1458,    -1,  1460,    -1,  1411,    -1,   611,   937,    -1,   611,
     937,   619,   937,    -1,  1459,    -1,  1379,    -1,   483,    -1,
     426,    -1,   576,    -1,    64,    -1,  1458,    20,  1457,    -1,
    1458,  1438,    -1,  1458,    21,  1457,    -1,  1458,    18,  1457,
      -1,  1458,    19,  1457,    -1,   588,   429,  1364,  1457,   390,
      -1,   600,   429,  1364,  1457,   390,    -1,   601,   429,  1364,
    1457,   390,    -1,   608,   429,  1364,  1457,   390,    -1,   495,
     429,  1364,  1457,   390,    -1,   937,   429,  1461,   390,    -1,
     537,   429,  1461,   390,    -1,   429,  1457,   390,    -1,   442,
     429,  1439,   390,    -1,  1466,    -1,  1457,    -1,  1461,     5,
    1457,    -1,  1463,    -1,   189,  1464,    -1,  1464,    -1,  1098,
      -1,   937,    -1,  1464,   619,  1465,    -1,    25,   619,  1464,
     619,  1465,    -1,    21,    -1,  1119,    -1,   937,    -1,  1463,
      -1,  1463,   419,  1463,    -1,   126,  1468,    -1,   130,  1468,
      -1,   125,  1468,    -1,    46,    -1,   165,  1468,    -1,   123,
    1468,    -1,    47,    -1,   148,  1468,    -1,   147,  1468,    -1,
     122,  1468,    -1,   354,    -1,   620,   625,  1469,    -1,   547,
    1469,    -1,   572,    -1,   533,  1470,    -1,   937,    -1,   589,
     937,    -1,   937,    -1,    -1,    -1,   526,  1472,   844,  1473,
    1487,   324,    -1,    -1,   658,  1477,    -1,    -1,   661,    -1,
     180,    -1,   276,   932,    -1,    69,   932,    -1,   306,    -1,
     305,    -1,   307,   934,  1474,  1475,    -1,   492,  1477,  1475,
      -1,   929,    -1,  1477,     5,   929,    -1,   102,    -1,   132,
     932,    -1,   844,   566,     5,   844,   391,    -1,   508,   844,
      -1,   263,   932,    -1,   101,  1482,     8,  1483,  1481,    -1,
      -1,   546,   844,    -1,   937,    -1,   937,    -1,   246,   932,
      -1,   249,   932,   625,   844,     5,   844,    -1,   249,   932,
     618,   844,     5,   844,    -1,    27,    -1,    -1,  1489,    -1,
    1490,  1195,    -1,  1488,    -1,  1489,  1488,    -1,    -1,  1491,
    1492,    -1,   668,    -1,   669,    -1,   670,    -1,   671,    -1,
     688,    -1,   710,    -1,   724,    -1,   725,    -1,   731,    -1,
     732,    -1,   751,    -1,   819,    -1,   820,    -1,   821,    -1,
     822,    -1,   833,    -1,   834,    -1,   835,    -1,   836,    -1,
     888,    -1,   892,    -1,   923,    -1,   944,    -1,   945,    -1,
     948,    -1,   949,    -1,   950,    -1,   951,    -1,   964,    -1,
     972,    -1,   993,    -1,   994,    -1,   996,    -1,  1000,    -1,
    1015,    -1,  1016,    -1,  1020,    -1,  1021,    -1,  1022,    -1,
    1023,    -1,  1031,    -1,  1046,    -1,  1059,    -1,  1070,    -1,
    1071,    -1,  1072,    -1,  1083,    -1,  1122,    -1,  1125,    -1,
    1127,    -1,  1133,    -1,  1134,    -1,  1137,    -1,  1140,    -1,
    1143,    -1,  1145,    -1,  1147,    -1,  1149,    -1,  1156,    -1,
    1161,    -1,  1165,    -1,  1166,    -1,  1167,    -1,  1179,    -1,
    1231,    -1,  1232,    -1,  1234,    -1,  1246,    -1,  1247,    -1,
    1265,    -1,  1268,    -1,  1298,    -1,  1300,    -1,  1389,    -1,
    1390,    -1,  1421,    -1,  1422,    -1,  1440,    -1,  1467,    -1,
    1471,    -1,  1476,    -1,  1478,    -1,  1480,    -1,  1484,    -1,
    1485,    -1
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
    1115,  1117,  1179,  1183,  1187,  1187,  1197,  1201,  1204,  1205,
    1212,  1218,  1212,  1231,  1236,  1240,  1231,  1252,  1256,  1252,
    1264,  1269,  1264,  1288,  1295,  1299,  1287,  1325,  1325,  1329,
    1330,  1331,  1336,  1339,  1344,  1348,  1356,  1359,  1359,  1365,
    1369,  1384,  1382,  1400,  1400,  1415,  1415,  1418,  1418,  1422,
    1425,  1425,  1425,  1432,  1433,  1432,  1440,  1440,  1451,  1451,
    1470,  1473,  1476,  1479,  1482,  1485,  1498,  1503,  1503,  1504,
    1504,  1507,  1512,  1512,  1516,  1526,  1540,  1544,  1539,  1554,
    1560,  1568,  1569,  1572,  1572,  1575,  1579,  1584,  1591,  1591,
    1595,  1595,  1602,  1602,  1607,  1607,  1612,  1612,  1617,  1617,
    1630,  1631,  1639,  1640,  1657,  1660,  1663,  1666,  1669,  1672,
    1678,  1689,  1694,  1707,  1711,  1726,  1727,  1731,  1731,  1735,
    1735,  1735,  1736,  1737,  1742,  1742,  1745,  1745,  1754,  1755,
    1756,  1759,  1763,  1764,  1764,  1781,  1781,  1781,  1781,  1785,
    1792,  1793,  1796,  1796,  1799,  1799,  1808,  1805,  1821,  1821,
    1823,  1823,  1825,  1827,  1829,  1831,  1834,  1838,  1838,  1839,
    1839,  1843,  1843,  1855,  1855,  1860,  1864,  1866,  1867,  1870,
    1870,  1870,  1874,  1875,  1876,  1877,  1884,  1885,  1886,  1887,
    1890,  1891,  1892,  1893,  1897,  1902,  1907,  1911,  1914,  1918,
    1919,  1920,  1921,  1922,  1923,  1924,  1925,  1928,  1929,  1930,
    1962,  1966,  1968,  1970,  1970,  1977,  1981,  1981,  1985,  1986,
    1987,  1988,  1989,  1990,  1991,  1997,  1997,  2000,  2002,  2008,
    2010,  2016,  2024,  2024,  2027,  2028,  2029,  2030,  2031,  2032,
    2033,  2039,  2042,  2042,  2055,  2055,  2062,  2063,  2064,  2066,
    2067,  2069,  2071,  2072,  2073,  2074,  2079,  2085,  2091,  2092,
    2094,  2096,  2097,  2098,  2099,  2100,  2101,  2104,  2105,  2112,
    2120,  2120,  2128,  2125,  2140,  2140,  2142,  2142,  2150,  2150,
    2153,  2156,  2157,  2162,  2174,  2178,  2181,  2184,  2185,  2186,
    2187,  2188,  2193,  2200,  2206,  2211,  2215,  2211,  2226,  2228,
    2233,  2238,  2238,  2242,  2242,  2245,  2245,  2251,  2251,  2257,
    2257,  2273,  2276,  2290,  2292,  2294,  2296,  2298,  2300,  2302,
    2308,  2310,  2314,  2316,  2318,  2320,  2322,  2324,  2326,  2332,
    2347,  2350,  2363,  2364,  2365,  2366,  2367,  2371,  2372,  2373,
    2377,  2382,  2389,  2390,  2391,  2392,  2393,  2394,  2395,  2396,
    2397,  2398,  2399,  2406,  2406,  2411,  2411,  2414,  2420,  2428,
    2434,  2444,  2445,  2453,  2460,  2464,  2474,  2478,  2483,  2488,
    2490,  2500,  2513,  2521,  2534,  2539,  2545,  2550,  2555,  2556,
    2562,  2633,  2639,  2644,  2652,  2652,  2667,  2671,  2678,  2681,
    2689,  2700,  2710,  2716,  2725,  2730,  2738,  2741,  2744,  2749,
    2756,  2761,  2766,  2771,  2781,  2789,  2797,  2802,  2806,  2811,
    2815,  2819,  2826,  2829,  2832,  2836,  2840,  2844,  2848,  2856,
    2866,  2871,  2864,  2887,  2892,  2887,  2909,  2909,  2909,  2912,
    2912,  2912,  2916,  2916,  2916,  2920,  2920,  2920,  2924,  2930,
    2936,  2942,  2952,  2952,  2956,  2960,  2961,  2972,  2973,  2979,
    2989,  2999,  3009,  3010,  3013,  3018,  3024,  3028,  3032,  3035,
    3041,  3044,  3047,  3064,  3067,  3073,  3074,  3075,  3079,  3080,
    3081,  3082,  3083,  3085,  3086,  3087,  3089,  3090,  3094,  3095,
    3100,  3101,  3113,  3117,  3112,  3125,  3128,  3142,  3146,  3152,
    3141,  3164,  3165,  3177,  3183,  3177,  3197,  3197,  3199,  3200,
    3204,  3204,  3208,  3208,  3213,  3213,  3220,  3221,  3225,  3225,
    3229,  3229,  3234,  3234,  3241,  3245,  3246,  3247,  3252,  3252,
    3255,  3255,  3259,  3259,  3263,  3263,  3267,  3267,  3272,  3272,
    3277,  3277,  3282,  3282,  3287,  3287,  3303,  3320,  3321,  3322,
    3323,  3324,  3325,  3328,  3328,  3331,  3333,  3336,  3339,  3341,
    3342,  3343,  3345,  3347,  3349,  3351,  3355,  3362,  3364,  3370,
    3375,  3380,  3385,  3385,  3388,  3394,  3399,  3402,  3409,  3409,
    3411,  3412,  3414,  3416,  3418,  3420,  3424,  3433,  3433,  3495,
    3507,  3514,  3514,  3518,  3523,  3529,  3533,  3537,  3543,  3547,
    3551,  3557,  3557,  3565,  3566,  3570,  3570,  3574,  3575,  3578,
    3581,  3581,  3584,  3586,  3586,  3589,  3591,  3591,  3592,  3594,
    3594,  3603,  3601,  3613,  3613,  3613,  3616,  3618,  3616,  3625,
    3628,  3634,  3645,  3645,  3649,  3655,  3655,  3659,  3660,  3671,
    3672,  3674,  3676,  3681,  3681,  3685,  3684,  3691,  3690,  3696,
    3696,  3701,  3701,  3707,  3707,  3712,  3712,  3717,  3717,  3722,
    3722,  3725,  3725,  3728,  3728,  3731,  3731,  3773,  3774,  3782,
    3783,  3792,  3797,  3802,  3803,  3804,  3808,  3807,  3818,  3823,
    3828,  3828,  3844,  3850,  3851,  3852,  3853,  3856,  3856,  3859,
    3866,  3867,  3868,  3869,  3870,  3871,  3872,  3873,  3874,  3879,
    3879,  3881,  3884,  3884,  3886,  3890,  3893,  3894,  3897,  3897,
    3902,  3905,  3906,  3907,  3908,  3909,  3910,  3911,  3912,  3913,
    3914,  3915,  3916,  3917,  3918,  3919,  3920,  3921,  3925,  3943,
    3943,  3943,  3970,  3981,  3988,  3994,  4000,  4006,  4017,  4040,
    4039,  4056,  4056,  4060,  4061,  4069,  4070,  4071,  4072,  4079,
    4080,  4082,  4083,  4087,  4092,  4093,  4094,  4095,  4096,  4097,
    4098,  4099,  4100,  4101,  4102,  4105,  4105,  4107,  4107,  4107,
    4109,  4113,  4113,  4122,  4127,  4143,  4149,  4121,  4163,  4177,
    4187,  4176,  4200,  4207,  4207,  4212,  4217,  4222,  4223,  4226,
    4226,  4226,  4229,  4229,  4237,  4243,  4257,  4261,  4274,  4256,
    4292,  4292,  4306,  4317,  4316,  4328,  4324,  4341,  4338,  4351,
    4351,  4353,  4354,  4356,  4357,  4360,  4361,  4362,  4364,  4369,
    4374,  4380,  4382,  4383,  4386,  4387,  4390,  4392,  4401,  4407,
    4401,  4418,  4419,  4423,  4423,  4433,  4433,  4445,  4448,  4451,
    4454,  4458,  4462,  4463,  4464,  4465,  4466,  4470,  4475,  4475,
    4478,  4504,  4563,  4563,  4566,  4570,  4574,  4617,  4659,  4660,
    4661,  4664,  4678,  4690,  4690,  4695,  4696,  4702,  4762,  4819,
    4824,  4831,  4836,  4844,  4850,  4884,  4887,  4888,  4929,  4972,
    4973,  4977,  4978,  4982,  5035,  5039,  5042,  5048,  5059,  5066,
    5074,  5074,  5077,  5078,  5079,  5080,  5081,  5084,  5087,  5093,
    5096,  5100,  5104,  5111,  5116,  5123,  5126,  5132,  5134,  5134,
    5134,  5138,  5158,  5165,  5172,  5175,  5189,  5196,  5197,  5200,
    5201,  5205,  5211,  5216,  5222,  5223,  5228,  5232,  5232,  5236,
    5237,  5240,  5241,  5245,  5253,  5256,  5262,  5263,  5265,  5267,
    5271,  5271,  5272,  5277,  5285,  5286,  5291,  5292,  5294,  5307,
    5309,  5310,  5312,  5315,  5318,  5321,  5325,  5328,  5331,  5335,
    5339,  5343,  5346,  5350,  5353,  5354,  5355,  5358,  5361,  5364,
    5367,  5370,  5373,  5376,  5392,  5400,  5400,  5402,  5409,  5416,
    5431,  5429,  5449,  5454,  5455,  5459,  5460,  5462,  5463,  5465,
    5465,  5473,  5482,  5482,  5492,  5493,  5496,  5497,  5500,  5504,
    5518,  5523,  5528,  5533,  5543,  5543,  5547,  5550,  5550,  5552,
    5562,  5571,  5578,  5580,  5584,  5587,  5587,  5591,  5590,  5594,
    5593,  5597,  5596,  5600,  5599,  5603,  5602,  5605,  5605,  5621,
    5620,  5642,  5643,  5644,  5645,  5646,  5647,  5650,  5650,  5656,
    5656,  5659,  5659,  5669,  5670,  5671,  5678,  5690,  5691,  5694,
    5695,  5698,  5701,  5701,  5706,  5710,  5715,  5721,  5722,  5723,
    5727,  5728,  5729,  5730,  5734,  5744,  5746,  5751,  5754,  5759,
    5765,  5772,  5779,  5788,  5795,  5802,  5809,  5816,  5825,  5825,
    5827,  5827,  5830,  5831,  5832,  5833,  5834,  5835,  5836,  5837,
    5838,  5839,  5842,  5842,  5845,  5846,  5847,  5848,  5851,  5851,
    5854,  5854,  5857,  5858,  5859,  5860,  5861,  5862,  5863,  5864,
    5866,  5867,  5868,  5869,  5871,  5872,  5873,  5874,  5876,  5877,
    5878,  5879,  5880,  5881,  5882,  5883,  5887,  5893,  5901,  5912,
    5921,  5932,  5936,  5940,  5946,  5911,  5959,  5962,  5970,  5982,
    5984,  5989,  5997,  6007,  6010,  6014,  6022,  5988,  6031,  6035,
    6039,  6043,  6035,  6053,  6054,  6055,  6056,  6061,  6063,  6066,
    6070,  6073,  6080,  6085,  6086,  6087,  6092,  6093,  6099,  6099,
    6099,  6104,  6104,  6104,  6115,  6116,  6122,  6123,  6135,  6136,
    6141,  6142,  6143,  6147,  6150,  6156,  6159,  6167,  6168,  6174,
    6181,  6184,  6193,  6196,  6199,  6202,  6205,  6208,  6211,  6218,
    6221,  6228,  6231,  6237,  6240,  6247,  6250,  6257,  6258,  6263,
    6267,  6270,  6276,  6279,  6285,  6292,  6293,  6297,  6303,  6306,
    6313,  6314,  6321,  6324,  6329,  6340,  6341,  6342,  6343,  6344,
    6345,  6346,  6347,  6348,  6351,  6354,  6360,  6360,  6366,  6366,
    6377,  6390,  6400,  6400,  6405,  6405,  6409,  6413,  6414,  6420,
    6421,  6426,  6430,  6437,  6440,  6447,  6451,  6446,  6460,  6464,
    6468,  6475,  6479,  6479,  6492,  6496,  6496,  6511,  6513,  6515,
    6517,  6519,  6521,  6523,  6525,  6531,  6541,  6548,  6553,  6554,
    6558,  6560,  6561,  6564,  6565,  6566,  6569,  6574,  6581,  6582,
    6588,  6600,  6601,  6604,  6604,  6609,  6614,  6619,  6620,  6623,
    6624,  6629,  6634,  6638,  6643,  6644,  6648,  6655,  6659,  6660,
    6665,  6667,  6671,  6672,  6676,  6677,  6678,  6679,  6683,  6684,
    6689,  6690,  6695,  6696,  6701,  6702,  6707,  6712,  6713,  6718,
    6719,  6723,  6724,  6729,  6736,  6741,  6746,  6750,  6751,  6756,
    6757,  6763,  6765,  6770,  6771,  6777,  6780,  6783,  6790,  6792,
    6806,  6811,  6812,  6815,  6817,  6824,  6827,  6833,  6837,  6841,
    6845,  6848,  6855,  6862,  6867,  6871,  6872,  6878,  6881,  6892,
    6899,  6905,  6908,  6915,  6922,  6928,  6929,  6935,  6936,  6937,
    6940,  6941,  6946,  6946,  6950,  6958,  6959,  6962,  6965,  6970,
    6971,  6976,  6979,  6985,  6988,  6994,  6997,  7003,  7006,  7013,
    7014,  7043,  7044,  7049,  7057,  7062,  7065,  7068,  7071,  7077,
    7078,  7082,  7085,  7088,  7089,  7094,  7097,  7100,  7103,  7106,
    7109,  7112,  7118,  7119,  7120,  7121,  7122,  7124,  7126,  7127,
    7132,  7135,  7139,  7145,  7146,  7147,  7148,  7160,  7161,  7162,
    7166,  7167,  7172,  7174,  7175,  7176,  7178,  7179,  7180,  7181,
    7183,  7184,  7186,  7187,  7189,  7190,  7191,  7192,  7194,  7198,
    7199,  7205,  7207,  7208,  7209,  7210,  7215,  7219,  7223,  7227,
    7228,  7232,  7233,  7243,  7252,  7253,  7254,  7258,  7261,  7266,
    7271,  7276,  7284,  7288,  7292,  7293,  7294,  7299,  7302,  7305,
    7319,  7333,  7346,  7347,  7351,  7351,  7351,  7351,  7351,  7351,
    7352,  7355,  7360,  7360,  7360,  7360,  7360,  7360,  7362,  7365,
    7371,  7371,  7371,  7371,  7371,  7371,  7371,  7372,  7372,  7372,
    7372,  7372,  7372,  7372,  7374,  7375,  7378,  7387,  7387,  7393,
    7393,  7400,  7400,  7406,  7406,  7414,  7415,  7416,  7419,  7419,
    7422,  7423,  7424,  7429,  7432,  7438,  7443,  7451,  7464,  7465,
    7462,  7483,  7493,  7496,  7501,  7513,  7516,  7520,  7523,  7524,
    7530,  7533,  7534,  7543,  7552,  7557,  7558,  7559,  7560,  7567,
    7570,  7576,  7579,  7589,  7598,  7601,  7604,  7610,  7616,  7619,
    7622,  7625,  7631,  7633,  7635,  7637,  7639,  7641,  7642,  7643,
    7644,  7645,  7646,  7647,  7649,  7651,  7653,  7655,  7657,  7659,
    7661,  7662,  7667,  7668,  7675,  7678,  7687,  7691,  7698,  7698,
    7702,  7702,  7707,  7707,  7711,  7711,  7715,  7721,  7721,  7724,
    7724,  7730,  7737,  7738,  7739,  7743,  7744,  7747,  7748,  7752,
    7758,  7768,  7769,  7777,  7778,  7779,  7780,  7781,  7782,  7786,
    7787,  7788,  7792,  7792,  7804,  7805,  7809,  7810,  7811,  7815,
    7821,  7908,  7912,  7908,  7921,  7925,  7931,  7939,  7949,  7959,
    7971,  7974,  7993,  8019,  8022,  8028,  8031,  8036,  8039,  8047,
    8055,  8068,  8071,  8079,  8082,  8085,  8093,  8097,  8100,  8103,
    8106,  8110,  8111,  8112,  8113,  8114,  8120,  8121,  8122,  8123,
    8124,  8125,  8126,  8127,  8128,  8129,  8130,  8131,  8132,  8133,
    8137,  8143,  8144,  8156,  8177,  8177,  8181,  8182,  8183,  8184,
    8188,  8189,  8190,  8195,  8221,  8272,  8274,  8276,  8278,  8282,
    8287,  8289,  8292,  8294,  8296,  8300,  8303,  8308,  8313,  8317,
    8326,  8327,  8331,  8343,  8346,  8342,  8365,  8365,  8369,  8370,
    8373,  8374,  8375,  8376,  8377,  8378,  8379,  8384,  8385,  8389,
    8392,  8397,  8401,  8406,  8410,  8415,  8419,  8422,  8426,  8429,
    8434,  8438,  8449,  8455,  8455,  8456,  8457,  8464,  8473,  8473,
    8475,  8476,  8477,  8478,  8479,  8480,  8481,  8482,  8483,  8484,
    8485,  8486,  8487,  8488,  8489,  8490,  8491,  8492,  8493,  8494,
    8495,  8496,  8497,  8498,  8499,  8500,  8501,  8502,  8503,  8504,
    8505,  8506,  8507,  8508,  8509,  8510,  8511,  8512,  8513,  8514,
    8515,  8516,  8517,  8518,  8519,  8520,  8521,  8522,  8523,  8524,
    8525,  8526,  8527,  8528,  8529,  8530,  8531,  8532,  8533,  8534,
    8535,  8536,  8537,  8538,  8539,  8540,  8541,  8542,  8543,  8544,
    8545,  8546,  8547,  8548,  8549,  8550,  8551,  8552,  8553,  8554,
    8555,  8556,  8557,  8558,  8559
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
  "CYAN", "DATE", "DESC", "KWDOWN", "TAB", "DROP", "ELSE", "EXEC", "EXIT", 
  "FREE", "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", "HIDE", 
  "HOUR", "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", 
  "NEXT", "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", 
  "SOME", "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", 
  "WITH", "WORK", "YEAR", "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", 
  "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", 
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
  "opt_foreach_using_part", "formhandler_def", "@71", "@72", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@73", 
  "@74", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@75", "@76", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@77", "@78", "@79", 
  "@80", "@81", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2", "cvariable", "real_number", "goto_cmd", 
  "check_menu_cmd", "menu_item_list", "menu_item", "uncheck_menu_cmd", 
  "disable_cmd", "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", 
  "gm_disable_msg", "op_returning_msg", "gm_returning_msg", "op_caption", 
  "gm_caption", "op_icon", "gm_icon", "op_buttons", "gm_buttons", 
  "op_def_but", "if_cmd", "@83", "op_else", "@84", "@85", "@86", 
  "import_m", "module_import", "init_cmd", "@87", "init_tab_list", 
  "init_tab", "end_input", "opt_defs", "field_commands", "field_command", 
  "@88", "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", 
  "@98", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@99", "inp_rest", "@100", 
  "scroll_cmd", "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@101", "key_val", 
  "@102", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@103", "@104", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@105", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@106", "@107", "@108", "@109", 
  "end_func_command", "main_def", "@110", "@111", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@112", 
  "glob_section", "mem_func_def", "@113", "@114", "@115", "menu_cmd", 
  "@116", "end_menu_command", "menu_block_command", "@117", "@118", 
  "@119", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@120", "@121", "menu_handler_elements", 
  "menu_handler_element", "@122", "@123", "message_cmd", "msg_next", 
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
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@124", 
  "gui_prompt_cmd", "opt_char", "prompt_key_sec", "prompt_key_clause", 
  "on_key_command_prompt", "@125", "prompt_title", "put_cmd", "@126", 
  "put_from", "put_val_list", "put_val", "start_cmd", "rout", "rep_name", 
  "op_values", "output_cmd", "finish_cmd", "term_rep_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@127", "@128", "@129", "@130", "@131", "@132", "@133", "report_cmd", 
  "need_command", "@134", "op_lines", "skip_command", "@135", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@136", "@137", "@138", "@139", "@140", 
  "@141", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@142", "@143", "@144", "@145", "@146", "@147", "pdf_report_section", 
  "pdf_functions", "@148", "@149", "@150", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@151", "@152", 
  "@153", "@154", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@155", "ins_2_ss", "@156", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@157", "@158", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@159", "opt_foreach_into_fetch_part", "@160", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@161", 
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
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@162", 
  "@163", "@164", "@165", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@166", "@167", 
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
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@168", "sql_block", 
  "sql_block_entry", "in_var", "sql_block_into", "update_statement_ss", 
  "@169", "@170", "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind_ss", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@171", "@172", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@173", "commands_all1", 0
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
     892,   896,   896,   898,   899,   897,   900,   900,   901,   901,
     902,   902,   904,   903,   905,   903,   906,   906,   907,   907,
     909,   908,   910,   908,   911,   912,   912,   912,   913,   913,
     914,   914,   915,   915,   916,   916,   918,   917,   919,   917,
     920,   917,   921,   917,   922,   917,   923,   924,   924,   924,
     924,   924,   924,   925,   925,   926,   927,   928,   929,   929,
     929,   929,   929,   929,   929,   929,   930,   931,   932,   933,
     934,   935,   936,   936,   937,   938,   939,   939,   940,   940,
     941,   941,   941,   941,   941,   941,   942,   943,   943,   944,
     945,   946,   946,   947,   948,   949,   949,   949,   950,   950,
     950,   952,   951,   953,   953,   954,   954,   955,   955,   956,
     957,   957,   958,   959,   959,   960,   961,   961,   962,   963,
     963,   965,   964,   966,   967,   966,   968,   969,   966,   970,
     970,   971,   973,   972,   972,   974,   974,   975,   975,   976,
     976,   977,   977,   978,   978,   980,   979,   981,   979,   982,
     979,   983,   979,   984,   979,   985,   979,   986,   979,   987,
     979,   988,   979,   989,   979,   990,   979,   991,   991,   992,
     992,   993,   994,   995,   995,   995,   997,   996,   998,   998,
     999,   998,  1000,  1001,  1001,  1001,  1001,  1002,  1002,  1003,
    1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,  1006,
    1005,  1005,  1008,  1007,  1009,  1010,  1011,  1011,  1012,  1012,
    1013,  1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,
    1014,  1014,  1014,  1014,  1014,  1014,  1014,  1014,  1015,  1017,
    1018,  1016,  1019,  1019,  1020,  1021,  1022,  1023,  1023,  1025,
    1024,  1026,  1026,  1027,  1027,  1028,  1028,  1028,  1028,  1029,
    1029,  1030,  1030,  1031,  1032,  1032,  1032,  1032,  1032,  1032,
    1032,  1032,  1032,  1032,  1032,  1033,  1033,  1034,  1034,  1034,
    1035,  1036,  1036,  1038,  1039,  1040,  1041,  1037,  1042,  1044,
    1045,  1043,  1046,  1047,  1047,  1048,  1049,  1050,  1050,  1051,
    1051,  1051,  1053,  1052,  1054,  1054,  1056,  1057,  1058,  1055,
    1060,  1059,  1061,  1063,  1062,  1064,  1062,  1065,  1062,  1066,
    1066,  1067,  1067,  1068,  1068,  1069,  1069,  1069,  1070,  1071,
    1072,  1073,  1073,  1073,  1074,  1074,  1075,  1075,  1077,  1078,
    1076,  1079,  1079,  1081,  1080,  1082,  1080,  1083,  1084,  1084,
    1084,  1084,  1085,  1085,  1085,  1085,  1085,  1086,  1087,  1087,
    1088,  1089,  1090,  1090,  1091,  1092,  1092,  1092,  1092,  1092,
    1092,  1093,  1094,  1095,  1095,  1096,  1096,  1097,  1098,  1099,
    1099,  1100,  1100,  1101,  1102,  1103,  1103,  1103,  1103,  1103,
    1103,  1104,  1104,  1105,  1106,  1106,  1107,  1107,  1108,  1108,
    1109,  1109,  1110,  1110,  1110,  1110,  1110,  1111,  1111,  1112,
    1112,  1113,  1113,  1114,  1115,  1116,  1116,  1117,  1118,  1118,
    1118,  1119,  1120,  1120,  1121,  1121,  1122,  1123,  1123,  1124,
    1124,  1125,  1126,  1127,  1128,  1128,  1129,  1130,  1130,  1131,
    1131,  1132,  1132,  1133,  1134,  1134,  1135,  1135,  1135,  1135,
    1136,  1136,  1136,  1137,  1138,  1138,  1139,  1139,  1139,  1140,
    1141,  1141,  1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,
    1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,
    1142,  1142,  1142,  1142,  1143,  1144,  1144,  1145,  1145,  1146,
    1148,  1147,  1149,  1150,  1150,  1151,  1151,  1152,  1152,  1154,
    1153,  1155,  1157,  1156,  1158,  1158,  1159,  1159,  1160,  1160,
    1161,  1161,  1161,  1161,  1162,  1162,  1163,  1164,  1164,  1165,
    1166,  1167,  1168,  1169,  1169,  1170,  1170,  1172,  1171,  1173,
    1171,  1174,  1171,  1175,  1171,  1176,  1171,  1177,  1171,  1178,
    1171,  1179,  1179,  1179,  1179,  1179,  1179,  1181,  1180,  1182,
    1182,  1184,  1183,  1183,  1183,  1183,  1183,  1185,  1185,  1186,
    1186,  1187,  1188,  1188,  1189,  1190,  1191,  1192,  1192,  1192,
    1193,  1193,  1193,  1193,  1194,  1195,  1195,  1196,  1196,  1197,
    1198,  1198,  1198,  1198,  1198,  1198,  1198,  1198,  1199,  1199,
    1200,  1200,  1201,  1201,  1201,  1201,  1201,  1201,  1201,  1201,
    1201,  1201,  1202,  1202,  1203,  1203,  1203,  1203,  1204,  1204,
    1205,  1205,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  1206,  1206,  1206,  1206,  1206,  1207,  1207,  1207,  1209,
    1210,  1211,  1212,  1213,  1214,  1208,  1215,  1215,  1216,  1217,
    1217,  1219,  1220,  1221,  1222,  1223,  1224,  1218,  1225,  1227,
    1228,  1229,  1226,  1230,  1230,  1230,  1230,  1231,  1231,  1231,
    1231,  1231,  1232,  1233,  1233,  1233,  1234,  1234,  1236,  1237,
    1235,  1238,  1239,  1235,  1240,  1240,  1241,  1241,  1242,  1242,
    1243,  1243,  1243,  1244,  1244,  1245,  1245,  1246,  1246,  1247,
    1248,  1248,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1250,
    1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,
    1256,  1256,  1257,  1257,  1258,  1259,  1259,  1260,  1261,  1261,
    1262,  1262,  1263,  1263,  1264,  1265,  1265,  1265,  1265,  1265,
    1265,  1265,  1265,  1265,  1265,  1265,  1266,  1266,  1267,  1267,
    1268,  1269,  1271,  1270,  1273,  1272,  1272,  1274,  1274,  1275,
    1275,  1276,  1276,  1277,  1277,  1279,  1280,  1278,  1281,  1282,
    1282,  1283,  1284,  1283,  1285,  1286,  1285,  1287,  1287,  1287,
    1287,  1287,  1287,  1287,  1287,  1288,  1289,  1290,  1291,  1291,
    1292,  1293,  1293,  1294,  1294,  1294,  1295,  1296,  1297,  1297,
    1298,  1299,  1299,  1301,  1300,  1302,  1302,  1302,  1302,  1302,
    1302,  1302,  1302,  1302,  1302,  1302,  1302,  1303,  1304,  1304,
    1305,  1305,  1306,  1306,  1307,  1307,  1307,  1307,  1308,  1308,
    1309,  1309,  1310,  1310,  1311,  1311,  1312,  1313,  1313,  1314,
    1314,  1315,  1315,  1316,  1317,  1318,  1319,  1320,  1320,  1321,
    1321,  1322,  1322,  1323,  1323,  1324,  1324,  1324,  1325,  1325,
    1326,  1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,  1330,
    1330,  1330,  1331,  1332,  1333,  1334,  1334,  1335,  1335,  1336,
    1337,  1338,  1338,  1339,  1340,  1341,  1341,  1342,  1342,  1342,
    1343,  1343,  1344,  1344,  1345,  1346,  1346,  1347,  1347,  1348,
    1348,  1349,  1349,  1350,  1350,  1351,  1351,  1352,  1352,  1353,
    1353,  1354,  1354,  1355,  1356,  1357,  1357,  1357,  1357,  1358,
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
    1418,  1418,  1419,  1419,  1420,  1421,  1422,  1422,  1423,  1423,
    1424,  1424,  1425,  1425,  1426,  1426,  1427,  1428,  1428,  1429,
    1429,  1430,  1431,  1431,  1431,  1432,  1432,  1433,  1434,  1435,
    1436,  1437,  1437,  1438,  1438,  1438,  1438,  1438,  1438,  1439,
    1439,  1439,  1441,  1440,  1442,  1442,  1443,  1443,  1443,  1444,
    1445,  1447,  1448,  1446,  1449,  1449,  1449,  1450,  1450,  1450,
    1450,  1450,  1450,  1451,  1451,  1452,  1453,  1454,  1454,  1455,
    1455,  1456,  1456,  1457,  1457,  1457,  1458,  1458,  1458,  1458,
    1458,  1458,  1458,  1458,  1458,  1458,  1459,  1459,  1459,  1459,
    1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,  1459,
    1460,  1461,  1461,  1462,  1463,  1463,  1464,  1464,  1464,  1464,
    1465,  1465,  1465,  1466,  1466,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1467,  1467,  1468,  1468,  1468,  1468,  1468,
    1469,  1469,  1470,  1472,  1473,  1471,  1474,  1474,  1475,  1475,
    1476,  1476,  1476,  1476,  1476,  1476,  1476,  1477,  1477,  1478,
    1478,  1479,  1479,  1480,  1480,  1481,  1481,  1482,  1483,  1484,
    1485,  1485,  1486,  1487,  1487,  1488,  1489,  1489,  1491,  1490,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,
    1492,  1492,  1492,  1492,  1492
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
       9,     0,     3,     0,     0,    10,     0,     1,     0,     1,
       1,     2,     0,     3,     0,     3,     0,     1,     1,     2,
       0,     3,     0,     3,     3,     1,     4,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     0,     3,     0,     3,
       0,     4,     0,     4,     0,     4,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     4,
       6,     4,     3,     6,     3,     6,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     4,     1,     1,
       1,     4,     3,     6,     3,     6,     1,     1,     2,     2,
       2,     1,     3,     1,     2,     2,     2,     4,     2,     2,
       4,     0,     8,     0,     1,     1,     1,     0,     1,     2,
       0,     1,     2,     0,     1,     2,     0,     1,     3,     0,
       2,     0,     7,     0,     0,     3,     0,     0,     7,     5,
       2,     2,     0,     5,     4,     1,     3,     3,     3,     0,
       2,     0,     1,     1,     2,     0,     4,     0,     4,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     1,     3,     1,
       3,     2,     4,     1,     1,     1,     0,     4,     5,     6,
       0,    10,     3,     2,     2,     1,     1,     0,     2,     1,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     0,
       3,     1,     0,     3,     2,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
     132,  1802,   671,   614,  1765,     0,     0,  1768,     0,  1764,
    1760,  1757,  1755,  1756,  1763,  1762,  1759,   294,  1565,  1564,
     825,   175,   186,   178,   183,     1,   789,   784,   830,   828,
     806,   126,   130,   133,  1772,  1769,     0,  1770,  1767,     0,
       0,   593,     0,     0,   176,   835,   899,   594,   833,   626,
     891,     0,   892,   900,   898,   186,   180,   199,     0,   184,
     200,   229,     0,   812,  1181,     0,     0,   811,   135,  1169,
     819,     0,     0,   802,   804,   801,   803,   780,   790,   791,
     813,   794,   795,   796,   799,   797,   798,   800,  1771,  1766,
       0,   893,   834,     0,     0,   907,   905,   906,   895,   894,
     292,   186,  1105,   193,   187,   186,   192,   226,     0,   670,
       0,     0,     0,     0,   175,   543,   868,   792,     0,   326,
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
      17,    19,    18,    20,     0,    14,     0,   909,     0,   627,
     188,   191,     0,   189,   190,     0,   196,   195,   194,   197,
     186,     0,   186,   256,   257,     0,     0,   186,     0,     0,
       0,     0,   239,   227,  1182,     0,     0,  1170,  1808,   544,
     869,   814,     0,   208,   209,     0,   275,   277,   272,   273,
     269,   271,   268,   270,   267,     0,   277,   288,   289,   285,
     287,   284,   286,   279,     0,     0,     0,   328,     0,   331,
     333,   216,     0,   215,     0,     0,   186,    11,    12,   912,
       0,   896,   628,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   228,   231,   924,   669,   836,   924,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
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
     548,   809,     0,   873,     0,   871,     0,   327,   210,   211,
       0,   276,   281,     0,     0,     0,     0,   329,   332,     0,
     214,     0,   910,     0,   220,     0,   186,     0,     0,     0,
       0,     0,  1183,     0,     0,  1171,     0,     0,  1215,   615,
     616,   793,  1046,  1051,  1782,   608,   122,     0,     0,  1747,
    1746,   984,  1743,  1745,  1797,     0,  1222,     0,  1218,  1227,
       7,     0,     6,     0,  1790,  1047,     0,  1139,  1138,  1086,
    1137,  1085,     0,     0,     0,   424,   426,     0,  1176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1532,
       0,     0,     0,   418,     0,     0,     0,     0,   417,     0,
       0,   434,     0,   505,     0,     0,     0,     0,     0,     0,
     413,  1279,     0,   383,   382,   389,   430,   427,   384,   503,
     495,   385,   387,   502,   388,   899,   425,   428,   433,  1267,
     504,  1661,  1273,   124,     0,  1050,   121,     0,   775,    23,
     610,   381,     0,   774,  1043,   776,     0,  1277,   862,   861,
     864,   860,   863,  1799,     0,   858,     0,   609,   957,   859,
    1793,     0,  1781,   120,   954,   672,   952,     0,   606,  1776,
     714,   713,     0,   715,   598,   711,     0,     0,   967,   611,
    1332,  1328,  1331,     0,     0,  1019,  1017,     0,  1011,  1013,
    1012,  1010,  1009,     0,     0,     0,  1008,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     998,   989,   990,     0,  1031,   411,    23,   822,   403,  1787,
       0,  1778,   125,   607,     0,  1016,  1015,  1180,  1178,  1104,
       0,  1650,  1651,  1105,  1193,  1105,  1088,  1089,  1092,  1107,
    1280,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,   899,     0,    68,     0,   101,   586,   629,     0,
    1077,   974,  1081,     0,     0,  1032,  1197,     0,     0,  1084,
     633,   630,   631,     0,   635,   636,     0,   638,   639,     0,
     634,   934,   936,     0,     0,   935,   716,   932,   681,   928,
     890,     0,     0,     0,     0,   645,   646,     0,     0,   888,
     885,   886,   882,   883,   884,   877,   881,   880,     0,     0,
       0,     0,     0,     0,   552,   554,   546,   549,   550,   875,
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
     409,   334,     0,   538,   591,   590,   588,   992,   592,   997,
     993,   996,   767,   754,   765,   766,   752,   753,   761,   756,
     760,   755,   764,   759,   762,   758,   763,   751,   757,   744,
     750,   994,   995,     0,  1002,  1006,   999,  1000,  1004,  1005,
    1003,  1001,  1007,     0,   777,     0,     0,     0,   406,   407,
     404,   405,     0,     0,     0,   726,   725,   722,  1779,  1786,
      23,  1100,  1101,  1102,  1103,  1097,  1095,  1194,  1109,  1094,
    1090,     0,     0,  1091,  1774,     0,     0,     0,     0,    97,
       0,    98,     0,     0,     0,    73,     0,     0,     0,   110,
     105,     0,   867,     0,   866,     0,   469,  1079,     0,   919,
     920,   943,   914,   915,   770,   941,  1034,  1199,     0,  1201,
    1200,  1686,     0,     0,     0,  1684,  1687,  1688,   661,     0,
       0,     0,   650,   681,   681,   679,     0,     0,   682,     0,
      25,   649,   652,     0,   659,   655,   889,   879,  1657,  1658,
    1648,  1648,  1298,     0,     0,  1566,     0,   186,  1281,     0,
       0,  1282,  1326,   186,     0,  1327,     0,  1605,     0,  1295,
       0,  1344,  1343,  1342,  1340,  1341,  1339,  1337,  1334,  1408,
    1407,  1335,  1336,  1345,  1575,  1338,  1664,  1663,  1662,  1346,
    1808,  1808,   565,   556,   547,     0,   551,  1808,   874,   175,
       0,   321,   213,     0,   186,   222,   205,  1184,   175,  1172,
    1398,     0,  1397,     0,  1399,     0,  1400,  1258,     0,  1264,
    1260,  1257,     0,     0,     0,     0,     0,     0,  1254,  1250,
    1387,  1386,  1385,  1226,  1225,     0,  1249,  1245,     0,  1241,
    1239,     0,   619,     0,   618,     0,   985,     0,     0,   983,
    1750,  1752,  1751,  1748,  1798,  1795,  1219,     0,     0,     0,
    1212,   469,   342,     0,  1177,     0,     0,     0,     0,  1605,
       0,     0,     0,     0,     0,   527,   513,   518,     0,   514,
     517,   516,     0,     0,     0,     0,     0,     0,   419,     0,
     171,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,   437,   436,   455,   446,   461,   464,   465,   462,   468,
     467,   466,   456,   457,   459,   458,   460,   402,   447,   451,
     469,   463,   450,   469,    92,     0,   429,     0,  1209,   976,
    1044,  1045,  1042,  1041,     0,   865,     0,     0,   595,     0,
       0,     0,   955,   953,     0,   674,   675,     0,     0,  1777,
    1785,     0,     0,   602,     0,   604,   712,     0,   141,     0,
     965,   972,     0,     0,   980,     0,   337,     0,     0,     0,
       0,    23,  1018,   541,     0,     0,     0,   745,   746,   991,
     778,   412,     0,  1023,     0,  1788,   723,   724,   361,     0,
    1105,     0,  1108,  1093,  1808,     0,     0,     0,   530,     0,
       0,     0,     0,    63,    92,     0,     0,   116,   111,     0,
     106,     0,   113,   107,   851,   843,   849,     0,  1078,     0,
    1080,  1082,     0,     0,   923,     0,     0,     0,     0,  1033,
    1198,  1753,  1689,   939,  1690,   937,  1683,  1685,  1808,   632,
     637,   640,   653,   651,   612,     0,   701,   699,   705,   703,
       0,     0,   697,   741,   695,   691,   689,   739,   717,     0,
     683,   693,   933,   929,     0,     0,     0,     0,   658,     0,
       0,     0,     0,     0,     0,     0,  1513,     0,  1403,  1404,
    1669,  1367,  1425,     0,     0,  1667,     0,     0,  1607,  1608,
    1606,  1588,  1691,     0,  1350,  1356,  1355,  1354,  1358,     0,
    1351,  1352,     0,  1576,  1587,   553,   555,     0,     0,   568,
     560,   562,     0,   557,   558,     0,     0,   576,   578,     0,
       0,   574,   876,   816,   212,     0,     0,   224,  1140,   838,
    1118,  1375,  1377,     0,  1262,     0,     0,     0,     0,     0,
    1252,     0,     0,  1505,  1503,  1490,  1492,  1488,     0,  1487,
       0,  1496,  1483,  1504,     0,  1495,  1480,  1486,  1502,  1494,
    1391,  1477,  1478,  1479,     0,  1247,  1243,     0,     0,  1231,
     617,     0,     0,     0,     0,     0,  1794,     4,     8,    10,
    1509,  1512,     0,   469,   501,   498,   497,   500,   496,     0,
     421,   507,   492,   492,     0,   515,     0,   519,     0,   282,
    1176,     0,  1533,   499,  1176,   506,   420,   266,     0,  1176,
     480,   477,   486,  1176,   483,  1176,  1176,  1176,     0,     0,
       0,     0,     0,     0,     0,     0,   471,    93,    94,    96,
     473,     0,     0,     0,   973,     0,     0,     0,     0,     0,
       0,     0,   186,   673,     0,   599,   601,     0,     0,   158,
     156,     0,     0,   138,     0,   148,   154,   681,   143,   145,
       0,   970,   981,   982,     0,   410,   336,   341,   597,   335,
       0,   338,   343,   469,  1304,   589,   587,     0,   748,  1022,
    1024,     0,   408,   362,  1098,  1096,  1195,  1196,     0,     0,
    1189,     0,     0,     0,     0,    99,     0,     0,    74,    80,
      70,  1808,  1808,   109,   104,   118,   114,     0,   108,   742,
     852,   612,  1808,   842,   841,   850,   975,     0,     0,   921,
     922,   916,   942,   469,     0,     0,  1631,  1523,  1526,  1632,
    1530,  1524,  1629,     0,     0,  1039,  1628,     0,     0,  1630,
       0,     0,     0,     0,     0,  1747,  1525,  1035,  1036,  1627,
    1527,  1619,  1038,  1614,  1617,  1618,     0,     0,     0,   663,
     656,   654,     0,    23,     0,  1808,  1808,  1808,  1808,   707,
     685,   709,   687,  1808,  1808,  1808,  1808,     0,   680,   684,
    1808,   612,   737,   735,   738,   736,     0,     0,    45,    43,
      40,    34,    38,    42,    37,    30,    39,     0,    33,    36,
      31,    41,    32,    44,    35,     0,    28,    46,   729,     0,
     660,  1649,     0,  1647,  1605,  1645,  1592,  1593,  1585,  1571,
    1586,     0,     0,     0,  1014,  1402,  1405,     0,     0,     0,
       0,  1426,  1316,  1287,  1672,  1671,  1670,     0,     0,     0,
       0,  1311,     0,  1310,     0,  1312,  1307,  1308,  1309,  1300,
    1296,     0,     0,  1357,     0,     0,     0,  1580,  1577,  1578,
     567,   572,     0,     0,  1808,  1808,   545,   559,   582,   570,
     584,  1808,  1808,   580,   564,   575,   807,   322,   206,     0,
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
       0,     0,     0,  1274,  1801,  1800,   596,     0,     0,    47,
       0,   678,   677,   676,  1275,     0,     0,   681,  1808,  1808,
     150,   620,   160,   152,   162,   142,   149,  1808,     0,     0,
       0,     0,     0,     0,     0,  1305,   539,     0,   747,   612,
       0,  1775,     0,    92,   531,     0,    64,     0,     0,     0,
      77,     0,    92,    92,   117,   112,  1808,  1808,   102,     0,
     853,   847,   855,   854,   844,   535,   902,     0,     0,  1616,
    1615,  1529,     0,  1605,     0,     0,  1473,     0,  1473,  1473,
    1473,  1473,  1620,     0,     0,     0,     0,     0,     0,  1673,
    1674,  1675,  1676,  1677,  1678,  1623,  1754,   940,   938,   666,
     664,     0,   643,   657,   613,   718,     0,   702,   700,   706,
     704,     0,  1808,     0,  1808,   698,   696,   692,   690,   740,
     694,    23,   730,     0,     0,     0,    26,     0,  1652,     0,
    1575,     0,     0,  1584,  1567,  1583,  1406,     0,  1369,     0,
    1315,  1413,     0,     0,  1668,     0,  1665,  1589,     0,     0,
       0,     0,     0,     0,  1692,  1314,  1313,  1301,  1299,     0,
    1360,     0,  1353,     0,     0,     0,     0,   569,   566,   561,
     563,     0,  1808,  1808,   577,   579,  1808,  1808,     0,     0,
    1164,  1165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1163,     0,     0,  1151,  1152,  1153,  1150,
    1155,  1156,  1157,  1154,  1141,  1132,     0,     0,  1188,     0,
    1808,     0,  1127,     0,     0,     0,     0,     0,     0,     0,
    1119,  1120,     0,  1052,     0,  1263,  1436,     0,  1440,     0,
    1453,  1439,     0,  1401,     0,  1454,  1467,  1464,  1465,  1462,
    1469,  1468,  1463,  1466,     0,     0,     0,     0,     0,     0,
    1518,     0,  1519,     0,     0,     0,     0,  1382,  1253,  1381,
    1373,     0,     0,     0,  1507,  1499,  1499,     0,     0,  1499,
    1506,     0,  1523,  1388,  1390,  1394,  1395,  1248,  1244,   988,
       0,   951,     9,     0,  1216,   824,  1049,     0,     0,  1425,
    1595,  1612,     0,   492,   520,     0,   275,   481,   478,   487,
     484,     0,   443,   442,   472,    95,   474,   348,  1210,     0,
       0,  1792,     0,     0,   956,    48,     0,   603,   605,   600,
     727,   159,   157,     0,  1808,     0,     0,     0,  1808,   155,
     144,     0,   147,   146,     0,   962,   966,   340,     0,   542,
       0,  1808,   749,    23,  1099,     0,  1190,    69,     0,     0,
     100,    67,    92,    75,    81,     0,   119,   115,   743,  1808,
     857,   612,   856,     0,   532,     0,   772,   773,   771,     0,
       0,  1640,     0,     0,     0,  1475,  1476,  1474,     0,  1642,
       0,     0,     0,     0,     0,     0,     0,  1037,  1625,  1626,
    1622,  1624,     0,  1808,   662,   647,   644,     0,   708,   686,
     710,   688,   719,   733,   734,   731,   732,    29,    27,     0,
    1646,  1601,  1572,  1573,  1569,  1575,     0,  1368,  1605,  1371,
       0,  1289,  1284,  1283,  1286,     0,  1601,     0,     0,  1725,
    1723,     0,     0,  1711,  1722,     0,     0,  1724,     0,     0,
       0,     0,     0,  1747,  1721,  1717,     0,  1709,  1712,  1713,
    1720,  1716,  1740,     0,  1702,  1701,  1705,  1707,     0,  1700,
       0,  1703,  1694,  1302,  1297,     0,  1359,     0,     0,  1581,
    1579,   573,   571,   583,   585,   581,     0,     0,   229,  1158,
    1159,  1160,  1162,  1145,  1143,  1142,  1146,  1147,  1144,  1161,
    1148,  1149,  1133,   948,  1168,   945,     0,     0,  1186,     0,
    1131,  1130,  1125,  1123,  1122,  1126,  1124,  1128,  1129,  1121,
    1174,  1378,  1438,  1432,  1434,  1441,  1443,     0,  1448,  1441,
       0,  1446,     0,  1456,  1455,     0,  1457,     0,  1374,  1380,
    1521,  1514,  1384,  1563,  1561,  1562,  1558,  1560,  1557,  1559,
    1489,     0,  1491,     0,     0,     0,     0,  1497,  1501,     0,
    1481,  1396,   987,  1224,  1217,  1213,  1610,     0,  1414,  1415,
    1417,  1420,  1427,     0,     0,  1473,  1597,  1591,  1548,  1546,
    1547,  1543,  1545,  1542,  1544,   493,   491,     0,   525,   524,
     172,   439,     0,     0,    23,     0,     0,   979,     0,    49,
     959,     0,    23,   161,   151,     0,   622,   624,   163,   153,
     727,     0,   339,  1306,     0,  1020,     0,     0,    65,     0,
      78,    87,     0,    71,   848,   845,   536,  1808,   917,  1531,
       0,     0,     0,  1641,     0,     0,     0,  1639,     0,     0,
       0,     0,  1621,  1638,     0,   665,   642,   648,   612,  1656,
       0,  1654,     0,     0,  1575,  1575,  1568,  1370,     0,  1372,
    1366,     0,  1288,     0,  1666,     0,  1715,  1714,     0,     0,
    1473,     0,  1473,  1473,  1473,  1473,  1718,     0,     0,  1698,
       0,     0,     0,     0,  1727,  1699,     0,     0,     0,     0,
       0,     0,  1693,     0,  1361,  1364,  1348,  1362,  1365,     0,
     818,   817,   323,   207,   950,   949,   947,     0,  1167,  1053,
    1057,  1059,     0,  1063,     0,  1061,  1065,  1054,  1055,     0,
     839,     0,     0,  1460,     0,  1449,  1452,  1451,  1459,     0,
    1441,     0,     0,  1515,  1520,     0,  1508,  1500,  1484,  1482,
       0,  1485,     0,  1418,     0,  1522,  1421,     0,  1428,  1429,
    1600,  1216,     0,     0,     0,     0,   522,   521,   475,   349,
     346,     0,   977,     0,     0,     0,   958,   728,   139,   621,
      23,   968,   540,  1025,    66,  1191,    83,     0,     0,    76,
      87,    87,  1808,   533,     0,     0,     0,     0,     0,  1637,
    1643,  1633,  1634,  1635,  1636,   667,   720,     0,  1653,  1602,
    1595,  1574,  1570,     0,  1290,     0,  1595,  1738,     0,     0,
    1741,     0,     0,     0,     0,     0,     0,     0,  1710,  1729,
    1730,  1726,  1728,  1708,     0,  1704,  1706,  1695,  1696,  1303,
       0,  1349,  1347,  1582,   946,  1808,  1808,  1067,  1808,  1069,
    1808,  1808,  1056,  1187,  1175,  1442,  1644,  1444,     0,  1447,
    1445,  1461,     0,     0,     0,  1498,  1422,     0,  1416,  1410,
    1411,  1613,     0,  1430,  1424,  1598,  1321,  1317,  1318,  1323,
    1322,  1596,  1216,     0,   351,   978,  1791,     0,     0,     0,
       0,     0,     0,    54,     0,    53,     0,    51,     0,     0,
     140,  1029,  1021,     0,  1027,    87,    92,    87,    88,    82,
      72,   846,     0,     0,  1604,     0,  1681,     0,  1808,    23,
    1655,  1594,  1603,  1294,     0,  1291,  1293,  1590,  1739,     0,
       0,  1737,     0,     0,     0,     0,  1719,  1736,     0,  1363,
    1058,  1060,  1808,  1064,  1808,  1062,  1066,  1450,  1458,  1516,
    1493,     0,  1419,     0,  1409,     0,  1325,  1324,  1320,  1599,
    1549,   357,   355,   347,     0,   353,   359,    56,    61,    58,
      60,    57,    59,    55,     0,    50,     0,   623,   625,  1808,
    1026,  1028,  1192,    84,    79,   534,   918,  1679,  1680,   663,
     721,     0,  1285,  1735,  1742,  1731,  1732,  1733,  1734,     0,
    1068,  1070,  1423,  1412,  1319,  1808,  1808,   352,   354,  1808,
      52,     0,  1030,     0,   668,  1292,  1697,   358,   356,   360,
       0,    85,   960,    89,    91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   552,   553,   554,   555,   711,  1737,  1738,   189,   264,
     190,  1133,  1134,  1625,  1965,  3025,  2464,  2465,  2904,  3026,
    3027,   556,   900,  2498,  2203,  2921,  1564,  2201,  2761,  2502,
    2917,  2202,  2762,  3036,  3143,  3153,  2919,  3156,  1786,  1787,
    1788,  1250,  1854,   557,  1261,   905,  1259,  1572,  1864,  1569,
    1862,  1867,  2207,  1260,  1861,  1573,  2206,   558,    17,    36,
      37,    38,    39,    40,   114,   561,   827,  1518,  1160,  1813,
    1817,  1818,  1814,  1815,  2474,  2478,  2177,  2169,  2168,  2170,
    2173,  1115,  1067,  1768,   562,    83,    84,    19,    62,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     679,  2329,   305,   660,  1685,   332,   333,   229,   287,   280,
     282,   985,   986,   146,   355,   147,   148,   293,   230,   231,
    1504,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   663,   247,   248,   323,   375,   196,    20,    80,   178,
     179,   180,   669,  2328,   181,   251,   240,   326,   327,   328,
     329,  1531,   563,   564,   565,   566,   784,  3014,  2734,  1135,
    3093,  3094,  3095,  3136,  3135,  3139,   567,   568,   569,   570,
     760,  1116,   867,  1219,  1220,  1169,   864,  1170,   762,   763,
     764,   765,   766,   767,   768,  1070,  1117,  2141,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,   716,   769,  1484,  2146,  2148,
    2732,   770,  1454,  2130,  1453,  2129,  1457,  2133,  1455,  2131,
    2113,  2122,   771,   772,   773,   774,  1438,  1439,  1440,  1441,
    1557,   571,  2767,  3042,  2514,   572,   837,  1533,  2491,  1834,
     115,   237,   365,  1353,   966,   967,   968,  1350,  1351,  1672,
    1673,  1674,  2024,  2025,  1354,  1355,  1668,  2028,  2020,  1680,
    1681,  2031,  2032,  2326,  2322,  2323,   573,  1177,    85,  1499,
    1500,  1829,   869,   817,   872,   694,   806,   789,   828,  1923,
      86,   695,   689,  1403,  2172,    87,   776,   574,   575,   921,
     922,   576,   577,   578,   579,   929,  2545,   950,  2786,   951,
    1602,   952,  1920,   953,  2252,   954,  1628,   580,  1598,  2251,
    2543,  2542,  3048,   116,    21,   581,  1151,  1505,  1506,  1618,
    1299,  1619,  1620,  2262,  2264,  1936,  1935,  1940,  1934,  1933,
    1926,  1925,  1928,  1927,  1930,  1932,   582,   583,   825,   584,
    1295,   936,  3049,   585,  1227,  2742,  1967,  1968,  1621,  1937,
    1870,  2209,   860,  1204,  1537,  1837,  1538,  1200,   586,   587,
     914,  1587,  2518,   588,   589,   590,   591,    22,    66,    23,
      24,    25,   117,   118,   592,   119,    26,   650,    27,   120,
     121,   158,   367,  1359,  2036,  2841,   122,   154,   298,   593,
    2109,    28,    29,    30,    31,    32,    61,    88,   123,   413,
    1368,  2042,   594,   909,  1874,  1576,  1872,  2922,  2509,  1577,
    1871,  2212,  2511,   595,   596,   597,   800,   801,  1263,   124,
     238,   366,   654,   655,   970,  1357,   598,   955,   956,   599,
    1307,   957,   777,    90,    91,    92,    93,  1270,   184,   138,
      94,   700,   135,   192,   193,  1271,  1272,  1881,  1273,   410,
     411,   938,   412,   939,  1594,  1595,  1274,  1275,  1131,  2644,
    2645,  2846,  1412,   815,   816,   600,  1146,  2906,   601,  2486,
     602,  1164,  1165,  1166,  1524,  1522,   603,   604,  1794,  1824,
     605,  1018,  1409,   606,   861,   862,   607,   877,   608,  1978,
     609,  2913,   610,  1841,  3032,  3033,  3034,  3109,   866,   611,
    1276,  1589,  1907,  1908,   612,  1492,   693,  1030,   613,   614,
     615,  2044,  2648,  2857,  2858,  2975,  2976,  2980,  2978,  2981,
    3072,  3074,   616,   617,  1265,  1581,   618,  1267,   885,   886,
     887,  1243,   619,   620,   621,  1550,  1235,   880,   199,   888,
     889,   778,  2045,  2370,  2371,  2354,   719,   720,  2040,  2355,
    2358,   125,   153,   359,   995,  1690,  2372,  2861,  1040,   622,
     878,   126,   150,   356,   992,  1688,  2359,  2859,  2041,   904,
    2193,  2757,  3035,  1238,   623,   624,   625,   626,   627,   787,
    1792,   713,  1742,   628,  2705,   707,   708,  2106,  1388,   629,
     630,  1004,  1005,  1006,  1400,  1727,  1007,  1724,  1397,  1008,
    1699,  1389,  1009,  1010,  1011,  1012,  1693,  1380,   631,   796,
     779,   632,  1331,  1332,  1643,  2573,  2803,  2293,  2570,  3054,
    3055,  1333,  1653,  2307,  1313,  2010,  2614,  2833,  2186,  2490,
    2011,  1334,  1335,  2716,  3007,  3008,  3009,  3088,  1336,  1337,
    1168,   633,   831,   634,   963,  1338,  1339,  2972,  1659,  1660,
    1661,  2013,  2309,  2836,  2837,  1340,  1988,  2287,  2800,  1390,
    1391,  1376,  2065,  1691,  2066,  1392,  2070,  1393,  2093,  1394,
    2094,  2424,  2425,  1694,  1341,  1637,  1638,  1985,  1342,  3003,
    2888,  2999,  1991,  2439,  2708,  2709,  2710,  2997,  2440,  1992,
    2889,  3004,  2053,  2054,  2055,  2056,  2057,  2863,  2665,  2985,
    2058,  2864,  2865,  2398,  2059,  2399,  2060,  2528,  1720,  1721,
    1722,  2694,  1723,  2421,  2415,  2877,  2067,  2838,  2402,  2606,
    2069,  2886,  1909,   780,  1910,  2221,  1058,  2114,  2725,  2083,
    2690,    60,   635,   636,  2565,  2795,  2280,  2794,  1664,  2018,
    2019,  2284,  1979,  1343,  1980,  1999,  2576,  1430,  1975,  1976,
    2717,  2891,  2793,  2569,  1911,  1651,  2110,  2111,  3000,  2061,
    1913,  1914,  2530,  2987,   637,   638,  1630,  1977,  2560,  2790,
    2791,  1310,   639,   782,  1345,  1346,  1646,  2295,  1347,  1348,
    1996,  2245,  2523,   640,   917,  1284,  1285,  1286,  1287,  1349,
    2000,  2612,  2832,  2304,  2609,  2610,  2611,  2608,  2596,  2597,
    2598,  2599,  2600,  2601,  2951,   701,  1591,   703,  1413,  1915,
      64,    49,    78,    75,   642,   891,  1554,  1154,  1229,   643,
     870,   644,  2159,   645,  1736,   705,  1415,   646,   647,    43,
     360,   361,   362,   363,   364,   648
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2560
static const short yypact[] =
{
    2626,  1138, -2560, -2560,   332,   437,   437,   437,   437,   437,
     437,   437,   437,   332,  1401, -2560, -2560, -2560,  1221, -2560,
   -2560, -2560,   412, -2560,  2626, -2560, -2560, -2560, -2560, -2560,
    2138, -2560, -2560, -2560, -2560, -2560,   393,   414, -2560,   597,
   -2560, -2560, -2560, -2560, -2560,   332,    46, -2560,  -124, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560,  1311,   355, -2560, -2560, -2560,  1295, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560,   332, -2560, -2560,    46,
     227, -2560,   332,   527,  1221, -2560,   840, -2560, -2560, -2560,
   -2560,   784,   153, -2560, -2560, -2560,   868,   543,   332, -2560,
   -2560,   901,   332, -2560, -2560,   332,   332, -2560, -2560, -2560,
   -2560,   332,   332, -2560, -2560, -2560, -2560, -2560,  1295, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
    8078,   153, -2560,   938,   346, -2560, -2560,   469, -2560, -2560,
     922,   355,   452, -2560, -2560, -2560, -2560, -2560,  7843, -2560,
     332,   523,   871,   332,  1221, -2560, -2560, -2560,   332, -2560,
   -2560,   467,  1037, -2560, -2560,   578, -2560,   588, -2560,   564,
   -2560, -2560,   595, -2560,   600, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,   617, -2560, -2560, -2560,   346,  1451,
    1026, -2560,   150, -2560,   346, -2560,   173, -2560, -2560, -2560,
      96, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   467,
   -2560,  1037, -2560, -2560,   626, -2560,   635, -2560,   653, -2560,
   -2560,   688, -2560,   712, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560,   716,  1130,   332,   749, -2560,  1221,  1221,   758,
     332, -2560,    -7, -2560,   589,  1047, -2560,   605,  1167,  1214,
    1225,   332,  1229,  1233,  1258, -2560,   673, -2560,   939, -2560,
   -2560, -2560, -2560, -2560,   346, -2560,   346,   854,   156, -2560,
   -2560, -2560,  1300, -2560, -2560,  1307, -2560, -2560, -2560, -2560,
   -2560,    -7, -2560, -2560, -2560,  1323,  1326,   355,  1229,  1337,
    1345,   760, -2560,  1330, -2560,  1008,   987, -2560,  1051, -2560,
   -2560, -2560,   816, -2560, -2560,  1412, -2560,  1023, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,  1167,  1023, -2560, -2560, -2560,
   -2560, -2560, -2560,  1046,   184,   251,   168, -2560,  2154, -2560,
   -2560, -2560,  1021,  1480,   273,  1102, -2560, -2560,  1451, -2560,
     346,  1041, -2560, -2560,   882,  1481,  1262,   276,   307,   316,
    1114,   352,  1153, -2560, -2560, -2560,   332, -2560, -2560,   332,
    1193, -2560,  3664,   452,  4851,  2592,  -214,   332,  1536,    17,
   -2560,  1047,  1544, -2560, -2560, -2560, -2560,  1550, -2560,  1557,
   -2560,  1561, -2560,   332, -2560,   332, -2560, -2560,  1229,  1576,
   -2560, -2560, -2560, -2560,   166,   346,  1584,    17,  1185,  1590,
   -2560,  1604, -2560, -2560, -2560,  1612, -2560, -2560, -2560,  1027,
    1257,  1643, -2560,   332,  1263, -2560, -2560, -2560,   332,   141,
     332,   332,   141,   141,   976,   332, -2560,   332, -2560, -2560,
     332, -2560,   942, -2560, -2560, -2560,   141, -2560, -2560, -2560,
   -2560,   332, -2560, -2560, -2560, -2560,   119,   119,  7022, -2560,
   -2560, -2560, -2560, -2560,   141, -2560, -2560,   141, -2560, -2560,
     332, -2560, -2560,   141, -2560, -2560,   258,   141, -2560, -2560,
    7022,   141,   258,   332,   258,   141, -2560, -2560,   108,   141,
     141,   108,   141,   332,   108,   141, -2560,   141,   141,   141,
   -2560, -2560, -2560, -2560,   258,   141, -2560, -2560,   141,    32,
     332, -2560, -2560, -2560, -2560,   141,  1101, -2560, -2560, -2560,
     141, -2560,  8124,   258,  7022, -2560,    37,    37,   141, -2560,
   -2560,  1109,   258,  1117,  7022,  7022, -2560,   841,  7022,   141,
      46, -2560,  7022,   141,  7022,   258, -2560,   141,  7022, -2560,
    7022,   119,   332,   141,   332,    37,   141,   332,    37, -2560,
     332,   303, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   128,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   599,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
     825, -2560,   332, -2560,   407, -2560,  1266, -2560, -2560, -2560,
    1362, -2560, -2560,  1275,  1277,  1283,  1284, -2560, -2560,  1053,
    1673,  1290, -2560,   169, -2560,  1381, -2560,  1294,  1296,  1062,
    1299,   332, -2560,   332,  1302, -2560,   290,  1261, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,  1076,  1454,  1242,
   -2560,  1085, -2560,  1092, -2560,  1702,  -236,   372, -2560, -2560,
   -2560,  1287, -2560,  1461, -2560,  1237,   152, -2560, -2560, -2560,
    1464, -2560,  7022,  7022,  7022, -2560, -2560,  1288,  1191,  1289,
    1293,  1308,  1317,  1331,  1334,  1336,  1342,  1344,  7022,  1231,
    1346,  1347,  1349, -2560,  7022,  7022,  1350,  1352, -2560,  7022,
    1353, -2560,  1358,  1361,  1367,  1369,  1370,  1372,  1373,  1376,
    6351, -2560,   127, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,   927, -2560,  1304, -2560, -2560,
   -2560, -2560, -2560, -2560,   258, -2560, -2560,  1461, -2560,   -49,
   -2560, -2560,  1448, -2560,   139, -2560,  1270, -2560, -2560, -2560,
   -2560,  1754, -2560, -2560,  -275, -2560,  1149, -2560,  1157,  1754,
   -2560,  1196, -2560, -2560,  1387,   114, -2560,  1351, -2560,  1142,
   -2560, -2560,  1388, -2560,  -122, -2560,  1160,   722,  -118, -2560,
    1076,  1494, -2560,  7022,  7022, -2560,  1812,   141, -2560, -2560,
   -2560, -2560, -2560,   279,   279,   279, -2560,   279,  1785,   279,
     279,  1226,   -49,  1226,  1226,  1121,  1121,  1226,  1226,   -49,
   -2560,  1818, -2560,    16,  1820, -2560,   -49, -2560,  4156, -2560,
     104,    53, -2560, -2560,  7022, -2560, -2560, -2560, -2560, -2560,
     978, -2560, -2560,   452,  1446,   452,  7022, -2560,    71, -2560,
   -2560,  7022,  1404,  1406,  1407,  1413,  1495,  1414,  1117,  1361,
   -2560,  1502,  1011,  1252, -2560,  1268, -2560, -2560, -2560,  1134,
   -2560,  1840, -2560,  1836,   332, -2560,   272,   182,  1276, -2560,
   -2560,  1849, -2560,  1197,  1849,  1851,  1205,  1849,  1851,  7022,
    1849, -2560, -2560,   152,   258, -2560, -2560,  1445,   781, -2560,
   -2560,  1436,   258,  7022,  1438, -2560, -2560,  1842,  1843,  1806,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  1177,  1177,
     141,   141,   141,  1434, -2560, -2560,  1783,   825, -2560, -2560,
     671, -2560, -2560, -2560,  1418, -2560, -2560, -2560, -2560,  8078,
    1229, -2560, -2560,  1420, -2560,   380, -2560, -2560, -2560, -2560,
   -2560, -2560,  1221, -2560, -2560,  1221,   741,   157,  1852, -2560,
   -2560,   315,   236,   480,  1874, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560,  1508,  1454,  1092, -2560,   976,  -174,   979,
     332, -2560, -2560,   332, -2560,  1303,  1265,  1310,  1459, -2560,
    1473,    72, -2560, -2560, -2560,  6420,  1516,  1516,    37,  7022,
   -2560,    37,    37,    37,    37,  1443,  7022,  1503,  1380,  7022,
    6351,  1477, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  1291,
      37,  1887,  7022,  4318,  6351,  1443,  7022, -2560,  6351,  1894,
     234, -2560, -2560, -2560,  7022, -2560,  7022,  7022,  7022,  7022,
    7022,  7022,  7022,  7022,  7022,  7022,  7022,  7022,  7022,  7022,
    7022,  7022,  7022,  7022,  7022,  7022, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560,  7022,  7022, -2560, -2560,
    1499,  7022, -2560,  7022,  1500, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   332,   258,
   -2560,  1306,  1505, -2560, -2560, -2560,   976,  1188, -2560,  1188,
    1117,   108,  7022,  7022,  7022,  1506, -2560, -2560,   258,   258,
   -2560,  1316,  1117,    37,  1281,   332,   346,    39,    32,   258,
   -2560,  1322,  7022,  1598, -2560, -2560,  1392, -2560, -2560,  1945,
   -2560,   133,   152, -2560, -2560,  1933,  1936, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560,  2186, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560,  8124, -2560,  1121,  7022,   -63, -2560, -2560,
    1947, -2560,    37,  1931,  1934, -2560, -2560, -2560, -2560, -2560,
      76, -2560, -2560, -2560, -2560,  1809, -2560,  1746, -2560, -2560,
   -2560,  7022,   119, -2560, -2560,   332,  1939,    37,    37, -2560,
    1384, -2560,    37,  1357,   258, -2560,   332,   332,  7022,    49,
   -2560,  1391, -2560,   250, -2560,  1493, -2560,  1501,  7022,  1091,
   -2560, -2560,  1365, -2560,  1975, -2560,  1439, -2560,   258, -2560,
   -2560, -2560,   976,   258,   179, -2560, -2560, -2560, -2560,   332,
      37,    37,   381,   781,  1838,  2073,   258,   152, -2560,  1450,
   -2560, -2560,  1945,  1963,  1599, -2560, -2560, -2560, -2560, -2560,
    1679,  1679, -2560,   164,  1455, -2560,   332, -2560, -2560,  1461,
    1461, -2560, -2560, -2560,   332, -2560,   332,   530,  1461, -2560,
     823, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,  1279, -2560, -2560, -2560, -2560, -2560,
     155,   155,   754,   980, -2560,   746, -2560,   671, -2560,  1221,
    1977, -2560, -2560,  1977, -2560, -2560, -2560, -2560,  1221, -2560,
   -2560,  1461, -2560,   733, -2560,  1578, -2560, -2560,   733, -2560,
   -2560, -2560,  1582,  1583,   109,  1586,  1587,  3783, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,   332, -2560, -2560,   109,  1343,
   -2560,   290, -2560,  1623,   153,  1398, -2560,  1117,  1442, -2560,
   -2560,  1563, -2560, -2560, -2560,  1476, -2560,   332,   332,   332,
   -2560, -2560, -2560,   383,  6351,  1635,  1640,   384,   398,   530,
    1644,  5474,  1646,   -95,  1335, -2560, -2560,   144,  1649, -2560,
   -2560, -2560,  5510,  2007,  1231,   420,  1650,  5541, -2560,  1653,
    2585,  1662, -2560,  7022,  7022,  7022,  5646,  7022,  5672,  5795,
    6096,  3364,  4791,  6420,  6569,  6690,  6911,  7454,  2941,  5605,
    7267,  7385,  1516,  1516,  3443,  3615,  4284,  6351,  6137,  6245,
    1443,  6351,  6297,  1443,  7022,  1624, -2560,   332, -2560,  1440,
   -2560, -2560, -2560, -2560,  1429, -2560,  2055,  2058, -2560,  2059,
    1486,  7022, -2560, -2560,  1447,  2062, -2560,  1588,  1444,  1851,
   -2560,  1685,   454, -2560,  1651, -2560, -2560,  1458,  1033,   332,
   -2560, -2560,  1654,   141,   931,  7022, -2560,   332,   332,  7022,
      34,   -49,  2074,  2070,  2060,  2061,  1785, -2560, -2560, -2560,
   -2560, -2560,   258,  1549,  4156, -2560, -2560, -2560,  2020,  7022,
     452,  1000, -2560, -2560,  1766,  2084,  2087,   422, -2560,   424,
     332,  1707,  1117, -2560,  7022,  1669,  1670, -2560, -2560,  1743,
   -2560,  7022,   354, -2560,  1507, -2560, -2560,   231, -2560,  7022,
   -2560, -2560,  1487,   938, -2560,  1200,   332,  2091,  7131, -2560,
   -2560,  1687, -2560,  1694,  2110, -2560, -2560, -2560,    26, -2560,
    1851,  1851,  1457, -2560,  1567,  1572, -2560, -2560, -2560, -2560,
      37,    37, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  1698,
   -2560, -2560, -2560, -2560,    37,  7976,  2114,  2094, -2560,  1117,
     317,   297,   140,  2021,   -17,  1109, -2560,    85, -2560, -2560,
   -2560,  1693,   241,  1461,   187, -2560,  1509,  1504, -2560, -2560,
   -2560, -2560, -2560,   674, -2560, -2560, -2560, -2560,  1695,  1511,
    2120, -2560,  1517, -2560, -2560, -2560, -2560,   258,   118, -2560,
   -2560, -2560,  1492,   980, -2560,   332,   332, -2560, -2560,   332,
     528, -2560, -2560, -2560, -2560,  1708,  1711, -2560,  1680, -2560,
    1681, -2560,  1703,   425, -2560,  6836,   430,    78,    78,   431,
   -2560,    78,  6836, -2560, -2560,  1375,  1375, -2560,  1712, -2560,
    1722,  1723, -2560,  1725,  1726, -2560,  1728, -2560, -2560, -2560,
     225, -2560, -2560, -2560,   433, -2560, -2560,   434,   332, -2560,
   -2560,   979,  2150,  1117,   346,  7022, -2560,  2155, -2560, -2560,
   -2560, -2560,   109, -2560, -2560, -2560, -2560, -2560, -2560,  7640,
   -2560, -2560,  1231,  1231,  2136, -2560,  2137,  1575,  1537, -2560,
    1191,  1775, -2560, -2560,  1191, -2560, -2560, -2560,  1776,  1191,
    6351,  6351,  6351,  1191,  6351,  1191,  1191,  1191,  2142,  2148,
    2152,  7022,  1789,  2156,  7022,  1792, -2560,  2170, -2560,  6351,
   -2560,  1564,   109,    70, -2560,  1117,  7022,  7022,  7022,  6624,
    2182,    57, -2560, -2560,  1117, -2560,  1569,   332,   332, -2560,
   -2560,   332,   332, -2560,   967, -2560, -2560,   916, -2560,  1573,
    7022, -2560, -2560, -2560,  2183, -2560, -2560, -2560, -2560, -2560,
     332,  1851, -2560, -2560,  1642, -2560, -2560,   435, -2560, -2560,
   -2560,   258, -2560, -2560,  4101, -2560, -2560, -2560,  1872,  2175,
   -2560,    37,  1858,  1859,  1749,  1589,  1860,  1781, -2560, -2560,
   -2560,     1,  1853, -2560, -2560, -2560, -2560,  1743, -2560, -2560,
   -2560,   204,   818, -2560, -2560, -2560,  1945,  7022,  1793, -2560,
    1759, -2560, -2560, -2560,  3957,  3957, -2560,  1076, -2560, -2560,
    1375, -2560, -2560,  7556,  1790, -2560, -2560,  1795,  1797, -2560,
    1798,  1799,  1821,  1823,   332,   537, -2560,  2213, -2560, -2560,
   -2560, -2560, -2560,  2151, -2560, -2560,   976,   258,   258,    54,
    1591, -2560,  2227,   -49,   332,  1777,  1777,  1777,  1777, -2560,
    2249, -2560,  2251,  1777,  1777,  1777,  1777,  2186, -2560, -2560,
    1777,   122, -2560, -2560, -2560, -2560,  2233,  2248, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,  2252, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,   447, -2560, -2560, -2560,  2239,
   -2560, -2560,  1461, -2560,   530, -2560, -2560, -2560, -2560, -2560,
   -2560,  1672,  1675,   115, -2560,    85, -2560,    78,  1657,   141,
    6836, -2560, -2560,  1845, -2560, -2560, -2560,   332,   332,  7640,
     201, -2560,  7022, -2560,  7022, -2560, -2560, -2560, -2560, -2560,
   -2560,   141,    78, -2560,  1461,  1007,  1658,  1659,  2271, -2560,
    2276, -2560,   258,   332,   755,   755, -2560, -2560,  2277, -2560,
    2277,   538,   538,  2277, -2560, -2560,  2592, -2560, -2560,  2968,
      84, -2560,  2592,  2096, -2560,    84,    78,   733, -2560,  7245,
    1855,  4753,  1855,   216,  2280, -2560, -2560, -2560, -2560, -2560,
   -2560,   382, -2560,  1461,   603,  1899,  2285,  1674, -2560, -2560,
     449, -2560,   109, -2560,   450,   259, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560,  1667,   324,  2274,  2274,  2275,  2274,  2274,
    2279, -2560,   209, -2560,   733,   332, -2560,   109, -2560, -2560,
    1688,  1117,  2298,   176, -2560,   332,   457, -2560,  7022,  1918,
     123, -2560,   332, -2560,  1689, -2560,  1922, -2560,  2289, -2560,
    1727, -2560, -2560, -2560, -2560, -2560,  1696, -2560, -2560,  1928,
    1929,  1930, -2560,  1937, -2560, -2560, -2560, -2560, -2560, -2560,
    6351,   462, -2560, -2560,   472, -2560,  1938,  7022,  7022,  2302,
     473,  1117,  2321, -2560, -2560, -2560, -2560,  7022,  1763,  2057,
    7022, -2560, -2560, -2560, -2560,  1235,  1941,   916,  1068,  1068,
    2327,     3, -2560,  2328, -2560, -2560, -2560,  1068,   332,  1788,
    1245,  2331,   332,  -121,  7022, -2560, -2560,  1785, -2560,  1567,
    7022, -2560,  2332,  7022, -2560,   258, -2560,   942,   332,   258,
   -2560,  1949,  7022,  7022, -2560, -2560,     1,  1853, -2560,  2186,
   -2560, -2560,  1238, -2560, -2560,  1770, -2560,   346,  6810,  1765,
    1765, -2560,  1718,   530,  1954,   388,   550,  7640,   550,   550,
     550,   550,  1729,  7640,  7131,  7640,  7640,  7640,  7640, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560,  1907,   985, -2560, -2560, -2560,  1730, -2560, -2560, -2560,
   -2560,    37,  1777,    37,  1777, -2560, -2560, -2560, -2560, -2560,
   -2560,   -49, -2560,  1017,  1022,  7976, -2560,  1962,  1924,  7640,
    1279,   140,   140, -2560, -2560, -2560, -2560,   477, -2560,  1884,
   -2560,  2349,    78,   677, -2560,  1731, -2560,  2352,  7666,  7666,
    7666,  7666,    78,    78, -2560, -2560, -2560,  1805, -2560,   482,
   -2560,  1734, -2560,   332,   332,  1517,   258, -2560,  2277, -2560,
   -2560,   332,   538,   538, -2560, -2560,   538,  2153,  1737,  1738,
   -2560, -2560,   119,   119,   119,  2338,   119,   119,   119,   119,
     119,   119,  2339, -2560,  2340,   119, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,  2968, -2560,   258,  1748, -2560,  1923,
    2153,  2344, -2560,  2345,  2346,  2347,  2348,  2350,  2355,  1256,
    2096, -2560,  1923, -2560,   485, -2560, -2560,  1901, -2560,   263,
     301, -2560,  6836, -2560,  6836, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,  3957,  1953,  3957,  1955,   680,  7640,
   -2560,  2357, -2560,  2092,    78,  1248,    78, -2560, -2560, -2560,
   -2560,  1397,  2360,  1397, -2560,  2383,  2383,   486,  1999,  2383,
   -2560,  2001, -2560, -2560, -2560,   733, -2560, -2560, -2560, -2560,
    1117, -2560, -2560,   109,  2126,  1945, -2560,  7640,   245,  1869,
     427, -2560,  1424,  1231,  1808,  1571, -2560, -2560, -2560, -2560,
   -2560,  7022, -2560, -2560, -2560, -2560, -2560,  1932, -2560,   223,
    1117, -2560,  2393,  1974, -2560, -2560,  2014, -2560, -2560, -2560,
    1856, -2560, -2560,   332,  1068,   346,  1292,   332,  1068, -2560,
   -2560,    37, -2560, -2560,  7022, -2560, -2560, -2560,    37,  1945,
     258,  2168, -2560,   -49,  6351,  2385, -2560, -2560,   152,  1983,
   -2560, -2560,  7022, -2560, -2560,  2024, -2560, -2560, -2560,   818,
   -2560,  1567, -2560,  7022, -2560,   183, -2560,  1820, -2560,  1397,
    7640, -2560,   296,  2026,  2413, -2560, -2560, -2560,  7640, -2560,
     488,  7640,  7640,  7640,  7640,   332,   495, -2560, -2560, -2560,
   -2560, -2560,  7022,  1981, -2560,  2079, -2560,  2404, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   332,
   -2560,    99, -2560, -2560, -2560,  1279,    78, -2560,   530,  2287,
     499, -2560, -2560, -2560, -2560,   332,  1875,  7355,  7355, -2560,
   -2560,  7801,  2002, -2560, -2560,  2003,  2006, -2560,  2010,  2011,
    2013,  2015,   332,   563, -2560, -2560,   503, -2560, -2560,  2538,
   -2560, -2560, -2560,   504,  2425,  2425, -2560, -2560,   506,  2438,
    2431, -2560,   255, -2560, -2560,    78, -2560,   105,  1827, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560,  2240,  8078, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560,   333,  2443, -2560,   258,  1371, -2560,  2240,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560,  2280, -2560,  2017,  2151,   217, -2560,  2017,
     217, -2560,  3957, -2560, -2560,  7640, -2560,   203, -2560, -2560,
   -2560,  1993, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560,  2063, -2560,  2428,  2065,  2068,  2433, -2560, -2560,  2071,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,   213,  2446, -2560,
   -2560,   332,  2093,   332,  1844,   550,  2133, -2560,  2038, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,  1577, -2560, -2560,
   -2560,  6351,  2085,    37,   -49,  2102,  1117, -2560,  7022, -2560,
    1908,  2453,   -49, -2560, -2560,   782, -2560, -2560, -2560, -2560,
     145,  2095,  1851,  2110,  2242, -2560,  2097,  2098,  2074,  2054,
   -2560,  2139,  2100, -2560, -2560, -2560, -2560,  2246,  2034, -2560,
     123,  1375,  1867, -2560,  1375,  2109,  7640, -2560,  2112,  2113,
    2115,  2116, -2560, -2560,  1925, -2560, -2560, -2560,  1567, -2560,
     510, -2560,   258,  1958,  1279,  1279, -2560, -2560,  7640, -2560,
   -2560,    78, -2560,  2082, -2560,  1958,  2053,  2053,  2118,   388,
     550,  7853,   550,   550,   550,   550,  1893,  7853,  7666, -2560,
    7853,  7853,  7853,  7853, -2560, -2560,    78,  2499,    78,  7666,
     141,  6836, -2560,   258, -2560, -2560,   321, -2560, -2560,   332,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,   258,  2443, -2560,
   -2560, -2560,   258, -2560,   258, -2560, -2560,  1417, -2560,  2281,
   -2560,  2282,   209, -2560,   512, -2560, -2560, -2560, -2560,   513,
    2017,  2507,  2492, -2560, -2560,  1896, -2560, -2560, -2560, -2560,
    2135, -2560,   245, -2560,   245, -2560, -2560,  7640, -2560,  2077,
   -2560,  2126,    64,   297,   332,  2500, -2560, -2560, -2560, -2560,
   -2560,  1117, -2560,  2143,  8087,  2104, -2560, -2560, -2560,  1916,
     -49, -2560, -2560,    42, -2560, -2560, -2560,  2146,   152, -2560,
    2139,  2139,   818, -2560,   346,  2147,  1914,  1397,  1915, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,   332, -2560,  2110,
     427, -2560, -2560,   123, -2560,  7570,   427, -2560,  2157,  7853,
   -2560,   522,  7853,  7853,  7853,  7853,   332,   524, -2560, -2560,
   -2560, -2560, -2560, -2560,  2119, -2560, -2560, -2560,  2349,  2110,
     105, -2560, -2560, -2560, -2560,  1739,  1739, -2560,  1739, -2560,
    1739,  1739, -2560, -2560, -2560, -2560, -2560, -2560,   264, -2560,
   -2560, -2560,  7640,  2124,  1397, -2560, -2560,   540, -2560,  2536,
   -2560, -2560,  6836, -2560, -2560, -2560, -2560,  2539, -2560,   404,
   -2560, -2560,  2126,  2161,   982, -2560, -2560,   279,   279,   279,
     279,   279,   279, -2560,  2518, -2560,   544, -2560,  7022,  1360,
   -2560, -2560, -2560,   683, -2560,  2139,  7022,  2139,  2074, -2560,
   -2560, -2560,  2305,   253, -2560,  1397, -2560,  1397,    26,   -49,
   -2560, -2560, -2560, -2560,   551, -2560, -2560, -2560, -2560,  2162,
    7853, -2560,  2163,  2164,  2171,  2173, -2560, -2560,  7666, -2560,
   -2560, -2560,  1739, -2560,  1739, -2560, -2560, -2560, -2560, -2560,
   -2560,   245, -2560,  7640,  2349,    64, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,   775, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,  8087, -2560,  2559, -2560, -2560,   695,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,    54,
   -2560,  7570, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   558,
   -2560, -2560, -2560, -2560, -2560,   879,   879, -2560, -2560,   879,
   -2560,  7022, -2560,  2176, -2560, -2560, -2560, -2560, -2560, -2560,
    2177, -2560, -2560,   289, -2560,   152, -2560,  2074
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2560, -2560, -2560, -2560, -2560,   368, -2560,   463,  -184, -2560,
   -2560,  -852,     6, -2560, -2560, -1571, -2560, -2560, -2560, -2560,
    -535, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -1974, -2560, -1546, -2560,
     423, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   705, -2560,
   -2560, -2560, -2560,  1319, -2560,  1009, -2560, -2560,   -61, -2560,
   -2560,  2542, -2560,  2543,  2219, -2560, -2560, -2560, -2560, -2560,
     776,   408, -2560,   771, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,  -126,   905,   274, -2560, -2560,
    2300,   -16, -2560,  2448, -2560, -2560,  2449, -2560,  2399, -2560,
   -2560, -2560,  2329,  2212,  1249,  2326,  -318, -2560, -2560, -2560,
   -2560, -2560,  1253,  -983, -2560, -2560, -2560, -2560, -2560, -2560,
    -154,  2265,  2408,  -195,   857, -2560,  2250,   181, -2560,  2309,
   -2560, -2560, -2560, -2560,  2313, -2560, -2560, -2560, -2560,  -325,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  2253, -2560,
    2244, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  -901,
   -2560, -2560,  -457, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
    2169, -2560, -2560,  1097, -2560,  -819,  -854,    33, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560,   862, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,  -233, -2560, -2560, -2560, -2560,
   -2560,  2121, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -1727, -2560, -2560, -2560, -2560, -2560, -2560,  1213, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560,  1682, -2560, -2560, -2560,
   -2560,   981, -2560, -2560, -2560, -2560, -2560, -1268, -2560, -2560,
     971, -2560, -2560, -2560, -2560, -2560, -2560,  -782,  -594,   855,
    1123, -2560,  -491,   802,  -821,  1241, -2560,   959, -2560, -1835,
      -4,  -250, -2560, -2560, -1756,   492,  1108, -2560, -2560,   548,
    1368, -2560, -2560, -2560, -2560, -2560, -2560,   406, -2560,   116,
   -2560,  1377, -2560,  1058, -2560,   744, -2560, -2560, -2560,  -452,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,   872, -2560,
   -1263, -2560,  1056, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  1518, -2560,
   -2560, -2560, -2560, -2560, -2560,   -67, -2560, -2560, -1506, -2560,
   -2560, -2560, -2560,   660, -1777, -2560,  -811, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560,  2660, -2560, -2560, -2560,  2567,  2657,  -613, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,    41, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560,  2658, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,  1115, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560,  -428,  2214, -2560, -2560,
   -2560, -2560, -2560,  2043, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560,  1943, -2560, -2560,   -59, -2560, -2560,  1116, -2560,
   -2560, -2560,  -686,  -193,  2434, -2560, -2560, -2560, -2560,   747,
   -2560,  -714,  2019,  1409, -2216,   786, -2560,  1122,  1778,    65,
    -134, -2560, -2560, -2560,  1570, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,  1510, -2560,  1081, -2560,  -371,
   -2560, -2560, -2560, -2560, -2560, -2560,  -313, -2560, -2560, -2560,
   -2560, -2560, -2560,   487, -2560,  1585,   797, -2560, -2560, -2560,
   -2560, -2560,   358, -2560,  -125, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
    1847, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  -330, -2560,
    1496,  1665, -2560, -2560,   373, -2560,  -415, -2560, -2560,   390,
     693, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  -282, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2553, -2560,  1719,   953,  -979, -2560,
   -2560, -2560,  1354, -2560, -1346, -2560, -2560, -2560, -1348, -2560,
   -2560, -1336, -2560, -2560, -2560, -2560,  1382, -2560, -2560, -2560,
   -2560, -2560, -2560,   763, -2560, -2560, -2560, -2560, -2560, -2560,
    -374, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560,  -335, -2560, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,
     738, -2560, -2560, -2560,  -216, -2560, -2560, -2560, -2560, -2560,
   -2560,   356, -2560, -2560,   715, -2560,  1057, -2560, -2560, -2560,
   -2560, -2560, -2560,  -951, -2560, -2560, -2560, -2560, -1454, -2560,
   -2560, -2560, -2560, -2560, -2560, -2559,    55, -2560, -1843,   325,
   -2560, -2560, -1681,   385,   379,   717, -2560, -2251, -2139, -2560,
   -2560,    95,  -220, -2560, -2560, -2560, -2560, -1897, -2560, -2560,
   -2560, -1971, -2560, -2560,  -577, -2560,  -669,  1453,    94, -1507,
     713, -2560,   344, -2560, -2560, -2560, -2560,  -705, -2560, -1677,
   -2339, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -1996, -2560,
     464, -2560, -1401, -2560,  1814, -2560, -2560,  -849,  -115, -2560,
   -1516,  -113,   206,   490, -1115, -1404, -1972,   347,  -298, -1553,
   -1834, -2560,   556, -2560, -2560, -2560,  1484,  -516, -2560, -2560,
    -141,  1841, -2560,   723, -2560, -2560, -1271,   226, -2560, -2560,
   -2560, -2322,    -5, -2560, -2560, -2560,  1522, -2560, -2560, -2560,
   -2560, -2560, -2560, -2560, -2560, -2210,   -26, -2560, -2261, -2449,
   -1967,  -935, -2560, -2560,    -9,  -437,  -413,  -489,  1078,  -926,
      19,  1744,    79, -2560, -2560, -2560, -2560, -2560,  1661, -2560,
    -431, -2560, -2560, -2560, -2560, -2560, -2560, -2560, -2560,  -323,
    1498,  2458, -2560, -2560, -2560, -2560
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1805
static const short yytable[] =
{
      42,   268,  1031,   386,   258,   113,  1366,   883,   823,    57,
      59,   702,  1816,  1016,  1217,  1171,  1173,   284,  1858,    33,
    1230,  2075,   256,   131,  1399,  1749,  2115,  2297,   236,  2084,
    1604,  1605,   721,   417,  1059,  1912,  2211,  1199,  2603,  2604,
    2605,    74,    77,    33,  1028,  1377,    97,  1725,  1700,    70,
    2219,  2220,  1726,   805,  1966,  1647,  2174,   113,  1222,    41,
    1513,    41,  1179,  1180,    41,  1181,    41,  1201,  1202,   832,
     670,   291,   128,    41,  2692,    77,  1241,  1297,  2161,   140,
     338,  1216,  1026,  1982,    41,   127,   871,   137, -1803,  1026,
    3006,    41,  2607,   702,   144,   881,   690,    41,   149,   690,
     690,   151,   152,  1026,  2437,    41,  2271,   155,   156,  1222,
    1292,   299,   300,   690,   925,   275,  2249,   928,  1132,  1149,
     269,   276,   277,  2022,  1302,    97,   919,  1222,  2437,   201,
    1422,   690,    41,   798,   690,    41,    41,   127,  1525,   836,
     690,  1315,    41,   269,   690,   717,   232,   394,   690,   235,
    1222,   269,   690,  1125,   239,   266,   690,   690,   129,   690,
    2269,   266,   690,  1756,   690,   690,   690,    41,    41,   688,
    1757,   266,   690,   383,   266,   690,   269,   931,   932,    41,
    2769,   266,   690,  1986,    41,  1223,  1224,   690,   266,   379,
    2068,  2071,   273,   940,  2071,   690,  2112,   269,   270,   271,
      41,  1526,   673,  1527,   781,  1528,   690,   781,  2872,  1015,
     690,   292,  1281,  2222,   690,  1281,  1449,   790,  2356,  1293,
     690,   781,  2382,   690,   941,   781,  1137,  1138,  2735,  2210,
     296,    41,   807,   269,  2422,  1888,   302,   781,  1026,   790,
      41,   269,  1887,  1888,    41,   818, -1803,   330,   790,  2298,
    2299,  2300,  2301,  2302,  1574,   829,   381,  2669,   266,    82,
     835,  1208,  1209,    41,   344,  2382,   346,  2487,   873,  2382,
    1026,    97,    41,  1574,  2753,   833,   834,  2824,   389,   818,
    1542,   399,   868,   818,  2562,    41,   874,   818,   269,  1887,
    1888,    41,    63,   790,  2162,  1753,   790,    82,   728,  1632,
    1633,  2771,  1021,   559,   649,  1174,    41,  2561,  1816,  2291,
    2385,  2386,   401,  2387,  2388,  2389,  2390,  2391,  2392,  1319,
     392,   141,   881,  2996,    41,  2998,  2970,   269,   931,   932,
      41,  2531,  2532,  2533,  2534,  1156,  1613,   392,  3005, -1803,
    2224,    82,    41,  1142,    41,   941,   996,   997,  1214,   941,
    1143,  1022,   409,  1382,  2493,   409,  1592,   405,    63,    41,
   -1803,  1994,  1321,   409,   185,   186,  1383,  1596,  1282,  2958,
    2379,  1282,   187,    41,   998,   999,  1000,  1023,  1548,   330,
    2966,   330,  1253,   641,   651,  1364,  1525,  1568,  1222,  1222,
    1989,  2385,  2386,    82,  2387,  2388,  2389,  2390,  2391,  2392,
    1215,   941,  1407,  1222,  2830,   820,   698,   658,  2030,   409,
     652,  2033,    65,   697,   686,    41,   691,   692,  2868,  1399,
     699,   704,   303,   706,    71,  1222,   709,  1851,  1162,  1222,
    2047,  2091,  2508,   653,  1277,  2047,  2072,   692,  2095,  2097,
    2187,   659,  1408,    35,   775,  2695,  2112,    82,  2699,   304,
     384,  3154,  2275,   698,  2406,  2406,   692,  1995,  1532,  3089,
    2475,  2971,  2433,   687,  1575, -1803,   775,  2451,    82,   692,
    1617,   942,   259,   260,   261,   262,   263,  2451,  2433,   808,
    2288,   761,  2566,  1575,  2824,  2824,    82,  2615,   687,   687,
    2404,  2696,    82,  2776,  1754,   824,   826,  1157,  2380,  1163,
    2776,    79,   699,   791,  2801,  2310,    82,    41,  2818,  2818,
     775,  2826,   824,   824,   690,  2937,   943,  2988,  2988,   944,
     775,   775,  3132,   902,   775,  1405,    77,  3060,   775,  3060,
     775,  2286,  1543,  2870,   775,    82,   775,  2488,   920,  2068,
     920,   824,  1830,   920,   824,  3081,   920,   865,  2770,  3104,
    1425,  1426,  2393,  1236,  2179,  1239,  3121,   884,   890,  1382,
    2666,   906,  2666,  2818,  1972,   910,  2835,   912, -1803,  2796,
    2279,   916,  1383,   918,   380,   267,  2939,   698,  1983, -1803,
    1406,   341,  2285,  1584,  1385,  1327,  1378,   873,  3046,  1330,
    1314,   672,  1873,   821,   982,  2736,  2250,  2357,   403,  1634,
    1386,  2431,  2456,  1890,   702,   949,  2383,  1423,  2768,   908,
    1327,  1890,  1427,  1428,  2808,  1278,  2963,  2969,  1891,  2991,
     737,  1540,  2476,  2092,  1494,    34,  1891,  1258,  2873,  1445,
    1832,  1782,  3155,  2393,  1785,    76,  1508,   690,   690,   690,
     944,   382,  2882,  1225,   944,   741,  2151,  2496,   969,  2410,
    1641,  1642,  2792,  2662,  1361,  3080,  2504,  2505,  1890,  1652,
     984,  2076,  1362,   390,  2023,  1395,   400,   823,  2063,  2438,
    1150,  2394,  1922,  1891,  2529,  2063,  2765,   991,  3116,   409,
    2529,  1912,  2538,  2539,  2540,  2541,   933,  2223,  1242,  2063,
    2672,  2521,  1866,   799,   699,  2741,   944,   402,   822,  1489,
     822,    41,  1692,   822,  2557,  1514,  3117,    95,  3118,  1027,
    1312,   835,   873,  1495,  1228,   272,  2726,  2743,   775,   775,
     775,  2748,  1509,   702,  1382,  1838,  2112,  2296,  2395,   750,
    1226,  1545,  1283,  1758,   775,  1283,  2408,  1383,   272,  1762,
     775,   775,   406,  1001,  1384,   775,   272,  2427,  2077,    41,
    1529,  2428,  2394,  2412,  1922,  2318,  1558,  2713,  1530,  2707,
    1876,  1561,  1024,  2107,  1139,  2078,  1990,  1974,   132,   943,
    1365,   272,   139,  1744,  1747,   188,   945,   946,   947,  1175,
    2831,    41,  2522,  1027,  2303,  2571,  1297,   948,  1748,   934,
    1385,    44,   272, -1803, -1803, -1803, -1803, -1803,  2941,  2942,
     259,   260,   261,   262,   263,   136,  1386,  3129,  2079,  2395,
    1763,    41,  1852,  2107,  1853,  2048,  1279,  1559,  2893,  2520,
    2062,  2073,   755,  2096,  2098,  2188,  2943,  1553,   272,   775,
     775,  1002,  2009,  1176,   757,   758,   272,  2276,  2666,  2407,
    2409, -1803,   759,   130,  2950,  2772,  2676,  2434,  2080,  1280,
    2950,  2034,  2452,  2959,  2960,  2961,  2962,  2396,  1205,  1600,
    1601, -1803,  2453,  2458,   775,  1212,  1367,  2567,    41,  1369,
     775,  2844,  2616,   141,  1003,  2661,  2697,  2081,  2777,  1806,
    2563,  2564,   775,   272,  2112,  2783,  2082,   775,  1648,  2802,
    1370,  1732,  1251,  2819,  2825,   143,  2827,  2679,  1370,  2682,
    2938,  1221,  2989,  2990,  2470,    18,   145,   865,  2525,  1398,
    1269,    82,  3061,  2949,  3067,  2952,  2953,  2954,  2955,   884,
    2845,  2178,   272,  2397,  1244,   775,   194,  2925,  2673,    18,
    3082,  1298,  1571,   958,  3105,  2378,   195,  2381,  2396,   775,
    2714,  3122,  3086,    82,   959,   892,  3039,  3040,  3146,  2413,
    2940,  2715,   233,  2936,  1404,  1385,  2760,   259,   260,   261,
     262,   263,  2946,   182,  3110,    41,  2233,  2112,   710,    41,
      45,  1386,  1512,   198,  1993,  2775, -1803,  1613,  2778,  2779,
    2780,  2781,  3059,   234,    46,  3062,  3063,  3064,  3065, -1803,
    1654,  3087,  2817,  1379,   134,   893,   960,  1387,  1396,  1387,
    1410,   697,   241,    41,  2397,  1649,    41,   249,  1675,    47,
     699,   961,  3137,   699,  2001,  1411,  1414,   250, -1803,   706,
     134,   252,   687,  2002,   253,  2526,  1846,    41,  1371,   254,
      82,   652,   894,  1579,   824,   775,  1371,   824,   824,   824,
     824,   257,   775,  2553,    41,   775,  1857,  2003,  2555,    41,
    2004, -1803,   265,   971,   653,   285,   824,    48,   775,  2797,
    2401,  3112,   775,  3114,   286,  2674,  1298,  2675,  2005,  1613,
     775,  2255,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   924,  3124,  2926,   927,  2375,  2928,   930,  1831,
    3052,   962,   775,   775,  1372,  1159,   414,   775,  2834,   775,
     288,  1617,  1372,  1971,   656,  1650, -1803,   289,  1399,  1929,
    1931,  3091,  2871, -1803,  1485,  3092,   830,    82,    41,   895,
    1809,    82,   699,  1810,   875,  2527,    41,  1667,   775,   775,
     775,   290,   881,  2426,    41,   294,    81,  2568,    41,   824,
    2968,  1511,  1676,  1515,   824,  2572,   295,  2175,   775,  1262,
     684,    41, -1803,  1640,  2798,   698,    34,    35,  2290,  1644,
    1373,  1677,  1678, -1803,  2006,  1496,  1497,  1498,   297, -1803,
     783, -1803, -1803,  2595,  2595,  2595,  2595,   301,  1743,    82,
    2308,  1679,  1419,  1941,   792,  1520,  1809,   735,   797,  1810,
     690, -1803,  1308,  1617,    41,   896,    82,  2909,  1374,   736,
     811,    82,   775,  1490,   306,    41,  1374,  2102,   824,  1016,
    1845,  1879, -1511,  2930,  1375, -1803,  1675,    41,  2007, -1803,
     315, -1803,  1375,  1683, -1803,  2008,  1811,   775,   715,  1812,
     324,  1555,  1689,   824,   824,  2112,   897,  1781,   824,  1541,
    1784,   325,  1565,  1566,   775,   331,  2467,   785, -1803,   334,
    1655,  1613,    41,  2510,   775,    41,  2482,     2,     3,  2680,
     794,  1656,    41,  1821,   884,    41,  1613,  2152,   699,  2153,
    2668,  2657,  2671,    41,   335,   920,   824,   824,  2164,  2435,
     698,  1567,   336,  1657,  2944, -1803,   133,   134,    82,  2524,
    1658,  1582,  1811,  2278,   274,  1812,    82, -1803,   279,   690,
      82,   340,  1636,  2746,   898,  1027,  1027, -1803, -1803,    41,
    1645,  3084,  1645,    82,  1027,     1,   342,  1613,  3091,   337,
     690,   907,  3092,   343,  3001,   911,    81, -1803,    41,   915,
   -1803,     2,     3,     5,     6,  2311,     7,     8,   984,   347,
     102,     9,   348,   752,  1434,   103,  1127,     2,     3,  1435,
    2194,  1437, -1803,   351,  2517,  2489,    82,  1027,    10,    11,
    1676,   352,  2602,  2602,  2602,  2602,  2492,    82,   899,   353,
    1387,  3107,   835,   133,   134,  3010,    12,    41,   354,  1677,
    1678,  1396,  3056, -1803,  1387,  1617, -1803, -1803,   357,  1434,
     104,   105,  -266,   873,  1435,  1436,  1437,  3031,   106,  1679,
    1617, -1803,   307,  1739,  1740,  1741,   358,     5,     6,  2552,
       7,     8,   754,  2327,  3051,     9,    58,    82,    41,  2360,
    3057,   756,  2849,     5,     6,   368,     7,     8,   369,  3078,
    1255,     9,    10,    11,  1655,    82,   387,  1128,   813,   775,
     775,   775,   372,   775,  2703,  1656,    13,   819,    10,    11,
      12,  1617,  2595,  2595,   964,   965,  2595,   133,   134,   259,
     260,   261,   262,   263,  2701,   377,    12,  1657,  2123,   697,
     775,    41,  2125,  1791,  1658,   388,  1026,  2128,    41,  -266,
    3113,  2132,   391,  2134,  2135,  2136, -1803,   775,   395,   308,
      82,   396,   923,  2246,  2850,   926,  -266,   397,  3096,  2416,
    2108,  2418,  2419,  1206,  1207,  1819,   309,  1210,  1211,   398,
    1249,   775,    41,  1826,  1827,   775,   824,  3031,  1432,  1433,
    3001,  1256,   316,  1402,  1800,    41,  1092,  1093,  1094,   404,
     775,  2103,  2016,   407,    41,   775,    13,  1583,   134,  -266,
    2850,  1095,  1316,   415,   718,   718,  1855,   657,  1825,   310,
     775,  2119,  1498,  2120,  2121,  1662,  1663,   775,  3056,  2851,
     662,  2852,  1032,  1033,  1034,   775,   664,  1221,  3010,  1822,
    1823,  1880,  1269,   665,  1905,  2429,  2853,   666,  3096,  -266,
    1231,  1232,  1233,  1234,  2854,  2728,  1051,  2729,  2855,   311,
    2184,  2896,   671,  2897,  1865,   674,   824,   824,  1096,  1097,
    1098,  1099,  1100,  1101,   676,  2851,   677,  2852,  -266,   317,
     824,  1670,  1671,  2856,  1102,  1103,  1104,  -266,   312,  1491,
     678,  1491,  2853,   945,   946,  2459,   318,   313,   680,  1027,
    2854,  2755,  2806,  2807,  2855,  2843,   681,   682,   683,   718,
    2218,  2602,  2602,   685,  1317,  2602,   973,    16,  2017,   935,
     690,   107,  1318,   974,   696,   975,   690,   976,  1319,  2856,
    1320,  2029,  2029,   977,   978,  2029,   979,   714,   980,   319,
     981,  1321,   983,  1052,   987,   989,   988,   108,   690,   990,
    1013,  1905,   994,  2064,  2064,  1014,  2595,  2064,  1905,   134,
    1053,  1017,  2595,  2595,   786,  2595,  2595,  2595,  2595,  1322,
    1020,  1019,  1025,  1136,  2595,  1029,  1039,  1038,  1041,   320,
     803,   804,  1042,  1129,  2099,  1323,   810,  1411,  1140,   812,
    1324,   775,  1606,   835,  1607,  1608,  1609,  1043,  1387,   873,
    2076,  2867,  1325,  1054,  2867,  1905,  1044,    16,   321,  1326,
      50,    51,    52,    53,    54,    55,    56,   322,   109,  1141,
    1045,   873,  2683,  1046,  1105,  1047,  1144,  1106,  2104,  2711,
    2548,  1048,  2550,  1049,  1145,  1060,  1061,   775,  1062,  1065,
     775,  1066,  1069,  1055,  2758,  2237,  2238,  1071,  1387,  2718,
    1072,  1147,   775,   775,   775,   775,  1073,  2064,  1074,  1075,
    1153,  1076,  1077,  2166,  1819,  1078,  1148,  2171,  2171,  1152,
    1182, -1803,  1056, -1803, -1803, -1803,   775,  1155,  1158,  1167,
    1172,  1057,  1203,  1213,   935,  1216,  2183,  2077,  1237,  2154,
    2155,  1498,  2158,  1245,  2595,  1246,  1247,  2595,  2595,  2595,
    2595,  1257,  1248,  1252,  2078,  1254,  1258,   824,  1266,  2684,
    1268,  1288,   110,  2181,  1289,  1290,  1222,  2239,  2240,  2241,
    2242,  2243,  2244,  1291,  1296,  1300,  2685,  1303,  1304,  1305,
    1126,  1306, -1803,   775,  1352,  1360,  2719,  1363,  1381,  1401,
    1905,  1905,  2900,  2524,  1418,  2602,  1107,  2079,  1420,  1905,
    2908,  2602,  2602,  2720,  2602,  2602,  2602,  2602,  1417,  1419,
    2232,  1108,  1421,  2602,  1327,  1109,  1443,  1016,  1446,  2686,
    2215,  1328,   699,  1429,  2702,  1451,  1444,  2629,  2630,  2631,
    2256,  2633,  2634,  2635,  2636,  2637,  2638,  2080,  1480,  1483,
    2641,  1487,   111,  1329,  1488,  1501,  2721, -1803,  1330, -1803,
     112,  1507,  1228,  1110,  2737,  2595,  1519,  1521,  1523,  2687,
    1525,  1534,  1544,  2595, -1803,  1535,  2081,  1546,   690,   690,
    1547,  1549, -1803,  1551,  1556,  2082, -1803,  1610,  1027,  1571,
    1611,  1111,  1612,  1560,  1578,   649,  2722, -1803,  2688,  1562,
    1586,   649,  1580,  2064,  1585,  1588,  1905,  2689,  1298,  1626,
    1112, -1803,  1613,  2294,  1645,  1905,  1624,  1627,   775,  1629,
     775,  1635,  1614,  1684,    89,  2723,  1728,  1695,  2064,  2967,
    1027,  1697,  1698,  1730,  2724,  1701,  1702,  1731,  1733,  2029,
    1734,  1938,  1735,  2602,  2515,  1745,  2602,  2602,  2602,  2602,
    1746,   835,   835,  1761,  1750,  2305,  1752,  2306,  2711,  1759,
    1764,   935,  2064,  1766,  1615,  1905, -1803,  1905,  1616, -1803,
    2750, -1803,  1769,  1790,  1795,   651,  1793,  2752,  3030,  2064,
    1796,   651,  2867,  1797,  1798,  1799,  1801,  1802,  1387,  1804,
    1803, -1803,  1113,  2822,  2823,  1805,   183,   191,  1833,  1297,
    1807, -1803,  1808,  1820,  1840,  1843,  1835,  1836,  1183,  1849,
   -1803,  1396,  1850,  1387,  1184,  1185,  1186,  1856,  1859,  1860,
   -1803,  1739,  1863,  1869,   775,  1883,  1916,  1606,  2441,  1607,
    1608,  1609,  1877,  1917,  1187,  1918,   948,  1922,  1924,  1969,
    1970,  1981,  1987, -1803,  2012,  2015,  1617, -1803,  1997,  1998,
    2026,   191,  2046,  2037,  2602,  2014,  2038,   191,  1114,  2039,
    2043,  2085,  2602,   775,   775,  2239,  2240,  2241,  2242,  2243,
    2244,  2086,  2087,   775,  2088,  2089,   775,  2090,  2101,   385,
    2105,  2468,  2116,  2117,  2118,  2124,  2127,  2137,     1,  2235,
    2236,  2237,  2238,  2138,  1819,  2147,  2483,  2139,  2485,  2142,
     775,  2143,  2145,  2149,     2,     3,   775,  2160,  2165,   775,
    2461,  2182,  2180,  2466,  2500,  2185,  2191,  3120,   775,   775,
    2192,  2195,  2196,  2199,  3038, -1803,  2197,   191,  2198,   191,
    2200,  1182, -1803,  2711,   775,  2711,  2217,  2216,  2234,  2225,
    2902,   699,  1188,  1905,  2226,  1189,  2227,  2228,  2229,  1905,
    1905,  1905,  1905,  1905,  1905,  3097,  3098,  3099,  3100,  3101,
    3102,   947,  2899,  2239,  2240,  2241,  2242,  2243,  2244,  1190,
    2230,   865,  2231,  2254,  2261,  2361,  2263,   824,  2272,   824,
       5,     6,  2273,     7,     8,  2277,  2274,  2281,     9,  1191,
    2282,  2362,  2363,  2289,  2292,  1905,  2315,  2313,  2314,  2364,
     935,  2316,  2321,   191,  2377,    10,    11,  2384,  2064,  2403,
    2404,  2745,  2411,  2405,  2593,  2593,  2593,  2593,  2064,  2064,
    2414,  2417,  2842,    12,  1192,  2420,  2430, -1748,  2436,  2618,
    2619,  2017,  2443,  2365,  2442,  2444,  2445,  2622,  2447,  2448,
    2449,  2446,  2366,  2457,  1193,  1194,  2460,  2450,  2454,  2462,
    2463,  2469,  2473,  2477,  2481,  1195,  2484,  2495,   191,  2503,
    1196,  2513,  1610,  2519,  2521,  1611,  2544,  1612,  2535,  2547,
     718,  2367,  2558,  2559,  2568,  2382,  2575,  2437,  2613,  2617,
    2627,  2628, -1803,  2632,  2639,  2640,  2646,  1613,  2647,  2650,
    2651,  2223,  2652,  2653,  2654,   712,  2655,  1614,  1905,  1197,
    1905,  2656,  2667,  2677,  2670,  3015,  2691,  1371,  2693,  2698,
    1905,  2700,  1905,  2704,  1990,  1905,  2368,  2727,  2738,  2733,
    2064,  2681,  2064,  2739,  2740,   935,  2741, -1803,  2759,   788,
    2756,  1198,  2711,   159,  2763,   793,  2773,   795,  2774,  1615,
   -1803,   802,   942,  1616,   802,  2788,  2799,   802,  2792,  1387,
    2818,  2809,  2810,  1905,  1027,  2811,  2423,   814,  2369,  2812,
    2813,  3157,  2814,  2828,  2815,  2829,  2839,   775,  2847,  2840,
    2401,  2884,   160,  2875,  2876,  2878,   863,  2862,  2879,  2880,
    2887,  2881,  2892,  2894,   876,   879,   882,  2895,  1358,  2171,
     903,   161,  2747,  2171,  2901,  2898,  2905,   824,   913,  2907,
     775,  2912,  2918,  2916,   824,  2911, -1803,  2914,  2915,  1183,
    2920,  2924,  2927,    14,   937,  1184,  1185,  1186,   775,  2929,
    2935,  1617,  2931,  2932,  2438,  2933,  2934,   690,  2947,   775,
     162,  2945,  2956,  2964,  2992,  1187,  1905,  2751,  2993,  2983,
    2984,  2994,   163,  3002,  1905,  2995,  3013,  1905,  1905,  1905,
    1905,  2782,   164,  3028,  3016,  3029,  3037,  3044,   775,  3045,
    3047,  3083,    15,  3103,  3085,  3115,  2766,  3058,  3068,  3079,
     165,  3090,  3123,  3125,  3126,  2789,  2820,  2821,  2822,  2823,
     166,  3127,  2064,  3128,  3141,  2499,  3151,  3152,  2432,  3140,
    2455,  2294,  2208,  2593,  2593,  2784,   167,  2593,  1570,    72,
     873,  1868,    73,   560,  2167,  2176,  2480,   349,  2816,   197,
    1767,  1079,  1080,  1081,   202,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,   281,   675,
     345,  2064,  1686,  1636,   350,  1536,   168,  1687,   408,   283,
    1095,   661,     1,  1188,  2126,   376,  1189,  2730,   374,   668,
    2239,  2240,  2241,  2242,  2243,  2244,   667,  3138,     2,     3,
     169,  1842,  2594,  2594,  2594,  2594,  2144,  1755,   901,  1356,
    1190,  2035,  1828,  2156,  2027,   170,     1,  1599,  2546,   937,
    1921,  2787,   171,   699,  2253,   172,   699,  3144,  1905,  1603,
    1191,  1905,     2,     3,  2163,  1939,  1516,  1096,  1097,  1098,
    1099,  1100,  1101,  2910,    67,   157,   173,    68,    69,   174,
    2860,   175,  1875,  1102,  1103,  1104,  1906,   972,   809,  1878,
     339,     4,   993,  1027,  2248,  1192,  1623,  2885,  1882,  2890,
     176,  2848,  1294,  2974,     5,     6,  1984,     7,     8,  1503,
    3111,  2537,     9,  1539,  1493,  1193,  1194,  1130,   177,   824,
    2660,  3043,  2982,  1240,   775,  1452,  1195,  1552,  2373,    10,
      11,  1196,  1416,  2659,  2642,  2150,  2283,  3145,     5,     6,
    3134,     7,     8,  2312,  3069,  1729,     9,    12,  2074,  2678,
    1696,  2374,  2883,  2664,  2712,  2869,  2376,  2663,  3077,  1639,
    1161,  2903,  1905,    10,    11,  2874,  2400,  1344,  3011,  2620,
    1197,  3012,  2805,  2574,  2706,  3133,  1178,  1178,  1178,  2536,
    1178,    12,  1178,  1178,  1905,  1631,  3050,  2064,    89,    89,
    1311,  2804,  2965,  1906,  2948,   699,  1597,  2593,  2957,  2100,
    1906,     0,  1198,  2593,  2593,  1510,  2593,  2593,  2593,  2593,
     416,     0,  2064,     0,  2064,  2593,     0,  1905,     0,     0,
       0,     0,     0,  1105,     0,  2973,  1106,     0,     0,     0,
       0,   882,     0,     0,     0,     0,     0,     0,  1665,  1666,
       0,     0,  1264,     0,     0,  1682,     0,  1906,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   937,  1130,  1027,     0,
    1027,     0,     0,  1905,     0,  1301,     0,     0,  2064,     0,
    2890,  1035,  1036,  1037,     0,     0,     0,     0,     0,     0,
       0,  1309,  1309,     0,     0,     0,     0,  1050,     0,     0,
       0,     0,     0,  1063,  1064,     0,     0,     0,  1068,     0,
       0,  2594,  2594,     0,     0,  2594,     0,     0,     0,     0,
       0,     0,     0,  2789,     0,     0,     0,     0,     0,     0,
       0,  1905,     0,     0,     0,  2593,     0,     0,  2593,  2593,
    2593,  2593,  3066,     0,     0,  1107,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,  1636,     0,     0,     0,
    1108,     0,     0,     0,  1109,     0,  1095,     0,     0,     0,
       0,    14,     0,     0,   699,     0,     0,     0,  1905,     0,
       0,     0,  1906,  1906,     0,     0,     0,     0,  1905,     0,
       0,  1906,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2866,  1110,     0,  2866,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   775,  3108,     0,     0,     0,     0,
      15,     0,   775,  1096,  1097,  1098,  1099,  1100,  1101,     0,
    1111,  2330,  2331,     0,  2332,  2333,  2334,     0,     0,  1102,
    1103,  1104,  1848,     0,     0,     0,  2593,     0,     0,  1112,
       0,  3106,    16,     0,  2593,     0,     0,     0,     0,     0,
       0,     0,  1486,     0,     0,     0,     0,  1027,     0,  1905,
      89,  2064,    89,   882,   802,     0,     0,     0,     0,     0,
       0,  1502,   814,     0,     0,   882,  1919,     0,  1906,   191,
       0,     0,  1517,     0,     0,     0,     0,  1906,     0,     0,
       0,     0,     0,     0,     0,   937,     0,  1905,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   775,     0,     0,
       0,  1113,     0,     0,  2335,     0,     0,     0,     0,     0,
       0,  2336,     0,     0,     0,  2594,     0,  1906,    89,  1906,
       0,  2594,  2594,     0,  2594,  2594,  2594,  2594,     0,     0,
       0,     0,     0,  2594,  3150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2337,     0,     0,     0,  1105,
       0,     0,  1106,     0,  2338,     0,     0,  1563,     0,     0,
    1906,     0,     0,     0,     0,     0,  2986,  1114,  1424,     0,
       0,     0,     0,     0,     0,  1431,     0,     0,  1442,     0,
       0,  1590,     0,  2339,  2340,     0,  1593,     0,     0,     0,
       0,  1447,     0,     0,     0,  1450,     0,     0,     0,  1622,
     937,     0,     0,  1456,     0,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,
    1473,  1474,  1475,  1476,  1477,     0,     0,     0,  2341,     0,
       0,     0,     0,     0,     0,  1478,  1479,     0,     0,     0,
    1481,     0,  1482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2594,     0,  1669,  2594,  2594,  2594,  2594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2342,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1108,     0,     0,     0,
    1109,     0,  2866,     0,     0,  1906,     0,     0,     0,     0,
       0,  1906,  1906,  1906,  1906,  1906,  1906,     0,     0,     0,
     882,     0,     0,     0,     0,     0,     0,     0,     0,  2204,
    2205,     0,     0,     0,     0,     0,  2343,     0,  1110,     0,
    2214,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1906,     0,     0,
       0,     0,     0,     0,     0,     0,  1111,     0,     0,  1095,
       0,     0,     0,     0,  2594,     0,  1906,  1906,  1906,  1906,
       0,     0,  2594,     0,     0,  1112,     0,     0,     0,     0,
       0,     0,     0,  2257,  2258,  2259,  2260,     0,     0,     0,
       0,  2265,  2266,  2267,  2268,     0,     0,     0,  2270,     0,
     718,   718,   718,     0,   718,   718,   718,   718,   718,   718,
       0,     0,     0,   718,     0,     0,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,  1093,  1094,     0,     0,     0,     0,
       0,     0,  1102,  1103,  1104,     0,     0,     0,  1095,     0,
       0,     0,     0,     0,     0,  1839,     0,     0,     0,     0,
    1906,     0,  1906,     0,  1847,     0,     0,  1113,     0,     0,
       0,     0,  1906,     0,  1906,   882,     0,  1906,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2319,  2320,     0,     0,   183,     0,     0,  2324,
    2325,     0,     0,     0,     0,  1096,  1097,  1098,  1099,  1100,
    1101,     0,     0,     0,     0,  1906,     0,     0,     0,     0,
       0,  1102,  1103,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,   882,  1973,   882,     0,     0,     0,   876,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2344,  2345,  2346,  2347,  2348,
    2349,  2350,  2351,  2352,  2353,     0,   935,     0,     0,     0,
    2021,     0,  1105,     0,     0,  1106,     0,     0,     0,     0,
       0,     0,  1770,  1771,  1772,     0,  1774,     0,  1906,     0,
       0,     0,     0,     0,     0,     0,  1906,  1094,     0,  1906,
    1906,  1906,  1906,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,  1789,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2471,  2472,     0,     0,
       0,     0,     0,     0,     0,  2479,   882,   191,     0,     0,
       0,     0,     0,     0,     0,  1906,  1906, -1804,     0,  1906,
       0,  1105,     0,     0,  1106,     0,     0,     0, -1804,     0,
   -1804, -1804, -1804,     0,  2506,  2507,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,     0,  1844,     0,
       0,     0,     0,  1102,  1103,  1104, -1804,     0,     0,     0,
       0,     0,     0,  1789,  1107,     0,   882,     0,   882,     0,
       0,     0,     0,     0,     0,     0,     0,   882,     0,  1108,
       0,     0,     0,  1109,     0, -1804,     0,     0,     0,     0,
    2549,     0,  2551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1906,     0,     0,  1906,     0,
    1906,     0,     0,  1906,  2189,     0,     0,     0,     0,     0,
       0,  1110,     0,     0,     0,     0,     0, -1804,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,  2213,     0,     0,     0,     0,  1111,
    2623,  2624,     0,     0,  2625,  2626,     0, -1804,  1108,     0,
   -1804,     0,  1109,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,     0,  1703,     0,     0,     0,
       0,     0,     0,     0, -1804,     0,     0,     0,  2649,     0,
    2247,  1593, -1804,  1105, -1804,     0,  1106,     0,     0,     0,
    1110,     0,     0, -1804,     0,     0,     0,     0,     0, -1804,
       0,     0,     0,     0,  1906,     0,     0, -1804,     0,     0,
       0, -1804,     0,     0,     0,     0,     0, -1804,  1111,     0,
       0, -1804, -1804, -1804, -1804,     0,  1906,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1804,  1112,     0,  1906,
    1113,     0,     0,     0,     0,  1906,  1906,     0,  1906,  1906,
    1906,  1906,     0, -1804,     0,     0, -1804,  1906, -1804,  1906,
       0,     0,     0,     0,     0, -1804,     0,     0,     0,     0,
    2140,     0,     0,  2140,     0,     0,     0,     0, -1804,     0,
       0,     0,     0,     0,     0,  2317,     0,     0, -1804,     0,
    1906,     0,  2744,     0,     0,     0,  2749,     0,  1886,     0,
       0,   269,  1887,  1888,    41,  1107,  1114, -1804, -1804,  2754,
       0,     0,     0,     0,     0,  1906,     0,     0,     0,  1113,
    1108,     0, -1804,     0,  1109,     0,     0,  2764,     0,     0,
   -1804,     0,     0,     0, -1804,     0,     0,     0,     0,     0,
       0,  1889,     0, -1804, -1804, -1804,   935,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2785,  1110,     0,   882,     0,     0,     0,     0,     0,
       0,     0,     0,  1906,     0,     0,     0,  1906,     0,     0,
    1906,  1906,  1906,  1906,     0,  1114,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1704,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,     0, -1804,     0,   882,     0,  1906,     0,     0,     0,
    1906,     0,     0, -1804,     0,     0,  2190,  1079,  1080,  1081,
    1906,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,  2497,  1705,
     712,     0,  2501,     0, -1804,     0,   698,     0,     0,     0,
       0,  1706,     0,     0,     0,  2512,     0,     0,     0,     0,
     191,  1707,     0,     0,     0,   722,     0,     0,  1906,     0,
       0,  1113,     0,     0,   723,   724,  1906,     0,     0,  1708,
     269,   725,   726,    41,     0,     0,     0,     0,     0,  1709,
       0,  1906,  1710,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,     0,     0,     0,     0,  1711, -1804,     0,     0,  1102,
    1103,  1104,     0,     0,     0,   727,  2554,  2556,     0,     0,
     728,     0,     0,     0,     0,     0,     0,   729,     0,  1906,
       0,     0,     0,     0,     0,     0,     0,  1114,     0,     0,
       0,     0, -1804,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1712,   730,     0,     0,     0,  2621,
       0,     0,     0,   935,     0,  2923,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1713,     0,     0,     0, -1804,     0,
       0,     0,     0,     0,  1714,     0,     0,     0,     0,  2643,
       0,     0, -1804, -1804, -1804, -1804, -1804, -1804, -1804,     0,
   -1804, -1804,  2658,     0,     0,  1715,  1789,  1789,  1716,  1095,
    1717,     0,     0,     0,  1079,  1080,  1081, -1804,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,     0,    82,     0,   731,  1718,  1105,
       0,  1890,  1106,  1095,     0,     0,     0,  1719,     0,  2494,
       0,     0,  1789,     0,     0,     0,  1891,     0,     0,     0,
       0,  1789,  1789,   882,     0,     0,  1096,  1097,  1098,  1099,
    1100,  1101,     0,  1892,     0,     0,  1893,     0,     0,     0,
       0,     0,  1102,  1103,  1104,     0,     0,     0,     0,  1894,
       0,     0,     0,   882,     0,     0,     0,     0,     0,     0,
    1096,  1097,  1098,  1099,  1100,  1101,     0,     0,   191,     0,
    3041,     0,     0,     0,     0,     0,  1102,  1103,  1104,     0,
       0,     0,     0,  1593,     0,     0,     0,     0,     0,     0,
    1896,   937,     0,     0,   732,     0,     0,     0,     0,   733,
       0,     0,  1897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1107,     0,  3070,  3071,     0,  3073,   734,  3075,  3076,
       0,     0,     0,     0,     0,     0,  1108,     0,     0,     0,
    1109,     0,     0,     0,  1898,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   736,     0,     0,     0,  1110,     0,
       0,     0,  1105,  1899,     0,  1106,     0,     0,     0,     0,
       0,     0,   737,     0,     0,  1900,  3119,   738,     0,     0,
     739,     0,     0,     0,     0,     0,  1111,  1901,  1902,     0,
       0,   740,     0,     0,     0,  1903,  1105,   741,  1904,  1106,
    3130,     0,  3131,     0,     0,  1112,   272,   742,     0,     0,
       0,     0,   743,     0,     0,   744,     0,     0,   745,  2643,
       0,     0,     0,     0,     0,     0,     0,   746,   747,     0,
       0,     0,     0,     0,     0,     0,     0,  3142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2731,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3147,  3148,     0,     0,  3149,  1218,   748,
       0,     0,     0,   749,     0,     0,     0,     0,     0,     0,
       0,   750,     0,     0,  1107,     0,     0,  1113,     0,     0,
       0,     0,   751,     0,     0,     0,     0,     0,   752,  1108,
       0,  1789,     0,  1109,     0,     0,     0,     0,     0,   882,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,     0,   753,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,     0,     0,     0,  1109,  1448,     0,
       0,  1110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1593,     0,   754,     0,  1111,
       0,     0,     0,     0,   755,  1110,   756,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   757,   758,  1112,     0,
       0,     0,  2049,     0,   759,     0,     0,     0,     0,     0,
       0,  1884,  1885,  1111,  1886,   272,  1593,   269,  1887,  1888,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2643,     0,  1112,     0,     0,  2977,     0,  2979,     0,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,  1889,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   882,     0,     0,     0,
    1113,     0,     0,     0,   882,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   937,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,  1113,     0,     0,     0,     0,     0,
       0,     1,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,     0,     0,     0,     0,     0,   418,     2,     3,  1102,
    1103,  1104,     0,     0,     0,   419,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   420,   421,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,     0,     0,     0,
    1114,   424,   698,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   425,   426,   427,     0,     0,     0,     0,     0,
    1178,  1178,  1178,  1178,  1178,  1178,     0,     0,   428,     0,
     429,   430,   431,     5,     6,   432,     7,     8,   433,     0,
     434,     9,   435,   436,     0,     0,     0,     0,     0,   437,
       0,     0,   438,     0,   439,   440,   441,     0,    10,    11,
       0,     0,     0,     0,   442,     0,   443,   444,     0,   445,
       0,   446,   447,     0,     0,   448,    12,     0,     0,   449,
     450,   451,     0,   452,   453,     0,     0,     0,   454,   455,
       0,   456,     0,     0,     0,   457,     0,   458,   459,  1105,
       0,     0,  1106,   460,     0,     0,  2050,   461,     0,     0,
     462,     0,   463,     0,   464,     0,   465,     0,   466,   467,
       0,   468,   469,   470,     0,     0,     0,   471,     0,   472,
     473,     0,   474,     0,     0,     0,     0,     0,     0,     0,
     475,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   477,     0,     0,   478,   479,   937,     0,
     480,   481,     0,     0,   482,   483,     0,     0,     0,     0,
       0,     0,     0,   484,   485,   486,     0,   487,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,   489,   490,
       0,   491,     0,     0,     0,   492,   493,     0,     0,     0,
     494,     0,     0,     0,     0,     0,     0,  1890,   495,     0,
       0,     0,     0,     0,     0,     0,   496,   497,   498,     0,
       0,  1107,  1891,     0,   499,   500,     0,     0,     0,     0,
     501,     0,     0,   502,     0,     0,  1108,   503,   504,  1892,
    1109,     0,  2051,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,  2052,  1894,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1789,   506,     0,     0,     0,
       0,     0,     0,     0,   507,     0,     0,     0,  1110,     0,
     508,     0,     0,  2223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1896,     0,     0,     0,
       0,     0,     0,   108,     0,     0,  1111,     0,  1897,     0,
     509,     0,   510,   511,     0,     0,     0,     0,     0,     0,
       0,   512,     0,     0,     0,  1112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1898,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     513,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   514,     0,     0,     0,   515,     0,     0,     0,   516,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1899,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1900,     0,   517,   518,     0,     0,  1113,   519,     0,
       0,     0,     0,  1901,  1902,     0,     0,     0,     0,     0,
     520,  1903,     0,     0,  1904,     0,   521,   522,   523,   524,
       0,     0,   272,   525,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,   527,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   529,     0,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
       0,   532,     0,  1114,   533,     0,     0,     0,     0,     0,
     534,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   535,     0,     0,   536,
       0,     0,     0,     0,   537,     0,     0,   538,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   540,     0,     0,     0,     0,     0,     0,   541,
    1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
       0,     0,   542,   543,   544,   545,   546,   547,   548,  1095,
       0,   549,     0,   550,     0,   551,  1079,  1080,  1081,     0,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1095,     0,  1079,  1080,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,  1102,  1103,  1104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,  1103,
    1104,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,
       0,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
    1103,  1104,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1079,  1080,
    1081,  1095,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,  1102,  1103,  1104,     0,     0,     0,     0,
       0,     0,  1105,     0,     0,  1106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,  1103,  1104,     0,  1105,     0,
       0,  1106,     0,     0,  1096,  1097,  1098,  1099,  1100,  1101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1102,  1103,  1104,     0,     0,     0,     0,     0,     0,  1105,
       0,     0,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,  1106,     0,     0,  1108,
       0,     0,     0,  1109,  1751,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,     0,     0,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,  1105,  1108,     0,  1106,     0,  1109,
    1760,  1110,     0,  1102,  1103,  1104,     0,     0,     0,     0,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,  1106,     0,     0,  1108,     0,     0,  1111,
    1109,  1765,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,     0,     0,  1110,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,     0,     0,  1112,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,  1109,     0,  1111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,  1107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1113,  1108,  1110,     0,     0,  1109,  1773,     0,     0,     0,
       0,     0,  1107,  1105,     0,     0,  1106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
    1111,  1109,  1775,     0,     0,     0,  1113,     0,     0,     0,
       0,     0,     0,  1110,     0,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1114,  1113,     0,  1110,
       0,  1111,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,     0,
    1112,     0,     0,     0,     0,     0,     0,  1111,     0,     0,
       0,  1095,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1079,  1080,  1081,  1112,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,  1113,     0,  1114,     0,  1107,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,  1109,  1776,     0,     0,  1096,  1097,
    1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,  1113,     0,  1102,  1103,  1104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,  1114,  1113,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,     0,     0,
    1111,  1079,  1080,  1081,     0,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1114,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,  1079,  1080,  1081,     0,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,     0,     0,     0,     0,  1096,  1097,  1098,
    1099,  1100,  1101,     0,  1105,     0,     0,  1106,     0,     0,
       0,  1113,     0,  1102,  1103,  1104,     0,  1079,  1080,  1081,
       0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,  1095,     0,  1106,  1096,
    1097,  1098,  1099,  1100,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,  1103,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1096,  1097,  1098,  1099,  1100,  1101,     0,
       0,     0,     0,     0,     0,  1095,     0,     0,     0,  1102,
    1103,  1104,     0,     0,     0,     0,  1107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1108,     0,     0,     0,  1109,  1777,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,  1106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,     0,
       0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
       0,     0,  1108,  1110,     0,     0,  1109,     0,  1102,  1103,
    1104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,  1106,     0,
       0,  1111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,     0,     0,
    1112,     0,     0,     0,     0,     0,     0,  1779,     0,     0,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1111,     0,     0,     0,     0,     0,     0,  1105,
       0,     0,  1106,     0,  1095,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1108,     0,     0,   722,  1109,     0,     0,     0,     0,     0,
       0,     0,   723,   724,     0,     0,     0,     0,   269,   725,
     726,    41,  1113,     0,     0,     0,     0,     0,     0,     0,
       0,  1096,  1097,  1098,  1099,  1100,  1101,  1107,  1105,     0,
       0,  1106,  1110,     0,     0,     0,     0,  1102,  1103,  1104,
       0,     0,  1108,   727,     0,  1780,  1109,     0,   728,     0,
       0,     0,     0,  1113,     0,   729,     0,     0,     0,     0,
    1111,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,     0,     0,     0,     0,     0,  1114,  1112,
       0,  1107,     0,   730,  1110,  1095,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1108,  1783,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1111,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,  1096,  1097,  1098,  1099,  1100,  1101,     0,     0,
    1107,     0,     0,     0,     0,     0,     0,     0,  1102,  1103,
    1104,  1113,     0,     0,     0,  1108,  1111,     0,     0,  1109,
       0,     0,     0,    82,     0,   731,     0,  1105,     0,   722,
    1106,     0,     0,     0,     0,  1112,     0,     0,   723,   724,
       0,     0,     0,     0,   269,   725,   726,    41,     0,     0,
       0,     0,     0,     0,     0,  2049,     0,  1110,     0,     0,
       0,     0,     0,  1113,  1884,  1885,     0,  1886,     0,     0,
     269,  1887,  1888,    41,     0,     0,     0,  1114,     0,   727,
       0,     0,     0,     0,   728,  1111,     0,     0,     0,     0,
       0,   729,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1112,     0,     0,     0,     0,     0,
    1889,     0,     0,     0,     0,     0,     0,  1113,     0,   730,
       0,     0,   732,     0,     0,     0,     0,   733,     0,  1114,
       0,     0,     0,     0,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,  1105,  1107,
       0,  1106,     0,     0,     0,   734,  1095,     0,     0,     0,
       0,     0,     0,     0,  1108,     0,     0,     0,  1109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,  1113,     0,     0,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,     0,     0,     0,  1110,     0,     0,    82,
       0,   731,     0,  1096,  1097,  1098,  1099,  1100,  1101,  1778,
     737,     0,     0,     0,     0,   738,     0,     0,   739,  1102,
    1103,  1104,     0,     0,  1111,   698,     0,     0,     0,   740,
       0,   722,     0,     0,     0,   741,     0,     0,     0,     0,
     723,   724,  1114,  1112,     0,   742,   269,   725,   726,    41,
     743,     0,     0,   744,     0,     0,   745,     0,     0,     0,
    1107,     0,     0,     0,     0,   746,   747,     0,     0,     0,
       0,     0,     0,     0,     0,  1108,     0,     0,     0,  1109,
       0,   727,     0,     0,     0,     0,   728,     0,     0,     0,
       0,     0,     0,   729,     0,     0,     0,     0,   732,     0,
       0,     0,     0,   733,     0,     0,     0,   748,     0,     0,
       0,   749,     0,     0,     0,     0,     0,  1110,     0,   750,
       0,   730,     0,     0,     0,  1113,     0,     0,     0,  2050,
     751,   734,  2157,     0,     0,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,  1111,     0,     0,     0,  1884,
    1885,     0,  1886,     0,     0,   269,  1887,  1888,    41,  1105,
       0,   753,  1106,     0,  1112,     0,   735,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,     0,     0,     0,  1889,   737,     0,     0,     0,
       0,   738,     0,     0,   739,   754,     0,     0,     0,     0,
       0,    82,   755,   731,   756,   740,     0,     0,     0,     0,
       0,   741,     0,     0,   757,   758,     0,     0,     0,     0,
    1890,   742,   759,     0,     0,     0,   743,     0,     0,   744,
       0,     0,   745,   272,     0,  1891,  1113,     0,     0,     0,
       0,   746,   747,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1892,  1884,  1885,  2051,  1886,     0,     0,   269,
    1887,  1888,    41,     0,     0,     0,     0,  2052,  1894,     0,
       0,  1107,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,  2516,   748,     0,     0,  1108,   749,     0,     0,
    1109,     0,  1095,     0,     0,   750,     0,     0,     0,  1889,
     732,     0,  1114,     0,     0,   733,   751,     0,     0,  1896,
     698,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,  1897,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,     0,   734,     0,     0,     0,   753,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
    1097,  1098,  1099,  1100,  1101,     0,  1111,     0,     0,     0,
       0,     0,     0,  1898,     0,  1102,  1103,  1104,   735,   269,
    1887,  1888,    41,     0,     0,  1112,     0,     0,     0,     0,
     736,   754,     0,     0,     0,     0,     0,     0,   755,     0,
     756,     0,     0,  1090,  1091,  1092,  1093,  1094,   737,     0,
     757,   758,  1899,   738,     0,     0,   739,     0,   759,  2579,
    1095,     0,     0,     0,  1900,     0,     0,   740,     0,   272,
       0,     0,     0,   741,   698,     0,  1901,  1902,     0,     0,
       0,     0,     0,   742,  1903,     0,     0,  1904,   743,     0,
       0,   744,     0,     0,   745,   272,     0,     0,     0,     0,
       0,     0,     0,   746,   747,     0,     0,  1113,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1096,  1097,  1098,
    1099,  1100,  1101,     0,     0,     0,     0,     0,     0,  1095,
       0,     0,     0,  1102,  1103,  1104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   748,     0,     0,     0,   749,
       0,     0,     0,     0,     0,  1105,     0,   750,  1106,     0,
       0,     0,     0,     0,     0,  1890,     0,     0,   751,     0,
       0,     0,     0,  1114,   752,     0,     0,     0,  2050,     0,
    1891,     0,     0,     0,   698,     0,  1096,  1097,  1098,  1099,
    1100,  1101,     0,     0,     0,     0,     0,  1892,     0,   753,
    1893,     0,  1102,  1103,  1104,     0,     0,     0,     0,     0,
       0,     0,     0,  1894,  1884,  1885,     0,  1886,     0,     0,
     269,  1887,  1888,    41,     0,     0,     0,     0,  1884,  1885,
       0,  1886,     0,     0,   269,  1887,  1888,    41,     0,     0,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
     755,     0,   756,  1895,  1896,     0,     0,     0,     0,     0,
    1889,     0,   757,   758,     0,     0,  1897,     0,     0,     0,
     759,     0,     0,  1105,  1889,     0,  1106,  1107,     0,  1890,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,  1891,     0,  1109,     0,  1884,  1885,
       0,  1886,     0,     0,   269,  1887,  1888,    41,  1898,     0,
       0,  1892,     0,     0,  2051,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2577,  2578,  2052,  1894,     0,     0,
     269,  1887,  1888,    41,  1110,     0,     0,     0,     0,     0,
       0,     0,  1105,     0,  1889,  1106,     0,  1899,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1900,
       0,     0,  1111,     0,     0,     0,     0,     0,  1896,     0,
    2579,  1901,  1902,     0,     0,     0,     0,     0,     0,  1903,
    1897,  1112,  1904,     0,     0,   698,     0,     0,     0,  1890,
     272,     0,     0,     0,     0,  1107,     0,     0,     0,   698,
       0,     0,     0,     0,  1891,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,  1109,     0,     0,     0,     0,     0,
       0,  2580,  1898,     0,  2581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2582,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,     0,     0,  2577,
    2578,  1899,     0,  1113,  1107,   269,  1887,  1888,    41,   698,
       0,     0,     0,  1900,     0,     0,     0,     0,  2584,  1108,
    1111,     0,     0,  1109,     0,  1901,  1902,     0,     0,     0,
    2585,     0,     0,  1903,     0,   698,  1904,     0,     0,  1112,
       0,     0,     0,     0,   272,  2579,     0,     0,     0,     0,
       0,  2577,  2578,     0,     0,   203,     0,   269,  1887,  1888,
      41,  1110,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,  2586,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1111,
       0,     0,     0,     0,     0,     0,     0,  2579,     0,     0,
       0,     0,   204,   205,     0,     0,     0,     0,  1112,     0,
       0,  2587,   206,     0,     0,     0,     0,     0,     0,     0,
       0,  1113,     0,  2588,     0,     0,     0,     0,     0,     0,
    1890,     0,     0,     0,     0,  2589,  2590,     0,     0,     0,
       0,     0,     0,  2591,  1890,  1891,  2592,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,  1891,
       0,     0,  1892,     0,     0,  1893,     0,     0,     0,     0,
     698,     0,     0,     0,     0,     0,  1892,     0,  1894,  1893,
       0,     0,     0,     0,     0,     0,     0,  1114,     0,     0,
    1113,     0,  1894,     0,     0,  1942,  1943,  1944,  1945,  1946,
    1947,     0,     0,     0,     0,     0,  2223,     0,     0,     0,
       0,     0,     0,     0,  1890,     0,     0,     0,     0,  1896,
       0,     0,   698,     0,     0,     0,     0,     0,     0,  1891,
       0,  1897,  3053,  1896,     0,     0,     0,     0,     0,     0,
    1890,     0,     0,     0,     0,  1897,  1892,     0,     0,  1893,
       0,     0,     0,     0,  1948,  1891,  1114,     0,     0,     0,
       0,     0,  1894,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2580,  1898,     0,  2581,     0,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,  1898,  2582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1896,     0,     0,  1942,  1943,  1944,  1945,
    1946,  1947,  1899,     0,     0,  1897,     0,     0,     0,     0,
       0,   208,     0,     0,  1900,     0,  1899,     0,  2583,  2584,
       0,     0,     0,     0,     0,     0,  1901,  1902,  1900,     0,
     209,  2585,     0,     0,  1903,     0,     0,  1904,     0,     0,
    1901,  1902,     0,     0,     0,   272,   210,  1898,  1903,     0,
       0,  1904,     0,     0,     0,  1948,     0,     0,     0,   272,
       0,     0,     0,     0,     0,  1890,     0,     0,     0,   211,
       0,     0,     0,  2586,     0,     0,     0,     0,     0,     0,
    1891,   212,     0,     0,     0,     0,  1899,     0,     0,     0,
       0,   213,     0,     0,     0,     0,     0,  2580,  1900,     0,
    2581,     0,     0,     0,     0,     0,     0,     0,     0,   214,
    1901,  1902,  2587,  2582,     0,     0,     0,  1890,  1903,   215,
       0,  1904,   838,     0,  2588,     0,     0,     0,     0,   272,
       0,   839,  1891,     0,     0,   216,  2589,  2590,     0,     0,
     840,  2223,     0,     0,  2591,   841,     0,  2592,     0,  2580,
       0,     0,  2581,     0,  2584,   272,     0,     0,     0,  3017,
       0,     0,     0,     0,     0,  2582,  2585,     0,     0,     0,
       0,     0,     0,     0,     0,   217,     0,  1949,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   842,     0,
    1950,     0,     0,     0,     0,     0,   843,     0,     0,   218,
       0,     0,     0,     0,     0,     0,  2584,   159,  2586,     0,
       0,     0,     0,     0,   219,  3018,     0,     0,  2585,     0,
       0,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3019,     0,     0,     0,     0,   222,   160,  2587,   223,  3020,
     224,     0,   844,     0,  1951,     0,     0,     0,     0,  2588,
    2586,  1952,     0,     0,     0,   161,     0,     0,     0,   225,
       0,  2589,  2590,     0,     0,     0,     0,   845,     0,  2591,
       0,     0,  2592,     0,   846,  3021,   847,   226,  1949,     0,
     272,     0,     0,  3022,     0,     0,   848,     0,     0,  2587,
    1953,  1950,     0,     0,   162,     0,     0,     0,     0,     0,
       0,  2588,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,   849,  2589,  2590,  1954,   164,     0,     0,   227,
     850,  2591,     0,     0,  2592,  1955,  1956,     0,     0,     0,
       0,  1957,   272,     0,   165,     0,     0,     0,     0,     0,
       0,  1958,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1951,     0,   851,     0,     0,
     167,     0,  1952,  1959,     0,     0,  1960,  1961,     0,     0,
       0,     0,  1962,     0,     0,     0,     0,  3023,     0,     0,
       0,     0,     0,   852,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,  1953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   853,     0,     0,   169,     0,  1954,     0,     0,  1963,
       0,     0,   854,     0,     0,     0,  1955,  1956,     0,   170,
    1964,     0,  1957,     0,     0,     0,   171,     0,     0,   172,
       0,     0,  1958,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,   174,  1959,   175,     0,  1960,  1961,     0,
       0,     0,     0,  1962,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   855,   856,   857,     0,     0,     0,     0,     0,
    1963,     0,     0,     0,     0,   858,     0,     0,     0,  3024,
       0,  1964,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   859
};

static const short yycheck[] =
{
       4,   194,   716,   328,   188,    66,   989,   523,   499,    13,
      14,   424,  1518,   699,   866,   834,   837,   212,  1564,     0,
     874,  1702,   176,    82,  1003,  1429,  1753,  1999,   154,  1706,
    1293,  1294,   447,   363,   739,  1588,  1871,   848,  2299,  2300,
    2301,    45,    46,    24,   713,   996,    62,  1395,  1384,    30,
    1884,  1885,  1398,   481,  1625,  1326,  1812,   118,     5,    27,
      21,    27,   844,   845,    27,   847,    27,   849,   850,   506,
     388,   225,    76,    27,  2413,    79,     5,     5,    21,    95,
     264,     5,    25,   100,    27,    66,   517,    91,    62,    25,
      26,    27,  2302,   506,    98,    25,   419,    27,   102,   422,
     423,   105,   106,    25,     5,    27,  1941,   111,   112,     5,
     929,   237,   238,   436,   545,    19,    62,   548,   787,     5,
      24,    25,    26,     5,   943,   141,   541,     5,     5,   145,
    1031,   454,    27,    25,   457,    27,    27,   118,     5,   510,
     463,   962,    27,    24,   467,    26,   150,   340,   471,   153,
       5,    24,   475,    26,   158,     5,   479,   480,    79,   482,
    1937,     5,   485,    19,   487,   488,   489,    27,    27,   419,
      26,     5,   495,     5,     5,   498,    24,    25,    26,    27,
    2519,     5,   505,  1637,    27,    81,    82,   510,     5,     5,
    1697,  1698,   196,    65,  1701,   518,  1749,    24,    25,    26,
      27,    68,   395,    70,   454,    72,   529,   457,     5,   698,
     533,   227,    33,  1890,   537,    33,  1065,   467,   134,   933,
     543,   471,     6,   546,   273,   475,    87,    88,     5,    25,
     234,    27,   482,    24,    25,    26,   240,   487,    25,   489,
      27,    24,    25,    26,    27,   495,    91,   251,   498,    48,
      49,    50,    51,    52,    23,   505,     5,  2396,     5,   189,
     510,   855,   856,    27,   280,     6,   282,   388,   518,     6,
      25,   287,    27,    23,  2490,   508,   509,  2599,     5,   529,
     343,     5,   515,   533,  2280,    27,   519,   537,    24,    25,
      26,    27,    18,   543,  1801,   390,   546,   189,    64,   135,
     136,     5,   538,   364,   365,    26,    27,  2279,  1814,  1990,
       9,    10,     5,    12,    13,    14,    15,    16,    17,   234,
     336,     5,    25,  2882,    27,  2884,     5,    24,    25,    26,
      27,  2228,  2229,  2230,  2231,   457,   294,   353,  2891,   338,
    1893,   189,    27,   618,    27,   273,    56,    57,   332,   273,
     625,   587,   356,   244,  2189,   359,  1282,     5,    84,    27,
     359,   174,   247,   367,    18,    19,   257,   188,   189,  2818,
    2051,   189,    26,    27,    84,    85,    86,     5,  1230,   383,
    2829,   385,   898,   364,   365,     5,     5,   338,     5,     5,
     149,     9,    10,   189,    12,    13,    14,    15,    16,    17,
     384,   273,   576,     5,   149,   373,   189,   390,  1676,   413,
     624,  1679,     0,    25,   418,    27,   420,   421,  2669,  1398,
     424,   425,   429,   427,    31,     5,   430,     5,   546,     5,
       5,   206,  2209,   647,   162,     5,     5,   441,     5,     5,
       5,   424,   616,    29,   448,  2416,  1999,   189,  2419,   456,
     282,   162,     5,   189,     5,     5,   460,   270,  1172,  3012,
     457,   140,     5,   348,   233,   439,   470,     5,   189,   473,
     428,   343,    18,    19,    20,    21,    22,     5,     5,   483,
    1987,   448,     5,   233,  2806,  2807,   189,     5,   348,   348,
       5,     5,   189,     5,   589,   499,   500,   619,  2051,   617,
       5,   625,   506,   470,     5,  2012,   189,    27,     5,     5,
     514,     5,   516,   517,   837,     5,   388,     5,     5,   568,
     524,   525,  3081,   527,   528,  1014,   530,     5,   532,     5,
     534,  1985,   595,  2672,   538,   189,   540,   658,   542,  2046,
     544,   545,   508,   547,   548,     5,   550,   514,  2520,     5,
    1041,  1042,   251,   883,  1817,   885,     5,   524,   525,   244,
    2394,   528,  2396,     5,   247,   532,   461,   534,   542,  2565,
    1974,   538,   257,   540,   390,   425,  2792,   189,   595,   578,
    1017,   425,  1983,  1269,   475,   470,   429,   837,  2927,   504,
     961,   425,   361,   561,   425,   372,   542,   513,   282,   435,
     491,   425,  2148,   394,  1017,   599,   390,  1038,   425,   530,
     470,   394,  1043,  1044,  2581,   343,  2826,  2833,   409,  2870,
     386,  1215,   619,   398,  1140,    28,   409,   578,   425,  1060,
    1531,  1480,   343,   251,  1483,   589,  1152,   960,   961,   962,
     568,   390,   429,   539,   568,   411,   576,  2193,   652,   390,
    1319,  1320,   553,   390,   979,  2994,  2202,  2203,   394,  1328,
     676,   365,   980,   390,   546,   429,   390,  1158,   611,   546,
     556,   370,   550,   409,  2227,   611,  2511,   681,   425,   683,
    2233,  2234,  2235,  2236,  2237,  2238,   383,   470,   617,   611,
      10,   390,   338,   585,   698,   550,   568,   390,   666,  1136,
     666,    27,  1371,   666,  2275,   666,  3045,   352,  3047,   713,
     960,   961,   962,  1141,   661,   619,  2443,  2473,   722,   723,
     724,  2477,  1153,  1136,   244,  1536,  2279,  1998,   427,   495,
     626,  1222,   553,   589,   738,   553,  2072,   257,   619,  1444,
     744,   745,   390,   453,   429,   749,   619,  2095,   452,    27,
     617,  2097,   370,   429,   550,  2023,  1247,   330,   625,   514,
    1579,  1252,   390,  1742,   625,   469,   525,   470,   241,   388,
     390,   619,   619,   390,   390,   429,   648,   649,   650,   500,
     525,    27,   394,   787,   583,  2292,     5,   659,   390,   486,
     475,   354,   619,   638,   639,   640,   641,   642,  2794,  2795,
      18,    19,    20,    21,    22,    21,   491,  3068,   512,   427,
     390,    27,   390,  1792,   390,   390,   544,  1248,  2715,  2223,
     390,   390,   588,   390,   390,   390,  2798,  1242,   619,   833,
     834,   541,  1653,   554,   600,   601,   619,   390,  2672,   390,
     390,    23,   608,   616,  2811,  2522,  2399,   390,   552,   577,
    2817,   323,   390,  2820,  2821,  2822,  2823,   556,   852,  1290,
    1291,   323,   390,   390,   868,   859,   992,   390,    27,   995,
     874,   538,   390,     5,   584,   390,   390,   581,   390,   425,
    2281,  2282,   886,   619,  2437,   390,   590,   891,   358,   390,
     157,  1407,   896,   390,   390,   352,   390,  2404,   157,  2406,
     390,   868,   390,   390,  2167,     0,     5,   874,   358,   429,
     914,   189,   390,  2810,   390,  2812,  2813,  2814,  2815,   886,
     587,     5,   619,   622,   891,   929,   457,  2770,   248,    24,
     390,   150,   578,   334,   390,  2050,    14,  2052,   556,   943,
     513,   390,   538,   189,   345,   104,  2920,  2921,   390,   625,
    2793,   524,   429,  2788,  1013,   475,  2502,    18,    19,    20,
      21,    22,  2805,    25,   281,    27,   429,  2520,    26,    27,
     533,   491,  1156,   521,  1643,  2528,   281,   294,  2531,  2532,
    2533,  2534,  2949,   112,   547,  2952,  2953,  2954,  2955,   294,
     167,   587,   429,   997,   457,   154,   397,  1001,  1002,  1003,
      21,    25,   535,    27,   622,   475,    27,   429,   480,   572,
    1014,   412,   237,  1017,   340,  1019,  1020,   429,   480,  1023,
     457,   457,   348,   349,   429,   475,    26,    27,   295,   429,
     189,   624,   191,  1266,  1038,  1039,   295,  1041,  1042,  1043,
    1044,   424,  1046,    26,    27,  1049,  1562,   373,    26,    27,
     376,   233,    26,   646,   647,   429,  1060,   620,  1062,  2566,
     457,  3035,  1066,  3037,   429,   385,   150,   387,   394,   294,
    1074,  1923,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,   544,  3060,  2771,   547,  2047,  2774,   550,  1530,
    2943,   502,  1106,  1107,   371,   383,   359,  1111,  2615,  1113,
     457,   428,   371,  1629,   367,   585,   237,   429,  2097,  1610,
    1611,   346,  2675,   428,  1128,   350,    25,   189,    27,   288,
     163,   189,  1136,   166,    25,   585,    27,   383,  1142,  1143,
    1144,   429,    25,  2094,    27,   429,    25,   470,    27,  1153,
    2831,  1155,   624,  1157,  1158,   478,    26,   190,  1162,    25,
     413,    27,   624,  1317,  2568,   189,    28,    29,  1989,  1323,
     429,   643,   644,   294,   500,  1142,  1143,  1144,   429,   361,
     457,   643,   644,  2298,  2299,  2300,  2301,   429,  1421,   189,
    2011,   663,   589,  1624,   471,  1162,   163,   356,   475,   166,
    1523,   663,    25,   428,    27,   364,   189,   425,   475,   368,
     487,   189,  1216,    25,   625,    27,   475,  1733,  1222,  1905,
    1550,    21,   619,  2776,   491,   346,   480,    27,   554,   350,
     625,   163,   491,  1359,   166,   561,   269,  1241,   441,   272,
      26,  1245,  1368,  1247,  1248,  2798,   405,  1480,  1252,  1216,
    1483,    26,  1256,  1257,  1258,    26,    21,   460,   190,    26,
     437,   294,    27,    25,  1268,    27,    21,    46,    47,    21,
     473,   448,    27,  1523,  1241,    27,   294,  1793,  1282,  1795,
    2395,    25,  2397,    27,    26,  1289,  1290,  1291,  1804,  2108,
     189,  1258,   619,   470,  2801,   624,   456,   457,   189,  2225,
     477,  1268,   269,  1972,   196,   272,   189,   428,   200,  1632,
     189,   457,  1316,    21,   473,  1319,  1320,   646,   647,    27,
    1324,  3002,  1326,   189,  1328,    30,    26,   294,   346,   390,
    1653,   529,   350,    26,  2887,   533,    25,   269,    27,   537,
     272,    46,    47,   122,   123,  2014,   125,   126,  1364,    26,
      55,   130,    26,   512,    19,    60,   429,    46,    47,    24,
    1851,    26,   294,    26,  2218,  2184,   189,  1371,   147,   148,
     624,    26,  2298,  2299,  2300,  2301,  2187,   189,   537,   619,
    1384,    21,  1632,   456,   457,  2892,   165,    27,    58,   643,
     644,  1395,  2945,   638,  1398,   428,   641,   642,   390,    19,
     105,   106,   365,  1653,    24,    25,    26,  2913,   113,   663,
     428,   360,   365,  1417,  1418,  1419,   429,   122,   123,  2271,
     125,   126,   581,  2036,  2940,   130,    25,   189,    27,  2042,
    2946,   590,    61,   122,   123,   619,   125,   126,    26,  2992,
     429,   130,   147,   148,   437,   189,   425,   520,   489,  1453,
    1454,  1455,   429,  1457,  2433,   448,   235,   498,   147,   148,
     165,   428,  2577,  2578,   639,   640,  2581,   456,   457,    18,
      19,    20,    21,    22,  2425,   429,   165,   470,  1760,    25,
    1484,    27,  1764,  1487,   477,     5,    25,  1769,    27,   452,
    3036,  1773,   390,  1775,  1776,  1777,   428,  1501,   457,   452,
     189,   619,   543,  1916,   133,   546,   469,    26,  3014,  2086,
    1743,  2088,  2089,   853,   854,  1519,   469,   857,   858,   257,
      25,  1525,    27,  1527,  1528,  1529,  1530,  3033,    25,    26,
    3083,   520,   365,    25,  1501,    27,    20,    21,    22,   425,
    1544,  1734,    25,   390,    27,  1549,   235,   456,   457,   512,
     133,    35,   118,   360,   446,   447,  1560,    21,  1525,   512,
    1564,    24,  1529,    26,  1759,   286,   287,  1571,  3121,   198,
      26,   200,   108,   109,   110,  1579,    26,  1544,  3085,   648,
     649,  1585,  1586,    26,  1588,  2101,   215,    26,  3094,   552,
     612,   613,   614,   615,   223,    24,   365,    26,   227,   552,
    1833,    24,    26,    26,  1571,    21,  1610,  1611,    92,    93,
      94,    95,    96,    97,   429,   198,    26,   200,   581,   452,
    1624,   641,   642,   252,   108,   109,   110,   590,   581,  1137,
      26,  1139,   215,   648,   649,  2151,   469,   590,    26,  1643,
     223,  2493,  2577,  2578,   227,  2628,   619,   390,     5,   541,
    1883,  2577,  2578,   390,   220,  2581,   390,   436,  1662,   551,
    1983,   366,   228,   301,   423,   390,  1989,   390,   234,   252,
     236,  1675,  1676,   390,   390,  1679,   623,   436,     5,   512,
     390,   247,   301,   452,   390,   623,   390,   392,  2011,   390,
     429,  1695,   390,  1697,  1698,   619,  2811,  1701,  1702,   457,
     469,   616,  2817,  2818,   463,  2820,  2821,  2822,  2823,   275,
       8,   619,   425,   265,  2829,   478,   525,   429,   429,   552,
     479,   480,   429,   419,  1728,   291,   485,  1731,   458,   488,
     296,  1735,    34,  1983,    36,    37,    38,   429,  1742,  1989,
     365,  2667,   308,   512,  2670,  1749,   429,   436,   581,   315,
       6,     7,     8,     9,    10,    11,    12,   590,   463,     5,
     429,  2011,   365,   429,   248,   429,   617,   251,  1735,  2438,
    2261,   429,  2263,   429,   617,   429,   429,  1781,   429,   429,
    1784,   429,   429,   552,  2498,    20,    21,   429,  1792,   365,
     429,   595,  1796,  1797,  1798,  1799,   429,  1801,   429,   429,
     658,   429,   429,  1807,  1808,   429,   419,  1811,  1812,   458,
      25,    34,   581,    36,    37,    38,  1820,   429,   658,   325,
       8,   590,   596,     5,   716,     5,  1830,   452,   382,  1796,
    1797,  1798,  1799,   429,  2949,   429,   429,  2952,  2953,  2954,
    2955,   589,   429,   429,   469,   343,   578,  1851,     8,   452,
      14,   575,   557,  1820,     5,   658,     5,    92,    93,    94,
      95,    96,    97,   658,   419,   429,   469,   429,    26,    26,
     762,    65,   133,  1877,    91,   457,   452,   457,    26,     5,
    1884,  1885,  2734,  2809,   619,  2811,   370,   512,   429,  1893,
    2742,  2817,  2818,   469,  2820,  2821,  2822,  2823,   595,   589,
    1904,   385,   429,  2829,   470,   389,   429,  2593,    21,   512,
    1877,   477,  1916,   470,  2430,    21,   625,  2332,  2333,  2334,
    1924,  2336,  2337,  2338,  2339,  2340,  2341,   552,   429,   429,
    2345,   625,   637,   499,   429,   429,   512,   198,   504,   200,
     645,   625,   661,   427,  2460,  3060,   624,   349,   556,   552,
       5,    18,     5,  3068,   215,    19,   581,    26,  2281,  2282,
      26,   152,   223,   217,    25,   590,   227,   269,  1972,   578,
     272,   455,   274,   589,   481,  2036,   552,   238,   581,   622,
       5,  2042,   481,  1987,   619,   546,  1990,   590,   150,    26,
     474,   252,   294,  1997,  1998,  1999,   546,   398,  2002,   320,
    2004,   546,   304,    26,    61,   581,   663,   429,  2012,  2830,
    2014,   429,   429,   390,   590,   429,   429,   619,   576,  2023,
     457,   323,   546,  2949,  2217,   390,  2952,  2953,  2954,  2955,
     390,  2281,  2282,    26,   390,  2002,   390,  2004,  2707,   390,
     390,   933,  2046,   390,   346,  2049,   269,  2051,   350,   272,
    2481,   274,   390,   429,   625,  2036,   616,  2488,  2910,  2063,
       5,  2042,  2988,     5,     5,   579,   619,     5,  2072,   625,
     482,   294,   556,    20,    21,   390,   133,   134,     8,     5,
     429,   304,   624,   429,   535,    65,    26,    26,   303,     5,
     324,  2095,     5,  2097,   309,   310,   311,   390,   429,   429,
     323,  2105,   359,   596,  2108,    14,   419,    34,  2112,    36,
      37,    38,   625,   419,   329,     5,   659,   550,   546,     5,
      26,   100,   429,   346,   429,     5,   428,   350,   619,   625,
     638,   188,   429,   425,  3060,   624,   425,   194,   622,   459,
     459,   429,  3068,  2147,  2148,    92,    93,    94,    95,    96,
      97,   429,   429,  2157,   429,   429,  2160,   429,     8,     5,
       5,  2165,    26,    26,   589,   390,   390,    25,    30,    18,
      19,    20,    21,    25,  2178,     5,  2180,    25,  2182,   390,
    2184,    25,   390,   619,    46,    47,  2190,     5,   619,  2193,
    2157,     8,   619,  2160,  2198,   553,   324,  3049,  2202,  2203,
      25,   343,   343,   343,  2918,   428,   457,   264,   619,   266,
     429,    25,   359,  2882,  2218,  2884,   457,   424,     5,   429,
    2736,  2225,   437,  2227,   429,   440,   429,   429,   429,  2233,
    2234,  2235,  2236,  2237,  2238,  3017,  3018,  3019,  3020,  3021,
    3022,   650,  2733,    92,    93,    94,    95,    96,    97,   464,
     429,  2218,   429,    26,     5,   159,     5,  2261,    25,  2263,
     122,   123,    14,   125,   126,    26,    14,   595,   130,   484,
     595,   175,   176,   616,   429,  2279,     5,   619,   619,   183,
    1172,     5,     5,   340,   429,   147,   148,     7,  2292,   390,
       5,  2475,   625,   619,  2298,  2299,  2300,  2301,  2302,  2303,
      26,    26,  2627,   165,   519,    26,     8,   619,   390,  2313,
    2314,  2315,   390,   217,   625,    26,   589,  2321,   390,   390,
     390,   625,   226,    21,   539,   540,     5,   390,   390,   566,
     273,   390,     5,     5,   546,   550,     5,     5,   395,   390,
     555,   571,   269,   625,   390,   272,   439,   274,   619,   619,
    1242,   255,   390,   429,   470,     6,   625,     5,   553,   625,
     623,   623,   209,    25,    25,    25,   618,   294,   445,    25,
      25,   470,    26,    26,    26,   432,    26,   304,  2382,   594,
    2384,    26,   429,    26,   429,  2901,    26,   295,     5,   390,
    2394,   390,  2396,   267,   525,  2399,   300,   589,     5,   467,
    2404,  2405,  2406,   429,   390,  1297,   550,   239,   425,   466,
      25,   626,  3081,   259,   390,   472,   390,   474,     5,   346,
     439,   478,   343,   350,   481,    21,   139,   484,   553,  2433,
       5,   429,   429,  2437,  2438,   429,  2092,   494,   342,   429,
     429,  3155,   429,     5,   429,    14,   619,  2451,     5,   209,
     457,     5,   298,   390,    26,   390,   513,   440,   390,    26,
     367,   390,   618,   330,   521,   522,   523,   429,   970,  2473,
     527,   317,  2476,  2477,   372,   390,   568,  2481,   535,    26,
    2484,   239,   343,   429,  2488,   390,   240,   390,   390,   303,
     390,   457,   625,   355,   551,   309,   310,   311,  2502,   390,
     575,   428,   390,   390,   546,   390,   390,  2830,   390,  2513,
     356,   429,   619,    14,     7,   329,  2520,  2484,    26,   238,
     238,   625,   368,   446,  2528,   390,    26,  2531,  2532,  2533,
    2534,  2535,   378,   429,   391,   619,   390,   390,  2542,   625,
     625,     5,   404,    25,     5,   240,  2513,   390,   429,   425,
     396,   390,   390,   390,   390,  2559,    18,    19,    20,    21,
     406,   390,  2566,   390,     5,  2197,   390,   390,  2105,  3104,
    2147,  2575,  1867,  2577,  2578,  2542,   422,  2581,  1259,    37,
    2830,  1572,    39,   364,  1808,  1814,  2178,   287,  2592,   141,
       5,     6,     7,     8,   145,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   209,   397,
     281,  2615,  1363,  2617,   288,   429,   462,  1364,   353,   211,
      35,   371,    30,   437,  1767,   316,   440,  2446,   315,   385,
      92,    93,    94,    95,    96,    97,   383,  3094,    46,    47,
     486,  1544,  2298,  2299,  2300,  2301,  1784,  1434,   527,   967,
     464,  1680,  1529,  1798,  1673,   501,    30,  1289,  2252,   716,
    1602,  2545,   508,  2667,  1920,   511,  2670,  3119,  2672,  1292,
     484,  2675,    46,    47,  1802,  1619,  1158,    92,    93,    94,
      95,    96,    97,  2750,    24,   118,   532,    30,    30,   535,
    2649,   537,  1577,   108,   109,   110,  1588,   654,   484,  1583,
     266,    75,   683,  2707,  1918,   519,  1297,  2711,  1586,  2713,
     556,  2646,   934,  2847,   122,   123,  1635,   125,   126,  1149,
    3033,  2234,   130,  1213,  1139,   539,   540,   784,   574,  2733,
    2372,  2924,  2857,   886,  2738,  1070,   550,  1241,  2045,   147,
     148,   555,  1023,  2370,  2354,  1792,  1983,  3121,   122,   123,
    3085,   125,   126,  2015,  2970,  1401,   130,   165,  1701,  2403,
    1378,  2046,  2707,  2384,  2439,  2670,  2049,  2382,  2988,  1316,
     827,  2738,  2776,   147,   148,  2681,  2063,   963,  2893,  2315,
     594,  2894,  2576,  2293,  2437,  3083,   843,   844,   845,  2233,
     847,   165,   849,   850,  2798,  1311,  2937,  2801,   855,   856,
     959,  2575,  2828,  1695,  2809,  2809,  1284,  2811,  2817,  1731,
    1702,    -1,   626,  2817,  2818,  1154,  2820,  2821,  2822,  2823,
     362,    -1,  2826,    -1,  2828,  2829,    -1,  2831,    -1,    -1,
      -1,    -1,    -1,   248,    -1,  2839,   251,    -1,    -1,    -1,
      -1,   898,    -1,    -1,    -1,    -1,    -1,    -1,  1350,  1351,
      -1,    -1,   909,    -1,    -1,  1357,    -1,  1749,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   933,   934,  2882,    -1,
    2884,    -1,    -1,  2887,    -1,   942,    -1,    -1,  2892,    -1,
    2894,   722,   723,   724,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   958,   959,    -1,    -1,    -1,    -1,   738,    -1,    -1,
      -1,    -1,    -1,   744,   745,    -1,    -1,    -1,   749,    -1,
      -1,  2577,  2578,    -1,    -1,  2581,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2937,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2945,    -1,    -1,    -1,  2949,    -1,    -1,  2952,  2953,
    2954,  2955,  2956,    -1,    -1,   370,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,  2970,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,    -1,    35,    -1,    -1,    -1,
      -1,   355,    -1,    -1,  2988,    -1,    -1,    -1,  2992,    -1,
      -1,    -1,  1884,  1885,    -1,    -1,    -1,    -1,  3002,    -1,
      -1,  1893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2667,   427,    -1,  2670,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3028,  3029,    -1,    -1,    -1,    -1,
     404,    -1,  3036,    92,    93,    94,    95,    96,    97,    -1,
     455,    73,    74,    -1,    76,    77,    78,    -1,    -1,   108,
     109,   110,  1554,    -1,    -1,    -1,  3060,    -1,    -1,   474,
      -1,  3028,   436,    -1,  3068,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1129,    -1,    -1,    -1,    -1,  3081,    -1,  3083,
    1137,  3085,  1139,  1140,  1141,    -1,    -1,    -1,    -1,    -1,
      -1,  1148,  1149,    -1,    -1,  1152,  1598,    -1,  1990,  1156,
      -1,    -1,  1159,    -1,    -1,    -1,    -1,  1999,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1172,    -1,  3121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3141,    -1,    -1,
      -1,   556,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,  2811,    -1,  2049,  1215,  2051,
      -1,  2817,  2818,    -1,  2820,  2821,  2822,  2823,    -1,    -1,
      -1,    -1,    -1,  2829,  3141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   248,
      -1,    -1,   251,    -1,   226,    -1,    -1,  1254,    -1,    -1,
    2092,    -1,    -1,    -1,    -1,    -1,  2862,   622,  1039,    -1,
      -1,    -1,    -1,    -1,    -1,  1046,    -1,    -1,  1049,    -1,
      -1,  1278,    -1,   255,   256,    -1,  1283,    -1,    -1,    -1,
      -1,  1062,    -1,    -1,    -1,  1066,    -1,    -1,    -1,  1296,
    1297,    -1,    -1,  1074,    -1,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,    -1,    -1,    -1,   300,    -1,
      -1,    -1,    -1,    -1,    -1,  1106,  1107,    -1,    -1,    -1,
    1111,    -1,  1113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2949,    -1,  1352,  2952,  2953,  2954,  2955,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     342,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,
     389,    -1,  2988,    -1,    -1,  2227,    -1,    -1,    -1,    -1,
      -1,  2233,  2234,  2235,  2236,  2237,  2238,    -1,    -1,    -1,
    1407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1861,
    1862,    -1,    -1,    -1,    -1,    -1,   398,    -1,   427,    -1,
    1872,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,  2279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    35,
      -1,    -1,    -1,    -1,  3060,    -1,  2298,  2299,  2300,  2301,
      -1,    -1,  3068,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1925,  1926,  1927,  1928,    -1,    -1,    -1,
      -1,  1933,  1934,  1935,  1936,    -1,    -1,    -1,  1940,    -1,
    2332,  2333,  2334,    -1,  2336,  2337,  2338,  2339,  2340,  2341,
      -1,    -1,    -1,  2345,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,  1542,    -1,    -1,    -1,    -1,
    2382,    -1,  2384,    -1,  1551,    -1,    -1,   556,    -1,    -1,
      -1,    -1,  2394,    -1,  2396,  1562,    -1,  2399,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2024,  2025,    -1,    -1,  1583,    -1,    -1,  2031,
    2032,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,  2437,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1629,  1630,  1631,    -1,    -1,    -1,  1635,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,    -1,  2498,    -1,    -1,    -1,
    1667,    -1,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,  1453,  1454,  1455,    -1,  1457,    -1,  2520,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2528,    22,    -1,  2531,
    2532,  2533,  2534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,  1484,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2168,  2169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2177,  1733,  1734,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2577,  2578,    23,    -1,  2581,
      -1,   248,    -1,    -1,   251,    -1,    -1,    -1,    34,    -1,
      36,    37,    38,    -1,  2206,  2207,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,  1549,    -1,
      -1,    -1,    -1,   108,   109,   110,    62,    -1,    -1,    -1,
      -1,    -1,    -1,  1564,   370,    -1,  1793,    -1,  1795,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1804,    -1,   385,
      -1,    -1,    -1,   389,    -1,    91,    -1,    -1,    -1,    -1,
    2262,    -1,  2264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2667,    -1,    -1,  2670,    -1,
    2672,    -1,    -1,  2675,  1841,    -1,    -1,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370,  1871,    -1,    -1,    -1,    -1,   455,
    2322,  2323,    -1,    -1,  2326,  2327,    -1,   163,   385,    -1,
     166,    -1,   389,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,  2360,    -1,
    1917,  1918,   198,   248,   200,    -1,   251,    -1,    -1,    -1,
     427,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,  2776,    -1,    -1,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,   233,   455,    -1,
      -1,   237,   238,   239,   240,    -1,  2798,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,   474,    -1,  2811,
     556,    -1,    -1,    -1,    -1,  2817,  2818,    -1,  2820,  2821,
    2822,  2823,    -1,   269,    -1,    -1,   272,  2829,   274,  2831,
      -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,    -1,    -1,
    1781,    -1,    -1,  1784,    -1,    -1,    -1,    -1,   294,    -1,
      -1,    -1,    -1,    -1,    -1,  2022,    -1,    -1,   304,    -1,
    2862,    -1,  2474,    -1,    -1,    -1,  2478,    -1,    21,    -1,
      -1,    24,    25,    26,    27,   370,   622,   323,   324,  2491,
      -1,    -1,    -1,    -1,    -1,  2887,    -1,    -1,    -1,   556,
     385,    -1,   338,    -1,   389,    -1,    -1,  2509,    -1,    -1,
     346,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,   359,   360,   361,  2918,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2543,   427,    -1,  2101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2945,    -1,    -1,    -1,  2949,    -1,    -1,
    2952,  2953,  2954,  2955,    -1,   622,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,   428,    -1,  2151,    -1,  2988,    -1,    -1,    -1,
    2992,    -1,    -1,   439,    -1,    -1,     5,     6,     7,     8,
    3002,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,  2195,   356,
    2197,    -1,  2199,    -1,   480,    -1,   189,    -1,    -1,    -1,
      -1,   368,    -1,    -1,    -1,  2212,    -1,    -1,    -1,    -1,
    2217,   378,    -1,    -1,    -1,     9,    -1,    -1,  3060,    -1,
      -1,   556,    -1,    -1,    18,    19,  3068,    -1,    -1,   396,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,   406,
      -1,  3083,   409,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   422,   542,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    59,  2273,  2274,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,  3121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      -1,    -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   471,    99,    -1,    -1,    -1,  2316,
      -1,    -1,    -1,  3155,    -1,  2767,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,   624,    -1,
      -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,  2356,
      -1,    -1,   638,   639,   640,   641,   642,   643,   644,    -1,
     646,   647,  2369,    -1,    -1,   532,  2147,  2148,   535,    35,
     537,    -1,    -1,    -1,     6,     7,     8,   663,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   189,    -1,   191,   565,   248,
      -1,   394,   251,    35,    -1,    -1,    -1,   574,    -1,  2190,
      -1,    -1,  2193,    -1,    -1,    -1,   409,    -1,    -1,    -1,
      -1,  2202,  2203,  2430,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,   426,    -1,    -1,   429,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,   442,
      -1,    -1,    -1,  2460,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,  2475,    -1,
    2922,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,  2490,    -1,    -1,    -1,    -1,    -1,    -1,
     483,  2498,    -1,    -1,   288,    -1,    -1,    -1,    -1,   293,
      -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   370,    -1,  2975,  2976,    -1,  2978,   321,  2980,  2981,
      -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,
     389,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,   427,    -1,
      -1,    -1,   248,   576,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,   386,    -1,    -1,   588,  3048,   391,    -1,    -1,
     394,    -1,    -1,    -1,    -1,    -1,   455,   600,   601,    -1,
      -1,   405,    -1,    -1,    -1,   608,   248,   411,   611,   251,
    3072,    -1,  3074,    -1,    -1,   474,   619,   421,    -1,    -1,
      -1,    -1,   426,    -1,    -1,   429,    -1,    -1,   432,  2646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,   442,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3135,  3136,    -1,    -1,  3139,   482,   483,
      -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   495,    -1,    -1,   370,    -1,    -1,   556,    -1,    -1,
      -1,    -1,   506,    -1,    -1,    -1,    -1,    -1,   512,   385,
      -1,  2502,    -1,   389,    -1,    -1,    -1,    -1,    -1,  2736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,
      -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,    -1,    -1,    -1,   389,   390,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2792,    -1,   581,    -1,   455,
      -1,    -1,    -1,    -1,   588,   427,   590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   600,   601,   474,    -1,
      -1,    -1,     9,    -1,   608,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,   455,    21,   619,  2833,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2847,    -1,   474,    -1,    -1,  2852,    -1,  2854,    -1,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2893,    -1,    -1,    -1,
     556,    -1,    -1,    -1,  2901,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2918,    -1,    -1,    -1,    -1,    -1,  2924,    -1,    -1,
      -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,   108,
     109,   110,    -1,    -1,    -1,    54,   622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
     622,    90,   189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
    3017,  3018,  3019,  3020,  3021,  3022,    -1,    -1,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,   141,    -1,   143,   144,   145,    -1,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,   172,   173,    -1,    -1,    -1,   177,   178,
      -1,   180,    -1,    -1,    -1,   184,    -1,   186,   187,   248,
      -1,    -1,   251,   192,    -1,    -1,   293,   196,    -1,    -1,
     199,    -1,   201,    -1,   203,    -1,   205,    -1,   207,   208,
      -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,   218,
     219,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    -1,    -1,   245,   246,  3155,    -1,
     249,   250,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,   263,   264,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   276,   277,   278,
      -1,   280,    -1,    -1,    -1,   284,   285,    -1,    -1,    -1,
     289,    -1,    -1,    -1,    -1,    -1,    -1,   394,   297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   305,   306,   307,    -1,
      -1,   370,   409,    -1,   313,   314,    -1,    -1,    -1,    -1,
     319,    -1,    -1,   322,    -1,    -1,   385,   326,   327,   426,
     389,    -1,   429,    -1,    -1,    -1,    -1,    -1,   337,    -1,
      -1,    -1,    -1,    -1,   441,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3036,   355,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,   427,    -1,
     369,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,   455,    -1,   495,    -1,
     399,    -1,   401,   402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,    -1,    -1,    -1,   464,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   576,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   588,    -1,   492,   493,    -1,    -1,   556,   497,    -1,
      -1,    -1,    -1,   600,   601,    -1,    -1,    -1,    -1,    -1,
     509,   608,    -1,    -1,   611,    -1,   515,   516,   517,   518,
      -1,    -1,   619,   522,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    -1,    -1,   533,   534,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,   547,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   558,
      -1,   560,    -1,   622,   563,    -1,    -1,    -1,    -1,    -1,
     569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   595,    -1,    -1,   598,
      -1,    -1,    -1,    -1,   603,    -1,    -1,   606,   607,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,   628,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,   651,   652,   653,   654,   655,   656,   657,    35,
      -1,   660,    -1,   662,    -1,   664,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    35,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,   248,    -1,
      -1,   251,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,   251,    -1,    -1,   385,
      -1,    -1,    -1,   389,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,   248,   385,    -1,   251,    -1,   389,
     390,   427,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,   385,    -1,    -1,   455,
     389,   390,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,   427,    -1,
      -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,    -1,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     556,   385,   427,    -1,    -1,   389,   390,    -1,    -1,    -1,
      -1,    -1,   370,   248,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,
     455,   389,   390,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,   556,    -1,   427,
      -1,   455,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    35,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   474,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   556,    -1,   622,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,   390,    -1,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   556,    -1,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,   622,   556,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,
     455,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   622,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,   248,    -1,    -1,   251,    -1,    -1,
      -1,   556,    -1,   108,   109,   110,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    35,    -1,   251,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,   389,   390,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,   385,   427,    -1,    -1,   389,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,    -1,
      -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   455,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,   251,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,     9,   389,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,   370,   248,    -1,
      -1,   251,   427,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,   385,    59,    -1,   440,   389,    -1,    64,    -1,
      -1,    -1,    -1,   556,    -1,    71,    -1,    -1,    -1,    -1,
     455,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,   622,   474,
      -1,   370,    -1,    99,   427,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   385,   440,    -1,    -1,
     389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   556,    -1,    -1,    -1,   385,   455,    -1,    -1,   389,
      -1,    -1,    -1,   189,    -1,   191,    -1,   248,    -1,     9,
     251,    -1,    -1,    -1,    -1,   474,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,   427,    -1,    -1,
      -1,    -1,    -1,   556,    18,    19,    -1,    21,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,   622,    -1,    59,
      -1,    -1,    -1,    -1,    64,   455,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    99,
      -1,    -1,   288,    -1,    -1,    -1,    -1,   293,    -1,   622,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,   248,   370,
      -1,   251,    -1,    -1,    -1,   321,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,   389,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,   556,    -1,    -1,    -1,
     356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,   427,    -1,    -1,   189,
      -1,   191,    -1,    92,    93,    94,    95,    96,    97,   440,
     386,    -1,    -1,    -1,    -1,   391,    -1,    -1,   394,   108,
     109,   110,    -1,    -1,   455,   189,    -1,    -1,    -1,   405,
      -1,     9,    -1,    -1,    -1,   411,    -1,    -1,    -1,    -1,
      18,    19,   622,   474,    -1,   421,    24,    25,    26,    27,
     426,    -1,    -1,   429,    -1,    -1,   432,    -1,    -1,    -1,
     370,    -1,    -1,    -1,    -1,   441,   442,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,   389,
      -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,   288,    -1,
      -1,    -1,    -1,   293,    -1,    -1,    -1,   483,    -1,    -1,
      -1,   487,    -1,    -1,    -1,    -1,    -1,   427,    -1,   495,
      -1,    99,    -1,    -1,    -1,   556,    -1,    -1,    -1,   293,
     506,   321,   508,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    18,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    27,   248,
      -1,   537,   251,    -1,   474,    -1,   356,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    64,   386,    -1,    -1,    -1,
      -1,   391,    -1,    -1,   394,   581,    -1,    -1,    -1,    -1,
      -1,   189,   588,   191,   590,   405,    -1,    -1,    -1,    -1,
      -1,   411,    -1,    -1,   600,   601,    -1,    -1,    -1,    -1,
     394,   421,   608,    -1,    -1,    -1,   426,    -1,    -1,   429,
      -1,    -1,   432,   619,    -1,   409,   556,    -1,    -1,    -1,
      -1,   441,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,    18,    19,   429,    21,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   441,   442,    -1,
      -1,   370,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    -1,   482,   483,    -1,    -1,   385,   487,    -1,    -1,
     389,    -1,    35,    -1,    -1,   495,    -1,    -1,    -1,    64,
     288,    -1,   622,    -1,    -1,   293,   506,    -1,    -1,   483,
     189,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,    -1,    -1,   321,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,   455,    -1,    -1,    -1,
      -1,    -1,    -1,   537,    -1,   108,   109,   110,   356,    24,
      25,    26,    27,    -1,    -1,   474,    -1,    -1,    -1,    -1,
     368,   581,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,
     590,    -1,    -1,    18,    19,    20,    21,    22,   386,    -1,
     600,   601,   576,   391,    -1,    -1,   394,    -1,   608,    64,
      35,    -1,    -1,    -1,   588,    -1,    -1,   405,    -1,   619,
      -1,    -1,    -1,   411,   189,    -1,   600,   601,    -1,    -1,
      -1,    -1,    -1,   421,   608,    -1,    -1,   611,   426,    -1,
      -1,   429,    -1,    -1,   432,   619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   441,   442,    -1,    -1,   556,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,   487,
      -1,    -1,    -1,    -1,    -1,   248,    -1,   495,   251,    -1,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   506,    -1,
      -1,    -1,    -1,   622,   512,    -1,    -1,    -1,   293,    -1,
     409,    -1,    -1,    -1,   189,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,   426,    -1,   537,
     429,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,    18,    19,    -1,    21,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    18,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
     588,    -1,   590,   482,   483,    -1,    -1,    -1,    -1,    -1,
      64,    -1,   600,   601,    -1,    -1,   495,    -1,    -1,    -1,
     608,    -1,    -1,   248,    64,    -1,   251,   370,    -1,   394,
      -1,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,   409,    -1,   389,    -1,    18,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    27,   537,    -1,
      -1,   426,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,   441,   442,    -1,    -1,
      24,    25,    26,    27,   427,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    -1,    64,   251,    -1,   576,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,
      -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      64,   600,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,
     495,   474,   611,    -1,    -1,   189,    -1,    -1,    -1,   394,
     619,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,   189,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,
     385,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,
      -1,   426,   537,    -1,   429,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,   576,    -1,   556,   370,    24,    25,    26,    27,   189,
      -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,   483,   385,
     455,    -1,    -1,   389,    -1,   600,   601,    -1,    -1,    -1,
     495,    -1,    -1,   608,    -1,   189,   611,    -1,    -1,   474,
      -1,    -1,    -1,    -1,   619,    64,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    32,    -1,    24,    25,    26,
      27,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,   474,    -1,
      -1,   576,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   556,    -1,   588,    -1,    -1,    -1,    -1,    -1,    -1,
     394,    -1,    -1,    -1,    -1,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,   608,   394,   409,   611,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,   409,
      -1,    -1,   426,    -1,    -1,   429,    -1,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,   426,    -1,   442,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
     556,    -1,   442,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,   483,
      -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,   409,
      -1,   495,   482,   483,    -1,    -1,    -1,    -1,    -1,    -1,
     394,    -1,    -1,    -1,    -1,   495,   426,    -1,    -1,   429,
      -1,    -1,    -1,    -1,    98,   409,   622,    -1,    -1,    -1,
      -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   426,   537,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,   537,   442,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   483,    -1,    -1,    39,    40,    41,    42,
      43,    44,   576,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,   298,    -1,    -1,   588,    -1,   576,    -1,   482,   483,
      -1,    -1,    -1,    -1,    -1,    -1,   600,   601,   588,    -1,
     317,   495,    -1,    -1,   608,    -1,    -1,   611,    -1,    -1,
     600,   601,    -1,    -1,    -1,   619,   333,   537,   608,    -1,
      -1,   611,    -1,    -1,    -1,    98,    -1,    -1,    -1,   619,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,   356,
      -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,
     409,   368,    -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,
      -1,   378,    -1,    -1,    -1,    -1,    -1,   426,   588,    -1,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
     600,   601,   576,   442,    -1,    -1,    -1,   394,   608,   406,
      -1,   611,   128,    -1,   588,    -1,    -1,    -1,    -1,   619,
      -1,   137,   409,    -1,    -1,   422,   600,   601,    -1,    -1,
     146,   470,    -1,    -1,   608,   151,    -1,   611,    -1,   426,
      -1,    -1,   429,    -1,   483,   619,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,   442,   495,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   462,    -1,   331,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     344,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,   486,
      -1,    -1,    -1,    -1,    -1,    -1,   483,   259,   537,    -1,
      -1,    -1,    -1,    -1,   501,   258,    -1,    -1,   495,    -1,
      -1,   508,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     283,    -1,    -1,    -1,    -1,   532,   298,   576,   535,   292,
     537,    -1,   258,    -1,   408,    -1,    -1,    -1,    -1,   588,
     537,   415,    -1,    -1,    -1,   317,    -1,    -1,    -1,   556,
      -1,   600,   601,    -1,    -1,    -1,    -1,   283,    -1,   608,
      -1,    -1,   611,    -1,   290,   328,   292,   574,   331,    -1,
     619,    -1,    -1,   336,    -1,    -1,   302,    -1,    -1,   576,
     454,   344,    -1,    -1,   356,    -1,    -1,    -1,    -1,    -1,
      -1,   588,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,
      -1,    -1,   328,   600,   601,   479,   378,    -1,    -1,   616,
     336,   608,    -1,    -1,   611,   489,   490,    -1,    -1,    -1,
      -1,   495,   619,    -1,   396,    -1,    -1,    -1,    -1,    -1,
      -1,   505,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   408,    -1,   373,    -1,    -1,
     422,    -1,   415,   527,    -1,    -1,   530,   531,    -1,    -1,
      -1,    -1,   536,    -1,    -1,    -1,    -1,   430,    -1,    -1,
      -1,    -1,    -1,   399,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     462,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   437,    -1,    -1,   486,    -1,   479,    -1,    -1,   593,
      -1,    -1,   448,    -1,    -1,    -1,   489,   490,    -1,   501,
     604,    -1,   495,    -1,    -1,    -1,   508,    -1,    -1,   511,
      -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,   535,   527,   537,    -1,   530,   531,    -1,
      -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,   549,   550,    -1,    -1,    -1,    -1,    -1,
     593,    -1,    -1,    -1,    -1,   561,    -1,    -1,    -1,   602,
      -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
       0,    30,    46,    47,    75,   122,   123,   125,   126,   130,
     147,   148,   165,   235,   355,   404,   436,   725,   753,   754,
     804,   971,  1024,  1026,  1027,  1028,  1033,  1035,  1048,  1049,
    1050,  1051,  1052,  1467,    28,    29,   726,   727,   728,   729,
     730,    27,   937,  1486,   354,   533,   547,   572,   620,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,   937,    25,   937,
    1388,  1053,   755,   754,  1467,     0,  1025,  1028,  1033,  1051,
    1467,    31,   728,   730,   937,  1470,   589,   937,  1469,   625,
     805,    25,   189,   752,   753,   925,   937,   942,  1054,  1089,
    1090,  1091,  1092,  1093,  1097,   352,   757,   758,   759,   760,
     763,   764,    55,    60,   105,   106,   113,   366,   392,   463,
     557,   637,   645,   725,   731,   897,   970,  1029,  1030,  1032,
    1036,  1037,  1043,  1055,  1076,  1208,  1218,  1467,   937,  1469,
     616,  1092,   241,   456,   457,  1099,    21,   937,  1096,   619,
     758,     5,   756,   352,   937,     5,   780,   782,   783,   937,
    1219,   937,   937,  1209,  1044,   937,   937,  1032,  1038,   259,
     298,   317,   356,   368,   378,   396,   406,   422,   462,   486,
     501,   508,   511,   532,   535,   537,   556,   574,   806,   807,
     808,   811,    25,  1089,  1095,    18,    19,    26,   429,   675,
     677,  1089,  1100,  1101,   457,    14,   803,   760,   521,  1195,
     761,   758,   763,    32,    79,    80,    89,   259,   298,   317,
     333,   356,   368,   378,   396,   406,   422,   462,   486,   501,
     508,   511,   532,   535,   537,   556,   574,   616,   766,   774,
     785,   786,   937,   429,   112,   937,   752,   898,  1077,   937,
     813,   535,   765,   789,   791,   792,   790,   799,   800,   429,
     429,   812,   457,   429,   429,   758,   787,   424,   675,    18,
      19,    20,    21,    22,   676,    26,     5,   425,  1100,    24,
      25,    26,   619,   937,   943,    19,    25,    26,   762,   943,
     776,   765,   777,   789,   790,   429,   429,   775,   457,   429,
     429,   787,   758,   784,   429,    26,   937,   429,  1045,   752,
     752,   429,   937,   429,   456,   769,   625,   365,   452,   469,
     512,   552,   581,   590,   793,   625,   365,   452,   469,   512,
     552,   581,   590,   801,    26,    26,   814,   815,   816,   817,
     937,    26,   772,   773,    26,    26,   619,   390,   675,  1101,
     457,   425,    26,    26,   758,   769,   758,    26,    26,   757,
     772,    26,    26,   619,    58,   781,  1220,   390,   429,  1210,
    1487,  1488,  1489,  1490,  1491,   899,  1078,  1039,   619,    26,
     794,   795,   429,   796,   801,   802,   796,   429,   797,     5,
     390,     5,   390,     5,   282,     5,   806,   425,     5,     5,
     390,   390,   758,   788,  1100,   457,   619,    26,   257,     5,
     390,     5,   390,   282,   425,     5,   390,   390,   788,   937,
    1106,  1107,  1109,  1056,  1106,   360,  1488,  1195,    45,    54,
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
     836,   888,   892,   923,   944,   945,   948,   949,   950,   951,
     964,   972,   993,   994,   996,  1000,  1015,  1016,  1020,  1021,
    1022,  1023,  1031,  1046,  1059,  1070,  1071,  1072,  1083,  1086,
    1122,  1125,  1127,  1133,  1134,  1137,  1140,  1143,  1145,  1147,
    1149,  1156,  1161,  1165,  1166,  1167,  1179,  1180,  1183,  1189,
    1190,  1191,  1216,  1231,  1232,  1233,  1234,  1235,  1240,  1246,
    1247,  1265,  1268,  1298,  1300,  1389,  1390,  1421,  1422,  1429,
    1440,  1467,  1471,  1476,  1478,  1480,  1484,  1485,  1492,   725,
    1034,  1467,   624,   647,  1079,  1080,  1106,    21,   390,   424,
     770,   793,    26,   798,    26,    26,    26,   815,   817,   809,
     773,    26,   425,  1100,    21,   770,   429,    26,    26,   767,
      26,   619,   390,     5,  1106,   390,   937,   348,   938,   939,
    1486,   937,   937,  1163,   932,   938,   932,    25,   189,   937,
    1098,  1462,  1463,  1464,   937,  1482,   937,  1242,  1243,   937,
      26,   672,  1089,  1238,   932,  1163,   862,    26,   943,  1203,
    1204,  1203,     9,    18,    19,    25,    26,    59,    64,    71,
      99,   191,   288,   293,   321,   356,   368,   386,   391,   394,
     405,   411,   421,   426,   429,   432,   441,   442,   483,   487,
     495,   506,   512,   537,   581,   588,   590,   600,   601,   608,
     837,   844,   845,   846,   847,   848,   849,   850,   851,   863,
     868,   879,   880,   881,   882,   937,   943,  1089,  1198,  1267,
    1380,   938,  1430,  1430,   823,  1163,   932,  1236,  1089,   934,
     938,   844,  1430,  1089,  1163,  1089,  1266,  1430,    25,   585,
    1073,  1074,  1089,   932,   932,  1073,   933,   938,   937,  1074,
     932,  1430,   932,   934,  1089,  1120,  1121,   930,   938,   934,
     373,   561,   666,   929,   937,   995,   937,   733,   935,   938,
      25,  1299,  1462,   862,   862,   938,  1146,   893,   128,   137,
     146,   151,   194,   202,   258,   283,   290,   292,   302,   328,
     336,   373,   399,   437,   448,   548,   549,   550,   561,   664,
    1009,  1141,  1142,  1089,   843,   844,  1155,   839,   862,   929,
    1477,  1477,   931,   938,   862,    25,  1089,  1144,  1217,  1089,
    1194,    25,  1089,  1424,   844,  1185,  1186,  1187,  1196,  1197,
     844,  1472,   104,   154,   191,   288,   364,   405,   473,   537,
     689,   868,   937,  1089,  1226,   712,   844,   930,  1469,  1060,
     844,   930,   844,  1089,  1017,   930,   844,  1441,   844,  1203,
     937,   946,   947,   934,   946,  1477,   934,   946,  1477,   952,
     946,    25,    26,   383,   486,   943,   998,  1089,  1108,  1110,
      65,   273,   343,   388,   568,   648,   649,   650,   659,   679,
     954,   956,   958,   960,   962,  1084,  1085,  1088,   334,   345,
     397,   412,   502,  1301,   639,   640,   901,   902,   903,   937,
    1081,   646,  1080,   390,   301,   390,   390,   390,   390,   623,
       5,   390,   425,   301,   758,   778,   779,   390,   390,   623,
     390,   937,  1221,  1109,   390,  1211,    56,    57,    84,    85,
      86,   453,   541,   584,  1248,  1249,  1250,  1253,  1256,  1259,
    1260,  1261,  1262,   429,   619,  1464,  1099,   616,  1138,   619,
       8,   538,   587,     5,   390,   425,    25,   937,  1373,   478,
    1164,  1108,   108,   109,   110,   837,   837,   837,   429,   525,
    1215,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     837,   365,   452,   469,   512,   552,   581,   590,  1383,  1384,
     429,   429,   429,   837,   837,   429,   429,   749,   837,   429,
     852,   429,   429,   429,   429,   429,   429,   429,   429,     6,
       7,     8,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    35,    92,    93,    94,    95,
      96,    97,   108,   109,   110,   248,   251,   370,   385,   389,
     427,   455,   474,   556,   622,   748,   838,   853,   855,   856,
     857,   858,   859,   860,   861,    26,   943,   429,   520,   419,
    1089,  1115,  1373,   678,   679,   826,   265,    87,    88,   625,
     458,     5,   618,   625,   617,   617,  1123,   595,   419,     5,
     556,   973,   458,   658,  1474,   429,   457,   619,   658,   383,
     735,  1089,   546,   617,  1128,  1129,  1130,   325,  1297,   842,
     844,   842,     8,   931,    26,   500,   554,   924,  1089,   924,
     924,   924,    25,   303,   309,   310,   311,   329,   437,   440,
     464,   484,   519,   539,   540,   550,   555,   594,   626,  1013,
    1014,   924,   924,   596,  1010,   679,  1010,  1010,   925,   925,
    1010,  1010,   679,     5,   332,   384,     5,   678,   482,   840,
     841,   844,     5,    81,    82,   539,   626,  1001,   661,  1475,
     843,   612,   613,   614,   615,  1193,  1195,   382,  1230,  1195,
    1187,     5,   617,  1188,   844,   429,   429,   429,   429,    25,
     708,   937,   429,  1424,   343,   429,   520,   589,   578,   713,
     720,   711,    25,  1075,  1089,  1181,     8,  1184,    14,   937,
    1094,  1102,  1103,  1105,  1113,  1114,  1157,   162,   343,   544,
     577,    33,   189,   553,  1442,  1443,  1444,  1445,   575,     5,
     658,   658,   842,  1108,  1115,   997,   419,     5,   150,   977,
     429,  1089,   842,   429,    26,    26,    65,  1087,    25,  1089,
    1428,  1428,   938,  1281,  1146,   931,   118,   220,   228,   234,
     236,   247,   275,   291,   296,   308,   315,   470,   477,   499,
     504,  1269,  1270,  1278,  1288,  1289,  1295,  1296,  1302,  1303,
    1312,  1331,  1335,  1400,  1401,  1431,  1432,  1435,  1436,  1446,
     904,   905,    91,   900,   911,   912,   903,  1082,  1487,  1040,
     457,   806,   773,   457,     5,   390,   780,   752,  1057,   752,
     157,   295,   371,   429,   475,   491,  1318,  1330,   429,   937,
    1264,    26,   244,   257,   429,   475,   491,   937,  1245,  1258,
    1316,  1317,  1322,  1324,  1326,   429,   937,  1255,   429,  1245,
    1251,     5,    25,   940,  1092,  1464,  1462,   576,   616,  1139,
      21,   937,  1119,  1465,   937,  1483,  1243,   595,   619,   589,
     429,   429,   826,  1477,   837,   929,   929,  1477,  1477,   470,
    1404,   837,    25,    26,    19,    24,    25,    26,   883,   884,
     885,   886,   837,   429,   625,  1477,    21,   837,   390,  1404,
     837,    21,  1198,   871,   869,   875,   837,   873,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     429,   837,   837,   429,   864,   937,  1089,   625,   429,  1462,
      25,   942,  1162,  1162,  1424,  1073,   844,   844,   844,   926,
     927,   429,  1089,  1121,   787,   974,   975,   625,  1424,  1477,
    1475,   937,   675,    21,   666,   937,   995,  1089,   734,   624,
     844,   349,  1132,   556,  1131,     5,    68,    70,    72,   617,
     625,   818,  1108,   894,    18,    19,   429,  1011,  1013,  1142,
     925,   844,   343,   595,     5,   929,    26,    26,   678,   152,
    1192,   217,  1197,  1203,  1473,   937,    25,   887,   929,  1477,
     589,   929,   622,  1089,   693,   937,   937,   844,   338,   716,
     720,   578,   714,   722,    23,   233,  1062,  1066,   481,   862,
     481,  1182,   844,   456,  1099,   619,     5,  1018,   546,  1158,
    1089,  1463,  1466,  1089,  1111,  1112,   188,  1443,   965,   947,
    1477,  1477,   957,   958,   977,   977,    34,    36,    37,    38,
     269,   272,   274,   294,   304,   346,   350,   428,   976,   978,
     979,  1005,  1089,  1110,   546,   680,    26,   398,   963,   320,
    1423,  1423,   135,   136,   435,   546,   937,  1332,  1333,  1374,
     787,  1373,  1373,  1271,   787,   937,  1433,  1433,   358,   475,
     585,  1412,  1373,  1279,   167,   437,   448,   470,   477,  1305,
    1306,  1307,   286,   287,  1395,  1487,  1487,   383,   913,  1089,
     641,   642,   906,   907,   908,   480,   624,   643,   644,   663,
     916,   917,  1487,   752,    26,   771,   771,   779,  1222,   752,
    1212,  1320,  1373,  1263,  1330,   429,  1263,   429,   429,  1257,
    1258,   429,   429,    63,   298,   356,   368,   378,   396,   406,
     409,   422,   471,   501,   511,   532,   535,   537,   565,   574,
    1365,  1366,  1367,  1369,  1254,  1255,  1251,  1252,   663,  1249,
     390,   619,  1424,   576,   457,   546,  1481,   673,   674,   937,
     937,   937,  1239,   862,   390,   390,   390,   390,   390,  1412,
     390,   390,   390,   390,   589,   884,    19,    26,   589,   390,
     390,    26,  1384,   390,   390,   390,   390,     5,   750,   390,
     837,   837,   837,   390,   837,   390,   390,   390,   440,   440,
     440,   862,  1404,   440,   862,  1404,   705,   706,   707,   837,
     429,   937,  1237,   616,  1135,   625,     5,     5,     5,   579,
     844,   619,     5,   482,   625,   390,   425,   429,   624,   163,
     166,   269,   272,   736,   739,   740,  1005,   737,   738,   937,
     429,   938,   648,   649,  1136,   844,   937,   937,   927,   928,
     508,  1477,   826,     8,   896,    26,    26,  1012,  1013,  1089,
     535,  1150,   840,    65,   837,  1195,    26,  1089,  1487,     5,
       5,     5,   390,   390,   709,   937,   390,  1424,   705,   429,
     429,   721,   717,   359,   715,   844,   338,   718,   722,   596,
    1007,  1067,  1063,   361,  1061,  1062,   842,   625,  1095,    21,
     937,  1104,  1114,    14,    18,    19,    21,    25,    26,    64,
     394,   409,   426,   429,   442,   482,   483,   495,   537,   576,
     588,   600,   601,   608,   611,   937,   943,  1159,  1160,  1379,
    1381,  1411,  1416,  1417,  1418,  1466,   419,   419,     5,  1487,
     959,   960,   550,   936,   546,   988,   987,   990,   989,   929,
     991,   929,   992,   986,   985,   983,   982,  1006,   323,   979,
     984,  1477,    39,    40,    41,    42,    43,    44,    98,   331,
     344,   408,   415,   454,   479,   489,   490,   495,   505,   527,
     530,   531,   536,   593,   604,   681,   682,  1003,  1004,     5,
      26,  1424,   247,  1089,   470,  1405,  1406,  1424,  1146,  1399,
    1401,   100,   100,   595,  1144,  1334,  1335,   429,  1313,   149,
     525,  1339,  1346,  1373,   174,   270,  1437,   619,   625,  1402,
    1447,   340,   349,   373,   376,   394,   500,   554,   561,   931,
    1282,  1287,   429,  1308,   624,     5,    25,   937,  1396,  1397,
     915,  1089,     5,   546,   909,   910,   638,   908,   914,   937,
     914,   918,   919,   914,   323,   917,  1041,   425,   425,   459,
    1205,  1225,  1058,   459,  1168,  1199,   429,     5,   390,     9,
     293,   429,   441,  1349,  1350,  1351,  1352,  1353,  1357,  1361,
    1363,  1416,   390,   611,   937,  1319,  1321,  1373,  1376,  1377,
    1323,  1376,     5,   390,  1323,  1349,   365,   452,   469,   512,
     552,   581,   590,  1386,  1386,   429,   429,   429,   429,   429,
     429,   206,   398,  1325,  1327,     5,   390,     5,   390,   937,
    1465,     8,  1424,  1100,   844,     5,  1244,  1245,   862,  1047,
    1413,  1414,  1416,   877,  1384,   877,    26,    26,   589,    24,
      26,   790,   878,  1215,   390,  1215,   791,   390,  1215,   872,
     870,   876,  1215,   874,  1215,  1215,  1215,    25,    25,    25,
     837,   854,   390,    25,   854,   390,   865,     5,   866,   619,
    1244,   576,  1424,  1424,   844,   844,   926,   508,   844,  1479,
       5,    21,  1376,   975,  1424,   619,   937,   737,   745,   744,
     746,   937,   941,   747,   941,   190,   740,   743,     5,   977,
     619,   844,     8,   937,   862,   553,  1285,     5,   390,  1089,
       5,   324,    25,  1227,   929,   343,   343,   457,   619,   343,
     429,   694,   698,   691,  1487,  1487,   723,   719,   715,  1008,
      25,   936,  1068,  1089,  1487,   844,   424,   457,   862,  1417,
    1417,  1382,  1386,   470,  1416,   429,   429,   429,   429,   429,
     429,   429,   937,   429,     5,    18,    19,    20,    21,    92,
      93,    94,    95,    96,    97,  1438,  1463,  1089,  1112,    62,
     542,   966,   961,   962,    26,   678,   937,  1487,  1487,  1487,
    1487,     5,   980,     5,   981,  1487,  1487,  1487,  1487,  1011,
    1487,   936,    25,    14,    14,     5,   390,    26,  1373,  1412,
    1393,   595,   595,  1270,  1398,  1399,  1335,  1314,  1376,   616,
     931,  1349,   429,  1274,   937,  1434,  1433,  1413,    48,    49,
      50,    51,    52,   583,  1450,   844,   844,  1280,   931,  1309,
    1376,  1373,  1307,   619,   619,     5,     5,  1089,   914,  1487,
    1487,     5,   921,   922,  1487,  1487,   920,  1034,   810,   768,
      73,    74,    76,    77,    78,   176,   183,   217,   226,   255,
     256,   300,   342,   398,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,  1202,  1206,   134,   513,  1207,  1223,
    1034,   159,   175,   176,   183,   217,   226,   255,   300,   342,
    1200,  1201,  1213,  1207,  1321,  1330,  1352,   429,  1411,  1349,
    1416,  1411,     6,   390,     7,     9,    10,    12,    13,    14,
      15,    16,    17,   251,   370,   427,   556,   622,  1360,  1362,
    1377,   457,  1375,   390,     5,   619,     5,   390,  1258,   390,
     390,   625,   429,   625,    26,  1371,  1371,    26,  1371,  1371,
      26,  1370,    25,  1379,  1328,  1329,  1330,  1255,  1251,  1424,
       8,   425,   674,     5,   390,   842,   390,     5,   546,  1340,
    1345,   937,   625,   390,    26,   589,   625,   390,   390,   390,
     390,     5,   390,   390,   390,   707,   705,    21,   390,  1424,
       5,   844,   566,   273,   683,   684,   844,    21,   937,   390,
     977,  1487,  1487,     5,   741,   457,   619,     5,   742,  1487,
     738,   546,    21,   937,     5,   937,  1126,   388,   658,   842,
    1286,   895,  1013,   936,   837,     5,   705,  1089,   690,   672,
     937,  1089,   696,   390,   705,   705,  1487,  1487,  1011,  1065,
      25,  1069,  1089,   571,   891,  1100,   482,   843,  1019,   625,
    1412,   390,   394,  1439,  1466,   358,   475,   585,  1364,  1416,
    1419,  1364,  1364,  1364,  1364,   619,  1419,  1160,  1416,  1416,
    1416,  1416,   968,   967,   439,   953,   954,   619,   929,  1487,
     929,  1487,   678,    26,  1089,    26,  1089,   682,   390,   429,
    1425,  1413,  1395,  1399,  1399,  1391,     5,   390,   470,  1410,
    1275,  1376,   478,  1272,  1410,   625,  1403,    18,    19,    64,
     426,   429,   442,   482,   483,   495,   537,   576,   588,   600,
     601,   608,   611,   937,  1379,  1411,  1455,  1456,  1457,  1458,
    1459,  1460,  1466,  1455,  1455,  1455,  1376,  1452,  1454,  1451,
    1452,  1453,  1448,   553,  1283,     5,   390,   625,   937,   937,
    1397,  1089,   937,  1487,  1487,  1487,  1487,   623,   623,  1203,
    1203,  1203,    25,  1203,  1203,  1203,  1203,  1203,  1203,    25,
      25,  1203,  1206,  1089,  1116,  1117,   618,   445,  1169,  1487,
      25,    25,    26,    26,    26,    26,    26,    25,  1089,  1201,
    1169,   390,   390,  1350,  1351,  1355,  1417,   429,  1411,  1355,
     429,  1411,    10,   248,   385,   387,  1416,    26,  1318,  1376,
      21,   937,  1376,   365,   452,   469,   512,   552,   581,   590,
    1387,    26,  1387,     5,  1368,  1368,     5,   390,   390,  1368,
     390,  1330,  1424,  1245,   267,  1241,  1414,   514,  1341,  1342,
    1343,  1373,  1346,   330,   513,   524,  1290,  1407,   365,   452,
     469,   512,   552,   581,   590,  1385,   877,   589,    24,    26,
     794,   837,   867,   467,   825,     5,   372,  1424,     5,   429,
     390,   550,  1002,   941,  1487,   675,    21,   937,   941,  1487,
    1477,   844,  1477,  1111,  1487,   678,    25,  1228,  1108,   425,
     705,   695,   699,   390,  1487,   936,   844,   889,   425,  1387,
    1413,     5,  1386,   390,     5,  1416,     5,   390,  1416,  1416,
    1416,  1416,   937,   390,   844,  1487,   955,   956,    21,   937,
    1426,  1427,   553,  1409,  1394,  1392,  1395,  1376,  1412,   139,
    1315,     5,   390,  1273,  1434,  1409,  1458,  1458,  1457,   429,
     429,   429,   429,   429,   429,   429,   937,   429,     5,   390,
      18,    19,    20,    21,  1438,   390,     5,   390,     5,    14,
     149,   525,  1449,  1284,  1376,   461,  1310,  1311,  1374,   619,
     209,  1042,   806,   780,   538,   587,  1118,     5,  1116,    61,
     133,   198,   200,   215,   223,   227,   252,  1170,  1171,  1224,
    1042,  1214,   440,  1354,  1358,  1359,  1379,  1466,  1354,  1358,
    1355,  1416,     5,   425,  1375,   390,    26,  1372,   390,   390,
      26,   390,   429,  1343,     5,   937,  1378,   367,  1337,  1347,
     937,  1408,   618,  1364,   330,   429,    24,    26,   390,   929,
     678,   372,  1424,   844,   685,   568,  1124,    26,   678,   425,
    1002,   390,   239,  1148,   390,   390,   429,   697,   343,   703,
     390,   692,  1064,  1487,   457,  1345,  1386,   625,  1386,   390,
    1416,   390,   390,   390,   390,   575,   936,     5,   390,  1111,
    1345,  1395,  1395,  1413,  1376,   429,  1345,   390,  1439,  1364,
    1457,  1461,  1364,  1364,  1364,  1364,   619,  1461,  1456,  1457,
    1457,  1457,  1457,  1452,    14,  1453,  1456,   931,  1349,  1111,
       5,   140,  1304,   937,  1117,  1172,  1173,  1089,  1175,  1089,
    1174,  1176,  1171,   238,   238,  1356,  1379,  1420,     5,   390,
     390,  1354,     7,    26,   625,   390,  1342,  1344,  1342,  1338,
    1415,  1416,   446,  1336,  1348,  1241,    26,  1291,  1292,  1293,
    1376,  1405,  1408,    26,   824,  1424,   391,   202,   258,   283,
     292,   328,   336,   430,   602,   682,   686,   687,   429,   619,
     678,  1005,  1151,  1152,  1153,  1229,   700,   390,  1108,   703,
     703,  1487,   890,  1100,   390,   625,  1387,   625,   969,   999,
    1427,  1407,  1345,   482,  1276,  1277,  1416,  1407,   390,  1457,
       5,   390,  1457,  1457,  1457,  1457,   937,   390,   429,  1311,
    1487,  1487,  1177,  1487,  1178,  1487,  1487,  1359,  1416,   425,
    1387,     5,   390,     5,  1349,     5,   538,   587,  1294,  1241,
     390,   346,   350,   827,   828,   829,  1005,   924,   924,   924,
     924,   924,   924,    25,     5,   390,   844,    21,   937,  1154,
     281,  1153,   703,   705,   703,   240,   425,  1387,  1387,  1487,
     678,     5,   390,   390,  1457,   390,   390,   390,   390,  1455,
    1487,  1487,  1342,  1415,  1292,   831,   830,   237,   829,   832,
     687,     5,  1487,   701,   966,  1277,   390,  1487,  1487,  1487,
     844,   390,   390,   702,   162,   343,   704,  1108
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
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1194 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 66:
#line 1197 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1201 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1205 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1212 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1218 "fgl.yacc"
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
#line 1227 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1231 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1236 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1240 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1248 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1252 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1256 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1258 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1264 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1269 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1272 "fgl.yacc"
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
#line 1288 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1295 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1299 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1303 "fgl.yacc"
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
#line 1325 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1325 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1329 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1330 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1331 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1336 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1339 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1345 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1348 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1360 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1366 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1369 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1384 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1394 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1400 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1409 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1422 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1425 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1427 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1433 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1435 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1440 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1445 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1451 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1455 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1470 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1473 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1476 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1479 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1482 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1485 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1507 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1516 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1526 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1540 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1544 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1547 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1555 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1561 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1576 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1580 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1585 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1595 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1598 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1602 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1604 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1607 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1609 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1612 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1614 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1617 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1620 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1630 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1631 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1639 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1640 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1657 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1660 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1663 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1666 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1669 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1672 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1681 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1689 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1694 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1707 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1711 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1726 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1727 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1735 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1735 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1745 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1745 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1754 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1755 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1756 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1759 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1764 "fgl.yacc"
    { }
    break;

  case 194:
#line 1764 "fgl.yacc"
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
#line 1781 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1785 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1799 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1808 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1812 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1828 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1830 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1831 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1838 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1838 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1839 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1840 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1843 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1845 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1855 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1870 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1870 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1876 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1877 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1884 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1885 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1886 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1887 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1890 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1891 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1892 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1893 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1897 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1902 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1907 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1911 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1914 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1918 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1919 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1920 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1921 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1922 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1923 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1924 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1925 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1928 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1929 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1930 "fgl.yacc"
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
#line 1962 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1966 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1968 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1970 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1972 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1977 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1981 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1981 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1985 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1986 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1987 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1988 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1989 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1990 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1992 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 1997 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 1997 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 2000 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 2002 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 2008 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 2010 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2016 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2024 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2024 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2027 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2028 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2029 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2030 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2031 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2032 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2034 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2055 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2064 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2066 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2068 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2070 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2071 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2072 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2073 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2074 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2079 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2086 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2091 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2093 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2095 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2096 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2097 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2098 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2099 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2100 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2101 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2104 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2106 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2112 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2120 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2128 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2132 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2140 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2141 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2142 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2143 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2162 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2174 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2178 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2181 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2184 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2185 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2186 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2187 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2188 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2194 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2201 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2206 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2211 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2215 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2218 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2226 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2228 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2233 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2245 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2248 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2251 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2254 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2257 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2260 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2273 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2276 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2291 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2293 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2295 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2297 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2299 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2301 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2302 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2309 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2311 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2315 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2317 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2319 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2321 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2323 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2325 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2327 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2333 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2347 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2350 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2367 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2373 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2377 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2382 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2392 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 402:
#line 2399 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2406 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2406 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2411 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 407:
#line 2415 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2421 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2429 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2435 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2444 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2446 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2453 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2461 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2465 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2474 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2479 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2484 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2488 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2490 "fgl.yacc"
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
#line 2500 "fgl.yacc"
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
#line 2514 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2522 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2534 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2540 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2546 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2556 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2562 "fgl.yacc"
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
#line 2634 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2640 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2644 "fgl.yacc"
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
#line 2652 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2652 "fgl.yacc"
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
#line 2668 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2672 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2678 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2681 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2689 "fgl.yacc"
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
#line 2700 "fgl.yacc"
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
#line 2710 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2716 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2726 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2731 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2738 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2741 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2744 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2749 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2756 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2761 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2766 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2771 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2782 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2790 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2798 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2803 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2807 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2812 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2816 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2820 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2826 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2829 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2833 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2837 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2841 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2845 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2849 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2856 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2866 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2871 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2877 "fgl.yacc"
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
#line 2887 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2892 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2895 "fgl.yacc"
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
#line 2909 "fgl.yacc"
    {chk4var=1;}
    break;

  case 477:
#line 2909 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 479:
#line 2912 "fgl.yacc"
    {chk4var=1;}
    break;

  case 480:
#line 2912 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2912 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 482:
#line 2916 "fgl.yacc"
    {chk4var=1;}
    break;

  case 483:
#line 2916 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2916 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 485:
#line 2920 "fgl.yacc"
    {chk4var=1;}
    break;

  case 486:
#line 2920 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2920 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 488:
#line 2924 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2930 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2936 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2942 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2952 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2953 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2961 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_inp_io,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 497:
#line 2972 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2973 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 499:
#line 2979 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_inp_io,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",yyvsp[-1].str); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 500:
#line 2990 "fgl.yacc"
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
#line 3000 "fgl.yacc"
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
#line 3013 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 3018 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 3025 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 3029 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3032 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3035 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3041 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3044 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3047 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3064 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3067 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3073 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3074 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3075 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3080 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3081 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3082 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3083 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3085 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3086 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3087 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3089 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3090 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3096 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3101 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3113 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 533:
#line 3117 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 534:
#line 3118 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 535:
#line 3125 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 537:
#line 3142 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 538:
#line 3146 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 539:
#line 3152 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 540:
#line 3156 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 541:
#line 3164 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 542:
#line 3165 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 543:
#line 3177 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 544:
#line 3183 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 545:
#line 3191 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 552:
#line 3208 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 553:
#line 3210 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3213 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 555:
#line 3215 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3229 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 561:
#line 3231 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 562:
#line 3234 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 563:
#line 3236 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 576:
#line 3267 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 577:
#line 3269 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3272 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 579:
#line 3274 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3277 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 581:
#line 3279 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3282 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 583:
#line 3284 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3287 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 585:
#line 3289 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 586:
#line 3304 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 587:
#line 3320 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 588:
#line 3321 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 589:
#line 3322 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 590:
#line 3323 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 591:
#line 3324 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 592:
#line 3325 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 596:
#line 3333 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 598:
#line 3339 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 599:
#line 3341 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 600:
#line 3342 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 601:
#line 3344 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 602:
#line 3346 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 603:
#line 3348 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3350 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 605:
#line 3352 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 606:
#line 3355 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 607:
#line 3362 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 608:
#line 3364 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3370 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3375 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 611:
#line 3380 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 612:
#line 3385 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 613:
#line 3385 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 614:
#line 3388 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 615:
#line 3394 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 616:
#line 3399 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 617:
#line 3403 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 620:
#line 3411 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 621:
#line 3413 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 622:
#line 3415 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 623:
#line 3417 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3419 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 625:
#line 3421 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 626:
#line 3424 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 628:
#line 3433 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 629:
#line 3495 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 630:
#line 3508 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 632:
#line 3515 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 633:
#line 3518 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 634:
#line 3524 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 635:
#line 3530 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3534 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 637:
#line 3538 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 638:
#line 3544 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3548 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 640:
#line 3552 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 641:
#line 3557 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 642:
#line 3562 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 661:
#line 3603 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 662:
#line 3608 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 664:
#line 3613 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 666:
#line 3616 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 667:
#line 3618 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 668:
#line 3621 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 669:
#line 3625 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 670:
#line 3628 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 671:
#line 3634 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 672:
#line 3645 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 673:
#line 3646 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 674:
#line 3649 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 676:
#line 3655 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 677:
#line 3659 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 678:
#line 3660 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 681:
#line 3674 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 682:
#line 3676 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 685:
#line 3685 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 686:
#line 3687 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 687:
#line 3691 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 688:
#line 3693 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3696 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 690:
#line 3698 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 691:
#line 3701 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 692:
#line 3704 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 693:
#line 3707 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 694:
#line 3709 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 695:
#line 3712 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 696:
#line 3714 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 697:
#line 3717 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 698:
#line 3719 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 699:
#line 3722 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 700:
#line 3724 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 701:
#line 3725 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 702:
#line 3727 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3728 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 704:
#line 3730 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3731 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 706:
#line 3733 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 707:
#line 3773 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 708:
#line 3774 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 709:
#line 3782 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 710:
#line 3783 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 711:
#line 3792 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 712:
#line 3797 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 713:
#line 3802 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 714:
#line 3803 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 716:
#line 3808 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 717:
#line 3811 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 718:
#line 3819 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 719:
#line 3824 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 720:
#line 3828 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 721:
#line 3835 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 722:
#line 3844 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 723:
#line 3850 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 724:
#line 3851 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 725:
#line 3852 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 726:
#line 3853 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 727:
#line 3856 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 729:
#line 3859 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 730:
#line 3866 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 731:
#line 3867 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 732:
#line 3868 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3869 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 734:
#line 3870 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 735:
#line 3871 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 736:
#line 3872 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 737:
#line 3873 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 738:
#line 3874 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 739:
#line 3879 "fgl.yacc"
    {iskey=1;}
    break;

  case 740:
#line 3879 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 741:
#line 3881 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 742:
#line 3884 "fgl.yacc"
    {iskey=1;}
    break;

  case 743:
#line 3884 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 744:
#line 3886 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 745:
#line 3890 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 746:
#line 3893 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 747:
#line 3894 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 749:
#line 3897 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 755:
#line 3909 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 756:
#line 3910 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 757:
#line 3911 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 758:
#line 3912 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 759:
#line 3913 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 760:
#line 3914 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 761:
#line 3915 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 762:
#line 3916 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 763:
#line 3917 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 764:
#line 3918 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 765:
#line 3919 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 766:
#line 3920 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 767:
#line 3921 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 768:
#line 3925 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 769:
#line 3943 "fgl.yacc"
    {chk4var=1;}
    break;

  case 770:
#line 3943 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 771:
#line 3946 "fgl.yacc"
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
#line 3970 "fgl.yacc"
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
#line 3988 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3994 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 4000 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 777:
#line 4006 "fgl.yacc"
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
#line 4017 "fgl.yacc"
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
#line 4040 "fgl.yacc"
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
#line 4056 "fgl.yacc"
    {
	}
    break;

  case 789:
#line 4079 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 793:
#line 4087 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 811:
#line 4113 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 812:
#line 4114 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 813:
#line 4122 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 814:
#line 4127 "fgl.yacc"
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
#line 4143 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 816:
#line 4149 "fgl.yacc"
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
#line 4164 "fgl.yacc"
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
#line 4177 "fgl.yacc"
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
#line 4187 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 821:
#line 4194 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 822:
#line 4201 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 823:
#line 4207 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 824:
#line 4207 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 825:
#line 4212 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 826:
#line 4217 "fgl.yacc"
    {
}
    break;

  case 832:
#line 4229 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 834:
#line 4237 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 835:
#line 4243 "fgl.yacc"
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
#line 4257 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 837:
#line 4261 "fgl.yacc"
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
#line 4274 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 840:
#line 4292 "fgl.yacc"
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
#line 4300 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 842:
#line 4306 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 843:
#line 4317 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 844:
#line 4321 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 845:
#line 4328 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 846:
#line 4335 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 847:
#line 4341 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 848:
#line 4346 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 851:
#line 4353 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 852:
#line 4354 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 853:
#line 4356 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 854:
#line 4357 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 855:
#line 4360 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 856:
#line 4361 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 857:
#line 4362 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 858:
#line 4364 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 859:
#line 4369 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 860:
#line 4374 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 861:
#line 4381 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 865:
#line 4388 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 866:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 867:
#line 4392 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 868:
#line 4401 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 869:
#line 4407 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 870:
#line 4411 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 873:
#line 4423 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 874:
#line 4428 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 875:
#line 4433 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 876:
#line 4436 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 878:
#line 4448 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 879:
#line 4451 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 880:
#line 4454 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 887:
#line 4470 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 888:
#line 4475 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 889:
#line 4475 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 890:
#line 4478 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4505 "fgl.yacc"
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
#line 4563 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 895:
#line 4570 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 896:
#line 4574 "fgl.yacc"
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
#line 4617 "fgl.yacc"
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
#line 4665 "fgl.yacc"
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
#line 4679 "fgl.yacc"
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
#line 4703 "fgl.yacc"
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
#line 4763 "fgl.yacc"
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
#line 4819 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 910:
#line 4824 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4832 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 912:
#line 4837 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 913:
#line 4845 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 914:
#line 4851 "fgl.yacc"
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
#line 4884 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 916:
#line 4887 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 917:
#line 4889 "fgl.yacc"
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
#line 4930 "fgl.yacc"
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
#line 4983 "fgl.yacc"
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
#line 5035 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 926:
#line 5042 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 927:
#line 5048 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 928:
#line 5059 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 929:
#line 5066 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 931:
#line 5074 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 932:
#line 5077 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 933:
#line 5078 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 935:
#line 5080 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 936:
#line 5081 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 5084 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 938:
#line 5087 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 939:
#line 5093 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 940:
#line 5096 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 941:
#line 5100 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 942:
#line 5104 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 5111 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 944:
#line 5116 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 945:
#line 5123 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 946:
#line 5126 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 951:
#line 5139 "fgl.yacc"
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
#line 5158 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 953:
#line 5165 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5172 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 955:
#line 5175 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 956:
#line 5189 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 961:
#line 5206 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 962:
#line 5211 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 963:
#line 5217 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 965:
#line 5224 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 966:
#line 5229 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 967:
#line 5232 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 968:
#line 5233 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 969:
#line 5236 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 970:
#line 5237 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 971:
#line 5240 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 972:
#line 5241 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 973:
#line 5246 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 974:
#line 5253 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 975:
#line 5256 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 976:
#line 5262 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 977:
#line 5264 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 978:
#line 5266 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 979:
#line 5268 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 980:
#line 5271 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 981:
#line 5271 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 982:
#line 5272 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 983:
#line 5277 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 984:
#line 5285 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 985:
#line 5286 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 986:
#line 5291 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 987:
#line 5293 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 988:
#line 5295 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 5312 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 993:
#line 5315 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 994:
#line 5318 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 995:
#line 5321 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 996:
#line 5325 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 997:
#line 5328 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 998:
#line 5331 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 999:
#line 5335 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5339 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5343 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1002:
#line 5346 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1003:
#line 5350 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1004:
#line 5353 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1005:
#line 5354 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5355 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1007:
#line 5358 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1008:
#line 5361 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1009:
#line 5364 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1010:
#line 5367 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1011:
#line 5370 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1012:
#line 5373 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1013:
#line 5376 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1014:
#line 5393 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1017:
#line 5403 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1018:
#line 5410 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1020:
#line 5431 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1021:
#line 5436 "fgl.yacc"
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
#line 5449 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1023:
#line 5454 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1024:
#line 5455 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1025:
#line 5459 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1029:
#line 5465 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1030:
#line 5467 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1032:
#line 5482 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1033:
#line 5486 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1034:
#line 5492 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1035:
#line 5493 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1036:
#line 5496 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1037:
#line 5497 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1038:
#line 5500 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1040:
#line 5519 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1041:
#line 5524 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1042:
#line 5529 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1043:
#line 5534 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1049:
#line 5556 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1050:
#line 5563 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1051:
#line 5572 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1052:
#line 5578 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1053:
#line 5580 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1057:
#line 5591 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1058:
#line 5592 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1059:
#line 5594 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1060:
#line 5595 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1061:
#line 5597 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1062:
#line 5598 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1063:
#line 5600 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1064:
#line 5601 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1065:
#line 5603 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1066:
#line 5604 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1067:
#line 5605 "fgl.yacc"
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
#line 5619 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1069:
#line 5621 "fgl.yacc"
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
#line 5638 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1077:
#line 5650 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1078:
#line 5650 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1079:
#line 5656 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1080:
#line 5656 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1081:
#line 5659 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1082:
#line 5659 "fgl.yacc"
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
#line 5669 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1084:
#line 5670 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1085:
#line 5671 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1086:
#line 5678 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1087:
#line 5690 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1093:
#line 5701 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1094:
#line 5706 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1095:
#line 5710 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1096:
#line 5715 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1097:
#line 5721 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1098:
#line 5722 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1099:
#line 5723 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1100:
#line 5727 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1101:
#line 5728 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1102:
#line 5729 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1103:
#line 5730 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1104:
#line 5734 "fgl.yacc"
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
#line 5744 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1106:
#line 5746 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1107:
#line 5751 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1108:
#line 5754 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1109:
#line 5759 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1110:
#line 5766 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1111:
#line 5773 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1112:
#line 5780 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1113:
#line 5789 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1114:
#line 5796 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1115:
#line 5803 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1116:
#line 5810 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1117:
#line 5817 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1122:
#line 5830 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1123:
#line 5831 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1124:
#line 5832 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1125:
#line 5833 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5834 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5835 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1128:
#line 5836 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1129:
#line 5837 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1130:
#line 5838 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1131:
#line 5839 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1134:
#line 5845 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1135:
#line 5846 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1136:
#line 5847 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1137:
#line 5848 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1142:
#line 5857 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1143:
#line 5858 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1144:
#line 5859 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1145:
#line 5860 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1146:
#line 5861 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5862 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5863 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1149:
#line 5864 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5866 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1151:
#line 5867 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1152:
#line 5868 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1153:
#line 5869 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1154:
#line 5871 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1155:
#line 5872 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1156:
#line 5873 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1157:
#line 5874 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1161:
#line 5879 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1162:
#line 5880 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1166:
#line 5887 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1167:
#line 5894 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1168:
#line 5901 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1169:
#line 5912 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1170:
#line 5921 "fgl.yacc"
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
#line 5932 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1172:
#line 5936 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1173:
#line 5940 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1174:
#line 5946 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1175:
#line 5951 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1176:
#line 5959 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1177:
#line 5962 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1178:
#line 5971 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1179:
#line 5982 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1181:
#line 5989 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1182:
#line 5997 "fgl.yacc"
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
#line 6007 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1184:
#line 6010 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1185:
#line 6014 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1186:
#line 6022 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1187:
#line 6025 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1188:
#line 6031 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1189:
#line 6035 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1190:
#line 6039 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1191:
#line 6043 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1192:
#line 6047 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1193:
#line 6053 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1194:
#line 6054 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1195:
#line 6055 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1196:
#line 6056 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1197:
#line 6061 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1198:
#line 6063 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1199:
#line 6066 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1200:
#line 6070 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1201:
#line 6073 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1202:
#line 6080 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1203:
#line 6085 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1204:
#line 6086 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1205:
#line 6087 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1206:
#line 6092 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1207:
#line 6093 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1208:
#line 6099 "fgl.yacc"
    {insql=1;}
    break;

  case 1209:
#line 6099 "fgl.yacc"
    {insql=0;}
    break;

  case 1210:
#line 6099 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1211:
#line 6104 "fgl.yacc"
    {insql=1;}
    break;

  case 1212:
#line 6104 "fgl.yacc"
    {insql=0;}
    break;

  case 1213:
#line 6104 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1214:
#line 6115 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1215:
#line 6116 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1216:
#line 6122 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1217:
#line 6124 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1219:
#line 6137 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1220:
#line 6141 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1221:
#line 6142 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1223:
#line 6147 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1224:
#line 6150 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1225:
#line 6156 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1226:
#line 6159 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6167 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1229:
#line 6174 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1230:
#line 6181 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1231:
#line 6184 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1232:
#line 6193 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1233:
#line 6196 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1234:
#line 6199 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1235:
#line 6202 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1236:
#line 6205 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6208 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6211 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6218 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1240:
#line 6221 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1241:
#line 6228 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1242:
#line 6231 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1243:
#line 6237 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1244:
#line 6240 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1245:
#line 6247 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1246:
#line 6250 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1248:
#line 6258 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1250:
#line 6267 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1251:
#line 6270 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1252:
#line 6276 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1253:
#line 6279 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1254:
#line 6285 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1255:
#line 6292 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1256:
#line 6293 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1257:
#line 6297 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1258:
#line 6303 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1259:
#line 6306 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1261:
#line 6314 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1262:
#line 6321 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6324 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1267:
#line 6342 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1273:
#line 6348 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1274:
#line 6351 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1275:
#line 6354 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1276:
#line 6360 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1278:
#line 6366 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1280:
#line 6377 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1281:
#line 6391 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1282:
#line 6400 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1283:
#line 6400 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1284:
#line 6405 "fgl.yacc"
    {insql=1;}
    break;

  case 1285:
#line 6405 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1286:
#line 6410 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1287:
#line 6413 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6415 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6422 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6426 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1292:
#line 6430 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1293:
#line 6437 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 6440 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1295:
#line 6447 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1296:
#line 6451 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1297:
#line 6455 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1298:
#line 6460 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1299:
#line 6465 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1300:
#line 6469 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1301:
#line 6475 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1302:
#line 6479 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1303:
#line 6485 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1304:
#line 6492 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1305:
#line 6496 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1306:
#line 6501 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1307:
#line 6511 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1308:
#line 6514 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1309:
#line 6516 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1310:
#line 6518 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1311:
#line 6520 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1312:
#line 6522 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6524 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6526 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1315:
#line 6532 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1316:
#line 6542 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1317:
#line 6549 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1319:
#line 6555 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6564 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1326:
#line 6569 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1327:
#line 6574 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1328:
#line 6581 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1329:
#line 6582 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1330:
#line 6589 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1331:
#line 6600 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1332:
#line 6601 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1333:
#line 6604 "fgl.yacc"
    {insql=1;}
    break;

  case 1334:
#line 6604 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1335:
#line 6609 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1336:
#line 6614 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1338:
#line 6620 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1340:
#line 6624 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1341:
#line 6629 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1342:
#line 6634 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1343:
#line 6638 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1345:
#line 6644 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1346:
#line 6648 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1347:
#line 6656 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6659 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1349:
#line 6661 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1350:
#line 6666 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1353:
#line 6673 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1357:
#line 6680 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6683 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1359:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6691 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6697 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6707 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1367:
#line 6712 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1368:
#line 6714 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6720 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1371:
#line 6723 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1373:
#line 6729 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1374:
#line 6737 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6742 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6752 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6758 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6764 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6766 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6772 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6777 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1386:
#line 6780 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1387:
#line 6783 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1388:
#line 6791 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6793 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1390:
#line 6806 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1391:
#line 6811 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6815 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1394:
#line 6817 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1395:
#line 6824 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1396:
#line 6827 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1397:
#line 6833 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1398:
#line 6837 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1399:
#line 6841 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1400:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1401:
#line 6848 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1402:
#line 6856 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1403:
#line 6863 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1406:
#line 6872 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1407:
#line 6878 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1408:
#line 6881 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6892 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6899 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6905 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6908 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6915 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6922 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1416:
#line 6929 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1417:
#line 6935 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1418:
#line 6936 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6937 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1421:
#line 6941 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6946 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1424:
#line 6953 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1425:
#line 6958 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1426:
#line 6959 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1427:
#line 6962 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1428:
#line 6965 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1429:
#line 6970 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1430:
#line 6971 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1431:
#line 6976 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1432:
#line 6979 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 6985 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 6988 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 6994 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1436:
#line 6997 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1437:
#line 7003 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 7006 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1439:
#line 7013 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1440:
#line 7014 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1441:
#line 7043 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1442:
#line 7045 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7049 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1445:
#line 7062 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1446:
#line 7065 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 7068 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1448:
#line 7071 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 7079 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 7082 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1453:
#line 7088 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 7094 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1456:
#line 7097 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1457:
#line 7100 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1458:
#line 7103 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7106 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1460:
#line 7109 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7112 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1463:
#line 7119 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1468:
#line 7126 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1469:
#line 7127 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1470:
#line 7132 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1471:
#line 7135 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7139 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7145 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7146 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1475:
#line 7147 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1476:
#line 7148 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1481:
#line 7168 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 7173 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7174 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1485:
#line 7177 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7182 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 7185 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7193 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7195 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7198 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1500:
#line 7199 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1501:
#line 7206 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7211 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1509:
#line 7227 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1510:
#line 7228 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1511:
#line 7232 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1512:
#line 7233 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1514:
#line 7252 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1515:
#line 7253 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1516:
#line 7254 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1517:
#line 7258 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1518:
#line 7261 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7267 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1520:
#line 7272 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1521:
#line 7277 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1523:
#line 7288 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1528:
#line 7303 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1529:
#line 7306 "fgl.yacc"
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
#line 7319 "fgl.yacc"
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
#line 7334 "fgl.yacc"
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
#line 7346 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1533:
#line 7348 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1534:
#line 7351 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1535:
#line 7351 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1536:
#line 7351 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1537:
#line 7351 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1538:
#line 7351 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1539:
#line 7351 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1540:
#line 7352 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1541:
#line 7355 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1542:
#line 7360 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1543:
#line 7360 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1544:
#line 7360 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1545:
#line 7360 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1546:
#line 7360 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1547:
#line 7360 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1548:
#line 7362 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1549:
#line 7365 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1564:
#line 7374 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1565:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1566:
#line 7379 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1567:
#line 7387 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1568:
#line 7387 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1569:
#line 7393 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1570:
#line 7393 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1571:
#line 7400 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1572:
#line 7400 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1573:
#line 7406 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1574:
#line 7406 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1575:
#line 7414 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1576:
#line 7415 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1577:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1581:
#line 7423 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7424 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7429 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1584:
#line 7432 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1585:
#line 7438 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1586:
#line 7443 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1587:
#line 7452 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1588:
#line 7464 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1589:
#line 7465 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1590:
#line 7468 "fgl.yacc"
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
#line 7483 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1592:
#line 7493 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1593:
#line 7496 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1594:
#line 7504 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1595:
#line 7513 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1596:
#line 7516 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1597:
#line 7520 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1598:
#line 7523 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1599:
#line 7524 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1601:
#line 7533 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1602:
#line 7534 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1603:
#line 7543 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1604:
#line 7552 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1605:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1606:
#line 7558 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1607:
#line 7559 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1608:
#line 7560 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1609:
#line 7567 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7570 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1611:
#line 7576 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1612:
#line 7579 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1613:
#line 7589 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1614:
#line 7598 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1615:
#line 7601 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1616:
#line 7604 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7610 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7616 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7619 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7622 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1621:
#line 7625 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1622:
#line 7632 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1623:
#line 7634 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1624:
#line 7636 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1625:
#line 7638 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7640 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7641 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1628:
#line 7642 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1629:
#line 7643 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1630:
#line 7644 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1631:
#line 7645 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1632:
#line 7646 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1633:
#line 7648 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1634:
#line 7650 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1635:
#line 7652 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1636:
#line 7654 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7656 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7658 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7660 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7661 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7663 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7667 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1643:
#line 7668 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1645:
#line 7678 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1646:
#line 7687 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1647:
#line 7691 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1648:
#line 7698 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1649:
#line 7698 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1651:
#line 7702 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1652:
#line 7707 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1653:
#line 7707 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1655:
#line 7711 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1656:
#line 7715 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1659:
#line 7724 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1660:
#line 7724 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1665:
#line 7743 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1666:
#line 7744 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1669:
#line 7752 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1670:
#line 7758 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1673:
#line 7777 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1674:
#line 7778 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1675:
#line 7779 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1676:
#line 7780 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1677:
#line 7781 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1678:
#line 7782 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1679:
#line 7786 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1680:
#line 7787 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1681:
#line 7788 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1682:
#line 7792 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1683:
#line 7796 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1685:
#line 7805 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1687:
#line 7810 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1688:
#line 7811 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1689:
#line 7815 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1690:
#line 7821 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1691:
#line 7908 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1692:
#line 7912 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1693:
#line 7914 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1694:
#line 7921 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1695:
#line 7925 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1696:
#line 7931 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1697:
#line 7939 "fgl.yacc"
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
#line 7949 "fgl.yacc"
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
#line 7959 "fgl.yacc"
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
#line 7971 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1701:
#line 7974 "fgl.yacc"
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
#line 7993 "fgl.yacc"
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
#line 8019 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1704:
#line 8022 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1706:
#line 8031 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1707:
#line 8036 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1708:
#line 8039 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1709:
#line 8047 "fgl.yacc"
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
#line 8055 "fgl.yacc"
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
#line 8068 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1712:
#line 8071 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1713:
#line 8079 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1714:
#line 8082 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1715:
#line 8085 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1716:
#line 8093 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1717:
#line 8097 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1718:
#line 8100 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1719:
#line 8103 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1720:
#line 8106 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1721:
#line 8110 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1722:
#line 8111 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1723:
#line 8112 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1724:
#line 8113 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1725:
#line 8114 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1726:
#line 8120 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1727:
#line 8121 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1728:
#line 8122 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1729:
#line 8123 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1730:
#line 8124 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 8125 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1732:
#line 8126 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1733:
#line 8127 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1734:
#line 8128 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1735:
#line 8129 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1736:
#line 8130 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1737:
#line 8131 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1738:
#line 8132 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1739:
#line 8133 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);printf("C14\n");}
    break;

  case 1740:
#line 8137 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1741:
#line 8143 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1742:
#line 8144 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1743:
#line 8157 "fgl.yacc"
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
#line 8177 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1748:
#line 8183 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1749:
#line 8184 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1753:
#line 8196 "fgl.yacc"
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
#line 8222 "fgl.yacc"
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
#line 8273 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1756:
#line 8275 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 8277 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 8278 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1759:
#line 8283 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1760:
#line 8288 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 8289 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1762:
#line 8293 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1763:
#line 8295 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8297 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8300 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1766:
#line 8304 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1767:
#line 8309 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1768:
#line 8314 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1769:
#line 8318 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1771:
#line 8328 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1773:
#line 8343 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1774:
#line 8346 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1775:
#line 8350 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1778:
#line 8369 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1779:
#line 8370 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1780:
#line 8373 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1781:
#line 8374 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1782:
#line 8375 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1783:
#line 8376 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1784:
#line 8377 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1785:
#line 8378 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1786:
#line 8379 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1787:
#line 8384 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1788:
#line 8385 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1789:
#line 8389 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1790:
#line 8393 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1791:
#line 8397 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1792:
#line 8401 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1793:
#line 8406 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1794:
#line 8410 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1795:
#line 8415 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1797:
#line 8423 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1799:
#line 8429 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1800:
#line 8435 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1801:
#line 8439 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1806:
#line 8457 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1807:
#line 8464 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1808:
#line 8473 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1809:
#line 8473 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17176 "y.tab.c"

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


#line 8568 "fgl.yacc"

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



